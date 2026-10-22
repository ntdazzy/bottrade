/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 25a0b0c0000 */

void FUN_25a0b0c0000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 25a0b0c0060 */

ulonglong FUN_25a0b0c0060(int *param_1,ulonglong param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  ulonglong uVar11;
  undefined8 unaff_RBX;
  undefined7 uVar13;
  ulonglong uVar12;
  uint *puVar14;
  uint uVar15;
  ulonglong uVar16;
  
  lVar6 = *(longlong *)(param_1 + 1);
  uVar13 = (undefined7)((ulonglong)unaff_RBX >> 8);
  if ((lVar6 == 0) || (puVar14 = (uint *)(lVar6 + -0xc), puVar14 == (uint *)0x0)) {
    piVar10 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_25a0b0c01bd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_25a0b0c01bd;
    piVar10 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      piVar1 = piVar10 + 3;
      *(undefined2 *)(piVar10 + 3) = 0;
      iVar5 = *piVar10;
      uVar12 = param_2 & 0xffffffff;
      if (*(uint *)(lVar6 + -4) < (uint)param_2) {
        uVar12 = (ulonglong)*(uint *)(lVar6 + -4);
      }
      uVar15 = (uint)uVar12;
      if (uVar15 != 0) {
        uVar16 = 0;
        if (uVar15 < 8) goto LAB_25a0b0c0120;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_25a0b0c0120;
        uVar16 = (ulonglong)(uVar15 & 0xfffffff8);
        uVar11 = 0;
        do {
          puVar3 = (undefined4 *)(lVar6 + uVar11 * 2);
          uVar7 = puVar3[1];
          uVar8 = puVar3[2];
          uVar9 = puVar3[3];
          puVar2 = (undefined4 *)((longlong)piVar1 + uVar11 * 2);
          *puVar2 = *puVar3;
          puVar2[1] = uVar7;
          puVar2[2] = uVar8;
          puVar2[3] = uVar9;
          uVar11 = uVar11 + 8;
        } while (uVar16 != uVar11);
        for (; uVar16 != uVar12; uVar16 = uVar16 + 1) {
LAB_25a0b0c0120:
          *(undefined2 *)((longlong)piVar1 + uVar16 * 2) = *(undefined2 *)(lVar6 + uVar16 * 2);
        }
        piVar10[2] = uVar15;
        *(undefined2 *)((longlong)piVar1 + uVar12 * 2) = 0;
      }
      *param_1 = iVar5;
      *(int **)(param_1 + 1) = piVar1;
      uVar12 = CONCAT71((uint7)(param_2 >> 8) & 0xffffff,1);
      if ((iVar4 != 0) && (*puVar14 != 0)) {
        piVar10 = (int *)(lVar6 + -8);
        *piVar10 = *piVar10 + -1;
        if (*piVar10 == 0) {
          (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8,puVar14);
        }
      }
      goto LAB_25a0b0c01bd;
    }
  }
  _LastError = 0x13aa;
  uVar12 = 0;
LAB_25a0b0c01bd:
  return uVar12 & 0xffffffff;
}



/* Address: 25a0b0c01d0 */

void FUN_25a0b0c01d0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  uint *puVar13;
  int *piVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  
  piVar12 = *(int **)(param_1 + 1);
  if (piVar12 == (int *)0x0) {
    _LastError = 0xfa9;
    return;
  }
  uVar3 = piVar12[-1];
  if (uVar3 != 0) {
    puVar13 = (uint *)(piVar12 + -3);
    if (puVar13 == (uint *)0x0) {
      piVar12 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8,uVar3);
      if (piVar12 == (int *)0x0) {
        _LastError = 0x13aa;
        return;
      }
      piVar12[1] = 1;
      piVar12[2] = 0;
      piVar14 = piVar12 + 3;
      *(undefined2 *)(piVar12 + 3) = 0;
      *(int **)(param_1 + 1) = piVar14;
      *param_1 = *piVar12;
    }
    else {
      iVar4 = *param_1;
      if (((iVar4 == 0) || (*puVar13 < uVar3)) || (piVar14 = piVar12, piVar12[-2] != 1)) {
        piVar11 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8,uVar3);
        if (piVar11 == (int *)0x0) {
          _LastError = 0x13aa;
          return;
        }
        piVar11[1] = 1;
        piVar11[2] = 0;
        piVar14 = piVar11 + 3;
        *(undefined2 *)(piVar11 + 3) = 0;
        iVar5 = *piVar11;
        uVar10 = piVar12[-1];
        uVar6 = uVar3;
        if (uVar10 < uVar3) {
          uVar6 = uVar10;
        }
        if (uVar10 != 0) {
          uVar15 = (ulonglong)uVar6;
          uVar16 = uVar15 + (uVar15 == 0);
          uVar17 = 0;
          if (uVar6 < 8) goto LAB_25a0b0c031c;
          if ((ulonglong)((longlong)piVar11 - (longlong)puVar13) < 0x20) goto LAB_25a0b0c031c;
          uVar17 = (ulonglong)((uint)uVar16 & 0xfffffff8);
          uVar18 = 0;
          do {
            puVar2 = (undefined4 *)((longlong)piVar12 + uVar18);
            uVar7 = puVar2[1];
            uVar8 = puVar2[2];
            uVar9 = puVar2[3];
            puVar1 = (undefined4 *)((longlong)piVar14 + uVar18);
            *puVar1 = *puVar2;
            puVar1[1] = uVar7;
            puVar1[2] = uVar8;
            puVar1[3] = uVar9;
            uVar18 = uVar18 + 0x10;
          } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
          for (; uVar16 != uVar17; uVar17 = uVar17 + 1) {
LAB_25a0b0c031c:
            *(undefined2 *)((longlong)piVar14 + uVar17 * 2) =
                 *(undefined2 *)((longlong)piVar12 + uVar17 * 2);
          }
          piVar11[2] = uVar6;
          *(undefined2 *)((longlong)piVar14 + uVar15 * 2) = 0;
        }
        *param_1 = iVar5;
        *(int **)(param_1 + 1) = piVar14;
        if ((iVar4 != 0) && (*puVar13 != 0)) {
          piVar12 = piVar12 + -2;
          *piVar12 = *piVar12 + -1;
          if (*piVar12 == 0) {
            (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8,puVar13);
          }
        }
      }
    }
    uVar10 = (*(code *)0x7ff653aac030)(piVar14,uVar3);
    if (uVar10 != uVar3) {
      piVar14[-1] = uVar10;
      *(undefined2 *)((longlong)piVar14 + (ulonglong)uVar10 * 2) = 0;
    }
    return;
  }
  return;
}



/* Address: 25a0b0c03a0 */

ulonglong FUN_25a0b0c03a0(short *param_1,short *param_2,uint param_3)

{
  ulonglong uVar1;
  short *psVar2;
  short sVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  bool bVar12;
  
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    _LastError = 0xfa9;
    uVar7 = 0xffffffff;
  }
  else {
    uVar10 = *(uint *)(param_1 + -2);
    if ((uVar10 == 0) || (uVar4 = *(uint *)(param_2 + -2), uVar4 == 0)) {
      _LastError = 0x13ab;
      uVar7 = 0xffffffff;
    }
    else {
      uVar7 = 0;
      if (0 < (int)param_3) {
        uVar7 = (ulonglong)param_3;
      }
      if (param_1 == param_2) {
        uVar7 = (ulonglong)-(uint)(0 < (int)param_3);
      }
      else {
        uVar6 = (uint)uVar7;
        uVar9 = uVar10 - uVar6;
        if (((uVar6 <= uVar10 && uVar9 != 0) && (uVar4 <= uVar9)) &&
           (uVar10 = (uVar9 - uVar4) + 1, uVar10 != 0)) {
          psVar2 = param_1 + uVar7;
          sVar3 = *param_2;
          uVar11 = (ulonglong)uVar10;
          if (uVar4 < 2) {
            if (*psVar2 == sVar3) {
              return uVar7;
            }
            uVar8 = 0;
            do {
              if (uVar11 - 1 == uVar8) goto LAB_25a0b0c03da;
              uVar1 = uVar8 + 1;
              lVar5 = uVar8 + 1;
              uVar8 = uVar1;
            } while (param_1[uVar7 + lVar5] != sVar3);
            if (uVar1 < uVar11) {
              return uVar7 + uVar1 & 0xffffffff;
            }
          }
          else {
            bVar12 = true;
            uVar7 = 0;
            do {
              if (psVar2[uVar7] == sVar3) {
                uVar8 = 1;
                while( true ) {
                  if (psVar2[(int)uVar7 + (uint)uVar8] != param_2[uVar8]) break;
                  uVar8 = uVar8 + 1;
                  if (uVar4 == uVar8) goto LAB_25a0b0c04b6;
                }
                if (uVar4 == (uint)uVar8) {
LAB_25a0b0c04b6:
                  if (bVar12) {
                    return (ulonglong)(uVar6 + (int)uVar7);
                  }
                  break;
                }
              }
              uVar7 = uVar7 + 1;
              bVar12 = uVar7 < uVar11;
            } while (uVar7 != uVar11);
          }
        }
LAB_25a0b0c03da:
        uVar7 = 0xffffffff;
      }
    }
  }
  return uVar7;
}



/* Address: 25a0b0c04d0 */

ulonglong FUN_25a0b0c04d0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined8 unaff_RSI;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  
  uVar8 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (param_2 == 0) goto LAB_25a0b0c05dd;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_25a0b0c05dd;
  if (lVar3 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = *(uint *)(lVar3 + -4);
  }
  uVar7 = uVar2 + uVar12;
  uVar6 = 0x104;
  if ((0x103 < uVar7) &&
     ((0x7ffffffd < uVar7 || (uVar6 = (uVar7 >> 2) + uVar7, 0x7ffffffd < uVar6)))) {
    uVar6 = 0x7ffffffe;
  }
  cVar5 = FUN_25a0b0c0060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_25a0b0c05dd;
  }
  lVar3 = *(longlong *)(param_1 + 4);
  if (uVar9 != 0) {
    lVar1 = lVar3 + (ulonglong)uVar12 * 2;
    if (uVar2 < 0x10) {
      uVar10 = 0;
    }
    else if ((ulonglong)(lVar1 - param_2) < 0x20) {
      uVar10 = 0;
    }
    else {
      uVar10 = (ulonglong)(uVar2 & 0xfffffff8);
      uVar11 = 0;
      do {
        uVar4 = ((undefined8 *)(param_2 + uVar11))[1];
        *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(param_2 + uVar11);
        ((undefined8 *)(lVar1 + uVar11))[1] = uVar4;
        uVar11 = uVar11 + 0x10;
      } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
      if (uVar10 == uVar9) goto LAB_25a0b0c05d2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_25a0b0c05d2:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_25a0b0c05dd:
  return uVar8 & 0xffffffff;
}



/* Address: 25a0b0c05f0 */

void FUN_25a0b0c05f0(int *param_1,int *param_2,char param_3,void *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  
  if (param_1 == param_2) {
    return;
  }
  lVar7 = *(longlong *)(param_2 + 1);
  if (lVar7 == 0) {
    if ((((*param_1 != 0) && (lVar7 = *(longlong *)(param_1 + 1), lVar7 != 0)) &&
        ((int *)(lVar7 + -0xc) != (int *)0x0)) && (*(int *)(lVar7 + -0xc) != 0)) {
      piVar12 = (int *)(lVar7 + -8);
      *piVar12 = *piVar12 + -1;
      if (*piVar12 == 0) {
        (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    return;
  }
  if (param_3 == '\0') {
    if (((*param_1 != 0) && (lVar7 = *(longlong *)(param_1 + 1), lVar7 != 0)) &&
       ((piVar12 = (int *)(lVar7 + -0xc), piVar12 != (int *)0x0 && (*piVar12 != 0)))) {
      piVar1 = (int *)(lVar7 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8,piVar12);
      }
    }
    param_1[2] = param_2[2];
    uVar8 = *(undefined8 *)param_2;
    *(undefined8 *)param_1 = uVar8;
    if (*(longlong *)(param_1 + 1) == 0) {
      return;
    }
    if ((int)uVar8 == 0) {
      return;
    }
    piVar12 = (int *)(*(longlong *)(param_1 + 1) + -8);
    *piVar12 = *piVar12 + 1;
    return;
  }
  uVar4 = *(uint *)(lVar7 + -4);
  uVar14 = (ulonglong)uVar4;
  piVar12 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8,uVar14);
  if (piVar12 == (int *)0x0) {
    _LastError = 0x13aa;
                    /* WARNING: Subroutine does not return */
    runtime_fault_395c00((void *)0x25a0930b4c8,0x1f9,param_4);
  }
  piVar12[1] = 1;
  piVar12[2] = 0;
  piVar1 = piVar12 + 3;
  *(undefined2 *)(piVar12 + 3) = 0;
  iVar5 = *piVar12;
  if (uVar4 != 0) {
    if (uVar4 < 8) {
      uVar13 = 0;
    }
    else if ((ulonglong)((longlong)piVar12 + (0xc - lVar7)) < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar13 = (ulonglong)(uVar4 & 0xfffffff8);
      uVar15 = 0;
      do {
        puVar2 = (undefined4 *)(lVar7 + uVar15);
        uVar9 = puVar2[1];
        uVar10 = puVar2[2];
        uVar11 = puVar2[3];
        puVar3 = (undefined4 *)((longlong)piVar1 + uVar15);
        *puVar3 = *puVar2;
        puVar3[1] = uVar9;
        puVar3[2] = uVar10;
        puVar3[3] = uVar11;
        uVar15 = uVar15 + 0x10;
      } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar15);
      if (uVar13 == uVar14) goto LAB_25a0b0c0780;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar13 * 2) = *(undefined2 *)(lVar7 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_25a0b0c0780:
  piVar12[2] = uVar4;
  *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = 0;
  lVar7 = *(longlong *)(param_1 + 1);
  iVar6 = *param_1;
  *param_1 = iVar5;
  *(int **)(param_1 + 1) = piVar1;
  if (((iVar6 != 0) && (lVar7 != 0)) &&
     (((int *)(lVar7 + -0xc) != (int *)0x0 && (*(int *)(lVar7 + -0xc) != 0)))) {
    piVar12 = (int *)(lVar7 + -8);
    *piVar12 = *piVar12 + -1;
    if (*piVar12 == 0) {
      (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
      return;
    }
  }
  return;
}



/* Address: 25a0b0c0810 */

void FUN_25a0b0c0810(longlong param_1,uint param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  dword *pdVar4;
  wchar16 *pwVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  iVar1 = 0xfa9;
  if ((param_1 == 0) || (param_1 + -0xc == 0)) {
LAB_25a0b0c09a8:
    _LastError = iVar1;
    if ((runtime_string_result.text == (wchar16 *)0x0) ||
       (runtime_string_result.text == (wchar16 *)0xc)) {
      _LastError = 0xfa9;
    }
    else if ((*(int *)(runtime_string_result.text + -2) != 0) &&
            (cVar2 = FUN_25a0b0c0060(&runtime_string_result,0), pwVar5 = runtime_string_result.text,
            cVar2 != '\0')) {
      pwVar5[-2] = L'\0';
      pwVar5[-1] = L'\0';
      *pwVar5 = L'\0';
    }
    return;
  }
  uVar7 = *(uint *)(param_1 + -4);
  if (((int)param_2 < 0) && (param_2 = param_2 + uVar7, (int)param_2 < 0)) {
    iVar1 = 0x13ab;
    goto LAB_25a0b0c09a8;
  }
  uVar3 = uVar7 - param_2;
  iVar1 = 0x13ab;
  if (uVar7 < param_2 || uVar3 == 0) goto LAB_25a0b0c09a8;
  uVar7 = uVar3;
  if ((-1 < (int)param_3) && (uVar7 = param_3, (int)uVar3 < (int)param_3)) {
    _LastError = 0x13ab;
    uVar7 = uVar3;
  }
  uVar8 = (ulonglong)uVar7;
  iVar1 = _LastError;
  if (uVar7 == 0) goto LAB_25a0b0c09a8;
  lVar9 = param_1 + -0xc + (ulonglong)param_2 * 2 + 0xc;
  if (uVar7 == 0xffffffff) {
    uVar8 = 0xffffffff;
    do {
      uVar8 = (ulonglong)((int)uVar8 + 1);
    } while (*(short *)(lVar9 + uVar8 * 2) != 0);
  }
  uVar7 = (uint)uVar8;
  uVar6 = 0x7ffffffe;
  if (uVar7 < 0x7ffffffe) {
    uVar6 = uVar8;
  }
  pwVar5 = runtime_string_result.text + -6;
  if (runtime_string_result.text == (wchar16 *)0x0) {
    pwVar5 = (wchar16 *)0x0;
  }
  uVar3 = (uint)uVar6;
  if ((runtime_string_result.opaque != 0) && (pwVar5 != (wchar16 *)0x0)) {
    if ((uVar3 <= *(uint *)pwVar5) && (*(uint *)(pwVar5 + 2) == 1)) goto LAB_25a0b0c094b;
    if (*(uint *)pwVar5 != 0) {
      pwVar5 = pwVar5 + 2;
      *(uint *)pwVar5 = *(uint *)pwVar5 - 1;
      if (*(uint *)pwVar5 == 0) {
        (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
      }
    }
    runtime_string_result.text = (wchar16 *)0x0;
    runtime_string_result.opaque = 0;
  }
  pdVar4 = (dword *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8,uVar6);
  if (pdVar4 == (dword *)0x0) {
    _LastError = 0x13aa;
    return;
  }
  pdVar4[1] = 1;
  pdVar4[2] = 0;
  runtime_string_result.text = (wchar16 *)(pdVar4 + 3);
  *(undefined2 *)(pdVar4 + 3) = 0;
  runtime_string_result.opaque = *pdVar4;
LAB_25a0b0c094b:
  pwVar5 = runtime_string_result.text;
  if (uVar7 == 0) {
    *(uint *)(runtime_string_result.text + -2) = uVar3;
    pwVar5[uVar6] = L'\0';
    return;
  }
  (*(code *)&MT5_StringSubstr)(runtime_string_result.text,lVar9,uVar6 * 2);
  *(uint *)(pwVar5 + -2) = uVar3;
  pwVar5[uVar6] = L'\0';
  if (uVar7 < 0x7fffffff) {
    return;
  }
  _LastError = 0xfa8;
  return;
}



/* Address: 25a0b0c0a30 */

undefined8 FUN_25a0b0c0a30(void)

{
  return 0;
}



/* Address: 25a0b0c0a40 */

void FUN_25a0b0c0a40(undefined8 param_1,undefined4 param_2)

{
                    /* WARNING: Subroutine does not return */
  runtime_fault_395990((void *)0x25a0930b4c8,CONCAT22((short)((uint)param_2 >> 0x10),0x224));
}



/* Address: 25a0b0c0a60 */

void FUN_25a0b0c0a60(undefined8 param_1,undefined4 param_2)

{
                    /* WARNING: Subroutine does not return */
  runtime_fault_395990((void *)0x25a0930b4c8,CONCAT22((short)((uint)param_2 >> 0x10),0x21e));
}



/* Address: 25a0b0c0a80 */

void FUN_25a0b0c0a80(void)

{
  return;
}



/* Address: 25a0b0c0a90 */

void FUN_25a0b0c0a90(undefined8 *param_1)

{
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,*param_1,0x25a092f9c70);
  param_1[1] = &DAT_25a0b0dc010;
  return;
}



/* Address: 25a0b0c0ad0 */

undefined4 FUN_25a0b0c0ad0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_60 = 0;
  local_70 = 0;
  local_4c = 0;
  local_5c = 0;
  local_6c = 0;
  FUN_25a0b0c05f0(&local_70,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0dff28);
  local_80 = 0;
  local_7c = 0;
  FUN_25a0b0c05f0(&local_80,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0dff38);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = MT5_OrderSend;
  }
  else {
    pcVar2 = MT5_OrderSendAsync;
  }
  uVar1 = (*pcVar2)(0x25a0930b4c8,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_25a0b0c0ca2;
    ppuVar4 = &PTR_DAT_25a0b0dff78;
    ppuVar3 = &PTR_DAT_25a0b0dff68;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_25a0b0c0ca2;
    ppuVar4 = &PTR_DAT_25a0b0dff58;
    ppuVar3 = &PTR_DAT_25a0b0dff48;
  }
  FUN_25a0b0d1c60(&local_80,param_2,param_3);
  FUN_25a0b0c05f0(&local_60,&runtime_string_result,1,ppuVar3);
  FUN_25a0b0d37f0(param_1,&local_70,param_2);
  FUN_25a0b0c05f0(&local_50,&runtime_string_result,1,ppuVar4);
  MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0dd188,0x590008,&local_50,
               0x590008,&local_60);
LAB_25a0b0c0ca2:
  FUN_25a0b0c0000(&local_80);
  FUN_25a0b0c0000(&local_70);
  FUN_25a0b0c0000(&local_60);
  FUN_25a0b0c0000(&local_50);
  return uVar1;
}



/* Address: 25a0b0c0ce0 */

void FUN_25a0b0c0ce0(undefined8 *param_1)

{
  FUN_25a0b0c0000(param_1 + 0x41);
  FUN_25a0b0c0000((longlong)param_1 + 0x144);
  FUN_25a0b0c0000((longlong)param_1 + 0x84);
  FUN_25a0b0c0000((longlong)param_1 + 0x34);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,*param_1,0x25a092f9c70);
  param_1[1] = &DAT_25a0b0dc010;
  return;
}



/* Address: 25a0b0c0d50 */

void FUN_25a0b0c0d50(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x24) != 0) {
    MT5_ObjectDelete((void *)0x25a0930b4c8,*(longlong *)(param_1 + 0x18),(void *)(param_1 + 0x20));
    *(undefined8 *)(param_1 + 0x18) = 0;
    FUN_25a0b0c05f0((void *)(param_1 + 0x20),&DAT_25a0b0dc150,0,&PTR_DAT_25a0b0e0b50);
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  }
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,param_1 + 0x60);
  if (*(longlong *)(param_1 + 0x34) != 0) {
    (*(code *)&MT5_ResourceFree)(0x25a0930b4c8,param_1 + 0x30);
    FUN_25a0b0c05f0(param_1 + 0x30,&DAT_25a0b0dc150,0,&PTR_DAT_25a0b0e0b60);
  }
  *(undefined8 *)(param_1 + 0x3c) = 0;
  return;
}



/* Address: 25a0b0c0e30 */

ulonglong FUN_25a0b0c0e30(longlong param_1,longlong param_2,int param_3,int param_4,
                         undefined4 param_5)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  int iVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined4 local_c0;
  longlong local_bc;
  int local_b4;
  undefined4 local_b0;
  longlong local_ac;
  undefined4 local_a0;
  longlong local_9c;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  longlong local_7c;
  undefined4 local_70;
  longlong local_6c;
  undefined4 local_60;
  longlong local_5c;
  longlong local_50;
  longlong local_48;
  
  local_80 = 0;
  local_60 = 0;
  local_90 = 0;
  local_c0 = 0;
  local_b0 = 0;
  local_70 = 0;
  local_a0 = 0;
  local_7c = 0;
  local_5c = 0;
  local_8c = 0;
  local_bc = 0;
  local_ac = 0;
  local_6c = 0;
  local_9c = 0;
  FUN_25a0b0c0d50();
  if ((0 < param_3) && (0 < param_4)) {
    local_48 = param_1 + 0x60;
    iVar9 = (*(code *)&runtime_array_helper_7aa0e0)(0x25a0930b4c8,local_48,param_4 * param_3,0);
    if (0 < iVar9) {
      local_a0 = 0;
      local_9c = 0;
      local_50 = param_2;
      uVar11 = MT5_ChartID((void *)0x25a0930b4c8);
      runtime_cast_to_string((void *)0x25a0930b4c8,uVar11,0x55,&local_70);
      uVar10 = MT5_GetTickCount();
      runtime_cast_to_string((void *)0x25a0930b4c8,(ulonglong)uVar10,0x53,&local_b0);
      FUN_25a0b0c05f0(&local_c0,&local_70);
      lVar12 = local_ac;
      if (local_ac != 0) {
        uVar10 = *(uint *)(local_ac + -4);
        uVar11 = (ulonglong)uVar10;
        if ((uVar11 == 0) && (local_bc != 0)) goto LAB_25a0b0c10e9;
        if (local_bc == 0) {
          uVar18 = 0;
          uVar17 = uVar10;
        }
        else {
          uVar18 = *(uint *)(local_bc + -4);
          uVar17 = uVar10 + uVar18;
        }
        cVar8 = FUN_25a0b0c0060(&local_c0);
        if (cVar8 != '\0') {
          if (uVar11 != 0) {
            lVar1 = local_bc + (ulonglong)uVar18 * 2;
            if (uVar10 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar12) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar15 = 0;
              uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar12 + uVar15);
                uVar5 = puVar2[1];
                uVar6 = puVar2[2];
                uVar7 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *puVar2;
                puVar3[1] = uVar5;
                puVar3[2] = uVar6;
                puVar3[3] = uVar7;
                uVar15 = uVar15 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar13 == uVar11) goto LAB_25a0b0c10d2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar12 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar11 != uVar13);
          }
LAB_25a0b0c10d2:
          *(uint *)(local_bc + -4) = uVar17;
          *(undefined2 *)(local_bc + (ulonglong)uVar17 * 2) = 0;
          goto LAB_25a0b0c10e9;
        }
LAB_25a0b0c17ea:
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2300ff000801f9);
LAB_25a0b0c180a:
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3e00ff000801f9);
LAB_25a0b0c182a:
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x140101000801f9);
LAB_25a0b0c184a:
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3d0101000801f9);
        pcVar4 = (code *)swi(3);
        uVar11 = (*pcVar4)();
        return uVar11;
      }
LAB_25a0b0c10e9:
      uVar10 = 0;
      FUN_25a0b0c05f0(&local_90,&local_c0,0,&PTR_DAT_25a0b0e0ad0);
      uVar18 = DAT_25a0b0de19c;
      uVar11 = (ulonglong)DAT_25a0b0de19c;
      if ((uVar11 != 0) || (local_8c == 0)) {
        if (local_8c != 0) {
          uVar10 = *(uint *)(local_8c + -4);
        }
        uVar16 = DAT_25a0b0de19c + uVar10;
        uVar17 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar17 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar17)))) {
          uVar17 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_90,uVar17);
        if (cVar8 == '\0') {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3a00ff000801f9);
          goto LAB_25a0b0c17ea;
        }
        if (uVar11 != 0) {
          lVar12 = local_8c + (ulonglong)uVar10 * 2;
          if (uVar18 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar12 - 0x25a0b0de1a0U < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar15 = 0;
            uVar13 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)(uVar15 + 0x25a0b0de1a4);
              uVar6 = *(undefined4 *)(uVar15 + 0x25a0b0de1a8);
              uVar7 = *(undefined4 *)(uVar15 + 0x25a0b0de1ac);
              puVar2 = (undefined4 *)(lVar12 + uVar15);
              *puVar2 = *(undefined4 *)((longlong)&DAT_25a0b0de1a0 + uVar15);
              puVar2[1] = uVar5;
              puVar2[2] = uVar6;
              puVar2[3] = uVar7;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar13 == uVar11) goto LAB_25a0b0c1212;
          }
          do {
            *(undefined2 *)(lVar12 + uVar13 * 2) = (&DAT_25a0b0de1a0)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar11 != uVar13);
        }
LAB_25a0b0c1212:
        *(uint *)(local_8c + -4) = uVar16;
        *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
      }
      uVar11 = MT5_GetMicrosecondCount((void *)0x25a0930b4c8);
      runtime_cast_to_string((void *)0x25a0930b4c8,(ulonglong)((uint)uVar11 & 0x3ff),0x56,&local_60)
      ;
      iVar9 = 0;
      FUN_25a0b0c05f0(&local_80,&local_90,0);
      lVar12 = local_5c;
      local_b4 = param_4;
      if (local_5c != 0) {
        uVar10 = *(uint *)(local_5c + -4);
        uVar11 = (ulonglong)uVar10;
        if ((uVar11 != 0) || (local_7c == 0)) {
          if (local_7c == 0) {
            uVar18 = 0;
            uVar17 = uVar10;
          }
          else {
            uVar18 = *(uint *)(local_7c + -4);
            uVar17 = uVar10 + uVar18;
          }
          cVar8 = FUN_25a0b0c0060(&local_80);
          if (cVar8 == '\0') goto LAB_25a0b0c180a;
          if (uVar11 != 0) {
            lVar1 = local_7c + (ulonglong)uVar18 * 2;
            if (uVar10 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar12) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar15 = 0;
              uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar12 + uVar15);
                uVar5 = puVar2[1];
                uVar6 = puVar2[2];
                uVar7 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *puVar2;
                puVar3[1] = uVar5;
                puVar3[2] = uVar6;
                puVar3[3] = uVar7;
                uVar15 = uVar15 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar13 == uVar11) goto LAB_25a0b0c1392;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar12 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar11 != uVar13);
          }
LAB_25a0b0c1392:
          *(uint *)(local_7c + -4) = uVar17;
          *(undefined2 *)(local_7c + (ulonglong)uVar17 * 2) = 0;
        }
      }
      iVar14 = local_b4;
      FUN_25a0b0c05f0(&local_a0,&local_80,0,&PTR_DAT_25a0b0e0af0);
      if ((local_9c != 0) && (iVar9 = 0, local_9c != 0xc)) {
        iVar9 = *(int *)(local_9c + -4);
      }
      FUN_25a0b0c0810(*(undefined8 *)(local_50 + 4),0,0x3f - iVar9);
      FUN_25a0b0c05f0(&local_70,&runtime_string_result,1,&PTR_DAT_25a0b0e0b00);
      FUN_25a0b0c05f0(&local_b0,&string_ref_25a0b0de1c8,0);
      lVar12 = local_6c;
      if (local_6c != 0) {
        uVar10 = *(uint *)(local_6c + -4);
        uVar11 = (ulonglong)uVar10;
        if ((uVar11 != 0) || (local_ac == 0)) {
          if (local_ac == 0) {
            uVar18 = 0;
            uVar17 = uVar10;
          }
          else {
            uVar18 = *(uint *)(local_ac + -4);
            uVar17 = uVar10 + uVar18;
          }
          cVar8 = FUN_25a0b0c0060(&local_b0);
          if (cVar8 == '\0') goto LAB_25a0b0c182a;
          if (uVar11 != 0) {
            lVar1 = local_ac + (ulonglong)uVar18 * 2;
            if (uVar10 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar12) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar15 = 0;
              uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar12 + uVar15);
                uVar5 = puVar2[1];
                uVar6 = puVar2[2];
                uVar7 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *puVar2;
                puVar3[1] = uVar5;
                puVar3[2] = uVar6;
                puVar3[3] = uVar7;
                uVar15 = uVar15 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar13 == uVar11) goto LAB_25a0b0c1552;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar12 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar11 != uVar13);
          }
LAB_25a0b0c1552:
          *(uint *)(local_ac + -4) = uVar17;
          *(undefined2 *)(local_ac + (ulonglong)uVar17 * 2) = 0;
          iVar14 = local_b4;
        }
      }
      FUN_25a0b0c05f0(&local_c0,&local_b0,0);
      lVar12 = local_9c;
      if (local_9c != 0) {
        uVar10 = *(uint *)(local_9c + -4);
        uVar11 = (ulonglong)uVar10;
        if ((uVar11 != 0) || (local_bc == 0)) {
          if (local_bc == 0) {
            uVar18 = 0;
            uVar17 = uVar10;
          }
          else {
            uVar18 = *(uint *)(local_bc + -4);
            uVar17 = uVar10 + uVar18;
          }
          cVar8 = FUN_25a0b0c0060(&local_c0);
          if (cVar8 == '\0') goto LAB_25a0b0c184a;
          if (uVar11 != 0) {
            lVar1 = local_bc + (ulonglong)uVar18 * 2;
            if (uVar10 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar12) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar15 = 0;
              uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar12 + uVar15);
                uVar5 = puVar2[1];
                uVar6 = puVar2[2];
                uVar7 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *puVar2;
                puVar3[1] = uVar5;
                puVar3[2] = uVar6;
                puVar3[3] = uVar7;
                uVar15 = uVar15 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar13 == uVar11) goto LAB_25a0b0c1682;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar12 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar11 != uVar13);
          }
LAB_25a0b0c1682:
          *(uint *)(local_bc + -4) = uVar17;
          *(undefined2 *)(local_bc + (ulonglong)uVar17 * 2) = 0;
          iVar14 = local_b4;
        }
      }
      FUN_25a0b0c05f0(param_1 + 0x30,&local_c0,0,&PTR_DAT_25a0b0e0b30);
      if (((*(int *)(param_1 + 100) == 4) && (*(void **)(param_1 + 0x7c) != (void *)0x0)) &&
         (uVar11 = (ulonglong)*(uint *)(param_1 + 0x68), uVar11 != 0)) {
        lVar12 = -3;
        do {
          uVar13 = (ulonglong)*(uint *)(param_1 + 0x78 + lVar12 * 4);
          if (uVar13 == 0) break;
          uVar11 = uVar11 * uVar13;
          lVar12 = lVar12 + 1;
        } while (lVar12 != 0);
        if (uVar11 != 0) {
          memset(*(void **)(param_1 + 0x7c),0,uVar11 << 2);
        }
      }
      cVar8 = (*(code *)&MT5_ResourceCreate)
                        (0x25a0930b4c8,param_1 + 0x30,local_48,param_3,iVar14,0,0,0,param_5);
      if (cVar8 != '\0') {
        *(int *)(param_1 + 0x3c) = param_3;
        *(int *)(param_1 + 0x40) = iVar14;
        *(undefined4 *)(param_1 + 0x44) = param_5;
        FUN_25a0b0c0000(&local_a0);
        uVar11 = CONCAT71((int7)((ulonglong)param_1 >> 8),1);
        goto LAB_25a0b0c1781;
      }
      FUN_25a0b0c0000(&local_a0);
    }
  }
  FUN_25a0b0c0d50(param_1);
  uVar11 = 0;
LAB_25a0b0c1781:
  FUN_25a0b0c0000(&local_70);
  FUN_25a0b0c0000(&local_b0);
  FUN_25a0b0c0000(&local_c0);
  FUN_25a0b0c0000(&local_90);
  FUN_25a0b0c0000(&local_60);
  FUN_25a0b0c0000(&local_80);
  return uVar11 & 0xffffffff;
}



/* Address: 25a0b0c1870 */

void FUN_25a0b0c1870(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,param_1 + 0x60);
  FUN_25a0b0c0000(param_1 + 0x48);
  FUN_25a0b0c0000(param_1 + 0x30);
  if ((((*(int *)(param_1 + 0x20) != 0) && (lVar2 = *(longlong *)(param_1 + 0x24), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
    }
  }
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(int *)(param_1 + 0x20) = 0;
  return;
}



/* Address: 25a0b0c18c0 */

undefined8 FUN_25a0b0c18c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_EAX;
  longlong lVar8;
  MqlStringAnalysisView *pMVar9;
  int iVar10;
  MqlStringAnalysisView *pMVar11;
  MqlStringAnalysisView *pMVar12;
  undefined8 uVar13;
  MqlStringAnalysisView *value_2;
  undefined **ppuVar14;
  double dVar15;
  undefined4 local_98;
  undefined8 local_94;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  MqlStringAnalysisView local_70;
  longlong local_60;
  
  local_70.opaque = 0;
  local_98 = 0;
  local_70.text = (wchar16 *)0x0;
  local_94 = 0;
  DAT_25a0b0e2590 = 0;
  iVar6 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,6);
  DAT_25a0b0e258c = iVar6 != 0;
  iVar6 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,7);
  DAT_25a0b0e258d = iVar6 != 0;
  iVar7 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,8);
  iVar4 = InpTSL_Distance;
  iVar3 = InpTSL_Step;
  iVar2 = InpTSL_Start;
  iVar1 = EAMode;
  iVar6 = BrokerType;
  DAT_25a0b0e258e = iVar7 != 0;
  DAT_25a0b0e258f = DAT_25a0b0e258c == '\0' || (bool)DAT_25a0b0e258e;
  state_v_225ad = UseFixedLot;
  dVar15 = DAT_25a0b0dba90;
  if (FixedLot <= DAT_25a0b0dba90) {
    dVar15 = FixedLot;
  }
  state_v_225b0 =
       (double)(-(ulonglong)(FixedLot < DAT_25a0b0dba98) & (ulonglong)DAT_25a0b0dba98 |
               ~-(ulonglong)(FixedLot < DAT_25a0b0dba98) & (ulonglong)dVar15);
  dVar15 = DAT_25a0b0dbaa0;
  if (RiskPercent <= DAT_25a0b0dbaa0) {
    dVar15 = RiskPercent;
  }
  state_v_225b8 =
       (double)(-(ulonglong)(RiskPercent < DAT_25a0b0dba98) & (ulonglong)DAT_25a0b0dba98 |
               ~-(ulonglong)(RiskPercent < DAT_25a0b0dba98) & (ulonglong)dVar15);
  state_v_225c0 = UseDD_Protection;
  state_v_225c4 = 100;
  if (MaxConsecLosses < 100) {
    state_v_225c4 = MaxConsecLosses;
  }
  iVar7 = 1;
  if (state_v_225c4 < 2) {
    state_v_225c4 = 1;
  }
  dVar15 = DAT_25a0b0dbaa8;
  if (DD_LotMultiplier <= DAT_25a0b0dbaa8) {
    dVar15 = DD_LotMultiplier;
  }
  state_v_225c8 =
       (double)(-(ulonglong)(DD_LotMultiplier < DAT_25a0b0dba98) & (ulonglong)DAT_25a0b0dba98 |
               ~-(ulonglong)(DD_LotMultiplier < DAT_25a0b0dba98) & (ulonglong)dVar15);
  dVar15 = DAT_25a0b0dbaa0;
  if (MaxDailyDD_Pct <= DAT_25a0b0dbaa0) {
    dVar15 = MaxDailyDD_Pct;
  }
  state_v_225d0 = (double)(~-(ulonglong)(MaxDailyDD_Pct < 0.0) & (ulonglong)dVar15);
  if (EAMode == 2) {
    state_v_223c4 = 0x10;
    state_v_223b0 = 0x20;
    state_v_223ac = 0x43;
    state_v_223a8 = 0x83;
    state_v_223a0 = 0xba;
    state_v_22398 = 0x12e;
    state_v_22370 = 1;
  }
  else {
    state_v_223c4 = 0x12;
    state_v_223ac = 0x1e;
    state_v_223a8 = 0x3c;
    state_v_223a0 = 0xa4;
    state_v_223b0 = 0x1e;
    state_v_22398 = 0x352;
    if (Mode1Stop == 1) {
      state_v_22398 = 0xdc;
    }
    state_v_22370 = 5;
  }
  state_v_2236c = true;
  state_v_22378 = 658.0;
  state_v_22380 = 0.6;
  state_v_22388 = 123.0;
  state_v_22390 = 2.1;
  state_v_22374 = true;
  state_v_223a4 = true;
  state_v_2239c = 0xc5c;
  state_v_22375 = true;
  state_v_223b4 = true;
  state_v_223c0 = true;
  state_v_223b5 = true;
  state_v_223c1 = true;
  state_v_223b6 = true;
  state_v_223b8 = 0.62;
  state_v_223b7 = true;
  state_v_223c8 = 0x78;
  if (BrokerType == 1) {
    if (EAMode == 1) {
      state_v_223ac = 0x1cc;
      state_v_223a8 = 0x168;
      state_v_22398 = 0x2134;
      if (Mode1Stop == 1) {
        state_v_22398 = 0x898;
      }
      state_v_223b0 = 0x186;
    }
    else {
      state_v_223b0 = 0x140;
      state_v_223ac = 0x29e;
      state_v_223a8 = 0x51e;
      state_v_22398 = 0xbcc;
    }
    state_v_2239c = 0x7b98;
    state_v_223c8 = 0x4b0;
    state_v_22378 = 6580.0;
    iVar7 = 10;
    state_v_22388 = 1230.0;
  }
  if (0 < InpSL_Points) {
    iVar10 = 1000000;
    if (InpSL_Points < 1000000) {
      iVar10 = InpSL_Points;
    }
    state_v_22398 = iVar10 * iVar7;
  }
  if (0 < InpTP_Points) {
    iVar10 = 1000000;
    if (InpTP_Points < 1000000) {
      iVar10 = InpTP_Points;
    }
    state_v_2239c = iVar10 * iVar7;
  }
  if (0 < InpTSL_Start) {
    iVar10 = 1000000;
    if (InpTSL_Start < 1000000) {
      iVar10 = InpTSL_Start;
    }
    state_v_223a8 = iVar10 * iVar7;
  }
  if (0 < InpTSL_Step) {
    iVar10 = 1000000;
    if (InpTSL_Step < 1000000) {
      iVar10 = InpTSL_Step;
    }
    state_v_223ac = iVar10 * iVar7;
  }
  local_78 = InpTP_Points;
  local_74 = InpSL_Points;
  if (0 < InpTSL_Distance) {
    iVar10 = 1000000;
    if (InpTSL_Distance < 1000000) {
      iVar10 = InpTSL_Distance;
    }
    state_v_223b0 = iVar10 * iVar7;
  }
  state_v_2229d = 0x410;
  state_v_22295 = (longlong)InpMagic;
  if (BrokerType != 1) {
    state_v_2229d = 0x68;
  }
  if (DAT_25a0b0e258c != '\0') {
    state_v_2229d = 0x68;
  }
  state_v_22294 = false;
  state_v_222a5 = 0;
  local_60 = state_v_22295;
  MT5_AccountInfoString((void *)0x25a0930b4c8,0x24);
  FUN_25a0b0c05f0(&local_70,&runtime_string_result,1,&PTR_DAT_25a0b0dfca0);
  FUN_25a0b0c05f0(&DAT_25a0b0e2580,&local_70,0,&PTR_DAT_25a0b0dfcb0);
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x10);
  DAT_25a0b0e2570 = runtime_double_result;
  if (runtime_double_result <= 0.0) {
    uVar13 = 0;
    if (DAT_25a0b0e258d != '\0') goto LAB_25a0b0c2a94;
    pMVar11 = &string_ref_25a0b0dc308;
  }
  else {
    local_80 = iVar2;
    local_84 = iVar3;
    local_88 = iVar4;
    local_7c = iVar1;
    lVar8 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
    DAT_25a0b0e2578 = (double)((int)lVar8 + 5) * DAT_25a0b0e2570;
    if (DAT_25a0b0e2578 <= DAT_25a0b0e2570 * state_v_22378) {
      DAT_25a0b0e2578 = DAT_25a0b0e2570 * state_v_22378;
    }
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1b);
    DAT_25a0b0e4928 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1a);
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x24);
    DAT_25a0b0e4930 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x22);
    DAT_25a0b0e4938 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x23);
    DAT_25a0b0e4940 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x37);
    DAT_25a0b0e4948 = runtime_double_result;
    lVar8 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x11);
    extraout_EAX = (undefined4)lVar8;
    DAT_25a0b0e4950 = extraout_EAX;
    if ((((DAT_25a0b0e4928 <= 0.0) || (DAT_25a0b0e4930 <= 0.0)) || (DAT_25a0b0e4938 <= 0.0)) ||
       (DAT_25a0b0e4940 <= 0.0)) {
      uVar13 = 0;
      if (DAT_25a0b0e258d != '\0') goto LAB_25a0b0c2a94;
      pMVar11 = &string_ref_25a0b0dc370;
    }
    else {
      lVar8 = MT5_Dispatch((void *)0x25a0930b4c8,0x53,3,0x590008,&DAT_25a0b0dc150,0x520004,0xf,
                           0x520004,0x3d);
      DAT_25a0b0e23cc = (int)lVar8;
      if (DAT_25a0b0e23cc == -1) {
        uVar13 = 0;
        if (DAT_25a0b0e258d != '\0') goto LAB_25a0b0c2a94;
        pMVar11 = &string_ref_25a0b0dc398;
      }
      else {
        if ((DAT_25a0b0e23f0._2_2_ & 0xf) != 0) {
          DAT_25a0b0e23f0._2_2_ = DAT_25a0b0e23f0._2_2_ | 0x10;
        }
        lVar8 = MT5_Dispatch((void *)0x25a0930b4c8,0x58,6,0x590008,&DAT_25a0b0dc150,0x520004,0xf,
                             0x520004,4,0x520004,0,0x520004,1,0x520004,1);
        DAT_25a0b0e23d0 = (int)lVar8;
        lVar8 = MT5_Dispatch((void *)0x25a0930b4c8,0x58,6,0x590008,&DAT_25a0b0dc150,0x520004,0xf,
                             0x520004,0x31,0x520004,0,0x520004,1,0x520004,1);
        DAT_25a0b0e23d4 = (int)lVar8;
        lVar8 = MT5_Dispatch((void *)0x25a0930b4c8,0x58,6,0x590008,&DAT_25a0b0dc150,0x520004,
                             state_v_22370,0x520004,0xec,0x520004,0,0x520004,1,0x520004,1);
        DAT_25a0b0e23d8 = (int)lVar8;
        lVar8 = MT5_Dispatch((void *)0x25a0930b4c8,0x58,6,0x590008,&DAT_25a0b0dc150,0x520004,
                             state_v_22370,0x520004,0x3ef,0x520004,0,0x520004,1,0x520004,1);
        DAT_25a0b0e23dc = (int)lVar8;
        if (((DAT_25a0b0e23d0 != -1) && (DAT_25a0b0e23d4 != -1)) &&
           ((DAT_25a0b0e23d8 != -1 && (DAT_25a0b0e23dc != -1)))) {
          if ((DAT_25a0b0e2430._2_2_ & 0xf) != 0) {
            DAT_25a0b0e2430._2_2_ = DAT_25a0b0e2430._2_2_ | 0x10;
          }
          if ((DAT_25a0b0e2470._2_2_ & 0xf) != 0) {
            DAT_25a0b0e2470._2_2_ = DAT_25a0b0e2470._2_2_ | 0x10;
          }
          if ((DAT_25a0b0e24b0._2_2_ & 0xf) != 0) {
            DAT_25a0b0e24b0._2_2_ = DAT_25a0b0e24b0._2_2_ | 0x10;
          }
          if ((DAT_25a0b0e24f0._2_2_ & 0xf) != 0) {
            DAT_25a0b0e24f0._2_2_ = DAT_25a0b0e24f0._2_2_ | 0x10;
          }
          DAT_25a0b0e25a0 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x4018,0);
          MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x25);
          DAT_25a0b0e2594 = 0;
          DAT_25a0b0e25d8 = 0;
          DAT_25a0b0e46e0 = 0;
          DAT_25a0b0e25a8 = 0;
          DAT_25a0b0e25ac = 0;
          DAT_25a0b0e26b8 = 0;
          DAT_25a0b0e4c80 = 0;
          DAT_25a0b0e4920 = 0;
          DAT_25a0b0e26b0 = 0xbff0000000000000;
          DAT_25a0b0e2598 = runtime_double_result;
          DAT_25a0b0e4718 = 0;
          DAT_25a0b0e26d0 = 0;
          DAT_25a0b0e4710 = 0;
          DAT_25a0b0e46e4 = 0xffffffff;
          DAT_25a0b0e46e8 = '\0';
          DAT_25a0b0e46e9 = 0;
          DAT_25a0b0e46ea = 0;
          FUN_25a0b0c2ef0();
          state_v_22630 = (double)state_v_22398 * DAT_25a0b0e2570;
          state_v_22638 = (double)state_v_2239c * DAT_25a0b0e2570;
          state_v_22640 = (double)state_v_223a8 * DAT_25a0b0e2570;
          DAT_25a0b0e2658 = 0;
          state_v_22648 = (double)state_v_223ac * DAT_25a0b0e2570;
          state_v_22650 = (double)state_v_223b0 * DAT_25a0b0e2570;
          DAT_25a0b0e2660 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0xf,0);
          bVar5 = UseNewsFilter;
          DAT_25a0b0e2668 = 1;
          DAT_25a0b0e2670 = 0;
          DAT_25a0b0e266c = 0;
          if ((UseNewsFilter != false) && (DAT_25a0b0e258c == '\0')) {
            FUN_25a0b0c3000();
          }
          if (DAT_25a0b0e258f != '\0') {
            lVar8 = MT5_ChartID((void *)0x25a0930b4c8);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x15,0x90405);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x16,0xb9aaaf);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x17,0x210f16);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1c,0xff4ea6);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1d,0x69545c);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x19,0xff4ea6);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1a,0x69545c);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1b,0xff4ea6);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x18,0x6e2c4d);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1e,0xff58ae);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x1f,0xaa3470);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x21,0x5f41c4);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x11,0);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x10,0);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0xc,0);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,2,1);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,4,1);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,5,3);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0,1);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x12,0);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0xd,1);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0xe,0);
            MT5_ChartSetInteger((void *)0x25a0930b4c8,lVar8,0x22,1);
            (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,lVar8);
            if (ShowPanel != false) {
              FUN_25a0b0c56c0();
              FUN_25a0b0c5bc0();
              FUN_25a0b0c60f0();
              DAT_25a0b0e2658 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
              DAT_25a0b0e2668 = 0;
            }
          }
          FUN_25a0b0c8810();
          if (DAT_25a0b0e258f != '\0') {
            local_98 = 0;
            local_94 = 0;
            if (local_7c == 2) {
              pMVar11 = &string_ref_25a0b0dc400;
              ppuVar14 = &PTR_DAT_25a0b0dfcc0;
            }
            else {
              pMVar11 = &string_ref_25a0b0dc480;
              ppuVar14 = &PTR_DAT_25a0b0dfcd0;
              if (Mode1Stop == 1) {
                pMVar11 = &string_ref_25a0b0dc440;
              }
            }
            FUN_25a0b0c05f0(&local_98,pMVar11,0,ppuVar14);
            pMVar11 = &string_ref_25a0b0dc570;
            if (iVar6 == 1) {
              pMVar11 = &string_ref_25a0b0dc540;
            }
            MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0dc508,0x590008,
                         &local_98,0x590008,pMVar11,0x520004,(int)local_60);
            pMVar12 = &string_ref_25a0b0dc688;
            pMVar11 = &string_ref_25a0b0dc688;
            if (UsePropFirmDelay != false) {
              MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dc6b8,0x520004,
                           PropFirmDelaySec);
              pMVar11 = &local_70;
              FUN_25a0b0c05f0(pMVar11,&runtime_string_result,1,&PTR_DAT_25a0b0dfce0);
            }
            value_2 = &string_ref_25a0b0dc688;
            pMVar9 = &string_ref_25a0b0dc688;
            if (DAT_25a0b0e236b != '\0') {
              pMVar9 = &string_ref_25a0b0dc658;
            }
            if (bVar5 != false) {
              value_2 = &string_ref_25a0b0dc658;
            }
            if (UseHolidayFilter != false) {
              pMVar12 = &string_ref_25a0b0dc658;
            }
            MT5_Dispatch((void *)0x25a0930b4c8,0xd,5,0x590008,&string_ref_25a0b0dc630,0x590008,
                         pMVar12,0x590008,value_2,0x590008,pMVar9,0x590008,pMVar11);
            pMVar11 = &string_ref_25a0b0dc170;
            pMVar12 = &string_ref_25a0b0dc170;
            pMVar9 = &string_ref_25a0b0dc170;
            if (0 < local_88) {
              pMVar12 = &string_ref_25a0b0dc790;
            }
            if (0 < local_84) {
              pMVar12 = &string_ref_25a0b0dc790;
            }
            if (0 < local_80) {
              pMVar12 = &string_ref_25a0b0dc790;
            }
            if (0 < local_78) {
              pMVar9 = &string_ref_25a0b0dc790;
            }
            if (0 < local_74) {
              pMVar11 = &string_ref_25a0b0dc790;
            }
            MT5_Dispatch((void *)0x25a0930b4c8,0xd,9,0x590008,&string_ref_25a0b0dc760,0x520004,
                         state_v_22398,0x590008,pMVar11,0x520004,state_v_2239c,0x590008,pMVar9,
                         0x520004,state_v_223a8,0x520004,state_v_223ac,0x520004,state_v_223b0,
                         0x590008,pMVar12);
            if (bVar5 != false) {
              pMVar12 = &string_ref_25a0b0dc8d8;
              pMVar11 = &string_ref_25a0b0dc878;
              if (DAT_25a0b0e46e8 != '\0') {
                pMVar12 = &string_ref_25a0b0dc8b0;
              }
              if (((NewsCurrencies.text != (wchar16 *)0x0) &&
                  (NewsCurrencies.text != (wchar16 *)0xc)) &&
                 (0 < *(int *)(NewsCurrencies.text + -2))) {
                pMVar11 = (MqlStringAnalysisView *)&NewsCurrencies;
              }
              MT5_Dispatch((void *)0x25a0930b4c8,0xd,6,0x590008,&string_ref_25a0b0dc848,0x590008,
                           pMVar11,0x520004,NewsStopBeforeMin,0x520004,NewsStopAfterMin,0x590008,
                           pMVar12,0x520004,DAT_25a0b0e46e0);
            }
            FUN_25a0b0c0000(&local_98);
          }
          uVar13 = 0;
          DAT_25a0b0e2590 = 1;
          goto LAB_25a0b0c2a94;
        }
        uVar13 = 0;
        if (DAT_25a0b0e258d != '\0') goto LAB_25a0b0c2a94;
        pMVar11 = &string_ref_25a0b0dc3c8;
      }
    }
  }
  MT5_Dispatch((void *)0x25a0930b4c8,2,2,0x590008,&string_ref_25a0b0de200,0x590008,pMVar11);
  uVar13 = 1;
LAB_25a0b0c2a94:
  FUN_25a0b0c0000(&local_70);
  return uVar13;
}



/* Address: 25a0b0c2ef0 */

void FUN_25a0b0c2ef0(void)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  
  iVar4 = 0;
  lVar1 = MT5_TimeGMT((void *)0x25a0930b4c8,(void *)0x0);
  if (0 < lVar1) {
    lVar2 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
    dVar6 = (double)(lVar2 - lVar1) / DAT_25a0b0dbab0;
    uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar5 - 0x3ff;
    dVar7 = dVar6;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000);
        }
      }
      else {
        bVar3 = (byte)lVar1;
        if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar7 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                          -0x10000000000000 >> (bVar3 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar7 = dVar6 + dVar6;
    }
    iVar4 = (int)(dVar7 * DAT_25a0b0dbab0);
  }
  DAT_25a0b0e470c = iVar4;
  return;
}



/* Address: 25a0b0c3000 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void FUN_25a0b0c3000(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  code *pcVar6;
  undefined4 uVar7;
  char cVar8;
  undefined4 uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  int *piVar13;
  int *piVar14;
  ulonglong uVar15;
  int *piVar16;
  uint uVar17;
  MqlStringAnalysisView *pMVar18;
  uint uVar19;
  int iVar20;
  short *psVar21;
  uint uVar22;
  uint uVar23;
  longlong lVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  uint uVar27;
  longlong *plVar28;
  undefined **ppuVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  bool bVar33;
  bool bVar34;
  undefined4 uVar35;
  undefined4 local_2188;
  short *local_2184;
  int local_2178;
  int *local_2174;
  undefined4 local_2168;
  short *local_2164;
  undefined8 local_2158;
  undefined4 local_2150;
  longlong local_214c;
  int local_2144;
  uint local_2140;
  uint local_213c;
  ulonglong local_2138;
  undefined4 local_2130;
  longlong local_212c;
  uint local_2124;
  ulonglong local_2120;
  undefined4 local_2118;
  longlong local_2114;
  undefined4 local_2108;
  undefined2 *local_2104;
  undefined4 local_20f8;
  longlong local_20f4;
  ulonglong local_20e8;
  MqlStringAnalysisView local_20e0;
  undefined4 uStack_20d4;
  undefined8 local_20d0;
  undefined8 local_20c8;
  undefined8 local_20c0;
  undefined8 local_20b8;
  undefined4 local_20b0;
  undefined4 local_20a8;
  short *local_20a4;
  int local_209c;
  undefined4 local_2098;
  undefined4 uStack_2094;
  undefined4 local_2090;
  undefined4 uStack_208c;
  undefined8 local_2088;
  undefined8 local_2080;
  undefined8 local_2078;
  undefined8 local_2070;
  undefined4 local_2068;
  longlong local_2060;
  undefined4 local_2058;
  undefined8 local_2054;
  int *local_2048;
  undefined1 local_2040 [3072];
  int local_1440;
  longlong alStack_143c [383];
  undefined1 auStack_840 [2040];
  undefined8 uStack_48;
  
  uStack_48 = 0x25a0b0c301e;
  local_2058 = 0;
  local_2188 = 0;
  local_2054 = 0;
  local_2184 = (short *)0x0;
  if (DAT_25a0b0e258c != '\0') {
    DAT_25a0b0e46e0 = 0;
    DAT_25a0b0e46e8 = 0;
    goto LAB_25a0b0c3615;
  }
  FUN_25a0b0c2ef0();
  local_2188 = 0;
  local_2184 = (short *)0x0;
  FUN_25a0b0c05f0(&local_2188,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0e0e50);
  local_2168 = 0;
  local_2164 = (short *)0x0;
  FUN_25a0b0c05f0(&local_2188,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0e0d50);
  local_2130 = 0;
  local_212c = 0;
  local_20e0.opaque = 0x1004d;
  local_20e0.text._0_4_ = 1;
  local_2098 = 0x1004d;
  uStack_2094 = 1;
  local_20e0.text._4_4_ = 0;
  uStack_20d4 = 0;
  local_20d0 = 0;
  local_20c8 = 0;
  local_20c0 = 0;
  local_20b8 = 0;
  local_20b0 = 0;
  local_2090 = 0;
  uStack_208c = 0;
  local_2088 = 0;
  local_2080 = 0;
  local_2078 = 0;
  local_2070 = 0;
  local_2068 = 0;
  FUN_25a0b0c05f0(&local_2130,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0e0d60);
  (*(code *)&runtime_array_helper_7aa0e0)(0x25a0930b4c8,&local_20e0,0,0);
  _LastError = 0;
  DAT_25a0b0e4e80 = 0;
  DAT_25a0b0e4e88 = 0;
  uVar35 = 0x25a;
  uVar9 = 5000;
  if (DAT_25a0b0e26cc == '\0') {
    uVar9 = 0;
  }
  iVar10 = (*(code *)&MT5_WebRequestNine)
                     (0x25a0930b4c8,&string_ref_25a0b0de8b8,&string_ref_25a0b0e26c0,&DAT_25a0b0dc150
                      ,&DAT_25a0b0dc150,uVar9,&local_20e0,0,&local_2098,&local_2130);
  if (iVar10 == 200) {
    DAT_25a0b0e46ea = 0;
    (*(code *)&MT5_CharArrayToString)
              (0x25a0930b4c8,&local_2098,0,0xffffffff,CONCAT44(uVar35,0xfde9));
    FUN_25a0b0c05f0(&local_2168,&runtime_string_result,0,&PTR_DAT_25a0b0e0d70);
    FUN_25a0b0c05f0(&local_2188,&local_2168,0);
    bVar34 = true;
    if (((local_2184 != (short *)0x0) && (local_2184 != (short *)0xc)) &&
       (uVar23 = *(uint *)(local_2184 + -2), 0x1f < (int)uVar23)) {
      if (DAT_25a0b0deba8 == 0) {
        _LastError = 0x13ab;
        goto LAB_25a0b0c3e06;
      }
      if (local_2184 == (short *)&DAT_25a0b0debac) goto LAB_25a0b0c550c;
      if ((uVar23 < DAT_25a0b0deba8) || (uVar27 = (uVar23 - DAT_25a0b0deba8) + 1, uVar27 == 0)) {
LAB_25a0b0c3e06:
        if (DAT_25a0b0debc8 == 0) {
          _LastError = 0x13ab;
          bVar34 = false;
          goto LAB_25a0b0c354e;
        }
        if (local_2184 != (short *)&DAT_25a0b0debcc) {
          if ((uVar23 < DAT_25a0b0debc8) || (uVar23 = (uVar23 - DAT_25a0b0debc8) + 1, uVar23 == 0))
          goto LAB_25a0b0c3e35;
          uVar32 = (ulonglong)uVar23;
          if (DAT_25a0b0debc8 != 1) {
            bVar33 = true;
            uVar23 = 1;
            uVar26 = 0;
            do {
              if (local_2184[uVar26] == 0x44) {
                psVar21 = &DAT_25a0b0debce;
                lVar12 = (ulonglong)DAT_25a0b0debc8 - 1;
                uVar27 = uVar23;
                while (local_2184[uVar27] == *psVar21) {
                  psVar21 = psVar21 + 1;
                  uVar27 = uVar27 + 1;
                  lVar12 = lVar12 + -1;
                  if (lVar12 == 0) goto LAB_25a0b0c54f7;
                }
                if ((int)lVar12 == 0) {
LAB_25a0b0c54f7:
                  if (bVar33) goto LAB_25a0b0c5504;
                  goto LAB_25a0b0c3e35;
                }
              }
              uVar26 = uVar26 + 1;
              uVar23 = uVar23 + 1;
              bVar34 = false;
              bVar33 = uVar26 < uVar32;
            } while (uVar26 != uVar32);
            goto LAB_25a0b0c354e;
          }
          if (*local_2184 != 0x44) {
            uVar26 = 0;
            do {
              if (uVar32 - 1 == uVar26) goto LAB_25a0b0c3e35;
              lVar12 = uVar26 + 1;
              uVar26 = uVar26 + 1;
            } while (local_2184[lVar12] != 0x44);
            if (uVar26 < uVar32) {
LAB_25a0b0c5504:
              if (-1 < (int)uVar26) goto LAB_25a0b0c550c;
            }
LAB_25a0b0c3e35:
            bVar34 = false;
            goto LAB_25a0b0c354e;
          }
        }
      }
      else {
        uVar32 = (ulonglong)uVar27;
        if (DAT_25a0b0deba8 != 1) {
          bVar34 = true;
          uVar27 = 1;
          uVar26 = 0;
          do {
            if (local_2184[uVar26] == 0x3c) {
              psVar21 = &DAT_25a0b0debae;
              lVar12 = (ulonglong)DAT_25a0b0deba8 - 1;
              uVar22 = uVar27;
              while (local_2184[uVar22] == *psVar21) {
                psVar21 = psVar21 + 1;
                uVar22 = uVar22 + 1;
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_25a0b0c547d;
              }
              if ((int)lVar12 == 0) {
LAB_25a0b0c547d:
                if (bVar34) goto LAB_25a0b0c5489;
                break;
              }
            }
            uVar26 = uVar26 + 1;
            uVar27 = uVar27 + 1;
            bVar34 = uVar26 < uVar32;
          } while (uVar26 != uVar32);
          goto LAB_25a0b0c3e06;
        }
        if (*local_2184 != 0x3c) {
          uVar26 = 0;
          do {
            if (uVar32 - 1 == uVar26) goto LAB_25a0b0c3e06;
            lVar12 = uVar26 + 1;
            uVar26 = uVar26 + 1;
          } while (local_2184[lVar12] != 0x3c);
          if (uVar26 < uVar32) {
LAB_25a0b0c5489:
            if (-1 < (int)uVar26) goto LAB_25a0b0c550c;
          }
          goto LAB_25a0b0c3e06;
        }
      }
LAB_25a0b0c550c:
      if (DAT_25a0b0e258f != '\0') {
        iVar10 = 900;
        if (DAT_25a0b0e26ce == '\0') {
          iVar10 = 0;
        }
        MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0dec68,0x520004,iVar10);
      }
      FUN_25a0b0c05f0(&local_2188,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0e0d90);
      bVar34 = true;
    }
  }
  else if (iVar10 == -1) {
    if (_LastError == 0xfae) {
      bVar34 = true;
      DAT_25a0b0e46ea = 1;
      if ((DAT_25a0b0e46e9 == '\0') && (DAT_25a0b0e258f != '\0')) {
        DAT_25a0b0e46e9 = '\x01';
        MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0de940);
        MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0dea00);
        MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0dea88);
      }
    }
    else {
      bVar34 = true;
      if (DAT_25a0b0e258f != '\0') {
        pMVar18 = &string_ref_25a0b0deb20;
        iVar10 = _LastError;
        goto LAB_25a0b0c3503;
      }
    }
  }
  else {
    bVar34 = true;
    if (DAT_25a0b0e258f != '\0') {
      pMVar18 = &string_ref_25a0b0deb88;
LAB_25a0b0c3503:
      bVar34 = true;
      iVar20 = 900;
      if (DAT_25a0b0e26ce == '\0') {
        iVar20 = 0;
      }
      MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,pMVar18,0x520004,iVar10,0x520004,iVar20);
    }
  }
LAB_25a0b0c354e:
  FUN_25a0b0c0000(&local_2130);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&local_2098);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8);
  FUN_25a0b0c0000(&local_2168);
  if (bVar34) {
    if ((int)DAT_25a0b0e46e0 < 1) {
      DAT_25a0b0e46e8 = 0;
    }
    lVar11 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
    lVar12 = lVar11 + -0x3840;
    if (DAT_25a0b0e26cd == '\0') {
      lVar12 = lVar11;
    }
    DAT_25a0b0e26d0 = lVar12 + 900;
    if (DAT_25a0b0e26ce == '\0') {
      DAT_25a0b0e26d0 = lVar12;
    }
  }
  else {
    uVar23 = 0;
    memset(&local_1440,0,0xc00);
    memset(local_2040,0,0xc00);
    local_2150 = 0;
    local_2108 = 0;
    local_2118 = 0;
    local_214c = 0;
    local_2104 = (undefined2 *)0x0;
    local_2114 = 0;
    if ((local_2184 != (short *)0x0) && (local_2184 != (short *)0xc)) {
      uVar23 = *(uint *)(local_2184 + -2);
    }
    local_20a8 = 0;
    local_20a4 = (short *)0x0;
    uVar32 = 0;
    FUN_25a0b0c05f0(&local_20a8,&string_ref_25a0b0deca0,0,&PTR_DAT_25a0b0e0da0);
    lVar12 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
    iVar10 = 0xfa9;
    if ((local_2184 != (short *)0x0) && (local_20a4 != (short *)0x0)) {
      uVar27 = *(uint *)(local_2184 + -2);
      iVar10 = 0x13ab;
      if ((uVar27 != 0) && (uVar22 = *(uint *)(local_20a4 + -2), uVar22 != 0)) {
        uVar26 = 0;
        if (local_2184 == local_20a4) goto LAB_25a0b0c3ee3;
        uVar32 = 0;
        iVar10 = _LastError;
        local_2060 = lVar12;
        if ((uVar22 <= uVar27) && (uVar27 = (uVar27 - uVar22) + 1, uVar27 != 0)) {
          sVar3 = *local_20a4;
          uVar30 = (ulonglong)uVar27;
          if (uVar22 < 2) {
            uVar26 = 0;
            if (*local_2184 == sVar3) {
LAB_25a0b0c3ee3:
              local_2060 = lVar12 + -0x15180;
              uVar32 = 0;
              local_2140 = uVar23;
LAB_25a0b0c3f00:
              local_2124 = FUN_25a0b0c03a0(local_2184,local_20a4,(int)uVar26 + 7);
              local_2108 = 0;
              local_2104 = (undefined2 *)0x0;
              local_213c = uVar23;
              if (0 < (int)local_2124) {
                local_213c = local_2124;
              }
              FUN_25a0b0d78f0(&local_2188,&string_ref_25a0b0decd0,uVar26 & 0xffffffff);
              FUN_25a0b0c05f0(&local_2150,&runtime_string_result,1,&PTR_DAT_25a0b0e0db0);
              FUN_25a0b0c05f0(&local_2108);
              FUN_25a0b0c01d0(&local_2108);
              if (local_2104 != &DAT_25a0b0decec) {
                if (local_2104 != (undefined2 *)0x0) {
                  uVar27 = *(uint *)(local_2104 + -2);
                  uVar22 = DAT_25a0b0dece8;
                  if (uVar27 < DAT_25a0b0dece8) {
                    uVar22 = uVar27;
                  }
                  iVar10 = uVar27 - DAT_25a0b0dece8;
                  if (uVar22 != 0) {
                    uVar30 = 0;
                    do {
                      uVar4 = local_2104[uVar30];
                      uVar5 = (&DAT_25a0b0decec)[uVar30];
                      uVar30 = uVar30 + 1;
                      if (uVar22 <= uVar30) break;
                    } while (uVar4 == uVar5);
                    if (uVar4 != uVar5) {
                      iVar10 = (uint)uVar4 - (uint)uVar5;
                    }
                  }
                  if (iVar10 == 0) goto LAB_25a0b0c4040;
                }
                goto LAB_25a0b0c4d9c;
              }
LAB_25a0b0c4040:
              local_2118 = 0;
              local_2114 = 0;
              FUN_25a0b0d78f0(&local_2188,&string_ref_25a0b0ded20,uVar26 & 0xffffffff,local_213c);
              FUN_25a0b0c05f0(&local_2150,&runtime_string_result,1,&PTR_DAT_25a0b0e0dd0);
              FUN_25a0b0c05f0(&local_2118,&local_2150,0,&PTR_DAT_25a0b0e0de0);
              if (((local_2114 == 0) || (local_2114 == 0xc)) || (*(int *)(local_2114 + -4) < 1)) {
                FUN_25a0b0d78f0(&local_2188,&string_ref_25a0b0ded50,uVar26 & 0xffffffff,local_213c);
                FUN_25a0b0c05f0(&local_2150,&runtime_string_result,1,&PTR_DAT_25a0b0e0df0);
                FUN_25a0b0c05f0(&local_2118,&local_2150,0,&PTR_DAT_25a0b0e0e00);
              }
              local_20e0.opaque = 0;
              local_2098 = 0;
              local_2168 = 0;
              local_2130 = 0;
              local_20f8 = 0;
              local_2178 = 0;
              local_20e0.text._0_4_ = 0;
              local_20e0.text._4_4_ = 0;
              uStack_2094 = 0;
              local_2090 = 0;
              local_2164 = (short *)0x0;
              local_212c = 0;
              local_20f4 = 0;
              local_2174 = (int *)0x0;
              local_2138 = uVar26;
              local_2120 = uVar32;
              FUN_25a0b0c05f0(&local_2178,&NewsCurrencies,0,&PTR_DAT_25a0b0e0cf0);
              piVar16 = local_2174;
              if ((local_2174 == (int *)0x0) || (piVar14 = local_2174 + -3, piVar14 == (int *)0x0))
              {
                _LastError = 0xfa9;
              }
              else {
                uVar23 = local_2174[-1];
                uVar32 = (ulonglong)uVar23;
                if (uVar32 != 0) {
                  uVar26 = 0;
                  do {
                    uVar15 = (ulonglong)*(ushort *)((longlong)local_2174 + uVar26 * 2);
                    uVar30 = uVar26;
                    if ((0x20 < uVar15) || ((0x100002600U >> (uVar15 & 0x3f) & 1) == 0)) break;
                    uVar26 = uVar26 + 1;
                    uVar30 = uVar32;
                  } while (uVar32 != uVar26);
                  uVar27 = (uint)uVar30;
                  if (uVar27 != 0) {
                    uVar22 = uVar23 - uVar27;
                    piVar13 = (int *)(*(code *)&runtime_string_helper_7d1190)(0x25a0930b4c8,uVar22);
                    if (piVar13 == (int *)0x0) {
                      _LastError = 0x13aa;
                    }
                    else {
                      piVar13[1] = 1;
                      piVar13[2] = 0;
                      *(undefined2 *)(piVar13 + 3) = 0;
                      local_2174 = piVar13 + 3;
                      uVar32 = (ulonglong)uVar22;
                      iVar10 = *piVar13;
                      if (uVar23 != uVar27) {
                        uVar30 = uVar30 & 0xffffffff;
                        uVar26 = uVar32 + (uVar32 == 0);
                        if ((7 < uVar22) &&
                           (0x1f < (longlong)piVar13 - ((longlong)piVar14 + uVar30 * 2))) {
                          uVar31 = 0;
                          uVar15 = (ulonglong)((uint)uVar26 & 0xfffffff8);
                          do {
                            puVar2 = (undefined4 *)((longlong)piVar16 + uVar31 * 2 + uVar30 * 2);
                            uVar9 = puVar2[1];
                            uVar35 = puVar2[2];
                            uVar7 = puVar2[3];
                            puVar1 = (undefined4 *)((longlong)local_2174 + uVar31 * 2);
                            *puVar1 = *puVar2;
                            puVar1[1] = uVar9;
                            puVar1[2] = uVar35;
                            puVar1[3] = uVar7;
                            uVar31 = uVar31 + 8;
                            if (uVar15 == uVar31) goto LAB_25a0b0c537d;
                          } while( true );
                        }
                        uVar15 = 0;
                        do {
                          *(undefined2 *)((longlong)local_2174 + uVar15 * 2) =
                               *(undefined2 *)((longlong)piVar16 + uVar15 * 2 + uVar30 * 2);
                          uVar15 = uVar15 + 1;
LAB_25a0b0c537d:
                        } while (uVar26 != uVar15);
                      }
                      piVar13[2] = uVar22;
                      *(undefined2 *)((longlong)local_2174 + uVar32 * 2) = 0;
                      bVar34 = local_2178 != 0;
                      local_2178 = iVar10;
                      if ((bVar34) && (*piVar14 != 0)) {
                        piVar16 = piVar16 + -2;
                        *piVar16 = *piVar16 + -1;
                        if (*piVar16 == 0) {
                          (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8,piVar14);
                        }
                      }
                    }
                  }
                }
              }
              uVar32 = local_2138;
              piVar16 = local_2174 + -3;
              if ((local_2174 == (int *)0x0) || (piVar16 == (int *)0x0)) {
                _LastError = 0xfa9;
              }
              else {
                uVar23 = local_2174[-1];
                if ((ulonglong)uVar23 != 0) {
                  lVar12 = 0;
                  uVar27 = uVar23;
                  do {
                    uVar26 = (ulonglong)
                             *(ushort *)
                              ((longlong)local_2174 + lVar12 * 2 + (ulonglong)uVar23 * 2 + -2);
                    if ((0x20 < uVar26) || ((0x100002600U >> (uVar26 & 0x3f) & 1) == 0)) {
                      if ((int)lVar12 == 0) goto LAB_25a0b0c4375;
                      uVar22 = -(int)lVar12;
                      break;
                    }
                    lVar12 = lVar12 + -1;
                    uVar27 = uVar27 - 1;
                    uVar22 = uVar23;
                  } while (uVar27 != 0);
                  uVar23 = uVar23 - uVar22;
                  cVar8 = FUN_25a0b0c0060(&local_2178,uVar23);
                  piVar16 = local_2174 + -3;
                  if (cVar8 != '\0') {
                    local_2174[-1] = uVar23;
                    *(undefined2 *)((longlong)local_2174 + (ulonglong)uVar23 * 2) = 0;
                  }
                }
              }
LAB_25a0b0c4375:
              uVar9 = (undefined4)uVar32;
              bVar34 = true;
              if (((piVar16 != (int *)0x0) && (local_2174 != (int *)0x0)) && (0 < piVar16[2])) {
                FUN_25a0b0c01d0(&local_2178);
                piVar16 = local_2174;
                uVar27 = DAT_25a0b0de874;
                uVar23 = DAT_25a0b0dc164;
                if ((local_2174 == (int *)0x0) || (uVar32 = (ulonglong)DAT_25a0b0de874, uVar32 == 0)
                   ) {
                  _LastError = 0x13b0;
                }
                else {
                  uVar22 = local_2174[-1];
                  if (0 < (int)uVar22) {
                    local_2048 = local_2174 + -3;
                    local_20e8 = (longlong)local_2174 + 2;
                    iVar20 = 0;
                    local_2158 = local_2158 & 0xffffffff00000000;
                    local_2144 = 0;
                    uVar26 = (ulonglong)(int)DAT_25a0b0dc164;
                    local_209c = ((int)uVar22 / (int)DAT_25a0b0de874) * DAT_25a0b0dc164 + uVar22;
                    uVar30 = uVar26 & 0xfffffffffffffff8;
                    piVar14 = (int *)0x0;
                    iVar10 = 0;
LAB_25a0b0c4454:
                    do {
                      lVar12 = (longlong)iVar10;
                      uVar19 = iVar10 + 1U;
                      if ((int)(iVar10 + 1U) < (int)uVar22) {
                        uVar19 = uVar22;
                      }
                      do {
                        if (*(short *)((longlong)piVar16 + lVar12 * 2) == 0x20) {
                          uVar19 = (uint)lVar12;
                          break;
                        }
                        lVar12 = lVar12 + 1;
                      } while (lVar12 < (longlong)(ulonglong)uVar22);
                      if ((int)(uVar22 - uVar19) < (int)uVar27) break;
                      uVar17 = 1;
                      if (1 < (int)uVar27) {
                        lVar12 = 0;
                        do {
                          if (*(short *)(local_20e8 + (longlong)(int)uVar19 * 2 + lVar12 * 2) !=
                              (&DAT_25a0b0de87a)[lVar12]) {
                            uVar17 = (int)lVar12 + 1;
                            goto LAB_25a0b0c44b8;
                          }
                          lVar12 = lVar12 + 1;
                        } while (uVar32 - 1 != lVar12);
LAB_25a0b0c44bd:
                        if (piVar14 == (int *)0x0) {
                          piVar14 = (int *)(*(code *)&runtime_string_helper_7d1190)
                                                     (0x25a0930b4c8,local_209c);
                          if (piVar14 == (int *)0x0) {
                            _LastError = 0x13aa;
                            goto LAB_25a0b0c46e5;
                          }
                          piVar14[1] = 1;
                          piVar14[2] = 0;
                          *(undefined2 *)(piVar14 + 3) = 0;
                          local_2144 = *piVar14;
                          piVar14 = piVar14 + 3;
                          uVar17 = uVar19 - iVar20;
                          if (uVar17 == 0 || (int)uVar19 < iVar20) goto LAB_25a0b0c455c;
LAB_25a0b0c44cc:
                          lVar12 = (longlong)piVar16 + (longlong)iVar20 * 2;
                          uVar15 = (ulonglong)(int)(uVar17 + (uVar17 == 0));
                          if (uVar17 < 8) {
                            uVar31 = 0;
                          }
                          else {
                            if (0x1f < (ulonglong)
                                       ((longlong)piVar14 +
                                       ((longlong)(int)(uint)local_2158 * 2 - lVar12))) {
                              uVar25 = 0;
                              uVar31 = uVar15 & 0xfffffffffffffff8;
                              do {
                                puVar2 = (undefined4 *)(lVar12 + uVar25 * 2);
                                uVar9 = puVar2[1];
                                uVar35 = puVar2[2];
                                uVar7 = puVar2[3];
                                puVar1 = (undefined4 *)
                                         ((longlong)piVar14 +
                                         uVar25 * 2 + (longlong)(int)(uint)local_2158 * 2);
                                *puVar1 = *puVar2;
                                puVar1[1] = uVar9;
                                puVar1[2] = uVar35;
                                puVar1[3] = uVar7;
                                uVar25 = uVar25 + 8;
                                if (uVar31 == uVar25) goto joined_r0x025a0b0c45a6;
                              } while( true );
                            }
                            uVar31 = 0;
                          }
                          do {
                            *(undefined2 *)
                             ((longlong)piVar14 + uVar31 * 2 + (longlong)(int)(uint)local_2158 * 2)
                                 = *(undefined2 *)(lVar12 + uVar31 * 2);
                            uVar31 = uVar31 + 1;
joined_r0x025a0b0c45a6:
                          } while (uVar31 != uVar15);
                          iVar10 = (uint)local_2158 + uVar17;
                        }
                        else {
                          uVar17 = uVar19 - iVar20;
                          if (uVar17 != 0 && iVar20 <= (int)uVar19) goto LAB_25a0b0c44cc;
LAB_25a0b0c455c:
                          iVar10 = (uint)local_2158;
                        }
                        if (uVar23 != 0) {
                          lVar12 = (longlong)iVar10;
                          if (uVar23 < 8) {
                            uVar15 = 0;
                          }
                          else if ((ulonglong)((longlong)piVar14 + lVar12 * 2 + -0x25a0b0dc168) <
                                   0x20) {
                            uVar15 = 0;
                          }
                          else {
                            uVar15 = 0;
                            do {
                              lVar11 = uVar15 * 2;
                              uVar9 = *(undefined4 *)(lVar11 + 0x25a0b0dc16c);
                              uVar35 = *(undefined4 *)
                                        ((longlong)&string_ref_25a0b0dc170.opaque + lVar11);
                              uVar7 = *(undefined4 *)
                                       ((longlong)&string_ref_25a0b0dc170.text + lVar11);
                              puVar2 = (undefined4 *)((longlong)piVar14 + uVar15 * 2 + lVar12 * 2);
                              *puVar2 = *(undefined4 *)(literal_25a0b0dc168 + uVar15);
                              puVar2[1] = uVar9;
                              puVar2[2] = uVar35;
                              puVar2[3] = uVar7;
                              uVar15 = uVar15 + 8;
                            } while (uVar30 != uVar15);
                            uVar15 = uVar30;
                            if (uVar30 == uVar26) goto LAB_25a0b0c4652;
                          }
                          do {
                            *(wchar_t *)((longlong)piVar14 + uVar15 * 2 + lVar12 * 2) =
                                 literal_25a0b0dc168[uVar15];
                            uVar15 = uVar15 + 1;
                          } while (uVar26 != uVar15);
                        }
LAB_25a0b0c4652:
                        uVar15 = local_2158 >> 0x20;
                        iVar20 = uVar19 + uVar27;
                        local_2158 = CONCAT44((int)uVar15,iVar10 + uVar23);
                        iVar10 = iVar20;
                        if ((int)uVar22 <= iVar20) break;
                        goto LAB_25a0b0c4454;
                      }
LAB_25a0b0c44b8:
                      if (uVar17 == uVar27) goto LAB_25a0b0c44bd;
                      iVar10 = uVar19 + 1;
                    } while (iVar10 < (int)uVar22);
                    iVar10 = local_2178;
                    if (piVar14 != (int *)0x0) {
                      uVar23 = (uint)local_2158;
                      if (iVar20 < (int)uVar22) {
                        uVar22 = uVar22 - iVar20;
                        uVar32 = (ulonglong)(int)(uVar22 + (uVar22 == 0));
                        lVar12 = (longlong)piVar16 + (longlong)iVar20 * 2;
                        if (uVar22 < 8) {
                          uVar26 = 0;
                        }
                        else {
                          if (0x1f < (ulonglong)
                                     ((longlong)piVar14 +
                                     ((longlong)(int)(uint)local_2158 * 2 - lVar12))) {
                            uVar30 = 0;
                            uVar26 = uVar32 & 0xfffffffffffffff8;
                            do {
                              puVar2 = (undefined4 *)(lVar12 + uVar30 * 2);
                              uVar9 = puVar2[1];
                              uVar35 = puVar2[2];
                              uVar7 = puVar2[3];
                              puVar1 = (undefined4 *)
                                       ((longlong)piVar14 +
                                       uVar30 * 2 + (longlong)(int)(uint)local_2158 * 2);
                              *puVar1 = *puVar2;
                              puVar1[1] = uVar9;
                              puVar1[2] = uVar35;
                              puVar1[3] = uVar7;
                              uVar30 = uVar30 + 8;
                              if (uVar26 == uVar30) goto joined_r0x025a0b0c52fb;
                            } while( true );
                          }
                          uVar26 = 0;
                        }
                        do {
                          *(undefined2 *)
                           ((longlong)piVar14 + uVar26 * 2 + (longlong)(int)(uint)local_2158 * 2) =
                               *(undefined2 *)(lVar12 + uVar26 * 2);
                          uVar26 = uVar26 + 1;
joined_r0x025a0b0c52fb:
                        } while (uVar26 != uVar32);
                        uVar23 = uVar22 + (uint)local_2158;
                      }
                      local_2178 = local_2144;
                      piVar14[-1] = uVar23;
                      *(undefined2 *)((longlong)piVar14 + (ulonglong)uVar23 * 2) = 0;
                      local_2174 = piVar14;
                      if (((local_2048 != (int *)0x0) && (iVar10 != 0)) && (*local_2048 != 0)) {
                        piVar16 = local_2048 + 1;
                        *piVar16 = *piVar16 + -1;
                        if (*piVar16 == 0) {
                          (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
                        }
                      }
                    }
                  }
                }
LAB_25a0b0c46e5:
                local_20f8 = 0;
                local_20f4 = 0;
                FUN_25a0b0c05f0(&local_20f8,&local_2118,0,&PTR_DAT_25a0b0e0d00);
                FUN_25a0b0c01d0(&local_20f8);
                FUN_25a0b0c05f0(&local_2130,&string_ref_25a0b0de890);
                lVar12 = local_20f4;
                if (local_20f4 != 0) {
                  uVar23 = *(uint *)(local_20f4 + -4);
                  uVar32 = (ulonglong)uVar23;
                  if ((uVar32 != 0) || (local_212c == 0)) {
                    if (local_212c == 0) {
                      uVar27 = 0;
                    }
                    else {
                      uVar27 = *(uint *)(local_212c + -4);
                    }
                    cVar8 = FUN_25a0b0c0060(&local_2130);
                    if (cVar8 == '\0') goto LAB_25a0b0c563b;
                    if (uVar32 != 0) {
                      lVar11 = local_212c + (ulonglong)uVar27 * 2;
                      if (uVar23 < 8) {
                        uVar26 = 0;
                      }
                      else if ((ulonglong)(lVar11 - lVar12) < 0x20) {
                        uVar26 = 0;
                      }
                      else {
                        uVar30 = 0;
                        uVar26 = (ulonglong)(uVar23 & 0xfffffff8);
                        do {
                          puVar2 = (undefined4 *)(lVar12 + uVar30);
                          uVar9 = puVar2[1];
                          uVar35 = puVar2[2];
                          uVar7 = puVar2[3];
                          puVar1 = (undefined4 *)(lVar11 + uVar30);
                          *puVar1 = *puVar2;
                          puVar1[1] = uVar9;
                          puVar1[2] = uVar35;
                          puVar1[3] = uVar7;
                          uVar30 = uVar30 + 0x10;
                        } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar30);
                        if (uVar26 == uVar32) goto LAB_25a0b0c4892;
                      }
                      do {
                        *(undefined2 *)(lVar11 + uVar26 * 2) = *(undefined2 *)(lVar12 + uVar26 * 2);
                        uVar26 = uVar26 + 1;
                      } while (uVar32 != uVar26);
                    }
LAB_25a0b0c4892:
                    *(uint *)(local_212c + -4) = uVar23 + uVar27;
                    *(undefined2 *)(local_212c + (ulonglong)(uVar23 + uVar27) * 2) = 0;
                  }
                }
                FUN_25a0b0c05f0(&local_2168,&local_2130,0,&PTR_DAT_25a0b0e0d20);
                uVar23 = DAT_25a0b0de884;
                uVar32 = (ulonglong)DAT_25a0b0de884;
                if ((uVar32 != 0) || (local_2164 == (short *)0x0)) {
                  if (local_2164 == (short *)0x0) {
                    uVar26 = 0;
                    uVar27 = DAT_25a0b0de884;
                  }
                  else {
                    uVar26 = (ulonglong)*(uint *)(local_2164 + -2);
                    uVar27 = DAT_25a0b0de884 + *(uint *)(local_2164 + -2);
                  }
                  uVar22 = 0x104;
                  if ((0x103 < uVar27) &&
                     ((0x7ffffffd < uVar27 || (uVar22 = (uVar27 >> 2) + uVar27, 0x7ffffffd < uVar22)
                      ))) {
                    uVar22 = 0x7ffffffe;
                  }
                  cVar8 = FUN_25a0b0c0060(&local_2168,uVar22);
                  if (cVar8 == '\0') goto LAB_25a0b0c55fb;
                  if (uVar32 != 0) {
                    if (uVar23 < 8) {
                      uVar30 = 0;
                    }
                    else if (local_2164 + (uVar26 - 0x12d0586f444) < (short *)0x20) {
                      uVar30 = 0;
                    }
                    else {
                      uVar15 = 0;
                      uVar30 = (ulonglong)(uVar23 & 0xfffffff8);
                      do {
                        uVar9 = *(undefined4 *)(uVar15 + 0x25a0b0de88c);
                        uVar35 = *(undefined4 *)((longlong)&string_ref_25a0b0de890.opaque + uVar15);
                        uVar7 = *(undefined4 *)((longlong)&string_ref_25a0b0de890.text + uVar15);
                        puVar2 = (undefined4 *)((longlong)local_2164 + uVar15 + uVar26 * 2);
                        *puVar2 = *(undefined4 *)((longlong)literal_25a0b0de888 + uVar15);
                        puVar2[1] = uVar9;
                        puVar2[2] = uVar35;
                        puVar2[3] = uVar7;
                        uVar15 = uVar15 + 0x10;
                      } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar15);
                      if (uVar30 == uVar32) goto LAB_25a0b0c49d2;
                    }
                    do {
                      local_2164[uVar26 + uVar30] = literal_25a0b0de888[uVar30];
                      uVar30 = uVar30 + 1;
                    } while (uVar32 != uVar30);
                  }
LAB_25a0b0c49d2:
                  *(uint *)(local_2164 + -2) = uVar27;
                  local_2164[uVar27] = 0;
                }
                FUN_25a0b0c05f0(&local_2098,&string_ref_25a0b0de890);
                piVar16 = local_2174;
                if (local_2174 != (int *)0x0) {
                  uVar23 = local_2174[-1];
                  uVar32 = (ulonglong)uVar23;
                  lVar12 = CONCAT44(local_2090,uStack_2094);
                  if ((uVar32 != 0) || (lVar12 == 0)) {
                    if (lVar12 == 0) {
                      uVar27 = 0;
                    }
                    else {
                      uVar27 = *(uint *)(lVar12 + -4);
                    }
                    cVar8 = FUN_25a0b0c0060(&local_2098);
                    if (cVar8 == '\0') goto LAB_25a0b0c565b;
                    lVar12 = CONCAT44(local_2090,uStack_2094);
                    if (uVar32 != 0) {
                      lVar11 = lVar12 + (ulonglong)uVar27 * 2;
                      if (uVar23 < 8) {
                        uVar26 = 0;
                      }
                      else if ((ulonglong)(lVar11 - (longlong)piVar16) < 0x20) {
                        uVar26 = 0;
                      }
                      else {
                        uVar30 = 0;
                        uVar26 = (ulonglong)(uVar23 & 0xfffffff8);
                        do {
                          puVar2 = (undefined4 *)((longlong)piVar16 + uVar30);
                          uVar9 = puVar2[1];
                          uVar35 = puVar2[2];
                          uVar7 = puVar2[3];
                          puVar1 = (undefined4 *)(lVar11 + uVar30);
                          *puVar1 = *puVar2;
                          puVar1[1] = uVar9;
                          puVar1[2] = uVar35;
                          puVar1[3] = uVar7;
                          uVar30 = uVar30 + 0x10;
                        } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar30);
                        if (uVar26 == uVar32) goto LAB_25a0b0c4af2;
                      }
                      do {
                        *(undefined2 *)(lVar11 + uVar26 * 2) =
                             *(undefined2 *)((longlong)piVar16 + uVar26 * 2);
                        uVar26 = uVar26 + 1;
                      } while (uVar32 != uVar26);
                    }
LAB_25a0b0c4af2:
                    *(uint *)(lVar12 + -4) = uVar23 + uVar27;
                    *(undefined2 *)(lVar12 + (ulonglong)(uVar23 + uVar27) * 2) = 0;
                  }
                }
                FUN_25a0b0c05f0();
                uVar23 = DAT_25a0b0de884;
                uVar32 = (ulonglong)DAT_25a0b0de884;
                psVar21 = (short *)CONCAT44(local_20e0.text._4_4_,local_20e0.text._0_4_);
                if ((uVar32 != 0) || (psVar21 == (short *)0x0)) {
                  if (psVar21 == (short *)0x0) {
                    uVar27 = 0;
                    uVar22 = DAT_25a0b0de884;
                  }
                  else {
                    uVar27 = *(uint *)(psVar21 + -2);
                    uVar22 = DAT_25a0b0de884 + uVar27;
                  }
                  cVar8 = FUN_25a0b0c0060(&local_20e0);
                  if (cVar8 == '\0') goto LAB_25a0b0c561b;
                  psVar21 = (short *)CONCAT44(local_20e0.text._4_4_,local_20e0.text._0_4_);
                  if (uVar32 != 0) {
                    uVar26 = (ulonglong)uVar27;
                    if (uVar23 < 8) {
                      uVar30 = 0;
                    }
                    else if (psVar21 + (uVar26 - 0x12d0586f444) < (short *)0x20) {
                      uVar30 = 0;
                    }
                    else {
                      uVar15 = 0;
                      uVar30 = (ulonglong)(uVar23 & 0xfffffff8);
                      do {
                        uVar9 = *(undefined4 *)(uVar15 + 0x25a0b0de88c);
                        uVar35 = *(undefined4 *)((longlong)&string_ref_25a0b0de890.opaque + uVar15);
                        uVar7 = *(undefined4 *)((longlong)&string_ref_25a0b0de890.text + uVar15);
                        puVar2 = (undefined4 *)((longlong)psVar21 + uVar15 + uVar26 * 2);
                        *puVar2 = *(undefined4 *)((longlong)literal_25a0b0de888 + uVar15);
                        puVar2[1] = uVar9;
                        puVar2[2] = uVar35;
                        puVar2[3] = uVar7;
                        uVar15 = uVar15 + 0x10;
                      } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar15);
                      if (uVar30 == uVar32) goto LAB_25a0b0c4c32;
                    }
                    do {
                      psVar21[uVar26 + uVar30] = literal_25a0b0de888[uVar30];
                      uVar30 = uVar30 + 1;
                    } while (uVar32 != uVar30);
                  }
LAB_25a0b0c4c32:
                  *(uint *)(psVar21 + -2) = uVar22;
                  psVar21[uVar22] = 0;
                }
                if ((psVar21 == (short *)0x0) || (local_2164 == (short *)0x0)) {
                  _LastError = 0xfa9;
LAB_25a0b0c4cab:
                  uVar32 = 0xffffffff;
                }
                else {
                  uVar23 = *(uint *)(psVar21 + -2);
                  if ((uVar23 == 0) || (uVar27 = *(uint *)(local_2164 + -2), uVar27 == 0)) {
                    _LastError = 0x13ab;
                    goto LAB_25a0b0c4cab;
                  }
                  uVar32 = 0;
                  if (psVar21 == local_2164) goto LAB_25a0b0c4cb0;
                  if ((uVar23 < uVar27) || (uVar23 = (uVar23 - uVar27) + 1, uVar23 == 0))
                  goto LAB_25a0b0c4cab;
                  sVar3 = *local_2164;
                  uVar26 = (ulonglong)uVar23;
                  if (1 < uVar27) {
                    bVar34 = true;
                    uVar32 = 0;
                    do {
                      if (psVar21[uVar32] == sVar3) {
                        lVar11 = 1;
                        lVar12 = (ulonglong)uVar27 - 1;
                        while (psVar21[(uint)((int)uVar32 + (int)lVar11)] == local_2164[lVar11]) {
                          lVar11 = lVar11 + 1;
                          lVar12 = lVar12 + -1;
                          if (lVar12 == 0) goto LAB_25a0b0c52c4;
                        }
                        if ((int)lVar12 == 0) {
LAB_25a0b0c52c4:
                          if (bVar34) goto LAB_25a0b0c4cb0;
                          break;
                        }
                      }
                      uVar32 = uVar32 + 1;
                      bVar34 = uVar32 < uVar26;
                    } while (uVar32 != uVar26);
                    goto LAB_25a0b0c4cab;
                  }
                  if (*psVar21 != sVar3) {
                    uVar32 = 0;
                    do {
                      if (uVar26 - 1 == uVar32) goto LAB_25a0b0c4cab;
                      lVar12 = uVar32 + 1;
                      uVar32 = uVar32 + 1;
                    } while (psVar21[lVar12] != sVar3);
                    if (uVar26 <= uVar32) goto LAB_25a0b0c4cab;
                  }
                }
LAB_25a0b0c4cb0:
                uVar9 = (undefined4)local_2138;
                bVar34 = -1 < (int)uVar32;
                FUN_25a0b0c0000(&local_20f8);
              }
              FUN_25a0b0c0000(&local_2178);
              FUN_25a0b0c0000(&local_2130);
              FUN_25a0b0c0000(&local_2168);
              FUN_25a0b0c0000(&local_2098);
              FUN_25a0b0c0000(&local_20e0);
              uVar32 = local_2120;
              uVar23 = local_2140;
              if (bVar34) {
                FUN_25a0b0d78f0(&local_2188,&string_ref_25a0b0ded78,uVar9,local_213c);
                FUN_25a0b0c05f0(&local_2150,&runtime_string_result,1,&PTR_DAT_25a0b0e0e10);
                local_20e0.opaque = 0;
                local_20e0.text._0_4_ = 0;
                local_20e0.text._4_4_ = 0;
                if (((local_214c != 0) && (local_214c != 0xc)) && (0x12 < *(int *)(local_214c + -4))
                   ) {
                  FUN_25a0b0c0810(local_214c,0,4);
                  FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0c80);
                  local_2158 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                  FUN_25a0b0c0810(local_214c,5,2);
                  FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0c90);
                  lVar12 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                  FUN_25a0b0c0810(local_214c,8,2);
                  FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0ca0);
                  lVar11 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                  FUN_25a0b0c0810(local_214c,0xb,2);
                  FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0cb0);
                  local_20e8 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                  FUN_25a0b0c0810(local_214c,0xe,2);
                  FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0cc0);
                  uVar32 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                  if (((1999 < (int)local_2158) && (uVar23 = (uint)lVar12, 0 < (int)uVar23)) &&
                     (((int)uVar23 < 0xd && ((iVar10 = (int)lVar11, 0 < iVar10 && (iVar10 < 0x20))))
                     )) {
                    uVar22 = (int)local_2158 - (uint)(uVar23 < 3);
                    uVar27 = uVar23 + 0xc;
                    if (2 < uVar23) {
                      uVar27 = uVar23;
                    }
                    lVar12 = (uVar32 & 0xffffffff) * 0x3c +
                             (local_20e8 & 0xffffffff) * 0xe10 +
                             (ulonglong)
                             (((uVar27 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
                             ((iVar10 + uVar22 * 0x16d + (uVar22 >> 2)) - uVar22 / 100) +
                             uVar22 / 400) * 0x15180;
                    if (lVar12 != 0) {
                      if ((((local_214c == 0) || (local_214c == 0xc)) ||
                          (*(int *)(local_214c + -4) < 0x19)) ||
                         ((sVar3 = *(short *)(local_214c + 0x26), sVar3 != 0x2d && (sVar3 != 0x2b)))
                         ) {
                        FUN_25a0b0c0000(&local_20e0);
                      }
                      else {
                        FUN_25a0b0c0810(local_214c,0x14,2);
                        FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0cd0);
                        lVar11 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                        FUN_25a0b0c0810(local_214c,0x17,2);
                        FUN_25a0b0c05f0(&local_20e0,&runtime_string_result,1,&PTR_DAT_25a0b0e0ce0);
                        lVar24 = MT5_StringToInteger((void *)0x25a0930b4c8,&local_20e0);
                        lVar24 = (longlong)((int)lVar24 * 0x3c + (int)lVar11 * 0xe10);
                        lVar11 = -lVar24;
                        if (sVar3 == 0x2d) {
                          lVar11 = lVar24;
                        }
                        lVar12 = lVar12 + lVar11;
                        FUN_25a0b0c0000(&local_20e0);
                        uVar32 = local_2120;
                        uVar23 = local_2140;
                        if (lVar12 < 1) goto LAB_25a0b0c4d91;
                      }
                      uVar23 = local_2140;
                      uVar32 = local_2120;
                      if (DAT_25a0b0e470c + lVar12 < local_2060) goto LAB_25a0b0c4d91;
                      uVar27 = (uint)local_2120;
                      if (0xff < uVar27) goto LAB_25a0b0c569b;
                      uVar32 = local_2120 & 0xffffffff;
                      *(longlong *)(auStack_840 + uVar32 * 8) = DAT_25a0b0e470c + lVar12;
                      FUN_25a0b0d78f0(&local_2188,&string_ref_25a0b0deda8,local_2138,local_213c);
                      FUN_25a0b0c05f0(&local_2150,&runtime_string_result,1,&PTR_DAT_25a0b0e0e20);
                      FUN_25a0b0c05f0(&local_1440 + uVar32 * 3,&local_2150,0,&PTR_DAT_25a0b0e0e30);
                      FUN_25a0b0c05f0(local_2040 + uVar32 * 0xc,&local_2118,0,&PTR_DAT_25a0b0e0e40);
                      uVar32 = (ulonglong)(uVar27 + 1);
                      goto LAB_25a0b0c4d91;
                    }
                  }
                }
                FUN_25a0b0c0000(&local_20e0);
                uVar32 = local_2120;
                uVar23 = local_2140;
              }
LAB_25a0b0c4d91:
              FUN_25a0b0c0000(&local_2118);
LAB_25a0b0c4d9c:
              uVar27 = local_2124;
              FUN_25a0b0c0000(&local_2108);
              iVar10 = _LastError;
              if (((int)uVar27 < 0) || (uVar26 = (ulonglong)uVar27, 0xff < (int)uVar32))
              goto LAB_25a0b0c378a;
              goto LAB_25a0b0c3f00;
            }
            uVar32 = 0;
            uVar26 = 0;
            do {
              if (uVar30 - 1 == uVar26) goto LAB_25a0b0c378a;
              lVar11 = uVar26 + 1;
              uVar26 = uVar26 + 1;
            } while (local_2184[lVar11] != sVar3);
            if (uVar26 < uVar30) {
LAB_25a0b0c3ed5:
              uVar32 = 0;
              if (-1 < (int)uVar26) goto LAB_25a0b0c3ee3;
            }
          }
          else {
            bVar34 = true;
            uVar26 = 0;
            do {
              if (local_2184[uVar26] == sVar3) {
                lVar24 = 1;
                lVar11 = (ulonglong)uVar22 - 1;
                while (local_2184[(uint)((int)uVar26 + (int)lVar24)] == local_20a4[lVar24]) {
                  lVar24 = lVar24 + 1;
                  lVar11 = lVar11 + -1;
                  if (lVar11 == 0) goto LAB_25a0b0c3ec8;
                }
                if ((int)lVar11 == 0) {
LAB_25a0b0c3ec8:
                  uVar32 = 0;
                  if (bVar34) goto LAB_25a0b0c3ed5;
                  break;
                }
              }
              uVar26 = uVar26 + 1;
              uVar32 = 0;
              bVar34 = uVar26 < uVar30;
            } while (uVar26 != uVar30);
          }
        }
      }
    }
LAB_25a0b0c378a:
    _LastError = iVar10;
    FUN_25a0b0c0000(&local_20a8);
    FUN_25a0b0c0000(&local_2150);
    if ((int)uVar32 < 1) {
      if ((int)DAT_25a0b0e46e0 < 1) {
        DAT_25a0b0e46e8 = 0;
      }
      lVar11 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      lVar12 = lVar11 + -0x3840;
      if (DAT_25a0b0e26cd == '\0') {
        lVar12 = lVar11;
      }
      DAT_25a0b0e26d0 = lVar12 + 900;
      if (DAT_25a0b0e26ce == '\0') {
        DAT_25a0b0e26d0 = lVar12;
      }
      if (DAT_25a0b0e258f != '\0') {
        MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0dee60);
      }
      lVar12 = -0xc00;
      do {
        if ((((*(int *)((longlong)&local_1440 + lVar12) != 0) &&
             (lVar11 = *(longlong *)((longlong)alStack_143c + lVar12), lVar11 != 0)) &&
            ((int *)(lVar11 + -0xc) != (int *)0x0)) && (*(int *)(lVar11 + -0xc) != 0)) {
          piVar16 = (int *)(lVar11 + -8);
          *piVar16 = *piVar16 + -1;
          if (*piVar16 == 0) {
            (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
          }
        }
        *(undefined8 *)((longlong)alStack_143c + lVar12) = 0;
        *(undefined4 *)((longlong)&local_1440 + lVar12) = 0;
        lVar12 = lVar12 + 0xc;
      } while (lVar12 != 0);
      lVar12 = -0xc00;
      do {
        if (((*(int *)(auStack_840 + lVar12) != 0) &&
            (lVar11 = *(longlong *)(auStack_840 + lVar12 + 4), lVar11 != 0)) &&
           (((int *)(lVar11 + -0xc) != (int *)0x0 && (*(int *)(lVar11 + -0xc) != 0)))) {
          piVar16 = (int *)(lVar11 + -8);
          *piVar16 = *piVar16 + -1;
          if (*piVar16 == 0) {
            (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
          }
        }
        *(undefined8 *)(auStack_840 + lVar12 + 4) = 0;
        *(undefined4 *)(auStack_840 + lVar12) = 0;
        lVar12 = lVar12 + 0xc;
      } while (lVar12 != 0);
    }
    else {
      lVar11 = 0;
      lVar12 = 0;
      local_2120 = uVar32;
      do {
        if (lVar12 == 0xc00) {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f062f000001f6);
          goto LAB_25a0b0c55bb;
        }
        *(undefined8 *)((longlong)&DAT_25a0b0e26e0 + lVar11) = *(undefined8 *)(auStack_840 + lVar11)
        ;
        FUN_25a0b0c05f0((longlong)&DAT_25a0b0e2ee0 + lVar12,(longlong)&local_1440 + lVar12,0,
                        &PTR_DAT_25a0b0e0e60);
        FUN_25a0b0c05f0((longlong)&DAT_25a0b0e3ae0 + lVar12,local_2040 + lVar12,0,
                        &PTR_DAT_25a0b0e0e70);
        lVar12 = lVar12 + 0xc;
        lVar11 = lVar11 + 8;
      } while ((uVar32 & 0xffffffff) * 0xc != lVar12);
      DAT_25a0b0e46e8 = 1;
      uVar23 = (uint)local_2120;
      DAT_25a0b0e46e0 = uVar23;
      DAT_25a0b0e26d0 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      if (DAT_25a0b0e258f != '\0') {
        local_20e0.opaque = 0;
        local_2098 = 0;
        local_2168 = 0;
        local_20e0.text._0_4_ = 0;
        local_20e0.text._4_4_ = 0;
        uStack_2094 = 0;
        local_2090 = 0;
        local_2164 = (short *)0x0;
        lVar12 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
        if ((int)DAT_25a0b0e46e0 < 1) {
LAB_25a0b0c3c21:
          pMVar18 = &string_ref_25a0b0def48;
          ppuVar29 = &PTR_DAT_25a0b0e0e90;
        }
        else {
          uVar32 = 0xffffffff;
          uVar26 = 0;
          plVar28 = &DAT_25a0b0e26e0;
          do {
            if (uVar26 == 0x100) goto LAB_25a0b0c55bb;
            if (lVar12 <= *plVar28) {
              if (-1 < (int)(uint)uVar32) {
                if (0xff < (uint)uVar32) goto LAB_25a0b0c55db;
                if ((longlong)(&DAT_25a0b0e26e0)[uVar32] <= *plVar28) goto LAB_25a0b0c3943;
              }
              uVar32 = uVar26 & 0xffffffff;
            }
LAB_25a0b0c3943:
            uVar26 = uVar26 + 1;
            plVar28 = plVar28 + 1;
          } while (DAT_25a0b0e46e0 != uVar26);
          if ((int)(uint)uVar32 < 0) goto LAB_25a0b0c3c21;
          if (0xff < (uint)uVar32) {
LAB_25a0b0c567b:
            (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x350646000001f6);
LAB_25a0b0c569b:
            (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x180605000001f6);
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          MT5_TimeToString((void *)0x25a0930b4c8,(&DAT_25a0b0e26e0)[uVar32],3);
          FUN_25a0b0c05f0(&local_2098,&runtime_string_result,1,&PTR_DAT_25a0b0e0ea0);
          MT5_Dispatch((void *)0x25a0930b4c8,0xd8,4,0x590008,&string_ref_25a0b0def88,0x590008,
                       &local_2098,0x590008,&DAT_25a0b0e3ae0 + uVar32 * 3,0x590008,
                       &DAT_25a0b0e2ee0 + uVar32 * 3);
          pMVar18 = &local_20e0;
          FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0eb0);
          ppuVar29 = &PTR_DAT_25a0b0e0ec0;
        }
        FUN_25a0b0c05f0(&local_2168,pMVar18,0,ppuVar29);
        FUN_25a0b0c05f0(&runtime_string_result,&local_2168,1,&PTR_DAT_25a0b0e0ed0);
        FUN_25a0b0c0000(&local_2168);
        FUN_25a0b0c0000(&local_2098);
        FUN_25a0b0c0000(&local_20e0);
        FUN_25a0b0c05f0(&local_2058,&runtime_string_result,1,&PTR_DAT_25a0b0e0e80);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0def18,0x520004,uVar23,
                     0x520004,DAT_25a0b0e470c / 0xe10,0x590008,&local_2058);
      }
      lVar12 = -0xc00;
      do {
        if (((*(int *)((longlong)&local_1440 + lVar12) != 0) &&
            (lVar11 = *(longlong *)((longlong)alStack_143c + lVar12), lVar11 != 0)) &&
           (((int *)(lVar11 + -0xc) != (int *)0x0 && (*(int *)(lVar11 + -0xc) != 0)))) {
          piVar16 = (int *)(lVar11 + -8);
          *piVar16 = *piVar16 + -1;
          if (*piVar16 == 0) {
            (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
          }
        }
        *(undefined8 *)((longlong)alStack_143c + lVar12) = 0;
        *(undefined4 *)((longlong)&local_1440 + lVar12) = 0;
        lVar12 = lVar12 + 0xc;
      } while (lVar12 != 0);
      lVar12 = -0xc00;
      do {
        if ((((*(int *)(auStack_840 + lVar12) != 0) &&
             (lVar11 = *(longlong *)(auStack_840 + lVar12 + 4), lVar11 != 0)) &&
            ((int *)(lVar11 + -0xc) != (int *)0x0)) && (*(int *)(lVar11 + -0xc) != 0)) {
          piVar16 = (int *)(lVar11 + -8);
          *piVar16 = *piVar16 + -1;
          if (*piVar16 == 0) {
            (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
          }
        }
        *(undefined8 *)(auStack_840 + lVar12 + 4) = 0;
        *(undefined4 *)(auStack_840 + lVar12) = 0;
        lVar12 = lVar12 + 0xc;
      } while (lVar12 != 0);
    }
  }
  FUN_25a0b0c0000(&local_2188);
LAB_25a0b0c3615:
  FUN_25a0b0c0000(&local_2058);
  return;
LAB_25a0b0c55bb:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150642000001f6);
LAB_25a0b0c55db:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x4c0642000001f6);
LAB_25a0b0c55fb:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3205b0000001f9);
LAB_25a0b0c561b:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2105b0000001f9);
LAB_25a0b0c563b:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2c05b0000001f9);
LAB_25a0b0c565b:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1a05b0000001f9);
  goto LAB_25a0b0c567b;
}



/* Address: 25a0b0c56c0 */

void FUN_25a0b0c56c0(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  uint uVar8;
  longlong arg_4;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar12;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  if ((DAT_25a0b0e258f != '\0') && (ShowPanel)) {
    if (DAT_25a0b0e4d24 == '\x01') {
      FUN_25a0b0c0d50(&DAT_25a0b0e4c90);
      DAT_25a0b0e4d24 = '\0';
    }
    iVar3 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528);
    if (-1 < iVar3) {
      MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528);
    }
    (*(code *)&MT5_ObjectsDeleteAllPrefix)
              (0x25a0930b4c8,0,&string_ref_25a0b0dfc40,0xffffffff,CONCAT44(uVar12,0xffffffff));
    lVar4 = MT5_ChartGetInteger((void *)0x25a0930b4c8,0,0x6a,0);
    lVar5 = MT5_ChartGetInteger((void *)0x25a0930b4c8,0,0x6b,0);
    lVar6 = 1000;
    if (0 < lVar4) {
      lVar6 = lVar4;
    }
    arg_4 = (longlong)PanelX;
    lVar4 = 700;
    if (0 < lVar5) {
      lVar4 = lVar5;
    }
    lVar5 = (longlong)PanelY;
    dVar11 = ((double)lVar6 * DAT_25a0b0dbab8 - (double)PanelX) / DAT_25a0b0dbac0;
    dVar9 = ((double)lVar4 * DAT_25a0b0dbac8 - (double)PanelY) / DAT_25a0b0dbad0;
    if (dVar9 <= dVar11) {
      dVar11 = dVar9;
    }
    if (DAT_25a0b0dbad8 <= dVar11) {
      dVar11 = DAT_25a0b0dbad8;
    }
    dVar9 = DAT_25a0b0dbae0;
    if (DAT_25a0b0dbae0 <= dVar11) {
      dVar9 = dVar11;
    }
    dVar10 = DAT_25a0b0dbac0 * dVar9;
    uVar8 = (uint)((ulonglong)dVar10 >> 0x34) & 0x7ff;
    lVar6 = (ulonglong)uVar8 - 0x3ff;
    dVar11 = dVar10;
    if ((ulonglong)uVar8 < 0x433) {
      if (uVar8 < 0x3ff) {
        dVar11 = (double)((ulonglong)dVar10 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar6 != -1) {
          dVar11 = (double)((ulonglong)dVar10 & 0x8000000000000000);
        }
      }
      else {
        bVar7 = (byte)lVar6;
        if (((longlong)dVar10 << (bVar7 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar11 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar10 &
                           -0x10000000000000 >> (bVar7 & 0x3f));
        }
      }
    }
    else if (lVar6 == 0x400) {
      dVar11 = dVar10 + dVar10;
    }
    dVar9 = dVar9 * DAT_25a0b0dbad0;
    DAT_25a0b0e4c84 = (int)dVar11;
    uVar8 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
    lVar6 = (ulonglong)uVar8 - 0x3ff;
    dVar11 = dVar9;
    if ((ulonglong)uVar8 < 0x433) {
      if (uVar8 < 0x3ff) {
        dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar6 != -1) {
          dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000);
        }
      }
      else {
        bVar7 = (byte)lVar6;
        if (((longlong)dVar9 << (bVar7 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar11 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar9 &
                           -0x10000000000000 >> (bVar7 & 0x3f));
        }
      }
    }
    else if (lVar6 == 0x400) {
      dVar11 = dVar9 + dVar9;
    }
    DAT_25a0b0e4c88 = (int)dVar11;
    cVar1 = FUN_25a0b0c0e30(&DAT_25a0b0e4c90,&string_ref_25a0b0df528,DAT_25a0b0e4c84,DAT_25a0b0e4c88
                            ,2);
    if ((((cVar1 == '\0') ||
         (lVar6 = MT5_Dispatch((void *)0x25a0930b4c8,0x112,6,0x550005,0,0x590008,
                               &string_ref_25a0b0df528,0x520004,0x6a,0x520004,0,0x540005,0,0x580007,
                               0.0), (char)lVar6 == '\0')) ||
        (bVar2 = MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528,0x3f4,arg_4),
        !bVar2)) ||
       ((bVar2 = MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528,0x3f5,lVar5),
        !bVar2 || (bVar2 = MT5_ObjectSetString((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528,0x3f9
                                               ,&DAT_25a0b0e4cc0), !bVar2)))) {
      MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0df5b8);
      DAT_25a0b0e4d24 = '\0';
    }
    else {
      DAT_25a0b0e4ca8 = 0;
      FUN_25a0b0c05f0(&DAT_25a0b0e4cb0,&string_ref_25a0b0df528,0,&PTR_DAT_25a0b0e0b40);
      DAT_25a0b0e4cbc = 0x6a;
      DAT_25a0b0e4d24 = '\x01';
    }
  }
  return;
}



/* Address: 25a0b0c5bc0 */

void FUN_25a0b0c5bc0(void)

{
  double dVar1;
  wchar16 wVar2;
  wchar16 wVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  double dVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  longlong lVar11;
  ulonglong arg_1;
  longlong lVar12;
  double *pdVar13;
  int *piVar14;
  int iVar15;
  int arg_1_00;
  ulonglong uVar16;
  undefined4 local_b8;
  wchar16 *local_b4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_88;
  int local_84;
  int local_80;
  
  local_b8 = 0;
  local_b4 = (wchar16 *)0x0;
  DAT_25a0b0e2678 = 0;
  DAT_25a0b0e2680 = 0.0;
  DAT_25a0b0e2674 = 0;
  DAT_25a0b0e2688 = 0.0;
  DAT_25a0b0e26a0 = 0;
  DAT_25a0b0e26a8 = 0.0;
  DAT_25a0b0e2690 = 0.0;
  DAT_25a0b0e2698 = 0.0;
  lVar11 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
  MT5_TimeToStruct((void *)0x25a0930b4c8,lVar11,&local_a8);
  bVar9 = MT5_HistorySelect((void *)0x25a0930b4c8,0,lVar11);
  if ((bVar9) && (iVar10 = MT5_HistoryDealsTotal((void *)0x25a0930b4c8), 0 < iVar10)) {
    arg_1_00 = 0;
    lVar11 = (longlong)InpMagic;
    do {
      arg_1 = MT5_HistoryDealGetTicket((void *)0x25a0930b4c8,arg_1_00);
      if (arg_1 != 0) {
        MT5_HistoryDealGetString((void *)0x25a0930b4c8,arg_1,0);
        FUN_25a0b0c05f0(&local_b8,&runtime_string_result,1,&PTR_DAT_25a0b0e1110);
        if (local_b4 == _Symbol.text) {
LAB_25a0b0c5e18:
          lVar12 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,0xb);
          if (((lVar12 == lVar11) &&
              (uVar16 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,3),
              (uVar16 & 0xfffffffe) == 0)) &&
             (lVar12 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,4),
             (int)lVar12 - 1U < 3)) {
            lVar12 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,2);
            MT5_TimeToStruct((void *)0x25a0930b4c8,lVar12,&local_88);
            MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,9);
            dVar7 = runtime_double_result;
            MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,8);
            dVar7 = dVar7 + runtime_double_result;
            MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,7);
            piVar14 = &DAT_25a0b0e2674;
            dVar7 = dVar7 + runtime_double_result;
            pdVar13 = (double *)&DAT_25a0b0e26a0;
            if (0.0 < dVar7) {
LAB_25a0b0c5feb:
              dVar1 = *pdVar13;
              *piVar14 = *piVar14 + 1;
              *pdVar13 = dVar1 + dVar7;
              dVar1 = DAT_25a0b0e2690;
            }
            else {
              piVar14 = &DAT_25a0b0e2678;
              pdVar13 = &DAT_25a0b0e26a8;
              dVar1 = DAT_25a0b0e2690;
              if (dVar7 < 0.0) goto LAB_25a0b0c5feb;
            }
            DAT_25a0b0e2690 = dVar7;
            if (dVar7 <= dVar1) {
              DAT_25a0b0e2690 = dVar1;
            }
            if (dVar7 < DAT_25a0b0e2698) {
              DAT_25a0b0e2698 = dVar7;
            }
            if (((local_80 == local_a0) && (local_84 == local_a4)) && (local_88 == local_a8)) {
              DAT_25a0b0e2680 = DAT_25a0b0e2680 + dVar7;
            }
            if ((local_84 == local_a4) && (local_88 == local_a8)) {
              DAT_25a0b0e2688 = dVar7 + DAT_25a0b0e2688;
            }
          }
        }
        else if ((local_b4 != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar4 = *(uint *)(local_b4 + -2);
          uVar5 = *(uint *)(_Symbol.text + -2);
          uVar8 = uVar5;
          if (uVar4 < uVar5) {
            uVar8 = uVar4;
          }
          iVar15 = uVar4 - uVar5;
          if (uVar8 != 0) {
            uVar16 = 1;
            do {
              wVar2 = local_b4[uVar16 - 1];
              wVar3 = _Symbol.text[uVar16 - 1];
              if (uVar8 <= uVar16) break;
              uVar16 = uVar16 + 1;
            } while (wVar2 == wVar3);
            if (wVar2 != wVar3) {
              iVar15 = (uint)(ushort)wVar2 - (uint)(ushort)wVar3;
            }
          }
          if (iVar15 == 0) goto LAB_25a0b0c5e18;
        }
      }
      arg_1_00 = arg_1_00 + 1;
    } while (arg_1_00 != iVar10);
  }
  if (((DAT_25a0b0e26a8 < DAT_25a0b0dbae8) && (DAT_25a0b0e26a8 == 0.0)) && (!NAN(DAT_25a0b0e26a8)))
  {
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x240a3a000001f7);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  DAT_25a0b0e2670 = local_a8 * 100 + local_a4;
  DAT_25a0b0e266c = local_a4 * 100 + local_a8 * 10000 + local_a0;
  FUN_25a0b0c0000(&local_b8);
  return;
}



/* Address: 25a0b0c60f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0c60f0(void)

{
  int *piVar1;
  longlong lVar2;
  wchar16 wVar3;
  wchar16 wVar4;
  bool bVar5;
  code *pcVar6;
  double dVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  ulonglong uVar14;
  longlong lVar15;
  byte bVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  uint uVar19;
  MqlStringAnalysisView *pMVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 *puVar24;
  uint uVar25;
  ulonglong uVar26;
  undefined **ppuVar27;
  undefined8 *puVar28;
  ulonglong uVar29;
  undefined4 uVar30;
  double arg_1;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  undefined4 local_288;
  longlong local_284;
  undefined4 local_278;
  undefined8 local_274;
  undefined4 local_268;
  longlong local_264;
  undefined4 local_258;
  longlong local_254;
  undefined4 local_248;
  undefined8 local_244;
  undefined4 local_238;
  undefined8 local_234;
  undefined4 local_228;
  undefined8 local_224;
  undefined4 local_218;
  longlong local_214;
  undefined4 local_208;
  longlong local_204;
  undefined4 local_1f8;
  undefined8 local_1f4;
  longlong local_1e8;
  undefined4 local_1e0;
  undefined8 local_1dc;
  undefined4 local_1d0;
  undefined8 local_1cc;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  wchar16 *local_1b4;
  undefined4 local_1a8;
  undefined8 local_1a4;
  undefined4 local_198;
  undefined8 local_194;
  undefined4 local_188;
  undefined8 local_184;
  undefined4 local_17c;
  undefined8 local_178;
  undefined4 local_170;
  undefined8 local_16c;
  undefined4 local_164;
  undefined8 local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined4 local_14c;
  undefined8 local_148;
  undefined4 local_140;
  undefined8 local_13c;
  undefined4 local_134;
  undefined8 local_130;
  undefined4 local_128;
  undefined8 local_124;
  int local_11c;
  undefined8 local_118;
  int local_110 [7];
  wchar_t *local_f4;
  undefined4 local_ec;
  wchar_t *local_e8;
  undefined4 local_e0;
  wchar_t *local_dc;
  undefined4 local_d4;
  wchar_t *local_d0;
  undefined4 local_c8;
  wchar_t *local_c4;
  undefined4 local_bc;
  wchar_t *local_b8;
  undefined4 local_b0;
  wchar_t *local_ac;
  undefined4 local_a4;
  wchar_t *local_a0;
  undefined4 local_98;
  wchar_t *local_94;
  int iStack_8c;
  undefined1 local_88 [24];
  int local_70;
  
  local_208 = 0;
  local_198 = 0;
  local_218 = 0;
  local_1a8 = 0;
  local_258 = 0;
  local_288 = 0;
  local_268 = 0;
  local_228 = 0;
  local_238 = 0;
  local_248 = 0;
  local_1f8 = 0;
  local_1d0 = 0;
  local_1e0 = 0;
  local_204 = 0;
  local_194 = 0;
  local_214 = 0;
  local_1a4 = 0;
  local_254 = 0;
  local_284 = 0;
  local_264 = 0;
  local_224 = 0;
  local_234 = 0;
  local_244 = 0;
  local_1f4 = 0;
  local_1cc = 0;
  local_1dc = 0;
  if (((DAT_25a0b0e258f == '\0') || (!ShowPanel)) || ((DAT_25a0b0e4d24 & 1) == 0))
  goto LAB_25a0b0c85d1;
  local_1b8 = 0;
  local_1b4 = (wchar16 *)0x0;
  dVar7 = DAT_25a0b0e26a0 + DAT_25a0b0e26a8;
  iVar12 = MT5_PositionsTotal((void *)0x25a0930b4c8);
  if (iVar12 + -1 < 0) {
LAB_25a0b0c64d9:
    arg_1 = (double)FUN_25a0b0d6270(state_v_22630,0);
  }
  else {
    arg_1 = 0.0;
    local_1e8 = (longlong)InpMagic;
    iVar12 = iVar12 + -1;
    do {
      uVar14 = MT5_PositionGetTicket((void *)0x25a0930b4c8,iVar12);
      if (uVar14 != 0) {
        local_88._0_4_ = 0;
        local_278 = 0;
        local_88._4_8_ = 0;
        local_274 = 0;
        MT5_PositionGetString((void *)0x25a0930b4c8,0);
        FUN_25a0b0c05f0(local_88,&runtime_string_result,1,&PTR_DAT_25a0b0dfe18);
        FUN_25a0b0c05f0(&local_278,local_88,0,&PTR_DAT_25a0b0dfe28);
        FUN_25a0b0c05f0(&runtime_string_result,&local_278,1,&PTR_DAT_25a0b0dfe38);
        FUN_25a0b0c0000(&local_278);
        FUN_25a0b0c0000(local_88);
        FUN_25a0b0c05f0(&local_1b8,&runtime_string_result,1,&PTR_DAT_25a0b0e1100);
        if (local_1b4 == _Symbol.text) {
LAB_25a0b0c647c:
          lVar15 = MT5_PositionGetInteger((void *)0x25a0930b4c8,0xc);
          if (lVar15 == local_1e8) {
            MT5_PositionGetDouble((void *)0x25a0930b4c8,3);
            arg_1 = arg_1 + runtime_double_result;
          }
        }
        else if ((local_1b4 != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar25 = *(uint *)(local_1b4 + -2);
          uVar21 = *(uint *)(_Symbol.text + -2);
          uVar19 = uVar21;
          if (uVar25 < uVar21) {
            uVar19 = uVar25;
          }
          iVar13 = uVar25 - uVar21;
          if (uVar19 != 0) {
            uVar14 = 1;
            do {
              wVar3 = local_1b4[uVar14 - 1];
              wVar4 = _Symbol.text[uVar14 - 1];
              if (uVar19 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (wVar3 == wVar4);
            if (wVar3 != wVar4) {
              iVar13 = (uint)(ushort)wVar3 - (uint)(ushort)wVar4;
            }
          }
          if (iVar13 == 0) goto LAB_25a0b0c647c;
        }
      }
      bVar5 = 0 < iVar12;
      iVar12 = iVar12 + -1;
    } while (bVar5);
    if (arg_1 <= 0.0) goto LAB_25a0b0c64d9;
  }
  FUN_25a0b0c0000(&local_1b8);
  local_1e8 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x12);
  local_228 = 0;
  local_224 = 0;
  if (state_v_225ad == false) {
    MT5_DoubleToString((void *)0x25a0930b4c8,state_v_225b8,1);
    FUN_25a0b0c05f0(&local_268,&runtime_string_result,1,&PTR_DAT_25a0b0e11b0);
    FUN_25a0b0c05f0(&local_288,&string_ref_25a0b0df7c0);
    lVar15 = local_264;
    if (local_264 != 0) {
      uVar25 = *(uint *)(local_264 + -4);
      uVar14 = (ulonglong)uVar25;
      if ((uVar14 != 0) || (local_284 == 0)) {
        if (local_284 == 0) {
          uVar26 = 0;
          uVar21 = uVar25;
        }
        else {
          uVar26 = (ulonglong)*(uint *)(local_284 + -4);
          uVar21 = uVar25 + *(uint *)(local_284 + -4);
        }
        cVar11 = FUN_25a0b0c0060(&local_288);
        if (cVar11 == '\0') goto LAB_25a0b0c87e2;
        if (uVar14 != 0) {
          lVar2 = local_284 + uVar26 * 2;
          if (uVar25 < 0x10) {
            uVar26 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar15) < 0x20) {
            uVar26 = 0;
          }
          else {
            uVar29 = 0;
            uVar26 = (ulonglong)(uVar25 & 0xfffffff8);
            do {
              uVar8 = ((undefined8 *)(lVar15 + uVar29))[1];
              *(undefined8 *)(lVar2 + uVar29) = *(undefined8 *)(lVar15 + uVar29);
              ((undefined8 *)(lVar2 + uVar29))[1] = uVar8;
              uVar29 = uVar29 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar29);
            if (uVar26 == uVar14) goto LAB_25a0b0c66e2;
          }
          do {
            *(undefined2 *)(lVar2 + uVar26 * 2) = *(undefined2 *)(lVar15 + uVar26 * 2);
            uVar26 = uVar26 + 1;
          } while (uVar14 != uVar26);
        }
LAB_25a0b0c66e2:
        *(uint *)(local_284 + -4) = uVar21;
        *(undefined2 *)(local_284 + (ulonglong)uVar21 * 2) = 0;
      }
    }
    uVar26 = 0;
    FUN_25a0b0c05f0(&local_258,&local_288,0,&PTR_DAT_25a0b0e11d0);
    uVar25 = DAT_25a0b0df7d4;
    uVar14 = (ulonglong)DAT_25a0b0df7d4;
    if ((uVar14 == 0) && (local_254 != 0)) {
LAB_25a0b0c681d:
      FUN_25a0b0c05f0(&local_228,&local_258,0,&PTR_DAT_25a0b0e11e0);
      uVar30 = 0xff5cb8;
      goto LAB_25a0b0c6843;
    }
    if (local_254 != 0) {
      uVar26 = (ulonglong)*(uint *)(local_254 + -4);
    }
    uVar19 = DAT_25a0b0df7d4 + (int)uVar26;
    uVar21 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar21 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar21)))) {
      uVar21 = 0x7ffffffe;
    }
    cVar11 = FUN_25a0b0c0060(&local_258,uVar21);
    if (cVar11 != '\0') {
      if (uVar14 != 0) {
        lVar15 = local_254 + uVar26 * 2;
        if (uVar25 < 0x10) {
          uVar26 = 0;
        }
        else if (lVar15 - 0x25a0b0df7d8U < 0x20) {
          uVar26 = 0;
        }
        else {
          uVar29 = 0;
          uVar26 = (ulonglong)(uVar25 & 0xfffffff8);
          do {
            uVar8 = *(undefined8 *)(uVar29 + 0x25a0b0df7e0);
            *(undefined8 *)(lVar15 + uVar29) = *(undefined8 *)((longlong)&DAT_25a0b0df7d8 + uVar29);
            ((undefined8 *)(lVar15 + uVar29))[1] = uVar8;
            uVar29 = uVar29 + 0x10;
          } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar29);
          if (uVar26 == uVar14) goto LAB_25a0b0c6812;
        }
        do {
          *(undefined2 *)(lVar15 + uVar26 * 2) = (&DAT_25a0b0df7d8)[uVar26];
          uVar26 = uVar26 + 1;
        } while (uVar14 != uVar26);
      }
LAB_25a0b0c6812:
      *(uint *)(local_254 + -4) = uVar19;
      *(undefined2 *)(local_254 + (ulonglong)uVar19 * 2) = 0;
      goto LAB_25a0b0c681d;
    }
  }
  else {
    FUN_25a0b0c05f0(&local_228,&string_ref_25a0b0df790,0,&PTR_DAT_25a0b0e11a0);
    uVar30 = 0x9b858f;
LAB_25a0b0c6843:
    local_238 = 0;
    local_234 = 0;
    FUN_25a0b0c05f0(&local_238,&string_ref_25a0b0df7f8,0,&PTR_DAT_25a0b0e11f0);
    uVar23 = 0x9b858f;
    if (DAT_25a0b0e26b0 < 0.0) {
LAB_25a0b0c6a65:
      iVar12 = EAMode;
      local_248 = 0;
      local_244 = 0;
      if (EAMode == 2) {
        pMVar20 = &string_ref_25a0b0df868;
        ppuVar27 = &PTR_DAT_25a0b0e1230;
      }
      else {
        pMVar20 = &string_ref_25a0b0df908;
        ppuVar27 = &PTR_DAT_25a0b0e1240;
        if (Mode1Stop == 0) {
          pMVar20 = &string_ref_25a0b0df8b8;
        }
      }
      FUN_25a0b0c05f0(&local_248,pMVar20,0,ppuVar27);
      local_1f8 = 0;
      local_1f4 = 0;
      lVar15 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      MT5_TimeToString((void *)0x25a0930b4c8,lVar15,3);
      FUN_25a0b0c05f0(&local_268,&runtime_string_result,1,&PTR_DAT_25a0b0e1250);
      FUN_25a0b0c05f0(&local_1f8,&local_268,0,&PTR_DAT_25a0b0e1260);
      puVar10 = ram0x025a0b0e4d0c;
      uVar9 = uRam0000025a0b0dbb18;
      uVar8 = _DAT_25a0b0dbb10;
      if (((DAT_25a0b0e4cf0._4_4_ == 4) && (ram0x025a0b0e4d0c != (undefined8 *)0x0)) &&
         (uVar14 = (ulonglong)DAT_25a0b0e4cf8, uVar14 != 0)) {
        lVar15 = -0xc;
        do {
          if ((ulonglong)*(uint *)((longlong)&DAT_25a0b0e4d08 + lVar15) == 0) break;
          uVar14 = uVar14 * *(uint *)((longlong)&DAT_25a0b0e4d08 + lVar15);
          lVar15 = lVar15 + 4;
        } while (lVar15 != 0);
        if (uVar14 != 0) {
          if (uVar14 < 4) {
            uVar29 = 0;
          }
          else {
            uVar29 = uVar14 & 0xfffffffffffffffc;
            uVar26 = uVar29;
            puVar28 = ram0x025a0b0e4d0c;
            do {
              *puVar28 = uVar8;
              puVar28[1] = uVar9;
              puVar28 = puVar28 + 2;
              uVar26 = uVar26 - 4;
            } while (uVar26 != 0);
            if (uVar14 == uVar29) goto LAB_25a0b0c6c2f;
          }
          lVar15 = uVar14 - uVar29;
          puVar18 = (undefined4 *)((longlong)puVar10 + uVar29 * 4);
          do {
            *puVar18 = 0xfc040308;
            puVar18 = puVar18 + 1;
            lVar15 = lVar15 + -1;
          } while (lVar15 != 0);
        }
      }
LAB_25a0b0c6c2f:
      FUN_25a0b0d8e90(0xe,0xe,0x1fa,0x29a,0x80304,0x692649,1);
      FUN_25a0b0d9ab0(0x18,0x18,0x1d8,0x278,0xd0608,0xbe307a);
      dVar31 = (DAT_25a0b0dbb20 * (double)DAT_25a0b0e4c88) / DAT_25a0b0dbb28;
      uVar25 = (uint)((ulonglong)dVar31 >> 0x34) & 0x7ff;
      lVar15 = (ulonglong)uVar25 - 0x3ff;
      dVar32 = dVar31;
      if ((ulonglong)uVar25 < 0x433) {
        if (uVar25 < 0x3ff) {
          dVar32 = (double)((ulonglong)dVar31 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar15 != -1) {
            dVar32 = (double)((ulonglong)dVar31 & 0x8000000000000000);
          }
        }
        else {
          bVar16 = (byte)lVar15;
          if (((longlong)dVar31 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar32 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar31 &
                             -0x10000000000000 >> (bVar16 & 0x3f));
          }
        }
      }
      else if (lVar15 == 0x400) {
        dVar32 = dVar31 + dVar31;
      }
      dVar35 = (DAT_25a0b0dbb30 * (double)DAT_25a0b0e4c84) / DAT_25a0b0dbb38;
      uVar25 = (uint)((ulonglong)dVar35 >> 0x34) & 0x7ff;
      lVar15 = (ulonglong)uVar25 - 0x3ff;
      dVar31 = dVar35;
      if ((ulonglong)uVar25 < 0x433) {
        if (uVar25 < 0x3ff) {
          dVar31 = (double)((ulonglong)dVar35 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar15 != -1) {
            dVar31 = (double)((ulonglong)dVar35 & 0x8000000000000000);
          }
        }
        else {
          bVar16 = (byte)lVar15;
          if (((longlong)dVar35 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar31 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar35 &
                             -0x10000000000000 >> (bVar16 & 0x3f));
          }
        }
      }
      else if (lVar15 == 0x400) {
        dVar31 = dVar35 + dVar35;
      }
      dVar33 = ((double)DAT_25a0b0e4c88 * DAT_25a0b0dbb40) / DAT_25a0b0dbb28;
      uVar25 = (uint)((ulonglong)dVar33 >> 0x34) & 0x7ff;
      lVar15 = (ulonglong)uVar25 - 0x3ff;
      dVar35 = dVar33;
      if ((ulonglong)uVar25 < 0x433) {
        if (uVar25 < 0x3ff) {
          dVar35 = (double)((ulonglong)dVar33 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar15 != -1) {
            dVar35 = (double)((ulonglong)dVar33 & 0x8000000000000000);
          }
        }
        else {
          bVar16 = (byte)lVar15;
          if (((longlong)dVar33 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar35 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar33 &
                             -0x10000000000000 >> (bVar16 & 0x3f));
          }
        }
      }
      else if (lVar15 == 0x400) {
        dVar35 = dVar33 + dVar33;
      }
      dVar34 = ((double)DAT_25a0b0e4c84 * DAT_25a0b0dbb48) / DAT_25a0b0dbb38;
      uVar25 = (uint)((ulonglong)dVar34 >> 0x34) & 0x7ff;
      lVar15 = (ulonglong)uVar25 - 0x3ff;
      dVar33 = dVar34;
      if ((ulonglong)uVar25 < 0x433) {
        if (uVar25 < 0x3ff) {
          dVar33 = (double)((ulonglong)dVar34 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar15 != -1) {
            dVar33 = (double)((ulonglong)dVar34 & 0x8000000000000000);
          }
        }
        else {
          bVar16 = (byte)lVar15;
          if (((longlong)dVar34 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar33 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar34 &
                             -0x10000000000000 >> (bVar16 & 0x3f));
          }
        }
      }
      else if (lVar15 == 0x400) {
        dVar33 = dVar34 + dVar34;
      }
      FUN_25a0b0d6040((int)dVar33,(int)dVar35,(int)dVar31,(int)dVar32,0xff0e0917);
      FUN_25a0b0d8720(0x2c,0x26,0x1dc,0x26,0xff5cb8,2);
      FUN_25a0b0d8720(0x2c,0x70,0x1dc,0x70,0x692649,1);
      FUN_25a0b0d8720(0x2c,0x26,0x1e,0x34,0xbe307a,2);
      FUN_25a0b0d8720(0x1dc,0x26,0x1ea,0x34,0xbe307a,2);
      FUN_25a0b0d92f0(0x48,0x48,0xe,0xff5cb8);
      FUN_25a0b0d92f0(0x48,0x48,9,0xbe307a);
      FUN_25a0b0d92f0(0x48,0x48,4,0xf4ebee);
      FUN_25a0b0d8720(0x3a,0x48,0x56,0x48,0xff5cb8,1);
      FUN_25a0b0d8720(0x48,0x3a,0x48,0x56,0xff5cb8,1);
      FUN_25a0b0c05f0(&local_268,&string_ref_25a0b0df940,0,&PTR_DAT_25a0b0e1270);
      FUN_25a0b0d82b0(0x69,0x31,&local_268,0xf4ebee,0x12,1,0);
      FUN_25a0b0c05f0(&local_268,&string_ref_25a0b0df968,0,&PTR_DAT_25a0b0e1280);
      FUN_25a0b0d82b0(0xf0,0x31,&local_268,0xff5cb8,0x12,1,0);
      FUN_25a0b0c05f0(&local_268,&string_ref_25a0b0df9c0,0,&PTR_DAT_25a0b0e1290);
      FUN_25a0b0d82b0(0x69,0x4e,&local_268,0xff5cb8,8,1,0);
      FUN_25a0b0d8720(0x1a4,0x36,0x1ad,0x2c,0xff5cb8,3);
      FUN_25a0b0d8720(0x1b1,0x36,0x1ba,0x2c,0xff5cb8,3);
      FUN_25a0b0d8720(0x1be,0x36,0x1c7,0x2c,0xff5cb8,3);
      FUN_25a0b0d8720(0x1cb,0x36,0x1d4,0x2c,0xff5cb8,3);
      FUN_25a0b0d9ab0(0x2c,0x7e,0x1b0,0x30,0x10080a,0x692649);
      local_1d0 = 0;
      local_278 = 0;
      local_1cc = 0;
      local_274 = 0;
      lVar15 = MT5_TerminalInfoInteger((void *)0x25a0930b4c8,8);
      local_1c0 = uVar23;
      local_1bc = uVar30;
      if ((((int)lVar15 == 0) || (iVar13 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,4), iVar13 == 0)
          ) || (lVar15 = MT5_AccountInfoInteger((void *)0x25a0930b4c8,0x21), lVar15 == 0)) {
        pMVar20 = &string_ref_25a0b0df5f0;
        ppuVar27 = &PTR_DAT_25a0b0e1120;
LAB_25a0b0c7393:
        FUN_25a0b0c05f0(&local_278,pMVar20,0,ppuVar27);
        uVar30 = 0x4f4feb;
      }
      else {
        lVar15 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1e);
        if (((int)lVar15 == 3) || ((int)lVar15 == 0)) {
          pMVar20 = &string_ref_25a0b0df628;
          ppuVar27 = &PTR_DAT_25a0b0e1130;
          goto LAB_25a0b0c7393;
        }
        lVar15 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
        MT5_TimeToStruct((void *)0x25a0930b4c8,lVar15,local_88);
        if ((local_70 == 6) || (local_70 == 0)) {
          FUN_25a0b0c05f0(&local_278,&string_ref_25a0b0df660,0,&PTR_DAT_25a0b0e1140);
          uVar30 = 0x9b858f;
        }
        else {
          cVar11 = FUN_25a0b0cab80();
          if (cVar11 == '\0') {
            if ((UseNewsFilter == false) || (cVar11 = FUN_25a0b0cb750(), cVar11 == '\0')) {
              iVar13 = 0x11;
              if (state_v_223c1 == false) {
                iVar13 = 0;
              }
              if (DAT_25a0b0e2594 < iVar13) {
                FUN_25a0b0c05f0(&local_278,&string_ref_25a0b0df750,0,&PTR_DAT_25a0b0e1180);
                uVar30 = 0x70cc34;
              }
              else {
                FUN_25a0b0c05f0(&local_278,&string_ref_25a0b0df718,0,&PTR_DAT_25a0b0e1170);
                uVar30 = 0x37b1ed;
              }
              goto LAB_25a0b0c73a8;
            }
            pMVar20 = &string_ref_25a0b0df6d8;
            ppuVar27 = &PTR_DAT_25a0b0e1160;
          }
          else {
            pMVar20 = &string_ref_25a0b0df698;
            ppuVar27 = &PTR_DAT_25a0b0e1150;
          }
          FUN_25a0b0c05f0(&local_278,pMVar20,0,ppuVar27);
          uVar30 = 0x37b1ed;
        }
      }
LAB_25a0b0c73a8:
      FUN_25a0b0c05f0(&runtime_string_result,&local_278,1,&PTR_DAT_25a0b0e1190);
      FUN_25a0b0c0000(&local_278);
      FUN_25a0b0c05f0(&local_268,&runtime_string_result,1,&PTR_DAT_25a0b0e12a0);
      FUN_25a0b0c05f0(&local_1d0,&local_268,0,&PTR_DAT_25a0b0e12b0);
      pMVar20 = &string_ref_25a0b0df9f0;
      local_1e0 = 0;
      local_1dc = 0;
      if (iVar12 == 2) {
        pMVar20 = &string_ref_25a0b0dc400;
      }
      FUN_25a0b0c05f0(&local_1e0,pMVar20,0,&PTR_DAT_25a0b0e12c0);
      FUN_25a0b0d8720(0xb8,0x87,0xb8,0xa5,0x692649,1);
      FUN_25a0b0d8720(0x160,0x87,0x160,0xa5,0x692649,1);
      FUN_25a0b0c05f0(&local_268,&_Symbol,1,&PTR_DAT_25a0b0e12d0);
      FUN_25a0b0d82b0(0x3e,0x8d,&local_268,0xff5cb8,10,1,0);
      FUN_25a0b0c05f0(&local_268,&local_1e0,0,&PTR_DAT_25a0b0e12e0);
      FUN_25a0b0d82b0(0x10c,0x8d,&local_268,0xf4ebee,9,1,1);
      FUN_25a0b0d8e90(0x16e,0x86,0x1ce,0xa5,0x17090e,uVar30,1);
      FUN_25a0b0c05f0(&local_268,&local_1d0,0,&PTR_DAT_25a0b0e12f0);
      FUN_25a0b0d82b0(0x19e,0x8e,&local_268,uVar30,8,1,1);
      local_110[6] = 0;
      local_188 = 0;
      local_184 = 0;
      local_f4 = u_Profit_Day_25a0b0dfa0c;
      local_ec = 0;
      local_e8 = u_Profit_Month_25a0b0dfa3c;
      local_e0 = 0;
      local_dc = u_Profit_Total_25a0b0dfa6c;
      local_d4 = 0;
      local_d0 = u_Lot_Size_25a0b0dfa9c;
      local_c8 = 0;
      local_c4 = u_Spread_25a0b0dfabc;
      local_bc = 0;
      local_b8 = u_Last_Slippage_25a0b0dfadc;
      local_b0 = 0;
      local_ac = u_Risk_25a0b0dfb0c;
      local_a4 = 0;
      local_a0 = u_Date_25a0b0dfb2c;
      local_98 = 0;
      local_94 = u_Selected_Mode_25a0b0dfb4c;
      FUN_25a0b0d9c80(DAT_25a0b0e2680);
      FUN_25a0b0c05f0(&local_268,&runtime_string_result,1,&PTR_DAT_25a0b0e1300);
      FUN_25a0b0c05f0(&local_188,&local_268,0,&PTR_DAT_25a0b0e1310);
      local_17c = 0;
      local_178 = 0;
      FUN_25a0b0d9c80(DAT_25a0b0e2688);
      FUN_25a0b0c05f0(&local_288,&runtime_string_result,1,&PTR_DAT_25a0b0e1320);
      FUN_25a0b0c05f0(&local_17c,&local_288,0,&PTR_DAT_25a0b0e1330);
      local_170 = 0;
      local_16c = 0;
      FUN_25a0b0d9c80(dVar7);
      FUN_25a0b0c05f0(&local_258,&runtime_string_result,1,&PTR_DAT_25a0b0e1340);
      FUN_25a0b0c05f0(&local_170,&local_258,0,&PTR_DAT_25a0b0e1350);
      local_164 = 0;
      local_160 = 0;
      MT5_DoubleToString((void *)0x25a0930b4c8,arg_1,2);
      FUN_25a0b0c05f0(&local_1a8,&runtime_string_result,1,&PTR_DAT_25a0b0e1360);
      FUN_25a0b0c05f0(&local_218,&local_1a8,0,&PTR_DAT_25a0b0e1370);
      lVar15 = local_1e8;
      uVar25 = DAT_25a0b0dfb78;
      uVar14 = (ulonglong)DAT_25a0b0dfb78;
      if ((uVar14 == 0) && (local_214 != 0)) {
LAB_25a0b0c79ed:
        puVar18 = &local_164;
        ppuVar27 = &PTR_DAT_25a0b0e1380;
        uVar25 = 0;
        FUN_25a0b0c05f0(puVar18,&local_218,0,&PTR_DAT_25a0b0e1380);
        local_158 = 0;
        local_154 = 0;
        MT5_IntegerToString((void *)0x25a0930b4c8,(longlong)(int)lVar15,0,
                            (int)CONCAT62((int6)((ulonglong)ppuVar27 >> 0x10),0x20));
        FUN_25a0b0c05f0(&local_198,&runtime_string_result,1,&PTR_DAT_25a0b0e1390);
        FUN_25a0b0c05f0(&local_208,&local_198,0);
        uVar21 = DAT_25a0b0df818;
        uVar14 = (ulonglong)DAT_25a0b0df818;
        if ((uVar14 != 0) || (local_204 == 0)) {
          if (local_204 != 0) {
            uVar25 = *(uint *)(local_204 + -4);
          }
          uVar19 = DAT_25a0b0df818 + uVar25;
          cVar11 = FUN_25a0b0c0060(&local_208);
          if (cVar11 == '\0') goto LAB_25a0b0c8782;
          if (uVar14 != 0) {
            lVar2 = local_204 + (ulonglong)uVar25 * 2;
            if ((uVar21 < 0x10) || (lVar2 - 0x25a0b0df81cU < 0x20)) {
              uVar26 = 0;
            }
            else {
              uVar29 = 0;
              uVar26 = (ulonglong)(uVar21 & 0xfffffff8);
              do {
                uVar8 = *(undefined8 *)(uVar29 + 0x25a0b0df824);
                *(undefined8 *)(lVar2 + uVar29) =
                     *(undefined8 *)((longlong)&DAT_25a0b0df81c + uVar29);
                ((undefined8 *)(lVar2 + uVar29))[1] = uVar8;
                uVar29 = uVar29 + 0x10;
              } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar29);
              if (uVar26 == uVar14) goto LAB_25a0b0c7b62;
            }
            do {
              *(undefined2 *)(lVar2 + uVar26 * 2) = (&DAT_25a0b0df81c)[uVar26];
              uVar26 = uVar26 + 1;
            } while (uVar14 != uVar26);
          }
LAB_25a0b0c7b62:
          *(uint *)(local_204 + -4) = uVar19;
          *(undefined2 *)(local_204 + (ulonglong)uVar19 * 2) = 0;
        }
        FUN_25a0b0c05f0(&local_158,&local_208,0,&PTR_DAT_25a0b0e13b0);
        local_14c = 0;
        local_148 = 0;
        FUN_25a0b0c05f0(&local_14c,&local_238,0,&PTR_DAT_25a0b0e13c0);
        local_140 = 0;
        local_13c = 0;
        FUN_25a0b0c05f0(&local_140,&local_228,0,&PTR_DAT_25a0b0e13d0);
        local_134 = 0;
        local_130 = 0;
        FUN_25a0b0c05f0(&local_134,&local_1f8,0,&PTR_DAT_25a0b0e13e0);
        local_128 = 0;
        local_124 = 0;
        FUN_25a0b0c05f0(&local_128,&local_248,0,&PTR_DAT_25a0b0e13f0);
        iVar12 = 0x4f4feb;
        if (0.0 <= DAT_25a0b0e2680) {
          iVar12 = 0x70cc34;
        }
        iVar13 = 0x4f4feb;
        if (0.0 <= DAT_25a0b0e2688) {
          iVar13 = 0x70cc34;
        }
        uVar30 = 0x4f4feb;
        if (0.0 <= dVar7) {
          uVar30 = 0x70cc34;
        }
        local_110[0] = 0xf4ebee;
        local_110[1] = 0x37b1ed;
        if ((int)lVar15 <= state_v_223c8) {
          local_110[1] = 0x70cc34;
        }
        local_110[2] = local_1c0;
        local_110[3] = local_1bc;
        local_110[4] = 0xf4ebee;
        local_110[5] = 0xf4ebee;
        local_11c = iVar12;
        local_118._0_4_ = iVar13;
        local_118._4_4_ = uVar30;
        FUN_25a0b0d9ab0(0x2c,0xbe,0x1b0,0x2b,0x10080a,0x692649);
        FUN_25a0b0d92f0(0x41,0xd3,5,0xff5cb8);
        FUN_25a0b0d92f0(0x41,0xd3,2,0xd0608);
        FUN_25a0b0c05f0(&local_268,local_110 + 6,0,&PTR_DAT_25a0b0e1400);
        FUN_25a0b0d82b0(0x54,0xc9,&local_268,0xf4ebee,10,1,0);
        FUN_25a0b0c05f0(&local_268,&local_188,0,&PTR_DAT_25a0b0e1410);
        FUN_25a0b0d82b0(0x1ca,0xc9,&local_268,iVar12,10,1,2);
        FUN_25a0b0d9ab0(0x2c,0xed,0x1b0,0x2b,0xd0608,0x692649);
        FUN_25a0b0d92f0(0x41,0x102,5,0xff5cb8);
        FUN_25a0b0d92f0(0x41,0x102,2,0xd0608);
        FUN_25a0b0c05f0(&local_268,&local_ec,0,&PTR_DAT_25a0b0e1400);
        FUN_25a0b0d82b0(0x54,0xf8,&local_268,0xf4ebee,10,1,0);
        FUN_25a0b0c05f0(&local_268,&local_17c,0,&PTR_DAT_25a0b0e1410);
        FUN_25a0b0d82b0(0x1ca,0xf8,&local_268,iVar13,10,1,2);
        FUN_25a0b0d9ab0(0x2c,0x11c,0x1b0,0x2b,0x10080a,0x692649);
        FUN_25a0b0d92f0(0x41,0x131,5,0xff5cb8);
        FUN_25a0b0d92f0(0x41,0x131,2,0xd0608);
        FUN_25a0b0c05f0(&local_268,&local_e0,0,&PTR_DAT_25a0b0e1400);
        FUN_25a0b0d82b0(0x54,0x127,&local_268,0xf4ebee,10,1,0);
        FUN_25a0b0c05f0(&local_268,&local_170,0,&PTR_DAT_25a0b0e1410);
        FUN_25a0b0d82b0(0x1ca,0x127,&local_268,uVar30,10,1,2);
        puVar24 = &local_d4;
        iVar12 = 0x14b;
        uVar14 = 3;
        do {
          uVar25 = 0x692649;
          uVar30 = 0xd0608;
          if ((uVar14 & 1) == 0) {
            uVar30 = 0x10080a;
          }
          FUN_25a0b0d9ab0(0x2c,iVar12,0x1b0,0x2b,uVar30,0x692649);
          FUN_25a0b0d92f0(0x41,iVar12 + 0x15,5,0xff5cb8);
          FUN_25a0b0d92f0(0x41,iVar12 + 0x15,2,0xd0608);
          FUN_25a0b0c05f0(&local_268,puVar24,0,&PTR_DAT_25a0b0e1400);
          FUN_25a0b0d82b0(0x54,iVar12 + 0xb,&local_268,0xf4ebee,10,uVar25 & 0xffffff00,0);
          iVar13 = (&local_11c)[uVar14];
          FUN_25a0b0c05f0(&local_268,puVar18,0,&PTR_DAT_25a0b0e1410);
          FUN_25a0b0d82b0(0x1ca,iVar12 + 0xb,&local_268,iVar13,9,uVar14 == 6,2);
          uVar14 = uVar14 + 1;
          puVar24 = puVar24 + 3;
          puVar18 = puVar18 + 3;
          iVar12 = iVar12 + 0x2f;
        } while (uVar14 != 9);
        FUN_25a0b0d8720(0x2a,0x26e,0x1de,0x26e,0xbe307a,1);
        FUN_25a0b0d8720(0x3a,0x280,0x44,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x1c4,0x280,0x1ce,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x49,0x280,0x53,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x1b5,0x280,0x1bf,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x58,0x280,0x62,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x1a6,0x280,0x1b0,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x67,0x280,0x71,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x197,0x280,0x1a1,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x76,0x280,0x80,0x274,0xff5cb8,3);
        FUN_25a0b0d8720(0x188,0x280,0x192,0x274,0xff5cb8,3);
        FUN_25a0b0d92f0(0x104,0x27c,0x13,0xbe307a);
        FUN_25a0b0d92f0(0x104,0x27c,0xb,0xff5cb8);
        FUN_25a0b0d92f0(0x104,0x27c,3,0xf4ebee);
        FUN_25a0b0d8720(0xf4,0x27c,0x114,0x27c,0xff5cb8,1);
        FUN_25a0b0d8720(0x104,0x26c,0x104,0x28c,0xff5cb8,1);
        pMVar20 = &string_ref_25a0b0dfc10;
        if (BrokerType == 1) {
          pMVar20 = &string_ref_25a0b0dfbc8;
        }
        FUN_25a0b0c05f0(&local_268,pMVar20,0,&PTR_DAT_25a0b0e1420);
        FUN_25a0b0d82b0(0x104,0x28f,&local_268,0x9b858f,7,1,1);
        if ((DAT_25a0b0e4cc4 != 0) &&
           (cVar11 = (*(code *)&MT5_ResourceCreate)
                               (0x25a0930b4c8,&DAT_25a0b0e4cc0,&DAT_25a0b0e4cf0,DAT_25a0b0e4ccc,
                                DAT_25a0b0e4cd0,0,0,0,DAT_25a0b0e4cd4), cVar11 != '\0')) {
          (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,DAT_25a0b0e4ca8);
        }
        lVar15 = -0x6c;
        do {
          if ((((*(int *)((longlong)&local_11c + lVar15) != 0) &&
               (lVar2 = *(longlong *)((longlong)&local_118 + lVar15), lVar2 != 0)) &&
              ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
            piVar1 = (int *)(lVar2 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
            }
          }
          *(undefined8 *)((longlong)&local_118 + lVar15) = 0;
          *(undefined4 *)((longlong)&local_11c + lVar15) = 0;
          lVar15 = lVar15 + 0xc;
        } while (lVar15 != 0);
        lVar15 = -0x6c;
        do {
          if (((*(int *)((longlong)&iStack_8c + lVar15) != 0) &&
              (lVar2 = *(longlong *)(local_88 + lVar15), lVar2 != 0)) &&
             (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
            piVar1 = (int *)(lVar2 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
            }
          }
          *(undefined8 *)(local_88 + lVar15) = 0;
          *(undefined4 *)((longlong)&iStack_8c + lVar15) = 0;
          lVar15 = lVar15 + 0xc;
        } while (lVar15 != 0);
        FUN_25a0b0c0000(&local_1e0);
        FUN_25a0b0c0000(&local_1d0);
        FUN_25a0b0c0000(&local_1f8);
        FUN_25a0b0c0000(&local_248);
        FUN_25a0b0c0000(&local_238);
        FUN_25a0b0c0000(&local_228);
LAB_25a0b0c85d1:
        FUN_25a0b0c0000(&local_268);
        FUN_25a0b0c0000(&local_288);
        FUN_25a0b0c0000(&local_258);
        FUN_25a0b0c0000(&local_1a8);
        FUN_25a0b0c0000(&local_218);
        FUN_25a0b0c0000(&local_198);
        FUN_25a0b0c0000(&local_208);
        return;
      }
      uVar21 = 0;
      if (local_214 != 0) {
        uVar21 = *(uint *)(local_214 + -4);
      }
      uVar22 = DAT_25a0b0dfb78 + uVar21;
      uVar19 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar19 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar19)))) {
        uVar19 = 0x7ffffffe;
      }
      cVar11 = FUN_25a0b0c0060(&local_218,uVar19);
      if (cVar11 != '\0') {
        if (uVar14 != 0) {
          lVar2 = local_214 + (ulonglong)uVar21 * 2;
          if (uVar25 < 0x10) {
            uVar26 = 0;
          }
          else if (lVar2 - 0x25a0b0dfb7cU < 0x20) {
            uVar26 = 0;
          }
          else {
            uVar29 = 0;
            uVar26 = (ulonglong)(uVar25 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)((longlong)u_lots_25a0b0dfb7e + uVar29 + 6);
              *(undefined8 *)(lVar2 + uVar29) = *(undefined8 *)((longlong)&DAT_25a0b0dfb7c + uVar29)
              ;
              ((undefined8 *)(lVar2 + uVar29))[1] = uVar8;
              uVar29 = uVar29 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar29);
            if (uVar26 == uVar14) goto LAB_25a0b0c79e2;
          }
          do {
            *(undefined2 *)(lVar2 + uVar26 * 2) = (&DAT_25a0b0dfb7c)[uVar26];
            uVar26 = uVar26 + 1;
          } while (uVar14 != uVar26);
        }
LAB_25a0b0c79e2:
        *(uint *)(local_214 + -4) = uVar22;
        *(undefined2 *)(local_214 + (ulonglong)uVar22 * 2) = 0;
        goto LAB_25a0b0c79ed;
      }
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2e0ad5000001f9);
LAB_25a0b0c8782:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x4e0ad5000001f9);
    }
    else {
      uVar25 = 0;
      MT5_DoubleToString((void *)0x25a0930b4c8,DAT_25a0b0e26b0,0);
      FUN_25a0b0c05f0(&local_268,&runtime_string_result,1,&PTR_DAT_25a0b0e1200);
      FUN_25a0b0c05f0(&local_288,&local_268,0,&PTR_DAT_25a0b0e1210);
      uVar21 = DAT_25a0b0df818;
      uVar14 = (ulonglong)DAT_25a0b0df818;
      if ((uVar14 == 0) && (local_284 != 0)) {
LAB_25a0b0c69fd:
        FUN_25a0b0c05f0(&local_238,&local_288,0,&PTR_DAT_25a0b0e1220);
        uVar17 = 0x4f4feb;
        if ((double)((ulonglong)DAT_25a0b0e26b0 & _DAT_25a0b0dbaf0) <= DAT_25a0b0dbb00) {
          uVar17 = 0x37b1ed;
        }
        uVar23 = 0x70cc34;
        if (DAT_25a0b0dbb08 < (double)((ulonglong)DAT_25a0b0e26b0 & _DAT_25a0b0dbaf0)) {
          uVar23 = uVar17;
        }
        goto LAB_25a0b0c6a65;
      }
      if (local_284 != 0) {
        uVar25 = *(uint *)(local_284 + -4);
      }
      uVar22 = DAT_25a0b0df818 + uVar25;
      uVar19 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar19 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar19)))) {
        uVar19 = 0x7ffffffe;
      }
      cVar11 = FUN_25a0b0c0060(&local_288,uVar19);
      if (cVar11 != '\0') {
        if (uVar14 != 0) {
          lVar15 = local_284 + (ulonglong)uVar25 * 2;
          if (uVar21 < 0x10) {
            uVar26 = 0;
          }
          else if (lVar15 - 0x25a0b0df81cU < 0x20) {
            uVar26 = 0;
          }
          else {
            uVar29 = 0;
            uVar26 = (ulonglong)(uVar21 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar29 + 0x25a0b0df824);
              *(undefined8 *)(lVar15 + uVar29) =
                   *(undefined8 *)((longlong)&DAT_25a0b0df81c + uVar29);
              ((undefined8 *)(lVar15 + uVar29))[1] = uVar8;
              uVar29 = uVar29 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar29);
            if (uVar26 == uVar14) goto LAB_25a0b0c69f2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar26 * 2) = (&DAT_25a0b0df81c)[uVar26];
            uVar26 = uVar26 + 1;
          } while (uVar14 != uVar26);
        }
LAB_25a0b0c69f2:
        *(uint *)(local_284 + -4) = uVar22;
        *(undefined2 *)(local_284 + (ulonglong)uVar22 * 2) = 0;
        goto LAB_25a0b0c69fd;
      }
    }
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x330a96000001f9);
  }
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x380a8e000001f9);
LAB_25a0b0c87e2:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x190a8e000001f9);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



/* Address: 25a0b0c8810 */

void FUN_25a0b0c8810(void)

{
  int iVar1;
  
  if ((((UseNewsFilter) && ((DAT_25a0b0e46ea & 1) != 0)) && (DAT_25a0b0e258f != '\0')) &&
     (DAT_25a0b0e258c == '\0')) {
    FUN_25a0b0d7ee0(&string_ref_25a0b0e46f0,0x14,&string_ref_25a0b0df068,0x4f4feb,0xb);
    FUN_25a0b0d7ee0(&string_ref_25a0b0e4700,0x2a,&string_ref_25a0b0df160,0x37b1ed,9);
    (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,0);
    return;
  }
  iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0e46f0);
  if (-1 < iVar1) {
    MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e46f0);
  }
  iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0e4700);
  if (-1 < iVar1) {
    MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e4700);
    return;
  }
  return;
}



/* Address: 25a0b0c8970 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0c8970(void)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  wchar16 wVar3;
  wchar16 wVar4;
  double dVar5;
  undefined8 uVar6;
  double dVar7;
  double dVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong lVar15;
  code *pcVar16;
  int *piVar17;
  undefined7 uVar18;
  int operation;
  uint uVar19;
  ulonglong uVar20;
  uint uVar21;
  uint uVar22;
  int argument_count;
  ulonglong uVar23;
  longlong lVar24;
  code *pcVar25;
  ulonglong uVar26;
  uint uVar27;
  bool bVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  MqlStringAnalysisView *pMVar32;
  uint in_stack_fffffffffffffea0;
  undefined8 in_stack_fffffffffffffea8;
  uint in_stack_fffffffffffffeb0;
  undefined8 in_stack_fffffffffffffeb8;
  undefined4 local_130;
  wchar16 *local_12c;
  undefined4 local_120;
  longlong local_11c;
  int local_110;
  int local_10c;
  longlong local_108;
  longlong local_100;
  ulonglong local_f8;
  MqlStringAnalysisView local_f0;
  int local_e4;
  int local_d8;
  int local_cc;
  double local_c8;
  longlong local_c0;
  
  iVar11 = (int)in_stack_fffffffffffffeb8;
  iVar10 = (int)in_stack_fffffffffffffea8;
  if (DAT_25a0b0e2590 != '\x01') {
    return;
  }
  uVar14 = (ulonglong)DAT_25a0b0e4920;
  if (0 < (int)DAT_25a0b0e4920) {
    if (DAT_25a0b0e258c == '\0') {
      uVar13 = (ulonglong)(DAT_25a0b0e4920 - 1);
      pcVar25 = (code *)(&DAT_25a0b0e475c + uVar13 * 0x20);
      uVar26 = uVar14;
      do {
        if (uVar14 - 0x11 < 0xfffffffffffffff0) goto LAB_25a0b0ca725;
        uVar1 = uVar26 - 1;
        lVar12 = uVar1 * 0x20;
        *(int *)(&DAT_25a0b0e473c + lVar12) = *(int *)(&DAT_25a0b0e473c + lVar12) + 1;
        cVar9 = FUN_25a0b0ce3c0((&DAT_25a0b0e4720)[uVar1 * 4],
                                *(undefined8 *)(&DAT_25a0b0e472c + lVar12),
                                *(undefined4 *)(&DAT_25a0b0e4728 + lVar12));
        iVar11 = (int)in_stack_fffffffffffffeb8;
        iVar10 = (int)in_stack_fffffffffffffea8;
        if (((cVar9 != '\0') ||
            (uVar22 = DAT_25a0b0e4920, 200 < *(int *)(&DAT_25a0b0e473c + lVar12))) &&
           (uVar22 = DAT_25a0b0e4920 - 1, (longlong)uVar26 <= (longlong)(int)uVar22)) {
          uVar20 = uVar26 & 0xffffffff;
          pcVar16 = pcVar25;
          uVar23 = uVar13;
          do {
            uVar27 = (uint)uVar20;
            if (0xf < uVar27) {
LAB_25a0b0ca6d7:
              (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2807cb000001f6);
              goto LAB_25a0b0ca6f7;
            }
            if (0xf < uVar23) {
              (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1807cb000001f6);
              goto LAB_25a0b0ca6d7;
            }
            uVar23 = uVar23 + 1;
            *(undefined8 *)(pcVar16 + -0x3c) = *(undefined8 *)(pcVar16 + -0x1c);
            *(undefined4 *)(pcVar16 + -0x34) = *(undefined4 *)(pcVar16 + -0x14);
            *(undefined8 *)(pcVar16 + -0x30) = *(undefined8 *)(pcVar16 + -0x10);
            *(undefined8 *)(pcVar16 + -0x28) = *(undefined8 *)(pcVar16 + -8);
            *(undefined4 *)(pcVar16 + -0x20) = *(undefined4 *)pcVar16;
            pcVar16 = pcVar16 + 0x20;
            uVar20 = (ulonglong)(uVar27 + 1);
          } while (uVar27 < uVar22);
        }
        DAT_25a0b0e4920 = uVar22;
        uVar13 = uVar13 - 1;
        pcVar25 = pcVar25 + -0x20;
        bVar28 = 1 < (longlong)uVar26;
        uVar26 = uVar1;
      } while (bVar28);
    }
    else {
      DAT_25a0b0e4920 = 0;
    }
  }
  lVar12 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1e);
  if (lVar12 == 0) {
    return;
  }
  if (DAT_25a0b0e236a == '\x01') {
    lVar12 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
    MT5_TimeToStruct((void *)0x25a0930b4c8,lVar12,&local_f0);
    if (local_d8 == 1) {
      if ((DAT_25a0b0e26b8 == 1) && (DAT_25a0b0e26b8 = 0, DAT_25a0b0e258f != '\0')) {
        operation = 2;
        argument_count = 1;
        pMVar32 = &string_ref_25a0b0de3e8;
LAB_25a0b0c8ca2:
        MT5_Dispatch((void *)0x25a0930b4c8,operation,argument_count,0x590008,pMVar32,
                     in_stack_fffffffffffffea0,iVar10,in_stack_fffffffffffffeb0,iVar11);
      }
    }
    else if (((local_d8 == 5) && ((DAT_25a0b0e26b8 & 1) == 0)) &&
            (iVar11 = (BrokerType != 1) + 0x11 + (uint)(BrokerType != 1), iVar11 <= local_e4)) {
      iVar10 = FUN_25a0b0cadc0(1);
      DAT_25a0b0e26b8 = 1;
      if (DAT_25a0b0e258f != '\0') {
        operation = 0xd;
        argument_count = 3;
        in_stack_fffffffffffffeb0 = 0x520004;
        in_stack_fffffffffffffea0 = 0x520004;
        pMVar32 = &string_ref_25a0b0de4c0;
        goto LAB_25a0b0c8ca2;
      }
    }
  }
  if (DAT_25a0b0e258c == '\0') {
    if ((((UseHolidayFilter != false) && (cVar9 = FUN_25a0b0cab80(), cVar9 != '\0')) &&
        (lVar12 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0),
        0x1d < lVar12 - DAT_25a0b0e4718)) &&
       ((DAT_25a0b0e4718 = lVar12, iVar10 = FUN_25a0b0cadc0(0x25a0b0e4701), 0 < iVar10 &&
        (DAT_25a0b0e258f != '\0')))) {
      MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0de840,0x520004,iVar10,
                   0x520004,0);
    }
    local_f0.opaque = 0;
    local_120 = 0;
    local_130 = 0;
    local_f0.text = (wchar16 *)0x0;
    local_11c = 0;
    local_12c = (wchar16 *)0x0;
    if ((UseNewsFilter != false) && (DAT_25a0b0e258c == '\0')) {
      lVar15 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      lVar12 = 0x3840;
      if (DAT_25a0b0e26cd == '\0') {
        lVar12 = 0;
      }
      if ((DAT_25a0b0e26d0 == 0) || (lVar12 <= lVar15 - DAT_25a0b0e26d0)) {
        FUN_25a0b0c3000();
      }
      FUN_25a0b0c8810();
      cVar9 = FUN_25a0b0cb750();
      if ((((cVar9 != '\0') && (0x1d < lVar15 - DAT_25a0b0e4710)) &&
          (DAT_25a0b0e4710 = lVar15, iVar10 = FUN_25a0b0cadc0(0), 0 < iVar10)) &&
         (DAT_25a0b0e258f != '\0')) {
        local_130 = 0;
        local_12c = (wchar16 *)0x0;
        if ((int)DAT_25a0b0e46e4 < 0) {
          pMVar32 = &string_ref_25a0b0df1a0;
          goto LAB_25a0b0c915c;
        }
        if (0xff < DAT_25a0b0e46e4) goto LAB_25a0b0ca7c5;
        uVar22 = 0;
        FUN_25a0b0c05f0(&local_120,&DAT_25a0b0e3ae0 + (ulonglong)DAT_25a0b0e46e4 * 3,0,
                        &PTR_DAT_25a0b0e0ee0);
        uVar27 = DAT_25a0b0de874;
        uVar14 = (ulonglong)DAT_25a0b0de874;
        if ((uVar14 != 0) || (local_11c == 0)) {
          if (local_11c != 0) {
            uVar22 = *(uint *)(local_11c + -4);
          }
          uVar21 = DAT_25a0b0de874 + uVar22;
          uVar19 = 0x104;
          if ((0x103 < uVar21) &&
             ((0x7ffffffd < uVar21 || (uVar19 = (uVar21 >> 2) + uVar21, 0x7ffffffd < uVar19)))) {
            uVar19 = 0x7ffffffe;
          }
          cVar9 = FUN_25a0b0c0060(&local_120,uVar19);
          if (cVar9 != '\0') {
            if (uVar14 != 0) {
              lVar12 = local_11c + (ulonglong)uVar22 * 2;
              if (uVar27 < 0x10) {
                uVar26 = 0;
              }
              else if (lVar12 - 0x25a0b0de878U < 0x20) {
                uVar26 = 0;
              }
              else {
                uVar13 = 0;
                uVar26 = (ulonglong)(uVar27 & 0xfffffff8);
                do {
                  uVar6 = *(undefined8 *)(uVar13 + 0x25a0b0de880);
                  *(undefined8 *)(lVar12 + uVar13) =
                       *(undefined8 *)((longlong)&DAT_25a0b0de878 + uVar13);
                  ((undefined8 *)(lVar12 + uVar13))[1] = uVar6;
                  uVar13 = uVar13 + 0x10;
                } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar13);
                if (uVar26 == uVar14) goto LAB_25a0b0c901d;
              }
              do {
                *(undefined2 *)(lVar12 + uVar26 * 2) = (&DAT_25a0b0de878)[uVar26];
                uVar26 = uVar26 + 1;
              } while (uVar14 != uVar26);
            }
LAB_25a0b0c901d:
            *(uint *)(local_11c + -4) = uVar21;
            *(undefined2 *)(local_11c + (ulonglong)uVar21 * 2) = 0;
            goto LAB_25a0b0c9028;
          }
          goto LAB_25a0b0ca805;
        }
LAB_25a0b0c9028:
        uVar14 = (ulonglong)DAT_25a0b0e46e4;
        if (0xff < uVar14) goto LAB_25a0b0ca7e5;
        pMVar32 = &local_f0;
        FUN_25a0b0c05f0(pMVar32,&local_120,0);
        lVar12 = *(longlong *)((longlong)&DAT_25a0b0e2ee4 + uVar14 * 0xc);
        if (lVar12 != 0) {
          uVar22 = *(uint *)(lVar12 + -4);
          uVar14 = (ulonglong)uVar22;
          if ((uVar14 != 0) || (local_f0.text == (wchar16 *)0x0)) {
            if (local_f0.text == (wchar16 *)0x0) {
              uVar27 = 0;
            }
            else {
              uVar27 = *(uint *)(local_f0.text + -2);
            }
            pMVar32 = &local_f0;
            cVar9 = FUN_25a0b0c0060(pMVar32);
            if (cVar9 == '\0') goto LAB_25a0b0ca845;
            if (uVar14 != 0) {
              if (uVar22 < 0x10) {
                uVar26 = 0;
              }
              else if ((longlong)local_f0.text + ((ulonglong)uVar27 * 2 - lVar12) < 0x20) {
                uVar26 = 0;
              }
              else {
                uVar13 = 0;
                uVar26 = (ulonglong)(uVar22 & 0xfffffff8);
                do {
                  uVar6 = ((undefined8 *)(lVar12 + uVar13))[1];
                  puVar2 = (undefined8 *)((longlong)local_f0.text + uVar13 + (ulonglong)uVar27 * 2);
                  *puVar2 = *(undefined8 *)(lVar12 + uVar13);
                  puVar2[1] = uVar6;
                  uVar13 = uVar13 + 0x10;
                } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar13);
                if (uVar26 == uVar14) goto LAB_25a0b0c9151;
              }
              do {
                local_f0.text[uVar27 + uVar26] = *(wchar16 *)(lVar12 + uVar26 * 2);
                uVar26 = uVar26 + 1;
              } while (uVar14 != uVar26);
            }
LAB_25a0b0c9151:
            *(uint *)(local_f0.text + -2) = uVar22 + uVar27;
            local_f0.text[uVar22 + uVar27] = L'\0';
          }
        }
LAB_25a0b0c915c:
        FUN_25a0b0c05f0(&local_130,pMVar32,0,&PTR_DAT_25a0b0e0f00);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0df228,0x520004,iVar10,
                     0x590008,&local_130);
        FUN_25a0b0c0000(&local_130);
      }
    }
    FUN_25a0b0c0000(&local_120);
    FUN_25a0b0c0000(&local_f0);
  }
  if ((state_v_223a4 == true) && (iVar10 = MT5_PositionsTotal((void *)0x25a0930b4c8), 0 < iVar10)) {
    pcVar25 = MT5_PositionGetInteger;
    local_130 = 0;
    local_12c = (wchar16 *)0x0;
    local_108 = CONCAT71(local_108._1_7_,UsePropFirmDelay);
    uVar22 = DAT_25a0b0e4c80;
    if (UsePropFirmDelay != false) {
      if ((int)DAT_25a0b0e4c80 < 1) {
        uVar22 = 0;
      }
      else {
        uVar26 = 0;
        uVar14 = 0;
LAB_25a0b0c92b9:
        do {
          uVar22 = (uint)uVar14;
          iVar10 = MT5_PositionsTotal((void *)0x25a0930b4c8);
          if (-1 < iVar10 + -1) {
            if (uVar26 < 0x32) {
              do {
                iVar10 = iVar10 + -1;
                uVar13 = MT5_PositionGetTicket((void *)0x25a0930b4c8,iVar10);
                if ((uVar13 != 0) &&
                   (lVar12 = MT5_PositionGetInteger((void *)0x25a0930b4c8,0x11),
                   lVar12 == (&DAT_25a0b0e4960)[uVar26])) {
                  if (uVar26 != uVar14) {
                    if (0x31 < uVar22) goto LAB_25a0b0ca785;
                    (&DAT_25a0b0e4960)[uVar14] = lVar12;
                    (&DAT_25a0b0e4af0)[uVar14] = (&DAT_25a0b0e4af0)[uVar26];
                  }
                  uVar14 = (ulonglong)(uVar22 + 1);
                  uVar26 = uVar26 + 1;
                  uVar22 = uVar22 + 1;
                  if ((longlong)(int)DAT_25a0b0e4c80 <= (longlong)uVar26) goto LAB_25a0b0c935a;
                  goto LAB_25a0b0c92b9;
                }
              } while (0 < iVar10);
            }
            else {
              do {
                iVar10 = iVar10 + -1;
                uVar13 = MT5_PositionGetTicket((void *)0x25a0930b4c8,iVar10);
                if (uVar13 != 0) goto LAB_25a0b0ca6f7;
              } while (0 < iVar10);
            }
          }
          uVar26 = uVar26 + 1;
        } while ((longlong)uVar26 < (longlong)(int)DAT_25a0b0e4c80);
      }
    }
LAB_25a0b0c935a:
    DAT_25a0b0e4c80 = uVar22;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
    dVar31 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
    dVar7 = runtime_double_result;
    iVar10 = MT5_PositionsTotal((void *)0x25a0930b4c8);
    uVar22 = iVar10 - 1;
    if (-1 < (int)uVar22) {
      local_100 = (longlong)InpMagic;
      local_cc = PropFirmDelaySec;
      do {
        uVar14 = MT5_PositionGetTicket((void *)0x25a0930b4c8,uVar22);
        uVar27 = uVar22;
        if (uVar14 != 0) {
          local_f0.opaque = 0;
          local_120 = 0;
          local_f0.text = (wchar16 *)0x0;
          local_11c = 0;
          MT5_PositionGetString((void *)0x25a0930b4c8,0);
          local_f8 = (ulonglong)uVar22;
          FUN_25a0b0c05f0(&local_f0,&runtime_string_result,1,&PTR_DAT_25a0b0dfe18);
          FUN_25a0b0c05f0(&local_120,&local_f0,0,&PTR_DAT_25a0b0dfe28);
          FUN_25a0b0c05f0(&runtime_string_result,&local_120,1,&PTR_DAT_25a0b0dfe38);
          FUN_25a0b0c0000(&local_120);
          FUN_25a0b0c0000(&local_f0);
          FUN_25a0b0c05f0(&local_130,&runtime_string_result,1);
          uVar27 = (uint)local_f8;
          if (local_12c == _Symbol.text) {
LAB_25a0b0c9595:
            lVar12 = MT5_PositionGetInteger((void *)0x25a0930b4c8,0xc);
            if (lVar12 == local_100) {
              lVar12 = MT5_PositionGetInteger((void *)0x25a0930b4c8,0x11);
              MT5_PositionGetDouble((void *)0x25a0930b4c8,4);
              dVar29 = runtime_double_result;
              MT5_PositionGetDouble((void *)0x25a0930b4c8,6);
              dVar5 = runtime_double_result;
              MT5_PositionGetDouble((void *)0x25a0930b4c8,7);
              dVar8 = runtime_double_result;
              if ((char)local_108 == '\0') {
LAB_25a0b0c96e8:
                lVar15 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
                if ((int)lVar15 == 0) {
                  if ((state_v_22640 <= dVar7 - dVar29) &&
                     (dVar29 = dVar7 - state_v_22650, state_v_22648 + dVar5 < dVar29)) {
LAB_25a0b0c97ac:
                    local_c8 = dVar29;
                    if ((dVar29 != dVar5) || (NAN(dVar29) || NAN(dVar5))) {
                      FUN_25a0b0d7770(&local_c8);
                      dVar29 = local_c8;
                      local_c0 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
                      lVar15 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
                      lVar24 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
                      iVar10 = (int)lVar24;
                      if ((int)lVar24 < (int)lVar15) {
                        iVar10 = (int)lVar15;
                      }
                      dVar5 = (double)(iVar10 + 2) * DAT_25a0b0e2570;
                      MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
                      dVar30 = runtime_double_result;
                      MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
                      if ((int)local_c0 == 0) {
                        if ((dVar29 <= 0.0) || (dVar5 <= dVar30 - dVar29)) {
                          if (0.0 < dVar8) {
                            dVar30 = dVar8 - dVar30;
                            goto LAB_25a0b0c98ef;
                          }
                          goto LAB_25a0b0c98fa;
                        }
                      }
                      else if ((dVar29 <= 0.0) || (dVar5 <= dVar29 - runtime_double_result)) {
                        if (0.0 < dVar8) {
                          dVar30 = runtime_double_result - dVar8;
LAB_25a0b0c98ef:
                          if (dVar30 < dVar5) goto LAB_25a0b0c9400;
                        }
LAB_25a0b0c98fa:
                        cVar9 = FUN_25a0b0d2640(lVar12,dVar29,dVar8);
                        if ((cVar9 != '\0') && (DAT_25a0b0e258f != '\0')) {
                          lVar15 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
                          pMVar32 = &string_ref_25a0b0df2d8;
                          if ((int)lVar15 == 0) {
                            pMVar32 = &string_ref_25a0b0df2a8;
                          }
                          MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0df280,
                                       0x520004,(int)lVar12,0x590008,pMVar32,0x580007,dVar29);
                        }
                      }
                    }
                  }
                }
                else {
                  lVar15 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
                  if (((int)lVar15 == 1) && (state_v_22640 <= dVar29 - dVar31)) {
                    dVar29 = state_v_22650 + dVar31;
                    if (((dVar5 == 0.0) && (!NAN(dVar5))) || (dVar29 < dVar5 - state_v_22648))
                    goto LAB_25a0b0c97ac;
                  }
                }
              }
              else {
                lVar15 = MT5_PositionGetInteger((void *)0x25a0930b4c8,1);
                uVar14 = (ulonglong)DAT_25a0b0e4c80;
                if ((int)DAT_25a0b0e4c80 < 1) {
                  if (uVar14 != 0) goto LAB_25a0b0ca7a5;
                  uVar26 = 0;
LAB_25a0b0c966e:
                  uVar14 = uVar14 + 1;
                  (&DAT_25a0b0e4960)[uVar26] = lVar12;
                  (&DAT_25a0b0e4af0)[uVar26] = lVar15;
                  DAT_25a0b0e4c80 = (uint)uVar14;
                }
                else {
                  lVar24 = 0;
                  do {
                    if (lVar24 == 400) goto LAB_25a0b0ca765;
                    if (*(longlong *)((longlong)&DAT_25a0b0e4960 + lVar24) == lVar12)
                    goto LAB_25a0b0c9689;
                    lVar24 = lVar24 + 8;
                  } while (uVar14 * 8 - lVar24 != 0);
                  uVar26 = uVar14;
                  if (DAT_25a0b0e4c80 < 0x32) goto LAB_25a0b0c966e;
                }
LAB_25a0b0c9689:
                lVar15 = 0;
                do {
                  if (lVar15 == 400) goto LAB_25a0b0ca745;
                  if (*(longlong *)((longlong)&DAT_25a0b0e4960 + lVar15) == lVar12) {
                    lVar15 = *(longlong *)((longlong)&DAT_25a0b0e4af0 + lVar15);
                    if ((lVar15 != 0) &&
                       (lVar24 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0),
                       local_cc <= (int)lVar24 - (int)lVar15)) goto LAB_25a0b0c96e8;
                    break;
                  }
                  lVar15 = lVar15 + 8;
                } while (uVar14 * 8 != lVar15);
              }
            }
          }
          else if ((local_12c != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
            uVar22 = *(uint *)(local_12c + -2);
            uVar19 = *(uint *)(_Symbol.text + -2);
            uVar21 = uVar19;
            if (uVar22 < uVar19) {
              uVar21 = uVar22;
            }
            iVar10 = uVar22 - uVar19;
            if (uVar21 != 0) {
              uVar14 = 1;
              do {
                wVar3 = local_12c[uVar14 - 1];
                wVar4 = _Symbol.text[uVar14 - 1];
                if (uVar21 <= uVar14) break;
                uVar14 = uVar14 + 1;
              } while (wVar3 == wVar4);
              if (wVar3 != wVar4) {
                iVar10 = (uint)(ushort)wVar3 - (uint)(ushort)wVar4;
              }
            }
            if (iVar10 == 0) goto LAB_25a0b0c9595;
          }
        }
LAB_25a0b0c9400:
        uVar22 = uVar27 - 1;
      } while (0 < (int)uVar27);
    }
    FUN_25a0b0c0000(&local_130);
  }
  iVar10 = 0xf;
  iVar11 = 0;
  if (state_v_2236c != false) {
    iVar11 = 0xf;
  }
  lVar12 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar11,0);
  if (lVar12 == DAT_25a0b0e2568) {
    return;
  }
  local_130 = 0;
  local_12c = (wchar16 *)0x0;
  DAT_25a0b0e2620 = 0xc000000000000000;
  DAT_25a0b0e25e0 = 0;
  DAT_25a0b0e2628 = 0xc000000000000000;
  DAT_25a0b0e2568 = lVar12;
  local_100 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
  lVar12 = (longlong)state_v_223a0;
  if (state_v_2236c == false) {
    iVar10 = 0;
  }
  iVar10 = MT5_PeriodSeconds((void *)0x25a0930b4c8,iVar10);
  iVar11 = MT5_OrdersTotal((void *)0x25a0930b4c8);
  if (-1 < iVar11 + -1) {
    local_108 = iVar10 * lVar12;
    local_f8 = (ulonglong)InpMagic;
    iVar10 = iVar11 + -1;
    do {
      uVar14 = MT5_OrderGetTicket((void *)0x25a0930b4c8,iVar10);
      DAT_25a0b0e2330 = -(ulonglong)(uVar14 == 0) | uVar14;
      if (uVar14 != 0) {
        local_f0.opaque = 0;
        local_120 = 0;
        local_f0.text = (wchar16 *)0x0;
        local_11c = 0;
        MT5_OrderGetString((void *)0x25a0930b4c8,0);
        FUN_25a0b0c05f0(&local_f0,&runtime_string_result,1,&PTR_DAT_25a0b0dfd90);
        FUN_25a0b0c05f0(&local_120,&local_f0,0,&PTR_DAT_25a0b0dfda0);
        FUN_25a0b0c05f0(&runtime_string_result,&local_120,1,&PTR_DAT_25a0b0dfdb0);
        FUN_25a0b0c0000(&local_120);
        FUN_25a0b0c0000(&local_f0);
        FUN_25a0b0c05f0(&local_130,&runtime_string_result,1,&PTR_DAT_25a0b0e0bc0);
        if (local_12c == _Symbol.text) {
LAB_25a0b0c9cfb:
          uVar14 = MT5_OrderGetInteger((void *)0x25a0930b4c8,0xf);
          if ((((uVar14 == local_f8) &&
               (lVar12 = MT5_OrderGetInteger((void *)0x25a0930b4c8,2), lVar12 == 0)) &&
              (lVar12 = MT5_OrderGetInteger((void *)0x25a0930b4c8,1), uVar14 = DAT_25a0b0e2330,
              0 < lVar12)) && (local_108 <= local_100 - lVar12)) {
            if (_StopFlag_native32 == 0) {
              DAT_25a0b0e2020 = 0;
              DAT_25a0b0e2024._0_4_ = 0;
              DAT_25a0b0e2024._4_4_ = 0;
              DAT_25a0b0e202c._0_4_ = 0;
              DAT_25a0b0e202c._4_4_ = 0;
              FUN_25a0b0c0000(&DAT_25a0b0e2034);
              DAT_25a0b0e2050 = 0;
              DAT_25a0b0e2058 = 0;
              DAT_25a0b0e2060 = 0;
              uRam0000025a0b0e2068 = 0;
              _DAT_25a0b0e2070 = 0;
              _DAT_25a0b0e2078 = 0;
              DAT_25a0b0e207c._4_4_ = 0;
              DAT_25a0b0e2040 = 0;
              DAT_25a0b0e2048 = 0;
              FUN_25a0b0c0000(&DAT_25a0b0e2084);
              _DAT_25a0b0e2100 = 0;
              uRam0000025a0b0e2108 = 0;
              _DAT_25a0b0e2120 = 0;
              uRam0000025a0b0e2128 = 0;
              _DAT_25a0b0e2130 = 0;
              uRam0000025a0b0e2138 = 0;
              _DAT_25a0b0e2110 = 0;
              uRam0000025a0b0e2118 = 0;
              _DAT_25a0b0e20e0 = 0;
              uRam0000025a0b0e20e8 = 0;
              _DAT_25a0b0e20f0 = 0;
              uRam0000025a0b0e20f8 = 0;
              _DAT_25a0b0e20c0 = 0;
              uRam0000025a0b0e20c8 = 0;
              _DAT_25a0b0e20d0 = 0;
              uRam0000025a0b0e20d8 = 0;
              _DAT_25a0b0e20a0 = 0;
              uRam0000025a0b0e20a8 = 0;
              _DAT_25a0b0e20b0 = 0;
              uRam0000025a0b0e20b8 = 0;
              DAT_25a0b0e2140 = 0;
              DAT_25a0b0e2090 = 0;
              uRam0000025a0b0e2098 = 0;
              FUN_25a0b0c0000(&DAT_25a0b0e2144);
              _DAT_25a0b0e21e0 = 0;
              uRam0000025a0b0e21e8 = 0;
              _DAT_25a0b0e21d0 = 0;
              uRam0000025a0b0e21d8 = 0;
              _DAT_25a0b0e21f0 = 0;
              uRam0000025a0b0e21f8 = 0;
              _DAT_25a0b0e21c0 = 0;
              uRam0000025a0b0e21c8 = 0;
              _DAT_25a0b0e21b0 = 0;
              uRam0000025a0b0e21b8 = 0;
              _DAT_25a0b0e21a0 = 0;
              uRam0000025a0b0e21a8 = 0;
              _DAT_25a0b0e2190 = 0;
              uRam0000025a0b0e2198 = 0;
              _DAT_25a0b0e2180 = 0;
              uRam0000025a0b0e2188 = 0;
              _DAT_25a0b0e2170 = 0;
              uRam0000025a0b0e2178 = 0;
              _DAT_25a0b0e2160 = 0;
              uRam0000025a0b0e2168 = 0;
              _DAT_25a0b0e2150 = 0;
              uRam0000025a0b0e2158 = 0;
              DAT_25a0b0e2200 = 0;
              FUN_25a0b0c0000(&DAT_25a0b0e2208);
              DAT_25a0b0e2284 = 0;
              DAT_25a0b0e227c = 0;
              DAT_25a0b0e228c = 0;
              DAT_25a0b0e2274 = 0;
              DAT_25a0b0e226c = 0;
              DAT_25a0b0e2264 = 0;
              DAT_25a0b0e225c = 0;
              DAT_25a0b0e2254 = 0;
              DAT_25a0b0e224c = 0;
              DAT_25a0b0e2244 = 0;
              DAT_25a0b0e223c = 0;
              DAT_25a0b0e2234 = 0;
              DAT_25a0b0e222c = 0;
              DAT_25a0b0e2224 = 0;
              DAT_25a0b0e221c = 0;
              DAT_25a0b0e2214 = 0;
              DAT_25a0b0e2020 = 8;
              DAT_25a0b0e2024._0_4_ = (undefined4)state_v_22295;
              DAT_25a0b0e2024._4_4_ = (undefined4)((ulonglong)state_v_22295 >> 0x20);
              DAT_25a0b0e202c._0_4_ = (int)uVar14;
              iVar11 = (int)DAT_25a0b0e202c;
              DAT_25a0b0e202c._4_4_ = (undefined4)(uVar14 >> 0x20);
              cVar9 = FUN_25a0b0c0ad0(&DAT_25a0b0e2000,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
              if ((cVar9 != '\0') && (DAT_25a0b0e258f != '\0')) {
                MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0de5e0,0x520004,
                             iVar11,0x520004,state_v_223a0);
              }
            }
            else {
              MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0de160,0x590008,
                           &string_ref_25a0b0dd128);
              _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x272b);
            }
          }
        }
        else if ((local_12c != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar22 = *(uint *)(local_12c + -2);
          uVar27 = *(uint *)(_Symbol.text + -2);
          uVar19 = uVar27;
          if (uVar22 < uVar27) {
            uVar19 = uVar22;
          }
          iVar11 = uVar22 - uVar27;
          if (uVar19 != 0) {
            uVar14 = 1;
            do {
              wVar3 = local_12c[uVar14 - 1];
              wVar4 = _Symbol.text[uVar14 - 1];
              if (uVar19 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (wVar3 == wVar4);
            if (wVar3 != wVar4) {
              iVar11 = (uint)(ushort)wVar3 - (uint)(ushort)wVar4;
            }
          }
          if (iVar11 == 0) goto LAB_25a0b0c9cfb;
        }
      }
      bVar28 = 0 < iVar10;
      iVar10 = iVar10 + -1;
    } while (bVar28);
  }
  FUN_25a0b0c0000(&local_130);
  lVar12 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x4018,0);
  if (lVar12 != DAT_25a0b0e25a0) {
    DAT_25a0b0e25a0 = lVar12;
    MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x25);
    DAT_25a0b0e2594 = 0;
    DAT_25a0b0e25d8 = 0;
    DAT_25a0b0e2598 = runtime_double_result;
    FUN_25a0b0ca870();
    DAT_25a0b0e2668 = '\x01';
    if (DAT_25a0b0e258f != '\0') {
      MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0dc930);
    }
  }
  if (((ShowPanel != false) && (DAT_25a0b0e258f != '\0')) && (DAT_25a0b0e4d24 == '\x01')) {
    FUN_25a0b0ca870();
    iVar10 = 0xf;
    if (state_v_2236c == false) {
      iVar10 = 0;
    }
    lVar12 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar10,0);
    if ((DAT_25a0b0e258e == '\0') || ((DAT_25a0b0e2368 & 1) == 0)) {
      lVar15 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      bVar28 = (longlong)((ulonglong)DAT_25a0b0e2369 + 1) <= lVar15 - DAT_25a0b0e2658;
    }
    else {
      bVar28 = lVar12 != DAT_25a0b0e2660;
    }
    if ((DAT_25a0b0e2668 != '\0') || (bVar28)) {
      FUN_25a0b0c60f0();
      DAT_25a0b0e2660 = lVar12;
      DAT_25a0b0e2658 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      DAT_25a0b0e2668 = '\0';
    }
  }
  cVar9 = FUN_25a0b0ca930();
  if (cVar9 == '\0') {
    return;
  }
  cVar9 = FUN_25a0b0cab80();
  if (cVar9 != '\0') {
    FUN_25a0b0cadc0(1);
    if (DAT_25a0b0e258f == '\0') {
      return;
    }
    iVar10 = 2;
    iVar11 = 1;
    pMVar32 = &string_ref_25a0b0dc9b0;
LAB_25a0b0ca3cf:
    MT5_Dispatch((void *)0x25a0930b4c8,iVar10,iVar11,0x590008,pMVar32);
    return;
  }
  if ((UseNewsFilter != false) && (cVar9 = FUN_25a0b0cb750(), cVar9 != '\0')) {
    FUN_25a0b0cadc0(0);
    return;
  }
  if (0 < DAT_25a0b0e25d8) {
    DAT_25a0b0e25d8 = DAT_25a0b0e25d8 + -1;
    return;
  }
  iVar10 = 0x11;
  if (state_v_223c1 == false) {
    iVar10 = 0;
  }
  if (iVar10 <= DAT_25a0b0e2594) {
    return;
  }
  if ((DAT_25a0b0e26b8 & 1) != 0) {
    return;
  }
  if ((state_v_225d0 <= 0.0) || (DAT_25a0b0e2598 <= 0.0)) {
LAB_25a0b0ca52e:
    cVar9 = FUN_25a0b0cb890();
    if (cVar9 != '\0') {
      FUN_25a0b0cba40();
      piVar17 = &local_10c;
      local_10c = 0;
      local_110 = 0;
      FUN_25a0b0cbc10(piVar17,&local_110);
      iVar10 = FUN_25a0b0cc080();
      if ((state_v_223b4 != true) || (iVar10 != 0)) {
        uVar18 = (undefined7)((ulonglong)piVar17 >> 8);
        if (((local_10c == 0) &&
            ((((iVar10 < 1 & state_v_223b4) == 0 &&
              (dVar31 = (double)FUN_25a0b0cc390(), 0.0 < dVar31)) &&
             (cVar9 = FUN_25a0b0cc690(CONCAT71(uVar18,1)), cVar9 != '\0')))) &&
           (cVar9 = FUN_25a0b0cc880(), cVar9 != '\0')) {
          FUN_25a0b0cca60(dVar31);
        }
        if (((local_110 == 0) && ((iVar10 < 0 || ((state_v_223b4 & 1U) == 0)))) &&
           ((dVar31 = (double)FUN_25a0b0ccf80(), 0.0 < dVar31 &&
            ((cVar9 = FUN_25a0b0cc690(0), cVar9 != '\0' &&
             (cVar9 = FUN_25a0b0cc880(), cVar9 != '\0')))))) {
          FUN_25a0b0cd280(dVar31);
        }
      }
    }
    return;
  }
  MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x28);
  if ((DAT_25a0b0e2598 != 0.0) || (NAN(DAT_25a0b0e2598))) {
    if (state_v_225d0 <=
        ((DAT_25a0b0e2598 - runtime_double_result) / DAT_25a0b0e2598) * DAT_25a0b0dbb50) {
      if (DAT_25a0b0e258f == '\0') {
        return;
      }
      iVar10 = 0xd;
      iVar11 = 2;
      pMVar32 = &string_ref_25a0b0dca00;
      goto LAB_25a0b0ca3cf;
    }
    goto LAB_25a0b0ca52e;
  }
  goto LAB_25a0b0ca825;
LAB_25a0b0ca6f7:
  (*pcVar25)(0x25a0930b4c8,0x11);
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3e06cd000001f6);
LAB_25a0b0ca725:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1207c3000001f6);
LAB_25a0b0ca745:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1506bb000001f6);
LAB_25a0b0ca765:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1506b1000001f6);
LAB_25a0b0ca785:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2606d1000001f6);
LAB_25a0b0ca7a5:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xf06b3000001f6);
LAB_25a0b0ca7c5:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1c06a5000001f6);
LAB_25a0b0ca7e5:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3e06a5000001f6);
LAB_25a0b0ca805:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2c06a5000001f9);
LAB_25a0b0ca825:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x200348000001f7);
LAB_25a0b0ca845:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3006a5000001f9);
  pcVar25 = (code *)swi(3);
  (*pcVar25)();
  return;
}



/* Address: 25a0b0ca870 */

void FUN_25a0b0ca870(void)

{
  longlong arg_1;
  int local_28;
  int local_24;
  int local_20;
  
  arg_1 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
  MT5_TimeToStruct((void *)0x25a0930b4c8,arg_1,&local_28);
  local_20 = local_24 * 100 + local_28 * 10000 + local_20;
  if ((DAT_25a0b0e266c != 0) && (local_20 != DAT_25a0b0e266c)) {
    DAT_25a0b0e2680 = 0;
  }
  local_24 = local_28 * 100 + local_24;
  if ((DAT_25a0b0e2670 != 0) && (local_24 != DAT_25a0b0e2670)) {
    DAT_25a0b0e2688 = 0;
  }
  DAT_25a0b0e266c = local_20;
  DAT_25a0b0e2670 = local_24;
  return;
}



/* Address: 25a0b0ca930 */

ulonglong FUN_25a0b0ca930(void)

{
  double dVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong local_68;
  longlong local_60;
  undefined1 local_58 [12];
  int local_4c;
  int local_40;
  
  lVar4 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1e);
  uVar7 = 0;
  if (((int)lVar4 != 0) && ((int)lVar4 != 3)) {
    lVar4 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
    MT5_TimeToStruct((void *)0x25a0930b4c8,lVar4,local_58);
    uVar7 = 0;
    if ((local_40 != 0) && (uVar7 = 0, local_40 != 6)) {
      if (((local_40 != 1) || (0 < local_4c)) && ((local_40 != 5 || (local_4c < 0x16)))) {
        uVar6 = 0x25a0930b4c8;
        local_60 = 0;
        local_68 = 0;
        lVar4 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
        cVar2 = (*(code *)&MT5_SymbolInfoSessionTrade)
                          (0x25a0930b4c8,&DAT_25a0b0dc150,local_40,0,&local_60,&local_68);
        if ((cVar2 != '\0') && (0 < local_68)) {
          uVar6 = 0;
          lVar5 = (lVar4 / 0x15180) * 0x15180;
          uVar7 = uVar6;
          if ((local_68 + lVar5 <= lVar4) || (uVar7 = 0, lVar4 < lVar5 + local_60))
          goto LAB_25a0b0ca9cb;
        }
        uVar7 = CONCAT71((int7)(uVar6 >> 8),1);
        if (DAT_25a0b0e258c != '\0') goto LAB_25a0b0ca9cb;
        lVar4 = MT5_TerminalInfoInteger((void *)0x25a0930b4c8,8);
        if ((int)lVar4 != 0) {
          iVar3 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,4);
          if (iVar3 != 0) {
            lVar4 = MT5_AccountInfoInteger((void *)0x25a0930b4c8,0x21);
            if (lVar4 != 0) {
              MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
              dVar1 = runtime_double_result;
              MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
              uVar7 = CONCAT71(0x25a0930b4,
                               dVar1 <= runtime_double_result &
                               -(0.0 < runtime_double_result) & -(0.0 < dVar1));
              goto LAB_25a0b0ca9cb;
            }
          }
        }
      }
      uVar7 = 0;
    }
  }
LAB_25a0b0ca9cb:
  return uVar7 & 0xffffffff;
}



/* Address: 25a0b0cab80 */

undefined8 FUN_25a0b0cab80(void)

{
  longlong arg_1;
  undefined7 extraout_var;
  int local_28;
  int local_24;
  uint local_20;
  
  if (!UseHolidayFilter) {
    return 0;
  }
  arg_1 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
  MT5_TimeToStruct((void *)0x25a0930b4c8,arg_1,&local_28);
  if ((((((((local_24 != 1) || (1 < local_20 - 1)) &&
          ((local_28 != 0x7ea || ((local_24 != 1 || (local_20 != 0x13)))))) &&
         ((local_28 != 0x7eb || ((local_24 != 1 || (local_20 != 0x12)))))) &&
        (((local_28 != 0x7ea || ((local_24 != 2 || (local_20 != 0x10)))) &&
         ((local_28 != 0x7eb || ((local_24 != 2 || (local_20 != 0xf)))))))) &&
       (((((local_28 != 0x7e9 || ((local_24 != 4 || (local_20 != 0x12)))) &&
          ((local_28 != 0x7ea || ((local_24 != 4 || (local_20 != 3)))))) &&
         ((local_28 != 0x7eb || ((local_24 != 3 || (local_20 != 0x1a)))))) &&
        ((local_28 != 0x7e9 || ((local_24 != 5 || (local_20 != 0x1a)))))))) &&
      (((((local_28 != 0x7ea || ((local_24 != 5 || (local_20 != 0x19)))) &&
         ((local_28 != 0x7eb || ((local_24 != 5 || (local_20 != 0x1f)))))) &&
        (((local_24 != 6 || (1 < local_20 - 0x13)) && ((local_24 != 7 || (2 < local_20 - 3)))))) &&
       (((local_28 != 0x7e9 || ((local_24 != 9 || (local_20 != 1)))) &&
        (((local_28 != 0x7ea || ((local_24 != 9 || (local_20 != 7)))) &&
         (((local_28 != 0x7eb || ((local_24 != 9 || (local_20 != 6)))) &&
          ((local_28 != 0x7e9 || ((local_24 != 0xb || (1 < local_20 - 0x1b)))))))))))))) &&
     (((local_28 != 0x7ea || ((local_24 != 0xb || ((local_20 & 0xfffffffe) != 0x1a)))) &&
      ((local_28 != 0x7eb || ((local_24 != 0xb || (1 < local_20 - 0x19)))))))) {
    if ((local_24 != 0xc) || (local_20 != 0x1a && (local_20 & 0xfffffffe) != 0x18)) {
      return CONCAT71(extraout_var,local_20 == 0x1f && local_24 == 0xc);
    }
  }
  return CONCAT71(extraout_var,1);
}



/* Address: 25a0b0cadc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_25a0b0cadc0(char param_1)

{
  wchar16 wVar1;
  wchar16 wVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  char cVar11;
  int iVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  int iVar16;
  MqlStringAnalysisView *value_1;
  int local_d8;
  int local_d4;
  undefined4 local_d0;
  wchar16 *local_cc;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 local_b0;
  undefined8 local_ac;
  longlong local_a0;
  
  local_d0 = 0;
  local_cc = (wchar16 *)0x0;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
  dVar8 = runtime_double_result;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
  dVar9 = runtime_double_result;
  lVar13 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
  lVar14 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
  dVar6 = (double)((int)lVar13 + 2 + (int)lVar14) * DAT_25a0b0e2570;
  iVar12 = MT5_OrdersTotal((void *)0x25a0930b4c8);
  if (iVar12 + -1 < 0) {
    local_d8 = 0;
    local_d4 = 0;
  }
  else {
    local_d8 = 0;
    local_d4 = 0;
    local_a0 = (longlong)InpMagic;
    iVar12 = iVar12 + -1;
    do {
      uVar15 = MT5_OrderGetTicket((void *)0x25a0930b4c8,iVar12);
      DAT_25a0b0e2330 = -(ulonglong)(uVar15 == 0) | uVar15;
      if (uVar15 != 0) {
        local_b0 = 0;
        local_c0 = 0;
        local_ac = 0;
        uStack_bc = 0;
        uStack_b8 = 0;
        MT5_OrderGetString((void *)0x25a0930b4c8,0);
        FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,&PTR_DAT_25a0b0dfd90);
        FUN_25a0b0c05f0(&local_c0,&local_b0,0,&PTR_DAT_25a0b0dfda0);
        FUN_25a0b0c05f0(&runtime_string_result,&local_c0,1,&PTR_DAT_25a0b0dfdb0);
        FUN_25a0b0c0000(&local_c0);
        FUN_25a0b0c0000(&local_b0);
        FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0b80);
        if (local_cc == _Symbol.text) {
LAB_25a0b0cb0ac:
          lVar13 = MT5_OrderGetInteger((void *)0x25a0930b4c8,0xf);
          if (lVar13 == local_a0) {
            lVar13 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
            if ((int)lVar13 != 4) {
              lVar13 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
              if ((int)lVar13 != 5) goto LAB_25a0b0caf10;
            }
            MT5_OrderGetDouble((void *)0x25a0930b4c8,9);
            dVar10 = runtime_double_result;
            lVar13 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
            if (((int)lVar13 != 4) || (dVar6 <= dVar10 - dVar9)) {
              lVar13 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
              uVar15 = DAT_25a0b0e2330;
              if (((int)lVar13 != 5) || (dVar6 <= dVar8 - dVar10)) {
                if (_StopFlag_native32 == 0) {
                  DAT_25a0b0e2020 = 0;
                  DAT_25a0b0e2024._0_4_ = 0;
                  DAT_25a0b0e2024._4_4_ = 0;
                  DAT_25a0b0e202c._0_4_ = 0;
                  DAT_25a0b0e202c._4_4_ = 0;
                  FUN_25a0b0c0000(&DAT_25a0b0e2034);
                  DAT_25a0b0e2050 = 0;
                  DAT_25a0b0e2058 = 0;
                  DAT_25a0b0e2060 = 0;
                  uRam0000025a0b0e2068 = 0;
                  _DAT_25a0b0e2070 = 0;
                  _DAT_25a0b0e2078 = 0;
                  DAT_25a0b0e207c._4_4_ = 0;
                  DAT_25a0b0e2040 = 0;
                  DAT_25a0b0e2048 = 0;
                  FUN_25a0b0c0000(&DAT_25a0b0e2084);
                  _DAT_25a0b0e2100 = 0;
                  uRam0000025a0b0e2108 = 0;
                  _DAT_25a0b0e2120 = 0;
                  uRam0000025a0b0e2128 = 0;
                  _DAT_25a0b0e2130 = 0;
                  uRam0000025a0b0e2138 = 0;
                  _DAT_25a0b0e2110 = 0;
                  uRam0000025a0b0e2118 = 0;
                  _DAT_25a0b0e20e0 = 0;
                  uRam0000025a0b0e20e8 = 0;
                  _DAT_25a0b0e20f0 = 0;
                  uRam0000025a0b0e20f8 = 0;
                  _DAT_25a0b0e20c0 = 0;
                  uRam0000025a0b0e20c8 = 0;
                  _DAT_25a0b0e20d0 = 0;
                  uRam0000025a0b0e20d8 = 0;
                  _DAT_25a0b0e20a0 = 0;
                  uRam0000025a0b0e20a8 = 0;
                  _DAT_25a0b0e20b0 = 0;
                  uRam0000025a0b0e20b8 = 0;
                  DAT_25a0b0e2140 = 0;
                  DAT_25a0b0e2090 = 0;
                  uRam0000025a0b0e2098 = 0;
                  FUN_25a0b0c0000(&DAT_25a0b0e2144);
                  _DAT_25a0b0e21e0 = 0;
                  uRam0000025a0b0e21e8 = 0;
                  _DAT_25a0b0e21d0 = 0;
                  uRam0000025a0b0e21d8 = 0;
                  _DAT_25a0b0e21f0 = 0;
                  uRam0000025a0b0e21f8 = 0;
                  _DAT_25a0b0e21c0 = 0;
                  uRam0000025a0b0e21c8 = 0;
                  _DAT_25a0b0e21b0 = 0;
                  uRam0000025a0b0e21b8 = 0;
                  _DAT_25a0b0e21a0 = 0;
                  uRam0000025a0b0e21a8 = 0;
                  _DAT_25a0b0e2190 = 0;
                  uRam0000025a0b0e2198 = 0;
                  _DAT_25a0b0e2180 = 0;
                  uRam0000025a0b0e2188 = 0;
                  _DAT_25a0b0e2170 = 0;
                  uRam0000025a0b0e2178 = 0;
                  _DAT_25a0b0e2160 = 0;
                  uRam0000025a0b0e2168 = 0;
                  _DAT_25a0b0e2150 = 0;
                  uRam0000025a0b0e2158 = 0;
                  DAT_25a0b0e2200 = 0;
                  FUN_25a0b0c0000(&DAT_25a0b0e2208);
                  DAT_25a0b0e2284 = 0;
                  DAT_25a0b0e227c = 0;
                  DAT_25a0b0e228c = 0;
                  DAT_25a0b0e2274 = 0;
                  DAT_25a0b0e226c = 0;
                  DAT_25a0b0e2264 = 0;
                  DAT_25a0b0e225c = 0;
                  DAT_25a0b0e2254 = 0;
                  DAT_25a0b0e224c = 0;
                  DAT_25a0b0e2244 = 0;
                  DAT_25a0b0e223c = 0;
                  DAT_25a0b0e2234 = 0;
                  DAT_25a0b0e222c = 0;
                  DAT_25a0b0e2224 = 0;
                  DAT_25a0b0e221c = 0;
                  DAT_25a0b0e2214 = 0;
                  DAT_25a0b0e2020 = 8;
                  DAT_25a0b0e2024._0_4_ = (undefined4)state_v_22295;
                  DAT_25a0b0e2024._4_4_ = (undefined4)((ulonglong)state_v_22295 >> 0x20);
                  DAT_25a0b0e202c._0_4_ = (undefined4)uVar15;
                  DAT_25a0b0e202c._4_4_ = (undefined4)(uVar15 >> 0x20);
                  cVar11 = FUN_25a0b0c0ad0(&DAT_25a0b0e2000,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
                  if (cVar11 != '\0') {
                    local_d4 = local_d4 + 1;
                    goto LAB_25a0b0caf10;
                  }
                }
                else {
                  MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0de160,0x590008
                               ,&string_ref_25a0b0dd128);
                  _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x272b);
                }
                if (DAT_25a0b0e258f != '\0') {
                  local_b0 = 0;
                  local_ac = 0;
                  local_c0 = 0;
                  uStack_bc = 0;
                  uStack_b8 = 0;
                  FUN_25a0b0d1c60(&local_c0,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
                  FUN_25a0b0c05f0(&local_b0,&local_c0,0,&PTR_DAT_25a0b0dfe98);
                  FUN_25a0b0c0000(&local_c0);
                  FUN_25a0b0c05f0(&runtime_string_result,&local_b0,1,&PTR_DAT_25a0b0dfea8);
                  FUN_25a0b0c0000(&local_b0);
                  FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0b90);
                  MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0de270,0x520004
                               ,(int)DAT_25a0b0e2330,0x530014,DAT_25a0b0e2110,0x590008,&local_d0);
                }
                goto LAB_25a0b0caf10;
              }
            }
            local_d8 = local_d8 + 1;
          }
        }
        else if ((local_cc != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar3 = *(uint *)(local_cc + -2);
          uVar4 = *(uint *)(_Symbol.text + -2);
          uVar7 = uVar4;
          if (uVar3 < uVar4) {
            uVar7 = uVar3;
          }
          iVar16 = uVar3 - uVar4;
          if (uVar7 != 0) {
            uVar15 = 1;
            do {
              wVar1 = local_cc[uVar15 - 1];
              wVar2 = _Symbol.text[uVar15 - 1];
              if (uVar7 <= uVar15) break;
              uVar15 = uVar15 + 1;
            } while (wVar1 == wVar2);
            if (wVar1 != wVar2) {
              iVar16 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
            }
          }
          if (iVar16 == 0) goto LAB_25a0b0cb0ac;
        }
      }
LAB_25a0b0caf10:
      bVar5 = 0 < iVar12;
      iVar12 = iVar12 + -1;
    } while (bVar5);
  }
  if ((0 < local_d8 || 0 < local_d4) && (DAT_25a0b0e258f != '\0')) {
    value_1 = &string_ref_25a0b0de318;
    if (param_1 == '\0') {
      value_1 = &string_ref_25a0b0de360;
    }
    MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0de2e0,0x590008,value_1,
                 0x520004,local_d4,0x520004,local_d8);
  }
  FUN_25a0b0c0000(&local_d0);
  return local_d4;
}



/* Address: 25a0b0cb750 */

ulonglong FUN_25a0b0cb750(void)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  
  DAT_25a0b0e46e4 = 0xffffffff;
  uVar6 = 0;
  if ((UseNewsFilter) && (DAT_25a0b0e258c == '\0')) {
    uVar6 = 0;
    if ((DAT_25a0b0e46e8 == '\x01') && (uVar6 = 0, 0 < (int)DAT_25a0b0e46e0)) {
      uVar6 = 0;
      lVar3 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
      uVar4 = NewsStopBeforeMin;
      if (99999 < NewsStopBeforeMin) {
        uVar4 = 100000;
      }
      uVar5 = (ulonglong)uVar4;
      if ((int)uVar4 < 1) {
        uVar5 = 0;
      }
      uVar4 = 100000;
      if (NewsStopAfterMin < 100000) {
        uVar4 = NewsStopAfterMin;
      }
      uVar7 = (ulonglong)uVar4;
      if ((int)uVar4 < 1) {
        uVar7 = 0;
      }
      if (0 < (int)DAT_25a0b0e46e0) {
        plVar9 = &DAT_25a0b0e26e0;
        uVar8 = 0;
        do {
          if (uVar8 == 0x100) {
            (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x200683000001f6);
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          lVar1 = *plVar9 + uVar5 * -0x3c;
          if ((lVar1 <= lVar3) && (lVar3 <= (longlong)(*plVar9 + uVar7 * 0x3c))) {
            uVar6 = CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
            DAT_25a0b0e46e4 = (undefined4)uVar8;
            goto LAB_25a0b0cb863;
          }
          uVar8 = uVar8 + 1;
          plVar9 = plVar9 + 1;
        } while (DAT_25a0b0e46e0 != uVar8);
        uVar6 = 0;
      }
    }
  }
LAB_25a0b0cb863:
  return uVar6 & 0xffffffff;
}



/* Address: 25a0b0cb890 */

undefined8 FUN_25a0b0cb890(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_25a0b0e23cc == -1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    iVar1 = MT5_CopyBuffer((void *)0x25a0930b4c8,DAT_25a0b0e23cc,0,0,5,&DAT_25a0b0e23f0);
    if (4 < iVar1) {
      if (state_v_223b4 == true) {
        if (DAT_25a0b0e23d0 == -1) {
          return 0;
        }
        if (DAT_25a0b0e23d4 == -1) {
          return 0;
        }
        if (DAT_25a0b0e23d8 == -1) {
          return 0;
        }
        if (DAT_25a0b0e23dc == -1) {
          return 0;
        }
        iVar1 = MT5_CopyBuffer((void *)0x25a0930b4c8,DAT_25a0b0e23d0,0,0,5,&DAT_25a0b0e2430);
        if (iVar1 < 5) {
          return 0;
        }
        iVar1 = MT5_CopyBuffer((void *)0x25a0930b4c8,DAT_25a0b0e23d4,0,0,5,&DAT_25a0b0e2470);
        if (iVar1 < 5) {
          return 0;
        }
        iVar1 = MT5_CopyBuffer((void *)0x25a0930b4c8,DAT_25a0b0e23d8,0,0,3,&DAT_25a0b0e24b0);
        if (iVar1 < 3) {
          return 0;
        }
        iVar1 = MT5_CopyBuffer((void *)0x25a0930b4c8,DAT_25a0b0e23dc,0,0,3,&DAT_25a0b0e24f0);
        if (iVar1 < 3) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* Address: 25a0b0cba40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0cba40(void)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  if (state_v_2236c) {
    iVar2 = 0xf;
  }
  lVar1 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,0);
  if (lVar1 != DAT_25a0b0e25e0) {
    iVar2 = 0;
    if (state_v_2236c != false) {
      iVar2 = 0xf;
    }
    DAT_25a0b0e25e0 = lVar1;
    MT5_iOpen((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,1);
    iVar2 = 0;
    if (state_v_2236c != false) {
      iVar2 = 0xf;
    }
    DAT_25a0b0e25e8 = runtime_double_result;
    MT5_iClose((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,1);
    iVar2 = 0;
    if (state_v_2236c != false) {
      iVar2 = 0xf;
    }
    DAT_25a0b0e2600 = runtime_double_result;
    MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,1);
    iVar2 = 0;
    if (state_v_2236c != false) {
      iVar2 = 0xf;
    }
    DAT_25a0b0e25f0 = runtime_double_result;
    MT5_iLow((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,1);
    DAT_25a0b0e25f8 = runtime_double_result;
    DAT_25a0b0e2608 = DAT_25a0b0e25f0 - runtime_double_result;
    DAT_25a0b0e2610 = (ulonglong)(DAT_25a0b0e2600 - DAT_25a0b0e25e8) & _DAT_25a0b0dbb60;
  }
  return;
}



/* Address: 25a0b0cbc10 */

void FUN_25a0b0cbc10(int *param_1,int *param_2)

{
  wchar16 wVar1;
  wchar16 wVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  int *piVar10;
  int iVar11;
  undefined4 local_88;
  wchar16 *local_84;
  longlong local_78;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  int *local_50;
  int *local_48;
  
  local_88 = 0;
  local_84 = (wchar16 *)0x0;
  *param_2 = 0;
  *param_1 = 0;
  local_50 = param_1;
  local_48 = param_2;
  iVar7 = MT5_PositionsTotal((void *)0x25a0930b4c8);
  if (-1 < iVar7 + -1) {
    local_78 = (longlong)InpMagic;
    iVar7 = iVar7 + -1;
    do {
      uVar8 = MT5_PositionGetTicket((void *)0x25a0930b4c8,iVar7);
      if (uVar8 != 0) {
        local_60 = 0;
        local_70 = 0;
        local_5c = 0;
        local_6c = 0;
        MT5_PositionGetString((void *)0x25a0930b4c8,0);
        FUN_25a0b0c05f0(&local_60,&runtime_string_result,1,&PTR_DAT_25a0b0dfe18);
        FUN_25a0b0c05f0(&local_70,&local_60,0,&PTR_DAT_25a0b0dfe28);
        FUN_25a0b0c05f0(&runtime_string_result,&local_70,1,&PTR_DAT_25a0b0dfe38);
        FUN_25a0b0c0000(&local_70);
        FUN_25a0b0c0000(&local_60);
        FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e0f20);
        if (local_84 == _Symbol.text) {
LAB_25a0b0cbdf5:
          lVar9 = MT5_PositionGetInteger((void *)0x25a0930b4c8,0xc);
          if (lVar9 == local_78) {
            lVar9 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
            piVar10 = local_48;
            if ((int)lVar9 == 0) {
              piVar10 = local_50;
            }
            *piVar10 = *piVar10 + 1;
          }
        }
        else if ((local_84 != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar3 = *(uint *)(local_84 + -2);
          uVar4 = *(uint *)(_Symbol.text + -2);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar11 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar8 = 1;
            do {
              wVar1 = local_84[uVar8 - 1];
              wVar2 = _Symbol.text[uVar8 - 1];
              if (uVar6 <= uVar8) break;
              uVar8 = uVar8 + 1;
            } while (wVar1 == wVar2);
            if (wVar1 != wVar2) {
              iVar11 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
            }
          }
          if (iVar11 == 0) goto LAB_25a0b0cbdf5;
        }
      }
      bVar5 = 0 < iVar7;
      iVar7 = iVar7 + -1;
    } while (bVar5);
  }
  iVar7 = MT5_OrdersTotal((void *)0x25a0930b4c8);
  if (-1 < iVar7 + -1) {
    local_78 = (longlong)InpMagic;
    iVar7 = iVar7 + -1;
    do {
      uVar8 = MT5_OrderGetTicket((void *)0x25a0930b4c8,iVar7);
      DAT_25a0b0e2330 = -(ulonglong)(uVar8 == 0) | uVar8;
      if (uVar8 != 0) {
        local_60 = 0;
        local_70 = 0;
        local_5c = 0;
        local_6c = 0;
        MT5_OrderGetString((void *)0x25a0930b4c8,0);
        FUN_25a0b0c05f0(&local_60,&runtime_string_result,1,&PTR_DAT_25a0b0dfd90);
        FUN_25a0b0c05f0(&local_70,&local_60,0,&PTR_DAT_25a0b0dfda0);
        FUN_25a0b0c05f0(&runtime_string_result,&local_70,1,&PTR_DAT_25a0b0dfdb0);
        FUN_25a0b0c0000(&local_70);
        FUN_25a0b0c0000(&local_60);
        FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e0f30);
        if (local_84 == _Symbol.text) {
LAB_25a0b0cbff5:
          lVar9 = MT5_OrderGetInteger((void *)0x25a0930b4c8,0xf);
          if (lVar9 == local_78) {
            lVar9 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
            if ((int)lVar9 == 4) {
              *local_50 = *local_50 + 1;
            }
            lVar9 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
            if ((int)lVar9 == 5) {
              *local_48 = *local_48 + 1;
            }
          }
        }
        else if ((local_84 != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
          uVar3 = *(uint *)(local_84 + -2);
          uVar4 = *(uint *)(_Symbol.text + -2);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar11 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar8 = 1;
            do {
              wVar1 = local_84[uVar8 - 1];
              wVar2 = _Symbol.text[uVar8 - 1];
              if (uVar6 <= uVar8) break;
              uVar8 = uVar8 + 1;
            } while (wVar1 == wVar2);
            if (wVar1 != wVar2) {
              iVar11 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
            }
          }
          if (iVar11 == 0) goto LAB_25a0b0cbff5;
        }
      }
      bVar5 = 0 < iVar7;
      iVar7 = iVar7 + -1;
    } while (bVar5);
  }
  FUN_25a0b0c0000(&local_88);
  return;
}



/* Address: 25a0b0cc080 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_25a0b0cc080(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  code *pcVar5;
  bool bVar6;
  longlong lVar7;
  ulonglong uVar8;
  byte bVar9;
  longlong lVar10;
  bool bVar11;
  longlong lVar12;
  byte bVar13;
  longlong lVar14;
  
  if (!state_v_223b4) {
    return 1;
  }
  if ((int)DAT_25a0b0e2438 < 3) {
    return 0;
  }
  if ((int)DAT_25a0b0e2478 < 3) {
    return 0;
  }
  if ((int)DAT_25a0b0e24b8 < 2) {
    return 0;
  }
  if ((int)DAT_25a0b0e24f8 < 2) {
    return 0;
  }
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
  uVar8 = (ulonglong)DAT_25a0b0e2438;
  if (uVar8 == 0) {
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x190386000001f6);
LAB_25a0b0cc30d:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2b0386000001f6);
LAB_25a0b0cc32d:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3d0386000001f6);
  }
  else {
    lVar10 = 0;
    if ((DAT_25a0b0e2430._2_2_ & 0x10) != 0) {
      lVar10 = uVar8 - 1;
    }
    if (uVar8 == 1) goto LAB_25a0b0cc30d;
    lVar7 = 1;
    if ((DAT_25a0b0e2430._2_2_ & 0x10) != 0) {
      lVar7 = uVar8 - 2;
    }
    if ((ulonglong)DAT_25a0b0e2478 == 0) goto LAB_25a0b0cc32d;
    lVar12 = 0;
    if ((DAT_25a0b0e2470._2_1_ & 0x10) != 0) {
      lVar12 = (ulonglong)DAT_25a0b0e2478 - 1;
    }
    if ((ulonglong)DAT_25a0b0e24b8 != 0) {
      lVar14 = 0;
      if ((DAT_25a0b0e24b0._2_1_ & 0x10) != 0) {
        lVar14 = (ulonglong)DAT_25a0b0e24b8 - 1;
      }
      if ((ulonglong)DAT_25a0b0e24f8 != 0) {
        dVar1 = *(double *)(ram0x025a0b0e244c + lVar10 * 8);
        dVar2 = *(double *)(ram0x025a0b0e248c + lVar12 * 8);
        dVar3 = *(double *)(ram0x025a0b0e24cc + lVar14 * 8);
        bVar11 = dVar1 < runtime_double_result && dVar2 < dVar1;
        bVar9 = -(runtime_double_result < dVar1) & -(dVar1 < dVar2);
        lVar10 = 0;
        if ((DAT_25a0b0e24f0._2_1_ & 0x10) != 0) {
          lVar10 = (ulonglong)DAT_25a0b0e24f8 - 1;
        }
        dVar2 = *(double *)(ram0x025a0b0e250c + lVar10 * 8);
        if (state_v_223b6 == true) {
          dVar4 = *(double *)(ram0x025a0b0e244c + lVar7 * 8);
          bVar11 = bVar11 && dVar4 < dVar1;
          bVar9 = bVar9 & dVar1 < dVar4;
        }
        bVar6 = dVar2 < dVar3 && dVar3 < runtime_double_result;
        bVar13 = -(dVar3 < dVar2) & -(runtime_double_result < dVar3);
        if (state_v_223b5 == true) {
          if ((bool)(bVar6 & bVar11)) {
            return 1;
          }
          bVar13 = bVar13 & bVar9;
        }
        else {
          if (bVar6 || bVar11) {
            return 1;
          }
          bVar13 = bVar13 | bVar9;
        }
        return (ulonglong)-(bVar13 & 1);
      }
      goto LAB_25a0b0cc36d;
    }
  }
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x500386000001f6);
LAB_25a0b0cc36d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x630386000001f6);
  pcVar5 = (code *)swi(3);
  uVar8 = (*pcVar5)();
  return uVar8;
}



/* Address: 25a0b0cc390 */

undefined8 FUN_25a0b0cc390(void)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint arg_3;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar6 = 0xf;
  if (!state_v_2236c) {
    iVar6 = 0;
  }
  lVar4 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar6,0);
  if (lVar4 == DAT_25a0b0e2618) {
    uVar8 = SUB84(DAT_25a0b0e2620,0);
    uVar10 = (undefined4)((ulonglong)DAT_25a0b0e2620 >> 0x20);
    if ((DAT_25a0b0e2620 != DAT_25a0b0dbb70) || (NAN(DAT_25a0b0e2620) || NAN(DAT_25a0b0dbb70)))
    goto LAB_25a0b0cc65e;
  }
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
  dVar1 = runtime_double_result;
  iVar6 = 0;
  if (state_v_22374 != false) {
    iVar6 = 0x12;
  }
  arg_3 = iVar6 + 1;
  iVar7 = 0;
  if (state_v_22375 != false) {
    iVar7 = 0x92;
  }
  uVar8 = (undefined4)DAT_25a0b0dbb78;
  uVar10 = (undefined4)((ulonglong)DAT_25a0b0dbb78 >> 0x20);
  if ((int)arg_3 < iVar7 - iVar6) {
    iVar7 = -iVar6;
    uVar12 = uVar8;
    uVar13 = uVar10;
    do {
      iVar5 = 0;
      if (state_v_2236c != false) {
        iVar5 = 0xf;
      }
      uVar3 = MT5_iHighest((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar5,2,iVar6 * 2 + 1,
                           arg_3 - iVar6);
      uVar8 = uVar12;
      uVar10 = uVar13;
      if (uVar3 == arg_3) {
        iVar6 = 0;
        if (state_v_2236c != false) {
          iVar6 = 0xf;
        }
        MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar6,arg_3);
        dVar2 = runtime_double_result;
        uVar9 = SUB84(runtime_double_result,0);
        uVar11 = (undefined4)((ulonglong)runtime_double_result >> 0x20);
        if (DAT_25a0b0e2578 + dVar1 <= runtime_double_result) {
          if (1 < arg_3) {
            iVar6 = 1;
            do {
              iVar5 = 0;
              if (state_v_2236c != false) {
                iVar5 = 0xf;
              }
              MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar5,iVar6);
              if (dVar2 <= runtime_double_result) goto LAB_25a0b0cc4f5;
              iVar5 = iVar7 + 1 + iVar6;
              iVar6 = iVar6 + 1;
            } while (iVar5 != 1);
          }
          uVar8 = uVar9;
          uVar10 = uVar11;
          if ((0.0 < (double)CONCAT44(uVar13,uVar12) || (double)CONCAT44(uVar13,uVar12) == 0.0) &&
             (uVar8 = uVar12, uVar10 = uVar13,
             dVar2 <= (double)CONCAT44(uVar13,uVar12) && (double)CONCAT44(uVar13,uVar12) != dVar2))
          {
            uVar8 = uVar9;
            uVar10 = uVar11;
          }
        }
      }
LAB_25a0b0cc4f5:
      arg_3 = arg_3 + 1;
      iVar5 = 0;
      if (state_v_22375 != false) {
        iVar5 = 0x92;
      }
      iVar6 = 0;
      if (state_v_22374 != false) {
        iVar6 = 0x12;
      }
      iVar7 = iVar7 + -1;
      uVar12 = uVar8;
      uVar13 = uVar10;
    } while ((int)arg_3 < iVar5 - iVar6);
  }
  DAT_25a0b0e2620 = (double)CONCAT44(uVar10,uVar8);
  DAT_25a0b0e2618 = lVar4;
LAB_25a0b0cc65e:
  return CONCAT44(uVar10,uVar8);
}



/* Address: 25a0b0cc690 */

undefined8 FUN_25a0b0cc690(char param_1)

{
  code *pcVar1;
  double *pdVar2;
  undefined8 uVar3;
  double dVar4;
  
  if (DAT_25a0b0e2608 < DAT_25a0b0dbb80) {
    return 0;
  }
  if (param_1 == '\0') {
    if (DAT_25a0b0e25e8 <= DAT_25a0b0e2600) {
      return 0;
    }
  }
  else if (DAT_25a0b0e2600 <= DAT_25a0b0e25e8) {
    return 0;
  }
  if (0.0 < state_v_22388) {
    if ((DAT_25a0b0e2570 != 0.0) || (NAN(DAT_25a0b0e2570))) {
      if (DAT_25a0b0e2608 / DAT_25a0b0e2570 < state_v_22388) {
        return 0;
      }
      goto LAB_25a0b0cc736;
    }
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2003bd000001f7);
LAB_25a0b0cc816:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f03be000001f7);
LAB_25a0b0cc836:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3803c0000001f7);
LAB_25a0b0cc856:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3303c1000001f7);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
LAB_25a0b0cc736:
  if (0.0 < state_v_22380) {
    if ((DAT_25a0b0e2608 == 0.0) && (!NAN(DAT_25a0b0e2608))) goto LAB_25a0b0cc816;
    if (DAT_25a0b0e2610 / DAT_25a0b0e2608 < state_v_22380) {
      return 0;
    }
  }
  pdVar2 = &state_v_22390;
  if (state_v_22390 <= 0.0) goto LAB_25a0b0cc7ea;
  if (param_1 == '\0') {
    if ((DAT_25a0b0e2608 == 0.0) && (!NAN(DAT_25a0b0e2608))) goto LAB_25a0b0cc856;
    pdVar2 = &DAT_25a0b0e25f0;
    dVar4 = DAT_25a0b0e25e8;
    if (DAT_25a0b0e25e8 <= DAT_25a0b0e2600) {
      dVar4 = DAT_25a0b0e2600;
    }
    dVar4 = DAT_25a0b0e25f0 - dVar4;
  }
  else {
    if ((DAT_25a0b0e2608 == 0.0) && (!NAN(DAT_25a0b0e2608))) goto LAB_25a0b0cc836;
    dVar4 = DAT_25a0b0e25e8;
    if (DAT_25a0b0e2600 <= DAT_25a0b0e25e8) {
      dVar4 = DAT_25a0b0e2600;
    }
    pdVar2 = &DAT_25a0b0e25f8;
    dVar4 = dVar4 - DAT_25a0b0e25f8;
  }
  if (state_v_22390 < dVar4 / DAT_25a0b0e2608) {
    return 0;
  }
LAB_25a0b0cc7ea:
  return CONCAT71((int7)((ulonglong)pdVar2 >> 8),1);
}



/* Address: 25a0b0cc880 */

ulonglong FUN_25a0b0cc880(void)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 unaff_RSI;
  undefined7 uVar8;
  undefined8 uVar9;
  ulonglong local_50;
  ulonglong local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined4 local_20;
  
  uVar8 = (undefined7)((ulonglong)unaff_RSI >> 8);
  uVar3 = CONCAT71(uVar8,1);
  if (!state_v_223b7) goto LAB_25a0b0cc9ed;
  local_50 = 0x800110055;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_28 = 0;
  local_20 = 0;
  uVar7 = (uint)state_v_223c0;
  uVar9 = 0xf;
  if (!state_v_2236c) {
    uVar9 = 0;
  }
  iVar2 = (*(code *)&MT5_CopyClose__CopyHigh__CopyLow__CopyOpen__CopyRates__CopyTime)
                    (0x25a0930b4c8,6,0,uVar9,1,uVar7 | 2,&local_50);
  uVar3 = CONCAT71(uVar8,1);
  if ((int)(uVar7 | 2) <= iVar2) {
    if (state_v_223c0 == true) {
      if ((local_50 & 0x100000) == 0) {
        if ((uint)local_48 < 2) goto LAB_25a0b0cca37;
        plVar4 = (longlong *)(CONCAT44(local_30,uStack_34) + 8);
      }
      else {
        if ((uint)local_48 < 2) goto LAB_25a0b0cca37;
        plVar4 = (longlong *)(CONCAT44(local_30,uStack_34) + -0x10 + (local_48 & 0xffffffff) * 8);
      }
      lVar5 = *plVar4;
    }
    else {
      lVar5 = 0;
    }
    if (state_v_223c0 == false) {
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x4003ad000001f7);
LAB_25a0b0cca17:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1503ae000001f6);
LAB_25a0b0cca37:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x3a03ad000001f6);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    if (0 < lVar5) {
      if ((local_48 & 0xffffffff) == 0) goto LAB_25a0b0cca17;
      lVar6 = 0;
      if ((local_50 & 0x100000) != 0) {
        lVar6 = (local_48 & 0xffffffff) - 1;
      }
      if ((longlong)((double)lVar5 * state_v_223b8) <=
          *(longlong *)(CONCAT44(local_30,uStack_34) + lVar6 * 8)) goto LAB_25a0b0cc9d2;
    }
    uVar3 = 0;
  }
LAB_25a0b0cc9d2:
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&local_50);
LAB_25a0b0cc9ed:
  return uVar3 & 0xffffffff;
}



/* Address: 25a0b0cca60 */

void FUN_25a0b0cca60(double param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  MqlStringAnalysisView *value_0;
  uint type_1;
  double dVar10;
  uint type_2;
  undefined4 *value_2;
  double local_b0;
  double local_a8;
  undefined4 *local_a0;
  double local_98;
  double local_90;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_84 = 0;
  local_98 = param_1;
  cVar1 = FUN_25a0b0ca930();
  if ((cVar1 != '\0') &&
     (MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4),
     runtime_double_result + DAT_25a0b0e2578 < param_1)) {
    local_a0 = (undefined4 *)(param_1 - state_v_22630);
    local_a8 = state_v_22638 + param_1;
    local_b0 = (double)FUN_25a0b0d6270(param_1 - (double)local_a0,0);
    if ((0.0 < local_b0) && (cVar1 = FUN_25a0b0d75c0(&local_b0), dVar6 = local_b0, cVar1 != '\0')) {
      uVar8 = SUB84(local_b0,0);
      uVar9 = (undefined4)((ulonglong)local_b0 >> 0x20);
      if (DAT_25a0b0e258c == '\0') {
        dVar6 = (double)FUN_25a0b0d69f0(local_b0,0);
        uVar8 = SUB84(dVar6,0);
        uVar9 = (undefined4)((ulonglong)dVar6 >> 0x20);
        if (dVar6 <= 0.0) goto LAB_25a0b0ccf2d;
      }
      else {
        if (local_b0 <= 0.0) goto LAB_25a0b0ccf2d;
        MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
        local_90 = 0.0;
        cVar1 = (*(code *)&MT5_OrderCalcMargin)
                          (0x25a0930b4c8,0,&_Symbol,dVar6,runtime_double_result,&local_90);
        dVar6 = local_90;
        if (((cVar1 == '\0') || (local_90 <= 0.0)) ||
           (MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x2a),
           runtime_double_result * DAT_25a0b0dbb88 < dVar6)) goto LAB_25a0b0ccf2d;
      }
      FUN_25a0b0d7770(&local_98);
      FUN_25a0b0d7770(&local_a0);
      FUN_25a0b0d7770(&local_a8);
      dVar10 = local_98;
      value_2 = local_a0;
      dVar6 = local_a8;
      lVar4 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
      lVar5 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
      iVar2 = (int)lVar5;
      if ((int)lVar5 < (int)lVar4) {
        iVar2 = (int)lVar4;
      }
      dVar7 = (double)(iVar2 + 2) * DAT_25a0b0e2570;
      if ((((double)value_2 <= 0.0) || (dVar7 <= dVar10 - (double)value_2)) &&
         ((dVar6 <= 0.0 || (dVar7 <= dVar6 - dVar10)))) {
        iVar2 = 0;
        if (state_v_2236c != false) {
          iVar2 = 0xf;
        }
        lVar4 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,0);
        iVar2 = state_v_223a0;
        iVar3 = 0;
        if (state_v_2236c != false) {
          iVar3 = 0xf;
        }
        iVar3 = MT5_PeriodSeconds((void *)0x25a0930b4c8,iVar3);
        cVar1 = FUN_25a0b0d7280(4,CONCAT44(uVar9,uVar8),dVar10,value_2,dVar6,iVar3 * iVar2 + lVar4);
        if (cVar1 == '\0') {
          if (DAT_25a0b0e258f == '\0') goto LAB_25a0b0ccf2d;
          FUN_25a0b0d1ba0();
          value_2 = &local_88;
          FUN_25a0b0c05f0(value_2,&runtime_string_result,1,&PTR_DAT_25a0b0e0bd0);
          iVar2 = 3;
          type_2 = 0x590008;
          type_1 = 0x530014;
          value_0 = &string_ref_25a0b0de6b8;
          dVar10 = (double)(ulonglong)DAT_25a0b0e2110;
        }
        else {
          DAT_25a0b0e2594 = DAT_25a0b0e2594 + 1;
          if (DAT_25a0b0e258f == '\0') goto LAB_25a0b0ccf2d;
          type_2 = 0x580007;
          type_1 = 0x580007;
          iVar2 = 5;
          value_0 = &string_ref_25a0b0de660;
        }
        MT5_Dispatch((void *)0x25a0930b4c8,0xd,iVar2,0x590008,value_0,type_1,SUB84(dVar10,0),type_2,
                     value_2);
      }
    }
  }
LAB_25a0b0ccf2d:
  FUN_25a0b0c0000(&local_88);
  return;
}



/* Address: 25a0b0ccf80 */

undefined8 FUN_25a0b0ccf80(void)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint arg_3;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar6 = 0xf;
  if (!state_v_2236c) {
    iVar6 = 0;
  }
  lVar4 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar6,0);
  if (lVar4 == DAT_25a0b0e2618) {
    uVar8 = SUB84(DAT_25a0b0e2628,0);
    uVar10 = (undefined4)((ulonglong)DAT_25a0b0e2628 >> 0x20);
    if ((DAT_25a0b0e2628 != DAT_25a0b0dbb90) || (NAN(DAT_25a0b0e2628) || NAN(DAT_25a0b0dbb90)))
    goto LAB_25a0b0cd24a;
  }
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
  dVar1 = runtime_double_result;
  iVar6 = 0;
  if (state_v_22374 != false) {
    iVar6 = 0x12;
  }
  arg_3 = iVar6 + 1;
  iVar7 = 0;
  if (state_v_22375 != false) {
    iVar7 = 0x92;
  }
  uVar8 = (undefined4)DAT_25a0b0dbb98;
  uVar10 = (undefined4)((ulonglong)DAT_25a0b0dbb98 >> 0x20);
  if ((int)arg_3 < iVar7 - iVar6) {
    iVar7 = -iVar6;
    uVar12 = uVar8;
    uVar13 = uVar10;
    do {
      iVar5 = 0;
      if (state_v_2236c != false) {
        iVar5 = 0xf;
      }
      uVar3 = MT5_iLowest((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar5,1,iVar6 * 2 + 1,arg_3 - iVar6
                         );
      uVar8 = uVar12;
      uVar10 = uVar13;
      if (uVar3 == arg_3) {
        iVar6 = 0;
        if (state_v_2236c != false) {
          iVar6 = 0xf;
        }
        MT5_iLow((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar6,arg_3);
        dVar2 = runtime_double_result;
        uVar9 = SUB84(runtime_double_result,0);
        uVar11 = (undefined4)((ulonglong)runtime_double_result >> 0x20);
        if (runtime_double_result <= dVar1 - DAT_25a0b0e2578) {
          if (1 < arg_3) {
            iVar6 = 1;
            do {
              iVar5 = 0;
              if (state_v_2236c != false) {
                iVar5 = 0xf;
              }
              MT5_iLow((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar5,iVar6);
              if (runtime_double_result <= dVar2) goto LAB_25a0b0cd0e5;
              iVar5 = iVar7 + 1 + iVar6;
              iVar6 = iVar6 + 1;
            } while (iVar5 != 1);
          }
          uVar8 = uVar9;
          uVar10 = uVar11;
          if ((0.0 < (double)CONCAT44(uVar13,uVar12) || (double)CONCAT44(uVar13,uVar12) == 0.0) &&
             (uVar8 = uVar12, uVar10 = uVar13,
             (double)CONCAT44(uVar13,uVar12) <= dVar2 && dVar2 != (double)CONCAT44(uVar13,uVar12)))
          {
            uVar8 = uVar9;
            uVar10 = uVar11;
          }
        }
      }
LAB_25a0b0cd0e5:
      arg_3 = arg_3 + 1;
      iVar5 = 0;
      if (state_v_22375 != false) {
        iVar5 = 0x92;
      }
      iVar6 = 0;
      if (state_v_22374 != false) {
        iVar6 = 0x12;
      }
      iVar7 = iVar7 + -1;
      uVar12 = uVar8;
      uVar13 = uVar10;
    } while ((int)arg_3 < iVar5 - iVar6);
  }
  DAT_25a0b0e2628 = (double)CONCAT44(uVar10,uVar8);
  DAT_25a0b0e2618 = lVar4;
LAB_25a0b0cd24a:
  return CONCAT44(uVar10,uVar8);
}



/* Address: 25a0b0cd280 */

void FUN_25a0b0cd280(double param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  MqlStringAnalysisView *value_0;
  uint type_1;
  double dVar10;
  uint type_2;
  undefined4 *value_2;
  double local_b0;
  double local_a8;
  undefined4 *local_a0;
  double local_98;
  double local_90;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_84 = 0;
  local_98 = param_1;
  cVar1 = FUN_25a0b0ca930();
  if ((cVar1 != '\0') &&
     (MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1),
     param_1 < runtime_double_result - DAT_25a0b0e2578)) {
    local_a0 = (undefined4 *)(state_v_22630 + param_1 + 0.0);
    local_a8 = param_1 - state_v_22638;
    local_b0 = (double)FUN_25a0b0d6270((double)local_a0 - param_1,1);
    if ((0.0 < local_b0) && (cVar1 = FUN_25a0b0d75c0(&local_b0), dVar6 = local_b0, cVar1 != '\0')) {
      uVar8 = SUB84(local_b0,0);
      uVar9 = (undefined4)((ulonglong)local_b0 >> 0x20);
      if (DAT_25a0b0e258c == '\0') {
        dVar6 = (double)FUN_25a0b0d69f0(local_b0,1);
        uVar8 = SUB84(dVar6,0);
        uVar9 = (undefined4)((ulonglong)dVar6 >> 0x20);
        if (dVar6 <= 0.0) goto LAB_25a0b0cd752;
      }
      else {
        if (local_b0 <= 0.0) goto LAB_25a0b0cd752;
        MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
        local_90 = 0.0;
        cVar1 = (*(code *)&MT5_OrderCalcMargin)
                          (0x25a0930b4c8,1,&_Symbol,dVar6,runtime_double_result,&local_90);
        dVar6 = local_90;
        if (((cVar1 == '\0') || (local_90 <= 0.0)) ||
           (MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x2a),
           runtime_double_result * DAT_25a0b0dbba0 < dVar6)) goto LAB_25a0b0cd752;
      }
      FUN_25a0b0d7770(&local_98);
      FUN_25a0b0d7770(&local_a0);
      FUN_25a0b0d7770(&local_a8);
      dVar10 = local_98;
      value_2 = local_a0;
      dVar6 = local_a8;
      lVar4 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
      lVar5 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
      iVar2 = (int)lVar5;
      if ((int)lVar5 < (int)lVar4) {
        iVar2 = (int)lVar4;
      }
      dVar7 = (double)(iVar2 + 2) * DAT_25a0b0e2570;
      if ((((double)value_2 <= 0.0) || (dVar7 <= (double)value_2 - dVar10)) &&
         ((dVar6 <= 0.0 || (dVar7 <= dVar10 - dVar6)))) {
        iVar2 = 0;
        if (state_v_2236c != false) {
          iVar2 = 0xf;
        }
        lVar4 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,iVar2,0);
        iVar2 = state_v_223a0;
        iVar3 = 0;
        if (state_v_2236c != false) {
          iVar3 = 0xf;
        }
        iVar3 = MT5_PeriodSeconds((void *)0x25a0930b4c8,iVar3);
        cVar1 = FUN_25a0b0d7280(5,CONCAT44(uVar9,uVar8),dVar10,value_2,dVar6,iVar3 * iVar2 + lVar4);
        if (cVar1 == '\0') {
          if (DAT_25a0b0e258f == '\0') goto LAB_25a0b0cd752;
          FUN_25a0b0d1ba0();
          value_2 = &local_88;
          FUN_25a0b0c05f0(value_2,&runtime_string_result,1,&PTR_DAT_25a0b0e0be0);
          iVar2 = 3;
          type_2 = 0x590008;
          type_1 = 0x530014;
          value_0 = &string_ref_25a0b0de798;
          dVar10 = (double)(ulonglong)DAT_25a0b0e2110;
        }
        else {
          DAT_25a0b0e2594 = DAT_25a0b0e2594 + 1;
          if (DAT_25a0b0e258f == '\0') goto LAB_25a0b0cd752;
          type_2 = 0x580007;
          type_1 = 0x580007;
          iVar2 = 5;
          value_0 = &string_ref_25a0b0de740;
        }
        MT5_Dispatch((void *)0x25a0930b4c8,0xd,iVar2,0x590008,value_0,type_1,SUB84(dVar10,0),type_2,
                     value_2);
      }
    }
  }
LAB_25a0b0cd752:
  FUN_25a0b0c0000(&local_88);
  return;
}



/* Address: 25a0b0cd7a0 */

void FUN_25a0b0cd7a0(void)

{
  MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x25);
  return;
}



/* Address: 25a0b0cd7c0 */

void FUN_25a0b0cd7c0(int param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 unaff_RBX;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulonglong)unaff_RBX >> 0x20);
  if (((param_1 == 9) && (DAT_25a0b0e258f != '\0')) && (ShowPanel)) {
    lVar2 = MT5_ChartGetInteger((void *)0x25a0930b4c8,0,0x6a,0);
    lVar3 = MT5_ChartGetInteger((void *)0x25a0930b4c8,0,0x6b,0);
    if (((0 < lVar2) && (0 < lVar3)) && ((lVar2 != DAT_25a0b0e4d28 || (lVar3 != DAT_25a0b0e4d30))))
    {
      DAT_25a0b0e4d28 = lVar2;
      DAT_25a0b0e4d30 = lVar3;
      FUN_25a0b0c56c0();
      FUN_25a0b0c5bc0();
      FUN_25a0b0c60f0();
      if (((UseNewsFilter != false) && ((DAT_25a0b0e46ea & 1) != 0)) &&
         ((DAT_25a0b0e258f != '\0' && (DAT_25a0b0e258c == '\0')))) {
        FUN_25a0b0d7ee0(&string_ref_25a0b0e46f0,0x14,&string_ref_25a0b0df068,0x4f4feb,
                        CONCAT44(uVar4,0xb),unaff_RDI,unaff_RSI);
        FUN_25a0b0d7ee0(&string_ref_25a0b0e4700,0x2a,&string_ref_25a0b0df160,0x37b1ed,9);
        (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,0);
        return;
      }
      iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0e46f0);
      if (-1 < iVar1) {
        MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e46f0);
      }
      iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0e4700);
      if (iVar1 < 0) {
        return;
      }
      MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e4700);
      return;
    }
  }
  return;
}



/* Address: 25a0b0cd890 */

void FUN_25a0b0cd890(void)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  longlong lVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar9;
  undefined4 local_68;
  wchar_t *local_64;
  undefined4 local_58;
  undefined8 local_54;
  longlong local_48;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  if (DAT_25a0b0e23cc != -1) {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,DAT_25a0b0e23cc);
  }
  if (DAT_25a0b0e23d0 != -1) {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,DAT_25a0b0e23d0);
  }
  if (DAT_25a0b0e23d4 != -1) {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,DAT_25a0b0e23d4);
  }
  if (DAT_25a0b0e23d8 != -1) {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,DAT_25a0b0e23d8);
  }
  if (DAT_25a0b0e23dc != -1) {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,DAT_25a0b0e23dc);
  }
  if (DAT_25a0b0e23e0 == '\0') {
    MT5_IndicatorRelease((void *)0x25a0930b4c8,0);
  }
  if ((ShowPanel != false) && (DAT_25a0b0e258f != '\0')) {
    if (DAT_25a0b0e4d24 == '\x01') {
      FUN_25a0b0c0d50(&DAT_25a0b0e4c90);
      DAT_25a0b0e4d24 = '\0';
    }
    iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528);
    if (-1 < iVar1) {
      MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0df528);
    }
    (*(code *)&MT5_ObjectsDeleteAllPrefix)
              (0x25a0930b4c8,0,&string_ref_25a0b0dfc40,0xffffffff,CONCAT44(uVar9,0xffffffff));
  }
  if (DAT_25a0b0e258f != '\0') {
    local_58 = 0;
    local_68 = 0;
    local_54 = 0;
    local_64 = (wchar_t *)0x0;
    iVar1 = MT5_ObjectsTotal((void *)0x25a0930b4c8,0,-1,-1);
    if (-1 < iVar1 + -1) {
      iVar1 = iVar1 + -1;
      do {
        local_68 = 0;
        local_64 = (wchar_t *)0x0;
        MT5_ObjectName((void *)0x25a0930b4c8,0,iVar1,-1,-1);
        FUN_25a0b0c05f0(&local_58,&runtime_string_result,1,&PTR_DAT_25a0b0e1050);
        FUN_25a0b0c05f0(&local_68,&local_58,0,&PTR_DAT_25a0b0e1060);
        if (local_64 == (wchar_t *)0x0) {
          _LastError = 0xfa9;
        }
        else {
          uVar2 = *(uint *)(local_64 + -2);
          if ((uVar2 == 0) || (DAT_25a0b0df358 == 0)) {
            _LastError = 0x13ab;
          }
          else {
            if (local_64 == literal_25a0b0df35c) goto LAB_25a0b0cdc88;
            if ((DAT_25a0b0df358 <= uVar2) && (uVar2 = (uVar2 - DAT_25a0b0df358) + 1, uVar2 != 0)) {
              uVar3 = (ulonglong)uVar2;
              if (DAT_25a0b0df358 < 2) {
                if (*local_64 == L'T') {
LAB_25a0b0cdc88:
                  MT5_ObjectDelete((void *)0x25a0930b4c8,0,&local_68);
                }
                else {
                  uVar4 = 0;
                  do {
                    if (uVar3 - 1 == uVar4) goto LAB_25a0b0cdac0;
                    lVar7 = uVar4 + 1;
                    uVar4 = uVar4 + 1;
                  } while (local_64[lVar7] != L'T');
                  if (uVar4 < uVar3) {
LAB_25a0b0cdc80:
                    if ((int)uVar4 == 0) goto LAB_25a0b0cdc88;
                  }
                }
              }
              else {
                bVar8 = true;
                uVar4 = 0;
                local_48 = (ulonglong)DAT_25a0b0df358 - 1;
                uVar2 = 1;
                do {
                  if (local_64[uVar4] == L'T') {
                    pwVar5 = literal_25a0b0df35c;
                    lVar7 = local_48;
                    uVar6 = uVar2;
                    while (pwVar5 = pwVar5 + 1, local_64[uVar6] == *pwVar5) {
                      uVar6 = uVar6 + 1;
                      lVar7 = lVar7 + -1;
                      if (lVar7 == 0) goto LAB_25a0b0cdc69;
                    }
                    if ((int)lVar7 == 0) {
LAB_25a0b0cdc69:
                      if (bVar8) goto LAB_25a0b0cdc80;
                      break;
                    }
                  }
                  uVar4 = uVar4 + 1;
                  uVar2 = uVar2 + 1;
                  bVar8 = uVar4 < uVar3;
                } while (uVar4 != uVar3);
              }
            }
          }
        }
LAB_25a0b0cdac0:
        FUN_25a0b0c0000(&local_68);
        bVar8 = 0 < iVar1;
        iVar1 = iVar1 + -1;
      } while (bVar8);
    }
    if ((DAT_25a0b0e258c == '\0') || (DAT_25a0b0e258e != '\0')) {
      (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,0);
    }
    FUN_25a0b0c0000(&local_58);
  }
  MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e46f0);
  MT5_ObjectDelete((void *)0x25a0930b4c8,0,&string_ref_25a0b0e4700);
  MT5_Dispatch((void *)0x25a0930b4c8,4,1,0x590008,&string_ref_25a0b0dc170);
  return;
}



/* Address: 25a0b0cdd50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0cdd50(ulonglong *param_1)

{
  wchar16 wVar1;
  wchar16 wVar2;
  uint uVar3;
  uint uVar4;
  ulonglong arg_1;
  code *pcVar5;
  double dVar6;
  bool bVar7;
  char cVar8;
  int extraout_EAX;
  longlong lVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  double dVar14;
  MqlStringAnalysisView *value_0;
  undefined4 local_68;
  wchar16 *local_64;
  
  local_68 = 0;
  local_64 = (wchar16 *)0x0;
  if ((*(int *)((longlong)param_1 + 0x1c) != 6) || (arg_1 = *param_1, arg_1 == 0))
  goto LAB_25a0b0ce345;
  bVar7 = MT5_HistoryDealSelect((void *)0x25a0930b4c8,arg_1);
  if (!bVar7) goto LAB_25a0b0ce345;
  lVar9 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,0xb);
  if (InpMagic != (int)lVar9) goto LAB_25a0b0ce345;
  MT5_HistoryDealGetString((void *)0x25a0930b4c8,arg_1,0);
  FUN_25a0b0c05f0(&local_68,&runtime_string_result,1,&PTR_DAT_25a0b0dfcf0);
  if (local_64 != _Symbol.text) {
    if ((local_64 == (wchar16 *)0x0) || (_Symbol.text == (wchar16 *)0x0)) goto LAB_25a0b0ce345;
    uVar3 = *(uint *)(local_64 + -2);
    uVar4 = *(uint *)(_Symbol.text + -2);
    uVar12 = uVar4;
    if (uVar3 < uVar4) {
      uVar12 = uVar3;
    }
    iVar11 = uVar3 - uVar4;
    if (uVar12 != 0) {
      uVar13 = 1;
      do {
        wVar1 = local_64[uVar13 - 1];
        wVar2 = _Symbol.text[uVar13 - 1];
        if (uVar12 <= uVar13) break;
        uVar13 = uVar13 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 != wVar2) {
        iVar11 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
      }
    }
    if (iVar11 != 0) goto LAB_25a0b0ce345;
  }
  lVar9 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,4);
  extraout_EAX = (int)lVar9;
  if (extraout_EAX == 0) {
    uVar13 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,1);
    MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,6);
    dVar6 = runtime_double_result;
    uVar10 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,3);
    dVar14 = 0.0;
    if (uVar13 != 0) {
      bVar7 = MT5_HistoryOrderSelect((void *)0x25a0930b4c8,uVar13);
      dVar14 = 0.0;
      if (bVar7) {
        MT5_HistoryOrderGetDouble((void *)0x25a0930b4c8,uVar13,9);
        dVar14 = 0.0;
        if (((0.0 < runtime_double_result) && (dVar14 = 0.0, 0.0 < dVar6)) &&
           (dVar14 = 0.0, 0.0 < DAT_25a0b0e2570)) {
          if ((int)uVar10 == 0) {
            if ((DAT_25a0b0e2570 == 0.0) && (!NAN(DAT_25a0b0e2570))) goto LAB_25a0b0ce394;
            dVar14 = dVar6 - runtime_double_result;
          }
          else {
            if ((DAT_25a0b0e2570 == 0.0) && (!NAN(DAT_25a0b0e2570))) {
              (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2f07f1000001f7);
LAB_25a0b0ce394:
              (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2f07f0000001f7);
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            dVar14 = runtime_double_result - dVar6;
          }
          dVar14 = dVar14 / DAT_25a0b0e2570;
          DAT_25a0b0e26b0 = dVar14;
        }
      }
    }
    if ((DAT_25a0b0e236b == '\x01') && (0.0 < dVar6)) {
      if (DAT_25a0b0e258c == '\0') {
        uVar13 = param_1[0xc];
      }
      else {
        uVar13 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,0xc);
      }
      if (uVar13 == 0) {
        uVar13 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,0xc);
      }
      cVar8 = FUN_25a0b0ce3c0(uVar13,dVar6,uVar10 & 0xffffffff);
      if (cVar8 == '\0' && DAT_25a0b0e258c == '\0') {
        FUN_25a0b0ce830(uVar13,uVar10 & 0xffffffff,dVar6,
                        (double)((ulonglong)dVar14 & _DAT_25a0b0dbbb0) * DAT_25a0b0e2570);
      }
    }
    DAT_25a0b0e2668 = 1;
    goto LAB_25a0b0ce345;
  }
  if (extraout_EAX - 4U < 0xfffffffd) goto LAB_25a0b0ce345;
  lVar9 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,arg_1,0x10);
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,9);
  dVar14 = runtime_double_result;
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,8);
  dVar14 = dVar14 + runtime_double_result;
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,arg_1,7);
  dVar14 = dVar14 + runtime_double_result;
  FUN_25a0b0cea90(arg_1,dVar14);
  DAT_25a0b0e2668 = 1;
  if (DAT_25a0b0e258f != '\0') {
    FUN_25a0b0cec70(arg_1);
  }
  if (extraout_EAX != 1) goto LAB_25a0b0ce345;
  if ((int)lVar9 == 4) {
    DAT_25a0b0e25d8 = state_v_223c4;
    DAT_25a0b0e25a8 = DAT_25a0b0e25a8 + 1;
    if ((state_v_225c0 != false) && (state_v_225c4 <= DAT_25a0b0e25a8)) {
      DAT_25a0b0e25ac = 1;
      if (DAT_25a0b0e258f == '\0') goto LAB_25a0b0ce234;
      MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0dca70,0x520004,
                   DAT_25a0b0e25a8,0x580007,state_v_225c8);
    }
    if (DAT_25a0b0e258f != '\0') {
      iVar11 = 4;
      value_0 = &string_ref_25a0b0dcaf0;
LAB_25a0b0ce22c:
      MT5_Dispatch((void *)0x25a0930b4c8,0xd,iVar11,0x590008,value_0,0x580007,dVar14);
    }
  }
  else if (0.0 < dVar14) {
    DAT_25a0b0e25a8 = 0;
    DAT_25a0b0e25ac = 0;
    if (DAT_25a0b0e258f != '\0') {
      iVar11 = 2;
      value_0 = &string_ref_25a0b0dcb30;
      goto LAB_25a0b0ce22c;
    }
  }
LAB_25a0b0ce234:
  MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x25);
LAB_25a0b0ce345:
  FUN_25a0b0c0000(&local_68);
  return;
}



/* Address: 25a0b0ce3c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_25a0b0ce3c0(ulonglong param_1,double param_2,int param_3)

{
  double dVar1;
  double value_2;
  double dVar2;
  double value_3;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 unaff_RSI;
  ulonglong uVar8;
  double dVar9;
  double local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  
  uVar8 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  local_b8 = 0;
  local_b4 = 0;
  if ((param_1 != 0) && (0.0 < param_2)) {
    bVar3 = MT5_PositionSelectByTicket((void *)0x25a0930b4c8,param_1);
    if (bVar3) {
      MT5_PositionGetDouble((void *)0x25a0930b4c8,6);
      value_2 = runtime_double_result;
      MT5_PositionGetDouble((void *)0x25a0930b4c8,7);
      dVar2 = runtime_double_result;
      MT5_PositionGetDouble((void *)0x25a0930b4c8,4);
      dVar1 = runtime_double_result;
      if (0.0 < value_2) {
        if (param_3 == 0) {
          local_c0 = param_2 - state_v_22630;
        }
        else {
          if (param_3 != 1) goto LAB_25a0b0ce7d5;
          local_c0 = state_v_22630 + param_2;
        }
        FUN_25a0b0d7770(&local_c0);
        value_3 = local_c0;
        if ((0.0 < local_c0) &&
           (DAT_25a0b0e2570 < (double)((ulonglong)(local_c0 - value_2) & _DAT_25a0b0dbbc0))) {
          if (param_3 == 0) {
            if ((dVar1 <= local_c0) || ((0.0 < dVar2 && (dVar2 <= local_c0)))) goto LAB_25a0b0ce7d5;
          }
          else if ((local_c0 <= dVar1) || ((0.0 < dVar2 && (local_c0 <= dVar2))))
          goto LAB_25a0b0ce7d5;
          lVar5 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
          lVar6 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
          dVar1 = (double)(int)lVar5;
          if ((double)(int)lVar5 <= (double)(int)lVar6) {
            dVar1 = (double)(int)lVar6;
          }
          dVar1 = (dVar1 + DAT_25a0b0dbbd0) * DAT_25a0b0e2570;
          MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
          dVar9 = runtime_double_result;
          MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
          if (param_3 == 0) {
            dVar9 = dVar9 - value_3;
          }
          else {
            dVar9 = value_3 - runtime_double_result;
          }
          if (dVar1 <= dVar9) {
            uVar7 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
            cVar4 = FUN_25a0b0d8150(uVar7 & 0xffffffff,value_3,dVar2);
            if (cVar4 != '\0') {
              cVar4 = FUN_25a0b0d2640(param_1,value_3,dVar2);
              if (cVar4 == '\0') {
                if (DAT_25a0b0e258f != '\0') {
                  FUN_25a0b0d1ba0();
                  FUN_25a0b0c05f0(&local_b8,&runtime_string_result,1,&PTR_DAT_25a0b0e1070);
                  MT5_Dispatch((void *)0x25a0930b4c8,0xd,3,0x590008,&string_ref_25a0b0df4b8,0x530014
                               ,DAT_25a0b0e2110,0x590008,&local_b8);
                }
                uVar8 = (ulonglong)DAT_25a0b0e258c;
              }
              else if (DAT_25a0b0e258f != '\0') {
                MT5_Dispatch((void *)0x25a0930b4c8,0xd,4,0x590008,&string_ref_25a0b0df458,0x580007,
                             param_2,0x580007,value_2,0x580007,value_3);
              }
            }
          }
        }
      }
    }
    else {
      uVar8 = 0;
    }
  }
LAB_25a0b0ce7d5:
  FUN_25a0b0c0000(&local_b8);
  return uVar8 & 0xffffffff;
}



/* Address: 25a0b0ce830 */

void FUN_25a0b0ce830(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulonglong uVar2;
  int *piVar3;
  undefined8 *puVar4;
  longlong lVar5;
  bool bVar6;
  
  piVar3 = (int *)&DAT_25a0b0e4920;
  puVar4 = &DAT_25a0b0e4720;
  uVar2 = (ulonglong)DAT_25a0b0e4920;
  if (0 < (int)DAT_25a0b0e4920) {
    if (DAT_25a0b0e4720 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 1) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4740 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 2) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4760 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 3) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4780 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 4) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e47a0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 5) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e47c0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 6) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e47e0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 7) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4800 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 8) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4820 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 9) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4840 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 10) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4860 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0xb) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4880 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0xc) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e48a0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0xd) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e48c0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0xe) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e48e0 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0xf) goto LAB_25a0b0cea1a;
    if (DAT_25a0b0e4900 == param_1) {
      return;
    }
    if (DAT_25a0b0e4920 == 0x10) {
      return;
    }
    param_1 = 0x25a0930b4c8;
    param_2 = 0x1f6;
    uVar2 = (*(code *)&runtime_memory_helper_3959a0)();
  }
  bVar6 = uVar2 != 0;
  uVar2 = 0;
  if (bVar6) {
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xf07b0000001f6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
LAB_25a0b0cea1a:
  lVar5 = uVar2 * 0x20;
  *piVar3 = (int)uVar2 + 1;
  puVar4[uVar2 * 4] = param_1;
  *(undefined4 *)(&DAT_25a0b0e4728 + lVar5) = param_2;
  *(undefined8 *)(&DAT_25a0b0e472c + lVar5) = param_3;
  *(undefined8 *)(&DAT_25a0b0e4734 + lVar5) = param_4;
  *(undefined4 *)(&DAT_25a0b0e473c + lVar5) = 0;
  return;
}



/* Address: 25a0b0cea90 */

void FUN_25a0b0cea90(ulonglong param_1,double param_2)

{
  double dVar1;
  code *pcVar2;
  double *pdVar3;
  longlong arg_1;
  longlong arg_1_00;
  int *piVar4;
  int local_68;
  int local_64;
  int local_60;
  int local_48;
  int local_44;
  int local_40;
  
  FUN_25a0b0ca870();
  if (param_2 <= 0.0) {
    if (param_2 < 0.0) {
      pdVar3 = &DAT_25a0b0e26a8;
      piVar4 = &DAT_25a0b0e2678;
      goto LAB_25a0b0cec09;
    }
  }
  else {
    pdVar3 = (double *)&DAT_25a0b0e26a0;
    piVar4 = &DAT_25a0b0e2674;
LAB_25a0b0cec09:
    dVar1 = *pdVar3;
    *piVar4 = *piVar4 + 1;
    *pdVar3 = dVar1 + param_2;
  }
  if (DAT_25a0b0e2690 < param_2) {
    DAT_25a0b0e2690 = param_2;
  }
  if (param_2 < DAT_25a0b0e2698) {
    DAT_25a0b0e2698 = param_2;
  }
  arg_1 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,param_1,2);
  arg_1_00 = MT5_TimeCurrent((void *)0x25a0930b4c8,(void *)0x0);
  MT5_TimeToStruct((void *)0x25a0930b4c8,arg_1_00,&local_48);
  MT5_TimeToStruct((void *)0x25a0930b4c8,arg_1,&local_68);
  if ((local_60 == local_40) && (local_64 == local_44)) {
    if (local_68 == local_48) {
      DAT_25a0b0e2680 = DAT_25a0b0e2680 + param_2;
    }
  }
  else if (local_64 != local_44) goto LAB_25a0b0cebba;
  if (local_68 == local_48) {
    DAT_25a0b0e2688 = param_2 + DAT_25a0b0e2688;
  }
LAB_25a0b0cebba:
  if (((DAT_25a0b0e26a8 < DAT_25a0b0dbbd8) && (DAT_25a0b0e26a8 == 0.0)) && (!NAN(DAT_25a0b0e26a8)))
  {
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2409bb000001f7);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  return;
}



/* Address: 25a0b0cec70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0cec70(ulonglong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  double dVar4;
  int iVar5;
  undefined8 uVar6;
  double value_5;
  bool bVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  MqlStringAnalysisView *pMVar17;
  int iVar18;
  ulonglong uVar19;
  int arg_3;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 local_140;
  longlong local_13c;
  undefined4 local_130;
  longlong local_12c;
  ulonglong local_120;
  undefined4 local_118;
  longlong local_114;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  longlong local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b0;
  undefined8 local_ac;
  longlong local_a0;
  
  if (!ShowPnLLabels) {
    return;
  }
  local_e8 = 0;
  local_130 = 0;
  local_118 = 0;
  local_140 = 0;
  local_d8 = 0;
  local_f8 = 0;
  local_e4 = 0;
  local_12c = 0;
  local_114 = 0;
  local_13c = 0;
  local_d4 = 0;
  local_f4 = 0;
  bVar7 = MT5_HistoryDealSelect((void *)0x25a0930b4c8,param_1);
  if (!bVar7) goto LAB_25a0b0d04fc;
  lVar11 = MT5_HistoryDealGetInteger((void *)0x25a0930b4c8,param_1,2);
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,param_1,6);
  value_5 = runtime_double_result;
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,param_1,9);
  dVar4 = runtime_double_result;
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,param_1,8);
  dVar22 = runtime_double_result;
  MT5_HistoryDealGetDouble((void *)0x25a0930b4c8,param_1,7);
  if ((lVar11 < 1) || (value_5 <= 0.0)) goto LAB_25a0b0d04fc;
  pMVar17 = &string_ref_25a0b0dc170;
  local_d8 = 0;
  local_d4 = 0;
  dVar4 = dVar4 + dVar22 + runtime_double_result;
  if (0.0 <= dVar4) {
    pMVar17 = &string_ref_25a0b0df338;
  }
  MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,2);
  FUN_25a0b0c05f0(&local_140,&runtime_string_result,1,&PTR_DAT_25a0b0e0f80);
  FUN_25a0b0c05f0(&local_118,pMVar17);
  lVar2 = local_13c;
  if (local_13c == 0) {
LAB_25a0b0cefcd:
    uVar9 = 0;
    FUN_25a0b0c05f0(&local_130,&local_118,0,&PTR_DAT_25a0b0e0fa0);
    uVar15 = DAT_25a0b0de874;
    uVar14 = (ulonglong)DAT_25a0b0de874;
    if ((uVar14 != 0) || (local_12c == 0)) {
      if (local_12c != 0) {
        uVar9 = *(uint *)(local_12c + -4);
      }
      uVar16 = DAT_25a0b0de874 + uVar9;
      uVar12 = 0x104;
      if ((0x103 < uVar16) &&
         ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
        uVar12 = 0x7ffffffe;
      }
      cVar8 = FUN_25a0b0c0060(&local_130,uVar12);
      if (cVar8 == '\0') {
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x400759000001f9);
        goto LAB_25a0b0d05bd;
      }
      if (uVar14 != 0) {
        lVar2 = local_12c + (ulonglong)uVar9 * 2;
        if (uVar15 < 0x10) {
          uVar13 = 0;
        }
        else if (lVar2 - 0x25a0b0de878U < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar19 = 0;
          uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
          do {
            uVar6 = *(undefined8 *)(uVar19 + 0x25a0b0de880);
            *(undefined8 *)(lVar2 + uVar19) = *(undefined8 *)((longlong)&DAT_25a0b0de878 + uVar19);
            ((undefined8 *)(lVar2 + uVar19))[1] = uVar6;
            uVar19 = uVar19 + 0x10;
          } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
          if (uVar13 == uVar14) goto LAB_25a0b0cf0f2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar13 * 2) = (&DAT_25a0b0de878)[uVar13];
          uVar13 = uVar13 + 1;
        } while (uVar14 != uVar13);
      }
LAB_25a0b0cf0f2:
      *(uint *)(local_12c + -4) = uVar16;
      *(undefined2 *)(local_12c + (ulonglong)uVar16 * 2) = 0;
    }
    local_c8 = lVar11;
    FUN_25a0b0c05f0(&local_e8,&local_130,0);
    lVar11 = DAT_25a0b0e2584;
    if (DAT_25a0b0e2584 != 0) {
      uVar9 = *(uint *)(DAT_25a0b0e2584 + -4);
      uVar14 = (ulonglong)uVar9;
      if ((uVar14 != 0) || (local_e4 == 0)) {
        if (local_e4 == 0) {
          uVar13 = 0;
          uVar15 = uVar9;
        }
        else {
          uVar13 = (ulonglong)*(uint *)(local_e4 + -4);
          uVar15 = uVar9 + *(uint *)(local_e4 + -4);
        }
        cVar8 = FUN_25a0b0c0060(&local_e8);
        if (cVar8 == '\0') goto LAB_25a0b0d05dd;
        if (uVar14 != 0) {
          lVar2 = local_e4 + uVar13 * 2;
          if (uVar9 < 0x10) {
            uVar13 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar11) < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar9 & 0xfffffff8);
            do {
              uVar6 = ((undefined8 *)(lVar11 + uVar19))[1];
              *(undefined8 *)(lVar2 + uVar19) = *(undefined8 *)(lVar11 + uVar19);
              ((undefined8 *)(lVar2 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0cf232;
          }
          do {
            *(undefined2 *)(lVar2 + uVar13 * 2) = *(undefined2 *)(lVar11 + uVar13 * 2);
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0cf232:
        *(uint *)(local_e4 + -4) = uVar15;
        *(undefined2 *)(local_e4 + (ulonglong)uVar15 * 2) = 0;
      }
    }
    FUN_25a0b0c05f0(&local_d8,&local_e8,0,&PTR_DAT_25a0b0e0fc0);
    uVar9 = MT5_iBarShift((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,local_c8,true);
    if (((-1 < (int)uVar9) ||
        (uVar9 = MT5_iBarShift((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,local_c8,false),
        -1 < (int)uVar9)) &&
       (iVar10 = (*(code *)&MT5_Bars)(0x25a0930b4c8,&DAT_25a0b0dc150,_Period), 9 < iVar10)) {
      local_120 = param_1;
      MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x10);
      dVar22 = runtime_double_result;
      MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,uVar9);
      dVar20 = runtime_double_result;
      MT5_iLow((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,uVar9);
      dVar20 = dVar20 - runtime_double_result;
      uVar23 = (undefined4)DAT_25a0b0dbc08;
      uVar24 = (undefined4)((ulonglong)DAT_25a0b0dbc08 >> 0x20);
      if (uVar9 < 2) {
        iVar10 = 0;
        do {
          MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,iVar10);
          if ((double)CONCAT44(uVar24,uVar23) <= runtime_double_result) {
            uVar23 = SUB84(runtime_double_result,0);
            uVar24 = (undefined4)((ulonglong)runtime_double_result >> 0x20);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 <= (int)(uVar9 | 2));
        iVar18 = 1;
        local_a0 = 5;
      }
      else {
        arg_3 = uVar9 - 2;
        iVar18 = -1;
        iVar5 = iVar10 + -1;
        if ((int)(uVar9 + 1) <= iVar10 + -1) {
          iVar5 = uVar9 + 1;
        }
        local_a0 = 1;
        if (arg_3 <= iVar5) {
          do {
            MT5_iHigh((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,arg_3);
            if ((double)CONCAT44(uVar24,uVar23) <= runtime_double_result) {
              uVar23 = SUB84(runtime_double_result,0);
              uVar24 = (undefined4)((ulonglong)runtime_double_result >> 0x20);
            }
            arg_3 = arg_3 + 1;
          } while (arg_3 <= iVar5);
          iVar18 = -1;
        }
      }
      uVar14 = local_120;
      uVar13 = (ulonglong)(iVar18 + uVar9);
      local_120 = MT5_iTime((void *)0x25a0930b4c8,&DAT_25a0b0dc150,_Period,iVar18 + uVar9);
      local_f8 = 0;
      local_f4 = 0;
      MT5_IntegerToString((void *)0x25a0930b4c8,uVar14,0,(int)CONCAT62((int6)(uVar13 >> 0x10),0x20))
      ;
      FUN_25a0b0c05f0(&local_140,&runtime_string_result,1,&PTR_DAT_25a0b0e0fd0);
      FUN_25a0b0c05f0(&local_118,&string_ref_25a0b0df370);
      lVar2 = local_c8;
      lVar11 = local_13c;
      if (local_13c != 0) {
        uVar9 = *(uint *)(local_13c + -4);
        uVar14 = (ulonglong)uVar9;
        if ((uVar14 != 0) || (local_114 == 0)) {
          if (local_114 == 0) {
            uVar15 = 0;
          }
          else {
            uVar15 = *(uint *)(local_114 + -4);
          }
          cVar8 = FUN_25a0b0c0060(&local_118);
          if (cVar8 == '\0') goto LAB_25a0b0d069d;
          if (uVar14 != 0) {
            lVar1 = local_114 + (ulonglong)uVar15 * 2;
            if (uVar9 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar11) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar19 = 0;
              uVar13 = (ulonglong)(uVar9 & 0xfffffff8);
              do {
                uVar6 = ((undefined8 *)(lVar11 + uVar19))[1];
                *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)(lVar11 + uVar19);
                ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
                uVar19 = uVar19 + 0x10;
              } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar13 == uVar14) goto LAB_25a0b0cf612;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar11 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar14 != uVar13);
          }
LAB_25a0b0cf612:
          *(uint *)(local_114 + -4) = uVar9 + uVar15;
          *(undefined2 *)(local_114 + (ulonglong)(uVar9 + uVar15) * 2) = 0;
        }
      }
      uVar9 = 0;
      FUN_25a0b0c05f0(&local_f8,&local_118,0,&PTR_DAT_25a0b0e0ff0);
      FUN_25a0b0c05f0(&local_140,&string_ref_25a0b0dc2b8,0,&PTR_DAT_25a0b0e1000);
      FUN_25a0b0c05f0(&local_118,&local_d8,0,&PTR_DAT_25a0b0e1010);
      FUN_25a0b0c05f0(&local_130,&local_f8,0,&PTR_DAT_25a0b0e1020);
      uVar15 = DAT_25a0b0df388;
      uVar14 = (ulonglong)DAT_25a0b0df388;
      if ((uVar14 != 0) || (local_12c == 0)) {
        if (local_12c != 0) {
          uVar9 = *(uint *)(local_12c + -4);
        }
        uVar16 = DAT_25a0b0df388 + uVar9;
        uVar12 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_130,uVar12);
        if (cVar8 == '\0') goto LAB_25a0b0d05fd;
        if (uVar14 != 0) {
          lVar11 = local_12c + (ulonglong)uVar9 * 2;
          if (uVar15 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar11 - 0x25a0b0df38cU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar6 = *(undefined8 *)((longlong)u_value_25a0b0df38e + uVar19 + 6);
              *(undefined8 *)(lVar11 + uVar19) =
                   *(undefined8 *)((longlong)&DAT_25a0b0df38c + uVar19);
              ((undefined8 *)(lVar11 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0cf7b2;
          }
          do {
            *(undefined2 *)(lVar11 + uVar13 * 2) = (&DAT_25a0b0df38c)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0cf7b2:
        *(uint *)(local_12c + -4) = uVar16;
        *(undefined2 *)(local_12c + (ulonglong)uVar16 * 2) = 0;
      }
      dVar21 = (double)((ulonglong)dVar20 & _DAT_25a0b0dbbe0) * DAT_25a0b0dbbf8;
      dVar20 = DAT_25a0b0dbbf0 * dVar22;
      if (dVar20 <= dVar21) {
        dVar20 = dVar21;
      }
      dVar22 = (double)(~-(ulonglong)(0.0 < dVar20) & (ulonglong)(dVar22 * DAT_25a0b0dbc00) |
                       (ulonglong)dVar20 & -(ulonglong)(0.0 < dVar20)) +
               (double)CONCAT44(uVar24,uVar23);
      iVar10 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&local_130);
      if (iVar10 < 0) {
        MT5_Dispatch((void *)0x25a0930b4c8,0x112,6,0x550005,0,0x590008,&local_130,0x520004,0x65,
                     0x520004,0,0x540005,local_120,0x580007,dVar22);
      }
      else {
        (*(code *)0x7ff6537a39d0)(0x25a0930b4c8,0,&local_130,0,local_120,dVar22);
      }
      uVar9 = 0;
      MT5_ObjectSetString((void *)0x25a0930b4c8,0,&local_130,6,&local_118);
      MT5_ObjectSetString((void *)0x25a0930b4c8,0,&local_130,0x3e9,&local_140);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,0x3ea,0xc);
      lVar11 = 0x7852ff;
      if (0.0 <= dVar4) {
        lVar11 = 0xaaeb00;
      }
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,0,lVar11);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,0x3f3,local_a0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,3,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,10,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,0xd0,1);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_130,0xcf,0x1a);
      FUN_25a0b0c05f0(&local_140,&local_f8,0,&PTR_DAT_25a0b0e1030);
      uVar15 = DAT_25a0b0df3a8;
      uVar14 = (ulonglong)DAT_25a0b0df3a8;
      if ((uVar14 != 0) || (local_13c == 0)) {
        if (local_13c != 0) {
          uVar9 = *(uint *)(local_13c + -4);
        }
        uVar16 = DAT_25a0b0df3a8 + uVar9;
        uVar12 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_140,uVar12);
        if (cVar8 == '\0') goto LAB_25a0b0d061d;
        if (uVar14 != 0) {
          lVar1 = local_13c + (ulonglong)uVar9 * 2;
          if (uVar15 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar1 - 0x25a0b0df3acU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar6 = *(undefined8 *)(uVar19 + 0x25a0b0df3b4);
              *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)((longlong)&DAT_25a0b0df3ac + uVar19)
              ;
              ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0cfb62;
          }
          do {
            *(undefined2 *)(lVar1 + uVar13 * 2) = (&DAT_25a0b0df3ac)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0cfb62:
        *(uint *)(local_13c + -4) = uVar16;
        *(undefined2 *)(local_13c + (ulonglong)uVar16 * 2) = 0;
      }
      local_108 = 0;
      local_b0 = 0;
      local_104 = 0;
      local_bc = 0;
      local_ac = 0;
      uVar9 = 0;
      FUN_25a0b0c05f0(&local_108,&local_140,0,&PTR_DAT_25a0b0e0f40);
      uVar15 = DAT_25a0b0df2f8;
      uVar14 = (ulonglong)DAT_25a0b0df2f8;
      if ((uVar14 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar9 = *(uint *)(local_104 + -4);
        }
        uVar16 = DAT_25a0b0df2f8 + uVar9;
        uVar12 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_108,uVar12);
        if (cVar8 == '\0') goto LAB_25a0b0d063d;
        if (uVar14 != 0) {
          lVar1 = local_104 + (ulonglong)uVar9 * 2;
          if (uVar15 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar1 - 0x25a0b0df2fcU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar6 = *(undefined8 *)(uVar19 + 0x25a0b0df304);
              *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)((longlong)&DAT_25a0b0df2fc + uVar19)
              ;
              ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0cfce2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar13 * 2) = (&DAT_25a0b0df2fc)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0cfce2:
        *(uint *)(local_104 + -4) = uVar16;
        *(undefined2 *)(local_104 + (ulonglong)uVar16 * 2) = 0;
      }
      uVar9 = 0;
      FUN_25a0b0c05f0(&local_b0,&local_108,0,&PTR_DAT_25a0b0e0f50);
      local_c0 = 0;
      local_bc = 0;
      FUN_25a0b0c05f0(&local_108,&local_140,0,&PTR_DAT_25a0b0e0f60);
      uVar15 = DAT_25a0b0df318;
      uVar14 = (ulonglong)DAT_25a0b0df318;
      if ((uVar14 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar9 = *(uint *)(local_104 + -4);
        }
        uVar16 = DAT_25a0b0df318 + uVar9;
        uVar12 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_108,uVar12);
        if (cVar8 == '\0') goto LAB_25a0b0d065d;
        if (uVar14 != 0) {
          lVar1 = local_104 + (ulonglong)uVar9 * 2;
          if (uVar15 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar1 - 0x25a0b0df31cU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar6 = *(undefined8 *)(uVar19 + 0x25a0b0df324);
              *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)((longlong)&DAT_25a0b0df31c + uVar19)
              ;
              ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0cfe52;
          }
          do {
            *(undefined2 *)(lVar1 + uVar13 * 2) = (&DAT_25a0b0df31c)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0cfe52:
        *(uint *)(local_104 + -4) = uVar16;
        *(undefined2 *)(local_104 + (ulonglong)uVar16 * 2) = 0;
      }
      FUN_25a0b0c05f0(&local_c0,&local_108,0,&PTR_DAT_25a0b0e0f70);
      iVar10 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&local_b0);
      if (iVar10 < 0) {
        MT5_Dispatch((void *)0x25a0930b4c8,0x112,6,0x550005,0,0x590008,&local_b0,0x520004,100,
                     0x520004,0,0x540005,lVar2,0x580007,value_5);
      }
      (*(code *)0x7ff6537a39d0)(0x25a0930b4c8,0,&local_b0,0,lVar2,value_5);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,0x3f0,0x9f);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,0,0xcc3f7a);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,2,5);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,0x3f3,8);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,3,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,10,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,0xd0,1);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_b0,0xcf,0x1a);
      iVar10 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&local_c0);
      if (iVar10 < 0) {
        MT5_Dispatch((void *)0x25a0930b4c8,0x112,6,0x550005,0,0x590008,&local_c0,0x520004,100,
                     0x520004,0,0x540005,lVar2,0x580007,value_5);
      }
      uVar9 = 0;
      (*(code *)0x7ff6537a39d0)(0x25a0930b4c8,0,&local_c0,0,lVar2,value_5);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,0x3f0,0x9f);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,0,lVar11);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,2,2);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,0x3f3,8);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,3,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,10,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,0xd0,1);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_c0,0xcf,0x1b);
      FUN_25a0b0c0000(&local_c0);
      FUN_25a0b0c0000(&local_b0);
      FUN_25a0b0c0000(&local_108);
      FUN_25a0b0c05f0(&local_140,&local_f8,0,&PTR_DAT_25a0b0e1040);
      uVar15 = DAT_25a0b0df3c8;
      uVar14 = (ulonglong)DAT_25a0b0df3c8;
      if ((uVar14 != 0) || (local_13c == 0)) {
        if (local_13c != 0) {
          uVar9 = *(uint *)(local_13c + -4);
        }
        uVar16 = DAT_25a0b0df3c8 + uVar9;
        uVar12 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar8 = FUN_25a0b0c0060(&local_140,uVar12);
        if (cVar8 == '\0') goto LAB_25a0b0d067d;
        if (uVar14 != 0) {
          lVar1 = local_13c + (ulonglong)uVar9 * 2;
          if (uVar15 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar1 - 0x25a0b0df3ccU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar19 = 0;
            uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar6 = *(undefined8 *)((longlong)u_link_25a0b0df3ce + uVar19 + 6);
              *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)((longlong)&DAT_25a0b0df3cc + uVar19)
              ;
              ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar13 == uVar14) goto LAB_25a0b0d02f2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar13 * 2) = (&DAT_25a0b0df3cc)[uVar13];
            uVar13 = uVar13 + 1;
          } while (uVar14 != uVar13);
        }
LAB_25a0b0d02f2:
        *(uint *)(local_13c + -4) = uVar16;
        *(undefined2 *)(local_13c + (ulonglong)uVar16 * 2) = 0;
      }
      iVar10 = MT5_ObjectFind((void *)0x25a0930b4c8,0,&local_140);
      if (iVar10 < 0) {
        MT5_Dispatch((void *)0x25a0930b4c8,0x112,8,0x550005,0,0x590008,&local_140,0x520004,2,
                     0x520004,0,0x540005,lVar2,0x580007,value_5,0x540005,local_120,0x580007,dVar22);
      }
      (*(code *)0x7ff6537a39d0)(0x25a0930b4c8,0,&local_140,0,lVar2,value_5);
      (*(code *)0x7ff6537a39d0)(0x25a0930b4c8,0,&local_140,1,local_120,dVar22);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,0,lVar11);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,1,2);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,2,1);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,0x3ec,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,3,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,10,0);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,0xd0,1);
      MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,&local_140,0xcf,0x16);
      FUN_25a0b0c0000(&local_f8);
    }
    FUN_25a0b0c0000(&local_d8);
LAB_25a0b0d04fc:
    FUN_25a0b0c0000(&local_140);
    FUN_25a0b0c0000(&local_118);
    FUN_25a0b0c0000(&local_130);
    FUN_25a0b0c0000(&local_e8);
    if ((DAT_25a0b0e258c == '\0') || (DAT_25a0b0e258e != '\0')) {
      (*(code *)0x7ff6537a51b0)(0x25a0930b4c8,0);
    }
    return;
  }
  uVar9 = *(uint *)(local_13c + -4);
  uVar14 = (ulonglong)uVar9;
  if ((uVar14 == 0) && (local_114 != 0)) goto LAB_25a0b0cefcd;
  if (local_114 == 0) {
    uVar13 = 0;
    uVar15 = uVar9;
  }
  else {
    uVar13 = (ulonglong)*(uint *)(local_114 + -4);
    uVar15 = uVar9 + *(uint *)(local_114 + -4);
  }
  cVar8 = FUN_25a0b0c0060(&local_118);
  if (cVar8 != '\0') {
    if (uVar14 != 0) {
      lVar1 = local_114 + uVar13 * 2;
      if (uVar9 < 0x10) {
        uVar13 = 0;
      }
      else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
        uVar13 = 0;
      }
      else {
        uVar19 = 0;
        uVar13 = (ulonglong)(uVar9 & 0xfffffff8);
        do {
          uVar6 = ((undefined8 *)(lVar2 + uVar19))[1];
          *(undefined8 *)(lVar1 + uVar19) = *(undefined8 *)(lVar2 + uVar19);
          ((undefined8 *)(lVar1 + uVar19))[1] = uVar6;
          uVar19 = uVar19 + 0x10;
        } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar19);
        if (uVar13 == uVar14) goto LAB_25a0b0cefc2;
      }
      do {
        *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar2 + uVar13 * 2);
        uVar13 = uVar13 + 1;
      } while (uVar14 != uVar13);
    }
LAB_25a0b0cefc2:
    *(uint *)(local_114 + -4) = uVar15;
    *(undefined2 *)(local_114 + (ulonglong)uVar15 * 2) = 0;
    goto LAB_25a0b0cefcd;
  }
LAB_25a0b0d05bd:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x270759000001f9);
LAB_25a0b0d05dd:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x440759000001f9);
LAB_25a0b0d05fd:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x19075e000001f9);
LAB_25a0b0d061d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x17075f000001f9);
LAB_25a0b0d063d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x140734000001f9);
LAB_25a0b0d065d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x240734000001f9);
LAB_25a0b0d067d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1a0760000001f9);
LAB_25a0b0d069d:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x16075d000001f9);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 25a0b0d06c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d06c0(void)

{
  int iVar1;
  longlong lVar2;
  
  DAT_25a0b0e4d28 = 0xffffffffffffffff;
  DAT_25a0b0e4d24 = 0;
  DAT_25a0b0e4d30 = 0xffffffffffffffff;
  DAT_25a0b0e4c88 = 0x230;
  DAT_25a0b0e4c84 = 0x1ae;
  DAT_25a0b0e4c80 = 0;
  DAT_25a0b0e4950 = 0;
  DAT_25a0b0e4948 = 0;
  DAT_25a0b0e4940 = 0;
  DAT_25a0b0e4938 = 0;
  DAT_25a0b0e4930 = 0;
  DAT_25a0b0e4928 = 0;
  DAT_25a0b0e4920 = 0;
  DAT_25a0b0e4718 = 0;
  DAT_25a0b0e4710 = 0;
  DAT_25a0b0e470c = 0;
  string_ref_25a0b0e4700.opaque = 0;
  string_ref_25a0b0e4700.text = (wchar16 *)0x0;
  FUN_25a0b0c05f0(&string_ref_25a0b0e4700,&string_ref_25a0b0dc280,0,&PTR_DAT_25a0b0dfd00);
  string_ref_25a0b0e46f0.opaque = 0;
  string_ref_25a0b0e46f0.text = (wchar16 *)0x0;
  FUN_25a0b0c05f0(&string_ref_25a0b0e46f0,&string_ref_25a0b0dc240,0,&PTR_DAT_25a0b0dfd10);
  DAT_25a0b0e46e9 = 0;
  DAT_25a0b0e46e8 = 0;
  DAT_25a0b0e46ea = 0;
  DAT_25a0b0e46e4 = 0xffffffff;
  DAT_25a0b0e46e0 = 0;
  memset(&DAT_25a0b0e3ae0,0,0xc00);
  memset(&DAT_25a0b0e2ee0,0,0xc00);
  DAT_25a0b0e26ce = 1;
  DAT_25a0b0e26cd = 1;
  DAT_25a0b0e26d0 = 0;
  DAT_25a0b0e26cc = 1;
  string_ref_25a0b0e26c0.opaque = 0;
  string_ref_25a0b0e26c0.text = (wchar16 *)0x0;
  FUN_25a0b0c05f0(&string_ref_25a0b0e26c0,&string_ref_25a0b0dc200,0,&PTR_DAT_25a0b0dfd20);
  DAT_25a0b0e26b0 = 0xbff0000000000000;
  DAT_25a0b0e26a8 = 0;
  DAT_25a0b0e26b8 = 0;
  DAT_25a0b0e26a0 = 0;
  DAT_25a0b0e2698 = 0;
  DAT_25a0b0e2690 = 0;
  DAT_25a0b0e2688 = 0;
  DAT_25a0b0e2680 = 0;
  DAT_25a0b0e2678 = 0;
  DAT_25a0b0e2674 = 0;
  DAT_25a0b0e2670 = 0;
  DAT_25a0b0e266c = 0;
  DAT_25a0b0e2668 = 1;
  DAT_25a0b0e2660 = 0;
  DAT_25a0b0e2658 = 0;
  state_v_22650 = 0.0;
  state_v_22648 = 0.0;
  state_v_22640 = 0.0;
  state_v_22638 = 0.0;
  state_v_22630 = 0.0;
  DAT_25a0b0e2628 = 0xc000000000000000;
  DAT_25a0b0e2620 = 0xc000000000000000;
  DAT_25a0b0e2610 = 0;
  DAT_25a0b0e2618 = 0;
  DAT_25a0b0e2600 = 0;
  DAT_25a0b0e2608 = 0;
  DAT_25a0b0e25f0 = 0;
  DAT_25a0b0e25f8 = 0;
  DAT_25a0b0e25e0 = 0;
  DAT_25a0b0e25e8 = 0;
  state_v_225d0 = 0.0;
  DAT_25a0b0e25d8 = 0;
  state_v_225c8 = 0.5;
  state_v_225c4 = 3;
  state_v_225c0 = false;
  state_v_225b8 = 10.0;
  state_v_225b0 = 0.01;
  state_v_225ad = false;
  DAT_25a0b0e25ac = 0;
  DAT_25a0b0e25a8 = 0;
  DAT_25a0b0e25a0 = 0;
  DAT_25a0b0e2598 = 0;
  DAT_25a0b0e2594 = 0;
  DAT_25a0b0e2590 = 0;
  DAT_25a0b0e258f = 0;
  DAT_25a0b0e258e = 0;
  DAT_25a0b0e258d = 0;
  DAT_25a0b0e258c = 0;
  DAT_25a0b0e2580 = 0;
  DAT_25a0b0e2584 = 0;
  FUN_25a0b0c05f0(&DAT_25a0b0e2580,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0dfd30);
  DAT_25a0b0e2570 = 0;
  DAT_25a0b0e2568 = 0;
  DAT_25a0b0e2578 = 0;
  DAT_25a0b0e2530 = 0x800010058;
  DAT_25a0b0e2538 = 0;
  DAT_25a0b0e2540 = 0;
  DAT_25a0b0e2548 = 0;
  DAT_25a0b0e2550 = 0;
  DAT_25a0b0e2558 = 0;
  DAT_25a0b0e2560 = 0;
  DAT_25a0b0e24f0 = 0x800010058;
  _DAT_25a0b0e24f8 = 0;
  DAT_25a0b0e2500 = 0;
  DAT_25a0b0e2508 = 0;
  DAT_25a0b0e2510 = 0;
  DAT_25a0b0e2518 = 0;
  DAT_25a0b0e2520 = 0;
  DAT_25a0b0e24b0 = 0x800010058;
  DAT_25a0b0e24e0 = 0;
  DAT_25a0b0e24d8 = 0;
  DAT_25a0b0e24d0 = 0;
  DAT_25a0b0e24c8 = 0;
  DAT_25a0b0e24c0 = 0;
  _DAT_25a0b0e24b8 = 0;
  DAT_25a0b0e2470 = 0x800010058;
  _DAT_25a0b0e2478 = 0;
  DAT_25a0b0e2480 = 0;
  DAT_25a0b0e2488 = 0;
  DAT_25a0b0e2490 = 0;
  DAT_25a0b0e2498 = 0;
  DAT_25a0b0e24a0 = 0;
  DAT_25a0b0e2430 = 0x800010058;
  _DAT_25a0b0e2438 = 0;
  DAT_25a0b0e2440 = 0;
  DAT_25a0b0e2448 = 0;
  DAT_25a0b0e2450 = 0;
  DAT_25a0b0e2458 = 0;
  DAT_25a0b0e2460 = 0;
  DAT_25a0b0e23f0 = 0x800010058;
  DAT_25a0b0e2400 = 0;
  DAT_25a0b0e23f8 = 0;
  DAT_25a0b0e2410 = 0;
  DAT_25a0b0e2408 = 0;
  DAT_25a0b0e2420 = 0;
  DAT_25a0b0e2418 = 0;
  DAT_25a0b0e23dc = 0xffffffff;
  DAT_25a0b0e23e0 = 1;
  DAT_25a0b0e23d4 = 0xffffffff;
  DAT_25a0b0e23d8 = 0xffffffff;
  DAT_25a0b0e23cc = 0xffffffff;
  DAT_25a0b0e23d0 = 0xffffffff;
  DAT_25a0b0e236a = 1;
  DAT_25a0b0e236b = 1;
  DAT_25a0b0e2368 = 1;
  DAT_25a0b0e2369 = 1;
  (*(code *)&runtime_object_register)(0x25a0930b4c8,0x25a0929a310,&DAT_25a0b0e2000);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2000,0x25a0932c8d0);
  PTR_PTR_25a0b0e2008 = &DAT_25a0b0dbfd0;
  _DAT_25a0b0e2010 = 0;
  uRam0000025a0b0e2018 = 0;
  DAT_25a0b0e2034 = 0;
  DAT_25a0b0e2038 = 0;
  DAT_25a0b0e2084 = 0;
  DAT_25a0b0e2088 = 0;
  DAT_25a0b0e2144 = 0;
  DAT_25a0b0e2148 = 0;
  DAT_25a0b0e2208 = 0;
  DAT_25a0b0e220c = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2000,0x25a092f9c70);
  PTR_PTR_25a0b0e2008 = &DAT_25a0b0dc010;
  _DAT_25a0b0e2010 = 0;
  uRam0000025a0b0e2018 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2000,0x25a0929a310);
  PTR_PTR_25a0b0e2008 = (undefined *)&PTR_FUN_25a0b0dc0d0;
  state_v_22294 = false;
  state_v_22295 = 0;
  state_v_2229d = 10;
  state_v_222a5 = 0;
  DAT_25a0b0e22ad = 1;
  lVar2 = MT5_AccountInfoInteger((void *)0x25a0930b4c8,0x35);
  _DAT_25a0b0e2020 = 0;
  ram0x025a0b0e2028 = 0;
  DAT_25a0b0e202c._4_4_ = 0;
  DAT_25a0b0e22a9 = (int)lVar2;
  FUN_25a0b0c0000(&DAT_25a0b0e2034);
  DAT_25a0b0e2050 = 0;
  DAT_25a0b0e2058 = 0;
  DAT_25a0b0e2060 = 0;
  uRam0000025a0b0e2068 = 0;
  _DAT_25a0b0e2070 = 0;
  _DAT_25a0b0e2078 = 0;
  DAT_25a0b0e207c._4_4_ = 0;
  DAT_25a0b0e2040 = 0;
  DAT_25a0b0e2048 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2084);
  _DAT_25a0b0e2120 = 0;
  uRam0000025a0b0e2128 = 0;
  _DAT_25a0b0e2110 = 0;
  uRam0000025a0b0e2118 = 0;
  _DAT_25a0b0e2130 = 0;
  uRam0000025a0b0e2138 = 0;
  _DAT_25a0b0e2100 = 0;
  uRam0000025a0b0e2108 = 0;
  _DAT_25a0b0e20f0 = 0;
  uRam0000025a0b0e20f8 = 0;
  _DAT_25a0b0e20e0 = 0;
  uRam0000025a0b0e20e8 = 0;
  _DAT_25a0b0e20d0 = 0;
  uRam0000025a0b0e20d8 = 0;
  _DAT_25a0b0e20c0 = 0;
  uRam0000025a0b0e20c8 = 0;
  _DAT_25a0b0e20b0 = 0;
  uRam0000025a0b0e20b8 = 0;
  _DAT_25a0b0e20a0 = 0;
  uRam0000025a0b0e20a8 = 0;
  DAT_25a0b0e2090 = 0;
  uRam0000025a0b0e2098 = 0;
  DAT_25a0b0e2140 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2144);
  _DAT_25a0b0e21e0 = 0;
  uRam0000025a0b0e21e8 = 0;
  _DAT_25a0b0e21d0 = 0;
  uRam0000025a0b0e21d8 = 0;
  _DAT_25a0b0e21f0 = 0;
  uRam0000025a0b0e21f8 = 0;
  _DAT_25a0b0e21c0 = 0;
  uRam0000025a0b0e21c8 = 0;
  _DAT_25a0b0e21b0 = 0;
  uRam0000025a0b0e21b8 = 0;
  _DAT_25a0b0e21a0 = 0;
  uRam0000025a0b0e21a8 = 0;
  _DAT_25a0b0e2190 = 0;
  uRam0000025a0b0e2198 = 0;
  _DAT_25a0b0e2180 = 0;
  uRam0000025a0b0e2188 = 0;
  _DAT_25a0b0e2170 = 0;
  uRam0000025a0b0e2178 = 0;
  _DAT_25a0b0e2160 = 0;
  uRam0000025a0b0e2168 = 0;
  _DAT_25a0b0e2150 = 0;
  uRam0000025a0b0e2158 = 0;
  DAT_25a0b0e2200 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2208);
  DAT_25a0b0e227c = 0;
  DAT_25a0b0e2284 = 0;
  DAT_25a0b0e228c = 0;
  DAT_25a0b0e226c = 0;
  DAT_25a0b0e2274 = 0;
  DAT_25a0b0e2214 = 0;
  DAT_25a0b0e225c = 0;
  DAT_25a0b0e2264 = 0;
  DAT_25a0b0e224c = 0;
  DAT_25a0b0e2254 = 0;
  DAT_25a0b0e223c = 0;
  DAT_25a0b0e2244 = 0;
  DAT_25a0b0e222c = 0;
  DAT_25a0b0e2234 = 0;
  DAT_25a0b0e221c = 0;
  DAT_25a0b0e2224 = 0;
  iVar1 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,6);
  if (iVar1 != 0) {
    DAT_25a0b0e22ad = 2;
  }
  iVar1 = MT5_MQLInfoInteger((void *)0x25a0930b4c8,7);
  if (iVar1 != 0) {
    DAT_25a0b0e22ad = 0;
  }
  (*(code *)&runtime_object_register)(0x25a0930b4c8,0x25a0b7ac700,&DAT_25a0b0e22c0);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e22c0,0x25a0932c8d0);
  PTR_PTR_25a0b0e22c8 = &DAT_25a0b0dbfd0;
  _DAT_25a0b0e22d0 = 0;
  uRam0000025a0b0e22d8 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e22c0,0x25a092f9c70);
  PTR_PTR_25a0b0e22c8 = &DAT_25a0b0dc010;
  _DAT_25a0b0e22d0 = 0;
  uRam0000025a0b0e22d8 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e22c0,0x25a0b7ac700);
  PTR_PTR_25a0b0e22c8 = (undefined *)&PTR_thunk_FUN_25a0b0c0a90_25a0b0dc090;
  DAT_25a0b0e22e0 = 0xffffffff;
  DAT_25a0b0e22e4 = 0;
  DAT_25a0b0e22ec = 0;
  DAT_25a0b0e22f4 = 0;
  DAT_25a0b0e22fc = 0;
  (*(code *)&runtime_object_register)(0x25a0930b4c8,0x25a09331210,&DAT_25a0b0e2310);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2310,0x25a0932c8d0);
  PTR_PTR_25a0b0e2318 = &DAT_25a0b0dbfd0;
  _DAT_25a0b0e2320 = 0;
  uRam0000025a0b0e2328 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2310,0x25a092f9c70);
  PTR_PTR_25a0b0e2318 = &DAT_25a0b0dc010;
  _DAT_25a0b0e2320 = 0;
  uRam0000025a0b0e2328 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2310,0x25a09331210);
  PTR_PTR_25a0b0e2318 = (undefined *)&PTR_FUN_25a0b0dc050;
  DAT_25a0b0e2330._0_4_ = 0xffffffff;
  DAT_25a0b0e2330._4_4_ = 0xffffffff;
  uRam0000025a0b0e2338 = 0xffffffff;
  uRam0000025a0b0e233c = 0xffffffff;
  _DAT_25a0b0e2340 = 0;
  uRam0000025a0b0e2348 = 0;
  _DAT_25a0b0e2350 = 0;
  uRam0000025a0b0e2358 = 0;
  DAT_25a0b0e2360 = 0;
  (*(code *)&runtime_object_register)(0x25a0930b4c8,0x25a09346080,&DAT_25a0b0e4c90);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e4c90,0x25a0932c8d0);
  PTR_PTR_25a0b0e4c98 = &DAT_25a0b0dbfd0;
  DAT_25a0b0e4cb0 = 0;
  DAT_25a0b0e4cb4 = 0;
  DAT_25a0b0e4cc0 = 0;
  DAT_25a0b0e4cc4 = 0;
  string_ref_25a0b0e4cd8.opaque = 0;
  string_ref_25a0b0e4cd8.text = (wchar16 *)0x0;
  DAT_25a0b0e4cf0 = 0x400010053;
  _DAT_25a0b0e4cf8 = 0;
  _DAT_25a0b0e4d00 = 0;
  DAT_25a0b0e4d08 = 0;
  DAT_25a0b0e4d10 = 0;
  DAT_25a0b0e4d18 = 0;
  DAT_25a0b0e4d20 = 0;
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e4c90,0x25a09346080);
  PTR_PTR_25a0b0e4c98 = (undefined *)&PTR_FUN_25a0b0dc110;
  DAT_25a0b0e4ca0 = 0xffffffff;
  DAT_25a0b0e4ca8 = 0;
  FUN_25a0b0c05f0(&DAT_25a0b0e4cb0,&DAT_25a0b0dc150,0,&PTR_DAT_25a0b0e0a90);
  DAT_25a0b0e4cbc = 0xffffffff;
  FUN_25a0b0c05f0(&DAT_25a0b0e4cc0,&DAT_25a0b0dc150,0,&PTR_DAT_25a0b0e0aa0);
  _DAT_25a0b0e4ccc = 0;
  DAT_25a0b0e4cd4 = 0;
  FUN_25a0b0c05f0(&string_ref_25a0b0e4cd8,&string_ref_25a0b0de188,0,&PTR_DAT_25a0b0e0ab0);
  _DAT_25a0b0e4ce4 = 0xffffff88;
  DAT_25a0b0e4cec = 0;
  return;
}



/* Address: 25a0b0d18e0 */

void FUN_25a0b0d18e0(void)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  
  FUN_25a0b0c1870(&DAT_25a0b0e4c90);
  (*(code *)&runtime_object_unregister)(0x25a0930b4c8,DAT_25a0b0e4c90);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2310,0x25a092f9c70);
  PTR_PTR_25a0b0e2318 = &DAT_25a0b0dc010;
  (*(code *)&runtime_object_unregister)(0x25a0930b4c8,DAT_25a0b0e2310);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e22c0,0x25a092f9c70);
  PTR_PTR_25a0b0e22c8 = &DAT_25a0b0dc010;
  (*(code *)&runtime_object_unregister)(0x25a0930b4c8,DAT_25a0b0e22c0);
  FUN_25a0b0c0000(&DAT_25a0b0e2208);
  FUN_25a0b0c0000(&DAT_25a0b0e2144);
  FUN_25a0b0c0000(&DAT_25a0b0e2084);
  FUN_25a0b0c0000(&DAT_25a0b0e2034);
  (*(code *)&runtime_object_type_change)(0x25a0930b4c8,DAT_25a0b0e2000,0x25a092f9c70);
  PTR_PTR_25a0b0e2008 = &DAT_25a0b0dc010;
  (*(code *)&runtime_object_unregister)(0x25a0930b4c8,DAT_25a0b0e2000);
  FUN_25a0b0c0000(&string_ref_25a0b0e4700);
  FUN_25a0b0c0000(&string_ref_25a0b0e46f0);
  lVar3 = -0xc00;
  do {
    if ((((*(int *)((longlong)&DAT_25a0b0e46e0 + lVar3) != 0) &&
         (lVar2 = *(longlong *)((longlong)&DAT_25a0b0e46e4 + lVar3), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
      }
    }
    *(undefined8 *)((longlong)&DAT_25a0b0e46e4 + lVar3) = 0;
    *(undefined4 *)((longlong)&DAT_25a0b0e46e0 + lVar3) = 0;
    lVar3 = lVar3 + 0xc;
  } while (lVar3 != 0);
  lVar3 = -0xc00;
  do {
    if (((*(int *)((longlong)&DAT_25a0b0e3ae0 + lVar3) != 0) &&
        (lVar2 = *(longlong *)((longlong)&DAT_25a0b0e3ae4 + lVar3), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)&runtime_string_helper_7d1200)(0x25a0930b4c8);
      }
    }
    *(undefined8 *)((longlong)&DAT_25a0b0e3ae4 + lVar3) = 0;
    *(undefined4 *)((longlong)&DAT_25a0b0e3ae0 + lVar3) = 0;
    lVar3 = lVar3 + 0xc;
  } while (lVar3 != 0);
  FUN_25a0b0c0000(&string_ref_25a0b0e26c0);
  FUN_25a0b0c0000(&DAT_25a0b0e2580);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e2530);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e24f0);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e24b0);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e2470);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e2430);
  (*(code *)&runtime_array_helper_7a9d20)(0x25a0930b4c8,&DAT_25a0b0e23f0);
  return;
}



/* Address: 25a0b0d1ba0 */

void FUN_25a0b0d1ba0(void)

{
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_2c = 0;
  local_40 = 0;
  local_38 = 0;
  FUN_25a0b0d1c60(&local_40,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
  FUN_25a0b0c05f0(&local_30,&local_40,0,&PTR_DAT_25a0b0dfe98);
  FUN_25a0b0c0000(&local_40);
  FUN_25a0b0c05f0(&runtime_string_result,&local_30,1,&PTR_DAT_25a0b0dfea8);
  FUN_25a0b0c0000(&local_30);
  return;
}



/* Address: 25a0b0d1c60 */

void FUN_25a0b0d1c60(undefined8 param_1,int *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  bool bVar8;
  char cVar9;
  MqlStringAnalysisView_conflict *pMVar10;
  MqlStringAnalysisView *pMVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined **ppuVar17;
  MqlStringAnalysisView local_98;
  undefined4 local_88;
  longlong local_84;
  MqlStringAnalysisView local_78;
  uint local_68 [2];
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_78.opaque = 0;
  local_98.opaque = 0;
  local_88 = 0;
  local_50 = 0;
  local_78.text = (wchar16 *)0x0;
  local_98.text = (wchar16 *)0x0;
  local_84 = 0;
  local_4c = 0;
  local_60 = 0;
  local_58 = 0;
  pMVar10 = &_Symbol;
  if (*(longlong *)(param_2 + 6) != 0) {
    pMVar10 = (MqlStringAnalysisView_conflict *)(param_2 + 5);
  }
  FUN_25a0b0c05f0(&local_60,pMVar10,0,&PTR_DAT_25a0b0e06e8);
  uVar13 = _Digits;
  bVar8 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_60,0x11,local_68);
  if (bVar8) {
    uVar13 = local_68[0];
  }
  bVar8 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_60,0x21,local_68);
  uVar15 = 0;
  if (bVar8) {
    uVar15 = local_68[0];
  }
  switch(*param_3) {
  case 0x2714:
    MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 0xb),uVar13);
    FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e06f8);
    MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 9),uVar13);
    FUN_25a0b0c05f0(&local_98,&runtime_string_result,1,&PTR_DAT_25a0b0e0708);
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,3,0x590008,&string_ref_25a0b0dd770,0x590008,&local_98,
                 0x590008,&local_88);
    pMVar11 = &local_78;
    FUN_25a0b0c05f0(pMVar11,&runtime_string_result,1,&PTR_DAT_25a0b0e0718);
    ppuVar17 = &PTR_DAT_25a0b0e0728;
    break;
  default:
    runtime_cast_to_string((void *)0x25a0930b4c8,(ulonglong)*param_3,0x53,&local_88);
    FUN_25a0b0c05f0(&local_98,&string_ref_25a0b0ddfe0,0);
    lVar7 = local_84;
    if (local_84 != 0) {
      uVar13 = *(uint *)(local_84 + -4);
      uVar14 = (ulonglong)uVar13;
      if ((uVar14 != 0) || (local_98.text == (wchar16 *)0x0)) {
        if (local_98.text == (wchar16 *)0x0) {
          uVar15 = 0;
        }
        else {
          uVar15 = *(uint *)(local_98.text + -2);
        }
        cVar9 = FUN_25a0b0c0060(&local_98);
        if (cVar9 == '\0') {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0561000101f9);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        if (uVar14 != 0) {
          if (uVar13 < 0x10) {
            uVar12 = 0;
          }
          else if ((longlong)local_98.text + ((ulonglong)uVar15 * 2 - lVar7) < 0x20) {
            uVar12 = 0;
          }
          else {
            uVar16 = 0;
            uVar12 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              puVar1 = (undefined4 *)(lVar7 + uVar16);
              uVar4 = puVar1[1];
              uVar5 = puVar1[2];
              uVar6 = puVar1[3];
              puVar2 = (undefined4 *)((longlong)local_98.text + uVar16 + (ulonglong)uVar15 * 2);
              *puVar2 = *puVar1;
              puVar2[1] = uVar4;
              puVar2[2] = uVar5;
              puVar2[3] = uVar6;
              uVar16 = uVar16 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar12 == uVar14) goto LAB_25a0b0d25f2;
          }
          do {
            local_98.text[uVar15 + uVar12] = *(wchar16 *)(lVar7 + uVar12 * 2);
            uVar12 = uVar12 + 1;
          } while (uVar14 != uVar12);
        }
LAB_25a0b0d25f2:
        *(uint *)(local_98.text + -2) = uVar13 + uVar15;
        local_98.text[uVar13 + uVar15] = L'\0';
      }
    }
    ppuVar17 = &PTR_DAT_25a0b0e09e8;
    pMVar11 = &local_98;
    break;
  case 0x2716:
    pMVar11 = &string_ref_25a0b0dcdc0;
    ppuVar17 = &PTR_DAT_25a0b0e07e8;
    break;
  case 0x2717:
    pMVar11 = &string_ref_25a0b0dcd90;
    ppuVar17 = &PTR_DAT_25a0b0e07f8;
    break;
  case 0x2718:
    pMVar11 = &string_ref_25a0b0dcd60;
    ppuVar17 = &PTR_DAT_25a0b0e0808;
    break;
  case 0x2719:
    if ((*param_2 == 1) && (uVar15 < 3)) {
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 7),uVar13);
      FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e0738);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dd7a8,0x590008,&local_88)
      ;
      pMVar11 = &local_98;
      FUN_25a0b0c05f0(pMVar11,&runtime_string_result,1,&PTR_DAT_25a0b0e0748);
      ppuVar17 = &PTR_DAT_25a0b0e0758;
    }
    else {
      pMVar11 = &string_ref_25a0b0dd7d8;
      ppuVar17 = &PTR_DAT_25a0b0e0768;
    }
    break;
  case 0x271a:
    if ((*param_2 == 1) && (uVar15 < 3)) {
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 7),uVar13);
      FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e0778);
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 5),2);
      FUN_25a0b0c05f0(&local_98,&runtime_string_result,1,&PTR_DAT_25a0b0e0788);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,3,0x590008,&string_ref_25a0b0dd830,0x590008,&local_98,
                   0x590008,&local_88);
      pMVar11 = &local_78;
      FUN_25a0b0c05f0(pMVar11,&runtime_string_result,1,&PTR_DAT_25a0b0e0798);
      ppuVar17 = &PTR_DAT_25a0b0e07a8;
    }
    else {
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)(param_3 + 5),2);
      FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0e07b8);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dd870,0x590008,&local_88)
      ;
      pMVar11 = &local_98;
      FUN_25a0b0c05f0(pMVar11,&runtime_string_result,1,&PTR_DAT_25a0b0e07c8);
      ppuVar17 = &PTR_DAT_25a0b0e07d8;
    }
    break;
  case 0x271b:
    pMVar11 = &string_ref_25a0b0dd8a8;
    ppuVar17 = &PTR_DAT_25a0b0e0818;
    break;
  case 0x271c:
    pMVar11 = &string_ref_25a0b0dd8e0;
    ppuVar17 = &PTR_DAT_25a0b0e0828;
    break;
  case 0x271d:
    pMVar11 = &string_ref_25a0b0dd920;
    ppuVar17 = &PTR_DAT_25a0b0e0838;
    break;
  case 0x271e:
    pMVar11 = &string_ref_25a0b0dd960;
    ppuVar17 = &PTR_DAT_25a0b0e0848;
    break;
  case 0x271f:
    pMVar11 = &string_ref_25a0b0dd998;
    ppuVar17 = &PTR_DAT_25a0b0e0858;
    break;
  case 0x2720:
    pMVar11 = &string_ref_25a0b0dd9d8;
    ppuVar17 = &PTR_DAT_25a0b0e0868;
    break;
  case 0x2721:
    pMVar11 = &string_ref_25a0b0dda20;
    ppuVar17 = &PTR_DAT_25a0b0e0878;
    break;
  case 0x2722:
    pMVar11 = &string_ref_25a0b0dda58;
    ppuVar17 = &PTR_DAT_25a0b0e0888;
    break;
  case 0x2723:
    pMVar11 = &string_ref_25a0b0ddaa0;
    ppuVar17 = &PTR_DAT_25a0b0e0898;
    break;
  case 0x2724:
    pMVar11 = &string_ref_25a0b0ddad8;
    ppuVar17 = &PTR_DAT_25a0b0e08a8;
    break;
  case 0x2725:
    pMVar11 = &string_ref_25a0b0ddb18;
    ppuVar17 = &PTR_DAT_25a0b0e08b8;
    break;
  case 0x2726:
    pMVar11 = &string_ref_25a0b0ddb68;
    ppuVar17 = &PTR_DAT_25a0b0e08c8;
    break;
  case 0x2727:
    pMVar11 = &string_ref_25a0b0ddba8;
    ppuVar17 = &PTR_DAT_25a0b0e08d8;
    break;
  case 0x2728:
    pMVar11 = &string_ref_25a0b0ddbf0;
    ppuVar17 = &PTR_DAT_25a0b0e08e8;
    break;
  case 0x2729:
    pMVar11 = &string_ref_25a0b0ddc28;
    ppuVar17 = &PTR_DAT_25a0b0e08f8;
    break;
  case 0x272a:
    pMVar11 = &string_ref_25a0b0ddc90;
    ppuVar17 = &PTR_DAT_25a0b0e0908;
    break;
  case 0x272b:
    pMVar11 = &string_ref_25a0b0ddcf0;
    ppuVar17 = &PTR_DAT_25a0b0e0918;
    break;
  case 0x272c:
    pMVar11 = &string_ref_25a0b0ddd20;
    ppuVar17 = &PTR_DAT_25a0b0e0928;
    break;
  case 0x272d:
    pMVar11 = &string_ref_25a0b0ddd50;
    ppuVar17 = &PTR_DAT_25a0b0e0938;
    break;
  case 0x272e:
    pMVar11 = &string_ref_25a0b0ddd88;
    ppuVar17 = &PTR_DAT_25a0b0e0948;
    break;
  case 0x272f:
    pMVar11 = &string_ref_25a0b0dddc8;
    ppuVar17 = &PTR_DAT_25a0b0e0958;
    break;
  case 0x2730:
    pMVar11 = &string_ref_25a0b0dde00;
    ppuVar17 = &PTR_DAT_25a0b0e0968;
    break;
  case 0x2731:
    pMVar11 = &string_ref_25a0b0dde38;
    ppuVar17 = &PTR_DAT_25a0b0e0978;
    break;
  case 0x2732:
    pMVar11 = &string_ref_25a0b0dde78;
    ppuVar17 = &PTR_DAT_25a0b0e0988;
    break;
  case 0x2733:
    pMVar11 = &string_ref_25a0b0ddef8;
    ppuVar17 = &PTR_DAT_25a0b0e09a8;
    break;
  case 0x2734:
    pMVar11 = &string_ref_25a0b0ddec0;
    ppuVar17 = &PTR_DAT_25a0b0e0998;
    break;
  case 0x2737:
    pMVar11 = &string_ref_25a0b0ddf58;
    ppuVar17 = &PTR_DAT_25a0b0e09b8;
    break;
  case 0x2738:
    pMVar11 = &string_ref_25a0b0ddfa0;
    ppuVar17 = &PTR_DAT_25a0b0e09c8;
  }
  FUN_25a0b0c05f0(param_1,pMVar11,0,ppuVar17);
  FUN_25a0b0c05f0(&local_50,param_1,0,&PTR_DAT_25a0b0e09f8);
  FUN_25a0b0c0000(&local_60);
  FUN_25a0b0c05f0(&runtime_string_result,&local_50,1,&PTR_DAT_25a0b0e0a08);
  FUN_25a0b0c0000(&local_50);
  FUN_25a0b0c0000(&local_88);
  FUN_25a0b0c0000(&local_98);
  FUN_25a0b0c0000(&local_78);
  return;
}



/* Address: 25a0b0d2640 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_25a0b0d2640(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_84 = 0;
  if (_StopFlag_native32 == 0) {
    bVar1 = MT5_PositionSelectByTicket((void *)0x25a0930b4c8,param_1);
    if (bVar1) {
      DAT_25a0b0e2020 = 0;
      DAT_25a0b0e2024._0_4_ = 0;
      DAT_25a0b0e2024._4_4_ = 0;
      DAT_25a0b0e202c._0_4_ = 0;
      DAT_25a0b0e202c._4_4_ = 0;
      FUN_25a0b0c0000(&DAT_25a0b0e2034);
      DAT_25a0b0e2050 = 0;
      DAT_25a0b0e2058 = 0;
      _DAT_25a0b0e2070 = 0;
      _DAT_25a0b0e2078 = 0;
      DAT_25a0b0e2060 = 0;
      uRam0000025a0b0e2068 = 0;
      DAT_25a0b0e2040 = 0;
      DAT_25a0b0e2048 = 0;
      DAT_25a0b0e207c._4_4_ = 0;
      FUN_25a0b0c0000(&DAT_25a0b0e2084);
      _DAT_25a0b0e2120 = 0;
      uRam0000025a0b0e2128 = 0;
      _DAT_25a0b0e2100 = 0;
      uRam0000025a0b0e2108 = 0;
      _DAT_25a0b0e2130 = 0;
      uRam0000025a0b0e2138 = 0;
      _DAT_25a0b0e2110 = 0;
      uRam0000025a0b0e2118 = 0;
      DAT_25a0b0e2090 = 0;
      uRam0000025a0b0e2098 = 0;
      _DAT_25a0b0e20f0 = 0;
      uRam0000025a0b0e20f8 = 0;
      _DAT_25a0b0e20e0 = 0;
      uRam0000025a0b0e20e8 = 0;
      _DAT_25a0b0e20d0 = 0;
      uRam0000025a0b0e20d8 = 0;
      _DAT_25a0b0e20c0 = 0;
      uRam0000025a0b0e20c8 = 0;
      _DAT_25a0b0e20b0 = 0;
      uRam0000025a0b0e20b8 = 0;
      _DAT_25a0b0e20a0 = 0;
      uRam0000025a0b0e20a8 = 0;
      DAT_25a0b0e2140 = 0;
      FUN_25a0b0c0000(&DAT_25a0b0e2144);
      _DAT_25a0b0e21e0 = 0;
      uRam0000025a0b0e21e8 = 0;
      _DAT_25a0b0e21d0 = 0;
      uRam0000025a0b0e21d8 = 0;
      _DAT_25a0b0e21f0 = 0;
      uRam0000025a0b0e21f8 = 0;
      _DAT_25a0b0e21c0 = 0;
      uRam0000025a0b0e21c8 = 0;
      _DAT_25a0b0e21b0 = 0;
      uRam0000025a0b0e21b8 = 0;
      _DAT_25a0b0e21a0 = 0;
      uRam0000025a0b0e21a8 = 0;
      _DAT_25a0b0e2190 = 0;
      uRam0000025a0b0e2198 = 0;
      _DAT_25a0b0e2180 = 0;
      uRam0000025a0b0e2188 = 0;
      _DAT_25a0b0e2170 = 0;
      uRam0000025a0b0e2178 = 0;
      _DAT_25a0b0e2160 = 0;
      uRam0000025a0b0e2168 = 0;
      _DAT_25a0b0e2150 = 0;
      uRam0000025a0b0e2158 = 0;
      DAT_25a0b0e2200 = 0;
      FUN_25a0b0c0000(&DAT_25a0b0e2208);
      DAT_25a0b0e2284 = 0;
      DAT_25a0b0e227c = 0;
      DAT_25a0b0e228c = 0;
      DAT_25a0b0e2274 = 0;
      DAT_25a0b0e226c = 0;
      DAT_25a0b0e2264 = 0;
      DAT_25a0b0e225c = 0;
      DAT_25a0b0e2254 = 0;
      DAT_25a0b0e224c = 0;
      DAT_25a0b0e2244 = 0;
      DAT_25a0b0e223c = 0;
      DAT_25a0b0e2234 = 0;
      DAT_25a0b0e222c = 0;
      DAT_25a0b0e2224 = 0;
      DAT_25a0b0e221c = 0;
      DAT_25a0b0e2214 = 0;
      DAT_25a0b0e2020 = 6;
      DAT_25a0b0e2090 = param_1;
      MT5_PositionGetString((void *)0x25a0930b4c8,0);
      FUN_25a0b0c05f0(&local_88,&runtime_string_result,1,&PTR_DAT_25a0b0dfeb8);
      FUN_25a0b0c05f0(&DAT_25a0b0e2034,&local_88,0,&PTR_DAT_25a0b0dfec8);
      DAT_25a0b0e2024._0_4_ = (undefined4)state_v_22295;
      DAT_25a0b0e2024._4_4_ = (undefined4)((ulonglong)state_v_22295 >> 0x20);
      DAT_25a0b0e2058 = param_2;
      DAT_25a0b0e2060 = param_3;
      uVar2 = FUN_25a0b0c0ad0(&DAT_25a0b0e2000,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0de160,0x590008,
                 &string_ref_25a0b0dcea0);
    uVar2 = 0;
    _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x272b);
  }
  FUN_25a0b0c0000(&local_88);
  return uVar2;
}



/* Address: 25a0b0d2b10 */

/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_25a0b0d2b10(MqlStringAnalysisView_conflict *param_1)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  ulonglong uVar4;
  MqlStringAnalysisView_conflict *pMVar5;
  uint uVar6;
  undefined8 unaff_RSI;
  ulonglong uVar7;
  undefined8 local_40;
  undefined4 local_38;
  uint local_30 [2];
  
  lVar3 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,param_1,0x21);
  uVar7 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  iVar1 = DAT_25a0b0e2074;
  if ((uint)lVar3 < 2) goto LAB_25a0b0d2ef9;
  uVar4 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,param_1,0x32);
  if ((uint)lVar3 == 2) {
    iVar1 = DAT_25a0b0e2074;
    if (DAT_25a0b0e2020 == 5) goto LAB_25a0b0d2ef9;
    if ((uVar4 & 1) != 0) {
      state_v_222a5 = 0;
      DAT_25a0b0e2074 = 0;
      iVar1 = DAT_25a0b0e2074;
      goto LAB_25a0b0d2ef9;
    }
    if ((uVar4 & 2) != 0) {
      state_v_222a5 = 1;
      DAT_25a0b0e2074 = 1;
      iVar1 = DAT_25a0b0e2074;
      goto LAB_25a0b0d2ef9;
    }
LAB_25a0b0d2e56:
    DAT_25a0b0e2110 = 0x272e;
  }
  else {
    if (state_v_222a5 == 2) {
LAB_25a0b0d2ed1:
      DAT_25a0b0e2074 = 2;
      iVar1 = DAT_25a0b0e2074;
      goto LAB_25a0b0d2ef9;
    }
    if (state_v_222a5 == 1) {
      if (DAT_25a0b0e2020 == 5) {
        local_40 = 0;
        local_38 = 0;
        pMVar5 = &_Symbol;
        if (param_1->text != (wchar16 *)0x0) {
          pMVar5 = param_1;
        }
        FUN_25a0b0c05f0(&local_40,pMVar5,0,&PTR_DAT_25a0b0e0a18);
        bVar2 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_40,0x31,local_30);
        uVar6 = 0;
        if (bVar2) {
          uVar6 = local_30[0];
        }
        switch(DAT_25a0b0e2078) {
        case 0:
          uVar6 = uVar6 & 1;
          break;
        case 1:
          uVar6 = uVar6 & 2;
          break;
        case 2:
          uVar6 = uVar6 & 4;
          break;
        case 3:
          uVar6 = uVar6 & 8;
          break;
        default:
          MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0de060);
          goto LAB_25a0b0d2e1c;
        }
        if (uVar6 == 0) {
LAB_25a0b0d2e1c:
          FUN_25a0b0c0000(&local_40);
          DAT_25a0b0e2078 = 1;
        }
        else {
          FUN_25a0b0c0000(&local_40);
        }
        if (DAT_25a0b0e2070 - 2U < 4) goto LAB_25a0b0d2ed1;
      }
      uVar4 = uVar4 & 2;
joined_r0x025a0b0d2e50:
      iVar1 = state_v_222a5;
      if (uVar4 != 0) goto LAB_25a0b0d2ef9;
      goto LAB_25a0b0d2e56;
    }
    if (state_v_222a5 == 0) {
      if (DAT_25a0b0e2020 == 5) {
        local_40 = 0;
        local_38 = 0;
        pMVar5 = &_Symbol;
        if (param_1->text != (wchar16 *)0x0) {
          pMVar5 = param_1;
        }
        FUN_25a0b0c05f0(&local_40,pMVar5,0,&PTR_DAT_25a0b0e0a18);
        bVar2 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_40,0x31,local_30);
        uVar6 = 0;
        if (bVar2) {
          uVar6 = local_30[0];
        }
        switch(DAT_25a0b0e2078) {
        case 0:
          uVar6 = uVar6 & 1;
          break;
        case 1:
          uVar6 = uVar6 & 2;
          break;
        case 2:
          uVar6 = uVar6 & 4;
          break;
        case 3:
          uVar6 = uVar6 & 8;
          break;
        default:
          MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0de060);
          goto LAB_25a0b0d2ea3;
        }
        if (uVar6 == 0) {
LAB_25a0b0d2ea3:
          FUN_25a0b0c0000(&local_40);
          DAT_25a0b0e2078 = 1;
        }
        else {
          FUN_25a0b0c0000(&local_40);
        }
        if (DAT_25a0b0e2070 - 2U < 4) goto LAB_25a0b0d2ed1;
      }
      uVar4 = uVar4 & 1;
      goto joined_r0x025a0b0d2e50;
    }
    DAT_25a0b0e2110 = 0x271b;
  }
  uVar7 = 0;
  iVar1 = DAT_25a0b0e2074;
LAB_25a0b0d2ef9:
  DAT_25a0b0e2074 = iVar1;
  return uVar7 & 0xffffffff;
}



/* Address: 25a0b0d2f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_25a0b0d2f10(MqlStringAnalysisView_conflict *param_1,undefined4 param_2,undefined8 param_3,
               undefined8 param_4,double param_5,double param_6,int param_7,longlong param_8)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  MqlStringAnalysisView *value_0;
  MqlStringAnalysisView_conflict *pMVar6;
  uint uVar7;
  undefined8 local_a0;
  undefined4 local_98;
  uint local_90 [20];
  
  if (_StopFlag_native32 != 0) {
    MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0de160,0x590008,
                 &string_ref_25a0b0dcee0);
    _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x272b);
    return 0;
  }
  DAT_25a0b0e2020 = 0;
  DAT_25a0b0e2024._0_4_ = 0;
  DAT_25a0b0e2024._4_4_ = 0;
  DAT_25a0b0e202c._0_4_ = 0;
  DAT_25a0b0e202c._4_4_ = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2034);
  DAT_25a0b0e207c._4_4_ = 0;
  _DAT_25a0b0e2070 = 0;
  DAT_25a0b0e2078 = 0;
  DAT_25a0b0e207c._0_4_ = 0;
  DAT_25a0b0e2060 = 0.0;
  uRam0000025a0b0e2068 = 0;
  DAT_25a0b0e2050 = 0;
  DAT_25a0b0e2058 = 0.0;
  DAT_25a0b0e2040 = 0;
  DAT_25a0b0e2048 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2084);
  _DAT_25a0b0e2120 = 0;
  uRam0000025a0b0e2128 = 0;
  _DAT_25a0b0e2110 = 0;
  uRam0000025a0b0e2118 = 0;
  _DAT_25a0b0e2130 = 0;
  uRam0000025a0b0e2138 = 0;
  _DAT_25a0b0e2100 = 0;
  uRam0000025a0b0e2108 = 0;
  _DAT_25a0b0e20f0 = 0;
  uRam0000025a0b0e20f8 = 0;
  _DAT_25a0b0e20e0 = 0;
  uRam0000025a0b0e20e8 = 0;
  _DAT_25a0b0e20d0 = 0;
  uRam0000025a0b0e20d8 = 0;
  _DAT_25a0b0e20c0 = 0;
  uRam0000025a0b0e20c8 = 0;
  _DAT_25a0b0e20b0 = 0;
  uRam0000025a0b0e20b8 = 0;
  _DAT_25a0b0e20a0 = 0;
  uRam0000025a0b0e20a8 = 0;
  DAT_25a0b0e2090 = 0;
  uRam0000025a0b0e2098 = 0;
  DAT_25a0b0e2140 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2144);
  _DAT_25a0b0e21e0 = 0;
  uRam0000025a0b0e21e8 = 0;
  _DAT_25a0b0e21d0 = 0;
  uRam0000025a0b0e21d8 = 0;
  _DAT_25a0b0e21f0 = 0;
  uRam0000025a0b0e21f8 = 0;
  _DAT_25a0b0e21c0 = 0;
  uRam0000025a0b0e21c8 = 0;
  _DAT_25a0b0e21b0 = 0;
  uRam0000025a0b0e21b8 = 0;
  _DAT_25a0b0e21a0 = 0;
  uRam0000025a0b0e21a8 = 0;
  _DAT_25a0b0e2190 = 0;
  uRam0000025a0b0e2198 = 0;
  _DAT_25a0b0e2180 = 0;
  uRam0000025a0b0e2188 = 0;
  _DAT_25a0b0e2170 = 0;
  uRam0000025a0b0e2178 = 0;
  _DAT_25a0b0e2160 = 0;
  uRam0000025a0b0e2168 = 0;
  _DAT_25a0b0e2150 = 0;
  uRam0000025a0b0e2158 = 0;
  DAT_25a0b0e2200 = 0;
  FUN_25a0b0c0000(&DAT_25a0b0e2208);
  DAT_25a0b0e2284 = 0;
  DAT_25a0b0e227c = 0;
  DAT_25a0b0e228c = 0;
  DAT_25a0b0e2274 = 0;
  DAT_25a0b0e226c = 0;
  DAT_25a0b0e2264 = 0;
  DAT_25a0b0e225c = 0;
  DAT_25a0b0e2254 = 0;
  DAT_25a0b0e224c = 0;
  DAT_25a0b0e2244 = 0;
  DAT_25a0b0e223c = 0;
  DAT_25a0b0e2234 = 0;
  DAT_25a0b0e222c = 0;
  DAT_25a0b0e2224 = 0;
  DAT_25a0b0e221c = 0;
  DAT_25a0b0e2214 = 0;
  cVar1 = FUN_25a0b0d2b10(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  if ((param_7 == 0) && (param_8 == 0)) {
    uVar5 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,param_1,0x31);
    param_7 = 0;
    if (((uVar5 & 1) == 0) && (param_7 = 1, (uVar5 & 2) == 0)) {
      MT5_Dispatch((void *)0x25a0930b4c8,2,2,0x590008,&string_ref_25a0b0dcee0,0x590008,
                   &string_ref_25a0b0dcf98);
      _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x2726);
      FUN_25a0b0c05f0(&DAT_25a0b0e2144,&string_ref_25a0b0dcff0,0,&PTR_DAT_25a0b0dfed8);
      return 0;
    }
  }
  DAT_25a0b0e2020 = 5;
  FUN_25a0b0c05f0(&DAT_25a0b0e2034,param_1,0,&PTR_DAT_25a0b0dfee8);
  local_a0 = 0;
  local_98 = 0;
  DAT_25a0b0e2024._0_4_ = (undefined4)state_v_22295;
  DAT_25a0b0e2024._4_4_ = (undefined4)((ulonglong)state_v_22295 >> 0x20);
  _DAT_25a0b0e2070 = CONCAT44(DAT_25a0b0e2074,param_2);
  DAT_25a0b0e2050 = 0;
  DAT_25a0b0e2058 = param_5;
  DAT_25a0b0e2060 = param_6;
  DAT_25a0b0e207c._0_4_ = (undefined4)param_8;
  DAT_25a0b0e207c._4_4_ = (undefined4)((ulonglong)param_8 >> 0x20);
  pMVar6 = param_1;
  if (param_1->text == (wchar16 *)0x0) {
    pMVar6 = &_Symbol;
  }
  DAT_25a0b0e2040 = param_3;
  DAT_25a0b0e2048 = param_4;
  DAT_25a0b0e2078 = param_7;
  FUN_25a0b0c05f0(&local_a0,pMVar6,0,&PTR_DAT_25a0b0e0a28);
  bVar2 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_a0,0x47,local_90);
  uVar7 = 0;
  if (bVar2) {
    uVar7 = local_90[0];
  }
  bVar3 = (byte)uVar7;
  switch(_DAT_25a0b0e2070 & 0xffffffff) {
  case 0:
  case 1:
    if ((uVar7 & 1) == 0) goto switchD_25a0b0d3559_default;
    goto LAB_25a0b0d35d7;
  case 2:
  case 3:
    bVar3 = bVar3 >> 1;
    goto joined_r0x025a0b0d3580;
  case 4:
  case 5:
    if ((bVar3 >> 2 & 1) != 0) goto LAB_25a0b0d35d7;
  default:
switchD_25a0b0d3559_default:
    _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x2733);
    MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0de0d8);
    FUN_25a0b0c0000(&local_a0);
    break;
  case 6:
  case 7:
    bVar3 = bVar3 >> 3;
joined_r0x025a0b0d3580:
    if ((bVar3 & 1) == 0) goto switchD_25a0b0d3559_default;
LAB_25a0b0d35d7:
    if ((((DAT_25a0b0e2058 != 0.0) || (NAN(DAT_25a0b0e2058))) || (DAT_25a0b0e2060 != 0.0)) ||
       (NAN(DAT_25a0b0e2060))) {
      if ((uVar7 & 0x10) == 0) {
        DAT_25a0b0e2058 = 0.0;
      }
      if ((uVar7 & 0x20) == 0) {
        DAT_25a0b0e2060 = 0.0;
      }
    }
    FUN_25a0b0c0000(&local_a0);
    cVar1 = FUN_25a0b0d2b10(param_1);
    if (cVar1 == '\0') {
      value_0 = &string_ref_25a0b0dd060;
      _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x272e);
    }
    else {
      local_a0 = 0;
      local_98 = 0;
      pMVar6 = &_Symbol;
      if (param_1->text != (wchar16 *)0x0) {
        pMVar6 = param_1;
      }
      FUN_25a0b0c05f0(&local_a0,pMVar6,0,&PTR_DAT_25a0b0e0a18);
      bVar2 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_a0,0x31,local_90);
      uVar7 = 0;
      if (bVar2) {
        uVar7 = local_90[0];
      }
      switch(DAT_25a0b0e2078) {
      case 0:
        uVar7 = uVar7 & 1;
        break;
      case 1:
        uVar7 = uVar7 & 2;
        break;
      case 2:
        uVar7 = uVar7 & 4;
        break;
      case 3:
        uVar7 = uVar7 & 8;
        break;
      default:
        MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,&string_ref_25a0b0de060);
        goto LAB_25a0b0d3798;
      }
      if (uVar7 != 0) {
        FUN_25a0b0c0000(&local_a0);
        FUN_25a0b0c05f0(&DAT_25a0b0e2084,&TradeComment,0,&PTR_DAT_25a0b0dfef8);
        uVar4 = FUN_25a0b0c0ad0(&DAT_25a0b0e2000,&DAT_25a0b0e2020,&DAT_25a0b0e2110);
        return uVar4;
      }
LAB_25a0b0d3798:
      FUN_25a0b0c0000(&local_a0);
      _DAT_25a0b0e2110 = CONCAT44(DAT_25a0b0e2110_4,0x2726);
      value_0 = &string_ref_25a0b0dd0d8;
    }
    MT5_Dispatch((void *)0x25a0930b4c8,2,1,0x590008,value_0);
  }
  return 0;
}



/* Address: 25a0b0d37f0 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_25a0b0d37f0(longlong param_1,longlong param_2,MqlStringAnalysisView_conflict *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  double dVar4;
  dword dVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  longlong lVar13;
  bool bVar14;
  char cVar15;
  wchar16 *pwVar16;
  MqlStringAnalysisView_conflict *pMVar17;
  MqlStringAnalysisView_conflict *pMVar18;
  MqlStringAnalysisView_conflict *pMVar19;
  ulonglong uVar20;
  longlong lVar21;
  ulonglong uVar22;
  undefined **ppuVar23;
  ulonglong uVar24;
  undefined **ppuVar25;
  uint local_10c;
  MqlStringAnalysisView_conflict local_108;
  MqlStringAnalysisView_conflict local_f8;
  longlong local_e8;
  undefined4 local_e0;
  longlong local_dc;
  MqlStringAnalysisView_conflict local_d0;
  undefined4 local_c0;
  undefined8 uStack_bc;
  MqlStringAnalysisView_conflict local_b0;
  uint local_a0 [2];
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_b0.opaque = 0;
  local_d0.opaque = 0;
  local_f8.opaque = 0;
  local_108.opaque = 0;
  local_68 = 0;
  local_c0 = 0;
  local_78 = 0;
  local_88 = 0;
  local_e0 = 0;
  local_b0.text = (wchar16 *)0x0;
  local_d0.text = (wchar16 *)0x0;
  local_f8.text = (wchar16 *)0x0;
  local_108.text = (wchar16 *)0x0;
  local_64 = 0;
  uStack_bc = 0;
  local_74 = 0;
  local_84 = 0;
  local_dc = 0;
  local_e8 = param_2;
  FUN_25a0b0c05f0(param_2,&string_ref_25a0b0dc170,0,&PTR_DAT_25a0b0e00e8);
  local_98 = 0;
  local_94 = 0;
  pMVar18 = (MqlStringAnalysisView_conflict *)((longlong)&param_3[1].text + 4);
  pMVar17 = &_Symbol;
  if (*(longlong *)(param_3 + 2) != 0) {
    pMVar17 = pMVar18;
  }
  FUN_25a0b0c05f0(&local_98,pMVar17,0,&PTR_DAT_25a0b0e00f8);
  local_10c = _Digits;
  bVar14 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_98,0x11,local_a0);
  if (bVar14) {
    local_10c = local_a0[0];
  }
  bVar14 = MT5_SymbolInfoIntegerRef((void *)0x25a0930b4c8,&local_98,0x21,local_a0);
  lVar21 = local_e8;
  dVar5 = param_3->opaque;
  if (8 < dVar5 - 1 && dVar5 != 10) {
switchD_25a0b0d39d0_caseD_b0d3d24:
    runtime_cast_to_string((void *)0x25a0930b4c8,(longlong)(int)dVar5,0x52,&local_108);
    FUN_25a0b0c05f0(&local_f8,&string_ref_25a0b0dd730,0);
    if (((MqlStringAnalysisView_conflict *)local_108.text != (MqlStringAnalysisView_conflict *)0x0)
       && ((uVar6 = *(uint *)((longlong)
                              &((MqlStringAnalysisView_conflict *)((longlong)local_108.text + -0xc))
                               ->text + 4),
           pMVar18 = (MqlStringAnalysisView_conflict *)(ulonglong)uVar6, uVar6 != 0 ||
           (local_f8.text == (wchar16 *)0x0)))) {
      pMVar17 = (MqlStringAnalysisView_conflict *)local_108.text;
      if (local_f8.text == (wchar16 *)0x0) goto LAB_25a0b0d543a;
      uVar6 = *(uint *)(local_f8.text + -2);
LAB_25a0b0d543d:
      uVar7 = (uint)pMVar18;
      cVar15 = FUN_25a0b0c0060(&local_f8);
      if (cVar15 == '\0') {
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1e04cf000101f9);
LAB_25a0b0d57ea:
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xf04a0000101f9);
        goto LAB_25a0b0d580a;
      }
      if (pMVar18 != (MqlStringAnalysisView_conflict *)0x0) {
        if (uVar7 < 0x10) {
          pMVar19 = (MqlStringAnalysisView_conflict *)0x0;
        }
        else if ((longlong)local_f8.text + ((ulonglong)uVar6 * 2 - (longlong)pMVar17) < 0x20) {
          pMVar19 = (MqlStringAnalysisView_conflict *)0x0;
        }
        else {
          uVar22 = 0;
          pMVar19 = (MqlStringAnalysisView_conflict *)(ulonglong)(uVar7 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)((longlong)&pMVar17->opaque + uVar22);
            uVar10 = puVar3[1];
            uVar11 = puVar3[2];
            uVar12 = puVar3[3];
            puVar2 = (undefined4 *)((longlong)local_f8.text + uVar22 + (ulonglong)uVar6 * 2);
            *puVar2 = *puVar3;
            puVar2[1] = uVar10;
            puVar2[2] = uVar11;
            puVar2[3] = uVar12;
            uVar22 = uVar22 + 0x10;
          } while (((longlong)pMVar18 * 2 & 0xfffffffffffffff0U) != uVar22);
          if (pMVar19 == pMVar18) goto LAB_25a0b0d5592;
        }
        do {
          local_f8.text[(longlong)&pMVar19->opaque + (ulonglong)uVar6] =
               *(wchar16 *)((longlong)&pMVar17->opaque + (longlong)pMVar19 * 2);
          pMVar19 = (MqlStringAnalysisView_conflict *)((longlong)&pMVar19->opaque + 1);
        } while (pMVar18 != pMVar19);
      }
LAB_25a0b0d5592:
      *(uint *)(local_f8.text + -2) = uVar7 + uVar6;
      local_f8.text[uVar7 + uVar6] = L'\0';
    }
    ppuVar23 = &PTR_DAT_25a0b0e06b8;
    pMVar18 = &local_f8;
    lVar21 = local_e8;
    goto LAB_25a0b0d42bb;
  }
  switch((&switchD_25a0b0d39d0::switchdataD_25a0b0dbdd8)[dVar5 - 1]) {
  case (undefined *)0x25a0b0d39d4:
    uVar6 = 0;
    if (bVar14) {
      uVar6 = local_a0[0];
    }
    switch(uVar6) {
    case 0:
      if ((*(int *)(param_1 + 0x2a9) == 2) && (param_3[9].text != (wchar16 *)0x0)) {
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[3].text,local_10c);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0108);
        pwVar16 = param_3[9].text;
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0118);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0128);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,6,0x590008,&string_ref_25a0b0dd200,0x590008,
                     &local_d0,0x590008,&local_f8,0x560015,(ulonglong)pwVar16,0x590008,pMVar18,
                     0x590008,&local_108);
        ppuVar25 = &PTR_DAT_25a0b0e0148;
        ppuVar23 = &PTR_DAT_25a0b0e0138;
      }
      else {
LAB_25a0b0d4daa:
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[3].text,local_10c);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0158);
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0168);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0178);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd250,0x590008,
                     &local_d0,0x590008,&local_f8,0x590008,pMVar18,0x590008,&local_108);
        ppuVar25 = &PTR_DAT_25a0b0e0198;
        ppuVar23 = &PTR_DAT_25a0b0e0188;
      }
      FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,ppuVar23);
      lVar21 = local_e8;
      FUN_25a0b0c05f0(local_e8,&local_b0,0,ppuVar25);
      dVar4 = *(double *)((longlong)&param_3[4].text + 4);
      if ((dVar4 == 0.0) && (!NAN(dVar4))) {
LAB_25a0b0d4fea:
        pwVar16 = param_3[5].text;
        if (((double)pwVar16 == 0.0) && (!NAN((double)pwVar16))) goto switchD_25a0b0d39fb_default;
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)pwVar16,local_10c);
        pMVar18 = &local_108;
        FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e01d8);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce50,0x590008,pMVar18)
        ;
        param_3 = &local_f8;
        FUN_25a0b0c05f0(param_3,&runtime_string_result,1,&PTR_DAT_25a0b0e01e8);
        FUN_25a0b0c05f0(&local_e0,param_3,0,&PTR_DAT_25a0b0e01f8);
        cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
        if (cVar15 != '\0') goto switchD_25a0b0d39fb_default;
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150441000101f9);
LAB_25a0b0d50f2:
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[3].text,local_10c);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0258);
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0268);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0278);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd310,0x590008,
                     &local_d0,0x590008,&local_f8,0x590008,pMVar18,0x590008,&local_108);
        ppuVar25 = &PTR_DAT_25a0b0e0298;
        ppuVar23 = &PTR_DAT_25a0b0e0288;
        goto LAB_25a0b0d5216;
      }
      MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e01a8);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce20,0x590008,&local_108
                  );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e01b8);
      FUN_25a0b0c05f0(&local_e0,&local_f8,0,&PTR_DAT_25a0b0e01c8);
      cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
      if (cVar15 != '\0') goto LAB_25a0b0d4fea;
      break;
    case 1:
      if ((*(int *)(param_1 + 0x2a9) != 2) || (param_3[9].text == (wchar16 *)0x0))
      goto LAB_25a0b0d50f2;
      MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[3].text,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0208);
      pwVar16 = param_3[9].text;
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0218);
      FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
      FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0228);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,6,0x590008,&string_ref_25a0b0dd2c0,0x590008,&local_d0,
                   0x590008,&local_f8,0x560015,(ulonglong)pwVar16,0x590008,pMVar18,0x590008,
                   &local_108);
      ppuVar25 = &PTR_DAT_25a0b0e0248;
      ppuVar23 = &PTR_DAT_25a0b0e0238;
LAB_25a0b0d5216:
      FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,ppuVar23);
      lVar21 = local_e8;
      FUN_25a0b0c05f0(local_e8,&local_b0,0,ppuVar25);
      dVar4 = *(double *)((longlong)&param_3[4].text + 4);
      if ((dVar4 != 0.0) || (NAN(dVar4))) {
        MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,local_10c);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e02a8);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce20,0x590008,
                     &local_108);
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e02b8);
        FUN_25a0b0c05f0(&local_e0,&local_f8,0,&PTR_DAT_25a0b0e02c8);
        cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
        if (cVar15 == '\0') goto LAB_25a0b0d588a;
      }
      pwVar16 = param_3[5].text;
      if (((double)pwVar16 == 0.0) && (!NAN((double)pwVar16))) goto switchD_25a0b0d39fb_default;
      MT5_DoubleToString((void *)0x25a0930b4c8,(double)pwVar16,local_10c);
      pMVar18 = &local_108;
      FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e02d8);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce50,0x590008,pMVar18);
      pMVar17 = &local_f8;
      FUN_25a0b0c05f0(pMVar17,&runtime_string_result,1,&PTR_DAT_25a0b0e02e8);
      FUN_25a0b0c05f0(&local_e0,pMVar17,0);
      cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
      if (cVar15 != '\0') goto switchD_25a0b0d39fb_default;
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x15045c000101f9);
LAB_25a0b0d543a:
      uVar6 = 0;
      goto LAB_25a0b0d543d;
    case 2:
      if ((*(int *)(param_1 + 0x2a9) == 2) && (pwVar16 = param_3[9].text, pwVar16 != (wchar16 *)0x0)
         ) {
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0308);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0318);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd370,0x590008,
                     &local_f8,0x590008,&local_108,0x560015,(ulonglong)pwVar16,0x590008,pMVar18);
        ppuVar25 = &PTR_DAT_25a0b0e0338;
        ppuVar23 = &PTR_DAT_25a0b0e0328;
      }
      else {
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0348);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0358);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,4,0x590008,&string_ref_25a0b0dd3b0,0x590008,
                     &local_f8,0x590008,&local_108,0x590008,pMVar18);
        ppuVar25 = &PTR_DAT_25a0b0e0378;
        ppuVar23 = &PTR_DAT_25a0b0e0368;
      }
      FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,ppuVar23);
      lVar21 = local_e8;
      FUN_25a0b0c05f0(local_e8,&local_d0,0,ppuVar25);
      dVar4 = *(double *)((longlong)&param_3[4].text + 4);
      if ((dVar4 == 0.0) && (!NAN(dVar4))) {
LAB_25a0b0d499d:
        pwVar16 = param_3[5].text;
        if (((double)pwVar16 == 0.0) && (!NAN((double)pwVar16))) goto switchD_25a0b0d39fb_default;
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)pwVar16,local_10c);
        pMVar18 = &local_108;
        FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e03b8);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce50,0x590008,pMVar18)
        ;
        param_3 = &local_f8;
        FUN_25a0b0c05f0(param_3,&runtime_string_result,1,&PTR_DAT_25a0b0e03c8);
        FUN_25a0b0c05f0(&local_e0,param_3,0,&PTR_DAT_25a0b0e03d8);
        cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
        if (cVar15 != '\0') goto switchD_25a0b0d39fb_default;
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150475000101f9);
LAB_25a0b0d4aa5:
        MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
        FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0428);
        FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
        FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0438);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,4,0x590008,&string_ref_25a0b0dd450,0x590008,
                     &local_f8,0x590008,&local_108,0x590008,pMVar18);
        ppuVar25 = &PTR_DAT_25a0b0e0458;
        ppuVar23 = &PTR_DAT_25a0b0e0448;
        goto LAB_25a0b0d4b8e;
      }
      MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0388);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce20,0x590008,&local_108
                  );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0398);
      FUN_25a0b0c05f0(&local_e0,&local_f8,0,&PTR_DAT_25a0b0e03a8);
      cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
      if (cVar15 != '\0') goto LAB_25a0b0d499d;
      goto LAB_25a0b0d582a;
    case 3:
      if ((*(int *)(param_1 + 0x2a9) != 2) || (pwVar16 = param_3[9].text, pwVar16 == (wchar16 *)0x0)
         ) goto LAB_25a0b0d4aa5;
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e03e8);
      FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e03f8);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd410,0x590008,&local_f8,
                   0x590008,&local_108,0x560015,(ulonglong)pwVar16,0x590008,pMVar18);
      ppuVar25 = &PTR_DAT_25a0b0e0418;
      ppuVar23 = &PTR_DAT_25a0b0e0408;
LAB_25a0b0d4b8e:
      FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,ppuVar23);
      lVar21 = local_e8;
      FUN_25a0b0c05f0(local_e8,&local_d0,0,ppuVar25);
      dVar4 = *(double *)((longlong)&param_3[4].text + 4);
      if ((dVar4 == 0.0) && (!NAN(dVar4))) {
LAB_25a0b0d4cab:
        pwVar16 = param_3[5].text;
        if (((double)pwVar16 == 0.0) && (!NAN((double)pwVar16))) goto switchD_25a0b0d39fb_default;
        MT5_DoubleToString((void *)0x25a0930b4c8,(double)pwVar16,local_10c);
        pMVar18 = &local_108;
        FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0498);
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce50,0x590008,pMVar18)
        ;
        param_3 = &local_f8;
        FUN_25a0b0c05f0(param_3,&runtime_string_result,1,&PTR_DAT_25a0b0e04a8);
        FUN_25a0b0c05f0(&local_e0,param_3,0,&PTR_DAT_25a0b0e04b8);
        cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
        if (cVar15 != '\0') goto switchD_25a0b0d39fb_default;
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x15048e000101f9);
        goto LAB_25a0b0d4daa;
      }
      MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0468);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce20,0x590008,&local_108
                  );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0478);
      FUN_25a0b0c05f0(&local_e0,&local_f8,0,&PTR_DAT_25a0b0e0488);
      cVar15 = FUN_25a0b0c04d0(lVar21,local_dc);
      if (cVar15 != '\0') goto LAB_25a0b0d4cab;
      goto LAB_25a0b0d584a;
    default:
      goto switchD_25a0b0d39fb_default;
    }
    goto LAB_25a0b0d586a;
  case (undefined *)0x25a0b0d3b56:
    if ((*(int *)(param_1 + 0x2a9) == 2) && (param_3[9].text != (wchar16 *)0x0)) {
      MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[5].text,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0578);
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[4].text + 4),local_10c
                        );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0588);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd508,0x560015,
                   (ulonglong)param_3[9].text,0x590008,pMVar18,0x590008,&local_f8,0x590008,
                   &local_108);
      pMVar18 = &local_d0;
      FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0598);
      ppuVar23 = &PTR_DAT_25a0b0e05a8;
      lVar21 = local_e8;
    }
    else {
      MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[5].text,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e05b8);
      MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[4].text + 4),local_10c
                        );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e05c8);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,4,0x590008,&string_ref_25a0b0dd568,0x590008,pMVar18,
                   0x590008,&local_f8,0x590008,&local_108);
      pMVar18 = &local_d0;
      FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e05d8);
      ppuVar23 = &PTR_DAT_25a0b0e05e8;
      lVar21 = local_e8;
    }
    break;
  case (undefined *)0x25a0b0d3c7a:
    pwVar16 = param_3[9].text;
    if (*(int *)(param_1 + 0x2a9) == 2) {
      if (pwVar16 != (wchar16 *)0x0) {
        MT5_Dispatch((void *)0x25a0930b4c8,0xd8,3,0x590008,&string_ref_25a0b0dd680,0x560015,
                     (ulonglong)pwVar16,0x560015,*(ulonglong *)(param_3 + 10));
        pMVar18 = &local_108;
        FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0668);
        ppuVar23 = &PTR_DAT_25a0b0e0678;
        break;
      }
      pwVar16 = (wchar16 *)0x0;
    }
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,3,0x590008,&string_ref_25a0b0dd6f0,0x560015,
                 (ulonglong)pwVar16,0x560015,*(ulonglong *)(param_3 + 10));
    pMVar18 = &local_108;
    FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0688);
    ppuVar23 = &PTR_DAT_25a0b0e0698;
    break;
  case (undefined *)0x25a0b0d3d24:
    goto switchD_25a0b0d39d0_caseD_b0d3d24;
  case (undefined *)0x25a0b0d3da5:
    FUN_25a0b0d5bb0(&local_78,param_3[3].text,*(undefined8 *)(param_3 + 4),local_10c);
    FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e04c8);
    MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[2].text + 4),2);
    FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e04d8);
    FUN_25a0b0d58b0(&local_c0,*(undefined4 *)((longlong)&param_3[6].text + 4));
    FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e04e8);
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd490,0x590008,&local_d0,
                 0x590008,&local_f8,0x590008,pMVar18,0x590008,&local_108);
    FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,&PTR_DAT_25a0b0e04f8);
    lVar21 = local_e8;
    FUN_25a0b0c05f0(local_e8,&local_b0,0,&PTR_DAT_25a0b0e0508);
    dVar4 = *(double *)((longlong)&param_3[4].text + 4);
    if ((dVar4 != 0.0) || (NAN(dVar4))) {
      MT5_DoubleToString((void *)0x25a0930b4c8,dVar4,local_10c);
      FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0518);
      MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dce20,0x590008,&local_108
                  );
      FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0528);
      FUN_25a0b0c05f0(&local_e0,&local_f8,0);
      lVar13 = local_dc;
      lVar1 = local_e8;
      if (local_dc == 0) goto LAB_25a0b0d5615;
      uVar6 = *(uint *)(local_dc + -4);
      uVar22 = (ulonglong)uVar6;
      lVar8 = *(longlong *)(lVar21 + 4);
      if ((uVar6 == 0) && (lVar8 != 0)) goto LAB_25a0b0d5615;
      if (lVar8 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(uint *)(lVar8 + -4);
      }
      cVar15 = FUN_25a0b0c0060(local_e8);
      if (cVar15 != '\0') {
        lVar21 = *(longlong *)(lVar1 + 4);
        if (uVar6 != 0) {
          lVar1 = lVar21 + (ulonglong)uVar7 * 2;
          if (uVar6 < 0x10) {
            uVar20 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar13) < 0x20) {
            uVar20 = 0;
          }
          else {
            uVar24 = 0;
            uVar20 = (ulonglong)(uVar6 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar13 + uVar24);
              uVar10 = puVar3[1];
              uVar11 = puVar3[2];
              uVar12 = puVar3[3];
              puVar2 = (undefined4 *)(lVar1 + uVar24);
              *puVar2 = *puVar3;
              puVar2[1] = uVar10;
              puVar2[2] = uVar11;
              puVar2[3] = uVar12;
              uVar24 = uVar24 + 0x10;
            } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar24);
            if (uVar20 == uVar22) goto LAB_25a0b0d5602;
          }
          do {
            *(undefined2 *)(lVar1 + uVar20 * 2) = *(undefined2 *)(lVar13 + uVar20 * 2);
            uVar20 = uVar20 + 1;
          } while (uVar22 != uVar20);
        }
LAB_25a0b0d5602:
        *(uint *)(lVar21 + -4) = uVar6 + uVar7;
        *(undefined2 *)(lVar21 + (ulonglong)(uVar6 + uVar7) * 2) = 0;
        lVar21 = local_e8;
        goto LAB_25a0b0d5615;
      }
      goto LAB_25a0b0d57ea;
    }
LAB_25a0b0d5615:
    pwVar16 = param_3[5].text;
    if (((double)pwVar16 == 0.0) && (!NAN((double)pwVar16))) goto switchD_25a0b0d39fb_default;
    MT5_DoubleToString((void *)0x25a0930b4c8,(double)pwVar16,local_10c);
    FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e0548);
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008);
    FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0558);
    FUN_25a0b0c05f0(&local_e0,&local_f8,0);
    lVar13 = local_dc;
    lVar1 = local_e8;
    if (local_dc == 0) goto switchD_25a0b0d39fb_default;
    uVar6 = *(uint *)(local_dc + -4);
    uVar22 = (ulonglong)uVar6;
    lVar8 = *(longlong *)(lVar21 + 4);
    if ((uVar6 == 0) && (lVar8 != 0)) goto switchD_25a0b0d39fb_default;
    if (lVar8 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(lVar8 + -4);
    }
    cVar15 = FUN_25a0b0c0060(local_e8);
    if (cVar15 != '\0') {
      lVar21 = *(longlong *)(lVar1 + 4);
      if (uVar6 != 0) {
        lVar1 = lVar21 + (ulonglong)uVar7 * 2;
        if (uVar6 < 0x10) {
          uVar20 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar13) < 0x20) {
          uVar20 = 0;
        }
        else {
          uVar24 = 0;
          uVar20 = (ulonglong)(uVar6 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar13 + uVar24);
            uVar10 = puVar3[1];
            uVar11 = puVar3[2];
            uVar12 = puVar3[3];
            puVar2 = (undefined4 *)(lVar1 + uVar24);
            *puVar2 = *puVar3;
            puVar2[1] = uVar10;
            puVar2[2] = uVar11;
            puVar2[3] = uVar12;
            uVar24 = uVar24 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar24);
          if (uVar20 == uVar22) goto LAB_25a0b0d57b2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar20 * 2) = *(undefined2 *)(lVar13 + uVar20 * 2);
          uVar20 = uVar20 + 1;
        } while (uVar22 != uVar20);
      }
LAB_25a0b0d57b2:
      *(uint *)(lVar21 + -4) = uVar6 + uVar7;
      *(undefined2 *)(lVar21 + (ulonglong)(uVar6 + uVar7) * 2) = 0;
      lVar21 = local_e8;
      goto switchD_25a0b0d39fb_default;
    }
LAB_25a0b0d580a:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xf04a5000101f9);
LAB_25a0b0d582a:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150470000101f9);
LAB_25a0b0d584a:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150489000101f9);
LAB_25a0b0d586a:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x15043c000101f9);
LAB_25a0b0d588a:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150457000101f9);
    pcVar9 = (code *)swi(3);
    (*pcVar9)();
    return;
  case (undefined *)0x25a0b0d3ff7:
    MT5_DoubleToString((void *)0x25a0930b4c8,(double)param_3[5].text,local_10c);
    FUN_25a0b0c05f0(&local_108,&runtime_string_result,1,&PTR_DAT_25a0b0e05f8);
    MT5_DoubleToString((void *)0x25a0930b4c8,*(double *)((longlong)&param_3[4].text + 4),local_10c);
    FUN_25a0b0c05f0(&local_f8,&runtime_string_result,1,&PTR_DAT_25a0b0e0608);
    FUN_25a0b0d5bb0(&local_88,param_3[3].text,*(undefined8 *)(param_3 + 4),local_10c);
    FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0618);
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,5,0x590008,&string_ref_25a0b0dd5d8,0x560015,
                 *(ulonglong *)(param_3 + 1),0x590008,&local_d0,0x590008,&local_f8,0x590008,
                 &local_108);
    pMVar18 = &local_b0;
    FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0628);
    ppuVar23 = &PTR_DAT_25a0b0e0638;
    lVar21 = local_e8;
    break;
  case (undefined *)0x25a0b0d413e:
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,2,0x590008,&string_ref_25a0b0dd618,0x560015,
                 *(ulonglong *)(param_3 + 1));
    pMVar18 = &local_108;
    FUN_25a0b0c05f0(pMVar18,&runtime_string_result,1,&PTR_DAT_25a0b0e0648);
    ppuVar23 = &PTR_DAT_25a0b0e0658;
    lVar21 = local_e8;
  }
LAB_25a0b0d42bb:
  FUN_25a0b0c05f0(lVar21,pMVar18,0,ppuVar23);
switchD_25a0b0d39fb_default:
  FUN_25a0b0c05f0(&local_68,lVar21,0,&PTR_DAT_25a0b0e06c8);
  FUN_25a0b0c0000(&local_98);
  FUN_25a0b0c0000(&local_e0);
  FUN_25a0b0c0000(&local_88);
  FUN_25a0b0c0000(&local_78);
  FUN_25a0b0c0000(&local_c0);
  FUN_25a0b0c05f0(&runtime_string_result,&local_68,1,&PTR_DAT_25a0b0e06d8);
  FUN_25a0b0c0000(&local_68);
  FUN_25a0b0c0000(&local_108);
  FUN_25a0b0c0000(&local_f8);
  FUN_25a0b0c0000(&local_d0);
  FUN_25a0b0c0000(&local_b0);
  return;
}



/* Address: 25a0b0d58b0 */

void FUN_25a0b0d58b0(undefined8 param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  char cVar9;
  MqlStringAnalysisView *pMVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined **ppuVar13;
  ulonglong uVar14;
  uint uVar15;
  MqlStringAnalysisView local_60;
  undefined4 local_50;
  longlong local_4c;
  undefined4 local_40;
  undefined8 local_3c;
  
  local_60.opaque = 0;
  local_50 = 0;
  local_40 = 0;
  local_60.text = (wchar16 *)0x0;
  local_4c = 0;
  local_3c = 0;
  switch((ulonglong)param_2) {
  case 0:
    pMVar10 = &string_ref_25a0b0dcb58;
    ppuVar13 = &PTR_DAT_25a0b0dff88;
    break;
  case 1:
    pMVar10 = &string_ref_25a0b0dcb88;
    ppuVar13 = &PTR_DAT_25a0b0dff98;
    break;
  case 2:
    pMVar10 = &string_ref_25a0b0dcbc0;
    ppuVar13 = &PTR_DAT_25a0b0dffa8;
    break;
  case 3:
    pMVar10 = &string_ref_25a0b0dcbf8;
    ppuVar13 = &PTR_DAT_25a0b0dffb8;
    break;
  case 4:
    pMVar10 = &string_ref_25a0b0dcc30;
    ppuVar13 = &PTR_DAT_25a0b0dffc8;
    break;
  case 5:
    pMVar10 = &string_ref_25a0b0dcc60;
    ppuVar13 = &PTR_DAT_25a0b0dffd8;
    break;
  case 6:
    pMVar10 = &string_ref_25a0b0dcca0;
    ppuVar13 = &PTR_DAT_25a0b0dffe8;
    break;
  case 7:
    pMVar10 = &string_ref_25a0b0dcce0;
    ppuVar13 = &PTR_DAT_25a0b0dfff8;
    break;
  default:
    runtime_cast_to_string((void *)0x25a0930b4c8,(ulonglong)param_2,0x53,&local_50);
    FUN_25a0b0c05f0(&local_60,&string_ref_25a0b0dcd28,0);
    lVar8 = local_4c;
    if (local_4c != 0) {
      uVar3 = *(uint *)(local_4c + -4);
      uVar14 = (ulonglong)uVar3;
      if ((uVar14 != 0) || (local_60.text == (wchar16 *)0x0)) {
        if (local_60.text == (wchar16 *)0x0) {
          uVar15 = 0;
        }
        else {
          uVar15 = *(uint *)(local_60.text + -2);
        }
        cVar9 = FUN_25a0b0c0060(&local_60);
        if (cVar9 == '\0') {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x2203c7000101f9);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if (uVar14 != 0) {
          if (uVar3 < 0x10) {
            uVar11 = 0;
          }
          else if ((longlong)local_60.text + ((ulonglong)uVar15 * 2 - lVar8) < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar12 = 0;
            uVar11 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              puVar1 = (undefined4 *)(lVar8 + uVar12);
              uVar5 = puVar1[1];
              uVar6 = puVar1[2];
              uVar7 = puVar1[3];
              puVar2 = (undefined4 *)((longlong)local_60.text + uVar12 + (ulonglong)uVar15 * 2);
              *puVar2 = *puVar1;
              puVar2[1] = uVar5;
              puVar2[2] = uVar6;
              puVar2[3] = uVar7;
              uVar12 = uVar12 + 0x10;
            } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar12);
            if (uVar11 == uVar14) goto LAB_25a0b0d5b02;
          }
          do {
            local_60.text[uVar15 + uVar11] = *(wchar16 *)(lVar8 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar14 != uVar11);
        }
LAB_25a0b0d5b02:
        *(uint *)(local_60.text + -2) = uVar3 + uVar15;
        local_60.text[uVar3 + uVar15] = L'\0';
      }
    }
    ppuVar13 = &PTR_DAT_25a0b0e0018;
    pMVar10 = &local_60;
  }
  FUN_25a0b0c05f0(param_1,pMVar10,0,ppuVar13);
  FUN_25a0b0c05f0(&local_40,param_1,0,&PTR_DAT_25a0b0e0028);
  FUN_25a0b0c05f0(&runtime_string_result,&local_40,1,&PTR_DAT_25a0b0e0038);
  FUN_25a0b0c0000(&local_40);
  FUN_25a0b0c0000(&local_50);
  FUN_25a0b0c0000(&local_60);
  return;
}



/* Address: 25a0b0d5bb0 */

void FUN_25a0b0d5bb0(undefined8 param_1,double param_2,double param_3,int param_4)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_78 = 0;
  local_68 = 0;
  local_88 = 0;
  local_98 = 0;
  local_74 = 0;
  local_64 = 0;
  local_84 = 0;
  local_94 = 0;
  MT5_DoubleToString((void *)0x25a0930b4c8,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_25a0b0c05f0(&local_78,&runtime_string_result,1,&PTR_DAT_25a0b0e0048);
    FUN_25a0b0c05f0(&local_88,&local_78,0,&PTR_DAT_25a0b0e0058);
    MT5_DoubleToString((void *)0x25a0930b4c8,param_3,param_4);
    FUN_25a0b0c05f0(&local_78,&runtime_string_result,1,&PTR_DAT_25a0b0e0068);
    FUN_25a0b0c05f0(&local_98,&local_78,0,&PTR_DAT_25a0b0e0078);
    MT5_Dispatch((void *)0x25a0930b4c8,0xd8,3,0x590008,&string_ref_25a0b0dcdf0,0x590008,&local_88,
                 0x590008,&local_98);
    ppuVar2 = &PTR_DAT_25a0b0e0098;
    ppuVar1 = &PTR_DAT_25a0b0e0088;
  }
  else {
    ppuVar2 = &PTR_DAT_25a0b0e00b8;
    ppuVar1 = &PTR_DAT_25a0b0e00a8;
  }
  FUN_25a0b0c05f0(&local_78,&runtime_string_result,1,ppuVar1);
  FUN_25a0b0c05f0(param_1,&local_78,0,ppuVar2);
  FUN_25a0b0c05f0(&local_68,param_1,0,&PTR_DAT_25a0b0e00c8);
  FUN_25a0b0c0000(&local_98);
  FUN_25a0b0c0000(&local_88);
  FUN_25a0b0c05f0(&runtime_string_result,&local_68,1,&PTR_DAT_25a0b0e00d8);
  FUN_25a0b0c0000(&local_68);
  FUN_25a0b0c0000(&local_78);
  return;
}



/* Address: 25a0b0d5df0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d5df0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  
  iVar6 = param_3;
  if (param_3 < param_2) {
    iVar6 = param_2;
  }
  if (param_2 < param_3) {
    param_3 = param_2;
  }
  if ((((-1 < iVar6) && (param_3 < DAT_25a0b0e4cd0)) && (-1 < param_1)) &&
     (param_1 < DAT_25a0b0e4ccc)) {
    iVar3 = 0;
    if (0 < param_3) {
      iVar3 = param_3;
    }
    iVar2 = DAT_25a0b0e4cd0 + -1;
    if (iVar6 < DAT_25a0b0e4cd0) {
      iVar2 = iVar6;
    }
    if (iVar3 <= iVar2) {
      param_1 = DAT_25a0b0e4ccc * iVar3 + param_1;
      do {
        uVar4 = (ulonglong)param_1;
        if (DAT_25a0b0e4cf8 <= uVar4) {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xf0281000801f6);
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        uVar5 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar4;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar5 = uVar4;
        }
        iVar3 = iVar3 + 1;
        *(undefined4 *)(ram0x025a0b0e4d0c + uVar5 * 4) = param_4;
        param_1 = DAT_25a0b0e4ccc + param_1;
      } while (iVar3 <= iVar2);
    }
  }
  return;
}



/* Address: 25a0b0d5ef0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d5ef0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  
  lVar3 = ram0x025a0b0e4d0c;
  iVar8 = param_2;
  if (param_2 < param_1) {
    iVar8 = param_1;
  }
  if (param_1 < param_2) {
    param_2 = param_1;
  }
  if ((((-1 < iVar8) && (param_2 < DAT_25a0b0e4ccc)) && (-1 < param_3)) &&
     (param_3 < DAT_25a0b0e4cd0)) {
    iVar11 = 0;
    if (0 < param_2) {
      iVar11 = param_2;
    }
    iVar4 = DAT_25a0b0e4ccc + -1;
    if (iVar8 < DAT_25a0b0e4ccc) {
      iVar4 = iVar8;
    }
    uVar5 = (iVar4 - iVar11) + 1;
    if (uVar5 != 0) {
      param_3 = DAT_25a0b0e4ccc * param_3;
      uVar7 = param_3 + iVar11;
      uVar6 = uVar5 + uVar7;
      if ((CARRY4(uVar5,uVar7)) || (DAT_25a0b0e4cf8 < uVar6)) {
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x30299000801f6);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar5 = iVar11 + 1 + param_3;
      if (uVar5 < uVar6) {
        uVar5 = uVar6;
      }
      uVar5 = (uVar5 - param_3) - iVar11;
      if (0x13 < uVar5) {
        uVar10 = iVar11 + 1 + param_3;
        if (uVar10 < uVar6) {
          uVar10 = uVar6;
        }
        if ((int)uVar7 <= (int)(uVar10 - 1)) {
          uVar12 = uVar5 & 0xfffffff8;
          uVar10 = uVar7 + uVar12;
          uVar9 = uVar12;
          do {
            puVar1 = (undefined4 *)(lVar3 + (longlong)(int)uVar7 * 4);
            *puVar1 = param_4;
            puVar1[1] = param_4;
            puVar1[2] = param_4;
            puVar1[3] = param_4;
            puVar1 = (undefined4 *)(lVar3 + 0x10 + (longlong)(int)uVar7 * 4);
            *puVar1 = param_4;
            puVar1[1] = param_4;
            puVar1[2] = param_4;
            puVar1[3] = param_4;
            uVar7 = uVar7 + 8;
            uVar9 = uVar9 - 8;
          } while (uVar9 != 0);
          uVar7 = uVar10;
          if (uVar5 == uVar12) {
            return;
          }
        }
      }
      do {
        *(undefined4 *)(lVar3 + (longlong)(int)uVar7 * 4) = param_4;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar6);
    }
  }
  return;
}



/* Address: 25a0b0d6040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d6040(uint param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  code *pcVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  
  uVar13 = param_1;
  if ((int)param_1 < (int)param_3) {
    uVar13 = param_3;
  }
  if ((int)param_3 < (int)param_1) {
    param_1 = param_3;
  }
  iVar9 = param_2;
  if (param_2 < param_4) {
    iVar9 = param_4;
  }
  if (param_4 < param_2) {
    param_2 = param_4;
  }
  if ((((-1 < (int)uVar13) && (-1 < iVar9)) && ((int)param_1 < DAT_25a0b0e4ccc)) &&
     (param_2 < DAT_25a0b0e4cd0)) {
    if ((int)param_1 < 1) {
      param_1 = 0;
    }
    iVar11 = 0;
    if (0 < param_2) {
      iVar11 = param_2;
    }
    uVar3 = DAT_25a0b0e4ccc - 1;
    if ((int)uVar13 < DAT_25a0b0e4ccc) {
      uVar3 = uVar13;
    }
    iVar7 = DAT_25a0b0e4cd0 + -1;
    if (iVar9 < DAT_25a0b0e4cd0) {
      iVar7 = iVar9;
    }
    if (iVar11 <= iVar7) {
      uVar13 = (uVar3 - param_1) + 1;
      if (uVar13 == 0) {
        do {
          iVar11 = iVar11 + 1;
        } while (iVar11 <= iVar7);
      }
      else {
        iVar8 = 0;
        iVar9 = iVar11;
        do {
          lVar4 = ram0x025a0b0e4d0c;
          iVar5 = DAT_25a0b0e4ccc * iVar9;
          uVar12 = iVar5 + param_1;
          uVar14 = uVar12 + uVar13;
          if ((CARRY4(uVar12,uVar13)) || (DAT_25a0b0e4cf8 < uVar14)) {
            (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x60793000801f6);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          uVar10 = param_1 + 1 + iVar5;
          uVar17 = uVar10;
          if (uVar10 < uVar14) {
            uVar17 = uVar14;
          }
          iVar15 = (iVar11 + iVar8) * DAT_25a0b0e4ccc;
          uVar17 = (uVar17 - param_1) - iVar15;
          if (uVar17 < 0x14) {
LAB_25a0b0d6210:
            do {
              *(undefined4 *)(lVar4 + (longlong)(int)uVar12 * 4) = param_5;
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar14);
          }
          else {
            uVar6 = uVar10;
            if (uVar10 < uVar14) {
              uVar6 = uVar14;
            }
            if ((int)(((uVar6 + ~param_1) - iVar15) + uVar12) < (int)uVar12) goto LAB_25a0b0d6210;
            uVar6 = iVar5 + uVar3 + 1;
            uVar16 = uVar12 + (uVar17 & 0xfffffff8);
            if (uVar6 <= uVar10) {
              uVar6 = uVar10;
            }
            uVar10 = uVar6 - uVar12 & 0xfffffff8;
            do {
              puVar1 = (undefined4 *)(lVar4 + (longlong)(int)uVar12 * 4);
              *puVar1 = param_5;
              puVar1[1] = param_5;
              puVar1[2] = param_5;
              puVar1[3] = param_5;
              puVar1 = (undefined4 *)(lVar4 + 0x10 + (longlong)(int)uVar12 * 4);
              *puVar1 = param_5;
              puVar1[1] = param_5;
              puVar1[2] = param_5;
              puVar1[3] = param_5;
              uVar12 = uVar12 + 8;
              uVar10 = uVar10 - 8;
            } while (uVar10 != 0);
            uVar12 = uVar16;
            if (uVar17 != (uVar17 & 0xfffffff8)) goto LAB_25a0b0d6210;
          }
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 + 1;
        } while (iVar9 <= iVar7);
      }
    }
  }
  return;
}



/* Address: 25a0b0d6270 */

double FUN_25a0b0d6270(double param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double local_a0 [13];
  
  if (1 < param_2) {
    return 0.0;
  }
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x22);
  dVar7 = runtime_double_result;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x23);
  dVar11 = runtime_double_result;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x37);
  dVar8 = dVar11;
  if (runtime_double_result <= dVar11) {
    dVar8 = runtime_double_result;
  }
  dVar11 = (double)(~-(ulonglong)(0.0 < runtime_double_result) & (ulonglong)dVar11 |
                   (ulonglong)dVar8 & -(ulonglong)(0.0 < runtime_double_result));
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x24);
  dVar8 = runtime_double_result;
  if (state_v_225ad == false) {
    if (param_1 <= 0.0) {
      return dVar7;
    }
    MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x25);
    dVar5 = runtime_double_result * state_v_225b8;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1b);
    dVar10 = runtime_double_result;
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1a);
    if (dVar10 <= 0.0) {
      return dVar7;
    }
    if (runtime_double_result <= 0.0) {
      return dVar7;
    }
    if (dVar8 <= 0.0) {
      return dVar7;
    }
    if ((dVar10 != 0.0) || (NAN(dVar10))) {
      dVar10 = (param_1 / dVar10) * runtime_double_result * dVar8;
      if (dVar10 <= 0.0) {
        return dVar7;
      }
      if ((dVar10 == 0.0) && (!NAN(dVar10))) goto LAB_25a0b0d69c9;
      dVar10 = (dVar5 / DAT_25a0b0dbe88) / dVar10;
      dVar9 = ABS(dVar10);
      uVar2 = (uint)((ulonglong)dVar9 >> 0x20);
      dVar5 = dVar10;
      if (uVar2 >> 0x14 < 0x3ff) {
        if ((dVar9 != 0.0) && (dVar5 = 0.0, (longlong)dVar10 < 0)) {
          dVar5 = DAT_25a0b0dbe90;
        }
      }
      else if (((uVar2 >> 0x16 < 0x10d) &&
               (bVar4 = 0x33 - (char)((ulonglong)dVar9 >> 0x34),
               dVar6 = (double)(((ulonglong)dVar9 >> (bVar4 & 0x3f)) << (bVar4 & 0x3f)),
               dVar5 = dVar6, (longlong)dVar10 < 1)) &&
              (dVar5 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar9)) {
        dVar5 = dVar5 + DAT_25a0b0dbe90;
      }
      dVar10 = dVar5 * dVar8;
      if (dVar5 * dVar8 <= dVar7) {
        dVar10 = dVar7;
      }
      if (dVar11 <= dVar10) {
        dVar10 = dVar11;
      }
      if (dVar8 == 0.0) goto joined_r0x025a0b0d6963;
      goto LAB_25a0b0d638f;
    }
  }
  else {
    dVar10 = state_v_225b0;
    if (runtime_double_result == 0.0) {
joined_r0x025a0b0d6963:
      if (NAN(dVar8)) goto LAB_25a0b0d638f;
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x140430000001f7);
    }
    else {
LAB_25a0b0d638f:
      dVar5 = state_v_225c8;
      if (DAT_25a0b0e25ac == '\0') {
        dVar5 = DAT_25a0b0dbe98;
      }
      if (state_v_225c0 == false) {
        dVar5 = DAT_25a0b0dbe98;
      }
      dVar9 = dVar10 * dVar5;
      if (dVar10 * dVar5 <= dVar7) {
        dVar9 = dVar7;
      }
      if (dVar11 <= dVar9) {
        dVar9 = dVar11;
      }
      dVar9 = dVar9 / dVar8;
      dVar5 = ABS(dVar9);
      dVar10 = dVar9;
      if ((uint)((ulonglong)dVar5 >> 0x34) < 0x3ff) {
        if ((dVar5 != 0.0) && (dVar10 = 0.0, (longlong)dVar9 < 0)) {
          dVar10 = DAT_25a0b0dbe90;
        }
      }
      else if ((((ulonglong)dVar5 < 0x4340000000000000) &&
               (bVar4 = 0x33 - (char)((ulonglong)dVar5 >> 0x34),
               dVar6 = (double)(((ulonglong)dVar5 >> (bVar4 & 0x3f)) << (bVar4 & 0x3f)),
               dVar10 = dVar6, (longlong)dVar9 < 1)) &&
              (dVar10 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar5)) {
        dVar10 = dVar10 + DAT_25a0b0dbe90;
      }
      dVar10 = dVar10 * dVar8;
      MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x2a);
      dVar5 = runtime_double_result;
      MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
      local_a0[0] = 0.0;
      cVar3 = (*(code *)&MT5_OrderCalcMargin)
                        (0x25a0930b4c8,0,&_Symbol,dVar8,runtime_double_result,local_a0);
      if (cVar3 == '\0') {
LAB_25a0b0d6763:
        if (dVar11 <= dVar10) {
          dVar10 = dVar11;
        }
        if (dVar10 <= dVar7) {
          dVar10 = dVar7;
        }
        dVar10 = dVar10 / dVar8;
        dVar5 = ABS(dVar10);
        dVar11 = dVar10;
        if ((ulonglong)dVar5 < 0x3ff0000000000000) {
          if ((dVar5 != 0.0) && (dVar11 = 0.0, (longlong)dVar10 < 0)) {
            dVar11 = DAT_25a0b0dbe90;
          }
        }
        else if ((((ulonglong)dVar5 < 0x4340000000000000) &&
                 (bVar4 = 0x33 - (char)((ulonglong)dVar5 >> 0x34),
                 dVar9 = (double)(((ulonglong)dVar5 >> (bVar4 & 0x3f)) << (bVar4 & 0x3f)),
                 dVar11 = dVar9, (longlong)dVar10 < 1)) &&
                (dVar11 = (double)((ulonglong)dVar9 | 0x8000000000000000), dVar9 != dVar5)) {
          dVar11 = dVar11 + DAT_25a0b0dbe90;
        }
        dVar11 = dVar11 * dVar8;
        if ((DAT_25a0b0e258c != '\0') && (DAT_25a0b0dbe88 <= dVar11)) {
          dVar11 = DAT_25a0b0dbe88;
        }
        dVar11 = dVar11 / dVar8;
        dVar5 = ABS(dVar11);
        dVar10 = dVar11;
        if ((ulonglong)dVar5 < 0x3ff0000000000000) {
          if ((dVar5 != 0.0) && (dVar10 = 0.0, (longlong)dVar11 < 0)) {
            dVar10 = DAT_25a0b0dbe90;
          }
        }
        else if ((((ulonglong)dVar5 < 0x4340000000000000) &&
                 (bVar4 = 0x33 - (char)((ulonglong)dVar5 >> 0x34),
                 dVar9 = (double)(((ulonglong)dVar5 >> (bVar4 & 0x3f)) << (bVar4 & 0x3f)),
                 dVar10 = dVar9, (longlong)dVar11 < 1)) &&
                (dVar10 = (double)((ulonglong)dVar9 | 0x8000000000000000), dVar9 != dVar5)) {
          dVar10 = dVar10 + DAT_25a0b0dbe90;
        }
        dVar11 = dVar8 * dVar10;
        if (dVar8 * dVar10 <= dVar7) {
          dVar11 = dVar7;
        }
        if ((longlong)dVar11 != -0x8000000000000000) {
          dVar7 = (double)(longlong)dVar11;
          dVar11 = (double)(longlong)
                           ((dVar11 - dVar7) * DAT_25a0b0dbe88 +
                           *(double *)(&DAT_25a0b0dbea8 + (ulonglong)(0.0 < dVar11) * 8)) /
                   DAT_25a0b0dbe88 + dVar7;
        }
        return dVar11;
      }
      if (local_a0[0] <= 0.0) goto LAB_25a0b0d6763;
      if ((local_a0[0] != 0.0) || (NAN(local_a0[0]))) {
        local_a0[0] = (dVar5 * DAT_25a0b0dbea0) / local_a0[0];
        dVar9 = ABS(local_a0[0]);
        dVar5 = local_a0[0];
        if ((ulonglong)dVar9 < 0x3ff0000000000000) {
          if ((dVar9 != 0.0) && (dVar5 = 0.0, (longlong)local_a0[0] < 0)) {
            dVar5 = DAT_25a0b0dbe90;
          }
        }
        else if ((((ulonglong)dVar9 < 0x4340000000000000) &&
                 (bVar4 = 0x33 - (char)((ulonglong)dVar9 >> 0x34),
                 dVar6 = (double)(((ulonglong)dVar9 >> (bVar4 & 0x3f)) << (bVar4 & 0x3f)),
                 dVar5 = dVar6, (longlong)local_a0[0] < 1)) &&
                (dVar5 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar9)) {
          dVar5 = dVar5 + DAT_25a0b0dbe90;
        }
        dVar9 = dVar5 * dVar8;
        if (dVar5 * dVar8 <= dVar7) {
          dVar9 = dVar7;
        }
        if (dVar9 <= dVar10) {
          dVar10 = dVar9;
        }
        goto LAB_25a0b0d6763;
      }
    }
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x370438000001f7);
  }
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x210424000001f7);
LAB_25a0b0d69c9:
  (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x180427000001f7);
  pcVar1 = (code *)swi(3);
  dVar7 = (double)(*pcVar1)();
  return dVar7;
}



/* Address: 25a0b0d69f0 */

double FUN_25a0b0d69f0(double param_1,int param_2)

{
  wchar16 wVar1;
  wchar16 wVar2;
  uint uVar3;
  code *pcVar4;
  double dVar5;
  uint uVar6;
  double dVar7;
  char cVar8;
  int iVar9;
  uint extraout_EAX;
  ulonglong uVar10;
  longlong lVar11;
  byte bVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  uint uVar16;
  bool bVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined4 local_d0;
  wchar16 *local_cc;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b0;
  undefined8 local_ac;
  double local_a0 [12];
  
  dVar14 = 0.0;
  if ((0.0 < param_1) && (0.0 < DAT_25a0b0e4930)) {
    MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,(uint)(param_2 != 1) * 3 + 1);
    dVar7 = runtime_double_result;
    MT5_AccountInfoDouble((void *)0x25a0930b4c8,0x2a);
    dVar5 = runtime_double_result;
    dVar14 = DAT_25a0b0e4940;
    local_d0 = 0;
    local_cc = (wchar16 *)0x0;
    if (0.0 < DAT_25a0b0e4948) {
      iVar9 = MT5_PositionsTotal((void *)0x25a0930b4c8);
      dVar18 = 0.0;
      if (-1 < iVar9 + -1) {
        iVar9 = iVar9 + -1;
        do {
          uVar10 = MT5_PositionGetTicket((void *)0x25a0930b4c8,iVar9);
          if (uVar10 != 0) {
            local_b0 = 0;
            local_c0 = 0;
            local_ac = 0;
            local_bc = 0;
            MT5_PositionGetString((void *)0x25a0930b4c8,0);
            FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,&PTR_DAT_25a0b0dfe18);
            FUN_25a0b0c05f0(&local_c0,&local_b0,0,&PTR_DAT_25a0b0dfe28);
            FUN_25a0b0c05f0(&runtime_string_result,&local_c0,1,&PTR_DAT_25a0b0dfe38);
            FUN_25a0b0c0000(&local_c0);
            FUN_25a0b0c0000(&local_b0);
            FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0ba0);
            if (local_cc == _Symbol.text) {
LAB_25a0b0d6c99:
              lVar11 = MT5_PositionGetInteger((void *)0x25a0930b4c8,2);
              if ((param_2 == 0) != ((int)lVar11 != 0)) {
                MT5_PositionGetDouble((void *)0x25a0930b4c8,3);
                dVar18 = dVar18 + runtime_double_result;
              }
            }
            else if ((local_cc != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
              uVar16 = *(uint *)(local_cc + -2);
              uVar3 = *(uint *)(_Symbol.text + -2);
              uVar6 = uVar3;
              if (uVar16 < uVar3) {
                uVar6 = uVar16;
              }
              iVar13 = uVar16 - uVar3;
              if (uVar6 != 0) {
                uVar10 = 1;
                do {
                  wVar1 = local_cc[uVar10 - 1];
                  wVar2 = _Symbol.text[uVar10 - 1];
                  if (uVar6 <= uVar10) break;
                  uVar10 = uVar10 + 1;
                } while (wVar1 == wVar2);
                if (wVar1 != wVar2) {
                  iVar13 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
                }
              }
              if (iVar13 == 0) goto LAB_25a0b0d6c99;
            }
          }
          bVar17 = 0 < iVar9;
          iVar9 = iVar9 + -1;
        } while (bVar17);
      }
      iVar9 = MT5_OrdersTotal((void *)0x25a0930b4c8);
      if (-1 < iVar9 + -1) {
        iVar9 = iVar9 + -1;
        do {
          uVar10 = MT5_OrderGetTicket((void *)0x25a0930b4c8,iVar9);
          DAT_25a0b0e2330 = -(ulonglong)(uVar10 == 0) | uVar10;
          if (uVar10 != 0) {
            local_b0 = 0;
            local_c0 = 0;
            local_ac = 0;
            local_bc = 0;
            MT5_OrderGetString((void *)0x25a0930b4c8,0);
            FUN_25a0b0c05f0(&local_b0,&runtime_string_result,1,&PTR_DAT_25a0b0dfd90);
            FUN_25a0b0c05f0(&local_c0,&local_b0,0,&PTR_DAT_25a0b0dfda0);
            FUN_25a0b0c05f0(&runtime_string_result,&local_c0,1,&PTR_DAT_25a0b0dfdb0);
            FUN_25a0b0c0000(&local_c0);
            FUN_25a0b0c0000(&local_b0);
            FUN_25a0b0c05f0(&local_d0,&runtime_string_result,1,&PTR_DAT_25a0b0e0bb0);
            if (local_cc == _Symbol.text) {
LAB_25a0b0d6eb9:
              lVar11 = MT5_OrderGetInteger((void *)0x25a0930b4c8,4);
              extraout_EAX = (uint)lVar11;
              if ((param_2 != 0) || (extraout_EAX != 4 && (extraout_EAX & 0xfffffffb) != 2)) {
                if ((param_2 == 0) || (extraout_EAX != 5 && (extraout_EAX & 0xfffffffb) != 3))
                goto LAB_25a0b0d6d52;
              }
              MT5_OrderGetDouble((void *)0x25a0930b4c8,8);
              dVar18 = dVar18 + runtime_double_result;
            }
            else if ((local_cc != (wchar16 *)0x0) && (_Symbol.text != (wchar16 *)0x0)) {
              uVar16 = *(uint *)(local_cc + -2);
              uVar3 = *(uint *)(_Symbol.text + -2);
              uVar6 = uVar3;
              if (uVar16 < uVar3) {
                uVar6 = uVar16;
              }
              iVar13 = uVar16 - uVar3;
              if (uVar6 != 0) {
                uVar10 = 1;
                do {
                  wVar1 = local_cc[uVar10 - 1];
                  wVar2 = _Symbol.text[uVar10 - 1];
                  if (uVar6 <= uVar10) break;
                  uVar10 = uVar10 + 1;
                } while (wVar1 == wVar2);
                if (wVar1 != wVar2) {
                  iVar13 = (uint)(ushort)wVar1 - (uint)(ushort)wVar2;
                }
              }
              if (iVar13 == 0) goto LAB_25a0b0d6eb9;
            }
          }
LAB_25a0b0d6d52:
          bVar17 = 0 < iVar9;
          iVar9 = iVar9 + -1;
        } while (bVar17);
      }
      if (DAT_25a0b0e4948 - dVar18 <= dVar14) {
        dVar14 = DAT_25a0b0e4948 - dVar18;
      }
      if (dVar14 <= 0.0) {
        dVar14 = 0.0;
      }
    }
    FUN_25a0b0c0000(&local_d0);
    dVar18 = DAT_25a0b0dbec0;
    if ((DAT_25a0b0e4930 == 0.0) && (!NAN(DAT_25a0b0e4930))) {
LAB_25a0b0d7254:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x14044d000001f7);
      pcVar4 = (code *)swi(3);
      dVar14 = (double)(*pcVar4)();
      return dVar14;
    }
    if (dVar14 <= param_1) {
      param_1 = dVar14;
    }
    param_1 = param_1 / DAT_25a0b0e4930;
    dVar14 = ABS(param_1);
    uVar16 = (uint)((ulonglong)dVar14 >> 0x20);
    dVar19 = param_1;
    if (uVar16 >> 0x14 < 0x3ff) {
      if ((dVar14 != 0.0) && (dVar19 = 0.0, (longlong)param_1 < 0)) {
        dVar19 = DAT_25a0b0dbec0;
      }
    }
    else if (((uVar16 >> 0x16 < 0x10d) &&
             (bVar12 = 0x33 - (char)((ulonglong)dVar14 >> 0x34),
             dVar20 = (double)(((ulonglong)dVar14 >> (bVar12 & 0x3f)) << (bVar12 & 0x3f)),
             dVar19 = dVar20, (longlong)param_1 < 1)) &&
            (dVar19 = (double)((ulonglong)dVar20 | 0x8000000000000000), dVar20 != dVar14)) {
      dVar19 = dVar19 + DAT_25a0b0dbec0;
    }
    dVar19 = DAT_25a0b0e4930 * dVar19;
    dVar14 = 0.0;
    if (DAT_25a0b0e4938 <= dVar19) {
      dVar5 = dVar5 * DAT_25a0b0dbeb8;
      uVar16 = 0;
      while( true ) {
        local_a0[0] = 0.0;
        cVar8 = (*(code *)&MT5_OrderCalcMargin)
                          (0x25a0930b4c8,param_2,&_Symbol,dVar19,dVar7,local_a0);
        if (((cVar8 != '\0') && (0.0 < local_a0[0])) && (local_a0[0] <= dVar5)) break;
        if ((DAT_25a0b0e4930 == 0.0) && (!NAN(DAT_25a0b0e4930))) {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x170458000001f7);
          goto LAB_25a0b0d7254;
        }
        dVar20 = (dVar19 - DAT_25a0b0e4930) / DAT_25a0b0e4930;
        dVar14 = ABS(dVar20);
        dVar19 = dVar20;
        if ((ulonglong)dVar14 < 0x3ff0000000000000) {
          if ((dVar14 != 0.0) && (dVar19 = 0.0, (longlong)dVar20 < 0)) {
            dVar19 = dVar18;
          }
        }
        else if ((((ulonglong)dVar14 < 0x4340000000000000) &&
                 (bVar12 = 0x33 - (char)((ulonglong)dVar14 >> 0x34),
                 dVar15 = (double)(((ulonglong)dVar14 >> (bVar12 & 0x3f)) << (bVar12 & 0x3f)),
                 dVar19 = dVar15, (longlong)dVar20 < 1)) &&
                (dVar19 = (double)((ulonglong)dVar15 | 0x8000000000000000), dVar15 != dVar14)) {
          dVar19 = dVar19 + dVar18;
        }
        dVar19 = dVar19 * DAT_25a0b0e4930;
        if (dVar19 < DAT_25a0b0e4938) {
          return 0.0;
        }
        bVar17 = 0x1869e < uVar16;
        uVar16 = uVar16 + 1;
        if (bVar17) {
          return 0.0;
        }
      }
      dVar14 = dVar19;
      if ((longlong)dVar19 != -0x8000000000000000) {
        dVar14 = (double)(longlong)dVar19;
        dVar14 = (double)(longlong)
                         ((dVar19 - dVar14) * DAT_25a0b0dbec8 +
                         *(double *)(&DAT_25a0b0dbed0 + (ulonglong)(0.0 < dVar19) * 8)) /
                 DAT_25a0b0dbec8 + dVar14;
      }
    }
  }
  return dVar14;
}



/* Address: 25a0b0d7280 */

undefined4
FUN_25a0b0d7280(int param_1,double param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined8 local_74;
  
  local_78 = 0;
  local_74 = 0;
  if (param_1 == 4) {
    local_80 = 0;
    local_88 = 0;
    if (0.0 < param_2) {
      FUN_25a0b0c05f0(&local_88,&_Symbol,0,&PTR_DAT_25a0b0dff08);
      uVar2 = 4;
      goto LAB_25a0b0d73dd;
    }
LAB_25a0b0d73eb:
    local_80 = 0;
    local_88 = 0;
    DAT_25a0b0e2110 = 0x271e;
    uVar1 = 0;
  }
  else {
    local_80 = 0;
    local_88 = 0;
    if (param_2 <= 0.0) goto LAB_25a0b0d73eb;
    FUN_25a0b0c05f0(&local_88,&_Symbol,0,&PTR_DAT_25a0b0dff18);
    uVar2 = 5;
LAB_25a0b0d73dd:
    uVar1 = FUN_25a0b0d2f10(&local_88,uVar2,param_2,param_3,param_4,param_5,2,param_6);
  }
  FUN_25a0b0c0000(&local_88);
  if (((DAT_25a0b0e258c != '\0') || ((char)uVar1 != '\0')) || (DAT_25a0b0e2110 != 0x2726))
  goto LAB_25a0b0d758c;
  if (DAT_25a0b0e258f != '\0') {
    MT5_Dispatch((void *)0x25a0930b4c8,0xd,2,0x590008,&string_ref_25a0b0de568,0x520004,0x2726);
  }
  if (param_1 == 4) {
    local_80 = 0;
    local_88 = 0;
    if (0.0 < param_2) {
      FUN_25a0b0c05f0(&local_88,&_Symbol,0,&PTR_DAT_25a0b0dff08);
      uVar2 = 4;
      goto LAB_25a0b0d756e;
    }
LAB_25a0b0d757c:
    local_80 = 0;
    local_88 = 0;
    DAT_25a0b0e2110 = 0x271e;
    uVar1 = 0;
  }
  else {
    local_80 = 0;
    local_88 = 0;
    if (param_2 <= 0.0) goto LAB_25a0b0d757c;
    FUN_25a0b0c05f0(&local_88,&_Symbol,0,&PTR_DAT_25a0b0dff18);
    uVar2 = 5;
LAB_25a0b0d756e:
    uVar1 = FUN_25a0b0d2f10(&local_88,uVar2,param_2,param_3,param_4,param_5,0,0);
  }
  FUN_25a0b0c0000(&local_88);
LAB_25a0b0d758c:
  FUN_25a0b0c0000(&local_78);
  return uVar1;
}



/* Address: 25a0b0d75c0 */

undefined8 FUN_25a0b0d75c0(double *param_1)

{
  bool bVar1;
  bool bVar2;
  code *pcVar3;
  uint uVar4;
  double dVar5;
  longlong lVar6;
  undefined8 uVar7;
  byte bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  
  dVar5 = DAT_25a0b0e4938;
  dVar12 = DAT_25a0b0e4930;
  uVar7 = 0;
  if (((0.0 < DAT_25a0b0e4930) && (0.0 < DAT_25a0b0e4938)) && (0.0 < DAT_25a0b0e4940)) {
    bVar1 = NAN(DAT_25a0b0e4930);
    bVar2 = DAT_25a0b0e4930 == 0.0;
    dVar13 = *param_1;
    if (*param_1 <= DAT_25a0b0e4938) {
      dVar13 = DAT_25a0b0e4938;
    }
    if (DAT_25a0b0e4940 <= dVar13) {
      dVar13 = DAT_25a0b0e4940;
    }
    *param_1 = dVar13;
    if ((bVar2) && (!bVar1)) {
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1a0883000001f7);
      pcVar3 = (code *)swi(3);
      uVar7 = (*pcVar3)();
      return uVar7;
    }
    dVar13 = dVar13 / dVar12;
    lVar6 = -0x8000000000000000;
    dVar10 = ABS(dVar13);
    uVar4 = (uint)((ulonglong)dVar10 >> 0x20);
    dVar9 = dVar13;
    if (uVar4 >> 0x14 < 0x3ff) {
      if ((dVar10 != 0.0) && (dVar9 = 0.0, (longlong)dVar13 < 0)) {
        dVar9 = DAT_25a0b0dbee0;
      }
    }
    else if (((uVar4 >> 0x16 < 0x10d) &&
             (bVar8 = 0x33 - (char)((ulonglong)dVar10 >> 0x34),
             dVar11 = (double)(((ulonglong)dVar10 >> (bVar8 & 0x3f)) << (bVar8 & 0x3f)),
             dVar9 = dVar11, (longlong)dVar13 < 1)) &&
            (dVar9 = (double)((ulonglong)dVar11 | 0x8000000000000000), dVar11 != dVar10)) {
      dVar9 = dVar9 + DAT_25a0b0dbee0;
    }
    dVar12 = dVar12 * dVar9;
    if ((longlong)dVar12 != -0x8000000000000000) {
      dVar13 = (double)(longlong)dVar12;
      lVar6 = (longlong)
              ((dVar12 - dVar13) * DAT_25a0b0dbee8 +
              *(double *)(&DAT_25a0b0dbef0 + (ulonglong)(0.0 < dVar12) * 8));
      dVar12 = (double)lVar6 / DAT_25a0b0dbee8 + dVar13;
    }
    *param_1 = dVar12;
    uVar7 = CONCAT71((int7)((ulonglong)lVar6 >> 8),dVar5 <= dVar12);
  }
  return uVar7;
}



/* Address: 25a0b0d7770 */

void FUN_25a0b0d7770(double *param_1)

{
  longlong lVar1;
  code *pcVar2;
  byte bVar3;
  ulonglong uVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  
  dVar6 = *param_1;
  if (0.0 < dVar6) {
    if (0.0 < DAT_25a0b0e4928) {
      if ((DAT_25a0b0e4928 == 0.0) && (!NAN(DAT_25a0b0e4928))) {
        (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x280879000001f7);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      dVar6 = dVar6 / DAT_25a0b0e4928;
      uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
      lVar1 = (ulonglong)uVar5 - 0x3ff;
      dVar7 = dVar6;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar1 != -1) {
            dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000);
          }
        }
        else {
          bVar3 = (byte)lVar1;
          if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar7 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                            -0x10000000000000 >> (bVar3 & 0x3f));
          }
        }
      }
      else if (lVar1 == 0x400) {
        dVar7 = dVar6 + dVar6;
      }
      dVar6 = dVar7 * DAT_25a0b0e4928;
    }
    if ((longlong)dVar6 != -0x8000000000000000) {
      dVar7 = (double)(longlong)dVar6;
      uVar4 = 0xb;
      if (DAT_25a0b0e4950 < 0xb) {
        uVar4 = (ulonglong)DAT_25a0b0e4950;
      }
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar7) * *(double *)(&DAT_25a0b0dbf50 + uVar4 * 8) +
                      *(double *)(&DAT_25a0b0dbf00 + (ulonglong)(0.0 < dVar6) * 8)) /
              *(double *)(&DAT_25a0b0dbf50 + uVar4 * 8) + dVar7;
    }
    *param_1 = dVar6;
  }
  return;
}



/* Address: 25a0b0d78f0 */

void FUN_25a0b0d78f0(longlong param_1,longlong param_2,undefined8 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  longlong lVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  int iVar10;
  ulonglong uVar11;
  MqlStringAnalysisView *pMVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined **ppuVar17;
  ulonglong uVar18;
  uint uVar19;
  uint uVar20;
  MqlStringAnalysisView local_80;
  undefined4 local_70;
  longlong local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  ulonglong uVar16;
  
  local_70 = 0;
  local_80.opaque = 0;
  local_60 = 0;
  local_6c = 0;
  local_80.text = (wchar16 *)0x0;
  local_5c = 0;
  local_50 = 0;
  uStack_4c = 0;
  local_48 = 0;
  FUN_25a0b0c05f0(&local_80,&string_ref_25a0b0de860);
  lVar4 = *(longlong *)(param_2 + 4);
  if (lVar4 != 0) {
    uVar19 = *(uint *)(lVar4 + -4);
    uVar16 = (ulonglong)uVar19;
    if ((uVar16 != 0) || (local_80.text == (wchar16 *)0x0)) {
      if (local_80.text == (wchar16 *)0x0) {
        uVar20 = 0;
        uVar13 = uVar19;
      }
      else {
        uVar20 = *(uint *)(local_80.text + -2);
        uVar13 = uVar19 + uVar20;
      }
      cVar9 = FUN_25a0b0c0060(&local_80);
      if (cVar9 == '\0') goto LAB_25a0b0d7ebe;
      if (uVar16 != 0) {
        if (uVar19 < 0x10) {
          uVar11 = 0;
        }
        else if ((longlong)local_80.text + ((ulonglong)uVar20 * 2 - lVar4) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar18 = 0;
          uVar11 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            puVar2 = (undefined4 *)(lVar4 + uVar18);
            uVar6 = puVar2[1];
            uVar7 = puVar2[2];
            uVar8 = puVar2[3];
            puVar1 = (undefined4 *)((longlong)local_80.text + uVar18 + (ulonglong)uVar20 * 2);
            *puVar1 = *puVar2;
            puVar1[1] = uVar6;
            puVar1[2] = uVar7;
            puVar1[3] = uVar8;
            uVar18 = uVar18 + 0x10;
          } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
          if (uVar11 == uVar16) goto LAB_25a0b0d7a72;
        }
        do {
          local_80.text[uVar20 + uVar11] = *(wchar16 *)(lVar4 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar16 != uVar11);
      }
LAB_25a0b0d7a72:
      *(uint *)(local_80.text + -2) = uVar13;
      local_80.text[uVar13] = L'\0';
    }
  }
  uVar19 = 0;
  FUN_25a0b0c05f0(&local_70,&local_80,0,&PTR_DAT_25a0b0e0c00);
  uVar20 = DAT_25a0b0de854;
  uVar16 = (ulonglong)DAT_25a0b0de854;
  if ((uVar16 != 0) || (local_6c == 0)) {
    if (local_6c != 0) {
      uVar19 = *(uint *)(local_6c + -4);
    }
    uVar14 = DAT_25a0b0de854 + uVar19;
    uVar13 = 0x104;
    if ((0x103 < uVar14) &&
       ((0x7ffffffd < uVar14 || (uVar13 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar13)))) {
      uVar13 = 0x7ffffffe;
    }
    cVar9 = FUN_25a0b0c0060(&local_70,uVar13);
    if (cVar9 == '\0') {
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1b0567000001f9);
LAB_25a0b0d7ebe:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x150567000001f9);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    if (uVar16 != 0) {
      lVar4 = local_6c + (ulonglong)uVar19 * 2;
      if (uVar20 < 0x10) {
        uVar11 = 0;
      }
      else if (lVar4 - 0x25a0b0de858U < 0x20) {
        uVar11 = 0;
      }
      else {
        uVar18 = 0;
        uVar11 = (ulonglong)(uVar20 & 0xfffffff8);
        do {
          uVar6 = *(undefined4 *)(uVar18 + 0x25a0b0de85c);
          uVar7 = *(undefined4 *)((longlong)&string_ref_25a0b0de860.opaque + uVar18);
          uVar8 = *(undefined4 *)((longlong)&string_ref_25a0b0de860.text + uVar18);
          puVar2 = (undefined4 *)(lVar4 + uVar18);
          *puVar2 = *(undefined4 *)((longlong)literal_25a0b0de858 + uVar18);
          puVar2[1] = uVar6;
          puVar2[2] = uVar7;
          puVar2[3] = uVar8;
          uVar18 = uVar18 + 0x10;
        } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
        if (uVar11 == uVar16) goto LAB_25a0b0d7ba2;
      }
      do {
        *(wchar_t *)(lVar4 + uVar11 * 2) = literal_25a0b0de858[uVar11];
        uVar11 = uVar11 + 1;
      } while (uVar16 != uVar11);
    }
LAB_25a0b0d7ba2:
    *(uint *)(local_6c + -4) = uVar14;
    *(undefined2 *)(local_6c + (ulonglong)uVar14 * 2) = 0;
  }
  FUN_25a0b0c05f0(&local_50,&local_70,0,&PTR_DAT_25a0b0e0c10);
  lVar4 = *(longlong *)(param_1 + 4);
  uVar19 = 0;
  if ((lVar4 != 0) && (uVar19 = 0, lVar4 != 0xc)) {
    uVar19 = *(uint *)(lVar4 + -4);
  }
  iVar10 = FUN_25a0b0c03a0(lVar4,CONCAT44(local_48,uStack_4c));
  if (iVar10 < 0) {
    ppuVar17 = &PTR_DAT_25a0b0e0c20;
  }
  else if ((param_4 < 1) || (iVar10 < param_4)) {
    lVar4 = CONCAT44(local_48,uStack_4c);
    iVar15 = 0;
    if ((lVar4 != 0) && (iVar15 = 0, lVar4 != 0xc)) {
      iVar15 = *(int *)(lVar4 + -4);
    }
    uVar16 = (ulonglong)(uint)(iVar15 + iVar10);
    if (iVar15 + iVar10 < (int)uVar19) {
      lVar4 = *(longlong *)(param_1 + 4);
      uVar20 = uVar19;
      if (lVar4 == 0) {
        uVar16 = (ulonglong)uVar19;
        _LastError = 0x13b1;
      }
      else {
        do {
          if ((uint)uVar16 < *(uint *)(lVar4 + -4)) {
            if (*(short *)(lVar4 + uVar16 * 2) == 0x3a) goto LAB_25a0b0d7c8e;
          }
          else {
            _LastError = 0x13b1;
          }
          uVar13 = (uint)uVar16 + 1;
          uVar16 = (ulonglong)uVar13;
        } while ((int)uVar13 < (int)uVar19);
        uVar16 = (ulonglong)uVar19;
      }
    }
    else {
LAB_25a0b0d7c8e:
      uVar20 = (uint)uVar16;
    }
    uVar20 = uVar20 + 1;
    if ((int)uVar20 < (int)uVar19) {
      lVar4 = *(longlong *)(param_1 + 4);
      if (lVar4 == 0) {
LAB_25a0b0d7dc8:
        _LastError = 0x13b1;
      }
      else {
        uVar13 = *(uint *)(lVar4 + -4);
        uVar11 = (ulonglong)uVar20;
        if (uVar20 < uVar13) {
          uVar20 = uVar13;
        }
        iVar10 = uVar20 - 1;
        do {
          iVar15 = (int)uVar16;
          if (uVar13 <= uVar11) {
            _LastError = 0x13b1;
            if ((lVar4 == 0) || (uVar20 = *(uint *)(lVar4 + -4), uVar20 <= iVar15 + 1U))
            goto LAB_25a0b0d7dc8;
LAB_25a0b0d7d51:
            if (*(short *)(lVar4 + (uVar11 & 0xffffffff) * 2) == 0x22) {
              uVar14 = iVar10 + 2;
              uVar13 = uVar14;
              goto joined_r0x025a0b0d7d61;
            }
            break;
          }
          uVar16 = (ulonglong)*(ushort *)(lVar4 + uVar11 * 2);
          if ((0x20 < uVar16) || ((0x100002600U >> (uVar16 & 0x3f) & 1) == 0)) {
            uVar20 = *(uint *)(lVar4 + -4);
            iVar10 = iVar15;
            if (iVar15 + 1U < uVar20) goto LAB_25a0b0d7d51;
            goto LAB_25a0b0d7dc8;
          }
          uVar11 = uVar11 + 1;
          uVar16 = (ulonglong)(iVar15 + 1);
        } while (iVar15 + 2 < (int)uVar19);
      }
    }
    ppuVar17 = &PTR_DAT_25a0b0e0c40;
  }
  else {
    ppuVar17 = &PTR_DAT_25a0b0e0c30;
  }
  pMVar12 = &string_ref_25a0b0dc170;
LAB_25a0b0d7df1:
  FUN_25a0b0c05f0(&local_60,pMVar12,0,ppuVar17);
  FUN_25a0b0c0000(&local_50);
  FUN_25a0b0c05f0(&runtime_string_result,&local_60,1,&PTR_DAT_25a0b0e0c70);
  FUN_25a0b0c0000(&local_60);
  FUN_25a0b0c0000(&local_80);
  FUN_25a0b0c0000(&local_70);
  return;
joined_r0x025a0b0d7d61:
  if ((int)uVar19 <= (int)uVar13) goto LAB_25a0b0d7e4f;
  if (uVar13 < uVar20) {
    sVar3 = *(short *)(lVar4 + (ulonglong)uVar13 * 2);
    if (sVar3 == 0x5c) {
      iVar10 = 2;
    }
    else {
      iVar10 = 1;
      if (sVar3 == 0x22) goto LAB_25a0b0d7e4f;
    }
  }
  else {
    _LastError = 0x13b1;
    iVar10 = 1;
  }
  uVar13 = uVar13 + iVar10;
  goto joined_r0x025a0b0d7d61;
LAB_25a0b0d7e4f:
  if ((int)uVar13 < (int)uVar19) {
    uVar19 = uVar13;
  }
  FUN_25a0b0c0810(lVar4,uVar14,uVar19 - uVar14);
  pMVar12 = &local_80;
  FUN_25a0b0c05f0(pMVar12,&runtime_string_result,1,&PTR_DAT_25a0b0e0c50);
  ppuVar17 = &PTR_DAT_25a0b0e0c60;
  goto LAB_25a0b0d7df1;
}



/* Address: 25a0b0d7ee0 */

void FUN_25a0b0d7ee0(void *param_1,uint param_2,void *param_3,ulonglong param_4,uint param_5)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  iVar1 = MT5_ObjectFind((void *)0x25a0930b4c8,0,param_1);
  if (iVar1 < 0) {
    lVar2 = MT5_Dispatch((void *)0x25a0930b4c8,0x112,6,0x550005,0,0x590008,param_1,0x520004,0x66,
                         0x520004,0,0x540005,0,0x580007,0.0);
    if ((char)lVar2 == '\0') {
      return;
    }
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0x402,0);
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0x3f3,7);
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,10,0);
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0xd0,1);
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,3,0);
    MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0xcf,100);
    MT5_ObjectSetString((void *)0x25a0930b4c8,0,param_1,0x3e9,&string_ref_25a0b0defd0);
  }
  uVar3 = MT5_ChartGetInteger((void *)0x25a0930b4c8,0,0x6a,0);
  lVar2 = 400;
  if (0 < (longlong)uVar3) {
    lVar2 = (longlong)(int)(uVar3 >> 1);
  }
  MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0x3f4,lVar2);
  MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0x3f5,(ulonglong)param_2);
  MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0x3ea,(ulonglong)param_5);
  MT5_ObjectSetInteger((void *)0x25a0930b4c8,0,param_1,0,param_4 & 0xffffffff);
  MT5_ObjectSetString((void *)0x25a0930b4c8,0,param_1,6,param_3);
  return;
}



/* Address: 25a0b0d8150 */

uint FUN_25a0b0d8150(int param_1,double param_2,double param_3)

{
  double dVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x1f);
  lVar6 = MT5_SymbolInfoInteger((void *)0x25a0930b4c8,&DAT_25a0b0dc150,0x20);
  iVar3 = (int)lVar6;
  if ((int)lVar6 < (int)lVar5) {
    iVar3 = (int)lVar5;
  }
  dVar1 = (double)(iVar3 + 2) * DAT_25a0b0e2570;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,1);
  dVar2 = runtime_double_result;
  MT5_SymbolInfoDouble((void *)0x25a0930b4c8,&DAT_25a0b0dc150,4);
  if (param_1 == 0) {
    if ((param_2 <= 0.0) || (dVar1 <= dVar2 - param_2)) {
      uVar4 = -(uint)(param_3 <= 0.0 || dVar1 <= param_3 - dVar2);
      goto LAB_25a0b0d8284;
    }
  }
  else if ((param_2 <= 0.0) || (dVar1 <= param_2 - runtime_double_result)) {
    uVar4 = -(uint)(param_3 <= 0.0 || dVar1 <= runtime_double_result - param_3);
    goto LAB_25a0b0d8284;
  }
  uVar4 = 0;
LAB_25a0b0d8284:
  return uVar4 & 0xffffff01;
}



/* Address: 25a0b0d82b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d82b0(int param_1,int param_2,undefined8 param_3,undefined8 param_4,int param_5,
                    char param_6,undefined4 param_7)

{
  longlong lVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  MqlStringAnalysisView *pMVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_70;
  
  local_80 = 0;
  local_7c = 0;
  dVar7 = (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf10;
  if ((double)DAT_25a0b0e4c88 / DAT_25a0b0dbf18 <= (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf10) {
    dVar7 = (double)DAT_25a0b0e4c88 / DAT_25a0b0dbf18;
  }
  dVar7 = (double)param_5 * dVar7;
  uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar5 - 0x3ff;
  dVar8 = dVar7;
  if ((ulonglong)uVar5 < 0x433) {
    if (uVar5 < 0x3ff) {
      dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
      }
    }
    else {
      bVar3 = (byte)lVar1;
      if (((longlong)dVar7 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar8 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar7 &
                        -0x10000000000000 >> (bVar3 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar8 = dVar7 + dVar7;
  }
  pMVar6 = &string_ref_25a0b0defd0;
  iVar4 = 1;
  if (1 < (int)dVar8) {
    iVar4 = (int)dVar8;
  }
  if (param_6 == '\0') {
    pMVar6 = &string_ref_25a0b0df4f0;
  }
  local_70 = param_3;
  cVar2 = (*(code *)&MT5_TextSetFont)(0x25a0930b4c8,pMVar6,iVar4 * -10,0,0);
  if (cVar2 != '\0') {
    FUN_25a0b0c05f0(&string_ref_25a0b0e4cd8,pMVar6,0,&PTR_DAT_25a0b0e0b70);
    _DAT_25a0b0e4ce8 = 0;
    DAT_25a0b0e4ce4 = iVar4 * -10;
  }
  FUN_25a0b0c05f0(&local_80,local_70,0,&PTR_DAT_25a0b0e1080);
  dVar8 = ((double)DAT_25a0b0e4c88 * (double)(param_2 + 6)) / DAT_25a0b0dbf18;
  uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar5 - 0x3ff;
  dVar7 = dVar8;
  if ((ulonglong)uVar5 < 0x433) {
    if (uVar5 < 0x3ff) {
      dVar7 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar7 = (double)((ulonglong)dVar8 & 0x8000000000000000);
      }
    }
    else {
      bVar3 = (byte)lVar1;
      if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar7 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                        -0x10000000000000 >> (bVar3 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar7 = dVar8 + dVar8;
  }
  dVar9 = ((double)DAT_25a0b0e4c84 * (double)(param_1 + 6)) / DAT_25a0b0dbf10;
  uVar5 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar5 - 0x3ff;
  dVar8 = dVar9;
  if ((ulonglong)uVar5 < 0x433) {
    if (uVar5 < 0x3ff) {
      dVar8 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar8 = (double)((ulonglong)dVar9 & 0x8000000000000000);
      }
    }
    else {
      bVar3 = (byte)lVar1;
      if (((longlong)dVar9 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar8 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar9 &
                        -0x10000000000000 >> (bVar3 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar8 = dVar9 + dVar9;
  }
  cVar2 = (*(code *)&MT5_TextSetFont)
                    (0x25a0930b4c8,&string_ref_25a0b0e4cd8,DAT_25a0b0e4ce4,
                     _DAT_25a0b0e4ce8 & 0xffffffff,DAT_25a0b0e4cec);
  if (cVar2 != '\0') {
    (*(code *)&MT5_TextOut)
              (0x25a0930b4c8,&local_80,(int)dVar8,(int)dVar7,param_7,&DAT_25a0b0e4cf0,
               DAT_25a0b0e4ccc,DAT_25a0b0e4cd0,
               (uint)((ulonglong)param_4 >> 0x10) & 0xff |
               (uint)param_4 & 0xff00 | (uint)param_4 << 0x10 | 0xff000000,DAT_25a0b0e4cd4);
  }
  FUN_25a0b0c0000(&local_80);
  return;
}



/* Address: 25a0b0d8720 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d8720(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  longlong lVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  int iVar10;
  ulonglong uVar11;
  code *pcVar12;
  byte bVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  ulonglong uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  
  dVar9 = DAT_25a0b0dbf28;
  dVar8 = DAT_25a0b0dbf20;
  dVar28 = (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf20;
  if ((double)DAT_25a0b0e4c88 / DAT_25a0b0dbf28 <= (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf20) {
    dVar28 = (double)DAT_25a0b0e4c88 / DAT_25a0b0dbf28;
  }
  dVar28 = (double)param_6 * dVar28;
  uVar17 = (uint)((ulonglong)dVar28 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar17 - 0x3ff;
  dVar30 = dVar28;
  if ((ulonglong)uVar17 < 0x433) {
    if (uVar17 < 0x3ff) {
      dVar30 = (double)((ulonglong)dVar28 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar30 = (double)((ulonglong)dVar28 & 0x8000000000000000);
      }
    }
    else {
      bVar13 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar13 & 0x3f) & (ulonglong)dVar28) != 0) {
        dVar30 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar28 &
                         -0x10000000000000 >> (bVar13 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar30 = dVar28 + dVar28;
  }
  iVar19 = 1;
  if (1 < (int)dVar30) {
    iVar19 = (int)dVar30;
  }
  iVar18 = 0;
  uVar17 = param_5 >> 0x10 & 0xff | param_5 & 0xff00 | param_5 << 0x10 | 0xff000000;
  do {
    dVar30 = ((double)(param_4 + 6) * (double)DAT_25a0b0e4c88) / dVar9;
    uVar15 = (uint)((ulonglong)dVar30 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar15 - 0x3ff;
    dVar28 = dVar30;
    if ((ulonglong)uVar15 < 0x433) {
      if (uVar15 < 0x3ff) {
        dVar28 = (double)((ulonglong)dVar30 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar28 = (double)((ulonglong)dVar30 & 0x8000000000000000);
        }
      }
      else {
        bVar13 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar13 & 0x3f) & (ulonglong)dVar30) != 0) {
          dVar28 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar30 &
                           -0x10000000000000 >> (bVar13 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar28 = dVar30 + dVar30;
    }
    dVar32 = ((double)(param_3 + 6) * (double)DAT_25a0b0e4c84) / dVar8;
    uVar15 = (uint)((ulonglong)dVar32 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar15 - 0x3ff;
    dVar30 = dVar32;
    if ((ulonglong)uVar15 < 0x433) {
      if (uVar15 < 0x3ff) {
        dVar30 = (double)((ulonglong)dVar32 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar30 = (double)((ulonglong)dVar32 & 0x8000000000000000);
        }
      }
      else {
        bVar13 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar13 & 0x3f) & (ulonglong)dVar32) != 0) {
          dVar30 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar32 &
                           -0x10000000000000 >> (bVar13 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar30 = dVar32 + dVar32;
    }
    dVar29 = ((double)DAT_25a0b0e4c88 * (double)(param_2 + 6)) / dVar9;
    uVar15 = (uint)((ulonglong)dVar29 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar15 - 0x3ff;
    dVar32 = dVar29;
    if ((ulonglong)uVar15 < 0x433) {
      if (uVar15 < 0x3ff) {
        dVar32 = (double)((ulonglong)dVar29 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar32 = (double)((ulonglong)dVar29 & 0x8000000000000000);
        }
      }
      else {
        bVar13 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar13 & 0x3f) & (ulonglong)dVar29) != 0) {
          dVar32 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar29 &
                           -0x10000000000000 >> (bVar13 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar32 = dVar29 + dVar29;
    }
    dVar31 = ((double)DAT_25a0b0e4c84 * (double)(param_1 + 6)) / dVar8;
    uVar15 = (uint)((ulonglong)dVar31 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar15 - 0x3ff;
    dVar29 = dVar31;
    if ((ulonglong)uVar15 < 0x433) {
      if (uVar15 < 0x3ff) {
        dVar29 = (double)((ulonglong)dVar31 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar29 = (double)((ulonglong)dVar31 & 0x8000000000000000);
        }
      }
      else {
        bVar13 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar13 & 0x3f) & (ulonglong)dVar31) != 0) {
          dVar29 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar31 &
                           -0x10000000000000 >> (bVar13 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar29 = dVar31 + dVar31;
    }
    iVar14 = (int)dVar29;
    iVar16 = (int)dVar30;
    if ((-1 < iVar14) || (-1 < iVar16)) {
      iVar2 = iVar18 + (int)dVar28;
      iVar10 = iVar18 + (int)dVar32;
      if ((((-1 < iVar10) || (-1 < iVar2)) &&
          ((iVar14 < DAT_25a0b0e4ccc || (iVar16 < DAT_25a0b0e4ccc)))) &&
         ((iVar10 < DAT_25a0b0e4cd0 || (iVar2 < DAT_25a0b0e4cd0)))) {
        iVar5 = iVar2 - iVar10;
        if (iVar2 - iVar10 == 0 || iVar2 < iVar10) {
          iVar5 = -(iVar2 - iVar10);
        }
        iVar26 = iVar16 - iVar14;
        if (iVar16 - iVar14 == 0 || iVar16 < iVar14) {
          iVar26 = -(iVar16 - iVar14);
        }
        if (iVar26 == 0) {
          pcVar12 = FUN_25a0b0d5df0;
        }
        else {
          if (iVar5 != 0) {
            bVar3 = iVar10 < iVar2;
            bVar4 = iVar14 < iVar16;
            iVar22 = DAT_25a0b0e4ccc;
            iVar23 = DAT_25a0b0e4cd0;
            if ((iVar16 != iVar14) || ((int)dVar32 != (int)dVar28)) {
              bVar7 = false;
              iVar24 = iVar26 - iVar5;
              do {
                if ((((iVar14 < 0) || (iVar22 <= iVar14)) || (iVar10 < 0)) || (iVar23 <= iVar10)) {
                  if (bVar7) goto LAB_25a0b0d88f0;
                  bVar7 = false;
                }
                else {
                  uVar20 = (ulonglong)(iVar22 * iVar10 + iVar14);
                  if (DAT_25a0b0e4cf8 <= uVar20) {
                    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1c02c7000801f6);
                    goto LAB_25a0b0d8e68;
                  }
                  bVar7 = true;
                  uVar11 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar20;
                  if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
                    uVar11 = uVar20;
                  }
                  *(uint *)(ram0x025a0b0e4d0c + uVar11 * 4) = uVar17;
                  iVar22 = DAT_25a0b0e4ccc;
                  iVar23 = DAT_25a0b0e4cd0;
                }
                iVar6 = iVar24 * 2;
                iVar27 = 0;
                if (-iVar5 < iVar6) {
                  iVar27 = (bVar4 - 1) + (uint)bVar4;
                }
                iVar21 = 0;
                if (-iVar5 < iVar6) {
                  iVar21 = iVar5;
                }
                iVar14 = iVar14 + iVar27;
                iVar27 = 0;
                if (iVar6 < iVar26) {
                  iVar27 = (uint)bVar3 * 2 + -1;
                }
                iVar25 = 0;
                if (iVar6 < iVar26) {
                  iVar25 = iVar26;
                }
                iVar24 = iVar25 + (iVar24 - iVar21);
                iVar10 = iVar10 + iVar27;
              } while ((iVar14 != iVar16) || (iVar10 != iVar2));
            }
            if (((-1 < iVar16) && ((iVar16 < iVar22 && (-1 < iVar2)))) && (iVar2 < iVar23)) {
              uVar20 = (ulonglong)(iVar22 * iVar2 + iVar16);
              if (DAT_25a0b0e4cf8 <= uVar20) {
LAB_25a0b0d8e68:
                (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1801ea000801f6);
                pcVar12 = (code *)swi(3);
                (*pcVar12)();
                return;
              }
              uVar11 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar20;
              if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
                uVar11 = uVar20;
              }
              *(uint *)(ram0x025a0b0e4d0c + uVar11 * 4) = uVar17;
            }
            goto LAB_25a0b0d88f0;
          }
          pcVar12 = FUN_25a0b0d5ef0;
          iVar2 = iVar10;
          iVar10 = iVar16;
        }
        (*pcVar12)(iVar14,iVar10,iVar2,uVar17);
      }
    }
LAB_25a0b0d88f0:
    iVar18 = iVar18 + 1;
    if (iVar18 == iVar19) {
      return;
    }
  } while( true );
}



/* Address: 25a0b0d8e90 */

void FUN_25a0b0d8e90(int param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
                    int param_7)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  
  dVar9 = ((double)(param_1 + 6) * (double)DAT_25a0b0e4c84) / DAT_25a0b0dbf30;
  uVar7 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar7 - 0x3ff;
  dVar10 = dVar9;
  if ((ulonglong)uVar7 < 0x433) {
    if (uVar7 < 0x3ff) {
      dVar10 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar10 = (double)((ulonglong)dVar9 & 0x8000000000000000);
      }
    }
    else {
      bVar2 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar2 & 0x3f) & (ulonglong)dVar9) != 0) {
        dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar9 &
                         -0x10000000000000 >> (bVar2 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar10 = dVar9 + dVar9;
  }
  dVar11 = ((double)(param_2 + 6) * (double)DAT_25a0b0e4c88) / DAT_25a0b0dbf38;
  uVar7 = (uint)((ulonglong)dVar11 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar7 - 0x3ff;
  dVar9 = dVar11;
  if ((ulonglong)uVar7 < 0x433) {
    if (uVar7 < 0x3ff) {
      dVar9 = (double)((ulonglong)dVar11 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar9 = (double)((ulonglong)dVar11 & 0x8000000000000000);
      }
    }
    else {
      bVar2 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar2 & 0x3f) & (ulonglong)dVar11) != 0) {
        dVar9 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar11 &
                        -0x10000000000000 >> (bVar2 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar9 = dVar11 + dVar11;
  }
  dVar12 = ((double)(param_3 + 6) * (double)DAT_25a0b0e4c84) / DAT_25a0b0dbf30;
  uVar7 = (uint)((ulonglong)dVar12 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar7 - 0x3ff;
  dVar11 = dVar12;
  if ((ulonglong)uVar7 < 0x433) {
    if (uVar7 < 0x3ff) {
      dVar11 = (double)((ulonglong)dVar12 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar11 = (double)((ulonglong)dVar12 & 0x8000000000000000);
      }
    }
    else {
      bVar2 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar2 & 0x3f) & (ulonglong)dVar12) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar12 &
                         -0x10000000000000 >> (bVar2 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar11 = dVar12 + dVar12;
  }
  iVar5 = (int)dVar10;
  iVar6 = (int)dVar9;
  iVar3 = (int)dVar11;
  dVar9 = ((double)(param_4 + 6) * (double)DAT_25a0b0e4c88) / DAT_25a0b0dbf38;
  uVar7 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar7 - 0x3ff;
  dVar10 = dVar9;
  if ((ulonglong)uVar7 < 0x433) {
    if (uVar7 < 0x3ff) {
      dVar10 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar10 = (double)((ulonglong)dVar9 & 0x8000000000000000);
      }
    }
    else {
      bVar2 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar2 & 0x3f) & (ulonglong)dVar9) != 0) {
        dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar9 &
                         -0x10000000000000 >> (bVar2 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar10 = dVar9 + dVar9;
  }
  iVar4 = (int)dVar10;
  FUN_25a0b0d6040(iVar5,iVar6,iVar3,iVar4,
                  param_5 >> 0x10 & 0xff | param_5 & 0xff00 | param_5 << 0x10 | 0xff000000);
  if (0 < param_7) {
    dVar10 = (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf30;
    if ((double)DAT_25a0b0e4c88 / DAT_25a0b0dbf38 <= (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf30) {
      dVar10 = (double)DAT_25a0b0e4c88 / DAT_25a0b0dbf38;
    }
    uVar7 = (uint)((ulonglong)dVar10 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar7 - 0x3ff;
    dVar9 = dVar10;
    if ((ulonglong)uVar7 < 0x433) {
      if (uVar7 < 0x3ff) {
        dVar9 = (double)((ulonglong)dVar10 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar9 = (double)((ulonglong)dVar10 & 0x8000000000000000);
        }
      }
      else {
        bVar2 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar2 & 0x3f) & (ulonglong)dVar10) != 0) {
          dVar9 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar10 &
                          -0x10000000000000 >> (bVar2 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar9 = dVar10 + dVar10;
    }
    uVar7 = param_6 >> 0x10 & 0xff | param_6 & 0xff00 | param_6 << 0x10 | 0xff000000;
    iVar8 = 1;
    if (1 < (int)dVar9) {
      iVar8 = (int)dVar9;
    }
    do {
      FUN_25a0b0d5ef0(iVar5,iVar3,iVar6,uVar7);
      FUN_25a0b0d5df0(iVar3,iVar6,iVar4,uVar7);
      FUN_25a0b0d5ef0(iVar3,iVar5,iVar4,uVar7);
      FUN_25a0b0d5df0(iVar5,iVar4,iVar6,uVar7);
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + -1;
      iVar4 = iVar4 + -1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}



/* Address: 25a0b0d92f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_25a0b0d92f0(int param_1,int param_2,int param_3,uint param_4)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  
  dVar20 = (double)DAT_25a0b0e4c84 / DAT_25a0b0dbf40;
  dVar18 = (double)DAT_25a0b0e4c88 / DAT_25a0b0dbf48;
  if (dVar18 <= dVar20) {
    dVar20 = dVar18;
  }
  dVar20 = (double)param_3 * dVar20;
  uVar8 = (uint)((ulonglong)dVar20 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar18 = dVar20;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar18 = (double)((ulonglong)dVar20 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar18 = (double)((ulonglong)dVar20 & 0x8000000000000000);
      }
    }
    else {
      bVar4 = (byte)lVar1;
      if (((longlong)dVar20 << (bVar4 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar4 & 0x3f)) + (longlong)dVar20 &
                         -0x10000000000000 >> (bVar4 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = dVar20 + dVar20;
  }
  iVar11 = 1;
  if (1 < (int)dVar18) {
    iVar11 = (int)dVar18;
  }
  dVar18 = ((double)(param_2 + 6) * (double)DAT_25a0b0e4c88) / DAT_25a0b0dbf48;
  uVar8 = (uint)((ulonglong)dVar18 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar20 = dVar18;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar20 = (double)((ulonglong)dVar18 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar20 = (double)((ulonglong)dVar18 & 0x8000000000000000);
      }
    }
    else {
      bVar4 = (byte)lVar1;
      if (((longlong)dVar18 << (bVar4 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar20 = (double)((0x8000000000000U >> (bVar4 & 0x3f)) + (longlong)dVar18 &
                         -0x10000000000000 >> (bVar4 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar20 = dVar18 + dVar18;
  }
  dVar19 = ((double)(param_1 + 6) * (double)DAT_25a0b0e4c84) / DAT_25a0b0dbf40;
  uVar8 = (uint)((ulonglong)dVar19 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar18 = dVar19;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar18 = (double)((ulonglong)dVar19 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar18 = (double)((ulonglong)dVar19 & 0x8000000000000000);
      }
    }
    else {
      bVar4 = (byte)lVar1;
      if (((longlong)dVar19 << (bVar4 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar4 & 0x3f)) + (longlong)dVar19 &
                         -0x10000000000000 >> (bVar4 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = dVar19 + dVar19;
  }
  uVar8 = param_4 * 0x10000 + (param_4 & 0xff00) + (param_4 >> 0x10 & 0xff) | 0xff000000;
  iVar10 = (int)dVar20;
  iVar17 = (int)dVar18;
  iVar14 = 0;
  iVar7 = iVar11 * -2;
  iVar12 = 1 - iVar11;
  iVar9 = iVar17;
  iVar15 = iVar10;
  iVar16 = 3;
  do {
    iVar5 = iVar17 + iVar14;
    if ((iVar5 < 0) || (DAT_25a0b0e4ccc <= iVar5)) goto LAB_25a0b0d9716;
    iVar3 = iVar11 + iVar10;
    if ((-1 < iVar3) && (iVar3 < DAT_25a0b0e4cd0)) {
      uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar3 + iVar5);
      if (uVar13 < DAT_25a0b0e4cf8) {
        uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        goto LAB_25a0b0d96ae;
      }
LAB_25a0b0d9a24:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0323000801f6);
LAB_25a0b0d9a44:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0326000801f6);
LAB_25a0b0d9a64:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f032d000801f6);
LAB_25a0b0d9a84:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0330000801f6);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
LAB_25a0b0d96ae:
    iVar3 = iVar10 - iVar11;
    if ((-1 < iVar3) && (iVar3 < DAT_25a0b0e4cd0)) {
      uVar13 = (ulonglong)(iVar5 + DAT_25a0b0e4ccc * iVar3);
      if (uVar13 < DAT_25a0b0e4cf8) {
        uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        goto LAB_25a0b0d9716;
      }
      goto LAB_25a0b0d9a44;
    }
LAB_25a0b0d9716:
    if ((-1 < iVar9) && (iVar9 < DAT_25a0b0e4ccc)) {
      iVar5 = iVar11 + iVar10;
      if ((iVar5 < 0) || (DAT_25a0b0e4cd0 <= iVar5)) {
LAB_25a0b0d9791:
        iVar5 = iVar10 - iVar11;
        if ((-1 < iVar5) && (iVar5 < DAT_25a0b0e4cd0)) {
          uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar5 + iVar9);
          if (DAT_25a0b0e4cf8 <= uVar13) goto LAB_25a0b0d9a84;
          uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
          if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
            uVar6 = uVar13;
          }
          *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        }
        goto LAB_25a0b0d97f8;
      }
      uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar5 + iVar9);
      if (uVar13 < DAT_25a0b0e4cf8) {
        uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        goto LAB_25a0b0d9791;
      }
      goto LAB_25a0b0d9a64;
    }
LAB_25a0b0d97f8:
    iVar5 = iVar11 + iVar17;
    if ((-1 < iVar5) && (iVar5 < DAT_25a0b0e4ccc)) {
      iVar3 = iVar10 + iVar14;
      if ((iVar3 < 0) || (DAT_25a0b0e4cd0 <= iVar3)) {
LAB_25a0b0d9879:
        if ((-1 < iVar15) && (iVar15 < DAT_25a0b0e4cd0)) {
          uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar15 + iVar5);
          if (DAT_25a0b0e4cf8 <= uVar13) goto LAB_25a0b0d99e4;
          uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
          if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
            uVar6 = uVar13;
          }
          *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        }
        goto LAB_25a0b0d98e0;
      }
      uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar3 + iVar5);
      if (uVar13 < DAT_25a0b0e4cf8) {
        uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
        goto LAB_25a0b0d9879;
      }
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0337000801f6);
LAB_25a0b0d99e4:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f033a000801f6);
LAB_25a0b0d9a04:
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0341000801f6);
      goto LAB_25a0b0d9a24;
    }
LAB_25a0b0d98e0:
    iVar5 = iVar17 - iVar11;
    if ((-1 < iVar5) && (iVar5 < DAT_25a0b0e4ccc)) {
      iVar3 = iVar10 + iVar14;
      if ((-1 < iVar3) && (iVar3 < DAT_25a0b0e4cd0)) {
        uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar3 + iVar5);
        if (DAT_25a0b0e4cf8 <= uVar13) goto LAB_25a0b0d9a04;
        uVar6 = (ulonglong)DAT_25a0b0e4cf8 + ~uVar13;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
      }
      if ((-1 < iVar15) && (iVar15 < DAT_25a0b0e4cd0)) {
        uVar13 = (ulonglong)(DAT_25a0b0e4ccc * iVar15 + iVar5);
        if (DAT_25a0b0e4cf8 <= uVar13) {
          (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f0344000801f6);
          return;
        }
        uVar6 = ~uVar13 + (ulonglong)DAT_25a0b0e4cf8;
        if ((DAT_25a0b0e4cf0._2_2_ & 0x10) == 0) {
          uVar6 = uVar13;
        }
        *(uint *)(ram0x025a0b0e4d0c + uVar6 * 4) = uVar8;
      }
    }
    iVar5 = iVar7 + 2;
    iVar3 = 0;
    if (-1 < iVar12) {
      iVar7 = iVar5;
      iVar3 = iVar5;
    }
    iVar14 = iVar14 + 1;
    iVar15 = iVar15 + -1;
    iVar9 = iVar9 + -1;
    iVar11 = iVar11 - (uint)(-1 < iVar12);
    iVar12 = iVar16 + iVar12 + iVar3;
    iVar16 = iVar16 + 2;
    if (iVar11 < iVar14) {
      return;
    }
  } while( true );
}



/* Address: 25a0b0d9ab0 */

void FUN_25a0b0d9ab0(int param_1,ulonglong param_2,int param_3,int param_4,undefined4 param_5,
                    undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = (int)param_2;
  iVar4 = param_4 + iVar1;
  iVar3 = param_1 + 9;
  iVar7 = param_3 + param_1;
  FUN_25a0b0d8e90(iVar3,param_2,param_3 + -9 + param_1,iVar4,param_5,param_5,0);
  iVar2 = iVar1 + 9;
  FUN_25a0b0d8e90(param_1,iVar2,iVar7,param_4 + -9 + iVar1,param_5,param_5,0);
  iVar6 = param_3 + -10 + param_1;
  FUN_25a0b0d8720(iVar3,param_2 & 0xffffffff,iVar6,param_2 & 0xffffffff,param_6,1);
  FUN_25a0b0d8720(iVar6,param_2 & 0xffffffff,iVar7,iVar1 + 10,param_6,1);
  iVar5 = param_4 + -10 + iVar1;
  FUN_25a0b0d8720(iVar7,iVar1 + 10,iVar7,iVar5,param_6,1);
  FUN_25a0b0d8720(iVar7,iVar5,iVar6,iVar4,param_6,1);
  FUN_25a0b0d8720(iVar6,iVar4,iVar3,iVar4,param_6,1);
  FUN_25a0b0d8720(iVar3,iVar4,param_1,iVar5,param_6,1);
  FUN_25a0b0d8720(param_1,iVar5,param_1,iVar2,param_6,1);
  FUN_25a0b0d8720(param_1,iVar2,iVar3,param_2 & 0xffffffff,param_6,1);
  return;
}



/* Address: 25a0b0d9c80 */

void FUN_25a0b0d9c80(double param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  uint uVar6;
  MqlStringAnalysisView *pMVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_48;
  undefined8 local_44;
  
  pMVar7 = &string_ref_25a0b0dc170;
  local_78 = 0;
  local_88 = 0;
  local_98 = 0;
  local_68 = 0;
  local_48 = 0;
  local_74 = 0;
  local_84 = 0;
  local_94 = 0;
  local_64 = 0;
  local_44 = 0;
  local_58 = 0;
  local_50 = 0;
  if (0.0 < param_1) {
    pMVar7 = &string_ref_25a0b0df338;
  }
  FUN_25a0b0c05f0(&local_58,pMVar7,0,&PTR_DAT_25a0b0e1090);
  MT5_DoubleToString((void *)0x25a0930b4c8,param_1,2);
  FUN_25a0b0c05f0(&local_68,&runtime_string_result,1,&PTR_DAT_25a0b0e10a0);
  FUN_25a0b0c05f0(&local_98,&local_58);
  lVar2 = local_64;
  if (local_64 != 0) {
    uVar13 = *(uint *)(local_64 + -4);
    uVar10 = (ulonglong)uVar13;
    if ((uVar10 == 0) && (local_94 != 0)) goto LAB_25a0b0d9e9d;
    if (local_94 == 0) {
      uVar8 = 0;
      uVar9 = uVar13;
    }
    else {
      uVar8 = (ulonglong)*(uint *)(local_94 + -4);
      uVar9 = uVar13 + *(uint *)(local_94 + -4);
    }
    cVar5 = FUN_25a0b0c0060(&local_98);
    if (cVar5 != '\0') {
      if (uVar10 != 0) {
        lVar1 = local_94 + uVar8 * 2;
        if (uVar13 < 0x10) {
          uVar8 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar8 = 0;
        }
        else {
          uVar12 = 0;
          uVar8 = (ulonglong)(uVar13 & 0xfffffff8);
          do {
            uVar4 = ((undefined8 *)(lVar2 + uVar12))[1];
            *(undefined8 *)(lVar1 + uVar12) = *(undefined8 *)(lVar2 + uVar12);
            ((undefined8 *)(lVar1 + uVar12))[1] = uVar4;
            uVar12 = uVar12 + 0x10;
          } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar12);
          if (uVar8 == uVar10) goto LAB_25a0b0d9e92;
        }
        do {
          *(undefined2 *)(lVar1 + uVar8 * 2) = *(undefined2 *)(lVar2 + uVar8 * 2);
          uVar8 = uVar8 + 1;
        } while (uVar10 != uVar8);
      }
LAB_25a0b0d9e92:
      *(uint *)(local_94 + -4) = uVar9;
      *(undefined2 *)(local_94 + (ulonglong)uVar9 * 2) = 0;
      goto LAB_25a0b0d9e9d;
    }
LAB_25a0b0da1a4:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0xb097d000001f9);
LAB_25a0b0da1c4:
    (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x23097d000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
LAB_25a0b0d9e9d:
  uVar13 = 0;
  FUN_25a0b0c05f0(&local_88,&local_98,0,&PTR_DAT_25a0b0e10c0);
  uVar9 = DAT_25a0b0de874;
  uVar10 = (ulonglong)DAT_25a0b0de874;
  if ((uVar10 != 0) || (local_84 == 0)) {
    if (local_84 != 0) {
      uVar13 = *(uint *)(local_84 + -4);
    }
    uVar11 = DAT_25a0b0de874 + uVar13;
    uVar6 = 0x104;
    if ((0x103 < uVar11) &&
       ((0x7ffffffd < uVar11 || (uVar6 = (uVar11 >> 2) + uVar11, 0x7ffffffd < uVar6)))) {
      uVar6 = 0x7ffffffe;
    }
    cVar5 = FUN_25a0b0c0060(&local_88,uVar6);
    if (cVar5 == '\0') {
      (*(code *)&runtime_memory_helper_3959a0)(0x25a0930b4c8,0x1f097d000001f9);
      goto LAB_25a0b0da1a4;
    }
    if (uVar10 != 0) {
      lVar2 = local_84 + (ulonglong)uVar13 * 2;
      if (uVar9 < 0x10) {
        uVar8 = 0;
      }
      else if (lVar2 - 0x25a0b0de878U < 0x20) {
        uVar8 = 0;
      }
      else {
        uVar12 = 0;
        uVar8 = (ulonglong)(uVar9 & 0xfffffff8);
        do {
          uVar4 = *(undefined8 *)(uVar12 + 0x25a0b0de880);
          *(undefined8 *)(lVar2 + uVar12) = *(undefined8 *)((longlong)&DAT_25a0b0de878 + uVar12);
          ((undefined8 *)(lVar2 + uVar12))[1] = uVar4;
          uVar12 = uVar12 + 0x10;
        } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar12);
        if (uVar8 == uVar10) goto LAB_25a0b0d9fc2;
      }
      do {
        *(undefined2 *)(lVar2 + uVar8 * 2) = (&DAT_25a0b0de878)[uVar8];
        uVar8 = uVar8 + 1;
      } while (uVar10 != uVar8);
    }
LAB_25a0b0d9fc2:
    *(uint *)(local_84 + -4) = uVar11;
    *(undefined2 *)(local_84 + (ulonglong)uVar11 * 2) = 0;
  }
  FUN_25a0b0c05f0(&local_78,&local_88,0);
  lVar2 = DAT_25a0b0e2584;
  if (DAT_25a0b0e2584 == 0) goto LAB_25a0b0da0fd;
  uVar13 = *(uint *)(DAT_25a0b0e2584 + -4);
  uVar10 = (ulonglong)uVar13;
  if ((uVar10 == 0) && (local_74 != 0)) goto LAB_25a0b0da0fd;
  if (local_74 == 0) {
    uVar8 = 0;
    uVar9 = uVar13;
  }
  else {
    uVar8 = (ulonglong)*(uint *)(local_74 + -4);
    uVar9 = uVar13 + *(uint *)(local_74 + -4);
  }
  cVar5 = FUN_25a0b0c0060(&local_78);
  if (cVar5 == '\0') goto LAB_25a0b0da1c4;
  if (uVar10 != 0) {
    lVar1 = local_74 + uVar8 * 2;
    if (uVar13 < 0x10) {
      uVar8 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
      uVar8 = 0;
    }
    else {
      uVar12 = 0;
      uVar8 = (ulonglong)(uVar13 & 0xfffffff8);
      do {
        uVar4 = ((undefined8 *)(lVar2 + uVar12))[1];
        *(undefined8 *)(lVar1 + uVar12) = *(undefined8 *)(lVar2 + uVar12);
        ((undefined8 *)(lVar1 + uVar12))[1] = uVar4;
        uVar12 = uVar12 + 0x10;
      } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar12);
      if (uVar8 == uVar10) goto LAB_25a0b0da0f2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar8 * 2) = *(undefined2 *)(lVar2 + uVar8 * 2);
      uVar8 = uVar8 + 1;
    } while (uVar10 != uVar8);
  }
LAB_25a0b0da0f2:
  *(uint *)(local_74 + -4) = uVar9;
  *(undefined2 *)(local_74 + (ulonglong)uVar9 * 2) = 0;
LAB_25a0b0da0fd:
  FUN_25a0b0c05f0(&local_48,&local_78,0,&PTR_DAT_25a0b0e10e0);
  FUN_25a0b0c0000(&local_58);
  FUN_25a0b0c05f0(&runtime_string_result,&local_48,1,&PTR_DAT_25a0b0e10f0);
  FUN_25a0b0c0000(&local_48);
  FUN_25a0b0c0000(&local_68);
  FUN_25a0b0c0000(&local_98);
  FUN_25a0b0c0000(&local_88);
  FUN_25a0b0c0000(&local_78);
  return;
}



/* Address: 25a0b0da1f0 */

void thunk_FUN_25a0b0c0a90(void)

{
  FUN_25a0b0c0a90();
  return;
}


