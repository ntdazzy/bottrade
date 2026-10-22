/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 2b6e6c90000 */

void FUN_2b6e6c90000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2b6e1db7188);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 2b6e6c90060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b6e6c90060(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2b6e1db7188);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_2b6e6c901cd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_2b6e6c901cd;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2b6e1db7188);
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
        if (uVar15 < 8) goto LAB_2b6e6c90130;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_2b6e6c90130;
        uVar16 = (ulonglong)(uVar15 & 0x7ffffff8);
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
LAB_2b6e6c90130:
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
          (*(code *)0x7ff63a101200)(0x2b6e1db7188,puVar14);
        }
      }
      goto LAB_2b6e6c901cd;
    }
  }
  _DAT_2b6e6d43d10 = 0x13aa;
  uVar12 = 0;
LAB_2b6e6c901cd:
  return uVar12 & 0xffffffff;
}



/* Address: 2b6e6c901e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c901e0(int *param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  uVar9 = (ulonglong)param_3;
  if (param_2 == 0) {
    if ((((*param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 1), lVar1 != 0)) &&
        ((int *)(lVar1 + -0xc) != (int *)0x0)) && (*(int *)(lVar1 + -0xc) != 0)) {
      piVar4 = (int *)(lVar1 + -8);
      *piVar4 = *piVar4 + -1;
      if (*piVar4 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    if (param_3 - 1 < 0xfffffffe) {
      _DAT_2b6e6d43d10 = 0xfa2;
      return;
    }
    return;
  }
  if (param_3 == 0xffffffff) {
    uVar9 = 0xffffffff;
    do {
      uVar9 = (ulonglong)((int)uVar9 + 1);
    } while (*(short *)(param_2 + uVar9 * 2) != 0);
  }
  uVar8 = (uint)uVar9;
  uVar7 = 0x3fffffe8;
  if (uVar8 < 0x3fffffe8) {
    uVar7 = uVar9;
  }
  piVar4 = *(int **)(param_1 + 1);
  puVar5 = (uint *)(piVar4 + -3);
  if (piVar4 == (int *)0x0) {
    puVar5 = (uint *)0x0;
  }
  uVar6 = (uint)uVar7;
  if ((*param_1 != 0) && (puVar5 != (uint *)0x0)) {
    if ((uVar6 <= *puVar5) && (puVar5[1] == 1)) goto LAB_2b6e6c902b7;
    if (*puVar5 != 0) {
      puVar5 = puVar5 + 1;
      *puVar5 = *puVar5 - 1;
      if (*puVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  piVar3 = (int *)(*(code *)0x7ff63a101190)(0x2b6e1db7188);
  if (piVar3 == (int *)0x0) {
    _DAT_2b6e6d43d10 = 0x13aa;
    return;
  }
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar4 = piVar3 + 3;
  *(undefined2 *)(piVar3 + 3) = 0;
  *(int **)(param_1 + 1) = piVar4;
  *param_1 = *piVar3;
LAB_2b6e6c902b7:
  if (uVar8 == 0) {
    piVar4[-1] = uVar6;
    *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
    return;
  }
  uVar9 = 0;
  if (uVar8 < 8) goto LAB_2b6e6c90310;
  if ((ulonglong)((longlong)piVar4 - param_2) < 0x20) goto LAB_2b6e6c90310;
  uVar9 = (ulonglong)(uVar6 & 0x3ffffff8);
  uVar10 = 0;
  do {
    uVar2 = ((undefined8 *)(param_2 + uVar10))[1];
    *(undefined8 *)((longlong)piVar4 + uVar10) = *(undefined8 *)(param_2 + uVar10);
    ((undefined8 *)((longlong)piVar4 + uVar10))[1] = uVar2;
    uVar10 = uVar10 + 0x10;
  } while ((uVar7 * 2 & 0xfffffffffffffff0) != uVar10);
  for (; uVar9 != uVar7; uVar9 = uVar9 + 1) {
LAB_2b6e6c90310:
    *(undefined2 *)((longlong)piVar4 + uVar9 * 2) = *(undefined2 *)(param_2 + uVar9 * 2);
  }
  piVar4[-1] = uVar6;
  *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
  if (0x3fffffe8 < uVar8) {
    _DAT_2b6e6d43d10 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2b6e6c903c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c903c0(short *param_1,short param_2,short *param_3)

{
  undefined4 *puVar1;
  short *psVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  uint *puVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong uVar18;
  uint uVar19;
  uint local_48;
  int iVar17;
  
  uVar4 = 0x13c7;
  if (*param_3 == 0x59) {
    lVar10 = 0;
    do {
      if (*(int *)(param_3 + lVar10 * 2 + 6) == 0) {
        if (lVar10 != 0) {
          _DAT_2b6e6d43d10 = 0xfa6;
          return;
        }
        uVar19 = 0;
        if ((param_1 == (short *)0x0) || (uVar19 = 0, *param_1 == 0)) goto LAB_2b6e6c90637;
        lVar10 = *(longlong *)(param_3 + 0xe);
        local_48 = *(uint *)(param_3 + 4);
        uVar3 = *(uint *)(param_1 + -2);
        uVar19 = 0;
        goto LAB_2b6e6c90460;
      }
      lVar10 = lVar10 + 1;
    } while (lVar10 != 3);
    uVar4 = 0xfa6;
  }
  _DAT_2b6e6d43d10 = uVar4;
  return;
LAB_2b6e6c90460:
  uVar18 = 0xffffffff;
  uVar8 = 0;
  do {
    uVar7 = uVar8;
    iVar17 = (int)uVar18;
    uVar16 = iVar17 + 1;
    uVar18 = (ulonglong)uVar16;
    if (param_1[uVar18] == 0) break;
    uVar8 = uVar7 + 1;
  } while (param_1[uVar18] != param_2);
  if (0x3fffffe8 < uVar16) {
    if ((*(byte *)(param_3 + 1) & 1) != 0) {
      (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,param_3);
    }
    _DAT_2b6e6d43d10 = 0x13b0;
    return;
  }
  if (local_48 <= uVar19) {
    if ((*(byte *)(param_3 + 1) & 1) == 0) {
      _DAT_2b6e6d43d10 = 0xfa7;
      return;
    }
    uVar8 = uVar3;
    if (uVar16 != 0) {
      uVar8 = uVar3 / uVar16;
    }
    local_48 = uVar19 + uVar8 + 1;
    iVar9 = (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,param_3,local_48,0x20 - (local_48 & 0x1f));
    if (iVar9 < 0) {
      return;
    }
    lVar10 = *(longlong *)(param_3 + 0xe);
  }
  uVar12 = (ulonglong)uVar19;
  puVar1 = (undefined4 *)(lVar10 + uVar12 * 0xc);
  puVar13 = *(undefined4 **)(lVar10 + 4 + uVar12 * 0xc);
  puVar14 = puVar13 + -3;
  if (puVar13 == (undefined4 *)0x0) {
    puVar14 = (uint *)0x0;
  }
  if ((*(int *)(lVar10 + uVar12 * 0xc) == 0) || (puVar14 == (uint *)0x0)) {
LAB_2b6e6c9055b:
    puVar11 = (undefined4 *)(*(code *)0x7ff63a101190)(0x2b6e1db7188);
    if (puVar11 != (undefined4 *)0x0) {
      *(undefined8 *)(puVar11 + 1) = 1;
      puVar13 = puVar11 + 3;
      *(undefined2 *)(puVar11 + 3) = 0;
      *(undefined4 **)(puVar1 + 1) = puVar13;
      *puVar1 = *puVar11;
      goto LAB_2b6e6c90596;
    }
    _DAT_2b6e6d43d10 = 0x13aa;
  }
  else {
    if ((*puVar14 < uVar16) || (puVar14[1] != 1)) {
      if (*puVar14 != 0) {
        puVar14 = puVar14 + 1;
        *puVar14 = *puVar14 - 1;
        if (*puVar14 == 0) {
          (*(code *)0x7ff63a101200)(0x2b6e1db7188);
        }
      }
      *(undefined8 *)(puVar1 + 1) = 0;
      *puVar1 = 0;
      goto LAB_2b6e6c9055b;
    }
LAB_2b6e6c90596:
    if (uVar16 != 0) {
      if (uVar16 < 8) {
        uVar12 = 0;
      }
      else {
        uVar12 = 0;
        if (0x1f < (ulonglong)((longlong)puVar13 - (longlong)param_1)) {
          uVar12 = (ulonglong)(uVar16 & 0x3ffffff8);
          uVar15 = 0;
          do {
            psVar2 = param_1 + uVar15;
            uVar4 = *(undefined4 *)(psVar2 + 2);
            uVar5 = *(undefined4 *)(psVar2 + 4);
            uVar6 = *(undefined4 *)(psVar2 + 6);
            puVar1 = (undefined4 *)((longlong)puVar13 + uVar15 * 2);
            *puVar1 = *(undefined4 *)psVar2;
            puVar1[1] = uVar4;
            puVar1[2] = uVar5;
            puVar1[3] = uVar6;
            uVar15 = uVar15 + 8;
          } while ((uVar7 & 0x3ffffff8) != uVar15);
          if (uVar12 == uVar18) goto LAB_2b6e6c90612;
        }
      }
      do {
        *(short *)((longlong)puVar13 + uVar12 * 2) = param_1[uVar12];
        uVar12 = uVar12 + 1;
      } while (uVar7 != uVar12);
    }
LAB_2b6e6c90612:
    puVar13[-1] = uVar16;
    *(undefined2 *)((longlong)puVar13 + uVar18 * 2) = 0;
  }
  uVar19 = uVar19 + 1;
  if (param_1[uVar18] == 0) {
LAB_2b6e6c90637:
    if ((*(byte *)(param_3 + 1) & 1) == 0) {
      return;
    }
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,param_3,uVar19,0);
    return;
  }
  param_1 = param_1 + (iVar17 + 2);
  goto LAB_2b6e6c90460;
}



/* Address: 2b6e6c906c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b6e6c906c0(short *param_1,short *param_2,uint param_3)

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
    _DAT_2b6e6d43d10 = 0xfa9;
    uVar7 = 0xffffffff;
  }
  else {
    uVar10 = *(uint *)(param_1 + -2);
    if ((uVar10 == 0) || (uVar4 = *(uint *)(param_2 + -2), uVar4 == 0)) {
      _DAT_2b6e6d43d10 = 0x13ab;
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
              if (uVar11 - 1 == uVar8) goto LAB_2b6e6c906fa;
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
                  if (uVar4 == uVar8) goto LAB_2b6e6c907d6;
                }
                if (uVar4 == (uint)uVar8) {
LAB_2b6e6c907d6:
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
LAB_2b6e6c906fa:
        uVar7 = 0xffffffff;
      }
    }
  }
  return uVar7;
}



/* Address: 2b6e6c907f0 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_2b6e6c907f0(uint *param_1,short *param_2,longlong param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  longlong lVar13;
  undefined1 *puVar14;
  int iVar15;
  undefined1 *puVar16;
  int iVar17;
  ulonglong uVar18;
  uint uVar19;
  ulonglong uVar20;
  uint uVar21;
  uint uVar22;
  undefined1 *puVar23;
  ulonglong uVar24;
  longlong lVar25;
  uint local_78;
  uint local_74;
  uint *local_70;
  int local_64;
  
  lVar25 = 0x2b6e6ca8d20;
  if (param_3 != 0) {
    lVar25 = param_3;
  }
  lVar5 = *(longlong *)(param_1 + 1);
  uVar18 = 0;
  uVar21 = 0;
  if (lVar5 != 0) {
    uVar21 = *(uint *)(lVar5 + -4);
  }
  if (param_2 != (short *)0x0) {
    uVar18 = (ulonglong)*(uint *)(param_2 + -2);
  }
  if (param_3 == 0) {
    local_74 = 0;
  }
  else {
    local_74 = *(uint *)(param_3 + -4);
  }
  if (((lVar5 == 0) || (param_2 == (short *)0x0)) || (iVar17 = (int)uVar18, iVar17 == 0)) {
    puVar11 = &DAT_2b6e6d43d10;
    _DAT_2b6e6d43d10 = 0x13b0;
  }
  else {
    puVar11 = (undefined1 *)((longlong)(int)uVar21 / (longlong)iVar17 & 0xffffffff);
    if (0 < (int)uVar21) {
      puVar14 = (undefined1 *)(longlong)(int)local_74;
      puVar9 = (undefined1 *)((ulonglong)puVar14 & 0xfffffffffffffff8);
      local_70 = (uint *)0x0;
      iVar15 = 0;
      local_64 = 0;
      uVar19 = 0;
      local_78 = 0;
LAB_2b6e6c908eb:
      do {
        lVar13 = (longlong)iVar15;
        uVar22 = iVar15 + 1U;
        if ((int)(iVar15 + 1U) < (int)uVar21) {
          uVar22 = uVar21;
        }
        do {
          if (*(short *)(lVar5 + lVar13 * 2) == *param_2) {
            uVar22 = (uint)lVar13;
            break;
          }
          lVar13 = lVar13 + 1;
        } while (lVar13 < (longlong)(ulonglong)uVar21);
        puVar11 = (undefined1 *)(ulonglong)(uVar21 - uVar22);
        if ((int)(uVar21 - uVar22) < iVar17) break;
        uVar20 = 1;
        if (1 < iVar17) {
          uVar20 = 1;
          do {
            uVar4 = *(ushort *)(lVar5 + (longlong)(int)uVar22 * 2 + uVar20 * 2);
            puVar11 = (undefined1 *)(ulonglong)uVar4;
            if (uVar4 != param_2[uVar20]) goto LAB_2b6e6c90970;
            uVar20 = uVar20 + 1;
          } while (uVar18 != uVar20);
LAB_2b6e6c90979:
          if (local_70 == (uint *)0x0) {
            puVar10 = (uint *)(*(code *)0x7ff63a101190)
                                        (0x2b6e1db7188,
                                         (int)((longlong)(int)uVar21 / (longlong)iVar17) * local_74
                                         + uVar21);
            if (puVar10 == (uint *)0x0) {
              _DAT_2b6e6d43d10 = 0x13aa;
              return &DAT_2b6e6d43d10;
            }
            puVar10[1] = 1;
            puVar10[2] = 0;
            local_70 = puVar10 + 3;
            *(undefined2 *)(puVar10 + 3) = 0;
            local_78 = *puVar10;
            puVar11 = (undefined1 *)(ulonglong)local_78;
            uVar12 = uVar22 - local_64;
            if (uVar12 != 0 && local_64 <= (int)uVar22) goto LAB_2b6e6c90a03;
          }
          else {
            uVar12 = uVar22 - local_64;
            if (uVar12 != 0 && local_64 <= (int)uVar22) {
LAB_2b6e6c90a03:
              lVar13 = lVar5 + (longlong)local_64 * 2;
              puVar16 = (undefined1 *)(longlong)(int)(uVar12 + (uVar12 == 0));
              if (uVar12 < 8) {
                puVar23 = (undefined1 *)0x0;
              }
              else {
                if (0x1f < (ulonglong)((longlong)local_70 + ((longlong)(int)uVar19 * 2 - lVar13))) {
                  puVar23 = (undefined1 *)((ulonglong)puVar16 & 0xfffffffffffffff8);
                  puVar11 = (undefined1 *)0x0;
                  do {
                    puVar2 = (undefined4 *)(lVar13 + (longlong)puVar11 * 2);
                    uVar6 = puVar2[1];
                    uVar7 = puVar2[2];
                    uVar8 = puVar2[3];
                    puVar3 = (undefined4 *)
                             ((longlong)local_70 + (longlong)puVar11 * 2 + (longlong)(int)uVar19 * 2
                             );
                    *puVar3 = *puVar2;
                    puVar3[1] = uVar6;
                    puVar3[2] = uVar7;
                    puVar3[3] = uVar8;
                    puVar11 = puVar11 + 8;
                    if (puVar23 == puVar11) goto joined_r0x02b6e6c90a66;
                  } while( true );
                }
                puVar23 = (undefined1 *)0x0;
              }
              do {
                uVar4 = *(ushort *)(lVar13 + (longlong)puVar23 * 2);
                puVar11 = (undefined1 *)(ulonglong)uVar4;
                *(ushort *)((longlong)local_70 + (longlong)puVar23 * 2 + (longlong)(int)uVar19 * 2)
                     = uVar4;
                puVar23 = puVar23 + 1;
joined_r0x02b6e6c90a66:
              } while (puVar23 != puVar16);
              uVar19 = uVar19 + uVar12;
            }
          }
          if (local_74 != 0) {
            lVar13 = (longlong)(int)uVar19;
            if (local_74 < 8) {
              puVar16 = (undefined1 *)0x0;
            }
            else if ((ulonglong)((longlong)local_70 + (lVar13 * 2 - lVar25)) < 0x20) {
              puVar16 = (undefined1 *)0x0;
            }
            else {
              puVar11 = (undefined1 *)0x0;
              do {
                puVar3 = (undefined4 *)(lVar25 + (longlong)puVar11 * 2);
                uVar6 = puVar3[1];
                uVar7 = puVar3[2];
                uVar8 = puVar3[3];
                puVar2 = (undefined4 *)((longlong)local_70 + (longlong)puVar11 * 2 + lVar13 * 2);
                *puVar2 = *puVar3;
                puVar2[1] = uVar6;
                puVar2[2] = uVar7;
                puVar2[3] = uVar8;
                puVar11 = puVar11 + 8;
              } while (puVar9 != puVar11);
              puVar11 = puVar9;
              puVar16 = puVar9;
              if (puVar9 == puVar14) goto LAB_2b6e6c90b03;
            }
            do {
              uVar4 = *(ushort *)(lVar25 + (longlong)puVar16 * 2);
              *(ushort *)((longlong)local_70 + (longlong)puVar16 * 2 + lVar13 * 2) = uVar4;
              puVar16 = puVar16 + 1;
              puVar11 = (undefined1 *)(ulonglong)uVar4;
            } while (puVar14 != puVar16);
          }
LAB_2b6e6c90b03:
          uVar19 = uVar19 + local_74;
          iVar15 = uVar22 + iVar17;
          local_64 = iVar15;
          if ((int)uVar21 <= iVar15) break;
          goto LAB_2b6e6c908eb;
        }
LAB_2b6e6c90970:
        if ((int)uVar20 == iVar17) goto LAB_2b6e6c90979;
        iVar15 = uVar22 + 1;
      } while (iVar15 < (int)uVar21);
      if (local_70 != (uint *)0x0) {
        uVar22 = uVar21 - local_64;
        if (uVar22 != 0 && local_64 <= (int)uVar21) {
          lVar5 = lVar5 + (longlong)local_64 * 2;
          uVar18 = (ulonglong)(int)(uVar22 + (uVar22 == 0));
          if (uVar22 < 0x10) {
            uVar20 = 0;
          }
          else {
            if (0x1f < (ulonglong)((longlong)local_70 + ((longlong)(int)uVar19 * 2 - lVar5))) {
              uVar20 = uVar18 & 0xfffffffffffffff8;
              uVar24 = 0;
              do {
                puVar2 = (undefined4 *)(lVar5 + uVar24 * 2);
                uVar6 = puVar2[1];
                uVar7 = puVar2[2];
                uVar8 = puVar2[3];
                puVar3 = (undefined4 *)((longlong)local_70 + uVar24 * 2 + (longlong)(int)uVar19 * 2)
                ;
                *puVar3 = *puVar2;
                puVar3[1] = uVar6;
                puVar3[2] = uVar7;
                puVar3[3] = uVar8;
                uVar24 = uVar24 + 8;
                if (uVar20 == uVar24) goto joined_r0x02b6e6c90bd9;
              } while( true );
            }
            uVar20 = 0;
          }
          do {
            *(undefined2 *)((longlong)local_70 + uVar20 * 2 + (longlong)(int)uVar19 * 2) =
                 *(undefined2 *)(lVar5 + uVar20 * 2);
            uVar20 = uVar20 + 1;
joined_r0x02b6e6c90bd9:
          } while (uVar20 != uVar18);
          uVar19 = uVar19 + uVar22;
        }
        local_70[-1] = uVar19;
        puVar11 = (undefined1 *)(ulonglong)uVar19;
        *(undefined2 *)((longlong)local_70 + (longlong)puVar11 * 2) = 0;
        lVar25 = *(longlong *)(param_1 + 1);
        uVar21 = *param_1;
        *param_1 = local_78;
        *(uint **)(param_1 + 1) = local_70;
        if (((uVar21 != 0) && (lVar25 != 0)) &&
           (((int *)(lVar25 + -0xc) != (int *)0x0 && (*(int *)(lVar25 + -0xc) != 0)))) {
          piVar1 = (int *)(lVar25 + -8);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            puVar11 = (undefined1 *)(*(code *)0x7ff63a101200)(0x2b6e1db7188);
            return puVar11;
          }
        }
      }
    }
  }
  return puVar11;
}



/* Address: 2b6e6c90c70 */

ulonglong FUN_2b6e6c90c70(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_2b6e6c90d7d;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_2b6e6c90d7d;
  if (lVar3 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = *(uint *)(lVar3 + -4);
  }
  uVar7 = uVar2 + uVar12;
  uVar6 = 0x104;
  if ((0x103 < uVar7) &&
     ((0x3fffffe7 < uVar7 || (uVar6 = (uVar7 >> 2) + uVar7, 0x3fffffe7 < uVar6)))) {
    uVar6 = 0x3fffffe8;
  }
  cVar5 = FUN_2b6e6c90060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_2b6e6c90d7d;
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
      if (uVar10 == uVar9) goto LAB_2b6e6c90d72;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_2b6e6c90d72:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_2b6e6c90d7d:
  return uVar8 & 0xffffffff;
}



/* Address: 2b6e6c90d90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c90d90(int *param_1,int *param_2,char param_3,undefined8 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int *piVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  
  if (param_1 == param_2) {
    return;
  }
  lVar7 = *(longlong *)(param_2 + 1);
  if (lVar7 == 0) {
    if ((((*param_1 != 0) && (lVar7 = *(longlong *)(param_1 + 1), lVar7 != 0)) &&
        ((int *)(lVar7 + -0xc) != (int *)0x0)) && (*(int *)(lVar7 + -0xc) != 0)) {
      piVar13 = (int *)(lVar7 + -8);
      *piVar13 = *piVar13 + -1;
      if (*piVar13 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    return;
  }
  if (param_3 == '\0') {
    if (((*param_1 != 0) && (lVar7 = *(longlong *)(param_1 + 1), lVar7 != 0)) &&
       ((piVar13 = (int *)(lVar7 + -0xc), piVar13 != (int *)0x0 && (*piVar13 != 0)))) {
      piVar1 = (int *)(lVar7 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188,piVar13);
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
    piVar13 = (int *)(*(longlong *)(param_1 + 1) + -8);
    *piVar13 = *piVar13 + 1;
    return;
  }
  uVar4 = *(uint *)(lVar7 + -4);
  uVar15 = (ulonglong)uVar4;
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x2b6e1db7188,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_2b6e6d43d10 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x2b6e1db7188,0x1f9,param_4);
    pcVar9 = (code *)swi(3);
    (*pcVar9)();
    return;
  }
  piVar13[1] = 1;
  piVar13[2] = 0;
  piVar1 = piVar13 + 3;
  *(undefined2 *)(piVar13 + 3) = 0;
  iVar5 = *piVar13;
  if (uVar4 != 0) {
    if (uVar4 < 8) {
      uVar14 = 0;
    }
    else if ((ulonglong)((longlong)piVar13 + (0xc - lVar7)) < 0x20) {
      uVar14 = 0;
    }
    else {
      uVar14 = (ulonglong)(uVar4 & 0xfffffff8);
      uVar16 = 0;
      do {
        puVar2 = (undefined4 *)(lVar7 + uVar16);
        uVar10 = puVar2[1];
        uVar11 = puVar2[2];
        uVar12 = puVar2[3];
        puVar3 = (undefined4 *)((longlong)piVar1 + uVar16);
        *puVar3 = *puVar2;
        puVar3[1] = uVar10;
        puVar3[2] = uVar11;
        puVar3[3] = uVar12;
        uVar16 = uVar16 + 0x10;
      } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
      if (uVar14 == uVar15) goto LAB_2b6e6c90f20;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_2b6e6c90f20:
  piVar13[2] = uVar4;
  *(undefined2 *)((longlong)piVar1 + uVar15 * 2) = 0;
  lVar7 = *(longlong *)(param_1 + 1);
  iVar6 = *param_1;
  *param_1 = iVar5;
  *(int **)(param_1 + 1) = piVar1;
  if (((iVar6 != 0) && (lVar7 != 0)) &&
     (((int *)(lVar7 + -0xc) != (int *)0x0 && (*(int *)(lVar7 + -0xc) != 0)))) {
    piVar13 = (int *)(lVar7 + -8);
    *piVar13 = *piVar13 + -1;
    if (*piVar13 == 0) {
      (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      return;
    }
  }
  return;
}



/* Address: 2b6e6c90fb0 */

bool FUN_2b6e6c90fb0(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  bool bVar8;
  
  if (param_1 == param_2) {
    return true;
  }
  bVar8 = false;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar3 = *(uint *)(param_1 + -4);
    uVar4 = *(uint *)(param_2 + -4);
    uVar6 = uVar4;
    if (uVar3 < uVar4) {
      uVar6 = uVar3;
    }
    iVar5 = uVar3 - uVar4;
    if (uVar6 != 0) {
      uVar7 = 1;
      do {
        uVar1 = *(ushort *)(param_1 + -2 + uVar7 * 2);
        uVar2 = *(ushort *)(param_2 + -2 + uVar7 * 2);
        if (uVar6 <= uVar7) break;
        uVar7 = uVar7 + 1;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar5 = (uint)uVar1 - (uint)uVar2;
      }
    }
    bVar8 = iVar5 == 0;
  }
  return bVar8;
}



/* Address: 2b6e6c91030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c91030(longlong param_1,uint param_2,uint param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  uVar2 = 0xfa9;
  if ((param_1 == 0) || (param_1 + -0xc == 0)) {
LAB_2b6e6c910b7:
    _DAT_2b6e6d43d10 = uVar2;
    if ((_DAT_2b6e6d43d40 != (int *)0x0) && (_DAT_2b6e6d43d40 != (int *)0xc)) {
      if ((_DAT_2b6e6d43d40[-1] != 0) &&
         (cVar3 = FUN_2b6e6c90060(0x2b6e6d43d3c,0), piVar5 = _DAT_2b6e6d43d40, cVar3 != '\0')) {
        _DAT_2b6e6d43d40[-1] = 0;
        *(undefined2 *)piVar5 = 0;
      }
      return;
    }
    _DAT_2b6e6d43d10 = 0xfa9;
    return;
  }
  uVar9 = *(uint *)(param_1 + -4);
  if (((int)param_2 < 0) && (param_2 = param_2 + uVar9, (int)param_2 < 0)) {
    uVar2 = 0x13ab;
    goto LAB_2b6e6c910b7;
  }
  uVar4 = uVar9 - param_2;
  uVar2 = 0x13ab;
  if (uVar9 < param_2 || uVar4 == 0) goto LAB_2b6e6c910b7;
  uVar9 = uVar4;
  if ((-1 < (int)param_3) && (uVar9 = param_3, (int)uVar4 < (int)param_3)) {
    _DAT_2b6e6d43d10 = 0x13ab;
    uVar9 = uVar4;
  }
  uVar2 = _DAT_2b6e6d43d10;
  if (uVar9 == 0) goto LAB_2b6e6c910b7;
  lVar7 = param_1 + -0xc + (ulonglong)param_2 * 2 + 0xc;
  uVar10 = (ulonglong)uVar9;
  if (lVar7 == 0) {
    if ((((iRam000002b6e6d43d3c != 0) && (_DAT_2b6e6d43d40 != (int *)0x0)) &&
        (_DAT_2b6e6d43d40 + -3 != (int *)0x0)) && (_DAT_2b6e6d43d40[-3] != 0)) {
      piVar5 = _DAT_2b6e6d43d40 + -2;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      }
    }
    if (uVar9 - 1 < 0xfffffffe) {
      _DAT_2b6e6d43d10 = 0xfa2;
      iRam000002b6e6d43d3c = 0;
      _DAT_2b6e6d43d40 = (int *)0x0;
      return;
    }
    iRam000002b6e6d43d3c = 0;
    _DAT_2b6e6d43d40 = (int *)0x0;
    return;
  }
  if (uVar9 == 0xffffffff) {
    uVar10 = 0xffffffff;
    do {
      uVar10 = (ulonglong)((int)uVar10 + 1);
    } while (*(short *)(lVar7 + uVar10 * 2) != 0);
  }
  uVar9 = (uint)uVar10;
  uVar8 = 0x3fffffe8;
  if (uVar9 < 0x3fffffe8) {
    uVar8 = uVar10;
  }
  puVar6 = (uint *)(_DAT_2b6e6d43d40 + -3);
  if (_DAT_2b6e6d43d40 == (int *)0x0) {
    puVar6 = (uint *)0x0;
  }
  uVar4 = (uint)uVar8;
  if ((iRam000002b6e6d43d3c != 0) && (puVar6 != (uint *)0x0)) {
    if ((uVar4 <= *puVar6) && (puVar6[1] == 1)) goto LAB_2b6e6c902b7;
    if (*puVar6 != 0) {
      puVar6 = puVar6 + 1;
      *puVar6 = *puVar6 - 1;
      if (*puVar6 == 0) {
        (*(code *)0x7ff63a101200)(0x2b6e1db7188);
      }
    }
    _DAT_2b6e6d43d40 = (int *)0x0;
    iRam000002b6e6d43d3c = 0;
  }
  piVar5 = (int *)(*(code *)0x7ff63a101190)(0x2b6e1db7188);
  if (piVar5 == (int *)0x0) {
    _DAT_2b6e6d43d10 = 0x13aa;
    return;
  }
  piVar5[1] = 1;
  piVar5[2] = 0;
  _DAT_2b6e6d43d40 = piVar5 + 3;
  *(undefined2 *)(piVar5 + 3) = 0;
  iRam000002b6e6d43d3c = *piVar5;
LAB_2b6e6c902b7:
  piVar5 = _DAT_2b6e6d43d40;
  if (uVar9 == 0) {
    _DAT_2b6e6d43d40[-1] = uVar4;
    *(undefined2 *)((longlong)piVar5 + uVar8 * 2) = 0;
    return;
  }
  uVar10 = 0;
  if (uVar9 < 8) goto LAB_2b6e6c90310;
  if ((ulonglong)((longlong)_DAT_2b6e6d43d40 - lVar7) < 0x20) goto LAB_2b6e6c90310;
  uVar10 = (ulonglong)(uVar4 & 0x3ffffff8);
  uVar11 = 0;
  do {
    uVar1 = ((undefined8 *)(lVar7 + uVar11))[1];
    *(undefined8 *)((longlong)piVar5 + uVar11) = *(undefined8 *)(lVar7 + uVar11);
    ((undefined8 *)((longlong)piVar5 + uVar11))[1] = uVar1;
    uVar11 = uVar11 + 0x10;
  } while ((uVar8 * 2 & 0xfffffffffffffff0) != uVar11);
  for (; uVar10 != uVar8; uVar10 = uVar10 + 1) {
LAB_2b6e6c90310:
    *(undefined2 *)((longlong)piVar5 + uVar10 * 2) = *(undefined2 *)(lVar7 + uVar10 * 2);
  }
  piVar5[-1] = uVar4;
  *(undefined2 *)((longlong)piVar5 + uVar8 * 2) = 0;
  if (0x3fffffe8 < uVar9) {
    _DAT_2b6e6d43d10 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2b6e6c91120 */

