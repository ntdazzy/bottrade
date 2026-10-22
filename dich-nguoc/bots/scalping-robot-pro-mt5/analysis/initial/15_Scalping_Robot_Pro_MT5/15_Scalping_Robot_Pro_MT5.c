/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 2ac334d0000 */

double FUN_2ac334d0000(void)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  undefined1 in_XMM0 [16];
  
  dVar5 = in_XMM0._0_8_;
  uVar3 = in_XMM0._4_4_ >> 0x14 & 0x7ff;
  lVar1 = (ulonglong)uVar3 - 0x3ff;
  if ((ulonglong)uVar3 < 0x433) {
    if (uVar3 < 0x3ff) {
      dVar4 = (double)((ulonglong)dVar5 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar4 = (double)((ulonglong)dVar5 & 0x8000000000000000);
      }
      return dVar4;
    }
    bVar2 = (byte)lVar1;
    if (((longlong)dVar5 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
      return (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar5 &
                     -0x10000000000000 >> (bVar2 & 0x3f));
    }
  }
  else if (lVar1 == 0x400) {
    dVar5 = dVar5 + dVar5;
  }
  return dVar5;
}



/* Address: 2ac334d0060 */

ulonglong FUN_2ac334d0060(byte param_1)

{
  longlong in_RAX;
  ulonglong in_XMM0_Qa;
  
  if ((in_RAX << (param_1 & 0x3f) & 0xfffffffffffffU) != 0) {
    return (0x8000000000000U >> (param_1 & 0x3f)) + in_RAX & -0x10000000000000 >> (param_1 & 0x3f);
  }
  return in_XMM0_Qa;
}



/* Address: 2ac334d00a0 */

void FUN_2ac334d00a0(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2ac301f9168);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 2ac334d0100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334d0100(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2ac301f9168);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_2ac334d026d;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_2ac334d026d;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2ac301f9168);
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
        if (uVar15 < 8) goto LAB_2ac334d01d0;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_2ac334d01d0;
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
LAB_2ac334d01d0:
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
          (*(code *)0x7ff63a101200)(0x2ac301f9168,puVar14);
        }
      }
      goto LAB_2ac334d026d;
    }
  }
  _DAT_2ac33505c10 = 0x13aa;
  uVar12 = 0;
LAB_2ac334d026d:
  return uVar12 & 0xffffffff;
}



/* Address: 2ac334d0280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d0280(int *param_1,longlong param_2,uint param_3)

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
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    if (param_3 - 1 < 0xfffffffe) {
      _DAT_2ac33505c10 = 0xfa2;
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
    if ((uVar6 <= *puVar5) && (puVar5[1] == 1)) goto LAB_2ac334d0357;
    if (*puVar5 != 0) {
      puVar5 = puVar5 + 1;
      *puVar5 = *puVar5 - 1;
      if (*puVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  piVar3 = (int *)(*(code *)0x7ff63a101190)(0x2ac301f9168);
  if (piVar3 == (int *)0x0) {
    _DAT_2ac33505c10 = 0x13aa;
    return;
  }
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar4 = piVar3 + 3;
  *(undefined2 *)(piVar3 + 3) = 0;
  *(int **)(param_1 + 1) = piVar4;
  *param_1 = *piVar3;
LAB_2ac334d0357:
  if (uVar8 == 0) {
    piVar4[-1] = uVar6;
    *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
    return;
  }
  uVar9 = 0;
  if (uVar8 < 8) goto LAB_2ac334d03b0;
  if ((ulonglong)((longlong)piVar4 - param_2) < 0x20) goto LAB_2ac334d03b0;
  uVar9 = (ulonglong)(uVar6 & 0x7ffffff8);
  uVar10 = 0;
  do {
    uVar2 = ((undefined8 *)(param_2 + uVar10))[1];
    *(undefined8 *)((longlong)piVar4 + uVar10) = *(undefined8 *)(param_2 + uVar10);
    ((undefined8 *)((longlong)piVar4 + uVar10))[1] = uVar2;
    uVar10 = uVar10 + 0x10;
  } while ((uVar7 * 2 & 0xfffffffffffffff0) != uVar10);
  for (; uVar9 != uVar7; uVar9 = uVar9 + 1) {
LAB_2ac334d03b0:
    *(undefined2 *)((longlong)piVar4 + uVar9 * 2) = *(undefined2 *)(param_2 + uVar9 * 2);
  }
  piVar4[-1] = uVar6;
  *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
  if (0x7ffffffe < uVar8) {
    _DAT_2ac33505c10 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2ac334d0460 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334d0460(short *param_1,short *param_2,uint param_3)

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
    _DAT_2ac33505c10 = 0xfa9;
    uVar7 = 0xffffffff;
  }
  else {
    uVar10 = *(uint *)(param_1 + -2);
    if ((uVar10 == 0) || (uVar4 = *(uint *)(param_2 + -2), uVar4 == 0)) {
      _DAT_2ac33505c10 = 0x13ab;
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
              if (uVar11 - 1 == uVar8) goto LAB_2ac334d049a;
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
                  if (uVar4 == uVar8) goto LAB_2ac334d0576;
                }
                if (uVar4 == (uint)uVar8) {
LAB_2ac334d0576:
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
LAB_2ac334d049a:
        uVar7 = 0xffffffff;
      }
    }
  }
  return uVar7;
}



/* Address: 2ac334d0590 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_2ac334d0590(uint *param_1,short *param_2)

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
  
  uVar21 = _DAT_2ac334f9154;
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
      puVar29 = (undefined1 *)(longlong)(int)_DAT_2ac334f9154;
      iVar11 = (int)((longlong)(int)uVar20 / (longlong)(int)uVar6) * _DAT_2ac334f9154;
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
LAB_2ac334d06d0:
          if ((uint)uVar24 == uVar6) goto LAB_2ac334d06d9;
          iVar19 = uVar18 + 1;
        }
        else {
          uVar24 = 1;
          do {
            uVar5 = *(ushort *)(lVar7 + (longlong)(int)uVar18 * 2 + uVar24 * 2);
            puVar14 = (undefined1 *)(ulonglong)uVar5;
            if (uVar5 != param_2[uVar24]) goto LAB_2ac334d06d0;
            uVar24 = uVar24 + 1;
          } while (uVar6 != uVar24);
LAB_2ac334d06d9:
          if (puVar15 == (uint *)0x0) {
            puVar13 = (uint *)(*(code *)0x7ff63a101190)(0x2ac301f9168,iVar11 + uVar20);
            if (puVar13 == (uint *)0x0) {
              _DAT_2ac33505c10 = 0x13aa;
              return &DAT_2ac33505c10;
            }
            puVar13[1] = 1;
            puVar13[2] = 0;
            puVar15 = puVar13 + 3;
            *(undefined2 *)(puVar13 + 3) = 0;
            local_68 = *puVar13;
            puVar14 = (undefined1 *)(ulonglong)local_68;
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) goto LAB_2ac334d0763;
          }
          else {
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) {
LAB_2ac334d0763:
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
                    if (puVar27 == puVar14) goto joined_r0x02ac334d07c6;
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
joined_r0x02ac334d07c6:
              } while (puVar27 != puVar22);
              uVar26 = uVar26 + uVar16;
            }
          }
          if (uVar21 != 0) {
            lVar17 = (longlong)(int)uVar26;
            if (uVar21 < 8) {
              puVar22 = (undefined1 *)0x0;
            }
            else if ((ulonglong)((longlong)puVar15 + lVar17 * 2 + -0x2ac334f9158) < 0x20) {
              puVar22 = (undefined1 *)0x0;
            }
            else {
              puVar14 = (undefined1 *)0x0;
              do {
                lVar2 = (longlong)puVar14 * 2;
                uVar8 = *(undefined4 *)(lVar2 + 0x2ac334f915c);
                uVar9 = *(undefined4 *)(lVar2 + 0x2ac334f9160);
                uVar10 = *(undefined4 *)(lVar2 + 0x2ac334f9164);
                puVar3 = (undefined4 *)((longlong)puVar15 + (longlong)puVar14 * 2 + lVar17 * 2);
                *puVar3 = *(undefined4 *)(&DAT_2ac334f9158 + lVar2);
                puVar3[1] = uVar8;
                puVar3[2] = uVar9;
                puVar3[3] = uVar10;
                puVar14 = puVar14 + 8;
              } while (puVar12 != puVar14);
              puVar14 = puVar12;
              puVar22 = puVar12;
              if (puVar12 == puVar29) goto LAB_2ac334d0872;
            }
            do {
              uVar5 = *(ushort *)(&DAT_2ac334f9158 + (longlong)puVar22 * 2);
              *(ushort *)((longlong)puVar15 + (longlong)puVar22 * 2 + lVar17 * 2) = uVar5;
              puVar22 = puVar22 + 1;
              puVar14 = (undefined1 *)(ulonglong)uVar5;
            } while (puVar29 != puVar22);
          }
LAB_2ac334d0872:
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
              if (uVar25 == uVar28) goto joined_r0x02ac334d0939;
            } while( true );
          }
          uVar25 = 0;
        }
        do {
          *(undefined2 *)((longlong)puVar15 + uVar25 * 2 + (longlong)(int)uVar26 * 2) =
               *(undefined2 *)(lVar7 + uVar25 * 2);
          uVar25 = uVar25 + 1;
joined_r0x02ac334d0939:
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
          puVar12 = (undefined1 *)(*(code *)0x7ff63a101200)(0x2ac301f9168);
          return puVar12;
        }
        return puVar12;
      }
      return puVar12;
    }
  }
  _DAT_2ac33505c10 = 0x13b0;
  return &DAT_2ac33505c10;
}



/* Address: 2ac334d08e0 */

void FUN_2ac334d08e0(longlong param_1)

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
      (*(code *)0x7ff63a101200)(0x2ac301f9168);
      return;
    }
  }
  return;
}



/* Address: 2ac334d09d0 */

ulonglong FUN_2ac334d09d0(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_2ac334d0add;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_2ac334d0add;
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
  cVar5 = FUN_2ac334d0100(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_2ac334d0add;
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
      if (uVar10 == uVar9) goto LAB_2ac334d0ad2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_2ac334d0ad2:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_2ac334d0add:
  return uVar8 & 0xffffffff;
}



/* Address: 2ac334d0af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d0af0(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
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
        (*(code *)0x7ff63a101200)(0x2ac301f9168,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x2ac301f9168,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_2ac33505c10 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x2ac301f9168,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_2ac334d0c80;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_2ac334d0c80:
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
      (*(code *)0x7ff63a101200)(0x2ac301f9168);
      return;
    }
  }
  return;
}



/* Address: 2ac334d0d10 */

bool FUN_2ac334d0d10(longlong param_1,longlong param_2,int param_3)

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



/* Address: 2ac334d0da0 */

undefined8 FUN_2ac334d0da0(void)

{
  return 0;
}



/* Address: 2ac334d0db0 */

void FUN_2ac334d0db0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x2ac301f9168,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ac334d0e00 */

void FUN_2ac334d0e00(undefined8 *param_1)

{
  (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*param_1,0x2ac301e7010);
  param_1[1] = 0x2ac334f8fc0;
  return;
}



/* Address: 2ac334d0e40 */

undefined4 FUN_2ac334d0e40(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_2ac334d0af0(&local_70,0x2ac334f9160,0,0x2ac334fd318);
  local_80 = 0;
  local_7c = 0;
  FUN_2ac334d0af0(&local_80,0x2ac334f9160,0,0x2ac334fd328);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x2ac301f9168,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_2ac334d1012;
    uVar4 = 0x2ac334fd368;
    uVar3 = 0x2ac334fd358;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_2ac334d1012;
    uVar4 = 0x2ac334fd348;
    uVar3 = 0x2ac334fd338;
  }
  FUN_2ac334f1430(&local_80,param_2,param_3);
  FUN_2ac334d0af0(&local_60,0x2ac33505c3c,1,uVar3);
  FUN_2ac334f1e10(param_1,&local_70,param_2);
  FUN_2ac334d0af0(&local_50,0x2ac33505c3c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x2ac301f9168,0xd,3,0x590008,0x2ac334fa3b8,0x590008,&local_50,0x590008,&local_60);
LAB_2ac334d1012:
  FUN_2ac334d00a0(&local_80);
  FUN_2ac334d00a0(&local_70);
  FUN_2ac334d00a0(&local_60);
  FUN_2ac334d00a0(&local_50);
  return uVar1;
}



/* Address: 2ac334d1050 */

void FUN_2ac334d1050(undefined8 *param_1)

{
  FUN_2ac334d00a0(param_1 + 0x41);
  FUN_2ac334d00a0((longlong)param_1 + 0x144);
  FUN_2ac334d00a0((longlong)param_1 + 0x84);
  FUN_2ac334d00a0((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*param_1,0x2ac301e7010);
  param_1[1] = 0x2ac334f8fc0;
  return;
}



/* Address: 2ac334d10c0 */

void FUN_2ac334d10c0(undefined8 *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 5) != 0) {
    iVar1 = (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,param_1 + 6,0,0);
    if (iVar1 != -1) {
      *(undefined8 *)((longlong)param_1 + 0x24) = 0;
    }
  }
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,param_1 + 6);
  (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*param_1,0x2ac3021ae00);
  param_1[1] = 0x2ac334f9080;
  (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*param_1,0x2ac301e7010);
  param_1[1] = 0x2ac334f8fc0;
  return;
}



/* Address: 2ac334d1170 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ac334d1170(void)

{
  code *pcVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  byte bVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  longlong lVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  uint uVar23;
  bool bVar24;
  double dVar25;
  double dVar26;
  undefined4 *in_stack_fffffffffffffe48;
  undefined8 in_stack_fffffffffffffe58;
  undefined4 uVar27;
  ulonglong in_stack_fffffffffffffe68;
  undefined8 in_stack_fffffffffffffe88;
  undefined4 uVar28;
  undefined4 local_168;
  longlong local_164;
  undefined4 local_158;
  longlong local_154;
  undefined4 local_148;
  undefined8 local_144;
  longlong local_138;
  undefined4 local_130;
  undefined8 local_12c;
  longlong local_120;
  undefined4 local_114;
  undefined4 local_110;
  longlong local_10c;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined8 local_e0;
  undefined8 local_d8;
  longlong local_d0;
  undefined1 local_c8 [28];
  int local_ac;
  
  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
  uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  local_110 = 0;
  local_100 = 0;
  local_10c = 0;
  local_fc = 0;
  uVar7 = (*(code *)0x7ff63a0e65d0)(0x2ac301f9168,0x2ac30187df0);
  puVar8 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ac301f9168,uVar7);
  if (puVar8 == (undefined8 *)0x0) {
LAB_2ac334d451e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1400e1000001fa);
LAB_2ac334d453e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1200e4000001fa);
LAB_2ac334d455e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x100e2000001fa);
LAB_2ac334d457e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x100e3000001fa);
LAB_2ac334d459e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c0159000001f9);
LAB_2ac334d45be:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x220b76000001f9);
LAB_2ac334d45de:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b86000001f9);
LAB_2ac334d45fe:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b87000001f9);
LAB_2ac334d461e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b88000001f9);
LAB_2ac334d463e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8b000001f9);
LAB_2ac334d465e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8c000001f9);
LAB_2ac334d467e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8d000001f9);
LAB_2ac334d469e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b90000001f9);
LAB_2ac334d46be:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b91000001f9);
LAB_2ac334d46de:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b92000001f9);
LAB_2ac334d46fe:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b93000001f9);
LAB_2ac334d471e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b94000001f9);
LAB_2ac334d473e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b97000001f9);
LAB_2ac334d475e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b98000001f9);
  }
  else {
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac30217cd0);
    puVar8[1] = 0x2ac334f8f80;
    puVar8[2] = 0;
    puVar8[3] = 0;
    *(undefined4 *)((longlong)puVar8 + 0x34) = 0;
    puVar8[7] = 0;
    *(undefined4 *)((longlong)puVar8 + 0x84) = 0;
    puVar8[0x11] = 0;
    *(undefined4 *)((longlong)puVar8 + 0x144) = 0;
    puVar8[0x29] = 0;
    *(undefined4 *)(puVar8 + 0x41) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x20c) = 0;
    puVar8 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ac301f9168,uVar7);
    if (puVar8 == (undefined8 *)0x0) goto LAB_2ac334d451e;
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac301e7010);
    puVar8[1] = 0x2ac334f8fc0;
    puVar8[2] = 0;
    puVar8[3] = 0;
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac30187df0);
    puVar8[1] = 0x2ac334f9040;
    *(undefined1 *)((longlong)puVar8 + 0x294) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x295) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x29d) = 10;
    *(undefined4 *)((longlong)puVar8 + 0x2a5) = 0;
    *(undefined4 *)((longlong)puVar8 + 0x2ad) = 1;
    uVar5 = (*(code *)0x7ff63a0c73c0)(0x2ac301f9168,0x35);
    *(undefined4 *)((longlong)puVar8 + 0x2a9) = uVar5;
    puVar8[4] = 0;
    puVar8[5] = 0;
    *(undefined4 *)(puVar8 + 6) = 0;
    FUN_2ac334d00a0((longlong)puVar8 + 0x34);
    *(undefined4 *)(puVar8 + 0x10) = 0;
    puVar8[0xf] = 0;
    puVar8[0xe] = 0;
    puVar8[0xd] = 0;
    puVar8[0xc] = 0;
    puVar8[0xb] = 0;
    puVar8[10] = 0;
    puVar8[9] = 0;
    puVar8[8] = 0;
    FUN_2ac334d00a0((longlong)puVar8 + 0x84);
    (*(code *)0x7ff63a3fad20)(puVar8 + 0x12,0,0xb4);
    FUN_2ac334d00a0((longlong)puVar8 + 0x144);
    (*(code *)0x7ff63a3fad20)(puVar8 + 0x2a,0,0xb8);
    FUN_2ac334d00a0(puVar8 + 0x41);
    *(undefined8 *)((longlong)puVar8 + 0x28c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x284) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x27c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x274) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x26c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x264) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x25c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x254) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x24c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x244) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x23c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x234) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x22c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x224) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x21c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x214) = 0;
    iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
    if (iVar6 != 0) {
      *(undefined4 *)((longlong)puVar8 + 0x2ad) = 2;
    }
    iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,7);
    if (iVar6 != 0) {
      *(undefined4 *)((longlong)puVar8 + 0x2ad) = 0;
    }
    _DAT_2ac33505af8 = uVar7;
    lVar9 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,uVar7);
    if (lVar9 == 0) goto LAB_2ac334d455e;
    *(longlong *)(lVar9 + 0x29d) = (longlong)_DAT_2ac33505e08;
    lVar9 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
    if (lVar9 == 0) goto LAB_2ac334d457e;
    lVar19 = (longlong)_DAT_2ac33505d18;
    *(longlong *)(lVar9 + 0x295) = lVar19;
    uVar7 = (*(code *)0x7ff63a0e65d0)(0x2ac301f9168,0x2ac332e1de0);
    puVar8 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ac301f9168,uVar7);
    if (puVar8 == (undefined8 *)0x0) goto LAB_2ac334d453e;
    local_d0 = lVar19;
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac30217cd0);
    puVar8[1] = 0x2ac334f8f80;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar8 = (undefined8 *)(*(code *)0x7ff63a0e6410)(0x2ac301f9168,uVar7);
    if (puVar8 == (undefined8 *)0x0) goto LAB_2ac334d453e;
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac301e7010);
    puVar8[1] = 0x2ac334f8fc0;
    puVar8[2] = 0;
    puVar8[3] = 0;
    (*(code *)0x7ff63a0e6470)(0x2ac301f9168,*puVar8,0x2ac332e1de0);
    puVar8[1] = 0x2ac334f9000;
    *(undefined4 *)(puVar8 + 4) = 0xffffffff;
    *(undefined8 *)((longlong)puVar8 + 0x24) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x2c) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x34) = 0;
    *(undefined8 *)((longlong)puVar8 + 0x3c) = 0;
    DAT_2ac33505972 = 0;
    DAT_2ac33500158 = 0;
    _DAT_2ac33505af0 = uVar7;
    uVar7 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
    (*(code *)0x7ff63a101f60)(0x2ac301f9168,uVar7,local_c8);
    if (local_ac != _DAT_2ac3350015c) {
      _DAT_2ac3350015c = local_ac;
      DAT_2ac33500158 = 0;
    }
    DAT_2ac3350007c = 1;
    _DAT_2ac33500078 = 0;
    _DAT_2ac33500094 = 0;
    DAT_2ac3350006c = 0;
    _DAT_2ac33500070 = 0;
    _DAT_2ac33500088 = 0;
    _DAT_2ac33500090 = 0;
    _DAT_2ac33500080 = 0;
    lVar19 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x20);
    lVar9 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x1f);
    if (lVar9 < lVar19) {
      lVar9 = lVar19;
    }
    _DAT_2ac33500154 = 2;
    if (2 < (int)lVar9) {
      _DAT_2ac33500154 = (int)lVar9;
    }
    iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
    if (iVar6 != 0) {
      iVar6 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x12);
      _DAT_2ac33500154 = _DAT_2ac33500154 + iVar6 * 2;
    }
    _DAT_2ac33505ad8 = 0;
    _DAT_2ac33505ae0 = 0;
    DAT_2ac33505970 = 0;
    _DAT_2ac33505ae8 = 0;
    DAT_2ac33500044 = DAT_2ac33506000;
    iVar6 = (*(code *)0x7ff63a101ec0)(0x2ac301f9168);
    lVar9 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
    lVar19 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
    dVar25 = (double)(lVar9 - lVar19) / _DAT_2ac334f89d0;
    uVar12 = (uint)((ulonglong)dVar25 >> 0x34) & 0x7ff;
    lVar9 = (ulonglong)uVar12 - 0x3ff;
    dVar26 = dVar25;
    if ((ulonglong)uVar12 < 0x433) {
      if (uVar12 < 0x3ff) {
        dVar26 = (double)((ulonglong)dVar25 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar9 != -1) {
          dVar26 = (double)((ulonglong)dVar25 & 0x8000000000000000);
        }
      }
      else {
        bVar10 = (byte)lVar9;
        if (((longlong)dVar25 << (bVar10 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar26 = (double)((0x8000000000000U >> (bVar10 & 0x3f)) + (longlong)dVar25 &
                           -0x10000000000000 >> (bVar10 & 0x3f));
        }
      }
    }
    else if (lVar9 == 0x400) {
      dVar26 = dVar25 + dVar25;
    }
    _DAT_2ac33505964 = (int)dVar26 * 0xe10 + iVar6;
    iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
    if (iVar6 == 0) {
      uVar7 = 100;
      if (DAT_2ac33505971 == '\0') {
        uVar7 = 0;
      }
      DAT_2ac33505970 = (*(code *)0x7ff63a0e7280)(0x2ac301f9168,uVar7);
      DAT_2ac335001c0 = '\0';
      if (DAT_2ac33500044 != '\0') {
        FUN_2ac334d47c0();
        _DAT_2ac33505968 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
        if (DAT_2ac33500044 != '\0') {
          FUN_2ac334d5c00();
          if ((DAT_2ac33500044 == '\0') || (_DAT_2ac33506010 == 0 && _DAT_2ac33506008 == 0))
          goto LAB_2ac334d19b6;
          _DAT_2ac33505920 = _DAT_2ac33506010 + 1;
          lVar9 = 0;
          while( true ) {
            if (_DAT_2ac33505c14 != 0) goto LAB_2ac334d19b6;
            dVar26 = *(double *)(&DAT_2ac33504650 + lVar9);
            dVar25 = *(double *)(lVar9 + 0x2ac33504c90);
            DAT_2ac335001c0 = '\x01';
            if (((dVar25 == _DAT_2ac334f89d8) && (!NAN(dVar25) && !NAN(_DAT_2ac334f89d8))) &&
               ((double)((ulonglong)dVar26 & _DAT_2ac334f89e0) <= (double)_DAT_2ac33506010)) break;
            DAT_2ac335001c0 = '\0';
            if (((dVar26 == _DAT_2ac334f89f0) && (!NAN(dVar26) && !NAN(_DAT_2ac334f89f0))) ||
               ((double)_DAT_2ac33506008 < dVar26)) break;
            if (0.0 <= dVar26) {
              bVar24 = (double)_DAT_2ac33506008 < dVar26;
            }
            else {
              bVar24 = (double)_DAT_2ac33506010 < (double)((ulonglong)dVar26 & _DAT_2ac334f89e0);
            }
            DAT_2ac335001c0 = '\x01';
            if ((_DAT_2ac334f8a00 <= dVar25 && dVar25 <= _DAT_2ac334f89f8) && !bVar24) break;
            lVar9 = lVar9 + 8;
            DAT_2ac335001c0 = '\0';
            if (lVar9 == 0x640) break;
          }
        }
      }
    }
    else {
      DAT_2ac33500044 = '\0';
      _DAT_2ac33505964 = 0;
LAB_2ac334d19b6:
      DAT_2ac335001c0 = '\0';
    }
    _DAT_2ac33500000 = 0;
    if (DAT_2ac33505e98 != '\0') {
      (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,1);
      (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
    }
    (*(code *)0x7ff63a0e21f0)(0x2ac301f9168,1);
    uVar7 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
    (*(code *)0x7ff63a0f5240)(0x2ac301f9168,uVar7,1,0);
    DAT_2ac33500160 = '\0';
    iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
    uVar12 = (uint)(in_stack_fffffffffffffe68 >> 0x20);
    if (iVar6 != 0) {
      DAT_2ac33500160 = '\x01';
LAB_2ac334d3f42:
      local_d8 = 0;
      local_e0 = 0;
      local_114 = 0;
      if (DAT_2ac33500054 == '\x01') {
        FUN_2ac334d8450(&local_d8,&local_e0,&local_114);
      }
      FUN_2ac334d8a00(local_d8,local_e0,local_114);
      if (DAT_2ac33505e40 != '\0') {
        in_stack_fffffffffffffe48 =
             (undefined4 *)((ulonglong)in_stack_fffffffffffffe48 & 0xffffffff00000000);
        uVar7 = CONCAT44(uVar27,_DAT_2ac33505e48);
        _DAT_2ac33505ac4 =
             (*(code *)0x7ff63a0e49f0)
                       (0x2ac301f9168,0x53,3,0x590008,0x2ac334f9140,0x520004,
                        in_stack_fffffffffffffe48,0x520004,uVar7);
        uVar27 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (-1 < _DAT_2ac33505ac4) goto LAB_2ac334d4043;
        uVar7 = 0x2ac334f9648;
LAB_2ac334d4353:
        (*(code *)0x7ff63a0e49f0)
                  (0x2ac301f9168,3,3,0x590008,uVar7,0x520004,_DAT_2ac33505c10,0x590008,0x2ac334f9678
                  );
        _DAT_2ac33505c10 = 0;
        uVar7 = 0xffffffff;
        _DAT_2ac33505c80 = 0;
        DAT_2ac33505c88 = 0;
LAB_2ac334d43b8:
        FUN_2ac334d00a0(&local_100);
        FUN_2ac334d00a0(&local_110);
        return uVar7;
      }
LAB_2ac334d4043:
      in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
      uVar20 = (ulonglong)in_stack_fffffffffffffe48 & 0xffffffff00000000;
      _DAT_2ac33505ac8 =
           (*(code *)0x7ff63a0e49f0)
                     (0x2ac301f9168,0x54,6,0x590008,0x2ac334f9140,0x520004,uVar20,0x520004,
                      CONCAT44(uVar27,0x14),0x520004,in_stack_fffffffffffffe68,0x580007,
                      0x4000000000000000,0x520004,CONCAT44(uVar28,3));
      if (_DAT_2ac33505ac8 < 0) {
        uVar7 = 0x2ac334f9708;
        goto LAB_2ac334d4353;
      }
      uVar20 = uVar20 & 0xffffffff00000000;
      _DAT_2ac33505acc =
           (*(code *)0x7ff63a0e49f0)
                     (0x2ac301f9168,0x54,6,0x590008,0x2ac334f9140,0x520004,uVar20,0x520004,0x14,
                      0x520004,in_stack_fffffffffffffe68 & 0xffffffff00000000,0x580007,
                      0x4000000000000000,0x520004,4);
      if (_DAT_2ac33505acc < 0) {
        uVar7 = 0x2ac334f9798;
        goto LAB_2ac334d4353;
      }
      _DAT_2ac33505ad0 =
           (*(code *)0x7ff63a0e49f0)
                     (0x2ac301f9168,0x5b,4,0x590008,0x2ac334f9140,0x520004,
                      uVar20 & 0xffffffff00000000,0x580007,_DAT_2ac33500058,0x580007,
                      0x3fc999999999999a);
      if (_DAT_2ac33505ad0 < 0) {
        uVar7 = 0x2ac334f9828;
        goto LAB_2ac334d4353;
      }
      uVar7 = 0;
      (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_d0,0,0x20);
      FUN_2ac334d0af0(&local_100,0x2ac33505c3c,1,0x2ac334fcd70);
      FUN_2ac334d0af0(&local_110,0x2ac334f98a0,0);
      lVar9 = local_fc;
      if (local_fc == 0) {
LAB_2ac334d44ed:
        (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,&local_110);
        goto LAB_2ac334d43b8;
      }
      uVar12 = *(uint *)(local_fc + -4);
      uVar20 = (ulonglong)uVar12;
      if ((uVar20 == 0) && (local_10c != 0)) goto LAB_2ac334d44ed;
      if (local_10c == 0) {
        uVar16 = 0;
        uVar18 = uVar12;
      }
      else {
        uVar16 = *(uint *)(local_10c + -4);
        uVar18 = uVar12 + uVar16;
      }
      cVar4 = FUN_2ac334d0100(&local_110);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_10c + (ulonglong)uVar16 * 2;
          if (uVar12 < 0x10) {
            uVar15 = 0;
          }
          else if ((ulonglong)(lVar19 - lVar9) < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
            do {
              uVar21 = ((undefined8 *)(lVar9 + uVar22))[1];
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(lVar9 + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar21;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d44e2;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(lVar9 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d44e2:
        *(uint *)(local_10c + -4) = uVar18;
        *(undefined2 *)(local_10c + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2ac334d44ed;
      }
      goto LAB_2ac334d459e;
    }
    if ((DAT_2ac33500160 != '\0') || (DAT_2ac33505b00 != '\0')) goto LAB_2ac334d3f42;
    uVar16 = 0;
    local_168 = 0;
    local_158 = 0;
    local_164 = 0;
    local_154 = 0;
    _DAT_2ac33505b04 = 10;
    if (DAT_2ac33505b1c == '\0') {
      _DAT_2ac33505b04 = uVar16;
    }
    _DAT_2ac33505b08 = 0x14;
    if (DAT_2ac33505b1d == '\0') {
      _DAT_2ac33505b08 = uVar16;
    }
    FUN_2ac334ef570();
    local_130 = 0;
    local_12c = 0;
    FUN_2ac334d0af0(&local_130,0x2ac33505b10,0,0x2ac334ff390);
    uVar14 = _DAT_2ac33505b04;
    local_138 = (longlong)(int)_DAT_2ac33505b08;
    lVar9 = (longlong)(int)_DAT_2ac33505b04;
    local_f0 = 0;
    local_ec = 0;
    FUN_2ac334d0af0(&local_158,&local_130,0,0x2ac334ff3a0);
    uVar18 = _DAT_2ac334f9398;
    uVar20 = (ulonglong)_DAT_2ac334f9398;
    if ((uVar20 != 0) || (local_154 == 0)) {
      if (local_154 != 0) {
        uVar16 = *(uint *)(local_154 + -4);
      }
      uVar23 = _DAT_2ac334f9398 + uVar16;
      uVar13 = 0x104;
      if ((0x103 < uVar23) &&
         ((0x7ffffffd < uVar23 || (uVar13 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar13)))) {
        uVar13 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_158,uVar13);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_154 + (ulonglong)uVar16 * 2;
          if (uVar18 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar19 - 0x2ac334f939cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f93a4);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2ac334f939c + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d1ea2;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f939c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d1ea2:
        *(uint *)(local_154 + -4) = uVar23;
        *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
        goto LAB_2ac334d1eaf;
      }
      goto LAB_2ac334d45be;
    }
LAB_2ac334d1eaf:
    FUN_2ac334d0af0(&local_f0,&local_158,0,0x2ac334ff3b0);
    iVar6 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,0,&local_f0);
    if (-1 < iVar6) {
      (*(code *)0x7ff63a0f4ce0)(0x2ac301f9168,0,&local_f0);
    }
    uVar28 = 0;
    in_stack_fffffffffffffe68 = (ulonglong)uVar12 << 0x20;
    uVar7 = CONCAT44(uVar27,0x6a);
    in_stack_fffffffffffffe48 = &local_f0;
    (*(code *)0x7ff63a0e49f0)
              (0x2ac301f9168,0x112,6,0x550005,0,0x590008,&local_f0,0x520004,uVar7,0x520004,
               in_stack_fffffffffffffe68,0x540005,0,0x580007,0);
    uVar27 = (undefined4)((ulonglong)uVar7 >> 0x20);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,0x3f4,lVar9);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,0x3f5,local_138);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,0x3f3,0);
    (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,0,&local_f0,0x3f9,0x2ac334fcc50);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,3,0);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,0xcf,0x3e6);
    uVar11 = 0;
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,&local_f0,10,0);
    bVar10 = DAT_2ac33505b2c;
    uVar5 = 0x858586;
    if (DAT_2ac33505b2d == 0) {
      uVar5 = 0;
    }
    FUN_2ac334f6fa0(0);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff3c0);
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff3d0);
    uVar12 = _DAT_2ac334f93c8;
    uVar20 = (ulonglong)_DAT_2ac334f93c8;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 == 0) {
        uVar16 = 0;
        uVar18 = _DAT_2ac334f93c8;
      }
      else {
        uVar16 = *(uint *)(local_164 + -4);
        uVar18 = _DAT_2ac334f93c8 + uVar16;
      }
      uVar13 = 0x104;
      if ((0x103 < uVar18) &&
         ((0x7ffffffd < uVar18 || (uVar13 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar13)))) {
        uVar13 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar13);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_164 + (ulonglong)uVar16 * 2;
          if (uVar12 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar19 - 0x2ac334f93ccU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f93d4);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2ac334f93cc + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d2212;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f93cc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d2212:
        *(uint *)(local_164 + -4) = uVar18;
        *(undefined2 *)(local_164 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2ac334d221f;
      }
      goto LAB_2ac334d45de;
    }
LAB_2ac334d221f:
    uVar7 = CONCAT44(uVar11,uVar5);
    local_120 = lVar9;
    FUN_2ac334f7970(&local_168,&local_158,uVar14 + 0x8c,(int)local_138 + 0x5f,uVar7,
                    (bVar10 & 1) * '\t');
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar12 = 0;
    uVar16 = 0x858586;
    if (DAT_2ac33505b2d == 0) {
      uVar16 = uVar12;
    }
    FUN_2ac334f7560(0);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff3e0);
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff3f0);
    uVar18 = _DAT_2ac334f93f8;
    uVar20 = (ulonglong)_DAT_2ac334f93f8;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar13 = _DAT_2ac334f93f8 + uVar12;
      uVar14 = 0x104;
      if ((0x103 < uVar13) &&
         ((0x7ffffffd < uVar13 || (uVar14 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar14)))) {
        uVar14 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar14);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar18 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f93fcU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9404);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f93fc + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d23f2;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f93fc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d23f2:
        *(uint *)(local_164 + -4) = uVar13;
        *(undefined2 *)(local_164 + (ulonglong)uVar13 * 2) = 0;
        goto LAB_2ac334d23ff;
      }
      goto LAB_2ac334d45fe;
    }
LAB_2ac334d23ff:
    uVar7 = CONCAT44(uVar5,uVar16);
    FUN_2ac334f7970(&local_168,&local_158,(int)local_120 + 0x7d,(int)local_138 + 0x7a,uVar7,
                    (bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar12 = 0;
    (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,0,0,0x20);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff400);
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff410);
    uVar16 = _DAT_2ac334f9418;
    uVar20 = (ulonglong)_DAT_2ac334f9418;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9418 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f941cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9424);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f941c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d25d2;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f941c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d25d2:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d25df;
      }
      goto LAB_2ac334d461e;
    }
LAB_2ac334d25df:
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,(int)local_120 + 0x8e,(int)local_138 + 0x95,uVar7,
                    (bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (DAT_2ac335001c0 == '\0') {
      uVar7 = 0x2ac334fcba0;
      uVar21 = 0x2ac334ff220;
    }
    else {
      uVar7 = 0x2ac334fcbd0;
      uVar21 = 0x2ac334ff230;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff240);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff420);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff430);
    uVar16 = _DAT_2ac334f9438;
    uVar20 = (ulonglong)_DAT_2ac334f9438;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9438 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f943cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9444);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f943c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d2832;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f943c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d2832:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d283d;
      }
      goto LAB_2ac334d463e;
    }
LAB_2ac334d283d:
    uVar12 = 0;
    uVar16 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar16 = uVar12;
    }
    uVar7 = CONCAT44(uVar5,uVar16);
    FUN_2ac334f7970(&local_168,&local_158,(int)local_120 + 0x93,(int)local_138 + 0xb1,uVar7,
                    (bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    lVar9 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x12);
    (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,(double)lVar9,0);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff440);
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff450);
    uVar16 = _DAT_2ac334f9458;
    uVar20 = (ulonglong)_DAT_2ac334f9458;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9458 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f945cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9464);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f945c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d2a32;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f945c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d2a32:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d2a3d;
      }
      goto LAB_2ac334d465e;
    }
LAB_2ac334d2a3d:
    uVar12 = 0;
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    iVar6 = (int)local_120;
    iVar17 = iVar6 + 0xa7;
    FUN_2ac334f7970(&local_168,&local_158,iVar17,(int)local_138 + 0xcc,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar7 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
    FUN_2ac334f59c0(uVar7);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff460);
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff470);
    uVar16 = _DAT_2ac334f9488;
    uVar20 = (ulonglong)_DAT_2ac334f9488;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9488 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f948cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9494);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f948c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d2c32;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f948c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d2c32:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d2c3f;
      }
      goto LAB_2ac334d467e;
    }
LAB_2ac334d2c3f:
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar17,(int)local_138 + 0xe7,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (DAT_2ac33505d50 == '\0') {
      uVar7 = 0x2ac334fccf8;
      uVar21 = 0x2ac334ff760;
    }
    else {
      uVar7 = 0x2ac334fccc8;
      uVar21 = 0x2ac334ff750;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff770);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff480);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff490);
    uVar16 = _DAT_2ac334f94b8;
    uVar20 = (ulonglong)_DAT_2ac334f94b8;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f94b8 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f94bcU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f94c4);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f94bc + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d2e82;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f94bc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d2e82:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d2e8d;
      }
      goto LAB_2ac334d469e;
    }
LAB_2ac334d2e8d:
    iVar6 = iVar6 + 0xac;
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar6,(int)local_138 + 0x103,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (DAT_2ac33505d60 == '\0') {
      uVar7 = 0x2ac334fccf8;
      uVar21 = 0x2ac334ff760;
    }
    else {
      uVar7 = 0x2ac334fccc8;
      uVar21 = 0x2ac334ff750;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff770);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff4a0);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff4b0);
    uVar16 = _DAT_2ac334f94d8;
    uVar20 = (ulonglong)_DAT_2ac334f94d8;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f94d8 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f94dcU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f94e4);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f94dc + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d30e2;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f94dc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d30e2:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d30ef;
      }
      goto LAB_2ac334d46be;
    }
LAB_2ac334d30ef:
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar6,(int)local_138 + 0x11e,uVar7,(bVar10 & 1) * '\t');
    cVar4 = DAT_2ac33505db8;
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (DAT_2ac33505db8 == '\0') {
      uVar7 = 0x2ac334fccf8;
      uVar21 = 0x2ac334ff760;
    }
    else {
      uVar7 = 0x2ac334fccc8;
      uVar21 = 0x2ac334ff750;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff770);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff4c0);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff4d0);
    uVar16 = _DAT_2ac334f94f8;
    uVar20 = (ulonglong)_DAT_2ac334f94f8;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f94f8 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar3 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar3 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f94fcU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9504);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f94fc + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d3342;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f94fc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d3342:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d334d;
      }
      goto LAB_2ac334d46de;
    }
LAB_2ac334d334d:
    iVar6 = (int)local_120 + 200;
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar6,(int)local_138 + 0x139,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (DAT_2ac33505da0 == '\0') {
      uVar7 = 0x2ac334fccf8;
      uVar21 = 0x2ac334ff760;
    }
    else {
      uVar7 = 0x2ac334fccc8;
      uVar21 = 0x2ac334ff750;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff770);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff4e0);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff4f0);
    lVar9 = local_120;
    uVar16 = _DAT_2ac334f9518;
    uVar20 = (ulonglong)_DAT_2ac334f9518;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9518 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar3 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar3 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar19 - 0x2ac334f951cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9524);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2ac334f951c + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d35b2;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f951c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d35b2:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d35bf;
      }
      goto LAB_2ac334d46fe;
    }
LAB_2ac334d35bf:
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar6,(int)local_138 + 0x155,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_148 = 0;
    local_144 = 0;
    if (cVar4 == '\0') {
      uVar7 = 0x2ac334fccf8;
      uVar21 = 0x2ac334ff760;
    }
    else {
      uVar7 = 0x2ac334fccc8;
      uVar21 = 0x2ac334ff750;
    }
    FUN_2ac334d0af0(&local_148,uVar7,0,uVar21);
    FUN_2ac334d0af0(0x2ac33505c3c,&local_148,1,0x2ac334ff770);
    FUN_2ac334d00a0(&local_148);
    FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334ff500);
    uVar12 = 0;
    FUN_2ac334d0af0(&local_168,&local_130,0,0x2ac334ff510);
    uVar16 = _DAT_2ac334f9538;
    uVar20 = (ulonglong)_DAT_2ac334f9538;
    if ((uVar20 != 0) || (local_164 == 0)) {
      if (local_164 != 0) {
        uVar12 = *(uint *)(local_164 + -4);
      }
      uVar14 = _DAT_2ac334f9538 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_168,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_164 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar19 - 0x2ac334f953cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9544);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2ac334f953c + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d3812;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f953c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d3812:
        *(uint *)(local_164 + -4) = uVar14;
        *(undefined2 *)(local_164 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d381f;
      }
      goto LAB_2ac334d471e;
    }
LAB_2ac334d381f:
    uVar12 = 0;
    uVar11 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar11 = 0;
    }
    uVar7 = CONCAT44(uVar5,uVar11);
    FUN_2ac334f7970(&local_168,&local_158,iVar6,(int)local_138 + 0x170,uVar7,(bVar10 & 1) * '\t');
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    FUN_2ac334d0af0(&local_158,&local_130,0,0x2ac334ff520);
    uVar16 = _DAT_2ac334f95b8;
    uVar20 = (ulonglong)_DAT_2ac334f95b8;
    if ((uVar20 != 0) || (local_154 == 0)) {
      if (local_154 != 0) {
        uVar12 = *(uint *)(local_154 + -4);
      }
      uVar14 = _DAT_2ac334f95b8 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_158,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar19 = local_154 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar19 - 0x2ac334f95bcU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f95c4);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2ac334f95bc + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d39b2;
          }
          do {
            *(undefined2 *)(lVar19 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f95bc + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d39b2:
        *(uint *)(local_154 + -4) = uVar14;
        *(undefined2 *)(local_154 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d39bd;
      }
      goto LAB_2ac334d473e;
    }
LAB_2ac334d39bd:
    iVar6 = (int)lVar9 + 0x14;
    uVar12 = 0;
    uVar16 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar16 = uVar12;
    }
    uVar7 = CONCAT44(uVar5,uVar16);
    FUN_2ac334f7970(&local_158,0x2ac334fcc78,iVar6,(int)local_138 + 0x1c7,uVar7,
                    (bVar10 & 1) * 9 + -2);
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    FUN_2ac334d0af0(&local_158,&local_130,0,0x2ac334ff530);
    uVar16 = _DAT_2ac334f9558;
    uVar20 = (ulonglong)_DAT_2ac334f9558;
    if ((uVar20 != 0) || (local_154 == 0)) {
      if (local_154 != 0) {
        uVar12 = *(uint *)(local_154 + -4);
      }
      uVar14 = _DAT_2ac334f9558 + uVar12;
      uVar18 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar4 = FUN_2ac334d0100(&local_158,uVar18);
      if (cVar4 != '\0') {
        if (uVar20 != 0) {
          lVar9 = local_154 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f955cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9564);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f955c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d3b52;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f955c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d3b52:
        *(uint *)(local_154 + -4) = uVar14;
        *(undefined2 *)(local_154 + (ulonglong)uVar14 * 2) = 0;
        goto LAB_2ac334d3b5d;
      }
      goto LAB_2ac334d475e;
    }
LAB_2ac334d3b5d:
    uVar12 = 0;
    uVar16 = 0x858586;
    if ((bVar2 & 1) == 0) {
      uVar16 = uVar12;
    }
    uVar7 = CONCAT44(uVar5,uVar16);
    FUN_2ac334f7970(&local_158,0x2ac334fcc78,iVar6,(int)local_138 + 0x1d5,uVar7,
                    (bVar10 & 1) * 9 + -2);
    bVar2 = DAT_2ac33505b2d;
    bVar10 = DAT_2ac33505b2c;
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    FUN_2ac334d0af0(&local_158,&local_130,0,0x2ac334ff540);
    uVar16 = _DAT_2ac334f9578;
    uVar20 = (ulonglong)_DAT_2ac334f9578;
    if ((uVar20 == 0) && (local_154 != 0)) {
LAB_2ac334d3cfd:
      uVar12 = 0;
      uVar16 = 0x858586;
      if ((bVar2 & 1) == 0) {
        uVar16 = uVar12;
      }
      uVar7 = CONCAT44(uVar5,uVar16);
      FUN_2ac334f7970(&local_158,0x2ac334fcc78,iVar6,(int)local_138 + 0x1e3,uVar7,
                      (bVar10 & 1) * 9 + -2);
      bVar2 = DAT_2ac33505b2d;
      bVar10 = DAT_2ac33505b2c;
      uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
      FUN_2ac334d0af0(&local_158,&local_130,0,0x2ac334ff550);
      uVar16 = _DAT_2ac334f9598;
      uVar20 = (ulonglong)_DAT_2ac334f9598;
      if ((uVar20 != 0) || (local_154 == 0)) {
        if (local_154 != 0) {
          uVar12 = *(uint *)(local_154 + -4);
        }
        uVar14 = _DAT_2ac334f9598 + uVar12;
        uVar18 = 0x104;
        if ((0x103 < uVar14) &&
           ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar4 = FUN_2ac334d0100(&local_158,uVar18);
        if (cVar4 == '\0') goto LAB_2ac334d479e;
        if (uVar20 != 0) {
          lVar9 = local_154 + (ulonglong)uVar12 * 2;
          if (uVar16 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar9 - 0x2ac334f959cU < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar22 = 0;
            uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f95a4);
              *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f959c + uVar22);
              ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar15 == uVar20) goto LAB_2ac334d3e92;
          }
          do {
            *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f959c + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
LAB_2ac334d3e92:
        *(uint *)(local_154 + -4) = uVar14;
        *(undefined2 *)(local_154 + (ulonglong)uVar14 * 2) = 0;
      }
      uVar11 = 0x858586;
      if ((bVar2 & 1) == 0) {
        uVar11 = 0;
      }
      FUN_2ac334f7970(&local_158,0x2ac334fcc78,iVar6,(int)local_138 + 0x1f1,CONCAT44(uVar5,uVar11),
                      (bVar10 & 1) * 9 + -2);
      FUN_2ac334d00a0(&local_f0);
      FUN_2ac334d00a0(&local_130);
      FUN_2ac334d00a0(&local_158);
      FUN_2ac334d00a0(&local_168);
      DAT_2ac33505b00 = '\x01';
      FUN_2ac334d8a00(0,0,0);
      goto LAB_2ac334d3f42;
    }
    if (local_154 != 0) {
      uVar12 = *(uint *)(local_154 + -4);
    }
    uVar14 = _DAT_2ac334f9578 + uVar12;
    uVar18 = 0x104;
    if ((0x103 < uVar14) &&
       ((0x7ffffffd < uVar14 || (uVar18 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar18)))) {
      uVar18 = 0x7ffffffe;
    }
    cVar4 = FUN_2ac334d0100(&local_158,uVar18);
    if (cVar4 != '\0') {
      if (uVar20 != 0) {
        lVar9 = local_154 + (ulonglong)uVar12 * 2;
        if (uVar16 < 0x10) {
          uVar15 = 0;
        }
        else if (lVar9 - 0x2ac334f957cU < 0x20) {
          uVar15 = 0;
        }
        else {
          uVar22 = 0;
          uVar15 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar7 = *(undefined8 *)(uVar22 + 0x2ac334f9584);
            *(undefined8 *)(lVar9 + uVar22) = *(undefined8 *)(&DAT_2ac334f957c + uVar22);
            ((undefined8 *)(lVar9 + uVar22))[1] = uVar7;
            uVar22 = uVar22 + 0x10;
          } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar15 == uVar20) goto LAB_2ac334d3cf2;
        }
        do {
          *(undefined2 *)(lVar9 + uVar15 * 2) = *(undefined2 *)(&DAT_2ac334f957c + uVar15 * 2);
          uVar15 = uVar15 + 1;
        } while (uVar20 != uVar15);
      }
LAB_2ac334d3cf2:
      *(uint *)(local_154 + -4) = uVar14;
      *(undefined2 *)(local_154 + (ulonglong)uVar14 * 2) = 0;
      goto LAB_2ac334d3cfd;
    }
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b99000001f9);
LAB_2ac334d479e:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b9a000001f9);
  pcVar1 = (code *)swi(3);
  uVar7 = (*pcVar1)();
  return uVar7;
}



/* Address: 2ac334d4420 */

ulonglong FUN_2ac334d4420(void)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  char cVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  ulonglong unaff_RDI;
  ulonglong uVar6;
  ulonglong unaff_R14;
  undefined1 in_stack_000000d8 [16];
  
  uVar2 = (uint)unaff_R14;
  cVar4 = FUN_2ac334d0100(&stack0x000000d8);
  if (cVar4 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c0159000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x220b76000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b86000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b87000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b88000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8b000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8c000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b8d000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b90000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b91000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b92000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b93000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b94000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b97000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b98000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b99000001f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b0b9a000001f9);
    pcVar1 = (code *)swi(3);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  if (unaff_R14 != 0) {
    if (uVar2 < 0x10) {
      uVar5 = 0;
    }
    else if ((ulonglong)(in_stack_000000d8._4_8_ - unaff_RBX) < 0x20) {
      uVar5 = 0;
    }
    else {
      uVar6 = 0;
      uVar5 = (ulonglong)(uVar2 & 0xfffffff8);
      do {
        uVar3 = ((undefined8 *)(unaff_RBX + uVar6))[1];
        *(undefined8 *)(in_stack_000000d8._4_8_ + uVar6) = *(undefined8 *)(unaff_RBX + uVar6);
        ((undefined8 *)(in_stack_000000d8._4_8_ + uVar6))[1] = uVar3;
        uVar6 = uVar6 + 0x10;
      } while ((unaff_R14 * 2 & 0xfffffffffffffff0) != uVar6);
      if (uVar5 == unaff_R14) goto LAB_2ac334d44e2;
    }
    do {
      *(undefined2 *)(in_stack_000000d8._4_8_ + uVar5 * 2) = *(undefined2 *)(unaff_RBX + uVar5 * 2);
      uVar5 = uVar5 + 1;
    } while (unaff_R14 != uVar5);
  }
LAB_2ac334d44e2:
  *(uint *)(in_stack_000000d8._4_8_ + -4) = uVar2;
  *(undefined2 *)(in_stack_000000d8._4_8_ + (unaff_R14 & 0xffffffff) * 2) = 0;
  (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008);
  FUN_2ac334d00a0(&stack0x000000e8);
  FUN_2ac334d00a0(&stack0x000000d8);
  return unaff_RDI & 0xffffffff;
}



/* Address: 2ac334d47c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d47c0(void)

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
  (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fc148);
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
  FUN_2ac334d0af0(&local_f0,0x2ac334f9140,0,0x2ac334fece0);
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
  FUN_2ac334d0af0(&local_148,0x2ac334f9160,0,0x2ac334fecf0);
  local_100 = 0;
  local_fc = 0;
  FUN_2ac334d0af0(&local_100,0x2ac334fc230,0,0x2ac334fed00);
  iVar4 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
  if (iVar4 == 0) {
    _DAT_2ac33505c10 = 0;
    _DAT_2ac33505c80 = 0;
    DAT_2ac33505c88 = 0;
    lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ac301f9168,0x2ac334fc268,1,1);
    if (lVar10 == -1) {
      lVar10 = 0;
    }
    else {
      lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ac301f9168,0x2ac334fc268,3,1);
      if ((0 < lVar10) &&
         (lVar11 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0), lVar11 - lVar10 < 0x136)) {
        lVar11 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
        (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,lVar11 - lVar10,0,0x20);
        FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fed10);
        FUN_2ac334d0af0(&local_120,0x2ac334fc2c0);
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
            cVar3 = FUN_2ac334d0100(&local_120);
            if (cVar3 == '\0') goto LAB_2ac334d5bdf;
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
                if (uVar16 == uVar13) goto LAB_2ac334d52a2;
              }
              do {
                *(undefined2 *)(lVar11 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
                uVar16 = uVar16 + 1;
              } while (uVar13 != uVar16);
            }
LAB_2ac334d52a2:
            *(uint *)(local_11c + -4) = uVar17;
            *(undefined2 *)(local_11c + (ulonglong)uVar17 * 2) = 0;
          }
        }
        uVar12 = 0;
        FUN_2ac334d0af0(&local_110,&local_120,0,0x2ac334fed30);
        uVar17 = _DAT_2ac334fc2d8;
        uVar13 = (ulonglong)_DAT_2ac334fc2d8;
        if ((uVar13 != 0) || (local_10c == 0)) {
          if (local_10c != 0) {
            uVar12 = *(uint *)(local_10c + -4);
          }
          uVar18 = _DAT_2ac334fc2d8 + uVar12;
          uVar15 = 0x104;
          if ((0x103 < uVar18) &&
             ((0x7ffffffd < uVar18 || (uVar15 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar15)))) {
            uVar15 = 0x7ffffffe;
          }
          cVar3 = FUN_2ac334d0100(&local_110,uVar15);
          if (cVar3 == '\0') {
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4c0949000001f9);
LAB_2ac334d5bdf:
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x240949000001f9);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          if (uVar13 != 0) {
            lVar10 = local_10c + (ulonglong)uVar12 * 2;
            if (uVar17 < 0x10) {
              uVar16 = 0;
            }
            else if (lVar10 - 0x2ac334fc2dcU < 0x20) {
              uVar16 = 0;
            }
            else {
              uVar21 = 0;
              uVar16 = (ulonglong)(uVar17 & 0xfffffff8);
              do {
                uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc2e0);
                uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc2e4);
                uVar14 = *(undefined4 *)(uVar21 + 0x2ac334fc2e8);
                puVar26 = (undefined4 *)(lVar10 + uVar21);
                *puVar26 = *(undefined4 *)(&DAT_2ac334fc2dc + uVar21);
                puVar26[1] = uVar9;
                puVar26[2] = uVar8;
                puVar26[3] = uVar14;
                uVar21 = uVar21 + 0x10;
              } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar21);
              if (uVar16 == uVar13) goto LAB_2ac334d53d2;
            }
            do {
              *(undefined2 *)(lVar10 + uVar16 * 2) = *(undefined2 *)(&DAT_2ac334fc2dc + uVar16 * 2);
              uVar16 = uVar16 + 1;
            } while (uVar13 != uVar16);
          }
LAB_2ac334d53d2:
          *(uint *)(local_10c + -4) = uVar18;
          *(undefined2 *)(local_10c + (ulonglong)uVar18 * 2) = 0;
        }
        (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,&local_110);
        uVar20 = CONCAT44(uVar6,0x10a5);
        uVar22 = CONCAT44(uVar5,0x520004);
        iVar4 = (*(code *)0x7ff63a0e49f0)
                          (0x2ac301f9168,0x150,2,0x590008,0x2ac334fc268,uVar22,uVar20);
        uVar5 = (undefined4)((ulonglong)uVar22 >> 0x20);
        uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
        if (iVar4 == -1) {
          (*(code *)0x7ff63a0e49f0)
                    (0x2ac301f9168,2,2,0x590008,0x2ac334fc450,CONCAT44(uVar5,0x520004),
                     CONCAT44(uVar6,_DAT_2ac33505c10));
          uVar22 = 0x2ac334fed80;
          goto LAB_2ac334d4fee;
        }
        uVar9 = (*(code *)0x7ff63a0e7ec0)(0x2ac301f9168,iVar4);
        (*(code *)0x7ff63a0eaa60)(0x2ac301f9168,iVar4,uVar9);
        FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fed40);
        FUN_2ac334d0af0(&local_148,&local_138,0,0x2ac334fed50);
        if (local_144 == (short *)0x0) {
          uVar9 = 0xfa9;
        }
        else {
          uVar12 = *(uint *)(local_144 + -2);
          uVar8 = 0x13ab;
          uVar9 = uVar8;
          if ((uVar12 != 0) && (_DAT_2ac334fc328 != 0)) {
            uVar9 = _DAT_2ac33505c10;
            if (local_144 == (short *)0x2ac334fc32c) goto LAB_2ac334d57a2;
            if ((_DAT_2ac334fc328 <= uVar12) &&
               (uVar17 = (uVar12 - _DAT_2ac334fc328) + 1, uVar17 != 0)) {
              uVar13 = (ulonglong)uVar17;
              if (_DAT_2ac334fc328 < 2) {
                if (*local_144 == 0x44) {
LAB_2ac334d57a2:
                  uVar9 = uVar8;
                  if (_DAT_2ac334fc358 != 0) {
                    if (local_144 == (short *)0x2ac334fc35c) goto LAB_2ac334d5a4e;
                    uVar9 = _DAT_2ac33505c10;
                    if ((_DAT_2ac334fc358 <= uVar12) &&
                       (uVar12 = (uVar12 - _DAT_2ac334fc358) + 1, uVar12 != 0)) {
                      uVar13 = (ulonglong)uVar12;
                      if (_DAT_2ac334fc358 == 1) {
                        if (*local_144 == 0x65) {
LAB_2ac334d5a4e:
                          if (0 < _DAT_2ac33505968) {
                            lVar10 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
                            _DAT_2ac33505968 = lVar10 + -0x3840;
                            if (DAT_2ac3350591c == '\0') {
                              _DAT_2ac33505968 = lVar10;
                            }
                            _DAT_2ac33505968 = _DAT_2ac33505968 + 0x9b;
                          }
                          (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fc3e8);
                          (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
                          lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ac301f9168,0x2ac334fc490,1,1);
                          uVar22 = 0x2ac334fed80;
                          if (lVar10 != -1) {
                            uVar22 = 0x2ac334fed80;
                            iVar4 = (*(code *)0x7ff63a0e49f0)
                                              (0x2ac301f9168,0x150,2,0x590008,0x2ac334fc490,
                                               CONCAT44(uVar5,0x520004),CONCAT44(uVar6,0x10a5));
                            if (iVar4 != -1) {
                              uVar5 = (*(code *)0x7ff63a0e7ec0)(0x2ac301f9168,iVar4);
                              (*(code *)0x7ff63a0eaa60)(0x2ac301f9168,iVar4,uVar5);
                              FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fed60);
                              FUN_2ac334d0af0(&local_148,&local_138,0,0x2ac334fed70);
                              (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
                            }
                          }
                          goto LAB_2ac334d4fee;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar13 - 1 == uVar16) goto LAB_2ac334d5594;
                          lVar10 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (local_144[lVar10] != 0x65);
                        if (uVar16 < uVar13) {
LAB_2ac334d5a46:
                          if (-1 < (int)uVar16) goto LAB_2ac334d5a4e;
                        }
                      }
                      else {
                        bVar23 = true;
                        uVar21 = 1;
                        uVar16 = 0;
                        do {
                          iVar7 = (int)uVar21;
                          if (local_144[uVar16] == 0x65) {
                            psVar19 = (short *)&DAT_2ac334fc35e;
                            lVar10 = (ulonglong)_DAT_2ac334fc358 - 1;
                            while (local_144[uVar21] == *psVar19) {
                              psVar19 = psVar19 + 1;
                              uVar21 = (ulonglong)((int)uVar21 + 1);
                              lVar10 = lVar10 + -1;
                              if (lVar10 == 0) goto LAB_2ac334d5a3c;
                            }
                            if ((int)lVar10 == 0) {
LAB_2ac334d5a3c:
                              if (bVar23) goto LAB_2ac334d5a46;
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
                    if (uVar13 - 1 == uVar16) goto LAB_2ac334d5594;
                    lVar10 = uVar16 + 1;
                    uVar16 = uVar16 + 1;
                  } while (local_144[lVar10] != 0x44);
                  if (uVar16 < uVar13) {
LAB_2ac334d5799:
                    if (-1 < (int)uVar16) goto LAB_2ac334d57a2;
                  }
                }
              }
              else {
                bVar23 = true;
                uVar16 = 0;
                local_128 = (ulonglong)_DAT_2ac334fc328 - 1;
                uVar21 = 1;
                do {
                  iVar7 = (int)uVar21;
                  if (local_144[uVar16] == 0x44) {
                    psVar19 = (short *)&DAT_2ac334fc32e;
                    lVar10 = local_128;
                    while (local_144[uVar21] == *psVar19) {
                      psVar19 = psVar19 + 1;
                      uVar21 = (ulonglong)((int)uVar21 + 1);
                      lVar10 = lVar10 + -1;
                      if (lVar10 == 0) goto LAB_2ac334d5785;
                    }
                    if ((int)lVar10 == 0) {
LAB_2ac334d5785:
                      if (bVar23) goto LAB_2ac334d5799;
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
LAB_2ac334d5594:
        _DAT_2ac33505c10 = uVar9;
        (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
        uVar22 = 0x2ac334fed80;
        goto LAB_2ac334d4fee;
      }
    }
    uVar5 = 0x2ac;
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fc4e0);
    (*(code *)0x7ff63a0e7cc0)(0x2ac301f9168,0x2ac334fc268,0x1000);
    puVar26 = &local_e0;
    puVar25 = &local_b0;
    puVar24 = &local_78;
    iVar4 = (*(code *)0x7ff63a0e5a80)
                      (0x2ac301f9168,0x2ac334fc508,&local_100,&local_f0,CONCAT44(uVar5,15000),
                       puVar24,puVar25,puVar26);
    uVar5 = (undefined4)((ulonglong)puVar26 >> 0x20);
    if (iVar4 == -1) {
      uVar22 = 0x2ac334fc568;
    }
    else {
      uVar22 = CONCAT44((int)((ulonglong)puVar24 >> 0x20),0x520004);
      uVar20 = CONCAT44((int)((ulonglong)puVar25 >> 0x20),(undefined4)local_a8);
      (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0xd,2,0x590008,0x2ac334fc608,uVar22,uVar20);
      uVar6 = 0x2ac;
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0x10a6);
      uVar22 = CONCAT44((int)((ulonglong)uVar22 >> 0x20),0x520004);
      iVar7 = (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0x150,2,0x590008,0x2ac334fc268,uVar22,uVar20);
      uVar9 = (undefined4)((ulonglong)uVar22 >> 0x20);
      uVar8 = (undefined4)((ulonglong)uVar20 >> 0x20);
      if (iVar7 != -1) {
        lVar10 = (*(code *)0x7ff63a0ec0d0)(0x2ac301f9168,0x2ac334fc268,3,1);
        (*(code *)0x7ff63a0e8710)
                  (0x2ac301f9168,iVar7,&local_b0,0,CONCAT44(uVar6,(undefined4)local_a8));
        (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar7);
      }
      uVar22 = 0x2ac334fedf0;
      if (iVar4 < 0) goto LAB_2ac334d4fee;
      uVar20 = CONCAT44(uVar8,0x10a5);
      uVar22 = CONCAT44(uVar9,0x520004);
      iVar4 = (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0x150,2,0x590008,0x2ac334fc268,uVar22,uVar20);
      uVar9 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar6 = (undefined4)((ulonglong)uVar22 >> 0x20);
      if (iVar4 != -1) {
        uVar8 = (*(code *)0x7ff63a0e7ec0)(0x2ac301f9168,iVar4);
        (*(code *)0x7ff63a0eaa60)(0x2ac301f9168,iVar4,uVar8);
        FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fed90);
        FUN_2ac334d0af0(&local_148,&local_138,0,0x2ac334feda0);
        if (local_144 == (short *)0x0) {
          uVar8 = 0xfa9;
        }
        else {
          uVar12 = *(uint *)(local_144 + -2);
          uVar14 = 0x13ab;
          uVar8 = uVar14;
          if ((uVar12 != 0) && (_DAT_2ac334fc328 != 0)) {
            uVar8 = _DAT_2ac33505c10;
            if (local_144 == (short *)0x2ac334fc32c) goto LAB_2ac334d566a;
            if ((_DAT_2ac334fc328 <= uVar12) &&
               (uVar17 = (uVar12 - _DAT_2ac334fc328) + 1, uVar17 != 0)) {
              uVar13 = (ulonglong)uVar17;
              if (_DAT_2ac334fc328 < 2) {
                if (*local_144 == 0x44) {
LAB_2ac334d566a:
                  uVar8 = uVar14;
                  if (_DAT_2ac334fc358 != 0) {
                    if (local_144 == (short *)0x2ac334fc35c) goto LAB_2ac334d58a8;
                    uVar8 = _DAT_2ac33505c10;
                    if ((_DAT_2ac334fc358 <= uVar12) &&
                       (uVar12 = (uVar12 - _DAT_2ac334fc358) + 1, uVar12 != 0)) {
                      uVar13 = (ulonglong)uVar12;
                      if (_DAT_2ac334fc358 == 1) {
                        if (*local_144 == 0x65) {
LAB_2ac334d58a8:
                          if (0 < _DAT_2ac33505968) {
                            lVar10 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
                            _DAT_2ac33505968 = lVar10 + -0x3840;
                            if (DAT_2ac3350591c == '\0') {
                              _DAT_2ac33505968 = lVar10;
                            }
                            _DAT_2ac33505968 = _DAT_2ac33505968 + 0x9b;
                          }
                          (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fc6a0);
                          (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
                          iVar4 = (*(code *)0x7ff63a0e49f0)
                                            (0x2ac301f9168,0x150,2,0x590008,0x2ac334fc490,
                                             CONCAT44(uVar6,0x520004),CONCAT44(uVar9,0x10a5));
                          if (iVar4 != -1) {
                            uVar5 = (*(code *)0x7ff63a0e7ec0)(0x2ac301f9168,iVar4);
                            (*(code *)0x7ff63a0eaa60)(0x2ac301f9168,iVar4,uVar5);
                            FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fedb0);
                            FUN_2ac334d0af0(&local_148,&local_138,0,0x2ac334fedc0);
                            (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
                          }
                          goto LAB_2ac334d4fe4;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar13 - 1 == uVar16) goto LAB_2ac334d50fe;
                          lVar11 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (local_144[lVar11] != 0x65);
                        if (uVar16 < uVar13) {
LAB_2ac334d58a0:
                          if (-1 < (int)uVar16) goto LAB_2ac334d58a8;
                        }
                      }
                      else {
                        bVar23 = true;
                        uVar21 = 1;
                        uVar16 = 0;
                        local_128 = (ulonglong)_DAT_2ac334fc358 - 1;
                        do {
                          iVar7 = (int)uVar21;
                          if (local_144[uVar16] == 0x65) {
                            psVar19 = (short *)&DAT_2ac334fc35e;
                            lVar11 = local_128;
                            while (local_144[uVar21] == *psVar19) {
                              psVar19 = psVar19 + 1;
                              uVar21 = (ulonglong)((int)uVar21 + 1);
                              lVar11 = lVar11 + -1;
                              if (lVar11 == 0) goto LAB_2ac334d5890;
                            }
                            if ((int)lVar11 == 0) {
LAB_2ac334d5890:
                              if (bVar23) goto LAB_2ac334d58a0;
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
                    if (uVar13 - 1 == uVar16) goto LAB_2ac334d50fe;
                    lVar11 = uVar16 + 1;
                    uVar16 = uVar16 + 1;
                  } while (local_144[lVar11] != 0x44);
                  if (uVar16 < uVar13) {
LAB_2ac334d5661:
                    if (-1 < (int)uVar16) goto LAB_2ac334d566a;
                  }
                }
              }
              else {
                uVar17 = 1;
                uVar16 = 0;
                local_128 = (ulonglong)_DAT_2ac334fc328 - 1;
                bVar23 = true;
                do {
                  if (local_144[uVar16] == 0x44) {
                    psVar19 = (short *)&DAT_2ac334fc32e;
                    lVar11 = local_128;
                    uVar15 = uVar17;
                    while (local_144[uVar15] == *psVar19) {
                      psVar19 = psVar19 + 1;
                      uVar15 = uVar15 + 1;
                      lVar11 = lVar11 + -1;
                      if (lVar11 == 0) goto LAB_2ac334d5643;
                    }
                    if ((int)lVar11 == 0) {
LAB_2ac334d5643:
                      if (bVar23) goto LAB_2ac334d5661;
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
LAB_2ac334d50fe:
        _DAT_2ac33505c10 = uVar8;
        (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,iVar4);
        (*(code *)0x7ff63a0ff6c0)(0x2ac301f9168,_DAT_2ac33505968,0x54,&local_138);
        (*(code *)0x7ff63a0ff6c0)(0x2ac301f9168,lVar10,0x54,&local_120);
        uVar9 = 0x2ac;
        (*(code *)0x7ff63a0e49f0)
                  (0x2ac301f9168,0xd,3,0x590008,0x2ac334fc740,CONCAT44(uVar6,0x590008),&local_120,
                   CONCAT44(uVar5,0x590008),&local_138);
        cVar3 = (*(code *)0x7ff63a0e7d80)
                          (0x2ac301f9168,0x2ac334fc268,0x1000,0x2ac334fc490,CONCAT44(uVar9,0x1200));
        if (cVar3 != '\0') {
          uVar22 = 0x2ac334fc790;
          goto LAB_2ac334d4c79;
        }
        goto LAB_2ac334d4fe4;
      }
      uVar22 = 0x2ac334fc450;
    }
    uVar20 = 2;
LAB_2ac334d4fdb:
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,uVar20,0x590008,uVar22);
  }
  else {
    cVar3 = (*(code *)0x7ff63a0e7d20)(0x2ac301f9168,0x2ac334fc268,0x1000);
    if (cVar3 == '\0') {
      uVar22 = 0x2ac334fc7f0;
LAB_2ac334d4c79:
      uVar20 = 1;
      goto LAB_2ac334d4fdb;
    }
    _DAT_2ac33505c10 = 0;
    _DAT_2ac33505c80 = 0;
    DAT_2ac33505c88 = 0;
    uVar5 = (*(code *)0x7ff63a0e49f0)
                      (0x2ac301f9168,0x150,2,0x590008,0x2ac334fc268,CONCAT44(uVar5,0x520004),
                       CONCAT44(uVar6,0x1025));
    uVar6 = (*(code *)0x7ff63a0e7ec0)(0x2ac301f9168,uVar5);
    (*(code *)0x7ff63a0eaa60)(0x2ac301f9168,uVar5,uVar6);
    FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fedd0);
    FUN_2ac334d0af0(&local_148,&local_138,0,0x2ac334fede0);
    (*(code *)0x7ff63a0e7e80)(0x2ac301f9168,uVar5);
  }
LAB_2ac334d4fe4:
  uVar22 = 0x2ac334fedf0;
LAB_2ac334d4fee:
  FUN_2ac334d0af0(&local_c0,&local_148,0,uVar22);
  FUN_2ac334d00a0(&local_100);
  FUN_2ac334d00a0(&local_148);
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_b0);
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_78);
  FUN_2ac334d00a0(&local_e0);
  FUN_2ac334d00a0(&local_f0);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_c0,1,0x2ac334fee00);
  FUN_2ac334d00a0(&local_c0);
  FUN_2ac334d00a0(&local_138);
  FUN_2ac334d00a0(&local_120);
  FUN_2ac334d00a0(&local_110);
  FUN_2ac334d0af0(&local_d0,0x2ac33505c3c,1,0x2ac334fecc0);
  FUN_2ac334d0af0(0x2ac335001c8,&local_d0,0,0x2ac334fecd0);
  FUN_2ac334d00a0(&local_d0);
  return;
}



/* Address: 2ac334d5c00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d5c00(void)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  code *pcVar6;
  undefined2 *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  short *psVar12;
  undefined8 uVar13;
  int iVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined1 *puVar17;
  uint uVar18;
  longlong lVar19;
  uint uVar20;
  short *psVar21;
  undefined1 *puVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  uint uVar30;
  longlong lVar31;
  longlong lVar32;
  bool bVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 local_1e8;
  undefined1 *local_1e4;
  longlong local_1d8;
  int local_1cc;
  longlong local_1c8;
  undefined4 local_1c0;
  undefined8 local_1bc;
  undefined4 local_1b0;
  short *local_1ac;
  undefined4 local_1a0;
  undefined8 local_19c;
  undefined4 local_190;
  undefined8 local_18c;
  undefined4 local_180;
  undefined8 local_17c;
  longlong local_170;
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
  local_10c = &DAT_2ac334fbc5c;
  local_104 = 0;
  local_100 = 0x2ac334fbc7c;
  local_f8 = 0;
  local_f4 = 0x2ac334fbc9c;
  local_ec = 0;
  local_e8 = 0x2ac334fbccc;
  local_e0 = 0;
  local_dc = 0x2ac334fbcfc;
  local_d4 = 0;
  local_d0 = 0x2ac334fbd2c;
  local_c8 = 0;
  local_c4 = 0x2ac334fbd6c;
  local_164 = &DAT_2ac334fbdac;
  local_15c = 0;
  local_158 = 0x2ac334fbdcc;
  local_150 = 0;
  local_14c = 0x2ac334fbdfc;
  local_144 = 0;
  local_140 = 0x2ac334fbe2c;
  local_138 = 0;
  local_134 = 0x2ac334fbe5c;
  local_12c = 0;
  local_128 = 0x2ac334fbe8c;
  local_120 = 0;
  local_11c = 0x2ac334fbebc;
  FUN_2ac334d0af0(&local_1b0,0x2ac334f9160,0,0x2ac334fea20);
  uVar36 = 0xfa9;
  local_180 = 0;
  local_17c = 0;
  if ((_DAT_2ac33505c2c == 0) || (_DAT_2ac33505c2c == 0xc)) {
LAB_2ac334d5ec9:
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else {
      _DAT_2ac33505c10 = uVar36;
      if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
         (cVar9 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar7 = _DAT_2ac33505c40, cVar9 != '\0')) {
        *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
        *puVar7 = 0;
      }
    }
  }
  else {
    iVar11 = *(int *)(_DAT_2ac33505c2c + -4);
    if (iVar11 == 0) {
      uVar36 = 0x13ab;
      goto LAB_2ac334d5ec9;
    }
    iVar14 = 3;
    if (iVar11 < 3) {
      _DAT_2ac33505c10 = 0x13ab;
      iVar14 = iVar11;
    }
    FUN_2ac334d0280(0x2ac33505c3c,_DAT_2ac33505c2c,iVar14);
  }
  FUN_2ac334d0af0(&local_1e8,0x2ac33505c3c,1,0x2ac334fea30);
  FUN_2ac334d0af0(&local_180,&local_1e8,0,0x2ac334fea40);
  uVar36 = 0xfa9;
  local_1c0 = 0;
  local_1bc = 0;
  if ((_DAT_2ac33505c2c != 0) && (_DAT_2ac33505c2c != 0xc)) {
    uVar36 = 0x13ab;
    if (3 < *(uint *)(_DAT_2ac33505c2c + -4)) {
      iVar14 = *(uint *)(_DAT_2ac33505c2c + -4) - 3;
      iVar11 = 3;
      if (iVar14 < 3) {
        _DAT_2ac33505c10 = 0x13ab;
        iVar11 = iVar14;
      }
      FUN_2ac334d0280(0x2ac33505c3c,_DAT_2ac33505c2c + 6,iVar11);
      goto LAB_2ac334d6042;
    }
  }
  if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
    _DAT_2ac33505c10 = 0xfa9;
  }
  else {
    _DAT_2ac33505c10 = uVar36;
    if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
       (cVar9 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar7 = _DAT_2ac33505c40, cVar9 != '\0')) {
      *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
      *puVar7 = 0;
    }
  }
LAB_2ac334d6042:
  FUN_2ac334d0af0(&local_1e8,0x2ac33505c3c,1,0x2ac334fea50);
  FUN_2ac334d0af0(&local_1c0,&local_1e8,0,0x2ac334fea60);
  cVar8 = DAT_2ac33506020;
  cVar9 = DAT_2ac33506018;
  _DAT_2ac33504650 = _DAT_2ac334f8a10;
  uRam000002ac33504654 = uRam000002ac334f8a14;
  uRam000002ac33504658 = uRam000002ac334f8a18;
  uRam000002ac3350465c = uRam000002ac334f8a1c;
  _DAT_2ac33504660 = _DAT_2ac334f8a10;
  uRam000002ac33504664 = uRam000002ac334f8a14;
  uRam000002ac33504668 = uRam000002ac334f8a18;
  uRam000002ac3350466c = uRam000002ac334f8a1c;
  _DAT_2ac33504670 = _DAT_2ac334f8a10;
  uRam000002ac33504674 = uRam000002ac334f8a14;
  uRam000002ac33504678 = uRam000002ac334f8a18;
  uRam000002ac3350467c = uRam000002ac334f8a1c;
  _DAT_2ac33504680 = _DAT_2ac334f8a10;
  uRam000002ac33504684 = uRam000002ac334f8a14;
  uRam000002ac33504688 = uRam000002ac334f8a18;
  uRam000002ac3350468c = uRam000002ac334f8a1c;
  _DAT_2ac33504690 = _DAT_2ac334f8a10;
  uRam000002ac33504694 = uRam000002ac334f8a14;
  uRam000002ac33504698 = uRam000002ac334f8a18;
  uRam000002ac3350469c = uRam000002ac334f8a1c;
  _DAT_2ac335046a0 = _DAT_2ac334f8a10;
  uRam000002ac335046a4 = uRam000002ac334f8a14;
  uRam000002ac335046a8 = uRam000002ac334f8a18;
  uRam000002ac335046ac = uRam000002ac334f8a1c;
  _DAT_2ac335046b0 = _DAT_2ac334f8a10;
  uRam000002ac335046b4 = uRam000002ac334f8a14;
  uRam000002ac335046b8 = uRam000002ac334f8a18;
  uRam000002ac335046bc = uRam000002ac334f8a1c;
  _DAT_2ac335046c0 = _DAT_2ac334f8a10;
  uRam000002ac335046c4 = uRam000002ac334f8a14;
  uRam000002ac335046c8 = uRam000002ac334f8a18;
  uRam000002ac335046cc = uRam000002ac334f8a1c;
  _DAT_2ac335046d0 = _DAT_2ac334f8a10;
  uRam000002ac335046d4 = uRam000002ac334f8a14;
  uRam000002ac335046d8 = uRam000002ac334f8a18;
  uRam000002ac335046dc = uRam000002ac334f8a1c;
  _DAT_2ac335046e0 = _DAT_2ac334f8a10;
  uRam000002ac335046e4 = uRam000002ac334f8a14;
  uRam000002ac335046e8 = uRam000002ac334f8a18;
  uRam000002ac335046ec = uRam000002ac334f8a1c;
  _DAT_2ac335046f0 = _DAT_2ac334f8a10;
  uRam000002ac335046f4 = uRam000002ac334f8a14;
  uRam000002ac335046f8 = uRam000002ac334f8a18;
  uRam000002ac335046fc = uRam000002ac334f8a1c;
  _DAT_2ac33504700 = _DAT_2ac334f8a10;
  uRam000002ac33504704 = uRam000002ac334f8a14;
  uRam000002ac33504708 = uRam000002ac334f8a18;
  uRam000002ac3350470c = uRam000002ac334f8a1c;
  _DAT_2ac33504710 = _DAT_2ac334f8a10;
  uRam000002ac33504714 = uRam000002ac334f8a14;
  uRam000002ac33504718 = uRam000002ac334f8a18;
  uRam000002ac3350471c = uRam000002ac334f8a1c;
  _DAT_2ac33504720 = _DAT_2ac334f8a10;
  uRam000002ac33504724 = uRam000002ac334f8a14;
  uRam000002ac33504728 = uRam000002ac334f8a18;
  uRam000002ac3350472c = uRam000002ac334f8a1c;
  _DAT_2ac33504730 = _DAT_2ac334f8a10;
  uRam000002ac33504734 = uRam000002ac334f8a14;
  uRam000002ac33504738 = uRam000002ac334f8a18;
  uRam000002ac3350473c = uRam000002ac334f8a1c;
  _DAT_2ac33504740 = _DAT_2ac334f8a10;
  uRam000002ac33504744 = uRam000002ac334f8a14;
  uRam000002ac33504748 = uRam000002ac334f8a18;
  uRam000002ac3350474c = uRam000002ac334f8a1c;
  _DAT_2ac33504750 = _DAT_2ac334f8a10;
  uRam000002ac33504754 = uRam000002ac334f8a14;
  uRam000002ac33504758 = uRam000002ac334f8a18;
  uRam000002ac3350475c = uRam000002ac334f8a1c;
  _DAT_2ac33504760 = _DAT_2ac334f8a10;
  uRam000002ac33504764 = uRam000002ac334f8a14;
  uRam000002ac33504768 = uRam000002ac334f8a18;
  uRam000002ac3350476c = uRam000002ac334f8a1c;
  _DAT_2ac33504770 = _DAT_2ac334f8a10;
  uRam000002ac33504774 = uRam000002ac334f8a14;
  uRam000002ac33504778 = uRam000002ac334f8a18;
  uRam000002ac3350477c = uRam000002ac334f8a1c;
  _DAT_2ac33504780 = _DAT_2ac334f8a10;
  uRam000002ac33504784 = uRam000002ac334f8a14;
  uRam000002ac33504788 = uRam000002ac334f8a18;
  uRam000002ac3350478c = uRam000002ac334f8a1c;
  _DAT_2ac33504790 = _DAT_2ac334f8a10;
  uRam000002ac33504794 = uRam000002ac334f8a14;
  uRam000002ac33504798 = uRam000002ac334f8a18;
  uRam000002ac3350479c = uRam000002ac334f8a1c;
  _DAT_2ac335047a0 = _DAT_2ac334f8a10;
  uRam000002ac335047a4 = uRam000002ac334f8a14;
  uRam000002ac335047a8 = uRam000002ac334f8a18;
  uRam000002ac335047ac = uRam000002ac334f8a1c;
  _DAT_2ac335047b0 = _DAT_2ac334f8a10;
  uRam000002ac335047b4 = uRam000002ac334f8a14;
  uRam000002ac335047b8 = uRam000002ac334f8a18;
  uRam000002ac335047bc = uRam000002ac334f8a1c;
  _DAT_2ac335047c0 = _DAT_2ac334f8a10;
  uRam000002ac335047c4 = uRam000002ac334f8a14;
  uRam000002ac335047c8 = uRam000002ac334f8a18;
  uRam000002ac335047cc = uRam000002ac334f8a1c;
  _DAT_2ac335047d0 = _DAT_2ac334f8a10;
  uRam000002ac335047d4 = uRam000002ac334f8a14;
  uRam000002ac335047d8 = uRam000002ac334f8a18;
  uRam000002ac335047dc = uRam000002ac334f8a1c;
  _DAT_2ac335047e0 = _DAT_2ac334f8a10;
  uRam000002ac335047e4 = uRam000002ac334f8a14;
  uRam000002ac335047e8 = uRam000002ac334f8a18;
  uRam000002ac335047ec = uRam000002ac334f8a1c;
  _DAT_2ac335047f0 = _DAT_2ac334f8a10;
  uRam000002ac335047f4 = uRam000002ac334f8a14;
  uRam000002ac335047f8 = uRam000002ac334f8a18;
  uRam000002ac335047fc = uRam000002ac334f8a1c;
  _DAT_2ac33504800 = _DAT_2ac334f8a10;
  uRam000002ac33504804 = uRam000002ac334f8a14;
  uRam000002ac33504808 = uRam000002ac334f8a18;
  uRam000002ac3350480c = uRam000002ac334f8a1c;
  _DAT_2ac33504810 = _DAT_2ac334f8a10;
  uRam000002ac33504814 = uRam000002ac334f8a14;
  uRam000002ac33504818 = uRam000002ac334f8a18;
  uRam000002ac3350481c = uRam000002ac334f8a1c;
  _DAT_2ac33504820 = _DAT_2ac334f8a10;
  uRam000002ac33504824 = uRam000002ac334f8a14;
  uRam000002ac33504828 = uRam000002ac334f8a18;
  uRam000002ac3350482c = uRam000002ac334f8a1c;
  _DAT_2ac33504830 = _DAT_2ac334f8a10;
  uRam000002ac33504834 = uRam000002ac334f8a14;
  uRam000002ac33504838 = uRam000002ac334f8a18;
  uRam000002ac3350483c = uRam000002ac334f8a1c;
  _DAT_2ac33504840 = _DAT_2ac334f8a10;
  uRam000002ac33504844 = uRam000002ac334f8a14;
  uRam000002ac33504848 = uRam000002ac334f8a18;
  uRam000002ac3350484c = uRam000002ac334f8a1c;
  _DAT_2ac33504850 = _DAT_2ac334f8a10;
  uRam000002ac33504854 = uRam000002ac334f8a14;
  uRam000002ac33504858 = uRam000002ac334f8a18;
  uRam000002ac3350485c = uRam000002ac334f8a1c;
  _DAT_2ac33504860 = _DAT_2ac334f8a10;
  uRam000002ac33504864 = uRam000002ac334f8a14;
  uRam000002ac33504868 = uRam000002ac334f8a18;
  uRam000002ac3350486c = uRam000002ac334f8a1c;
  _DAT_2ac33504870 = _DAT_2ac334f8a10;
  uRam000002ac33504874 = uRam000002ac334f8a14;
  uRam000002ac33504878 = uRam000002ac334f8a18;
  uRam000002ac3350487c = uRam000002ac334f8a1c;
  _DAT_2ac33504880 = _DAT_2ac334f8a10;
  uRam000002ac33504884 = uRam000002ac334f8a14;
  uRam000002ac33504888 = uRam000002ac334f8a18;
  uRam000002ac3350488c = uRam000002ac334f8a1c;
  _DAT_2ac33504890 = _DAT_2ac334f8a10;
  uRam000002ac33504894 = uRam000002ac334f8a14;
  uRam000002ac33504898 = uRam000002ac334f8a18;
  uRam000002ac3350489c = uRam000002ac334f8a1c;
  _DAT_2ac335048a0 = _DAT_2ac334f8a10;
  uRam000002ac335048a4 = uRam000002ac334f8a14;
  uRam000002ac335048a8 = uRam000002ac334f8a18;
  uRam000002ac335048ac = uRam000002ac334f8a1c;
  _DAT_2ac335048b0 = _DAT_2ac334f8a10;
  uRam000002ac335048b4 = uRam000002ac334f8a14;
  uRam000002ac335048b8 = uRam000002ac334f8a18;
  uRam000002ac335048bc = uRam000002ac334f8a1c;
  _DAT_2ac335048c0 = _DAT_2ac334f8a10;
  uRam000002ac335048c4 = uRam000002ac334f8a14;
  uRam000002ac335048c8 = uRam000002ac334f8a18;
  uRam000002ac335048cc = uRam000002ac334f8a1c;
  _DAT_2ac335048d0 = _DAT_2ac334f8a10;
  uRam000002ac335048d4 = uRam000002ac334f8a14;
  uRam000002ac335048d8 = uRam000002ac334f8a18;
  uRam000002ac335048dc = uRam000002ac334f8a1c;
  _DAT_2ac335048e0 = _DAT_2ac334f8a10;
  uRam000002ac335048e4 = uRam000002ac334f8a14;
  uRam000002ac335048e8 = uRam000002ac334f8a18;
  uRam000002ac335048ec = uRam000002ac334f8a1c;
  _DAT_2ac335048f0 = _DAT_2ac334f8a10;
  uRam000002ac335048f4 = uRam000002ac334f8a14;
  uRam000002ac335048f8 = uRam000002ac334f8a18;
  uRam000002ac335048fc = uRam000002ac334f8a1c;
  _DAT_2ac33504900 = _DAT_2ac334f8a10;
  uRam000002ac33504904 = uRam000002ac334f8a14;
  uRam000002ac33504908 = uRam000002ac334f8a18;
  uRam000002ac3350490c = uRam000002ac334f8a1c;
  _DAT_2ac33504910 = _DAT_2ac334f8a10;
  uRam000002ac33504914 = uRam000002ac334f8a14;
  uRam000002ac33504918 = uRam000002ac334f8a18;
  uRam000002ac3350491c = uRam000002ac334f8a1c;
  _DAT_2ac33504920 = _DAT_2ac334f8a10;
  uRam000002ac33504924 = uRam000002ac334f8a14;
  uRam000002ac33504928 = uRam000002ac334f8a18;
  uRam000002ac3350492c = uRam000002ac334f8a1c;
  _DAT_2ac33504930 = _DAT_2ac334f8a10;
  uRam000002ac33504934 = uRam000002ac334f8a14;
  uRam000002ac33504938 = uRam000002ac334f8a18;
  uRam000002ac3350493c = uRam000002ac334f8a1c;
  _DAT_2ac33504940 = _DAT_2ac334f8a10;
  uRam000002ac33504944 = uRam000002ac334f8a14;
  uRam000002ac33504948 = uRam000002ac334f8a18;
  uRam000002ac3350494c = uRam000002ac334f8a1c;
  _DAT_2ac33504950 = _DAT_2ac334f8a10;
  uRam000002ac33504954 = uRam000002ac334f8a14;
  uRam000002ac33504958 = uRam000002ac334f8a18;
  uRam000002ac3350495c = uRam000002ac334f8a1c;
  _DAT_2ac33504960 = _DAT_2ac334f8a10;
  uRam000002ac33504964 = uRam000002ac334f8a14;
  uRam000002ac33504968 = uRam000002ac334f8a18;
  uRam000002ac3350496c = uRam000002ac334f8a1c;
  _DAT_2ac33504970 = _DAT_2ac334f8a10;
  uRam000002ac33504974 = uRam000002ac334f8a14;
  uRam000002ac33504978 = uRam000002ac334f8a18;
  uRam000002ac3350497c = uRam000002ac334f8a1c;
  _DAT_2ac33504980 = _DAT_2ac334f8a10;
  uRam000002ac33504984 = uRam000002ac334f8a14;
  uRam000002ac33504988 = uRam000002ac334f8a18;
  uRam000002ac3350498c = uRam000002ac334f8a1c;
  _DAT_2ac33504990 = _DAT_2ac334f8a10;
  uRam000002ac33504994 = uRam000002ac334f8a14;
  uRam000002ac33504998 = uRam000002ac334f8a18;
  uRam000002ac3350499c = uRam000002ac334f8a1c;
  _DAT_2ac335049a0 = _DAT_2ac334f8a10;
  uRam000002ac335049a4 = uRam000002ac334f8a14;
  uRam000002ac335049a8 = uRam000002ac334f8a18;
  uRam000002ac335049ac = uRam000002ac334f8a1c;
  _DAT_2ac335049b0 = _DAT_2ac334f8a10;
  uRam000002ac335049b4 = uRam000002ac334f8a14;
  uRam000002ac335049b8 = uRam000002ac334f8a18;
  uRam000002ac335049bc = uRam000002ac334f8a1c;
  _DAT_2ac335049c0 = _DAT_2ac334f8a10;
  uRam000002ac335049c4 = uRam000002ac334f8a14;
  uRam000002ac335049c8 = uRam000002ac334f8a18;
  uRam000002ac335049cc = uRam000002ac334f8a1c;
  _DAT_2ac335049d0 = _DAT_2ac334f8a10;
  uRam000002ac335049d4 = uRam000002ac334f8a14;
  uRam000002ac335049d8 = uRam000002ac334f8a18;
  uRam000002ac335049dc = uRam000002ac334f8a1c;
  _DAT_2ac335049e0 = _DAT_2ac334f8a10;
  uRam000002ac335049e4 = uRam000002ac334f8a14;
  uRam000002ac335049e8 = uRam000002ac334f8a18;
  uRam000002ac335049ec = uRam000002ac334f8a1c;
  _DAT_2ac335049f0 = _DAT_2ac334f8a10;
  uRam000002ac335049f4 = uRam000002ac334f8a14;
  uRam000002ac335049f8 = uRam000002ac334f8a18;
  uRam000002ac335049fc = uRam000002ac334f8a1c;
  _DAT_2ac33504a00 = _DAT_2ac334f8a10;
  uRam000002ac33504a04 = uRam000002ac334f8a14;
  uRam000002ac33504a08 = uRam000002ac334f8a18;
  uRam000002ac33504a0c = uRam000002ac334f8a1c;
  _DAT_2ac33504a10 = _DAT_2ac334f8a10;
  uRam000002ac33504a14 = uRam000002ac334f8a14;
  uRam000002ac33504a18 = uRam000002ac334f8a18;
  uRam000002ac33504a1c = uRam000002ac334f8a1c;
  _DAT_2ac33504a20 = _DAT_2ac334f8a10;
  uRam000002ac33504a24 = uRam000002ac334f8a14;
  uRam000002ac33504a28 = uRam000002ac334f8a18;
  uRam000002ac33504a2c = uRam000002ac334f8a1c;
  _DAT_2ac33504a30 = _DAT_2ac334f8a10;
  uRam000002ac33504a34 = uRam000002ac334f8a14;
  uRam000002ac33504a38 = uRam000002ac334f8a18;
  uRam000002ac33504a3c = uRam000002ac334f8a1c;
  _DAT_2ac33504a40 = _DAT_2ac334f8a10;
  uRam000002ac33504a44 = uRam000002ac334f8a14;
  uRam000002ac33504a48 = uRam000002ac334f8a18;
  uRam000002ac33504a4c = uRam000002ac334f8a1c;
  _DAT_2ac33504a50 = _DAT_2ac334f8a10;
  uRam000002ac33504a54 = uRam000002ac334f8a14;
  uRam000002ac33504a58 = uRam000002ac334f8a18;
  uRam000002ac33504a5c = uRam000002ac334f8a1c;
  _DAT_2ac33504a60 = _DAT_2ac334f8a10;
  uRam000002ac33504a64 = uRam000002ac334f8a14;
  uRam000002ac33504a68 = uRam000002ac334f8a18;
  uRam000002ac33504a6c = uRam000002ac334f8a1c;
  _DAT_2ac33504a70 = _DAT_2ac334f8a10;
  uRam000002ac33504a74 = uRam000002ac334f8a14;
  uRam000002ac33504a78 = uRam000002ac334f8a18;
  uRam000002ac33504a7c = uRam000002ac334f8a1c;
  _DAT_2ac33504a80 = _DAT_2ac334f8a10;
  uRam000002ac33504a84 = uRam000002ac334f8a14;
  uRam000002ac33504a88 = uRam000002ac334f8a18;
  uRam000002ac33504a8c = uRam000002ac334f8a1c;
  _DAT_2ac33504a90 = _DAT_2ac334f8a10;
  uRam000002ac33504a94 = uRam000002ac334f8a14;
  uRam000002ac33504a98 = uRam000002ac334f8a18;
  uRam000002ac33504a9c = uRam000002ac334f8a1c;
  _DAT_2ac33504aa0 = _DAT_2ac334f8a10;
  uRam000002ac33504aa4 = uRam000002ac334f8a14;
  uRam000002ac33504aa8 = uRam000002ac334f8a18;
  uRam000002ac33504aac = uRam000002ac334f8a1c;
  _DAT_2ac33504ab0 = _DAT_2ac334f8a10;
  uRam000002ac33504ab4 = uRam000002ac334f8a14;
  uRam000002ac33504ab8 = uRam000002ac334f8a18;
  uRam000002ac33504abc = uRam000002ac334f8a1c;
  _DAT_2ac33504ac0 = _DAT_2ac334f8a10;
  uRam000002ac33504ac4 = uRam000002ac334f8a14;
  uRam000002ac33504ac8 = uRam000002ac334f8a18;
  uRam000002ac33504acc = uRam000002ac334f8a1c;
  _DAT_2ac33504ad0 = _DAT_2ac334f8a10;
  uRam000002ac33504ad4 = uRam000002ac334f8a14;
  uRam000002ac33504ad8 = uRam000002ac334f8a18;
  uRam000002ac33504adc = uRam000002ac334f8a1c;
  _DAT_2ac33504ae0 = _DAT_2ac334f8a10;
  uRam000002ac33504ae4 = uRam000002ac334f8a14;
  uRam000002ac33504ae8 = uRam000002ac334f8a18;
  uRam000002ac33504aec = uRam000002ac334f8a1c;
  _DAT_2ac33504af0 = _DAT_2ac334f8a10;
  uRam000002ac33504af4 = uRam000002ac334f8a14;
  uRam000002ac33504af8 = uRam000002ac334f8a18;
  uRam000002ac33504afc = uRam000002ac334f8a1c;
  _DAT_2ac33504b00 = _DAT_2ac334f8a10;
  uRam000002ac33504b04 = uRam000002ac334f8a14;
  uRam000002ac33504b08 = uRam000002ac334f8a18;
  uRam000002ac33504b0c = uRam000002ac334f8a1c;
  _DAT_2ac33504b10 = _DAT_2ac334f8a10;
  uRam000002ac33504b14 = uRam000002ac334f8a14;
  uRam000002ac33504b18 = uRam000002ac334f8a18;
  uRam000002ac33504b1c = uRam000002ac334f8a1c;
  _DAT_2ac33504b20 = _DAT_2ac334f8a10;
  uRam000002ac33504b24 = uRam000002ac334f8a14;
  uRam000002ac33504b28 = uRam000002ac334f8a18;
  uRam000002ac33504b2c = uRam000002ac334f8a1c;
  _DAT_2ac33504b30 = _DAT_2ac334f8a10;
  uRam000002ac33504b34 = uRam000002ac334f8a14;
  uRam000002ac33504b38 = uRam000002ac334f8a18;
  uRam000002ac33504b3c = uRam000002ac334f8a1c;
  _DAT_2ac33504b40 = _DAT_2ac334f8a10;
  uRam000002ac33504b44 = uRam000002ac334f8a14;
  uRam000002ac33504b48 = uRam000002ac334f8a18;
  uRam000002ac33504b4c = uRam000002ac334f8a1c;
  _DAT_2ac33504b50 = _DAT_2ac334f8a10;
  uRam000002ac33504b54 = uRam000002ac334f8a14;
  uRam000002ac33504b58 = uRam000002ac334f8a18;
  uRam000002ac33504b5c = uRam000002ac334f8a1c;
  _DAT_2ac33504b60 = _DAT_2ac334f8a10;
  uRam000002ac33504b64 = uRam000002ac334f8a14;
  uRam000002ac33504b68 = uRam000002ac334f8a18;
  uRam000002ac33504b6c = uRam000002ac334f8a1c;
  _DAT_2ac33504b70 = _DAT_2ac334f8a10;
  uRam000002ac33504b74 = uRam000002ac334f8a14;
  uRam000002ac33504b78 = uRam000002ac334f8a18;
  uRam000002ac33504b7c = uRam000002ac334f8a1c;
  _DAT_2ac33504b80 = _DAT_2ac334f8a10;
  uRam000002ac33504b84 = uRam000002ac334f8a14;
  uRam000002ac33504b88 = uRam000002ac334f8a18;
  uRam000002ac33504b8c = uRam000002ac334f8a1c;
  _DAT_2ac33504b90 = _DAT_2ac334f8a10;
  uRam000002ac33504b94 = uRam000002ac334f8a14;
  uRam000002ac33504b98 = uRam000002ac334f8a18;
  uRam000002ac33504b9c = uRam000002ac334f8a1c;
  _DAT_2ac33504ba0 = _DAT_2ac334f8a10;
  uRam000002ac33504ba4 = uRam000002ac334f8a14;
  uRam000002ac33504ba8 = uRam000002ac334f8a18;
  uRam000002ac33504bac = uRam000002ac334f8a1c;
  _DAT_2ac33504bb0 = _DAT_2ac334f8a10;
  uRam000002ac33504bb4 = uRam000002ac334f8a14;
  uRam000002ac33504bb8 = uRam000002ac334f8a18;
  uRam000002ac33504bbc = uRam000002ac334f8a1c;
  _DAT_2ac33504bc0 = _DAT_2ac334f8a10;
  uRam000002ac33504bc4 = uRam000002ac334f8a14;
  uRam000002ac33504bc8 = uRam000002ac334f8a18;
  uRam000002ac33504bcc = uRam000002ac334f8a1c;
  _DAT_2ac33504bd0 = _DAT_2ac334f8a10;
  uRam000002ac33504bd4 = uRam000002ac334f8a14;
  uRam000002ac33504bd8 = uRam000002ac334f8a18;
  uRam000002ac33504bdc = uRam000002ac334f8a1c;
  _DAT_2ac33504be0 = _DAT_2ac334f8a10;
  uRam000002ac33504be4 = uRam000002ac334f8a14;
  uRam000002ac33504be8 = uRam000002ac334f8a18;
  uRam000002ac33504bec = uRam000002ac334f8a1c;
  _DAT_2ac33504bf0 = _DAT_2ac334f8a10;
  uRam000002ac33504bf4 = uRam000002ac334f8a14;
  uRam000002ac33504bf8 = uRam000002ac334f8a18;
  uRam000002ac33504bfc = uRam000002ac334f8a1c;
  _DAT_2ac33504c00 = _DAT_2ac334f8a10;
  uRam000002ac33504c04 = uRam000002ac334f8a14;
  uRam000002ac33504c08 = uRam000002ac334f8a18;
  uRam000002ac33504c0c = uRam000002ac334f8a1c;
  _DAT_2ac33504c10 = _DAT_2ac334f8a10;
  uRam000002ac33504c14 = uRam000002ac334f8a14;
  uRam000002ac33504c18 = uRam000002ac334f8a18;
  uRam000002ac33504c1c = uRam000002ac334f8a1c;
  _DAT_2ac33504c20 = _DAT_2ac334f8a10;
  uRam000002ac33504c24 = uRam000002ac334f8a14;
  uRam000002ac33504c28 = uRam000002ac334f8a18;
  uRam000002ac33504c2c = uRam000002ac334f8a1c;
  _DAT_2ac33504c30 = _DAT_2ac334f8a10;
  uRam000002ac33504c34 = uRam000002ac334f8a14;
  uRam000002ac33504c38 = uRam000002ac334f8a18;
  uRam000002ac33504c3c = uRam000002ac334f8a1c;
  _DAT_2ac33504c40 = _DAT_2ac334f8a10;
  uRam000002ac33504c44 = uRam000002ac334f8a14;
  uRam000002ac33504c48 = uRam000002ac334f8a18;
  uRam000002ac33504c4c = uRam000002ac334f8a1c;
  _DAT_2ac33504c50 = _DAT_2ac334f8a10;
  uRam000002ac33504c54 = uRam000002ac334f8a14;
  uRam000002ac33504c58 = uRam000002ac334f8a18;
  uRam000002ac33504c5c = uRam000002ac334f8a1c;
  _DAT_2ac33504c60 = _DAT_2ac334f8a10;
  uRam000002ac33504c64 = uRam000002ac334f8a14;
  uRam000002ac33504c68 = uRam000002ac334f8a18;
  uRam000002ac33504c6c = uRam000002ac334f8a1c;
  _DAT_2ac33504c70 = _DAT_2ac334f8a10;
  uRam000002ac33504c74 = uRam000002ac334f8a14;
  uRam000002ac33504c78 = uRam000002ac334f8a18;
  uRam000002ac33504c7c = uRam000002ac334f8a1c;
  _DAT_2ac33504c80 = _DAT_2ac334f8a10;
  uRam000002ac33504c84 = uRam000002ac334f8a14;
  uRam000002ac33504c88 = uRam000002ac334f8a18;
  uRam000002ac33504c8c = uRam000002ac334f8a1c;
  if (_DAT_2ac33505c14 == 0) {
    iVar11 = 0;
    uVar18 = 0;
    uVar36 = (undefined4)_DAT_2ac334f8a20;
    uVar37 = (undefined4)((ulonglong)_DAT_2ac334f8a20 >> 0x20);
    uVar38 = (undefined4)_DAT_2ac334f8a28;
    uVar39 = (undefined4)((ulonglong)_DAT_2ac334f8a28 >> 0x20);
    uVar40 = (undefined4)_DAT_2ac334f8a30;
    uVar41 = (undefined4)((ulonglong)_DAT_2ac334f8a30 >> 0x20);
    do {
      iVar11 = FUN_2ac334d0460(_DAT_2ac335001cc,0x2ac334fbeec,iVar11);
      if (iVar11 == -1) break;
      uVar20 = iVar11 + 7;
      iVar11 = FUN_2ac334d0460(_DAT_2ac335001cc,0x2ac334fbf0c,uVar20);
      if (iVar11 == -1) break;
      uVar34 = 0xfa9;
      if ((_DAT_2ac335001cc == 0) || (_DAT_2ac335001cc == 0xc)) {
LAB_2ac334d67cd:
        _DAT_2ac33505c10 = uVar34;
        if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
          _DAT_2ac33505c10 = 0xfa9;
        }
        else if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
                (cVar10 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar7 = _DAT_2ac33505c40,
                cVar10 != '\0')) {
          *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
          *puVar7 = 0;
        }
      }
      else {
        uVar26 = *(uint *)(_DAT_2ac335001cc + -4);
        uVar15 = uVar20;
        if (((int)uVar20 < 0) && (uVar15 = uVar26 + uVar20, (int)uVar15 < 0)) {
          uVar34 = 0x13ab;
          goto LAB_2ac334d67cd;
        }
        iVar14 = uVar26 - uVar15;
        uVar34 = 0x13ab;
        if (uVar26 < uVar15 || iVar14 == 0) goto LAB_2ac334d67cd;
        iVar23 = iVar11 - uVar20;
        iVar24 = iVar14;
        if ((-1 < iVar23) && (iVar24 = iVar23, iVar14 < iVar23)) {
          _DAT_2ac33505c10 = 0x13ab;
          iVar24 = iVar14;
        }
        uVar34 = _DAT_2ac33505c10;
        if (iVar24 == 0) goto LAB_2ac334d67cd;
        FUN_2ac334d0280(0x2ac33505c3c,_DAT_2ac335001cc + (ulonglong)uVar15 * 2);
      }
      local_1cc = iVar11;
      FUN_2ac334d0af0(&local_1e8,0x2ac33505c3c,1,0x2ac334fea70);
      FUN_2ac334d0af0(&local_1b0,&local_1e8,0,0x2ac334fea80);
      if (199 < uVar18) {
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xf0897000001f6);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      lVar32 = 0;
      uVar20 = 0;
      do {
        FUN_2ac334d0af0(&DAT_2ac335001e0 + lVar32 * 0xc + (ulonglong)(uVar18 * 7) * 0xc,
                        0x2ac334f9160,0,0x2ac334fea90);
        if ((local_1ac == (short *)0x0) ||
           (psVar12 = *(short **)((longlong)&local_10c + lVar32 * 0xc), psVar12 == (short *)0x0)) {
LAB_2ac334d68b0:
          _DAT_2ac33505c10 = 0xfa9;
        }
        else {
          uVar26 = *(uint *)(local_1ac + -2);
          if ((uVar26 == 0) || (uVar15 = *(uint *)(psVar12 + -2), uVar15 == 0)) {
            _DAT_2ac33505c10 = 0x13ab;
          }
          else {
            uVar27 = 0;
            if (0 < (int)uVar20) {
              uVar27 = (ulonglong)uVar20;
            }
            uVar25 = (uint)uVar27;
            if (local_1ac == psVar12) {
              uVar25 = -(uint)(0 < (int)uVar20);
LAB_2ac334d69b2:
              if (uVar25 != 0xffffffff) {
LAB_2ac334d69bc:
                if (psVar12 == (short *)0xc) {
                  uVar15 = 0;
                }
                psVar12 = *(short **)((longlong)&local_164 + lVar32 * 0xc);
                uVar20 = uVar15 + uVar25;
                if (psVar12 == (short *)0x0) goto LAB_2ac334d68b0;
                uVar15 = *(uint *)(psVar12 + -2);
                if (uVar15 == 0) {
                  _DAT_2ac33505c10 = 0x13ab;
                  goto LAB_2ac334d68c0;
                }
                uVar25 = 0;
                if (0 < (int)uVar20) {
                  uVar25 = uVar20;
                }
                if (local_1ac == psVar12) {
                  uVar25 = -(uint)(0 < (int)uVar20);
                  goto LAB_2ac334d6a46;
                }
                uVar30 = uVar26 - uVar25;
                if (((uVar25 <= uVar26 && uVar30 != 0) && (uVar15 <= uVar30)) &&
                   (uVar30 = (uVar30 - uVar15) + 1, uVar30 != 0)) {
                  sVar2 = *psVar12;
                  uVar27 = (ulonglong)uVar30;
                  psVar21 = local_1ac + uVar25;
                  if (uVar15 == 1) {
                    if (*psVar21 != sVar2) {
                      uVar28 = 0;
                      do {
                        if (uVar27 - 1 == uVar28) goto LAB_2ac334d68c0;
                        lVar19 = uVar28 + 1;
                        uVar28 = uVar28 + 1;
                      } while (local_1ac[(ulonglong)uVar25 + lVar19] != sVar2);
                      if (uVar27 <= uVar28) goto LAB_2ac334d68c0;
                      uVar25 = uVar25 + (int)uVar28;
                    }
LAB_2ac334d6a46:
                    iVar11 = uVar25 - uVar20;
                    if ((iVar11 != 0 && (int)uVar20 <= (int)uVar25) && (uVar25 != 0xffffffff)) {
                      if (local_1ac == (short *)0xc) {
                        uVar34 = 0xfa9;
LAB_2ac334d6bbb:
                        _DAT_2ac33505c10 = uVar34;
                        if ((_DAT_2ac33505c40 == (undefined2 *)0x0) ||
                           (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
                          _DAT_2ac33505c10 = 0xfa9;
                        }
                        else if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
                                (cVar10 = FUN_2ac334d0100(0x2ac33505c3c,0),
                                puVar7 = _DAT_2ac33505c40, cVar10 != '\0')) {
                          *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
                          *puVar7 = 0;
                        }
                      }
                      else {
                        uVar15 = uVar20;
                        if (((int)uVar20 < 0) && (uVar15 = uVar26 + uVar20, (int)uVar15 < 0)) {
                          uVar34 = 0x13ab;
                          goto LAB_2ac334d6bbb;
                        }
                        iVar14 = uVar26 - uVar15;
                        uVar34 = 0x13ab;
                        if (uVar26 < uVar15 || iVar14 == 0) goto LAB_2ac334d6bbb;
                        iVar24 = iVar14;
                        if ((-1 < iVar11) && (iVar24 = iVar11, iVar14 < iVar11)) {
                          _DAT_2ac33505c10 = 0x13ab;
                          iVar24 = iVar14;
                        }
                        uVar34 = _DAT_2ac33505c10;
                        if (iVar24 == 0) goto LAB_2ac334d6bbb;
                        FUN_2ac334d0280(0x2ac33505c3c,local_1ac + uVar15);
                      }
                      FUN_2ac334d0af0(&local_1e8,0x2ac33505c3c,1,0x2ac334feaa0);
                      FUN_2ac334d0af0(&DAT_2ac335001e0 +
                                      lVar32 * 0xc + (ulonglong)(uVar18 * 7) * 0xc,&local_1e8,0,
                                      0x2ac334feab0);
                    }
                  }
                  else {
                    bVar33 = true;
                    uVar28 = 0;
                    local_1d8 = (ulonglong)uVar15 - 1;
                    do {
                      if (psVar21[uVar28] == sVar2) {
                        lVar31 = 1;
                        lVar19 = local_1d8;
                        while (psVar21[(uint)((int)uVar28 + (int)lVar31)] == psVar12[lVar31]) {
                          lVar31 = lVar31 + 1;
                          lVar19 = lVar19 + -1;
                          if (lVar19 == 0) goto LAB_2ac334d6d28;
                        }
                        if ((int)lVar19 == 0) {
LAB_2ac334d6d28:
                          if (bVar33) {
                            uVar25 = uVar25 + (int)uVar28;
                            goto LAB_2ac334d6a46;
                          }
                          break;
                        }
                      }
                      uVar28 = uVar28 + 1;
                      bVar33 = uVar28 < uVar27;
                    } while (uVar28 != uVar27);
                  }
                }
              }
            }
            else {
              uVar30 = uVar26 - uVar25;
              if (((uVar25 <= uVar26 && uVar30 != 0) && (uVar15 <= uVar30)) &&
                 (uVar30 = (uVar30 - uVar15) + 1, uVar30 != 0)) {
                sVar2 = *psVar12;
                uVar28 = (ulonglong)uVar30;
                psVar21 = local_1ac + uVar27;
                if (uVar15 < 2) {
                  if (*psVar21 == sVar2) goto LAB_2ac334d69bc;
                  uVar16 = 0;
                  do {
                    if (uVar28 - 1 == uVar16) goto LAB_2ac334d68c0;
                    lVar19 = uVar16 + 1;
                    uVar16 = uVar16 + 1;
                  } while (local_1ac[uVar27 + lVar19] != sVar2);
                  if (uVar16 < uVar28) {
                    uVar25 = uVar25 + (int)uVar16;
                    goto LAB_2ac334d69b2;
                  }
                }
                else {
                  bVar33 = true;
                  uVar27 = 0;
                  local_1d8 = CONCAT62(local_1d8._2_6_,sVar2);
                  local_1c8 = (ulonglong)uVar15 - 1;
                  do {
                    if (psVar21[uVar27] == sVar2) {
                      lVar31 = 1;
                      lVar19 = local_1c8;
                      while (psVar21[(uint)((int)uVar27 + (int)lVar31)] == psVar12[lVar31]) {
                        lVar31 = lVar31 + 1;
                        lVar19 = lVar19 + -1;
                        if (lVar19 == 0) goto LAB_2ac334d6b78;
                      }
                      if ((int)lVar19 == 0) {
LAB_2ac334d6b78:
                        if (bVar33) {
                          uVar25 = uVar25 + (int)uVar27;
                          goto LAB_2ac334d69b2;
                        }
                        break;
                      }
                    }
                    uVar27 = uVar27 + 1;
                    bVar33 = uVar27 < uVar28;
                  } while (uVar27 != uVar28);
                }
              }
            }
          }
        }
LAB_2ac334d68c0:
        bVar33 = lVar32 != 6;
        lVar32 = lVar32 + 1;
      } while (bVar33);
      uVar27 = (ulonglong)uVar18;
      lVar32 = uVar27 * 0x54;
      FUN_2ac334d0af0(&local_1e8,&DAT_2ac335001ec + lVar32,0);
      iVar11 = local_1cc;
      if (cVar9 == '\0') {
LAB_2ac334d6e33:
        if (cVar8 != '\0') {
          if (local_1e4 == &DAT_2ac334fbc3c) goto LAB_2ac334d6eb0;
          if (local_1e4 != (undefined1 *)0x0) {
            uVar20 = *(uint *)(local_1e4 + -4);
            uVar26 = _DAT_2ac334fbc38;
            if (uVar20 < _DAT_2ac334fbc38) {
              uVar26 = uVar20;
            }
            iVar14 = uVar20 - _DAT_2ac334fbc38;
            if (uVar26 != 0) {
              uVar28 = 0;
              do {
                uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
                uVar4 = *(ushort *)(&DAT_2ac334fbc3c + uVar28 * 2);
                uVar28 = uVar28 + 1;
                if (uVar26 <= uVar28) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar14 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar14 == 0) goto LAB_2ac334d6eb0;
          }
        }
      }
      else {
        if (local_1e4 != &DAT_2ac334fbc1c) {
          if (local_1e4 == (undefined1 *)0x0) goto LAB_2ac334d66e0;
          uVar20 = *(uint *)(local_1e4 + -4);
          uVar26 = _DAT_2ac334fbc18;
          if (uVar20 < _DAT_2ac334fbc18) {
            uVar26 = uVar20;
          }
          iVar14 = uVar20 - _DAT_2ac334fbc18;
          if (uVar26 != 0) {
            uVar28 = 0;
            do {
              uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
              uVar4 = *(ushort *)(&DAT_2ac334fbc1c + uVar28 * 2);
              uVar28 = uVar28 + 1;
              if (uVar26 <= uVar28) break;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar14 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar14 != 0) goto LAB_2ac334d6e33;
        }
LAB_2ac334d6eb0:
        puVar17 = &DAT_2ac335001e0 + lVar32;
        puVar22 = *(undefined1 **)(lVar32 + 0x2ac33500214);
        if (DAT_2ac33500045 == '\0') {
          if (puVar22 != &DAT_2ac334fbb9c) {
            if (puVar22 == (undefined1 *)0x0) {
              puVar22 = (undefined1 *)0x0;
              goto joined_r0x02ac334d706d;
            }
            uVar20 = *(uint *)(puVar22 + -4);
            uVar26 = _DAT_2ac334fbb98;
            if (uVar20 < _DAT_2ac334fbb98) {
              uVar26 = uVar20;
            }
            iVar14 = uVar20 - _DAT_2ac334fbb98;
            if (uVar26 != 0) {
              uVar28 = 0;
              do {
                uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                uVar4 = *(ushort *)(&DAT_2ac334fbb9c + uVar28 * 2);
                uVar28 = uVar28 + 1;
                if (uVar26 <= uVar28) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar14 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar14 != 0) goto LAB_2ac334d6f53;
          }
        }
        else {
LAB_2ac334d6f53:
          if (puVar22 != &DAT_2ac334fbbbc) {
            if (puVar22 == (undefined1 *)0x0) {
              puVar22 = (undefined1 *)0x0;
joined_r0x02ac334d706d:
              uVar34 = _DAT_2ac33505c10;
              if (DAT_2ac33500046 == '\0') {
                psVar12 = *(short **)(&DAT_2ac335001e4 + lVar32);
                if (psVar12 == (short *)0x0) {
                  uVar34 = 0xfa9;
                }
                else {
                  uVar20 = *(uint *)(psVar12 + -2);
                  uVar34 = 0x13ab;
                  if ((uVar20 != 0) && (_DAT_2ac334fbf28 != 0)) {
                    if (psVar12 == (short *)0x2ac334fbf2c) goto LAB_2ac334d66e0;
                    uVar34 = _DAT_2ac33505c10;
                    if ((_DAT_2ac334fbf28 <= uVar20) &&
                       (uVar20 = (uVar20 - _DAT_2ac334fbf28) + 1, uVar20 != 0)) {
                      uVar28 = (ulonglong)uVar20;
                      if (_DAT_2ac334fbf28 < 2) {
                        if (*psVar12 == 0x53) goto LAB_2ac334d66e0;
                        uVar16 = 0;
                        do {
                          if (uVar28 - 1 == uVar16) goto LAB_2ac334d70e9;
                          lVar19 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (psVar12[lVar19] != 0x53);
                        if (uVar16 < uVar28) {
LAB_2ac334d66d2:
                          if ((int)uVar16 != -1) goto LAB_2ac334d66e0;
                        }
                      }
                      else {
                        bVar33 = true;
                        uVar29 = 1;
                        uVar16 = 0;
                        do {
                          iVar14 = (int)uVar29;
                          if (psVar12[uVar16] == 0x53) {
                            psVar21 = (short *)&DAT_2ac334fbf2e;
                            lVar19 = (ulonglong)_DAT_2ac334fbf28 - 1;
                            while (psVar12[uVar29] == *psVar21) {
                              psVar21 = psVar21 + 1;
                              uVar29 = (ulonglong)((int)uVar29 + 1);
                              lVar19 = lVar19 + -1;
                              if (lVar19 == 0) goto LAB_2ac334d7519;
                            }
                            if ((int)lVar19 == 0) {
LAB_2ac334d7519:
                              if (bVar33) goto LAB_2ac334d66d2;
                              break;
                            }
                          }
                          uVar16 = uVar16 + 1;
                          uVar29 = (ulonglong)(iVar14 + 1);
                          bVar33 = uVar16 < uVar28;
                        } while (uVar16 != uVar28);
                      }
                    }
                  }
                }
              }
LAB_2ac334d70e9:
              _DAT_2ac33505c10 = uVar34;
              puVar5 = *(undefined1 **)(lVar32 + 0x2ac33500208);
              if (puVar5 != &DAT_2ac334fbf4c) {
                if (puVar5 != (undefined1 *)0x0) {
                  uVar20 = *(uint *)(puVar5 + -4);
                  uVar26 = _DAT_2ac334fbf48;
                  if (uVar20 < _DAT_2ac334fbf48) {
                    uVar26 = uVar20;
                  }
                  iVar14 = uVar20 - _DAT_2ac334fbf48;
                  if (uVar26 != 0) {
                    uVar28 = 0;
                    do {
                      uVar3 = *(ushort *)(puVar5 + uVar28 * 2);
                      uVar4 = *(ushort *)(&DAT_2ac334fbf4c + uVar28 * 2);
                      uVar28 = uVar28 + 1;
                      if (uVar26 <= uVar28) break;
                    } while (uVar3 == uVar4);
                    if (uVar3 != uVar4) {
                      iVar14 = (uint)uVar3 - (uint)uVar4;
                    }
                  }
                  if (iVar14 == 0) goto LAB_2ac334d7177;
                  goto LAB_2ac334d7207;
                }
                goto LAB_2ac334d7303;
              }
LAB_2ac334d7177:
              if (puVar22 == &DAT_2ac334fbbfc) {
LAB_2ac334d7207:
                if (puVar5 != &DAT_2ac334fbf6c) {
                  if (puVar5 == (undefined1 *)0x0) {
LAB_2ac334d7303:
                    uVar34 = _DAT_2ac33505c10;
                    if ((_DAT_2ac33505914 != (short *)&DAT_2ac334f9158) &&
                       (uVar34 = 0xfa9, _DAT_2ac33505914 != (short *)0x0)) {
                      uVar20 = *(uint *)(_DAT_2ac33505914 + -2);
                      uVar26 = _DAT_2ac334f9154;
                      if (uVar20 < _DAT_2ac334f9154) {
                        uVar26 = uVar20;
                      }
                      iVar14 = uVar20 - _DAT_2ac334f9154;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = _DAT_2ac33505914[uVar28];
                          uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar14 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      uVar34 = _DAT_2ac33505c10;
                      if ((iVar14 != 0) &&
                         (psVar12 = *(short **)(&DAT_2ac335001e4 + lVar32), uVar34 = 0xfa9,
                         psVar12 != (short *)0x0)) {
                        uVar26 = *(uint *)(psVar12 + -2);
                        uVar34 = 0x13ab;
                        if ((uVar26 != 0) && (uVar20 != 0)) {
                          if (psVar12 == _DAT_2ac33505914) goto LAB_2ac334d66e0;
                          uVar34 = _DAT_2ac33505c10;
                          if ((uVar20 <= uVar26) && (uVar26 = (uVar26 - uVar20) + 1, uVar26 != 0)) {
                            sVar2 = *_DAT_2ac33505914;
                            uVar28 = (ulonglong)uVar26;
                            if (uVar20 < 2) {
                              if (*psVar12 == sVar2) goto LAB_2ac334d66e0;
                              uVar16 = 0;
                              do {
                                if (uVar28 - 1 == uVar16) goto LAB_2ac334d73ef;
                                lVar19 = uVar16 + 1;
                                uVar16 = uVar16 + 1;
                              } while (psVar12[lVar19] != sVar2);
                              if (uVar16 < uVar28) {
LAB_2ac334d77d7:
                                if ((int)uVar16 != -1) goto LAB_2ac334d66e0;
                              }
                            }
                            else {
                              bVar33 = true;
                              uVar16 = 0;
                              do {
                                if (psVar12[uVar16] == sVar2) {
                                  lVar31 = 1;
                                  lVar19 = (ulonglong)uVar20 - 1;
                                  while (psVar12[(uint)((int)uVar16 + (int)lVar31)] ==
                                         _DAT_2ac33505914[lVar31]) {
                                    lVar31 = lVar31 + 1;
                                    lVar19 = lVar19 + -1;
                                    if (lVar19 == 0) goto LAB_2ac334d77b4;
                                  }
                                  if ((int)lVar19 == 0) {
LAB_2ac334d77b4:
                                    if (bVar33) goto LAB_2ac334d77d7;
                                    break;
                                  }
                                }
                                uVar16 = uVar16 + 1;
                                bVar33 = uVar16 < uVar28;
                              } while (uVar16 != uVar28);
                            }
                          }
                        }
                      }
                    }
LAB_2ac334d73ef:
                    _DAT_2ac33505c10 = uVar34;
                    psVar12 = *(short **)(&DAT_2ac335001e4 + lVar32);
                    if (psVar12 == (short *)0x0) {
LAB_2ac334d771d:
                      _DAT_2ac33505c10 = 0xfa9;
                      goto LAB_2ac334d7968;
                    }
                    uVar20 = *(uint *)(psVar12 + -2);
                    if ((uVar20 == 0) || (_DAT_2ac334fbf88 == 0)) {
                      _DAT_2ac33505c10 = 0x13ab;
                      uVar20 = *(uint *)(psVar12 + -2);
joined_r0x02ac334d746c:
                      if (uVar20 != 0) goto LAB_2ac334d760c;
LAB_2ac334d7804:
                      _DAT_2ac33505c10 = 0x13ab;
LAB_2ac334d7814:
                      uVar20 = *(uint *)(psVar12 + -2);
                      if (uVar20 == 0) goto LAB_2ac334d7958;
LAB_2ac334d781f:
                      if (_DAT_2ac334fbfa8 == 0) goto LAB_2ac334d7958;
                      if (psVar12 == (short *)0x2ac334fbfac) goto LAB_2ac334d791e;
                      if ((_DAT_2ac334fbfa8 <= uVar20) &&
                         (uVar20 = (uVar20 - _DAT_2ac334fbfa8) + 1, uVar20 != 0)) {
                        uVar28 = (ulonglong)uVar20;
                        if (_DAT_2ac334fbfa8 < 2) {
                          if (*psVar12 == 0x5d) {
LAB_2ac334d791e:
                            FUN_2ac334d0590(puVar17,0x2ac334fbfac);
                          }
                          else {
                            uVar16 = 0;
                            do {
                              if (uVar28 - 1 == uVar16) goto LAB_2ac334d7968;
                              lVar19 = uVar16 + 1;
                              uVar16 = uVar16 + 1;
                            } while (psVar12[lVar19] != 0x5d);
                            if (uVar16 < uVar28) {
LAB_2ac334d7919:
                              if ((int)uVar16 != -1) goto LAB_2ac334d791e;
                            }
                          }
                        }
                        else {
                          bVar33 = true;
                          uVar29 = 1;
                          uVar16 = 0;
                          do {
                            iVar11 = (int)uVar29;
                            if (psVar12[uVar16] == 0x5d) {
                              psVar21 = (short *)&DAT_2ac334fbfae;
                              lVar19 = (ulonglong)_DAT_2ac334fbfa8 - 1;
                              while (psVar12[uVar29] == *psVar21) {
                                psVar21 = psVar21 + 1;
                                uVar29 = (ulonglong)((int)uVar29 + 1);
                                lVar19 = lVar19 + -1;
                                if (lVar19 == 0) goto LAB_2ac334d78ff;
                              }
                              if ((int)lVar19 == 0) {
LAB_2ac334d78ff:
                                if (bVar33) goto LAB_2ac334d7919;
                                break;
                              }
                            }
                            uVar16 = uVar16 + 1;
                            uVar29 = (ulonglong)(iVar11 + 1);
                            bVar33 = uVar16 < uVar28;
                          } while (uVar16 != uVar28);
                        }
                      }
                    }
                    else {
                      if (psVar12 == (short *)0x2ac334fbf8c) goto LAB_2ac334d75db;
                      if ((uVar20 < _DAT_2ac334fbf88) ||
                         (uVar20 = (uVar20 - _DAT_2ac334fbf88) + 1, uVar20 == 0)) {
LAB_2ac334d75f8:
                        if (psVar12 == (short *)0x0) goto LAB_2ac334d771d;
                      }
                      else {
                        uVar28 = (ulonglong)uVar20;
                        if (1 < _DAT_2ac334fbf88) {
                          bVar33 = true;
                          uVar29 = 1;
                          uVar16 = 0;
                          do {
                            iVar11 = (int)uVar29;
                            if (psVar12[uVar16] == 0x3c) {
                              psVar21 = (short *)&DAT_2ac334fbf8e;
                              lVar19 = (ulonglong)_DAT_2ac334fbf88 - 1;
                              while (psVar12[uVar29] == *psVar21) {
                                psVar21 = psVar21 + 1;
                                uVar29 = (ulonglong)((int)uVar29 + 1);
                                lVar19 = lVar19 + -1;
                                if (lVar19 == 0) goto LAB_2ac334d75bc;
                              }
                              if ((int)lVar19 == 0) {
LAB_2ac334d75bc:
                                if (bVar33) goto LAB_2ac334d75d6;
                                goto LAB_2ac334d75f8;
                              }
                            }
                            uVar16 = uVar16 + 1;
                            uVar29 = (ulonglong)(iVar11 + 1);
                            bVar33 = uVar16 < uVar28;
                          } while (uVar16 != uVar28);
                          uVar20 = *(uint *)(psVar12 + -2);
                          goto joined_r0x02ac334d746c;
                        }
                        if (*psVar12 == 0x3c) {
LAB_2ac334d75db:
                          FUN_2ac334d0590(puVar17,0x2ac334fbf8c);
                          psVar12 = *(short **)(&DAT_2ac335001e4 + lVar32);
                          goto LAB_2ac334d75f8;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar28 - 1 == uVar16) goto LAB_2ac334d75f8;
                          lVar19 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (psVar12[lVar19] != 0x3c);
                        if (uVar16 < uVar28) {
LAB_2ac334d75d6:
                          if ((int)uVar16 == -1) goto LAB_2ac334d75f8;
                          goto LAB_2ac334d75db;
                        }
                      }
                      uVar20 = *(uint *)(psVar12 + -2);
                      if (uVar20 == 0) goto LAB_2ac334d7804;
LAB_2ac334d760c:
                      if (_DAT_2ac334fbfa8 == 0) goto LAB_2ac334d7804;
                      if (psVar12 == (short *)0x2ac334fbfac) goto LAB_2ac334d76f7;
                      if ((uVar20 < _DAT_2ac334fbfa8) ||
                         (uVar20 = (uVar20 - _DAT_2ac334fbfa8) + 1, uVar20 == 0)) {
LAB_2ac334d7714:
                        if (psVar12 == (short *)0x0) goto LAB_2ac334d771d;
                        goto LAB_2ac334d7814;
                      }
                      uVar28 = (ulonglong)uVar20;
                      if (_DAT_2ac334fbfa8 < 2) {
                        if (*psVar12 == 0x5d) {
LAB_2ac334d76f7:
                          FUN_2ac334d0590(puVar17,0x2ac334fbfac);
                          psVar12 = *(short **)(&DAT_2ac335001e4 + lVar32);
                          goto LAB_2ac334d7714;
                        }
                        uVar16 = 0;
                        do {
                          if (uVar28 - 1 == uVar16) goto LAB_2ac334d7714;
                          lVar19 = uVar16 + 1;
                          uVar16 = uVar16 + 1;
                        } while (psVar12[lVar19] != 0x5d);
                        if (uVar16 < uVar28) {
LAB_2ac334d76f2:
                          if ((int)uVar16 == -1) goto LAB_2ac334d7714;
                          goto LAB_2ac334d76f7;
                        }
                        goto LAB_2ac334d7814;
                      }
                      bVar33 = true;
                      uVar29 = 1;
                      uVar16 = 0;
                      do {
                        iVar11 = (int)uVar29;
                        if (psVar12[uVar16] == 0x5d) {
                          psVar21 = (short *)&DAT_2ac334fbfae;
                          lVar19 = (ulonglong)_DAT_2ac334fbfa8 - 1;
                          while (psVar12[uVar29] == *psVar21) {
                            psVar21 = psVar21 + 1;
                            uVar29 = (ulonglong)((int)uVar29 + 1);
                            lVar19 = lVar19 + -1;
                            if (lVar19 == 0) goto LAB_2ac334d76d8;
                          }
                          if ((int)lVar19 == 0) {
LAB_2ac334d76d8:
                            if (bVar33) goto LAB_2ac334d76f2;
                            goto LAB_2ac334d7714;
                          }
                        }
                        uVar16 = uVar16 + 1;
                        uVar29 = (ulonglong)(iVar11 + 1);
                        bVar33 = uVar16 < uVar28;
                      } while (uVar16 != uVar28);
                      uVar20 = *(uint *)(psVar12 + -2);
                      if (uVar20 != 0) goto LAB_2ac334d781f;
LAB_2ac334d7958:
                      _DAT_2ac33505c10 = 0x13ab;
                    }
LAB_2ac334d7968:
                    psVar12 = *(short **)(lVar32 + 0x2ac33500220);
                    if (psVar12 == (short *)0x0) {
                      _DAT_2ac33505c10 = 0xfa9;
                    }
                    else {
                      uVar20 = *(uint *)(psVar12 + -2);
                      if ((uVar20 == 0) || (_DAT_2ac334fbfc8 == 0)) {
                        _DAT_2ac33505c10 = 0x13ab;
                      }
                      else {
                        if (psVar12 == (short *)0x2ac334fbfcc) goto LAB_2ac334d7aa0;
                        if ((_DAT_2ac334fbfc8 <= uVar20) &&
                           (uVar20 = (uVar20 - _DAT_2ac334fbfc8) + 1, uVar20 != 0)) {
                          uVar28 = (ulonglong)uVar20;
                          if (_DAT_2ac334fbfc8 < 2) {
                            if (*psVar12 == 0x26) {
LAB_2ac334d7aa0:
                              FUN_2ac334d0590(lVar32 + 0x2ac3350021c,0x2ac334fbfcc);
                            }
                            else {
                              uVar16 = 0;
                              do {
                                if (uVar28 - 1 == uVar16) goto LAB_2ac334d7ab9;
                                lVar19 = uVar16 + 1;
                                uVar16 = uVar16 + 1;
                              } while (psVar12[lVar19] != 0x26);
                              if (uVar16 < uVar28) {
LAB_2ac334d7a9b:
                                if ((int)uVar16 != -1) goto LAB_2ac334d7aa0;
                              }
                            }
                          }
                          else {
                            bVar33 = true;
                            uVar29 = 1;
                            uVar16 = 0;
                            do {
                              iVar11 = (int)uVar29;
                              if (psVar12[uVar16] == 0x26) {
                                psVar21 = (short *)&DAT_2ac334fbfce;
                                lVar19 = (ulonglong)_DAT_2ac334fbfc8 - 1;
                                while (psVar12[uVar29] == *psVar21) {
                                  psVar21 = psVar21 + 1;
                                  uVar29 = (ulonglong)((int)uVar29 + 1);
                                  lVar19 = lVar19 + -1;
                                  if (lVar19 == 0) goto LAB_2ac334d7a81;
                                }
                                if ((int)lVar19 == 0) {
LAB_2ac334d7a81:
                                  if (bVar33) goto LAB_2ac334d7a9b;
                                  break;
                                }
                              }
                              uVar16 = uVar16 + 1;
                              uVar29 = (ulonglong)(iVar11 + 1);
                              bVar33 = uVar16 < uVar28;
                            } while (uVar16 != uVar28);
                          }
                        }
                      }
                    }
LAB_2ac334d7ab9:
                    psVar12 = *(short **)(lVar32 + 0x2ac3350022c);
                    if (psVar12 == (short *)0x0) {
                      _DAT_2ac33505c10 = 0xfa9;
                    }
                    else {
                      uVar20 = *(uint *)(psVar12 + -2);
                      if ((uVar20 == 0) || (_DAT_2ac334fbfc8 == 0)) {
                        _DAT_2ac33505c10 = 0x13ab;
                      }
                      else {
                        if (psVar12 == (short *)0x2ac334fbfcc) goto LAB_2ac334d7bf2;
                        if ((_DAT_2ac334fbfc8 <= uVar20) &&
                           (uVar20 = (uVar20 - _DAT_2ac334fbfc8) + 1, uVar20 != 0)) {
                          uVar28 = (ulonglong)uVar20;
                          if (_DAT_2ac334fbfc8 < 2) {
                            if (*psVar12 == 0x26) {
LAB_2ac334d7bf2:
                              FUN_2ac334d0590(lVar32 + 0x2ac33500228,0x2ac334fbfcc);
                            }
                            else {
                              uVar16 = 0;
                              do {
                                if (uVar28 - 1 == uVar16) goto LAB_2ac334d7c0b;
                                lVar19 = uVar16 + 1;
                                uVar16 = uVar16 + 1;
                              } while (psVar12[lVar19] != 0x26);
                              if (uVar16 < uVar28) {
LAB_2ac334d7bed:
                                if ((int)uVar16 != -1) goto LAB_2ac334d7bf2;
                              }
                            }
                          }
                          else {
                            bVar33 = true;
                            uVar29 = 1;
                            uVar16 = 0;
                            do {
                              iVar11 = (int)uVar29;
                              if (psVar12[uVar16] == 0x26) {
                                psVar21 = (short *)&DAT_2ac334fbfce;
                                lVar19 = (ulonglong)_DAT_2ac334fbfc8 - 1;
                                while (psVar12[uVar29] == *psVar21) {
                                  psVar21 = psVar21 + 1;
                                  uVar29 = (ulonglong)((int)uVar29 + 1);
                                  lVar19 = lVar19 + -1;
                                  if (lVar19 == 0) goto LAB_2ac334d7bd3;
                                }
                                if ((int)lVar19 == 0) {
LAB_2ac334d7bd3:
                                  if (bVar33) goto LAB_2ac334d7bed;
                                  break;
                                }
                              }
                              uVar16 = uVar16 + 1;
                              uVar29 = (ulonglong)(iVar11 + 1);
                              bVar33 = uVar16 < uVar28;
                            } while (uVar16 != uVar28);
                          }
                        }
                      }
                    }
LAB_2ac334d7c0b:
                    puVar22 = *(undefined1 **)(lVar32 + 0x2ac33500220);
                    if (puVar22 == &DAT_2ac334f9158) {
LAB_2ac334d7c6f:
                      FUN_2ac334d0af0(lVar32 + 0x2ac3350021c,0x2ac334fbff8,0);
                    }
                    else if (puVar22 != (undefined1 *)0x0) {
                      uVar20 = *(uint *)(puVar22 + -4);
                      uVar26 = _DAT_2ac334f9154;
                      if (uVar20 < _DAT_2ac334f9154) {
                        uVar26 = uVar20;
                      }
                      iVar11 = uVar20 - _DAT_2ac334f9154;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar11 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      if (iVar11 == 0) goto LAB_2ac334d7c6f;
                    }
                    puVar22 = *(undefined1 **)(lVar32 + 0x2ac3350022c);
                    if (puVar22 == &DAT_2ac334f9158) {
LAB_2ac334d7cef:
                      FUN_2ac334d0af0(lVar32 + 0x2ac33500228,0x2ac334fbff8,0,0x2ac334feae0);
                    }
                    else if (puVar22 != (undefined1 *)0x0) {
                      uVar20 = *(uint *)(puVar22 + -4);
                      uVar26 = _DAT_2ac334f9154;
                      if (uVar20 < _DAT_2ac334f9154) {
                        uVar26 = uVar20;
                      }
                      iVar11 = uVar20 - _DAT_2ac334f9154;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar11 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      if (iVar11 == 0) goto LAB_2ac334d7cef;
                    }
                    local_170 = lVar32 + 0x2ac33500204;
                    FUN_2ac334d0af0(&local_1e8,local_170,0,0x2ac334feaf0);
                    FUN_2ac334d0af0(&local_1a0,&DAT_2ac335001f8 + lVar32,0,0x2ac334feb00);
                    FUN_2ac334f6140(&local_1a0,&local_1e8);
                    FUN_2ac334d0af0(&local_190,0x2ac33505c3c,1,0x2ac334feb10);
                    lVar19 = (*(code *)0x7ff63a0fd370)(0x2ac301f9168,&local_190);
                    local_1c8 = (*(code *)0x7ff63a101e20)(0x2ac301f9168,0);
                    local_1d8 = lVar19;
                    (*(code *)0x7ff63a101f60)(0x2ac301f9168,lVar19,&local_98);
                    uVar13 = (*(code *)0x7ff63a101e20)(0x2ac301f9168,0);
                    (*(code *)0x7ff63a101f60)(0x2ac301f9168,uVar13,&local_b8);
                    FUN_2ac334d0af0(&local_1e8,lVar32 + 0x2ac33500210,0,0x2ac334feb20);
                    iVar11 = local_1cc;
                    uVar34 = uVar36;
                    uVar35 = uVar37;
                    if (local_1e4 == &DAT_2ac334fbb9c) {
LAB_2ac334d8033:
                      *(ulonglong *)(uVar27 * 8 + 0x2ac33504c90) = CONCAT44(uVar35,uVar34);
LAB_2ac334d8047:
                      iVar14 = ((int)local_1d8 - (int)local_1c8) / 0x3c;
                    }
                    else {
                      uVar34 = 0;
                      uVar35 = 0;
                      if (local_1e4 == (undefined1 *)0x0) goto LAB_2ac334d8033;
                      uVar20 = *(uint *)(local_1e4 + -4);
                      uVar26 = _DAT_2ac334fbb98;
                      if (uVar20 < _DAT_2ac334fbb98) {
                        uVar26 = uVar20;
                      }
                      iVar14 = uVar20 - _DAT_2ac334fbb98;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334fbb9c + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar14 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      uVar34 = uVar36;
                      uVar35 = uVar37;
                      if ((iVar14 == 0) ||
                         (uVar34 = uVar38, uVar35 = uVar39, local_1e4 == &DAT_2ac334fbbbc))
                      goto LAB_2ac334d8033;
                      uVar26 = _DAT_2ac334fbbb8;
                      if (uVar20 < _DAT_2ac334fbbb8) {
                        uVar26 = uVar20;
                      }
                      iVar14 = uVar20 - _DAT_2ac334fbbb8;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334fbbbc + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar14 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      if ((iVar14 == 0) ||
                         (uVar34 = uVar40, uVar35 = uVar41, local_1e4 == &DAT_2ac334fbbdc))
                      goto LAB_2ac334d8033;
                      uVar26 = _DAT_2ac334fbbd8;
                      if (uVar20 < _DAT_2ac334fbbd8) {
                        uVar26 = uVar20;
                      }
                      iVar14 = uVar20 - _DAT_2ac334fbbd8;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334fbbdc + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar14 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      if (iVar14 == 0) goto LAB_2ac334d8033;
                      if (local_1e4 != &DAT_2ac334fbbfc) {
                        uVar26 = _DAT_2ac334fbbf8;
                        if (uVar20 < _DAT_2ac334fbbf8) {
                          uVar26 = uVar20;
                        }
                        iVar14 = uVar20 - _DAT_2ac334fbbf8;
                        if (uVar26 != 0) {
                          uVar28 = 0;
                          do {
                            uVar3 = *(ushort *)(local_1e4 + uVar28 * 2);
                            uVar4 = *(ushort *)(&DAT_2ac334fbbfc + uVar28 * 2);
                            uVar28 = uVar28 + 1;
                            if (uVar26 <= uVar28) break;
                          } while (uVar3 == uVar4);
                          if (uVar3 != uVar4) {
                            iVar14 = (uint)uVar3 - (uint)uVar4;
                          }
                        }
                        uVar34 = 0;
                        uVar35 = 0;
                        if (iVar14 != 0) goto LAB_2ac334d8033;
                      }
                      *(undefined8 *)(uVar27 * 8 + 0x2ac33504c90) = 0x4010000000000000;
                      if (((local_90 != local_b0) || (local_94 != local_b8._4_4_)) ||
                         (iVar14 = 0, local_98 != (int)local_b8)) goto LAB_2ac334d8047;
                    }
                    if (-1 < _DAT_2ac33505920 + iVar14) {
                      *(double *)(&DAT_2ac33504650 + uVar27 * 8) = (double)iVar14;
                      FUN_2ac334d0af0(&local_1e8,local_170,0,0x2ac334feb30);
                      FUN_2ac334d0af0(&local_1a0,&DAT_2ac335001f8 + lVar32,0,0x2ac334feb40);
                      FUN_2ac334f6140(&local_1a0,&local_1e8);
                      FUN_2ac334d0af0(&local_190,0x2ac33505c3c,1,0x2ac334feb50);
                      lVar32 = (*(code *)0x7ff63a0fd370)(0x2ac301f9168,&local_190);
                      uVar18 = uVar18 + 1;
                      *(longlong *)(uVar27 * 8 + 0x2ac335052d0) = lVar32 - _DAT_2ac33505964;
                    }
                  }
                  else {
                    uVar20 = *(uint *)(puVar5 + -4);
                    uVar26 = _DAT_2ac334fbf68;
                    if (uVar20 < _DAT_2ac334fbf68) {
                      uVar26 = uVar20;
                    }
                    iVar14 = uVar20 - _DAT_2ac334fbf68;
                    if (uVar26 != 0) {
                      uVar28 = 0;
                      do {
                        uVar3 = *(ushort *)(puVar5 + uVar28 * 2);
                        uVar4 = *(ushort *)(&DAT_2ac334fbf6c + uVar28 * 2);
                        uVar28 = uVar28 + 1;
                        if (uVar26 <= uVar28) break;
                      } while (uVar3 == uVar4);
                      if (uVar3 != uVar4) {
                        iVar14 = (uint)uVar3 - (uint)uVar4;
                      }
                    }
                    if ((iVar14 != 0) && (puVar5 != &DAT_2ac334f9158)) {
                      uVar26 = _DAT_2ac334f9154;
                      if (uVar20 < _DAT_2ac334f9154) {
                        uVar26 = uVar20;
                      }
                      iVar14 = uVar20 - _DAT_2ac334f9154;
                      if (uVar26 != 0) {
                        uVar28 = 0;
                        do {
                          uVar3 = *(ushort *)(puVar5 + uVar28 * 2);
                          uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar28 * 2);
                          uVar28 = uVar28 + 1;
                          if (uVar26 <= uVar28) break;
                        } while (uVar3 == uVar4);
                        if (uVar3 != uVar4) {
                          iVar14 = (uint)uVar3 - (uint)uVar4;
                        }
                      }
                      if (iVar14 != 0) goto LAB_2ac334d7303;
                    }
                  }
                }
              }
              else if (puVar22 != (undefined1 *)0x0) {
                uVar20 = *(uint *)(puVar22 + -4);
                uVar26 = _DAT_2ac334fbbf8;
                if (uVar20 < _DAT_2ac334fbbf8) {
                  uVar26 = uVar20;
                }
                iVar14 = uVar20 - _DAT_2ac334fbbf8;
                if (uVar26 != 0) {
                  uVar28 = 0;
                  do {
                    uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                    uVar4 = *(ushort *)(&DAT_2ac334fbbfc + uVar28 * 2);
                    uVar28 = uVar28 + 1;
                    if (uVar26 <= uVar28) break;
                  } while (uVar3 == uVar4);
                  if (uVar3 != uVar4) {
                    iVar14 = (uint)uVar3 - (uint)uVar4;
                  }
                }
                if (iVar14 == 0) goto LAB_2ac334d7207;
              }
            }
            else {
              uVar20 = *(uint *)(puVar22 + -4);
              uVar26 = _DAT_2ac334fbbb8;
              if (uVar20 < _DAT_2ac334fbbb8) {
                uVar26 = uVar20;
              }
              iVar14 = uVar20 - _DAT_2ac334fbbb8;
              if (uVar26 != 0) {
                uVar28 = 0;
                do {
                  uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                  uVar4 = *(ushort *)(&DAT_2ac334fbbbc + uVar28 * 2);
                  uVar28 = uVar28 + 1;
                  if (uVar26 <= uVar28) break;
                } while (uVar3 == uVar4);
                if (uVar3 != uVar4) {
                  iVar14 = (uint)uVar3 - (uint)uVar4;
                }
              }
              if ((iVar14 != 0) && (puVar22 != &DAT_2ac334fbbdc)) {
                uVar20 = *(uint *)(puVar22 + -4);
                uVar26 = _DAT_2ac334fbbd8;
                if (uVar20 < _DAT_2ac334fbbd8) {
                  uVar26 = uVar20;
                }
                iVar14 = uVar20 - _DAT_2ac334fbbd8;
                if (uVar26 != 0) {
                  uVar28 = 0;
                  do {
                    uVar3 = *(ushort *)(puVar22 + uVar28 * 2);
                    uVar4 = *(ushort *)(&DAT_2ac334fbbdc + uVar28 * 2);
                    uVar28 = uVar28 + 1;
                    if (uVar26 <= uVar28) break;
                  } while (uVar3 == uVar4);
                  if (uVar3 != uVar4) {
                    iVar14 = (uint)uVar3 - (uint)uVar4;
                  }
                }
                if (iVar14 != 0) goto joined_r0x02ac334d706d;
              }
            }
          }
        }
      }
LAB_2ac334d66e0:
    } while (_DAT_2ac33505c14 == 0);
    puVar22 = &DAT_2ac335001e0;
    _DAT_2ac33504630 = 0;
    uRam000002ac33504638 = 0;
    _DAT_2ac33504640 = 0;
    uRam000002ac33504648 = 0;
    _DAT_2ac33504620 = 0;
    uRam000002ac33504628 = 0;
    _DAT_2ac33504600 = 0;
    uRam000002ac33504608 = 0;
    _DAT_2ac33504610 = 0;
    uRam000002ac33504618 = 0;
    if (0 < (int)uVar18) {
      uVar27 = 10;
      if ((int)uVar18 < 10) {
        uVar27 = (ulonglong)uVar18;
      }
      lVar32 = 0;
      lVar19 = 0;
      do {
        FUN_2ac334d0af0(&DAT_2ac33504380 + lVar19,puVar22,0,0x2ac334feb60);
        FUN_2ac334d0af0(&DAT_2ac33504400 + lVar19,puVar22 + 0xc,0,0x2ac334feb70);
        FUN_2ac334d0af0(&DAT_2ac33504480 + lVar19,puVar22 + 0x30,0,0x2ac334feb80);
        FUN_2ac334d0af0(&DAT_2ac33504500 + lVar19,puVar22 + 0x3c,0,0x2ac334feb90);
        FUN_2ac334d0af0(&DAT_2ac33504580 + lVar19,puVar22 + 0x48,0,0x2ac334feba0);
        lVar19 = lVar19 + 0xc;
        puVar22 = puVar22 + 0x54;
        *(undefined8 *)(&DAT_2ac33504600 + lVar32) = *(undefined8 *)(lVar32 + 0x2ac335052d0);
        lVar32 = lVar32 + 8;
      } while (uVar27 * 0xc != lVar19);
    }
  }
  else {
    _DAT_2ac33504630 = 0;
    uRam000002ac33504638 = 0;
    _DAT_2ac33504620 = 0;
    uRam000002ac33504628 = 0;
    _DAT_2ac33504640 = 0;
    uRam000002ac33504648 = 0;
    _DAT_2ac33504610 = 0;
    uRam000002ac33504618 = 0;
    _DAT_2ac33504600 = 0;
    uRam000002ac33504608 = 0;
  }
  FUN_2ac334d00a0(&local_1c0);
  FUN_2ac334d00a0(&local_180);
  FUN_2ac334d00a0(&local_1b0);
  lVar32 = -0x54;
  do {
    if (((*(int *)((longlong)&iStack_114 + lVar32) != 0) &&
        (lVar19 = *(longlong *)(local_110 + lVar32), lVar19 != 0)) &&
       (((int *)(lVar19 + -0xc) != (int *)0x0 && (*(int *)(lVar19 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar19 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(local_110 + lVar32) = 0;
    *(undefined4 *)((longlong)&iStack_114 + lVar32) = 0;
    lVar32 = lVar32 + 0xc;
  } while (lVar32 != 0);
  lVar32 = -0x54;
  do {
    if (((*(int *)((longlong)&iStack_bc + lVar32) != 0) &&
        (lVar19 = *(longlong *)((longlong)&local_b8 + lVar32), lVar19 != 0)) &&
       (((int *)(lVar19 + -0xc) != (int *)0x0 && (*(int *)(lVar19 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar19 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)((longlong)&local_b8 + lVar32) = 0;
    *(undefined4 *)((longlong)&iStack_bc + lVar32) = 0;
    lVar32 = lVar32 + 0xc;
  } while (lVar32 != 0);
  FUN_2ac334d00a0(&local_1e8);
  FUN_2ac334d00a0(&local_1a0);
  FUN_2ac334d00a0(&local_190);
  return;
}



/* Address: 2ac334d8450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d8450(double *param_1,double *param_2,int *param_3)

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
  longlong local_d8;
  double *local_d0;
  double *local_c8;
  int *local_c0;
  
  local_e8 = 0;
  local_e4 = 0;
  *param_1 = 0.0;
  *param_2 = 0.0;
  *param_3 = 0;
  local_d0 = param_1;
  local_c8 = param_2;
  local_c0 = param_3;
  uVar12 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
  (*(code *)0x7ff63a0fcc50)(0x2ac301f9168,uVar12,1);
  FUN_2ac334d0af0(&local_e8,0x2ac33505c3c,1,0x2ac334fea00);
  uVar12 = (*(code *)0x7ff63a0fd370)(0x2ac301f9168,&local_e8);
  uVar13 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
  (*(code *)0x7ff63a1084f0)(0x2ac301f9168,uVar12,uVar13);
  iVar11 = (*(code *)0x7ff63a108810)(0x2ac301f9168);
  dVar8 = _DAT_2ac334f8a38;
  if (-1 < iVar11 + -1) {
    lVar18 = (longlong)_DAT_2ac33505d18;
    iVar11 = iVar11 + -1;
    local_d8 = lVar18;
    do {
      uVar12 = (*(code *)0x7ff63a108860)(0x2ac301f9168,iVar11);
      (*(code *)0x7ff63a1089d0)(0x2ac301f9168,uVar12,0);
      FUN_2ac334d0af0(&local_e8,0x2ac33505c3c,1,0x2ac334fea10);
      if (local_e4 == _DAT_2ac33505c2c) {
LAB_2ac334d86f2:
        lVar14 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar12);
        if (lVar14 == lVar18) {
          lVar18 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar12,4);
          if (lVar18 == 1) {
            (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar12,9);
            dVar6 = _DAT_2ac33505c48;
            (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar12,8);
            dVar6 = dVar6 + _DAT_2ac33505c48;
            (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar12,7);
            dVar9 = _DAT_2ac33505c48;
            (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x1b);
            dVar21 = _DAT_2ac33505c48;
            (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x10);
            dVar10 = _DAT_2ac33505c48;
            (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x1a);
            lVar18 = local_d8;
            dVar20 = dVar8;
            if ((((dVar21 != 0.0) || (NAN(dVar21))) &&
                ((_DAT_2ac33505c48 != 0.0 || (NAN(_DAT_2ac33505c48))))) &&
               ((dVar10 != 0.0 || (NAN(dVar10))))) {
              dVar21 = dVar21 / dVar10;
              if ((dVar21 == 0.0) && (!NAN(dVar21))) {
                (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x32081a000001f7);
LAB_2ac334d89d0:
                (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e081b000001f7);
                pcVar5 = (code *)swi(3);
                (*pcVar5)();
                return;
              }
              dVar20 = _DAT_2ac33505c48 / dVar21;
              if ((dVar20 == 0.0) && (!NAN(dVar20))) goto LAB_2ac334d89d0;
            }
            (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar12);
            if ((_DAT_2ac33505c48 != 0.0) || (NAN(_DAT_2ac33505c48))) {
              dVar6 = dVar6 + dVar9 + dVar9;
              dVar20 = (dVar6 / dVar20) / _DAT_2ac33505c48;
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
              *local_d0 = dVar6 + *local_d0;
              *local_c8 = (double)(int)dVar21 + *local_c8;
            }
          }
          else {
            lVar14 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar12);
            lVar18 = local_d8;
            if (lVar14 == 0) {
              *local_c0 = *local_c0 + 1;
            }
          }
        }
      }
      else if ((local_e4 != 0) && (_DAT_2ac33505c2c != 0)) {
        uVar17 = *(uint *)(local_e4 + -4);
        uVar3 = *(uint *)(_DAT_2ac33505c2c + -4);
        uVar7 = uVar3;
        if (uVar17 < uVar3) {
          uVar7 = uVar17;
        }
        iVar16 = uVar17 - uVar3;
        if (uVar7 != 0) {
          uVar19 = 1;
          do {
            uVar1 = *(ushort *)(local_e4 + -2 + uVar19 * 2);
            uVar2 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar19 * 2);
            if (uVar7 <= uVar19) break;
            uVar19 = uVar19 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar16 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar16 == 0) goto LAB_2ac334d86f2;
      }
      bVar4 = 0 < iVar11;
      iVar11 = iVar11 + -1;
    } while (bVar4);
  }
  FUN_2ac334d00a0(&local_e8);
  return;
}



/* Address: 2ac334d89b0 */

void FUN_2ac334d89b0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x32081a000001f7);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e081b000001f7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ac334d8a00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334d8a00(undefined4 param_1,double param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  char cVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  char *pcVar18;
  uint uVar19;
  int iVar20;
  ulonglong uVar21;
  char *pcVar22;
  ulonglong uVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  uint uVar26;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined4 local_d0;
  longlong local_cc;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b0;
  longlong local_ac;
  undefined4 local_a0;
  undefined8 local_9c;
  int local_90;
  int local_8c;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  local_b0 = 0;
  local_88 = 0;
  local_d0 = 0;
  local_100 = 0;
  local_f0 = 0;
  local_e0 = 0;
  local_c0 = 0;
  local_a0 = 0;
  local_ac = 0;
  local_84 = 0;
  local_cc = 0;
  local_fc = 0;
  local_ec = 0;
  local_dc = 0;
  local_bc = 0;
  local_9c = 0;
  if (DAT_2ac33505b00 != '\x01') goto LAB_2ac334da007;
  local_bc = 0;
  uVar26 = 0;
  FUN_2ac334d0af0(&local_c0,0x2ac33505b10,0,0x2ac334ff560);
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff570);
  lVar12 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x12);
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,(double)lVar12,0);
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff580);
  FUN_2ac334d0af0(&local_100,&local_c0,0,0x2ac334ff590);
  uVar16 = _DAT_2ac334f9458;
  uVar23 = (ulonglong)_DAT_2ac334f9458;
  if ((uVar23 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar26 = *(uint *)(local_fc + -4);
    }
    uVar19 = _DAT_2ac334f9458 + uVar26;
    uVar15 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar15 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    cVar11 = FUN_2ac334d0100(&local_100,uVar15);
    if (cVar11 != '\0') {
      if (uVar23 != 0) {
        lVar12 = local_fc + (ulonglong)uVar26 * 2;
        if (uVar16 < 0x10) {
          uVar21 = 0;
        }
        else if (lVar12 - 0x2ac334f945cU < 0x20) {
          uVar21 = 0;
        }
        else {
          uVar25 = 0;
          uVar21 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar14 = *(undefined4 *)(uVar25 + 0x2ac334f9460);
            uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9464);
            uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9468);
            puVar3 = (undefined4 *)(lVar12 + uVar25);
            *puVar3 = *(undefined4 *)(&DAT_2ac334f945c + uVar25);
            puVar3[1] = uVar14;
            puVar3[2] = uVar17;
            puVar3[3] = uVar7;
            uVar25 = uVar25 + 0x10;
          } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
          if (uVar21 == uVar23) goto LAB_2ac334d8cb2;
        }
        do {
          *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f945c + uVar21 * 2);
          uVar21 = uVar21 + 1;
        } while (uVar23 != uVar21);
      }
LAB_2ac334d8cb2:
      *(uint *)(local_fc + -4) = uVar19;
      *(undefined2 *)(local_fc + (ulonglong)uVar19 * 2) = 0;
      goto LAB_2ac334d8cbd;
    }
LAB_2ac334da11e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x160bb6000001f9);
LAB_2ac334da13e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x170bb7000001f9);
LAB_2ac334da15e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x170bb8000001f9);
LAB_2ac334da17e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x170bbb000001f9);
LAB_2ac334da19e:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x170bbc000001f9);
LAB_2ac334da1be:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x170bbd000001f9);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
LAB_2ac334d8cbd:
  FUN_2ac334f7ba0(&local_100,&local_f0,0xffffffff,&local_e0);
  uVar26 = 0;
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff5a0);
  uVar13 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
  FUN_2ac334f59c0(uVar13);
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff5b0);
  FUN_2ac334d0af0(&local_100,&local_c0,0,0x2ac334ff5c0);
  uVar16 = _DAT_2ac334f9488;
  uVar23 = (ulonglong)_DAT_2ac334f9488;
  if ((uVar23 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar26 = *(uint *)(local_fc + -4);
    }
    uVar19 = _DAT_2ac334f9488 + uVar26;
    uVar15 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar15 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    cVar11 = FUN_2ac334d0100(&local_100,uVar15);
    if (cVar11 == '\0') goto LAB_2ac334da13e;
    if (uVar23 != 0) {
      lVar12 = local_fc + (ulonglong)uVar26 * 2;
      if (uVar16 < 0x10) {
        uVar21 = 0;
      }
      else if (lVar12 - 0x2ac334f948cU < 0x20) {
        uVar21 = 0;
      }
      else {
        uVar25 = 0;
        uVar21 = (ulonglong)(uVar16 & 0xfffffff8);
        do {
          uVar14 = *(undefined4 *)(uVar25 + 0x2ac334f9490);
          uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9494);
          uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9498);
          puVar3 = (undefined4 *)(lVar12 + uVar25);
          *puVar3 = *(undefined4 *)(&DAT_2ac334f948c + uVar25);
          puVar3[1] = uVar14;
          puVar3[2] = uVar17;
          puVar3[3] = uVar7;
          uVar25 = uVar25 + 0x10;
        } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
        if (uVar21 == uVar23) goto LAB_2ac334d8e72;
      }
      do {
        *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f948c + uVar21 * 2);
        uVar21 = uVar21 + 1;
      } while (uVar23 != uVar21);
    }
LAB_2ac334d8e72:
    *(uint *)(local_fc + -4) = uVar19;
    *(undefined2 *)(local_fc + (ulonglong)uVar19 * 2) = 0;
  }
  FUN_2ac334f7ba0(&local_100,&local_f0,0xffffffff,&local_e0);
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff5d0);
  local_78 = 0;
  local_74 = 0;
  if (DAT_2ac335001c0 == '\0') {
    uVar13 = 0x2ac334fcba0;
    uVar24 = 0x2ac334ff220;
  }
  else {
    uVar13 = 0x2ac334fcbd0;
    uVar24 = 0x2ac334ff230;
  }
  FUN_2ac334d0af0(&local_78,uVar13,0,uVar24);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_78,1,0x2ac334ff240);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff5e0);
  uVar26 = 0;
  FUN_2ac334d0af0(&local_100,&local_c0,0);
  uVar16 = _DAT_2ac334f9438;
  uVar23 = (ulonglong)_DAT_2ac334f9438;
  if ((uVar23 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar26 = *(uint *)(local_fc + -4);
    }
    uVar15 = _DAT_2ac334f9438 + uVar26;
    cVar11 = FUN_2ac334d0100(&local_100);
    if (cVar11 == '\0') goto LAB_2ac334da15e;
    if (uVar23 != 0) {
      lVar12 = local_fc + (ulonglong)uVar26 * 2;
      if ((uVar16 < 0x10) || (lVar12 - 0x2ac334f943cU < 0x20)) {
        uVar21 = 0;
      }
      else {
        uVar25 = 0;
        uVar21 = (ulonglong)(uVar16 & 0xfffffff8);
        do {
          uVar14 = *(undefined4 *)(uVar25 + 0x2ac334f9440);
          uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9444);
          uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9448);
          puVar3 = (undefined4 *)(lVar12 + uVar25);
          *puVar3 = *(undefined4 *)(&DAT_2ac334f943c + uVar25);
          puVar3[1] = uVar14;
          puVar3[2] = uVar17;
          puVar3[3] = uVar7;
          uVar25 = uVar25 + 0x10;
        } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
        if (uVar21 == uVar23) goto LAB_2ac334d9042;
      }
      do {
        *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f943c + uVar21 * 2);
        uVar21 = uVar21 + 1;
      } while (uVar23 != uVar21);
    }
LAB_2ac334d9042:
    *(uint *)(local_fc + -4) = uVar15;
    *(undefined2 *)(local_fc + (ulonglong)uVar15 * 2) = 0;
  }
  local_90 = param_3;
  FUN_2ac334f7ba0(&local_100,&local_f0,0xffffffff,&local_e0);
  uVar26 = 0;
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff600);
  local_8c = (int)param_2;
  pcVar18 = &DAT_2ac33505b2d;
  pcVar22 = &DAT_2ac33505b2d;
  uVar14 = 0x858586;
  if (local_8c < 0) {
    uVar14 = 0x3c14dc;
    pcVar22 = &DAT_2ac33505b2f;
  }
  if (0 < local_8c) {
    pcVar22 = &DAT_2ac33505b2e;
    uVar14 = 0x8000;
  }
  uVar17 = 0;
  if (*pcVar22 != '\0') {
    uVar17 = uVar14;
  }
  FUN_2ac334f6fa0(param_1);
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff610);
  FUN_2ac334d0af0(&local_100,&local_c0,0,0x2ac334ff620);
  uVar16 = _DAT_2ac334f93c8;
  uVar23 = (ulonglong)_DAT_2ac334f93c8;
  if ((uVar23 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar26 = *(uint *)(local_fc + -4);
    }
    uVar19 = _DAT_2ac334f93c8 + uVar26;
    uVar15 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar15 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    cVar11 = FUN_2ac334d0100(&local_100,uVar15);
    if (cVar11 == '\0') goto LAB_2ac334da17e;
    if (uVar23 != 0) {
      lVar12 = local_fc + (ulonglong)uVar26 * 2;
      if (uVar16 < 0x10) {
        uVar21 = 0;
      }
      else if (lVar12 - 0x2ac334f93ccU < 0x20) {
        uVar21 = 0;
      }
      else {
        uVar25 = 0;
        uVar21 = (ulonglong)(uVar16 & 0xfffffff8);
        do {
          uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f93d0);
          uVar8 = *(undefined4 *)(uVar25 + 0x2ac334f93d4);
          uVar9 = *(undefined4 *)(uVar25 + 0x2ac334f93d8);
          puVar3 = (undefined4 *)(lVar12 + uVar25);
          *puVar3 = *(undefined4 *)(&DAT_2ac334f93cc + uVar25);
          puVar3[1] = uVar7;
          puVar3[2] = uVar8;
          puVar3[3] = uVar9;
          uVar25 = uVar25 + 0x10;
        } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
        if (uVar21 == uVar23) goto LAB_2ac334d9292;
      }
      do {
        *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f93cc + uVar21 * 2);
        uVar21 = uVar21 + 1;
      } while (uVar23 != uVar21);
    }
LAB_2ac334d9292:
    *(uint *)(local_fc + -4) = uVar19;
    *(undefined2 *)(local_fc + (ulonglong)uVar19 * 2) = 0;
  }
  FUN_2ac334f7ba0(&local_100,&local_f0,uVar17,&local_e0);
  uVar23 = 0;
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff630);
  if (local_8c < 0) {
    pcVar18 = &DAT_2ac33505b2f;
  }
  if (0 < local_8c) {
    pcVar18 = &DAT_2ac33505b2e;
  }
  if (*pcVar18 == '\0') {
    uVar14 = 0;
  }
  FUN_2ac334f7560(SUB84(param_2,0));
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff640);
  FUN_2ac334d0af0(&local_100,&local_c0,0,0x2ac334ff650);
  uVar26 = _DAT_2ac334f93f8;
  uVar21 = (ulonglong)_DAT_2ac334f93f8;
  if ((uVar21 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar23 = (ulonglong)*(uint *)(local_fc + -4);
    }
    uVar15 = _DAT_2ac334f93f8 + (int)uVar23;
    uVar16 = 0x104;
    if ((0x103 < uVar15) &&
       ((0x7ffffffd < uVar15 || (uVar16 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar16)))) {
      uVar16 = 0x7ffffffe;
    }
    cVar11 = FUN_2ac334d0100(&local_100,uVar16);
    if (cVar11 == '\0') goto LAB_2ac334da19e;
    if (uVar21 != 0) {
      lVar12 = local_fc + uVar23 * 2;
      if (uVar26 < 0x10) {
        uVar23 = 0;
      }
      else if (lVar12 - 0x2ac334f93fcU < 0x20) {
        uVar23 = 0;
      }
      else {
        uVar25 = 0;
        uVar23 = (ulonglong)(uVar26 & 0xfffffff8);
        do {
          uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9400);
          uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9404);
          uVar8 = *(undefined4 *)(uVar25 + 0x2ac334f9408);
          puVar3 = (undefined4 *)(lVar12 + uVar25);
          *puVar3 = *(undefined4 *)(&DAT_2ac334f93fc + uVar25);
          puVar3[1] = uVar17;
          puVar3[2] = uVar7;
          puVar3[3] = uVar8;
          uVar25 = uVar25 + 0x10;
        } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar25);
        if (uVar23 == uVar21) goto LAB_2ac334d9452;
      }
      do {
        *(undefined2 *)(lVar12 + uVar23 * 2) = *(undefined2 *)(&DAT_2ac334f93fc + uVar23 * 2);
        uVar23 = uVar23 + 1;
      } while (uVar21 != uVar23);
    }
LAB_2ac334d9452:
    *(uint *)(local_fc + -4) = uVar15;
    *(undefined2 *)(local_fc + (ulonglong)uVar15 * 2) = 0;
  }
  FUN_2ac334f7ba0(&local_100,&local_f0,uVar14,&local_e0);
  uVar26 = 0;
  FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff660);
  (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)local_90,0,0x20);
  FUN_2ac334d0af0(&local_f0,0x2ac33505c3c,1,0x2ac334ff670);
  FUN_2ac334d0af0(&local_100,&local_c0,0,0x2ac334ff680);
  uVar16 = _DAT_2ac334f9418;
  uVar23 = (ulonglong)_DAT_2ac334f9418;
  if ((uVar23 != 0) || (local_fc == 0)) {
    if (local_fc != 0) {
      uVar26 = *(uint *)(local_fc + -4);
    }
    uVar19 = _DAT_2ac334f9418 + uVar26;
    uVar15 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar15 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar15)))) {
      uVar15 = 0x7ffffffe;
    }
    cVar11 = FUN_2ac334d0100(&local_100,uVar15);
    if (cVar11 == '\0') goto LAB_2ac334da1be;
    if (uVar23 != 0) {
      lVar12 = local_fc + (ulonglong)uVar26 * 2;
      if (uVar16 < 0x10) {
        uVar21 = 0;
      }
      else if (lVar12 - 0x2ac334f941cU < 0x20) {
        uVar21 = 0;
      }
      else {
        uVar25 = 0;
        uVar21 = (ulonglong)(uVar16 & 0xfffffff8);
        do {
          uVar14 = *(undefined4 *)(uVar25 + 0x2ac334f9420);
          uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9424);
          uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9428);
          puVar3 = (undefined4 *)(lVar12 + uVar25);
          *puVar3 = *(undefined4 *)(&DAT_2ac334f941c + uVar25);
          puVar3[1] = uVar14;
          puVar3[2] = uVar17;
          puVar3[3] = uVar7;
          uVar25 = uVar25 + 0x10;
        } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
        if (uVar21 == uVar23) goto LAB_2ac334d9602;
      }
      do {
        *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f941c + uVar21 * 2);
        uVar21 = uVar21 + 1;
      } while (uVar23 != uVar21);
    }
LAB_2ac334d9602:
    *(uint *)(local_fc + -4) = uVar19;
    *(undefined2 *)(local_fc + (ulonglong)uVar19 * 2) = 0;
  }
  FUN_2ac334f7ba0(&local_100,&local_f0,0xffffffff,&local_e0);
  if (DAT_2ac33500044 != '\0') {
    lVar12 = 0;
    do {
      local_a0 = 0;
      local_9c = 0;
      FUN_2ac334d0af0(&local_a0,0x2ac334fcc78,0,0x2ac334ff690);
      if (*(longlong *)(&DAT_2ac33504600 + lVar12 * 8) != 0) {
        (*(code *)0x7ff63a0fcc50)(0x2ac301f9168,*(longlong *)(&DAT_2ac33504600 + lVar12 * 8),3);
        FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334ff6a0);
        FUN_2ac334d0af0(&local_f0,&local_e0,0,0x2ac334ff6b0);
        uVar26 = _DAT_2ac334fcc98;
        uVar23 = (ulonglong)_DAT_2ac334fcc98;
        if ((uVar23 != 0) || (local_ec == 0)) {
          if (local_ec == 0) {
            uVar16 = 0;
            uVar15 = _DAT_2ac334fcc98;
          }
          else {
            uVar16 = *(uint *)(local_ec + -4);
            uVar15 = _DAT_2ac334fcc98 + uVar16;
          }
          uVar19 = 0x104;
          if ((0x103 < uVar15) &&
             ((0x7ffffffd < uVar15 || (uVar19 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar19)))) {
            uVar19 = 0x7ffffffe;
          }
          cVar11 = FUN_2ac334d0100(&local_f0,uVar19);
          if (cVar11 != '\0') {
            if (uVar23 != 0) {
              lVar1 = local_ec + (ulonglong)uVar16 * 2;
              if (uVar26 < 8) {
                uVar21 = 0;
              }
              else if (local_ec + -0x2ac334fcc9c + (ulonglong)uVar16 * 2 < 0x20) {
                uVar21 = 0;
              }
              else {
                uVar25 = 0;
                uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  uVar14 = *(undefined4 *)(uVar25 + 0x2ac334fcca0);
                  uVar17 = *(undefined4 *)(uVar25 + 0x2ac334fcca4);
                  uVar7 = *(undefined4 *)(uVar25 + 0x2ac334fcca8);
                  puVar3 = (undefined4 *)(lVar1 + uVar25);
                  *puVar3 = *(undefined4 *)(&DAT_2ac334fcc9c + uVar25);
                  puVar3[1] = uVar14;
                  puVar3[2] = uVar17;
                  puVar3[3] = uVar7;
                  uVar25 = uVar25 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
                if (uVar21 == uVar23) goto LAB_2ac334d9872;
              }
              do {
                *(undefined2 *)(lVar1 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334fcc9c + uVar21 * 2)
                ;
                uVar21 = uVar21 + 1;
              } while (uVar23 != uVar21);
            }
LAB_2ac334d9872:
            *(uint *)(local_ec + -4) = uVar15;
            *(undefined2 *)(local_ec + (ulonglong)uVar15 * 2) = 0;
            goto LAB_2ac334d987d;
          }
          goto LAB_2ac334da09e;
        }
LAB_2ac334d987d:
        FUN_2ac334d0af0(&local_100,&local_f0,0);
        lVar1 = *(longlong *)(&DAT_2ac33504404 + lVar12 * 0xc);
        if (lVar1 == 0) {
LAB_2ac334d99c3:
          FUN_2ac334d0af0(&local_d0,&local_100,0,0x2ac334ff6d0);
          uVar26 = _DAT_2ac334fcc68;
          uVar23 = (ulonglong)_DAT_2ac334fcc68;
          if ((uVar23 != 0) || (local_cc == 0)) {
            if (local_cc == 0) {
              uVar16 = 0;
              uVar15 = _DAT_2ac334fcc68;
            }
            else {
              uVar16 = *(uint *)(local_cc + -4);
              uVar15 = _DAT_2ac334fcc68 + uVar16;
            }
            uVar19 = 0x104;
            if ((0x103 < uVar15) &&
               ((0x7ffffffd < uVar15 || (uVar19 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar19)))) {
              uVar19 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_d0,uVar19);
            if (cVar11 != '\0') {
              if (uVar23 != 0) {
                lVar1 = local_cc + (ulonglong)uVar16 * 2;
                if (uVar26 < 8) {
                  uVar21 = 0;
                }
                else if (local_cc + -0x2ac334fcc6c + (ulonglong)uVar16 * 2 < 0x20) {
                  uVar21 = 0;
                }
                else {
                  uVar25 = 0;
                  uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
                  do {
                    uVar14 = *(undefined4 *)(uVar25 + 0x2ac334fcc70);
                    uVar17 = *(undefined4 *)(uVar25 + 0x2ac334fcc74);
                    uVar7 = *(undefined4 *)(uVar25 + 0x2ac334fcc78);
                    puVar3 = (undefined4 *)(lVar1 + uVar25);
                    *puVar3 = *(undefined4 *)(&DAT_2ac334fcc6c + uVar25);
                    puVar3[1] = uVar14;
                    puVar3[2] = uVar17;
                    puVar3[3] = uVar7;
                    uVar25 = uVar25 + 0x10;
                  } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
                  if (uVar21 == uVar23) goto LAB_2ac334d9ae2;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar21 * 2) =
                       *(undefined2 *)(&DAT_2ac334fcc6c + uVar21 * 2);
                  uVar21 = uVar21 + 1;
                } while (uVar23 != uVar21);
              }
LAB_2ac334d9ae2:
              *(uint *)(local_cc + -4) = uVar15;
              *(undefined2 *)(local_cc + (ulonglong)uVar15 * 2) = 0;
              goto LAB_2ac334d9af7;
            }
            goto LAB_2ac334da0be;
          }
LAB_2ac334d9af7:
          lVar1 = *(longlong *)(&DAT_2ac33504384 + lVar12 * 0xc);
          uVar14 = 0xfa9;
          if ((lVar1 == 0) || (lVar1 == 0xc)) {
LAB_2ac334d9b5b:
            if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc))
            {
              _DAT_2ac33505c10 = 0xfa9;
            }
            else {
              _DAT_2ac33505c10 = uVar14;
              if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
                 (cVar11 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar10 = _DAT_2ac33505c40,
                 cVar11 != '\0')) {
                *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
                *puVar10 = 0;
              }
            }
          }
          else {
            iVar5 = *(int *)(lVar1 + -4);
            if (iVar5 == 0) {
              uVar14 = 0x13ab;
              goto LAB_2ac334d9b5b;
            }
            iVar20 = 0x19;
            if (iVar5 < 0x19) {
              _DAT_2ac33505c10 = 0x13ab;
              iVar20 = iVar5;
            }
            FUN_2ac334d0280(0x2ac33505c3c,lVar1,iVar20);
          }
          FUN_2ac334d0af0(&local_88,0x2ac33505c3c,1,0x2ac334ff6e0);
          FUN_2ac334d0af0(&local_b0,&local_d0,0);
          lVar1 = local_84;
          if (local_84 == 0) {
LAB_2ac334d9d17:
            FUN_2ac334d0af0(&local_a0,&local_b0,0,0x2ac334ff700);
            goto LAB_2ac334d9d33;
          }
          uVar26 = *(uint *)(local_84 + -4);
          uVar23 = (ulonglong)uVar26;
          if ((uVar23 == 0) && (local_ac != 0)) goto LAB_2ac334d9d17;
          if (local_ac == 0) {
            uVar16 = 0;
            uVar15 = uVar26;
          }
          else {
            uVar16 = *(uint *)(local_ac + -4);
            uVar15 = uVar26 + uVar16;
          }
          cVar11 = FUN_2ac334d0100(&local_b0);
          if (cVar11 != '\0') {
            if (uVar23 != 0) {
              lVar2 = local_ac + (ulonglong)uVar16 * 2;
              if (uVar26 < 8) {
                uVar21 = 0;
              }
              else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
                uVar21 = 0;
              }
              else {
                uVar25 = 0;
                uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  puVar3 = (undefined4 *)(lVar1 + uVar25);
                  uVar14 = puVar3[1];
                  uVar17 = puVar3[2];
                  uVar7 = puVar3[3];
                  puVar4 = (undefined4 *)(lVar2 + uVar25);
                  *puVar4 = *puVar3;
                  puVar4[1] = uVar14;
                  puVar4[2] = uVar17;
                  puVar4[3] = uVar7;
                  uVar25 = uVar25 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
                if (uVar21 == uVar23) goto LAB_2ac334d9d02;
              }
              do {
                *(undefined2 *)(lVar2 + uVar21 * 2) = *(undefined2 *)(lVar1 + uVar21 * 2);
                uVar21 = uVar21 + 1;
              } while (uVar23 != uVar21);
            }
LAB_2ac334d9d02:
            *(uint *)(local_ac + -4) = uVar15;
            *(undefined2 *)(local_ac + (ulonglong)uVar15 * 2) = 0;
            goto LAB_2ac334d9d17;
          }
          goto LAB_2ac334da0de;
        }
        uVar26 = *(uint *)(lVar1 + -4);
        uVar23 = (ulonglong)uVar26;
        if ((uVar23 == 0) && (local_fc != 0)) goto LAB_2ac334d99c3;
        if (local_fc == 0) {
          uVar16 = 0;
          uVar15 = uVar26;
        }
        else {
          uVar16 = *(uint *)(local_fc + -4);
          uVar15 = uVar26 + uVar16;
        }
        cVar11 = FUN_2ac334d0100(&local_100);
        if (cVar11 != '\0') {
          if (uVar23 != 0) {
            lVar2 = local_fc + (ulonglong)uVar16 * 2;
            if (uVar26 < 8) {
              uVar21 = 0;
            }
            else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
              uVar21 = 0;
            }
            else {
              uVar25 = 0;
              uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar1 + uVar25);
                uVar14 = puVar3[1];
                uVar17 = puVar3[2];
                uVar7 = puVar3[3];
                puVar4 = (undefined4 *)(lVar2 + uVar25);
                *puVar4 = *puVar3;
                puVar4[1] = uVar14;
                puVar4[2] = uVar17;
                puVar4[3] = uVar7;
                uVar25 = uVar25 + 0x10;
              } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
              if (uVar21 == uVar23) goto LAB_2ac334d99a2;
            }
            do {
              *(undefined2 *)(lVar2 + uVar21 * 2) = *(undefined2 *)(lVar1 + uVar21 * 2);
              uVar21 = uVar21 + 1;
            } while (uVar23 != uVar21);
          }
LAB_2ac334d99a2:
          *(uint *)(local_fc + -4) = uVar15;
          *(undefined2 *)(local_fc + (ulonglong)uVar15 * 2) = 0;
          goto LAB_2ac334d99c3;
        }
LAB_2ac334da0fe:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x460bc5000001f9);
        goto LAB_2ac334da11e;
      }
LAB_2ac334d9d33:
      FUN_2ac334d0af0(&local_e0,0x2ac334f9160,0,0x2ac334ff710);
      FUN_2ac334d0af0(&local_f0,&local_c0,0,0x2ac334ff720);
      uVar26 = _DAT_2ac334f9438;
      uVar23 = (ulonglong)_DAT_2ac334f9438;
      if ((uVar23 != 0) || (local_ec == 0)) {
        if (local_ec == 0) {
          uVar16 = 0;
          uVar15 = _DAT_2ac334f9438;
        }
        else {
          uVar16 = *(uint *)(local_ec + -4);
          uVar15 = _DAT_2ac334f9438 + uVar16;
        }
        uVar19 = 0x104;
        if ((0x103 < uVar15) &&
           ((0x7ffffffd < uVar15 || (uVar19 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar19)))) {
          uVar19 = 0x7ffffffe;
        }
        cVar11 = FUN_2ac334d0100(&local_f0,uVar19);
        if (cVar11 != '\0') {
          if (uVar23 != 0) {
            lVar1 = local_ec + (ulonglong)uVar16 * 2;
            if (uVar26 < 8) {
              uVar21 = 0;
            }
            else if (local_ec + -0x2ac334f943c + (ulonglong)uVar16 * 2 < 0x20) {
              uVar21 = 0;
            }
            else {
              uVar25 = 0;
              uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
              do {
                uVar14 = *(undefined4 *)(uVar25 + 0x2ac334f9440);
                uVar17 = *(undefined4 *)(uVar25 + 0x2ac334f9444);
                uVar7 = *(undefined4 *)(uVar25 + 0x2ac334f9448);
                puVar3 = (undefined4 *)(lVar1 + uVar25);
                *puVar3 = *(undefined4 *)(&DAT_2ac334f943c + uVar25);
                puVar3[1] = uVar14;
                puVar3[2] = uVar17;
                puVar3[3] = uVar7;
                uVar25 = uVar25 + 0x10;
              } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
              if (uVar21 == uVar23) goto LAB_2ac334d9e72;
            }
            do {
              *(undefined2 *)(lVar1 + uVar21 * 2) = *(undefined2 *)(&DAT_2ac334f943c + uVar21 * 2);
              uVar21 = uVar21 + 1;
            } while (uVar23 != uVar21);
          }
LAB_2ac334d9e72:
          *(uint *)(local_ec + -4) = uVar15;
          *(undefined2 *)(local_ec + (ulonglong)uVar15 * 2) = 0;
          goto LAB_2ac334d9e87;
        }
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1d0bc9000001f9);
LAB_2ac334da07e:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x290bc9000001f9);
LAB_2ac334da09e:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x400bc5000001f9);
LAB_2ac334da0be:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x190bc6000001f9);
LAB_2ac334da0de:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1e0bc6000001f9);
        goto LAB_2ac334da0fe;
      }
LAB_2ac334d9e87:
      (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,lVar12,0,0x20);
      FUN_2ac334d0af0(&local_100,0x2ac33505c3c,1,0x2ac334ff730);
      FUN_2ac334d0af0(&local_d0,&local_f0,0);
      lVar1 = local_fc;
      if (local_fc != 0) {
        uVar26 = *(uint *)(local_fc + -4);
        uVar23 = (ulonglong)uVar26;
        if ((uVar23 != 0) || (local_cc == 0)) {
          if (local_cc == 0) {
            uVar16 = 0;
            uVar15 = uVar26;
          }
          else {
            uVar16 = *(uint *)(local_cc + -4);
            uVar15 = uVar26 + uVar16;
          }
          cVar11 = FUN_2ac334d0100(&local_d0);
          if (cVar11 == '\0') goto LAB_2ac334da07e;
          if (uVar23 != 0) {
            lVar2 = local_cc + (ulonglong)uVar16 * 2;
            if (uVar26 < 8) {
              uVar21 = 0;
            }
            else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
              uVar21 = 0;
            }
            else {
              uVar25 = 0;
              uVar21 = (ulonglong)(uVar26 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar1 + uVar25);
                uVar14 = puVar3[1];
                uVar17 = puVar3[2];
                uVar7 = puVar3[3];
                puVar4 = (undefined4 *)(lVar2 + uVar25);
                *puVar4 = *puVar3;
                puVar4[1] = uVar14;
                puVar4[2] = uVar17;
                puVar4[3] = uVar7;
                uVar25 = uVar25 + 0x10;
              } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar25);
              if (uVar21 == uVar23) goto LAB_2ac334d9670;
            }
            do {
              *(undefined2 *)(lVar2 + uVar21 * 2) = *(undefined2 *)(lVar1 + uVar21 * 2);
              uVar21 = uVar21 + 1;
            } while (uVar23 != uVar21);
          }
LAB_2ac334d9670:
          *(uint *)(local_cc + -4) = uVar15;
          *(undefined2 *)(local_cc + (ulonglong)uVar15 * 2) = 0;
        }
      }
      FUN_2ac334f7ba0(&local_d0,&local_a0,0xffffffff,&local_e0);
      FUN_2ac334d00a0(&local_a0);
      lVar12 = lVar12 + 1;
    } while (lVar12 != 4);
  }
  (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
  FUN_2ac334d00a0(&local_c0);
LAB_2ac334da007:
  FUN_2ac334d00a0(&local_e0);
  FUN_2ac334d00a0(&local_f0);
  FUN_2ac334d00a0(&local_100);
  FUN_2ac334d00a0(&local_d0);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_b0);
  return;
}



/* Address: 2ac334e3480 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334e3480(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  undefined1 *puVar7;
  bool bVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char cVar13;
  int iVar14;
  longlong lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  int iVar18;
  uint uVar19;
  ulonglong uVar20;
  uint uVar21;
  longlong lVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  uint uVar25;
  uint local_cc;
  undefined4 local_c8;
  longlong local_c4;
  undefined4 local_b8;
  longlong local_b4;
  longlong local_a8;
  undefined4 local_a0;
  longlong local_9c;
  undefined4 local_94;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  longlong local_7c;
  longlong local_70;
  ulonglong local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_b8 = 0;
  local_a0 = 0;
  local_80 = 0;
  local_c8 = 0;
  local_90 = 0;
  local_b4 = 0;
  local_9c = 0;
  local_7c = 0;
  local_c4 = 0;
  local_8c = 0;
  iVar14 = (*(code *)0x7ff63a107da0)(0x2ac301f9168);
  if (iVar14 + -1 < 0) {
    local_cc = 0;
  }
  else {
    lVar22 = (longlong)param_2;
    local_cc = 0;
    iVar14 = iVar14 + -1;
    local_a8 = lVar22;
    local_70 = param_1;
    do {
      lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
      if (lVar15 == 0) {
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x9058a000001fa);
LAB_2ac334e3d7d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xc058b000001fa);
LAB_2ac334e3d9d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x10058c000001fa);
LAB_2ac334e3dbd:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x160590000001fa);
LAB_2ac334e3ddd:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2f0590000001fa);
LAB_2ac334e3dfd:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x21058f000001fa);
LAB_2ac334e3e1d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4b0591000001fa);
LAB_2ac334e3e3d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x210591000001f9);
LAB_2ac334e3e5d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5f0591000001f9);
LAB_2ac334e3e7d:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3a0591000001f9);
        pcVar9 = (code *)swi(3);
        uVar24 = (*pcVar9)();
        return uVar24;
      }
      lVar15 = (*(code *)0x7ff63a107df0)(0x2ac301f9168,iVar14);
      if (lVar15 != 0) {
        lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar15 == 0) goto LAB_2ac334e3d7d;
        lVar15 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0xc);
        if (lVar15 != lVar22) goto LAB_2ac334e3592;
        lVar22 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar22 == 0) goto LAB_2ac334e3d9d;
        local_50 = 0;
        local_60 = 0;
        local_4c = 0;
        local_5c = 0;
        (*(code *)0x7ff63a108010)(0x2ac301f9168,0);
        FUN_2ac334d0af0(&local_50,0x2ac33505c3c,1,0x2ac334fd248);
        FUN_2ac334d0af0(&local_60,&local_50,0,0x2ac334fd258);
        FUN_2ac334d0af0(0x2ac33505c3c,&local_60,1,0x2ac334fd268);
        FUN_2ac334d00a0(&local_60);
        FUN_2ac334d00a0(&local_50);
        FUN_2ac334d0af0(&local_90,0x2ac33505c3c,1);
        lVar22 = local_a8;
        if (local_8c != _DAT_2ac33505c2c) {
          if ((local_8c != 0) && (_DAT_2ac33505c2c != 0)) {
            uVar6 = *(uint *)(local_8c + -4);
            uVar25 = *(uint *)(_DAT_2ac33505c2c + -4);
            uVar19 = uVar25;
            if (uVar6 < uVar25) {
              uVar19 = uVar6;
            }
            iVar18 = uVar6 - uVar25;
            if (uVar19 != 0) {
              uVar24 = 1;
              do {
                uVar4 = *(ushort *)(local_8c + -2 + uVar24 * 2);
                uVar5 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar24 * 2);
                if (uVar19 <= uVar24) break;
                uVar24 = uVar24 + 1;
              } while (uVar4 == uVar5);
              if (uVar4 != uVar5) {
                iVar18 = (uint)uVar4 - (uint)uVar5;
              }
            }
            if (iVar18 == 0) goto LAB_2ac334e37f0;
          }
          puVar7 = *(undefined1 **)(local_70 + 4);
          if (puVar7 != &DAT_2ac334f9158) {
            if (puVar7 != (undefined1 *)0x0) {
              uVar6 = *(uint *)(puVar7 + -4);
              uVar25 = _DAT_2ac334f9154;
              if (uVar6 < _DAT_2ac334f9154) {
                uVar25 = uVar6;
              }
              iVar18 = uVar6 - _DAT_2ac334f9154;
              if (uVar25 != 0) {
                uVar24 = 0;
                do {
                  uVar4 = *(ushort *)(puVar7 + uVar24 * 2);
                  uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar24 * 2);
                  uVar24 = uVar24 + 1;
                  if (uVar25 <= uVar24) break;
                } while (uVar4 == uVar5);
                if (uVar4 != uVar5) {
                  iVar18 = (uint)uVar4 - (uint)uVar5;
                }
              }
              if (iVar18 == 0) goto LAB_2ac334e37f0;
            }
            goto LAB_2ac334e3592;
          }
        }
LAB_2ac334e37f0:
        _DAT_2ac33505c10 = 0;
        _DAT_2ac33505c80 = 0;
        DAT_2ac33505c88 = 0;
        lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar15 == 0) goto LAB_2ac334e3dfd;
        uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
        lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar15 == 0) goto LAB_2ac334e3ddd;
        uVar17 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
        lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
        if (lVar15 == 0) goto LAB_2ac334e3dbd;
        cVar13 = FUN_2ac334f0d20(lVar15,uVar17);
        if (cVar13 != '\0') {
          local_cc = local_cc + 1;
          FUN_2ac334f48b0(uVar16);
          goto LAB_2ac334e3592;
        }
        local_94 = _DAT_2ac33505c10;
        FUN_2ac334d0af0(&local_c8,local_70,0,0x2ac334fe240);
        uVar6 = _DAT_2ac334fb548;
        uVar24 = (ulonglong)_DAT_2ac334fb548;
        if ((uVar24 != 0) || (local_c4 == 0)) {
          if (local_c4 == 0) {
            uVar25 = 0;
          }
          else {
            uVar25 = *(uint *)(local_c4 + -4);
          }
          uVar21 = _DAT_2ac334fb548 + uVar25;
          uVar19 = 0x104;
          if ((0x103 < uVar21) &&
             ((0x7ffffffd < uVar21 || (uVar19 = (uVar21 >> 2) + uVar21, 0x7ffffffd < uVar19)))) {
            uVar19 = 0x7ffffffe;
          }
          cVar13 = FUN_2ac334d0100(&local_c8,uVar19);
          if (cVar13 != '\0') {
            if (uVar24 != 0) {
              lVar15 = local_c4 + (ulonglong)uVar25 * 2;
              if (uVar6 < 8) {
                uVar20 = 0;
              }
              else if (local_c4 + -0x2ac334fb54c + (ulonglong)uVar25 * 2 < 0x20) {
                uVar20 = 0;
              }
              else {
                uVar23 = 0;
                uVar20 = (ulonglong)(uVar6 & 0xfffffff8);
                do {
                  uVar10 = *(undefined4 *)(uVar23 + 0x2ac334fb550);
                  uVar11 = *(undefined4 *)(uVar23 + 0x2ac334fb554);
                  uVar12 = *(undefined4 *)(uVar23 + 0x2ac334fb558);
                  puVar3 = (undefined4 *)(lVar15 + uVar23);
                  *puVar3 = *(undefined4 *)(&DAT_2ac334fb54c + uVar23);
                  puVar3[1] = uVar10;
                  puVar3[2] = uVar11;
                  puVar3[3] = uVar12;
                  uVar23 = uVar23 + 0x10;
                } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar23);
                if (uVar20 == uVar24) goto LAB_2ac334e39f3;
              }
              do {
                *(undefined2 *)(lVar15 + uVar20 * 2) =
                     *(undefined2 *)(&DAT_2ac334fb54c + uVar20 * 2);
                uVar20 = uVar20 + 1;
              } while (uVar24 != uVar20);
            }
LAB_2ac334e39f3:
            *(uint *)(local_c4 + -4) = uVar21;
            *(undefined2 *)(local_c4 + (ulonglong)uVar21 * 2) = 0;
            goto LAB_2ac334e3a0d;
          }
          goto LAB_2ac334e3e3d;
        }
LAB_2ac334e3a0d:
        lVar15 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar15 == 0) goto LAB_2ac334e3e1d;
        uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
        (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,uVar16,0,0x20);
        FUN_2ac334d0af0(&local_80,0x2ac33505c3c,1,0x2ac334fe250);
        FUN_2ac334d0af0(&local_a0,&local_c8,0);
        lVar15 = local_7c;
        if (local_7c != 0) {
          uVar6 = *(uint *)(local_7c + -4);
          uVar24 = (ulonglong)uVar6;
          if ((uVar24 != 0) || (local_9c == 0)) {
            if (local_9c == 0) {
              local_68 = 0;
            }
            else {
              local_68 = (ulonglong)*(uint *)(local_9c + -4);
            }
            uVar25 = uVar6 + (int)local_68;
            cVar13 = FUN_2ac334d0100(&local_a0);
            if (cVar13 == '\0') goto LAB_2ac334e3e7d;
            if (uVar24 != 0) {
              lVar1 = local_9c + (local_68 & 0xffffffff) * 2;
              if (uVar6 < 8) {
                uVar20 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar15) < 0x20) {
                uVar20 = 0;
              }
              else {
                uVar23 = 0;
                uVar20 = (ulonglong)(uVar6 & 0xfffffff8);
                do {
                  puVar3 = (undefined4 *)(lVar15 + uVar23);
                  uVar10 = puVar3[1];
                  uVar11 = puVar3[2];
                  uVar12 = puVar3[3];
                  puVar2 = (undefined4 *)(lVar1 + uVar23);
                  *puVar2 = *puVar3;
                  puVar2[1] = uVar10;
                  puVar2[2] = uVar11;
                  puVar2[3] = uVar12;
                  uVar23 = uVar23 + 0x10;
                } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar23);
                if (uVar20 == uVar24) goto LAB_2ac334e3b92;
              }
              do {
                *(undefined2 *)(lVar1 + uVar20 * 2) = *(undefined2 *)(lVar15 + uVar20 * 2);
                uVar20 = uVar20 + 1;
              } while (uVar24 != uVar20);
            }
LAB_2ac334e3b92:
            *(uint *)(local_9c + -4) = uVar25;
            *(undefined2 *)(local_9c + (ulonglong)uVar25 * 2) = 0;
          }
        }
        FUN_2ac334d0af0(&local_b8,&local_a0,0,0x2ac334fe270);
        uVar6 = _DAT_2ac334fb588;
        uVar24 = (ulonglong)_DAT_2ac334fb588;
        if ((uVar24 != 0) || (local_b4 == 0)) {
          if (local_b4 == 0) {
            uVar25 = 0;
          }
          else {
            uVar25 = *(uint *)(local_b4 + -4);
          }
          uVar21 = _DAT_2ac334fb588 + uVar25;
          uVar19 = 0x104;
          if ((0x103 < uVar21) &&
             ((0x7ffffffd < uVar21 || (uVar19 = (uVar21 >> 2) + uVar21, 0x7ffffffd < uVar19)))) {
            uVar19 = 0x7ffffffe;
          }
          cVar13 = FUN_2ac334d0100(&local_b8,uVar19);
          if (cVar13 == '\0') goto LAB_2ac334e3e5d;
          if (uVar24 != 0) {
            lVar15 = local_b4 + (ulonglong)uVar25 * 2;
            if (uVar6 < 8) {
              uVar20 = 0;
            }
            else if (local_b4 + -0x2ac334fb58c + (ulonglong)uVar25 * 2 < 0x20) {
              uVar20 = 0;
            }
            else {
              uVar23 = 0;
              uVar20 = (ulonglong)(uVar6 & 0xfffffff8);
              do {
                uVar10 = *(undefined4 *)(uVar23 + 0x2ac334fb590);
                uVar11 = *(undefined4 *)(uVar23 + 0x2ac334fb594);
                uVar12 = *(undefined4 *)(uVar23 + 0x2ac334fb598);
                puVar3 = (undefined4 *)(lVar15 + uVar23);
                *puVar3 = *(undefined4 *)(&DAT_2ac334fb58c + uVar23);
                puVar3[1] = uVar10;
                puVar3[2] = uVar11;
                puVar3[3] = uVar12;
                uVar23 = uVar23 + 0x10;
              } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar23);
              if (uVar20 == uVar24) goto LAB_2ac334e3cc3;
            }
            do {
              *(undefined2 *)(lVar15 + uVar20 * 2) = *(undefined2 *)(&DAT_2ac334fb58c + uVar20 * 2);
              uVar20 = uVar20 + 1;
            } while (uVar24 != uVar20);
          }
LAB_2ac334e3cc3:
          *(uint *)(local_b4 + -4) = uVar21;
          *(undefined2 *)(local_b4 + (ulonglong)uVar21 * 2) = 0;
        }
        (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,2,0x590008,&local_b8,0x520004,local_94);
      }
LAB_2ac334e3592:
      bVar8 = 0 < iVar14;
      iVar14 = iVar14 + -1;
    } while (bVar8);
  }
  FUN_2ac334d00a0(&local_90);
  FUN_2ac334d00a0(&local_c8);
  FUN_2ac334d00a0(&local_80);
  FUN_2ac334d00a0(&local_a0);
  FUN_2ac334d00a0(&local_b8);
  return (ulonglong)local_cc;
}



/* Address: 2ac334e3ea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334e3ea0(longlong param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 *puVar4;
  bool bVar5;
  code *pcVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong uVar14;
  uint local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined1 local_b8 [120];
  
  local_e8 = 0;
  local_f8 = 0;
  local_e4 = 0;
  local_f4 = 0;
  local_c8 = param_1;
  iVar9 = (*(code *)0x7ff63a1081a0)(0x2ac301f9168);
  if (iVar9 + -1 < 0) {
    local_104 = 0;
  }
  else {
    local_c0 = (longlong)param_3;
    local_104 = 0;
    iVar9 = iVar9 + -1;
    do {
      lVar11 = (*(code *)0x7ff63a1081f0)(0x2ac301f9168,iVar9);
      if ((lVar11 == 0) ||
         (lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,0xf), lVar12 != param_2))
      goto LAB_2ac334e4020;
      (*(code *)0x7ff63a1083a0)(0x2ac301f9168,0);
      FUN_2ac334d0af0(&local_f8,0x2ac33505c3c,1);
      if (local_f4 == _DAT_2ac33505c2c) {
LAB_2ac334e4190:
        if (((((param_3 < 0) && (lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,4), 1 < lVar12))
             && (lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,4), lVar12 < 8)) ||
            (lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,4), lVar12 == local_c0)) &&
           ((lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,0x17), lVar12 < 4 &&
            (lVar12 = (*(code *)0x7ff63a108310)(0x2ac301f9168,0xe), lVar12 == 1)))) {
          _DAT_2ac33505c10 = 0;
          _DAT_2ac33505c80 = 0;
          DAT_2ac33505c88 = 0;
          (*(code *)0x7ff63a108280)(0x2ac301f9168,9);
          iVar10 = (*(code *)0x7ff63a108310)(0x2ac301f9168,4);
          (*(code *)0x7ff63a1083a0)(0x2ac301f9168,0);
          FUN_2ac334d0af0(&local_e8,0x2ac33505c3c,1,0x2ac334fe290);
          (*(code *)0x7ff63a0f2c10)(0x2ac301f9168,&local_e8,local_b8);
          (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_e8,0x10);
          (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
          if (iVar10 - 2U < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334e4325 */
                    /* WARNING: Treating indirect jump as call */
            uVar14 = (**(code **)((ulonglong)(iVar10 - 2U) * 8 + 0x2ac334f8b60))();
            return uVar14;
          }
          lVar12 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
          if (lVar12 == 0) {
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1c05f4000001fa);
            pcVar6 = (code *)swi(3);
            uVar14 = (*pcVar6)();
            return uVar14;
          }
          if (_DAT_2ac33505c14 == 0) {
            local_d0 = lVar12 + 0x20;
            *(undefined4 *)(lVar12 + 0x30) = 0;
            *(undefined8 *)(lVar12 + 0x28) = 0;
            *(undefined8 *)(lVar12 + 0x20) = 0;
            FUN_2ac334d00a0(lVar12 + 0x34);
            *(undefined4 *)(lVar12 + 0x80) = 0;
            *(undefined8 *)(lVar12 + 0x78) = 0;
            *(undefined8 *)(lVar12 + 0x70) = 0;
            *(undefined8 *)(lVar12 + 0x68) = 0;
            *(undefined8 *)(lVar12 + 0x60) = 0;
            *(undefined8 *)(lVar12 + 0x58) = 0;
            *(undefined8 *)(lVar12 + 0x50) = 0;
            *(undefined8 *)(lVar12 + 0x48) = 0;
            *(undefined8 *)(lVar12 + 0x40) = 0;
            FUN_2ac334d00a0(lVar12 + 0x84);
            local_d8 = lVar12 + 0x110;
            (*(code *)0x7ff63a3fad20)(lVar12 + 0x90,0,0xb4);
            FUN_2ac334d00a0(lVar12 + 0x144);
            (*(code *)0x7ff63a3fad20)(lVar12 + 0x150,0,0xb8);
            FUN_2ac334d00a0(lVar12 + 0x208);
            *(undefined8 *)(lVar12 + 0x28c) = 0;
            *(undefined8 *)(lVar12 + 0x284) = 0;
            *(undefined8 *)(lVar12 + 0x27c) = 0;
            *(undefined8 *)(lVar12 + 0x274) = 0;
            *(undefined8 *)(lVar12 + 0x26c) = 0;
            *(undefined8 *)(lVar12 + 0x264) = 0;
            *(undefined8 *)(lVar12 + 0x25c) = 0;
            *(undefined8 *)(lVar12 + 0x254) = 0;
            *(undefined8 *)(lVar12 + 0x24c) = 0;
            *(undefined8 *)(lVar12 + 0x244) = 0;
            *(undefined8 *)(lVar12 + 0x23c) = 0;
            *(undefined8 *)(lVar12 + 0x234) = 0;
            *(undefined8 *)(lVar12 + 0x22c) = 0;
            *(undefined8 *)(lVar12 + 0x224) = 0;
            *(undefined8 *)(lVar12 + 0x21c) = 0;
            *(undefined8 *)(lVar12 + 0x214) = 0;
            *(undefined4 *)(lVar12 + 0x20) = 8;
            *(undefined8 *)(lVar12 + 0x24) = *(undefined8 *)(lVar12 + 0x295);
            *(longlong *)(lVar12 + 0x2c) = lVar11;
            cVar8 = FUN_2ac334d0e40(lVar12,local_d0,local_d8);
            if (cVar8 != '\0') {
              local_104 = local_104 + 1;
            }
          }
          else {
            (*(code *)0x7ff63a0e49f0)
                      (0x2ac301f9168,0xd,2,0x590008,0x2ac334fb310,0x590008,0x2ac334fa358);
            *(undefined4 *)(lVar12 + 0x110) = 0x272b;
          }
        }
      }
      else {
        if ((local_f4 != 0) && (_DAT_2ac33505c2c != 0)) {
          uVar3 = *(uint *)(local_f4 + -4);
          uVar13 = *(uint *)(_DAT_2ac33505c2c + -4);
          uVar7 = uVar13;
          if (uVar3 < uVar13) {
            uVar7 = uVar3;
          }
          iVar10 = uVar3 - uVar13;
          if (uVar7 != 0) {
            uVar14 = 1;
            do {
              uVar1 = *(ushort *)(local_f4 + -2 + uVar14 * 2);
              uVar2 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar14 * 2);
              if (uVar7 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar10 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar10 == 0) goto LAB_2ac334e4190;
        }
        puVar4 = *(undefined1 **)(local_c8 + 4);
        if (puVar4 == &DAT_2ac334f9158) goto LAB_2ac334e4190;
        if (puVar4 != (undefined1 *)0x0) {
          uVar3 = *(uint *)(puVar4 + -4);
          uVar13 = _DAT_2ac334f9154;
          if (uVar3 < _DAT_2ac334f9154) {
            uVar13 = uVar3;
          }
          iVar10 = uVar3 - _DAT_2ac334f9154;
          if (uVar13 != 0) {
            uVar14 = 0;
            do {
              uVar1 = *(ushort *)(puVar4 + uVar14 * 2);
              uVar2 = *(ushort *)(&DAT_2ac334f9158 + uVar14 * 2);
              uVar14 = uVar14 + 1;
              if (uVar13 <= uVar14) break;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar10 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar10 == 0) goto LAB_2ac334e4190;
        }
      }
LAB_2ac334e4020:
      bVar5 = 0 < iVar9;
      iVar9 = iVar9 + -1;
    } while (bVar5);
  }
  FUN_2ac334d00a0(&local_f8);
  FUN_2ac334d00a0(&local_e8);
  return (ulonglong)local_104;
}



/* Address: 2ac334e4600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334e4600(void)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined4 local_138;
  longlong local_134;
  undefined4 local_128;
  longlong local_124;
  undefined4 local_11c;
  undefined4 local_118;
  longlong local_114;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  longlong local_c4;
  undefined8 local_b8;
  undefined8 local_b0 [14];
  
  local_f8 = 0;
  local_c8 = 0;
  local_118 = 0;
  local_d8 = 0;
  local_138 = 0;
  local_128 = 0;
  local_e8 = 0;
  local_108 = 0;
  local_f4 = 0;
  local_c4 = 0;
  local_114 = 0;
  local_d4 = 0;
  local_134 = 0;
  local_124 = 0;
  local_e4 = 0;
  local_104 = 0;
  lVar10 = (*(code *)0x7ff63a101d80)(0x2ac301f9168,0);
  uVar7 = 0;
  if (DAT_2ac33500044 != '\0') {
    lVar12 = 0x3840;
    if (DAT_2ac3350591c == '\0') {
      lVar12 = 0;
    }
    if (lVar12 + _DAT_2ac33505968 <= lVar10) {
      _DAT_2ac33505968 = lVar10;
      FUN_2ac334d47c0();
      DAT_2ac335001c0 = 0;
      uVar7 = DAT_2ac335001c0;
      if (DAT_2ac33500044 == '\0') goto LAB_2ac334e4799;
    }
    DAT_2ac335001c0 = 0;
    FUN_2ac334d5c00();
    if ((DAT_2ac33500044 != '\0') && (_DAT_2ac33506010 != 0 || _DAT_2ac33506008 != 0)) {
      _DAT_2ac33505920 = _DAT_2ac33506010 + 1;
      lVar10 = 0;
      do {
        if (_DAT_2ac33505c14 != 0) break;
        dVar1 = *(double *)(&DAT_2ac33504650 + lVar10);
        dVar2 = *(double *)(lVar10 + 0x2ac33504c90);
        if (((dVar2 == _DAT_2ac334f8b80) && (!NAN(dVar2) && !NAN(_DAT_2ac334f8b80))) &&
           (uVar7 = 1, (double)((ulonglong)dVar1 & _DAT_2ac334f8b90) <= (double)_DAT_2ac33506010))
        goto LAB_2ac334e4799;
        uVar7 = 0;
        if (((dVar1 == _DAT_2ac334f8ba0) && (!NAN(dVar1) && !NAN(_DAT_2ac334f8ba0))) ||
           ((double)_DAT_2ac33506008 < dVar1)) goto LAB_2ac334e4799;
        if (0.0 <= dVar1) {
          bVar3 = (double)_DAT_2ac33506008 < dVar1;
        }
        else {
          bVar3 = (double)_DAT_2ac33506010 < (double)((ulonglong)dVar1 & _DAT_2ac334f8b90);
        }
        uVar7 = 1;
        if ((dVar2 <= _DAT_2ac334f8ba8 && _DAT_2ac334f8bb0 <= dVar2) && !bVar3)
        goto LAB_2ac334e4799;
        lVar10 = lVar10 + 8;
      } while (lVar10 != 0x640);
    }
    uVar7 = 0;
  }
LAB_2ac334e4799:
  DAT_2ac335001c0 = uVar7;
  dVar1 = _DAT_2ac33505df8;
  local_b0[0] = 0;
  local_b8 = 0;
  local_11c = 0;
  if (((DAT_2ac33500054 != '\0') || (_DAT_2ac33505df8 != 0.0)) || (NAN(_DAT_2ac33505df8))) {
    FUN_2ac334d8450(local_b0,&local_b8,&local_11c);
  }
  if ((dVar1 == 0.0) && (!NAN(dVar1))) goto LAB_2ac334e50bf;
  local_108 = 0;
  local_104 = 0;
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar1,2);
  FUN_2ac334d0af0(&local_e8,0x2ac33505c3c,1,0x2ac334fde18);
  (*(code *)0x7ff63a0c7410)(0x2ac301f9168,0x24);
  FUN_2ac334d0af0(&local_128,0x2ac33505c3c,1,0x2ac334fde28);
  FUN_2ac334d0af0(&local_138,&local_e8,0);
  lVar10 = local_124;
  if (local_124 != 0) {
    uVar15 = *(uint *)(local_124 + -4);
    uVar16 = (ulonglong)uVar15;
    if ((uVar16 == 0) && (local_134 != 0)) goto LAB_2ac334e4b0d;
    if (local_134 == 0) {
      uVar13 = 0;
      uVar14 = uVar15;
    }
    else {
      uVar13 = (ulonglong)*(uint *)(local_134 + -4);
      uVar14 = uVar15 + *(uint *)(local_134 + -4);
    }
    cVar8 = FUN_2ac334d0100(&local_138);
    if (cVar8 != '\0') {
      if (uVar16 != 0) {
        lVar12 = local_134 + uVar13 * 2;
        if (uVar15 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar18 = 0;
          uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
          do {
            uVar5 = ((undefined8 *)(lVar10 + uVar18))[1];
            *(undefined8 *)(lVar12 + uVar18) = *(undefined8 *)(lVar10 + uVar18);
            ((undefined8 *)(lVar12 + uVar18))[1] = uVar5;
            uVar18 = uVar18 + 0x10;
          } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
          if (uVar13 == uVar16) goto LAB_2ac334e4b02;
        }
        do {
          *(undefined2 *)(lVar12 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar16 != uVar13);
      }
LAB_2ac334e4b02:
      *(uint *)(local_134 + -4) = uVar14;
      *(undefined2 *)(local_134 + (ulonglong)uVar14 * 2) = 0;
      goto LAB_2ac334e4b0d;
    }
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e040e000001f9);
LAB_2ac334e518b:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2d0412000001f9);
LAB_2ac334e51ab:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x250412000001f9);
LAB_2ac334e51cb:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3a0412000001f9);
LAB_2ac334e51eb:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x590412000001f9);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
LAB_2ac334e4b0d:
  FUN_2ac334d0af0(&local_108,&local_138,0,0x2ac334fde48);
  uVar6 = _DAT_2ac33505d18;
  if ((dVar1 <= 0.0) && (DAT_2ac33500158 == '\0')) {
    FUN_2ac334d0af0(&local_e8,0x2ac33505c28,1,0x2ac334fde58);
    iVar9 = FUN_2ac334e3480(&local_e8,uVar6);
    if (0 < iVar9) {
      FUN_2ac334d0af0(&local_128,0x2ac334fb350);
      lVar10 = local_104;
      if (local_104 != 0) {
        uVar15 = *(uint *)(local_104 + -4);
        uVar16 = (ulonglong)uVar15;
        if ((uVar16 == 0) && (local_124 != 0)) goto LAB_2ac334e4ca7;
        if (local_124 == 0) {
          uVar14 = 0;
        }
        else {
          uVar14 = *(uint *)(local_124 + -4);
        }
        cVar8 = FUN_2ac334d0100(&local_128);
        if (cVar8 != '\0') {
          if (uVar16 != 0) {
            lVar12 = local_124 + (ulonglong)uVar14 * 2;
            if (uVar15 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar18 = 0;
              uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar5 = ((undefined8 *)(lVar10 + uVar18))[1];
                *(undefined8 *)(lVar12 + uVar18) = *(undefined8 *)(lVar10 + uVar18);
                ((undefined8 *)(lVar12 + uVar18))[1] = uVar5;
                uVar18 = uVar18 + 0x10;
              } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
              if (uVar13 == uVar16) goto LAB_2ac334e4c92;
            }
            do {
              *(undefined2 *)(lVar12 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar16 != uVar13);
          }
LAB_2ac334e4c92:
          *(uint *)(local_124 + -4) = uVar15 + uVar14;
          *(undefined2 *)(local_124 + (ulonglong)(uVar15 + uVar14) * 2) = 0;
          goto LAB_2ac334e4ca7;
        }
        goto LAB_2ac334e51ab;
      }
LAB_2ac334e4ca7:
      uVar15 = 0;
      FUN_2ac334d0af0(&local_138,&local_128,0,0x2ac334fde78);
      uVar14 = _DAT_2ac334fb368;
      uVar16 = (ulonglong)_DAT_2ac334fb368;
      if ((uVar16 != 0) || (local_134 == 0)) {
        if (local_134 != 0) {
          uVar15 = *(uint *)(local_134 + -4);
        }
        uVar17 = _DAT_2ac334fb368 + uVar15;
        uVar11 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar11 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar11)))) {
          uVar11 = 0x7ffffffe;
        }
        cVar8 = FUN_2ac334d0100(&local_138,uVar11);
        if (cVar8 == '\0') goto LAB_2ac334e518b;
        if (uVar16 != 0) {
          lVar10 = local_134 + (ulonglong)uVar15 * 2;
          if (uVar14 < 0x10) {
            uVar13 = 0;
          }
          else if (lVar10 - 0x2ac334fb36cU < 0x20) {
            uVar13 = 0;
          }
          else {
            uVar18 = 0;
            uVar13 = (ulonglong)(uVar14 & 0xfffffff8);
            do {
              uVar5 = *(undefined8 *)(uVar18 + 0x2ac334fb374);
              *(undefined8 *)(lVar10 + uVar18) = *(undefined8 *)(&DAT_2ac334fb36c + uVar18);
              ((undefined8 *)(lVar10 + uVar18))[1] = uVar5;
              uVar18 = uVar18 + 0x10;
            } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
            if (uVar13 == uVar16) goto LAB_2ac334e4dc2;
          }
          do {
            *(undefined2 *)(lVar10 + uVar13 * 2) = *(undefined2 *)(&DAT_2ac334fb36c + uVar13 * 2);
            uVar13 = uVar13 + 1;
          } while (uVar16 != uVar13);
        }
LAB_2ac334e4dc2:
        *(uint *)(local_134 + -4) = uVar17;
        *(undefined2 *)(local_134 + (ulonglong)uVar17 * 2) = 0;
      }
      (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,0,2);
      FUN_2ac334d0af0(&local_d8,0x2ac33505c3c,1,0x2ac334fde88);
      FUN_2ac334d0af0(&local_118,&local_138,0);
      lVar10 = local_d4;
      if (local_d4 != 0) {
        uVar15 = *(uint *)(local_d4 + -4);
        uVar16 = (ulonglong)uVar15;
        if ((uVar16 != 0) || (local_114 == 0)) {
          if (local_114 == 0) {
            uVar14 = 0;
          }
          else {
            uVar14 = *(uint *)(local_114 + -4);
          }
          cVar8 = FUN_2ac334d0100(&local_118);
          if (cVar8 == '\0') goto LAB_2ac334e51cb;
          if (uVar16 != 0) {
            lVar12 = local_114 + (ulonglong)uVar14 * 2;
            if (uVar15 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar18 = 0;
              uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar5 = ((undefined8 *)(lVar10 + uVar18))[1];
                *(undefined8 *)(lVar12 + uVar18) = *(undefined8 *)(lVar10 + uVar18);
                ((undefined8 *)(lVar12 + uVar18))[1] = uVar5;
                uVar18 = uVar18 + 0x10;
              } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
              if (uVar13 == uVar16) goto LAB_2ac334e4f02;
            }
            do {
              *(undefined2 *)(lVar12 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar16 != uVar13);
          }
LAB_2ac334e4f02:
          *(uint *)(local_114 + -4) = uVar15 + uVar14;
          *(undefined2 *)(local_114 + (ulonglong)(uVar15 + uVar14) * 2) = 0;
        }
      }
      (*(code *)0x7ff63a0c7410)(0x2ac301f9168,0x24);
      FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fdea8);
      FUN_2ac334d0af0(&local_f8,&local_118,0);
      lVar10 = local_c4;
      if (local_c4 != 0) {
        uVar15 = *(uint *)(local_c4 + -4);
        uVar16 = (ulonglong)uVar15;
        if ((uVar16 != 0) || (local_f4 == 0)) {
          if (local_f4 == 0) {
            uVar14 = 0;
          }
          else {
            uVar14 = *(uint *)(local_f4 + -4);
          }
          cVar8 = FUN_2ac334d0100(&local_f8);
          if (cVar8 == '\0') goto LAB_2ac334e51eb;
          if (uVar16 != 0) {
            lVar12 = local_f4 + (ulonglong)uVar14 * 2;
            if (uVar15 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar18 = 0;
              uVar13 = (ulonglong)(uVar15 & 0xfffffff8);
              do {
                uVar5 = ((undefined8 *)(lVar10 + uVar18))[1];
                *(undefined8 *)(lVar12 + uVar18) = *(undefined8 *)(lVar10 + uVar18);
                ((undefined8 *)(lVar12 + uVar18))[1] = uVar5;
                uVar18 = uVar18 + 0x10;
              } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar18);
              if (uVar13 == uVar16) goto LAB_2ac334e5052;
            }
            do {
              *(undefined2 *)(lVar12 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar16 != uVar13);
          }
LAB_2ac334e5052:
          *(uint *)(local_f4 + -4) = uVar15 + uVar14;
          *(undefined2 *)(local_f4 + (ulonglong)(uVar15 + uVar14) * 2) = 0;
        }
      }
      (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,&local_f8);
      (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fb3d0);
      DAT_2ac33500158 = '\x01';
    }
  }
  FUN_2ac334d00a0(&local_108);
LAB_2ac334e50bf:
  FUN_2ac334d8a00(local_b0[0],local_b8,local_11c);
  FUN_2ac334d00a0(&local_e8);
  FUN_2ac334d00a0(&local_128);
  FUN_2ac334d00a0(&local_138);
  FUN_2ac334d00a0(&local_d8);
  FUN_2ac334d00a0(&local_118);
  FUN_2ac334d00a0(&local_c8);
  FUN_2ac334d00a0(&local_f8);
  return;
}



/* Address: 2ac334e5210 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ac334e5210(void)

{
  code *pcVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double local_80 [11];
  
  dVar5 = _DAT_2ac33505d40;
  if (_DAT_2ac33505d38 != 0) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x24);
    dVar7 = _DAT_2ac33505c48;
    local_80[0] = 0.0;
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,4);
    (*(code *)0x7ff63a108d40)(0x2ac301f9168,0,0x2ac33505c28,dVar7,_DAT_2ac33505c48,local_80);
    dVar3 = (double)(*(code *)0x7ff63a3dae50)(dVar7);
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x23);
    dVar4 = _DAT_2ac33505c48;
    if ((longlong)_DAT_2ac33505c48 != -0x8000000000000000) {
      dVar4 = (double)(longlong)_DAT_2ac33505c48;
      dVar4 = (double)(longlong)
                      ((_DAT_2ac33505c48 - dVar4) * _DAT_2ac334f8bc0 +
                      *(double *)((ulonglong)(0.0 < _DAT_2ac33505c48) * 8 + 0x2ac334f8bc8)) /
              _DAT_2ac334f8bc0 + dVar4;
    }
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x22);
    dVar6 = _DAT_2ac33505c48;
    if ((longlong)_DAT_2ac33505c48 != -0x8000000000000000) {
      dVar6 = (double)(longlong)_DAT_2ac33505c48;
      dVar6 = (double)(longlong)
                      ((_DAT_2ac33505c48 - dVar6) * _DAT_2ac334f8bc0 +
                      *(double *)((ulonglong)(0.0 < _DAT_2ac33505c48) * 8 + 0x2ac334f8bc8)) /
              _DAT_2ac334f8bc0 + dVar6;
    }
    if (dVar6 <= dVar7) {
      dVar6 = dVar7;
    }
    dVar5 = dVar6;
    if (0.0 < local_80[0]) {
      (*(code *)0x7ff63a0c7370)(0x2ac301f9168,0x25);
      if ((local_80[0] == 0.0) && (!NAN(local_80[0]))) {
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x8207d6000001f7);
        pcVar1 = (code *)swi(3);
        dVar5 = (double)(*pcVar1)();
        return dVar5;
      }
      dVar5 = (dVar7 * (_DAT_2ac33505d48 / _DAT_2ac334f8bd8) * _DAT_2ac33505c48) / local_80[0];
      if ((longlong)dVar5 != -0x8000000000000000) {
        dVar7 = (double)(longlong)dVar5;
        uVar2 = 0xb;
        if ((uint)(int)(dVar3 / _DAT_2ac334f8bb8) < 0xb) {
          uVar2 = (ulonglong)(uint)(int)(dVar3 / _DAT_2ac334f8bb8);
        }
        dVar3 = *(double *)(uVar2 * 8 + 0x2ac334f8f00);
        dVar5 = (double)(longlong)
                        ((dVar5 - dVar7) * dVar3 +
                        *(double *)((ulonglong)(0.0 < dVar5) * 8 + 0x2ac334f8bc8)) / dVar3 + dVar7;
      }
      if (dVar4 <= dVar5) {
        dVar5 = dVar4;
      }
      if (dVar5 <= dVar6) {
        dVar5 = dVar6;
      }
    }
  }
  return dVar5;
}



/* Address: 2ac334e5530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334e5530(double param_1,double param_2)

{
  double dVar1;
  code *pcVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined8 local_180;
  ulonglong local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  undefined4 local_150;
  undefined8 local_148;
  ulonglong local_140;
  undefined8 local_138;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined8 local_120;
  undefined4 local_118;
  undefined8 local_110;
  ulonglong local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  uint uVar7;
  
  iVar3 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
  if (iVar3 == 0) {
    local_d8 = 0x800010058;
    local_d0 = 0;
    local_c8 = 0;
    local_c0 = 0;
    uStack_bc = 0;
    local_b8 = 0;
    uStack_b4 = 0;
    local_b0 = 0;
    local_a8 = 0;
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_d8,_DAT_2ac33500078 - 1,0);
    (*(code *)0x7ff63a0c7470)(0x2ac301f9168,&local_d8,0x2ac335000a0,0,1,_DAT_2ac33500078 - 1);
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_d8,_DAT_2ac33500078,0);
    if ((longlong)(int)_DAT_2ac33500078 - 1U < (local_d0 & 0xffffffff)) {
      param_1 = param_1 - param_2;
      if ((longlong)param_1 != -0x8000000000000000) {
        dVar13 = (double)(longlong)param_1;
        uVar10 = 0xb;
        if (_DAT_2ac33505c20 < 0xb) {
          uVar10 = (ulonglong)_DAT_2ac33505c20;
        }
        dVar14 = *(double *)(uVar10 * 8 + 0x2ac334f8f00);
        param_1 = (double)(longlong)
                          ((param_1 - dVar13) * dVar14 +
                          *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x2ac334f8be0)) / dVar14 +
                  dVar13;
      }
      *(double *)(CONCAT44(local_b8,uStack_bc) + -8 + (longlong)(int)_DAT_2ac33500078 * 8) = param_1
      ;
      (*(code *)0x7ff63a0c7470)(0x2ac301f9168,0x2ac335000a0,&local_d8,0,0,0);
      uVar8 = _DAT_2ac33500078;
      local_180 = 0x800010058;
      local_a0 = 0x800010058;
      local_178 = 0;
      local_170 = 0;
      local_168 = 0;
      uStack_164 = 0;
      local_160 = 0;
      uStack_15c = 0;
      local_158 = 0;
      local_150 = 0;
      local_98 = 0;
      local_90 = 0;
      local_88 = 0;
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      uVar6 = _DAT_2ac33500078;
      if (_DAT_2ac33500078 == 0) {
        uVar6 = _DAT_2ac335000a8;
      }
      uVar16 = 0;
      uVar17 = 0;
      if ((0 < (int)uVar6 && (int)uVar6 <= (int)_DAT_2ac33500078) ||
         ((int)(uVar6 - _DAT_2ac33500078) < 0)) {
LAB_2ac334e5996:
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_a0);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_180);
        _DAT_2ac33500070 = CONCAT44(uVar17,uVar16);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_d8);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_d8);
        goto LAB_2ac334e59e1;
      }
      iVar3 = (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_180,uVar6,0);
      if (iVar3 < 0) goto LAB_2ac334e5996;
      if (0 < (int)uVar8) {
        uVar10 = (ulonglong)_DAT_2ac335000a8;
        iVar3 = 0;
        iVar9 = 1;
        dVar13 = 0.0;
        dVar14 = 0.0;
        do {
          uVar7 = uVar6;
          uVar6 = uVar7 - 1;
          if (uVar10 <= (ulonglong)(longlong)(int)uVar6) goto LAB_2ac334e5d61;
          dVar15 = (double)iVar9;
          iVar3 = iVar3 + iVar9;
          iVar9 = iVar9 + 1;
          dVar1 = *(double *)(_DAT_2ac335000bc + (longlong)(int)uVar6 * 8);
          dVar14 = dVar14 + dVar1;
          dVar13 = dVar13 + dVar15 * dVar1;
        } while (iVar9 <= (int)uVar8);
        if (-1 < (int)uVar6) {
          if (iVar3 == 0) goto LAB_2ac334e5971;
          if (uVar6 < (uint)local_178) {
            uVar10 = (ulonglong)uVar6;
            uVar6 = uVar7 - 2;
            do {
              *(double *)(CONCAT44(local_160,uStack_164) + uVar10 * 8) = dVar13 / (double)iVar3;
              bVar12 = uVar10 == 0;
              uVar10 = uVar10 - 1;
              if (bVar12) goto LAB_2ac334e5982;
              if (_DAT_2ac335000a8 <= uVar6) goto LAB_2ac334e5e01;
              iVar9 = uVar8 + uVar6;
              if ((ulonglong)_DAT_2ac335000a8 <= (ulonglong)(longlong)iVar9) goto LAB_2ac334e5951;
              dVar13 = dVar13 - dVar14;
              uVar6 = uVar6 - 1;
              dVar1 = *(double *)(_DAT_2ac335000bc + uVar10 * 8);
              dVar14 = (dVar14 - *(double *)(_DAT_2ac335000bc + (longlong)iVar9 * 8)) + dVar1;
              dVar13 = dVar13 + dVar1 * (double)(int)uVar8;
            } while (uVar10 < (local_178 & 0xffffffff));
          }
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x180a7c000001f6);
          goto LAB_2ac334e5927;
        }
LAB_2ac334e5982:
        if ((uint)local_178 == 0) goto LAB_2ac334e5e61;
        uVar16 = (undefined4)*(undefined8 *)CONCAT44(local_160,uStack_164);
        uVar17 = (undefined4)((ulonglong)*(undefined8 *)CONCAT44(local_160,uStack_164) >> 0x20);
        goto LAB_2ac334e5996;
      }
LAB_2ac334e5927:
      if ((int)uVar6 < 0) goto LAB_2ac334e5982;
      uVar10 = (ulonglong)_DAT_2ac335000a8;
      iVar3 = uVar8 + uVar6;
      if (uVar6 - 1 < _DAT_2ac335000a8) {
        do {
          uVar4 = (ulonglong)uVar6;
          uVar8 = iVar3 - 1;
          do {
            bVar12 = uVar4 == 0;
            uVar4 = uVar4 - 1;
            if (bVar12) goto LAB_2ac334e5982;
            uVar5 = (ulonglong)(int)uVar8;
            uVar8 = uVar8 - 1;
          } while (uVar5 < uVar10);
LAB_2ac334e5951:
          uVar10 = 0x2ac301f9168;
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x120a82000001f6);
LAB_2ac334e5971:
          iVar3 = uVar8 + uVar6;
        } while (uVar6 - 1 < (uint)uVar10);
      }
      if (uVar6 == 0) goto LAB_2ac334e5982;
      goto LAB_2ac334e5e01;
    }
  }
  else {
LAB_2ac334e59e1:
    local_110 = 0x800010058;
    local_148 = 0x800010058;
    local_108 = 0;
    local_100 = 0;
    local_f8 = 0;
    uStack_f4 = 0;
    local_f0 = 0;
    uStack_ec = 0;
    local_e8 = 0;
    local_e0 = 0;
    local_140 = 0;
    local_138 = 0;
    local_130 = 0;
    uStack_12c = 0;
    local_128 = 0;
    uStack_124 = 0;
    local_120 = 0;
    local_118 = 0;
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_110,_DAT_2ac33500078 - 1,0);
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_148,_DAT_2ac33500078 - 1,0);
    (*(code *)0x7ff63a0c7470)(0x2ac301f9168,&local_110,0x2ac335000e0,0,1,_DAT_2ac33500078 - 1);
    (*(code *)0x7ff63a0c7470)(0x2ac301f9168,&local_148,0x2ac33500120,0,1,_DAT_2ac33500078 - 1);
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_110,_DAT_2ac33500078,0);
    (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,&local_148,_DAT_2ac33500078,0);
    if ((longlong)(int)_DAT_2ac33500078 - 1U < (local_108 & 0xffffffff)) {
      *(double *)(CONCAT44(local_f0,uStack_f4) + -8 + (longlong)(int)_DAT_2ac33500078 * 8) = param_2
      ;
      iVar3 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
      if ((local_140 & 0xffffffff) <= (longlong)(int)_DAT_2ac33500078 - 1U) goto LAB_2ac334e5da1;
      *(double *)(CONCAT44(local_128,uStack_12c) + -8 + (longlong)(int)_DAT_2ac33500078 * 8) =
           (double)iVar3;
      (*(code *)0x7ff63a0c7470)(0x2ac301f9168,0x2ac335000e0,&local_110,0,0,0xffffffff);
      (*(code *)0x7ff63a0c7470)(0x2ac301f9168,0x2ac33500120,&local_148,0,0,0xffffffff);
      lVar11 = (longlong)(int)_DAT_2ac33500078;
      uVar10 = lVar11 - 1;
      if (_DAT_2ac33500128 <= uVar10) goto LAB_2ac334e5dc1;
      if (uVar10 < _DAT_2ac335000e8) {
        dVar13 = 0.0;
        if (0 < (int)_DAT_2ac33500078) {
          uVar8 = _DAT_2ac33500078;
          do {
            if (_DAT_2ac33500128 <= (uint)uVar10) {
              (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x280a4f000001f6);
LAB_2ac334e5d61:
              (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x120a73000001f6);
              goto LAB_2ac334e5d81;
            }
            uVar6 = uVar8 - 1;
            if ((int)(uint)DAT_2ac33500060 <
                *(int *)(_DAT_2ac3350013c + -4 + lVar11 * 4) -
                *(int *)(_DAT_2ac3350013c + (ulonglong)uVar6 * 4)) {
              if (_DAT_2ac335000e8 <= uVar6) goto LAB_2ac334e5e41;
              dVar13 = *(double *)(_DAT_2ac335000fc + (ulonglong)uVar6 * 8);
              goto LAB_2ac334e5c91;
            }
            uVar6 = uVar8 - 1;
            bVar12 = 0 < (int)uVar8;
            uVar8 = uVar6;
          } while (uVar6 != 0 && bVar12);
          dVar13 = 0.0;
        }
LAB_2ac334e5c91:
        dVar13 = *(double *)(_DAT_2ac335000fc + -8 + lVar11 * 8) - dVar13;
        _DAT_2ac33500088 = 0.0;
        if (dVar13 / _DAT_2ac33505c18 <= _DAT_2ac334f8bf0 || _DAT_2ac33505c18 == 0.0) {
          _DAT_2ac33500088 = dVar13;
        }
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_148);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_110);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_148);
        (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_110);
        return;
      }
    }
    else {
LAB_2ac334e5d81:
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x120a42000001f6);
LAB_2ac334e5da1:
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x130a43000001f6);
LAB_2ac334e5dc1:
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x200a47000001f6);
    }
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x210a48000001f6);
LAB_2ac334e5e01:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x120a80000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x180a35000001f6);
LAB_2ac334e5e41:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f0a51000001f6);
LAB_2ac334e5e61:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x140a85000001f6);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



/* Address: 2ac334e5e90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ac334e5e90(double param_1,longlong param_2)

{
  longlong lVar1;
  double dVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  ulonglong uVar10;
  double dVar11;
  
  puVar5 = *(undefined1 **)(param_2 + 4);
  if (puVar5 != &DAT_2ac334f9158) {
    if (puVar5 == (undefined1 *)0x0) goto LAB_2ac334e5f32;
    uVar8 = *(uint *)(puVar5 + -4);
    uVar6 = _DAT_2ac334f9154;
    if (uVar8 < _DAT_2ac334f9154) {
      uVar6 = uVar8;
    }
    iVar7 = uVar8 - _DAT_2ac334f9154;
    if (uVar6 != 0) {
      uVar10 = 0;
      do {
        uVar3 = *(ushort *)(puVar5 + uVar10 * 2);
        uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar10 * 2);
        uVar10 = uVar10 + 1;
        if (uVar6 <= uVar10) break;
      } while (uVar3 == uVar4);
      if (uVar3 != uVar4) {
        iVar7 = (uint)uVar3 - (uint)uVar4;
      }
    }
    if (iVar7 != 0) goto LAB_2ac334e5f32;
  }
  FUN_2ac334d0af0(param_2,0x2ac33505c28,1,0x2ac334fe210);
LAB_2ac334e5f32:
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,param_2,0x1b);
  if ((_DAT_2ac33505c48 != 0.0) || (NAN(_DAT_2ac33505c48))) {
    param_1 = param_1 / _DAT_2ac33505c48;
    uVar8 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar8 - 0x3ff;
    dVar11 = param_1;
    if ((ulonglong)uVar8 < 0x433) {
      if (uVar8 < 0x3ff) {
        dVar11 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar11 = (double)((ulonglong)param_1 & 0x8000000000000000);
        }
      }
      else {
        bVar9 = (byte)lVar1;
        if (((longlong)param_1 << (bVar9 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar11 = (double)((0x8000000000000U >> (bVar9 & 0x3f)) + (longlong)param_1 &
                           -0x10000000000000 >> (bVar9 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar11 = param_1 + param_1;
    }
    param_1 = dVar11 * _DAT_2ac33505c48;
  }
  else {
    uVar8 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,param_2,0x11);
    if ((longlong)param_1 != -0x8000000000000000) {
      dVar11 = (double)(longlong)param_1;
      uVar10 = 0xb;
      if (uVar8 < 0xb) {
        uVar10 = (ulonglong)uVar8;
      }
      dVar2 = *(double *)(uVar10 * 8 + 0x2ac334f8f00);
      param_1 = (double)(longlong)
                        ((param_1 - dVar11) * dVar2 +
                        *(double *)((ulonglong)(0.0 < param_1) * 8 + 0x2ac334f8bf8)) / dVar2 +
                dVar11;
    }
  }
  return param_1;
}



/* Address: 2ac334e60c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_2ac334e60c0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_78;
  undefined8 local_74;
  
  local_78 = 0;
  local_74 = 0;
  if (_DAT_2ac33505c14 == 0) {
    cVar1 = (*(code *)0x7ff63a107ee0)(0x2ac301f9168);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      FUN_2ac334d00a0(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      FUN_2ac334d00a0(param_1 + 0x84);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
      FUN_2ac334d00a0(param_1 + 0x144);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
      FUN_2ac334d00a0(param_1 + 0x208);
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
      (*(code *)0x7ff63a108010)(0x2ac301f9168,0);
      FUN_2ac334d0af0(&local_78,0x2ac33505c3c,1,0x2ac334fd2c8);
      FUN_2ac334d0af0(param_1 + 0x34,&local_78,0,0x2ac334fd2d8);
      *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
      *(undefined8 *)(param_1 + 0x58) = param_3;
      *(undefined8 *)(param_1 + 0x60) = param_4;
      uVar2 = FUN_2ac334d0e40(param_1,param_1 + 0x20,param_1 + 0x110);
      goto LAB_2ac334e6392;
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0xd,2,0x590008,0x2ac334fb310,0x590008,0x2ac334fa2c0);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  uVar2 = 0;
LAB_2ac334e6392:
  FUN_2ac334d00a0(&local_78);
  return uVar2;
}



/* Address: 2ac334e63c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ac334e63c0(undefined8 param_1,int param_2)

{
  double dVar1;
  int iVar2;
  undefined8 uVar3;
  double dVar4;
  undefined1 local_78 [96];
  
  (*(code *)0x7ff63a0f2c10)(0x2ac301f9168,param_1,local_78);
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,param_1,0x10);
  dVar1 = _DAT_2ac33505c48;
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
  dVar4 = 0.0;
  if (iVar2 != 0) {
    dVar4 = _DAT_2ac334f8c08 * dVar1 + 0.0;
  }
  if (param_2 - 2U < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334e6468 */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)((ulonglong)(param_2 - 2U) * 8 + 0x2ac334f8c10))(dVar4);
    return uVar3;
  }
  return 1;
}



/* Address: 2ac334e64f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334e64f0(longlong param_1,undefined8 param_2)

{
  if (_DAT_2ac33505c14 != 0) {
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0xd,2,0x590008,0x2ac334fb310,0x590008,0x2ac334fa358);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
    return;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  FUN_2ac334d00a0(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  FUN_2ac334d00a0(param_1 + 0x84);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
  FUN_2ac334d00a0(param_1 + 0x144);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
  FUN_2ac334d00a0(param_1 + 0x208);
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
  *(undefined4 *)(param_1 + 0x20) = 8;
  *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
  *(undefined8 *)(param_1 + 0x2c) = param_2;
  FUN_2ac334d0e40(param_1,param_1 + 0x20,param_1 + 0x110);
  return;
}



/* Address: 2ac334e6740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ac334e6740(longlong param_1)

{
  longlong lVar1;
  double dVar2;
  ushort uVar3;
  ushort uVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  double dVar17;
  undefined8 uVar18;
  undefined4 *puVar19;
  undefined4 local_d8;
  undefined1 *local_d4;
  undefined4 local_c8;
  longlong local_c4;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  double local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  double *local_64;
  undefined8 local_5c;
  undefined8 local_54;
  
  local_80 = 0x1000058;
  local_a8 = 0;
  local_b8 = 0;
  local_98 = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_a4 = 0;
  local_b4 = 0;
  local_94 = 0;
  local_c4 = 0;
  local_d4 = (undefined1 *)0x0;
  uVar18 = 1;
  _DAT_2ac33505c10 = 0;
  _DAT_2ac33505c80 = 0;
  DAT_2ac33505c88 = 0;
  local_7c = 0x100000008;
  local_74 = 0;
  local_64 = &local_88;
  local_6c = 0x100000000;
  puVar19 = &local_80;
  local_54 = 0;
  local_5c = 0;
  iVar9 = (*(code *)0x7ff63a0eeec0)(0x2ac301f9168);
  if (-1 < iVar9) {
    FUN_2ac334d0af0(&local_d8,0x2ac334f9160,0,0x2ac334fee60,uVar18,puVar19);
    if (local_d4 == &DAT_2ac334f9158) {
LAB_2ac334e691c:
      FUN_2ac334d0af0(&local_d8,0x2ac33505c28,1,0x2ac334fe220,uVar18,puVar19);
    }
    else if (local_d4 != (undefined1 *)0x0) {
      uVar10 = *(uint *)(local_d4 + -4);
      uVar11 = _DAT_2ac334f9154;
      if (uVar10 < _DAT_2ac334f9154) {
        uVar11 = uVar10;
      }
      iVar9 = uVar10 - _DAT_2ac334f9154;
      if (uVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = *(ushort *)(local_d4 + uVar15 * 2);
          uVar4 = *(ushort *)(&DAT_2ac334f9158 + uVar15 * 2);
          uVar15 = uVar15 + 1;
          if (uVar11 <= uVar15) break;
        } while (uVar3 == uVar4);
        if (uVar3 != uVar4) {
          iVar9 = (uint)uVar3 - (uint)uVar4;
        }
      }
      if (iVar9 == 0) goto LAB_2ac334e691c;
    }
    uVar10 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_d8,0x11);
    if ((longlong)local_88 != -0x8000000000000000) {
      dVar17 = (double)(longlong)local_88;
      uVar15 = 0xb;
      if (uVar10 < 0xb) {
        uVar15 = (ulonglong)uVar10;
      }
      dVar2 = *(double *)(uVar15 * 8 + 0x2ac334f8f00);
      local_88 = (double)(longlong)
                         ((local_88 - dVar17) * dVar2 +
                         *(double *)((ulonglong)(0.0 < local_88) * 8 + 0x2ac334f8c30)) / dVar2 +
                 dVar17;
    }
    goto LAB_2ac334e6eed;
  }
  FUN_2ac334d0af0(&local_d8,0x2ac334fc830,0,0x2ac334fee10,uVar18,puVar19);
  lVar5 = *(longlong *)(param_1 + 4);
  if (lVar5 == 0) {
LAB_2ac334e6afd:
    uVar12 = 0;
    FUN_2ac334d0af0(&local_c8,&local_d8,0,0x2ac334fee20,uVar18,puVar19);
    uVar10 = _DAT_2ac334fc848;
    uVar15 = (ulonglong)_DAT_2ac334fc848;
    if ((uVar15 == 0) && (local_c4 != 0)) {
LAB_2ac334e6c2d:
      (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)_DAT_2ac33505c10,0,0x20);
      FUN_2ac334d0af0(&local_98,0x2ac33505c3c,1,0x2ac334fee30);
      FUN_2ac334d0af0(&local_b8,&local_c8);
      lVar5 = local_94;
      if (local_94 != 0) {
        uVar10 = *(uint *)(local_94 + -4);
        uVar15 = (ulonglong)uVar10;
        if ((uVar15 != 0) || (local_b4 == 0)) {
          if (local_b4 == 0) {
            uVar12 = 0;
            uVar11 = uVar10;
          }
          else {
            uVar12 = (ulonglong)*(uint *)(local_b4 + -4);
            uVar11 = uVar10 + *(uint *)(local_b4 + -4);
          }
          cVar8 = FUN_2ac334d0100(&local_b8);
          if (cVar8 == '\0') goto LAB_2ac334e6f96;
          if (uVar15 != 0) {
            lVar1 = local_b4 + uVar12 * 2;
            if (uVar10 < 0x10) {
              uVar12 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
              uVar12 = 0;
            }
            else {
              uVar16 = 0;
              uVar12 = (ulonglong)(uVar10 & 0xfffffff8);
              do {
                uVar18 = ((undefined8 *)(lVar5 + uVar16))[1];
                *(undefined8 *)(lVar1 + uVar16) = *(undefined8 *)(lVar5 + uVar16);
                ((undefined8 *)(lVar1 + uVar16))[1] = uVar18;
                uVar16 = uVar16 + 0x10;
              } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
              if (uVar12 == uVar15) goto LAB_2ac334e6d82;
            }
            do {
              *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
              uVar12 = uVar12 + 1;
            } while (uVar15 != uVar12);
          }
LAB_2ac334e6d82:
          *(uint *)(local_b4 + -4) = uVar11;
          *(undefined2 *)(local_b4 + (ulonglong)uVar11 * 2) = 0;
        }
      }
      uVar10 = 0;
      FUN_2ac334d0af0(&local_a8,&local_b8,0,0x2ac334fee50);
      uVar11 = _DAT_2ac334f9668;
      uVar15 = (ulonglong)_DAT_2ac334f9668;
      if ((uVar15 != 0) || (local_a4 == 0)) {
        if (local_a4 != 0) {
          uVar10 = *(uint *)(local_a4 + -4);
        }
        uVar13 = _DAT_2ac334f9668 + uVar10;
        uVar14 = 0x104;
        if ((0x103 < uVar13) &&
           ((0x7ffffffd < uVar13 || (uVar14 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar14)))) {
          uVar14 = 0x7ffffffe;
        }
        cVar8 = FUN_2ac334d0100(&local_a8,uVar14);
        if (cVar8 == '\0') goto LAB_2ac334e6f56;
        if (uVar15 != 0) {
          lVar5 = local_a4 + (ulonglong)uVar10 * 2;
          if (uVar11 < 0x10) {
            uVar12 = 0;
          }
          else if (lVar5 - 0x2ac334f966cU < 0x20) {
            uVar12 = 0;
          }
          else {
            uVar16 = 0;
            uVar12 = (ulonglong)(uVar11 & 0xfffffff8);
            do {
              uVar18 = *(undefined8 *)(uVar16 + 0x2ac334f9674);
              *(undefined8 *)(lVar5 + uVar16) = *(undefined8 *)(&DAT_2ac334f966c + uVar16);
              ((undefined8 *)(lVar5 + uVar16))[1] = uVar18;
              uVar16 = uVar16 + 0x10;
            } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar12 == uVar15) goto LAB_2ac334e6eb2;
          }
          do {
            *(undefined2 *)(lVar5 + uVar12 * 2) = *(undefined2 *)(&DAT_2ac334f966c + uVar12 * 2);
            uVar12 = uVar12 + 1;
          } while (uVar15 != uVar12);
        }
LAB_2ac334e6eb2:
        *(uint *)(local_a4 + -4) = uVar13;
        *(undefined2 *)(local_a4 + (ulonglong)uVar13 * 2) = 0;
      }
      (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,&local_a8);
      local_88 = 0.0;
LAB_2ac334e6eed:
      FUN_2ac334d00a0(&local_d8);
      FUN_2ac334d00a0(&local_c8);
      FUN_2ac334d00a0(&local_98);
      FUN_2ac334d00a0(&local_b8);
      FUN_2ac334d00a0(&local_a8);
      return local_88;
    }
    if (local_c4 != 0) {
      uVar12 = (ulonglong)*(uint *)(local_c4 + -4);
    }
    uVar14 = _DAT_2ac334fc848 + (int)uVar12;
    uVar11 = 0x104;
    if ((0x103 < uVar14) &&
       ((0x7ffffffd < uVar14 || (uVar11 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar11)))) {
      uVar11 = 0x7ffffffe;
    }
    cVar8 = FUN_2ac334d0100(&local_c8,uVar11);
    if (cVar8 != '\0') {
      if (uVar15 != 0) {
        lVar5 = local_c4 + uVar12 * 2;
        if (uVar10 < 0x10) {
          uVar12 = 0;
        }
        else if (lVar5 - 0x2ac334fc84cU < 0x20) {
          uVar12 = 0;
        }
        else {
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar10 & 0xfffffff8);
          do {
            uVar18 = *(undefined8 *)(uVar16 + 0x2ac334fc854);
            *(undefined8 *)(lVar5 + uVar16) = *(undefined8 *)(&DAT_2ac334fc84c + uVar16);
            ((undefined8 *)(lVar5 + uVar16))[1] = uVar18;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar12 == uVar15) goto LAB_2ac334e6c22;
        }
        do {
          *(undefined2 *)(lVar5 + uVar12 * 2) = *(undefined2 *)(&DAT_2ac334fc84c + uVar12 * 2);
          uVar12 = uVar12 + 1;
        } while (uVar15 != uVar12);
      }
LAB_2ac334e6c22:
      *(uint *)(local_c4 + -4) = uVar14;
      *(undefined2 *)(local_c4 + (ulonglong)uVar14 * 2) = 0;
      goto LAB_2ac334e6c2d;
    }
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2009be000001f9);
LAB_2ac334e6f56:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5c09be000001f9);
  }
  else {
    uVar10 = *(uint *)(lVar5 + -4);
    uVar15 = (ulonglong)uVar10;
    if ((uVar15 == 0) && (local_d4 != (undefined1 *)0x0)) goto LAB_2ac334e6afd;
    if (local_d4 == (undefined1 *)0x0) {
      uVar11 = 0;
      uVar14 = uVar10;
    }
    else {
      uVar11 = *(uint *)(local_d4 + -4);
      uVar14 = uVar10 + uVar11;
    }
    cVar8 = FUN_2ac334d0100(&local_d8);
    if (cVar8 != '\0') {
      if (uVar15 != 0) {
        if (uVar10 < 0x10) {
          uVar12 = 0;
        }
        else if (local_d4 + ((ulonglong)uVar11 * 2 - lVar5) < (undefined1 *)0x20) {
          uVar12 = 0;
        }
        else {
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar10 & 0xfffffff8);
          do {
            uVar7 = ((undefined8 *)(lVar5 + uVar16))[1];
            *(undefined8 *)(local_d4 + uVar16 + (ulonglong)uVar11 * 2) =
                 *(undefined8 *)(lVar5 + uVar16);
            *(undefined8 *)((longlong)(local_d4 + uVar16 + (ulonglong)uVar11 * 2) + 8) = uVar7;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar12 == uVar15) goto LAB_2ac334e6af2;
        }
        do {
          *(undefined2 *)(local_d4 + uVar12 * 2 + (ulonglong)uVar11 * 2) =
               *(undefined2 *)(lVar5 + uVar12 * 2);
          uVar12 = uVar12 + 1;
        } while (uVar15 != uVar12);
      }
LAB_2ac334e6af2:
      *(uint *)(local_d4 + -4) = uVar14;
      *(undefined2 *)(local_d4 + (ulonglong)uVar14 * 2) = 0;
      goto LAB_2ac334e6afd;
    }
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1c09be000001f9);
LAB_2ac334e6f96:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3c09be000001f9);
  pcVar6 = (code *)swi(3);
  dVar17 = (double)(*pcVar6)();
  return dVar17;
}



/* Address: 2ac334e6fc0 */

undefined8 FUN_2ac334e6fc0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 *local_1c;
  undefined8 local_14;
  undefined8 local_c;
  
  local_38 = 0x1000058;
  local_1c = &local_40;
  local_34 = 0x100000008;
  local_2c = 0;
  local_24 = 0x100000000;
  local_14 = 0;
  local_c = 0;
  iVar1 = (*(code *)0x7ff63a1021d0)(0x2ac301f9168,5,param_1,0,0,1,&local_38);
  uVar2 = 0;
  if (0 < iVar1) {
    uVar2 = local_40;
  }
  return uVar2;
}



/* Address: 2ac334e7060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2ac334e7060(undefined8 param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  char cVar10;
  int iVar11;
  longlong lVar12;
  int iVar13;
  int iVar14;
  ulonglong uVar15;
  double dVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  longlong local_a4;
  
  local_b8 = 0;
  local_b4 = 0;
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x23);
  dVar9 = _DAT_2ac33505c48;
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,0x2ac334f9140,0x37);
  dVar6 = 0.0;
  bVar5 = _DAT_2ac33505c48 == 0.0;
  uVar15 = ~-(ulonglong)bVar5 & (ulonglong)_DAT_2ac33505c48;
  FUN_2ac334d0af0(&local_b8,param_1,0,0x2ac334fe990);
  cVar10 = (*(code *)0x7ff63a107f20)(0x2ac301f9168,&local_b8);
  if (cVar10 == '\0') {
    uVar17 = (undefined4)_DAT_2ac334f8c40;
    uVar18 = (undefined4)((ulonglong)_DAT_2ac334f8c40 >> 0x20);
  }
  else {
    (*(code *)0x7ff63a107f70)(0x2ac301f9168,3);
    uVar17 = SUB84(_DAT_2ac33505c48,0);
    uVar18 = (undefined4)((ulonglong)_DAT_2ac33505c48 >> 0x20);
  }
  dVar16 = (double)(uVar15 | -(ulonglong)bVar5 & (ulonglong)dVar9);
  iVar14 = 0;
  FUN_2ac334d0af0(&local_b8,param_1,0,0x2ac334fe9a0);
  local_a8 = 0;
  local_a4 = 0;
  iVar11 = (*(code *)0x7ff63a1081a0)(0x2ac301f9168);
  if (0 < iVar11) {
    dVar6 = 0.0;
    do {
      lVar12 = (*(code *)0x7ff63a1081f0)(0x2ac301f9168,iVar14);
      if (lVar12 != 0) {
        (*(code *)0x7ff63a1083a0)(0x2ac301f9168,0);
        FUN_2ac334d0af0(&local_a8,0x2ac33505c3c,1,0x2ac334fe980);
        if (local_b4 == local_a4) {
LAB_2ac334e7210:
          (*(code *)0x7ff63a108280)(0x2ac301f9168,7);
          dVar6 = dVar6 + _DAT_2ac33505c48;
        }
        else if ((local_b4 != 0) && (local_a4 != 0)) {
          uVar3 = *(uint *)(local_b4 + -4);
          uVar4 = *(uint *)(local_a4 + -4);
          uVar7 = uVar4;
          if (uVar3 < uVar4) {
            uVar7 = uVar3;
          }
          iVar13 = uVar3 - uVar4;
          if (uVar7 != 0) {
            uVar15 = 1;
            do {
              uVar1 = *(ushort *)(local_b4 + -2 + uVar15 * 2);
              uVar2 = *(ushort *)(local_a4 + -2 + uVar15 * 2);
              if (uVar7 <= uVar15) break;
              uVar15 = uVar15 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar13 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar13 == 0) goto LAB_2ac334e7210;
        }
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 != iVar11);
  }
  FUN_2ac334d00a0(&local_a8);
  if ((((double)CONCAT44(uVar18,uVar17) < 0.0) ||
      (dVar16 = dVar16 - (double)CONCAT44(uVar18,uVar17), dVar8 = 0.0, 0.0 < dVar16)) &&
     (dVar8 = dVar16 - dVar6, dVar9 < dVar16 - dVar6)) {
    dVar8 = dVar9;
  }
  FUN_2ac334d00a0(&local_b8);
  return dVar8;
}



/* Address: 2ac334e7380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_2ac334e7380(undefined8 param_1,undefined8 param_2,uint param_3,double param_4,double param_5)

{
  ulonglong uVar1;
  double dVar2;
  double dVar3;
  char cVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  double *pdVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  undefined8 in_stack_fffffffffffffe38;
  undefined4 uVar20;
  undefined4 local_180;
  undefined8 local_17c;
  double local_170;
  undefined1 local_168 [64];
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined2 uStack_10c;
  undefined2 uStack_10a;
  undefined2 local_108;
  ushort local_106;
  undefined2 local_104;
  
  uVar19 = (undefined4)((ulonglong)param_4 >> 0x20);
  uVar14 = SUB84(param_4,0);
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  local_180 = 0;
  local_17c = 0;
  _DAT_2ac33505c10 = 0;
  _DAT_2ac33505c80 = 0;
  DAT_2ac33505c88 = 0;
  (*(code *)0x7ff63a0f2c10)(0x2ac301f9168,param_1,local_168);
  if ((param_4 == 0.0) && (!NAN(param_4))) {
    if (param_3 == 5) {
      uVar14 = (undefined4)local_168._8_8_;
      uVar19 = SUB84(local_168._8_8_,4);
    }
    else {
      uVar14 = (undefined4)local_168._16_8_;
      uVar19 = SUB84(local_168._16_8_,4);
    }
  }
  (*(code *)0x7ff63a0c7370)(0x2ac301f9168,0x2a);
  dVar3 = _DAT_2ac33505c48;
  dVar2 = (double)(*(code *)0x7ff63a3d9970)(SUB84((double)(int)param_3,0),(int)_DAT_2ac334f8c48);
  pdVar16 = &local_170;
  cVar4 = (*(code *)0x7ff63a108d40)
                    (0x2ac301f9168,(int)dVar2,param_1,(int)param_2,CONCAT44(uVar19,uVar14),pdVar16);
  uVar14 = (undefined4)((ulonglong)pdVar16 >> 0x20);
  if (cVar4 == '\0') {
    uVar19 = 0x520004;
    uVar9 = 4;
    uVar18 = 0x2ac334fb480;
    puVar17 = (undefined4 *)0x2ac334fb448;
    uVar15 = 0x2ac334fb400;
    param_2 = CONCAT44(uVar20,_DAT_2ac33505c10);
  }
  else {
    uVar19 = 0x301f9101;
    if (local_170 <= dVar3 - param_5) goto LAB_2ac334e773a;
    uVar5 = (ulonglong)param_3;
    uVar6 = 1;
    uVar8 = 9;
    puVar7 = (undefined8 *)0x0;
    do {
      while( true ) {
        if (uVar8 < uVar6) goto LAB_2ac334e7583;
        uVar11 = uVar6 + uVar8 >> 1;
        uVar1 = *(ulonglong *)(uVar11 * 0x10 + 0x2ac334fe160);
        if (uVar1 != uVar5) break;
        uVar12 = uVar11;
        if (3 < uVar6 + uVar8) {
          bVar13 = uVar11 != 1;
          puVar10 = (ulonglong *)(uVar11 * 0x10 + 0x2ac334fe150);
          do {
            uVar12 = uVar11;
            if (*puVar10 != uVar5) break;
            uVar11 = uVar11 - 1;
            puVar10 = puVar10 + -2;
            uVar12 = (ulonglong)bVar13;
          } while (1 < uVar11);
        }
        puVar7 = *(undefined8 **)(uVar12 * 0x10 + 0x2ac334fe168);
        if (uVar1 == uVar5) goto LAB_2ac334e7583;
      }
      uVar12 = uVar11 - 1;
      if ((longlong)uVar1 <= (longlong)uVar5) {
        uVar6 = uVar11 + 1;
        uVar12 = uVar8;
      }
      uVar8 = uVar12;
    } while (uVar1 != uVar5);
LAB_2ac334e7583:
    if (puVar7 == (undefined8 *)0x0) {
      puVar7 = &local_128;
      _DAT_2ac33505c10 = 0xfa3;
      local_118 = _DAT_2ac334fdfa0;
      uStack_114 = uRam000002ac334fdfa4;
      uStack_110 = uRam000002ac334fdfa8;
      local_128 = _DAT_2ac334fdf90;
      uStack_120 = uRam000002ac334fdf98;
      _uStack_10c = CONCAT22(0x3a,(short)uRam000002ac334fdfac);
      local_108 = 0x3a;
      local_106 = (short)param_3 + (short)(param_3 / 10) * -10 | 0x30;
      local_104 = 0;
    }
    puVar17 = &local_180;
    FUN_2ac334d0280(puVar17,puVar7,0xffffffff);
    uVar9 = 8;
    uVar19 = 0x580007;
    uVar15 = 0x2ac334fb4c8;
    uVar18 = 0x2ac334fb4e8;
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2ac301f9168,2,uVar9,0x590008,uVar15,CONCAT44(uVar14,0x590008),puVar17,0x590008,uVar18
             ,uVar19,param_2);
  uVar19 = 0;
LAB_2ac334e773a:
  FUN_2ac334d00a0(&local_180);
  return uVar19;
}



/* Address: 2ac334e7780 */

bool FUN_2ac334e7780(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)0x7ff63a0c73c0)(0x2ac301f9168,0x2f);
  if (iVar1 != 0) {
    iVar2 = (*(code *)0x7ff63a1081a0)(0x2ac301f9168);
    return iVar2 < iVar1;
  }
  return true;
}



/* Address: 2ac334e77d0 */

void FUN_2ac334e77d0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined1 local_140 [52];
  undefined4 local_10c;
  undefined8 local_108;
  
  lVar1 = (longlong)&local_228 + 4;
  local_1d4 = 0;
  local_1d0 = 0;
  local_10c = 0;
  local_108 = 0;
  local_228 = 0;
  uStack_220 = 0;
  local_238 = 0;
  uStack_234 = 0;
  uStack_230 = 0;
  uStack_22c = 0;
  FUN_2ac334d00a0(lVar1);
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_208 = 0;
  uStack_200 = 0;
  local_218 = 0;
  uStack_210 = 0;
  local_1d8 = 0;
  FUN_2ac334d00a0(&local_1d4);
  local_158 = 0;
  uStack_150 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  local_238 = 5;
  uStack_200 = 0;
  local_1f8 = 0;
  uVar4 = 0;
  uStack_210 = param_4;
  FUN_2ac334d0af0(lVar1,param_1,0,0x2ac334fe2b0);
  uStack_234 = (undefined4)param_7;
  uStack_230 = (undefined4)((ulonglong)param_7 >> 0x20);
  local_1e8 = CONCAT44(local_1e8._4_4_,param_2);
  local_218 = param_3;
  FUN_2ac334d0af0(&local_1d4,param_6,0,0x2ac334fe2c0);
  uVar2 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,param_1,0x21);
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,param_1,0x32);
  if ((uVar3 == 0) || ((uVar3 & 1) == 0)) {
    uVar4 = 2;
    if ((uVar2 & 0xfffffffd) != 1) {
      uVar4 = (uint)(uVar3 == 2);
    }
  }
  local_1e8 = CONCAT44(uVar4,(undefined4)local_1e8);
  uStack_1f0 = param_5;
  (*(code *)0x7ff63a108b70)(0x2ac301f9168,&local_238,local_140);
  FUN_2ac334d00a0(&local_10c);
  FUN_2ac334d00a0(&local_1d4);
  FUN_2ac334d00a0(lVar1);
  return;
}



/* Address: 2ac334e7a20 */

void FUN_2ac334e7a20(longlong param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x28);
  iVar4 = iVar3 - *(int *)(param_1 + 0x24);
  if (iVar4 < 1) {
    iVar1 = *(int *)(param_1 + 0x20);
    if ((iVar4 != -0x7fffffff) || (iVar1 != -1)) {
      if (iVar1 == 0) goto LAB_2ac334e7b2e;
      iVar3 = ((1 - iVar4) / iVar1 + 1) * iVar1 + iVar3;
      if (iVar3 < 0) {
        return;
      }
      iVar3 = (*(code *)0x7ff63a0da0e0)(0x2ac301f9168,param_1 + 0x30,iVar3,0);
      *(int *)(param_1 + 0x28) = iVar3;
      if (iVar3 == -1) {
        iVar3 = *(int *)(param_1 + 0x38);
        *(int *)(param_1 + 0x28) = iVar3;
      }
      goto LAB_2ac334e7a36;
    }
  }
  else {
LAB_2ac334e7a36:
    iVar4 = *(int *)(param_1 + 0x24);
    if (iVar3 - iVar4 < 1) {
      return;
    }
    *(int *)(param_1 + 0x24) = iVar4 + 1;
    if ((ulonglong)(longlong)iVar4 < (ulonglong)*(uint *)(param_1 + 0x38)) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x4c) + (longlong)iVar4 * 4) = param_2;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      return;
    }
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1600c5000801f6);
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3d008a00080236);
LAB_2ac334e7b2e:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3d008a000801f7);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



/* Address: 2ac334e7b50 */

ulonglong FUN_2ac334e7b50(longlong param_1,uint param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  
  uVar2 = 0x7fffffff;
  if ((int)param_2 < *(int *)(param_1 + 0x24)) {
    if (*(uint *)(param_1 + 0x38) <= param_2) {
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x11016b000801f6);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x4c) + (ulonglong)param_2 * 4);
  }
  return uVar2;
}



/* Address: 2ac334e7ba0 */

void FUN_2ac334e7ba0(longlong param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 <= (int)param_2) {
    return;
  }
  iVar6 = iVar1 + -1;
  if ((int)param_2 < iVar6) {
    if ((int)param_2 < -1) {
      return;
    }
    uVar3 = iVar1 + ~param_2;
    if ((int)uVar3 < 0) {
      return;
    }
    if (uVar3 != 0) {
      uVar4 = (ulonglong)uVar3;
      uVar3 = param_2;
      do {
        uVar5 = uVar3 + 1;
        if ((ulonglong)*(uint *)(param_1 + 0x38) <= (ulonglong)(longlong)(int)uVar5) {
LAB_2ac334e7c30:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x220071000801f6);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        if ((ulonglong)*(uint *)(param_1 + 0x38) <= (ulonglong)(longlong)(int)uVar3) {
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x140071000801f6);
          goto LAB_2ac334e7c30;
        }
        uVar4 = uVar4 - 1;
        *(undefined4 *)(*(longlong *)(param_1 + 0x4c) + (longlong)(int)uVar3 * 4) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x4c) + (longlong)(int)uVar5 * 4);
        uVar3 = uVar5;
      } while (uVar4 != 0);
    }
    if ((int)param_2 < 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x24) + -1;
  }
  *(int *)(param_1 + 0x24) = iVar6;
  return;
}



/* Address: 2ac334e7c10 */

void FUN_2ac334e7c10(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x140071000801f6);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x220071000801f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ac334e7c60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2ac334e7c60(uint param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (_DAT_2ac33505a14 <= (int)param_1) {
    return _DAT_2ac334f8c50;
  }
  if (param_1 < _DAT_2ac33505a28) {
    return *(undefined8 *)(_DAT_2ac33505a3c + (ulonglong)param_1 * 8);
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x11016d000a01f6);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



/* Address: 2ac334e7cd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334e7cd0(double param_1,double param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  code *pcVar6;
  double dVar7;
  double dVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined4 *puVar17;
  ulonglong uVar18;
  uint uVar19;
  uint uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  uint uVar23;
  undefined4 *in_stack_fffffffffffffe78;
  undefined4 uVar24;
  undefined4 local_168;
  longlong local_164;
  undefined4 local_158;
  longlong local_154;
  undefined4 local_148;
  longlong local_144;
  int local_13c;
  undefined4 local_138;
  longlong local_134;
  char local_12a;
  char local_129;
  undefined8 local_128;
  int local_11c;
  undefined4 local_118;
  longlong local_114;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined8 local_d8;
  undefined4 local_d0;
  longlong local_cc;
  longlong local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined8 local_a4;
  
  local_118 = 0;
  local_138 = 0;
  local_168 = 0;
  local_158 = 0;
  local_148 = 0;
  local_d0 = 0;
  local_108 = 0;
  local_f8 = 0;
  local_e8 = 0;
  local_114 = 0;
  local_134 = 0;
  local_164 = 0;
  local_154 = 0;
  local_144 = 0;
  local_cc = 0;
  local_104 = 0;
  local_f4 = 0;
  local_e4 = 0;
  iVar12 = (*(code *)0x7ff63a107da0)(0x2ac301f9168);
  cVar10 = DAT_2ac33505db8;
  cVar9 = DAT_2ac33505da0;
  if (0 < iVar12) {
    local_c0 = (longlong)_DAT_2ac33505d18;
    local_12a = DAT_2ac33505db8 == '\0' || DAT_2ac33505da0 == '\0';
    local_129 = DAT_2ac33505db8 == '\0' && DAT_2ac33505da0 == '\0';
    iVar12 = 0;
    do {
      lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
      if (lVar14 == 0) {
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x906cb000001fa);
LAB_2ac334ebbf0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xc06cc000001fa);
LAB_2ac334ebc10:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c06cc000001fa);
LAB_2ac334ebc30:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1906d1000001fa);
LAB_2ac334ebc50:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1906d0000001fa);
LAB_2ac334ebc70:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b06cd000001fa);
LAB_2ac334ebc90:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1706eb000001fa);
LAB_2ac334ebcb0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1206d6000001fa);
LAB_2ac334ebcd0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4706d4000001fa);
LAB_2ac334ebcf0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4506d3000001fa);
LAB_2ac334ebd10:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2a06de000001fa);
LAB_2ac334ebd30:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2706dc000001fa);
LAB_2ac334ebd50:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3f06ee000001f9);
LAB_2ac334ebd70:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x42070a000001f9);
LAB_2ac334ebd90:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06d7000001f9);
LAB_2ac334ebdb0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b06d7000001f9);
LAB_2ac334ebdd0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1506e2000001fa);
LAB_2ac334ebdf0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2706ee000001f9);
LAB_2ac334ebe10:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2a070a000001f9);
LAB_2ac334ebe30:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2306d7000001f9);
LAB_2ac334ebe50:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2106d9000001f9);
LAB_2ac334ebe70:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2d06d9000001f9);
LAB_2ac334ebe90:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2506d9000001f9);
LAB_2ac334ebeb0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4306d9000001f9);
LAB_2ac334ebed0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x6e06dd000001f9);
LAB_2ac334ebef0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x7306df000001f9);
LAB_2ac334ebf10:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06f5000001fa);
LAB_2ac334ebf30:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3806f5000001fa);
LAB_2ac334ebf50:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06ff000001fa);
LAB_2ac334ebf70:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3806ff000001fa);
LAB_2ac334ebf90:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2206e3000001f9);
LAB_2ac334ebfb0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e06e3000001f9);
LAB_2ac334ebfd0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f0710000001fa);
LAB_2ac334ebff0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x380710000001fa);
LAB_2ac334ec010:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f071a000001fa);
LAB_2ac334ec030:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x38071a000001fa);
LAB_2ac334ec050:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5606dd000001f9);
LAB_2ac334ec070:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5b06df000001f9);
LAB_2ac334ec090:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2606e3000001f9);
LAB_2ac334ec0b0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2406e6000001f9);
LAB_2ac334ec0d0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3006e6000001f9);
LAB_2ac334ec0f0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5506f6000001fa);
LAB_2ac334ec110:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x550700000001fa);
LAB_2ac334ec130:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2806e6000001f9);
LAB_2ac334ec150:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4c06e6000001f9);
LAB_2ac334ec170:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x550711000001fa);
LAB_2ac334ec190:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x55071b000001fa);
LAB_2ac334ec1b0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b06f6000001f9);
LAB_2ac334ec1d0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x6906f6000001f9);
LAB_2ac334ec1f0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b0700000001f9);
LAB_2ac334ec210:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x690700000001f9);
LAB_2ac334ec230:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b0711000001f9);
LAB_2ac334ec250:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x690711000001f9);
LAB_2ac334ec270:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b071b000001f9);
LAB_2ac334ec290:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x69071b000001f9);
LAB_2ac334ec2b0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4406f6000001f9);
LAB_2ac334ec2d0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x440700000001f9);
LAB_2ac334ec2f0:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x440711000001f9);
LAB_2ac334ec310:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x44071b000001f9);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      lVar14 = (*(code *)0x7ff63a107df0)(0x2ac301f9168,iVar12);
      if (lVar14 == 0) goto LAB_2ac334e7f00;
      local_13c = iVar12;
      lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
      if (lVar14 == 0) goto LAB_2ac334ebbf0;
      local_a8 = 0;
      local_b8 = 0;
      local_a4 = 0;
      local_b4 = 0;
      (*(code *)0x7ff63a108010)(0x2ac301f9168,0);
      FUN_2ac334d0af0(&local_a8,0x2ac33505c3c,1,0x2ac334fd248);
      FUN_2ac334d0af0(&local_b8,&local_a8,0,0x2ac334fd258);
      FUN_2ac334d0af0(0x2ac33505c3c,&local_b8,1,0x2ac334fd268);
      FUN_2ac334d00a0(&local_b8);
      FUN_2ac334d00a0(&local_a8);
      FUN_2ac334d0af0(&local_d0,0x2ac33505c3c,1,0x2ac334fe560);
      iVar12 = local_13c;
      if (local_cc == _DAT_2ac33505c2c) {
LAB_2ac334e80cf:
        lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar14 == 0) goto LAB_2ac334ebc10;
        lVar14 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0xc);
        if (lVar14 != local_c0) goto LAB_2ac334e7f00;
        lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar14 == 0) goto LAB_2ac334ebc70;
        local_128 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
        local_108 = 0;
        local_104 = 0;
        (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_128,0,0x20);
        FUN_2ac334d0af0(&local_148,0x2ac33505c3c,1,0x2ac334fe570);
        FUN_2ac334d0af0(&local_108,&local_148,0,0x2ac334fe580);
        lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar14 == 0) goto LAB_2ac334ebc50;
        (*(code *)0x7ff63a107f70)(0x2ac301f9168,6);
        dVar7 = _DAT_2ac33505c48;
        lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar14 == 0) goto LAB_2ac334ebc30;
        (*(code *)0x7ff63a107f70)(0x2ac301f9168,7);
        dVar8 = _DAT_2ac33505c48;
        uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffe78 >> 0x20);
        if ((dVar7 != 0.0 && cVar10 != '\0') || (cVar9 != '\0' && _DAT_2ac33505c48 != 0.0)) {
          if (((dVar7 != 0.0) || (NAN(dVar7))) && (cVar10 != '\0')) {
            lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
            if (lVar14 != 0) {
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              FUN_2ac334d0af0(&local_148,0x2ac334fb728,0,0x2ac334fe590);
              FUN_2ac334d0af0(&local_158,0x2ac33505c28,1,0x2ac334fe5a0);
              uVar15 = CONCAT44(uVar24,0xff);
              FUN_2ac334f50f0(local_154,&local_148,uVar16,dVar7,uVar15);
              uVar24 = (undefined4)((ulonglong)uVar15 >> 0x20);
              goto LAB_2ac334e840f;
            }
            goto LAB_2ac334ebcf0;
          }
LAB_2ac334e840f:
          if (((dVar8 != 0.0) || (NAN(dVar8))) && (cVar9 != '\0')) {
            lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
            if (lVar14 != 0) {
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              FUN_2ac334d0af0(&local_148,0x2ac334fb7b8,0,0x2ac334fe5b0);
              FUN_2ac334d0af0(&local_158,0x2ac33505c28,1,0x2ac334fe5c0);
              FUN_2ac334f50f0(local_154,&local_148,uVar16,dVar8,CONCAT44(uVar24,0x8000));
              goto LAB_2ac334e84c2;
            }
            goto LAB_2ac334ebcd0;
          }
LAB_2ac334e84c2:
          _DAT_2ac33505c10 = 0;
          _DAT_2ac33505c80 = 0;
          DAT_2ac33505c88 = 0;
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
          if (lVar14 == 0) goto LAB_2ac334ebcb0;
          cVar11 = FUN_2ac334e60c0(lVar14,local_128,0,0);
          if (cVar11 != '\0') {
            FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe5d0);
            uVar5 = _DAT_2ac334fb8fc;
            uVar22 = (ulonglong)_DAT_2ac334fb8fc;
            if ((uVar22 != 0) || (local_144 == 0)) {
              if (local_144 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb8fc;
              }
              else {
                uVar23 = *(uint *)(local_144 + -4);
                uVar19 = _DAT_2ac334fb8fc + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_148,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_144 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_144 + -0x2ac334fb900 + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb908);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb900 + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334e8772;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb900 + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334e8772:
                *(uint *)(local_144 + -4) = uVar19;
                *(undefined2 *)(local_144 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334e8787;
              }
              goto LAB_2ac334ebd90;
            }
LAB_2ac334e8787:
            FUN_2ac334d0af0(&local_158,&local_148,0);
            lVar14 = local_104;
            if (local_104 == 0) {
LAB_2ac334e88ce:
              FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe5f0);
              uVar5 = _DAT_2ac334fb918;
              uVar22 = (ulonglong)_DAT_2ac334fb918;
              if ((uVar22 == 0) && (local_164 != 0)) {
LAB_2ac334e8a17:
                in_stack_fffffffffffffe78 = &local_168;
LAB_2ac334e8f46:
                (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,in_stack_fffffffffffffe78);
                goto LAB_2ac334e8f7f;
              }
              if (local_164 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb918;
              }
              else {
                uVar23 = *(uint *)(local_164 + -4);
                uVar19 = _DAT_2ac334fb918 + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_168,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_164 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_164 + -0x2ac334fb91c + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb924);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb91c + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334e8a02;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb91c + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334e8a02:
                *(uint *)(local_164 + -4) = uVar19;
                *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334e8a17;
              }
              goto LAB_2ac334ebdb0;
            }
            uVar5 = *(uint *)(local_104 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e88ce;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e88b2;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e88b2:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e88ce;
            }
            goto LAB_2ac334ebe30;
          }
          FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe600);
          uVar5 = _DAT_2ac334fb8fc;
          uVar22 = (ulonglong)_DAT_2ac334fb8fc;
          if ((uVar22 != 0) || (local_144 == 0)) {
            if (local_144 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb8fc;
            }
            else {
              uVar23 = *(uint *)(local_144 + -4);
              uVar19 = _DAT_2ac334fb8fc + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_148,uVar20);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_144 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_144 + -0x2ac334fb900 + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb908);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb900 + uVar21);
                    puVar2[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e8a72;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb900 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e8a72:
              *(uint *)(local_144 + -4) = uVar19;
              *(undefined2 *)(local_144 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_2ac334e8a87;
            }
            goto LAB_2ac334ebe50;
          }
LAB_2ac334e8a87:
          FUN_2ac334d0af0(&local_158,&local_148,0);
          lVar14 = local_104;
          if (local_104 != 0) {
            uVar5 = *(uint *)(local_104 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e8c5e;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e8c42;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e8c42:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e8c5e;
            }
            goto LAB_2ac334ebe90;
          }
LAB_2ac334e8c5e:
          FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe620);
          uVar5 = _DAT_2ac334fb948;
          uVar22 = (ulonglong)_DAT_2ac334fb948;
          if ((uVar22 != 0) || (local_164 == 0)) {
            if (local_164 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb948;
            }
            else {
              uVar23 = *(uint *)(local_164 + -4);
              uVar19 = _DAT_2ac334fb948 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_168,uVar20);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_164 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_164 + -0x2ac334fb94c + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb954);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb94c + uVar21);
                    puVar2[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e8d92;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb94c + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e8d92:
              *(uint *)(local_164 + -4) = uVar19;
              *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_2ac334e8da7;
            }
            goto LAB_2ac334ebe70;
          }
LAB_2ac334e8da7:
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)_DAT_2ac33505c10,0,0x20);
          FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fe630);
          FUN_2ac334d0af0(&local_118,&local_168,0);
          lVar14 = local_134;
          if (local_134 == 0) {
LAB_2ac334e8f3e:
            in_stack_fffffffffffffe78 = &local_118;
            goto LAB_2ac334e8f46;
          }
          uVar5 = *(uint *)(local_134 + -4);
          uVar22 = (ulonglong)uVar5;
          if ((uVar22 == 0) && (local_114 != 0)) goto LAB_2ac334e8f3e;
          if (local_114 == 0) {
            uVar18 = 0;
            uVar23 = uVar5;
          }
          else {
            uVar18 = (ulonglong)*(uint *)(local_114 + -4);
            uVar23 = uVar5 + *(uint *)(local_114 + -4);
          }
          cVar11 = FUN_2ac334d0100(&local_118);
          if (cVar11 != '\0') {
            if (uVar22 != 0) {
              lVar1 = local_114 + uVar18 * 2;
              if (uVar5 < 8) {
                uVar18 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar21 = 0;
                uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                do {
                  uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                  *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                  ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar18 == uVar22) goto LAB_2ac334e8f22;
              }
              do {
                *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar22 != uVar18);
            }
LAB_2ac334e8f22:
            *(uint *)(local_114 + -4) = uVar23;
            *(undefined2 *)(local_114 + (ulonglong)uVar23 * 2) = 0;
            iVar12 = local_13c;
            goto LAB_2ac334e8f3e;
          }
          goto LAB_2ac334ebeb0;
        }
        if (local_12a != '\0') {
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
          if (lVar14 == 0) goto LAB_2ac334ebd30;
          (*(code *)0x7ff63a107f70)(0x2ac301f9168,6);
          if (cVar10 == '\0') {
            (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_128,0,0x20);
            FUN_2ac334d0af0(&local_148,0x2ac33505c3c,1,0x2ac334fe650);
            FUN_2ac334d0af0(&local_158,0x2ac334fb5b8,0);
            lVar14 = local_144;
            if (local_144 == 0) {
LAB_2ac334e95fe:
              FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe670);
              uVar5 = _DAT_2ac334fb5d8;
              uVar22 = (ulonglong)_DAT_2ac334fb5d8;
              if ((uVar22 == 0) && (local_164 != 0)) {
LAB_2ac334e9747:
                uVar16 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
                in_stack_fffffffffffffe78 =
                     (undefined4 *)((ulonglong)in_stack_fffffffffffffe78 & 0xffffffff00000000);
                (*(code *)0x7ff63a0f48b0)
                          (0x2ac301f9168,uVar16,&local_168,9,in_stack_fffffffffffffe78);
                goto LAB_2ac334e978f;
              }
              if (local_164 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb5d8;
              }
              else {
                uVar23 = *(uint *)(local_164 + -4);
                uVar19 = _DAT_2ac334fb5d8 + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_168,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_164 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_164 + -0x2ac334fb5dc + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb5e4);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb5dc + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334e9732;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb5dc + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334e9732:
                *(uint *)(local_164 + -4) = uVar19;
                *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334e9747;
              }
              goto LAB_2ac334ebed0;
            }
            uVar5 = *(uint *)(local_144 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e95fe;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e95e2;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e95e2:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e95fe;
            }
            goto LAB_2ac334ec050;
          }
LAB_2ac334e978f:
          dVar7 = _DAT_2ac33505c48;
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
          if (lVar14 == 0) goto LAB_2ac334ebd10;
          (*(code *)0x7ff63a107f70)(0x2ac301f9168,7);
          if (cVar9 == '\0') {
            (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_128,0,0x20);
            FUN_2ac334d0af0(&local_148,0x2ac33505c3c,1,0x2ac334fe680);
            FUN_2ac334d0af0(&local_158,0x2ac334fb5b8,0);
            lVar14 = local_144;
            if (local_144 == 0) {
LAB_2ac334e994e:
              FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe6a0);
              uVar5 = _DAT_2ac334fb5f8;
              uVar22 = (ulonglong)_DAT_2ac334fb5f8;
              if ((uVar22 == 0) && (local_164 != 0)) {
LAB_2ac334e9a97:
                uVar16 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
                in_stack_fffffffffffffe78 =
                     (undefined4 *)((ulonglong)in_stack_fffffffffffffe78 & 0xffffffff00000000);
                (*(code *)0x7ff63a0f48b0)
                          (0x2ac301f9168,uVar16,&local_168,9,in_stack_fffffffffffffe78);
                goto LAB_2ac334e9ae4;
              }
              if (local_164 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb5f8;
              }
              else {
                uVar23 = *(uint *)(local_164 + -4);
                uVar19 = _DAT_2ac334fb5f8 + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_168,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_164 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_164 + -0x2ac334fb5fc + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb604);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb5fc + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334e9a82;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb5fc + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334e9a82:
                *(uint *)(local_164 + -4) = uVar19;
                *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334e9a97;
              }
              goto LAB_2ac334ebef0;
            }
            uVar5 = *(uint *)(local_144 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e994e;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e9932;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e9932:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e994e;
            }
            goto LAB_2ac334ec070;
          }
LAB_2ac334e9ae4:
          if ((cVar10 != '\0' || dVar7 == 0.0) && (cVar9 != '\0' || _DAT_2ac33505c48 == 0.0)) {
LAB_2ac334e8f7f:
            if (local_129 == '\0') goto LAB_2ac334e8f8a;
            goto LAB_2ac334e7ede;
          }
          _DAT_2ac33505c10 = 0;
          _DAT_2ac33505c80 = 0;
          DAT_2ac33505c88 = 0;
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
          if (lVar14 == 0) goto LAB_2ac334ebdd0;
          cVar11 = FUN_2ac334e60c0(lVar14,local_128);
          if (cVar11 != '\0') {
            FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe6b0);
            uVar5 = _DAT_2ac334fb8fc;
            uVar22 = (ulonglong)_DAT_2ac334fb8fc;
            if ((uVar22 != 0) || (local_144 == 0)) {
              if (local_144 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb8fc;
              }
              else {
                uVar23 = *(uint *)(local_144 + -4);
                uVar19 = _DAT_2ac334fb8fc + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_148,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_144 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_144 + -0x2ac334fb900 + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb908);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb900 + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334e9de2;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb900 + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334e9de2:
                *(uint *)(local_144 + -4) = uVar19;
                *(undefined2 *)(local_144 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334e9df7;
              }
              goto LAB_2ac334ebf90;
            }
LAB_2ac334e9df7:
            FUN_2ac334d0af0(&local_158,&local_148,0);
            lVar14 = local_104;
            if (local_104 == 0) {
LAB_2ac334e9f3e:
              FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe6d0);
              uVar5 = _DAT_2ac334fb988;
              uVar22 = (ulonglong)_DAT_2ac334fb988;
              if ((uVar22 == 0) && (local_164 != 0)) {
LAB_2ac334ea087:
                in_stack_fffffffffffffe78 = &local_168;
                (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,in_stack_fffffffffffffe78);
                FUN_2ac334f48b0(local_128);
                goto LAB_2ac334e8f7f;
              }
              if (local_164 == 0) {
                uVar23 = 0;
                uVar19 = _DAT_2ac334fb988;
              }
              else {
                uVar23 = *(uint *)(local_164 + -4);
                uVar19 = _DAT_2ac334fb988 + uVar23;
              }
              uVar20 = 0x104;
              if ((0x103 < uVar19) &&
                 ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20))))
              {
                uVar20 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_168,uVar20);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_164 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_164 + -0x2ac334fb98c + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb994);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb98c + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334ea072;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb98c + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334ea072:
                *(uint *)(local_164 + -4) = uVar19;
                *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
                goto LAB_2ac334ea087;
              }
              goto LAB_2ac334ebfb0;
            }
            uVar5 = *(uint *)(local_104 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e9f3e;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e9f22;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e9f22:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e9f3e;
            }
            goto LAB_2ac334ec090;
          }
          FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe6e0);
          uVar5 = _DAT_2ac334fb8fc;
          uVar22 = (ulonglong)_DAT_2ac334fb8fc;
          if ((uVar22 != 0) || (local_144 == 0)) {
            if (local_144 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb8fc;
            }
            else {
              uVar23 = *(uint *)(local_144 + -4);
              uVar19 = _DAT_2ac334fb8fc + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_148,uVar20);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_144 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_144 + -0x2ac334fb900 + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb908);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb900 + uVar21);
                    puVar2[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ea112;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb900 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ea112:
              *(uint *)(local_144 + -4) = uVar19;
              *(undefined2 *)(local_144 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_2ac334ea127;
            }
            goto LAB_2ac334ec0b0;
          }
LAB_2ac334ea127:
          FUN_2ac334d0af0(&local_158,&local_148,0);
          lVar14 = local_104;
          if (local_104 != 0) {
            uVar5 = *(uint *)(local_104 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334ea39e;
            if (local_154 == 0) {
              uVar23 = 0;
            }
            else {
              uVar23 = *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ea382;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ea382:
              *(uint *)(local_154 + -4) = uVar5 + uVar23;
              *(undefined2 *)(local_154 + (ulonglong)(uVar5 + uVar23) * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334ea39e;
            }
            goto LAB_2ac334ec130;
          }
LAB_2ac334ea39e:
          FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe700);
          uVar5 = _DAT_2ac334fb9c8;
          uVar22 = (ulonglong)_DAT_2ac334fb9c8;
          if ((uVar22 != 0) || (local_164 == 0)) {
            if (local_164 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb9c8;
            }
            else {
              uVar23 = *(uint *)(local_164 + -4);
              uVar19 = _DAT_2ac334fb9c8 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_168,uVar20);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_164 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_164 + -0x2ac334fb9cc + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb9d4);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb9cc + uVar21);
                    puVar2[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ea4d2;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb9cc + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ea4d2:
              *(uint *)(local_164 + -4) = uVar19;
              *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_2ac334ea4e7;
            }
            goto LAB_2ac334ec0d0;
          }
LAB_2ac334ea4e7:
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)_DAT_2ac33505c10,0,0x20);
          FUN_2ac334d0af0(&local_138,0x2ac33505c3c,1,0x2ac334fe710);
          FUN_2ac334d0af0(&local_118,&local_168,0);
          lVar14 = local_134;
          if (local_134 == 0) goto LAB_2ac334e8f3e;
          uVar5 = *(uint *)(local_134 + -4);
          uVar22 = (ulonglong)uVar5;
          if ((uVar22 == 0) && (local_114 != 0)) goto LAB_2ac334e8f3e;
          if (local_114 == 0) {
            uVar19 = 0;
          }
          else {
            uVar19 = *(uint *)(local_114 + -4);
          }
          uVar23 = uVar5 + uVar19;
          cVar11 = FUN_2ac334d0100(&local_118);
          if (cVar11 != '\0') {
            if (uVar22 != 0) {
              lVar1 = local_114 + (ulonglong)uVar19 * 2;
              if (uVar5 < 8) {
                uVar18 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar21 = 0;
                uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                do {
                  uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                  *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                  ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar18 == uVar22) goto LAB_2ac334e8f22;
              }
              do {
                *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar22 != uVar18);
            }
            goto LAB_2ac334e8f22;
          }
          goto LAB_2ac334ec150;
        }
LAB_2ac334e8f8a:
        lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
        if (lVar14 == 0) goto LAB_2ac334ebc90;
        uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,2);
        if (cVar10 != '\0') {
          local_f8 = 0;
          local_f4 = 0;
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_128,0,0x20);
          FUN_2ac334d0af0(&local_148,0x2ac33505c3c,1,0x2ac334fe730);
          FUN_2ac334d0af0(&local_158,0x2ac334fb5b8,0);
          lVar14 = local_144;
          if (local_144 != 0) {
            uVar5 = *(uint *)(local_144 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334e915e;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar15 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar15;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334e9142;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334e9142:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334e915e;
            }
            goto LAB_2ac334ebdf0;
          }
LAB_2ac334e915e:
          FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe750);
          uVar5 = _DAT_2ac334fb5d8;
          uVar22 = (ulonglong)_DAT_2ac334fb5d8;
          if ((uVar22 != 0) || (local_164 == 0)) {
            if (local_164 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb5d8;
            }
            else {
              uVar23 = *(uint *)(local_164 + -4);
              uVar19 = _DAT_2ac334fb5d8 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_168,uVar20);
            if (cVar11 == '\0') goto LAB_2ac334ebd50;
            if (uVar22 != 0) {
              lVar14 = local_164 + (ulonglong)uVar23 * 2;
              if (uVar5 < 8) {
                uVar18 = 0;
              }
              else if (local_164 + -0x2ac334fb5dc + (ulonglong)uVar23 * 2 < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar21 = 0;
                uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                do {
                  uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb5e4);
                  puVar2 = (undefined8 *)(lVar14 + uVar21);
                  *puVar2 = *(undefined8 *)(&DAT_2ac334fb5dc + uVar21);
                  puVar2[1] = uVar15;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar18 == uVar22) goto LAB_2ac334e9292;
              }
              do {
                *(undefined2 *)(lVar14 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_2ac334fb5dc + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar22 != uVar18);
            }
LAB_2ac334e9292:
            *(uint *)(local_164 + -4) = uVar19;
            *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
          }
          FUN_2ac334d0af0(&local_f8,&local_168,0,0x2ac334fe760);
          uVar15 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
          iVar13 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,uVar15,&local_f8);
          if (iVar13 < 0) {
LAB_2ac334ead4a:
            FUN_2ac334d00a0(&local_f8);
            goto LAB_2ac334ead5e;
          }
          uVar15 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
          in_stack_fffffffffffffe78 =
               (undefined4 *)((ulonglong)in_stack_fffffffffffffe78 & 0xffffffff00000000);
          (*(code *)0x7ff63a0f48b0)(0x2ac301f9168,uVar15,&local_f8,9,in_stack_fffffffffffffe78);
          if ((int)uVar16 != 1) {
            if (((int)uVar16 != 0) || (_DAT_2ac33505c48 < param_2)) goto LAB_2ac334ead4a;
            _DAT_2ac33505c10 = 0;
            _DAT_2ac33505c80 = 0;
            DAT_2ac33505c88 = 0;
            local_d8 = uVar16;
            lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
            if (lVar14 == 0) goto LAB_2ac334ebf30;
            uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
            lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
            if (lVar14 == 0) goto LAB_2ac334ebf10;
            cVar11 = FUN_2ac334f0d20(lVar14,uVar16);
            if (cVar11 != '\0') goto LAB_2ac334e7e77;
            local_11c = _DAT_2ac33505c10;
            FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe770);
            uVar16 = local_d8;
            uVar5 = _DAT_2ac334fb548;
            uVar22 = (ulonglong)_DAT_2ac334fb548;
            if ((uVar22 != 0) || (local_144 == 0)) {
              if (local_144 == 0) {
                uVar23 = 0;
              }
              else {
                uVar23 = *(uint *)(local_144 + -4);
              }
              uVar20 = _DAT_2ac334fb548 + uVar23;
              uVar19 = 0x104;
              if ((0x103 < uVar20) &&
                 ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19))))
              {
                uVar19 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_148,uVar19);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_144 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_144 + -0x2ac334fb54c + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb554);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb54c + uVar21);
                      puVar2[1] = uVar15;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334ea6a2;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb54c + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
LAB_2ac334ea6a2:
                *(uint *)(local_144 + -4) = uVar20;
                *(undefined2 *)(local_144 + (ulonglong)uVar20 * 2) = 0;
                goto LAB_2ac334ea6b7;
              }
              goto LAB_2ac334ec1b0;
            }
LAB_2ac334ea6b7:
            lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
            if (lVar14 == 0) goto LAB_2ac334ec0f0;
            uVar15 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
            (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,uVar15,0,0x20);
            FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334fe780);
            FUN_2ac334d0af0(&local_168,&local_148,0);
            lVar14 = local_154;
            if (local_154 == 0) {
LAB_2ac334ea9de:
              FUN_2ac334d0af0(&local_138,&local_168,0,0x2ac334fe7a0);
              uVar5 = _DAT_2ac334fb588;
              uVar22 = (ulonglong)_DAT_2ac334fb588;
              if ((uVar22 == 0) && (local_134 != 0)) goto LAB_2ac334ead13;
              if (local_134 == 0) {
                uVar23 = 0;
              }
              else {
                uVar23 = *(uint *)(local_134 + -4);
              }
              uVar20 = _DAT_2ac334fb588 + uVar23;
              uVar19 = 0x104;
              if ((0x103 < uVar20) &&
                 ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19))))
              {
                uVar19 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_138,uVar19);
              if (cVar11 != '\0') {
                if (uVar22 != 0) {
                  lVar14 = local_134 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_134 + -0x2ac334fb58c + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb594);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb58c + uVar21);
                      puVar2[1] = uVar15;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334eacf2;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb58c + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
                goto LAB_2ac334eacf2;
              }
              goto LAB_2ac334ec1d0;
            }
            uVar5 = *(uint *)(local_154 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_164 != 0)) goto LAB_2ac334ea9de;
            if (local_164 == 0) {
              uVar23 = 0;
            }
            else {
              uVar23 = *(uint *)(local_164 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_168);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_164 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar15 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar15;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ea9c2;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ea9c2:
              *(uint *)(local_164 + -4) = uVar5 + uVar23;
              *(undefined2 *)(local_164 + (ulonglong)(uVar5 + uVar23) * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334ea9de;
            }
            goto LAB_2ac334ec2b0;
          }
          if (param_1 < _DAT_2ac33505c48) goto LAB_2ac334ead4a;
          _DAT_2ac33505c10 = 0;
          _DAT_2ac33505c80 = 0;
          DAT_2ac33505c88 = 0;
          local_d8 = uVar16;
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
          if (lVar14 == 0) goto LAB_2ac334ebf70;
          uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
          if (lVar14 == 0) goto LAB_2ac334ebf50;
          cVar11 = FUN_2ac334f0d20(lVar14,uVar16);
          if (cVar11 != '\0') {
LAB_2ac334e7e77:
            in_stack_fffffffffffffe78 = (undefined4 *)0x2ac334fba40;
            (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fba40);
            FUN_2ac334f48b0(local_128);
            puVar17 = &local_f8;
            goto LAB_2ac334e7ecc;
          }
          local_11c = _DAT_2ac33505c10;
          FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe7b0);
          uVar16 = local_d8;
          uVar5 = _DAT_2ac334fb548;
          uVar22 = (ulonglong)_DAT_2ac334fb548;
          if ((uVar22 != 0) || (local_144 == 0)) {
            if (local_144 == 0) {
              uVar23 = 0;
            }
            else {
              uVar23 = *(uint *)(local_144 + -4);
            }
            uVar20 = _DAT_2ac334fb548 + uVar23;
            uVar19 = 0x104;
            if ((0x103 < uVar20) &&
               ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19)))) {
              uVar19 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_148,uVar19);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_144 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_144 + -0x2ac334fb54c + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb554);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb54c + uVar21);
                    puVar2[1] = uVar15;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ea832;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb54c + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ea832:
              *(uint *)(local_144 + -4) = uVar20;
              *(undefined2 *)(local_144 + (ulonglong)uVar20 * 2) = 0;
              goto LAB_2ac334ea847;
            }
            goto LAB_2ac334ec1f0;
          }
LAB_2ac334ea847:
          lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
          if (lVar14 == 0) goto LAB_2ac334ec110;
          uVar15 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,uVar15,0,0x20);
          FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334fe7c0);
          FUN_2ac334d0af0(&local_168,&local_148,0);
          lVar14 = local_154;
          if (local_154 == 0) {
LAB_2ac334eab8e:
            FUN_2ac334d0af0(&local_138,&local_168,0,0x2ac334fe7e0);
            uVar5 = _DAT_2ac334fb588;
            uVar22 = (ulonglong)_DAT_2ac334fb588;
            if ((uVar22 == 0) && (local_134 != 0)) {
LAB_2ac334ead13:
              in_stack_fffffffffffffe78 = &local_138;
              (*(code *)0x7ff63a0e49f0)
                        (0x2ac301f9168,2,2,0x590008,in_stack_fffffffffffffe78,0x520004,local_11c);
              goto LAB_2ac334ead4a;
            }
            if (local_134 == 0) {
              uVar23 = 0;
            }
            else {
              uVar23 = *(uint *)(local_134 + -4);
            }
            uVar20 = _DAT_2ac334fb588 + uVar23;
            uVar19 = 0x104;
            if ((0x103 < uVar20) &&
               ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19)))) {
              uVar19 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_138,uVar19);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar14 = local_134 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_134 + -0x2ac334fb58c + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb594);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb58c + uVar21);
                    puVar2[1] = uVar15;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334eacf2;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb58c + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334eacf2:
              *(uint *)(local_134 + -4) = uVar20;
              *(undefined2 *)(local_134 + (ulonglong)uVar20 * 2) = 0;
              goto LAB_2ac334ead13;
            }
            goto LAB_2ac334ec210;
          }
          uVar5 = *(uint *)(local_154 + -4);
          uVar22 = (ulonglong)uVar5;
          if ((uVar22 == 0) && (local_164 != 0)) goto LAB_2ac334eab8e;
          if (local_164 == 0) {
            uVar23 = 0;
          }
          else {
            uVar23 = *(uint *)(local_164 + -4);
          }
          cVar11 = FUN_2ac334d0100(&local_168);
          if (cVar11 != '\0') {
            if (uVar22 != 0) {
              lVar1 = local_164 + (ulonglong)uVar23 * 2;
              if (uVar5 < 8) {
                uVar18 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar21 = 0;
                uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                do {
                  uVar15 = ((undefined8 *)(lVar14 + uVar21))[1];
                  *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                  ((undefined8 *)(lVar1 + uVar21))[1] = uVar15;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar18 == uVar22) goto LAB_2ac334eab72;
              }
              do {
                *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar22 != uVar18);
            }
LAB_2ac334eab72:
            *(uint *)(local_164 + -4) = uVar5 + uVar23;
            *(undefined2 *)(local_164 + (ulonglong)(uVar5 + uVar23) * 2) = 0;
            iVar12 = local_13c;
            goto LAB_2ac334eab8e;
          }
          goto LAB_2ac334ec2d0;
        }
LAB_2ac334ead5e:
        if (cVar9 != '\0') {
          local_e8 = 0;
          local_e4 = 0;
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,local_128,0,0x20);
          FUN_2ac334d0af0(&local_148,0x2ac33505c3c,1,0x2ac334fe7f0);
          FUN_2ac334d0af0(&local_158,0x2ac334fb5b8,0);
          lVar14 = local_144;
          if (local_144 != 0) {
            uVar5 = *(uint *)(local_144 + -4);
            uVar22 = (ulonglong)uVar5;
            if ((uVar22 == 0) && (local_154 != 0)) goto LAB_2ac334eaefe;
            if (local_154 == 0) {
              uVar18 = 0;
              uVar23 = uVar5;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_154 + -4);
              uVar23 = uVar5 + *(uint *)(local_154 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_158);
            if (cVar11 != '\0') {
              if (uVar22 != 0) {
                lVar1 = local_154 + uVar18 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar15 = ((undefined8 *)(lVar14 + uVar21))[1];
                    *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                    ((undefined8 *)(lVar1 + uVar21))[1] = uVar15;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334eaee2;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334eaee2:
              *(uint *)(local_154 + -4) = uVar23;
              *(undefined2 *)(local_154 + (ulonglong)uVar23 * 2) = 0;
              iVar12 = local_13c;
              goto LAB_2ac334eaefe;
            }
            goto LAB_2ac334ebe10;
          }
LAB_2ac334eaefe:
          FUN_2ac334d0af0(&local_168,&local_158,0,0x2ac334fe810);
          uVar5 = _DAT_2ac334fb5f8;
          uVar22 = (ulonglong)_DAT_2ac334fb5f8;
          if ((uVar22 != 0) || (local_164 == 0)) {
            if (local_164 == 0) {
              uVar23 = 0;
              uVar19 = _DAT_2ac334fb5f8;
            }
            else {
              uVar23 = *(uint *)(local_164 + -4);
              uVar19 = _DAT_2ac334fb5f8 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar20 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_168,uVar20);
            if (cVar11 == '\0') goto LAB_2ac334ebd70;
            if (uVar22 != 0) {
              lVar14 = local_164 + (ulonglong)uVar23 * 2;
              if (uVar5 < 8) {
                uVar18 = 0;
              }
              else if (local_164 + -0x2ac334fb5fc + (ulonglong)uVar23 * 2 < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar21 = 0;
                uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                do {
                  uVar15 = *(undefined8 *)(uVar21 + 0x2ac334fb604);
                  puVar2 = (undefined8 *)(lVar14 + uVar21);
                  *puVar2 = *(undefined8 *)(&DAT_2ac334fb5fc + uVar21);
                  puVar2[1] = uVar15;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar18 == uVar22) goto LAB_2ac334eb032;
              }
              do {
                *(undefined2 *)(lVar14 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_2ac334fb5fc + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar22 != uVar18);
            }
LAB_2ac334eb032:
            *(uint *)(local_164 + -4) = uVar19;
            *(undefined2 *)(local_164 + (ulonglong)uVar19 * 2) = 0;
          }
          puVar17 = &local_e8;
          FUN_2ac334d0af0(puVar17,&local_168,0,0x2ac334fe820);
          uVar15 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
          iVar13 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,uVar15,puVar17);
          if (-1 < iVar13) {
            uVar15 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
            in_stack_fffffffffffffe78 =
                 (undefined4 *)((ulonglong)in_stack_fffffffffffffe78 & 0xffffffff00000000);
            (*(code *)0x7ff63a0f48b0)(0x2ac301f9168,uVar15,puVar17,9,in_stack_fffffffffffffe78);
            if ((int)uVar16 == 1) {
              if (_DAT_2ac33505c48 < param_1) goto LAB_2ac334e7ecc;
              _DAT_2ac33505c10 = 0;
              _DAT_2ac33505c80 = 0;
              DAT_2ac33505c88 = 0;
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
              if (lVar14 == 0) goto LAB_2ac334ec030;
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
              if (lVar14 == 0) goto LAB_2ac334ec010;
              cVar11 = FUN_2ac334f0d20(lVar14,uVar16);
              iVar13 = _DAT_2ac33505c10;
              if (cVar11 != '\0') goto LAB_2ac334eb29c;
              FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe870);
              uVar5 = _DAT_2ac334fb548;
              uVar22 = (ulonglong)_DAT_2ac334fb548;
              if ((uVar22 != 0) || (local_144 == 0)) {
                if (local_144 == 0) {
                  uVar23 = 0;
                }
                else {
                  uVar23 = *(uint *)(local_144 + -4);
                }
                uVar20 = _DAT_2ac334fb548 + uVar23;
                uVar19 = 0x104;
                if ((0x103 < uVar20) &&
                   ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19)))
                   ) {
                  uVar19 = 0x7ffffffe;
                }
                cVar11 = FUN_2ac334d0100(&local_148,uVar19);
                if (cVar11 != '\0') {
                  if (uVar22 != 0) {
                    lVar14 = local_144 + (ulonglong)uVar23 * 2;
                    if (uVar5 < 8) {
                      uVar18 = 0;
                    }
                    else if (local_144 + -0x2ac334fb54c + (ulonglong)uVar23 * 2 < 0x20) {
                      uVar18 = 0;
                    }
                    else {
                      uVar21 = 0;
                      uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                      do {
                        uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb554);
                        puVar2 = (undefined8 *)(lVar14 + uVar21);
                        *puVar2 = *(undefined8 *)(&DAT_2ac334fb54c + uVar21);
                        puVar2[1] = uVar16;
                        uVar21 = uVar21 + 0x10;
                      } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                      if (uVar18 == uVar22) goto LAB_2ac334eb652;
                    }
                    do {
                      *(undefined2 *)(lVar14 + uVar18 * 2) =
                           *(undefined2 *)(&DAT_2ac334fb54c + uVar18 * 2);
                      uVar18 = uVar18 + 1;
                    } while (uVar22 != uVar18);
                  }
LAB_2ac334eb652:
                  *(uint *)(local_144 + -4) = uVar20;
                  *(undefined2 *)(local_144 + (ulonglong)uVar20 * 2) = 0;
                  goto LAB_2ac334eb667;
                }
                goto LAB_2ac334ec270;
              }
LAB_2ac334eb667:
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
              if (lVar14 == 0) goto LAB_2ac334ec190;
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,uVar16,0,0x20);
              FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334fe880);
              FUN_2ac334d0af0(&local_168,&local_148,0);
              lVar14 = local_154;
              if (local_154 != 0) {
                uVar5 = *(uint *)(local_154 + -4);
                uVar22 = (ulonglong)uVar5;
                if ((uVar22 != 0) || (local_164 == 0)) {
                  if (local_164 == 0) {
                    uVar23 = 0;
                  }
                  else {
                    uVar23 = *(uint *)(local_164 + -4);
                  }
                  cVar11 = FUN_2ac334d0100(&local_168);
                  if (cVar11 == '\0') goto LAB_2ac334ec310;
                  if (uVar22 != 0) {
                    lVar1 = local_164 + (ulonglong)uVar23 * 2;
                    if (uVar5 < 8) {
                      uVar18 = 0;
                    }
                    else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                      uVar18 = 0;
                    }
                    else {
                      uVar21 = 0;
                      uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                      do {
                        uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                        *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                        ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                        uVar21 = uVar21 + 0x10;
                      } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                      if (uVar18 == uVar22) goto LAB_2ac334eb992;
                    }
                    do {
                      *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                      uVar18 = uVar18 + 1;
                    } while (uVar22 != uVar18);
                  }
LAB_2ac334eb992:
                  *(uint *)(local_164 + -4) = uVar5 + uVar23;
                  *(undefined2 *)(local_164 + (ulonglong)(uVar5 + uVar23) * 2) = 0;
                  iVar12 = local_13c;
                }
              }
              FUN_2ac334d0af0(&local_138,&local_168,0,0x2ac334fe8a0);
              uVar5 = _DAT_2ac334fb588;
              uVar22 = (ulonglong)_DAT_2ac334fb588;
              if ((uVar22 != 0) || (local_134 == 0)) {
                if (local_134 == 0) {
                  uVar23 = 0;
                }
                else {
                  uVar23 = *(uint *)(local_134 + -4);
                }
                uVar20 = _DAT_2ac334fb588 + uVar23;
                uVar19 = 0x104;
                if ((0x103 < uVar20) &&
                   ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19)))
                   ) {
                  uVar19 = 0x7ffffffe;
                }
                cVar11 = FUN_2ac334d0100(&local_138,uVar19);
                if (cVar11 == '\0') goto LAB_2ac334ec290;
                if (uVar22 != 0) {
                  lVar14 = local_134 + (ulonglong)uVar23 * 2;
                  if (uVar5 < 8) {
                    uVar18 = 0;
                  }
                  else if (local_134 + -0x2ac334fb58c + (ulonglong)uVar23 * 2 < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb594);
                      puVar2 = (undefined8 *)(lVar14 + uVar21);
                      *puVar2 = *(undefined8 *)(&DAT_2ac334fb58c + uVar21);
                      puVar2[1] = uVar16;
                      uVar21 = uVar21 + 0x10;
                    } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                    if (uVar18 == uVar22) goto LAB_2ac334ebaf2;
                  }
                  do {
                    *(undefined2 *)(lVar14 + uVar18 * 2) =
                         *(undefined2 *)(&DAT_2ac334fb58c + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar22 != uVar18);
                }
                goto LAB_2ac334ebaf2;
              }
            }
            else {
              if (((int)uVar16 != 0) || (param_2 < _DAT_2ac33505c48)) goto LAB_2ac334e7ecc;
              _DAT_2ac33505c10 = 0;
              _DAT_2ac33505c80 = 0;
              DAT_2ac33505c88 = 0;
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
              if (lVar14 == 0) goto LAB_2ac334ebff0;
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af8);
              if (lVar14 == 0) goto LAB_2ac334ebfd0;
              cVar11 = FUN_2ac334f0d20(lVar14,uVar16);
              iVar13 = _DAT_2ac33505c10;
              if (cVar11 != '\0') {
LAB_2ac334eb29c:
                in_stack_fffffffffffffe78 = (undefined4 *)0x2ac334fba90;
                (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fba90);
                FUN_2ac334f48b0(local_128);
                puVar17 = &local_e8;
                goto LAB_2ac334e7ecc;
              }
              FUN_2ac334d0af0(&local_148,0x2ac33505c28,0,0x2ac334fe830);
              uVar5 = _DAT_2ac334fb548;
              uVar22 = (ulonglong)_DAT_2ac334fb548;
              if ((uVar22 != 0) || (local_144 == 0)) {
                if (local_144 == 0) {
                  uVar23 = 0;
                }
                else {
                  uVar23 = *(uint *)(local_144 + -4);
                }
                uVar20 = _DAT_2ac334fb548 + uVar23;
                uVar19 = 0x104;
                if ((0x103 < uVar20) &&
                   ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19)))
                   ) {
                  uVar19 = 0x7ffffffe;
                }
                cVar11 = FUN_2ac334d0100(&local_148,uVar19);
                if (cVar11 != '\0') {
                  if (uVar22 != 0) {
                    lVar14 = local_144 + (ulonglong)uVar23 * 2;
                    if (uVar5 < 8) {
                      uVar18 = 0;
                    }
                    else if (local_144 + -0x2ac334fb54c + (ulonglong)uVar23 * 2 < 0x20) {
                      uVar18 = 0;
                    }
                    else {
                      uVar21 = 0;
                      uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                      do {
                        uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb554);
                        puVar2 = (undefined8 *)(lVar14 + uVar21);
                        *puVar2 = *(undefined8 *)(&DAT_2ac334fb54c + uVar21);
                        puVar2[1] = uVar16;
                        uVar21 = uVar21 + 0x10;
                      } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                      if (uVar18 == uVar22) goto LAB_2ac334eb4c2;
                    }
                    do {
                      *(undefined2 *)(lVar14 + uVar18 * 2) =
                           *(undefined2 *)(&DAT_2ac334fb54c + uVar18 * 2);
                      uVar18 = uVar18 + 1;
                    } while (uVar22 != uVar18);
                  }
LAB_2ac334eb4c2:
                  *(uint *)(local_144 + -4) = uVar20;
                  *(undefined2 *)(local_144 + (ulonglong)uVar20 * 2) = 0;
                  goto LAB_2ac334eb4d7;
                }
                goto LAB_2ac334ec230;
              }
LAB_2ac334eb4d7:
              lVar14 = (*(code *)0x7ff63a0e6410)(0x2ac301f9168,_DAT_2ac33505af0);
              if (lVar14 == 0) goto LAB_2ac334ec170;
              uVar16 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168,0x11);
              (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,uVar16,0,0x20);
              FUN_2ac334d0af0(&local_158,0x2ac33505c3c,1,0x2ac334fe840);
              FUN_2ac334d0af0(&local_168,&local_148,0);
              lVar14 = local_154;
              if (local_154 != 0) {
                uVar5 = *(uint *)(local_154 + -4);
                uVar22 = (ulonglong)uVar5;
                if ((uVar22 == 0) && (local_164 != 0)) goto LAB_2ac334eb7fe;
                if (local_164 == 0) {
                  uVar23 = 0;
                }
                else {
                  uVar23 = *(uint *)(local_164 + -4);
                }
                cVar11 = FUN_2ac334d0100(&local_168);
                if (cVar11 != '\0') {
                  if (uVar22 != 0) {
                    lVar1 = local_164 + (ulonglong)uVar23 * 2;
                    if (uVar5 < 8) {
                      uVar18 = 0;
                    }
                    else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
                      uVar18 = 0;
                    }
                    else {
                      uVar21 = 0;
                      uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                      do {
                        uVar16 = ((undefined8 *)(lVar14 + uVar21))[1];
                        *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar14 + uVar21);
                        ((undefined8 *)(lVar1 + uVar21))[1] = uVar16;
                        uVar21 = uVar21 + 0x10;
                      } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                      if (uVar18 == uVar22) goto LAB_2ac334eb7e2;
                    }
                    do {
                      *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar14 + uVar18 * 2);
                      uVar18 = uVar18 + 1;
                    } while (uVar22 != uVar18);
                  }
LAB_2ac334eb7e2:
                  *(uint *)(local_164 + -4) = uVar5 + uVar23;
                  *(undefined2 *)(local_164 + (ulonglong)(uVar5 + uVar23) * 2) = 0;
                  iVar12 = local_13c;
                  goto LAB_2ac334eb7fe;
                }
                goto LAB_2ac334ec2f0;
              }
LAB_2ac334eb7fe:
              FUN_2ac334d0af0(&local_138,&local_168,0,0x2ac334fe860);
              uVar5 = _DAT_2ac334fb588;
              uVar22 = (ulonglong)_DAT_2ac334fb588;
              if ((uVar22 == 0) && (local_134 != 0)) goto LAB_2ac334ebaff;
              if (local_134 == 0) {
                uVar23 = 0;
              }
              else {
                uVar23 = *(uint *)(local_134 + -4);
              }
              uVar20 = _DAT_2ac334fb588 + uVar23;
              uVar19 = 0x104;
              if ((0x103 < uVar20) &&
                 ((0x7ffffffd < uVar20 || (uVar19 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar19))))
              {
                uVar19 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_138,uVar19);
              if (cVar11 == '\0') goto LAB_2ac334ec250;
              if (uVar22 != 0) {
                lVar14 = local_134 + (ulonglong)uVar23 * 2;
                if (uVar5 < 8) {
                  uVar18 = 0;
                }
                else if (local_134 + -0x2ac334fb58c + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar18 = (ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    uVar16 = *(undefined8 *)(uVar21 + 0x2ac334fb594);
                    puVar2 = (undefined8 *)(lVar14 + uVar21);
                    *puVar2 = *(undefined8 *)(&DAT_2ac334fb58c + uVar21);
                    puVar2[1] = uVar16;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar18 == uVar22) goto LAB_2ac334ebaf2;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) =
                       *(undefined2 *)(&DAT_2ac334fb58c + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar22 != uVar18);
              }
LAB_2ac334ebaf2:
              *(uint *)(local_134 + -4) = uVar20;
              *(undefined2 *)(local_134 + (ulonglong)uVar20 * 2) = 0;
            }
LAB_2ac334ebaff:
            in_stack_fffffffffffffe78 = &local_138;
            (*(code *)0x7ff63a0e49f0)
                      (0x2ac301f9168,2,2,0x590008,in_stack_fffffffffffffe78,0x520004,iVar13);
            puVar17 = &local_e8;
          }
LAB_2ac334e7ecc:
          FUN_2ac334d00a0(puVar17);
        }
LAB_2ac334e7ede:
        FUN_2ac334d00a0(&local_108);
      }
      else if ((local_cc != 0) && (_DAT_2ac33505c2c != 0)) {
        uVar5 = *(uint *)(local_cc + -4);
        uVar23 = *(uint *)(_DAT_2ac33505c2c + -4);
        uVar19 = uVar23;
        if (uVar5 < uVar23) {
          uVar19 = uVar5;
        }
        iVar13 = uVar5 - uVar23;
        if (uVar19 != 0) {
          uVar22 = 1;
          do {
            uVar3 = *(ushort *)(local_cc + -2 + uVar22 * 2);
            uVar4 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar22 * 2);
            if (uVar19 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar13 = (uint)uVar3 - (uint)uVar4;
          }
        }
        if (iVar13 == 0) goto LAB_2ac334e80cf;
      }
LAB_2ac334e7f00:
      iVar12 = iVar12 + 1;
      iVar13 = (*(code *)0x7ff63a107da0)(0x2ac301f9168);
    } while (iVar12 < iVar13);
  }
  FUN_2ac334d00a0(&local_d0);
  FUN_2ac334d00a0(&local_148);
  FUN_2ac334d00a0(&local_158);
  FUN_2ac334d00a0(&local_168);
  FUN_2ac334d00a0(&local_138);
  FUN_2ac334d00a0(&local_118);
  return;
}



/* Address: 2ac334ebbd0 */

void FUN_2ac334ebbd0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x906cb000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xc06cc000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c06cc000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1906d1000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1906d0000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1b06cd000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1706eb000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1206d6000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4706d4000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4506d3000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2a06de000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2706dc000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3f06ee000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x42070a000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06d7000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b06d7000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1506e2000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2706ee000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2a070a000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2306d7000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2106d9000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2d06d9000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2506d9000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4306d9000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x6e06dd000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x7306df000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06f5000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3806f5000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f06ff000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3806ff000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2206e3000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e06e3000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f0710000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x380710000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f071a000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x38071a000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5606dd000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5b06df000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2606e3000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2406e6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3006e6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x5506f6000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x550700000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2806e6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4c06e6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x550711000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x55071b000001fa);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b06f6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x6906f6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b0700000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x690700000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b0711000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x690711000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b071b000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x69071b000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x4406f6000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x440700000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x440711000001f9);
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x44071b000001f9);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ac334ec340 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334ec340(int param_1,double param_2,undefined4 param_3,undefined8 param_4,
                    longlong param_5)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_64 = 0;
  local_74 = 0;
  dVar9 = (double)FUN_2ac334e5210();
  if (param_1 == 0) {
    if (DAT_2ac33505d50 != '\0') {
      dVar9 = (double)FUN_2ac334f4410(dVar9);
    }
  }
  else if ((DAT_2ac33505d60 == '\0') || (param_2 <= 0.0)) {
    if ((DAT_2ac33505d70 != '\0') && ((0.0 < param_2 && (_DAT_2ac33505d80 <= param_1)))) {
      dVar9 = param_2 + _DAT_2ac33505d78;
    }
  }
  else {
    dVar9 = param_2 * _DAT_2ac33505d68;
  }
  local_88 = 0;
  local_84 = 0;
  FUN_2ac334d0af0(&local_88,0x2ac33505c28,1,0x2ac334fdf28);
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x24);
  dVar10 = (double)(~-(ulonglong)(_DAT_2ac33505c48 == 0.0) & (ulonglong)_DAT_2ac33505c48 |
                   _DAT_2ac334f8c58 & -(ulonglong)(_DAT_2ac33505c48 == 0.0));
  dVar9 = dVar9 / dVar10;
  uVar6 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
  lVar7 = (ulonglong)uVar6 - 0x3ff;
  dVar11 = dVar9;
  if ((ulonglong)uVar6 < 0x433) {
    if (uVar6 < 0x3ff) {
      dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar7 != -1) {
        dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000);
      }
    }
    else {
      bVar5 = (byte)lVar7;
      if (((longlong)dVar9 << (bVar5 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar5 & 0x3f)) + (longlong)dVar9 &
                         -0x10000000000000 >> (bVar5 & 0x3f));
      }
    }
  }
  else if (lVar7 == 0x400) {
    dVar11 = dVar9 + dVar9;
  }
  dVar9 = (dVar11 * dVar10) / dVar10;
  if ((longlong)dVar9 != -0x8000000000000000) {
    dVar11 = (double)(longlong)dVar9;
    dVar9 = (double)(longlong)
                    ((dVar9 - dVar11) + *(double *)((ulonglong)(0.0 < dVar9) * 8 + 0x2ac334f8c60)) +
            dVar11;
  }
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x23);
  dVar11 = dVar9 * dVar10;
  if (_DAT_2ac33505c48 <= dVar9 * dVar10) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x23);
    dVar11 = _DAT_2ac33505c48;
  }
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x22);
  if (dVar11 <= _DAT_2ac33505c48) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x22);
    dVar11 = _DAT_2ac33505c48;
  }
  FUN_2ac334d0af0(&local_78,0x2ac334f9160,0,0x2ac334fdf38);
  dVar9 = (double)FUN_2ac334e5e90((double)_DAT_2ac33505d90 * _DAT_2ac33505c18 +
                                  *(double *)(param_5 + 0x10),&local_78);
  if (dVar9 - *(double *)(param_5 + 0x10) <= (double)_DAT_2ac33500154 * _DAT_2ac33505c18) {
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334f9ba0);
    uVar1 = param_3;
  }
  else {
    FUN_2ac334d0af0(&local_78,&local_88,0,0x2ac334fdf48);
    dVar10 = (double)FUN_2ac334e7060(&local_78);
    uVar1 = param_3;
    if (dVar11 <= dVar10) {
      FUN_2ac334d0af0(&local_78,0x2ac33505c28,1,0x2ac334fdf58);
      cVar2 = FUN_2ac334e7380(&local_78,dVar11,4,dVar9,param_4);
      uVar1 = param_3;
      if ((cVar2 != '\0') &&
         ((iVar3 = (*(code *)0x7ff63a0c73c0)(0x2ac301f9168,0x2f), iVar3 == 0 ||
          (iVar4 = (*(code *)0x7ff63a1081a0)(0x2ac301f9168), uVar1 = param_3, iVar4 < iVar3)))) {
        lVar7 = (longlong)_DAT_2ac33505d18;
        FUN_2ac334d0af0(&local_78,0x2ac33505d20,0,0x2ac334fdf68);
        lVar8 = (longlong)_DAT_2ac33505e08;
        FUN_2ac334d0af0(&local_68,0x2ac33505c28,1,0x2ac334fdf78);
        FUN_2ac334e77d0(&local_68,4,dVar11,dVar9,lVar8,&local_78,lVar7);
        uVar1 = _DAT_2ac33500094;
      }
    }
  }
  _DAT_2ac33500094 = uVar1;
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d00a0(&local_68);
  return;
}



/* Address: 2ac334ec880 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334ec880(int param_1,double param_2,undefined4 param_3,undefined8 param_4,
                    longlong param_5)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_64 = 0;
  local_74 = 0;
  dVar9 = (double)FUN_2ac334e5210();
  if (param_1 == 0) {
    if (DAT_2ac33505d50 != '\0') {
      dVar9 = (double)FUN_2ac334f4410(dVar9);
    }
  }
  else if ((DAT_2ac33505d60 == '\0') || (param_2 <= 0.0)) {
    if ((DAT_2ac33505d70 != '\0') && ((0.0 < param_2 && (_DAT_2ac33505d80 <= param_1)))) {
      dVar9 = param_2 + _DAT_2ac33505d78;
    }
  }
  else {
    dVar9 = param_2 * _DAT_2ac33505d68;
  }
  local_88 = 0;
  local_84 = 0;
  FUN_2ac334d0af0(&local_88,0x2ac33505c28,1,0x2ac334fdec8);
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x24);
  dVar10 = (double)(~-(ulonglong)(_DAT_2ac33505c48 == 0.0) & (ulonglong)_DAT_2ac33505c48 |
                   _DAT_2ac334f8c70 & -(ulonglong)(_DAT_2ac33505c48 == 0.0));
  dVar9 = dVar9 / dVar10;
  uVar6 = (uint)((ulonglong)dVar9 >> 0x34) & 0x7ff;
  lVar7 = (ulonglong)uVar6 - 0x3ff;
  dVar11 = dVar9;
  if ((ulonglong)uVar6 < 0x433) {
    if (uVar6 < 0x3ff) {
      dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar7 != -1) {
        dVar11 = (double)((ulonglong)dVar9 & 0x8000000000000000);
      }
    }
    else {
      bVar5 = (byte)lVar7;
      if (((longlong)dVar9 << (bVar5 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar5 & 0x3f)) + (longlong)dVar9 &
                         -0x10000000000000 >> (bVar5 & 0x3f));
      }
    }
  }
  else if (lVar7 == 0x400) {
    dVar11 = dVar9 + dVar9;
  }
  dVar9 = (dVar11 * dVar10) / dVar10;
  if ((longlong)dVar9 != -0x8000000000000000) {
    dVar11 = (double)(longlong)dVar9;
    dVar9 = (double)(longlong)
                    ((dVar9 - dVar11) + *(double *)((ulonglong)(0.0 < dVar9) * 8 + 0x2ac334f8c78)) +
            dVar11;
  }
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x23);
  dVar11 = dVar9 * dVar10;
  if (_DAT_2ac33505c48 <= dVar9 * dVar10) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x23);
    dVar11 = _DAT_2ac33505c48;
  }
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x22);
  if (dVar11 <= _DAT_2ac33505c48) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,0x22);
    dVar11 = _DAT_2ac33505c48;
  }
  FUN_2ac334d0af0(&local_78,0x2ac334f9160,0,0x2ac334fded8);
  dVar9 = (double)FUN_2ac334e5e90(*(double *)(param_5 + 8) -
                                  (double)_DAT_2ac33505d90 * _DAT_2ac33505c18,&local_78);
  if (*(double *)(param_5 + 8) - dVar9 <= (double)_DAT_2ac33500154 * _DAT_2ac33505c18) {
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334f9c20);
    uVar1 = param_3;
  }
  else {
    FUN_2ac334d0af0(&local_78,&local_88,0,0x2ac334fdee8);
    dVar10 = (double)FUN_2ac334e7060(&local_78);
    uVar1 = param_3;
    if (dVar11 <= dVar10) {
      FUN_2ac334d0af0(&local_78,0x2ac33505c28,1,0x2ac334fdef8);
      cVar2 = FUN_2ac334e7380(&local_78,dVar11,5,dVar9,param_4);
      uVar1 = param_3;
      if ((cVar2 != '\0') &&
         ((iVar3 = (*(code *)0x7ff63a0c73c0)(0x2ac301f9168,0x2f), iVar3 == 0 ||
          (iVar4 = (*(code *)0x7ff63a1081a0)(0x2ac301f9168), uVar1 = param_3, iVar4 < iVar3)))) {
        lVar7 = (longlong)_DAT_2ac33505d18;
        FUN_2ac334d0af0(&local_78,0x2ac33505d20,0,0x2ac334fdf08);
        lVar8 = (longlong)_DAT_2ac33505e08;
        FUN_2ac334d0af0(&local_68,0x2ac33505c28,1,0x2ac334fdf18);
        FUN_2ac334e77d0(&local_68,5,dVar11,dVar9,lVar8,&local_78,lVar7);
        uVar1 = _DAT_2ac33500094;
      }
    }
  }
  _DAT_2ac33500094 = uVar1;
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d00a0(&local_68);
  return;
}



/* Address: 2ac334ecdc0 */

undefined8 FUN_2ac334ecdc0(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  undefined4 local_10;
  
  local_40 = 0x800010055;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_24 = 0;
  local_20 = 0;
  uStack_1c = 0;
  local_18 = 0;
  local_10 = 0;
  iVar2 = (*(code *)0x7ff63a1021d0)(0x2ac301f9168,6,param_1,0,0,1,&local_40);
  if (iVar2 < 1) {
    uVar3 = 0xffffffffffffffff;
  }
  else {
    if ((int)local_38 == 0) {
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x13054f000001f6);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    uVar3 = *(undefined8 *)CONCAT44(local_20,uStack_24);
  }
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,&local_40);
  return uVar3;
}



/* Address: 2ac334eceb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334eceb0(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  double dVar3;
  ushort uVar4;
  ushort uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  longlong lVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  ulonglong unaff_RSI;
  uint uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  undefined4 *puVar29;
  undefined4 local_128;
  longlong local_124;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  longlong local_b4;
  
  local_e8 = 0;
  local_f8 = 0;
  local_b8 = 0;
  local_108 = 0;
  local_128 = 0;
  local_118 = 0;
  local_e4 = 0;
  local_f4 = 0;
  local_b4 = 0;
  local_104 = 0;
  local_124 = 0;
  local_114 = (undefined1 *)0x0;
  if (_DAT_2ac33500000 == 0) {
    if ((DAT_2ac33505e10 == '\0') ||
       (lVar15 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,0x2ac334f9140,0x12),
       lVar15 <= _DAT_2ac33505e18)) {
      cVar11 = DAT_2ac33505e38;
      if (DAT_2ac33505e20 == '\0') {
LAB_2ac334ed4b0:
        if (DAT_2ac33505e40 == '\0') {
LAB_2ac334edb82:
          uVar20 = CONCAT71((int7)(unaff_RSI >> 8),1);
          if ((DAT_2ac33505e68 == '\0') || (_DAT_2ac33505e70 <= _DAT_2ac33505a84))
          goto LAB_2ac334eef7b;
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)_DAT_2ac33505a84,0,0x20);
          FUN_2ac334d0af0(&local_118,0x2ac33505c3c,1,0x2ac334ff1c0);
          FUN_2ac334d0af0(&local_128,0x2ac334fcb10);
          puVar10 = local_114;
          if (local_114 != (undefined1 *)0x0) {
            uVar13 = *(uint *)(local_114 + -4);
            uVar20 = (ulonglong)uVar13;
            if ((uVar20 == 0) && (local_124 != 0)) goto LAB_2ac334ee788;
            if (local_124 == 0) {
              uVar17 = 0;
            }
            else {
              uVar17 = (ulonglong)*(uint *)(local_124 + -4);
            }
            uVar18 = uVar13 + (int)uVar17;
            cVar11 = FUN_2ac334d0100(&local_128);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_124 + uVar17 * 2;
                if (uVar13 < 0x10) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar15 - (longlong)puVar10) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                  do {
                    puVar29 = (undefined4 *)(puVar10 + uVar21);
                    uVar7 = puVar29[1];
                    uVar8 = puVar29[2];
                    uVar9 = puVar29[3];
                    puVar2 = (undefined4 *)(lVar15 + uVar21);
                    *puVar2 = *puVar29;
                    puVar2[1] = uVar7;
                    puVar2[2] = uVar8;
                    puVar2[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334ee77d;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) = *(undefined2 *)(puVar10 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334ee77d:
              *(uint *)(local_124 + -4) = uVar18;
              *(undefined2 *)(local_124 + (ulonglong)uVar18 * 2) = 0;
              goto LAB_2ac334ee788;
            }
            goto LAB_2ac334ef1f5;
          }
LAB_2ac334ee788:
          uVar17 = 0;
          FUN_2ac334d0af0(&local_108,&local_128,0,0x2ac334ff1e0);
          uVar13 = _DAT_2ac334fcb28;
          uVar20 = (ulonglong)_DAT_2ac334fcb28;
          if ((uVar20 != 0) || (local_104 == 0)) {
            if (local_104 != 0) {
              uVar17 = (ulonglong)*(uint *)(local_104 + -4);
            }
            uVar16 = _DAT_2ac334fcb28 + (int)uVar17;
            uVar18 = 0x104;
            if ((0x103 < uVar16) &&
               ((0x7ffffffd < uVar16 || (uVar18 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar18)))) {
              uVar18 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_108,uVar18);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_104 + uVar17 * 2;
                if (uVar13 < 0x10) {
                  uVar17 = 0;
                }
                else if (lVar15 - 0x2ac334fcb2cU < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fcb30);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fcb34);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fcb38);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fcb2c + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334ee8a2;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fcb2c + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334ee8a2:
              *(uint *)(local_104 + -4) = uVar16;
              *(undefined2 *)(local_104 + (ulonglong)uVar16 * 2) = 0;
              goto LAB_2ac334ee8ad;
            }
            goto LAB_2ac334ef175;
          }
LAB_2ac334ee8ad:
          (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,(longlong)_DAT_2ac33505e78,0,0x20);
          FUN_2ac334d0af0(&local_b8,0x2ac33505c3c,1,0x2ac334ff1f0);
          FUN_2ac334d0af0(&local_f8,&local_108);
          lVar15 = local_b4;
          if (local_b4 == 0) {
LAB_2ac334ee9f6:
            uVar13 = 0;
            FUN_2ac334d0af0(&local_e8,&local_f8,0,0x2ac334ff210);
            uVar18 = _DAT_2ac334fcb48;
            uVar20 = (ulonglong)_DAT_2ac334fcb48;
            if ((uVar20 == 0) && (local_e4 != 0)) goto LAB_2ac334eef4d;
            if (local_e4 != 0) {
              uVar13 = *(uint *)(local_e4 + -4);
            }
            uVar16 = _DAT_2ac334fcb48 + uVar13;
            uVar19 = 0x104;
            if ((0x103 < uVar16) &&
               ((0x7ffffffd < uVar16 || (uVar19 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar19)))) {
              uVar19 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_e8,uVar19);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_e4 + (ulonglong)uVar13 * 2;
                if (uVar18 < 0x10) {
                  uVar17 = 0;
                }
                else if (lVar15 - 0x2ac334fcb4cU < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fcb50);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fcb54);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fcb58);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fcb4c + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334eef42;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fcb4c + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
              goto LAB_2ac334eef42;
            }
            goto LAB_2ac334ef195;
          }
          uVar13 = *(uint *)(local_b4 + -4);
          uVar20 = (ulonglong)uVar13;
          if ((uVar20 == 0) && (local_f4 != 0)) goto LAB_2ac334ee9f6;
          if (local_f4 == 0) {
            uVar17 = 0;
          }
          else {
            uVar17 = (ulonglong)*(uint *)(local_f4 + -4);
          }
          uVar18 = uVar13 + (int)uVar17;
          cVar11 = FUN_2ac334d0100(&local_f8);
          if (cVar11 != '\0') {
            if (uVar20 != 0) {
              lVar1 = local_f4 + uVar17 * 2;
              if (uVar13 < 0x10) {
                uVar17 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar15) < 0x20) {
                uVar17 = 0;
              }
              else {
                uVar21 = 0;
                uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                do {
                  puVar29 = (undefined4 *)(lVar15 + uVar21);
                  uVar7 = puVar29[1];
                  uVar8 = puVar29[2];
                  uVar9 = puVar29[3];
                  puVar2 = (undefined4 *)(lVar1 + uVar21);
                  *puVar2 = *puVar29;
                  puVar2[1] = uVar7;
                  puVar2[2] = uVar8;
                  puVar2[3] = uVar9;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar17 == uVar20) goto LAB_2ac334ee9eb;
              }
              do {
                *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar15 + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar20 != uVar17);
            }
LAB_2ac334ee9eb:
            *(uint *)(local_f4 + -4) = uVar18;
            *(undefined2 *)(local_f4 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_2ac334ee9f6;
          }
          goto LAB_2ac334ef215;
        }
        unaff_RSI = (ulonglong)_DAT_2ac33505ac4;
        FUN_2ac334d0af0(&local_118,0x2ac334fca18,0,0x2ac334ff0e0);
        dVar25 = (double)FUN_2ac334e6740(&local_118,unaff_RSI,0,0);
        iVar12 = _DAT_2ac33505e60;
        dVar23 = 0.0;
        if (0 < _DAT_2ac33505e60) {
          unaff_RSI = 1;
          dVar23 = 0.0;
          do {
            uVar13 = _DAT_2ac33505ac4;
            FUN_2ac334d0af0(&local_118,0x2ac334fca18,0,0x2ac334ff0f0);
            dVar26 = (double)FUN_2ac334e6740(&local_118,uVar13,0,unaff_RSI);
            uVar13 = (int)unaff_RSI + 1;
            unaff_RSI = (ulonglong)uVar13;
            dVar23 = dVar23 + dVar26;
          } while ((int)uVar13 <= iVar12);
        }
        if (iVar12 == 0) goto LAB_2ac334ef055;
        dVar23 = dVar23 / (double)iVar12;
        if (dVar25 < _DAT_2ac33505e50 * dVar23) {
          local_c8 = 0;
          local_d8 = 0;
          local_c4 = 0;
          local_d4 = 0;
          (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar25,_DAT_2ac33505c20);
          FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
          FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
          FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
          FUN_2ac334d00a0(&local_d8);
          FUN_2ac334d00a0(&local_c8);
          FUN_2ac334d0af0(&local_118,0x2ac33505c3c,1,0x2ac334ff100);
          FUN_2ac334d0af0(&local_128,0x2ac334fca70,0);
          puVar10 = local_114;
          if (local_114 != (undefined1 *)0x0) {
            uVar13 = *(uint *)(local_114 + -4);
            uVar20 = (ulonglong)uVar13;
            if ((uVar20 == 0) && (local_124 != 0)) goto LAB_2ac334ee307;
            if (local_124 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = *(uint *)(local_124 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_128);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_124 + (ulonglong)uVar18 * 2;
                if (uVar13 < 0x10) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar15 - (longlong)puVar10) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                  do {
                    puVar29 = (undefined4 *)(puVar10 + uVar21);
                    uVar7 = puVar29[1];
                    uVar8 = puVar29[2];
                    uVar9 = puVar29[3];
                    puVar2 = (undefined4 *)(lVar15 + uVar21);
                    *puVar2 = *puVar29;
                    puVar2[1] = uVar7;
                    puVar2[2] = uVar8;
                    puVar2[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334ee2f2;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) = *(undefined2 *)(puVar10 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334ee2f2:
              *(uint *)(local_124 + -4) = uVar13 + uVar18;
              *(undefined2 *)(local_124 + (ulonglong)(uVar13 + uVar18) * 2) = 0;
              goto LAB_2ac334ee307;
            }
            goto LAB_2ac334ef135;
          }
LAB_2ac334ee307:
          uVar13 = 0;
          FUN_2ac334d0af0(&local_108,&local_128,0);
          uVar18 = _DAT_2ac334fc9a8;
          uVar20 = (ulonglong)_DAT_2ac334fc9a8;
          if ((uVar20 != 0) || (local_104 == 0)) {
            if (local_104 != 0) {
              uVar13 = *(uint *)(local_104 + -4);
            }
            uVar16 = _DAT_2ac334fc9a8 + uVar13;
            cVar11 = FUN_2ac334d0100(&local_108);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_104 + (ulonglong)uVar13 * 2;
                if ((uVar18 < 0x10) || (lVar15 - 0x2ac334fc9acU < 0x20)) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9b0);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9b4);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9b8);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fc9ac + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334ee3e2;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fc9ac + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334ee3e2:
              *(uint *)(local_104 + -4) = uVar16;
              *(undefined2 *)(local_104 + (ulonglong)uVar16 * 2) = 0;
              goto LAB_2ac334ee3ed;
            }
            goto LAB_2ac334ef0b5;
          }
LAB_2ac334ee3ed:
          local_c8 = 0;
          local_d8 = 0;
          local_c4 = 0;
          local_d4 = 0;
          (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar23,_DAT_2ac33505c20);
          FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
          FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
          FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
          FUN_2ac334d00a0(&local_d8);
          FUN_2ac334d00a0(&local_c8);
          FUN_2ac334d0af0(&local_b8,0x2ac33505c3c,1,0x2ac334ff130);
          FUN_2ac334d0af0(&local_f8,&local_108,0);
          lVar15 = local_b4;
          if (local_b4 == 0) {
LAB_2ac334ee61d:
            uVar13 = 0;
            FUN_2ac334d0af0(&local_e8,&local_f8,0);
            uVar18 = _DAT_2ac334fc9c8;
            uVar20 = (ulonglong)_DAT_2ac334fc9c8;
            if ((uVar20 == 0) && (local_e4 != 0)) goto LAB_2ac334eef4d;
            if (local_e4 != 0) {
              uVar13 = *(uint *)(local_e4 + -4);
            }
            uVar16 = _DAT_2ac334fc9c8 + uVar13;
            cVar11 = FUN_2ac334d0100(&local_e8);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_e4 + (ulonglong)uVar13 * 2;
                if ((uVar18 < 0x10) || (lVar15 - 0x2ac334fc9ccU < 0x20)) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9d0);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9d4);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9d8);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fc9cc + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334eef42;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fc9cc + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
              goto LAB_2ac334eef42;
            }
            goto LAB_2ac334ef0d5;
          }
          uVar13 = *(uint *)(local_b4 + -4);
          uVar20 = (ulonglong)uVar13;
          if ((uVar20 == 0) && (local_f4 != 0)) goto LAB_2ac334ee61d;
          if (local_f4 == 0) {
            uVar17 = 0;
          }
          else {
            uVar17 = (ulonglong)*(uint *)(local_f4 + -4);
          }
          uVar18 = uVar13 + (int)uVar17;
          cVar11 = FUN_2ac334d0100(&local_f8);
          if (cVar11 != '\0') {
            if (uVar20 != 0) {
              lVar1 = local_f4 + uVar17 * 2;
              if (uVar13 < 0x10) {
                uVar17 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar15) < 0x20) {
                uVar17 = 0;
              }
              else {
                uVar21 = 0;
                uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                do {
                  puVar29 = (undefined4 *)(lVar15 + uVar21);
                  uVar7 = puVar29[1];
                  uVar8 = puVar29[2];
                  uVar9 = puVar29[3];
                  puVar2 = (undefined4 *)(lVar1 + uVar21);
                  *puVar2 = *puVar29;
                  puVar2[1] = uVar7;
                  puVar2[2] = uVar8;
                  puVar2[3] = uVar9;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar17 == uVar20) goto LAB_2ac334ee612;
              }
              do {
                *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar15 + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar20 != uVar17);
            }
LAB_2ac334ee612:
            *(uint *)(local_f4 + -4) = uVar18;
            *(undefined2 *)(local_f4 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_2ac334ee61d;
          }
          goto LAB_2ac334ef155;
        }
        if (dVar25 <= _DAT_2ac33505e58 * dVar23) goto LAB_2ac334edb82;
        local_c8 = 0;
        local_d8 = 0;
        local_c4 = 0;
        local_d4 = 0;
        (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar25,_DAT_2ac33505c20);
        FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
        FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
        FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
        FUN_2ac334d00a0(&local_d8);
        FUN_2ac334d00a0(&local_c8);
        FUN_2ac334d0af0(&local_118,0x2ac33505c3c,1,0x2ac334ff160);
        FUN_2ac334d0af0(&local_128,0x2ac334fcac0,0);
        puVar10 = local_114;
        if (local_114 == (undefined1 *)0x0) {
LAB_2ac334eeb68:
          uVar13 = 0;
          FUN_2ac334d0af0(&local_108,&local_128,0);
          uVar18 = _DAT_2ac334fc9a8;
          uVar20 = (ulonglong)_DAT_2ac334fc9a8;
          if ((uVar20 != 0) || (local_104 == 0)) {
            if (local_104 != 0) {
              uVar13 = *(uint *)(local_104 + -4);
            }
            uVar16 = _DAT_2ac334fc9a8 + uVar13;
            cVar11 = FUN_2ac334d0100(&local_108);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_104 + (ulonglong)uVar13 * 2;
                if ((uVar18 < 0x10) || (lVar15 - 0x2ac334fc9acU < 0x20)) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9b0);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9b4);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9b8);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fc9ac + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334eec42;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fc9ac + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334eec42:
              *(uint *)(local_104 + -4) = uVar16;
              *(undefined2 *)(local_104 + (ulonglong)uVar16 * 2) = 0;
              goto LAB_2ac334eec4d;
            }
            goto LAB_2ac334ef1b5;
          }
LAB_2ac334eec4d:
          local_c8 = 0;
          local_d8 = 0;
          local_c4 = 0;
          local_d4 = 0;
          (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar23,_DAT_2ac33505c20);
          FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
          FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
          FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
          FUN_2ac334d00a0(&local_d8);
          FUN_2ac334d00a0(&local_c8);
          FUN_2ac334d0af0(&local_b8,0x2ac33505c3c,1,0x2ac334ff190);
          FUN_2ac334d0af0(&local_f8,&local_108,0);
          lVar15 = local_b4;
          if (local_b4 != 0) {
            uVar13 = *(uint *)(local_b4 + -4);
            uVar20 = (ulonglong)uVar13;
            if ((uVar20 != 0) || (local_f4 == 0)) {
              if (local_f4 == 0) {
                uVar17 = 0;
              }
              else {
                uVar17 = (ulonglong)*(uint *)(local_f4 + -4);
              }
              uVar18 = uVar13 + (int)uVar17;
              cVar11 = FUN_2ac334d0100(&local_f8);
              if (cVar11 == '\0') goto LAB_2ac334ef255;
              if (uVar20 != 0) {
                lVar1 = local_f4 + uVar17 * 2;
                if (uVar13 < 0x10) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar1 - lVar15) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                  do {
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    uVar7 = puVar29[1];
                    uVar8 = puVar29[2];
                    uVar9 = puVar29[3];
                    puVar2 = (undefined4 *)(lVar1 + uVar21);
                    *puVar2 = *puVar29;
                    puVar2[1] = uVar7;
                    puVar2[2] = uVar8;
                    puVar2[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334eee4e;
                }
                do {
                  *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar15 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334eee4e:
              *(uint *)(local_f4 + -4) = uVar18;
              *(undefined2 *)(local_f4 + (ulonglong)uVar18 * 2) = 0;
            }
          }
          uVar13 = 0;
          FUN_2ac334d0af0(&local_e8,&local_f8,0);
          uVar18 = _DAT_2ac334fc9c8;
          uVar20 = (ulonglong)_DAT_2ac334fc9c8;
          if ((uVar20 == 0) && (local_e4 != 0)) goto LAB_2ac334eef4d;
          if (local_e4 != 0) {
            uVar13 = *(uint *)(local_e4 + -4);
          }
          uVar16 = _DAT_2ac334fc9c8 + uVar13;
          cVar11 = FUN_2ac334d0100(&local_e8);
          if (cVar11 != '\0') {
            if (uVar20 != 0) {
              lVar15 = local_e4 + (ulonglong)uVar13 * 2;
              if ((uVar18 < 0x10) || (lVar15 - 0x2ac334fc9ccU < 0x20)) {
                uVar17 = 0;
              }
              else {
                uVar21 = 0;
                uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                do {
                  uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9d0);
                  uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9d4);
                  uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9d8);
                  puVar29 = (undefined4 *)(lVar15 + uVar21);
                  *puVar29 = *(undefined4 *)(&DAT_2ac334fc9cc + uVar21);
                  puVar29[1] = uVar7;
                  puVar29[2] = uVar8;
                  puVar29[3] = uVar9;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar17 == uVar20) goto LAB_2ac334eef42;
              }
              do {
                *(undefined2 *)(lVar15 + uVar17 * 2) =
                     *(undefined2 *)(&DAT_2ac334fc9cc + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar20 != uVar17);
            }
            goto LAB_2ac334eef42;
          }
          goto LAB_2ac334ef1d5;
        }
        uVar13 = *(uint *)(local_114 + -4);
        uVar20 = (ulonglong)uVar13;
        if ((uVar20 == 0) && (local_124 != 0)) goto LAB_2ac334eeb68;
        if (local_124 == 0) {
          uVar18 = 0;
        }
        else {
          uVar18 = *(uint *)(local_124 + -4);
        }
        cVar11 = FUN_2ac334d0100(&local_128);
        if (cVar11 != '\0') {
          if (uVar20 != 0) {
            lVar15 = local_124 + (ulonglong)uVar18 * 2;
            if (uVar13 < 0x10) {
              uVar17 = 0;
            }
            else if ((ulonglong)(lVar15 - (longlong)puVar10) < 0x20) {
              uVar17 = 0;
            }
            else {
              uVar21 = 0;
              uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
              do {
                puVar29 = (undefined4 *)(puVar10 + uVar21);
                uVar7 = puVar29[1];
                uVar8 = puVar29[2];
                uVar9 = puVar29[3];
                puVar2 = (undefined4 *)(lVar15 + uVar21);
                *puVar2 = *puVar29;
                puVar2[1] = uVar7;
                puVar2[2] = uVar8;
                puVar2[3] = uVar9;
                uVar21 = uVar21 + 0x10;
              } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
              if (uVar17 == uVar20) goto LAB_2ac334eeb53;
            }
            do {
              *(undefined2 *)(lVar15 + uVar17 * 2) = *(undefined2 *)(puVar10 + uVar17 * 2);
              uVar17 = uVar17 + 1;
            } while (uVar20 != uVar17);
          }
LAB_2ac334eeb53:
          *(uint *)(local_124 + -4) = uVar13 + uVar18;
          *(undefined2 *)(local_124 + (ulonglong)(uVar13 + uVar18) * 2) = 0;
          goto LAB_2ac334eeb68;
        }
      }
      else {
        bVar22 = DAT_2ac33505e38 == '\0';
        FUN_2ac334d0af0(&local_118,0x2ac334f9160,0,0x2ac334ff000);
        uVar7 = _DAT_2ac33505c24;
        FUN_2ac334d0af0(&local_128,0x2ac33505c28,1,0x2ac334ff010);
        dVar23 = (double)FUN_2ac334f4810(local_124,uVar7,bVar22);
        if (local_114 == &DAT_2ac334f9158) {
LAB_2ac334ed100:
          FUN_2ac334d0af0(&local_118,0x2ac33505c28,1,0x2ac334fe220);
        }
        else if (local_114 != (undefined1 *)0x0) {
          uVar13 = *(uint *)(local_114 + -4);
          uVar18 = _DAT_2ac334f9154;
          if (uVar13 < _DAT_2ac334f9154) {
            uVar18 = uVar13;
          }
          iVar12 = uVar13 - _DAT_2ac334f9154;
          if (uVar18 != 0) {
            uVar20 = 0;
            do {
              uVar4 = *(ushort *)(local_114 + uVar20 * 2);
              uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar20 * 2);
              uVar20 = uVar20 + 1;
              if (uVar18 <= uVar20) break;
            } while (uVar4 == uVar5);
            if (uVar4 != uVar5) {
              iVar12 = (uint)uVar4 - (uint)uVar5;
            }
          }
          if (iVar12 == 0) goto LAB_2ac334ed100;
        }
        uVar13 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_118,0x11);
        if ((longlong)dVar23 != -0x8000000000000000) {
          dVar25 = (double)(longlong)dVar23;
          uVar20 = 0xb;
          if (uVar13 < 0xb) {
            uVar20 = (ulonglong)uVar13;
          }
          dVar26 = *(double *)(uVar20 * 8 + 0x2ac334f8f00);
          dVar23 = (double)(longlong)
                           ((dVar23 - dVar25) * dVar26 +
                           *(double *)((ulonglong)(0.0 < dVar23) * 8 + 0x2ac334f8c88)) / dVar26 +
                   dVar25;
        }
        FUN_2ac334d0af0(&local_118,0x2ac334f9160,0,0x2ac334ff020);
        uVar7 = _DAT_2ac33505c24;
        FUN_2ac334d0af0(&local_128,0x2ac33505c28,1,0x2ac334ff030);
        dVar25 = (double)FUN_2ac334f4770(local_124,uVar7,bVar22);
        if (local_114 == &DAT_2ac334f9158) {
LAB_2ac334ed270:
          FUN_2ac334d0af0(&local_118,0x2ac33505c28,1,0x2ac334fe220);
        }
        else if (local_114 != (undefined1 *)0x0) {
          uVar13 = *(uint *)(local_114 + -4);
          uVar18 = _DAT_2ac334f9154;
          if (uVar13 < _DAT_2ac334f9154) {
            uVar18 = uVar13;
          }
          iVar12 = uVar13 - _DAT_2ac334f9154;
          if (uVar18 != 0) {
            uVar20 = 0;
            do {
              uVar4 = *(ushort *)(local_114 + uVar20 * 2);
              uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar20 * 2);
              uVar20 = uVar20 + 1;
              if (uVar18 <= uVar20) break;
            } while (uVar4 == uVar5);
            if (uVar4 != uVar5) {
              iVar12 = (uint)uVar4 - (uint)uVar5;
            }
          }
          if (iVar12 == 0) goto LAB_2ac334ed270;
        }
        uVar13 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_118,0x11);
        iVar12 = _DAT_2ac33505e28;
        if ((longlong)dVar25 != -0x8000000000000000) {
          dVar26 = (double)(longlong)dVar25;
          uVar20 = 0xb;
          if (uVar13 < 0xb) {
            uVar20 = (ulonglong)uVar13;
          }
          dVar24 = *(double *)(uVar20 * 8 + 0x2ac334f8f00);
          dVar25 = (double)(longlong)
                           ((dVar25 - dVar26) * dVar24 +
                           *(double *)((ulonglong)(0.0 < dVar25) * 8 + 0x2ac334f8c88)) / dVar24 +
                   dVar26;
        }
        dVar26 = 0.0;
        uVar13 = (cVar11 == '\0') + 1;
        unaff_RSI = (ulonglong)uVar13;
        dVar24 = 0.0;
        if ((int)uVar13 <= _DAT_2ac33505e28) {
          do {
            FUN_2ac334d0af0(&local_118,0x2ac334f9160,0,0x2ac334ff040);
            uVar7 = _DAT_2ac33505c24;
            FUN_2ac334d0af0(&local_128,0x2ac33505c28,1);
            dVar24 = (double)FUN_2ac334f4810(local_124,uVar7,unaff_RSI);
            if (local_114 == &DAT_2ac334f9158) {
LAB_2ac334ed800:
              FUN_2ac334d0af0(&local_118,0x2ac33505c28,1,0x2ac334fe220);
            }
            else if (local_114 != (undefined1 *)0x0) {
              uVar13 = *(uint *)(local_114 + -4);
              uVar18 = _DAT_2ac334f9154;
              if (uVar13 < _DAT_2ac334f9154) {
                uVar18 = uVar13;
              }
              iVar14 = uVar13 - _DAT_2ac334f9154;
              if (uVar18 != 0) {
                uVar20 = 0;
                do {
                  uVar4 = *(ushort *)(local_114 + uVar20 * 2);
                  uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar20 * 2);
                  uVar20 = uVar20 + 1;
                  if (uVar18 <= uVar20) break;
                } while (uVar4 == uVar5);
                if (uVar4 != uVar5) {
                  iVar14 = (uint)uVar4 - (uint)uVar5;
                }
              }
              if (iVar14 == 0) goto LAB_2ac334ed800;
            }
            uVar13 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_118,0x11);
            if ((longlong)dVar24 != -0x8000000000000000) {
              dVar27 = (double)(longlong)dVar24;
              uVar20 = (ulonglong)uVar13;
              if (10 < uVar13) {
                uVar20 = 0xb;
              }
              dVar28 = *(double *)(uVar20 * 8 + 0x2ac334f8f00);
              dVar24 = (double)(longlong)
                               ((dVar24 - dVar27) * dVar28 +
                               *(double *)((ulonglong)(0.0 < dVar24) * 8 + 0x2ac334f8c88)) / dVar28
                       + dVar27;
            }
            FUN_2ac334d0af0(&local_118,0x2ac334f9160,0,0x2ac334ff060);
            uVar7 = _DAT_2ac33505c24;
            FUN_2ac334d0af0(&local_128,0x2ac33505c28,1);
            dVar27 = (double)FUN_2ac334f4770(local_124,uVar7,unaff_RSI);
            if (local_114 == &DAT_2ac334f9158) {
LAB_2ac334ed980:
              FUN_2ac334d0af0(&local_118,0x2ac33505c28,1,0x2ac334fe220);
            }
            else if (local_114 != (undefined1 *)0x0) {
              uVar13 = *(uint *)(local_114 + -4);
              uVar18 = _DAT_2ac334f9154;
              if (uVar13 < _DAT_2ac334f9154) {
                uVar18 = uVar13;
              }
              iVar14 = uVar13 - _DAT_2ac334f9154;
              if (uVar18 != 0) {
                uVar20 = 0;
                do {
                  uVar4 = *(ushort *)(local_114 + uVar20 * 2);
                  uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar20 * 2);
                  uVar20 = uVar20 + 1;
                  if (uVar18 <= uVar20) break;
                } while (uVar4 == uVar5);
                if (uVar4 != uVar5) {
                  iVar14 = (uint)uVar4 - (uint)uVar5;
                }
              }
              if (iVar14 == 0) goto LAB_2ac334ed980;
            }
            uVar13 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_118);
            if ((longlong)dVar27 != -0x8000000000000000) {
              dVar28 = (double)(longlong)dVar27;
              uVar20 = (ulonglong)uVar13;
              if (10 < uVar13) {
                uVar20 = 0xb;
              }
              dVar3 = *(double *)(uVar20 * 8 + 0x2ac334f8f00);
              dVar27 = (double)(longlong)
                               ((dVar27 - dVar28) * dVar3 +
                               *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x2ac334f8c88)) / dVar3 +
                       dVar28;
            }
            uVar13 = (int)unaff_RSI + 1;
            unaff_RSI = (ulonglong)uVar13;
            dVar26 = dVar26 + (dVar24 - dVar27);
            dVar24 = dVar26;
          } while ((int)uVar13 <= iVar12);
        }
        if (iVar12 == 0) {
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xd0ab9000001f7);
LAB_2ac334ef055:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xf0ac8000001f7);
LAB_2ac334ef075:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c0abc000001f9);
LAB_2ac334ef095:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x3c0abc000001f9);
LAB_2ac334ef0b5:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x300aca000001f9);
LAB_2ac334ef0d5:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x400aca000001f9);
LAB_2ac334ef0f5:
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x220abc000001f9);
        }
        else {
          if (dVar23 - dVar25 <= _DAT_2ac33505e30 * (dVar24 / (double)iVar12)) goto LAB_2ac334ed4b0;
          local_c8 = 0;
          local_d8 = 0;
          local_c4 = 0;
          local_d4 = 0;
          (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar23 - dVar25,_DAT_2ac33505c20);
          FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
          FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
          FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
          FUN_2ac334d00a0(&local_d8);
          FUN_2ac334d00a0(&local_c8);
          FUN_2ac334d0af0(&local_118,0x2ac33505c3c,1,0x2ac334ff080);
          FUN_2ac334d0af0(&local_128,0x2ac334fc990);
          puVar10 = local_114;
          if (local_114 != (undefined1 *)0x0) {
            uVar13 = *(uint *)(local_114 + -4);
            uVar20 = (ulonglong)uVar13;
            if ((uVar20 == 0) && (local_124 != 0)) goto LAB_2ac334edda7;
            if (local_124 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = *(uint *)(local_124 + -4);
            }
            cVar11 = FUN_2ac334d0100(&local_128);
            if (cVar11 != '\0') {
              if (uVar20 != 0) {
                lVar15 = local_124 + (ulonglong)uVar18 * 2;
                if (uVar13 < 0x10) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar15 - (longlong)puVar10) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                  do {
                    puVar29 = (undefined4 *)(puVar10 + uVar21);
                    uVar7 = puVar29[1];
                    uVar8 = puVar29[2];
                    uVar9 = puVar29[3];
                    puVar2 = (undefined4 *)(lVar15 + uVar21);
                    *puVar2 = *puVar29;
                    puVar2[1] = uVar7;
                    puVar2[2] = uVar8;
                    puVar2[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334edd92;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) = *(undefined2 *)(puVar10 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334edd92:
              *(uint *)(local_124 + -4) = uVar13 + uVar18;
              *(undefined2 *)(local_124 + (ulonglong)(uVar13 + uVar18) * 2) = 0;
              goto LAB_2ac334edda7;
            }
            goto LAB_2ac334ef0f5;
          }
LAB_2ac334edda7:
          uVar13 = 0;
          FUN_2ac334d0af0(&local_108,&local_128,0,0x2ac334ff0a0);
          uVar18 = _DAT_2ac334fc9a8;
          uVar20 = (ulonglong)_DAT_2ac334fc9a8;
          if ((uVar20 != 0) || (local_104 == 0)) {
            if (local_104 != 0) {
              uVar13 = *(uint *)(local_104 + -4);
            }
            uVar19 = _DAT_2ac334fc9a8 + uVar13;
            uVar16 = 0x104;
            if ((0x103 < uVar19) &&
               ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
              uVar16 = 0x7ffffffe;
            }
            cVar11 = FUN_2ac334d0100(&local_108,uVar16);
            if (cVar11 == '\0') goto LAB_2ac334ef075;
            if (uVar20 != 0) {
              lVar15 = local_104 + (ulonglong)uVar13 * 2;
              if (uVar18 < 0x10) {
                uVar17 = 0;
              }
              else if (lVar15 - 0x2ac334fc9acU < 0x20) {
                uVar17 = 0;
              }
              else {
                uVar21 = 0;
                uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                do {
                  uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9b0);
                  uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9b4);
                  uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9b8);
                  puVar29 = (undefined4 *)(lVar15 + uVar21);
                  *puVar29 = *(undefined4 *)(&DAT_2ac334fc9ac + uVar21);
                  puVar29[1] = uVar7;
                  puVar29[2] = uVar8;
                  puVar29[3] = uVar9;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar17 == uVar20) goto LAB_2ac334edec2;
              }
              do {
                *(undefined2 *)(lVar15 + uVar17 * 2) =
                     *(undefined2 *)(&DAT_2ac334fc9ac + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar20 != uVar17);
            }
LAB_2ac334edec2:
            *(uint *)(local_104 + -4) = uVar19;
            *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
          }
          local_c8 = 0;
          local_d8 = 0;
          local_c4 = 0;
          local_d4 = 0;
          (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,dVar24 / (double)iVar12,_DAT_2ac33505c20);
          FUN_2ac334d0af0(&local_c8,0x2ac33505c3c,1,0x2ac334fefd0);
          FUN_2ac334d0af0(&local_d8,&local_c8,0,0x2ac334fefe0);
          FUN_2ac334d0af0(0x2ac33505c3c,&local_d8,1,0x2ac334feff0);
          FUN_2ac334d00a0(&local_d8);
          FUN_2ac334d00a0(&local_c8);
          FUN_2ac334d0af0(&local_b8,0x2ac33505c3c,1,0x2ac334ff0b0);
          FUN_2ac334d0af0(&local_f8,&local_108);
          lVar15 = local_b4;
          if (local_b4 == 0) {
LAB_2ac334ee09d:
            uVar13 = 0;
            FUN_2ac334d0af0(&local_e8,&local_f8,0,0x2ac334ff0d0);
            uVar18 = _DAT_2ac334fc9c8;
            uVar20 = (ulonglong)_DAT_2ac334fc9c8;
            if ((uVar20 != 0) || (local_e4 == 0)) {
              if (local_e4 != 0) {
                uVar13 = *(uint *)(local_e4 + -4);
              }
              uVar16 = _DAT_2ac334fc9c8 + uVar13;
              uVar19 = 0x104;
              if ((0x103 < uVar16) &&
                 ((0x7ffffffd < uVar16 || (uVar19 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar19))))
              {
                uVar19 = 0x7ffffffe;
              }
              cVar11 = FUN_2ac334d0100(&local_e8,uVar19);
              if (cVar11 == '\0') goto LAB_2ac334ef095;
              if (uVar20 != 0) {
                lVar15 = local_e4 + (ulonglong)uVar13 * 2;
                if (uVar18 < 0x10) {
                  uVar17 = 0;
                }
                else if (lVar15 - 0x2ac334fc9ccU < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar21 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar7 = *(undefined4 *)(uVar21 + 0x2ac334fc9d0);
                    uVar8 = *(undefined4 *)(uVar21 + 0x2ac334fc9d4);
                    uVar9 = *(undefined4 *)(uVar21 + 0x2ac334fc9d8);
                    puVar29 = (undefined4 *)(lVar15 + uVar21);
                    *puVar29 = *(undefined4 *)(&DAT_2ac334fc9cc + uVar21);
                    puVar29[1] = uVar7;
                    puVar29[2] = uVar8;
                    puVar29[3] = uVar9;
                    uVar21 = uVar21 + 0x10;
                  } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                  if (uVar17 == uVar20) goto LAB_2ac334eef42;
                }
                do {
                  *(undefined2 *)(lVar15 + uVar17 * 2) =
                       *(undefined2 *)(&DAT_2ac334fc9cc + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar20 != uVar17);
              }
LAB_2ac334eef42:
              *(uint *)(local_e4 + -4) = uVar16;
              *(undefined2 *)(local_e4 + (ulonglong)uVar16 * 2) = 0;
            }
LAB_2ac334eef4d:
            puVar29 = &local_e8;
            goto LAB_2ac334eef52;
          }
          uVar13 = *(uint *)(local_b4 + -4);
          uVar20 = (ulonglong)uVar13;
          if ((uVar20 == 0) && (local_f4 != 0)) goto LAB_2ac334ee09d;
          if (local_f4 == 0) {
            uVar17 = 0;
          }
          else {
            uVar17 = (ulonglong)*(uint *)(local_f4 + -4);
          }
          uVar18 = uVar13 + (int)uVar17;
          cVar11 = FUN_2ac334d0100(&local_f8);
          if (cVar11 != '\0') {
            if (uVar20 != 0) {
              lVar1 = local_f4 + uVar17 * 2;
              if (uVar13 < 0x10) {
                uVar17 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar15) < 0x20) {
                uVar17 = 0;
              }
              else {
                uVar21 = 0;
                uVar17 = (ulonglong)(uVar13 & 0xfffffff8);
                do {
                  puVar29 = (undefined4 *)(lVar15 + uVar21);
                  uVar7 = puVar29[1];
                  uVar8 = puVar29[2];
                  uVar9 = puVar29[3];
                  puVar2 = (undefined4 *)(lVar1 + uVar21);
                  *puVar2 = *puVar29;
                  puVar2[1] = uVar7;
                  puVar2[2] = uVar8;
                  puVar2[3] = uVar9;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar17 == uVar20) goto LAB_2ac334ee092;
              }
              do {
                *(undefined2 *)(lVar1 + uVar17 * 2) = *(undefined2 *)(lVar15 + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar20 != uVar17);
            }
LAB_2ac334ee092:
            *(uint *)(local_f4 + -4) = uVar18;
            *(undefined2 *)(local_f4 + (ulonglong)uVar18 * 2) = 0;
            goto LAB_2ac334ee09d;
          }
        }
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x330abc000001f9);
LAB_2ac334ef135:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x270aca000001f9);
LAB_2ac334ef155:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x370aca000001f9);
LAB_2ac334ef175:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x400ad6000001f9);
LAB_2ac334ef195:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x6c0ad6000001f9);
LAB_2ac334ef1b5:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x310ace000001f9);
LAB_2ac334ef1d5:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x410ace000001f9);
LAB_2ac334ef1f5:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x270ad6000001f9);
LAB_2ac334ef215:
        (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x480ad6000001f9);
      }
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x280ace000001f9);
LAB_2ac334ef255:
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x380ace000001f9);
      pcVar6 = (code *)swi(3);
      uVar20 = (*pcVar6)();
      return uVar20;
    }
    puVar29 = (undefined4 *)0x2ac334fc948;
  }
  else {
    puVar29 = (undefined4 *)0x2ac334fc8e8;
  }
LAB_2ac334eef52:
  (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,puVar29);
  uVar20 = 0;
LAB_2ac334eef7b:
  FUN_2ac334d00a0(&local_118);
  FUN_2ac334d00a0(&local_128);
  FUN_2ac334d00a0(&local_108);
  FUN_2ac334d00a0(&local_b8);
  FUN_2ac334d00a0(&local_f8);
  FUN_2ac334d00a0(&local_e8);
  return uVar20 & 0xffffffff;
}



/* Address: 2ac334ef570 */

void FUN_2ac334ef570(void)

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
    FUN_2ac334d0af0(&local_60,0x2ac33505b10,0);
    lVar5 = *(longlong *)(&DAT_2ac33505b34 + lVar14 * 0xc);
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
        cVar10 = FUN_2ac334d0100(&local_60);
        if (cVar10 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x250bd4000001f9);
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
            if (uVar12 == uVar15) goto LAB_2ac334ef722;
          }
          do {
            *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
            uVar12 = uVar12 + 1;
          } while (uVar15 != uVar12);
        }
LAB_2ac334ef722:
        *(uint *)(local_5c + -4) = uVar13;
        *(undefined2 *)(local_5c + (ulonglong)uVar13 * 2) = 0;
      }
    }
    FUN_2ac334d0af0(&local_50,&local_60,0,0x2ac334ff360);
    iVar11 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,0);
    if (-1 < iVar11) {
      (*(code *)0x7ff63a0f4ce0)(0x2ac301f9168,0);
    }
    FUN_2ac334d00a0(&local_50);
    bVar18 = lVar14 == 0xf;
    lVar14 = lVar14 + 1;
    if (bVar18) {
      DAT_2ac33505b00 = 0;
      FUN_2ac334d00a0(&local_60);
      return;
    }
  } while( true );
}



/* Address: 2ac334ef7c0 */

void FUN_2ac334ef7c0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x250bd4000001f9);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2ac334f0740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f0740(void)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  FUN_2ac334f0ce0(0x2ac33505a60);
  FUN_2ac334d10c0(&DAT_2ac335059f0);
  (*(code *)0x7ff63a0e62f0)(0x2ac301f9168,_DAT_2ac335059f0);
  FUN_2ac334f0ce0(0x2ac33505980);
  lVar4 = -0xc0;
  do {
    if ((((*(int *)(lVar4 + 0x2ac33505bf0) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ac33505bf4), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac33505bf4) = 0;
    *(undefined4 *)(lVar4 + 0x2ac33505bf0) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_2ac334d00a0(0x2ac33505b20);
  FUN_2ac334d00a0(0x2ac33505b10);
  lVar4 = _DAT_2ac3350594c;
  if (_DAT_2ac3350594c != 0) {
    uVar5 = (ulonglong)_DAT_2ac33505938;
    if (uVar5 != 0) {
      lVar2 = -0xc;
      do {
        if ((ulonglong)*(uint *)(&DAT_2ac33505948 + lVar2) == 0) break;
        uVar5 = uVar5 * *(uint *)(&DAT_2ac33505948 + lVar2);
        lVar2 = lVar2 + 4;
      } while (lVar2 != 0);
      if (uVar5 != 0) {
        plVar3 = (longlong *)(_DAT_2ac3350594c + 4);
        do {
          if (((*(int *)((longlong)plVar3 + -4) != 0) && (lVar2 = *plVar3, lVar2 != 0)) &&
             (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
            piVar1 = (int *)(lVar2 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2ac301f9168);
            }
          }
          *plVar3 = 0;
          *(undefined4 *)((longlong)plVar3 + -4) = 0;
          plVar3 = (longlong *)((longlong)plVar3 + 0xc);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2ac301f9168,lVar4,0);
    _DAT_2ac3350594c = 0;
  }
  _DAT_2ac33505938 = 0;
  _DAT_2ac33505948 = 0;
  FUN_2ac334d00a0(0x2ac33505910);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ac335045f8) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ac335045fc), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac335045fc) = 0;
    *(undefined4 *)(lVar4 + 0x2ac335045f8) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if ((((*(int *)(lVar4 + 0x2ac33504578) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ac3350457c), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac3350457c) = 0;
    *(undefined4 *)(lVar4 + 0x2ac33504578) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ac335044f8) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ac335044fc), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac335044fc) = 0;
    *(undefined4 *)(lVar4 + 0x2ac335044f8) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if (((*(int *)(lVar4 + 0x2ac33504478) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ac3350447c), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac3350447c) = 0;
    *(undefined4 *)(lVar4 + 0x2ac33504478) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x78;
  do {
    if ((((*(int *)(lVar4 + 0x2ac335043f8) != 0) &&
         (lVar2 = *(longlong *)(lVar4 + 0x2ac335043fc), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac335043fc) = 0;
    *(undefined4 *)(lVar4 + 0x2ac335043f8) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  lVar4 = -0x41a0;
  do {
    if (((*(int *)(&DAT_2ac33504380 + lVar4) != 0) &&
        (lVar2 = *(longlong *)(&DAT_2ac33504384 + lVar4), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(&DAT_2ac33504384 + lVar4) = 0;
    *(undefined4 *)(&DAT_2ac33504380 + lVar4) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  FUN_2ac334d00a0(0x2ac335001c8);
  lVar4 = -0x30;
  do {
    if (((*(int *)(&DAT_2ac335001c0 + lVar4) != 0) &&
        (lVar2 = *(longlong *)(lVar4 + 0x2ac335001c4), lVar2 != 0)) &&
       (((int *)(lVar2 + -0xc) != (int *)0x0 && (*(int *)(lVar2 + -0xc) != 0)))) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2ac301f9168);
      }
    }
    *(undefined8 *)(lVar4 + 0x2ac335001c4) = 0;
    *(undefined4 *)(&DAT_2ac335001c0 + lVar4) = 0;
    lVar4 = lVar4 + 0xc;
  } while (lVar4 != 0);
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,0x2ac33500120);
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,0x2ac335000e0);
  (*(code *)0x7ff63a0d9d20)(0x2ac301f9168,0x2ac335000a0);
  FUN_2ac334d00a0(0x2ac33500048);
  FUN_2ac334d00a0(0x2ac33500038);
  FUN_2ac334d00a0(0x2ac33500028);
  FUN_2ac334d00a0(0x2ac33500018);
  FUN_2ac334d00a0(0x2ac33500008);
  return;
}



/* Address: 2ac334f0ce0 */

void FUN_2ac334f0ce0(undefined8 *param_1)

{
  FUN_2ac334d10c0();
  (*(code *)0x7ff63a0e62f0)(0x2ac301f9168,*param_1);
  return;
}



/* Address: 2ac334f0d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334f0d20(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_88;
  longlong local_84;
  undefined8 local_78;
  undefined4 local_70;
  ulonglong local_68;
  undefined1 local_60 [8];
  undefined4 local_58;
  undefined8 local_54;
  undefined8 local_48;
  
  local_58 = 0;
  local_88 = 0;
  local_54 = 0;
  local_84 = 0;
  if (_DAT_2ac33505c14 != 0) {
    (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0xd,2,0x590008,0x2ac334fb310,0x590008,0x2ac334fa308);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
    uVar5 = 0;
    goto LAB_2ac334f1410;
  }
  local_48 = param_2;
  cVar2 = (*(code *)0x7ff63a107ee0)(0x2ac301f9168);
  if (cVar2 == '\0') {
    uVar5 = 0;
    goto LAB_2ac334f1410;
  }
  local_88 = 0;
  local_84 = 0;
  (*(code *)0x7ff63a108010)(0x2ac301f9168,0);
  FUN_2ac334d0af0(&local_58,0x2ac33505c3c,1,0x2ac334fd2e8);
  FUN_2ac334d0af0(&local_88,&local_58,0,0x2ac334fd2f8);
  piVar1 = (int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  FUN_2ac334d00a0(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  FUN_2ac334d00a0(param_1 + 0x84);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
  FUN_2ac334d00a0(param_1 + 0x144);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
  FUN_2ac334d00a0(param_1 + 0x208);
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
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_88,0x21);
  if (1 < uVar3) {
    puVar7 = &local_88;
    uVar5 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,puVar7,0x32);
    if (uVar3 == 2) {
      if (*piVar1 == 5) goto LAB_2ac334f1329;
      if ((uVar5 & 1) == 0) {
        uVar6 = 0x272e;
        if ((uVar5 & 2) == 0) goto LAB_2ac334f12a8;
        *(undefined4 *)(param_1 + 0x2a5) = 1;
        iVar4 = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x2a5) = 0;
        iVar4 = 0;
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0x2a5);
      if (iVar4 != 2) {
        if (iVar4 == 1) {
          if (*piVar1 == 5) {
            local_78 = 0;
            local_70 = 0;
            if (local_84 == 0) {
              puVar7 = (undefined4 *)0x2ac33505c28;
            }
            local_68 = uVar5;
            FUN_2ac334d0af0(&local_78,puVar7,0,0x2ac334fde08);
            (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_78,0x31,local_60);
            if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334f11d2 */
                    /* WARNING: Treating indirect jump as call */
              uVar5 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2ac334f8cd0))();
              return uVar5;
            }
            (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fb290);
            FUN_2ac334d00a0(&local_78);
            *(undefined4 *)(param_1 + 0x78) = 1;
            iVar4 = 2;
            uVar5 = local_68;
            if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2ac334f1326;
          }
          uVar5 = uVar5 & 2;
        }
        else {
          uVar6 = 0x271b;
          if (iVar4 != 0) goto LAB_2ac334f12a8;
          if (*piVar1 == 5) {
            local_78 = 0;
            local_70 = 0;
            if (local_84 == 0) {
              puVar7 = (undefined4 *)0x2ac33505c28;
            }
            local_68 = uVar5;
            FUN_2ac334d0af0(&local_78,puVar7,0,0x2ac334fde08);
            (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_78,0x31,local_60);
            if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334f1125 */
                    /* WARNING: Treating indirect jump as call */
              uVar5 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2ac334f8cf0))();
              return uVar5;
            }
            (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,2,1,0x590008,0x2ac334fb290);
            FUN_2ac334d00a0(&local_78);
            *(undefined4 *)(param_1 + 0x78) = 1;
            iVar4 = 2;
            uVar5 = local_68;
            if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2ac334f1326;
          }
          uVar5 = uVar5 & 1;
        }
        uVar6 = 0x272e;
        if (uVar5 == 0) {
LAB_2ac334f12a8:
          *(undefined4 *)(param_1 + 0x110) = uVar6;
          FUN_2ac334d00a0(&local_88);
          uVar5 = 0;
          goto LAB_2ac334f1410;
        }
        iVar4 = *(int *)(param_1 + 0x2a5);
      }
    }
LAB_2ac334f1326:
    *(int *)(param_1 + 0x74) = iVar4;
  }
LAB_2ac334f1329:
  iVar4 = (*(code *)0x7ff63a107fc0)(0x2ac301f9168);
  *(uint *)(param_1 + 0x70) = (uint)(iVar4 == 0);
  (*(code *)0x7ff63a0f2890)(0x2ac301f9168,&local_88,(iVar4 != 0) * '\x03' + '\x01');
  *(undefined8 *)(param_1 + 0x48) = _DAT_2ac33505c48;
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined8 *)(param_1 + 0x90) = local_48;
  FUN_2ac334d0af0(param_1 + 0x34,&local_88,0,0x2ac334fd308);
  (*(code *)0x7ff63a107f70)(0x2ac301f9168,3);
  *(undefined8 *)(param_1 + 0x40) = _DAT_2ac33505c48;
  *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_1 + 0x29d);
  uVar3 = FUN_2ac334d0e40(param_1,piVar1,param_1 + 0x110);
  uVar5 = (ulonglong)uVar3;
  FUN_2ac334d00a0(&local_88);
LAB_2ac334f1410:
  FUN_2ac334d00a0(&local_58);
  return uVar5;
}



/* Address: 2ac334f1430 */

void FUN_2ac334f1430(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x2ac33505c28;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_2ac334d0af0(&local_60,lVar10,0,0x2ac334fdad8);
  (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334f1567 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x2ac334f8d10))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ac301f9168,*param_3,0x53,&local_88);
  FUN_2ac334d0af0(&local_98,0x2ac334fb210,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_2ac334f1bcf;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_2ac334f1bcf;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_2ac334d0100(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1f0561000101f9);
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
      if (uVar11 == uVar12) goto LAB_2ac334f1dc2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_2ac334f1dc2:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_2ac334f1bcf:
  FUN_2ac334d0af0(param_1,&local_98,0,0x2ac334fddd8);
  FUN_2ac334d0af0(&local_50,param_1,0,0x2ac334fdde8);
  FUN_2ac334d00a0(&local_60);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_50,1,0x2ac334fddf8);
  FUN_2ac334d00a0(&local_50);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_78);
  return;
}



/* Address: 2ac334f1c50 */

void FUN_2ac334f1c50(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_2ac334d0af0(&stack0x00000060,0x2ac33505c3c,1,0x2ac334fdba8);
  (*(code *)0x7ff63a0e49f0)(0x2ac301f9168,0xd8,2,0x590008,0x2ac334faaa0);
  FUN_2ac334d0af0(&stack0x00000050,0x2ac33505c3c,1,0x2ac334fdbb8);
  FUN_2ac334d0af0(in_stack_00000048,&stack0x00000050,0,0x2ac334fdbc8);
  FUN_2ac334d0af0(&stack0x00000098,in_stack_00000048,0,0x2ac334fdde8);
  FUN_2ac334d00a0(&stack0x00000088);
  FUN_2ac334d0af0(0x2ac33505c3c,&stack0x00000098,1,0x2ac334fddf8);
  FUN_2ac334d00a0(&stack0x00000098);
  FUN_2ac334d00a0(&stack0x00000060);
  FUN_2ac334d00a0(&stack0x00000050);
  FUN_2ac334d00a0(&stack0x00000070);
  return;
}



/* Address: 2ac334f1e10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f1e10(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_2ac334d0af0(param_2,0x2ac334f9160,0,0x2ac334fd4d8);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x2ac33505c28;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_2ac334d0af0(&local_98,piVar12,0,0x2ac334fd4e8);
  (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x2ac301f9168,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x02ac334f1ff0 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x2ac334f8e38))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ac301f9168,(longlong)*param_3,0x52,&local_108);
  FUN_2ac334d0af0(&local_f8,0x2ac334fa960,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_2ac334f28db;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_2ac334f28db;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_2ac334d0100(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1e04cf000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xf04a0000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xf04a5000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x150470000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x150489000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x15043c000101f9);
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x150457000101f9);
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
      if (uVar13 == uVar14) goto LAB_2ac334f3bb2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_2ac334f3bb2:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_2ac334f28db:
  uVar9 = local_e8;
  FUN_2ac334d0af0(local_e8,&local_f8,0,0x2ac334fdaa8);
  FUN_2ac334d0af0(&local_68,uVar9,0,0x2ac334fdab8);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_e0);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d00a0(&local_c0);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_68,1,0x2ac334fdac8);
  FUN_2ac334d00a0(&local_68);
  FUN_2ac334d00a0(&local_108);
  FUN_2ac334d00a0(&local_f8);
  FUN_2ac334d00a0(&local_d0);
  FUN_2ac334d00a0(&local_b0);
  return;
}



/* Address: 2ac334f3ed0 */

void FUN_2ac334f3ed0(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x02ac334f3f33 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x2ac334f8ea8))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2ac301f9168,(ulonglong)param_2,0x53,&local_50);
  FUN_2ac334d0af0(&local_60,0x2ac334fa148,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_2ac334f412d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_2ac334f412d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_2ac334d0100(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2203c7000101f9);
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
      if (uVar11 == uVar13) goto LAB_2ac334f4122;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_2ac334f4122:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_2ac334f412d:
  FUN_2ac334d0af0(param_1,&local_60,0,0x2ac334fd408);
  FUN_2ac334d0af0(&local_40,param_1,0,0x2ac334fd418);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_40,1,0x2ac334fd428);
  FUN_2ac334d00a0(&local_40);
  FUN_2ac334d00a0(&local_50);
  FUN_2ac334d00a0(&local_60);
  return;
}



/* Address: 2ac334f41d0 */

void FUN_2ac334f41d0(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_2ac334d0af0(&local_78,0x2ac33505c3c,1,0x2ac334fd438);
    FUN_2ac334d0af0(&local_88,&local_78,0,0x2ac334fd448);
    (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,param_3,param_4);
    FUN_2ac334d0af0(&local_78,0x2ac33505c3c,1,0x2ac334fd458);
    FUN_2ac334d0af0(&local_98,&local_78,0,0x2ac334fd468);
    (*(code *)0x7ff63a0e49f0)
              (0x2ac301f9168,0xd8,3,0x590008,0x2ac334fa210,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x2ac334fd488;
    uVar1 = 0x2ac334fd478;
  }
  else {
    uVar2 = 0x2ac334fd4a8;
    uVar1 = 0x2ac334fd498;
  }
  FUN_2ac334d0af0(&local_78,0x2ac33505c3c,1,uVar1);
  FUN_2ac334d0af0(param_1,&local_78,0,uVar2);
  FUN_2ac334d0af0(&local_68,param_1,0,0x2ac334fd4b8);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_68,1,0x2ac334fd4c8);
  FUN_2ac334d00a0(&local_68);
  FUN_2ac334d00a0(&local_78);
  return;
}



/* Address: 2ac334f4410 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334f4410(double param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  uint uVar7;
  double dVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  int iVar12;
  ulonglong uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 local_a8;
  longlong local_a4;
  longlong local_98;
  longlong local_90;
  
  local_a8 = 0;
  local_a4 = 0;
  uVar10 = (*(code *)0x7ff63a101c40)(0x2ac301f9168,0);
  (*(code *)0x7ff63a1084f0)(0x2ac301f9168,0,uVar10);
  iVar9 = (*(code *)0x7ff63a108810)(0x2ac301f9168);
  dVar8 = param_1;
  if (iVar9 + -1 < 0) {
    uVar13 = 0;
  }
  else {
    dVar6 = 0.0;
    uVar14 = 0;
    uVar15 = 0;
    local_90 = (longlong)_DAT_2ac33505d18;
    local_98 = 0;
    iVar9 = iVar9 + -1;
    do {
      uVar10 = (*(code *)0x7ff63a108860)(0x2ac301f9168,iVar9);
      (*(code *)0x7ff63a1089d0)(0x2ac301f9168,uVar10,0);
      FUN_2ac334d0af0(&local_a8,0x2ac33505c3c,1,0x2ac334fe200);
      if (local_a4 == _DAT_2ac33505c2c) {
LAB_2ac334f45ef:
        lVar11 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar10);
        if (((lVar11 == local_90) &&
            (lVar11 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar10), lVar11 == 0)) &&
           (lVar11 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar10), local_98 <= lVar11)) {
          local_98 = (*(code *)0x7ff63a108940)(0x2ac301f9168,uVar10,2);
          (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar10,9);
          dVar6 = _DAT_2ac33505c48;
          (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar10,8);
          dVar6 = dVar6 + _DAT_2ac33505c48;
          (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar10,7);
          dVar6 = dVar6 + _DAT_2ac33505c48;
          (*(code *)0x7ff63a1088b0)(0x2ac301f9168,uVar10);
          uVar14 = SUB84(_DAT_2ac33505c48,0);
          uVar15 = (undefined4)((ulonglong)_DAT_2ac33505c48 >> 0x20);
        }
      }
      else if ((local_a4 != 0) && (_DAT_2ac33505c2c != 0)) {
        uVar3 = *(uint *)(local_a4 + -4);
        uVar4 = *(uint *)(_DAT_2ac33505c2c + -4);
        uVar7 = uVar4;
        if (uVar3 < uVar4) {
          uVar7 = uVar3;
        }
        iVar12 = uVar3 - uVar4;
        if (uVar7 != 0) {
          uVar13 = 1;
          do {
            uVar1 = *(ushort *)(local_a4 + -2 + uVar13 * 2);
            uVar2 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar13 * 2);
            if (uVar7 <= uVar13) break;
            uVar13 = uVar13 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar12 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar12 == 0) goto LAB_2ac334f45ef;
      }
      bVar5 = 0 < iVar9;
      iVar9 = iVar9 + -1;
    } while (bVar5);
    uVar13 = -(ulonglong)((double)CONCAT44(uVar15,uVar14) != 0.0);
    if (dVar6 < 0.0) {
      dVar8 = (double)CONCAT44(uVar15,uVar14) * _DAT_2ac33505d58;
    }
  }
  FUN_2ac334d00a0(&local_a8);
  return ~uVar13 & (ulonglong)param_1 | (ulonglong)dVar8 & uVar13;
}



/* Address: 2ac334f4770 */

undefined8 FUN_2ac334f4770(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 *local_1c;
  undefined8 local_14;
  undefined8 local_c;
  
  local_38 = 0x1000058;
  local_34 = 0x100000008;
  local_2c = 0;
  local_24 = 0x100000000;
  local_1c = &local_40;
  local_14 = 0;
  local_c = 0;
  iVar1 = (*(code *)0x7ff63a1021d0)(0x2ac301f9168,4,param_1,param_2,param_3,1,&local_38);
  uVar2 = 0;
  if (0 < iVar1) {
    uVar2 = local_40;
  }
  return uVar2;
}



/* Address: 2ac334f4810 */

undefined8 FUN_2ac334f4810(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 *local_1c;
  undefined8 local_14;
  undefined8 local_c;
  
  local_38 = 0x1000058;
  local_34 = 0x100000008;
  local_2c = 0;
  local_24 = 0x100000000;
  local_1c = &local_40;
  local_14 = 0;
  local_c = 0;
  iVar1 = (*(code *)0x7ff63a1021d0)(0x2ac301f9168,3,param_1,param_2,param_3,1,&local_38);
  uVar2 = 0;
  if (0 < iVar1) {
    uVar2 = local_40;
  }
  return uVar2;
}



/* Address: 2ac334f48b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f48b0(undefined8 param_1)

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
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined4 local_68;
  longlong local_64;
  undefined4 local_58;
  longlong local_54;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  
  local_58 = 0;
  local_68 = 0;
  local_54 = 0;
  local_64 = 0;
  local_48 = 0;
  uStack_44 = 0;
  local_40 = 0;
  (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,param_1,0,0x20);
  FUN_2ac334d0af0(&local_68,0x2ac33505c3c,1,0x2ac334fe920);
  FUN_2ac334d0af0(&local_48,&local_68,0,0x2ac334fe930);
  if (DAT_2ac33505db8 == '\0') {
LAB_2ac334f4bf9:
    if (DAT_2ac33505da0 == '\0') goto LAB_2ac334f4e89;
    FUN_2ac334d0af0(&local_68,0x2ac334fb5b8);
    lVar2 = CONCAT44(local_40,uStack_44);
    if (lVar2 != 0) {
      uVar17 = *(uint *)(lVar2 + -4);
      uVar15 = (ulonglong)uVar17;
      if ((uVar15 != 0) || (local_64 == 0)) {
        if (local_64 == 0) {
          uVar12 = 0;
          uVar13 = uVar17;
        }
        else {
          uVar12 = *(uint *)(local_64 + -4);
          uVar13 = uVar17 + uVar12;
        }
        cVar9 = FUN_2ac334d0100(&local_68);
        if (cVar9 == '\0') goto LAB_2ac334f4f18;
        if (uVar15 != 0) {
          lVar1 = local_64 + (ulonglong)uVar12 * 2;
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
              puVar4 = (undefined4 *)(lVar2 + uVar16);
              uVar6 = puVar4[1];
              uVar7 = puVar4[2];
              uVar8 = puVar4[3];
              puVar3 = (undefined4 *)(lVar1 + uVar16);
              *puVar3 = *puVar4;
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar16 = uVar16 + 0x10;
            } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
            if (uVar11 == uVar15) goto LAB_2ac334f4d32;
          }
          do {
            *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
            uVar11 = uVar11 + 1;
          } while (uVar15 != uVar11);
        }
LAB_2ac334f4d32:
        *(uint *)(local_64 + -4) = uVar13;
        *(undefined2 *)(local_64 + (ulonglong)uVar13 * 2) = 0;
      }
    }
    uVar17 = 0;
    FUN_2ac334d0af0(&local_58,&local_68,0,0x2ac334fe970);
    uVar12 = _DAT_2ac334fb5f8;
    uVar15 = (ulonglong)_DAT_2ac334fb5f8;
    if ((uVar15 != 0) || (local_54 == 0)) {
      if (local_54 != 0) {
        uVar17 = *(uint *)(local_54 + -4);
      }
      uVar14 = _DAT_2ac334fb5f8 + uVar17;
      uVar13 = 0x104;
      if ((0x103 < uVar14) &&
         ((0x7ffffffd < uVar14 || (uVar13 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar13)))) {
        uVar13 = 0x7ffffffe;
      }
      cVar9 = FUN_2ac334d0100(&local_58,uVar13);
      if (cVar9 == '\0') goto LAB_2ac334f4ed8;
      if (uVar15 != 0) {
        lVar2 = local_54 + (ulonglong)uVar17 * 2;
        if (uVar12 < 0x10) {
          uVar11 = 0;
        }
        else if (lVar2 - 0x2ac334fb5fcU < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar12 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar16 + 0x2ac334fb600);
            uVar7 = *(undefined4 *)(uVar16 + 0x2ac334fb604);
            uVar8 = *(undefined4 *)(uVar16 + 0x2ac334fb608);
            puVar4 = (undefined4 *)(lVar2 + uVar16);
            *puVar4 = *(undefined4 *)(&DAT_2ac334fb5fc + uVar16);
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar15) goto LAB_2ac334f4e62;
        }
        do {
          *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_2ac334fb5fc + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar15 != uVar11);
      }
LAB_2ac334f4e62:
      *(uint *)(local_54 + -4) = uVar14;
      *(undefined2 *)(local_54 + (ulonglong)uVar14 * 2) = 0;
    }
    uVar10 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
    (*(code *)0x7ff63a0f4ce0)(0x2ac301f9168,uVar10,&local_58);
LAB_2ac334f4e89:
    FUN_2ac334d00a0(&local_48);
    FUN_2ac334d00a0(&local_68);
    FUN_2ac334d00a0(&local_58);
    return;
  }
  FUN_2ac334d0af0(&local_68,0x2ac334fb5b8);
  lVar2 = CONCAT44(local_40,uStack_44);
  if (lVar2 == 0) {
LAB_2ac334f4aad:
    uVar11 = 0;
    FUN_2ac334d0af0(&local_58,&local_68,0,0x2ac334fe950);
    uVar17 = _DAT_2ac334fb5d8;
    uVar15 = (ulonglong)_DAT_2ac334fb5d8;
    if ((uVar15 == 0) && (local_54 != 0)) {
LAB_2ac334f4bdd:
      uVar10 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
      (*(code *)0x7ff63a0f4ce0)(0x2ac301f9168,uVar10);
      goto LAB_2ac334f4bf9;
    }
    if (local_54 != 0) {
      uVar11 = (ulonglong)*(uint *)(local_54 + -4);
    }
    uVar13 = _DAT_2ac334fb5d8 + (int)uVar11;
    uVar12 = 0x104;
    if ((0x103 < uVar13) &&
       ((0x7ffffffd < uVar13 || (uVar12 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar12)))) {
      uVar12 = 0x7ffffffe;
    }
    cVar9 = FUN_2ac334d0100(&local_58,uVar12);
    if (cVar9 != '\0') {
      if (uVar15 != 0) {
        lVar2 = local_54 + uVar11 * 2;
        if (uVar17 < 0x10) {
          uVar11 = 0;
        }
        else if (lVar2 - 0x2ac334fb5dcU < 0x20) {
          uVar11 = 0;
        }
        else {
          uVar16 = 0;
          uVar11 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar16 + 0x2ac334fb5e0);
            uVar7 = *(undefined4 *)(uVar16 + 0x2ac334fb5e4);
            uVar8 = *(undefined4 *)(uVar16 + 0x2ac334fb5e8);
            puVar4 = (undefined4 *)(lVar2 + uVar16);
            *puVar4 = *(undefined4 *)(&DAT_2ac334fb5dc + uVar16);
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar15) goto LAB_2ac334f4bd2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar11 * 2) = *(undefined2 *)(&DAT_2ac334fb5dc + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar15 != uVar11);
      }
LAB_2ac334f4bd2:
      *(uint *)(local_54 + -4) = uVar13;
      *(undefined2 *)(local_54 + (ulonglong)uVar13 * 2) = 0;
      goto LAB_2ac334f4bdd;
    }
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2c073a000001f9);
LAB_2ac334f4ed8:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x40073c000001f9);
  }
  else {
    uVar17 = *(uint *)(lVar2 + -4);
    uVar15 = (ulonglong)uVar17;
    if ((uVar15 == 0) && (local_64 != 0)) goto LAB_2ac334f4aad;
    if (local_64 == 0) {
      uVar11 = 0;
      uVar12 = uVar17;
    }
    else {
      uVar11 = (ulonglong)*(uint *)(local_64 + -4);
      uVar12 = uVar17 + *(uint *)(local_64 + -4);
    }
    cVar9 = FUN_2ac334d0100(&local_68);
    if (cVar9 != '\0') {
      if (uVar15 != 0) {
        lVar1 = local_64 + uVar11 * 2;
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
            puVar4 = (undefined4 *)(lVar2 + uVar16);
            uVar6 = puVar4[1];
            uVar7 = puVar4[2];
            uVar8 = puVar4[3];
            puVar3 = (undefined4 *)(lVar1 + uVar16);
            *puVar3 = *puVar4;
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar11 == uVar15) goto LAB_2ac334f4aa2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar2 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar15 != uVar11);
      }
LAB_2ac334f4aa2:
      *(uint *)(local_64 + -4) = uVar12;
      *(undefined2 *)(local_64 + (ulonglong)uVar12 * 2) = 0;
      goto LAB_2ac334f4aad;
    }
  }
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x25073a000001f9);
LAB_2ac334f4f18:
  (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x39073c000001f9);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



/* Address: 2ac334f4f40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2ac334f4f40(undefined8 param_1,int param_2,double param_3,double param_4)

{
  double dVar1;
  int iVar2;
  undefined8 unaff_RSI;
  ulonglong uVar3;
  double dVar4;
  undefined1 local_98 [8];
  double local_90;
  double local_88;
  
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x2ac301f9168,6);
  uVar3 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (iVar2 != 0) {
    (*(code *)0x7ff63a0f2890)(0x2ac301f9168,param_1,0x10);
    dVar1 = _DAT_2ac33505c48;
    (*(code *)0x7ff63a0f2c10)(0x2ac301f9168,param_1,local_98);
    dVar4 = _DAT_2ac334f8ee8 * dVar1;
    if (param_2 == 1) {
      if ((((param_3 == 0.0) && (!NAN(param_3))) ||
          ((double)_DAT_2ac33500154 * dVar1 < (param_3 - local_90) - dVar4)) &&
         (((param_4 == 0.0 && (!NAN(param_4))) ||
          (dVar1 * (double)_DAT_2ac33500154 < (local_90 - param_4) - dVar4)))) goto LAB_2ac334f50c7;
    }
    else if ((param_2 != 0) ||
            ((((param_3 == 0.0 && (!NAN(param_3))) ||
              ((double)_DAT_2ac33500154 * dVar1 < (local_88 - dVar4) - param_3)) &&
             (((param_4 == 0.0 && (!NAN(param_4))) ||
              (dVar1 * (double)_DAT_2ac33500154 < (param_4 - dVar4) - local_88))))))
    goto LAB_2ac334f50c7;
    uVar3 = 0;
  }
LAB_2ac334f50c7:
  return uVar3 & 0xffffffff;
}



/* Address: 2ac334f50f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f50f0(longlong param_1,longlong param_2,undefined8 param_3,double param_4,
                    uint param_5)

{
  longlong lVar1;
  longlong lVar2;
  double dVar3;
  ushort uVar4;
  ushort uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  uint uVar12;
  ulonglong uVar13;
  int iVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  double dVar19;
  undefined4 local_98;
  undefined1 *local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_88 = 0;
  local_98 = 0;
  local_64 = 0;
  local_74 = 0;
  local_84 = 0;
  local_94 = (undefined1 *)0x0;
  if (_DAT_2ac33505c2c == param_1) {
    iVar14 = 0;
  }
  else {
    iVar14 = 1;
    if ((param_1 != 0) && (_DAT_2ac33505c2c != 0)) {
      uVar10 = *(uint *)(param_1 + -4);
      uVar17 = *(uint *)(_DAT_2ac33505c2c + -4);
      uVar12 = uVar17;
      if (uVar10 < uVar17) {
        uVar12 = uVar10;
      }
      iVar14 = uVar10 - uVar17;
      if (uVar12 != 0) {
        uVar15 = 1;
        do {
          uVar4 = *(ushort *)(param_1 + -2 + uVar15 * 2);
          uVar5 = *(ushort *)(_DAT_2ac33505c2c + -2 + uVar15 * 2);
          if (uVar12 <= uVar15) break;
          uVar15 = uVar15 + 1;
        } while (uVar4 == uVar5);
        if (uVar4 != uVar5) {
          iVar14 = (uint)uVar4 - (uint)uVar5;
        }
      }
    }
  }
  (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,param_3,0,0x20);
  FUN_2ac334d0af0(&local_98,0x2ac33505c3c,1,0x2ac334fe8b0);
  FUN_2ac334d0af0(&local_88,0x2ac334fb5b8);
  puVar7 = local_94;
  if (local_94 != (undefined1 *)0x0) {
    uVar10 = *(uint *)(local_94 + -4);
    uVar15 = (ulonglong)uVar10;
    if ((uVar15 == 0) && (local_84 != 0)) goto LAB_2ac334f536f;
    if (local_84 == 0) {
      uVar13 = 0;
      uVar17 = uVar10;
    }
    else {
      uVar13 = (ulonglong)*(uint *)(local_84 + -4);
      uVar17 = uVar10 + *(uint *)(local_84 + -4);
    }
    cVar8 = FUN_2ac334d0100(&local_88);
    if (cVar8 != '\0') {
      if (uVar15 != 0) {
        lVar1 = local_84 + uVar13 * 2;
        if (uVar10 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar1 - (longlong)puVar7) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar16 = 0;
          uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
          do {
            uVar11 = *(undefined8 *)((longlong)(puVar7 + uVar16) + 8);
            *(undefined8 *)(lVar1 + uVar16) = *(undefined8 *)(puVar7 + uVar16);
            ((undefined8 *)(lVar1 + uVar16))[1] = uVar11;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar13 == uVar15) goto LAB_2ac334f5362;
        }
        do {
          *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(puVar7 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar15 != uVar13);
      }
LAB_2ac334f5362:
      *(uint *)(local_84 + -4) = uVar17;
      *(undefined2 *)(local_84 + (ulonglong)uVar17 * 2) = 0;
      goto LAB_2ac334f536f;
    }
LAB_2ac334f5974:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x12072a000001f9);
LAB_2ac334f5994:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2e072a000001f9);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
LAB_2ac334f536f:
  uVar10 = 0;
  FUN_2ac334d0af0(&local_78,&local_88,0,0x2ac334fe8d0);
  uVar17 = _DAT_2ac334fbaa4;
  uVar15 = (ulonglong)_DAT_2ac334fbaa4;
  if ((uVar15 != 0) || (local_74 == 0)) {
    if (local_74 != 0) {
      uVar10 = *(uint *)(local_74 + -4);
    }
    uVar18 = _DAT_2ac334fbaa4 + uVar10;
    uVar12 = 0x104;
    if ((0x103 < uVar18) &&
       ((0x7ffffffd < uVar18 || (uVar12 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar12)))) {
      uVar12 = 0x7ffffffe;
    }
    cVar8 = FUN_2ac334d0100(&local_78,uVar12);
    if (cVar8 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2a072a000001f9);
      goto LAB_2ac334f5974;
    }
    if (uVar15 != 0) {
      lVar1 = local_74 + (ulonglong)uVar10 * 2;
      if (uVar17 < 0x10) {
        uVar13 = 0;
      }
      else if (lVar1 - 0x2ac334fbaa8U < 0x20) {
        uVar13 = 0;
      }
      else {
        uVar16 = 0;
        uVar13 = (ulonglong)(uVar17 & 0xfffffff8);
        do {
          uVar11 = *(undefined8 *)(uVar16 + 0x2ac334fbab0);
          *(undefined8 *)(lVar1 + uVar16) = *(undefined8 *)(&DAT_2ac334fbaa8 + uVar16);
          ((undefined8 *)(lVar1 + uVar16))[1] = uVar11;
          uVar16 = uVar16 + 0x10;
        } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
        if (uVar13 == uVar15) goto LAB_2ac334f54a2;
      }
      do {
        *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(&DAT_2ac334fbaa8 + uVar13 * 2);
        uVar13 = uVar13 + 1;
      } while (uVar15 != uVar13);
    }
LAB_2ac334f54a2:
    *(uint *)(local_74 + -4) = uVar18;
    *(undefined2 *)(local_74 + (ulonglong)uVar18 * 2) = 0;
  }
  FUN_2ac334d0af0(&local_68,&local_78,0);
  lVar1 = *(longlong *)(param_2 + 4);
  if (lVar1 != 0) {
    uVar10 = *(uint *)(lVar1 + -4);
    uVar15 = (ulonglong)uVar10;
    if ((uVar15 != 0) || (local_64 == 0)) {
      if (local_64 == 0) {
        uVar17 = 0;
        uVar12 = uVar10;
      }
      else {
        uVar17 = *(uint *)(local_64 + -4);
        uVar12 = uVar10 + uVar17;
      }
      cVar8 = FUN_2ac334d0100(&local_68);
      if (cVar8 == '\0') goto LAB_2ac334f5994;
      if (uVar15 != 0) {
        lVar2 = local_64 + (ulonglong)uVar17 * 2;
        if (uVar10 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar16 = 0;
          uVar13 = (ulonglong)(uVar10 & 0xfffffff8);
          do {
            uVar11 = ((undefined8 *)(lVar1 + uVar16))[1];
            *(undefined8 *)(lVar2 + uVar16) = *(undefined8 *)(lVar1 + uVar16);
            ((undefined8 *)(lVar2 + uVar16))[1] = uVar11;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar13 == uVar15) goto LAB_2ac334f55d2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar13 * 2) = *(undefined2 *)(lVar1 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar15 != uVar13);
      }
LAB_2ac334f55d2:
      *(uint *)(local_64 + -4) = uVar12;
      *(undefined2 *)(local_64 + (ulonglong)uVar12 * 2) = 0;
    }
  }
  FUN_2ac334d0af0(param_2,&local_68,0,0x2ac334fe8f0);
  uVar11 = (*(code *)0x7ff63a0f5790)(0x2ac301f9168);
  iVar9 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,uVar11,param_2);
  if (iVar9 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2ac301f9168,0x112,6,0x550005,uVar11,0x590008,param_2,0x520004,1,0x520004,0,0x540005
               ,0,0x580007,0);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,uVar11,param_2,4,0);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,uVar11,param_2,2,1);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,uVar11,param_2,0,-(uint)(iVar14 != 0) | param_5);
    (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,uVar11,param_2,1,1);
    (*(code *)0x7ff63a0fdfe0)(0x2ac301f9168,param_3,0,0x20);
    FUN_2ac334d0af0(&local_98,0x2ac33505c3c,1,0x2ac334fe900);
    (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,uVar11,param_2,6,&local_98);
  }
  FUN_2ac334d0af0(&local_98,0x2ac334f9160,0,0x2ac334fe910);
  if (local_94 != &DAT_2ac334f9158) {
    if (local_94 == (undefined1 *)0x0) goto LAB_2ac334f584e;
    uVar10 = *(uint *)(local_94 + -4);
    uVar17 = _DAT_2ac334f9154;
    if (uVar10 < _DAT_2ac334f9154) {
      uVar17 = uVar10;
    }
    iVar14 = uVar10 - _DAT_2ac334f9154;
    if (uVar17 != 0) {
      uVar15 = 0;
      do {
        uVar4 = *(ushort *)(local_94 + uVar15 * 2);
        uVar5 = *(ushort *)(&DAT_2ac334f9158 + uVar15 * 2);
        uVar15 = uVar15 + 1;
        if (uVar17 <= uVar15) break;
      } while (uVar4 == uVar5);
      if (uVar4 != uVar5) {
        iVar14 = (uint)uVar4 - (uint)uVar5;
      }
    }
    if (iVar14 != 0) goto LAB_2ac334f584e;
  }
  FUN_2ac334d0af0(&local_98,0x2ac33505c28,1,0x2ac334fe220);
LAB_2ac334f584e:
  uVar10 = (*(code *)0x7ff63a0f2970)(0x2ac301f9168,&local_98,0x11);
  if ((longlong)param_4 != -0x8000000000000000) {
    dVar19 = (double)(longlong)param_4;
    uVar15 = 0xb;
    if (uVar10 < 0xb) {
      uVar15 = (ulonglong)uVar10;
    }
    dVar3 = *(double *)(uVar15 * 8 + 0x2ac334f8f00);
    param_4 = (double)(longlong)
                      ((param_4 - dVar19) * dVar3 +
                      *(double *)((ulonglong)(0.0 < param_4) * 8 + 0x2ac334f8ef0)) / dVar3 + dVar19;
  }
  (*(code *)0x7ff63a0f3a50)(0x2ac301f9168,uVar11,param_2,9,param_4);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d00a0(&local_68);
  return;
}



/* Address: 2ac334f59c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f59c0(undefined8 param_1)

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
  (*(code *)0x7ff63a101f60)(0x2ac301f9168,param_1,local_60);
  local_80 = 0;
  local_7c = 0;
  FUN_2ac334d0af0(&local_80,0x2ac334f9160,0,0x2ac334fe9b0);
  lVar17 = 0;
  do {
    iVar5 = *(int *)(&DAT_2ac33500170 + lVar17 * 8);
    iVar6 = *(int *)(&DAT_2ac33500174 + lVar17 * 8);
    if (iVar5 < iVar6) {
      if ((iVar5 <= local_54) && (local_54 < iVar6)) {
        FUN_2ac334d0af0(&local_90,&DAT_2ac33500190 + lVar17 * 0xc);
        uVar7 = _DAT_2ac334fb4dc;
        uVar20 = (ulonglong)_DAT_2ac334fb4dc;
        if ((uVar20 == 0) && (local_8c != 0)) {
LAB_2ac334f5afd:
          uVar7 = *(uint *)(local_8c + -4);
          lVar1 = local_8c;
        }
        else {
          if (local_8c == 0) {
            uVar19 = 0;
            uVar16 = _DAT_2ac334fb4dc;
          }
          else {
            uVar19 = *(uint *)(local_8c + -4);
            uVar16 = _DAT_2ac334fb4dc + uVar19;
          }
          uVar13 = 0x104;
          if ((0x103 < uVar16) &&
             ((0x7ffffffd < uVar16 || (uVar13 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar13)))) {
            uVar13 = 0x7ffffffe;
          }
          cVar12 = FUN_2ac334d0100(&local_90,uVar13);
          if (cVar12 == '\0') {
LAB_2ac334f60db:
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2207af000001f9);
LAB_2ac334f60fb:
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1007b3000001f9);
            goto LAB_2ac334f611b;
          }
          if (uVar20 == 0) {
            *(uint *)(local_8c + -4) = uVar16;
            *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
            if (local_8c == 0) goto LAB_2ac334f5a86;
            goto LAB_2ac334f5afd;
          }
          lVar1 = local_8c + (ulonglong)uVar19 * 2;
          if (uVar7 < 8) {
            uVar14 = 0;
          }
          else {
            if (0x1f < local_8c + -0x2ac334fb4e0 + (ulonglong)uVar19 * 2) {
              uVar15 = 0;
              uVar14 = (ulonglong)(uVar7 & 0xfffffff8);
              do {
                uVar9 = *(undefined4 *)(uVar15 + 0x2ac334fb4e4);
                uVar10 = *(undefined4 *)(uVar15 + 0x2ac334fb4e8);
                uVar11 = *(undefined4 *)(uVar15 + 0x2ac334fb4ec);
                puVar3 = (undefined4 *)(lVar1 + uVar15);
                *puVar3 = *(undefined4 *)(&DAT_2ac334fb4e0 + uVar15);
                puVar3[1] = uVar9;
                puVar3[2] = uVar10;
                puVar3[3] = uVar11;
                uVar15 = uVar15 + 0x10;
                if ((uVar20 * 2 & 0xfffffffffffffff0) == uVar15) goto joined_r0x02ac334f5eb6;
              } while( true );
            }
            uVar14 = 0;
          }
          do {
            *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_2ac334fb4e0 + uVar14 * 2);
            uVar14 = uVar14 + 1;
joined_r0x02ac334f5eb6:
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
          cVar12 = FUN_2ac334d0100(&local_80);
          if (cVar12 == '\0') {
LAB_2ac334f611b:
            (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x1007af000001f9);
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
              if (uVar15 == uVar20) goto LAB_2ac334f5a79;
            }
            do {
              *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(lVar1 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar20 != uVar15);
          }
LAB_2ac334f5a79:
          *(int *)(local_7c + -4) = (int)uVar14;
          *(undefined2 *)(local_7c + uVar14 * 2) = 0;
        }
      }
    }
    else if ((iVar5 <= local_54) || (local_54 < iVar6)) {
      FUN_2ac334d0af0(&local_90,&DAT_2ac33500190 + lVar17 * 0xc,0);
      uVar7 = _DAT_2ac334fb4dc;
      uVar20 = (ulonglong)_DAT_2ac334fb4dc;
      if ((uVar20 == 0) && (local_8c != 0)) {
LAB_2ac334f5b78:
        uVar7 = *(uint *)(local_8c + -4);
        lVar1 = local_8c;
      }
      else {
        if (local_8c == 0) {
          uVar19 = 0;
          uVar16 = _DAT_2ac334fb4dc;
        }
        else {
          uVar19 = *(uint *)(local_8c + -4);
          uVar16 = _DAT_2ac334fb4dc + uVar19;
        }
        uVar13 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar13 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar13)))) {
          uVar13 = 0x7ffffffe;
        }
        cVar12 = FUN_2ac334d0100(&local_90,uVar13);
        if (cVar12 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2207b3000001f9);
          goto LAB_2ac334f60db;
        }
        if (uVar20 == 0) {
          *(uint *)(local_8c + -4) = uVar16;
          *(undefined2 *)(local_8c + (ulonglong)uVar16 * 2) = 0;
          if (local_8c == 0) goto LAB_2ac334f5a86;
          goto LAB_2ac334f5b78;
        }
        lVar1 = local_8c + (ulonglong)uVar19 * 2;
        if (uVar7 < 8) {
          uVar14 = 0;
        }
        else {
          if (0x1f < local_8c + -0x2ac334fb4e0 + (ulonglong)uVar19 * 2) {
            uVar15 = 0;
            uVar14 = (ulonglong)(uVar7 & 0xfffffff8);
            do {
              uVar9 = *(undefined4 *)(uVar15 + 0x2ac334fb4e4);
              uVar10 = *(undefined4 *)(uVar15 + 0x2ac334fb4e8);
              uVar11 = *(undefined4 *)(uVar15 + 0x2ac334fb4ec);
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              *puVar3 = *(undefined4 *)(&DAT_2ac334fb4e0 + uVar15);
              puVar3[1] = uVar9;
              puVar3[2] = uVar10;
              puVar3[3] = uVar11;
              uVar15 = uVar15 + 0x10;
              if ((uVar20 * 2 & 0xfffffffffffffff0) == uVar15) goto joined_r0x02ac334f5d96;
            } while( true );
          }
          uVar14 = 0;
        }
        do {
          *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_2ac334fb4e0 + uVar14 * 2);
          uVar14 = uVar14 + 1;
joined_r0x02ac334f5d96:
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
        cVar12 = FUN_2ac334d0100(&local_80);
        if (cVar12 == '\0') goto LAB_2ac334f60fb;
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
            if (uVar15 == uVar20) goto LAB_2ac334f5a79;
          }
          do {
            *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(lVar1 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar20 != uVar15);
        }
        goto LAB_2ac334f5a79;
      }
    }
LAB_2ac334f5a86:
    bVar21 = lVar17 == 3;
    lVar17 = lVar17 + 1;
    if (bVar21) {
      FUN_2ac334d0af0(&local_70,&local_80,0,0x2ac334fe9e0);
      FUN_2ac334d00a0(&local_80);
      FUN_2ac334d0af0(0x2ac33505c3c,&local_70,1,0x2ac334fe9f0);
      FUN_2ac334d00a0(&local_70);
      FUN_2ac334d00a0(&local_90);
      return;
    }
  } while( true );
}



/* Address: 2ac334f6140 */

/* WARNING: Removing unreachable block (ram,0x02ac334f6ad8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f6140(longlong param_1,longlong param_2)

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
    _DAT_2ac33505c10 = 0xfa9;
LAB_2ac334f62b5:
    uVar14 = 0xffffffff;
  }
  else {
    uVar6 = *(uint *)(psVar3 + -2);
    if ((uVar6 == 0) || (_DAT_2ac334fc00c == 0)) {
      _DAT_2ac33505c10 = 0x13ab;
      goto LAB_2ac334f62b5;
    }
    uVar14 = 0;
    if (psVar3 == (short *)0x2ac334fc010) goto LAB_2ac334f62bb;
    if ((uVar6 < _DAT_2ac334fc00c) || (uVar6 = (uVar6 - _DAT_2ac334fc00c) + 1, uVar6 == 0))
    goto LAB_2ac334f62b5;
    uVar13 = (ulonglong)uVar6;
    if (1 < _DAT_2ac334fc00c) {
      bVar17 = true;
      uVar12 = 1;
      uVar14 = 0;
      do {
        iVar9 = (int)uVar12;
        if (psVar3[uVar14] == 0x2d) {
          psVar16 = (short *)&DAT_2ac334fc012;
          lVar11 = (ulonglong)_DAT_2ac334fc00c - 1;
          while (psVar3[uVar12] == *psVar16) {
            psVar16 = psVar16 + 1;
            uVar12 = (ulonglong)((int)uVar12 + 1);
            lVar11 = lVar11 + -1;
            if (lVar11 == 0) goto LAB_2ac334f6f19;
          }
          if ((int)lVar11 == 0) {
LAB_2ac334f6f19:
            if (bVar17) goto LAB_2ac334f62bb;
            break;
          }
        }
        uVar14 = uVar14 + 1;
        uVar12 = (ulonglong)(iVar9 + 1);
        bVar17 = uVar14 < uVar13;
      } while (uVar14 != uVar13);
      goto LAB_2ac334f62b5;
    }
    if (*psVar3 != 0x2d) {
      uVar14 = 0;
      do {
        if (uVar13 - 1 == uVar14) goto LAB_2ac334f62b5;
        lVar11 = uVar14 + 1;
        uVar14 = uVar14 + 1;
      } while (psVar3[lVar11] != 0x2d);
      if (uVar13 <= uVar14) goto LAB_2ac334f62b5;
    }
  }
LAB_2ac334f62bb:
  FUN_2ac334d0460(psVar3,0x2ac334fc010,(int)uVar14 + 1);
  local_68 = 0;
  local_64 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ac334f6347:
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else {
      _DAT_2ac33505c10 = uVar7;
      if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
         (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    iVar9 = *(int *)(lVar11 + -4);
    if (iVar9 == 0) {
      uVar7 = 0x13ab;
      goto LAB_2ac334f6347;
    }
    iVar8 = 2;
    if (iVar9 < 2) {
      _DAT_2ac33505c10 = 0x13ab;
      iVar8 = iVar9;
    }
    FUN_2ac334d0280(0x2ac33505c3c,lVar11,iVar8);
  }
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334febb0);
  FUN_2ac334d0af0(&local_68,&local_e0,0,0x2ac334febc0);
  local_78 = 0;
  local_74 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ac334f644f:
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else {
      _DAT_2ac33505c10 = uVar7;
      if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
         (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar7 = 0x13ab;
    if (*(uint *)(lVar11 + -4) < 4) goto LAB_2ac334f644f;
    iVar8 = *(uint *)(lVar11 + -4) - 3;
    iVar9 = 2;
    if (iVar8 < 2) {
      _DAT_2ac33505c10 = 0x13ab;
      iVar9 = iVar8;
    }
    FUN_2ac334d0280(0x2ac33505c3c,lVar11 + 6,iVar9);
  }
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334febd0);
  FUN_2ac334d0af0(&local_78,&local_e0,0,0x2ac334febe0);
  local_98 = 0;
  local_94 = 0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_1 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ac334f6550:
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else {
      _DAT_2ac33505c10 = uVar7;
      if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
         (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar7 = 0x13ab;
    if (*(uint *)(lVar11 + -4) < 7) goto LAB_2ac334f6550;
    iVar8 = *(uint *)(lVar11 + -4) - 6;
    iVar9 = 4;
    if (iVar8 < 4) {
      _DAT_2ac33505c10 = 0x13ab;
      iVar9 = iVar8;
    }
    FUN_2ac334d0280(0x2ac33505c3c,lVar11 + 0xc,iVar9);
  }
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334febf0);
  FUN_2ac334d0af0(&local_98,&local_e0,0,0x2ac334fec00);
  psVar3 = *(short **)(param_2 + 4);
  if (psVar3 == (short *)0x0) {
    iVar9 = -1;
    _DAT_2ac33505c10 = 0xfa9;
joined_r0x02ac334f6686:
    if (_DAT_2ac33505c40 != (undefined2 *)0x0) {
      local_ec = 0;
      local_f0 = 0;
      if (_DAT_2ac33505c40 != (undefined2 *)0xc) {
        if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
           (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
          *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
          *puVar4 = 0;
        }
        goto LAB_2ac334f6768;
      }
    }
    local_ec = 0;
    local_f0 = 0;
    _DAT_2ac33505c10 = 0xfa9;
  }
  else {
    uVar6 = *(uint *)(psVar3 + -2);
    if ((uVar6 == 0) || (_DAT_2ac334fc01c == 0)) {
      _DAT_2ac33505c10 = 0x13ab;
      goto LAB_2ac334f6695;
    }
    uVar14 = 0;
    if (psVar3 == (short *)0x2ac334fc020) goto LAB_2ac334f669b;
    if ((uVar6 < _DAT_2ac334fc01c) || (uVar6 = (uVar6 - _DAT_2ac334fc01c) + 1, uVar6 == 0)) {
LAB_2ac334f6695:
      uVar14 = 0xffffffff;
    }
    else {
      local_c0 = (ulonglong)uVar6;
      if (1 < _DAT_2ac334fc01c) {
        bVar17 = true;
        uVar13 = 1;
        uVar14 = 0;
        local_58 = (ulonglong)_DAT_2ac334fc01c - 1;
        do {
          iVar9 = (int)uVar13;
          if (psVar3[uVar14] == 0x3a) {
            psVar16 = (short *)&DAT_2ac334fc022;
            lVar11 = local_58;
            while (psVar3[uVar13] == *psVar16) {
              psVar16 = psVar16 + 1;
              uVar13 = (ulonglong)((int)uVar13 + 1);
              lVar11 = lVar11 + -1;
              if (lVar11 == 0) goto LAB_2ac334f6f8a;
            }
            if ((int)lVar11 == 0) {
LAB_2ac334f6f8a:
              if (bVar17) goto LAB_2ac334f669b;
              break;
            }
          }
          uVar14 = uVar14 + 1;
          uVar13 = (ulonglong)(iVar9 + 1);
          bVar17 = uVar14 < local_c0;
        } while (uVar14 != local_c0);
        goto LAB_2ac334f6695;
      }
      if (*psVar3 != 0x3a) {
        uVar14 = 0;
        do {
          if (local_c0 - 1 == uVar14) goto LAB_2ac334f6695;
          lVar11 = uVar14 + 1;
          uVar14 = uVar14 + 1;
        } while (psVar3[lVar11] != 0x3a);
        if (local_c0 <= uVar14) goto LAB_2ac334f6695;
      }
    }
LAB_2ac334f669b:
    iVar9 = (int)uVar14;
    local_f0 = 0;
    local_ec = 0;
    if (psVar3 == (short *)0xc) {
      _DAT_2ac33505c10 = 0xfa9;
      goto joined_r0x02ac334f6686;
    }
    uVar6 = *(uint *)(psVar3 + -2);
    uVar13 = (ulonglong)uVar6;
    if (uVar6 == 0) {
      _DAT_2ac33505c10 = 0x13ab;
      goto joined_r0x02ac334f6686;
    }
    if (-1 < iVar9) {
      if ((int)uVar6 < iVar9) {
        _DAT_2ac33505c10 = 0x13ab;
      }
      else {
        uVar13 = uVar14 & 0xffffffff;
        if (iVar9 == 0) {
          iVar9 = 0;
          goto joined_r0x02ac334f6686;
        }
      }
    }
    FUN_2ac334d0280(0x2ac33505c3c,psVar3,uVar13);
  }
LAB_2ac334f6768:
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334fec10);
  FUN_2ac334d0af0(&local_f0,&local_e0,0,0x2ac334fec20);
  local_a8 = 0;
  local_a4 = 0;
  lVar11 = *(longlong *)(param_2 + 4);
  uVar7 = 0xfa9;
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ac334f682b:
    _DAT_2ac33505c10 = uVar7;
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
            (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
      *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
      *puVar4 = 0;
    }
  }
  else {
    uVar6 = *(uint *)(lVar11 + -4);
    uVar15 = iVar9 + 1;
    if (((int)uVar15 < 0) && (uVar15 = uVar15 + uVar6, (int)uVar15 < 0)) {
      uVar7 = 0x13ab;
      goto LAB_2ac334f682b;
    }
    iVar9 = uVar6 - uVar15;
    uVar7 = 0x13ab;
    if ((uVar6 < uVar15 || iVar9 == 0) ||
       ((iVar8 = 2, iVar9 < 2 &&
        (_DAT_2ac33505c10 = 0x13ab, uVar7 = _DAT_2ac33505c10, iVar8 = iVar9, iVar9 == 0))))
    goto LAB_2ac334f682b;
    FUN_2ac334d0280(0x2ac33505c3c,lVar11 + (ulonglong)uVar15 * 2,iVar8);
  }
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334fec30);
  FUN_2ac334d0af0(&local_a8,&local_e0,0,0x2ac334fec40);
  local_d0 = 0;
  local_cc = (undefined1 *)0x0;
  uVar7 = 0xfa9;
  lVar11 = *(longlong *)(param_2 + 4);
  if ((lVar11 == 0) || (lVar11 == 0xc)) {
LAB_2ac334f691f:
    if ((_DAT_2ac33505c40 == (undefined2 *)0x0) || (_DAT_2ac33505c40 == (undefined2 *)0xc)) {
      _DAT_2ac33505c10 = 0xfa9;
    }
    else {
      _DAT_2ac33505c10 = uVar7;
      if ((*(int *)(_DAT_2ac33505c40 + -2) != 0) &&
         (cVar5 = FUN_2ac334d0100(0x2ac33505c3c,0), puVar4 = _DAT_2ac33505c40, cVar5 != '\0')) {
        *(undefined4 *)(_DAT_2ac33505c40 + -2) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    uVar6 = *(uint *)(lVar11 + -4);
    uVar15 = uVar6 - 2;
    if (((int)uVar15 < 0) && (uVar15 = uVar15 + uVar6, (int)uVar15 < 0)) {
      uVar7 = 0x13ab;
      goto LAB_2ac334f691f;
    }
    uVar7 = 0x13ab;
    if (uVar6 <= uVar15) goto LAB_2ac334f691f;
    FUN_2ac334d0280(0x2ac33505c3c,lVar11 + (ulonglong)uVar15 * 2);
  }
  FUN_2ac334d0af0(&local_e0,0x2ac33505c3c,1,0x2ac334fec50);
  FUN_2ac334d0af0(&local_d0,&local_e0,0,0x2ac334fec60);
  lVar11 = (*(code *)0x7ff63a0fe4f0)(0x2ac301f9168,&local_f0);
  if (local_cc == &DAT_2ac334fc04c) {
    lVar10 = lVar11 + 0xc;
    if (lVar11 == 0xc) {
      lVar10 = lVar11;
    }
LAB_2ac334f6b23:
    uVar6 = *(uint *)(local_cc + -4);
    uVar15 = _DAT_2ac334fc088;
    if (uVar6 < _DAT_2ac334fc088) {
      uVar15 = uVar6;
    }
    iVar9 = uVar6 - _DAT_2ac334fc088;
    if (uVar15 != 0) {
      uVar14 = 0;
      do {
        uVar1 = *(ushort *)(local_cc + uVar14 * 2);
        uVar2 = *(ushort *)(&DAT_2ac334fc08c + uVar14 * 2);
        uVar14 = uVar14 + 1;
        if (uVar15 <= uVar14) break;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar9 = (uint)uVar1 - (uint)uVar2;
      }
    }
    if (iVar9 == 0) {
LAB_2ac334f6bfd:
      bVar17 = true;
      goto LAB_2ac334f6c14;
    }
    if (local_cc == &DAT_2ac334fc0ac) {
      iVar9 = 0;
    }
    else {
      if (local_cc == (undefined1 *)0x0) goto LAB_2ac334f6c02;
      uVar15 = _DAT_2ac334fc0a8;
      if (uVar6 < _DAT_2ac334fc0a8) {
        uVar15 = uVar6;
      }
      iVar9 = uVar6 - _DAT_2ac334fc0a8;
      if (uVar15 != 0) {
        uVar14 = 0;
        do {
          uVar1 = *(ushort *)(local_cc + uVar14 * 2);
          uVar2 = *(ushort *)(&DAT_2ac334fc0ac + uVar14 * 2);
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
LAB_2ac334f6aed:
      bVar17 = iVar9 == 0;
    }
    else {
      uVar6 = *(uint *)(local_cc + -4);
      uVar15 = _DAT_2ac334fc048;
      if (uVar6 < _DAT_2ac334fc048) {
        uVar15 = uVar6;
      }
      iVar9 = uVar6 - _DAT_2ac334fc048;
      if (uVar15 != 0) {
        uVar14 = 0;
        do {
          uVar1 = *(ushort *)(local_cc + uVar14 * 2);
          uVar2 = *(ushort *)(&DAT_2ac334fc04c + uVar14 * 2);
          uVar14 = uVar14 + 1;
          if (uVar15 <= uVar14) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar9 != 0) {
        if (local_cc == &DAT_2ac334fc06c) {
          iVar9 = 0;
        }
        else {
          uVar15 = _DAT_2ac334fc068;
          if (uVar6 < _DAT_2ac334fc068) {
            uVar15 = uVar6;
          }
          iVar9 = uVar6 - _DAT_2ac334fc068;
          if (uVar15 != 0) {
            uVar14 = 0;
            do {
              uVar1 = *(ushort *)(local_cc + uVar14 * 2);
              uVar2 = *(ushort *)(&DAT_2ac334fc06c + uVar14 * 2);
              uVar14 = uVar14 + 1;
              if (uVar15 <= uVar14) break;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar9 = (uint)uVar1 - (uint)uVar2;
            }
          }
        }
        goto LAB_2ac334f6aed;
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
    if (local_cc == &DAT_2ac334fc08c) goto LAB_2ac334f6bfd;
    if (local_cc != (undefined1 *)0x0) goto LAB_2ac334f6b23;
LAB_2ac334f6c02:
    iVar9 = 1;
  }
  bVar17 = iVar9 == 0;
LAB_2ac334f6c14:
  local_b8 = 0;
  local_b4 = 0;
  lVar11 = 0;
  if (lVar10 != 0xc) {
    lVar11 = lVar10;
  }
  if (!bVar17) {
    lVar11 = lVar10;
  }
  FUN_2ac334d0af0(&local_b8,0x2ac334f9160,0,0x2ac334fec70);
  if (lVar11 < 10) {
    FUN_2ac334d0af0(&local_b8,0x2ac334fc0c8,0,0x2ac334fec80);
  }
  local_88 = 0;
  local_84 = 0;
  FUN_2ac334d0af0(&local_88,0x2ac334f9160,0,0x2ac334fec90);
  (*(code *)0x7ff63a0e49f0)
            (0x2ac301f9168,0x174,0xb,0x59000a,&local_88,0x590008,&local_98,0x590008,0x2ac334fc0e8,
             0x590008,&local_68,0x590008,0x2ac334fc0e8,0x590008,&local_78,0x590008,0x2ac334fb4e8,
             0x590008,&local_b8,0x550005,lVar11,0x590008,0x2ac334fc028,0x590008,&local_a8);
  FUN_2ac334d0af0(&local_50,&local_88,0,0x2ac334feca0);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_b8);
  FUN_2ac334d00a0(&local_d0);
  FUN_2ac334d00a0(&local_a8);
  FUN_2ac334d00a0(&local_f0);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d00a0(&local_68);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_50,1,0x2ac334fecb0);
  FUN_2ac334d00a0(&local_50);
  FUN_2ac334d00a0(&local_e0);
  return;
}



/* Address: 2ac334f6fa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f6fa0(double param_1)

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
  FUN_2ac334d0af0(&local_78,0x2ac334fcbf0,0,0x2ac334ff250);
  if (param_1 <= 0.0) {
    FUN_2ac334d0af0(&local_78,0x2ac334f9160,0,0x2ac334ff260);
  }
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,param_1,2);
  FUN_2ac334d0af0(&local_68,0x2ac33505c3c,1,0x2ac334ff270);
  FUN_2ac334d0af0(&local_a8,&local_78);
  lVar2 = local_64;
  if (local_64 != 0) {
    uVar12 = *(uint *)(local_64 + -4);
    uVar9 = (ulonglong)uVar12;
    if ((uVar9 == 0) && (local_a4 != 0)) goto LAB_2ac334f71dd;
    if (local_a4 == 0) {
      uVar7 = 0;
      uVar8 = uVar12;
    }
    else {
      uVar7 = (ulonglong)*(uint *)(local_a4 + -4);
      uVar8 = uVar12 + *(uint *)(local_a4 + -4);
    }
    cVar5 = FUN_2ac334d0100(&local_a8);
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
          if (uVar7 == uVar9) goto LAB_2ac334f71d2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
          uVar7 = uVar7 + 1;
        } while (uVar9 != uVar7);
      }
LAB_2ac334f71d2:
      *(uint *)(local_a4 + -4) = uVar8;
      *(undefined2 *)(local_a4 + (ulonglong)uVar8 * 2) = 0;
      goto LAB_2ac334f71dd;
    }
LAB_2ac334f751f:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xe0aed000001f9);
LAB_2ac334f753f:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x2b0aed000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
LAB_2ac334f71dd:
  uVar12 = 0;
  FUN_2ac334d0af0(&local_98,&local_a8,0,0x2ac334ff290);
  uVar8 = _DAT_2ac334fb4dc;
  uVar9 = (ulonglong)_DAT_2ac334fb4dc;
  if ((uVar9 != 0) || (local_94 == 0)) {
    if (local_94 != 0) {
      uVar12 = *(uint *)(local_94 + -4);
    }
    uVar10 = _DAT_2ac334fb4dc + uVar12;
    uVar6 = 0x104;
    if ((0x103 < uVar10) &&
       ((0x7ffffffd < uVar10 || (uVar6 = (uVar10 >> 2) + uVar10, 0x7ffffffd < uVar6)))) {
      uVar6 = 0x7ffffffe;
    }
    cVar5 = FUN_2ac334d0100(&local_98,uVar6);
    if (cVar5 == '\0') {
      (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x270aed000001f9);
      goto LAB_2ac334f751f;
    }
    if (uVar9 != 0) {
      lVar2 = local_94 + (ulonglong)uVar12 * 2;
      if (uVar8 < 0x10) {
        uVar7 = 0;
      }
      else if (lVar2 - 0x2ac334fb4e0U < 0x20) {
        uVar7 = 0;
      }
      else {
        uVar11 = 0;
        uVar7 = (ulonglong)(uVar8 & 0xfffffff8);
        do {
          uVar4 = *(undefined8 *)(uVar11 + 0x2ac334fb4e8);
          *(undefined8 *)(lVar2 + uVar11) = *(undefined8 *)(&DAT_2ac334fb4e0 + uVar11);
          ((undefined8 *)(lVar2 + uVar11))[1] = uVar4;
          uVar11 = uVar11 + 0x10;
        } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
        if (uVar7 == uVar9) goto LAB_2ac334f7302;
      }
      do {
        *(undefined2 *)(lVar2 + uVar7 * 2) = *(undefined2 *)(&DAT_2ac334fb4e0 + uVar7 * 2);
        uVar7 = uVar7 + 1;
      } while (uVar9 != uVar7);
    }
LAB_2ac334f7302:
    *(uint *)(local_94 + -4) = uVar10;
    *(undefined2 *)(local_94 + (ulonglong)uVar10 * 2) = 0;
  }
  (*(code *)0x7ff63a0c7410)(0x2ac301f9168,0x24);
  FUN_2ac334d0af0(&local_58,0x2ac33505c3c,1,0x2ac334ff2a0);
  FUN_2ac334d0af0(&local_88,&local_98,0);
  lVar2 = local_54;
  if (local_54 == 0) goto LAB_2ac334f746d;
  uVar12 = *(uint *)(local_54 + -4);
  uVar9 = (ulonglong)uVar12;
  if ((uVar9 == 0) && (local_84 != 0)) goto LAB_2ac334f746d;
  if (local_84 == 0) {
    uVar7 = 0;
    uVar8 = uVar12;
  }
  else {
    uVar7 = (ulonglong)*(uint *)(local_84 + -4);
    uVar8 = uVar12 + *(uint *)(local_84 + -4);
  }
  cVar5 = FUN_2ac334d0100(&local_88);
  if (cVar5 == '\0') goto LAB_2ac334f753f;
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
      if (uVar7 == uVar9) goto LAB_2ac334f7462;
    }
    do {
      *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
      uVar7 = uVar7 + 1;
    } while (uVar9 != uVar7);
  }
LAB_2ac334f7462:
  *(uint *)(local_84 + -4) = uVar8;
  *(undefined2 *)(local_84 + (ulonglong)uVar8 * 2) = 0;
LAB_2ac334f746d:
  FUN_2ac334d0af0(&local_48,&local_88,0,0x2ac334ff2c0);
  FUN_2ac334d00a0(&local_78);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_48,1,0x2ac334ff2d0);
  FUN_2ac334d00a0(&local_48);
  FUN_2ac334d00a0(&local_68);
  FUN_2ac334d00a0(&local_a8);
  FUN_2ac334d00a0(&local_98);
  FUN_2ac334d00a0(&local_58);
  FUN_2ac334d00a0(&local_88);
  return;
}



/* Address: 2ac334f7560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f7560(double param_1)

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
  FUN_2ac334d0af0(&local_68,0x2ac334fcbf0,0,0x2ac334ff2e0);
  if (param_1 <= 0.0) {
    FUN_2ac334d0af0(&local_68,0x2ac334f9160,0,0x2ac334ff2f0);
  }
  (*(code *)0x7ff63a0fd7c0)(0x2ac301f9168,param_1,0);
  FUN_2ac334d0af0(&local_58,0x2ac33505c3c,1,0x2ac334ff300);
  FUN_2ac334d0af0(&local_88,&local_68);
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
      cVar5 = FUN_2ac334d0100(&local_88);
      if (cVar5 == '\0') goto LAB_2ac334f7949;
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
          if (uVar7 == uVar9) goto LAB_2ac334f7772;
        }
        do {
          *(undefined2 *)(lVar1 + uVar7 * 2) = *(undefined2 *)(lVar2 + uVar7 * 2);
          uVar7 = uVar7 + 1;
        } while (uVar9 != uVar7);
      }
LAB_2ac334f7772:
      *(uint *)(local_84 + -4) = uVar8;
      *(undefined2 *)(local_84 + (ulonglong)uVar8 * 2) = 0;
    }
  }
  uVar12 = 0;
  FUN_2ac334d0af0(&local_78,&local_88,0,0x2ac334ff320);
  uVar8 = _DAT_2ac334fcc08;
  uVar9 = (ulonglong)_DAT_2ac334fcc08;
  if ((uVar9 == 0) && (local_74 != 0)) goto LAB_2ac334f78ad;
  if (local_74 != 0) {
    uVar12 = *(uint *)(local_74 + -4);
  }
  uVar10 = _DAT_2ac334fcc08 + uVar12;
  uVar6 = 0x104;
  if ((0x103 < uVar10) &&
     ((0x7ffffffd < uVar10 || (uVar6 = (uVar10 >> 2) + uVar10, 0x7ffffffd < uVar6)))) {
    uVar6 = 0x7ffffffe;
  }
  cVar5 = FUN_2ac334d0100(&local_78,uVar6);
  if (cVar5 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0x280af2000001f9);
LAB_2ac334f7949:
    (*(code *)0x7ff639cc59a0)(0x2ac301f9168,0xe0af2000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar9 != 0) {
    lVar2 = local_74 + (ulonglong)uVar12 * 2;
    if (uVar8 < 0x10) {
      uVar7 = 0;
    }
    else if (lVar2 - 0x2ac334fcc0cU < 0x20) {
      uVar7 = 0;
    }
    else {
      uVar11 = 0;
      uVar7 = (ulonglong)(uVar8 & 0xfffffff8);
      do {
        uVar4 = *(undefined8 *)(uVar11 + 0x2ac334fcc14);
        *(undefined8 *)(lVar2 + uVar11) = *(undefined8 *)(&DAT_2ac334fcc0c + uVar11);
        ((undefined8 *)(lVar2 + uVar11))[1] = uVar4;
        uVar11 = uVar11 + 0x10;
      } while ((uVar9 * 2 & 0xfffffffffffffff0) != uVar11);
      if (uVar7 == uVar9) goto LAB_2ac334f78a2;
    }
    do {
      *(undefined2 *)(lVar2 + uVar7 * 2) = *(undefined2 *)(&DAT_2ac334fcc0c + uVar7 * 2);
      uVar7 = uVar7 + 1;
    } while (uVar9 != uVar7);
  }
LAB_2ac334f78a2:
  *(uint *)(local_74 + -4) = uVar10;
  *(undefined2 *)(local_74 + (ulonglong)uVar10 * 2) = 0;
LAB_2ac334f78ad:
  FUN_2ac334d0af0(&local_48,&local_78,0,0x2ac334ff330);
  FUN_2ac334d00a0(&local_68);
  FUN_2ac334d0af0(0x2ac33505c3c,&local_48,1,0x2ac334ff340);
  FUN_2ac334d00a0(&local_48);
  FUN_2ac334d00a0(&local_58);
  FUN_2ac334d00a0(&local_88);
  FUN_2ac334d00a0(&local_78);
  return;
}



/* Address: 2ac334f7970 */

void FUN_2ac334f7970(undefined8 param_1,undefined8 param_2,int param_3,int param_4,
                    undefined4 param_5,int param_6)

{
  int iVar1;
  
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,0,param_1);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x2ac301f9168,0,param_1);
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2ac301f9168,0x112,6,0x550005,0,0x590008,param_1,0x520004,0x66,0x520004,0,0x540005,0,
             0x580007,0);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0x402,0);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0x3f4,(longlong)param_3);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0x3f5,(longlong)param_4);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0x3f3,2);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0x3ea,(longlong)param_6);
  (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,0,param_1,0x3e9,0x2ac33505b20);
  (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,0,param_1,6,param_2);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,3,0);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0xcf,1000);
  (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,10,0);
  return;
}



/* Address: 2ac334f7ba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2ac334f7ba0(undefined8 param_1,longlong param_2,int param_3,longlong param_4)

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
  iVar6 = (*(code *)0x7ff63a0f4840)(0x2ac301f9168,0,param_1);
  if (iVar6 < 0) goto LAB_2ac334f7df1;
  local_60 = 0;
  local_5c = 0;
  (*(code *)0x7ff63a0f4a80)
            (0x2ac301f9168,0,param_1,6,in_stack_ffffffffffffff98 & 0xffffffff00000000);
  FUN_2ac334d0af0(&local_50,0x2ac33505c3c,1,0x2ac334ff370);
  FUN_2ac334d0af0(&local_60,&local_50,0,0x2ac334ff380);
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
      if (iVar6 == 0) goto LAB_2ac334f7de9;
    }
    (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,0,param_1,6,param_2);
    if (param_3 != -1) {
      (*(code *)0x7ff63a0f3b30)(0x2ac301f9168,0,param_1,0,param_3);
    }
    puVar5 = *(undefined1 **)(param_4 + 4);
    if (puVar5 != &DAT_2ac334f9158) {
      if (puVar5 != (undefined1 *)0x0) {
        uVar3 = *(uint *)(puVar5 + -4);
        uVar8 = _DAT_2ac334f9154;
        if (uVar3 < _DAT_2ac334f9154) {
          uVar8 = uVar3;
        }
        iVar6 = uVar3 - _DAT_2ac334f9154;
        if (uVar8 != 0) {
          uVar9 = 0;
          do {
            uVar1 = *(ushort *)(puVar5 + uVar9 * 2);
            uVar2 = *(ushort *)(&DAT_2ac334f9158 + uVar9 * 2);
            uVar9 = uVar9 + 1;
            if (uVar8 <= uVar9) break;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar6 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar6 == 0) goto LAB_2ac334f7de9;
      }
      (*(code *)0x7ff63a0f3c80)(0x2ac301f9168,0,param_1,0xce,param_4);
    }
  }
LAB_2ac334f7de9:
  FUN_2ac334d00a0(&local_60);
LAB_2ac334f7df1:
  FUN_2ac334d00a0(&local_50);
  return;
}



/* Address: 2ac334f7e10 */

void thunk_FUN_2ac334d0e00(void)

{
  FUN_2ac334d0e00();
  return;
}


