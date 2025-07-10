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