void FUN_2b6e6c91120(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x1c);
  if (lVar2 != 0) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 8);
    if (uVar5 != 0) {
      lVar3 = 0;
      do {
        uVar4 = (ulonglong)*(uint *)(param_1 + 0xc + lVar3 * 4);
        if (uVar4 == 0) break;
        uVar5 = uVar5 * uVar4;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 3);
      if (uVar5 != 0) {
        plVar6 = (longlong *)(lVar2 + 4);
        do {
          if ((((*(int *)((longlong)plVar6 + -4) != 0) && (lVar3 = *plVar6, lVar3 != 0)) &&
              ((int *)(lVar3 + -0xc) != (int *)0x0)) && (*(int *)(lVar3 + -0xc) != 0)) {
            piVar1 = (int *)(lVar3 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2b6e1db7188);
            }
          }
          *plVar6 = 0;
          *(undefined4 *)((longlong)plVar6 + -4) = 0;
          plVar6 = (longlong *)((longlong)plVar6 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2b6e1db7188,lVar2,0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 2b6e6c91210 */

void FUN_2b6e6c91210(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x1c);
  if (lVar2 != 0) {
    pcVar3 = *(code **)(param_1 + 0x2c);
    if ((pcVar3 != (code *)0x0) && (uVar6 = (ulonglong)*(uint *)(param_1 + 8), uVar6 != 0)) {
      lVar4 = 0;
      do {
        uVar5 = (ulonglong)*(uint *)(param_1 + 0xc + lVar4 * 4);
        if (uVar5 == 0) break;
        uVar6 = uVar6 * uVar5;
        lVar4 = lVar4 + 1;
      } while (lVar4 != 3);
      if (uVar6 != 0) {
        uVar1 = *(uint *)(param_1 + 4);
        lVar4 = lVar2;
        do {
          (*pcVar3)(lVar4);
          lVar4 = lVar4 + (ulonglong)uVar1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2b6e1db7188,lVar2 - *(int *)(lVar2 + -4),0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 2b6e6c912e0 */

void FUN_2b6e6c912e0(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  (*(code *)0x7ff63a1021d0)(0x2b6e1db7188,0,0,param_1,0,param_2,param_3);
  return;
}



/* Address: 2b6e6c91320 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b6e6c91320(undefined8 param_1,ulonglong param_2,longlong param_3,longlong param_4)

{
  ulonglong uVar1;
  short sVar2;
  undefined1 auVar3 [12];
  longlong lVar4;
  short *psVar5;
  ulonglong uVar6;
  short *psVar7;
  longlong lVar8;
  ulonglong uVar9;
  short *psVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong lVar15;
  bool bVar16;
  undefined1 auVar17 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined8 local_10f;
  short local_e8 [96];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 uVar26;
  
  uVar14 = param_4 - 1;
  uVar6 = 1;
  psVar7 = (short *)0x0;
  do {
    while( true ) {
      if (uVar14 < uVar6) goto LAB_2b6e6c913c3;
      uVar12 = uVar6 + uVar14 >> 1;
      uVar9 = *(ulonglong *)(param_3 + uVar12 * 0x10);
      if (uVar9 != param_2) break;
      uVar13 = uVar12;
      if (3 < uVar6 + uVar14) {
        bVar16 = uVar12 != 1;
        puVar11 = (ulonglong *)(uVar12 * 0x10 + param_3 + -0x10);
        do {
          uVar13 = uVar12;
          if (*puVar11 != param_2) break;
          uVar12 = uVar12 - 1;
          puVar11 = puVar11 + -2;
          uVar13 = (ulonglong)bVar16;
        } while (1 < uVar12);
      }
      psVar7 = *(short **)(param_3 + 8 + uVar13 * 0x10);
      if (uVar9 == param_2) goto LAB_2b6e6c913c3;
    }
    uVar13 = uVar12 - 1;
    if ((longlong)uVar9 <= (longlong)param_2) {
      uVar6 = uVar12 + 1;
      uVar13 = uVar14;
    }
    uVar14 = uVar13;
  } while (uVar9 != param_2);
LAB_2b6e6c913c3:
  if (psVar7 != (short *)0x0) goto LAB_2b6e6c91524;
  lVar15 = *(longlong *)(param_3 + 8);
  psVar7 = local_e8 + 1;
  lVar4 = 0;
  psVar5 = local_e8 + 2;
  do {
    psVar10 = psVar5;
    lVar8 = lVar4;
    sVar2 = *(short *)(lVar15 + lVar8 * 2);
    local_e8[lVar8] = sVar2;
    psVar7 = psVar7 + 1;
    lVar4 = lVar8 + 1;
    psVar5 = psVar10 + 1;
  } while (sVar2 != 0);
  local_e8[lVar8] = 0x3a;
  local_e8[lVar8 + 1] = 0x3a;
  bVar16 = (longlong)param_2 < 0;
  if (bVar16) {
    local_e8[lVar8 + 2] = 0x2d;
    param_2 = -param_2;
  }
  uVar6 = (ulonglong)bVar16;
  uVar14 = 0;
  do {
    uVar9 = uVar14;
    *(byte *)((longlong)&local_10f + uVar9 + 7) = (char)param_2 + (char)(param_2 / 10) * -10 | 0x30;
    uVar14 = uVar9 + 1;
    bVar16 = 9 < param_2;
    param_2 = param_2 / 10;
  } while (bVar16);
  if (uVar14 < 8) {
LAB_2b6e6c914d5:
    psVar10 = psVar10 + uVar6;
    lVar15 = 0;
    do {
      *psVar10 = (short)*(char *)((longlong)&local_10f + lVar15 + uVar14 + 6);
      psVar10 = psVar10 + 1;
      lVar15 = lVar15 + -1;
    } while (-lVar15 != uVar14);
    uVar13 = uVar6 - lVar15;
  }
  else {
    puVar11 = (ulonglong *)((longlong)&local_10f + uVar9);
    uVar9 = uVar14 & 0xfffffffffffffff8;
    uVar13 = uVar6 | uVar9;
    uVar12 = 0;
    do {
      uVar1 = *puVar11;
      uVar26 = (undefined1)(uVar1 >> 0x38);
      auVar23._8_6_ = 0;
      auVar23._0_8_ = uVar1;
      auVar23[0xe] = uVar26;
      auVar23[0xf] = uVar26;
      uVar26 = (undefined1)(uVar1 >> 0x30);
      auVar22._14_2_ = auVar23._14_2_;
      auVar22._8_5_ = 0;
      auVar22._0_8_ = uVar1;
      auVar22[0xd] = uVar26;
      auVar21._13_3_ = auVar22._13_3_;
      auVar21._8_4_ = 0;
      auVar21._0_8_ = uVar1;
      auVar21[0xc] = uVar26;
      uVar26 = (undefined1)(uVar1 >> 0x28);
      auVar20._12_4_ = auVar21._12_4_;
      auVar20._8_3_ = 0;
      auVar20._0_8_ = uVar1;
      auVar20[0xb] = uVar26;
      auVar19._11_5_ = auVar20._11_5_;
      auVar19._8_2_ = 0;
      auVar19._0_8_ = uVar1;
      auVar19[10] = uVar26;
      uVar26 = (undefined1)(uVar1 >> 0x20);
      auVar18._10_6_ = auVar19._10_6_;
      auVar18[8] = 0;
      auVar18._0_8_ = uVar1;
      auVar18[9] = uVar26;
      auVar17._9_7_ = auVar18._9_7_;
      auVar17[8] = uVar26;
      auVar17._0_8_ = uVar1;
      uVar26 = (undefined1)(uVar1 >> 0x18);
      auVar3._4_8_ = auVar17._8_8_;
      auVar3[3] = uVar26;
      auVar3[2] = uVar26;
      uVar26 = (undefined1)(uVar1 >> 0x10);
      auVar3[1] = uVar26;
      auVar3[0] = uVar26;
      uVar26 = (undefined1)(uVar1 >> 8);
      auVar25._4_12_ = auVar3;
      auVar25[3] = uVar26;
      auVar25[2] = uVar26;
      auVar25[0] = (undefined1)uVar1;
      auVar25[1] = auVar25[0];
      auVar24._8_4_ = auVar25._0_4_;
      auVar24._0_8_ = auVar17._8_8_;
      auVar24._12_4_ = auVar3._0_4_;
      auVar25 = pshuflw(auVar24,auVar24,0x1b);
      auVar25 = pshufhw(auVar25,auVar25,0x1b);
      auVar25 = psraw(auVar25,8);
      *(undefined1 (*) [16])(psVar7 + uVar6 + uVar12) = auVar25;
      uVar12 = uVar12 + 8;
      puVar11 = puVar11 + -1;
    } while (uVar9 != uVar12);
    bVar16 = uVar14 != uVar9;
    uVar14 = (ulonglong)((uint)uVar14 & 7);
    uVar6 = uVar13;
    if (bVar16) goto LAB_2b6e6c914d5;
  }
  (local_e8 + lVar8 + 2)[uVar13] = 0;
  _DAT_2b6e6d43d10 = 0xfa3;
  psVar7 = local_e8;
LAB_2b6e6c91524:
  FUN_2b6e6c901e0(param_1,psVar7,0xffffffff);
  return param_1;
}



/* Address: 2b6e6c91550 */

undefined8 FUN_2b6e6c91550(void)

{
  return 0;
}



/* Address: 2b6e6c91560 */

void FUN_2b6e6c91560(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x2b6e1db7188,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2b6e6c915b0 */

undefined4 FUN_2b6e6c915b0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  FUN_2b6e6c90d90(&local_70,0x2b6e6ca8e50,0,0x2b6e6d409a8);
  local_80 = 0;
  local_7c = 0;
  FUN_2b6e6c90d90(&local_80,0x2b6e6ca8e50,0,0x2b6e6d409b8);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x2b6e1db7188,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_2b6e6c91782;
    uVar4 = 0x2b6e6d409f8;
    uVar3 = 0x2b6e6d409e8;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_2b6e6c91782;
    uVar4 = 0x2b6e6d409d8;
    uVar3 = 0x2b6e6d409c8;
  }
  FUN_2b6e6c98f90(&local_80,param_2,param_3);
  FUN_2b6e6c90d90(&local_60,0x2b6e6d43d3c,1,uVar3);
  FUN_2b6e6c99980(param_1,&local_70,param_2);
  FUN_2b6e6c90d90(&local_50,0x2b6e6d43d3c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x2b6e1db7188,0xd,3,0x590008,0x2b6e6ca93f8,0x590008,&local_50,0x590008,&local_60);
LAB_2b6e6c91782:
  FUN_2b6e6c90000(&local_80);
  FUN_2b6e6c90000(&local_70);
  FUN_2b6e6c90000(&local_60);
  FUN_2b6e6c90000(&local_50);
  return uVar1;
}



/* Address: 2b6e6c917c0 */

void FUN_2b6e6c917c0(undefined8 *param_1)

{
  FUN_2b6e6c90000(param_1 + 0x41);
  FUN_2b6e6c90000((longlong)param_1 + 0x144);
  FUN_2b6e6c90000((longlong)param_1 + 0x84);
  FUN_2b6e6c90000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,*param_1,0x2b6e4d63b50);
  param_1[1] = 0x2b6e6ca8d70;
  return;
}



/* Address: 2b6e6c91830 */

void FUN_2b6e6c91830(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  FUN_2b6e6c90000(param_1 + 0x48);
  lVar2 = *(longlong *)(param_1 + 0x2c);
  if (lVar2 != 0) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x18);
    if (uVar5 != 0) {
      lVar3 = 0;
      do {
        uVar4 = (ulonglong)*(uint *)(param_1 + 0x1c + lVar3 * 4);
        if (uVar4 == 0) break;
        uVar5 = uVar5 * uVar4;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 3);
      if (uVar5 != 0) {
        plVar6 = (longlong *)(lVar2 + 4);
        do {
          if ((((*(int *)((longlong)plVar6 + -4) != 0) && (lVar3 = *plVar6, lVar3 != 0)) &&
              ((int *)(lVar3 + -0xc) != (int *)0x0)) && (*(int *)(lVar3 + -0xc) != 0)) {
            piVar1 = (int *)(lVar3 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2b6e1db7188);
            }
          }
          *plVar6 = 0;
          *(undefined4 *)((longlong)plVar6 + -4) = 0;
          plVar6 = (longlong *)((longlong)plVar6 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2b6e1db7188,lVar2,0);
    *(undefined8 *)(param_1 + 0x2c) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}



/* Address: 2b6e6c91e40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c91e40(void)

{
  double dVar1;
  double dVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  short *psVar6;
  code *pcVar7;
  double dVar8;
  double dVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  undefined2 *puVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  longlong lVar20;
  double *pdVar21;
  longlong lVar22;
  undefined8 uVar23;
  ulonglong uVar24;
  uint uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  longlong *plVar28;
  uint uVar29;
  short *psVar30;
  int iVar31;
  ulonglong uVar32;
  uint uVar33;
  ulonglong uVar34;
  undefined8 uVar35;
  ulonglong uVar36;
  longlong lVar37;
  longlong lVar38;
  longlong lVar39;
  uint uVar40;
  ulonglong uVar41;
  uint uVar42;
  bool bVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  undefined8 in_stack_fffffffffffffce8;
  undefined8 in_stack_fffffffffffffcf0;
  undefined4 *puVar49;
  undefined4 *puVar50;
  undefined4 local_2e0;
  longlong local_2dc;
  undefined4 local_2d0;
  undefined8 local_2cc;
  ulonglong local_2c0;
  undefined4 local_2b8;
  short *local_2b4;
  undefined4 local_2a8;
  undefined8 local_2a4;
  undefined2 local_298;
  byte bStack_296;
  undefined1 uStack_295;
  undefined4 uStack_294;
  uint uStack_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 local_284;
  undefined4 uStack_280;
  undefined8 local_27c;
  undefined4 local_274;
  undefined4 uStack_270;
  undefined4 local_26c;
  undefined4 uStack_268;
  undefined4 local_260;
  undefined8 local_25c;
  int local_254;
  undefined4 local_250;
  longlong local_24c;
  undefined2 local_240;
  ushort uStack_23e;
  undefined4 uStack_23c;
  uint uStack_238;
  undefined4 uStack_234;
  undefined8 local_230;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 local_220;
  undefined4 uStack_21c;
  undefined8 local_218;
  undefined4 local_210;
  longlong local_208;
  undefined4 local_200;
  undefined8 local_1fc;
  ulonglong local_1f0;
  undefined4 local_1e8;
  undefined8 local_1e4;
  undefined4 local_1d8;
  undefined8 local_1d4;
  uint local_1c8;
  int local_1c4;
  undefined4 local_1c0;
  longlong local_1bc;
  undefined4 local_1b0;
  undefined8 local_1ac;
  ulonglong local_1a0;
  ulonglong local_198;
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined4 local_160;
  longlong local_150;
  longlong local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 uVar51;
  
  local_1c0 = 0;
  local_1bc = 0;
  lVar19 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  uVar23 = 1;
  if (lVar19 < 0x692d9eac) {
    if (lVar19 < 0x69257a60) {
      if ((lVar19 == 0x69242124) || (lVar19 == 0x6924bae4)) {
LAB_2b6e6c91f2a:
        FUN_2b6e6ca4cf0(uVar23);
      }
    }
    else if ((lVar19 == 0x69257a60) || (lVar19 == 0x69260fe8)) {
LAB_2b6e6c91f25:
      uVar23 = 2;
      goto LAB_2b6e6c91f2a;
    }
  }
  else if (lVar19 < 0x69302d0c) {
    if ((lVar19 == 0x692d9eac) || (lVar19 == 0x692eb6fc)) goto LAB_2b6e6c91f25;
  }
  else if ((lVar19 == 0x69302d0c) || (lVar19 == 0x69316230)) goto LAB_2b6e6c91f2a;
  local_240 = 0;
  uStack_23e = 0;
  uStack_23c = 0;
  uStack_238 = 0;
  iVar14 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
  dVar1 = _DAT_2b6e6ca8700;
  uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffcf0 >> 0x20);
  uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffce8 >> 0x20);
  if (0 < iVar14) {
    iVar14 = 0;
    local_2c0 = (ulonglong)_DAT_2b6e6d43e18;
    do {
      lVar19 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar14);
      if (lVar19 != 0) {
        local_140 = 0;
        local_190 = 0;
        uStack_13c = 0;
        uStack_138 = 0;
        uStack_18c = 0;
        uStack_188 = 0;
        (*(code *)0x7ff63a108010)(0x2b6e1db7188,0);
        FUN_2b6e6c90d90(&local_140,0x2b6e6d43d3c,1,0x2b6e6d42a90);
        FUN_2b6e6c90d90(&local_190,&local_140,0,0x2b6e6d42aa0);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_190,1,0x2b6e6d42ab0);
        FUN_2b6e6c90000(&local_190);
        FUN_2b6e6c90000(&local_190);
        FUN_2b6e6c90000(&local_140);
        FUN_2b6e6c90d90(&local_240,0x2b6e6d43d3c,1,0x2b6e6d42a80);
        lVar19 = CONCAT44(uStack_238,uStack_23c);
        if (lVar19 == _DAT_2b6e6d43d2c) {
LAB_2b6e6c921bf:
          uVar36 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc);
          if (uVar36 == local_2c0) {
            (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x10);
            dVar47 = _DAT_2b6e6d43d48;
            iVar15 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,2);
            if (iVar15 == 0) {
              (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
              dVar8 = _DAT_2b6e6d43d48;
              (*(code *)0x7ff63a107f70)(0x2b6e1db7188,4);
              if ((dVar8 - _DAT_2b6e6d43d48 <= _DAT_2b6e6d43a78 * dVar47) ||
                 ((*(code *)0x7ff63a107f70)(0x2b6e1db7188,6),
                 dVar8 - (_DAT_2b6e6d43a78 + _DAT_2b6e6d43a80 + dVar1) * dVar47 <= _DAT_2b6e6d43d48)
                 ) goto LAB_2b6e6c9246d;
              (*(code *)0x7ff63a107f70)(0x2b6e1db7188,7);
              dVar2 = _DAT_2b6e6d43d48;
              dVar48 = _DAT_2b6e6d43a78 * dVar47;
              (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,4);
              uVar18 = _DAT_2b6e6d43d20;
              (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
              dVar9 = _DAT_2b6e6d43d48;
              iVar15 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,0x2b6e6ca8e30,0x1f);
              if ((longlong)dVar9 != -0x8000000000000000) {
                dVar46 = (double)(longlong)dVar9;
                if (10 < uVar18) {
                  uVar18 = 0xb;
                }
                dVar9 = (double)(longlong)
                                ((dVar9 - dVar46) *
                                 *(double *)(&DAT_2b6e6ca8ca0 + (ulonglong)uVar18 * 8) +
                                *(double *)((ulonglong)(0.0 < dVar9) * 8 + 0x2b6e6ca8708)) /
                        *(double *)(&DAT_2b6e6ca8ca0 + (ulonglong)uVar18 * 8) + dVar46;
              }
              if ((dVar9 - (dVar8 - dVar48) <= (double)iVar15 * _DAT_2b6e6d43d18) ||
                 (dVar2 - dVar9 <= (double)iVar15 * _DAT_2b6e6d43d18)) goto LAB_2b6e6c9246d;
              dVar8 = dVar8 - dVar47 * _DAT_2b6e6d43a78;
LAB_2b6e6c9270f:
              (*(code *)0x7ff63a107f70)(0x2b6e1db7188,7);
              dVar47 = _DAT_2b6e6d43d48;
              lVar19 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0x11);
              local_140 = 0;
              uStack_13c = 0;
              uStack_138 = 0;
              if (_DAT_2b6e6d43d14 == 0) {
                local_208 = lVar19;
                cVar13 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188);
                if (cVar13 != '\0') {
                  _DAT_2b6e6d43030 = 0;
                  _DAT_2b6e6d43020 = 0;
                  _DAT_2b6e6d43024 = 0;
                  uRam000002b6e6d43028 = 0;
                  uRam000002b6e6d4302c = 0;
                  FUN_2b6e6c90000(&DAT_2b6e6d43034);
                  _DAT_2b6e6d43050 = 0;
                  _DAT_2b6e6d43058 = 0.0;
                  _DAT_2b6e6d43060 = 0.0;
                  _DAT_2b6e6d43068 = 0;
                  _DAT_2b6e6d43070 = 0;
                  _DAT_2b6e6d43078 = 0;
                  _DAT_2b6e6d43080 = 0;
                  _DAT_2b6e6d43040 = 0.0;
                  _DAT_2b6e6d43048 = 0.0;
                  FUN_2b6e6c90000(&DAT_2b6e6d43084);
                  _DAT_2b6e6d43120 = 0;
                  uRam000002b6e6d43128 = 0;
                  _DAT_2b6e6d43110 = 0;
                  uRam000002b6e6d43118 = 0;
                  _DAT_2b6e6d43130 = 0;
                  uRam000002b6e6d43138 = 0;
                  _DAT_2b6e6d43100 = 0;
                  uRam000002b6e6d43108 = 0;
                  _DAT_2b6e6d430f0 = 0;
                  uRam000002b6e6d430f8 = 0;
                  _DAT_2b6e6d430e0 = 0;
                  uRam000002b6e6d430e8 = 0;
                  _DAT_2b6e6d430d0 = 0;
                  uRam000002b6e6d430d8 = 0;
                  _DAT_2b6e6d430c0 = 0;
                  uRam000002b6e6d430c8 = 0;
                  _DAT_2b6e6d430b0 = 0;
                  uRam000002b6e6d430b8 = 0;
                  _DAT_2b6e6d430a0 = 0;
                  uRam000002b6e6d430a8 = 0;
                  _DAT_2b6e6d43090 = 0;
                  uRam000002b6e6d43098 = 0;
                  _DAT_2b6e6d43140 = 0;
                  FUN_2b6e6c90000(&DAT_2b6e6d43144);
                  _DAT_2b6e6d431e0 = 0;
                  uRam000002b6e6d431e8 = 0;
                  _DAT_2b6e6d431d0 = 0;
                  uRam000002b6e6d431d8 = 0;
                  _DAT_2b6e6d431f0 = 0;
                  uRam000002b6e6d431f8 = 0;
                  _DAT_2b6e6d431c0 = 0;
                  uRam000002b6e6d431c8 = 0;
                  _DAT_2b6e6d431b0 = 0;
                  uRam000002b6e6d431b8 = 0;
                  _DAT_2b6e6d431a0 = 0;
                  uRam000002b6e6d431a8 = 0;
                  _DAT_2b6e6d43190 = 0;
                  uRam000002b6e6d43198 = 0;
                  _DAT_2b6e6d43180 = 0;
                  uRam000002b6e6d43188 = 0;
                  _DAT_2b6e6d43170 = 0;
                  uRam000002b6e6d43178 = 0;
                  _DAT_2b6e6d43160 = 0;
                  uRam000002b6e6d43168 = 0;
                  _DAT_2b6e6d43150 = 0;
                  uRam000002b6e6d43158 = 0;
                  _DAT_2b6e6d43200 = 0;
                  FUN_2b6e6c90000(&DAT_2b6e6d43208);
                  _DAT_2b6e6d43284 = 0;
                  _DAT_2b6e6d4327c = 0;
                  _DAT_2b6e6d4328c = 0;
                  _DAT_2b6e6d43274 = 0;
                  _DAT_2b6e6d4326c = 0;
                  _DAT_2b6e6d43264 = 0;
                  _DAT_2b6e6d4325c = 0;
                  _DAT_2b6e6d43254 = 0;
                  _DAT_2b6e6d4324c = 0;
                  _DAT_2b6e6d43244 = 0;
                  _DAT_2b6e6d4323c = 0;
                  _DAT_2b6e6d43234 = 0;
                  _DAT_2b6e6d4322c = 0;
                  _DAT_2b6e6d43224 = 0;
                  _DAT_2b6e6d4321c = 0;
                  _DAT_2b6e6d43214 = 0;
                  _DAT_2b6e6d43020 = 6;
                  _DAT_2b6e6d43090 = local_208;
                  (*(code *)0x7ff63a108010)(0x2b6e1db7188,0);
                  FUN_2b6e6c90d90(&local_140,0x2b6e6d43d3c,1,0x2b6e6d40938);
                  FUN_2b6e6c90d90(&DAT_2b6e6d43034,&local_140,0,0x2b6e6d40948);
                  _DAT_2b6e6d43024 = (undefined4)_DAT_2b6e6d43295;
                  uRam000002b6e6d43028 = (undefined4)((ulonglong)_DAT_2b6e6d43295 >> 0x20);
                  _DAT_2b6e6d43060 = dVar47;
                  _DAT_2b6e6d43058 = dVar8;
                  FUN_2b6e6c915b0(&DAT_2b6e6d43000,&DAT_2b6e6d43020,&DAT_2b6e6d43110);
                }
              }
              else {
                in_stack_fffffffffffffcf0 =
                     CONCAT44((int)((ulonglong)in_stack_fffffffffffffcf0 >> 0x20),0x590008);
                in_stack_fffffffffffffce8 = 0x2b6e6caa3d0;
                (*(code *)0x7ff63a0e49f0)
                          (0x2b6e1db7188,0xd,2,0x590008,0x2b6e6caa3d0,in_stack_fffffffffffffcf0,
                           0x2b6e6ca9350);
                _DAT_2b6e6d43110 = CONCAT44(DAT_2b6e6d43110_4,0x272b);
              }
              FUN_2b6e6c90000(&local_140);
            }
            else {
LAB_2b6e6c9246d:
              uVar18 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,2);
              if (uVar18 == DAT_2b6e6d43769) {
                (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,4);
                dVar8 = _DAT_2b6e6d43d48;
                (*(code *)0x7ff63a107f70)(0x2b6e1db7188,4);
                if (_DAT_2b6e6d43a78 * dVar47 < _DAT_2b6e6d43d48 - dVar8) {
                  (*(code *)0x7ff63a107f70)(0x2b6e1db7188,6);
                  if (_DAT_2b6e6d43d48 <=
                      (_DAT_2b6e6d43a78 + _DAT_2b6e6d43a80 + dVar1) * dVar47 + dVar8) {
                    (*(code *)0x7ff63a107f70)(0x2b6e1db7188,6);
                    if ((_DAT_2b6e6d43d48 != 0.0) || (NAN(_DAT_2b6e6d43d48))) goto LAB_2b6e6c92060;
                  }
                  (*(code *)0x7ff63a107f70)(0x2b6e1db7188,7);
                  dVar2 = _DAT_2b6e6d43d48;
                  uVar18 = _DAT_2b6e6d43d20;
                  dVar48 = _DAT_2b6e6d43a78 * dVar47;
                  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,4);
                  dVar9 = _DAT_2b6e6d43d48;
                  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
                  iVar15 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,0x2b6e6ca8e30,0x1f);
                  if ((longlong)dVar9 != -0x8000000000000000) {
                    dVar46 = (double)(longlong)dVar9;
                    if (10 < uVar18) {
                      uVar18 = 0xb;
                    }
                    dVar9 = (double)(longlong)
                                    ((dVar9 - dVar46) *
                                     *(double *)(&DAT_2b6e6ca8ca0 + (ulonglong)uVar18 * 8) +
                                    *(double *)((ulonglong)(0.0 < dVar9) * 8 + 0x2b6e6ca8708)) /
                            *(double *)(&DAT_2b6e6ca8ca0 + (ulonglong)uVar18 * 8) + dVar46;
                  }
                  if (((double)iVar15 * _DAT_2b6e6d43d18 < dVar9 - dVar2) &&
                     ((double)iVar15 * _DAT_2b6e6d43d18 < (dVar48 + dVar8) - dVar9)) {
                    dVar8 = dVar8 + dVar47 * _DAT_2b6e6d43a78;
                    goto LAB_2b6e6c9270f;
                  }
                }
              }
            }
          }
        }
        else if ((lVar19 != 0) && (_DAT_2b6e6d43d2c != 0)) {
          uVar18 = *(uint *)(lVar19 + -4);
          uVar17 = *(uint *)(_DAT_2b6e6d43d2c + -4);
          uVar25 = uVar17;
          if (uVar18 < uVar17) {
            uVar25 = uVar18;
          }
          iVar15 = uVar18 - uVar17;
          if (uVar25 != 0) {
            uVar36 = 1;
            do {
              uVar3 = *(ushort *)(lVar19 + -2 + uVar36 * 2);
              uVar4 = *(ushort *)(_DAT_2b6e6d43d2c + -2 + uVar36 * 2);
              if (uVar25 <= uVar36) break;
              uVar36 = uVar36 + 1;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar15 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar15 == 0) goto LAB_2b6e6c921bf;
        }
      }
LAB_2b6e6c92060:
      iVar14 = iVar14 + 1;
      iVar15 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
      uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffcf0 >> 0x20);
      uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffce8 >> 0x20);
    } while (iVar14 < iVar15);
  }
  FUN_2b6e6c90000(&local_240);
  lVar19 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  local_140 = 0x7e9;
  uStack_13c = 0xc;
  uStack_138 = 5;
  lVar20 = (*(code *)0x7ff63a102140)(0x2b6e1db7188,&local_140);
  if (lVar20 < lVar19) {
    uVar23 = 0x14;
    if (DAT_2b6e6d43ac0 == '\0') {
      uVar23 = 0;
    }
    lVar19 = (*(code *)0x7ff63a103b50)(0x2b6e1db7188,0x2b6e6ca8e30,uVar23,0);
    if (lVar19 == _DAT_2b6e6d43c18) goto LAB_2b6e6c93005;
    _DAT_2b6e6d43c18 = lVar19;
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,&DAT_2b6e6d43ae0,2,0);
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,&DAT_2b6e6d43b20,2,0);
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,&DAT_2b6e6d43b60,2,0);
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,&DAT_2b6e6d43ba0,2,0);
    (*(code *)0x7ff63a0da0e0)(0x2b6e1db7188,&DAT_2b6e6d43be0,2,0);
    uVar45 = (undefined4)((ulonglong)&DAT_2b6e6d43ae0 >> 0x20);
    iVar14 = (*(code *)0x7ff63a0eeec0)
                       (0x2b6e1db7188,_DAT_2b6e6d43ad0,0,1,CONCAT44(uVar44,2),&DAT_2b6e6d43ae0);
    if (iVar14 != 2) goto LAB_2b6e6c93005;
    uVar45 = (undefined4)((ulonglong)&DAT_2b6e6d43b20 >> 0x20);
    iVar14 = (*(code *)0x7ff63a0eeec0)(0x2b6e1db7188,_DAT_2b6e6d43ad4,0,1,2,&DAT_2b6e6d43b20);
    if (iVar14 != 2) goto LAB_2b6e6c93005;
    uVar45 = (undefined4)((ulonglong)&DAT_2b6e6d43b60 >> 0x20);
    iVar14 = (*(code *)0x7ff63a0eeec0)(0x2b6e1db7188,_DAT_2b6e6d43acc,0,1,2,&DAT_2b6e6d43b60);
    if (iVar14 != 2) goto LAB_2b6e6c93005;
    uVar45 = (undefined4)((ulonglong)&DAT_2b6e6d43ba0 >> 0x20);
    iVar14 = (*(code *)0x7ff63a0eeec0)(0x2b6e1db7188,_DAT_2b6e6d43ac4,0,1,2,&DAT_2b6e6d43ba0);
    if (iVar14 != 2) goto LAB_2b6e6c93005;
    uVar45 = (undefined4)((ulonglong)&DAT_2b6e6d43be0 >> 0x20);
    iVar14 = (*(code *)0x7ff63a0eeec0)(0x2b6e1db7188,_DAT_2b6e6d43ac8,0,1,2,&DAT_2b6e6d43be0);
    if (iVar14 != 2) goto LAB_2b6e6c93005;
    uVar36 = (ulonglong)_DAT_2b6e6d43ae8;
    if (uVar36 == 0) goto LAB_2b6e6c9612a;
    lVar19 = 0;
    if ((_DAT_2b6e6d43ae2 & 0x10) != 0) {
      lVar19 = uVar36 - 1;
    }
    if (uVar36 == 1) goto LAB_2b6e6c9614a;
    uVar32 = (ulonglong)_DAT_2b6e6d43b28;
    lVar20 = 1;
    if ((_DAT_2b6e6d43ae2 & 0x10) != 0) {
      lVar20 = uVar36 - 2;
    }
    if (uVar32 == 0) goto LAB_2b6e6c9616a;
    lVar38 = 0;
    if ((_DAT_2b6e6d43b22 & 0x10) != 0) {
      lVar38 = uVar32 - 1;
    }
    if (uVar32 == 1) goto LAB_2b6e6c9618a;
    lVar22 = 1;
    if ((_DAT_2b6e6d43b22 & 0x10) != 0) {
      lVar22 = uVar32 - 2;
    }
    if ((ulonglong)_DAT_2b6e6d43b68 == 0) goto LAB_2b6e6c961aa;
    lVar39 = 0;
    if ((DAT_2b6e6d43b62 & 0x10) != 0) {
      lVar39 = (ulonglong)_DAT_2b6e6d43b68 - 1;
    }
    if ((ulonglong)_DAT_2b6e6d43ba8 == 0) goto LAB_2b6e6c961ca;
    lVar37 = 0;
    if ((DAT_2b6e6d43ba2 & 0x10) != 0) {
      lVar37 = (ulonglong)_DAT_2b6e6d43ba8 - 1;
    }
    if ((ulonglong)_DAT_2b6e6d43be8 != 0) {
      dVar1 = *(double *)(_DAT_2b6e6d43afc + lVar19 * 8);
      dVar47 = *(double *)(_DAT_2b6e6d43afc + lVar20 * 8);
      dVar8 = *(double *)(_DAT_2b6e6d43b3c + lVar38 * 8);
      dVar48 = *(double *)(_DAT_2b6e6d43b3c + lVar22 * 8);
      dVar9 = *(double *)(_DAT_2b6e6d43b7c + lVar39 * 8);
      dVar2 = *(double *)(_DAT_2b6e6d43bbc + lVar37 * 8);
      lVar19 = 0;
      if ((DAT_2b6e6d43be2 & 0x10) != 0) {
        lVar19 = (ulonglong)_DAT_2b6e6d43be8 - 1;
      }
      dVar46 = *(double *)(_DAT_2b6e6d43bfc + lVar19 * 8);
      if ((((dVar47 < dVar48) && (dVar8 < dVar1)) && (0.0 < dVar46)) &&
         ((0.0 < dVar2 && (_DAT_2b6e6d43ab8 < dVar9)))) {
        FUN_2b6e6ca4cf0(1);
      }
      if (((dVar48 < dVar47) && (dVar1 < dVar8)) &&
         ((dVar46 < 0.0 && ((dVar2 < 0.0 && (dVar9 < _DAT_2b6e6ca8718 - _DAT_2b6e6d43ab8)))))) {
        FUN_2b6e6ca4cf0(2);
      }
      goto LAB_2b6e6c93005;
    }
LAB_2b6e6c961ea:
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x28002c000d01f6);
LAB_2b6e6c9620a:
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x3d0050000b01f6);
  }
  else {
LAB_2b6e6c93005:
    lVar19 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
    local_140 = 0x7e9;
    uStack_13c = 0xb;
    uStack_138 = 0x17;
    lVar20 = (*(code *)0x7ff63a102140)(0x2b6e1db7188,&local_140);
    if (((((lVar19 < lVar20) && (cVar13 = FUN_2b6e6c96350(0x7db,7,0x12), cVar13 == '\0')) &&
         (cVar13 = FUN_2b6e6c96350(0x7e8,4,0xc), cVar13 == '\0')) &&
        (((cVar13 = FUN_2b6e6c96350(0x7e8,9,0x12), cVar13 == '\0' &&
          (cVar13 = FUN_2b6e6c96350(0x7e8,9,0x12), cVar13 == '\0')) &&
         (((cVar13 = FUN_2b6e6c96350(0x7e9,6,0xb), cVar13 == '\0' &&
           ((cVar13 = FUN_2b6e6c96350(0x7e9,6,0xd), cVar13 == '\0' &&
            (cVar13 = FUN_2b6e6c96350(0x7e9,10,0xd), cVar13 == '\0')))) &&
          (cVar13 = FUN_2b6e6c96350(0x7db,8,0x19), cVar13 == '\0')))))) &&
       ((((((((cVar13 = FUN_2b6e6c96350(0x7dd,5,0x16), cVar13 == '\0' &&
              (cVar13 = FUN_2b6e6c96350(0x7e7,0xc,4), cVar13 == '\0')) &&
             (cVar13 = FUN_2b6e6c96350(0x7e9,10,6), cVar13 == '\0')) &&
            ((cVar13 = FUN_2b6e6c96350(0x7e9,10,0xd), cVar13 == '\0' &&
             (cVar13 = FUN_2b6e6c96350(0x7e9,10,2), cVar13 == '\0')))) &&
           (cVar13 = FUN_2b6e6c96350(0x7e9,10,0xd), cVar13 == '\0')) &&
          (((cVar13 = FUN_2b6e6c96350(0x7e9,6,0xc), cVar13 == '\0' &&
            (cVar13 = FUN_2b6e6c96350(0x7e9,5,0x1c), cVar13 == '\0')) &&
           ((cVar13 = FUN_2b6e6c96350(0x7e9,4,0x19), cVar13 == '\0' &&
            (((cVar13 = FUN_2b6e6c96350(0x7e9,4,0x16), cVar13 == '\0' &&
              (cVar13 = FUN_2b6e6c96350(0x7e9,10,0x10), cVar13 == '\0')) &&
             (cVar13 = FUN_2b6e6c96350(0x7e9,6,5), cVar13 == '\0')))))))) &&
         ((cVar13 = FUN_2b6e6c96350(0x7e9,0xb,0xe), cVar13 == '\0' &&
          (cVar13 = FUN_2b6e6c96350(0x7e9,10,0x1d), cVar13 == '\0')))) &&
        (cVar13 = FUN_2b6e6c96350(0x7e9,10,0x14), cVar13 == '\0')))) {
      FUN_2b6e6c963b0();
    }
    iVar14 = (*(code *)0x7ff63a102a30)(0x2b6e1db7188,0x2b6e6ca8e30);
    if (_DAT_2b6e6d43a64 == iVar14) {
LAB_2b6e6c94d84:
      if (DAT_2b6e6d43e70 == '\x01') {
        (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x25);
        dVar1 = _DAT_2b6e6d43d48;
        uVar44 = SUB84(_DAT_2b6e6d43d48,0);
        uVar45 = (undefined4)((ulonglong)_DAT_2b6e6d43d48 >> 0x20);
        (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x28);
        dVar47 = _DAT_2b6e6d43d48;
        lVar19 = (*(code *)0x7ff63a103b50)(0x2b6e1db7188,0x2b6e6ca8e30,0x4018,0);
        if (lVar19 == _DAT_2b6e6d43aa8) {
          uVar44 = SUB84(_DAT_2b6e6d43aa0,0);
          uVar45 = (undefined4)((ulonglong)_DAT_2b6e6d43aa0 >> 0x20);
        }
        else {
          _DAT_2b6e6d43aa0 = dVar1;
          _DAT_2b6e6d43aa8 = lVar19;
        }
        if ((((double)CONCAT44(uVar45,uVar44) - dVar47) / (double)CONCAT44(uVar45,uVar44)) *
            _DAT_2b6e6ca8718 <= _DAT_2b6e6d43e80) {
          (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x25);
          dVar1 = _DAT_2b6e6d43d48;
          (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x28);
          dVar47 = _DAT_2b6e6d43d48;
          lVar19 = (*(code *)0x7ff63a103b50)(0x2b6e1db7188,0x2b6e6ca8e30,0x4018,0);
          if (lVar19 != _DAT_2b6e6d43aa8) {
            _DAT_2b6e6d43aa0 = dVar1;
            _DAT_2b6e6d43aa8 = lVar19;
          }
          if (((dVar1 - dVar47) / dVar1) * _DAT_2b6e6ca8718 <= _DAT_2b6e6d43e78)
          goto LAB_2b6e6c955e4;
        }
        iVar14 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
        if (-1 < iVar14 + -1) {
          local_2c0 = CONCAT44(local_2c0._4_4_,_DAT_2b6e6d43e18);
          iVar14 = iVar14 + -1;
          do {
            lVar19 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar14);
            if ((lVar19 != 0) &&
               (cVar13 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,lVar19), cVar13 != '\0')) {
              iVar15 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc);
              (*(code *)0x7ff63a108010)(0x2b6e1db7188,0);
              bVar43 = true;
              FUN_2b6e6c90d90(&local_1c0,0x2b6e6d43d3c,1,0x2b6e6d40870);
              if (local_1bc != _DAT_2b6e6d43d2c) {
                if ((local_1bc == 0) || (_DAT_2b6e6d43d2c == 0)) goto LAB_2b6e6c94fa0;
                uVar18 = *(uint *)(local_1bc + -4);
                uVar17 = *(uint *)(_DAT_2b6e6d43d2c + -4);
                uVar25 = uVar17;
                if (uVar18 < uVar17) {
                  uVar25 = uVar18;
                }
                iVar31 = uVar18 - uVar17;
                if (uVar25 != 0) {
                  uVar36 = 1;
                  do {
                    uVar3 = *(ushort *)(local_1bc + -2 + uVar36 * 2);
                    uVar4 = *(ushort *)(_DAT_2b6e6d43d2c + -2 + uVar36 * 2);
                    if (uVar25 <= uVar36) break;
                    uVar36 = uVar36 + 1;
                  } while (uVar3 == uVar4);
                  if (uVar3 != uVar4) {
                    iVar31 = (uint)uVar3 - (uint)uVar4;
                  }
                }
                bVar43 = iVar31 == 0;
              }
              if ((bVar43) && ((int)local_2c0 == iVar15)) {
                local_140 = 0;
                local_190 = 0;
                uStack_13c = 0;
                uStack_138 = 0;
                uStack_18c = 0;
                uStack_188 = 0;
                if (_DAT_2b6e6d43d14 == 0) {
                  cVar13 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,lVar19);
                  if (cVar13 != '\0') {
                    local_190 = 0;
                    uStack_18c = 0;
                    uStack_188 = 0;
                    (*(code *)0x7ff63a108010)(0x2b6e1db7188,0);
                    FUN_2b6e6c90d90(&local_140,0x2b6e6d43d3c,1,0x2b6e6d40958);
                    FUN_2b6e6c90d90(&local_190,&local_140,0,0x2b6e6d40968);
                    _DAT_2b6e6d43030 = 0;
                    _DAT_2b6e6d43020 = 0;
                    _DAT_2b6e6d43024 = 0;
                    uRam000002b6e6d43028 = 0;
                    uRam000002b6e6d4302c = 0;
                    FUN_2b6e6c90000(&DAT_2b6e6d43034);
                    _DAT_2b6e6d43060 = 0.0;
                    _DAT_2b6e6d43068 = 0;
                    _DAT_2b6e6d43070 = 0;
                    _DAT_2b6e6d43078 = 0;
                    _DAT_2b6e6d43050 = 0;
                    _DAT_2b6e6d43058 = 0.0;
                    _DAT_2b6e6d43040 = 0.0;
                    _DAT_2b6e6d43048 = 0.0;
                    _DAT_2b6e6d43080 = 0;
                    FUN_2b6e6c90000(&DAT_2b6e6d43084);
                    _DAT_2b6e6d43120 = 0;
                    uRam000002b6e6d43128 = 0;
                    _DAT_2b6e6d43110 = 0;
                    uRam000002b6e6d43118 = 0;
                    _DAT_2b6e6d43130 = 0;
                    uRam000002b6e6d43138 = 0;
                    _DAT_2b6e6d43100 = 0;
                    uRam000002b6e6d43108 = 0;
                    _DAT_2b6e6d430f0 = 0;
                    uRam000002b6e6d430f8 = 0;
                    _DAT_2b6e6d430e0 = 0;
                    uRam000002b6e6d430e8 = 0;
                    _DAT_2b6e6d430d0 = 0;
                    uRam000002b6e6d430d8 = 0;
                    _DAT_2b6e6d430c0 = 0;
                    uRam000002b6e6d430c8 = 0;
                    _DAT_2b6e6d430b0 = 0;
                    uRam000002b6e6d430b8 = 0;
                    _DAT_2b6e6d430a0 = 0;
                    uRam000002b6e6d430a8 = 0;
                    _DAT_2b6e6d43090 = 0;
                    uRam000002b6e6d43098 = 0;
                    _DAT_2b6e6d43140 = 0;
                    FUN_2b6e6c90000(&DAT_2b6e6d43144);
                    _DAT_2b6e6d431e0 = 0;
                    uRam000002b6e6d431e8 = 0;
                    _DAT_2b6e6d431d0 = 0;
                    uRam000002b6e6d431d8 = 0;
                    _DAT_2b6e6d431f0 = 0;
                    uRam000002b6e6d431f8 = 0;
                    _DAT_2b6e6d431c0 = 0;
                    uRam000002b6e6d431c8 = 0;
                    _DAT_2b6e6d431b0 = 0;
                    uRam000002b6e6d431b8 = 0;
                    _DAT_2b6e6d431a0 = 0;
                    uRam000002b6e6d431a8 = 0;
                    _DAT_2b6e6d43190 = 0;
                    uRam000002b6e6d43198 = 0;
                    _DAT_2b6e6d43180 = 0;
                    uRam000002b6e6d43188 = 0;
                    _DAT_2b6e6d43170 = 0;
                    uRam000002b6e6d43178 = 0;
                    _DAT_2b6e6d43160 = 0;
                    uRam000002b6e6d43168 = 0;
                    _DAT_2b6e6d43150 = 0;
                    uRam000002b6e6d43158 = 0;
                    _DAT_2b6e6d43200 = 0;
                    FUN_2b6e6c90000(&DAT_2b6e6d43208);
                    _DAT_2b6e6d43284 = 0;
                    _DAT_2b6e6d4327c = 0;
                    _DAT_2b6e6d4328c = 0;
                    _DAT_2b6e6d43274 = 0;
                    _DAT_2b6e6d4326c = 0;
                    _DAT_2b6e6d43264 = 0;
                    _DAT_2b6e6d4325c = 0;
                    _DAT_2b6e6d43254 = 0;
                    _DAT_2b6e6d4324c = 0;
                    _DAT_2b6e6d43244 = 0;
                    _DAT_2b6e6d4323c = 0;
                    _DAT_2b6e6d43234 = 0;
                    _DAT_2b6e6d4322c = 0;
                    _DAT_2b6e6d43224 = 0;
                    _DAT_2b6e6d4321c = 0;
                    _DAT_2b6e6d43214 = 0;
                    cVar13 = FUN_2b6e6c98b90(&local_190);
                    if (cVar13 != '\0') {
                      iVar15 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188);
                      _DAT_2b6e6d43070 = CONCAT44(_DAT_2b6e6d43074,(uint)(iVar15 == 0));
                      (*(code *)0x7ff63a0f2890)
                                (0x2b6e1db7188,&local_190,(iVar15 != 0) * '\x03' + '\x01');
                      _DAT_2b6e6d43048 = _DAT_2b6e6d43d48;
                      _DAT_2b6e6d43020 = 1;
                      _DAT_2b6e6d43090 = lVar19;
                      FUN_2b6e6c90d90(&DAT_2b6e6d43034,&local_190,0,0x2b6e6d40978);
                      (*(code *)0x7ff63a107f70)(0x2b6e1db7188,3);
                      _DAT_2b6e6d43040 = _DAT_2b6e6d43d48;
                      _DAT_2b6e6d43024 = (undefined4)_DAT_2b6e6d43295;
                      uRam000002b6e6d43028 = (undefined4)((ulonglong)_DAT_2b6e6d43295 >> 0x20);
                      _DAT_2b6e6d43068 = _DAT_2b6e6d4329d;
                      FUN_2b6e6c915b0(&DAT_2b6e6d43000,&DAT_2b6e6d43020,&DAT_2b6e6d43110);
                    }
                    FUN_2b6e6c90000(&local_190);
                  }
                }
                else {
                  (*(code *)0x7ff63a0e49f0)
                            (0x2b6e1db7188,0xd,2,0x590008,0x2b6e6caa3d0,0x590008,0x2b6e6ca9398);
                  _DAT_2b6e6d43110 = CONCAT44(DAT_2b6e6d43110_4,0x272b);
                }
                FUN_2b6e6c90000(&local_140);
              }
            }
LAB_2b6e6c94fa0:
            bVar43 = 0 < iVar14;
            iVar14 = iVar14 + -1;
          } while (bVar43);
        }
      }
LAB_2b6e6c955e4:
      iVar14 = (*(code *)0x7ff63a0f0fd0)(0x2b6e1db7188,8);
      bVar43 = true;
      if (iVar14 != 1) {
        iVar14 = (*(code *)0x7ff63a0f0fd0)(0x2b6e1db7188,6);
        bVar43 = iVar14 == 0;
      }
      uVar11 = _DAT_2b6e1e2671a;
      local_27c = (undefined4 *)CONCAT44(local_27c._4_4_,(undefined4)local_27c);
      if ((!bVar43) ||
         (local_27c = (undefined4 *)CONCAT44(local_27c._4_4_,(undefined4)local_27c),
         DAT_2b6e6d43e30 != '\x01')) goto LAB_2b6e6c95f78;
      local_298 = _DAT_2b6e1e2671a;
      bStack_296 = 0;
      uStack_295 = 1;
      uStack_294 = 0x3c;
      uStack_290 = 2;
      uStack_28c = 0;
      uStack_288 = 0;
      local_284 = 0;
      uStack_280 = 2;
      local_27c = &local_140;
      local_274 = 0;
      uStack_270 = 0;
      local_26c = 0;
      uStack_268 = 0;
      iVar14 = FUN_2b6e6c912e0(_DAT_2b6e6d43d24,2,&local_298);
      if (iVar14 < 1) {
LAB_2b6e6c9589c:
        bVar43 = false;
        if (_DAT_2b6e6d43730 < 1) goto LAB_2b6e6c95f48;
LAB_2b6e6c958a6:
        uVar18 = _DAT_2b6e6d43730 - 1;
        cVar13 = (*(code *)0x7ff63a0f2c10)(0x2b6e1db7188,0x2b6e6ca8e30,&local_140);
        if (cVar13 == '\0') {
          (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
          pdVar21 = (double *)&DAT_2b6e6d43d48;
        }
        else {
          pdVar21 = (double *)&uStack_138;
        }
        dVar1 = *pdVar21;
        lVar19 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
        if (0xf < uVar18) {
LAB_2b6e6c9606a:
          (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0xd03f5000901f6);
LAB_2b6e6c9608a:
          (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1d02e0000901f6);
LAB_2b6e6c960aa:
          (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1f02eb000901f6);
          goto LAB_2b6e6c960ca;
        }
        uVar36 = (ulonglong)uVar18;
        lVar20 = uVar36 * 0x18;
        *(double *)(&DAT_2b6e6d434c0 + lVar20) = dVar1;
        *(longlong *)(&DAT_2b6e6d43340 + lVar20) = lVar19;
        dVar1 = (*(double *)(&DAT_2b6e6d434b8 + lVar20) + *(double *)(&DAT_2b6e6d434b0 + lVar20) +
                dVar1) / _DAT_2b6e6ca8720;
        *(longlong *)(&DAT_2b6e6d43630 + uVar36 * 8) =
             (lVar19 + *(longlong *)(&DAT_2b6e6d43338 + lVar20) +
             *(longlong *)(&DAT_2b6e6d43330 + lVar20)) / 3;
        *(double *)(&DAT_2b6e6d436b0 + uVar36 * 8) = dVar1;
        FUN_2b6e6ca2180();
        uVar23 = _DAT_2b6e6ca8728;
        _DAT_2b6e6d43740 =
             (double)(*(code *)0x7ff63a3d9970)
                               (SUB84(_DAT_2b6e6d43740 + _DAT_2b6e6d432c8,0),_DAT_2b6e6ca8728);
        _DAT_2b6e6d43748 =
             (double)(*(code *)0x7ff63a3d9970)(SUB84(_DAT_2b6e6d43748 + _DAT_2b6e6d432e0,0),uVar23);
        _DAT_2b6e6d43750 =
             (double)(*(code *)0x7ff63a3d9970)(SUB84(_DAT_2b6e6d43750 + _DAT_2b6e6d432f8,0),uVar23);
        _DAT_2b6e6d43758 =
             (double)(*(code *)0x7ff63a3d9970)(SUB84(_DAT_2b6e6d43758 + _DAT_2b6e6d43320,0),uVar23);
        FUN_2b6e6ca3560();
        FUN_2b6e6ca3f10();
        FUN_2b6e6ca4650();
        FUN_2b6e6c9c3f0();
        if ((((!bVar43 && (DAT_2b6e6d432b8 & 1) == 0) && ((DAT_2b6e6d432d1 & 1) == 0)) &&
            ((DAT_2b6e6d432e8 & 1) == 0)) && ((DAT_2b6e6d43313 & 1) == 0)) goto LAB_2b6e6c95f78;
      }
      else {
        if (CONCAT44(uStack_13c,local_140) == _DAT_2b6e6d43738) goto LAB_2b6e6c9589c;
        _DAT_2b6e6d43730 = 0;
        _DAT_2b6e6d43738 = CONCAT44(uStack_13c,local_140);
        uVar17 = (*(code *)0x7ff63a102a30)(0x2b6e1db7188,0x2b6e6ca8e30,_DAT_2b6e6d43d24);
        uVar18 = 300;
        if (DAT_2b6e6d432b1 == '\0') {
          uVar18 = 0;
        }
        iVar14 = 0x14;
        if (DAT_2b6e6d432b2 == '\0') {
          iVar14 = 0;
        }
        if (uVar18 <= (uint)(iVar14 * 3)) {
          uVar18 = iVar14 * 3;
        }
        if ((int)uVar17 <= (int)uVar18) {
          uVar18 = uVar17;
        }
        if (iVar14 * 2 <= (int)uVar18) {
          local_240 = uVar11;
          uStack_23e = 1;
          uStack_23c = 0x3c;
          uStack_238 = 0;
          uStack_234 = 0;
          local_230 = 0;
          local_228 = 0;
          uStack_224 = 0;
          local_220 = 0;
          uStack_21c = 0;
          local_218 = 0;
          local_210 = 0;
          uVar18 = FUN_2b6e6c912e0(_DAT_2b6e6d43d24,uVar18,&local_240);
          iVar14 = _DAT_2b6e6d43730;
          if (0 < (int)uVar18) {
            uVar36 = (ulonglong)uVar18;
            if ((uStack_23e & 0xf) != 0) {
              uStack_23e = uStack_23e & 0xffef;
            }
            uVar17 = 5;
            if (DAT_2b6e6d432b2 != '\0') {
              uVar17 = 0x14;
            }
            uVar25 = (uint)(uVar36 / uVar17);
            if ((1 < uVar25) && (DAT_2b6e6d432b3 == '\x01')) {
              uVar29 = uVar25 - 8;
              if (uVar25 < 8) {
                uVar29 = 0;
              }
              local_1f0 = uVar36 / uVar17;
              cVar13 = (*(code *)0x7ff63a0f2c10)(0x2b6e1db7188,0x2b6e6ca8e30,&local_190);
              if (cVar13 == '\0') {
                (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
                pdVar21 = (double *)&DAT_2b6e6d43d48;
              }
              else {
                pdVar21 = (double *)&uStack_188;
              }
              dVar1 = *pdVar21;
              local_148 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
              uVar25 = (uint)local_1f0;
              iVar14 = 0;
              if (uVar29 < uVar25) {
                local_1c4 = uVar18 - 1;
                uVar42 = uVar29 * uVar17;
                local_198 = (ulonglong)(uVar25 - 1);
                local_2c0 = (ulonglong)uStack_238;
                local_254 = uVar42 + 1;
                uVar40 = ~uVar42;
                local_208 = CONCAT44(local_208._4_4_,(uint)uStack_23e);
                local_150 = local_2c0 * 0x3c + -0x78;
                uVar32 = (ulonglong)uVar29;
                lVar19 = 0;
                do {
                  iVar14 = uVar17 * (int)uVar32;
                  lVar20 = lVar19;
                  local_1c8 = uVar17;
                  local_1a0 = uVar36;
                  if ((int)uVar18 <= iVar14) break;
                  uVar33 = (uint)(uVar32 + 1);
                  uVar29 = uVar17 * uVar33;
                  if (uVar32 == local_198) {
                    uVar29 = uVar18;
                  }
                  uVar24 = (ulonglong)iVar14;
                  iVar15 = uVar29 - 1;
                  if ((int)uVar18 <= (int)(uVar29 - 1)) {
                    iVar15 = local_1c4;
                  }
                  if (local_2c0 <= uVar24) goto LAB_2b6e6c9608a;
                  lVar20 = CONCAT44(local_220,uStack_224);
                  uVar41 = ~uVar24 + local_2c0;
                  if ((uStack_23e & 0x10) == 0) {
                    uVar41 = uVar24;
                  }
                  lVar38 = uVar41 * 0x3c;
                  uVar23 = *(undefined8 *)(lVar20 + 0x18 + lVar38);
                  uVar44 = (undefined4)uVar23;
                  uVar45 = (undefined4)((ulonglong)uVar23 >> 0x20);
                  lVar22 = *(longlong *)(lVar20 + lVar38);
                  dVar47 = *(double *)(lVar20 + 0x10 + lVar38);
                  lVar38 = lVar22;
                  if (iVar14 < iVar15) {
                    lVar39 = (longlong)(int)uVar42;
                    uVar24 = 0;
                    if ((ulonglong)(longlong)local_254 <= local_2c0) {
                      uVar24 = local_2c0 - (longlong)local_254;
                    }
                    if ((uStack_23e & 0x10) == 0) {
                      if (uVar24 <= iVar15 + uVar40) goto LAB_2b6e6c960ea;
                      plVar28 = (longlong *)(lVar20 + 0x3c + (longlong)(int)uVar42 * 0x3c);
                      do {
                        dVar8 = (double)plVar28[3];
                        if (dVar8 <= (double)CONCAT44(uVar45,uVar44) &&
                            (double)CONCAT44(uVar45,uVar44) != dVar8) {
                          lVar38 = *plVar28;
                          uVar44 = SUB84(dVar8,0);
                          uVar45 = (undefined4)((ulonglong)dVar8 >> 0x20);
                        }
                        if (dVar47 < (double)plVar28[2]) {
                          lVar22 = *plVar28;
                          dVar47 = (double)plVar28[2];
                        }
                        lVar39 = lVar39 + 1;
                        plVar28 = (longlong *)((longlong)plVar28 + 0x3c);
                      } while (lVar39 < iVar15);
                    }
                    else {
                      if (uVar24 <= iVar15 + uVar40) goto LAB_2b6e6c960ea;
                      plVar28 = (longlong *)((longlong)(int)uVar42 * -0x3c + local_150 + lVar20);
                      do {
                        dVar8 = (double)plVar28[3];
                        if (dVar8 <= (double)CONCAT44(uVar45,uVar44) &&
                            (double)CONCAT44(uVar45,uVar44) != dVar8) {
                          lVar38 = *plVar28;
                          uVar44 = SUB84(dVar8,0);
                          uVar45 = (undefined4)((ulonglong)dVar8 >> 0x20);
                          dVar8 = (double)plVar28[2];
                        }
                        else {
                          dVar8 = (double)plVar28[2];
                        }
                        if (dVar47 < dVar8) {
                          lVar22 = *plVar28;
                          dVar47 = dVar8;
                        }
                        lVar39 = lVar39 + 1;
                        plVar28 = (longlong *)((longlong)plVar28 + -0x3c);
                      } while (lVar39 < iVar15);
                    }
                  }
                  uVar24 = (ulonglong)iVar15;
                  if (local_2c0 <= uVar24) goto LAB_2b6e6c960aa;
                  uVar41 = ~uVar24 + local_2c0;
                  if ((uStack_23e & 0x10) == 0) {
                    uVar41 = uVar24;
                  }
                  lVar39 = local_148;
                  if (uVar32 != local_198) {
                    lVar39 = *(longlong *)(lVar20 + uVar41 * 0x3c);
                  }
                  dVar8 = *(double *)(lVar20 + 0x20 + uVar41 * 0x3c);
                  lVar37 = lVar19 * 0x18;
                  *(ulonglong *)(&DAT_2b6e6d434b0 + lVar37) = CONCAT44(uVar45,uVar44);
                  *(longlong *)(&DAT_2b6e6d43330 + lVar37) = lVar38;
                  *(longlong *)(&DAT_2b6e6d43338 + lVar37) = lVar22;
                  *(double *)(&DAT_2b6e6d434b8 + lVar37) = dVar47;
                  dVar48 = dVar1;
                  if (uVar32 != local_198) {
                    dVar48 = dVar8;
                  }
                  lVar20 = lVar19 + 1;
                  *(longlong *)(&DAT_2b6e6d43340 + lVar37) = lVar39;
                  *(double *)(&DAT_2b6e6d434c0 + lVar37) = dVar48;
                  *(longlong *)(&DAT_2b6e6d43630 + lVar19 * 8) = (lVar22 + lVar38 + lVar39) / 3;
                  *(double *)(&DAT_2b6e6d436b0 + lVar19 * 8) =
                       ((double)CONCAT44(uVar45,uVar44) + dVar47 + dVar48) / _DAT_2b6e6ca8720;
                  if (uVar25 <= uVar33) break;
                  local_254 = local_254 + uVar17;
                  uVar42 = uVar42 + uVar17;
                  uVar40 = uVar40 - uVar17;
                  bVar43 = lVar19 != 0xf;
                  uVar32 = uVar32 + 1;
                  lVar19 = lVar20;
                } while (bVar43);
                iVar14 = (int)lVar20;
              }
            }
          }
          _DAT_2b6e6d43730 = iVar14;
          FUN_2b6e6c91210(&local_240);
        }
        FUN_2b6e6ca2180();
        FUN_2b6e6ca3560();
        FUN_2b6e6ca3f10();
        FUN_2b6e6ca4650();
        bVar43 = true;
        if (0 < _DAT_2b6e6d43730) goto LAB_2b6e6c958a6;
LAB_2b6e6c95f48:
        FUN_2b6e6c96d00();
        FUN_2b6e6c9c3f0();
      }
      (*(code *)0x7ff63a0f51b0)(0x2b6e1db7188,0);
LAB_2b6e6c95f78:
      DAT_2b6e6d43ab0 = 1;
      FUN_2b6e6c90000(&local_1c0);
      return;
    }
    local_2b8 = 0;
    local_2e0 = 0;
    local_1b0 = 0;
    local_1d8 = 0;
    local_250 = 0;
    local_200 = 0;
    local_2a8 = 0;
    local_260 = 0;
    local_2d0 = 0;
    local_1e8 = 0;
    local_2b4 = (short *)0x0;
    local_2dc = 0;
    local_1ac = 0;
    local_1d4 = 0;
    local_24c = 0;
    local_1fc = 0;
    local_2a4 = 0;
    local_25c = 0;
    local_2cc = 0;
    local_1e4 = 0;
    _DAT_2b6e6d43a64 = iVar14;
    if (DAT_2b6e6d43e88 != '\x01') {
LAB_2b6e6c94d71:
      FUN_2b6e6c90000(&local_2e0);
      FUN_2b6e6c90000(&local_2b8);
      goto LAB_2b6e6c94d84;
    }
    if (_DAT_2b6e6d43c34 != &DAT_2b6e6ca8e9c) {
      if (_DAT_2b6e6d43c34 != (undefined1 *)0x0) {
        uVar18 = *(uint *)(_DAT_2b6e6d43c34 + -4);
        uVar17 = _DAT_2b6e6ca8e98;
        if (uVar18 < _DAT_2b6e6ca8e98) {
          uVar17 = uVar18;
        }
        iVar14 = uVar18 - _DAT_2b6e6ca8e98;
        if (uVar17 != 0) {
          uVar36 = 0;
          do {
            uVar3 = *(ushort *)(_DAT_2b6e6d43c34 + uVar36 * 2);
            uVar4 = *(ushort *)(&DAT_2b6e6ca8e9c + uVar36 * 2);
            uVar36 = uVar36 + 1;
            if (uVar17 <= uVar36) break;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar14 = (uint)uVar3 - (uint)uVar4;
          }
        }
        if (iVar14 == 0) goto LAB_2b6e6c93460;
      }
      goto LAB_2b6e6c94d71;
    }
LAB_2b6e6c93460:
    uVar18 = 0;
    FUN_2b6e6c90d90(&local_1b0,0x2b6e6ca8e30,0,0x2b6e6d42428);
    local_1d8 = 0;
    local_250 = 0;
    local_1d4 = 0;
    local_24c = 0;
    local_140 = 0x1004d;
    uStack_13c = 1;
    local_190 = 0x1004d;
    uStack_18c = 1;
    uStack_138 = 0;
    uStack_134 = 0;
    local_130 = 0;
    local_128 = 0;
    local_120 = 0;
    local_118 = 0;
    local_110 = 0;
    uStack_188 = 0;
    uStack_184 = 0;
    local_180 = 0;
    local_178 = 0;
    local_170 = 0;
    local_168 = 0;
    local_160 = 0;
    FUN_2b6e6c90d90(&local_2e0,&DAT_2b6e6d43c30,0,0x2b6e6d42438);
    uVar17 = _DAT_2b6e6cab488;
    uVar36 = (ulonglong)_DAT_2b6e6cab488;
    if ((uVar36 != 0) || (local_2dc == 0)) {
      if (local_2dc != 0) {
        uVar18 = *(uint *)(local_2dc + -4);
      }
      uVar29 = _DAT_2b6e6cab488 + uVar18;
      uVar25 = 0x104;
      if ((0x103 < uVar29) &&
         ((0x3fffffe7 < uVar29 || (uVar25 = (uVar29 >> 2) + uVar29, 0x3fffffe7 < uVar25)))) {
        uVar25 = 0x3fffffe8;
      }
      cVar13 = FUN_2b6e6c90060(&local_2e0,uVar25);
      if (cVar13 != '\0') {
        if (uVar36 != 0) {
          lVar19 = local_2dc + (ulonglong)uVar18 * 2;
          if (uVar17 < 0x10) {
            uVar32 = 0;
          }
          else if (lVar19 - 0x2b6e6cab48cU < 0x20) {
            uVar32 = 0;
          }
          else {
            uVar24 = 0;
            uVar32 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar44 = *(undefined4 *)(uVar24 + 0x2b6e6cab490);
              uVar51 = *(undefined4 *)(uVar24 + 0x2b6e6cab494);
              uVar10 = *(undefined4 *)(uVar24 + 0x2b6e6cab498);
              puVar50 = (undefined4 *)(lVar19 + uVar24);
              *puVar50 = *(undefined4 *)(&DAT_2b6e6cab48c + uVar24);
              puVar50[1] = uVar44;
              puVar50[2] = uVar51;
              puVar50[3] = uVar10;
              uVar24 = uVar24 + 0x10;
            } while ((uVar36 * 2 & 0xfffffffffffffff0) != uVar24);
            if (uVar32 == uVar36) goto LAB_2b6e6c93682;
          }
          do {
            *(undefined2 *)(lVar19 + uVar32 * 2) = *(undefined2 *)(&DAT_2b6e6cab48c + uVar32 * 2);
            uVar32 = uVar32 + 1;
          } while (uVar36 != uVar32);
        }
LAB_2b6e6c93682:
        *(uint *)(local_2dc + -4) = uVar29;
        *(undefined2 *)(local_2dc + (ulonglong)uVar29 * 2) = 0;
        goto LAB_2b6e6c9368d;
      }
LAB_2b6e6c960ca:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x230007000b01f9);
LAB_2b6e6c960ea:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1202e7000901f6);
LAB_2b6e6c9610a:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x3f0043000b01f6);
LAB_2b6e6c9612a:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x270026000d01f6);
LAB_2b6e6c9614a:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x270027000d01f6);
LAB_2b6e6c9616a:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x270028000d01f6);
LAB_2b6e6c9618a:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x270029000d01f6);
LAB_2b6e6c961aa:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x26002a000d01f6);
LAB_2b6e6c961ca:
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x28002b000d01f6);
      goto LAB_2b6e6c961ea;
    }
LAB_2b6e6c9368d:
    FUN_2b6e6c90d90(&local_250,&local_2e0,0,0x2b6e6d42448);
    _DAT_2b6e6d43d10 = 0;
    uVar23 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
    if (((int)uVar23 - _DAT_2b6e6d43760 < 0x12d) && ((DAT_2b6e6d43768 & 1) == 0)) {
LAB_2b6e6c94d22:
      FUN_2b6e6c90000(&local_250);
      (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&local_190);
      (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&local_140);
      FUN_2b6e6c90000(&local_1d8);
      FUN_2b6e6c90000(&local_1b0);
      goto LAB_2b6e6c94d71;
    }
    puVar50 = &local_190;
    puVar49 = &local_140;
    uVar36 = 0x2b6e6ca8e30;
    uVar35 = CONCAT44(uVar45,5000);
    iVar14 = (*(code *)0x7ff63a0e5df0)
                       (0x2b6e1db7188,0x2b6e6cab4e8,&local_250,&local_1b0,0x2b6e6ca8e30,uVar35,
                        puVar49,0,puVar50,&local_1d8);
    uVar45 = (undefined4)((ulonglong)puVar49 >> 0x20);
    uVar44 = (undefined4)((ulonglong)uVar35 >> 0x20);
    uVar51 = (undefined4)((ulonglong)puVar50 >> 0x20);
    DAT_2b6e6d43768 = 0;
    _DAT_2b6e6d43760 = uVar23;
    if (iVar14 == 200) {
      local_200 = 0;
      local_1fc = 0;
      (*(code *)0x7ff63a0fe920)(0x2b6e1db7188,&local_190,0,0xffffffff,uVar36 & 0xffffffff00000000);
      FUN_2b6e6c90d90(&local_2e0,0x2b6e6d43d3c,0,0x2b6e6d42478);
      FUN_2b6e6c90d90(&local_200,&local_2e0,0,0x2b6e6d42488);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd,2,0x590008,0x2b6e6cab680,CONCAT44(uVar44,0x520004),
                 CONCAT44(uVar45,uStack_188));
      local_240 = 0x59;
      uStack_23e = 1;
      uStack_23c = 0xc;
      uStack_238 = 0;
      uStack_234 = 0;
      local_230 = 0;
      local_228 = 0;
      uStack_224 = 0;
      local_220 = 0;
      uStack_21c = 0;
      local_218 = 0;
      local_210 = 0;
      FUN_2b6e6c903c0(_DAT_2b6e6d43c44,0x2c,&local_240);
      local_2c0 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
      local_298 = 0x59;
      bStack_296 = 1;
      uStack_295 = 0;
      uStack_294 = 0xc;
      uStack_290 = 0;
      uStack_28c = 0;
      uStack_288 = 0;
      local_284 = 0;
      uStack_280 = 0;
      local_27c._0_4_ = 0;
      local_27c._4_4_ = 0;
      local_274 = 0;
      uStack_270 = 0;
      local_26c = 0;
      uStack_268 = 0;
      FUN_2b6e6c903c0(local_1fc,0x7d,&local_298);
      if (0 < (int)uStack_290) {
        uVar36 = 0;
LAB_2b6e6c93a44:
        uVar32 = (ulonglong)uStack_238;
        if (0 < (int)uStack_238) {
          uVar41 = 0;
          uVar24 = ~uVar36;
          do {
            if ((uVar32 & 0xffffffff) <= uVar41) {
              (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x470035000b01f6);
LAB_2b6e6c9600a:
              (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x310035000b01f6);
LAB_2b6e6c9602a:
              (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x4a0035000b01f9);
LAB_2b6e6c9604a:
              (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x3a0035000b01f9);
              goto LAB_2b6e6c9606a;
            }
            lVar19 = CONCAT44(local_220,uStack_224);
            uVar32 = ~uVar41 + (uVar32 & 0xffffffff);
            if ((uStack_23e & 0x10) == 0) {
              uVar32 = uVar41;
            }
            FUN_2b6e6c90d90(&local_2e0,0x2b6e6cab6a0,0);
            lVar19 = *(longlong *)(lVar19 + 4 + uVar32 * 0xc);
            if (lVar19 != 0) {
              uVar18 = *(uint *)(lVar19 + -4);
              uVar32 = (ulonglong)uVar18;
              if ((uVar32 == 0) && (local_2dc != 0)) goto LAB_2b6e6c93bdd;
              if (local_2dc == 0) {
                uVar17 = 0;
                uVar25 = uVar18;
              }
              else {
                uVar17 = *(uint *)(local_2dc + -4);
                uVar25 = uVar18 + uVar17;
              }
              cVar13 = FUN_2b6e6c90060(&local_2e0);
              if (cVar13 != '\0') {
                if (uVar32 != 0) {
                  lVar20 = local_2dc + (ulonglong)uVar17 * 2;
                  if (uVar18 < 8) {
                    uVar26 = 0;
                  }
                  else if ((ulonglong)(lVar20 - lVar19) < 0x20) {
                    uVar26 = 0;
                  }
                  else {
                    uVar27 = 0;
                    uVar26 = (ulonglong)(uVar18 & 0xfffffff8);
                    do {
                      puVar50 = (undefined4 *)(lVar19 + uVar27);
                      uVar44 = puVar50[1];
                      uVar45 = puVar50[2];
                      uVar51 = puVar50[3];
                      puVar49 = (undefined4 *)(lVar20 + uVar27);
                      *puVar49 = *puVar50;
                      puVar49[1] = uVar44;
                      puVar49[2] = uVar45;
                      puVar49[3] = uVar51;
                      uVar27 = uVar27 + 0x10;
                    } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar27);
                    if (uVar26 == uVar32) goto LAB_2b6e6c93bd2;
                  }
                  do {
                    *(undefined2 *)(lVar20 + uVar26 * 2) = *(undefined2 *)(lVar19 + uVar26 * 2);
                    uVar26 = uVar26 + 1;
                  } while (uVar32 != uVar26);
                }
LAB_2b6e6c93bd2:
                *(uint *)(local_2dc + -4) = uVar25;
                *(undefined2 *)(local_2dc + (ulonglong)uVar25 * 2) = 0;
                goto LAB_2b6e6c93bdd;
              }
              goto LAB_2b6e6c9604a;
            }
LAB_2b6e6c93bdd:
            FUN_2b6e6c90d90(&local_2b8,&local_2e0,0,0x2b6e6d424a8);
            uVar18 = _DAT_2b6e6cab694;
            uVar32 = (ulonglong)_DAT_2b6e6cab694;
            if ((uVar32 != 0) || (local_2b4 == (short *)0x0)) {
              if (local_2b4 == (short *)0x0) {
                uVar17 = 0;
                uVar25 = _DAT_2b6e6cab694;
              }
              else {
                uVar17 = *(uint *)(local_2b4 + -2);
                uVar25 = _DAT_2b6e6cab694 + uVar17;
              }
              uVar29 = 0x104;
              if ((0x103 < uVar25) &&
                 ((0x3fffffe7 < uVar25 || (uVar29 = (uVar25 >> 2) + uVar25, 0x3fffffe7 < uVar29))))
              {
                uVar29 = 0x3fffffe8;
              }
              cVar13 = FUN_2b6e6c90060(&local_2b8,uVar29);
              if (cVar13 != '\0') {
                if (uVar32 != 0) {
                  uVar26 = (ulonglong)uVar17;
                  if (uVar18 < 8) {
                    uVar27 = 0;
                  }
                  else if (local_2b4 + (uVar26 - 0x15b73655b4c) < (short *)0x20) {
                    uVar27 = 0;
                  }
                  else {
                    uVar34 = 0;
                    uVar27 = (ulonglong)(uVar18 & 0xfffffff8);
                    do {
                      uVar44 = *(undefined4 *)(uVar34 + 0x2b6e6cab69c);
                      uVar45 = *(undefined4 *)(uVar34 + 0x2b6e6cab6a0);
                      uVar51 = *(undefined4 *)(uVar34 + 0x2b6e6cab6a4);
                      puVar50 = (undefined4 *)((longlong)local_2b4 + uVar34 + uVar26 * 2);
                      *puVar50 = *(undefined4 *)(&DAT_2b6e6cab698 + uVar34);
                      puVar50[1] = uVar44;
                      puVar50[2] = uVar45;
                      puVar50[3] = uVar51;
                      uVar34 = uVar34 + 0x10;
                    } while ((uVar32 * 2 & 0xfffffffffffffff0) != uVar34);
                    if (uVar27 == uVar32) goto LAB_2b6e6c93d13;
                  }
                  do {
                    local_2b4[uVar26 + uVar27] = *(short *)(&DAT_2b6e6cab698 + uVar27 * 2);
                    uVar27 = uVar27 + 1;
                  } while (uVar32 != uVar27);
                }
LAB_2b6e6c93d13:
                *(uint *)(local_2b4 + -2) = uVar25;
                local_2b4[uVar25] = 0;
                goto LAB_2b6e6c93d20;
              }
              goto LAB_2b6e6c9602a;
            }
LAB_2b6e6c93d20:
            if (uStack_290 <= uVar36) goto LAB_2b6e6c9600a;
            uVar32 = uStack_290 + uVar24;
            if ((bStack_296 & 0x10) == 0) {
              uVar32 = uVar36;
            }
            psVar6 = *(short **)(CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc)
            ;
            iVar14 = 0xfa9;
            if ((psVar6 != (short *)0x0) && (local_2b4 != (short *)0x0)) {
              uVar18 = *(uint *)(psVar6 + -2);
              iVar14 = 0x13ab;
              if ((uVar18 != 0) && (uVar17 = *(uint *)(local_2b4 + -2), uVar17 != 0)) {
                if (psVar6 == local_2b4) goto LAB_2b6e6c93e86;
                iVar14 = _DAT_2b6e6d43d10;
                if ((uVar17 <= uVar18) && (uVar25 = (uVar18 - uVar17) + 1, uVar25 != 0)) {
                  sVar5 = *local_2b4;
                  uVar32 = (ulonglong)uVar25;
                  if (uVar17 < 2) {
                    if (*psVar6 == sVar5) {
LAB_2b6e6c93e86:
                      if (_DAT_2b6e6cab6b8 == 0) {
                        _DAT_2b6e6d43d10 = 0x13ab;
                      }
                      else {
                        iVar14 = 0;
                        if (psVar6 == (short *)0x2b6e6cab6bc) goto LAB_2b6e6c93f6d;
                        if ((_DAT_2b6e6cab6b8 <= uVar18) &&
                           (uVar18 = (uVar18 - _DAT_2b6e6cab6b8) + 1, uVar18 != 0)) {
                          uVar32 = (ulonglong)uVar18;
                          if (_DAT_2b6e6cab6b8 != 1) {
                            bVar43 = true;
                            uVar26 = 1;
                            uVar41 = 0;
                            goto LAB_2b6e6c93f27;
                          }
                          if (*psVar6 == 0x22) goto LAB_2b6e6c93f6d;
                          uVar41 = 0;
                          goto LAB_2b6e6c93ed8;
                        }
                      }
                      break;
                    }
                    uVar26 = 0;
                    do {
                      if (uVar32 - 1 == uVar26) goto LAB_2b6e6c93a6d;
                      lVar19 = uVar26 + 1;
                      uVar26 = uVar26 + 1;
                    } while (psVar6[lVar19] != sVar5);
                    if (uVar26 < uVar32) {
LAB_2b6e6c93e7c:
                      if ((int)uVar26 != -1) goto LAB_2b6e6c93e86;
                    }
                  }
                  else {
                    bVar43 = true;
                    uVar26 = 0;
                    do {
                      if (psVar6[uVar26] == sVar5) {
                        lVar20 = 1;
                        lVar19 = (ulonglong)uVar17 - 1;
                        while (psVar6[(uint)((int)uVar26 + (int)lVar20)] == local_2b4[lVar20]) {
                          lVar20 = lVar20 + 1;
                          lVar19 = lVar19 + -1;
                          if (lVar19 == 0) goto LAB_2b6e6c93e68;
                        }
                        if ((int)lVar19 == 0) {
LAB_2b6e6c93e68:
                          if (bVar43) goto LAB_2b6e6c93e7c;
                          break;
                        }
                      }
                      uVar26 = uVar26 + 1;
                      bVar43 = uVar26 < uVar32;
                    } while (uVar26 != uVar32);
                  }
                }
              }
            }
LAB_2b6e6c93a6d:
            _DAT_2b6e6d43d10 = iVar14;
            uVar32 = (ulonglong)(int)uStack_238;
            uVar41 = uVar41 + 1;
          } while ((longlong)uVar41 < (longlong)uVar32);
        }
        goto LAB_2b6e6c93a30;
      }
LAB_2b6e6c94a8d:
      FUN_2b6e6c91120(&local_298);
      FUN_2b6e6c91120(&local_240);
      FUN_2b6e6c90000(&local_200);
      goto LAB_2b6e6c94d22;
    }
    if (iVar14 != -1) {
LAB_2b6e6c937c6:
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd,3,0x590008,0x2b6e6cab8b8,CONCAT44(uVar44,0x590008),&local_250,
                 0x520004,CONCAT44(uVar51,iVar14));
      (*(code *)0x7ff63a0e17c0)(0x2b6e1db7188,5000);
      goto LAB_2b6e6c94d22;
    }
    if (_DAT_2b6e6d43d10 == 0x1ad) {
      (*(code *)0x7ff63a0e17c0)(0x2b6e1db7188,5000);
      goto LAB_2b6e6c937c6;
    }
    FUN_2b6e6c90d90(&local_2e0,0x2b6e6cab558);
    lVar19 = local_24c;
    if (local_24c != 0) {
      uVar18 = *(uint *)(local_24c + -4);
      uVar36 = (ulonglong)uVar18;
      if ((uVar36 != 0) || (local_2dc == 0)) {
        if (local_2dc == 0) {
          uVar17 = 0;
        }
        else {
          uVar17 = *(uint *)(local_2dc + -4);
        }
        cVar13 = FUN_2b6e6c90060(&local_2e0);
        if (cVar13 == '\0') goto LAB_2b6e6c9624a;
        if (uVar36 != 0) {
          lVar20 = local_2dc + (ulonglong)uVar17 * 2;
          if (uVar18 < 0x10) {
            uVar32 = 0;
          }
          else if ((ulonglong)(lVar20 - lVar19) < 0x20) {
            uVar32 = 0;
          }
          else {
            uVar24 = 0;
            uVar32 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              puVar50 = (undefined4 *)(lVar19 + uVar24);
              uVar44 = puVar50[1];
              uVar45 = puVar50[2];
              uVar51 = puVar50[3];
              puVar49 = (undefined4 *)(lVar20 + uVar24);
              *puVar49 = *puVar50;
              puVar49[1] = uVar44;
              puVar49[2] = uVar45;
              puVar49[3] = uVar51;
              uVar24 = uVar24 + 0x10;
            } while ((uVar36 * 2 & 0xfffffffffffffff0) != uVar24);
            if (uVar32 == uVar36) goto LAB_2b6e6c94bc0;
          }
          do {
            *(undefined2 *)(lVar20 + uVar32 * 2) = *(undefined2 *)(lVar19 + uVar32 * 2);
            uVar32 = uVar32 + 1;
          } while (uVar36 != uVar32);
        }
LAB_2b6e6c94bc0:
        *(uint *)(local_2dc + -4) = uVar18 + uVar17;
        *(undefined2 *)(local_2dc + (ulonglong)(uVar18 + uVar17) * 2) = 0;
      }
    }
    uVar18 = 0;
    FUN_2b6e6c90d90(&local_2b8,&local_2e0,0,0x2b6e6d42468);
    uVar17 = _DAT_2b6e6cab578;
    uVar36 = (ulonglong)_DAT_2b6e6cab578;
    if ((uVar36 == 0) && (local_2b4 != (short *)0x0)) {
LAB_2b6e6c94cf4:
      (*(code *)0x7ff63a0e16a0)(0x2b6e1db7188,&local_2b8,0x2b6e6cab5f8,0x40);
      goto LAB_2b6e6c94d22;
    }
    if (local_2b4 != (short *)0x0) {
      uVar18 = *(uint *)(local_2b4 + -2);
    }
    uVar29 = _DAT_2b6e6cab578 + uVar18;
    uVar25 = 0x104;
    if ((0x103 < uVar29) &&
       ((0x3fffffe7 < uVar29 || (uVar25 = (uVar29 >> 2) + uVar29, 0x3fffffe7 < uVar25)))) {
      uVar25 = 0x3fffffe8;
    }
    cVar13 = FUN_2b6e6c90060(&local_2b8,uVar25);
    if (cVar13 != '\0') {
      if (uVar36 != 0) {
        if (uVar17 < 0x10) {
          uVar32 = 0;
        }
        else if (local_2b4 + ((ulonglong)uVar18 - 0x15b73655abe) < (short *)0x20) {
          uVar32 = 0;
        }
        else {
          uVar24 = 0;
          uVar32 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar44 = *(undefined4 *)(uVar24 + 0x2b6e6cab580);
            uVar45 = *(undefined4 *)(uVar24 + 0x2b6e6cab584);
            uVar51 = *(undefined4 *)(uVar24 + 0x2b6e6cab588);
            puVar50 = (undefined4 *)((longlong)local_2b4 + uVar24 + (ulonglong)uVar18 * 2);
            *puVar50 = *(undefined4 *)(&DAT_2b6e6cab57c + uVar24);
            puVar50[1] = uVar44;
            puVar50[2] = uVar45;
            puVar50[3] = uVar51;
            uVar24 = uVar24 + 0x10;
          } while ((uVar36 * 2 & 0xfffffffffffffff0) != uVar24);
          if (uVar32 == uVar36) goto LAB_2b6e6c94ce9;
        }
        do {
          local_2b4[uVar18 + uVar32] = *(short *)(&DAT_2b6e6cab57c + uVar32 * 2);
          uVar32 = uVar32 + 1;
        } while (uVar36 != uVar32);
      }
LAB_2b6e6c94ce9:
      *(uint *)(local_2b4 + -2) = uVar29;
      local_2b4[uVar29] = 0;
      goto LAB_2b6e6c94cf4;
    }
  }
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x4c001a000b01f9);
LAB_2b6e6c9624a:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x46001a000b01f9);
LAB_2b6e6c9626a:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x410055000b01f6);
LAB_2b6e6c9628a:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x300059000b01f6);
LAB_2b6e6c962aa:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x3f0061000b01f6);
LAB_2b6e6c962ca:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x35005d000b01f6);
LAB_2b6e6c962ea:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x400066000b01f6);
LAB_2b6e6c9630a:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x48006b000b01f6);
LAB_2b6e6c9632a:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x46006d000b01f6);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
LAB_2b6e6c93f27:
  do {
    iVar14 = (int)uVar26;
    if (psVar6[uVar41] == 0x22) {
      psVar30 = (short *)&DAT_2b6e6cab6be;
      lVar19 = (ulonglong)_DAT_2b6e6cab6b8 - 1;
      while (psVar6[uVar26] == *psVar30) {
        psVar30 = psVar30 + 1;
        uVar26 = (ulonglong)((int)uVar26 + 1);
        lVar19 = lVar19 + -1;
        if (lVar19 == 0) goto LAB_2b6e6c93f59;
      }
      if ((int)lVar19 == 0) {
LAB_2b6e6c93f59:
        if (bVar43) goto LAB_2b6e6c93f63;
        break;
      }
    }
    uVar41 = uVar41 + 1;
    uVar26 = (ulonglong)(iVar14 + 1);
    bVar43 = uVar41 < uVar32;
  } while (uVar41 != uVar32);
  goto LAB_2b6e6c93a30;
  while (lVar19 = uVar41 + 1, uVar41 = uVar41 + 1, psVar6[lVar19] != 0x22) {
LAB_2b6e6c93ed8:
    if (uVar32 - 1 == uVar41) goto LAB_2b6e6c93a30;
  }
  if (uVar32 <= uVar41) goto LAB_2b6e6c93a30;
LAB_2b6e6c93f63:
  iVar14 = (int)uVar41;
  if (iVar14 == -1) goto LAB_2b6e6c93a30;
LAB_2b6e6c93f6d:
  uVar18 = iVar14 + 8;
  iVar14 = FUN_2b6e6c906c0(psVar6,&DAT_2b6e6cab698);
  if (iVar14 == -1) goto LAB_2b6e6c93a30;
  local_2a8 = 0;
  local_2a4 = 0;
  if (uStack_290 <= uVar36) goto LAB_2b6e6c9610a;
  uVar32 = uStack_290 + uVar24;
  if ((bStack_296 & 0x10) == 0) {
    uVar32 = uVar36;
  }
  lVar19 = *(longlong *)(CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc);
  iVar15 = 0xfa9;
  if ((lVar19 == 0) || (lVar19 == 0xc)) {
LAB_2b6e6c94059:
    _DAT_2b6e6d43d10 = iVar15;
    if ((_DAT_2b6e6d43d40 == (undefined2 *)0x0) || (_DAT_2b6e6d43d40 == (undefined2 *)0xc)) {
      _DAT_2b6e6d43d10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2b6e6d43d40 + -2) != 0) &&
            (cVar13 = FUN_2b6e6c90060(0x2b6e6d43d3c,0), puVar12 = _DAT_2b6e6d43d40, cVar13 != '\0'))
    {
      *(undefined4 *)(_DAT_2b6e6d43d40 + -2) = 0;
      *puVar12 = 0;
    }
  }
  else {
    uVar17 = *(uint *)(lVar19 + -4);
    uVar25 = uVar18;
    if (((int)uVar18 < 0) && (uVar25 = uVar17 + uVar18, (int)uVar25 < 0)) {
      iVar15 = 0x13ab;
      goto LAB_2b6e6c94059;
    }
    iVar31 = uVar17 - uVar25;
    iVar15 = 0x13ab;
    if (uVar17 < uVar25 || iVar31 == 0) goto LAB_2b6e6c94059;
    iVar14 = iVar14 - uVar18;
    iVar16 = iVar31;
    if ((-1 < iVar14) && (iVar16 = iVar14, iVar31 < iVar14)) {
      _DAT_2b6e6d43d10 = 0x13ab;
      iVar16 = iVar31;
    }
    iVar15 = _DAT_2b6e6d43d10;
    if (iVar16 == 0) goto LAB_2b6e6c94059;
    FUN_2b6e6c901e0(0x2b6e6d43d3c,lVar19 + (ulonglong)uVar25 * 2,iVar16);
  }
  FUN_2b6e6c90d90(&local_2e0,0x2b6e6d43d3c,1,0x2b6e6d424b8);
  FUN_2b6e6c90d90(&local_2a8,&local_2e0,0,0x2b6e6d424c8);
  FUN_2b6e6c907f0(&local_2a8,0x2b6e6cab6da,0x2b6e6cab6ea);
  lVar20 = (*(code *)0x7ff63a0fd370)(0x2b6e1db7188,&local_2a8);
  lVar19 = lVar20 + 0xa8c;
  if (DAT_2b6e6d43c4d == '\0') {
    lVar19 = lVar20;
  }
  lVar38 = lVar20 + -0xa8c;
  if (DAT_2b6e6d43c4c == '\0') {
    lVar38 = lVar20;
  }
  if (((longlong)local_2c0 <= lVar20 && lVar38 <= (longlong)local_2c0) ||
     (iVar14 = _DAT_2b6e6d43d10, lVar20 <= (longlong)local_2c0 && (longlong)local_2c0 <= lVar19)) {
    if (uStack_290 <= uVar36) goto LAB_2b6e6c9620a;
    uVar32 = uStack_290 + uVar24;
    if ((bStack_296 & 0x10) == 0) {
      uVar32 = uVar36;
    }
    psVar6 = *(short **)(CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc);
    if (psVar6 == (short *)0x0) {
      iVar14 = 0xfa9;
    }
    else {
      uVar18 = *(uint *)(psVar6 + -2);
      iVar14 = 0x13ab;
      if ((uVar18 != 0) && (_DAT_2b6e6cab708 != 0)) {
        iVar15 = 0;
        if (psVar6 == (short *)0x2b6e6cab70c) goto LAB_2b6e6c942cb;
        iVar14 = _DAT_2b6e6d43d10;
        if ((_DAT_2b6e6cab708 <= uVar18) && (uVar18 = (uVar18 - _DAT_2b6e6cab708) + 1, uVar18 != 0))
        {
          uVar32 = (ulonglong)uVar18;
          if (_DAT_2b6e6cab708 < 2) {
            if (*psVar6 == 0x22) {
LAB_2b6e6c942cb:
              uVar18 = iVar15 + 9;
              iVar15 = FUN_2b6e6c906c0(psVar6,&DAT_2b6e6cab698);
              iVar14 = _DAT_2b6e6d43d10;
              if (iVar15 != -1) {
                local_260 = 0;
                local_25c = 0;
                if (uStack_290 <= uVar36) goto LAB_2b6e6c9626a;
                uVar32 = uStack_290 + uVar24;
                if ((bStack_296 & 0x10) == 0) {
                  uVar32 = uVar36;
                }
                lVar19 = *(longlong *)
                          (CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc);
                iVar14 = 0xfa9;
                if ((lVar19 == 0) || (lVar19 == 0xc)) {
LAB_2b6e6c943c1:
                  _DAT_2b6e6d43d10 = iVar14;
                  if ((_DAT_2b6e6d43d40 == (undefined2 *)0x0) ||
                     (_DAT_2b6e6d43d40 == (undefined2 *)0xc)) {
                    _DAT_2b6e6d43d10 = 0xfa9;
                  }
                  else if ((*(int *)(_DAT_2b6e6d43d40 + -2) != 0) &&
                          (cVar13 = FUN_2b6e6c90060(0x2b6e6d43d3c,0), puVar12 = _DAT_2b6e6d43d40,
                          cVar13 != '\0')) {
                    *(undefined4 *)(_DAT_2b6e6d43d40 + -2) = 0;
                    *puVar12 = 0;
                  }
                }
                else {
                  uVar17 = *(uint *)(lVar19 + -4);
                  uVar25 = uVar18;
                  if (((int)uVar18 < 0) && (uVar25 = uVar17 + uVar18, (int)uVar25 < 0)) {
                    iVar14 = 0x13ab;
                    goto LAB_2b6e6c943c1;
                  }
                  iVar31 = uVar17 - uVar25;
                  iVar14 = 0x13ab;
                  if (uVar17 < uVar25 || iVar31 == 0) goto LAB_2b6e6c943c1;
                  iVar15 = iVar15 - uVar18;
                  iVar16 = iVar31;
                  if ((-1 < iVar15) && (iVar16 = iVar15, iVar31 < iVar15)) {
                    _DAT_2b6e6d43d10 = 0x13ab;
                    iVar16 = iVar31;
                  }
                  iVar14 = _DAT_2b6e6d43d10;
                  if (iVar16 == 0) goto LAB_2b6e6c943c1;
                  FUN_2b6e6c901e0(0x2b6e6d43d3c,lVar19 + (ulonglong)uVar25 * 2,iVar16);
                }
                FUN_2b6e6c90d90(&local_2e0,0x2b6e6d43d3c,1,0x2b6e6d424d8);
                FUN_2b6e6c90d90(&local_260,&local_2e0,0,0x2b6e6d424e8);
                local_2d0 = 0;
                local_2cc = 0;
                FUN_2b6e6c90d90(&local_2d0,0x2b6e6ca8e50,0);
                if (uStack_290 <= uVar36) goto LAB_2b6e6c9628a;
                uVar32 = uStack_290 + uVar24;
                if ((bStack_296 & 0x10) == 0) {
                  uVar32 = uVar36;
                }
                psVar6 = *(short **)
                          (CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc);
                if (psVar6 == (short *)0x0) {
                  iVar14 = 0xfa9;
LAB_2b6e6c9453e:
                  _DAT_2b6e6d43d10 = iVar14;
                  iVar14 = FUN_2b6e6c906c0(psVar6,0x2b6e6cab78c,0);
                  if (iVar14 != -1) {
                    uVar23 = 0x2b6e6cab7d0;
                    uVar35 = 0x2b6e6d42518;
                    goto LAB_2b6e6c946c6;
                  }
                  if (uStack_290 <= uVar36) goto LAB_2b6e6c962ca;
                  uVar32 = uStack_290 + uVar24;
                  if ((bStack_296 & 0x10) == 0) {
                    uVar32 = uVar36;
                  }
                  iVar14 = FUN_2b6e6c906c0(*(undefined8 *)
                                            (CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 +
                                            uVar32 * 0xc),0x2b6e6cab7ec,0);
                  if (iVar14 != -1) {
                    uVar23 = 0x2b6e6cab828;
                    uVar35 = 0x2b6e6d42528;
                    goto LAB_2b6e6c946c6;
                  }
                }
                else {
                  uVar18 = *(uint *)(psVar6 + -2);
                  iVar14 = 0x13ab;
                  if ((uVar18 == 0) || (_DAT_2b6e6cab728 == 0)) goto LAB_2b6e6c9453e;
                  if (psVar6 == (short *)0x2b6e6cab72c) goto LAB_2b6e6c946ac;
                  iVar14 = _DAT_2b6e6d43d10;
                  if ((uVar18 < _DAT_2b6e6cab728) ||
                     (uVar18 = (uVar18 - _DAT_2b6e6cab728) + 1, uVar18 == 0)) goto LAB_2b6e6c9453e;
                  uVar32 = (ulonglong)uVar18;
                  if (1 < _DAT_2b6e6cab728) {
                    bVar43 = true;
                    uVar26 = 1;
                    uVar41 = 0;
                    do {
                      iVar15 = (int)uVar26;
                      if (psVar6[uVar41] == 0x22) {
                        psVar30 = (short *)&DAT_2b6e6cab72e;
                        lVar19 = (ulonglong)_DAT_2b6e6cab728 - 1;
                        while (psVar6[uVar26] == *psVar30) {
                          psVar30 = psVar30 + 1;
                          uVar26 = (ulonglong)((int)uVar26 + 1);
                          lVar19 = lVar19 + -1;
                          if (lVar19 == 0) goto LAB_2b6e6c9468a;
                        }
                        if ((int)lVar19 == 0) {
LAB_2b6e6c9468a:
                          if (bVar43) goto LAB_2b6e6c946a3;
                          break;
                        }
                      }
                      uVar41 = uVar41 + 1;
                      uVar26 = (ulonglong)(iVar15 + 1);
                      bVar43 = uVar41 < uVar32;
                    } while (uVar41 != uVar32);
                    goto LAB_2b6e6c9453e;
                  }
                  if (*psVar6 != 0x22) {
                    uVar41 = 0;
                    do {
                      if (uVar32 - 1 == uVar41) goto LAB_2b6e6c9453e;
                      lVar19 = uVar41 + 1;
                      uVar41 = uVar41 + 1;
                    } while (psVar6[lVar19] != 0x22);
                    if (uVar41 < uVar32) {
LAB_2b6e6c946a3:
                      if ((int)uVar41 != -1) goto LAB_2b6e6c946ac;
                    }
                    goto LAB_2b6e6c9453e;
                  }
LAB_2b6e6c946ac:
                  uVar23 = 0x2b6e6cab768;
                  uVar35 = 0x2b6e6d42508;
LAB_2b6e6c946c6:
                  FUN_2b6e6c90d90(&local_2d0,uVar23,0,uVar35);
                }
                if (uStack_290 <= uVar36) goto LAB_2b6e6c962aa;
                uVar32 = uStack_290 + uVar24;
                if ((bStack_296 & 0x10) == 0) {
                  uVar32 = uVar36;
                }
                psVar6 = *(short **)
                          (CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 + uVar32 * 0xc);
                if (psVar6 == (short *)0x0) {
                  iVar14 = 0xfa9;
                }
                else {
                  uVar18 = *(uint *)(psVar6 + -2);
                  iVar14 = 0x13ab;
                  if ((uVar18 != 0) && (_DAT_2b6e6cab848 != 0)) {
                    iVar15 = 0;
                    if (psVar6 == (short *)0x2b6e6cab84c) goto LAB_2b6e6c94846;
                    iVar14 = _DAT_2b6e6d43d10;
                    if ((_DAT_2b6e6cab848 <= uVar18) &&
                       (uVar18 = (uVar18 - _DAT_2b6e6cab848) + 1, uVar18 != 0)) {
                      uVar32 = (ulonglong)uVar18;
                      if (_DAT_2b6e6cab848 < 2) {
                        iVar15 = 0;
                        if (*psVar6 == 0x22) {
LAB_2b6e6c94846:
                          iVar31 = FUN_2b6e6c906c0(psVar6,&DAT_2b6e6cab698);
                          iVar14 = _DAT_2b6e6d43d10;
                          if (iVar31 != -1) {
                            local_1e8 = 0;
                            local_1e4 = 0;
                            if (uStack_290 <= uVar36) goto LAB_2b6e6c962ea;
                            uVar32 = uStack_290 + uVar24;
                            if ((bStack_296 & 0x10) == 0) {
                              uVar32 = uVar36;
                            }
                            FUN_2b6e6c91030(*(undefined8 *)
                                             (CONCAT44(local_27c._4_4_,(undefined4)local_27c) + 4 +
                                             uVar32 * 0xc),iVar15 + 0xb,iVar31 - (iVar15 + 0xb));
                            FUN_2b6e6c90d90(&local_2e0,0x2b6e6d43d3c,1,0x2b6e6d42538);
                            FUN_2b6e6c90d90(&local_1e8,&local_2e0,0,0x2b6e6d42548);
                            cVar13 = FUN_2b6e6c90fb0(local_2cc,0x2b6e6cab75c);
                            if (cVar13 != '\0') {
                              (*(code *)0x7ff63a0da0e0)
                                        (0x2b6e1db7188,&DAT_2b6e6d43770,_DAT_2b6e6d43778 + 1,0);
                              uVar32 = (ulonglong)(int)(_DAT_2b6e6d43778 - 1);
                              if (_DAT_2b6e6d43778 <= uVar32) goto LAB_2b6e6c9630a;
                              uVar24 = ~uVar32 + (ulonglong)_DAT_2b6e6d43778;
                              if ((_DAT_2b6e6d43772 & 0x10) == 0) {
                                uVar24 = uVar32;
                              }
                              FUN_2b6e6c90d90(uVar24 * 0xc + _DAT_2b6e6d4378c,&local_260,0,
                                              0x2b6e6d42558);
                              (*(code *)0x7ff63a0da0e0)
                                        (0x2b6e1db7188,&DAT_2b6e6d43830,_DAT_2b6e6d43838 + 1,0);
                              uVar32 = (ulonglong)(int)(_DAT_2b6e6d43838 - 1);
                              if (_DAT_2b6e6d43838 <= uVar32) goto LAB_2b6e6c9632a;
                              uVar24 = ~uVar32 + (ulonglong)_DAT_2b6e6d43838;
                              if ((_DAT_2b6e6d43832 & 0x10) == 0) {
                                uVar24 = uVar32;
                              }
                              FUN_2b6e6c90d90(uVar24 * 0xc + _DAT_2b6e6d4384c,&local_2a8,0,
                                              0x2b6e6d42568);
                            }
                            FUN_2b6e6c90000(&local_1e8);
                            iVar14 = _DAT_2b6e6d43d10;
                          }
                        }
                        else {
                          uVar41 = 0;
                          do {
                            if (uVar32 - 1 == uVar41) goto LAB_2b6e6c9475d;
                            lVar19 = uVar41 + 1;
                            uVar41 = uVar41 + 1;
                          } while (psVar6[lVar19] != 0x22);
                          if (uVar41 < uVar32) {
LAB_2b6e6c9483c:
                            iVar15 = (int)uVar41;
                            if ((int)uVar41 != -1) goto LAB_2b6e6c94846;
                          }
                        }
                      }
                      else {
                        bVar43 = true;
                        uVar26 = 1;
                        uVar41 = 0;
                        do {
                          iVar15 = (int)uVar26;
                          if (psVar6[uVar41] == 0x22) {
                            psVar30 = (short *)&DAT_2b6e6cab84e;
                            lVar19 = (ulonglong)_DAT_2b6e6cab848 - 1;
                            while (psVar6[uVar26] == *psVar30) {
                              psVar30 = psVar30 + 1;
                              uVar26 = (ulonglong)((int)uVar26 + 1);
                              lVar19 = lVar19 + -1;
                              if (lVar19 == 0) goto LAB_2b6e6c94823;
                            }
                            if ((int)lVar19 == 0) {
LAB_2b6e6c94823:
                              if (bVar43) goto LAB_2b6e6c9483c;
                              break;
                            }
                          }
                          uVar41 = uVar41 + 1;
                          uVar26 = (ulonglong)(iVar15 + 1);
                          bVar43 = uVar41 < uVar32;
                        } while (uVar41 != uVar32);
                      }
                    }
                  }
                }
LAB_2b6e6c9475d:
                _DAT_2b6e6d43d10 = iVar14;
                FUN_2b6e6c90000(&local_2d0);
                FUN_2b6e6c90000(&local_260);
                iVar14 = _DAT_2b6e6d43d10;
              }
            }
            else {
              uVar41 = 0;
              do {
                if (uVar32 - 1 == uVar41) goto LAB_2b6e6c94238;
                lVar19 = uVar41 + 1;
                uVar41 = uVar41 + 1;
              } while (psVar6[lVar19] != 0x22);
              if (uVar41 < uVar32) {
LAB_2b6e6c942c1:
                iVar15 = (int)uVar41;
                iVar14 = _DAT_2b6e6d43d10;
                if (iVar15 != -1) goto LAB_2b6e6c942cb;
              }
            }
          }
          else {
            bVar43 = true;
            uVar26 = 1;
            uVar41 = 0;
            do {
              iVar14 = (int)uVar26;
              if (psVar6[uVar41] == 0x22) {
                psVar30 = (short *)&DAT_2b6e6cab70e;
                lVar19 = (ulonglong)_DAT_2b6e6cab708 - 1;
                while (psVar6[uVar26] == *psVar30) {
                  psVar30 = psVar30 + 1;
                  uVar26 = (ulonglong)((int)uVar26 + 1);
                  lVar19 = lVar19 + -1;
                  if (lVar19 == 0) goto LAB_2b6e6c942b7;
                }
                if ((int)lVar19 == 0) {
LAB_2b6e6c942b7:
                  iVar14 = _DAT_2b6e6d43d10;
                  if (bVar43) goto LAB_2b6e6c942c1;
                  break;
                }
              }
              uVar41 = uVar41 + 1;
              uVar26 = (ulonglong)(iVar14 + 1);
              bVar43 = uVar41 < uVar32;
              iVar14 = _DAT_2b6e6d43d10;
            } while (uVar41 != uVar32);
          }
        }
      }
    }
  }
LAB_2b6e6c94238:
  _DAT_2b6e6d43d10 = iVar14;
  FUN_2b6e6c90000(&local_2a8);
LAB_2b6e6c93a30:
  uVar36 = uVar36 + 1;
  if ((longlong)(int)uStack_290 <= (longlong)uVar36) goto LAB_2b6e6c94a8d;
  goto LAB_2b6e6c93a44;
}



/* Address: 2b6e6c96350 */

bool FUN_2b6e6c96350(int param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  int local_40;
  int local_3c;
  int local_38;
  
  uVar1 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  (*(code *)0x7ff63a101f60)(0x2b6e1db7188,uVar1,&local_40);
  return param_3 == local_38 && (param_2 == local_3c && param_1 == local_40);
}



/* Address: 2b6e6c963b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c963b0(void)

{
  short sVar1;
  double dVar2;
  undefined2 *puVar3;
  double dVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  undefined4 local_130;
  short *local_12c;
  undefined4 local_120;
  undefined8 local_11c;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined1 local_f8 [12];
  undefined4 local_ec;
  undefined8 local_e8;
  undefined1 local_d8 [12];
  undefined4 local_cc;
  undefined8 local_c8;
  undefined1 local_b8 [24];
  uint local_a0;
  undefined1 local_98 [88];
  
  local_120 = 0;
  local_130 = 0;
  local_11c = 0;
  local_12c = (short *)0x0;
  uVar10 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  (*(code *)0x7ff63a101f60)(0x2b6e1db7188,uVar10,local_b8);
  (*(code *)0x7ff63a101c40)(0x2b6e1db7188,local_f8);
  uVar7 = 1;
  if (local_a0 < 7) {
    uVar7 = local_a0;
  }
  (*(code *)0x7ff63a0f2cb0)(0x2b6e1db7188,0x2b6e6ca8e30,uVar7,0,&local_100,&local_108);
  (*(code *)0x7ff63a101f60)(0x2b6e1db7188,local_100,local_d8);
  (*(code *)0x7ff63a101f60)(0x2b6e1db7188,local_108,local_98);
  local_ec = local_cc;
  local_e8 = local_c8;
  iVar6 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
  if (0 < iVar6) goto LAB_2b6e6c96b9a;
  lVar11 = (*(code *)0x7ff63a102140)(0x2b6e1db7188,local_f8);
  lVar12 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  if ((lVar12 + -4000 < lVar11) ||
     (lVar11 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0),
     (double)lVar11 < (double)_DAT_2b6e6d43a98 + _DAT_2b6e6d43a90 * _DAT_2b6e6ca8730))
  goto LAB_2b6e6c96b9a;
  local_130 = 0;
  local_12c = (short *)0x0;
  _DAT_2b6e6d43a98 = lVar11;
  uVar10 = (*(code *)0x7ff63a103b50)(0x2b6e1db7188,0x2b6e6ca8e30,0x4018,0);
  (*(code *)0x7ff63a0fcc50)(0x2b6e1db7188,uVar10,3);
  FUN_2b6e6c90d90(&local_120,0x2b6e6d43d3c,1,0x2b6e6d426b8);
  FUN_2b6e6c90d90(&local_130,&local_120,0,0x2b6e6d426c8);
  FUN_2b6e6c907f0(&local_130,0x2b6e6cab6ea);
  if (local_12c == (short *)0x0) {
    _DAT_2b6e6d43d10 = 0xfa9;
LAB_2b6e6c9669e:
    uVar13 = 0xffffffff;
  }
  else {
    if ((_DAT_2b6e6cabd48 == 0) || (uVar7 = *(uint *)(local_12c + -2), uVar7 == 0)) {
      _DAT_2b6e6d43d10 = 0x13ab;
      goto LAB_2b6e6c9669e;
    }
    uVar13 = 0;
    if (local_12c == (short *)&DAT_2b6e6cabd4c) goto LAB_2b6e6c966a4;
    if ((_DAT_2b6e6cabd48 < uVar7) || (uVar14 = (_DAT_2b6e6cabd48 - uVar7) + 1, uVar14 == 0))
    goto LAB_2b6e6c9669e;
    sVar1 = *local_12c;
    uVar15 = (ulonglong)uVar14;
    if (1 < uVar7) {
      bVar18 = true;
      uVar13 = 0;
      do {
        if (*(short *)(&DAT_2b6e6cabd4c + uVar13 * 2) == sVar1) {
          lVar12 = 1;
          lVar11 = (ulonglong)uVar7 - 1;
          while (*(short *)(&DAT_2b6e6cabd4c + (ulonglong)(uint)((int)uVar13 + (int)lVar12) * 2) ==
                 local_12c[lVar12]) {
            lVar12 = lVar12 + 1;
            lVar11 = lVar11 + -1;
            if (lVar11 == 0) goto LAB_2b6e6c96c49;
          }
          if ((int)lVar11 == 0) {
LAB_2b6e6c96c49:
            if (bVar18) goto LAB_2b6e6c966a4;
            break;
          }
        }
        uVar13 = uVar13 + 1;
        bVar18 = uVar13 < uVar15;
      } while (uVar13 != uVar15);
      goto LAB_2b6e6c9669e;
    }
    if (sVar1 != 0x32) {
      uVar13 = 0;
      do {
        if (uVar15 - 1 == uVar13) goto LAB_2b6e6c9669e;
        lVar11 = uVar13 * 2;
        uVar13 = uVar13 + 1;
      } while (*(short *)(&DAT_2b6e6cabd4e + lVar11) != sVar1);
      if (uVar15 <= uVar13) goto LAB_2b6e6c9669e;
    }
  }
LAB_2b6e6c966a4:
  iVar6 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,uVar13);
  uVar7 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,iVar6 + 1);
  uVar14 = uVar7 + 1;
  iVar6 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,uVar14);
  iVar8 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,iVar6 + 1);
  local_110 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,iVar8 + 1);
  uVar16 = (int)local_110 + 1;
  iVar8 = FUN_2b6e6c906c0(&DAT_2b6e6cabd4c,0x2b6e6cab970,uVar16);
  if ((((int)uVar14 < 0) && (uVar14 = uVar14 + _DAT_2b6e6cabd48, (int)uVar14 < 0)) ||
     (iVar9 = _DAT_2b6e6cabd48 - uVar14, _DAT_2b6e6cabd48 < uVar14 || iVar9 == 0)) {
    _DAT_2b6e6d43d10 = 0x13ab;
LAB_2b6e6c967e5:
    if ((_DAT_2b6e6d43d40 == (undefined2 *)0x0) || (_DAT_2b6e6d43d40 == (undefined2 *)0xc)) {
      _DAT_2b6e6d43d10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2b6e6d43d40 + -2) != 0) &&
            (cVar5 = FUN_2b6e6c90060(0x2b6e6d43d3c,0), puVar3 = _DAT_2b6e6d43d40, cVar5 != '\0')) {
      *(undefined4 *)(_DAT_2b6e6d43d40 + -2) = 0;
      *puVar3 = 0;
    }
  }
  else {
    iVar6 = iVar6 + ~uVar7;
    iVar17 = iVar9;
    if ((-1 < iVar6) && (iVar17 = iVar6, iVar9 < iVar6)) {
      _DAT_2b6e6d43d10 = 0x13ab;
      iVar17 = iVar9;
    }
    if (iVar17 == 0) goto LAB_2b6e6c967e5;
    FUN_2b6e6c901e0(0x2b6e6d43d3c,&DAT_2b6e6cabd4c + (ulonglong)uVar14 * 2,iVar17);
  }
  FUN_2b6e6c90d90(&local_120,0x2b6e6d43d3c,1,0x2b6e6d426d8);
  (*(code *)0x7ff63a0fe4a0)(0x2b6e1db7188,&local_120);
  if ((((int)uVar16 < 0) && (uVar16 = uVar16 + _DAT_2b6e6cabd48, (int)uVar16 < 0)) ||
     (iVar6 = _DAT_2b6e6cabd48 - uVar16, _DAT_2b6e6cabd48 < uVar16 || iVar6 == 0)) {
    _DAT_2b6e6d43d10 = 0x13ab;
LAB_2b6e6c968f7:
    if ((_DAT_2b6e6d43d40 == (undefined2 *)0x0) || (_DAT_2b6e6d43d40 == (undefined2 *)0xc)) {
      _DAT_2b6e6d43d10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2b6e6d43d40 + -2) != 0) &&
            (cVar5 = FUN_2b6e6c90060(0x2b6e6d43d3c,0), puVar3 = _DAT_2b6e6d43d40, cVar5 != '\0')) {
      *(undefined4 *)(_DAT_2b6e6d43d40 + -2) = 0;
      *puVar3 = 0;
    }
  }
  else {
    iVar8 = iVar8 + ~(uint)local_110;
    iVar9 = iVar6;
    if ((-1 < iVar8) && (iVar9 = iVar8, iVar6 < iVar8)) {
      _DAT_2b6e6d43d10 = 0x13ab;
      iVar9 = iVar6;
    }
    if (iVar9 == 0) goto LAB_2b6e6c968f7;
    FUN_2b6e6c901e0(0x2b6e6d43d3c,&DAT_2b6e6cabd4c + (ulonglong)uVar16 * 2,iVar9);
  }
  FUN_2b6e6c90d90(&local_120,0x2b6e6d43d3c,1,0x2b6e6d426e8);
  (*(code *)0x7ff63a0fe4a0)(0x2b6e1db7188,&local_120);
  dVar4 = _DAT_2b6e6d43d48;
  uVar7 = _DAT_2b6e6d43d20;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,4);
  uVar14 = _DAT_2b6e6d43d20;
  dVar20 = _DAT_2b6e6d43d48;
  if ((longlong)_DAT_2b6e6d43d48 != -0x8000000000000000) {
    dVar20 = (double)(longlong)_DAT_2b6e6d43d48;
    uVar13 = 0xb;
    if (uVar7 < 0xb) {
      uVar13 = (ulonglong)uVar7;
    }
    dVar20 = (double)(longlong)
                     ((_DAT_2b6e6d43d48 - dVar20) * *(double *)(&DAT_2b6e6ca8ca0 + uVar13 * 8) +
                     *(double *)((ulonglong)(0.0 < _DAT_2b6e6d43d48) * 8 + 0x2b6e6ca8738)) /
             *(double *)(&DAT_2b6e6ca8ca0 + uVar13 * 8) + dVar20;
  }
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
  dVar21 = _DAT_2b6e6d43d48;
  if ((longlong)_DAT_2b6e6d43d48 != -0x8000000000000000) {
    dVar21 = (double)(longlong)_DAT_2b6e6d43d48;
    uVar13 = 0xb;
    if (uVar14 < 0xb) {
      uVar13 = (ulonglong)uVar14;
    }
    dVar21 = (double)(longlong)
                     ((_DAT_2b6e6d43d48 - dVar21) * *(double *)(&DAT_2b6e6ca8ca0 + uVar13 * 8) +
                     *(double *)((ulonglong)(0.0 < _DAT_2b6e6d43d48) * 8 + 0x2b6e6ca8738)) /
             *(double *)(&DAT_2b6e6ca8ca0 + uVar13 * 8) + dVar21;
  }
  dVar2 = _DAT_2b6e6ca8758;
  if (_DAT_2b6e6d43d20 != 3) {
    dVar2 = *(double *)((ulonglong)(_DAT_2b6e6d43d20 == 1) * 8 + 0x2b6e6ca8748);
  }
  dVar19 = _DAT_2b6e6ca8760;
  if (DAT_2b6e6d43a88 == '\0') {
    dVar19 = 0.0;
  }
  if ((dVar20 + dVar2 * dVar19 * _DAT_2b6e6d43d18 < dVar4) &&
     (FUN_2b6e6ca4cf0(1), dVar19 = _DAT_2b6e6ca8760, DAT_2b6e6d43a88 == '\0')) {
    dVar19 = 0.0;
  }
  dVar20 = _DAT_2b6e6ca8758;
  if (_DAT_2b6e6d43d20 != 3) {
    dVar20 = *(double *)((ulonglong)(_DAT_2b6e6d43d20 == 1) * 8 + 0x2b6e6ca8748);
  }
  if (dVar4 < dVar21 - _DAT_2b6e6d43d18 * dVar19 * dVar20) {
    FUN_2b6e6ca4cf0(2);
  }
  FUN_2b6e6c90000(&local_130);
LAB_2b6e6c96b9a:
  FUN_2b6e6c90000(&local_120);
  return;
}



/* Address: 2b6e6c96cf0 */

void thunk_FUN_2b6e6c96d00(void)

{
  FUN_2b6e6c96d00();
  return;
}



/* Address: 2b6e6c96d00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c96d00(void)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  short *psVar6;
  uint uVar7;
  longlong lVar8;
  bool bVar9;
  undefined4 local_68;
  short *local_64;
  undefined4 local_58;
  undefined8 local_54;
  longlong local_48;
  
  local_58 = 0;
  local_68 = 0;
  local_54 = 0;
  local_64 = (short *)0x0;
  uVar2 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  iVar1 = (*(code *)0x7ff63a0f35d0)(0x2b6e1db7188,uVar2,0,0xffffffff);
  if (-1 < iVar1 + -1) {
    iVar1 = iVar1 + -1;
    do {
      local_68 = 0;
      local_64 = (short *)0x0;
      (*(code *)0x7ff63a0f4c00)(0x2b6e1db7188,uVar2,iVar1,0xffffffff,0xffffffff);
      FUN_2b6e6c90d90(&local_58,0x2b6e6d43d3c,1,0x2b6e6d41740);
      FUN_2b6e6c90d90(&local_68,&local_58,0,0x2b6e6d41750);
      if (local_64 == (short *)0x0) {
        _DAT_2b6e6d43d10 = 0xfa9;
      }
      else {
        uVar3 = *(uint *)(local_64 + -2);
        if ((uVar3 == 0) || (_DAT_2b6e6caa7e8 == 0)) {
          _DAT_2b6e6d43d10 = 0x13ab;
        }
        else {
          if (local_64 == (short *)0x2b6e6caa7ec) goto LAB_2b6e6c96f76;
          if ((_DAT_2b6e6caa7e8 <= uVar3) && (uVar3 = (uVar3 - _DAT_2b6e6caa7e8) + 1, uVar3 != 0)) {
            uVar4 = (ulonglong)uVar3;
            if (_DAT_2b6e6caa7e8 < 2) {
              if (*local_64 == 0x42) {
LAB_2b6e6c96f76:
                (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,uVar2,&local_68);
              }
              else {
                uVar5 = 0;
                do {
                  if (uVar4 - 1 == uVar5) goto LAB_2b6e6c96dc0;
                  lVar8 = uVar5 + 1;
                  uVar5 = uVar5 + 1;
                } while (local_64[lVar8] != 0x42);
                if (uVar5 < uVar4) {
LAB_2b6e6c96f6e:
                  if ((int)uVar5 == 0) goto LAB_2b6e6c96f76;
                }
              }
            }
            else {
              bVar9 = true;
              uVar5 = 0;
              local_48 = (ulonglong)_DAT_2b6e6caa7e8 - 1;
              uVar3 = 1;
              do {
                if (local_64[uVar5] == 0x42) {
                  psVar6 = (short *)&DAT_2b6e6caa7ee;
                  lVar8 = local_48;
                  uVar7 = uVar3;
                  while (local_64[uVar7] == *psVar6) {
                    psVar6 = psVar6 + 1;
                    uVar7 = uVar7 + 1;
                    lVar8 = lVar8 + -1;
                    if (lVar8 == 0) goto LAB_2b6e6c96f5a;
                  }
                  if ((int)lVar8 == 0) {
LAB_2b6e6c96f5a:
                    if (bVar9) goto LAB_2b6e6c96f6e;
                    break;
                  }
                }
                uVar5 = uVar5 + 1;
                uVar3 = uVar3 + 1;
                bVar9 = uVar5 < uVar4;
              } while (uVar5 != uVar4);
            }
          }
        }
      }
LAB_2b6e6c96dc0:
      FUN_2b6e6c90000(&local_68);
      bVar9 = 0 < iVar1;
      iVar1 = iVar1 + -1;
    } while (bVar9);
  }
  FUN_2b6e6c90000(&local_58);
  return;
}



/* Address: 2b6e6c96fb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c96fb0(void)

{
  int iVar1;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_64 = 0;
  DAT_2b6e6d43c4f = 1;
  DAT_2b6e6d43c4e = 1;
  DAT_2b6e6d43c50 = 1;
  DAT_2b6e6d43c4d = 1;
  DAT_2b6e6d43c4c = 1;
  _DAT_2b6e6d43c40 = 0;
  _DAT_2b6e6d43c44 = 0;
  FUN_2b6e6c90d90(&DAT_2b6e6d43c40,0x2b6e6ca8f10,0,0x2b6e6d40880);
  _DAT_2b6e6d43c30 = 0;
  _DAT_2b6e6d43c34 = 0;
  FUN_2b6e6c90d90(&DAT_2b6e6d43c30,0x2b6e6ca8ed8,0,0x2b6e6d40890);
  _DAT_2b6e6d43c20 = 0;
  _DAT_2b6e6d43c24 = 0;
  FUN_2b6e6c90d90(&DAT_2b6e6d43c20,0x2b6e6ca8e78,0,0x2b6e6d408a0);
  _DAT_2b6e6d43be0 = 0x800010058;
  _DAT_2b6e6d43be8 = 0;
  _DAT_2b6e6d43bf0 = 0;
  _DAT_2b6e6d43c18 = 0;
  _DAT_2b6e6d43bf8 = 0;
  _DAT_2b6e6d43c00 = 0;
  _DAT_2b6e6d43c08 = 0;
  _DAT_2b6e6d43c10 = 0;
  _DAT_2b6e6d43ba0 = 0x800010058;
  _DAT_2b6e6d43ba8 = 0;
  _DAT_2b6e6d43bb0 = 0;
  _DAT_2b6e6d43bb8 = 0;
  _DAT_2b6e6d43bc0 = 0;
  _DAT_2b6e6d43bc8 = 0;
  _DAT_2b6e6d43bd0 = 0;
  _DAT_2b6e6d43b60 = 0x800010058;
  _DAT_2b6e6d43b90 = 0;
  _DAT_2b6e6d43b88 = 0;
  _DAT_2b6e6d43b80 = 0;
  _DAT_2b6e6d43b78 = 0;
  _DAT_2b6e6d43b70 = 0;
  _DAT_2b6e6d43b68 = 0;
  _DAT_2b6e6d43b20 = 0x800010058;
  _DAT_2b6e6d43b28 = 0;
  _DAT_2b6e6d43b38 = 0;
  _DAT_2b6e6d43b30 = 0;
  _DAT_2b6e6d43b48 = 0;
  _DAT_2b6e6d43b40 = 0;
  _DAT_2b6e6d43ae0 = 0x800010058;
  _DAT_2b6e6d43ae8 = 0;
  _DAT_2b6e6d43b50 = 0;
  _DAT_2b6e6d43af8 = 0;
  _DAT_2b6e6d43af0 = 0;
  _DAT_2b6e6d43b08 = 0;
  _DAT_2b6e6d43b00 = 0;
  DAT_2b6e6d43ac0 = 1;
  _DAT_2b6e6d43b10 = 0;
  _DAT_2b6e6d43ab8 = 0x404e000000000000;
  DAT_2b6e6d43ab5 = 1;
  DAT_2b6e6d43ab4 = 1;
  DAT_2b6e6d43ab3 = 1;
  DAT_2b6e6d43ab2 = 1;
  DAT_2b6e6d43ab1 = 1;
  DAT_2b6e6d43ab0 = 0;
  _DAT_2b6e6d43a90 = 0x402b3851eb851eb8;
  DAT_2b6e6d43a88 = 1;
  _DAT_2b6e6d43a30 = 0xc00010059;
  _DAT_2b6e6d43a60 = 0;
  _DAT_2b6e6d43a58 = 0;
  _DAT_2b6e6d43a50 = 0;
  _DAT_2b6e6d43a48 = 0;
  _DAT_2b6e6d43a40 = 0;
  _DAT_2b6e6d43a38 = 0;
  _DAT_2b6e6d439f0 = 0xc00010059;
  _DAT_2b6e6d43a20 = 0;
  _DAT_2b6e6d43a18 = 0;
  _DAT_2b6e6d43a10 = 0;
  _DAT_2b6e6d43a08 = 0;
  _DAT_2b6e6d43a00 = 0;
  _DAT_2b6e6d439f8 = 0;
  _DAT_2b6e6d439b0 = 0xc00010059;
  _DAT_2b6e6d439e0 = 0;
  _DAT_2b6e6d439d8 = 0;
  _DAT_2b6e6d439d0 = 0;
  _DAT_2b6e6d439c8 = 0;
  _DAT_2b6e6d439c0 = 0;
  _DAT_2b6e6d439b8 = 0;
  _DAT_2b6e6d43970 = 0xc00010059;
  _DAT_2b6e6d439a0 = 0;
  _DAT_2b6e6d43998 = 0;
  _DAT_2b6e6d43990 = 0;
  _DAT_2b6e6d43988 = 0;
  _DAT_2b6e6d43980 = 0;
  _DAT_2b6e6d43978 = 0;
  _DAT_2b6e6d43930 = 0xc00010059;
  _DAT_2b6e6d43960 = 0;
  _DAT_2b6e6d43958 = 0;
  _DAT_2b6e6d43950 = 0;
  _DAT_2b6e6d43948 = 0;
  _DAT_2b6e6d43940 = 0;
  _DAT_2b6e6d43938 = 0;
  _DAT_2b6e6d438f0 = 0xc00010059;
  _DAT_2b6e6d43920 = 0;
  _DAT_2b6e6d43918 = 0;
  _DAT_2b6e6d43910 = 0;
  _DAT_2b6e6d43908 = 0;
  _DAT_2b6e6d43900 = 0;
  _DAT_2b6e6d438f8 = 0;
  _DAT_2b6e6d438b0 = 0xc00010059;
  _DAT_2b6e6d438e0 = 0;
  _DAT_2b6e6d438d8 = 0;
  _DAT_2b6e6d438d0 = 0;
  _DAT_2b6e6d438c8 = 0;
  _DAT_2b6e6d438c0 = 0;
  _DAT_2b6e6d438b8 = 0;
  _DAT_2b6e6d43870 = 0xc00010059;
  _DAT_2b6e6d438a0 = 0;
  _DAT_2b6e6d43898 = 0;
  _DAT_2b6e6d43890 = 0;
  _DAT_2b6e6d43888 = 0;
  _DAT_2b6e6d43880 = 0;
  _DAT_2b6e6d43878 = 0;
  _DAT_2b6e6d43830 = 0xc00010059;
  _DAT_2b6e6d43860 = 0;
  _DAT_2b6e6d43858 = 0;
  _DAT_2b6e6d43850 = 0;
  _DAT_2b6e6d43848 = 0;
  _DAT_2b6e6d43840 = 0;
  _DAT_2b6e6d43838 = 0;
  _DAT_2b6e6d437f0 = 0xc00010059;
  _DAT_2b6e6d43820 = 0;
  _DAT_2b6e6d43818 = 0;
  _DAT_2b6e6d43810 = 0;
  _DAT_2b6e6d43808 = 0;
  _DAT_2b6e6d43800 = 0;
  _DAT_2b6e6d437f8 = 0;
  _DAT_2b6e6d437b0 = 0xc00010059;
  _DAT_2b6e6d437e0 = 0;
  _DAT_2b6e6d437d0 = 0;
  _DAT_2b6e6d437d8 = 0;
  _DAT_2b6e6d437c0 = 0;
  _DAT_2b6e6d437c8 = 0;
  _DAT_2b6e6d43770 = 0xc00010059;
  _DAT_2b6e6d437b8 = 0;
  _DAT_2b6e6d43798 = 0;
  _DAT_2b6e6d437a0 = 0;
  DAT_2b6e6d4331b = 1;
  _DAT_2b6e6d43788 = 0;
  _DAT_2b6e6d43790 = 0;
  DAT_2b6e6d43319 = 1;
  _DAT_2b6e6d43778 = 0;
  _DAT_2b6e6d43780 = 0;
  DAT_2b6e6d43317 = 1;
  DAT_2b6e6d43768 = 1;
  DAT_2b6e6d43769 = 1;
  DAT_2b6e6d43315 = 1;
  _DAT_2b6e6d43758 = 0;
  _DAT_2b6e6d43760 = 0;
  DAT_2b6e6d43313 = 1;
  _DAT_2b6e6d43748 = 0;
  _DAT_2b6e6d43750 = 0;
  DAT_2b6e6d43311 = 1;
  _DAT_2b6e6d43738 = 0;
  _DAT_2b6e6d43740 = 0;
  DAT_2b6e6d4331c = 1;
  _DAT_2b6e6d43730 = 0;
  DAT_2b6e6d4331a = 1;
  _DAT_2b6e6d43320 = 0x3f9eb851eb851eb8;
  DAT_2b6e6d43318 = 1;
  DAT_2b6e6d43316 = 1;
  DAT_2b6e6d43314 = 1;
  DAT_2b6e6d43312 = 1;
  DAT_2b6e6d43310 = 1;
  _DAT_2b6e6d43308 = 0x4044000000000000;
  _DAT_2b6e6d43300 = 0x3fe999999999999a;
  DAT_2b6e6d432ea = 1;
  _DAT_2b6e6d432f8 = 0x3f947ae147ae147b;
  DAT_2b6e6d432e8 = 1;
  DAT_2b6e6d432eb = 1;
  _DAT_2b6e6d432f0 = 0x4034000000000000;
  DAT_2b6e6d432e9 = 1;
  _DAT_2b6e6d432e0 = 0x3fa999999999999a;
  DAT_2b6e6d432d4 = 1;
  _DAT_2b6e6d432d8 = 0x4041800000000000;
  DAT_2b6e6d432d2 = 1;
  DAT_2b6e6d432b9 = 1;
  DAT_2b6e6d432d3 = 1;
  DAT_2b6e6d432d0 = 1;
  DAT_2b6e6d432b7 = 1;
  DAT_2b6e6d432d1 = 1;
  _DAT_2b6e6d432c0 = 0x4039000000000000;
  DAT_2b6e6d432b5 = 1;
  _DAT_2b6e6d432c8 = 0x3f9eb851eb851eb8;
  DAT_2b6e6d432ba = 1;
  DAT_2b6e6d432b3 = 1;
  DAT_2b6e6d432b8 = 1;
  DAT_2b6e6d432b1 = 1;
  DAT_2b6e6d432b6 = 1;
  DAT_2b6e6d432b4 = 1;
  DAT_2b6e6d432b2 = 1;
  (*(code *)0x7ff63a0e4490)(0x2b6e1db7188,0x2b6e1d4be00,&DAT_2b6e6d43000);
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43000,0x2b6e1dd7850);
  _DAT_2b6e6d43008 = 0x2b6e6ca8d30;
  _DAT_2b6e6d43010 = 0;
  uRam000002b6e6d43018 = 0;
  _DAT_2b6e6d43034 = 0;
  _DAT_2b6e6d43038 = 0;
  _DAT_2b6e6d43084 = 0;
  _DAT_2b6e6d43088 = 0;
  _DAT_2b6e6d43144 = 0;
  _DAT_2b6e6d43148 = 0;
  _DAT_2b6e6d43208 = 0;
  _DAT_2b6e6d4320c = 0;
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43000,0x2b6e4d63b50);
  _DAT_2b6e6d43008 = 0x2b6e6ca8d70;
  _DAT_2b6e6d43010 = 0;
  uRam000002b6e6d43018 = 0;
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43000,0x2b6e1d4be00);
  _DAT_2b6e6d43008 = 0x2b6e6ca8db0;
  DAT_2b6e6d43294 = 0;
  _DAT_2b6e6d43295 = 0;
  _DAT_2b6e6d4329d = 10;
  _DAT_2b6e6d432a5 = 0;
  _DAT_2b6e6d432ad = 1;
  _DAT_2b6e6d432a9 = (*(code *)0x7ff63a0c73c0)(0x2b6e1db7188,0x35);
  _DAT_2b6e6d43020 = 0;
  uRam000002b6e6d43028 = 0;
  _DAT_2b6e6d43030 = 0;
  FUN_2b6e6c90000(&DAT_2b6e6d43034);
  _DAT_2b6e6d43050 = 0;
  _DAT_2b6e6d43058 = 0;
  _DAT_2b6e6d43060 = 0;
  _DAT_2b6e6d43068 = 0;
  _DAT_2b6e6d43070 = 0;
  _DAT_2b6e6d43078 = 0;
  _DAT_2b6e6d43080 = 0;
  _DAT_2b6e6d43040 = 0;
  _DAT_2b6e6d43048 = 0;
  FUN_2b6e6c90000(&DAT_2b6e6d43084);
  _DAT_2b6e6d43120 = 0;
  uRam000002b6e6d43128 = 0;
  _DAT_2b6e6d43110 = 0;
  uRam000002b6e6d43118 = 0;
  _DAT_2b6e6d43130 = 0;
  uRam000002b6e6d43138 = 0;
  _DAT_2b6e6d43100 = 0;
  uRam000002b6e6d43108 = 0;
  _DAT_2b6e6d430f0 = 0;
  uRam000002b6e6d430f8 = 0;
  _DAT_2b6e6d430e0 = 0;
  uRam000002b6e6d430e8 = 0;
  _DAT_2b6e6d430d0 = 0;
  uRam000002b6e6d430d8 = 0;
  _DAT_2b6e6d430c0 = 0;
  uRam000002b6e6d430c8 = 0;
  _DAT_2b6e6d430b0 = 0;
  uRam000002b6e6d430b8 = 0;
  _DAT_2b6e6d430a0 = 0;
  uRam000002b6e6d430a8 = 0;
  _DAT_2b6e6d43090 = 0;
  uRam000002b6e6d43098 = 0;
  _DAT_2b6e6d43140 = 0;
  FUN_2b6e6c90000(&DAT_2b6e6d43144);
  _DAT_2b6e6d431e0 = 0;
  uRam000002b6e6d431e8 = 0;
  _DAT_2b6e6d431d0 = 0;
  uRam000002b6e6d431d8 = 0;
  _DAT_2b6e6d431f0 = 0;
  uRam000002b6e6d431f8 = 0;
  _DAT_2b6e6d431c0 = 0;
  uRam000002b6e6d431c8 = 0;
  _DAT_2b6e6d431b0 = 0;
  uRam000002b6e6d431b8 = 0;
  _DAT_2b6e6d431a0 = 0;
  uRam000002b6e6d431a8 = 0;
  _DAT_2b6e6d43190 = 0;
  uRam000002b6e6d43198 = 0;
  _DAT_2b6e6d43180 = 0;
  uRam000002b6e6d43188 = 0;
  _DAT_2b6e6d43170 = 0;
  uRam000002b6e6d43178 = 0;
  _DAT_2b6e6d43160 = 0;
  uRam000002b6e6d43168 = 0;
  _DAT_2b6e6d43150 = 0;
  uRam000002b6e6d43158 = 0;
  _DAT_2b6e6d43200 = 0;
  FUN_2b6e6c90000(&DAT_2b6e6d43208);
  _DAT_2b6e6d4327c = 0;
  _DAT_2b6e6d43284 = 0;
  _DAT_2b6e6d4328c = 0;
  _DAT_2b6e6d4326c = 0;
  _DAT_2b6e6d43274 = 0;
  _DAT_2b6e6d43214 = 0;
  _DAT_2b6e6d4325c = 0;
  _DAT_2b6e6d43264 = 0;
  _DAT_2b6e6d4324c = 0;
  _DAT_2b6e6d43254 = 0;
  _DAT_2b6e6d4323c = 0;
  _DAT_2b6e6d43244 = 0;
  _DAT_2b6e6d4322c = 0;
  _DAT_2b6e6d43234 = 0;
  _DAT_2b6e6d4321c = 0;
  _DAT_2b6e6d43224 = 0;
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x2b6e1db7188,6);
  if (iVar1 != 0) {
    _DAT_2b6e6d432ad = 2;
  }
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x2b6e1db7188,7);
  if (iVar1 != 0) {
    _DAT_2b6e6d432ad = 0;
  }
  (*(code *)0x7ff63a0e4490)(0x2b6e1db7188,0x2b6e4d63d60,&DAT_2b6e6d43c60);
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43c60,0x2b6e1dd7850);
  _DAT_2b6e6d43c68 = 0x2b6e6ca8d30;
  _DAT_2b6e6d43c70 = 0xc00010059;
  _DAT_2b6e6d43ca8 = 0;
  _DAT_2b6e6d43cac = 0;
  _DAT_2b6e6d43c78 = 0;
  _DAT_2b6e6d43c80 = 0;
  _DAT_2b6e6d43c88 = 0;
  _DAT_2b6e6d43c90 = 0;
  _DAT_2b6e6d43c98 = 0;
  _DAT_2b6e6d43ca0 = 0;
  FUN_2b6e6c90d90(&local_68,0x2b6e6ca8f40,0,0x2b6e6d408b0);
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43c60,0x2b6e4d63d60);
  _DAT_2b6e6d43c68 = 0x2b6e6ca8df0;
  FUN_2b6e6c90d90(&DAT_2b6e6d43ca8,&local_68,0,0x2b6e6d42b10);
  _DAT_2b6e6d43ca4 = 0;
  _DAT_2b6e6d43cbc = 0x32;
  _DAT_2b6e6d43cb4 = (*(code *)0x7ff63a0e6780)(0x2b6e1db7188);
  FUN_2b6e6c90000(&local_68);
  return;
}



/* Address: 2b6e6c982b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c982b0(void)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  FUN_2b6e6c90000(&DAT_2b6e6d43ca8);
  FUN_2b6e6c91120(&DAT_2b6e6d43c70);
  (*(code *)0x7ff63a0e62f0)(0x2b6e1db7188,_DAT_2b6e6d43c60);
  FUN_2b6e6c90000(&DAT_2b6e6d43208);
  FUN_2b6e6c90000(&DAT_2b6e6d43144);
  FUN_2b6e6c90000(&DAT_2b6e6d43084);
  FUN_2b6e6c90000(&DAT_2b6e6d43034);
  (*(code *)0x7ff63a0e6470)(0x2b6e1db7188,_DAT_2b6e6d43000,0x2b6e4d63b50);
  _DAT_2b6e6d43008 = 0x2b6e6ca8d70;
  (*(code *)0x7ff63a0e62f0)(0x2b6e1db7188,_DAT_2b6e6d43000);
  FUN_2b6e6c90000(&DAT_2b6e6d43c40);
  FUN_2b6e6c90000(&DAT_2b6e6d43c30);
  FUN_2b6e6c90000(&DAT_2b6e6d43c20);
  (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&DAT_2b6e6d43be0);
  (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&DAT_2b6e6d43ba0);
  (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&DAT_2b6e6d43b60);
  (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&DAT_2b6e6d43b20);
  (*(code *)0x7ff63a0d9d20)(0x2b6e1db7188,&DAT_2b6e6d43ae0);
  FUN_2b6e6c91120(&DAT_2b6e6d43a30);
  FUN_2b6e6c91120(&DAT_2b6e6d439f0);
  FUN_2b6e6c91120(&DAT_2b6e6d439b0);
  FUN_2b6e6c91120(&DAT_2b6e6d43970);
  FUN_2b6e6c91120(&DAT_2b6e6d43930);
  FUN_2b6e6c91120(&DAT_2b6e6d438f0);
  FUN_2b6e6c91120(&DAT_2b6e6d438b0);
  FUN_2b6e6c91120(&DAT_2b6e6d43870);
  FUN_2b6e6c91120(&DAT_2b6e6d43830);
  FUN_2b6e6c91120(&DAT_2b6e6d437f0);
  FUN_2b6e6c91120(&DAT_2b6e6d437b0);
  lVar2 = _DAT_2b6e6d4378c;
  if (_DAT_2b6e6d4378c != 0) {
    uVar5 = (ulonglong)_DAT_2b6e6d43778;
    if (uVar5 != 0) {
      lVar3 = 0;
      do {
        uVar4 = (ulonglong)*(uint *)(lVar3 * 4 + 0x2b6e6d4377c);
        if (uVar4 == 0) break;
        uVar5 = uVar5 * uVar4;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 3);
      if (uVar5 != 0) {
        plVar6 = (longlong *)(_DAT_2b6e6d4378c + 4);
        do {
          if ((((*(int *)((longlong)plVar6 + -4) != 0) && (lVar3 = *plVar6, lVar3 != 0)) &&
              ((int *)(lVar3 + -0xc) != (int *)0x0)) && (*(int *)(lVar3 + -0xc) != 0)) {
            piVar1 = (int *)(lVar3 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2b6e1db7188);
            }
          }
          *plVar6 = 0;
          *(undefined4 *)((longlong)plVar6 + -4) = 0;
          plVar6 = (longlong *)((longlong)plVar6 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2b6e1db7188,lVar2,0);
    _DAT_2b6e6d4378c = 0;
  }
  _DAT_2b6e6d43778 = 0;
  _DAT_2b6e6d43788 = 0;
  return;
}



/* Address: 2b6e6c984b0 */

/* WARNING: Removing unreachable block (ram,0x02b6e6c90db4) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f79) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90dde) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90dfe) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90ecf) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90ee0) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90ef0) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f03) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f08) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90edc) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90e07) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f10) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f20) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f3a) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f3f) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f45) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f4a) */
/* WARNING: Removing unreachable block (ram,0x02b6e6c90f59) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c984b0(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  int *piVar1;
  int *piVar2;
  longlong lVar3;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined1 local_a0 [80];
  undefined8 uStack_50;
  
  if (_DAT_2b6e6d43d14 == 0) {
    _DAT_2b6e6d43020 = 0;
    _DAT_2b6e6d43024 = 0;
    uRam000002b6e6d43028 = 0;
    uRam000002b6e6d4302c = 0;
    _DAT_2b6e6d43030 = 0;
    FUN_2b6e6c90000(&DAT_2b6e6d43034);
    _DAT_2b6e6d43080 = 0;
    _DAT_2b6e6d43070 = 0;
    _DAT_2b6e6d43078 = 0;
    _DAT_2b6e6d43060 = 0;
    _DAT_2b6e6d43068 = 0;
    _DAT_2b6e6d43050 = 0;
    _DAT_2b6e6d43058 = 0;
    _DAT_2b6e6d43040 = 0;
    _DAT_2b6e6d43048 = 0;
    FUN_2b6e6c90000(&DAT_2b6e6d43084);
    _DAT_2b6e6d43100 = 0;
    uRam000002b6e6d43108 = 0;
    _DAT_2b6e6d43120 = 0;
    uRam000002b6e6d43128 = 0;
    _DAT_2b6e6d43130 = 0;
    uRam000002b6e6d43138 = 0;
    _DAT_2b6e6d43110 = 0;
    uRam000002b6e6d43118 = 0;
    _DAT_2b6e6d430e0 = 0;
    uRam000002b6e6d430e8 = 0;
    _DAT_2b6e6d430f0 = 0;
    uRam000002b6e6d430f8 = 0;
    _DAT_2b6e6d430c0 = 0;
    uRam000002b6e6d430c8 = 0;
    _DAT_2b6e6d430d0 = 0;
    uRam000002b6e6d430d8 = 0;
    _DAT_2b6e6d430a0 = 0;
    uRam000002b6e6d430a8 = 0;
    _DAT_2b6e6d430b0 = 0;
    uRam000002b6e6d430b8 = 0;
    _DAT_2b6e6d43140 = 0;
    _DAT_2b6e6d43090 = 0;
    uRam000002b6e6d43098 = 0;
    FUN_2b6e6c90000(&DAT_2b6e6d43144);
    _DAT_2b6e6d431e0 = 0;
    uRam000002b6e6d431e8 = 0;
    _DAT_2b6e6d431d0 = 0;
    uRam000002b6e6d431d8 = 0;
    _DAT_2b6e6d431f0 = 0;
    uRam000002b6e6d431f8 = 0;
    _DAT_2b6e6d431c0 = 0;
    uRam000002b6e6d431c8 = 0;
    _DAT_2b6e6d431b0 = 0;
    uRam000002b6e6d431b8 = 0;
    _DAT_2b6e6d431a0 = 0;
    uRam000002b6e6d431a8 = 0;
    _DAT_2b6e6d43190 = 0;
    uRam000002b6e6d43198 = 0;
    _DAT_2b6e6d43180 = 0;
    uRam000002b6e6d43188 = 0;
    _DAT_2b6e6d43170 = 0;
    uRam000002b6e6d43178 = 0;
    _DAT_2b6e6d43160 = 0;
    uRam000002b6e6d43168 = 0;
    _DAT_2b6e6d43150 = 0;
    uRam000002b6e6d43158 = 0;
    _DAT_2b6e6d43200 = 0;
    FUN_2b6e6c90000(&DAT_2b6e6d43208);
    _DAT_2b6e6d43284 = 0;
    _DAT_2b6e6d4327c = 0;
    _DAT_2b6e6d4328c = 0;
    _DAT_2b6e6d43274 = 0;
    _DAT_2b6e6d4326c = 0;
    _DAT_2b6e6d43264 = 0;
    _DAT_2b6e6d4325c = 0;
    _DAT_2b6e6d43254 = 0;
    _DAT_2b6e6d4324c = 0;
    _DAT_2b6e6d43244 = 0;
    _DAT_2b6e6d4323c = 0;
    _DAT_2b6e6d43234 = 0;
    _DAT_2b6e6d4322c = 0;
    _DAT_2b6e6d43224 = 0;
    _DAT_2b6e6d4321c = 0;
    _DAT_2b6e6d43214 = 0;
    if (1 < param_2) {
      _DAT_2b6e6d43110 = CONCAT44(DAT_2b6e6d43110_4,0x271d);
      if (CONCAT44(uRam000002b6e6ca9300,uRam000002b6e6ca92fc) == 0) {
        if ((((_DAT_2b6e6d43144 != 0) &&
             (lVar3 = CONCAT44(uRam000002b6e6d4314c,_DAT_2b6e6d43148), lVar3 != 0)) &&
            ((int *)(lVar3 + -0xc) != (int *)0x0)) && (*(int *)(lVar3 + -0xc) != 0)) {
          piVar2 = (int *)(lVar3 + -8);
          *piVar2 = *piVar2 + -1;
          if (*piVar2 == 0) {
            uStack_50 = 0x2b6e6c90e49;
            (*(code *)0x7ff63a101200)(0x2b6e1db7188);
          }
        }
        _DAT_2b6e6d43148 = 0;
        uRam000002b6e6d4314c = 0;
        _DAT_2b6e6d43144 = 0;
      }
      else {
        if (((_DAT_2b6e6d43144 != 0) &&
            (lVar3 = CONCAT44(uRam000002b6e6d4314c,_DAT_2b6e6d43148), lVar3 != 0)) &&
           ((piVar2 = (int *)(lVar3 + -0xc), piVar2 != (int *)0x0 && (*piVar2 != 0)))) {
          piVar1 = (int *)(lVar3 + -8);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            uStack_50 = 0x2b6e6c90ea0;
            (*(code *)0x7ff63a101200)(0x2b6e1db7188,piVar2);
          }
        }
        uRam000002b6e6d4314c = uRam000002b6e6ca9300;
        _DAT_2b6e6d43144 = iRam000002b6e6ca92f8;
        _DAT_2b6e6d43148 = uRam000002b6e6ca92fc;
        if ((CONCAT44(uRam000002b6e6ca9300,uRam000002b6e6ca92fc) != 0) &&
           (iRam000002b6e6ca92f8 != 0)) {
          piVar2 = (int *)(CONCAT44(uRam000002b6e6ca9300,uRam000002b6e6ca92fc) + -8);
          *piVar2 = *piVar2 + 1;
        }
      }
      return;
    }
    local_a8 = param_7;
    _DAT_2b6e6d43020 = 1;
    FUN_2b6e6c90d90(&DAT_2b6e6d43034,param_1,0,0x2b6e6d40918);
    local_b8 = 0;
    local_b0 = 0;
    _DAT_2b6e6d43024 = (undefined4)_DAT_2b6e6d43295;
    uRam000002b6e6d43028 = (undefined4)((ulonglong)_DAT_2b6e6d43295 >> 0x20);
    _DAT_2b6e6d43070 = CONCAT44(_DAT_2b6e6d43074,param_2);
    _DAT_2b6e6d43058 = param_5;
    _DAT_2b6e6d43060 = param_6;
    _DAT_2b6e6d43068 = _DAT_2b6e6d4329d;
    lVar3 = 0x2b6e6d43d28;
    if (*(longlong *)(param_1 + 4) != 0) {
      lVar3 = param_1;
    }
    _DAT_2b6e6d43040 = param_3;
    _DAT_2b6e6d43048 = param_4;
    FUN_2b6e6c90d90(&local_b8,lVar3,0,0x2b6e6d414a8);
    (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_b8,0x47,local_a0);
    if ((_DAT_2b6e6d43070 & 0xffffffff) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c98a62 */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((_DAT_2b6e6d43070 & 0xffffffff) * 8 + 0x2b6e6ca8768))();
      return;
    }
    _DAT_2b6e6d43110 = CONCAT44(DAT_2b6e6d43110_4,0x2733);
    (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,2,1,0x590008,0x2b6e6caa348);
    FUN_2b6e6c90000(&local_b8);
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,0xd,2,0x590008,0x2b6e6caa3d0,0x590008,0x2b6e6ca92a8);
    _DAT_2b6e6d43110 = CONCAT44(DAT_2b6e6d43110_4,0x272b);
  }
  return;
}



/* Address: 2b6e6c98b90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b6e6c98b90(longlong param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 unaff_RSI;
  undefined8 local_40;
  undefined4 local_38;
  undefined1 local_30 [8];
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,param_1,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  iVar1 = _DAT_2b6e6d43074;
  if (uVar2 < 2) goto LAB_2b6e6c98f79;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,param_1,0x32);
  if (uVar2 == 2) {
    iVar1 = _DAT_2b6e6d43074;
    if (_DAT_2b6e6d43020 == 5) goto LAB_2b6e6c98f79;
    if ((uVar3 & 1) != 0) {
      _DAT_2b6e6d432a5 = 0;
      _DAT_2b6e6d43074 = 0;
      iVar1 = _DAT_2b6e6d43074;
      goto LAB_2b6e6c98f79;
    }
    if ((uVar3 & 2) != 0) {
      _DAT_2b6e6d432a5 = 1;
      _DAT_2b6e6d43074 = 1;
      iVar1 = _DAT_2b6e6d43074;
      goto LAB_2b6e6c98f79;
    }
LAB_2b6e6c98ed6:
    _DAT_2b6e6d43110 = 0x272e;
  }
  else {
    if (_DAT_2b6e6d432a5 == 2) {
LAB_2b6e6c98f51:
      _DAT_2b6e6d43074 = 2;
      iVar1 = _DAT_2b6e6d43074;
      goto LAB_2b6e6c98f79;
    }
    if (_DAT_2b6e6d432a5 == 1) {
      if (_DAT_2b6e6d43020 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x2b6e6d43d28;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_2b6e6c90d90(&local_40,lVar5,0,0x2b6e6d41498);
        (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_2b6e6d43078 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c98db9 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_2b6e6d43078 * 8 + 0x2b6e6ca87a8))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,2,1,0x590008,0x2b6e6caa2d0);
        FUN_2b6e6c90000(&local_40);
        _DAT_2b6e6d43078 = 1;
        if (_DAT_2b6e6d43070 - 2U < 4) goto LAB_2b6e6c98f51;
      }
      uVar3 = uVar3 & 2;
joined_r0x02b6e6c98ed0:
      iVar1 = _DAT_2b6e6d432a5;
      if (uVar3 != 0) goto LAB_2b6e6c98f79;
      goto LAB_2b6e6c98ed6;
    }
    if (_DAT_2b6e6d432a5 == 0) {
      if (_DAT_2b6e6d43020 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x2b6e6d43d28;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_2b6e6c90d90(&local_40,lVar5,0,0x2b6e6d41498);
        (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_2b6e6d43078 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c98cfe */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_2b6e6d43078 * 8 + 0x2b6e6ca87c8))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,2,1,0x590008,0x2b6e6caa2d0);
        FUN_2b6e6c90000(&local_40);
        _DAT_2b6e6d43078 = 1;
        if (_DAT_2b6e6d43070 - 2U < 4) goto LAB_2b6e6c98f51;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x02b6e6c98ed0;
    }
    _DAT_2b6e6d43110 = 0x271b;
  }
  uVar4 = 0;
  iVar1 = _DAT_2b6e6d43074;
