# Flag 01

## Tools Used:

* `cat` command
* John the Ripper (`john`) password cracker (run on another machine)

## Process:

We start by inspecting the `/etc/passwd` file to identify potential users to target:

```bash
level01@SnowCrash:~$ cat /etc/passwd
```

From the list, we notice that most user accounts are managed through external authentication services, except for the `flag01` user, who has an encrypted password stored directly in the file:

```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

We extract the relevant line and use **John the Ripper** on a separate machine to crack the password:

```bash
andres@andres-System-Product-Name:~$ echo 'flag01:42hDRfypTqqnw:3001:3001' > hashes
andres@andres-System-Product-Name:~$ john hashes 
```

John successfully cracks the password as:

```
abcdefg
```

We use this password to log in as `flag01` and execute the `getflag` command to retrieve the flag:

```bash
f2av5il02puano7naaf6adaaf
```

---

# Flag 01

## Herramientas Utilizadas:

* Comando `cat`
* John the Ripper (`john`) para descifrar contraseñas (ejecutado en otra máquina)

## Proceso:

Comenzamos inspeccionando el archivo `/etc/passwd` para identificar usuarios potenciales a atacar:

```bash
level01@SnowCrash:~$ cat /etc/passwd
```

En la lista observamos que la mayoría de las cuentas de usuario se gestionan mediante servicios externos, excepto el usuario `flag01`, que tiene una contraseña cifrada directamente en el archivo:

```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Extraemos esta línea y usamos **John the Ripper** en otra máquina para descifrar la contraseña:

```bash
andres@andres-System-Product-Name:~$ echo 'flag01:42hDRfypTqqnw:3001:3001' > hashes
andres@andres-System-Product-Name:~$ john hashes 
```

John logra descifrar la contraseña:

```
abcdefg
```

Utilizamos esta contraseña para iniciar sesión como `flag01` y ejecutar el comando `getflag` para obtener la flag:

```bash
f2av5il02puano7naaf6adaaf
```

---

## Scripts Used:

None

## Flag:

```
f2av5il02puano7naaf6adaaf
```
