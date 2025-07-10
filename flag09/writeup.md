# Flag 09

## Tools Used:

* `ls`, `chmod`, `./level09`
* Reverse engineering (Ghidra or static analysis)
* Python (for decryption)

## Process:

Upon logging into `level09`, we find the following files:

```bash
level09@SnowCrash:~$ ls -la
```

Key files:

```
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```

The **token** is readable, and the **level09** binary is an SUID executable owned by `flag09`.

### Analysis:

Decompiling the binary reveals several anti-debugging and anti-injection checks (such as blocking `LD_PRELOAD`), but fundamentally, the program reads an argument and transforms each character based on its position. Testing this manually shows the pattern:

```bash
level09@SnowCrash:~$ ./level09 1
1
level09@SnowCrash:~$ ./level09 11
12
level09@SnowCrash:~$ ./level09 111
123
```

This suggests the executable is **incrementing each character by its position index**.

### Token Recovery:

1. The **token** file contains an obfuscated string:

```
ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo=
```

2. Decoding the string and reversing the transformation using Python allows us to recover the original token.

### Python Script Used:

```python
#%%
import base64

#%%
tokenb64 = 'ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo='

#%%
e1 = base64.b64decode(tokenb64)

#%%
e2 = []
for num, byte in enumerate(e1):
    e2.append((byte - num) % 256)

#%%
print(''.join(chr(n) for n in e2))
#%%
```

3. Running this script yields:

```
f3iji1ju5yuevaus41q1afiuq
```

4. Switching to the `flag09` user and using the token:

```bash
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```

---

# Flag 09

## Herramientas Utilizadas:

* Comandos `ls`, `chmod`, `./level09`
* Ingeniería inversa (Ghidra o análisis estático)
* Python (para descifrado)

## Proceso:

Al ingresar a la cuenta `level09`, encontramos los siguientes archivos:

```bash
level09@SnowCrash:~$ ls -la
```

Archivos clave:

```
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```

El archivo **token** es legible y el ejecutable **level09** tiene permisos SUID.

### Análisis:

La descompilación muestra varias protecciones contra depuración y manipulación, pero en esencia, el programa toma un argumento y transforma cada carácter basándose en su posición. Al probar manualmente:

```bash
level09@SnowCrash:~$ ./level09 1
1
level09@SnowCrash:~$ ./level09 111
123
```

Esto sugiere que el ejecutable incrementa cada carácter por su índice.

### Recuperación del Token:

1. El archivo **token** contiene el string cifrado:

```
ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo=
```

2. Usando Python y aplicando la lógica inversa conseguimos el token original.

### Script de Python Usado:

```python
#%%
import base64

#%%
tokenb64 = 'ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo='

#%%
e1 = base64.b64decode(tokenb64)

#%%
e2 = []
for num, byte in enumerate(e1):
    e2.append((byte - num) % 256)

#%%
print(''.join(chr(n) for n in e2))
#%%
```

3. Este script devuelve:

```
f3iji1ju5yuevaus41q1afiuq
```

4. Con este token accedemos al usuario `flag09` y ejecutamos:

```bash
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```

---

## Scripts Used:

```python
import base64

tokenb64 = 'ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo='
e1 = base64.b64decode(tokenb64)
e2 = [(byte - i) % 256 for i, byte in enumerate(e1)]
print(''.join(chr(n) for n in e2))
```

## Flag:

```
s5cAJpM8ev6XHw998pRWG728z
```