LAB_2b6e6c98f79:
  _DAT_2b6e6d43074 = iVar1;
  return uVar4 & 0xffffffff;
}



/* Address: 2b6e6c98f90 */

void FUN_2b6e6c98f90(undefined8 param_1,longlong param_2,int *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined1 local_68 [8];
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_78 = 0;
  local_98 = 0;
  local_88 = 0;
  local_50 = 0;
  local_74 = 0;
  local_94 = 0;
  local_84 = 0;
  local_4c = 0;
  local_60 = 0;
  local_58 = 0;
  lVar10 = 0x2b6e6d43d28;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_2b6e6c90d90(&local_60,lVar10,0,0x2b6e6d41168);
  (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c990c7 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x2b6e6ca87e8))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b6e1db7188,*param_3,0x53,&local_88);
  FUN_2b6e6c90d90(&local_98,0x2b6e6caa250,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_2b6e6c9972f;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_2b6e6c9972f;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_2b6e6c90060(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1f0561000101f9);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (uVar12 != 0) {
    lVar1 = local_94 + (ulonglong)uVar14 * 2;
    if (uVar9 < 0x10) {
      uVar11 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
      uVar11 = 0;
    }
    else {
      uVar13 = 0;
      uVar11 = (ulonglong)(uVar9 & 0xfffffff8);
      do {
        puVar2 = (undefined4 *)(lVar10 + uVar13);
        uVar5 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        puVar3 = (undefined4 *)(lVar1 + uVar13);
        *puVar3 = *puVar2;
        puVar3[1] = uVar5;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        uVar13 = uVar13 + 0x10;
      } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
      if (uVar11 == uVar12) goto LAB_2b6e6c99927;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_2b6e6c99927:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_2b6e6c9972f:
  FUN_2b6e6c90d90(param_1,&local_98,0,0x2b6e6d41468);
  FUN_2b6e6c90d90(&local_50,param_1,0,0x2b6e6d41478);
  FUN_2b6e6c90000(&local_60);
  FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_50,1,0x2b6e6d41488);
  FUN_2b6e6c90000(&local_50);
  FUN_2b6e6c90000(&local_50);
  FUN_2b6e6c90000(&local_88);
  FUN_2b6e6c90000(&local_98);
  FUN_2b6e6c90000(&local_78);
  return;
}



/* Address: 2b6e6c99980 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c99980(undefined8 param_1,undefined8 param_2,int *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  char cVar10;
  uint uVar11;
  int *piVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint uVar16;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined1 local_a0 [8];
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_b0 = 0;
  local_d0 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_68 = 0;
  local_c0 = 0;
  local_78 = 0;
  local_88 = 0;
  local_e0 = 0;
  local_ac = 0;
  local_cc = 0;
  local_f4 = 0;
  local_104 = 0;
  local_64 = 0;
  local_bc = 0;
  local_74 = 0;
  local_84 = 0;
  local_dc = 0;
  local_e8 = param_2;
  FUN_2b6e6c90d90(param_2,0x2b6e6ca8e50,0,0x2b6e6d40b68);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x2b6e6d43d28;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_2b6e6c90d90(&local_98,piVar12,0,0x2b6e6d40b78);
  (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x2b6e1db7188,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c99b60 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x2b6e6ca8910))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b6e1db7188,(longlong)*param_3,0x52,&local_108);
  FUN_2b6e6c90d90(&local_f8,0x2b6e6ca99a0,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_2b6e6c9a44b;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_2b6e6c9a44b;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_2b6e6c90060(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1e04cf000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0xf04a0000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0xf04a5000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x150470000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x150489000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x15043c000101f9);
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x150457000101f9);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (uVar14 != 0) {
    lVar1 = local_f4 + (ulonglong)uVar16 * 2;
    if (uVar11 < 0x10) {
      uVar13 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar8) < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar15 = 0;
      uVar13 = (ulonglong)(uVar11 & 0xfffffff8);
      do {
        puVar2 = (undefined4 *)(lVar8 + uVar15);
        uVar5 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        puVar3 = (undefined4 *)(lVar1 + uVar15);
        *puVar3 = *puVar2;
        puVar3[1] = uVar5;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        uVar15 = uVar15 + 0x10;
      } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar15);
      if (uVar13 == uVar14) goto LAB_2b6e6c9b732;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_2b6e6c9b732:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_2b6e6c9a44b:
  uVar9 = local_e8;
  FUN_2b6e6c90d90(local_e8,&local_f8,0,0x2b6e6d41138);
  FUN_2b6e6c90d90(&local_68,uVar9,0,0x2b6e6d41148);
  FUN_2b6e6c90000(&local_98);
  FUN_2b6e6c90000(&local_e0);
  FUN_2b6e6c90000(&local_88);
  FUN_2b6e6c90000(&local_78);
  FUN_2b6e6c90000(&local_c0);
  FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_68,1,0x2b6e6d41158);
  FUN_2b6e6c90000(&local_68);
  FUN_2b6e6c90000(&local_68);
  FUN_2b6e6c90000(&local_108);
  FUN_2b6e6c90000(&local_f8);
  FUN_2b6e6c90000(&local_d0);
  FUN_2b6e6c90000(&local_b0);
  return;
}



/* Address: 2b6e6c9ba50 */

void FUN_2b6e6c9ba50(undefined8 param_1,uint param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  char cVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_50;
  longlong local_4c;
  undefined4 local_40;
  undefined8 local_3c;
  
  local_60 = 0;
  local_50 = 0;
  local_40 = 0;
  local_5c = 0;
  local_4c = 0;
  local_3c = 0;
  if (param_2 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c9bab3 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x2b6e6ca8980))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b6e1db7188,(ulonglong)param_2,0x53,&local_50);
  FUN_2b6e6c90d90(&local_60,0x2b6e6ca9138,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_2b6e6c9bcad;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_2b6e6c9bcad;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_2b6e6c90060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x2203c7000101f9);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  if (uVar13 != 0) {
    lVar1 = local_5c + (ulonglong)uVar14 * 2;
    if (uVar4 < 0x10) {
      uVar11 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar9) < 0x20) {
      uVar11 = 0;
    }
    else {
      uVar12 = 0;
      uVar11 = (ulonglong)(uVar4 & 0xfffffff8);
      do {
        puVar2 = (undefined4 *)(lVar9 + uVar12);
        uVar6 = puVar2[1];
        uVar7 = puVar2[2];
        uVar8 = puVar2[3];
        puVar3 = (undefined4 *)(lVar1 + uVar12);
        *puVar3 = *puVar2;
        puVar3[1] = uVar6;
        puVar3[2] = uVar7;
        puVar3[3] = uVar8;
        uVar12 = uVar12 + 0x10;
      } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar12);
      if (uVar11 == uVar13) goto LAB_2b6e6c9bca2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_2b6e6c9bca2:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_2b6e6c9bcad:
  FUN_2b6e6c90d90(param_1,&local_60,0,0x2b6e6d40a98);
  FUN_2b6e6c90d90(&local_40,param_1,0,0x2b6e6d40aa8);
  FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_40,1,0x2b6e6d40ab8);
  FUN_2b6e6c90000(&local_40);
  FUN_2b6e6c90000(&local_40);
  FUN_2b6e6c90000(&local_50);
  FUN_2b6e6c90000(&local_60);
  return;
}



