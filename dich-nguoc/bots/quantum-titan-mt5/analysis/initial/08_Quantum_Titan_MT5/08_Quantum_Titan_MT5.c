/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 130b71d0000 */

void FUN_130b71d0000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x130b53f81d8);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 130b71d0060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71d0060(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x130b53f81d8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_130b71d01bd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_130b71d01bd;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x130b53f81d8);
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
        if (uVar15 < 8) goto LAB_130b71d0120;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_130b71d0120;
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
LAB_130b71d0120:
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
          (*(code *)0x7ff63a101200)(0x130b53f81d8,puVar14);
        }
      }
      goto LAB_130b71d01bd;
    }
  }
  _DAT_130b720bb10 = 0x13aa;
  uVar12 = 0;
LAB_130b71d01bd:
  return uVar12 & 0xffffffff;
}



/* Address: 130b71d01d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71d01d0(short *param_1,short *param_2)

{
  short *psVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  ulonglong uVar19;
  int iVar18;
  
  uVar3 = 0x13c7;
  if (*param_2 == 0x59) {
    lVar9 = 0;
    do {
      if (*(int *)(param_2 + lVar9 * 2 + 6) == 0) {
        if (lVar9 != 0) {
          _DAT_130b720bb10 = 0xfa6;
          return 0xffffffff;
        }
        uVar11 = 0;
        if ((param_1 == (short *)0x0) || (*param_1 == 0)) goto LAB_130b71d0456;
        lVar9 = *(longlong *)(param_2 + 0xe);
        uVar7 = *(uint *)(param_2 + 4);
        uVar2 = *(uint *)(param_1 + -2);
        uVar11 = 0;
        goto LAB_130b71d0270;
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 != 3);
    uVar3 = 0xfa6;
  }
  _DAT_130b720bb10 = uVar3;
  return 0xffffffff;
LAB_130b71d0270:
  uVar19 = 0xffffffff;
  uVar15 = 0;
  do {
    uVar6 = uVar15;
    iVar18 = (int)uVar19;
    uVar17 = iVar18 + 1;
    uVar19 = (ulonglong)uVar17;
    if (param_1[uVar19] == 0x3b) break;
    uVar15 = uVar6 + 1;
  } while (param_1[uVar19] != 0);
  if (0x7ffffffe < uVar17) {
    if ((*(byte *)(param_2 + 1) & 1) != 0) {
      (*(code *)0x7ff63a0d9d20)(0x130b53f81d8,param_2);
    }
    _DAT_130b720bb10 = 0x13b0;
    return 0xffffffff;
  }
  uVar15 = (uint)uVar11;
  if (uVar7 <= uVar15) {
    if ((*(byte *)(param_2 + 1) & 1) == 0) {
      _DAT_130b720bb10 = 0xfa7;
      return 0xffffffff;
    }
    uVar7 = uVar2;
    if (uVar17 != 0) {
      uVar7 = uVar2 / uVar17;
    }
    uVar7 = uVar15 + uVar7 + 1;
    iVar8 = (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,param_2,uVar7,0x20 - (uVar7 & 0x1f));
    if (iVar8 < 0) {
      return 0xffffffff;
    }
    lVar9 = *(longlong *)(param_2 + 0xe);
  }
  puVar14 = (undefined4 *)(uVar11 * 0xc + lVar9);
  puVar12 = *(undefined4 **)(lVar9 + 4 + uVar11 * 0xc);
  puVar13 = puVar12 + -3;
  if (puVar12 == (undefined4 *)0x0) {
    puVar13 = (uint *)0x0;
  }
  if ((*(int *)(lVar9 + uVar11 * 0xc) == 0) || (puVar13 == (uint *)0x0)) {
LAB_130b71d036d:
    puVar10 = (undefined4 *)(*(code *)0x7ff63a101190)(0x130b53f81d8);
    if (puVar10 != (undefined4 *)0x0) {
      *(undefined8 *)(puVar10 + 1) = 1;
      puVar12 = puVar10 + 3;
      *(undefined2 *)(puVar10 + 3) = 0;
      *(undefined4 **)(puVar14 + 1) = puVar12;
      *puVar14 = *puVar10;
      goto LAB_130b71d03a6;
    }
    _DAT_130b720bb10 = 0x13aa;
  }
  else {
    if ((*puVar13 < uVar17) || (puVar13[1] != 1)) {
      if (*puVar13 != 0) {
        puVar13 = puVar13 + 1;
        *puVar13 = *puVar13 - 1;
        if (*puVar13 == 0) {
          (*(code *)0x7ff63a101200)(0x130b53f81d8);
        }
      }
      *(undefined8 *)(puVar14 + 1) = 0;
      *puVar14 = 0;
      goto LAB_130b71d036d;
    }
LAB_130b71d03a6:
    if (uVar17 != 0) {
      if (uVar17 < 8) {
        uVar11 = 0;
      }
      else {
        uVar11 = 0;
        if (0x1f < (ulonglong)((longlong)puVar12 - (longlong)param_1)) {
          uVar11 = (ulonglong)(uVar17 & 0x7ffffff8);
          uVar16 = 0;
          do {
            psVar1 = param_1 + uVar16;
            uVar3 = *(undefined4 *)(psVar1 + 2);
            uVar4 = *(undefined4 *)(psVar1 + 4);
            uVar5 = *(undefined4 *)(psVar1 + 6);
            puVar14 = (undefined4 *)((longlong)puVar12 + uVar16 * 2);
            *puVar14 = *(undefined4 *)psVar1;
            puVar14[1] = uVar3;
            puVar14[2] = uVar4;
            puVar14[3] = uVar5;
            uVar16 = uVar16 + 8;
          } while ((uVar6 & 0x7ffffff8) != uVar16);
          if (uVar11 == uVar19) goto LAB_130b71d0432;
        }
      }
      do {
        *(short *)((longlong)puVar12 + uVar11 * 2) = param_1[uVar11];
        uVar11 = uVar11 + 1;
      } while (uVar6 != uVar11);
    }
LAB_130b71d0432:
    puVar12[-1] = uVar17;
    *(undefined2 *)((longlong)puVar12 + uVar19 * 2) = 0;
  }
  uVar11 = (ulonglong)(uVar15 + 1);
  if (param_1[uVar19] == 0) {
LAB_130b71d0456:
    if ((*(byte *)(param_2 + 1) & 1) != 0) {
      (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,param_2,uVar11,0);
      return uVar11;
    }
    return uVar11;
  }
  param_1 = param_1 + (iVar18 + 2);
  goto LAB_130b71d0270;
}



/* Address: 130b71d04d0 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_130b71d04d0(uint *param_1,short *param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined1 *puVar12;
  uint *puVar13;
  undefined1 *puVar14;
  uint *puVar15;
  uint uVar16;
  longlong lVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined1 *puVar22;
  int iVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  uint uVar26;
  undefined1 *puVar27;
  ulonglong uVar28;
  undefined1 *puVar29;
  uint local_68;
  
  uVar21 = _DAT_130b7203354;
  lVar7 = *(longlong *)(param_1 + 1);
  if (lVar7 == 0) {
    uVar20 = 0;
  }
  else {
    uVar20 = *(uint *)(lVar7 + -4);
  }
  if ((param_2 != (short *)0x0) && (lVar7 != 0)) {
    uVar6 = *(uint *)(param_2 + -2);
    if (uVar6 != 0) {
      if ((int)uVar20 < 1) {
        return (undefined1 *)((longlong)(int)uVar20 / (longlong)(int)uVar6 & 0xffffffff);
      }
      puVar29 = (undefined1 *)(longlong)(int)_DAT_130b7203354;
      iVar11 = (int)((longlong)(int)uVar20 / (longlong)(int)uVar6) * _DAT_130b7203354;
      puVar12 = (undefined1 *)((ulonglong)puVar29 & 0xfffffffffffffff8);
      puVar15 = (uint *)0x0;
      iVar19 = 0;
      iVar23 = 0;
      uVar26 = 0;
      local_68 = 0;
      do {
        lVar17 = (longlong)iVar19;
        uVar18 = iVar19 + 1U;
        if ((int)(iVar19 + 1U) < (int)uVar20) {
          uVar18 = uVar20;
        }
        do {
          if (*(short *)(lVar7 + lVar17 * 2) == *param_2) {
            uVar18 = (uint)lVar17;
            break;
          }
          lVar17 = lVar17 + 1;
        } while (lVar17 < (longlong)(ulonglong)uVar20);
        puVar14 = (undefined1 *)(ulonglong)(uVar20 - uVar18);
        if ((int)(uVar20 - uVar18) < (int)uVar6) break;
        uVar24 = 1;
        if ((int)uVar6 < 2) {
LAB_130b71d0610:
          if ((uint)uVar24 == uVar6) goto LAB_130b71d0619;
          iVar19 = uVar18 + 1;
        }
        else {
          uVar24 = 1;
          do {
            uVar5 = *(ushort *)(lVar7 + (longlong)(int)uVar18 * 2 + uVar24 * 2);
            puVar14 = (undefined1 *)(ulonglong)uVar5;
            if (uVar5 != param_2[uVar24]) goto LAB_130b71d0610;
            uVar24 = uVar24 + 1;
          } while (uVar6 != uVar24);
LAB_130b71d0619:
          if (puVar15 == (uint *)0x0) {
            puVar13 = (uint *)(*(code *)0x7ff63a101190)(0x130b53f81d8,iVar11 + uVar20);
            if (puVar13 == (uint *)0x0) {
              _DAT_130b720bb10 = 0x13aa;
              return &DAT_130b720bb10;
            }
            puVar13[1] = 1;
            puVar13[2] = 0;
            puVar15 = puVar13 + 3;
            *(undefined2 *)(puVar13 + 3) = 0;
            local_68 = *puVar13;
            puVar14 = (undefined1 *)(ulonglong)local_68;
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) goto LAB_130b71d06a3;
          }
          else {
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) {
LAB_130b71d06a3:
              lVar17 = lVar7 + (longlong)iVar23 * 2;
              puVar22 = (undefined1 *)(longlong)(int)(uVar16 + (uVar16 == 0));
              if (uVar16 < 8) {
                puVar27 = (undefined1 *)0x0;
              }
              else {
                if (0x1f < (ulonglong)((longlong)puVar15 + ((longlong)(int)uVar26 * 2 - lVar17))) {
                  puVar27 = (undefined1 *)((ulonglong)puVar22 & 0xfffffffffffffff8);
                  puVar14 = (undefined1 *)0x0;
                  do {
                    puVar3 = (undefined4 *)(lVar17 + (longlong)puVar14 * 2);
                    uVar8 = puVar3[1];
                    uVar9 = puVar3[2];
                    uVar10 = puVar3[3];
                    puVar4 = (undefined4 *)
                             ((longlong)puVar15 + (longlong)puVar14 * 2 + (longlong)(int)uVar26 * 2)
                    ;
                    *puVar4 = *puVar3;
                    puVar4[1] = uVar8;
                    puVar4[2] = uVar9;
                    puVar4[3] = uVar10;
                    puVar14 = puVar14 + 8;
                    if (puVar27 == puVar14) goto joined_r0x0130b71d0706;
                  } while( true );
                }
                puVar27 = (undefined1 *)0x0;
              }
              do {
                uVar5 = *(ushort *)(lVar17 + (longlong)puVar27 * 2);
                puVar14 = (undefined1 *)(ulonglong)uVar5;
                *(ushort *)((longlong)puVar15 + (longlong)puVar27 * 2 + (longlong)(int)uVar26 * 2) =
                     uVar5;
                puVar27 = puVar27 + 1;
joined_r0x0130b71d0706:
              } while (puVar27 != puVar22);
              uVar26 = uVar26 + uVar16;
            }
          }
          if (uVar21 != 0) {
            lVar17 = (longlong)(int)uVar26;
            if (uVar21 < 8) {
              puVar22 = (undefined1 *)0x0;
            }
            else if ((ulonglong)((longlong)puVar15 + lVar17 * 2 + -0x130b7203358) < 0x20) {
              puVar22 = (undefined1 *)0x0;
            }
            else {
              puVar14 = (undefined1 *)0x0;
              do {
                lVar2 = (longlong)puVar14 * 2;
                uVar8 = *(undefined4 *)(lVar2 + 0x130b720335c);
                uVar9 = *(undefined4 *)(lVar2 + 0x130b7203360);
                uVar10 = *(undefined4 *)(lVar2 + 0x130b7203364);
                puVar3 = (undefined4 *)((longlong)puVar15 + (longlong)puVar14 * 2 + lVar17 * 2);
                *puVar3 = *(undefined4 *)(&DAT_130b7203358 + lVar2);
                puVar3[1] = uVar8;
                puVar3[2] = uVar9;
                puVar3[3] = uVar10;
                puVar14 = puVar14 + 8;
              } while (puVar12 != puVar14);
              puVar14 = puVar12;
              puVar22 = puVar12;
              if (puVar12 == puVar29) goto LAB_130b71d07b2;
            }
            do {
              uVar5 = *(ushort *)(&DAT_130b7203358 + (longlong)puVar22 * 2);
              *(ushort *)((longlong)puVar15 + (longlong)puVar22 * 2 + lVar17 * 2) = uVar5;
              puVar22 = puVar22 + 1;
              puVar14 = (undefined1 *)(ulonglong)uVar5;
            } while (puVar29 != puVar22);
          }
LAB_130b71d07b2:
          uVar26 = uVar26 + uVar21;
          iVar19 = uVar18 + uVar6;
          iVar23 = iVar19;
        }
      } while (iVar19 < (int)uVar20);
      if (puVar15 == (uint *)0x0) {
        return puVar14;
      }
      uVar21 = uVar20 - iVar23;
      if (uVar21 != 0 && iVar23 <= (int)uVar20) {
        lVar7 = lVar7 + (longlong)iVar23 * 2;
        uVar24 = (ulonglong)(int)(uVar21 + (uVar21 == 0));
        if (uVar21 < 0x10) {
          uVar25 = 0;
        }
        else {
          if (0x1f < (ulonglong)((longlong)puVar15 + ((longlong)(int)uVar26 * 2 - lVar7))) {
            uVar25 = uVar24 & 0xfffffffffffffff8;
            uVar28 = 0;
            do {
              puVar3 = (undefined4 *)(lVar7 + uVar28 * 2);
              uVar8 = puVar3[1];
              uVar9 = puVar3[2];
              uVar10 = puVar3[3];
              puVar4 = (undefined4 *)((longlong)puVar15 + uVar28 * 2 + (longlong)(int)uVar26 * 2);
              *puVar4 = *puVar3;
              puVar4[1] = uVar8;
              puVar4[2] = uVar9;
              puVar4[3] = uVar10;
              uVar28 = uVar28 + 8;
              if (uVar25 == uVar28) goto joined_r0x0130b71d0879;
            } while( true );
          }
          uVar25 = 0;
        }
        do {
          *(undefined2 *)((longlong)puVar15 + uVar25 * 2 + (longlong)(int)uVar26 * 2) =
               *(undefined2 *)(lVar7 + uVar25 * 2);
          uVar25 = uVar25 + 1;
joined_r0x0130b71d0879:
        } while (uVar25 != uVar24);
        uVar26 = uVar26 + uVar21;
      }
      puVar15[-1] = uVar26;
      puVar12 = (undefined1 *)(ulonglong)uVar26;
      *(undefined2 *)((longlong)puVar15 + (longlong)puVar12 * 2) = 0;
      lVar7 = *(longlong *)(param_1 + 1);
      uVar21 = *param_1;
      *param_1 = local_68;
      *(uint **)(param_1 + 1) = puVar15;
      if (uVar21 == 0) {
        return puVar12;
      }
      if (lVar7 == 0) {
        return puVar12;
      }
      if ((int *)(lVar7 + -0xc) != (int *)0x0) {
        if (*(int *)(lVar7 + -0xc) == 0) {
          return puVar12;
        }
        piVar1 = (int *)(lVar7 + -8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          puVar12 = (undefined1 *)(*(code *)0x7ff63a101200)(0x130b53f81d8);
          return puVar12;
        }
        return puVar12;
      }
      return puVar12;
    }
  }
  _DAT_130b720bb10 = 0x13b0;
  return &DAT_130b720bb10;
}



/* Address: 130b71d0820 */

void FUN_130b71d0820(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int *unaff_RSI;
  uint in_R11D;
  int local_res20;
  
  *(uint *)(param_1 + -4) = in_R11D;
  *(undefined2 *)(param_1 + (ulonglong)in_R11D * 2) = 0;
  lVar3 = *(longlong *)(unaff_RSI + 1);
  iVar2 = *unaff_RSI;
  *unaff_RSI = local_res20;
  *(longlong *)(unaff_RSI + 1) = param_1;
  if ((((iVar2 != 0) && (lVar3 != 0)) && ((int *)(lVar3 + -0xc) != (int *)0x0)) &&
     (*(int *)(lVar3 + -0xc) != 0)) {
    piVar1 = (int *)(lVar3 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x130b53f81d8);
      return;
    }
  }
  return;
}



/* Address: 130b71d0910 */

ulonglong FUN_130b71d0910(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_130b71d0a1d;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_130b71d0a1d;
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
  cVar5 = FUN_130b71d0060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_130b71d0a1d;
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
      if (uVar10 == uVar9) goto LAB_130b71d0a12;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_130b71d0a12:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_130b71d0a1d:
  return uVar8 & 0xffffffff;
}



/* Address: 130b71d0a30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71d0a30(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x130b53f81d8);
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
        (*(code *)0x7ff63a101200)(0x130b53f81d8,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x130b53f81d8,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_130b720bb10 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x130b53f81d8,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_130b71d0bc0;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_130b71d0bc0:
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
      (*(code *)0x7ff63a101200)(0x130b53f81d8);
      return;
    }
  }
  return;
}



/* Address: 130b71d0c50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71d0c50(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  int *piVar17;
  uint uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  
  lVar8 = *(longlong *)(param_1 + 1);
  if ((lVar8 == 0) || (piVar17 = (int *)(lVar8 + -0xc), piVar17 == (int *)0x0)) {
    _DAT_130b720bb10 = 0xfa9;
  }
  else {
    uVar5 = *(uint *)(lVar8 + -4);
    uVar19 = (ulonglong)uVar5;
    if (uVar19 != 0) {
      uVar15 = 0;
      do {
        uVar13 = (ulonglong)*(ushort *)(lVar8 + uVar15 * 2);
        uVar16 = uVar15;
        if ((0x20 < uVar13) || ((0x100002600U >> (uVar13 & 0x3f) & 1) == 0)) break;
        uVar15 = uVar15 + 1;
        uVar16 = uVar19;
      } while (uVar19 != uVar15);
      uVar14 = (uint)uVar16;
      if (uVar14 == 0) {
        return 0;
      }
      uVar18 = uVar5 - uVar14;
      piVar12 = (int *)(*(code *)0x7ff63a101190)(0x130b53f81d8,uVar18);
      if (piVar12 != (int *)0x0) {
        piVar12[1] = 1;
        piVar12[2] = 0;
        piVar1 = piVar12 + 3;
        *(undefined2 *)(piVar12 + 3) = 0;
        iVar6 = *piVar12;
        uVar19 = (ulonglong)uVar18;
        if (uVar5 != uVar14) {
          lVar2 = lVar8 + (uVar16 & 0xffffffff) * 2;
          uVar15 = uVar19 + (uVar19 == 0);
          if ((0xf < uVar18) &&
             (0x1f < (longlong)piVar12 - ((longlong)piVar17 + (uVar16 & 0xffffffff) * 2))) {
            uVar13 = (ulonglong)((uint)uVar15 & 0xfffffff8);
            uVar20 = 0;
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar20 * 2);
              uVar9 = puVar3[1];
              uVar10 = puVar3[2];
              uVar11 = puVar3[3];
              puVar4 = (undefined4 *)((longlong)piVar1 + uVar20 * 2);
              *puVar4 = *puVar3;
              puVar4[1] = uVar9;
              puVar4[2] = uVar10;
              puVar4[3] = uVar11;
              uVar20 = uVar20 + 8;
              if (uVar13 == uVar20) goto LAB_130b71d0da1;
            } while( true );
          }
          uVar13 = 0;
          do {
            *(undefined2 *)((longlong)piVar1 + uVar13 * 2) = *(undefined2 *)(lVar2 + uVar13 * 2);
            uVar13 = uVar13 + 1;
LAB_130b71d0da1:
          } while (uVar15 != uVar13);
        }
        piVar12[2] = uVar18;
        *(undefined2 *)((longlong)piVar1 + uVar19 * 2) = 0;
        iVar7 = *param_1;
        *param_1 = iVar6;
        *(int **)(param_1 + 1) = piVar1;
        if ((iVar7 != 0) && (*piVar17 != 0)) {
          piVar12 = (int *)(lVar8 + -8);
          *piVar12 = *piVar12 + -1;
          if (*piVar12 == 0) {
            (*(code *)0x7ff63a101200)(0x130b53f81d8,piVar17);
          }
        }
        return uVar16 & 0xffffffff;
      }
      _DAT_130b720bb10 = 0x13aa;
      return 0;
    }
  }
  return 0;
}



/* Address: 130b71d0df0 */

void FUN_130b71d0df0(longlong param_1)

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
              (*(code *)0x7ff63a101200)(0x130b53f81d8);
            }
          }
          *plVar6 = 0;
          *(undefined4 *)((longlong)plVar6 + -4) = 0;
          plVar6 = (longlong *)((longlong)plVar6 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x130b53f81d8,lVar2,0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 130b71d0ee0 */

void FUN_130b71d0ee0(longlong param_1)

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
    (*(code *)0x7ff63a0e6ef0)(0x130b53f81d8,lVar2 - *(int *)(lVar2 + -4),0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 130b71d0fb0 */

undefined8 FUN_130b71d0fb0(void)

{
  return 0;
}



/* Address: 130b71d0fc0 */

void FUN_130b71d0fc0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x130b53f81d8,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 130b71d1010 */

undefined4 FUN_130b71d1010(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b72069e8);
  local_80 = 0;
  local_7c = 0;
  FUN_130b71d0a30(&local_80,0x130b7201870,0,0x130b72069f8);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x130b53f81d8,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_130b71d11e2;
    uVar4 = 0x130b7206a38;
    uVar3 = 0x130b7206a28;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_130b71d11e2;
    uVar4 = 0x130b7206a18;
    uVar3 = 0x130b7206a08;
  }
  FUN_130b71dbd30(&local_80,param_2,param_3);
  FUN_130b71d0a30(&local_60,0x130b720bb3c,1,uVar3);
  FUN_130b71dd7f0(param_1,&local_70,param_2);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd,3,0x590008,0x130b7202188,0x590008,&local_50,0x590008,&local_60);
LAB_130b71d11e2:
  FUN_130b71d0000(&local_80);
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_50);
  return uVar1;
}



/* Address: 130b71d1220 */

void FUN_130b71d1220(undefined8 *param_1)

{
  FUN_130b71d0000(param_1 + 0x41);
  FUN_130b71d0000((longlong)param_1 + 0x144);
  FUN_130b71d0000((longlong)param_1 + 0x84);
  FUN_130b71d0000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x130b53f81d8,*param_1,0x130b7466890);
  param_1[1] = 0x130b72017d0;
  return;
}



/* Address: 130b71d1290 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71d1290(void)

{
  double dVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  double dVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  double dVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  longlong in_stack_fffffffffffffee0;
  undefined4 uVar26;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d0;
  undefined8 local_cc;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  
  iVar13 = _DAT_130b720bc30;
  cVar10 = DAT_130b720bc18;
  bVar6 = true;
  if ((DAT_130b720bc18 != '\0') && (_DAT_130b720bc30 < 1)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7206468);
    bVar6 = false;
  }
  iVar12 = _DAT_130b720bcb8;
  cVar9 = DAT_130b720bca0;
  if ((DAT_130b720bca0 != '\0') && (_DAT_130b720bcb8 < 1)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72064a8);
    bVar6 = false;
  }
  if ((((cVar10 != '\0') && (cVar9 != '\0')) && (iVar12 <= iVar13)) && (iVar13 < iVar12 + 100)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72064e8);
    bVar6 = false;
  }
  iVar11 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if ((iVar11 == 0) && (iVar11 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0x35), iVar11 != 2)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7206528);
    bVar6 = false;
  }
  iVar11 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1e);
  if ((iVar11 == 3) || (iVar11 == 0)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7206568);
    bVar6 = false;
  }
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
  if (((_DAT_130b720bb48 <= 0.0) ||
      ((*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x22), _DAT_130b720bb48 <= 0.0)) ||
     ((*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x24), _DAT_130b720bb48 <= 0.0)) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72065a8);
    bVar6 = false;
  }
  iVar11 = _DAT_130b720bc50;
  if (((cVar10 == '\0') || (_DAT_130b720bc50 != 1)) || (0.0 < _DAT_130b720bc68)) {
    if (((cVar10 != '\0') && (_DAT_130b720bc50 == 0)) && (_DAT_130b720bc60 <= 0.0)) {
      uVar14 = 0x130b7206628;
      goto LAB_130b71d15d2;
    }
    if (((cVar10 != '\0') && (_DAT_130b720bc50 == 2)) &&
       ((uVar14 = 0x130b7206668, _DAT_130b720bc78 <= 0.0 || (_DAT_130b720bc70 <= 0.0))))
    goto LAB_130b71d15d2;
  }
  else {
    uVar14 = 0x130b72065e8;
LAB_130b71d15d2:
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,uVar14);
    bVar6 = false;
  }
  uVar4 = _DAT_130b720bcd8;
  if ((DAT_130b720bc80 == '\0') || (0.0 < _DAT_130b720bc88)) {
    if (_DAT_130b720bd40 < 0.0) goto LAB_130b71d166c;
    if (bVar6) {
      uVar15 = (ulonglong)_DAT_130b720bcd8;
      _DAT_130b720b390 = _DAT_130b7201030;
      if (uVar15 < 8) {
        _DAT_130b720b390 = *(undefined8 *)(uVar15 * 8 + 0x130b7209eb0);
      }
      if (cVar9 != '\0') {
        DAT_130b720b3e0 = DAT_130b720bcc0;
        DAT_130b720b3e1 = DAT_130b720bcc8;
        _DAT_130b720b3e8 = _DAT_130b720b3a0;
        _DAT_130b720b3f0 = iVar12;
        FUN_130b71d0a30(0x130b720b3f8,0x130b720bca8,0,0x130b7208038);
        _DAT_130b720b408 = _DAT_130b720b398;
        if ((_DAT_130b720bcd0 == 3) && (_DAT_130b720b390 = _DAT_130b7201030, uVar4 < 8)) {
          _DAT_130b720b390 = *(undefined8 *)(uVar15 * 8 + 0x130b7209eb0);
        }
        in_stack_fffffffffffffee0 = _DAT_130b720b398;
        FUN_130b71ef790(_DAT_130b720bcd0,&DAT_130b720bce0,_DAT_130b720bce8,_DAT_130b720bcf0,
                        _DAT_130b720bcf8,_DAT_130b720b398,_DAT_130b720b390);
        uVar20 = 0;
        (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b410,0,0);
        (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b840,0,0);
        (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b880,0,0);
        uVar15 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b720bb28,0x32);
        if (((uVar15 & 1) != 0) || (uVar20 = 1, (uVar15 & 2) != 0)) {
          _DAT_130b720b6f5 = uVar20;
        }
        FUN_130b71e0640();
        local_100 = 0;
        local_fc = 0;
        iVar12 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        if (iVar12 == 0) {
          FUN_130b71e3f70(0x130b72034c0);
          FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207b68);
          cVar10 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_100);
          if (cVar10 != '\0') {
            FUN_130b71e3f70(0x130b72034c0);
            FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207b78);
            (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
            if (0.0 < _DAT_130b720bb48) {
              DAT_130b720b8c0 = 1;
              FUN_130b71d0a30(0x130b720b8c1,0x130b720bb28,1,0x130b7207b88);
              FUN_130b71e3f70(0x130b72034e0);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207b98);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b8cd = (longlong)_DAT_130b720bb48;
              FUN_130b71e3f70(0x130b7203500);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207ba8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b8d5 = (int)_DAT_130b720bb48;
              FUN_130b71e3f70(0x130b7203520);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207bb8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b8d9 = SUB84(_DAT_130b720bb48,0);
              _DAT_130b720b8dd = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
              FUN_130b71e3f70(0x130b7203540);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207bc8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b8e1 = SUB84(_DAT_130b720bb48,0);
              _DAT_130b720b8e5 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
              FUN_130b71e3f70(0x130b7203560);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207bd8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b8e9 = (longlong)_DAT_130b720bb48;
              FUN_130b71e3f70(0x130b7203580);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207be8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              dVar1 = _DAT_130b7201038;
              uVar15 = (longlong)_DAT_130b720bb48 >> 0x3f &
                       (longlong)(_DAT_130b720bb48 - _DAT_130b7201038) | (longlong)_DAT_130b720bb48;
              _DAT_130b720b8f1 = (undefined4)uVar15;
              _DAT_130b720b8f5 = (undefined4)(uVar15 >> 0x20);
              FUN_130b71e3f70(0x130b72035a0);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207bf8);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              uVar15 = (longlong)_DAT_130b720bb48 >> 0x3f & (longlong)(_DAT_130b720bb48 - dVar1) |
                       (longlong)_DAT_130b720bb48;
              _DAT_130b720b8f9 = (undefined4)uVar15;
              _DAT_130b720b8fd = (undefined4)(uVar15 >> 0x20);
              FUN_130b71e3f70(0x130b72035c0);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7207c08);
              (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_100);
              _DAT_130b720b901 = (longlong)_DAT_130b720bb48;
              if (((_DAT_130b720b8cd == 0) ||
                  ((double)CONCAT44(_DAT_130b720b8dd,_DAT_130b720b8d9) <= 0.0)) ||
                 ((double)CONCAT44(_DAT_130b720b8e5,_DAT_130b720b8e1) <= 0.0)) {
                DAT_130b720b8c0 = 0;
                FUN_130b71d0a30(0x130b720b8c1,0x130b7201870,0,0x130b7207b28);
                _DAT_130b720b8cd = 0;
                _DAT_130b720b8fd = 0;
                _DAT_130b720b901 = 0;
                _DAT_130b720b8f5 = 0;
                _DAT_130b720b8f9 = 0;
                _DAT_130b720b905 = 0;
                _DAT_130b720b8ed = 0;
                _DAT_130b720b8f1 = 0;
                _DAT_130b720b8e5 = 0;
                _DAT_130b720b8e9 = 0;
                _DAT_130b720b8dd = 0;
                _DAT_130b720b8e1 = 0;
                _DAT_130b720b8d5 = 0;
                _DAT_130b720b8d9 = 0;
                FUN_130b71e4c00();
              }
              else {
                FUN_130b71e5750();
              }
            }
          }
        }
        FUN_130b71d0000(&local_100);
        _DAT_130b720b708 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,5,0);
        _DAT_130b720b710 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,1,0);
      }
      lVar18 = 0xf2ce01c4;
      if (DAT_130b720b2f2 == '\0') {
        lVar18 = 0;
      }
      lVar16 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
      if (lVar18 <= lVar16) {
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,3,1,0x590008,0x130b7203238);
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7206728);
        uVar14 = 1;
        lVar18 = _DAT_130b720b8e9;
        lVar16 = _DAT_130b720b901;
        goto LAB_130b71d169e;
      }
      (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
      if ((iVar11 == 3) && (_DAT_130b720b388 = _DAT_130b7201030, (ulonglong)_DAT_130b720bc58 < 8)) {
        _DAT_130b720b388 = *(undefined8 *)((ulonglong)_DAT_130b720bc58 * 8 + 0x130b7209eb0);
      }
      _DAT_130b720b90c = 0xffffffff;
      (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b910,0,0);
      _DAT_130b720b948 = 0x3ff0000000000000;
      _DAT_130b720b950 = 0;
      DAT_130b720b944 = 0;
      _DAT_130b720b958 = 0xffffffff;
      _DAT_130b720b9bc = 0xffffffff;
      DAT_130b720b9c0 = 0;
      DAT_130b720b9c1 = 0;
      DAT_130b720b9c2 = 0;
      _DAT_130b720b9d0 = 0;
      uRam00000130b720b9d8 = 0;
      _DAT_130b720b9e0 = 0;
      uRam00000130b720b9e8 = 0;
      _DAT_130b720b9f0 = 0;
      uRam00000130b720b9f8 = 0;
      _DAT_130b720ba00 = 0;
      uRam00000130b720ba08 = 0;
      _DAT_130b720ba10 = 0;
      uRam00000130b720ba18 = 0;
      _DAT_130b720ba20 = 0;
      uRam00000130b720ba28 = 0;
      _DAT_130b720ba30 = 0;
      uRam00000130b720ba38 = 0;
      _DAT_130b720ba40 = 0;
      uRam00000130b720ba48 = 0;
      _DAT_130b720ba50 = 0;
      uRam00000130b720ba58 = 0;
      _DAT_130b720ba60 = 0;
      DAT_130b720b95c = 0;
      DAT_130b720b95d = 0;
      _DAT_130b720b960 = 0;
      _DAT_130b720b968 = 0;
      _DAT_130b720b970 = 0;
      _DAT_130b720b978 = 0;
      FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
      _DAT_130b720b998 = 0;
      _DAT_130b720b9a0 = 0;
      _DAT_130b720b990 = 0;
      _DAT_130b720b9a8 = 0;
      FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
      local_100 = 0;
      local_f0 = 0;
      local_d0 = 0;
      local_e0 = 0;
      local_fc = 0;
      local_ec = 0;
      local_cc = 0;
      local_dc = 0;
      _DAT_130b720ba68 = -1;
      DAT_130b720ba6c = 0;
      DAT_130b720ba6d = 0;
      iVar12 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
      if (iVar12 == 0) {
        local_f0 = 0;
        local_ec = 0;
        FUN_130b71f6b50(0x130b7203da8);
        FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7208528);
        FUN_130b71d0a30(&local_f0,&local_100,0,0x130b7208538);
        local_d0 = 0;
        local_cc = 0;
        FUN_130b71f6b50(0x130b7204c98);
        FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7208548);
        FUN_130b71d0a30(&local_d0,&local_100,0,0x130b7208558);
        local_e0 = 0;
        local_dc = 0;
        FUN_130b71f6b50(0x130b7204cc8);
        FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b7208568);
        FUN_130b71d0a30(&local_e0,&local_100,0,0x130b7208578);
        if (DAT_130b720bd48 == '\0') {
LAB_130b71d237d:
          (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_f0);
          iVar12 = _DAT_130b720ba68;
        }
        else {
          cVar10 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_f0);
          if (cVar10 == '\0') goto LAB_130b71d237d;
          (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_f0);
          iVar12 = (int)_DAT_130b720bb48;
          iVar11 = FUN_130b71efc10();
          if (iVar11 != iVar12) goto LAB_130b71d237d;
        }
        _DAT_130b720ba68 = iVar12;
        cVar10 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_d0);
        if (cVar10 == '\0') {
LAB_130b71d23ec:
          DAT_130b720ba6c = 0;
        }
        else {
          (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_d0);
          DAT_130b720ba6c = 1;
          if (_DAT_130b720bb48 <= 0.0) goto LAB_130b71d23ec;
        }
        cVar10 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_e0);
        if (cVar10 == '\0') {
LAB_130b71d243b:
          DAT_130b720ba6d = 0;
        }
        else {
          (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_e0);
          DAT_130b720ba6d = 1;
          if (_DAT_130b720bb48 <= 0.0) goto LAB_130b71d243b;
        }
        FUN_130b71d0000(&local_e0);
        FUN_130b71d0000(&local_d0);
        FUN_130b71d0000(&local_f0);
      }
      FUN_130b71d0000(&local_100);
      FUN_130b71f0be0();
      local_100 = 0;
      local_fc = 0;
      iVar12 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
      if (-1 < iVar12 + -1) {
        lVar18 = (longlong)iVar13;
        dVar1 = *(double *)((ulonglong)(_DAT_130b720bc48 == 0) * 8 + 0x130b7201040);
        iVar13 = iVar12 + -1;
        local_b8 = lVar18;
        do {
          lVar16 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
          if (lVar16 != 0) {
            cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar16);
            if (cVar10 != '\0') {
              (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
              FUN_130b71d0a30(&local_100,0x130b720bb3c,1,0x130b72083b8);
              if (local_fc == _DAT_130b720bb2c) {
LAB_130b71d2665:
                lVar17 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
                if (lVar17 == lVar18) {
                  iVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                  lVar17 = (ulonglong)(iVar12 != 0) * 0x4c;
                  if ((&DAT_130b720b9d0)[lVar17] == '\0') {
                    local_b0 = lVar17;
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                    dVar8 = _DAT_130b720bb48;
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                    lVar18 = local_b8;
                    dVar19 = _DAT_130b720bb48;
                    uVar26 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
                    uVar20 = SUB84(_DAT_130b720bb48,0);
                    uVar15 = (ulonglong)_DAT_130b720bb48 >> 0x20;
                    if ((dVar8 <= 0.0) || (_DAT_130b720bb48 <= 0.0)) {
                      lVar17 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd);
                      (*(code *)0x7ff63a107f70)(0x130b53f81d8,3);
                      dVar8 = _DAT_130b720bb48;
                      uVar24 = 0;
                      uVar25 = 0;
                      local_c0 = lVar17;
                      if (lVar17 < 1) {
                        uVar22 = 0;
                        uVar23 = 0;
                      }
                      else {
                        cVar10 = (*(code *)0x7ff63a108b30)(0x130b53f81d8,lVar17);
                        lVar17 = local_c0;
                        uVar22 = 0;
                        uVar23 = 0;
                        if (cVar10 != '\0') {
                          (*(code *)0x7ff63a1085d0)(0x130b53f81d8,local_c0,0xc);
                          uVar22 = SUB84(_DAT_130b720bb48,0);
                          uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                          (*(code *)0x7ff63a1085d0)(0x130b53f81d8,lVar17,0xd);
                          uVar24 = SUB84(_DAT_130b720bb48,0);
                          uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                          lVar18 = local_b8;
                        }
                      }
                      uVar21 = (int)uVar15;
                      if (0.0 < (double)CONCAT44(uVar25,uVar24) || dVar19 <= 0.0) {
                        uVar20 = uVar24;
                        uVar21 = uVar25;
                      }
                      dVar19 = (double)CONCAT44(uVar23,uVar22);
                      if (((double)CONCAT44(uVar23,uVar22) <= 0.0) &&
                         (dVar19 = (double)CONCAT44(uVar23,uVar22),
                         0.0 <= (double)CONCAT44(uVar21,uVar20) &&
                         (double)CONCAT44(uVar21,uVar20) != 0.0)) {
                        dVar19 = *(double *)((ulonglong)(iVar12 == 0) * 8 + 0x130b7201050) +
                                 (double)CONCAT44(uVar21,uVar20);
                        if (iVar12 == 0) {
                          dVar19 = dVar19 - dVar1;
                        }
                        else {
                          dVar19 = dVar19 + dVar1;
                        }
                      }
                      if ((dVar19 <= 0.0) || ((double)CONCAT44(uVar21,uVar20) <= 0.0)) {
                        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar16,0x56,&local_100);
                        in_stack_fffffffffffffee0 = CONCAT44(uVar26,0x590008);
                        (*(code *)0x7ff63a0e49f0)
                                  (0x130b53f81d8,0xd,2,0x590008,0x130b7204980,
                                   in_stack_fffffffffffffee0,&local_100);
                        FUN_130b71e82f0(lVar16,0x130b72049d0);
                      }
                      else {
                        uVar14 = FUN_130b71f4e60(dVar19);
                        dVar19 = (double)FUN_130b71f4e60(CONCAT44(uVar21,uVar20));
                        lVar16 = local_c0;
                        in_stack_fffffffffffffee0 = local_c0;
                        FUN_130b71f5400(iVar12 == 0,
                                        *(double *)((ulonglong)(iVar12 == 0) * 8 + 0x130b7201050) +
                                        dVar19,uVar14,dVar19,dVar8,local_c0,0);
                        *(longlong *)(local_b0 + 0x130b720ba0a) = lVar16;
                        FUN_130b71e8bd0();
                      }
                    }
                  }
                }
              }
              else if ((local_fc != 0) && (_DAT_130b720bb2c != 0)) {
                uVar4 = *(uint *)(local_fc + -4);
                uVar5 = *(uint *)(_DAT_130b720bb2c + -4);
                uVar7 = uVar5;
                if (uVar4 < uVar5) {
                  uVar7 = uVar4;
                }
                iVar12 = uVar4 - uVar5;
                if (uVar7 != 0) {
                  uVar15 = 1;
                  do {
                    uVar2 = *(ushort *)(local_fc + -2 + uVar15 * 2);
                    uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar15 * 2);
                    if (uVar7 <= uVar15) break;
                    uVar15 = uVar15 + 1;
                  } while (uVar2 == uVar3);
                  if (uVar2 != uVar3) {
                    iVar12 = (uint)uVar2 - (uint)uVar3;
                  }
                }
                if (iVar12 == 0) goto LAB_130b71d2665;
              }
            }
          }
          bVar6 = 0 < iVar13;
          iVar13 = iVar13 + -1;
        } while (bVar6);
      }
      FUN_130b71d0000(&local_100);
      FUN_130b71e8bd0();
      if (DAT_130b720bd58 == '\0') {
        iVar13 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        uVar14 = 0;
        lVar18 = _DAT_130b720b8e9;
        lVar16 = _DAT_130b720b901;
        if (iVar13 == 1) goto LAB_130b71d169e;
        uVar14 = 0x1e;
      }
      else {
        FUN_130b71f97d0();
        FUN_130b71fb750();
        FUN_130b71fc9d0();
        uVar14 = 1;
      }
      (*(code *)0x7ff63a0e7210)(0x130b53f81d8,uVar14);
      uVar14 = 0;
      lVar18 = _DAT_130b720b8e9;
      lVar16 = _DAT_130b720b901;
      goto LAB_130b71d169e;
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72066a8);
    lVar16 = CONCAT44(_DAT_130b720b905,_DAT_130b720b901);
    lVar18 = CONCAT44(_DAT_130b720b8ed,_DAT_130b720b8e9);
    uVar14 = 0x7fff;
    if (0.0 <= _DAT_130b720bd40) goto LAB_130b71d169e;
LAB_130b71d166c:
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72066e8);
  }
  uVar14 = 0x7fff;
  lVar18 = CONCAT44(_DAT_130b720b8ed,_DAT_130b720b8e9);
  lVar16 = CONCAT44(_DAT_130b720b905,_DAT_130b720b901);
LAB_130b71d169e:
  _DAT_130b720b905 = (undefined4)((ulonglong)lVar16 >> 0x20);
  _DAT_130b720b901 = (undefined4)lVar16;
  _DAT_130b720b8ed = (undefined4)((ulonglong)lVar18 >> 0x20);
  _DAT_130b720b8e9 = (undefined4)lVar18;
  return uVar14;
}



/* Address: 130b71d2a80 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71d2a80(void)

{
  undefined8 *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  uint uVar7;
  bool bVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  longlong lVar18;
  undefined1 *puVar19;
  int *piVar20;
  code *pcVar21;
  undefined8 uVar22;
  double *pdVar23;
  undefined7 uVar25;
  longlong lVar24;
  undefined1 *puVar26;
  ulonglong *puVar27;
  char *pcVar28;
  longlong lVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  bool bVar34;
  bool bVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar41;
  undefined4 uVar42;
  double dVar38;
  double dVar39;
  undefined4 *puVar40;
  double dVar43;
  double dVar44;
  double dVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  undefined8 in_stack_fffffffffffffb60;
  int *in_stack_fffffffffffffb78;
  undefined4 *in_stack_fffffffffffffb88;
  double dVar52;
  undefined4 *in_stack_fffffffffffffb98;
  undefined8 in_stack_fffffffffffffba8;
  double in_stack_fffffffffffffbb8;
  undefined4 local_428;
  int local_420;
  longlong local_41c;
  char local_411;
  int local_410;
  longlong local_40c;
  longlong *local_400;
  undefined1 *local_3f8;
  ulonglong local_3f0;
  longlong local_3e8;
  int local_3dc;
  int local_3d8;
  undefined4 uStack_3d4;
  undefined4 uStack_3d0;
  int local_398;
  int iStack_394;
  uint uStack_390;
  undefined4 uStack_38c;
  undefined8 local_388;
  int iStack_380;
  undefined4 uStack_37c;
  undefined4 uStack_378;
  undefined4 uStack_374;
  undefined8 local_370;
  ulonglong local_368;
  undefined4 *local_360;
  double local_358;
  undefined8 local_350;
  undefined8 local_348;
  undefined8 local_340;
  undefined4 local_338;
  undefined4 local_334;
  undefined8 local_330;
  longlong local_328;
  undefined8 local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined8 local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 local_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined4 local_2a8;
  undefined8 local_2a4;
  undefined4 local_298;
  undefined8 local_294;
  int local_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  uint uStack_27c;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined4 local_258;
  undefined4 local_254;
  undefined8 local_250;
  undefined1 local_248 [136];
  longlong local_1c0;
  int local_1b8;
  int iStack_1b4;
  int iStack_1b0;
  undefined4 uStack_1ac;
  double local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined1 local_178 [312];
  
  dVar52 = _DAT_130b720bc98;
  dVar45 = _DAT_130b7201090;
  uVar32 = _DAT_130b7201080;
  local_2a8 = 0;
  local_410 = 0;
  local_298 = 0;
  local_2a4 = 0;
  local_40c = 0;
  local_294 = 0;
  local_3e8 = (longlong)_DAT_130b720bc30;
  local_3f0 = 0;
  local_3dc = _DAT_130b720bc90;
  uVar16 = 0;
  bVar35 = true;
  do {
    bVar34 = bVar35;
    lVar29 = (ulonglong)uVar16 * 0x4c;
    if ((&DAT_130b720b9d0)[lVar29] != '\0') {
      puVar19 = &DAT_130b720b9d0 + lVar29;
      lVar18 = FUN_130b71f5600();
      if (lVar18 == 0) {
        local_398 = 0;
        iStack_394 = 0;
        uStack_390 = 0;
        local_3f8 = puVar19;
        if (((*(longlong *)(lVar29 + 0x130b720ba02) != 0) &&
            (cVar9 = (*(code *)0x7ff63a108af0)(0x130b53f81d8), cVar9 != '\0')) &&
           (uVar30 = (*(code *)0x7ff63a108940)
                               (0x130b53f81d8,*(undefined8 *)(lVar29 + 0x130b720ba02),4),
           (uVar30 & 0xfffffffffffffffd) == 0)) {
LAB_130b71d2bca:
          FUN_130b71d0000(&local_398);
          *local_3f8 = 0;
          local_3f0 = CONCAT71((int7)((ulonglong)local_3f8 >> 8),1);
          goto LAB_130b71d2c08;
        }
        lVar18 = *(longlong *)(lVar29 + 0x130b720b9f2) + -10;
        if (lVar18 < 1) {
          lVar18 = 0;
        }
        uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
        cVar9 = (*(code *)0x7ff63a1084f0)(0x130b53f81d8,lVar18,uVar22);
        puVar40 = in_stack_fffffffffffffb88;
        dVar51 = in_stack_fffffffffffffbb8;
        if (cVar9 != '\0') {
          iVar13 = (*(code *)0x7ff63a108810)(0x130b53f81d8);
          puVar40 = in_stack_fffffffffffffb88;
          dVar51 = in_stack_fffffffffffffbb8;
          if (-1 < iVar13 + -1) {
            local_400 = (longlong *)(lVar29 + 0x130b720ba0a);
            iVar13 = iVar13 + -1;
            do {
              lVar18 = (*(code *)0x7ff63a108860)(0x130b53f81d8,iVar13);
              if (lVar18 != 0) {
                (*(code *)0x7ff63a1089d0)(0x130b53f81d8,lVar18,0);
                FUN_130b71d0a30(&local_398,0x130b720bb3c,1,0x130b7208368);
                lVar24 = CONCAT44(uStack_390,iStack_394);
                if (lVar24 == _DAT_130b720bb2c) {
LAB_130b71d2e75:
                  lVar24 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar18);
                  if (((lVar24 == local_3e8) &&
                      (uVar30 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar18),
                      (uVar30 & 0xfffffffffffffffd) == 0)) &&
                     (uVar30 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar18),
                     uVar30 == (*(char *)(lVar29 + 0x130b720b9d1) == '\0'))) {
                    lVar24 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar18,1);
                    lVar18 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar18);
                    if (((*(longlong *)(lVar29 + 0x130b720b9fa) == 0) ||
                        (lVar24 == *(longlong *)(lVar29 + 0x130b720b9fa))) ||
                       ((0 < *local_400 && (lVar18 == *local_400)))) goto LAB_130b71d2bca;
                  }
                }
                else if ((lVar24 != 0) && (_DAT_130b720bb2c != 0)) {
                  uVar16 = *(uint *)(lVar24 + -4);
                  uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
                  uVar5 = uVar4;
                  if (uVar16 < uVar4) {
                    uVar5 = uVar16;
                  }
                  iVar14 = uVar16 - uVar4;
                  if (uVar5 != 0) {
                    uVar30 = 1;
                    do {
                      uVar2 = *(ushort *)(lVar24 + -2 + uVar30 * 2);
                      uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar30 * 2);
                      if (uVar5 <= uVar30) break;
                      uVar30 = uVar30 + 1;
                    } while (uVar2 == uVar3);
                    if (uVar2 != uVar3) {
                      iVar14 = (uint)uVar2 - (uint)uVar3;
                    }
                  }
                  if (iVar14 == 0) goto LAB_130b71d2e75;
                }
              }
              bVar35 = 0 < iVar13;
              iVar13 = iVar13 + -1;
              puVar40 = in_stack_fffffffffffffb88;
              dVar51 = in_stack_fffffffffffffbb8;
            } while (bVar35);
          }
        }
        FUN_130b71d0000(&local_398);
        puVar1 = (undefined8 *)(lVar29 + 0x130b720b9fa);
        in_stack_fffffffffffffb88 = puVar40;
        in_stack_fffffffffffffbb8 = dVar51;
        if (((*(longlong *)(lVar29 + 0x130b720b9fa) != 0) &&
            (cVar9 = (*(code *)0x7ff63a108240)(0x130b53f81d8), in_stack_fffffffffffffb88 = puVar40,
            in_stack_fffffffffffffbb8 = dVar51, cVar9 == '\0')) &&
           (cVar9 = (*(code *)0x7ff63a108b30)(0x130b53f81d8,*puVar1),
           in_stack_fffffffffffffb88 = puVar40, in_stack_fffffffffffffbb8 = dVar51, cVar9 != '\0'))
        {
          uVar16 = (*(code *)0x7ff63a108620)(0x130b53f81d8,*puVar1,0xe);
          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
          in_stack_fffffffffffffb88 = puVar40;
          in_stack_fffffffffffffbb8 = dVar51;
          if ((uVar16 < 7) && ((100U >> (uVar16 & 0x1f) & 1) != 0)) {
            dVar50 = *(double *)(lVar29 + 0x130b720b9d2);
            cVar9 = *(char *)(lVar29 + 0x130b720b9d1);
            if (local_3dc == 1) {
              uVar36 = (undefined4)_DAT_130b720b3d0;
              uVar41 = (undefined4)(_DAT_130b720b3d0 >> 0x20);
              if (cVar9 != '\0') {
                uVar36 = (undefined4)(_DAT_130b720b3d0 ^ uVar32);
                uVar41 = (undefined4)((_DAT_130b720b3d0 ^ uVar32) >> 0x20);
              }
              dVar50 = dVar50 + (double)CONCAT44(uVar41,uVar36);
            }
            pcVar28 = (char *)(lVar29 + 0x130b720b9d1);
            if (((dVar52 <= 0.0) || (dVar50 <= 0.0)) ||
               (cVar10 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,&local_398),
               dVar49 = _DAT_130b720bb18, cVar10 == '\0')) {
LAB_130b71d35db:
              cVar9 = *pcVar28;
              dVar50 = *(double *)(lVar29 + 0x130b720b9d2);
              uVar41 = SUB84(dVar50,0);
              uVar42 = (undefined4)((ulonglong)dVar50 >> 0x20);
LAB_130b71d35e3:
              if (cVar9 == '\0') {
                _DAT_130b720b998 = *(double *)(lVar29 + 0x130b720b9da);
                _DAT_130b720b9a0 = *(double *)(lVar29 + 0x130b720b9e2);
                _DAT_130b720b990 = (double)CONCAT44(uVar42,uVar41);
                _DAT_130b720b9a8 = *(undefined8 *)(lVar29 + 0x130b720b9ea);
                FUN_130b71d0a30(0x130b720b9b0,0x130b720bc20,0,0x130b7208388);
                puVar19 = &DAT_130b720b95d;
                puVar26 = &DAT_130b720b9c1;
                in_stack_fffffffffffffb88 = puVar40;
                in_stack_fffffffffffffbb8 = dVar51;
              }
              else {
                _DAT_130b720b968 = *(double *)(lVar29 + 0x130b720b9da);
                _DAT_130b720b970 = *(double *)(lVar29 + 0x130b720b9e2);
                _DAT_130b720b960 = (double)CONCAT44(uVar42,uVar41);
                _DAT_130b720b978 = *(undefined8 *)(lVar29 + 0x130b720b9ea);
                FUN_130b71d0a30(0x130b720b980,0x130b720bc20,0,0x130b7208378);
                puVar19 = &DAT_130b720b95c;
                puVar26 = &DAT_130b720b9c0;
                in_stack_fffffffffffffb88 = puVar40;
                in_stack_fffffffffffffbb8 = dVar51;
              }
              *puVar19 = 1;
              *puVar26 = 0;
              uVar22 = 0x130b7201cf8;
              in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
              *local_3f8 = 0;
              if (*pcVar28 == '\0') {
                uVar22 = 0x130b7201d28;
              }
              (*(code *)0x7ff63a0e49f0)
                        (0x130b53f81d8,0xd,2,0x590008,0x130b7204630,in_stack_fffffffffffffb60,uVar22
                        );
            }
            else {
              uVar16 = uStack_390;
              uVar36 = uStack_38c;
              if (cVar9 != '\0') {
                uVar36 = (undefined4)((ulonglong)local_388 >> 0x20);
                uVar16 = SUB84(local_388,0);
              }
              if ((double)CONCAT44(uVar36,uVar16) <= 0.0) goto LAB_130b71d35db;
              if (cVar9 == '\0') {
                dVar50 = dVar50 - (double)CONCAT44(uStack_38c,uStack_390);
              }
              else {
                dVar50 = local_388 - dVar50;
              }
              in_stack_fffffffffffffbb8 = 0.0;
              if (0.0 <= dVar50) {
                in_stack_fffffffffffffbb8 = dVar50;
              }
              uVar46 = SUB84(_DAT_130b720bb18,0);
              uVar47 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
              (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
              in_stack_fffffffffffffb88 = *(undefined4 **)(lVar29 + 0x130b720b9d2);
              uVar41 = SUB84(in_stack_fffffffffffffb88,0);
              uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
              if (dVar49 <= _DAT_130b720bb48) {
                uVar46 = SUB84(_DAT_130b720bb48,0);
                uVar47 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
              }
              cVar9 = *pcVar28;
              if (in_stack_fffffffffffffbb8 <= (double)CONCAT44(uVar47,uVar46) * dVar45 + dVar52)
              goto LAB_130b71d35e3;
              bVar35 = cVar9 == '\0';
              puVar19 = &DAT_130b720b95c;
              in_stack_fffffffffffffba8 = CONCAT44(uVar36,uVar16);
              in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
              if (bVar35) {
                puVar19 = &DAT_130b720b95d;
              }
              *puVar19 = 0;
              uVar16 = _DAT_130b720bb20;
              *local_3f8 = 0;
              puVar19 = &DAT_130b720b9c0;
              if (bVar35) {
                puVar19 = &DAT_130b720b9c1;
              }
              uVar22 = 0x130b7201cf8;
              if (bVar35) {
                uVar22 = 0x130b7201d28;
              }
              *puVar19 = 1;
              in_stack_fffffffffffffb98 =
                   (undefined4 *)
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffb98 >> 0x20),uVar16);
              in_stack_fffffffffffffb78 =
                   (int *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffb78 >> 0x20),uVar16);
              (*(code *)0x7ff63a0e49f0)
                        (0x130b53f81d8,0xd,8,0x590008,0x130b7204518,in_stack_fffffffffffffb60,uVar22
                         ,0x520004,in_stack_fffffffffffffb78,0x580007,in_stack_fffffffffffffb88,
                         0x520004,in_stack_fffffffffffffb98,0x580007,in_stack_fffffffffffffba8,
                         0x580007,in_stack_fffffffffffffbb8,0x580007,dVar52);
            }
            FUN_130b71e8bd0();
            goto LAB_130b71d2c08;
          }
        }
        if (*(char *)(lVar29 + 0x130b720ba12) == '\0') {
          lVar18 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
          if (0x1d < lVar18 - *(longlong *)(lVar29 + 0x130b720b9f2)) {
            in_stack_fffffffffffffb88 = &local_298;
            *(undefined1 *)(lVar29 + 0x130b720ba12) = 1;
            (*(code *)0x7ff63a0ff6c0)
                      (0x130b53f81d8,*(undefined8 *)(lVar29 + 0x130b720ba02),0x56,
                       in_stack_fffffffffffffb88);
            in_stack_fffffffffffffb78 = &local_410;
            (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,*puVar1,0x56,in_stack_fffffffffffffb78);
            in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
            uVar22 = 0x130b7201cf8;
            if (*(char *)(lVar29 + 0x130b720b9d1) == '\0') {
              uVar22 = 0x130b7201d28;
            }
            (*(code *)0x7ff63a0e49f0)
                      (0x130b53f81d8,0xd,4,0x590008,0x130b7204938,in_stack_fffffffffffffb60,uVar22,
                       0x590008,in_stack_fffffffffffffb78,0x590008,in_stack_fffffffffffffb88);
          }
        }
      }
      else {
        if (*(char *)(lVar29 + 0x130b720ba13) != '\0') {
          FUN_130b71e82f0(lVar18,0x130b72045e8);
          goto LAB_130b71d2c08;
        }
        local_3f8 = puVar19;
        cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
        if (cVar9 != '\0') {
          uVar22 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd);
          *(undefined8 *)(lVar29 + 0x130b720ba0a) = uVar22;
        }
        local_3d8 = 0;
        local_420 = 0;
        uStack_3d4 = 0;
        uStack_3d0 = 0;
        local_41c = 0;
        cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
        if (cVar9 == '\0') {
LAB_130b71d4245:
          FUN_130b71d0000(&local_3d8);
        }
        else {
          iVar13 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
          dVar51 = (double)FUN_130b71f4e60((int)*(undefined8 *)(lVar29 + 0x130b720b9da));
          dVar50 = (double)FUN_130b71f4e60((int)*(undefined8 *)(lVar29 + 0x130b720b9e2));
          cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
          if (cVar9 == '\0') {
LAB_130b71d327c:
            cVar9 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,&local_1b8);
            dVar49 = _DAT_130b720bb18;
            if (cVar9 == '\0') goto LAB_130b71d4245;
            pdVar23 = &local_1a8;
            if (iVar13 == 0) {
              pdVar23 = (double *)&iStack_1b0;
            }
            dVar44 = *pdVar23;
            uVar37 = SUB84(_DAT_130b720bb18,0);
            uVar36 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
            (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
            uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
            if (dVar49 <= _DAT_130b720bb48) {
              uVar37 = SUB84(_DAT_130b720bb48,0);
              uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
            }
            dVar49 = (double)CONCAT44(uVar36,uVar37) * _DAT_130b7201060;
            bVar35 = dVar44 <= dVar50 + dVar49;
            if (iVar13 == 0) {
              bVar35 = dVar50 - dVar49 <= dVar44;
            }
            bVar8 = dVar51 - dVar49 <= dVar44;
            if (iVar13 == 0) {
              bVar8 = dVar44 <= dVar51 + dVar49;
            }
            if ((bVar8) || (bVar35)) {
              uVar22 = 0x130b72046c8;
              local_420 = 0;
              local_41c = 0;
              if (bVar8) {
                uVar22 = 0x130b7204678;
              }
              FUN_130b71d0a30(&local_420,uVar22,0,0x130b7208398);
              (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_3d8);
              in_stack_fffffffffffffb60 = CONCAT44(uVar41,0x590008);
              in_stack_fffffffffffffb78 = &local_420;
              (*(code *)0x7ff63a0e49f0)
                        (0x130b53f81d8,0xd,3,0x590008,0x130b7204718,in_stack_fffffffffffffb60,
                         &local_3d8,0x590008,&local_420);
              cVar9 = FUN_130b71e82f0(lVar18,&local_420);
              FUN_130b71d0000(&local_420);
            }
            else {
              (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
              dVar44 = dVar51;
              if (0.0 < _DAT_130b720bb48) {
                dVar44 = _DAT_130b720bb48;
                if (iVar13 == 0) {
                  if (_DAT_130b720bb48 <= dVar51) {
                    dVar44 = dVar51;
                  }
                }
                else if (dVar51 <= _DAT_130b720bb48) {
                  dVar44 = dVar51;
                }
              }
              puVar40 = (undefined4 *)FUN_130b71f5090(iVar13,dVar44);
              iVar15 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1f);
              iVar14 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x20);
              uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
              if (iVar14 < iVar15) {
                iVar14 = iVar15;
              }
              dVar44 = (double)iVar14 * _DAT_130b720bb18;
              if (iVar13 == 0) {
                dVar6 = (double)CONCAT44(uStack_1ac,iStack_1b0) - (double)puVar40;
                dVar43 = dVar50 - local_1a8;
              }
              else {
                dVar6 = (double)puVar40 - local_1a8;
                dVar43 = (double)CONCAT44(uStack_1ac,iStack_1b0) - dVar50;
              }
              if ((dVar44 <= dVar6) && (dVar44 <= dVar43)) {
                local_334 = 0;
                local_330 = 0;
                local_254 = 0;
                local_250 = 0;
                local_388 = 0.0;
                iStack_380 = 0;
                uStack_37c = 0;
                local_398 = 0;
                iStack_394 = 0;
                uStack_390 = 0;
                uStack_38c = 0;
                FUN_130b71d0000((longlong)&local_388 + 4);
                local_338 = 0;
                local_340 = 0;
                local_348 = 0;
                local_350 = 0;
                local_358 = 0.0;
                local_360 = (undefined4 *)0x0;
                local_368 = 0;
                local_370 = 0;
                uStack_378 = 0;
                uStack_374 = 0;
                FUN_130b71d0000(&local_334);
                local_2b0 = 0;
                local_2b8 = 0;
                local_2c0 = 0;
                local_2c8 = 0;
                local_2d0 = 0;
                local_2d8 = 0;
                local_2e0 = 0;
                local_2e8 = 0;
                local_2f0 = 0;
                local_2f8 = 0;
                local_300 = 0;
                local_308 = 0;
                local_310 = 0;
                local_318 = 0;
                local_320 = 0;
                local_268 = 0;
                uStack_260 = 0;
                local_278 = 0;
                uStack_270 = 0;
                local_288 = 0;
                uStack_284 = 0;
                uStack_280 = 0;
                uStack_27c = 0;
                local_258 = 0;
                FUN_130b71d0000(&local_254);
                (*(code *)0x7ff63a3fad20)(local_248,0,0x84);
                local_398 = 6;
                local_328 = lVar18;
                FUN_130b71d0a30((longlong)&local_388 + 4,0x130b720bb28,1,0x130b72083a8);
                _DAT_130b720bb10 = 0;
                _DAT_130b720bb80 = 0;
                DAT_130b720bb88 = 0;
                local_360 = puVar40;
                local_358 = dVar50;
                cVar9 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_398,&local_288);
                uVar37 = _DAT_130b720bb10;
                if ((cVar9 == '\0') ||
                   ((local_288 - 0x271bU < 0xfffffffd ||
                    (cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18), cVar9 == '\0')))) {
LAB_130b71d3bf8:
                  cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
                  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                  uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                  if (cVar9 != '\0') {
                    if ((local_288 - 0x2714U < 0x12) &&
                       ((0x30101U >> (local_288 - 0x2714U & 0x1f) & 1) != 0)) {
                      _DAT_130b720bb10 = 0;
                      _DAT_130b720bb80 = 0;
                      DAT_130b720bb88 = 0;
                      cVar9 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_398,&local_288);
                      uVar37 = _DAT_130b720bb10;
                      if ((cVar9 != '\0') &&
                         ((0xfffffffc < local_288 - 0x271bU &&
                          (cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18), cVar9 != '\0')))
                         ) {
                        iVar14 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                        (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                        dVar6 = _DAT_130b720bb48;
                        (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                        dVar43 = _DAT_130b720bb48;
                        dVar44 = _DAT_130b720bb18;
                        uVar36 = SUB84(_DAT_130b720bb18,0);
                        uVar41 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                        uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                        if (0.0 < dVar43) {
                          if (dVar44 <= _DAT_130b720bb48) {
                            uVar36 = SUB84(_DAT_130b720bb48,0);
                            uVar41 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                          }
                          dVar44 = (double)CONCAT44(uVar41,uVar36) * _DAT_130b7201060;
                          bVar35 = dVar51 + dVar44 < dVar6;
                          if (iVar14 == 0) {
                            bVar35 = dVar6 < dVar51 - dVar44;
                          }
                          if ((((double)((ulonglong)(dVar43 - dVar50) & _DAT_130b7201070) <= dVar44)
                              && (0.0 < dVar6)) && (!bVar35)) {
                            (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_3d8);
                            in_stack_fffffffffffffb60 = CONCAT44(uVar42,0x590008);
                            (*(code *)0x7ff63a0e49f0)
                                      (0x130b53f81d8,0xd,2,0x590008,0x130b7204820,
                                       in_stack_fffffffffffffb60,&local_3d8);
                            goto LAB_130b71d4035;
                          }
                        }
                      }
                      cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
                      uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                      uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                      uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                      if (cVar9 == '\0') goto LAB_130b71d4035;
                    }
                    iVar14 = local_288;
                    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_3d8);
                    in_stack_fffffffffffffb98 = &local_254;
                    in_stack_fffffffffffffb88 = (undefined4 *)CONCAT44(uVar42,iVar14);
                    in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar41,uVar37);
                    in_stack_fffffffffffffb60 = CONCAT44(uVar36,0x590008);
                    (*(code *)0x7ff63a0e49f0)
                              (0x130b53f81d8,0xd,5,0x590008,0x130b7204880,in_stack_fffffffffffffb60,
                               &local_3d8,0x520004,in_stack_fffffffffffffb78,0x530014,
                               in_stack_fffffffffffffb88,0x590008,in_stack_fffffffffffffb98);
                    cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18);
                    if (cVar9 == '\0') {
LAB_130b71d4224:
                      FUN_130b71d0000(&local_254);
                      FUN_130b71d0000(&local_334);
                      FUN_130b71d0000((longlong)&local_388 + 4);
                      goto LAB_130b71d4245;
                    }
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                    if (iVar13 == 0) {
                      if ((0.0 < _DAT_130b720bb48) && (dVar51 - dVar49 <= _DAT_130b720bb48))
                      goto LAB_130b71d4224;
                    }
                    else if ((0.0 < _DAT_130b720bb48) && (_DAT_130b720bb48 <= dVar51 + dVar49))
                    goto LAB_130b71d4224;
                    cVar9 = FUN_130b71e82f0(lVar18,0x130b72048d8);
                    FUN_130b71d0000(&local_254);
                    FUN_130b71d0000(&local_334);
                    FUN_130b71d0000((longlong)&local_388 + 4);
                    goto LAB_130b71d3ef2;
                  }
                }
                else {
                  iVar14 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                  (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                  dVar6 = _DAT_130b720bb48;
                  (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                  dVar43 = _DAT_130b720bb48;
                  dVar44 = _DAT_130b720bb18;
                  uVar36 = SUB84(_DAT_130b720bb18,0);
                  uVar41 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                  if (dVar43 <= 0.0) goto LAB_130b71d3bf8;
                  if (dVar44 <= _DAT_130b720bb48) {
                    uVar36 = SUB84(_DAT_130b720bb48,0);
                    uVar41 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                  }
                  dVar44 = (double)CONCAT44(uVar41,uVar36) * _DAT_130b7201060;
                  bVar35 = dVar51 + dVar44 < dVar6;
                  if (iVar14 == 0) {
                    bVar35 = dVar6 < dVar51 - dVar44;
                  }
                  if (((dVar44 < (double)((ulonglong)(dVar43 - dVar50) & _DAT_130b7201070)) ||
                      (dVar6 <= 0.0)) || (bVar35)) goto LAB_130b71d3bf8;
                }
LAB_130b71d4035:
                FUN_130b71d0000(&local_254);
                FUN_130b71d0000(&local_334);
                FUN_130b71d0000((longlong)&local_388 + 4);
                goto LAB_130b71d406a;
              }
              in_stack_fffffffffffffb78 = (int *)0x130b7203778;
              in_stack_fffffffffffffb88 = (undefined4 *)0x130b7203778;
              if (dVar44 <= dVar43) {
                in_stack_fffffffffffffb88 = (undefined4 *)0x130b7203748;
              }
              if (dVar44 <= dVar6) {
                in_stack_fffffffffffffb78 = (int *)0x130b7203748;
              }
              (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_3d8);
              in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
              (*(code *)0x7ff63a0e49f0)
                        (0x130b53f81d8,0xd,4,0x590008,0x130b7204778,in_stack_fffffffffffffb60,
                         &local_3d8,0x590008,in_stack_fffffffffffffb78,0x590008,
                         in_stack_fffffffffffffb88);
              cVar9 = FUN_130b71e82f0(lVar18,0x130b72047d8);
            }
LAB_130b71d3ef2:
            FUN_130b71d0000(&local_3d8);
            if (cVar9 == '\0') goto LAB_130b71d2c08;
          }
          else {
            iVar14 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
            (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
            dVar44 = _DAT_130b720bb48;
            (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
            dVar6 = _DAT_130b720bb48;
            dVar49 = _DAT_130b720bb18;
            uVar37 = SUB84(_DAT_130b720bb18,0);
            uVar36 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
            (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
            if (dVar6 <= 0.0) goto LAB_130b71d327c;
            if (dVar49 <= _DAT_130b720bb48) {
              uVar37 = SUB84(_DAT_130b720bb48,0);
              uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
            }
            dVar49 = (double)CONCAT44(uVar36,uVar37) * _DAT_130b7201060;
            bVar35 = dVar51 + dVar49 < dVar44;
            if (iVar14 == 0) {
              bVar35 = dVar44 < dVar51 - dVar49;
            }
            if (((dVar49 < (double)((ulonglong)(dVar6 - dVar50) & _DAT_130b7201070)) ||
                (dVar44 <= 0.0)) || (bVar35)) goto LAB_130b71d327c;
LAB_130b71d406a:
            FUN_130b71d0000(&local_3d8);
          }
          *local_3f8 = 0;
          local_3f0 = CONCAT71((int7)((ulonglong)local_3f8 >> 8),1);
        }
      }
    }
LAB_130b71d2c08:
    uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffbb8 >> 0x20);
    uVar16 = 1;
    bVar35 = false;
  } while (bVar34);
  if ((char)local_3f0 != '\0') {
    FUN_130b71e8bd0();
  }
  FUN_130b71d0000(&local_298);
  FUN_130b71d0000();
  FUN_130b71f4a40();
  local_3f8 = (undefined1 *)CONCAT71(local_3f8._1_7_,DAT_130b720bca0);
  if (DAT_130b720bca0 != '\0') {
    local_398 = 0;
    local_288 = 0;
    iStack_394 = 0;
    uStack_390 = 0;
    uStack_284 = 0;
    uStack_280 = 0;
    if ((DAT_130b720b8c0 != '\0') && (cVar9 = FUN_130b71e5750(), cVar9 == '\0')) {
      lVar29 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
      uVar16 = _DAT_130b720b7b0;
      uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
      uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
      uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb98 >> 0x20);
      if ((0 < CONCAT44(_DAT_130b720b8ed,_DAT_130b720b8e9)) &&
         (CONCAT44(_DAT_130b720b8ed,_DAT_130b720b8e9) + 300 < lVar29)) {
        uVar22 = CONCAT44(_DAT_130b720b8e5,_DAT_130b720b8e1);
        in_stack_fffffffffffffba8 = CONCAT44(_DAT_130b720b8dd,_DAT_130b720b8d9);
        uVar46 = _DAT_130b720b8cd;
        (*(code *)0x7ff63a0ff6c0)
                  (0x130b53f81d8,CONCAT44(_DAT_130b720b8fd,_DAT_130b720b8f9),0x56,&local_288);
        (*(code *)0x7ff63a0ff6c0)
                  (0x130b53f81d8,CONCAT44(_DAT_130b720b8f5,_DAT_130b720b8f1),0x56,&local_398);
        in_stack_fffffffffffffb78 = &local_288;
        in_stack_fffffffffffffb98 = (undefined4 *)CONCAT44(uVar42,uVar16);
        in_stack_fffffffffffffb88 = (undefined4 *)CONCAT44(uVar41,uVar46);
        in_stack_fffffffffffffb60 = CONCAT44(uVar36,0x590008);
        (*(code *)0x7ff63a0e49f0)
                  (0x130b53f81d8,0xd,8,0x590008,0x130b7203690,in_stack_fffffffffffffb60,&local_398,
                   0x590008,in_stack_fffffffffffffb78,0x520004,in_stack_fffffffffffffb88,0x520004,
                   in_stack_fffffffffffffb98,0x580007,in_stack_fffffffffffffba8,0x520004,
                   CONCAT44(uVar37,uVar16),0x580007,uVar22);
        DAT_130b720b8c0 = '\0';
        FUN_130b71d0a30(0x130b720b8c1,0x130b7201870,0,0x130b7207b28);
        _DAT_130b720b8fd = 0;
        _DAT_130b720b901 = 0;
        _DAT_130b720b8f5 = 0;
        _DAT_130b720b8f9 = 0;
        _DAT_130b720b905 = 0;
        _DAT_130b720b8ed = 0;
        _DAT_130b720b8f1 = 0;
        _DAT_130b720b8e5 = 0;
        _DAT_130b720b8e9 = 0;
        _DAT_130b720b8dd = 0;
        _DAT_130b720b8e1 = 0;
        _DAT_130b720b8d5 = 0;
        _DAT_130b720b8d9 = 0;
        _DAT_130b720b8cd = 0;
        FUN_130b71e4c00();
      }
    }
    FUN_130b71d0000(&local_288);
    FUN_130b71d0000(&local_398);
    iVar13 = (*(code *)0x7ff63a107da0)();
    if (-1 < iVar13 + -1) {
      lVar29 = (longlong)_DAT_130b720bcb8;
      iVar14 = _DAT_130b720bcb8 + 100;
      do {
        iVar13 = iVar13 + -1;
        piVar20 = (int *)(*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
        if ((((piVar20 != (int *)0x0) &&
             (cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,piVar20), cVar9 != '\0')) &&
            (lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc), lVar29 <= lVar18)) &&
           (lVar18 < iVar14)) {
          local_3d8 = 0;
          uStack_3d4 = 0;
          cVar9 = FUN_130b71e3130(piVar20,&local_3d8);
          if (cVar9 != '\0') {
            local_398 = 0;
            local_288 = 0;
            iStack_394 = 0;
            uStack_390 = 0;
            uStack_284 = 0;
            uStack_280 = 0;
            cVar9 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,piVar20);
            if (cVar9 == '\0') {
              FUN_130b71e3490(piVar20);
              pcVar21 = FUN_130b71e3740;
LAB_130b71d4877:
              (*pcVar21)(piVar20);
            }
            else {
              lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
              if ((lVar29 <= lVar18) && (lVar18 < iVar14)) {
                local_1b8 = 0;
                iStack_1b4 = 0;
                cVar9 = FUN_130b71e3130(piVar20,&local_1b8);
                if ((cVar9 != '\0') &&
                   (dVar45 = (double)CONCAT44(iStack_1b4,local_1b8), 0.0 < dVar45)) {
                  local_288 = 0;
                  uStack_284 = 0;
                  uStack_280 = 0;
                  (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
                  FUN_130b71d0a30(&local_398,0x130b720bb3c,1,0x130b7207c78);
                  FUN_130b71d0a30(&local_288,&local_398,0,0x130b7207c88);
                  lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_288,1);
                  dVar52 = _DAT_130b720bb48;
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_288,4);
                  if ((0.0 < dVar52) && (0.0 < _DAT_130b720bb48)) {
                    if (lVar18 == 1) {
                      if (_DAT_130b720bb48 <= dVar45) goto LAB_130b71d4834;
                    }
                    else if ((lVar18 == 0) && (dVar45 <= dVar52)) {
LAB_130b71d4834:
                      FUN_130b71e6960(piVar20,0);
                    }
                    piVar20 = &local_288;
                    pcVar21 = FUN_130b71d0000;
                    goto LAB_130b71d4877;
                  }
                  FUN_130b71d0000(&local_288);
                }
              }
            }
            FUN_130b71d0000();
          }
        }
      } while (0 < iVar13);
    }
    FUN_130b71e3e10();
  }
  cVar9 = FUN_130b71eb190();
  local_3f0 = CONCAT71(local_3f0._1_7_,cVar9);
  if ((cVar9 != '\0') && (cVar9 = FUN_130b71eb190(), cVar9 != '\0')) {
    DAT_130b720b95d = '\0';
    _DAT_130b720b960 = 0.0;
    DAT_130b720b95c = '\0';
    _DAT_130b720b968 = 0.0;
    _DAT_130b720b970 = 0.0;
    _DAT_130b720b978 = 0;
    FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
    _DAT_130b720b998 = 0.0;
    _DAT_130b720b9a0 = 0.0;
    _DAT_130b720b990 = 0.0;
    _DAT_130b720b9a8 = 0;
    FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
    FUN_130b71eb3a0();
    uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_398);
    iVar13 = iStack_394 * 100 + local_398 * 10000 + uStack_390;
    if (_DAT_130b720b720 != iVar13) {
      _DAT_130b720b720 = iVar13;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204348);
      FUN_130b71e8bd0();
    }
    FUN_130b71eb510();
    FUN_130b71eb6f0();
  }
  FUN_130b71f7df0();
  cVar9 = DAT_130b720bd48;
  iVar13 = _DAT_130b720ba68;
  if (DAT_130b720bd48 == '\0') {
    bVar35 = true;
    if (0 < _DAT_130b720ba68) {
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
    }
  }
  else {
    bVar35 = true;
    if (0 < _DAT_130b720ba68) {
      iVar15 = FUN_130b71efc10();
      iVar14 = _DAT_130b720ba68;
      if (iVar13 == iVar15) {
        bVar35 = false;
      }
      else {
        _DAT_130b720ba68 = -1;
        FUN_130b71f7b60();
        if (0 < iVar14) {
          (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d08);
        }
      }
    }
  }
  if (DAT_130b720b2f0 == '\x01') {
    iVar13 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
    if (-1 < iVar13 + -1) {
      iVar14 = 0;
      do {
        iVar13 = iVar13 + -1;
        uVar22 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
        cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar22);
        if (cVar10 != '\0') {
          lVar29 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
          iVar14 = iVar14 + (uint)(lVar29 == local_3e8);
        }
      } while (0 < iVar13);
      if (iVar14 != 0) goto LAB_130b71d4c9d;
    }
    iVar13 = (*(code *)0x7ff63a1081a0)(0x130b53f81d8);
    if (0 < iVar13) {
      iVar14 = 0;
      iVar13 = 0;
      do {
        uVar22 = (*(code *)0x7ff63a1081f0)(0x130b53f81d8,iVar14);
        cVar10 = (*(code *)0x7ff63a108240)(0x130b53f81d8,uVar22);
        if (cVar10 != '\0') {
          lVar29 = (*(code *)0x7ff63a108310)(0x130b53f81d8,0xf);
          iVar13 = iVar13 + (uint)(lVar29 == local_3e8);
        }
        iVar14 = iVar14 + 1;
        iVar15 = (*(code *)0x7ff63a1081a0)();
      } while (iVar14 < iVar15);
      if (iVar13 != 0) goto LAB_130b71d4c9d;
    }
    lVar29 = 0;
    do {
      lVar24 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
      lVar18 = *(longlong *)(lVar29 + 0x130b720b2c0);
      iVar13 = (*(code *)0x7ff63a0e2010)();
      if (lVar18 - iVar13 < lVar24) {
        lVar24 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
        lVar18 = *(longlong *)(lVar29 + 0x130b720b2c0);
        iVar13 = (*(code *)0x7ff63a0e2010)();
        if (lVar24 < iVar13 + lVar18) goto LAB_130b71d87ec;
      }
      lVar29 = lVar29 + 8;
    } while (lVar29 != 0x30);
  }
LAB_130b71d4c9d:
  lVar29 = 0x5e0be100;
  if (DAT_130b720b2f1 == '\0') {
    lVar29 = 0;
  }
  lVar18 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  if (lVar18 < lVar29) goto LAB_130b71d87ec;
  lVar29 = 0xf2ce01c4;
  if (DAT_130b720b2f2 == '\0') {
    lVar29 = 0;
  }
  lVar18 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  if (lVar29 <= lVar18) {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,3,1,0x590008,0x130b7203238);
    (*(code *)0x7ff63a0e2120)(0x130b53f81d8);
  }
  local_288 = 0;
  local_1b8 = 0;
  local_3d8 = 0;
  uStack_284 = 0;
  uStack_280 = 0;
  iStack_1b4 = 0;
  iStack_1b0 = 0;
  uStack_3d4 = 0;
  uStack_3d0 = 0;
  iVar13 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar13 != 0) {
    local_3d8 = 0;
    uStack_3d4 = 0;
    uStack_3d0 = 0;
    DAT_130b720b2b2 = 0;
    uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a0fcc50)(0x130b53f81d8,uVar22,1);
    FUN_130b71d0a30(&local_1b8,0x130b720bb3c,1,0x130b7207588);
    FUN_130b71d0a30(&local_3d8,&local_1b8,0,0x130b7207598);
    lVar29 = CONCAT44(uStack_3d0,uStack_3d4);
    if (_DAT_130b720b354 != lVar29) {
      if ((_DAT_130b720b354 != 0) && (lVar29 != 0)) {
        uVar16 = *(uint *)(_DAT_130b720b354 + -4);
        uVar4 = *(uint *)(lVar29 + -4);
        uVar5 = uVar4;
        if (uVar16 < uVar4) {
          uVar5 = uVar16;
        }
        iVar13 = uVar16 - uVar4;
        if (uVar5 != 0) {
          uVar32 = 1;
          do {
            uVar2 = *(ushort *)(_DAT_130b720b354 + -2 + uVar32 * 2);
            uVar3 = *(ushort *)(lVar29 + -2 + uVar32 * 2);
            if (uVar5 <= uVar32) break;
            uVar32 = uVar32 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar13 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar13 == 0) goto LAB_130b71d5786;
      }
      FUN_130b71d0a30(0x130b720b350,&local_3d8,0,0x130b72075a8);
      local_398 = 0x10059;
      iStack_394 = 0xc;
      _DAT_130b720b35c = 0;
      uStack_390 = 0;
      uStack_38c = 0;
      local_388 = 0.0;
      iStack_380 = 0;
      uStack_37c = 0;
      uStack_378 = 0;
      uStack_374 = 0;
      local_370 = 0;
      local_368 = local_368 & 0xffffffff00000000;
      uVar16 = FUN_130b71d01d0(_DAT_130b720b30c,&local_398);
      if (0 < (int)uVar16) {
        uVar32 = (ulonglong)uStack_390;
        uVar30 = 0;
        do {
          if (uVar32 <= uVar30) goto LAB_130b71d94c9;
          FUN_130b71d0a30(&local_1b8,CONCAT44(uStack_378,uStack_37c) + uVar30 * 0xc,0,0x130b72075b8)
          ;
          FUN_130b71dfdf0(&local_1b8);
          FUN_130b71d0a30(&local_288,0x130b720bb3c,1,0x130b72075c8);
          if (uStack_390 <= uVar30) goto LAB_130b71d9489;
          FUN_130b71d0a30(uVar30 * 0xc + CONCAT44(uStack_378,uStack_37c),&local_288,0,0x130b72075d8)
          ;
          uVar32 = (ulonglong)uStack_390;
          if (uVar32 <= uVar30) goto LAB_130b71d94a9;
          lVar18 = CONCAT44(uStack_3d0,uStack_3d4);
          lVar29 = *(longlong *)(CONCAT44(uStack_378,uStack_37c) + 4 + uVar30 * 0xc);
          if (lVar29 == lVar18) {
LAB_130b71d517f:
            _DAT_130b720b35c = 1;
            _DAT_130b720b33c = 700;
            if (DAT_130b720b314 == '\0') {
              _DAT_130b720b33c = 0;
            }
            _DAT_130b720b340 = 300;
            if (DAT_130b720b315 == '\0') {
              _DAT_130b720b340 = 0;
            }
            _DAT_130b720b344 = 0x32;
            if (DAT_130b720b316 == '\0') {
              _DAT_130b720b344 = 0;
            }
            _DAT_130b720b348 = 10;
            if (DAT_130b720b317 == '\0') {
              _DAT_130b720b348 = 0;
            }
            break;
          }
          if ((lVar29 != 0) && (lVar18 != 0)) {
            uVar4 = *(uint *)(lVar29 + -4);
            uVar5 = *(uint *)(lVar18 + -4);
            uVar7 = uVar5;
            if (uVar4 < uVar5) {
              uVar7 = uVar4;
            }
            iVar13 = uVar4 - uVar5;
            if (uVar7 != 0) {
              uVar33 = 1;
              do {
                uVar2 = *(ushort *)(lVar29 + -2 + uVar33 * 2);
                uVar3 = *(ushort *)(lVar18 + -2 + uVar33 * 2);
                if (uVar7 <= uVar33) break;
                uVar33 = uVar33 + 1;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar13 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar13 == 0) goto LAB_130b71d517f;
          }
          uVar30 = uVar30 + 1;
        } while (uVar30 != uVar16);
      }
      if (_DAT_130b720b35c == 0) {
        uVar16 = FUN_130b71d01d0(_DAT_130b720b31c,&local_398);
        if (0 < (int)uVar16) {
          uVar32 = (ulonglong)uStack_390;
          uVar30 = 0;
          do {
            if (uVar32 <= uVar30) goto LAB_130b71d9589;
            FUN_130b71d0a30(&local_1b8,CONCAT44(uStack_378,uStack_37c) + uVar30 * 0xc,0,
                            0x130b72075e8);
            FUN_130b71dfdf0(&local_1b8);
            FUN_130b71d0a30(&local_288,0x130b720bb3c,1,0x130b72075f8);
            if (uStack_390 <= uVar30) goto LAB_130b71d9549;
            FUN_130b71d0a30(uVar30 * 0xc + CONCAT44(uStack_378,uStack_37c),&local_288,0,
                            0x130b7207608);
            uVar32 = (ulonglong)uStack_390;
            if (uVar32 <= uVar30) goto LAB_130b71d9569;
            lVar18 = CONCAT44(uStack_3d0,uStack_3d4);
            lVar29 = *(longlong *)(CONCAT44(uStack_378,uStack_37c) + 4 + uVar30 * 0xc);
            if (lVar29 == lVar18) {
LAB_130b71d53cb:
              _DAT_130b720b35c = 2;
              _DAT_130b720b33c = 0x4b0;
              if (DAT_130b720b324 == '\0') {
                _DAT_130b720b33c = 0;
              }
              _DAT_130b720b340 = 700;
              if (DAT_130b720b325 == '\0') {
                _DAT_130b720b340 = 0;
              }
              _DAT_130b720b344 = 0x50;
              if (DAT_130b720b326 == '\0') {
                _DAT_130b720b344 = 0;
              }
              _DAT_130b720b348 = 10;
              if (DAT_130b720b327 == '\0') {
                _DAT_130b720b348 = 0;
              }
              break;
            }
            if ((lVar29 != 0) && (lVar18 != 0)) {
              uVar4 = *(uint *)(lVar29 + -4);
              uVar5 = *(uint *)(lVar18 + -4);
              uVar7 = uVar5;
              if (uVar4 < uVar5) {
                uVar7 = uVar4;
              }
              iVar13 = uVar4 - uVar5;
              if (uVar7 != 0) {
                uVar33 = 1;
                do {
                  uVar2 = *(ushort *)(lVar29 + -2 + uVar33 * 2);
                  uVar3 = *(ushort *)(lVar18 + -2 + uVar33 * 2);
                  if (uVar7 <= uVar33) break;
                  uVar33 = uVar33 + 1;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar13 = (uint)uVar2 - (uint)uVar3;
                }
              }
              if (iVar13 == 0) goto LAB_130b71d53cb;
            }
            uVar30 = uVar30 + 1;
          } while (uVar30 != uVar16);
        }
        if ((_DAT_130b720b35c == 0) &&
           (uVar16 = FUN_130b71d01d0(_DAT_130b720b32c,&local_398), 0 < (int)uVar16)) {
          uVar32 = (ulonglong)uStack_390;
          uVar30 = 0;
          do {
            if (uVar32 <= uVar30) goto LAB_130b71d95e9;
            FUN_130b71d0a30(&local_1b8,CONCAT44(uStack_378,uStack_37c) + uVar30 * 0xc,0,
                            0x130b7207618);
            FUN_130b71dfdf0(&local_1b8);
            FUN_130b71d0a30(&local_288,0x130b720bb3c,1,0x130b7207628);
            if (uStack_390 <= uVar30) goto LAB_130b71d95a9;
            FUN_130b71d0a30(uVar30 * 0xc + CONCAT44(uStack_378,uStack_37c),&local_288,0,
                            0x130b7207638);
            uVar32 = (ulonglong)uStack_390;
            if (uVar32 <= uVar30) goto LAB_130b71d95c9;
            lVar18 = CONCAT44(uStack_3d0,uStack_3d4);
            lVar29 = *(longlong *)(CONCAT44(uStack_378,uStack_37c) + 4 + uVar30 * 0xc);
            if (lVar29 == lVar18) {
LAB_130b71d561b:
              _DAT_130b720b35c = 3;
              _DAT_130b720b33c = 0x898;
              if (DAT_130b720b334 == '\0') {
                _DAT_130b720b33c = 0;
              }
              _DAT_130b720b340 = 0x578;
              if (DAT_130b720b335 == '\0') {
                _DAT_130b720b340 = 0;
              }
              _DAT_130b720b344 = 0x50;
              if (DAT_130b720b336 == '\0') {
                _DAT_130b720b344 = 0;
              }
              _DAT_130b720b348 = 10;
              if (DAT_130b720b337 == '\0') {
                _DAT_130b720b348 = 0;
              }
              break;
            }
            if ((lVar29 != 0) && (lVar18 != 0)) {
              uVar4 = *(uint *)(lVar29 + -4);
              uVar5 = *(uint *)(lVar18 + -4);
              uVar7 = uVar5;
              if (uVar4 < uVar5) {
                uVar7 = uVar4;
              }
              iVar13 = uVar4 - uVar5;
              if (uVar7 != 0) {
                uVar33 = 1;
                do {
                  uVar2 = *(ushort *)(lVar29 + -2 + uVar33 * 2);
                  uVar3 = *(ushort *)(lVar18 + -2 + uVar33 * 2);
                  if (uVar7 <= uVar33) break;
                  uVar33 = uVar33 + 1;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar13 = (uint)uVar2 - (uint)uVar3;
                }
              }
              if (iVar13 == 0) goto LAB_130b71d561b;
            }
            uVar30 = uVar30 + 1;
          } while (uVar30 != uVar16);
        }
      }
      if (_DAT_130b720b360 != _DAT_130b720b35c) {
        DAT_130b720b2b2 = 1;
      }
      if (_DAT_130b720b35c == 0) {
        _DAT_130b720b33c = 0x28;
        if (DAT_130b720b33b == '\0') {
          _DAT_130b720b33c = 0;
        }
        _DAT_130b720b340 = 300;
        if (DAT_130b720b338 == '\0') {
          _DAT_130b720b340 = 0;
        }
        _DAT_130b720b344 = 0x32;
        if (DAT_130b720b339 == '\0') {
          _DAT_130b720b344 = 0;
        }
        _DAT_130b720b348 = 10;
        if (DAT_130b720b33a == '\0') {
          _DAT_130b720b348 = 0;
        }
      }
      _DAT_130b720b360 = _DAT_130b720b35c;
      FUN_130b71d0df0(&local_398);
    }
LAB_130b71d5786:
    FUN_130b71d0000(&local_3d8);
  }
  FUN_130b71d0000(&local_1b8);
  FUN_130b71d0000(&local_288);
  local_411 = FUN_130b71e7e30();
  cVar10 = DAT_130b720bc18;
  if ((((local_411 != '\0') && (DAT_130b720bc18 != '\0')) &&
      (cVar11 = FUN_130b71e7e30(), cVar11 != '\0')) &&
     (DAT_130b720b95c != '\0' || DAT_130b720b95d != '\0')) {
    DAT_130b720b95d = '\0';
    DAT_130b720b95c = '\0';
    _DAT_130b720b960 = 0.0;
    _DAT_130b720b968 = 0.0;
    _DAT_130b720b970 = 0.0;
    _DAT_130b720b978 = 0;
    FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
    _DAT_130b720b998 = 0.0;
    _DAT_130b720b9a0 = 0.0;
    _DAT_130b720b990 = 0.0;
    _DAT_130b720b9a8 = 0;
    FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
    FUN_130b71e8bd0();
  }
  lVar29 = _DAT_130b720ba98;
  _DAT_130b720ba98 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,0x4018,0);
  local_400 = (longlong *)CONCAT71(local_400._1_7_,cVar10);
  if (_DAT_130b720ba98 != lVar29) {
    local_1b8 = 0;
    local_3d8 = 0;
    local_420 = 0;
    iStack_1b4 = 0;
    iStack_1b0 = 0;
    uStack_3d4 = 0;
    uStack_3d0 = 0;
    local_41c = 0;
    (*(code *)0x7ff63a101c40)(0x130b53f81d8,&local_288);
    iVar13 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
    if (iVar13 == 0) {
      cVar11 = '\x01';
    }
    else {
      local_420 = 0;
      local_41c = 0;
      uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
      (*(code *)0x7ff63a0fcc50)(0x130b53f81d8,uVar22,1);
      cVar11 = '\x01';
      FUN_130b71d0a30(&local_3d8,0x130b720bb3c,1,0x130b72074f8);
      FUN_130b71d0a30(&local_420,&local_3d8,0,0x130b7207508);
      local_398 = 0x10059;
      iStack_394 = 0xc;
      uStack_390 = 0;
      uStack_38c = 0;
      local_388 = 0.0;
      iStack_380 = 0;
      uStack_37c = 0;
      uStack_378 = 0;
      uStack_374 = 0;
      local_370 = 0;
      local_368 = local_368 & 0xffffffff00000000;
      uVar16 = FUN_130b71d01d0(_DAT_130b720b2fc,&local_398);
      if (0 < (int)uVar16) {
        uVar32 = (ulonglong)uStack_390;
        uVar30 = 0;
        do {
          if (uVar32 <= uVar30) goto LAB_130b71d9529;
          FUN_130b71d0a30(&local_3d8,CONCAT44(uStack_378,uStack_37c) + uVar30 * 0xc,0,0x130b7207518)
          ;
          FUN_130b71dfdf0(&local_3d8);
          FUN_130b71d0a30(&local_1b8,0x130b720bb3c,1,0x130b7207528);
          if (uStack_390 <= uVar30) goto LAB_130b71d94e9;
          FUN_130b71d0a30(uVar30 * 0xc + CONCAT44(uStack_378,uStack_37c),&local_1b8,0,0x130b7207538)
          ;
          uVar32 = (ulonglong)uStack_390;
          if (uVar32 <= uVar30) goto LAB_130b71d9509;
          lVar29 = *(longlong *)(CONCAT44(uStack_378,uStack_37c) + 4 + uVar30 * 0xc);
          if (lVar29 == local_41c) {
LAB_130b71d5c30:
            cVar11 = '\0';
            goto LAB_130b71d5c37;
          }
          if ((lVar29 != 0) && (local_41c != 0)) {
            uVar4 = *(uint *)(lVar29 + -4);
            uVar5 = *(uint *)(local_41c + -4);
            uVar7 = uVar5;
            if (uVar4 < uVar5) {
              uVar7 = uVar4;
            }
            iVar13 = uVar4 - uVar5;
            if (uVar7 != 0) {
              uVar33 = 1;
              do {
                uVar2 = *(ushort *)(lVar29 + -2 + uVar33 * 2);
                uVar3 = *(ushort *)(local_41c + -2 + uVar33 * 2);
                if (uVar7 <= uVar33) break;
                uVar33 = uVar33 + 1;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar13 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar13 == 0) goto LAB_130b71d5c30;
          }
          uVar30 = uVar30 + 1;
        } while (uVar30 != uVar16);
        cVar11 = '\x01';
LAB_130b71d5c37:
        cVar10 = (char)local_400;
      }
      FUN_130b71d0df0(&local_398);
      FUN_130b71d0000(&local_420);
    }
    FUN_130b71d0000(&local_3d8);
    FUN_130b71d0000(&local_1b8);
    DAT_130b720b304 = cVar11;
  }
  iVar13 = _DAT_130b720bcb8;
  cVar11 = (char)local_3f0;
  if (((char)local_3f8 != '\0') && ((char)local_3f0 == '\0')) {
    DAT_130b720b3e0 = DAT_130b720bcc0;
    DAT_130b720b3e1 = DAT_130b720bcc8;
    lVar29 = (longlong)_DAT_130b720bcb8;
    _DAT_130b720b3e8 = _DAT_130b720b3a0;
    _DAT_130b720b3f0 = _DAT_130b720bcb8;
    FUN_130b71d0a30(0x130b720b3f8,0x130b720bca8,0,0x130b7208038);
    _DAT_130b720b408 = _DAT_130b720b398;
    if ((_DAT_130b720bcd0 == 3) &&
       (_DAT_130b720b390 = _DAT_130b7201098, (ulonglong)_DAT_130b720bcd8 < 8)) {
      _DAT_130b720b390 = *(undefined8 *)((ulonglong)_DAT_130b720bcd8 * 8 + 0x130b7209eb0);
    }
    in_stack_fffffffffffffb60 = _DAT_130b720b398;
    FUN_130b71ef790(_DAT_130b720bcd0,_DAT_130b720bce0,(int)_DAT_130b720bce8,_DAT_130b720bcf0,
                    _DAT_130b720bcf8,_DAT_130b720b398,_DAT_130b720b390);
    if ((((bVar35 && DAT_130b720ba6e == '\0') && (DAT_130b720ba6c == '\0')) &&
        (DAT_130b720ba6d == '\0')) && (DAT_130b720b304 != '\0')) {
      uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_398);
      if ((((((iStack_380 == 1) && (DAT_130b720bd00 == '\0')) ||
            ((iStack_380 == 2 && (DAT_130b720bd08 == '\0')))) ||
           ((iStack_380 == 3 && (DAT_130b720bd10 == '\0')))) ||
          ((iStack_380 == 4 && (DAT_130b720bd18 == '\0')))) ||
         (((iStack_380 == 5 && (DAT_130b720bd20 == '\0')) ||
          (uVar22 = 1, iStack_380 - 6U < 0xfffffffb)))) goto LAB_130b71d5f23;
    }
    else {
LAB_130b71d5f23:
      uVar22 = 0;
    }
    FUN_130b71eb8d0(uVar22);
    iVar14 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
    if (iVar14 == 0) {
      local_398 = 0;
      iStack_394 = 0;
      uStack_390 = 0;
      iVar14 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
      if (((iVar14 == 0) &&
          (lVar18 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,1,0), lVar18 != 0)) &&
         (lVar18 != _DAT_130b720b718)) {
        _DAT_130b720b718 = lVar18;
        FUN_130b71e0640();
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
        dVar45 = _DAT_130b720bb48;
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
        dVar52 = _DAT_130b720bb48;
        if (((0.0 < dVar45) && (0.0 < _DAT_130b720bb48)) && (0.0 < _DAT_130b720b81c)) {
          iVar14 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
          if (-1 < iVar14 + -1) {
            local_1c0 = (longlong)(iVar13 + 100);
            iVar13 = iVar14 + -1;
            do {
              lVar18 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
              if ((lVar18 != 0) &&
                 (cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18), cVar10 != '\0')) {
                (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
                FUN_130b71d0a30(&local_398,0x130b720bb3c,1,0x130b7207ca8);
                lVar24 = CONCAT44(uStack_390,iStack_394);
                if (lVar24 == _DAT_130b720bb2c) {
LAB_130b71d89b2:
                  lVar24 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
                  if ((lVar29 <= lVar24) && (lVar24 < local_1c0)) {
                    lVar24 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,4);
                    dVar51 = _DAT_130b720bb48;
                    if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                      dVar51 = (double)(longlong)_DAT_130b720bb48;
                      uVar32 = (ulonglong)_DAT_130b720b7b0;
                      if (10 < _DAT_130b720b7b0) {
                        uVar32 = 0xb;
                      }
                      dVar51 = (double)(longlong)
                                       ((_DAT_130b720bb48 - dVar51) *
                                        *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                       *(double *)
                                        ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72010a0)) /
                               *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar51;
                    }
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                    dVar50 = _DAT_130b720bb48;
                    if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                      dVar50 = (double)(longlong)_DAT_130b720bb48;
                      uVar32 = (ulonglong)_DAT_130b720b7b0;
                      if (10 < _DAT_130b720b7b0) {
                        uVar32 = 0xb;
                      }
                      dVar50 = (double)(longlong)
                                       ((_DAT_130b720bb48 - dVar50) *
                                        *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                       *(double *)
                                        ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72010a0)) /
                               *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar50;
                    }
                    local_288 = 0;
                    uStack_284 = 0;
                    local_1b8 = 0;
                    iStack_1b4 = 0;
                    FUN_130b71e37c0(lVar18,&local_288,&local_1b8);
                    dVar49 = (double)CONCAT44(iStack_1b4,local_1b8);
                    if (0.0 < dVar49) {
                      if (lVar24 == 1) {
                        puVar40 = (undefined4 *)(dVar51 - _DAT_130b720b824);
                        if ((longlong)(double)puVar40 != -0x8000000000000000) {
                          dVar44 = (double)(longlong)(double)puVar40;
                          uVar32 = (ulonglong)_DAT_130b720b7b0;
                          if (10 < _DAT_130b720b7b0) {
                            uVar32 = 0xb;
                          }
                          puVar40 = (undefined4 *)
                                    ((double)(longlong)
                                             (((double)puVar40 - dVar44) *
                                              *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                             *(double *)
                                              ((ulonglong)(0.0 < (double)puVar40) * 8 +
                                              0x130b72010a0)) /
                                     *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar44);
                        }
                        bVar34 = true;
                        if ((0.0 < dVar50) && (dVar50 - _DAT_130b720b7a0 <= (double)puVar40)) {
                          bVar34 = false;
                        }
                        if ((((dVar52 < dVar51 - _DAT_130b720b81c) && (bVar34)) &&
                            (dVar52 < (double)puVar40 - _DAT_130b720b82c)) &&
                           (_DAT_130b720b834 + dVar49 < dVar52)) {
                          cVar10 = FUN_130b71e5c50(lVar18,puVar40);
                          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                          uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                          if (cVar10 != '\0') {
                            FUN_130b71e3600(lVar18,puVar40);
                            uVar16 = _DAT_130b720b7b0;
                            (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_398);
                            uVar22 = 0x130b7203c60;
                            in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar36,uVar16);
LAB_130b71d8880:
                            in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
                            (*(code *)0x7ff63a0e49f0)
                                      (0x130b53f81d8,0xd,4,0x590008,uVar22,in_stack_fffffffffffffb60
                                       ,&local_398,0x520004,in_stack_fffffffffffffb78,0x580007,
                                       puVar40);
                            in_stack_fffffffffffffb88 = puVar40;
                          }
                        }
                      }
                      else if (lVar24 == 0) {
                        puVar40 = (undefined4 *)(_DAT_130b720b824 + dVar51);
                        if ((longlong)(double)puVar40 != -0x8000000000000000) {
                          dVar44 = (double)(longlong)(double)puVar40;
                          uVar32 = (ulonglong)_DAT_130b720b7b0;
                          if (10 < _DAT_130b720b7b0) {
                            uVar32 = 0xb;
                          }
                          puVar40 = (undefined4 *)
                                    ((double)(longlong)
                                             (((double)puVar40 - dVar44) *
                                              *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                             *(double *)
                                              ((ulonglong)(0.0 < (double)puVar40) * 8 +
                                              0x130b72010a0)) /
                                     *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar44);
                        }
                        dVar51 = dVar51 + _DAT_130b720b81c;
                        if ((longlong)dVar51 != -0x8000000000000000) {
                          dVar44 = (double)(longlong)dVar51;
                          uVar32 = (ulonglong)_DAT_130b720b7b0;
                          if (10 < _DAT_130b720b7b0) {
                            uVar32 = 0xb;
                          }
                          dVar51 = (double)(longlong)
                                           ((dVar51 - dVar44) *
                                            *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                           *(double *)
                                            ((ulonglong)(0.0 < dVar51) * 8 + 0x130b72010a0)) /
                                   *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar44;
                        }
                        bVar12 = 1;
                        if ((0.0 < dVar50) && ((double)puVar40 <= dVar50 + _DAT_130b720b7a0)) {
                          bVar12 = 0;
                        }
                        dVar50 = _DAT_130b720b82c + (double)puVar40;
                        if ((longlong)dVar50 != -0x8000000000000000) {
                          dVar44 = (double)(longlong)dVar50;
                          uVar32 = (ulonglong)_DAT_130b720b7b0;
                          if (10 < _DAT_130b720b7b0) {
                            uVar32 = 0xb;
                          }
                          dVar50 = (double)(longlong)
                                           ((dVar50 - dVar44) *
                                            *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                           *(double *)
                                            ((ulonglong)(0.0 < dVar50) * 8 + 0x130b72010a0)) /
                                   *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar44;
                        }
                        if (((!(bool)(bVar12 ^ 1 | dVar45 <= dVar51)) && (dVar50 < dVar45)) &&
                           (dVar45 < dVar49 - _DAT_130b720b834)) {
                          cVar10 = FUN_130b71e5c50(lVar18,puVar40);
                          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                          uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                          if (cVar10 != '\0') {
                            FUN_130b71e3600(lVar18,puVar40);
                            uVar16 = _DAT_130b720b7b0;
                            (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar18,0x56,&local_398);
                            in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar36,uVar16);
                            uVar22 = 0x130b7203c10;
                            goto LAB_130b71d8880;
                          }
                        }
                      }
                    }
                  }
                }
                else if ((lVar24 != 0) && (_DAT_130b720bb2c != 0)) {
                  uVar16 = *(uint *)(lVar24 + -4);
                  uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
                  uVar5 = uVar4;
                  if (uVar16 < uVar4) {
                    uVar5 = uVar16;
                  }
                  iVar14 = uVar16 - uVar4;
                  if (uVar5 != 0) {
                    uVar32 = 1;
                    do {
                      uVar2 = *(ushort *)(lVar24 + -2 + uVar32 * 2);
                      uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar32 * 2);
                      if (uVar5 <= uVar32) break;
                      uVar32 = uVar32 + 1;
                    } while (uVar2 == uVar3);
                    if (uVar2 != uVar3) {
                      iVar14 = (uint)uVar2 - (uint)uVar3;
                    }
                  }
                  if (iVar14 == 0) goto LAB_130b71d89b2;
                }
              }
              bVar34 = 0 < iVar13;
              iVar13 = iVar13 + -1;
            } while (bVar34);
          }
        }
      }
      FUN_130b71d0000(&local_398);
      cVar11 = (char)local_3f0;
      cVar10 = (char)local_400;
    }
  }
  if ((cVar10 != '\0') && (iVar13 = FUN_130b71efc10(), iVar13 != _DAT_130b720b958)) {
    _DAT_130b720b958 = iVar13;
  }
  if (((((bool)(bVar35 & cVar10 != '\0' &
               ((cVar11 == '\0' && DAT_130b720ba6e == '\0') && local_411 == '\0'))) &&
       (DAT_130b720ba6c == '\0')) && (DAT_130b720ba6d == '\0')) && (DAT_130b720b304 != '\0')) {
    FUN_130b71f6830();
    local_3d8 = 0;
    local_420 = 0;
    uStack_3d4 = 0;
    uStack_3d0 = 0;
    local_41c = 0;
    uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_288);
    iVar13 = FUN_130b71efc10();
    if (iVar13 != _DAT_130b720b958) {
      _DAT_130b720b958 = iVar13;
    }
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_1b8);
    iVar13 = iStack_1b4 * 100 + local_1b8 * 10000 + iStack_1b0;
    if (iVar13 != _DAT_130b720b9bc) {
      _DAT_130b720b9bc = iVar13;
      FUN_130b71f08e0(&DAT_130b720b9c0,&DAT_130b720b9c1);
    }
    if (iVar13 != _DAT_130b720b90c) {
      FUN_130b71d0a30(&local_420,0x130b720bb28,1,0x130b7209dc0);
      cVar10 = FUN_130b71f4c90();
      if (cVar10 != '\0') {
        DAT_130b720b95d = '\0';
        _DAT_130b720b960 = 0.0;
        DAT_130b720b95c = '\0';
        _DAT_130b720b968 = 0.0;
        _DAT_130b720b970 = 0.0;
        _DAT_130b720b978 = 0;
        FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
        _DAT_130b720b998 = 0.0;
        _DAT_130b720b9a0 = 0.0;
        _DAT_130b720b990 = 0.0;
        _DAT_130b720b9a8 = 0;
        FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
      }
      FUN_130b71e8bd0();
    }
    uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_398);
    if ((iStack_380 != 0) && (iStack_380 != 6)) {
      cVar10 = DAT_130b720bd00;
      if (iStack_380 == 1) {
joined_r0x0130b71d676f:
        if (cVar10 != '\0') {
LAB_130b71d62c3:
          uVar22 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
          (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar22,&local_398);
          if ((((((int)uStack_390 < 0x18 || iStack_394 != 0xc) || 0x1a < (int)uStack_390) &&
               (iStack_394 != 0xc || uStack_390 != 0x1f)) && (uStack_390 != 1 || iStack_394 != 1))
             && ((((cVar10 = FUN_130b71e6fc0(), cVar10 == '\0' &&
                   ((int)(uint)DAT_130b720b3a8 <= (int)uStack_27c)) &&
                  ((uStack_27c != DAT_130b720b3a8 ||
                   ((int)((uint)DAT_130b720b3a9 + (uint)DAT_130b720b3a9 * 4) <= (int)local_278))))
                 && ((iVar13 != _DAT_130b720b90c &&
                     (iVar14 = (*(code *)0x7ff63a102a30)(0x130b53f81d8,0x130b7201850,0x4018),
                     1 < iVar14)))))) {
            FUN_130b71d0a30(&local_420,0x130b720bb28,1,0x130b7209dd0);
            iVar14 = FUN_130b71efd10(&local_420,local_3e8);
            if ((iVar14 < 1) &&
               (FUN_130b71d0a30(&local_3d8,0x130b720bb28,1,0x130b7209de0),
               DAT_130b720b95d == '\0' && DAT_130b720b95c == '\0')) {
              (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,0x4018,1);
              dVar45 = _DAT_130b720bb48;
              (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,0x4018,1);
              dVar52 = _DAT_130b720bb48;
              if (((0.0 < dVar45) && (0.0 < _DAT_130b720bb48)) &&
                 (_DAT_130b72010b0 <= dVar45 - _DAT_130b720bb48)) {
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
                dVar49 = _DAT_130b720bb48;
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
                dVar50 = _DAT_130b720bb48;
                iVar14 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1f);
                dVar51 = dVar50 - dVar49;
                dVar44 = 0.0;
                if (0.0 <= dVar51) {
                  dVar44 = dVar51;
                }
                dVar50 = dVar50 + (double)iVar14 * _DAT_130b720bb18;
                dVar49 = dVar49 - (double)iVar14 * _DAT_130b720bb18;
                dVar51 = 0.0;
                if (0.0 <= dVar44 * _DAT_130b720b3c8) {
                  dVar51 = dVar44 * _DAT_130b720b3c8;
                }
                dVar45 = dVar45 + dVar51;
                dVar52 = dVar52 - dVar51;
                uVar32 = -(ulonglong)(dVar52 < dVar49);
                bVar34 = DAT_130b720b9c0 == '\0';
                uVar30 = -(ulonglong)(dVar50 < dVar45);
                bVar35 = DAT_130b720b9c1 == '\0';
                dVar51 = (double)(uVar30 & (ulonglong)dVar45 |
                                 ~uVar30 & (ulonglong)(_DAT_130b720bb18 * _DAT_130b72010b8 + dVar50)
                                 );
                dVar50 = (double)(uVar32 & (ulonglong)dVar52 |
                                 ~uVar32 & (ulonglong)(dVar49 - _DAT_130b720bb18 * _DAT_130b72010b8)
                                 );
                if (DAT_130b720b3c0 == '\x01') {
                  bVar34 = DAT_130b720b9c0 == '\0';
                  (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,0x4018,0);
                  dVar49 = _DAT_130b720bb48;
                  (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,0x4018,0);
                  if (DAT_130b720b9c2 == '\0') {
                    dVar45 = dVar51;
                    dVar52 = dVar50;
                  }
                  bVar35 = DAT_130b720bc38 == '\0' &&
                           (dVar52 + _DAT_130b720bb18 + _DAT_130b720bb18 < _DAT_130b720bb48 &&
                           bVar35);
                  bVar34 = dVar49 < dVar45 - (_DAT_130b720bb18 + _DAT_130b720bb18) && bVar34;
                }
                else if (DAT_130b720bc38 != '\0') {
                  bVar35 = false;
                }
                if (((bVar35) && (DAT_130b720bc40 != '\0')) &&
                   (cVar10 = FUN_130b71efc70(), cVar10 == '\0')) {
                  bVar35 = true;
                }
                else {
                  bVar35 = !bVar35;
                }
                uVar16 = _DAT_130b720bb20;
                dVar45 = *(double *)((ulonglong)(_DAT_130b720bc48 == 0) * 8 + 0x130b72010c0);
                dVar52 = dVar50 + dVar45;
                dVar49 = dVar50;
                if ((longlong)dVar50 != -0x8000000000000000) {
                  dVar49 = (double)(longlong)dVar50;
                  uVar32 = 0xb;
                  if (_DAT_130b720bb20 < 0xb) {
                    uVar32 = (ulonglong)_DAT_130b720bb20;
                  }
                  dVar49 = (double)(longlong)
                                   ((dVar50 - dVar49) * *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar50) * 8 + 0x130b72010a0)) /
                           *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar49;
                }
                if ((longlong)dVar52 != -0x8000000000000000) {
                  uVar32 = 0xb;
                  if (_DAT_130b720bb20 < 0xb) {
                    uVar32 = (ulonglong)_DAT_130b720bb20;
                  }
                  dVar52 = (double)(longlong)
                                   ((dVar52 - (double)(longlong)dVar52) *
                                    *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar52) * 8 + 0x130b72010a0)) /
                           *(double *)(&DAT_130b7201710 + uVar32 * 8) + (double)(longlong)dVar52;
                }
                dVar44 = dVar50 + _DAT_130b72010d0;
                if ((longlong)dVar44 != -0x8000000000000000) {
                  dVar44 = (double)(longlong)dVar44;
                  uVar32 = 0xb;
                  if (_DAT_130b720bb20 < 0xb) {
                    uVar32 = (ulonglong)_DAT_130b720bb20;
                  }
                  dVar44 = (double)(longlong)
                                   (((dVar50 + _DAT_130b72010d0) - dVar44) *
                                    *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                   *(double *)
                                    ((ulonglong)(0.0 < dVar50 + _DAT_130b72010d0) * 8 +
                                    0x130b72010a0)) / *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                           dVar44;
                }
                uVar22 = FUN_130b71f4940(SUB84(dVar45,0));
                if (bVar34) {
                  _DAT_130b720b970 = _DAT_130b72010d8 + dVar51;
                  if ((longlong)_DAT_130b720b970 != -0x8000000000000000) {
                    dVar50 = (double)(longlong)_DAT_130b720b970;
                    uVar32 = 0xb;
                    if (uVar16 < 0xb) {
                      uVar32 = (ulonglong)uVar16;
                    }
                    _DAT_130b720b970 =
                         (double)(longlong)
                                 ((_DAT_130b720b970 - dVar50) *
                                  *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                 *(double *)
                                  ((ulonglong)(0.0 < _DAT_130b720b970) * 8 + 0x130b72010a0)) /
                         *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar50;
                  }
                  _DAT_130b720b968 = dVar51 - dVar45;
                  if ((longlong)_DAT_130b720b968 != -0x8000000000000000) {
                    dVar45 = (double)(longlong)_DAT_130b720b968;
                    uVar32 = 0xb;
                    if (uVar16 < 0xb) {
                      uVar32 = (ulonglong)uVar16;
                    }
                    _DAT_130b720b968 =
                         (double)(longlong)
                                 ((_DAT_130b720b968 - dVar45) *
                                  *(double *)(&DAT_130b7201710 + uVar32 * 8) +
                                 *(double *)
                                  ((ulonglong)(0.0 < _DAT_130b720b968) * 8 + 0x130b72010a0)) /
                         *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar45;
                  }
                  if ((longlong)dVar51 != -0x8000000000000000) {
                    dVar45 = (double)(longlong)dVar51;
                    uVar32 = 0xb;
                    if (uVar16 < 0xb) {
                      uVar32 = (ulonglong)uVar16;
                    }
                    dVar51 = (double)(longlong)
                                     ((dVar51 - dVar45) * *(double *)(&DAT_130b7201710 + uVar32 * 8)
                                     + *(double *)((ulonglong)(0.0 < dVar51) * 8 + 0x130b72010a0)) /
                             *(double *)(&DAT_130b7201710 + uVar32 * 8) + dVar45;
                  }
                  _DAT_130b720b960 = dVar51;
                  _DAT_130b720b978 = uVar22;
                  FUN_130b71d0a30(0x130b720b980,0x130b720bc20,0,0x130b7209df0);
                  DAT_130b720b95c = '\x01';
                  bVar8 = true;
                }
                else {
                  bVar8 = false;
                }
                if (!bVar35) {
                  _DAT_130b720b990 = dVar49;
                  _DAT_130b720b998 = dVar52;
                  _DAT_130b720b9a0 = dVar44;
                  _DAT_130b720b9a8 = uVar22;
                  FUN_130b71d0a30(0x130b720b9b0,0x130b720bc20,0,0x130b7209e00);
                  DAT_130b720b95d = '\x01';
                  bVar8 = true;
                }
                if (DAT_130b720b3c0 == '\x01') {
                  bVar35 = (bool)(bVar35 & (bVar34 ^ 1U));
                }
                else {
                  bVar35 = false;
                }
                if ((bVar8) || (bVar35)) {
                  DAT_130b720b9c2 = '\0';
                  _DAT_130b720b90c = iVar13;
                  FUN_130b71e8bd0();
                }
              }
            }
          }
        }
      }
      else if ((((iStack_380 != 2) || (DAT_130b720bd08 != '\0')) &&
               ((iStack_380 != 3 || (DAT_130b720bd10 != '\0')))) &&
              ((iStack_380 != 4 || (DAT_130b720bd18 != '\0')))) {
        cVar10 = DAT_130b720bd20;
        if (iStack_380 == 5) goto joined_r0x0130b71d676f;
        goto LAB_130b71d62c3;
      }
    }
    FUN_130b71d0000(&local_420);
    FUN_130b71d0000(&local_3d8);
    local_398 = 0;
    local_288 = 0;
    iStack_394 = 0;
    uStack_390 = 0;
    uStack_284 = 0;
    uStack_280 = 0;
    FUN_130b71d0000(&local_288);
    FUN_130b71d0000(&local_398);
    FUN_130b71f6830();
    cVar10 = (char)local_400;
  }
  FUN_130b71d0a30(&local_2a8,0x130b720bb28,1,0x130b7209e30);
  iVar13 = FUN_130b71efd10(&local_2a8,local_3e8);
  dVar45 = _DAT_130b720bb18;
  if ((cVar10 != '\0') || (cVar10 = '\0', 0 < iVar13)) {
    if (_DAT_130b720b35c == 0) {
      pdVar23 = (double *)&DAT_130b720b3b0;
      local_410 = 0;
      local_40c = 0;
      if (local_3dc == 1) {
        pdVar23 = (double *)&DAT_130b720b3d0;
      }
      puVar27 = (ulonglong *)&DAT_130b720b3b8;
      if (local_3dc == 1) {
        puVar27 = (ulonglong *)&DAT_130b720b3d8;
      }
      dVar45 = *pdVar23;
      uVar32 = *puVar27;
      iVar13 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
      if (-1 < iVar13 + -1) {
        uVar30 = _DAT_130b7201080 ^ uVar32;
        iVar13 = iVar13 + -1;
        do {
          lVar29 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
          cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29);
          if (cVar10 != '\0') {
            (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
            FUN_130b71d0a30(&local_410,0x130b720bb3c,1,0x130b7209e20);
            if (local_40c == _DAT_130b720bb2c) {
LAB_130b71d7405:
              iVar14 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
              if ((int)local_3e8 == iVar14) {
                iVar14 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,4);
                dVar52 = _DAT_130b720bb48;
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                dVar51 = _DAT_130b720bb48;
                if (iVar14 == 0) {
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
                  dVar49 = _DAT_130b720bb48;
                  uVar37 = SUB84(_DAT_130b720bb48,0);
                  uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                  dVar50 = (double)FUN_130b71efa90(lVar29,_DAT_130b720bb48);
                  if (dVar50 < dVar49) goto LAB_130b71d74b4;
                }
                else {
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
                  dVar49 = _DAT_130b720bb48;
                  uVar37 = SUB84(_DAT_130b720bb48,0);
                  uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                  dVar50 = (double)FUN_130b71efa90(lVar29,_DAT_130b720bb48);
                  if (dVar49 < dVar50) {
LAB_130b71d74b4:
                    dVar50 = (double)CONCAT44(uVar36,uVar37);
                  }
                }
                if (0 < (int)_DAT_130b720b918) {
                  uVar33 = 0;
                  pcVar28 = (char *)(_DAT_130b720b92c + 0x10);
                  do {
                    if ((*pcVar28 != '\0') && (*(longlong *)(pcVar28 + -0x10) == lVar29)) {
                      if (-1 < (int)(uint)uVar33) {
                        if (_DAT_130b720b918 <= (uint)uVar33) goto LAB_130b71d9609;
                        *(double *)(pcVar28 + -8) = dVar50;
                        goto joined_r0x0130b71d754b;
                      }
                      break;
                    }
                    uVar33 = uVar33 + 1;
                    pcVar28 = pcVar28 + 0x11;
                  } while (_DAT_130b720b918 != uVar33);
                }
                FUN_130b71efa90(lVar29,dVar50);
joined_r0x0130b71d754b:
                if (iVar14 == 0) {
                  dVar52 = (double)CONCAT44(uVar36,uVar37) - dVar52;
                }
                else {
                  dVar52 = dVar52 - (double)CONCAT44(uVar36,uVar37);
                }
                if (dVar45 <= dVar52) {
                  uVar41 = (int)uVar30;
                  uVar42 = (int)(uVar30 >> 0x20);
                  if (iVar14 != 0) {
                    uVar41 = (undefined4)uVar32;
                    uVar42 = (undefined4)(uVar32 >> 0x20);
                  }
                  puVar40 = (undefined4 *)
                            FUN_130b71f4e60(SUB84((double)CONCAT44(uVar42,uVar41) + dVar50,0));
                  uVar16 = _DAT_130b720bb20;
                  uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                  uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffb98 >> 0x20);
                  bVar35 = (double)puVar40 <= (double)CONCAT44(uVar36,uVar37);
                  if (iVar14 == 0) {
                    bVar35 = (double)CONCAT44(uVar36,uVar37) <= (double)puVar40;
                  }
                  if (bVar35) {
                    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar29,0x56,&local_410);
                    in_stack_fffffffffffffba8 = CONCAT44(uVar36,uVar37);
                    in_stack_fffffffffffffb98 = (undefined4 *)CONCAT44(uVar46,uVar16);
                    in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar42,uVar16);
                    in_stack_fffffffffffffb60 = CONCAT44(uVar41,0x590008);
                    (*(code *)0x7ff63a0e49f0)
                              (0x130b53f81d8,0xd,6,0x590008,0x130b72063f0,in_stack_fffffffffffffb60,
                               &local_410,0x520004,in_stack_fffffffffffffb78,0x580007,puVar40,
                               0x520004,in_stack_fffffffffffffb98,0x580007,in_stack_fffffffffffffba8
                              );
                    FUN_130b71e82f0(lVar29,0x130b7206430);
                    in_stack_fffffffffffffb88 = puVar40;
                  }
                  else if (iVar14 == 0) {
                    if (dVar51 < (double)puVar40) goto LAB_130b71d75f8;
                  }
                  else if ((dVar51 <= 0.0) || ((double)puVar40 < dVar51)) {
LAB_130b71d75f8:
                    iVar17 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1f);
                    iVar15 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x20);
                    if (iVar15 < iVar17) {
                      iVar15 = iVar17;
                    }
                    dVar52 = (double)iVar15 * _DAT_130b720bb18;
                    if (iVar14 == 0) {
                      if ((double)CONCAT44(uVar36,uVar37) - (double)puVar40 < dVar52) {
                        puVar40 = (undefined4 *)((double)CONCAT44(uVar36,uVar37) - dVar52);
                      }
                    }
                    else if ((double)puVar40 - (double)CONCAT44(uVar36,uVar37) < dVar52) {
                      puVar40 = (undefined4 *)((double)CONCAT44(uVar36,uVar37) + dVar52);
                    }
                    uVar37 = FUN_130b71f5090(iVar14,puVar40);
                    local_420 = 0;
                    local_41c = 0;
                    if ((lVar29 != 0) &&
                       (cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29), cVar10 != '\0')) {
                      (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                      dVar52 = _DAT_130b720bb48;
                      puVar40 = (undefined4 *)FUN_130b71f4e60(uVar37);
                      local_334 = 0;
                      local_330 = 0;
                      local_254 = 0;
                      local_250 = 0;
                      local_398 = 0;
                      iStack_394 = 0;
                      uStack_390 = 0;
                      uStack_38c = 0;
                      local_388 = 0.0;
                      iStack_380 = 0;
                      uStack_37c = 0;
                      FUN_130b71d0000((longlong)&local_388 + 4);
                      local_338 = 0;
                      local_340 = 0;
                      local_348 = 0;
                      local_350 = 0;
                      local_358 = 0.0;
                      local_360 = (undefined4 *)0x0;
                      local_368 = 0;
                      local_370 = 0;
                      uStack_378 = 0;
                      uStack_374 = 0;
                      FUN_130b71d0000(&local_334);
                      local_2b0 = 0;
                      local_2b8 = 0;
                      local_2c0 = 0;
                      local_2c8 = 0;
                      local_2d0 = 0;
                      local_2d8 = 0;
                      local_2e0 = 0;
                      local_2e8 = 0;
                      local_2f0 = 0;
                      local_2f8 = 0;
                      local_300 = 0;
                      local_308 = 0;
                      local_310 = 0;
                      local_318 = 0;
                      local_320 = 0;
                      local_268 = 0;
                      uStack_260 = 0;
                      local_278 = 0;
                      uStack_270 = 0;
                      local_288 = 0;
                      uStack_284 = 0;
                      uStack_280 = 0;
                      uStack_27c = 0;
                      local_258 = 0;
                      FUN_130b71d0000(&local_254);
                      (*(code *)0x7ff63a3fad20)(local_248,0,0x84);
                      local_398 = 6;
                      local_328 = lVar29;
                      FUN_130b71d0a30((longlong)&local_388 + 4,0x130b720bb28,1,0x130b7209e10);
                      local_358 = dVar52;
                      _DAT_130b720bb10 = 0;
                      _DAT_130b720bb80 = 0;
                      DAT_130b720bb88 = 0;
                      local_360 = puVar40;
                      cVar10 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_398,&local_288);
                      uVar37 = _DAT_130b720bb10;
                      if ((cVar10 == '\0') || (local_288 - 0x271bU < 0xfffffffd)) {
                        cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29);
                        dVar52 = _DAT_130b720bb18;
                        if (cVar10 != '\0') {
                          uVar36 = SUB84(_DAT_130b720bb18,0);
                          uVar41 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                          (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                          if (dVar52 <= _DAT_130b720bb48) {
                            uVar36 = SUB84(_DAT_130b720bb48,0);
                            uVar41 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                          }
                          (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                          dVar52 = (double)FUN_130b71f4e60(SUB84(_DAT_130b720bb48,0));
                          if ((double)((ulonglong)(dVar52 - (double)puVar40) & _DAT_130b7201070) <=
                              (double)CONCAT44(uVar41,uVar36) * _DAT_130b7201060)
                          goto LAB_130b71d7e0f;
                        }
                        uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                        uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                        uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                        uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffba8 >> 0x20);
                        if ((local_288 - 0x2714U < 0x12) &&
                           ((0x30101U >> (local_288 - 0x2714U & 0x1f) & 1) != 0)) {
                          cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29);
                          uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                          uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                          uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                          uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffba8 >> 0x20);
                          if (cVar10 != '\0') {
                            (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,&local_3d8);
                            local_1b8 = 0;
                            iStack_1b4 = 0;
                            iStack_1b0 = 0;
                            uStack_1ac = 0;
                            local_1a8 = 0.0;
                            uStack_1a0 = 0;
                            local_198 = 0;
                            uStack_190 = 0;
                            local_188 = 0;
                            uStack_180 = 0;
                            FUN_130b71d0000((longlong)&local_188 + 4);
                            (*(code *)0x7ff63a3fad20)(local_178,0,0x84);
                            _DAT_130b720bb10 = 0;
                            _DAT_130b720bb80 = 0;
                            DAT_130b720bb88 = 0;
                            cVar10 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_398,&local_1b8);
                            uVar16 = _DAT_130b720bb20;
                            uVar37 = _DAT_130b720bb10;
                            uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                            uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                            if ((cVar10 == '\0') || (local_1b8 - 0x271bU < 0xfffffffd)) {
                              cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29);
                              dVar52 = _DAT_130b720bb18;
                              uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                              uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                              uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                              uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffba8 >> 0x20);
                              if (cVar10 != '\0') {
                                uVar47 = SUB84(_DAT_130b720bb18,0);
                                uVar48 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                                if (dVar52 <= _DAT_130b720bb48) {
                                  uVar47 = SUB84(_DAT_130b720bb48,0);
                                  uVar48 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                                }
                                (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                                dVar52 = (double)FUN_130b71f4e60(SUB84(_DAT_130b720bb48,0));
                                uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                                uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                                uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                                uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffba8 >> 0x20);
                                if ((double)((ulonglong)(dVar52 - (double)puVar40) &
                                            _DAT_130b7201070) <=
                                    (double)CONCAT44(uVar48,uVar47) * _DAT_130b7201060)
                                goto LAB_130b71d7e03;
                              }
                              iVar14 = local_1b8;
                              uVar16 = _DAT_130b720bb20;
                              (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar29,0x56,&local_420);
                              in_stack_fffffffffffffb98 = (undefined4 *)((longlong)&local_188 + 4);
                              in_stack_fffffffffffffba8 = CONCAT44(uVar46,uVar16);
                              in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar41,uVar37);
                              in_stack_fffffffffffffb60 = CONCAT44(uVar36,0x590008);
                              in_stack_fffffffffffffb88 = (undefined4 *)CONCAT44(uVar42,iVar14);
                              (*(code *)0x7ff63a0e49f0)
                                        (0x130b53f81d8,0xd,7,0x590008,0x130b7206320,
                                         in_stack_fffffffffffffb60,&local_420,0x520004,
                                         in_stack_fffffffffffffb78,0x530014,
                                         in_stack_fffffffffffffb88,0x590008,
                                         in_stack_fffffffffffffb98,0x520004,
                                         in_stack_fffffffffffffba8,0x580007,puVar40);
                            }
                            else {
                              (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar29,0x56,&local_420);
                              in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar41,uVar16);
                              in_stack_fffffffffffffb60 = CONCAT44(uVar36,0x590008);
                              (*(code *)0x7ff63a0e49f0)
                                        (0x130b53f81d8,0xd,4,0x590008,0x130b72062b0,
                                         in_stack_fffffffffffffb60,&local_420,0x520004,
                                         in_stack_fffffffffffffb78,0x580007,puVar40);
                              in_stack_fffffffffffffb88 = puVar40;
                            }
LAB_130b71d7e03:
                            FUN_130b71d0000((longlong)&local_188 + 4);
                            goto LAB_130b71d7e0f;
                          }
                        }
                        iVar14 = local_288;
                        uVar16 = _DAT_130b720bb20;
                        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar29,0x56,&local_420);
                        in_stack_fffffffffffffb98 = &local_254;
                        in_stack_fffffffffffffba8 = CONCAT44(uVar46,uVar16);
                        in_stack_fffffffffffffb88 = (undefined4 *)CONCAT44(uVar42,iVar14);
                        in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar41,uVar37);
                        in_stack_fffffffffffffb60 = CONCAT44(uVar36,0x590008);
                        (*(code *)0x7ff63a0e49f0)
                                  (0x130b53f81d8,0xd,7,0x590008,0x130b7206390,
                                   in_stack_fffffffffffffb60,&local_420,0x520004,
                                   in_stack_fffffffffffffb78,0x530014,in_stack_fffffffffffffb88,
                                   0x590008,in_stack_fffffffffffffb98,0x520004,
                                   in_stack_fffffffffffffba8,0x580007,puVar40);
                      }
LAB_130b71d7e0f:
                      FUN_130b71d0000(&local_254);
                      FUN_130b71d0000(&local_334);
                      FUN_130b71d0000((longlong)&local_388 + 4);
                    }
                    FUN_130b71d0000(&local_420);
                  }
                }
              }
            }
            else if ((local_40c != 0) && (_DAT_130b720bb2c != 0)) {
              uVar16 = *(uint *)(local_40c + -4);
              uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
              uVar5 = uVar4;
              if (uVar16 < uVar4) {
                uVar5 = uVar16;
              }
              iVar14 = uVar16 - uVar4;
              if (uVar5 != 0) {
                uVar33 = 1;
                do {
                  uVar2 = *(ushort *)(local_40c + -2 + uVar33 * 2);
                  uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar33 * 2);
                  if (uVar5 <= uVar33) break;
                  uVar33 = uVar33 + 1;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar14 = (uint)uVar2 - (uint)uVar3;
                }
              }
              if (iVar14 == 0) goto LAB_130b71d7405;
            }
          }
          bVar35 = 0 < iVar13;
          iVar13 = iVar13 + -1;
        } while (bVar35);
      }
      uVar32 = (ulonglong)_DAT_130b720b918;
      if (0 < (int)_DAT_130b720b918) {
        lVar29 = 0x10;
        uVar30 = 0;
        do {
          if (uVar32 <= uVar30) {
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xe0afa000001f6);
LAB_130b71d9489:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0119000001f6);
LAB_130b71d94a9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xd011a000001f6);
LAB_130b71d94c9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250119000001f6);
LAB_130b71d94e9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xc00b2000001f6);
LAB_130b71d9509:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xf00b3000001f6);
LAB_130b71d9529:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2700b2000001f6);
LAB_130b71d9549:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xc0129000001f6);
LAB_130b71d9569:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xf012a000001f6);
LAB_130b71d9589:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x270129000001f6);
LAB_130b71d95a9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xc013a000001f6);
LAB_130b71d95c9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xf013b000001f6);
LAB_130b71d95e9:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x27013a000001f6);
LAB_130b71d9609:
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0af3000001f6);
            pcVar21 = (code *)swi(3);
            (*pcVar21)();
            return;
          }
          if (*(char *)(_DAT_130b720b92c + lVar29) != '\0') {
            cVar10 = (*(code *)0x7ff63a107ee0)
                               (0x130b53f81d8,*(undefined8 *)(_DAT_130b720b92c + -0x10 + lVar29));
            uVar32 = (ulonglong)_DAT_130b720b918;
            if (cVar10 == '\0') {
              if (uVar32 <= uVar30) {
                (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0afd000001f6);
                break;
              }
              *(undefined1 *)(_DAT_130b720b92c + lVar29) = 0;
              uVar32 = (ulonglong)_DAT_130b720b918;
            }
          }
          uVar30 = uVar30 + 1;
          lVar29 = lVar29 + 0x11;
        } while ((longlong)uVar30 < (longlong)(int)uVar32);
      }
      piVar20 = &local_410;
    }
    else {
      local_3d8 = 0;
      local_420 = 0;
      local_410 = 0;
      uStack_3d4 = 0;
      uStack_3d0 = 0;
      local_41c = 0;
      local_40c = 0;
      lVar18 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x20);
      lVar29 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1f);
      if (lVar29 < lVar18) {
        lVar29 = lVar18;
      }
      dVar52 = (double)lVar29 * _DAT_130b720bb18;
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
      dVar50 = _DAT_130b720bb48;
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
      dVar49 = _DAT_130b720bb48;
      iVar13 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
      dVar51 = _DAT_130b72010e8;
      if (0 < iVar13) {
        iVar13 = 0;
        dVar44 = _DAT_130b72010e0 * dVar45;
        if (_DAT_130b72010e0 * dVar45 <= dVar52) {
          dVar44 = dVar52;
        }
        do {
          lVar29 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
          if (lVar29 != 0) {
            (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
            FUN_130b71d0a30(&local_410,0x130b720bb3c,1,0x130b7207648);
            if (local_40c == _DAT_130b720bb2c) {
LAB_130b71d6c92:
              lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
              if (lVar18 == local_3e8) {
                lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,4);
                dVar52 = _DAT_130b720bb48;
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,3);
                (*(code *)0x7ff63a107fc0)(0x130b53f81d8,1);
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                dVar6 = _DAT_130b720bb48;
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                dVar43 = _DAT_130b720bb48;
                if (lVar18 == 0) {
                  dVar38 = (double)FUN_130b71e0070(SUB84(dVar49 - (double)_DAT_130b720b344 * dVar45,
                                                         0));
                  dVar39 = (double)FUN_130b71e0070(SUB84((double)_DAT_130b720b33c * dVar45 + dVar52,
                                                         0));
                  if (dVar52 <= dVar6) {
                    if ((double)_DAT_130b720b344 * dVar45 < dVar49 - dVar6) goto LAB_130b71d6f98;
LAB_130b71d6fd2:
                    bVar35 = dVar49 - dVar38 <= dVar44;
                    dVar52 = dVar6;
                    if (!bVar35 && (((DAT_130b720b2b2 ^ 1) & 1) == 0 && dVar38 != dVar6)) {
                      dVar52 = dVar38;
                    }
                    bVar12 = ~(bVar35 | DAT_130b720b2b2 ^ 1 | dVar38 == dVar6) & 1;
                    dVar38 = dVar52;
                  }
                  else {
                    if (((_DAT_130b720b360 == 0) && (dVar51 <= dVar6)) ||
                       (dVar49 - dVar52 <= (double)_DAT_130b720b340 * dVar45)) goto LAB_130b71d6fd2;
LAB_130b71d6f98:
                    if ((dVar38 - dVar6 <= (double)_DAT_130b720b348 * dVar45) ||
                       (bVar12 = 1, dVar49 - dVar38 <= dVar44)) goto LAB_130b71d6fd2;
                  }
                  if ((dVar39 != dVar43) || (NAN(dVar39) || NAN(dVar43))) {
                    dVar52 = dVar39 - dVar49;
                    goto joined_r0x0130b71d7031;
                  }
LAB_130b71d7033:
                  dVar39 = dVar43;
                  if (bVar12 == 0) goto LAB_130b71d6bc0;
                }
                else {
                  dVar38 = (double)FUN_130b71e0070(SUB84((double)_DAT_130b720b344 * dVar45 + dVar50,
                                                         0));
                  dVar39 = (double)FUN_130b71e0070(SUB84(dVar52 - (double)_DAT_130b720b33c * dVar45,
                                                         0));
                  if ((dVar52 < dVar6) || (dVar6 < dVar51)) {
                    if (((_DAT_130b720b360 != 0) || (dVar6 < dVar51)) &&
                       ((double)_DAT_130b720b340 * dVar45 < dVar52 - dVar50)) goto LAB_130b71d6e9d;
LAB_130b71d6efa:
                    bVar35 = dVar38 - dVar50 <= dVar44;
                    dVar52 = dVar6;
                    if (!bVar35 && (((DAT_130b720b2b2 ^ 1) & 1) == 0 && dVar38 != dVar6)) {
                      dVar52 = dVar38;
                    }
                    bVar12 = ~(bVar35 | DAT_130b720b2b2 ^ 1 | dVar38 == dVar6) & 1;
                    dVar38 = dVar52;
                  }
                  else {
                    if (dVar6 - dVar50 <= (double)_DAT_130b720b344 * dVar45) goto LAB_130b71d6efa;
LAB_130b71d6e9d:
                    if ((_DAT_130b72010e8 <= dVar6 &&
                         dVar6 - dVar38 <= (double)_DAT_130b720b348 * dVar45) ||
                       (bVar12 = 1, dVar38 - dVar50 <= dVar44)) goto LAB_130b71d6efa;
                  }
                  if ((dVar39 == dVar43) && (!NAN(dVar39) && !NAN(dVar43))) goto LAB_130b71d7033;
                  dVar52 = dVar50 - dVar39;
joined_r0x0130b71d7031:
                  if (dVar52 <= dVar44) goto LAB_130b71d7033;
                }
                _DAT_130b720bb10 = 0;
                _DAT_130b720bb80 = 0;
                DAT_130b720bb88 = 0;
                cVar10 = FUN_130b71dd110(0x130b720b000,lVar29,SUB84(dVar38,0),dVar39);
                iVar14 = _DAT_130b720b110;
                local_428 = _DAT_130b720bb10;
                if ((cVar10 == '\0') || (2 < _DAT_130b720b110 - 0x2718U)) {
                  cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar29);
                  dVar52 = _DAT_130b720bb18;
                  if (cVar10 != '\0') {
                    uVar37 = SUB84(_DAT_130b720bb18,0);
                    uVar36 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                    if (dVar52 <= _DAT_130b720bb48) {
                      uVar37 = SUB84(_DAT_130b720bb48,0);
                      uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                    }
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
                    dVar6 = _DAT_130b720bb48;
                    (*(code *)0x7ff63a107f70)(0x130b53f81d8,7);
                    dVar52 = (double)CONCAT44(uVar36,uVar37) * _DAT_130b7201060;
                    if (((double)((ulonglong)(dVar6 - dVar38) & _DAT_130b7201070) <= dVar52) &&
                       ((double)((ulonglong)(_DAT_130b720bb48 - dVar39) & _DAT_130b7201070) <=
                        dVar52)) goto LAB_130b71d6bc0;
                  }
                  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                  uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                  uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                  if ((iVar14 - 0x2714U < 0x12) &&
                     ((0x30101U >> (iVar14 - 0x2714U & 0x1f) & 1) != 0)) {
                    (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,&local_398);
                    _DAT_130b720bb10 = 0;
                    _DAT_130b720bb80 = 0;
                    DAT_130b720bb88 = 0;
                    cVar10 = FUN_130b71dd110(0x130b720b000,lVar29,SUB84(dVar38,0),dVar39);
                    uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffb78 >> 0x20);
                    uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
                    uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffb88 >> 0x20);
                    local_428 = _DAT_130b720bb10;
                    iVar14 = _DAT_130b720b110;
                    if ((cVar10 != '\0') && (0xfffffffc < _DAT_130b720b110 - 0x271bU))
                    goto LAB_130b71d6bc0;
                  }
                  local_288 = 0;
                  uStack_284 = 0;
                  uStack_280 = 0;
                  local_1b8 = 0;
                  iStack_1b4 = 0;
                  iStack_1b0 = 0;
                  FUN_130b71dbd30(&local_1b8,0x130b720b020,&DAT_130b720b110);
                  FUN_130b71d0a30(&local_288,&local_1b8,0,0x130b7206928);
                  FUN_130b71d0000(&local_1b8);
                  FUN_130b71d0a30(0x130b720bb3c,&local_288,1,0x130b7206938);
                  FUN_130b71d0000(&local_288);
                  FUN_130b71d0a30(&local_420,0x130b720bb3c,1,0x130b7207658);
                  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar29,0x56,&local_3d8);
                  in_stack_fffffffffffffb88 = (undefined4 *)CONCAT44(uVar41,iVar14);
                  in_stack_fffffffffffffb60 = CONCAT44(uVar37,0x590008);
                  in_stack_fffffffffffffb78 = (int *)CONCAT44(uVar36,local_428);
                  (*(code *)0x7ff63a0e49f0)
                            (0x130b53f81d8,0xd,5,0x590008,0x130b7203310,in_stack_fffffffffffffb60,
                             &local_3d8,0x520004,in_stack_fffffffffffffb78,0x530014,
                             in_stack_fffffffffffffb88,0x590008,&local_420);
                }
              }
            }
            else if ((local_40c != 0) && (_DAT_130b720bb2c != 0)) {
              uVar16 = *(uint *)(local_40c + -4);
              uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
              uVar5 = uVar4;
              if (uVar16 < uVar4) {
                uVar5 = uVar16;
              }
              iVar14 = uVar16 - uVar4;
              if (uVar5 != 0) {
                uVar32 = 1;
                do {
                  uVar2 = *(ushort *)(local_40c + -2 + uVar32 * 2);
                  uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar32 * 2);
                  if (uVar5 <= uVar32) break;
                  uVar32 = uVar32 + 1;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar14 = (uint)uVar2 - (uint)uVar3;
                }
              }
              if (iVar14 == 0) goto LAB_130b71d6c92;
            }
          }
LAB_130b71d6bc0:
          iVar13 = iVar13 + 1;
          iVar14 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
        } while (iVar13 < iVar14);
      }
      FUN_130b71d0000(&local_410);
      FUN_130b71d0000(&local_420);
      piVar20 = &local_3d8;
    }
    FUN_130b71d0000(piVar20);
    cVar10 = (char)local_400;
  }
  dVar45 = _DAT_130b720bd40;
  if (cVar10 == '\0' && (char)local_3f8 == '\0') goto LAB_130b71d87ec;
  local_398 = 0;
  iStack_394 = 0;
  uStack_390 = 0;
  if ((0.0 < _DAT_130b720bd40) &&
     ((*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x25), dVar52 = _DAT_130b720bb48,
     0.0 < _DAT_130b720bb48)) {
    iVar13 = (*(code *)0x7ff63a107da0)();
    uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
    if (iVar13 + -1 < 0) {
      bVar35 = false;
      dVar50 = 0.0;
      bVar34 = false;
      dVar51 = 0.0;
    }
    else {
      dVar50 = 0.0;
      dVar51 = 0.0;
      local_3f0 = local_3f0 & 0xffffffff00000000;
      local_3f8 = (undefined1 *)((ulonglong)local_3f8 & 0xffffffff00000000);
      lVar29 = (longlong)_DAT_130b720bcb8;
      local_400 = (longlong *)(longlong)(_DAT_130b720bcb8 + 100);
      iVar13 = iVar13 + -1;
      do {
        lVar18 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar13);
        if ((lVar18 != 0) &&
           (cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar18), cVar10 != '\0')) {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_398,0x130b720bb3c,1,0x130b7208598);
          lVar18 = CONCAT44(uStack_390,iStack_394);
          if (lVar18 == _DAT_130b720bb2c) {
LAB_130b71d811f:
            lVar18 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            (*(code *)0x7ff63a107f70)(0x130b53f81d8,10);
            dVar49 = _DAT_130b720bb48;
            uVar22 = (*(code *)0x7ff63a107f70)(0x130b53f81d8,9);
            uVar25 = (undefined7)((ulonglong)uVar22 >> 8);
            if (lVar18 == local_3e8) {
              dVar51 = dVar51 + dVar49 + _DAT_130b720bb48;
              local_3f8 = (undefined1 *)CONCAT44(local_3f8._4_4_,(int)CONCAT71(uVar25,1));
            }
            else if ((lVar29 <= lVar18) && (lVar18 < (longlong)local_400)) {
              dVar50 = dVar50 + dVar49 + _DAT_130b720bb48;
              local_3f0 = CONCAT44(local_3f0._4_4_,(int)CONCAT71(uVar25,1));
            }
          }
          else if ((lVar18 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar16 = *(uint *)(lVar18 + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar5 = uVar4;
            if (uVar16 < uVar4) {
              uVar5 = uVar16;
            }
            iVar14 = uVar16 - uVar4;
            if (uVar5 != 0) {
              uVar32 = 1;
              do {
                uVar2 = *(ushort *)(lVar18 + -2 + uVar32 * 2);
                uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar32 * 2);
                if (uVar5 <= uVar32) break;
                uVar32 = uVar32 + 1;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar14 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar14 == 0) goto LAB_130b71d811f;
          }
        }
        uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffb60 >> 0x20);
        bVar35 = 0 < iVar13;
        iVar13 = iVar13 + -1;
      } while (bVar35);
      bVar34 = (char)local_3f8 != '\0';
      bVar35 = (char)local_3f0 != '\0';
    }
    cVar10 = DAT_130b720ba6d;
    dVar49 = (dVar45 * dVar52) / _DAT_130b72010f0;
    bVar8 = (bool)(dVar50 + dVar51 <= dVar49 & bVar34 & bVar35);
    bVar34 = (bool)(dVar51 <= dVar49 & (bVar34 ^ bVar8));
    bVar35 = (bool)(dVar50 <= dVar49 & bVar35 & ~bVar8);
    if (((bVar8) || (bVar34)) || (bVar35)) {
      if (bVar8) {
        bVar35 = DAT_130b720ba6c == '\0';
        DAT_130b720ba6c = '\x01';
        DAT_130b720ba6d = '\x01';
        if ((bVar35) || (cVar10 == '\0')) {
          uVar22 = 0x130b7204e80;
          uVar31 = 6;
          dVar52 = dVar50;
LAB_130b71d8535:
          DAT_130b720ba6d = '\x01';
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd,uVar31,0x590008,uVar22,CONCAT44(uVar37,0x580007),dVar45,
                     0x580007,dVar51,0x580007,dVar52);
        }
      }
      else {
        if ((bVar34) && (bVar34 = DAT_130b720ba6c == '\0', DAT_130b720ba6c = '\x01', bVar34)) {
          uVar22 = CONCAT44(uVar37,0x580007);
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd,4,0x590008,0x130b7204ee8,uVar22,dVar45,0x580007,dVar51,
                     0x580007,dVar52);
          uVar37 = (undefined4)((ulonglong)uVar22 >> 0x20);
        }
        if ((bVar35) && (DAT_130b720ba6d = '\x01', cVar10 == '\0')) {
          uVar22 = 0x130b7204f58;
          uVar31 = 4;
          dVar51 = dVar50;
          goto LAB_130b71d8535;
        }
      }
      if (cVar9 == '\0') {
        if (DAT_130b720ba6c != '\0') {
          DAT_130b720b95d = '\0';
          _DAT_130b720b960 = 0.0;
          DAT_130b720b95c = '\0';
          _DAT_130b720b968 = 0.0;
          _DAT_130b720b970 = 0.0;
          _DAT_130b720b978 = 0;
          FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
          _DAT_130b720b998 = 0.0;
          _DAT_130b720b9a0 = 0.0;
          _DAT_130b720b990 = 0.0;
          _DAT_130b720b9a8 = 0;
          FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
          FUN_130b71e8bd0();
        }
        if (DAT_130b720ba6d != '\0') {
          FUN_130b71eb3a0();
        }
        pcVar21 = FUN_130b71f7b60;
      }
      else {
        iVar13 = FUN_130b71efc10();
        if (_DAT_130b720ba68 != iVar13) {
          (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d48);
        }
        DAT_130b720b95d = '\0';
        _DAT_130b720b960 = 0.0;
        DAT_130b720b95c = '\0';
        _DAT_130b720b968 = 0.0;
        _DAT_130b720b970 = 0.0;
        _DAT_130b720b978 = 0;
        _DAT_130b720ba68 = iVar13;
        FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
        _DAT_130b720b998 = 0.0;
        _DAT_130b720b9a0 = 0.0;
        _DAT_130b720b990 = 0.0;
        _DAT_130b720b9a8 = 0;
        FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
        FUN_130b71eb3a0();
        FUN_130b71f7b60();
        pcVar21 = FUN_130b71e8bd0;
      }
      (*pcVar21)();
      FUN_130b71f7df0();
    }
  }
  FUN_130b71d0000(&local_398);
LAB_130b71d87ec:
  FUN_130b71d0000(&local_2a8);
  return;
}



/* Address: 130b71d97a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71d97a0(int param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  code *pcVar12;
  int iVar13;
  ulonglong uVar14;
  undefined4 local_258;
  longlong local_254;
  undefined4 local_248;
  longlong local_244;
  undefined4 local_238;
  undefined8 local_234;
  undefined4 local_228;
  longlong local_224;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined8 local_1e0;
  undefined1 local_1d8 [144];
  undefined4 local_148;
  int iStack_144;
  int iStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  
  local_248 = 0;
  local_258 = 0;
  local_238 = 0;
  local_244 = 0;
  local_254 = 0;
  local_234 = 0;
  if ((DAT_130b720bd58 == '\0') || (param_1 != 1)) goto LAB_130b71d9e42;
  FUN_130b71d0a30(&local_238,0x130b72058c8,0,0x130b7209e40);
  FUN_130b71f80a0(&local_238);
  FUN_130b71d0a30(&local_258,0x130b720bb3c,1,0x130b7209e50);
  lVar4 = *(longlong *)(param_4 + 4);
  if (lVar4 == local_254) {
LAB_130b71d99cd:
    DAT_130b720ba6f = DAT_130b720ba6f == '\0';
    pcVar12 = FUN_130b71fb750;
  }
  else {
    if ((lVar4 != 0) && (local_254 != 0)) {
      uVar10 = *(uint *)(lVar4 + -4);
      uVar3 = *(uint *)(local_254 + -4);
      uVar6 = uVar3;
      if (uVar10 < uVar3) {
        uVar6 = uVar10;
      }
      iVar13 = uVar10 - uVar3;
      if (uVar6 != 0) {
        uVar14 = 1;
        do {
          uVar1 = *(ushort *)(lVar4 + -2 + uVar14 * 2);
          uVar2 = *(ushort *)(local_254 + -2 + uVar14 * 2);
          if (uVar6 <= uVar14) break;
          uVar14 = uVar14 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar13 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar13 == 0) goto LAB_130b71d99cd;
    }
    FUN_130b71d0a30(&local_238,0x130b72060e0,0,0x130b7209e60);
    FUN_130b71f80a0(&local_238);
    FUN_130b71d0a30(&local_258,0x130b720bb3c,1,0x130b7209e70);
    lVar4 = *(longlong *)(param_4 + 4);
    if (lVar4 != local_254) {
      if ((lVar4 == 0) || (local_254 == 0)) goto LAB_130b71d9e42;
      uVar10 = *(uint *)(lVar4 + -4);
      uVar3 = *(uint *)(local_254 + -4);
      uVar6 = uVar3;
      if (uVar10 < uVar3) {
        uVar6 = uVar10;
      }
      iVar13 = uVar10 - uVar3;
      if (uVar6 != 0) {
        uVar14 = 1;
        do {
          uVar1 = *(ushort *)(lVar4 + -2 + uVar14 * 2);
          uVar2 = *(ushort *)(local_254 + -2 + uVar14 * 2);
          if (uVar6 <= uVar14) break;
          uVar14 = uVar14 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar13 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar13 != 0) goto LAB_130b71d9e42;
    }
    DAT_130b720ba6e = DAT_130b720ba6e == '\0';
    if ((bool)DAT_130b720ba6e) {
      FUN_130b71d0a30(&local_248,0x130b720bb28,1,0x130b7209e80);
      local_228 = 0;
      local_224 = 0;
      iVar8 = (*(code *)0x7ff63a1081a0)(0x130b53f81d8);
      iVar13 = _DAT_130b720bc30;
      if (-1 < iVar8 + -1) {
        iVar8 = iVar8 + -1;
        do {
          uVar11 = (*(code *)0x7ff63a1081f0)(0x130b53f81d8,iVar8);
          cVar7 = (*(code *)0x7ff63a108240)(0x130b53f81d8,uVar11);
          if (cVar7 != '\0') {
            (*(code *)0x7ff63a1083a0)(0x130b53f81d8,0);
            FUN_130b71d0a30(&local_228,0x130b720bb3c,1,0x130b72083e8);
            if (local_224 == local_244) {
LAB_130b71d9b86:
              iVar9 = (*(code *)0x7ff63a108310)(0x130b53f81d8,0xf);
              if (iVar13 == iVar9) {
                uVar10 = (*(code *)0x7ff63a108310)(0x130b53f81d8,4);
                if ((uVar10 & 0xfffffffe) == 4) {
                  local_e4 = 0;
                  local_e0 = 0;
                  local_1e4 = 0;
                  local_1e0 = 0;
                  uStack_138 = 0;
                  uStack_134 = 0;
                  uStack_130 = 0;
                  local_148 = 0;
                  iStack_144 = 0;
                  iStack_140 = 0;
                  uStack_13c = 0;
                  FUN_130b71d0000(&uStack_134);
                  local_e8 = 0;
                  local_f0 = 0;
                  local_f8 = 0;
                  local_100 = 0;
                  local_108 = 0;
                  local_110 = 0;
                  local_118 = 0;
                  local_120 = 0;
                  local_128 = 0;
                  FUN_130b71d0000(&local_e4);
                  local_60 = 0;
                  local_68 = 0;
                  local_70 = 0;
                  local_78 = 0;
                  local_80 = 0;
                  local_88 = 0;
                  local_90 = 0;
                  local_98 = 0;
                  local_a0 = 0;
                  local_a8 = 0;
                  local_b0 = 0;
                  local_b8 = 0;
                  local_c0 = 0;
                  local_c8 = 0;
                  local_d0 = 0;
                  local_d8 = 0;
                  local_1f8 = 0;
                  uStack_1f0 = 0;
                  local_208 = 0;
                  uStack_200 = 0;
                  local_218 = 0;
                  uStack_210 = 0;
                  local_1e8 = 0;
                  FUN_130b71d0000(&local_1e4);
                  (*(code *)0x7ff63a3fad20)(local_1d8,0,0x84);
                  local_148 = 8;
                  uStack_13c = (undefined4)uVar11;
                  uStack_138 = (undefined4)((ulonglong)uVar11 >> 0x20);
                  FUN_130b71d0a30(&uStack_134,&local_248,0,0x130b72083f8);
                  iStack_144 = iVar13;
                  iStack_140 = iVar13 >> 0x1f;
                  cVar7 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_148,&local_218);
                  if (cVar7 == '\0') {
                    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204c68);
                  }
                  FUN_130b71d0000(&local_1e4);
                  FUN_130b71d0000(&local_e4);
                  FUN_130b71d0000(&uStack_134);
                }
              }
            }
            else if ((local_224 != 0) && (local_244 != 0)) {
              uVar10 = *(uint *)(local_224 + -4);
              uVar3 = *(uint *)(local_244 + -4);
              uVar6 = uVar3;
              if (uVar10 < uVar3) {
                uVar6 = uVar10;
              }
              iVar9 = uVar10 - uVar3;
              if (uVar6 != 0) {
                uVar14 = 1;
                do {
                  uVar1 = *(ushort *)(local_224 + -2 + uVar14 * 2);
                  uVar2 = *(ushort *)(local_244 + -2 + uVar14 * 2);
                  if (uVar6 <= uVar14) break;
                  uVar14 = uVar14 + 1;
                } while (uVar1 == uVar2);
                if (uVar1 != uVar2) {
                  iVar9 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar9 == 0) goto LAB_130b71d9b86;
            }
          }
          bVar5 = 0 < iVar8;
          iVar8 = iVar8 + -1;
        } while (bVar5);
      }
      FUN_130b71d0000(&local_228);
      FUN_130b71f4a40();
      uVar11 = 0x130b7206768;
    }
    else {
      uVar11 = 0x130b72067a8;
    }
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,uVar11);
    pcVar12 = FUN_130b71e8bd0;
  }
  (*pcVar12)();
  FUN_130b71fc9d0();
  (*(code *)0x7ff63a0f51b0)(0x130b53f81d8,0);
LAB_130b71d9e42:
  FUN_130b71d0000(&local_238);
  FUN_130b71d0000(&local_258);
  FUN_130b71d0000(&local_248);
  return;
}



/* Address: 130b71d9e80 */

void FUN_130b71d9e80(void)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  longlong lVar4;
  undefined4 local_2c0;
  undefined8 local_2bc;
  undefined4 local_2b0;
  undefined8 local_2ac;
  undefined4 local_2a0;
  undefined8 local_29c;
  undefined1 local_290 [588];
  int iStack_44;
  
  FUN_130b71e8bd0();
  if (DAT_130b720bca0 != '\0') {
    (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b410,0,0);
  }
  (*(code *)0x7ff63a0e72d0)(0x130b53f81d8);
  puVar3 = local_290;
  local_2c0 = 0;
  local_2bc = 0;
  (*(code *)0x7ff63a3fa670)(puVar3,0x130b7209b60,0x24c);
  lVar4 = 0x31;
  do {
    FUN_130b71d0a30(&local_2c0,puVar3,0,0x130b7209db0);
    local_2a0 = 0;
    local_2b0 = 0;
    local_29c = 0;
    local_2ac = 0;
    FUN_130b71d0a30(&local_2b0,&local_2c0,0,0x130b72085d8);
    FUN_130b71f80a0(&local_2b0);
    FUN_130b71d0a30(&local_2a0,0x130b720bb3c,1,0x130b72085e8);
    (*(code *)0x7ff63a0f4ce0)(0x130b53f81d8,0);
    FUN_130b71d0000(&local_2b0);
    FUN_130b71d0000(&local_2a0);
    puVar3 = puVar3 + 0xc;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  lVar4 = -0x24c;
  do {
    if ((((*(int *)((longlong)&iStack_44 + lVar4) != 0) &&
         (lVar2 = *(longlong *)(&stack0xffffffffffffffc0 + lVar4), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x130b53f81d8);
      }
    }
    *(undefined8 *)(&stack0xffffffffffffffc0 + lVar4) = 0;
    *(undefined4 *)((longlong)&iStack_44 + lVar4) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_130b71d0000(&local_2c0);
  return;
}



/* Address: 130b71da090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71da090(longlong *param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  double dVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 *puVar13;
  undefined8 *puVar14;
  undefined1 *puVar15;
  uint uVar16;
  longlong lVar17;
  ulonglong uVar18;
  undefined4 local_80;
  longlong local_7c;
  longlong local_70;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_80 = 0;
  local_64 = 0;
  local_7c = 0;
  if (*(int *)((longlong)param_1 + 0x1c) != 6) goto LAB_130b71da837;
  iVar8 = FUN_130b71efc10();
  if (iVar8 != _DAT_130b720b958) {
    _DAT_130b720b958 = iVar8;
  }
  lVar5 = *param_1;
  if ((lVar5 == 0) || (cVar7 = (*(code *)0x7ff63a108af0)(0x130b53f81d8,lVar5), cVar7 == '\0'))
  goto LAB_130b71da837;
  local_80 = 0;
  local_7c = 0;
  (*(code *)0x7ff63a1089d0)(0x130b53f81d8,lVar5,0);
  FUN_130b71d0a30(&local_68,0x130b720bb3c,1,0x130b7209e90);
  FUN_130b71d0a30(&local_80,&local_68,0,0x130b7209ea0);
  lVar9 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar5,0xb);
  uVar10 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar5,4);
  iVar8 = 0;
  if ((local_7c != _DAT_130b720bb2c) && ((iVar8 = 1, local_7c != 0 && (_DAT_130b720bb2c != 0)))) {
    uVar3 = *(uint *)(local_7c + -4);
    uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
    uVar16 = uVar4;
    if (uVar3 < uVar4) {
      uVar16 = uVar3;
    }
    iVar8 = uVar3 - uVar4;
    if (uVar16 != 0) {
      uVar18 = 1;
      do {
        uVar1 = *(ushort *)(local_7c + -2 + uVar18 * 2);
        uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar18 * 2);
        if (uVar16 <= uVar18) break;
        uVar18 = uVar18 + 1;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar8 = (uint)uVar1 - (uint)uVar2;
      }
    }
  }
  lVar17 = (longlong)_DAT_130b720bc30;
  if (iVar8 == 0) {
    if ((lVar9 == lVar17) && ((uVar10 & 0xfffffffffffffffd) == 0)) {
      FUN_130b71f5920(lVar5);
    }
    if (local_7c == _DAT_130b720bb2c) goto LAB_130b71da2fd;
LAB_130b71da295:
    if ((_DAT_130b720bb2c != 0) && (local_7c != 0)) {
      uVar3 = *(uint *)(local_7c + -4);
      uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
      uVar16 = uVar4;
      if (uVar3 < uVar4) {
        uVar16 = uVar3;
      }
      iVar8 = uVar3 - uVar4;
      if (uVar16 != 0) {
        uVar18 = 1;
        do {
          uVar1 = *(ushort *)(local_7c + -2 + uVar18 * 2);
          uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar18 * 2);
          if (uVar16 <= uVar18) break;
          uVar18 = uVar18 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar8 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar8 == 0) goto LAB_130b71da2fd;
    }
  }
  else {
    if (local_7c != _DAT_130b720bb2c) goto LAB_130b71da295;
LAB_130b71da2fd:
    if ((((_DAT_130b720bcb8 <= lVar9) && (lVar9 < _DAT_130b720bcb8 + 100)) && (uVar10 == 0)) &&
       (DAT_130b720b8c0 != '\0')) {
      if (_DAT_130b720b8c5 == local_7c) {
LAB_130b71da51a:
        if (_DAT_130b720b8cd == lVar9) {
          _DAT_130b720b8f9 = lVar5;
          lVar12 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar5,0xc);
          if (0 < lVar12) {
            _DAT_130b720b901 = lVar12;
          }
          FUN_130b71e4e30();
          FUN_130b71e5750();
        }
      }
      else if ((local_7c != 0) && (_DAT_130b720b8c5 != 0)) {
        uVar3 = *(uint *)(local_7c + -4);
        uVar4 = *(uint *)(_DAT_130b720b8c5 + -4);
        uVar16 = uVar4;
        if (uVar3 < uVar4) {
          uVar16 = uVar3;
        }
        iVar8 = uVar3 - uVar4;
        if (uVar16 != 0) {
          uVar18 = 1;
          do {
            uVar1 = *(ushort *)(local_7c + -2 + uVar18 * 2);
            uVar2 = *(ushort *)(_DAT_130b720b8c5 + -2 + uVar18 * 2);
            if (uVar16 <= uVar18) break;
            uVar18 = uVar18 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar8 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar8 == 0) goto LAB_130b71da51a;
      }
    }
  }
  if (local_7c == _DAT_130b720bb2c) {
LAB_130b71da385:
    if (((_DAT_130b720bcb8 <= lVar9) && (lVar9 < _DAT_130b720bcb8 + 100)) &&
       ((uVar10 & 0xfffffffffffffffd) == 1)) {
      lVar11 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar5,0xc);
      lVar12 = param_1[0xc];
      if (lVar11 < 1) {
        if (lVar12 != 0) {
          local_70 = lVar12;
          cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8);
          if (cVar7 == '\0') goto LAB_130b71da5bf;
          goto LAB_130b71da5fa;
        }
      }
      else {
        local_70 = lVar12;
        iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
        if (-1 < iVar8 + -1) {
          do {
            iVar8 = iVar8 + -1;
            lVar12 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
            if (((lVar12 != 0) &&
                (cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar12), cVar7 != '\0')) &&
               (lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd), lVar12 == lVar11))
            goto LAB_130b71da5fa;
          } while (0 < iVar8);
        }
        if (local_70 != 0) {
LAB_130b71da5bf:
          FUN_130b71e3b50(local_70);
        }
        if ((0 < lVar11) && (lVar11 != local_70)) {
          FUN_130b71e3b50(lVar11);
        }
      }
      FUN_130b71e3e10();
    }
  }
  else if ((_DAT_130b720bb2c != 0) && (local_7c != 0)) {
    uVar3 = *(uint *)(local_7c + -4);
    uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
    uVar16 = uVar4;
    if (uVar3 < uVar4) {
      uVar16 = uVar3;
    }
    iVar8 = uVar3 - uVar4;
    if (uVar16 != 0) {
      uVar18 = 1;
      do {
        uVar1 = *(ushort *)(local_7c + -2 + uVar18 * 2);
        uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar18 * 2);
        if (uVar16 <= uVar18) break;
        uVar18 = uVar18 + 1;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar8 = (uint)uVar1 - (uint)uVar2;
      }
    }
    if (iVar8 == 0) goto LAB_130b71da385;
  }
LAB_130b71da5fa:
  if (local_7c == _DAT_130b720bb2c) {
joined_r0x0130b71da694:
    if (lVar9 == lVar17) {
      if (uVar10 == 2) {
LAB_130b71da6bd:
        lVar9 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar5,3);
        _DAT_130b720b9bc = FUN_130b71efc10();
        if (lVar9 == 0) {
          puVar13 = &DAT_130b720b95c;
          puVar15 = &DAT_130b720b9c0;
LAB_130b71da72c:
          *puVar15 = 1;
          *puVar13 = 0;
        }
        else if (lVar9 == 1) {
          puVar13 = &DAT_130b720b95d;
          puVar15 = &DAT_130b720b9c1;
          goto LAB_130b71da72c;
        }
        FUN_130b71e8bd0();
        if (uVar10 != 1) goto LAB_130b71da826;
      }
      else if (uVar10 != 1) {
        if (uVar10 != 0) goto LAB_130b71da826;
        goto LAB_130b71da6bd;
      }
      (*(code *)0x7ff63a1088b0)(0x130b53f81d8,lVar5,9);
      dVar6 = _DAT_130b720bb48;
      (*(code *)0x7ff63a1088b0)(0x130b53f81d8,lVar5,7);
      dVar6 = dVar6 + _DAT_130b720bb48;
      (*(code *)0x7ff63a1088b0)(0x130b53f81d8,lVar5,8);
      dVar6 = dVar6 + _DAT_130b720bb48;
      (*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x28);
      if (DAT_130b720bc80 == '\0') {
LAB_130b71da7f2:
        DAT_130b720b944 = '\0';
        _DAT_130b720b950 = 0.0;
        puVar14 = (undefined8 *)&DAT_130b7201100;
LAB_130b71da803:
        _DAT_130b720b948 = *puVar14;
      }
      else {
        if (dVar6 < 0.0) {
          _DAT_130b720b950 = _DAT_130b720bb48 - dVar6;
          DAT_130b720b944 = '\x01';
          puVar14 = (undefined8 *)&DAT_130b720bc88;
          goto LAB_130b71da803;
        }
        if (((0.0 < dVar6) && (DAT_130b720b944 != '\0')) &&
           (_DAT_130b720b950 + _DAT_130b72010f8 <= _DAT_130b720bb48)) goto LAB_130b71da7f2;
      }
      FUN_130b71e8bd0();
    }
  }
  else if ((local_7c != 0) && (_DAT_130b720bb2c != 0)) {
    uVar3 = *(uint *)(local_7c + -4);
    uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
    uVar16 = uVar4;
    if (uVar3 < uVar4) {
      uVar16 = uVar3;
    }
    iVar8 = uVar3 - uVar4;
    if (uVar16 != 0) {
      uVar18 = 1;
      do {
        uVar1 = *(ushort *)(local_7c + -2 + uVar18 * 2);
        uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar18 * 2);
        if (uVar16 <= uVar18) break;
        uVar18 = uVar18 + 1;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar8 = (uint)uVar1 - (uint)uVar2;
      }
    }
    if (iVar8 == 0) goto joined_r0x0130b71da694;
  }
LAB_130b71da826:
  FUN_130b71d0000(&local_80);
LAB_130b71da837:
  FUN_130b71d0000(&local_68);
  return;
}



/* Address: 130b71db8c0 */

void FUN_130b71db8c0(undefined8 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  (*(code *)0x7ff63a0e6470)(0x130b53f81d8,*param_1,0x130b7466890);
  param_1[1] = 0x130b72017d0;
  param_1[2] = 0;
  param_1[3] = 0;
  (*(code *)0x7ff63a0e6470)(0x130b53f81d8,*param_1,0x130b538aa50);
  param_1[1] = 0x130b7201810;
  *(undefined1 *)((longlong)param_1 + 0x294) = 0;
  *(undefined8 *)((longlong)param_1 + 0x295) = 0;
  *(undefined8 *)((longlong)param_1 + 0x29d) = 10;
  *(undefined4 *)((longlong)param_1 + 0x2a5) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2ad) = 1;
  uVar1 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0x35);
  *(undefined4 *)((longlong)param_1 + 0x2a9) = uVar1;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  FUN_130b71d0000((longlong)param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  FUN_130b71d0000((longlong)param_1 + 0x84);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x12,0,0xb4);
  FUN_130b71d0000((longlong)param_1 + 0x144);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x2a,0,0xb8);
  FUN_130b71d0000(param_1 + 0x41);
  *(undefined8 *)((longlong)param_1 + 0x28c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x284) = 0;
  *(undefined8 *)((longlong)param_1 + 0x27c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x274) = 0;
  *(undefined8 *)((longlong)param_1 + 0x26c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x264) = 0;
  *(undefined8 *)((longlong)param_1 + 0x25c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x254) = 0;
  *(undefined8 *)((longlong)param_1 + 0x24c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x244) = 0;
  *(undefined8 *)((longlong)param_1 + 0x23c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x234) = 0;
  *(undefined8 *)((longlong)param_1 + 0x22c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x224) = 0;
  *(undefined8 *)((longlong)param_1 + 0x21c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x214) = 0;
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar2 != 0) {
    *(undefined4 *)((longlong)param_1 + 0x2ad) = 2;
  }
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,7);
  if (iVar2 != 0) {
    *(undefined4 *)((longlong)param_1 + 0x2ad) = 0;
  }
  return;
}



/* Address: 130b71dbb40 */

void FUN_130b71dbb40(longlong param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  return;
}



/* Address: 130b71dbb60 */

void FUN_130b71dbb60(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  
  FUN_130b71d0000(param_1 + 0x34);
  if ((((*(int *)(param_1 + 4) != 0) && (lVar2 = *(longlong *)(param_1 + 8), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x130b53f81d8);
    }
  }
  *(undefined8 *)(param_1 + 8) = 0;
  *(int *)(param_1 + 4) = 0;
  return;
}



/* Address: 130b71dbca0 */

void FUN_130b71dbca0(undefined8 *param_1)

{
  FUN_130b71d0000(param_1 + 0x41);
  FUN_130b71d0000((longlong)param_1 + 0x144);
  FUN_130b71d0000((longlong)param_1 + 0x84);
  FUN_130b71d0000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x130b53f81d8,*param_1,0x130b7466890);
  param_1[1] = 0x130b72017d0;
  (*(code *)0x7ff63a0e62f0)(0x130b53f81d8,*param_1);
  return;
}



/* Address: 130b71dbd30 */

void FUN_130b71dbd30(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x130b720bb28;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_130b71d0a30(&local_60,lVar10,0,0x130b72071a8);
  (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71dbe67 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x130b7201108))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,*param_3,0x53,&local_88);
  FUN_130b71d0a30(&local_98,0x130b7202fe0,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_130b71dc4cf;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_130b71dc4cf;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_130b71d0060(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1f0561000101f9);
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
      if (uVar11 == uVar12) goto LAB_130b71dc6c2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_130b71dc6c2:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_130b71dc4cf:
  FUN_130b71d0a30(param_1,&local_98,0,0x130b72074a8);
  FUN_130b71d0a30(&local_50,param_1,0,0x130b72074b8);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0a30(0x130b720bb3c,&local_50,1,0x130b72074c8);
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_88);
  FUN_130b71d0000(&local_98);
  FUN_130b71d0000(&local_78);
  return;
}



/* Address: 130b71dc550 */

void FUN_130b71dc550(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_130b71d0a30(&stack0x00000060,0x130b720bb3c,1,0x130b7207278);
  (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd8,2,0x590008,0x130b7202870);
  FUN_130b71d0a30(&stack0x00000050,0x130b720bb3c,1,0x130b7207288);
  FUN_130b71d0a30(in_stack_00000048,&stack0x00000050,0,0x130b7207298);
  FUN_130b71d0a30(&stack0x00000098,in_stack_00000048,0,0x130b72074b8);
  FUN_130b71d0000(&stack0x00000088);
  FUN_130b71d0a30(0x130b720bb3c,&stack0x00000098,1,0x130b72074c8);
  FUN_130b71d0000(&stack0x00000098);
  FUN_130b71d0000(&stack0x00000060);
  FUN_130b71d0000(&stack0x00000050);
  FUN_130b71d0000(&stack0x00000070);
  return;
}



/* Address: 130b71dc710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_130b71dc710(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 local_90;
  undefined4 local_88;
  undefined1 local_80 [64];
  
  if (_DAT_130b720bb14 == 0) {
    _DAT_130b720b470 = 0;
    _DAT_130b720b474 = 0;
    uRam00000130b720b478 = 0;
    uRam00000130b720b47c = 0;
    _DAT_130b720b480 = 0;
    FUN_130b71d0000(0x130b720b484);
    _DAT_130b720b4d0 = 0;
    _DAT_130b720b4c0 = 0;
    uRam00000130b720b4c8 = 0;
    _DAT_130b720b4b0 = 0;
    _DAT_130b720b4b8 = 0;
    _DAT_130b720b4a0 = 0;
    _DAT_130b720b4a8 = 0;
    _DAT_130b720b490 = 0;
    _DAT_130b720b498 = 0;
    FUN_130b71d0000(0x130b720b4d4);
    _DAT_130b720b550 = 0;
    uRam00000130b720b558 = 0;
    _DAT_130b720b570 = 0;
    uRam00000130b720b578 = 0;
    _DAT_130b720b580 = 0;
    uRam00000130b720b588 = 0;
    _DAT_130b720b560 = 0;
    uRam00000130b720b568 = 0;
    _DAT_130b720b530 = 0;
    uRam00000130b720b538 = 0;
    _DAT_130b720b540 = 0;
    uRam00000130b720b548 = 0;
    _DAT_130b720b510 = 0;
    uRam00000130b720b518 = 0;
    _DAT_130b720b520 = 0;
    uRam00000130b720b528 = 0;
    _DAT_130b720b4f0 = 0;
    uRam00000130b720b4f8 = 0;
    _DAT_130b720b500 = 0;
    uRam00000130b720b508 = 0;
    _DAT_130b720b590 = 0;
    _DAT_130b720b4e0 = 0;
    uRam00000130b720b4e8 = 0;
    FUN_130b71d0000(0x130b720b594);
    _DAT_130b720b630 = 0;
    uRam00000130b720b638 = 0;
    _DAT_130b720b620 = 0;
    uRam00000130b720b628 = 0;
    _DAT_130b720b640 = 0;
    uRam00000130b720b648 = 0;
    _DAT_130b720b610 = 0;
    uRam00000130b720b618 = 0;
    _DAT_130b720b600 = 0;
    uRam00000130b720b608 = 0;
    _DAT_130b720b5f0 = 0;
    uRam00000130b720b5f8 = 0;
    _DAT_130b720b5e0 = 0;
    uRam00000130b720b5e8 = 0;
    _DAT_130b720b5d0 = 0;
    uRam00000130b720b5d8 = 0;
    _DAT_130b720b5c0 = 0;
    uRam00000130b720b5c8 = 0;
    _DAT_130b720b5b0 = 0;
    uRam00000130b720b5b8 = 0;
    _DAT_130b720b5a0 = 0;
    uRam00000130b720b5a8 = 0;
    _DAT_130b720b650 = 0;
    FUN_130b71d0000(0x130b720b658);
    _DAT_130b720b6d4 = 0;
    _DAT_130b720b6cc = 0;
    _DAT_130b720b6dc = 0;
    _DAT_130b720b6c4 = 0;
    _DAT_130b720b6bc = 0;
    _DAT_130b720b6b4 = 0;
    _DAT_130b720b6ac = 0;
    _DAT_130b720b6a4 = 0;
    _DAT_130b720b69c = 0;
    _DAT_130b720b694 = 0;
    _DAT_130b720b68c = 0;
    _DAT_130b720b684 = 0;
    _DAT_130b720b67c = 0;
    _DAT_130b720b674 = 0;
    _DAT_130b720b66c = 0;
    _DAT_130b720b664 = 0;
    if (param_2 < 2) {
      _DAT_130b720b470 = 1;
      FUN_130b71d0a30(0x130b720b484,param_1,0,0x130b7206958);
      local_90 = 0;
      local_88 = 0;
      _DAT_130b720b474 = (undefined4)_DAT_130b720b6e5;
      uRam00000130b720b478 = (undefined4)((ulonglong)_DAT_130b720b6e5 >> 0x20);
      _DAT_130b720b4c0 = CONCAT44(DAT_130b720b4c0_4,param_2);
      _DAT_130b720b4a8 = param_5;
      _DAT_130b720b4b0 = 0;
      _DAT_130b720b4b8 = _DAT_130b720b6ed;
      lVar2 = 0x130b720bb28;
      if (*(longlong *)(param_1 + 4) != 0) {
        lVar2 = param_1;
      }
      _DAT_130b720b490 = param_3;
      _DAT_130b720b498 = param_4;
      FUN_130b71d0a30(&local_90,lVar2,0,0x130b72074e8);
      (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_90,0x47,local_80);
      if ((_DAT_130b720b4c0 & 0xffffffff) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71dcc28 */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)((_DAT_130b720b4c0 & 0xffffffff) * 8 + 0x130b7201230))();
        return uVar1;
      }
      _DAT_130b720b560 = CONCAT44(_DAT_130b720b564,0x2733);
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b72030d8);
      FUN_130b71d0000(&local_90);
    }
    else {
      _DAT_130b720b560 = CONCAT44(_DAT_130b720b564,0x271d);
      FUN_130b71d0a30(0x130b720b594,0x130b7202088,0,0x130b7206948);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,2,0x590008,0x130b7203160,0x590008,0x130b7202038);
    _DAT_130b720b560 = CONCAT44(_DAT_130b720b564,0x272b);
  }
  return 0;
}



/* Address: 130b71dcd90 */

ulonglong FUN_130b71dcd90(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 unaff_RSI;
  undefined8 local_48;
  undefined4 local_40;
  undefined1 local_38 [8];
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,param_2,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (uVar2 < 2) goto LAB_130b71dd0f3;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,param_2,0x32);
  if (uVar2 == 2) {
    if (*(int *)(param_1 + 0x20) == 5) goto LAB_130b71dd0f3;
    if ((uVar3 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      goto LAB_130b71dd0f3;
    }
    if ((uVar3 & 2) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 1;
      *(undefined4 *)(param_1 + 0x74) = 1;
      goto LAB_130b71dd0f3;
    }
LAB_130b71dd073:
    *(undefined4 *)(param_1 + 0x110) = 0x272e;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x2a5);
    if (iVar1 == 2) {
LAB_130b71dd0dd:
      *(undefined4 *)(param_1 + 0x74) = 2;
      goto LAB_130b71dd0f3;
    }
    if (iVar1 == 1) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x130b720bb28;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_130b71d0a30(&local_48,lVar5,0,0x130b72074d8);
        (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71dcf7b */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x130b7201270))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7203060);
        FUN_130b71d0000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_130b71dd0dd;
      }
      uVar3 = uVar3 & 2;
joined_r0x0130b71dd071:
      if (uVar3 != 0) {
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x2a5);
        goto LAB_130b71dd0f3;
      }
      goto LAB_130b71dd073;
    }
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x130b720bb28;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_130b71d0a30(&local_48,lVar5,0,0x130b72074d8);
        (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71dced2 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x130b7201290))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7203060);
        FUN_130b71d0000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_130b71dd0dd;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x0130b71dd071;
    }
    *(undefined4 *)(param_1 + 0x110) = 0x271b;
  }
  uVar4 = 0;
LAB_130b71dd0f3:
  return uVar4 & 0xffffffff;
}



/* Address: 130b71dd110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_130b71dd110(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_78;
  undefined8 local_74;
  
  local_78 = 0;
  local_74 = 0;
  if (_DAT_130b720bb14 == 0) {
    cVar1 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      FUN_130b71d0000(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      FUN_130b71d0000(param_1 + 0x84);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
      FUN_130b71d0000(param_1 + 0x144);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
      FUN_130b71d0000(param_1 + 0x208);
      *(undefined8 *)(param_1 + 0x28c) = 0;
      *(undefined8 *)(param_1 + 0x284) = 0;
      *(undefined8 *)(param_1 + 0x27c) = 0;
      *(undefined8 *)(param_1 + 0x274) = 0;
      *(undefined8 *)(param_1 + 0x26c) = 0;
      *(undefined8 *)(param_1 + 0x264) = 0;
      *(undefined8 *)(param_1 + 0x25c) = 0;
      *(undefined8 *)(param_1 + 0x254) = 0;
      *(undefined8 *)(param_1 + 0x24c) = 0;
      *(undefined8 *)(param_1 + 0x244) = 0;
      *(undefined8 *)(param_1 + 0x23c) = 0;
      *(undefined8 *)(param_1 + 0x234) = 0;
      *(undefined8 *)(param_1 + 0x22c) = 0;
      *(undefined8 *)(param_1 + 0x224) = 0;
      *(undefined8 *)(param_1 + 0x21c) = 0;
      *(undefined8 *)(param_1 + 0x214) = 0;
      *(undefined4 *)(param_1 + 0x20) = 6;
      *(undefined8 *)(param_1 + 0x90) = param_2;
      (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7206978);
      FUN_130b71d0a30(param_1 + 0x34,&local_78,0,0x130b7206988);
      *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
      *(undefined8 *)(param_1 + 0x58) = param_3;
      *(undefined8 *)(param_1 + 0x60) = param_4;
      uVar2 = FUN_130b71d1010(param_1,param_1 + 0x20,param_1 + 0x110);
      goto LAB_130b71dd3e2;
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,2,0x590008,0x130b7203160,0x590008,0x130b72020e0);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  uVar2 = 0;
LAB_130b71dd3e2:
  FUN_130b71d0000(&local_78);
  return uVar2;
}



/* Address: 130b71dd410 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_130b71dd410(longlong param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_58;
  undefined8 local_54;
  longlong local_48;
  
  local_58 = 0;
  local_68 = 0;
  local_54 = 0;
  local_64 = 0;
  if (_DAT_130b720bb14 == 0) {
    local_48 = param_3;
    cVar1 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8);
    if (cVar1 != '\0') {
      local_68 = 0;
      local_64 = 0;
      (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
      FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7206998);
      FUN_130b71d0a30(&local_68,&local_58,0,0x130b72069a8);
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      FUN_130b71d0000(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      FUN_130b71d0000(param_1 + 0x84);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
      FUN_130b71d0000(param_1 + 0x144);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
      FUN_130b71d0000(param_1 + 0x208);
      *(undefined8 *)(param_1 + 0x28c) = 0;
      *(undefined8 *)(param_1 + 0x284) = 0;
      *(undefined8 *)(param_1 + 0x27c) = 0;
      *(undefined8 *)(param_1 + 0x274) = 0;
      *(undefined8 *)(param_1 + 0x26c) = 0;
      *(undefined8 *)(param_1 + 0x264) = 0;
      *(undefined8 *)(param_1 + 0x25c) = 0;
      *(undefined8 *)(param_1 + 0x254) = 0;
      *(undefined8 *)(param_1 + 0x24c) = 0;
      *(undefined8 *)(param_1 + 0x244) = 0;
      *(undefined8 *)(param_1 + 0x23c) = 0;
      *(undefined8 *)(param_1 + 0x234) = 0;
      *(undefined8 *)(param_1 + 0x22c) = 0;
      *(undefined8 *)(param_1 + 0x224) = 0;
      *(undefined8 *)(param_1 + 0x21c) = 0;
      *(undefined8 *)(param_1 + 0x214) = 0;
      cVar1 = FUN_130b71dcd90(param_1,&local_68);
      if (cVar1 != '\0') {
        iVar2 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8);
        *(uint *)(param_1 + 0x70) = (uint)(iVar2 == 0);
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_68,(iVar2 != 0) * '\x03' + '\x01');
        *(undefined8 *)(param_1 + 0x48) = _DAT_130b720bb48;
        *(undefined4 *)(param_1 + 0x20) = 1;
        *(undefined8 *)(param_1 + 0x90) = param_2;
        FUN_130b71d0a30(param_1 + 0x34,&local_68,0,0x130b72069b8);
        (*(code *)0x7ff63a107f70)(0x130b53f81d8,3);
        *(undefined8 *)(param_1 + 0x40) = _DAT_130b720bb48;
        *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
        lVar4 = local_48;
        if (local_48 == -1) {
          lVar4 = *(longlong *)(param_1 + 0x29d);
        }
        *(longlong *)(param_1 + 0x68) = lVar4;
        uVar3 = FUN_130b71d1010(param_1,param_1 + 0x20,param_1 + 0x110);
        FUN_130b71d0000(&local_68);
        goto LAB_130b71dd4b7;
      }
      FUN_130b71d0000(&local_68);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,2,0x590008,0x130b7203160,0x590008,0x130b7202128);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  uVar3 = 0;
LAB_130b71dd4b7:
  FUN_130b71d0000(&local_58);
  return uVar3;
}



/* Address: 130b71dd7f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71dd7f0(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_130b71d0a30(param_2,0x130b7201870,0,0x130b7206ba8);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x130b720bb28;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_130b71d0a30(&local_98,piVar12,0,0x130b7206bb8);
  (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x130b53f81d8,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71dd9d0 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x130b72012b0))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(longlong)*param_3,0x52,&local_108);
  FUN_130b71d0a30(&local_f8,0x130b7202730,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_130b71de2bb;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_130b71de2bb;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_130b71d0060(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1e04cf000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xf04a0000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xf04a5000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x150470000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x150489000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x15043c000101f9);
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x150457000101f9);
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
      if (uVar13 == uVar14) goto LAB_130b71df592;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_130b71df592:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_130b71de2bb:
  uVar9 = local_e8;
  FUN_130b71d0a30(local_e8,&local_f8,0,0x130b7207178);
  FUN_130b71d0a30(&local_68,uVar9,0,0x130b7207188);
  FUN_130b71d0000(&local_98);
  FUN_130b71d0000(&local_e0);
  FUN_130b71d0000(&local_88);
  FUN_130b71d0000(&local_78);
  FUN_130b71d0000(&local_c0);
  FUN_130b71d0a30(0x130b720bb3c,&local_68,1,0x130b7207198);
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_108);
  FUN_130b71d0000(&local_f8);
  FUN_130b71d0000(&local_d0);
  FUN_130b71d0000(&local_b0);
  return;
}



/* Address: 130b71df8b0 */

void FUN_130b71df8b0(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x0130b71df913 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x130b7201320))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(ulonglong)param_2,0x53,&local_50);
  FUN_130b71d0a30(&local_60,0x130b7201ec8,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_130b71dfb0d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_130b71dfb0d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_130b71d0060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2203c7000101f9);
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
      if (uVar11 == uVar13) goto LAB_130b71dfb02;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_130b71dfb02:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_130b71dfb0d:
  FUN_130b71d0a30(param_1,&local_60,0,0x130b7206ad8);
  FUN_130b71d0a30(&local_40,param_1,0,0x130b7206ae8);
  FUN_130b71d0a30(0x130b720bb3c,&local_40,1,0x130b7206af8);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_60);
  return;
}



/* Address: 130b71dfbb0 */

void FUN_130b71dfbb0(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7206b08);
    FUN_130b71d0a30(&local_88,&local_78,0,0x130b7206b18);
    (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,param_3,param_4);
    FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7206b28);
    FUN_130b71d0a30(&local_98,&local_78,0,0x130b7206b38);
    (*(code *)0x7ff63a0e49f0)
              (0x130b53f81d8,0xd8,3,0x590008,0x130b7201f90,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x130b7206b58;
    uVar1 = 0x130b7206b48;
  }
  else {
    uVar2 = 0x130b7206b78;
    uVar1 = 0x130b7206b68;
  }
  FUN_130b71d0a30(&local_78,0x130b720bb3c,1,uVar1);
  FUN_130b71d0a30(param_1,&local_78,0,uVar2);
  FUN_130b71d0a30(&local_68,param_1,0,0x130b7206b88);
  FUN_130b71d0000(&local_98);
  FUN_130b71d0000(&local_88);
  FUN_130b71d0a30(0x130b720bb3c,&local_68,1,0x130b7206b98);
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_78);
  return;
}



/* Address: 130b71dfdf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71dfdf0(longlong param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_38;
  undefined8 local_34;
  ulonglong uVar5;
  
  cVar1 = DAT_130b720b2b1;
  local_48 = 0;
  local_38 = 0;
  local_44 = 0;
  local_34 = 0;
  iVar2 = FUN_130b71d0c50();
  if (cVar1 == '\x01') {
    lVar6 = *(longlong *)(param_1 + 4);
    if ((lVar6 == 0) || (lVar6 == 0xc)) {
      _DAT_130b720bb10 = 0xfa9;
    }
    else {
      uVar7 = *(uint *)(lVar6 + -4);
      if ((ulonglong)uVar7 != 0) {
        lVar3 = 0;
        uVar8 = uVar7;
        do {
          uVar5 = (ulonglong)*(ushort *)(lVar6 + -2 + (ulonglong)uVar7 * 2 + lVar3 * 2);
          if ((0x20 < uVar5) || ((0x100002600U >> (uVar5 & 0x3f) & 1) == 0)) {
            if ((int)lVar3 == 0) goto LAB_130b71e0015;
            uVar4 = -(int)lVar3;
            break;
          }
          lVar3 = lVar3 + -1;
          uVar8 = uVar8 - 1;
          uVar4 = uVar7;
        } while (uVar8 != 0);
        uVar7 = uVar7 - uVar4;
        cVar1 = FUN_130b71d0060(param_1,uVar7);
        if (cVar1 != '\0') {
          lVar6 = *(longlong *)(param_1 + 4);
          *(uint *)(lVar6 + -4) = uVar7;
          *(undefined2 *)(lVar6 + (ulonglong)uVar7 * 2) = 0;
        }
      }
    }
    goto LAB_130b71e0015;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(longlong)iVar2,0x52,&local_48);
  FUN_130b71d0a30(param_1,&local_48,0,0x130b7207548);
  lVar6 = *(longlong *)(param_1 + 4);
  if ((lVar6 == 0) || (lVar6 == 0xc)) {
    lVar6 = 0;
    _DAT_130b720bb10 = 0xfa9;
  }
  else {
    uVar7 = *(uint *)(lVar6 + -4);
    uVar5 = (ulonglong)uVar7;
    if (uVar5 != 0) {
      lVar3 = uVar5 * 2;
      lVar10 = 0;
      do {
        uVar9 = (ulonglong)*(ushort *)(lVar6 + -2 + lVar3 + lVar10 * 2);
        if ((0x20 < uVar9) || ((0x100002600U >> (uVar9 & 0x3f) & 1) == 0)) {
          if ((int)lVar10 == 0) goto LAB_130b71dffe3;
          uVar8 = -(int)lVar10;
          break;
        }
        lVar10 = lVar10 + -1;
        uVar4 = (int)uVar5 - 1;
        uVar5 = (ulonglong)uVar4;
        uVar8 = uVar7;
      } while (uVar4 != 0);
      uVar7 = uVar7 - uVar8;
      cVar1 = FUN_130b71d0060(param_1,uVar7);
      if (cVar1 != '\0') {
        lVar3 = *(longlong *)(param_1 + 4);
        lVar6 = (longlong)(int)uVar8;
        *(uint *)(lVar3 + -4) = uVar7;
        *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
        goto LAB_130b71dffe5;
      }
    }
LAB_130b71dffe3:
    lVar6 = 0;
  }
LAB_130b71dffe5:
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,lVar6,0x52,&local_48);
  FUN_130b71d0a30(param_1,&local_48,0,0x130b7207558);
LAB_130b71e0015:
  FUN_130b71d0a30(&local_38,param_1,0,0x130b7207568);
  FUN_130b71d0a30(0x130b720bb3c,&local_38,1,0x130b7207578);
  FUN_130b71d0000(&local_38);
  FUN_130b71d0000(&local_48);
  return;
}



/* Address: 130b71e0070 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71e0070(double param_1)

{
  longlong lVar1;
  uint uVar2;
  byte bVar3;
  ulonglong uVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
  dVar8 = _DAT_130b720bb48;
  uVar2 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x11);
  if ((dVar8 != 0.0) || (NAN(dVar8))) {
    param_1 = param_1 / dVar8;
    uVar5 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar5 - 0x3ff;
    dVar7 = param_1;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar7 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar7 = (double)((ulonglong)param_1 & 0x8000000000000000);
        }
      }
      else {
        bVar3 = (byte)lVar1;
        if (((longlong)param_1 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar7 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)param_1 &
                          -0x10000000000000 >> (bVar3 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar7 = param_1 + param_1;
    }
    dVar8 = dVar8 * dVar7;
    if ((longlong)dVar8 == -0x8000000000000000) {
      return dVar8;
    }
    dVar7 = (double)(longlong)dVar8;
    uVar4 = 0xb;
    if (uVar2 < 0xb) {
      uVar4 = (ulonglong)uVar2;
    }
    dVar6 = *(double *)(&DAT_130b7201710 + uVar4 * 8);
    dVar8 = (dVar8 - dVar7) * dVar6 + *(double *)((ulonglong)(0.0 < dVar8) * 8 + 0x130b7201360);
  }
  else {
    if ((longlong)param_1 == -0x8000000000000000) {
      return param_1;
    }
    dVar7 = (double)(longlong)param_1;
    uVar4 = 0xb;
    if (uVar2 < 0xb) {
      uVar4 = (ulonglong)uVar2;
    }
    dVar6 = *(double *)(&DAT_130b7201710 + uVar4 * 8);
    dVar8 = (param_1 - dVar7) * dVar6 + *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x130b7201360);
  }
  return (double)(longlong)dVar8 / dVar6 + dVar7;
}



/* Address: 130b71e0270 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_130b71e0270(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined4 local_58;
  longlong local_54;
  longlong local_48;
  
  local_58 = 0;
  local_54 = 0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
  if (iVar8 + -1 < 0) {
    iVar11 = 0;
  }
  else {
    iVar11 = 0;
    lVar13 = (longlong)_DAT_130b720bcb8;
    local_48 = (longlong)(_DAT_130b720bcb8 + 100);
    iVar8 = iVar8 + -1;
    do {
      lVar9 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
      if (lVar9 != 0) {
        cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar9);
        if (cVar7 != '\0') {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7207668);
          if (local_54 == _DAT_130b720bb2c) {
LAB_130b71e03e2:
            lVar9 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if (lVar13 <= lVar9) {
              iVar11 = iVar11 + (uint)(lVar9 < local_48);
            }
          }
          else if ((local_54 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar3 = *(uint *)(local_54 + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar10 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar12 = 1;
              do {
                uVar1 = *(ushort *)(local_54 + -2 + uVar12 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar12 * 2);
                if (uVar6 <= uVar12) break;
                uVar12 = uVar12 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar10 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar10 == 0) goto LAB_130b71e03e2;
          }
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  FUN_130b71d0000(&local_58);
  return iVar11;
}



/* Address: 130b71e0440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_130b71e0440(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined4 local_58;
  longlong local_54;
  longlong local_48;
  
  local_58 = 0;
  local_54 = 0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
  if (-1 < iVar8 + -1) {
    lVar14 = (longlong)_DAT_130b720bcb8;
    iVar9 = _DAT_130b720bcb8 + 100;
    iVar8 = iVar8 + -1;
    local_48 = lVar14;
    do {
      lVar11 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
      if (lVar11 != 0) {
        cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar11);
        if (cVar7 != '\0') {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7207678);
          if (local_54 == _DAT_130b720bb2c) {
LAB_130b71e05c3:
            lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if ((lVar14 <= lVar11) && (lVar11 < iVar9)) {
              iVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
              if (iVar10 == param_1) {
                uVar12 = 0x3a107d01;
                goto LAB_130b71e060e;
              }
            }
          }
          else if ((local_54 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar3 = *(uint *)(local_54 + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar10 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar13 = 1;
              do {
                uVar1 = *(ushort *)(local_54 + -2 + uVar13 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar13 * 2);
                if (uVar6 <= uVar13) break;
                uVar13 = uVar13 + 1;
              } while (uVar1 == uVar2);
              lVar14 = local_48;
              if (uVar1 != uVar2) {
                iVar10 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar10 == 0) goto LAB_130b71e05c3;
          }
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  uVar12 = 0;
LAB_130b71e060e:
  FUN_130b71d0000(&local_58);
  return uVar12;
}



/* Address: 130b71e0640 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e0640(void)

{
  code *pcVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x10);
  _DAT_130b720b7a0 = _DAT_130b720bb48;
  _DAT_130b720b7b0 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x11);
  _DAT_130b720b7a8 = _DAT_130b720b7a0;
  if ((_DAT_130b720b7b0 == 5) || (_DAT_130b720b7b0 == 3)) {
    _DAT_130b720b7a8 = _DAT_130b720b7a0 * _DAT_130b7201370;
  }
  (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,0x4018,1);
  uVar3 = SUB84(_DAT_130b720bb48,0);
  uVar4 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  if (_DAT_130b720bb48 <= 0.0) {
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
    uVar3 = SUB84(_DAT_130b720bb48,0);
    uVar4 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  }
  dVar5 = _DAT_130b7201378;
  if (0.0 <= (double)CONCAT44(uVar4,uVar3) && (double)CONCAT44(uVar4,uVar3) != 0.0) {
    if ((_DAT_130b720b790 == 0.0) && (!NAN(_DAT_130b720b790))) {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2c034d000001f7);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    dVar5 = (double)CONCAT44(uVar4,uVar3) / _DAT_130b720b790;
  }
  _DAT_130b720b7b4 =
       (double)(~-(ulonglong)(0.0 < dVar5) & (ulonglong)_DAT_130b7201378 |
               (ulonglong)dVar5 & -(ulonglong)(0.0 < dVar5));
  _DAT_130b720b7bc = _DAT_130b720b730 * _DAT_130b720b7b4;
  _DAT_130b720b7c4 = _DAT_130b720b738 * _DAT_130b720b7b4;
  if ((longlong)_DAT_130b720b7c4 != -0x8000000000000000) {
    dVar5 = (double)(longlong)_DAT_130b720b7c4;
    _DAT_130b720b7c4 =
         (double)(longlong)
                 ((_DAT_130b720b7c4 - dVar5) +
                 *(double *)((ulonglong)(0.0 < _DAT_130b720b7c4) * 8 + 0x130b7201380)) + dVar5;
  }
  _DAT_130b720b7cc = _DAT_130b720b740 * _DAT_130b720b7b4;
  if ((longlong)_DAT_130b720b7cc != -0x8000000000000000) {
    dVar5 = (double)(longlong)_DAT_130b720b7cc;
    _DAT_130b720b7cc =
         (double)(longlong)
                 ((_DAT_130b720b7cc - dVar5) +
                 *(double *)((ulonglong)(0.0 < _DAT_130b720b7cc) * 8 + 0x130b7201380)) + dVar5;
  }
  _DAT_130b720b7d4 = _DAT_130b720b748;
  _DAT_130b720b7e4 = _DAT_130b720b750 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b7ec = _DAT_130b720b758 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b7fc = _DAT_130b720b760 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b804 = _DAT_130b720b768 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b80c = _DAT_130b720b770 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b814 = _DAT_130b720b778 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b81c = _DAT_130b720b780 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b824 = _DAT_130b720b788 * _DAT_130b720b7b4 * _DAT_130b720b7a8;
  _DAT_130b720b7f4 = _DAT_130b7201398 * _DAT_130b720b7a8;
  _DAT_130b720b7dc = (_DAT_130b720b7a8 / _DAT_130b7201390) * _DAT_130b720b398;
  lVar2 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x1f);
  _DAT_130b720b82c = (double)lVar2 * _DAT_130b720b7a0;
  lVar2 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x20);
  _DAT_130b720b834 = (double)lVar2 * _DAT_130b720b7a0;
  return;
}



/* Address: 130b71e0af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71e0af0(double param_1)

{
  ulonglong uVar1;
  double dVar2;
  
  if ((longlong)param_1 != -0x8000000000000000) {
    dVar2 = (double)(longlong)param_1;
    uVar1 = 0xb;
    if (_DAT_130b720b7b0 < 0xb) {
      uVar1 = (ulonglong)_DAT_130b720b7b0;
    }
    param_1 = (double)(longlong)
                      ((param_1 - dVar2) * *(double *)(&DAT_130b7201710 + uVar1 * 8) +
                      *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x130b72013a0)) /
              *(double *)(&DAT_130b7201710 + uVar1 * 8) + dVar2;
  }
  return param_1;
}



/* Address: 130b71e0b70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_130b71e0b70(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong *plVar11;
  uint uVar12;
  ulonglong uVar13;
  
  uVar7 = (ulonglong)_DAT_130b720b418;
  if ((int)_DAT_130b720b418 < 1) {
    iVar6 = 0;
  }
  else if (_DAT_130b720bb2c == 0) {
    plVar11 = (longlong *)(_DAT_130b720b42c + 8);
    iVar6 = 0;
    do {
      if ((((*(char *)((longlong)plVar11 + 0x54) != '\0') && (*plVar11 == 0)) &&
          ((int)plVar11[1] == param_1)) && (_DAT_130b720bcb8 <= (int)plVar11[7])) {
        iVar6 = iVar6 + (uint)((int)plVar11[7] < _DAT_130b720bcb8 + 100);
      }
      plVar11 = (longlong *)((longlong)plVar11 + 0x62);
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  else {
    uVar9 = 0;
    iVar6 = 0;
    do {
      lVar10 = uVar9 * 0x62;
      if (*(char *)(_DAT_130b720b42c + 0x5c + lVar10) != '\0') {
        lVar5 = *(longlong *)(_DAT_130b720b42c + 8 + lVar10);
        if (lVar5 == _DAT_130b720bb2c) {
LAB_130b71e0c50:
          if ((*(int *)(_DAT_130b720b42c + 0x10 + lVar10) == param_1) &&
             (iVar8 = *(int *)(_DAT_130b720b42c + 0x40 + lVar10), _DAT_130b720bcb8 <= iVar8)) {
            iVar6 = iVar6 + (uint)(iVar8 < _DAT_130b720bcb8 + 100);
          }
        }
        else if (lVar5 != 0) {
          uVar3 = *(uint *)(lVar5 + -4);
          uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
          uVar12 = uVar4;
          if (uVar3 < uVar4) {
            uVar12 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar12 != 0) {
            uVar13 = 1;
            do {
              uVar1 = *(ushort *)(lVar5 + -2 + uVar13 * 2);
              uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar13 * 2);
              if (uVar12 <= uVar13) break;
              uVar13 = uVar13 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_130b71e0c50;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != uVar7);
  }
  return iVar6;
}



/* Address: 130b71e0ce0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71e0ce0(int param_1,double param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  uint uVar8;
  longlong lVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar6 = (ulonglong)_DAT_130b720b418;
  if (0 < (int)_DAT_130b720b418) {
    if (_DAT_130b720bb2c == 0) {
      plVar7 = (longlong *)(_DAT_130b720b42c + 8);
      do {
        if (((((*(char *)((longlong)plVar7 + 0x54) != '\0') && (*plVar7 == 0)) &&
             ((int)plVar7[1] == param_1)) &&
            ((_DAT_130b720bcb8 <= (int)plVar7[7] && ((int)plVar7[7] < _DAT_130b720bcb8 + 100)))) &&
           ((double)((ulonglong)(*(double *)((longlong)plVar7 + 0x14) - param_2) & _DAT_130b72013b0)
            < _DAT_130b720b7d4 * _DAT_130b720b7a8)) goto LAB_130b71e0e7b;
        plVar7 = (longlong *)((longlong)plVar7 + 0x62);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    else {
      uVar11 = 0;
      do {
        lVar9 = uVar11 * 0x62;
        if (*(char *)(_DAT_130b720b42c + 0x5c + lVar9) != '\0') {
          lVar5 = *(longlong *)(_DAT_130b720b42c + 8 + lVar9);
          if (lVar5 == _DAT_130b720bb2c) {
LAB_130b71e0df0:
            if (((*(int *)(_DAT_130b720b42c + 0x10 + lVar9) == param_1) &&
                (iVar10 = *(int *)(_DAT_130b720b42c + 0x40 + lVar9), _DAT_130b720bcb8 <= iVar10)) &&
               ((iVar10 < _DAT_130b720bcb8 + 100 &&
                ((double)((ulonglong)(*(double *)(_DAT_130b720b42c + 0x1c + lVar9) - param_2) &
                         _DAT_130b72013b0) < _DAT_130b720b7d4 * _DAT_130b720b7a8)))) {
LAB_130b71e0e7b:
              return CONCAT71((int7)(uVar6 >> 8),1);
            }
          }
          else if (lVar5 != 0) {
            uVar3 = *(uint *)(lVar5 + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar8 = uVar4;
            if (uVar3 < uVar4) {
              uVar8 = uVar3;
            }
            iVar10 = uVar3 - uVar4;
            if (uVar8 != 0) {
              uVar12 = 1;
              do {
                uVar1 = *(ushort *)(lVar5 + -2 + uVar12 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar12 * 2);
                if (uVar8 <= uVar12) break;
                uVar12 = uVar12 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar10 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar10 == 0) goto LAB_130b71e0df0;
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 != uVar6);
    }
  }
  return 0;
}



/* Address: 130b71e0e90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71e0e90(int param_1,double param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  uint uVar13;
  ulonglong uVar14;
  
  uVar8 = (ulonglong)_DAT_130b720b418;
  uVar7 = 0x130b720b401;
  if (0 < (int)_DAT_130b720b418) {
    iVar1 = _DAT_130b720bcb8 + 100;
    if (_DAT_130b720bb2c == 0) {
      plVar12 = (longlong *)(_DAT_130b720b42c + 8);
      do {
        if (((*(char *)((longlong)plVar12 + 0x54) != '\0') && (*plVar12 == 0)) &&
           (((int)plVar12[1] == param_1 &&
            ((_DAT_130b720bcb8 <= (int)plVar12[7] && ((int)plVar12[7] < iVar1)))))) {
          if (param_1 == 4) {
            if (*(double *)((longlong)plVar12 + 0x14) <= param_2) {
              return 0;
            }
          }
          else if ((param_1 == 5) && (param_2 <= *(double *)((longlong)plVar12 + 0x14))) {
            return 0;
          }
        }
        plVar12 = (longlong *)((longlong)plVar12 + 0x62);
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    else {
      uVar10 = 0;
      do {
        lVar11 = uVar10 * 0x62;
        if (*(char *)(_DAT_130b720b42c + 0x5c + lVar11) != '\0') {
          lVar6 = *(longlong *)(_DAT_130b720b42c + 8 + lVar11);
          if (lVar6 == _DAT_130b720bb2c) {
LAB_130b71e0f80:
            if (((*(int *)(_DAT_130b720b42c + 0x10 + lVar11) == param_1) &&
                (iVar9 = *(int *)(_DAT_130b720b42c + 0x40 + lVar11), _DAT_130b720bcb8 <= iVar9)) &&
               (iVar9 < iVar1)) {
              if (param_1 == 5) {
                if (param_2 <= *(double *)(_DAT_130b720b42c + 0x1c + lVar11)) {
                  return 0;
                }
              }
              else if ((param_1 == 4) && (*(double *)(_DAT_130b720b42c + 0x1c + lVar11) <= param_2))
              {
                return 0;
              }
            }
          }
          else if (lVar6 != 0) {
            uVar4 = *(uint *)(lVar6 + -4);
            uVar5 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar13 = uVar5;
            if (uVar4 < uVar5) {
              uVar13 = uVar4;
            }
            iVar9 = uVar4 - uVar5;
            if (uVar13 != 0) {
              uVar14 = 1;
              do {
                uVar2 = *(ushort *)(lVar6 + -2 + uVar14 * 2);
                uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar14 * 2);
                if (uVar13 <= uVar14) break;
                uVar14 = uVar14 + 1;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar9 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar9 == 0) goto LAB_130b71e0f80;
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != uVar8);
      uVar7 = CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);
    }
  }
  return uVar7;
}



/* Address: 130b71e1030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71e1030(undefined4 param_1,double param_2,double param_3,double param_4)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  double dVar11;
  
  uVar8 = (ulonglong)(int)_DAT_130b720b418;
  if (0 < (longlong)uVar8) {
    uVar6 = 0;
    pcVar5 = (char *)(_DAT_130b720b42c + 0x5c);
    do {
      if (*pcVar5 == '\0') goto LAB_130b71e10ce;
      uVar6 = uVar6 + 1;
      pcVar5 = pcVar5 + 0x62;
    } while (_DAT_130b720b418 != (uint)uVar6);
  }
  (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b410,_DAT_130b720b418 + 1,0);
  uVar6 = uVar8;
LAB_130b71e10ce:
  iVar1 = _DAT_130b720b704 + 1;
  if (uVar6 < _DAT_130b720b418) {
    lVar9 = uVar6 * 0x62;
    iVar3 = iVar1;
    *(int *)(_DAT_130b720b42c + lVar9) = _DAT_130b720b704;
    _DAT_130b720b704 = iVar3;
    if (2100000000 < iVar1) {
      _DAT_130b720b704 = 1900000000;
    }
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1524;
    FUN_130b71d0a30(_DAT_130b720b42c + 4 + lVar9,0x130b720bb28,
                    CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1),0x130b7207688);
    iVar1 = _DAT_130b720bcd0;
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1544;
    *(undefined4 *)(_DAT_130b720b42c + 0x10 + lVar9) = param_1;
    if ((iVar1 == 3) && (_DAT_130b720b390 = _DAT_130b72013c0, (ulonglong)_DAT_130b720bcd8 < 8)) {
      _DAT_130b720b390 = *(undefined8 *)((ulonglong)_DAT_130b720bcd8 * 8 + 0x130b7209eb0);
    }
    uVar10 = FUN_130b71ef790(iVar1,_DAT_130b720bce0,&DAT_130b720bce8,_DAT_130b720bcf0,
                             _DAT_130b720bcf8,_DAT_130b720b398,_DAT_130b720b390);
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1564;
    *(undefined8 *)(_DAT_130b720b42c + 0x14 + lVar9) = uVar10;
    if ((longlong)param_2 != -0x8000000000000000) {
      dVar11 = (double)(longlong)param_2;
      uVar8 = 0xb;
      if (_DAT_130b720b7b0 < 0xb) {
        uVar8 = (ulonglong)_DAT_130b720b7b0;
      }
      param_2 = (double)(longlong)
                        ((param_2 - dVar11) * *(double *)(&DAT_130b7201710 + uVar8 * 8) +
                        *(double *)((ulonglong)(0.0 < param_2) * 8 + 0x130b72013c8)) /
                *(double *)(&DAT_130b7201710 + uVar8 * 8) + dVar11;
    }
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1584;
    *(double *)(_DAT_130b720b42c + 0x1c + lVar9) = param_2;
    if ((longlong)param_3 != -0x8000000000000000) {
      dVar11 = (double)(longlong)param_3;
      uVar8 = 0xb;
      if (_DAT_130b720b7b0 < 0xb) {
        uVar8 = (ulonglong)_DAT_130b720b7b0;
      }
      param_3 = (double)(longlong)
                        ((param_3 - dVar11) * *(double *)(&DAT_130b7201710 + uVar8 * 8) +
                        *(double *)((ulonglong)(0.0 < param_3) * 8 + 0x130b72013c8)) /
                *(double *)(&DAT_130b7201710 + uVar8 * 8) + dVar11;
    }
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e15a4;
    *(double *)(_DAT_130b720b42c + 0x24 + lVar9) = param_3;
    if ((longlong)param_4 != -0x8000000000000000) {
      dVar11 = (double)(longlong)param_4;
      uVar8 = 0xb;
      if (_DAT_130b720b7b0 < 0xb) {
        uVar8 = (ulonglong)_DAT_130b720b7b0;
      }
      param_4 = (double)(longlong)
                        ((param_4 - dVar11) * *(double *)(&DAT_130b7201710 + uVar8 * 8) +
                        *(double *)((ulonglong)(0.0 < param_4) * 8 + 0x130b72013c8)) /
                *(double *)(&DAT_130b7201710 + uVar8 * 8) + dVar11;
    }
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e15c4;
    *(double *)(_DAT_130b720b42c + 0x2c + lVar9) = param_4;
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e15e4;
    FUN_130b71d0a30(_DAT_130b720b42c + 0x34 + lVar9,0x130b720b3f8,0,0x130b7207698);
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1604;
    *(int *)(_DAT_130b720b42c + 0x40 + lVar9) = _DAT_130b720b3f0 + 9;
    uVar10 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1624;
    *(undefined8 *)(_DAT_130b720b42c + 0x4c + lVar9) = uVar10;
    lVar4 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1644;
    lVar7 = lVar4 + 72000;
    if (DAT_130b720b72a == '\0') {
      lVar7 = lVar4;
    }
    *(longlong *)(_DAT_130b720b42c + 0x44 + lVar9) = lVar7;
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1664;
    *(undefined8 *)(_DAT_130b720b42c + 0x54 + lVar9) = 0;
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e1684;
    *(undefined1 *)(_DAT_130b720b42c + 0x5d + lVar9) = 0;
    if (_DAT_130b720b418 <= uVar6) goto LAB_130b71e16a4;
    *(undefined4 *)(_DAT_130b720b42c + 0x5e + lVar9) = 0;
    if (uVar6 < _DAT_130b720b418) {
      *(undefined1 *)(_DAT_130b720b42c + 0x5c + lVar9) = 1;
      if (uVar6 < _DAT_130b720b418) {
        return (ulonglong)*(uint *)(_DAT_130b720b42c + lVar9);
      }
      goto LAB_130b71e16e4;
    }
  }
  else {
    _DAT_130b720b704 = iVar1;
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03cb000001f6);
LAB_130b71e1524:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03ce000001f6);
LAB_130b71e1544:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03cf000001f6);
LAB_130b71e1564:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d0000001f6);
LAB_130b71e1584:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d1000001f6);
LAB_130b71e15a4:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d2000001f6);
LAB_130b71e15c4:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d3000001f6);
LAB_130b71e15e4:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d4000001f6);
LAB_130b71e1604:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d5000001f6);
LAB_130b71e1624:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d6000001f6);
LAB_130b71e1644:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d7000001f6);
LAB_130b71e1664:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d8000001f6);
LAB_130b71e1684:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03d9000001f6);
LAB_130b71e16a4:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03da000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03db000001f6);
LAB_130b71e16e4:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1103dc000001f6);
  pcVar2 = (code *)swi(3);
  uVar8 = (*pcVar2)();
  return uVar8;
}



/* Address: 130b71e1710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e1710(void)

{
  longlong lVar1;
  bool bVar2;
  code *pcVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  lVar4 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  uVar5 = _DAT_130b720b418 - 1;
  if (-1 < (int)uVar5) {
    lVar6 = (ulonglong)uVar5 * 0x62 + 0x5c;
    uVar7 = (ulonglong)uVar5;
    uVar5 = _DAT_130b720b418;
    do {
      if (uVar5 <= uVar7) {
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xd03e3000001f6);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      if (((*(char *)(_DAT_130b720b42c + lVar6) != '\0') &&
          (lVar1 = *(longlong *)(_DAT_130b720b42c + -0x18 + lVar6), 0 < lVar1)) && (lVar1 <= lVar4))
      {
        *(undefined1 *)(_DAT_130b720b42c + lVar6) = 0;
        uVar5 = _DAT_130b720b418;
      }
      lVar6 = lVar6 + -0x62;
      bVar2 = 0 < (longlong)uVar7;
      uVar7 = uVar7 - 1;
    } while (bVar2);
  }
  return;
}



/* Address: 130b71e17c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e17c0(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_d0;
  longlong local_cc;
  undefined4 local_c0;
  longlong local_bc;
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
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_90 = 0;
  local_70 = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_80 = 0;
  local_c0 = 0;
  local_d0 = 0;
  local_60 = 0;
  local_50 = 0;
  local_8c = 0;
  local_6c = 0;
  local_9c = 0;
  local_ac = 0;
  local_7c = 0;
  local_bc = 0;
  local_cc = 0;
  local_5c = 0;
  local_4c = 0;
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,5,0x590008,0x130b7203340,0x520004,0x51,0x520004,0x54,0x520004,0x32,
             0x520004,0x5f);
  FUN_130b71d0a30(&local_60,0x130b720bb3c,1,0x130b72076a8);
  FUN_130b71d0a30(&local_d0,&local_60,0);
  lVar4 = *(longlong *)(param_1 + 4);
  if (lVar4 == 0) {
LAB_130b71e1a5d:
    uVar17 = 0;
    FUN_130b71d0a30(&local_c0,&local_d0,0);
    uVar14 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_bc == 0)) {
      if (local_bc != 0) {
        uVar17 = *(uint *)(local_bc + -4);
      }
      uVar15 = _DAT_130b7203354 + uVar17;
      cVar9 = FUN_130b71d0060(&local_c0);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar4 = local_bc + (ulonglong)uVar17 * 2;
          if ((uVar14 < 0x10) || (lVar4 - 0x130b7203358U < 0x20)) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar2 = (undefined4 *)(lVar4 + uVar16);
              *puVar2 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar2[1] = uVar6;
              puVar2[2] = uVar7;
              puVar2[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71e1b42;
          }
          do {
            *(undefined2 *)(lVar4 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e1b42:
        *(uint *)(local_bc + -4) = uVar15;
        *(undefined2 *)(local_bc + (ulonglong)uVar15 * 2) = 0;
        goto LAB_130b71e1b4d;
      }
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x35044b000001f9);
LAB_130b71e2059:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x63044b000001f9);
      goto LAB_130b71e2079;
    }
LAB_130b71e1b4d:
    uVar10 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,uVar10,0x55,&local_80);
    FUN_130b71d0a30(&local_b0,&local_c0);
    lVar4 = local_7c;
    if (local_7c == 0) {
LAB_130b71e1d0d:
      uVar17 = 0;
      FUN_130b71d0a30(&local_a0,&local_b0,0,0x130b72076e8);
      uVar14 = _DAT_130b7203354;
      uVar13 = (ulonglong)_DAT_130b7203354;
      if ((uVar13 != 0) || (local_9c == 0)) {
        if (local_9c != 0) {
          uVar17 = *(uint *)(local_9c + -4);
        }
        uVar12 = _DAT_130b7203354 + uVar17;
        uVar15 = 0x104;
        if ((0x103 < uVar12) &&
           ((0x7ffffffd < uVar12 || (uVar15 = (uVar12 >> 2) + uVar12, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar9 = FUN_130b71d0060(&local_a0,uVar15);
        if (cVar9 == '\0') goto LAB_130b71e2059;
        if (uVar13 != 0) {
          lVar4 = local_9c + (ulonglong)uVar17 * 2;
          if (uVar14 < 0x10) {
            uVar11 = 0;
          }
          else if (lVar4 - 0x130b7203358U < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar2 = (undefined4 *)(lVar4 + uVar16);
              *puVar2 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar2[1] = uVar6;
              puVar2[2] = uVar7;
              puVar2[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71e1e32;
          }
          do {
            *(undefined2 *)(lVar4 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e1e32:
        *(uint *)(local_9c + -4) = uVar12;
        *(undefined2 *)(local_9c + (ulonglong)uVar12 * 2) = 0;
      }
      (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_2,0x56,&local_70);
      FUN_130b71d0a30(&local_90,&local_a0,0);
      lVar4 = local_6c;
      if (local_6c == 0) goto LAB_130b71e1f8d;
      uVar17 = *(uint *)(local_6c + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_8c != 0)) goto LAB_130b71e1f8d;
      if (local_8c == 0) {
        uVar14 = 0;
        uVar15 = uVar17;
      }
      else {
        uVar14 = *(uint *)(local_8c + -4);
        uVar15 = uVar17 + uVar14;
      }
      cVar9 = FUN_130b71d0060(&local_90);
      if (cVar9 == '\0') goto LAB_130b71e20b9;
      if (uVar13 != 0) {
        lVar1 = local_8c + (ulonglong)uVar14 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar4) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar2 = (undefined4 *)(lVar4 + uVar16);
            uVar6 = puVar2[1];
            uVar7 = puVar2[2];
            uVar8 = puVar2[3];
            puVar3 = (undefined4 *)(lVar1 + uVar16);
            *puVar3 = *puVar2;
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e1f82;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar4 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e1f82:
      *(uint *)(local_8c + -4) = uVar15;
      *(undefined2 *)(local_8c + (ulonglong)uVar15 * 2) = 0;
LAB_130b71e1f8d:
      FUN_130b71d0a30(&local_50,&local_90,0,0x130b7207708);
      FUN_130b71d0a30(0x130b720bb3c,&local_50,1,0x130b7207718);
      FUN_130b71d0000(&local_50);
      FUN_130b71d0000(&local_60);
      FUN_130b71d0000(&local_d0);
      FUN_130b71d0000(&local_c0);
      FUN_130b71d0000(&local_80);
      FUN_130b71d0000(&local_b0);
      FUN_130b71d0000(&local_a0);
      FUN_130b71d0000(&local_70);
      FUN_130b71d0000(&local_90);
      return;
    }
    uVar17 = *(uint *)(local_7c + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_ac != 0)) goto LAB_130b71e1d0d;
    if (local_ac == 0) {
      uVar14 = 0;
      uVar15 = uVar17;
    }
    else {
      uVar14 = *(uint *)(local_ac + -4);
      uVar15 = uVar17 + uVar14;
    }
    cVar9 = FUN_130b71d0060(&local_b0);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_ac + (ulonglong)uVar14 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar4) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar2 = (undefined4 *)(lVar4 + uVar16);
            uVar6 = puVar2[1];
            uVar7 = puVar2[2];
            uVar8 = puVar2[3];
            puVar3 = (undefined4 *)(lVar1 + uVar16);
            *puVar3 = *puVar2;
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e1d02;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar4 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e1d02:
      *(uint *)(local_ac + -4) = uVar15;
      *(undefined2 *)(local_ac + (ulonglong)uVar15 * 2) = 0;
      goto LAB_130b71e1d0d;
    }
  }
  else {
    uVar17 = *(uint *)(lVar4 + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_cc != 0)) goto LAB_130b71e1a5d;
    if (local_cc == 0) {
      uVar11 = 0;
      uVar14 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_cc + -4);
      uVar14 = uVar17 + *(uint *)(local_cc + -4);
    }
    cVar9 = FUN_130b71d0060(&local_d0);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_cc + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar4) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar2 = (undefined4 *)(lVar4 + uVar16);
            uVar6 = puVar2[1];
            uVar7 = puVar2[2];
            uVar8 = puVar2[3];
            puVar3 = (undefined4 *)(lVar1 + uVar16);
            *puVar3 = *puVar2;
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e1a52;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar4 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e1a52:
      *(uint *)(local_cc + -4) = uVar14;
      *(undefined2 *)(local_cc + (ulonglong)uVar14 * 2) = 0;
      goto LAB_130b71e1a5d;
    }
LAB_130b71e2079:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2b044b000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x39044b000001f9);
LAB_130b71e20b9:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x67044b000001f9);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



/* Address: 130b71e20e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e20e0(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined8 uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  local_88 = 0;
  local_68 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_78 = 0;
  local_58 = 0;
  local_48 = 0;
  local_84 = 0;
  local_64 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_74 = 0;
  local_54 = 0;
  local_44 = 0;
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,9,0x590008,0x130b7203390,0x520004,0x51,0x520004,0x54,0x520004,0x42,
             0x520004,0x5f,0x520004,0x56,0x520004,0x54,0x520004,0x50,0x520004,0x5f);
  FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7207728);
  uVar10 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,uVar10,0x55,&local_78);
  FUN_130b71d0a30(&local_a8,&local_58);
  lVar2 = local_74;
  if (local_74 != 0) {
    uVar17 = *(uint *)(local_74 + -4);
    uVar14 = (ulonglong)uVar17;
    if ((uVar14 == 0) && (local_a4 != 0)) goto LAB_130b71e23ed;
    if (local_a4 == 0) {
      uVar12 = 0;
      uVar15 = uVar17;
    }
    else {
      uVar12 = (ulonglong)*(uint *)(local_a4 + -4);
      uVar15 = uVar17 + *(uint *)(local_a4 + -4);
    }
    cVar9 = FUN_130b71d0060(&local_a8);
    if (cVar9 != '\0') {
      if (uVar14 != 0) {
        lVar1 = local_a4 + uVar12 * 2;
        if (uVar17 < 0x10) {
          uVar12 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar12 = 0;
        }
        else {
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar12 == uVar14) goto LAB_130b71e23e2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
          uVar12 = uVar12 + 1;
        } while (uVar14 != uVar12);
      }
LAB_130b71e23e2:
      *(uint *)(local_a4 + -4) = uVar15;
      *(undefined2 *)(local_a4 + (ulonglong)uVar15 * 2) = 0;
      goto LAB_130b71e23ed;
    }
LAB_130b71e2739:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x459000001f9);
LAB_130b71e2759:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x45b000001f9);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
LAB_130b71e23ed:
  uVar17 = 0;
  FUN_130b71d0a30(&local_98,&local_a8,0,0x130b7207748);
  uVar15 = _DAT_130b7203354;
  uVar14 = (ulonglong)_DAT_130b7203354;
  if ((uVar14 != 0) || (local_94 == 0)) {
    if (local_94 != 0) {
      uVar17 = *(uint *)(local_94 + -4);
    }
    uVar13 = _DAT_130b7203354 + uVar17;
    uVar11 = 0x104;
    if ((0x103 < uVar13) &&
       ((0x7ffffffd < uVar13 || (uVar11 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar11)))) {
      uVar11 = 0x7ffffffe;
    }
    cVar9 = FUN_130b71d0060(&local_98,uVar11);
    if (cVar9 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x45a000001f9);
      goto LAB_130b71e2739;
    }
    if (uVar14 != 0) {
      lVar2 = local_94 + (ulonglong)uVar17 * 2;
      if (uVar15 < 0x10) {
        uVar12 = 0;
      }
      else if (lVar2 - 0x130b7203358U < 0x20) {
        uVar12 = 0;
      }
      else {
        uVar16 = 0;
        uVar12 = (ulonglong)(uVar15 & 0xfffffff8);
        do {
          uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
          uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
          uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
          puVar3 = (undefined4 *)(lVar2 + uVar16);
          *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
          puVar3[1] = uVar6;
          puVar3[2] = uVar7;
          puVar3[3] = uVar8;
          uVar16 = uVar16 + 0x10;
        } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
        if (uVar12 == uVar14) goto LAB_130b71e2522;
      }
      do {
        *(undefined2 *)(lVar2 + uVar12 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar12 * 2);
        uVar12 = uVar12 + 1;
      } while (uVar14 != uVar12);
    }
LAB_130b71e2522:
    *(uint *)(local_94 + -4) = uVar13;
    *(undefined2 *)(local_94 + (ulonglong)uVar13 * 2) = 0;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_68);
  FUN_130b71d0a30(&local_88,&local_98,0);
  lVar2 = local_64;
  if (local_64 == 0) goto LAB_130b71e267d;
  uVar17 = *(uint *)(local_64 + -4);
  uVar14 = (ulonglong)uVar17;
  if ((uVar14 == 0) && (local_84 != 0)) goto LAB_130b71e267d;
  if (local_84 == 0) {
    uVar15 = 0;
    uVar11 = uVar17;
  }
  else {
    uVar15 = *(uint *)(local_84 + -4);
    uVar11 = uVar17 + uVar15;
  }
  cVar9 = FUN_130b71d0060(&local_88);
  if (cVar9 == '\0') goto LAB_130b71e2759;
  if (uVar14 != 0) {
    lVar1 = local_84 + (ulonglong)uVar15 * 2;
    if (uVar17 < 0x10) {
      uVar12 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
      uVar12 = 0;
    }
    else {
      uVar16 = 0;
      uVar12 = (ulonglong)(uVar17 & 0xfffffff8);
      do {
        puVar3 = (undefined4 *)(lVar2 + uVar16);
        uVar6 = puVar3[1];
        uVar7 = puVar3[2];
        uVar8 = puVar3[3];
        puVar4 = (undefined4 *)(lVar1 + uVar16);
        *puVar4 = *puVar3;
        puVar4[1] = uVar6;
        puVar4[2] = uVar7;
        puVar4[3] = uVar8;
        uVar16 = uVar16 + 0x10;
      } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
      if (uVar12 == uVar14) goto LAB_130b71e2672;
    }
    do {
      *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
      uVar12 = uVar12 + 1;
    } while (uVar14 != uVar12);
  }
LAB_130b71e2672:
  *(uint *)(local_84 + -4) = uVar11;
  *(undefined2 *)(local_84 + (ulonglong)uVar11 * 2) = 0;
LAB_130b71e267d:
  FUN_130b71d0a30(&local_48,&local_88,0,0x130b7207768);
  FUN_130b71d0a30(0x130b720bb3c,&local_48,1,0x130b7207778);
  FUN_130b71d0000(&local_48);
  FUN_130b71d0000(&local_58);
  FUN_130b71d0000(&local_78);
  FUN_130b71d0000(&local_a8);
  FUN_130b71d0000(&local_98);
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_88);
  return;
}



/* Address: 130b71e2780 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e2780(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined8 uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  local_88 = 0;
  local_68 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_78 = 0;
  local_58 = 0;
  local_48 = 0;
  local_84 = 0;
  local_64 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_74 = 0;
  local_54 = 0;
  local_44 = 0;
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,10,0x590008,0x130b72033d8,0x520004,0x51,0x520004,0x54,0x520004,0x42,
             0x520004,0x5f,0x520004,0x56,0x520004,0x54,0x520004,0x50,0x520004,0x42,0x520004,0x5f);
  FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7207788);
  uVar10 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,uVar10,0x55,&local_78);
  FUN_130b71d0a30(&local_a8,&local_58);
  lVar2 = local_74;
  if (local_74 != 0) {
    uVar17 = *(uint *)(local_74 + -4);
    uVar14 = (ulonglong)uVar17;
    if ((uVar14 == 0) && (local_a4 != 0)) goto LAB_130b71e2a9d;
    if (local_a4 == 0) {
      uVar12 = 0;
      uVar15 = uVar17;
    }
    else {
      uVar12 = (ulonglong)*(uint *)(local_a4 + -4);
      uVar15 = uVar17 + *(uint *)(local_a4 + -4);
    }
    cVar9 = FUN_130b71d0060(&local_a8);
    if (cVar9 != '\0') {
      if (uVar14 != 0) {
        lVar1 = local_a4 + uVar12 * 2;
        if (uVar17 < 0x10) {
          uVar12 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar12 = 0;
        }
        else {
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar12 == uVar14) goto LAB_130b71e2a92;
        }
        do {
          *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
          uVar12 = uVar12 + 1;
        } while (uVar14 != uVar12);
      }
LAB_130b71e2a92:
      *(uint *)(local_a4 + -4) = uVar15;
      *(undefined2 *)(local_a4 + (ulonglong)uVar15 * 2) = 0;
      goto LAB_130b71e2a9d;
    }
LAB_130b71e2de9:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x461000001f9);
LAB_130b71e2e09:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x463000001f9);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
LAB_130b71e2a9d:
  uVar17 = 0;
  FUN_130b71d0a30(&local_98,&local_a8,0,0x130b72077a8);
  uVar15 = _DAT_130b7203354;
  uVar14 = (ulonglong)_DAT_130b7203354;
  if ((uVar14 != 0) || (local_94 == 0)) {
    if (local_94 != 0) {
      uVar17 = *(uint *)(local_94 + -4);
    }
    uVar13 = _DAT_130b7203354 + uVar17;
    uVar11 = 0x104;
    if ((0x103 < uVar13) &&
       ((0x7ffffffd < uVar13 || (uVar11 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar11)))) {
      uVar11 = 0x7ffffffe;
    }
    cVar9 = FUN_130b71d0060(&local_98,uVar11);
    if (cVar9 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x462000001f9);
      goto LAB_130b71e2de9;
    }
    if (uVar14 != 0) {
      lVar2 = local_94 + (ulonglong)uVar17 * 2;
      if (uVar15 < 0x10) {
        uVar12 = 0;
      }
      else if (lVar2 - 0x130b7203358U < 0x20) {
        uVar12 = 0;
      }
      else {
        uVar16 = 0;
        uVar12 = (ulonglong)(uVar15 & 0xfffffff8);
        do {
          uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
          uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
          uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
          puVar3 = (undefined4 *)(lVar2 + uVar16);
          *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
          puVar3[1] = uVar6;
          puVar3[2] = uVar7;
          puVar3[3] = uVar8;
          uVar16 = uVar16 + 0x10;
        } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
        if (uVar12 == uVar14) goto LAB_130b71e2bd2;
      }
      do {
        *(undefined2 *)(lVar2 + uVar12 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar12 * 2);
        uVar12 = uVar12 + 1;
      } while (uVar14 != uVar12);
    }
LAB_130b71e2bd2:
    *(uint *)(local_94 + -4) = uVar13;
    *(undefined2 *)(local_94 + (ulonglong)uVar13 * 2) = 0;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_68);
  FUN_130b71d0a30(&local_88,&local_98,0);
  lVar2 = local_64;
  if (local_64 == 0) goto LAB_130b71e2d2d;
  uVar17 = *(uint *)(local_64 + -4);
  uVar14 = (ulonglong)uVar17;
  if ((uVar14 == 0) && (local_84 != 0)) goto LAB_130b71e2d2d;
  if (local_84 == 0) {
    uVar15 = 0;
    uVar11 = uVar17;
  }
  else {
    uVar15 = *(uint *)(local_84 + -4);
    uVar11 = uVar17 + uVar15;
  }
  cVar9 = FUN_130b71d0060(&local_88);
  if (cVar9 == '\0') goto LAB_130b71e2e09;
  if (uVar14 != 0) {
    lVar1 = local_84 + (ulonglong)uVar15 * 2;
    if (uVar17 < 0x10) {
      uVar12 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
      uVar12 = 0;
    }
    else {
      uVar16 = 0;
      uVar12 = (ulonglong)(uVar17 & 0xfffffff8);
      do {
        puVar3 = (undefined4 *)(lVar2 + uVar16);
        uVar6 = puVar3[1];
        uVar7 = puVar3[2];
        uVar8 = puVar3[3];
        puVar4 = (undefined4 *)(lVar1 + uVar16);
        *puVar4 = *puVar3;
        puVar4[1] = uVar6;
        puVar4[2] = uVar7;
        puVar4[3] = uVar8;
        uVar16 = uVar16 + 0x10;
      } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar16);
      if (uVar12 == uVar14) goto LAB_130b71e2d22;
    }
    do {
      *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
      uVar12 = uVar12 + 1;
    } while (uVar14 != uVar12);
  }
LAB_130b71e2d22:
  *(uint *)(local_84 + -4) = uVar11;
  *(undefined2 *)(local_84 + (ulonglong)uVar11 * 2) = 0;
LAB_130b71e2d2d:
  FUN_130b71d0a30(&local_48,&local_88,0,0x130b72077c8);
  FUN_130b71d0a30(0x130b720bb3c,&local_48,1,0x130b72077d8);
  FUN_130b71d0000(&local_48);
  FUN_130b71d0000(&local_58);
  FUN_130b71d0000(&local_78);
  FUN_130b71d0000(&local_a8);
  FUN_130b71d0000(&local_98);
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_88);
  return;
}



/* Address: 130b71e2e30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e2e30(longlong param_1,double param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  uVar2 = _DAT_130b720b848;
  local_48 = 0;
  local_58 = 0;
  local_68 = 0;
  local_44 = 0;
  local_54 = 0;
  local_64 = 0;
  if (param_1 == 0) {
LAB_130b71e30b0:
    FUN_130b71d0000(&local_48);
    return;
  }
  uVar6 = (ulonglong)_DAT_130b720b848;
  if (0 < (int)_DAT_130b720b848) {
    uVar4 = 0;
    pcVar5 = (char *)(_DAT_130b720b85c + 0x10);
    do {
      if ((*pcVar5 != '\0') && (*(longlong *)(pcVar5 + -0x10) == param_1)) {
        if (-1 < (int)uVar4) goto LAB_130b71e2f37;
        break;
      }
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 0x11;
    } while (uVar6 != uVar4);
  }
  (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b840,_DAT_130b720b848 + 1,0);
  uVar4 = (ulonglong)(int)uVar2;
  if (uVar4 < _DAT_130b720b848) {
    *(longlong *)(_DAT_130b720b85c + uVar4 * 0x11) = param_1;
    if (_DAT_130b720b848 <= uVar4) goto LAB_130b71e3109;
    *(undefined1 *)(_DAT_130b720b85c + 0x10 + uVar4 * 0x11) = 1;
    uVar6 = (ulonglong)_DAT_130b720b848;
LAB_130b71e2f37:
    if (uVar4 < uVar6) {
      *(double *)(_DAT_130b720b85c + 8 + uVar4 * 0x11) = param_2;
      local_58 = 0;
      local_54 = 0;
      FUN_130b71e20e0(param_1);
      FUN_130b71d0a30(&local_48,0x130b720bb3c,1,0x130b72077e8);
      FUN_130b71d0a30(&local_58,&local_48,0,0x130b72077f8);
      local_68 = 0;
      local_64 = 0;
      FUN_130b71e2780(param_1);
      FUN_130b71d0a30(&local_48,0x130b720bb3c,1,0x130b7207808);
      FUN_130b71d0a30(&local_68,&local_48,0,0x130b7207818);
      if (param_2 <= 0.0) {
        (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_58);
        iVar3 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        if (iVar3 == 0) {
          (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_68);
        }
      }
      else {
        (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_58,param_2);
        iVar3 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        if (iVar3 == 0) {
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_68,param_2);
        }
      }
      FUN_130b71d0000(&local_68);
      FUN_130b71d0000(&local_58);
      goto LAB_130b71e30b0;
    }
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa047c000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0478000001f6);
LAB_130b71e3109:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0479000001f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 130b71e3130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71e3130(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined8 unaff_RBX;
  undefined7 uVar8;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_88 = 0;
  local_64 = 0;
  local_74 = 0;
  local_84 = 0;
  uVar8 = (undefined7)((ulonglong)unaff_RBX >> 8);
  if (0 < (int)_DAT_130b720b848) {
    uVar6 = 0;
    pcVar7 = (char *)(_DAT_130b720b85c + 0x10);
    do {
      if ((*pcVar7 != '\0') && (*(longlong *)(pcVar7 + -0x10) == param_1)) {
        if (-1 < (int)(uint)uVar6) {
          if (_DAT_130b720b848 <= (uint)uVar6) {
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x140493000001f6);
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          uVar6 = CONCAT71(uVar8,1);
          *param_2 = *(undefined8 *)(pcVar7 + -8);
          goto LAB_130b71e32e1;
        }
        break;
      }
      uVar6 = uVar6 + 1;
      pcVar7 = pcVar7 + 0x11;
    } while (_DAT_130b720b848 != uVar6);
  }
  local_74 = 0;
  FUN_130b71e20e0(param_1);
  FUN_130b71d0a30(&local_68,0x130b720bb3c,1,0x130b7207828);
  FUN_130b71d0a30(&local_78,&local_68,0,0x130b7207838);
  cVar4 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_78);
  if (cVar4 == '\0') {
    iVar5 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
    if (iVar5 == 0) {
      local_88 = 0;
      local_84 = 0;
      FUN_130b71e2780(param_1);
      FUN_130b71d0a30(&local_68,0x130b720bb3c,1,0x130b7207848);
      FUN_130b71d0a30(&local_88,&local_68,0,0x130b7207858);
      cVar4 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_88);
      if (cVar4 != '\0') {
        (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_88);
        *param_2 = _DAT_130b720bb48;
        FUN_130b71e2e30(param_1);
        uVar3 = _DAT_130b720b7b0;
        uVar1 = *param_2;
        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_68);
        (*(code *)0x7ff63a0e49f0)
                  (0x130b53f81d8,0xd,4,0x590008,0x130b7203430,0x590008,&local_68,0x520004,uVar3,
                   0x580007,uVar1);
        FUN_130b71d0000(&local_88);
        goto LAB_130b71e32b6;
      }
      FUN_130b71d0000(&local_88);
    }
    *param_2 = 0;
    FUN_130b71d0000(&local_78);
    uVar6 = 0;
  }
  else {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_78);
    *param_2 = _DAT_130b720bb48;
    FUN_130b71e2e30(param_1);
LAB_130b71e32b6:
    uVar6 = CONCAT71(uVar8,1);
    FUN_130b71d0000(&local_78);
  }
LAB_130b71e32e1:
  FUN_130b71d0000(&local_68);
  return uVar6 & 0xffffffff;
}



/* Address: 130b71e3490 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e3490(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined4 local_38;
  undefined8 local_34;
  
  local_38 = 0;
  local_34 = 0;
  if (0 < (int)_DAT_130b720b848) {
    uVar4 = 0;
    pcVar3 = (char *)(_DAT_130b720b85c + 0x10);
    do {
      if ((*pcVar3 != '\0') && (*(longlong *)(pcVar3 + -0x10) == param_1)) {
        if (-1 < (int)(uint)uVar4) {
          if (_DAT_130b720b848 <= (uint)uVar4) {
            (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04b4000001f6);
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          *pcVar3 = '\0';
        }
        break;
      }
      uVar4 = uVar4 + 1;
      pcVar3 = pcVar3 + 0x11;
    } while (_DAT_130b720b848 != uVar4);
  }
  FUN_130b71e20e0(param_1);
  FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b7207868);
  (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_38);
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar2 == 0) {
    FUN_130b71e2780(param_1);
    FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b7207878);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_38);
  }
  FUN_130b71d0000(&local_38);
  return;
}



/* Address: 130b71e3600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e3600(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  uVar2 = _DAT_130b720b888;
  uVar5 = (ulonglong)_DAT_130b720b888;
  if (0 < (int)_DAT_130b720b888) {
    uVar3 = 0;
    pcVar4 = (char *)(_DAT_130b720b89c + 0x10);
    do {
      if ((*pcVar4 != '\0') && (*(longlong *)(pcVar4 + -0x10) == param_1)) {
        if (-1 < (int)uVar3) goto LAB_130b71e36af;
        break;
      }
      uVar3 = uVar3 + 1;
      pcVar4 = pcVar4 + 0x11;
    } while (uVar5 != uVar3);
  }
  (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b880,_DAT_130b720b888 + 1,0);
  uVar3 = (ulonglong)(int)uVar2;
  if (uVar3 < _DAT_130b720b888) {
    *(longlong *)(_DAT_130b720b89c + uVar3 * 0x11) = param_1;
    if (_DAT_130b720b888 <= uVar3) goto LAB_130b71e3716;
    *(undefined1 *)(_DAT_130b720b89c + 0x10 + uVar3 * 0x11) = 1;
    uVar5 = (ulonglong)_DAT_130b720b888;
LAB_130b71e36af:
    if (uVar3 < uVar5) {
      *(undefined8 *)(_DAT_130b720b89c + 8 + uVar3 * 0x11) = param_2;
      return;
    }
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04e6000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04e3000001f6);
LAB_130b71e3716:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04e4000001f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 130b71e3740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e3740(longlong param_1)

{
  code *pcVar1;
  char *pcVar2;
  ulonglong uVar3;
  
  if (0 < (int)_DAT_130b720b888) {
    uVar3 = 0;
    pcVar2 = (char *)(_DAT_130b720b89c + 0x10);
    do {
      if ((*pcVar2 != '\0') && (*(longlong *)(pcVar2 + -0x10) == param_1)) {
        if ((int)(uint)uVar3 < 0) {
          return;
        }
        if ((uint)uVar3 < _DAT_130b720b888) {
          *pcVar2 = '\0';
          return;
        }
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04ed000001f6);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 0x11;
    } while (_DAT_130b720b888 != uVar3);
  }
  return;
}



/* Address: 130b71e37c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e37c0(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined4 local_90;
  undefined8 local_8c;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_80 = 0;
  local_a0 = 0;
  local_7c = 0;
  local_9c = 0;
  *param_2 = 0;
  *param_3 = 0;
  local_90 = 0;
  local_8c = 0;
  FUN_130b71e17c0(0x130b7203458,param_1);
  FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b72078e8);
  FUN_130b71d0a30(&local_90,&local_80,0,0x130b72078f8);
  cVar1 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_90);
  if (cVar1 == '\0') {
    iVar2 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
    if (iVar2 == 0) {
      local_a0 = 0;
      local_50 = 0;
      local_70 = 0;
      local_60 = 0;
      local_9c = 0;
      local_4c = 0;
      local_6c = 0;
      local_5c = 0;
      (*(code *)0x7ff63a0e49f0)
                (0x130b53f81d8,0xd8,5,0x590008,0x130b7203340,0x520004,0x52,0x520004,0x45,0x520004,
                 0x46,0x520004,0x42);
      FUN_130b71d0a30(&local_70,0x130b720bb3c,1,0x130b7207888);
      FUN_130b71e17c0(&local_70,param_1);
      FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7207898);
      FUN_130b71d0a30(&local_60,&local_50,0,0x130b72078a8);
      FUN_130b71d0a30(0x130b720bb3c,&local_60,1,0x130b72078b8);
      FUN_130b71d0000(&local_60);
      FUN_130b71d0000(&local_70);
      FUN_130b71d0000(&local_50);
      FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b7207908);
      FUN_130b71d0a30(&local_a0,&local_80,0,0x130b7207918);
      cVar1 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_a0);
      if (cVar1 != '\0') {
        (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_a0);
        *param_2 = _DAT_130b720bb48;
        (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_90);
      }
      FUN_130b71d0000(&local_a0);
    }
  }
  else {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_90);
    *param_2 = _DAT_130b720bb48;
  }
  FUN_130b71e3130(param_1,param_3);
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_80);
  return;
}



/* Address: 130b71e3b50 */

void FUN_130b71e3b50(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_80 = 0;
  local_7c = 0;
  local_90 = 0;
  local_88 = 0;
  FUN_130b71e17c0(0x130b7203458,param_1);
  FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b7207928);
  FUN_130b71d0a30(&local_90,&local_80,0,0x130b7207938);
  cVar1 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_90);
  if (cVar1 != '\0') {
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_90);
  }
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar2 == 0) {
    local_50 = 0;
    local_60 = 0;
    local_70 = 0;
    local_4c = 0;
    local_5c = 0;
    local_6c = 0;
    (*(code *)0x7ff63a0e49f0)
              (0x130b53f81d8,0xd8,5,0x590008,0x130b7203340,0x520004,0x52,0x520004,0x45,0x520004,0x46
               ,0x520004,0x42);
    FUN_130b71d0a30(&local_60,0x130b720bb3c,1,0x130b7207888);
    FUN_130b71e17c0(&local_60,param_1);
    FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7207898);
    FUN_130b71d0a30(&local_70,&local_50,0,0x130b72078a8);
    FUN_130b71d0a30(0x130b720bb3c,&local_70,1,0x130b72078b8);
    FUN_130b71d0000(&local_70);
    FUN_130b71d0000(&local_60);
    FUN_130b71d0000(&local_50);
    FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b7207948);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_80);
  }
  FUN_130b71e3490(param_1);
  FUN_130b71e3740(param_1);
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_80);
  return;
}



/* Address: 130b71e3e10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e3e10(void)

{
  undefined8 uVar1;
  code *pcVar2;
  char cVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)_DAT_130b720b848;
  if (0 < (int)_DAT_130b720b848) {
    lVar5 = 0x10;
    uVar6 = 0;
    do {
      if ((uVar4 & 0xffffffff) <= uVar6) {
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xe0520000001f6);
        goto LAB_130b71e3f4b;
      }
      if (*(char *)(_DAT_130b720b85c + lVar5) != '\0') {
        uVar1 = *(undefined8 *)(_DAT_130b720b85c + -0x10 + lVar5);
        cVar3 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar1);
        if (cVar3 == '\0') {
          FUN_130b71e3b50(uVar1);
        }
      }
      uVar4 = (ulonglong)(int)_DAT_130b720b848;
      uVar6 = uVar6 + 1;
      lVar5 = lVar5 + 0x11;
    } while ((longlong)uVar6 < (longlong)uVar4);
  }
  uVar4 = (ulonglong)_DAT_130b720b888;
  if (0 < (int)_DAT_130b720b888) {
    lVar5 = 0x10;
    uVar6 = 0;
    do {
      if ((uVar4 & 0xffffffff) <= uVar6) {
LAB_130b71e3f4b:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xe0529000001f6);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if (*(char *)(_DAT_130b720b89c + lVar5) != '\0') {
        uVar1 = *(undefined8 *)(_DAT_130b720b89c + -0x10 + lVar5);
        cVar3 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar1);
        if (cVar3 == '\0') {
          FUN_130b71e3b50(uVar1);
        }
      }
      uVar4 = (ulonglong)(int)_DAT_130b720b888;
      uVar6 = uVar6 + 1;
      lVar5 = lVar5 + 0x11;
    } while ((longlong)uVar6 < (longlong)uVar4);
  }
  return;
}



/* Address: 130b71e3f70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e3f70(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  longlong local_dc;
  undefined4 local_d0;
  longlong local_cc;
  undefined4 local_c0;
  longlong local_bc;
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
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_90 = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_70 = 0;
  local_c0 = 0;
  local_d0 = 0;
  local_e0 = 0;
  local_f0 = 0;
  local_80 = 0;
  local_60 = 0;
  local_50 = 0;
  local_8c = 0;
  local_9c = 0;
  local_ac = 0;
  local_6c = 0;
  local_bc = 0;
  local_cc = 0;
  local_dc = 0;
  local_ec = 0;
  local_7c = 0;
  local_5c = 0;
  local_4c = 0;
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,8,0x590008,0x130b72034a0,0x520004,0x51,0x520004,0x54,0x520004,0x32,
             0x520004,0x5f,0x520004,0x57,0x520004,0x44,0x520004,0x5f);
  FUN_130b71d0a30(&local_60,0x130b720bb3c,1,0x130b7207968);
  uVar10 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,uVar10,0x55,&local_80);
  FUN_130b71d0a30(&local_f0,&local_60,0);
  lVar2 = local_7c;
  if (local_7c == 0) {
LAB_130b71e42bd:
    uVar11 = 0;
    FUN_130b71d0a30(&local_e0,&local_f0,0);
    uVar17 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_dc == 0)) {
      if (local_dc != 0) {
        uVar11 = (ulonglong)*(uint *)(local_dc + -4);
      }
      uVar14 = _DAT_130b7203354 + (int)uVar11;
      cVar9 = FUN_130b71d0060(&local_e0);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar2 = local_dc + uVar11 * 2;
          if ((uVar17 < 0x10) || (lVar2 - 0x130b7203358U < 0x20)) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71e43b2;
          }
          do {
            *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e43b2:
        *(uint *)(local_dc + -4) = uVar14;
        *(undefined2 *)(local_dc + (ulonglong)uVar14 * 2) = 0;
        goto LAB_130b71e43bd;
      }
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x640583000001f9);
LAB_130b71e4b33:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x700583000001f9);
LAB_130b71e4b53:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x110584000001f9);
      goto LAB_130b71e4b73;
    }
LAB_130b71e43bd:
    FUN_130b71d0a30(&local_d0,&local_e0,0);
    lVar2 = _DAT_130b720bb2c;
    if (_DAT_130b720bb2c != 0) {
      uVar17 = *(uint *)(_DAT_130b720bb2c + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_cc != 0)) goto LAB_130b71e454d;
      if (local_cc == 0) {
        uVar14 = 0;
        uVar15 = uVar17;
      }
      else {
        uVar14 = *(uint *)(local_cc + -4);
        uVar15 = uVar17 + uVar14;
      }
      cVar9 = FUN_130b71d0060(&local_d0);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar1 = local_cc + (ulonglong)uVar14 * 2;
          if (uVar17 < 0x10) {
            uVar11 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar1 + uVar16);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71e4542;
          }
          do {
            *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e4542:
        *(uint *)(local_cc + -4) = uVar15;
        *(undefined2 *)(local_cc + (ulonglong)uVar15 * 2) = 0;
        goto LAB_130b71e454d;
      }
      goto LAB_130b71e4b93;
    }
LAB_130b71e454d:
    uVar17 = 0;
    FUN_130b71d0a30(&local_c0,&local_d0,0);
    uVar14 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_bc == 0)) {
      if (local_bc != 0) {
        uVar17 = *(uint *)(local_bc + -4);
      }
      uVar15 = _DAT_130b7203354 + uVar17;
      cVar9 = FUN_130b71d0060(&local_c0);
      if (cVar9 == '\0') goto LAB_130b71e4b33;
      if (uVar13 != 0) {
        lVar2 = local_bc + (ulonglong)uVar17 * 2;
        if ((uVar14 < 0x10) || (lVar2 - 0x130b7203358U < 0x20)) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
            uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
            uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e4632;
        }
        do {
          *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e4632:
      *(uint *)(local_bc + -4) = uVar15;
      *(undefined2 *)(local_bc + (ulonglong)uVar15 * 2) = 0;
    }
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(longlong)_DAT_130b720b3f0,0x52,&local_70);
    FUN_130b71d0a30(&local_b0,&local_c0);
    lVar2 = local_6c;
    if (local_6c == 0) {
LAB_130b71e47ed:
      uVar17 = 0;
      FUN_130b71d0a30(&local_a0,&local_b0,0,0x130b72079c8);
      uVar14 = _DAT_130b7203354;
      uVar13 = (ulonglong)_DAT_130b7203354;
      if ((uVar13 != 0) || (local_9c == 0)) {
        if (local_9c != 0) {
          uVar17 = *(uint *)(local_9c + -4);
        }
        uVar12 = _DAT_130b7203354 + uVar17;
        uVar15 = 0x104;
        if ((0x103 < uVar12) &&
           ((0x7ffffffd < uVar12 || (uVar15 = (uVar12 >> 2) + uVar12, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar9 = FUN_130b71d0060(&local_a0,uVar15);
        if (cVar9 == '\0') goto LAB_130b71e4b53;
        if (uVar13 != 0) {
          lVar2 = local_9c + (ulonglong)uVar17 * 2;
          if (uVar14 < 0x10) {
            uVar11 = 0;
          }
          else if (lVar2 - 0x130b7203358U < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71e4912;
          }
          do {
            *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e4912:
        *(uint *)(local_9c + -4) = uVar12;
        *(undefined2 *)(local_9c + (ulonglong)uVar12 * 2) = 0;
      }
      FUN_130b71d0a30(&local_90,&local_a0,0);
      lVar2 = *(longlong *)(param_1 + 4);
      if (lVar2 == 0) goto LAB_130b71e4a4d;
      uVar17 = *(uint *)(lVar2 + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_8c != 0)) goto LAB_130b71e4a4d;
      if (local_8c == 0) {
        uVar11 = 0;
        uVar14 = uVar17;
      }
      else {
        uVar11 = (ulonglong)*(uint *)(local_8c + -4);
        uVar14 = uVar17 + *(uint *)(local_8c + -4);
      }
      cVar9 = FUN_130b71d0060(&local_90);
      if (cVar9 == '\0') goto LAB_130b71e4bd3;
      if (uVar13 != 0) {
        lVar1 = local_8c + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e4a42;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e4a42:
      *(uint *)(local_8c + -4) = uVar14;
      *(undefined2 *)(local_8c + (ulonglong)uVar14 * 2) = 0;
LAB_130b71e4a4d:
      FUN_130b71d0a30(&local_50,&local_90,0,0x130b72079e8);
      FUN_130b71d0a30(0x130b720bb3c,&local_50,1,0x130b72079f8);
      FUN_130b71d0000(&local_50);
      FUN_130b71d0000(&local_60);
      FUN_130b71d0000(&local_80);
      FUN_130b71d0000(&local_f0);
      FUN_130b71d0000(&local_e0);
      FUN_130b71d0000(&local_d0);
      FUN_130b71d0000(&local_c0);
      FUN_130b71d0000(&local_70);
      FUN_130b71d0000(&local_b0);
      FUN_130b71d0000(&local_a0);
      FUN_130b71d0000(&local_90);
      return;
    }
    uVar17 = *(uint *)(local_6c + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_ac != 0)) goto LAB_130b71e47ed;
    if (local_ac == 0) {
      uVar11 = 0;
      uVar14 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_ac + -4);
      uVar14 = uVar17 + *(uint *)(local_ac + -4);
    }
    cVar9 = FUN_130b71d0060(&local_b0);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_ac + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e47e2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e47e2:
      *(uint *)(local_ac + -4) = uVar14;
      *(undefined2 *)(local_ac + (ulonglong)uVar14 * 2) = 0;
      goto LAB_130b71e47ed;
    }
  }
  else {
    uVar17 = *(uint *)(local_7c + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_ec != 0)) goto LAB_130b71e42bd;
    if (local_ec == 0) {
      uVar11 = 0;
      uVar14 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_ec + -4);
      uVar14 = uVar17 + *(uint *)(local_ec + -4);
    }
    cVar9 = FUN_130b71d0060(&local_f0);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_ec + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71e42b2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71e42b2:
      *(uint *)(local_ec + -4) = uVar14;
      *(undefined2 *)(local_ec + (ulonglong)uVar14 * 2) = 0;
      goto LAB_130b71e42bd;
    }
LAB_130b71e4b73:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x3a0583000001f9);
LAB_130b71e4b93:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x680583000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x740583000001f9);
LAB_130b71e4bd3:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x150584000001f9);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



/* Address: 130b71e4c00 */

void FUN_130b71e4c00(void)

{
  int iVar1;
  undefined4 local_40;
  undefined8 local_3c;
  
  local_40 = 0;
  local_3c = 0;
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar1 == 0) {
    FUN_130b71e3f70(0x130b72034c0);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a08);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b72034e0);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a18);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b7203500);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a28);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b7203520);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a38);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b7203540);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a48);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b7203560);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a58);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b7203580);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a68);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b72035a0);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a78);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
    FUN_130b71e3f70(0x130b72035c0);
    FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b7207a88);
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_40);
  }
  FUN_130b71d0000(&local_40);
  return;
}



/* Address: 130b71e4e30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e4e30(void)

{
  double dVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined4 local_78;
  undefined8 local_74;
  
  local_78 = 0;
  local_74 = 0;
  iVar7 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar7 == 0) {
    if (DAT_130b720b8c0 == '\0') {
      FUN_130b71e4c00();
    }
    else {
      FUN_130b71e3f70(0x130b72034c0);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207a98);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,_DAT_130b72013e0);
      dVar1 = (double)_DAT_130b720b8cd;
      FUN_130b71e3f70(0x130b72034e0);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207aa8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,dVar1);
      dVar1 = (double)_DAT_130b720b8d5;
      FUN_130b71e3f70(0x130b7203500);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207ab8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,dVar1);
      uVar6 = _DAT_130b720b8d9;
      FUN_130b71e3f70(0x130b7203520);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207ac8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,uVar6);
      uVar6 = _DAT_130b720b8e1;
      FUN_130b71e3f70(0x130b7203540);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207ad8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,uVar6);
      dVar1 = (double)_DAT_130b720b8e9;
      FUN_130b71e3f70(0x130b7203560);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207ae8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,dVar1);
      dVar5 = dRam00000130b7201408;
      dVar1 = _DAT_130b7201400;
      uVar4 = uRam00000130b72013f4;
      uVar3 = _DAT_130b72013f0;
      dVar9 = (double)CONCAT44(_DAT_130b72013f0,(int)_DAT_130b720b8f1) - _DAT_130b7201400;
      dVar10 = (double)CONCAT44(uRam00000130b72013f4,(int)((ulonglong)_DAT_130b720b8f1 >> 0x20)) -
               dRam00000130b7201408;
      FUN_130b71e3f70(0x130b7203580);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207af8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,dVar10 + dVar9);
      uVar2 = (ulonglong)_DAT_130b720b8f9 >> 0x20;
      uVar8 = (undefined4)_DAT_130b720b8f9;
      FUN_130b71e3f70(0x130b72035a0);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207b08);
      (*(code *)0x7ff63a0edc90)
                (0x130b53f81d8,&local_78,
                 ((double)CONCAT44(uVar4,(int)uVar2) - dVar5) +
                 ((double)CONCAT44(uVar3,uVar8) - dVar1));
      dVar1 = (double)_DAT_130b720b901;
      FUN_130b71e3f70(0x130b72035c0);
      FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207b18);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_78,dVar1);
    }
  }
  FUN_130b71d0000(&local_78);
  return;
}



/* Address: 130b71e5190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71e5190(undefined8 param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  int iVar11;
  longlong lVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar15;
  undefined8 in_stack_ffffffffffffff18;
  undefined4 uVar16;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  local_b8 = 0;
  local_b4 = 0;
  if (DAT_130b720b8c0 != '\0') {
    cVar10 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
    if (cVar10 != '\0') {
      (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
      FUN_130b71d0a30(&local_b8,0x130b720bb3c,1,0x130b7207b58);
      if (local_b4 != _DAT_130b720b8c5) {
        uVar14 = 0;
        if ((local_b4 == 0) || (_DAT_130b720b8c5 == 0)) goto LAB_130b71e5714;
        uVar3 = *(uint *)(local_b4 + -4);
        uVar4 = *(uint *)(_DAT_130b720b8c5 + -4);
        uVar5 = uVar4;
        if (uVar3 < uVar4) {
          uVar5 = uVar3;
        }
        iVar11 = uVar3 - uVar4;
        if (uVar5 != 0) {
          uVar14 = 1;
          do {
            uVar1 = *(ushort *)(local_b4 + -2 + uVar14 * 2);
            uVar2 = *(ushort *)(_DAT_130b720b8c5 + -2 + uVar14 * 2);
            if (uVar5 <= uVar14) break;
            uVar14 = uVar14 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar11 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar11 != 0) goto LAB_130b71e5712;
      }
      lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
      if (lVar12 == _DAT_130b720b8cd) {
        if (0 < CONCAT44(_DAT_130b720b905,_DAT_130b720b901)) {
          lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd);
          if (lVar12 != CONCAT44(_DAT_130b720b905,_DAT_130b720b901)) goto LAB_130b71e5712;
        }
        uVar9 = _DAT_130b720b8e1;
        uVar8 = _DAT_130b720b8d9;
        local_a8 = 0;
        local_a4 = 0;
        uVar6 = CONCAT44(_DAT_130b720b8dd,_DAT_130b720b8d9);
        uVar7 = CONCAT44(_DAT_130b720b8e5,_DAT_130b720b8e1);
        FUN_130b71e17c0(0x130b7203458,param_1);
        FUN_130b71d0a30(&local_a8,0x130b720bb3c,1,0x130b72078c8);
        (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_a8,uVar8);
        iVar11 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        if (iVar11 == 0) {
          local_78 = 0;
          local_98 = 0;
          local_88 = 0;
          local_74 = 0;
          local_94 = 0;
          local_84 = 0;
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd8,5,0x590008,0x130b7203340,0x520004,CONCAT44(uVar15,0x52),
                     0x520004,0x45,0x520004,CONCAT44(uVar16,0x46),0x520004,0x42);
          FUN_130b71d0a30(&local_98,0x130b720bb3c,1,0x130b7207888);
          FUN_130b71e17c0(&local_98,param_1);
          FUN_130b71d0a30(&local_78,0x130b720bb3c,1,0x130b7207898);
          FUN_130b71d0a30(&local_88,&local_78,0,0x130b72078a8);
          FUN_130b71d0a30(0x130b720bb3c,&local_88,1,0x130b72078b8);
          FUN_130b71d0000(&local_88);
          FUN_130b71d0000(&local_98);
          FUN_130b71d0000(&local_78);
          FUN_130b71d0a30(&local_a8,0x130b720bb3c,1,0x130b72078d8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_a8,uVar8);
        }
        puVar13 = &local_a8;
        FUN_130b71e2e30(param_1,uVar9);
        FUN_130b71d0000(&local_a8);
        uVar15 = _DAT_130b720b7b0;
        if (param_2 != '\0') {
          puVar13 = (undefined4 *)0x130b53f81d8;
          (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_b8);
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd,6,0x590008,0x130b7203620,0x590008,&local_b8,0x520004,uVar15,
                     0x580007,uVar6,0x520004,uVar15,0x580007,uVar7);
        }
        DAT_130b720b8c0 = '\0';
        FUN_130b71d0a30(0x130b720b8c1,0x130b7201870,0,0x130b7207b28);
        _DAT_130b720b8fd = 0;
        _DAT_130b720b901 = 0;
        _DAT_130b720b8f5 = 0;
        _DAT_130b720b905 = 0;
        _DAT_130b720b8ed = 0;
        _DAT_130b720b8e5 = 0;
        _DAT_130b720b8e9 = 0;
        _DAT_130b720b8dd = 0;
        _DAT_130b720b8e1 = 0;
        _DAT_130b720b8d5 = 0;
        _DAT_130b720b8d9 = 0;
        _DAT_130b720b8cd = 0;
        FUN_130b71e4c00();
        uVar14 = CONCAT71((int7)((ulonglong)puVar13 >> 8),1);
        goto LAB_130b71e5714;
      }
    }
  }
LAB_130b71e5712:
  uVar14 = 0;
LAB_130b71e5714:
  FUN_130b71d0000(&local_b8);
  return uVar14 & 0xffffffff;
}



/* Address: 130b71e5750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71e5750(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  int iVar12;
  longlong lVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined4 local_50;
  longlong local_4c;
  
  if (DAT_130b720b8c0 != '\0') {
    local_50 = 0;
    local_4c = 0;
    iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
    if (iVar8 + -1 < 0) {
      FUN_130b71d0000(&local_50);
    }
    else {
      lVar15 = -1;
      lVar13 = 0;
      iVar8 = iVar8 + -1;
      do {
        lVar9 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
        if ((lVar9 != 0) && (cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar9), cVar7 != '\0'))
        {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7207b48);
          if (local_4c == _DAT_130b720b8c5) {
LAB_130b71e58f8:
            lVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if (lVar10 == _DAT_130b720b8cd) {
              if ((0 < _DAT_130b720b901) &&
                 (lVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd), lVar10 == _DAT_130b720b901)
                 ) break;
              lVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xe);
              if (lVar15 < lVar10) {
                lVar13 = lVar9;
                lVar15 = lVar10;
              }
            }
          }
          else if ((local_4c != 0) && (_DAT_130b720b8c5 != 0)) {
            uVar3 = *(uint *)(local_4c + -4);
            uVar4 = *(uint *)(_DAT_130b720b8c5 + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar12 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar14 = 1;
              do {
                uVar1 = *(ushort *)(local_4c + -2 + uVar14 * 2);
                uVar2 = *(ushort *)(_DAT_130b720b8c5 + -2 + uVar14 * 2);
                if (uVar6 <= uVar14) break;
                uVar14 = uVar14 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar12 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar12 == 0) goto LAB_130b71e58f8;
          }
        }
        bVar5 = 0 < iVar8;
        lVar9 = lVar13;
        iVar8 = iVar8 + -1;
      } while (bVar5);
      FUN_130b71d0000(&local_50);
      if (lVar9 != 0) {
        uVar11 = FUN_130b71e5190(lVar9,1);
        return uVar11;
      }
    }
  }
  return 0;
}



/* Address: 130b71e59b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e59b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    char param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined8 local_74;
  
  uVar1 = _DAT_130b720b7b0;
  local_98 = 0;
  local_a8 = 0;
  local_78 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_74 = 0;
  local_88 = 0;
  local_80 = 0;
  FUN_130b71dbd30(&local_88,&DAT_130b720b470,&DAT_130b720b560);
  FUN_130b71d0a30(&local_78,&local_88,0,0x130b7206928);
  FUN_130b71d0000(&local_88);
  FUN_130b71d0a30(0x130b720bb3c,&local_78,1,0x130b7206938);
  FUN_130b71d0000(&local_78);
  FUN_130b71d0a30(&local_a8,0x130b720bb3c,1,0x130b7207c18);
  uVar2 = 0x130b7203748;
  if (param_5 == '\0') {
    uVar2 = 0x130b7203778;
  }
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_2,0x56,&local_98);
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd,0xb,0x590008,0x130b7203720,0x590008,param_1,0x590008,&local_98,
             0x590008,uVar2,0x520004,param_7,0x530014,param_6,0x590008,&local_a8,0x520004,uVar1,
             0x580007,param_3,0x520004,uVar1,0x580007,param_4);
  FUN_130b71d0000(&local_a8);
  FUN_130b71d0000(&local_98);
  return;
}



/* Address: 130b71e5c50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71e5c50(undefined4 *param_1,double param_2,double param_3)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  double dVar4;
  char cVar5;
  char cVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined8 in_stack_fffffffffffffe58;
  undefined8 uVar19;
  uint uVar20;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_110;
  undefined8 local_10c;
  undefined8 local_100;
  undefined1 local_f8 [184];
  
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  local_110 = 0;
  local_120 = 0;
  local_10c = 0;
  local_11c = 0;
  if (param_1 == (undefined4 *)0x0) {
LAB_130b71e5fe0:
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_110);
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,2,0x590008,0x130b72037c0,0x590008,&local_110);
  }
  else {
    cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
    if (cVar5 == '\0') goto LAB_130b71e5fe0;
    local_120 = 0;
    local_11c = 0;
    (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
    FUN_130b71d0a30(&local_110,0x130b720bb3c,1,0x130b7207c28);
    FUN_130b71d0a30(&local_120,&local_110,0,0x130b7207c38);
    uVar8 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
    lVar9 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
    if (param_3 <= 0.0) goto LAB_130b71e5ed7;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,0x10);
    dVar14 = _DAT_130b720bb48;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,1);
    dVar13 = _DAT_130b720bb48;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,4);
    dVar15 = _DAT_130b720bb48;
    if (((0.0 < dVar14) && (0.0 < dVar13)) && (0.0 < _DAT_130b720bb48)) {
      lVar10 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x1f);
      lVar11 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x20);
      dVar1 = (double)lVar10;
      if ((double)lVar10 <= (double)lVar11) {
        dVar1 = (double)lVar11;
      }
      dVar14 = dVar14 * dVar1;
      if (lVar9 == 1) {
        if (dVar15 - dVar14 <= param_3) goto LAB_130b71e64e1;
      }
      else if ((lVar9 != 0) || (param_3 <= dVar13 + dVar14)) goto LAB_130b71e64e1;
LAB_130b71e5ed7:
      uVar16 = 0;
      _DAT_130b720b6ed = 0;
      _DAT_130b720b6e5 = uVar8;
      uVar12 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x32);
      if (((uVar12 & 1) != 0) || (uVar16 = 1, (uVar12 & 2) != 0)) {
        _DAT_130b720b6f5 = uVar16;
      }
      uVar16 = 0;
      uVar17 = 0;
      if ((param_2 <= 0.0) ||
         (uVar16 = SUB84(param_2,0), uVar17 = (int)((ulonglong)param_2 >> 0x20),
         (longlong)param_2 == -0x8000000000000000)) {
        dVar14 = (double)CONCAT44(uVar17,uVar16);
      }
      else {
        dVar14 = (double)(longlong)param_2;
        uVar12 = 0xb;
        if (_DAT_130b720b7b0 < 0xb) {
          uVar12 = (ulonglong)_DAT_130b720b7b0;
        }
        dVar14 = (double)(longlong)
                         ((param_2 - dVar14) * *(double *)(&DAT_130b7201710 + uVar12 * 8) +
                         _DAT_130b7201410) / *(double *)(&DAT_130b7201710 + uVar12 * 8) + dVar14;
      }
      dVar13 = 0.0;
      if ((0.0 < param_3) && (dVar13 = param_3, (longlong)param_3 != -0x8000000000000000)) {
        dVar13 = (double)(longlong)param_3;
        uVar12 = 0xb;
        if (_DAT_130b720b7b0 < 0xb) {
          uVar12 = (ulonglong)_DAT_130b720b7b0;
        }
        dVar13 = (double)(longlong)
                         ((param_3 - dVar13) * *(double *)(&DAT_130b7201710 + uVar12 * 8) +
                         _DAT_130b7201410) / *(double *)(&DAT_130b7201710 + uVar12 * 8) + dVar13;
      }
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,0x1b);
      uVar16 = SUB84(_DAT_130b720b7a0,0);
      uVar17 = (undefined4)((ulonglong)_DAT_130b720b7a0 >> 0x20);
      if (_DAT_130b720b7a0 <= _DAT_130b720bb48) {
        uVar16 = SUB84(_DAT_130b720bb48,0);
        uVar17 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
      }
      (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
      dVar15 = _DAT_130b720bb48;
      if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
        dVar15 = (double)(longlong)_DAT_130b720bb48;
        uVar12 = 0xb;
        if (_DAT_130b720b7b0 < 0xb) {
          uVar12 = (ulonglong)_DAT_130b720b7b0;
        }
        dVar15 = (double)(longlong)
                         ((_DAT_130b720bb48 - dVar15) * *(double *)(&DAT_130b7201710 + uVar12 * 8) +
                         *(double *)((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b7201418)) /
                 *(double *)(&DAT_130b7201710 + uVar12 * 8) + dVar15;
      }
      dVar1 = (double)CONCAT44(uVar17,uVar16) * _DAT_130b7201440;
      if ((double)((ulonglong)(dVar15 - dVar14) & _DAT_130b7201430) <= dVar1) {
LAB_130b71e6224:
        FUN_130b71e2e30(param_1,dVar13);
      }
      else {
        _DAT_130b720bb10 = 0;
        _DAT_130b720bb80 = 0;
        DAT_130b720bb88 = 0;
        cVar5 = FUN_130b71dd110(0x130b720b450,param_1,dVar14);
        iVar18 = _DAT_130b720b560;
        if ((cVar5 != '\0') && (0xfffffffc < _DAT_130b720b560 - 0x271bU)) goto LAB_130b71e6224;
        uVar20 = _DAT_130b720b560 - 0x2714;
        local_100 = CONCAT44(local_100._4_4_,_DAT_130b720bb10);
        if (0x15 < uVar20) {
LAB_130b71e672f:
          uVar8 = 0x130b72039a0;
LAB_130b71e68c2:
          uVar19 = CONCAT44(uVar7,(undefined4)local_100);
LAB_130b71e68c6:
          FUN_130b71e59b0(uVar8,param_1,dVar14,dVar13,cVar5,iVar18,uVar19);
          goto LAB_130b71e68e6;
        }
        if ((0x30101U >> (uVar20 & 0x1f) & 1) == 0) {
          if ((uVar20 == 0x15) &&
             (cVar6 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar6 != '\0')) {
            (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
            dVar15 = _DAT_130b720bb48;
            if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
              dVar15 = (double)(longlong)_DAT_130b720bb48;
              uVar12 = 0xb;
              if (_DAT_130b720b7b0 < 0xb) {
                uVar12 = (ulonglong)_DAT_130b720b7b0;
              }
              dVar15 = (double)(longlong)
                               ((_DAT_130b720bb48 - dVar15) *
                                *(double *)(&DAT_130b7201710 + uVar12 * 8) +
                               *(double *)((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b7201418))
                       / *(double *)(&DAT_130b7201710 + uVar12 * 8) + dVar15;
            }
            if ((double)((ulonglong)(dVar15 - dVar14) & _DAT_130b7201430) <= dVar1)
            goto LAB_130b71e6224;
          }
          goto LAB_130b71e672f;
        }
        cVar6 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
        if (cVar6 == '\0') goto LAB_130b71e672f;
        if (param_3 <= 0.0) goto LAB_130b71e63c0;
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,0x10);
        dVar15 = _DAT_130b720bb48;
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,1);
        dVar1 = _DAT_130b720bb48;
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,4);
        dVar4 = _DAT_130b720bb48;
        if (((dVar15 <= 0.0) || (dVar1 <= 0.0)) || (_DAT_130b720bb48 <= 0.0)) {
LAB_130b71e68a7:
          uVar8 = 0x130b7203888;
          goto LAB_130b71e68c2;
        }
        lVar10 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x1f);
        lVar11 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x20);
        dVar2 = (double)lVar10;
        if ((double)lVar10 <= (double)lVar11) {
          dVar2 = (double)lVar11;
        }
        dVar15 = dVar15 * dVar2;
        if (lVar9 == 1) {
          if (dVar4 - dVar15 <= param_3) goto LAB_130b71e68a7;
        }
        else if ((lVar9 != 0) || (param_3 <= dVar1 + dVar15)) goto LAB_130b71e68a7;
LAB_130b71e63c0:
        (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,&local_120,local_f8);
        _DAT_130b720bb10 = 0;
        _DAT_130b720bb80 = 0;
        DAT_130b720bb88 = 0;
        cVar5 = FUN_130b71dd110(0x130b720b450,param_1,dVar14,0);
        uVar16 = _DAT_130b720bb10;
        iVar18 = _DAT_130b720b560;
        if ((cVar5 == '\0') || (_DAT_130b720b560 - 0x271bU < 0xfffffffd)) {
          cVar6 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
          if (cVar6 != '\0') {
            (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
            dVar15 = (double)FUN_130b71e0af0(_DAT_130b720bb48);
            if ((double)((ulonglong)(dVar15 - dVar14) & _DAT_130b7201430) <=
                _DAT_130b720b7a0 * _DAT_130b7201440) {
              FUN_130b71e2e30(param_1,dVar13);
              uVar20 = _DAT_130b720b7b0;
              (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_110);
              uVar8 = 0x130b7203930;
              goto LAB_130b71e6848;
            }
          }
          uVar8 = 0x130b7203968;
          uVar19 = CONCAT44(uVar7,uVar16);
          goto LAB_130b71e68c6;
        }
        FUN_130b71e2e30(param_1,dVar13);
        uVar20 = _DAT_130b720b7b0;
        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_110);
        uVar8 = 0x130b72038e0;
        dVar15 = dVar14;
LAB_130b71e6848:
        param_1 = &local_110;
        (*(code *)0x7ff63a0e49f0)
                  (0x130b53f81d8,0xd,4,0x590008,uVar8,0x590008,param_1,0x520004,uVar20,0x580007,
                   dVar15);
      }
      FUN_130b71d0000(&local_120);
      uVar12 = CONCAT71((int7)((ulonglong)param_1 >> 8),1);
      goto LAB_130b71e68f5;
    }
LAB_130b71e64e1:
    local_100 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x20);
    uVar7 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_120,0x1f);
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,4);
    dVar14 = _DAT_130b720bb48;
    uVar20 = _DAT_130b720b7b0;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_120,1);
    dVar13 = _DAT_130b720bb48;
    uVar3 = _DAT_130b720b7b0;
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_110);
    (*(code *)0x7ff63a0e49f0)
              (0x130b53f81d8,0xd,10,0x590008,0x130b7203840,0x590008,&local_110,0x520004,uVar3,
               0x580007,param_3,0x520004,uVar3,0x580007,dVar13,0x520004,uVar20,0x580007,dVar14,
               0x520004,uVar7,0x520004,(int)local_100);
LAB_130b71e68e6:
    FUN_130b71d0000(&local_120);
  }
  uVar12 = 0;
LAB_130b71e68f5:
  FUN_130b71d0000(&local_110);
  return uVar12 & 0xffffffff;
}



/* Address: 130b71e6960 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e6960(longlong param_1,double param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  double dVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  undefined8 in_stack_ffffffffffffff08;
  undefined4 uVar15;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_ac;
  undefined1 local_a8 [104];
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  local_b8 = 0;
  local_c8 = 0;
  local_b4 = 0;
  local_c4 = 0;
  if ((param_1 == 0) || (cVar4 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar4 == '\0'))
  goto LAB_130b71e6de1;
  uVar6 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
  local_c8 = 0;
  local_c4 = 0;
  uVar10 = 0;
  (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
  FUN_130b71d0a30(&local_b8,0x130b720bb3c,1,0x130b7207c48);
  FUN_130b71d0a30(&local_c8,&local_b8,0,0x130b7207c58);
  if ((param_2 <= 0.0) ||
     ((*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_c8,0x10), _DAT_130b720bb48 <= 0.0)) {
    uVar11 = 0;
  }
  else {
    if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2b06f9000001f7);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    dVar14 = param_2 / _DAT_130b720bb48 + _DAT_130b7201450;
    dVar13 = (double)(_DAT_130b7201460 & (ulonglong)dVar14);
    uVar2 = (uint)((ulonglong)dVar13 >> 0x20);
    if (uVar2 >> 0x14 < 0x3ff) {
      if ((dVar13 != 0.0) &&
         (dVar14 = (double)((ulonglong)dVar14 & 0x8000000000000000), dVar14 == 0.0)) {
        dVar14 = _DAT_130b7201470;
      }
    }
    else if (uVar2 >> 0x16 < 0x10d) {
      bVar8 = 0x33 - (char)((ulonglong)dVar13 >> 0x34);
      dVar9 = (double)(((ulonglong)dVar13 >> (bVar8 & 0x3f)) << (bVar8 & 0x3f));
      if ((longlong)dVar14 < 0) {
        dVar14 = (double)((ulonglong)dVar9 | 0x8000000000000000);
      }
      else {
        dVar14 = dVar13;
        if (dVar9 != dVar13) {
          dVar14 = dVar9 + _DAT_130b7201470;
        }
      }
    }
    dVar13 = 0.0;
    if (0.0 <= dVar14) {
      dVar13 = dVar14;
    }
    uVar11 = (longlong)(dVar13 - _DAT_130b7201478) & (longlong)dVar13 >> 0x3f | (longlong)dVar13;
  }
  _DAT_130b720b6e5 = uVar6;
  uVar7 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_c8,0x32);
  if (((uVar7 & 1) != 0) || (uVar10 = 1, (uVar7 & 2) != 0)) {
    _DAT_130b720b6f5 = uVar10;
  }
  _DAT_130b720bb10 = 0;
  _DAT_130b720bb80 = 0;
  DAT_130b720bb88 = 0;
  _DAT_130b720b6ed = uVar11;
  cVar4 = FUN_130b71dd410(0x130b720b450,param_1,uVar11);
  iVar3 = _DAT_130b720b560;
  local_ac = _DAT_130b720bb10;
  bVar12 = _DAT_130b720b560 - 0x271bU < 0xfffffffd;
  if (((bVar12 || cVar4 == '\0') ||
      (cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar5 != '\0')) &&
     (cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar5 != '\0')) {
    if ((iVar3 - 0x2714U < 0x12) && ((0x30101U >> (iVar3 - 0x2714U & 0x1f) & 1) != 0)) {
      (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,&local_c8,local_a8);
      _DAT_130b720bb10 = 0;
      _DAT_130b720bb80 = 0;
      DAT_130b720bb88 = 0;
      cVar4 = FUN_130b71dd410(0x130b720b450,param_1,uVar11);
      uVar10 = _DAT_130b720bb10;
      iVar3 = _DAT_130b720b560;
      if ((cVar4 == '\0') ||
         ((_DAT_130b720b560 - 0x271bU < 0xfffffffd ||
          (cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar5 != '\0')))) {
        cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
        if (cVar5 == '\0') goto LAB_130b71e6dc1;
        FUN_130b71e59b0(0x130b7203a18,param_1,0,0,cVar4,iVar3,CONCAT44(uVar15,uVar10));
      }
      else {
        FUN_130b71e3b50(param_1);
        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_b8);
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,2,0x590008,0x130b72039e0,0x590008,&local_b8);
      }
    }
    else if ((bVar12 || cVar4 == '\0') ||
            (cVar5 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar5 == '\0')) {
      FUN_130b71e59b0(0x130b7203aa8,param_1,0,0,cVar4,iVar3,CONCAT44(uVar15,local_ac));
    }
    else {
      (*(code *)0x7ff63a107f70)(0x130b53f81d8,3);
      dVar14 = _DAT_130b720bb48;
      (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_b8);
      (*(code *)0x7ff63a0e49f0)
                (0x130b53f81d8,0xd,4,0x590008,0x130b7203a78,0x590008,&local_b8,0x530014,iVar3,
                 0x580007,dVar14);
    }
  }
  else {
LAB_130b71e6dc1:
    FUN_130b71e3b50(param_1);
  }
  FUN_130b71d0000(&local_c8);
LAB_130b71e6de1:
  FUN_130b71d0000(&local_b8);
  return;
}



/* Address: 130b71e6fc0 */

undefined8 FUN_130b71e6fc0(void)

{
  uint uVar1;
  undefined8 uVar2;
  int local_28;
  int local_24;
  int local_20;
  ulonglong uVar3;
  
  uVar2 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  if (DAT_130b720bd28 != '\0') {
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar2,&local_28);
    uVar1 = local_24 * 100 + local_28 * 10000 + local_20;
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0x134b1ca) {
      if ((int)uVar1 < 0x13464d7) {
        if ((int)uVar1 < 0x1343e92) {
          if ((int)uVar1 < 0x1343c9d) {
            if ((int)uVar1 < 0x1343b72) {
              if ((uVar1 == 0x1343aae) || (uVar1 == 0x1343b0f)) goto LAB_130b71e7bb8;
            }
            else if ((uVar1 == 0x1343b72) || ((uVar1 == 0x1343bd3 || (uVar1 == 0x1343c3c))))
            goto LAB_130b71e7bb8;
          }
          else if ((int)uVar1 < 0x1343d67) {
            if ((uVar1 == 0x1343c9d) || (uVar1 == 0x1343cfe)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x1343d67) || ((uVar1 == 0x1343dc8 || (uVar1 == 0x1343e2a))))
          goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x13462e2) {
          if ((int)uVar1 < 0x13461bc) {
            if ((uVar1 == 0x1343e92) || (uVar1 == 0x1343ef4)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x13461bc) || ((uVar1 == 0x134621d || (uVar1 == 0x1346281))))
          goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x13463ac) {
          if ((uVar1 == 0x13462e2) || (uVar1 == 0x134634b)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x13463ac) || ((uVar1 == 0x134640e || (uVar1 == 0x1346476))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x1348b24) {
        if ((int)uVar1 < 0x134892c) {
          if ((int)uVar1 < 0x13465a1) {
            if ((uVar1 == 0x13464d7) || (uVar1 == 0x1346540)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x13465a1) || ((uVar1 == 0x1346603 || (uVar1 == 0x13488cb))))
          goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x13489f1) {
          if ((uVar1 == 0x134892c) || (uVar1 == 0x1348990)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x13489f1) || ((uVar1 == 0x1348a5a || (uVar1 == 0x1348abb))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x1348d12) {
        if ((int)uVar1 < 0x1348be6) {
          if ((uVar1 == 0x1348b24) || (uVar1 == 0x1348b85)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x1348be6) || ((uVar1 == 0x1348c4f || (uVar1 == 0x1348cb0))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134b0a6) {
        if (((uVar1 == 0x1348d12) || (uVar1 == 0x134afda)) || (uVar1 == 0x134b03b))
        goto LAB_130b71e7bb8;
      }
      else if (((uVar1 == 0x134b0a6) || (uVar1 == 0x134b107)) || (uVar1 == 0x134b169))
      goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x134fec3) {
      if ((int)uVar1 < 0x134d815) {
        if ((int)uVar1 < 0x134b3bf) {
          if ((int)uVar1 < 0x134b294) {
            if ((uVar1 == 0x134b1ca) || (uVar1 == 0x134b233)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x134b294) || ((uVar1 == 0x134b2f5 || (uVar1 == 0x134b35e))))
          goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x134d6e9) {
          if ((uVar1 == 0x134b3bf) || (uVar1 == 0x134b428)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134d6e9) || ((uVar1 == 0x134d74a || (uVar1 == 0x134d7b4))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134da0a) {
        if ((int)uVar1 < 0x134d8df) {
          if ((uVar1 == 0x134d815) || (uVar1 == 0x134d877)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134d8df) || ((uVar1 == 0x134d941 || (uVar1 == 0x134d9a2))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134db36) {
        if (((uVar1 == 0x134da0a) || (uVar1 == 0x134da6c)) || (uVar1 == 0x134dacd))
        goto LAB_130b71e7bb8;
      }
      else if (((uVar1 == 0x134db36) || (uVar1 == 0x134fdfe)) || (uVar1 == 0x134fe5f))
      goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x1352573) {
      if ((int)uVar1 < 0x13500b1) {
        if ((int)uVar1 < 0x134ff86) {
          if ((uVar1 == 0x134fec3) || (uVar1 == 0x134ff24)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134ff86) || ((uVar1 == 0x134ffee || (uVar1 == 0x135004f))))
        goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x13501f0) {
        if ((uVar1 == 0x13500b1) || (uVar1 == 0x1350119)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x13501f0) || ((uVar1 == 0x1350250 || (uVar1 == 0x135250d))))
      goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x135275e) {
      if ((int)uVar1 < 0x1352633) {
        if ((uVar1 == 0x1352573) || (uVar1 == 0x13525d2)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x1352633) || ((uVar1 == 0x135269c || (uVar1 == 0x13526fd))))
      goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x135288a) {
      if (((uVar1 == 0x135275e) || (uVar1 == 0x13527c7)) || (uVar1 == 0x1352828))
      goto LAB_130b71e7bb8;
    }
    else if (((uVar1 == 0x135288a) || (uVar1 == 0x13528f2)) || (uVar1 == 0x1352954))
    goto LAB_130b71e7bb8;
  }
  if (DAT_130b720bd30 != '\0') {
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar2,&local_28);
    uVar1 = local_24 * 100 + local_28 * 10000 + local_20;
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0x134b42d) {
      if ((int)uVar1 < 0x134659f) {
        if ((int)uVar1 < 0x1343e91) {
          if ((int)uVar1 < 0x1343bed) {
            if (((uVar1 + 0xfecbc491 < 0x15) &&
                ((0x101001U >> (uVar1 + 0xfecbc491 & 0x1f) & 1) != 0)) || (uVar1 == 0x1343ac1))
            goto LAB_130b71e7bb8;
          }
          else if ((int)uVar1 < 0x1343d19) {
            if ((uVar1 == 0x1343bed) || (uVar1 == 0x1343ca2)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x1343d19) || (uVar1 == 0x1343dd4)) goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x13462fc) {
          if ((int)uVar1 < 0x13461cf) {
            if ((uVar1 == 0x1343e91) || (uVar1 == 0x1343f00)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x13461cf) || (uVar1 == 0x134628d)) goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x1346428) {
          if ((uVar1 == 0x13462fc) || (uVar1 == 0x13463b8)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x1346428) || (uVar1 == 0x13464ea)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x1348cae) {
        if ((int)uVar1 < 0x1348a58) {
          if ((int)uVar1 < 0x13488de) {
            if ((uVar1 == 0x134659f) || (uVar1 == 0x134660f)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x13488de) || (uVar1 == 0x134899c)) goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x1348b37) {
          if ((uVar1 == 0x1348a58) || (uVar1 == 0x1348ac7)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x1348b37) || (uVar1 == 0x1348bf9)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134b167) {
        if ((int)uVar1 < 0x134b039) {
          if ((uVar1 == 0x1348cae) || (uVar1 == 0x1348d1e)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134b039) || (uVar1 == 0x134b0b2)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134b246) {
        if ((uVar1 == 0x134b167) || (uVar1 == 0x134b1d6)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x134b246) || ((uVar1 == 0x134b308 || (uVar1 == 0x134b3bd))))
      goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x135024a) {
      if ((int)uVar1 < 0x134db42) {
        if ((int)uVar1 < 0x134d8e4) {
          if ((int)uVar1 < 0x134d7c0) {
            if ((uVar1 == 0x134b42d) || (uVar1 == 0x134d703)) goto LAB_130b71e7bb8;
          }
          else if ((uVar1 == 0x134d7c0) || (uVar1 == 0x134d875)) goto LAB_130b71e7bb8;
        }
        else if ((int)uVar1 < 0x134da16) {
          if ((uVar1 == 0x134d8e4) || (uVar1 == 0x134d95b)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134da16) || (uVar1 == 0x134dad3)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x134fffa) {
        if ((int)uVar1 < 0x134fecf) {
          if ((uVar1 == 0x134db42) || (uVar1 == 0x134fe11)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x134fecf) || (uVar1 == 0x134ff8b)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x1350125) {
        if ((uVar1 == 0x134fffa) || (uVar1 == 0x135006a)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x1350125) || (uVar1 == 0x1350195)) goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x1352959) {
      if ((int)uVar1 < 0x1352709) {
        if ((int)uVar1 < 0x13525de) {
          if ((uVar1 == 0x135024a) || (uVar1 == 0x1352520)) goto LAB_130b71e7bb8;
        }
        else if ((uVar1 == 0x13525de) || (uVar1 == 0x135264d)) goto LAB_130b71e7bb8;
      }
      else if ((int)uVar1 < 0x1352834) {
        if ((uVar1 == 0x1352709) || (uVar1 == 0x1352779)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x1352834) || (uVar1 == 0x13528a4)) goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x1354e11) {
      if ((int)uVar1 < 0x1354ced) {
        if ((uVar1 == 0x1352959) || (uVar1 == 0x1354c2f)) goto LAB_130b71e7bb8;
      }
      else if ((uVar1 == 0x1354ced) || (uVar1 == 0x1354d5c)) goto LAB_130b71e7bb8;
    }
    else if ((int)uVar1 < 0x1354f43) {
      if ((uVar1 == 0x1354e11) || (uVar1 == 0x1354e88)) goto LAB_130b71e7bb8;
    }
    else if ((uVar1 == 0x1354f43) || ((uVar1 == 0x1354fb3 || (uVar1 == 0x1355068))))
    goto LAB_130b71e7bb8;
  }
  if (DAT_130b720bd38 == '\0') {
    return 0;
  }
  (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar2,&local_28);
  uVar1 = local_24 * 100 + local_28 * 10000 + local_20;
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0x1354c26) {
    if ((int)uVar1 < 0x135282b) {
      if ((int)uVar1 < 0x13526ad) {
        if (((uVar1 != 0x1352505) && (uVar1 != 0x1352517)) && (uVar1 != 0x1352578)) {
          uVar2 = FUN_130b71e7bc0();
          return uVar2;
        }
      }
      else if (((uVar1 != 0x13526ad) && (uVar1 != 0x135270b)) && (uVar1 != 0x1352760)) {
        uVar2 = FUN_130b71e7bc0();
        return uVar2;
      }
    }
    else if ((int)uVar1 < 0x1352906) {
      if (((uVar1 != 0x135282b) && (uVar1 != 0x1352894)) && (uVar1 != 0x13528f7)) {
        uVar2 = FUN_130b71e7bc0();
        return uVar2;
      }
    }
    else if (((uVar1 != 0x1352906) && (uVar1 != 0x1352969)) && (uVar1 != 0x1354c15)) {
      uVar2 = FUN_130b71e7bc0();
      return uVar2;
    }
  }
  else if ((int)uVar1 < 0x1354f3a) {
    if ((int)uVar1 < 0x1354e1b) {
      if (((uVar1 != 0x1354c26) && (uVar1 != 0x1354c87)) && (uVar1 != 0x1354dc3)) {
        uVar2 = FUN_130b71e7bc0();
        return uVar2;
      }
    }
    else if ((1 < uVar1 + 0xfecab190) && (uVar1 != 0x1354e1b)) {
      uVar2 = FUN_130b71e7bc0();
      return uVar2;
    }
  }
  else if ((int)uVar1 < 0x1355007) {
    if ((uVar1 != 0x1354f3a) && (uVar1 != 0x1354fa3)) {
      return 0;
    }
  }
  else if (((uVar1 != 0x1355007) && (uVar1 != 0x1355015)) && (uVar1 != 0x1355079)) {
    uVar2 = FUN_130b71e7bc0();
    return uVar2;
  }
LAB_130b71e7bb8:
  return CONCAT71((int7)(uVar3 >> 8),1);
}



/* Address: 130b71e7bc0 */

undefined8 FUN_130b71e7bc0(void)

{
  return 0;
}



/* Address: 130b71e7bd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71e7bd0(int param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar6;
  double local_70;
  undefined1 local_68 [8];
  undefined8 auStack_60 [10];
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  cVar1 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,local_68);
  if (cVar1 == '\0') {
    uVar5 = 0x520004;
    uVar3 = 2;
    uVar4 = 0x130b7204a10;
    uVar2 = CONCAT44(uVar6,_DAT_130b720bb10);
  }
  else {
    _DAT_130b720bb10 = 0;
    local_70 = 0.0;
    _DAT_130b720bb80 = 0;
    DAT_130b720bb88 = 0;
    cVar1 = (*(code *)0x7ff63a108d40)
                      (0x130b53f81d8,param_1,0x130b720bb28,param_2,auStack_60[param_1 != 1],
                       &local_70);
    if (cVar1 == '\0') {
      uVar2 = 0x130b7201d28;
      uVar5 = 0x590008;
      uVar3 = 4;
      if (param_1 == 0) {
        uVar2 = 0x130b7201cf8;
      }
      uVar4 = 0x130b7204a68;
    }
    else {
      (*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x2a);
      if (local_70 <= _DAT_130b720bb48) {
        return 0x130b720bb01;
      }
      uVar2 = 0x130b7201d28;
      uVar3 = 5;
      uVar5 = 0x590008;
      if (param_1 == 0) {
        uVar2 = 0x130b7201cf8;
      }
      uVar4 = 0x130b7204ad8;
    }
  }
  (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd,uVar3,0x590008,uVar4,uVar5,uVar2);
  return 0;
}



/* Address: 130b71e7e30 */

bool FUN_130b71e7e30(void)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  bool bVar14;
  undefined8 local_c0;
  undefined8 local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined1 local_a0 [12];
  int local_94;
  int local_90;
  int local_8c;
  undefined1 local_80 [12];
  int local_74;
  int local_70;
  int local_6c;
  int local_60;
  uint local_5c;
  int local_58;
  int local_48;
  
  lVar9 = 0;
  local_a8 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_a8,&local_60);
  local_b8 = 0;
  local_c0 = 0;
  uVar2 = local_60 - (uint)(local_5c < 3);
  uVar6 = local_5c + 0xc;
  if (2 < local_5c) {
    uVar6 = local_5c;
  }
  lVar10 = (ulonglong)
           (((uVar6 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
           ((uVar2 * 0x16d + local_58 + (uVar2 >> 2)) - uVar2 / 100) + uVar2 / 400) * 0x15180;
  iVar4 = (int)((ulonglong)((longlong)(local_48 + 7) * -0x6db6db6d) >> 0x20) + 7 + local_48;
  iVar4 = local_48 + 7 + ((iVar4 >> 2) - (iVar4 >> 0x1f)) * -7;
  cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,iVar4,0,&local_b8,&local_c0);
  lVar13 = 0;
  if (cVar1 != '\0') {
    lVar13 = 0;
    local_b0 = lVar10 + 0x15180;
    iVar8 = 1;
    lVar9 = 0;
    do {
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_b8,local_80);
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_c0,local_a0);
      local_b8 = 0;
      local_c0 = 0;
      iVar7 = local_90 * 0x3c + local_94 * 0xe10 + local_8c;
      iVar5 = local_70 * 0x3c + local_74 * 0xe10 + local_6c;
      lVar12 = lVar10 + iVar5;
      lVar3 = lVar10 + 0x15180;
      if (iVar5 < iVar7) {
        lVar3 = lVar10;
      }
      lVar11 = lVar3 + iVar7;
      if (0 < iVar5) {
        lVar11 = local_b0;
      }
      if (iVar7 != 0) {
        lVar11 = lVar3 + iVar7;
      }
      lVar3 = lVar13;
      if (lVar12 < lVar13) {
        lVar3 = lVar12;
      }
      bVar14 = lVar13 == 0;
      lVar13 = lVar3;
      if (bVar14) {
        lVar13 = lVar12;
      }
      if (lVar9 < lVar11) {
        lVar9 = lVar11;
      }
      cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,iVar4,iVar8,&local_b8,&local_c0)
      ;
      iVar8 = iVar8 + 1;
    } while (cVar1 != '\0');
  }
  lVar12 = 0;
  local_b8 = 0;
  local_c0 = 0;
  local_b0 = lVar9;
  if (lVar9 <= local_a8) {
    local_b0 = lVar12;
  }
  if (lVar9 <= lVar13) {
    local_b0 = lVar12;
  }
  if (lVar13 < 1) {
    local_b0 = lVar12;
  }
  if (local_a8 < lVar13) {
    local_b0 = lVar12;
  }
  iVar4 = (int)((ulonglong)((longlong)(local_48 + 6) * -0x6db6db6d) >> 0x20) + 6 + local_48;
  iVar4 = local_48 + 6 + ((iVar4 >> 2) - (iVar4 >> 0x1f)) * -7;
  cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,iVar4,0,&local_b8,&local_c0);
  lVar9 = 0;
  if (cVar1 != '\0') {
    iVar8 = 1;
    lVar9 = 0;
    lVar12 = 0;
    do {
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_b8,local_80);
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_c0,local_a0);
      iVar5 = local_70 * 0x3c + local_74 * 0xe10 + local_6c;
      iVar7 = local_90 * 0x3c + local_94 * 0xe10 + local_8c;
      lVar13 = lVar10 + -0x15180;
      if (iVar7 <= iVar5) {
        lVar13 = lVar10;
      }
      local_b8 = 0;
      local_c0 = 0;
      lVar11 = (longlong)iVar5 + lVar10 + -0x15180;
      lVar3 = iVar7 + lVar13;
      if (0 < iVar5) {
        lVar3 = lVar10;
      }
      if (iVar7 != 0) {
        lVar3 = iVar7 + lVar13;
      }
      lVar13 = lVar9;
      if (lVar11 < lVar9) {
        lVar13 = lVar11;
      }
      bVar14 = lVar9 == 0;
      lVar9 = lVar13;
      if (bVar14) {
        lVar9 = lVar11;
      }
      if (lVar12 < lVar3) {
        lVar12 = lVar3;
      }
      cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,iVar4,iVar8,&local_b8,&local_c0)
      ;
      iVar8 = iVar8 + 1;
    } while (cVar1 != '\0');
  }
  lVar13 = local_b0;
  if ((((lVar9 <= local_a8) && (0 < lVar9)) && (lVar9 < lVar12)) && (local_a8 < lVar12)) {
    if (lVar12 < local_b0) {
      lVar13 = lVar12;
    }
    if (local_b0 == 0) {
      lVar13 = lVar12;
    }
  }
  if (lVar13 < 1) {
    bVar14 = false;
  }
  else {
    lVar10 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    lVar9 = lVar13 + -300;
    if (DAT_130b720b799 == '\0') {
      lVar9 = lVar13;
    }
    bVar14 = lVar10 < lVar13 && lVar9 <= lVar10;
  }
  return bVar14;
}



/* Address: 130b71e82f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71e82f0(longlong param_1,undefined8 param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  char cVar6;
  char cVar7;
  longlong lVar8;
  byte bVar9;
  undefined4 uVar10;
  undefined8 unaff_RBX;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  double dVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  double dVar17;
  double dVar18;
  undefined8 uVar19;
  undefined4 *puVar20;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined8 local_e8;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined1 local_a8 [104];
  
  uVar15 = CONCAT71((int7)((ulonglong)unaff_RBX >> 8),1);
  local_d8 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_d4 = 0;
  local_f4 = 0;
  local_104 = 0;
  if ((param_1 == 0) ||
     (local_e8 = param_2, cVar6 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1), cVar6 == '\0'))
  goto LAB_130b71e8b6b;
  local_108 = 0;
  local_104 = 0;
  (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
  FUN_130b71d0a30(&local_f8,0x130b720bb3c,1,0x130b7207cb8);
  FUN_130b71d0a30(&local_108,&local_f8,0,0x130b7207cc8);
  lVar8 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
  iVar11 = 0;
  if (local_104 == _DAT_130b720bb2c) {
LAB_130b71e84aa:
    uVar15 = 0;
    if ((iVar11 == 0) && (uVar15 = 0, lVar8 == _DAT_130b720bc30)) {
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_108,0x10);
      dVar18 = _DAT_130b720bb48;
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_108,4);
      dVar17 = _DAT_130b720bb48;
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_108,1);
      uVar16 = 0x14;
      if ((0.0 < dVar18) && ((0.0 < dVar17 && (0.0 < _DAT_130b720bb48)))) {
        if ((dVar18 == 0.0) && (!NAN(dVar18))) {
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x390d87000001f7);
          pcVar5 = (code *)swi(3);
          uVar15 = (*pcVar5)();
          return uVar15;
        }
        dVar18 = (dVar17 - _DAT_130b720bb48) / dVar18;
        dVar18 = dVar18 + dVar18;
        dVar17 = (double)(_DAT_130b7201480 & (ulonglong)dVar18);
        uVar3 = (uint)((ulonglong)dVar17 >> 0x20);
        if (uVar3 >> 0x14 < 0x3ff) {
          if ((dVar17 != 0.0) &&
             (dVar18 = (double)((ulonglong)dVar18 & 0x8000000000000000), dVar18 == 0.0)) {
            dVar18 = _DAT_130b7201490;
          }
        }
        else if (uVar3 >> 0x16 < 0x10d) {
          bVar9 = 0x33 - (char)((ulonglong)dVar17 >> 0x34);
          dVar14 = (double)(((ulonglong)dVar17 >> (bVar9 & 0x3f)) << (bVar9 & 0x3f));
          if ((longlong)dVar18 < 0) {
            dVar18 = (double)((ulonglong)dVar14 | 0x8000000000000000);
          }
          else {
            dVar18 = dVar17;
            if (dVar14 != dVar17) {
              dVar18 = dVar14 + _DAT_130b7201490;
            }
          }
        }
        dVar17 = _DAT_130b7201498;
        if (_DAT_130b7201498 <= dVar18) {
          dVar17 = dVar18;
        }
        uVar16 = (longlong)(dVar17 - _DAT_130b72014a0) & (longlong)dVar17 >> 0x3f | (longlong)dVar17
        ;
      }
      _DAT_130b720b295 = lVar8;
      uVar15 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,&local_108,0x32);
      uVar10 = 0;
      if (((uVar15 & 1) != 0) || (uVar10 = 1, (uVar15 & 2) != 0)) {
        _DAT_130b720b2a5 = uVar10;
      }
      _DAT_130b720bb10 = 0;
      _DAT_130b720bb80 = 0;
      DAT_130b720bb88 = 0;
      _DAT_130b720b29d = uVar16;
      cVar6 = FUN_130b71dd410(0x130b720b000,param_1,uVar16);
      uVar10 = _DAT_130b720bb10;
      iVar11 = _DAT_130b720b110;
      cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
      uVar15 = 0x130b53f8101;
      if (cVar7 != '\0') {
        if (((cVar6 == '\0') || (iVar11 - 0x271bU < 0xfffffffd)) &&
           ((uVar3 = iVar11 - 0x2714, 0x11 < uVar3 || ((0x30101U >> (uVar3 & 0x1f) & 1) == 0)))) {
LAB_130b71e89b1:
          local_b8 = 0;
          local_b4 = 0;
          local_c8 = 0;
          local_c0 = 0;
          local_dc = uVar10;
          FUN_130b71dbd30(&local_c8,0x130b720b020,&DAT_130b720b110);
          uVar15 = 0;
          FUN_130b71d0a30(&local_b8,&local_c8,0,0x130b7206928);
          FUN_130b71d0000(&local_c8);
          FUN_130b71d0a30(0x130b720bb3c,&local_b8,1,0x130b7206938);
          FUN_130b71d0000(&local_b8);
          FUN_130b71d0a30(&local_f8,0x130b720bb3c,1,0x130b7207cd8);
          puVar20 = &local_d8;
          (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,puVar20);
          uVar13 = 7;
          uVar19 = 0x130b7203d20;
        }
        else {
          (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,&local_108,local_a8);
          _DAT_130b720bb10 = 0;
          _DAT_130b720bb80 = 0;
          DAT_130b720bb88 = 0;
          cVar6 = FUN_130b71dd410(0x130b720b000,param_1,uVar16);
          uVar10 = _DAT_130b720bb10;
          iVar11 = _DAT_130b720b110;
          cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
          if (cVar7 != '\0') {
            if (((cVar6 != '\0') && (0xfffffffc < iVar11 - 0x271bU)) ||
               ((uVar3 = iVar11 - 0x2714, uVar3 < 0x12 && ((0x30101U >> (uVar3 & 0x1f) & 1) != 0))))
            {
              (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,&local_108,local_a8);
              cVar6 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,param_1);
              if (cVar6 != '\0') {
                (*(code *)0x7ff63a107f70)(0x130b53f81d8,3);
                dVar18 = _DAT_130b720bb48;
                (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,&local_f8);
                (*(code *)0x7ff63a0e49f0)
                          (0x130b53f81d8,0xd,4,0x590008,0x130b7203d78,0x590008,&local_f8,0x590008,
                           local_e8,0x580007,dVar18);
                uVar15 = 0;
              }
              goto LAB_130b71e8b60;
            }
            goto LAB_130b71e89b1;
          }
          puVar20 = &local_f8;
          (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,param_1,0x56,puVar20);
          uVar13 = 3;
          uVar19 = 0x130b7203ca8;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x130b53f81d8,0xd,uVar13,0x590008,uVar19,0x590008,puVar20,0x590008,local_e8);
      }
    }
  }
  else {
    uVar15 = 0;
    if ((local_104 != 0) && (_DAT_130b720bb2c != 0)) {
      uVar3 = *(uint *)(local_104 + -4);
      uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
      uVar12 = uVar4;
      if (uVar3 < uVar4) {
        uVar12 = uVar3;
      }
      iVar11 = uVar3 - uVar4;
      if (uVar12 != 0) {
        uVar15 = 1;
        do {
          uVar1 = *(ushort *)(local_104 + -2 + uVar15 * 2);
          uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar15 * 2);
          if (uVar12 <= uVar15) break;
          uVar15 = uVar15 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar11 = (uint)uVar1 - (uint)uVar2;
        }
      }
      goto LAB_130b71e84aa;
    }
  }
LAB_130b71e8b60:
  FUN_130b71d0000(&local_108);
LAB_130b71e8b6b:
  FUN_130b71d0000(&local_f8);
  FUN_130b71d0000(&local_d8);
  return uVar15 & 0xffffffff;
}



/* Address: 130b71e8bd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71e8bd0(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  double dVar4;
  undefined8 uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 unaff_R13;
  undefined8 uVar14;
  longlong lVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 local_b0;
  longlong local_ac;
  char local_9d;
  uint local_9c;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_84 = 0;
  local_ac = 0;
  local_94 = 0;
  iVar8 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar8 == 0) {
    dVar4 = (double)_DAT_130b720b9bc;
    FUN_130b71ea9d0(0x130b7203da8);
    uVar14 = CONCAT71((int7)((ulonglong)unaff_R13 >> 8),1);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d08);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,dVar4);
    dVar4 = (double)_DAT_130b720b90c;
    FUN_130b71ea9d0(0x130b7203dd8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d18);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,dVar4);
    uVar20 = 0;
    uVar21 = 0;
    uVar22 = (undefined4)_DAT_130b72014a8;
    uVar23 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b9c0 != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e08);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d28);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b9c1 != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e38);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d38);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b95c != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e68);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d48);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    uVar5 = _DAT_130b720b960;
    FUN_130b71ea9d0(0x130b7203e98);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d58);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b968;
    FUN_130b71ea9d0(0x130b7203ec8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d68);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b970;
    FUN_130b71ea9d0(0x130b7203ef8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d78);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b978;
    FUN_130b71ea9d0(0x130b7203f28);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d88);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b95d != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203f58);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207d98);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    uVar5 = _DAT_130b720b990;
    FUN_130b71ea9d0(0x130b7203f88);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207da8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b998;
    FUN_130b71ea9d0(0x130b7203fb8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207db8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b9a0;
    FUN_130b71ea9d0(0x130b7203fe8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207dc8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar5 = _DAT_130b720b9a8;
    FUN_130b71ea9d0(0x130b7204018);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207dd8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar5);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720ba6e != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7204048);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207de8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    cVar7 = DAT_130b720bc80;
    uVar24 = uVar22;
    uVar25 = uVar23;
    if (DAT_130b720b944 == '\0') {
      uVar24 = 0;
      uVar25 = 0;
    }
    if (DAT_130b720bc80 == '\0') {
      uVar24 = 0;
      uVar25 = 0;
    }
    FUN_130b71ea9d0(0x130b7204078);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207df8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    if (cVar7 != '\0') {
      uVar22 = (undefined4)_DAT_130b720b948;
      uVar23 = (undefined4)((ulonglong)_DAT_130b720b948 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b72040a8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207e08);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar23,uVar22));
    local_9d = cVar7;
    if (cVar7 != '\0') {
      uVar20 = (undefined4)_DAT_130b720b950;
      uVar21 = (undefined4)((ulonglong)_DAT_130b720b950 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b72040d8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207e18);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar21,uVar20));
    uVar24 = (undefined4)_DAT_130b72014a8;
    uVar25 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    uVar11 = 0;
    do {
      local_98 = 0;
      local_9c = (uint)uVar14;
      local_94 = 0;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd8,2,0x590008,0x130b7204108,0x520004,uVar11);
      FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207e28);
      FUN_130b71d0a30(&local_98,&local_b0,0,0x130b7207e38);
      lVar19 = (ulonglong)uVar11 * 0x4c;
      cVar7 = (&DAT_130b720b9d0)[lVar19];
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207e48);
      uVar11 = _DAT_130b72034b4;
      uVar12 = (ulonglong)_DAT_130b72034b4;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b72034b4;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b72034b4 + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar6 == '\0') goto LAB_130b71ea9a5;
        if (uVar12 != 0) {
          lVar15 = local_ac + (ulonglong)uVar17 * 2;
          if (uVar11 < 8) {
            uVar10 = 0;
          }
          else if (local_ac + -0x130b72034b8 + (ulonglong)uVar17 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar13 = 0;
            uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
            do {
              uVar20 = *(undefined4 *)(uVar13 + 0x130b72034bc);
              uVar21 = *(undefined4 *)(uVar13 + 0x130b72034c0);
              uVar22 = *(undefined4 *)(uVar13 + 0x130b72034c4);
              puVar2 = (undefined4 *)(lVar15 + uVar13);
              *puVar2 = *(undefined4 *)(&DAT_130b72034b8 + uVar13);
              puVar2[1] = uVar20;
              puVar2[2] = uVar21;
              puVar2[3] = uVar22;
              uVar13 = uVar13 + 0x10;
            } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
            if (uVar10 == uVar12) goto LAB_130b71e9422;
          }
          do {
            *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72034b8 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar12 != uVar10);
        }
LAB_130b71e9422:
        *(uint *)(local_ac + -4) = uVar16;
        *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
      }
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207e58);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,CONCAT44(uVar21,uVar20));
      cVar7 = *(char *)(lVar19 + 0x130b720b9d1);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207e68);
      uVar11 = _DAT_130b720411c;
      uVar12 = (ulonglong)_DAT_130b720411c;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b720411c;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b720411c + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar6 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7204120 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b7204124);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7204128);
                uVar22 = *(undefined4 *)(&DAT_130b720412c + uVar13);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7204120 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e95d2;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204120 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e95d2:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e95f3;
        }
LAB_130b71ea8e5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2b000001f9);
LAB_130b71ea905:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c35000001f9);
LAB_130b71ea925:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c32000001f9);
LAB_130b71ea945:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c30000001f9);
LAB_130b71ea965:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2e000001f9);
LAB_130b71ea985:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2c000001f9);
LAB_130b71ea9a5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2a000001f9);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
LAB_130b71e95f3:
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207e78);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,CONCAT44(uVar21,uVar20));
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9d2);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207e88);
      uVar11 = _DAT_130b7203514;
      uVar12 = (ulonglong)_DAT_130b7203514;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b7203514;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b7203514 + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7203518 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b720351c);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7203520);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b7203524);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7203518 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9782;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203518 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9782:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e97a3;
        }
        goto LAB_130b71ea985;
      }
LAB_130b71e97a3:
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207e98);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,uVar14);
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9da);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207ea8);
      uVar11 = _DAT_130b72034f4;
      uVar12 = (ulonglong)_DAT_130b72034f4;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b72034f4;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b72034f4 + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b72034f8 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b72034fc);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7203500);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b7203504);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b72034f8 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9912;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72034f8 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9912:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e9933;
        }
LAB_130b71ea8c5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2d000001f9);
        goto LAB_130b71ea8e5;
      }
LAB_130b71e9933:
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207eb8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,uVar14);
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9e2);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207ec8);
      uVar11 = _DAT_130b7203534;
      uVar12 = (ulonglong)_DAT_130b7203534;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b7203534;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b7203534 + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7203538 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b720353c);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7203540);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b7203544);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7203538 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9aa2;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203538 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9aa2:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e9ac3;
        }
        goto LAB_130b71ea965;
      }
LAB_130b71e9ac3:
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207ed8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,uVar14);
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9ea);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207ee8);
      uVar11 = _DAT_130b720412c;
      uVar12 = (ulonglong)_DAT_130b720412c;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b720412c;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b720412c + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7204130 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b7204134);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7204138);
                uVar22 = *(undefined4 *)(&DAT_130b720413c + uVar13);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7204130 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9c32;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204130 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9c32:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e9c53;
        }
LAB_130b71ea8a5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2f000001f9);
        goto LAB_130b71ea8c5;
      }
LAB_130b71e9c53:
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207ef8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,uVar14);
      lVar15 = *(longlong *)(lVar19 + 0x130b720b9f2);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f08);
      uVar11 = _DAT_130b7203554;
      uVar12 = (ulonglong)_DAT_130b7203554;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b7203554;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b7203554 + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar1 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7203558 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b720355c);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7203560);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b7203564);
                puVar2 = (undefined4 *)(lVar1 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7203558 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9dc2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203558 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9dc2:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71e9de3;
        }
        goto LAB_130b71ea945;
      }
LAB_130b71e9de3:
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207f18);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,(double)lVar15);
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9fa);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f28);
      uVar11 = _DAT_130b7203574;
      uVar12 = (ulonglong)_DAT_130b7203574;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar10 = 0;
          uVar17 = _DAT_130b7203574;
        }
        else {
          uVar10 = (ulonglong)*(uint *)(local_ac + -4);
          uVar17 = _DAT_130b7203574 + *(uint *)(local_ac + -4);
        }
        uVar16 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar16);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + uVar10 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7203578 + uVar10 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b720357c);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7203580);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b7203584);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7203578 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71e9f62;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203578 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71e9f62:
          *(uint *)(local_ac + -4) = uVar17;
          *(undefined2 *)(local_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e9f83;
        }
LAB_130b71ea885:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c31000001f9);
        goto LAB_130b71ea8a5;
      }
LAB_130b71e9f83:
      FUN_130b71eade0(&local_b0,uVar14);
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720ba02);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f38);
      uVar11 = _DAT_130b7203594;
      uVar12 = (ulonglong)_DAT_130b7203594;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar10 = 0;
          uVar17 = _DAT_130b7203594;
        }
        else {
          uVar10 = (ulonglong)*(uint *)(local_ac + -4);
          uVar17 = _DAT_130b7203594 + *(uint *)(local_ac + -4);
        }
        uVar16 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar16);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + uVar10 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7203598 + uVar10 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b720359c);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b72035a0);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b72035a4);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7203598 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71ea0d2;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203598 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71ea0d2:
          *(uint *)(local_ac + -4) = uVar17;
          *(undefined2 *)(local_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71ea0f3;
        }
        goto LAB_130b71ea925;
      }
LAB_130b71ea0f3:
      FUN_130b71eade0(&local_b0,uVar14);
      lVar15 = *(longlong *)(lVar19 + 0x130b720ba0a);
      if (lVar15 < 1) {
        lVar15 = 0;
      }
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f48);
      uVar11 = _DAT_130b72035b4;
      uVar12 = (ulonglong)_DAT_130b72035b4;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar10 = 0;
          uVar17 = _DAT_130b72035b4;
        }
        else {
          uVar10 = (ulonglong)*(uint *)(local_ac + -4);
          uVar17 = _DAT_130b72035b4 + *(uint *)(local_ac + -4);
        }
        uVar16 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar16);
        if (cVar7 != '\0') {
          if (uVar12 != 0) {
            lVar1 = local_ac + uVar10 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b72035b8 + uVar10 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b72035bc);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b72035c0);
                uVar22 = *(undefined4 *)(uVar13 + 0x130b72035c4);
                puVar2 = (undefined4 *)(lVar1 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b72035b8 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71ea242;
            }
            do {
              *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72035b8 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71ea242:
          *(uint *)(local_ac + -4) = uVar17;
          *(undefined2 *)(local_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71ea263;
        }
LAB_130b71ea865:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c33000001f9);
        goto LAB_130b71ea885;
      }
LAB_130b71ea263:
      FUN_130b71eade0(&local_b0,lVar15);
      cVar7 = *(char *)(lVar19 + 0x130b720ba13);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f58);
      uVar11 = _DAT_130b720413c;
      uVar12 = (ulonglong)_DAT_130b720413c;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar17 = 0;
          uVar16 = _DAT_130b720413c;
        }
        else {
          uVar17 = *(uint *)(local_ac + -4);
          uVar16 = _DAT_130b720413c + uVar17;
        }
        uVar18 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&local_b0,uVar18);
        if (cVar6 != '\0') {
          if (uVar12 != 0) {
            lVar15 = local_ac + (ulonglong)uVar17 * 2;
            if (uVar11 < 8) {
              uVar10 = 0;
            }
            else if (local_ac + -0x130b7204140 + (ulonglong)uVar17 * 2 < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar13 = 0;
              uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar13 + 0x130b7204144);
                uVar21 = *(undefined4 *)(uVar13 + 0x130b7204148);
                uVar22 = *(undefined4 *)(&DAT_130b720414c + uVar13);
                puVar2 = (undefined4 *)(lVar15 + uVar13);
                *puVar2 = *(undefined4 *)(&DAT_130b7204140 + uVar13);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar13 = uVar13 + 0x10;
              } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
              if (uVar10 == uVar12) goto LAB_130b71ea3b2;
            }
            do {
              *(undefined2 *)(lVar15 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204140 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar12 != uVar10);
          }
LAB_130b71ea3b2:
          *(uint *)(local_ac + -4) = uVar16;
          *(undefined2 *)(local_ac + (ulonglong)uVar16 * 2) = 0;
          goto LAB_130b71ea3c9;
        }
        goto LAB_130b71ea905;
      }
LAB_130b71ea3c9:
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207f68);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,CONCAT44(uVar21,uVar20));
      uVar14 = *(undefined8 *)(lVar19 + 0x130b720ba14);
      FUN_130b71d0a30(&local_b0,&local_98,0,0x130b7207f78);
      uVar17 = local_9c;
      uVar11 = _DAT_130b720414c;
      uVar12 = (ulonglong)_DAT_130b720414c;
      if ((uVar12 != 0) || (local_ac == 0)) {
        if (local_ac == 0) {
          uVar16 = 0;
          uVar18 = _DAT_130b720414c;
        }
        else {
          uVar16 = *(uint *)(local_ac + -4);
          uVar18 = _DAT_130b720414c + uVar16;
        }
        uVar9 = 0x104;
        if ((0x103 < uVar18) &&
           ((0x7ffffffd < uVar18 || (uVar9 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar9)))) {
          uVar9 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&local_b0,uVar9);
        if (cVar7 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c36000001f9);
          goto LAB_130b71ea865;
        }
        if (uVar12 != 0) {
          lVar19 = local_ac + (ulonglong)uVar16 * 2;
          if (uVar11 < 8) {
            uVar10 = 0;
          }
          else if (local_ac + -0x130b7204150 + (ulonglong)uVar16 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar13 = 0;
            uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
            do {
              uVar20 = *(undefined4 *)(uVar13 + 0x130b7204154);
              uVar21 = *(undefined4 *)(uVar13 + 0x130b7204158);
              uVar22 = *(undefined4 *)(uVar13 + 0x130b720415c);
              puVar2 = (undefined4 *)(lVar19 + uVar13);
              *puVar2 = *(undefined4 *)(&DAT_130b7204150 + uVar13);
              puVar2[1] = uVar20;
              puVar2[2] = uVar21;
              puVar2[3] = uVar22;
              uVar13 = uVar13 + 0x10;
            } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
            if (uVar10 == uVar12) goto LAB_130b71e91e0;
          }
          do {
            *(undefined2 *)(lVar19 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204150 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar12 != uVar10);
        }
LAB_130b71e91e0:
        *(uint *)(local_ac + -4) = uVar18;
        *(undefined2 *)(local_ac + (ulonglong)uVar18 * 2) = 0;
      }
      FUN_130b71ea9d0(&local_b0);
      FUN_130b71d0a30(&local_88,0x130b720bb3c,1,0x130b7207f88);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_88,uVar14);
      FUN_130b71d0000(&local_98);
      uVar11 = 1;
      uVar14 = 0;
    } while ((uVar17 & 1) != 0);
    dVar4 = (double)_DAT_130b720bc50;
    FUN_130b71ea9d0(0x130b7204178);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207f98);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,dVar4);
    dVar4 = (double)_DAT_130b720bc58;
    FUN_130b71ea9d0(0x130b72041a8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207fa8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,dVar4);
    uVar14 = _DAT_130b720bc60;
    FUN_130b71ea9d0(0x130b72041d8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207fb8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar14);
    uVar14 = _DAT_130b720bc68;
    FUN_130b71ea9d0(0x130b7204208);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207fc8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar14);
    uVar14 = _DAT_130b720bc70;
    FUN_130b71ea9d0(0x130b7204238);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207fd8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar14);
    uVar14 = _DAT_130b720bc78;
    FUN_130b71ea9d0(0x130b7204268);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207fe8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar14);
    uVar24 = 0;
    uVar25 = 0;
    if (local_9d != '\0') {
      uVar24 = (undefined4)_DAT_130b72014a8;
      uVar25 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b7204298);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7207ff8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,CONCAT44(uVar25,uVar24));
    uVar14 = _DAT_130b720bc88;
    FUN_130b71ea9d0(0x130b72042c8);
    FUN_130b71d0a30(&local_b0,0x130b720bb3c,1,0x130b7208008);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_b0,uVar14);
    _DAT_130b720bb10 = 0;
    _DAT_130b720bb80 = 0;
    DAT_130b720bb88 = 0;
    (*(code *)0x7ff63a0edfa0)(0x130b53f81d8);
    if (_DAT_130b720bb10 != 0) {
      (*(code *)0x7ff63a0e49f0)
                (0x130b53f81d8,0xd,2,0x590008,0x130b7204310,0x520004,_DAT_130b720bb10);
    }
  }
  FUN_130b71d0000(&local_b0);
  FUN_130b71d0000(&local_88);
  return;
}



/* Address: 130b71ea9d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71ea9d0(undefined8 param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  uint uVar4;
  char cVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 uVar13;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar14;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar15;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  local_50 = 0;
  local_90 = 0;
  local_80 = 0;
  local_60 = 0;
  local_4c = 0;
  local_8c = 0;
  local_7c = 0;
  local_5c = 0;
  local_70 = 0;
  local_68 = 0;
  FUN_130b71d0a30(&local_70,0x130b720bb28,1,0x130b7208058);
  FUN_130b71d04d0(&local_70,0x130b7204398);
  FUN_130b71d04d0(&local_70,0x130b72043a8);
  FUN_130b71d04d0(&local_70,0x130b72043b8);
  FUN_130b71d04d0(&local_70,0x130b72043c8);
  FUN_130b71d04d0(&local_70,&DAT_130b72043d8);
  uVar8 = 0;
  uVar6 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,5,0x590008,0x130b7203340,0x520004,CONCAT44(uVar13,0x51),0x520004,
             CONCAT44(uVar14,0x54),0x520004,0x41,0x520004,CONCAT44(uVar15,0x5f));
  FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b7208068);
  FUN_130b71d0a30(&local_90,&local_80,0,0x130b7208078);
  uVar4 = _DAT_130b72043e8;
  uVar12 = (ulonglong)_DAT_130b72043e8;
  if ((uVar12 == 0) && (local_8c != 0)) goto LAB_130b71eacb9;
  if (local_8c != 0) {
    uVar8 = *(uint *)(local_8c + -4);
  }
  uVar11 = _DAT_130b72043e8 + uVar8;
  uVar7 = 0x104;
  if ((0x103 < uVar11) &&
     ((0x7ffffffd < uVar11 || (uVar7 = (uVar11 >> 2) + uVar11, 0x7ffffffd < uVar7)))) {
    uVar7 = 0x7ffffffe;
  }
  cVar5 = FUN_130b71d0060(&local_90,uVar7);
  if (cVar5 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x380be9000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar12 != 0) {
    lVar1 = local_8c + (ulonglong)uVar8 * 2;
    if (uVar4 < 0x10) {
      uVar9 = 0;
    }
    else if (lVar1 - 0x130b72043ecU < 0x20) {
      uVar9 = 0;
    }
    else {
      uVar10 = 0;
      uVar9 = (ulonglong)(uVar4 & 0xfffffff8);
      do {
        uVar13 = *(undefined4 *)(uVar10 + 0x130b72043f0);
        uVar14 = *(undefined4 *)(uVar10 + 0x130b72043f4);
        uVar15 = *(undefined4 *)(uVar10 + 0x130b72043f8);
        puVar2 = (undefined4 *)(lVar1 + uVar10);
        *puVar2 = *(undefined4 *)(&DAT_130b72043ec + uVar10);
        puVar2[1] = uVar13;
        puVar2[2] = uVar14;
        puVar2[3] = uVar15;
        uVar10 = uVar10 + 0x10;
      } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar10);
      if (uVar9 == uVar12) goto LAB_130b71eaca2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar9 * 2) = *(undefined2 *)(&DAT_130b72043ec + uVar9 * 2);
      uVar9 = uVar9 + 1;
    } while (uVar12 != uVar9);
  }
LAB_130b71eaca2:
  *(uint *)(local_8c + -4) = uVar11;
  *(undefined2 *)(local_8c + (ulonglong)uVar11 * 2) = 0;
LAB_130b71eacb9:
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,5,0x590008,&local_90,0x550005,uVar6,0x590008,&local_70,0x520004,
             _DAT_130b720bc30,0x590008,param_1);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208088);
  FUN_130b71d0a30(&local_60,&local_50,0,0x130b7208098);
  FUN_130b71d0000(&local_70);
  FUN_130b71d0a30(0x130b720bb3c,&local_60,1,0x130b72080a8);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_80);
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_50);
  return;
}



/* Address: 130b71eade0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71eade0(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_64 = 0;
  local_74 = 0;
  uVar14 = 0;
  FUN_130b71d0a30(&local_78,param_1,0,0x130b72080d8);
  uVar7 = _DAT_130b7204412;
  uVar10 = (ulonglong)_DAT_130b7204412;
  if ((uVar10 != 0) || (local_74 == 0)) {
    if (local_74 != 0) {
      uVar14 = *(uint *)(local_74 + -4);
    }
    uVar11 = _DAT_130b7204412 + uVar14;
    uVar9 = 0x104;
    if ((0x103 < uVar11) &&
       ((0x7ffffffd < uVar11 || (uVar9 = (uVar11 >> 2) + uVar11, 0x7ffffffd < uVar9)))) {
      uVar9 = 0x7ffffffe;
    }
    cVar8 = FUN_130b71d0060(&local_78,uVar9);
    if (cVar8 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250bf9000001f9);
      goto LAB_130b71eb164;
    }
    if (uVar10 != 0) {
      lVar1 = local_74 + (ulonglong)uVar14 * 2;
      if (uVar7 < 0x10) {
        uVar12 = 0;
      }
      else if (lVar1 - 0x130b7204416U < 0x20) {
        uVar12 = 0;
      }
      else {
        uVar13 = 0;
        uVar12 = (ulonglong)(uVar7 & 0xfffffff8);
        do {
          uVar4 = *(undefined4 *)(uVar13 + 0x130b720441a);
          uVar5 = *(undefined4 *)(uVar13 + 0x130b720441e);
          uVar6 = *(undefined4 *)(&DAT_130b7204422 + uVar13);
          puVar2 = (undefined4 *)(lVar1 + uVar13);
          *puVar2 = *(undefined4 *)(&DAT_130b7204416 + uVar13);
          puVar2[1] = uVar4;
          puVar2[2] = uVar5;
          puVar2[3] = uVar6;
          uVar13 = uVar13 + 0x10;
        } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar13);
        if (uVar12 == uVar10) goto LAB_130b71eaf42;
      }
      do {
        *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(&DAT_130b7204416 + uVar12 * 2);
        uVar12 = uVar12 + 1;
      } while (uVar10 != uVar12);
    }
LAB_130b71eaf42:
    *(uint *)(local_74 + -4) = uVar11;
    *(undefined2 *)(local_74 + (ulonglong)uVar11 * 2) = 0;
  }
  FUN_130b71ea9d0(&local_78);
  FUN_130b71d0a30(&local_68,0x130b720bb3c,1,0x130b72080e8);
  (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_68,(double)(param_2 & 0xffffffff));
  uVar14 = 0;
  FUN_130b71d0a30(&local_78,param_1,0,0x130b72080f8);
  uVar7 = _DAT_130b7204422;
  uVar10 = (ulonglong)_DAT_130b7204422;
  if ((uVar10 == 0) && (local_74 != 0)) goto LAB_130b71eb0cd;
  if (local_74 != 0) {
    uVar14 = *(uint *)(local_74 + -4);
  }
  uVar11 = _DAT_130b7204422 + uVar14;
  uVar9 = 0x104;
  if ((0x103 < uVar11) &&
     ((0x7ffffffd < uVar11 || (uVar9 = (uVar11 >> 2) + uVar11, 0x7ffffffd < uVar9)))) {
    uVar9 = 0x7ffffffe;
  }
  cVar8 = FUN_130b71d0060(&local_78,uVar9);
  if (cVar8 == '\0') {
LAB_130b71eb164:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250bfa000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar10 != 0) {
    lVar1 = local_74 + (ulonglong)uVar14 * 2;
    if (uVar7 < 0x10) {
      uVar12 = 0;
    }
    else if (lVar1 - 0x130b7204426U < 0x20) {
      uVar12 = 0;
    }
    else {
      uVar13 = 0;
      uVar12 = (ulonglong)(uVar7 & 0xfffffff8);
      do {
        uVar4 = *(undefined4 *)(uVar13 + 0x130b720442a);
        uVar5 = *(undefined4 *)(uVar13 + 0x130b720442e);
        uVar6 = *(undefined4 *)(uVar13 + 0x130b7204432);
        puVar2 = (undefined4 *)(lVar1 + uVar13);
        *puVar2 = *(undefined4 *)(&DAT_130b7204426 + uVar13);
        puVar2[1] = uVar4;
        puVar2[2] = uVar5;
        puVar2[3] = uVar6;
        uVar13 = uVar13 + 0x10;
      } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar13);
      if (uVar12 == uVar10) goto LAB_130b71eb0c2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(&DAT_130b7204426 + uVar12 * 2);
      uVar12 = uVar12 + 1;
    } while (uVar10 != uVar12);
  }
LAB_130b71eb0c2:
  *(uint *)(local_74 + -4) = uVar11;
  *(undefined2 *)(local_74 + (ulonglong)uVar11 * 2) = 0;
LAB_130b71eb0cd:
  FUN_130b71ea9d0(&local_78);
  FUN_130b71d0a30(&local_68,0x130b720bb3c,1,0x130b7208108);
  (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_68,(double)(param_2 >> 0x20));
  FUN_130b71d0000(&local_78);
  FUN_130b71d0000(&local_68);
  return;
}



/* Address: 130b71eb190 */

undefined8 FUN_130b71eb190(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 local_a0 [12];
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined1 local_80 [12];
  int local_74;
  int local_70;
  int local_6c;
  undefined1 local_60 [12];
  int local_54;
  int local_50;
  int local_4c;
  
  if (DAT_130b720bd50 != '\0') {
    uVar3 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar3,local_a0);
    if (local_88 != 5) {
      return 0;
    }
    local_a8 = 0;
    local_b0 = 0;
    cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,5,0,&local_a8,&local_b0);
    if (cVar1 != '\0') {
      uVar7 = 0xffffffff;
      iVar8 = 1;
      do {
        (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_a8,local_60);
        (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_b0,local_80);
        iVar2 = local_50 * 0x3c + local_54 * 0xe10 + local_4c;
        iVar5 = local_70 * 0x3c + local_74 * 0xe10;
        uVar6 = iVar5 + local_6c;
        uVar4 = uVar6;
        if ((int)uVar6 < iVar2) {
          uVar4 = local_6c + 0x15180 + iVar5;
        }
        local_a8 = 0;
        local_b0 = 0;
        uVar10 = uVar4;
        if (0 < iVar2) {
          uVar10 = 0x15180;
        }
        if (uVar6 != 0) {
          uVar10 = uVar4;
        }
        if ((int)uVar7 < (int)uVar10) {
          uVar7 = uVar10;
        }
        cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,5,iVar8,&local_a8,&local_b0);
        iVar8 = iVar8 + 1;
      } while (cVar1 != '\0');
      uVar9 = 0;
      if ((int)uVar7 < 0) {
        return 0;
      }
      uVar6 = uVar7 - 0xe10;
      if (DAT_130b720b798 == '\0') {
        uVar6 = uVar7;
      }
      if (0 < (int)uVar6) {
        uVar9 = (ulonglong)uVar6;
      }
      return CONCAT71((int7)(uVar9 >> 8),(int)uVar9 <= local_90 * 0x3c + local_94 * 0xe10 + local_8c
                     );
    }
  }
  return 0;
}



/* Address: 130b71eb3a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71eb3a0(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  
  iVar7 = _DAT_130b720bcb8;
  if (0 < (int)_DAT_130b720b418) {
    uVar13 = 0;
    iVar1 = _DAT_130b720bcb8 + 100;
    uVar9 = _DAT_130b720b418;
    do {
      if (uVar9 <= (uint)uVar13) {
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xd0958000001f6);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      lVar11 = uVar13 * 0x62;
      if (*(char *)(_DAT_130b720b42c + 0x5c + lVar11) != '\0') {
        lVar5 = *(longlong *)(_DAT_130b720b42c + 8 + lVar11);
        if (lVar5 == _DAT_130b720bb2c) {
LAB_130b71eb4a8:
          iVar10 = *(int *)(_DAT_130b720b42c + 0x40 + lVar11);
          if ((iVar7 <= iVar10) && (iVar10 < iVar1)) {
            *(undefined1 *)(_DAT_130b720b42c + 0x5c + lVar11) = 0;
            uVar9 = _DAT_130b720b418;
          }
        }
        else if ((lVar5 != 0) && (_DAT_130b720bb2c != 0)) {
          uVar12 = *(uint *)(lVar5 + -4);
          uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
          uVar8 = uVar4;
          if (uVar12 < uVar4) {
            uVar8 = uVar12;
          }
          iVar10 = uVar12 - uVar4;
          if (uVar8 != 0) {
            uVar14 = 1;
            do {
              uVar2 = *(ushort *)(lVar5 + -2 + uVar14 * 2);
              uVar3 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar14 * 2);
              if (uVar8 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar2 == uVar3);
            if (uVar2 != uVar3) {
              iVar10 = (uint)uVar2 - (uint)uVar3;
            }
          }
          if (iVar10 == 0) goto LAB_130b71eb4a8;
        }
      }
      uVar12 = (uint)uVar13 + 1;
      uVar13 = (ulonglong)uVar12;
    } while ((int)uVar12 < (int)uVar9);
  }
  return;
}



/* Address: 130b71eb510 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71eb510(undefined8 param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined4 local_58;
  longlong local_54;
  undefined8 local_48;
  
  local_58 = 0;
  local_54 = 0;
  local_48 = param_1;
  iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
  if (-1 < iVar8 + -1) {
    lVar13 = (longlong)_DAT_130b720bc30;
    iVar8 = iVar8 + -1;
    do {
      lVar9 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
      if (lVar9 != 0) {
        cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar9);
        if (cVar7 != '\0') {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_58,0x130b720bb3c,1,0x130b7208018);
          if (local_54 == _DAT_130b720bb2c) {
LAB_130b71eb688:
            lVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if (lVar10 == lVar13) {
              FUN_130b71e82f0(lVar9,local_48);
            }
          }
          else if ((local_54 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar3 = *(uint *)(local_54 + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar11 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar12 = 1;
              do {
                uVar1 = *(ushort *)(local_54 + -2 + uVar12 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar12 * 2);
                if (uVar6 <= uVar12) break;
                uVar12 = uVar12 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar11 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar11 == 0) goto LAB_130b71eb688;
          }
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  FUN_130b71d0000(&local_58);
  return;
}



/* Address: 130b71eb6f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71eb6f0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined4 local_50;
  longlong local_4c;
  
  local_50 = 0;
  local_4c = 0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
  if (-1 < iVar8 + -1) {
    lVar14 = (longlong)_DAT_130b720bcb8;
    iVar9 = _DAT_130b720bcb8 + 100;
    iVar8 = iVar8 + -1;
    do {
      lVar10 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar8);
      if (lVar10 != 0) {
        cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar10);
        if (cVar7 != '\0') {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208028);
          if (local_4c == _DAT_130b720bb2c) {
LAB_130b71eb868:
            lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if ((lVar14 <= lVar11) && (lVar11 < iVar9)) {
              FUN_130b71e6960(lVar10,0);
            }
          }
          else if ((local_4c != 0) && (_DAT_130b720bb2c != 0)) {
            uVar3 = *(uint *)(local_4c + -4);
            uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar12 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar13 = 1;
              do {
                uVar1 = *(ushort *)(local_4c + -2 + uVar13 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar13 * 2);
                if (uVar6 <= uVar13) break;
                uVar13 = uVar13 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar12 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar12 == 0) goto LAB_130b71eb868;
          }
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  FUN_130b71d0000(&local_50);
  return;
}



/* Address: 130b71eb8d0 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71eb8d0(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  char *pcVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  int iVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  uint uVar20;
  uint uVar21;
  longlong lVar22;
  ulonglong uVar23;
  bool bVar24;
  bool bVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  undefined8 uVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 *in_stack_fffffffffffffdb8;
  undefined4 uVar39;
  undefined4 *in_stack_fffffffffffffdd8;
  undefined8 in_stack_fffffffffffffde8;
  undefined4 uVar40;
  double in_stack_fffffffffffffdf8;
  double in_stack_fffffffffffffe08;
  undefined4 uVar41;
  undefined4 local_198;
  longlong local_194;
  ulonglong local_188;
  ulonglong local_180;
  longlong local_178;
  longlong local_170;
  longlong local_168;
  ulonglong local_160;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  ulonglong local_148;
  double local_140;
  double local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined8 local_124;
  undefined8 local_118;
  ulonglong local_110;
  undefined1 local_108 [12];
  int local_fc;
  int local_f8;
  
  FUN_130b71e0640();
  if (((param_1 != '\0') && (FUN_130b71e1710(), DAT_130b720b8c0 == '\0')) &&
     (iVar5 = FUN_130b71e0270(), iVar5 < (int)(uint)DAT_130b720b729)) {
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
    dVar31 = _DAT_130b720bb48;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
    iVar5 = _DAT_130b720bcd0;
    dVar28 = _DAT_130b720bb48;
    uVar15 = _DAT_130b72014c0;
    dVar30 = _DAT_130b72014b8;
    uVar20 = _DAT_130b720b418 - 1;
    if (-1 < (int)uVar20) {
      uVar37 = (undefined4)_DAT_130b72014b0;
      uVar38 = (undefined4)((ulonglong)_DAT_130b72014b0 >> 0x20);
      local_160 = _DAT_130b720bcf8;
      local_110 = (ulonglong)_DAT_130b720bcd8;
      uVar35 = (undefined4)_DAT_130b720bce0;
      uVar36 = (undefined4)((ulonglong)_DAT_130b720bce0 >> 0x20);
      local_148 = _DAT_130b720bcf0;
      local_170 = _DAT_130b720bce8;
LAB_130b71ebae4:
      lVar22 = (ulonglong)uVar20 * 0x62;
      if (*(char *)(_DAT_130b720b42c + 0x5c + lVar22) != '\0') {
        lVar10 = *(longlong *)(_DAT_130b720b42c + 8 + lVar22);
        if (lVar10 != _DAT_130b720bb2c) {
          if ((lVar10 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar8 = *(uint *)(lVar10 + -4);
            uVar7 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar21 = uVar7;
            if (uVar8 < uVar7) {
              uVar21 = uVar8;
            }
            iVar6 = uVar8 - uVar7;
            if (uVar21 != 0) {
              uVar23 = 1;
              do {
                uVar1 = *(ushort *)(lVar10 + -2 + uVar23 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar23 * 2);
                if (uVar21 <= uVar23) break;
                uVar23 = uVar23 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar6 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar6 == 0) goto LAB_130b71ebb90;
          }
          goto LAB_130b71ebad0;
        }
LAB_130b71ebb90:
        dVar32 = *(double *)(_DAT_130b720b42c + 0x1c + lVar22);
        bVar24 = dVar28 <= dVar32;
        if (*(int *)(_DAT_130b720b42c + 0x10 + lVar22) == 4) {
          bVar24 = dVar32 <= dVar31;
        }
        if ((int)_DAT_130b720b418 <= (int)uVar20) goto LAB_130b71ebad0;
        if (*(char *)(_DAT_130b720b42c + 0x5d + lVar22) != '\0') {
          iVar6 = *(int *)(_DAT_130b720b42c + 0x5e + lVar22);
          if (0 < iVar6) {
            *(int *)(_DAT_130b720b42c + 0x5e + lVar22) = iVar6 + -1;
            if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eedf6;
            if (0 < *(int *)(_DAT_130b720b42c + 0x5e + lVar22)) goto LAB_130b71ebad0;
          }
LAB_130b71ebcb2:
          bVar24 = true;
          local_158 = 0;
          local_128 = 0;
          uStack_154 = 0;
          uStack_150 = 0;
          local_124 = 0;
          if ((int)uVar20 < (int)_DAT_130b720b418) {
            if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eee16;
            if (((*(char *)(_DAT_130b720b42c + 0x5c + lVar22) != '\0') && (DAT_130b720b8c0 == '\0'))
               && ((iVar6 = FUN_130b71e0270(), iVar6 < (int)(uint)DAT_130b720b729 &&
                   (cVar4 = FUN_130b71e6fc0(), cVar4 == '\0')))) {
              if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eeed6;
              iVar6 = *(int *)(_DAT_130b720b42c + 0x10 + lVar22);
              (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
              (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
              local_180 = CONCAT44(local_180._4_4_,iVar6);
              if (iVar6 == 4) {
                if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eeef6;
              }
              else if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eef16;
              local_140 = *(double *)(_DAT_130b720b42c + 0x2c + lVar22);
              local_168 = (longlong)*(int *)(_DAT_130b720b42c + 0x40 + lVar22);
              uVar29 = *(undefined8 *)(_DAT_130b720b42c + 0x1c + lVar22);
              local_188 = CONCAT71(local_188._1_7_,iVar6 != 4);
              if (local_140 <= 0.0) {
LAB_130b71ebfcc:
                _DAT_130b720b6e5 = local_168;
                uVar23 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b720bb28,0x32);
                uVar16 = 0;
                if (((uVar23 & 1) != 0) || (uVar16 = 1, (uVar23 & 2) != 0)) {
                  _DAT_130b720b6f5 = uVar16;
                }
                dVar26 = (double)(int)(_DAT_130b720b7a8 * (double)CONCAT44(uVar38,uVar37));
                dVar32 = 0.0;
                if (0.0 <= dVar26) {
                  dVar32 = dVar26;
                }
                _DAT_130b720b6ed =
                     (longlong)(dVar32 - dVar30) & (longlong)dVar32 >> 0x3f | (longlong)dVar32;
                if ((iVar5 == 3) && (_DAT_130b720b390 = uVar15, (uint)local_110 < 8)) {
                  _DAT_130b720b390 = *(undefined8 *)(local_110 * 8 + 0x130b7209eb0);
                }
                local_188 = CONCAT44(local_188._4_4_,(uint)(byte)local_188);
                lVar10 = _DAT_130b720b398;
                dVar32 = (double)FUN_130b71ef790(iVar5,CONCAT44(uVar36,uVar35),local_170,local_148,
                                                 local_160,_DAT_130b720b398,_DAT_130b720b390);
                cVar4 = FUN_130b71e7bd0(local_188 & 0xffffffff);
                if (cVar4 != '\0') {
                  DAT_130b720b8c0 = '\x01';
                  FUN_130b71d0a30(0x130b720b8c1,0x130b720bb28,0,0x130b7207b38);
                  iVar6 = (int)local_180;
                  _DAT_130b720b8cd = local_168;
                  _DAT_130b720b8d5 = (int)local_180;
                  _DAT_130b720b8d9 = (undefined4)uVar29;
                  _DAT_130b720b8dd = (undefined4)((ulonglong)uVar29 >> 0x20);
                  _DAT_130b720b8e1 = SUB84(local_140,0);
                  _DAT_130b720b8e5 = (undefined4)((ulonglong)local_140 >> 0x20);
                  uVar9 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
                  _DAT_130b720b8e9 = (undefined4)uVar9;
                  _DAT_130b720b8ed = (undefined4)((ulonglong)uVar9 >> 0x20);
                  _DAT_130b720b8f9 = 0;
                  _DAT_130b720b8fd = 0;
                  _DAT_130b720b8f1 = 0;
                  _DAT_130b720b8f5 = 0;
                  _DAT_130b720b901 = 0;
                  _DAT_130b720b905 = 0;
                  FUN_130b71e4e30();
                  lVar11 = _DAT_130b720b42c;
                  _DAT_130b720bb10 = 0;
                  _DAT_130b720bb80 = 0;
                  DAT_130b720bb88 = 0;
                  if (iVar6 == 4) {
                    if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eef56;
                    if (dVar32 <= 0.0) goto LAB_130b71ec3e8;
                    uVar9 = *(undefined8 *)(_DAT_130b720b42c + 0x24 + lVar22);
                    local_198 = 0;
                    local_194 = 0;
                    FUN_130b71d0a30(&local_198,0x130b720bb28,0,0x130b72069c8);
                    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_198,4);
                    uVar19 = 0;
LAB_130b71ec3bf:
                    lVar10 = lVar11 + 0x34 + lVar22;
                    cVar4 = FUN_130b71dc710(&local_198,uVar19,dVar32,_DAT_130b720bb48,uVar9,lVar10);
                    FUN_130b71d0000(&local_198);
                  }
                  else {
                    if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eef36;
                    if (0.0 < dVar32) {
                      uVar9 = *(undefined8 *)(_DAT_130b720b42c + 0x24 + lVar22);
                      local_198 = 0;
                      local_194 = 0;
                      FUN_130b71d0a30(&local_198,0x130b720bb28,0,0x130b72069d8);
                      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,&local_198,1);
                      uVar19 = 1;
                      goto LAB_130b71ec3bf;
                    }
LAB_130b71ec3e8:
                    cVar4 = '\0';
                    _DAT_130b720b560 = 0x271e;
                  }
                  uVar39 = (undefined4)((ulonglong)in_stack_fffffffffffffdb8 >> 0x20);
                  uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffde8 >> 0x20);
                  uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffe08 >> 0x20);
                  uVar16 = (undefined4)((ulonglong)lVar10 >> 0x20);
                  if ((cVar4 == '\0') || (2 < _DAT_130b720b560 - 0x2718)) {
                    local_168 = CONCAT44(local_168._4_4_,_DAT_130b720bb10);
                    local_188 = (ulonglong)_DAT_130b720b560;
                    if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eef76;
                    uVar9 = *(undefined8 *)(_DAT_130b720b42c + 0x24 + lVar22);
                    local_198 = 0;
                    local_194 = 0;
                    local_138 = 0.0;
                    local_130 = 0;
                    local_178 = CONCAT44(local_178._4_4_,_DAT_130b720b7b0);
                    FUN_130b71dbd30(&local_138,&DAT_130b720b470,&DAT_130b720b560);
                    FUN_130b71d0a30(&local_198,&local_138,0,0x130b7206928);
                    FUN_130b71d0000(&local_138);
                    bVar24 = true;
                    FUN_130b71d0a30(0x130b720bb3c,&local_198,1,0x130b7206938);
                    FUN_130b71d0000(&local_198);
                    in_stack_fffffffffffffdd8 = &local_128;
                    FUN_130b71d0a30(in_stack_fffffffffffffdd8,0x130b720bb3c,1,0x130b7207c68);
                    uVar19 = 0x130b7203778;
                    if (cVar4 != '\0') {
                      uVar19 = 0x130b7203748;
                    }
                    in_stack_fffffffffffffe08 = (double)CONCAT44(uVar41,(undefined4)local_178);
                    in_stack_fffffffffffffde8 = CONCAT44(uVar40,(int)local_180);
                    in_stack_fffffffffffffdb8 = (undefined4 *)CONCAT44(uVar39,(undefined4)local_168)
                    ;
                    (*(code *)0x7ff63a0e49f0)
                              (0x130b53f81d8,0xd,0xd,0x590008,0x130b7203b50,
                               CONCAT44(uVar16,0x590008),uVar19,0x520004,in_stack_fffffffffffffdb8,
                               0x530014,(int)local_188,0x590008,in_stack_fffffffffffffdd8,0x520004,
                               in_stack_fffffffffffffde8,0x580007,dVar32,0x520004,
                               in_stack_fffffffffffffe08,0x580007,uVar29,0x520004,
                               (undefined4)local_178,0x580007,uVar9,0x520004,(undefined4)local_178,
                               0x580007,local_140);
                    DAT_130b720b8c0 = '\0';
                    FUN_130b71d0a30(0x130b720b8c1,0x130b7201870,0,0x130b7207b28);
                    _DAT_130b720b8fd = 0;
                    _DAT_130b720b901 = 0;
                    _DAT_130b720b8f5 = 0;
                    _DAT_130b720b8f9 = 0;
                    _DAT_130b720b905 = 0;
                    _DAT_130b720b8ed = 0;
                    _DAT_130b720b8f1 = 0;
                    _DAT_130b720b8e5 = 0;
                    _DAT_130b720b8e9 = 0;
                    _DAT_130b720b8dd = 0;
                    _DAT_130b720b8e1 = 0;
                    _DAT_130b720b8d5 = 0;
                    _DAT_130b720b8d9 = 0;
                    _DAT_130b720b8cd = 0;
                    FUN_130b71e4c00();
                    in_stack_fffffffffffffdf8 = dVar32;
                  }
                  else {
                    if (DAT_130b720b8c0 != '\0') {
                      _DAT_130b720b8f1 = (undefined4)_DAT_130b720b56c;
                      _DAT_130b720b8f5 = (undefined4)((ulonglong)_DAT_130b720b56c >> 0x20);
                      _DAT_130b720b8f9 = (undefined4)_DAT_130b720b564;
                      _DAT_130b720b8fd = (undefined4)((ulonglong)_DAT_130b720b564 >> 0x20);
                      if (((_DAT_130b720b564 != 0) &&
                          (cVar4 = (*(code *)0x7ff63a108af0)(0x130b53f81d8), cVar4 != '\0')) &&
                         (lVar11 = (*(code *)0x7ff63a108940)
                                             (0x130b53f81d8,
                                              CONCAT44(_DAT_130b720b8fd,_DAT_130b720b8f9),0xc),
                         0 < lVar11)) {
                        _DAT_130b720b901 = (undefined4)lVar11;
                        _DAT_130b720b905 = (undefined4)((ulonglong)lVar11 >> 0x20);
                      }
                      FUN_130b71e4e30();
                    }
                    lVar11 = _DAT_130b720b564;
                    local_198 = 0;
                    local_194 = 0;
                    if (((_DAT_130b720b564 != 0) &&
                        (cVar4 = (*(code *)0x7ff63a108af0)(0x130b53f81d8,_DAT_130b720b564),
                        cVar4 != '\0')) &&
                       ((local_180 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar11,0xc),
                        0 < (longlong)local_180 &&
                        (iVar6 = (*(code *)0x7ff63a107da0)(0x130b53f81d8), -1 < iVar6 + -1)))) {
                      do {
                        iVar6 = iVar6 + -1;
                        uVar23 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar6);
                        if (((uVar23 != 0) &&
                            (local_188 = uVar23,
                            cVar4 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar23), cVar4 != '\0'))
                           && (uVar23 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd),
                              uVar23 == local_180)) {
                          FUN_130b71d0000(&local_198);
                          goto LAB_130b71ecb3a;
                        }
                      } while (0 < iVar6);
                    }
                    iVar6 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
                    uVar16 = (undefined4)((ulonglong)lVar10 >> 0x20);
                    uVar39 = (undefined4)((ulonglong)in_stack_fffffffffffffdd8 >> 0x20);
                    uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffdf8 >> 0x20);
                    if (iVar6 + -1 < 0) {
                      FUN_130b71d0000(&local_198);
LAB_130b71ecb61:
                      uVar8 = _DAT_130b720b7b0;
                      (*(code *)0x7ff63a0ff6c0)
                                (0x130b53f81d8,CONCAT44(_DAT_130b720b8fd,_DAT_130b720b8f9),0x56,
                                 &local_128);
                      (*(code *)0x7ff63a0ff6c0)
                                (0x130b53f81d8,CONCAT44(_DAT_130b720b8f5,_DAT_130b720b8f1),0x56,
                                 &local_158);
                      in_stack_fffffffffffffdb8 = &local_128;
                      in_stack_fffffffffffffdf8 = (double)CONCAT44(uVar40,uVar8);
                      in_stack_fffffffffffffdd8 = (undefined4 *)CONCAT44(uVar39,uVar8);
                      in_stack_fffffffffffffe08 = local_140;
                      (*(code *)0x7ff63a0e49f0)
                                (0x130b53f81d8,0xd,8,0x590008,0x130b7203bc0,
                                 CONCAT44(uVar16,0x590008),&local_158,0x590008,
                                 in_stack_fffffffffffffdb8,0x520004,(int)local_168,0x520004,
                                 in_stack_fffffffffffffdd8,0x580007,uVar29,0x520004,
                                 in_stack_fffffffffffffdf8,0x580007,local_140);
                    }
                    else {
                      local_178 = -1;
                      local_188 = 0;
                      iVar6 = iVar6 + -1;
                      do {
                        uVar23 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar6);
                        if ((uVar23 != 0) &&
                           (local_180 = uVar23,
                           cVar4 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar23), cVar4 != '\0'))
                        {
                          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
                          FUN_130b71d0a30(&local_198,0x130b720bb3c,1,0x130b7207958);
                          if (local_194 == _DAT_130b720bb2c) {
LAB_130b71ec6c3:
                            lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
                            if ((lVar11 == local_168) &&
                               (lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xe),
                               local_178 < lVar11)) {
                              local_188 = local_180;
                              local_178 = lVar11;
                            }
                          }
                          else if ((local_194 != 0) && (_DAT_130b720bb2c != 0)) {
                            uVar8 = *(uint *)(local_194 + -4);
                            uVar7 = *(uint *)(_DAT_130b720bb2c + -4);
                            uVar21 = uVar7;
                            if (uVar8 < uVar7) {
                              uVar21 = uVar8;
                            }
                            iVar17 = uVar8 - uVar7;
                            if (uVar21 != 0) {
                              uVar23 = 1;
                              do {
                                uVar1 = *(ushort *)(local_194 + -2 + uVar23 * 2);
                                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar23 * 2);
                                if (uVar21 <= uVar23) break;
                                uVar23 = uVar23 + 1;
                              } while (uVar1 == uVar2);
                              if (uVar1 != uVar2) {
                                iVar17 = (uint)uVar1 - (uint)uVar2;
                              }
                            }
                            if (iVar17 == 0) goto LAB_130b71ec6c3;
                          }
                        }
                        uVar16 = (undefined4)((ulonglong)lVar10 >> 0x20);
                        bVar24 = 0 < iVar6;
                        iVar6 = iVar6 + -1;
                      } while (bVar24);
                      FUN_130b71d0000(&local_198);
                      uVar39 = (undefined4)((ulonglong)in_stack_fffffffffffffdd8 >> 0x20);
                      uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffdf8 >> 0x20);
                      if (local_188 == 0) goto LAB_130b71ecb61;
LAB_130b71ecb3a:
                      FUN_130b71e5190(local_188,0);
                      uVar29 = in_stack_fffffffffffffde8;
                    }
                    if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eef96;
                    bVar24 = false;
                    *(undefined1 *)(_DAT_130b720b42c + 0x5c + lVar22) = 0;
                    in_stack_fffffffffffffde8 = uVar29;
                  }
                }
              }
              else {
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b720bb28,0x10);
                dVar32 = _DAT_130b720bb48;
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b720bb28,1);
                dVar26 = _DAT_130b720bb48;
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b720bb28,4);
                dVar27 = _DAT_130b720bb48;
                if ((0.0 < dVar32) && (0.0 < dVar26)) {
                  local_178 = CONCAT44(uVar38,uVar37);
                  local_118 = CONCAT44(uVar36,uVar35);
                  if (0.0 < _DAT_130b720bb48) {
                    lVar10 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b720bb28,0x1f);
                    lVar11 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b720bb28,0x20);
                    uVar35 = (undefined4)local_118;
                    uVar36 = (undefined4)((ulonglong)local_118 >> 0x20);
                    dVar34 = (double)lVar10;
                    if ((double)lVar10 <= (double)lVar11) {
                      dVar34 = (double)lVar11;
                    }
                    dVar32 = dVar32 * dVar34;
                    uVar37 = (undefined4)local_178;
                    uVar38 = (undefined4)((ulonglong)local_178 >> 0x20);
                    bVar25 = local_140 <= dVar26 + dVar32;
                    if ((int)local_180 != 4) {
                      bVar25 = dVar27 - dVar32 <= local_140;
                    }
                    if (!bVar25) goto LAB_130b71ebfcc;
                  }
                }
              }
            }
          }
          FUN_130b71d0000(&local_128);
          FUN_130b71d0000(&local_158);
          if (((int)uVar20 < 1) || (!bVar24)) goto LAB_130b71eccc8;
          goto LAB_130b71ebad8;
        }
        if (bVar24) {
          iVar6 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
          if (iVar6 == 0) goto LAB_130b71ebcb2;
          if (uVar20 < _DAT_130b720b418) {
            iVar6 = *(int *)(_DAT_130b720b42c + lVar22);
            lVar10 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
            uVar23 = lVar10 * 0x3039 + 0x9e3779b1 + (longlong)iVar6 * 0x41c64e6d;
            if (uVar20 < _DAT_130b720b418) {
              *(undefined1 *)(_DAT_130b720b42c + 0x5d + lVar22) = 1;
              if (uVar20 < _DAT_130b720b418) {
                *(int *)(_DAT_130b720b42c + 0x5e + lVar22) =
                     (int)uVar23 + (int)(uVar23 / 3) * -3 + 1;
                goto LAB_130b71ebad0;
              }
              goto LAB_130b71eee96;
            }
            goto LAB_130b71eee76;
          }
          goto LAB_130b71eee56;
        }
      }
LAB_130b71ebad0:
      if ((int)uVar20 < 1) goto LAB_130b71eccc8;
LAB_130b71ebad8:
      uVar20 = uVar20 - 1;
      if (_DAT_130b720b418 <= uVar20) goto LAB_130b71eed76;
      goto LAB_130b71ebae4;
    }
  }
LAB_130b71eccc8:
  lVar22 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,1,0);
  if (lVar22 != _DAT_130b720b710) {
    local_198 = 0;
    local_148 = CONCAT71(local_148._1_7_,param_1);
    local_194 = 0;
    _DAT_130b720b710 = lVar22;
    iVar5 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
    if (-1 < iVar5 + -1) {
      lVar22 = (longlong)_DAT_130b720bcb8;
      local_160 = (ulonglong)(_DAT_130b720bcb8 + 100);
      iVar5 = iVar5 + -1;
      local_170 = lVar22;
      do {
        lVar10 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar5);
        if ((lVar10 != 0) &&
           (cVar4 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar10), cVar4 != '\0')) {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_198,0x130b720bb3c,1,0x130b7207c98);
          if (local_194 == _DAT_130b720bb2c) {
LAB_130b71ececc:
            lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if (((lVar22 <= lVar11) && (lVar11 < (longlong)local_160)) &&
               (cVar4 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar10), cVar4 != '\0')) {
              lVar11 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2);
              (*(code *)0x7ff63a107f70)(0x130b53f81d8,4);
              dVar30 = _DAT_130b720bb48;
              if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                dVar30 = (double)(longlong)_DAT_130b720bb48;
                uVar23 = (ulonglong)_DAT_130b720b7b0;
                if (10 < _DAT_130b720b7b0) {
                  uVar23 = 0xb;
                }
                dVar30 = (double)(longlong)
                                 ((_DAT_130b720bb48 - dVar30) *
                                  *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                 *(double *)
                                  ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72014c8)) /
                         *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar30;
              }
              (*(code *)0x7ff63a107f70)(0x130b53f81d8,6);
              dVar31 = _DAT_130b720bb48;
              if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                dVar31 = (double)(longlong)_DAT_130b720bb48;
                uVar23 = (ulonglong)_DAT_130b720b7b0;
                if (10 < _DAT_130b720b7b0) {
                  uVar23 = 0xb;
                }
                dVar31 = (double)(longlong)
                                 ((_DAT_130b720bb48 - dVar31) *
                                  *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                 *(double *)
                                  ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72014c8)) /
                         *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar31;
              }
              lVar22 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,1);
              local_138 = 0.0;
              local_158 = 0;
              uStack_154 = 0;
              FUN_130b71e37c0(lVar10,&local_138,&local_158);
              uVar38 = uStack_154;
              uVar37 = local_158;
              if (local_138 <= 0.0) {
                local_138 = dVar30;
              }
              if (dVar31 <= 0.0) {
                uVar35 = SUB84(_DAT_130b720b7dc,0);
                uVar36 = (undefined4)((ulonglong)_DAT_130b720b7dc >> 0x20);
                if (lVar11 == 0) {
                  uVar35 = (undefined4)((ulonglong)_DAT_130b720b7dc ^ _DAT_130b72014e0);
                  uVar36 = (undefined4)(((ulonglong)_DAT_130b720b7dc ^ _DAT_130b72014e0) >> 0x20);
                }
                dVar31 = (double)CONCAT44(uVar36,uVar35) + dVar30;
                if ((longlong)dVar31 != -0x8000000000000000) {
                  dVar28 = (double)(longlong)dVar31;
                  uVar23 = (ulonglong)_DAT_130b720b7b0;
                  if (10 < _DAT_130b720b7b0) {
                    uVar23 = 0xb;
                  }
                  dVar31 = (double)(longlong)
                                   ((dVar31 - dVar28) * *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar31) * 8 + 0x130b72014c8)) /
                           *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar28;
                }
                FUN_130b71e5c50(lVar10,dVar31,CONCAT44(uStack_154,local_158));
              }
              dVar28 = (double)CONCAT44(uVar38,uVar37);
              if (dVar28 <= 0.0) {
                uVar37 = SUB84(_DAT_130b720b7e4,0);
                uVar38 = (undefined4)((ulonglong)_DAT_130b720b7e4 >> 0x20);
                if (lVar11 != 0) {
                  uVar37 = (undefined4)((ulonglong)_DAT_130b720b7e4 ^ _DAT_130b72014e0);
                  uVar38 = (undefined4)(((ulonglong)_DAT_130b720b7e4 ^ _DAT_130b72014e0) >> 0x20);
                }
                dVar28 = (double)CONCAT44(uVar38,uVar37) + dVar30;
                if ((longlong)dVar28 != -0x8000000000000000) {
                  dVar32 = (double)(longlong)dVar28;
                  uVar23 = (ulonglong)_DAT_130b720b7b0;
                  if (10 < _DAT_130b720b7b0) {
                    uVar23 = 0xb;
                  }
                  dVar28 = (double)(longlong)
                                   ((dVar28 - dVar32) * *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar28) * 8 + 0x130b72014c8)) /
                           *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar32;
                }
                local_158 = SUB84(dVar28,0);
                uStack_154 = (undefined4)((ulonglong)dVar28 >> 0x20);
                FUN_130b71e5c50(lVar10,dVar31,dVar28);
              }
              (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
              dVar32 = _DAT_130b720bb48;
              (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
              dVar26 = _DAT_130b720bb48;
              lVar12 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,1,1);
              lVar13 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,1,0);
              if (lVar11 == 0) {
                if ((lVar22 >= lVar13 || lVar12 > lVar22) || (lVar12 >= lVar13 || 0 >= lVar12)) {
LAB_130b71ed402:
                  lVar12 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,0xf,1);
                  lVar13 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,0xf,0);
                  if (((0 < lVar12) && ((lVar12 < lVar13 && (lVar12 <= lVar22)))) &&
                     (lVar22 < lVar13)) {
                    (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,0xf,1);
                    dVar27 = _DAT_130b720bb48;
                    (*(code *)0x7ff63a103d40)(0x130b53f81d8,0x130b7201850,0xf,1);
                    if ((_DAT_130b720bb48 < dVar27) && (_DAT_130b720bb48 < dVar30))
                    goto LAB_130b71ecdac;
                  }
                  goto LAB_130b71ed4c7;
                }
                (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,1,1);
                dVar27 = _DAT_130b720bb48;
                (*(code *)0x7ff63a103d40)(0x130b53f81d8,0x130b7201850,1,1);
                if ((dVar27 <= _DAT_130b720bb48) || (dVar30 <= _DAT_130b720bb48))
                goto LAB_130b71ed402;
                goto LAB_130b71ecdac;
              }
              if ((lVar22 < lVar13 && lVar12 <= lVar22) && (lVar12 < lVar13 && 0 < lVar12)) {
                (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,1,1);
                dVar27 = _DAT_130b720bb48;
                (*(code *)0x7ff63a103d40)(0x130b53f81d8,0x130b7201850,1,1);
                if (((lVar11 == 1) && (dVar27 < _DAT_130b720bb48)) && (dVar30 < _DAT_130b720bb48))
                goto LAB_130b71ecdac;
              }
              lVar12 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,0xf,1);
              lVar13 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,0xf,0);
              if (((0 < lVar12) && (lVar12 < lVar13)) && ((lVar12 <= lVar22 && (lVar22 < lVar13))))
              {
                (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,0xf,1);
                dVar27 = _DAT_130b720bb48;
                (*(code *)0x7ff63a103d40)(0x130b53f81d8,0x130b7201850,0xf,1);
                if (((lVar11 == 1) && (dVar27 < _DAT_130b720bb48)) && (dVar30 < _DAT_130b720bb48))
                goto LAB_130b71ecdac;
              }
LAB_130b71ed4c7:
              if (_DAT_130b720b408 <= 0.0) {
LAB_130b71ed7d1:
                uVar23 = (ulonglong)(int)_DAT_130b720b888;
                if (0 < (longlong)uVar23) {
                  uVar18 = 0;
                  pcVar14 = (char *)(_DAT_130b720b89c + 0x10);
                  do {
                    if ((*pcVar14 != '\0') && (*(longlong *)(pcVar14 + -0x10) == lVar10)) {
                      if (-1 < (int)(uint)uVar18) {
                        if (_DAT_130b720b888 <= (uint)uVar18) goto LAB_130b71eeeb6;
                        dVar27 = *(double *)(pcVar14 + -8);
                        goto LAB_130b71ed94c;
                      }
                      break;
                    }
                    uVar18 = uVar18 + 1;
                    pcVar14 = pcVar14 + 0x11;
                  } while (_DAT_130b720b888 != uVar18);
                }
                uVar37 = SUB84(_DAT_130b720b7dc,0);
                uVar38 = (undefined4)((ulonglong)_DAT_130b720b7dc >> 0x20);
                if (lVar11 == 0) {
                  uVar37 = (undefined4)((ulonglong)_DAT_130b720b7dc ^ _DAT_130b72014e0);
                  uVar38 = (undefined4)(((ulonglong)_DAT_130b720b7dc ^ _DAT_130b72014e0) >> 0x20);
                }
                dVar27 = (double)CONCAT44(uVar38,uVar37) + dVar30;
                if ((longlong)dVar27 != -0x8000000000000000) {
                  dVar34 = (double)(longlong)dVar27;
                  uVar18 = (ulonglong)_DAT_130b720b7b0;
                  if (10 < _DAT_130b720b7b0) {
                    uVar18 = 0xb;
                  }
                  dVar27 = (double)(longlong)
                                   ((dVar27 - dVar34) * *(double *)(&DAT_130b7201710 + uVar18 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8)) /
                           *(double *)(&DAT_130b7201710 + uVar18 * 8) + dVar34;
                }
                (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b880,_DAT_130b720b888 + 1,0);
                if (_DAT_130b720b888 <= uVar23) goto LAB_130b71eed96;
                lVar22 = uVar23 * 0x11;
                *(longlong *)(_DAT_130b720b89c + lVar22) = lVar10;
                if (_DAT_130b720b888 <= uVar23) goto LAB_130b71eedb6;
                *(double *)(_DAT_130b720b89c + 8 + lVar22) = dVar27;
                if (_DAT_130b720b888 <= uVar23) goto LAB_130b71eedd6;
                *(undefined1 *)(_DAT_130b720b89c + 0x10 + lVar22) = 1;
LAB_130b71ed94c:
                lVar22 = local_170;
                dVar34 = _DAT_130b720b7ec;
                if ((lVar11 != 0 || dVar27 <= dVar32) && (lVar11 != 1 || dVar26 <= dVar27)) {
                  if (lVar11 == 0) {
                    if (0.0 < _DAT_130b720b7ec) {
                      dVar27 = _DAT_130b720b7a0 + dVar31 + _DAT_130b720b7f4 + _DAT_130b720b7ec;
                      if ((longlong)dVar27 != -0x8000000000000000) {
                        dVar33 = (double)(longlong)dVar27;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar27 = (double)(longlong)
                                         ((dVar27 - dVar33) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar33;
                      }
                      if ((((dVar27 < dVar32) &&
                           (dVar27 = (double)FUN_130b71e0af0(_DAT_130b720b7fc + dVar30),
                           dVar27 < dVar32)) && (dVar32 < dVar28 - _DAT_130b720b834)) &&
                         ((dVar27 = (double)FUN_130b71e0af0(_DAT_130b720b804 + dVar30),
                          dVar31 < dVar27 &&
                          (dVar31 = (double)FUN_130b71e0af0(dVar32 - dVar34),
                          dVar31 < dVar32 - _DAT_130b720b82c)))) {
                        FUN_130b71e5c50(lVar10,dVar31,dVar28);
                      }
                    }
                    dVar27 = _DAT_130b720b80c;
                    if (0.0 < _DAT_130b720b80c) {
                      dVar34 = (dVar28 - _DAT_130b720b7a0) - _DAT_130b720b80c;
                      if ((longlong)dVar34 != -0x8000000000000000) {
                        dVar33 = (double)(longlong)dVar34;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar34 = (double)(longlong)
                                         ((dVar34 - dVar33) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar34) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar33;
                      }
                      if (((dVar26 < dVar34) &&
                          (dVar34 = (double)FUN_130b71e0af0(dVar30 - _DAT_130b720b814),
                          dVar26 < dVar34)) &&
                         ((dVar32 < dVar28 - _DAT_130b720b834 &&
                          (dVar28 = (double)FUN_130b71e0af0(dVar27 + dVar32),
                          _DAT_130b720b82c + dVar26 < dVar28)))) {
                        FUN_130b71e5c50(lVar10,dVar31,dVar28);
                      }
                    }
                    dVar27 = _DAT_130b720b82c;
                    dVar26 = _DAT_130b720b824 + dVar30;
                    if ((longlong)dVar26 != -0x8000000000000000) {
                      dVar34 = (double)(longlong)dVar26;
                      uVar23 = (ulonglong)_DAT_130b720b7b0;
                      if (10 < _DAT_130b720b7b0) {
                        uVar23 = 0xb;
                      }
                      dVar26 = (double)(longlong)
                                       ((dVar26 - dVar34) *
                                        *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                       *(double *)((ulonglong)(0.0 < dVar26) * 8 + 0x130b72014c8)) /
                               *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                    }
                    if (0.0 < _DAT_130b720b81c) {
                      dVar30 = dVar30 + _DAT_130b720b81c;
                      if ((longlong)dVar30 != -0x8000000000000000) {
                        dVar34 = (double)(longlong)dVar30;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar30 = (double)(longlong)
                                         ((dVar30 - dVar34) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar30) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                      }
                      if ((((dVar30 < dVar32) && (_DAT_130b720b7a0 + dVar31 < dVar26)) &&
                          (dVar30 = (double)FUN_130b71e0af0(dVar26 + _DAT_130b720b82c),
                          dVar30 < dVar32)) &&
                         ((dVar32 < dVar28 - _DAT_130b720b834 &&
                          (dVar31 = dVar26, dVar26 < dVar32 - dVar27)))) {
                        FUN_130b71e5c50(lVar10,dVar26,dVar28);
                      }
                    }
                    FUN_130b71e3600(lVar10);
                    if (dVar32 < dVar31) goto LAB_130b71ecdac;
                  }
                  else {
                    if ((((0.0 < _DAT_130b720b7ec) &&
                         (dVar26 < (dVar31 - _DAT_130b720b7a0) -
                                   (_DAT_130b720b7f4 + _DAT_130b720b7ec))) &&
                        ((dVar26 < dVar30 - _DAT_130b720b7fc &&
                         (((_DAT_130b720b834 + dVar28 < dVar26 &&
                           (dVar30 - _DAT_130b720b804 < dVar31)) &&
                          (dVar27 = (double)FUN_130b71e0af0(_DAT_130b720b7ec + dVar26),
                          dVar27 < dVar31)))))) &&
                       (dVar31 = dVar27, _DAT_130b720b82c + dVar26 < dVar27)) {
                      FUN_130b71e5c50(lVar10,dVar27,dVar28);
                    }
                    if (0.0 < _DAT_130b720b80c) {
                      dVar27 = _DAT_130b720b7a0 + dVar28 + _DAT_130b720b80c;
                      if ((longlong)dVar27 != -0x8000000000000000) {
                        dVar34 = (double)(longlong)dVar27;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar27 = (double)(longlong)
                                         ((dVar27 - dVar34) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                      }
                      if (dVar27 < dVar32) {
                        dVar27 = _DAT_130b720b814 + dVar30;
                        if ((longlong)dVar27 != -0x8000000000000000) {
                          dVar34 = (double)(longlong)dVar27;
                          uVar23 = (ulonglong)_DAT_130b720b7b0;
                          if (10 < _DAT_130b720b7b0) {
                            uVar23 = 0xb;
                          }
                          dVar27 = (double)(longlong)
                                           ((dVar27 - dVar34) *
                                            *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                           *(double *)
                                            ((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8)) /
                                   *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                        }
                        if (((dVar27 < dVar32) && (_DAT_130b720b834 + dVar28 < dVar32)) &&
                           (dVar28 = (double)FUN_130b71e0af0(dVar32 - _DAT_130b720b80c),
                           dVar28 < dVar32 - _DAT_130b720b82c)) {
                          FUN_130b71e5c50(lVar10,dVar31,dVar28);
                        }
                      }
                    }
                    dVar32 = dVar30 - _DAT_130b720b824;
                    if ((longlong)dVar32 != -0x8000000000000000) {
                      dVar27 = (double)(longlong)dVar32;
                      uVar23 = (ulonglong)_DAT_130b720b7b0;
                      if (10 < _DAT_130b720b7b0) {
                        uVar23 = 0xb;
                      }
                      dVar32 = (double)(longlong)
                                       ((dVar32 - dVar27) *
                                        *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                       *(double *)((ulonglong)(0.0 < dVar32) * 8 + 0x130b72014c8)) /
                               *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar27;
                    }
                    if (((0.0 < _DAT_130b720b81c) && (dVar26 < dVar30 - _DAT_130b720b81c)) &&
                       ((dVar32 < dVar31 - _DAT_130b720b7a0 &&
                        ((((dVar26 < dVar32 - _DAT_130b720b82c &&
                           (_DAT_130b720b834 + dVar28 < dVar26)) && (dVar32 < dVar31)) &&
                         (dVar31 = dVar32, _DAT_130b720b82c + dVar26 < dVar32)))))) {
                      FUN_130b71e5c50(lVar10,dVar32,dVar28);
                    }
                    FUN_130b71e3600(lVar10);
                    if (dVar31 < dVar26) goto LAB_130b71ecdac;
                  }
                  goto LAB_130b71ecdf0;
                }
              }
              else if (lVar11 == 0) {
                dVar27 = (dVar30 - _DAT_130b720b408) - (dVar26 - dVar32);
                if ((longlong)dVar27 != -0x8000000000000000) {
                  dVar34 = (double)(longlong)dVar27;
                  uVar23 = (ulonglong)_DAT_130b720b7b0;
                  if (10 < _DAT_130b720b7b0) {
                    uVar23 = 0xb;
                  }
                  dVar27 = (double)(longlong)
                                   ((dVar27 - dVar34) * *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8)) /
                           *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                }
                if (dVar31 < dVar27) {
                  FUN_130b71e5c50(lVar10,dVar27,dVar28);
                  dVar31 = dVar27;
                }
                if (dVar27 <= dVar32) goto LAB_130b71ed7d1;
              }
              else {
                dVar27 = _DAT_130b720b408 + dVar30 + (dVar26 - dVar32);
                if ((longlong)dVar27 != -0x8000000000000000) {
                  dVar34 = (double)(longlong)dVar27;
                  uVar23 = (ulonglong)_DAT_130b720b7b0;
                  if (10 < _DAT_130b720b7b0) {
                    uVar23 = 0xb;
                  }
                  dVar27 = (double)(longlong)
                                   ((dVar27 - dVar34) * *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                   *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x130b72014c8)) /
                           *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar34;
                }
                if (dVar27 < dVar31) {
                  FUN_130b71e5c50(lVar10,dVar27,dVar28);
                  dVar31 = dVar27;
                }
                if (dVar26 <= dVar27) goto LAB_130b71ed7d1;
              }
LAB_130b71ecdac:
              FUN_130b71e6960(lVar10);
              lVar22 = local_170;
            }
          }
          else if ((local_194 != 0) && (_DAT_130b720bb2c != 0)) {
            uVar20 = *(uint *)(local_194 + -4);
            uVar8 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar7 = uVar8;
            if (uVar20 < uVar8) {
              uVar7 = uVar20;
            }
            iVar6 = uVar20 - uVar8;
            if (uVar7 != 0) {
              uVar23 = 1;
              do {
                uVar1 = *(ushort *)(local_194 + -2 + uVar23 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar23 * 2);
                if (uVar7 <= uVar23) break;
                uVar23 = uVar23 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar6 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar6 == 0) goto LAB_130b71ececc;
          }
        }
LAB_130b71ecdf0:
        bVar24 = 0 < iVar5;
        iVar5 = iVar5 + -1;
      } while (bVar24);
    }
    FUN_130b71d0000(&local_198);
    param_1 = (char)local_148;
  }
  if (param_1 != '\0') {
    uVar15 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
    (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar15,local_108);
    if (((local_fc != 0) || (4 < local_f8)) && (cVar4 = FUN_130b71e6fc0(), cVar4 == '\0')) {
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
      dVar30 = _DAT_130b720bb48;
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
      if (0.0 < _DAT_130b720b7a8) {
        if ((_DAT_130b720b7a8 == 0.0) && (!NAN(_DAT_130b720b7a8))) goto LAB_130b71eee36;
        if (_DAT_130b720b3e8 < (dVar30 - _DAT_130b720bb48) / _DAT_130b720b7a8) {
          return;
        }
      }
      lVar22 = (*(code *)0x7ff63a103b50)(0x130b53f81d8,0x130b7201850,5,0);
      if (((lVar22 != 0) && (lVar22 != _DAT_130b720b708)) &&
         (_DAT_130b720b708 = lVar22, FUN_130b71e1710(), DAT_130b720b728 == 1)) {
        local_160 = 0;
        do {
          if (((DAT_130b720b3e0 != '\0') && (cVar4 = FUN_130b71e0440(0), cVar4 == '\0')) &&
             (iVar5 = FUN_130b71e0b70(4),
             iVar5 < (int)((uint)DAT_130b720b728 + (uint)DAT_130b720b728 * 4))) {
            uVar37 = 0;
            if (DAT_130b720b724 != '\0') {
              uVar37 = 0x4001;
            }
            if (DAT_130b720b727 == '\x01') {
              uVar20 = 1;
              if (DAT_130b720b726 != '\0') {
                uVar20 = 0x19;
              }
              iVar5 = -uVar20;
              do {
                uVar38 = 0;
                if (DAT_130b720b724 != '\0') {
                  uVar38 = 0x4001;
                }
                (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar38,uVar20);
                dVar30 = _DAT_130b720bb48;
                uVar8 = uVar20;
                if (0.0 < _DAT_130b720bb48) {
                  do {
                    (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar38,uVar8);
                    if (dVar30 < _DAT_130b720bb48) goto LAB_130b71ee850;
                    uVar7 = uVar20 - 0x18;
                    if (DAT_130b720b726 == '\0') {
                      uVar7 = uVar20;
                    }
                    bVar24 = (int)uVar7 < (int)uVar8;
                    uVar8 = uVar8 - 1;
                    uVar7 = uVar20;
                  } while (bVar24);
                  do {
                    (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar38,uVar7);
                    if (dVar30 < _DAT_130b720bb48) goto LAB_130b71ee850;
                    uVar8 = uVar20 + 0x1a;
                    if (DAT_130b720b725 == '\0') {
                      uVar8 = uVar20;
                    }
                    bVar24 = uVar7 < uVar8;
                    uVar7 = uVar7 + 1;
                  } while (bVar24);
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
                  if (_DAT_130b720b7bc * _DAT_130b720b7a8 + _DAT_130b720bb48 < dVar30) {
                    (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar38,0);
                    uVar35 = SUB84(_DAT_130b720bb48,0);
                    uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                    iVar6 = 1;
                    do {
                      (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar38,iVar6);
                      if ((double)CONCAT44(uVar36,uVar35) <= _DAT_130b720bb48) {
                        uVar35 = SUB84(_DAT_130b720bb48,0);
                        uVar36 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                      }
                      iVar17 = iVar5 + 1 + iVar6;
                      iVar6 = iVar6 + 1;
                    } while (iVar17 != 1);
                    if ((double)CONCAT44(uVar36,uVar35) <= dVar30) {
                      (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,uVar37,uVar20);
                      dVar30 = _DAT_130b720bb48;
                      if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                        dVar30 = (double)(longlong)_DAT_130b720bb48;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar30 = (double)(longlong)
                                         ((_DAT_130b720bb48 - dVar30) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)
                                          ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar30;
                      }
                      dVar30 = _DAT_130b720b7c4 * _DAT_130b720b7a8 + dVar30;
                      if ((longlong)dVar30 != -0x8000000000000000) {
                        dVar31 = (double)(longlong)dVar30;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar30 = (double)(longlong)
                                         ((dVar30 - dVar31) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar30) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar31;
                      }
                      cVar4 = FUN_130b71e0ce0(4,dVar30);
                      if ((cVar4 == '\0') && (cVar4 = FUN_130b71e0e90(4,dVar30), cVar4 != '\0')) {
                        uVar15 = FUN_130b71e0af0(dVar30 - _DAT_130b720b7dc);
                        uVar29 = FUN_130b71e0af0(_DAT_130b720b7e4 + dVar30);
                        iVar5 = FUN_130b71e1030(4,dVar30,uVar15,uVar29);
                        if (0 < iVar5) {
                          bVar24 = false;
                          goto joined_r0x0130b71eecf7;
                        }
                        break;
                      }
                    }
                  }
                }
LAB_130b71ee850:
                if (DAT_130b720b727 != '\x01') break;
                iVar5 = iVar5 + -1;
                bVar24 = uVar20 < 0x8c;
                uVar20 = uVar20 + 1;
              } while (bVar24);
            }
          }
          bVar24 = true;
joined_r0x0130b71eecf7:
          if (((DAT_130b720b3e1 != '\0') && (cVar4 = FUN_130b71e0440(), cVar4 == '\0')) &&
             (iVar5 = FUN_130b71e0b70(5),
             iVar5 < (int)((uint)DAT_130b720b728 + (uint)DAT_130b720b728 * 4))) {
            uVar37 = 0;
            if (DAT_130b720b724 != '\0') {
              uVar37 = 0x4001;
            }
            local_148 = CONCAT44(local_148._4_4_,uVar37);
            if (DAT_130b720b727 == '\x01') {
              uVar20 = 1;
              if (DAT_130b720b726 != '\0') {
                uVar20 = 0x19;
              }
              iVar5 = -uVar20;
              do {
                uVar37 = 0;
                if (DAT_130b720b724 != '\0') {
                  uVar37 = 0x4001;
                }
                (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,uVar37,uVar20);
                dVar30 = _DAT_130b720bb48;
                if (0.0 < _DAT_130b720bb48) {
                  uVar8 = uVar20;
                  do {
                    (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,uVar37,uVar8);
                    if (_DAT_130b720bb48 < dVar30) goto LAB_130b71eec10;
                    uVar7 = uVar20;
                    if (DAT_130b720b726 != '\0') {
                      uVar7 = uVar20 - 0x18;
                    }
                    bVar25 = (int)uVar7 < (int)uVar8;
                    uVar8 = uVar8 - 1;
                  } while (bVar25);
                  uVar8 = uVar20;
                  do {
                    (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,uVar37,uVar8);
                    if (_DAT_130b720bb48 < dVar30) goto LAB_130b71eec10;
                    uVar7 = uVar20;
                    if (DAT_130b720b725 != '\0') {
                      uVar7 = uVar20 + 0x1a;
                    }
                    bVar25 = uVar8 < uVar7;
                    uVar8 = uVar8 + 1;
                  } while (bVar25);
                  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
                  if (dVar30 < _DAT_130b720bb48 - _DAT_130b720b7bc * _DAT_130b720b7a8) {
                    (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,uVar37,0);
                    uVar38 = SUB84(_DAT_130b720bb48,0);
                    uVar35 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                    iVar6 = 1;
                    do {
                      (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,uVar37,iVar6);
                      if (_DAT_130b720bb48 <= (double)CONCAT44(uVar35,uVar38)) {
                        uVar38 = SUB84(_DAT_130b720bb48,0);
                        uVar35 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                      }
                      iVar17 = iVar5 + 1 + iVar6;
                      iVar6 = iVar6 + 1;
                    } while (iVar17 != 1);
                    if (dVar30 <= (double)CONCAT44(uVar35,uVar38)) {
                      (*(code *)0x7ff63a103cc0)
                                (0x130b53f81d8,0x130b7201850,local_148 & 0xffffffff,uVar20);
                      dVar30 = _DAT_130b720bb48;
                      if ((longlong)_DAT_130b720bb48 != -0x8000000000000000) {
                        dVar30 = (double)(longlong)_DAT_130b720bb48;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar30 = (double)(longlong)
                                         ((_DAT_130b720bb48 - dVar30) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)
                                          ((ulonglong)(0.0 < _DAT_130b720bb48) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar30;
                      }
                      dVar30 = dVar30 - _DAT_130b720b7cc * _DAT_130b720b7a8;
                      if ((longlong)dVar30 != -0x8000000000000000) {
                        dVar31 = (double)(longlong)dVar30;
                        uVar23 = (ulonglong)_DAT_130b720b7b0;
                        if (10 < _DAT_130b720b7b0) {
                          uVar23 = 0xb;
                        }
                        dVar30 = (double)(longlong)
                                         ((dVar30 - dVar31) *
                                          *(double *)(&DAT_130b7201710 + uVar23 * 8) +
                                         *(double *)((ulonglong)(0.0 < dVar30) * 8 + 0x130b72014c8))
                                 / *(double *)(&DAT_130b7201710 + uVar23 * 8) + dVar31;
                      }
                      cVar4 = FUN_130b71e0ce0(5,dVar30);
                      if ((cVar4 == '\0') && (cVar4 = FUN_130b71e0e90(5,dVar30), cVar4 != '\0')) {
                        uVar15 = FUN_130b71e0af0(_DAT_130b720b7dc + dVar30);
                        uVar29 = FUN_130b71e0af0(dVar30 - _DAT_130b720b7e4);
                        iVar5 = FUN_130b71e1030(5,dVar30,uVar15,uVar29);
                        if ((bool)(bVar24 & iVar5 < 1)) {
                          return;
                        }
                        goto LAB_130b71eec4e;
                      }
                    }
                  }
                }
LAB_130b71eec10:
                if (DAT_130b720b727 != '\x01') break;
                iVar5 = iVar5 + -1;
                bVar25 = uVar20 < 0x8c;
                uVar20 = uVar20 + 1;
              } while (bVar25);
            }
          }
          if (bVar24) {
            return;
          }
LAB_130b71eec4e:
          if (DAT_130b720b728 != 1) {
            return;
          }
          uVar20 = (uint)local_160;
          local_160 = (ulonglong)(uVar20 + 1);
          if (3 < uVar20) {
            return;
          }
        } while( true );
      }
    }
  }
  return;
LAB_130b71eed76:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xe078f000001f6);
LAB_130b71eed96:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04d6000001f6);
LAB_130b71eedb6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04d7000001f6);
LAB_130b71eedd6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa04d8000001f6);
LAB_130b71eedf6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xd03b9000001f6);
LAB_130b71eee16:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x3c073c000001f6);
LAB_130b71eee36:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2509b3000001f7);
LAB_130b71eee56:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1d03a9000001f6);
LAB_130b71eee76:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03b1000001f6);
LAB_130b71eee96:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa03b2000001f6);
LAB_130b71eeeb6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1104cf000001f6);
LAB_130b71eeed6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1e0742000001f6);
LAB_130b71eeef6:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x390745000001f6);
LAB_130b71eef16:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x580745000001f6);
LAB_130b71eef36:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x5c0763000001f6);
LAB_130b71eef56:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x5b0761000001f6);
LAB_130b71eef76:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x50076b000001f6);
LAB_130b71eef96:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0780000001f6);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 130b71eefc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71eefc0(double param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x22);
  dVar8 = _DAT_130b720bb48;
  uVar14 = SUB84(_DAT_130b720bb48,0);
  uVar15 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x23);
  dVar11 = _DAT_130b720bb48;
  uVar12 = SUB84(_DAT_130b720bb48,0);
  uVar2 = (ulonglong)_DAT_130b720bb48 >> 0x20;
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x24);
  dVar6 = dVar8;
  if (dVar8 <= param_1) {
    dVar6 = param_1;
  }
  dVar10 = dVar11;
  if (dVar6 <= dVar11) {
    dVar10 = dVar6;
  }
  if (0.0 < _DAT_130b720bb48) {
    if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2e09dd000001f7);
      pcVar1 = (code *)swi(3);
      dVar8 = (double)(*pcVar1)();
      return dVar8;
    }
    dVar9 = (dVar10 + _DAT_130b72014f0 * _DAT_130b720bb48) / _DAT_130b720bb48;
    dVar6 = ABS(dVar9);
    uVar5 = (uint)((ulonglong)dVar6 >> 0x20);
    dVar10 = dVar9;
    if (uVar5 >> 0x14 < 0x3ff) {
      if ((dVar6 != 0.0) && (dVar10 = 0.0, (longlong)dVar9 < 0)) {
        dVar10 = _DAT_130b72014f8;
      }
    }
    else if (((uVar5 >> 0x16 < 0x10d) &&
             (bVar3 = 0x33 - (char)((ulonglong)dVar6 >> 0x34),
             dVar7 = (double)(((ulonglong)dVar6 >> (bVar3 & 0x3f)) << (bVar3 & 0x3f)),
             dVar10 = dVar7, (longlong)dVar9 < 1)) &&
            (dVar10 = (double)((ulonglong)dVar7 | 0x8000000000000000), dVar7 != dVar6)) {
      dVar10 = dVar10 + _DAT_130b72014f8;
    }
    dVar10 = dVar10 * _DAT_130b720bb48;
  }
  if (dVar8 <= dVar10) {
    uVar14 = SUB84(dVar10,0);
    uVar15 = (undefined4)((ulonglong)dVar10 >> 0x20);
  }
  lVar4 = 2;
  uVar13 = (int)uVar2;
  if ((double)CONCAT44(uVar15,uVar14) <= dVar11) {
    uVar12 = uVar14;
    uVar13 = uVar15;
  }
  dVar8 = (double)CONCAT44(uVar13,uVar12);
  if (0.0 < _DAT_130b720bb48) {
    uVar5 = (uint)((ulonglong)_DAT_130b720bb48 >> 0x34) & 0x7ff;
    lVar4 = (ulonglong)uVar5 - 0x3ff;
    dVar11 = _DAT_130b720bb48;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar4 != -1) {
          dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000);
        }
      }
      else {
        bVar3 = (byte)lVar4;
        if (((longlong)_DAT_130b720bb48 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)_DAT_130b720bb48 &
                           -0x10000000000000 >> (bVar3 & 0x3f));
        }
      }
    }
    else if (lVar4 == 0x400) {
      dVar11 = _DAT_130b720bb48 + _DAT_130b720bb48;
    }
    if ((double)((ulonglong)(_DAT_130b720bb48 - dVar11) & _DAT_130b7201500) <= _DAT_130b7201510) {
      lVar4 = 0;
    }
    else {
      dVar6 = _DAT_130b720bb48 * _DAT_130b7201518;
      uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
      lVar4 = (ulonglong)uVar5 - 0x3ff;
      dVar11 = dVar6;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar4 != -1) {
            dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
          }
        }
        else {
          bVar3 = (byte)lVar4;
          if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                             -0x10000000000000 >> (bVar3 & 0x3f));
          }
        }
      }
      else if (lVar4 == 0x400) {
        dVar11 = dVar6 + dVar6;
      }
      lVar4 = 1;
      if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
        dVar6 = dVar6 * _DAT_130b7201518;
        uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
        lVar4 = (ulonglong)uVar5 - 0x3ff;
        dVar11 = dVar6;
        if ((ulonglong)uVar5 < 0x433) {
          if (uVar5 < 0x3ff) {
            dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar4 != -1) {
              dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
            }
          }
          else {
            bVar3 = (byte)lVar4;
            if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
              dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                               -0x10000000000000 >> (bVar3 & 0x3f));
            }
          }
        }
        else if (lVar4 == 0x400) {
          dVar11 = dVar6 + dVar6;
        }
        lVar4 = 2;
        if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
          dVar6 = dVar6 * _DAT_130b7201518;
          uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
          lVar4 = (ulonglong)uVar5 - 0x3ff;
          dVar11 = dVar6;
          if ((ulonglong)uVar5 < 0x433) {
            if (uVar5 < 0x3ff) {
              dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
              if (lVar4 != -1) {
                dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
              }
            }
            else {
              bVar3 = (byte)lVar4;
              if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                                 -0x10000000000000 >> (bVar3 & 0x3f));
              }
            }
          }
          else if (lVar4 == 0x400) {
            dVar11 = dVar6 + dVar6;
          }
          lVar4 = 3;
          if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
            dVar6 = dVar6 * _DAT_130b7201518;
            uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
            lVar4 = (ulonglong)uVar5 - 0x3ff;
            dVar11 = dVar6;
            if ((ulonglong)uVar5 < 0x433) {
              if (uVar5 < 0x3ff) {
                dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar4 != -1) {
                  dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
                }
              }
              else {
                bVar3 = (byte)lVar4;
                if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                                   -0x10000000000000 >> (bVar3 & 0x3f));
                }
              }
            }
            else if (lVar4 == 0x400) {
              dVar11 = dVar6 + dVar6;
            }
            lVar4 = 4;
            if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
              dVar6 = dVar6 * _DAT_130b7201518;
              uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
              lVar4 = (ulonglong)uVar5 - 0x3ff;
              dVar11 = dVar6;
              if ((ulonglong)uVar5 < 0x433) {
                if (uVar5 < 0x3ff) {
                  dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
                  if (lVar4 != -1) {
                    dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
                  }
                }
                else {
                  bVar3 = (byte)lVar4;
                  if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                                     -0x10000000000000 >> (bVar3 & 0x3f));
                  }
                }
              }
              else if (lVar4 == 0x400) {
                dVar11 = dVar6 + dVar6;
              }
              lVar4 = 5;
              if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
                dVar6 = dVar6 * _DAT_130b7201518;
                uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
                lVar4 = (ulonglong)uVar5 - 0x3ff;
                dVar11 = dVar6;
                if ((ulonglong)uVar5 < 0x433) {
                  if (uVar5 < 0x3ff) {
                    dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
                    if (lVar4 != -1) {
                      dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
                    }
                  }
                  else {
                    bVar3 = (byte)lVar4;
                    if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                      dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                                       -0x10000000000000 >> (bVar3 & 0x3f));
                    }
                  }
                }
                else if (lVar4 == 0x400) {
                  dVar11 = dVar6 + dVar6;
                }
                lVar4 = 6;
                if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
                  dVar6 = dVar6 * _DAT_130b7201518;
                  uVar5 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
                  lVar4 = (ulonglong)uVar5 - 0x3ff;
                  dVar11 = dVar6;
                  if ((ulonglong)uVar5 < 0x433) {
                    if (uVar5 < 0x3ff) {
                      dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000 | 0x3ff0000000000000);
                      if (lVar4 != -1) {
                        dVar11 = (double)((ulonglong)dVar6 & 0x8000000000000000);
                      }
                    }
                    else {
                      bVar3 = (byte)lVar4;
                      if (((longlong)dVar6 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                        dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar6 &
                                         -0x10000000000000 >> (bVar3 & 0x3f));
                      }
                    }
                  }
                  else if (lVar4 == 0x400) {
                    dVar11 = dVar6 + dVar6;
                  }
                  lVar4 = 7;
                  if (_DAT_130b7201510 < (double)((ulonglong)(dVar6 - dVar11) & _DAT_130b7201500)) {
                    lVar4 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ((longlong)(double)CONCAT44(uVar13,uVar12) != -0x8000000000000000) {
    dVar8 = (double)(longlong)(double)CONCAT44(uVar13,uVar12);
    dVar8 = (double)(longlong)
                    (((double)CONCAT44(uVar13,uVar12) - dVar8) *
                     *(double *)(&DAT_130b7201710 + lVar4 * 8) +
                    *(double *)
                     ((ulonglong)
                      (0.0 <= (double)CONCAT44(uVar13,uVar12) &&
                      (double)CONCAT44(uVar13,uVar12) != 0.0) * 8 + 0x130b7201520)) /
            *(double *)(&DAT_130b7201710 + lVar4 * 8) + dVar8;
  }
  return dVar8;
}



/* Address: 130b71ef790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71ef790(uint param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  if (param_1 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71ef7d7 */
                    /* WARNING: Treating indirect jump as call */
    dVar7 = (double)(**(code **)((ulonglong)param_1 * 8 + 0x130b7201548))();
    return dVar7;
  }
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x22);
  dVar7 = _DAT_130b720bb48;
  uVar14 = SUB84(_DAT_130b720bb48,0);
  uVar15 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x23);
  dVar11 = _DAT_130b720bb48;
  uVar12 = SUB84(_DAT_130b720bb48,0);
  uVar2 = (ulonglong)_DAT_130b720bb48 >> 0x20;
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x24);
  dVar8 = dVar7;
  if (dVar7 <= 0.0) {
    dVar8 = 0.0;
  }
  dVar10 = dVar11;
  if (dVar8 <= dVar11) {
    dVar10 = dVar8;
  }
  if (0.0 < _DAT_130b720bb48) {
    if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2e09dd000001f7);
      pcVar1 = (code *)swi(3);
      dVar7 = (double)(*pcVar1)();
      return dVar7;
    }
    dVar9 = (dVar10 + _DAT_130b72014f0 * _DAT_130b720bb48) / _DAT_130b720bb48;
    dVar8 = ABS(dVar9);
    uVar5 = (uint)((ulonglong)dVar8 >> 0x20);
    dVar10 = dVar9;
    if (uVar5 >> 0x14 < 0x3ff) {
      if ((dVar8 != 0.0) && (dVar10 = 0.0, (longlong)dVar9 < 0)) {
        dVar10 = _DAT_130b72014f8;
      }
    }
    else if (((uVar5 >> 0x16 < 0x10d) &&
             (bVar3 = 0x33 - (char)((ulonglong)dVar8 >> 0x34),
             dVar6 = (double)(((ulonglong)dVar8 >> (bVar3 & 0x3f)) << (bVar3 & 0x3f)),
             dVar10 = dVar6, (longlong)dVar9 < 1)) &&
            (dVar10 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar8)) {
      dVar10 = dVar10 + _DAT_130b72014f8;
    }
    dVar10 = dVar10 * _DAT_130b720bb48;
  }
  if (dVar7 <= dVar10) {
    uVar14 = SUB84(dVar10,0);
    uVar15 = (undefined4)((ulonglong)dVar10 >> 0x20);
  }
  lVar4 = 2;
  uVar13 = (int)uVar2;
  if ((double)CONCAT44(uVar15,uVar14) <= dVar11) {
    uVar12 = uVar14;
    uVar13 = uVar15;
  }
  dVar7 = (double)CONCAT44(uVar13,uVar12);
  if (0.0 < _DAT_130b720bb48) {
    uVar5 = (uint)((ulonglong)_DAT_130b720bb48 >> 0x34) & 0x7ff;
    lVar4 = (ulonglong)uVar5 - 0x3ff;
    dVar11 = _DAT_130b720bb48;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar4 != -1) {
          dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000);
        }
      }
      else {
        bVar3 = (byte)lVar4;
        if (((longlong)_DAT_130b720bb48 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)_DAT_130b720bb48 &
                           -0x10000000000000 >> (bVar3 & 0x3f));
        }
      }
    }
    else if (lVar4 == 0x400) {
      dVar11 = _DAT_130b720bb48 + _DAT_130b720bb48;
    }
    if ((double)((ulonglong)(_DAT_130b720bb48 - dVar11) & _DAT_130b7201500) <= _DAT_130b7201510) {
      lVar4 = 0;
    }
    else {
      dVar8 = _DAT_130b720bb48 * _DAT_130b7201518;
      uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
      lVar4 = (ulonglong)uVar5 - 0x3ff;
      dVar11 = dVar8;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar4 != -1) {
            dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
          }
        }
        else {
          bVar3 = (byte)lVar4;
          if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                             -0x10000000000000 >> (bVar3 & 0x3f));
          }
        }
      }
      else if (lVar4 == 0x400) {
        dVar11 = dVar8 + dVar8;
      }
      lVar4 = 1;
      if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
        dVar8 = dVar8 * _DAT_130b7201518;
        uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
        lVar4 = (ulonglong)uVar5 - 0x3ff;
        dVar11 = dVar8;
        if ((ulonglong)uVar5 < 0x433) {
          if (uVar5 < 0x3ff) {
            dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar4 != -1) {
              dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
            }
          }
          else {
            bVar3 = (byte)lVar4;
            if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
              dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                               -0x10000000000000 >> (bVar3 & 0x3f));
            }
          }
        }
        else if (lVar4 == 0x400) {
          dVar11 = dVar8 + dVar8;
        }
        lVar4 = 2;
        if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
          dVar8 = dVar8 * _DAT_130b7201518;
          uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
          lVar4 = (ulonglong)uVar5 - 0x3ff;
          dVar11 = dVar8;
          if ((ulonglong)uVar5 < 0x433) {
            if (uVar5 < 0x3ff) {
              dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
              if (lVar4 != -1) {
                dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
              }
            }
            else {
              bVar3 = (byte)lVar4;
              if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                 -0x10000000000000 >> (bVar3 & 0x3f));
              }
            }
          }
          else if (lVar4 == 0x400) {
            dVar11 = dVar8 + dVar8;
          }
          lVar4 = 3;
          if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
            dVar8 = dVar8 * _DAT_130b7201518;
            uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
            lVar4 = (ulonglong)uVar5 - 0x3ff;
            dVar11 = dVar8;
            if ((ulonglong)uVar5 < 0x433) {
              if (uVar5 < 0x3ff) {
                dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar4 != -1) {
                  dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                }
              }
              else {
                bVar3 = (byte)lVar4;
                if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                   -0x10000000000000 >> (bVar3 & 0x3f));
                }
              }
            }
            else if (lVar4 == 0x400) {
              dVar11 = dVar8 + dVar8;
            }
            lVar4 = 4;
            if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
              dVar8 = dVar8 * _DAT_130b7201518;
              uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
              lVar4 = (ulonglong)uVar5 - 0x3ff;
              dVar11 = dVar8;
              if ((ulonglong)uVar5 < 0x433) {
                if (uVar5 < 0x3ff) {
                  dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                  if (lVar4 != -1) {
                    dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                  }
                }
                else {
                  bVar3 = (byte)lVar4;
                  if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                     -0x10000000000000 >> (bVar3 & 0x3f));
                  }
                }
              }
              else if (lVar4 == 0x400) {
                dVar11 = dVar8 + dVar8;
              }
              lVar4 = 5;
              if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                dVar8 = dVar8 * _DAT_130b7201518;
                uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
                lVar4 = (ulonglong)uVar5 - 0x3ff;
                dVar11 = dVar8;
                if ((ulonglong)uVar5 < 0x433) {
                  if (uVar5 < 0x3ff) {
                    dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                    if (lVar4 != -1) {
                      dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                    }
                  }
                  else {
                    bVar3 = (byte)lVar4;
                    if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                      dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                       -0x10000000000000 >> (bVar3 & 0x3f));
                    }
                  }
                }
                else if (lVar4 == 0x400) {
                  dVar11 = dVar8 + dVar8;
                }
                lVar4 = 6;
                if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                  dVar8 = dVar8 * _DAT_130b7201518;
                  uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
                  lVar4 = (ulonglong)uVar5 - 0x3ff;
                  dVar11 = dVar8;
                  if ((ulonglong)uVar5 < 0x433) {
                    if (uVar5 < 0x3ff) {
                      dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                      if (lVar4 != -1) {
                        dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                      }
                    }
                    else {
                      bVar3 = (byte)lVar4;
                      if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                        dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                         -0x10000000000000 >> (bVar3 & 0x3f));
                      }
                    }
                  }
                  else if (lVar4 == 0x400) {
                    dVar11 = dVar8 + dVar8;
                  }
                  lVar4 = 7;
                  if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                    lVar4 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ((longlong)(double)CONCAT44(uVar13,uVar12) != -0x8000000000000000) {
    dVar7 = (double)(longlong)(double)CONCAT44(uVar13,uVar12);
    dVar7 = (double)(longlong)
                    (((double)CONCAT44(uVar13,uVar12) - dVar7) *
                     *(double *)(&DAT_130b7201710 + lVar4 * 8) +
                    *(double *)
                     ((ulonglong)
                      (0.0 <= (double)CONCAT44(uVar13,uVar12) &&
                      (double)CONCAT44(uVar13,uVar12) != 0.0) * 8 + 0x130b7201520)) /
            *(double *)(&DAT_130b7201710 + lVar4 * 8) + dVar7;
  }
  return dVar7;
}



/* Address: 130b71efa90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71efa90(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  
  uVar3 = _DAT_130b720b918;
  uVar6 = (ulonglong)_DAT_130b720b918;
  if (0 < (int)_DAT_130b720b918) {
    uVar4 = 0;
    pcVar5 = (char *)(_DAT_130b720b92c + 0x10);
    do {
      if ((*pcVar5 != '\0') && (*(longlong *)(pcVar5 + -0x10) == param_1)) {
        if (-1 < (int)uVar4) goto LAB_130b71efb5b;
        break;
      }
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 0x11;
    } while (uVar6 != uVar4);
  }
  (*(code *)0x7ff63a0da0e0)(0x130b53f81d8,0x130b720b910,_DAT_130b720b918 + 1,0);
  uVar4 = (ulonglong)(int)uVar3;
  if (uVar4 < _DAT_130b720b918) {
    lVar2 = uVar4 * 0x11;
    *(longlong *)(_DAT_130b720b92c + lVar2) = param_1;
    if (uVar4 < _DAT_130b720b918) {
      *(undefined8 *)(_DAT_130b720b92c + 8 + lVar2) = param_2;
      if (_DAT_130b720b918 <= uVar4) goto LAB_130b71efbe2;
      *(undefined1 *)(_DAT_130b720b92c + 0x10 + lVar2) = 1;
      uVar6 = (ulonglong)_DAT_130b720b918;
LAB_130b71efb5b:
      if (uVar4 < uVar6) {
        return *(undefined8 *)(_DAT_130b720b92c + 8 + uVar4 * 0x11);
      }
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x110ae8000001f6);
      goto LAB_130b71efba2;
    }
  }
  else {
LAB_130b71efba2:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0ae4000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0ae5000001f6);
LAB_130b71efbe2:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0xa0ae6000001f6);
  pcVar1 = (code *)swi(3);
  uVar7 = (*pcVar1)();
  return uVar7;
}



/* Address: 130b71efc10 */

int FUN_130b71efc10(void)

{
  undefined8 uVar1;
  int local_28;
  int local_24;
  int local_20;
  
  uVar1 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar1,&local_28);
  return local_24 * 100 + local_28 * 10000 + local_20;
}



/* Address: 130b71efc70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_130b71efc70(void)

{
  double dVar1;
  
  (*(code *)0x7ff63a103bc0)(0x130b53f81d8,0x130b7201850,0x4018,1);
  dVar1 = _DAT_130b720bb48;
  (*(code *)0x7ff63a103d40)(0x130b53f81d8,0x130b7201850,0x4018,1);
  return _DAT_130b720bb48 < dVar1 & -(0.0 < _DAT_130b720bb48) & -(0.0 < dVar1);
}



/* Address: 130b71efd10 */

int FUN_130b71efd10(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  bool bVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int iVar12;
  ulonglong uVar13;
  undefined4 local_50;
  longlong local_4c;
  
  local_50 = 0;
  local_4c = 0;
  iVar9 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
  iVar12 = 0;
  iVar9 = iVar9 + -1;
  if (-1 < iVar9) {
    do {
      uVar11 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar9);
      cVar8 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,uVar11);
      if (cVar8 != '\0') {
        (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
        FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208048);
        lVar5 = *(longlong *)(param_1 + 4);
        if (local_4c == lVar5) {
LAB_130b71efd90:
          iVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
          iVar12 = iVar12 + (uint)(iVar10 == param_2);
        }
        else if ((local_4c != 0) && (lVar5 != 0)) {
          uVar3 = *(uint *)(local_4c + -4);
          uVar4 = *(uint *)(lVar5 + -4);
          uVar7 = uVar4;
          if (uVar3 < uVar4) {
            uVar7 = uVar3;
          }
          iVar10 = uVar3 - uVar4;
          if (uVar7 != 0) {
            uVar13 = 1;
            do {
              uVar1 = *(ushort *)(local_4c + -2 + uVar13 * 2);
              uVar2 = *(ushort *)(lVar5 + -2 + uVar13 * 2);
              if (uVar7 <= uVar13) break;
              uVar13 = uVar13 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar10 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar10 == 0) goto LAB_130b71efd90;
        }
      }
      bVar6 = 0 < iVar9;
      iVar9 = iVar9 + -1;
    } while (bVar6);
  }
  FUN_130b71d0000(&local_50);
  return iVar12;
}



/* Address: 130b71efed0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_130b71efed0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined8 local_34;
  
  uVar3 = (undefined4)((ulonglong)param_2 >> 0x20);
  uVar2 = (undefined4)param_2;
  local_38 = 0;
  local_34 = 0;
  local_48 = 0;
  local_40 = 0;
  FUN_130b71ea9d0();
  FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b72080b8);
  FUN_130b71d0a30(&local_48,&local_38,0,0x130b72080c8);
  cVar1 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_48);
  if (cVar1 != '\0') {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_48);
    uVar2 = (undefined4)_DAT_130b720bb48;
    uVar3 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  }
  FUN_130b71d0000(&local_48);
  FUN_130b71d0000(&local_38);
  return CONCAT44(uVar3,uVar2);
}



/* Address: 130b71effc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71effc0(undefined8 param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  char cVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined4 local_a0;
  longlong local_9c;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_a0 = 0;
  local_70 = 0;
  local_60 = 0;
  local_4c = 0;
  local_9c = 0;
  local_6c = 0;
  local_5c = 0;
  uVar12 = 0;
  FUN_130b71d0a30(&local_a0,param_1,0);
  uVar4 = _DAT_130b7204412;
  uVar9 = (ulonglong)_DAT_130b7204412;
  if ((uVar9 != 0) || (local_9c == 0)) {
    if (local_9c != 0) {
      uVar12 = *(uint *)(local_9c + -4);
    }
    uVar7 = _DAT_130b7204412 + uVar12;
    cVar5 = FUN_130b71d0060(&local_a0);
    if (cVar5 != '\0') {
      if (uVar9 != 0) {
        lVar1 = local_9c + (ulonglong)uVar12 * 2;
        if ((uVar4 < 0x10) || (lVar1 - 0x130b7204416U < 0x20)) {
          uVar6 = 0;
        }
        else {
          uVar10 = 0;
          uVar6 = (ulonglong)(uVar4 & 0xfffffff8);
          do {
            uVar3 = *(undefined8 *)(uVar10 + 0x130b720441e);
            *(undefined8 *)(lVar1 + uVar10) = *(undefined8 *)(&DAT_130b7204416 + uVar10);
            ((undefined8 *)(lVar1 + uVar10))[1] = uVar3;
            uVar10 = uVar10 + 0x10;
          } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar10);
          if (uVar6 == uVar9) goto LAB_130b71f0102;
        }
        do {
          *(undefined2 *)(lVar1 + uVar6 * 2) = *(undefined2 *)(&DAT_130b7204416 + uVar6 * 2);
          uVar6 = uVar6 + 1;
        } while (uVar9 != uVar6);
      }
LAB_130b71f0102:
      *(uint *)(local_9c + -4) = uVar7;
      *(undefined2 *)(local_9c + (ulonglong)uVar7 * 2) = 0;
      goto LAB_130b71f010d;
    }
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0bff000001f9);
LAB_130b71f0871:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0c00000001f9);
LAB_130b71f0891:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x360c03000001f9);
LAB_130b71f08b1:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x360c04000001f9);
    pcVar2 = (code *)swi(3);
    uVar9 = (*pcVar2)();
    return uVar9;
  }
LAB_130b71f010d:
  FUN_130b71ea9d0(&local_a0);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208128);
  uVar12 = 0;
  FUN_130b71d0a30(&local_60,&local_50,0,0x130b7208138);
  local_70 = 0;
  local_6c = 0;
  FUN_130b71d0a30(&local_a0,param_1,0);
  uVar4 = _DAT_130b7204422;
  uVar9 = (ulonglong)_DAT_130b7204422;
  if ((uVar9 != 0) || (local_9c == 0)) {
    if (local_9c != 0) {
      uVar12 = *(uint *)(local_9c + -4);
    }
    uVar7 = _DAT_130b7204422 + uVar12;
    cVar5 = FUN_130b71d0060(&local_a0);
    if (cVar5 == '\0') goto LAB_130b71f0871;
    if (uVar9 != 0) {
      lVar1 = local_9c + (ulonglong)uVar12 * 2;
      if ((uVar4 < 0x10) || (lVar1 - 0x130b7204426U < 0x20)) {
        uVar6 = 0;
      }
      else {
        uVar10 = 0;
        uVar6 = (ulonglong)(uVar4 & 0xfffffff8);
        do {
          uVar3 = *(undefined8 *)(uVar10 + 0x130b720442e);
          *(undefined8 *)(lVar1 + uVar10) = *(undefined8 *)(&DAT_130b7204426 + uVar10);
          ((undefined8 *)(lVar1 + uVar10))[1] = uVar3;
          uVar10 = uVar10 + 0x10;
        } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar10);
        if (uVar6 == uVar9) goto LAB_130b71f0252;
      }
      do {
        *(undefined2 *)(lVar1 + uVar6 * 2) = *(undefined2 *)(&DAT_130b7204426 + uVar6 * 2);
        uVar6 = uVar6 + 1;
      } while (uVar9 != uVar6);
    }
LAB_130b71f0252:
    *(uint *)(local_9c + -4) = uVar7;
    *(undefined2 *)(local_9c + (ulonglong)uVar7 * 2) = 0;
  }
  FUN_130b71ea9d0(&local_a0);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208158);
  FUN_130b71d0a30(&local_70,&local_50,0,0x130b7208168);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_60);
  if ((cVar5 == '\0') && (cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_70), cVar5 == '\0')
     ) {
    local_80 = 0;
    local_7c = 0;
    local_90 = 0;
    local_88 = 0;
    FUN_130b71ea9d0(param_1);
    FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b72080b8);
    uVar9 = 0;
    FUN_130b71d0a30(&local_90,&local_80,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_90);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_90);
      uVar9 = (longlong)_DAT_130b720bb48 >> 0x3f & (longlong)(_DAT_130b720bb48 - _DAT_130b7201568) |
              (longlong)_DAT_130b720bb48;
    }
    goto LAB_130b71f080a;
  }
  uVar12 = 0;
  FUN_130b71d0a30(&local_a0,param_1,0,0x130b7208178);
  uVar4 = _DAT_130b7204412;
  uVar9 = (ulonglong)_DAT_130b7204412;
  if ((uVar9 != 0) || (local_9c == 0)) {
    if (local_9c != 0) {
      uVar12 = *(uint *)(local_9c + -4);
    }
    uVar8 = _DAT_130b7204412 + uVar12;
    uVar7 = 0x104;
    if ((0x103 < uVar8) &&
       ((0x7ffffffd < uVar8 || (uVar7 = (uVar8 >> 2) + uVar8, 0x7ffffffd < uVar7)))) {
      uVar7 = 0x7ffffffe;
    }
    cVar5 = FUN_130b71d0060(&local_a0,uVar7);
    if (cVar5 == '\0') goto LAB_130b71f0891;
    if (uVar9 != 0) {
      lVar1 = local_9c + (ulonglong)uVar12 * 2;
      if (uVar4 < 0x10) {
        uVar6 = 0;
      }
      else if (lVar1 - 0x130b7204416U < 0x20) {
        uVar6 = 0;
      }
      else {
        uVar10 = 0;
        uVar6 = (ulonglong)(uVar4 & 0xfffffff8);
        do {
          uVar3 = *(undefined8 *)(uVar10 + 0x130b720441e);
          *(undefined8 *)(lVar1 + uVar10) = *(undefined8 *)(&DAT_130b7204416 + uVar10);
          ((undefined8 *)(lVar1 + uVar10))[1] = uVar3;
          uVar10 = uVar10 + 0x10;
        } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar10);
        if (uVar6 == uVar9) goto LAB_130b71f0562;
      }
      do {
        *(undefined2 *)(lVar1 + uVar6 * 2) = *(undefined2 *)(&DAT_130b7204416 + uVar6 * 2);
        uVar6 = uVar6 + 1;
      } while (uVar9 != uVar6);
    }
LAB_130b71f0562:
    *(uint *)(local_9c + -4) = uVar8;
    *(undefined2 *)(local_9c + (ulonglong)uVar8 * 2) = 0;
  }
  local_80 = 0;
  local_7c = 0;
  local_90 = 0;
  local_88 = 0;
  FUN_130b71ea9d0(&local_a0);
  FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b72080b8);
  uVar6 = 0;
  FUN_130b71d0a30(&local_90,&local_80,0,0x130b72080c8);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_90);
  if (cVar5 != '\0') {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_90);
    uVar6 = (longlong)_DAT_130b720bb48 & 0xffffffff;
  }
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_80);
  uVar12 = 0;
  FUN_130b71d0a30(&local_a0,param_1,0,0x130b7208188);
  uVar4 = _DAT_130b7204422;
  uVar9 = (ulonglong)_DAT_130b7204422;
  if ((uVar9 != 0) || (local_9c == 0)) {
    if (local_9c != 0) {
      uVar12 = *(uint *)(local_9c + -4);
    }
    uVar8 = _DAT_130b7204422 + uVar12;
    uVar7 = 0x104;
    if ((0x103 < uVar8) &&
       ((0x7ffffffd < uVar8 || (uVar7 = (uVar8 >> 2) + uVar8, 0x7ffffffd < uVar7)))) {
      uVar7 = 0x7ffffffe;
    }
    cVar5 = FUN_130b71d0060(&local_a0,uVar7);
    if (cVar5 == '\0') goto LAB_130b71f08b1;
    if (uVar9 != 0) {
      lVar1 = local_9c + (ulonglong)uVar12 * 2;
      if (uVar4 < 0x10) {
        uVar10 = 0;
      }
      else if (lVar1 - 0x130b7204426U < 0x20) {
        uVar10 = 0;
      }
      else {
        uVar11 = 0;
        uVar10 = (ulonglong)(uVar4 & 0xfffffff8);
        do {
          uVar3 = *(undefined8 *)(uVar11 + 0x130b720442e);
          *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(&DAT_130b7204426 + uVar11);
          ((undefined8 *)(lVar1 + uVar11))[1] = uVar3;
          uVar11 = uVar11 + 0x10;
        } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
        if (uVar10 == uVar9) goto LAB_130b71f0752;
      }
      do {
        *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204426 + uVar10 * 2);
        uVar10 = uVar10 + 1;
      } while (uVar9 != uVar10);
    }
LAB_130b71f0752:
    *(uint *)(local_9c + -4) = uVar8;
    *(undefined2 *)(local_9c + (ulonglong)uVar8 * 2) = 0;
  }
  local_80 = 0;
  local_7c = 0;
  local_90 = 0;
  local_88 = 0;
  FUN_130b71ea9d0(&local_a0);
  FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b72080b8);
  uVar9 = 0;
  FUN_130b71d0a30(&local_90,&local_80,0,0x130b72080c8);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_90);
  if (cVar5 != '\0') {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_90);
    uVar9 = (longlong)_DAT_130b720bb48 << 0x20;
  }
  uVar9 = uVar9 | uVar6;
LAB_130b71f080a:
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_80);
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_a0);
  FUN_130b71d0000(&local_50);
  return uVar9;
}



/* Address: 130b71f08e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f08e0(char *param_1,char *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined4 local_80;
  longlong local_7c;
  char *local_70;
  char *local_68;
  int local_60;
  uint local_5c;
  int local_58;
  
  local_80 = 0;
  local_7c = 0;
  *param_1 = '\0';
  *param_2 = '\0';
  local_70 = param_1;
  local_68 = param_2;
  uVar7 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  uVar8 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar8,&local_60);
  uVar5 = local_60 - (uint)(local_5c < 3);
  uVar11 = local_5c + 0xc;
  if (2 < local_5c) {
    uVar11 = local_5c;
  }
  cVar4 = (*(code *)0x7ff63a1084f0)
                    (0x130b53f81d8,
                     (ulonglong)
                     (((uVar11 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
                     ((uVar5 * 0x16d + local_58 + (uVar5 >> 2)) - uVar5 / 100) + uVar5 / 400) *
                     0x15180,uVar7);
  if ((cVar4 != '\0') && (iVar6 = (*(code *)0x7ff63a108810)(0x130b53f81d8), 0 < iVar6)) {
    iVar13 = 0;
    lVar15 = (longlong)_DAT_130b720bc30;
    do {
      lVar9 = (*(code *)0x7ff63a108860)(0x130b53f81d8,iVar13);
      if (lVar9 != 0) {
        (*(code *)0x7ff63a1089d0)(0x130b53f81d8,lVar9,0);
        FUN_130b71d0a30(&local_80,0x130b720bb3c,1,0x130b7208218);
        if (local_7c == _DAT_130b720bb2c) {
LAB_130b71f0b18:
          lVar10 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar9);
          if ((lVar10 == lVar15) &&
             (uVar14 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar9),
             (uVar14 & 0xfffffffffffffffd) == 0)) {
            lVar9 = (*(code *)0x7ff63a108940)(0x130b53f81d8,lVar9);
            if (lVar9 == 1) {
              *local_68 = '\x01';
              cVar4 = *local_70;
joined_r0x0130b71f0ba7:
              if (cVar4 == '\0') goto LAB_130b71f0a40;
            }
            else {
              if (lVar9 != 0) {
                cVar4 = *local_70;
                goto joined_r0x0130b71f0ba7;
              }
              *local_70 = '\x01';
            }
            if (*local_68 != '\0') break;
          }
        }
        else if ((local_7c != 0) && (_DAT_130b720bb2c != 0)) {
          uVar11 = *(uint *)(local_7c + -4);
          uVar5 = *(uint *)(_DAT_130b720bb2c + -4);
          uVar3 = uVar5;
          if (uVar11 < uVar5) {
            uVar3 = uVar11;
          }
          iVar12 = uVar11 - uVar5;
          if (uVar3 != 0) {
            uVar14 = 1;
            do {
              uVar1 = *(ushort *)(local_7c + -2 + uVar14 * 2);
              uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar14 * 2);
              if (uVar3 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar12 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar12 == 0) goto LAB_130b71f0b18;
        }
      }
LAB_130b71f0a40:
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar6);
  }
  FUN_130b71d0000(&local_80);
  return;
}



/* Address: 130b71f0be0 */

/* WARNING: Removing unreachable block (ram,0x0130b71f44c6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f0be0(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  ulonglong uVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_150;
  undefined8 local_14c;
  char local_13d;
  char local_13c;
  char local_13b;
  char local_13a;
  char local_139;
  undefined4 local_138;
  longlong local_134;
  undefined4 local_128;
  undefined8 local_124;
  uint local_11c;
  undefined4 local_118;
  undefined8 local_114;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  
  local_138 = 0;
  local_118 = 0;
  local_128 = 0;
  local_134 = 0;
  local_114 = 0;
  local_124 = 0;
  iVar6 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar6 != 0) goto LAB_130b71f4777;
  local_150 = 0;
  local_14c = 0;
  local_160 = 0;
  local_158 = 0;
  FUN_130b71ea9d0(0x130b7204048);
  FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
  FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
  if (cVar5 == '\0') {
    uVar22 = 0;
    uVar23 = 0;
  }
  else {
    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
    uVar22 = SUB84(_DAT_130b720bb48,0);
    uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
  }
  FUN_130b71d0000(&local_160);
  FUN_130b71d0000(&local_150);
  DAT_130b720ba6e =
       _DAT_130b7201570 <= (double)CONCAT44(uVar23,uVar22) &&
       (double)CONCAT44(uVar23,uVar22) != _DAT_130b7201570;
  local_13d = DAT_130b720bc80;
  if (DAT_130b720bc80 == '\0') {
    puVar7 = (undefined1 *)0x0;
    DAT_130b720b944 = '\0';
    _DAT_130b720b948 = 1.0;
    _DAT_130b720b950 = 0;
  }
  else {
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(0x130b7204078);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    DAT_130b720b944 =
         _DAT_130b7201570 <= (double)CONCAT44(uVar23,uVar22) &&
         (double)CONCAT44(uVar23,uVar22) != _DAT_130b7201570;
    FUN_130b71ea9d0(0x130b72040a8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = (undefined4)_DAT_130b7201578;
      uVar23 = (undefined4)((ulonglong)_DAT_130b7201578 >> 0x20);
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    _DAT_130b720b948 = (double)CONCAT44(uVar23,uVar22);
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(0x130b72040d8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    puVar7 = &DAT_130b720b950;
    _DAT_130b720b950 = CONCAT44(uVar23,uVar22);
    if (_DAT_130b720b948 <= 0.0) {
      puVar7 = (undefined1 *)0x0;
      _DAT_130b720b948 = 1.0;
    }
  }
  dVar20 = _DAT_130b7201570;
  uVar22 = (undefined4)_DAT_130b7201578;
  uVar23 = (undefined4)((ulonglong)_DAT_130b7201578 >> 0x20);
  uVar8 = CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
  uVar13 = 0;
  do {
    local_11c = (uint)uVar8;
    local_118 = 0;
    local_114 = 0;
    (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd8,2,0x590008,0x130b7204108,0x520004,uVar13);
    FUN_130b71d0a30(&local_138,0x130b720bb3c,1,0x130b7208228);
    FUN_130b71d0a30(&local_118,&local_138,0,0x130b7208238);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208248);
    uVar12 = _DAT_130b72034b4;
    uVar18 = (ulonglong)_DAT_130b72034b4;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar17 = 0;
        uVar16 = _DAT_130b72034b4;
      }
      else {
        uVar17 = *(uint *)(local_134 + -4);
        uVar16 = _DAT_130b72034b4 + uVar17;
      }
      uVar9 = 0x104;
      if ((0x103 < uVar16) &&
         ((0x7ffffffd < uVar16 || (uVar9 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar9)))) {
        uVar9 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar9);
      if (cVar5 == '\0') goto LAB_130b71f4915;
      if (uVar18 != 0) {
        lVar11 = local_134 + (ulonglong)uVar17 * 2;
        if (uVar12 < 8) {
          uVar10 = 0;
        }
        else if (local_134 + -0x130b72034b8 + (ulonglong)uVar17 * 2 < 0x20) {
          uVar10 = 0;
        }
        else {
          uVar14 = 0;
          uVar10 = (ulonglong)(uVar12 & 0xfffffff8);
          do {
            uVar8 = *(undefined8 *)(uVar14 + 0x130b72034c0);
            puVar2 = (undefined8 *)(lVar11 + uVar14);
            *puVar2 = *(undefined8 *)(&DAT_130b72034b8 + uVar14);
            puVar2[1] = uVar8;
            uVar14 = uVar14 + 0x10;
          } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
          if (uVar10 == uVar18) goto LAB_130b71f12b2;
        }
        do {
          *(undefined2 *)(lVar11 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72034b8 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar18 != uVar10);
      }
LAB_130b71f12b2:
      *(uint *)(local_134 + -4) = uVar16;
      *(undefined2 *)(local_134 + (ulonglong)uVar16 * 2) = 0;
    }
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar24 = 0;
      uVar25 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    lVar11 = (ulonglong)uVar13 * 0x4c;
    (&DAT_130b720b9d0)[lVar11] =
         dVar20 <= (double)CONCAT44(uVar25,uVar24) && (double)CONCAT44(uVar25,uVar24) != dVar20;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208258);
    uVar13 = _DAT_130b720411c;
    uVar18 = (ulonglong)_DAT_130b720411c;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b720411c;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b720411c + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7204120 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7204128);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7204120 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f14e2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204120 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f14e2:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1503;
      }
LAB_130b71f4855:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2b0ca5000001f9);
LAB_130b71f4875:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2b0caf000001f9);
LAB_130b71f4895:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0cac000001f9);
LAB_130b71f48b5:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x340caa000001f9);
LAB_130b71f48d5:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0ca8000001f9);
LAB_130b71f48f5:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0ca6000001f9);
LAB_130b71f4915:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2b0ca4000001f9);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
LAB_130b71f1503:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(bool *)(lVar11 + 0x130b720b9d1) =
         dVar20 <= (double)CONCAT44(uVar23,uVar22) && (double)CONCAT44(uVar23,uVar22) != dVar20;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208268);
    uVar13 = _DAT_130b7203514;
    uVar18 = (ulonglong)_DAT_130b7203514;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b7203514;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b7203514 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7203518 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7203520);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7203518 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f1702;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203518 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f1702:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1723;
      }
      goto LAB_130b71f48f5;
    }
LAB_130b71f1723:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(ulonglong *)(lVar11 + 0x130b720b9d2) = CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208278);
    uVar13 = _DAT_130b72034f4;
    uVar18 = (ulonglong)_DAT_130b72034f4;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b72034f4;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b72034f4 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b72034f8 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7203500);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b72034f8 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f1922;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72034f8 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f1922:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1943;
      }
LAB_130b71f4835:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0ca7000001f9);
      goto LAB_130b71f4855;
    }
LAB_130b71f1943:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(ulonglong *)(lVar11 + 0x130b720b9da) = CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208288);
    uVar13 = _DAT_130b7203534;
    uVar18 = (ulonglong)_DAT_130b7203534;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b7203534;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b7203534 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7203538 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7203540);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7203538 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f1b42;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203538 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f1b42:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1b63;
      }
      goto LAB_130b71f48d5;
    }
LAB_130b71f1b63:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(ulonglong *)(lVar11 + 0x130b720b9e2) = CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b7208298);
    uVar13 = _DAT_130b720412c;
    uVar18 = (ulonglong)_DAT_130b720412c;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b720412c;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b720412c + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7204130 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7204138);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7204130 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f1d62;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204130 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f1d62:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1d83;
      }
LAB_130b71f4815:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x270ca9000001f9);
      goto LAB_130b71f4835;
    }
LAB_130b71f1d83:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(ulonglong *)(lVar11 + 0x130b720b9ea) = CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082a8);
    uVar13 = _DAT_130b7203554;
    uVar18 = (ulonglong)_DAT_130b7203554;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b7203554;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b7203554 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7203558 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7203560);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7203558 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f1f82;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203558 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f1f82:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f1fa3;
      }
      goto LAB_130b71f48b5;
    }
LAB_130b71f1fa3:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(longlong *)(lVar11 + 0x130b720b9f2) = (longlong)(double)CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082b8);
    uVar13 = _DAT_130b7203574;
    uVar18 = (ulonglong)_DAT_130b7203574;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b7203574;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b7203574 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7203578 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7203580);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7203578 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f21b2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203578 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f21b2:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f21d3;
      }
LAB_130b71f47f5:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0cab000001f9);
      goto LAB_130b71f4815;
    }
LAB_130b71f21d3:
    uVar8 = FUN_130b71effc0(&local_138);
    *(undefined8 *)(lVar11 + 0x130b720b9fa) = uVar8;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082c8);
    uVar13 = _DAT_130b7203594;
    uVar18 = (ulonglong)_DAT_130b7203594;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b7203594;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b7203594 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7203598 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b72035a0);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7203598 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f2322;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7203598 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f2322:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f2343;
      }
      goto LAB_130b71f4895;
    }
LAB_130b71f2343:
    uVar8 = FUN_130b71effc0(&local_138);
    *(undefined8 *)(lVar11 + 0x130b720ba02) = uVar8;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082d8);
    uVar13 = _DAT_130b72035b4;
    uVar18 = (ulonglong)_DAT_130b72035b4;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b72035b4;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b72035b4 + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b72035b8 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b72035c0);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b72035b8 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f2492;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b72035b8 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f2492:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f24b3;
      }
LAB_130b71f47d5:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x300cad000001f9);
      goto LAB_130b71f47f5;
    }
LAB_130b71f24b3:
    uVar8 = FUN_130b71effc0(&local_138);
    *(undefined8 *)(lVar11 + 0x130b720ba0a) = uVar8;
    *(undefined1 *)(lVar11 + 0x130b720ba12) = 0;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082e8);
    uVar13 = _DAT_130b720413c;
    uVar18 = (ulonglong)_DAT_130b720413c;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b720413c;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b720413c + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 != '\0') {
        if (uVar18 != 0) {
          lVar1 = local_134 + (ulonglong)uVar12 * 2;
          if (uVar13 < 8) {
            uVar10 = 0;
          }
          else if (local_134 + -0x130b7204140 + (ulonglong)uVar12 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar14 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar8 = *(undefined8 *)(uVar14 + 0x130b7204148);
              puVar2 = (undefined8 *)(lVar1 + uVar14);
              *puVar2 = *(undefined8 *)(&DAT_130b7204140 + uVar14);
              puVar2[1] = uVar8;
              uVar14 = uVar14 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
            if (uVar10 == uVar18) goto LAB_130b71f2602;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204140 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar18 != uVar10);
        }
LAB_130b71f2602:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_130b71f2623;
      }
      goto LAB_130b71f4875;
    }
LAB_130b71f2623:
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(bool *)(lVar11 + 0x130b720ba13) =
         dVar20 <= (double)CONCAT44(uVar23,uVar22) && (double)CONCAT44(uVar23,uVar22) != dVar20;
    FUN_130b71d0a30(&local_138,&local_118,0,0x130b72082f8);
    uVar13 = _DAT_130b720414c;
    uVar18 = (ulonglong)_DAT_130b720414c;
    if ((uVar18 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar12 = 0;
        uVar17 = _DAT_130b720414c;
      }
      else {
        uVar12 = *(uint *)(local_134 + -4);
        uVar17 = _DAT_130b720414c + uVar12;
      }
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar5 = FUN_130b71d0060(&local_138,uVar16);
      if (cVar5 == '\0') {
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0cb0000001f9);
        goto LAB_130b71f47d5;
      }
      if (uVar18 != 0) {
        lVar1 = local_134 + (ulonglong)uVar12 * 2;
        if (uVar13 < 8) {
          uVar10 = 0;
        }
        else if (local_134 + -0x130b7204150 + (ulonglong)uVar12 * 2 < 0x20) {
          uVar10 = 0;
        }
        else {
          uVar14 = 0;
          uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
          do {
            uVar8 = *(undefined8 *)(uVar14 + 0x130b7204158);
            puVar2 = (undefined8 *)(lVar1 + uVar14);
            *puVar2 = *(undefined8 *)(&DAT_130b7204150 + uVar14);
            puVar2[1] = uVar8;
            uVar14 = uVar14 + 0x10;
          } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar14);
          if (uVar10 == uVar18) goto LAB_130b71f2822;
        }
        do {
          *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_130b7204150 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar18 != uVar10);
      }
LAB_130b71f2822:
      *(uint *)(local_134 + -4) = uVar17;
      *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
    }
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(&local_138);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    *(ulonglong *)(lVar11 + 0x130b720ba14) = CONCAT44(uVar23,uVar22);
    if (((&DAT_130b720b9d0)[lVar11] != '\0') &&
       (((*(double *)(lVar11 + 0x130b720b9da) <= 0.0 || (*(double *)(lVar11 + 0x130b720b9e2) <= 0.0)
         ) || (*(double *)(lVar11 + 0x130b720b9ea) <= 0.0)))) {
      (&DAT_130b720b9d0)[lVar11] = '\0';
    }
    FUN_130b71d0000(&local_118);
    uVar13 = 1;
    uVar22 = 0;
    uVar23 = 0;
    uVar8 = 0;
  } while ((local_11c & 1) != 0);
  iVar6 = FUN_130b71efc10();
  local_128 = 0;
  local_124 = 0;
  FUN_130b71ea9d0(0x130b7203da8);
  bVar19 = true;
  FUN_130b71d0a30(&local_138,0x130b720bb3c,1,0x130b7208308);
  FUN_130b71d0a30(&local_128,&local_138,0,0x130b7208318);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_128);
  if ((cVar5 != '\0') &&
     ((*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_128), iVar6 == (int)_DAT_130b720bb48)) {
    bVar19 = false;
  }
  local_98 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_e8 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_b4 = 0;
  local_c4 = 0;
  local_d4 = 0;
  local_e4 = 0;
  local_f4 = 0;
  local_104 = 0;
  FUN_130b71ea9d0(0x130b7204178);
  bVar4 = 1;
  FUN_130b71d0a30(&local_108,0x130b720bb3c,1,0x130b7208198);
  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_108);
  if (cVar5 != '\0') {
    FUN_130b71ea9d0(0x130b72041a8);
    bVar4 = 1;
    FUN_130b71d0a30(&local_f8,0x130b720bb3c,1,0x130b72081a8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_f8);
    if (cVar5 != '\0') {
      FUN_130b71ea9d0(0x130b72041d8);
      bVar4 = 1;
      FUN_130b71d0a30(&local_e8,0x130b720bb3c,1,0x130b72081b8);
      cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_e8);
      if (cVar5 != '\0') {
        FUN_130b71ea9d0(0x130b7204208);
        bVar4 = 1;
        FUN_130b71d0a30(&local_d8,0x130b720bb3c,1,0x130b72081c8);
        cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_d8);
        if (cVar5 != '\0') {
          FUN_130b71ea9d0(0x130b7204238);
          bVar4 = 1;
          FUN_130b71d0a30(&local_c8,0x130b720bb3c,1,0x130b72081d8);
          cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_c8);
          if (cVar5 != '\0') {
            FUN_130b71ea9d0(0x130b7204268);
            bVar4 = 1;
            FUN_130b71d0a30(&local_b8,0x130b720bb3c,1,0x130b72081e8);
            cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_b8);
            if (cVar5 != '\0') {
              FUN_130b71ea9d0(0x130b7204298);
              bVar4 = 1;
              FUN_130b71d0a30(&local_a8,0x130b720bb3c,1,0x130b72081f8);
              cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_a8);
              if (cVar5 != '\0') {
                FUN_130b71ea9d0(0x130b72042c8);
                bVar4 = 1;
                FUN_130b71d0a30(&local_98,0x130b720bb3c,1,0x130b7208208);
                cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_98);
                if (cVar5 != '\0') {
                  local_150 = 0;
                  local_14c = 0;
                  local_160 = 0;
                  local_158 = 0;
                  FUN_130b71ea9d0(0x130b7204178);
                  bVar4 = 1;
                  FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
                  FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
                  cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
                  if (cVar5 == '\0') {
                    uVar13 = 0xffffffff;
                  }
                  else {
                    (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
                    uVar13 = (uint)_DAT_130b720bb48;
                  }
                  FUN_130b71d0000(&local_160);
                  FUN_130b71d0000(&local_150);
                  if (_DAT_130b720bc50 == uVar13) {
                    if (uVar13 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71f2e67 */
                    /* WARNING: Treating indirect jump as call */
                      (**(code **)((ulonglong)uVar13 * 8 + 0x130b72015b0))();
                      return;
                    }
                    local_150 = 0;
                    local_14c = 0;
                    local_160 = 0;
                    local_158 = 0;
                    FUN_130b71ea9d0(0x130b7204298);
                    bVar4 = 1;
                    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
                    bVar15 = false;
                    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
                    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
                    if (cVar5 != '\0') {
                      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
                      bVar15 = _DAT_130b7201570 < _DAT_130b720bb48;
                    }
                    FUN_130b71d0000(&local_160);
                    FUN_130b71d0000(&local_150);
                    if (((bool)local_13d == bVar15) &&
                       ((local_13d == '\0' ||
                        (dVar20 = (double)FUN_130b71efed0(0x130b72042c8,0),
                        (double)((ulonglong)(dVar20 - _DAT_130b720bc88) & _DAT_130b7201580) <=
                        _DAT_130b7201590)))) {
                      bVar4 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  FUN_130b71d0000(&local_108);
  FUN_130b71d0000(&local_f8);
  FUN_130b71d0000(&local_e8);
  FUN_130b71d0000(&local_d8);
  FUN_130b71d0000(&local_c8);
  FUN_130b71d0000(&local_b8);
  FUN_130b71d0000(&local_a8);
  FUN_130b71d0000(&local_98);
  _DAT_130b720b9bc = iVar6;
  if (bVar19) {
    local_13b = '\0';
    local_13c = '\0';
    FUN_130b71f08e0(&local_13b,&local_13c);
    DAT_130b720b95d = '\0';
    DAT_130b720b95c = '\0';
    _DAT_130b720b960 = 0.0;
    _DAT_130b720b970 = 0.0;
    DAT_130b720b9c0 = local_13b;
    DAT_130b720b9c1 = local_13c;
    _DAT_130b720b90c = -1;
    _DAT_130b720b968 = 0.0;
    _DAT_130b720b978 = 0.0;
    FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
    _DAT_130b720b998 = 0.0;
    _DAT_130b720b9a0 = 0.0;
    _DAT_130b720b990 = 0.0;
    _DAT_130b720b9a8 = 0.0;
    FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
LAB_130b71f44e1:
    DAT_130b720b9c2 = 1;
  }
  else {
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(0x130b7203dd8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 == '\0') {
      uVar22 = (undefined4)_DAT_130b7201598;
      uVar23 = (undefined4)((ulonglong)_DAT_130b7201598 >> 0x20);
    }
    else {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    _DAT_130b720b90c = (int)(double)CONCAT44(uVar23,uVar22);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(0x130b7203e08);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    DAT_130b720b9c0 =
         _DAT_130b7201570 <= (double)CONCAT44(uVar25,uVar24) &&
         (double)CONCAT44(uVar25,uVar24) != _DAT_130b7201570;
    FUN_130b71ea9d0(0x130b7203e38);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    DAT_130b720b9c1 =
         _DAT_130b7201570 <= (double)CONCAT44(uVar23,uVar22) &&
         (double)CONCAT44(uVar23,uVar22) != _DAT_130b7201570;
    FUN_130b71ea9d0(0x130b7203e68);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    DAT_130b720b95c =
         _DAT_130b7201570 <= (double)CONCAT44(uVar25,uVar24) &&
         (double)CONCAT44(uVar25,uVar24) != _DAT_130b7201570;
    FUN_130b71ea9d0(0x130b7203e98);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b960 = (double)CONCAT44(uVar23,uVar22);
    FUN_130b71ea9d0(0x130b7203ec8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b968 = (double)CONCAT44(uVar25,uVar24);
    FUN_130b71ea9d0(0x130b7203ef8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b970 = (double)CONCAT44(uVar23,uVar22);
    FUN_130b71ea9d0(0x130b7203f28);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    _DAT_130b720b978 = (double)CONCAT44(uVar25,uVar24);
    FUN_130b71d0a30(0x130b720b980,0x130b720bc20,0,0x130b7208328);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    FUN_130b71ea9d0(0x130b7203f58);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    DAT_130b720b95d =
         _DAT_130b7201570 <= (double)CONCAT44(uVar23,uVar22) &&
         (double)CONCAT44(uVar23,uVar22) != _DAT_130b7201570;
    FUN_130b71ea9d0(0x130b7203f88);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b990 = (double)CONCAT44(uVar25,uVar24);
    FUN_130b71ea9d0(0x130b7203fb8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b998 = (double)CONCAT44(uVar23,uVar22);
    FUN_130b71ea9d0(0x130b7203fe8);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar24 = SUB84(_DAT_130b720bb48,0);
      uVar25 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    local_150 = 0;
    local_14c = 0;
    local_160 = 0;
    local_158 = 0;
    _DAT_130b720b9a0 = (double)CONCAT44(uVar25,uVar24);
    FUN_130b71ea9d0(0x130b7204018);
    FUN_130b71d0a30(&local_150,0x130b720bb3c,1,0x130b72080b8);
    FUN_130b71d0a30(&local_160,&local_150,0,0x130b72080c8);
    cVar5 = (*(code *)0x7ff63a0edda0)(0x130b53f81d8,&local_160);
    if (cVar5 != '\0') {
      (*(code *)0x7ff63a0edbe0)(0x130b53f81d8,&local_160);
      uVar22 = SUB84(_DAT_130b720bb48,0);
      uVar23 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    }
    FUN_130b71d0000(&local_160);
    FUN_130b71d0000(&local_150);
    _DAT_130b720b9a8 = (double)CONCAT44(uVar23,uVar22);
    FUN_130b71d0a30(0x130b720b9b0,0x130b720bc20,0,0x130b7208338);
    local_139 = '\0';
    local_13a = '\0';
    FUN_130b71f08e0(&local_139,&local_13a);
    DAT_130b720b9c0 = DAT_130b720b9c0 != '\0' || local_139 != '\0';
    DAT_130b720b9c1 = DAT_130b720b9c1 != '\0' || local_13a != '\0';
    dVar20 = _DAT_130b720bb18 + _DAT_130b720bb18;
    if (DAT_130b720b95c != '\0') {
      (*(code *)0x7ff63a103c40)(0x130b53f81d8,0x130b7201850,0x4018,0);
      if (_DAT_130b720bc90 == 1) {
        dVar21 = _DAT_130b720b960 - _DAT_130b720b3d0;
      }
      else {
        dVar21 = _DAT_130b720b960 - 0.0;
      }
      if (dVar21 - dVar20 <= _DAT_130b720bb48) {
        DAT_130b720b9c0 = '\x01';
      }
    }
    if (DAT_130b720b95d != '\0') {
      (*(code *)0x7ff63a103cc0)(0x130b53f81d8,0x130b7201850,0x4018,0);
      dVar21 = _DAT_130b720b3d0;
      if (_DAT_130b720bc90 != 1) {
        dVar21 = _DAT_130b72015a0;
      }
      if (_DAT_130b720bb48 <= dVar20 + dVar21 + _DAT_130b720b990) {
        DAT_130b720b9c1 = '\x01';
      }
    }
    if (DAT_130b720b9c0 != '\0') {
      DAT_130b720b95c = '\0';
    }
    if (DAT_130b720b9c1 != '\0') {
      DAT_130b720b95d = '\0';
    }
    if ((DAT_130b720b95c == '\0') ||
       ((((0.0 < _DAT_130b720b960 && (0.0 < _DAT_130b720b968)) && (0.0 < _DAT_130b720b970)) &&
        (0.0 < _DAT_130b720b978)))) {
      if (DAT_130b720b95d != '\0') {
        bVar19 = false;
        goto LAB_130b71f439c;
      }
      bVar19 = true;
      if (-1 < _DAT_130b720b90c) goto LAB_130b71f44ee;
LAB_130b71f44d9:
      if ((DAT_130b720b95c == '\0') && (bVar19)) goto LAB_130b71f44e1;
    }
    else {
      bVar19 = true;
      if (DAT_130b720b95d == '\0') {
LAB_130b71f43cc:
        _DAT_130b720b968 = 0.0;
        DAT_130b720b95c = '\0';
        _DAT_130b720b970 = 0.0;
        _DAT_130b720b978 = 0.0;
        DAT_130b720b95d = '\0';
        _DAT_130b720b960 = 0.0;
        FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
        _DAT_130b720b990 = 0.0;
        _DAT_130b720b9a0 = 0.0;
        _DAT_130b720b9a8 = 0.0;
        _DAT_130b720b998 = 0.0;
        FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
        bVar19 = DAT_130b720b95d == '\0';
        DAT_130b720b9c2 = 1;
        _DAT_130b720b90c = -1;
        goto LAB_130b71f44d9;
      }
LAB_130b71f439c:
      if (((bVar19) || (_DAT_130b720b990 <= 0.0)) ||
         ((_DAT_130b720b998 <= 0.0 || ((_DAT_130b720b9a0 <= 0.0 || (_DAT_130b720b9a8 <= 0.0))))))
      goto LAB_130b71f43cc;
    }
  }
LAB_130b71f44ee:
  cVar5 = local_13d;
  if ((!(bool)(bVar4 ^ 1 | local_13d == '\0')) && (DAT_130b720b944 != '\0')) {
    _DAT_130b720b948 = _DAT_130b720bc88;
  }
  dVar20 = _DAT_130b720b978;
  if ((bool)(DAT_130b720b95c != '\0' & bVar4)) {
    if ((_DAT_130b720bc50 == 3) &&
       (_DAT_130b720b388 = _DAT_130b72015a8, (ulonglong)_DAT_130b720bc58 < 8)) {
      _DAT_130b720b388 = *(undefined8 *)((ulonglong)_DAT_130b720bc58 * 8 + 0x130b7209eb0);
    }
    dVar20 = (double)FUN_130b71ef790(_DAT_130b720bc50,_DAT_130b720bc60,_DAT_130b720bc68,
                                     _DAT_130b720bc70,_DAT_130b720bc78,
                                     (ulonglong)(_DAT_130b720b960 - _DAT_130b720b968) &
                                     _DAT_130b7201580,_DAT_130b720b388);
    if ((cVar5 != '\0') && (DAT_130b720b944 != '\0')) {
      dVar20 = (double)FUN_130b71eefc0(dVar20 * _DAT_130b720b948);
    }
  }
  _DAT_130b720b978 = dVar20;
  dVar20 = _DAT_130b720b9a8;
  if ((bool)(bVar4 & DAT_130b720b95d != '\0')) {
    if ((_DAT_130b720bc50 == 3) &&
       (_DAT_130b720b388 = _DAT_130b72015a8, (ulonglong)_DAT_130b720bc58 < 8)) {
      _DAT_130b720b388 = *(undefined8 *)((ulonglong)_DAT_130b720bc58 * 8 + 0x130b7209eb0);
    }
    dVar20 = (double)FUN_130b71ef790(_DAT_130b720bc50,_DAT_130b720bc60,_DAT_130b720bc68,
                                     _DAT_130b720bc70,_DAT_130b720bc78,
                                     (ulonglong)(_DAT_130b720b990 - _DAT_130b720b998) &
                                     _DAT_130b7201580,_DAT_130b720b388);
    if ((cVar5 != '\0') && (DAT_130b720b944 != '\0')) {
      dVar20 = (double)FUN_130b71eefc0(dVar20 * _DAT_130b720b948);
    }
  }
  _DAT_130b720b9a8 = dVar20;
  FUN_130b71d0000(&local_128);
LAB_130b71f4777:
  FUN_130b71d0000(&local_138);
  return;
}



/* Address: 130b71f4940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71f4940(undefined8 param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  if ((_DAT_130b720bc50 == 3) &&
     (_DAT_130b720b388 = _DAT_130b72015d0, (ulonglong)_DAT_130b720bc58 < 8)) {
    _DAT_130b720b388 = *(undefined8 *)((ulonglong)_DAT_130b720bc58 * 8 + 0x130b7209eb0);
  }
  dVar9 = (double)FUN_130b71ef790(_DAT_130b720bc50,_DAT_130b720bc60,_DAT_130b720bc68,
                                  _DAT_130b720bc70,_DAT_130b720bc78,param_1,_DAT_130b720b388);
  if ((DAT_130b720bc80 != '\0') && (DAT_130b720b944 != '\0')) {
    dVar9 = dVar9 * _DAT_130b720b948;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x22);
    dVar11 = _DAT_130b720bb48;
    uVar14 = SUB84(_DAT_130b720bb48,0);
    uVar15 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x23);
    dVar8 = _DAT_130b720bb48;
    uVar12 = SUB84(_DAT_130b720bb48,0);
    uVar2 = (ulonglong)_DAT_130b720bb48 >> 0x20;
    (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x24);
    dVar6 = dVar11;
    if (dVar11 <= dVar9) {
      dVar6 = dVar9;
    }
    dVar9 = dVar8;
    if (dVar6 <= dVar8) {
      dVar9 = dVar6;
    }
    if (0.0 < _DAT_130b720bb48) {
      if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2e09dd000001f7);
        pcVar1 = (code *)swi(3);
        dVar9 = (double)(*pcVar1)();
        return dVar9;
      }
      dVar10 = (dVar9 + _DAT_130b72014f0 * _DAT_130b720bb48) / _DAT_130b720bb48;
      dVar6 = ABS(dVar10);
      uVar5 = (uint)((ulonglong)dVar6 >> 0x20);
      dVar9 = dVar10;
      if (uVar5 >> 0x14 < 0x3ff) {
        if ((dVar6 != 0.0) && (dVar9 = 0.0, (longlong)dVar10 < 0)) {
          dVar9 = _DAT_130b72014f8;
        }
      }
      else if (((uVar5 >> 0x16 < 0x10d) &&
               (bVar3 = 0x33 - (char)((ulonglong)dVar6 >> 0x34),
               dVar7 = (double)(((ulonglong)dVar6 >> (bVar3 & 0x3f)) << (bVar3 & 0x3f)),
               dVar9 = dVar7, (longlong)dVar10 < 1)) &&
              (dVar9 = (double)((ulonglong)dVar7 | 0x8000000000000000), dVar7 != dVar6)) {
        dVar9 = dVar9 + _DAT_130b72014f8;
      }
      dVar9 = dVar9 * _DAT_130b720bb48;
    }
    if (dVar11 <= dVar9) {
      uVar14 = SUB84(dVar9,0);
      uVar15 = (undefined4)((ulonglong)dVar9 >> 0x20);
    }
    lVar4 = 2;
    uVar13 = (int)uVar2;
    if ((double)CONCAT44(uVar15,uVar14) <= dVar8) {
      uVar12 = uVar14;
      uVar13 = uVar15;
    }
    dVar9 = (double)CONCAT44(uVar13,uVar12);
    if (0.0 < _DAT_130b720bb48) {
      uVar5 = (uint)((ulonglong)_DAT_130b720bb48 >> 0x34) & 0x7ff;
      lVar4 = (ulonglong)uVar5 - 0x3ff;
      dVar11 = _DAT_130b720bb48;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar4 != -1) {
            dVar11 = (double)((ulonglong)_DAT_130b720bb48 & 0x8000000000000000);
          }
        }
        else {
          bVar3 = (byte)lVar4;
          if (((longlong)_DAT_130b720bb48 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)_DAT_130b720bb48 &
                             -0x10000000000000 >> (bVar3 & 0x3f));
          }
        }
      }
      else if (lVar4 == 0x400) {
        dVar11 = _DAT_130b720bb48 + _DAT_130b720bb48;
      }
      if ((double)((ulonglong)(_DAT_130b720bb48 - dVar11) & _DAT_130b7201500) <= _DAT_130b7201510) {
        lVar4 = 0;
      }
      else {
        dVar8 = _DAT_130b720bb48 * _DAT_130b7201518;
        uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
        lVar4 = (ulonglong)uVar5 - 0x3ff;
        dVar11 = dVar8;
        if ((ulonglong)uVar5 < 0x433) {
          if (uVar5 < 0x3ff) {
            dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar4 != -1) {
              dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
            }
          }
          else {
            bVar3 = (byte)lVar4;
            if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
              dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                               -0x10000000000000 >> (bVar3 & 0x3f));
            }
          }
        }
        else if (lVar4 == 0x400) {
          dVar11 = dVar8 + dVar8;
        }
        lVar4 = 1;
        if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
          dVar8 = dVar8 * _DAT_130b7201518;
          uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
          lVar4 = (ulonglong)uVar5 - 0x3ff;
          dVar11 = dVar8;
          if ((ulonglong)uVar5 < 0x433) {
            if (uVar5 < 0x3ff) {
              dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
              if (lVar4 != -1) {
                dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
              }
            }
            else {
              bVar3 = (byte)lVar4;
              if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                 -0x10000000000000 >> (bVar3 & 0x3f));
              }
            }
          }
          else if (lVar4 == 0x400) {
            dVar11 = dVar8 + dVar8;
          }
          lVar4 = 2;
          if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
            dVar8 = dVar8 * _DAT_130b7201518;
            uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
            lVar4 = (ulonglong)uVar5 - 0x3ff;
            dVar11 = dVar8;
            if ((ulonglong)uVar5 < 0x433) {
              if (uVar5 < 0x3ff) {
                dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar4 != -1) {
                  dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                }
              }
              else {
                bVar3 = (byte)lVar4;
                if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                   -0x10000000000000 >> (bVar3 & 0x3f));
                }
              }
            }
            else if (lVar4 == 0x400) {
              dVar11 = dVar8 + dVar8;
            }
            lVar4 = 3;
            if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
              dVar8 = dVar8 * _DAT_130b7201518;
              uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
              lVar4 = (ulonglong)uVar5 - 0x3ff;
              dVar11 = dVar8;
              if ((ulonglong)uVar5 < 0x433) {
                if (uVar5 < 0x3ff) {
                  dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                  if (lVar4 != -1) {
                    dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                  }
                }
                else {
                  bVar3 = (byte)lVar4;
                  if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                     -0x10000000000000 >> (bVar3 & 0x3f));
                  }
                }
              }
              else if (lVar4 == 0x400) {
                dVar11 = dVar8 + dVar8;
              }
              lVar4 = 4;
              if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                dVar8 = dVar8 * _DAT_130b7201518;
                uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
                lVar4 = (ulonglong)uVar5 - 0x3ff;
                dVar11 = dVar8;
                if ((ulonglong)uVar5 < 0x433) {
                  if (uVar5 < 0x3ff) {
                    dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                    if (lVar4 != -1) {
                      dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                    }
                  }
                  else {
                    bVar3 = (byte)lVar4;
                    if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                      dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                       -0x10000000000000 >> (bVar3 & 0x3f));
                    }
                  }
                }
                else if (lVar4 == 0x400) {
                  dVar11 = dVar8 + dVar8;
                }
                lVar4 = 5;
                if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                  dVar8 = dVar8 * _DAT_130b7201518;
                  uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
                  lVar4 = (ulonglong)uVar5 - 0x3ff;
                  dVar11 = dVar8;
                  if ((ulonglong)uVar5 < 0x433) {
                    if (uVar5 < 0x3ff) {
                      dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000);
                      if (lVar4 != -1) {
                        dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                      }
                    }
                    else {
                      bVar3 = (byte)lVar4;
                      if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                        dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                         -0x10000000000000 >> (bVar3 & 0x3f));
                      }
                    }
                  }
                  else if (lVar4 == 0x400) {
                    dVar11 = dVar8 + dVar8;
                  }
                  lVar4 = 6;
                  if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500)) {
                    dVar8 = dVar8 * _DAT_130b7201518;
                    uVar5 = (uint)((ulonglong)dVar8 >> 0x34) & 0x7ff;
                    lVar4 = (ulonglong)uVar5 - 0x3ff;
                    dVar11 = dVar8;
                    if ((ulonglong)uVar5 < 0x433) {
                      if (uVar5 < 0x3ff) {
                        dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000 | 0x3ff0000000000000
                                         );
                        if (lVar4 != -1) {
                          dVar11 = (double)((ulonglong)dVar8 & 0x8000000000000000);
                        }
                      }
                      else {
                        bVar3 = (byte)lVar4;
                        if (((longlong)dVar8 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
                          dVar11 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)dVar8 &
                                           -0x10000000000000 >> (bVar3 & 0x3f));
                        }
                      }
                    }
                    else if (lVar4 == 0x400) {
                      dVar11 = dVar8 + dVar8;
                    }
                    lVar4 = 7;
                    if (_DAT_130b7201510 < (double)((ulonglong)(dVar8 - dVar11) & _DAT_130b7201500))
                    {
                      lVar4 = 8;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ((longlong)(double)CONCAT44(uVar13,uVar12) != -0x8000000000000000) {
      dVar9 = (double)(longlong)(double)CONCAT44(uVar13,uVar12);
      dVar9 = (double)(longlong)
                      (((double)CONCAT44(uVar13,uVar12) - dVar9) *
                       *(double *)(&DAT_130b7201710 + lVar4 * 8) +
                      *(double *)
                       ((ulonglong)
                        (0.0 <= (double)CONCAT44(uVar13,uVar12) &&
                        (double)CONCAT44(uVar13,uVar12) != 0.0) * 8 + 0x130b7201520)) /
              *(double *)(&DAT_130b7201710 + lVar4 * 8) + dVar9;
    }
    return dVar9;
  }
  return dVar9;
}



/* Address: 130b71f4a40 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f4a40(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  double dVar5;
  undefined1 local_68 [8];
  double local_60;
  double local_58;
  
  if ((DAT_130b720ba6e == '\0') && (DAT_130b720bc18 != '\0')) {
    return;
  }
  cVar3 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,local_68);
  if (cVar3 == '\0') {
    return;
  }
  iVar4 = FUN_130b71efc10();
  uVar2 = true;
  uVar1 = true;
  if (DAT_130b720b95c != '\0') {
    if (_DAT_130b720bc90 == 1) {
      dVar5 = _DAT_130b720b960 - _DAT_130b720b3d0;
    }
    else {
      dVar5 = _DAT_130b720b960 - 0.0;
    }
    if (dVar5 <= local_58) {
      if (_DAT_130b720b9bc != iVar4) {
        _DAT_130b720b9bc = iVar4;
        FUN_130b71f08e0(&DAT_130b720b9c0,&DAT_130b720b9c1);
      }
      DAT_130b720b95c = '\0';
      DAT_130b720b9c0 = 1;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204458);
      uVar2 = false;
      uVar1 = false;
    }
  }
  if (DAT_130b720b95d != '\0') {
    dVar5 = _DAT_130b720b3d0;
    if (_DAT_130b720bc90 != 1) {
      dVar5 = _DAT_130b72015d8;
    }
    uVar1 = uVar2;
    if (local_60 <= dVar5 + _DAT_130b720b990) {
      if (_DAT_130b720b9bc != iVar4) {
        _DAT_130b720b9bc = iVar4;
        FUN_130b71f08e0(&DAT_130b720b9c0,&DAT_130b720b9c1);
      }
      DAT_130b720b95d = '\0';
      DAT_130b720b9c1 = 1;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204498);
      goto LAB_130b71f4c6c;
    }
  }
  if ((bool)uVar1) {
    return;
  }
LAB_130b71f4c6c:
  FUN_130b71e8bd0();
  return;
}



/* Address: 130b71f4c90 */

undefined8 FUN_130b71f4c90(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 local_a0 [12];
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  undefined1 local_80 [12];
  int local_74;
  int local_70;
  int local_6c;
  undefined1 local_60 [12];
  int local_54;
  int local_50;
  int local_4c;
  
  uVar3 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  (*(code *)0x7ff63a101f60)(0x130b53f81d8,uVar3,local_a0);
  local_a8 = 0;
  local_b0 = 0;
  iVar5 = local_90 * 0x3c + local_94 * 0xe10 + local_8c;
  cVar1 = (*(code *)0x7ff63a0f2cb0)(0x130b53f81d8,0x130b7201850,local_88,0,&local_a8,&local_b0);
  if (cVar1 != '\0') {
    iVar6 = 1;
    do {
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_a8,local_60);
      (*(code *)0x7ff63a101f60)(0x130b53f81d8,local_b0,local_80);
      iVar4 = local_50 * 0x3c + local_54 * 0xe10 + local_4c;
      iVar2 = local_70 * 0x3c + local_74 * 0xe10 + local_6c;
      if (iVar4 < iVar2) {
        if ((iVar4 <= iVar5) && (iVar5 < iVar2)) {
          return 1;
        }
      }
      else {
        if (iVar4 <= iVar2) {
          return 1;
        }
        if (iVar4 <= iVar5) {
          return 1;
        }
        if (iVar5 < iVar2) {
          return 1;
        }
      }
      local_a8 = 0;
      local_b0 = 0;
      cVar1 = (*(code *)0x7ff63a0f2cb0)
                        (0x130b53f81d8,0x130b7201850,local_88,iVar6,&local_a8,&local_b0);
      iVar6 = iVar6 + 1;
    } while (cVar1 != '\0');
  }
  return 0;
}



/* Address: 130b71f4e60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71f4e60(double param_1)

{
  longlong lVar1;
  code *pcVar2;
  byte bVar3;
  ulonglong uVar4;
  uint uVar5;
  double dVar6;
  
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
  if (_DAT_130b720bb48 <= 0.0) {
    if ((longlong)param_1 != -0x8000000000000000) {
      dVar6 = (double)(longlong)param_1;
      uVar4 = 0xb;
      if (_DAT_130b720bb20 < 0xb) {
        uVar4 = (ulonglong)_DAT_130b720bb20;
      }
      param_1 = (double)(longlong)
                        ((param_1 - dVar6) * *(double *)(&DAT_130b7201710 + uVar4 * 8) +
                        *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x130b72015e0)) /
                *(double *)(&DAT_130b7201710 + uVar4 * 8) + dVar6;
    }
  }
  else {
    if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0dc4000001f7);
      pcVar2 = (code *)swi(3);
      dVar6 = (double)(*pcVar2)();
      return dVar6;
    }
    param_1 = param_1 / _DAT_130b720bb48;
    uVar5 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar5 - 0x3ff;
    dVar6 = param_1;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar6 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar6 = (double)((ulonglong)param_1 & 0x8000000000000000);
        }
      }
      else {
        bVar3 = (byte)lVar1;
        if (((longlong)param_1 << (bVar3 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar6 = (double)((0x8000000000000U >> (bVar3 & 0x3f)) + (longlong)param_1 &
                          -0x10000000000000 >> (bVar3 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar6 = param_1 + param_1;
    }
    param_1 = _DAT_130b720bb48 * dVar6;
    if ((longlong)param_1 != -0x8000000000000000) {
      dVar6 = (double)(longlong)param_1;
      uVar4 = 0xb;
      if (_DAT_130b720bb20 < 0xb) {
        uVar4 = (ulonglong)_DAT_130b720bb20;
      }
      param_1 = (double)(longlong)
                        ((param_1 - dVar6) * *(double *)(&DAT_130b7201710 + uVar4 * 8) +
                        *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x130b72015e0)) /
                *(double *)(&DAT_130b7201710 + uVar4 * 8) + dVar6;
    }
  }
  return param_1;
}



/* Address: 130b71f5060 */

void FUN_130b71f5060(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2a0dc4000001f7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 130b71f5090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_130b71f5090(int param_1,double param_2)

{
  code *pcVar1;
  byte bVar2;
  double *pdVar3;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
  if (_DAT_130b720bb48 <= 0.0) {
    if ((longlong)param_2 == -0x8000000000000000) {
      return param_2;
    }
    dVar8 = (double)(longlong)param_2;
    uVar4 = 0xb;
    if (_DAT_130b720bb20 < 0xb) {
      uVar4 = (ulonglong)_DAT_130b720bb20;
    }
    return (double)(longlong)
                   ((param_2 - dVar8) * *(double *)(&DAT_130b7201710 + uVar4 * 8) +
                   *(double *)((ulonglong)(0.0 < param_2) * 8 + 0x130b72015f0)) /
           *(double *)(&DAT_130b7201710 + uVar4 * 8) + dVar8;
  }
  if ((_DAT_130b720bb48 == 0.0) && (!NAN(_DAT_130b720bb48))) {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x200dcd000001f7);
    pcVar1 = (code *)swi(3);
    dVar8 = (double)(*pcVar1)();
    return dVar8;
  }
  if (param_1 == 0) {
    dVar5 = param_2 / _DAT_130b720bb48 + _DAT_130b7201628;
    dVar7 = ABS(dVar5);
    dVar8 = dVar5;
    if (0x3fefffffffffffff < (ulonglong)dVar7) {
      if ((((uint)((ulonglong)dVar7 >> 0x36) < 0x10d) &&
          (bVar2 = 0x33 - (char)((ulonglong)dVar7 >> 0x34),
          dVar6 = (double)(((ulonglong)dVar7 >> (bVar2 & 0x3f)) << (bVar2 & 0x3f)), dVar8 = dVar6,
          (longlong)dVar5 < 1)) &&
         (dVar8 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar7)) {
        dVar8 = (double)((ulonglong)dVar6 | 0x8000000000000000) + _DAT_130b7201630;
      }
      goto joined_r0x0130b71f53d6;
    }
    if ((dVar7 == 0.0) || (dVar8 = 0.0, -1 < (longlong)dVar5)) goto joined_r0x0130b71f53d6;
    pdVar3 = (double *)&DAT_130b7201630;
  }
  else {
    dVar8 = param_2 / _DAT_130b720bb48 + _DAT_130b7201600;
    dVar7 = (double)(_DAT_130b7201610 & (ulonglong)dVar8);
    if (0x3fefffffffffffff < (ulonglong)dVar7) {
      if ((uint)((ulonglong)dVar7 >> 0x36) < 0x10d) {
        bVar2 = 0x33 - (char)((ulonglong)dVar7 >> 0x34);
        dVar5 = (double)(((ulonglong)dVar7 >> (bVar2 & 0x3f)) << (bVar2 & 0x3f));
        if ((longlong)dVar8 < 0) {
          dVar8 = (double)((ulonglong)dVar5 | 0x8000000000000000);
        }
        else {
          dVar8 = dVar7;
          if (dVar5 != dVar7) {
            dVar8 = dVar5 + _DAT_130b7201620;
          }
        }
      }
      goto joined_r0x0130b71f53d6;
    }
    if ((dVar7 == 0.0) || (dVar8 = (double)((ulonglong)dVar8 & 0x8000000000000000), dVar8 != 0.0))
    goto joined_r0x0130b71f53d6;
    pdVar3 = (double *)&DAT_130b7201620;
  }
  dVar8 = *pdVar3;
joined_r0x0130b71f53d6:
  dVar8 = _DAT_130b720bb48 * dVar8;
  if ((longlong)dVar8 != -0x8000000000000000) {
    dVar7 = (double)(longlong)dVar8;
    uVar4 = 0xb;
    if (_DAT_130b720bb20 < 0xb) {
      uVar4 = (ulonglong)_DAT_130b720bb20;
    }
    dVar8 = (double)(longlong)
                    ((dVar8 - dVar7) * *(double *)(&DAT_130b7201710 + uVar4 * 8) +
                    *(double *)((ulonglong)(0.0 < dVar8) * 8 + 0x130b72015f0)) /
            *(double *)(&DAT_130b7201710 + uVar4 * 8) + dVar7;
  }
  return dVar8;
}



/* Address: 130b71f5400 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f5400(char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,longlong param_7)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  double dVar4;
  undefined8 uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  undefined8 unaff_R13;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uStack_b0;
  longlong lStack_ac;
  char cStack_9d;
  uint uStack_9c;
  undefined4 uStack_98;
  undefined8 uStack_94;
  undefined4 uStack_88;
  undefined8 uStack_84;
  undefined8 uStack_40;
  
  lVar14 = (ulonglong)(param_1 == '\0') * 0x4c;
  *(undefined8 *)(lVar14 + 0x130b720b9d8) = 0;
  *(undefined8 *)(&DAT_130b720b9d0 + lVar14) = 0;
  (&DAT_130b720b9d0)[lVar14] = 1;
  *(undefined8 *)(&DAT_130b720b9e0 + lVar14) = 0;
  *(undefined8 *)(lVar14 + 0x130b720b9e8) = 0;
  *(undefined8 *)(&DAT_130b720b9f0 + lVar14) = 0;
  *(undefined4 *)(lVar14 + 0x130b720ba18) = 0;
  *(undefined8 *)(&DAT_130b720ba10 + lVar14) = 0;
  *(undefined8 *)(lVar14 + 0x130b720ba08) = 0;
  *(undefined8 *)(&DAT_130b720ba00 + lVar14) = 0;
  *(undefined8 *)(lVar14 + 0x130b720b9f8) = 0;
  *(char *)(lVar14 + 0x130b720b9d1) = param_1;
  *(undefined8 *)(lVar14 + 0x130b720b9d2) = param_2;
  *(undefined8 *)(lVar14 + 0x130b720b9da) = param_3;
  *(undefined8 *)(lVar14 + 0x130b720b9e2) = param_4;
  *(undefined8 *)(lVar14 + 0x130b720b9ea) = param_5;
  uStack_40 = 0x130b71f553a;
  uVar9 = (*(code *)0x7ff63a101c40)(0x130b53f81d8,0);
  *(undefined8 *)(lVar14 + 0x130b720b9f2) = uVar9;
  *(undefined8 *)(lVar14 + 0x130b720b9fa) = param_6;
  *(longlong *)(lVar14 + 0x130b720ba02) = param_7;
  *(undefined8 *)(lVar14 + 0x130b720ba0a) = 0;
  *(undefined8 *)(lVar14 + 0x130b720ba12) = 0;
  *(undefined2 *)(lVar14 + 0x130b720ba1a) = 0;
  if (param_7 != 0) {
    uStack_40 = 0x130b71f55b6;
    cVar7 = (*(code *)0x7ff63a108af0)(0x130b53f81d8,param_7);
    if (cVar7 != '\0') {
      uStack_40 = 0x130b71f55dc;
      uVar9 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_7,0xc);
      *(undefined8 *)(lVar14 + 0x130b720ba0a) = uVar9;
    }
  }
  uStack_88 = 0;
  uStack_b0 = 0;
  uStack_98 = 0;
  uStack_84 = 0;
  lStack_ac = 0;
  uStack_94 = 0;
  iVar8 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar8 == 0) {
    dVar4 = (double)_DAT_130b720b9bc;
    FUN_130b71ea9d0(0x130b7203da8);
    uVar9 = CONCAT71((int7)((ulonglong)unaff_R13 >> 8),1);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d08);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar4);
    dVar4 = (double)_DAT_130b720b90c;
    FUN_130b71ea9d0(0x130b7203dd8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d18);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar4);
    uVar20 = 0;
    uVar21 = 0;
    uVar22 = (undefined4)_DAT_130b72014a8;
    uVar23 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b9c0 != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e08);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d28);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b9c1 != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e38);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d38);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b95c != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203e68);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d48);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    uVar5 = _DAT_130b720b960;
    FUN_130b71ea9d0(0x130b7203e98);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d58);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b968;
    FUN_130b71ea9d0(0x130b7203ec8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d68);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b970;
    FUN_130b71ea9d0(0x130b7203ef8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d78);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b978;
    FUN_130b71ea9d0(0x130b7203f28);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d88);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720b95d != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7203f58);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d98);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    uVar5 = _DAT_130b720b990;
    FUN_130b71ea9d0(0x130b7203f88);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207da8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b998;
    FUN_130b71ea9d0(0x130b7203fb8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207db8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b9a0;
    FUN_130b71ea9d0(0x130b7203fe8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207dc8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar5 = _DAT_130b720b9a8;
    FUN_130b71ea9d0(0x130b7204018);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207dd8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar5);
    uVar24 = 0;
    uVar25 = 0;
    if (DAT_130b720ba6e != '\0') {
      uVar24 = uVar22;
      uVar25 = uVar23;
    }
    FUN_130b71ea9d0(0x130b7204048);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207de8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    cVar7 = DAT_130b720bc80;
    uVar24 = uVar22;
    uVar25 = uVar23;
    if (DAT_130b720b944 == '\0') {
      uVar24 = 0;
      uVar25 = 0;
    }
    if (DAT_130b720bc80 == '\0') {
      uVar24 = 0;
      uVar25 = 0;
    }
    FUN_130b71ea9d0(0x130b7204078);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207df8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    if (cVar7 != '\0') {
      uVar22 = (undefined4)_DAT_130b720b948;
      uVar23 = (undefined4)((ulonglong)_DAT_130b720b948 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b72040a8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e08);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar23,uVar22));
    cStack_9d = cVar7;
    if (cVar7 != '\0') {
      uVar20 = (undefined4)_DAT_130b720b950;
      uVar21 = (undefined4)((ulonglong)_DAT_130b720b950 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b72040d8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e18);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar21,uVar20));
    uVar24 = (undefined4)_DAT_130b72014a8;
    uVar25 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    uVar12 = 0;
    do {
      uStack_98 = 0;
      uStack_9c = (uint)uVar9;
      uStack_94 = 0;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd8,2,0x590008,0x130b7204108,0x520004,uVar12);
      FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e28);
      FUN_130b71d0a30(&uStack_98,&uStack_b0,0,0x130b7207e38);
      lVar14 = (ulonglong)uVar12 * 0x4c;
      cVar7 = (&DAT_130b720b9d0)[lVar14];
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e48);
      uVar12 = _DAT_130b72034b4;
      uVar13 = (ulonglong)_DAT_130b72034b4;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b72034b4;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b72034b4 + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar6 == '\0') goto LAB_130b71ea9a5;
        if (uVar13 != 0) {
          lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
          if (uVar12 < 8) {
            uVar11 = 0;
          }
          else if (lStack_ac + -0x130b72034b8 + (ulonglong)uVar18 * 2 < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar15 = 0;
            uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
            do {
              uVar20 = *(undefined4 *)(uVar15 + 0x130b72034bc);
              uVar21 = *(undefined4 *)(uVar15 + 0x130b72034c0);
              uVar22 = *(undefined4 *)(uVar15 + 0x130b72034c4);
              puVar2 = (undefined4 *)(lVar16 + uVar15);
              *puVar2 = *(undefined4 *)(&DAT_130b72034b8 + uVar15);
              puVar2[1] = uVar20;
              puVar2[2] = uVar21;
              puVar2[3] = uVar22;
              uVar15 = uVar15 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar11 == uVar13) goto LAB_130b71e9422;
          }
          do {
            *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b72034b8 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e9422:
        *(uint *)(lStack_ac + -4) = uVar17;
        *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
      }
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e58);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar21,uVar20));
      cVar7 = *(char *)(lVar14 + 0x130b720b9d1);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e68);
      uVar12 = _DAT_130b720411c;
      uVar13 = (ulonglong)_DAT_130b720411c;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b720411c;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b720411c + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar6 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7204120 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b7204124);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7204128);
                uVar22 = *(undefined4 *)(&DAT_130b720412c + uVar15);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7204120 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e95d2;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7204120 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e95d2:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e95f3;
        }
LAB_130b71ea8e5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2b000001f9);
LAB_130b71ea905:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c35000001f9);
LAB_130b71ea925:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c32000001f9);
LAB_130b71ea945:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c30000001f9);
LAB_130b71ea965:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2e000001f9);
LAB_130b71ea985:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2c000001f9);
LAB_130b71ea9a5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2a000001f9);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
LAB_130b71e95f3:
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e78);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar21,uVar20));
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720b9d2);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e88);
      uVar12 = _DAT_130b7203514;
      uVar13 = (ulonglong)_DAT_130b7203514;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b7203514;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b7203514 + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7203518 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b720351c);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7203520);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b7203524);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7203518 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9782;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203518 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9782:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e97a3;
        }
        goto LAB_130b71ea985;
      }
LAB_130b71e97a3:
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e98);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar9);
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720b9da);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ea8);
      uVar12 = _DAT_130b72034f4;
      uVar13 = (ulonglong)_DAT_130b72034f4;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b72034f4;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b72034f4 + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b72034f8 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b72034fc);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7203500);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b7203504);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b72034f8 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9912;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b72034f8 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9912:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e9933;
        }
LAB_130b71ea8c5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2d000001f9);
        goto LAB_130b71ea8e5;
      }
LAB_130b71e9933:
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207eb8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar9);
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720b9e2);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ec8);
      uVar12 = _DAT_130b7203534;
      uVar13 = (ulonglong)_DAT_130b7203534;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b7203534;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b7203534 + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7203538 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b720353c);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7203540);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b7203544);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7203538 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9aa2;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203538 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9aa2:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e9ac3;
        }
        goto LAB_130b71ea965;
      }
LAB_130b71e9ac3:
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207ed8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar9);
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720b9ea);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ee8);
      uVar12 = _DAT_130b720412c;
      uVar13 = (ulonglong)_DAT_130b720412c;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b720412c;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b720412c + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7204130 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b7204134);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7204138);
                uVar22 = *(undefined4 *)(&DAT_130b720413c + uVar15);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7204130 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9c32;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7204130 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9c32:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e9c53;
        }
LAB_130b71ea8a5:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2f000001f9);
        goto LAB_130b71ea8c5;
      }
LAB_130b71e9c53:
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207ef8);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar9);
      lVar16 = *(longlong *)(lVar14 + 0x130b720b9f2);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f08);
      uVar12 = _DAT_130b7203554;
      uVar13 = (ulonglong)_DAT_130b7203554;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b7203554;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b7203554 + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar1 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7203558 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b720355c);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7203560);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b7203564);
                puVar2 = (undefined4 *)(lVar1 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7203558 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9dc2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203558 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9dc2:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71e9de3;
        }
        goto LAB_130b71ea945;
      }
LAB_130b71e9de3:
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f18);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,(double)lVar16);
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720b9fa);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f28);
      uVar12 = _DAT_130b7203574;
      uVar13 = (ulonglong)_DAT_130b7203574;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar11 = 0;
          uVar18 = _DAT_130b7203574;
        }
        else {
          uVar11 = (ulonglong)*(uint *)(lStack_ac + -4);
          uVar18 = _DAT_130b7203574 + *(uint *)(lStack_ac + -4);
        }
        uVar17 = 0x104;
        if ((0x103 < uVar18) &&
           ((0x7ffffffd < uVar18 || (uVar17 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar17)))) {
          uVar17 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar17);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + uVar11 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7203578 + uVar11 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b720357c);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7203580);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b7203584);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7203578 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71e9f62;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203578 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71e9f62:
          *(uint *)(lStack_ac + -4) = uVar18;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar18 * 2) = 0;
          goto LAB_130b71e9f83;
        }
LAB_130b71ea885:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c31000001f9);
        goto LAB_130b71ea8a5;
      }
LAB_130b71e9f83:
      FUN_130b71eade0(&uStack_b0,uVar9);
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720ba02);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f38);
      uVar12 = _DAT_130b7203594;
      uVar13 = (ulonglong)_DAT_130b7203594;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar11 = 0;
          uVar18 = _DAT_130b7203594;
        }
        else {
          uVar11 = (ulonglong)*(uint *)(lStack_ac + -4);
          uVar18 = _DAT_130b7203594 + *(uint *)(lStack_ac + -4);
        }
        uVar17 = 0x104;
        if ((0x103 < uVar18) &&
           ((0x7ffffffd < uVar18 || (uVar17 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar17)))) {
          uVar17 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar17);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + uVar11 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7203598 + uVar11 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b720359c);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b72035a0);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b72035a4);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7203598 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71ea0d2;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203598 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71ea0d2:
          *(uint *)(lStack_ac + -4) = uVar18;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar18 * 2) = 0;
          goto LAB_130b71ea0f3;
        }
        goto LAB_130b71ea925;
      }
LAB_130b71ea0f3:
      FUN_130b71eade0(&uStack_b0,uVar9);
      lVar16 = *(longlong *)(lVar14 + 0x130b720ba0a);
      if (lVar16 < 1) {
        lVar16 = 0;
      }
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f48);
      uVar12 = _DAT_130b72035b4;
      uVar13 = (ulonglong)_DAT_130b72035b4;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar11 = 0;
          uVar18 = _DAT_130b72035b4;
        }
        else {
          uVar11 = (ulonglong)*(uint *)(lStack_ac + -4);
          uVar18 = _DAT_130b72035b4 + *(uint *)(lStack_ac + -4);
        }
        uVar17 = 0x104;
        if ((0x103 < uVar18) &&
           ((0x7ffffffd < uVar18 || (uVar17 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar17)))) {
          uVar17 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar17);
        if (cVar7 != '\0') {
          if (uVar13 != 0) {
            lVar1 = lStack_ac + uVar11 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b72035b8 + uVar11 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b72035bc);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b72035c0);
                uVar22 = *(undefined4 *)(uVar15 + 0x130b72035c4);
                puVar2 = (undefined4 *)(lVar1 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b72035b8 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71ea242;
            }
            do {
              *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(&DAT_130b72035b8 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71ea242:
          *(uint *)(lStack_ac + -4) = uVar18;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar18 * 2) = 0;
          goto LAB_130b71ea263;
        }
LAB_130b71ea865:
        (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c33000001f9);
        goto LAB_130b71ea885;
      }
LAB_130b71ea263:
      FUN_130b71eade0(&uStack_b0,lVar16);
      cVar7 = *(char *)(lVar14 + 0x130b720ba13);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f58);
      uVar12 = _DAT_130b720413c;
      uVar13 = (ulonglong)_DAT_130b720413c;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar18 = 0;
          uVar17 = _DAT_130b720413c;
        }
        else {
          uVar18 = *(uint *)(lStack_ac + -4);
          uVar17 = _DAT_130b720413c + uVar18;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar19 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar6 = FUN_130b71d0060(&uStack_b0,uVar19);
        if (cVar6 != '\0') {
          if (uVar13 != 0) {
            lVar16 = lStack_ac + (ulonglong)uVar18 * 2;
            if (uVar12 < 8) {
              uVar11 = 0;
            }
            else if (lStack_ac + -0x130b7204140 + (ulonglong)uVar18 * 2 < 0x20) {
              uVar11 = 0;
            }
            else {
              uVar15 = 0;
              uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                uVar20 = *(undefined4 *)(uVar15 + 0x130b7204144);
                uVar21 = *(undefined4 *)(uVar15 + 0x130b7204148);
                uVar22 = *(undefined4 *)(&DAT_130b720414c + uVar15);
                puVar2 = (undefined4 *)(lVar16 + uVar15);
                *puVar2 = *(undefined4 *)(&DAT_130b7204140 + uVar15);
                puVar2[1] = uVar20;
                puVar2[2] = uVar21;
                puVar2[3] = uVar22;
                uVar15 = uVar15 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar11 == uVar13) goto LAB_130b71ea3b2;
            }
            do {
              *(undefined2 *)(lVar16 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7204140 + uVar11 * 2);
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
          }
LAB_130b71ea3b2:
          *(uint *)(lStack_ac + -4) = uVar17;
          *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
          goto LAB_130b71ea3c9;
        }
        goto LAB_130b71ea905;
      }
LAB_130b71ea3c9:
      uVar20 = 0;
      uVar21 = 0;
      if (cVar7 != '\0') {
        uVar20 = uVar24;
        uVar21 = uVar25;
      }
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f68);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar21,uVar20));
      uVar9 = *(undefined8 *)(lVar14 + 0x130b720ba14);
      FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f78);
      uVar18 = uStack_9c;
      uVar12 = _DAT_130b720414c;
      uVar13 = (ulonglong)_DAT_130b720414c;
      if ((uVar13 != 0) || (lStack_ac == 0)) {
        if (lStack_ac == 0) {
          uVar17 = 0;
          uVar19 = _DAT_130b720414c;
        }
        else {
          uVar17 = *(uint *)(lStack_ac + -4);
          uVar19 = _DAT_130b720414c + uVar17;
        }
        uVar10 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar10 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar10)))) {
          uVar10 = 0x7ffffffe;
        }
        cVar7 = FUN_130b71d0060(&uStack_b0,uVar10);
        if (cVar7 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c36000001f9);
          goto LAB_130b71ea865;
        }
        if (uVar13 != 0) {
          lVar14 = lStack_ac + (ulonglong)uVar17 * 2;
          if (uVar12 < 8) {
            uVar11 = 0;
          }
          else if (lStack_ac + -0x130b7204150 + (ulonglong)uVar17 * 2 < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar15 = 0;
            uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
            do {
              uVar20 = *(undefined4 *)(uVar15 + 0x130b7204154);
              uVar21 = *(undefined4 *)(uVar15 + 0x130b7204158);
              uVar22 = *(undefined4 *)(uVar15 + 0x130b720415c);
              puVar2 = (undefined4 *)(lVar14 + uVar15);
              *puVar2 = *(undefined4 *)(&DAT_130b7204150 + uVar15);
              puVar2[1] = uVar20;
              puVar2[2] = uVar21;
              puVar2[3] = uVar22;
              uVar15 = uVar15 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar11 == uVar13) goto LAB_130b71e91e0;
          }
          do {
            *(undefined2 *)(lVar14 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7204150 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71e91e0:
        *(uint *)(lStack_ac + -4) = uVar19;
        *(undefined2 *)(lStack_ac + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_130b71ea9d0(&uStack_b0);
      FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f88);
      (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar9);
      FUN_130b71d0000(&uStack_98);
      uVar12 = 1;
      uVar9 = 0;
    } while ((uVar18 & 1) != 0);
    dVar4 = (double)_DAT_130b720bc50;
    FUN_130b71ea9d0(0x130b7204178);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207f98);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar4);
    dVar4 = (double)_DAT_130b720bc58;
    FUN_130b71ea9d0(0x130b72041a8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fa8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar4);
    uVar9 = _DAT_130b720bc60;
    FUN_130b71ea9d0(0x130b72041d8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fb8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar9);
    uVar9 = _DAT_130b720bc68;
    FUN_130b71ea9d0(0x130b7204208);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fc8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar9);
    uVar9 = _DAT_130b720bc70;
    FUN_130b71ea9d0(0x130b7204238);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fd8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar9);
    uVar9 = _DAT_130b720bc78;
    FUN_130b71ea9d0(0x130b7204268);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fe8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar9);
    uVar24 = 0;
    uVar25 = 0;
    if (cStack_9d != '\0') {
      uVar24 = (undefined4)_DAT_130b72014a8;
      uVar25 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
    }
    FUN_130b71ea9d0(0x130b7204298);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207ff8);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar25,uVar24));
    uVar9 = _DAT_130b720bc88;
    FUN_130b71ea9d0(0x130b72042c8);
    FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7208008);
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar9);
    _DAT_130b720bb10 = 0;
    _DAT_130b720bb80 = 0;
    DAT_130b720bb88 = 0;
    (*(code *)0x7ff63a0edfa0)(0x130b53f81d8);
    if (_DAT_130b720bb10 != 0) {
      (*(code *)0x7ff63a0e49f0)
                (0x130b53f81d8,0xd,2,0x590008,0x130b7204310,0x520004,_DAT_130b720bb10);
    }
  }
  FUN_130b71d0000(&uStack_b0);
  FUN_130b71d0000(&uStack_88);
  return;
}



/* Address: 130b71f5600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_130b71f5600(ulonglong param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined4 local_70;
  longlong local_6c;
  longlong *local_60;
  longlong *local_58;
  longlong *local_50;
  longlong local_48;
  
  local_70 = 0;
  local_6c = 0;
  lVar14 = (param_1 & 0xffffffff) * 0x4c;
  if ((&DAT_130b720b9d0)[lVar14] != '\0') {
    local_60 = (longlong *)(lVar14 + 0x130b720ba0a);
    if (((*(longlong *)(lVar14 + 0x130b720ba0a) == 0) &&
        (*(longlong *)(lVar14 + 0x130b720ba02) != 0)) &&
       (cVar8 = (*(code *)0x7ff63a108af0)(0x130b53f81d8), cVar8 != '\0')) {
      lVar11 = (*(code *)0x7ff63a108940)(0x130b53f81d8,*(undefined8 *)(lVar14 + 0x130b720ba02),0xc);
      *local_60 = lVar11;
    }
    cVar8 = *(char *)(lVar14 + 0x130b720b9d1);
    iVar9 = (*(code *)0x7ff63a107da0)(0x130b53f81d8);
    if (-1 < iVar9 + -1) {
      local_48 = (longlong)_DAT_130b720bc30;
      local_50 = (longlong *)(lVar14 + 0x130b720b9fa);
      local_58 = (longlong *)(lVar14 + 0x130b720b9f2);
      lVar14 = 0;
      iVar9 = iVar9 + -1;
      do {
        lVar11 = (*(code *)0x7ff63a107df0)(0x130b53f81d8,iVar9);
        if ((lVar11 != 0) &&
           (cVar7 = (*(code *)0x7ff63a107ee0)(0x130b53f81d8,lVar11), cVar7 != '\0')) {
          (*(code *)0x7ff63a108010)(0x130b53f81d8,0);
          FUN_130b71d0a30(&local_70,0x130b720bb3c,1,0x130b7208348);
          if (local_6c == _DAT_130b720bb2c) {
LAB_130b71f580c:
            lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xc);
            if ((lVar12 == local_48) &&
               (uVar10 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,2), uVar10 == (cVar8 == '\0'))) {
              lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,0xd);
              if (((0 < *local_60) && (lVar12 == *local_60)) ||
                 ((lVar4 = *local_50, lVar4 != 0 && ((lVar11 == lVar4 || (lVar12 == lVar4))))))
              break;
              lVar12 = (*(code *)0x7ff63a107fc0)(0x130b53f81d8,1);
              if (*local_58 + -5 <= lVar12) {
                lVar14 = lVar11;
              }
            }
          }
          else if ((local_6c != 0) && (_DAT_130b720bb2c != 0)) {
            uVar10 = *(uint *)(local_6c + -4);
            uVar3 = *(uint *)(_DAT_130b720bb2c + -4);
            uVar6 = uVar3;
            if (uVar10 < uVar3) {
              uVar6 = uVar10;
            }
            iVar13 = uVar10 - uVar3;
            if (uVar6 != 0) {
              uVar15 = 1;
              do {
                uVar1 = *(ushort *)(local_6c + -2 + uVar15 * 2);
                uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar15 * 2);
                if (uVar6 <= uVar15) break;
                uVar15 = uVar15 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar13 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar13 == 0) goto LAB_130b71f580c;
          }
        }
        bVar5 = 0 < iVar9;
        lVar11 = lVar14;
        iVar9 = iVar9 + -1;
      } while (bVar5);
      goto LAB_130b71f5894;
    }
  }
  lVar11 = 0;
LAB_130b71f5894:
  FUN_130b71d0000(&local_70);
  return lVar11;
}



/* Address: 130b71f5920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f5920(undefined8 param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  char cVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  int iVar12;
  undefined8 uVar13;
  byte bVar14;
  uint uVar15;
  ulonglong uVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 local_98;
  longlong local_94;
  
  dVar7 = _DAT_130b720bc98;
  local_98 = 0;
  local_94 = 0;
  if (0.0 < _DAT_130b720bc98) {
    cVar8 = (*(code *)0x7ff63a108af0)(0x130b53f81d8,param_1);
    if (cVar8 != '\0') {
      (*(code *)0x7ff63a1089d0)(0x130b53f81d8,param_1,0);
      FUN_130b71d0a30(&local_98,0x130b720bb3c,1,0x130b7208358);
      if (local_94 != _DAT_130b720bb2c) {
        if ((local_94 == 0) || (_DAT_130b720bb2c == 0)) goto LAB_130b71f5dee;
        uVar3 = *(uint *)(local_94 + -4);
        uVar4 = *(uint *)(_DAT_130b720bb2c + -4);
        uVar15 = uVar4;
        if (uVar3 < uVar4) {
          uVar15 = uVar3;
        }
        iVar12 = uVar3 - uVar4;
        if (uVar15 != 0) {
          uVar16 = 1;
          do {
            uVar1 = *(ushort *)(local_94 + -2 + uVar16 * 2);
            uVar2 = *(ushort *)(_DAT_130b720bb2c + -2 + uVar16 * 2);
            if (uVar15 <= uVar16) break;
            uVar16 = uVar16 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar12 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar12 != 0) goto LAB_130b71f5dee;
      }
      lVar9 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_1,0xb);
      if (lVar9 == _DAT_130b720bc30) {
        uVar16 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_1,4);
        if ((uVar16 & 0xfffffffffffffffd) == 0) {
          uVar16 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_1,3);
          if ((((uVar16 < 2) && (lVar9 = uVar16 * 0x4c, (&DAT_130b720b9d0)[lVar9] != '\0')) &&
              (bVar14 = (byte)uVar16 ^ 1, *(byte *)(lVar9 + 0x130b720b9d1) == bVar14)) &&
             (0.0 < *(double *)(lVar9 + 0x130b720b9d2))) {
            lVar10 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_1,1);
            lVar11 = (*(code *)0x7ff63a108940)(0x130b53f81d8,param_1,0xc);
            if (((*(longlong *)(lVar9 + 0x130b720b9fa) == 0) || (lVar10 == 0)) ||
               ((lVar10 == *(longlong *)(lVar9 + 0x130b720b9fa) ||
                ((0 < *(longlong *)(lVar9 + 0x130b720ba0a) &&
                 (lVar11 == *(longlong *)(lVar9 + 0x130b720ba0a))))))) {
              (*(code *)0x7ff63a1088b0)(0x130b53f81d8,param_1,6);
              dVar6 = _DAT_130b720bb48;
              dVar5 = _DAT_130b720bb18;
              if (0.0 < _DAT_130b720bb48) {
                dVar17 = *(double *)(lVar9 + 0x130b720b9d2);
                if (_DAT_130b720bc90 == 1) {
                  dVar18 = _DAT_130b720b3d0;
                  if (bVar14 != 0) {
                    dVar18 = (double)((ulonglong)_DAT_130b720b3d0 ^ _DAT_130b7201640);
                  }
                  dVar17 = dVar17 + dVar18;
                }
                if (uVar16 == 0) {
                  dVar17 = _DAT_130b720bb48 - dVar17;
                }
                else {
                  dVar17 = dVar17 - _DAT_130b720bb48;
                }
                uVar19 = 0;
                uVar20 = 0;
                uVar21 = SUB84(_DAT_130b720bb18,0);
                uVar22 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
                if (0.0 <= dVar17) {
                  uVar19 = SUB84(dVar17,0);
                  uVar20 = (undefined4)((ulonglong)dVar17 >> 0x20);
                }
                (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
                if (dVar5 <= _DAT_130b720bb48) {
                  uVar21 = SUB84(_DAT_130b720bb48,0);
                  uVar22 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
                }
                if ((double)CONCAT44(uVar22,uVar21) * _DAT_130b7201650 + dVar7 <
                    (double)CONCAT44(uVar20,uVar19)) {
                  *(undefined8 *)(lVar9 + 0x130b720ba02) = param_1;
                  if (0 < lVar11) {
                    *(longlong *)(lVar9 + 0x130b720ba0a) = lVar11;
                  }
                  *(undefined1 *)(lVar9 + 0x130b720ba13) = 1;
                  *(double *)(lVar9 + 0x130b720ba14) = dVar6;
                  FUN_130b71e8bd0();
                  uVar13 = 0x130b7201d28;
                  if (uVar16 == 0) {
                    uVar13 = 0x130b7201cf8;
                  }
                  (*(code *)0x7ff63a0e49f0)
                            (0x130b53f81d8,0xd,8,0x590008,0x130b7204598,0x590008,uVar13,0x520004,
                             _DAT_130b720bb20,0x580007,*(double *)(lVar9 + 0x130b720b9d2),0x520004,
                             _DAT_130b720bb20,0x580007,dVar6,0x580007,CONCAT44(uVar20,uVar19),
                             0x580007,dVar7);
                  lVar9 = FUN_130b71f5600(uVar16 & 0xffffffff);
                  if (lVar9 != 0) {
                    FUN_130b71e82f0(lVar9,0x130b72045e8);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_130b71f5dee:
  FUN_130b71d0000(&local_98);
  return;
}



/* Address: 130b71f5e40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_130b71f5e40(undefined4 param_1,undefined8 param_2,double param_3,undefined8 param_4,
                         undefined8 param_5,undefined8 param_6)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  double dVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined8 in_stack_fffffffffffffc30;
  undefined4 uVar20;
  undefined8 in_stack_fffffffffffffc48;
  undefined4 uVar21;
  undefined8 in_stack_fffffffffffffc58;
  undefined4 uVar22;
  undefined8 in_stack_fffffffffffffc68;
  undefined4 uVar23;
  undefined8 in_stack_fffffffffffffc78;
  undefined4 uVar24;
  undefined8 in_stack_fffffffffffffc98;
  undefined4 uVar25;
  undefined4 local_328;
  undefined8 local_324;
  undefined4 local_318;
  undefined8 local_314;
  undefined4 local_308;
  int iStack_304;
  int iStack_300;
  undefined4 uStack_2fc;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  int local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined8 local_1e0;
  undefined1 local_1d8 [144];
  undefined1 local_148 [8];
  double local_140;
  double local_138;
  undefined1 local_108 [8];
  undefined8 auStack_100 [24];
  
  uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffc78 >> 0x20);
  uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffc98 >> 0x20);
  uVar22 = (undefined4)((ulonglong)in_stack_fffffffffffffc58 >> 0x20);
  uVar21 = (undefined4)((ulonglong)in_stack_fffffffffffffc48 >> 0x20);
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffc30 >> 0x20);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffc68 >> 0x20);
  lVar12 = 0x7ff63a0f2c10;
  local_318 = 0;
  local_328 = 0;
  local_314 = 0;
  local_324 = 0;
  cVar5 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,local_108);
  dVar4 = _DAT_130b720bc98;
  if (cVar5 == '\0') {
LAB_130b71f66a2:
    uVar13 = 0;
  }
  else {
    cVar5 = (char)param_1;
    dVar1 = param_3;
    if (_DAT_130b720bc90 == 1) {
      uVar14 = (undefined4)_DAT_130b720b3d0;
      uVar15 = (undefined4)(_DAT_130b720b3d0 >> 0x20);
      if (cVar5 != '\0') {
        uVar14 = (undefined4)(_DAT_130b720b3d0 ^ _DAT_130b7201660);
        uVar15 = (undefined4)((_DAT_130b720b3d0 ^ _DAT_130b7201660) >> 0x20);
      }
      dVar1 = (double)CONCAT44(uVar15,uVar14) + param_3;
    }
    uVar14 = 0;
    uVar15 = 0;
    if ((_DAT_130b720bc98 <= 0.0) || (dVar1 <= 0.0)) {
LAB_130b71f6058:
      lVar12 = (longlong)&local_2f8 + 4;
      local_2a4 = 0;
      local_2a0 = 0;
      local_1e4 = 0;
      local_1e0 = 0;
      local_2f8 = 0;
      uStack_2f0 = 0;
      local_308 = 0;
      iStack_304 = 0;
      iStack_300 = 0;
      uStack_2fc = 0;
      FUN_130b71d0000(lVar12);
      local_2b8 = 0;
      uStack_2b0 = 0;
      local_2c8 = 0;
      uStack_2c0 = 0;
      local_2d8 = 0;
      uStack_2d0 = 0;
      local_2e8 = 0;
      uStack_2e0 = 0;
      local_2a8 = 0;
      FUN_130b71d0000(&local_2a4);
      local_228 = 0;
      uStack_220 = 0;
      local_238 = 0;
      uStack_230 = 0;
      local_248 = 0;
      uStack_240 = 0;
      local_258 = 0;
      uStack_250 = 0;
      local_268 = 0;
      uStack_260 = 0;
      local_278 = 0;
      uStack_270 = 0;
      local_288 = 0;
      uStack_280 = 0;
      local_298 = 0;
      uStack_290 = 0;
      local_218 = 0;
      uStack_214 = 0;
      uStack_210 = 0;
      uStack_20c = 0;
      uStack_208 = 0;
      uStack_204 = 0;
      uStack_200 = 0;
      uStack_1fc = 0;
      local_1f8 = 0;
      uStack_1f0 = 0;
      local_1e8 = 0;
      FUN_130b71d0000(&local_1e4);
      (*(code *)0x7ff63a3fad20)(local_1d8,0,0x84);
      local_308 = 1;
      iStack_304 = _DAT_130b720bc30;
      iStack_300 = _DAT_130b720bc30 >> 0x1f;
      FUN_130b71d0a30(lVar12,0x130b720bb28,1,0x130b72083c8);
      local_2b8 = CONCAT44(local_2b8._4_4_,(uint)(cVar5 == '\0'));
      if ((double)CONCAT44(uVar15,uVar14) < 0.0 || (double)CONCAT44(uVar15,uVar14) == 0.0) {
        uVar14 = (undefined4)auStack_100[cVar5 != '\0'];
        uVar15 = (undefined4)((ulonglong)auStack_100[cVar5 != '\0'] >> 0x20);
      }
      local_2e8 = param_2;
      uStack_2e0 = FUN_130b71f4e60(CONCAT44(uVar15,uVar14));
      uStack_2d0 = FUN_130b71f4e60(param_4);
      local_2c8 = FUN_130b71f4e60(param_5);
      uVar7 = (*(code *)0x7ff63a0f2970)(0x130b53f81d8,0x130b7201850,0x32);
      iVar10 = ((uVar7 & 2) == 0) + 1;
      if ((uVar7 & 1) != 0) {
        iVar10 = 0;
      }
      local_2b8 = CONCAT44(iVar10,(undefined4)local_2b8);
      FUN_130b71d0a30(&local_2a4,param_6,0,0x130b72083d8);
      cVar6 = FUN_130b71e7bd0(local_2b8 & 0xffffffff,param_2);
      if (cVar6 == '\0') {
LAB_130b71f6696:
        FUN_130b71d0000(&local_1e4);
        FUN_130b71d0000(&local_2a4);
        FUN_130b71d0000(lVar12);
        goto LAB_130b71f66a2;
      }
      _DAT_130b720bb10 = 0;
      _DAT_130b720bb80 = 0;
      DAT_130b720bb88 = 0;
      cVar6 = (*(code *)0x7ff63a108b70)(0x130b53f81d8,&local_308,&local_218);
      if ((cVar6 == '\0') || (2 < local_218 - 0x2718U)) {
        if (local_218 != 0x271c) {
          uVar8 = 0x130b7203778;
          if (cVar6 != '\0') {
            uVar8 = 0x130b7203748;
          }
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd,0xb,0x590008,0x130b7204bc8,CONCAT44(uVar20,0x590008),uVar8,
                     0x520004,CONCAT44(uVar21,_DAT_130b720bb10),0x530014,CONCAT44(uVar22,local_218),
                     0x590008,&local_1e4,0x520004,CONCAT44(uVar24,_DAT_130b720bb20),0x580007,
                     uStack_2e0,0x520004,CONCAT44(uVar25,_DAT_130b720bb20),0x580007,uStack_2d0,
                     0x520004,_DAT_130b720bb20,0x580007,local_2c8);
          goto LAB_130b71f6696;
        }
        uVar8 = CONCAT44(uStack_208,uStack_20c);
        FUN_130b71f5400(param_1,param_3,uStack_2d0,local_2c8,param_2,uVar8,
                        CONCAT44(uStack_210,uStack_214));
        uVar20 = (undefined4)((ulonglong)uVar8 >> 0x20);
        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,CONCAT44(uStack_210,uStack_214),0x56,&local_328);
        (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,CONCAT44(uStack_208,uStack_20c),0x56,&local_318);
        uVar8 = 0x130b7201cf8;
        if (cVar5 == '\0') {
          uVar8 = 0x130b7201d28;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x130b53f81d8,0xd,4,0x590008,0x130b7204b38,CONCAT44(uVar20,0x590008),uVar8,
                   0x590008,&local_318,0x590008,&local_328);
      }
      else {
        if (local_218 == 0x271a) {
          uVar8 = 0x130b7201cf8;
          if (cVar5 == '\0') {
            uVar8 = 0x130b7201d28;
          }
          (*(code *)0x7ff63a0e49f0)
                    (0x130b53f81d8,0xd,4,0x590008,0x130b7204c30,CONCAT44(uVar20,0x590008),uVar8,
                     0x580007,param_2,0x580007,CONCAT44(uStack_200,uStack_204));
        }
        FUN_130b71f5400(param_1,param_3,uStack_2d0,local_2c8,param_2,CONCAT44(uStack_208,uStack_20c)
                        ,CONCAT44(uStack_210,uStack_214));
        if (CONCAT44(uStack_210,uStack_214) != 0) {
          FUN_130b71f5920();
        }
      }
      FUN_130b71d0000(&local_1e4);
      FUN_130b71d0000(&local_2a4);
      FUN_130b71d0000(lVar12);
    }
    else {
      cVar6 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,local_148);
      dVar2 = _DAT_130b720bb18;
      uVar14 = 0;
      uVar15 = 0;
      if (cVar6 == '\0') goto LAB_130b71f6058;
      uVar14 = SUB84(local_140,0);
      uVar15 = (undefined4)((ulonglong)local_140 >> 0x20);
      if (cVar5 != '\0') {
        uVar14 = SUB84(local_138,0);
        uVar15 = (undefined4)((ulonglong)local_138 >> 0x20);
      }
      if ((double)CONCAT44(uVar15,uVar14) <= 0.0) goto LAB_130b71f6058;
      if (cVar5 == '\0') {
        local_138 = dVar1 - local_140;
      }
      else {
        local_138 = local_138 - dVar1;
      }
      uVar16 = 0;
      uVar17 = 0;
      uVar18 = SUB84(_DAT_130b720bb18,0);
      uVar19 = (undefined4)((ulonglong)_DAT_130b720bb18 >> 0x20);
      if (0.0 <= local_138) {
        uVar16 = SUB84(local_138,0);
        uVar17 = (undefined4)((ulonglong)local_138 >> 0x20);
      }
      (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,0x1b);
      uVar3 = _DAT_130b720bb20;
      if (dVar2 <= _DAT_130b720bb48) {
        uVar18 = SUB84(_DAT_130b720bb48,0);
        uVar19 = (undefined4)((ulonglong)_DAT_130b720bb48 >> 0x20);
      }
      dVar2 = (double)CONCAT44(uVar19,uVar18) * _DAT_130b7201670 + dVar4;
      if ((double)CONCAT44(uVar17,uVar16) < dVar2 || (double)CONCAT44(uVar17,uVar16) == dVar2)
      goto LAB_130b71f6058;
      puVar9 = &DAT_130b720b95c;
      puVar11 = &DAT_130b720b9c0;
      if (cVar5 == '\0') {
        puVar9 = &DAT_130b720b95d;
        puVar11 = &DAT_130b720b9c1;
      }
      uVar8 = 0x130b7201cf8;
      if (cVar5 == '\0') {
        uVar8 = 0x130b7201d28;
      }
      *puVar9 = 0;
      *puVar11 = 1;
      (*(code *)0x7ff63a0e49f0)
                (0x130b53f81d8,0xd,8,0x590008,0x130b7204518,CONCAT44(uVar20,0x590008),uVar8,0x520004
                 ,CONCAT44(uVar21,uVar3),0x580007,dVar1,0x520004,CONCAT44(uVar23,uVar3),0x580007,
                 CONCAT44(uVar15,uVar14),0x580007,CONCAT44(uVar17,uVar16),0x580007,dVar4);
      FUN_130b71e8bd0();
    }
    uVar13 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
  }
  FUN_130b71d0000(&local_328);
  FUN_130b71d0000(&local_318);
  return uVar13 & 0xffffffff;
}



/* Address: 130b71f6830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f6830(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  longlong lVar15;
  undefined8 unaff_R13;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  double dVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uStack_b0;
  longlong lStack_ac;
  char cStack_9d;
  uint uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined8 uStack_84;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_58 [8];
  undefined4 local_50;
  undefined4 uStack_4c;
  double local_48;
  
  uStack_90 = 0xb71f6843;
  uStack_8c = 0x130;
  cVar6 = FUN_130b71e6fc0();
  if (cVar6 == '\0') {
    uStack_90 = 0xb71f685b;
    uStack_8c = 0x130;
    cVar6 = FUN_130b71f4c90();
    iVar7 = _DAT_130b720b90c;
    if ((cVar6 != '\0') && (DAT_130b720ba6e == '\0')) {
      uStack_90 = 0xb71f6886;
      uStack_8c = 0x130;
      iVar8 = FUN_130b71efc10();
      if (iVar7 == iVar8) {
        uStack_90 = 0xb71f68af;
        uStack_8c = 0x130;
        cVar6 = (*(code *)0x7ff63a0f2c10)(0x130b53f81d8,0x130b7201850,local_58);
        if (cVar6 != '\0') {
          if (DAT_130b720b95c != '\0') {
            dVar20 = _DAT_130b720b3d0;
            if (_DAT_130b720bc90 != 1) {
              dVar20 = 0.0;
            }
            if (_DAT_130b720b960 - dVar20 <= local_48) {
              local_60 = 0x130b720b980;
              local_68 = _DAT_130b720b970;
              uStack_90 = 0xb71f6a6d;
              uStack_8c = 0x130;
              cVar6 = FUN_130b71f5e40(1,_DAT_130b720b978,&DAT_130b720b968,_DAT_130b720b968);
              if (cVar6 != '\0') {
                DAT_130b720b95c = '\0';
                DAT_130b720b9c0 = '\x01';
                uStack_90 = 0xb71f6a8d;
                uStack_8c = 0x130;
                FUN_130b71e8bd0();
              }
            }
          }
          if (DAT_130b720b95d != '\0') {
            if (_DAT_130b720bc90 == 1) {
              uVar25 = SUB84(_DAT_130b720b3d0,0);
              uVar26 = (undefined4)((ulonglong)_DAT_130b720b3d0 >> 0x20);
            }
            else {
              uVar25 = (undefined4)_DAT_130b7201678;
              uVar26 = (undefined4)((ulonglong)_DAT_130b7201678 >> 0x20);
            }
            if ((double)CONCAT44(uStack_4c,local_50) <=
                (double)CONCAT44(uVar26,uVar25) + _DAT_130b720b990) {
              local_60 = 0x130b720b9b0;
              local_68 = _DAT_130b720b9a0;
              uStack_90 = 0xb71f6b25;
              uStack_8c = 0x130;
              cVar6 = FUN_130b71f5e40(0,_DAT_130b720b9a8,&DAT_130b720b998,_DAT_130b720b998);
              if (cVar6 != '\0') {
                DAT_130b720b95d = '\0';
                DAT_130b720b9c1 = '\x01';
                uStack_90 = 0xb71f6b49;
                uStack_8c = 0x130;
                FUN_130b71e8bd0();
              }
            }
          }
        }
      }
      else if (DAT_130b720b95c != '\0' || DAT_130b720b95d != '\0') {
        DAT_130b720b95d = '\0';
        DAT_130b720b95c = '\0';
        _DAT_130b720b960 = 0.0;
        _DAT_130b720b968 = 0;
        _DAT_130b720b970 = 0;
        _DAT_130b720b978 = 0;
        uStack_90 = 0xb71f6999;
        uStack_8c = 0x130;
        FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
        _DAT_130b720b998 = 0;
        _DAT_130b720b9a0 = 0;
        _DAT_130b720b990 = 0.0;
        _DAT_130b720b9a8 = 0;
        uStack_90 = 0xb71f69f9;
        uStack_8c = 0x130;
        FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
        uStack_88 = 0;
        uStack_b0 = 0;
        uStack_98 = 0;
        uStack_84 = 0;
        lStack_ac = 0;
        uStack_94 = 0;
        uStack_90 = 0;
        iVar7 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
        if (iVar7 == 0) {
          dVar20 = (double)_DAT_130b720b9bc;
          FUN_130b71ea9d0(0x130b7203da8);
          uVar14 = CONCAT71((int7)((ulonglong)unaff_R13 >> 8),1);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d08);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar20);
          dVar20 = (double)_DAT_130b720b90c;
          FUN_130b71ea9d0(0x130b7203dd8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d18);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar20);
          uVar21 = 0;
          uVar22 = 0;
          uVar23 = (undefined4)_DAT_130b72014a8;
          uVar24 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
          uVar25 = 0;
          uVar26 = 0;
          if (DAT_130b720b9c0 != '\0') {
            uVar25 = uVar23;
            uVar26 = uVar24;
          }
          FUN_130b71ea9d0(0x130b7203e08);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d28);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          uVar25 = 0;
          uVar26 = 0;
          if (DAT_130b720b9c1 != '\0') {
            uVar25 = uVar23;
            uVar26 = uVar24;
          }
          FUN_130b71ea9d0(0x130b7203e38);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d38);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          uVar25 = 0;
          uVar26 = 0;
          if (DAT_130b720b95c != '\0') {
            uVar25 = uVar23;
            uVar26 = uVar24;
          }
          FUN_130b71ea9d0(0x130b7203e68);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d48);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          uVar4 = _DAT_130b720b960;
          FUN_130b71ea9d0(0x130b7203e98);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d58);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b968;
          FUN_130b71ea9d0(0x130b7203ec8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d68);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b970;
          FUN_130b71ea9d0(0x130b7203ef8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d78);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b978;
          FUN_130b71ea9d0(0x130b7203f28);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d88);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar25 = 0;
          uVar26 = 0;
          if (DAT_130b720b95d != '\0') {
            uVar25 = uVar23;
            uVar26 = uVar24;
          }
          FUN_130b71ea9d0(0x130b7203f58);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207d98);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          uVar4 = _DAT_130b720b990;
          FUN_130b71ea9d0(0x130b7203f88);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207da8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b998;
          FUN_130b71ea9d0(0x130b7203fb8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207db8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b9a0;
          FUN_130b71ea9d0(0x130b7203fe8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207dc8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar4 = _DAT_130b720b9a8;
          FUN_130b71ea9d0(0x130b7204018);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207dd8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar4);
          uVar25 = 0;
          uVar26 = 0;
          if (DAT_130b720ba6e != '\0') {
            uVar25 = uVar23;
            uVar26 = uVar24;
          }
          FUN_130b71ea9d0(0x130b7204048);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207de8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          cVar6 = DAT_130b720bc80;
          uVar25 = uVar23;
          uVar26 = uVar24;
          if (DAT_130b720b944 == '\0') {
            uVar25 = 0;
            uVar26 = 0;
          }
          if (DAT_130b720bc80 == '\0') {
            uVar25 = 0;
            uVar26 = 0;
          }
          FUN_130b71ea9d0(0x130b7204078);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207df8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          if (cVar6 != '\0') {
            uVar23 = (undefined4)_DAT_130b720b948;
            uVar24 = (undefined4)((ulonglong)_DAT_130b720b948 >> 0x20);
          }
          FUN_130b71ea9d0(0x130b72040a8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e08);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar24,uVar23));
          cStack_9d = cVar6;
          if (cVar6 != '\0') {
            uVar21 = (undefined4)_DAT_130b720b950;
            uVar22 = (undefined4)((ulonglong)_DAT_130b720b950 >> 0x20);
          }
          FUN_130b71ea9d0(0x130b72040d8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e18);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar22,uVar21));
          uVar25 = (undefined4)_DAT_130b72014a8;
          uVar26 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
          uVar11 = 0;
          do {
            uStack_98 = 0;
            uStack_9c = (uint)uVar14;
            uStack_94 = 0;
            uStack_90 = 0;
            (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,0xd8,2,0x590008,0x130b7204108,0x520004,uVar11);
            FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207e28);
            FUN_130b71d0a30(&uStack_98,&uStack_b0,0,0x130b7207e38);
            lVar19 = (ulonglong)uVar11 * 0x4c;
            cVar6 = (&DAT_130b720b9d0)[lVar19];
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e48);
            uVar11 = _DAT_130b72034b4;
            uVar12 = (ulonglong)_DAT_130b72034b4;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b72034b4;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b72034b4 + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar5 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar5 == '\0') goto LAB_130b71ea9a5;
              if (uVar12 != 0) {
                lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                if (uVar11 < 8) {
                  uVar10 = 0;
                }
                else if (lStack_ac + -0x130b72034b8 + (ulonglong)uVar17 * 2 < 0x20) {
                  uVar10 = 0;
                }
                else {
                  uVar13 = 0;
                  uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                  do {
                    uVar21 = *(undefined4 *)(uVar13 + 0x130b72034bc);
                    uVar22 = *(undefined4 *)(uVar13 + 0x130b72034c0);
                    uVar23 = *(undefined4 *)(uVar13 + 0x130b72034c4);
                    puVar2 = (undefined4 *)(lVar15 + uVar13);
                    *puVar2 = *(undefined4 *)(&DAT_130b72034b8 + uVar13);
                    puVar2[1] = uVar21;
                    puVar2[2] = uVar22;
                    puVar2[3] = uVar23;
                    uVar13 = uVar13 + 0x10;
                  } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                  if (uVar10 == uVar12) goto LAB_130b71e9422;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar10 * 2) =
                       *(undefined2 *)(&DAT_130b72034b8 + uVar10 * 2);
                  uVar10 = uVar10 + 1;
                } while (uVar12 != uVar10);
              }
LAB_130b71e9422:
              *(uint *)(lStack_ac + -4) = uVar16;
              *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
            }
            uVar21 = 0;
            uVar22 = 0;
            if (cVar6 != '\0') {
              uVar21 = uVar25;
              uVar22 = uVar26;
            }
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e58);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar22,uVar21));
            cVar6 = *(char *)(lVar19 + 0x130b720b9d1);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e68);
            uVar11 = _DAT_130b720411c;
            uVar12 = (ulonglong)_DAT_130b720411c;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b720411c;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b720411c + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar5 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar5 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7204120 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b7204124);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7204128);
                      uVar23 = *(undefined4 *)(&DAT_130b720412c + uVar13);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7204120 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e95d2;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7204120 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e95d2:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e95f3;
              }
LAB_130b71ea8e5:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2b000001f9);
LAB_130b71ea905:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c35000001f9);
LAB_130b71ea925:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c32000001f9);
LAB_130b71ea945:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c30000001f9);
LAB_130b71ea965:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2e000001f9);
LAB_130b71ea985:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2c000001f9);
LAB_130b71ea9a5:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2a000001f9);
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
LAB_130b71e95f3:
            uVar21 = 0;
            uVar22 = 0;
            if (cVar6 != '\0') {
              uVar21 = uVar25;
              uVar22 = uVar26;
            }
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e78);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar22,uVar21));
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9d2);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207e88);
            uVar11 = _DAT_130b7203514;
            uVar12 = (ulonglong)_DAT_130b7203514;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b7203514;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b7203514 + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7203518 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b720351c);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7203520);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b7203524);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7203518 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9782;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7203518 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9782:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e97a3;
              }
              goto LAB_130b71ea985;
            }
LAB_130b71e97a3:
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207e98);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar14);
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9da);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ea8);
            uVar11 = _DAT_130b72034f4;
            uVar12 = (ulonglong)_DAT_130b72034f4;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b72034f4;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b72034f4 + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b72034f8 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b72034fc);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7203500);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b7203504);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b72034f8 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9912;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b72034f8 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9912:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e9933;
              }
LAB_130b71ea8c5:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2d000001f9);
              goto LAB_130b71ea8e5;
            }
LAB_130b71e9933:
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207eb8);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar14);
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9e2);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ec8);
            uVar11 = _DAT_130b7203534;
            uVar12 = (ulonglong)_DAT_130b7203534;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b7203534;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b7203534 + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7203538 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b720353c);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7203540);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b7203544);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7203538 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9aa2;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7203538 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9aa2:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e9ac3;
              }
              goto LAB_130b71ea965;
            }
LAB_130b71e9ac3:
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207ed8);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar14);
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9ea);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207ee8);
            uVar11 = _DAT_130b720412c;
            uVar12 = (ulonglong)_DAT_130b720412c;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b720412c;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b720412c + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7204130 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b7204134);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7204138);
                      uVar23 = *(undefined4 *)(&DAT_130b720413c + uVar13);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7204130 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9c32;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7204130 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9c32:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e9c53;
              }
LAB_130b71ea8a5:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c2f000001f9);
              goto LAB_130b71ea8c5;
            }
LAB_130b71e9c53:
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207ef8);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar14);
            lVar15 = *(longlong *)(lVar19 + 0x130b720b9f2);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f08);
            uVar11 = _DAT_130b7203554;
            uVar12 = (ulonglong)_DAT_130b7203554;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b7203554;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b7203554 + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar1 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7203558 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b720355c);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7203560);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b7203564);
                      puVar2 = (undefined4 *)(lVar1 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7203558 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9dc2;
                  }
                  do {
                    *(undefined2 *)(lVar1 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7203558 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9dc2:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71e9de3;
              }
              goto LAB_130b71ea945;
            }
LAB_130b71e9de3:
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f18);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,(double)lVar15);
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720b9fa);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f28);
            uVar11 = _DAT_130b7203574;
            uVar12 = (ulonglong)_DAT_130b7203574;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar10 = 0;
                uVar17 = _DAT_130b7203574;
              }
              else {
                uVar10 = (ulonglong)*(uint *)(lStack_ac + -4);
                uVar17 = _DAT_130b7203574 + *(uint *)(lStack_ac + -4);
              }
              uVar16 = 0x104;
              if ((0x103 < uVar17) &&
                 ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16))))
              {
                uVar16 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar16);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + uVar10 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7203578 + uVar10 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b720357c);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7203580);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b7203584);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7203578 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71e9f62;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7203578 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71e9f62:
                *(uint *)(lStack_ac + -4) = uVar17;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
                goto LAB_130b71e9f83;
              }
LAB_130b71ea885:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c31000001f9);
              goto LAB_130b71ea8a5;
            }
LAB_130b71e9f83:
            FUN_130b71eade0(&uStack_b0,uVar14);
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720ba02);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f38);
            uVar11 = _DAT_130b7203594;
            uVar12 = (ulonglong)_DAT_130b7203594;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar10 = 0;
                uVar17 = _DAT_130b7203594;
              }
              else {
                uVar10 = (ulonglong)*(uint *)(lStack_ac + -4);
                uVar17 = _DAT_130b7203594 + *(uint *)(lStack_ac + -4);
              }
              uVar16 = 0x104;
              if ((0x103 < uVar17) &&
                 ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16))))
              {
                uVar16 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar16);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + uVar10 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7203598 + uVar10 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b720359c);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b72035a0);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b72035a4);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7203598 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71ea0d2;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7203598 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71ea0d2:
                *(uint *)(lStack_ac + -4) = uVar17;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
                goto LAB_130b71ea0f3;
              }
              goto LAB_130b71ea925;
            }
LAB_130b71ea0f3:
            FUN_130b71eade0(&uStack_b0,uVar14);
            lVar15 = *(longlong *)(lVar19 + 0x130b720ba0a);
            if (lVar15 < 1) {
              lVar15 = 0;
            }
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f48);
            uVar11 = _DAT_130b72035b4;
            uVar12 = (ulonglong)_DAT_130b72035b4;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar10 = 0;
                uVar17 = _DAT_130b72035b4;
              }
              else {
                uVar10 = (ulonglong)*(uint *)(lStack_ac + -4);
                uVar17 = _DAT_130b72035b4 + *(uint *)(lStack_ac + -4);
              }
              uVar16 = 0x104;
              if ((0x103 < uVar17) &&
                 ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16))))
              {
                uVar16 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar16);
              if (cVar6 != '\0') {
                if (uVar12 != 0) {
                  lVar1 = lStack_ac + uVar10 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b72035b8 + uVar10 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b72035bc);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b72035c0);
                      uVar23 = *(undefined4 *)(uVar13 + 0x130b72035c4);
                      puVar2 = (undefined4 *)(lVar1 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b72035b8 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71ea242;
                  }
                  do {
                    *(undefined2 *)(lVar1 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b72035b8 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71ea242:
                *(uint *)(lStack_ac + -4) = uVar17;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar17 * 2) = 0;
                goto LAB_130b71ea263;
              }
LAB_130b71ea865:
              (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x130c33000001f9);
              goto LAB_130b71ea885;
            }
LAB_130b71ea263:
            FUN_130b71eade0(&uStack_b0,lVar15);
            cVar6 = *(char *)(lVar19 + 0x130b720ba13);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f58);
            uVar11 = _DAT_130b720413c;
            uVar12 = (ulonglong)_DAT_130b720413c;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar17 = 0;
                uVar16 = _DAT_130b720413c;
              }
              else {
                uVar17 = *(uint *)(lStack_ac + -4);
                uVar16 = _DAT_130b720413c + uVar17;
              }
              uVar18 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18))))
              {
                uVar18 = 0x7ffffffe;
              }
              cVar5 = FUN_130b71d0060(&uStack_b0,uVar18);
              if (cVar5 != '\0') {
                if (uVar12 != 0) {
                  lVar15 = lStack_ac + (ulonglong)uVar17 * 2;
                  if (uVar11 < 8) {
                    uVar10 = 0;
                  }
                  else if (lStack_ac + -0x130b7204140 + (ulonglong)uVar17 * 2 < 0x20) {
                    uVar10 = 0;
                  }
                  else {
                    uVar13 = 0;
                    uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                    do {
                      uVar21 = *(undefined4 *)(uVar13 + 0x130b7204144);
                      uVar22 = *(undefined4 *)(uVar13 + 0x130b7204148);
                      uVar23 = *(undefined4 *)(&DAT_130b720414c + uVar13);
                      puVar2 = (undefined4 *)(lVar15 + uVar13);
                      *puVar2 = *(undefined4 *)(&DAT_130b7204140 + uVar13);
                      puVar2[1] = uVar21;
                      puVar2[2] = uVar22;
                      puVar2[3] = uVar23;
                      uVar13 = uVar13 + 0x10;
                    } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                    if (uVar10 == uVar12) goto LAB_130b71ea3b2;
                  }
                  do {
                    *(undefined2 *)(lVar15 + uVar10 * 2) =
                         *(undefined2 *)(&DAT_130b7204140 + uVar10 * 2);
                    uVar10 = uVar10 + 1;
                  } while (uVar12 != uVar10);
                }
LAB_130b71ea3b2:
                *(uint *)(lStack_ac + -4) = uVar16;
                *(undefined2 *)(lStack_ac + (ulonglong)uVar16 * 2) = 0;
                goto LAB_130b71ea3c9;
              }
              goto LAB_130b71ea905;
            }
LAB_130b71ea3c9:
            uVar21 = 0;
            uVar22 = 0;
            if (cVar6 != '\0') {
              uVar21 = uVar25;
              uVar22 = uVar26;
            }
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f68);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,CONCAT44(uVar22,uVar21));
            uVar14 = *(undefined8 *)(lVar19 + 0x130b720ba14);
            FUN_130b71d0a30(&uStack_b0,&uStack_98,0,0x130b7207f78);
            uVar17 = uStack_9c;
            uVar11 = _DAT_130b720414c;
            uVar12 = (ulonglong)_DAT_130b720414c;
            if ((uVar12 != 0) || (lStack_ac == 0)) {
              if (lStack_ac == 0) {
                uVar16 = 0;
                uVar18 = _DAT_130b720414c;
              }
              else {
                uVar16 = *(uint *)(lStack_ac + -4);
                uVar18 = _DAT_130b720414c + uVar16;
              }
              uVar9 = 0x104;
              if ((0x103 < uVar18) &&
                 ((0x7ffffffd < uVar18 || (uVar9 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar9)))) {
                uVar9 = 0x7ffffffe;
              }
              cVar6 = FUN_130b71d0060(&uStack_b0,uVar9);
              if (cVar6 == '\0') {
                (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x250c36000001f9);
                goto LAB_130b71ea865;
              }
              if (uVar12 != 0) {
                lVar19 = lStack_ac + (ulonglong)uVar16 * 2;
                if (uVar11 < 8) {
                  uVar10 = 0;
                }
                else if (lStack_ac + -0x130b7204150 + (ulonglong)uVar16 * 2 < 0x20) {
                  uVar10 = 0;
                }
                else {
                  uVar13 = 0;
                  uVar10 = (ulonglong)(uVar11 & 0xfffffff8);
                  do {
                    uVar21 = *(undefined4 *)(uVar13 + 0x130b7204154);
                    uVar22 = *(undefined4 *)(uVar13 + 0x130b7204158);
                    uVar23 = *(undefined4 *)(uVar13 + 0x130b720415c);
                    puVar2 = (undefined4 *)(lVar19 + uVar13);
                    *puVar2 = *(undefined4 *)(&DAT_130b7204150 + uVar13);
                    puVar2[1] = uVar21;
                    puVar2[2] = uVar22;
                    puVar2[3] = uVar23;
                    uVar13 = uVar13 + 0x10;
                  } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar13);
                  if (uVar10 == uVar12) goto LAB_130b71e91e0;
                }
                do {
                  *(undefined2 *)(lVar19 + uVar10 * 2) =
                       *(undefined2 *)(&DAT_130b7204150 + uVar10 * 2);
                  uVar10 = uVar10 + 1;
                } while (uVar12 != uVar10);
              }
LAB_130b71e91e0:
              *(uint *)(lStack_ac + -4) = uVar18;
              *(undefined2 *)(lStack_ac + (ulonglong)uVar18 * 2) = 0;
            }
            FUN_130b71ea9d0(&uStack_b0);
            FUN_130b71d0a30(&uStack_88,0x130b720bb3c,1,0x130b7207f88);
            (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_88,uVar14);
            FUN_130b71d0000(&uStack_98);
            uVar11 = 1;
            uVar14 = 0;
          } while ((uVar17 & 1) != 0);
          dVar20 = (double)_DAT_130b720bc50;
          FUN_130b71ea9d0(0x130b7204178);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207f98);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar20);
          dVar20 = (double)_DAT_130b720bc58;
          FUN_130b71ea9d0(0x130b72041a8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fa8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,dVar20);
          uVar14 = _DAT_130b720bc60;
          FUN_130b71ea9d0(0x130b72041d8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fb8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar14);
          uVar14 = _DAT_130b720bc68;
          FUN_130b71ea9d0(0x130b7204208);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fc8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar14);
          uVar14 = _DAT_130b720bc70;
          FUN_130b71ea9d0(0x130b7204238);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fd8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar14);
          uVar14 = _DAT_130b720bc78;
          FUN_130b71ea9d0(0x130b7204268);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207fe8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar14);
          uVar25 = 0;
          uVar26 = 0;
          if (cStack_9d != '\0') {
            uVar25 = (undefined4)_DAT_130b72014a8;
            uVar26 = (undefined4)((ulonglong)_DAT_130b72014a8 >> 0x20);
          }
          FUN_130b71ea9d0(0x130b7204298);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7207ff8);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,CONCAT44(uVar26,uVar25));
          uVar14 = _DAT_130b720bc88;
          FUN_130b71ea9d0(0x130b72042c8);
          FUN_130b71d0a30(&uStack_b0,0x130b720bb3c,1,0x130b7208008);
          (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&uStack_b0,uVar14);
          _DAT_130b720bb10 = 0;
          _DAT_130b720bb80 = 0;
          DAT_130b720bb88 = 0;
          (*(code *)0x7ff63a0edfa0)(0x130b53f81d8);
          if (_DAT_130b720bb10 != 0) {
            (*(code *)0x7ff63a0e49f0)
                      (0x130b53f81d8,0xd,2,0x590008,0x130b7204310,0x520004,_DAT_130b720bb10);
          }
        }
        FUN_130b71d0000(&uStack_b0);
        FUN_130b71d0000(&uStack_88);
        return;
      }
    }
  }
  return;
}



/* Address: 130b71f6b50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f6b50(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_120;
  longlong local_11c;
  undefined4 local_110;
  longlong local_10c;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  longlong local_dc;
  undefined4 local_d0;
  longlong local_cc;
  undefined4 local_c0;
  longlong local_bc;
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
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_a0 = 0;
  local_b0 = 0;
  local_c0 = 0;
  local_70 = 0;
  local_d0 = 0;
  local_e0 = 0;
  local_80 = 0;
  local_f0 = 0;
  local_100 = 0;
  local_110 = 0;
  local_120 = 0;
  local_90 = 0;
  local_60 = 0;
  local_50 = 0;
  local_9c = 0;
  local_ac = 0;
  local_bc = 0;
  local_6c = 0;
  local_cc = 0;
  local_dc = 0;
  local_7c = 0;
  local_ec = 0;
  local_fc = 0;
  local_10c = 0;
  local_11c = 0;
  local_8c = 0;
  local_5c = 0;
  local_4c = 0;
  (*(code *)0x7ff63a0e49f0)
            (0x130b53f81d8,0xd8,10,0x590008,0x130b72033d8,0x520004,0x51,0x520004,0x54,0x520004,0x32,
             0x520004,0x5f,0x520004,0x50,0x520004,0x52,0x520004,0x4f,0x520004,0x54,0x520004,0x5f);
  FUN_130b71d0a30(&local_60,0x130b720bb3c,1,0x130b7208408);
  uVar10 = (*(code *)0x7ff63a0c73c0)(0x130b53f81d8,0);
  (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,uVar10,0x55,&local_90);
  FUN_130b71d0a30(&local_120,&local_60,0);
  lVar2 = local_8c;
  if (local_8c == 0) {
LAB_130b71f6f1d:
    uVar11 = 0;
    FUN_130b71d0a30(&local_110,&local_120,0);
    uVar17 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_10c == 0)) {
      if (local_10c != 0) {
        uVar11 = (ulonglong)*(uint *)(local_10c + -4);
      }
      uVar14 = _DAT_130b7203354 + (int)uVar11;
      cVar9 = FUN_130b71d0060(&local_110);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar2 = local_10c + uVar11 * 2;
          if ((uVar17 < 0x10) || (lVar2 - 0x130b7203358U < 0x20)) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71f7012;
          }
          do {
            *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71f7012:
        *(uint *)(local_10c + -4) = uVar14;
        *(undefined2 *)(local_10c + (ulonglong)uVar14 * 2) = 0;
        goto LAB_130b71f701d;
      }
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x6e1067000001f9);
LAB_130b71f7a51:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x7a1067000001f9);
LAB_130b71f7a71:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x131068000001f9);
LAB_130b71f7a91:
      (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x291068000001f9);
      goto LAB_130b71f7ab1;
    }
LAB_130b71f701d:
    FUN_130b71d0a30(&local_100,&local_110,0);
    lVar2 = _DAT_130b720bb2c;
    if (_DAT_130b720bb2c != 0) {
      uVar17 = *(uint *)(_DAT_130b720bb2c + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_fc != 0)) goto LAB_130b71f71ad;
      if (local_fc == 0) {
        uVar11 = 0;
        uVar14 = uVar17;
      }
      else {
        uVar11 = (ulonglong)*(uint *)(local_fc + -4);
        uVar14 = uVar17 + *(uint *)(local_fc + -4);
      }
      cVar9 = FUN_130b71d0060(&local_100);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar1 = local_fc + uVar11 * 2;
          if (uVar17 < 0x10) {
            uVar11 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar1 + uVar16);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71f71a2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71f71a2:
        *(uint *)(local_fc + -4) = uVar14;
        *(undefined2 *)(local_fc + (ulonglong)uVar14 * 2) = 0;
        goto LAB_130b71f71ad;
      }
      goto LAB_130b71f7ad1;
    }
LAB_130b71f71ad:
    uVar11 = 0;
    FUN_130b71d0a30(&local_f0,&local_100,0);
    uVar17 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_ec == 0)) {
      if (local_ec != 0) {
        uVar11 = (ulonglong)*(uint *)(local_ec + -4);
      }
      uVar14 = _DAT_130b7203354 + (int)uVar11;
      cVar9 = FUN_130b71d0060(&local_f0);
      if (cVar9 == '\0') goto LAB_130b71f7a51;
      if (uVar13 != 0) {
        lVar2 = local_ec + uVar11 * 2;
        if ((uVar17 < 0x10) || (lVar2 - 0x130b7203358U < 0x20)) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
            uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
            uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71f7292;
        }
        do {
          *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71f7292:
      *(uint *)(local_ec + -4) = uVar14;
      *(undefined2 *)(local_ec + (ulonglong)uVar14 * 2) = 0;
    }
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(longlong)_DAT_130b720bc30,0x52,&local_80);
    FUN_130b71d0a30(&local_e0,&local_f0,0);
    lVar2 = local_7c;
    if (local_7c != 0) {
      uVar17 = *(uint *)(local_7c + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_dc != 0)) goto LAB_130b71f744d;
      if (local_dc == 0) {
        uVar14 = 0;
        uVar15 = uVar17;
      }
      else {
        uVar14 = *(uint *)(local_dc + -4);
        uVar15 = uVar17 + uVar14;
      }
      cVar9 = FUN_130b71d0060(&local_e0);
      if (cVar9 != '\0') {
        if (uVar13 != 0) {
          lVar1 = local_dc + (ulonglong)uVar14 * 2;
          if (uVar17 < 0x10) {
            uVar11 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar1 + uVar16);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71f7442;
          }
          do {
            *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71f7442:
        *(uint *)(local_dc + -4) = uVar15;
        *(undefined2 *)(local_dc + (ulonglong)uVar15 * 2) = 0;
        goto LAB_130b71f744d;
      }
      goto LAB_130b71f7af1;
    }
LAB_130b71f744d:
    uVar17 = 0;
    FUN_130b71d0a30(&local_d0,&local_e0,0);
    uVar14 = _DAT_130b7203354;
    uVar13 = (ulonglong)_DAT_130b7203354;
    if ((uVar13 != 0) || (local_cc == 0)) {
      if (local_cc != 0) {
        uVar17 = *(uint *)(local_cc + -4);
      }
      uVar15 = _DAT_130b7203354 + uVar17;
      cVar9 = FUN_130b71d0060(&local_d0);
      if (cVar9 == '\0') goto LAB_130b71f7a71;
      if (uVar13 != 0) {
        lVar2 = local_cc + (ulonglong)uVar17 * 2;
        if ((uVar14 < 0x10) || (lVar2 - 0x130b7203358U < 0x20)) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
            uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
            uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71f7532;
        }
        do {
          *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71f7532:
      *(uint *)(local_cc + -4) = uVar15;
      *(undefined2 *)(local_cc + (ulonglong)uVar15 * 2) = 0;
    }
    (*(code *)0x7ff63a0ff6c0)(0x130b53f81d8,(longlong)_DAT_130b720bcb8,0x52,&local_70);
    FUN_130b71d0a30(&local_c0,&local_d0);
    lVar2 = local_6c;
    if (local_6c == 0) {
LAB_130b71f76ed:
      uVar17 = 0;
      FUN_130b71d0a30(&local_b0,&local_c0,0,0x130b7208488);
      uVar14 = _DAT_130b7203354;
      uVar13 = (ulonglong)_DAT_130b7203354;
      if ((uVar13 != 0) || (local_ac == 0)) {
        if (local_ac != 0) {
          uVar17 = *(uint *)(local_ac + -4);
        }
        uVar12 = _DAT_130b7203354 + uVar17;
        uVar15 = 0x104;
        if ((0x103 < uVar12) &&
           ((0x7ffffffd < uVar12 || (uVar15 = (uVar12 >> 2) + uVar12, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar9 = FUN_130b71d0060(&local_b0,uVar15);
        if (cVar9 == '\0') goto LAB_130b71f7a91;
        if (uVar13 != 0) {
          lVar2 = local_ac + (ulonglong)uVar17 * 2;
          if (uVar14 < 0x10) {
            uVar11 = 0;
          }
          else if (lVar2 - 0x130b7203358U < 0x20) {
            uVar11 = 0;
          }
          else {
            uVar16 = 0;
            uVar11 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar16 + 0x130b720335c);
              uVar7 = *(undefined4 *)(uVar16 + 0x130b7203360);
              uVar8 = *(undefined4 *)(uVar16 + 0x130b7203364);
              puVar3 = (undefined4 *)(lVar2 + uVar16);
              *puVar3 = *(undefined4 *)(&DAT_130b7203358 + uVar16);
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar13) goto LAB_130b71f7812;
          }
          do {
            *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_130b7203358 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar13 != uVar11);
        }
LAB_130b71f7812:
        *(uint *)(local_ac + -4) = uVar12;
        *(undefined2 *)(local_ac + (ulonglong)uVar12 * 2) = 0;
      }
      FUN_130b71d0a30(&local_a0,&local_b0,0);
      lVar2 = *(longlong *)(param_1 + 4);
      if (lVar2 == 0) goto LAB_130b71f794d;
      uVar17 = *(uint *)(lVar2 + -4);
      uVar13 = (ulonglong)uVar17;
      if ((uVar13 == 0) && (local_9c != 0)) goto LAB_130b71f794d;
      if (local_9c == 0) {
        uVar11 = 0;
        uVar14 = uVar17;
      }
      else {
        uVar11 = (ulonglong)*(uint *)(local_9c + -4);
        uVar14 = uVar17 + *(uint *)(local_9c + -4);
      }
      cVar9 = FUN_130b71d0060(&local_a0);
      if (cVar9 == '\0') goto LAB_130b71f7b31;
      if (uVar13 != 0) {
        lVar1 = local_9c + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71f7942;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71f7942:
      *(uint *)(local_9c + -4) = uVar14;
      *(undefined2 *)(local_9c + (ulonglong)uVar14 * 2) = 0;
LAB_130b71f794d:
      FUN_130b71d0a30(&local_50,&local_a0,0,0x130b72084a8);
      FUN_130b71d0a30(0x130b720bb3c,&local_50,1,0x130b72084b8);
      FUN_130b71d0000(&local_50);
      FUN_130b71d0000(&local_60);
      FUN_130b71d0000(&local_90);
      FUN_130b71d0000(&local_120);
      FUN_130b71d0000(&local_110);
      FUN_130b71d0000(&local_100);
      FUN_130b71d0000(&local_f0);
      FUN_130b71d0000(&local_80);
      FUN_130b71d0000(&local_e0);
      FUN_130b71d0000(&local_d0);
      FUN_130b71d0000(&local_70);
      FUN_130b71d0000(&local_c0);
      FUN_130b71d0000(&local_b0);
      FUN_130b71d0000(&local_a0);
      return;
    }
    uVar17 = *(uint *)(local_6c + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_bc != 0)) goto LAB_130b71f76ed;
    if (local_bc == 0) {
      uVar11 = 0;
      uVar14 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_bc + -4);
      uVar14 = uVar17 + *(uint *)(local_bc + -4);
    }
    cVar9 = FUN_130b71d0060(&local_c0);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_bc + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71f76e2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71f76e2:
      *(uint *)(local_bc + -4) = uVar14;
      *(undefined2 *)(local_bc + (ulonglong)uVar14 * 2) = 0;
      goto LAB_130b71f76ed;
    }
  }
  else {
    uVar17 = *(uint *)(local_8c + -4);
    uVar13 = (ulonglong)uVar17;
    if ((uVar13 == 0) && (local_11c != 0)) goto LAB_130b71f6f1d;
    if (local_11c == 0) {
      uVar11 = 0;
      uVar14 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_11c + -4);
      uVar14 = uVar17 + *(uint *)(local_11c + -4);
    }
    cVar9 = FUN_130b71d0060(&local_120);
    if (cVar9 != '\0') {
      if (uVar13 != 0) {
        lVar1 = local_11c + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar1 + uVar16);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar13) goto LAB_130b71f6f12;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar13 != uVar11);
      }
LAB_130b71f6f12:
      *(uint *)(local_11c + -4) = uVar14;
      *(undefined2 *)(local_11c + (ulonglong)uVar14 * 2) = 0;
      goto LAB_130b71f6f1d;
    }
LAB_130b71f7ab1:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x441067000001f9);
LAB_130b71f7ad1:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x721067000001f9);
LAB_130b71f7af1:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x7e1067000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x171068000001f9);
LAB_130b71f7b31:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2d1068000001f9);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



/* Address: 130b71f7b60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f7b60(void)

{
  int iVar1;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_38;
  undefined8 local_34;
  
  local_38 = 0;
  local_48 = 0;
  local_58 = 0;
  local_68 = 0;
  local_34 = 0;
  local_44 = 0;
  local_54 = 0;
  local_64 = 0;
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x130b53f81d8,6);
  if (iVar1 != 0) goto LAB_130b71f7dd3;
  local_48 = 0;
  local_44 = 0;
  FUN_130b71f6b50(0x130b7203da8);
  FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b72084c8);
  FUN_130b71d0a30(&local_48,&local_38,0,0x130b72084d8);
  local_58 = 0;
  local_54 = 0;
  FUN_130b71f6b50(0x130b7204c98);
  FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b72084e8);
  FUN_130b71d0a30(&local_58,&local_38,0,0x130b72084f8);
  local_68 = 0;
  local_64 = 0;
  FUN_130b71f6b50(0x130b7204cc8);
  FUN_130b71d0a30(&local_38,0x130b720bb3c,1,0x130b7208508);
  FUN_130b71d0a30(&local_68,&local_38,0,0x130b7208518);
  if (_DAT_130b720ba68 < 1) {
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_48);
  }
  else {
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_48,(double)_DAT_130b720ba68);
  }
  if (DAT_130b720ba6c == '\0') {
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_58);
    if (DAT_130b720ba6d == '\0') goto LAB_130b71f7da3;
LAB_130b71f7d6c:
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_68,_DAT_130b7201680);
  }
  else {
    (*(code *)0x7ff63a0edc90)(0x130b53f81d8,&local_58,_DAT_130b7201680);
    if (DAT_130b720ba6d != '\0') goto LAB_130b71f7d6c;
LAB_130b71f7da3:
    (*(code *)0x7ff63a0edde0)(0x130b53f81d8,&local_68);
  }
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_58);
  FUN_130b71d0000(&local_48);
LAB_130b71f7dd3:
  FUN_130b71d0000(&local_38);
  return;
}



/* Address: 130b71f7df0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f7df0(void)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_38;
  undefined8 local_34;
  
  if (DAT_130b720ba6c == '\0') {
    bVar3 = true;
  }
  else {
    DAT_130b720b95d = 0;
    _DAT_130b720b960 = 0;
    DAT_130b720b95c = 0;
    _DAT_130b720b968 = 0;
    _DAT_130b720b970 = 0;
    _DAT_130b720b978 = 0;
    FUN_130b71d0a30(0x130b720b980,0x130b7201870,0,0x130b7207ce8);
    _DAT_130b720b998 = 0;
    _DAT_130b720b9a0 = 0;
    _DAT_130b720b990 = 0;
    _DAT_130b720b9a8 = 0;
    FUN_130b71d0a30(0x130b720b9b0,0x130b7201870,0,0x130b7207cf8);
    FUN_130b71eb510(0x130b7204d80);
    uVar1 = _DAT_130b720bc30;
    local_38 = 0;
    local_34 = 0;
    FUN_130b71d0a30(&local_38,0x130b720bb28,1,0x130b7208588);
    iVar2 = FUN_130b71efd10(&local_38,uVar1);
    FUN_130b71d0000(&local_38);
    bVar3 = iVar2 != 0;
    if (!bVar3) {
      DAT_130b720ba6c = '\0';
      _DAT_130b720b90c = 0xffffffff;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204db8);
    }
  }
  if (DAT_130b720ba6d != '\0') {
    FUN_130b71eb3a0();
    FUN_130b71eb6f0();
    iVar2 = FUN_130b71e0270();
    if ((iVar2 == 0) && (DAT_130b720b8c0 == '\0')) {
      DAT_130b720ba6d = '\0';
      _DAT_130b720b708 = 0;
      (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204df8);
      goto LAB_130b71f8078;
    }
  }
  if (bVar3) {
    return;
  }
LAB_130b71f8078:
  FUN_130b71f7b60();
  FUN_130b71e8bd0();
  return;
}



/* Address: 130b71f80a0 */

void FUN_130b71f80a0(longlong param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined4 local_48;
  longlong local_44;
  undefined4 local_38;
  undefined8 local_34;
  
  local_48 = 0;
  local_38 = 0;
  local_44 = 0;
  local_34 = 0;
  FUN_130b71d0a30(&local_48,0x130b720ba70,0);
  lVar5 = *(longlong *)(param_1 + 4);
  if (lVar5 == 0) goto LAB_130b71f81fd;
  uVar4 = *(uint *)(lVar5 + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_44 != 0)) goto LAB_130b71f81fd;
  if (local_44 == 0) {
    uVar15 = 0;
    uVar12 = uVar4;
  }
  else {
    uVar15 = *(uint *)(local_44 + -4);
    uVar12 = uVar4 + uVar15;
  }
  cVar10 = FUN_130b71d0060(&local_48);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x10114f000001f9);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  if (uVar13 != 0) {
    lVar1 = local_44 + (ulonglong)uVar15 * 2;
    if (uVar4 < 0x10) {
      uVar11 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
      uVar11 = 0;
    }
    else {
      uVar14 = 0;
      uVar11 = (ulonglong)(uVar4 & 0xfffffff8);
      do {
        puVar2 = (undefined4 *)(lVar5 + uVar14);
        uVar7 = puVar2[1];
        uVar8 = puVar2[2];
        uVar9 = puVar2[3];
        puVar3 = (undefined4 *)(lVar1 + uVar14);
        *puVar3 = *puVar2;
        puVar3[1] = uVar7;
        puVar3[2] = uVar8;
        puVar3[3] = uVar9;
        uVar14 = uVar14 + 0x10;
      } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar14);
      if (uVar11 == uVar13) goto LAB_130b71f81f2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar5 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_130b71f81f2:
  *(uint *)(local_44 + -4) = uVar12;
  *(undefined2 *)(local_44 + (ulonglong)uVar12 * 2) = 0;
LAB_130b71f81fd:
  FUN_130b71d0a30(&local_38,&local_48,0,0x130b72085b8);
  FUN_130b71d0a30(0x130b720bb3c,&local_38,1,0x130b72085c8);
  FUN_130b71d0000(&local_38);
  FUN_130b71d0000(&local_48);
  return;
}



/* Address: 130b71f8280 */

void FUN_130b71f8280(undefined8 param_1,undefined4 param_2,int param_3,undefined8 param_4,
                    undefined4 param_5,undefined4 param_6,undefined8 param_7)

{
  char cVar1;
  int iVar2;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_60 = 0;
  local_4c = 0;
  local_5c = 0;
  local_70 = 0;
  local_68 = 0;
  FUN_130b71d0a30(&local_60,param_1,0,0x130b72085f8);
  FUN_130b71f80a0(&local_60);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208608);
  FUN_130b71d0a30(&local_70,&local_50,0,0x130b7208618);
  iVar2 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_70);
  if (iVar2 < 0) {
    cVar1 = (*(code *)0x7ff63a0e49f0)
                      (0x130b53f81d8,0x112,6,0x550005,0,0x590008,&local_70,0x520004,0x66,0x520004,0,
                       0x540005,0,0x580007,0);
    if (cVar1 != '\0') {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f4,param_2);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f5,(longlong)param_3);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3ea,param_5);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0,param_6);
      (*(code *)0x7ff63a0f3c80)(0x130b53f81d8,0,&local_70,0x3e9,param_7);
      (*(code *)0x7ff63a0f3c80)(0x130b53f81d8,0,&local_70,6,param_4);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,10,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,3,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0xd0,0);
    }
  }
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_50);
  return;
}



/* Address: 130b71f8570 */

void FUN_130b71f8570(undefined8 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                    undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_60 = 0;
  local_4c = 0;
  local_5c = 0;
  local_70 = 0;
  local_68 = 0;
  FUN_130b71d0a30(&local_60,param_1,0,0x130b7208628);
  FUN_130b71f80a0(&local_60);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208638);
  FUN_130b71d0a30(&local_70,&local_50,0,0x130b7208648);
  iVar2 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_70);
  if (iVar2 < 0) {
    cVar1 = (*(code *)0x7ff63a0e49f0)
                      (0x130b53f81d8,0x112,6,0x550005,0,0x590008,&local_70,0x520004,0x67,0x520004,0,
                       0x540005,0,0x580007,0);
    if (cVar1 != '\0') {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f4,param_2);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f5,param_3);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3fb,(longlong)param_4);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3fc,0x18);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3ea,param_6);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0,param_7);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x401,param_8);
      uVar3 = 0x302b19;
      if (DAT_130b720ba81 == '\0') {
        uVar3 = 0;
      }
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x40b,uVar3);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,2,1);
      (*(code *)0x7ff63a0f3c80)(0x130b53f81d8,0,&local_70,0x3e9,0x130b7204fa0);
      (*(code *)0x7ff63a0f3c80)(0x130b53f81d8,0,&local_70,6,param_5);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,10,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,3,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0xd0,0);
    }
  }
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_50);
  return;
}



/* Address: 130b71f8900 */

void FUN_130b71f8900(undefined8 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_60 = 0;
  local_4c = 0;
  local_5c = 0;
  local_70 = 0;
  local_68 = 0;
  FUN_130b71d0a30(&local_60,param_1,0,0x130b7208658);
  FUN_130b71f80a0(&local_60);
  FUN_130b71d0a30(&local_50,0x130b720bb3c,1,0x130b7208668);
  FUN_130b71d0a30(&local_70,&local_50,0,0x130b7208678);
  iVar2 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_70);
  if (iVar2 < 0) {
    cVar1 = (*(code *)0x7ff63a0e49f0)
                      (0x130b53f81d8,0x112,6,0x550005,0,0x590008,&local_70,0x520004,0x6e,0x520004,0,
                       0x540005,0,0x580007,0);
    if (cVar1 != '\0') {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x402,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f4,param_2);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3f5,param_3);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3fb,(longlong)param_4);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x3fc,param_5);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x401,param_6);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0x40b,param_7);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0,param_7);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,1,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,2,1);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,10,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,3,0);
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_70,0xd0,0);
    }
  }
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_60);
  FUN_130b71d0000(&local_50);
  return;
}



/* Address: 130b71f8c30 */

void FUN_130b71f8c30(undefined8 param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong in_stack_ffffffffffffff98;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_40 = 0;
  local_60 = 0;
  local_50 = 0;
  local_2c = 0;
  local_3c = 0;
  local_5c = 0;
  local_4c = 0;
  FUN_130b71d0a30(&local_40,param_1,0,0x130b7208688);
  FUN_130b71f80a0(&local_40);
  FUN_130b71d0a30(&local_30,0x130b720bb3c,1,0x130b7208698);
  FUN_130b71d0a30(&local_50,&local_30,0,0x130b72086a8);
  iVar6 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_50);
  if (iVar6 < 0) goto LAB_130b71f8e30;
  local_60 = 0;
  local_5c = 0;
  (*(code *)0x7ff63a0f4a80)
            (0x130b53f81d8,0,&local_50,6,in_stack_ffffffffffffff98 & 0xffffffff00000000);
  FUN_130b71d0a30(&local_40,0x130b720bb3c,1,0x130b72086b8);
  FUN_130b71d0a30(&local_60,&local_40,0,0x130b72086c8);
  lVar5 = *(longlong *)(param_2 + 4);
  if (local_5c != lVar5) {
    if ((local_5c != 0) && (lVar5 != 0)) {
      uVar3 = *(uint *)(local_5c + -4);
      uVar4 = *(uint *)(lVar5 + -4);
      uVar7 = uVar4;
      if (uVar3 < uVar4) {
        uVar7 = uVar3;
      }
      iVar6 = uVar3 - uVar4;
      if (uVar7 != 0) {
        uVar8 = 1;
        do {
          uVar1 = *(ushort *)(local_5c + -2 + uVar8 * 2);
          uVar2 = *(ushort *)(lVar5 + -2 + uVar8 * 2);
          if (uVar7 <= uVar8) break;
          uVar8 = uVar8 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar6 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar6 == 0) goto LAB_130b71f8e29;
    }
    (*(code *)0x7ff63a0f3c80)(0x130b53f81d8,0,&local_50,6,param_2);
  }
LAB_130b71f8e29:
  FUN_130b71d0000(&local_60);
LAB_130b71f8e30:
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_30);
  return;
}



/* Address: 130b71f8e50 */

void FUN_130b71f8e50(undefined8 param_1,int param_2)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_40 = 0;
  local_2c = 0;
  local_3c = 0;
  local_50 = 0;
  local_48 = 0;
  FUN_130b71d0a30(&local_40,param_1,0,0x130b72086d8);
  FUN_130b71f80a0(&local_40);
  FUN_130b71d0a30(&local_30,0x130b720bb3c,1,0x130b72086e8);
  FUN_130b71d0a30(&local_50,&local_30,0,0x130b72086f8);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_50);
  if (-1 < iVar1) {
    iVar1 = (*(code *)0x7ff63a0f49a0)
                      (0x130b53f81d8,0,&local_50,0,in_stack_ffffffffffffffa8 & 0xffffffff00000000);
    if (iVar1 != param_2) {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_50,0,param_2);
    }
  }
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_30);
  return;
}



/* Address: 130b71f8fa0 */

void FUN_130b71f8fa0(undefined8 param_1,int param_2)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_40 = 0;
  local_2c = 0;
  local_3c = 0;
  local_50 = 0;
  local_48 = 0;
  FUN_130b71d0a30(&local_40,param_1,0,0x130b7208708);
  FUN_130b71f80a0(&local_40);
  FUN_130b71d0a30(&local_30,0x130b720bb3c,1,0x130b7208718);
  FUN_130b71d0a30(&local_50,&local_30,0,0x130b7208728);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_50);
  if (-1 < iVar1) {
    iVar1 = (*(code *)0x7ff63a0f49a0)
                      (0x130b53f81d8,0,&local_50,0x401,
                       in_stack_ffffffffffffffa8 & 0xffffffff00000000);
    if (iVar1 != param_2) {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_50,0x401,param_2);
    }
  }
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_30);
  return;
}



/* Address: 130b71f9100 */

void FUN_130b71f9100(undefined8 param_1,int param_2)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_40 = 0;
  local_2c = 0;
  local_3c = 0;
  local_50 = 0;
  local_48 = 0;
  FUN_130b71d0a30(&local_40,param_1,0,0x130b7208738);
  FUN_130b71f80a0(&local_40);
  FUN_130b71d0a30(&local_30,0x130b720bb3c,1,0x130b7208748);
  FUN_130b71d0a30(&local_50,&local_30,0,0x130b7208758);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_50);
  if (-1 < iVar1) {
    iVar1 = (*(code *)0x7ff63a0f49a0)
                      (0x130b53f81d8,0,&local_50,0x40b,
                       in_stack_ffffffffffffffa8 & 0xffffffff00000000);
    if (iVar1 != param_2) {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_50,0x40b,param_2);
    }
  }
  FUN_130b71d0000(&local_50);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_30);
  return;
}



/* Address: 130b71f9260 */

void FUN_130b71f9260(undefined8 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  local_48 = 0;
  local_58 = 0;
  local_44 = 0;
  local_54 = 0;
  local_68 = 0;
  local_60 = 0;
  FUN_130b71d0a30(&local_58,param_1,0,0x130b7208768);
  FUN_130b71f80a0(&local_58);
  FUN_130b71d0a30(&local_48,0x130b720bb3c,1,0x130b7208778);
  FUN_130b71d0a30(&local_68,&local_48,0,0x130b7208788);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_68);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_68,0x3f4,param_2);
    (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_68,0x3f5,(longlong)param_3);
    if (-1 < param_4) {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_68,0x3fb,param_4);
    }
    if (-1 < param_5) {
      (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_68,0x3fc,param_5);
    }
  }
  FUN_130b71d0000(&local_68);
  FUN_130b71d0000(&local_58);
  FUN_130b71d0000(&local_48);
  return;
}



/* Address: 130b71f9410 */

void FUN_130b71f9410(uint param_1)

{
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_40 = 0;
  local_2c = 0;
  local_3c = 0;
  if (param_1 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0130b71f9464 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_1 * 8 + 0x130b7201688))();
    return;
  }
  FUN_130b71d0a30(&local_40,0x130b7205170,0,0x130b72088b8);
  FUN_130b71d0a30(0x130b720bb3c,&local_40,1,0x130b72088c8);
  FUN_130b71d0000(&local_40);
  FUN_130b71d0000(&local_30);
  return;
}



/* Address: 130b71f9670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71f9670(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 local_28;
  undefined8 local_24;
  
  iVar1 = _DAT_130b720ba68;
  local_28 = 0;
  local_24 = 0;
  if (param_1 == '\0') {
    uVar4 = 0x130b7205230;
    uVar5 = 0x130b72088d8;
    goto LAB_130b71f9780;
  }
  if (DAT_130b720ba6e == '\0') {
    if (DAT_130b720bd48 == '\0') {
      if (0 < _DAT_130b720ba68) {
        _DAT_130b720ba68 = -1;
        FUN_130b71f7b60();
      }
    }
    else if (0 < _DAT_130b720ba68) {
      iVar3 = FUN_130b71efc10();
      iVar2 = _DAT_130b720ba68;
      if (iVar1 == iVar3) goto LAB_130b71f96a5;
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
      if (0 < iVar2) {
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d08);
      }
    }
    uVar4 = 0x130b7205290;
    uVar5 = 0x130b72088f8;
  }
  else {
LAB_130b71f96a5:
    uVar4 = 0x130b7205260;
    uVar5 = 0x130b72088e8;
  }
LAB_130b71f9780:
  FUN_130b71d0a30(&local_28,uVar4,0,uVar5);
  FUN_130b71d0a30(0x130b720bb3c,&local_28,1,0x130b7208908);
  FUN_130b71d0000(&local_28);
  return;
}



/* Address: 130b71f97d0 */

void FUN_130b71f97d0(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 in_stack_ffffffffffffff48;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined4 local_90;
  undefined8 local_8c;
  ulonglong local_80;
  int local_74;
  undefined4 local_70;
  undefined8 local_6c;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  int local_48;
  int local_44;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  local_58 = 0;
  local_70 = 0;
  local_90 = 0;
  local_54 = 0;
  local_6c = 0;
  local_8c = 0;
  if (DAT_130b720bd58 != '\0') {
    local_80 = 0xc;
    if (DAT_130b720ba90 == '\0') {
      local_80 = 0;
    }
    iVar4 = (int)local_80;
    uVar1 = 0x18;
    if (DAT_130b720ba91 == '\0') {
      uVar1 = 0;
    }
    iVar10 = (int)uVar1;
    uVar7 = 0x60402;
    if (DAT_130b720ba7d == '\0') {
      uVar7 = 0;
    }
    uVar3 = 0x1fe;
    uVar6 = 0;
    if (DAT_130b720ba93 != '\0') {
      uVar6 = uVar3;
    }
    uVar2 = 0xfffffffa;
    if (DAT_130b720ba92 != '\0') {
      uVar2 = 0x18e;
    }
    FUN_130b71d0a30(&local_90,0x130b7205360,0,0x130b7208998);
    uVar13 = CONCAT44(uVar14,uVar7);
    uVar11 = CONCAT44(uVar9,uVar6);
    FUN_130b71f8900(&local_90,iVar4 + 3,iVar10 + 4,uVar2,uVar11,uVar7,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0x302b19;
    if (DAT_130b720ba81 == '\0') {
      uVar9 = 0;
    }
    uVar6 = 0xe0b07;
    if (DAT_130b720ba7c == '\0') {
      uVar6 = 0;
    }
    if (DAT_130b720ba93 == '\0') {
      uVar3 = 0;
    }
    uVar2 = 0x194;
    if (DAT_130b720ba92 == '\0') {
      uVar2 = 0;
    }
    FUN_130b71d0a30(&local_90,0x130b7205388,0,0x130b72089a8);
    uVar5 = local_80;
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,uVar3);
    FUN_130b71f8900(&local_90,local_80 & 0xffffffff,uVar1,uVar2,uVar11,uVar6,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    uVar6 = 0xfffffffe;
    if (DAT_130b720ba92 != '\0') {
      uVar6 = 0x192;
    }
    FUN_130b71d0a30(&local_90,0x130b72053c8,0,0x130b72089b8);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,2);
    FUN_130b71f8900(&local_90,(int)uVar5 + 1,iVar10 + 1,uVar6,uVar11,uVar9,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    iVar4 = (int)uVar5 + 10;
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0;
    if (DAT_130b720ba7e != '\0') {
      uVar6 = 0x17130c;
    }
    uVar3 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar3 = 0x180;
    }
    FUN_130b71d0a30(&local_90,0x130b7205408,0,0x130b72089c8);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,0x32);
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 9,uVar3,uVar11,uVar6,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar3 = 0x1d180f;
    uVar6 = 0;
    if (DAT_130b720ba7f != '\0') {
      uVar6 = uVar3;
    }
    uVar2 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar2 = 0x180;
    }
    FUN_130b71d0a30(&local_90,0x130b7205440,0,0x130b72089d8);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,0x38);
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 0x59,uVar2,uVar11,uVar6,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    if (DAT_130b720ba7f == '\0') {
      uVar3 = 0;
    }
    uVar6 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar6 = 0x180;
    }
    FUN_130b71d0a30(&local_90,0x130b7205470,0,0x130b72089e8);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,0x38);
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 0x97,uVar6,uVar11,uVar3,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0;
    if (DAT_130b720ba7e != '\0') {
      uVar6 = 0x17130c;
    }
    uVar3 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar3 = 0x180;
    }
    FUN_130b71d0a30(&local_90,0x130b72054a8,0,0x130b72089f8);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,0x4c);
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 0xea,uVar3,uVar11,uVar6,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0;
    if (DAT_130b720ba7e != '\0') {
      uVar6 = 0x17130c;
    }
    uVar3 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar3 = 0x180;
    }
    FUN_130b71d0a30(&local_90,0x130b72054e0,0,0x130b7208a08);
    uVar13 = CONCAT44(uVar7,uVar9);
    uVar11 = CONCAT44(uVar14,0x34);
    local_44 = iVar4;
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 0x152,uVar3,uVar11,uVar6,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0x17130c;
    if (DAT_130b720ba7e == '\0') {
      uVar6 = 0;
    }
    uVar3 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar3 = 0x180;
    }
    local_60 = uVar1;
    FUN_130b71d0a30(&local_90,0x130b7205510,0,0x130b7208a18);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x38);
    FUN_130b71f8900(&local_90,iVar4,iVar10 + 0x1a2,uVar3,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    iVar4 = (int)local_80;
    uVar6 = 0;
    if (DAT_130b720ba8d != '\0') {
      uVar6 = 0x28340e;
    }
    FUN_130b71d0a30(&local_90,0x130b7205548,0,0x130b7208a28);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x16);
    FUN_130b71f8900(&local_90,iVar4 + 0x10c,iVar10 + 0x13,0x52,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0xff7089;
    if (DAT_130b720ba84 == '\0') {
      uVar9 = 0;
    }
    local_74 = iVar4 + 0x10;
    FUN_130b71d0a30(&local_90,0x130b7205580,0,0x130b7208a38);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x1b);
    FUN_130b71f8900(&local_90,iVar4 + 0x10,iVar10 + 0x13,3,uVar1,uVar9,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    iVar10 = (int)local_60;
    iVar8 = iVar10 + 0x62;
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0;
    if (DAT_130b720ba8d != '\0') {
      uVar6 = 0x28340e;
    }
    FUN_130b71d0a30(&local_90,0x130b72055b8,0,0x130b7208a48);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x14);
    FUN_130b71f8900(&local_90,iVar4 + 0x54,iVar8,0x52,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar3 = 0x231d12;
    uVar6 = 0;
    if (DAT_130b720ba80 != '\0') {
      uVar6 = 0x231d12;
    }
    FUN_130b71d0a30(&local_90,0x130b72055f8,0,0x130b7208a58);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x14);
    FUN_130b71f8900(&local_90,iVar4 + 0x100,iVar8,0x80,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    iVar10 = iVar10 + 0xa0;
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    uVar6 = 0;
    if (DAT_130b720ba8d != '\0') {
      uVar6 = 0x28340e;
    }
    FUN_130b71d0a30(&local_90,0x130b7205638,0,0x130b7208a68);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x14);
    FUN_130b71f8900(&local_90,iVar4 + 0x54,iVar10,0x52,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    if (DAT_130b720ba80 == '\0') {
      uVar3 = 0;
    }
    FUN_130b71d0a30(&local_90,0x130b7205678,0,0x130b7208a78);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x14);
    FUN_130b71f8900(&local_90,iVar4 + 0x100,iVar10,0x80,uVar1,uVar3,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0;
    if (DAT_130b720ba82 != '\0') {
      uVar9 = 0x221e12;
    }
    iVar4 = (int)local_60;
    iVar10 = (int)local_80;
    iVar8 = iVar10 + 0x10a;
    uVar3 = 0x28340e;
    uVar6 = 0;
    if (DAT_130b720ba8d != '\0') {
      uVar6 = 0x28340e;
    }
    FUN_130b71d0a30(&local_90,0x130b72056b0,0,0x130b7208a88);
    uVar11 = CONCAT44(uVar7,uVar9);
    uVar1 = CONCAT44(uVar14,0x12);
    FUN_130b71f8900(&local_90,iVar8,iVar4 + 0x1ac,0x6c,uVar1,uVar6,uVar11);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = 0x221e12;
    if (DAT_130b720ba82 == '\0') {
      uVar9 = 0;
    }
    if (DAT_130b720ba8d == '\0') {
      uVar3 = 0;
    }
    FUN_130b71d0a30(&local_90,0x130b72056e0,0,0x130b7208a98);
    uVar1 = CONCAT44(uVar14,0x12);
    FUN_130b71f8900(&local_90,iVar8,iVar4 + 0x1c3,0x6c,uVar1,uVar3,CONCAT44(uVar7,uVar9));
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208aa8);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7205748,0,0x130b7208ab8);
    iVar10 = iVar10 + 0x1b;
    FUN_130b71d0a30(&local_58,0x130b7205708,0,0x130b7208ac8);
    uVar1 = CONCAT44(uVar14,0xd);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x11,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208ad8);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b72057c8,0,0x130b7208ae8);
    FUN_130b71d0a30(&local_58,0x130b7205780,0,0x130b7208af8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x27,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7205870,0,0x130b7208b08);
    uVar9 = 0;
    if (DAT_130b720ba87 != '\0') {
      uVar9 = 0x96e24d;
    }
    FUN_130b71d0a30(&local_70,0x130b7205828,0,0x130b7208b18);
    iVar10 = (int)local_80;
    FUN_130b71d0a30(&local_58,0x130b7205808,0,0x130b7208b28);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar10 + 0x116,iVar4 + 0x17,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208b38);
    uVar9 = 0;
    if (DAT_130b720ba87 != '\0') {
      uVar9 = 0x96e24d;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208b48);
    FUN_130b71d0a30(&local_58,0x130b72058a0,0,0x130b7208b58);
    puVar12 = &local_90;
    FUN_130b71f8280(&local_58,iVar10 + 0x124,iVar4 + 0x16,&local_70,CONCAT44(uVar14,8),uVar9,
                    &local_90);
    uVar14 = (undefined4)((ulonglong)puVar12 >> 0x20);
    uVar9 = 0x1e1910;
    if (DAT_130b720ba8a == '\0') {
      uVar9 = 0;
    }
    uVar7 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar7 = 0x99917e;
    }
    FUN_130b71d0a30(&local_90,0x130b72058e8,0,0x130b7208b68);
    FUN_130b71d0a30(&local_70,0x130b72058c8,0,0x130b7208b78);
    puVar12 = &local_90;
    FUN_130b71f8570(&local_70,iVar10 + 0x16c,iVar4 + 0x12,0x1b,&local_90,10,CONCAT44(uVar14,uVar7),
                    uVar9);
    uVar14 = (undefined4)((ulonglong)puVar12 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208b88);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    FUN_130b71d0a30(&local_70,0x130b7205958,0,0x130b7208b98);
    iVar4 = (int)local_60;
    FUN_130b71d0a30(&local_58,0x130b7205920,0,0x130b7208ba8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,local_74,iVar4 + 0x46,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208bb8);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b72059c0,0,0x130b7208bc8);
    iVar10 = (int)local_80;
    iVar8 = iVar10 + 0x14;
    FUN_130b71d0a30(&local_58,0x130b7205990,0,0x130b7208bd8);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x65,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208be8);
    uVar9 = 0;
    if (DAT_130b720ba87 != '\0') {
      uVar9 = 0x96e24d;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208bf8);
    FUN_130b71d0a30(&local_58,0x130b72059f0,0,0x130b7208c08);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar10 + 99,iVar4 + 0x66,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208c18);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208c28);
    local_48 = iVar10 + 0x10b;
    FUN_130b71d0a30(&local_58,0x130b7205a20,0,0x130b7208c38);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar10 + 0x10b,iVar4 + 0x66,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208c48);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208c58);
    iVar4 = (int)local_60;
    FUN_130b71d0a30(&local_58,0x130b7205a50,0,0x130b7208c68);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x7c,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208c78);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7205ab0,0,0x130b7208c88);
    FUN_130b71d0a30(&local_58,0x130b7205a80,0,0x130b7208c98);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0xa3,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208ca8);
    uVar9 = 0;
    if (DAT_130b720ba87 != '\0') {
      uVar9 = 0x96e24d;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208cb8);
    FUN_130b71d0a30(&local_58,0x130b7205ae0,0,0x130b7208cc8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar10 + 99,iVar4 + 0xa4,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208cd8);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208ce8);
    FUN_130b71d0a30(&local_58,0x130b7205b10,0,0x130b7208cf8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,local_48,iVar4 + 0xa4,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208d08);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208d18);
    iVar4 = (int)local_60;
    FUN_130b71d0a30(&local_58,0x130b7205b40,0,0x130b7208d28);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0xba,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208d38);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    FUN_130b71d0a30(&local_70,0x130b7205bb0,0,0x130b7208d48);
    FUN_130b71d0a30(&local_58,0x130b7205b78,0,0x130b7208d58);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,local_74,iVar4 + 0xd8,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208d68);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205c10,0,0x130b7208d78);
    FUN_130b71d0a30(&local_58,0x130b7205bd8,0,0x130b7208d88);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0xf6,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208d98);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208da8);
    iVar10 = (int)local_80 + 0xee;
    FUN_130b71d0a30(&local_58,0x130b7205c38,0,0x130b7208db8);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0xf5,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208dc8);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205ca0,0,0x130b7208dd8);
    FUN_130b71d0a30(&local_58,0x130b7205c68,0,0x130b7208de8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x10c,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208df8);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208e08);
    FUN_130b71d0a30(&local_58,0x130b7205cc8,0,0x130b7208e18);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x10b,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208e28);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205d38,0,0x130b7208e38);
    FUN_130b71d0a30(&local_58,0x130b7205d00,0,0x130b7208e48);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x122,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208e58);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208e68);
    FUN_130b71d0a30(&local_58,0x130b7205d70,0,0x130b7208e78);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x121,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208e88);
    uVar9 = 0;
    if (DAT_130b720ba83 != '\0') {
      uVar9 = 0xcedc4a;
    }
    FUN_130b71d0a30(&local_70,0x130b7205dd0,0,0x130b7208e98);
    FUN_130b71d0a30(&local_58,0x130b7205da0,0,0x130b7208ea8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,local_74,iVar4 + 0x140,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208eb8);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205e30,0,0x130b7208ec8);
    FUN_130b71d0a30(&local_58,0x130b7205e00,0,0x130b7208ed8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x15e,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208ee8);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208ef8);
    FUN_130b71d0a30(&local_58,0x130b7205e60,0,0x130b7208f08);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x15d,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208f18);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205ec0,0,0x130b7208f28);
    FUN_130b71d0a30(&local_58,0x130b7205e90,0,0x130b7208f38);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x174,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208f48);
    uVar9 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar9 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208f58);
    FUN_130b71d0a30(&local_58,0x130b7205ef0,0,0x130b7208f68);
    uVar1 = CONCAT44(uVar14,9);
    FUN_130b71f8280(&local_58,iVar10,iVar4 + 0x173,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208f78);
    uVar9 = 0xcedc4a;
    if (DAT_130b720ba83 == '\0') {
      uVar9 = 0;
    }
    FUN_130b71d0a30(&local_70,0x130b7205f58,0,0x130b7208f88);
    FUN_130b71d0a30(&local_58,0x130b7205f20,0,0x130b7208f98);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,local_74,iVar4 + 400,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7208fa8);
    uVar9 = 0;
    if (DAT_130b720ba86 != '\0') {
      uVar9 = 0x99917e;
    }
    FUN_130b71d0a30(&local_70,0x130b7205fc8,0,0x130b7208fb8);
    FUN_130b71d0a30(&local_58,0x130b7205f90,0,0x130b7208fc8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x1b1,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7208fd8);
    uVar9 = 0;
    if (DAT_130b720ba87 != '\0') {
      uVar9 = 0x96e24d;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7208fe8);
    uVar5 = (ulonglong)((int)local_80 + 0x11c);
    local_80 = uVar5;
    FUN_130b71d0a30(&local_58,0x130b7206000,0,0x130b7208ff8);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,uVar5,iVar4 + 0x1af,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7201cd0,0,0x130b7209008);
    uVar9 = 0x99917e;
    if (DAT_130b720ba86 == '\0') {
      uVar9 = 0;
    }
    FUN_130b71d0a30(&local_70,0x130b7206078,0,0x130b7209018);
    FUN_130b71d0a30(&local_58,0x130b7206030,0,0x130b7209028);
    uVar1 = CONCAT44(uVar14,8);
    FUN_130b71f8280(&local_58,iVar8,iVar4 + 0x1c9,&local_70,uVar1,uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    FUN_130b71d0a30(&local_90,0x130b7204fa0,0,0x130b7209038);
    uVar9 = 0x96e24d;
    if (DAT_130b720ba87 == '\0') {
      uVar9 = 0;
    }
    FUN_130b71d0a30(&local_70,0x130b7201870,0,0x130b7209048);
    FUN_130b71d0a30(&local_58,0x130b72060b0,0,0x130b7209058);
    puVar12 = &local_90;
    FUN_130b71f8280(&local_58,local_80,iVar4 + 0x1c6,&local_70,CONCAT44(uVar14,8),uVar9,&local_90);
    uVar14 = (undefined4)((ulonglong)puVar12 >> 0x20);
    uVar9 = 0x262148;
    if (DAT_130b720ba8c == '\0') {
      uVar9 = 0;
    }
    uVar7 = 0;
    if (DAT_130b720ba85 != '\0') {
      uVar7 = 0xf4f2ec;
    }
    FUN_130b71d0a30(&local_90,0x130b7206110,0,0x130b7209068);
    uVar6 = 0xffffffec;
    if (DAT_130b720ba92 != '\0') {
      uVar6 = 0x180;
    }
    FUN_130b71d0a30(&local_70,0x130b72060e0,0,0x130b7209078);
    FUN_130b71f8570(&local_70,local_44,iVar4 + 0x1de,uVar6,&local_90,8,CONCAT44(uVar14,uVar7),uVar9)
    ;
  }
  FUN_130b71d0000(&local_90);
  FUN_130b71d0000(&local_70);
  FUN_130b71d0000(&local_58);
  return;
}



/* Address: 130b71fb750 */

void FUN_130b71fb750(void)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined8 in_stack_fffffffffffffd38;
  undefined4 local_2b0;
  undefined8 local_2ac;
  int local_2a4;
  undefined4 local_2a0;
  undefined8 local_29c;
  undefined8 local_290;
  undefined4 local_288;
  undefined4 local_280;
  undefined8 local_27c;
  undefined4 local_270;
  undefined8 local_26c;
  undefined1 local_260 [540];
  int iStack_44;
  
  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffd38 >> 0x20);
  local_2a0 = 0;
  local_2b0 = 0;
  local_29c = 0;
  local_2ac = 0;
  if (DAT_130b720bd58 != '\0') {
    puVar4 = local_260;
    uVar9 = 0xc;
    if (DAT_130b720ba90 == '\0') {
      uVar9 = 0;
    }
    uVar8 = 0x18;
    if (DAT_130b720ba91 == '\0') {
      uVar8 = 0;
    }
    (*(code *)0x7ff63a3fa670)(puVar4,0x130b7209090,0x21c);
    uVar5 = 0xfffffffa;
    if (DAT_130b720ba92 != '\0') {
      uVar5 = 0x18e;
    }
    if (DAT_130b720ba6f == '\0') {
      uVar10 = 0x1fe;
      uVar12 = 0;
      if (DAT_130b720ba93 != '\0') {
        uVar12 = uVar10;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205360,0,0x130b7209320);
      uVar11 = CONCAT44(uVar6,uVar12);
      FUN_130b71f9260(&local_2b0,uVar9 + 3,uVar8 + 4,uVar5,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      if (DAT_130b720ba93 == '\0') {
        uVar10 = 0;
      }
      uVar5 = 0x194;
      if (DAT_130b720ba92 == '\0') {
        uVar5 = 0;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205388,0,0x130b7209330);
      uVar11 = CONCAT44(uVar6,uVar10);
      FUN_130b71f9260(&local_2b0,uVar9,uVar8,uVar5,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xfffffffe;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x192;
      }
      FUN_130b71d0a30(&local_2b0,0x130b72053c8,0,0x130b7209340);
      uVar11 = CONCAT44(uVar5,2);
      FUN_130b71f9260(&local_2b0,uVar9 | 1,uVar8 | 1,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      iVar3 = uVar9 + 10;
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205408,0,0x130b7209350);
      uVar11 = CONCAT44(uVar5,0x32);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 9,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205440,0,0x130b7209360);
      uVar11 = CONCAT44(uVar5,0x38);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x59,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205470,0,0x130b7209370);
      uVar11 = CONCAT44(uVar5,0x38);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x97,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b72054a8,0,0x130b7209380);
      uVar11 = CONCAT44(uVar5,0x4c);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0xea,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b72054e0,0,0x130b7209390);
      uVar11 = CONCAT44(uVar5,0x34);
      local_2a4 = iVar3;
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x152,uVar6,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205510,0,0x130b72093a0);
      uVar11 = CONCAT44(uVar5,0x38);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 | 0x1a2,uVar6,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205548,0,0x130b72093b0);
      uVar11 = CONCAT44(uVar6,0x16);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x10c,uVar8 + 0x13,0x52,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      iVar14 = uVar9 + 0x10;
      FUN_130b71d0a30(&local_2b0,0x130b7205580,0,0x130b72093c0);
      uVar11 = CONCAT44(uVar6,0x1b);
      FUN_130b71f9260(&local_2b0,iVar14,uVar8 + 0x13,3,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72055b8,0,0x130b72093d0);
      uVar11 = CONCAT44(uVar6,0x14);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x54,uVar8 | 0x62,0x52,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72055f8,0,0x130b72093e0);
      uVar11 = CONCAT44(uVar6,0x14);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x100,uVar8 | 0x62,0x80,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205638,0,0x130b72093f0);
      uVar11 = CONCAT44(uVar6,0x14);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x54,uVar8 + 0xa0,0x52,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205678,0,0x130b7209400);
      uVar11 = CONCAT44(uVar6,0x14);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x100,uVar8 + 0xa0,0x80,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72056b0,0,0x130b7209410);
      uVar11 = CONCAT44(uVar6,0x12);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x10a,uVar8 + 0x1ac,0x6c,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72056e0,0,0x130b7209420);
      uVar11 = CONCAT44(uVar6,0x12);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x10a,uVar8 | 0x1c3,0x6c,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205708,0,0x130b7209430);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x1b,uVar8 + 0x11,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205780,0,0x130b7209440);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x1b,uVar8 | 0x27,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205808,0,0x130b7209450);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x116,uVar8 + 0x17,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72058a0,0,0x130b7209460);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x124,uVar8 + 0x16,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72058c8,0,0x130b7209470);
      uVar11 = CONCAT44(uVar6,0x18);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x16c,uVar8 + 0x12,0x1b,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205920,0,0x130b7209480);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar14,uVar8 | 0x46,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      iVar3 = uVar9 + 0x14;
      FUN_130b71d0a30(&local_2b0,0x130b7205990,0,0x130b7209490);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 | 0x65,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72059f0,0,0x130b72094a0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 | 99,uVar8 | 0x66,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205a20,0,0x130b72094b0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x10b,uVar8 | 0x66,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205a50,0,0x130b72094c0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x7c,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205a80,0,0x130b72094d0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 | 0xa3,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205ae0,0,0x130b72094e0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 | 99,uVar8 | 0xa4,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205b10,0,0x130b72094f0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x10b,uVar8 | 0xa4,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205b40,0,0x130b7209500);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0xba,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205b78,0,0x130b7209510);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar14,uVar8 + 0xd8,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205bd8,0,0x130b7209520);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0xf6,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      iVar13 = uVar9 + 0xee;
      FUN_130b71d0a30(&local_2b0,0x130b7205c38,0,0x130b7209530);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar13,uVar8 + 0xf5,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205c68,0,0x130b7209540);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x10c,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205cc8,0,0x130b7209550);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar13,uVar8 + 0x10b,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205d00,0,0x130b7209560);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 | 0x122,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205d70,0,0x130b7209570);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar13,uVar8 | 0x121,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205da0,0,0x130b7209580);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar14,uVar8 + 0x140,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205e00,0,0x130b7209590);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x15e,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205e60,0,0x130b72095a0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar13,uVar8 + 0x15d,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205e90,0,0x130b72095b0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x174,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205ef0,0,0x130b72095c0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar13,uVar8 + 0x173,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205f20,0,0x130b72095d0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar14,uVar8 + 400,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205f90,0,0x130b72095e0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x1b1,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7206000,0,0x130b72095f0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x11c,uVar8 + 0x1af,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7206030,0,0x130b7209600);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,iVar3,uVar8 + 0x1c9,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72060b0,0,0x130b7209610);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x11c,uVar8 | 0x1c6,0xffffffff,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar6 = 0xffffffec;
      if (DAT_130b720ba92 != '\0') {
        uVar6 = 0x180;
      }
      FUN_130b71d0a30(&local_2b0,0x130b72060e0,0,0x130b7209620);
      FUN_130b71f9260(&local_2b0,local_2a4,uVar8 + 0x1de,uVar6,CONCAT44(uVar5,0x18));
      FUN_130b71d0a30(&local_2b0,0x130b72058e8,0,0x130b7209630);
      uVar11 = 0x130b7209640;
    }
    else {
      uVar10 = 0x30;
      uVar12 = 0;
      if (DAT_130b720ba94 != '\0') {
        uVar12 = uVar10;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205360,0,0x130b72092b0);
      uVar11 = CONCAT44(uVar6,uVar12);
      FUN_130b71f9260(&local_2b0,uVar9 + 3,uVar8 + 4,uVar5,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      if (DAT_130b720ba94 == '\0') {
        uVar10 = 0;
      }
      uVar5 = 0x194;
      if (DAT_130b720ba92 == '\0') {
        uVar5 = 0;
      }
      FUN_130b71d0a30(&local_2b0,0x130b7205388,0,0x130b72092c0);
      uVar11 = CONCAT44(uVar6,uVar10);
      FUN_130b71f9260(&local_2b0,uVar9,uVar8,uVar5,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b7205708,0,0x130b72092d0);
      uVar11 = CONCAT44(uVar6,0xffffffff);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x1b,uVar8 + 0x11,0xffffffff,uVar11);
      uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
      FUN_130b71d0a30(&local_2b0,0x130b72058c8,0,0x130b72092e0);
      FUN_130b71f9260(&local_2b0,uVar9 + 0x16c,uVar8 + 0xc,0x1b,CONCAT44(uVar6,0x18));
      lVar7 = 0x2d;
      do {
        FUN_130b71d0a30(&local_2b0,puVar4,0,0x130b72092f0);
        local_270 = 0;
        local_280 = 0;
        local_26c = 0;
        local_27c = 0;
        local_290 = 0;
        local_288 = 0;
        FUN_130b71d0a30(&local_280,&local_2b0,0,0x130b7208798);
        FUN_130b71f80a0(&local_280);
        FUN_130b71d0a30(&local_270,0x130b720bb3c,1,0x130b72087a8);
        FUN_130b71d0a30(&local_290,&local_270,0,0x130b72087b8);
        iVar3 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0);
        if (-1 < iVar3) {
          (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_290,0x3f4,5000);
          (*(code *)0x7ff63a0f3b30)(0x130b53f81d8,0,&local_290,0x3f5,5000);
        }
        FUN_130b71d0000(&local_290);
        FUN_130b71d0000(&local_280);
        FUN_130b71d0000(&local_270);
        puVar4 = puVar4 + 0xc;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      FUN_130b71d0a30(&local_2b0,0x130b7206130,0,0x130b7209300);
      uVar11 = 0x130b7209310;
    }
    FUN_130b71d0a30(&local_2a0,0x130b72058c8,0,uVar11);
    FUN_130b71f8c30(&local_2a0,&local_2b0);
    lVar7 = -0x21c;
    do {
      if ((((*(int *)((longlong)&iStack_44 + lVar7) != 0) &&
           (lVar2 = *(longlong *)(&stack0xffffffffffffffc0 + lVar7), lVar2 != 0)) &&
          ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
        piVar1 = (int *)(lVar2 + -8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(code *)0x7ff63a101200)(0x130b53f81d8);
        }
      }
      *(undefined8 *)(&stack0xffffffffffffffc0 + lVar7) = 0;
      *(undefined4 *)((longlong)&iStack_44 + lVar7) = 0;
      lVar7 = lVar7 + 0xc;
    } while (lVar7 != 0);
  }
  FUN_130b71d0000(&local_2b0);
  FUN_130b71d0000(&local_2a0);
  return;
}



/* Address: 130b71fc9d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_130b71fc9d0(void)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined4 uVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  bool bVar23;
  double dVar24;
  undefined4 local_198;
  longlong local_194;
  char local_18a;
  char local_189;
  undefined4 local_188;
  longlong local_184;
  char local_17b;
  char local_17a;
  char local_179;
  undefined4 local_178;
  longlong local_174;
  undefined4 local_16c;
  undefined4 local_168;
  undefined8 local_164;
  undefined4 local_158;
  longlong local_154;
  undefined4 local_148;
  longlong local_144;
  undefined4 local_138;
  undefined8 local_134;
  undefined4 local_128;
  longlong local_124;
  undefined4 local_118;
  longlong local_114;
  undefined4 local_10c;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  undefined8 local_94;
  
  local_98 = 0;
  local_128 = 0;
  local_178 = 0;
  local_198 = 0;
  local_188 = 0;
  local_138 = 0;
  local_b8 = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_118 = 0;
  local_e8 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_148 = 0;
  local_158 = 0;
  local_94 = 0;
  local_124 = 0;
  local_174 = 0;
  local_194 = 0;
  local_184 = 0;
  local_134 = 0;
  local_b4 = 0;
  local_c4 = 0;
  local_d4 = 0;
  local_114 = 0;
  local_e4 = 0;
  local_f4 = 0;
  local_104 = 0;
  local_144 = 0;
  local_154 = 0;
  if (DAT_130b720bd58 == '\0') goto LAB_130b71ff278;
  FUN_130b71d0a30(&local_188,0x130b7205388,0,0x130b7209650);
  FUN_130b71f80a0(&local_188);
  FUN_130b71d0a30(&local_198,0x130b720bb3c,1,0x130b7209660);
  iVar8 = (*(code *)0x7ff63a0f4840)(0x130b53f81d8,0,&local_198);
  if (iVar8 < 0) {
    FUN_130b71f97d0();
    FUN_130b71fb750();
  }
  iVar8 = _DAT_130b720ba68;
  local_18a = DAT_130b720bd48;
  if (DAT_130b720bd48 == '\0') {
    if (0 < _DAT_130b720ba68) {
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
    }
LAB_130b71fcd15:
    uVar13 = 0x130b7205260;
    local_138 = 0;
    local_134 = 0;
    if (DAT_130b720ba6e == '\0') {
      uVar13 = 0x130b7206190;
    }
    FUN_130b71d0a30(&local_138,uVar13,0,0x130b7209670);
    uVar13 = 0x6f68ff;
    if (DAT_130b720ba88 == '\0') {
      uVar13 = 0;
    }
    local_10c = 0x96e24d;
    if (DAT_130b720ba87 == '\0') {
      local_10c = 0;
    }
    if (DAT_130b720ba6e != '\0') {
      local_10c = (int)uVar13;
    }
    local_16c = (undefined4)CONCAT71((int7)((ulonglong)uVar13 >> 8),1);
  }
  else {
    if (_DAT_130b720ba68 < 1) goto LAB_130b71fcd15;
    iVar9 = FUN_130b71efc10();
    iVar4 = _DAT_130b720ba68;
    if (iVar8 != iVar9) {
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
      if (0 < iVar4) {
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d08);
      }
      goto LAB_130b71fcd15;
    }
    local_138 = 0;
    local_134 = 0;
    FUN_130b71d0a30(&local_138,0x130b7206160,0,0x130b7209670);
    local_16c = 0;
    local_10c = 0x58bef4;
    if (DAT_130b720ba89 == '\0') {
      local_10c = 0;
    }
  }
  uVar13 = 0x130b72061c0;
  local_b8 = 0;
  local_b4 = 0;
  if (DAT_130b720ba6e == '\0') {
    uVar13 = 0x130b7206110;
  }
  FUN_130b71d0a30(&local_b8,uVar13,0,0x130b7209680);
  local_c8 = 0;
  local_c4 = 0;
  uVar10 = 0x314212;
  if (DAT_130b720ba8b == '\0') {
    uVar10 = 0;
  }
  local_a8 = 0x262148;
  if (DAT_130b720ba8c == '\0') {
    local_a8 = 0;
  }
  if (DAT_130b720ba6e != '\0') {
    local_a8 = uVar10;
  }
  local_179 = DAT_130b720bc18;
  FUN_130b71f9670();
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209690);
  FUN_130b71d0a30(&local_c8,&local_188,0,0x130b72096a0);
  local_d8 = 0;
  local_d4 = 0;
  local_189 = DAT_130b720bca0;
  FUN_130b71f9670();
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b72096b0);
  FUN_130b71d0a30(&local_d8,&local_188,0,0x130b72096c0);
  uVar10 = _DAT_130b720bc30;
  FUN_130b71d0a30(&local_188,0x130b720bb28,1,0x130b72096d0);
  local_9c = FUN_130b71efd10(&local_188,uVar10);
  local_a0 = FUN_130b71e0270();
  (*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x25);
  dVar5 = _DAT_130b720bb48;
  (*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x28);
  dVar6 = _DAT_130b720bb48;
  dVar24 = _DAT_130b720bb48 - dVar5;
  (*(code *)0x7ff63a0c7370)(0x130b53f81d8,0x26);
  dVar24 = dVar24 - _DAT_130b720bb48;
  local_118 = 0;
  local_114 = 0;
  dVar24 = (double)(~-(ulonglong)((double)(_DAT_130b72016f0 & (ulonglong)dVar24) < _DAT_130b7201700)
                   & (ulonglong)dVar24);
  (*(code *)0x7ff63a0c7410)(0x130b53f81d8,0x24);
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b72096e0);
  FUN_130b71d0a30(&local_118,&local_188,0,0x130b72096f0);
  uVar13 = 0x130b7201870;
  local_e8 = 0;
  local_e4 = 0;
  if (0.0 < dVar24) {
    uVar13 = 0x130b7206130;
  }
  FUN_130b71d0a30(&local_e8,uVar13,0,0x130b7209700);
  local_f8 = 0;
  local_168 = 0;
  local_f4 = 0;
  local_164 = 0;
  uVar10 = 0xf4f2ec;
  if (DAT_130b720ba85 == '\0') {
    uVar10 = 0;
  }
  uVar16 = 0x96e24d;
  if (DAT_130b720ba87 == '\0') {
    uVar16 = 0;
  }
  if (dVar24 <= 0.0) {
    uVar16 = uVar10;
  }
  uVar10 = 0x6f68ff;
  if (DAT_130b720ba88 == '\0') {
    uVar10 = 0;
  }
  if (0.0 <= dVar24) {
    uVar10 = uVar16;
  }
  bVar23 = DAT_130b720bd28 == '\0' && DAT_130b720bd30 == '\0';
  if (DAT_130b720bd28 == '\0' && DAT_130b720bd30 == '\0') {
    uVar13 = 0x130b72052b8;
    uVar21 = 0x130b7208918;
  }
  else {
    cVar7 = FUN_130b71e6fc0();
    if (cVar7 == '\0') {
      uVar13 = 0x130b7205290;
      uVar21 = 0x130b7208938;
    }
    else {
      uVar13 = 0x130b72052f8;
      uVar21 = 0x130b7208928;
    }
  }
  FUN_130b71d0a30(&local_168,uVar13,0,uVar21);
  FUN_130b71d0a30(0x130b720bb3c,&local_168,1,0x130b7208948);
  FUN_130b71d0000(&local_168);
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209710);
  FUN_130b71d0a30(&local_f8,&local_188,0,0x130b7209720);
  local_108 = 0;
  local_168 = 0;
  local_104 = 0;
  local_164 = 0;
  local_17a = DAT_130b720bd50;
  local_17b = bVar23;
  local_a4 = uVar10;
  if (DAT_130b720bd50 == '\0') {
    uVar13 = 0x130b72052b8;
    uVar21 = 0x130b7208958;
  }
  else {
    cVar7 = FUN_130b71eb190();
    if (cVar7 == '\0') {
      uVar13 = 0x130b7205290;
      uVar21 = 0x130b7208978;
    }
    else {
      uVar13 = 0x130b7205330;
      uVar21 = 0x130b7208968;
    }
  }
  FUN_130b71d0a30(&local_168,uVar13,0,uVar21);
  FUN_130b71d0a30(0x130b720bb3c,&local_168,1,0x130b7208988);
  FUN_130b71d0000(&local_168);
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209730);
  FUN_130b71d0a30(&local_108,&local_188,0,0x130b7209740);
  FUN_130b71d0a30(&local_188,&local_138,0,0x130b7209750);
  FUN_130b71d0a30(&local_198,0x130b72058a0,0,0x130b7209760);
  FUN_130b71f8c30(&local_198,&local_188);
  FUN_130b71d0a30(&local_188,0x130b7205828,0,0x130b7209770);
  FUN_130b71d0a30(&local_198,0x130b7205808,0,0x130b7209780);
  FUN_130b71f8c30(&local_198,&local_188);
  FUN_130b71d0a30(&local_188,0x130b72058a0,0,0x130b7209790);
  uVar10 = local_10c;
  FUN_130b71f8e50(&local_188,local_10c);
  FUN_130b71d0a30(&local_188,0x130b7205808,0,0x130b72097a0);
  FUN_130b71f8e50(&local_188,uVar10);
  if ((char)local_16c == '\0') {
    uVar10 = 0;
    if (DAT_130b720ba8f != '\0') {
      uVar10 = 0x16303d;
    }
  }
  else {
    uVar16 = 0x201c3c;
    if (DAT_130b720ba8e == '\0') {
      uVar16 = 0;
    }
    uVar10 = 0x28340e;
    if (DAT_130b720ba8d == '\0') {
      uVar10 = 0;
    }
    if (DAT_130b720ba6e != '\0') {
      uVar10 = uVar16;
    }
  }
  FUN_130b71d0a30(&local_188,0x130b7205548,0,0x130b72097b0);
  FUN_130b71f8fa0(&local_188,uVar10);
  if ((char)local_16c == '\0') {
    uVar10 = 0;
    if (DAT_130b720ba89 != '\0') {
      uVar10 = 0x58bef4;
    }
  }
  else {
    uVar16 = 0x262148;
    if (DAT_130b720ba8c == '\0') {
      uVar16 = 0;
    }
    uVar10 = 0x302b19;
    if (DAT_130b720ba81 == '\0') {
      uVar10 = 0;
    }
    if (DAT_130b720ba6e != '\0') {
      uVar10 = uVar16;
    }
  }
  FUN_130b71d0a30(&local_188,0x130b7205548,0,0x130b72097c0);
  FUN_130b71f9100(&local_188,uVar10);
  FUN_130b71d0a30(&local_188,&local_c8,0,0x130b72097d0);
  FUN_130b71d0a30(&local_198,0x130b72059f0,0,0x130b72097e0);
  FUN_130b71f8c30(&local_198,&local_188);
  cVar7 = local_179;
  iVar8 = _DAT_130b720ba68;
  uVar10 = 0x6f68ff;
  if ((local_179 == '\0') || (DAT_130b720ba6e != '\0')) {
    pcVar11 = &DAT_130b720ba88;
  }
  else if (local_18a == '\0') {
    uVar10 = 0x96e24d;
    if (0 < _DAT_130b720ba68) {
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
    }
    pcVar11 = &DAT_130b720ba87;
  }
  else {
    if (0 < _DAT_130b720ba68) {
      iVar9 = FUN_130b71efc10();
      iVar4 = _DAT_130b720ba68;
      pcVar11 = &DAT_130b720ba88;
      if (iVar8 == iVar9) goto LAB_130b71fd62b;
      _DAT_130b720ba68 = -1;
      FUN_130b71f7b60();
      if (0 < iVar4) {
        (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d08);
      }
    }
    pcVar11 = &DAT_130b720ba87;
    uVar10 = 0x96e24d;
  }
LAB_130b71fd62b:
  if (*pcVar11 == '\0') {
    uVar10 = 0;
  }
  FUN_130b71d0a30(&local_188,0x130b72059f0,0,0x130b72097f0);
  FUN_130b71f8e50(&local_188,uVar10);
  uVar10 = 0x28340e;
  if (DAT_130b720ba8d == '\0') {
    uVar10 = 0;
  }
  uVar16 = 0x201c3c;
  if (DAT_130b720ba8e == '\0') {
    uVar16 = 0;
  }
  if (DAT_130b720ba6e != '\0') {
    uVar10 = uVar16;
  }
  if (cVar7 == '\0') {
    uVar10 = uVar16;
  }
  if ((char)local_16c == '\0') {
    uVar10 = uVar16;
  }
  FUN_130b71d0a30(&local_188,0x130b72055b8,0,0x130b7209800);
  FUN_130b71f8fa0(&local_188,uVar10);
  iVar8 = _DAT_130b720bc50;
  FUN_130b71f9410(_DAT_130b720bc50,_DAT_130b720bc58);
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209810);
  FUN_130b71d0a30(&local_198,0x130b7205a20,0,0x130b7209820);
  FUN_130b71f8c30(&local_198,&local_188);
  local_148 = 0;
  local_144 = 0;
  (*(code *)0x7ff63a0fdfe0)(0x130b53f81d8,(longlong)local_9c,0,0x20);
  FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209830);
  FUN_130b71d0a30(&local_198,0x130b7206200,0);
  lVar2 = local_184;
  if (local_184 == 0) {
LAB_130b71fd8bd:
    FUN_130b71d0a30(&local_148,&local_198,0,0x130b7209850);
    if (iVar8 != 1) goto LAB_130b71fdb5d;
    (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,_DAT_130b720bc68,2);
    FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209860);
    FUN_130b71d0a30(&local_198,0x130b7206238,0);
    lVar2 = local_184;
    if (local_184 == 0) {
LAB_130b71fda4d:
      if (local_194 != 0) {
LAB_130b71fda5b:
        lVar2 = local_194;
        uVar15 = *(uint *)(local_194 + -4);
        uVar17 = (ulonglong)uVar15;
        if ((uVar17 == 0) && (local_144 != 0)) goto LAB_130b71fdb5d;
        if (local_144 == 0) {
          uVar19 = 0;
          uVar18 = uVar15;
        }
        else {
          uVar19 = *(uint *)(local_144 + -4);
          uVar18 = uVar15 + uVar19;
        }
        cVar7 = FUN_130b71d0060(&local_148);
        if (cVar7 != '\0') {
          if (uVar17 != 0) {
            lVar1 = local_144 + (ulonglong)uVar19 * 2;
            if (uVar15 < 0x10) {
              uVar14 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fdb52;
            }
            do {
              *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fdb52:
          *(uint *)(local_144 + -4) = uVar18;
          *(undefined2 *)(local_144 + (ulonglong)uVar18 * 2) = 0;
          goto LAB_130b71fdb5d;
        }
        goto LAB_130b71ff43c;
      }
LAB_130b71fdb5d:
      FUN_130b71d0a30(&local_188,&local_148,0,0x130b7209880);
      FUN_130b71d0a30(&local_198,0x130b7205a50,0,0x130b7209890);
      FUN_130b71f8c30(&local_198,&local_188);
      FUN_130b71d0a30(&local_188,&local_d8,0,0x130b72098a0);
      FUN_130b71d0a30(&local_198,0x130b7205ae0,0,0x130b72098b0);
      FUN_130b71f8c30(&local_198,&local_188);
      iVar8 = _DAT_130b720ba68;
      uVar10 = 0x6f68ff;
      pcVar11 = &DAT_130b720ba88;
      if ((local_189 != '\0') && (DAT_130b720ba6e == '\0')) {
        if (local_18a == '\0') {
          uVar10 = 0x96e24d;
          pcVar11 = &DAT_130b720ba87;
          if (0 < _DAT_130b720ba68) {
            _DAT_130b720ba68 = -1;
            FUN_130b71f7b60();
          }
        }
        else {
          if (0 < _DAT_130b720ba68) {
            iVar9 = FUN_130b71efc10();
            iVar4 = _DAT_130b720ba68;
            if (iVar8 == iVar9) goto LAB_130b71fdce6;
            _DAT_130b720ba68 = -1;
            FUN_130b71f7b60();
            if (0 < iVar4) {
              (*(code *)0x7ff63a0e49f0)(0x130b53f81d8,2,1,0x590008,0x130b7204d08);
            }
          }
          pcVar11 = &DAT_130b720ba87;
          uVar10 = 0x96e24d;
        }
      }
LAB_130b71fdce6:
      if (*pcVar11 == '\0') {
        uVar10 = 0;
      }
      FUN_130b71d0a30(&local_188,0x130b7205ae0,0,0x130b72098c0);
      FUN_130b71f8e50(&local_188,uVar10);
      uVar10 = 0x28340e;
      if (DAT_130b720ba8d == '\0') {
        uVar10 = 0;
      }
      uVar16 = 0x201c3c;
      if (DAT_130b720ba8e == '\0') {
        uVar16 = 0;
      }
      if (DAT_130b720ba6e != '\0') {
        uVar10 = uVar16;
      }
      if (local_189 == '\0') {
        uVar10 = uVar16;
      }
      if ((char)local_16c == '\0') {
        uVar10 = uVar16;
      }
      FUN_130b71d0a30(&local_188,0x130b7205638,0,0x130b72098d0);
      FUN_130b71f8fa0(&local_188,uVar10);
      iVar8 = _DAT_130b720bcd0;
      FUN_130b71f9410(_DAT_130b720bcd0,_DAT_130b720bcd8);
      FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b72098e0);
      FUN_130b71d0a30(&local_198,0x130b7205b10,0,0x130b72098f0);
      FUN_130b71f8c30(&local_198,&local_188);
      local_158 = 0;
      local_154 = 0;
      (*(code *)0x7ff63a0fdfe0)(0x130b53f81d8,(longlong)local_a0,0,0x20);
      FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209900);
      FUN_130b71d0a30(&local_198,0x130b7206200,0);
      lVar2 = local_184;
      if (local_184 != 0) {
        uVar15 = *(uint *)(local_184 + -4);
        uVar17 = (ulonglong)uVar15;
        if ((uVar17 == 0) && (local_194 != 0)) goto LAB_130b71fdf6d;
        if (local_194 == 0) {
          uVar14 = 0;
          uVar19 = uVar15;
        }
        else {
          uVar14 = (ulonglong)*(uint *)(local_194 + -4);
          uVar19 = uVar15 + *(uint *)(local_194 + -4);
        }
        cVar7 = FUN_130b71d0060(&local_198);
        if (cVar7 != '\0') {
          if (uVar17 != 0) {
            lVar1 = local_194 + uVar14 * 2;
            if (uVar15 < 0x10) {
              uVar14 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fdf62;
            }
            do {
              *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fdf62:
          *(uint *)(local_194 + -4) = uVar19;
          *(undefined2 *)(local_194 + (ulonglong)uVar19 * 2) = 0;
          goto LAB_130b71fdf6d;
        }
        goto LAB_130b71ff39c;
      }
LAB_130b71fdf6d:
      FUN_130b71d0a30(&local_158,&local_198,0,0x130b7209920);
      pcVar11 = &DAT_130b720ba8f;
      if (iVar8 != 1) {
LAB_130b71fe20d:
        uVar14 = 0;
        FUN_130b71d0a30(&local_188,&local_158,0,0x130b7209950);
        FUN_130b71d0a30(&local_198,0x130b7205b40,0,0x130b7209960);
        FUN_130b71f8c30(&local_198,&local_188);
        (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,dVar5,2);
        FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209970);
        FUN_130b71d0a30(&local_198,&local_188,0);
        uVar15 = _DAT_130b72043d4;
        uVar17 = (ulonglong)_DAT_130b72043d4;
        if ((uVar17 != 0) || (local_194 == 0)) {
          if (local_194 != 0) {
            uVar14 = (ulonglong)*(uint *)(local_194 + -4);
          }
          uVar19 = _DAT_130b72043d4 + (int)uVar14;
          cVar7 = FUN_130b71d0060(&local_198);
          if (cVar7 != '\0') {
            if (uVar17 != 0) {
              lVar2 = local_194 + uVar14 * 2;
              if ((uVar15 < 0x10) || (lVar2 - 0x130b72043d8U < 0x20)) {
                uVar14 = 0;
              }
              else {
                uVar22 = 0;
                uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar13 = *(undefined8 *)(uVar22 + 0x130b72043e0);
                  *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(&DAT_130b72043d8 + uVar22);
                  ((undefined8 *)(lVar2 + uVar22))[1] = uVar13;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar14 == uVar17) goto LAB_130b71fe362;
              }
              do {
                *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(&DAT_130b72043d8 + uVar14 * 2)
                ;
                uVar14 = uVar14 + 1;
              } while (uVar17 != uVar14);
            }
LAB_130b71fe362:
            *(uint *)(local_194 + -4) = uVar19;
            *(undefined2 *)(local_194 + (ulonglong)uVar19 * 2) = 0;
            goto LAB_130b71fe36d;
          }
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2d1347000001f9);
LAB_130b71ff2fc:
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x2c1348000001f9);
LAB_130b71ff31c:
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x391349000001f9);
LAB_130b71ff33c:
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1b11e9000001f7);
LAB_130b71ff35c:
          (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x32134d000001f9);
          goto LAB_130b71ff37c;
        }
LAB_130b71fe36d:
        FUN_130b71d0a30(&local_178,&local_198,0);
        lVar2 = local_114;
        if (local_114 != 0) {
          uVar15 = *(uint *)(local_114 + -4);
          uVar17 = (ulonglong)uVar15;
          if ((uVar17 == 0) && (local_174 != 0)) goto LAB_130b71fe4e7;
          if (local_174 == 0) {
            uVar14 = 0;
            uVar19 = uVar15;
          }
          else {
            uVar14 = (ulonglong)*(uint *)(local_174 + -4);
            uVar19 = uVar15 + *(uint *)(local_174 + -4);
          }
          cVar7 = FUN_130b71d0060(&local_178);
          if (cVar7 != '\0') {
            if (uVar17 != 0) {
              lVar1 = local_174 + uVar14 * 2;
              if (uVar15 < 0x10) {
                uVar14 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
                uVar14 = 0;
              }
              else {
                uVar22 = 0;
                uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                  *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                  ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar14 == uVar17) goto LAB_130b71fe4d2;
              }
              do {
                *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
                uVar14 = uVar14 + 1;
              } while (uVar17 != uVar14);
            }
LAB_130b71fe4d2:
            *(uint *)(local_174 + -4) = uVar19;
            *(undefined2 *)(local_174 + (ulonglong)uVar19 * 2) = 0;
            goto LAB_130b71fe4e7;
          }
          goto LAB_130b71ff3bc;
        }
LAB_130b71fe4e7:
        uVar14 = 0;
        FUN_130b71d0a30(&local_128,0x130b7205c38,0,0x130b72099a0);
        FUN_130b71f8c30(&local_128,&local_178);
        (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,dVar6,2);
        FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b72099b0);
        FUN_130b71d0a30(&local_198,&local_188,0);
        uVar15 = _DAT_130b72043d4;
        uVar17 = (ulonglong)_DAT_130b72043d4;
        if ((uVar17 != 0) || (local_194 == 0)) {
          if (local_194 != 0) {
            uVar14 = (ulonglong)*(uint *)(local_194 + -4);
          }
          uVar19 = _DAT_130b72043d4 + (int)uVar14;
          cVar7 = FUN_130b71d0060(&local_198);
          if (cVar7 == '\0') goto LAB_130b71ff2fc;
          if (uVar17 != 0) {
            lVar2 = local_194 + uVar14 * 2;
            if ((uVar15 < 0x10) || (lVar2 - 0x130b72043d8U < 0x20)) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar13 = *(undefined8 *)(uVar22 + 0x130b72043e0);
                *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(&DAT_130b72043d8 + uVar22);
                ((undefined8 *)(lVar2 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fe622;
            }
            do {
              *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(&DAT_130b72043d8 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fe622:
          *(uint *)(local_194 + -4) = uVar19;
          *(undefined2 *)(local_194 + (ulonglong)uVar19 * 2) = 0;
        }
        FUN_130b71d0a30(&local_178,&local_198,0);
        lVar2 = local_114;
        if (local_114 != 0) {
          uVar15 = *(uint *)(local_114 + -4);
          uVar17 = (ulonglong)uVar15;
          if ((uVar17 == 0) && (local_174 != 0)) goto LAB_130b71fe7a7;
          if (local_174 == 0) {
            uVar14 = 0;
            uVar19 = uVar15;
          }
          else {
            uVar14 = (ulonglong)*(uint *)(local_174 + -4);
            uVar19 = uVar15 + *(uint *)(local_174 + -4);
          }
          cVar7 = FUN_130b71d0060(&local_178);
          if (cVar7 != '\0') {
            if (uVar17 != 0) {
              lVar1 = local_174 + uVar14 * 2;
              if (uVar15 < 0x10) {
                uVar14 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
                uVar14 = 0;
              }
              else {
                uVar22 = 0;
                uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                  *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                  ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar14 == uVar17) goto LAB_130b71fe792;
              }
              do {
                *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
                uVar14 = uVar14 + 1;
              } while (uVar17 != uVar14);
            }
LAB_130b71fe792:
            *(uint *)(local_174 + -4) = uVar19;
            *(undefined2 *)(local_174 + (ulonglong)uVar19 * 2) = 0;
            goto LAB_130b71fe7a7;
          }
          goto LAB_130b71ff3dc;
        }
LAB_130b71fe7a7:
        FUN_130b71d0a30(&local_128,0x130b7205cc8,0,0x130b72099e0);
        FUN_130b71f8c30(&local_128,&local_178);
        (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,dVar24,2);
        FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b72099f0);
        FUN_130b71d0a30(&local_198,&local_e8);
        lVar2 = local_184;
        if (local_184 != 0) {
          uVar15 = *(uint *)(local_184 + -4);
          uVar17 = (ulonglong)uVar15;
          if ((uVar17 == 0) && (local_194 != 0)) goto LAB_130b71fe937;
          if (local_194 == 0) {
            uVar19 = 0;
            uVar18 = uVar15;
          }
          else {
            uVar19 = *(uint *)(local_194 + -4);
            uVar18 = uVar15 + uVar19;
          }
          cVar7 = FUN_130b71d0060(&local_198);
          if (cVar7 != '\0') {
            if (uVar17 != 0) {
              lVar1 = local_194 + (ulonglong)uVar19 * 2;
              if (uVar15 < 0x10) {
                uVar14 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
                uVar14 = 0;
              }
              else {
                uVar22 = 0;
                uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                  *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                  ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar14 == uVar17) goto LAB_130b71fe922;
              }
              do {
                *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
                uVar14 = uVar14 + 1;
              } while (uVar17 != uVar14);
            }
LAB_130b71fe922:
            *(uint *)(local_194 + -4) = uVar18;
            *(undefined2 *)(local_194 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_130b71fe937;
          }
          goto LAB_130b71ff3fc;
        }
LAB_130b71fe937:
        uVar15 = 0;
        FUN_130b71d0a30(&local_178,&local_198,0,0x130b7209a10);
        uVar19 = _DAT_130b72043d4;
        uVar17 = (ulonglong)_DAT_130b72043d4;
        if ((uVar17 != 0) || (local_174 == 0)) {
          if (local_174 != 0) {
            uVar15 = *(uint *)(local_174 + -4);
          }
          uVar20 = _DAT_130b72043d4 + uVar15;
          uVar18 = 0x104;
          if ((0x103 < uVar20) &&
             ((0x7ffffffd < uVar20 || (uVar18 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar18)))) {
            uVar18 = 0x7ffffffe;
          }
          cVar7 = FUN_130b71d0060(&local_178,uVar18);
          if (cVar7 == '\0') goto LAB_130b71ff31c;
          if (uVar17 != 0) {
            lVar2 = local_174 + (ulonglong)uVar15 * 2;
            if (uVar19 < 0x10) {
              uVar14 = 0;
            }
            else if (lVar2 - 0x130b72043d8U < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar19 & 0xfffffff8);
              do {
                uVar13 = *(undefined8 *)(uVar22 + 0x130b72043e0);
                *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(&DAT_130b72043d8 + uVar22);
                ((undefined8 *)(lVar2 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fea52;
            }
            do {
              *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(&DAT_130b72043d8 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fea52:
          *(uint *)(local_174 + -4) = uVar20;
          *(undefined2 *)(local_174 + (ulonglong)uVar20 * 2) = 0;
        }
        FUN_130b71d0a30(&local_128,&local_178,0);
        lVar2 = local_114;
        if (local_114 != 0) {
          uVar15 = *(uint *)(local_114 + -4);
          uVar17 = (ulonglong)uVar15;
          if ((uVar17 == 0) && (local_124 != 0)) goto LAB_130b71feb97;
          if (local_124 == 0) {
            uVar19 = 0;
            uVar18 = uVar15;
          }
          else {
            uVar19 = *(uint *)(local_124 + -4);
            uVar18 = uVar15 + uVar19;
          }
          cVar7 = FUN_130b71d0060(&local_128);
          if (cVar7 != '\0') {
            if (uVar17 != 0) {
              lVar1 = local_124 + (ulonglong)uVar19 * 2;
              if (uVar15 < 0x10) {
                uVar14 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
                uVar14 = 0;
              }
              else {
                uVar22 = 0;
                uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                  *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                  ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar14 == uVar17) goto LAB_130b71feb82;
              }
              do {
                *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
                uVar14 = uVar14 + 1;
              } while (uVar17 != uVar14);
            }
LAB_130b71feb82:
            *(uint *)(local_124 + -4) = uVar18;
            *(undefined2 *)(local_124 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_130b71feb97;
          }
          goto LAB_130b71ff41c;
        }
LAB_130b71feb97:
        FUN_130b71d0a30(&local_98,0x130b7205d70,0,0x130b7209a30);
        FUN_130b71f8c30(&local_98,&local_128);
        FUN_130b71d0a30(&local_188,0x130b7205d70,0,0x130b7209a40);
        FUN_130b71f8e50(&local_188,local_a4);
        FUN_130b71d0a30(&local_188,0x130b720bb28,1,0x130b7209a50);
        FUN_130b71d0a30(&local_198,0x130b7205e60,0,0x130b7209a60);
        FUN_130b71f8c30(&local_198,&local_188);
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,4);
        dVar5 = _DAT_130b720bb48;
        (*(code *)0x7ff63a0f2890)(0x130b53f81d8,0x130b7201850,1);
        dVar24 = 0.0;
        if ((0.0 < dVar5) && (0.0 < _DAT_130b720bb48)) {
          if ((_DAT_130b720bb18 == 0.0) && (!NAN(_DAT_130b720bb18))) goto LAB_130b71ff33c;
          dVar24 = (dVar5 - _DAT_130b720bb48) / _DAT_130b720bb18;
        }
        (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,dVar24,1);
        FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209a70);
        uVar15 = 0;
        FUN_130b71d0a30(&local_198,&local_188,0,0x130b7209a80);
        uVar19 = _DAT_130b7206258;
        uVar17 = (ulonglong)_DAT_130b7206258;
        if ((uVar17 != 0) || (local_194 == 0)) {
          if (local_194 != 0) {
            uVar15 = *(uint *)(local_194 + -4);
          }
          uVar20 = _DAT_130b7206258 + uVar15;
          uVar18 = 0x104;
          if ((0x103 < uVar20) &&
             ((0x7ffffffd < uVar20 || (uVar18 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar18)))) {
            uVar18 = 0x7ffffffe;
          }
          cVar7 = FUN_130b71d0060(&local_198,uVar18);
          if (cVar7 == '\0') goto LAB_130b71ff35c;
          if (uVar17 != 0) {
            lVar2 = local_194 + (ulonglong)uVar15 * 2;
            if (uVar19 < 0x10) {
              uVar14 = 0;
            }
            else if (lVar2 - 0x130b720625cU < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar19 & 0xfffffff8);
              do {
                uVar13 = *(undefined8 *)(uVar22 + 0x130b7206264);
                *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(&DAT_130b720625c + uVar22);
                ((undefined8 *)(lVar2 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fee12;
            }
            do {
              *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(&DAT_130b720625c + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fee12:
          *(uint *)(local_194 + -4) = uVar20;
          *(undefined2 *)(local_194 + (ulonglong)uVar20 * 2) = 0;
        }
        FUN_130b71d0a30(&local_178,0x130b7205ef0,0,0x130b7209a90);
        FUN_130b71f8c30(&local_178,&local_198);
        FUN_130b71d0a30(&local_188,&local_f8,0,0x130b7209aa0);
        FUN_130b71d0a30(&local_198,0x130b7206000,0,0x130b7209ab0);
        FUN_130b71f8c30(&local_198,&local_188);
        if (local_17b == '\0') {
          cVar7 = FUN_130b71e6fc0();
          pcVar12 = &DAT_130b720ba89;
          if (cVar7 == '\0') {
            pcVar12 = &DAT_130b720ba87;
          }
          uVar10 = 0x58bef4;
          if (cVar7 == '\0') {
            uVar10 = 0x96e24d;
          }
          if (*pcVar12 == '\0') {
            uVar10 = 0;
          }
          FUN_130b71d0a30(&local_188,0x130b7206000,0,0x130b7209ac0);
          FUN_130b71f8e50(&local_188,uVar10);
          cVar7 = FUN_130b71e6fc0();
          pcVar12 = &DAT_130b720ba8f;
          if (cVar7 == '\0') {
            pcVar12 = &DAT_130b720ba8d;
          }
          uVar10 = 0x16303d;
          if (cVar7 == '\0') {
            uVar10 = 0x28340e;
          }
        }
        else {
          uVar10 = 0x6f68ff;
          if (DAT_130b720ba88 == '\0') {
            uVar10 = 0;
          }
          FUN_130b71d0a30(&local_188,0x130b7206000,0,0x130b7209ac0);
          FUN_130b71f8e50(&local_188,uVar10);
          pcVar12 = &DAT_130b720ba8e;
          uVar10 = 0x201c3c;
        }
        uVar16 = 0;
        if (*pcVar12 == '\0') {
          uVar10 = uVar16;
        }
        FUN_130b71d0a30(&local_188,0x130b72056b0,0,0x130b7209ad0);
        FUN_130b71f8fa0(&local_188,uVar10);
        FUN_130b71d0a30(&local_188,&local_108,0,0x130b7209ae0);
        FUN_130b71d0a30(&local_198,0x130b72060b0,0,0x130b7209af0);
        FUN_130b71f8c30(&local_198,&local_188);
        if (local_17a == '\0') {
          uVar10 = 0x6f68ff;
          if (DAT_130b720ba88 == '\0') {
            uVar10 = uVar16;
          }
          FUN_130b71d0a30(&local_188,0x130b72060b0,0,0x130b7209b00);
          FUN_130b71f8e50(&local_188,uVar10);
          pcVar11 = &DAT_130b720ba8e;
          uVar10 = 0x201c3c;
        }
        else {
          cVar7 = FUN_130b71eb190();
          pcVar12 = &DAT_130b720ba89;
          if (cVar7 == '\0') {
            pcVar12 = &DAT_130b720ba87;
          }
          uVar10 = 0x58bef4;
          if (cVar7 == '\0') {
            uVar10 = 0x96e24d;
          }
          if (*pcVar12 == '\0') {
            uVar10 = uVar16;
          }
          FUN_130b71d0a30(&local_188,0x130b72060b0,0,0x130b7209b00);
          FUN_130b71f8e50(&local_188,uVar10);
          cVar7 = FUN_130b71eb190();
          if (cVar7 == '\0') {
            pcVar11 = &DAT_130b720ba8d;
          }
          uVar10 = 0x16303d;
          if (cVar7 == '\0') {
            uVar10 = 0x28340e;
          }
        }
        if (*pcVar11 == '\0') {
          uVar10 = 0;
        }
        FUN_130b71d0a30(&local_188,0x130b72056e0,0,0x130b7209b10);
        FUN_130b71f8fa0(&local_188,uVar10);
        FUN_130b71d0a30(&local_188,&local_b8,0,0x130b7209b20);
        FUN_130b71d0a30(&local_198,0x130b72060e0,0,0x130b7209b30);
        FUN_130b71f8c30(&local_198,&local_188);
        FUN_130b71d0a30(&local_188,0x130b72060e0,0,0x130b7209b40);
        FUN_130b71f8fa0(&local_188,local_a8);
        uVar10 = 0x96e24d;
        if (DAT_130b720ba87 == '\0') {
          uVar10 = 0;
        }
        uVar16 = 0x6f68ff;
        if (DAT_130b720ba88 == '\0') {
          uVar16 = 0;
        }
        if (DAT_130b720ba6e != '\0') {
          uVar16 = uVar10;
        }
        FUN_130b71d0a30(&local_188,0x130b72060e0,0,0x130b7209b50);
        FUN_130b71f9100(&local_188,uVar16);
        FUN_130b71d0000(&local_158);
        FUN_130b71d0000(&local_148);
        FUN_130b71d0000(&local_108);
        FUN_130b71d0000(&local_f8);
        FUN_130b71d0000(&local_e8);
        FUN_130b71d0000(&local_118);
        FUN_130b71d0000(&local_d8);
        FUN_130b71d0000(&local_c8);
        FUN_130b71d0000(&local_b8);
        FUN_130b71d0000(&local_138);
LAB_130b71ff278:
        FUN_130b71d0000(&local_188);
        FUN_130b71d0000(&local_198);
        FUN_130b71d0000(&local_178);
        FUN_130b71d0000(&local_128);
        FUN_130b71d0000(&local_98);
        return;
      }
      (*(code *)0x7ff63a0fd7c0)(0x130b53f81d8,_DAT_130b720bce8,2);
      FUN_130b71d0a30(&local_188,0x130b720bb3c,1,0x130b7209930);
      FUN_130b71d0a30(&local_198,0x130b7206238,0);
      lVar2 = local_184;
      if (local_184 == 0) {
LAB_130b71fe10d:
        if (local_194 == 0) goto LAB_130b71fe20d;
      }
      else {
        uVar15 = *(uint *)(local_184 + -4);
        uVar17 = (ulonglong)uVar15;
        if ((uVar17 != 0) || (local_194 == 0)) {
          if (local_194 == 0) {
            uVar14 = 0;
            uVar19 = uVar15;
          }
          else {
            uVar14 = (ulonglong)*(uint *)(local_194 + -4);
            uVar19 = uVar15 + *(uint *)(local_194 + -4);
          }
          cVar7 = FUN_130b71d0060(&local_198);
          if (cVar7 == '\0') goto LAB_130b71ff49c;
          if (uVar17 != 0) {
            lVar1 = local_194 + uVar14 * 2;
            if (uVar15 < 0x10) {
              uVar14 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar22 = 0;
              uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
                *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
                ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
                uVar22 = uVar22 + 0x10;
              } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar14 == uVar17) goto LAB_130b71fe102;
            }
            do {
              *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar17 != uVar14);
          }
LAB_130b71fe102:
          *(uint *)(local_194 + -4) = uVar19;
          *(undefined2 *)(local_194 + (ulonglong)uVar19 * 2) = 0;
          goto LAB_130b71fe10d;
        }
      }
      lVar2 = local_194;
      uVar15 = *(uint *)(local_194 + -4);
      uVar17 = (ulonglong)uVar15;
      if ((uVar17 == 0) && (local_154 != 0)) goto LAB_130b71fe20d;
      if (local_154 == 0) {
        uVar14 = 0;
        uVar19 = uVar15;
      }
      else {
        uVar14 = (ulonglong)*(uint *)(local_154 + -4);
        uVar19 = uVar15 + *(uint *)(local_154 + -4);
      }
      cVar7 = FUN_130b71d0060(&local_158);
      if (cVar7 != '\0') {
        if (uVar17 != 0) {
          lVar1 = local_154 + uVar14 * 2;
          if (uVar15 < 0x10) {
            uVar14 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar14 = 0;
          }
          else {
            uVar22 = 0;
            uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
              *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
              ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
              uVar22 = uVar22 + 0x10;
            } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar14 == uVar17) goto LAB_130b71fe202;
          }
          do {
            *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
            uVar14 = uVar14 + 1;
          } while (uVar17 != uVar14);
        }
LAB_130b71fe202:
        *(uint *)(local_154 + -4) = uVar19;
        *(undefined2 *)(local_154 + (ulonglong)uVar19 * 2) = 0;
        goto LAB_130b71fe20d;
      }
      goto LAB_130b71ff45c;
    }
    uVar15 = *(uint *)(local_184 + -4);
    uVar17 = (ulonglong)uVar15;
    if ((uVar17 == 0) && (local_194 != 0)) goto LAB_130b71fda5b;
    if (local_194 == 0) {
      uVar14 = 0;
      uVar19 = uVar15;
    }
    else {
      uVar14 = (ulonglong)*(uint *)(local_194 + -4);
      uVar19 = uVar15 + *(uint *)(local_194 + -4);
    }
    cVar7 = FUN_130b71d0060(&local_198);
    if (cVar7 != '\0') {
      if (uVar17 != 0) {
        lVar1 = local_194 + uVar14 * 2;
        if (uVar15 < 0x10) {
          uVar14 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar14 = 0;
        }
        else {
          uVar22 = 0;
          uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
          do {
            uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
            *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
            ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
            uVar22 = uVar22 + 0x10;
          } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar14 == uVar17) goto LAB_130b71fda42;
        }
        do {
          *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar17 != uVar14);
      }
LAB_130b71fda42:
      *(uint *)(local_194 + -4) = uVar19;
      *(undefined2 *)(local_194 + (ulonglong)uVar19 * 2) = 0;
      goto LAB_130b71fda4d;
    }
  }
  else {
    uVar15 = *(uint *)(local_184 + -4);
    uVar17 = (ulonglong)uVar15;
    if ((uVar17 == 0) && (local_194 != 0)) goto LAB_130b71fd8bd;
    if (local_194 == 0) {
      uVar19 = 0;
      uVar18 = uVar15;
    }
    else {
      uVar19 = *(uint *)(local_194 + -4);
      uVar18 = uVar15 + uVar19;
    }
    cVar7 = FUN_130b71d0060(&local_198);
    if (cVar7 != '\0') {
      if (uVar17 != 0) {
        lVar1 = local_194 + (ulonglong)uVar19 * 2;
        if (uVar15 < 0x10) {
          uVar14 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar14 = 0;
        }
        else {
          uVar22 = 0;
          uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
          do {
            uVar13 = ((undefined8 *)(lVar2 + uVar22))[1];
            *(undefined8 *)(lVar1 + uVar22) = *(undefined8 *)(lVar2 + uVar22);
            ((undefined8 *)(lVar1 + uVar22))[1] = uVar13;
            uVar22 = uVar22 + 0x10;
          } while ((uVar17 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar14 == uVar17) goto LAB_130b71fd8b2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(lVar2 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar17 != uVar14);
      }
LAB_130b71fd8b2:
      *(uint *)(local_194 + -4) = uVar18;
      *(undefined2 *)(local_194 + (ulonglong)uVar18 * 2) = 0;
      goto LAB_130b71fd8bd;
    }
LAB_130b71ff37c:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x241339000001f9);
LAB_130b71ff39c:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x241342000001f9);
LAB_130b71ff3bc:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x321347000001f9);
LAB_130b71ff3dc:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x311348000001f9);
LAB_130b71ff3fc:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x1d1349000001f9);
LAB_130b71ff41c:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x3e1349000001f9);
LAB_130b71ff43c:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x9133b000001f9);
LAB_130b71ff45c:
    (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x91344000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x18133b000001f9);
LAB_130b71ff49c:
  (*(code *)0x7ff639cc59a0)(0x130b53f81d8,0x181344000001f9);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}


