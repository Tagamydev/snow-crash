# Flag 00

## Tools Used:

* `find` command
* Online Caesar cipher decoder ([dcode.fr](https://www.dcode.fr/caesar-cipher))

## Process:

From the subject, we know we need to find files associated with the `flag00` user.
We start by searching for files belonging to the `flag00` group:

```bash
level00@SnowCrash:~$ find / -group flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

Inspecting the discovered file:

```bash
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

The content appears to be encrypted with a Caesar cipher. Using an online decoder, we determine that it translates to:

```
nottoohardhere
```

We use this password to switch to the `flag00` user and execute the `getflag` command to retrieve the flag:

```bash
x24ti5gi3x0ol2eh4esiuxias
```

---

# Flag 00

## Herramientas Utilizadas:

* Comando `find`
* Descifrador online de cifrado César ([dcode.fr](https://www.dcode.fr/caesar-cipher))

## Proceso:

A partir del enunciado, sabemos que necesitamos encontrar archivos asociados al usuario `flag00`.
Comenzamos buscando archivos que pertenezcan al grupo `flag00`:

```bash
level00@SnowCrash:~$ find / -group flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

Al inspeccionar el archivo encontrado:

```bash
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

El contenido parece estar cifrado con un cifrado César. Usando un descifrador en línea, descubrimos que se traduce como:

```
nottoohardhere
```

Utilizamos esta contraseña para cambiar al usuario `flag00` y ejecutamos el comando `getflag` para obtener la flag:

```bash
x24ti5gi3x0ol2eh4esiuxias
```

---

## Scripts Used:

None

## Flag:

```
x24ti5gi3x0ol2eh4esiuxias
```