/* Address: 2b6e6c9bd50 */

void FUN_2b6e6c9bd50(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
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
  (*(code *)0x7ff63a0fd7c0)(0x2b6e1db7188,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_2b6e6c90d90(&local_78,0x2b6e6d43d3c,1,0x2b6e6d40ac8);
    FUN_2b6e6c90d90(&local_88,&local_78,0,0x2b6e6d40ad8);
    (*(code *)0x7ff63a0fd7c0)(0x2b6e1db7188,param_3,param_4);
    FUN_2b6e6c90d90(&local_78,0x2b6e6d43d3c,1,0x2b6e6d40ae8);
    FUN_2b6e6c90d90(&local_98,&local_78,0,0x2b6e6d40af8);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6ca9200,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x2b6e6d40b18;
    uVar1 = 0x2b6e6d40b08;
  }
  else {
    uVar2 = 0x2b6e6d40b38;
    uVar1 = 0x2b6e6d40b28;
  }
  FUN_2b6e6c90d90(&local_78,0x2b6e6d43d3c,1,uVar1);
  FUN_2b6e6c90d90(param_1,&local_78,0,uVar2);
  FUN_2b6e6c90d90(&local_68,param_1,0,0x2b6e6d40b48);
  FUN_2b6e6c90000(&local_98);
  FUN_2b6e6c90000(&local_88);
  FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_68,1,0x2b6e6d40b58);
  FUN_2b6e6c90000(&local_68);
  FUN_2b6e6c90000(&local_68);
  FUN_2b6e6c90000(&local_78);
  return;
}



