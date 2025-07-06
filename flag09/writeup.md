when we enter we see a single executable with s permits and a token that can be read

```bash
total 24
drwxrwxrwx 1 level09 level09  140 Jul  6 23:01 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level09 level09  220 Apr  3  2012 .bash_logout
-r-x------ 1 level09 level09 3518 Aug 30  2015 .bashrc
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
-r-x------ 1 level09 level09  675 Apr  3  2012 .profile
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```

Decompiling that binary with ghidra

```C

/* WARNING: Unknown calling convention */


size_t main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int in_GS_OFFSET;
  byte bVar8;
  char *pcVar9;
  FILE *pFVar10;
  int iVar11;
  uint local_120;
  char local_114 [256];
  int local_14;
  
  bVar8 = 0;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  bVar2 = false;
  local_120 = 0xffffffff;
  iVar11 = 1;
  pFVar10 = (FILE *)0x0;
  lVar3 = ptrace(PTRACE_TRACEME,0,1,0);
  if (lVar3 < 0) {
    pcVar9 = "You should not reverse this";
    puts("You should not reverse this");
    sVar4 = 1;
  }
  else {
    pcVar9 = getenv("LD_PRELOAD");
    if (pcVar9 == (char *)0x0) {
      iVar11 = open("/etc/ld.so.preload",0);
      if (iVar11 < 1) {
        iVar5 = syscall_open();
        if (iVar5 == -1) {
          iVar11 = 0x46;
          pFVar10 = (FILE *)0x1;
          pcVar9 = "/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n";
          fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n",1,0x46,
                 stderr);
          sVar4 = 1;
        }
        else {
          do {
            do {
              while( true ) {
                pFVar10 = (FILE *)0x100;
                pcVar9 = local_114;
                iVar11 = iVar5;
                sVar4 = syscall_gets((int)pcVar9,0x100);
                if (sVar4 == 0) goto LAB_08048a77;
                iVar6 = isLib(local_114,0x8048c2b);
                if (iVar6 == 0) break;
                bVar2 = true;
              }
            } while (!bVar2);
            iVar6 = isLib(local_114,0x8048c30);
            if (iVar6 != 0) {
              if (param_1 == 2) goto LAB_08048996;
              iVar11 = 0x22;
              pFVar10 = (FILE *)0x1;
              pcVar9 = "You need to provied only one arg.\n";
              sVar4 = fwrite("You need to provied only one arg.\n",1,0x22,stderr);
              goto LAB_08048a77;
            }
            pcVar9 = afterSubstr(local_114,0x8048c57);
          } while (pcVar9 != (char *)0x0);
          iVar11 = 0x30;
          pFVar10 = (FILE *)0x1;
          pcVar9 = "LD_PRELOAD detected through memory maps exit ..\n";
          sVar4 = fwrite("LD_PRELOAD detected through memory maps exit ..\n",1,0x30,stderr);
        }
      }
      else {
        iVar11 = 0x25;
        pFVar10 = (FILE *)0x1;
        pcVar9 = "Injection Linked lib detected exit..\n";
        fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
        sVar4 = 1;
      }
    }
    else {
      iVar11 = 0x25;
      pFVar10 = (FILE *)0x1;
      pcVar9 = "Injection Linked lib detected exit..\n";
      fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
      sVar4 = 1;
    }
  }
LAB_08048a77:
  if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pcVar9,pFVar10,iVar11);
LAB_08048996:
  local_120 = local_120 + 1;
  uVar7 = 0xffffffff;
  pcVar9 = *(char **)(param_2 + 4);
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + (uint)bVar8 * -2 + 1;
  } while (cVar1 != '\0');
  if (~uVar7 - 1 <= local_120) goto code_r0x080489ca;
  putchar((int)*(char *)(local_120 + *(int *)(param_2 + 4)) + local_120);
  goto LAB_08048996;
code_r0x080489ca:
  pcVar9 = (char *)0xa;
  pFVar10 = stdout;
  sVar4 = fputc(10,stdout);
  goto LAB_08048a77;
}

```

the code is obfuscated but it seems it just processes a string passed as parameter. It is posible to rev eng from the code but it seems more straightforward to show some lines

```bash
level09@SnowCrash:~$ ./level09 1
1
level09@SnowCrash:~$ ./level09 2
2
level09@SnowCrash:~$ ./level09 3
3
level09@SnowCrash:~$ ./level09 11
12
level09@SnowCrash:~$ ./level09 111
123
level09@SnowCrash:~$ ./level09 1111
1234
level09@SnowCrash:~$ ./level09 11111
12345
level09@SnowCrash:~$ ./level09 111111
123456
level09@SnowCrash:~$ ./level09 1111111
1234567
level09@SnowCrash:~$ ./level09 11111111
12345678
level09@SnowCrash:~$ ./level09 11111111111111111
123456789:;<=>?@A
```

so it seems that the token was generated adding the position to the ascii code of the pattern. converting the file into base64 to work in python we get this small script that gives us the original token.

```bash
#%%
import base64

#%%
tokenb64 = 'ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo='


# %%
e1=base64.b64decode(tokenb64)


#%%

e2 = []

for num,byte in enumerate(e1):
    e2.append( (byte - num)%256)
# %%

print(''.join(chr(n) for n in e2))
# %%

```

giving back f3iji1ju5yuevaus41q1afiuq

then going into flag09 and running getflag

```bash
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```