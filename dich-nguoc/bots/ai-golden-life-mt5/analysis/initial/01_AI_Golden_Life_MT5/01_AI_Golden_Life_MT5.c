/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 2ad99140000 */

void FUN_2ad99140000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2ad95e68178);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 2ad99140060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ad99140060(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2ad95e68178);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_2ad991401bd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_2ad991401bd;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2ad95e68178);
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
        if (uVar15 < 8) goto LAB_2ad99140120;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_2ad99140120;
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
LAB_2ad99140120:
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
          (*(code *)0x7ff63a101200)(0x2ad95e68178,puVar14);
        }
      }
      goto LAB_2ad991401bd;
    }
  }
  _DAT_2ad99183b10 = 0x13aa;
  uVar12 = 0;
LAB_2ad991401bd:
  return uVar12 & 0xffffffff;
}



/* Address: 2ad991401d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad991401d0(int *param_1,longlong param_2,uint param_3)

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
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    if (param_3 - 1 < 0xfffffffe) {
      _DAT_2ad99183b10 = 0xfa2;
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
  uVar7 = 0x7ffffffe;
  if (uVar8 < 0x7ffffffe) {
    uVar7 = uVar9;
  }
  piVar4 = *(int **)(param_1 + 1);
  puVar5 = (uint *)(piVar4 + -3);
  if (piVar4 == (int *)0x0) {
    puVar5 = (uint *)0x0;
  }
  uVar6 = (uint)uVar7;
  if ((*param_1 != 0) && (puVar5 != (uint *)0x0)) {
    if ((uVar6 <= *puVar5) && (puVar5[1] == 1)) goto LAB_2ad991402a7;
    if (*puVar5 != 0) {
      puVar5 = puVar5 + 1;
      *puVar5 = *puVar5 - 1;
      if (*puVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  piVar3 = (int *)(*(code *)0x7ff63a101190)(0x2ad95e68178);
  if (piVar3 == (int *)0x0) {
    _DAT_2ad99183b10 = 0x13aa;
    return;
  }
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar4 = piVar3 + 3;
  *(undefined2 *)(piVar3 + 3) = 0;
  *(int **)(param_1 + 1) = piVar4;
  *param_1 = *piVar3;
LAB_2ad991402a7:
  if (uVar8 == 0) {
    piVar4[-1] = uVar6;
    *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
    return;
  }
  uVar9 = 0;
  if (uVar8 < 8) goto LAB_2ad99140300;
  if ((ulonglong)((longlong)piVar4 - param_2) < 0x20) goto LAB_2ad99140300;
  uVar9 = (ulonglong)(uVar6 & 0x7ffffff8);
  uVar10 = 0;
  do {
    uVar2 = ((undefined8 *)(param_2 + uVar10))[1];
    *(undefined8 *)((longlong)piVar4 + uVar10) = *(undefined8 *)(param_2 + uVar10);
    ((undefined8 *)((longlong)piVar4 + uVar10))[1] = uVar2;
    uVar10 = uVar10 + 0x10;
  } while ((uVar7 * 2 & 0xfffffffffffffff0) != uVar10);
  for (; uVar9 != uVar7; uVar9 = uVar9 + 1) {
LAB_2ad99140300:
    *(undefined2 *)((longlong)piVar4 + uVar9 * 2) = *(undefined2 *)(param_2 + uVar9 * 2);
  }
  piVar4[-1] = uVar6;
  *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
  if (0x7ffffffe < uVar8) {
    _DAT_2ad99183b10 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2ad991403b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ad991403b0(short *param_1,short *param_2,uint param_3)

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
    _DAT_2ad99183b10 = 0xfa9;
    uVar7 = 0xffffffff;
  }
  else {
    uVar10 = *(uint *)(param_1 + -2);
    if ((uVar10 == 0) || (uVar4 = *(uint *)(param_2 + -2), uVar4 == 0)) {
      _DAT_2ad99183b10 = 0x13ab;
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
              if (uVar11 - 1 == uVar8) goto LAB_2ad991403ea;
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
                  if (uVar4 == uVar8) goto LAB_2ad991404c6;
                }
                if (uVar4 == (uint)uVar8) {
LAB_2ad991404c6:
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
LAB_2ad991403ea:
        uVar7 = 0xffffffff;
      }
    }
  }
  return uVar7;
}



/* Address: 2ad991404e0 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_2ad991404e0(uint *param_1,short *param_2)

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
  
  uVar21 = _DAT_2ad99160cfc;
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
      puVar29 = (undefined1 *)(longlong)(int)_DAT_2ad99160cfc;
      iVar11 = (int)((longlong)(int)uVar20 / (longlong)(int)uVar6) * _DAT_2ad99160cfc;
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
LAB_2ad99140620:
          if ((uint)uVar24 == uVar6) goto LAB_2ad99140629;
          iVar19 = uVar18 + 1;
        }
        else {
          uVar24 = 1;
          do {
            uVar5 = *(ushort *)(lVar7 + (longlong)(int)uVar18 * 2 + uVar24 * 2);
            puVar14 = (undefined1 *)(ulonglong)uVar5;
            if (uVar5 != param_2[uVar24]) goto LAB_2ad99140620;
            uVar24 = uVar24 + 1;
          } while (uVar6 != uVar24);
LAB_2ad99140629:
          if (puVar15 == (uint *)0x0) {
            puVar13 = (uint *)(*(code *)0x7ff63a101190)(0x2ad95e68178,iVar11 + uVar20);
            if (puVar13 == (uint *)0x0) {
              _DAT_2ad99183b10 = 0x13aa;
              return &DAT_2ad99183b10;
            }
            puVar13[1] = 1;
            puVar13[2] = 0;
            puVar15 = puVar13 + 3;
            *(undefined2 *)(puVar13 + 3) = 0;
            local_68 = *puVar13;
            puVar14 = (undefined1 *)(ulonglong)local_68;
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) goto LAB_2ad991406b3;
          }
          else {
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) {
LAB_2ad991406b3:
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
                    if (puVar27 == puVar14) goto joined_r0x02ad99140716;
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
joined_r0x02ad99140716:
              } while (puVar27 != puVar22);
              uVar26 = uVar26 + uVar16;
            }
          }
          if (uVar21 != 0) {
            lVar17 = (longlong)(int)uVar26;
            if (uVar21 < 8) {
              puVar22 = (undefined1 *)0x0;
            }
            else if ((ulonglong)((longlong)puVar15 + lVar17 * 2 + -0x2ad99160d00) < 0x20) {
              puVar22 = (undefined1 *)0x0;
            }
            else {
              puVar14 = (undefined1 *)0x0;
              do {
                lVar2 = (longlong)puVar14 * 2;
                uVar8 = *(undefined4 *)(lVar2 + 0x2ad99160d04);
                uVar9 = *(undefined4 *)(lVar2 + 0x2ad99160d08);
                uVar10 = *(undefined4 *)(lVar2 + 0x2ad99160d0c);
                puVar3 = (undefined4 *)((longlong)puVar15 + (longlong)puVar14 * 2 + lVar17 * 2);
                *puVar3 = *(undefined4 *)(&DAT_2ad99160d00 + lVar2);
                puVar3[1] = uVar8;
                puVar3[2] = uVar9;
                puVar3[3] = uVar10;
                puVar14 = puVar14 + 8;
              } while (puVar12 != puVar14);
              puVar14 = puVar12;
              puVar22 = puVar12;
              if (puVar12 == puVar29) goto LAB_2ad991407c2;
            }
            do {
              uVar5 = *(ushort *)(&DAT_2ad99160d00 + (longlong)puVar22 * 2);
              *(ushort *)((longlong)puVar15 + (longlong)puVar22 * 2 + lVar17 * 2) = uVar5;
              puVar22 = puVar22 + 1;
              puVar14 = (undefined1 *)(ulonglong)uVar5;
            } while (puVar29 != puVar22);
          }
LAB_2ad991407c2:
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
              if (uVar25 == uVar28) goto joined_r0x02ad99140889;
            } while( true );
          }
          uVar25 = 0;
        }
        do {
          *(undefined2 *)((longlong)puVar15 + uVar25 * 2 + (longlong)(int)uVar26 * 2) =
               *(undefined2 *)(lVar7 + uVar25 * 2);
          uVar25 = uVar25 + 1;
joined_r0x02ad99140889:
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
          puVar12 = (undefined1 *)(*(code *)0x7ff63a101200)(0x2ad95e68178);
          return puVar12;
        }
        return puVar12;
      }
      return puVar12;
    }
  }
  _DAT_2ad99183b10 = 0x13b0;
  return &DAT_2ad99183b10;
}



/* Address: 2ad99140830 */

void FUN_2ad99140830(longlong param_1)

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
      (*(code *)0x7ff63a101200)(0x2ad95e68178);
      return;
    }
  }
  return;
}



/* Address: 2ad99140920 */

ulonglong FUN_2ad99140920(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_2ad99140a2d;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_2ad99140a2d;
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
  cVar5 = FUN_2ad99140060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_2ad99140a2d;
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
      if (uVar10 == uVar9) goto LAB_2ad99140a22;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_2ad99140a22:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_2ad99140a2d:
  return uVar8 & 0xffffffff;
}



/* Address: 2ad99140a40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99140a40(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
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
        (*(code *)0x7ff63a101200)(0x2ad95e68178,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x2ad95e68178,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_2ad99183b10 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x2ad95e68178,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_2ad99140bd0;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_2ad99140bd0:
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
      (*(code *)0x7ff63a101200)(0x2ad95e68178);
      return;
    }
  }
  return;
}



/* Address: 2ad99140c60 */

bool FUN_2ad99140c60(longlong param_1,longlong param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  ulonglong uVar8;
  
  if (param_1 == param_2) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
    if ((param_1 != 0) && (param_2 != 0)) {
      uVar3 = *(uint *)(param_1 + -4);
      uVar4 = *(uint *)(param_2 + -4);
      uVar5 = uVar4;
      if (uVar3 < uVar4) {
        uVar5 = uVar3;
      }
      iVar7 = uVar3 - uVar4;
      if (uVar5 != 0) {
        uVar8 = 1;
        do {
          uVar1 = *(ushort *)(param_1 + -2 + uVar8 * 2);
          uVar2 = *(ushort *)(param_2 + -2 + uVar8 * 2);
          if (uVar5 <= uVar8) break;
          uVar8 = uVar8 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar7 = (uint)uVar1 - (uint)uVar2;
        }
      }
    }
  }
  bVar6 = iVar7 == 0;
  if (param_3 == 0x14) {
    bVar6 = iVar7 != 0;
  }
  return bVar6;
}



/* Address: 2ad99140cf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99140cf0(int *param_1)

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
  ulonglong uVar14;
  ulonglong uVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  ulonglong uVar19;
  
  lVar8 = *(longlong *)(param_1 + 1);
  if ((lVar8 == 0) || (piVar16 = (int *)(lVar8 + -0xc), piVar16 == (int *)0x0)) {
    _DAT_2ad99183b10 = 0xfa9;
  }
  else {
    uVar5 = *(uint *)(lVar8 + -4);
    uVar14 = (ulonglong)uVar5;
    if (uVar14 != 0) {
      uVar19 = 0;
      do {
        uVar15 = (ulonglong)*(ushort *)(lVar8 + uVar19 * 2);
        uVar13 = uVar19;
        if ((0x20 < uVar15) || ((0x100002600U >> (uVar15 & 0x3f) & 1) == 0)) break;
        uVar19 = uVar19 + 1;
        uVar13 = uVar14;
      } while (uVar14 != uVar19);
      uVar18 = (uint)uVar13;
      if (uVar18 != 0) {
        uVar17 = uVar5 - uVar18;
        piVar12 = (int *)(*(code *)0x7ff63a101190)(0x2ad95e68178,uVar17);
        if (piVar12 == (int *)0x0) {
          _DAT_2ad99183b10 = 0x13aa;
        }
        else {
          piVar12[1] = 1;
          piVar12[2] = 0;
          piVar1 = piVar12 + 3;
          *(undefined2 *)(piVar12 + 3) = 0;
          iVar6 = *piVar12;
          uVar14 = (ulonglong)uVar17;
          if (uVar5 != uVar18) {
            lVar2 = lVar8 + (uVar13 & 0xffffffff) * 2;
            uVar19 = uVar14 + (uVar14 == 0);
            if ((0xf < uVar17) &&
               (0x1f < (longlong)piVar12 - ((longlong)piVar16 + (uVar13 & 0xffffffff) * 2))) {
              uVar13 = (ulonglong)((uint)uVar19 & 0xfffffff8);
              uVar15 = 0;
              do {
                puVar3 = (undefined4 *)(lVar2 + uVar15 * 2);
                uVar9 = puVar3[1];
                uVar10 = puVar3[2];
                uVar11 = puVar3[3];
                puVar4 = (undefined4 *)((longlong)piVar1 + uVar15 * 2);
                *puVar4 = *puVar3;
                puVar4[1] = uVar9;
                puVar4[2] = uVar10;
                puVar4[3] = uVar11;
                uVar15 = uVar15 + 8;
                if (uVar13 == uVar15) goto LAB_2ad99140e30;
              } while( true );
            }
            uVar13 = 0;
            do {
              *(undefined2 *)((longlong)piVar1 + uVar13 * 2) = *(undefined2 *)(lVar2 + uVar13 * 2);
              uVar13 = uVar13 + 1;
LAB_2ad99140e30:
            } while (uVar19 != uVar13);
          }
          piVar12[2] = uVar17;
          *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = 0;
          iVar7 = *param_1;
          *param_1 = iVar6;
          *(int **)(param_1 + 1) = piVar1;
          if ((iVar7 != 0) && (*piVar16 != 0)) {
            piVar12 = (int *)(lVar8 + -8);
            *piVar12 = *piVar12 + -1;
            if (*piVar12 == 0) {
              (*(code *)0x7ff63a101200)(0x2ad95e68178,piVar16);
              return;
            }
          }
        }
      }
    }
  }
  return;
}



/* Address: 2ad99140e80 */

void FUN_2ad99140e80(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  (*(code *)0x7ff63a1021d0)(0x2ad95e68178,1,param_1,param_2,0,1,param_3);
  return;
}



/* Address: 2ad99140ed0 */

undefined8 FUN_2ad99140ed0(void)

{
  return 0;
}



/* Address: 2ad99140ee0 */

void FUN_2ad99140ee0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x2ad95e68178,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ad99140f30 */

void FUN_2ad99140f30(undefined8 *param_1)

{
  (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*param_1,0x2ad95e51640);
  param_1[1] = 0x2ad99160be0;
  return;
}



/* Address: 2ad99140f70 */

undefined4 FUN_2ad99140f70(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_2ad99140a40(&local_70,0x2ad99160d08,0,0x2ad9916ffe8);
  local_80 = 0;
  local_7c = 0;
  FUN_2ad99140a40(&local_80,0x2ad99160d08,0,0x2ad9916fff8);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x2ad95e68178,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_2ad99141142;
    uVar4 = 0x2ad99170038;
    uVar3 = 0x2ad99170028;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_2ad99141142;
    uVar4 = 0x2ad99170018;
    uVar3 = 0x2ad99170008;
  }
  FUN_2ad99156a40(&local_80,param_2,param_3);
  FUN_2ad99140a40(&local_60,0x2ad99183b3c,1,uVar3);
  FUN_2ad99157420(param_1,&local_70,param_2);
  FUN_2ad99140a40(&local_50,0x2ad99183b3c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x2ad95e68178,0xd,3,0x590008,0x2ad99161988,0x590008,&local_50,0x590008,&local_60);
LAB_2ad99141142:
  FUN_2ad99140000(&local_80);
  FUN_2ad99140000(&local_70);
  FUN_2ad99140000(&local_60);
  FUN_2ad99140000(&local_50);
  return uVar1;
}



/* Address: 2ad99141180 */

void FUN_2ad99141180(undefined8 *param_1)

{
  FUN_2ad99140000(param_1 + 0x41);
  FUN_2ad99140000((longlong)param_1 + 0x144);
  FUN_2ad99140000((longlong)param_1 + 0x84);
  FUN_2ad99140000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*param_1,0x2ad95e51640);
  param_1[1] = 0x2ad99160be0;
  return;
}



/* Address: 2ad991411f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ad991411f0(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  undefined2 *puVar6;
  char cVar7;
  char cVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong lVar17;
  longlong lVar18;
  undefined4 *puVar19;
  byte bVar20;
  undefined4 uVar21;
  undefined4 *puVar22;
  uint uVar23;
  undefined4 uVar24;
  ulonglong uVar25;
  uint *puVar26;
  ulonglong uVar27;
  uint uVar28;
  undefined8 *unaff_RBX;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  char *unaff_RBP;
  undefined8 *puVar32;
  code *pcVar33;
  ulonglong uVar34;
  uint uVar35;
  undefined8 uVar36;
  ulonglong uVar37;
  char *unaff_R12;
  code *pcVar38;
  short sVar39;
  short *psVar40;
  code *unaff_R15;
  bool bVar41;
  double dVar42;
  double dVar43;
  ulonglong in_stack_fffffffffffffe58;
  undefined8 in_stack_fffffffffffffe88;
  undefined8 in_stack_fffffffffffffe98;
  undefined4 local_148;
  longlong local_144;
  undefined4 local_138;
  longlong local_134;
  longlong local_128;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_110;
  undefined8 local_10c;
  uint local_104;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f4;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  longlong local_dc;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c0;
  longlong local_bc;
  ulonglong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 *local_74;
  code *local_68;
  int local_44;
  
  local_e0 = 0;
  local_f0 = 0;
  local_78 = 0;
  local_100 = 0;
  local_98 = 0;
  local_dc = 0;
  local_ec = 0;
  local_74 = (undefined8 *)0x0;
  local_fc = 0;
  local_94 = 0;
  _DAT_2ad99178394 = 0;
  _DAT_2ad99178250 = _DAT_2ad99183b18 * _DAT_2ad991606a0;
  pcVar12 = (code *)(*(code *)0x7ff63a0e65d0)(0x2ad95e68178,0x2ad95df98b0);
  pcVar38 = (code *)0x7ff63a0e6410;
  puVar13 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ad95e68178,pcVar12);
  puVar32 = (undefined8 *)0x2ad95e68178;
  if (puVar13 == (undefined8 *)0x0) {
LAB_2ad99142184:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1200d3000001fa);
LAB_2ad991421a4:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1200d6000001fa);
LAB_2ad991421c4:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x100d4000001fa);
LAB_2ad991421e4:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x100d5000001fa);
LAB_2ad99142204:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x60101000001f6);
LAB_2ad99142224:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2b00d8000001f9);
LAB_2ad99142244:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4c00d8000001f9);
LAB_2ad99142264:
    lVar15 = 0x2ad95e68178;
    uVar28 = 0x1f9;
    uVar29 = (*(code *)0x7ff639cc59a0)();
LAB_2ad99142284:
    do {
      *(undefined8 *)(lVar15 + (longlong)(int)uVar28 * 8) = 0;
      uVar28 = uVar28 + 1;
LAB_2ad99142291:
      lVar17 = _DAT_2ad991782bc;
      uVar23 = (uint)unaff_RBX;
    } while (uVar23 != uVar28);
    if (_DAT_2ad991782a8 < uVar23) {
      lVar17 = 0x2ad95e68178;
      uVar28 = 0x1f6;
      uVar29 = (*(code *)0x7ff639cc59a0)();
      goto LAB_2ad99142307;
    }
    uVar28 = 0;
    if (uVar29 < 0x80000003) goto LAB_2ad99142307;
    puVar13 = (undefined8 *)(_DAT_2ad991782bc + 0x10);
    uVar28 = uVar23 & 0xfffffffc;
    uVar35 = uVar28;
    do {
      puVar13[-2] = 0;
      puVar13[-1] = 0;
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13 = puVar13 + 4;
      uVar35 = uVar35 - 4;
    } while (uVar35 != 0);
    for (; lVar15 = _DAT_2ad991782fc, uVar23 != uVar28; uVar28 = uVar28 + 1) {
LAB_2ad99142307:
      *(undefined8 *)(lVar17 + (longlong)(int)uVar28 * 8) = 0;
    }
    if (_DAT_2ad991782e8 < uVar23) {
      lVar15 = 0x2ad95e68178;
      uVar28 = 0x1f6;
      uVar29 = (*(code *)0x7ff639cc59a0)();
      goto LAB_2ad99142387;
    }
    uVar28 = 0;
    if (uVar29 < 0x80000003) goto LAB_2ad99142387;
    puVar13 = (undefined8 *)(_DAT_2ad991782fc + 0x10);
    uVar28 = uVar23 & 0xfffffffc;
    uVar35 = uVar28;
    do {
      puVar13[-2] = 0;
      puVar13[-1] = 0;
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13 = puVar13 + 4;
      uVar35 = uVar35 - 4;
    } while (uVar35 != 0);
    for (; lVar17 = _DAT_2ad9917833c, uVar23 != uVar28; uVar28 = uVar28 + 1) {
LAB_2ad99142387:
      *(undefined8 *)(lVar15 + (longlong)(int)uVar28 * 8) = 0;
    }
    if (_DAT_2ad99178328 < uVar23) {
      lVar17 = 0x2ad95e68178;
      uVar28 = 0x1f6;
      uVar29 = (*(code *)0x7ff639cc59a0)();
      goto LAB_2ad99142407;
    }
    uVar28 = 0;
    if (uVar29 < 0x80000003) goto LAB_2ad99142407;
    puVar13 = (undefined8 *)(_DAT_2ad9917833c + 0x10);
    uVar28 = uVar23 & 0xfffffffc;
    uVar35 = uVar28;
    do {
      puVar13[-2] = 0;
      puVar13[-1] = 0;
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13 = puVar13 + 4;
      uVar35 = uVar35 - 4;
    } while (uVar35 != 0);
    for (; lVar15 = _DAT_2ad9917837c, uVar23 != uVar28; uVar28 = uVar28 + 1) {
LAB_2ad99142407:
      *(undefined8 *)(lVar17 + (longlong)(int)uVar28 * 8) = 0;
    }
    if (_DAT_2ad99178368 < uVar23) {
      lVar15 = 0x2ad95e68178;
      uVar28 = 0x1f6;
      (*(code *)0x7ff639cc59a0)();
      goto LAB_2ad99142485;
    }
    uVar28 = 0;
    if (uVar29 < 0x80000003) goto LAB_2ad99142485;
    puVar13 = (undefined8 *)(_DAT_2ad9917837c + 0x10);
    uVar28 = uVar23 & 0xfffffffc;
    uVar29 = uVar28;
    do {
      puVar13[-2] = 0;
      puVar13[-1] = 0;
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13 = puVar13 + 4;
      uVar29 = uVar29 - 4;
    } while (uVar29 != 0);
    while( true ) {
      uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
      uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
      if (uVar23 == uVar28) break;
LAB_2ad99142485:
      *(undefined8 *)(lVar15 + (longlong)(int)uVar28 * 8) = 0;
      uVar28 = uVar28 + 1;
    }
  }
  else {
    unaff_RBX = (undefined8 *)0x2ad95e68178;
    unaff_R12 = (char *)0x7ff63a0e6470;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar13,0x2ad95e867d0);
    puVar13[1] = 0x2ad99160ba0;
    puVar13[2] = 0;
    puVar13[3] = 0;
    *(undefined4 *)((longlong)puVar13 + 0x34) = 0;
    puVar13[7] = 0;
    *(undefined4 *)((longlong)puVar13 + 0x84) = 0;
    puVar13[0x11] = 0;
    *(undefined4 *)((longlong)puVar13 + 0x144) = 0;
    puVar13[0x29] = 0;
    *(undefined4 *)(puVar13 + 0x41) = 0;
    *(undefined8 *)((longlong)puVar13 + 0x20c) = 0;
    puVar14 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ad95e68178,pcVar12);
    puVar32 = puVar13;
    if (puVar14 == (undefined8 *)0x0) goto LAB_2ad99142184;
    unaff_RBX = (undefined8 *)0x2ad95e68178;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar14,0x2ad95e51640);
    puVar14[1] = 0x2ad99160be0;
    puVar14[2] = 0;
    puVar14[3] = 0;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar14,0x2ad95df98b0);
    puVar14[1] = 0x2ad99160c60;
    *(undefined1 *)((longlong)puVar14 + 0x294) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x295) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x29d) = 10;
    *(undefined4 *)((longlong)puVar14 + 0x2a5) = 0;
    *(undefined4 *)((longlong)puVar14 + 0x2ad) = 1;
    uVar9 = (*(code *)0x7ff63a0c73c0)(0x2ad95e68178,0x35);
    unaff_R15 = FUN_2ad99140000;
    *(undefined4 *)((longlong)puVar14 + 0x2a9) = uVar9;
    puVar14[4] = 0;
    puVar14[5] = 0;
    *(undefined4 *)(puVar14 + 6) = 0;
    FUN_2ad99140000((longlong)puVar14 + 0x34);
    *(undefined4 *)(puVar14 + 0x10) = 0;
    puVar14[0xf] = 0;
    puVar14[0xe] = 0;
    puVar14[0xd] = 0;
    puVar14[0xc] = 0;
    puVar14[0xb] = 0;
    puVar14[10] = 0;
    puVar14[9] = 0;
    puVar14[8] = 0;
    FUN_2ad99140000((longlong)puVar14 + 0x84);
    unaff_RBP = (char *)0x7ff63a3fad20;
    (*(code *)0x7ff63a3fad20)(puVar14 + 0x12,0,0xb4);
    FUN_2ad99140000((longlong)puVar14 + 0x144);
    (*(code *)0x7ff63a3fad20)(puVar14 + 0x2a,0,0xb8);
    FUN_2ad99140000(puVar14 + 0x41);
    *(undefined8 *)((longlong)puVar14 + 0x28c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x284) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x27c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x274) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x26c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x264) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x25c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x254) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x24c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x244) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x23c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x234) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x22c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x224) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x21c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x214) = 0;
    iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,6);
    if (iVar10 != 0) {
      *(undefined4 *)((longlong)puVar14 + 0x2ad) = 2;
    }
    iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,7);
    if (iVar10 != 0) {
      *(undefined4 *)((longlong)puVar14 + 0x2ad) = 0;
    }
    puVar32 = (undefined8 *)&DAT_2ad99178420;
    _DAT_2ad99178420 = pcVar12;
    lVar15 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,pcVar12);
    if (lVar15 == 0) goto LAB_2ad991421c4;
    *(longlong *)(lVar15 + 0x29d) = (longlong)(int)(_DAT_2ad99183c88 * _DAT_2ad991606a0);
    lVar15 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
    if (lVar15 == 0) goto LAB_2ad991421e4;
    unaff_R15 = (code *)(longlong)_DAT_2ad99183c78;
    *(code **)(lVar15 + 0x295) = unaff_R15;
    puVar32 = (undefined8 *)(*(code *)0x7ff63a0e65d0)(0x2ad95e68178,0x2ad95e48c10);
    puVar13 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ad95e68178,puVar32);
    unaff_RBX = (undefined8 *)0x2ad95e68178;
    if (puVar13 == (undefined8 *)0x0) goto LAB_2ad991421a4;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar13,0x2ad95e867d0);
    puVar13[1] = 0x2ad99160ba0;
    puVar13[2] = 0;
    puVar13[3] = 0;
    puVar14 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ad95e68178,puVar32);
    unaff_RBX = puVar13;
    if (puVar14 == (undefined8 *)0x0) goto LAB_2ad991421a4;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar14,0x2ad95e51640);
    puVar14[1] = 0x2ad99160be0;
    puVar14[2] = 0;
    puVar14[3] = 0;
    (*(code *)0x7ff63a0e6470)(0x2ad95e68178,*puVar14,0x2ad95e48c10);
    puVar14[1] = 0x2ad99160c20;
    *(undefined4 *)(puVar14 + 4) = 0xffffffff;
    *(undefined8 *)((longlong)puVar14 + 0x24) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x2c) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x34) = 0;
    *(undefined8 *)((longlong)puVar14 + 0x3c) = 0;
    _DAT_2ad99178418 = puVar32;
    (*(code *)0x7ff63a0e21f0)(0x2ad95e68178,1);
    uVar23 = 0;
    (*(code *)0x7ff63a0f0d20)(0x2ad95e68178,0);
    pcVar38 = FUN_2ad99140a40;
    FUN_2ad99140a40(&local_98,0x2ad99183b3c,1,0x2ad991647c8);
    FUN_2ad99140a40(&local_100,&local_98,0);
    uVar29 = _DAT_2ad99161302;
    pcVar12 = (code *)&DAT_2ad99161302;
    puVar32 = (undefined8 *)(ulonglong)_DAT_2ad99161302;
    if ((puVar32 != (undefined8 *)0x0) || (local_fc == 0)) {
      if (local_fc != 0) {
        uVar23 = *(uint *)(local_fc + -4);
      }
      uVar28 = _DAT_2ad99161302 + uVar23;
      unaff_RBX = (undefined8 *)(ulonglong)uVar28;
      cVar7 = FUN_2ad99140060(&local_100);
      if (cVar7 != '\0') {
        if (puVar32 != (undefined8 *)0x0) {
          lVar15 = local_fc + (ulonglong)uVar23 * 2;
          if ((uVar29 < 0x10) || (lVar15 - 0x2ad99161306U < 0x20)) {
            puVar13 = (undefined8 *)0x0;
          }
          else {
            uVar34 = 0;
            puVar13 = (undefined8 *)(ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar34 + 0x2ad9916130e);
              *(undefined8 *)(lVar15 + uVar34) = *(undefined8 *)(&DAT_2ad99161306 + uVar34);
              ((undefined8 *)(lVar15 + uVar34))[1] = uVar16;
              uVar34 = uVar34 + 0x10;
            } while (((longlong)puVar32 * 2 & 0xfffffffffffffff0U) != uVar34);
            if (puVar13 == puVar32) goto LAB_2ad991418d2;
          }
          do {
            *(undefined2 *)(lVar15 + (longlong)puVar13 * 2) =
                 *(undefined2 *)(&DAT_2ad99161306 + (longlong)puVar13 * 2);
            puVar13 = (undefined8 *)((longlong)puVar13 + 1);
          } while (puVar32 != puVar13);
        }
LAB_2ad991418d2:
        *(uint *)(local_fc + -4) = uVar28;
        *(undefined2 *)(local_fc + (longlong)unaff_RBX * 2) = 0;
        goto LAB_2ad991418dd;
      }
      goto LAB_2ad99142224;
    }
LAB_2ad991418dd:
    (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,unaff_R15,0,0x20);
    FUN_2ad99140a40(&local_78,0x2ad99183b3c,1,0x2ad991647e8);
    FUN_2ad99140a40(&local_f0,&local_100);
    puVar32 = local_74;
    if (local_74 != (undefined8 *)0x0) {
      uVar23 = *(uint *)((longlong)local_74 + -4);
      unaff_RBX = (undefined8 *)(ulonglong)uVar23;
      if ((unaff_RBX == (undefined8 *)0x0) && (local_ec != 0)) goto LAB_2ad99141a9d;
      if (local_ec == 0) {
        uVar34 = 0;
        uVar29 = uVar23;
      }
      else {
        uVar34 = (ulonglong)*(uint *)(local_ec + -4);
        uVar29 = uVar23 + *(uint *)(local_ec + -4);
      }
      unaff_RBP = (char *)(ulonglong)uVar29;
      cVar7 = FUN_2ad99140060(&local_f0);
      if (cVar7 != '\0') {
        if (unaff_RBX != (undefined8 *)0x0) {
          lVar15 = local_ec + uVar34 * 2;
          if (uVar23 < 0x10) {
            puVar13 = (undefined8 *)0x0;
          }
          else if ((ulonglong)(lVar15 - (longlong)puVar32) < 0x20) {
            puVar13 = (undefined8 *)0x0;
          }
          else {
            uVar34 = 0;
            puVar13 = (undefined8 *)(ulonglong)(uVar23 & 0xfffffff8);
            do {
              uVar16 = ((undefined8 *)((longlong)puVar32 + uVar34))[1];
              *(undefined8 *)(lVar15 + uVar34) = *(undefined8 *)((longlong)puVar32 + uVar34);
              ((undefined8 *)(lVar15 + uVar34))[1] = uVar16;
              uVar34 = uVar34 + 0x10;
            } while (((longlong)unaff_RBX * 2 & 0xfffffffffffffff0U) != uVar34);
            if (puVar13 == unaff_RBX) goto LAB_2ad99141a92;
          }
          do {
            *(undefined2 *)(lVar15 + (longlong)puVar13 * 2) =
                 *(undefined2 *)((longlong)puVar32 + (longlong)puVar13 * 2);
            puVar13 = (undefined8 *)((longlong)puVar13 + 1);
          } while (unaff_RBX != puVar13);
        }
LAB_2ad99141a92:
        *(uint *)(local_ec + -4) = uVar29;
        *(undefined2 *)(local_ec + (longlong)unaff_RBP * 2) = 0;
        goto LAB_2ad99141a9d;
      }
      goto LAB_2ad99142264;
    }
LAB_2ad99141a9d:
    unaff_RBX = (undefined8 *)0x0;
    FUN_2ad99140a40(&local_e0,&local_f0,0,0x2ad99164808);
    uVar23 = _DAT_2ad99161302;
    pcVar12 = (code *)(ulonglong)_DAT_2ad99161302;
    if ((pcVar12 != (code *)0x0) || (local_dc == 0)) {
      if (local_dc != 0) {
        unaff_RBX = (undefined8 *)(ulonglong)*(uint *)(local_dc + -4);
      }
      uVar28 = _DAT_2ad99161302 + (int)unaff_RBX;
      puVar32 = (undefined8 *)(ulonglong)uVar28;
      uVar29 = 0x104;
      if ((0x103 < uVar28) &&
         ((0x7ffffffd < uVar28 || (uVar29 = (uVar28 >> 2) + uVar28, 0x7ffffffd < uVar29)))) {
        uVar29 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_e0,uVar29);
      if (cVar7 != '\0') {
        if (pcVar12 != (code *)0x0) {
          lVar15 = local_dc + (longlong)unaff_RBX * 2;
          if (uVar23 < 0x10) {
            pcVar33 = (code *)0x0;
          }
          else if (lVar15 - 0x2ad99161306U < 0x20) {
            pcVar33 = (code *)0x0;
          }
          else {
            uVar34 = 0;
            pcVar33 = (code *)(ulonglong)(uVar23 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar34 + 0x2ad9916130e);
              *(undefined8 *)(lVar15 + uVar34) = *(undefined8 *)(&DAT_2ad99161306 + uVar34);
              ((undefined8 *)(lVar15 + uVar34))[1] = uVar16;
              uVar34 = uVar34 + 0x10;
            } while (((longlong)pcVar12 * 2 & 0xfffffffffffffff0U) != uVar34);
            if (pcVar33 == pcVar12) goto LAB_2ad99141bc2;
          }
          do {
            *(undefined2 *)(lVar15 + (longlong)pcVar33 * 2) =
                 *(undefined2 *)(&DAT_2ad99161306 + (longlong)pcVar33 * 2);
            pcVar33 = pcVar33 + 1;
          } while (pcVar12 != pcVar33);
        }
LAB_2ad99141bc2:
        *(uint *)(local_dc + -4) = uVar28;
        *(undefined2 *)(local_dc + (longlong)puVar32 * 2) = 0;
        goto LAB_2ad99141bcd;
      }
      goto LAB_2ad99142244;
    }
LAB_2ad99141bcd:
    FUN_2ad99140a40(0x2ad99178398,&local_e0,0,0x2ad99164818);
    uVar16 = (*(code *)0x7ff63a0f5790)(0x2ad95e68178);
    (*(code *)0x7ff63a0f5240)(0x2ad95e68178,uVar16,1,0);
    (*(code *)0x7ff63a0f2c10)(0x2ad95e68178,0x2ad99160ca0,0x2ad99178430);
    DAT_2ad99178400 = 0;
    iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,6);
    uVar9 = _DAT_2ad99183b10;
    if (iVar10 == 0) {
LAB_2ad99141d6e:
      _DAT_2ad99183b10 = uVar9;
      DAT_2ad99178401 = 0;
    }
    else {
      if (_DAT_2ad99183b2c == (short *)0x0) {
        uVar9 = 0xfa9;
        goto LAB_2ad99141d6e;
      }
      uVar23 = *(uint *)(_DAT_2ad99183b2c + -2);
      if ((uVar23 == 0) || (_DAT_2ad99160e18 == 0)) {
        _DAT_2ad99183b10 = 0x13ab;
        goto LAB_2ad99141d01;
      }
      DAT_2ad99178401 = 1;
      if (_DAT_2ad99183b2c == (short *)0x2ad99160e1c) goto LAB_2ad99141d70;
      if ((uVar23 < _DAT_2ad99160e18) || (uVar29 = (uVar23 - _DAT_2ad99160e18) + 1, uVar29 == 0)) {
LAB_2ad99141d01:
        uVar9 = 0x13ab;
        if ((uVar23 != 0) && (_DAT_2ad99161318 != 0)) {
          DAT_2ad99178401 = 1;
          if (_DAT_2ad99183b2c == (short *)0x2ad9916131c) goto LAB_2ad99141d70;
          uVar9 = _DAT_2ad99183b10;
          if ((_DAT_2ad99161318 <= uVar23) &&
             (uVar23 = (uVar23 - _DAT_2ad99161318) + 1, uVar23 != 0)) {
            uVar34 = (ulonglong)uVar23;
            if (_DAT_2ad99161318 < 2) {
              if (*_DAT_2ad99183b2c == 0x47) goto LAB_2ad99141d70;
              uVar27 = 0;
              do {
                if (uVar34 - 1 == uVar27) goto LAB_2ad99141d6e;
                lVar15 = uVar27 + 1;
                uVar27 = uVar27 + 1;
              } while (_DAT_2ad99183b2c[lVar15] != 0x47);
              if (uVar27 < uVar34) {
LAB_2ad99142176:
                if (-1 < (int)uVar27) goto LAB_2ad99141d70;
              }
            }
            else {
              bVar41 = true;
              uVar23 = 1;
              uVar27 = 0;
              do {
                if (_DAT_2ad99183b2c[uVar27] == 0x47) {
                  psVar40 = (short *)&DAT_2ad9916131e;
                  lVar15 = (ulonglong)_DAT_2ad99161318 - 1;
                  uVar29 = uVar23;
                  while (_DAT_2ad99183b2c[uVar29] == *psVar40) {
                    psVar40 = psVar40 + 1;
                    uVar29 = uVar29 + 1;
                    lVar15 = lVar15 + -1;
                    if (lVar15 == 0) goto LAB_2ad99142159;
                  }
                  if ((int)lVar15 == 0) {
LAB_2ad99142159:
                    if (bVar41) goto LAB_2ad99142176;
                    break;
                  }
                }
                uVar27 = uVar27 + 1;
                uVar23 = uVar23 + 1;
                bVar41 = uVar27 < uVar34;
              } while (uVar27 != uVar34);
            }
          }
        }
        goto LAB_2ad99141d6e;
      }
      uVar34 = (ulonglong)uVar29;
      if (1 < _DAT_2ad99160e18) {
        bVar41 = true;
        uVar29 = 1;
        uVar27 = 0;
        do {
          if (_DAT_2ad99183b2c[uVar27] == 0x58) {
            psVar40 = (short *)&DAT_2ad99160e1e;
            lVar15 = (ulonglong)_DAT_2ad99160e18 - 1;
            uVar28 = uVar29;
            while (_DAT_2ad99183b2c[uVar28] == *psVar40) {
              psVar40 = psVar40 + 1;
              uVar28 = uVar28 + 1;
              lVar15 = lVar15 + -1;
              if (lVar15 == 0) goto LAB_2ad99142099;
            }
            if ((int)lVar15 == 0) {
LAB_2ad99142099:
              if (bVar41) goto LAB_2ad991420b6;
              break;
            }
          }
          uVar27 = uVar27 + 1;
          uVar29 = uVar29 + 1;
          bVar41 = uVar27 < uVar34;
        } while (uVar27 != uVar34);
        goto LAB_2ad99141d01;
      }
      if (*_DAT_2ad99183b2c != 0x58) {
        uVar27 = 0;
        do {
          if (uVar34 - 1 == uVar27) goto LAB_2ad99141d01;
          lVar15 = uVar27 + 1;
          uVar27 = uVar27 + 1;
        } while (_DAT_2ad99183b2c[lVar15] != 0x58);
        if (uVar27 < uVar34) {
LAB_2ad991420b6:
          if (-1 < (int)uVar27) goto LAB_2ad99141d70;
        }
        goto LAB_2ad99141d01;
      }
    }
LAB_2ad99141d70:
    unaff_RBP = &DAT_2ad99178400;
    unaff_R12 = &DAT_2ad99173054;
    DAT_2ad99173054 = DAT_2ad99183c48;
    local_68 = unaff_R15;
    iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,6);
    unaff_R15 = (code *)0x7ff63a0e49f0;
    if (iVar10 == 0) {
      if (DAT_2ad99183c28 != '\0') {
        in_stack_fffffffffffffe58 = 0x2ad991781d8;
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,2,0x590008,0x2ad991613f8,0x590008,0x2ad991781d8);
      }
      uVar16 = 0x28;
      if (DAT_2ad99178205 == '\0') {
        uVar16 = 0;
      }
      (*(code *)0x7ff63a0e7210)(0x2ad95e68178,uVar16);
      FUN_2ad99145ec0();
    }
    else {
      DAT_2ad99173054 = 0;
      DAT_2ad99178400 = 1;
      DAT_2ad99178410 = 1;
    }
    puVar32 = (undefined8 *)0x2ad99160ca0;
    (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x20);
    (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x1f);
    uVar23 = (*(code *)0x7ff63a102a30)(0x2ad95e68178,0x2ad99160ca0,0);
    pcVar12 = (code *)0x7ff63a0da0e0;
    unaff_RBX = (undefined8 *)(ulonglong)uVar23;
    (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178260,uVar23,0);
    (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad991782a0,uVar23,0);
    (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad991782e0,uVar23,0);
    (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178320,uVar23,0);
    (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178360,uVar23,0);
    lVar15 = _DAT_2ad9917827c;
    uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
    uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
    if ((_DAT_2ad99178262 & 0xf) != 0) {
      _DAT_2ad99178262 = _DAT_2ad99178262 | 0x10;
    }
    if ((_DAT_2ad991782a2 & 0xf) != 0) {
      _DAT_2ad991782a2 = _DAT_2ad991782a2 | 0x10;
    }
    if ((_DAT_2ad991782e2 & 0xf) != 0) {
      _DAT_2ad991782e2 = _DAT_2ad991782e2 | 0x10;
    }
    if ((_DAT_2ad99178322 & 0xf) != 0) {
      _DAT_2ad99178322 = _DAT_2ad99178322 | 0x10;
    }
    if ((_DAT_2ad99178362 & 0xf) != 0) {
      _DAT_2ad99178362 = _DAT_2ad99178362 | 0x10;
    }
    if (uVar23 != 0) {
      if (_DAT_2ad99178268 < uVar23) goto LAB_2ad99142204;
      uVar28 = 0;
      uVar29 = uVar23 + 0x7fffffff;
      if (0x80000002 < uVar29) {
        puVar13 = (undefined8 *)(_DAT_2ad9917827c + 0x10);
        uVar28 = uVar23 & 0xfffffffc;
        uVar23 = uVar28;
        do {
          puVar13[-2] = 0;
          puVar13[-1] = 0;
          *puVar13 = 0;
          puVar13[1] = 0;
          puVar13 = puVar13 + 4;
          uVar23 = uVar23 - 4;
          if (uVar23 == 0) goto LAB_2ad99142291;
        } while( true );
      }
      goto LAB_2ad99142284;
    }
  }
  uVar16 = CONCAT44(uVar24,1);
  uVar34 = CONCAT44(uVar9,2);
  in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
  _DAT_2ad9917846c =
       (*(code *)0x7ff63a0e49f0)
                 (0x2ad95e68178,0x58,6,0x590008,puVar32,0x520004,in_stack_fffffffffffffe58,0x520004,
                  DAT_2ad99173034,0x520004,0,0x520004,uVar34,0x520004,uVar16);
  uVar9 = (undefined4)(in_stack_fffffffffffffe58 >> 0x20);
  uVar24 = (undefined4)((ulonglong)uVar16 >> 0x20);
  if (_DAT_2ad9917846c == -1) {
    (*unaff_R15)(0x2ad95e68178,2,1,0x590008,0x2ad99161450);
  }
  uVar21 = 0xe;
  if (DAT_2ad9917301c == '\0') {
    uVar21 = 0;
  }
  _DAT_2ad99178470 =
       (*(code *)0x7ff63a0e49f0)
                 (0x2ad95e68178,0x67,7,0x590008,puVar32,0x520004,CONCAT44(uVar9,_DAT_2ad99183b24),
                  0x520004,uVar21,0x520004,0,0x520004,uVar34 & 0xffffffff00000000,0x520004,
                  CONCAT44(uVar24,(uint)DAT_2ad9917301d),0x580007,_DAT_2ad99173020);
  if (_DAT_2ad99178470 == -1) {
    (*unaff_R15)(0x2ad95e68178,2,1,0x590008,0x2ad99161450);
  }
  iVar10 = (*(code *)0x7ff63a101ec0)(0x2ad95e68178);
  lVar15 = (*(code *)0x7ff63a101d80)(0x2ad95e68178,0);
  lVar17 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  dVar42 = (double)(lVar15 - lVar17) / _DAT_2ad991606a8;
  uVar23 = (uint)((ulonglong)dVar42 >> 0x34) & 0x7ff;
  lVar15 = (ulonglong)uVar23 - 0x3ff;
  dVar43 = dVar42;
  if ((ulonglong)uVar23 < 0x433) {
    if (uVar23 < 0x3ff) {
      dVar43 = (double)((ulonglong)dVar42 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar15 != -1) {
        dVar43 = (double)((ulonglong)dVar42 & 0x8000000000000000);
      }
    }
    else {
      bVar20 = (byte)lVar15;
      if (((longlong)dVar42 << (bVar20 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar43 = (double)((0x8000000000000U >> (bVar20 & 0x3f)) + (longlong)dVar42 &
                         -0x10000000000000 >> (bVar20 & 0x3f));
      }
    }
  }
  else if (lVar15 == 0x400) {
    dVar43 = dVar42 + dVar42;
  }
  _DAT_2ad991781c4 = (int)dVar43 * 0xe10 + iVar10;
  iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178);
  if (iVar10 != 0) {
    _DAT_2ad991781c4 = 0;
  }
  DAT_2ad991781d0 = '\0';
  if (*unaff_R12 != '\0') {
    _DAT_2ad991781c8 = (*(code *)0x7ff63a101d80)(0x2ad95e68178);
    FUN_2ad99148330();
    if ((DAT_2ad99183de8 != '\0') && (_DAT_2ad99183df4 != (short *)&DAT_2ad99160d00)) {
      if (_DAT_2ad99183df4 != (short *)0x0) {
        uVar23 = *(uint *)(_DAT_2ad99183df4 + -2);
        uVar29 = _DAT_2ad99160cfc;
        if (uVar23 < _DAT_2ad99160cfc) {
          uVar29 = uVar23;
        }
        iVar10 = uVar23 - _DAT_2ad99160cfc;
        if (uVar29 != 0) {
          uVar34 = 0;
          do {
            uVar3 = _DAT_2ad99183df4[uVar34];
            uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar34 * 2);
            uVar34 = uVar34 + 1;
            if (uVar29 <= uVar34) break;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar10 = (uint)uVar3 - (uint)uVar4;
          }
        }
        if (iVar10 == 0) goto LAB_2ad99142a6a;
      }
      sVar39 = 0x2c;
      if (_DAT_2ad99161464 == 0) {
        sVar39 = 0;
        _DAT_2ad99183b10 = 0x13b1;
      }
      uVar9 = 0x13c7;
      if (_DAT_2ad99178190 == 0x59) {
        lVar15 = 0;
        do {
          if (*(int *)(&DAT_2ad9917819c + lVar15 * 4) == 0) {
            uVar9 = 0xfa6;
            if (lVar15 != 0) goto LAB_2ad991428f4;
            uVar34 = 0;
            if ((_DAT_2ad99183df4 == (short *)0x0) || (*_DAT_2ad99183df4 == 0))
            goto LAB_2ad99143247;
            local_104 = *(uint *)(_DAT_2ad99183df4 + -2);
            uVar34 = 0;
            local_128 = CONCAT44(local_128._4_4_,_DAT_2ad99178198);
            lVar15 = _DAT_2ad991781ac;
            psVar40 = _DAT_2ad99183df4;
            goto LAB_2ad99143054;
          }
          lVar15 = lVar15 + 1;
        } while (lVar15 != 3);
        uVar9 = 0xfa6;
      }
LAB_2ad991428f4:
      uVar34 = 0xffffffff;
      _DAT_2ad99183b10 = uVar9;
      goto LAB_2ad99142906;
    }
    goto LAB_2ad99142a6a;
  }
  goto LAB_2ad99142aa2;
LAB_2ad99143054:
  uVar27 = 0xffffffff;
  uVar23 = 0;
  do {
    uVar29 = uVar23;
    iVar10 = (int)uVar27;
    uVar28 = iVar10 + 1;
    uVar27 = (ulonglong)uVar28;
    if (psVar40[uVar27] == 0) break;
    uVar23 = uVar29 + 1;
  } while (psVar40[uVar27] != sVar39);
  if (0x7ffffffe < uVar28) {
    if ((_DAT_2ad99178192 & 1) != 0) {
      (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&DAT_2ad99178190);
    }
    uVar34 = 0xffffffff;
    _DAT_2ad99183b10 = 0x13b0;
    goto LAB_2ad99142906;
  }
  uVar23 = (uint)uVar34;
  if ((uint)local_128 <= uVar23) {
    if ((_DAT_2ad99178192 & 1) == 0) {
      uVar34 = 0xffffffff;
      _DAT_2ad99183b10 = 0xfa7;
      goto LAB_2ad99142906;
    }
    uVar35 = local_104;
    if (uVar28 != 0) {
      uVar35 = local_104 / uVar28;
    }
    uVar35 = uVar23 + 1 + uVar35;
    local_128 = CONCAT44(local_128._4_4_,uVar35);
    iVar11 = (*pcVar12)(0x2ad95e68178,&DAT_2ad99178190,uVar35,0x20 - (uVar35 & 0x1f));
    lVar15 = _DAT_2ad991781ac;
    if (iVar11 < 0) {
      uVar34 = 0xffffffff;
      goto LAB_2ad99142906;
    }
  }
  puVar22 = *(undefined4 **)(lVar15 + 4 + uVar34 * 0xc);
  puVar1 = (undefined4 *)(lVar15 + uVar34 * 0xc);
  puVar26 = puVar22 + -3;
  if (puVar22 == (undefined4 *)0x0) {
    puVar26 = (uint *)0x0;
  }
  if ((*(int *)(lVar15 + uVar34 * 0xc) == 0) || (puVar26 == (uint *)0x0)) {
LAB_2ad9914315e:
    puVar19 = (undefined4 *)(*(code *)0x7ff63a101190)(0x2ad95e68178);
    if (puVar19 != (undefined4 *)0x0) {
      puVar22 = puVar19 + 3;
      *(undefined8 *)(puVar19 + 1) = 1;
      *(undefined2 *)(puVar19 + 3) = 0;
      *(undefined4 **)(puVar1 + 1) = puVar22;
      *puVar1 = *puVar19;
      goto LAB_2ad99143196;
    }
    _DAT_2ad99183b10 = 0x13aa;
  }
  else {
    if ((*puVar26 < uVar28) || (puVar26[1] != 1)) {
      if (*puVar26 != 0) {
        puVar26 = puVar26 + 1;
        *puVar26 = *puVar26 - 1;
        if (*puVar26 == 0) {
          (*(code *)0x7ff63a101200)(0x2ad95e68178);
        }
      }
      *(undefined8 *)(puVar1 + 1) = 0;
      *puVar1 = 0;
      goto LAB_2ad9914315e;
    }
LAB_2ad99143196:
    if (uVar28 != 0) {
      if (uVar28 < 8) {
        uVar34 = 0;
      }
      else {
        uVar34 = 0;
        if (0x1f < (ulonglong)((longlong)puVar22 - (longlong)psVar40)) {
          uVar37 = 0;
          uVar34 = (ulonglong)(uVar28 & 0x7ffffff8);
          do {
            uVar16 = *(undefined8 *)(psVar40 + uVar37 + 4);
            puVar32 = (undefined8 *)((longlong)puVar22 + uVar37 * 2);
            *puVar32 = *(undefined8 *)(psVar40 + uVar37);
            puVar32[1] = uVar16;
            uVar37 = uVar37 + 8;
          } while ((uVar29 & 0x7ffffff8) != uVar37);
          if (uVar34 == uVar27) goto LAB_2ad99143222;
        }
      }
      do {
        *(short *)((longlong)puVar22 + uVar34 * 2) = psVar40[uVar34];
        uVar34 = uVar34 + 1;
      } while (uVar29 != uVar34);
    }
LAB_2ad99143222:
    puVar22[-1] = uVar28;
    *(undefined2 *)((longlong)puVar22 + uVar27 * 2) = 0;
  }
  uVar34 = (ulonglong)(uVar23 + 1);
  if (psVar40[uVar27] == 0) goto LAB_2ad99143247;
  psVar40 = psVar40 + (iVar10 + 2);
  goto LAB_2ad99143054;
LAB_2ad99143247:
  if ((_DAT_2ad99178192 & 1) != 0) {
    (*pcVar12)(0x2ad95e68178,&DAT_2ad99178190,uVar34,0);
  }
LAB_2ad99142906:
  uVar23 = 0;
  (*pcVar12)(0x2ad95e68178,&DAT_2ad99178190,uVar34,0);
  if (0 < (int)(uint)uVar34) {
    do {
      if (_DAT_2ad99178198 <= uVar23) {
LAB_2ad99145bfb:
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x25011a000001f6);
        goto LAB_2ad99145c1b;
      }
      uVar37 = (ulonglong)uVar23;
      uVar27 = (ulonglong)_DAT_2ad99178198 + ~uVar37;
      if ((_DAT_2ad99178192 & 0x10) == 0) {
        uVar27 = uVar37;
      }
      lVar15 = *(longlong *)(_DAT_2ad991781ac + 4 + uVar27 * 0xc);
      if ((lVar15 == 0) || (lVar15 == 0xc)) {
        _DAT_2ad99183b10 = 0xfa9;
      }
      else {
        uVar29 = *(uint *)(lVar15 + -4);
        uVar25 = (ulonglong)uVar29;
        if (uVar25 != 0) {
          lVar17 = _DAT_2ad991781ac + uVar27 * 0xc;
          lVar2 = uVar25 * 2;
          lVar18 = 0;
          do {
            uVar27 = (ulonglong)*(ushort *)(lVar15 + -2 + lVar2 + lVar18 * 2);
            if ((0x20 < uVar27) || ((0x100002600U >> (uVar27 & 0x3f) & 1) == 0)) {
              if ((int)lVar18 == 0) goto LAB_2ad99142a10;
              uVar28 = -(int)lVar18;
              break;
            }
            lVar18 = lVar18 + -1;
            uVar35 = (int)uVar25 - 1;
            uVar25 = (ulonglong)uVar35;
            uVar28 = uVar29;
          } while (uVar35 != 0);
          uVar29 = uVar29 - uVar28;
          cVar7 = FUN_2ad99140060(lVar17,uVar29);
          if (cVar7 != '\0') {
            lVar15 = *(longlong *)(lVar17 + 4);
            *(uint *)(lVar15 + -4) = uVar29;
            *(undefined2 *)(lVar15 + (ulonglong)uVar29 * 2) = 0;
          }
        }
      }
LAB_2ad99142a10:
      if (_DAT_2ad99178198 <= uVar23) {
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x24011b000001f6);
        goto LAB_2ad99145bfb;
      }
      uVar27 = (ulonglong)_DAT_2ad99178198 + ~uVar37;
      if ((_DAT_2ad99178192 & 0x10) == 0) {
        uVar27 = uVar37;
      }
      FUN_2ad99140cf0(uVar27 * 0xc + _DAT_2ad991781ac);
      uVar23 = uVar23 + 1;
    } while (uVar23 != (uint)uVar34);
  }
LAB_2ad99142a6a:
  FUN_2ad99149770();
  DAT_2ad991781d0 = FUN_2ad9914c430();
  pcVar38 = FUN_2ad99140a40;
  unaff_RBP = &DAT_2ad99178400;
LAB_2ad99142aa2:
  uVar16 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  (*(code *)0x7ff63a101f60)(0x2ad95e68178,uVar16);
  if (local_44 != _DAT_2ad99178404) {
    _DAT_2ad99178404 = local_44;
  }
  (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x25);
  cVar7 = DAT_2ad99183c90;
  if ((*unaff_RBP != '\0') || (DAT_2ad99183c90 == '\0')) {
LAB_2ad99145878:
    local_a0 = 0;
    local_a8 = 0;
    local_f4 = 0;
    pcVar12 = local_68;
    if ((cVar7 != '\0') && (*unaff_RBP == '\0')) {
LAB_2ad991458ac:
      pcVar12 = local_68;
      local_a0 = 0;
      local_a8 = 0;
      local_f4 = 0;
      FUN_2ad9914c6f0(&local_a0,&local_a8,&local_f4);
    }
    FUN_2ad9914ccb0(local_a0,local_a8);
    (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,pcVar12,0,0x20);
    (*pcVar38)(&local_98,0x2ad99183b3c,1,0x2ad99164828);
    (*pcVar38)(&local_100,0x2ad991614c8,0);
    lVar15 = local_94;
    if (local_94 == 0) goto LAB_2ad99145a5d;
    uVar23 = *(uint *)(local_94 + -4);
    uVar34 = (ulonglong)uVar23;
    if ((uVar34 == 0) && (local_fc != 0)) goto LAB_2ad99145a5d;
    if (local_fc == 0) {
      uVar29 = 0;
      uVar28 = uVar23;
    }
    else {
      uVar29 = *(uint *)(local_fc + -4);
      uVar28 = uVar23 + uVar29;
    }
    cVar7 = FUN_2ad99140060(&local_100);
    if (cVar7 == '\0') {
LAB_2ad99145c1b:
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2c0139000001f9);
      goto LAB_2ad99145c3b;
    }
    if (uVar34 != 0) {
      lVar17 = local_fc + (ulonglong)uVar29 * 2;
      if (uVar23 < 0x10) {
        uVar27 = 0;
      }
      else if ((ulonglong)(lVar17 - lVar15) < 0x20) {
        uVar27 = 0;
      }
      else {
        uVar37 = 0;
        uVar27 = (ulonglong)(uVar23 & 0xfffffff8);
        do {
          uVar16 = ((undefined8 *)(lVar15 + uVar37))[1];
          *(undefined8 *)(lVar17 + uVar37) = *(undefined8 *)(lVar15 + uVar37);
          ((undefined8 *)(lVar17 + uVar37))[1] = uVar16;
          uVar37 = uVar37 + 0x10;
        } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
        if (uVar27 == uVar34) goto LAB_2ad99145a52;
      }
      do {
        *(undefined2 *)(lVar17 + uVar27 * 2) = *(undefined2 *)(lVar15 + uVar27 * 2);
        uVar27 = uVar27 + 1;
      } while (uVar34 != uVar27);
    }
LAB_2ad99145a52:
    *(uint *)(local_fc + -4) = uVar28;
    *(undefined2 *)(local_fc + (ulonglong)uVar28 * 2) = 0;
LAB_2ad99145a5d:
    (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_100);
    FUN_2ad99140000(&local_98);
    FUN_2ad99140000(&local_100);
    FUN_2ad99140000(&local_78);
    FUN_2ad99140000(&local_f0);
    FUN_2ad99140000(&local_e0);
    return 0;
  }
  if (DAT_2ad991784d6 == '\x01') goto LAB_2ad991458ac;
  local_104 = CONCAT31(local_104._1_3_,DAT_2ad99183c90);
  uVar23 = 0;
  local_c0 = 0;
  local_138 = 0;
  local_148 = 0;
  local_d0 = 0;
  local_bc = 0;
  local_134 = 0;
  local_144 = 0;
  local_cc = 0;
  _DAT_2ad991784d8 = 10;
  if (DAT_2ad991784ec == '\0') {
    _DAT_2ad991784d8 = uVar23;
  }
  _DAT_2ad991784dc = 0x14;
  if (DAT_2ad991784ed == '\0') {
    _DAT_2ad991784dc = uVar23;
  }
  FUN_2ad99154d40();
  local_120 = 0;
  local_11c = 0;
  (*pcVar38)(&local_120,0x2ad991784e0,0,0x2ad991716e0);
  uVar28 = _DAT_2ad991784dc;
  local_128 = (longlong)(int)_DAT_2ad991784d8;
  lVar15 = (longlong)(int)_DAT_2ad991784dc;
  local_88 = 0;
  local_84 = 0;
  (*pcVar38)(&local_148,&local_120,0,0x2ad991716f0);
  uVar29 = _DAT_2ad99161028;
  uVar34 = (ulonglong)_DAT_2ad99161028;
  if ((uVar34 == 0) && (local_144 != 0)) {
LAB_2ad99142dbd:
    (*pcVar38)(&local_88,&local_148,0,0x2ad99171700);
    iVar10 = (*(code *)0x7ff63a0f4840)(0x2ad95e68178,0,&local_88);
    if (-1 < iVar10) {
      (*(code *)0x7ff63a0f4ce0)(0x2ad95e68178,0,&local_88);
    }
    (*(code *)0x7ff63a0e49f0)
              (0x2ad95e68178,0x112,6,0x550005,0,0x590008,&local_88,0x520004,0x6a,0x520004,0,0x540005
               ,0,0x580007,0);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,0x3f4,local_128);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,0x3f5,lVar15);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,0x3f3,0);
    (*pcVar38)(&local_148,0x2ad99163978,0);
    lVar15 = _DAT_2ad99173004;
    if (_DAT_2ad99173004 != 0) {
      uVar23 = *(uint *)(_DAT_2ad99173004 + -4);
      uVar34 = (ulonglong)uVar23;
      if ((uVar34 == 0) && (local_144 != 0)) goto LAB_2ad991432d9;
      if (local_144 == 0) {
        uVar29 = 0;
        uVar35 = uVar23;
      }
      else {
        uVar29 = *(uint *)(local_144 + -4);
        uVar35 = uVar23 + uVar29;
      }
      cVar7 = FUN_2ad99140060(&local_148);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar17 = local_144 + (ulonglong)uVar29 * 2;
          if (uVar23 < 0x10) {
            uVar27 = 0;
          }
          else if ((ulonglong)(lVar17 - lVar15) < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar23 & 0xfffffff8);
            do {
              uVar16 = ((undefined8 *)(lVar15 + uVar37))[1];
              *(undefined8 *)(lVar17 + uVar37) = *(undefined8 *)(lVar15 + uVar37);
              ((undefined8 *)(lVar17 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991432c2;
          }
          do {
            *(undefined2 *)(lVar17 + uVar27 * 2) = *(undefined2 *)(lVar15 + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991432c2:
        pcVar38 = FUN_2ad99140a40;
        *(uint *)(local_144 + -4) = uVar35;
        *(undefined2 *)(local_144 + (ulonglong)uVar35 * 2) = 0;
        goto LAB_2ad991432d9;
      }
      goto LAB_2ad99145e5b;
    }
LAB_2ad991432d9:
    (*(code *)0x7ff63a0f3c80)(0x2ad95e68178,0,&local_88,0x3f9,&local_148);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,3,0);
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,0xcf,0x3e6);
    uVar24 = 0;
    (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,&local_88,10,0);
    bVar20 = DAT_2ad991784fc;
    uVar9 = 0xeaeaea;
    if (DAT_2ad991784fd == 0) {
      uVar9 = 0;
    }
    FUN_2ad9915e0a0(0);
    (*pcVar38)(&local_148,0x2ad99183b3c,1,0x2ad99171720);
    (*pcVar38)(&local_138,&local_120,0,0x2ad99171730);
    uVar23 = _DAT_2ad99161058;
    uVar34 = (ulonglong)_DAT_2ad99161058;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 == 0) {
        uVar29 = 0;
        uVar35 = _DAT_2ad99161058;
      }
      else {
        uVar29 = *(uint *)(local_134 + -4);
        uVar35 = _DAT_2ad99161058 + uVar29;
      }
      uVar30 = 0x104;
      if ((0x103 < uVar35) &&
         ((0x7ffffffd < uVar35 || (uVar30 = (uVar35 >> 2) + uVar35, 0x7ffffffd < uVar30)))) {
        uVar30 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar30);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar29 * 2;
          if (uVar23 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916105cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar23 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161064);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916105c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991434e2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916105c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991434e2:
        *(uint *)(local_134 + -4) = uVar35;
        *(undefined2 *)(local_134 + (ulonglong)uVar35 * 2) = 0;
        goto LAB_2ad991434ef;
      }
      goto LAB_2ad99145c5b;
    }
LAB_2ad991434ef:
    uVar16 = CONCAT44(uVar24,uVar9);
    FUN_2ad9915ea70(&local_138,&local_148,(int)local_128 + 0x8c,uVar28 + 0x4f,uVar16,
                    (bVar20 & 1) * '\t');
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar23 = 0;
    uVar29 = 0xeaeaea;
    if (DAT_2ad991784fd == 0) {
      uVar29 = uVar23;
    }
    FUN_2ad9915e660(0);
    (*pcVar38)(&local_148,0x2ad99183b3c,1,0x2ad99171740);
    (*pcVar38)(&local_138,&local_120,0,0x2ad99171750);
    uVar35 = _DAT_2ad99161088;
    uVar34 = (ulonglong)_DAT_2ad99161088;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar31 = _DAT_2ad99161088 + uVar23;
      uVar30 = 0x104;
      if ((0x103 < uVar31) &&
         ((0x7ffffffd < uVar31 || (uVar30 = (uVar31 >> 2) + uVar31, 0x7ffffffd < uVar30)))) {
        uVar30 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar30);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar35 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916108cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar35 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161094);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916108c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991436b2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916108c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991436b2:
        *(uint *)(local_134 + -4) = uVar31;
        *(undefined2 *)(local_134 + (ulonglong)uVar31 * 2) = 0;
        goto LAB_2ad991436bd;
      }
      goto LAB_2ad99145c7b;
    }
LAB_2ad991436bd:
    uVar16 = CONCAT44(uVar9,uVar29);
    FUN_2ad9915ea70(&local_138,&local_148,(int)local_128 + 0x7d,uVar28 + 100,uVar16,
                    (bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    local_110 = 0;
    local_10c = 0;
    if (DAT_2ad991781d0 == '\0') {
      uVar16 = 0x2ad991638e0;
      uVar36 = 0x2ad99171570;
    }
    else {
      uVar16 = 0x2ad99163910;
      uVar36 = 0x2ad99171580;
    }
    (*pcVar38)(&local_110,uVar16,0,uVar36);
    (*pcVar38)(0x2ad99183b3c,&local_110,1,0x2ad99171590);
    FUN_2ad99140000(&local_110);
    (*pcVar38)(&local_148,0x2ad99183b3c,1,0x2ad99171760);
    uVar23 = 0;
    (*pcVar38)(&local_138,&local_120,0,0x2ad99171770);
    uVar29 = _DAT_2ad991610a8;
    uVar34 = (ulonglong)_DAT_2ad991610a8;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar30 = _DAT_2ad991610a8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991610acU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991610b4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991610ac + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991438f2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991610ac + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991438f2:
        *(uint *)(local_134 + -4) = uVar30;
        *(undefined2 *)(local_134 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad991438ff;
      }
      goto LAB_2ad99145c9b;
    }
LAB_2ad991438ff:
    uVar23 = 0;
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_138,&local_148,(int)local_128 + 0x93,uVar28 + 0x79,uVar16,
                    (bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar16 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x12);
    (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,uVar16,0,0x20);
    FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad99171780);
    FUN_2ad99140a40(&local_138,&local_120,0,0x2ad99171790);
    uVar29 = _DAT_2ad991610c8;
    uVar34 = (ulonglong)_DAT_2ad991610c8;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar30 = _DAT_2ad991610c8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991610ccU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991610d4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991610cc + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99143b02;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991610cc + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99143b02:
        *(uint *)(local_134 + -4) = uVar30;
        *(undefined2 *)(local_134 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad99143b0d;
      }
      goto LAB_2ad99145cbb;
    }
LAB_2ad99143b0d:
    uVar23 = 0;
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    iVar10 = (int)local_128 + 0xa7;
    FUN_2ad9915ea70(&local_138,&local_148,iVar10,uVar28 + 0x8e,uVar16,(bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar16 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
    FUN_2ad9915d030(uVar16);
    FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad991717a0);
    FUN_2ad99140a40(&local_138,&local_120,0,0x2ad991717b0);
    uVar29 = _DAT_2ad991610f8;
    uVar34 = (ulonglong)_DAT_2ad991610f8;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar30 = _DAT_2ad991610f8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991610fcU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161104);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991610fc + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99143d02;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991610fc + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99143d02:
        *(uint *)(local_134 + -4) = uVar30;
        *(undefined2 *)(local_134 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad99143d0f;
      }
      goto LAB_2ad99145cdb;
    }
LAB_2ad99143d0f:
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_138,&local_148,iVar10,uVar28 + 0xa3,uVar16,(bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    local_110 = 0;
    local_10c = 0;
    if (DAT_2ad99183c30 == '\0') {
      uVar16 = 0x2ad991638a8;
      uVar36 = 0x2ad99171550;
    }
    else {
      uVar16 = 0x2ad99163878;
      uVar36 = 0x2ad99171540;
    }
    FUN_2ad99140a40(&local_110,uVar16,0,uVar36);
    FUN_2ad99140a40(0x2ad99183b3c,&local_110,1,0x2ad99171560);
    FUN_2ad99140000(&local_110);
    FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad991717c0);
    uVar23 = 0;
    FUN_2ad99140a40(&local_138,&local_120,0,0x2ad991717d0);
    uVar29 = _DAT_2ad99161128;
    uVar34 = (ulonglong)_DAT_2ad99161128;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar30 = _DAT_2ad99161128 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916112cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161134);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916112c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99143f52;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916112c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99143f52:
        *(uint *)(local_134 + -4) = uVar30;
        *(undefined2 *)(local_134 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad99143f5f;
      }
      goto LAB_2ad99145cfb;
    }
LAB_2ad99143f5f:
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_138,&local_148,iVar10,uVar28 + 0xb8,uVar16,(bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    local_110 = 0;
    local_10c = 0;
    if (DAT_2ad99183c28 == '\0') {
      uVar16 = 0x2ad991638a8;
      uVar36 = 0x2ad99171550;
    }
    else {
      uVar16 = 0x2ad99163878;
      uVar36 = 0x2ad99171540;
    }
    FUN_2ad99140a40(&local_110,uVar16,0,uVar36);
    FUN_2ad99140a40(0x2ad99183b3c,&local_110,1,0x2ad99171560);
    FUN_2ad99140000(&local_110);
    FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad991717e0);
    uVar23 = 0;
    FUN_2ad99140a40(&local_138,&local_120,0,0x2ad991717f0);
    uVar29 = _DAT_2ad99161148;
    uVar34 = (ulonglong)_DAT_2ad99161148;
    if ((uVar34 != 0) || (local_134 == 0)) {
      if (local_134 != 0) {
        uVar23 = *(uint *)(local_134 + -4);
      }
      uVar30 = _DAT_2ad99161148 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_138,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_134 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916114cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161154);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916114c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991441a2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916114c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991441a2:
        *(uint *)(local_134 + -4) = uVar30;
        *(undefined2 *)(local_134 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad991441af;
      }
      goto LAB_2ad99145d1b;
    }
LAB_2ad991441af:
    uVar23 = 0;
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_138,&local_148,(int)local_128 + 0xc5,uVar28 + 0xcd,uVar16,
                    (bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171800);
    uVar29 = _DAT_2ad991611c8;
    uVar34 = (ulonglong)_DAT_2ad991611c8;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad991611c8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991611ccU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991611d4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991611cc + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99144342;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991611cc + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99144342:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad9914434d;
      }
      goto LAB_2ad99145d3b;
    }
LAB_2ad9914434d:
    uVar23 = 0;
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    iVar10 = (int)local_128 + 0x14;
    FUN_2ad9915ea70(&local_148,0x2ad991639a8,iVar10,uVar28 + 0x10d,uVar16,(bVar20 & 1) * 9 + -2);
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171810);
    uVar29 = _DAT_2ad99161168;
    uVar34 = (ulonglong)_DAT_2ad99161168;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad99161168 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916116cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161174);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916116c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991444f2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916116c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991444f2:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad991444ff;
      }
      goto LAB_2ad99145d5b;
    }
LAB_2ad991444ff:
    uVar23 = 0;
    uVar29 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar29 = uVar23;
    }
    uVar16 = CONCAT44(uVar9,uVar29);
    FUN_2ad9915ea70(&local_148,0x2ad991639a8,iVar10,uVar28 + 0x11c,uVar16,(bVar20 & 1) * 9 + -2);
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171820);
    uVar29 = _DAT_2ad99161188;
    uVar34 = (ulonglong)_DAT_2ad99161188;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad99161188 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916118cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161194);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916118c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad991446a2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916118c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad991446a2:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad991446af;
      }
      goto LAB_2ad99145d7b;
    }
LAB_2ad991446af:
    uVar23 = 0;
    uVar29 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar29 = uVar23;
    }
    uVar16 = CONCAT44(uVar9,uVar29);
    FUN_2ad9915ea70(&local_148,0x2ad991639a8,iVar10,uVar28 + 0x129,uVar16,(bVar20 & 1) * 9 + -2);
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171830);
    uVar29 = _DAT_2ad991611a8;
    uVar34 = (ulonglong)_DAT_2ad991611a8;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad991611a8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991611acU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991611b4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991611ac + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99144852;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991611ac + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99144852:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad9914485f;
      }
      goto LAB_2ad99145d9b;
    }
LAB_2ad9914485f:
    uVar23 = 0;
    uVar29 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar29 = uVar23;
    }
    uVar16 = CONCAT44(uVar9,uVar29);
    FUN_2ad9915ea70(&local_148,0x2ad991639a8,iVar10,uVar28 + 0x137,uVar16,(bVar20 & 1) * 9 + -2);
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    cVar7 = DAT_2ad99178210;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171840);
    uVar29 = _DAT_2ad991611e8;
    uVar34 = (ulonglong)_DAT_2ad991611e8;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad991611e8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar8 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar8 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991611ecU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991611f4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991611ec + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99144a02;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991611ec + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99144a02:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad99144a0d;
      }
      goto LAB_2ad99145dbb;
    }
LAB_2ad99144a0d:
    uVar16 = 0x2ad991639f0;
    if (cVar7 == '\0') {
      uVar16 = 0x2ad99163a30;
    }
    uVar34 = 0;
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar36 = CONCAT44(uVar9,uVar24);
    iVar10 = (int)local_128 + 100;
    FUN_2ad9915ea70(&local_148,uVar16,iVar10,uVar28 + 0x191,uVar36,(bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar36 >> 0x20);
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171850);
    uVar23 = _DAT_2ad99161218;
    uVar27 = (ulonglong)_DAT_2ad99161218;
    if ((uVar27 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar34 = (ulonglong)*(uint *)(local_144 + -4);
      }
      uVar35 = _DAT_2ad99161218 + (int)uVar34;
      uVar29 = 0x104;
      if ((0x103 < uVar35) &&
         ((0x7ffffffd < uVar35 || (uVar29 = (uVar35 >> 2) + uVar35, 0x7ffffffd < uVar29)))) {
        uVar29 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar29);
      if (cVar7 != '\0') {
        if (uVar27 != 0) {
          lVar15 = local_144 + uVar34 * 2;
          if (uVar23 < 0x10) {
            uVar34 = 0;
          }
          else if (lVar15 - 0x2ad9916121cU < 0x20) {
            uVar34 = 0;
          }
          else {
            uVar37 = 0;
            uVar34 = (ulonglong)(uVar23 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161224);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916121c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar27 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar34 == uVar27) goto LAB_2ad99144bc2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar34 * 2) = *(undefined2 *)(&DAT_2ad9916121c + uVar34 * 2);
            uVar34 = uVar34 + 1;
          } while (uVar27 != uVar34);
        }
LAB_2ad99144bc2:
        *(uint *)(local_144 + -4) = uVar35;
        *(undefined2 *)(local_144 + (ulonglong)uVar35 * 2) = 0;
        goto LAB_2ad99144bcf;
      }
      goto LAB_2ad99145ddb;
    }
LAB_2ad99144bcf:
    uVar24 = 0xeaeaea;
    if ((bVar5 & 1) == 0) {
      uVar24 = 0;
    }
    uVar16 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_148,0x2ad99178218,iVar10,uVar28 + 0x1a6,uVar16,(bVar20 & 1) * '\t');
    bVar5 = DAT_2ad991784fd;
    bVar20 = DAT_2ad991784fc;
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    iVar11 = 0;
    if (_DAT_2ad9917823c != &DAT_2ad99163a4c) {
      if (_DAT_2ad9917823c == (undefined1 *)0x0) {
        iVar11 = 1;
      }
      else {
        uVar23 = *(uint *)(_DAT_2ad9917823c + -4);
        uVar29 = _DAT_2ad99163a48;
        if (uVar23 < _DAT_2ad99163a48) {
          uVar29 = uVar23;
        }
        iVar11 = uVar23 - _DAT_2ad99163a48;
        if (uVar29 != 0) {
          uVar34 = 0;
          do {
            uVar3 = *(ushort *)(_DAT_2ad9917823c + uVar34 * 2);
            uVar4 = *(ushort *)(&DAT_2ad99163a4c + uVar34 * 2);
            uVar34 = uVar34 + 1;
            if (uVar29 <= uVar34) break;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar11 = (uint)uVar3 - (uint)uVar4;
          }
        }
      }
    }
    uVar23 = 0;
    FUN_2ad99140a40(&local_148,&local_120,0,0x2ad99171860);
    uVar29 = _DAT_2ad99161248;
    uVar34 = (ulonglong)_DAT_2ad99161248;
    if ((uVar34 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad99161248 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad9916124cU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161254);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916124c + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99144df2;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916124c + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99144df2:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad99144dff;
      }
      goto LAB_2ad99145dfb;
    }
LAB_2ad99144dff:
    uVar16 = 0x2ad99178238;
    if (iVar11 == 0) {
      uVar16 = 0x2ad99163a68;
    }
    uVar24 = 0;
    if ((bVar5 & 1) != 0) {
      uVar24 = 0xeaeaea;
    }
    uVar36 = CONCAT44(uVar9,uVar24);
    FUN_2ad9915ea70(&local_148,uVar16,iVar10,uVar28 + 0x1bb,uVar36,(bVar20 & 1) * '\t');
    bVar20 = DAT_2ad991784fc;
    uVar24 = (undefined4)((ulonglong)uVar36 >> 0x20);
    uVar9 = 0;
    if (DAT_2ad991784fd != 0) {
      uVar9 = 0xeaeaea;
    }
    puVar22 = (undefined4 *)0x2ad99163a68;
    if (_DAT_2ad99178248 < 1) {
LAB_2ad9914502f:
      uVar23 = 0;
      FUN_2ad99140a40(&local_c0,&local_120,0,0x2ad99171880);
      uVar29 = _DAT_2ad99161278;
      uVar34 = (ulonglong)_DAT_2ad99161278;
      if ((uVar34 != 0) || (local_bc == 0)) {
        if (local_bc != 0) {
          uVar23 = *(uint *)(local_bc + -4);
        }
        uVar30 = _DAT_2ad99161278 + uVar23;
        uVar35 = 0x104;
        if ((0x103 < uVar30) &&
           ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
          uVar35 = 0x7ffffffe;
        }
        cVar7 = FUN_2ad99140060(&local_c0,uVar35);
        if (cVar7 != '\0') {
          if (uVar34 != 0) {
            lVar15 = local_bc + (ulonglong)uVar23 * 2;
            if (uVar29 < 0x10) {
              uVar27 = 0;
            }
            else if (lVar15 - 0x2ad9916127cU < 0x20) {
              uVar27 = 0;
            }
            else {
              uVar37 = 0;
              uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
              do {
                uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161284);
                *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad9916127c + uVar37);
                ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
                uVar37 = uVar37 + 0x10;
              } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
              if (uVar27 == uVar34) goto LAB_2ad99145162;
            }
            do {
              *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916127c + uVar27 * 2);
              uVar27 = uVar27 + 1;
            } while (uVar34 != uVar27);
          }
LAB_2ad99145162:
          *(uint *)(local_bc + -4) = uVar30;
          *(undefined2 *)(local_bc + (ulonglong)uVar30 * 2) = 0;
          goto LAB_2ad9914516f;
        }
        goto LAB_2ad99145e1b;
      }
LAB_2ad9914516f:
      uVar16 = CONCAT44(uVar24,uVar9);
      FUN_2ad9915ea70(&local_c0,puVar22,iVar10,uVar28 + 0x1d0,uVar16,(uint)bVar20 + (uint)bVar20 * 8
                     );
      uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
      local_d0 = 0;
      local_cc = 0;
      FUN_2ad99140a40(&local_d0,0x2ad99160d08,0,0x2ad99171890);
      if (((_DAT_2ad9917822c != (undefined1 *)0x0) && (_DAT_2ad9917822c != (undefined1 *)0xc)) &&
         (uVar23 = *(uint *)(_DAT_2ad9917822c + -4), 0x1d < (int)uVar23)) {
        if (_DAT_2ad9916303c == 0) {
          _DAT_2ad99183b10 = 0x13ab;
          uVar29 = 0xffffffff;
LAB_2ad991452c5:
          uVar27 = (ulonglong)(uVar29 + uVar23);
          uVar35 = uVar29;
          if (-1 < (int)(uVar29 + uVar23)) goto LAB_2ad991452cf;
LAB_2ad991452f4:
          _DAT_2ad99183b10 = 0x13ab;
          if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
            _DAT_2ad99183b10 = 0xfa9;
          }
          else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                  (cVar7 = FUN_2ad99140060(0x2ad99183b3c,0), puVar6 = _DAT_2ad99183b40,
                  cVar7 != '\0')) {
            *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
            *puVar6 = 0;
          }
        }
        else {
          uVar29 = 0xffffffff;
          if (((_DAT_2ad9917822c == &DAT_2ad99163040) || (uVar23 - 0x14 < _DAT_2ad9916303c)) ||
             (uVar35 = ((uVar23 - 0x14) - _DAT_2ad9916303c) + 1, uVar35 == 0)) goto LAB_2ad991452c5;
          local_b0 = (ulonglong)uVar35;
          if (_DAT_2ad9916303c != 1) {
            bVar41 = true;
            uVar35 = 1;
            uVar34 = 0;
            do {
              if (*(short *)(_DAT_2ad9917822c + uVar34 * 2 + 0x28) == 0x20) {
                psVar40 = (short *)&DAT_2ad99163042;
                lVar15 = (ulonglong)_DAT_2ad9916303c - 1;
                uVar30 = uVar35;
                while (*(short *)(_DAT_2ad9917822c + (ulonglong)uVar30 * 2 + 0x28) == *psVar40) {
                  psVar40 = psVar40 + 1;
                  uVar30 = uVar30 + 1;
                  lVar15 = lVar15 + -1;
                  if (lVar15 == 0) goto LAB_2ad99145b30;
                }
                if ((int)lVar15 == 0) {
LAB_2ad99145b30:
                  if (bVar41) goto LAB_2ad99145b44;
                  break;
                }
              }
              uVar34 = uVar34 + 1;
              uVar35 = uVar35 + 1;
              bVar41 = uVar34 < local_b0;
            } while (uVar34 != local_b0);
            goto LAB_2ad991452c5;
          }
          uVar27 = 0x14;
          uVar35 = 0x14;
          if (*(short *)(_DAT_2ad9917822c + 0x28) != 0x20) {
            uVar34 = 0;
            do {
              if (local_b0 - 1 == uVar34) goto LAB_2ad991452c5;
              lVar15 = uVar34 * 2;
              uVar34 = uVar34 + 1;
            } while (*(short *)(_DAT_2ad9917822c + lVar15 + 0x2a) != 0x20);
            if (uVar34 < local_b0) {
LAB_2ad99145b44:
              uVar29 = (int)uVar34 + 0x14;
              uVar27 = (ulonglong)uVar29;
              uVar35 = uVar29;
              if (-0x15 < (int)uVar34) goto LAB_2ad991452cf;
            }
            goto LAB_2ad991452c5;
          }
LAB_2ad991452cf:
          uVar29 = uVar35;
          if (uVar23 <= (uint)uVar27) goto LAB_2ad991452f4;
          FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad9917822c + uVar27 * 2);
        }
        FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad991718a0);
        FUN_2ad99140a40(&local_d0,&local_148,0,0x2ad991718b0);
        uVar24 = 0xfa9;
        if ((_DAT_2ad9917822c == (undefined1 *)0x0) || (_DAT_2ad9917822c == (undefined1 *)0xc)) {
LAB_2ad991453da:
          _DAT_2ad99183b10 = uVar24;
          if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
            _DAT_2ad99183b10 = 0xfa9;
          }
          else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                  (cVar7 = FUN_2ad99140060(0x2ad99183b3c,0), puVar6 = _DAT_2ad99183b40,
                  cVar7 != '\0')) {
            *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
            *puVar6 = 0;
          }
        }
        else {
          uVar23 = *(uint *)(_DAT_2ad9917822c + -4);
          if (uVar23 == 0) {
            uVar24 = 0x13ab;
            goto LAB_2ad991453da;
          }
          if (-1 < (int)uVar29) {
            if ((int)uVar23 < (int)uVar29) {
              _DAT_2ad99183b10 = 0x13ab;
            }
            else {
              uVar23 = uVar29;
              uVar24 = _DAT_2ad99183b10;
              if (uVar29 == 0) goto LAB_2ad991453da;
            }
          }
          FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad9917822c,uVar23);
        }
        FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad991718c0);
        uVar27 = 0;
        FUN_2ad99140a40(0x2ad99178228,&local_148,0,0x2ad991718d0);
        bVar5 = DAT_2ad991784fd;
        bVar20 = DAT_2ad991784fc;
        FUN_2ad99140a40(&local_148,&local_120,0,0x2ad991718e0);
        uVar23 = _DAT_2ad991612d8;
        uVar34 = (ulonglong)_DAT_2ad991612d8;
        if ((uVar34 != 0) || (local_144 == 0)) {
          if (local_144 != 0) {
            uVar27 = (ulonglong)*(uint *)(local_144 + -4);
          }
          uVar35 = _DAT_2ad991612d8 + (int)uVar27;
          uVar29 = 0x104;
          if ((0x103 < uVar35) &&
             ((0x7ffffffd < uVar35 || (uVar29 = (uVar35 >> 2) + uVar35, 0x7ffffffd < uVar29)))) {
            uVar29 = 0x7ffffffe;
          }
          cVar7 = FUN_2ad99140060(&local_148,uVar29);
          if (cVar7 == '\0') goto LAB_2ad99145e9b;
          if (uVar34 != 0) {
            lVar15 = local_144 + uVar27 * 2;
            if (uVar23 < 0x10) {
              uVar27 = 0;
            }
            else if (lVar15 - 0x2ad991612dcU < 0x20) {
              uVar27 = 0;
            }
            else {
              uVar37 = 0;
              uVar27 = (ulonglong)(uVar23 & 0xfffffff8);
              do {
                uVar16 = *(undefined8 *)(uVar37 + 0x2ad991612e4);
                *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991612dc + uVar37);
                ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
                uVar37 = uVar37 + 0x10;
              } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
              if (uVar27 == uVar34) goto LAB_2ad991455e2;
            }
            do {
              *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991612dc + uVar27 * 2);
              uVar27 = uVar27 + 1;
            } while (uVar34 != uVar27);
          }
LAB_2ad991455e2:
          *(uint *)(local_144 + -4) = uVar35;
          *(undefined2 *)(local_144 + (ulonglong)uVar35 * 2) = 0;
        }
        uVar24 = 0xeaeaea;
        if ((bVar5 & 1) == 0) {
          uVar24 = 0;
        }
        uVar16 = CONCAT44(uVar9,uVar24);
        FUN_2ad9915ea70(&local_148,&local_d0,(int)local_128 + 0x32,uVar28 + 0x1fa,uVar16,
                        (bVar20 & 1) * '\t');
        uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
      }
      bVar5 = DAT_2ad991784fd;
      bVar20 = DAT_2ad991784fc;
      pcVar38 = FUN_2ad99140a40;
      uVar23 = 0;
      FUN_2ad99140a40(&local_148,&local_120,0,0x2ad991718f0);
      uVar29 = _DAT_2ad991612a8;
      uVar34 = (ulonglong)_DAT_2ad991612a8;
      if ((uVar34 == 0) && (local_144 != 0)) {
LAB_2ad991457a7:
        unaff_RBP = &DAT_2ad99178400;
        uVar24 = 0xeaeaea;
        if ((bVar5 & 1) == 0) {
          uVar24 = 0;
        }
        FUN_2ad9915ea70(&local_148,0x2ad99178228,(int)local_128 + 0x68,uVar28 + 0x1e5,
                        CONCAT44(uVar9,uVar24),(bVar20 & 1) * '\t');
        FUN_2ad99140000(&local_d0);
        FUN_2ad99140000(&local_88);
        FUN_2ad99140000(&local_120);
        FUN_2ad99140000(&local_148);
        FUN_2ad99140000(&local_138);
        FUN_2ad99140000(&local_c0);
        DAT_2ad991784d6 = '\x01';
        FUN_2ad9914ccb0(0,0);
        cVar7 = (char)local_104;
        goto LAB_2ad99145878;
      }
      if (local_144 != 0) {
        uVar23 = *(uint *)(local_144 + -4);
      }
      uVar30 = _DAT_2ad991612a8 + uVar23;
      uVar35 = 0x104;
      if ((0x103 < uVar30) &&
         ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
        uVar35 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_148,uVar35);
      if (cVar7 != '\0') {
        if (uVar34 != 0) {
          lVar15 = local_144 + (ulonglong)uVar23 * 2;
          if (uVar29 < 0x10) {
            uVar27 = 0;
          }
          else if (lVar15 - 0x2ad991612acU < 0x20) {
            uVar27 = 0;
          }
          else {
            uVar37 = 0;
            uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
            do {
              uVar16 = *(undefined8 *)(uVar37 + 0x2ad991612b4);
              *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad991612ac + uVar37);
              ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
              uVar37 = uVar37 + 0x10;
            } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
            if (uVar27 == uVar34) goto LAB_2ad99145792;
          }
          do {
            *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad991612ac + uVar27 * 2);
            uVar27 = uVar27 + 1;
          } while (uVar34 != uVar27);
        }
LAB_2ad99145792:
        *(uint *)(local_144 + -4) = uVar30;
        *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
        goto LAB_2ad991457a7;
      }
      goto LAB_2ad99145e3b;
    }
    lVar15 = SUB168(SEXT816(_DAT_2ad99178248 + 0x3b) * SEXT816(-0x7777777777777777),8) + 0x3b +
             _DAT_2ad99178248;
    (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,(lVar15 >> 5) - (lVar15 >> 0x3f),0x55,&local_148);
    uVar27 = 0;
    FUN_2ad99140a40(&local_138,&local_148,0,0x2ad99171870);
    uVar23 = _DAT_2ad99163a88;
    uVar34 = (ulonglong)_DAT_2ad99163a88;
    if ((uVar34 == 0) && (puVar22 = &local_138, local_134 != 0)) goto LAB_2ad9914502f;
    if (local_134 != 0) {
      uVar27 = (ulonglong)*(uint *)(local_134 + -4);
    }
    uVar35 = _DAT_2ad99163a88 + (int)uVar27;
    uVar29 = 0x104;
    if ((0x103 < uVar35) &&
       ((0x7ffffffd < uVar35 || (uVar29 = (uVar35 >> 2) + uVar35, 0x7ffffffd < uVar29)))) {
      uVar29 = 0x7ffffffe;
    }
    puVar22 = &local_138;
    cVar7 = FUN_2ad99140060(puVar22,uVar29);
    if (cVar7 != '\0') {
      if (uVar34 != 0) {
        lVar15 = local_134 + uVar27 * 2;
        if (uVar23 < 0x10) {
          uVar27 = 0;
        }
        else if (lVar15 - 0x2ad99163a8cU < 0x20) {
          uVar27 = 0;
        }
        else {
          uVar37 = 0;
          uVar27 = (ulonglong)(uVar23 & 0xfffffff8);
          do {
            uVar16 = *(undefined8 *)(uVar37 + 0x2ad99163a94);
            *(undefined8 *)(lVar15 + uVar37) = *(undefined8 *)(&DAT_2ad99163a8c + uVar37);
            ((undefined8 *)(lVar15 + uVar37))[1] = uVar16;
            uVar37 = uVar37 + 0x10;
          } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
          if (uVar27 == uVar34) goto LAB_2ad99145022;
        }
        do {
          *(undefined2 *)(lVar15 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad99163a8c + uVar27 * 2);
          uVar27 = uVar27 + 1;
        } while (uVar34 != uVar27);
      }
LAB_2ad99145022:
      *(uint *)(local_134 + -4) = uVar35;
      *(undefined2 *)(local_134 + (ulonglong)uVar35 * 2) = 0;
      goto LAB_2ad9914502f;
    }
  }
  else {
    if (local_144 != 0) {
      uVar23 = *(uint *)(local_144 + -4);
    }
    uVar30 = _DAT_2ad99161028 + uVar23;
    uVar35 = 0x104;
    if ((0x103 < uVar30) &&
       ((0x7ffffffd < uVar30 || (uVar35 = (uVar30 >> 2) + uVar30, 0x7ffffffd < uVar35)))) {
      uVar35 = 0x7ffffffe;
    }
    cVar7 = FUN_2ad99140060(&local_148,uVar35);
    if (cVar7 != '\0') {
      if (uVar34 != 0) {
        lVar17 = local_144 + (ulonglong)uVar23 * 2;
        if (uVar29 < 0x10) {
          uVar27 = 0;
        }
        else if (lVar17 - 0x2ad9916102cU < 0x20) {
          uVar27 = 0;
        }
        else {
          uVar37 = 0;
          uVar27 = (ulonglong)(uVar29 & 0xfffffff8);
          do {
            uVar16 = *(undefined8 *)(uVar37 + 0x2ad99161034);
            *(undefined8 *)(lVar17 + uVar37) = *(undefined8 *)(&DAT_2ad9916102c + uVar37);
            ((undefined8 *)(lVar17 + uVar37))[1] = uVar16;
            uVar37 = uVar37 + 0x10;
          } while ((uVar34 * 2 & 0xfffffffffffffff0) != uVar37);
          if (uVar27 == uVar34) goto LAB_2ad99142db2;
        }
        do {
          *(undefined2 *)(lVar17 + uVar27 * 2) = *(undefined2 *)(&DAT_2ad9916102c + uVar27 * 2);
          uVar27 = uVar27 + 1;
        } while (uVar34 != uVar27);
      }
LAB_2ad99142db2:
      *(uint *)(local_144 + -4) = uVar30;
      *(undefined2 *)(local_144 + (ulonglong)uVar30 * 2) = 0;
      goto LAB_2ad99142dbd;
    }
LAB_2ad99145c3b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2208e0000001f9);
LAB_2ad99145c5b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08ee000001f9);
LAB_2ad99145c7b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08ef000001f9);
LAB_2ad99145c9b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f1000001f9);
LAB_2ad99145cbb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f2000001f9);
LAB_2ad99145cdb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f3000001f9);
LAB_2ad99145cfb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f4000001f9);
LAB_2ad99145d1b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f5000001f9);
LAB_2ad99145d3b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f8000001f9);
LAB_2ad99145d5b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08f9000001f9);
LAB_2ad99145d7b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08fa000001f9);
LAB_2ad99145d9b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08fb000001f9);
LAB_2ad99145dbb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08fd000001f9);
LAB_2ad99145ddb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08fe000001f9);
LAB_2ad99145dfb:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b08ff000001f9);
LAB_2ad99145e1b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0900000001f9);
LAB_2ad99145e3b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0909000001f9);
LAB_2ad99145e5b:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3b08e7000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x640900000001f9);
LAB_2ad99145e9b:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1e0907000001f9);
  pcVar12 = (code *)swi(3);
  uVar16 = (*pcVar12)();
  return uVar16;
}



/* Address: 2ad99145ec0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99145ec0(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  longlong lVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  ulonglong uVar21;
  undefined8 in_stack_fffffffffffffcf8;
  undefined4 uVar23;
  ulonglong *puVar22;
  undefined8 in_stack_fffffffffffffd00;
  undefined8 *puVar24;
  undefined8 *puVar25;
  undefined4 *puVar26;
  undefined4 local_2b0;
  longlong local_2ac;
  undefined4 local_2a0;
  longlong local_29c;
  undefined4 local_290;
  longlong local_28c;
  undefined4 local_280;
  longlong local_27c;
  undefined4 local_270;
  longlong local_26c;
  undefined4 local_260;
  longlong local_25c;
  undefined4 local_250;
  longlong local_24c;
  undefined4 local_240;
  longlong local_23c;
  undefined4 local_230;
  longlong local_22c;
  undefined4 local_220;
  longlong local_21c;
  undefined4 local_210;
  longlong local_20c;
  undefined4 local_200;
  longlong local_1fc;
  undefined4 local_1f0;
  longlong local_1ec;
  undefined4 local_1e0;
  undefined1 *local_1dc;
  undefined4 local_1d0;
  undefined8 local_1cc;
  undefined4 local_1c0;
  undefined8 local_1bc;
  undefined4 local_1b0;
  longlong local_1ac;
  undefined4 local_1a0;
  undefined8 local_19c;
  undefined4 local_190;
  undefined8 local_18c;
  undefined4 local_180;
  undefined8 local_17c;
  undefined4 local_170;
  longlong local_16c;
  undefined8 local_160;
  ulonglong local_158;
  ulonglong local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined4 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  uVar10 = (undefined4)((ulonglong)in_stack_fffffffffffffd00 >> 0x20);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffcf8 >> 0x20);
  local_1f0 = 0;
  local_200 = 0;
  local_210 = 0;
  local_220 = 0;
  local_230 = 0;
  local_240 = 0;
  local_260 = 0;
  local_2a0 = 0;
  local_270 = 0;
  local_290 = 0;
  local_280 = 0;
  local_2b0 = 0;
  local_1b0 = 0;
  local_1c0 = 0;
  local_190 = 0;
  local_1a0 = 0;
  local_1d0 = 0;
  local_1e0 = 0;
  local_1ec = 0;
  local_1fc = 0;
  local_20c = 0;
  local_21c = 0;
  local_22c = 0;
  local_23c = 0;
  local_25c = 0;
  local_29c = 0;
  local_26c = 0;
  local_28c = 0;
  local_27c = 0;
  local_2ac = 0;
  local_1ac = 0;
  local_1bc = 0;
  local_18c = 0;
  local_19c = 0;
  local_1cc = 0;
  local_1dc = (undefined1 *)0x0;
  if (DAT_2ad99183c28 == '\0') goto LAB_2ad9914804b;
  lVar11 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  lVar14 = 0x28;
  if (DAT_2ad99178205 == '\0') {
    lVar14 = 0;
  }
  if (lVar11 - _DAT_2ad99178208 < lVar14) goto LAB_2ad9914804b;
  uVar16 = 0;
  _DAT_2ad99178208 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  uVar12 = (*(code *)0x7ff63a101e20)(0x2ad95e68178,0);
  local_1b0 = 0;
  local_1ac = 0;
  FUN_2ad99140a40(&local_2b0,0x2ad991781e8,0);
  uVar19 = _DAT_2ad991632fa;
  uVar13 = (ulonglong)_DAT_2ad991632fa;
  if ((uVar13 == 0) && (local_2ac != 0)) {
LAB_2ad9914620d:
    (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,uVar12,0x55,&local_280);
    FUN_2ad99140a40(&local_290,&local_2b0);
    lVar14 = local_27c;
    if (local_27c != 0) {
      uVar19 = *(uint *)(local_27c + -4);
      uVar13 = (ulonglong)uVar19;
      if ((uVar13 == 0) && (local_28c != 0)) goto LAB_2ad991463b7;
      if (local_28c == 0) {
        uVar16 = 0;
        uVar18 = uVar19;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_28c + -4);
        uVar18 = uVar19 + *(uint *)(local_28c + -4);
      }
      cVar7 = FUN_2ad99140060(&local_290);
      if (cVar7 != '\0') {
        if (uVar13 != 0) {
          lVar11 = local_28c + uVar16 * 2;
          if (uVar19 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              uVar8 = puVar26[1];
              uVar5 = puVar26[2];
              uVar6 = puVar26[3];
              puVar1 = (undefined4 *)(lVar11 + uVar17);
              *puVar1 = *puVar26;
              puVar1[1] = uVar8;
              puVar1[2] = uVar5;
              puVar1[3] = uVar6;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad991463a2;
          }
          do {
            *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar14 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad991463a2:
        *(uint *)(local_28c + -4) = uVar18;
        *(undefined2 *)(local_28c + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2ad991463b7;
      }
      goto LAB_2ad99148281;
    }
LAB_2ad991463b7:
    uVar19 = 0;
    FUN_2ad99140a40(&local_270,&local_290,0,0x2ad99171370);
    uVar18 = _DAT_2ad991632fa;
    uVar13 = (ulonglong)_DAT_2ad991632fa;
    if ((uVar13 != 0) || (local_26c == 0)) {
      if (local_26c != 0) {
        uVar19 = *(uint *)(local_26c + -4);
      }
      uVar20 = _DAT_2ad991632fa + uVar19;
      uVar15 = 0x104;
      if ((0x103 < uVar20) &&
         ((0x7ffffffd < uVar20 || (uVar15 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_270,uVar15);
      if (cVar7 == '\0') goto LAB_2ad99148141;
      if (uVar13 != 0) {
        lVar14 = local_26c + (ulonglong)uVar19 * 2;
        if (uVar18 < 0x10) {
          uVar16 = 0;
        }
        else if (lVar14 - 0x2ad991632feU < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163302);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163306);
            uVar6 = *(undefined4 *)(uVar17 + 0x2ad9916330a);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad991632fe + uVar17);
            puVar26[1] = uVar8;
            puVar26[2] = uVar5;
            puVar26[3] = uVar6;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad991464d2;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991632fe + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad991464d2:
      *(uint *)(local_26c + -4) = uVar20;
      *(undefined2 *)(local_26c + (ulonglong)uVar20 * 2) = 0;
    }
    uVar19 = 0;
    FUN_2ad99140a40(&local_2a0,&local_270,0,0x2ad99171380);
    uVar18 = _DAT_2ad99163318;
    uVar13 = (ulonglong)_DAT_2ad99163318;
    if ((uVar13 != 0) || (local_29c == 0)) {
      if (local_29c != 0) {
        uVar19 = *(uint *)(local_29c + -4);
      }
      uVar20 = _DAT_2ad99163318 + uVar19;
      uVar15 = 0x104;
      if ((0x103 < uVar20) &&
         ((0x7ffffffd < uVar20 || (uVar15 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_2a0,uVar15);
      if (cVar7 == '\0') goto LAB_2ad99148161;
      if (uVar13 != 0) {
        lVar14 = local_29c + (ulonglong)uVar19 * 2;
        if (uVar18 < 0x10) {
          uVar16 = 0;
        }
        else if (lVar14 - 0x2ad9916331cU < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163320);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163324);
            uVar6 = *(undefined4 *)(uVar17 + 0x2ad99163328);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad9916331c + uVar17);
            puVar26[1] = uVar8;
            puVar26[2] = uVar5;
            puVar26[3] = uVar6;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad9914660a;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad9916331c + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad9914660a:
      *(uint *)(local_29c + -4) = uVar20;
      *(undefined2 *)(local_29c + (ulonglong)uVar20 * 2) = 0;
    }
    local_170 = 0;
    local_180 = 0;
    local_250 = 0;
    local_16c = 0;
    local_17c = 0;
    local_24c = 0;
    local_78 = 0x10001004e;
    local_158 = 0x10001004e;
    local_b0 = 0x10001004e;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_150 = 0;
    local_148 = 0;
    local_140 = 0;
    uStack_13c = 0;
    local_138 = 0;
    uStack_134 = 0;
    local_130 = 0;
    local_128 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_98 = 0;
    local_90 = 0;
    local_88 = 0;
    local_80 = 0;
    uVar8 = 0;
    if ((local_29c != 0) && (uVar8 = 0, local_29c != 0xc)) {
      uVar8 = *(undefined4 *)(local_29c + -4);
    }
    local_160 = uVar12;
    (*(code *)0x7ff63a0feed0)
              (0x2ad95e68178,&local_2a0,&local_78,0,CONCAT44(uVar23,uVar8),CONCAT44(uVar10,0xfde9));
    puVar22 = &local_158;
    iVar9 = (*(code *)0x7ff639cb0870)(0x2ad95e68178,5,&local_78,&local_b0,puVar22);
    uVar23 = (undefined4)((ulonglong)puVar22 >> 0x20);
    if (iVar9 < 1) {
      FUN_2ad99140a40(&local_180,0x2ad99160d08,0,0x2ad99171250);
    }
    else {
      local_250 = 0;
      local_24c = 0;
      FUN_2ad99140a40(&local_250,0x2ad99160d08,0,0x2ad99171260);
      uVar13 = local_150 & 0xffffffff;
      if (0 < (int)local_150) {
        uVar16 = 0;
        do {
          if ((uVar13 & 0xffffffff) <= uVar16) {
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2607e2000001f6);
LAB_2ad99148101:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xa07e2000001f9);
            goto LAB_2ad99148121;
          }
          uVar13 = ~uVar16 + (uVar13 & 0xffffffff);
          if ((local_158 & 0x100000) == 0) {
            uVar13 = uVar16;
          }
          uVar23 = 0x2ad;
          (*(code *)0x7ff63a0e49f0)
                    (0x2ad95e68178,0xd8,2,0x590008,0x2ad991632a8,0x4e0011,
                     *(undefined1 *)(CONCAT44(local_138,uStack_13c) + uVar13));
          FUN_2ad99140a40(&local_170,0x2ad99183b3c,1);
          lVar14 = local_16c;
          if (local_16c != 0) {
            uVar19 = *(uint *)(local_16c + -4);
            uVar13 = (ulonglong)uVar19;
            if ((uVar13 != 0) || (local_24c == 0)) {
              if (local_24c == 0) {
                uVar18 = 0;
                uVar15 = uVar19;
              }
              else {
                uVar18 = *(uint *)(local_24c + -4);
                uVar15 = uVar19 + uVar18;
              }
              cVar7 = FUN_2ad99140060(&local_250);
              if (cVar7 == '\0') goto LAB_2ad99148101;
              if (uVar13 != 0) {
                lVar11 = local_24c + (ulonglong)uVar18 * 2;
                if (uVar19 < 8) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar19 & 0xfffffff8);
                  do {
                    puVar26 = (undefined4 *)(lVar14 + uVar21);
                    uVar10 = puVar26[1];
                    uVar8 = puVar26[2];
                    uVar5 = puVar26[3];
                    puVar1 = (undefined4 *)(lVar11 + uVar21);
                    *puVar1 = *puVar26;
                    puVar1[1] = uVar10;
                    puVar1[2] = uVar8;
                    puVar1[3] = uVar5;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar13) goto LAB_2ad99146850;
                }
                do {
                  *(undefined2 *)(lVar11 + uVar17 * 2) = *(undefined2 *)(lVar14 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar13 != uVar17);
              }
LAB_2ad99146850:
              *(uint *)(local_24c + -4) = uVar15;
              *(undefined2 *)(local_24c + (ulonglong)uVar15 * 2) = 0;
            }
          }
          uVar13 = (ulonglong)(int)local_150;
          uVar16 = uVar16 + 1;
        } while ((longlong)uVar16 < (longlong)uVar13);
      }
      FUN_2ad99140a40(&local_180,&local_250,0,0x2ad99171280);
      FUN_2ad99140000(&local_250);
    }
    (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_b0);
    (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_158);
    (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_78);
    FUN_2ad99140a40(0x2ad99183b3c,&local_180,1,0x2ad99171290);
    FUN_2ad99140000(&local_180);
    FUN_2ad99140000(&local_170);
    FUN_2ad99140a40(&local_260,0x2ad99183b3c,1,0x2ad99171390);
    FUN_2ad99140a40(&local_1b0,&local_260,0,0x2ad991713a0);
    local_1c0 = 0;
    local_1bc = 0;
    FUN_2ad99140a40(&local_2b0,0x2ad991633b8);
    lVar14 = _DAT_2ad991781ec;
    if (_DAT_2ad991781ec != 0) {
      uVar19 = *(uint *)(_DAT_2ad991781ec + -4);
      uVar13 = (ulonglong)uVar19;
      if ((uVar13 == 0) && (local_2ac != 0)) goto LAB_2ad99146c5d;
      if (local_2ac == 0) {
        uVar16 = 0;
        uVar18 = uVar19;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_2ac + -4);
        uVar18 = uVar19 + *(uint *)(local_2ac + -4);
      }
      cVar7 = FUN_2ad99140060(&local_2b0);
      if (cVar7 != '\0') {
        if (uVar13 != 0) {
          lVar11 = local_2ac + uVar16 * 2;
          if (uVar19 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              uVar10 = puVar26[1];
              uVar8 = puVar26[2];
              uVar5 = puVar26[3];
              puVar1 = (undefined4 *)(lVar11 + uVar17);
              *puVar1 = *puVar26;
              puVar1[1] = uVar10;
              puVar1[2] = uVar8;
              puVar1[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad99146c52;
          }
          do {
            *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar14 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad99146c52:
        *(uint *)(local_2ac + -4) = uVar18;
        *(undefined2 *)(local_2ac + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2ad99146c5d;
      }
      goto LAB_2ad991482a1;
    }
LAB_2ad99146c5d:
    uVar19 = 0;
    FUN_2ad99140a40(&local_280,&local_2b0);
    uVar18 = _DAT_2ad991633d8;
    uVar13 = (ulonglong)_DAT_2ad991633d8;
    if ((uVar13 != 0) || (local_27c == 0)) {
      if (local_27c != 0) {
        uVar19 = *(uint *)(local_27c + -4);
      }
      uVar15 = _DAT_2ad991633d8 + uVar19;
      cVar7 = FUN_2ad99140060(&local_280);
      if (cVar7 == '\0') goto LAB_2ad99148181;
      if (uVar13 != 0) {
        lVar14 = local_27c + (ulonglong)uVar19 * 2;
        if ((uVar18 < 0x10) || (lVar14 - 0x2ad991633dcU < 0x20)) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar10 = *(undefined4 *)(uVar17 + 0x2ad991633e0);
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad991633e4);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad991633e8);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad991633dc + uVar17);
            puVar26[1] = uVar10;
            puVar26[2] = uVar8;
            puVar26[3] = uVar5;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad99146d52;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991633dc + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad99146d52:
      *(uint *)(local_27c + -4) = uVar15;
      *(undefined2 *)(local_27c + (ulonglong)uVar15 * 2) = 0;
    }
    uVar16 = 0;
    FUN_2ad99140a40(&local_290,&local_280,0,0x2ad991713d0);
    uVar19 = _DAT_2ad991633f8;
    uVar13 = (ulonglong)_DAT_2ad991633f8;
    if ((uVar13 != 0) || (local_28c == 0)) {
      if (local_28c != 0) {
        uVar16 = (ulonglong)*(uint *)(local_28c + -4);
      }
      uVar15 = _DAT_2ad991633f8 + (int)uVar16;
      uVar18 = 0x104;
      if ((0x103 < uVar15) &&
         ((0x7ffffffd < uVar15 || (uVar18 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_290,uVar18);
      if (cVar7 == '\0') goto LAB_2ad991481a1;
      if (uVar13 != 0) {
        lVar14 = local_28c + uVar16 * 2;
        if (uVar19 < 0x10) {
          uVar16 = 0;
        }
        else if (lVar14 - 0x2ad991633fcU < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            uVar10 = *(undefined4 *)(uVar17 + 0x2ad99163400);
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163404);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163408);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad991633fc + uVar17);
            puVar26[1] = uVar10;
            puVar26[2] = uVar8;
            puVar26[3] = uVar5;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad99146ed2;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991633fc + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad99146ed2:
      *(uint *)(local_28c + -4) = uVar15;
      *(undefined2 *)(local_28c + (ulonglong)uVar15 * 2) = 0;
    }
    (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,local_160,0x55,&local_270);
    FUN_2ad99140a40(&local_2a0,&local_290);
    lVar14 = local_26c;
    if (local_26c != 0) {
      uVar19 = *(uint *)(local_26c + -4);
      uVar13 = (ulonglong)uVar19;
      if ((uVar13 == 0) && (local_29c != 0)) goto LAB_2ad99147037;
      if (local_29c == 0) {
        uVar16 = 0;
        uVar18 = uVar19;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_29c + -4);
        uVar18 = uVar19 + *(uint *)(local_29c + -4);
      }
      cVar7 = FUN_2ad99140060(&local_2a0);
      if (cVar7 != '\0') {
        if (uVar13 != 0) {
          lVar11 = local_29c + uVar16 * 2;
          if (uVar19 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              uVar10 = puVar26[1];
              uVar8 = puVar26[2];
              uVar5 = puVar26[3];
              puVar1 = (undefined4 *)(lVar11 + uVar17);
              *puVar1 = *puVar26;
              puVar1[1] = uVar10;
              puVar1[2] = uVar8;
              puVar1[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad99147022;
          }
          do {
            *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar14 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad99147022:
        *(uint *)(local_29c + -4) = uVar18;
        *(undefined2 *)(local_29c + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2ad99147037;
      }
      goto LAB_2ad991482c1;
    }
LAB_2ad99147037:
    uVar19 = 0;
    FUN_2ad99140a40(&local_260,&local_2a0);
    uVar18 = _DAT_2ad991633d8;
    uVar13 = (ulonglong)_DAT_2ad991633d8;
    if ((uVar13 != 0) || (local_25c == 0)) {
      if (local_25c != 0) {
        uVar19 = *(uint *)(local_25c + -4);
      }
      uVar15 = _DAT_2ad991633d8 + uVar19;
      cVar7 = FUN_2ad99140060(&local_260);
      if (cVar7 == '\0') goto LAB_2ad991481c1;
      if (uVar13 != 0) {
        lVar14 = local_25c + (ulonglong)uVar19 * 2;
        if ((uVar18 < 0x10) || (lVar14 - 0x2ad991633dcU < 0x20)) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar10 = *(undefined4 *)(uVar17 + 0x2ad991633e0);
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad991633e4);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad991633e8);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad991633dc + uVar17);
            puVar26[1] = uVar10;
            puVar26[2] = uVar8;
            puVar26[3] = uVar5;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad99147122;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991633dc + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad99147122:
      *(uint *)(local_25c + -4) = uVar15;
      *(undefined2 *)(local_25c + (ulonglong)uVar15 * 2) = 0;
    }
    uVar16 = 0;
    FUN_2ad99140a40(&local_240,&local_260,0,0x2ad99171400);
    uVar19 = _DAT_2ad99163428;
    uVar13 = (ulonglong)_DAT_2ad99163428;
    if ((uVar13 != 0) || (local_23c == 0)) {
      if (local_23c != 0) {
        uVar16 = (ulonglong)*(uint *)(local_23c + -4);
      }
      uVar15 = _DAT_2ad99163428 + (int)uVar16;
      uVar18 = 0x104;
      if ((0x103 < uVar15) &&
         ((0x7ffffffd < uVar15 || (uVar18 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar7 = FUN_2ad99140060(&local_240,uVar18);
      if (cVar7 == '\0') goto LAB_2ad991481e1;
      if (uVar13 != 0) {
        lVar14 = local_23c + uVar16 * 2;
        if (uVar19 < 0x10) {
          uVar16 = 0;
        }
        else if (lVar14 - 0x2ad9916342cU < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            uVar10 = *(undefined4 *)(uVar17 + 0x2ad99163430);
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163434);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163438);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad9916342c + uVar17);
            puVar26[1] = uVar10;
            puVar26[2] = uVar8;
            puVar26[3] = uVar5;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad991472a2;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad9916342c + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad991472a2:
      *(uint *)(local_23c + -4) = uVar15;
      *(undefined2 *)(local_23c + (ulonglong)uVar15 * 2) = 0;
    }
    FUN_2ad99140a40(&local_230,&local_240);
    lVar14 = local_1ac;
    if (local_1ac == 0) {
LAB_2ad991473e7:
      uVar19 = 0;
      FUN_2ad99140a40(&local_220,&local_230);
      uVar18 = _DAT_2ad991633d8;
      uVar13 = (ulonglong)_DAT_2ad991633d8;
      if ((uVar13 != 0) || (local_21c == 0)) {
        if (local_21c != 0) {
          uVar19 = *(uint *)(local_21c + -4);
        }
        uVar15 = _DAT_2ad991633d8 + uVar19;
        cVar7 = FUN_2ad99140060(&local_220);
        if (cVar7 == '\0') goto LAB_2ad99148201;
        if (uVar13 != 0) {
          lVar14 = local_21c + (ulonglong)uVar19 * 2;
          if ((uVar18 < 0x10) || (lVar14 - 0x2ad991633dcU < 0x20)) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar10 = *(undefined4 *)(uVar17 + 0x2ad991633e0);
              uVar8 = *(undefined4 *)(uVar17 + 0x2ad991633e4);
              uVar5 = *(undefined4 *)(uVar17 + 0x2ad991633e8);
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              *puVar26 = *(undefined4 *)(&DAT_2ad991633dc + uVar17);
              puVar26[1] = uVar10;
              puVar26[2] = uVar8;
              puVar26[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad991474d2;
          }
          do {
            *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991633dc + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad991474d2:
        *(uint *)(local_21c + -4) = uVar15;
        *(undefined2 *)(local_21c + (ulonglong)uVar15 * 2) = 0;
      }
      uVar16 = 0;
      FUN_2ad99140a40(&local_210,&local_220,0,0x2ad99171430);
      uVar19 = _DAT_2ad99163458;
      uVar13 = (ulonglong)_DAT_2ad99163458;
      if ((uVar13 != 0) || (local_20c == 0)) {
        if (local_20c != 0) {
          uVar16 = (ulonglong)*(uint *)(local_20c + -4);
        }
        uVar15 = _DAT_2ad99163458 + (int)uVar16;
        uVar18 = 0x104;
        if ((0x103 < uVar15) &&
           ((0x7ffffffd < uVar15 || (uVar18 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_2ad99140060(&local_210,uVar18);
        if (cVar7 == '\0') goto LAB_2ad99148221;
        if (uVar13 != 0) {
          lVar14 = local_20c + uVar16 * 2;
          if (uVar19 < 0x10) {
            uVar16 = 0;
          }
          else if (lVar14 - 0x2ad9916345cU < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              uVar10 = *(undefined4 *)(uVar17 + 0x2ad99163460);
              uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163464);
              uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163468);
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              *puVar26 = *(undefined4 *)(&DAT_2ad9916345c + uVar17);
              puVar26[1] = uVar10;
              puVar26[2] = uVar8;
              puVar26[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad99147652;
          }
          do {
            *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad9916345c + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad99147652:
        *(uint *)(local_20c + -4) = uVar15;
        *(undefined2 *)(local_20c + (ulonglong)uVar15 * 2) = 0;
      }
      FUN_2ad99140a40(&local_200,&local_210);
      lVar14 = _DAT_2ad991781fc;
      if (_DAT_2ad991781fc != 0) {
        uVar19 = *(uint *)(_DAT_2ad991781fc + -4);
        uVar13 = (ulonglong)uVar19;
        if ((uVar13 != 0) || (local_1fc == 0)) {
          if (local_1fc == 0) {
            uVar16 = 0;
            uVar18 = uVar19;
          }
          else {
            uVar16 = (ulonglong)*(uint *)(local_1fc + -4);
            uVar18 = uVar19 + *(uint *)(local_1fc + -4);
          }
          cVar7 = FUN_2ad99140060(&local_200);
          if (cVar7 == '\0') goto LAB_2ad99148301;
          if (uVar13 != 0) {
            lVar11 = local_1fc + uVar16 * 2;
            if (uVar19 < 0x10) {
              uVar16 = 0;
            }
            else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
              uVar16 = 0;
            }
            else {
              uVar17 = 0;
              uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
              do {
                puVar26 = (undefined4 *)(lVar14 + uVar17);
                uVar10 = puVar26[1];
                uVar8 = puVar26[2];
                uVar5 = puVar26[3];
                puVar1 = (undefined4 *)(lVar11 + uVar17);
                *puVar1 = *puVar26;
                puVar1[1] = uVar10;
                puVar1[2] = uVar8;
                puVar1[3] = uVar5;
                uVar17 = uVar17 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
              if (uVar16 == uVar13) goto LAB_2ad99147782;
            }
            do {
              *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar14 + uVar16 * 2);
              uVar16 = uVar16 + 1;
            } while (uVar13 != uVar16);
          }
LAB_2ad99147782:
          *(uint *)(local_1fc + -4) = uVar18;
          *(undefined2 *)(local_1fc + (ulonglong)uVar18 * 2) = 0;
        }
      }
      uVar19 = 0;
      FUN_2ad99140a40(&local_1f0,&local_200,0,0x2ad99171450);
      uVar18 = _DAT_2ad991633d8;
      uVar13 = (ulonglong)_DAT_2ad991633d8;
      if ((uVar13 != 0) || (local_1ec == 0)) {
        if (local_1ec != 0) {
          uVar19 = *(uint *)(local_1ec + -4);
        }
        uVar20 = _DAT_2ad991633d8 + uVar19;
        uVar15 = 0x104;
        if ((0x103 < uVar20) &&
           ((0x7ffffffd < uVar20 || (uVar15 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar7 = FUN_2ad99140060(&local_1f0,uVar15);
        if (cVar7 == '\0') goto LAB_2ad99148241;
        if (uVar13 != 0) {
          lVar14 = local_1ec + (ulonglong)uVar19 * 2;
          if (uVar18 < 0x10) {
            uVar16 = 0;
          }
          else if (lVar14 - 0x2ad991633dcU < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar10 = *(undefined4 *)(uVar17 + 0x2ad991633e0);
              uVar8 = *(undefined4 *)(uVar17 + 0x2ad991633e4);
              uVar5 = *(undefined4 *)(uVar17 + 0x2ad991633e8);
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              *puVar26 = *(undefined4 *)(&DAT_2ad991633dc + uVar17);
              puVar26[1] = uVar10;
              puVar26[2] = uVar8;
              puVar26[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad991478b2;
          }
          do {
            *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991633dc + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad991478b2:
        *(uint *)(local_1ec + -4) = uVar20;
        *(undefined2 *)(local_1ec + (ulonglong)uVar20 * 2) = 0;
      }
      uVar19 = 0;
      FUN_2ad99140a40(&local_1c0,&local_1f0,0,0x2ad99171460);
      local_190 = 0;
      local_18c = 0;
      FUN_2ad99140a40(&local_2b0,0x2ad991781d8,0,0x2ad99171470);
      uVar18 = _DAT_2ad99163498;
      uVar13 = (ulonglong)_DAT_2ad99163498;
      if ((uVar13 != 0) || (local_2ac == 0)) {
        if (local_2ac != 0) {
          uVar19 = *(uint *)(local_2ac + -4);
        }
        uVar20 = _DAT_2ad99163498 + uVar19;
        uVar15 = 0x104;
        if ((0x103 < uVar20) &&
           ((0x7ffffffd < uVar20 || (uVar15 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar7 = FUN_2ad99140060(&local_2b0,uVar15);
        if (cVar7 == '\0') goto LAB_2ad99148261;
        if (uVar13 != 0) {
          lVar14 = local_2ac + (ulonglong)uVar19 * 2;
          if (uVar18 < 0x10) {
            uVar16 = 0;
          }
          else if (lVar14 - 0x2ad9916349cU < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar17 = 0;
            uVar16 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar10 = *(undefined4 *)(uVar17 + 0x2ad991634a0);
              uVar8 = *(undefined4 *)(uVar17 + 0x2ad991634a4);
              uVar5 = *(undefined4 *)(uVar17 + 0x2ad991634a8);
              puVar26 = (undefined4 *)(lVar14 + uVar17);
              *puVar26 = *(undefined4 *)(&DAT_2ad9916349c + uVar17);
              puVar26[1] = uVar10;
              puVar26[2] = uVar8;
              puVar26[3] = uVar5;
              uVar17 = uVar17 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
            if (uVar16 == uVar13) goto LAB_2ad99147a12;
          }
          do {
            *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad9916349c + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar13 != uVar16);
        }
LAB_2ad99147a12:
        *(uint *)(local_2ac + -4) = uVar20;
        *(undefined2 *)(local_2ac + (ulonglong)uVar20 * 2) = 0;
      }
      FUN_2ad99140a40(&local_190,&local_2b0,0,0x2ad99171480);
      local_1a0 = 0;
      local_19c = 0;
      local_e8 = 0x10001004d;
      local_120 = 0x10001004d;
      _DAT_2ad99183b10 = 0;
      _DAT_2ad99183b80 = 0;
      DAT_2ad99183b88 = 0;
      puVar26 = &local_1a0;
      local_e0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      local_c8 = 0;
      local_c0 = 0;
      local_b8 = 0;
      local_118 = 0;
      local_110 = 0;
      local_108 = 0;
      local_100 = 0;
      local_f8 = 0;
      local_f0 = 0;
      puVar25 = &local_120;
      puVar24 = &local_e8;
      uVar10 = 5000;
      if (DAT_2ad99178204 == '\0') {
        uVar10 = 0;
      }
      iVar9 = (*(code *)0x7ff63a0e5a80)
                        (0x2ad95e68178,0x2ad99163508,&local_190,&local_1c0,CONCAT44(uVar23,uVar10),
                         puVar24,puVar25,puVar26);
      uVar23 = (undefined4)((ulonglong)puVar24 >> 0x20);
      uVar8 = (undefined4)((ulonglong)puVar26 >> 0x20);
      uVar10 = (undefined4)((ulonglong)puVar25 >> 0x20);
      if (iVar9 == -1) {
        uVar12 = 0x2ad99160d08;
        if (_DAT_2ad99183b10 == 0xfae) {
          uVar12 = 0x2ad991635f0;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x2ad95e68178,2,3,0x590008,0x2ad99163568,CONCAT44(uVar23,0x520004),
                   CONCAT44(uVar10,_DAT_2ad99183b10),CONCAT44(uVar8,0x590008),uVar12);
      }
      else {
        local_1d0 = 0;
        local_1cc = 0;
        (*(code *)0x7ff63a0fe920)(0x2ad95e68178,&local_120,0,0xffffffff,0xfde9);
        FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,0,0x2ad99171490);
        FUN_2ad99140a40(&local_1d0,&local_2b0,0,0x2ad991714a0);
        if (iVar9 == 200) {
          local_1e0 = 0;
          local_1dc = (undefined1 *)0x0;
          FUN_2ad9915d7b0(&local_1d0,0x2ad991636a0);
          FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,1,0x2ad991714b0);
          FUN_2ad99140a40(&local_1e0,&local_2b0,0,0x2ad991714c0);
          iVar9 = 0;
          if (local_1dc != &DAT_2ad991636bc) {
            if (local_1dc == (undefined1 *)0x0) {
              iVar9 = 1;
            }
            else {
              uVar19 = *(uint *)(local_1dc + -4);
              uVar18 = _DAT_2ad991636b8;
              if (uVar19 < _DAT_2ad991636b8) {
                uVar18 = uVar19;
              }
              iVar9 = uVar19 - _DAT_2ad991636b8;
              if (uVar18 != 0) {
                uVar13 = 0;
                do {
                  uVar2 = *(ushort *)(local_1dc + uVar13 * 2);
                  uVar3 = *(ushort *)(&DAT_2ad991636bc + uVar13 * 2);
                  uVar13 = uVar13 + 1;
                  if (uVar18 <= uVar13) break;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar9 = (uint)uVar2 - (uint)uVar3;
                }
              }
            }
          }
          DAT_2ad99178210 = iVar9 == 0;
          FUN_2ad9915d7b0(&local_1d0,0x2ad991636f8);
          FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,1,0x2ad991714d0);
          FUN_2ad99140a40(0x2ad99178218,&local_2b0,0,0x2ad991714e0);
          FUN_2ad9915d7b0(&local_1d0,0x2ad99163730);
          FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,1,0x2ad991714f0);
          FUN_2ad99140a40(0x2ad99178228,&local_2b0,0,0x2ad99171500);
          FUN_2ad9915d7b0(&local_1d0,0x2ad99163760);
          FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,1,0x2ad99171510);
          FUN_2ad99140a40(0x2ad99178238,&local_2b0,0,0x2ad99171520);
          FUN_2ad9915d7b0(&local_1d0,0x2ad991637a0);
          FUN_2ad99140a40(&local_2b0,0x2ad99183b3c,1,0x2ad99171530);
          _DAT_2ad99178248 = (*(code *)0x7ff63a0fe4f0)(0x2ad95e68178,&local_2b0);
          (*(code *)0x7ff63a0e49f0)
                    (0x2ad95e68178,0xd,6,0x590008,0x2ad99163848,CONCAT44(uVar23,0x590008),&local_1e0
                     ,CONCAT44(uVar8,0x590008),0x2ad99178218,0x590008,0x2ad99178238,0x550005,
                     _DAT_2ad99178248,0x590008,0x2ad99178228);
          FUN_2ad99140000(&local_1e0);
          FUN_2ad99140000(&local_1d0);
        }
        else {
          (*(code *)0x7ff63a0e49f0)
                    (0x2ad95e68178,2,4,0x590008,0x2ad99163630,CONCAT44(uVar23,0x520004),
                     CONCAT44(uVar10,iVar9),CONCAT44(uVar8,0x590008),0x2ad99163660,0x590008,
                     &local_1d0);
          FUN_2ad99140000(&local_1d0);
        }
      }
      FUN_2ad99140000(&local_1a0);
      (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_120);
      (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_e8);
      FUN_2ad99140000(&local_190);
      FUN_2ad99140000(&local_1c0);
      FUN_2ad99140000(&local_1b0);
LAB_2ad9914804b:
      FUN_2ad99140000(&local_2b0);
      FUN_2ad99140000(&local_280);
      FUN_2ad99140000(&local_290);
      FUN_2ad99140000(&local_270);
      FUN_2ad99140000(&local_2a0);
      FUN_2ad99140000(&local_260);
      FUN_2ad99140000(&local_240);
      FUN_2ad99140000(&local_230);
      FUN_2ad99140000(&local_220);
      FUN_2ad99140000(&local_210);
      FUN_2ad99140000(&local_200);
      FUN_2ad99140000(&local_1f0);
      return;
    }
    uVar19 = *(uint *)(local_1ac + -4);
    uVar13 = (ulonglong)uVar19;
    if ((uVar13 == 0) && (local_22c != 0)) goto LAB_2ad991473e7;
    if (local_22c == 0) {
      uVar16 = 0;
      uVar18 = uVar19;
    }
    else {
      uVar16 = (ulonglong)*(uint *)(local_22c + -4);
      uVar18 = uVar19 + *(uint *)(local_22c + -4);
    }
    cVar7 = FUN_2ad99140060(&local_230);
    if (cVar7 != '\0') {
      if (uVar13 != 0) {
        lVar11 = local_22c + uVar16 * 2;
        if (uVar19 < 0x10) {
          uVar16 = 0;
        }
        else if ((ulonglong)(lVar11 - lVar14) < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            uVar10 = puVar26[1];
            uVar8 = puVar26[2];
            uVar5 = puVar26[3];
            puVar1 = (undefined4 *)(lVar11 + uVar17);
            *puVar1 = *puVar26;
            puVar1[1] = uVar10;
            puVar1[2] = uVar8;
            puVar1[3] = uVar5;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad991473d2;
        }
        do {
          *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar14 + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad991473d2:
      *(uint *)(local_22c + -4) = uVar18;
      *(undefined2 *)(local_22c + (ulonglong)uVar18 * 2) = 0;
      goto LAB_2ad991473e7;
    }
  }
  else {
    if (local_2ac != 0) {
      uVar16 = (ulonglong)*(uint *)(local_2ac + -4);
    }
    uVar18 = _DAT_2ad991632fa + (int)uVar16;
    cVar7 = FUN_2ad99140060(&local_2b0);
    if (cVar7 != '\0') {
      if (uVar13 != 0) {
        lVar14 = local_2ac + uVar16 * 2;
        if ((uVar19 < 0x10) || (lVar14 - 0x2ad991632feU < 0x20)) {
          uVar16 = 0;
        }
        else {
          uVar17 = 0;
          uVar16 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            uVar8 = *(undefined4 *)(uVar17 + 0x2ad99163302);
            uVar5 = *(undefined4 *)(uVar17 + 0x2ad99163306);
            uVar6 = *(undefined4 *)(uVar17 + 0x2ad9916330a);
            puVar26 = (undefined4 *)(lVar14 + uVar17);
            *puVar26 = *(undefined4 *)(&DAT_2ad991632fe + uVar17);
            puVar26[1] = uVar8;
            puVar26[2] = uVar5;
            puVar26[3] = uVar6;
            uVar17 = uVar17 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar17);
          if (uVar16 == uVar13) goto LAB_2ad99146202;
        }
        do {
          *(undefined2 *)(lVar14 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991632fe + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar13 != uVar16);
      }
LAB_2ad99146202:
      *(uint *)(local_2ac + -4) = uVar18;
      *(undefined2 *)(local_2ac + (ulonglong)uVar18 * 2) = 0;
      goto LAB_2ad9914620d;
    }
LAB_2ad99148121:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x270812000001f9);
LAB_2ad99148141:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3a0812000001f9);
LAB_2ad99148161:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x400812000001f9);
LAB_2ad99148181:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2a0815000001f9);
LAB_2ad991481a1:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x330815000001f9);
LAB_2ad991481c1:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2a0816000001f9);
LAB_2ad991481e1:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x330816000001f9);
LAB_2ad99148201:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2a0817000001f9);
LAB_2ad99148221:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x330817000001f9);
LAB_2ad99148241:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2a0818000001f9);
LAB_2ad99148261:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b081a000001f9);
LAB_2ad99148281:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2d0812000001f9);
LAB_2ad991482a1:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0815000001f9);
LAB_2ad991482c1:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0816000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0817000001f9);
LAB_2ad99148301:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b0818000001f9);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



/* Address: 2ad99148330 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99148330(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined4 uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  short *psVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined8 uVar22;
  bool bVar23;
  undefined8 in_stack_fffffffffffffe90;
  undefined8 *puVar24;
  undefined8 in_stack_fffffffffffffe98;
  undefined8 *puVar25;
  undefined4 *puVar26;
  undefined4 local_148;
  short *local_144;
  undefined4 local_138;
  longlong local_134;
  longlong local_128;
  undefined4 local_120;
  longlong local_11c;
  undefined4 local_110;
  longlong local_10c;
  undefined4 local_100;
  undefined8 local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  uVar5 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  local_d0 = 0;
  local_cc = 0;
  (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99164068);
  local_110 = 0;
  local_120 = 0;
  local_138 = 0;
  local_c0 = 0;
  local_f0 = 0;
  local_10c = 0;
  local_11c = 0;
  local_134 = 0;
  local_bc = 0;
  local_ec = 0;
  FUN_2ad99140a40(&local_f0,0x2ad99160ca0,0,0x2ad99171ea0);
  local_e0 = 0;
  local_148 = 0;
  local_dc = 0;
  local_144 = (short *)0x0;
  local_78 = 0x10001004d;
  local_b0 = 0x10001004d;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  FUN_2ad99140a40(&local_148,0x2ad99160d08,0,0x2ad99171eb0);
  local_100 = 0;
  local_fc = 0;
  FUN_2ad99140a40(&local_100,0x2ad99164150,0,0x2ad99171ec0);
  iVar4 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,6);
  if (iVar4 == 0) {
    _DAT_2ad99183b10 = 0;
    _DAT_2ad99183b80 = 0;
    DAT_2ad99183b88 = 0;
    lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ad95e68178,0x2ad99164188,1,1);
    if (lVar10 == -1) {
      lVar10 = 0;
    }
    else {
      lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ad95e68178,0x2ad99164188,3,1);
      if ((0 < lVar10) &&
         (lVar11 = (*(code *)0x7ff63a101d80)(0x2ad95e68178,0), lVar11 - lVar10 < 0x136)) {
        lVar11 = (*(code *)0x7ff63a101d80)(0x2ad95e68178,0);
        (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,lVar11 - lVar10,0,0x20);
        FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171ed0);
        FUN_2ad99140a40(&local_120,0x2ad991641e0);
        lVar10 = local_134;
        if (local_134 != 0) {
          uVar12 = *(uint *)(local_134 + -4);
          uVar13 = (ulonglong)uVar12;
          if ((uVar13 != 0) || (local_11c == 0)) {
            if (local_11c == 0) {
              uVar16 = 0;
            }
            else {
              uVar16 = (ulonglong)*(uint *)(local_11c + -4);
            }
            uVar17 = uVar12 + (int)uVar16;
            cVar3 = FUN_2ad99140060(&local_120);
            if (cVar3 == '\0') goto LAB_2ad9914974f;
            if (uVar13 != 0) {
              lVar11 = local_11c + uVar16 * 2;
              if (uVar12 < 0x10) {
                uVar16 = 0;
              }
              else if ((ulonglong)(lVar11 - lVar10) < 0x20) {
                uVar16 = 0;
              }
              else {
                uVar21 = 0;
                uVar16 = (ulonglong)(uVar12 & 0xfffffff8);
                do {
                  puVar26 = (undefined4 *)(lVar10 + uVar21);
                  uVar9 = puVar26[1];
                  uVar8 = puVar26[2];
                  uVar14 = puVar26[3];
                  puVar1 = (undefined4 *)(lVar11 + uVar21);
                  *puVar1 = *puVar26;
                  puVar1[1] = uVar9;
                  puVar1[2] = uVar8;
                  puVar1[3] = uVar14;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar16 == uVar13) goto LAB_2ad99148e12;
              }
              do {
                *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
                uVar16 = uVar16 + 1;
              } while (uVar13 != uVar16);
            }
LAB_2ad99148e12:
            *(uint *)(local_11c + -4) = uVar17;
            *(undefined2 *)(local_11c + (ulonglong)uVar17 * 2) = 0;
          }
        }
        uVar12 = 0;
        FUN_2ad99140a40(&local_110,&local_120,0,0x2ad99171ef0);
        uVar17 = _DAT_2ad991641f8;
        uVar13 = (ulonglong)_DAT_2ad991641f8;
        if ((uVar13 != 0) || (local_10c == 0)) {
          if (local_10c != 0) {
            uVar12 = *(uint *)(local_10c + -4);
          }
          uVar18 = _DAT_2ad991641f8 + uVar12;
          uVar15 = 0x104;
          if ((0x103 < uVar18) &&
             ((0x7ffffffd < uVar18 || (uVar15 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar15)))) {
            uVar15 = 0x7ffffffe;
          }
          cVar3 = FUN_2ad99140060(&local_110,uVar15);
          if (cVar3 == '\0') {
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4c0a6e000001f9);
LAB_2ad9914974f:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x240a6e000001f9);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          if (uVar13 != 0) {
            lVar10 = local_10c + (ulonglong)uVar12 * 2;
            if (uVar17 < 0x10) {
              uVar16 = 0;
            }
            else if (lVar10 - 0x2ad991641fcU < 0x20) {
              uVar16 = 0;
            }
            else {
              uVar21 = 0;
              uVar16 = (ulonglong)(uVar17 & 0xfffffff8);
              do {
                uVar9 = *(undefined4 *)(uVar21 + 0x2ad99164200);
                uVar8 = *(undefined4 *)(uVar21 + 0x2ad99164204);
                uVar14 = *(undefined4 *)(uVar21 + 0x2ad99164208);
                puVar26 = (undefined4 *)(lVar10 + uVar21);
                *puVar26 = *(undefined4 *)(&DAT_2ad991641fc + uVar21);
                puVar26[1] = uVar9;
                puVar26[2] = uVar8;
                puVar26[3] = uVar14;
                uVar21 = uVar21 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar21);
              if (uVar16 == uVar13) goto LAB_2ad99148f42;
            }
            do {
              *(undefined2 *)(lVar10 + uVar16 * 2) = *(undefined2 *)(&DAT_2ad991641fc + uVar16 * 2);
              uVar16 = uVar16 + 1;
            } while (uVar13 != uVar16);
          }
LAB_2ad99148f42:
          *(uint *)(local_10c + -4) = uVar18;
          *(undefined2 *)(local_10c + (ulonglong)uVar18 * 2) = 0;
        }
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_110);
        uVar20 = CONCAT44(uVar6,0x10a5);
        uVar22 = CONCAT44(uVar5,0x520004);
        iVar4 = (*(code *)0x7ff63a0e49f0)
                          (0x2ad95e68178,0x150,2,0x590008,0x2ad99164188,uVar22,uVar20);
        uVar5 = (undefined4)((ulonglong)uVar22 >> 0x20);
        uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
        if (iVar4 == -1) {
          (*(code *)0x7ff63a0e49f0)
                    (0x2ad95e68178,2,2,0x590008,0x2ad99164370,CONCAT44(uVar5,0x520004),
                     CONCAT44(uVar6,_DAT_2ad99183b10));
          uVar22 = 0x2ad99171f40;
          goto LAB_2ad99148b5e;
        }
        uVar9 = (*(code *)0x7ff63a0e7ec0)(0x2ad95e68178,iVar4);
        (*(code *)0x7ff63a0eaa60)(0x2ad95e68178,iVar4,uVar9);
        FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171f00);
        FUN_2ad99140a40(&local_148,&local_138,0,0x2ad99171f10);
        if (local_144 == (short *)0x0) {
          uVar9 = 0xfa9;
        }
        else {
          uVar12 = *(uint *)(local_144 + -2);
          uVar8 = 0x13ab;
          uVar9 = uVar8;
          if ((uVar12 != 0) && (_DAT_2ad99164248 != 0)) {
            uVar9 = _DAT_2ad99183b10;
            if (local_144 == (short *)0x2ad9916424c) goto LAB_2ad99149312;
            if ((_DAT_2ad99164248 <= uVar12) &&
               (uVar17 = (uVar12 - _DAT_2ad99164248) + 1, uVar17 != 0)) {
              uVar13 = (ulonglong)uVar17;
              if (_DAT_2ad99164248 < 2) {
                if (*local_144 == 0x44) {
LAB_2ad99149312:
                  uVar9 = uVar8;
                  if (_DAT_2ad99164278 != 0) {
                    if (local_144 == (short *)0x2ad9916427c) goto LAB_2ad991495be;
                    uVar9 = _DAT_2ad99183b10;
                    if ((_DAT_2ad99164278 <= uVar12) &&
                       (uVar12 = (uVar12 - _DAT_2ad99164278) + 1, uVar12 != 0)) {
                      uVar13 = (ulonglong)uVar12;
                      if (_DAT_2ad99164278 == 1) {
                        if (*local_144 == 0x65) {
LAB_2ad991495be:
                          if (0 < _DAT_2ad991781c8) {
                            lVar10 = (*(code *)0x7ff63a101d80)(0x2ad95e68178,0);
                            _DAT_2ad991781c8 = lVar10 + -0x3840;
                            if (DAT_2ad9917817c == '\0') {
                              _DAT_2ad991781c8 = lVar10;
                            }
                            _DAT_2ad991781c8 = _DAT_2ad991781c8 + 0x9b;
                          }
                          (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99164308);
                          (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
                          lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ad95e68178,0x2ad991643b0,1,1);
                          uVar22 = 0x2ad99171f40;
                          if (lVar10 != -1) {
                            uVar22 = 0x2ad99171f40;
                            iVar4 = (*(code *)0x7ff63a0e49f0)
                                              (0x2ad95e68178,0x150,2,0x590008,0x2ad991643b0,
                                               CONCAT44(uVar5,0x520004),CONCAT44(uVar6,0x10a5));
                            if (iVar4 != -1) {
                              uVar5 = (*(code *)0x7ff63a0e7ec0)(0x2ad95e68178,iVar4);
                              (*(code *)0x7ff63a0eaa60)(0x2ad95e68178,iVar4,uVar5);
                              FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171f20);
                              FUN_2ad99140a40(&local_148,&local_138,0,0x2ad99171f30);
                              (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
                            }
                          }
                          goto LAB_2ad99148b5e;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar13 - 1 == uVar16) goto LAB_2ad99149104;
                          lVar10 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (local_144[lVar10] != 0x65);
                        if (uVar16 < uVar13) {
LAB_2ad991495b6:
                          if (-1 < (int)uVar16) goto LAB_2ad991495be;
                        }
                      }
                      else {
                        bVar23 = true;
                        uVar21 = 1;
                        uVar16 = 0;
                        do {
                          iVar7 = (int)uVar21;
                          if (local_144[uVar16] == 0x65) {
                            psVar19 = (short *)&DAT_2ad9916427e;
                            lVar10 = (ulonglong)_DAT_2ad99164278 - 1;
                            while (local_144[uVar21] == *psVar19) {
                              psVar19 = psVar19 + 1;
                              uVar21 = (ulonglong)((int)uVar21 + 1);
                              lVar10 = lVar10 + -1;
                              if (lVar10 == 0) goto LAB_2ad991495ac;
                            }
                            if ((int)lVar10 == 0) {
LAB_2ad991495ac:
                              if (bVar23) goto LAB_2ad991495b6;
                              break;
                            }
                          }
                          uVar16 = uVar16 + 1;
                          uVar21 = (ulonglong)(iVar7 + 1);
                          bVar23 = uVar16 < uVar13;
                        } while (uVar16 != uVar13);
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0;
                  do {
                    if (uVar13 - 1 == uVar16) goto LAB_2ad99149104;
                    lVar10 = uVar16 + 1;
                    uVar16 = uVar16 + 1;
                  } while (local_144[lVar10] != 0x44);
                  if (uVar16 < uVar13) {
LAB_2ad99149309:
                    if (-1 < (int)uVar16) goto LAB_2ad99149312;
                  }
                }
              }
              else {
                bVar23 = true;
                uVar16 = 0;
                local_128 = (ulonglong)_DAT_2ad99164248 - 1;
                uVar21 = 1;
                do {
                  iVar7 = (int)uVar21;
                  if (local_144[uVar16] == 0x44) {
                    psVar19 = (short *)&DAT_2ad9916424e;
                    lVar10 = local_128;
                    while (local_144[uVar21] == *psVar19) {
                      psVar19 = psVar19 + 1;
                      uVar21 = (ulonglong)((int)uVar21 + 1);
                      lVar10 = lVar10 + -1;
                      if (lVar10 == 0) goto LAB_2ad991492f5;
                    }
                    if ((int)lVar10 == 0) {
LAB_2ad991492f5:
                      if (bVar23) goto LAB_2ad99149309;
                      break;
                    }
                  }
                  uVar16 = uVar16 + 1;
                  uVar21 = (ulonglong)(iVar7 + 1);
                  bVar23 = uVar16 < uVar13;
                } while (uVar16 != uVar13);
              }
            }
          }
        }
LAB_2ad99149104:
        _DAT_2ad99183b10 = uVar9;
        (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
        uVar22 = 0x2ad99171f40;
        goto LAB_2ad99148b5e;
      }
    }
    uVar5 = 0x2ad;
    (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99164400);
    (*(code *)0x7ff63a0e7cc0)(0x2ad95e68178,0x2ad99164188,0x1000);
    puVar26 = &local_e0;
    puVar25 = &local_b0;
    puVar24 = &local_78;
    iVar4 = (*(code *)0x7ff63a0e5a80)
                      (0x2ad95e68178,0x2ad99163508,&local_100,&local_f0,CONCAT44(uVar5,15000),
                       puVar24,puVar25,puVar26);
    uVar5 = (undefined4)((ulonglong)puVar26 >> 0x20);
    if (iVar4 == -1) {
      uVar22 = 0x2ad99164458;
    }
    else {
      uVar22 = CONCAT44((int)((ulonglong)puVar24 >> 0x20),0x520004);
      uVar20 = CONCAT44((int)((ulonglong)puVar25 >> 0x20),(undefined4)local_a8);
      (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,0xd,2,0x590008,0x2ad991644f8,uVar22,uVar20);
      uVar6 = 0x2ad;
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0x10a6);
      uVar22 = CONCAT44((int)((ulonglong)uVar22 >> 0x20),0x520004);
      iVar7 = (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,0x150,2,0x590008,0x2ad99164188,uVar22,uVar20);
      uVar9 = (undefined4)((ulonglong)uVar22 >> 0x20);
      uVar8 = (undefined4)((ulonglong)uVar20 >> 0x20);
      if (iVar7 != -1) {
        lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ad95e68178,0x2ad99164188,3,1);
        (*(code *)0x7ff63a0e8710)
                  (0x2ad95e68178,iVar7,&local_b0,0,CONCAT44(uVar6,(undefined4)local_a8));
        (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar7);
      }
      uVar22 = 0x2ad99171fb0;
      if (iVar4 < 0) goto LAB_2ad99148b5e;
      uVar20 = CONCAT44(uVar8,0x10a5);
      uVar22 = CONCAT44(uVar9,0x520004);
      iVar4 = (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,0x150,2,0x590008,0x2ad99164188,uVar22,uVar20);
      uVar9 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar6 = (undefined4)((ulonglong)uVar22 >> 0x20);
      if (iVar4 != -1) {
        uVar8 = (*(code *)0x7ff63a0e7ec0)(0x2ad95e68178,iVar4);
        (*(code *)0x7ff63a0eaa60)(0x2ad95e68178,iVar4,uVar8);
        FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171f50);
        FUN_2ad99140a40(&local_148,&local_138,0,0x2ad99171f60);
        if (local_144 == (short *)0x0) {
          uVar8 = 0xfa9;
        }
        else {
          uVar12 = *(uint *)(local_144 + -2);
          uVar14 = 0x13ab;
          uVar8 = uVar14;
          if ((uVar12 != 0) && (_DAT_2ad99164248 != 0)) {
            uVar8 = _DAT_2ad99183b10;
            if (local_144 == (short *)0x2ad9916424c) goto LAB_2ad991491da;
            if ((_DAT_2ad99164248 <= uVar12) &&
               (uVar17 = (uVar12 - _DAT_2ad99164248) + 1, uVar17 != 0)) {
              uVar13 = (ulonglong)uVar17;
              if (_DAT_2ad99164248 < 2) {
                if (*local_144 == 0x44) {
LAB_2ad991491da:
                  uVar8 = uVar14;
                  if (_DAT_2ad99164278 != 0) {
                    if (local_144 == (short *)0x2ad9916427c) goto LAB_2ad99149418;
                    uVar8 = _DAT_2ad99183b10;
                    if ((_DAT_2ad99164278 <= uVar12) &&
                       (uVar12 = (uVar12 - _DAT_2ad99164278) + 1, uVar12 != 0)) {
                      uVar13 = (ulonglong)uVar12;
                      if (_DAT_2ad99164278 == 1) {
                        if (*local_144 == 0x65) {
LAB_2ad99149418:
                          if (0 < _DAT_2ad991781c8) {
                            lVar10 = (*(code *)0x7ff63a101d80)(0x2ad95e68178,0);
                            _DAT_2ad991781c8 = lVar10 + -0x3840;
                            if (DAT_2ad9917817c == '\0') {
                              _DAT_2ad991781c8 = lVar10;
                            }
                            _DAT_2ad991781c8 = _DAT_2ad991781c8 + 0x9b;
                          }
                          (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99164590);
                          (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
                          iVar4 = (*(code *)0x7ff63a0e49f0)
                                            (0x2ad95e68178,0x150,2,0x590008,0x2ad991643b0,
                                             CONCAT44(uVar6,0x520004),CONCAT44(uVar9,0x10a5));
                          if (iVar4 != -1) {
                            uVar5 = (*(code *)0x7ff63a0e7ec0)(0x2ad95e68178,iVar4);
                            (*(code *)0x7ff63a0eaa60)(0x2ad95e68178,iVar4,uVar5);
                            FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171f70);
                            FUN_2ad99140a40(&local_148,&local_138,0,0x2ad99171f80);
                            (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
                          }
                          goto LAB_2ad99148b54;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar13 - 1 == uVar16) goto LAB_2ad99148c6e;
                          lVar11 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (local_144[lVar11] != 0x65);
                        if (uVar16 < uVar13) {
LAB_2ad99149410:
                          if (-1 < (int)uVar16) goto LAB_2ad99149418;
                        }
                      }
                      else {
                        bVar23 = true;
                        uVar21 = 1;
                        uVar16 = 0;
                        local_128 = (ulonglong)_DAT_2ad99164278 - 1;
                        do {
                          iVar7 = (int)uVar21;
                          if (local_144[uVar16] == 0x65) {
                            psVar19 = (short *)&DAT_2ad9916427e;
                            lVar11 = local_128;
                            while (local_144[uVar21] == *psVar19) {
                              psVar19 = psVar19 + 1;
                              uVar21 = (ulonglong)((int)uVar21 + 1);
                              lVar11 = lVar11 + -1;
                              if (lVar11 == 0) goto LAB_2ad99149400;
                            }
                            if ((int)lVar11 == 0) {
LAB_2ad99149400:
                              if (bVar23) goto LAB_2ad99149410;
                              break;
                            }
                          }
                          uVar16 = uVar16 + 1;
                          uVar21 = (ulonglong)(iVar7 + 1);
                          bVar23 = uVar16 < uVar13;
                        } while (uVar16 != uVar13);
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0;
                  do {
                    if (uVar13 - 1 == uVar16) goto LAB_2ad99148c6e;
                    lVar11 = uVar16 + 1;
                    uVar16 = uVar16 + 1;
                  } while (local_144[lVar11] != 0x44);
                  if (uVar16 < uVar13) {
LAB_2ad991491d1:
                    if (-1 < (int)uVar16) goto LAB_2ad991491da;
                  }
                }
              }
              else {
                uVar17 = 1;
                uVar16 = 0;
                local_128 = (ulonglong)_DAT_2ad99164248 - 1;
                bVar23 = true;
                do {
                  if (local_144[uVar16] == 0x44) {
                    psVar19 = (short *)&DAT_2ad9916424e;
                    lVar11 = local_128;
                    uVar15 = uVar17;
                    while (local_144[uVar15] == *psVar19) {
                      psVar19 = psVar19 + 1;
                      uVar15 = uVar15 + 1;
                      lVar11 = lVar11 + -1;
                      if (lVar11 == 0) goto LAB_2ad991491b3;
                    }
                    if ((int)lVar11 == 0) {
LAB_2ad991491b3:
                      if (bVar23) goto LAB_2ad991491d1;
                      break;
                    }
                  }
                  uVar16 = uVar16 + 1;
                  uVar17 = uVar17 + 1;
                  bVar23 = uVar16 < uVar13;
                } while (uVar16 != uVar13);
              }
            }
          }
        }
LAB_2ad99148c6e:
        _DAT_2ad99183b10 = uVar8;
        (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,iVar4);
        (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,_DAT_2ad991781c8,0x54,&local_138);
        (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,lVar10,0x54,&local_120);
        uVar9 = 0x2ad;
        (*(code *)0x7ff63a0e49f0)
                  (0x2ad95e68178,0xd,3,0x590008,0x2ad99164630,CONCAT44(uVar6,0x590008),&local_120,
                   CONCAT44(uVar5,0x590008),&local_138);
        cVar3 = (*(code *)0x7ff63a0e7d80)
                          (0x2ad95e68178,0x2ad99164188,0x1000,0x2ad991643b0,CONCAT44(uVar9,0x1200));
        if (cVar3 != '\0') {
          uVar22 = 0x2ad99164680;
          goto LAB_2ad991487e9;
        }
        goto LAB_2ad99148b54;
      }
      uVar22 = 0x2ad99164370;
    }
    uVar20 = 2;
LAB_2ad99148b4b:
    (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,uVar20,0x590008,uVar22);
  }
  else {
    cVar3 = (*(code *)0x7ff63a0e7d20)(0x2ad95e68178,0x2ad99164188,0x1000);
    if (cVar3 == '\0') {
      uVar22 = 0x2ad991646e0;
LAB_2ad991487e9:
      uVar20 = 1;
      goto LAB_2ad99148b4b;
    }
    _DAT_2ad99183b10 = 0;
    _DAT_2ad99183b80 = 0;
    DAT_2ad99183b88 = 0;
    uVar5 = (*(code *)0x7ff63a0e49f0)
                      (0x2ad95e68178,0x150,2,0x590008,0x2ad99164188,CONCAT44(uVar5,0x520004),
                       CONCAT44(uVar6,0x1025));
    uVar6 = (*(code *)0x7ff63a0e7ec0)(0x2ad95e68178,uVar5);
    (*(code *)0x7ff63a0eaa60)(0x2ad95e68178,uVar5,uVar6);
    FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad99171f90);
    FUN_2ad99140a40(&local_148,&local_138,0,0x2ad99171fa0);
    (*(code *)0x7ff63a0e7e80)(0x2ad95e68178,uVar5);
  }
LAB_2ad99148b54:
  uVar22 = 0x2ad99171fb0;
LAB_2ad99148b5e:
  FUN_2ad99140a40(&local_c0,&local_148,0,uVar22);
  FUN_2ad99140000(&local_100);
  FUN_2ad99140000(&local_148);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_b0);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_78);
  FUN_2ad99140000(&local_e0);
  FUN_2ad99140000(&local_f0);
  FUN_2ad99140a40(0x2ad99183b3c,&local_c0,1,0x2ad99171fc0);
  FUN_2ad99140000(&local_c0);
  FUN_2ad99140000(&local_138);
  FUN_2ad99140000(&local_120);
  FUN_2ad99140000(&local_110);
  FUN_2ad99140a40(&local_d0,0x2ad99183b3c,1,0x2ad99171e80);
  FUN_2ad99140a40(0x2ad99173068,&local_d0,0,0x2ad99171e90);
  FUN_2ad99140000(&local_d0);
  return;
}



/* Address: 2ad99149770 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99149770(void)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  code *pcVar5;
  undefined2 *puVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  short *psVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  ulonglong uVar18;
  longlong *plVar19;
  short *psVar20;
  uint uVar21;
  longlong *plVar22;
  undefined1 *puVar23;
  longlong lVar24;
  undefined1 *puVar25;
  int iVar26;
  uint uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  uint uVar31;
  longlong lVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  longlong lVar35;
  uint uVar36;
  undefined1 *puVar37;
  bool bVar38;
  bool bVar39;
  bool bVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 local_1e8;
  undefined1 *local_1e4;
  longlong *local_1d8;
  ulonglong local_1d0;
  longlong local_1c8;
  undefined4 local_1c0;
  undefined8 local_1bc;
  undefined4 local_1b0;
  short *local_1ac;
  undefined4 local_1a0;
  undefined8 local_19c;
  undefined4 local_190;
  undefined8 local_18c;
  undefined1 *local_180;
  undefined4 local_178;
  undefined8 local_174;
  undefined4 local_168;
  undefined1 *local_164;
  undefined4 local_15c;
  undefined8 local_158;
  undefined4 local_150;
  undefined8 local_14c;
  undefined4 local_144;
  undefined8 local_140;
  undefined4 local_138;
  undefined8 local_134;
  undefined4 local_12c;
  undefined8 local_128;
  undefined4 local_120;
  undefined8 local_11c;
  int iStack_114;
  undefined1 local_110 [4];
  undefined1 *local_10c;
  undefined4 local_104;
  undefined8 local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c4;
  int iStack_bc;
  undefined8 local_b8;
  int local_b0;
  int local_98;
  int local_94;
  int local_90;
  
  local_110 = (undefined1  [4])0x0;
  local_168 = 0;
  local_190 = 0;
  local_1a0 = 0;
  local_1e8 = 0;
  local_1c0 = 0;
  local_1b0 = 0;
  local_18c = 0;
  local_19c = 0;
  local_1e4 = (undefined1 *)0x0;
  local_1bc = 0;
  local_1ac = (short *)0x0;
  local_10c = &DAT_2ad99163b8c;
  local_104 = 0;
  local_100 = 0x2ad99163bac;
  local_f8 = 0;
  local_f4 = 0x2ad99163bcc;
  local_ec = 0;
  local_e8 = 0x2ad99163bfc;
  local_e0 = 0;
  local_dc = 0x2ad99163c2c;
  local_d4 = 0;
  local_d0 = 0x2ad99163c5c;
  local_c8 = 0;
  local_c4 = 0x2ad99163c9c;
  local_164 = &DAT_2ad99163cdc;
  local_15c = 0;
  local_158 = 0x2ad99163cfc;
  local_150 = 0;
  local_14c = 0x2ad99163d2c;
  local_144 = 0;
  local_140 = 0x2ad99163d5c;
  local_138 = 0;
  local_134 = 0x2ad99163d8c;
  local_12c = 0;
  local_128 = 0x2ad99163dbc;
  local_120 = 0;
  local_11c = 0x2ad99163dec;
  FUN_2ad99140a40(&local_1b0,0x2ad99160d08,0,0x2ad99171be0);
  uVar43 = 0xfa9;
  local_178 = 0;
  local_174 = 0;
  if ((_DAT_2ad99183b2c == 0) || (_DAT_2ad99183b2c == 0xc)) {
LAB_2ad99149a39:
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else {
      _DAT_2ad99183b10 = uVar43;
      if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
         (cVar9 = FUN_2ad99140060(0x2ad99183b3c,0), puVar6 = _DAT_2ad99183b40, cVar9 != '\0')) {
        *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
        *puVar6 = 0;
      }
    }
  }
  else {
    iVar11 = *(int *)(_DAT_2ad99183b2c + -4);
    if (iVar11 == 0) {
      uVar43 = 0x13ab;
      goto LAB_2ad99149a39;
    }
    iVar15 = 3;
    if (iVar11 < 3) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar15 = iVar11;
    }
    FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad99183b2c,iVar15);
  }
  FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99171bf0);
  FUN_2ad99140a40(&local_178,&local_1e8,0,0x2ad99171c00);
  uVar43 = 0xfa9;
  local_1c0 = 0;
  local_1bc = 0;
  if ((_DAT_2ad99183b2c != 0) && (_DAT_2ad99183b2c != 0xc)) {
    uVar43 = 0x13ab;
    if (3 < *(uint *)(_DAT_2ad99183b2c + -4)) {
      iVar15 = *(uint *)(_DAT_2ad99183b2c + -4) - 3;
      iVar11 = 3;
      if (iVar15 < 3) {
        _DAT_2ad99183b10 = 0x13ab;
        iVar11 = iVar15;
      }
      FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad99183b2c + 6,iVar11);
      goto LAB_2ad99149bb2;
    }
  }
  if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
    _DAT_2ad99183b10 = 0xfa9;
  }
  else {
    _DAT_2ad99183b10 = uVar43;
    if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
       (cVar9 = FUN_2ad99140060(0x2ad99183b3c,0), puVar6 = _DAT_2ad99183b40, cVar9 != '\0')) {
      *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
      *puVar6 = 0;
    }
  }
LAB_2ad99149bb2:
  FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99171c10);
  FUN_2ad99140a40(&local_1c0,&local_1e8,0,0x2ad99171c20);
  cVar8 = DAT_2ad99183de0;
  cVar7 = DAT_2ad99183dd8;
  cVar9 = DAT_2ad99183dd0;
  _DAT_2ad991774f0 = _DAT_2ad991606b0;
  uRam000002ad991774f4 = uRam000002ad991606b4;
  uRam000002ad991774f8 = uRam000002ad991606b8;
  uRam000002ad991774fc = uRam000002ad991606bc;
  _DAT_2ad99177500 = _DAT_2ad991606b0;
  uRam000002ad99177504 = uRam000002ad991606b4;
  uRam000002ad99177508 = uRam000002ad991606b8;
  uRam000002ad9917750c = uRam000002ad991606bc;
  _DAT_2ad99177510 = _DAT_2ad991606b0;
  uRam000002ad99177514 = uRam000002ad991606b4;
  uRam000002ad99177518 = uRam000002ad991606b8;
  uRam000002ad9917751c = uRam000002ad991606bc;
  _DAT_2ad99177520 = _DAT_2ad991606b0;
  uRam000002ad99177524 = uRam000002ad991606b4;
  uRam000002ad99177528 = uRam000002ad991606b8;
  uRam000002ad9917752c = uRam000002ad991606bc;
  _DAT_2ad99177530 = _DAT_2ad991606b0;
  uRam000002ad99177534 = uRam000002ad991606b4;
  uRam000002ad99177538 = uRam000002ad991606b8;
  uRam000002ad9917753c = uRam000002ad991606bc;
  _DAT_2ad99177540 = _DAT_2ad991606b0;
  uRam000002ad99177544 = uRam000002ad991606b4;
  uRam000002ad99177548 = uRam000002ad991606b8;
  uRam000002ad9917754c = uRam000002ad991606bc;
  _DAT_2ad99177550 = _DAT_2ad991606b0;
  uRam000002ad99177554 = uRam000002ad991606b4;
  uRam000002ad99177558 = uRam000002ad991606b8;
  uRam000002ad9917755c = uRam000002ad991606bc;
  _DAT_2ad99177560 = _DAT_2ad991606b0;
  uRam000002ad99177564 = uRam000002ad991606b4;
  uRam000002ad99177568 = uRam000002ad991606b8;
  uRam000002ad9917756c = uRam000002ad991606bc;
  _DAT_2ad99177570 = _DAT_2ad991606b0;
  uRam000002ad99177574 = uRam000002ad991606b4;
  uRam000002ad99177578 = uRam000002ad991606b8;
  uRam000002ad9917757c = uRam000002ad991606bc;
  _DAT_2ad99177580 = _DAT_2ad991606b0;
  uRam000002ad99177584 = uRam000002ad991606b4;
  uRam000002ad99177588 = uRam000002ad991606b8;
  uRam000002ad9917758c = uRam000002ad991606bc;
  _DAT_2ad99177590 = _DAT_2ad991606b0;
  uRam000002ad99177594 = uRam000002ad991606b4;
  uRam000002ad99177598 = uRam000002ad991606b8;
  uRam000002ad9917759c = uRam000002ad991606bc;
  _DAT_2ad991775a0 = _DAT_2ad991606b0;
  uRam000002ad991775a4 = uRam000002ad991606b4;
  uRam000002ad991775a8 = uRam000002ad991606b8;
  uRam000002ad991775ac = uRam000002ad991606bc;
  _DAT_2ad991775b0 = _DAT_2ad991606b0;
  uRam000002ad991775b4 = uRam000002ad991606b4;
  uRam000002ad991775b8 = uRam000002ad991606b8;
  uRam000002ad991775bc = uRam000002ad991606bc;
  _DAT_2ad991775c0 = _DAT_2ad991606b0;
  uRam000002ad991775c4 = uRam000002ad991606b4;
  uRam000002ad991775c8 = uRam000002ad991606b8;
  uRam000002ad991775cc = uRam000002ad991606bc;
  _DAT_2ad991775d0 = _DAT_2ad991606b0;
  uRam000002ad991775d4 = uRam000002ad991606b4;
  uRam000002ad991775d8 = uRam000002ad991606b8;
  uRam000002ad991775dc = uRam000002ad991606bc;
  _DAT_2ad991775e0 = _DAT_2ad991606b0;
  uRam000002ad991775e4 = uRam000002ad991606b4;
  uRam000002ad991775e8 = uRam000002ad991606b8;
  uRam000002ad991775ec = uRam000002ad991606bc;
  _DAT_2ad991775f0 = _DAT_2ad991606b0;
  uRam000002ad991775f4 = uRam000002ad991606b4;
  uRam000002ad991775f8 = uRam000002ad991606b8;
  uRam000002ad991775fc = uRam000002ad991606bc;
  _DAT_2ad99177600 = _DAT_2ad991606b0;
  uRam000002ad99177604 = uRam000002ad991606b4;
  uRam000002ad99177608 = uRam000002ad991606b8;
  uRam000002ad9917760c = uRam000002ad991606bc;
  _DAT_2ad99177610 = _DAT_2ad991606b0;
  uRam000002ad99177614 = uRam000002ad991606b4;
  uRam000002ad99177618 = uRam000002ad991606b8;
  uRam000002ad9917761c = uRam000002ad991606bc;
  _DAT_2ad99177620 = _DAT_2ad991606b0;
  uRam000002ad99177624 = uRam000002ad991606b4;
  uRam000002ad99177628 = uRam000002ad991606b8;
  uRam000002ad9917762c = uRam000002ad991606bc;
  _DAT_2ad99177630 = _DAT_2ad991606b0;
  uRam000002ad99177634 = uRam000002ad991606b4;
  uRam000002ad99177638 = uRam000002ad991606b8;
  uRam000002ad9917763c = uRam000002ad991606bc;
  _DAT_2ad99177640 = _DAT_2ad991606b0;
  uRam000002ad99177644 = uRam000002ad991606b4;
  uRam000002ad99177648 = uRam000002ad991606b8;
  uRam000002ad9917764c = uRam000002ad991606bc;
  _DAT_2ad99177650 = _DAT_2ad991606b0;
  uRam000002ad99177654 = uRam000002ad991606b4;
  uRam000002ad99177658 = uRam000002ad991606b8;
  uRam000002ad9917765c = uRam000002ad991606bc;
  _DAT_2ad99177660 = _DAT_2ad991606b0;
  uRam000002ad99177664 = uRam000002ad991606b4;
  uRam000002ad99177668 = uRam000002ad991606b8;
  uRam000002ad9917766c = uRam000002ad991606bc;
  _DAT_2ad99177670 = _DAT_2ad991606b0;
  uRam000002ad99177674 = uRam000002ad991606b4;
  uRam000002ad99177678 = uRam000002ad991606b8;
  uRam000002ad9917767c = uRam000002ad991606bc;
  _DAT_2ad99177680 = _DAT_2ad991606b0;
  uRam000002ad99177684 = uRam000002ad991606b4;
  uRam000002ad99177688 = uRam000002ad991606b8;
  uRam000002ad9917768c = uRam000002ad991606bc;
  _DAT_2ad99177690 = _DAT_2ad991606b0;
  uRam000002ad99177694 = uRam000002ad991606b4;
  uRam000002ad99177698 = uRam000002ad991606b8;
  uRam000002ad9917769c = uRam000002ad991606bc;
  _DAT_2ad991776a0 = _DAT_2ad991606b0;
  uRam000002ad991776a4 = uRam000002ad991606b4;
  uRam000002ad991776a8 = uRam000002ad991606b8;
  uRam000002ad991776ac = uRam000002ad991606bc;
  _DAT_2ad991776b0 = _DAT_2ad991606b0;
  uRam000002ad991776b4 = uRam000002ad991606b4;
  uRam000002ad991776b8 = uRam000002ad991606b8;
  uRam000002ad991776bc = uRam000002ad991606bc;
  _DAT_2ad991776c0 = _DAT_2ad991606b0;
  uRam000002ad991776c4 = uRam000002ad991606b4;
  uRam000002ad991776c8 = uRam000002ad991606b8;
  uRam000002ad991776cc = uRam000002ad991606bc;
  _DAT_2ad991776d0 = _DAT_2ad991606b0;
  uRam000002ad991776d4 = uRam000002ad991606b4;
  uRam000002ad991776d8 = uRam000002ad991606b8;
  uRam000002ad991776dc = uRam000002ad991606bc;
  _DAT_2ad991776e0 = _DAT_2ad991606b0;
  uRam000002ad991776e4 = uRam000002ad991606b4;
  uRam000002ad991776e8 = uRam000002ad991606b8;
  uRam000002ad991776ec = uRam000002ad991606bc;
  _DAT_2ad991776f0 = _DAT_2ad991606b0;
  uRam000002ad991776f4 = uRam000002ad991606b4;
  uRam000002ad991776f8 = uRam000002ad991606b8;
  uRam000002ad991776fc = uRam000002ad991606bc;
  _DAT_2ad99177700 = _DAT_2ad991606b0;
  uRam000002ad99177704 = uRam000002ad991606b4;
  uRam000002ad99177708 = uRam000002ad991606b8;
  uRam000002ad9917770c = uRam000002ad991606bc;
  _DAT_2ad99177710 = _DAT_2ad991606b0;
  uRam000002ad99177714 = uRam000002ad991606b4;
  uRam000002ad99177718 = uRam000002ad991606b8;
  uRam000002ad9917771c = uRam000002ad991606bc;
  _DAT_2ad99177720 = _DAT_2ad991606b0;
  uRam000002ad99177724 = uRam000002ad991606b4;
  uRam000002ad99177728 = uRam000002ad991606b8;
  uRam000002ad9917772c = uRam000002ad991606bc;
  _DAT_2ad99177730 = _DAT_2ad991606b0;
  uRam000002ad99177734 = uRam000002ad991606b4;
  uRam000002ad99177738 = uRam000002ad991606b8;
  uRam000002ad9917773c = uRam000002ad991606bc;
  _DAT_2ad99177740 = _DAT_2ad991606b0;
  uRam000002ad99177744 = uRam000002ad991606b4;
  uRam000002ad99177748 = uRam000002ad991606b8;
  uRam000002ad9917774c = uRam000002ad991606bc;
  _DAT_2ad99177750 = _DAT_2ad991606b0;
  uRam000002ad99177754 = uRam000002ad991606b4;
  uRam000002ad99177758 = uRam000002ad991606b8;
  uRam000002ad9917775c = uRam000002ad991606bc;
  _DAT_2ad99177760 = _DAT_2ad991606b0;
  uRam000002ad99177764 = uRam000002ad991606b4;
  uRam000002ad99177768 = uRam000002ad991606b8;
  uRam000002ad9917776c = uRam000002ad991606bc;
  _DAT_2ad99177770 = _DAT_2ad991606b0;
  uRam000002ad99177774 = uRam000002ad991606b4;
  uRam000002ad99177778 = uRam000002ad991606b8;
  uRam000002ad9917777c = uRam000002ad991606bc;
  _DAT_2ad99177780 = _DAT_2ad991606b0;
  uRam000002ad99177784 = uRam000002ad991606b4;
  uRam000002ad99177788 = uRam000002ad991606b8;
  uRam000002ad9917778c = uRam000002ad991606bc;
  _DAT_2ad99177790 = _DAT_2ad991606b0;
  uRam000002ad99177794 = uRam000002ad991606b4;
  uRam000002ad99177798 = uRam000002ad991606b8;
  uRam000002ad9917779c = uRam000002ad991606bc;
  _DAT_2ad991777a0 = _DAT_2ad991606b0;
  uRam000002ad991777a4 = uRam000002ad991606b4;
  uRam000002ad991777a8 = uRam000002ad991606b8;
  uRam000002ad991777ac = uRam000002ad991606bc;
  _DAT_2ad991777b0 = _DAT_2ad991606b0;
  uRam000002ad991777b4 = uRam000002ad991606b4;
  uRam000002ad991777b8 = uRam000002ad991606b8;
  uRam000002ad991777bc = uRam000002ad991606bc;
  _DAT_2ad991777c0 = _DAT_2ad991606b0;
  uRam000002ad991777c4 = uRam000002ad991606b4;
  uRam000002ad991777c8 = uRam000002ad991606b8;
  uRam000002ad991777cc = uRam000002ad991606bc;
  _DAT_2ad991777d0 = _DAT_2ad991606b0;
  uRam000002ad991777d4 = uRam000002ad991606b4;
  uRam000002ad991777d8 = uRam000002ad991606b8;
  uRam000002ad991777dc = uRam000002ad991606bc;
  _DAT_2ad991777e0 = _DAT_2ad991606b0;
  uRam000002ad991777e4 = uRam000002ad991606b4;
  uRam000002ad991777e8 = uRam000002ad991606b8;
  uRam000002ad991777ec = uRam000002ad991606bc;
  _DAT_2ad991777f0 = _DAT_2ad991606b0;
  uRam000002ad991777f4 = uRam000002ad991606b4;
  uRam000002ad991777f8 = uRam000002ad991606b8;
  uRam000002ad991777fc = uRam000002ad991606bc;
  _DAT_2ad99177800 = _DAT_2ad991606b0;
  uRam000002ad99177804 = uRam000002ad991606b4;
  uRam000002ad99177808 = uRam000002ad991606b8;
  uRam000002ad9917780c = uRam000002ad991606bc;
  _DAT_2ad99177810 = _DAT_2ad991606b0;
  uRam000002ad99177814 = uRam000002ad991606b4;
  uRam000002ad99177818 = uRam000002ad991606b8;
  uRam000002ad9917781c = uRam000002ad991606bc;
  _DAT_2ad99177820 = _DAT_2ad991606b0;
  uRam000002ad99177824 = uRam000002ad991606b4;
  uRam000002ad99177828 = uRam000002ad991606b8;
  uRam000002ad9917782c = uRam000002ad991606bc;
  _DAT_2ad99177830 = _DAT_2ad991606b0;
  uRam000002ad99177834 = uRam000002ad991606b4;
  uRam000002ad99177838 = uRam000002ad991606b8;
  uRam000002ad9917783c = uRam000002ad991606bc;
  _DAT_2ad99177840 = _DAT_2ad991606b0;
  uRam000002ad99177844 = uRam000002ad991606b4;
  uRam000002ad99177848 = uRam000002ad991606b8;
  uRam000002ad9917784c = uRam000002ad991606bc;
  _DAT_2ad99177850 = _DAT_2ad991606b0;
  uRam000002ad99177854 = uRam000002ad991606b4;
  uRam000002ad99177858 = uRam000002ad991606b8;
  uRam000002ad9917785c = uRam000002ad991606bc;
  _DAT_2ad99177860 = _DAT_2ad991606b0;
  uRam000002ad99177864 = uRam000002ad991606b4;
  uRam000002ad99177868 = uRam000002ad991606b8;
  uRam000002ad9917786c = uRam000002ad991606bc;
  _DAT_2ad99177870 = _DAT_2ad991606b0;
  uRam000002ad99177874 = uRam000002ad991606b4;
  uRam000002ad99177878 = uRam000002ad991606b8;
  uRam000002ad9917787c = uRam000002ad991606bc;
  _DAT_2ad99177880 = _DAT_2ad991606b0;
  uRam000002ad99177884 = uRam000002ad991606b4;
  uRam000002ad99177888 = uRam000002ad991606b8;
  uRam000002ad9917788c = uRam000002ad991606bc;
  _DAT_2ad99177890 = _DAT_2ad991606b0;
  uRam000002ad99177894 = uRam000002ad991606b4;
  uRam000002ad99177898 = uRam000002ad991606b8;
  uRam000002ad9917789c = uRam000002ad991606bc;
  _DAT_2ad991778a0 = _DAT_2ad991606b0;
  uRam000002ad991778a4 = uRam000002ad991606b4;
  uRam000002ad991778a8 = uRam000002ad991606b8;
  uRam000002ad991778ac = uRam000002ad991606bc;
  _DAT_2ad991778b0 = _DAT_2ad991606b0;
  uRam000002ad991778b4 = uRam000002ad991606b4;
  uRam000002ad991778b8 = uRam000002ad991606b8;
  uRam000002ad991778bc = uRam000002ad991606bc;
  _DAT_2ad991778c0 = _DAT_2ad991606b0;
  uRam000002ad991778c4 = uRam000002ad991606b4;
  uRam000002ad991778c8 = uRam000002ad991606b8;
  uRam000002ad991778cc = uRam000002ad991606bc;
  _DAT_2ad991778d0 = _DAT_2ad991606b0;
  uRam000002ad991778d4 = uRam000002ad991606b4;
  uRam000002ad991778d8 = uRam000002ad991606b8;
  uRam000002ad991778dc = uRam000002ad991606bc;
  _DAT_2ad991778e0 = _DAT_2ad991606b0;
  uRam000002ad991778e4 = uRam000002ad991606b4;
  uRam000002ad991778e8 = uRam000002ad991606b8;
  uRam000002ad991778ec = uRam000002ad991606bc;
  _DAT_2ad991778f0 = _DAT_2ad991606b0;
  uRam000002ad991778f4 = uRam000002ad991606b4;
  uRam000002ad991778f8 = uRam000002ad991606b8;
  uRam000002ad991778fc = uRam000002ad991606bc;
  _DAT_2ad99177900 = _DAT_2ad991606b0;
  uRam000002ad99177904 = uRam000002ad991606b4;
  uRam000002ad99177908 = uRam000002ad991606b8;
  uRam000002ad9917790c = uRam000002ad991606bc;
  _DAT_2ad99177910 = _DAT_2ad991606b0;
  uRam000002ad99177914 = uRam000002ad991606b4;
  uRam000002ad99177918 = uRam000002ad991606b8;
  uRam000002ad9917791c = uRam000002ad991606bc;
  _DAT_2ad99177920 = _DAT_2ad991606b0;
  uRam000002ad99177924 = uRam000002ad991606b4;
  uRam000002ad99177928 = uRam000002ad991606b8;
  uRam000002ad9917792c = uRam000002ad991606bc;
  _DAT_2ad99177930 = _DAT_2ad991606b0;
  uRam000002ad99177934 = uRam000002ad991606b4;
  uRam000002ad99177938 = uRam000002ad991606b8;
  uRam000002ad9917793c = uRam000002ad991606bc;
  _DAT_2ad99177940 = _DAT_2ad991606b0;
  uRam000002ad99177944 = uRam000002ad991606b4;
  uRam000002ad99177948 = uRam000002ad991606b8;
  uRam000002ad9917794c = uRam000002ad991606bc;
  _DAT_2ad99177950 = _DAT_2ad991606b0;
  uRam000002ad99177954 = uRam000002ad991606b4;
  uRam000002ad99177958 = uRam000002ad991606b8;
  uRam000002ad9917795c = uRam000002ad991606bc;
  _DAT_2ad99177960 = _DAT_2ad991606b0;
  uRam000002ad99177964 = uRam000002ad991606b4;
  uRam000002ad99177968 = uRam000002ad991606b8;
  uRam000002ad9917796c = uRam000002ad991606bc;
  _DAT_2ad99177970 = _DAT_2ad991606b0;
  uRam000002ad99177974 = uRam000002ad991606b4;
  uRam000002ad99177978 = uRam000002ad991606b8;
  uRam000002ad9917797c = uRam000002ad991606bc;
  _DAT_2ad99177980 = _DAT_2ad991606b0;
  uRam000002ad99177984 = uRam000002ad991606b4;
  uRam000002ad99177988 = uRam000002ad991606b8;
  uRam000002ad9917798c = uRam000002ad991606bc;
  _DAT_2ad99177990 = _DAT_2ad991606b0;
  uRam000002ad99177994 = uRam000002ad991606b4;
  uRam000002ad99177998 = uRam000002ad991606b8;
  uRam000002ad9917799c = uRam000002ad991606bc;
  _DAT_2ad991779a0 = _DAT_2ad991606b0;
  uRam000002ad991779a4 = uRam000002ad991606b4;
  uRam000002ad991779a8 = uRam000002ad991606b8;
  uRam000002ad991779ac = uRam000002ad991606bc;
  _DAT_2ad991779b0 = _DAT_2ad991606b0;
  uRam000002ad991779b4 = uRam000002ad991606b4;
  uRam000002ad991779b8 = uRam000002ad991606b8;
  uRam000002ad991779bc = uRam000002ad991606bc;
  _DAT_2ad991779c0 = _DAT_2ad991606b0;
  uRam000002ad991779c4 = uRam000002ad991606b4;
  uRam000002ad991779c8 = uRam000002ad991606b8;
  uRam000002ad991779cc = uRam000002ad991606bc;
  _DAT_2ad991779d0 = _DAT_2ad991606b0;
  uRam000002ad991779d4 = uRam000002ad991606b4;
  uRam000002ad991779d8 = uRam000002ad991606b8;
  uRam000002ad991779dc = uRam000002ad991606bc;
  _DAT_2ad991779e0 = _DAT_2ad991606b0;
  uRam000002ad991779e4 = uRam000002ad991606b4;
  uRam000002ad991779e8 = uRam000002ad991606b8;
  uRam000002ad991779ec = uRam000002ad991606bc;
  _DAT_2ad991779f0 = _DAT_2ad991606b0;
  uRam000002ad991779f4 = uRam000002ad991606b4;
  uRam000002ad991779f8 = uRam000002ad991606b8;
  uRam000002ad991779fc = uRam000002ad991606bc;
  _DAT_2ad99177a00 = _DAT_2ad991606b0;
  uRam000002ad99177a04 = uRam000002ad991606b4;
  uRam000002ad99177a08 = uRam000002ad991606b8;
  uRam000002ad99177a0c = uRam000002ad991606bc;
  _DAT_2ad99177a10 = _DAT_2ad991606b0;
  uRam000002ad99177a14 = uRam000002ad991606b4;
  uRam000002ad99177a18 = uRam000002ad991606b8;
  uRam000002ad99177a1c = uRam000002ad991606bc;
  _DAT_2ad99177a20 = _DAT_2ad991606b0;
  uRam000002ad99177a24 = uRam000002ad991606b4;
  uRam000002ad99177a28 = uRam000002ad991606b8;
  uRam000002ad99177a2c = uRam000002ad991606bc;
  _DAT_2ad99177a30 = _DAT_2ad991606b0;
  uRam000002ad99177a34 = uRam000002ad991606b4;
  uRam000002ad99177a38 = uRam000002ad991606b8;
  uRam000002ad99177a3c = uRam000002ad991606bc;
  _DAT_2ad99177a40 = _DAT_2ad991606b0;
  uRam000002ad99177a44 = uRam000002ad991606b4;
  uRam000002ad99177a48 = uRam000002ad991606b8;
  uRam000002ad99177a4c = uRam000002ad991606bc;
  _DAT_2ad99177a50 = _DAT_2ad991606b0;
  uRam000002ad99177a54 = uRam000002ad991606b4;
  uRam000002ad99177a58 = uRam000002ad991606b8;
  uRam000002ad99177a5c = uRam000002ad991606bc;
  _DAT_2ad99177a60 = _DAT_2ad991606b0;
  uRam000002ad99177a64 = uRam000002ad991606b4;
  uRam000002ad99177a68 = uRam000002ad991606b8;
  uRam000002ad99177a6c = uRam000002ad991606bc;
  _DAT_2ad99177a70 = _DAT_2ad991606b0;
  uRam000002ad99177a74 = uRam000002ad991606b4;
  uRam000002ad99177a78 = uRam000002ad991606b8;
  uRam000002ad99177a7c = uRam000002ad991606bc;
  _DAT_2ad99177a80 = _DAT_2ad991606b0;
  uRam000002ad99177a84 = uRam000002ad991606b4;
  uRam000002ad99177a88 = uRam000002ad991606b8;
  uRam000002ad99177a8c = uRam000002ad991606bc;
  _DAT_2ad99177a90 = _DAT_2ad991606b0;
  uRam000002ad99177a94 = uRam000002ad991606b4;
  uRam000002ad99177a98 = uRam000002ad991606b8;
  uRam000002ad99177a9c = uRam000002ad991606bc;
  _DAT_2ad99177aa0 = _DAT_2ad991606b0;
  uRam000002ad99177aa4 = uRam000002ad991606b4;
  uRam000002ad99177aa8 = uRam000002ad991606b8;
  uRam000002ad99177aac = uRam000002ad991606bc;
  _DAT_2ad99177ab0 = _DAT_2ad991606b0;
  uRam000002ad99177ab4 = uRam000002ad991606b4;
  uRam000002ad99177ab8 = uRam000002ad991606b8;
  uRam000002ad99177abc = uRam000002ad991606bc;
  _DAT_2ad99177ac0 = _DAT_2ad991606b0;
  uRam000002ad99177ac4 = uRam000002ad991606b4;
  uRam000002ad99177ac8 = uRam000002ad991606b8;
  uRam000002ad99177acc = uRam000002ad991606bc;
  _DAT_2ad99177ad0 = _DAT_2ad991606b0;
  uRam000002ad99177ad4 = uRam000002ad991606b4;
  uRam000002ad99177ad8 = uRam000002ad991606b8;
  uRam000002ad99177adc = uRam000002ad991606bc;
  _DAT_2ad99177ae0 = _DAT_2ad991606b0;
  uRam000002ad99177ae4 = uRam000002ad991606b4;
  uRam000002ad99177ae8 = uRam000002ad991606b8;
  uRam000002ad99177aec = uRam000002ad991606bc;
  _DAT_2ad99177af0 = _DAT_2ad991606b0;
  uRam000002ad99177af4 = uRam000002ad991606b4;
  uRam000002ad99177af8 = uRam000002ad991606b8;
  uRam000002ad99177afc = uRam000002ad991606bc;
  _DAT_2ad99177b00 = _DAT_2ad991606b0;
  uRam000002ad99177b04 = uRam000002ad991606b4;
  uRam000002ad99177b08 = uRam000002ad991606b8;
  uRam000002ad99177b0c = uRam000002ad991606bc;
  _DAT_2ad99177b10 = _DAT_2ad991606b0;
  uRam000002ad99177b14 = uRam000002ad991606b4;
  uRam000002ad99177b18 = uRam000002ad991606b8;
  uRam000002ad99177b1c = uRam000002ad991606bc;
  _DAT_2ad99177b20 = _DAT_2ad991606b0;
  uRam000002ad99177b24 = uRam000002ad991606b4;
  uRam000002ad99177b28 = uRam000002ad991606b8;
  uRam000002ad99177b2c = uRam000002ad991606bc;
  if (_DAT_2ad99183b14 == 0) {
    local_1d0 = local_1d0 & 0xffffffff00000000;
    local_180 = _DAT_2ad99183df4;
    bVar38 = DAT_2ad99183de8 == '\0';
    bVar39 = _DAT_2ad99183df4 == &DAT_2ad99160d00;
    uVar45 = (undefined4)_DAT_2ad991606c8;
    uVar46 = (undefined4)((ulonglong)_DAT_2ad991606c8 >> 0x20);
    plVar22 = (longlong *)0x0;
    uVar43 = (undefined4)_DAT_2ad991606c0;
    uVar44 = (undefined4)((ulonglong)_DAT_2ad991606c0 >> 0x20);
    uVar47 = (undefined4)_DAT_2ad991606d0;
    uVar48 = (undefined4)((ulonglong)_DAT_2ad991606d0 >> 0x20);
    do {
      local_1d8 = plVar22;
      iVar11 = FUN_2ad991403b0(_DAT_2ad9917306c,0x2ad99163e1c,local_1d0 & 0xffffffff);
      plVar22 = local_1d8;
      if (iVar11 == -1) break;
      uVar21 = iVar11 + 7;
      iVar11 = FUN_2ad991403b0(_DAT_2ad9917306c,0x2ad99163e3c,uVar21);
      local_1d0 = CONCAT44(local_1d0._4_4_,iVar11);
      plVar22 = local_1d8;
      if (iVar11 == -1) break;
      uVar41 = 0xfa9;
      if ((_DAT_2ad9917306c == 0) || (_DAT_2ad9917306c == 0xc)) {
LAB_2ad9914a3ad:
        _DAT_2ad99183b10 = uVar41;
        if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
          _DAT_2ad99183b10 = 0xfa9;
        }
        else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                (cVar10 = FUN_2ad99140060(0x2ad99183b3c,0), puVar6 = _DAT_2ad99183b40,
                cVar10 != '\0')) {
          *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
          *puVar6 = 0;
        }
      }
      else {
        uVar36 = *(uint *)(_DAT_2ad9917306c + -4);
        uVar16 = uVar21;
        if (((int)uVar21 < 0) && (uVar16 = uVar36 + uVar21, (int)uVar16 < 0)) {
          uVar41 = 0x13ab;
          goto LAB_2ad9914a3ad;
        }
        iVar15 = uVar36 - uVar16;
        uVar41 = 0x13ab;
        if (uVar36 < uVar16 || iVar15 == 0) goto LAB_2ad9914a3ad;
        iVar11 = iVar11 - uVar21;
        iVar26 = iVar15;
        if ((-1 < iVar11) && (iVar26 = iVar11, iVar15 < iVar11)) {
          _DAT_2ad99183b10 = 0x13ab;
          iVar26 = iVar15;
        }
        uVar41 = _DAT_2ad99183b10;
        if (iVar26 == 0) goto LAB_2ad9914a3ad;
        FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad9917306c + (ulonglong)uVar16 * 2);
      }
      FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99171c30);
      FUN_2ad99140a40(&local_1b0,&local_1e8,0,0x2ad99171c40);
      uVar21 = (uint)local_1d8;
      if (199 < uVar21) {
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xf09bf000001f6);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      lVar35 = 0;
      uVar36 = 0;
      do {
        FUN_2ad99140a40(&DAT_2ad99173080 + lVar35 * 0xc + (ulonglong)(uVar21 * 7) * 0xc,
                        0x2ad99160d08,0,0x2ad99171c50);
        if ((local_1ac == (short *)0x0) ||
           (psVar12 = *(short **)((longlong)&local_10c + lVar35 * 0xc), psVar12 == (short *)0x0)) {
LAB_2ad9914a490:
          _DAT_2ad99183b10 = 0xfa9;
        }
        else {
          uVar16 = *(uint *)(local_1ac + -2);
          if ((uVar16 == 0) || (uVar17 = *(uint *)(psVar12 + -2), uVar17 == 0)) {
            _DAT_2ad99183b10 = 0x13ab;
          }
          else {
            uVar28 = 0;
            if (0 < (int)uVar36) {
              uVar28 = (ulonglong)uVar36;
            }
            uVar27 = (uint)uVar28;
            if (local_1ac == psVar12) {
              uVar27 = -(uint)(0 < (int)uVar36);
LAB_2ad9914a592:
              if (uVar27 != 0xffffffff) {
LAB_2ad9914a59c:
                if (psVar12 == (short *)0xc) {
                  uVar17 = 0;
                }
                psVar12 = *(short **)((longlong)&local_164 + lVar35 * 0xc);
                uVar36 = uVar17 + uVar27;
                if (psVar12 == (short *)0x0) goto LAB_2ad9914a490;
                uVar17 = *(uint *)(psVar12 + -2);
                if (uVar17 == 0) {
                  _DAT_2ad99183b10 = 0x13ab;
                  goto LAB_2ad9914a4a0;
                }
                uVar27 = 0;
                if (0 < (int)uVar36) {
                  uVar27 = uVar36;
                }
                if (local_1ac == psVar12) {
                  uVar27 = -(uint)(0 < (int)uVar36);
                  goto LAB_2ad9914a630;
                }
                uVar31 = uVar16 - uVar27;
                if (((uVar27 <= uVar16 && uVar31 != 0) && (uVar17 <= uVar31)) &&
                   (uVar31 = (uVar31 - uVar17) + 1, uVar31 != 0)) {
                  sVar2 = *psVar12;
                  uVar28 = (ulonglong)uVar31;
                  psVar20 = local_1ac + uVar27;
                  if (uVar17 == 1) {
                    if (*psVar20 != sVar2) {
                      uVar29 = 0;
                      do {
                        if (uVar28 - 1 == uVar29) goto LAB_2ad9914a4a0;
                        lVar24 = uVar29 + 1;
                        uVar29 = uVar29 + 1;
                      } while (local_1ac[(ulonglong)uVar27 + lVar24] != sVar2);
                      if (uVar28 <= uVar29) goto LAB_2ad9914a4a0;
                      uVar27 = uVar27 + (int)uVar29;
                    }
LAB_2ad9914a630:
                    iVar11 = uVar27 - uVar36;
                    if ((iVar11 != 0 && (int)uVar36 <= (int)uVar27) && (uVar27 != 0xffffffff)) {
                      if (local_1ac == (short *)0xc) {
                        uVar41 = 0xfa9;
LAB_2ad9914a7d0:
                        _DAT_2ad99183b10 = uVar41;
                        if ((_DAT_2ad99183b40 == (undefined2 *)0x0) ||
                           (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
                          _DAT_2ad99183b10 = 0xfa9;
                        }
                        else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                                (cVar10 = FUN_2ad99140060(0x2ad99183b3c,0),
                                puVar6 = _DAT_2ad99183b40, cVar10 != '\0')) {
                          *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
                          *puVar6 = 0;
                        }
                      }
                      else {
                        uVar17 = uVar36;
                        if (((int)uVar36 < 0) && (uVar17 = uVar16 + uVar36, (int)uVar17 < 0)) {
                          uVar41 = 0x13ab;
                          goto LAB_2ad9914a7d0;
                        }
                        iVar15 = uVar16 - uVar17;
                        uVar41 = 0x13ab;
                        if (uVar16 < uVar17 || iVar15 == 0) goto LAB_2ad9914a7d0;
                        iVar26 = iVar15;
                        if ((-1 < iVar11) && (iVar26 = iVar11, iVar15 < iVar11)) {
                          _DAT_2ad99183b10 = 0x13ab;
                          iVar26 = iVar15;
                        }
                        uVar41 = _DAT_2ad99183b10;
                        if (iVar26 == 0) goto LAB_2ad9914a7d0;
                        FUN_2ad991401d0(0x2ad99183b3c,local_1ac + uVar17);
                      }
                      FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99171c60);
                      FUN_2ad99140a40(&DAT_2ad99173080 +
                                      lVar35 * 0xc + (ulonglong)(uVar21 * 7) * 0xc,&local_1e8,0,
                                      0x2ad99171c70);
                    }
                  }
                  else {
                    bVar40 = true;
                    uVar29 = 0;
                    do {
                      if (psVar20[uVar29] == sVar2) {
                        lVar32 = 1;
                        lVar24 = (ulonglong)uVar17 - 1;
                        while (psVar20[(uint)((int)uVar29 + (int)lVar32)] == psVar12[lVar32]) {
                          lVar32 = lVar32 + 1;
                          lVar24 = lVar24 + -1;
                          if (lVar24 == 0) goto LAB_2ad9914a939;
                        }
                        if ((int)lVar24 == 0) {
LAB_2ad9914a939:
                          if (bVar40) {
                            uVar27 = uVar27 + (int)uVar29;
                            goto LAB_2ad9914a630;
                          }
                          break;
                        }
                      }
                      uVar29 = uVar29 + 1;
                      bVar40 = uVar29 < uVar28;
                    } while (uVar29 != uVar28);
                  }
                }
              }
            }
            else {
              uVar31 = uVar16 - uVar27;
              if (((uVar27 <= uVar16 && uVar31 != 0) && (uVar17 <= uVar31)) &&
                 (uVar31 = (uVar31 - uVar17) + 1, uVar31 != 0)) {
                sVar2 = *psVar12;
                uVar29 = (ulonglong)uVar31;
                psVar20 = local_1ac + uVar28;
                if (uVar17 < 2) {
                  if (*psVar20 == sVar2) goto LAB_2ad9914a59c;
                  uVar18 = 0;
                  do {
                    if (uVar29 - 1 == uVar18) goto LAB_2ad9914a4a0;
                    lVar24 = uVar18 + 1;
                    uVar18 = uVar18 + 1;
                  } while (local_1ac[uVar28 + lVar24] != sVar2);
                  if (uVar18 < uVar29) {
                    uVar27 = uVar27 + (int)uVar18;
                    goto LAB_2ad9914a592;
                  }
                }
                else {
                  bVar40 = true;
                  uVar28 = 0;
                  local_1c8 = (ulonglong)uVar17 - 1;
                  do {
                    if (psVar20[uVar28] == sVar2) {
                      lVar32 = 1;
                      lVar24 = local_1c8;
                      while (psVar20[(uint)((int)uVar28 + (int)lVar32)] == psVar12[lVar32]) {
                        lVar32 = lVar32 + 1;
                        lVar24 = lVar24 + -1;
                        if (lVar24 == 0) goto LAB_2ad9914a76a;
                      }
                      if ((int)lVar24 == 0) {
LAB_2ad9914a76a:
                        if (bVar40) {
                          uVar27 = uVar27 + (int)uVar28;
                          goto LAB_2ad9914a592;
                        }
                        break;
                      }
                    }
                    uVar28 = uVar28 + 1;
                    bVar40 = uVar28 < uVar29;
                  } while (uVar28 != uVar29);
                }
              }
            }
          }
        }
LAB_2ad9914a4a0:
        plVar22 = local_1d8;
        bVar40 = lVar35 != 6;
        lVar35 = lVar35 + 1;
      } while (bVar40);
      uVar28 = (ulonglong)local_1d8 & 0xffffffff;
      lVar35 = uVar28 * 0x54;
      FUN_2ad99140a40(&local_1e8,&DAT_2ad9917308c + lVar35);
      if (cVar9 == '\0') {
LAB_2ad9914aa5d:
        if (cVar7 != '\0') {
          if (local_1e4 == &DAT_2ad99163b6c) goto LAB_2ad9914aae0;
          if (local_1e4 != (undefined1 *)0x0) {
            uVar21 = *(uint *)(local_1e4 + -4);
            uVar36 = _DAT_2ad99163b68;
            if (uVar21 < _DAT_2ad99163b68) {
              uVar36 = uVar21;
            }
            iVar11 = uVar21 - _DAT_2ad99163b68;
            if (uVar36 != 0) {
              uVar29 = 0;
              do {
                uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
                uVar4 = *(ushort *)(&DAT_2ad99163b6c + uVar29 * 2);
                uVar29 = uVar29 + 1;
                if (uVar36 <= uVar29) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar11 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar11 == 0) goto LAB_2ad9914aae0;
          }
        }
      }
      else {
        if (local_1e4 != &DAT_2ad99163b4c) {
          if (local_1e4 == (undefined1 *)0x0) goto LAB_2ad9914a2b0;
          uVar21 = *(uint *)(local_1e4 + -4);
          uVar36 = _DAT_2ad99163b48;
          if (uVar21 < _DAT_2ad99163b48) {
            uVar36 = uVar21;
          }
          iVar11 = uVar21 - _DAT_2ad99163b48;
          if (uVar36 != 0) {
            uVar29 = 0;
            do {
              uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
              uVar4 = *(ushort *)(&DAT_2ad99163b4c + uVar29 * 2);
              uVar29 = uVar29 + 1;
              if (uVar36 <= uVar29) break;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar11 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar11 != 0) goto LAB_2ad9914aa5d;
        }
LAB_2ad9914aae0:
        puVar33 = &DAT_2ad99173080 + lVar35;
        if (cVar8 != '\0') {
          puVar25 = *(undefined1 **)(lVar35 + 0x2ad991730b4);
          if (puVar25 == &DAT_2ad99163b2c) goto LAB_2ad9914a2b0;
          if (puVar25 != (undefined1 *)0x0) {
            uVar21 = *(uint *)(puVar25 + -4);
            uVar36 = _DAT_2ad99163b28;
            if (uVar21 < _DAT_2ad99163b28) {
              uVar36 = uVar21;
            }
            iVar11 = uVar21 - _DAT_2ad99163b28;
            if (uVar36 != 0) {
              uVar29 = 0;
              do {
                uVar3 = *(ushort *)(puVar25 + uVar29 * 2);
                uVar4 = *(ushort *)(&DAT_2ad99163b2c + uVar29 * 2);
                uVar29 = uVar29 + 1;
                if (uVar36 <= uVar29) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar11 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar11 == 0) goto LAB_2ad9914a2b0;
          }
        }
        puVar25 = *(undefined1 **)(lVar35 + 0x2ad991730b4);
        if (DAT_2ad99173060 == '\0') {
          if (puVar25 != &DAT_2ad99163acc) {
            if (puVar25 == (undefined1 *)0x0) goto LAB_2ad9914ad11;
            uVar21 = *(uint *)(puVar25 + -4);
            uVar36 = _DAT_2ad99163ac8;
            if (uVar21 < _DAT_2ad99163ac8) {
              uVar36 = uVar21;
            }
            iVar11 = uVar21 - _DAT_2ad99163ac8;
            if (uVar36 != 0) {
              uVar29 = 0;
              do {
                uVar3 = *(ushort *)(puVar25 + uVar29 * 2);
                uVar4 = *(ushort *)(&DAT_2ad99163acc + uVar29 * 2);
                uVar29 = uVar29 + 1;
                if (uVar36 <= uVar29) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar11 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar11 != 0) goto LAB_2ad9914ac0d;
          }
        }
        else {
LAB_2ad9914ac0d:
          if (puVar25 != &DAT_2ad99163aec) {
            if (puVar25 == (undefined1 *)0x0) {
LAB_2ad9914ad11:
              puVar25 = (undefined1 *)0x0;
joined_r0x02ad9914ad2a:
              uVar41 = _DAT_2ad99183b10;
              if (DAT_2ad99173061 == '\0') {
                psVar12 = *(short **)(&DAT_2ad99173084 + lVar35);
                if (psVar12 == (short *)0x0) {
                  uVar41 = 0xfa9;
                }
                else {
                  uVar21 = *(uint *)(psVar12 + -2);
                  uVar41 = 0x13ab;
                  if ((uVar21 != 0) && (_DAT_2ad99163e58 != 0)) {
                    if (psVar12 == (short *)0x2ad99163e5c) goto LAB_2ad9914a2b0;
                    uVar41 = _DAT_2ad99183b10;
                    if ((_DAT_2ad99163e58 <= uVar21) &&
                       (uVar21 = (uVar21 - _DAT_2ad99163e58) + 1, uVar21 != 0)) {
                      uVar29 = (ulonglong)uVar21;
                      if (_DAT_2ad99163e58 < 2) {
                        if (*psVar12 == 0x53) goto LAB_2ad9914a2b0;
                        uVar18 = 0;
                        do {
                          if (uVar29 - 1 == uVar18) goto LAB_2ad9914ada7;
                          lVar24 = uVar18 + 1;
                          uVar18 = uVar18 + 1;
                        } while (psVar12[lVar24] != 0x53);
                        if (uVar18 < uVar29) {
LAB_2ad9914b444:
                          if ((int)uVar18 != -1) goto LAB_2ad9914a2b0;
                        }
                      }
                      else {
                        bVar40 = true;
                        uVar30 = 1;
                        uVar18 = 0;
                        do {
                          iVar11 = (int)uVar30;
                          if (psVar12[uVar18] == 0x53) {
                            psVar20 = (short *)&DAT_2ad99163e5e;
                            lVar24 = (ulonglong)_DAT_2ad99163e58 - 1;
                            while (psVar12[uVar30] == *psVar20) {
                              psVar20 = psVar20 + 1;
                              uVar30 = (ulonglong)((int)uVar30 + 1);
                              lVar24 = lVar24 + -1;
                              if (lVar24 == 0) goto LAB_2ad9914b412;
                            }
                            if ((int)lVar24 == 0) {
LAB_2ad9914b412:
                              if (bVar40) goto LAB_2ad9914b444;
                              break;
                            }
                          }
                          uVar18 = uVar18 + 1;
                          uVar30 = (ulonglong)(iVar11 + 1);
                          bVar40 = uVar18 < uVar29;
                        } while (uVar18 != uVar29);
                      }
                    }
                  }
                }
              }
LAB_2ad9914ada7:
              _DAT_2ad99183b10 = uVar41;
              puVar34 = *(undefined1 **)(lVar35 + 0x2ad991730a8);
              if (puVar34 == &DAT_2ad99163e7c) {
                if (puVar25 == &DAT_2ad99163b2c) goto LAB_2ad9914aeba;
LAB_2ad9914ae47:
                if (puVar25 != (undefined1 *)0x0) {
                  uVar21 = *(uint *)(puVar25 + -4);
                  uVar36 = _DAT_2ad99163b28;
                  if (uVar21 < _DAT_2ad99163b28) {
                    uVar36 = uVar21;
                  }
                  iVar11 = uVar21 - _DAT_2ad99163b28;
                  if (uVar36 != 0) {
                    uVar29 = 0;
                    do {
                      uVar3 = *(ushort *)(puVar25 + uVar29 * 2);
                      uVar4 = *(ushort *)(&DAT_2ad99163b2c + uVar29 * 2);
                      uVar29 = uVar29 + 1;
                      if (uVar36 <= uVar29) break;
                    } while (uVar3 == uVar4);
                    if (uVar3 != uVar4) {
                      iVar11 = (uint)uVar3 - (uint)uVar4;
                    }
                  }
                  if (iVar11 == 0) goto LAB_2ad9914aeba;
                }
              }
              else if (puVar34 == (undefined1 *)0x0) {
LAB_2ad9914afad:
                if (bVar39 || bVar38) {
LAB_2ad9914afb8:
                  uVar41 = _DAT_2ad99183b10;
                  if ((_DAT_2ad99178174 != (short *)&DAT_2ad99160d00) &&
                     (uVar41 = 0xfa9, _DAT_2ad99178174 != (short *)0x0)) {
                    uVar21 = *(uint *)(_DAT_2ad99178174 + -2);
                    uVar36 = _DAT_2ad99160cfc;
                    if (uVar21 < _DAT_2ad99160cfc) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99160cfc;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = _DAT_2ad99178174[uVar29];
                        uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    uVar41 = _DAT_2ad99183b10;
                    if ((iVar11 != 0) &&
                       (psVar12 = *(short **)(&DAT_2ad99173084 + lVar35), uVar41 = 0xfa9,
                       psVar12 != (short *)0x0)) {
                      uVar36 = *(uint *)(psVar12 + -2);
                      uVar41 = 0x13ab;
                      if ((uVar36 != 0) && (uVar21 != 0)) {
                        if (psVar12 == _DAT_2ad99178174) goto LAB_2ad9914a2b0;
                        uVar41 = _DAT_2ad99183b10;
                        if ((uVar21 <= uVar36) && (uVar36 = (uVar36 - uVar21) + 1, uVar36 != 0)) {
                          sVar2 = *_DAT_2ad99178174;
                          uVar29 = (ulonglong)uVar36;
                          if (uVar21 < 2) {
                            if (*psVar12 == sVar2) goto LAB_2ad9914a2b0;
                            uVar18 = 0;
                            do {
                              if (uVar29 - 1 == uVar18) goto LAB_2ad9914b2e1;
                              lVar24 = uVar18 + 1;
                              uVar18 = uVar18 + 1;
                            } while (psVar12[lVar24] != sVar2);
                            if (uVar18 < uVar29) {
LAB_2ad9914b711:
                              if ((int)uVar18 != -1) goto LAB_2ad9914a2b0;
                            }
                          }
                          else {
                            bVar40 = true;
                            uVar18 = 0;
                            do {
                              if (psVar12[uVar18] == sVar2) {
                                lVar32 = 1;
                                lVar24 = (ulonglong)uVar21 - 1;
                                while (psVar12[(uint)((int)uVar18 + (int)lVar32)] ==
                                       _DAT_2ad99178174[lVar32]) {
                                  lVar32 = lVar32 + 1;
                                  lVar24 = lVar24 + -1;
                                  if (lVar24 == 0) goto LAB_2ad9914b6e9;
                                }
                                if ((int)lVar24 == 0) {
LAB_2ad9914b6e9:
                                  if (bVar40) goto LAB_2ad9914b711;
                                  break;
                                }
                              }
                              uVar18 = uVar18 + 1;
                              bVar40 = uVar18 < uVar29;
                            } while (uVar18 != uVar29);
                          }
                        }
                      }
                    }
                  }
LAB_2ad9914b2e1:
                  _DAT_2ad99183b10 = uVar41;
                  psVar12 = *(short **)(&DAT_2ad99173084 + lVar35);
                  if (psVar12 == (short *)0x0) {
LAB_2ad9914b645:
                    _DAT_2ad99183b10 = 0xfa9;
                    goto LAB_2ad9914b8ce;
                  }
                  uVar21 = *(uint *)(psVar12 + -2);
                  if ((uVar21 == 0) || (_DAT_2ad99163eb8 == 0)) {
                    _DAT_2ad99183b10 = 0x13ab;
                    uVar21 = *(uint *)(psVar12 + -2);
joined_r0x02ad9914b35f:
                    if (uVar21 != 0) goto LAB_2ad9914b529;
LAB_2ad9914b748:
                    _DAT_2ad99183b10 = 0x13ab;
LAB_2ad9914b758:
                    uVar21 = *(uint *)(psVar12 + -2);
                    if (uVar21 == 0) goto LAB_2ad9914b8be;
LAB_2ad9914b763:
                    if (_DAT_2ad99163ed8 == 0) goto LAB_2ad9914b8be;
                    if (psVar12 == (short *)0x2ad99163edc) goto LAB_2ad9914b87a;
                    if ((_DAT_2ad99163ed8 <= uVar21) &&
                       (uVar21 = (uVar21 - _DAT_2ad99163ed8) + 1, uVar21 != 0)) {
                      uVar29 = (ulonglong)uVar21;
                      if (_DAT_2ad99163ed8 < 2) {
                        if (*psVar12 == 0x5d) {
LAB_2ad9914b87a:
                          FUN_2ad991404e0(puVar33,0x2ad99163edc);
                        }
                        else {
                          uVar18 = 0;
                          do {
                            if (uVar29 - 1 == uVar18) goto LAB_2ad9914b8ce;
                            lVar24 = uVar18 + 1;
                            uVar18 = uVar18 + 1;
                          } while (psVar12[lVar24] != 0x5d);
                          if (uVar18 < uVar29) {
LAB_2ad9914b875:
                            if ((int)uVar18 != -1) goto LAB_2ad9914b87a;
                          }
                        }
                      }
                      else {
                        bVar40 = true;
                        uVar30 = 1;
                        uVar18 = 0;
                        do {
                          iVar11 = (int)uVar30;
                          if (psVar12[uVar18] == 0x5d) {
                            psVar20 = (short *)&DAT_2ad99163ede;
                            lVar24 = (ulonglong)_DAT_2ad99163ed8 - 1;
                            while (psVar12[uVar30] == *psVar20) {
                              psVar20 = psVar20 + 1;
                              uVar30 = (ulonglong)((int)uVar30 + 1);
                              lVar24 = lVar24 + -1;
                              if (lVar24 == 0) goto LAB_2ad9914b851;
                            }
                            if ((int)lVar24 == 0) {
LAB_2ad9914b851:
                              if (bVar40) goto LAB_2ad9914b875;
                              break;
                            }
                          }
                          uVar18 = uVar18 + 1;
                          uVar30 = (ulonglong)(iVar11 + 1);
                          bVar40 = uVar18 < uVar29;
                        } while (uVar18 != uVar29);
                      }
                    }
                  }
                  else {
                    if (psVar12 == (short *)0x2ad99163ebc) goto LAB_2ad9914b4f7;
                    if ((uVar21 < _DAT_2ad99163eb8) ||
                       (uVar21 = (uVar21 - _DAT_2ad99163eb8) + 1, uVar21 == 0)) {
LAB_2ad9914b515:
                      if (psVar12 == (short *)0x0) goto LAB_2ad9914b645;
                    }
                    else {
                      uVar29 = (ulonglong)uVar21;
                      if (1 < _DAT_2ad99163eb8) {
                        bVar40 = true;
                        uVar30 = 1;
                        uVar18 = 0;
                        do {
                          iVar11 = (int)uVar30;
                          if (psVar12[uVar18] == 0x3c) {
                            psVar20 = (short *)&DAT_2ad99163ebe;
                            lVar24 = (ulonglong)_DAT_2ad99163eb8 - 1;
                            while (psVar12[uVar30] == *psVar20) {
                              psVar20 = psVar20 + 1;
                              uVar30 = (ulonglong)((int)uVar30 + 1);
                              lVar24 = lVar24 + -1;
                              if (lVar24 == 0) goto LAB_2ad9914b4ce;
                            }
                            if ((int)lVar24 == 0) {
LAB_2ad9914b4ce:
                              if (bVar40) goto LAB_2ad9914b4f2;
                              goto LAB_2ad9914b515;
                            }
                          }
                          uVar18 = uVar18 + 1;
                          uVar30 = (ulonglong)(iVar11 + 1);
                          bVar40 = uVar18 < uVar29;
                        } while (uVar18 != uVar29);
                        uVar21 = *(uint *)(psVar12 + -2);
                        goto joined_r0x02ad9914b35f;
                      }
                      if (*psVar12 == 0x3c) {
LAB_2ad9914b4f7:
                        FUN_2ad991404e0(puVar33,0x2ad99163ebc);
                        psVar12 = *(short **)(&DAT_2ad99173084 + lVar35);
                        goto LAB_2ad9914b515;
                      }
                      uVar18 = 0;
                      do {
                        if (uVar29 - 1 == uVar18) goto LAB_2ad9914b515;
                        lVar24 = uVar18 + 1;
                        uVar18 = uVar18 + 1;
                      } while (psVar12[lVar24] != 0x3c);
                      if (uVar18 < uVar29) {
LAB_2ad9914b4f2:
                        if ((int)uVar18 == -1) goto LAB_2ad9914b515;
                        goto LAB_2ad9914b4f7;
                      }
                    }
                    uVar21 = *(uint *)(psVar12 + -2);
                    if (uVar21 == 0) goto LAB_2ad9914b748;
LAB_2ad9914b529:
                    if (_DAT_2ad99163ed8 == 0) goto LAB_2ad9914b748;
                    if (psVar12 == (short *)0x2ad99163edc) goto LAB_2ad9914b61e;
                    if ((uVar21 < _DAT_2ad99163ed8) ||
                       (uVar21 = (uVar21 - _DAT_2ad99163ed8) + 1, uVar21 == 0)) {
LAB_2ad9914b63c:
                      if (psVar12 == (short *)0x0) goto LAB_2ad9914b645;
                      goto LAB_2ad9914b758;
                    }
                    uVar29 = (ulonglong)uVar21;
                    if (_DAT_2ad99163ed8 < 2) {
                      if (*psVar12 == 0x5d) {
LAB_2ad9914b61e:
                        FUN_2ad991404e0(puVar33,0x2ad99163edc);
                        psVar12 = *(short **)(&DAT_2ad99173084 + lVar35);
                        goto LAB_2ad9914b63c;
                      }
                      uVar18 = 0;
                      do {
                        if (uVar29 - 1 == uVar18) goto LAB_2ad9914b63c;
                        lVar24 = uVar18 + 1;
                        uVar18 = uVar18 + 1;
                      } while (psVar12[lVar24] != 0x5d);
                      if (uVar18 < uVar29) {
LAB_2ad9914b619:
                        if ((int)uVar18 == -1) goto LAB_2ad9914b63c;
                        goto LAB_2ad9914b61e;
                      }
                      goto LAB_2ad9914b758;
                    }
                    bVar40 = true;
                    uVar30 = 1;
                    uVar18 = 0;
                    do {
                      iVar11 = (int)uVar30;
                      if (psVar12[uVar18] == 0x5d) {
                        psVar20 = (short *)&DAT_2ad99163ede;
                        lVar24 = (ulonglong)_DAT_2ad99163ed8 - 1;
                        while (psVar12[uVar30] == *psVar20) {
                          psVar20 = psVar20 + 1;
                          uVar30 = (ulonglong)((int)uVar30 + 1);
                          lVar24 = lVar24 + -1;
                          if (lVar24 == 0) goto LAB_2ad9914b5f5;
                        }
                        if ((int)lVar24 == 0) {
LAB_2ad9914b5f5:
                          if (bVar40) goto LAB_2ad9914b619;
                          goto LAB_2ad9914b63c;
                        }
                      }
                      uVar18 = uVar18 + 1;
                      uVar30 = (ulonglong)(iVar11 + 1);
                      bVar40 = uVar18 < uVar29;
                    } while (uVar18 != uVar29);
                    uVar21 = *(uint *)(psVar12 + -2);
                    if (uVar21 != 0) goto LAB_2ad9914b763;
LAB_2ad9914b8be:
                    _DAT_2ad99183b10 = 0x13ab;
                  }
LAB_2ad9914b8ce:
                  psVar12 = *(short **)(lVar35 + 0x2ad991730c0);
                  if (psVar12 == (short *)0x0) {
                    _DAT_2ad99183b10 = 0xfa9;
                  }
                  else {
                    uVar21 = *(uint *)(psVar12 + -2);
                    if ((uVar21 == 0) || (_DAT_2ad99163ef8 == 0)) {
                      _DAT_2ad99183b10 = 0x13ab;
                    }
                    else {
                      if (psVar12 == (short *)0x2ad99163efc) goto LAB_2ad9914ba20;
                      if ((_DAT_2ad99163ef8 <= uVar21) &&
                         (uVar21 = (uVar21 - _DAT_2ad99163ef8) + 1, uVar21 != 0)) {
                        uVar29 = (ulonglong)uVar21;
                        if (_DAT_2ad99163ef8 < 2) {
                          if (*psVar12 == 0x26) {
LAB_2ad9914ba20:
                            FUN_2ad991404e0(lVar35 + 0x2ad991730bc,0x2ad99163efc);
                          }
                          else {
                            uVar18 = 0;
                            do {
                              if (uVar29 - 1 == uVar18) goto LAB_2ad9914ba39;
                              lVar24 = uVar18 + 1;
                              uVar18 = uVar18 + 1;
                            } while (psVar12[lVar24] != 0x26);
                            if (uVar18 < uVar29) {
LAB_2ad9914ba1b:
                              if ((int)uVar18 != -1) goto LAB_2ad9914ba20;
                            }
                          }
                        }
                        else {
                          bVar40 = true;
                          uVar30 = 1;
                          uVar18 = 0;
                          do {
                            iVar11 = (int)uVar30;
                            if (psVar12[uVar18] == 0x26) {
                              psVar20 = (short *)&DAT_2ad99163efe;
                              lVar24 = (ulonglong)_DAT_2ad99163ef8 - 1;
                              while (psVar12[uVar30] == *psVar20) {
                                psVar20 = psVar20 + 1;
                                uVar30 = (ulonglong)((int)uVar30 + 1);
                                lVar24 = lVar24 + -1;
                                if (lVar24 == 0) goto LAB_2ad9914b9f7;
                              }
                              if ((int)lVar24 == 0) {
LAB_2ad9914b9f7:
                                if (bVar40) goto LAB_2ad9914ba1b;
                                break;
                              }
                            }
                            uVar18 = uVar18 + 1;
                            uVar30 = (ulonglong)(iVar11 + 1);
                            bVar40 = uVar18 < uVar29;
                          } while (uVar18 != uVar29);
                        }
                      }
                    }
                  }
LAB_2ad9914ba39:
                  psVar12 = *(short **)(lVar35 + 0x2ad991730cc);
                  if (psVar12 == (short *)0x0) {
                    _DAT_2ad99183b10 = 0xfa9;
                  }
                  else {
                    uVar21 = *(uint *)(psVar12 + -2);
                    if ((uVar21 == 0) || (_DAT_2ad99163ef8 == 0)) {
                      _DAT_2ad99183b10 = 0x13ab;
                    }
                    else {
                      if (psVar12 == (short *)0x2ad99163efc) goto LAB_2ad9914bb90;
                      if ((_DAT_2ad99163ef8 <= uVar21) &&
                         (uVar21 = (uVar21 - _DAT_2ad99163ef8) + 1, uVar21 != 0)) {
                        uVar29 = (ulonglong)uVar21;
                        if (_DAT_2ad99163ef8 < 2) {
                          if (*psVar12 == 0x26) {
LAB_2ad9914bb90:
                            FUN_2ad991404e0(lVar35 + 0x2ad991730c8,0x2ad99163efc);
                          }
                          else {
                            uVar18 = 0;
                            do {
                              if (uVar29 - 1 == uVar18) goto LAB_2ad9914bbab;
                              lVar24 = uVar18 + 1;
                              uVar18 = uVar18 + 1;
                            } while (psVar12[lVar24] != 0x26);
                            if (uVar18 < uVar29) {
LAB_2ad9914bb8b:
                              if ((int)uVar18 != -1) goto LAB_2ad9914bb90;
                            }
                          }
                        }
                        else {
                          bVar40 = true;
                          uVar30 = 1;
                          uVar18 = 0;
                          do {
                            iVar11 = (int)uVar30;
                            if (psVar12[uVar18] == 0x26) {
                              psVar20 = (short *)&DAT_2ad99163efe;
                              lVar24 = (ulonglong)_DAT_2ad99163ef8 - 1;
                              while (psVar12[uVar30] == *psVar20) {
                                psVar20 = psVar20 + 1;
                                uVar30 = (ulonglong)((int)uVar30 + 1);
                                lVar24 = lVar24 + -1;
                                if (lVar24 == 0) goto LAB_2ad9914bb67;
                              }
                              if ((int)lVar24 == 0) {
LAB_2ad9914bb67:
                                if (bVar40) goto LAB_2ad9914bb8b;
                                break;
                              }
                            }
                            uVar18 = uVar18 + 1;
                            uVar30 = (ulonglong)(iVar11 + 1);
                            bVar40 = uVar18 < uVar29;
                          } while (uVar18 != uVar29);
                        }
                      }
                    }
                  }
LAB_2ad9914bbab:
                  puVar33 = *(undefined1 **)(lVar35 + 0x2ad991730c0);
                  if (puVar33 == &DAT_2ad99160d00) {
LAB_2ad9914bc29:
                    FUN_2ad99140a40(lVar35 + 0x2ad991730bc,0x2ad99163f28,0);
                  }
                  else if (puVar33 != (undefined1 *)0x0) {
                    uVar21 = *(uint *)(puVar33 + -4);
                    uVar36 = _DAT_2ad99160cfc;
                    if (uVar21 < _DAT_2ad99160cfc) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99160cfc;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(puVar33 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if (iVar11 == 0) goto LAB_2ad9914bc29;
                  }
                  puVar33 = *(undefined1 **)(lVar35 + 0x2ad991730cc);
                  if (puVar33 == &DAT_2ad99160d00) {
LAB_2ad9914bcc9:
                    FUN_2ad99140a40(lVar35 + 0x2ad991730c8,0x2ad99163f28,0,0x2ad99171ca0);
                  }
                  else if (puVar33 != (undefined1 *)0x0) {
                    uVar21 = *(uint *)(puVar33 + -4);
                    uVar36 = _DAT_2ad99160cfc;
                    if (uVar21 < _DAT_2ad99160cfc) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99160cfc;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(puVar33 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if (iVar11 == 0) goto LAB_2ad9914bcc9;
                  }
                  FUN_2ad99140a40(&local_1e8,lVar35 + 0x2ad991730a4,0,0x2ad99171cb0);
                  FUN_2ad99140a40(&local_1a0,&DAT_2ad99173098 + lVar35,0,0x2ad99171cc0);
                  FUN_2ad9915ef10(&local_1a0,&local_1e8);
                  FUN_2ad99140a40(&local_190,0x2ad99183b3c,1,0x2ad99171cd0);
                  uVar13 = (*(code *)0x7ff63a0fd370)(0x2ad95e68178,&local_190);
                  local_1c8 = (*(code *)0x7ff63a101e20)(0x2ad95e68178,0);
                  (*(code *)0x7ff63a101f60)(0x2ad95e68178,uVar13,&local_98);
                  uVar14 = (*(code *)0x7ff63a101e20)(0x2ad95e68178,0);
                  (*(code *)0x7ff63a101f60)(0x2ad95e68178,uVar14,&local_b8);
                  FUN_2ad99140a40(&local_1e8,lVar35 + 0x2ad991730b0,0);
                  uVar41 = uVar43;
                  uVar42 = uVar44;
                  if (local_1e4 == &DAT_2ad99163acc) {
LAB_2ad9914bfd9:
                    *(ulonglong *)(uVar28 * 8 + 0x2ad99177b30) = CONCAT44(uVar42,uVar41);
LAB_2ad9914bfed:
                    iVar11 = ((int)uVar13 - (int)local_1c8) / 0x3c;
                  }
                  else {
                    uVar41 = 0;
                    uVar42 = 0;
                    if (local_1e4 == (undefined1 *)0x0) goto LAB_2ad9914bfd9;
                    uVar21 = *(uint *)(local_1e4 + -4);
                    uVar36 = _DAT_2ad99163ac8;
                    if (uVar21 < _DAT_2ad99163ac8) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99163ac8;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99163acc + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    uVar41 = uVar43;
                    uVar42 = uVar44;
                    if ((iVar11 == 0) ||
                       (uVar41 = uVar45, uVar42 = uVar46, local_1e4 == &DAT_2ad99163aec))
                    goto LAB_2ad9914bfd9;
                    uVar36 = _DAT_2ad99163ae8;
                    if (uVar21 < _DAT_2ad99163ae8) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99163ae8;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99163aec + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if ((iVar11 == 0) ||
                       (uVar41 = uVar47, uVar42 = uVar48, local_1e4 == &DAT_2ad99163b0c))
                    goto LAB_2ad9914bfd9;
                    uVar36 = _DAT_2ad99163b08;
                    if (uVar21 < _DAT_2ad99163b08) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99163b08;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99163b0c + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if (iVar11 == 0) goto LAB_2ad9914bfd9;
                    if (local_1e4 != &DAT_2ad99163b2c) {
                      uVar36 = _DAT_2ad99163b28;
                      if (uVar21 < _DAT_2ad99163b28) {
                        uVar36 = uVar21;
                      }
                      iVar11 = uVar21 - _DAT_2ad99163b28;
                      if (uVar36 != 0) {
                        uVar29 = 0;
                        do {
                          uVar3 = *(ushort *)(local_1e4 + uVar29 * 2);
                          uVar4 = *(ushort *)(&DAT_2ad99163b2c + uVar29 * 2);
                          uVar29 = uVar29 + 1;
                          if (uVar36 <= uVar29) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar11 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      uVar41 = 0;
                      uVar42 = 0;
                      if (iVar11 != 0) goto LAB_2ad9914bfd9;
                    }
                    *(undefined8 *)(uVar28 * 8 + 0x2ad99177b30) = 0x4010000000000000;
                    if (((local_90 != local_b0) || (local_94 != local_b8._4_4_)) ||
                       (iVar11 = 0, local_98 != (int)local_b8)) goto LAB_2ad9914bfed;
                  }
                  plVar22 = local_1d8;
                  if (-1 < _DAT_2ad99178180 + iVar11) {
                    plVar22 = (longlong *)(ulonglong)((int)local_1d8 + 1);
                    *(double *)(&DAT_2ad991774f0 + uVar28 * 8) = (double)iVar11;
                  }
                }
                else {
                  if (local_180 != (undefined1 *)0x0) {
                    uVar21 = *(uint *)(local_180 + -4);
                    uVar36 = _DAT_2ad99160cfc;
                    if (uVar21 < _DAT_2ad99160cfc) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99160cfc;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(local_180 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if (iVar11 == 0) goto LAB_2ad9914afb8;
                  }
                  if (0 < (int)_DAT_2ad99178198) {
                    psVar12 = *(short **)(&DAT_2ad99173084 + lVar35);
                    uVar29 = 0;
                    do {
                      uVar18 = ~uVar29 + (ulonglong)_DAT_2ad99178198;
                      if ((_DAT_2ad99178192 & 0x10) == 0) {
                        uVar18 = uVar29;
                      }
                      uVar41 = 0xfa9;
                      if ((psVar12 != (short *)0x0) &&
                         (psVar20 = *(short **)(_DAT_2ad991781ac + 4 + uVar18 * 0xc),
                         psVar20 != (short *)0x0)) {
                        uVar21 = *(uint *)(psVar12 + -2);
                        uVar41 = 0x13ab;
                        if ((uVar21 != 0) && (uVar36 = *(uint *)(psVar20 + -2), uVar36 != 0)) {
                          if (psVar12 == psVar20) goto LAB_2ad9914afb8;
                          uVar41 = _DAT_2ad99183b10;
                          if ((uVar36 <= uVar21) && (uVar21 = (uVar21 - uVar36) + 1, uVar21 != 0)) {
                            sVar2 = *psVar20;
                            uVar18 = (ulonglong)uVar21;
                            if (uVar36 < 2) {
                              if (*psVar12 == sVar2) goto LAB_2ad9914afb8;
                              uVar30 = 0;
                              do {
                                if (uVar18 - 1 == uVar30) goto LAB_2ad9914b18d;
                                lVar24 = uVar30 + 1;
                                uVar30 = uVar30 + 1;
                              } while (psVar12[lVar24] != sVar2);
                              if (uVar30 < uVar18) {
LAB_2ad9914b2c6:
                                if (-1 < (int)uVar30) goto LAB_2ad9914afb8;
                              }
                            }
                            else {
                              bVar40 = true;
                              uVar30 = 0;
                              do {
                                if (psVar12[uVar30] == sVar2) {
                                  lVar32 = 1;
                                  lVar24 = (ulonglong)uVar36 - 1;
                                  while (psVar12[(uint)((int)uVar30 + (int)lVar32)] ==
                                         psVar20[lVar32]) {
                                    lVar32 = lVar32 + 1;
                                    lVar24 = lVar24 + -1;
                                    if (lVar24 == 0) goto LAB_2ad9914b2a8;
                                  }
                                  if ((int)lVar24 == 0) {
LAB_2ad9914b2a8:
                                    if (bVar40) goto LAB_2ad9914b2c6;
                                    break;
                                  }
                                }
                                uVar30 = uVar30 + 1;
                                bVar40 = uVar30 < uVar18;
                              } while (uVar30 != uVar18);
                            }
                          }
                        }
                      }
LAB_2ad9914b18d:
                      _DAT_2ad99183b10 = uVar41;
                      uVar29 = uVar29 + 1;
                    } while (uVar29 != _DAT_2ad99178198);
                  }
                }
              }
              else {
                uVar21 = *(uint *)(puVar34 + -4);
                uVar36 = _DAT_2ad99163e78;
                if (uVar21 < _DAT_2ad99163e78) {
                  uVar36 = uVar21;
                }
                iVar11 = uVar21 - _DAT_2ad99163e78;
                if (uVar36 != 0) {
                  uVar29 = 0;
                  do {
                    uVar3 = *(ushort *)(puVar34 + uVar29 * 2);
                    uVar4 = *(ushort *)(&DAT_2ad99163e7c + uVar29 * 2);
                    uVar29 = uVar29 + 1;
                    if (uVar36 <= uVar29) break;
                  } while (uVar3 == uVar4);
                  if (uVar3 != uVar4) {
                    iVar11 = (uint)uVar3 - (uint)uVar4;
                  }
                }
                if ((iVar11 == 0) && (puVar25 != &DAT_2ad99163b2c)) goto LAB_2ad9914ae47;
LAB_2ad9914aeba:
                if (puVar34 != &DAT_2ad99163e9c) {
                  if (puVar34 == (undefined1 *)0x0) goto LAB_2ad9914afad;
                  uVar21 = *(uint *)(puVar34 + -4);
                  uVar36 = _DAT_2ad99163e98;
                  if (uVar21 < _DAT_2ad99163e98) {
                    uVar36 = uVar21;
                  }
                  iVar11 = uVar21 - _DAT_2ad99163e98;
                  if (uVar36 != 0) {
                    uVar29 = 0;
                    do {
                      uVar3 = *(ushort *)(puVar34 + uVar29 * 2);
                      uVar4 = *(ushort *)(&DAT_2ad99163e9c + uVar29 * 2);
                      uVar29 = uVar29 + 1;
                      if (uVar36 <= uVar29) break;
                    } while (uVar3 == uVar4);
                    if (uVar3 != uVar4) {
                      iVar11 = (uint)uVar3 - (uint)uVar4;
                    }
                  }
                  if ((iVar11 != 0) && (puVar34 != &DAT_2ad99160d00)) {
                    uVar36 = _DAT_2ad99160cfc;
                    if (uVar21 < _DAT_2ad99160cfc) {
                      uVar36 = uVar21;
                    }
                    iVar11 = uVar21 - _DAT_2ad99160cfc;
                    if (uVar36 != 0) {
                      uVar29 = 0;
                      do {
                        uVar3 = *(ushort *)(puVar34 + uVar29 * 2);
                        uVar4 = *(ushort *)(&DAT_2ad99160d00 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                        if (uVar36 <= uVar29) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar11 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if (iVar11 != 0) goto LAB_2ad9914afad;
                  }
                }
              }
            }
            else {
              uVar21 = *(uint *)(puVar25 + -4);
              uVar36 = _DAT_2ad99163ae8;
              if (uVar21 < _DAT_2ad99163ae8) {
                uVar36 = uVar21;
              }
              iVar11 = uVar21 - _DAT_2ad99163ae8;
              if (uVar36 != 0) {
                uVar29 = 0;
                do {
                  uVar3 = *(ushort *)(puVar25 + uVar29 * 2);
                  uVar4 = *(ushort *)(&DAT_2ad99163aec + uVar29 * 2);
                  uVar29 = uVar29 + 1;
                  if (uVar36 <= uVar29) break;
                } while (uVar3 == uVar4);
                if (uVar3 != uVar4) {
                  iVar11 = (uint)uVar3 - (uint)uVar4;
                }
              }
              if ((iVar11 != 0) && (puVar25 != &DAT_2ad99163b0c)) {
                uVar21 = *(uint *)(puVar25 + -4);
                uVar36 = _DAT_2ad99163b08;
                if (uVar21 < _DAT_2ad99163b08) {
                  uVar36 = uVar21;
                }
                iVar11 = uVar21 - _DAT_2ad99163b08;
                if (uVar36 != 0) {
                  uVar29 = 0;
                  do {
                    uVar3 = *(ushort *)(puVar25 + uVar29 * 2);
                    uVar4 = *(ushort *)(&DAT_2ad99163b0c + uVar29 * 2);
                    uVar29 = uVar29 + 1;
                    if (uVar36 <= uVar29) break;
                  } while (uVar3 == uVar4);
                  if (uVar3 != uVar4) {
                    iVar11 = (uint)uVar3 - (uint)uVar4;
                  }
                }
                if (iVar11 != 0) goto joined_r0x02ad9914ad2a;
              }
            }
          }
        }
      }
LAB_2ad9914a2b0:
    } while (_DAT_2ad99183b14 == 0);
    _DAT_2ad991774d0 = 0;
    uRam000002ad991774d8 = 0;
    _DAT_2ad991774c0 = 0;
    uRam000002ad991774c8 = 0;
    plVar19 = (longlong *)&DAT_2ad991774a0;
    _DAT_2ad991774e0 = 0;
    uRam000002ad991774e8 = 0;
    _DAT_2ad991774b0 = 0;
    uRam000002ad991774b8 = 0;
    _DAT_2ad991774a0 = 0;
    uRam000002ad991774a8 = 0;
    if (0 < (int)plVar22) {
      puVar25 = &DAT_2ad991772a0;
      puVar33 = &DAT_2ad99177320;
      puVar34 = &DAT_2ad991773a0;
      puVar37 = &DAT_2ad99177420;
      local_1d0 = 10;
      if ((int)plVar22 < 10) {
        local_1d0 = (ulonglong)plVar22 & 0xffffffff;
      }
      puVar23 = &DAT_2ad99177220;
      uVar28 = 0;
      local_1d0 = local_1d0 * 0x54;
      do {
        local_1d8 = plVar19;
        FUN_2ad99140a40(puVar23,&DAT_2ad99173080 + uVar28,0,0x2ad99171cf0);
        FUN_2ad99140a40(puVar25,&DAT_2ad9917308c + uVar28,0,0x2ad99171d00);
        FUN_2ad99140a40(puVar33,uVar28 + 0x2ad991730b0,0,0x2ad99171d10);
        FUN_2ad99140a40(puVar34,uVar28 + 0x2ad991730bc,0,0x2ad99171d20);
        FUN_2ad99140a40(puVar37,uVar28 + 0x2ad991730c8,0,0x2ad99171d30);
        FUN_2ad99140a40(&local_1e8,uVar28 + 0x2ad991730a4,0,0x2ad99171d40);
        FUN_2ad99140a40(&local_1a0,&DAT_2ad99173098 + uVar28,0,0x2ad99171d50);
        FUN_2ad9915ef10(&local_1a0,&local_1e8);
        FUN_2ad99140a40(&local_190,0x2ad99183b3c,1,0x2ad99171d60);
        lVar35 = (*(code *)0x7ff63a0fd370)(0x2ad95e68178,&local_190);
        uVar28 = uVar28 + 0x54;
        puVar23 = puVar23 + 0xc;
        puVar25 = puVar25 + 0xc;
        puVar33 = puVar33 + 0xc;
        puVar34 = puVar34 + 0xc;
        puVar37 = puVar37 + 0xc;
        *local_1d8 = lVar35 - _DAT_2ad991781c4;
        plVar19 = local_1d8 + 1;
      } while (local_1d0 != uVar28);
    }
  }
  else {
    _DAT_2ad991774d0 = 0;
    uRam000002ad991774d8 = 0;
    _DAT_2ad991774c0 = 0;
    uRam000002ad991774c8 = 0;
    _DAT_2ad991774e0 = 0;
    uRam000002ad991774e8 = 0;
    _DAT_2ad991774b0 = 0;
    uRam000002ad991774b8 = 0;
    _DAT_2ad991774a0 = 0;
    uRam000002ad991774a8 = 0;
  }
  FUN_2ad99140000(&local_1c0);
  FUN_2ad99140000(&local_178);
  FUN_2ad99140000(&local_1b0);
  lVar35 = -0x54;
  do {
    if (((*(int *)((longlong)&iStack_114 + lVar35) != 0) &&
        (lVar24 = *(longlong *)(local_110 + lVar35), lVar24 != 0)) &&
       (((int *)(lVar24 + -0xc) != (int *)0x0 && (*(int *)(lVar24 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar24 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(local_110 + lVar35) = 0;
    *(undefined4 *)((longlong)&iStack_114 + lVar35) = 0;
    lVar35 = lVar35 + 0xc;
  } while (lVar35 != 0);
  lVar35 = -0x54;
  do {
    if (((*(int *)((longlong)&iStack_bc + lVar35) != 0) &&
        (lVar24 = *(longlong *)((longlong)&local_b8 + lVar35), lVar24 != 0)) &&
       (((int *)(lVar24 + -0xc) != (int *)0x0 && (*(int *)(lVar24 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar24 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)((longlong)&local_b8 + lVar35) = 0;
    *(undefined4 *)((longlong)&iStack_bc + lVar35) = 0;
    lVar35 = lVar35 + 0xc;
  } while (lVar35 != 0);
  FUN_2ad99140000(&local_1e8);
  FUN_2ad99140000(&local_1a0);
  FUN_2ad99140000(&local_190);
  return;
}



/* Address: 2ad9914c430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ad9914c430(void)

{
  double dVar1;
  double dVar2;
  undefined1 *puVar3;
  longlong lVar4;
  bool bVar5;
  double dVar6;
  double dVar7;
  
  if ((DAT_2ad99173054 != '\0') && (_DAT_2ad99183dc8 != 0 || _DAT_2ad99183dc0 != 0)) {
    _DAT_2ad99178180 = _DAT_2ad99183dc8 + 1;
    dVar6 = (double)_DAT_2ad99183dc8;
    dVar7 = (double)_DAT_2ad99183dc0;
    if (DAT_2ad99183de0 == '\0') {
      puVar3 = &DAT_2ad99160710;
      lVar4 = 0;
      while (_DAT_2ad99183b14 == 0) {
        dVar1 = *(double *)(&DAT_2ad991774f0 + lVar4);
        dVar2 = *(double *)(lVar4 + 0x2ad99177b30);
        if (((dVar2 == _DAT_2ad99160710) && (!NAN(dVar2) && !NAN(_DAT_2ad99160710))) &&
           ((double)((ulonglong)dVar1 & _DAT_2ad99160700) <= dVar6)) {
          return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
        }
        if ((dVar1 == _DAT_2ad991606e0) && (!NAN(dVar1) && !NAN(_DAT_2ad991606e0))) {
          return 0;
        }
        if (dVar7 < dVar1) {
          return 0;
        }
        if (0.0 <= dVar1) {
          bVar5 = dVar7 < dVar1;
        }
        else {
          bVar5 = dVar6 < (double)((ulonglong)dVar1 & _DAT_2ad99160700);
        }
        if ((dVar2 >= _DAT_2ad991606f0 && _DAT_2ad991606e8 >= dVar2) && !bVar5) {
          return CONCAT71((uint7)(uint3)(-(ulonglong)
                                          (dVar2 < _DAT_2ad991606f0 || _DAT_2ad991606e8 < dVar2) >>
                                        8),1);
        }
        lVar4 = lVar4 + 8;
        puVar3 = (undefined1 *)0x0;
        if (lVar4 == 0x640) {
          return 0;
        }
      }
    }
    else {
      lVar4 = 0;
      do {
        if (_DAT_2ad99183b14 != 0) {
          return 0;
        }
        dVar1 = *(double *)(&DAT_2ad991774f0 + lVar4);
        if ((dVar1 == _DAT_2ad991606e0) && (!NAN(dVar1) && !NAN(_DAT_2ad991606e0))) {
          return 0;
        }
        if (dVar7 < dVar1) {
          return 0;
        }
        dVar2 = *(double *)(lVar4 + 0x2ad99177b30);
        bVar5 = dVar2 < _DAT_2ad991606f0 || _DAT_2ad991606e8 < dVar2;
        if (0.0 <= dVar1) {
          if ((dVar2 >= _DAT_2ad991606f0 && _DAT_2ad991606e8 >= dVar2) && dVar1 <= dVar7)
          goto LAB_2ad9914c5c1;
        }
        else if ((bool)(~bVar5 & (double)((ulonglong)dVar1 & _DAT_2ad99160700) <= dVar6)) {
LAB_2ad9914c5c1:
          return CONCAT71((uint7)(uint3)(-(ulonglong)bVar5 >> 8),1);
        }
        lVar4 = lVar4 + 8;
      } while (lVar4 != 0x640);
    }
  }
  return 0;
}



/* Address: 2ad9914c4b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ad9914c4b0(int param_1)

{
  double dVar1;
  double dVar2;
  int in_EAX;
  undefined1 *puVar3;
  longlong lVar4;
  bool bVar5;
  double dVar6;
  double dVar7;
  
  _DAT_2ad99178180 = in_EAX + 1;
  dVar6 = (double)in_EAX;
  dVar7 = (double)param_1;
  if (DAT_2ad99183de0 == '\0') {
    puVar3 = &DAT_2ad99160710;
    lVar4 = 0;
    while (_DAT_2ad99183b14 == 0) {
      dVar1 = *(double *)(&DAT_2ad991774f0 + lVar4);
      dVar2 = *(double *)(lVar4 + 0x2ad99177b30);
      if (((dVar2 == _DAT_2ad99160710) && (!NAN(dVar2) && !NAN(_DAT_2ad99160710))) &&
         ((double)((ulonglong)dVar1 & _DAT_2ad99160700) <= dVar6)) {
        return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
      }
      if ((dVar1 == _DAT_2ad991606e0) && (!NAN(dVar1) && !NAN(_DAT_2ad991606e0))) {
        return 0;
      }
      if (dVar7 < dVar1) {
        return 0;
      }
      if (0.0 <= dVar1) {
        bVar5 = dVar7 < dVar1;
      }
      else {
        bVar5 = dVar6 < (double)((ulonglong)dVar1 & _DAT_2ad99160700);
      }
      if ((dVar2 >= _DAT_2ad991606f0 && _DAT_2ad991606e8 >= dVar2) && !bVar5) {
        return CONCAT71((uint7)(uint3)(-(ulonglong)
                                        (dVar2 < _DAT_2ad991606f0 || _DAT_2ad991606e8 < dVar2) >> 8)
                        ,1);
      }
      lVar4 = lVar4 + 8;
      puVar3 = (undefined1 *)0x0;
      if (lVar4 == 0x640) {
        return 0;
      }
    }
  }
  else {
    lVar4 = 0;
    do {
      if (_DAT_2ad99183b14 != 0) {
        return 0;
      }
      dVar1 = *(double *)(&DAT_2ad991774f0 + lVar4);
      if ((dVar1 == _DAT_2ad991606e0) && (!NAN(dVar1) && !NAN(_DAT_2ad991606e0))) {
        return 0;
      }
      if (dVar7 < dVar1) {
        return 0;
      }
      dVar2 = *(double *)(lVar4 + 0x2ad99177b30);
      bVar5 = dVar2 < _DAT_2ad991606f0 || _DAT_2ad991606e8 < dVar2;
      if (0.0 <= dVar1) {
        if ((dVar2 >= _DAT_2ad991606f0 && _DAT_2ad991606e8 >= dVar2) && dVar1 <= dVar7)
        goto LAB_2ad9914c5c1;
      }
      else if ((bool)(~bVar5 & (double)((ulonglong)dVar1 & _DAT_2ad99160700) <= dVar6)) {
LAB_2ad9914c5c1:
        return CONCAT71((uint7)(uint3)(-(ulonglong)bVar5 >> 8),1);
      }
      lVar4 = lVar4 + 8;
    } while (lVar4 != 0x640);
  }
  return 0;
}



/* Address: 2ad9914c6f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9914c6f0(double *param_1,double *param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  code *pcVar5;
  double dVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  byte bVar15;
  int iVar16;
  uint uVar17;
  longlong lVar18;
  ulonglong uVar19;
  double dVar20;
  double dVar21;
  undefined4 local_e8;
  longlong local_e4;
  double *local_d8;
  longlong local_d0;
  double *local_c8;
  int *local_c0;
  
  local_e8 = 0;
  local_e4 = 0;
  *param_1 = 0.0;
  *param_2 = 0.0;
  *param_3 = 0;
  local_d8 = param_2;
  local_c8 = param_1;
  local_c0 = param_3;
  uVar12 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  (*(code *)0x7ff63a0fcc50)(0x2ad95e68178,uVar12,1);
  FUN_2ad99140a40(&local_e8,0x2ad99183b3c,1,0x2ad991711e0);
  uVar12 = (*(code *)0x7ff63a0fd370)(0x2ad95e68178,&local_e8);
  uVar13 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  (*(code *)0x7ff63a1084f0)(0x2ad95e68178,uVar12,uVar13);
  iVar11 = (*(code *)0x7ff63a108810)(0x2ad95e68178);
  dVar8 = _DAT_2ad99160718;
  if (-1 < iVar11 + -1) {
    lVar18 = (longlong)_DAT_2ad99183c78;
    iVar11 = iVar11 + -1;
    local_d0 = lVar18;
    do {
      uVar12 = (*(code *)0x7ff63a108860)(0x2ad95e68178,iVar11);
      (*(code *)0x7ff63a1089d0)(0x2ad95e68178,uVar12,0);
      FUN_2ad99140a40(&local_e8,0x2ad99183b3c,1,0x2ad991711f0);
      if (local_e4 == _DAT_2ad99183b2c) {
LAB_2ad9914c992:
        lVar14 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar12);
        if (lVar14 == lVar18) {
          lVar18 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar12,4);
          if (lVar18 == 1) {
            (*(code *)0x7ff63a1088b0)(0x2ad95e68178,uVar12,9);
            dVar6 = _DAT_2ad99183b48;
            (*(code *)0x7ff63a1088b0)(0x2ad95e68178,uVar12,8);
            dVar6 = dVar6 + _DAT_2ad99183b48;
            (*(code *)0x7ff63a1088b0)(0x2ad95e68178,uVar12,7);
            dVar9 = _DAT_2ad99183b48;
            (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x1b);
            dVar21 = _DAT_2ad99183b48;
            (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x10);
            dVar10 = _DAT_2ad99183b48;
            (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x1a);
            lVar18 = local_d0;
            dVar20 = dVar8;
            if ((((dVar21 != 0.0) || (NAN(dVar21))) &&
                ((_DAT_2ad99183b48 != 0.0 || (NAN(_DAT_2ad99183b48))))) &&
               ((dVar10 != 0.0 || (NAN(dVar10))))) {
              dVar21 = dVar21 / dVar10;
              if ((dVar21 == 0.0) && (!NAN(dVar21))) {
                (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x32079b000001f7);
LAB_2ad9914cc8b:
                (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2e079c000001f7);
                pcVar5 = (code *)swi(3);
                (*pcVar5)();
                return;
              }
              dVar20 = _DAT_2ad99183b48 / dVar21;
              if ((dVar20 == 0.0) && (!NAN(dVar20))) goto LAB_2ad9914cc8b;
            }
            (*(code *)0x7ff63a1088b0)(0x2ad95e68178,uVar12);
            if ((_DAT_2ad99183b48 != 0.0) || (NAN(_DAT_2ad99183b48))) {
              dVar6 = dVar6 + dVar9 + dVar9;
              dVar20 = (dVar6 / dVar20) / _DAT_2ad99183b48;
              uVar17 = (uint)((ulonglong)dVar20 >> 0x34) & 0x7ff;
              lVar14 = (ulonglong)uVar17 - 0x3ff;
              dVar21 = dVar20;
              if ((ulonglong)uVar17 < 0x433) {
                if (uVar17 < 0x3ff) {
                  dVar21 = (double)(((ulonglong)dVar20 & 0x8000000000000000) + 0x3ff0000000000000);
                  if (lVar14 != -1) {
                    dVar21 = (double)((ulonglong)dVar20 & 0x8000000000000000);
                  }
                }
                else {
                  bVar15 = (byte)lVar14;
                  if (((longlong)dVar20 << (bVar15 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar21 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar20 &
                                     -0x10000000000000 >> (bVar15 & 0x3f));
                  }
                }
              }
              else if (lVar14 == 0x400) {
                dVar21 = dVar20 + dVar20;
              }
              *local_c8 = dVar6 + *local_c8;
              *local_d8 = (double)(int)dVar21 + *local_d8;
            }
          }
          else {
            lVar14 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar12);
            lVar18 = local_d0;
            if (lVar14 == 0) {
              *local_c0 = *local_c0 + 1;
            }
          }
        }
      }
      else if ((local_e4 != 0) && (_DAT_2ad99183b2c != 0)) {
        uVar17 = *(uint *)(local_e4 + -4);
        uVar3 = *(uint *)(_DAT_2ad99183b2c + -4);
        uVar7 = uVar3;
        if (uVar17 < uVar3) {
          uVar7 = uVar17;
        }
        iVar16 = uVar17 - uVar3;
        if (uVar7 != 0) {
          uVar19 = 1;
          do {
            uVar1 = *(ushort *)(local_e4 + -2 + uVar19 * 2);
            uVar2 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar19 * 2);
            if (uVar7 <= uVar19) break;
            uVar19 = uVar19 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar16 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar16 == 0) goto LAB_2ad9914c992;
      }
      bVar4 = 0 < iVar11;
      iVar11 = iVar11 + -1;
    } while (bVar4);
  }
  *local_d8 = *local_d8 / _DAT_2ad99160720;
  FUN_2ad99140000(&local_e8);
  return;
}



/* Address: 2ad9914ccb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9914ccb0(undefined4 param_1,double param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ushort uVar4;
  ushort uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  byte bVar10;
  undefined2 *puVar11;
  char cVar12;
  char cVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  undefined4 *puVar18;
  int iVar19;
  undefined4 uVar20;
  longlong lVar21;
  uint uVar22;
  undefined4 uVar23;
  int iVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined8 uVar27;
  ulonglong uVar28;
  char *pcVar29;
  uint uVar30;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  local_98 = 0;
  local_88 = 0;
  local_d8 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_e8 = 0;
  local_c8 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_94 = 0;
  local_84 = 0;
  local_d4 = 0;
  local_f4 = 0;
  local_104 = 0;
  local_e4 = 0;
  local_c4 = 0;
  local_a4 = 0;
  local_b4 = 0;
  if (DAT_2ad991784d6 != '\x01') goto LAB_2ad9914eef2;
  local_c4 = 0;
  uVar30 = 0;
  FUN_2ad99140a40(&local_c8,0x2ad991784e0,0,0x2ad99171900);
  FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171910);
  uVar14 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x12);
  (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,uVar14,0,0x20);
  FUN_2ad99140a40(&local_108,0x2ad99183b3c,1,0x2ad99171920);
  FUN_2ad99140a40(&local_f8,&local_c8,0,0x2ad99171930);
  uVar16 = _DAT_2ad991610c8;
  uVar26 = (ulonglong)_DAT_2ad991610c8;
  if ((uVar26 == 0) && (local_f4 != 0)) {
LAB_2ad9914cf7d:
    FUN_2ad9915eca0(&local_f8,&local_108,0xffffffff,&local_e8);
    uVar30 = 0;
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171940);
    uVar14 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
    FUN_2ad9915d030(uVar14);
    FUN_2ad99140a40(&local_108,0x2ad99183b3c,1,0x2ad99171950);
    FUN_2ad99140a40(&local_f8,&local_c8,0,0x2ad99171960);
    uVar16 = _DAT_2ad991610f8;
    uVar26 = (ulonglong)_DAT_2ad991610f8;
    if ((uVar26 != 0) || (local_f4 == 0)) {
      if (local_f4 != 0) {
        uVar30 = *(uint *)(local_f4 + -4);
      }
      uVar22 = _DAT_2ad991610f8 + uVar30;
      uVar15 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar12 = FUN_2ad99140060(&local_f8,uVar15);
      if (cVar12 == '\0') goto LAB_2ad9914f02c;
      if (uVar26 != 0) {
        lVar21 = local_f4 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad991610fcU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad99161100);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad99161104);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161108);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad991610fc + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914d122;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991610fc + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914d122:
      *(uint *)(local_f4 + -4) = uVar22;
      *(undefined2 *)(local_f4 + (ulonglong)uVar22 * 2) = 0;
    }
    FUN_2ad9915eca0(&local_f8,&local_108,0xffffffff,&local_e8);
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171970);
    local_78 = 0;
    local_74 = 0;
    if (DAT_2ad991781d0 == '\0') {
      uVar14 = 0x2ad991638e0;
      uVar27 = 0x2ad99171570;
    }
    else {
      uVar14 = 0x2ad99163910;
      uVar27 = 0x2ad99171580;
    }
    FUN_2ad99140a40(&local_78,uVar14,0,uVar27);
    FUN_2ad99140a40(0x2ad99183b3c,&local_78,1,0x2ad99171590);
    FUN_2ad99140000(&local_78);
    FUN_2ad99140a40(&local_108,0x2ad99183b3c,1,0x2ad99171980);
    uVar30 = 0;
    FUN_2ad99140a40(&local_f8,&local_c8,0);
    uVar16 = _DAT_2ad991610a8;
    uVar26 = (ulonglong)_DAT_2ad991610a8;
    if ((uVar26 != 0) || (local_f4 == 0)) {
      if (local_f4 != 0) {
        uVar30 = *(uint *)(local_f4 + -4);
      }
      uVar15 = _DAT_2ad991610a8 + uVar30;
      cVar12 = FUN_2ad99140060(&local_f8);
      if (cVar12 == '\0') goto LAB_2ad9914f04c;
      if (uVar26 != 0) {
        lVar21 = local_f4 + (ulonglong)uVar30 * 2;
        if ((uVar16 < 0x10) || (lVar21 - 0x2ad991610acU < 0x20)) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad991610b0);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad991610b4);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad991610b8);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad991610ac + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914d2f2;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991610ac + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914d2f2:
      *(uint *)(local_f4 + -4) = uVar15;
      *(undefined2 *)(local_f4 + (ulonglong)uVar15 * 2) = 0;
    }
    FUN_2ad9915eca0(&local_f8,&local_108,0xffffffff,&local_e8);
    uVar30 = 0;
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad991719a0);
    iVar19 = (int)param_2;
    pcVar29 = &DAT_2ad991784ff;
    pcVar17 = &DAT_2ad991784fd;
    uVar23 = 0xeaeaea;
    if (iVar19 < 0) {
      pcVar17 = &DAT_2ad991784ff;
      uVar23 = 0x3c14dc;
    }
    if (0 < iVar19) {
      pcVar17 = &DAT_2ad991784fe;
      uVar23 = 0x8000;
    }
    uVar20 = 0;
    if (*pcVar17 != '\0') {
      uVar20 = uVar23;
    }
    FUN_2ad9915e0a0(param_1);
    FUN_2ad99140a40(&local_108,0x2ad99183b3c,1,0x2ad991719b0);
    FUN_2ad99140a40(&local_f8,&local_c8,0,0x2ad991719c0);
    uVar16 = _DAT_2ad99161058;
    uVar26 = (ulonglong)_DAT_2ad99161058;
    if ((uVar26 != 0) || (local_f4 == 0)) {
      if (local_f4 != 0) {
        uVar30 = *(uint *)(local_f4 + -4);
      }
      uVar22 = _DAT_2ad99161058 + uVar30;
      uVar15 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar12 = FUN_2ad99140060(&local_f8,uVar15);
      if (cVar12 == '\0') goto LAB_2ad9914f06c;
      if (uVar26 != 0) {
        lVar21 = local_f4 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad9916105cU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161060);
            uVar8 = *(undefined4 *)(uVar28 + 0x2ad99161064);
            uVar9 = *(undefined4 *)(uVar28 + 0x2ad99161068);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad9916105c + uVar28);
            puVar18[1] = uVar7;
            puVar18[2] = uVar8;
            puVar18[3] = uVar9;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914d522;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad9916105c + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914d522:
      *(uint *)(local_f4 + -4) = uVar22;
      *(undefined2 *)(local_f4 + (ulonglong)uVar22 * 2) = 0;
    }
    FUN_2ad9915eca0(&local_f8,&local_108,uVar20,&local_e8);
    uVar26 = 0;
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad991719d0);
    if (-1 < iVar19) {
      pcVar29 = &DAT_2ad991784fd;
    }
    if (0 < iVar19) {
      pcVar29 = &DAT_2ad991784fe;
    }
    if (*pcVar29 == '\0') {
      uVar23 = 0;
    }
    FUN_2ad9915e660(SUB84(param_2,0));
    FUN_2ad99140a40(&local_108,0x2ad99183b3c,1,0x2ad991719e0);
    FUN_2ad99140a40(&local_f8,&local_c8,0,0x2ad991719f0);
    uVar30 = _DAT_2ad99161088;
    uVar25 = (ulonglong)_DAT_2ad99161088;
    if ((uVar25 != 0) || (local_f4 == 0)) {
      if (local_f4 != 0) {
        uVar26 = (ulonglong)*(uint *)(local_f4 + -4);
      }
      uVar15 = _DAT_2ad99161088 + (int)uVar26;
      uVar16 = 0x104;
      if ((0x103 < uVar15) &&
         ((0x7ffffffd < uVar15 || (uVar16 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar12 = FUN_2ad99140060(&local_f8,uVar16);
      if (cVar12 == '\0') goto LAB_2ad9914f08c;
      if (uVar25 != 0) {
        lVar21 = local_f4 + uVar26 * 2;
        if (uVar30 < 0x10) {
          uVar26 = 0;
        }
        else if (lVar21 - 0x2ad9916108cU < 0x20) {
          uVar26 = 0;
        }
        else {
          uVar28 = 0;
          uVar26 = (ulonglong)(uVar30 & 0xfffffff8);
          do {
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad99161090);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161094);
            uVar8 = *(undefined4 *)(uVar28 + 0x2ad99161098);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad9916108c + uVar28);
            puVar18[1] = uVar20;
            puVar18[2] = uVar7;
            puVar18[3] = uVar8;
            uVar28 = uVar28 + 0x10;
          } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar26 == uVar25) goto LAB_2ad9914d6f2;
        }
        do {
          *(undefined2 *)(lVar21 + uVar26 * 2) = *(undefined2 *)(&DAT_2ad9916108c + uVar26 * 2);
          uVar26 = uVar26 + 1;
        } while (uVar25 != uVar26);
      }
LAB_2ad9914d6f2:
      *(uint *)(local_f4 + -4) = uVar15;
      *(undefined2 *)(local_f4 + (ulonglong)uVar15 * 2) = 0;
    }
    FUN_2ad9915eca0(&local_f8,&local_108,uVar23,&local_e8);
    uVar30 = 0;
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171a00);
    bVar10 = DAT_2ad991784fd;
    cVar12 = DAT_2ad99178210;
    FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171a10);
    uVar16 = _DAT_2ad991611e8;
    uVar26 = (ulonglong)_DAT_2ad991611e8;
    if ((uVar26 != 0) || (local_104 == 0)) {
      if (local_104 != 0) {
        uVar30 = *(uint *)(local_104 + -4);
      }
      uVar22 = _DAT_2ad991611e8 + uVar30;
      uVar15 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar13 = FUN_2ad99140060(&local_108,uVar15);
      if (cVar13 == '\0') goto LAB_2ad9914f0ac;
      if (uVar26 != 0) {
        lVar21 = local_104 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad991611ecU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad991611f0);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad991611f4);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad991611f8);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad991611ec + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914d882;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991611ec + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914d882:
      *(uint *)(local_104 + -4) = uVar22;
      *(undefined2 *)(local_104 + (ulonglong)uVar22 * 2) = 0;
    }
    uVar14 = 0x2ad991639f0;
    if (cVar12 == '\0') {
      uVar14 = 0x2ad99163a30;
    }
    uVar30 = 0;
    uVar27 = 0xeaeaea;
    if ((bVar10 & 1) == 0) {
      uVar27 = 0;
    }
    FUN_2ad9915eca0(&local_108,uVar14,uVar27,&local_e8);
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171a20);
    bVar10 = DAT_2ad991784fd;
    FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171a30);
    uVar16 = _DAT_2ad99161218;
    uVar26 = (ulonglong)_DAT_2ad99161218;
    if ((uVar26 != 0) || (local_104 == 0)) {
      if (local_104 != 0) {
        uVar30 = *(uint *)(local_104 + -4);
      }
      uVar22 = _DAT_2ad99161218 + uVar30;
      uVar15 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar12 = FUN_2ad99140060(&local_108,uVar15);
      if (cVar12 == '\0') goto LAB_2ad9914f0cc;
      if (uVar26 != 0) {
        lVar21 = local_104 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad9916121cU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad99161220);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad99161224);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161228);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad9916121c + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914da22;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad9916121c + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914da22:
      *(uint *)(local_104 + -4) = uVar22;
      *(undefined2 *)(local_104 + (ulonglong)uVar22 * 2) = 0;
    }
    uVar14 = 0xeaeaea;
    if ((bVar10 & 1) == 0) {
      uVar14 = 0;
    }
    FUN_2ad9915eca0(&local_108,0x2ad99178218,uVar14,&local_e8);
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171a40);
    bVar10 = DAT_2ad991784fd;
    iVar19 = 0;
    if (_DAT_2ad9917823c != &DAT_2ad99163a4c) {
      if (_DAT_2ad9917823c == (undefined1 *)0x0) {
        iVar19 = 1;
      }
      else {
        uVar30 = *(uint *)(_DAT_2ad9917823c + -4);
        uVar16 = _DAT_2ad99163a48;
        if (uVar30 < _DAT_2ad99163a48) {
          uVar16 = uVar30;
        }
        iVar19 = uVar30 - _DAT_2ad99163a48;
        if (uVar16 != 0) {
          uVar26 = 0;
          do {
            uVar4 = *(ushort *)(_DAT_2ad9917823c + uVar26 * 2);
            uVar5 = *(ushort *)(&DAT_2ad99163a4c + uVar26 * 2);
            uVar26 = uVar26 + 1;
            if (uVar16 <= uVar26) break;
          } while (uVar4 == uVar5);
          if (uVar4 != uVar5) {
            iVar19 = (uint)uVar4 - (uint)uVar5;
          }
        }
      }
    }
    uVar30 = 0;
    FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171a50);
    uVar16 = _DAT_2ad99161248;
    uVar26 = (ulonglong)_DAT_2ad99161248;
    if ((uVar26 != 0) || (local_104 == 0)) {
      if (local_104 != 0) {
        uVar30 = *(uint *)(local_104 + -4);
      }
      uVar22 = _DAT_2ad99161248 + uVar30;
      uVar15 = 0x104;
      if ((0x103 < uVar22) &&
         ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
        uVar15 = 0x7ffffffe;
      }
      cVar12 = FUN_2ad99140060(&local_108,uVar15);
      if (cVar12 == '\0') goto LAB_2ad9914f0ec;
      if (uVar26 != 0) {
        lVar21 = local_104 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad9916124cU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad99161250);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad99161254);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161258);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad9916124c + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914dc32;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad9916124c + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914dc32:
      *(uint *)(local_104 + -4) = uVar22;
      *(undefined2 *)(local_104 + (ulonglong)uVar22 * 2) = 0;
    }
    uVar14 = 0x2ad99178238;
    if (iVar19 == 0) {
      uVar14 = 0x2ad99163a68;
    }
    uVar27 = 0;
    if ((bVar10 & 1) != 0) {
      uVar27 = 0xeaeaea;
    }
    FUN_2ad9915eca0(&local_108,uVar14,uVar27,&local_e8);
    FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171a60);
    uVar23 = 0;
    if (DAT_2ad991784fd != 0) {
      uVar23 = 0xeaeaea;
    }
    puVar18 = (undefined4 *)0x2ad99163a68;
    if (_DAT_2ad99178248 < 1) {
LAB_2ad9914de3d:
      uVar30 = 0;
      FUN_2ad99140a40(&local_d8,&local_c8,0,0x2ad99171a80);
      uVar16 = _DAT_2ad99161278;
      uVar26 = (ulonglong)_DAT_2ad99161278;
      if ((uVar26 != 0) || (local_d4 == 0)) {
        if (local_d4 != 0) {
          uVar30 = *(uint *)(local_d4 + -4);
        }
        uVar22 = _DAT_2ad99161278 + uVar30;
        uVar15 = 0x104;
        if ((0x103 < uVar22) &&
           ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_d8,uVar15);
        if (cVar12 == '\0') goto LAB_2ad9914f10c;
        if (uVar26 != 0) {
          lVar21 = local_d4 + (ulonglong)uVar30 * 2;
          if (uVar16 < 0x10) {
            uVar25 = 0;
          }
          else if (lVar21 - 0x2ad9916127cU < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar28 = 0;
            uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar20 = *(undefined4 *)(uVar28 + 0x2ad99161280);
              uVar7 = *(undefined4 *)(uVar28 + 0x2ad99161284);
              uVar8 = *(undefined4 *)(uVar28 + 0x2ad99161288);
              puVar3 = (undefined4 *)(lVar21 + uVar28);
              *puVar3 = *(undefined4 *)(&DAT_2ad9916127c + uVar28);
              puVar3[1] = uVar20;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar28 = uVar28 + 0x10;
            } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar25 == uVar26) goto LAB_2ad9914df62;
          }
          do {
            *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad9916127c + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar26 != uVar25);
        }
LAB_2ad9914df62:
        *(uint *)(local_d4 + -4) = uVar22;
        *(undefined2 *)(local_d4 + (ulonglong)uVar22 * 2) = 0;
      }
      FUN_2ad9915eca0(&local_d8,puVar18,uVar23,&local_e8);
      local_a8 = 0;
      local_a4 = 0;
      FUN_2ad99140a40(&local_a8,0x2ad99160d08,0,0x2ad99171a90);
      if (((_DAT_2ad9917822c != 0) && (_DAT_2ad9917822c != 0xc)) &&
         (0x1d < *(int *)(_DAT_2ad9917822c + -4))) {
        uVar30 = FUN_2ad991403b0(_DAT_2ad9917822c,&DAT_2ad99163040,0x14);
        uVar23 = 0xfa9;
        if ((_DAT_2ad9917822c == 0) || (_DAT_2ad9917822c == 0xc)) {
LAB_2ad9914e072:
          if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
            _DAT_2ad99183b10 = 0xfa9;
          }
          else {
            _DAT_2ad99183b10 = uVar23;
            if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
               (cVar12 = FUN_2ad99140060(0x2ad99183b3c,0), puVar11 = _DAT_2ad99183b40,
               cVar12 != '\0')) {
              *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
              *puVar11 = 0;
            }
          }
        }
        else {
          uVar16 = uVar30;
          if (((int)uVar30 < 0) &&
             (uVar16 = *(uint *)(_DAT_2ad9917822c + -4) + uVar30, (int)uVar16 < 0)) {
            uVar23 = 0x13ab;
            goto LAB_2ad9914e072;
          }
          uVar23 = 0x13ab;
          if (*(uint *)(_DAT_2ad9917822c + -4) <= uVar16) goto LAB_2ad9914e072;
          FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad9917822c + (ulonglong)uVar16 * 2);
        }
        FUN_2ad99140a40(&local_e8,0x2ad99183b3c,1,0x2ad99171aa0);
        FUN_2ad99140a40(&local_a8,&local_e8,0,0x2ad99171ab0);
        uVar23 = 0xfa9;
        if ((_DAT_2ad9917822c == 0) || (_DAT_2ad9917822c == 0xc)) {
LAB_2ad9914e147:
          _DAT_2ad99183b10 = uVar23;
          if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
            _DAT_2ad99183b10 = 0xfa9;
          }
          else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                  (cVar12 = FUN_2ad99140060(0x2ad99183b3c,0), puVar11 = _DAT_2ad99183b40,
                  cVar12 != '\0')) {
            *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
            *puVar11 = 0;
          }
        }
        else {
          uVar16 = *(uint *)(_DAT_2ad9917822c + -4);
          if (uVar16 == 0) {
            uVar23 = 0x13ab;
            goto LAB_2ad9914e147;
          }
          if (-1 < (int)uVar30) {
            if ((int)uVar16 < (int)uVar30) {
              _DAT_2ad99183b10 = 0x13ab;
            }
            else {
              uVar16 = uVar30;
              uVar23 = _DAT_2ad99183b10;
              if (uVar30 == 0) goto LAB_2ad9914e147;
            }
          }
          FUN_2ad991401d0(0x2ad99183b3c,_DAT_2ad9917822c,uVar16);
        }
        FUN_2ad99140a40(&local_e8,0x2ad99183b3c,1,0x2ad99171ac0);
        uVar25 = 0;
        FUN_2ad99140a40(0x2ad99178228,&local_e8,0,0x2ad99171ad0);
        FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171ae0);
        bVar10 = DAT_2ad991784fd;
        FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171af0);
        uVar30 = _DAT_2ad991612d8;
        uVar26 = (ulonglong)_DAT_2ad991612d8;
        if ((uVar26 != 0) || (local_104 == 0)) {
          if (local_104 != 0) {
            uVar25 = (ulonglong)*(uint *)(local_104 + -4);
          }
          uVar15 = _DAT_2ad991612d8 + (int)uVar25;
          uVar16 = 0x104;
          if ((0x103 < uVar15) &&
             ((0x7ffffffd < uVar15 || (uVar16 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar16)))) {
            uVar16 = 0x7ffffffe;
          }
          cVar12 = FUN_2ad99140060(&local_108,uVar16);
          if (cVar12 == '\0') goto LAB_2ad9914f16c;
          if (uVar26 != 0) {
            lVar21 = local_104 + uVar25 * 2;
            if (uVar30 < 0x10) {
              uVar25 = 0;
            }
            else if (lVar21 - 0x2ad991612dcU < 0x20) {
              uVar25 = 0;
            }
            else {
              uVar28 = 0;
              uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
              do {
                uVar23 = *(undefined4 *)(uVar28 + 0x2ad991612e0);
                uVar20 = *(undefined4 *)(uVar28 + 0x2ad991612e4);
                uVar7 = *(undefined4 *)(uVar28 + 0x2ad991612e8);
                puVar18 = (undefined4 *)(lVar21 + uVar28);
                *puVar18 = *(undefined4 *)(&DAT_2ad991612dc + uVar28);
                puVar18[1] = uVar23;
                puVar18[2] = uVar20;
                puVar18[3] = uVar7;
                uVar28 = uVar28 + 0x10;
              } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
              if (uVar25 == uVar26) goto LAB_2ad9914e342;
            }
            do {
              *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991612dc + uVar25 * 2);
              uVar25 = uVar25 + 1;
            } while (uVar26 != uVar25);
          }
LAB_2ad9914e342:
          *(uint *)(local_104 + -4) = uVar15;
          *(undefined2 *)(local_104 + (ulonglong)uVar15 * 2) = 0;
        }
        uVar14 = 0xeaeaea;
        if ((bVar10 & 1) == 0) {
          uVar14 = 0;
        }
        FUN_2ad9915eca0(&local_108,&local_a8,uVar14,&local_e8);
      }
      uVar30 = 0;
      FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171b00);
      bVar10 = DAT_2ad991784fd;
      FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171b10);
      uVar16 = _DAT_2ad991612a8;
      uVar26 = (ulonglong)_DAT_2ad991612a8;
      if ((uVar26 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar30 = *(uint *)(local_104 + -4);
        }
        uVar22 = _DAT_2ad991612a8 + uVar30;
        uVar15 = 0x104;
        if ((0x103 < uVar22) &&
           ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
          uVar15 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_108,uVar15);
        if (cVar12 == '\0') goto LAB_2ad9914f12c;
        if (uVar26 != 0) {
          lVar21 = local_104 + (ulonglong)uVar30 * 2;
          if (uVar16 < 0x10) {
            uVar25 = 0;
          }
          else if (lVar21 - 0x2ad991612acU < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar28 = 0;
            uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar23 = *(undefined4 *)(uVar28 + 0x2ad991612b0);
              uVar20 = *(undefined4 *)(uVar28 + 0x2ad991612b4);
              uVar7 = *(undefined4 *)(uVar28 + 0x2ad991612b8);
              puVar18 = (undefined4 *)(lVar21 + uVar28);
              *puVar18 = *(undefined4 *)(&DAT_2ad991612ac + uVar28);
              puVar18[1] = uVar23;
              puVar18[2] = uVar20;
              puVar18[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar25 == uVar26) goto LAB_2ad9914e4c2;
          }
          do {
            *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991612ac + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar26 != uVar25);
        }
LAB_2ad9914e4c2:
        *(uint *)(local_104 + -4) = uVar22;
        *(undefined2 *)(local_104 + (ulonglong)uVar22 * 2) = 0;
      }
      uVar14 = 0xeaeaea;
      if ((bVar10 & 1) == 0) {
        uVar14 = 0;
      }
      FUN_2ad9915eca0(&local_108,0x2ad99178228,uVar14,&local_e8);
      if (DAT_2ad99173054 != '\0') {
        lVar21 = 0;
        do {
          local_b8 = 0;
          local_b4 = 0;
          FUN_2ad99140a40(&local_b8,0x2ad991639a8,0,0x2ad99171b20);
          if (*(longlong *)(&DAT_2ad991774a0 + lVar21 * 8) != 0) {
            (*(code *)0x7ff63a0fcc50)(0x2ad95e68178,*(longlong *)(&DAT_2ad991774a0 + lVar21 * 8),3);
            FUN_2ad99140a40(&local_e8,0x2ad99183b3c,1,0x2ad99171b30);
            FUN_2ad99140a40(&local_108,&local_e8,0,0x2ad99171b40);
            uVar30 = _DAT_2ad99163aa8;
            uVar26 = (ulonglong)_DAT_2ad99163aa8;
            if ((uVar26 != 0) || (local_104 == 0)) {
              if (local_104 == 0) {
                uVar16 = 0;
                uVar15 = _DAT_2ad99163aa8;
              }
              else {
                uVar16 = *(uint *)(local_104 + -4);
                uVar15 = _DAT_2ad99163aa8 + uVar16;
              }
              uVar22 = 0x104;
              if ((0x103 < uVar15) &&
                 ((0x7ffffffd < uVar15 || (uVar22 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar22))))
              {
                uVar22 = 0x7ffffffe;
              }
              cVar12 = FUN_2ad99140060(&local_108,uVar22);
              if (cVar12 != '\0') {
                if (uVar26 != 0) {
                  lVar1 = local_104 + (ulonglong)uVar16 * 2;
                  if (uVar30 < 8) {
                    uVar25 = 0;
                  }
                  else if (local_104 + -0x2ad99163aac + (ulonglong)uVar16 * 2 < 0x20) {
                    uVar25 = 0;
                  }
                  else {
                    uVar28 = 0;
                    uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                    do {
                      uVar23 = *(undefined4 *)(uVar28 + 0x2ad99163ab0);
                      uVar20 = *(undefined4 *)(uVar28 + 0x2ad99163ab4);
                      uVar7 = *(undefined4 *)(uVar28 + 0x2ad99163ab8);
                      puVar18 = (undefined4 *)(lVar1 + uVar28);
                      *puVar18 = *(undefined4 *)(&DAT_2ad99163aac + uVar28);
                      puVar18[1] = uVar23;
                      puVar18[2] = uVar20;
                      puVar18[3] = uVar7;
                      uVar28 = uVar28 + 0x10;
                    } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                    if (uVar25 == uVar26) goto LAB_2ad9914e722;
                  }
                  do {
                    *(undefined2 *)(lVar1 + uVar25 * 2) =
                         *(undefined2 *)(&DAT_2ad99163aac + uVar25 * 2);
                    uVar25 = uVar25 + 1;
                  } while (uVar26 != uVar25);
                }
LAB_2ad9914e722:
                *(uint *)(local_104 + -4) = uVar15;
                *(undefined2 *)(local_104 + (ulonglong)uVar15 * 2) = 0;
                goto LAB_2ad9914e72f;
              }
              goto LAB_2ad9914ef8c;
            }
LAB_2ad9914e72f:
            FUN_2ad99140a40(&local_f8,&local_108,0);
            lVar1 = *(longlong *)(&DAT_2ad991772a4 + lVar21 * 0xc);
            if (lVar1 == 0) {
LAB_2ad9914e86c:
              FUN_2ad99140a40(&local_d8,&local_f8,0,0x2ad99171b60);
              uVar30 = _DAT_2ad99163998;
              uVar26 = (ulonglong)_DAT_2ad99163998;
              if ((uVar26 != 0) || (local_d4 == 0)) {
                if (local_d4 == 0) {
                  uVar16 = 0;
                  uVar15 = _DAT_2ad99163998;
                }
                else {
                  uVar16 = *(uint *)(local_d4 + -4);
                  uVar15 = _DAT_2ad99163998 + uVar16;
                }
                uVar22 = 0x104;
                if ((0x103 < uVar15) &&
                   ((0x7ffffffd < uVar15 || (uVar22 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar22)))
                   ) {
                  uVar22 = 0x7ffffffe;
                }
                cVar12 = FUN_2ad99140060(&local_d8,uVar22);
                if (cVar12 != '\0') {
                  if (uVar26 != 0) {
                    lVar1 = local_d4 + (ulonglong)uVar16 * 2;
                    if (uVar30 < 8) {
                      uVar25 = 0;
                    }
                    else if (local_d4 + -0x2ad9916399c + (ulonglong)uVar16 * 2 < 0x20) {
                      uVar25 = 0;
                    }
                    else {
                      uVar28 = 0;
                      uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                      do {
                        uVar23 = *(undefined4 *)(uVar28 + 0x2ad991639a0);
                        uVar20 = *(undefined4 *)(uVar28 + 0x2ad991639a4);
                        uVar7 = *(undefined4 *)(uVar28 + 0x2ad991639a8);
                        puVar18 = (undefined4 *)(lVar1 + uVar28);
                        *puVar18 = *(undefined4 *)(&DAT_2ad9916399c + uVar28);
                        puVar18[1] = uVar23;
                        puVar18[2] = uVar20;
                        puVar18[3] = uVar7;
                        uVar28 = uVar28 + 0x10;
                      } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                      if (uVar25 == uVar26) goto LAB_2ad9914e993;
                    }
                    do {
                      *(undefined2 *)(lVar1 + uVar25 * 2) =
                           *(undefined2 *)(&DAT_2ad9916399c + uVar25 * 2);
                      uVar25 = uVar25 + 1;
                    } while (uVar26 != uVar25);
                  }
LAB_2ad9914e993:
                  *(uint *)(local_d4 + -4) = uVar15;
                  *(undefined2 *)(local_d4 + (ulonglong)uVar15 * 2) = 0;
                  goto LAB_2ad9914e9a5;
                }
                goto LAB_2ad9914efac;
              }
LAB_2ad9914e9a5:
              lVar1 = *(longlong *)(&DAT_2ad99177224 + lVar21 * 0xc);
              uVar23 = 0xfa9;
              if ((lVar1 == 0) || (lVar1 == 0xc)) {
LAB_2ad9914ea22:
                if ((_DAT_2ad99183b40 == (undefined2 *)0x0) ||
                   (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
                  _DAT_2ad99183b10 = 0xfa9;
                }
                else {
                  _DAT_2ad99183b10 = uVar23;
                  if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
                     (cVar12 = FUN_2ad99140060(0x2ad99183b3c,0), puVar11 = _DAT_2ad99183b40,
                     cVar12 != '\0')) {
                    *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
                    *puVar11 = 0;
                  }
                }
              }
              else {
                iVar19 = *(int *)(lVar1 + -4);
                if (iVar19 == 0) {
                  uVar23 = 0x13ab;
                  goto LAB_2ad9914ea22;
                }
                iVar24 = 0x19;
                if (iVar19 < 0x19) {
                  _DAT_2ad99183b10 = 0x13ab;
                  iVar24 = iVar19;
                }
                FUN_2ad991401d0(0x2ad99183b3c,lVar1,iVar24);
              }
              FUN_2ad99140a40(&local_88,0x2ad99183b3c,1,0x2ad99171b70);
              FUN_2ad99140a40(&local_98,&local_d8,0);
              lVar1 = local_84;
              if (local_84 == 0) {
LAB_2ad9914ebfc:
                FUN_2ad99140a40(&local_b8,&local_98,0,0x2ad99171b90);
                goto LAB_2ad9914ec16;
              }
              uVar30 = *(uint *)(local_84 + -4);
              uVar26 = (ulonglong)uVar30;
              if ((uVar26 == 0) && (local_94 != 0)) goto LAB_2ad9914ebfc;
              if (local_94 == 0) {
                uVar16 = 0;
                uVar15 = uVar30;
              }
              else {
                uVar16 = *(uint *)(local_94 + -4);
                uVar15 = uVar30 + uVar16;
              }
              cVar12 = FUN_2ad99140060(&local_98);
              if (cVar12 != '\0') {
                if (uVar26 != 0) {
                  lVar2 = local_94 + (ulonglong)uVar16 * 2;
                  if (uVar30 < 8) {
                    uVar25 = 0;
                  }
                  else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
                    uVar25 = 0;
                  }
                  else {
                    uVar28 = 0;
                    uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                    do {
                      puVar18 = (undefined4 *)(lVar1 + uVar28);
                      uVar23 = puVar18[1];
                      uVar20 = puVar18[2];
                      uVar7 = puVar18[3];
                      puVar3 = (undefined4 *)(lVar2 + uVar28);
                      *puVar3 = *puVar18;
                      puVar3[1] = uVar23;
                      puVar3[2] = uVar20;
                      puVar3[3] = uVar7;
                      uVar28 = uVar28 + 0x10;
                    } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                    if (uVar25 == uVar26) goto LAB_2ad9914ebe2;
                  }
                  do {
                    *(undefined2 *)(lVar2 + uVar25 * 2) = *(undefined2 *)(lVar1 + uVar25 * 2);
                    uVar25 = uVar25 + 1;
                  } while (uVar26 != uVar25);
                }
LAB_2ad9914ebe2:
                *(uint *)(local_94 + -4) = uVar15;
                *(undefined2 *)(local_94 + (ulonglong)uVar15 * 2) = 0;
                goto LAB_2ad9914ebfc;
              }
              goto LAB_2ad9914efcc;
            }
            uVar30 = *(uint *)(lVar1 + -4);
            uVar26 = (ulonglong)uVar30;
            if ((uVar26 == 0) && (local_f4 != 0)) goto LAB_2ad9914e86c;
            if (local_f4 == 0) {
              uVar16 = 0;
              uVar15 = uVar30;
            }
            else {
              uVar16 = *(uint *)(local_f4 + -4);
              uVar15 = uVar30 + uVar16;
            }
            cVar12 = FUN_2ad99140060(&local_f8);
            if (cVar12 != '\0') {
              if (uVar26 != 0) {
                lVar2 = local_f4 + (ulonglong)uVar16 * 2;
                if (uVar30 < 8) {
                  uVar25 = 0;
                }
                else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
                  uVar25 = 0;
                }
                else {
                  uVar28 = 0;
                  uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                  do {
                    puVar18 = (undefined4 *)(lVar1 + uVar28);
                    uVar23 = puVar18[1];
                    uVar20 = puVar18[2];
                    uVar7 = puVar18[3];
                    puVar3 = (undefined4 *)(lVar2 + uVar28);
                    *puVar3 = *puVar18;
                    puVar3[1] = uVar23;
                    puVar3[2] = uVar20;
                    puVar3[3] = uVar7;
                    uVar28 = uVar28 + 0x10;
                  } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                  if (uVar25 == uVar26) goto LAB_2ad9914e852;
                }
                do {
                  *(undefined2 *)(lVar2 + uVar25 * 2) = *(undefined2 *)(lVar1 + uVar25 * 2);
                  uVar25 = uVar25 + 1;
                } while (uVar26 != uVar25);
              }
LAB_2ad9914e852:
              *(uint *)(local_f4 + -4) = uVar15;
              *(undefined2 *)(local_f4 + (ulonglong)uVar15 * 2) = 0;
              goto LAB_2ad9914e86c;
            }
LAB_2ad9914efec:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x460940000001f9);
            goto LAB_2ad9914f00c;
          }
LAB_2ad9914ec16:
          FUN_2ad99140a40(&local_e8,0x2ad99160d08,0,0x2ad99171ba0);
          FUN_2ad99140a40(&local_108,&local_c8,0,0x2ad99171bb0);
          uVar30 = _DAT_2ad991610a8;
          uVar26 = (ulonglong)_DAT_2ad991610a8;
          if ((uVar26 != 0) || (local_104 == 0)) {
            if (local_104 == 0) {
              uVar16 = 0;
              uVar15 = _DAT_2ad991610a8;
            }
            else {
              uVar16 = *(uint *)(local_104 + -4);
              uVar15 = _DAT_2ad991610a8 + uVar16;
            }
            uVar22 = 0x104;
            if ((0x103 < uVar15) &&
               ((0x7ffffffd < uVar15 || (uVar22 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar22)))) {
              uVar22 = 0x7ffffffe;
            }
            cVar12 = FUN_2ad99140060(&local_108,uVar22);
            if (cVar12 != '\0') {
              if (uVar26 != 0) {
                lVar1 = local_104 + (ulonglong)uVar16 * 2;
                if (uVar30 < 8) {
                  uVar25 = 0;
                }
                else if (local_104 + -0x2ad991610ac + (ulonglong)uVar16 * 2 < 0x20) {
                  uVar25 = 0;
                }
                else {
                  uVar28 = 0;
                  uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                  do {
                    uVar23 = *(undefined4 *)(uVar28 + 0x2ad991610b0);
                    uVar20 = *(undefined4 *)(uVar28 + 0x2ad991610b4);
                    uVar7 = *(undefined4 *)(uVar28 + 0x2ad991610b8);
                    puVar18 = (undefined4 *)(lVar1 + uVar28);
                    *puVar18 = *(undefined4 *)(&DAT_2ad991610ac + uVar28);
                    puVar18[1] = uVar23;
                    puVar18[2] = uVar20;
                    puVar18[3] = uVar7;
                    uVar28 = uVar28 + 0x10;
                  } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                  if (uVar25 == uVar26) goto LAB_2ad9914ed52;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar25 * 2) =
                       *(undefined2 *)(&DAT_2ad991610ac + uVar25 * 2);
                  uVar25 = uVar25 + 1;
                } while (uVar26 != uVar25);
              }
LAB_2ad9914ed52:
              *(uint *)(local_104 + -4) = uVar15;
              *(undefined2 *)(local_104 + (ulonglong)uVar15 * 2) = 0;
              goto LAB_2ad9914ed64;
            }
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1d0944000001f9);
LAB_2ad9914ef6c:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x290944000001f9);
LAB_2ad9914ef8c:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x400940000001f9);
LAB_2ad9914efac:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x190941000001f9);
LAB_2ad9914efcc:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1e0941000001f9);
            goto LAB_2ad9914efec;
          }
LAB_2ad9914ed64:
          (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,lVar21,0,0x20);
          FUN_2ad99140a40(&local_f8,0x2ad99183b3c,1,0x2ad99171bc0);
          FUN_2ad99140a40(&local_d8,&local_108,0);
          lVar1 = local_f4;
          if (local_f4 != 0) {
            uVar30 = *(uint *)(local_f4 + -4);
            uVar26 = (ulonglong)uVar30;
            if ((uVar26 != 0) || (local_d4 == 0)) {
              if (local_d4 == 0) {
                uVar16 = 0;
                uVar15 = uVar30;
              }
              else {
                uVar16 = *(uint *)(local_d4 + -4);
                uVar15 = uVar30 + uVar16;
              }
              cVar12 = FUN_2ad99140060(&local_d8);
              if (cVar12 == '\0') goto LAB_2ad9914ef6c;
              if (uVar26 != 0) {
                lVar2 = local_d4 + (ulonglong)uVar16 * 2;
                if (uVar30 < 8) {
                  uVar25 = 0;
                }
                else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
                  uVar25 = 0;
                }
                else {
                  uVar28 = 0;
                  uVar25 = (ulonglong)(uVar30 & 0xfffffff8);
                  do {
                    puVar18 = (undefined4 *)(lVar1 + uVar28);
                    uVar23 = puVar18[1];
                    uVar20 = puVar18[2];
                    uVar7 = puVar18[3];
                    puVar3 = (undefined4 *)(lVar2 + uVar28);
                    *puVar3 = *puVar18;
                    puVar3[1] = uVar23;
                    puVar3[2] = uVar20;
                    puVar3[3] = uVar7;
                    uVar28 = uVar28 + 0x10;
                  } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
                  if (uVar25 == uVar26) goto LAB_2ad9914e530;
                }
                do {
                  *(undefined2 *)(lVar2 + uVar25 * 2) = *(undefined2 *)(lVar1 + uVar25 * 2);
                  uVar25 = uVar25 + 1;
                } while (uVar26 != uVar25);
              }
LAB_2ad9914e530:
              *(uint *)(local_d4 + -4) = uVar15;
              *(undefined2 *)(local_d4 + (ulonglong)uVar15 * 2) = 0;
            }
          }
          FUN_2ad9915eca0(&local_d8,&local_b8,0xffffffff,&local_e8);
          FUN_2ad99140000(&local_b8);
          lVar21 = lVar21 + 1;
        } while (lVar21 != 4);
      }
      (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
      FUN_2ad99140000(&local_a8);
      FUN_2ad99140000(&local_c8);
LAB_2ad9914eef2:
      FUN_2ad99140000(&local_e8);
      FUN_2ad99140000(&local_108);
      FUN_2ad99140000(&local_f8);
      FUN_2ad99140000(&local_d8);
      FUN_2ad99140000(&local_88);
      FUN_2ad99140000(&local_98);
      return;
    }
    lVar21 = SUB168(SEXT816(_DAT_2ad99178248 + 0x3b) * SEXT816(-0x7777777777777777),8) + 0x3b +
             _DAT_2ad99178248;
    (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,(lVar21 >> 5) - (lVar21 >> 0x3f),0x55,&local_108);
    uVar30 = 0;
    FUN_2ad99140a40(&local_f8,&local_108,0,0x2ad99171a70);
    uVar16 = _DAT_2ad99163a88;
    uVar26 = (ulonglong)_DAT_2ad99163a88;
    if ((uVar26 == 0) && (puVar18 = &local_f8, local_f4 != 0)) goto LAB_2ad9914de3d;
    if (local_f4 != 0) {
      uVar30 = *(uint *)(local_f4 + -4);
    }
    uVar22 = _DAT_2ad99163a88 + uVar30;
    uVar15 = 0x104;
    if ((0x103 < uVar22) &&
       ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    puVar18 = &local_f8;
    cVar12 = FUN_2ad99140060(puVar18,uVar15);
    if (cVar12 != '\0') {
      if (uVar26 != 0) {
        lVar21 = local_f4 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad99163a8cU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad99163a90);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad99163a94);
            uVar8 = *(undefined4 *)(uVar28 + 0x2ad99163a98);
            puVar3 = (undefined4 *)(lVar21 + uVar28);
            *puVar3 = *(undefined4 *)(&DAT_2ad99163a8c + uVar28);
            puVar3[1] = uVar20;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914de32;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad99163a8c + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914de32:
      *(uint *)(local_f4 + -4) = uVar22;
      *(undefined2 *)(local_f4 + (ulonglong)uVar22 * 2) = 0;
      goto LAB_2ad9914de3d;
    }
  }
  else {
    if (local_f4 != 0) {
      uVar30 = *(uint *)(local_f4 + -4);
    }
    uVar22 = _DAT_2ad991610c8 + uVar30;
    uVar15 = 0x104;
    if ((0x103 < uVar22) &&
       ((0x7ffffffd < uVar22 || (uVar15 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    cVar12 = FUN_2ad99140060(&local_f8,uVar15);
    if (cVar12 != '\0') {
      if (uVar26 != 0) {
        lVar21 = local_f4 + (ulonglong)uVar30 * 2;
        if (uVar16 < 0x10) {
          uVar25 = 0;
        }
        else if (lVar21 - 0x2ad991610ccU < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar28 = 0;
          uVar25 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar23 = *(undefined4 *)(uVar28 + 0x2ad991610d0);
            uVar20 = *(undefined4 *)(uVar28 + 0x2ad991610d4);
            uVar7 = *(undefined4 *)(uVar28 + 0x2ad991610d8);
            puVar18 = (undefined4 *)(lVar21 + uVar28);
            *puVar18 = *(undefined4 *)(&DAT_2ad991610cc + uVar28);
            puVar18[1] = uVar23;
            puVar18[2] = uVar20;
            puVar18[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar26 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar25 == uVar26) goto LAB_2ad9914cf72;
        }
        do {
          *(undefined2 *)(lVar21 + uVar25 * 2) = *(undefined2 *)(&DAT_2ad991610cc + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar26 != uVar25);
      }
LAB_2ad9914cf72:
      *(uint *)(local_f4 + -4) = uVar22;
      *(undefined2 *)(local_f4 + (ulonglong)uVar22 * 2) = 0;
      goto LAB_2ad9914cf7d;
    }
LAB_2ad9914f00c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x160923000001f9);
LAB_2ad9914f02c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x170924000001f9);
LAB_2ad9914f04c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x170925000001f9);
LAB_2ad9914f06c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x170928000001f9);
LAB_2ad9914f08c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x170929000001f9);
LAB_2ad9914f0ac:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x17092c000001f9);
LAB_2ad9914f0cc:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x17092d000001f9);
LAB_2ad9914f0ec:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x17092e000001f9);
LAB_2ad9914f10c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x17092f000001f9);
LAB_2ad9914f12c:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x170937000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x60092f000001f9);
LAB_2ad9914f16c:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1a0935000001f9);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



/* Address: 2ad9914f4b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9914f4b0(undefined1 param_1)

{
  double dVar1;
  double dVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  code *pcVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  char cVar12;
  char cVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  longlong lVar18;
  undefined8 uVar19;
  longlong lVar20;
  longlong lVar21;
  undefined4 *puVar22;
  uint uVar23;
  ulonglong uVar24;
  longlong lVar25;
  uint uVar26;
  uint uVar27;
  longlong lVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  longlong lVar33;
  int iVar34;
  double dVar35;
  double dVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined8 in_stack_fffffffffffffd48;
  undefined8 uVar43;
  undefined4 local_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  ulonglong local_280;
  undefined4 local_278;
  longlong local_274;
  undefined4 local_268;
  longlong local_264;
  undefined4 local_258;
  longlong local_254;
  undefined4 local_248;
  longlong local_244;
  ulonglong local_238;
  uint local_230;
  undefined4 local_22c;
  uint uStack_228;
  undefined4 uStack_224;
  undefined8 local_220;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 local_210;
  undefined4 uStack_20c;
  undefined8 local_208;
  undefined4 local_200;
  undefined4 local_1f8;
  longlong local_1f4;
  undefined4 local_1e8;
  longlong local_1e4;
  undefined4 local_1d8;
  longlong local_1d4;
  undefined8 local_1cc;
  undefined8 local_1c4;
  undefined4 *local_1bc;
  undefined8 local_1b4;
  undefined8 local_1ac;
  undefined4 local_1a0;
  longlong local_19c;
  longlong local_190;
  undefined4 local_188;
  longlong local_184;
  longlong local_178;
  undefined4 local_170;
  longlong local_16c;
  longlong local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined4 local_148;
  undefined8 local_144;
  undefined4 local_138;
  undefined8 local_134;
  ulonglong local_128;
  ulonglong local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined8 local_100;
  undefined4 local_f8;
  ulonglong local_f0;
  ulonglong local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined4 local_c0;
  
  local_190 = CONCAT71(local_190._1_7_,param_1);
  local_138 = 0;
  local_148 = 0;
  local_158 = 0;
  local_1a0 = 0;
  local_170 = 0;
  local_1e8 = 0;
  local_134 = 0;
  local_144 = 0;
  local_154 = 0;
  local_19c = 0;
  local_16c = 0;
  local_1e4 = 0;
  uVar14 = (*(code *)0x7ff63a102a30)(0x2ad95e68178,0x2ad99160ca0,0);
  if (-1 < (int)_DAT_2ad99178394) {
    if ((int)_DAT_2ad99178368 < (int)uVar14) {
      if ((_DAT_2ad99178262 & 0xf) != 0) {
        _DAT_2ad99178262 = _DAT_2ad99178262 & 0xffef;
      }
      if ((_DAT_2ad991782a2 & 0xf) != 0) {
        _DAT_2ad991782a2 = _DAT_2ad991782a2 & 0xffef;
      }
      if ((_DAT_2ad991782e2 & 0xf) != 0) {
        _DAT_2ad991782e2 = _DAT_2ad991782e2 & 0xffef;
      }
      if ((_DAT_2ad99178322 & 0xf) != 0) {
        _DAT_2ad99178322 = _DAT_2ad99178322 & 0xffef;
      }
      if ((_DAT_2ad99178362 & 0xf) != 0) {
        _DAT_2ad99178362 = _DAT_2ad99178362 & 0xffef;
      }
      (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178260,uVar14,0);
      (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad991782a0,uVar14,0);
      (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad991782e0,uVar14,0);
      (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178320,uVar14,0);
      (*(code *)0x7ff63a0da0e0)(0x2ad95e68178,0x2ad99178360,uVar14,0);
      if ((_DAT_2ad99178262 & 0xf) != 0) {
        _DAT_2ad99178262 = _DAT_2ad99178262 | 0x10;
      }
      if ((_DAT_2ad991782a2 & 0xf) != 0) {
        _DAT_2ad991782a2 = _DAT_2ad991782a2 | 0x10;
      }
      if ((_DAT_2ad991782e2 & 0xf) != 0) {
        _DAT_2ad991782e2 = _DAT_2ad991782e2 | 0x10;
      }
      if ((_DAT_2ad99178322 & 0xf) != 0) {
        _DAT_2ad99178322 = _DAT_2ad99178322 | 0x10;
      }
      if ((_DAT_2ad99178362 & 0xf) != 0) {
        _DAT_2ad99178362 = _DAT_2ad99178362 | 0x10;
      }
    }
    dVar8 = _DAT_2ad99160748;
    dVar7 = _DAT_2ad99160740;
    dVar2 = _DAT_2ad99160738;
    uVar19 = _DAT_2ad99160730;
    uVar27 = ~_DAT_2ad99178394 + uVar14;
    if ((int)(~_DAT_2ad99178394 + uVar14) < 1) {
      uVar27 = 0;
    }
    if (-1 < (int)(uVar27 - (uVar27 == uVar14))) {
      local_178 = (longlong)(int)(uVar14 - 2);
      local_238 = (ulonglong)(int)(uVar14 - 1);
      uVar31 = (ulonglong)uVar27 - (ulonglong)(uVar27 == uVar14);
      do {
        dVar9 = 0.0;
        iVar34 = 1;
        uVar27 = (uint)uVar31;
        uVar29 = uVar31 & 0xffffffff;
        do {
          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
          iVar16 = (int)uVar29;
          if ((int)uVar14 <= iVar16) goto LAB_2ad9914f976;
          local_1d8 = 0x1000058;
          uVar43 = CONCAT44(uVar37,iVar16);
          local_1d4 = 0x100000008;
          local_1cc = 0;
          local_1c4 = 0x100000000;
          local_1ac = 0;
          local_1b4 = 0;
          local_1bc = &local_290;
          iVar15 = (*(code *)0x7ff63a1021d0)(0x2ad95e68178,3,0,_DAT_2ad99183b24,uVar43,1,&local_1d8)
          ;
          uVar38 = 0;
          uVar39 = 0;
          if (0 < iVar15) {
            uVar38 = local_290;
            uVar39 = uStack_28c;
          }
          local_1d8 = 0x1000058;
          in_stack_fffffffffffffd48 = CONCAT44((int)((ulonglong)uVar43 >> 0x20),iVar16);
          local_1d4 = 0x100000008;
          local_1cc = 0;
          local_1c4 = 0x100000000;
          local_1ac = 0;
          local_1b4 = 0;
          local_1bc = &local_290;
          iVar15 = (*(code *)0x7ff63a1021d0)
                             (0x2ad95e68178,4,0,_DAT_2ad99183b24,in_stack_fffffffffffffd48,1,
                              &local_1d8);
          uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
          uVar40 = 0;
          uVar41 = 0;
          if (0 < iVar15) {
            uVar40 = local_290;
            uVar41 = uStack_28c;
          }
          iVar34 = iVar34 + 1;
          uVar29 = (ulonglong)(iVar16 + 1);
          dVar9 = dVar9 + ((double)CONCAT44(uVar39,uVar38) - (double)CONCAT44(uVar41,uVar40));
        } while (iVar34 != 0xfb);
        iVar34 = 0xfa;
LAB_2ad9914f976:
        uVar38 = (undefined4)uVar19;
        uVar39 = (undefined4)((ulonglong)uVar19 >> 0x20);
        if (DAT_2ad99173035 == '\0') {
          uVar38 = 0;
          uVar39 = 0;
        }
        local_22c = 8;
        in_stack_fffffffffffffd48 = CONCAT44(uVar37,1);
        local_200 = 0;
        local_208 = 0;
        local_210 = 0;
        uStack_20c = 0;
        local_218 = 0;
        uStack_214 = 0;
        local_220 = 0;
        uStack_228 = 0;
        uStack_224 = 0;
        local_230 = 0x110058;
        iVar15 = uVar14 - uVar27;
        iVar16 = 0;
        if (0 < iVar15) {
          iVar16 = iVar15;
        }
        (*(code *)0x7ff63a0eeec0)
                  (0x2ad95e68178,_DAT_2ad9917846c,0,uVar31 & 0xffffffff,in_stack_fffffffffffffd48,
                   &local_230);
        if ((ulonglong)uStack_228 == 0) {
LAB_2ad9915446a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1605d0000001f6);
LAB_2ad9915448a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1406fc000001f6);
LAB_2ad991544aa:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1506fb000001f6);
LAB_2ad991544ca:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1105f2000001f6);
LAB_2ad991544ea:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1f05f2000001f6);
LAB_2ad9915450a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1005da000001f6);
LAB_2ad9915452a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1005d6000001f6);
LAB_2ad9915454a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x24070b000001f6);
LAB_2ad9915456a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x34070b000001f6);
LAB_2ad9915458a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x210667000001f6);
LAB_2ad991545aa:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x260632000001f6);
          goto LAB_2ad991545ca;
        }
        uVar29 = ~uVar31;
        lVar18 = 0;
        if ((local_230 & 0x100000) != 0) {
          lVar18 = (ulonglong)uStack_228 - 1;
        }
        dVar35 = *(double *)(CONCAT44(local_210,uStack_214) + lVar18 * 8);
        _DAT_2ad99178478 = dVar35;
        if (DAT_2ad99173037 == '\x01') {
          if (local_178 <= (longlong)uVar31) {
            dVar36 = 0.0;
            if (uVar27 < _DAT_2ad99178368) {
LAB_2ad9914fb68:
              uVar32 = _DAT_2ad99178368 + uVar29;
              if ((_DAT_2ad99178362 & 0x10) == 0) {
                uVar32 = uVar31;
              }
              *(double *)(_DAT_2ad9917837c + uVar32 * 8) = dVar36;
              goto LAB_2ad9914fb93;
            }
            goto LAB_2ad9915450a;
          }
          uVar32 = (ulonglong)_DAT_2ad99178368;
          dVar36 = dVar35;
          if (DAT_2ad99173038 != '\x01') {
LAB_2ad9914fb41:
            if (uVar27 < _DAT_2ad99178368) goto LAB_2ad9914fb68;
            goto LAB_2ad9915452a;
          }
          if (uVar32 <= uVar31 + 1) goto LAB_2ad9915454a;
          uVar24 = (ulonglong)(int)(uVar27 + 2);
          local_280 = uVar29;
          if (uVar24 < uVar32) {
            uVar30 = ~uVar24 + uVar32;
            uVar32 = (uVar32 - uVar31) - 2;
            if ((_DAT_2ad99178362 & 0x10) == 0) {
              uVar30 = uVar24;
              uVar32 = uVar31 + 1;
            }
            dVar36 = *(double *)(_DAT_2ad9917837c + uVar30 * 8) * dVar8 +
                     *(double *)(_DAT_2ad9917837c + uVar32 * 8) * dVar7 + dVar35 * dVar2;
            goto LAB_2ad9914fb41;
          }
          goto LAB_2ad9915456a;
        }
LAB_2ad9914fb93:
        if ((longlong)uVar31 < (longlong)local_238) {
          if (_DAT_2ad99178368 <= uVar27) goto LAB_2ad991544ca;
          if (uVar31 + 1 < (ulonglong)_DAT_2ad99178368) goto LAB_2ad9914fbbe;
          goto LAB_2ad991544ea;
        }
LAB_2ad9914fbbe:
        dVar9 = (dVar9 / (double)iVar34) * (double)CONCAT44(uVar39,uVar38);
        dVar36 = dVar9;
        dVar10 = dVar35;
        dVar11 = dVar35;
        if (iVar15 < 2) goto LAB_2ad991501a0;
        if (-1 < _DAT_2ad99178490) {
          if (dVar35 < _DAT_2ad991784a0) {
            if (((DAT_2ad991784d1 == '\x01') &&
                (uVar23 = (iVar16 + uVar27) - _DAT_2ad991784b0, (int)uVar23 < (int)uVar14)) &&
               (-1 < (int)uVar23)) {
              if (_DAT_2ad991782e8 <= uVar23) goto LAB_2ad991546aa;
              uVar32 = (ulonglong)_DAT_2ad991782e8 + ~(ulonglong)uVar23;
              if ((_DAT_2ad991782e2 & 0x10) == 0) {
                uVar32 = (ulonglong)uVar23;
              }
              *(undefined8 *)(_DAT_2ad991782fc + uVar32 * 8) = 0;
            }
            DAT_2ad991784d1 = '\x01';
            _DAT_2ad991784a0 = dVar35;
            _DAT_2ad991784b0 = iVar16;
LAB_2ad9914fe90:
            dVar36 = _DAT_2ad99178480;
            dVar10 = _DAT_2ad991784a0;
            dVar11 = _DAT_2ad991784b8;
            if (0 < _DAT_2ad99178490) goto LAB_2ad991501a0;
            goto LAB_2ad9914fea3;
          }
          if (dVar35 <= _DAT_2ad991784a0) goto LAB_2ad9914fe90;
          _DAT_2ad99178498 = iVar16 - _DAT_2ad991784b0;
          uVar23 = _DAT_2ad99178498 + uVar27;
          if (((int)uVar23 < (int)uVar14) && (-1 < (int)uVar23)) {
            if (_DAT_2ad991782e8 <= uVar23) goto LAB_2ad9915468a;
            uVar32 = (ulonglong)_DAT_2ad991782e8 + ~(ulonglong)uVar23;
            if ((_DAT_2ad991782e2 & 0x10) == 0) {
              uVar32 = (ulonglong)uVar23;
            }
            *(undefined8 *)(_DAT_2ad991782fc + uVar32 * 8) = 0xbff0000000000000;
          }
          DAT_2ad991784d1 = '\x01';
          if ((local_230 & 0xf0000) != 0) {
            local_230 = local_230 | 0x100000;
          }
          in_stack_fffffffffffffd48 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffd48 >> 0x20),1);
          local_280 = uVar29;
          (*(code *)0x7ff63a0eeec0)
                    (0x2ad95e68178,_DAT_2ad9917846c,0,uVar23,in_stack_fffffffffffffd48,&local_230);
          if ((ulonglong)uStack_228 != 0) {
            lVar18 = 0;
            if ((local_230 & 0x100000) != 0) {
              lVar18 = (ulonglong)uStack_228 - 1;
            }
            dVar36 = *(double *)(CONCAT44(local_210,uStack_214) + lVar18 * 8);
            uVar29 = local_280;
            dVar35 = _DAT_2ad99178478;
            if (DAT_2ad991784d0 == '\0') {
              if (dVar36 * (_DAT_2ad99178480 / _DAT_2ad99160750 + _DAT_2ad99160758) <=
                  _DAT_2ad99178478) goto LAB_2ad9914fe6a;
              goto LAB_2ad9914fe90;
            }
            if (_DAT_2ad99178478 - dVar36 < _DAT_2ad99178480) goto LAB_2ad9914fe90;
LAB_2ad9914fe6a:
            if (_DAT_2ad99178498 < (int)(uint)DAT_2ad991784d5) goto LAB_2ad9914fe90;
            _DAT_2ad99178490 = -1;
            DAT_2ad991784d3 = '\0';
            _DAT_2ad991784b8 = _DAT_2ad99178478;
            DAT_2ad991784d1 = '\0';
            _DAT_2ad991784c8 = iVar16;
            goto LAB_2ad9914ffc2;
          }
          goto LAB_2ad991545aa;
        }
LAB_2ad9914fea3:
        if (dVar35 <= _DAT_2ad991784b8) {
LAB_2ad9914ffc2:
          dVar36 = _DAT_2ad99178480;
          dVar10 = _DAT_2ad991784a0;
          dVar11 = _DAT_2ad991784b8;
          if (_DAT_2ad991784b8 <= dVar35) goto LAB_2ad991501a0;
          _DAT_2ad99178498 = iVar16 - _DAT_2ad991784c8;
          uVar23 = _DAT_2ad99178498 + uVar27;
          if (((int)uVar23 < (int)uVar14) && (-1 < (int)uVar23)) {
            if (_DAT_2ad99178328 <= uVar23) goto LAB_2ad9915462a;
            uVar32 = (ulonglong)_DAT_2ad99178328 + ~(ulonglong)uVar23;
            if ((_DAT_2ad99178322 & 0x10) == 0) {
              uVar32 = (ulonglong)uVar23;
            }
            *(undefined8 *)(_DAT_2ad9917833c + uVar32 * 8) = 0x3ff0000000000000;
          }
          in_stack_fffffffffffffd48 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffd48 >> 0x20),1);
          DAT_2ad991784d3 = '\x01';
          local_280 = uVar29;
          (*(code *)0x7ff63a0eeec0)
                    (0x2ad95e68178,_DAT_2ad9917846c,0,uVar23,in_stack_fffffffffffffd48,&local_230);
          if ((ulonglong)uStack_228 != 0) {
            lVar18 = 0;
            if ((local_230 & 0x100000) != 0) {
              lVar18 = (ulonglong)uStack_228 - 1;
            }
            dVar1 = *(double *)(CONCAT44(local_210,uStack_214) + lVar18 * 8);
            uVar29 = local_280;
            dVar35 = _DAT_2ad99178478;
            dVar36 = _DAT_2ad99178480;
            dVar10 = _DAT_2ad991784a0;
            dVar11 = _DAT_2ad991784b8;
            if (DAT_2ad991784d0 == '\0') {
              if (_DAT_2ad99178478 <=
                  dVar1 * (_DAT_2ad99178480 / _DAT_2ad99160760 + _DAT_2ad99160758))
              goto LAB_2ad99150138;
            }
            else if (_DAT_2ad99178480 <= dVar1 - _DAT_2ad99178478) {
LAB_2ad99150138:
              if ((int)(uint)DAT_2ad991784d5 <= _DAT_2ad99178498) {
                _DAT_2ad99178490 = 1;
                DAT_2ad991784d3 = '\0';
                _DAT_2ad991784a0 = _DAT_2ad99178478;
                DAT_2ad991784d1 = '\0';
                dVar10 = _DAT_2ad991784a0;
                _DAT_2ad991784b0 = iVar16;
              }
            }
            goto LAB_2ad991501a0;
          }
          goto LAB_2ad9915458a;
        }
        if (((DAT_2ad991784d3 == '\x01') &&
            (uVar23 = (iVar16 + uVar27) - _DAT_2ad991784c8, (int)uVar23 < (int)uVar14)) &&
           (-1 < (int)uVar23)) {
          if (_DAT_2ad99178328 <= uVar23) goto LAB_2ad9915464a;
          uVar32 = (ulonglong)_DAT_2ad99178328 + ~(ulonglong)uVar23;
          if ((_DAT_2ad99178322 & 0x10) == 0) {
            uVar32 = (ulonglong)uVar23;
          }
          *(undefined8 *)(_DAT_2ad9917833c + uVar32 * 8) = 0;
        }
        DAT_2ad991784d3 = '\x01';
        dVar36 = _DAT_2ad99178480;
        dVar10 = _DAT_2ad991784a0;
        dVar11 = dVar35;
        _DAT_2ad991784c8 = iVar16;
LAB_2ad991501a0:
        _DAT_2ad991784b8 = dVar11;
        _DAT_2ad991784a0 = dVar10;
        _DAT_2ad99178480 = dVar36;
        if (_DAT_2ad991782e8 <= uVar27) {
LAB_2ad9915444a:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x14067a000001f6);
          goto LAB_2ad9915446a;
        }
        uVar32 = _DAT_2ad991782e8 + uVar29;
        if ((_DAT_2ad991782e2 & 0x10) == 0) {
          uVar32 = uVar31;
        }
        *(undefined8 *)(_DAT_2ad991782fc + uVar32 * 8) = 0;
        if (_DAT_2ad99178328 <= uVar27) {
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x15067b000001f6);
          goto LAB_2ad9915444a;
        }
        uVar32 = _DAT_2ad99178328 + uVar29;
        if ((_DAT_2ad99178322 & 0x10) == 0) {
          uVar32 = uVar31;
        }
        *(undefined8 *)(_DAT_2ad9917833c + uVar32 * 8) = 0;
        if (iVar15 == 1) {
          _DAT_2ad99178488 = _DAT_2ad99160768;
          if (DAT_2ad99173036 == '\0') {
            _DAT_2ad99178488 = 0.0;
          }
          _DAT_2ad99178488 = dVar9 * _DAT_2ad99178488;
          _DAT_2ad991784a8 = dVar35;
          _DAT_2ad991784c0 = dVar35;
        }
        else if (1 < iVar15) {
          if (_DAT_2ad99178494 < 0) {
LAB_2ad991505b5:
            if (_DAT_2ad991784c0 < dVar35) {
              if (((DAT_2ad991784d4 == '\x01') &&
                  (uVar23 = (iVar16 + uVar27) - _DAT_2ad991784cc, (int)uVar23 < (int)uVar14)) &&
                 (-1 < (int)uVar23)) {
                if (_DAT_2ad991782a8 <= uVar23) goto LAB_2ad9915472a;
                uVar32 = (ulonglong)_DAT_2ad991782a8 + ~(ulonglong)uVar23;
                if ((_DAT_2ad991782a2 & 0x10) == 0) {
                  uVar32 = (ulonglong)uVar23;
                }
                *(undefined8 *)(_DAT_2ad991782bc + uVar32 * 8) = 0;
              }
              DAT_2ad991784d4 = '\x01';
              _DAT_2ad991784c0 = dVar35;
              _DAT_2ad991784cc = iVar16;
              goto LAB_2ad9915037e;
            }
          }
          else {
            if (dVar35 < _DAT_2ad991784a8) {
              if (((DAT_2ad991784d2 == '\x01') &&
                  (uVar23 = (iVar16 + uVar27) - _DAT_2ad991784b4, (int)uVar23 < (int)uVar14)) &&
                 (-1 < (int)uVar23)) {
                if (_DAT_2ad99178268 <= uVar23) goto LAB_2ad9915476a;
                uVar32 = (ulonglong)_DAT_2ad99178268 + ~(ulonglong)uVar23;
                if ((_DAT_2ad99178262 & 0x10) == 0) {
                  uVar32 = (ulonglong)uVar23;
                }
                *(undefined8 *)(_DAT_2ad9917827c + uVar32 * 8) = 0;
              }
              DAT_2ad991784d2 = '\x01';
              _DAT_2ad991784a8 = dVar35;
              _DAT_2ad991784b4 = iVar16;
LAB_2ad991505a2:
              if (0 < _DAT_2ad99178494) goto LAB_2ad9915037e;
              goto LAB_2ad991505b5;
            }
            if (dVar35 <= _DAT_2ad991784a8) goto LAB_2ad991505a2;
            _DAT_2ad9917849c = iVar16 - _DAT_2ad991784b4;
            uVar23 = _DAT_2ad9917849c + uVar27;
            if (((int)uVar23 < (int)uVar14) && (-1 < (int)uVar23)) {
              if (_DAT_2ad99178268 <= uVar23) goto LAB_2ad9915474a;
              uVar32 = (ulonglong)_DAT_2ad99178268 + ~(ulonglong)uVar23;
              if ((_DAT_2ad99178262 & 0x10) == 0) {
                uVar32 = (ulonglong)uVar23;
              }
              *(undefined8 *)(_DAT_2ad9917827c + uVar32 * 8) = 0xbff0000000000000;
            }
            in_stack_fffffffffffffd48 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffd48 >> 0x20),1);
            DAT_2ad991784d2 = '\x01';
            local_280 = uVar29;
            (*(code *)0x7ff63a0eeec0)
                      (0x2ad95e68178,_DAT_2ad9917846c,0,uVar23,in_stack_fffffffffffffd48,&local_230)
            ;
            if ((ulonglong)uStack_228 == 0) goto LAB_2ad991546ca;
            lVar18 = 0;
            if ((local_230 & 0x100000) != 0) {
              lVar18 = (ulonglong)uStack_228 - 1;
            }
            dVar9 = *(double *)(CONCAT44(local_210,uStack_214) + lVar18 * 8);
            uVar29 = local_280;
            dVar35 = _DAT_2ad99178478;
            if (DAT_2ad991784d0 == '\0') {
              if (dVar9 * (_DAT_2ad99178488 / _DAT_2ad99160750 + _DAT_2ad99160758) <=
                  _DAT_2ad99178478) goto LAB_2ad99150583;
              goto LAB_2ad991505a2;
            }
            if (_DAT_2ad99178478 - dVar9 < _DAT_2ad99178488) goto LAB_2ad991505a2;
LAB_2ad99150583:
            if (_DAT_2ad9917849c < (int)(uint)DAT_2ad991784d5) goto LAB_2ad991505a2;
            _DAT_2ad99178494 = -1;
            DAT_2ad991784d4 = '\0';
            _DAT_2ad991784c0 = _DAT_2ad99178478;
            DAT_2ad991784d2 = '\0';
            _DAT_2ad991784cc = iVar16;
          }
          if (dVar35 < _DAT_2ad991784c0) {
            _DAT_2ad9917849c = iVar16 - _DAT_2ad991784cc;
            uVar23 = _DAT_2ad9917849c + uVar27;
            if (((int)uVar23 < (int)uVar14) && (-1 < (int)uVar23)) {
              if (_DAT_2ad991782a8 <= uVar23) goto LAB_2ad9915470a;
              uVar32 = (ulonglong)_DAT_2ad991782a8 + ~(ulonglong)uVar23;
              if ((_DAT_2ad991782a2 & 0x10) == 0) {
                uVar32 = (ulonglong)uVar23;
              }
              *(undefined8 *)(_DAT_2ad991782bc + uVar32 * 8) = 0x3ff0000000000000;
            }
            in_stack_fffffffffffffd48 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffd48 >> 0x20),1);
            DAT_2ad991784d4 = '\x01';
            local_280 = uVar29;
            (*(code *)0x7ff63a0eeec0)
                      (0x2ad95e68178,_DAT_2ad9917846c,0,uVar23,in_stack_fffffffffffffd48,&local_230)
            ;
            if ((ulonglong)uStack_228 == 0) goto LAB_2ad9915466a;
            lVar18 = 0;
            if ((local_230 & 0x100000) != 0) {
              lVar18 = (ulonglong)uStack_228 - 1;
            }
            dVar9 = *(double *)(CONCAT44(local_210,uStack_214) + lVar18 * 8);
            uVar29 = local_280;
            if (DAT_2ad991784d0 == '\0') {
              if (_DAT_2ad99178478 <=
                  dVar9 * (_DAT_2ad99178488 / _DAT_2ad99160760 + _DAT_2ad99160758))
              goto LAB_2ad99150838;
            }
            else if (_DAT_2ad99178488 <= dVar9 - _DAT_2ad99178478) {
LAB_2ad99150838:
              if ((int)(uint)DAT_2ad991784d5 <= _DAT_2ad9917849c) {
                _DAT_2ad99178494 = 1;
                DAT_2ad991784d4 = '\0';
                _DAT_2ad991784a8 = _DAT_2ad99178478;
                DAT_2ad991784d2 = '\0';
                _DAT_2ad991784b4 = iVar16;
              }
            }
          }
        }
LAB_2ad9915037e:
        if (_DAT_2ad991782a8 <= uVar27) goto LAB_2ad991544aa;
        uVar32 = _DAT_2ad991782a8 + uVar29;
        if ((_DAT_2ad991782a2 & 0x10) == 0) {
          uVar32 = uVar31;
        }
        *(undefined8 *)(_DAT_2ad991782bc + uVar32 * 8) = 0;
        if (_DAT_2ad99178268 <= uVar27) goto LAB_2ad9915448a;
        uVar29 = _DAT_2ad99178268 + uVar29;
        if ((_DAT_2ad99178262 & 0x10) == 0) {
          uVar29 = uVar31;
        }
        *(undefined8 *)(_DAT_2ad9917827c + uVar29 * 8) = 0;
        (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_230);
        bVar5 = 0 < (longlong)uVar31;
        uVar31 = uVar31 - 1;
      } while (bVar5);
    }
  }
  local_238 = local_238 & 0xffffffff00000000;
  _DAT_2ad99178394 = (*(code *)0x7ff63a102a30)(0x2ad95e68178,0x2ad99160ca0,0);
  local_258 = 0;
  local_268 = 0;
  local_254 = 0;
  local_264 = 0;
  uVar37 = 0x99178301;
  if (DAT_2ad99183ce0 == '\0') {
    (*(code *)0x7ff63a101d80)(0x2ad95e68178,&local_1d8);
    if (local_1c4._4_4_ - 1U < 5) {
                    /* WARNING: Could not emulate address calculation at 0x02ad9915096b */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(&DAT_2ad99160798 + (ulonglong)(local_1c4._4_4_ - 1U) * 8))();
      return;
    }
    uVar37 = 0;
  }
  local_280 = CONCAT44(local_280._4_4_,uVar37);
  FUN_2ad99140000(&local_258);
  iVar16 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
  uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
  iVar34 = 0;
  if (0 < iVar16) {
    iVar16 = 0;
    local_238 = local_238 & 0xffffffff00000000;
    iVar34 = 0;
    lVar18 = (longlong)_DAT_2ad99183c78;
    do {
      uVar19 = (*(code *)0x7ff63a107df0)(0x2ad95e68178,iVar16);
      cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar19);
      if (cVar12 != '\0') {
        (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
        FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99170af8);
        if (local_1e4 == _DAT_2ad99183b2c) {
LAB_2ad99150f29:
          lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0xc);
          if (lVar20 == lVar18) {
            lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2);
            if (lVar20 == 0) {
              iVar34 = iVar34 + 1;
LAB_2ad99150f7c:
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
            }
            else {
              lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2);
              if (lVar20 == 1) {
                local_238 = CONCAT44(local_238._4_4_,(int)local_238 + 1);
                goto LAB_2ad99150f7c;
              }
            }
            (*(code *)0x7ff63a107f70)(0x2ad95e68178,6);
            (*(code *)0x7ff63a107f70)(0x2ad95e68178,7);
            (*(code *)0x7ff63a107f70)(0x2ad95e68178,10);
            (*(code *)0x7ff63a107f70)(0x2ad95e68178,9);
            cVar12 = (*(code *)0x7ff63a1084b0)(0x2ad95e68178,uVar19);
            if ((cVar12 != '\0') && (iVar15 = (*(code *)0x7ff63a108810)(0x2ad95e68178), 0 < iVar15))
            {
              iVar15 = 0;
              do {
                lVar20 = (*(code *)0x7ff63a108860)(0x2ad95e68178,iVar15);
                if ((lVar20 != 0) &&
                   (lVar21 = (*(code *)0x7ff63a108940)(0x2ad95e68178,lVar20,4), lVar21 == 0)) {
                  (*(code *)0x7ff63a1088b0)(0x2ad95e68178,lVar20,7);
                }
                iVar15 = iVar15 + 1;
                iVar17 = (*(code *)0x7ff63a108810)(0x2ad95e68178);
              } while (iVar15 < iVar17);
            }
          }
        }
        else if ((local_1e4 != 0) && (_DAT_2ad99183b2c != 0)) {
          uVar14 = *(uint *)(local_1e4 + -4);
          uVar27 = *(uint *)(_DAT_2ad99183b2c + -4);
          uVar23 = uVar27;
          if (uVar14 < uVar27) {
            uVar23 = uVar14;
          }
          iVar15 = uVar14 - uVar27;
          if (uVar23 != 0) {
            uVar31 = 1;
            do {
              uVar3 = *(ushort *)(local_1e4 + -2 + uVar31 * 2);
              uVar4 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar31 * 2);
              if (uVar23 <= uVar31) break;
              uVar31 = uVar31 + 1;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar15 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar15 == 0) goto LAB_2ad99150f29;
        }
      }
      iVar16 = iVar16 + 1;
      iVar15 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
      uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
    } while (iVar16 < iVar15);
  }
  cVar12 = DAT_2ad99183c30;
  iVar16 = (int)local_238;
  if (iVar34 == 0 && (int)local_238 == 0) {
    if ((DAT_2ad99183c30 == '\0') || (_DAT_2ad99173050 == 0)) {
      if ((DAT_2ad991781d0 != '\0') || (DAT_2ad99178210 == '\0')) goto LAB_2ad99153021;
      local_f0 = 0x800110058;
      local_128 = 0x800110058;
      local_e8 = 0;
      local_e0 = 0;
      local_d8 = 0;
      uStack_d4 = 0;
      local_d0 = 0;
      uStack_cc = 0;
      local_c8 = 0;
      local_c0 = 0;
      local_120 = 0;
      local_118 = 0;
      local_110 = 0;
      uStack_10c = 0;
      local_108 = 0;
      uStack_104 = 0;
      local_100 = 0;
      local_f8 = 0;
      (*(code *)0x7ff63a0eeec0)(0x2ad95e68178,_DAT_2ad99178470,0,0,CONCAT44(uVar37,1),&local_f0);
      (*(code *)0x7ff63a0eeec0)(0x2ad95e68178,_DAT_2ad99178470,1,0,1,&local_128);
      if ((local_e8 & 0xffffffff) == 0) goto LAB_2ad991547aa;
      lVar18 = 0;
      if ((local_f0 & 0x100000) != 0) {
        lVar18 = (local_e8 & 0xffffffff) - 1;
      }
      if ((local_120 & 0xffffffff) == 0) goto LAB_2ad991547ca;
      lVar20 = 0;
      if ((local_128 & 0x100000) != 0) {
        lVar20 = (local_120 & 0xffffffff) - 1;
      }
      if ((ulonglong)_DAT_2ad99178268 < 2) goto LAB_2ad991547ea;
      lVar21 = (ulonglong)_DAT_2ad99178268 - 2;
      if ((_DAT_2ad99178262 & 0x10) == 0) {
        lVar21 = 1;
      }
      if ((ulonglong)_DAT_2ad991782e8 < 2) goto LAB_2ad9915480a;
      lVar25 = (ulonglong)_DAT_2ad991782e8 - 2;
      if ((_DAT_2ad991782e2 & 0x10) == 0) {
        lVar25 = 1;
      }
      if ((ulonglong)_DAT_2ad991782a8 < 2) goto LAB_2ad9915484a;
      lVar28 = (ulonglong)_DAT_2ad991782a8 - 2;
      if ((_DAT_2ad991782a2 & 0x10) == 0) {
        lVar28 = 1;
      }
      if (1 < (ulonglong)_DAT_2ad99178328) {
        lVar33 = (ulonglong)_DAT_2ad99178328 - 2;
        dVar2 = *(double *)(_DAT_2ad991782bc + lVar28 * 8);
        if ((_DAT_2ad99178322 & 0x10) == 0) {
          lVar33 = 1;
        }
        dVar7 = *(double *)(_DAT_2ad9917833c + lVar33 * 8);
        if (*(double *)(CONCAT44(local_108,uStack_10c) + lVar20 * 8) < _DAT_2ad99178438) {
LAB_2ad99151517:
          if (*(double *)(CONCAT44(local_d0,uStack_d4) + lVar18 * 8) <= _DAT_2ad99178438) {
            if ((dVar2 != _DAT_2ad99160758) || (NAN(dVar2) || NAN(_DAT_2ad99160758))) {
              if ((dVar7 != _DAT_2ad99160758) || (NAN(dVar7) || NAN(_DAT_2ad99160758)))
              goto LAB_2ad991543f7;
            }
            if (((byte)local_280 & _DAT_2ad99183c98 != 1) == 1) {
              uVar19 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
              cVar13 = FUN_2ad9915be70(uVar19);
              if ((cVar13 != '\0') &&
                 ((((DAT_2ad99178401 == '\0' || ((char)local_190 != '\0')) &&
                   (iVar34 = FUN_2ad9915bf20(), iVar34 == 0)) &&
                  (_DAT_2ad99178440 - _DAT_2ad99178438 <= _DAT_2ad99183c80 * _DAT_2ad99178250)))) {
                if (cVar12 != '\0') {
                  _DAT_2ad99173048 = _DAT_2ad99178438;
                  _DAT_2ad99173040 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
                  _DAT_2ad99173050 = -1;
                  uVar19 = 0x2ad99162c10;
                  goto LAB_2ad99152317;
                }
                uVar19 = FUN_2ad99159c50(_DAT_2ad99183c50,_DAT_2ad99183c60);
                uVar37 = (undefined4)uVar19;
                uVar38 = (undefined4)((ulonglong)uVar19 >> 0x20);
                FUN_2ad99140a40(&local_1e8,0x2ad99162a48,0,0x2ad99170b38);
                uVar19 = 1;
                goto LAB_2ad991543ee;
              }
            }
          }
        }
        else {
          dVar8 = *(double *)(_DAT_2ad9917827c + lVar21 * 8);
          if ((dVar8 != _DAT_2ad99160770) || (NAN(dVar8) || NAN(_DAT_2ad99160770))) {
            dVar8 = *(double *)(_DAT_2ad991782fc + lVar25 * 8);
            if ((dVar8 != _DAT_2ad99160770) || (NAN(dVar8) || NAN(_DAT_2ad99160770)))
            goto LAB_2ad99151517;
          }
          if (((byte)local_280 & _DAT_2ad99183c98 != 2) == 1) {
            uVar19 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
            cVar13 = FUN_2ad9915be70(uVar19);
            if ((((cVar13 != '\0') && ((DAT_2ad99178401 == '\0' || ((char)local_190 != '\0')))) &&
                (iVar34 = FUN_2ad9915bf20(), iVar34 == 0)) &&
               (_DAT_2ad99178440 - _DAT_2ad99178438 <= _DAT_2ad99183c80 * _DAT_2ad99178250)) {
              if (cVar12 == '\0') {
                uVar19 = FUN_2ad99159c50(_DAT_2ad99183c50,_DAT_2ad99183c60);
                uVar37 = (undefined4)uVar19;
                uVar38 = (undefined4)((ulonglong)uVar19 >> 0x20);
                FUN_2ad99140a40(&local_1e8,0x2ad99162988,0,0x2ad99170b28);
                uVar19 = 0;
LAB_2ad991543ee:
                FUN_2ad99159f70(uVar19,CONCAT44(uVar38,uVar37),&local_1e8);
              }
              else {
                _DAT_2ad99173048 = _DAT_2ad99178440;
                _DAT_2ad99173040 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
                _DAT_2ad99173050 = 1;
                uVar19 = 0x2ad99162b80;
LAB_2ad99152317:
                (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,uVar19);
              }
            }
          }
        }
LAB_2ad991543f7:
        (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_128);
        (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_f0);
        goto LAB_2ad99153021;
      }
      goto LAB_2ad9915488a;
    }
    lVar18 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
    if (_DAT_2ad99183c38 + _DAT_2ad99173040 <= lVar18) {
      if (_DAT_2ad99173050 < 1) {
        if (_DAT_2ad99173050 < 0) {
          if ((double)((ulonglong)(_DAT_2ad99173048 - _DAT_2ad99178438) & _DAT_2ad99160780) <=
              (double)_DAT_2ad99183c40 * _DAT_2ad99183b18) {
            uVar19 = FUN_2ad99159c50(_DAT_2ad99183c50,_DAT_2ad99183c60);
            uVar37 = (undefined4)uVar19;
            uVar38 = (undefined4)((ulonglong)uVar19 >> 0x20);
            FUN_2ad99140a40(&local_1e8,0x2ad99162a48,0,0x2ad99170b18);
            uVar19 = 1;
            goto LAB_2ad991521ea;
          }
          uVar19 = 0x2ad99162ae8;
          goto LAB_2ad9915115b;
        }
      }
      else if ((double)((ulonglong)(_DAT_2ad99173048 - _DAT_2ad99178440) & _DAT_2ad99160780) <=
               (double)_DAT_2ad99183c40 * _DAT_2ad99183b18) {
        uVar19 = FUN_2ad99159c50(_DAT_2ad99183c50,_DAT_2ad99183c60);
        uVar37 = (undefined4)uVar19;
        uVar38 = (undefined4)((ulonglong)uVar19 >> 0x20);
        FUN_2ad99140a40(&local_1e8,0x2ad99162988,0,0x2ad99170b08);
        uVar19 = 0;
LAB_2ad991521ea:
        FUN_2ad99159f70(uVar19,CONCAT44(uVar38,uVar37),&local_1e8);
      }
      else {
        uVar19 = 0x2ad99162a20;
LAB_2ad9915115b:
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,uVar19);
      }
      _DAT_2ad99173050 = 0;
      _DAT_2ad99173040 = 0;
      _DAT_2ad99173048 = 0.0;
    }
LAB_2ad99153021:
    (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x25);
    if ((_DAT_2ad99183b48 != _DAT_2ad99178258) || (NAN(_DAT_2ad99183b48) || NAN(_DAT_2ad99178258)))
    {
      (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x25);
      _DAT_2ad99178258 = _DAT_2ad99183b48;
    }
    dVar2 = _DAT_2ad99183cd8;
    if (_DAT_2ad99183ca0 < 2) goto LAB_2ad99153cb8;
    local_1d8 = 0;
    local_230 = 0;
    local_290 = 0;
    local_258 = 0;
    local_268 = 0;
    local_1f8 = 0;
    local_278 = 0;
    local_248 = 0;
    local_188 = 0;
    local_1d4 = 0;
    local_22c = 0;
    uStack_228 = 0;
    uStack_28c = 0;
    uStack_288 = 0;
    local_254 = 0;
    local_264 = 0;
    local_1f4 = 0;
    local_274 = 0;
    local_244 = 0;
    local_184 = 0;
    (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x25);
    dVar8 = 0.0;
    dVar7 = (dVar2 / _DAT_2ad99160790) * _DAT_2ad99183b48 + 0.0;
    iVar34 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
    if (0 < iVar34) {
      iVar34 = 0;
      dVar8 = 0.0;
      lVar18 = (longlong)_DAT_2ad99183c78;
      do {
        uVar19 = (*(code *)0x7ff63a107df0)(0x2ad95e68178,iVar34);
        cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar19);
        if (cVar12 != '\0') {
          (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
          FUN_2ad99140a40(&local_188,0x2ad99183b3c,1,0x2ad99170e88);
          if (local_184 == _DAT_2ad99183b2c) {
LAB_2ad9915331f:
            lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0xc);
            if (lVar20 == lVar18) {
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,10);
              dVar35 = _DAT_2ad99183b48;
              cVar12 = (*(code *)0x7ff63a1084b0)(0x2ad95e68178,uVar19);
              dVar9 = 0.0;
              if ((cVar12 != '\0') &&
                 (iVar16 = (*(code *)0x7ff63a108810)(0x2ad95e68178), dVar9 = 0.0, 0 < iVar16)) {
                iVar16 = 0;
                dVar9 = 0.0;
                do {
                  lVar20 = (*(code *)0x7ff63a108860)(0x2ad95e68178,iVar16);
                  if ((lVar20 != 0) &&
                     (lVar21 = (*(code *)0x7ff63a108940)(0x2ad95e68178,lVar20,4), lVar21 == 0)) {
                    (*(code *)0x7ff63a1088b0)(0x2ad95e68178,lVar20,7);
                    dVar9 = dVar9 + _DAT_2ad99183b48;
                  }
                  iVar16 = iVar16 + 1;
                  iVar15 = (*(code *)0x7ff63a108810)(0x2ad95e68178);
                } while (iVar16 < iVar15);
              }
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,9);
              dVar8 = dVar8 + dVar35 + dVar9 + _DAT_2ad99183b48;
            }
          }
          else if ((local_184 != 0) && (_DAT_2ad99183b2c != 0)) {
            uVar14 = *(uint *)(local_184 + -4);
            uVar27 = *(uint *)(_DAT_2ad99183b2c + -4);
            uVar23 = uVar27;
            if (uVar14 < uVar27) {
              uVar23 = uVar14;
            }
            iVar16 = uVar14 - uVar27;
            if (uVar23 != 0) {
              uVar31 = 1;
              do {
                uVar3 = *(ushort *)(local_184 + -2 + uVar31 * 2);
                uVar4 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar31 * 2);
                if (uVar23 <= uVar31) break;
                uVar31 = uVar31 + 1;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar16 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar16 == 0) goto LAB_2ad9915331f;
          }
        }
        iVar34 = iVar34 + 1;
        iVar16 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
      } while (iVar34 < iVar16);
    }
    if (dVar8 < dVar7) {
      (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,(ulonglong)dVar8 & _DAT_2ad99160780,2);
      FUN_2ad99140a40(&local_188,0x2ad99183b3c,1,0x2ad99170e98);
      FUN_2ad99140a40(&local_248,0x2ad99163088);
      lVar18 = local_184;
      if (local_184 != 0) {
        uVar14 = *(uint *)(local_184 + -4);
        uVar31 = (ulonglong)uVar14;
        if ((uVar31 == 0) && (local_244 != 0)) goto LAB_2ad991535a7;
        if (local_244 == 0) {
          uVar29 = 0;
          uVar27 = uVar14;
        }
        else {
          uVar29 = (ulonglong)*(uint *)(local_244 + -4);
          uVar27 = uVar14 + *(uint *)(local_244 + -4);
        }
        cVar12 = FUN_2ad99140060(&local_248);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar20 = local_244 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
                *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
                ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99153592;
            }
            do {
              *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99153592:
          *(uint *)(local_244 + -4) = uVar27;
          *(undefined2 *)(local_244 + (ulonglong)uVar27 * 2) = 0;
          goto LAB_2ad991535a7;
        }
        goto LAB_2ad991548ca;
      }
LAB_2ad991535a7:
      uVar29 = 0;
      FUN_2ad99140a40(&local_278,&local_248,0,0x2ad99170eb8);
      uVar14 = _DAT_2ad991630a8;
      uVar31 = (ulonglong)_DAT_2ad991630a8;
      if ((uVar31 != 0) || (local_274 == 0)) {
        if (local_274 != 0) {
          uVar29 = (ulonglong)*(uint *)(local_274 + -4);
        }
        uVar23 = _DAT_2ad991630a8 + (int)uVar29;
        uVar27 = 0x104;
        if ((0x103 < uVar23) &&
           ((0x7ffffffd < uVar23 || (uVar27 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar27)))) {
          uVar27 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_278,uVar27);
        if (cVar12 == '\0') goto LAB_2ad9915482a;
        if (uVar31 != 0) {
          lVar18 = local_274 + uVar29 * 2;
          if (uVar14 < 0x10) {
            uVar29 = 0;
          }
          else if (lVar18 - 0x2ad991630acU < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = *(undefined8 *)(uVar32 + 0x2ad991630b4);
              *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad991630ac + uVar32);
              ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad991536c2;
          }
          do {
            *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad991630ac + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad991536c2:
        *(uint *)(local_274 + -4) = uVar23;
        *(undefined2 *)(local_274 + (ulonglong)uVar23 * 2) = 0;
      }
      (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,dVar2,2);
      FUN_2ad99140a40(&local_1f8,0x2ad99183b3c,1,0x2ad99170ec8);
      FUN_2ad99140a40(&local_268,&local_278);
      lVar18 = local_1f4;
      if (local_1f4 != 0) {
        uVar14 = *(uint *)(local_1f4 + -4);
        uVar31 = (ulonglong)uVar14;
        if ((uVar31 == 0) && (local_264 != 0)) goto LAB_2ad99153837;
        if (local_264 == 0) {
          uVar27 = 0;
          uVar23 = uVar14;
        }
        else {
          uVar27 = *(uint *)(local_264 + -4);
          uVar23 = uVar14 + uVar27;
        }
        cVar12 = FUN_2ad99140060(&local_268);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar20 = local_264 + (ulonglong)uVar27 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
                *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
                ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99153822;
            }
            do {
              *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99153822:
          *(uint *)(local_264 + -4) = uVar23;
          *(undefined2 *)(local_264 + (ulonglong)uVar23 * 2) = 0;
          goto LAB_2ad99153837;
        }
        goto LAB_2ad991548ea;
      }
LAB_2ad99153837:
      uVar29 = 0;
      FUN_2ad99140a40(&local_258,&local_268,0,0x2ad99170ee8);
      uVar14 = _DAT_2ad991630d8;
      uVar31 = (ulonglong)_DAT_2ad991630d8;
      if ((uVar31 != 0) || (local_254 == 0)) {
        if (local_254 != 0) {
          uVar29 = (ulonglong)*(uint *)(local_254 + -4);
        }
        uVar23 = _DAT_2ad991630d8 + (int)uVar29;
        uVar27 = 0x104;
        if ((0x103 < uVar23) &&
           ((0x7ffffffd < uVar23 || (uVar27 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar27)))) {
          uVar27 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_258,uVar27);
        if (cVar12 == '\0') goto LAB_2ad9915486a;
        if (uVar31 != 0) {
          lVar18 = local_254 + uVar29 * 2;
          if (uVar14 < 0x10) {
            uVar29 = 0;
          }
          else if (lVar18 - 0x2ad991630dcU < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = *(undefined8 *)(uVar32 + 0x2ad991630e4);
              *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad991630dc + uVar32);
              ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99153962;
          }
          do {
            *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad991630dc + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99153962:
        *(uint *)(local_254 + -4) = uVar23;
        *(undefined2 *)(local_254 + (ulonglong)uVar23 * 2) = 0;
      }
      (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,(ulonglong)dVar7 & _DAT_2ad99160780,2);
      FUN_2ad99140a40(&local_290,0x2ad99183b3c,1,0x2ad99170ef8);
      FUN_2ad99140a40(&local_230,&local_258);
      lVar18 = CONCAT44(uStack_288,uStack_28c);
      if (lVar18 != 0) {
        uVar14 = *(uint *)(lVar18 + -4);
        uVar31 = (ulonglong)uVar14;
        lVar20 = CONCAT44(uStack_228,local_22c);
        if ((uVar31 == 0) && (lVar20 != 0)) goto LAB_2ad99153add;
        if (lVar20 == 0) {
          uVar29 = 0;
          uVar27 = uVar14;
        }
        else {
          uVar29 = (ulonglong)*(uint *)(lVar20 + -4);
          uVar27 = uVar14 + *(uint *)(lVar20 + -4);
        }
        cVar12 = FUN_2ad99140060(&local_230);
        if (cVar12 != '\0') {
          lVar20 = CONCAT44(uStack_228,local_22c);
          if (uVar31 != 0) {
            lVar21 = lVar20 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar21 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
                *(undefined8 *)(lVar21 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
                ((undefined8 *)(lVar21 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99153ad2;
            }
            do {
              *(undefined2 *)(lVar21 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99153ad2:
          *(uint *)(lVar20 + -4) = uVar27;
          *(undefined2 *)(lVar20 + (ulonglong)uVar27 * 2) = 0;
          goto LAB_2ad99153add;
        }
        goto LAB_2ad9915490a;
      }
LAB_2ad99153add:
      uVar14 = 0;
      FUN_2ad99140a40(&local_1d8,&local_230,0,0x2ad99170f18);
      uVar27 = _DAT_2ad99163118;
      uVar31 = (ulonglong)_DAT_2ad99163118;
      if ((uVar31 != 0) || (local_1d4 == 0)) {
        if (local_1d4 != 0) {
          uVar14 = *(uint *)(local_1d4 + -4);
        }
        uVar26 = _DAT_2ad99163118 + uVar14;
        uVar23 = 0x104;
        if ((0x103 < uVar26) &&
           ((0x7ffffffd < uVar26 || (uVar23 = (uVar26 >> 2) + uVar26, 0x7ffffffd < uVar23)))) {
          uVar23 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_1d8,uVar23);
        if (cVar12 == '\0') goto LAB_2ad991548aa;
        if (uVar31 != 0) {
          lVar18 = local_1d4 + (ulonglong)uVar14 * 2;
          if (uVar27 < 0x10) {
            uVar29 = 0;
          }
          else if (lVar18 - 0x2ad9916311cU < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar27 & 0xfffffff8);
            do {
              uVar19 = *(undefined8 *)(uVar32 + 0x2ad99163124);
              *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad9916311c + uVar32);
              ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99153c12;
          }
          do {
            *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad9916311c + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99153c12:
        *(uint *)(local_1d4 + -4) = uVar26;
        *(undefined2 *)(local_1d4 + (ulonglong)uVar26 * 2) = 0;
      }
      (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_1d8);
      FUN_2ad9915c1f0(0);
      FUN_2ad9915c1f0(1);
    }
    FUN_2ad99140000(&local_188);
    FUN_2ad99140000(&local_248);
    FUN_2ad99140000(&local_278);
    FUN_2ad99140000(&local_1f8);
    FUN_2ad99140000(&local_268);
    FUN_2ad99140000(&local_258);
    FUN_2ad99140000(&local_290);
    FUN_2ad99140000(&local_230);
    FUN_2ad99140000(&local_1d8);
LAB_2ad99153cb8:
    FUN_2ad99140000(&local_1e8);
    FUN_2ad99140000(&local_170);
    FUN_2ad99140000(&local_1a0);
    FUN_2ad99140000(&local_158);
    FUN_2ad99140000(&local_148);
    FUN_2ad99140000(&local_138);
    return;
  }
  uVar37 = (undefined4)_DAT_2ad99183c50;
  uVar38 = (undefined4)((ulonglong)_DAT_2ad99183c50 >> 0x20);
  iVar15 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
  if (iVar15 + -1 < 0) {
    uVar39 = 0;
    uVar40 = 0;
    uVar41 = 0;
    uVar42 = 0;
    local_238 = 0;
    local_280 = 0;
  }
  else {
    uVar39 = 0;
    uVar40 = 0;
    uVar41 = 0;
    uVar42 = 0;
    lVar18 = (longlong)_DAT_2ad99183c78;
    local_238 = 0;
    local_280 = 0;
    iVar15 = iVar15 + -1;
    do {
      uVar19 = (*(code *)0x7ff63a107df0)(0x2ad95e68178,iVar15);
      cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar19);
      if (cVar12 != '\0') {
        (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
        FUN_2ad99140a40(&local_1e8,0x2ad99183b3c,1,0x2ad99170b48);
        if (local_1e4 == _DAT_2ad99183b2c) {
LAB_2ad9915197f:
          lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0xc);
          if (lVar20 == lVar18) {
            lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2);
            if ((lVar20 == 0) || (lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2), lVar20 == 1))
            {
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
              local_280 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2);
              bVar5 = (double)CONCAT44(uVar40,uVar39) != 0.0;
              if (((!bVar5) && (!NAN((double)CONCAT44(uVar40,uVar39)))) ||
                 ((0.0 <= (double)CONCAT44(uVar40,uVar39) && bVar5 &&
                  ((*(code *)0x7ff63a107f70)(0x2ad95e68178,4),
                  (double)CONCAT44(uVar40,uVar39) <= _DAT_2ad99183b48 &&
                  _DAT_2ad99183b48 != (double)CONCAT44(uVar40,uVar39))))) {
                (*(code *)0x7ff63a107f70)(0x2ad95e68178,4);
                uVar39 = SUB84(_DAT_2ad99183b48,0);
                uVar40 = (undefined4)((ulonglong)_DAT_2ad99183b48 >> 0x20);
              }
              bVar5 = (double)CONCAT44(uVar42,uVar41) != 0.0;
              if (((!bVar5) && (!NAN((double)CONCAT44(uVar42,uVar41)))) ||
                 ((0.0 <= (double)CONCAT44(uVar42,uVar41) && bVar5 &&
                  ((*(code *)0x7ff63a107f70)(0x2ad95e68178,4),
                  _DAT_2ad99183b48 <= (double)CONCAT44(uVar42,uVar41) &&
                  (double)CONCAT44(uVar42,uVar41) != _DAT_2ad99183b48)))) {
                (*(code *)0x7ff63a107f70)(0x2ad95e68178,4);
                uVar41 = SUB84(_DAT_2ad99183b48,0);
                uVar42 = (undefined4)((ulonglong)_DAT_2ad99183b48 >> 0x20);
              }
              local_238 = (ulonglong)((int)local_238 + 1);
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
              if ((double)CONCAT44(uVar38,uVar37) <= _DAT_2ad99183b48 &&
                  _DAT_2ad99183b48 != (double)CONCAT44(uVar38,uVar37)) {
                (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
                uVar37 = SUB84(_DAT_2ad99183b48,0);
                uVar38 = (undefined4)((ulonglong)_DAT_2ad99183b48 >> 0x20);
              }
            }
            if (1 < iVar34 + iVar16) {
              lVar20 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178418);
              if (lVar20 == 0) goto LAB_2ad991545ca;
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,7);
              if ((_DAT_2ad99183b48 == 0.0) && (!NAN(_DAT_2ad99183b48))) {
                lVar20 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178418);
                if (lVar20 == 0) goto LAB_2ad991546ea;
                (*(code *)0x7ff63a107f70)(0x2ad95e68178,6);
                if ((_DAT_2ad99183b48 == 0.0) && (!NAN(_DAT_2ad99183b48))) goto LAB_2ad991518a0;
              }
              _DAT_2ad99183b10 = 0;
              _DAT_2ad99183b80 = 0;
              DAT_2ad99183b88 = 0;
              lVar20 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178418);
              if (lVar20 == 0) goto LAB_2ad9915460a;
              uVar19 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0x11);
              lVar20 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
              if (lVar20 == 0) goto LAB_2ad991545ea;
              local_1d8 = 0;
              local_1d4 = 0;
              if (_DAT_2ad99183b14 == 0) {
                cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar19);
                if (cVar12 == '\0') goto LAB_2ad99151c39;
                local_178 = lVar20 + 0x20;
                local_190 = lVar20 + 0x34;
                *(undefined4 *)(lVar20 + 0x30) = 0;
                *(undefined8 *)(lVar20 + 0x28) = 0;
                *(undefined8 *)(lVar20 + 0x20) = 0;
                FUN_2ad99140000();
                *(undefined4 *)(lVar20 + 0x80) = 0;
                *(undefined8 *)(lVar20 + 0x78) = 0;
                *(undefined8 *)(lVar20 + 0x70) = 0;
                *(undefined8 *)(lVar20 + 0x68) = 0;
                *(undefined8 *)(lVar20 + 0x60) = 0;
                *(undefined8 *)(lVar20 + 0x58) = 0;
                *(undefined8 *)(lVar20 + 0x50) = 0;
                *(undefined8 *)(lVar20 + 0x48) = 0;
                *(undefined8 *)(lVar20 + 0x40) = 0;
                FUN_2ad99140000(lVar20 + 0x84);
                local_160 = lVar20 + 0x110;
                (*(code *)0x7ff63a3fad20)(lVar20 + 0x90,0,0xb4);
                FUN_2ad99140000(lVar20 + 0x144);
                (*(code *)0x7ff63a3fad20)(lVar20 + 0x150,0,0xb8);
                FUN_2ad99140000(lVar20 + 0x208);
                *(undefined8 *)(lVar20 + 0x28c) = 0;
                *(undefined8 *)(lVar20 + 0x284) = 0;
                *(undefined8 *)(lVar20 + 0x27c) = 0;
                *(undefined8 *)(lVar20 + 0x274) = 0;
                *(undefined8 *)(lVar20 + 0x26c) = 0;
                *(undefined8 *)(lVar20 + 0x264) = 0;
                *(undefined8 *)(lVar20 + 0x25c) = 0;
                *(undefined8 *)(lVar20 + 0x254) = 0;
                *(undefined8 *)(lVar20 + 0x24c) = 0;
                *(undefined8 *)(lVar20 + 0x244) = 0;
                *(undefined8 *)(lVar20 + 0x23c) = 0;
                *(undefined8 *)(lVar20 + 0x234) = 0;
                *(undefined8 *)(lVar20 + 0x22c) = 0;
                *(undefined8 *)(lVar20 + 0x224) = 0;
                *(undefined8 *)(lVar20 + 0x21c) = 0;
                *(undefined8 *)(lVar20 + 0x214) = 0;
                *(undefined4 *)(lVar20 + 0x20) = 6;
                *(undefined8 *)(lVar20 + 0x90) = uVar19;
                (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
                FUN_2ad99140a40(&local_1d8,0x2ad99183b3c,1,0x2ad9916ff98);
                FUN_2ad99140a40(local_190,&local_1d8,0,0x2ad9916ffa8);
                *(undefined8 *)(lVar20 + 0x24) = *(undefined8 *)(lVar20 + 0x295);
                *(undefined8 *)(lVar20 + 0x58) = 0;
                *(undefined8 *)(lVar20 + 0x60) = 0;
                cVar12 = FUN_2ad99140f70(lVar20,local_178,local_160);
                FUN_2ad99140000(&local_1d8);
                puVar22 = (undefined4 *)0x2ad99162cb8;
                if (cVar12 == '\0') goto LAB_2ad99151c57;
              }
              else {
                (*(code *)0x7ff63a0e49f0)
                          (0x2ad95e68178,0xd,2,0x590008,0x2ad99162960,0x590008,0x2ad991618e0);
                *(undefined4 *)(lVar20 + 0x110) = 0x272b;
LAB_2ad99151c39:
                FUN_2ad99140000(&local_1d8);
LAB_2ad99151c57:
                (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,(longlong)_DAT_2ad99183b10,0,0x20);
                FUN_2ad99140a40(&local_170,0x2ad99183b3c,1,0x2ad99170b58);
                puVar22 = &local_1a0;
                FUN_2ad99140a40(puVar22,0x2ad99162c58,0);
                lVar20 = local_16c;
                if (local_16c != 0) {
                  uVar14 = *(uint *)(local_16c + -4);
                  uVar31 = (ulonglong)uVar14;
                  if ((uVar31 != 0) || (puVar22 = &local_1a0, local_19c == 0)) {
                    if (local_19c == 0) {
                      uVar27 = 0;
                      uVar23 = uVar14;
                    }
                    else {
                      uVar27 = *(uint *)(local_19c + -4);
                      uVar23 = uVar14 + uVar27;
                    }
                    cVar12 = FUN_2ad99140060(&local_1a0);
                    if (cVar12 == '\0') goto LAB_2ad9915478a;
                    if (uVar31 != 0) {
                      lVar21 = local_19c + (ulonglong)uVar27 * 2;
                      if (uVar14 < 8) {
                        uVar29 = 0;
                      }
                      else if ((ulonglong)(lVar21 - lVar20) < 0x20) {
                        uVar29 = 0;
                      }
                      else {
                        uVar32 = 0;
                        uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
                        do {
                          uVar19 = ((undefined8 *)(lVar20 + uVar32))[1];
                          *(undefined8 *)(lVar21 + uVar32) = *(undefined8 *)(lVar20 + uVar32);
                          ((undefined8 *)(lVar21 + uVar32))[1] = uVar19;
                          uVar32 = uVar32 + 0x10;
                        } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
                        if (uVar29 == uVar31) goto LAB_2ad9915183b;
                      }
                      do {
                        *(undefined2 *)(lVar21 + uVar29 * 2) = *(undefined2 *)(lVar20 + uVar29 * 2);
                        uVar29 = uVar29 + 1;
                      } while (uVar31 != uVar29);
                    }
LAB_2ad9915183b:
                    *(uint *)(local_19c + -4) = uVar23;
                    *(undefined2 *)(local_19c + (ulonglong)uVar23 * 2) = 0;
                    puVar22 = &local_1a0;
                  }
                }
              }
              (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,puVar22);
            }
          }
        }
        else if ((local_1e4 != 0) && (_DAT_2ad99183b2c != 0)) {
          uVar14 = *(uint *)(local_1e4 + -4);
          uVar27 = *(uint *)(_DAT_2ad99183b2c + -4);
          uVar23 = uVar27;
          if (uVar14 < uVar27) {
            uVar23 = uVar14;
          }
          iVar17 = uVar14 - uVar27;
          if (uVar23 != 0) {
            uVar31 = 1;
            do {
              uVar3 = *(ushort *)(local_1e4 + -2 + uVar31 * 2);
              uVar4 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar31 * 2);
              if (uVar23 <= uVar31) break;
              uVar31 = uVar31 + 1;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar17 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar17 == 0) goto LAB_2ad9915197f;
        }
      }
LAB_2ad991518a0:
      bVar5 = 0 < iVar15;
      iVar15 = iVar15 + -1;
    } while (bVar5);
  }
  local_1d8 = 0;
  local_230 = 0;
  local_290 = 0;
  local_258 = 0;
  local_268 = 0;
  local_1f8 = 0;
  local_278 = 0;
  local_248 = 0;
  local_1d4 = 0;
  local_22c = 0;
  uStack_228 = 0;
  uStack_28c = 0;
  uStack_288 = 0;
  local_254 = 0;
  local_264 = 0;
  local_1f4 = 0;
  local_274 = 0;
  local_244 = 0;
  if ((_DAT_2ad99183ca0 == 1) || (iVar34 = (int)local_238, iVar34 < 1)) goto LAB_2ad99152fd2;
  if (_DAT_2ad99183ca0 <= iVar34) {
LAB_2ad99152546:
    iVar34 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
    if (iVar34 < 1) {
      dVar2 = 0.0;
    }
    else {
      iVar34 = 0;
      dVar2 = 0.0;
      lVar18 = (longlong)_DAT_2ad99183c78;
      do {
        uVar19 = (*(code *)0x7ff63a107df0)(0x2ad95e68178,iVar34);
        cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar19);
        if (cVar12 != '\0') {
          (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
          FUN_2ad99140a40(&local_248,0x2ad99183b3c,1,0x2ad99170bb8);
          if (local_244 == _DAT_2ad99183b2c) {
LAB_2ad991526ef:
            lVar20 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0xc);
            if (lVar20 == lVar18) {
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,10);
              dVar8 = _DAT_2ad99183b48;
              cVar12 = (*(code *)0x7ff63a1084b0)(0x2ad95e68178,uVar19);
              dVar7 = 0.0;
              if ((cVar12 != '\0') &&
                 (iVar16 = (*(code *)0x7ff63a108810)(0x2ad95e68178), dVar7 = 0.0, 0 < iVar16)) {
                iVar16 = 0;
                dVar7 = 0.0;
                do {
                  lVar20 = (*(code *)0x7ff63a108860)(0x2ad95e68178,iVar16);
                  if ((lVar20 != 0) &&
                     (lVar21 = (*(code *)0x7ff63a108940)(0x2ad95e68178,lVar20,4), lVar21 == 0)) {
                    (*(code *)0x7ff63a1088b0)(0x2ad95e68178,lVar20,7);
                    dVar7 = dVar7 + _DAT_2ad99183b48;
                  }
                  iVar16 = iVar16 + 1;
                  iVar15 = (*(code *)0x7ff63a108810)(0x2ad95e68178);
                } while (iVar16 < iVar15);
              }
              (*(code *)0x7ff63a107f70)(0x2ad95e68178,9);
              dVar2 = dVar2 + dVar8 + dVar7 + _DAT_2ad99183b48;
            }
          }
          else if ((local_244 != 0) && (_DAT_2ad99183b2c != 0)) {
            uVar14 = *(uint *)(local_244 + -4);
            uVar27 = *(uint *)(_DAT_2ad99183b2c + -4);
            uVar23 = uVar27;
            if (uVar14 < uVar27) {
              uVar23 = uVar14;
            }
            iVar16 = uVar14 - uVar27;
            if (uVar23 != 0) {
              uVar31 = 1;
              do {
                uVar3 = *(ushort *)(local_244 + -2 + uVar31 * 2);
                uVar4 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar31 * 2);
                if (uVar23 <= uVar31) break;
                uVar31 = uVar31 + 1;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar16 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar16 == 0) goto LAB_2ad991526ef;
          }
        }
        iVar34 = iVar34 + 1;
        iVar16 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
      } while (iVar34 < iVar16);
    }
    dVar7 = _DAT_2ad99183cb0;
    if (_DAT_2ad99183cb0 <= dVar2) {
      (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,dVar2,2);
      FUN_2ad99140a40(&local_248,0x2ad99183b3c,1,0x2ad99170bc8);
      FUN_2ad99140a40(&local_278,0x2ad99162d60,0);
      lVar18 = local_244;
      if (local_244 != 0) {
        uVar14 = *(uint *)(local_244 + -4);
        uVar31 = (ulonglong)uVar14;
        if ((uVar31 == 0) && (local_274 != 0)) goto LAB_2ad99152a87;
        if (local_274 == 0) {
          uVar29 = 0;
        }
        else {
          uVar29 = (ulonglong)*(uint *)(local_274 + -4);
        }
        uVar27 = uVar14 + (int)uVar29;
        cVar12 = FUN_2ad99140060(&local_278);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar20 = local_274 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
                *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
                ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99152a72;
            }
            do {
              *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99152a72:
          *(uint *)(local_274 + -4) = uVar27;
          *(undefined2 *)(local_274 + (ulonglong)uVar27 * 2) = 0;
          goto LAB_2ad99152a87;
        }
        goto LAB_2ad9915496a;
      }
LAB_2ad99152a87:
      (*(code *)0x7ff63a0c7410)(0x2ad95e68178,0x24);
      FUN_2ad99140a40(&local_1f8,0x2ad99183b3c,1,0x2ad99170be8);
      FUN_2ad99140a40(&local_268,&local_278);
      lVar18 = local_1f4;
      if (local_1f4 != 0) {
        uVar14 = *(uint *)(local_1f4 + -4);
        uVar31 = (ulonglong)uVar14;
        if ((uVar31 == 0) && (local_264 != 0)) goto LAB_2ad99152bd7;
        if (local_264 == 0) {
          uVar29 = 0;
        }
        else {
          uVar29 = (ulonglong)*(uint *)(local_264 + -4);
        }
        uVar27 = uVar14 + (int)uVar29;
        cVar12 = FUN_2ad99140060(&local_268);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar20 = local_264 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
                *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
                ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99152bc2;
            }
            do {
              *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99152bc2:
          *(uint *)(local_264 + -4) = uVar27;
          *(undefined2 *)(local_264 + (ulonglong)uVar27 * 2) = 0;
          goto LAB_2ad99152bd7;
        }
        goto LAB_2ad9915498a;
      }
LAB_2ad99152bd7:
      uVar29 = 0;
      FUN_2ad99140a40(&local_258,&local_268,0,0x2ad99170c08);
      uVar14 = _DAT_2ad99162d78;
      uVar31 = (ulonglong)_DAT_2ad99162d78;
      if ((uVar31 != 0) || (local_254 == 0)) {
        if (local_254 != 0) {
          uVar29 = (ulonglong)*(uint *)(local_254 + -4);
        }
        uVar23 = _DAT_2ad99162d78 + (int)uVar29;
        uVar27 = 0x104;
        if ((0x103 < uVar23) &&
           ((0x7ffffffd < uVar23 || (uVar27 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar27)))) {
          uVar27 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_258,uVar27);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar18 = local_254 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if (lVar18 - 0x2ad99162d7cU < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = *(undefined8 *)(uVar32 + 0x2ad99162d84);
                *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad99162d7c + uVar32);
                ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99152d02;
            }
            do {
              *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad99162d7c + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99152d02:
          *(uint *)(local_254 + -4) = uVar23;
          *(undefined2 *)(local_254 + (ulonglong)uVar23 * 2) = 0;
          goto LAB_2ad99152d0d;
        }
        goto LAB_2ad9915492a;
      }
LAB_2ad99152d0d:
      (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,dVar7,2);
      FUN_2ad99140a40(&local_290,0x2ad99183b3c,1,0x2ad99170c18);
      FUN_2ad99140a40(&local_230,&local_258);
      lVar18 = CONCAT44(uStack_288,uStack_28c);
      if (lVar18 == 0) {
LAB_2ad99152e5d:
        uVar14 = 0;
        FUN_2ad99140a40(&local_1d8,&local_230,0,0x2ad99170c38);
        uVar27 = _DAT_2ad99162d98;
        uVar31 = (ulonglong)_DAT_2ad99162d98;
        if ((uVar31 == 0) && (local_1d4 != 0)) {
LAB_2ad99152f8d:
          (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_1d8);
          FUN_2ad9915c1f0(local_280);
          goto LAB_2ad99152fd2;
        }
        if (local_1d4 != 0) {
          uVar14 = *(uint *)(local_1d4 + -4);
        }
        uVar26 = _DAT_2ad99162d98 + uVar14;
        uVar23 = 0x104;
        if ((0x103 < uVar26) &&
           ((0x7ffffffd < uVar26 || (uVar23 = (uVar26 >> 2) + uVar26, 0x7ffffffd < uVar23)))) {
          uVar23 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_1d8,uVar23);
        if (cVar12 != '\0') {
          if (uVar31 != 0) {
            lVar18 = local_1d4 + (ulonglong)uVar14 * 2;
            if (uVar27 < 0x10) {
              uVar29 = 0;
            }
            else if (lVar18 - 0x2ad99162d9cU < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar32 = 0;
              uVar29 = (ulonglong)(uVar27 & 0xfffffff8);
              do {
                uVar19 = *(undefined8 *)(uVar32 + 0x2ad99162da4);
                *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad99162d9c + uVar32);
                ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
                uVar32 = uVar32 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
              if (uVar29 == uVar31) goto LAB_2ad99152f82;
            }
            do {
              *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad99162d9c + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
LAB_2ad99152f82:
          *(uint *)(local_1d4 + -4) = uVar26;
          *(undefined2 *)(local_1d4 + (ulonglong)uVar26 * 2) = 0;
          goto LAB_2ad99152f8d;
        }
        goto LAB_2ad9915494a;
      }
      uVar14 = *(uint *)(lVar18 + -4);
      uVar31 = (ulonglong)uVar14;
      lVar20 = CONCAT44(uStack_228,local_22c);
      if ((uVar31 == 0) && (lVar20 != 0)) goto LAB_2ad99152e5d;
      if (lVar20 == 0) {
        uVar29 = 0;
      }
      else {
        uVar29 = (ulonglong)*(uint *)(lVar20 + -4);
      }
      uVar27 = uVar14 + (int)uVar29;
      cVar12 = FUN_2ad99140060(&local_230);
      if (cVar12 != '\0') {
        lVar20 = CONCAT44(uStack_228,local_22c);
        if (uVar31 != 0) {
          lVar21 = lVar20 + uVar29 * 2;
          if (uVar14 < 0x10) {
            uVar29 = 0;
          }
          else if ((ulonglong)(lVar21 - lVar18) < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
              *(undefined8 *)(lVar21 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
              ((undefined8 *)(lVar21 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99152e52;
          }
          do {
            *(undefined2 *)(lVar21 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99152e52:
        *(uint *)(lVar20 + -4) = uVar27;
        *(undefined2 *)(lVar20 + (ulonglong)uVar27 * 2) = 0;
        goto LAB_2ad99152e5d;
      }
      goto LAB_2ad991549aa;
    }
    if (((_DAT_2ad99183cb8 == 0.0) && (!NAN(_DAT_2ad99183cb8))) ||
       ((_DAT_2ad99183cc0 == 0.0 && (!NAN(_DAT_2ad99183cc0))))) {
LAB_2ad99152fd2:
      FUN_2ad99140000(&local_248);
      FUN_2ad99140000(&local_278);
      FUN_2ad99140000(&local_1f8);
      FUN_2ad99140000(&local_268);
      FUN_2ad99140000(&local_258);
      FUN_2ad99140000(&local_290);
      FUN_2ad99140000(&local_230);
      FUN_2ad99140000(&local_1d8);
      goto LAB_2ad99153021;
    }
    if ((_DAT_2ad99183cb8 <= dVar2) && (_DAT_2ad99173058 < dVar2)) {
      _DAT_2ad99173058 = dVar2;
    }
    if (((_DAT_2ad99173058 == 0.0) && (!NAN(_DAT_2ad99173058))) ||
       (_DAT_2ad99173058 - _DAT_2ad99183cc0 < dVar2)) goto LAB_2ad99152fd2;
    (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,dVar2,2);
    FUN_2ad99140a40(&local_248,0x2ad99183b3c,1,0x2ad99170c48);
    FUN_2ad99140a40(&local_278,0x2ad99162e10,0);
    lVar18 = local_244;
    if (local_244 != 0) {
      uVar14 = *(uint *)(local_244 + -4);
      uVar31 = (ulonglong)uVar14;
      if ((uVar31 == 0) && (local_274 != 0)) goto LAB_2ad99153e1b;
      if (local_274 == 0) {
        uVar27 = 0;
      }
      else {
        uVar27 = *(uint *)(local_274 + -4);
      }
      cVar12 = FUN_2ad99140060(&local_278);
      if (cVar12 != '\0') {
        if (uVar31 != 0) {
          lVar20 = local_274 + (ulonglong)uVar27 * 2;
          if (uVar14 < 0x10) {
            uVar29 = 0;
          }
          else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
              *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
              ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99153dfc;
          }
          do {
            *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99153dfc:
        *(uint *)(local_274 + -4) = uVar14 + uVar27;
        *(undefined2 *)(local_274 + (ulonglong)(uVar14 + uVar27) * 2) = 0;
        goto LAB_2ad99153e1b;
      }
      goto LAB_2ad99154a0a;
    }
LAB_2ad99153e1b:
    (*(code *)0x7ff63a0c7410)(0x2ad95e68178,0x24);
    FUN_2ad99140a40(&local_1f8,0x2ad99183b3c,1,0x2ad99170c68);
    FUN_2ad99140a40(&local_268,&local_278,0);
    lVar18 = local_1f4;
    if (local_1f4 != 0) {
      uVar14 = *(uint *)(local_1f4 + -4);
      uVar31 = (ulonglong)uVar14;
      if ((uVar31 == 0) && (local_264 != 0)) goto LAB_2ad99153f73;
      if (local_264 == 0) {
        uVar27 = 0;
      }
      else {
        uVar27 = *(uint *)(local_264 + -4);
      }
      cVar12 = FUN_2ad99140060(&local_268);
      if (cVar12 != '\0') {
        if (uVar31 != 0) {
          lVar20 = local_264 + (ulonglong)uVar27 * 2;
          if (uVar14 < 0x10) {
            uVar29 = 0;
          }
          else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
              *(undefined8 *)(lVar20 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
              ((undefined8 *)(lVar20 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99153f54;
          }
          do {
            *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99153f54:
        *(uint *)(local_264 + -4) = uVar14 + uVar27;
        *(undefined2 *)(local_264 + (ulonglong)(uVar14 + uVar27) * 2) = 0;
        goto LAB_2ad99153f73;
      }
      goto LAB_2ad99154a2a;
    }
LAB_2ad99153f73:
    uVar29 = 0;
    FUN_2ad99140a40(&local_258,&local_268,0);
    uVar14 = _DAT_2ad99162d78;
    uVar31 = (ulonglong)_DAT_2ad99162d78;
    if ((uVar31 != 0) || (local_254 == 0)) {
      if (local_254 != 0) {
        uVar29 = (ulonglong)*(uint *)(local_254 + -4);
      }
      uVar27 = _DAT_2ad99162d78 + (int)uVar29;
      cVar12 = FUN_2ad99140060(&local_258);
      if (cVar12 != '\0') {
        if (uVar31 != 0) {
          lVar18 = local_254 + uVar29 * 2;
          if ((uVar14 < 0x10) || (lVar18 - 0x2ad99162d7cU < 0x20)) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar19 = *(undefined8 *)(uVar32 + 0x2ad99162d84);
              *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad99162d7c + uVar32);
              ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99154062;
          }
          do {
            *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad99162d7c + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
LAB_2ad99154062:
        *(uint *)(local_254 + -4) = uVar27;
        *(undefined2 *)(local_254 + (ulonglong)uVar27 * 2) = 0;
        goto LAB_2ad99154077;
      }
      goto LAB_2ad991549ca;
    }
LAB_2ad99154077:
    (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,_DAT_2ad99173058,2);
    FUN_2ad99140a40(&local_290,0x2ad99183b3c,1,0x2ad99170c98);
    FUN_2ad99140a40(&local_230,&local_258,0);
    lVar18 = CONCAT44(uStack_288,uStack_28c);
    if (lVar18 == 0) {
LAB_2ad991541fd:
      uVar14 = 0;
      FUN_2ad99140a40(&local_1d8,&local_230,0);
      uVar27 = _DAT_2ad99162d98;
      uVar31 = (ulonglong)_DAT_2ad99162d98;
      if ((uVar31 == 0) && (local_1d4 != 0)) goto LAB_2ad99152f8d;
      if (local_1d4 != 0) {
        uVar14 = *(uint *)(local_1d4 + -4);
      }
      uVar26 = _DAT_2ad99162d98 + uVar14;
      cVar12 = FUN_2ad99140060(&local_1d8);
      if (cVar12 != '\0') {
        if (uVar31 != 0) {
          lVar18 = local_1d4 + (ulonglong)uVar14 * 2;
          if ((uVar27 < 0x10) || (lVar18 - 0x2ad99162d9cU < 0x20)) {
            uVar29 = 0;
          }
          else {
            uVar32 = 0;
            uVar29 = (ulonglong)(uVar27 & 0xfffffff8);
            do {
              uVar19 = *(undefined8 *)(uVar32 + 0x2ad99162da4);
              *(undefined8 *)(lVar18 + uVar32) = *(undefined8 *)(&DAT_2ad99162d9c + uVar32);
              ((undefined8 *)(lVar18 + uVar32))[1] = uVar19;
              uVar32 = uVar32 + 0x10;
            } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
            if (uVar29 == uVar31) goto LAB_2ad99152f82;
          }
          do {
            *(undefined2 *)(lVar18 + uVar29 * 2) = *(undefined2 *)(&DAT_2ad99162d9c + uVar29 * 2);
            uVar29 = uVar29 + 1;
          } while (uVar31 != uVar29);
        }
        goto LAB_2ad99152f82;
      }
      goto LAB_2ad991549ea;
    }
    uVar14 = *(uint *)(lVar18 + -4);
    uVar31 = (ulonglong)uVar14;
    lVar20 = CONCAT44(uStack_228,local_22c);
    if ((uVar31 == 0) && (lVar20 != 0)) goto LAB_2ad991541fd;
    if (lVar20 == 0) {
      uVar29 = 0;
    }
    else {
      uVar29 = (ulonglong)*(uint *)(lVar20 + -4);
    }
    uVar27 = uVar14 + (int)uVar29;
    cVar12 = FUN_2ad99140060(&local_230);
    if (cVar12 != '\0') {
      lVar20 = CONCAT44(uStack_228,local_22c);
      if (uVar31 != 0) {
        lVar21 = lVar20 + uVar29 * 2;
        if (uVar14 < 0x10) {
          uVar29 = 0;
        }
        else if ((ulonglong)(lVar21 - lVar18) < 0x20) {
          uVar29 = 0;
        }
        else {
          uVar32 = 0;
          uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
          do {
            uVar19 = ((undefined8 *)(lVar18 + uVar32))[1];
            *(undefined8 *)(lVar21 + uVar32) = *(undefined8 *)(lVar18 + uVar32);
            ((undefined8 *)(lVar21 + uVar32))[1] = uVar19;
            uVar32 = uVar32 + 0x10;
          } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar32);
          if (uVar29 == uVar31) goto LAB_2ad991541f2;
        }
        do {
          *(undefined2 *)(lVar21 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
          uVar29 = uVar29 + 1;
        } while (uVar31 != uVar29);
      }
LAB_2ad991541f2:
      *(uint *)(lVar20 + -4) = uVar27;
      *(undefined2 *)(lVar20 + (ulonglong)uVar27 * 2) = 0;
      goto LAB_2ad991541fd;
    }
    goto LAB_2ad99154a4a;
  }
  if ((int)local_280 == 1) {
    if ((double)CONCAT44(uVar40,uVar39) + _DAT_2ad99183ca8 * _DAT_2ad99178250 <= _DAT_2ad99178438) {
      (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,iVar34 + 1,0,0x20);
      FUN_2ad99140a40(&local_248,0x2ad99183b3c,1,0x2ad99170b98);
      FUN_2ad99140a40(&local_278,0x2ad99162d18,0);
      lVar18 = local_244;
      if (local_244 != 0) {
        uVar14 = *(uint *)(local_244 + -4);
        uVar31 = (ulonglong)uVar14;
        if ((uVar31 != 0) || (local_274 == 0)) {
          if (local_274 == 0) {
            uVar29 = 0;
          }
          else {
            uVar29 = (ulonglong)*(uint *)(local_274 + -4);
          }
          uVar32 = (ulonglong)(uVar14 + (int)uVar29);
          cVar12 = FUN_2ad99140060(&local_278);
          if (cVar12 == '\0') goto LAB_2ad99154a8a;
          if (uVar31 != 0) {
            lVar20 = local_274 + uVar29 * 2;
            if (uVar14 < 0x10) {
              uVar29 = 0;
            }
            else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
              uVar29 = 0;
            }
            else {
              uVar24 = 0;
              uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
              do {
                uVar19 = ((undefined8 *)(lVar18 + uVar24))[1];
                *(undefined8 *)(lVar20 + uVar24) = *(undefined8 *)(lVar18 + uVar24);
                ((undefined8 *)(lVar20 + uVar24))[1] = uVar19;
                uVar24 = uVar24 + 0x10;
              } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar24);
              if (uVar29 == uVar31) goto LAB_2ad99152513;
            }
            do {
              *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
              uVar29 = uVar29 + 1;
            } while (uVar31 != uVar29);
          }
          goto LAB_2ad99152513;
        }
      }
      goto LAB_2ad9915251e;
    }
    goto LAB_2ad99152546;
  }
  if (((int)local_280 != 0) ||
     ((double)CONCAT44(uVar42,uVar41) - _DAT_2ad99183ca8 * _DAT_2ad99178250 < _DAT_2ad99178440))
  goto LAB_2ad99152546;
  (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,iVar34 + 1,0,0x20);
  FUN_2ad99140a40(&local_248,0x2ad99183b3c,1,0x2ad99170b78);
  FUN_2ad99140a40(&local_278,0x2ad99162ce8,0);
  lVar18 = local_244;
  if (local_244 == 0) {
LAB_2ad9915251e:
    FUN_2ad99159f70(local_280,(double)CONCAT44(uVar38,uVar37) + _DAT_2ad99183c58,&local_278);
    goto LAB_2ad99152546;
  }
  uVar14 = *(uint *)(local_244 + -4);
  uVar31 = (ulonglong)uVar14;
  if ((uVar31 == 0) && (local_274 != 0)) goto LAB_2ad9915251e;
  if (local_274 == 0) {
    uVar29 = 0;
  }
  else {
    uVar29 = (ulonglong)*(uint *)(local_274 + -4);
  }
  uVar32 = (ulonglong)(uVar14 + (int)uVar29);
  cVar12 = FUN_2ad99140060(&local_278);
  if (cVar12 != '\0') {
    if (uVar31 != 0) {
      lVar20 = local_274 + uVar29 * 2;
      if (uVar14 < 0x10) {
        uVar29 = 0;
      }
      else if ((ulonglong)(lVar20 - lVar18) < 0x20) {
        uVar29 = 0;
      }
      else {
        uVar24 = 0;
        uVar29 = (ulonglong)(uVar14 & 0xfffffff8);
        do {
          uVar19 = ((undefined8 *)(lVar18 + uVar24))[1];
          *(undefined8 *)(lVar20 + uVar24) = *(undefined8 *)(lVar18 + uVar24);
          ((undefined8 *)(lVar20 + uVar24))[1] = uVar19;
          uVar24 = uVar24 + 0x10;
        } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar24);
        if (uVar29 == uVar31) goto LAB_2ad99152513;
      }
      do {
        *(undefined2 *)(lVar20 + uVar29 * 2) = *(undefined2 *)(lVar18 + uVar29 * 2);
        uVar29 = uVar29 + 1;
      } while (uVar31 != uVar29);
    }
LAB_2ad99152513:
    *(int *)(local_274 + -4) = (int)uVar32;
    *(undefined2 *)(local_274 + uVar32 * 2) = 0;
    goto LAB_2ad9915251e;
  }
  goto LAB_2ad99154a6a;
LAB_2ad991545ca:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1802ac000001fa);
LAB_2ad991545ea:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1902af000001fa);
LAB_2ad9915460a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3302af000001fa);
LAB_2ad9915462a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x55065a000001f6);
LAB_2ad9915464a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x7f064f000001f6);
LAB_2ad9915466a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2506e8000001f6);
LAB_2ad9915468a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4b0621000001f6);
LAB_2ad991546aa:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x310614000001f6);
LAB_2ad991546ca:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2106b2000001f6);
LAB_2ad991546ea:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3602ac000001fa);
LAB_2ad9915470a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4f06db000001f6);
LAB_2ad9915472a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x7806cf000001f6);
LAB_2ad9915474a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x5706a4000001f6);
LAB_2ad9915476a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x7b0697000001f6);
LAB_2ad9915478a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3302b0000001f9);
LAB_2ad991547aa:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3001fb000001f6);
LAB_2ad991547ca:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3001fc000001f6);
LAB_2ad991547ea:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2d01fe000001f6);
LAB_2ad9915480a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2d01ff000001f6);
LAB_2ad9915482a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4404bc000001f9);
LAB_2ad9915484a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2f0200000001f6);
LAB_2ad9915486a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x7204bc000001f9);
LAB_2ad9915488a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2f0201000001f6);
LAB_2ad991548aa:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xaf04bc000001f9);
LAB_2ad991548ca:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b04bc000001f9);
LAB_2ad991548ea:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x5104bc000001f9);
LAB_2ad9915490a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x8c04bc000001f9);
LAB_2ad9915492a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x5e0302000001f9);
LAB_2ad9915494a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x7e0302000001f9);
LAB_2ad9915496a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x210302000001f9);
LAB_2ad9915498a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3a0302000001f9);
LAB_2ad991549aa:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x650302000001f9);
LAB_2ad991549ca:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x68030f000001f9);
LAB_2ad991549ea:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x93030f000001f9);
LAB_2ad99154a0a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2b030f000001f9);
LAB_2ad99154a2a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x44030f000001f9);
LAB_2ad99154a4a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x6f030f000001f9);
LAB_2ad99154a6a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4002e4000001f9);
LAB_2ad99154a8a:
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4202e8000001f9);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



/* Address: 2ad99154d40 */

void FUN_2ad99154d40(void)

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
  int iVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  uint uVar17;
  bool bVar18;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  lVar14 = 0;
  local_60 = 0;
  local_5c = 0;
  do {
    local_50 = 0;
    local_4c = 0;
    FUN_2ad99140a40(&local_60,0x2ad991784e0,0);
    lVar5 = *(longlong *)(&DAT_2ad99178504 + lVar14 * 0xc);
    if (lVar5 != 0) {
      uVar4 = *(uint *)(lVar5 + -4);
      uVar15 = (ulonglong)uVar4;
      if ((uVar15 != 0) || (local_5c == 0)) {
        if (local_5c == 0) {
          uVar17 = 0;
          uVar13 = uVar4;
        }
        else {
          uVar17 = *(uint *)(local_5c + -4);
          uVar13 = uVar4 + uVar17;
        }
        cVar10 = FUN_2ad99140060(&local_60);
        if (cVar10 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x25094f000001f9);
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        if (uVar15 != 0) {
          lVar1 = local_5c + (ulonglong)uVar17 * 2;
          if (uVar4 < 8) {
            uVar12 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
            uVar12 = 0;
          }
          else {
            uVar16 = 0;
            uVar12 = (ulonglong)(uVar4 & 0xfffffff8);
            do {
              puVar2 = (undefined4 *)(lVar5 + uVar16);
              uVar7 = puVar2[1];
              uVar8 = puVar2[2];
              uVar9 = puVar2[3];
              puVar3 = (undefined4 *)(lVar1 + uVar16);
              *puVar3 = *puVar2;
              puVar3[1] = uVar7;
              puVar3[2] = uVar8;
              puVar3[3] = uVar9;
              uVar16 = uVar16 + 0x10;
            } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar12 == uVar15) goto LAB_2ad99154ef2;
          }
          do {
            *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
            uVar12 = uVar12 + 1;
          } while (uVar15 != uVar12);
        }
LAB_2ad99154ef2:
        *(uint *)(local_5c + -4) = uVar13;
        *(undefined2 *)(local_5c + (ulonglong)uVar13 * 2) = 0;
      }
    }
    FUN_2ad99140a40(&local_50,&local_60,0,0x2ad991716b0);
    iVar11 = (*(code *)0x7ff63a0f4840)(0x2ad95e68178,0);
    if (-1 < iVar11) {
      (*(code *)0x7ff63a0f4ce0)(0x2ad95e68178,0);
    }
    FUN_2ad99140000(&local_50);
    bVar18 = lVar14 == 0x11;
    lVar14 = lVar14 + 1;
    if (bVar18) {
      DAT_2ad991784d6 = 0;
      FUN_2ad99140000(&local_60);
      return;
    }
  } while( true );
}



/* Address: 2ad99154f90 */

void FUN_2ad99154f90(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x25094f000001f9);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ad99155c50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99155c50(void)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = -0xd8;
  do {
    if ((((*(int *)(lVar4 + 0x2ad991785d8) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ad991785dc), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad991785dc) = 0;
    *(undefined4 *)(lVar4 + 0x2ad991785d8) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_2ad99140000(0x2ad991784f0);
  FUN_2ad99140000(0x2ad991784e0);
  lVar4 = -0x30;
  do {
    if (((*(int *)(&DAT_2ad99178400 + lVar4) != 0) &&
        (lVar2 = *(longlong *)(&DAT_2ad99178404 + lVar4), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(&DAT_2ad99178404 + lVar4) = 0;
    *(undefined4 *)(&DAT_2ad99178400 + lVar4) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_2ad99140000(0x2ad99178398);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,0x2ad99178360);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,0x2ad99178320);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,0x2ad991782e0);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,0x2ad991782a0);
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,0x2ad99178260);
  FUN_2ad99140000(0x2ad99178238);
  FUN_2ad99140000(0x2ad99178228);
  FUN_2ad99140000(0x2ad99178218);
  FUN_2ad99140000(0x2ad991781f8);
  FUN_2ad99140000(0x2ad991781e8);
  FUN_2ad99140000(0x2ad991781d8);
  lVar4 = _DAT_2ad991781ac;
  if (_DAT_2ad991781ac != 0) {
    uVar5 = (ulonglong)_DAT_2ad99178198;
    if (uVar5 != 0) {
      lVar2 = -0xc;
      do {
        if ((ulonglong)*(uint *)(&DAT_2ad991781a8 + lVar2) == 0) break;
        uVar5 = uVar5 * *(uint *)(&DAT_2ad991781a8 + lVar2);
        lVar2 = lVar2 + 4;
      } while (lVar2 != 0);
      if (uVar5 != 0) {
        plVar3 = (longlong *)(_DAT_2ad991781ac + 4);
        do {
          if (((*(int *)((longlong)plVar3 + -4) != 0) && (lVar2 = *plVar3, lVar2 != 0)) &&
             (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
            piVar1 = (int *)(lVar2 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2ad95e68178);
            }
          }
          *plVar3 = 0;
          *(undefined4 *)((longlong)plVar3 + -4) = 0;
          plVar3 = (longlong *)((longlong)plVar3 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2ad95e68178,lVar4,0);
    _DAT_2ad991781ac = 0;
  }
  _DAT_2ad99178198 = 0;
  _DAT_2ad991781a8 = 0;
  FUN_2ad99140000(0x2ad99178170);
  lVar4 = -0x78;
  do {
    if ((((*(int *)(lVar4 + 0x2ad99177498) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ad9917749c), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad9917749c) = 0;
    *(undefined4 *)(lVar4 + 0x2ad99177498) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ad99177418) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ad9917741c), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad9917741c) = 0;
    *(undefined4 *)(lVar4 + 0x2ad99177418) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ad99177398) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ad9917739c), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad9917739c) = 0;
    *(undefined4 *)(lVar4 + 0x2ad99177398) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if ((((*(int *)(lVar4 + 0x2ad99177318) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ad9917731c), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad9917731c) = 0;
    *(undefined4 *)(lVar4 + 0x2ad99177318) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ad99177298) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ad9917729c), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ad9917729c) = 0;
    *(undefined4 *)(lVar4 + 0x2ad99177298) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x41a0;
  do {
    if (((*(int *)(&DAT_2ad99177220 + lVar4) != 0) &&
        (lVar2 = *(longlong *)(&DAT_2ad99177224 + lVar4), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ad95e68178);
      }
    }
    *(undefined8 *)(&DAT_2ad99177224 + lVar4) = 0;
    *(undefined4 *)(&DAT_2ad99177220 + lVar4) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_2ad99140000(0x2ad99173068);
  FUN_2ad99140000(0x2ad99173028);
  FUN_2ad99140000(0x2ad99173010);
  FUN_2ad99140000(0x2ad99173000);
  return;
}



/* Address: 2ad99156210 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99156210(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 local_a8;
  undefined4 local_a0;
  longlong local_98;
  undefined4 local_90 [20];
  
  if (_DAT_2ad99183b14 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    FUN_2ad99140000(param_1 + 0x34);
    local_98 = param_1 + 0x84;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    FUN_2ad99140000();
    (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
    FUN_2ad99140000(param_1 + 0x144);
    (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
    FUN_2ad99140000(param_1 + 0x208);
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
    if (1 < param_2) {
      *(undefined4 *)(param_1 + 0x110) = 0x271d;
      FUN_2ad99140a40(param_1 + 0x144,0x2ad99161888,0,0x2ad9916ff68);
      return;
    }
    *(undefined4 *)(param_1 + 0x20) = 1;
    FUN_2ad99140a40(param_1 + 0x34,0x2ad99183b28,0,0x2ad9916ff78);
    *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
    *(undefined8 *)(param_1 + 0x40) = param_3;
    *(uint *)(param_1 + 0x70) = param_2;
    *(undefined8 *)(param_1 + 0x48) = param_4;
    *(undefined8 *)(param_1 + 0x58) = param_5;
    *(undefined8 *)(param_1 + 0x60) = param_6;
    *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_1 + 0x29d);
    local_a8 = 0;
    local_a0 = 0;
    FUN_2ad99140a40(&local_a8,0x2ad99183b28,0,0x2ad99170ae8);
    cVar1 = (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_a8,0x47,local_90);
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = local_90[0];
    }
    if ((ulonglong)*(uint *)(param_1 + 0x70) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02ad991565af */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((ulonglong)*(uint *)(param_1 + 0x70) * 8 + 0x2ad99160830))(0x2ad99160830,uVar2);
      return;
    }
    *(undefined4 *)(param_1 + 0x110) = 0x2733;
    (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad991628d8);
    FUN_2ad99140000(&local_a8);
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,0xd,2,0x590008,0x2ad99162960,0x590008,0x2ad99161838);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  return;
}



/* Address: 2ad991566c0 */

ulonglong FUN_2ad991566c0(longlong param_1,longlong param_2)

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
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,param_2,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (uVar2 < 2) goto LAB_2ad99156a23;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,param_2,0x32);
  if (uVar2 == 2) {
    if (*(int *)(param_1 + 0x20) == 5) goto LAB_2ad99156a23;
    if ((uVar3 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      goto LAB_2ad99156a23;
    }
    if ((uVar3 & 2) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 1;
      *(undefined4 *)(param_1 + 0x74) = 1;
      goto LAB_2ad99156a23;
    }
LAB_2ad991569a3:
    *(undefined4 *)(param_1 + 0x110) = 0x272e;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x2a5);
    if (iVar1 == 2) {
LAB_2ad99156a0d:
      *(undefined4 *)(param_1 + 0x74) = 2;
      goto LAB_2ad99156a23;
    }
    if (iVar1 == 1) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x2ad99183b28;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_2ad99140a40(&local_48,lVar5,0,0x2ad99170ad8);
        (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ad991568ab */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2ad99160870))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99162860);
        FUN_2ad99140000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2ad99156a0d;
      }
      uVar3 = uVar3 & 2;
joined_r0x02ad991569a1:
      if (uVar3 != 0) {
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x2a5);
        goto LAB_2ad99156a23;
      }
      goto LAB_2ad991569a3;
    }
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x2ad99183b28;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_2ad99140a40(&local_48,lVar5,0,0x2ad99170ad8);
        (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ad99156802 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2ad99160890))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99162860);
        FUN_2ad99140000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2ad99156a0d;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x02ad991569a1;
    }
    *(undefined4 *)(param_1 + 0x110) = 0x271b;
  }
  uVar4 = 0;
LAB_2ad99156a23:
  return uVar4 & 0xffffffff;
}



/* Address: 2ad99156a40 */

void FUN_2ad99156a40(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x2ad99183b28;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_2ad99140a40(&local_60,lVar10,0,0x2ad991707a8);
  (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x02ad99156b77 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x2ad991608b0))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,*param_3,0x53,&local_88);
  FUN_2ad99140a40(&local_98,0x2ad991627e0,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_2ad991571df;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_2ad991571df;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_2ad99140060(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1f0561000101f9);
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
      if (uVar11 == uVar12) goto LAB_2ad991573d2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_2ad991573d2:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_2ad991571df:
  FUN_2ad99140a40(param_1,&local_98,0,0x2ad99170aa8);
  FUN_2ad99140a40(&local_50,param_1,0,0x2ad99170ab8);
  FUN_2ad99140000(&local_60);
  FUN_2ad99140a40(0x2ad99183b3c,&local_50,1,0x2ad99170ac8);
  FUN_2ad99140000(&local_50);
  FUN_2ad99140000(&local_88);
  FUN_2ad99140000(&local_98);
  FUN_2ad99140000(&local_78);
  return;
}



/* Address: 2ad99157260 */

void FUN_2ad99157260(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_2ad99140a40(&stack0x00000060,0x2ad99183b3c,1,0x2ad99170878);
  (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,0xd8,2,0x590008,0x2ad99162070);
  FUN_2ad99140a40(&stack0x00000050,0x2ad99183b3c,1,0x2ad99170888);
  FUN_2ad99140a40(in_stack_00000048,&stack0x00000050,0,0x2ad99170898);
  FUN_2ad99140a40(&stack0x00000098,in_stack_00000048,0,0x2ad99170ab8);
  FUN_2ad99140000(&stack0x00000088);
  FUN_2ad99140a40(0x2ad99183b3c,&stack0x00000098,1,0x2ad99170ac8);
  FUN_2ad99140000(&stack0x00000098);
  FUN_2ad99140000(&stack0x00000060);
  FUN_2ad99140000(&stack0x00000050);
  FUN_2ad99140000(&stack0x00000070);
  return;
}



/* Address: 2ad99157420 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99157420(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_2ad99140a40(param_2,0x2ad99160d08,0,0x2ad991701a8);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x2ad99183b28;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_2ad99140a40(&local_98,piVar12,0,0x2ad991701b8);
  (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x2ad95e68178,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x02ad99157600 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x2ad991609d8))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,(longlong)*param_3,0x52,&local_108);
  FUN_2ad99140a40(&local_f8,0x2ad99161f30,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_2ad99157eeb;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_2ad99157eeb;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_2ad99140060(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1e04cf000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xf04a0000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xf04a5000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x150470000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x150489000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x15043c000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x150457000101f9);
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
      if (uVar13 == uVar14) goto LAB_2ad991591c2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_2ad991591c2:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_2ad99157eeb:
  uVar9 = local_e8;
  FUN_2ad99140a40(local_e8,&local_f8,0,0x2ad99170778);
  FUN_2ad99140a40(&local_68,uVar9,0,0x2ad99170788);
  FUN_2ad99140000(&local_98);
  FUN_2ad99140000(&local_e0);
  FUN_2ad99140000(&local_88);
  FUN_2ad99140000(&local_78);
  FUN_2ad99140000(&local_c0);
  FUN_2ad99140a40(0x2ad99183b3c,&local_68,1,0x2ad99170798);
  FUN_2ad99140000(&local_68);
  FUN_2ad99140000(&local_108);
  FUN_2ad99140000(&local_f8);
  FUN_2ad99140000(&local_d0);
  FUN_2ad99140000(&local_b0);
  return;
}



/* Address: 2ad991594e0 */

void FUN_2ad991594e0(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x02ad99159543 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x2ad99160a48))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ad95e68178,(ulonglong)param_2,0x53,&local_50);
  FUN_2ad99140a40(&local_60,0x2ad991616c8,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_2ad9915973d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_2ad9915973d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_2ad99140060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2203c7000101f9);
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
      if (uVar11 == uVar13) goto LAB_2ad99159732;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_2ad99159732:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_2ad9915973d:
  FUN_2ad99140a40(param_1,&local_60,0,0x2ad991700d8);
  FUN_2ad99140a40(&local_40,param_1,0,0x2ad991700e8);
  FUN_2ad99140a40(0x2ad99183b3c,&local_40,1,0x2ad991700f8);
  FUN_2ad99140000(&local_40);
  FUN_2ad99140000(&local_50);
  FUN_2ad99140000(&local_60);
  return;
}



/* Address: 2ad991597e0 */

void FUN_2ad991597e0(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_2ad99140a40(&local_78,0x2ad99183b3c,1,0x2ad99170108);
    FUN_2ad99140a40(&local_88,&local_78,0,0x2ad99170118);
    (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,param_3,param_4);
    FUN_2ad99140a40(&local_78,0x2ad99183b3c,1,0x2ad99170128);
    FUN_2ad99140a40(&local_98,&local_78,0,0x2ad99170138);
    (*(code *)0x7ff63a0e49f0)
              (0x2ad95e68178,0xd8,3,0x590008,0x2ad99161790,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x2ad99170158;
    uVar1 = 0x2ad99170148;
  }
  else {
    uVar2 = 0x2ad99170178;
    uVar1 = 0x2ad99170168;
  }
  FUN_2ad99140a40(&local_78,0x2ad99183b3c,1,uVar1);
  FUN_2ad99140a40(param_1,&local_78,0,uVar2);
  FUN_2ad99140a40(&local_68,param_1,0,0x2ad99170188);
  FUN_2ad99140000(&local_98);
  FUN_2ad99140000(&local_88);
  FUN_2ad99140a40(0x2ad99183b3c,&local_68,1,0x2ad99170198);
  FUN_2ad99140000(&local_68);
  FUN_2ad99140000(&local_78);
  return;
}



/* Address: 2ad99159a20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ad99159a20(double param_1,longlong param_2)

{
  longlong lVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  ulonglong uVar9;
  double dVar10;
  
  puVar4 = *(undefined1 **)(param_2 + 4);
  if (puVar4 != &DAT_2ad99160d00) {
    if (puVar4 == (undefined1 *)0x0) goto LAB_2ad99159ac2;
    uVar7 = *(uint *)(puVar4 + -4);
    uVar5 = _DAT_2ad99160cfc;
    if (uVar7 < _DAT_2ad99160cfc) {
      uVar5 = uVar7;
    }
    iVar6 = uVar7 - _DAT_2ad99160cfc;
    if (uVar5 != 0) {
      uVar9 = 0;
      do {
        uVar2 = *(ushort *)(puVar4 + uVar9 * 2);
        uVar3 = *(ushort *)(&DAT_2ad99160d00 + uVar9 * 2);
        uVar9 = uVar9 + 1;
        if (uVar5 <= uVar9) break;
      } while (uVar2 == uVar3);
      if (uVar2 != uVar3) {
        iVar6 = (uint)uVar2 - (uint)uVar3;
      }
    }
    if (iVar6 != 0) goto LAB_2ad99159ac2;
  }
  FUN_2ad99140a40(param_2,0x2ad99183b28,1,0x2ad991711a0);
LAB_2ad99159ac2:
  (*(code *)0x7ff63a0f2890)(0x2ad95e68178,param_2,0x1b);
  if ((_DAT_2ad99183b48 != 0.0) || (NAN(_DAT_2ad99183b48))) {
    param_1 = param_1 / _DAT_2ad99183b48;
    uVar7 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar7 - 0x3ff;
    dVar10 = param_1;
    if ((ulonglong)uVar7 < 0x433) {
      if (uVar7 < 0x3ff) {
        dVar10 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar10 = (double)((ulonglong)param_1 & 0x8000000000000000);
        }
      }
      else {
        bVar8 = (byte)lVar1;
        if (((longlong)param_1 << (bVar8 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar10 = (double)((0x8000000000000U >> (bVar8 & 0x3f)) + (longlong)param_1 &
                           -0x10000000000000 >> (bVar8 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar10 = param_1 + param_1;
    }
    param_1 = dVar10 * _DAT_2ad99183b48;
  }
  else {
    uVar7 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,param_2,0x11);
    if ((longlong)param_1 != -0x8000000000000000) {
      dVar10 = (double)(longlong)param_1;
      uVar9 = 0xb;
      if (uVar7 < 0xb) {
        uVar9 = (ulonglong)uVar7;
      }
      param_1 = (double)(longlong)
                        ((param_1 - dVar10) * *(double *)(&DAT_2ad99160b20 + uVar9 * 8) +
                        *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x2ad99160a88)) /
                *(double *)(&DAT_2ad99160b20 + uVar9 * 8) + dVar10;
    }
  }
  return param_1;
}



/* Address: 2ad99159c50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99159c50(double param_1,double param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double local_90 [13];
  
  if (param_1 <= 0.0) {
    (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x24);
    dVar6 = _DAT_2ad99183b48;
    dVar3 = (double)(*(code *)0x7ff63a3dae50)(_DAT_2ad99183b48);
    local_90[0] = 0.0;
    (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,4);
    (*(code *)0x7ff63a108d40)(0x2ad95e68178,0,0x2ad99183b28,dVar6,_DAT_2ad99183b48,local_90);
    (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x23);
    dVar4 = _DAT_2ad99183b48;
    if ((longlong)_DAT_2ad99183b48 != -0x8000000000000000) {
      dVar4 = (double)(longlong)_DAT_2ad99183b48;
      dVar4 = (double)(longlong)
                      ((_DAT_2ad99183b48 - dVar4) * _DAT_2ad99160aa0 +
                      *(double *)((ulonglong)(0.0 < _DAT_2ad99183b48) * 8 + 0x2ad99160aa8)) /
              _DAT_2ad99160aa0 + dVar4;
    }
    (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x22);
    dVar5 = _DAT_2ad99183b48;
    if ((longlong)_DAT_2ad99183b48 != -0x8000000000000000) {
      dVar5 = (double)(longlong)_DAT_2ad99183b48;
      dVar5 = (double)(longlong)
                      ((_DAT_2ad99183b48 - dVar5) * _DAT_2ad99160aa0 +
                      *(double *)((ulonglong)(0.0 < _DAT_2ad99183b48) * 8 + 0x2ad99160aa8)) /
              _DAT_2ad99160aa0 + dVar5;
    }
    if (dVar5 <= dVar6) {
      dVar5 = dVar6;
    }
    param_1 = dVar5;
    if (0.0 < local_90[0]) {
      (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x25);
      if ((local_90[0] == 0.0) && (!NAN(local_90[0]))) {
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x880455000001f7);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      param_1 = (dVar6 * (param_2 / _DAT_2ad99160ab8) * _DAT_2ad99183b48) / local_90[0];
      if ((longlong)param_1 != -0x8000000000000000) {
        dVar6 = (double)(longlong)param_1;
        uVar2 = 0xb;
        if ((uint)(int)(dVar3 / _DAT_2ad99160a98) < 0xb) {
          uVar2 = (ulonglong)(uint)(int)(dVar3 / _DAT_2ad99160a98);
        }
        param_1 = (double)(longlong)
                          ((param_1 - dVar6) * *(double *)(&DAT_2ad99160b20 + uVar2 * 8) +
                          *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x2ad99160aa8)) /
                  *(double *)(&DAT_2ad99160b20 + uVar2 * 8) + dVar6;
      }
      if (dVar4 <= param_1) {
        param_1 = dVar4;
      }
      if (param_1 <= dVar5) {
        param_1 = dVar5;
      }
    }
  }
  FUN_2ad9915cd50(param_1);
  return;
}



/* Address: 2ad99159f70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad99159f70(int param_1,undefined8 param_2,longlong param_3)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  double dVar4;
  double dVar5;
  undefined8 uVar6;
  undefined1 auVar7 [12];
  longlong lVar8;
  char cVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  int iVar14;
  ulonglong uVar15;
  undefined4 *puVar16;
  ulonglong *puVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  undefined1 (*pauVar26) [16];
  longlong lVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 extraout_XMM0_Qa;
  undefined1 auVar36 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  double dVar50;
  double *pdVar51;
  undefined8 in_stack_fffffffffffffc98;
  undefined4 local_318;
  longlong local_314;
  int local_30c;
  undefined4 local_308;
  longlong local_304;
  undefined4 local_2f8;
  longlong local_2f4;
  longlong local_2e8;
  undefined4 local_2e0;
  longlong local_2dc;
  undefined4 local_2d0;
  undefined8 local_2cc;
  longlong local_2c0;
  double local_2b8;
  int local_2b0;
  undefined8 local_2ac;
  longlong local_2a4;
  undefined8 local_29c;
  undefined8 local_294;
  undefined8 local_28c;
  undefined8 local_284;
  undefined4 local_27c;
  undefined8 local_278;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_1e8;
  undefined1 local_1e4 [53];
  undefined8 local_1af;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined8 local_178;
  undefined6 uStack_170;
  undefined2 uStack_16a;
  undefined2 local_168;
  short local_166 [147];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 uVar45;
  undefined4 uVar52;
  
  uVar48 = (undefined4)((ulonglong)in_stack_fffffffffffffc98 >> 0x20);
  local_2f8 = 0;
  local_2e0 = 0;
  local_308 = 0;
  local_318 = 0;
  local_27c = 0;
  local_2f4 = 0;
  local_2dc = 0;
  local_304 = 0;
  local_314 = 0;
  local_278 = 0;
  if (param_1 == 0) {
    uVar46 = (undefined4)_DAT_2ad99178440;
    uVar47 = (undefined4)((ulonglong)_DAT_2ad99178440 >> 0x20);
  }
  else {
    uVar46 = 0;
    uVar47 = 0;
  }
  if (param_1 == 1) {
    uVar46 = (undefined4)_DAT_2ad99178438;
    uVar47 = (undefined4)((ulonglong)_DAT_2ad99178438 >> 0x20);
  }
  local_30c = param_1;
  local_2c0 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170cc8);
  dVar31 = (double)FUN_2ad99159a20(CONCAT44(uVar47,uVar46),&local_318);
  uVar46 = SUB84(dVar31,0);
  uVar47 = (undefined4)((ulonglong)dVar31 >> 0x20);
  dVar32 = (double)FUN_2ad9915cd50(param_2);
  iVar19 = local_30c;
  if ((dVar32 == 0.0) && (!NAN(dVar32))) goto LAB_2ad9915ab70;
  bVar29 = local_30c != 1;
  FUN_2ad99140a40(&local_318,0x2ad99183b28,1,0x2ad99170cd8);
  local_2d0 = 0;
  local_2cc = 0;
  _DAT_2ad99183b10 = 0;
  _DAT_2ad99183b80 = 0;
  DAT_2ad99183b88 = 0;
  (*(code *)0x7ff63a0f2c10)(0x2ad95e68178,&local_318,&local_1e8);
  uVar34 = *(undefined8 *)(local_1e4 + (ulonglong)bVar29 * 8 + 4);
  (*(code *)0x7ff63a0c7370)(0x2ad95e68178,0x2a);
  dVar4 = _DAT_2ad99183b48;
  dVar33 = (double)(*(code *)0x7ff63a3d9970)((double)iVar19,_DAT_2ad99160ad0);
  iVar19 = (int)dVar33;
  pdVar51 = &local_2b8;
  cVar9 = (*(code *)0x7ff63a108d40)(0x2ad95e68178,iVar19,&local_318,dVar32,uVar34,pdVar51);
  uVar49 = _DAT_2ad99183b10;
  uVar52 = (undefined4)((ulonglong)pdVar51 >> 0x20);
  if (cVar9 == '\0') {
    (*(code *)0x7ff63a0e49f0)
              (0x2ad95e68178,2,4,0x590008,0x2ad99163170,CONCAT44(uVar52,0x590008),0x2ad991631b8,
               0x590008,0x2ad991631f0,0x520004,CONCAT44(uVar48,_DAT_2ad99183b10));
  }
  else {
    if (local_2b8 <= dVar4) {
      FUN_2ad99140000(&local_2d0);
      FUN_2ad99140a40(&local_318,0x2ad99183b28,1,0x2ad99170ce8);
      local_1e8 = 0;
      local_1e4._0_8_ = 0;
      (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x23);
      dVar33 = _DAT_2ad99183b48;
      (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x37);
      dVar4 = 0.0;
      bVar29 = _DAT_2ad99183b48 == 0.0;
      uVar25 = ~-(ulonglong)bVar29 & (ulonglong)_DAT_2ad99183b48;
      FUN_2ad99140a40(&local_1e8,&local_318,0,0x2ad991711c0);
      cVar9 = (*(code *)0x7ff63a107f20)(0x2ad95e68178,&local_1e8);
      if (cVar9 == '\0') {
        uVar48 = (undefined4)_DAT_2ad99160ad8;
        uVar49 = (undefined4)((ulonglong)_DAT_2ad99160ad8 >> 0x20);
      }
      else {
        (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
        uVar48 = SUB84(_DAT_2ad99183b48,0);
        uVar49 = (undefined4)((ulonglong)_DAT_2ad99183b48 >> 0x20);
      }
      dVar50 = (double)(uVar25 | -(ulonglong)bVar29 & (ulonglong)dVar33);
      iVar20 = 0;
      FUN_2ad99140a40(&local_1e8,&local_318,0);
      local_188 = 0;
      uStack_184 = 0;
      uStack_180 = 0;
      iVar19 = (*(code *)0x7ff63a1081a0)(0x2ad95e68178);
      local_2e8 = param_3;
      if (0 < iVar19) {
        dVar4 = 0.0;
        do {
          lVar11 = (*(code *)0x7ff63a1081f0)(0x2ad95e68178,iVar20);
          if (lVar11 != 0) {
            (*(code *)0x7ff63a1083a0)(0x2ad95e68178,0);
            FUN_2ad99140a40(&local_188,0x2ad99183b3c,1);
            lVar11 = CONCAT44(uStack_180,uStack_184);
            if (local_1e4._0_8_ == lVar11) {
LAB_2ad9915a5a0:
              (*(code *)0x7ff63a108280)(0x2ad95e68178,7);
              dVar4 = dVar4 + _DAT_2ad99183b48;
            }
            else if ((local_1e4._0_8_ != 0) && (lVar11 != 0)) {
              uVar21 = *(uint *)(local_1e4._0_8_ + -4);
              uVar22 = *(uint *)(lVar11 + -4);
              uVar18 = uVar22;
              if (uVar21 < uVar22) {
                uVar18 = uVar21;
              }
              iVar14 = uVar21 - uVar22;
              if (uVar18 != 0) {
                uVar25 = 1;
                do {
                  uVar1 = *(ushort *)(local_1e4._0_8_ + -2 + uVar25 * 2);
                  uVar2 = *(ushort *)(lVar11 + -2 + uVar25 * 2);
                  if (uVar18 <= uVar25) break;
                  uVar25 = uVar25 + 1;
                } while (uVar1 == uVar2);
                param_3 = local_2e8;
                if (uVar1 != uVar2) {
                  iVar14 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar14 == 0) goto LAB_2ad9915a5a0;
            }
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 != iVar19);
      }
      FUN_2ad99140000(&local_188);
      dVar5 = 0.0;
      if ((((double)CONCAT44(uVar49,uVar48) < 0.0) ||
          (dVar50 = dVar50 - (double)CONCAT44(uVar49,uVar48), 0.0 < dVar50)) &&
         (dVar5 = dVar50 - dVar4, dVar33 < dVar5)) {
        dVar5 = dVar33;
      }
      FUN_2ad99140000(&local_1e8);
      if ((dVar5 < dVar32) ||
         ((iVar19 = (*(code *)0x7ff63a0c73c0)(0x2ad95e68178,0x2f), iVar19 != 0 &&
          (iVar20 = (*(code *)0x7ff63a1081a0)(0x2ad95e68178), iVar19 <= iVar20))))
      goto LAB_2ad9915ab70;
      dVar33 = _DAT_2ad99183cd0;
      iVar19 = _DAT_2ad99183ca0;
      dVar4 = *(double *)((ulonglong)(param_1 == 1) * 8 + 0x2ad99160ac0);
      puVar13 = *(undefined1 **)(param_3 + 4);
      if (puVar13 == &DAT_2ad9916297c) {
LAB_2ad9915a851:
        if ((_DAT_2ad99183ca0 != 1) ||
           (((_DAT_2ad99183cd0 == 0.0 && (!NAN(_DAT_2ad99183cd0))) ||
            (dVar50 = _DAT_2ad99178250 * _DAT_2ad99183cd0,
            lVar11 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x1f),
            (double)lVar11 * _DAT_2ad99183b18 <= dVar50)))) {
          dVar50 = _DAT_2ad99183cc8;
          uVar34 = 0;
          if (((_DAT_2ad99183cc8 == 0.0) && (!NAN(_DAT_2ad99183cc8))) ||
             (dVar5 = _DAT_2ad99178250 * _DAT_2ad99183cc8,
             lVar11 = (*(code *)0x7ff63a0f2970)(0x2ad95e68178,0x2ad99160ca0,0x1f),
             (double)lVar11 * _DAT_2ad99183b18 <= dVar5)) {
            if (0.0 < dVar50) {
              FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170cf8);
              uVar34 = FUN_2ad99159a20(dVar50 * dVar4 * _DAT_2ad99178250 + dVar31,&local_318);
            }
            uVar48 = 0;
            uVar49 = 0;
            if ((iVar19 == 1) && (0.0 < dVar33)) {
              FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170d08);
              uVar35 = FUN_2ad99159a20(dVar31 - dVar33 * dVar4 * _DAT_2ad99178250,&local_318);
              uVar48 = (undefined4)uVar35;
              uVar49 = (undefined4)((ulonglong)uVar35 >> 0x20);
            }
            goto LAB_2ad9915accc;
          }
        }
        (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,0x2ad99162e80);
        goto LAB_2ad9915ab70;
      }
      uVar48 = 0;
      uVar49 = 0;
      if (puVar13 != (undefined1 *)0x0) {
        uVar21 = *(uint *)(puVar13 + -4);
        uVar22 = _DAT_2ad99162978;
        if (uVar21 < _DAT_2ad99162978) {
          uVar22 = uVar21;
        }
        iVar20 = uVar21 - _DAT_2ad99162978;
        if (uVar22 != 0) {
          uVar25 = 0;
          do {
            uVar1 = *(ushort *)(puVar13 + uVar25 * 2);
            uVar2 = *(ushort *)(&DAT_2ad9916297c + uVar25 * 2);
            uVar25 = uVar25 + 1;
            if (uVar22 <= uVar25) break;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar20 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if ((iVar20 != 0) && (puVar13 != &DAT_2ad99162a3c)) {
          uVar22 = _DAT_2ad99162a38;
          if (uVar21 < _DAT_2ad99162a38) {
            uVar22 = uVar21;
          }
          iVar20 = uVar21 - _DAT_2ad99162a38;
          if (uVar22 != 0) {
            uVar25 = 0;
            do {
              uVar1 = *(ushort *)(puVar13 + uVar25 * 2);
              uVar2 = *(ushort *)(&DAT_2ad99162a3c + uVar25 * 2);
              uVar25 = uVar25 + 1;
              if (uVar22 <= uVar25) break;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar20 = (uint)uVar1 - (uint)uVar2;
            }
          }
          uVar34 = 0;
          if (iVar20 != 0) goto LAB_2ad9915accc;
        }
        goto LAB_2ad9915a851;
      }
      uVar34 = 0;
LAB_2ad9915accc:
      FUN_2ad99140a40(&local_318,0x2ad99183c68,0);
      lVar11 = *(longlong *)(param_3 + 4);
      if (lVar11 == 0) {
LAB_2ad9915adef:
        lVar11 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
        if (lVar11 == 0) {
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x11035c000001fa);
LAB_2ad9915bcd3:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3035e000001fa);
LAB_2ad9915bcf3:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x120373000001fa);
LAB_2ad9915bd13:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x90374000001fa);
LAB_2ad9915bd33:
          uVar34 = (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2a03a2000001f9);
LAB_2ad9915bd53:
          (*(code *)0x7ff639cc59a0)(uVar34,0x3203a2000001f9);
LAB_2ad9915bd69:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3703a2000001f9);
LAB_2ad9915bd89:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2f037d000001f9);
LAB_2ad9915bda9:
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x340363000001f9);
          goto LAB_2ad9915bdc9;
        }
        FUN_2ad99156210(lVar11,local_30c,dVar32,dVar31,CONCAT44(uVar49,uVar48),uVar34,&local_318);
        lVar11 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
        if (lVar11 == 0) goto LAB_2ad9915bcd3;
        local_2b0 = *(int *)(lVar11 + 0x110);
        local_2ac = *(undefined8 *)(lVar11 + 0x114);
        local_2a4 = *(longlong *)(lVar11 + 0x11c);
        local_29c = *(undefined8 *)(lVar11 + 0x124);
        local_294 = *(undefined8 *)(lVar11 + 300);
        local_28c = *(undefined8 *)(lVar11 + 0x134);
        local_284 = *(undefined8 *)(lVar11 + 0x13c);
        FUN_2ad99140a40(&local_27c,lVar11 + 0x144,0,0x2ad9916ff58);
        lVar27 = local_2e8;
        local_270 = *(undefined4 *)(lVar11 + 0x150);
        local_26c = *(undefined4 *)(lVar11 + 0x154);
        if (local_2a4 == 0) {
          (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,local_2b0,0,0x20);
          FUN_2ad99140a40(&local_318,0x2ad99183b3c,1,0x2ad99170d28);
          FUN_2ad99140a40(&local_308,0x2ad99162ee8,0,0x2ad99170d38);
          cVar9 = FUN_2ad99140920(&local_308,local_314);
          if (cVar9 != '\0') {
            (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_308);
            dVar31 = _DAT_2ad99183cc8;
            if (_DAT_2ad99183b14 == 0) {
              bVar30 = _DAT_2ad99183ca0 == 1;
              dVar33 = dVar4 * _DAT_2ad99183cc8;
              dVar4 = dVar4 * _DAT_2ad99183cd0;
              bVar29 = 0.0 < _DAT_2ad99183cd0;
              uVar21 = 0;
              while( true ) {
                if (local_2a4 != 0) goto LAB_2ad9915b0f0;
                lVar11 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
                if ((9 < lVar11 - local_2c0) ||
                   (iVar19 = (*(code *)0x7ff63a0f0fd0)(0x2ad95e68178,6), iVar19 != 0)) break;
                if (local_2b0 == 0x2738) goto LAB_2ad9915ab70;
                (*(code *)0x7ff63a0e17c0)(0x2ad95e68178,1000);
                cVar9 = (*(code *)0x7ff63a0f2c10)(0x2ad95e68178,0x2ad99160ca0,0x2ad99178430);
                if (cVar9 == '\0') goto LAB_2ad9915b45a;
                if (local_30c == 0) {
                  uVar46 = (undefined4)_DAT_2ad99178440;
                  uVar47 = (undefined4)((ulonglong)_DAT_2ad99178440 >> 0x20);
LAB_2ad9915b29a:
                  puVar13 = *(undefined1 **)(lVar27 + 4);
                  if (puVar13 == &DAT_2ad9916297c) goto LAB_2ad9915b3b5;
LAB_2ad9915b2f9:
                  if (puVar13 != (undefined1 *)0x0) {
                    uVar22 = *(uint *)(puVar13 + -4);
                    uVar18 = _DAT_2ad99162978;
                    if (uVar22 < _DAT_2ad99162978) {
                      uVar18 = uVar22;
                    }
                    iVar19 = uVar22 - _DAT_2ad99162978;
                    if (uVar18 != 0) {
                      uVar25 = 0;
                      do {
                        uVar1 = *(ushort *)(puVar13 + uVar25 * 2);
                        uVar2 = *(ushort *)(&DAT_2ad9916297c + uVar25 * 2);
                        uVar25 = uVar25 + 1;
                        if (uVar18 <= uVar25) break;
                      } while (uVar1 == uVar2);
                      if (uVar1 != uVar2) {
                        iVar19 = (uint)uVar1 - (uint)uVar2;
                      }
                    }
                    if ((iVar19 != 0) && (puVar13 != &DAT_2ad99162a3c)) {
                      uVar18 = _DAT_2ad99162a38;
                      if (uVar22 < _DAT_2ad99162a38) {
                        uVar18 = uVar22;
                      }
                      iVar19 = uVar22 - _DAT_2ad99162a38;
                      if (uVar18 != 0) {
                        uVar25 = 0;
                        do {
                          uVar1 = *(ushort *)(puVar13 + uVar25 * 2);
                          uVar2 = *(ushort *)(&DAT_2ad99162a3c + uVar25 * 2);
                          uVar25 = uVar25 + 1;
                          if (uVar18 <= uVar25) break;
                        } while (uVar1 == uVar2);
                        if (uVar1 != uVar2) {
                          iVar19 = (uint)uVar1 - (uint)uVar2;
                        }
                      }
                      if (iVar19 != 0) goto LAB_2ad9915b45a;
                    }
                    goto LAB_2ad9915b3b5;
                  }
                }
                else {
                  if (local_30c != 1) goto LAB_2ad9915b29a;
                  uVar46 = (undefined4)_DAT_2ad99178438;
                  uVar47 = (undefined4)((ulonglong)_DAT_2ad99178438 >> 0x20);
                  puVar13 = *(undefined1 **)(lVar27 + 4);
                  if (puVar13 != &DAT_2ad9916297c) goto LAB_2ad9915b2f9;
LAB_2ad9915b3b5:
                  if (0.0 < dVar31) {
                    FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170d48);
                    uVar34 = FUN_2ad99159a20(_DAT_2ad99178250 * dVar33 +
                                             (double)CONCAT44(uVar47,uVar46),&local_318);
                  }
                  if (bVar29 && bVar30) {
                    FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170d58);
                    uVar35 = FUN_2ad99159a20((double)CONCAT44(uVar47,uVar46) -
                                             _DAT_2ad99178250 * dVar4,&local_318);
                    uVar48 = (undefined4)uVar35;
                    uVar49 = (undefined4)((ulonglong)uVar35 >> 0x20);
                  }
                }
LAB_2ad9915b45a:
                FUN_2ad99140a40(&local_318,0x2ad99160d08,0,0x2ad99170d68);
                uVar35 = FUN_2ad99159a20(CONCAT44(uVar47,uVar46),&local_318);
                uVar46 = (undefined4)uVar35;
                uVar47 = (undefined4)((ulonglong)uVar35 >> 0x20);
                FUN_2ad99140a40(&local_318,0x2ad99183c68,0);
                lVar11 = *(longlong *)(lVar27 + 4);
                if (lVar11 != 0) {
                  uVar22 = *(uint *)(lVar11 + -4);
                  uVar25 = (ulonglong)uVar22;
                  if ((uVar25 != 0) || (local_314 == 0)) {
                    if (local_314 == 0) {
                      uVar18 = 0;
                    }
                    else {
                      uVar18 = *(uint *)(local_314 + -4);
                    }
                    cVar9 = FUN_2ad99140060(&local_318);
                    if (cVar9 == '\0') goto LAB_2ad9915be29;
                    if (uVar25 != 0) {
                      lVar27 = local_314 + (ulonglong)uVar18 * 2;
                      if (uVar22 < 8) {
                        uVar10 = 0;
                      }
                      else if ((ulonglong)(lVar27 - lVar11) < 0x20) {
                        uVar10 = 0;
                      }
                      else {
                        uVar15 = 0;
                        uVar10 = (ulonglong)(uVar22 & 0xfffffff8);
                        do {
                          uVar6 = ((undefined8 *)(lVar11 + uVar15))[1];
                          *(undefined8 *)(lVar27 + uVar15) = *(undefined8 *)(lVar11 + uVar15);
                          ((undefined8 *)(lVar27 + uVar15))[1] = uVar6;
                          uVar15 = uVar15 + 0x10;
                        } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar15);
                        if (uVar10 == uVar25) goto LAB_2ad9915b590;
                      }
                      do {
                        *(undefined2 *)(lVar27 + uVar10 * 2) = *(undefined2 *)(lVar11 + uVar10 * 2);
                        uVar10 = uVar10 + 1;
                      } while (uVar25 != uVar10);
                    }
LAB_2ad9915b590:
                    *(uint *)(local_314 + -4) = uVar22 + uVar18;
                    *(undefined2 *)(local_314 + (ulonglong)(uVar22 + uVar18) * 2) = 0;
                    lVar27 = local_2e8;
                  }
                }
                lVar11 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
                if (lVar11 == 0) goto LAB_2ad9915bcf3;
                FUN_2ad99156210(lVar11,local_30c,dVar32,uVar35,CONCAT44(uVar49,uVar48),uVar34,
                                &local_318);
                lVar11 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
                if (lVar11 == 0) goto LAB_2ad9915bd13;
                local_2b0 = *(int *)(lVar11 + 0x110);
                local_2ac = *(undefined8 *)(lVar11 + 0x114);
                local_2a4 = *(longlong *)(lVar11 + 0x11c);
                local_29c = *(undefined8 *)(lVar11 + 0x124);
                local_294 = *(undefined8 *)(lVar11 + 300);
                local_28c = *(undefined8 *)(lVar11 + 0x134);
                local_284 = *(undefined8 *)(lVar11 + 0x13c);
                FUN_2ad99140a40(&local_27c,lVar11 + 0x144,0);
                local_270 = *(undefined4 *)(lVar11 + 0x150);
                local_26c = *(undefined4 *)(lVar11 + 0x154);
                if ((_DAT_2ad99183b14 != 0) || (bVar28 = 0x12 < uVar21, uVar21 = uVar21 + 1, bVar28)
                   ) break;
              }
            }
            if (local_2a4 == 0) {
              (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,local_2b0,0,0x20);
              FUN_2ad99140a40(&local_318,0x2ad99183b3c,1,0x2ad99170d88);
              FUN_2ad99140a40(&local_308,0x2ad99162ee8,0,0x2ad99170d98);
              cVar9 = FUN_2ad99140920(&local_308,local_314);
              if (cVar9 == '\0') goto LAB_2ad9915be49;
              (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_308);
              if (local_2a4 == 0) goto LAB_2ad9915ab70;
            }
            goto LAB_2ad9915b0f0;
          }
          goto LAB_2ad9915bda9;
        }
LAB_2ad9915b0f0:
        lVar8 = local_2a4;
        FUN_2ad99140a40(&local_318,0x2ad99162f40,0);
        lVar11 = *(longlong *)(lVar27 + 4);
        if (lVar11 != 0) {
          uVar21 = *(uint *)(lVar11 + -4);
          uVar25 = (ulonglong)uVar21;
          if ((uVar25 == 0) && (local_314 != 0)) goto LAB_2ad9915b7aa;
          if (local_314 == 0) {
            uVar10 = 0;
          }
          else {
            uVar10 = (ulonglong)*(uint *)(local_314 + -4);
          }
          uVar22 = uVar21 + (int)uVar10;
          cVar9 = FUN_2ad99140060(&local_318);
          if (cVar9 != '\0') {
            if (uVar25 != 0) {
              lVar27 = local_314 + uVar10 * 2;
              if (uVar21 < 0x10) {
                uVar10 = 0;
              }
              else if ((ulonglong)(lVar27 - lVar11) < 0x20) {
                uVar10 = 0;
              }
              else {
                uVar15 = 0;
                uVar10 = (ulonglong)(uVar21 & 0xfffffff8);
                do {
                  uVar34 = ((undefined8 *)(lVar11 + uVar15))[1];
                  *(undefined8 *)(lVar27 + uVar15) = *(undefined8 *)(lVar11 + uVar15);
                  ((undefined8 *)(lVar27 + uVar15))[1] = uVar34;
                  uVar15 = uVar15 + 0x10;
                } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar15);
                if (uVar10 == uVar25) goto LAB_2ad9915b79f;
              }
              do {
                *(undefined2 *)(lVar27 + uVar10 * 2) = *(undefined2 *)(lVar11 + uVar10 * 2);
                uVar10 = uVar10 + 1;
              } while (uVar25 != uVar10);
            }
LAB_2ad9915b79f:
            *(uint *)(local_314 + -4) = uVar22;
            *(undefined2 *)(local_314 + (ulonglong)uVar22 * 2) = 0;
            goto LAB_2ad9915b7aa;
          }
          goto LAB_2ad9915bde9;
        }
LAB_2ad9915b7aa:
        uVar21 = 0;
        FUN_2ad99140a40(&local_308,&local_318,0);
        uVar22 = _DAT_2ad99162f58;
        uVar25 = (ulonglong)_DAT_2ad99162f58;
        if ((uVar25 != 0) || (local_304 == 0)) {
          if (local_304 != 0) {
            uVar21 = *(uint *)(local_304 + -4);
          }
          uVar18 = _DAT_2ad99162f58 + uVar21;
          cVar9 = FUN_2ad99140060(&local_308);
          if (cVar9 != '\0') {
            if (uVar25 != 0) {
              lVar11 = local_304 + (ulonglong)uVar21 * 2;
              if ((uVar22 < 0x10) || (lVar11 - 0x2ad99162f5cU < 0x20)) {
                uVar10 = 0;
              }
              else {
                uVar15 = 0;
                uVar10 = (ulonglong)(uVar22 & 0xfffffff8);
                do {
                  uVar34 = *(undefined8 *)(uVar15 + 0x2ad99162f64);
                  *(undefined8 *)(lVar11 + uVar15) = *(undefined8 *)(&DAT_2ad99162f5c + uVar15);
                  ((undefined8 *)(lVar11 + uVar15))[1] = uVar34;
                  uVar15 = uVar15 + 0x10;
                } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar15);
                if (uVar10 == uVar25) goto LAB_2ad9915b8a2;
              }
              do {
                *(undefined2 *)(lVar11 + uVar10 * 2) =
                     *(undefined2 *)(&DAT_2ad99162f5c + uVar10 * 2);
                uVar10 = uVar10 + 1;
              } while (uVar25 != uVar10);
            }
LAB_2ad9915b8a2:
            *(uint *)(local_304 + -4) = uVar18;
            *(undefined2 *)(local_304 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_2ad9915b8ad;
          }
          goto LAB_2ad9915bd89;
        }
LAB_2ad9915b8ad:
        (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,lVar8,0,0x20);
        FUN_2ad99140a40(&local_2e0,0x2ad99183b3c,1,0x2ad99170dc8);
        FUN_2ad99140a40(&local_2f8,&local_308,0);
        lVar11 = local_2dc;
        if (local_2dc == 0) {
LAB_2ad9915ba54:
          (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_2f8);
          _DAT_2ad99183b10 = 0;
          _DAT_2ad99183b80 = 0;
          DAT_2ad99183b88 = 0;
          cVar9 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,lVar8);
          lVar11 = local_2e8;
          if (cVar9 == '\0') {
LAB_2ad9915bbe4:
            puVar13 = *(undefined1 **)(lVar11 + 4);
            if (puVar13 != &DAT_2ad9916297c) {
              if (puVar13 != (undefined1 *)0x0) {
                uVar21 = *(uint *)(puVar13 + -4);
                uVar22 = _DAT_2ad99162978;
                if (uVar21 < _DAT_2ad99162978) {
                  uVar22 = uVar21;
                }
                iVar19 = uVar21 - _DAT_2ad99162978;
                if (uVar22 != 0) {
                  uVar25 = 0;
                  do {
                    uVar1 = *(ushort *)(puVar13 + uVar25 * 2);
                    uVar2 = *(ushort *)(&DAT_2ad9916297c + uVar25 * 2);
                    uVar25 = uVar25 + 1;
                    if (uVar22 <= uVar25) break;
                  } while (uVar1 == uVar2);
                  if (uVar1 != uVar2) {
                    iVar19 = (uint)uVar1 - (uint)uVar2;
                  }
                }
                if (iVar19 == 0) goto LAB_2ad9915bc9d;
              }
              cVar9 = FUN_2ad99140c60(puVar13,&DAT_2ad99162a3c,0x15);
              if (cVar9 == '\0') goto LAB_2ad9915ab70;
            }
LAB_2ad9915bc9d:
            _DAT_2ad99173058 = 0;
            goto LAB_2ad9915ab70;
          }
          FUN_2ad99140a40(&local_318,0x2ad99162f40,0,0x2ad99170de8);
          cVar9 = FUN_2ad99140920(&local_318,*(undefined8 *)(lVar11 + 4));
          if (cVar9 == '\0') goto LAB_2ad9915bd33;
          FUN_2ad99140a40(&local_308,&local_318,0,0x2ad99170df8);
          cVar9 = FUN_2ad99140920(&local_308,&DAT_2ad99162f5c);
          uVar34 = extraout_XMM0_Qa;
          if (cVar9 == '\0') goto LAB_2ad9915bd53;
          (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,lVar8,0,0x20);
          FUN_2ad99140a40(&local_2e0,0x2ad99183b3c,1,0x2ad99170e08);
          FUN_2ad99140a40(&local_2f8,&local_308,0,0x2ad99170e18);
          cVar9 = FUN_2ad99140920(&local_2f8,local_2dc);
          if (cVar9 != '\0') {
            (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_2f8);
            goto LAB_2ad9915bbe4;
          }
          goto LAB_2ad9915bd69;
        }
        uVar21 = *(uint *)(local_2dc + -4);
        uVar25 = (ulonglong)uVar21;
        if ((uVar25 == 0) && (local_2f4 != 0)) goto LAB_2ad9915ba54;
        if (local_2f4 == 0) {
          uVar22 = 0;
        }
        else {
          uVar22 = *(uint *)(local_2f4 + -4);
        }
        cVar9 = FUN_2ad99140060(&local_2f8);
        if (cVar9 != '\0') {
          if (uVar25 != 0) {
            lVar27 = local_2f4 + (ulonglong)uVar22 * 2;
            if (uVar21 < 0x10) {
              uVar10 = 0;
            }
            else if ((ulonglong)(lVar27 - lVar11) < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar15 = 0;
              uVar10 = (ulonglong)(uVar21 & 0xfffffff8);
              do {
                uVar34 = ((undefined8 *)(lVar11 + uVar15))[1];
                *(undefined8 *)(lVar27 + uVar15) = *(undefined8 *)(lVar11 + uVar15);
                ((undefined8 *)(lVar27 + uVar15))[1] = uVar34;
                uVar15 = uVar15 + 0x10;
              } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar10 == uVar25) goto LAB_2ad9915ba49;
            }
            do {
              *(undefined2 *)(lVar27 + uVar10 * 2) = *(undefined2 *)(lVar11 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar25 != uVar10);
          }
LAB_2ad9915ba49:
          *(uint *)(local_2f4 + -4) = uVar21 + uVar22;
          *(undefined2 *)(local_2f4 + (ulonglong)(uVar21 + uVar22) * 2) = 0;
          goto LAB_2ad9915ba54;
        }
      }
      else {
        uVar21 = *(uint *)(lVar11 + -4);
        uVar25 = (ulonglong)uVar21;
        if ((uVar25 == 0) && (local_314 != 0)) goto LAB_2ad9915adef;
        if (local_314 == 0) {
          uVar22 = 0;
        }
        else {
          uVar22 = *(uint *)(local_314 + -4);
        }
        cVar9 = FUN_2ad99140060(&local_318);
        if (cVar9 != '\0') {
          if (uVar25 != 0) {
            lVar27 = local_314 + (ulonglong)uVar22 * 2;
            if (uVar21 < 0x10) {
              uVar10 = 0;
            }
            else if ((ulonglong)(lVar27 - lVar11) < 0x20) {
              uVar10 = 0;
            }
            else {
              uVar15 = 0;
              uVar10 = (ulonglong)(uVar21 & 0xfffffff8);
              do {
                uVar35 = ((undefined8 *)(lVar11 + uVar15))[1];
                *(undefined8 *)(lVar27 + uVar15) = *(undefined8 *)(lVar11 + uVar15);
                ((undefined8 *)(lVar27 + uVar15))[1] = uVar35;
                uVar15 = uVar15 + 0x10;
              } while ((uVar25 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar10 == uVar25) goto LAB_2ad9915adda;
            }
            do {
              *(undefined2 *)(lVar27 + uVar10 * 2) = *(undefined2 *)(lVar11 + uVar10 * 2);
              uVar10 = uVar10 + 1;
            } while (uVar25 != uVar10);
          }
LAB_2ad9915adda:
          *(uint *)(local_314 + -4) = uVar21 + uVar22;
          *(undefined2 *)(local_314 + (ulonglong)(uVar21 + uVar22) * 2) = 0;
          goto LAB_2ad9915adef;
        }
LAB_2ad9915bdc9:
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x6c035c000001f9);
LAB_2ad9915bde9:
        (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x27037d000001f9);
      }
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x34037d000001f9);
LAB_2ad9915be29:
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x6d0373000001f9);
LAB_2ad9915be49:
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x4e0377000001f9);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uVar15 = (ulonglong)iVar19;
    uVar10 = 1;
    uVar25 = 9;
    puVar16 = (undefined4 *)0x0;
    do {
      while( true ) {
        if (uVar25 < uVar10) goto LAB_2ad9915a302;
        uVar23 = uVar10 + uVar25 >> 1;
        uVar12 = *(ulonglong *)(uVar23 * 0x10 + 0x2ad99171100);
        if (uVar12 != uVar15) break;
        uVar24 = uVar23;
        if (3 < uVar10 + uVar25) {
          bVar29 = uVar23 != 1;
          puVar17 = (ulonglong *)(uVar23 * 0x10 + 0x2ad991710f0);
          do {
            uVar24 = uVar23;
            if (*puVar17 != uVar15) break;
            uVar23 = uVar23 - 1;
            puVar17 = puVar17 + -2;
            uVar24 = (ulonglong)bVar29;
          } while (1 < uVar23);
        }
        puVar16 = *(undefined4 **)(uVar24 * 0x10 + 0x2ad99171108);
        if (uVar12 == uVar15) goto LAB_2ad9915a302;
      }
      uVar24 = uVar23 - 1;
      if ((longlong)uVar12 <= (longlong)uVar15) {
        uVar10 = uVar23 + 1;
        uVar24 = uVar25;
      }
      uVar25 = uVar24;
    } while (uVar12 != uVar15);
LAB_2ad9915a302:
    if (puVar16 == (undefined4 *)0x0) {
      local_178 = _DAT_2ad99170f40;
      local_188 = (undefined4)_DAT_2ad99170f30;
      uStack_184 = (undefined4)((ulonglong)_DAT_2ad99170f30 >> 0x20);
      uStack_180 = (undefined4)uRam000002ad99170f38;
      uStack_17c = (undefined4)((ulonglong)uRam000002ad99170f38 >> 0x20);
      _uStack_170 = CONCAT26(0x3a,(int6)uRam000002ad99170f48);
      local_168 = 0x3a;
      if (iVar19 < 0) {
        uVar15 = -uVar15;
        local_166[0] = 0x2d;
      }
      uVar10 = (ulonglong)(iVar19 < 0);
      uVar25 = 0;
      do {
        uVar12 = uVar25;
        *(byte *)((longlong)&local_1af + uVar12 + 7) =
             (char)uVar15 + (char)(uVar15 / 10) * -10 | 0x30;
        uVar25 = uVar12 + 1;
        bVar29 = 9 < uVar15;
        uVar15 = uVar15 / 10;
      } while (bVar29);
      if (uVar25 < 8) {
LAB_2ad9915aa60:
        do {
          uVar15 = uVar10 + 1;
          uVar12 = uVar25 - 1;
          local_166[uVar10] = (short)*(char *)((longlong)&local_1af + uVar25 + 6);
          uVar25 = uVar12;
          uVar10 = uVar15;
        } while (uVar12 != 0);
      }
      else {
        puVar17 = (ulonglong *)((longlong)&local_1af + uVar12);
        pauVar26 = (undefined1 (*) [16])(local_166 + uVar10);
        uVar12 = uVar25 & 0xfffffffffffffff8;
        uVar10 = uVar10 | uVar12;
        uVar15 = uVar12;
        do {
          uVar23 = *puVar17;
          puVar17 = puVar17 + -1;
          uVar45 = (undefined1)(uVar23 >> 0x38);
          auVar42._8_6_ = 0;
          auVar42._0_8_ = uVar23;
          auVar42[0xe] = uVar45;
          auVar42[0xf] = uVar45;
          uVar45 = (undefined1)(uVar23 >> 0x30);
          auVar41._14_2_ = auVar42._14_2_;
          auVar41._8_5_ = 0;
          auVar41._0_8_ = uVar23;
          auVar41[0xd] = uVar45;
          auVar40._13_3_ = auVar41._13_3_;
          auVar40._8_4_ = 0;
          auVar40._0_8_ = uVar23;
          auVar40[0xc] = uVar45;
          uVar45 = (undefined1)(uVar23 >> 0x28);
          auVar39._12_4_ = auVar40._12_4_;
          auVar39._8_3_ = 0;
          auVar39._0_8_ = uVar23;
          auVar39[0xb] = uVar45;
          auVar38._11_5_ = auVar39._11_5_;
          auVar38._8_2_ = 0;
          auVar38._0_8_ = uVar23;
          auVar38[10] = uVar45;
          uVar45 = (undefined1)(uVar23 >> 0x20);
          auVar37._10_6_ = auVar38._10_6_;
          auVar37[8] = 0;
          auVar37._0_8_ = uVar23;
          auVar37[9] = uVar45;
          auVar36._9_7_ = auVar37._9_7_;
          auVar36[8] = uVar45;
          auVar36._0_8_ = uVar23;
          uVar45 = (undefined1)(uVar23 >> 0x18);
          auVar7._4_8_ = auVar36._8_8_;
          auVar7[3] = uVar45;
          auVar7[2] = uVar45;
          uVar45 = (undefined1)(uVar23 >> 0x10);
          auVar7[1] = uVar45;
          auVar7[0] = uVar45;
          uVar45 = (undefined1)(uVar23 >> 8);
          auVar44._4_12_ = auVar7;
          auVar44[3] = uVar45;
          auVar44[2] = uVar45;
          auVar44[0] = (undefined1)uVar23;
          auVar44[1] = auVar44[0];
          auVar43._8_4_ = auVar44._0_4_;
          auVar43._0_8_ = auVar36._8_8_;
          auVar43._12_4_ = auVar7._0_4_;
          auVar44 = pshuflw(auVar43,auVar43,0x1b);
          auVar44 = pshufhw(auVar44,auVar44,0x1b);
          auVar44 = psraw(auVar44,8);
          *pauVar26 = auVar44;
          pauVar26 = pauVar26 + 1;
          uVar15 = uVar15 - 8;
        } while (uVar15 != 0);
        bVar29 = uVar25 != uVar12;
        uVar25 = (ulonglong)((uint)uVar25 & 7);
        if (bVar29) goto LAB_2ad9915aa60;
      }
      puVar16 = &local_188;
      local_166[uVar10] = 0;
      _DAT_2ad99183b10 = 0xfa3;
    }
    FUN_2ad991401d0(&local_2d0,puVar16,0xffffffff);
    (*(code *)0x7ff63a0e49f0)
              (0x2ad95e68178,2,8,0x590008,0x2ad99163238,CONCAT44(uVar52,0x590008),&local_2d0,
               0x590008,0x2ad99163048,0x580007,dVar32,0x590008,0x2ad99163048,0x590008,&local_318,
               0x590008,0x2ad99163278,0x520004,uVar49);
  }
  FUN_2ad99140000(&local_2d0);
LAB_2ad9915ab70:
  FUN_2ad99140000(&local_27c);
  FUN_2ad99140000(&local_318);
  FUN_2ad99140000(&local_308);
  FUN_2ad99140000(&local_2e0);
  FUN_2ad99140000(&local_2f8);
  return;
}



/* Address: 2ad9915be70 */

ulonglong FUN_2ad9915be70(undefined8 param_1)

{
  undefined8 unaff_RSI;
  ulonglong uVar1;
  longlong lVar2;
  int local_70 [3];
  int local_64;
  int local_54;
  int local_50 [3];
  int local_44;
  int local_34;
  
  uVar1 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (DAT_2ad99178401 != '\0') {
    (*(code *)0x7ff63a101f60)(0x2ad95e68178,param_1,local_50);
    lVar2 = 0;
    do {
      (*(code *)0x7ff63a101f60)(0x2ad95e68178,*(undefined8 *)(lVar2 + 0x2ad991785e0),local_70);
      if (local_70[0] < local_50[0]) break;
      if (((local_50[0] == local_70[0]) && (local_34 == local_54)) && (local_44 == local_64)) {
        uVar1 = 0;
        break;
      }
      lVar2 = lVar2 + 8;
    } while (lVar2 != 0xb510);
  }
  return uVar1 & 0xffffffff;
}



/* Address: 2ad9915bf20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ad9915bf20(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined4 local_90;
  longlong local_8c;
  longlong local_80;
  ulonglong local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined4 local_48;
  
  local_90 = 0;
  local_8c = 0;
  uVar12 = 0;
  local_78 = 0x800110054;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  uStack_5c = 0;
  local_58 = 0;
  uStack_54 = 0;
  local_50 = 0;
  local_48 = 0;
  FUN_2ad99140e80(0,_DAT_2ad99183b24,&local_78);
  if ((local_70 & 0xffffffff) == 0) {
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1d0435000001f6);
    pcVar4 = (code *)swi(3);
    uVar12 = (*pcVar4)();
    return uVar12;
  }
  uVar14 = (local_70 & 0xffffffff) - 1;
  if ((local_78 & 0x100000) == 0) {
    uVar14 = uVar12;
  }
  uVar10 = *(undefined8 *)(CONCAT44(local_58,uStack_5c) + uVar14 * 8);
  uVar9 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  cVar5 = (*(code *)0x7ff63a1084f0)(0x2ad95e68178,uVar10,uVar9);
  if ((cVar5 != '\0') && (iVar6 = (*(code *)0x7ff63a108810)(0x2ad95e68178), 0 < iVar6)) {
    uVar12 = 0;
    iVar6 = 0;
    local_80 = (longlong)_DAT_2ad99183c78;
    do {
      uVar10 = (*(code *)0x7ff63a108860)(0x2ad95e68178,iVar6);
      uVar8 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar10,3);
      lVar11 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar10,4);
      if ((uVar8 & 0xfffffffe) == 0 && lVar11 == 0) {
        (*(code *)0x7ff63a1089d0)(0x2ad95e68178,uVar10,0);
        FUN_2ad99140a40(&local_90,0x2ad99183b3c,1,0x2ad99170e78);
        if (local_8c == _DAT_2ad99183b2c) {
LAB_2ad9915c060:
          lVar11 = (*(code *)0x7ff63a108940)(0x2ad95e68178,uVar10,0xb);
          uVar12 = (ulonglong)((int)uVar12 + (uint)(lVar11 == local_80));
        }
        else if ((local_8c != 0) && (_DAT_2ad99183b2c != 0)) {
          uVar8 = *(uint *)(local_8c + -4);
          uVar3 = *(uint *)(_DAT_2ad99183b2c + -4);
          uVar13 = uVar3;
          if (uVar8 < uVar3) {
            uVar13 = uVar8;
          }
          iVar7 = uVar8 - uVar3;
          if (uVar13 != 0) {
            uVar14 = 1;
            do {
              uVar1 = *(ushort *)(local_8c + -2 + uVar14 * 2);
              uVar2 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar14 * 2);
              if (uVar13 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar7 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar7 == 0) goto LAB_2ad9915c060;
        }
      }
      iVar6 = iVar6 + 1;
      iVar7 = (*(code *)0x7ff63a108810)(0x2ad95e68178);
    } while (iVar6 < iVar7);
  }
  (*(code *)0x7ff63a0d9d20)(0x2ad95e68178,&local_78);
  FUN_2ad99140000(&local_90);
  return uVar12;
}



/* Address: 2ad9915c1f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915c1f0(int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  code *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  longlong lVar16;
  ulonglong uVar17;
  uint uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  uint uVar21;
  undefined4 local_178;
  longlong local_174;
  undefined4 local_168;
  longlong local_164;
  undefined4 local_158;
  undefined8 local_154;
  undefined4 local_148;
  longlong local_144;
  undefined4 local_138;
  undefined8 local_134;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  longlong local_110;
  int local_108;
  undefined8 local_104;
  longlong local_fc;
  undefined8 local_f4;
  undefined8 local_ec;
  undefined8 local_e4;
  undefined8 local_dc;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  
  local_178 = 0;
  local_168 = 0;
  local_148 = 0;
  local_174 = 0;
  local_164 = 0;
  local_144 = 0;
  (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
  local_d4 = 0;
  local_d0 = 0;
  iVar13 = (*(code *)0x7ff63a107da0)(0x2ad95e68178);
  if (-1 < iVar13 + -1) {
    local_120 = (longlong)param_1;
    local_118 = (longlong)_DAT_2ad99183c78;
    iVar13 = iVar13 + -1;
    do {
      uVar15 = (*(code *)0x7ff63a107df0)(0x2ad95e68178,iVar13);
      cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar15);
      if (cVar12 != '\0') {
        (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
        FUN_2ad99140a40(&local_148,0x2ad99183b3c,1,0x2ad99170e28);
        if (local_144 == _DAT_2ad99183b2c) {
LAB_2ad9915c3ff:
          lVar16 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,0xc);
          if ((lVar16 == local_118) &&
             (lVar16 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178,2), lVar16 == local_120)) {
            uVar21 = 0;
            local_110 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
            do {
              lVar16 = (*(code *)0x7ff63a101c40)(0x2ad95e68178,0);
              if (((9 < lVar16 - local_110) || (0x13 < uVar21)) || (_DAT_2ad99183b14 != 0)) break;
              lVar16 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
              if (lVar16 == 0) {
LAB_2ad9915cceb:
                (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1803c5000001fa);
                goto LAB_2ad9915cd0b;
              }
              local_138 = 0;
              local_158 = 0;
              local_134 = 0;
              local_154 = 0;
              if (_DAT_2ad99183b14 == 0) {
                cVar12 = (*(code *)0x7ff63a107ee0)(0x2ad95e68178,uVar15);
                if (cVar12 == '\0') {
                  cVar12 = '\0';
                }
                else {
                  local_158 = 0;
                  local_154 = 0;
                  (*(code *)0x7ff63a108010)(0x2ad95e68178,0);
                  FUN_2ad99140a40(&local_138,0x2ad99183b3c,1,0x2ad9916ffb8);
                  FUN_2ad99140a40(&local_158,&local_138,0,0x2ad9916ffc8);
                  local_128 = lVar16 + 0x34;
                  *(undefined4 *)(lVar16 + 0x30) = 0;
                  *(undefined8 *)(lVar16 + 0x28) = 0;
                  *(undefined8 *)(lVar16 + 0x20) = 0;
                  FUN_2ad99140000();
                  *(undefined4 *)(lVar16 + 0x80) = 0;
                  *(undefined8 *)(lVar16 + 0x78) = 0;
                  *(undefined8 *)(lVar16 + 0x70) = 0;
                  *(undefined8 *)(lVar16 + 0x68) = 0;
                  *(undefined8 *)(lVar16 + 0x60) = 0;
                  *(undefined8 *)(lVar16 + 0x58) = 0;
                  *(undefined8 *)(lVar16 + 0x50) = 0;
                  *(undefined8 *)(lVar16 + 0x48) = 0;
                  *(undefined8 *)(lVar16 + 0x40) = 0;
                  FUN_2ad99140000(lVar16 + 0x84);
                  (*(code *)0x7ff63a3fad20)(lVar16 + 0x90,0,0xb4);
                  FUN_2ad99140000(lVar16 + 0x144);
                  (*(code *)0x7ff63a3fad20)(lVar16 + 0x150,0,0xb8);
                  FUN_2ad99140000(lVar16 + 0x208);
                  *(undefined8 *)(lVar16 + 0x28c) = 0;
                  *(undefined8 *)(lVar16 + 0x284) = 0;
                  *(undefined8 *)(lVar16 + 0x27c) = 0;
                  *(undefined8 *)(lVar16 + 0x274) = 0;
                  *(undefined8 *)(lVar16 + 0x26c) = 0;
                  *(undefined8 *)(lVar16 + 0x264) = 0;
                  *(undefined8 *)(lVar16 + 0x25c) = 0;
                  *(undefined8 *)(lVar16 + 0x254) = 0;
                  *(undefined8 *)(lVar16 + 0x24c) = 0;
                  *(undefined8 *)(lVar16 + 0x244) = 0;
                  *(undefined8 *)(lVar16 + 0x23c) = 0;
                  *(undefined8 *)(lVar16 + 0x234) = 0;
                  *(undefined8 *)(lVar16 + 0x22c) = 0;
                  *(undefined8 *)(lVar16 + 0x224) = 0;
                  *(undefined8 *)(lVar16 + 0x21c) = 0;
                  *(undefined8 *)(lVar16 + 0x214) = 0;
                  cVar12 = FUN_2ad991566c0(lVar16,&local_158);
                  if (cVar12 == '\0') {
                    FUN_2ad99140000(&local_158);
                    cVar12 = '\0';
                  }
                  else {
                    iVar14 = (*(code *)0x7ff63a107fc0)(0x2ad95e68178);
                    *(uint *)(lVar16 + 0x70) = (uint)(iVar14 == 0);
                    (*(code *)0x7ff63a0f2890)
                              (0x2ad95e68178,&local_158,(iVar14 != 0) * '\x03' + '\x01');
                    *(undefined8 *)(lVar16 + 0x48) = _DAT_2ad99183b48;
                    *(undefined4 *)(lVar16 + 0x20) = 1;
                    *(undefined8 *)(lVar16 + 0x90) = uVar15;
                    FUN_2ad99140a40(local_128,&local_158,0,0x2ad9916ffd8);
                    (*(code *)0x7ff63a107f70)(0x2ad95e68178,3);
                    *(undefined8 *)(lVar16 + 0x40) = _DAT_2ad99183b48;
                    *(undefined8 *)(lVar16 + 0x24) = *(undefined8 *)(lVar16 + 0x295);
                    *(undefined8 *)(lVar16 + 0x68) = *(undefined8 *)(lVar16 + 0x29d);
                    cVar12 = FUN_2ad99140f70(lVar16,lVar16 + 0x20,lVar16 + 0x110);
                    FUN_2ad99140000(&local_158);
                  }
                }
              }
              else {
                (*(code *)0x7ff63a0e49f0)
                          (0x2ad95e68178,0xd,2,0x590008,0x2ad99162960,0x590008,0x2ad99161928);
                *(undefined4 *)(lVar16 + 0x110) = 0x272b;
                cVar12 = '\0';
              }
              FUN_2ad99140000(&local_138);
              lVar16 = (*(code *)0x7ff63a0e6410)(0x2ad95e68178,_DAT_2ad99178420);
              if (lVar16 == 0) {
                (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xf03c6000001fa);
                goto LAB_2ad9915cceb;
              }
              local_108 = *(int *)(lVar16 + 0x110);
              local_104 = *(undefined8 *)(lVar16 + 0x114);
              local_fc = *(longlong *)(lVar16 + 0x11c);
              local_f4 = *(undefined8 *)(lVar16 + 0x124);
              local_ec = *(undefined8 *)(lVar16 + 300);
              local_e4 = *(undefined8 *)(lVar16 + 0x134);
              local_dc = *(undefined8 *)(lVar16 + 0x13c);
              FUN_2ad99140a40(&local_d4,lVar16 + 0x144,0,0x2ad9916ff58);
              local_c8 = *(undefined4 *)(lVar16 + 0x150);
              local_c4 = *(undefined4 *)(lVar16 + 0x154);
              if (local_fc != 0) goto LAB_2ad9915c9b2;
              if (local_108 == 0x2734) goto LAB_2ad9915cc97;
              (*(code *)0x7ff63a0e17c0)(0x2ad95e68178);
              uVar21 = uVar21 + 1;
            } while (cVar12 == '\0');
            if (local_fc == 0) {
              (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,local_108,0,0x20);
              FUN_2ad99140a40(&local_168,0x2ad99183b3c,1,0x2ad99170e38);
              FUN_2ad99140a40(&local_178,0x2ad99162fd0,0);
              lVar16 = local_164;
              if (local_164 != 0) {
                uVar21 = *(uint *)(local_164 + -4);
                uVar20 = (ulonglong)uVar21;
                if ((uVar20 != 0) || (local_174 == 0)) {
                  if (local_174 == 0) {
                    uVar17 = 0;
                    uVar18 = uVar21;
                  }
                  else {
                    uVar17 = (ulonglong)*(uint *)(local_174 + -4);
                    uVar18 = uVar21 + *(uint *)(local_174 + -4);
                  }
                  cVar12 = FUN_2ad99140060(&local_178);
                  if (cVar12 == '\0') goto LAB_2ad9915cd2b;
                  if (uVar20 != 0) {
                    lVar1 = local_174 + uVar17 * 2;
                    if (uVar21 < 8) {
                      uVar17 = 0;
                    }
                    else if ((ulonglong)(lVar1 - lVar16) < 0x20) {
                      uVar17 = 0;
                    }
                    else {
                      uVar19 = 0;
                      uVar17 = (ulonglong)(uVar21 & 0xfffffff8);
                      do {
                        puVar2 = (undefined4 *)(lVar16 + uVar19);
                        uVar9 = puVar2[1];
                        uVar10 = puVar2[2];
                        uVar11 = puVar2[3];
                        puVar3 = (undefined4 *)(lVar1 + uVar19);
                        *puVar3 = *puVar2;
                        puVar3[1] = uVar9;
                        puVar3[2] = uVar10;
                        puVar3[3] = uVar11;
                        uVar19 = uVar19 + 0x10;
                      } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar19);
                      if (uVar17 == uVar20) goto LAB_2ad9915c2cd;
                    }
                    do {
                      *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar16 + uVar17 * 2);
                      uVar17 = uVar17 + 1;
                    } while (uVar20 != uVar17);
                  }
                  goto LAB_2ad9915c2cd;
                }
              }
            }
            else {
LAB_2ad9915c9b2:
              (*(code *)0x7ff63a0fdfe0)(0x2ad95e68178,uVar15,0,0x20);
              FUN_2ad99140a40(&local_168,0x2ad99183b3c,1,0x2ad99170e58);
              FUN_2ad99140a40(&local_178,0x2ad99163028,0);
              lVar16 = local_164;
              if (local_164 != 0) {
                uVar21 = *(uint *)(local_164 + -4);
                uVar20 = (ulonglong)uVar21;
                if ((uVar20 != 0) || (local_174 == 0)) {
                  if (local_174 == 0) {
                    uVar17 = 0;
                    uVar18 = uVar21;
                  }
                  else {
                    uVar17 = (ulonglong)*(uint *)(local_174 + -4);
                    uVar18 = uVar21 + *(uint *)(local_174 + -4);
                  }
                  cVar12 = FUN_2ad99140060(&local_178);
                  if (cVar12 == '\0') {
LAB_2ad9915cd0b:
                    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3403d6000001f9);
LAB_2ad9915cd2b:
                    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x3f03d3000001f9);
                    pcVar7 = (code *)swi(3);
                    (*pcVar7)();
                    return;
                  }
                  if (uVar20 != 0) {
                    lVar1 = local_174 + uVar17 * 2;
                    if (uVar21 < 8) {
                      uVar17 = 0;
                    }
                    else if ((ulonglong)(lVar1 - lVar16) < 0x20) {
                      uVar17 = 0;
                    }
                    else {
                      uVar19 = 0;
                      uVar17 = (ulonglong)(uVar21 & 0xfffffff8);
                      do {
                        puVar2 = (undefined4 *)(lVar16 + uVar19);
                        uVar9 = puVar2[1];
                        uVar10 = puVar2[2];
                        uVar11 = puVar2[3];
                        puVar3 = (undefined4 *)(lVar1 + uVar19);
                        *puVar3 = *puVar2;
                        puVar3[1] = uVar9;
                        puVar3[2] = uVar10;
                        puVar3[3] = uVar11;
                        uVar19 = uVar19 + 0x10;
                      } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar19);
                      if (uVar17 == uVar20) goto LAB_2ad9915c2cd;
                    }
                    do {
                      *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar16 + uVar17 * 2);
                      uVar17 = uVar17 + 1;
                    } while (uVar20 != uVar17);
                  }
LAB_2ad9915c2cd:
                  *(uint *)(local_174 + -4) = uVar18;
                  *(undefined2 *)(local_174 + (ulonglong)uVar18 * 2) = 0;
                }
              }
            }
            (*(code *)0x7ff63a0e49f0)(0x2ad95e68178,2,1,0x590008,&local_178);
          }
        }
        else if ((local_144 != 0) && (_DAT_2ad99183b2c != 0)) {
          uVar21 = *(uint *)(local_144 + -4);
          uVar18 = *(uint *)(_DAT_2ad99183b2c + -4);
          uVar8 = uVar18;
          if (uVar21 < uVar18) {
            uVar8 = uVar21;
          }
          iVar14 = uVar21 - uVar18;
          if (uVar8 != 0) {
            uVar20 = 1;
            do {
              uVar4 = *(ushort *)(local_144 + -2 + uVar20 * 2);
              uVar5 = *(ushort *)(_DAT_2ad99183b2c + -2 + uVar20 * 2);
              if (uVar8 <= uVar20) break;
              uVar20 = uVar20 + 1;
            } while (uVar4 == uVar5);
            if (uVar4 != uVar5) {
              iVar14 = (uint)uVar4 - (uint)uVar5;
            }
          }
          if (iVar14 == 0) goto LAB_2ad9915c3ff;
        }
      }
      bVar6 = 0 < iVar13;
      iVar13 = iVar13 + -1;
    } while (bVar6);
  }
LAB_2ad9915cc97:
  FUN_2ad99140000(&local_d4);
  FUN_2ad99140000(&local_148);
  FUN_2ad99140000(&local_168);
  FUN_2ad99140000(&local_178);
  return;
}



/* Address: 2ad9915cd50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ad9915cd50(double param_1)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x22);
  dVar5 = _DAT_2ad99183b48;
  uVar8 = SUB84(_DAT_2ad99183b48,0);
  uVar9 = (undefined4)((ulonglong)_DAT_2ad99183b48 >> 0x20);
  (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x23);
  dVar6 = _DAT_2ad99183b48;
  (*(code *)0x7ff63a0f2890)(0x2ad95e68178,0x2ad99160ca0,0x24);
  if (dVar5 <= param_1) {
    uVar8 = SUB84(param_1,0);
    uVar9 = (undefined4)((ulonglong)param_1 >> 0x20);
  }
  lVar2 = 2;
  if ((double)CONCAT44(uVar9,uVar8) <= dVar6) {
    dVar6 = (double)CONCAT44(uVar9,uVar8);
  }
  if (_DAT_2ad99160ae0 <= _DAT_2ad99183b48) {
    if ((_DAT_2ad99183b48 != _DAT_2ad99160ae8) || (NAN(_DAT_2ad99183b48) || NAN(_DAT_2ad99160ae8)))
    {
      if ((_DAT_2ad99183b48 == _DAT_2ad99160af0) &&
         (!NAN(_DAT_2ad99183b48) && !NAN(_DAT_2ad99160af0))) {
        dVar6 = dVar6 + dVar6;
        if ((longlong)dVar6 != -0x8000000000000000) {
          dVar5 = (double)(longlong)dVar6;
          dVar6 = (double)(longlong)
                          ((dVar6 - dVar5) * _DAT_2ad99160af8 +
                          *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2ad99160b00)) /
                  _DAT_2ad99160af8 + dVar5;
        }
        dVar6 = dVar6 * _DAT_2ad99160b10;
        if ((longlong)dVar6 == -0x8000000000000000) {
          return dVar6;
        }
        dVar5 = (double)(longlong)dVar6;
        return (double)(longlong)
                       ((dVar6 - dVar5) * _DAT_2ad99160b18 +
                       *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2ad99160b00)) / _DAT_2ad99160b18
               + dVar5;
      }
      lVar2 = 1;
    }
    else {
      lVar2 = 0;
    }
  }
  dVar5 = (double)(~-(ulonglong)(_DAT_2ad99183b48 == 0.0) & (ulonglong)_DAT_2ad99183b48 |
                  (ulonglong)_DAT_2ad99160ae8 & -(ulonglong)(_DAT_2ad99183b48 == 0.0));
  dVar6 = dVar6 / dVar5;
  uVar4 = (uint)((ulonglong)dVar6 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar4 - 0x3ff;
  dVar7 = dVar6;
  if ((ulonglong)uVar4 < 0x433) {
    if (uVar4 < 0x3ff) {
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
  dVar7 = dVar7 * dVar5;
  if ((longlong)dVar7 != -0x8000000000000000) {
    dVar6 = (double)(longlong)dVar7;
    dVar7 = (double)(longlong)
                    ((dVar7 - dVar6) * *(double *)(&DAT_2ad99160b20 + lVar2 * 8) +
                    *(double *)((ulonglong)(0.0 < dVar7) * 8 + 0x2ad99160b00)) /
            *(double *)(&DAT_2ad99160b20 + lVar2 * 8) + dVar6;
  }
  return dVar7;
}



/* Address: 2ad9915cf40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ad9915cf40(ulonglong *param_1,double param_2)

{
  longlong lVar1;
  byte bVar2;
  ulonglong unaff_RBX;
  uint uVar3;
  double dVar4;
  double dVar5;
  double unaff_XMM6_Qa;
  double dVar6;
  
  if ((param_2 != _DAT_2ad99160af0) || (NAN(param_2) || NAN(_DAT_2ad99160af0))) {
    dVar4 = (double)(~-(ulonglong)(param_2 == 0.0) & (ulonglong)param_2 |
                    *param_1 & -(ulonglong)(param_2 == 0.0));
    dVar5 = unaff_XMM6_Qa / dVar4;
    uVar3 = (uint)((ulonglong)dVar5 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar3 - 0x3ff;
    dVar6 = dVar5;
    if ((ulonglong)uVar3 < 0x433) {
      if (uVar3 < 0x3ff) {
        dVar6 = (double)((ulonglong)dVar5 & unaff_RBX | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar6 = (double)((ulonglong)dVar5 & unaff_RBX);
        }
      }
      else {
        bVar2 = (byte)lVar1;
        if (((longlong)dVar5 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar6 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar5 &
                          -0x10000000000000 >> (bVar2 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar6 = dVar5 + dVar5;
    }
    dVar6 = dVar6 * dVar4;
    if ((longlong)dVar6 != unaff_RBX) {
      dVar4 = (double)(longlong)dVar6;
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar4) * dRam000002ad99160b28 +
                      *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2ad99160b00)) /
              dRam000002ad99160b28 + dVar4;
    }
  }
  else {
    dVar6 = unaff_XMM6_Qa + unaff_XMM6_Qa;
    if ((longlong)dVar6 != unaff_RBX) {
      dVar4 = (double)(longlong)dVar6;
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar4) * _DAT_2ad99160af8 +
                      *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2ad99160b00)) / _DAT_2ad99160af8
              + dVar4;
    }
    dVar6 = dVar6 * _DAT_2ad99160b10;
    if ((longlong)dVar6 != unaff_RBX) {
      dVar4 = (double)(longlong)dVar6;
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar4) * _DAT_2ad99160b18 +
                      *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2ad99160b00)) / _DAT_2ad99160b18
              + dVar4;
    }
  }
  return dVar6;
}



/* Address: 2ad9915d030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915d030(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char cVar12;
  uint uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint uVar16;
  longlong lVar17;
  ulonglong uVar18;
  uint uVar19;
  ulonglong uVar20;
  bool bVar21;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  longlong local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  undefined1 local_60 [12];
  int local_54;
  
  local_90 = 0;
  local_70 = 0;
  local_8c = 0;
  local_6c = 0;
  (*(code *)0x7ff63a101f60)(0x2ad95e68178,param_1,local_60);
  local_80 = 0;
  local_7c = 0;
  FUN_2ad99140a40(&local_80,0x2ad99160d08,0,0x2ad99171200);
  lVar17 = 0;
  do {
    iVar5 = *(int *)(&DAT_2ad991783b0 + lVar17 * 8);
    iVar6 = *(int *)(&DAT_2ad991783b4 + lVar17 * 8);
    if (iVar5 < iVar6) {
      if ((iVar5 <= local_54) && (local_54 < iVar6)) {
        FUN_2ad99140a40(&local_90,&DAT_2ad991783d0 + lVar17 * 0xc);
        uVar7 = _DAT_2ad9916303c;
        uVar20 = (ulonglong)_DAT_2ad9916303c;
        if ((uVar20 == 0) && (local_8c != 0)) {
LAB_2ad9915d16d:
          uVar7 = *(uint *)(local_8c + -4);
          lVar1 = local_8c;
        }
        else {
          if (local_8c == 0) {
            uVar19 = 0;
            uVar16 = _DAT_2ad9916303c;
          }
          else {
            uVar19 = *(uint *)(local_8c + -4);
            uVar16 = _DAT_2ad9916303c + uVar19;
          }
          uVar13 = 0x104;
          if ((0x103 < uVar16) &&
             ((0x7ffffffd < uVar16 || (uVar13 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar13)))) {
            uVar13 = 0x7ffffffe;
          }
          cVar12 = FUN_2ad99140060(&local_90,uVar13);
          if (cVar12 == '\0') {
LAB_2ad9915d74b:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2207cc000001f9);
LAB_2ad9915d76b:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1007d0000001f9);
            goto LAB_2ad9915d78b;
          }
          if (uVar20 == 0) {
            *(uint *)(local_8c + -4) = uVar16;
            *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
            if (local_8c == 0) goto LAB_2ad9915d0f6;
            goto LAB_2ad9915d16d;
          }
          lVar1 = local_8c + (ulonglong)uVar19 * 2;
          if (uVar7 < 8) {
            uVar14 = 0;
          }
          else {
            if (0x1f < local_8c + -0x2ad99163040 + (ulonglong)uVar19 * 2) {
              uVar15 = 0;
              uVar14 = (ulonglong)(uVar7 & 0xfffffff8);
              do {
                uVar9 = *(undefined4 *)(&DAT_2ad99163044 + uVar15);
                uVar10 = *(undefined4 *)(uVar15 + 0x2ad99163048);
                uVar11 = *(undefined4 *)(uVar15 + 0x2ad9916304c);
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *(undefined4 *)(&DAT_2ad99163040 + uVar15);
                puVar3[1] = uVar9;
                puVar3[2] = uVar10;
                puVar3[3] = uVar11;
                uVar15 = uVar15 + 0x10;
                if ((uVar20 * 2 & 0xfffffffffffffff0) == uVar15) goto joined_r0x02ad9915d526;
              } while( true );
            }
            uVar14 = 0;
          }
          do {
            *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_2ad99163040 + uVar14 * 2);
            uVar14 = uVar14 + 1;
joined_r0x02ad9915d526:
          } while (uVar14 != uVar20);
          *(uint *)(local_8c + -4) = uVar16;
          *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
          uVar7 = *(uint *)(local_8c + -4);
          lVar1 = local_8c;
        }
        uVar20 = (ulonglong)uVar7;
        local_8c = lVar1;
        if ((uVar20 != 0) || (local_7c == 0)) {
          if (local_7c == 0) {
            uVar19 = 0;
            uVar14 = uVar20;
          }
          else {
            uVar19 = *(uint *)(local_7c + -4);
            uVar14 = (ulonglong)(uVar7 + uVar19);
          }
          cVar12 = FUN_2ad99140060(&local_80);
          if (cVar12 == '\0') {
LAB_2ad9915d78b:
            (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1007cc000001f9);
            pcVar8 = (code *)swi(3);
            (*pcVar8)();
            return;
          }
          if (uVar20 != 0) {
            lVar2 = local_7c + (ulonglong)uVar19 * 2;
            if (uVar7 < 8) {
              uVar15 = 0;
            }
            else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
              uVar15 = 0;
            }
            else {
              uVar18 = 0;
              uVar15 = (ulonglong)(uVar7 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar1 + uVar18);
                uVar9 = puVar3[1];
                uVar10 = puVar3[2];
                uVar11 = puVar3[3];
                puVar4 = (undefined4 *)(lVar2 + uVar18);
                *puVar4 = *puVar3;
                puVar4[1] = uVar9;
                puVar4[2] = uVar10;
                puVar4[3] = uVar11;
                uVar18 = uVar18 + 0x10;
              } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar18);
              if (uVar15 == uVar20) goto LAB_2ad9915d0e9;
            }
            do {
              *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(lVar1 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar20 != uVar15);
          }
LAB_2ad9915d0e9:
          *(int *)(local_7c + -4) = (int)uVar14;
          *(undefined2 *)(local_7c + uVar14 * 2) = 0;
        }
      }
    }
    else if ((iVar5 <= local_54) || (local_54 < iVar6)) {
      FUN_2ad99140a40(&local_90,&DAT_2ad991783d0 + lVar17 * 0xc,0);
      uVar7 = _DAT_2ad9916303c;
      uVar20 = (ulonglong)_DAT_2ad9916303c;
      if ((uVar20 == 0) && (local_8c != 0)) {
LAB_2ad9915d1e8:
        uVar7 = *(uint *)(local_8c + -4);
        lVar1 = local_8c;
      }
      else {
        if (local_8c == 0) {
          uVar19 = 0;
          uVar16 = _DAT_2ad9916303c;
        }
        else {
          uVar19 = *(uint *)(local_8c + -4);
          uVar16 = _DAT_2ad9916303c + uVar19;
        }
        uVar13 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar13 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar13)))) {
          uVar13 = 0x7ffffffe;
        }
        cVar12 = FUN_2ad99140060(&local_90,uVar13);
        if (cVar12 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2207d0000001f9);
          goto LAB_2ad9915d74b;
        }
        if (uVar20 == 0) {
          *(uint *)(local_8c + -4) = uVar16;
          *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
          if (local_8c == 0) goto LAB_2ad9915d0f6;
          goto LAB_2ad9915d1e8;
        }
        lVar1 = local_8c + (ulonglong)uVar19 * 2;
        if (uVar7 < 8) {
          uVar14 = 0;
        }
        else {
          if (0x1f < local_8c + -0x2ad99163040 + (ulonglong)uVar19 * 2) {
            uVar15 = 0;
            uVar14 = (ulonglong)(uVar7 & 0xfffffff8);
            do {
              uVar9 = *(undefined4 *)(&DAT_2ad99163044 + uVar15);
              uVar10 = *(undefined4 *)(uVar15 + 0x2ad99163048);
              uVar11 = *(undefined4 *)(uVar15 + 0x2ad9916304c);
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              *puVar3 = *(undefined4 *)(&DAT_2ad99163040 + uVar15);
              puVar3[1] = uVar9;
              puVar3[2] = uVar10;
              puVar3[3] = uVar11;
              uVar15 = uVar15 + 0x10;
              if ((uVar20 * 2 & 0xfffffffffffffff0) == uVar15) goto joined_r0x02ad9915d406;
            } while( true );
          }
          uVar14 = 0;
        }
        do {
          *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_2ad99163040 + uVar14 * 2);
          uVar14 = uVar14 + 1;
joined_r0x02ad9915d406:
        } while (uVar14 != uVar20);
        *(uint *)(local_8c + -4) = uVar16;
        *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
        uVar7 = *(uint *)(local_8c + -4);
        lVar1 = local_8c;
      }
      uVar20 = (ulonglong)uVar7;
      local_8c = lVar1;
      if ((uVar20 != 0) || (local_7c == 0)) {
        if (local_7c == 0) {
          uVar19 = 0;
          uVar14 = uVar20;
        }
        else {
          uVar19 = *(uint *)(local_7c + -4);
          uVar14 = (ulonglong)(uVar7 + uVar19);
        }
        cVar12 = FUN_2ad99140060(&local_80);
        if (cVar12 == '\0') goto LAB_2ad9915d76b;
        if (uVar20 != 0) {
          lVar2 = local_7c + (ulonglong)uVar19 * 2;
          if (uVar7 < 8) {
            uVar15 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar18 = 0;
            uVar15 = (ulonglong)(uVar7 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar1 + uVar18);
              uVar9 = puVar3[1];
              uVar10 = puVar3[2];
              uVar11 = puVar3[3];
              puVar4 = (undefined4 *)(lVar2 + uVar18);
              *puVar4 = *puVar3;
              puVar4[1] = uVar9;
              puVar4[2] = uVar10;
              puVar4[3] = uVar11;
              uVar18 = uVar18 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar18);
            if (uVar15 == uVar20) goto LAB_2ad9915d0e9;
          }
          do {
            *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(lVar1 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
        goto LAB_2ad9915d0e9;
      }
    }
LAB_2ad9915d0f6:
    bVar21 = lVar17 == 3;
    lVar17 = lVar17 + 1;
    if (bVar21) {
      FUN_2ad99140a40(&local_70,&local_80,0,0x2ad99171230);
      FUN_2ad99140000(&local_80);
      FUN_2ad99140a40(0x2ad99183b3c,&local_70,1,0x2ad99171240);
      FUN_2ad99140000(&local_70);
      FUN_2ad99140000(&local_90);
      return;
    }
  } while( true );
}



/* Address: 2ad9915d7b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915d7b0(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  short sVar2;
  short *psVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ulonglong uVar19;
  int iVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  longlong lVar23;
  longlong lVar24;
  bool bVar25;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  longlong local_7c;
  undefined4 local_70;
  longlong local_6c;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  short *local_4c;
  
  local_70 = 0;
  local_90 = 0;
  local_60 = 0;
  local_80 = 0;
  local_50 = 0;
  local_6c = 0;
  local_8c = 0;
  local_5c = 0;
  local_7c = 0;
  local_4c = (short *)0x0;
  FUN_2ad99140a40(&local_90,0x2ad991632c8);
  lVar24 = *(longlong *)(param_2 + 4);
  if (lVar24 != 0) {
    uVar18 = *(uint *)(lVar24 + -4);
    uVar19 = (ulonglong)uVar18;
    if ((uVar19 != 0) || (local_8c == 0)) {
      if (local_8c == 0) {
        uVar13 = 0;
        uVar15 = uVar18;
      }
      else {
        uVar13 = (ulonglong)*(uint *)(local_8c + -4);
        uVar15 = uVar18 + *(uint *)(local_8c + -4);
      }
      cVar9 = FUN_2ad99140060(&local_90);
      if (cVar9 == '\0') goto LAB_2ad9915e072;
      if (uVar19 != 0) {
        lVar23 = local_8c + uVar13 * 2;
        if (uVar18 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar23 - lVar24) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar22 = 0;
          uVar13 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            puVar14 = (undefined4 *)(lVar24 + uVar22);
            uVar5 = puVar14[1];
            uVar6 = puVar14[2];
            uVar7 = puVar14[3];
            puVar1 = (undefined4 *)(lVar23 + uVar22);
            *puVar1 = *puVar14;
            puVar1[1] = uVar5;
            puVar1[2] = uVar6;
            puVar1[3] = uVar7;
            uVar22 = uVar22 + 0x10;
          } while ((uVar19 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar13 == uVar19) goto LAB_2ad9915d942;
        }
        do {
          *(undefined2 *)(lVar23 + uVar13 * 2) = *(undefined2 *)(lVar24 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar19 != uVar13);
      }
LAB_2ad9915d942:
      *(uint *)(local_8c + -4) = uVar15;
      *(undefined2 *)(local_8c + (ulonglong)uVar15 * 2) = 0;
    }
  }
  uVar18 = 0;
  FUN_2ad99140a40(&local_70,&local_90,0,0x2ad991712b0);
  uVar15 = _DAT_2ad991632e8;
  uVar19 = (ulonglong)_DAT_2ad991632e8;
  if ((uVar19 != 0) || (local_6c == 0)) {
    if (local_6c != 0) {
      uVar18 = *(uint *)(local_6c + -4);
    }
    uVar16 = _DAT_2ad991632e8 + uVar18;
    uVar12 = 0x104;
    if ((0x103 < uVar16) &&
       ((0x7ffffffd < uVar16 || (uVar12 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar12)))) {
      uVar12 = 0x7ffffffe;
    }
    cVar9 = FUN_2ad99140060(&local_70,uVar12);
    if (cVar9 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1b07eb000001f9);
LAB_2ad9915e072:
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x1507eb000001f9);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (uVar19 != 0) {
      lVar24 = local_6c + (ulonglong)uVar18 * 2;
      if (uVar15 < 0x10) {
        uVar13 = 0;
      }
      else if (lVar24 - 0x2ad991632ecU < 0x20) {
        uVar13 = 0;
      }
      else {
        uVar22 = 0;
        uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
        do {
          uVar5 = *(undefined4 *)(uVar22 + 0x2ad991632f0);
          uVar6 = *(undefined4 *)(uVar22 + 0x2ad991632f4);
          uVar7 = *(undefined4 *)(uVar22 + 0x2ad991632f8);
          puVar14 = (undefined4 *)(lVar24 + uVar22);
          *puVar14 = *(undefined4 *)(&DAT_2ad991632ec + uVar22);
          puVar14[1] = uVar5;
          puVar14[2] = uVar6;
          puVar14[3] = uVar7;
          uVar22 = uVar22 + 0x10;
        } while ((uVar19 * 2 & 0xfffffffffffffff0) != uVar22);
        if (uVar13 == uVar19) goto LAB_2ad9915da72;
      }
      do {
        *(undefined2 *)(lVar24 + uVar13 * 2) = *(undefined2 *)(&DAT_2ad991632ec + uVar13 * 2);
        uVar13 = uVar13 + 1;
      } while (uVar19 != uVar13);
    }
LAB_2ad9915da72:
    *(uint *)(local_6c + -4) = uVar16;
    *(undefined2 *)(local_6c + (ulonglong)uVar16 * 2) = 0;
  }
  FUN_2ad99140a40(&local_50,&local_70,0);
  psVar3 = *(short **)(param_1 + 4);
  uVar5 = 0xfa9;
  if ((psVar3 == (short *)0x0) || (local_4c == (short *)0x0)) {
LAB_2ad9915db19:
    _DAT_2ad99183b10 = uVar5;
    uVar21 = 0x2ad991712d0;
  }
  else {
    uVar18 = *(uint *)(psVar3 + -2);
    uVar5 = 0x13ab;
    if ((uVar18 == 0) || (uVar15 = *(uint *)(local_4c + -2), uVar15 == 0)) goto LAB_2ad9915db19;
    uVar19 = 0;
    iVar20 = 0;
    if (psVar3 == local_4c) goto LAB_2ad9915dc1b;
    uVar5 = _DAT_2ad99183b10;
    if ((uVar18 < uVar15) || (uVar12 = (uVar18 - uVar15) + 1, uVar12 == 0)) goto LAB_2ad9915db19;
    sVar2 = *local_4c;
    uVar13 = (ulonglong)uVar12;
    if (1 < uVar15) {
      bVar25 = true;
      uVar22 = 0;
      do {
        if (psVar3[uVar22] == sVar2) {
          lVar23 = 1;
          lVar24 = (ulonglong)uVar15 - 1;
          while (psVar3[(uint)((int)uVar22 + (int)lVar23)] == local_4c[lVar23]) {
            lVar23 = lVar23 + 1;
            lVar24 = lVar24 + -1;
            if (lVar24 == 0) goto LAB_2ad9915dc08;
          }
          if ((int)lVar24 == 0) {
LAB_2ad9915dc08:
            if (bVar25) goto LAB_2ad9915dc12;
            break;
          }
        }
        uVar22 = uVar22 + 1;
        bVar25 = uVar22 < uVar13;
      } while (uVar22 != uVar13);
      goto LAB_2ad9915db19;
    }
    iVar20 = 0;
    if (*psVar3 != sVar2) {
      uVar22 = 0;
      do {
        if (uVar13 - 1 == uVar22) goto LAB_2ad9915db19;
        lVar24 = uVar22 + 1;
        uVar22 = uVar22 + 1;
      } while (psVar3[lVar24] != sVar2);
      if (uVar22 < uVar13) {
LAB_2ad9915dc12:
        iVar20 = (int)uVar22;
        if (-1 < iVar20) goto LAB_2ad9915dc1b;
      }
      goto LAB_2ad9915db19;
    }
LAB_2ad9915dc1b:
    if (local_4c == (short *)0xc) {
      uVar15 = 0;
    }
    uVar15 = uVar15 + iVar20;
    if (psVar3 != (short *)0xc) {
      uVar19 = (ulonglong)uVar18;
    }
    uVar12 = (uint)uVar19;
    if ((int)uVar15 < (int)uVar12) {
      uVar13 = (ulonglong)uVar15;
      uVar16 = uVar15;
      if (uVar15 < uVar18) {
        uVar16 = uVar18;
      }
      lVar24 = 0;
      do {
        if ((uVar13 - uVar16) + lVar24 == 0) {
LAB_2ad9915dcb5:
          _DAT_2ad99183b10 = 0x13b1;
LAB_2ad9915dcc5:
          uVar17 = uVar16;
          uVar15 = uVar16;
          if ((int)uVar16 < (int)uVar12) goto LAB_2ad9915dcea;
          goto LAB_2ad9915dd2a;
        }
        if (psVar3[uVar13 + lVar24] != 0x20) {
          uVar16 = (uint)(uVar13 + lVar24);
          if (uVar18 <= uVar16) goto LAB_2ad9915dcb5;
          if (psVar3[uVar13 + lVar24 & 0xffffffff] != 0x22) goto LAB_2ad9915dcc5;
          uVar13 = uVar13 + 1 + lVar24;
          uVar16 = (uint)uVar13;
          if ((int)uVar12 <= (int)uVar16) {
            uVar22 = uVar13 & 0xffffffff;
            goto LAB_2ad9915df2d;
          }
          uVar13 = uVar13 & 0xffffffff;
          goto LAB_2ad9915dd12;
        }
        lVar24 = lVar24 + 1;
      } while ((int)((int)lVar24 + uVar15) < (int)uVar12);
    }
    uVar21 = 0x2ad991712e0;
  }
  puVar14 = (undefined4 *)0x2ad99160d08;
  goto LAB_2ad9915db32;
LAB_2ad9915dcea:
  do {
    if (uVar15 < uVar18) {
      uVar17 = uVar15;
      if ((psVar3[uVar15] == 0x2c) || (psVar3[uVar15] == 0x7d)) break;
    }
    else {
      _DAT_2ad99183b10 = 0x13b1;
    }
    uVar15 = uVar15 + 1;
    uVar17 = uVar12;
  } while (uVar12 != uVar15);
LAB_2ad9915dd2a:
  local_80 = 0;
  local_7c = 0;
  if (psVar3 == (short *)0xc) {
    uVar5 = 0xfa9;
LAB_2ad9915ddb6:
    _DAT_2ad99183b10 = uVar5;
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
            (cVar9 = FUN_2ad99140060(0x2ad99183b3c,0), puVar8 = _DAT_2ad99183b40, cVar9 != '\0')) {
      *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
      *puVar8 = 0;
    }
  }
  else {
    uVar15 = uVar16;
    if (((int)uVar16 < 0) && (uVar15 = uVar18 + uVar16, (int)uVar15 < 0)) {
      uVar5 = 0x13ab;
      goto LAB_2ad9915ddb6;
    }
    iVar20 = uVar18 - uVar15;
    uVar5 = 0x13ab;
    if (uVar18 < uVar15 || iVar20 == 0) goto LAB_2ad9915ddb6;
    iVar11 = uVar17 - uVar16;
    iVar10 = iVar20;
    if ((-1 < iVar11) && (iVar10 = iVar11, iVar20 < iVar11)) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar10 = iVar20;
    }
    uVar5 = _DAT_2ad99183b10;
    if (iVar10 == 0) goto LAB_2ad9915ddb6;
    FUN_2ad991401d0(0x2ad99183b3c,psVar3 + uVar15,iVar10);
  }
  FUN_2ad99140a40(&local_90,0x2ad99183b3c,1,0x2ad99171310);
  FUN_2ad99140a40(&local_80,&local_90,0,0x2ad99171320);
  FUN_2ad99140cf0(&local_80);
  if ((local_7c == 0) || (local_7c == 0xc)) {
    _DAT_2ad99183b10 = 0xfa9;
  }
  else {
    uVar18 = *(uint *)(local_7c + -4);
    if ((ulonglong)uVar18 != 0) {
      lVar24 = 0;
      uVar15 = uVar18;
      do {
        uVar19 = (ulonglong)*(ushort *)(local_7c + -2 + (ulonglong)uVar18 * 2 + lVar24 * 2);
        if ((0x20 < uVar19) || ((0x100002600U >> (uVar19 & 0x3f) & 1) == 0)) {
          if ((int)lVar24 == 0) goto LAB_2ad9915deea;
          uVar12 = -(int)lVar24;
          break;
        }
        lVar24 = lVar24 + -1;
        uVar15 = uVar15 - 1;
        uVar12 = uVar18;
      } while (uVar15 != 0);
      uVar18 = uVar18 - uVar12;
      cVar9 = FUN_2ad99140060(&local_80,uVar18);
      if (cVar9 != '\0') {
        *(uint *)(local_7c + -4) = uVar18;
        *(undefined2 *)(local_7c + (ulonglong)uVar18 * 2) = 0;
      }
    }
  }
LAB_2ad9915deea:
  FUN_2ad99140a40(&local_60,&local_80,0,0x2ad99171330);
  FUN_2ad99140000(&local_80);
  goto LAB_2ad9915db37;
LAB_2ad9915dd12:
  do {
    if ((uint)uVar13 < uVar18) {
      uVar22 = uVar13;
      if (psVar3[uVar13] == 0x22) break;
    }
    else {
      _DAT_2ad99183b10 = 0x13b1;
    }
    uVar17 = (uint)uVar13 + 1;
    uVar13 = (ulonglong)uVar17;
    uVar22 = uVar19;
  } while (uVar12 != uVar17);
LAB_2ad9915df2d:
  if (psVar3 == (short *)0xc) {
    uVar5 = 0xfa9;
LAB_2ad9915df90:
    _DAT_2ad99183b10 = uVar5;
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
            (cVar9 = FUN_2ad99140060(0x2ad99183b3c,0), puVar8 = _DAT_2ad99183b40, cVar9 != '\0')) {
      *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
      *puVar8 = 0;
    }
  }
  else {
    if (((int)uVar16 < 0) && (uVar16 = uVar18 + 1 + uVar15 + (int)lVar24, (int)uVar16 < 0)) {
      uVar5 = 0x13ab;
      goto LAB_2ad9915df90;
    }
    iVar20 = uVar18 - uVar16;
    uVar5 = 0x13ab;
    if (uVar18 < uVar16 || iVar20 == 0) goto LAB_2ad9915df90;
    iVar11 = (~uVar15 + (int)uVar22) - (int)lVar24;
    iVar10 = iVar20;
    if ((-1 < iVar11) && (iVar10 = iVar11, iVar20 < iVar11)) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar10 = iVar20;
    }
    uVar5 = _DAT_2ad99183b10;
    if (iVar10 == 0) goto LAB_2ad9915df90;
    FUN_2ad991401d0(0x2ad99183b3c,psVar3 + uVar16);
  }
  puVar14 = &local_90;
  FUN_2ad99140a40(puVar14,0x2ad99183b3c,1,0x2ad991712f0);
  uVar21 = 0x2ad99171300;
LAB_2ad9915db32:
  FUN_2ad99140a40(&local_60,puVar14,0,uVar21);
LAB_2ad9915db37:
  FUN_2ad99140000(&local_50);
  FUN_2ad99140a40(0x2ad99183b3c,&local_60,1,0x2ad99171340);
  FUN_2ad99140000(&local_60);
  FUN_2ad99140000(&local_90);
  FUN_2ad99140000(&local_70);
  return;
}



/* Address: 2ad9915e0a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915e0a0(double param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_68;
  longlong local_64;
  undefined4 local_58;
  longlong local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  local_88 = 0;
  local_58 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_68 = 0;
  local_48 = 0;
  local_84 = 0;
  local_54 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_64 = 0;
  local_44 = 0;
  local_78 = 0;
  local_70 = 0;
  FUN_2ad99140a40(&local_78,0x2ad99163930,0,0x2ad991715a0);
  if (param_1 <= 0.0) {
    FUN_2ad99140a40(&local_78,0x2ad99160d08,0,0x2ad991715b0);
  }
  (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,param_1,2);
  FUN_2ad99140a40(&local_68,0x2ad99183b3c,1,0x2ad991715c0);
  FUN_2ad99140a40(&local_a8,&local_78);
  lVar2 = local_64;
  if (local_64 != 0) {
    uVar12 = *(uint *)(local_64 + -4);
    uVar9 = (ulonglong)uVar12;
    if ((uVar9 == 0) && (local_a4 != 0)) goto LAB_2ad9915e2dd;
    if (local_a4 == 0) {
      uVar7 = 0;
      uVar8 = uVar12;
    }
    else {
      uVar7 = (ulonglong)*(uint *)(local_a4 + -4);
      uVar8 = uVar12 + *(uint *)(local_a4 + -4);
    }
    cVar5 = FUN_2ad99140060(&local_a8);
    if (cVar5 != '\0') {
      if (uVar9 != 0) {
        lVar1 = local_a4 + uVar7 * 2;
        if (uVar12 < 0x10) {
          uVar7 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar7 = 0;
        }
        else {
          uVar11 = 0;
          uVar7 = (ulonglong)(uVar12 & 0xfffffff8);
          do {
            uVar4 = ((undefined8 *)(lVar2 + uVar11))[1];
            *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(lVar2 + uVar11);
            ((undefined8 *)(lVar1 + uVar11))[1] = uVar4;
            uVar11 = uVar11 + 0x10;
          } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
          if (uVar7 == uVar9) goto LAB_2ad9915e2d2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
          uVar7 = uVar7 + 1;
        } while (uVar9 != uVar7);
      }
LAB_2ad9915e2d2:
      *(uint *)(local_a4 + -4) = uVar8;
      *(undefined2 *)(local_a4 + (ulonglong)uVar8 * 2) = 0;
      goto LAB_2ad9915e2dd;
    }
LAB_2ad9915e61f:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xe0856000001f9);
LAB_2ad9915e63f:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x2b0856000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
LAB_2ad9915e2dd:
  uVar12 = 0;
  FUN_2ad99140a40(&local_98,&local_a8,0,0x2ad991715e0);
  uVar8 = _DAT_2ad9916303c;
  uVar9 = (ulonglong)_DAT_2ad9916303c;
  if ((uVar9 != 0) || (local_94 == 0)) {
    if (local_94 != 0) {
      uVar12 = *(uint *)(local_94 + -4);
    }
    uVar10 = _DAT_2ad9916303c + uVar12;
    uVar6 = 0x104;
    if ((0x103 < uVar10) &&
       ((0x7ffffffd < uVar10 || (uVar6 = (uVar10 >> 2) + uVar10, 0x7ffffffd < uVar6)))) {
      uVar6 = 0x7ffffffe;
    }
    cVar5 = FUN_2ad99140060(&local_98,uVar6);
    if (cVar5 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x270856000001f9);
      goto LAB_2ad9915e61f;
    }
    if (uVar9 != 0) {
      lVar2 = local_94 + (ulonglong)uVar12 * 2;
      if (uVar8 < 0x10) {
        uVar7 = 0;
      }
      else if (lVar2 - 0x2ad99163040U < 0x20) {
        uVar7 = 0;
      }
      else {
        uVar11 = 0;
        uVar7 = (ulonglong)(uVar8 & 0xfffffff8);
        do {
          uVar4 = *(undefined8 *)(uVar11 + 0x2ad99163048);
          *(undefined8 *)(lVar2 + uVar11) = *(undefined8 *)(&DAT_2ad99163040 + uVar11);
          ((undefined8 *)(lVar2 + uVar11))[1] = uVar4;
          uVar11 = uVar11 + 0x10;
        } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
        if (uVar7 == uVar9) goto LAB_2ad9915e402;
      }
      do {
        *(undefined2 *)(lVar2 + uVar7 * 2) = *(undefined2 *)(&DAT_2ad99163040 + uVar7 * 2);
        uVar7 = uVar7 + 1;
      } while (uVar9 != uVar7);
    }
LAB_2ad9915e402:
    *(uint *)(local_94 + -4) = uVar10;
    *(undefined2 *)(local_94 + (ulonglong)uVar10 * 2) = 0;
  }
  (*(code *)0x7ff63a0c7410)(0x2ad95e68178,0x24);
  FUN_2ad99140a40(&local_58,0x2ad99183b3c,1,0x2ad991715f0);
  FUN_2ad99140a40(&local_88,&local_98,0);
  lVar2 = local_54;
  if (local_54 == 0) goto LAB_2ad9915e56d;
  uVar12 = *(uint *)(local_54 + -4);
  uVar9 = (ulonglong)uVar12;
  if ((uVar9 == 0) && (local_84 != 0)) goto LAB_2ad9915e56d;
  if (local_84 == 0) {
    uVar7 = 0;
    uVar8 = uVar12;
  }
  else {
    uVar7 = (ulonglong)*(uint *)(local_84 + -4);
    uVar8 = uVar12 + *(uint *)(local_84 + -4);
  }
  cVar5 = FUN_2ad99140060(&local_88);
  if (cVar5 == '\0') goto LAB_2ad9915e63f;
  if (uVar9 != 0) {
    lVar1 = local_84 + uVar7 * 2;
    if (uVar12 < 0x10) {
      uVar7 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
      uVar7 = 0;
    }
    else {
      uVar11 = 0;
      uVar7 = (ulonglong)(uVar12 & 0xfffffff8);
      do {
        uVar4 = ((undefined8 *)(lVar2 + uVar11))[1];
        *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(lVar2 + uVar11);
        ((undefined8 *)(lVar1 + uVar11))[1] = uVar4;
        uVar11 = uVar11 + 0x10;
      } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
      if (uVar7 == uVar9) goto LAB_2ad9915e562;
    }
    do {
      *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
      uVar7 = uVar7 + 1;
    } while (uVar9 != uVar7);
  }
LAB_2ad9915e562:
  *(uint *)(local_84 + -4) = uVar8;
  *(undefined2 *)(local_84 + (ulonglong)uVar8 * 2) = 0;
LAB_2ad9915e56d:
  FUN_2ad99140a40(&local_48,&local_88,0,0x2ad99171610);
  FUN_2ad99140000(&local_78);
  FUN_2ad99140a40(0x2ad99183b3c,&local_48,1,0x2ad99171620);
  FUN_2ad99140000(&local_48);
  FUN_2ad99140000(&local_68);
  FUN_2ad99140000(&local_a8);
  FUN_2ad99140000(&local_98);
  FUN_2ad99140000(&local_58);
  FUN_2ad99140000(&local_88);
  return;
}



/* Address: 2ad9915e660 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915e660(double param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  longlong local_54;
  undefined4 local_48;
  undefined8 local_44;
  
  local_78 = 0;
  local_88 = 0;
  local_58 = 0;
  local_48 = 0;
  local_74 = 0;
  local_84 = 0;
  local_54 = 0;
  local_44 = 0;
  local_68 = 0;
  local_60 = 0;
  FUN_2ad99140a40(&local_68,0x2ad99163930,0,0x2ad99171630);
  if (param_1 <= 0.0) {
    FUN_2ad99140a40(&local_68,0x2ad99160d08,0,0x2ad99171640);
  }
  (*(code *)0x7ff63a0fd7c0)(0x2ad95e68178,param_1,0);
  FUN_2ad99140a40(&local_58,0x2ad99183b3c,1,0x2ad99171650);
  FUN_2ad99140a40(&local_88,&local_68);
  lVar2 = local_54;
  if (local_54 != 0) {
    uVar12 = *(uint *)(local_54 + -4);
    uVar9 = (ulonglong)uVar12;
    if ((uVar9 != 0) || (local_84 == 0)) {
      if (local_84 == 0) {
        uVar7 = 0;
        uVar8 = uVar12;
      }
      else {
        uVar7 = (ulonglong)*(uint *)(local_84 + -4);
        uVar8 = uVar12 + *(uint *)(local_84 + -4);
      }
      cVar5 = FUN_2ad99140060(&local_88);
      if (cVar5 == '\0') goto LAB_2ad9915ea49;
      if (uVar9 != 0) {
        lVar1 = local_84 + uVar7 * 2;
        if (uVar12 < 0x10) {
          uVar7 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar7 = 0;
        }
        else {
          uVar11 = 0;
          uVar7 = (ulonglong)(uVar12 & 0xfffffff8);
          do {
            uVar4 = ((undefined8 *)(lVar2 + uVar11))[1];
            *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(lVar2 + uVar11);
            ((undefined8 *)(lVar1 + uVar11))[1] = uVar4;
            uVar11 = uVar11 + 0x10;
          } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
          if (uVar7 == uVar9) goto LAB_2ad9915e872;
        }
        do {
          *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
          uVar7 = uVar7 + 1;
        } while (uVar9 != uVar7);
      }
LAB_2ad9915e872:
      *(uint *)(local_84 + -4) = uVar8;
      *(undefined2 *)(local_84 + (ulonglong)uVar8 * 2) = 0;
    }
  }
  uVar12 = 0;
  FUN_2ad99140a40(&local_78,&local_88,0,0x2ad99171670);
  uVar8 = _DAT_2ad99163948;
  uVar9 = (ulonglong)_DAT_2ad99163948;
  if ((uVar9 == 0) && (local_74 != 0)) goto LAB_2ad9915e9ad;
  if (local_74 != 0) {
    uVar12 = *(uint *)(local_74 + -4);
  }
  uVar10 = _DAT_2ad99163948 + uVar12;
  uVar6 = 0x104;
  if ((0x103 < uVar10) &&
     ((0x7ffffffd < uVar10 || (uVar6 = (uVar10 >> 2) + uVar10, 0x7ffffffd < uVar6)))) {
    uVar6 = 0x7ffffffe;
  }
  cVar5 = FUN_2ad99140060(&local_78,uVar6);
  if (cVar5 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0x28085b000001f9);
LAB_2ad9915ea49:
    (*(code *)0x7ff639cc59a0)(0x2ad95e68178,0xe085b000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar9 != 0) {
    lVar2 = local_74 + (ulonglong)uVar12 * 2;
    if (uVar8 < 0x10) {
      uVar7 = 0;
    }
    else if (lVar2 - 0x2ad9916394cU < 0x20) {
      uVar7 = 0;
    }
    else {
      uVar11 = 0;
      uVar7 = (ulonglong)(uVar8 & 0xfffffff8);
      do {
        uVar4 = *(undefined8 *)(uVar11 + 0x2ad99163954);
        *(undefined8 *)(lVar2 + uVar11) = *(undefined8 *)(&DAT_2ad9916394c + uVar11);
        ((undefined8 *)(lVar2 + uVar11))[1] = uVar4;
        uVar11 = uVar11 + 0x10;
      } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
      if (uVar7 == uVar9) goto LAB_2ad9915e9a2;
    }
    do {
      *(undefined2 *)(lVar2 + uVar7 * 2) = *(undefined2 *)(&DAT_2ad9916394c + uVar7 * 2);
      uVar7 = uVar7 + 1;
    } while (uVar9 != uVar7);
  }
LAB_2ad9915e9a2:
  *(uint *)(local_74 + -4) = uVar10;
  *(undefined2 *)(local_74 + (ulonglong)uVar10 * 2) = 0;
LAB_2ad9915e9ad:
  FUN_2ad99140a40(&local_48,&local_78,0,0x2ad99171680);
  FUN_2ad99140000(&local_68);
  FUN_2ad99140a40(0x2ad99183b3c,&local_48,1,0x2ad99171690);
  FUN_2ad99140000(&local_48);
  FUN_2ad99140000(&local_58);
  FUN_2ad99140000(&local_88);
  FUN_2ad99140000(&local_78);
  return;
}



/* Address: 2ad9915ea70 */

void FUN_2ad9915ea70(undefined8 param_1,undefined8 param_2,int param_3,int param_4,
                    undefined4 param_5,int param_6)

{
  int iVar1;
  
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2ad95e68178,0,param_1);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x2ad95e68178,0,param_1);
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2ad95e68178,0x112,6,0x550005,0,0x590008,param_1,0x520004,0x66,0x520004,0,0x540005,0,
             0x580007,0);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0x402,0);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0x3f4,(longlong)param_3);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0x3f5,(longlong)param_4);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0x3f3,2);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0x3ea,(longlong)param_6);
  (*(code *)0x7ff63a0f3c80)(0x2ad95e68178,0,param_1,0x3e9,0x2ad991784f0);
  (*(code *)0x7ff63a0f3c80)(0x2ad95e68178,0,param_1,6,param_2);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,3,0);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0xcf,1000);
  (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,10,0);
  return;
}



/* Address: 2ad9915eca0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915eca0(undefined8 param_1,longlong param_2,int param_3,longlong param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong in_stack_ffffffffffffff98;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_50 = 0;
  local_60 = 0;
  local_4c = 0;
  local_5c = 0;
  iVar6 = (*(code *)0x7ff63a0f4840)(0x2ad95e68178,0,param_1);
  if (iVar6 < 0) goto LAB_2ad9915eef1;
  local_60 = 0;
  local_5c = 0;
  (*(code *)0x7ff63a0f4a80)
            (0x2ad95e68178,0,param_1,6,in_stack_ffffffffffffff98 & 0xffffffff00000000);
  FUN_2ad99140a40(&local_50,0x2ad99183b3c,1,0x2ad991716c0);
  FUN_2ad99140a40(&local_60,&local_50,0,0x2ad991716d0);
  lVar4 = *(longlong *)(param_2 + 4);
  if (local_5c != lVar4) {
    if ((local_5c != 0) && (lVar4 != 0)) {
      uVar3 = *(uint *)(local_5c + -4);
      uVar8 = *(uint *)(lVar4 + -4);
      uVar7 = uVar8;
      if (uVar3 < uVar8) {
        uVar7 = uVar3;
      }
      iVar6 = uVar3 - uVar8;
      if (uVar7 != 0) {
        uVar9 = 1;
        do {
          uVar1 = *(ushort *)(local_5c + -2 + uVar9 * 2);
          uVar2 = *(ushort *)(lVar4 + -2 + uVar9 * 2);
          if (uVar7 <= uVar9) break;
          uVar9 = uVar9 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar6 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar6 == 0) goto LAB_2ad9915eee9;
    }
    (*(code *)0x7ff63a0f3c80)(0x2ad95e68178,0,param_1,6,param_2);
    if (param_3 != -1) {
      (*(code *)0x7ff63a0f3b30)(0x2ad95e68178,0,param_1,0,param_3);
    }
    puVar5 = *(undefined1 **)(param_4 + 4);
    if (puVar5 != &DAT_2ad99160d00) {
      if (puVar5 != (undefined1 *)0x0) {
        uVar3 = *(uint *)(puVar5 + -4);
        uVar8 = _DAT_2ad99160cfc;
        if (uVar3 < _DAT_2ad99160cfc) {
          uVar8 = uVar3;
        }
        iVar6 = uVar3 - _DAT_2ad99160cfc;
        if (uVar8 != 0) {
          uVar9 = 0;
          do {
            uVar1 = *(ushort *)(puVar5 + uVar9 * 2);
            uVar2 = *(ushort *)(&DAT_2ad99160d00 + uVar9 * 2);
            uVar9 = uVar9 + 1;
            if (uVar8 <= uVar9) break;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar6 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar6 == 0) goto LAB_2ad9915eee9;
      }
      (*(code *)0x7ff63a0f3c80)(0x2ad95e68178,0,param_1,0xce,param_4);
    }
  }
LAB_2ad9915eee9:
  FUN_2ad99140000(&local_60);
LAB_2ad9915eef1:
  FUN_2ad99140000(&local_50);
  return;
}



/* Address: 2ad9915ef10 */

/* WARNING: Removing unreachable block (ram,0x02ad9915f8a8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ad9915ef10(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  short *psVar3;
  undefined2 *puVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  short *psVar16;
  bool bVar17;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d0;
  undefined1 *local_cc;
  ulonglong local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  longlong local_58;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_e0 = 0;
  local_50 = 0;
  local_78 = 0;
  local_98 = 0;
  local_f0 = 0;
  local_a8 = 0;
  local_d0 = 0;
  local_b8 = 0;
  local_88 = 0;
  local_dc = 0;
  local_4c = 0;
  local_64 = 0;
  local_74 = 0;
  local_94 = 0;
  local_ec = 0;
  local_a4 = 0;
  local_cc = (undefined1 *)0x0;
  local_b4 = 0;
  local_84 = 0;
  psVar3 = *(short **)(param_1 + 4);
  if (psVar3 == (short *)0x0) {
    _DAT_2ad99183b10 = 0xfa9;
LAB_2ad9915f085:
    uVar14 = 0xffffffff;
  }
  else {
    uVar6 = *(uint *)(psVar3 + -2);
    if ((uVar6 == 0) || (_DAT_2ad99163a5e == 0)) {
      _DAT_2ad99183b10 = 0x13ab;
      goto LAB_2ad9915f085;
    }
    uVar14 = 0;
    if (psVar3 == (short *)0x2ad99163a62) goto LAB_2ad9915f08b;
    if ((uVar6 < _DAT_2ad99163a5e) || (uVar6 = (uVar6 - _DAT_2ad99163a5e) + 1, uVar6 == 0))
    goto LAB_2ad9915f085;
    uVar13 = (ulonglong)uVar6;
    if (1 < _DAT_2ad99163a5e) {
      bVar17 = true;
      uVar12 = 1;
      uVar14 = 0;
      do {
        iVar9 = (int)uVar12;
        if (psVar3[uVar14] == 0x2d) {
          psVar16 = (short *)&DAT_2ad99163a64;
          lVar11 = (ulonglong)_DAT_2ad99163a5e - 1;
          while (psVar3[uVar12] == *psVar16) {
            psVar16 = psVar16 + 1;
            uVar12 = (ulonglong)((int)uVar12 + 1);
            lVar11 = lVar11 + -1;
            if (lVar11 == 0) goto LAB_2ad9915fce9;
          }
          if ((int)lVar11 == 0) {
LAB_2ad9915fce9:
            if (bVar17) goto LAB_2ad9915f08b;
            break;
          }
        }
        uVar14 = uVar14 + 1;
        uVar12 = (ulonglong)(iVar9 + 1);
        bVar17 = uVar14 < uVar13;
      } while (uVar14 != uVar13);
      goto LAB_2ad9915f085;
    }
    if (*psVar3 != 0x2d) {
      uVar14 = 0;
      do {
        if (uVar13 - 1 == uVar14) goto LAB_2ad9915f085;
        lVar11 = uVar14 + 1;
        uVar14 = uVar14 + 1;
      } while (psVar3[lVar11] != 0x2d);
      if (uVar13 <= uVar14) goto LAB_2ad9915f085;
    }
  }
LAB_2ad9915f08b:
  FUN_2ad991403b0(psVar3,0x2ad99163a62,(int)uVar14 + 1);
  local_68 = 0;
  local_64 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ad9915f117:
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else {
      _DAT_2ad99183b10 = uVar7;
      if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
         (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    iVar9 = *(int *)(lVar11 + -4);
    if (iVar9 == 0) {
      uVar7 = 0x13ab;
      goto LAB_2ad9915f117;
    }
    iVar8 = 2;
    if (iVar9 < 2) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar8 = iVar9;
    }
    FUN_2ad991401d0(0x2ad99183b3c,lVar11,iVar8);
  }
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171d70);
  FUN_2ad99140a40(&local_68,&local_e0,0,0x2ad99171d80);
  local_78 = 0;
  local_74 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ad9915f21f:
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else {
      _DAT_2ad99183b10 = uVar7;
      if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
         (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar7 = 0x13ab;
    if (*(uint *)(lVar11 + -4) < 4) goto LAB_2ad9915f21f;
    iVar8 = *(uint *)(lVar11 + -4) - 3;
    iVar9 = 2;
    if (iVar8 < 2) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar9 = iVar8;
    }
    FUN_2ad991401d0(0x2ad99183b3c,lVar11 + 6,iVar9);
  }
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171d90);
  FUN_2ad99140a40(&local_78,&local_e0,0,0x2ad99171da0);
  local_98 = 0;
  local_94 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ad9915f320:
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else {
      _DAT_2ad99183b10 = uVar7;
      if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
         (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar7 = 0x13ab;
    if (*(uint *)(lVar11 + -4) < 7) goto LAB_2ad9915f320;
    iVar8 = *(uint *)(lVar11 + -4) - 6;
    iVar9 = 4;
    if (iVar8 < 4) {
      _DAT_2ad99183b10 = 0x13ab;
      iVar9 = iVar8;
    }
    FUN_2ad991401d0(0x2ad99183b3c,lVar11 + 0xc,iVar9);
  }
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171db0);
  FUN_2ad99140a40(&local_98,&local_e0,0,0x2ad99171dc0);
  psVar3 = *(short **)(param_2 + 4);
  if (psVar3 == (short *)0x0) {
    iVar9 = -1;
    _DAT_2ad99183b10 = 0xfa9;
joined_r0x02ad9915f456:
    if (_DAT_2ad99183b40 != (undefined2 *)0x0) {
      local_ec = 0;
      local_f0 = 0;
      if (_DAT_2ad99183b40 != (undefined2 *)0xc) {
        if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
           (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
          *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
          *puVar4 = 0;
        }
        goto LAB_2ad9915f538;
      }
    }
    local_ec = 0;
    local_f0 = 0;
    _DAT_2ad99183b10 = 0xfa9;
  }
  else {
    uVar6 = *(uint *)(psVar3 + -2);
    if ((uVar6 == 0) || (_DAT_2ad99163f3c == 0)) {
      _DAT_2ad99183b10 = 0x13ab;
      goto LAB_2ad9915f465;
    }
    uVar14 = 0;
    if (psVar3 == (short *)0x2ad99163f40) goto LAB_2ad9915f46b;
    if ((uVar6 < _DAT_2ad99163f3c) || (uVar6 = (uVar6 - _DAT_2ad99163f3c) + 1, uVar6 == 0)) {
LAB_2ad9915f465:
      uVar14 = 0xffffffff;
    }
    else {
      local_c0 = (ulonglong)uVar6;
      if (1 < _DAT_2ad99163f3c) {
        bVar17 = true;
        uVar13 = 1;
        uVar14 = 0;
        local_58 = (ulonglong)_DAT_2ad99163f3c - 1;
        do {
          iVar9 = (int)uVar13;
          if (psVar3[uVar14] == 0x3a) {
            psVar16 = (short *)&DAT_2ad99163f42;
            lVar11 = local_58;
            while (psVar3[uVar13] == *psVar16) {
              psVar16 = psVar16 + 1;
              uVar13 = (ulonglong)((int)uVar13 + 1);
              lVar11 = lVar11 + -1;
              if (lVar11 == 0) goto LAB_2ad9915fd5a;
            }
            if ((int)lVar11 == 0) {
LAB_2ad9915fd5a:
              if (bVar17) goto LAB_2ad9915f46b;
              break;
            }
          }
          uVar14 = uVar14 + 1;
          uVar13 = (ulonglong)(iVar9 + 1);
          bVar17 = uVar14 < local_c0;
        } while (uVar14 != local_c0);
        goto LAB_2ad9915f465;
      }
      if (*psVar3 != 0x3a) {
        uVar14 = 0;
        do {
          if (local_c0 - 1 == uVar14) goto LAB_2ad9915f465;
          lVar11 = uVar14 + 1;
          uVar14 = uVar14 + 1;
        } while (psVar3[lVar11] != 0x3a);
        if (local_c0 <= uVar14) goto LAB_2ad9915f465;
      }
    }
LAB_2ad9915f46b:
    iVar9 = (int)uVar14;
    local_f0 = 0;
    local_ec = 0;
    if (psVar3 == (short *)0xc) {
      _DAT_2ad99183b10 = 0xfa9;
      goto joined_r0x02ad9915f456;
    }
    uVar6 = *(uint *)(psVar3 + -2);
    uVar13 = (ulonglong)uVar6;
    if (uVar6 == 0) {
      _DAT_2ad99183b10 = 0x13ab;
      goto joined_r0x02ad9915f456;
    }
    if (-1 < iVar9) {
      if ((int)uVar6 < iVar9) {
        _DAT_2ad99183b10 = 0x13ab;
      }
      else {
        uVar13 = uVar14 & 0xffffffff;
        if (iVar9 == 0) {
          iVar9 = 0;
          goto joined_r0x02ad9915f456;
        }
      }
    }
    FUN_2ad991401d0(0x2ad99183b3c,psVar3,uVar13);
  }
LAB_2ad9915f538:
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171dd0);
  FUN_2ad99140a40(&local_f0,&local_e0,0,0x2ad99171de0);
  local_a8 = 0;
  local_a4 = 0;
  lVar11 = *(longlong *)(param_2 + 4);
  uVar7 = 0xfa9;
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ad9915f5fb:
    _DAT_2ad99183b10 = uVar7;
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
            (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
      *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
      *puVar4 = 0;
    }
  }
  else {
    uVar6 = *(uint *)(lVar11 + -4);
    uVar15 = iVar9 + 1;
    if (((int)uVar15 < 0) && (uVar15 = uVar15 + uVar6, (int)uVar15 < 0)) {
      uVar7 = 0x13ab;
      goto LAB_2ad9915f5fb;
    }
    iVar9 = uVar6 - uVar15;
    uVar7 = 0x13ab;
    if ((uVar6 < uVar15 || iVar9 == 0) ||
       ((iVar8 = 2, iVar9 < 2 &&
        (_DAT_2ad99183b10 = 0x13ab, uVar7 = _DAT_2ad99183b10, iVar8 = iVar9, iVar9 == 0))))
    goto LAB_2ad9915f5fb;
    FUN_2ad991401d0(0x2ad99183b3c,lVar11 + (ulonglong)uVar15 * 2,iVar8);
  }
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171df0);
  FUN_2ad99140a40(&local_a8,&local_e0,0,0x2ad99171e00);
  local_d0 = 0;
  local_cc = (undefined1 *)0x0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_2 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ad9915f6ef:
    if ((_DAT_2ad99183b40 == (undefined2 *)0x0) || (_DAT_2ad99183b40 == (undefined2 *)0xc)) {
      _DAT_2ad99183b10 = 0xfa9;
    }
    else {
      _DAT_2ad99183b10 = uVar7;
      if ((*(int *)(_DAT_2ad99183b40 + -2) != 0) &&
         (cVar5 = FUN_2ad99140060(0x2ad99183b3c,0), puVar4 = _DAT_2ad99183b40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ad99183b40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar6 = *(uint *)(lVar11 + -4);
    uVar15 = uVar6 - 2;
    if (((int)uVar15 < 0) && (uVar15 = uVar15 + uVar6, (int)uVar15 < 0)) {
      uVar7 = 0x13ab;
      goto LAB_2ad9915f6ef;
    }
    uVar7 = 0x13ab;
    if (uVar6 <= uVar15) goto LAB_2ad9915f6ef;
    FUN_2ad991401d0(0x2ad99183b3c,lVar11 + (ulonglong)uVar15 * 2);
  }
  FUN_2ad99140a40(&local_e0,0x2ad99183b3c,1,0x2ad99171e10);
  FUN_2ad99140a40(&local_d0,&local_e0,0,0x2ad99171e20);
  lVar11 = (*(code *)0x7ff63a0fe4f0)(0x2ad95e68178,&local_f0);
  if (local_cc == &DAT_2ad99163f6c) {
    lVar10 = lVar11 + 0xc;
    if (lVar11 == 0xc) {
      lVar10 = lVar11;
    }
LAB_2ad9915f8f3:
    uVar6 = *(uint *)(local_cc + -4);
    uVar15 = _DAT_2ad99163fa8;
    if (uVar6 < _DAT_2ad99163fa8) {
      uVar15 = uVar6;
    }
    iVar9 = uVar6 - _DAT_2ad99163fa8;
    if (uVar15 != 0) {
      uVar14 = 0;
      do {
        uVar1 = *(ushort *)(local_cc + uVar14 * 2);
        uVar2 = *(ushort *)(&DAT_2ad99163fac + uVar14 * 2);
        uVar14 = uVar14 + 1;
        if (uVar15 <= uVar14) break;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar9 = (uint)uVar1 - (uint)uVar2;
      }
    }
    if (iVar9 == 0) {
LAB_2ad9915f9cd:
      bVar17 = true;
      goto LAB_2ad9915f9e4;
    }
    if (local_cc == &DAT_2ad99163fcc) {
      iVar9 = 0;
    }
    else {
      if (local_cc == (undefined1 *)0x0) goto LAB_2ad9915f9d2;
      uVar15 = _DAT_2ad99163fc8;
      if (uVar6 < _DAT_2ad99163fc8) {
        uVar15 = uVar6;
      }
      iVar9 = uVar6 - _DAT_2ad99163fc8;
      if (uVar15 != 0) {
        uVar14 = 0;
        do {
          uVar1 = *(ushort *)(local_cc + uVar14 * 2);
          uVar2 = *(ushort *)(&DAT_2ad99163fcc + uVar14 * 2);
          uVar14 = uVar14 + 1;
          if (uVar15 <= uVar14) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
    }
  }
  else {
    if (local_cc == (undefined1 *)0x0) {
      iVar9 = 1;
LAB_2ad9915f8bd:
      bVar17 = iVar9 == 0;
    }
    else {
      uVar6 = *(uint *)(local_cc + -4);
      uVar15 = _DAT_2ad99163f68;
      if (uVar6 < _DAT_2ad99163f68) {
        uVar15 = uVar6;
      }
      iVar9 = uVar6 - _DAT_2ad99163f68;
      if (uVar15 != 0) {
        uVar14 = 0;
        do {
          uVar1 = *(ushort *)(local_cc + uVar14 * 2);
          uVar2 = *(ushort *)(&DAT_2ad99163f6c + uVar14 * 2);
          uVar14 = uVar14 + 1;
          if (uVar15 <= uVar14) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar9 != 0) {
        if (local_cc == &DAT_2ad99163f8c) {
          iVar9 = 0;
        }
        else {
          uVar15 = _DAT_2ad99163f88;
          if (uVar6 < _DAT_2ad99163f88) {
            uVar15 = uVar6;
          }
          iVar9 = uVar6 - _DAT_2ad99163f88;
          if (uVar15 != 0) {
            uVar14 = 0;
            do {
              uVar1 = *(ushort *)(local_cc + uVar14 * 2);
              uVar2 = *(ushort *)(&DAT_2ad99163f8c + uVar14 * 2);
              uVar14 = uVar14 + 1;
              if (uVar15 <= uVar14) break;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar9 = (uint)uVar1 - (uint)uVar2;
            }
          }
        }
        goto LAB_2ad9915f8bd;
      }
      bVar17 = true;
    }
    lVar10 = lVar11 + 0xc;
    if (lVar11 == 0xc) {
      lVar10 = lVar11;
    }
    if (!bVar17) {
      lVar10 = lVar11;
    }
    if (local_cc == &DAT_2ad99163fac) goto LAB_2ad9915f9cd;
    if (local_cc != (undefined1 *)0x0) goto LAB_2ad9915f8f3;
LAB_2ad9915f9d2:
    iVar9 = 1;
  }
  bVar17 = iVar9 == 0;
LAB_2ad9915f9e4:
  local_b8 = 0;
  local_b4 = 0;
  lVar11 = 0;
  if (lVar10 != 0xc) {
    lVar11 = lVar10;
  }
  if (!bVar17) {
    lVar11 = lVar10;
  }
  FUN_2ad99140a40(&local_b8,0x2ad99160d08,0,0x2ad99171e30);
  if (lVar11 < 10) {
    FUN_2ad99140a40(&local_b8,0x2ad99163fe8,0,0x2ad99171e40);
  }
  local_88 = 0;
  local_84 = 0;
  FUN_2ad99140a40(&local_88,0x2ad99160d08,0,0x2ad99171e50);
  (*(code *)0x7ff63a0e49f0)
            (0x2ad95e68178,0x174,0xb,0x59000a,&local_88,0x590008,&local_98,0x590008,0x2ad99164008,
             0x590008,&local_68,0x590008,0x2ad99164008,0x590008,&local_78,0x590008,0x2ad99163048,
             0x590008,&local_b8,0x550005,lVar11,0x590008,0x2ad99163f48,0x590008,&local_a8);
  FUN_2ad99140a40(&local_50,&local_88,0,0x2ad99171e60);
  FUN_2ad99140000(&local_88);
  FUN_2ad99140000(&local_b8);
  FUN_2ad99140000(&local_d0);
  FUN_2ad99140000(&local_a8);
  FUN_2ad99140000(&local_f0);
  FUN_2ad99140000(&local_98);
  FUN_2ad99140000(&local_78);
  FUN_2ad99140000(&local_68);
  FUN_2ad99140a40(0x2ad99183b3c,&local_50,1,0x2ad99171e70);
  FUN_2ad99140000(&local_50);
  FUN_2ad99140000(&local_e0);
  return;
}