/* Address: 2b6e6c9bf90 */

void FUN_2b6e6c9bf90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined1 param_9)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffff20;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff20 >> 0x20);
  uVar2 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar2,param_1);
  if (iVar1 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0x112,8,0x550005,uVar2,CONCAT44(uVar3,0x590008),param_1,0x520004,2,
               0x520004,0,0x540005,param_2,0x580007,param_3,0x540005,param_4,0x580007,param_5);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0x3ec,0);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0x3eb,0);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,3,param_9);
  }
  (*(code *)0x7ff63a0f39d0)(0x2b6e1db7188,uVar2,param_1,0,param_2,param_3);
  (*(code *)0x7ff63a0f39d0)(0x2b6e1db7188,uVar2,param_1,1,param_4,param_5);
  (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0,param_6);
  (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,2,param_7);
  (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,1,param_8);
  return;
}



/* Address: 2b6e6c9c1f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c9c1f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffff60;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  uVar2 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar2,param_1);
  if (iVar1 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0x112,6,0x550005,uVar2,CONCAT44(uVar3,0x590008),param_1,0x520004,0x65,
               0x520004,0,0x540005,param_2,0x580007,param_3);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0x3f3,8);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,3,0);
  }
  (*(code *)0x7ff63a0f39d0)(0x2b6e1db7188,uVar2,param_1,0,param_2,param_3);
  (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar2,param_1,6,0x2b6e6caa788);
  (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar2,param_1,0x3e9,0x2b6e6caa7d0);
  (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0x3ea,(longlong)_DAT_2b6e6d43e38);
  (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar2,param_1,0,param_4);
  return;
}



/* Address: 2b6e6c9c3f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6c9c3f0(void)

{
  double *pdVar1;
  int *piVar2;
  ushort uVar3;
  code *pcVar4;
  undefined2 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  byte bVar13;
  double *pdVar14;
  undefined8 uVar15;
  ushort uVar16;
  undefined8 uVar17;
  uint uVar18;
  longlong lVar19;
  undefined8 *puVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  ulonglong uVar32;
  undefined8 in_stack_fffffffffffffca0;
  undefined4 uVar33;
  undefined4 *puVar34;
  undefined4 *puVar35;
  double dVar36;
  double dVar37;
  undefined8 in_stack_fffffffffffffcb8;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 local_308;
  undefined8 local_304;
  undefined8 local_2f8;
  undefined8 *local_2f0;
  undefined4 local_2e8;
  undefined8 local_2e4;
  undefined4 local_2d8;
  undefined4 local_2d4;
  uint uStack_2d0;
  undefined4 uStack_2cc;
  undefined8 local_2c8;
  undefined4 local_2c0;
  undefined4 uStack_2bc;
  undefined4 local_2b8;
  undefined4 uStack_2b4;
  undefined8 local_2b0;
  undefined4 local_2a8;
  undefined4 local_2a0;
  undefined8 local_29c;
  ulonglong local_290;
  ulonglong local_288;
  ulonglong local_280;
  ulonglong local_278;
  ulonglong local_270;
  undefined4 local_268;
  undefined1 *local_264;
  undefined4 local_258;
  undefined1 *local_254;
  undefined4 local_248;
  undefined8 local_244;
  ulonglong local_238;
  ulonglong local_230;
  undefined4 local_228;
  undefined8 local_224;
  undefined4 local_218;
  undefined8 local_214;
  undefined4 local_208;
  undefined8 local_204;
  undefined4 local_1f8;
  undefined8 local_1f4;
  undefined4 local_1e8;
  undefined8 local_1e4;
  undefined4 local_1d8;
  undefined8 local_1d4;
  undefined4 local_1c8;
  undefined8 local_1c4;
  undefined4 local_1b8;
  undefined8 local_1b4;
  undefined4 local_1a8;
  undefined8 local_1a4;
  undefined4 local_198;
  undefined8 local_194;
  ulonglong local_188;
  undefined4 local_180;
  undefined8 local_17c;
  undefined4 local_170;
  undefined8 local_16c;
  undefined4 local_160;
  undefined8 local_15c;
  undefined4 local_150;
  undefined8 local_14c;
  undefined2 local_140;
  ushort local_13e;
  undefined4 local_13c;
  ulonglong local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  int iStack_e4;
  longlong alStack_e0 [4];
  ulonglong local_c0;
  
  local_2a0 = 0;
  local_258 = 0;
  local_268 = 0;
  local_198 = 0;
  local_1a8 = 0;
  local_1b8 = 0;
  local_1c8 = 0;
  local_1d8 = 0;
  local_1e8 = 0;
  local_1f8 = 0;
  local_2e8 = 0;
  local_150 = 0;
  local_160 = 0;
  local_170 = 0;
  local_208 = 0;
  local_218 = 0;
  local_228 = 0;
  local_180 = 0;
  local_29c = 0;
  local_254 = (undefined1 *)0x0;
  local_264 = (undefined1 *)0x0;
  local_194 = 0;
  local_1a4 = 0;
  local_1b4 = 0;
  local_1c4 = 0;
  local_1d4 = 0;
  local_1e4 = 0;
  local_1f4 = 0;
  local_2e4 = 0;
  local_14c = 0;
  local_15c = 0;
  local_16c = 0;
  local_204 = 0;
  local_214 = 0;
  local_224 = 0;
  local_17c = 0;
  uVar10 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  uVar5 = _DAT_2b6e1e2671a;
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffcb8 >> 0x20);
  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffca0 >> 0x20);
  if (DAT_2b6e6d43313 == '\0') {
    local_248 = 0;
    local_244 = 0;
    puVar20 = (undefined8 *)(*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar10 = CONCAT44(uVar28,0x590008);
    uVar17 = CONCAT44(uVar29,_DAT_2b6e6d43d24);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa720,uVar10,0x2b6e6d43d28,0x520004,uVar17);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d416e0);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d416f0);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41700);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41da0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar10 = CONCAT44(uVar28,0x590008);
    uVar17 = CONCAT44(uVar29,_DAT_2b6e6d43d24);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa768,uVar10,0x2b6e6d43d28,0x520004,uVar17);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41710);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41720);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41730);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41db0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar10 = CONCAT44(uVar28,0x590008);
    uVar17 = CONCAT44(uVar29,_DAT_2b6e6d43d24);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa5a0,uVar10,0x2b6e6d43d28,0x520004,uVar17);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d415f0);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41600);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41610);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41dc0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar10 = CONCAT44(uVar28,0x590008);
    uVar17 = CONCAT44(uVar29,_DAT_2b6e6d43d24);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa688,uVar10,0x2b6e6d43d28,0x520004,uVar17);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41680);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41690);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d416a0);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41dd0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar12 = 0x2b6e6d43d28;
    uVar10 = CONCAT44(uVar28,0x590008);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa6d8,uVar10,0x2b6e6d43d28,0x520004,
               CONCAT44(uVar29,_DAT_2b6e6d43d24));
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d416b0);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d416c0);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d416d0);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41de0);
    local_2f0 = puVar20;
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar12 = uVar12 & 0xffffffff00000000;
    uVar10 = CONCAT44(uVar28,0x520004);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,uVar10,uVar12,0x590008,0x2b6e6d43d28,
               0x520004,_DAT_2b6e6d43d24);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar29 = (undefined4)(uVar12 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41df0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar17 = CONCAT44(uVar29,1);
    uVar10 = CONCAT44(uVar28,0x520004);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,uVar10,uVar17,0x590008,0x2b6e6d43d28,
               0x520004,_DAT_2b6e6d43d24);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41df0);
    puVar20 = local_2f0;
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_2f0,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar17 = CONCAT44(uVar29,2);
    uVar10 = CONCAT44(uVar28,0x520004);
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,uVar10,uVar17,0x590008,0x2b6e6d43d28,
               0x520004,_DAT_2b6e6d43d24);
    uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41df0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    local_2d8 = 0;
    local_308 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    (*(code *)0x7ff63a0e49f0)
              (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,CONCAT44(uVar28,0x520004),
               CONCAT44(uVar29,3),0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
    FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
    FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41df0);
    (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
    iVar7 = 0;
    do {
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,0x520004,iVar7,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_248,0x2b6e6d43d3c,1,0x2b6e6d41e00);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,puVar20,&local_248);
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x10);
    puVar34 = &local_248;
    goto LAB_2b6e6ca201f;
  }
  local_140 = _DAT_2b6e1e2671a;
  local_13e = 1;
  local_13c = 0x3c;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  uStack_124 = 0;
  local_120 = 0;
  uStack_11c = 0;
  local_118 = 0;
  local_110 = 0;
  iVar7 = FUN_2b6e6c912e0(_DAT_2b6e6d43d24,2,&local_140);
  dVar36 = 0.0;
  uVar30 = 0;
  uVar31 = 0;
  uVar28 = 0;
  uVar29 = 0;
  dVar37 = 0.0;
  dVar27 = 0.0;
  if (iVar7 < 2) {
LAB_2b6e6c9c775:
    FUN_2b6e6c91210(&local_140);
    local_2f0 = (undefined8 *)CONCAT62(local_2f0._2_6_,uVar5);
    if (DAT_2b6e6d432b3 != '\0') {
      dVar36 = (double)_DAT_2b6e6d43730 * _DAT_2b6e6ca89c8;
    }
    uVar17 = 0x2b6e6caaf68;
    local_258 = 0;
    local_254 = (undefined1 *)0x0;
    if (0 < _DAT_2b6e6d43730) {
      uVar17 = 0x2b6e6caaf40;
    }
    local_2f8 = uVar10;
    FUN_2b6e6c90d90(&local_258,uVar17,0,0x2b6e6d41e10);
    local_268 = 0;
    local_264 = (undefined1 *)0x0;
    FUN_2b6e6c90d90(&local_268,0x2b6e6caaf98,0,0x2b6e6d41e20);
    iVar7 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
    if (-1 < iVar7 + -1) {
      lVar19 = (longlong)_DAT_2b6e6d43e18;
      do {
        iVar7 = iVar7 + -1;
        uVar10 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar7);
        cVar6 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,uVar10);
        if ((cVar6 != '\0') &&
           (lVar11 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc), lVar11 == lVar19)) {
          iVar8 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,2);
          if (iVar8 == 0) {
            FUN_2b6e6c90d90(&local_268,0x2b6e6caafc8,0,0x2b6e6d41e30);
            break;
          }
          if (iVar8 == 1) break;
        }
      } while (0 < iVar7);
    }
    iVar7 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
    if (-1 < iVar7 + -1) {
      lVar19 = (longlong)_DAT_2b6e6d43e18;
      do {
        iVar7 = iVar7 + -1;
        uVar10 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar7);
        cVar6 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,uVar10);
        if ((cVar6 != '\0') &&
           (lVar11 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc), lVar11 == lVar19)) {
          iVar8 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,2);
          if (iVar8 == 0) break;
          if (iVar8 == 1) {
            FUN_2b6e6c90d90(&local_268,0x2b6e6caaff8,0,0x2b6e6d41e40);
            break;
          }
        }
      } while (0 < iVar7);
    }
    iVar7 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
    uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffcb8 >> 0x20);
    uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffca0 >> 0x20);
    if (-1 < iVar7 + -1) {
      lVar19 = (longlong)_DAT_2b6e6d43e18;
      do {
        iVar7 = iVar7 + -1;
        uVar10 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar7);
        cVar6 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,uVar10);
        if ((cVar6 != '\0') &&
           (lVar11 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc), lVar11 == lVar19)) {
          uVar12 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,2);
          uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffcb8 >> 0x20);
          uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffca0 >> 0x20);
          if ((uVar12 & 0xfffffffe) == 0) goto LAB_2b6e6c9d68a;
        }
        uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffcb8 >> 0x20);
        uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffca0 >> 0x20);
      } while (0 < iVar7);
    }
    FUN_2b6e6c90d90(&local_268,0x2b6e6cab030,0,0x2b6e6d41e50);
LAB_2b6e6c9d68a:
    local_198 = 0;
    local_2d8 = 0;
    local_308 = 0;
    local_194 = 0;
    local_2d4 = 0;
    uStack_2d0 = 0;
    local_304 = 0;
    uVar5 = local_2f0._0_2_;
    if ((longlong)_DAT_2b6e6d43d24 < 0x4001) {
      if (_DAT_2b6e6d43d24 - 1U < 0x1e) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c9d718 */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((ulonglong)(_DAT_2b6e6d43d24 - 1U) * 8 + 0x2b6e6ca8a10))();
        return;
      }
LAB_2b6e6c9d95d:
      puVar34 = &local_2d8;
      FUN_2b6e6c91320(puVar34,(longlong)_DAT_2b6e6d43d24,0x2b6e6d41b90,0x17);
      uVar10 = 0x2b6e6d41d00;
    }
    else {
      if (_DAT_2b6e6d43d24 - 0x4001U < 0x18) {
                    /* WARNING: Could not emulate address calculation at 0x02b6e6c9d766 */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((ulonglong)(_DAT_2b6e6d43d24 - 0x4001U) * 8 + 0x2b6e6ca8b00))();
        return;
      }
      if (_DAT_2b6e6d43d24 == 0x8001) {
        puVar34 = (undefined4 *)0x2b6e6caaba8;
        uVar10 = 0x2b6e6d41890;
      }
      else {
        if (_DAT_2b6e6d43d24 != 0xc001) goto LAB_2b6e6c9d95d;
        puVar34 = (undefined4 *)0x2b6e6caabd8;
        uVar10 = 0x2b6e6d418a0;
      }
    }
    FUN_2b6e6c90d90(&local_308,puVar34,0,uVar10);
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41d10);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_308);
    FUN_2b6e6c90000(&local_2d8);
    FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41e60);
    FUN_2b6e6c90d90(&local_198,&local_2a0,0,0x2b6e6d41e70);
    local_1a8 = 0;
    local_308 = 0;
    local_2d8 = CONCAT22(1,uVar5);
    local_2d4 = 0x3c;
    local_1a4 = 0;
    local_304 = 0;
    uStack_2d0 = 0;
    uStack_2cc = 0;
    local_2c8 = 0;
    local_2c0 = 0;
    uStack_2bc = 0;
    local_2b8 = 0;
    uStack_2b4 = 0;
    local_2b0 = 0;
    local_2a8 = 0;
    uVar9 = FUN_2b6e6c912e0(_DAT_2b6e6d43d24,0x28,&local_2d8);
    if ((int)uVar9 < 2) {
      uVar10 = 0x2b6e6caac58;
      uVar17 = 0x2b6e6d41d20;
LAB_2b6e6c9dc90:
      FUN_2b6e6c90d90(&local_308,uVar10,0,uVar17);
      FUN_2b6e6c91210(&local_2d8);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41d90);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41e80);
      uVar12 = 0;
      FUN_2b6e6c90d90(&local_1a8,&local_2a0,0,0x2b6e6d41e90);
      dVar22 = (double)(*(code *)0x7ff63a3de390)(_DAT_2b6e6d43758);
      alStack_e0[3] = 0xffff0000;
      local_1b8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_1b4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar17 = CONCAT44(uVar33,0x590008);
      uVar10 = 0xaa000000;
      dVar22 = (dVar22 + _DAT_2b6e6ca89d0) * _DAT_2b6e6ca8a08;
      if (DAT_2b6e6d4331c == '\0') {
        alStack_e0[3] = 0xff000000;
      }
      else {
        uVar10 = 0xaaff0000;
      }
      if (dVar22 < _DAT_2b6e6ca8a08) {
        alStack_e0[3] = uVar10;
      }
      uVar10 = CONCAT44(uVar38,_DAT_2b6e6d43d24);
      uVar32 = 0xffbf00;
      if (DAT_2b6e6d4331a == '\0') {
        uVar32 = uVar12;
      }
      local_c0 = 0x8515c7;
      if (DAT_2b6e6d4331b == '\0') {
        local_c0 = uVar12;
      }
      if (0.0 <= dVar37) {
        local_c0 = uVar32;
      }
      uVar32 = (ulonglong)((uint)DAT_2b6e6d43317 + (uint)DAT_2b6e6d43317 * 4);
      local_270 = 0x19;
      if (DAT_2b6e6d43318 == '\0') {
        local_270 = uVar12;
      }
      local_288 = 0x183;
      if (DAT_2b6e6d43315 == '\0') {
        local_288 = uVar12;
      }
      local_230 = 0x102;
      if (DAT_2b6e6d43316 == '\0') {
        local_230 = uVar12;
      }
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa720,uVar17,0x2b6e6d43d28,0x520004,uVar10);
      uVar38 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d416e0);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d416f0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41700);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41ea0);
      FUN_2b6e6c90d90(&local_1b8,&local_2a0,0,0x2b6e6d41eb0);
      uVar10 = local_2f8;
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,local_2f8,&local_1b8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar38,0x6a);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,CONCAT44(uVar33,0x590008),&local_1b8,
                   0x520004,uVar17,0x520004,0,0x540005,0,0x580007,0);
        uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1b8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1b8,10,0);
        uVar12 = 0;
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1b8,3,0);
        uVar33 = 0x2b6;
        (*(code *)0x7ff63a0f47a0)
                  (0x2b6e1db7188,uVar10,&local_1b8,0x3f9,uVar12 & 0xffffffff00000000,0x2b6e6cab0a0);
      }
      local_2f0 = (undefined8 *)uVar32;
      local_280 = uVar32;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_1b8,0x3f4,uVar32);
      uVar12 = local_270 & 0xffffffff;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_1b8,0x3f5,uVar12);
      local_1c8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_1c4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar10 = CONCAT44(uVar33,0x590008);
      uVar17 = CONCAT44(uVar38,_DAT_2b6e6d43d24);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa5a0,uVar10,0x2b6e6d43d28,0x520004,uVar17);
      uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d415f0);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41600);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41610);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41ec0);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_1c8,&local_2a0,0,0x2b6e6d41ed0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_1c8);
      if (iVar7 < 0) {
        uVar15 = CONCAT44(uVar38,0x6e);
        uVar17 = CONCAT44(uVar33,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_1c8,0x520004,uVar15,0x520004,
                   0,0x540005,0,0x580007,0);
        uVar38 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,10,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,3,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x3f4,local_2f0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x3f5,uVar12);
      local_290 = local_288 & 0xffffffff;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x3fb,local_290);
      uVar12 = local_230;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x3fc,local_230 & 0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,0x401,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,1,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1c8,2,0);
      local_1d8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_1d4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar10 = CONCAT44(uVar33,0x590008);
      puVar34 = (undefined4 *)0x2b6e6d43d28;
      iVar8 = (uint)uVar12 + 4 + (int)local_270;
      uVar17 = CONCAT44(uVar38,_DAT_2b6e6d43d24);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa768,uVar10,0x2b6e6d43d28,0x520004,uVar17);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41710);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41720);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41730);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41ee0);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_1d8,&local_2a0,0,0x2b6e6d41ef0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_1d8);
      if (iVar7 < 0) {
        puVar34 = &local_1d8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,CONCAT44(uVar33,0x590008),&local_1d8,
                   0x520004,CONCAT44(uVar38,0x6a),0x520004,0,0x540005,0,0x580007,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1d8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1d8,10,0);
        uVar32 = 0;
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1d8,3,0);
        uVar33 = 0x2b6;
        (*(code *)0x7ff63a0f47a0)
                  (0x2b6e1db7188,uVar10,&local_1d8,0x3f9,uVar32 & 0xffffffff00000000,0x2b6e6cab110);
      }
      uVar9 = (uint)uVar12 | (uint)local_270;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_1d8,0x3f4,local_2f0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_1d8,0x3f5,iVar8);
      local_1e8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_1e4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar12 = (ulonglong)puVar34 & 0xffffffff00000000;
      uVar10 = CONCAT44(uVar33,0x520004);
      uVar39 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,uVar10,uVar12,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar38 = (undefined4)(uVar12 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f00);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_1e8,&local_2a0,0,0x2b6e6d41f10);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_1e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar34 = &local_1e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_1e8,0x520004,
                   CONCAT44(uVar39,0x6e),0x520004,0,0x540005,0,0x580007,0);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar38 = (undefined4)((ulonglong)puVar34 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,10,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,3,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x3f4,local_2f0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x3f5,iVar8);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x3fb,local_290);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x3fc,0x96);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,0x401,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,1,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1e8,2,0);
      local_1f8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_1f4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      puVar34 = (undefined4 *)CONCAT44(uVar38,1);
      uVar10 = CONCAT44(uVar33,0x520004);
      local_2f0 = (undefined8 *)CONCAT44(local_2f0._4_4_,uVar9 + 0xc);
      uVar38 = 0x2b6;
      uVar18 = (int)local_288 - 0x10;
      local_290 = CONCAT44(local_290._4_4_,(int)local_280 + 8);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa5e8,uVar10,puVar34,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41620);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41630);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41640);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f20);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_1f8,&local_2a0,0,0x2b6e6d41f30);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_1f8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar34 = &local_1f8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_1f8,0x520004,
                   CONCAT44(uVar38,0x6e),0x520004,0,0x540005,0,0x580007,0);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,10,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,3,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0x3f4,local_290 & 0xffffffff);
      (*(code *)0x7ff63a0f3b30)
                (0x2b6e1db7188,uVar10,&local_1f8,0x3f5,(ulonglong)local_2f0 & 0xffffffff);
      alStack_e0[1] = (ulonglong)uVar18;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0x3fb,(longlong)(int)uVar18);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0x3fc,0x16);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,0x401,0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,1,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_1f8,2,0);
      local_2e8 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_2e4 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar12 = (ulonglong)puVar34 & 0xffffffff00000000;
      uVar10 = CONCAT44(uVar33,0x520004);
      uVar39 = 0x2b6;
      uVar18 = (uint)local_280;
      local_2f0 = (undefined8 *)(ulonglong)uVar9;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar10,uVar12,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar38 = (undefined4)(uVar12 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f40);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d41f50);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar34 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar39,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar38 = (undefined4)((ulonglong)puVar34 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,10,0);
      }
      dVar26 = _DAT_2b6e6ca89d0;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      local_188 = (ulonglong)(uVar18 | 0x12);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_188);
      local_278 = (ulonglong)(uVar9 + 0x10);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,local_278);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,&local_258);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab150);
      local_238 = (ulonglong)_DAT_2b6e6d43e38;
      local_290 = (ulonglong)(_DAT_2b6e6d43e38 + 1);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      if (local_254 == &DAT_2b6e6caaf2c) {
        uVar17 = 0xffbf00;
        cVar6 = DAT_2b6e6d4331a;
LAB_2b6e6c9f266:
        if (cVar6 == '\0') {
          uVar17 = 0;
        }
      }
      else {
        if (local_254 == (undefined1 *)0x0) {
          uVar17 = 0x8515c7;
          cVar6 = DAT_2b6e6d4331b;
          goto LAB_2b6e6c9f266;
        }
        uVar9 = *(uint *)(local_254 + -4);
        uVar18 = _DAT_2b6e6caaf28;
        if (uVar9 < _DAT_2b6e6caaf28) {
          uVar18 = uVar9;
        }
        iVar7 = uVar9 - _DAT_2b6e6caaf28;
        if (uVar18 != 0) {
          uVar12 = 0;
          do {
            uVar16 = *(ushort *)(local_254 + uVar12 * 2);
            uVar3 = *(ushort *)(&DAT_2b6e6caaf2c + uVar12 * 2);
            uVar12 = uVar12 + 1;
            if (uVar18 <= uVar12) break;
          } while (uVar16 == uVar3);
          if (uVar16 != uVar3) {
            iVar7 = (uint)uVar16 - (uint)uVar3;
          }
        }
        uVar15 = 0xffbf00;
        if (DAT_2b6e6d4331a == '\0') {
          uVar15 = 0;
        }
        uVar17 = 0x8515c7;
        if (DAT_2b6e6d4331b == '\0') {
          uVar17 = 0;
        }
        if (iVar7 == 0) {
          uVar17 = uVar15;
        }
      }
      if (dVar36 <= dVar26) {
        dVar26 = dVar36;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar10 = CONCAT44(uVar33,0x520004);
      uVar39 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar10,CONCAT44(uVar38,1),0x590008,
                 0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      uVar10 = local_2f8;
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f60);
      FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d41f70);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar39,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,(int)local_280 + 0x58);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,local_278);
      uVar17 = CONCAT44(uVar33,0x580007);
      dVar26 = dVar26 * _DAT_2b6e6ca89c0;
      (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,0xd8,2,0x590008,0x2b6e6cab188,uVar17,dVar26);
      uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar38 = (undefined4)((ulonglong)dVar26 >> 0x20);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f80);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,&local_2a0);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab150);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      uVar17 = 0xffbf00;
      if (DAT_2b6e6d43319 == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar17 = CONCAT44(uVar38,2);
      uVar10 = CONCAT44(uVar33,0x520004);
      uVar39 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar10,uVar17,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      uVar10 = local_2f8;
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d41f90);
      FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d41fa0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar34 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar39,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar38 = (undefined4)((ulonglong)puVar34 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      uVar12 = (ulonglong)((int)local_280 + 0x9e);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,uVar12);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,local_278);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,&local_268);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab150);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      if (local_264 == &DAT_2b6e6caafbc) {
LAB_2b6e6c9fa29:
        bVar21 = DAT_2b6e6d4331a == '\0';
        uVar17 = 0xffbf00;
LAB_2b6e6c9fa90:
        if (bVar21) {
          uVar17 = 0;
        }
      }
      else {
        if (local_264 == (undefined1 *)0x0) {
          bVar21 = DAT_2b6e6d43314 == '\0';
          uVar17 = 0xfff8f0;
          goto LAB_2b6e6c9fa90;
        }
        uVar9 = *(uint *)(local_264 + -4);
        uVar18 = _DAT_2b6e6caafb8;
        if (uVar9 < _DAT_2b6e6caafb8) {
          uVar18 = uVar9;
        }
        iVar7 = uVar9 - _DAT_2b6e6caafb8;
        if (uVar18 != 0) {
          uVar32 = 0;
          do {
            uVar16 = *(ushort *)(local_264 + uVar32 * 2);
            uVar3 = *(ushort *)(&DAT_2b6e6caafbc + uVar32 * 2);
            uVar32 = uVar32 + 1;
            if (uVar18 <= uVar32) break;
          } while (uVar16 == uVar3);
          if (uVar16 != uVar3) {
            iVar7 = (uint)uVar16 - (uint)uVar3;
          }
        }
        if (iVar7 == 0) goto LAB_2b6e6c9fa29;
        if (local_264 == &DAT_2b6e6caafec) {
          bVar21 = DAT_2b6e6d4331b == '\0';
          uVar17 = 0x8515c7;
          goto LAB_2b6e6c9fa90;
        }
        uVar18 = _DAT_2b6e6caafe8;
        if (uVar9 < _DAT_2b6e6caafe8) {
          uVar18 = uVar9;
        }
        iVar7 = uVar9 - _DAT_2b6e6caafe8;
        if (uVar18 != 0) {
          uVar32 = 0;
          do {
            uVar16 = *(ushort *)(local_264 + uVar32 * 2);
            uVar3 = *(ushort *)(&DAT_2b6e6caafec + uVar32 * 2);
            uVar32 = uVar32 + 1;
            if (uVar18 <= uVar32) break;
          } while (uVar16 == uVar3);
          if (uVar16 != uVar3) {
            iVar7 = (uint)uVar16 - (uint)uVar3;
          }
        }
        uVar15 = 0x8515c7;
        if (DAT_2b6e6d4331b == '\0') {
          uVar15 = 0;
        }
        uVar17 = 0xfff8f0;
        if (DAT_2b6e6d43314 == '\0') {
          uVar17 = 0;
        }
        if (iVar7 == 0) {
          uVar17 = uVar15;
        }
      }
      alStack_e0[2] = uVar12;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar39 = 0x2b6;
      uVar17 = CONCAT44(uVar38,3);
      uVar10 = CONCAT44(uVar33,0x520004);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar10,uVar17,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      uVar10 = local_2f8;
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      puVar34 = &local_2a0;
      FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d41fb0);
      FUN_2b6e6c90d90(&local_2e8,puVar34,0,0x2b6e6d41fc0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar35 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar39,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar38 = (undefined4)((ulonglong)puVar35 >> 0x20);
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      iVar7 = (int)local_280;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,iVar7 + 0xe4);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,local_278);
      uVar17 = CONCAT44(uVar33,0x520004);
      uVar15 = CONCAT44(uVar38,_DAT_2b6e6d43730);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6cab1c8,uVar17,uVar15,0x590008,&local_198);
      uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar38 = (undefined4)((ulonglong)uVar15 >> 0x20);
      FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d41fd0);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,puVar34);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      uVar17 = 0xfff8f0;
      if (DAT_2b6e6d43314 == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar17 = CONCAT44(uVar38,4);
      uVar10 = CONCAT44(uVar33,0x520004);
      uVar39 = 0x2b6;
      local_278 = CONCAT44(local_278._4_4_,(int)alStack_e0[1] + -6 + iVar7);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar10,uVar17,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar33 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar38 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      uVar10 = local_2f8;
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d41fe0);
      FUN_2b6e6c90d90(&local_2e8,puVar34,0,0x2b6e6d41ff0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar33,0x590008);
        puVar35 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar39,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar33 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar38 = (undefined4)((ulonglong)puVar35 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f3,6);
      local_278 = (ulonglong)(int)local_278;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_278);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,(int)local_2f0 + 0xf);
      local_150 = 0;
      local_14c = 0;
      if ((double)CONCAT44(uVar29,uVar28) < 0.0 || (double)CONCAT44(uVar29,uVar28) == 0.0) {
        puVar34 = (undefined4 *)0x2b6e6cab228;
      }
      else {
        (*(code *)0x7ff63a0fd7c0)(0x2b6e1db7188,CONCAT44(uVar29,uVar28),_DAT_2b6e6d43d20);
        FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d42000);
      }
      FUN_2b6e6c90d90(&local_150,puVar34,0,0x2b6e6d42010);
      uVar10 = local_2f8;
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,local_2f8,&local_2e8,6,&local_150);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab150);
      (*(code *)0x7ff63a0f3b30)
                (0x2b6e1db7188,uVar10,&local_2e8,0x3ea,(longlong)((int)local_238 + 3));
      uVar17 = 0xffbf00;
      if (DAT_2b6e6d43319 == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar15 = CONCAT44(uVar38,5);
      uVar17 = CONCAT44(uVar33,0x520004);
      uVar33 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar17,uVar15,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar15 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      puVar34 = &local_2a0;
      FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d42020);
      FUN_2b6e6c90d90(&local_2e8,puVar34,0,0x2b6e6d42030);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar28,0x590008);
        puVar35 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar33,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar29 = (undefined4)((ulonglong)puVar35 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f3,6);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_278);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,(int)local_2f0 + 0x19);
      local_160 = 0;
      local_15c = 0;
      if ((double)CONCAT44(uVar31,uVar30) < 0.0 || (double)CONCAT44(uVar31,uVar30) == 0.0) {
        puVar34 = (undefined4 *)0x2b6e6cab228;
      }
      else {
        uVar10 = CONCAT44(uVar28,0x580007);
        dVar36 = dVar37;
        (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,0xd8,2,0x590008,0x2b6e6cab258,uVar10,dVar37);
        uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
        uVar29 = (undefined4)((ulonglong)dVar36 >> 0x20);
        FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d42040);
      }
      FUN_2b6e6c90d90(&local_160,puVar34,0,0x2b6e6d42050);
      uVar10 = local_2f8;
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,local_2f8,&local_2e8,6,&local_160);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_238);
      uVar17 = 0xffbf00;
      if (DAT_2b6e6d4331a == '\0') {
        uVar17 = 0;
      }
      uVar15 = 0x8515c7;
      if (DAT_2b6e6d4331b == '\0') {
        uVar15 = 0;
      }
      if (0.0 <= dVar37) {
        uVar15 = uVar17;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar15);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar15 = CONCAT44(uVar29,6);
      uVar17 = CONCAT44(uVar28,0x520004);
      uVar33 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar17,uVar15,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar15 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      puVar34 = &local_2a0;
      FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d42060);
      FUN_2b6e6c90d90(&local_2e8,puVar34,0,0x2b6e6d42070);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44(uVar28,0x590008);
        puVar35 = &local_2e8;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar33,0x66),0x520004,0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar29 = (undefined4)((ulonglong)puVar35 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f3,6);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_278);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,(int)local_2f0 + 0x22);
      local_170 = 0;
      local_16c = 0;
      if ((double)CONCAT44(uVar31,uVar30) < 0.0 || (double)CONCAT44(uVar31,uVar30) == 0.0) {
        puVar34 = (undefined4 *)0x2b6e6cab228;
      }
      else {
        uVar10 = CONCAT44(uVar28,0x580007);
        dVar37 = dVar27;
        (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,0xd8,2,0x590008,0x2b6e6cab290,uVar10,dVar27);
        uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
        uVar29 = (undefined4)((ulonglong)dVar37 >> 0x20);
        FUN_2b6e6c90d90(puVar34,0x2b6e6d43d3c,1,0x2b6e6d42080);
      }
      FUN_2b6e6c90d90(&local_170,puVar34,0,0x2b6e6d42090);
      uVar10 = local_2f8;
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,local_2f8,&local_2e8,6,&local_170);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_238);
      uVar17 = 0xffbf00;
      if (DAT_2b6e6d4331a == '\0') {
        uVar17 = 0;
      }
      uVar15 = 0x8515c7;
      if (DAT_2b6e6d4331b == '\0') {
        uVar15 = 0;
      }
      if (0.0 <= dVar27) {
        uVar15 = uVar17;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar15);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar17 = CONCAT44(uVar28,0x520004);
      uVar30 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar17,CONCAT44(uVar29,7),0x590008,
                 0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d420a0);
      FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d420b0);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar15 = CONCAT44(uVar30,0x66);
        uVar17 = CONCAT44(uVar28,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,uVar15,0x520004,
                   0,0x540005,0,0x580007,0);
        uVar10 = local_2f8;
        uVar30 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_188);
      iVar7 = (int)local_2f0;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,iVar7 + 0x27);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,0x2b6e6cab2d8);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      uVar17 = 0xfff8f0;
      if (DAT_2b6e6d43314 == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,uVar17);
      local_208 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_204 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar10 = CONCAT44(uVar28,0x590008);
      local_238 = CONCAT44(local_238._4_4_,iVar7 + 0x28);
      iVar7 = 0x146;
      if (0x146 < (int)local_288) {
        iVar7 = (int)local_288;
      }
      local_288 = CONCAT44(local_288._4_4_,iVar7 + -0xf6);
      uVar17 = CONCAT44(uVar30,_DAT_2b6e6d43d24);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa688,uVar10,0x2b6e6d43d28,0x520004,uVar17);
      uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41680);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41690);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d416a0);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d420c0);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_208,&local_2a0,0,0x2b6e6d420d0);
      iVar8 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_208);
      if (iVar8 < 0) {
        uVar15 = CONCAT44(uVar29,0x6e);
        uVar17 = CONCAT44(uVar28,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_208,0x520004,uVar15,0x520004,
                   0,0x540005,0,0x580007,0);
        uVar29 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,10,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,3,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x3f4,alStack_e0[2]);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x3f5,local_238 & 0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x3fb,local_288 & 0xffffffff);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x3fc,10);
      uVar17 = 0xff;
      if (DAT_2b6e6d4331c == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0,uVar17);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,0x401,0xdc000000);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,1,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_208,2,1);
      local_218 = 0;
      local_2d8 = 0;
      local_308 = 0;
      local_214 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar10 = CONCAT44(uVar28,0x590008);
      uVar30 = 0x2b6;
      uVar17 = CONCAT44(uVar29,_DAT_2b6e6d43d24);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6caa6d8,uVar10,0x2b6e6d43d28,0x520004,uVar17);
      uVar28 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar17 >> 0x20);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d416b0);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d416c0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d416d0);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d420e0);
      uVar10 = local_2f8;
      FUN_2b6e6c90d90(&local_218,&local_2a0,0,0x2b6e6d420f0);
      iVar8 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_218);
      if (iVar8 < 0) {
        uVar17 = CONCAT44(uVar28,0x590008);
        puVar34 = &local_218;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_218,0x520004,
                   CONCAT44(uVar29,0x6e),0x520004,0,0x540005,0,0x580007,0);
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar30 = (undefined4)((ulonglong)puVar34 >> 0x20);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,10,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,3,0);
      }
      uVar10 = local_2f8;
      dVar22 = dVar22 * (double)(iVar7 + -0xfa);
      uVar9 = (uint)((ulonglong)dVar22 >> 0x34) & 0x7ff;
      lVar19 = (ulonglong)uVar9 - 0x3ff;
      dVar27 = dVar22;
      if ((ulonglong)uVar9 < 0x433) {
        if (uVar9 < 0x3ff) {
          dVar27 = (double)((ulonglong)dVar22 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar19 != -1) {
            dVar27 = (double)((ulonglong)dVar22 & 0x8000000000000000);
          }
        }
        else {
          bVar13 = (byte)lVar19;
          if (((longlong)dVar22 << (bVar13 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar27 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar22 &
                             -0x10000000000000 >> (bVar13 & 0x3f));
          }
        }
      }
      else if (lVar19 == 0x400) {
        dVar27 = dVar22 + dVar22;
      }
      iVar7 = 4;
      if (4 < (int)dVar27) {
        iVar7 = (int)dVar27;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,local_2f8,&local_218,0x3f4,(uint)local_280 | 0xa0);
      iVar8 = (int)local_2f0;
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0x3f5,iVar8 + 0x2a);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0x3fb,iVar7);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0x3fc,6);
      uVar17 = 0xff;
      if (DAT_2b6e6d4331c == '\0') {
        uVar17 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0,uVar17);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,0x401,alStack_e0[3]);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,1,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_218,2,0);
      local_2f0 = (undefined8 *)(ulonglong)(iVar8 + 0x3a);
      local_2d8 = 0;
      local_308 = 0;
      local_2d4 = 0;
      uStack_2d0 = 0;
      local_304 = 0;
      uVar29 = 0x2b6;
      uVar17 = CONCAT44(uVar28,0x520004);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar17,CONCAT44(uVar30,0xd),0x590008,
                 0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
      FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_308);
      FUN_2b6e6c90000(&local_2d8);
      FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d42100);
      FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d42110);
      iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
      if (iVar7 < 0) {
        uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                   CONCAT44(uVar29,0x66),0x520004,0,0x540005,0,0x580007,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,10,0);
      }
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_188);
      (*(code *)0x7ff63a0f3b30)
                (0x2b6e1db7188,uVar10,&local_2e8,0x3f5,(ulonglong)local_2f0 & 0xffffffff);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,&local_1a8);
      (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
      (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,local_c0);
      puVar20 = &local_108;
      local_e8 = 0;
      local_108 = 0;
      uStack_100 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      FUN_2b6e6c90d90(puVar20,0x2b6e6cab320,0,0x2b6e6d42120);
      FUN_2b6e6c90d90((longlong)&uStack_100 + 4,0x2b6e6cab360,0,0x2b6e6d42130);
      FUN_2b6e6c90d90(&uStack_f0,0x2b6e6cab398,0,0x2b6e6d42140);
      local_228 = 0;
      local_224 = 0;
      if (local_254 == &DAT_2b6e6caaf2c) {
LAB_2b6e6ca199f:
        uVar10 = 0x2b6e6cab3c8;
      }
      else {
        uVar10 = 0x2b6e6cab3f8;
        if (local_254 != (undefined1 *)0x0) {
          uVar9 = *(uint *)(local_254 + -4);
          uVar18 = _DAT_2b6e6caaf28;
          if (uVar9 < _DAT_2b6e6caaf28) {
            uVar18 = uVar9;
          }
          iVar7 = uVar9 - _DAT_2b6e6caaf28;
          if (uVar18 != 0) {
            uVar12 = 0;
            do {
              uVar16 = *(ushort *)(local_254 + uVar12 * 2);
              uVar3 = *(ushort *)(&DAT_2b6e6caaf2c + uVar12 * 2);
              uVar12 = uVar12 + 1;
              if (uVar18 <= uVar12) break;
            } while (uVar16 == uVar3);
            if (uVar16 != uVar3) {
              iVar7 = (uint)uVar16 - (uint)uVar3;
            }
          }
          if (iVar7 == 0) goto LAB_2b6e6ca199f;
        }
      }
      FUN_2b6e6c90d90(&local_228,uVar10,0,0x2b6e6d42150);
      uVar10 = local_2f8;
      if (local_254 == &DAT_2b6e6caaf2c) {
        local_288 = 0xffbf00;
        cVar6 = DAT_2b6e6d4331a;
LAB_2b6e6ca1a95:
        if (cVar6 == '\0') {
          local_288 = 0;
        }
      }
      else {
        if (local_254 == (undefined1 *)0x0) {
          local_288 = 0x8515c7;
          cVar6 = DAT_2b6e6d4331b;
          goto LAB_2b6e6ca1a95;
        }
        uVar9 = *(uint *)(local_254 + -4);
        uVar18 = _DAT_2b6e6caaf28;
        if (uVar9 < _DAT_2b6e6caaf28) {
          uVar18 = uVar9;
        }
        iVar7 = uVar9 - _DAT_2b6e6caaf28;
        if (uVar18 != 0) {
          uVar12 = 0;
          do {
            uVar16 = *(ushort *)(local_254 + uVar12 * 2);
            uVar3 = *(ushort *)(&DAT_2b6e6caaf2c + uVar12 * 2);
            uVar12 = uVar12 + 1;
            if (uVar18 <= uVar12) break;
          } while (uVar16 == uVar3);
          if (uVar16 != uVar3) {
            iVar7 = (uint)uVar16 - (uint)uVar3;
          }
        }
        uVar15 = 0xffbf00;
        if (DAT_2b6e6d4331a == '\0') {
          uVar15 = 0;
        }
        local_288 = 0x8515c7;
        if (DAT_2b6e6d4331b == '\0') {
          local_288 = 0;
        }
        if (iVar7 == 0) {
          local_288 = uVar15;
        }
      }
      lVar19 = -3;
      uVar12 = (ulonglong)(uint)((int)local_230 + 0x4a + (int)local_270);
      do {
        local_2d8 = 0;
        local_308 = 0;
        local_2d4 = 0;
        uStack_2d0 = 0;
        local_304 = 0;
        uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),0x520004);
        uVar29 = 0x2b6;
        local_2f0 = puVar20;
        local_280 = uVar12;
        local_270 = lVar19;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa638,uVar17,(int)lVar19 + 0xb,0x590008,
                   0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
        FUN_2b6e6c90d90(&local_2d8,0x2b6e6d43d3c,1,0x2b6e6d41650);
        FUN_2b6e6c90d90(&local_308,&local_2d8,0,0x2b6e6d41660);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_308,1,0x2b6e6d41670);
        FUN_2b6e6c90000(&local_308);
        FUN_2b6e6c90000(&local_308);
        FUN_2b6e6c90000(&local_2d8);
        FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d42160);
        FUN_2b6e6c90d90(&local_2e8,&local_2a0,0,0x2b6e6d42170);
        iVar7 = (*(code *)0x7ff63a0f4840)(0x2b6e1db7188,uVar10,&local_2e8);
        if (iVar7 < 0) {
          uVar17 = CONCAT44(uVar28,0x590008);
          (*(code *)0x7ff63a0e49f0)
                    (0x2b6e1db7188,0x112,6,0x550005,uVar10,uVar17,&local_2e8,0x520004,
                     CONCAT44(uVar29,0x66),0x520004,0,0x540005,0,0x580007,0);
          uVar28 = (undefined4)((ulonglong)uVar17 >> 0x20);
          (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,10,0);
        }
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x402,0);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f4,local_188);
        uVar12 = local_280;
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3f5,local_280);
        puVar20 = local_2f0;
        local_180 = 0;
        local_17c = 0;
        uVar17 = CONCAT44(uVar28,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6cab430,uVar17,&local_228,0x590008,local_2f0)
        ;
        FUN_2b6e6c90d90(&local_2a0,0x2b6e6d43d3c,1,0x2b6e6d42180);
        FUN_2b6e6c90d90(&local_180,&local_2a0,0,0x2b6e6d42190);
        (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,6,&local_180);
        (*(code *)0x7ff63a0f3c80)(0x2b6e1db7188,uVar10,&local_2e8,0x3e9,0x2b6e6cab200);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0x3ea,local_290);
        (*(code *)0x7ff63a0f3b30)(0x2b6e1db7188,uVar10,&local_2e8,0,local_288);
        FUN_2b6e6c90000(&local_180);
        uVar12 = uVar12 + 0xe;
        puVar20 = (undefined8 *)((longlong)puVar20 + 0xc);
        lVar19 = local_270 + 1;
      } while (lVar19 != 0);
      FUN_2b6e6c90000(&local_228);
      lVar19 = -0x24;
      do {
        if ((((*(int *)((longlong)&iStack_e4 + lVar19) != 0) &&
             (lVar11 = *(longlong *)((longlong)alStack_e0 + lVar19), lVar11 != 0)) &&
            ((int *)(lVar11 + -0xc) != (int *)0x0)) && (*(int *)(lVar11 + -0xc) != 0)) {
          piVar2 = (int *)(lVar11 + -8);
          *piVar2 = *piVar2 + -1;
          if (*piVar2 == 0) {
            (*(code *)0x7ff63a101200)(0x2b6e1db7188);
          }
        }
        *(undefined8 *)((longlong)alStack_e0 + lVar19) = 0;
        *(undefined4 *)((longlong)&iStack_e4 + lVar19) = 0;
        lVar19 = lVar19 + 0xc;
      } while (lVar19 != 0);
      FUN_2b6e6c90000(&local_218);
      FUN_2b6e6c90000(&local_208);
      FUN_2b6e6c90000(&local_170);
      FUN_2b6e6c90000(&local_160);
      FUN_2b6e6c90000(&local_150);
      FUN_2b6e6c90000(&local_2e8);
      FUN_2b6e6c90000(&local_1f8);
      FUN_2b6e6c90000(&local_1e8);
      FUN_2b6e6c90000(&local_1d8);
      FUN_2b6e6c90000(&local_1c8);
      FUN_2b6e6c90000(&local_1b8);
      FUN_2b6e6c90000(&local_1a8);
      FUN_2b6e6c90000(&local_198);
      FUN_2b6e6c90000(&local_268);
      puVar34 = &local_258;
LAB_2b6e6ca201f:
      FUN_2b6e6c90000(puVar34);
      FUN_2b6e6c90000(&local_2a0);
      return;
    }
    uVar16 = local_2d8._2_2_;
    if ((local_2d8 & 0xf0000) != 0) {
      uVar16 = local_2d8._2_2_ | 0x10;
      local_2d8 = local_2d8 | 0x100000;
    }
    uVar12 = (ulonglong)uStack_2d0;
    if (uVar12 == 0) goto LAB_2b6e6ca211f;
    uVar18 = uVar9 - 1;
    lVar19 = 0;
    if ((uVar16 & 0x10) != 0) {
      lVar19 = uVar12 - 1;
    }
    if (uVar18 < uStack_2d0) {
      lVar19 = lVar19 * 0x3c;
      lVar11 = CONCAT44(local_2b8,uStack_2bc);
      uVar32 = ~(ulonglong)uVar18 + uVar12;
      if ((uVar16 & 0x10) == 0) {
        uVar32 = (ulonglong)uVar18;
      }
      dVar22 = *(double *)(lVar11 + 0x20 + lVar19);
      dVar26 = *(double *)(lVar11 + 0x10 + lVar19);
      dVar25 = *(double *)(lVar11 + 0x18 + lVar19);
      if ((uVar16 & 0x10) == 0) {
        if (uStack_2d0 - 1 <= uVar9 - 2) goto LAB_2b6e6ca215f;
        lVar19 = (ulonglong)uVar9 - 1;
        pdVar14 = (double *)(lVar11 + 0x54);
        do {
          pdVar1 = pdVar14 + -1;
          dVar24 = *pdVar14;
          pdVar14 = (double *)((longlong)pdVar14 + 0x3c);
          lVar19 = lVar19 + -1;
          dVar23 = *pdVar1;
          if (*pdVar1 <= dVar26) {
            dVar23 = dVar26;
          }
          if (dVar25 <= dVar24) {
            dVar24 = dVar25;
          }
          dVar25 = dVar24;
          dVar26 = dVar23;
        } while (lVar19 != 0);
      }
      else {
        if (uStack_2d0 - 1 <= uVar9 - 2) goto LAB_2b6e6ca215f;
        lVar19 = (ulonglong)uVar9 - 1;
        pdVar14 = (double *)(uVar12 * 0x3c + -0x60 + lVar11);
        do {
          pdVar1 = pdVar14 + -1;
          dVar24 = *pdVar14;
          pdVar14 = (double *)((longlong)pdVar14 + -0x3c);
          lVar19 = lVar19 + -1;
          dVar23 = *pdVar1;
          if (*pdVar1 <= dVar26) {
            dVar23 = dVar26;
          }
          if (dVar25 <= dVar24) {
            dVar24 = dVar25;
          }
          dVar25 = dVar24;
          dVar26 = dVar23;
        } while (lVar19 != 0);
      }
      dVar23 = dVar23 - dVar24;
      if (dVar23 <= 0.0) {
        uVar10 = 0x2b6e6caacb8;
        uVar17 = 0x2b6e6d41d30;
      }
      else {
        dVar26 = (dVar22 - *(double *)(lVar11 + 0x20 + uVar32 * 0x3c)) / dVar23;
        if (_DAT_2b6e6ca89f0 <= (double)(_DAT_2b6e6ca89e0 & (ulonglong)dVar26)) {
          if (dVar26 <= 0.0) {
            uVar10 = 0x2b6e6caaf08;
            uVar17 = 0x2b6e6d41d80;
          }
          else {
            uVar10 = 0x2b6e6caae88;
            uVar17 = 0x2b6e6d41d70;
          }
        }
        else if (_DAT_2b6e6ca89f8 * dVar23 + dVar24 <= dVar22) {
          if (dVar22 <= dVar24 + dVar23 * _DAT_2b6e6ca8a00) {
            uVar10 = 0x2b6e6caae10;
            uVar17 = 0x2b6e6d41d60;
          }
          else {
            uVar10 = 0x2b6e6caada0;
            uVar17 = 0x2b6e6d41d50;
          }
        }
        else {
          uVar10 = 0x2b6e6caad28;
          uVar17 = 0x2b6e6d41d40;
        }
      }
      goto LAB_2b6e6c9dc90;
    }
  }
  else {
    if ((local_13e & 0xf) != 0) {
      local_13e = local_13e | 0x10;
    }
    uVar12 = local_138 & 0xffffffff;
    if (uVar12 == 0) {
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x16015e000901f6);
    }
    else {
      lVar19 = 0;
      if ((local_13e & 0x10) != 0) {
        lVar19 = uVar12 - 1;
      }
      if (uVar12 != 1) {
        lVar11 = 1;
        if ((local_13e & 0x10) != 0) {
          lVar11 = uVar12 - 2;
        }
        dVar22 = *(double *)(CONCAT44(local_120,uStack_124) + 0x20 + lVar11 * 0x3c);
        uVar30 = SUB84(dVar22,0);
        uVar31 = (undefined4)((ulonglong)dVar22 >> 0x20);
        dVar26 = *(double *)(CONCAT44(local_120,uStack_124) + 0x20 + lVar19 * 0x3c);
        uVar28 = SUB84(dVar26,0);
        uVar29 = (undefined4)((ulonglong)dVar26 >> 0x20);
        dVar37 = 0.0;
        dVar27 = 0.0;
        if (0.0 < dVar22) {
          dVar37 = (dVar26 - dVar22) / _DAT_2b6e6d43d18;
          dVar27 = ((dVar26 - dVar22) / dVar22) * _DAT_2b6e6ca89c0;
        }
        goto LAB_2b6e6c9c775;
      }
    }
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x16015f000901f6);
LAB_2b6e6ca211f:
    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x190100000901f6);
  }
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x190101000901f6);
LAB_2b6e6ca215f:
  (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0xb0106000901f6);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



/* Address: 2b6e6ca2180 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6ca2180(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  ulonglong in_stack_fffffffffffffee8;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  uint local_bc;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  ulonglong local_98;
  int local_8c;
  longlong local_88;
  longlong local_80;
  
  local_c8 = 0;
  local_c4 = 0;
  local_b8 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  if ((DAT_2b6e6d432b4 == '\x01') && (0 < _DAT_2b6e6d43730)) {
    lVar10 = 0;
    lVar7 = 0;
    lVar8 = 0;
    do {
      local_88 = lVar10;
      if (lVar8 == 0x10) {
        (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1c031f000901f6);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      local_98 = *(ulonglong *)(&DAT_2b6e6d43330 + lVar7);
      local_a8 = *(undefined8 *)(&DAT_2b6e6d43338 + lVar7);
      local_a0 = *(undefined8 *)(&DAT_2b6e6d43340 + lVar7);
      uVar11 = *(undefined8 *)(&DAT_2b6e6d434b0 + lVar7);
      uVar1 = *(undefined8 *)(&DAT_2b6e6d434b8 + lVar7);
      uVar2 = *(undefined8 *)(&DAT_2b6e6d434c0 + lVar7);
      local_8c = (uint)DAT_2b6e6d432b7 * 2;
      local_bc = (uint)DAT_2b6e6d432b6;
      uVar4 = 0;
      if (DAT_2b6e6d432b5 != '\0') {
        uVar4 = 0x908070;
      }
      local_b0 = lVar8;
      local_80 = lVar7;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,(int)lVar8,0x520004,
                 in_stack_fffffffffffffee8 & 0xffffffff00000000,0x590008,0x2b6e6d43d28,0x520004,
                 _DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421e0);
      FUN_2b6e6c9bf90(&local_c8,local_98,(int)uVar11,local_a8,uVar1,uVar4,local_bc,local_8c,1);
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      uVar5 = (uint)DAT_2b6e6d432b7;
      local_bc = (uint)DAT_2b6e6d432b6;
      uVar4 = 0;
      if (DAT_2b6e6d432b5 != '\0') {
        uVar4 = 0x908070;
      }
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,(int)local_b0,0x520004,1,
                 0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421f0);
      FUN_2b6e6c9bf90(&local_c8,local_a8,(int)uVar1,local_a0,uVar2,uVar4,local_bc,uVar5 * 2,1);
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      uVar12 = 0x2b6;
      uVar5 = (uint)DAT_2b6e6d432b7;
      local_a8 = CONCAT44(local_a8._4_4_,(uint)DAT_2b6e6d432b6);
      uVar4 = 0;
      if (DAT_2b6e6d432b5 != '\0') {
        uVar4 = 0x908070;
      }
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,(int)local_b0,0x520004,2,
                 0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42200);
      FUN_2b6e6c9bf90(&local_c8,local_a0,(int)uVar2,local_98,uVar11,uVar4,(undefined4)local_a8,
                      uVar5 * 2,1);
      lVar10 = local_88;
      if (DAT_2b6e6d43310 == '\x01') {
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        in_stack_fffffffffffffee8 = 0x2b6e6d43d28;
        uVar4 = 0;
        if (DAT_2b6e6d43311 != '\0') {
          uVar4 = 0xdec4b0;
        }
        uVar11 = *(undefined8 *)(&DAT_2b6e6d436b0 + local_88);
        local_98 = CONCAT44(local_98._4_4_,uVar4);
        local_a0 = *(undefined8 *)(&DAT_2b6e6d43630 + local_88);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa468,0x520004,(int)local_b0,0x590008,
                   0x2b6e6d43d28,0x520004,CONCAT44(uVar12,_DAT_2b6e6d43d24));
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41530);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41540);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41550);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42210);
        FUN_2b6e6c9c1f0(&local_c8,local_a0,(int)uVar11,local_98 & 0xffffffff);
      }
      else {
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        in_stack_fffffffffffffee8 = 0x2b6e6d43d28;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa468,0x520004,(int)local_b0,0x590008,
                   0x2b6e6d43d28,0x520004,CONCAT44(uVar12,_DAT_2b6e6d43d24));
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41530);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41540);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41550);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42220);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
        lVar10 = local_88;
      }
      lVar10 = lVar10 + 8;
      uVar6 = (ulonglong)_DAT_2b6e6d43730;
      lVar8 = local_b0 + 1;
      lVar7 = local_80 + 0x18;
    } while (lVar8 < (longlong)uVar6);
    if (_DAT_2b6e6d43730 < 0x10) {
      do {
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        iVar9 = (int)uVar6;
        in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,
                   in_stack_fffffffffffffee8,0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        uVar4 = (undefined4)(in_stack_fffffffffffffee8 >> 0x20);
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42230);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        uVar11 = CONCAT44(uVar4,1);
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,uVar11,
                   0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42240);
        uVar11 = local_b8;
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        uVar12 = 0x2b6;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,
                   CONCAT44(uVar4,2),0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42250);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,uVar11,&local_c8);
        local_e8 = 0;
        local_d8 = 0;
        local_e4 = 0;
        local_d4 = 0;
        in_stack_fffffffffffffee8 = 0x2b6e6d43d28;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa468,0x520004,iVar9,0x590008,0x2b6e6d43d28
                   ,0x520004,CONCAT44(uVar12,_DAT_2b6e6d43d24));
        FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41530);
        FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41540);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41550);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_d8);
        FUN_2b6e6c90000(&local_e8);
        FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42260);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,uVar11,&local_c8);
        uVar6 = (ulonglong)(iVar9 + 1U);
      } while (iVar9 + 1U != 0x10);
    }
  }
  else {
    iVar9 = 0;
    do {
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,
                 in_stack_fffffffffffffee8,0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      uVar4 = (undefined4)(in_stack_fffffffffffffee8 >> 0x20);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421a0);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      uVar11 = CONCAT44(uVar4,1);
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,uVar11,0x590008
                 ,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421b0);
      uVar11 = local_b8;
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      uVar12 = 0x2b6;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa420,0x520004,iVar9,0x520004,
                 CONCAT44(uVar4,2),0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41500);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41510);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41520);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421c0);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,uVar11,&local_c8);
      local_e8 = 0;
      local_d8 = 0;
      local_e4 = 0;
      local_d4 = 0;
      in_stack_fffffffffffffee8 = 0x2b6e6d43d28;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa468,0x520004,iVar9,0x590008,0x2b6e6d43d28,
                 0x520004,CONCAT44(uVar12,_DAT_2b6e6d43d24));
      FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d3c,1,0x2b6e6d41530);
      FUN_2b6e6c90d90(&local_d8,&local_e8,0,0x2b6e6d41540);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_d8,1,0x2b6e6d41550);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d421d0);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,uVar11,&local_c8);
      iVar9 = iVar9 + 1;
    } while (iVar9 != 0x10);
  }
  FUN_2b6e6c90000(&local_c8);
  return;
}



/* Address: 2b6e6ca3560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6ca3560(void)

{
  double dVar1;
  code *pcVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  int iVar12;
  undefined8 uVar13;
  longlong lVar14;
  bool bVar15;
  double dVar16;
  undefined4 local_118;
  undefined8 local_114;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  longlong local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  
  local_f8 = 0;
  local_d8 = 0;
  local_f4 = 0;
  local_d4 = 0;
  local_e0 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  dVar8 = _DAT_2b6e6ca8be0;
  dVar7 = _DAT_2b6e6ca8bd8;
  dVar6 = _DAT_2b6e6ca8bd0;
  dVar5 = _DAT_2b6e6ca8bc8;
  if (((DAT_2b6e6d432b8 == '\x01') && (0 < _DAT_2b6e6d43730)) && ((DAT_2b6e6d432d0 & 1) != 0)) {
    lVar14 = 0;
    dVar4 = _DAT_2b6e6d43308 * _DAT_2b6e6d43d18;
    dVar3 = _DAT_2b6e6d43d18 * _DAT_2b6e6d432c0 * _DAT_2b6e6ca8bc0;
    do {
      if (lVar14 == 0x10) {
        (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x200351000901f6);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      iVar9 = 0;
      iVar12 = (int)lVar14;
      if (DAT_2b6e6d432d0 == 1) {
        dVar1 = *(double *)(&DAT_2b6e6d436b0 + lVar14 * 8);
        local_e8 = lVar14 * 3;
        uVar10 = 0;
        do {
          local_d8 = 0;
          local_108 = 0;
          local_118 = 0;
          local_d4 = 0;
          local_104 = 0;
          local_114 = 0;
          (*(code *)0x7ff63a0e49f0)
                    (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa4c0,0x520004,iVar12,0x520004,uVar10,
                     0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
          FUN_2b6e6c90d90(&local_108,0x2b6e6d43d3c,1,0x2b6e6d41560);
          FUN_2b6e6c90d90(&local_118,&local_108,0,0x2b6e6d41570);
          FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_118,1,0x2b6e6d41580);
          FUN_2b6e6c90000(&local_118);
          FUN_2b6e6c90000(&local_118);
          FUN_2b6e6c90000(&local_108);
          FUN_2b6e6c90d90(&local_f8,0x2b6e6d43d3c,1,0x2b6e6d42280);
          FUN_2b6e6c90d90(&local_d8,&local_f8,0,0x2b6e6d42290);
          dVar16 = dVar6;
          if (DAT_2b6e6d432d0 == 0) {
            dVar16 = dVar7;
          }
          dVar16 = (double)(*(code *)0x7ff63a3de390)
                                     (((double)(int)uVar10 + (double)(int)uVar10) / dVar16 +
                                      _DAT_2b6e6d43740 + (double)iVar12 * dVar5);
          uVar13 = 0;
          if (DAT_2b6e6d432b9 != '\0') {
            uVar13 = 0xffbf00;
          }
          FUN_2b6e6c9c1f0(&local_d8,
                          (longlong)
                          ((double)(*(longlong *)(&DAT_2b6e6d43338 + local_e8 * 8) -
                                   *(longlong *)(&DAT_2b6e6d43330 + local_e8 * 8)) *
                          (dVar16 * dVar8 + dVar8)) + *(longlong *)(&DAT_2b6e6d43330 + local_e8 * 8)
                          ,dVar3 * dVar16 + dVar1 + dVar4,uVar13);
          FUN_2b6e6c90000(&local_d8);
        } while (((DAT_2b6e6d432d0 & 1) != 0) && (bVar15 = uVar10 < 2, uVar10 = uVar10 + 1, bVar15))
        ;
        iVar9 = (DAT_2b6e6d432d0 & 1) * 3;
      }
      do {
        local_108 = 0;
        local_118 = 0;
        local_104 = 0;
        local_114 = 0;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa4c0,0x520004,iVar12,0x520004,iVar9,
                   0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        FUN_2b6e6c90d90(&local_108,0x2b6e6d43d3c,1,0x2b6e6d41560);
        FUN_2b6e6c90d90(&local_118,&local_108,0,0x2b6e6d41570);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_118,1,0x2b6e6d41580);
        FUN_2b6e6c90000(&local_118);
        FUN_2b6e6c90000(&local_118);
        FUN_2b6e6c90000(&local_108);
        FUN_2b6e6c90d90(&local_f8,0x2b6e6d43d3c,1,0x2b6e6d422a0);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_e0,&local_f8);
        iVar9 = iVar9 + 1;
      } while (iVar9 != 10);
      lVar14 = lVar14 + 1;
      uVar11 = (ulonglong)_DAT_2b6e6d43730;
    } while (lVar14 < (longlong)uVar11);
    if (_DAT_2b6e6d43730 < 0x10) {
      do {
        iVar9 = 0;
        do {
          local_108 = 0;
          local_118 = 0;
          local_104 = 0;
          local_114 = 0;
          (*(code *)0x7ff63a0e49f0)
                    (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa4c0,0x520004,(int)uVar11,0x520004,iVar9
                     ,0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
          FUN_2b6e6c90d90(&local_108,0x2b6e6d43d3c,1,0x2b6e6d41560);
          FUN_2b6e6c90d90(&local_118,&local_108,0,0x2b6e6d41570);
          FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_118,1,0x2b6e6d41580);
          FUN_2b6e6c90000(&local_118);
          FUN_2b6e6c90000(&local_118);
          FUN_2b6e6c90000(&local_108);
          FUN_2b6e6c90d90(&local_f8,0x2b6e6d43d3c,1,0x2b6e6d422b0);
          (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_e0,&local_f8);
          iVar9 = iVar9 + 1;
        } while (iVar9 != 10);
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
      } while (uVar10 != 0x10);
    }
  }
  else {
    iVar9 = 0;
    do {
      iVar12 = 0;
      local_e8 = CONCAT44(local_e8._4_4_,iVar9);
      do {
        local_108 = 0;
        local_118 = 0;
        local_104 = 0;
        local_114 = 0;
        (*(code *)0x7ff63a0e49f0)
                  (0x2b6e1db7188,0xd8,5,0x590008,0x2b6e6caa4c0,0x520004,iVar9,0x520004,iVar12,
                   0x590008,0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
        FUN_2b6e6c90d90(&local_108,0x2b6e6d43d3c,1,0x2b6e6d41560);
        FUN_2b6e6c90d90(&local_118,&local_108,0,0x2b6e6d41570);
        FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_118,1,0x2b6e6d41580);
        FUN_2b6e6c90000(&local_118);
        FUN_2b6e6c90000(&local_118);
        FUN_2b6e6c90000(&local_108);
        FUN_2b6e6c90d90(&local_f8,0x2b6e6d43d3c,1,0x2b6e6d42270);
        (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_e0,&local_f8);
        iVar12 = iVar12 + 1;
        iVar9 = (int)local_e8;
      } while (iVar12 != 10);
      iVar9 = (int)local_e8 + 1;
    } while (iVar9 != 0x10);
  }
  FUN_2b6e6c90000(&local_f8);
  return;
}



/* Address: 2b6e6ca3f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6ca3f10(void)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  double dVar13;
  double dVar14;
  ulonglong uVar15;
  undefined4 local_110;
  undefined8 local_10c;
  undefined4 local_100;
  undefined8 local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined8 local_d0;
  longlong local_c8;
  undefined8 local_c0;
  
  local_f0 = 0;
  local_e0 = 0;
  local_ec = 0;
  local_dc = 0;
  local_d0 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  dVar8 = _DAT_2b6e6ca8bf8;
  dVar7 = _DAT_2b6e6ca8bf0;
  dVar6 = _DAT_2b6e6ca8be8;
  if (((DAT_2b6e6d432d1 == '\x01') && (0 < _DAT_2b6e6d43730)) && ((DAT_2b6e6d432d4 & 1) != 0)) {
    if (0xf < _DAT_2b6e6d43730 - 1U) {
      (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1e037c000901f6);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uVar15 = (ulonglong)(_DAT_2b6e6d43730 - 1U);
    uVar12 = 0;
    local_c0 = *(undefined8 *)(&DAT_2b6e6d43630 + uVar15 * 8);
    dVar4 = _DAT_2b6e6d43308 * _DAT_2b6e6d43d18 + *(double *)(&DAT_2b6e6d436b0 + uVar15 * 8);
    local_c8 = uVar15 * 3;
    dVar5 = _DAT_2b6e6d43d18 * _DAT_2b6e6d432d8;
    do {
      uVar15 = 0x2b6e6d43d28;
      local_e0 = 0;
      local_100 = 0;
      local_110 = 0;
      local_dc = 0;
      local_fc = 0;
      local_10c = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa508,0x520004,uVar12,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_100,0x2b6e6d43d3c,1,0x2b6e6d41590);
      FUN_2b6e6c90d90(&local_110,&local_100,0,0x2b6e6d415a0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_110,1,0x2b6e6d415b0);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_100);
      FUN_2b6e6c90d90(&local_f0,0x2b6e6d43d3c,1,0x2b6e6d422d0);
      FUN_2b6e6c90d90(&local_e0,&local_f0,0,0x2b6e6d422e0);
      dVar14 = dVar7;
      if (DAT_2b6e6d432d4 == 0) {
        dVar14 = 0.0;
      }
      dVar14 = ((double)(int)uVar12 * dVar6) / dVar14 + _DAT_2b6e6d43748;
      dVar13 = (double)(*(code *)0x7ff63a3de390)(dVar14);
      lVar1 = *(longlong *)(&DAT_2b6e6d43330 + local_c8 * 8);
      lVar2 = *(longlong *)(&DAT_2b6e6d43340 + local_c8 * 8);
      dVar14 = (double)(*(code *)0x7ff63a3d72c0)(dVar14);
      uVar9 = 0;
      if (DAT_2b6e6d432d2 != '\0') {
        uVar9 = 0xff901e;
      }
      FUN_2b6e6c9bf90(&local_e0,local_c0,dVar4,
                      (longlong)((double)(lVar2 - lVar1) * (dVar14 * dVar8 + dVar8)) + lVar1,
                      dVar13 * dVar5 + dVar4,uVar9,(uint)DAT_2b6e6d432d3 * 2,0,
                      uVar15 & 0xffffffffffffff00);
      FUN_2b6e6c90000(&local_e0);
      uVar12 = uVar12 + 1;
      uVar10 = (uint)DAT_2b6e6d432d4 + (uint)DAT_2b6e6d432d4 * 4;
    } while (uVar12 < uVar10);
    do {
      local_100 = 0;
      local_110 = 0;
      local_fc = 0;
      local_10c = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa508,0x520004,uVar10,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_100,0x2b6e6d43d3c,1,0x2b6e6d41590);
      FUN_2b6e6c90d90(&local_110,&local_100,0,0x2b6e6d415a0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_110,1,0x2b6e6d415b0);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_100);
      FUN_2b6e6c90d90(&local_f0,0x2b6e6d43d3c,1,0x2b6e6d422f0);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_d0,&local_f0);
      uVar10 = uVar10 + 1;
    } while (uVar10 != 0x10);
  }
  else {
    iVar11 = 0;
    do {
      local_100 = 0;
      local_110 = 0;
      local_fc = 0;
      local_10c = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa508,0x520004,iVar11,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_100,0x2b6e6d43d3c,1,0x2b6e6d41590);
      FUN_2b6e6c90d90(&local_110,&local_100,0,0x2b6e6d415a0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_110,1,0x2b6e6d415b0);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_110);
      FUN_2b6e6c90000(&local_100);
      FUN_2b6e6c90d90(&local_f0,0x2b6e6d43d3c,1,0x2b6e6d422c0);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_d0,&local_f0);
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0x10);
  }
  FUN_2b6e6c90000(&local_f0);
  return;
}



/* Address: 2b6e6ca4650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6ca4650(void)

{
  double dVar1;
  double dVar2;
  code *pcVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  undefined4 uVar9;
  longlong lVar10;
  double dVar11;
  double dVar12;
  ulonglong uVar13;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  uint local_bc;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  
  local_c8 = 0;
  local_c4 = 0;
  local_b8 = (*(code *)0x7ff63a0f5790)(0x2b6e1db7188);
  if ((DAT_2b6e6d432e8 == '\x01') && (1 < _DAT_2b6e6d43730)) {
    lVar8 = -0xf;
    dVar5 = _DAT_2b6e6d43308 * _DAT_2b6e6d43d18;
    dVar4 = _DAT_2b6e6d43d18 * _DAT_2b6e6d432f0;
    lVar10 = 0;
    do {
      if (lVar8 == 0) {
        (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x1f03aa000901f6);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      local_b0 = lVar10 + 1;
      local_a8 = *(undefined8 *)(lVar8 * 8 + 0x2b6e6d436a8);
      dVar1 = *(double *)(lVar8 * 8 + 0x2b6e6d43728);
      local_a0 = *(undefined8 *)(&DAT_2b6e6d436b0 + lVar8 * 8);
      dVar2 = *(double *)(&DAT_2b6e6d43730 + lVar8 * 8);
      dVar12 = (double)(int)local_b0 * _DAT_2b6e6d43300 + _DAT_2b6e6d43750;
      dVar11 = (double)(*(code *)0x7ff63a3de390)
                                 ((double)(int)lVar10 * _DAT_2b6e6d43300 + _DAT_2b6e6d43750);
      dVar12 = (double)(*(code *)0x7ff63a3de390)(dVar12);
      local_d8 = 0;
      local_e8 = 0;
      local_d4 = 0;
      local_e4 = 0;
      uVar13 = 0x2b6e6d43d28;
      local_bc = (uint)DAT_2b6e6d432eb;
      uVar7 = (uint)DAT_2b6e6d432ea;
      uVar9 = 0;
      if (DAT_2b6e6d432e9 != '\0') {
        uVar9 = 0xffbf00;
      }
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa558,0x520004,(int)lVar10,0x590008,
                 0x2b6e6d43d28,0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_d8,0x2b6e6d43d3c,1,0x2b6e6d415c0);
      FUN_2b6e6c90d90(&local_e8,&local_d8,0,0x2b6e6d415d0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_e8,1,0x2b6e6d415e0);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42310);
      FUN_2b6e6c9bf90(&local_c8,local_a8,dVar1 + dVar5 + dVar11 * dVar4,local_a0,
                      dVar12 * dVar4 + dVar2 + dVar5,uVar9,uVar7 * 2,local_bc,
                      uVar13 & 0xffffffffffffff00);
      lVar8 = lVar8 + 1;
      lVar10 = local_b0;
    } while (local_b0 < _DAT_2b6e6d43730 + -1);
    iVar6 = _DAT_2b6e6d43730 + -2;
    do {
      iVar6 = iVar6 + 1;
      local_d8 = 0;
      local_e8 = 0;
      local_d4 = 0;
      local_e4 = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa558,0x520004,iVar6,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_d8,0x2b6e6d43d3c,1,0x2b6e6d415c0);
      FUN_2b6e6c90d90(&local_e8,&local_d8,0,0x2b6e6d415d0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_e8,1,0x2b6e6d415e0);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42320);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
    } while (iVar6 < 0xf);
  }
  else {
    iVar6 = 0;
    do {
      local_d8 = 0;
      local_e8 = 0;
      local_d4 = 0;
      local_e4 = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,4,0x590008,0x2b6e6caa558,0x520004,iVar6,0x590008,0x2b6e6d43d28,
                 0x520004,_DAT_2b6e6d43d24);
      FUN_2b6e6c90d90(&local_d8,0x2b6e6d43d3c,1,0x2b6e6d415c0);
      FUN_2b6e6c90d90(&local_e8,&local_d8,0,0x2b6e6d415d0);
      FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_e8,1,0x2b6e6d415e0);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_e8);
      FUN_2b6e6c90000(&local_d8);
      FUN_2b6e6c90d90(&local_c8,0x2b6e6d43d3c,1,0x2b6e6d42300);
      (*(code *)0x7ff63a0f4ce0)(0x2b6e1db7188,local_b8,&local_c8);
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
  }
  FUN_2b6e6c90000(&local_c8);
  return;
}



/* Address: 2b6e6ca4cf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b6e6ca4cf0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  
  uVar9 = _DAT_2b6e6d43d20;
  local_d8 = 0;
  local_d4 = 0;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,4);
  uVar2 = _DAT_2b6e6d43d20;
  dVar14 = _DAT_2b6e6d43d48;
  if ((longlong)_DAT_2b6e6d43d48 != -0x8000000000000000) {
    dVar14 = (double)(longlong)_DAT_2b6e6d43d48;
    uVar6 = 0xb;
    if (uVar9 < 0xb) {
      uVar6 = (ulonglong)uVar9;
    }
    dVar14 = (double)(longlong)
                     ((_DAT_2b6e6d43d48 - dVar14) * *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) +
                     *(double *)((ulonglong)(0.0 < _DAT_2b6e6d43d48) * 8 + 0x2b6e6ca8c00)) /
             *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) + dVar14;
  }
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,1);
  dVar15 = _DAT_2b6e6d43d48;
  if ((longlong)_DAT_2b6e6d43d48 != -0x8000000000000000) {
    dVar15 = (double)(longlong)_DAT_2b6e6d43d48;
    uVar6 = 0xb;
    if (uVar2 < 0xb) {
      uVar6 = (ulonglong)uVar2;
    }
    dVar15 = (double)(longlong)
                     ((_DAT_2b6e6d43d48 - dVar15) * *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) +
                     *(double *)((ulonglong)(0.0 < _DAT_2b6e6d43d48) * 8 + 0x2b6e6ca8c00)) /
             *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) + dVar15;
  }
  if (param_1 == 2) {
    local_e8 = 0;
    local_b8 = 0;
    local_e4 = 0;
    local_b4 = 0;
    dVar14 = dVar15;
    if ((longlong)dVar15 != -0x8000000000000000) {
      dVar14 = (double)(longlong)dVar15;
      uVar6 = 0xb;
      if (_DAT_2b6e6d43d20 < 0xb) {
        uVar6 = (ulonglong)_DAT_2b6e6d43d20;
      }
      dVar14 = (double)(longlong)
                       ((dVar15 - dVar14) * *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) +
                       *(double *)((ulonglong)(0.0 < dVar15) * 8 + 0x2b6e6ca8c00)) /
               *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) + dVar14;
    }
    if ((DAT_2b6e6d43e88 == '\x01') && (0 < _DAT_2b6e6d43778)) goto LAB_2b6e6ca54df;
    lVar5 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,0x2b6e6ca8e30,0x12);
    if (_DAT_2b6e6d43e98 < lVar5) goto LAB_2b6e6ca54df;
    local_c8 = 0;
    local_c4 = 0;
    uVar12 = FUN_2b6e6ca59f0(1,dVar14);
    FUN_2b6e6c90d90(&local_b8,0x2b6e6d43d28,1,0x2b6e6d423d0);
    cVar3 = FUN_2b6e6ca6670(&local_b8,uVar12,1);
    if (cVar3 == '\0') {
LAB_2b6e6ca54d8:
      FUN_2b6e6c90000(&local_c8);
      goto LAB_2b6e6ca54df;
    }
    uVar12 = FUN_2b6e6ca59f0(1);
    cVar3 = FUN_2b6e6ca68f0(uVar12,&local_c8);
    if (cVar3 == '\0') goto LAB_2b6e6ca54d8;
    FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d28,1,0x2b6e6d423e0);
    cVar3 = (*(code *)0x7ff63a107f20)(0x2b6e1db7188,&local_e8);
    if (cVar3 != '\0') {
      (*(code *)0x7ff63a107f70)(0x2b6e1db7188,3);
      if ((_DAT_2b6e6d43d48 == 0.0) && (!NAN(_DAT_2b6e6d43d48))) goto LAB_2b6e6ca54d8;
    }
    FUN_2b6e6ca59f0(1,dVar14);
    cVar3 = FUN_2b6e6ca6c50();
    if (cVar3 == '\0') goto LAB_2b6e6ca54d8;
    cVar3 = FUN_2b6e6ca6dd0();
    if (cVar3 == '\0') goto LAB_2b6e6ca54d8;
    cVar3 = FUN_2b6e6ca6e30();
    FUN_2b6e6c90000(&local_c8);
    FUN_2b6e6c90000(&local_b8);
    FUN_2b6e6c90000(&local_e8);
    if (cVar3 == '\0') goto LAB_2b6e6ca54ed;
    iVar4 = FUN_2b6e6ca5850();
    if (0 < iVar4) goto LAB_2b6e6ca54ed;
    uVar9 = 0;
    FUN_2b6e6c90d90(&local_d8,0x2b6e6d43e20,0,0x2b6e6d423a0);
    uVar2 = _DAT_2b6e6cab468;
    uVar6 = (ulonglong)_DAT_2b6e6cab468;
    if ((uVar6 != 0) || (local_d4 == 0)) {
      if (local_d4 != 0) {
        uVar9 = *(uint *)(local_d4 + -4);
      }
      uVar8 = _DAT_2b6e6cab468 + uVar9;
      uVar7 = 0x104;
      if ((0x103 < uVar8) &&
         ((0x3fffffe7 < uVar8 || (uVar7 = (uVar8 >> 2) + uVar8, 0x3fffffe7 < uVar7)))) {
        uVar7 = 0x3fffffe8;
      }
      cVar3 = FUN_2b6e6c90060(&local_d8,uVar7);
      if (cVar3 == '\0') {
LAB_2b6e6ca582a:
        (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x62000e000a01f9);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (uVar6 != 0) {
        lVar5 = local_d4 + (ulonglong)uVar9 * 2;
        if (uVar2 < 0x10) {
          uVar10 = 0;
        }
        else if (lVar5 - 0x2b6e6cab46cU < 0x20) {
          uVar10 = 0;
        }
        else {
          uVar11 = 0;
          uVar10 = (ulonglong)(uVar2 & 0xfffffff8);
          do {
            uVar12 = *(undefined8 *)(uVar11 + 0x2b6e6cab474);
            *(undefined8 *)(lVar5 + uVar11) = *(undefined8 *)(&DAT_2b6e6cab46c + uVar11);
            ((undefined8 *)(lVar5 + uVar11))[1] = uVar12;
            uVar11 = uVar11 + 0x10;
          } while ((uVar6 * 2 & 0xfffffffffffffff0) != uVar11);
          if (uVar10 == uVar6) goto LAB_2b6e6ca56f2;
        }
        do {
          *(undefined2 *)(lVar5 + uVar10 * 2) = *(undefined2 *)(&DAT_2b6e6cab46c + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar6 != uVar10);
      }
LAB_2b6e6ca56f2:
      *(uint *)(local_d4 + -4) = uVar8;
      *(undefined2 *)(local_d4 + (ulonglong)uVar8 * 2) = 0;
    }
    dVar17 = _DAT_2b6e6d43a70 * _DAT_2b6e6d43d18;
    dVar16 = _DAT_2b6e6d43d18 * _DAT_2b6e6d43a68;
    dVar13 = (double)FUN_2b6e6ca59f0(1,dVar15);
    if (dVar13 <= 0.0) {
LAB_2b6e6ca57f5:
      _DAT_2b6e6d43110 = 0x271e;
      goto LAB_2b6e6ca54ed;
    }
    local_e8 = 0;
    dVar16 = dVar16 + dVar15;
    local_e4 = 0;
    dVar17 = dVar15 - dVar17;
    FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d28,0,0x2b6e6d40998);
    if ((dVar15 == 0.0) && (!NAN(dVar15))) {
      (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,&local_e8,1);
      dVar15 = _DAT_2b6e6d43d48;
    }
    uVar12 = 1;
LAB_2b6e6ca57e8:
    FUN_2b6e6c984b0(&local_e8,uVar12,dVar13,dVar15,dVar16,dVar17,&local_d8);
  }
  else {
    if (param_1 != 1) goto LAB_2b6e6ca54ed;
    local_e8 = 0;
    local_b8 = 0;
    local_c8 = 0;
    local_e4 = 0;
    local_b4 = 0;
    local_c4 = 0;
    dVar15 = dVar14;
    if ((longlong)dVar14 != -0x8000000000000000) {
      dVar15 = (double)(longlong)dVar14;
      uVar6 = 0xb;
      if (_DAT_2b6e6d43d20 < 0xb) {
        uVar6 = (ulonglong)_DAT_2b6e6d43d20;
      }
      dVar15 = (double)(longlong)
                       ((dVar14 - dVar15) * *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) +
                       *(double *)((ulonglong)(0.0 < dVar14) * 8 + 0x2b6e6ca8c00)) /
               *(double *)(&DAT_2b6e6ca8ca0 + uVar6 * 8) + dVar15;
    }
    if ((DAT_2b6e6d43e88 != '\x01') || (_DAT_2b6e6d43778 < 1)) {
      lVar5 = (*(code *)0x7ff63a0f2970)(0x2b6e1db7188,0x2b6e6ca8e30,0x12);
      if (lVar5 <= _DAT_2b6e6d43e98) {
        local_c8 = 0;
        local_c4 = 0;
        uVar12 = FUN_2b6e6ca59f0(0,dVar15);
        FUN_2b6e6c90d90(&local_b8,0x2b6e6d43d28,1,0x2b6e6d423b0);
        cVar3 = FUN_2b6e6ca6670(&local_b8,uVar12,0);
        if (cVar3 != '\0') {
          uVar12 = FUN_2b6e6ca59f0(0);
          cVar3 = FUN_2b6e6ca68f0(uVar12,&local_c8);
          if (cVar3 != '\0') {
            FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d28,1,0x2b6e6d423c0);
            cVar3 = (*(code *)0x7ff63a107f20)(0x2b6e1db7188,&local_e8);
            if (cVar3 != '\0') {
              (*(code *)0x7ff63a107f70)(0x2b6e1db7188,3);
              if ((_DAT_2b6e6d43d48 == 0.0) && (!NAN(_DAT_2b6e6d43d48))) goto LAB_2b6e6ca54d8;
            }
            FUN_2b6e6ca59f0(0,dVar15);
            cVar3 = FUN_2b6e6ca6c50();
            if (cVar3 != '\0') {
              cVar3 = FUN_2b6e6ca6dd0();
              if (cVar3 != '\0') {
                cVar3 = FUN_2b6e6ca6e30();
                FUN_2b6e6c90000(&local_c8);
                FUN_2b6e6c90000(&local_b8);
                FUN_2b6e6c90000(&local_e8);
                if (cVar3 == '\0') goto LAB_2b6e6ca54ed;
                iVar4 = FUN_2b6e6ca5850();
                if (0 < iVar4) goto LAB_2b6e6ca54ed;
                uVar9 = 0;
                FUN_2b6e6c90d90(&local_d8,0x2b6e6d43e20,0,0x2b6e6d42390);
                uVar2 = _DAT_2b6e6cab448;
                uVar6 = (ulonglong)_DAT_2b6e6cab448;
                if ((uVar6 != 0) || (local_d4 == 0)) {
                  if (local_d4 != 0) {
                    uVar9 = *(uint *)(local_d4 + -4);
                  }
                  uVar8 = _DAT_2b6e6cab448 + uVar9;
                  uVar7 = 0x104;
                  if ((0x103 < uVar8) &&
                     ((0x3fffffe7 < uVar8 || (uVar7 = (uVar8 >> 2) + uVar8, 0x3fffffe7 < uVar7)))) {
                    uVar7 = 0x3fffffe8;
                  }
                  cVar3 = FUN_2b6e6c90060(&local_d8,uVar7);
                  if (cVar3 == '\0') {
                    (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x600008000a01f9);
                    goto LAB_2b6e6ca582a;
                  }
                  if (uVar6 != 0) {
                    lVar5 = local_d4 + (ulonglong)uVar9 * 2;
                    if (uVar2 < 0x10) {
                      uVar10 = 0;
                    }
                    else if (lVar5 - 0x2b6e6cab44cU < 0x20) {
                      uVar10 = 0;
                    }
                    else {
                      uVar11 = 0;
                      uVar10 = (ulonglong)(uVar2 & 0xfffffff8);
                      do {
                        uVar12 = *(undefined8 *)(uVar11 + 0x2b6e6cab454);
                        *(undefined8 *)(lVar5 + uVar11) = *(undefined8 *)(&DAT_2b6e6cab44c + uVar11)
                        ;
                        ((undefined8 *)(lVar5 + uVar11))[1] = uVar12;
                        uVar11 = uVar11 + 0x10;
                      } while ((uVar6 * 2 & 0xfffffffffffffff0) != uVar11);
                      if (uVar10 == uVar6) goto LAB_2b6e6ca55bf;
                    }
                    do {
                      *(undefined2 *)(lVar5 + uVar10 * 2) =
                           *(undefined2 *)(&DAT_2b6e6cab44c + uVar10 * 2);
                      uVar10 = uVar10 + 1;
                    } while (uVar6 != uVar10);
                  }
LAB_2b6e6ca55bf:
                  *(uint *)(local_d4 + -4) = uVar8;
                  *(undefined2 *)(local_d4 + (ulonglong)uVar8 * 2) = 0;
                }
                dVar17 = _DAT_2b6e6d43a70 * _DAT_2b6e6d43d18;
                dVar16 = _DAT_2b6e6d43d18 * _DAT_2b6e6d43a68;
                dVar13 = (double)FUN_2b6e6ca59f0(0,dVar14);
                if (dVar13 <= 0.0) goto LAB_2b6e6ca57f5;
                local_e8 = 0;
                dVar17 = dVar17 + dVar14;
                local_e4 = 0;
                dVar16 = dVar14 - dVar16;
                FUN_2b6e6c90d90(&local_e8,0x2b6e6d43d28,0,0x2b6e6d40988);
                dVar15 = dVar14;
                if ((dVar14 == 0.0) && (!NAN(dVar14))) {
                  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,&local_e8,4);
                  dVar15 = _DAT_2b6e6d43d48;
                }
                uVar12 = 0;
                goto LAB_2b6e6ca57e8;
              }
            }
          }
        }
        goto LAB_2b6e6ca54d8;
      }
    }
LAB_2b6e6ca54df:
    FUN_2b6e6c90000(&local_b8);
  }
  FUN_2b6e6c90000(&local_e8);
LAB_2b6e6ca54ed:
  FUN_2b6e6c90000(&local_d8);
  return;
}



/* Address: 2b6e6ca5850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_2b6e6ca5850(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined4 local_50;
  longlong local_4c;
  
  local_50 = 0;
  local_4c = 0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
  if (iVar8 + -1 < 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    lVar14 = (longlong)_DAT_2b6e6d43e18;
    iVar8 = iVar8 + -1;
    do {
      uVar9 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar8);
      lVar10 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc);
      cVar7 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,uVar9);
      if ((cVar7 != '\0') && (lVar10 == lVar14)) {
        (*(code *)0x7ff63a108010)(0x2b6e1db7188,0);
        FUN_2b6e6c90d90(&local_50,0x2b6e6d43d3c,1,0x2b6e6d42608);
        if (local_4c == _DAT_2b6e6d43d2c) {
LAB_2b6e6ca58c0:
          iVar12 = iVar12 + 1;
        }
        else if ((local_4c != 0) && (_DAT_2b6e6d43d2c != 0)) {
          uVar3 = *(uint *)(local_4c + -4);
          uVar4 = *(uint *)(_DAT_2b6e6d43d2c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar11 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar13 = 1;
            do {
              uVar1 = *(ushort *)(local_4c + -2 + uVar13 * 2);
              uVar2 = *(ushort *)(_DAT_2b6e6d43d2c + -2 + uVar13 * 2);
              if (uVar6 <= uVar13) break;
              uVar13 = uVar13 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar11 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar11 == 0) goto LAB_2b6e6ca58c0;
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  FUN_2b6e6c90000(&local_50);
  return iVar12;
}



/* Address: 2b6e6ca59f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2b6e6ca59f0(undefined4 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong lVar15;
  uint uVar16;
  bool bVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 local_100;
  short *local_fc;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  short *local_dc;
  ulonglong local_d0;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined4 local_a0;
  undefined8 local_9c;
  longlong local_90;
  
  local_b0 = 0;
  local_100 = 0;
  local_f0 = 0;
  local_ac = 0;
  local_fc = (short *)0x0;
  local_ec = 0;
  (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x25);
  cVar5 = DAT_2b6e6d43e68;
  dVar18 = _DAT_2b6e6d43d48;
  if (DAT_2b6e6d43e68 == '\x01') {
    local_f0 = 0;
    local_ec = 0;
    local_c4 = param_1;
    FUN_2b6e6c90d90(&local_100,0x2b6e6cab8f0,0,0x2b6e6d425c8);
    local_a0 = 0;
    local_c0 = 0;
    local_e0 = 0;
    local_9c = 0;
    local_bc = 0;
    local_dc = (short *)0x0;
    iVar6 = (*(code *)0x7ff63a0f2730)(0x2b6e1db7188,0);
    if (0 < iVar6) {
      iVar10 = 0;
      do {
        local_e0 = 0;
        local_dc = (short *)0x0;
        (*(code *)0x7ff63a0f2780)(0x2b6e1db7188,iVar10,0);
        FUN_2b6e6c90d90(&local_a0,0x2b6e6d43d3c,1,0x2b6e6d42618);
        FUN_2b6e6c90d90(&local_e0,&local_a0,0,0x2b6e6d42628);
        uVar23 = 0xfa9;
        if ((local_dc != (short *)0x0) && (local_fc != (short *)0x0)) {
          uVar11 = *(uint *)(local_dc + -2);
          uVar23 = 0x13ab;
          if ((uVar11 != 0) && (uVar16 = *(uint *)(local_fc + -2), uVar16 != 0)) {
            if (local_dc == local_fc) goto LAB_2b6e6ca5d4b;
            uVar23 = _DAT_2b6e6d43d10;
            if ((uVar16 <= uVar11) && (uVar11 = (uVar11 - uVar16) + 1, uVar11 != 0)) {
              sVar3 = *local_fc;
              local_d0 = (ulonglong)uVar11;
              if (uVar16 < 2) {
                if (*local_dc == sVar3) {
LAB_2b6e6ca5d4b:
                  FUN_2b6e6c90d90(&local_c0,&local_e0,0,0x2b6e6d42638);
                  FUN_2b6e6c90000(&local_e0);
                  goto LAB_2b6e6ca5dc7;
                }
                uVar13 = 0;
                do {
                  if (local_d0 - 1 == uVar13) goto LAB_2b6e6ca5b9c;
                  lVar15 = uVar13 + 1;
                  uVar13 = uVar13 + 1;
                } while (local_dc[lVar15] != sVar3);
                if (uVar13 < local_d0) {
LAB_2b6e6ca5d42:
                  if ((int)uVar13 == 0) goto LAB_2b6e6ca5d4b;
                }
              }
              else {
                bVar17 = true;
                uVar13 = 0;
                local_90 = (ulonglong)uVar16 - 1;
                do {
                  if (local_dc[uVar13] == sVar3) {
                    lVar12 = 1;
                    lVar15 = local_90;
                    while (local_dc[(uint)((int)uVar13 + (int)lVar12)] == local_fc[lVar12]) {
                      lVar12 = lVar12 + 1;
                      lVar15 = lVar15 + -1;
                      if (lVar15 == 0) goto LAB_2b6e6ca5d28;
                    }
                    if ((int)lVar15 == 0) {
LAB_2b6e6ca5d28:
                      if (bVar17) goto LAB_2b6e6ca5d42;
                      break;
                    }
                  }
                  uVar13 = uVar13 + 1;
                  bVar17 = uVar13 < local_d0;
                } while (uVar13 != local_d0);
              }
            }
          }
        }
LAB_2b6e6ca5b9c:
        _DAT_2b6e6d43d10 = uVar23;
        FUN_2b6e6c90000(&local_e0);
        iVar10 = iVar10 + 1;
      } while (iVar10 != iVar6);
    }
    FUN_2b6e6c90d90(&local_c0,0x2b6e6ca8e50,0,0x2b6e6d42648);
LAB_2b6e6ca5dc7:
    FUN_2b6e6c90d90(0x2b6e6d43d3c,&local_c0,1,0x2b6e6d42658);
    FUN_2b6e6c90000(&local_c0);
    FUN_2b6e6c90000(&local_c0);
    FUN_2b6e6c90000(&local_a0);
    FUN_2b6e6c90d90(&local_b0,0x2b6e6d43d3c,1,0x2b6e6d425d8);
    FUN_2b6e6c90d90(&local_f0,&local_b0,0,0x2b6e6d425e8);
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,&local_f0,1);
    if ((_DAT_2b6e6d43d48 == 0.0) && (!NAN(_DAT_2b6e6d43d48))) {
      FUN_2b6e6c90d90(&local_100,0x2b6e6cab958,0);
      lVar15 = local_ec;
      if (local_ec != 0) {
        uVar11 = *(uint *)(local_ec + -4);
        uVar13 = (ulonglong)uVar11;
        if ((uVar13 != 0) || (local_fc == (short *)0x0)) {
          if (local_fc == (short *)0x0) {
            uVar16 = 0;
            uVar9 = uVar11;
          }
          else {
            uVar16 = *(uint *)(local_fc + -2);
            uVar9 = uVar11 + uVar16;
          }
          cVar5 = FUN_2b6e6c90060(&local_100);
          if (cVar5 == '\0') {
            (*(code *)0x7ff639cc59a0)(0x2b6e1db7188,0x370009000c01f9);
            pcVar4 = (code *)swi(3);
            dVar18 = (double)(*pcVar4)();
            return dVar18;
          }
          if (uVar13 != 0) {
            if (uVar11 < 0x10) {
              uVar8 = 0;
            }
            else if ((longlong)local_fc + ((ulonglong)uVar16 * 2 - lVar15) < 0x20) {
              uVar8 = 0;
            }
            else {
              uVar14 = 0;
              uVar8 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)(lVar15 + uVar14);
                uVar23 = puVar1[1];
                uVar24 = puVar1[2];
                uVar21 = puVar1[3];
                puVar2 = (undefined4 *)((longlong)local_fc + uVar14 + (ulonglong)uVar16 * 2);
                *puVar2 = *puVar1;
                puVar2[1] = uVar23;
                puVar2[2] = uVar24;
                puVar2[3] = uVar21;
                uVar14 = uVar14 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar14);
              if (uVar8 == uVar13) goto LAB_2b6e6ca65b2;
            }
            do {
              local_fc[uVar16 + uVar8] = *(short *)(lVar15 + uVar8 * 2);
              uVar8 = uVar8 + 1;
            } while (uVar13 != uVar8);
          }
LAB_2b6e6ca65b2:
          *(uint *)(local_fc + -2) = uVar9;
          local_fc[uVar9] = 0;
        }
      }
      (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,2,1,0x590008,&local_100);
      FUN_2b6e6c90000(&local_f0);
      dVar18 = 0.0;
      goto LAB_2b6e6ca65f8;
    }
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,&local_f0,1);
    uVar23 = SUB84(_DAT_2b6e6d43d48,0);
    uVar24 = (undefined4)((ulonglong)_DAT_2b6e6d43d48 >> 0x20);
    FUN_2b6e6c90000(&local_f0);
    param_1 = local_c4;
    if (DAT_2b6e6d43e40 != '\x01') goto LAB_2b6e6ca5d8a;
LAB_2b6e6ca5f32:
    if (cVar5 == '\0') {
      if (_DAT_2b6e6d43e50 < 6) {
        lVar15 = 0x2b6e6d42b20;
        goto LAB_2b6e6ca5f84;
      }
      puVar7 = (undefined8 *)&DAT_2b6e6ca8c18;
LAB_2b6e6ca5f94:
      uVar21 = (undefined4)*puVar7;
      uVar22 = (undefined4)((ulonglong)*puVar7 >> 0x20);
    }
    else {
      uVar21 = (undefined4)_DAT_2b6e6ca8c18;
      uVar22 = (undefined4)((ulonglong)_DAT_2b6e6ca8c18 >> 0x20);
      if ((cVar5 == '\x01') && (_DAT_2b6e6d43e50 < 6)) {
        lVar15 = 0x2b6e6d42b50;
LAB_2b6e6ca5f84:
        puVar7 = (undefined8 *)(lVar15 + (ulonglong)_DAT_2b6e6d43e50 * 8);
        goto LAB_2b6e6ca5f94;
      }
    }
    if (DAT_2b6e6d43e58 != '\0') {
      uVar21 = (undefined4)_DAT_2b6e6d43e60;
      uVar22 = (undefined4)((ulonglong)_DAT_2b6e6d43e60 >> 0x20);
    }
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x24);
    if ((_DAT_2b6e6d43d48 != 0.0) || (NAN(_DAT_2b6e6d43d48))) {
      dVar19 = _DAT_2b6e6d43d48;
      if ((longlong)_DAT_2b6e6d43d48 != -0x8000000000000000) {
        dVar19 = (double)(longlong)_DAT_2b6e6d43d48;
        dVar19 = (double)(longlong)
                         ((_DAT_2b6e6d43d48 - dVar19) +
                         *(double *)((ulonglong)(0.0 < _DAT_2b6e6d43d48) * 8 + 0x2b6e6ca8c20)) +
                 dVar19;
      }
      if (_DAT_2b6e6ca8c10 <= dVar19) goto LAB_2b6e6ca63cc;
      dVar19 = _DAT_2b6e6ca8c30 * _DAT_2b6e6d43d48;
      if ((longlong)dVar19 != -0x8000000000000000) {
        dVar20 = (double)(longlong)dVar19;
        dVar19 = (double)(longlong)
                         ((dVar19 - dVar20) * _DAT_2b6e6ca8c30 +
                         *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                 _DAT_2b6e6ca8c30 + dVar20;
      }
      lVar15 = 1;
      if (dVar19 < _DAT_2b6e6ca8c10) {
        dVar19 = _DAT_2b6e6ca8c38 * _DAT_2b6e6d43d48;
        if ((longlong)dVar19 != -0x8000000000000000) {
          dVar20 = (double)(longlong)dVar19;
          dVar19 = (double)(longlong)
                           ((dVar19 - dVar20) * _DAT_2b6e6ca8c38 +
                           *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                   _DAT_2b6e6ca8c38 + dVar20;
        }
        lVar15 = 2;
        if (dVar19 < _DAT_2b6e6ca8c10) {
          dVar19 = _DAT_2b6e6ca8c40 * _DAT_2b6e6d43d48;
          if ((longlong)dVar19 != -0x8000000000000000) {
            dVar20 = (double)(longlong)dVar19;
            dVar19 = (double)(longlong)
                             ((dVar19 - dVar20) * _DAT_2b6e6ca8c40 +
                             *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                     _DAT_2b6e6ca8c40 + dVar20;
          }
          lVar15 = 3;
          if (dVar19 < _DAT_2b6e6ca8c10) {
            dVar19 = _DAT_2b6e6ca8c48 * _DAT_2b6e6d43d48;
            if ((longlong)dVar19 != -0x8000000000000000) {
              dVar20 = (double)(longlong)dVar19;
              dVar19 = (double)(longlong)
                               ((dVar19 - dVar20) * _DAT_2b6e6ca8c48 +
                               *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                       _DAT_2b6e6ca8c48 + dVar20;
            }
            lVar15 = 4;
            if (dVar19 < _DAT_2b6e6ca8c10) {
              dVar19 = _DAT_2b6e6ca8c50 * _DAT_2b6e6d43d48;
              if ((longlong)dVar19 != -0x8000000000000000) {
                dVar20 = (double)(longlong)dVar19;
                dVar19 = (double)(longlong)
                                 ((dVar19 - dVar20) * _DAT_2b6e6ca8c50 +
                                 *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                         _DAT_2b6e6ca8c50 + dVar20;
              }
              lVar15 = 5;
              if (dVar19 < _DAT_2b6e6ca8c10) {
                dVar19 = _DAT_2b6e6ca8c58 * _DAT_2b6e6d43d48;
                if ((longlong)dVar19 != -0x8000000000000000) {
                  dVar20 = (double)(longlong)dVar19;
                  dVar19 = (double)(longlong)
                                   ((dVar19 - dVar20) * _DAT_2b6e6ca8c58 +
                                   *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                           _DAT_2b6e6ca8c58 + dVar20;
                }
                lVar15 = 6;
                if (dVar19 < _DAT_2b6e6ca8c10) {
                  dVar19 = _DAT_2b6e6ca8c60 * _DAT_2b6e6d43d48;
                  if ((longlong)dVar19 != -0x8000000000000000) {
                    dVar20 = (double)(longlong)dVar19;
                    dVar19 = (double)(longlong)
                                     ((dVar19 - dVar20) * _DAT_2b6e6ca8c60 +
                                     *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                             _DAT_2b6e6ca8c60 + dVar20;
                  }
                  lVar15 = 7;
                  if (dVar19 < _DAT_2b6e6ca8c10) {
                    dVar19 = _DAT_2b6e6d43d48 * _DAT_2b6e6ca8c68;
                    if ((longlong)dVar19 != -0x8000000000000000) {
                      dVar20 = (double)(longlong)dVar19;
                      dVar19 = (double)(longlong)
                                       ((dVar19 - dVar20) * _DAT_2b6e6ca8c68 +
                                       *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b6e6ca8c20)) /
                               _DAT_2b6e6ca8c68 + dVar20;
                    }
                    lVar15 = 8;
                    if (dVar19 < _DAT_2b6e6ca8c10) {
                      lVar15 = 9;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
LAB_2b6e6ca63cc:
      lVar15 = 0;
    }
    dVar18 = (dVar18 / (double)CONCAT44(uVar24,uVar23)) *
             ((double)CONCAT44(uVar22,uVar21) / _DAT_2b6e6ca8c50);
    if ((longlong)dVar18 != -0x8000000000000000) {
      dVar19 = (double)(longlong)dVar18;
      dVar18 = (double)(longlong)
                       ((dVar18 - dVar19) * *(double *)(&DAT_2b6e6ca8ca0 + lVar15 * 8) +
                       *(double *)((ulonglong)(0.0 < dVar18) * 8 + 0x2b6e6ca8c20)) /
               *(double *)(&DAT_2b6e6ca8ca0 + lVar15 * 8) + dVar19;
    }
  }
  else {
    uVar23 = SUB84(_DAT_2b6e6ca8c10,0);
    uVar24 = (undefined4)((ulonglong)_DAT_2b6e6ca8c10 >> 0x20);
    if (DAT_2b6e6d43e40 == '\x01') goto LAB_2b6e6ca5f32;
LAB_2b6e6ca5d8a:
    dVar18 = 0.0;
    if (DAT_2b6e6d43e40 == '\0') {
      dVar18 = _DAT_2b6e6d43e48;
    }
  }
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x22);
  if (dVar18 < _DAT_2b6e6d43d48) {
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x22);
    dVar18 = _DAT_2b6e6d43d48;
  }
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x23);
  if (_DAT_2b6e6d43d48 <= dVar18) {
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x23);
    dVar18 = _DAT_2b6e6d43d48;
  }
  dVar19 = (double)FUN_2b6e6ca7010(param_1,param_2);
  if (dVar19 <= dVar18) {
    dVar18 = (double)FUN_2b6e6ca7010(param_1,param_2);
  }
LAB_2b6e6ca65f8:
  FUN_2b6e6c90000(&local_100);
  FUN_2b6e6c90000(&local_b0);
  return dVar18;
}



/* Address: 2b6e6ca6670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2b6e6ca6670(undefined8 param_1,undefined8 param_2,int param_3)

{
  double dVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  double *pdVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined8 in_stack_ffffffffffffff18;
  undefined4 local_a0;
  undefined8 local_9c;
  double local_90;
  undefined1 local_88 [8];
  undefined8 auStack_80 [13];
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  local_a0 = 0;
  local_9c = 0;
  (*(code *)0x7ff63a0f2c10)(0x2b6e1db7188,param_1,local_88);
  uVar4 = auStack_80[param_3 != 1];
  (*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x2a);
  dVar1 = _DAT_2b6e6d43d48;
  pdVar6 = &local_90;
  cVar2 = (*(code *)0x7ff63a108d40)(0x2b6e1db7188,param_3,param_1,(int)param_2,uVar4,pdVar6);
  uVar7 = (undefined4)((ulonglong)pdVar6 >> 0x20);
  if (cVar2 == '\0') {
    uVar10 = 0x520004;
    uVar4 = 4;
    uVar9 = 0x2b6e6caba20;
    puVar8 = (undefined4 *)0x2b6e6cab9e8;
    uVar5 = 0x2b6e6cab9a0;
    param_2 = CONCAT44(uVar3,_DAT_2b6e6d43d10);
  }
  else {
    uVar3 = 0xe1db7101;
    if (local_90 <= dVar1) goto LAB_2b6e6ca68ae;
    puVar8 = &local_a0;
    FUN_2b6e6c91320(puVar8,param_3,0x2b6e6d428d0,10);
    uVar4 = 8;
    uVar10 = 0x580007;
    uVar5 = 0x2b6e6caba68;
    uVar9 = 0x2b6e6cab6f0;
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2b6e1db7188,2,uVar4,0x590008,uVar5,CONCAT44(uVar7,0x590008),puVar8,0x590008,uVar9,
             uVar10,param_2);
  uVar3 = 0;
LAB_2b6e6ca68ae:
  FUN_2b6e6c90000(&local_a0);
  return uVar3;
}



/* Address: 2b6e6ca68f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2b6e6ca68f0(double param_1,undefined8 param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  double dVar6;
  double dVar7;
  undefined4 local_48;
  undefined8 local_44;
  
  local_48 = 0;
  local_44 = 0;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x22);
  if (_DAT_2b6e6d43d48 <= param_1) {
    (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x23);
    if (param_1 <= _DAT_2b6e6d43d48) {
      (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x24);
      dVar6 = param_1 / _DAT_2b6e6d43d48;
      uVar3 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
      lVar1 = (ulonglong)uVar3 - 0x3ff;
      dVar7 = dVar6;
      if ((ulonglong)uVar3 < 0x433) {
        if (uVar3 < 0x3ff) {
          dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar1 != -1) {
            dVar7 = (double)((ulonglong)dVar6 & 0x8000000000000000);
          }
        }
        else {
          bVar2 = (byte)lVar1;
          if (((longlong)dVar6 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar7 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar6 &
                            -0x10000000000000 >> (bVar2 & 0x3f));
          }
        }
      }
      else if (lVar1 == 0x400) {
        dVar7 = dVar6 + dVar6;
      }
      if ((double)((ulonglong)((double)(int)dVar7 * _DAT_2b6e6d43d48 - param_1) & _DAT_2b6e6ca8c70)
          <= _DAT_2b6e6ca8c80) {
        FUN_2b6e6c90d90(param_2,0x2b6e6cabd28,0,0x2b6e6d42a20);
        uVar4 = 0x3a0f2801;
        goto LAB_2b6e6ca6bfe;
      }
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,3,0x590008,0x2b6e6cabce0,0x580007,_DAT_2b6e6d43d48,0x580007,
                 (double)(int)dVar7 * _DAT_2b6e6d43d48);
      FUN_2b6e6c90d90(&local_48,0x2b6e6d43d3c,1,0x2b6e6d42a00);
      uVar5 = 0x2b6e6d42a10;
    }
    else {
      (*(code *)0x7ff63a0e49f0)
                (0x2b6e1db7188,0xd8,2,0x590008,0x2b6e6cabbf0,0x580007,_DAT_2b6e6d43d48);
      FUN_2b6e6c90d90(&local_48,0x2b6e6d43d3c,1,0x2b6e6d429e0);
      uVar5 = 0x2b6e6d429f0;
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2b6e1db7188,0xd8,2,0x590008,0x2b6e6cabb50,0x580007,_DAT_2b6e6d43d48)
    ;
    FUN_2b6e6c90d90(&local_48,0x2b6e6d43d3c,1,0x2b6e6d429c0);
    uVar5 = 0x2b6e6d429d0;
  }
  uVar4 = 0;
  FUN_2b6e6c90d90(param_2,&local_48,0,uVar5);
LAB_2b6e6ca6bfe:
  FUN_2b6e6c90000(&local_48);
  return uVar4;
}



/* Address: 2b6e6ca6c20 */

ulonglong FUN_2b6e6ca6c20(void)

{
  undefined8 unaff_RDI;
  
  FUN_2b6e6c90d90();
  FUN_2b6e6c90000(&stack0x00000050);
  return CONCAT71((int7)((ulonglong)unaff_RDI >> 8),1) & 0xffffffff;
}



/* Address: 2b6e6ca6c50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_2b6e6ca6c50(double param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x37);
  dVar3 = _DAT_2b6e6d43d48;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6ca8e30,0x23);
  dVar4 = _DAT_2b6e6d43d48;
  iVar6 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
  dVar1 = 0.0;
  dVar2 = 0.0;
  if (-1 < iVar6 + -1) {
    lVar9 = (longlong)_DAT_2b6e6d43e18;
    do {
      iVar6 = iVar6 + -1;
      uVar7 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar6);
      cVar5 = (*(code *)0x7ff63a107ee0)(0x2b6e1db7188,uVar7);
      if (cVar5 != '\0') {
        lVar8 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc);
        if (lVar8 == lVar9) {
          (*(code *)0x7ff63a107f70)(0x2b6e1db7188,3);
          dVar1 = dVar1 + _DAT_2b6e6d43d48;
        }
      }
      dVar2 = dVar1;
    } while (0 < iVar6);
  }
  uVar10 = -(ulonglong)(dVar3 == 0.0);
  return dVar2 + param_1 <= (double)(~uVar10 & (ulonglong)dVar3 | (ulonglong)dVar4 & uVar10);
}



/* Address: 2b6e6ca6dd0 */

undefined8 FUN_2b6e6ca6dd0(void)

{
  undefined8 uVar1;
  undefined1 local_28 [24];
  int local_10;
  
  uVar1 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
  (*(code *)0x7ff63a101f60)(0x2b6e1db7188,uVar1,local_28);
  return CONCAT71(0x2b6e6d43e,DAT_2b6e6d43e90 != '\0' || local_10 != 5);
}



/* Address: 2b6e6ca6e30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b6e6ca6e30(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  
  if (DAT_2b6e6d43e70 == '\x01') {
    iVar10 = 0;
    lVar5 = (*(code *)0x7ff63a103b50)(0x2b6e1db7188,0x2b6e6ca8e30,0x4018,0);
    iVar3 = (*(code *)0x7ff63a107da0)(0x2b6e1db7188);
    iVar1 = _DAT_2b6e6d43e18;
    if (-1 < iVar3 + -1) {
      iVar10 = 0;
      do {
        iVar3 = iVar3 + -1;
        lVar6 = (*(code *)0x7ff63a107df0)(0x2b6e1db7188,iVar3);
        if ((lVar6 != 0) && (iVar4 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,0xc), iVar1 == iVar4))
        {
          lVar6 = (*(code *)0x7ff63a107fc0)(0x2b6e1db7188,1);
          iVar10 = iVar10 + (uint)(lVar5 <= lVar6);
        }
      } while (0 < iVar3);
    }
    uVar7 = (*(code *)0x7ff63a101c40)(0x2b6e1db7188,0);
    cVar2 = (*(code *)0x7ff63a1084f0)(0x2b6e1db7188,lVar5,uVar7);
    if ((cVar2 != '\0') &&
       (iVar3 = (*(code *)0x7ff63a108810)(0x2b6e1db7188), iVar1 = _DAT_2b6e6d43e18, -1 < iVar3 + -1)
       ) {
      do {
        iVar3 = iVar3 + -1;
        lVar6 = (*(code *)0x7ff63a108860)(0x2b6e1db7188,iVar3);
        if ((lVar6 != 0) &&
           (iVar4 = (*(code *)0x7ff63a108940)(0x2b6e1db7188,lVar6,0xb), iVar1 == iVar4)) {
          lVar8 = (*(code *)0x7ff63a108940)(0x2b6e1db7188,lVar6,2);
          uVar9 = (*(code *)0x7ff63a108940)(0x2b6e1db7188,lVar6,3);
          iVar10 = iVar10 + (uint)((uVar9 & 0xfffffffe) == 0 && lVar5 <= lVar8);
        }
      } while (0 < iVar3);
    }
    if (0 < iVar10) {
      return 0;
    }
  }
  return 1;
}



/* Address: 2b6e6ca7010 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2b6e6ca7010(undefined4 param_1,undefined8 param_2)

{
  longlong lVar1;
  double dVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double local_90 [10];
  
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6d43d28,0x24);
  dVar2 = _DAT_2b6e6d43d48;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6d43d28,0x22);
  dVar13 = _DAT_2b6e6d43d48;
  (*(code *)0x7ff63a0f2890)(0x2b6e1db7188,0x2b6e6d43d28,0x23);
  dVar12 = _DAT_2b6e6d43d48;
  dVar10 = (double)(*(code *)0x7ff63a3db380)(_DAT_2b6e6ca8c88 / dVar2);
  dVar13 = dVar13 / dVar2;
  uVar8 = (uint)((ulonglong)dVar13 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar11 = dVar13;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar11 = (double)((ulonglong)dVar13 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar11 = (double)((ulonglong)dVar13 & 0x8000000000000000);
      }
    }
    else {
      bVar7 = (byte)lVar1;
      if (((longlong)dVar13 << (bVar7 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar13 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar11 = dVar13 + dVar13;
  }
  dVar12 = dVar12 / dVar2;
  iVar5 = (int)dVar11;
  uVar8 = (uint)((ulonglong)dVar12 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar13 = dVar12;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar13 = (double)((ulonglong)dVar12 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar13 = (double)((ulonglong)dVar12 & 0x8000000000000000);
      }
    }
    else {
      bVar7 = (byte)lVar1;
      if (((longlong)dVar12 << (bVar7 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar13 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar12 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar13 = dVar12 + dVar12;
  }
  uVar8 = (uint)dVar10;
  if (iVar5 <= (int)dVar13) {
    uVar9 = 0xb;
    iVar3 = iVar5;
    if (uVar8 < 0xb) {
      uVar9 = (ulonglong)uVar8;
    }
    do {
      iVar6 = iVar3;
      dVar12 = (double)iVar6 * dVar2;
      if ((longlong)dVar12 != -0x8000000000000000) {
        dVar11 = (double)(longlong)dVar12;
        dVar12 = (double)(longlong)
                         ((dVar12 - dVar11) * *(double *)(&DAT_2b6e6ca8ca0 + uVar9 * 8) +
                         *(double *)((ulonglong)(0.0 < dVar12) * 8 + 0x2b6e6ca8c90)) /
                 *(double *)(&DAT_2b6e6ca8ca0 + uVar9 * 8) + dVar11;
      }
      local_90[0] = 0.0;
      cVar4 = (*(code *)0x7ff63a108d40)(0x2b6e1db7188,param_1,0x2b6e6d43d28,dVar12,param_2,local_90)
      ;
    } while (((cVar4 != '\0') &&
             ((*(code *)0x7ff63a0c7370)(0x2b6e1db7188,0x2a), 0.0 < _DAT_2b6e6d43d48 - local_90[0]))
            && (iVar3 = iVar6 + 1, iVar5 = iVar6, iVar6 + 1 <= (int)dVar13));
  }
  dVar2 = dVar2 * (double)iVar5;
  if ((longlong)dVar2 != -0x8000000000000000) {
    dVar13 = (double)(longlong)dVar2;
    uVar9 = 0xb;
    if (uVar8 < 0xb) {
      uVar9 = (ulonglong)uVar8;
    }
    dVar2 = (double)(longlong)
                    ((dVar2 - dVar13) * *(double *)(&DAT_2b6e6ca8ca0 + uVar9 * 8) +
                    *(double *)((ulonglong)(0.0 < dVar2) * 8 + 0x2b6e6ca8c90)) /
            *(double *)(&DAT_2b6e6ca8ca0 + uVar9 * 8) + dVar13;
  }
  return dVar2;
}


