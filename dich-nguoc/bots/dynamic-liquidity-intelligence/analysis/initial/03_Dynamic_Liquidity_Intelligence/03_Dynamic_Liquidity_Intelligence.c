/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 146d4e40000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_146d4e40000(double param_1)

{
  uint uVar1;
  double dVar2;
  byte bVar3;
  double dVar4;
  double dVar5;
  
  dVar4 = ABS(param_1);
  uVar1 = (uint)((ulonglong)dVar4 >> 0x20);
  dVar2 = param_1;
  if (uVar1 >> 0x14 < 0x3ff) {
    if ((dVar4 != 0.0) && (dVar2 = 0.0, (longlong)param_1 < 0)) {
      return _DAT_146d4e5e000;
    }
  }
  else if (((uVar1 >> 0x16 < 0x10d) &&
           (bVar3 = 0x33 - (char)((ulonglong)dVar4 >> 0x34),
           dVar5 = (double)(((ulonglong)dVar4 >> (bVar3 & 0x3f)) << (bVar3 & 0x3f)), dVar2 = dVar5,
           (longlong)param_1 < 1)) &&
          (dVar2 = (double)((ulonglong)dVar5 | 0x8000000000000000), dVar5 != dVar4)) {
    dVar2 = dVar2 + _DAT_146d4e5e000;
  }
  return dVar2;
}



/* Address: 146d4e400a0 */

void FUN_146d4e400a0(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x146d2d8aad8);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 146d4e40100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e40100(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x146d2d8aad8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_146d4e4025d;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_146d4e4025d;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x146d2d8aad8);
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
        if (uVar15 < 8) goto LAB_146d4e401c0;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_146d4e401c0;
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
LAB_146d4e401c0:
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
          (*(code *)0x7ff63a101200)(0x146d2d8aad8,puVar14);
        }
      }
      goto LAB_146d4e4025d;
    }
  }
  _DAT_146d4e68510 = 0x13aa;
  uVar12 = 0;
LAB_146d4e4025d:
  return uVar12 & 0xffffffff;
}



/* Address: 146d4e40270 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_146d4e40270(uint *param_1,short *param_2)

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
  
  uVar21 = _DAT_146d4e623c4;
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
      puVar29 = (undefined1 *)(longlong)(int)_DAT_146d4e623c4;
      iVar11 = (int)((longlong)(int)uVar20 / (longlong)(int)uVar6) * _DAT_146d4e623c4;
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
LAB_146d4e403b0:
          if ((uint)uVar24 == uVar6) goto LAB_146d4e403b9;
          iVar19 = uVar18 + 1;
        }
        else {
          uVar24 = 1;
          do {
            uVar5 = *(ushort *)(lVar7 + (longlong)(int)uVar18 * 2 + uVar24 * 2);
            puVar14 = (undefined1 *)(ulonglong)uVar5;
            if (uVar5 != param_2[uVar24]) goto LAB_146d4e403b0;
            uVar24 = uVar24 + 1;
          } while (uVar6 != uVar24);
LAB_146d4e403b9:
          if (puVar15 == (uint *)0x0) {
            puVar13 = (uint *)(*(code *)0x7ff63a101190)(0x146d2d8aad8,iVar11 + uVar20);
            if (puVar13 == (uint *)0x0) {
              _DAT_146d4e68510 = 0x13aa;
              return &DAT_146d4e68510;
            }
            puVar13[1] = 1;
            puVar13[2] = 0;
            puVar15 = puVar13 + 3;
            *(undefined2 *)(puVar13 + 3) = 0;
            local_68 = *puVar13;
            puVar14 = (undefined1 *)(ulonglong)local_68;
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) goto LAB_146d4e40443;
          }
          else {
            uVar16 = uVar18 - iVar23;
            if (uVar16 != 0 && iVar23 <= (int)uVar18) {
LAB_146d4e40443:
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
                    if (puVar27 == puVar14) goto joined_r0x0146d4e404a6;
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
joined_r0x0146d4e404a6:
              } while (puVar27 != puVar22);
              uVar26 = uVar26 + uVar16;
            }
          }
          if (uVar21 != 0) {
            lVar17 = (longlong)(int)uVar26;
            if (uVar21 < 8) {
              puVar22 = (undefined1 *)0x0;
            }
            else if ((ulonglong)((longlong)puVar15 + lVar17 * 2 + -0x146d4e623c8) < 0x20) {
              puVar22 = (undefined1 *)0x0;
            }
            else {
              puVar14 = (undefined1 *)0x0;
              do {
                lVar2 = (longlong)puVar14 * 2;
                uVar8 = *(undefined4 *)(lVar2 + 0x146d4e623cc);
                uVar9 = *(undefined4 *)(lVar2 + 0x146d4e623d0);
                uVar10 = *(undefined4 *)(lVar2 + 0x146d4e623d4);
                puVar3 = (undefined4 *)((longlong)puVar15 + (longlong)puVar14 * 2 + lVar17 * 2);
                *puVar3 = *(undefined4 *)(&DAT_146d4e623c8 + lVar2);
                puVar3[1] = uVar8;
                puVar3[2] = uVar9;
                puVar3[3] = uVar10;
                puVar14 = puVar14 + 8;
              } while (puVar12 != puVar14);
              puVar14 = puVar12;
              puVar22 = puVar12;
              if (puVar12 == puVar29) goto LAB_146d4e40552;
            }
            do {
              uVar5 = *(ushort *)(&DAT_146d4e623c8 + (longlong)puVar22 * 2);
              *(ushort *)((longlong)puVar15 + (longlong)puVar22 * 2 + lVar17 * 2) = uVar5;
              puVar22 = puVar22 + 1;
              puVar14 = (undefined1 *)(ulonglong)uVar5;
            } while (puVar29 != puVar22);
          }
LAB_146d4e40552:
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
              if (uVar25 == uVar28) goto joined_r0x0146d4e40619;
            } while( true );
          }
          uVar25 = 0;
        }
        do {
          *(undefined2 *)((longlong)puVar15 + uVar25 * 2 + (longlong)(int)uVar26 * 2) =
               *(undefined2 *)(lVar7 + uVar25 * 2);
          uVar25 = uVar25 + 1;
joined_r0x0146d4e40619:
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
          puVar12 = (undefined1 *)(*(code *)0x7ff63a101200)(0x146d2d8aad8);
          return puVar12;
        }
        return puVar12;
      }
      return puVar12;
    }
  }
  _DAT_146d4e68510 = 0x13b0;
  return &DAT_146d4e68510;
}



/* Address: 146d4e405c0 */

void FUN_146d4e405c0(longlong param_1)

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
      (*(code *)0x7ff63a101200)(0x146d2d8aad8);
      return;
    }
  }
  return;
}



/* Address: 146d4e406b0 */

ulonglong FUN_146d4e406b0(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_146d4e407bd;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_146d4e407bd;
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
  cVar5 = FUN_146d4e40100(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_146d4e407bd;
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
      if (uVar10 == uVar9) goto LAB_146d4e407b2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_146d4e407b2:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_146d4e407bd:
  return uVar8 & 0xffffffff;
}



/* Address: 146d4e407d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e407d0(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x146d2d8aad8);
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
        (*(code *)0x7ff63a101200)(0x146d2d8aad8,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x146d2d8aad8,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_146d4e68510 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x146d2d8aad8,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_146d4e40960;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_146d4e40960:
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
      (*(code *)0x7ff63a101200)(0x146d2d8aad8);
      return;
    }
  }
  return;
}



/* Address: 146d4e409f0 */

void FUN_146d4e409f0(longlong param_1)

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
    (*(code *)0x7ff63a0e6ef0)(0x146d2d8aad8,lVar2 - *(int *)(lVar2 + -4),0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 146d4e40ac0 */

undefined8 FUN_146d4e40ac0(void)

{
  return 0;
}



/* Address: 146d4e40ad0 */

void FUN_146d4e40ad0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x146d2d8aad8,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 146d4e40b20 */

undefined4 FUN_146d4e40b20(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_146d4e407d0(&local_70,0x146d4e5e910,0,0x146d4e64258);
  local_80 = 0;
  local_7c = 0;
  FUN_146d4e407d0(&local_80,0x146d4e5e910,0,0x146d4e64268);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x146d2d8aad8,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_146d4e40cf2;
    uVar4 = 0x146d4e642a8;
    uVar3 = 0x146d4e64298;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_146d4e40cf2;
    uVar4 = 0x146d4e64288;
    uVar3 = 0x146d4e64278;
  }
  FUN_146d4e4ba00(&local_80,param_2,param_3);
  FUN_146d4e407d0(&local_60,&DAT_146d4e6853c,1,uVar3);
  FUN_146d4e4dd20(param_1,&local_70,param_2);
  FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x146d2d8aad8,0xd,3,0x590008,0x146d4e5f638,0x590008,&local_50,0x590008,&local_60);
LAB_146d4e40cf2:
  FUN_146d4e400a0(&local_80);
  FUN_146d4e400a0(&local_70);
  FUN_146d4e400a0(&local_60);
  FUN_146d4e400a0(&local_50);
  return uVar1;
}



/* Address: 146d4e40d30 */

void FUN_146d4e40d30(undefined8 *param_1)

{
  FUN_146d4e400a0(param_1 + 0x41);
  FUN_146d4e400a0((longlong)param_1 + 0x144);
  FUN_146d4e400a0((longlong)param_1 + 0x84);
  FUN_146d4e400a0((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x146d2d8aad8,*param_1,0x146d2d79600);
  param_1[1] = 0x146d4e5e810;
  return;
}



/* Address: 146d4e40da0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e40da0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  code *pcVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong lVar14;
  byte bVar15;
  longlong lVar16;
  int iVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  double dVar20;
  double dVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined4 uVar26;
  undefined8 in_stack_fffffffffffffea8;
  undefined4 uVar28;
  undefined4 *puVar27;
  undefined4 uVar29;
  undefined8 in_stack_fffffffffffffeb8;
  undefined4 uVar30;
  int local_fc;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined8 local_a8;
  undefined4 local_a0;
  
  iVar8 = 0;
  local_b8 = 0;
  local_e8 = 0;
  local_b4 = 0;
  local_e4 = 0;
  _DAT_146d4e68375 = 0xa0a3;
  if (DAT_146d4e68059 == '\0') {
    _DAT_146d4e68375 = 0;
  }
  iVar17 = 0;
  if (DAT_146d4e68071 != '\0') {
    iVar17 = 10;
  }
  iVar9 = 10;
  if (DAT_146d4e68002 == '\0') {
    iVar9 = iVar8;
  }
  if (DAT_146d4e68000 != '\0') {
    iVar9 = iVar17;
  }
  iVar17 = 0;
  if (iVar9 != 0) {
    if ((_DAT_146d4e68520 == 5) || (dVar20 = _DAT_146d4e68518, _DAT_146d4e68520 == 3)) {
      dVar20 = _DAT_146d4e5e008 * _DAT_146d4e68518;
    }
    iVar17 = iVar9;
    if ((0.0 < dVar20) && (0.0 < _DAT_146d4e68518)) {
      if ((_DAT_146d4e68518 == 0.0) && (!NAN(_DAT_146d4e68518))) {
        (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x400904000001f7);
        pcVar5 = (code *)swi(3);
        uVar12 = (*pcVar5)();
        return uVar12;
      }
      dVar20 = dVar20 / _DAT_146d4e68518;
      uVar10 = (uint)((ulonglong)dVar20 >> 0x34) & 0x7ff;
      lVar13 = (ulonglong)uVar10 - 0x3ff;
      dVar21 = dVar20;
      if ((ulonglong)uVar10 < 0x433) {
        if (uVar10 < 0x3ff) {
          dVar21 = (double)((ulonglong)dVar20 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar13 != -1) {
            dVar21 = (double)((ulonglong)dVar20 & 0x8000000000000000);
          }
        }
        else {
          bVar15 = (byte)lVar13;
          if (((longlong)dVar20 << (bVar15 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar21 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar20 &
                             -0x10000000000000 >> (bVar15 & 0x3f));
          }
        }
      }
      else if (lVar13 == 0x400) {
        dVar21 = dVar20 + dVar20;
      }
      dVar20 = _DAT_146d4e5e010;
      if (_DAT_146d4e5e010 <= dVar21) {
        dVar20 = dVar21;
      }
      iVar17 = iVar9 * (int)dVar20;
    }
  }
  _DAT_146d4e6837d = (longlong)iVar17;
  uVar11 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e68528,0x32);
  if (((uVar11 & 1) != 0) || (iVar8 = 1, (uVar11 & 2) != 0)) {
    _DAT_146d4e68385 = iVar8;
  }
  DAT_146d4e683bc = 0;
  DAT_146d4e683bd = 0;
  _DAT_146d4e683a8 = 0.0;
  DAT_146d4e683b0 = 0;
  _DAT_146d4e683b8 = 0;
  FUN_146d4e407d0(&DAT_146d4e683c0,0x146d4e5e968,0,0x146d4e63f60);
  DAT_146d4e683cd = 0;
  FUN_146d4e407d0(&DAT_146d4e683d0,0x146d4e5e910,0,0x146d4e63f70);
  FUN_146d4e407d0(&DAT_146d4e683e0,0x146d4e5e910,0,0x146d4e63f80);
  FUN_146d4e407d0(&DAT_146d4e683f0,0x146d4e5e910,0,0x146d4e63f90);
  FUN_146d4e407d0(&DAT_146d4e68400,0x146d4e5e910,0,0x146d4e63fa0);
  FUN_146d4e407d0(&DAT_146d4e68410,0x146d4e5e910,0,0x146d4e63fb0);
  local_c8 = 0;
  local_d8 = 0;
  local_c4 = 0;
  _DAT_146d4e683a8 = 0.0;
  DAT_146d4e683b0 = '\0';
  local_d4 = 0;
  FUN_146d4e5c7e0();
  bVar4 = true;
  FUN_146d4e407d0(&local_c8,&DAT_146d4e6853c,1,0x146d4e65818);
  FUN_146d4e407d0(&local_d8,&local_c8,0,0x146d4e65828);
  cVar7 = (*(code *)0x7ff63a0edda0)(0x146d2d8aad8,&local_d8);
  if ((cVar7 != '\0') &&
     ((*(code *)0x7ff63a0edbe0)(0x146d2d8aad8,&local_d8), 0.0 < _DAT_146d4e68548)) {
    _DAT_146d4e683a8 = (double)FUN_146d4e59600(0x146d4e68528);
    bVar4 = false;
  }
  uVar12 = (*(code *)0x7ff63a101c40)(0x146d2d8aad8,0);
  cVar7 = (*(code *)0x7ff63a1084f0)(0x146d2d8aad8,0,uVar12);
  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
  if (cVar7 == '\0') {
    _DAT_146d4e683b4 = 0;
    if (!bVar4) {
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,_DAT_146d4e683a8,2);
      FUN_146d4e407d0(&local_c8,&DAT_146d4e6853c,1,0x146d4e65848);
      uVar12 = 0x146d4e62680;
      goto LAB_146d4e41725;
    }
  }
  else {
    _DAT_146d4e683b4 = (*(code *)0x7ff63a108810)(0x146d2d8aad8);
    local_f8 = 0;
    local_f4 = 0;
    DAT_146d4e683b0 = '\0';
    iVar8 = (*(code *)0x7ff63a108810)(0x146d2d8aad8);
    uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
    uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    uVar22 = 0;
    uVar26 = 0;
    uVar29 = 0;
    uVar23 = 0;
    if (0 < iVar8) {
      iVar17 = 0;
      do {
        lVar13 = (*(code *)0x7ff63a108860)(0x146d2d8aad8,iVar17);
        if (lVar13 != 0) {
          iVar9 = (*(code *)0x7ff63a108940)(0x146d2d8aad8,lVar13,3);
          if ((iVar9 - 2U < 0xb) && ((0x41fU >> (iVar9 - 2U & 0x1f) & 1) != 0)) {
            uVar29 = 0;
            uVar23 = 0;
            DAT_146d4e683b0 = '\x01';
          }
          else {
            (*(code *)0x7ff63a1089d0)(0x146d2d8aad8,lVar13,0);
            FUN_146d4e407d0(&local_f8,&DAT_146d4e6853c,1,0x146d4e65808);
            if (local_f4 == _DAT_146d4e6852c) {
LAB_146d4e4148f:
              lVar14 = (*(code *)0x7ff63a108940)(0x146d2d8aad8,lVar13,0xb);
              lVar16 = 0;
              if (DAT_146d4e68059 != '\0') {
                lVar16 = 0xa0a3;
              }
              if (((lVar14 == lVar16) &&
                  (uVar10 = (*(code *)0x7ff63a108940)(0x146d2d8aad8,lVar13,4),
                  (uVar10 & 0xfffffffd) == 1)) &&
                 ((*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar13,5), dVar20 = _DAT_146d4e68548,
                 0.0 < _DAT_146d4e68548)) {
                (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar13,9);
                dVar21 = _DAT_146d4e68548;
                (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar13,8);
                dVar21 = dVar21 + _DAT_146d4e68548;
                (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar13,7);
                dVar21 = dVar21 + _DAT_146d4e68548;
                (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar13,0x11);
                if (dVar21 + _DAT_146d4e68548 < 0.0) {
                  uVar12 = FUN_146d4e59600(0x146d4e68528,dVar20);
                  uVar29 = (undefined4)uVar12;
                  uVar23 = (undefined4)((ulonglong)uVar12 >> 0x20);
                  DAT_146d4e683b0 = '\0';
                }
              }
            }
            else if ((local_f4 != 0) && (_DAT_146d4e6852c != 0)) {
              uVar10 = *(uint *)(local_f4 + -4);
              uVar3 = *(uint *)(_DAT_146d4e6852c + -4);
              uVar6 = uVar3;
              if (uVar10 < uVar3) {
                uVar6 = uVar10;
              }
              iVar9 = uVar10 - uVar3;
              if (uVar6 != 0) {
                uVar11 = 1;
                do {
                  uVar1 = *(ushort *)(local_f4 + -2 + uVar11 * 2);
                  uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar11 * 2);
                  if (uVar6 <= uVar11) break;
                  uVar11 = uVar11 + 1;
                } while (uVar1 == uVar2);
                if (uVar1 != uVar2) {
                  iVar9 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar9 == 0) goto LAB_146d4e4148f;
            }
          }
        }
        uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
        uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
        iVar17 = iVar17 + 1;
      } while (iVar17 != iVar8);
    }
    FUN_146d4e400a0(&local_f8);
    local_f8 = 0;
    local_f4 = 0;
    local_a8 = 0;
    local_a0 = 0;
    _DAT_146d4e683a8 = (double)CONCAT44(uVar23,uVar29);
    FUN_146d4e5c7e0();
    FUN_146d4e407d0(&local_f8,&DAT_146d4e6853c,1,0x146d4e657e8);
    FUN_146d4e407d0(&local_a8,&local_f8,0,0x146d4e657f8);
    if (0.0 < _DAT_146d4e683a8) {
      uVar12 = FUN_146d4e59600(0x146d4e68528);
      uVar22 = (undefined4)uVar12;
      uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);
    }
    (*(code *)0x7ff63a0edc90)(0x146d2d8aad8,&local_a8,CONCAT44(uVar26,uVar22));
    FUN_146d4e400a0(&local_a8);
    FUN_146d4e400a0(&local_f8);
    if (_DAT_146d4e683a8 <= 0.0) {
      if (DAT_146d4e683b0 == '\0') {
        if (bVar4) goto LAB_146d4e417af;
        uVar12 = 0x146d4e625f8;
      }
      else {
        uVar12 = 0x146d4e62558;
      }
      uVar18 = 1;
    }
    else {
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,_DAT_146d4e683a8,2);
      FUN_146d4e407d0(&local_c8,&DAT_146d4e6853c,1,0x146d4e65838);
      uVar12 = 0x146d4e624b8;
LAB_146d4e41725:
      uVar30 = 0x146;
      uVar28 = (undefined4)((ulonglong)&local_c8 >> 0x20);
      uVar18 = 3;
    }
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,uVar18,0x590008,uVar12);
  }
LAB_146d4e417af:
  FUN_146d4e400a0(&local_d8);
  FUN_146d4e400a0(&local_c8);
  local_fc = 0xf;
  iVar8 = 0;
  if (DAT_146d4e68070 != '\0') {
    iVar8 = 0xf;
  }
  if (DAT_146d4e68001 == '\0') {
    local_fc = 0;
  }
  if (DAT_146d4e68000 != '\0') {
    local_fc = iVar8;
  }
  if (local_fc == 0) {
    local_fc = _DAT_146d4e68524;
  }
  uVar29 = 0x520004;
  uVar26 = 0x520004;
  uVar22 = 0;
  if (DAT_146d4e68074 != '\0') {
    uVar22 = 0xe;
  }
  uVar23 = 0;
  if (DAT_146d4e68005 != '\0') {
    uVar23 = 0xe;
  }
  if (DAT_146d4e68000 != '\0') {
    uVar23 = uVar22;
  }
  uVar12 = CONCAT44(uVar30,uVar23);
  puVar27 = (undefined4 *)CONCAT44(uVar28,local_fc);
  _DAT_146d4e68394 =
       (*(code *)0x7ff63a0e49f0)
                 (0x146d2d8aad8,0x53,3,0x590008,0x146d4e5e890,0x520004,puVar27,0x520004,uVar12);
  if (_DAT_146d4e68394 == -1) {
    uVar24 = 1;
    uVar18 = 2;
    uVar19 = 1;
    uVar25 = 0x146d4e5e9c8;
  }
  else {
    if (local_fc == 0) {
      uVar18 = 1;
      uVar24 = 0x146d4e5ea90;
    }
    else {
      FUN_146d4e421a0(local_fc);
      puVar27 = &local_e8;
      FUN_146d4e407d0(puVar27,&DAT_146d4e6853c,1,0x146d4e63fc0);
      uVar18 = 3;
      uVar29 = 0x590008;
      uVar26 = 0x590008;
      uVar12 = 0x146d4e5eb60;
      uVar24 = 0x146d4e5eaf8;
    }
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,uVar18,0x590008,uVar24,uVar26,puVar27,uVar29,uVar12);
    if (_DAT_146d4e68638 != 0) {
      if (_DAT_146d4e68638 == 1) {
        uVar18 = 0x146d4e5ec98;
        uVar12 = 0x146d4e5ecc8;
        if (DAT_146d4e6806c != '\0') {
          uVar12 = 0x146d4e5ec98;
        }
        if (DAT_146d4e6806d == '\0') {
          uVar18 = 0x146d4e5ecc8;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x146d2d8aad8,0xd8,7,0x590008,0x146d4e5ec70,0x580007,_DAT_146d4e68648,0x590008,
                   0x146d4e5ecc8,0x590008,uVar18,0x580007,_DAT_146d4e68650,0x580007,_DAT_146d4e68658
                   ,0x590008,uVar12);
        uVar12 = 0x146d4e63fd0;
      }
      else {
        if (_DAT_146d4e68638 - 2U < 9) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e41afa */
                    /* WARNING: Treating indirect jump as call */
          uVar12 = (**(code **)((ulonglong)(_DAT_146d4e68638 - 2U) * 8 + 0x146d4e5e058))();
          return uVar12;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x146d2d8aad8,0xd8,3,0x590008,0x146d4e5ed40,0x580007,0,0x580007,_DAT_146d4e680d0)
        ;
        uVar12 = 0x146d4e63fe0;
      }
      FUN_146d4e407d0(&local_e8,&DAT_146d4e6853c,1,uVar12);
      (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,&local_e8);
    }
    local_f8 = 0;
    local_f4 = 0;
    if (DAT_146d4e68000 == '\0') {
      uVar12 = 0x146d4e632e8;
      uVar18 = 0x146d4e65c38;
    }
    else {
      uVar12 = 0x146d4e63328;
      uVar18 = 0x146d4e65c48;
    }
    FUN_146d4e407d0(&local_f8,uVar12,0,uVar18);
    FUN_146d4e407d0(&DAT_146d4e6853c,&local_f8,1,0x146d4e65c58);
    FUN_146d4e400a0(&local_f8);
    FUN_146d4e407d0(&local_e8,&DAT_146d4e6853c,1,0x146d4e63ff0);
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,2,0x590008,0x146d4e5ed90,0x590008,&local_e8);
    FUN_146d4e42480();
    FUN_146d4e407d0(&local_e8,&DAT_146d4e6853c,1,0x146d4e64000);
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,2,0x590008,0x146d4e5ede0,0x590008,&local_e8);
    FUN_146d4e42960();
    local_f8 = 0;
    local_f4 = 0;
    iVar8 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e61850);
    if (-1 < iVar8) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e61850);
    }
    iVar8 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e61898);
    if (-1 < iVar8) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e61898);
    }
    if (DAT_146d4e687e0 != '\0') {
      iVar8 = (*(code *)0x7ff63a1081a0)(0x146d2d8aad8);
      iVar8 = iVar8 + -1;
      if (-1 < iVar8) {
        do {
          lVar13 = (*(code *)0x7ff63a1081f0)(0x146d2d8aad8,iVar8);
          if ((lVar13 != 0) &&
             (cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,lVar13), cVar7 != '\0')) {
            (*(code *)0x7ff63a1083a0)(0x146d2d8aad8,0);
            FUN_146d4e407d0(&local_f8,&DAT_146d4e6853c,1,0x146d4e65548);
            if (local_f4 == _DAT_146d4e6852c) {
LAB_146d4e41f25:
              lVar13 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,0xf);
              lVar14 = 0;
              if (DAT_146d4e68059 != '\0') {
                lVar14 = 0xa0a3;
              }
              if ((lVar13 == lVar14) &&
                 (iVar17 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,4), 0xfffffffd < iVar17 - 6U)) {
                (*(code *)0x7ff63a108280)(0x146d2d8aad8,7);
                dVar20 = _DAT_146d4e68548;
                (*(code *)0x7ff63a108280)(0x146d2d8aad8,0xc);
                dVar21 = _DAT_146d4e68548;
                (*(code *)0x7ff63a108280)(0x146d2d8aad8,9);
                FUN_146d4e58fa0(iVar17,_DAT_146d4e68548,dVar21,dVar20);
              }
            }
            else if ((local_f4 != 0) && (_DAT_146d4e6852c != 0)) {
              uVar10 = *(uint *)(local_f4 + -4);
              uVar3 = *(uint *)(_DAT_146d4e6852c + -4);
              uVar6 = uVar3;
              if (uVar10 < uVar3) {
                uVar6 = uVar10;
              }
              iVar17 = uVar10 - uVar3;
              if (uVar6 != 0) {
                uVar11 = 1;
                do {
                  uVar1 = *(ushort *)(local_f4 + -2 + uVar11 * 2);
                  uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar11 * 2);
                  if (uVar6 <= uVar11) break;
                  uVar11 = uVar11 + 1;
                } while (uVar1 == uVar2);
                if (uVar1 != uVar2) {
                  iVar17 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar17 == 0) goto LAB_146d4e41f25;
            }
          }
          bVar4 = 0 < iVar8;
          iVar8 = iVar8 + -1;
        } while (bVar4);
      }
    }
    FUN_146d4e400a0(&local_f8);
    FUN_146d4e42ba0();
    uVar24 = 0;
    if ((local_fc == 0) || (_DAT_146d4e68524 == local_fc)) goto LAB_146d4e4211d;
    FUN_146d4e421a0();
    FUN_146d4e407d0(&local_e8,&DAT_146d4e6853c,1,0x146d4e64010);
    FUN_146d4e421a0(local_fc);
    puVar27 = &local_b8;
    FUN_146d4e407d0(puVar27,&DAT_146d4e6853c,1,0x146d4e64020);
    uVar18 = 3;
    uVar19 = 5;
    uVar29 = 0x590008;
    uVar26 = 0x590008;
    uVar25 = 0x146d4e5ee68;
    uVar12 = 0x146d4e5eeb8;
  }
  (*(code *)0x7ff63a0e49f0)
            (0x146d2d8aad8,uVar18,uVar19,0x590008,uVar25,uVar26,puVar27,uVar29,uVar12);
LAB_146d4e4211d:
  FUN_146d4e400a0(&local_e8);
  FUN_146d4e400a0(&local_b8);
  return uVar24;
}



/* Address: 146d4e421a0 */

void FUN_146d4e421a0(uint param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 local_20;
  undefined8 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if ((int)param_1 < 0x4001) {
    if (param_1 < 0x1f) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e421de */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((ulonglong)param_1 * 8 + 0x146d4e5e0a0))();
      return;
    }
  }
  else {
    if (param_1 - 0x4001 < 0x18) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4220f */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((ulonglong)(param_1 - 0x4001) * 8 + 0x146d4e5e198))();
      return;
    }
    if (param_1 == 0x8001) {
      uVar1 = 0x146d4e62e68;
      uVar2 = 0x146d4e65a48;
      goto LAB_146d4e4243c;
    }
    if (param_1 == 0xc001) {
      uVar1 = 0x146d4e62e98;
      uVar2 = 0x146d4e65a58;
      goto LAB_146d4e4243c;
    }
  }
  uVar1 = 0x146d4e61960;
  uVar2 = 0x146d4e65a68;
LAB_146d4e4243c:
  FUN_146d4e407d0(&local_20,uVar1,0,uVar2);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_20,1,0x146d4e65a78);
  FUN_146d4e400a0(&local_20);
  return;
}



/* Address: 146d4e42480 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e42480(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  int iVar10;
  int *piVar11;
  longlong lVar12;
  int *piVar13;
  ulonglong uVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  bool bVar24;
  int local_60;
  undefined8 uStack_5c;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_40;
  undefined8 local_3c;
  
  local_50 = 0;
  local_40 = 0;
  local_4c = 0;
  local_3c = 0;
  local_60 = 0;
  uStack_5c._0_4_ = 0;
  uStack_5c._4_4_ = 0;
  FUN_146d4e407d0(&local_60,&DAT_146d4e68060,0,0x146d4e65a88);
  piVar18 = (int *)CONCAT44(uStack_5c._4_4_,(undefined4)uStack_5c);
  uStack_5c = piVar18;
  if ((piVar18 == (int *)0x0) || (piVar13 = piVar18 + -3, piVar13 == (int *)0x0)) {
    _DAT_146d4e68510 = 0xfa9;
  }
  else {
    uVar16 = piVar18[-1];
    uVar20 = (ulonglong)uVar16;
    if (uVar20 != 0) {
      uVar23 = 0;
      do {
        uVar14 = (ulonglong)*(ushort *)((longlong)piVar18 + uVar23 * 2);
        uVar21 = uVar23;
        if ((0x20 < uVar14) || ((0x100002600U >> (uVar14 & 0x3f) & 1) == 0)) break;
        uVar23 = uVar23 + 1;
        uVar21 = uVar20;
      } while (uVar20 != uVar23);
      uVar19 = (uint)uVar21;
      if (uVar19 != 0) {
        uVar17 = uVar16 - uVar19;
        piVar11 = (int *)(*(code *)0x7ff63a101190)(0x146d2d8aad8,uVar17);
        if (piVar11 == (int *)0x0) {
          _DAT_146d4e68510 = 0x13aa;
          uStack_5c = (int *)CONCAT44(uStack_5c._4_4_,(undefined4)uStack_5c);
        }
        else {
          piVar11[1] = 1;
          piVar11[2] = 0;
          *(undefined2 *)(piVar11 + 3) = 0;
          uStack_5c = piVar11 + 3;
          uVar20 = (ulonglong)uVar17;
          iVar10 = *piVar11;
          if (uVar16 != uVar19) {
            uVar21 = uVar21 & 0xffffffff;
            uVar23 = uVar20 + (uVar20 == 0);
            if ((0xf < uVar17) &&
               (0x1f < (ulonglong)((longlong)piVar11 - (longlong)((longlong)piVar13 + uVar21 * 2))))
            {
              uVar22 = 0;
              uVar14 = (ulonglong)((uint)uVar23 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)((longlong)piVar18 + uVar22 * 2 + uVar21 * 2);
                uVar6 = puVar1[1];
                uVar7 = puVar1[2];
                uVar8 = puVar1[3];
                puVar2 = (undefined4 *)((longlong)uStack_5c + uVar22 * 2);
                *puVar2 = *puVar1;
                puVar2[1] = uVar6;
                puVar2[2] = uVar7;
                puVar2[3] = uVar8;
                uVar22 = uVar22 + 8;
                if (uVar14 == uVar22) goto LAB_146d4e42902;
              } while( true );
            }
            uVar14 = 0;
            do {
              *(undefined2 *)((longlong)uStack_5c + uVar14 * 2) =
                   *(undefined2 *)((longlong)piVar18 + uVar14 * 2 + uVar21 * 2);
              uVar14 = uVar14 + 1;
LAB_146d4e42902:
            } while (uVar23 != uVar14);
          }
          piVar11[2] = uVar17;
          *(undefined2 *)((longlong)uStack_5c + uVar20 * 2) = 0;
          bVar24 = local_60 != 0;
          local_60 = iVar10;
          if ((bVar24) && (*piVar13 != 0)) {
            piVar18 = piVar18 + -2;
            *piVar18 = *piVar18 + -1;
            if (*piVar18 == 0) {
              (*(code *)0x7ff63a101200)(0x146d2d8aad8,piVar13);
            }
          }
        }
      }
    }
  }
  if ((uStack_5c == (int *)0x0) || (uStack_5c == (int *)0xc)) {
    _DAT_146d4e68510 = 0xfa9;
  }
  else {
    uVar16 = uStack_5c[-1];
    if ((ulonglong)uVar16 != 0) {
      lVar12 = 0;
      uVar19 = uVar16;
      do {
        uVar20 = (ulonglong)
                 *(ushort *)((longlong)uStack_5c + lVar12 * 2 + (ulonglong)uVar16 * 2 + -2);
        if ((0x20 < uVar20) || ((0x100002600U >> (uVar20 & 0x3f) & 1) == 0)) {
          if ((int)lVar12 == 0) goto LAB_146d4e4265e;
          uVar17 = -(int)lVar12;
          break;
        }
        lVar12 = lVar12 + -1;
        uVar19 = uVar19 - 1;
        uVar17 = uVar16;
      } while (uVar19 != 0);
      uVar16 = uVar16 - uVar17;
      cVar9 = FUN_146d4e40100(&local_60,uVar16);
      if (cVar9 != '\0') {
        uStack_5c[-1] = uVar16;
        *(undefined2 *)((longlong)uStack_5c + (ulonglong)uVar16 * 2) = 0;
      }
    }
  }
LAB_146d4e4265e:
  if (uStack_5c == (int *)&DAT_146d4e5e908) {
LAB_146d4e426cf:
    FUN_146d4e407d0(&local_60,0x146d4e5e8f0,0,0x146d4e65a98);
    piVar18 = uStack_5c;
  }
  else {
    if (uStack_5c == (int *)0x0) goto LAB_146d4e4286d;
    uVar16 = uStack_5c[-1];
    uVar19 = _DAT_146d4e5e904;
    if (uVar16 < _DAT_146d4e5e904) {
      uVar19 = uVar16;
    }
    iVar10 = uVar16 - _DAT_146d4e5e904;
    if (uVar19 != 0) {
      uVar20 = 0;
      do {
        uVar3 = *(ushort *)((longlong)uStack_5c + uVar20 * 2);
        uVar4 = *(ushort *)(&DAT_146d4e5e908 + uVar20 * 2);
        uVar20 = uVar20 + 1;
        if (uVar19 <= uVar20) break;
      } while (uVar3 == uVar4);
      if (uVar3 != uVar4) {
        iVar10 = (uint)uVar3 - (uint)uVar4;
      }
    }
    piVar18 = uStack_5c;
    if (iVar10 == 0) goto LAB_146d4e426cf;
  }
  uStack_5c = piVar18;
  if (((piVar18 == (int *)0x0) || (piVar18 == (int *)0xc)) || (piVar18[-1] < 0x20))
  goto LAB_146d4e4286d;
  puVar15 = (uint *)(_DAT_146d4e68540 + -3);
  if (_DAT_146d4e68540 == (int *)0x0) {
    puVar15 = (uint *)0x0;
  }
  if ((_DAT_146d4e6853c == 0) || (puVar15 == (uint *)0x0)) {
LAB_146d4e4279b:
    piVar13 = (int *)(*(code *)0x7ff63a101190)(0x146d2d8aad8,0x1f);
    if (piVar13 != (int *)0x0) {
      _DAT_146d4e68540 = piVar13 + 3;
      piVar13[1] = 1;
      piVar13[2] = 0;
      *(undefined2 *)(piVar13 + 3) = 0;
      _DAT_146d4e6853c = *piVar13;
      goto LAB_146d4e427d4;
    }
    _DAT_146d4e68510 = 0x13aa;
  }
  else {
    if (*puVar15 < 0x1f) {
      if (*puVar15 != 0) goto LAB_146d4e42773;
LAB_146d4e4278e:
      _DAT_146d4e68540 = (int *)0x0;
      _DAT_146d4e6853c = 0;
      goto LAB_146d4e4279b;
    }
    if (puVar15[1] != 1) {
LAB_146d4e42773:
      puVar15 = puVar15 + 1;
      *puVar15 = *puVar15 - 1;
      if (*puVar15 == 0) {
        (*(code *)0x7ff63a101200)(0x146d2d8aad8);
      }
      goto LAB_146d4e4278e;
    }
LAB_146d4e427d4:
    piVar13 = _DAT_146d4e68540;
    *(undefined8 *)((longlong)_DAT_146d4e68540 + 0x36) = *(undefined8 *)((longlong)piVar18 + 0x36);
    *(undefined8 *)(piVar13 + 0xc) = *(undefined8 *)(piVar18 + 0xc);
    *(undefined8 *)(piVar13 + 10) = *(undefined8 *)(piVar18 + 10);
    *(undefined8 *)(piVar13 + 8) = *(undefined8 *)(piVar18 + 8);
    *(undefined8 *)(piVar13 + 6) = *(undefined8 *)(piVar18 + 6);
    *(undefined8 *)(piVar13 + 4) = *(undefined8 *)(piVar18 + 4);
    uVar5 = *(undefined8 *)piVar18;
    *(undefined8 *)(piVar13 + 2) = *(undefined8 *)(piVar18 + 2);
    *(undefined8 *)piVar13 = uVar5;
    piVar13[-1] = 0x1f;
    *(undefined2 *)((longlong)piVar13 + 0x3e) = 0;
  }
  FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65aa8);
  FUN_146d4e407d0(&local_60,&local_50,0,0x146d4e65ab8);
LAB_146d4e4286d:
  FUN_146d4e407d0(&local_40,&local_60,0,0x146d4e65ac8);
  FUN_146d4e400a0(&local_60);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_40,1,0x146d4e65ad8);
  FUN_146d4e400a0(&local_40);
  FUN_146d4e400a0(&local_50);
  return;
}



/* Address: 146d4e42960 */

void FUN_146d4e42960(void)

{
  int iVar1;
  
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e621c0,0xffffffff,0xffffffff);
  FUN_146d4e52f90();
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e62360,0xffffffff,0xffffffff);
  DAT_146d4e683cd = 0;
  DAT_146d4e683ce = 0;
  DAT_146d4e683cc = 0;
  FUN_146d4e407d0(&DAT_146d4e683d0,0x146d4e5e910,0,0x146d4e65738);
  FUN_146d4e407d0(&DAT_146d4e683e0,0x146d4e5e910,0,0x146d4e65748);
  FUN_146d4e407d0(&DAT_146d4e683f0,0x146d4e5e910,0,0x146d4e65758);
  FUN_146d4e407d0(&DAT_146d4e68400,0x146d4e5e910,0,0x146d4e65768);
  FUN_146d4e407d0(&DAT_146d4e68410,0x146d4e5e910,0,0x146d4e65778);
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e62390,0xffffffff,0xffffffff);
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e63da0,0xffffffff,0xffffffff);
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e63dd0,0xffffffff,0xffffffff);
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e61b00,0xffffffff,0xffffffff);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e61850);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e61850);
  }
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e61898);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e61898);
    return;
  }
  return;
}



/* Address: 146d4e42ba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e42ba0(void)

{
  longlong lVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  code *pcVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 unaff_RBP;
  int iVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  undefined8 in_stack_fffffffffffffe58;
  undefined4 local_180;
  longlong local_17c;
  undefined4 local_170;
  longlong local_16c;
  undefined4 local_160;
  longlong local_15c;
  undefined4 local_150;
  longlong local_14c;
  undefined4 local_140;
  undefined8 local_13c;
  undefined4 local_130;
  undefined8 local_12c;
  undefined4 local_120;
  undefined1 *local_11c;
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
  uint local_c4;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined8 local_ac;
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
  
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  local_50 = 0;
  local_60 = 0;
  local_70 = 0;
  local_80 = 0;
  local_90 = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_170 = 0;
  local_150 = 0;
  local_f0 = 0;
  local_100 = 0;
  local_110 = 0;
  local_e0 = 0;
  local_120 = 0;
  local_4c = 0;
  local_5c = 0;
  local_6c = 0;
  local_7c = 0;
  local_8c = 0;
  local_9c = 0;
  local_ac = 0;
  local_16c = 0;
  local_14c = 0;
  local_ec = 0;
  local_fc = 0;
  local_10c = 0;
  local_dc = 0;
  local_11c = (undefined1 *)0x0;
  local_b8 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e68528,0x1e);
  if ((DAT_146d4e68678 == '\0') || (cVar6 = FUN_146d4e50b50(), cVar6 != '\0')) {
    uVar15 = CONCAT71((int7)((ulonglong)unaff_RBP >> 8),1);
  }
  else {
    uVar15 = 0;
  }
  local_d0 = 0;
  local_180 = 0;
  local_cc = 0;
  local_17c = 0;
  if (DAT_146d4e68000 == '\0') {
    uVar12 = 0x146d4e632e8;
    uVar20 = 0x146d4e65c38;
  }
  else {
    uVar12 = 0x146d4e63328;
    uVar20 = 0x146d4e65c48;
  }
  FUN_146d4e407d0(&local_180,uVar12,0,uVar20);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_180,1,0x146d4e65c58);
  FUN_146d4e400a0(&local_180);
  FUN_146d4e407d0(&local_150,&DAT_146d4e6853c,1,0x146d4e66028);
  FUN_146d4e407d0(&local_170,0x146d4e63618,0);
  lVar10 = local_14c;
  if (local_14c != 0) {
    uVar4 = *(uint *)(local_14c + -4);
    uVar22 = (ulonglong)uVar4;
    if ((uVar22 == 0) && (local_16c != 0)) goto LAB_146d4e42f2d;
    if (local_16c == 0) {
      uVar13 = 0;
      uVar16 = uVar4;
    }
    else {
      uVar13 = (ulonglong)*(uint *)(local_16c + -4);
      uVar16 = uVar4 + *(uint *)(local_16c + -4);
    }
    cVar6 = FUN_146d4e40100(&local_170);
    if (cVar6 != '\0') {
      if (uVar22 != 0) {
        lVar1 = local_16c + uVar13 * 2;
        if (uVar4 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar21 = 0;
          uVar13 = (ulonglong)(uVar4 & 0xfffffff8);
          do {
            uVar12 = ((undefined8 *)(lVar10 + uVar21))[1];
            *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar10 + uVar21);
            ((undefined8 *)(lVar1 + uVar21))[1] = uVar12;
            uVar21 = uVar21 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
          if (uVar13 == uVar22) goto LAB_146d4e42f22;
        }
        do {
          *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar22 != uVar13);
      }
LAB_146d4e42f22:
      *(uint *)(local_16c + -4) = uVar16;
      *(undefined2 *)(local_16c + (ulonglong)uVar16 * 2) = 0;
      goto LAB_146d4e42f2d;
    }
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x441120000001f9);
LAB_146d4e44b09:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x361121000001f9);
LAB_146d4e44b29:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x361122000001f9);
LAB_146d4e44b49:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3d1123000001f9);
LAB_146d4e44b69:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3f112a000001f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x5c0b52000001f9);
LAB_146d4e44ba9:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1a1114000001f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x240b52000001f9);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
LAB_146d4e42f2d:
  FUN_146d4e407d0(&local_d0,&local_170,0,0x146d4e66048);
  uVar4 = _DAT_146d4e68638;
  local_f0 = 0;
  local_180 = 0;
  local_160 = 0;
  local_130 = 0;
  local_140 = 0;
  local_ec = 0;
  local_17c = 0;
  local_15c = 0;
  local_12c = 0;
  local_13c = 0;
  if ((ulonglong)_DAT_146d4e68638 < 0xb) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e42fd1 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)_DAT_146d4e68638 * 8 + 0x146d4e5e258))();
    return;
  }
  FUN_146d4e407d0(&local_140,0x146d4e617d0,0,0x146d4e654d8);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_140,1,0x146d4e654e8);
  FUN_146d4e400a0(&local_140);
  FUN_146d4e400a0(&local_130);
  FUN_146d4e400a0(&local_160);
  FUN_146d4e400a0(&local_180);
  FUN_146d4e407d0(&local_150,&DAT_146d4e6853c,1,0x146d4e66058);
  FUN_146d4e407d0(&local_170,0x146d4e63658,0);
  lVar10 = local_14c;
  if (local_14c != 0) {
    uVar16 = *(uint *)(local_14c + -4);
    uVar22 = (ulonglong)uVar16;
    if ((uVar22 != 0) || (local_16c == 0)) {
      uVar15 = uVar15 & 0xffffffff;
      if (local_16c == 0) {
        uVar18 = 0;
        uVar17 = uVar16;
      }
      else {
        uVar18 = *(uint *)(local_16c + -4);
        uVar17 = uVar16 + uVar18;
      }
      cVar6 = FUN_146d4e40100(&local_170);
      if (cVar6 == '\0') goto LAB_146d4e44b09;
      if (uVar22 != 0) {
        lVar1 = local_16c + (ulonglong)uVar18 * 2;
        if (uVar16 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar21 = 0;
          uVar13 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar12 = ((undefined8 *)(lVar10 + uVar21))[1];
            *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar10 + uVar21);
            ((undefined8 *)(lVar1 + uVar21))[1] = uVar12;
            uVar21 = uVar21 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
          if (uVar13 == uVar22) goto LAB_146d4e43382;
        }
        do {
          *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar22 != uVar13);
      }
LAB_146d4e43382:
      *(uint *)(local_16c + -4) = uVar17;
      *(undefined2 *)(local_16c + (ulonglong)uVar17 * 2) = 0;
    }
  }
  FUN_146d4e407d0(&local_f0,&local_170,0,0x146d4e66078);
  local_100 = 0;
  local_180 = 0;
  local_160 = 0;
  local_fc = 0;
  local_17c = 0;
  local_15c = 0;
  if (uVar4 == 1) {
    uVar11 = 0x146;
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd8,2,0x590008,0x146d4e61808,0x580007,_DAT_146d4e68648)
    ;
    uVar20 = 0x146d4e65508;
    uVar12 = 0x146d4e654f8;
  }
  else {
    uVar12 = FUN_146d4e57de0();
    uVar12 = FUN_146d4e59600(0x146d4e68528,uVar12);
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,uVar12,2);
    uVar20 = 0x146d4e65528;
    uVar12 = 0x146d4e65518;
  }
  FUN_146d4e407d0(&local_180,&DAT_146d4e6853c,1,uVar12);
  FUN_146d4e407d0(&local_160,&local_180,0,uVar20);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_160,1,0x146d4e65538);
  FUN_146d4e400a0(&local_160);
  FUN_146d4e400a0(&local_180);
  FUN_146d4e407d0(&local_150,&DAT_146d4e6853c,1,0x146d4e66088);
  FUN_146d4e407d0(&local_170,0x146d4e63698,0);
  lVar10 = local_14c;
  if (local_14c != 0) {
    uVar16 = *(uint *)(local_14c + -4);
    uVar22 = (ulonglong)uVar16;
    if ((uVar22 != 0) || (local_16c == 0)) {
      uVar15 = uVar15 & 0xffffffff;
      if (local_16c == 0) {
        uVar13 = 0;
        uVar18 = uVar16;
      }
      else {
        uVar13 = (ulonglong)*(uint *)(local_16c + -4);
        uVar18 = uVar16 + *(uint *)(local_16c + -4);
      }
      cVar6 = FUN_146d4e40100(&local_170);
      if (cVar6 == '\0') goto LAB_146d4e44b29;
      if (uVar22 != 0) {
        lVar1 = local_16c + uVar13 * 2;
        if (uVar16 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar21 = 0;
          uVar13 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar12 = ((undefined8 *)(lVar10 + uVar21))[1];
            *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar10 + uVar21);
            ((undefined8 *)(lVar1 + uVar21))[1] = uVar12;
            uVar21 = uVar21 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
          if (uVar13 == uVar22) goto LAB_146d4e43632;
        }
        do {
          *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar22 != uVar13);
      }
LAB_146d4e43632:
      *(uint *)(local_16c + -4) = uVar18;
      *(undefined2 *)(local_16c + (ulonglong)uVar18 * 2) = 0;
    }
  }
  FUN_146d4e407d0(&local_100,&local_170,0,0x146d4e660a8);
  local_110 = 0;
  local_180 = 0;
  local_160 = 0;
  local_130 = 0;
  local_10c = 0;
  local_17c = 0;
  local_15c = 0;
  local_12c = 0;
  if ((uVar4 < 2) || (DAT_146d4e68668 == '\0')) {
    puVar14 = (undefined4 *)0x146d4e62718;
    uVar12 = 0x146d4e65858;
  }
  else if (DAT_146d4e683b0 == '\0') {
    if (_DAT_146d4e683a8 <= 0.0) {
      puVar14 = (undefined4 *)0x146d4e627e8;
      uVar12 = 0x146d4e658a8;
    }
    else {
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,_DAT_146d4e683a8,2);
      FUN_146d4e407d0(&local_160,&DAT_146d4e6853c,1,0x146d4e65878);
      FUN_146d4e407d0(&local_180,0x146d4e627b8,0);
      lVar10 = local_15c;
      if (local_15c != 0) {
        uVar4 = *(uint *)(local_15c + -4);
        uVar22 = (ulonglong)uVar4;
        if ((uVar22 != 0) || (local_17c == 0)) {
          if (local_17c == 0) {
            uVar13 = 0;
          }
          else {
            uVar13 = (ulonglong)*(uint *)(local_17c + -4);
          }
          uVar16 = uVar4 + (int)uVar13;
          cVar6 = FUN_146d4e40100(&local_180);
          if (cVar6 == '\0') goto LAB_146d4e44ba9;
          if (uVar22 != 0) {
            lVar1 = local_17c + uVar13 * 2;
            if (uVar4 < 0x10) {
              uVar13 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
              uVar13 = 0;
            }
            else {
              uVar21 = 0;
              uVar13 = (ulonglong)(uVar4 & 0xfffffff8);
              do {
                uVar12 = ((undefined8 *)(lVar10 + uVar21))[1];
                *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar10 + uVar21);
                ((undefined8 *)(lVar1 + uVar21))[1] = uVar12;
                uVar21 = uVar21 + 0x10;
              } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
              if (uVar13 == uVar22) goto LAB_146d4e44922;
            }
            do {
              *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
              uVar13 = uVar13 + 1;
            } while (uVar22 != uVar13);
          }
LAB_146d4e44922:
          *(uint *)(local_17c + -4) = uVar16;
          *(undefined2 *)(local_17c + (ulonglong)uVar16 * 2) = 0;
        }
      }
      uVar12 = 0x146d4e65898;
      puVar14 = &local_180;
    }
  }
  else {
    puVar14 = (undefined4 *)0x146d4e62778;
    uVar12 = 0x146d4e65868;
  }
  FUN_146d4e407d0(&local_130,puVar14,0,uVar12);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_130,1,0x146d4e658b8);
  FUN_146d4e400a0(&local_130);
  FUN_146d4e400a0(&local_160);
  FUN_146d4e400a0(&local_180);
  FUN_146d4e407d0(&local_150,&DAT_146d4e6853c,1,0x146d4e660b8);
  FUN_146d4e407d0(&local_170,0x146d4e636e0,0);
  lVar10 = local_14c;
  if (local_14c != 0) {
    uVar4 = *(uint *)(local_14c + -4);
    uVar22 = (ulonglong)uVar4;
    if ((uVar22 != 0) || (local_16c == 0)) {
      if (local_16c == 0) {
        uVar16 = 0;
        uVar18 = uVar4;
      }
      else {
        uVar16 = *(uint *)(local_16c + -4);
        uVar18 = uVar4 + uVar16;
      }
      cVar6 = FUN_146d4e40100(&local_170);
      if (cVar6 == '\0') goto LAB_146d4e44b49;
      if (uVar22 != 0) {
        lVar1 = local_16c + (ulonglong)uVar16 * 2;
        if (uVar4 < 0x10) {
          uVar13 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
          uVar13 = 0;
        }
        else {
          uVar21 = 0;
          uVar13 = (ulonglong)(uVar4 & 0xfffffff8);
          do {
            uVar12 = ((undefined8 *)(lVar10 + uVar21))[1];
            *(undefined8 *)(lVar1 + uVar21) = *(undefined8 *)(lVar10 + uVar21);
            ((undefined8 *)(lVar1 + uVar21))[1] = uVar12;
            uVar21 = uVar21 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
          if (uVar13 == uVar22) goto LAB_146d4e43952;
        }
        do {
          *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar10 + uVar13 * 2);
          uVar13 = uVar13 + 1;
        } while (uVar22 != uVar13);
      }
LAB_146d4e43952:
      *(uint *)(local_16c + -4) = uVar18;
      *(undefined2 *)(local_16c + (ulonglong)uVar18 * 2) = 0;
    }
  }
  uVar22 = 0;
  FUN_146d4e407d0(&local_110,&local_170,0,0x146d4e660d8);
  lVar10 = (*(code *)0x7ff63a101ce0)(0x146d2d8aad8,0);
  if (lVar10 == 0) {
    lVar10 = (*(code *)0x7ff63a101c40)(0x146d2d8aad8,0);
  }
  local_e0 = 0;
  local_dc = 0;
  FUN_146d4e50320(lVar10);
  puVar14 = &local_150;
  FUN_146d4e407d0(puVar14,&DAT_146d4e6853c,1,0x146d4e660e8);
  FUN_146d4e407d0(&local_e0,puVar14,0,0x146d4e660f8);
  cVar6 = DAT_146d4e686f0;
  if ((local_dc != 0) && (local_dc != 0xc)) {
    uVar22 = (ulonglong)*(uint *)(local_dc + -4);
  }
  local_120 = 0;
  local_11c = (undefined1 *)0x0;
  local_c0 = uVar22;
  if (DAT_146d4e686f0 == '\0') {
    puVar14 = (undefined4 *)0x146d4e5e910;
    iVar19 = 0xd4;
  }
  else {
    FUN_146d4e407d0(puVar14,0x146d4e63720,0);
    if ((int)uVar22 < 1) {
      lVar10 = 0x146d4e6373c;
    }
    else {
      iVar19 = 0xe6;
      lVar10 = local_dc;
      if (local_dc == 0) goto LAB_146d4e43bd6;
    }
    iVar19 = 0xe6;
    uVar4 = *(uint *)(lVar10 + -4);
    uVar22 = (ulonglong)uVar4;
    if ((uVar22 != 0) || (local_14c == 0)) {
      local_c4 = (uint)uVar15;
      if (local_14c == 0) {
        uVar16 = 0;
        uVar18 = uVar4;
      }
      else {
        uVar16 = *(uint *)(local_14c + -4);
        uVar18 = uVar4 + uVar16;
      }
      puVar14 = &local_150;
      cVar7 = FUN_146d4e40100(puVar14);
      if (cVar7 == '\0') goto LAB_146d4e44b69;
      if (uVar22 != 0) {
        lVar1 = local_14c + (ulonglong)uVar16 * 2;
        if (uVar4 < 0x10) {
          uVar15 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
          uVar15 = 0;
        }
        else {
          uVar13 = 0;
          uVar15 = (ulonglong)(uVar4 & 0xfffffff8);
          do {
            uVar12 = ((undefined8 *)(lVar10 + uVar13))[1];
            *(undefined8 *)(lVar1 + uVar13) = *(undefined8 *)(lVar10 + uVar13);
            ((undefined8 *)(lVar1 + uVar13))[1] = uVar12;
            uVar13 = uVar13 + 0x10;
          } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar13);
          if (uVar15 == uVar22) goto LAB_146d4e43bc2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar10 + uVar15 * 2);
          uVar15 = uVar15 + 1;
        } while (uVar22 != uVar15);
      }
LAB_146d4e43bc2:
      uVar15 = (ulonglong)local_c4;
      *(uint *)(local_14c + -4) = uVar18;
      *(undefined2 *)(local_14c + (ulonglong)uVar18 * 2) = 0;
    }
  }
LAB_146d4e43bd6:
  iVar8 = (int)local_b8;
  FUN_146d4e407d0(&local_120,puVar14,0,0x146d4e66118);
  if (DAT_146d4e683cc == '\0') {
    uVar12 = CONCAT44(uVar11,0xffffffff);
    (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e62360,0xffffffff,uVar12);
    uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
    DAT_146d4e683cc = 0;
    DAT_146d4e683cd = 0;
    DAT_146d4e683ce = '\0';
    FUN_146d4e407d0(&DAT_146d4e683d0,0x146d4e5e910,0,0x146d4e65738);
    FUN_146d4e407d0(&DAT_146d4e683e0,0x146d4e5e910,0,0x146d4e65748);
    FUN_146d4e407d0(&DAT_146d4e683f0,0x146d4e5e910,0,0x146d4e65758);
    FUN_146d4e407d0(&DAT_146d4e68400,0x146d4e5e910,0,0x146d4e65768);
    FUN_146d4e407d0(&DAT_146d4e68410,0x146d4e5e910,0,0x146d4e65778);
    DAT_146d4e683cc = '\x01';
    uVar12 = CONCAT44(uVar11,0xc);
    FUN_146d4e5d870(0x146d4e63790,0x146d4e63800,0x12,0x30,uVar12,0xd7ff);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63840,0x146d4e638a8,0x12,0x44,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e638f0,0x146d4e63958,0x12,0x56,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e639a0,0x146d4e639f0,0x12,0x68,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63a30,0x146d4e63a88,0x12,0x7a,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63ad0,&local_d0,0x12,0x8c,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63b10,&local_f0,0x12,0x9e,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63b50,&local_100,0x12,0xb0,uVar12,0xff901e);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63b90,&local_110,0x12,0xc2,uVar12,0xff901e);
    uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
    if (cVar6 != '\0') {
      uVar12 = CONCAT44(uVar11,8);
      uVar11 = 0xd7ff;
      if (0 < (int)local_c0) {
        uVar11 = 0x4763ff;
      }
      FUN_146d4e5d870(0x146d4e63bd0,&local_120,0x12,0xd4,uVar12,uVar11);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
    }
    FUN_146d4e407d0(&DAT_146d4e683d0,&local_d0,0,0x146d4e66128);
    FUN_146d4e407d0(&DAT_146d4e683e0,&local_f0,0,0x146d4e66138);
    FUN_146d4e407d0(&DAT_146d4e683f0,&local_100,0,0x146d4e66148);
    FUN_146d4e407d0(&DAT_146d4e68400,&local_110,0,0x146d4e66158);
    uVar12 = 0x146d4e66168;
    puVar14 = &local_120;
LAB_146d4e44412:
    FUN_146d4e407d0(&DAT_146d4e68410,puVar14,0,uVar12);
  }
  else {
    if (local_cc != _DAT_146d4e683d4) {
      if ((local_cc != 0) && (_DAT_146d4e683d4 != 0)) {
        uVar4 = *(uint *)(local_cc + -4);
        uVar16 = *(uint *)(_DAT_146d4e683d4 + -4);
        uVar18 = uVar16;
        if (uVar4 < uVar16) {
          uVar18 = uVar4;
        }
        iVar9 = uVar4 - uVar16;
        if (uVar18 != 0) {
          uVar22 = 1;
          do {
            uVar2 = *(ushort *)(local_cc + -2 + uVar22 * 2);
            uVar3 = *(ushort *)(_DAT_146d4e683d4 + -2 + uVar22 * 2);
            if (uVar18 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar9 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar9 == 0) goto LAB_146d4e43ceb;
      }
      uVar12 = CONCAT44(uVar11,8);
      FUN_146d4e5d870(0x146d4e63ad0,&local_d0,0x12,0x8c,uVar12,0xff901e);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
      FUN_146d4e407d0(&DAT_146d4e683d0,&local_d0,0,0x146d4e66178);
    }
LAB_146d4e43ceb:
    if (local_ec != _DAT_146d4e683e4) {
      if ((local_ec != 0) && (_DAT_146d4e683e4 != 0)) {
        uVar4 = *(uint *)(local_ec + -4);
        uVar16 = *(uint *)(_DAT_146d4e683e4 + -4);
        uVar18 = uVar16;
        if (uVar4 < uVar16) {
          uVar18 = uVar4;
        }
        iVar9 = uVar4 - uVar16;
        if (uVar18 != 0) {
          uVar22 = 1;
          do {
            uVar2 = *(ushort *)(local_ec + -2 + uVar22 * 2);
            uVar3 = *(ushort *)(_DAT_146d4e683e4 + -2 + uVar22 * 2);
            if (uVar18 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar9 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar9 == 0) goto LAB_146d4e43dcb;
      }
      uVar12 = CONCAT44(uVar11,8);
      FUN_146d4e5d870(0x146d4e63b10,&local_f0,0x12,0x9e,uVar12,0xff901e);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
      FUN_146d4e407d0(&DAT_146d4e683e0,&local_f0,0,0x146d4e66188);
    }
LAB_146d4e43dcb:
    if (local_fc != _DAT_146d4e683f4) {
      if ((local_fc != 0) && (_DAT_146d4e683f4 != 0)) {
        uVar4 = *(uint *)(local_fc + -4);
        uVar16 = *(uint *)(_DAT_146d4e683f4 + -4);
        uVar18 = uVar16;
        if (uVar4 < uVar16) {
          uVar18 = uVar4;
        }
        iVar9 = uVar4 - uVar16;
        if (uVar18 != 0) {
          uVar22 = 1;
          do {
            uVar2 = *(ushort *)(local_fc + -2 + uVar22 * 2);
            uVar3 = *(ushort *)(_DAT_146d4e683f4 + -2 + uVar22 * 2);
            if (uVar18 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar9 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar9 == 0) goto LAB_146d4e43eab;
      }
      uVar12 = CONCAT44(uVar11,8);
      FUN_146d4e5d870(0x146d4e63b50,&local_100,0x12,0xb0,uVar12,0xff901e);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
      FUN_146d4e407d0(&DAT_146d4e683f0,&local_100,0,0x146d4e66198);
    }
LAB_146d4e43eab:
    if (local_10c != _DAT_146d4e68404) {
      if ((local_10c != 0) && (_DAT_146d4e68404 != 0)) {
        uVar4 = *(uint *)(local_10c + -4);
        uVar16 = *(uint *)(_DAT_146d4e68404 + -4);
        uVar18 = uVar16;
        if (uVar4 < uVar16) {
          uVar18 = uVar4;
        }
        iVar9 = uVar4 - uVar16;
        if (uVar18 != 0) {
          uVar22 = 1;
          do {
            uVar2 = *(ushort *)(local_10c + -2 + uVar22 * 2);
            uVar3 = *(ushort *)(_DAT_146d4e68404 + -2 + uVar22 * 2);
            if (uVar18 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar9 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar9 == 0) goto LAB_146d4e43f8b;
      }
      uVar12 = CONCAT44(uVar11,8);
      FUN_146d4e5d870(0x146d4e63b90,&local_110,0x12,0xc2,uVar12,0xff901e);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
      FUN_146d4e407d0(&DAT_146d4e68400,&local_110,0,0x146d4e661a8);
    }
LAB_146d4e43f8b:
    if (cVar6 == '\0') {
      if (_DAT_146d4e68414 != &DAT_146d4e5e908) {
        if (_DAT_146d4e68414 != (undefined1 *)0x0) {
          uVar4 = *(uint *)(_DAT_146d4e68414 + -4);
          uVar16 = _DAT_146d4e5e904;
          if (uVar4 < _DAT_146d4e5e904) {
            uVar16 = uVar4;
          }
          iVar9 = uVar4 - _DAT_146d4e5e904;
          if (uVar16 != 0) {
            uVar22 = 0;
            do {
              uVar2 = *(ushort *)(_DAT_146d4e68414 + uVar22 * 2);
              uVar3 = *(ushort *)(&DAT_146d4e5e908 + uVar22 * 2);
              uVar22 = uVar22 + 1;
              if (uVar16 <= uVar22) break;
            } while (uVar2 == uVar3);
            if (uVar2 != uVar3) {
              iVar9 = (uint)uVar2 - (uint)uVar3;
            }
          }
          if (iVar9 == 0) goto LAB_146d4e44418;
        }
        iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e63bd0);
        if (-1 < iVar9) {
          (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e63bd0);
        }
        puVar14 = (undefined4 *)0x146d4e5e910;
        uVar12 = 0x146d4e661c8;
        goto LAB_146d4e44412;
      }
    }
    else if (local_11c != _DAT_146d4e68414) {
      if ((local_11c != (undefined1 *)0x0) && (_DAT_146d4e68414 != (undefined1 *)0x0)) {
        uVar4 = *(uint *)(local_11c + -4);
        uVar16 = *(uint *)(_DAT_146d4e68414 + -4);
        uVar18 = uVar16;
        if (uVar4 < uVar16) {
          uVar18 = uVar4;
        }
        iVar9 = uVar4 - uVar16;
        if (uVar18 != 0) {
          uVar22 = 1;
          do {
            uVar2 = *(ushort *)(local_11c + uVar22 * 2 + -2);
            uVar3 = *(ushort *)(_DAT_146d4e68414 + uVar22 * 2 + -2);
            if (uVar18 <= uVar22) break;
            uVar22 = uVar22 + 1;
          } while (uVar2 == uVar3);
          if (uVar2 != uVar3) {
            iVar9 = (uint)uVar2 - (uint)uVar3;
          }
        }
        if (iVar9 == 0) goto LAB_146d4e44418;
      }
      puVar14 = &local_120;
      uVar12 = CONCAT44(uVar11,8);
      uVar11 = 0xd7ff;
      if (0 < (int)local_c0) {
        uVar11 = 0x4763ff;
      }
      FUN_146d4e5d870(0x146d4e63bd0,puVar14,0x12,0xd4,uVar12,uVar11);
      uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
      uVar12 = 0x146d4e661b8;
      goto LAB_146d4e44412;
    }
  }
LAB_146d4e44418:
  if (iVar8 == 3) {
    uVar12 = CONCAT44(uVar11,0xc);
    FUN_146d4e5d870(0x146d4e63c10,0x146d4e63c40,0x18,iVar19 + -2,uVar12,0x4763ff);
    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),8);
    FUN_146d4e5d870(0x146d4e63c80,0x146d4e60688,0x18,iVar19 + 0x10,uVar12,0xd7ff);
    uVar11 = (undefined4)((ulonglong)uVar12 >> 0x20);
    iVar19 = iVar19 + 0x24;
    DAT_146d4e683ce = '\x01';
  }
  else if (DAT_146d4e683ce == '\x01') {
    iVar8 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e63c10);
    if (-1 < iVar8) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e63c10);
    }
    iVar8 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e63c80);
    if (-1 < iVar8) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e63c80);
    }
    DAT_146d4e683ce = '\0';
  }
  if ((byte)uVar15 == 0) {
    FUN_146d4e5d870(0x146d4e63cc0,0x146d4e63c40,0x18,iVar19 + -2,CONCAT44(uVar11,0xc),0x4763ff);
    FUN_146d4e5d870(0x146d4e63d00,0x146d4e63d70,0x18,iVar19 + 0x10,9,0xd7ff);
  }
  else {
    if (DAT_146d4e683cd != 1) goto LAB_146d4e44644;
    iVar19 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e63cc0);
    if (-1 < iVar19) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e63cc0);
    }
    iVar19 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e63d00);
    if (-1 < iVar19) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e63d00);
    }
  }
  DAT_146d4e683cd = (byte)uVar15 ^ 1;
LAB_146d4e44644:
  FUN_146d4e400a0(&local_120);
  FUN_146d4e400a0(&local_e0);
  FUN_146d4e400a0(&local_110);
  FUN_146d4e400a0(&local_100);
  FUN_146d4e400a0(&local_f0);
  FUN_146d4e400a0(&local_d0);
  FUN_146d4e400a0(&local_150);
  FUN_146d4e400a0(&local_170);
  FUN_146d4e400a0(&local_b0);
  FUN_146d4e400a0(&local_a0);
  FUN_146d4e400a0(&local_90);
  FUN_146d4e400a0(&local_80);
  FUN_146d4e400a0(&local_70);
  FUN_146d4e400a0(&local_60);
  FUN_146d4e400a0(&local_50);
  return;
}



/* Address: 146d4e48e50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e48e50(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  undefined4 uVar12;
  longlong lVar13;
  longlong lVar14;
  uint uVar15;
  int iVar16;
  ulonglong uVar17;
  int iVar18;
  bool bVar19;
  int local_bc;
  undefined4 local_b8;
  undefined1 *local_b4;
  undefined4 local_a8;
  undefined1 *local_a4;
  int local_9c;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined8 local_84;
  
  local_98 = 0;
  local_b8 = 0;
  local_94 = 0;
  local_b4 = (undefined1 *)0x0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x146d2d8aad8);
  if (-1 < iVar8 + -1) {
    bVar19 = false;
    iVar8 = iVar8 + -1;
LAB_146d4e48f2d:
    lVar11 = (*(code *)0x7ff63a107df0)(0x146d2d8aad8,iVar8);
    if ((lVar11 == 0) || (cVar7 = (*(code *)0x7ff63a107ee0)(0x146d2d8aad8,lVar11), cVar7 == '\0'))
    goto LAB_146d4e48f20;
    lVar11 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,0xc);
    lVar13 = 0;
    if (DAT_146d4e68059 != '\0') {
      lVar13 = 0xa0a3;
    }
    if (lVar11 != lVar13) goto LAB_146d4e48f20;
    local_b8 = 0;
    local_b4 = (undefined1 *)0x0;
    (*(code *)0x7ff63a108010)(0x146d2d8aad8,0);
    FUN_146d4e407d0(&local_98,&DAT_146d4e6853c,1,0x146d4e65d08);
    FUN_146d4e407d0(&local_b8,&local_98,0);
    if (local_b4 == &DAT_146d4e5e908) goto LAB_146d4e48eff;
    if (local_b4 != (undefined1 *)0x0) {
      uVar10 = *(uint *)(local_b4 + -4);
      uVar15 = _DAT_146d4e5e904;
      if (uVar10 < _DAT_146d4e5e904) {
        uVar15 = uVar10;
      }
      iVar9 = uVar10 - _DAT_146d4e5e904;
      if (uVar15 != 0) {
        uVar17 = 0;
        do {
          uVar1 = *(ushort *)(local_b4 + uVar17 * 2);
          uVar2 = *(ushort *)(&DAT_146d4e5e908 + uVar17 * 2);
          uVar17 = uVar17 + 1;
          if (uVar15 <= uVar17) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar9 == 0) goto LAB_146d4e48eff;
    }
    uVar17 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,&local_b8,0x32);
    uVar12 = 0;
    if (((uVar17 & 1) != 0) || (uVar12 = 1, (uVar17 & 2) != 0)) {
      _DAT_146d4e68385 = uVar12;
    }
    if (_DAT_146d4e68514 == 0) {
      _DAT_146d4e68110 = 0;
      _DAT_146d4e68100 = 0;
      _DAT_146d4e68104 = 0;
      uRam00000146d4e68108 = 0;
      _DAT_146d4e6810c = 0;
      FUN_146d4e400a0(&DAT_146d4e68114);
      _DAT_146d4e68130 = 0;
      _DAT_146d4e68138 = 0;
      _DAT_146d4e68140 = 0;
      _DAT_146d4e68148 = 0;
      _DAT_146d4e68150 = 0;
      _DAT_146d4e68158 = 0;
      _DAT_146d4e68160 = 0;
      _DAT_146d4e68120 = 0.0;
      _DAT_146d4e68128 = 0.0;
      FUN_146d4e400a0(&DAT_146d4e68164);
      _DAT_146d4e68200 = 0;
      uRam00000146d4e68208 = 0;
      _DAT_146d4e681f0 = 0;
      uRam00000146d4e681f8 = 0;
      _DAT_146d4e68210 = 0;
      uRam00000146d4e68218 = 0;
      _DAT_146d4e681e0 = 0;
      uRam00000146d4e681e8 = 0;
      _DAT_146d4e681d0 = 0;
      uRam00000146d4e681d8 = 0;
      _DAT_146d4e681c0 = 0;
      uRam00000146d4e681c8 = 0;
      _DAT_146d4e681b0 = 0;
      uRam00000146d4e681b8 = 0;
      _DAT_146d4e681a0 = 0;
      uRam00000146d4e681a8 = 0;
      _DAT_146d4e68190 = 0;
      uRam00000146d4e68198 = 0;
      _DAT_146d4e68180 = 0;
      uRam00000146d4e68188 = 0;
      _DAT_146d4e68170 = 0;
      uRam00000146d4e68178 = 0;
      _DAT_146d4e68220 = 0;
      FUN_146d4e400a0(&DAT_146d4e68224);
      _DAT_146d4e682c0 = 0;
      uRam00000146d4e682c8 = 0;
      _DAT_146d4e682b0 = 0;
      uRam00000146d4e682b8 = 0;
      _DAT_146d4e682d0 = 0;
      uRam00000146d4e682d8 = 0;
      _DAT_146d4e682a0 = 0;
      uRam00000146d4e682a8 = 0;
      _DAT_146d4e68290 = 0;
      uRam00000146d4e68298 = 0;
      _DAT_146d4e68280 = 0;
      uRam00000146d4e68288 = 0;
      _DAT_146d4e68270 = 0;
      uRam00000146d4e68278 = 0;
      _DAT_146d4e68260 = 0;
      uRam00000146d4e68268 = 0;
      _DAT_146d4e68250 = 0;
      uRam00000146d4e68258 = 0;
      _DAT_146d4e68240 = 0;
      uRam00000146d4e68248 = 0;
      _DAT_146d4e68230 = 0;
      uRam00000146d4e68238 = 0;
      _DAT_146d4e682e0 = 0;
      FUN_146d4e400a0(&DAT_146d4e682e8);
      _DAT_146d4e68364 = 0;
      _DAT_146d4e6835c = 0;
      _DAT_146d4e6836c = 0;
      _DAT_146d4e68354 = 0;
      _DAT_146d4e6834c = 0;
      _DAT_146d4e68344 = 0;
      _DAT_146d4e6833c = 0;
      _DAT_146d4e68334 = 0;
      _DAT_146d4e6832c = 0;
      _DAT_146d4e68324 = 0;
      _DAT_146d4e6831c = 0;
      _DAT_146d4e68314 = 0;
      _DAT_146d4e6830c = 0;
      _DAT_146d4e68304 = 0;
      _DAT_146d4e682fc = 0;
      _DAT_146d4e682f4 = 0;
      cVar7 = FUN_146d4e4ca90(&local_b8);
      if (cVar7 != '\0') {
        local_bc = 0x2716;
        local_9c = 10;
LAB_146d4e493b9:
        local_88 = 0;
        local_a8 = 0;
        local_84 = 0;
        local_a4 = (undefined1 *)0x0;
        if (_DAT_146d4e68389 == 2) {
          iVar9 = (*(code *)0x7ff63a107da0)(0x146d2d8aad8);
          if (iVar9 != 0) {
            iVar18 = 0;
            do {
              local_a8 = 0;
              local_a4 = (undefined1 *)0x0;
              (*(code *)0x7ff63a107e40)(0x146d2d8aad8,iVar18);
              FUN_146d4e407d0(&local_88,&DAT_146d4e6853c,1,0x146d4e64d68);
              FUN_146d4e407d0(&local_a8,&local_88,0,0x146d4e64d78);
              lVar11 = _DAT_146d4e68375;
              if (local_a4 == local_b4) {
LAB_146d4e49410:
                lVar13 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,0xc);
                if (lVar11 == lVar13) goto LAB_146d4e49565;
              }
              else if ((local_a4 != (undefined1 *)0x0) && (local_b4 != (undefined1 *)0x0)) {
                uVar10 = *(uint *)(local_a4 + -4);
                uVar15 = *(uint *)(local_b4 + -4);
                uVar4 = uVar15;
                if (uVar10 < uVar15) {
                  uVar4 = uVar10;
                }
                iVar16 = uVar10 - uVar15;
                if (uVar4 != 0) {
                  uVar17 = 1;
                  do {
                    uVar1 = *(ushort *)(local_a4 + uVar17 * 2 + -2);
                    uVar2 = *(ushort *)(local_b4 + uVar17 * 2 + -2);
                    if (uVar4 <= uVar17) break;
                    uVar17 = uVar17 + 1;
                  } while (uVar1 == uVar2);
                  if (uVar1 != uVar2) {
                    iVar16 = (uint)uVar1 - (uint)uVar2;
                  }
                }
                if (iVar16 == 0) goto LAB_146d4e49410;
              }
              FUN_146d4e400a0(&local_a8);
              iVar18 = iVar18 + 1;
              if (iVar18 == iVar9) break;
            } while( true );
          }
          FUN_146d4e400a0(&local_88);
        }
        else {
          cVar7 = (*(code *)0x7ff63a107f20)(0x146d2d8aad8,&local_b8);
          FUN_146d4e400a0(&local_88);
          if (cVar7 != '\0') goto LAB_146d4e49576;
        }
        goto LAB_146d4e497aa;
      }
    }
    else {
      (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd,2,0x590008,0x146d4e60610,0x590008,0x146d4e5f348);
      local_bc = 0x272b;
LAB_146d4e497aa:
      _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,local_bc);
    }
LAB_146d4e497b6:
    FUN_146d4e400a0(&local_b8);
    uVar17 = 0;
    goto LAB_146d4e498b3;
  }
  bVar19 = false;
LAB_146d4e497c8:
  uVar10 = (*(code *)0x7ff63a1081a0)(0x146d2d8aad8);
  uVar17 = (ulonglong)uVar10;
  if (-1 < (int)(uVar10 - 1)) {
    do {
      uVar10 = (int)uVar17 - 1;
      uVar17 = (ulonglong)uVar10;
      lVar11 = (*(code *)0x7ff63a1081f0)(0x146d2d8aad8,uVar17);
      if ((lVar11 != 0) && (cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,lVar11), cVar7 != '\0'))
      {
        lVar13 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,0xf);
        lVar14 = 0;
        if (DAT_146d4e68059 != '\0') {
          lVar14 = 0xa0a3;
        }
        if (lVar13 == lVar14) {
          cVar7 = FUN_146d4e58090(lVar11);
          bVar19 = true;
          if (cVar7 == '\0') {
            uVar17 = 0;
            goto LAB_146d4e498b3;
          }
        }
      }
    } while (0 < (int)uVar10);
  }
  if (bVar19) {
    uVar10 = FUN_146d4e49960();
    uVar17 = (ulonglong)uVar10 ^ 1;
  }
  else {
    uVar17 = CONCAT71((int7)(uVar17 >> 8),1);
  }
LAB_146d4e498b3:
  FUN_146d4e400a0(&local_98);
  return uVar17;
LAB_146d4e49565:
  FUN_146d4e400a0(&local_a8);
  FUN_146d4e400a0(&local_88);
LAB_146d4e49576:
  iVar9 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8);
  _DAT_146d4e68150 = CONCAT44(_DAT_146d4e68154,(uint)(iVar9 == 0));
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,&local_b8,(iVar9 != 0) * '\x03' + '\x01');
  _DAT_146d4e68128 = _DAT_146d4e68548;
  _DAT_146d4e68100 = 1;
  FUN_146d4e407d0(&DAT_146d4e68114,&local_b8,0,0x146d4e641b8);
  (*(code *)0x7ff63a107f70)(0x146d2d8aad8,3);
  _DAT_146d4e68120 = _DAT_146d4e68548;
  _DAT_146d4e68104 = (undefined4)_DAT_146d4e68375;
  uRam00000146d4e68108 = (undefined4)((ulonglong)_DAT_146d4e68375 >> 0x20);
  _DAT_146d4e68148 = _DAT_146d4e6837d;
  _DAT_146d4e68170 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,0x11);
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,&local_b8,0x23);
  dVar6 = _DAT_146d4e68548;
  iVar9 = _DAT_146d4e68389;
  dVar5 = _DAT_146d4e68120;
  if (_DAT_146d4e68548 < _DAT_146d4e68120) {
    _DAT_146d4e68120 = _DAT_146d4e68548;
  }
  cVar7 = FUN_146d4e40b20(&DAT_146d4e680e0,&DAT_146d4e68100,&DAT_146d4e681f0);
  if (iVar9 == 2) {
    bVar19 = true;
    if (cVar7 == '\0') goto LAB_146d4e497b6;
    goto LAB_146d4e48eff;
  }
  if (cVar7 == '\0') {
    local_9c = local_9c + -1;
    if (local_9c == 0) {
      bVar19 = local_bc != 0x271a;
      local_bc = 0x271a;
      if (bVar19) goto LAB_146d4e497b6;
      goto LAB_146d4e497aa;
    }
  }
  else {
    bVar19 = true;
    if ((dVar5 <= dVar6) || (DAT_146d4e68374 != '\0')) goto LAB_146d4e48eff;
    (*(code *)0x7ff63a0e17c0)(0x146d2d8aad8,1000);
    local_bc = 0x271a;
  }
  if (dVar5 <= dVar6) goto code_r0x0146d4e4977a;
  goto LAB_146d4e493b9;
code_r0x0146d4e4977a:
  bVar19 = true;
LAB_146d4e48eff:
  FUN_146d4e400a0(&local_b8);
LAB_146d4e48f20:
  bVar3 = iVar8 < 1;
  iVar8 = iVar8 + -1;
  if (bVar3) goto LAB_146d4e497c8;
  goto LAB_146d4e48f2d;
}



/* Address: 146d4e49960 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e49960(void)

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
  undefined8 uVar10;
  longlong lVar11;
  uint uVar12;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined4 local_50;
  longlong local_4c;
  ulonglong uVar13;
  
  local_50 = 0;
  local_4c = 0;
  iVar8 = (*(code *)0x7ff63a107da0)(0x146d2d8aad8);
  uVar12 = iVar8 - 1;
  if (-1 < (int)uVar12) {
    do {
      uVar13 = (ulonglong)uVar12;
      lVar9 = (*(code *)0x7ff63a107df0)(0x146d2d8aad8,uVar13);
      if ((lVar9 != 0) && (cVar7 = (*(code *)0x7ff63a107ee0)(0x146d2d8aad8,lVar9), cVar7 != '\0')) {
        (*(code *)0x7ff63a108010)(0x146d2d8aad8,0);
        FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65c08);
        if (local_4c == _DAT_146d4e6852c) {
LAB_146d4e499e4:
          lVar9 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,0xc);
          lVar11 = 0;
          if (DAT_146d4e68059 != '\0') {
            lVar11 = 0xa0a3;
          }
          if (lVar9 == lVar11) goto LAB_146d4e49e39;
        }
        else if ((local_4c != 0) && (_DAT_146d4e6852c != 0)) {
          uVar3 = *(uint *)(local_4c + -4);
          uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar15 = 1;
            do {
              uVar1 = *(ushort *)(local_4c + -2 + uVar15 * 2);
              uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar15 * 2);
              if (uVar6 <= uVar15) break;
              uVar15 = uVar15 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_146d4e499e4;
        }
      }
      bVar5 = 0 < (int)uVar12;
      uVar12 = uVar12 - 1;
    } while (bVar5);
  }
  iVar8 = (*(code *)0x7ff63a1081a0)(0x146d2d8aad8);
  uVar12 = iVar8 - 1;
  if (-1 < (int)uVar12) {
    do {
      uVar13 = (ulonglong)uVar12;
      lVar9 = (*(code *)0x7ff63a1081f0)(0x146d2d8aad8,uVar13);
      if ((lVar9 != 0) && (cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,lVar9), cVar7 != '\0')) {
        (*(code *)0x7ff63a1083a0)(0x146d2d8aad8,0);
        FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65c18);
        if (local_4c == _DAT_146d4e6852c) {
LAB_146d4e49b68:
          lVar9 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,0xf);
          lVar11 = 0;
          if (DAT_146d4e68059 != '\0') {
            lVar11 = 0xa0a3;
          }
          if (lVar9 == lVar11) goto LAB_146d4e49e39;
        }
        else if ((local_4c != 0) && (_DAT_146d4e6852c != 0)) {
          uVar3 = *(uint *)(local_4c + -4);
          uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar15 = 1;
            do {
              uVar1 = *(ushort *)(local_4c + -2 + uVar15 * 2);
              uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar15 * 2);
              if (uVar6 <= uVar15) break;
              uVar15 = uVar15 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_146d4e49b68;
        }
      }
      bVar5 = 0 < (int)uVar12;
      uVar12 = uVar12 - 1;
    } while (bVar5);
  }
  uVar14 = 0;
  uVar10 = (*(code *)0x7ff63a101c40)(0x146d2d8aad8,0);
  cVar7 = (*(code *)0x7ff63a1084f0)(0x146d2d8aad8,0,uVar10);
  if (cVar7 != '\0') {
    iVar8 = (*(code *)0x7ff63a108810)(0x146d2d8aad8);
    uVar12 = iVar8 - 1;
    if (-1 < (int)uVar12) {
      do {
        uVar13 = (ulonglong)uVar12;
        lVar9 = (*(code *)0x7ff63a108860)(0x146d2d8aad8,uVar13);
        if (lVar9 != 0) {
          (*(code *)0x7ff63a1089d0)(0x146d2d8aad8,lVar9,0);
          FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65c28);
          if (local_4c == _DAT_146d4e6852c) {
LAB_146d4e49d20:
            lVar9 = (*(code *)0x7ff63a108940)(0x146d2d8aad8,lVar9);
            lVar11 = 0;
            if (DAT_146d4e68059 != '\0') {
              lVar11 = 0xa0a3;
            }
            if (lVar9 == lVar11) goto LAB_146d4e49e39;
          }
          else if ((local_4c != 0) && (_DAT_146d4e6852c != 0)) {
            uVar3 = *(uint *)(local_4c + -4);
            uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar8 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar15 = 1;
              do {
                uVar1 = *(ushort *)(local_4c + -2 + uVar15 * 2);
                uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar15 * 2);
                if (uVar6 <= uVar15) break;
                uVar15 = uVar15 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar8 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar8 == 0) goto LAB_146d4e49d20;
          }
        }
        bVar5 = 0 < (int)uVar12;
        uVar12 = uVar12 - 1;
      } while (bVar5);
    }
    uVar14 = 0;
  }
LAB_146d4e49e3c:
  FUN_146d4e400a0(&local_50);
  return uVar14;
LAB_146d4e49e39:
  uVar14 = CONCAT71((int7)(uVar13 >> 8),1);
  goto LAB_146d4e49e3c;
}



/* Address: 146d4e49e60 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e49e60(char param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  double dVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  uint uVar14;
  byte *pbVar15;
  uint *puVar16;
  int iVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined1 *puVar20;
  undefined4 uVar21;
  uint *puVar22;
  uint local_144 [5];
  uint local_130;
  undefined1 *local_12c;
  undefined4 local_120;
  undefined8 local_11c;
  int local_114;
  undefined4 local_110;
  undefined1 *local_10c;
  double local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 local_d8 [64];
  undefined1 local_98 [88];
  
  if (param_1 == '\0') {
    return;
  }
  if ((DAT_146d4e683bc & 1) != 0) {
    return;
  }
  iVar10 = (*(code *)0x7ff63a0f0fd0)(0x146d2d8aad8,6);
  if (iVar10 == 0) {
    return;
  }
  iVar10 = (*(code *)0x7ff63a0f0fd0)(0x146d2d8aad8,6);
  if ((iVar10 == 0) ||
     ((*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x25), _DAT_146d4e5e2f0 < _DAT_146d4e68548)) {
LAB_146d4e49f8d:
    iVar10 = 0;
    if ((DAT_146d4e68070 & 1) != 0) {
      iVar10 = 0xf;
    }
    iVar17 = 0;
    if ((DAT_146d4e68001 & 1) != 0) {
      iVar17 = 0xf;
    }
    bVar1 = DAT_146d4e68001;
    if ((DAT_146d4e68000 & 1) != 0) {
      iVar17 = iVar10;
      bVar1 = DAT_146d4e68070;
    }
    if ((bVar1 & 1) == 0) {
      return;
    }
    if (iVar17 == _DAT_146d4e68524) {
      return;
    }
  }
  else {
    iVar10 = 0;
    if ((DAT_146d4e68070 & 1) != 0) {
      iVar10 = 0xf;
    }
    iVar17 = 0;
    if ((DAT_146d4e68001 & 1) != 0) {
      iVar17 = 0xf;
    }
    bVar1 = DAT_146d4e68001;
    if ((DAT_146d4e68000 & 1) != 0) {
      bVar1 = DAT_146d4e68070;
      iVar17 = iVar10;
    }
    if (((bVar1 & 1) == 0) || (iVar17 == _DAT_146d4e68524)) goto LAB_146d4e49f8d;
  }
  pbVar15 = &DAT_146d4e68058;
  if ((DAT_146d4e68000 & 1) != 0) {
    pbVar15 = &DAT_146d4e680c8;
  }
  if (_DAT_146d4e683b8 < (int)((uint)*pbVar15 + (uint)*pbVar15 * 4)) {
    return;
  }
  cVar9 = FUN_146d4e49960();
  if (cVar9 != '\0') {
    return;
  }
  local_144[1] = 0;
  local_110 = 0;
  local_144[2] = 0;
  local_144[3] = 0;
  local_10c = (undefined1 *)0x0;
  cVar9 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,0x146d4e5e890,local_98);
  if (cVar9 == '\0') {
    FUN_146d4e400a0(local_144 + 1);
    return;
  }
  iVar10 = 0;
  if (DAT_146d4e68070 != 0) {
    iVar10 = 0xf;
  }
  iVar17 = 0;
  if (DAT_146d4e68001 != 0) {
    iVar17 = 0xf;
  }
  if (DAT_146d4e68000 != 0) {
    iVar17 = iVar10;
  }
  if (iVar17 == 0) {
    iVar17 = _DAT_146d4e68524;
  }
  (*(code *)0x7ff63a103d40)(0x146d2d8aad8,0x146d4e5e890,iVar17,1);
  dVar8 = _DAT_146d4e68548;
  local_114 = iVar17;
  (*(code *)0x7ff63a103bc0)(0x146d2d8aad8,0x146d4e5e890,iVar17,1);
  bVar5 = dVar8 < _DAT_146d4e68548;
  local_f8 = 0;
  local_f4 = 0;
  bVar6 = !bVar5;
  FUN_146d4e42480();
  FUN_146d4e407d0(local_144 + 1,&DAT_146d4e6853c,1,0x146d4e65c68);
  FUN_146d4e407d0(&local_f8,local_144 + 1,0,0x146d4e65c78);
  local_130 = 0;
  local_12c = (undefined1 *)0x0;
  FUN_146d4e407d0(&local_130,0x146d4e5e910,0,0x146d4e65c88);
  puVar20 = local_d8;
  local_144[0] = (uint)bVar5;
  local_100 = 0.0;
  cVar9 = FUN_146d4e5d650(0x146d4e68528,bVar6,&local_130,local_144,&local_100,puVar20);
  uVar21 = (undefined4)((ulonglong)puVar20 >> 0x20);
  if (cVar9 == '\0') {
    iVar10 = (*(code *)0x7ff63a0f2730)(0x146d2d8aad8,1);
    uVar21 = (undefined4)((ulonglong)puVar20 >> 0x20);
    if (0 < iVar10) {
      iVar17 = 0;
      do {
        local_110 = 0;
        local_10c = (undefined1 *)0x0;
        (*(code *)0x7ff63a0f2780)(0x146d2d8aad8,iVar17,1);
        FUN_146d4e407d0(local_144 + 1,&DAT_146d4e6853c,1,0x146d4e65c98);
        FUN_146d4e407d0(&local_110,local_144 + 1,0);
        if (local_10c == &DAT_146d4e5e908) {
LAB_146d4e4a300:
          FUN_146d4e400a0(&local_110);
        }
        else {
          if (local_10c != (undefined1 *)0x0) {
            uVar4 = *(uint *)(local_10c + -4);
            uVar14 = _DAT_146d4e5e904;
            if (uVar4 < _DAT_146d4e5e904) {
              uVar14 = uVar4;
            }
            iVar11 = uVar4 - _DAT_146d4e5e904;
            if (uVar14 != 0) {
              uVar18 = 0;
              do {
                uVar2 = *(ushort *)(local_10c + uVar18 * 2);
                uVar3 = *(ushort *)(&DAT_146d4e5e908 + uVar18 * 2);
                uVar18 = uVar18 + 1;
                if (uVar14 <= uVar18) break;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar11 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar11 == 0) goto LAB_146d4e4a300;
          }
          if (local_10c == _DAT_146d4e6852c) goto LAB_146d4e4a300;
          if ((local_10c != (undefined1 *)0x0) && (_DAT_146d4e6852c != (undefined1 *)0x0)) {
            uVar4 = *(uint *)(local_10c + -4);
            uVar14 = *(uint *)(_DAT_146d4e6852c + -4);
            uVar7 = uVar14;
            if (uVar4 < uVar14) {
              uVar7 = uVar4;
            }
            iVar11 = uVar4 - uVar14;
            if (uVar7 != 0) {
              uVar18 = 1;
              do {
                uVar2 = *(ushort *)(local_10c + uVar18 * 2 + -2);
                uVar3 = *(ushort *)(_DAT_146d4e6852c + uVar18 * 2 + -2);
                if (uVar7 <= uVar18) break;
                uVar18 = uVar18 + 1;
              } while (uVar2 == uVar3);
              if (uVar2 != uVar3) {
                iVar11 = (uint)uVar2 - (uint)uVar3;
              }
            }
            if (iVar11 == 0) goto LAB_146d4e4a300;
          }
          puVar20 = local_d8;
          cVar9 = FUN_146d4e5d650(&local_110,bVar6,&local_130,local_144,&local_100,puVar20);
          FUN_146d4e400a0(&local_110);
          uVar21 = (undefined4)((ulonglong)puVar20 >> 0x20);
          if (cVar9 != '\0') break;
        }
        uVar21 = (undefined4)((ulonglong)puVar20 >> 0x20);
        iVar17 = iVar17 + 1;
      } while (iVar17 != iVar10);
    }
  }
  dVar8 = local_100;
  if (local_12c == &DAT_146d4e5e908) {
LAB_146d4e4a6be:
    (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x2a);
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,_DAT_146d4e68548,2);
    puVar22 = local_144 + 1;
    FUN_146d4e407d0(puVar22,&DAT_146d4e6853c,1,0x146d4e65cb8);
    uVar13 = 2;
    uVar19 = 0x146d4e633f8;
  }
  else {
    if (local_12c == (undefined1 *)0x0) {
      iVar10 = 1;
    }
    else {
      uVar4 = *(uint *)(local_12c + -4);
      uVar14 = _DAT_146d4e5e904;
      if (uVar4 < _DAT_146d4e5e904) {
        uVar14 = uVar4;
      }
      iVar10 = uVar4 - _DAT_146d4e5e904;
      if (uVar14 != 0) {
        uVar18 = 0;
        do {
          uVar2 = *(ushort *)(local_12c + uVar18 * 2);
          uVar3 = *(ushort *)(&DAT_146d4e5e908 + uVar18 * 2);
          uVar18 = uVar18 + 1;
          if (uVar14 <= uVar18) break;
        } while (uVar2 == uVar3);
        if (uVar2 != uVar3) {
          iVar10 = (uint)uVar2 - (uint)uVar3;
        }
      }
    }
    if ((iVar10 == 0) || (local_100 <= 0.0)) goto LAB_146d4e4a6be;
    puVar22 = &local_130;
    uVar18 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,puVar22,0x32);
    uVar12 = 0;
    if (((uVar18 & 1) != 0) || (uVar12 = 1, (uVar18 & 2) != 0)) {
      _DAT_146d4e68385 = uVar12;
    }
    if (local_144[0] != 0) {
      local_120 = 0;
      local_11c = 0;
      puVar16 = (uint *)0x146d4e68528;
      if (local_12c != (undefined1 *)0x0) {
        puVar16 = puVar22;
      }
      FUN_146d4e407d0(&local_120,puVar16,0,0x146d4e64228);
      (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,&local_120,1);
      cVar9 = FUN_146d4e4c3e0(&local_120,1,dVar8,_DAT_146d4e68548,&local_f8);
      FUN_146d4e400a0(&local_120);
      iVar10 = _DAT_146d4e683b8;
      if (cVar9 == '\0') goto LAB_146d4e4a94d;
      FUN_146d4e421a0(local_114);
      FUN_146d4e407d0(local_144 + 1,&DAT_146d4e6853c,1,0x146d4e65cd8);
      uVar13 = 0x146d4e63558;
LAB_146d4e4a8fd:
      (*(code *)0x7ff63a0e49f0)
                (0x146d2d8aad8,2,7,0x590008,uVar13,CONCAT44(uVar21,0x590008),puVar22,0x590008,
                 0x146d4e623b0,0x590008,local_144 + 1,0x590008,0x146d4e634a0,0x520004,iVar10,
                 0x590008,0x146d4e634f0);
      cVar9 = FUN_146d4e48e50();
      if (cVar9 == '\0') {
        bVar5 = false;
      }
      else {
        bVar5 = false;
        DAT_146d4e683bd = 1;
      }
      goto LAB_146d4e4a762;
    }
    local_120 = 0;
    local_11c = 0;
    puVar16 = (uint *)0x146d4e68528;
    if (local_12c != (undefined1 *)0x0) {
      puVar16 = puVar22;
    }
    FUN_146d4e407d0(&local_120,puVar16,0,0x146d4e64218);
    (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,&local_120,4);
    cVar9 = FUN_146d4e4c3e0(&local_120,0,dVar8,_DAT_146d4e68548,&local_f8);
    FUN_146d4e400a0(&local_120);
    iVar10 = _DAT_146d4e683b8;
    if (cVar9 != '\0') {
      FUN_146d4e421a0(local_114);
      FUN_146d4e407d0(local_144 + 1,&DAT_146d4e6853c,1,0x146d4e65cc8);
      uVar13 = 0x146d4e63468;
      goto LAB_146d4e4a8fd;
    }
LAB_146d4e4a94d:
    local_120 = 0;
    local_11c = 0;
    local_e8 = 0;
    local_e0 = 0;
    FUN_146d4e4ba00(&local_e8,&DAT_146d4e68100,&DAT_146d4e681f0);
    FUN_146d4e407d0(&local_120,&local_e8,0,0x146d4e64168);
    FUN_146d4e400a0(&local_e8);
    FUN_146d4e407d0(&DAT_146d4e6853c,&local_120,1,0x146d4e64178);
    FUN_146d4e400a0(&local_120);
    FUN_146d4e407d0(local_144 + 1,&DAT_146d4e6853c,1,0x146d4e65ce8);
    uVar13 = 4;
    uVar19 = 0x146d4e635c0;
  }
  bVar5 = true;
  (*(code *)0x7ff63a0e49f0)
            (0x146d2d8aad8,2,uVar13,0x590008,uVar19,CONCAT44(uVar21,0x590008),puVar22);
LAB_146d4e4a762:
  FUN_146d4e400a0(&local_130);
  FUN_146d4e400a0(&local_f8);
  FUN_146d4e400a0(local_144 + 1);
  if (!bVar5) {
    DAT_146d4e683bc = 1;
  }
  return;
}



/* Address: 146d4e4abc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e4abc0(void)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  FUN_146d4e5c7e0();
  FUN_146d4e407d0(&local_20,&DAT_146d4e6853c,1,0x146d4e657e8);
  FUN_146d4e407d0(&local_30,&local_20,0,0x146d4e657f8);
  uVar1 = 0;
  if (0.0 < _DAT_146d4e683a8) {
    uVar1 = FUN_146d4e59600(0x146d4e68528);
  }
  (*(code *)0x7ff63a0edc90)(0x146d2d8aad8,&local_30,uVar1);
  FUN_146d4e400a0(&local_30);
  FUN_146d4e400a0(&local_20);
  return;
}



/* Address: 146d4e4acb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e4acb0(void)

{
  int iVar1;
  
  _DAT_146d4e68488 = 0;
  _DAT_146d4e6848c = 0;
  FUN_146d4e407d0(&DAT_146d4e68488,0x146d4e5e910,0,0x146d4e64040);
  _DAT_146d4e68480 = 0;
  _DAT_146d4e6847c = 0;
  _DAT_146d4e68484 = 0;
  _DAT_146d4e68470 = 0;
  _DAT_146d4e68474 = 0;
  FUN_146d4e407d0(&DAT_146d4e68470,0x146d4e5e910,0,0x146d4e64050);
  _DAT_146d4e68460 = 0;
  _DAT_146d4e68464 = 0;
  FUN_146d4e407d0(&DAT_146d4e68460,0x146d4e5e910,0,0x146d4e64060);
  _DAT_146d4e68450 = 0;
  _DAT_146d4e68454 = 0;
  FUN_146d4e407d0(&DAT_146d4e68450,0x146d4e5e910,0,0x146d4e64070);
  _DAT_146d4e68440 = 0;
  _DAT_146d4e68444 = 0;
  FUN_146d4e407d0(&DAT_146d4e68440,0x146d4e5e910,0,0x146d4e64080);
  _DAT_146d4e68430 = 0;
  _DAT_146d4e68434 = 0;
  FUN_146d4e407d0(&DAT_146d4e68430,0x146d4e5e910,0,0x146d4e64090);
  _DAT_146d4e68420 = 0;
  _DAT_146d4e68424 = 0;
  FUN_146d4e407d0(&DAT_146d4e68420,0x146d4e5e910,0,0x146d4e640a0);
  _DAT_146d4e68410 = 0;
  _DAT_146d4e68414 = 0;
  FUN_146d4e407d0(&DAT_146d4e68410,0x146d4e5e910,0,0x146d4e640b0);
  _DAT_146d4e68400 = 0;
  _DAT_146d4e68404 = 0;
  FUN_146d4e407d0(&DAT_146d4e68400,0x146d4e5e910,0,0x146d4e640c0);
  _DAT_146d4e683f0 = 0;
  _DAT_146d4e683f4 = 0;
  FUN_146d4e407d0(&DAT_146d4e683f0,0x146d4e5e910,0,0x146d4e640d0);
  _DAT_146d4e683e0 = 0;
  _DAT_146d4e683e4 = 0;
  FUN_146d4e407d0(&DAT_146d4e683e0,0x146d4e5e910,0,0x146d4e640e0);
  _DAT_146d4e683d0 = 0;
  _DAT_146d4e683d4 = 0;
  FUN_146d4e407d0(&DAT_146d4e683d0,0x146d4e5e910,0,0x146d4e640f0);
  DAT_146d4e683cd = 0;
  DAT_146d4e683cc = 0;
  DAT_146d4e683ce = 0;
  _DAT_146d4e683c0 = 0;
  _DAT_146d4e683c4 = 0;
  FUN_146d4e407d0(&DAT_146d4e683c0,0x146d4e5e968,0,0x146d4e64100);
  DAT_146d4e683bc = 0;
  _DAT_146d4e683b8 = 0;
  DAT_146d4e683bd = 0;
  _DAT_146d4e683b4 = 0;
  DAT_146d4e683b0 = 0;
  _DAT_146d4e683a8 = 0;
  _DAT_146d4e683a0 = 0;
  DAT_146d4e68398 = 1;
  _DAT_146d4e68394 = 0xffffffff;
  _DAT_146d4e680d0 = 0x3f847ae147ae147b;
  DAT_146d4e680ca = 1;
  DAT_146d4e680c9 = 1;
  DAT_146d4e680c8 = 1;
  _DAT_146d4e680c0 = 0x3f8eb851eb851eb8;
  _DAT_146d4e680b8 = 0x3fc70a3d70a3d70a;
  DAT_146d4e680b0 = 1;
  _DAT_146d4e680a8 = 0x3fe8f5c28f5c28f6;
  DAT_146d4e680a0 = 1;
  _DAT_146d4e68098 = 0x407f400000000000;
  DAT_146d4e68088 = 1;
  _DAT_146d4e68090 = 0x3ff8f5c28f5c28f6;
  _DAT_146d4e68078 = 0x3ff999999999999a;
  _DAT_146d4e68080 = 0x4002666666666666;
  DAT_146d4e68073 = 1;
  DAT_146d4e68074 = 1;
  DAT_146d4e68071 = 1;
  DAT_146d4e68072 = 1;
  DAT_146d4e6806f = 1;
  DAT_146d4e68070 = 1;
  DAT_146d4e6806d = 1;
  DAT_146d4e6806e = 1;
  DAT_146d4e6806c = 1;
  _DAT_146d4e68060 = 0;
  _DAT_146d4e68064 = 0;
  FUN_146d4e407d0(&DAT_146d4e68060,0x146d4e5e8f0,0,0x146d4e64110);
  DAT_146d4e68058 = 1;
  DAT_146d4e68059 = 1;
  _DAT_146d4e68050 = 0x3f90624dd2f1a9fc;
  _DAT_146d4e68048 = 0x3fc70a3d70a3d70a;
  DAT_146d4e68040 = 1;
  _DAT_146d4e68038 = 0x3fe8f5c28f5c28f6;
  DAT_146d4e68030 = 1;
  _DAT_146d4e68028 = 0x407f400000000000;
  _DAT_146d4e68020 = 0x3fee147ae147ae14;
  DAT_146d4e68018 = 1;
  _DAT_146d4e68010 = 0x4002666666666666;
  _DAT_146d4e68008 = 0x3ff999999999999a;
  DAT_146d4e68005 = 1;
  DAT_146d4e68004 = 1;
  DAT_146d4e68003 = 1;
  DAT_146d4e68002 = 1;
  DAT_146d4e68001 = 1;
  DAT_146d4e68000 = 1;
  (*(code *)0x7ff63a0e4490)(0x146d2d8aad8,0x146d2d1a300,&DAT_146d4e680e0);
  (*(code *)0x7ff63a0e6470)(0x146d2d8aad8,_DAT_146d4e680e0,0x146d2da9430);
  _DAT_146d4e680e8 = 0x146d4e5e7d0;
  _DAT_146d4e680f0 = 0;
  uRam00000146d4e680f8 = 0;
  _DAT_146d4e68114 = 0;
  _DAT_146d4e68118 = 0;
  _DAT_146d4e68164 = 0;
  _DAT_146d4e68168 = 0;
  _DAT_146d4e68224 = 0;
  _DAT_146d4e68228 = 0;
  _DAT_146d4e682e8 = 0;
  _DAT_146d4e682ec = 0;
  (*(code *)0x7ff63a0e6470)(0x146d2d8aad8,_DAT_146d4e680e0,0x146d2d79600);
  _DAT_146d4e680e8 = 0x146d4e5e810;
  _DAT_146d4e680f0 = 0;
  uRam00000146d4e680f8 = 0;
  (*(code *)0x7ff63a0e6470)(0x146d2d8aad8,_DAT_146d4e680e0,0x146d2d1a300);
  _DAT_146d4e680e8 = 0x146d4e5e850;
  DAT_146d4e68374 = 0;
  _DAT_146d4e68375 = 0;
  _DAT_146d4e6837d = 10;
  _DAT_146d4e68385 = 0;
  _DAT_146d4e6838d = 1;
  _DAT_146d4e68389 = (*(code *)0x7ff63a0c73c0)(0x146d2d8aad8,0x35);
  _DAT_146d4e68100 = 0;
  uRam00000146d4e68108 = 0;
  _DAT_146d4e68110 = 0;
  FUN_146d4e400a0(&DAT_146d4e68114);
  _DAT_146d4e68130 = 0;
  _DAT_146d4e68138 = 0;
  _DAT_146d4e68140 = 0;
  _DAT_146d4e68148 = 0;
  _DAT_146d4e68150 = 0;
  _DAT_146d4e68158 = 0;
  _DAT_146d4e68160 = 0;
  _DAT_146d4e68120 = 0;
  _DAT_146d4e68128 = 0;
  FUN_146d4e400a0(&DAT_146d4e68164);
  _DAT_146d4e68200 = 0;
  uRam00000146d4e68208 = 0;
  _DAT_146d4e681f0 = 0;
  uRam00000146d4e681f8 = 0;
  _DAT_146d4e68210 = 0;
  uRam00000146d4e68218 = 0;
  _DAT_146d4e681e0 = 0;
  uRam00000146d4e681e8 = 0;
  _DAT_146d4e681d0 = 0;
  uRam00000146d4e681d8 = 0;
  _DAT_146d4e681c0 = 0;
  uRam00000146d4e681c8 = 0;
  _DAT_146d4e681b0 = 0;
  uRam00000146d4e681b8 = 0;
  _DAT_146d4e681a0 = 0;
  uRam00000146d4e681a8 = 0;
  _DAT_146d4e68190 = 0;
  uRam00000146d4e68198 = 0;
  _DAT_146d4e68180 = 0;
  uRam00000146d4e68188 = 0;
  _DAT_146d4e68170 = 0;
  uRam00000146d4e68178 = 0;
  _DAT_146d4e68220 = 0;
  FUN_146d4e400a0(&DAT_146d4e68224);
  _DAT_146d4e682c0 = 0;
  uRam00000146d4e682c8 = 0;
  _DAT_146d4e682b0 = 0;
  uRam00000146d4e682b8 = 0;
  _DAT_146d4e682d0 = 0;
  uRam00000146d4e682d8 = 0;
  _DAT_146d4e682a0 = 0;
  uRam00000146d4e682a8 = 0;
  _DAT_146d4e68290 = 0;
  uRam00000146d4e68298 = 0;
  _DAT_146d4e68280 = 0;
  uRam00000146d4e68288 = 0;
  _DAT_146d4e68270 = 0;
  uRam00000146d4e68278 = 0;
  _DAT_146d4e68260 = 0;
  uRam00000146d4e68268 = 0;
  _DAT_146d4e68250 = 0;
  uRam00000146d4e68258 = 0;
  _DAT_146d4e68240 = 0;
  uRam00000146d4e68248 = 0;
  _DAT_146d4e68230 = 0;
  uRam00000146d4e68238 = 0;
  _DAT_146d4e682e0 = 0;
  FUN_146d4e400a0(&DAT_146d4e682e8);
  _DAT_146d4e6835c = 0;
  _DAT_146d4e68364 = 0;
  _DAT_146d4e6836c = 0;
  _DAT_146d4e6834c = 0;
  _DAT_146d4e68354 = 0;
  _DAT_146d4e682f4 = 0;
  _DAT_146d4e6833c = 0;
  _DAT_146d4e68344 = 0;
  _DAT_146d4e6832c = 0;
  _DAT_146d4e68334 = 0;
  _DAT_146d4e6831c = 0;
  _DAT_146d4e68324 = 0;
  _DAT_146d4e6830c = 0;
  _DAT_146d4e68314 = 0;
  _DAT_146d4e682fc = 0;
  _DAT_146d4e68304 = 0;
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x146d2d8aad8,6);
  if (iVar1 != 0) {
    _DAT_146d4e6838d = 2;
  }
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x146d2d8aad8,7);
  if (iVar1 != 0) {
    _DAT_146d4e6838d = 0;
  }
  return;
}



/* Address: 146d4e4b7f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e4b7f0(void)

{
  int *piVar1;
  
  FUN_146d4e400a0(&DAT_146d4e682e8);
  FUN_146d4e400a0(&DAT_146d4e68224);
  FUN_146d4e400a0(&DAT_146d4e68164);
  FUN_146d4e400a0(&DAT_146d4e68114);
  (*(code *)0x7ff63a0e6470)(0x146d2d8aad8,_DAT_146d4e680e0,0x146d2d79600);
  _DAT_146d4e680e8 = 0x146d4e5e810;
  (*(code *)0x7ff63a0e62f0)(0x146d2d8aad8,_DAT_146d4e680e0);
  FUN_146d4e400a0(&DAT_146d4e68488);
  FUN_146d4e400a0(&DAT_146d4e68470);
  FUN_146d4e400a0(&DAT_146d4e68460);
  FUN_146d4e400a0(&DAT_146d4e68450);
  FUN_146d4e400a0(&DAT_146d4e68440);
  FUN_146d4e400a0(&DAT_146d4e68430);
  FUN_146d4e400a0(&DAT_146d4e68420);
  FUN_146d4e400a0(&DAT_146d4e68410);
  FUN_146d4e400a0(&DAT_146d4e68400);
  FUN_146d4e400a0(&DAT_146d4e683f0);
  FUN_146d4e400a0(&DAT_146d4e683e0);
  FUN_146d4e400a0(&DAT_146d4e683d0);
  FUN_146d4e400a0(&DAT_146d4e683c0);
  if ((((_DAT_146d4e68060 != 0) && (_DAT_146d4e68064 != 0)) &&
      ((int *)(_DAT_146d4e68064 + -0xc) != (int *)0x0)) && (*(int *)(_DAT_146d4e68064 + -0xc) != 0))
  {
    piVar1 = (int *)(_DAT_146d4e68064 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x146d2d8aad8);
    }
  }
  _DAT_146d4e68064 = 0;
  _DAT_146d4e68060 = 0;
  return;
}



/* Address: 146d4e4b940 */

void FUN_146d4e4b940(void)

{
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_2c = 0;
  local_40 = 0;
  local_38 = 0;
  FUN_146d4e4ba00(&local_40,&DAT_146d4e68100,&DAT_146d4e681f0);
  FUN_146d4e407d0(&local_30,&local_40,0,0x146d4e64168);
  FUN_146d4e400a0(&local_40);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_30,1,0x146d4e64178);
  FUN_146d4e400a0(&local_30);
  return;
}



/* Address: 146d4e4ba00 */

void FUN_146d4e4ba00(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x146d4e68528;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_146d4e407d0(&local_60,lVar10,0,0x146d4e64a18);
  (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4bb37 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x146d4e5e2f8))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x146d2d8aad8,*param_3,0x53,&local_88);
  FUN_146d4e407d0(&local_98,0x146d4e60490,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_146d4e4c19f;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_146d4e4c19f;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_146d4e40100(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1f0561000101f9);
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
      if (uVar11 == uVar12) goto LAB_146d4e4c392;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_146d4e4c392:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_146d4e4c19f:
  FUN_146d4e407d0(param_1,&local_98,0,0x146d4e64d18);
  FUN_146d4e407d0(&local_50,param_1,0,0x146d4e64d28);
  FUN_146d4e400a0(&local_60);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_50,1,0x146d4e64d38);
  FUN_146d4e400a0(&local_50);
  FUN_146d4e400a0(&local_88);
  FUN_146d4e400a0(&local_98);
  FUN_146d4e400a0(&local_78);
  return;
}



/* Address: 146d4e4c220 */

void FUN_146d4e4c220(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_146d4e407d0(&stack0x00000060,&DAT_146d4e6853c,1,0x146d4e64ae8);
  (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd8,2,0x590008,0x146d4e5fd20);
  FUN_146d4e407d0(&stack0x00000050,&DAT_146d4e6853c,1,0x146d4e64af8);
  FUN_146d4e407d0(in_stack_00000048,&stack0x00000050,0,0x146d4e64b08);
  FUN_146d4e407d0(&stack0x00000098,in_stack_00000048,0,0x146d4e64d28);
  FUN_146d4e400a0(&stack0x00000088);
  FUN_146d4e407d0(&DAT_146d4e6853c,&stack0x00000098,1,0x146d4e64d38);
  FUN_146d4e400a0(&stack0x00000098);
  FUN_146d4e400a0(&stack0x00000060);
  FUN_146d4e400a0(&stack0x00000050);
  FUN_146d4e400a0(&stack0x00000070);
  return;
}



/* Address: 146d4e4c3e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_146d4e4c3e0(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 unaff_XMM8_Dd;
  undefined4 uStack_80;
  undefined8 uStack_7c;
  undefined4 uStack_70;
  undefined8 uStack_6c;
  undefined4 uStack_60;
  undefined8 uStack_5c;
  undefined4 uStack_50;
  undefined8 uStack_4c;
  
  uStack_4c = CONCAT44(uStack_4c._4_4_,unaff_XMM8_Dd);
  if (_DAT_146d4e68514 != 0) {
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd,2,0x590008,0x146d4e60610,0x590008,0x146d4e5f2a8);
    _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x272b);
    return 0;
  }
  _DAT_146d4e68100 = 0;
  _DAT_146d4e68104 = 0;
  uRam00000146d4e68108 = 0;
  _DAT_146d4e6810c = 0;
  _DAT_146d4e68110 = 0;
  FUN_146d4e400a0(&DAT_146d4e68114);
  _DAT_146d4e68160 = 0;
  _DAT_146d4e68150 = 0;
  _DAT_146d4e68158 = 0;
  _DAT_146d4e68140 = 0;
  _DAT_146d4e68148 = 0;
  _DAT_146d4e68130 = 0;
  _DAT_146d4e68138 = 0;
  _DAT_146d4e68120 = 0;
  _DAT_146d4e68128 = 0;
  FUN_146d4e400a0(&DAT_146d4e68164);
  _DAT_146d4e681e0 = 0;
  uRam00000146d4e681e8 = 0;
  _DAT_146d4e68200 = 0;
  uRam00000146d4e68208 = 0;
  _DAT_146d4e68210 = 0;
  uRam00000146d4e68218 = 0;
  _DAT_146d4e681f0 = 0;
  uRam00000146d4e681f8 = 0;
  _DAT_146d4e681c0 = 0;
  uRam00000146d4e681c8 = 0;
  _DAT_146d4e681d0 = 0;
  uRam00000146d4e681d8 = 0;
  _DAT_146d4e681a0 = 0;
  uRam00000146d4e681a8 = 0;
  _DAT_146d4e681b0 = 0;
  uRam00000146d4e681b8 = 0;
  _DAT_146d4e68180 = 0;
  uRam00000146d4e68188 = 0;
  _DAT_146d4e68190 = 0;
  uRam00000146d4e68198 = 0;
  _DAT_146d4e68220 = 0;
  _DAT_146d4e68170 = 0;
  uRam00000146d4e68178 = 0;
  FUN_146d4e400a0(&DAT_146d4e68224);
  _DAT_146d4e682c0 = 0;
  uRam00000146d4e682c8 = 0;
  _DAT_146d4e682b0 = 0;
  uRam00000146d4e682b8 = 0;
  _DAT_146d4e682d0 = 0;
  uRam00000146d4e682d8 = 0;
  _DAT_146d4e682a0 = 0;
  uRam00000146d4e682a8 = 0;
  _DAT_146d4e68290 = 0;
  uRam00000146d4e68298 = 0;
  _DAT_146d4e68280 = 0;
  uRam00000146d4e68288 = 0;
  _DAT_146d4e68270 = 0;
  uRam00000146d4e68278 = 0;
  _DAT_146d4e68260 = 0;
  uRam00000146d4e68268 = 0;
  _DAT_146d4e68250 = 0;
  uRam00000146d4e68258 = 0;
  _DAT_146d4e68240 = 0;
  uRam00000146d4e68248 = 0;
  _DAT_146d4e68230 = 0;
  uRam00000146d4e68238 = 0;
  _DAT_146d4e682e0 = 0;
  FUN_146d4e400a0(&DAT_146d4e682e8);
  _DAT_146d4e68364 = 0;
  _DAT_146d4e6835c = 0;
  _DAT_146d4e6836c = 0;
  _DAT_146d4e68354 = 0;
  _DAT_146d4e6834c = 0;
  _DAT_146d4e68344 = 0;
  _DAT_146d4e6833c = 0;
  _DAT_146d4e68334 = 0;
  _DAT_146d4e6832c = 0;
  _DAT_146d4e68324 = 0;
  _DAT_146d4e6831c = 0;
  _DAT_146d4e68314 = 0;
  _DAT_146d4e6830c = 0;
  _DAT_146d4e68304 = 0;
  _DAT_146d4e682fc = 0;
  _DAT_146d4e682f4 = 0;
  if (1 < param_2) {
    _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x271d);
    FUN_146d4e407d0(&DAT_146d4e68224,0x146d4e5f2f8,0,0x146d4e64188);
    return 0;
  }
  _DAT_146d4e68100 = 1;
  FUN_146d4e407d0(&DAT_146d4e68114,param_1,0,0x146d4e64198);
  _DAT_146d4e68104 = (undefined4)_DAT_146d4e68375;
  uRam00000146d4e68108 = (undefined4)((ulonglong)_DAT_146d4e68375 >> 0x20);
  _DAT_146d4e68150 = CONCAT44(_DAT_146d4e68154,param_2);
  _DAT_146d4e68138 = 0;
  _DAT_146d4e68140 = 0;
  _DAT_146d4e68148 = _DAT_146d4e6837d;
  _DAT_146d4e68120 = param_3;
  _DAT_146d4e68128 = param_4;
  cVar1 = FUN_146d4e4c920(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = FUN_146d4e4ca90(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_146d4e407d0(&DAT_146d4e68164,param_5,0,0x146d4e641a8);
  uStack_50 = 0;
  uStack_60 = 0;
  uStack_70 = 0;
  uStack_4c = 0;
  uStack_5c = 0;
  uStack_6c = 0;
  FUN_146d4e407d0(&uStack_70,0x146d4e5e910,0,0x146d4e64258);
  uStack_80 = 0;
  uStack_7c = 0;
  FUN_146d4e407d0(&uStack_80,0x146d4e5e910,0,0x146d4e64268);
  if (DAT_146d4e68374 == '\0') {
    pcVar3 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar3 = (code *)0x7ff63a108be0;
  }
  uVar2 = (*pcVar3)(0x146d2d8aad8,&DAT_146d4e68100,&DAT_146d4e681f0);
  if ((char)uVar2 == '\0') {
    if (_DAT_146d4e6838d < 1) goto LAB_146d4e40cf2;
    uVar5 = 0x146d4e642a8;
    uVar4 = 0x146d4e64298;
  }
  else {
    if (_DAT_146d4e6838d < 2) goto LAB_146d4e40cf2;
    uVar5 = 0x146d4e64288;
    uVar4 = 0x146d4e64278;
  }
  FUN_146d4e4ba00(&uStack_80,&DAT_146d4e68100,&DAT_146d4e681f0);
  FUN_146d4e407d0(&uStack_60,&DAT_146d4e6853c,1,uVar4);
  FUN_146d4e4dd20(&DAT_146d4e680e0,&uStack_70,&DAT_146d4e68100);
  FUN_146d4e407d0(&uStack_50,&DAT_146d4e6853c,1,uVar5);
  (*(code *)0x7ff63a0e49f0)
            (0x146d2d8aad8,0xd,3,0x590008,0x146d4e5f638,0x590008,&uStack_50,0x590008,&uStack_60);
LAB_146d4e40cf2:
  FUN_146d4e400a0(&uStack_80);
  FUN_146d4e400a0(&uStack_70);
  FUN_146d4e400a0(&uStack_60);
  FUN_146d4e400a0(&uStack_50);
  return uVar2;
}



/* Address: 146d4e4c920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e4c920(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [8];
  
  local_20 = 0;
  local_28 = 0;
  lVar2 = 0x146d4e68528;
  if (*(longlong *)(param_1 + 4) != 0) {
    lVar2 = param_1;
  }
  FUN_146d4e407d0(&local_28,lVar2,0,0x146d4e64d58);
  (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_28,0x47,local_18);
  if ((ulonglong)_DAT_146d4e68150 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4c9b5 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)((ulonglong)_DAT_146d4e68150 * 8 + 0x146d4e5e420))();
    return uVar1;
  }
  _DAT_146d4e681f0 = 0x2733;
  (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,0x146d4e60588);
  FUN_146d4e400a0(&local_28);
  return 0;
}



/* Address: 146d4e4ca90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e4ca90(longlong param_1)

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
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,param_1,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  iVar1 = _DAT_146d4e68154;
  if (uVar2 < 2) goto LAB_146d4e4ce79;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,param_1,0x32);
  if (uVar2 == 2) {
    iVar1 = _DAT_146d4e68154;
    if (_DAT_146d4e68100 == 5) goto LAB_146d4e4ce79;
    if ((uVar3 & 1) != 0) {
      _DAT_146d4e68385 = 0;
      _DAT_146d4e68154 = 0;
      iVar1 = _DAT_146d4e68154;
      goto LAB_146d4e4ce79;
    }
    if ((uVar3 & 2) != 0) {
      _DAT_146d4e68385 = 1;
      _DAT_146d4e68154 = 1;
      iVar1 = _DAT_146d4e68154;
      goto LAB_146d4e4ce79;
    }
LAB_146d4e4cdd6:
    _DAT_146d4e681f0 = 0x272e;
  }
  else {
    if (_DAT_146d4e68385 == 2) {
LAB_146d4e4ce51:
      _DAT_146d4e68154 = 2;
      iVar1 = _DAT_146d4e68154;
      goto LAB_146d4e4ce79;
    }
    if (_DAT_146d4e68385 == 1) {
      if (_DAT_146d4e68100 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x146d4e68528;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_146d4e407d0(&local_40,lVar5,0,0x146d4e64d48);
        (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_146d4e68158 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4ccb9 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_146d4e68158 * 8 + 0x146d4e5e460))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,0x146d4e60510);
        FUN_146d4e400a0(&local_40);
        _DAT_146d4e68158 = 1;
        if (_DAT_146d4e68150 - 2U < 4) goto LAB_146d4e4ce51;
      }
      uVar3 = uVar3 & 2;
joined_r0x0146d4e4cdd0:
      iVar1 = _DAT_146d4e68385;
      if (uVar3 != 0) goto LAB_146d4e4ce79;
      goto LAB_146d4e4cdd6;
    }
    if (_DAT_146d4e68385 == 0) {
      if (_DAT_146d4e68100 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x146d4e68528;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_146d4e407d0(&local_40,lVar5,0,0x146d4e64d48);
        (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_146d4e68158 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4cbfe */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_146d4e68158 * 8 + 0x146d4e5e480))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,0x146d4e60510);
        FUN_146d4e400a0(&local_40);
        _DAT_146d4e68158 = 1;
        if (_DAT_146d4e68150 - 2U < 4) goto LAB_146d4e4ce51;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x0146d4e4cdd0;
    }
    _DAT_146d4e681f0 = 0x271b;
  }
  uVar4 = 0;
  iVar1 = _DAT_146d4e68154;
LAB_146d4e4ce79:
  _DAT_146d4e68154 = iVar1;
  return uVar4 & 0xffffffff;
}



/* Address: 146d4e4ce90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_146d4e4ce90(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_a0;
  undefined4 local_98;
  undefined1 local_90 [80];
  
  if (_DAT_146d4e68514 == 0) {
    _DAT_146d4e68100 = 0;
    _DAT_146d4e68104 = 0;
    uRam00000146d4e68108 = 0;
    _DAT_146d4e6810c = 0;
    _DAT_146d4e68110 = 0;
    FUN_146d4e400a0(&DAT_146d4e68114);
    _DAT_146d4e68160 = 0;
    _DAT_146d4e68150 = 0;
    _DAT_146d4e68158 = 0;
    _DAT_146d4e6815c = 0;
    _DAT_146d4e68140 = 0;
    _DAT_146d4e68148 = 0;
    _DAT_146d4e68130 = 0;
    _DAT_146d4e68138 = 0;
    _DAT_146d4e68120 = 0;
    _DAT_146d4e68128 = 0;
    FUN_146d4e400a0(&DAT_146d4e68164);
    _DAT_146d4e68200 = 0;
    uRam00000146d4e68208 = 0;
    _DAT_146d4e681f0 = 0;
    uRam00000146d4e681f8 = 0;
    _DAT_146d4e68210 = 0;
    uRam00000146d4e68218 = 0;
    _DAT_146d4e681e0 = 0;
    uRam00000146d4e681e8 = 0;
    _DAT_146d4e681d0 = 0;
    uRam00000146d4e681d8 = 0;
    _DAT_146d4e681c0 = 0;
    uRam00000146d4e681c8 = 0;
    _DAT_146d4e681b0 = 0;
    uRam00000146d4e681b8 = 0;
    _DAT_146d4e681a0 = 0;
    uRam00000146d4e681a8 = 0;
    _DAT_146d4e68190 = 0;
    uRam00000146d4e68198 = 0;
    _DAT_146d4e68180 = 0;
    uRam00000146d4e68188 = 0;
    _DAT_146d4e68170 = 0;
    uRam00000146d4e68178 = 0;
    _DAT_146d4e68220 = 0;
    FUN_146d4e400a0(&DAT_146d4e68224);
    _DAT_146d4e682c0 = 0;
    uRam00000146d4e682c8 = 0;
    _DAT_146d4e682b0 = 0;
    uRam00000146d4e682b8 = 0;
    _DAT_146d4e682d0 = 0;
    uRam00000146d4e682d8 = 0;
    _DAT_146d4e682a0 = 0;
    uRam00000146d4e682a8 = 0;
    _DAT_146d4e68290 = 0;
    uRam00000146d4e68298 = 0;
    _DAT_146d4e68280 = 0;
    uRam00000146d4e68288 = 0;
    _DAT_146d4e68270 = 0;
    uRam00000146d4e68278 = 0;
    _DAT_146d4e68260 = 0;
    uRam00000146d4e68268 = 0;
    _DAT_146d4e68250 = 0;
    uRam00000146d4e68258 = 0;
    _DAT_146d4e68240 = 0;
    uRam00000146d4e68248 = 0;
    _DAT_146d4e68230 = 0;
    uRam00000146d4e68238 = 0;
    _DAT_146d4e682e0 = 0;
    FUN_146d4e400a0(&DAT_146d4e682e8);
    _DAT_146d4e6835c = 0;
    _DAT_146d4e68364 = 0;
    _DAT_146d4e6836c = 0;
    _DAT_146d4e6834c = 0;
    _DAT_146d4e68354 = 0;
    _DAT_146d4e682f4 = 0;
    _DAT_146d4e6833c = 0;
    _DAT_146d4e68344 = 0;
    _DAT_146d4e6832c = 0;
    _DAT_146d4e68334 = 0;
    _DAT_146d4e6831c = 0;
    _DAT_146d4e68324 = 0;
    _DAT_146d4e6830c = 0;
    _DAT_146d4e68314 = 0;
    _DAT_146d4e682fc = 0;
    _DAT_146d4e68304 = 0;
    cVar1 = FUN_146d4e4ca90(param_1);
    uVar5 = 0;
    if (cVar1 != '\0') {
      uVar2 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,param_1,0x31);
      if (((uVar2 & 1) == 0) && (uVar5 = 1, (uVar2 & 2) == 0)) {
        (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,2,0x590008,0x146d4e5f390,0x590008,0x146d4e5f448);
        _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x2726);
        FUN_146d4e407d0(&DAT_146d4e68224,0x146d4e5f4a0,0,0x146d4e641c8);
      }
      else {
        _DAT_146d4e68100 = 5;
        FUN_146d4e407d0(&DAT_146d4e68114,param_1,0,0x146d4e641d8);
        _DAT_146d4e68104 = (undefined4)_DAT_146d4e68375;
        uRam00000146d4e68108 = (undefined4)((ulonglong)_DAT_146d4e68375 >> 0x20);
        _DAT_146d4e68150 = CONCAT44(_DAT_146d4e68154,param_2);
        _DAT_146d4e68130 = 0;
        _DAT_146d4e68138 = param_5;
        _DAT_146d4e68140 = param_6;
        _DAT_146d4e6815c = 0;
        _DAT_146d4e68160 = 0;
        _DAT_146d4e68120 = param_3;
        _DAT_146d4e68128 = param_4;
        _DAT_146d4e68158 = uVar5;
        cVar1 = FUN_146d4e4c920(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_146d4e4ca90(param_1);
          if (cVar1 == '\0') {
            _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x272e);
            uVar3 = 0x146d4e5f510;
          }
          else {
            local_a0 = 0;
            local_98 = 0;
            lVar4 = 0x146d4e68528;
            if (*(longlong *)(param_1 + 4) != 0) {
              lVar4 = param_1;
            }
            FUN_146d4e407d0(&local_a0,lVar4,0,0x146d4e64d48);
            (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_a0,0x31,local_90);
            if ((ulonglong)_DAT_146d4e68158 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4d4c2 */
                    /* WARNING: Treating indirect jump as call */
              uVar3 = (**(code **)((ulonglong)_DAT_146d4e68158 * 8 + 0x146d4e5e4a0))();
              return uVar3;
            }
            (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,0x146d4e60510);
            FUN_146d4e400a0(&local_a0);
            _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x2726);
            uVar3 = 0x146d4e5f588;
          }
          (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,2,1,0x590008,uVar3);
        }
      }
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd,2,0x590008,0x146d4e60610,0x590008,0x146d4e5f390);
    _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x272b);
  }
  return 0;
}



/* Address: 146d4e4d600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_146d4e4d600(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_98;
  undefined8 local_94;
  
  local_98 = 0;
  local_94 = 0;
  if (_DAT_146d4e68514 == 0) {
    cVar1 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,param_1);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      _DAT_146d4e68100 = 0;
      _DAT_146d4e68104 = 0;
      uRam00000146d4e68108 = 0;
      _DAT_146d4e6810c = 0;
      _DAT_146d4e68110 = 0;
      FUN_146d4e400a0(&DAT_146d4e68114);
      _DAT_146d4e68140 = 0;
      _DAT_146d4e68148 = 0;
      _DAT_146d4e68150 = 0;
      _DAT_146d4e68158 = 0;
      _DAT_146d4e6815c = 0;
      _DAT_146d4e68130 = 0;
      _DAT_146d4e68138 = 0;
      _DAT_146d4e68120 = 0;
      _DAT_146d4e68128 = 0;
      _DAT_146d4e68160 = 0;
      FUN_146d4e400a0(&DAT_146d4e68164);
      _DAT_146d4e681e0 = 0;
      uRam00000146d4e681e8 = 0;
      _DAT_146d4e68200 = 0;
      uRam00000146d4e68208 = 0;
      _DAT_146d4e68210 = 0;
      uRam00000146d4e68218 = 0;
      _DAT_146d4e681f0 = 0;
      uRam00000146d4e681f8 = 0;
      _DAT_146d4e681c0 = 0;
      uRam00000146d4e681c8 = 0;
      _DAT_146d4e681d0 = 0;
      uRam00000146d4e681d8 = 0;
      _DAT_146d4e681a0 = 0;
      uRam00000146d4e681a8 = 0;
      _DAT_146d4e681b0 = 0;
      uRam00000146d4e681b8 = 0;
      _DAT_146d4e68180 = 0;
      uRam00000146d4e68188 = 0;
      _DAT_146d4e68190 = 0;
      uRam00000146d4e68198 = 0;
      _DAT_146d4e68220 = 0;
      _DAT_146d4e68170 = 0;
      uRam00000146d4e68178 = 0;
      FUN_146d4e400a0(&DAT_146d4e68224);
      _DAT_146d4e682c0 = 0;
      uRam00000146d4e682c8 = 0;
      _DAT_146d4e682b0 = 0;
      uRam00000146d4e682b8 = 0;
      _DAT_146d4e682d0 = 0;
      uRam00000146d4e682d8 = 0;
      _DAT_146d4e682a0 = 0;
      uRam00000146d4e682a8 = 0;
      _DAT_146d4e68290 = 0;
      uRam00000146d4e68298 = 0;
      _DAT_146d4e68280 = 0;
      uRam00000146d4e68288 = 0;
      _DAT_146d4e68270 = 0;
      uRam00000146d4e68278 = 0;
      _DAT_146d4e68260 = 0;
      uRam00000146d4e68268 = 0;
      _DAT_146d4e68250 = 0;
      uRam00000146d4e68258 = 0;
      _DAT_146d4e68240 = 0;
      uRam00000146d4e68248 = 0;
      _DAT_146d4e68230 = 0;
      uRam00000146d4e68238 = 0;
      _DAT_146d4e682e0 = 0;
      FUN_146d4e400a0(&DAT_146d4e682e8);
      _DAT_146d4e68364 = 0;
      _DAT_146d4e6835c = 0;
      _DAT_146d4e6836c = 0;
      _DAT_146d4e68354 = 0;
      _DAT_146d4e6834c = 0;
      _DAT_146d4e68344 = 0;
      _DAT_146d4e6833c = 0;
      _DAT_146d4e68334 = 0;
      _DAT_146d4e6832c = 0;
      _DAT_146d4e68324 = 0;
      _DAT_146d4e6831c = 0;
      _DAT_146d4e68314 = 0;
      _DAT_146d4e6830c = 0;
      _DAT_146d4e68304 = 0;
      _DAT_146d4e682fc = 0;
      _DAT_146d4e682f4 = 0;
      (*(code *)0x7ff63a1083a0)(0x146d2d8aad8,0);
      FUN_146d4e407d0(&local_98,&DAT_146d4e6853c,1,0x146d4e641f8);
      FUN_146d4e407d0(&DAT_146d4e68114,&local_98,0,0x146d4e64208);
      _DAT_146d4e68100 = 7;
      _DAT_146d4e68104 = (undefined4)_DAT_146d4e68375;
      uRam00000146d4e68108 = (undefined4)((ulonglong)_DAT_146d4e68375 >> 0x20);
      _DAT_146d4e6810c = (undefined4)param_1;
      _DAT_146d4e68110 = (undefined4)((ulonglong)param_1 >> 0x20);
      _DAT_146d4e68130 = 0;
      _DAT_146d4e68158 = 0;
      _DAT_146d4e6815c = 0;
      _DAT_146d4e68160 = 0;
      _DAT_146d4e68128 = param_2;
      _DAT_146d4e68138 = param_3;
      _DAT_146d4e68140 = param_4;
      uVar2 = FUN_146d4e40b20(&DAT_146d4e680e0,&DAT_146d4e68100,&DAT_146d4e681f0);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x146d2d8aad8,0xd,2,0x590008,0x146d4e60610,0x590008,0x146d4e5f5d8);
    uVar2 = 0;
    _DAT_146d4e681f0 = CONCAT44(DAT_146d4e681f0_4,0x272b);
  }
  FUN_146d4e400a0(&local_98);
  return uVar2;
}



/* Address: 146d4e4db20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_146d4e4db20(double param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined4 uVar1;
  undefined8 local_68;
  undefined4 local_60;
  
  local_60 = 0;
  local_68 = 0;
  if (param_1 <= 0.0) {
    uVar1 = 0;
    _DAT_146d4e681f0 = 0x271e;
  }
  else {
    FUN_146d4e407d0(&local_68,0x146d4e68528,0,0x146d4e64238);
    uVar1 = FUN_146d4e4ce90(&local_68,4,param_1,param_2,param_3,param_4,param_5);
  }
  FUN_146d4e400a0(&local_68);
  return uVar1;
}



/* Address: 146d4e4dc20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_146d4e4dc20(double param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined4 uVar1;
  undefined8 local_68;
  undefined4 local_60;
  
  local_60 = 0;
  local_68 = 0;
  if (param_1 <= 0.0) {
    uVar1 = 0;
    _DAT_146d4e681f0 = 0x271e;
  }
  else {
    FUN_146d4e407d0(&local_68,0x146d4e68528,0,0x146d4e64248);
    uVar1 = FUN_146d4e4ce90(&local_68,5,param_1,param_2,param_3,param_4,param_5);
  }
  FUN_146d4e400a0(&local_68);
  return uVar1;
}



/* Address: 146d4e4dd20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e4dd20(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_146d4e407d0(param_2,0x146d4e5e910,0,0x146d4e64418);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x146d4e68528;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_146d4e407d0(&local_98,piVar12,0,0x146d4e64428);
  (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x146d2d8aad8,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4df00 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x146d4e5e4c0))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x146d2d8aad8,(longlong)*param_3,0x52,&local_108);
  FUN_146d4e407d0(&local_f8,0x146d4e5fbe0,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_146d4e4e7eb;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_146d4e4e7eb;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_146d4e40100(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1e04cf000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf04a0000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf04a5000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x150470000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x150489000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x15043c000101f9);
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x150457000101f9);
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
      if (uVar13 == uVar14) goto LAB_146d4e4fac2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_146d4e4fac2:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_146d4e4e7eb:
  uVar9 = local_e8;
  FUN_146d4e407d0(local_e8,&local_f8,0,0x146d4e649e8);
  FUN_146d4e407d0(&local_68,uVar9,0,0x146d4e649f8);
  FUN_146d4e400a0(&local_98);
  FUN_146d4e400a0(&local_e0);
  FUN_146d4e400a0(&local_88);
  FUN_146d4e400a0(&local_78);
  FUN_146d4e400a0(&local_c0);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_68,1,0x146d4e64a08);
  FUN_146d4e400a0(&local_68);
  FUN_146d4e400a0(&local_108);
  FUN_146d4e400a0(&local_f8);
  FUN_146d4e400a0(&local_d0);
  FUN_146d4e400a0(&local_b0);
  return;
}



/* Address: 146d4e4fde0 */

void FUN_146d4e4fde0(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x0146d4e4fe43 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x146d4e5e530))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x146d2d8aad8,(ulonglong)param_2,0x53,&local_50);
  FUN_146d4e407d0(&local_60,0x146d4e5f108,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_146d4e5003d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_146d4e5003d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_146d4e40100(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2203c7000101f9);
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
      if (uVar11 == uVar13) goto LAB_146d4e50032;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_146d4e50032:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_146d4e5003d:
  FUN_146d4e407d0(param_1,&local_60,0,0x146d4e64348);
  FUN_146d4e407d0(&local_40,param_1,0,0x146d4e64358);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_40,1,0x146d4e64368);
  FUN_146d4e400a0(&local_40);
  FUN_146d4e400a0(&local_50);
  FUN_146d4e400a0(&local_60);
  return;
}



/* Address: 146d4e500e0 */

void FUN_146d4e500e0(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_146d4e407d0(&local_78,&DAT_146d4e6853c,1,0x146d4e64378);
    FUN_146d4e407d0(&local_88,&local_78,0,0x146d4e64388);
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_3,param_4);
    FUN_146d4e407d0(&local_78,&DAT_146d4e6853c,1,0x146d4e64398);
    FUN_146d4e407d0(&local_98,&local_78,0,0x146d4e643a8);
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0xd8,3,0x590008,0x146d4e5f200,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x146d4e643c8;
    uVar1 = 0x146d4e643b8;
  }
  else {
    uVar2 = 0x146d4e643e8;
    uVar1 = 0x146d4e643d8;
  }
  FUN_146d4e407d0(&local_78,&DAT_146d4e6853c,1,uVar1);
  FUN_146d4e407d0(param_1,&local_78,0,uVar2);
  FUN_146d4e407d0(&local_68,param_1,0,0x146d4e643f8);
  FUN_146d4e400a0(&local_98);
  FUN_146d4e400a0(&local_88);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_68,1,0x146d4e64408);
  FUN_146d4e400a0(&local_68);
  FUN_146d4e400a0(&local_78);
  return;
}



/* Address: 146d4e50320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e50320(longlong param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  longlong lVar17;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  longlong local_78;
  ulonglong local_70;
  longlong local_68;
  int local_60;
  uint local_5c;
  int local_58;
  
  local_98 = 0;
  local_a8 = 0;
  local_88 = 0;
  local_d8 = 0;
  local_c8 = 0;
  local_e8 = 0;
  local_b8 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_84 = 0;
  local_d4 = 0;
  local_c4 = 0;
  local_e4 = 0;
  local_b4 = 0;
  if ((DAT_146d4e686f0 == '\0') || (param_1 < 1)) {
    FUN_146d4e407d0(&local_c8,0x146d4e5e910,0,0x146d4e65098);
    goto LAB_146d4e5078b;
  }
  local_e4 = 0;
  FUN_146d4e59d80(param_1);
  FUN_146d4e407d0(&local_d8,&DAT_146d4e6853c,1,0x146d4e650a8);
  FUN_146d4e407d0(&local_e8,&local_d8,0,0x146d4e650b8);
  uVar10 = _DAT_146d4e686f8;
  if (((local_e4 == 0) || (local_e4 == 0xc)) || (*(int *)(local_e4 + -4) < 1)) {
    if ((int)_DAT_146d4e686f8 < 1) {
      uVar15 = 0x146d4e650d8;
    }
    else {
      uVar11 = (ulonglong)_DAT_146d4e686f8;
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,param_1,&local_60);
      uVar8 = local_60 - (uint)(local_5c < 3);
      uVar9 = local_5c + 0xc;
      if (2 < local_5c) {
        uVar9 = local_5c;
      }
      uVar9 = ((uVar9 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
              ((uVar8 * 0x16d + local_58 + (uVar8 >> 2)) - uVar8 / 100) + uVar8 / 400;
      if (uVar9 != 0) {
        lVar14 = 0x1518000000000;
        uVar8 = (int)(uVar10 + 0x17) / 0x18;
        uVar12 = 1;
        if (1 < (int)uVar8) {
          uVar12 = (ulonglong)uVar8;
        }
        local_68 = (longlong)(int)(uVar10 * 0xe10);
        local_78 = param_1;
        local_70 = uVar11;
LAB_146d4e505bf:
        local_b8 = 0;
        local_b4 = 0;
        lVar17 = (lVar14 >> 0x20) + (ulonglong)uVar9 * 0x15180;
        FUN_146d4e59d80(lVar17);
        FUN_146d4e407d0(&local_d8,&DAT_146d4e6853c,1,0x146d4e650f8);
        FUN_146d4e407d0(&local_b8,&local_d8,0,0x146d4e65108);
        if (((local_b4 == 0) || (local_b4 == 0xc)) ||
           ((*(int *)(local_b4 + -4) == 0 ||
            ((lVar17 <= local_78 || (local_78 < lVar17 - local_68)))))) goto LAB_146d4e505a0;
        uVar10 = 0;
        FUN_146d4e407d0(&local_d8,&local_b8,0,0x146d4e65118);
        uVar9 = _DAT_146d4e60f98;
        uVar11 = (ulonglong)_DAT_146d4e60f98;
        if ((uVar11 == 0) && (local_d4 != 0)) goto LAB_146d4e5085d;
        if (local_d4 != 0) {
          uVar10 = *(uint *)(local_d4 + -4);
        }
        uVar13 = _DAT_146d4e60f98 + uVar10;
        uVar8 = 0x104;
        if ((0x103 < uVar13) &&
           ((0x7ffffffd < uVar13 || (uVar8 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar8)))) {
          uVar8 = 0x7ffffffe;
        }
        cVar7 = FUN_146d4e40100(&local_d8,uVar8);
        if (cVar7 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x240618000001f9);
          goto LAB_146d4e50b04;
        }
        if (uVar11 != 0) {
          lVar14 = local_d4 + (ulonglong)uVar10 * 2;
          if (uVar9 < 0x10) {
            uVar12 = 0;
            goto LAB_146d4e50840;
          }
          if (lVar14 - 0x146d4e60f9cU < 0x20) {
            uVar12 = 0;
            goto LAB_146d4e50840;
          }
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar9 & 0xfffffff8);
          do {
            uVar4 = *(undefined4 *)(uVar16 + 0x146d4e60fa0);
            uVar5 = *(undefined4 *)(uVar16 + 0x146d4e60fa4);
            uVar6 = *(undefined4 *)(uVar16 + 0x146d4e60fa8);
            puVar2 = (undefined4 *)(lVar14 + uVar16);
            *puVar2 = *(undefined4 *)(&DAT_146d4e60f9c + uVar16);
            puVar2[1] = uVar4;
            puVar2[2] = uVar5;
            puVar2[3] = uVar6;
            uVar16 = uVar16 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar16);
          for (; uVar12 != uVar11; uVar12 = uVar12 + 1) {
LAB_146d4e50840:
            *(undefined2 *)(lVar14 + uVar12 * 2) = *(undefined2 *)(&DAT_146d4e60f9c + uVar12 * 2);
          }
        }
        *(uint *)(local_d4 + -4) = uVar13;
        *(undefined2 *)(local_d4 + (ulonglong)uVar13 * 2) = 0;
LAB_146d4e5085d:
        (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,local_70 & 0xffffffff,0,0x20);
        FUN_146d4e407d0(&local_88,&DAT_146d4e6853c,1,0x146d4e65128);
        FUN_146d4e407d0(&local_a8,&local_d8);
        lVar14 = local_84;
        if (local_84 != 0) {
          uVar10 = *(uint *)(local_84 + -4);
          uVar11 = (ulonglong)uVar10;
          if ((uVar11 != 0) || (local_a4 == 0)) {
            if (local_a4 == 0) {
              uVar9 = 0;
            }
            else {
              uVar9 = *(uint *)(local_a4 + -4);
            }
            cVar7 = FUN_146d4e40100(&local_a8);
            if (cVar7 == '\0') goto LAB_146d4e50b24;
            if (uVar11 != 0) {
              lVar17 = local_a4 + (ulonglong)uVar9 * 2;
              if (uVar10 < 0x10) {
                uVar12 = 0;
              }
              else if ((ulonglong)(lVar17 - lVar14) < 0x20) {
                uVar12 = 0;
              }
              else {
                uVar16 = 0;
                uVar12 = (ulonglong)(uVar10 & 0xfffffff8);
                do {
                  puVar2 = (undefined4 *)(lVar14 + uVar16);
                  uVar4 = puVar2[1];
                  uVar5 = puVar2[2];
                  uVar6 = puVar2[3];
                  puVar1 = (undefined4 *)(lVar17 + uVar16);
                  *puVar1 = *puVar2;
                  puVar1[1] = uVar4;
                  puVar1[2] = uVar5;
                  puVar1[3] = uVar6;
                  uVar16 = uVar16 + 0x10;
                } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar16);
                if (uVar12 == uVar11) goto LAB_146d4e509a0;
              }
              do {
                *(undefined2 *)(lVar17 + uVar12 * 2) = *(undefined2 *)(lVar14 + uVar12 * 2);
                uVar12 = uVar12 + 1;
              } while (uVar11 != uVar12);
            }
LAB_146d4e509a0:
            *(uint *)(local_a4 + -4) = uVar10 + uVar9;
            *(undefined2 *)(local_a4 + (ulonglong)(uVar10 + uVar9) * 2) = 0;
          }
        }
        uVar10 = 0;
        FUN_146d4e407d0(&local_98,&local_a8,0,0x146d4e65148);
        uVar9 = _DAT_146d4e60fc8;
        uVar11 = (ulonglong)_DAT_146d4e60fc8;
        if ((uVar11 != 0) || (local_94 == 0)) {
          if (local_94 != 0) {
            uVar10 = *(uint *)(local_94 + -4);
          }
          uVar13 = _DAT_146d4e60fc8 + uVar10;
          uVar8 = 0x104;
          if ((0x103 < uVar13) &&
             ((0x7ffffffd < uVar13 || (uVar8 = (uVar13 >> 2) + uVar13, 0x7ffffffd < uVar8)))) {
            uVar8 = 0x7ffffffe;
          }
          cVar7 = FUN_146d4e40100(&local_98,uVar8);
          if (cVar7 == '\0') {
LAB_146d4e50b04:
            (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x550618000001f9);
LAB_146d4e50b24:
            (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x350618000001f9);
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          if (uVar11 != 0) {
            lVar14 = local_94 + (ulonglong)uVar10 * 2;
            if (uVar9 < 0x10) {
              uVar12 = 0;
            }
            else if (lVar14 - 0x146d4e60fccU < 0x20) {
              uVar12 = 0;
            }
            else {
              uVar16 = 0;
              uVar12 = (ulonglong)(uVar9 & 0xfffffff8);
              do {
                uVar4 = *(undefined4 *)(uVar16 + 0x146d4e60fd0);
                uVar5 = *(undefined4 *)(uVar16 + 0x146d4e60fd4);
                uVar6 = *(undefined4 *)(uVar16 + 0x146d4e60fd8);
                puVar2 = (undefined4 *)(lVar14 + uVar16);
                *puVar2 = *(undefined4 *)(&DAT_146d4e60fcc + uVar16);
                puVar2[1] = uVar4;
                puVar2[2] = uVar5;
                puVar2[3] = uVar6;
                uVar16 = uVar16 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar16);
              if (uVar12 == uVar11) goto LAB_146d4e50ab2;
            }
            do {
              *(undefined2 *)(lVar14 + uVar12 * 2) = *(undefined2 *)(&DAT_146d4e60fcc + uVar12 * 2);
              uVar12 = uVar12 + 1;
            } while (uVar11 != uVar12);
          }
LAB_146d4e50ab2:
          *(uint *)(local_94 + -4) = uVar13;
          *(undefined2 *)(local_94 + (ulonglong)uVar13 * 2) = 0;
        }
        FUN_146d4e407d0(&local_c8,&local_98,0,0x146d4e65158);
        FUN_146d4e400a0(&local_b8);
        goto LAB_146d4e50788;
      }
      uVar15 = 0x146d4e650e8;
    }
    goto LAB_146d4e50780;
  }
  FUN_146d4e407d0(&local_c8,&local_e8,0,0x146d4e650c8);
LAB_146d4e50788:
  FUN_146d4e400a0(&local_e8);
LAB_146d4e5078b:
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_c8,1,0x146d4e65178);
  FUN_146d4e400a0(&local_c8);
  FUN_146d4e400a0(&local_d8);
  FUN_146d4e400a0(&local_88);
  FUN_146d4e400a0(&local_a8);
  FUN_146d4e400a0(&local_98);
  return;
LAB_146d4e505a0:
  FUN_146d4e400a0(&local_b8);
  lVar14 = lVar14 + 0x1518000000000;
  uVar12 = uVar12 - 1;
  if (uVar12 == 0) goto LAB_146d4e5073c;
  goto LAB_146d4e505bf;
LAB_146d4e5073c:
  uVar15 = 0x146d4e65168;
LAB_146d4e50780:
  FUN_146d4e407d0(&local_c8,0x146d4e5e910,0,uVar15);
  goto LAB_146d4e50788;
}



/* Address: 146d4e50b50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e50b50(void)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  char cVar4;
  ulonglong uVar5;
  byte bVar6;
  uint uVar7;
  undefined8 unaff_RBX;
  undefined7 uVar8;
  double dVar9;
  double dVar10;
  undefined1 local_50 [8];
  double local_48;
  double local_40;
  
  uVar3 = _DAT_146d4e68680;
  uVar8 = (undefined7)((ulonglong)unaff_RBX >> 8);
  uVar5 = CONCAT71(uVar8,1);
  if ((((DAT_146d4e68678 != '\0') && (0 < (int)_DAT_146d4e68680)) &&
      (cVar4 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,0x146d4e5e890,local_50), cVar4 != '\0')) &&
     (0.0 < _DAT_146d4e68518)) {
    if ((_DAT_146d4e68518 == 0.0) && (!NAN(_DAT_146d4e68518))) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2f0911000001f7);
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    dVar9 = (local_40 - local_48) / _DAT_146d4e68518;
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
        bVar6 = (byte)lVar1;
        if (((longlong)dVar9 << (bVar6 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar10 = (double)((0x8000000000000U >> (bVar6 & 0x3f)) + (longlong)dVar9 &
                           -0x10000000000000 >> (bVar6 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar10 = dVar9 + dVar9;
    }
    if (0 < (int)dVar10) {
      uVar5 = CONCAT71(uVar8,(uint)(int)dVar10 <= uVar3);
    }
  }
  return uVar5 & 0xffffffff;
}



/* Address: 146d4e50c90 */

void FUN_146d4e50c90(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2f0911000001f7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 146d4e50cc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e50cc0(longlong param_1,int param_2,longlong param_3,longlong param_4,longlong param_5
                    ,longlong param_6)

{
  double dVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  double dVar6;
  double dVar7;
  ushort uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ushort uVar13;
  ulonglong uVar14;
  double *pdVar15;
  uint uVar16;
  undefined4 uVar17;
  ulonglong uVar18;
  double *pdVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
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
  ulonglong local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined4 local_70;
  
  local_a0 = 0x800010058;
  local_d8 = 0x800010058;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  uStack_84 = 0;
  local_80 = 0;
  uStack_7c = 0;
  local_78 = 0;
  local_70 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  uStack_bc = 0;
  local_b8 = 0;
  uStack_b4 = 0;
  local_b0 = 0;
  local_a8 = 0;
  (*(code *)0x7ff63a0da0e0)(0x146d2d8aad8,&local_a0,param_2,0);
  (*(code *)0x7ff63a0da0e0)(0x146d2d8aad8,&local_d8,param_2,0);
  uVar13 = local_a0._2_2_;
  if ((local_a0 & 0xf0000) != 0) {
    uVar13 = local_a0._2_2_ | 0x10;
    local_a0 = local_a0 | 0x100000;
  }
  uVar8 = local_d8._2_2_;
  if ((local_d8 & 0xf0000) != 0) {
    uVar8 = local_d8._2_2_ | 0x10;
    local_d8 = local_d8 | 0x100000;
  }
  pdVar15 = (double *)&DAT_146d4e68008;
  pdVar19 = (double *)&DAT_146d4e68010;
  uVar16 = param_2 - 1;
  uVar18 = (ulonglong)uVar16;
  if (DAT_146d4e68000 != '\0') {
    pdVar15 = (double *)&DAT_146d4e68078;
  }
  if (DAT_146d4e68000 != '\0') {
    pdVar19 = (double *)&DAT_146d4e68080;
  }
  if (uVar16 < *(uint *)(param_1 + 8)) {
    if ((uint)local_d0 <= uVar16) goto LAB_146d4e5160a;
    lVar3 = *(longlong *)(param_1 + 0x1c);
    dVar23 = *pdVar15 * *pdVar19;
    uVar20 = ~uVar18;
    uVar9 = *(uint *)(param_1 + 8) + uVar20;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      uVar9 = uVar18;
    }
    lVar11 = uVar9 * 0x3c;
    uVar9 = (local_d0 & 0xffffffff) + uVar20;
    if ((uVar8 & 0x10) == 0) {
      uVar9 = uVar18;
    }
    lVar5 = CONCAT44(local_b8,uStack_bc);
    *(double *)(lVar5 + uVar9 * 8) =
         (*(double *)(lVar3 + 8 + lVar11) + *(double *)(lVar3 + 0x10 + lVar11) +
          *(double *)(lVar3 + 0x18 + lVar11) + *(double *)(lVar3 + 0x20 + lVar11)) *
         _DAT_146d4e5e570;
    if (*(uint *)(param_1 + 8) <= uVar16) goto LAB_146d4e5162a;
    if ((uint)local_98 <= uVar16) goto LAB_146d4e5164a;
    uVar22 = *(uint *)(param_1 + 8) + uVar20;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      uVar22 = uVar18;
    }
    uVar10 = (local_98 & 0xffffffff) + uVar20;
    if ((uVar13 & 0x10) == 0) {
      uVar10 = uVar18;
    }
    *(double *)(CONCAT44(local_80,uStack_84) + uVar10 * 8) =
         (*(double *)(*(longlong *)(param_1 + 0x1c) + 8 + uVar22 * 0x3c) +
         *(double *)(*(longlong *)(param_1 + 0x1c) + 0x20 + uVar22 * 0x3c)) * _DAT_146d4e5e578;
    if (*(uint *)(param_3 + 8) <= uVar16) goto LAB_146d4e5166a;
    if (*(uint *)(param_5 + 8) <= uVar16) goto LAB_146d4e5168a;
    uVar22 = *(uint *)(param_3 + 8) + uVar20;
    if ((*(ushort *)(param_3 + 2) & 0x10) == 0) {
      uVar22 = uVar18;
    }
    uVar10 = *(uint *)(param_5 + 8) + uVar20;
    if ((*(ushort *)(param_5 + 2) & 0x10) == 0) {
      uVar10 = uVar18;
    }
    *(double *)(*(longlong *)(param_5 + 0x1c) + uVar10 * 8) =
         *(double *)(lVar5 + uVar9 * 8) -
         *(double *)(*(longlong *)(param_3 + 0x1c) + uVar22 * 8) * dVar23;
    if (*(uint *)(param_3 + 8) <= uVar16) goto LAB_146d4e516aa;
    if (uVar16 < *(uint *)(param_6 + 8)) {
      uVar22 = *(uint *)(param_3 + 8) + uVar20;
      if ((*(ushort *)(param_3 + 2) & 0x10) == 0) {
        uVar22 = uVar18;
      }
      uVar10 = *(uint *)(param_6 + 8) + uVar20;
      if ((*(ushort *)(param_6 + 2) & 0x10) == 0) {
        uVar10 = uVar18;
      }
      *(double *)(*(longlong *)(param_6 + 0x1c) + uVar10 * 8) =
           *(double *)(*(longlong *)(param_3 + 0x1c) + uVar22 * 8) * dVar23 +
           *(double *)(lVar5 + uVar9 * 8);
      dVar7 = _DAT_146d4e5e578;
      dVar6 = _DAT_146d4e5e570;
      if (*(uint *)(param_4 + 8) <= uVar16) goto LAB_146d4e516ea;
      uVar9 = *(uint *)(param_4 + 8) + uVar20;
      if ((*(ushort *)(param_4 + 2) & 0x10) == 0) {
        uVar9 = uVar18;
      }
      param_2 = param_2 + -2;
      *(undefined4 *)(*(longlong *)(param_4 + 0x1c) + uVar9 * 4) = 1;
      while( true ) {
        uVar18 = (ulonglong)param_2;
        if (*(uint *)(param_1 + 8) <= uVar18) break;
        if ((local_d0 & 0xffffffff) <= uVar18) {
LAB_146d4e514ea:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xe02ff000001f6);
          break;
        }
        lVar3 = *(longlong *)(param_1 + 0x1c);
        uVar22 = ~uVar18;
        uVar20 = (ulonglong)(param_2 + 1);
        uVar9 = *(uint *)(param_1 + 8) + uVar22;
        if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
          uVar9 = uVar18;
        }
        lVar11 = uVar9 * 0x3c;
        uVar9 = (local_d0 & 0xffffffff) + uVar22;
        if ((uVar8 & 0x10) == 0) {
          uVar9 = uVar18;
        }
        *(double *)(CONCAT44(local_b8,uStack_bc) + uVar9 * 8) =
             (*(double *)(lVar3 + 8 + lVar11) + *(double *)(lVar3 + 0x10 + lVar11) +
              *(double *)(lVar3 + 0x18 + lVar11) + *(double *)(lVar3 + 0x20 + lVar11)) * dVar6;
        uVar9 = local_98 & 0xffffffff;
        if (uVar9 <= uVar20) {
LAB_146d4e514ca:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1c0300000001f6);
          goto LAB_146d4e514ea;
        }
        uVar10 = local_d0 & 0xffffffff;
        if (uVar10 <= uVar20) {
LAB_146d4e514aa:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2d0300000001f6);
          goto LAB_146d4e514ca;
        }
        if (uVar9 <= uVar18) {
LAB_146d4e5148a:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xd0300000001f6);
          goto LAB_146d4e514aa;
        }
        uVar21 = ~uVar20;
        uVar12 = uVar10 + uVar21;
        if ((local_d8 & 0x100000) == 0) {
          uVar12 = uVar20;
        }
        lVar3 = CONCAT44(local_b8,uStack_bc);
        uVar14 = uVar9 + uVar22;
        uVar9 = uVar9 + uVar21;
        if ((local_a0 & 0x100000) == 0) {
          uVar14 = uVar18;
          uVar9 = uVar20;
        }
        *(double *)(CONCAT44(local_80,uStack_84) + uVar14 * 8) =
             (*(double *)(CONCAT44(local_80,uStack_84) + uVar9 * 8) +
             *(double *)(lVar3 + uVar12 * 8)) * dVar7;
        if (uVar10 <= uVar18) {
LAB_146d4e5146a:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x200302000001f6);
          goto LAB_146d4e5148a;
        }
        if (*(uint *)(param_3 + 8) <= uVar18) {
LAB_146d4e5144a:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x420302000001f6);
          goto LAB_146d4e5146a;
        }
        uVar9 = uVar10 + uVar22;
        if ((local_d8 & 0x100000) == 0) {
          uVar9 = uVar18;
        }
        uVar14 = (ulonglong)*(uint *)(param_5 + 8);
        uVar10 = *(uint *)(param_3 + 8) + uVar22;
        if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
          uVar10 = uVar18;
        }
        if (uVar14 <= uVar20) {
LAB_146d4e5142a:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x210305000001f6);
          goto LAB_146d4e5144a;
        }
        dVar24 = *(double *)(lVar3 + uVar9 * 8);
        dVar25 = *(double *)(*(longlong *)(param_3 + 0x1c) + uVar10 * 8) * dVar23;
        uVar10 = uVar14 + uVar21;
        if ((*(ushort *)(param_5 + 2) & 0x10) == 0) {
          uVar10 = uVar20;
        }
        dVar26 = dVar24 - dVar25;
        dVar1 = *(double *)(*(longlong *)(param_5 + 0x1c) + uVar10 * 8);
        if (*(double *)(lVar3 + uVar12 * 8) <= dVar1) {
          if (uVar18 < uVar14) goto LAB_146d4e511dc;
          goto LAB_146d4e5154a;
        }
        if (uVar14 <= uVar18) goto LAB_146d4e5158a;
        if (dVar26 <= dVar1) {
          dVar26 = dVar1;
        }
LAB_146d4e511dc:
        uVar10 = uVar14 + uVar22;
        if ((*(ushort *)(param_5 + 2) & 0x10) == 0) {
          uVar10 = uVar18;
        }
        *(double *)(*(longlong *)(param_5 + 0x1c) + uVar10 * 8) = dVar26;
        uVar10 = (ulonglong)*(uint *)(param_6 + 8);
        if (uVar10 <= uVar20) {
LAB_146d4e5140a:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x21030a000001f6);
          goto LAB_146d4e5142a;
        }
        dVar24 = dVar24 + dVar25;
        uVar14 = uVar10 + uVar21;
        if ((*(ushort *)(param_6 + 2) & 0x10) == 0) {
          uVar14 = uVar20;
        }
        dVar25 = *(double *)(*(longlong *)(param_6 + 0x1c) + uVar14 * 8);
        pdVar15 = (double *)(lVar3 + uVar12 * 8);
        if (dVar25 < *pdVar15 || dVar25 == *pdVar15) {
          if (uVar18 < uVar10) goto LAB_146d4e51239;
          goto LAB_146d4e5152a;
        }
        if (uVar10 <= uVar18) goto LAB_146d4e5156a;
        if (dVar25 <= dVar24) {
          dVar24 = dVar25;
        }
LAB_146d4e51239:
        uVar10 = uVar10 + uVar22;
        if ((*(ushort *)(param_6 + 2) & 0x10) == 0) {
          uVar10 = uVar18;
        }
        *(double *)(*(longlong *)(param_6 + 0x1c) + uVar10 * 8) = dVar24;
        uVar10 = (ulonglong)*(uint *)(param_4 + 8);
        if (uVar10 <= uVar20) {
LAB_146d4e513ea:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x19030f000001f6);
          goto LAB_146d4e5140a;
        }
        if (uVar10 <= uVar18) {
LAB_146d4e513ca:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xc030f000001f6);
          goto LAB_146d4e513ea;
        }
        uVar12 = uVar10 + uVar22;
        uVar10 = uVar10 + uVar21;
        if ((*(ushort *)(param_4 + 2) & 0x10) == 0) {
          uVar12 = uVar18;
          uVar10 = uVar20;
        }
        *(undefined4 *)(*(longlong *)(param_4 + 0x1c) + uVar12 * 4) =
             *(undefined4 *)(*(longlong *)(param_4 + 0x1c) + uVar10 * 4);
        if (*(uint *)(param_4 + 8) <= uVar18) {
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf0310000001f6);
          goto LAB_146d4e513ca;
        }
        uVar22 = *(uint *)(param_4 + 8) + uVar22;
        if ((*(byte *)(param_4 + 2) & 0x10) == 0) {
          uVar22 = uVar18;
        }
        iVar2 = *(int *)(*(longlong *)(param_4 + 0x1c) + uVar22 * 4);
        if (iVar2 == 1) {
          if (uVar20 < *(uint *)(param_5 + 8)) {
            uVar18 = *(uint *)(param_5 + 8) + uVar21;
            if ((*(byte *)(param_5 + 2) & 0x10) == 0) {
              uVar18 = uVar20;
            }
            dVar24 = *(double *)(*(longlong *)(param_5 + 0x1c) + uVar18 * 8);
            uVar17 = 0xffffffff;
            pdVar15 = (double *)(lVar3 + uVar9 * 8);
            if (*pdVar15 <= dVar24 && dVar24 != *pdVar15) {
LAB_146d4e51030:
              *(undefined4 *)(*(longlong *)(param_4 + 0x1c) + uVar22 * 4) = uVar17;
            }
            goto LAB_146d4e51034;
          }
          goto LAB_146d4e515ca;
        }
        if (iVar2 == -1) {
          if (uVar20 < *(uint *)(param_6 + 8)) {
            dVar24 = *(double *)(lVar3 + uVar9 * 8);
            uVar17 = 1;
            uVar18 = *(uint *)(param_6 + 8) + uVar21;
            if ((*(byte *)(param_6 + 2) & 0x10) == 0) {
              uVar18 = uVar20;
            }
            pdVar15 = (double *)(*(longlong *)(param_6 + 0x1c) + uVar18 * 8);
            if (*pdVar15 <= dVar24 && dVar24 != *pdVar15) goto LAB_146d4e51030;
            goto LAB_146d4e51034;
          }
          goto LAB_146d4e515aa;
        }
LAB_146d4e51034:
        param_2 = param_2 + -1;
        uVar8 = local_d8._2_2_;
        if (param_2 < 0) {
          (*(code *)0x7ff63a0d9d20)(0x146d2d8aad8,&local_d8);
          (*(code *)0x7ff63a0d9d20)(0x146d2d8aad8,&local_a0);
          return;
        }
      }
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1a02ff000001f6);
LAB_146d4e5152a:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xe030d000001f6);
LAB_146d4e5154a:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xe0308000001f6);
LAB_146d4e5156a:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xe030b000001f6);
LAB_146d4e5158a:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xe0306000001f6);
LAB_146d4e515aa:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2f0310000001f6);
LAB_146d4e515ca:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x330312000001f6);
      goto LAB_146d4e515ea;
    }
  }
  else {
LAB_146d4e515ea:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1f02f6000001f6);
LAB_146d4e5160a:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xb02f6000001f6);
LAB_146d4e5162a:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1e02f7000001f6);
LAB_146d4e5164a:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xa02f7000001f6);
LAB_146d4e5166a:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x4702f9000001f6);
LAB_146d4e5168a:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x802f9000001f6);
LAB_146d4e516aa:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x4702fa000001f6);
  }
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x802fa000001f6);
LAB_146d4e516ea:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x902fb000001f6);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



/* Address: 146d4e51710 */

void FUN_146d4e51710(undefined8 *param_1,longlong param_2,int param_3,longlong param_4,char param_5,
                    int param_6)

{
  double *pdVar1;
  undefined8 *puVar2;
  double dVar3;
  undefined8 uVar4;
  ushort uVar5;
  longlong lVar6;
  undefined8 uVar7;
  bool bVar8;
  code *pcVar9;
  char cVar10;
  uint uVar11;
  ulonglong uVar12;
  int iVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  int iVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  
  uVar11 = 0xb;
  uVar15 = 0;
  if (DAT_146d4e68072 != '\0') {
    uVar15 = uVar11;
  }
  if (DAT_146d4e68003 == '\0') {
    uVar11 = 0;
  }
  iVar20 = 0;
  if (DAT_146d4e68073 != '\0') {
    iVar20 = 4000;
  }
  iVar13 = 0;
  if (DAT_146d4e68004 != '\0') {
    iVar13 = 4000;
  }
  if (DAT_146d4e68000 != '\0') {
    iVar13 = iVar20;
    uVar11 = uVar15;
  }
  iVar20 = ~uVar11 + param_3;
  if (iVar13 <= (int)(~uVar11 + param_3)) {
    iVar20 = iVar13;
  }
  if ((int)uVar11 < iVar20) {
    uVar15 = uVar11 + 1;
    if (param_5 == '\0') {
      uVar16 = (ulonglong)uVar11;
      uVar17 = ~uVar16;
      do {
        if (*(uint *)(param_4 + 8) <= uVar15) goto LAB_146d4e51a88;
        uVar22 = (ulonglong)uVar15;
        uVar23 = ~uVar22;
        uVar12 = *(uint *)(param_4 + 8) + uVar23;
        if ((*(byte *)(param_4 + 2) & 0x10) == 0) {
          uVar12 = uVar22;
        }
        if ((*(int *)(*(longlong *)(param_4 + 0x1c) + uVar12 * 4) == param_6) &&
           (cVar10 = FUN_146d4e53590(param_2,param_3,uVar15), cVar10 != '\0')) {
          if (uVar15 < 2) goto LAB_146d4e5199e;
          uVar11 = *(uint *)(param_2 + 8);
          uVar12 = (ulonglong)uVar11;
          if (uVar11 <= uVar15) goto LAB_146d4e51aee;
          uVar14 = uVar17 + uVar12;
          uVar19 = uVar16;
          while( true ) {
            if (uVar12 <= uVar19) goto LAB_146d4e51b14;
            uVar21 = uVar14;
            uVar18 = ~uVar22 + uVar12;
            if ((*(byte *)(param_2 + 2) & 0x10) == 0) {
              uVar21 = uVar19;
              uVar18 = uVar22;
            }
            dVar3 = *(double *)(*(longlong *)(param_2 + 0x1c) + 0x18 + uVar18 * 0x3c);
            pdVar1 = (double *)(*(longlong *)(param_2 + 0x1c) + 0x20 + uVar21 * 0x3c);
            if (*pdVar1 <= dVar3 && dVar3 != *pdVar1) break;
            uVar18 = uVar19 + 1;
            uVar14 = uVar14 + 1;
            uVar19 = uVar19 - 1;
            if (uVar18 < 3) goto LAB_146d4e5199e;
          }
        }
        uVar16 = uVar16 + 1;
        uVar17 = uVar17 - 1;
        bVar8 = (int)uVar15 < iVar20;
        uVar15 = uVar15 + 1;
      } while (bVar8);
    }
    else {
      uVar17 = (ulonglong)uVar11;
      uVar16 = ~uVar17;
      do {
        if (*(uint *)(param_4 + 8) <= uVar15) goto LAB_146d4e51a88;
        uVar22 = (ulonglong)uVar15;
        uVar23 = ~uVar22;
        uVar12 = *(uint *)(param_4 + 8) + uVar23;
        if ((*(byte *)(param_4 + 2) & 0x10) == 0) {
          uVar12 = uVar22;
        }
        if ((*(int *)(*(longlong *)(param_4 + 0x1c) + uVar12 * 4) == param_6) &&
           (cVar10 = FUN_146d4e533c0(param_2,param_3,uVar15), cVar10 != '\0')) {
          if (uVar15 < 2) goto LAB_146d4e5199e;
          uVar11 = *(uint *)(param_2 + 8);
          uVar12 = (ulonglong)uVar11;
          if (uVar11 <= uVar15) goto LAB_146d4e51aa8;
          uVar14 = uVar16 + uVar12;
          uVar19 = uVar17;
          while( true ) {
            if (uVar12 <= uVar19) goto LAB_146d4e51ace;
            uVar21 = ~uVar22 + uVar12;
            uVar18 = uVar14;
            if ((*(byte *)(param_2 + 2) & 0x10) == 0) {
              uVar21 = uVar22;
              uVar18 = uVar19;
            }
            dVar3 = *(double *)(*(longlong *)(param_2 + 0x1c) + 0x20 + uVar18 * 0x3c);
            pdVar1 = (double *)(*(longlong *)(param_2 + 0x1c) + 0x10 + uVar21 * 0x3c);
            if (*pdVar1 <= dVar3 && dVar3 != *pdVar1) break;
            uVar18 = uVar19 + 1;
            uVar14 = uVar14 + 1;
            uVar19 = uVar19 - 1;
            if (uVar18 < 3) goto LAB_146d4e5199e;
          }
        }
        uVar17 = uVar17 + 1;
        uVar16 = uVar16 - 1;
        bVar8 = (int)uVar15 < iVar20;
        uVar15 = uVar15 + 1;
      } while (bVar8);
    }
  }
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined4 *)((longlong)param_1 + 0x11) = 0xffffffff;
  return;
LAB_146d4e5199e:
  uVar16 = (ulonglong)*(uint *)(param_2 + 8);
  if (param_5 == '\0') {
    if (uVar16 <= uVar22) goto LAB_146d4e51b54;
    uVar5 = *(ushort *)(param_2 + 2);
    lVar6 = *(longlong *)(param_2 + 0x1c);
    uVar17 = uVar23 + uVar16;
    if ((uVar5 & 0x10) == 0) {
      uVar17 = uVar22;
    }
    puVar2 = (undefined8 *)(lVar6 + 0x18 + uVar17 * 0x3c);
joined_r0x0146d4e519d7:
    if (uVar22 < uVar16) {
      uVar4 = *puVar2;
      uVar16 = uVar23 + uVar16;
      if ((uVar5 & 0x10) == 0) {
        uVar16 = uVar22;
      }
      uVar7 = *(undefined8 *)(lVar6 + uVar16 * 0x3c);
      *(undefined1 *)param_1 = 1;
      *(undefined8 *)((longlong)param_1 + 1) = uVar4;
      *(undefined8 *)((longlong)param_1 + 9) = uVar7;
      *(uint *)((longlong)param_1 + 0x11) = uVar15;
      return;
    }
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x19035d000001f6);
LAB_146d4e51a88:
    uVar11 = (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf0351000001f6);
LAB_146d4e51aa8:
    uVar15 = uVar15 - 1;
    if (uVar15 < uVar11) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x33038a000001f6);
    }
LAB_146d4e51ace:
    uVar11 = (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1b038a000001f6);
LAB_146d4e51aee:
    if (uVar15 - 1 < uVar11) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x34038d000001f6);
    }
LAB_146d4e51b14:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1c038d000001f6);
  }
  else if (uVar22 < uVar16) {
    uVar5 = *(ushort *)(param_2 + 2);
    lVar6 = *(longlong *)(param_2 + 0x1c);
    uVar17 = uVar23 + uVar16;
    if ((uVar5 & 0x10) == 0) {
      uVar17 = uVar22;
    }
    puVar2 = (undefined8 *)(lVar6 + 0x10 + uVar17 * 0x3c);
    goto joined_r0x0146d4e519d7;
  }
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x25035c000001f6);
LAB_146d4e51b54:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3e035c000001f6);
  pcVar9 = (code *)swi(3);
  (*pcVar9)();
  return;
}



/* Address: 146d4e51b80 */

void FUN_146d4e51b80(longlong param_1,int param_2,char *param_3,char *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e62390,0xffffffff,0xffffffff);
  if (0 < param_1) {
    if (param_2 < 1) {
      if (param_2 == 0) {
        return;
      }
      if (DAT_146d4e68768 == '\0') {
        return;
      }
      if (*param_3 == '\0') {
        return;
      }
      uVar4 = *(undefined8 *)(param_3 + 1);
      uVar3 = *(undefined8 *)(param_3 + 9);
      uVar1 = 0x146d4e62fd8;
      uVar6 = 3;
      uVar5 = 0x4763ff;
      uVar2 = 0x146d4e62f88;
    }
    else {
      if (DAT_146d4e68770 == '\0') {
        return;
      }
      if (*param_4 == '\0') {
        return;
      }
      uVar4 = *(undefined8 *)(param_4 + 1);
      uVar3 = *(undefined8 *)(param_4 + 9);
      uVar1 = 0x146d4e62f38;
      uVar2 = 0x146d4e62ee8;
      uVar6 = 7;
      uVar5 = 0xff901e;
    }
    FUN_146d4e5c280(uVar2,uVar3,uVar4,param_1,uVar5,uVar1,uVar6);
  }
  return;
}



/* Address: 146d4e51c80 */

void FUN_146d4e51c80(undefined8 param_1,undefined4 param_2,longlong param_3,int param_4,
                    char *param_5,char *param_6)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 local_38;
  undefined8 local_30;
  
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e63da0,0xffffffff,0xffffffff);
  if (param_3 < 1) {
    return;
  }
  local_30 = 0;
  local_38 = 0;
  if (param_4 < 1) {
    if (param_4 == 0) {
      return;
    }
    if (DAT_146d4e68788 == '\0') {
      return;
    }
    if (*param_5 == '\0') {
      return;
    }
    cVar1 = FUN_146d4e5ca60(param_1,param_2,param_5,&local_30,&local_38);
    if (cVar1 == '\0') {
      return;
    }
    uVar4 = *(undefined8 *)(param_5 + 9);
    uVar2 = 0x146d4e630f8;
    uVar5 = 0x4763ff;
    uVar3 = 0x146d4e630b0;
  }
  else {
    if (DAT_146d4e68790 == '\0') {
      return;
    }
    if (*param_6 == '\0') {
      return;
    }
    cVar1 = FUN_146d4e5ca60(param_1,param_2,param_6,&local_30,&local_38);
    if (cVar1 == '\0') {
      return;
    }
    uVar4 = *(undefined8 *)(param_6 + 9);
    uVar2 = 0x146d4e63068;
    uVar3 = 0x146d4e63020;
    uVar5 = 0xff901e;
  }
  FUN_146d4e5cb10(uVar3,uVar4,local_30,param_3,local_38,uVar5,uVar2);
  return;
}



/* Address: 146d4e51e00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e51e00(longlong param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  double *pdVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  ulonglong uVar14;
  int iVar15;
  undefined4 uVar16;
  ulonglong uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  uint uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  uint uVar28;
  double dVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  uint local_108;
  undefined4 local_100;
  longlong local_fc;
  undefined4 local_f0;
  longlong local_ec;
  undefined4 local_e0;
  longlong local_dc;
  ulonglong local_d0;
  ulonglong local_c8;
  undefined4 local_c0;
  longlong local_bc;
  undefined4 local_b0;
  longlong local_ac;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_8c;
  undefined4 local_80;
  undefined8 local_7c;
  ulonglong local_70;
  
  uVar21 = (ulonglong)param_2;
  local_e0 = 0;
  local_b0 = 0;
  local_f0 = 0;
  local_100 = 0;
  local_c0 = 0;
  local_80 = 0;
  local_90 = 0;
  local_dc = 0;
  local_ac = 0;
  local_ec = 0;
  local_fc = 0;
  local_bc = 0;
  local_7c = 0;
  local_8c = 0;
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e63dd0,0xffffffff,0xffffffff);
  cVar9 = DAT_146d4e687b0;
  cVar8 = DAT_146d4e687a8;
  uVar18 = 0;
  if (DAT_146d4e68072 != '\0') {
    uVar18 = 0xb;
  }
  uVar23 = 0;
  if (DAT_146d4e68003 != '\0') {
    uVar23 = 0xb;
  }
  if (DAT_146d4e68000 != '\0') {
    uVar23 = uVar18;
  }
  if ((DAT_146d4e687a8 != '\0' || DAT_146d4e687b0 != '\0') &&
     ((int)(uVar23 * 2 + 10) <= (int)param_2)) {
    lVar12 = (*(code *)0x7ff63a0f53d0)(0x146d2d8aad8,0,100,0);
    lVar13 = 0x15e;
    if (0 < lVar12) {
      lVar13 = lVar12 + 0x32;
    }
    dVar29 = (double)(int)(param_2 - 2);
    if ((double)lVar13 <= (double)(int)(param_2 - 2)) {
      dVar29 = (double)lVar13;
    }
    iVar15 = 2;
    if (2 < (int)dVar29) {
      iVar15 = (int)dVar29;
    }
    iVar15 = uVar23 + 10 + iVar15;
    iVar11 = ~uVar23 + param_2;
    iVar19 = iVar15;
    if (iVar11 < iVar15) {
      iVar19 = iVar11;
    }
    if (1 < iVar19) {
      uVar30 = 0;
      uVar31 = 0;
      uVar32 = 0;
      uVar33 = 0;
      bVar4 = false;
      local_108 = 0;
      if (iVar11 < iVar15) {
        iVar15 = iVar11;
      }
      bVar7 = false;
      bVar6 = false;
      local_98 = 0;
      local_a0 = 0;
      uVar27 = (longlong)iVar15;
      local_c8 = uVar21;
      do {
        uVar14 = (ulonglong)*(uint *)(param_3 + 8);
        iVar15 = (int)uVar27 + 1;
        uVar22 = ~uVar27;
        if (iVar15 < (int)uVar21) {
          if (uVar27 < uVar14) {
            uVar17 = (ulonglong)iVar15;
            if (uVar17 < uVar14) {
              uVar24 = ~uVar17 + uVar14;
              uVar25 = uVar14 + uVar22;
              if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
                uVar24 = uVar17;
                uVar25 = uVar27;
              }
              uVar18 = *(uint *)(*(longlong *)(param_3 + 0x1c) + uVar25 * 4);
              if (uVar18 != *(uint *)(*(longlong *)(param_3 + 0x1c) + uVar24 * 4)) {
                bVar4 = 0 < (int)uVar18;
                local_108 = uVar18 >> 0x1f;
              }
              goto LAB_146d4e520de;
            }
            goto LAB_146d4e52d8c;
          }
LAB_146d4e52dac:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1f0f1e000001f6);
LAB_146d4e52dcc:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1a0f27000001f6);
LAB_146d4e52dec:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c0f32000001f6);
LAB_146d4e52e0c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2d0f45000001f6);
LAB_146d4e52e2c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1a0f2e000001f6);
LAB_146d4e52e4c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x780f37000001f6);
LAB_146d4e52e6c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a0f3b000001f6);
LAB_146d4e52e8c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x780f4a000001f6);
LAB_146d4e52eac:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a0f4e000001f6);
LAB_146d4e52ecc:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x550f37000001f9);
LAB_146d4e52eec:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x550f4a000001f9);
LAB_146d4e52f0c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x350f37000001f9);
LAB_146d4e52f2c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x5b0f37000001f9);
LAB_146d4e52f4c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x350f4a000001f9);
LAB_146d4e52f6c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x5b0f4a000001f9);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
LAB_146d4e520de:
        if (uVar14 <= uVar27) {
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf0f24000001f6);
LAB_146d4e52d2c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf0f2b000001f6);
LAB_146d4e52d4c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1b0f45000001f6);
LAB_146d4e52d6c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x1b0f32000001f6);
LAB_146d4e52d8c:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2d0f1e000001f6);
          goto LAB_146d4e52dac;
        }
        uVar14 = uVar14 + uVar22;
        if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
          uVar14 = uVar27;
        }
        if ((*(int *)(*(longlong *)(param_3 + 0x1c) + uVar14 * 4) == 1) &&
           (cVar10 = FUN_146d4e533c0(param_1,uVar21 & 0xffffffff,uVar27 & 0xffffffff),
           cVar10 != '\0')) {
          if (uVar27 < *(uint *)(param_1 + 8)) {
            bVar6 = true;
            uVar14 = *(uint *)(param_1 + 8) + uVar22;
            if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
              uVar14 = uVar27;
            }
            uVar26 = *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + 0x10 + uVar14 * 0x3c);
            uVar32 = (undefined4)uVar26;
            uVar33 = (undefined4)((ulonglong)uVar26 >> 0x20);
            local_98 = *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c);
            goto LAB_146d4e52148;
          }
          goto LAB_146d4e52dcc;
        }
LAB_146d4e52148:
        if (*(uint *)(param_3 + 8) <= uVar27) goto LAB_146d4e52d2c;
        uVar14 = *(uint *)(param_3 + 8) + uVar22;
        if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
          uVar14 = uVar27;
        }
        if ((*(int *)(*(longlong *)(param_3 + 0x1c) + uVar14 * 4) == -1) &&
           (cVar10 = FUN_146d4e53590(param_1,uVar21 & 0xffffffff,uVar27 & 0xffffffff),
           cVar10 != '\0')) {
          if (uVar27 < *(uint *)(param_1 + 8)) {
            bVar7 = true;
            uVar14 = *(uint *)(param_1 + 8) + uVar22;
            if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
              uVar14 = uVar27;
            }
            uVar26 = *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + 0x18 + uVar14 * 0x3c);
            uVar30 = (undefined4)uVar26;
            uVar31 = (undefined4)((ulonglong)uVar26 >> 0x20);
            local_a0 = *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c);
            goto LAB_146d4e521b5;
          }
          goto LAB_146d4e52e2c;
        }
LAB_146d4e521b5:
        if (bVar6) {
          if (*(uint *)(param_3 + 8) <= uVar27) goto LAB_146d4e52d6c;
          uVar14 = *(uint *)(param_3 + 8) + uVar22;
          if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
            uVar14 = uVar27;
          }
          if (*(int *)(*(longlong *)(param_3 + 0x1c) + uVar14 * 4) != 1) goto LAB_146d4e52768;
          if (*(uint *)(param_1 + 8) <= uVar27) goto LAB_146d4e52dec;
          uVar14 = *(uint *)(param_1 + 8) + uVar22;
          if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
            uVar14 = uVar27;
          }
          dVar29 = *(double *)(*(longlong *)(param_1 + 0x1c) + 0x20 + uVar14 * 0x3c);
          if (dVar29 < (double)CONCAT44(uVar33,uVar32) || dVar29 == (double)CONCAT44(uVar33,uVar32))
          goto LAB_146d4e52768;
          cVar10 = cVar8;
          if (!bVar4) {
            cVar10 = cVar9;
          }
          if (cVar10 == '\0') {
LAB_146d4e5275d:
            bVar4 = false;
            goto LAB_146d4e52765;
          }
          local_80 = 0;
          local_7c = 0;
          (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,(longlong)(int)local_98,0,0x20);
          FUN_146d4e407d0(&local_c0,&DAT_146d4e6853c,1,0x146d4e65ae8);
          FUN_146d4e407d0(&local_100,0x146d4e63138,0);
          lVar13 = local_bc;
          if (local_bc != 0) {
            uVar18 = *(uint *)(local_bc + -4);
            uVar14 = (ulonglong)uVar18;
            if ((uVar14 == 0) && (local_fc != 0)) goto LAB_146d4e523c2;
            if (local_fc == 0) {
              local_70 = 0;
            }
            else {
              local_70 = (ulonglong)*(uint *)(local_fc + -4);
            }
            local_d0 = CONCAT44(local_d0._4_4_,(int)local_70 + uVar18);
            cVar10 = FUN_146d4e40100(&local_100);
            if (cVar10 != '\0') {
              if (uVar14 != 0) {
                lVar12 = local_fc + (local_70 & 0xffffffff) * 2;
                if (uVar18 < 8) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar12 - lVar13) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar25 = 0;
                  uVar17 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar26 = ((undefined8 *)(lVar13 + uVar25))[1];
                    *(undefined8 *)(lVar12 + uVar25) = *(undefined8 *)(lVar13 + uVar25);
                    ((undefined8 *)(lVar12 + uVar25))[1] = uVar26;
                    uVar25 = uVar25 + 0x10;
                  } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar25);
                  if (uVar17 == uVar14) goto LAB_146d4e523b3;
                }
                do {
                  *(undefined2 *)(lVar12 + uVar17 * 2) = *(undefined2 *)(lVar13 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar14 != uVar17);
              }
LAB_146d4e523b3:
              *(undefined4 *)(local_fc + -4) = (undefined4)local_d0;
              *(undefined2 *)(local_fc + (local_d0 & 0xffffffff) * 2) = 0;
              goto LAB_146d4e523c2;
            }
            goto LAB_146d4e52f0c;
          }
LAB_146d4e523c2:
          FUN_146d4e407d0(&local_f0,&local_100,0,0x146d4e65b08);
          uVar18 = _DAT_146d4e623c4;
          uVar14 = (ulonglong)_DAT_146d4e623c4;
          if ((uVar14 != 0) || (local_ec == 0)) {
            if (local_ec == 0) {
              uVar23 = 0;
              uVar28 = _DAT_146d4e623c4;
            }
            else {
              uVar23 = *(uint *)(local_ec + -4);
              uVar28 = _DAT_146d4e623c4 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar28) &&
               ((0x7ffffffd < uVar28 || (uVar20 = (uVar28 >> 2) + uVar28, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar10 = FUN_146d4e40100(&local_f0,uVar20);
            if (cVar10 != '\0') {
              if (uVar14 != 0) {
                lVar13 = local_ec + (ulonglong)uVar23 * 2;
                if (uVar18 < 8) {
                  uVar21 = 0;
                }
                else if (local_ec + -0x146d4e623c8 + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar21 = 0;
                }
                else {
                  uVar17 = 0;
                  uVar21 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar26 = *(undefined8 *)(uVar17 + 0x146d4e623d0);
                    puVar1 = (undefined8 *)(lVar13 + uVar17);
                    *puVar1 = *(undefined8 *)(&DAT_146d4e623c8 + uVar17);
                    puVar1[1] = uVar26;
                    uVar17 = uVar17 + 0x10;
                  } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar17);
                  if (uVar21 == uVar14) goto LAB_146d4e52502;
                }
                do {
                  *(undefined2 *)(lVar13 + uVar21 * 2) =
                       *(undefined2 *)(&DAT_146d4e623c8 + uVar21 * 2);
                  uVar21 = uVar21 + 1;
                } while (uVar14 != uVar21);
              }
LAB_146d4e52502:
              *(uint *)(local_ec + -4) = uVar28;
              *(undefined2 *)(local_ec + (ulonglong)uVar28 * 2) = 0;
              uVar21 = local_c8;
              goto LAB_146d4e52517;
            }
            goto LAB_146d4e52ecc;
          }
LAB_146d4e52517:
          if (*(uint *)(param_1 + 8) <= uVar27) goto LAB_146d4e52e4c;
          uVar14 = *(uint *)(param_1 + 8) + uVar22;
          if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
            uVar14 = uVar27;
          }
          (*(code *)0x7ff63a0fdfe0)
                    (0x146d2d8aad8,(longlong)*(int *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c)
                     ,0,0x20);
          FUN_146d4e407d0(&local_b0,&DAT_146d4e6853c,1,0x146d4e65b18);
          FUN_146d4e407d0(&local_e0,&local_f0,0);
          lVar13 = local_ac;
          if (local_ac == 0) {
LAB_146d4e526a6:
            FUN_146d4e407d0(&local_80,&local_e0,0,0x146d4e65b38);
            if (uVar27 < *(uint *)(param_1 + 8)) {
              uVar26 = 0x146d4e63178;
              if (!bVar4) {
                uVar26 = 0x146d4e631b8;
              }
              uVar16 = 0xffbf00;
              if (!bVar4) {
                uVar16 = 0xff00;
              }
              uVar14 = *(uint *)(param_1 + 8) + uVar22;
              if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
                uVar14 = uVar27;
              }
              FUN_146d4e5d0d0(&local_80,local_98,CONCAT44(uVar33,uVar32),
                              *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c),uVar16,
                              uVar26,3);
              FUN_146d4e400a0(&local_80);
              goto LAB_146d4e5275d;
            }
            goto LAB_146d4e52e6c;
          }
          uVar18 = *(uint *)(local_ac + -4);
          uVar14 = (ulonglong)uVar18;
          if ((uVar14 == 0) && (local_dc != 0)) goto LAB_146d4e526a6;
          if (local_dc == 0) {
            local_d0 = 0;
          }
          else {
            local_d0 = (ulonglong)*(uint *)(local_dc + -4);
          }
          uVar23 = uVar18 + (int)local_d0;
          cVar10 = FUN_146d4e40100(&local_e0);
          if (cVar10 != '\0') {
            if (uVar14 != 0) {
              lVar12 = local_dc + (local_d0 & 0xffffffff) * 2;
              if (uVar18 < 8) {
                uVar21 = 0;
              }
              else if ((ulonglong)(lVar12 - lVar13) < 0x20) {
                uVar21 = 0;
              }
              else {
                uVar17 = 0;
                uVar21 = (ulonglong)(uVar18 & 0xfffffff8);
                do {
                  uVar26 = ((undefined8 *)(lVar13 + uVar17))[1];
                  *(undefined8 *)(lVar12 + uVar17) = *(undefined8 *)(lVar13 + uVar17);
                  ((undefined8 *)(lVar12 + uVar17))[1] = uVar26;
                  uVar17 = uVar17 + 0x10;
                } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar17);
                if (uVar21 == uVar14) goto LAB_146d4e52693;
              }
              do {
                *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(lVar13 + uVar21 * 2);
                uVar21 = uVar21 + 1;
              } while (uVar14 != uVar21);
            }
LAB_146d4e52693:
            *(uint *)(local_dc + -4) = uVar23;
            *(undefined2 *)(local_dc + (ulonglong)uVar23 * 2) = 0;
            uVar21 = local_c8;
            goto LAB_146d4e526a6;
          }
          goto LAB_146d4e52f2c;
        }
LAB_146d4e52765:
        bVar6 = false;
LAB_146d4e52768:
        if (bVar7) {
          if (*(uint *)(param_3 + 8) <= uVar27) goto LAB_146d4e52d4c;
          uVar14 = *(uint *)(param_3 + 8) + uVar22;
          if ((*(byte *)(param_3 + 2) & 0x10) == 0) {
            uVar14 = uVar27;
          }
          if (*(int *)(*(longlong *)(param_3 + 0x1c) + uVar14 * 4) != -1) goto LAB_146d4e52073;
          if (*(uint *)(param_1 + 8) <= uVar27) goto LAB_146d4e52e0c;
          uVar14 = *(uint *)(param_1 + 8) + uVar22;
          if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
            uVar14 = uVar27;
          }
          pdVar2 = (double *)(*(longlong *)(param_1 + 0x1c) + 0x20 + uVar14 * 0x3c);
          if ((double)CONCAT44(uVar31,uVar30) < *pdVar2 ||
              (double)CONCAT44(uVar31,uVar30) == *pdVar2) goto LAB_146d4e52073;
          cVar10 = cVar8;
          if ((char)local_108 == '\0') {
            cVar10 = cVar9;
          }
          if (cVar10 == '\0') {
LAB_146d4e52cfc:
            bVar7 = false;
            local_108 = 0;
            goto LAB_146d4e52073;
          }
          local_90 = 0;
          local_8c = 0;
          (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,(longlong)(int)local_a0,0,0x20);
          FUN_146d4e407d0(&local_c0,&DAT_146d4e6853c,1,0x146d4e65b48);
          FUN_146d4e407d0(&local_100,0x146d4e631f8,0);
          lVar13 = local_bc;
          if (local_bc == 0) {
LAB_146d4e52965:
            FUN_146d4e407d0(&local_f0,&local_100,0,0x146d4e65b68);
            uVar18 = _DAT_146d4e623c4;
            uVar14 = (ulonglong)_DAT_146d4e623c4;
            if ((uVar14 == 0) && (local_ec != 0)) {
LAB_146d4e52ab7:
              if (*(uint *)(param_1 + 8) <= uVar27) goto LAB_146d4e52e8c;
              uVar14 = *(uint *)(param_1 + 8) + uVar22;
              if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
                uVar14 = uVar27;
              }
              (*(code *)0x7ff63a0fdfe0)
                        (0x146d2d8aad8,
                         (longlong)*(int *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c),0,0x20);
              FUN_146d4e407d0(&local_b0,&DAT_146d4e6853c,1,0x146d4e65b78);
              FUN_146d4e407d0(&local_e0,&local_f0,0);
              lVar13 = local_ac;
              if (local_ac != 0) {
                uVar18 = *(uint *)(local_ac + -4);
                uVar14 = (ulonglong)uVar18;
                if ((uVar14 != 0) || (local_dc == 0)) {
                  if (local_dc == 0) {
                    local_d0 = 0;
                  }
                  else {
                    local_d0 = (ulonglong)*(uint *)(local_dc + -4);
                  }
                  uVar23 = uVar18 + (int)local_d0;
                  cVar10 = FUN_146d4e40100(&local_e0);
                  if (cVar10 == '\0') goto LAB_146d4e52f6c;
                  if (uVar14 != 0) {
                    lVar12 = local_dc + (local_d0 & 0xffffffff) * 2;
                    if (uVar18 < 8) {
                      uVar21 = 0;
                    }
                    else if ((ulonglong)(lVar12 - lVar13) < 0x20) {
                      uVar21 = 0;
                    }
                    else {
                      uVar17 = 0;
                      uVar21 = (ulonglong)(uVar18 & 0xfffffff8);
                      do {
                        uVar26 = ((undefined8 *)(lVar13 + uVar17))[1];
                        *(undefined8 *)(lVar12 + uVar17) = *(undefined8 *)(lVar13 + uVar17);
                        ((undefined8 *)(lVar12 + uVar17))[1] = uVar26;
                        uVar17 = uVar17 + 0x10;
                      } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar17);
                      if (uVar21 == uVar14) goto LAB_146d4e52c32;
                    }
                    do {
                      *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(lVar13 + uVar21 * 2);
                      uVar21 = uVar21 + 1;
                    } while (uVar14 != uVar21);
                  }
LAB_146d4e52c32:
                  *(uint *)(local_dc + -4) = uVar23;
                  *(undefined2 *)(local_dc + (ulonglong)uVar23 * 2) = 0;
                  uVar21 = local_c8;
                }
              }
              FUN_146d4e407d0(&local_90,&local_e0,0,0x146d4e65b98);
              if (uVar27 < *(uint *)(param_1 + 8)) {
                uVar26 = 0x146d4e63238;
                if ((char)local_108 == '\0') {
                  uVar26 = 0x146d4e63278;
                }
                uVar16 = 0x45ff;
                if ((char)local_108 == '\0') {
                  uVar16 = 0x4763ff;
                }
                uVar14 = *(uint *)(param_1 + 8) + uVar22;
                if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
                  uVar14 = uVar27;
                }
                FUN_146d4e5d0d0(&local_90,local_a0,CONCAT44(uVar31,uVar30),
                                *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + uVar14 * 0x3c),
                                uVar16,uVar26,7);
                FUN_146d4e400a0(&local_90);
                goto LAB_146d4e52cfc;
              }
              goto LAB_146d4e52eac;
            }
            if (local_ec == 0) {
              uVar23 = 0;
              uVar28 = _DAT_146d4e623c4;
            }
            else {
              uVar23 = *(uint *)(local_ec + -4);
              uVar28 = _DAT_146d4e623c4 + uVar23;
            }
            uVar20 = 0x104;
            if ((0x103 < uVar28) &&
               ((0x7ffffffd < uVar28 || (uVar20 = (uVar28 >> 2) + uVar28, 0x7ffffffd < uVar20)))) {
              uVar20 = 0x7ffffffe;
            }
            cVar10 = FUN_146d4e40100(&local_f0,uVar20);
            if (cVar10 != '\0') {
              if (uVar14 != 0) {
                lVar13 = local_ec + (ulonglong)uVar23 * 2;
                if (uVar18 < 8) {
                  uVar21 = 0;
                }
                else if (local_ec + -0x146d4e623c8 + (ulonglong)uVar23 * 2 < 0x20) {
                  uVar21 = 0;
                }
                else {
                  uVar17 = 0;
                  uVar21 = (ulonglong)(uVar18 & 0xfffffff8);
                  do {
                    uVar26 = *(undefined8 *)(uVar17 + 0x146d4e623d0);
                    puVar1 = (undefined8 *)(lVar13 + uVar17);
                    *puVar1 = *(undefined8 *)(&DAT_146d4e623c8 + uVar17);
                    puVar1[1] = uVar26;
                    uVar17 = uVar17 + 0x10;
                  } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar17);
                  if (uVar21 == uVar14) goto LAB_146d4e52aa2;
                }
                do {
                  *(undefined2 *)(lVar13 + uVar21 * 2) =
                       *(undefined2 *)(&DAT_146d4e623c8 + uVar21 * 2);
                  uVar21 = uVar21 + 1;
                } while (uVar14 != uVar21);
              }
LAB_146d4e52aa2:
              *(uint *)(local_ec + -4) = uVar28;
              *(undefined2 *)(local_ec + (ulonglong)uVar28 * 2) = 0;
              uVar21 = local_c8;
              goto LAB_146d4e52ab7;
            }
            goto LAB_146d4e52eec;
          }
          uVar18 = *(uint *)(local_bc + -4);
          uVar14 = (ulonglong)uVar18;
          if ((uVar14 == 0) && (local_fc != 0)) goto LAB_146d4e52965;
          if (local_fc == 0) {
            local_d0 = 0;
          }
          else {
            local_d0 = (ulonglong)*(uint *)(local_fc + -4);
          }
          uVar23 = uVar18 + (int)local_d0;
          cVar10 = FUN_146d4e40100(&local_100);
          if (cVar10 != '\0') {
            if (uVar14 != 0) {
              lVar12 = local_fc + (local_d0 & 0xffffffff) * 2;
              if (uVar18 < 8) {
                uVar21 = 0;
              }
              else if ((ulonglong)(lVar12 - lVar13) < 0x20) {
                uVar21 = 0;
              }
              else {
                uVar17 = 0;
                uVar21 = (ulonglong)(uVar18 & 0xfffffff8);
                do {
                  uVar26 = ((undefined8 *)(lVar13 + uVar17))[1];
                  *(undefined8 *)(lVar12 + uVar17) = *(undefined8 *)(lVar13 + uVar17);
                  ((undefined8 *)(lVar12 + uVar17))[1] = uVar26;
                  uVar17 = uVar17 + 0x10;
                } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar17);
                if (uVar21 == uVar14) goto LAB_146d4e52952;
              }
              do {
                *(undefined2 *)(lVar12 + uVar21 * 2) = *(undefined2 *)(lVar13 + uVar21 * 2);
                uVar21 = uVar21 + 1;
              } while (uVar14 != uVar21);
            }
LAB_146d4e52952:
            *(uint *)(local_fc + -4) = uVar23;
            *(undefined2 *)(local_fc + (ulonglong)uVar23 * 2) = 0;
            uVar21 = local_c8;
            goto LAB_146d4e52965;
          }
          goto LAB_146d4e52f4c;
        }
        bVar7 = false;
LAB_146d4e52073:
        bVar3 = 1 < (longlong)uVar27;
        uVar27 = uVar27 - 1;
      } while (bVar3);
    }
  }
  FUN_146d4e400a0(&local_c0);
  FUN_146d4e400a0(&local_100);
  FUN_146d4e400a0(&local_f0);
  FUN_146d4e400a0(&local_b0);
  FUN_146d4e400a0(&local_e0);
  return;
}



/* Address: 146d4e52f90 */

void FUN_146d4e52f90(void)

{
  int iVar1;
  
  (*(code *)0x7ff63a0f4da0)(0x146d2d8aad8,0,0x146d4e621f0,0xffffffff,0xffffffff);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e62228);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e62228);
  }
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e62268);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e62268);
  }
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e622b0);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e622b0);
  }
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e622e8);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e622e8);
  }
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,0x146d4e62330);
  if (-1 < iVar1) {
    (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,0x146d4e62330);
    return;
  }
  return;
}



/* Address: 146d4e530f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e530f0(int param_1,char *param_2,char *param_3)

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
  char *pcVar13;
  ulonglong uVar14;
  undefined4 local_60;
  longlong local_5c;
  int local_54;
  char *local_50;
  char *local_48;
  
  if (DAT_146d4e6806e == '\x01') {
    local_60 = 0;
    local_5c = 0;
    local_54 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    iVar8 = (*(code *)0x7ff63a107da0)(0x146d2d8aad8);
    iVar8 = iVar8 + -1;
    if (-1 < iVar8) {
      do {
        lVar9 = (*(code *)0x7ff63a107df0)(0x146d2d8aad8,iVar8);
        if ((lVar9 != 0) && (cVar7 = (*(code *)0x7ff63a107ee0)(0x146d2d8aad8,lVar9), cVar7 != '\0'))
        {
          (*(code *)0x7ff63a108010)(0x146d2d8aad8,0);
          FUN_146d4e407d0(&local_60,&DAT_146d4e6853c,1,0x146d4e65068);
          if (local_5c == _DAT_146d4e6852c) {
LAB_146d4e5319d:
            lVar9 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,0xc);
            lVar10 = 0;
            if (DAT_146d4e68059 != '\0') {
              lVar10 = 0xa0a3;
            }
            if (lVar9 == lVar10) {
              FUN_146d4e400a0(&local_60);
              FUN_146d4e53740(4);
              goto LAB_146d4e533a6;
            }
          }
          else if ((local_5c != 0) && (_DAT_146d4e6852c != 0)) {
            uVar3 = *(uint *)(local_5c + -4);
            uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
            uVar6 = uVar4;
            if (uVar3 < uVar4) {
              uVar6 = uVar3;
            }
            iVar12 = uVar3 - uVar4;
            if (uVar6 != 0) {
              uVar14 = 1;
              do {
                uVar1 = *(ushort *)(local_5c + -2 + uVar14 * 2);
                uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar14 * 2);
                if (uVar6 <= uVar14) break;
                uVar14 = uVar14 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar12 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar12 == 0) goto LAB_146d4e5319d;
          }
        }
        bVar5 = 0 < iVar8;
        iVar8 = iVar8 + -1;
      } while (bVar5);
    }
    FUN_146d4e400a0(&local_60);
    param_2 = local_50;
    param_3 = local_48;
    param_1 = local_54;
  }
  if (param_1 < 1) {
    if (-1 < param_1) {
      return;
    }
    cVar7 = FUN_146d4e53740(4);
    if (cVar7 == '\0') {
      return;
    }
    if (((_DAT_146d4e68670 == 1) || (*param_3 == '\0')) || (*param_2 == '\0')) {
LAB_146d4e533a6:
      uVar11 = 5;
      goto LAB_146d4e533ab;
    }
    uVar11 = 5;
    pcVar13 = param_3;
  }
  else {
    cVar7 = FUN_146d4e53740(5);
    if (cVar7 == '\0') {
      return;
    }
    if (((_DAT_146d4e68670 == 2) || (*param_2 == '\0')) || (*param_3 == '\0')) {
      uVar11 = 4;
LAB_146d4e533ab:
      FUN_146d4e53740(uVar11);
      return;
    }
    uVar11 = 4;
    pcVar13 = param_2;
    param_2 = param_3;
  }
  FUN_146d4e53950(uVar11,pcVar13,param_2);
  return;
}



/* Address: 146d4e533c0 */

undefined8 FUN_146d4e533c0(longlong param_1,int param_2,uint param_3)

{
  double dVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar4 = 0;
  uVar9 = 0;
  if (DAT_146d4e68072 != '\0') {
    uVar9 = 0xb;
  }
  uVar6 = 0xb;
  if (DAT_146d4e68003 == '\0') {
    uVar6 = 0;
  }
  if (DAT_146d4e68000 != '\0') {
    uVar6 = uVar9;
  }
  uVar7 = (ulonglong)uVar6;
  if ((((int)uVar6 < (int)param_3) && ((int)(uVar6 + param_3) < param_2)) && (uVar4 = 1, uVar6 != 0)
     ) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 8);
    if (*(uint *)(param_1 + 8) <= param_3) goto LAB_146d4e53563;
    lVar2 = *(longlong *)(param_1 + 0x1c);
    uVar10 = ~(ulonglong)param_3 + uVar5;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      uVar10 = (ulonglong)param_3;
    }
    dVar1 = *(double *)(lVar2 + 0x10 + uVar10 * 0x3c);
    iVar8 = param_3 + 1;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      do {
        param_3 = param_3 - 1;
        if (uVar5 <= (ulonglong)(longlong)iVar8) goto LAB_146d4e53523;
        if (dVar1 < *(double *)(lVar2 + 0x10 + (longlong)iVar8 * 0x3c)) {
          return 0;
        }
        if (uVar5 <= (ulonglong)(longlong)(int)param_3) goto LAB_146d4e53543;
        if (dVar1 < *(double *)(lVar2 + 0x10 + (longlong)(int)param_3 * 0x3c)) {
          return 0;
        }
        iVar8 = iVar8 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    else {
      do {
        param_3 = param_3 - 1;
        if (uVar5 <= (ulonglong)(longlong)iVar8) goto LAB_146d4e53523;
        if (dVar1 < *(double *)(lVar2 + 0x10 + (~(longlong)iVar8 + uVar5) * 0x3c)) {
          return 0;
        }
        if (uVar5 <= (ulonglong)(longlong)(int)param_3) goto LAB_146d4e53543;
        if (dVar1 < *(double *)(lVar2 + 0x10 + (~(longlong)(int)param_3 + uVar5) * 0x3c)) {
          return 0;
        }
        iVar8 = iVar8 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  return uVar4;
LAB_146d4e53523:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x33036d000001f6);
LAB_146d4e53543:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x6a036d000001f6);
LAB_146d4e53563:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf036d000001f6);
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



/* Address: 146d4e53590 */

undefined8 FUN_146d4e53590(longlong param_1,int param_2,uint param_3)

{
  double *pdVar1;
  double dVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  
  uVar5 = 0;
  uVar10 = 0;
  if (DAT_146d4e68072 != '\0') {
    uVar10 = 0xb;
  }
  uVar7 = 0xb;
  if (DAT_146d4e68003 == '\0') {
    uVar7 = 0;
  }
  if (DAT_146d4e68000 != '\0') {
    uVar7 = uVar10;
  }
  uVar8 = (ulonglong)uVar7;
  if ((((int)uVar7 < (int)param_3) && ((int)(uVar7 + param_3) < param_2)) && (uVar5 = 1, uVar7 != 0)
     ) {
    uVar6 = (ulonglong)*(uint *)(param_1 + 8);
    if (*(uint *)(param_1 + 8) <= param_3) goto LAB_146d4e5371b;
    lVar3 = *(longlong *)(param_1 + 0x1c);
    uVar11 = ~(ulonglong)param_3 + uVar6;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      uVar11 = (ulonglong)param_3;
    }
    dVar2 = *(double *)(lVar3 + 0x18 + uVar11 * 0x3c);
    iVar9 = param_3 + 1;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      do {
        param_3 = param_3 - 1;
        if (uVar6 <= (ulonglong)(longlong)iVar9) goto LAB_146d4e536db;
        pdVar1 = (double *)(lVar3 + 0x18 + (longlong)iVar9 * 0x3c);
        if (*pdVar1 <= dVar2 && dVar2 != *pdVar1) {
          return 0;
        }
        if (uVar6 <= (ulonglong)(longlong)(int)param_3) goto LAB_146d4e536fb;
        pdVar1 = (double *)(lVar3 + 0x18 + (longlong)(int)param_3 * 0x3c);
        if (*pdVar1 <= dVar2 && dVar2 != *pdVar1) {
          return 0;
        }
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    else {
      do {
        param_3 = param_3 - 1;
        if (uVar6 <= (ulonglong)(longlong)iVar9) goto LAB_146d4e536db;
        pdVar1 = (double *)(lVar3 + 0x18 + (~(longlong)iVar9 + uVar6) * 0x3c);
        if (*pdVar1 <= dVar2 && dVar2 != *pdVar1) {
          return 0;
        }
        if (uVar6 <= (ulonglong)(longlong)(int)param_3) goto LAB_146d4e536fb;
        pdVar1 = (double *)(lVar3 + 0x18 + (~(longlong)(int)param_3 + uVar6) * 0x3c);
        if (*pdVar1 <= dVar2 && dVar2 != *pdVar1) {
          return 0;
        }
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  return uVar5;
LAB_146d4e536db:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x32037c000001f6);
LAB_146d4e536fb:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x67037c000001f6);
LAB_146d4e5371b:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0xf037c000001f6);
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



/* Address: 146d4e53740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_146d4e53740(int param_1)

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
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  ulonglong uVar14;
  uint local_58;
  undefined4 local_50;
  longlong local_4c;
  
  local_50 = 0;
  local_4c = 0;
  uVar9 = (*(code *)0x7ff63a1081a0)(0x146d2d8aad8);
  iVar13 = (int)uVar9 + -1;
  local_58 = (uint)CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
  if (-1 < iVar13) {
    do {
      lVar10 = (*(code *)0x7ff63a1081f0)(0x146d2d8aad8,iVar13);
      if ((lVar10 != 0) && (cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,lVar10), cVar7 != '\0'))
      {
        (*(code *)0x7ff63a1083a0)(0x146d2d8aad8,0);
        FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65058);
        if (local_4c == _DAT_146d4e6852c) {
LAB_146d4e538b2:
          lVar11 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,0xf);
          lVar12 = 0;
          if (DAT_146d4e68059 != '\0') {
            lVar12 = 0xa0a3;
          }
          if ((lVar11 == lVar12) &&
             (iVar8 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,4), iVar8 == param_1)) {
            cVar7 = FUN_146d4e58090(lVar10);
            local_58 = local_58 & 0xff;
            if (cVar7 == '\0') {
              local_58 = 0;
            }
          }
        }
        else if ((local_4c != 0) && (_DAT_146d4e6852c != 0)) {
          uVar3 = *(uint *)(local_4c + -4);
          uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar14 = 1;
            do {
              uVar1 = *(ushort *)(local_4c + -2 + uVar14 * 2);
              uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar14 * 2);
              if (uVar6 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_146d4e538b2;
        }
      }
      bVar5 = 0 < iVar13;
      iVar13 = iVar13 + -1;
    } while (bVar5);
  }
  FUN_146d4e400a0(&local_50);
  return local_58;
}



/* Address: 146d4e53950 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e53950(int param_1,char *param_2,char *param_3)

{
  longlong lVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 *puVar4;
  double dVar5;
  double dVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  double *pdVar11;
  code *pcVar12;
  char *pcVar13;
  longlong lVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  bool bVar24;
  undefined4 uVar25;
  uint uVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined8 in_stack_fffffffffffffcc0;
  undefined4 *puVar41;
  undefined4 uVar42;
  undefined8 uVar43;
  undefined4 local_2b8;
  longlong local_2b4;
  undefined4 *local_2a8;
  undefined4 local_2a0;
  undefined8 local_29c;
  ulonglong local_290;
  undefined4 local_288;
  undefined8 local_284;
  undefined4 local_278;
  longlong local_274;
  undefined4 local_268;
  undefined8 local_264;
  undefined4 local_258;
  longlong local_254;
  undefined4 local_248;
  longlong local_244;
  undefined4 local_238;
  longlong local_234;
  undefined4 local_228;
  longlong local_224;
  undefined4 local_218;
  longlong local_214;
  undefined4 local_208;
  longlong local_204;
  undefined4 local_1f8;
  longlong local_1f4;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  double local_1d8;
  double local_1a8;
  undefined4 local_1a0;
  undefined8 local_19c;
  undefined4 local_190;
  undefined8 local_18c;
  undefined4 local_180;
  undefined8 local_17c;
  undefined4 local_170;
  undefined8 local_16c;
  int local_164;
  undefined4 local_160;
  longlong local_15c;
  undefined4 local_150;
  longlong local_14c;
  undefined4 local_140;
  longlong local_13c;
  char *local_130;
  undefined4 local_128;
  undefined8 local_124;
  undefined4 local_118;
  undefined8 local_114;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  
  local_118 = 0;
  local_128 = 0;
  local_268 = 0;
  local_288 = 0;
  local_2a0 = 0;
  local_170 = 0;
  local_180 = 0;
  local_2b8 = 0;
  local_190 = 0;
  local_1a0 = 0;
  local_114 = 0;
  local_124 = 0;
  local_264 = 0;
  local_284 = 0;
  local_29c = 0;
  local_16c = 0;
  local_17c = 0;
  local_2b4 = 0;
  local_18c = 0;
  local_19c = 0;
  if ((*param_2 == '\0') || (*param_3 == '\0')) {
    FUN_146d4e53740(param_1);
    goto LAB_146d4e53f2f;
  }
  local_130 = param_2;
  dVar27 = (double)FUN_146d4e56920((int)*(undefined8 *)(param_2 + 1));
  cVar7 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,0x146d4e5e890,&local_1e8);
  if (cVar7 == '\0') {
LAB_146d4e53b75:
    FUN_146d4e53740(param_1);
    local_170 = 0;
    local_16c = 0;
    uVar25 = 0;
    FUN_146d4e56b10(param_1,0x146d4e60a30,dVar27,0,0,0);
    FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64e48);
    FUN_146d4e407d0(&local_170,&local_2a0,0,0x146d4e64e58);
    cVar7 = FUN_146d4e57bf0(param_1,&local_170);
    if (cVar7 != '\0') {
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
      FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64e68);
      local_1e8 = 0;
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      if (param_1 == 4) {
        uVar17 = 0x146d4e61900;
        uVar21 = 0x146d4e65598;
      }
      else {
        uVar17 = 0x146d4e61930;
        uVar21 = 0x146d4e655a8;
      }
      FUN_146d4e407d0(&local_1e8,uVar17,0,uVar21);
      FUN_146d4e407d0(&DAT_146d4e6853c,&local_1e8,1,0x146d4e655b8);
      FUN_146d4e400a0(&local_1e8);
      FUN_146d4e407d0(&local_288,&DAT_146d4e6853c,1,0x146d4e64e78);
      (*(code *)0x7ff63a0e49f0)
                (0x146d2d8aad8,2,4,0x590008,&local_288,CONCAT44(uVar25,0x590008),0x146d4e60a80,
                 0x590008,&local_2a0,0x590008,0x146d4e60af8);
    }
    puVar15 = &local_170;
  }
  else {
    lVar10 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e5e890,0x1f);
    if (param_1 == 4) {
      if (dVar27 <= (double)lVar10 * _DAT_146d4e68518 + local_1d8) goto LAB_146d4e53b75;
    }
    else if ((double)CONCAT44(uStack_1dc,uStack_1e0) - (double)lVar10 * _DAT_146d4e68518 <= dVar27)
    goto LAB_146d4e53b75;
    dVar28 = (double)FUN_146d4e56920((int)*(undefined8 *)(param_3 + 1));
    if ((param_1 != 4 || dVar28 < dVar27) && (param_1 != 5 || dVar27 < dVar28)) {
      pcVar13 = &DAT_146d4e68030;
      local_1e8 = 0;
      local_278 = 0;
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      local_274 = 0;
      if (DAT_146d4e68000 != '\0') {
        pcVar13 = &DAT_146d4e680a0;
      }
      pdVar11 = (double *)&DAT_146d4e68038;
      if (DAT_146d4e68000 != '\0') {
        pdVar11 = (double *)&DAT_146d4e680a8;
      }
      dVar5 = dVar28;
      if ((((*pcVar13 == '\x01') && (0.0 < *pdVar11)) && (0.0 < dVar27)) &&
         (dVar29 = (double)FUN_146d4e56920(SUB84((*pdVar11 / _DAT_146d4e5e580) * dVar27,0)),
         0.0 < dVar29)) {
        if (param_1 == 4) {
          dVar29 = (double)FUN_146d4e56920(SUB84(dVar27 - dVar29,0));
          if (dVar28 < dVar29) {
            cVar7 = FUN_146d4e5b060(4);
            uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffcc0 >> 0x20);
            dVar5 = dVar29;
            if (cVar7 != '\0') {
              local_2a8 = (undefined4 *)0x146d4e613f0;
              local_290 = 0x146d4e653b8;
              uVar17 = 0x146d4e653a8;
LAB_146d4e54281:
              (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar29,_DAT_146d4e68520);
              FUN_146d4e407d0(&local_278,&DAT_146d4e6853c,1,uVar17);
              (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar28,_DAT_146d4e68520);
              FUN_146d4e407d0(&local_1e8,&DAT_146d4e6853c,1,local_290);
              in_stack_fffffffffffffcc0 = CONCAT44(uVar25,0x590008);
              (*(code *)0x7ff63a0e49f0)
                        (0x146d2d8aad8,2,4,0x590008,local_2a8,in_stack_fffffffffffffcc0,&local_1e8,
                         0x590008,0x146d4e60d58,0x590008,&local_278);
              dVar5 = dVar29;
            }
          }
        }
        else {
          dVar29 = (double)FUN_146d4e56920(SUB84(dVar29 + dVar27,0));
          if (dVar29 < dVar28) {
            cVar7 = FUN_146d4e5b060(5);
            uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffcc0 >> 0x20);
            dVar5 = dVar29;
            if (cVar7 != '\0') {
              local_2a8 = (undefined4 *)0x146d4e61448;
              local_290 = 0x146d4e653d8;
              uVar17 = 0x146d4e653c8;
              goto LAB_146d4e54281;
            }
          }
        }
      }
      FUN_146d4e400a0(&local_278);
      FUN_146d4e400a0(&local_1e8);
      pcVar13 = &DAT_146d4e68018;
      if (DAT_146d4e68000 != '\0') {
        pcVar13 = &DAT_146d4e68088;
      }
      if (*pcVar13 == '\x01') {
        pdVar11 = (double *)&DAT_146d4e68020;
        dVar28 = 0.0;
        if (DAT_146d4e68000 != '\0') {
          pdVar11 = (double *)&DAT_146d4e68090;
        }
        if ((0.0 < *pdVar11) && (0.0 < dVar27)) {
          uVar25 = SUB84((*pdVar11 / _DAT_146d4e5e580) * dVar27,0);
LAB_146d4e5448d:
          dVar28 = (double)FUN_146d4e56920(uVar25);
        }
      }
      else {
        pdVar11 = (double *)&DAT_146d4e68028;
        dVar28 = 0.0;
        if (DAT_146d4e68000 != '\0') {
          pdVar11 = (double *)&DAT_146d4e68098;
        }
        if (0.0 < *pdVar11) {
          if ((_DAT_146d4e68520 == 5) || (dVar28 = _DAT_146d4e68518, _DAT_146d4e68520 == 3)) {
            dVar28 = _DAT_146d4e68518 * _DAT_146d4e5e588;
          }
          uVar25 = SUB84(*pdVar11 * dVar28,0);
          goto LAB_146d4e5448d;
        }
      }
      uVar37 = 0;
      uVar38 = 0;
      dVar28 = (double)(~-(ulonglong)(dVar28 <= 0.0) & (ulonglong)dVar28);
      uVar25 = SUB84(dVar28,0);
      uVar42 = (undefined4)((ulonglong)dVar28 >> 0x20);
      local_1a8 = 0.0;
      if (0.0 < dVar28) {
        if (param_1 != 4) {
          uVar25 = (undefined4)((ulonglong)dVar28 ^ _DAT_146d4e5e590);
          uVar42 = (undefined4)(((ulonglong)dVar28 ^ _DAT_146d4e5e590) >> 0x20);
        }
        local_1a8 = (double)FUN_146d4e56920(SUB84((double)CONCAT44(uVar42,uVar25) + dVar27,0));
      }
      local_1e8 = 0;
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      FUN_146d4e400a0(&local_1e8);
      local_1e8 = 0;
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      iVar8 = (*(code *)0x7ff63a1081a0)(0x146d2d8aad8);
      uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffcc0 >> 0x20);
      if (iVar8 + -1 < 0) {
        local_2a8 = (undefined4 *)0x0;
        local_290 = CONCAT44(local_290._4_4_,1);
      }
      else {
        iVar8 = iVar8 + -1;
        do {
          local_2a8 = (undefined4 *)(*(code *)0x7ff63a1081f0)(0x146d2d8aad8,iVar8);
          if ((local_2a8 != (undefined4 *)0x0) &&
             (cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,local_2a8), cVar7 != '\0')) {
            (*(code *)0x7ff63a1083a0)(0x146d2d8aad8,0);
            FUN_146d4e407d0(&local_1e8,&DAT_146d4e6853c,1,0x146d4e65078);
            puVar4 = (undefined1 *)CONCAT44(uStack_1e0,uStack_1e4);
            if (puVar4 == _DAT_146d4e6852c) {
LAB_146d4e5465f:
              lVar10 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,0xf);
              lVar14 = 0;
              if (DAT_146d4e68059 != '\0') {
                lVar14 = 0xa0a3;
              }
              if (lVar10 == lVar14) {
                iVar9 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,4);
                uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffcc0 >> 0x20);
                if (iVar9 == param_1) {
                  (*(code *)0x7ff63a108280)(0x146d2d8aad8,9);
                  local_290 = local_290 & 0xffffffff00000000;
                  uVar37 = SUB84(_DAT_146d4e68548,0);
                  uVar38 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
                  goto LAB_146d4e54745;
                }
              }
            }
            else if ((puVar4 != (undefined1 *)0x0) && (_DAT_146d4e6852c != (undefined1 *)0x0)) {
              uVar26 = *(uint *)(puVar4 + -4);
              uVar19 = *(uint *)(_DAT_146d4e6852c + -4);
              uVar16 = uVar19;
              if (uVar26 < uVar19) {
                uVar16 = uVar26;
              }
              iVar9 = uVar26 - uVar19;
              if (uVar16 != 0) {
                uVar23 = 1;
                do {
                  uVar2 = *(ushort *)(puVar4 + uVar23 * 2 + -2);
                  uVar3 = *(ushort *)(_DAT_146d4e6852c + uVar23 * 2 + -2);
                  if (uVar16 <= uVar23) break;
                  uVar23 = uVar23 + 1;
                } while (uVar2 == uVar3);
                if (uVar2 != uVar3) {
                  iVar9 = (uint)uVar2 - (uint)uVar3;
                }
              }
              if (iVar9 == 0) goto LAB_146d4e5465f;
            }
          }
          uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffcc0 >> 0x20);
          iVar9 = iVar8 + -1;
          bVar24 = 0 < iVar8;
          iVar8 = iVar9;
        } while (bVar24);
        local_290 = CONCAT44(local_290._4_4_,(int)CONCAT71((uint7)(uint3)((uint)iVar9 >> 8),1));
        local_2a8 = (undefined4 *)0x0;
      }
LAB_146d4e54745:
      uVar26 = FUN_146d4e400a0(&local_1e8);
      local_164 = _DAT_146d4e68638;
      if (_DAT_146d4e68638 == 1) {
        uVar42 = 0;
        uVar23 = (ulonglong)uVar26;
        if (_DAT_146d4e6852c == &DAT_146d4e5e908) goto LAB_146d4e54828;
        if (_DAT_146d4e6852c == (undefined1 *)0x0) {
          iVar8 = 1;
        }
        else {
          uVar19 = *(uint *)(_DAT_146d4e6852c + -4);
          uVar16 = _DAT_146d4e5e904;
          if (uVar19 < _DAT_146d4e5e904) {
            uVar16 = uVar19;
          }
          iVar8 = uVar19 - _DAT_146d4e5e904;
          if (uVar16 != 0) {
            uVar23 = 0;
            do {
              uVar2 = *(ushort *)(_DAT_146d4e6852c + uVar23 * 2);
              uVar3 = *(ushort *)(&DAT_146d4e5e908 + uVar23 * 2);
              uVar23 = uVar23 + 1;
              if (uVar16 <= uVar23) break;
            } while (uVar2 == uVar3);
            if (uVar2 != uVar3) {
              iVar8 = (uint)uVar2 - (uint)uVar3;
            }
          }
        }
        uVar23 = (ulonglong)uVar26;
        if (iVar8 == 0) goto LAB_146d4e54828;
        uVar23 = 0;
        if ((dVar27 <= 0.0) || (uVar23 = 0, dVar5 <= 0.0)) goto LAB_146d4e54828;
        uVar26 = (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x25);
        uVar33 = SUB84(_DAT_146d4e68548,0);
        uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
        uVar42 = 0;
        if (_DAT_146d4e68548 <= 0.0) {
          uVar26 = (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x28);
          uVar33 = SUB84(_DAT_146d4e68548,0);
          uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
        }
        uVar23 = (ulonglong)uVar26;
        if (((double)CONCAT44(uVar34,uVar33) <= 0.0) || (uVar23 = 0, _DAT_146d4e68648 <= 0.0))
        goto LAB_146d4e54828;
        uVar42 = 0;
        dVar29 = (double)CONCAT44(uVar34,uVar33) * (_DAT_146d4e68648 / _DAT_146d4e5e580);
        uVar23 = 0;
        if (dVar29 <= 0.0) goto LAB_146d4e54828;
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x22);
        dVar28 = _DAT_146d4e68548;
        uVar42 = SUB84(_DAT_146d4e68548,0);
        uVar33 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
        dVar30 = 0.0;
        if ((0.0 < dVar28) && (dVar30 = 0.0, 0.0 < _DAT_146d4e68548)) {
          if (dVar28 <= _DAT_146d4e68650) {
            uVar42 = SUB84(_DAT_146d4e68650,0);
            uVar33 = (undefined4)((ulonglong)_DAT_146d4e68650 >> 0x20);
          }
          if (_DAT_146d4e68548 <= (double)CONCAT44(uVar33,uVar42)) {
            uVar33 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
            uVar42 = SUB84(_DAT_146d4e68548,0);
          }
          dVar30 = (double)FUN_146d4e59600(0x146d4e68528,CONCAT44(uVar33,uVar42));
        }
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
        dVar28 = 0.0;
        if (0.0 < _DAT_146d4e68548) {
          (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x22);
          dVar28 = _DAT_146d4e68548;
          (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
          if ((0.0 < dVar28) && (0.0 < _DAT_146d4e68548)) {
            FUN_146d4e59600(0x146d4e68528);
          }
          dVar28 = (double)FUN_146d4e59600(0x146d4e68528);
        }
        uVar26 = (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
        uVar42 = 0;
        uVar23 = (ulonglong)uVar26;
        if ((dVar30 <= 0.0) || (uVar23 = (ulonglong)dVar28 & 0xffffffff, dVar28 <= 0.0))
        goto LAB_146d4e54828;
        uVar23 = (ulonglong)_DAT_146d4e68548 & 0xffffffff;
        if (_DAT_146d4e68548 <= 0.0) goto LAB_146d4e54828;
        uVar34 = (undefined4)((ulonglong)_DAT_146d4e5e5a0 >> 0x20);
        uVar33 = SUB84(_DAT_146d4e5e5a0,0);
        if (_DAT_146d4e68548 <= _DAT_146d4e5e5a0) {
          uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
          uVar33 = SUB84(_DAT_146d4e68548,0);
        }
        uVar23 = (ulonglong)_DAT_146d4e68548 & 0xffffffff;
        if ((double)CONCAT44(uVar34,uVar33) <= 0.0) goto LAB_146d4e54828;
        dVar31 = (double)FUN_146d4e5b8f0(param_1,dVar27,dVar5,CONCAT44(uVar34,uVar33),
                                         DAT_146d4e6806d);
        uVar42 = 0;
        uVar23 = (ulonglong)dVar31 & 0xffffffff;
        if (dVar31 <= 0.0) goto LAB_146d4e54828;
        if (((double)CONCAT44(uVar34,uVar33) != 0.0) || (NAN((double)CONCAT44(uVar34,uVar33)))) {
          dVar31 = dVar31 / (double)CONCAT44(uVar34,uVar33);
          uVar23 = (ulonglong)dVar31 & 0xffffffff;
          if (0.0 < dVar31) {
            if ((dVar31 == 0.0) && (!NAN(dVar31))) goto LAB_146d4e568f0;
            dVar29 = dVar29 / dVar31;
            uVar23 = (ulonglong)dVar31 & 0xffffffff;
            if ((0.0 < dVar29) &&
               ((dVar31 = dVar29, dVar30 <= _DAT_146d4e5e5a8 + dVar29 ||
                (dVar31 = dVar30, uVar23 = (ulonglong)(_DAT_146d4e5e5a8 + dVar29) & 0xffffffff,
                DAT_146d4e6806c == '\x01')))) {
              dVar29 = dVar28;
              if (dVar31 <= dVar28) {
                dVar29 = dVar31;
              }
              dVar29 = (double)FUN_146d4e59600(0x146d4e68528,dVar29);
              uVar42 = 0;
              uVar23 = (ulonglong)dVar29 & 0xffffffff;
              if ((0.0 < dVar29) &&
                 ((dVar30 <= dVar29 + _DAT_146d4e5e5a8 ||
                  (uVar23 = (ulonglong)dVar30 & 0xffffffff, dVar29 = dVar30,
                  DAT_146d4e6806c == '\x01')))) {
                if (dVar29 <= dVar28) {
                  dVar28 = dVar29;
                }
                goto LAB_146d4e5480d;
              }
            }
          }
          goto LAB_146d4e54828;
        }
      }
      else {
        dVar28 = (double)FUN_146d4e57de0();
LAB_146d4e5480d:
        uVar23 = FUN_146d4e59600(0x146d4e68528,dVar28);
        uVar42 = (undefined4)uVar23;
LAB_146d4e54828:
        local_2b8 = 0;
        local_1e8 = 0;
        local_278 = 0;
        local_1f8 = 0;
        local_208 = 0;
        local_140 = 0;
        local_218 = 0;
        local_228 = 0;
        local_150 = 0;
        local_238 = 0;
        local_248 = 0;
        local_160 = 0;
        local_258 = 0;
        local_108 = 0;
        local_f8 = 0;
        local_2b4 = 0;
        uStack_1e4 = 0;
        uStack_1e0 = 0;
        local_274 = 0;
        local_1f4 = 0;
        local_204 = 0;
        local_13c = 0;
        local_214 = 0;
        local_224 = 0;
        local_14c = 0;
        local_234 = 0;
        local_244 = 0;
        local_15c = 0;
        local_254 = 0;
        local_104 = 0;
        local_f4 = 0;
        (*(code *)0x7ff63a0c7370)((int)uVar23,0x2a);
        uVar33 = SUB84(_DAT_146d4e68548,0);
        uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
        if (_DAT_146d4e68548 <= 0.0) {
          (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x25);
          uVar33 = SUB84(_DAT_146d4e68548,0);
          uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
        }
        uVar18 = 0;
        (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,param_1,0,0x20);
        FUN_146d4e407d0(&local_108,&DAT_146d4e6853c,1,0x146d4e65ef8);
        FUN_146d4e407d0(&local_258,&local_108,0);
        uVar26 = _DAT_146d4e635d4;
        uVar23 = (ulonglong)_DAT_146d4e635d4;
        if ((uVar23 == 0) && (local_254 != 0)) {
LAB_146d4e54afd:
          (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
          FUN_146d4e407d0(&local_160,&DAT_146d4e6853c,1,0x146d4e65f18);
          FUN_146d4e407d0(&local_248,&local_258,0);
          lVar10 = local_15c;
          if (local_15c != 0) {
            uVar26 = *(uint *)(local_15c + -4);
            uVar23 = (ulonglong)uVar26;
            if ((uVar23 == 0) && (local_244 != 0)) goto LAB_146d4e550b7;
            if (local_244 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_244 + -4);
            }
            uVar19 = uVar26 + (int)uVar18;
            cVar7 = FUN_146d4e40100(&local_248);
            if (cVar7 != '\0') {
              if (uVar23 != 0) {
                lVar14 = local_244 + uVar18 * 2;
                if (uVar26 < 0x10) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar14 - lVar10) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar22 = 0;
                  uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                  do {
                    puVar15 = (undefined4 *)(lVar10 + uVar22);
                    uVar35 = puVar15[1];
                    uVar36 = puVar15[2];
                    uVar39 = puVar15[3];
                    puVar41 = (undefined4 *)(lVar14 + uVar22);
                    *puVar41 = *puVar15;
                    puVar41[1] = uVar35;
                    puVar41[2] = uVar36;
                    puVar41[3] = uVar39;
                    uVar22 = uVar22 + 0x10;
                  } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                  if (uVar18 == uVar23) goto LAB_146d4e550a2;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) = *(undefined2 *)(lVar10 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar23 != uVar18);
              }
LAB_146d4e550a2:
              *(uint *)(local_244 + -4) = uVar19;
              *(undefined2 *)(local_244 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_146d4e550b7;
            }
            goto LAB_146d4e56850;
          }
LAB_146d4e550b7:
          uVar18 = 0;
          FUN_146d4e407d0(&local_238,&local_248,0);
          uVar26 = _DAT_146d4e635d4;
          uVar23 = (ulonglong)_DAT_146d4e635d4;
          if ((uVar23 != 0) || (local_234 == 0)) {
            if (local_234 != 0) {
              uVar18 = (ulonglong)*(uint *)(local_234 + -4);
            }
            uVar19 = _DAT_146d4e635d4 + (int)uVar18;
            cVar7 = FUN_146d4e40100(&local_238);
            if (cVar7 == '\0') goto LAB_146d4e567f0;
            if (uVar23 != 0) {
              lVar10 = local_234 + uVar18 * 2;
              if ((uVar26 < 0x10) || (lVar10 - 0x146d4e635d8U < 0x20)) {
                uVar18 = 0;
              }
              else {
                uVar22 = 0;
                uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  uVar35 = *(undefined4 *)(uVar22 + 0x146d4e635dc);
                  uVar36 = *(undefined4 *)(uVar22 + 0x146d4e635e0);
                  uVar39 = *(undefined4 *)(uVar22 + 0x146d4e635e4);
                  puVar15 = (undefined4 *)(lVar10 + uVar22);
                  *puVar15 = *(undefined4 *)(&DAT_146d4e635d8 + uVar22);
                  puVar15[1] = uVar35;
                  puVar15[2] = uVar36;
                  puVar15[3] = uVar39;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar18 == uVar23) goto LAB_146d4e551a2;
              }
              do {
                *(undefined2 *)(lVar10 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_146d4e635d8 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar23 != uVar18);
            }
LAB_146d4e551a2:
            *(uint *)(local_234 + -4) = uVar19;
            *(undefined2 *)(local_234 + (ulonglong)uVar19 * 2) = 0;
          }
          (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar5,_DAT_146d4e68520);
          FUN_146d4e407d0(&local_150,&DAT_146d4e6853c,1,0x146d4e65f48);
          FUN_146d4e407d0(&local_228,&local_238,0);
          lVar10 = local_14c;
          if (local_14c != 0) {
            uVar26 = *(uint *)(local_14c + -4);
            uVar23 = (ulonglong)uVar26;
            if ((uVar23 == 0) && (local_224 != 0)) goto LAB_146d4e55357;
            if (local_224 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_224 + -4);
            }
            uVar19 = uVar26 + (int)uVar18;
            cVar7 = FUN_146d4e40100(&local_228);
            if (cVar7 != '\0') {
              if (uVar23 != 0) {
                lVar14 = local_224 + uVar18 * 2;
                if (uVar26 < 0x10) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar14 - lVar10) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar22 = 0;
                  uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                  do {
                    puVar15 = (undefined4 *)(lVar10 + uVar22);
                    uVar35 = puVar15[1];
                    uVar36 = puVar15[2];
                    uVar39 = puVar15[3];
                    puVar41 = (undefined4 *)(lVar14 + uVar22);
                    *puVar41 = *puVar15;
                    puVar41[1] = uVar35;
                    puVar41[2] = uVar36;
                    puVar41[3] = uVar39;
                    uVar22 = uVar22 + 0x10;
                  } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                  if (uVar18 == uVar23) goto LAB_146d4e55342;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) = *(undefined2 *)(lVar10 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar23 != uVar18);
              }
LAB_146d4e55342:
              *(uint *)(local_224 + -4) = uVar19;
              *(undefined2 *)(local_224 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_146d4e55357;
            }
            goto LAB_146d4e56870;
          }
LAB_146d4e55357:
          uVar18 = 0;
          FUN_146d4e407d0(&local_218,&local_228,0);
          uVar26 = _DAT_146d4e635d4;
          uVar23 = (ulonglong)_DAT_146d4e635d4;
          if ((uVar23 != 0) || (local_214 == 0)) {
            if (local_214 != 0) {
              uVar18 = (ulonglong)*(uint *)(local_214 + -4);
            }
            uVar19 = _DAT_146d4e635d4 + (int)uVar18;
            cVar7 = FUN_146d4e40100(&local_218);
            if (cVar7 == '\0') goto LAB_146d4e56810;
            if (uVar23 != 0) {
              lVar10 = local_214 + uVar18 * 2;
              if ((uVar26 < 0x10) || (lVar10 - 0x146d4e635d8U < 0x20)) {
                uVar18 = 0;
              }
              else {
                uVar22 = 0;
                uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  uVar35 = *(undefined4 *)(uVar22 + 0x146d4e635dc);
                  uVar36 = *(undefined4 *)(uVar22 + 0x146d4e635e0);
                  uVar39 = *(undefined4 *)(uVar22 + 0x146d4e635e4);
                  puVar15 = (undefined4 *)(lVar10 + uVar22);
                  *puVar15 = *(undefined4 *)(&DAT_146d4e635d8 + uVar22);
                  puVar15[1] = uVar35;
                  puVar15[2] = uVar36;
                  puVar15[3] = uVar39;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar18 == uVar23) goto LAB_146d4e55442;
              }
              do {
                *(undefined2 *)(lVar10 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_146d4e635d8 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar23 != uVar18);
            }
LAB_146d4e55442:
            *(uint *)(local_214 + -4) = uVar19;
            *(undefined2 *)(local_214 + (ulonglong)uVar19 * 2) = 0;
          }
          (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,uVar42,4);
          FUN_146d4e407d0(&local_140,&DAT_146d4e6853c,1,0x146d4e65f78);
          FUN_146d4e407d0(&local_208,&local_218);
          lVar10 = local_13c;
          if (local_13c != 0) {
            uVar26 = *(uint *)(local_13c + -4);
            uVar23 = (ulonglong)uVar26;
            if ((uVar23 == 0) && (local_204 != 0)) goto LAB_146d4e555e7;
            if (local_204 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = (ulonglong)*(uint *)(local_204 + -4);
            }
            uVar19 = uVar26 + (int)uVar18;
            cVar7 = FUN_146d4e40100(&local_208);
            if (cVar7 != '\0') {
              if (uVar23 != 0) {
                lVar14 = local_204 + uVar18 * 2;
                if (uVar26 < 0x10) {
                  uVar18 = 0;
                }
                else if ((ulonglong)(lVar14 - lVar10) < 0x20) {
                  uVar18 = 0;
                }
                else {
                  uVar22 = 0;
                  uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                  do {
                    puVar15 = (undefined4 *)(lVar10 + uVar22);
                    uVar35 = puVar15[1];
                    uVar36 = puVar15[2];
                    uVar39 = puVar15[3];
                    puVar41 = (undefined4 *)(lVar14 + uVar22);
                    *puVar41 = *puVar15;
                    puVar41[1] = uVar35;
                    puVar41[2] = uVar36;
                    puVar41[3] = uVar39;
                    uVar22 = uVar22 + 0x10;
                  } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                  if (uVar18 == uVar23) goto LAB_146d4e555d2;
                }
                do {
                  *(undefined2 *)(lVar14 + uVar18 * 2) = *(undefined2 *)(lVar10 + uVar18 * 2);
                  uVar18 = uVar18 + 1;
                } while (uVar23 != uVar18);
              }
LAB_146d4e555d2:
              *(uint *)(local_204 + -4) = uVar19;
              *(undefined2 *)(local_204 + (ulonglong)uVar19 * 2) = 0;
              goto LAB_146d4e555e7;
            }
            goto LAB_146d4e56890;
          }
LAB_146d4e555e7:
          uVar26 = 0;
          FUN_146d4e407d0(&local_1f8,&local_208,0,0x146d4e65f98);
          uVar19 = _DAT_146d4e635d4;
          uVar23 = (ulonglong)_DAT_146d4e635d4;
          if ((uVar23 != 0) || (local_1f4 == 0)) {
            if (local_1f4 != 0) {
              uVar26 = *(uint *)(local_1f4 + -4);
            }
            uVar20 = _DAT_146d4e635d4 + uVar26;
            uVar16 = 0x104;
            if ((0x103 < uVar20) &&
               ((0x7ffffffd < uVar20 || (uVar16 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar16)))) {
              uVar16 = 0x7ffffffe;
            }
            cVar7 = FUN_146d4e40100(&local_1f8,uVar16);
            if (cVar7 == '\0') goto LAB_146d4e56830;
            if (uVar23 != 0) {
              lVar10 = local_1f4 + (ulonglong)uVar26 * 2;
              if (uVar19 < 0x10) {
                uVar18 = 0;
              }
              else if (lVar10 - 0x146d4e635d8U < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar22 = 0;
                uVar18 = (ulonglong)(uVar19 & 0xfffffff8);
                do {
                  uVar35 = *(undefined4 *)(uVar22 + 0x146d4e635dc);
                  uVar36 = *(undefined4 *)(uVar22 + 0x146d4e635e0);
                  uVar39 = *(undefined4 *)(uVar22 + 0x146d4e635e4);
                  puVar15 = (undefined4 *)(lVar10 + uVar22);
                  *puVar15 = *(undefined4 *)(&DAT_146d4e635d8 + uVar22);
                  puVar15[1] = uVar35;
                  puVar15[2] = uVar36;
                  puVar15[3] = uVar39;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar18 == uVar23) goto LAB_146d4e55702;
              }
              do {
                *(undefined2 *)(lVar10 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_146d4e635d8 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar23 != uVar18);
            }
LAB_146d4e55702:
            *(uint *)(local_1f4 + -4) = uVar20;
            *(undefined2 *)(local_1f4 + (ulonglong)uVar20 * 2) = 0;
          }
          (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,CONCAT44(uVar34,uVar33),2);
          FUN_146d4e407d0(&local_278,&DAT_146d4e6853c,1,0x146d4e65fa8);
          FUN_146d4e407d0(&local_1e8,&local_1f8,0);
          lVar10 = local_274;
          if (local_274 == 0) {
LAB_146d4e5585d:
            FUN_146d4e407d0(&local_f8,&local_1e8,0,0x146d4e65fc8);
            FUN_146d4e407d0(&DAT_146d4e6853c,&local_f8,1,0x146d4e65fd8);
            FUN_146d4e400a0(&local_f8);
            FUN_146d4e400a0(&local_108);
            FUN_146d4e400a0(&local_258);
            FUN_146d4e400a0(&local_160);
            FUN_146d4e400a0(&local_248);
            FUN_146d4e400a0(&local_238);
            FUN_146d4e400a0(&local_150);
            FUN_146d4e400a0(&local_228);
            FUN_146d4e400a0(&local_218);
            FUN_146d4e400a0(&local_140);
            FUN_146d4e400a0(&local_208);
            FUN_146d4e400a0(&local_1f8);
            FUN_146d4e400a0(&local_278);
            FUN_146d4e400a0(&local_1e8);
            FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64ed8);
            FUN_146d4e407d0(&local_2b8,&local_2a0,0,0x146d4e64ee8);
            if (param_1 == 4) {
              if (_DAT_146d4e68464 == local_2b4) goto LAB_146d4e55ca0;
              if ((local_2b4 != 0) && (_DAT_146d4e68464 != 0)) {
                uVar26 = *(uint *)(_DAT_146d4e68464 + -4);
                uVar19 = *(uint *)(local_2b4 + -4);
                iVar8 = uVar26 - uVar19;
                if (uVar26 < uVar19) {
                  uVar19 = uVar26;
                }
                if (uVar19 != 0) {
                  uVar23 = 1;
                  do {
                    uVar2 = *(ushort *)(_DAT_146d4e68464 + -2 + uVar23 * 2);
                    uVar26 = (uint)uVar2;
                    uVar3 = *(ushort *)(local_2b4 + -2 + uVar23 * 2);
                    uVar16 = (uint)uVar3;
                    bVar24 = uVar2 == uVar3;
                    if (uVar19 <= uVar23) break;
                    uVar23 = uVar23 + 1;
                  } while (bVar24);
LAB_146d4e55a5e:
                  if (!bVar24) {
                    iVar8 = uVar26 - uVar16;
                  }
                }
LAB_146d4e55a68:
                if (iVar8 == 0) goto LAB_146d4e55ca0;
              }
LAB_146d4e55a70:
              (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x22);
              dVar28 = _DAT_146d4e68548;
              (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
              dVar29 = _DAT_146d4e68548;
              (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x24);
              dVar30 = _DAT_146d4e68548;
              puVar15 = local_2a8;
              dVar31 = 0.0;
              if ((dVar28 <= 0.0) || (dVar31 = 0.0, dVar29 <= 0.0)) {
LAB_146d4e55da7:
                dVar29 = dVar31;
                if ((char)local_290 != '\0') goto LAB_146d4e55db5;
LAB_146d4e563de:
                (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e5e890,0x1b);
                uVar33 = 0;
                uVar34 = 0;
                dVar28 = _DAT_146d4e68548;
                if (_DAT_146d4e68548 <= 0.0) {
                  dVar28 = _DAT_146d4e68518;
                }
                dVar28 = dVar28 * _DAT_146d4e5e5c0;
                cVar7 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,puVar15);
                uVar35 = 0;
                uVar36 = 0;
                uVar39 = 0;
                uVar40 = 0;
                if (cVar7 != '\0') {
                  (*(code *)0x7ff63a108280)(0x146d2d8aad8,0xc);
                  uVar39 = SUB84(_DAT_146d4e68548,0);
                  uVar40 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
                  (*(code *)0x7ff63a108280)(0x146d2d8aad8,0xd);
                  uVar35 = SUB84(_DAT_146d4e68548,0);
                  uVar36 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
                  (*(code *)0x7ff63a108280)(0x146d2d8aad8,7);
                  uVar33 = SUB84(_DAT_146d4e68548,0);
                  uVar34 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
                }
                dVar30 = (double)((ulonglong)((double)CONCAT44(uVar34,uVar33) - dVar29) &
                                 _DAT_146d4e5e5d0);
                if ((((dVar28 < (double)((ulonglong)((double)CONCAT44(uVar38,uVar37) - dVar27) &
                                        _DAT_146d4e5e5d0)) ||
                     (dVar28 < (double)((ulonglong)((double)CONCAT44(uVar40,uVar39) - dVar5) &
                                       _DAT_146d4e5e5d0))) ||
                    (dVar28 < (double)((ulonglong)((double)CONCAT44(uVar36,uVar35) - local_1a8) &
                                      _DAT_146d4e5e5d0))) || (_DAT_146d4e5e5a8 < dVar30)) {
                  if (_DAT_146d4e5e5a8 < dVar30) {
                    cVar7 = FUN_146d4e58090(puVar15);
                    if (cVar7 != '\0') goto LAB_146d4e55db5;
                  }
                  else {
                    cVar7 = FUN_146d4e4d600(puVar15,dVar27,dVar5);
                    if (cVar7 == '\0') {
                      FUN_146d4e4b940();
                      FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64f08);
                      FUN_146d4e57d40(param_1);
                      puVar41 = &local_288;
                      FUN_146d4e407d0(puVar41,&DAT_146d4e6853c,1,0x146d4e64f18);
                      uVar42 = 0x560015;
                      uVar43 = 0x146d4e60cf8;
                      uVar17 = 0x146d4e60ca0;
                      uVar21 = 0x146d4e60cd0;
                    }
                    else {
                      FUN_146d4e58fa0(param_1,dVar27,dVar5,dVar29);
                      (*(code *)0x7ff63a0fcc50)(0x146d2d8aad8,*(undefined8 *)(local_130 + 9),3);
                      FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64f28);
                      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
                      puVar15 = &local_288;
                      FUN_146d4e407d0(puVar15,&DAT_146d4e6853c,1,0x146d4e64f38);
                      FUN_146d4e57d40(param_1);
                      puVar41 = &local_268;
                      FUN_146d4e407d0(puVar41,&DAT_146d4e6853c,1,0x146d4e64f48);
                      uVar42 = 0x590008;
                      uVar43 = 0x146d4e60da8;
                      uVar17 = 0x146d4e60d30;
                      uVar21 = 0x146d4e60d58;
                    }
                    (*(code *)0x7ff63a0e49f0)
                              (0x146d2d8aad8,2,6,0x590008,uVar17,CONCAT44(uVar25,0x590008),puVar41,
                               0x590008,uVar21,uVar42,puVar15,0x590008,uVar43,0x590008,&local_2a0);
                  }
                }
              }
              else {
                dVar29 = (double)FUN_146d4e59600(0x146d4e68528);
                dVar28 = dVar28 + _DAT_146d4e5e5b0;
                puVar15 = local_2a8;
                dVar31 = 0.0;
                if (dVar29 < dVar28) goto LAB_146d4e55da7;
                (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x2a);
                if (_DAT_146d4e68548 <= 0.0) {
                  (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x25);
                }
                puVar15 = local_2a8;
                dVar31 = 0.0;
                if (_DAT_146d4e68548 <= 0.0) goto LAB_146d4e55da7;
                local_1e8 = 0;
                uStack_1e4 = 0;
                dVar32 = _DAT_146d4e68548 * _DAT_146d4e5e5b8;
                puVar41 = &local_1e8;
                cVar7 = (*(code *)0x7ff63a108d40)
                                  (0x146d2d8aad8,param_1 != 4,0x146d4e68528,dVar29,dVar27,&local_1e8
                                  );
                uVar25 = (undefined4)((ulonglong)puVar41 >> 0x20);
                if (((cVar7 == '\0') || ((double)CONCAT44(uStack_1e4,local_1e8) <= 0.0)) ||
                   (dVar32 < (double)CONCAT44(uStack_1e4,local_1e8))) {
                  puVar15 = local_2a8;
                  dVar31 = 0.0;
                  dVar6 = dVar29;
                  if (dVar30 <= 0.0) goto LAB_146d4e55da7;
                  do {
                    dVar6 = dVar6 - dVar30;
                    puVar15 = local_2a8;
                    dVar31 = 0.0;
                    if (dVar6 < dVar28) goto LAB_146d4e55da7;
                    uVar25 = (undefined4)((ulonglong)puVar41 >> 0x20);
                    dVar29 = (double)FUN_146d4e59600(0x146d4e68528);
                    puVar15 = local_2a8;
                    dVar31 = 0.0;
                    if (dVar29 < dVar28) goto LAB_146d4e55da7;
                    local_1e8 = 0;
                    uStack_1e4 = 0;
                    puVar41 = &local_1e8;
                    cVar7 = (*(code *)0x7ff63a108d40)
                                      (0x146d2d8aad8,param_1 != 4,0x146d4e68528,dVar29,dVar27,
                                       &local_1e8);
                    uVar25 = (undefined4)((ulonglong)puVar41 >> 0x20);
                  } while (((cVar7 == '\0') || ((double)CONCAT44(uStack_1e4,local_1e8) <= 0.0)) ||
                          (dVar32 < (double)CONCAT44(uStack_1e4,local_1e8)));
                }
                puVar15 = local_2a8;
                if ((local_164 != 1) || (dVar29 <= 0.0)) {
                  if (0.0 < dVar29) goto LAB_146d4e563bc;
                }
                else {
                  dVar28 = (double)FUN_146d4e57f60();
                  dVar31 = 0.0;
                  if ((0.0 < dVar28 && _DAT_146d4e5e5a8 + dVar29 < dVar28) ||
                     (dVar31 = dVar29, dVar29 <= 0.0)) goto LAB_146d4e55da7;
LAB_146d4e563bc:
                  FUN_146d4e58020(param_1);
                }
                if ((char)local_290 == '\0') goto LAB_146d4e563de;
LAB_146d4e55db5:
                if (dVar29 <= 0.0) {
                  FUN_146d4e53740(param_1);
                  FUN_146d4e407d0(&DAT_146d4e683c0,0x146d4e60c58,0,0x146d4e64f58);
                  FUN_146d4e595b0(param_1,&local_2b8);
                  local_190 = 0;
                  local_18c = 0;
                  dVar28 = dVar29;
                  FUN_146d4e56b10(param_1,0x146d4e60df8,dVar27,dVar5,uVar42,dVar29);
                  uVar25 = (undefined4)((ulonglong)dVar28 >> 0x20);
                  FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64f68);
                  FUN_146d4e407d0(&local_190,&local_2a0,0,0x146d4e64f78);
                  cVar7 = FUN_146d4e57bf0(param_1,&local_190);
                  if (cVar7 != '\0') {
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar5,_DAT_146d4e68520);
                    FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64f88);
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
                    FUN_146d4e407d0(&local_288,&DAT_146d4e6853c,1,0x146d4e64f98);
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar29,2);
                    FUN_146d4e407d0(&local_268,&DAT_146d4e6853c,1,0x146d4e64fa8);
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,uVar42,2);
                    FUN_146d4e407d0(&local_128,&DAT_146d4e6853c,1,0x146d4e64fb8);
                    FUN_146d4e57d40(param_1);
                    FUN_146d4e407d0(&local_118,&DAT_146d4e6853c,1,0x146d4e64fc8);
                    (*(code *)0x7ff63a0e49f0)
                              (0x146d2d8aad8,2,9,0x590008,&local_118,CONCAT44(uVar25,0x590008),
                               0x146d4e60e98,0x590008,&local_128,0x590008,0x146d4e60ed8,0x590008,
                               &local_268,0x590008,0x146d4e60f10,0x590008,&local_288,0x590008,
                               0x146d4e60c08,0x590008,&local_2a0);
                  }
                  puVar15 = &local_190;
                }
                else {
                  local_1a0 = 0;
                  local_19c = 0;
                  FUN_146d4e42480();
                  FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64fd8);
                  FUN_146d4e407d0(&local_1a0,&local_2a0,0,0x146d4e64fe8);
                  if (param_1 == 4) {
                    pcVar12 = FUN_146d4e4db20;
                  }
                  else {
                    pcVar12 = FUN_146d4e4dc20;
                  }
                  cVar7 = (*pcVar12)(SUB84(dVar29,0),dVar27,dVar5,local_1a8,&local_1a0);
                  if (cVar7 == '\0') {
                    FUN_146d4e4b940();
                    FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64ff8);
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
                    FUN_146d4e407d0(&local_288,&DAT_146d4e6853c,1,0x146d4e65008);
                    FUN_146d4e57d40(param_1);
                    FUN_146d4e407d0(&local_268,&DAT_146d4e6853c,1,0x146d4e65018);
                    uVar21 = 0x146d4e60cf8;
                    uVar17 = 0x146d4e60f50;
                  }
                  else {
                    FUN_146d4e58fa0(param_1,dVar27,dVar5,dVar29);
                    (*(code *)0x7ff63a0fcc50)(0x146d2d8aad8,*(undefined8 *)(local_130 + 9),3);
                    FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e65028);
                    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
                    FUN_146d4e407d0(&local_288,&DAT_146d4e6853c,1,0x146d4e65038);
                    FUN_146d4e57d40(param_1);
                    FUN_146d4e407d0(&local_268,&DAT_146d4e6853c,1,0x146d4e65048);
                    uVar21 = 0x146d4e60da8;
                    uVar17 = 0x146d4e60f80;
                  }
                  (*(code *)0x7ff63a0e49f0)
                            (0x146d2d8aad8,2,6,0x590008,uVar17,CONCAT44(uVar25,0x590008),&local_268,
                             0x590008,0x146d4e5f1c8,0x590008,&local_288,0x590008,uVar21,0x590008,
                             &local_2a0);
                  puVar15 = &local_1a0;
                }
                FUN_146d4e400a0(puVar15);
              }
            }
            else {
              if (_DAT_146d4e68474 != local_2b4) {
                if ((local_2b4 != 0) && (_DAT_146d4e68474 != 0)) {
                  uVar26 = *(uint *)(_DAT_146d4e68474 + -4);
                  uVar19 = *(uint *)(local_2b4 + -4);
                  iVar8 = uVar26 - uVar19;
                  if (uVar26 < uVar19) {
                    uVar19 = uVar26;
                  }
                  if (uVar19 != 0) {
                    uVar23 = 1;
                    do {
                      uVar2 = *(ushort *)(_DAT_146d4e68474 + -2 + uVar23 * 2);
                      uVar26 = (uint)uVar2;
                      uVar3 = *(ushort *)(local_2b4 + -2 + uVar23 * 2);
                      uVar16 = (uint)uVar3;
                      bVar24 = uVar2 == uVar3;
                      if (uVar19 <= uVar23) break;
                      uVar23 = uVar23 + 1;
                    } while (bVar24);
                    goto LAB_146d4e55a5e;
                  }
                  goto LAB_146d4e55a68;
                }
                goto LAB_146d4e55a70;
              }
LAB_146d4e55ca0:
              FUN_146d4e53740();
              FUN_146d4e407d0(&DAT_146d4e683c0,0x146d4e60c58,0,0x146d4e64ef8);
            }
            puVar15 = &local_2b8;
            goto LAB_146d4e53f2c;
          }
          uVar26 = *(uint *)(local_274 + -4);
          uVar23 = (ulonglong)uVar26;
          lVar14 = CONCAT44(uStack_1e0,uStack_1e4);
          if ((uVar23 == 0) && (lVar14 != 0)) goto LAB_146d4e5585d;
          if (lVar14 == 0) {
            uVar19 = 0;
          }
          else {
            uVar19 = *(uint *)(lVar14 + -4);
          }
          cVar7 = FUN_146d4e40100(&local_1e8);
          if (cVar7 != '\0') {
            lVar14 = CONCAT44(uStack_1e0,uStack_1e4);
            if (uVar23 != 0) {
              lVar1 = lVar14 + (ulonglong)uVar19 * 2;
              if (uVar26 < 0x10) {
                uVar18 = 0;
              }
              else if ((ulonglong)(lVar1 - lVar10) < 0x20) {
                uVar18 = 0;
              }
              else {
                uVar22 = 0;
                uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  puVar15 = (undefined4 *)(lVar10 + uVar22);
                  uVar33 = puVar15[1];
                  uVar34 = puVar15[2];
                  uVar35 = puVar15[3];
                  puVar41 = (undefined4 *)(lVar1 + uVar22);
                  *puVar41 = *puVar15;
                  puVar41[1] = uVar33;
                  puVar41[2] = uVar34;
                  puVar41[3] = uVar35;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar18 == uVar23) goto LAB_146d4e55852;
              }
              do {
                *(undefined2 *)(lVar1 + uVar18 * 2) = *(undefined2 *)(lVar10 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar23 != uVar18);
            }
LAB_146d4e55852:
            *(uint *)(lVar14 + -4) = uVar26 + uVar19;
            *(undefined2 *)(lVar14 + (ulonglong)(uVar26 + uVar19) * 2) = 0;
            goto LAB_146d4e5585d;
          }
        }
        else {
          if (local_254 != 0) {
            uVar18 = (ulonglong)*(uint *)(local_254 + -4);
          }
          uVar19 = _DAT_146d4e635d4 + (int)uVar18;
          cVar7 = FUN_146d4e40100(&local_258);
          if (cVar7 != '\0') {
            if (uVar23 != 0) {
              lVar10 = local_254 + uVar18 * 2;
              if ((uVar26 < 0x10) || (lVar10 - 0x146d4e635d8U < 0x20)) {
                uVar18 = 0;
              }
              else {
                uVar22 = 0;
                uVar18 = (ulonglong)(uVar26 & 0xfffffff8);
                do {
                  uVar35 = *(undefined4 *)(uVar22 + 0x146d4e635dc);
                  uVar36 = *(undefined4 *)(uVar22 + 0x146d4e635e0);
                  uVar39 = *(undefined4 *)(uVar22 + 0x146d4e635e4);
                  puVar15 = (undefined4 *)(lVar10 + uVar22);
                  *puVar15 = *(undefined4 *)(&DAT_146d4e635d8 + uVar22);
                  puVar15[1] = uVar35;
                  puVar15[2] = uVar36;
                  puVar15[3] = uVar39;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar23 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar18 == uVar23) goto LAB_146d4e54af2;
              }
              do {
                *(undefined2 *)(lVar10 + uVar18 * 2) =
                     *(undefined2 *)(&DAT_146d4e635d8 + uVar18 * 2);
                uVar18 = uVar18 + 1;
              } while (uVar23 != uVar18);
            }
LAB_146d4e54af2:
            *(uint *)(local_254 + -4) = uVar19;
            *(undefined2 *)(local_254 + (ulonglong)uVar19 * 2) = 0;
            goto LAB_146d4e54afd;
          }
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a0403000001f9);
LAB_146d4e567f0:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2e0404000001f9);
LAB_146d4e56810:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c0405000001f9);
LAB_146d4e56830:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2d0406000001f9);
LAB_146d4e56850:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x300403000001f9);
LAB_146d4e56870:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x340404000001f9);
LAB_146d4e56890:
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x320405000001f9);
        }
        (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x330406000001f9);
      }
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3108be000001f7);
LAB_146d4e568f0:
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2508c2000001f7);
      pcVar12 = (code *)swi(3);
      (*pcVar12)();
      return;
    }
    FUN_146d4e53740(param_1);
    local_180 = 0;
    local_17c = 0;
    uVar25 = 0;
    FUN_146d4e56b10(param_1,0x146d4e60b38,dVar27,dVar28,0,0);
    FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64e88);
    FUN_146d4e407d0(&local_180,&local_2a0,0,0x146d4e64e98);
    cVar7 = FUN_146d4e57bf0(param_1,&local_180);
    if (cVar7 != '\0') {
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar28,_DAT_146d4e68520);
      FUN_146d4e407d0(&local_2a0,&DAT_146d4e6853c,1,0x146d4e64ea8);
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar27,_DAT_146d4e68520);
      FUN_146d4e407d0(&local_288,&DAT_146d4e6853c,1,0x146d4e64eb8);
      local_1e8 = 0;
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      if (param_1 == 4) {
        uVar17 = 0x146d4e61900;
        uVar21 = 0x146d4e65598;
      }
      else {
        uVar17 = 0x146d4e61930;
        uVar21 = 0x146d4e655a8;
      }
      FUN_146d4e407d0(&local_1e8,uVar17,0,uVar21);
      FUN_146d4e407d0(&DAT_146d4e6853c,&local_1e8,1,0x146d4e655b8);
      FUN_146d4e400a0(&local_1e8);
      FUN_146d4e407d0(&local_268,&DAT_146d4e6853c,1,0x146d4e64ec8);
      (*(code *)0x7ff63a0e49f0)
                (0x146d2d8aad8,2,5,0x590008,&local_268,CONCAT44(uVar25,0x590008),0x146d4e60be0,
                 0x590008,&local_288,0x590008,0x146d4e60c08,0x590008,&local_2a0);
    }
    puVar15 = &local_180;
  }
LAB_146d4e53f2c:
  FUN_146d4e400a0(puVar15);
LAB_146d4e53f2f:
  FUN_146d4e400a0(&local_2a0);
  FUN_146d4e400a0(&local_288);
  FUN_146d4e400a0(&local_268);
  FUN_146d4e400a0(&local_128);
  FUN_146d4e400a0(&local_118);
  return;
}



/* Address: 146d4e56920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_146d4e56920(double param_1)

{
  longlong lVar1;
  double dVar2;
  code *pcVar3;
  uint uVar4;
  byte bVar5;
  ulonglong uVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x1b);
  uVar10 = SUB84(_DAT_146d4e68548,0);
  uVar11 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
  if (_DAT_146d4e68548 <= 0.0) {
    (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x10);
    uVar10 = SUB84(_DAT_146d4e68548,0);
    uVar11 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
  }
  uVar4 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e68528,0x11);
  if ((int)uVar4 < 1) {
    uVar4 = _DAT_146d4e68520;
  }
  if (((double)CONCAT44(uVar11,uVar10) == 0.0) && (!NAN((double)CONCAT44(uVar11,uVar10)))) {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2d0522000001f7);
    pcVar3 = (code *)swi(3);
    dVar8 = (double)(*pcVar3)();
    return dVar8;
  }
  param_1 = param_1 / (double)CONCAT44(uVar11,uVar10);
  uVar7 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar7 - 0x3ff;
  dVar8 = param_1;
  if ((ulonglong)uVar7 < 0x433) {
    if (uVar7 < 0x3ff) {
      dVar8 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar8 = (double)((ulonglong)param_1 & 0x8000000000000000);
      }
    }
    else {
      bVar5 = (byte)lVar1;
      if (((longlong)param_1 << (bVar5 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar8 = (double)((0x8000000000000U >> (bVar5 & 0x3f)) + (longlong)param_1 &
                        -0x10000000000000 >> (bVar5 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar8 = param_1 + param_1;
  }
  dVar8 = (double)CONCAT44(uVar11,uVar10) * dVar8;
  if ((longlong)dVar8 != -0x8000000000000000) {
    dVar9 = (double)(longlong)dVar8;
    uVar6 = 0xb;
    if (uVar4 < 0xb) {
      uVar6 = (ulonglong)uVar4;
    }
    dVar2 = *(double *)(uVar6 * 8 + 0x146d4e5e750);
    dVar8 = (double)(longlong)
                    ((dVar8 - dVar9) * dVar2 +
                    *(double *)((ulonglong)(0.0 < dVar8) * 8 + 0x146d4e5e5e0)) / dVar2 + dVar9;
  }
  return dVar8;
}



/* Address: 146d4e56b10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e56b10(undefined4 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6)

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
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  uint uVar16;
  undefined4 local_168;
  longlong local_164;
  undefined4 local_158;
  longlong local_154;
  undefined4 local_148;
  longlong local_144;
  undefined4 local_138;
  longlong local_134;
  undefined4 local_128;
  longlong local_124;
  undefined4 local_118;
  longlong local_114;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  longlong local_f4;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  longlong local_c4;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  local_d8 = 0;
  local_98 = 0;
  local_e8 = 0;
  local_f8 = 0;
  local_a8 = 0;
  local_108 = 0;
  local_118 = 0;
  local_b8 = 0;
  local_128 = 0;
  local_138 = 0;
  local_c8 = 0;
  local_148 = 0;
  local_158 = 0;
  local_168 = 0;
  local_88 = 0;
  local_78 = 0;
  local_d4 = 0;
  local_94 = 0;
  local_e4 = 0;
  local_f4 = 0;
  local_a4 = 0;
  local_104 = 0;
  local_114 = 0;
  local_b4 = 0;
  local_124 = 0;
  local_134 = 0;
  local_c4 = 0;
  local_144 = 0;
  local_154 = 0;
  local_164 = 0;
  local_84 = 0;
  local_74 = 0;
  uVar16 = 0;
  (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,param_1,0,0x20);
  FUN_146d4e407d0(&local_88,&DAT_146d4e6853c,1,0x146d4e65d28);
  FUN_146d4e407d0(&local_168,&local_88,0);
  uVar13 = _DAT_146d4e635d4;
  uVar11 = (ulonglong)_DAT_146d4e635d4;
  if ((uVar11 == 0) && (local_164 != 0)) {
LAB_146d4e56dbd:
    FUN_146d4e407d0(&local_158,&local_168,0);
    lVar1 = *(longlong *)(param_2 + 4);
    if (lVar1 != 0) {
      uVar16 = *(uint *)(lVar1 + -4);
      uVar11 = (ulonglong)uVar16;
      if ((uVar11 == 0) && (local_154 != 0)) goto LAB_146d4e56f2d;
      if (local_154 == 0) {
        uVar10 = 0;
        uVar13 = uVar16;
      }
      else {
        uVar10 = (ulonglong)*(uint *)(local_154 + -4);
        uVar13 = uVar16 + *(uint *)(local_154 + -4);
      }
      cVar9 = FUN_146d4e40100(&local_158);
      if (cVar9 != '\0') {
        if (uVar11 != 0) {
          lVar2 = local_154 + uVar10 * 2;
          if (uVar16 < 0x10) {
            uVar10 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar15 = 0;
            uVar10 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar2 + uVar15);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar10 == uVar11) goto LAB_146d4e56f22;
          }
          do {
            *(undefined2 *)(lVar2 + uVar10 * 2) = *(undefined2 *)(lVar1 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar11 != uVar10);
        }
LAB_146d4e56f22:
        *(uint *)(local_154 + -4) = uVar13;
        *(undefined2 *)(local_154 + (ulonglong)uVar13 * 2) = 0;
        goto LAB_146d4e56f2d;
      }
      goto LAB_146d4e57b40;
    }
LAB_146d4e56f2d:
    uVar16 = 0;
    FUN_146d4e407d0(&local_148,&local_158,0);
    uVar13 = _DAT_146d4e635d4;
    uVar11 = (ulonglong)_DAT_146d4e635d4;
    if ((uVar11 != 0) || (local_144 == 0)) {
      if (local_144 != 0) {
        uVar16 = *(uint *)(local_144 + -4);
      }
      uVar12 = _DAT_146d4e635d4 + uVar16;
      cVar9 = FUN_146d4e40100(&local_148);
      if (cVar9 == '\0') goto LAB_146d4e57ac0;
      if (uVar11 != 0) {
        lVar1 = local_144 + (ulonglong)uVar16 * 2;
        if ((uVar13 < 0x10) || (lVar1 - 0x146d4e635d8U < 0x20)) {
          uVar10 = 0;
        }
        else {
          uVar15 = 0;
          uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar15 + 0x146d4e635dc);
            uVar7 = *(undefined4 *)(uVar15 + 0x146d4e635e0);
            uVar8 = *(undefined4 *)(uVar15 + 0x146d4e635e4);
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar15);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar10 == uVar11) goto LAB_146d4e57002;
        }
        do {
          *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar11 != uVar10);
      }
LAB_146d4e57002:
      *(uint *)(local_144 + -4) = uVar12;
      *(undefined2 *)(local_144 + (ulonglong)uVar12 * 2) = 0;
    }
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_3,_DAT_146d4e68520);
    FUN_146d4e407d0(&local_c8,&DAT_146d4e6853c,1,0x146d4e65d68);
    FUN_146d4e407d0(&local_138,&local_148,0);
    lVar1 = local_c4;
    if (local_c4 != 0) {
      uVar16 = *(uint *)(local_c4 + -4);
      uVar11 = (ulonglong)uVar16;
      if ((uVar11 == 0) && (local_134 != 0)) goto LAB_146d4e571cd;
      if (local_134 == 0) {
        uVar13 = 0;
        uVar12 = uVar16;
      }
      else {
        uVar13 = *(uint *)(local_134 + -4);
        uVar12 = uVar16 + uVar13;
      }
      cVar9 = FUN_146d4e40100(&local_138);
      if (cVar9 != '\0') {
        if (uVar11 != 0) {
          lVar2 = local_134 + (ulonglong)uVar13 * 2;
          if (uVar16 < 0x10) {
            uVar10 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar15 = 0;
            uVar10 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar2 + uVar15);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar10 == uVar11) goto LAB_146d4e571c2;
          }
          do {
            *(undefined2 *)(lVar2 + uVar10 * 2) = *(undefined2 *)(lVar1 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar11 != uVar10);
        }
LAB_146d4e571c2:
        *(uint *)(local_134 + -4) = uVar12;
        *(undefined2 *)(local_134 + (ulonglong)uVar12 * 2) = 0;
        goto LAB_146d4e571cd;
      }
      goto LAB_146d4e57b60;
    }
LAB_146d4e571cd:
    uVar11 = 0;
    FUN_146d4e407d0(&local_128,&local_138,0);
    uVar16 = _DAT_146d4e635d4;
    uVar10 = (ulonglong)_DAT_146d4e635d4;
    if ((uVar10 != 0) || (local_124 == 0)) {
      if (local_124 != 0) {
        uVar11 = (ulonglong)*(uint *)(local_124 + -4);
      }
      uVar13 = _DAT_146d4e635d4 + (int)uVar11;
      cVar9 = FUN_146d4e40100(&local_128);
      if (cVar9 == '\0') goto LAB_146d4e57ae0;
      if (uVar10 != 0) {
        lVar1 = local_124 + uVar11 * 2;
        if ((uVar16 < 0x10) || (lVar1 - 0x146d4e635d8U < 0x20)) {
          uVar11 = 0;
        }
        else {
          uVar15 = 0;
          uVar11 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar15 + 0x146d4e635dc);
            uVar7 = *(undefined4 *)(uVar15 + 0x146d4e635e0);
            uVar8 = *(undefined4 *)(uVar15 + 0x146d4e635e4);
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar15);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar10 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar11 == uVar10) goto LAB_146d4e572a2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar11 * 2);
          uVar11 = uVar11 + 1;
        } while (uVar10 != uVar11);
      }
LAB_146d4e572a2:
      *(uint *)(local_124 + -4) = uVar13;
      *(undefined2 *)(local_124 + (ulonglong)uVar13 * 2) = 0;
    }
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_4,_DAT_146d4e68520);
    FUN_146d4e407d0(&local_b8,&DAT_146d4e6853c,1,0x146d4e65d98);
    FUN_146d4e407d0(&local_118,&local_128,0);
    lVar1 = local_b4;
    if (local_b4 != 0) {
      uVar16 = *(uint *)(local_b4 + -4);
      uVar11 = (ulonglong)uVar16;
      if ((uVar11 == 0) && (local_114 != 0)) goto LAB_146d4e5745d;
      if (local_114 == 0) {
        uVar10 = 0;
        uVar13 = uVar16;
      }
      else {
        uVar10 = (ulonglong)*(uint *)(local_114 + -4);
        uVar13 = uVar16 + *(uint *)(local_114 + -4);
      }
      cVar9 = FUN_146d4e40100(&local_118);
      if (cVar9 != '\0') {
        if (uVar11 != 0) {
          lVar2 = local_114 + uVar10 * 2;
          if (uVar16 < 0x10) {
            uVar10 = 0;
          }
          else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar15 = 0;
            uVar10 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              uVar6 = puVar3[1];
              uVar7 = puVar3[2];
              uVar8 = puVar3[3];
              puVar4 = (undefined4 *)(lVar2 + uVar15);
              *puVar4 = *puVar3;
              puVar4[1] = uVar6;
              puVar4[2] = uVar7;
              puVar4[3] = uVar8;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar10 == uVar11) goto LAB_146d4e57452;
          }
          do {
            *(undefined2 *)(lVar2 + uVar10 * 2) = *(undefined2 *)(lVar1 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar11 != uVar10);
        }
LAB_146d4e57452:
        *(uint *)(local_114 + -4) = uVar13;
        *(undefined2 *)(local_114 + (ulonglong)uVar13 * 2) = 0;
        goto LAB_146d4e5745d;
      }
      goto LAB_146d4e57b80;
    }
LAB_146d4e5745d:
    uVar16 = 0;
    FUN_146d4e407d0(&local_108,&local_118,0);
    uVar13 = _DAT_146d4e635d4;
    uVar11 = (ulonglong)_DAT_146d4e635d4;
    if ((uVar11 != 0) || (local_104 == 0)) {
      if (local_104 != 0) {
        uVar16 = *(uint *)(local_104 + -4);
      }
      uVar12 = _DAT_146d4e635d4 + uVar16;
      cVar9 = FUN_146d4e40100(&local_108);
      if (cVar9 == '\0') goto LAB_146d4e57b00;
      if (uVar11 != 0) {
        lVar1 = local_104 + (ulonglong)uVar16 * 2;
        if ((uVar13 < 0x10) || (lVar1 - 0x146d4e635d8U < 0x20)) {
          uVar10 = 0;
        }
        else {
          uVar15 = 0;
          uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar15 + 0x146d4e635dc);
            uVar7 = *(undefined4 *)(uVar15 + 0x146d4e635e0);
            uVar8 = *(undefined4 *)(uVar15 + 0x146d4e635e4);
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar15);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar10 == uVar11) goto LAB_146d4e57542;
        }
        do {
          *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar11 != uVar10);
      }
LAB_146d4e57542:
      *(uint *)(local_104 + -4) = uVar12;
      *(undefined2 *)(local_104 + (ulonglong)uVar12 * 2) = 0;
    }
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_5,4);
    FUN_146d4e407d0(&local_a8,&DAT_146d4e6853c,1,0x146d4e65dc8);
    FUN_146d4e407d0(&local_f8,&local_108);
    lVar1 = local_a4;
    if (local_a4 == 0) {
LAB_146d4e5770d:
      uVar16 = 0;
      FUN_146d4e407d0(&local_e8,&local_f8,0,0x146d4e65de8);
      uVar13 = _DAT_146d4e635d4;
      uVar11 = (ulonglong)_DAT_146d4e635d4;
      if ((uVar11 != 0) || (local_e4 == 0)) {
        if (local_e4 != 0) {
          uVar16 = *(uint *)(local_e4 + -4);
        }
        uVar14 = _DAT_146d4e635d4 + uVar16;
        uVar12 = 0x104;
        if ((0x103 < uVar14) &&
           ((0x7ffffffd < uVar14 || (uVar12 = (uVar14 >> 2) + uVar14, 0x7ffffffd < uVar12)))) {
          uVar12 = 0x7ffffffe;
        }
        cVar9 = FUN_146d4e40100(&local_e8,uVar12);
        if (cVar9 == '\0') goto LAB_146d4e57b20;
        if (uVar11 != 0) {
          lVar1 = local_e4 + (ulonglong)uVar16 * 2;
          if (uVar13 < 0x10) {
            uVar10 = 0;
          }
          else if (lVar1 - 0x146d4e635d8U < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar15 = 0;
            uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
            do {
              uVar6 = *(undefined4 *)(uVar15 + 0x146d4e635dc);
              uVar7 = *(undefined4 *)(uVar15 + 0x146d4e635e0);
              uVar8 = *(undefined4 *)(uVar15 + 0x146d4e635e4);
              puVar3 = (undefined4 *)(lVar1 + uVar15);
              *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar15);
              puVar3[1] = uVar6;
              puVar3[2] = uVar7;
              puVar3[3] = uVar8;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar10 == uVar11) goto LAB_146d4e57832;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar11 != uVar10);
        }
LAB_146d4e57832:
        *(uint *)(local_e4 + -4) = uVar14;
        *(undefined2 *)(local_e4 + (ulonglong)uVar14 * 2) = 0;
      }
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_6,4);
      FUN_146d4e407d0(&local_98,&DAT_146d4e6853c,1,0x146d4e65df8);
      FUN_146d4e407d0(&local_d8,&local_e8,0);
      lVar1 = local_94;
      if (local_94 == 0) goto LAB_146d4e579ad;
      uVar16 = *(uint *)(local_94 + -4);
      uVar11 = (ulonglong)uVar16;
      if ((uVar11 == 0) && (local_d4 != 0)) goto LAB_146d4e579ad;
      if (local_d4 == 0) {
        uVar10 = 0;
        uVar13 = uVar16;
      }
      else {
        uVar10 = (ulonglong)*(uint *)(local_d4 + -4);
        uVar13 = uVar16 + *(uint *)(local_d4 + -4);
      }
      cVar9 = FUN_146d4e40100(&local_d8);
      if (cVar9 == '\0') goto LAB_146d4e57bc0;
      if (uVar11 != 0) {
        lVar2 = local_d4 + uVar10 * 2;
        if (uVar16 < 0x10) {
          uVar10 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
          uVar10 = 0;
        }
        else {
          uVar15 = 0;
          uVar10 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar2 + uVar15);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar10 == uVar11) goto LAB_146d4e579a2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar10 * 2) = *(undefined2 *)(lVar1 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar11 != uVar10);
      }
LAB_146d4e579a2:
      *(uint *)(local_d4 + -4) = uVar13;
      *(undefined2 *)(local_d4 + (ulonglong)uVar13 * 2) = 0;
LAB_146d4e579ad:
      FUN_146d4e407d0(&local_78,&local_d8,0,0x146d4e65e18);
      FUN_146d4e407d0(&DAT_146d4e6853c,&local_78,1,0x146d4e65e28);
      FUN_146d4e400a0(&local_78);
      FUN_146d4e400a0(&local_88);
      FUN_146d4e400a0(&local_168);
      FUN_146d4e400a0(&local_158);
      FUN_146d4e400a0(&local_148);
      FUN_146d4e400a0(&local_c8);
      FUN_146d4e400a0(&local_138);
      FUN_146d4e400a0(&local_128);
      FUN_146d4e400a0(&local_b8);
      FUN_146d4e400a0(&local_118);
      FUN_146d4e400a0(&local_108);
      FUN_146d4e400a0(&local_a8);
      FUN_146d4e400a0(&local_f8);
      FUN_146d4e400a0(&local_e8);
      FUN_146d4e400a0(&local_98);
      FUN_146d4e400a0(&local_d8);
      return;
    }
    uVar16 = *(uint *)(local_a4 + -4);
    uVar11 = (ulonglong)uVar16;
    if ((uVar11 == 0) && (local_f4 != 0)) goto LAB_146d4e5770d;
    if (local_f4 == 0) {
      uVar13 = 0;
      uVar12 = uVar16;
    }
    else {
      uVar13 = *(uint *)(local_f4 + -4);
      uVar12 = uVar16 + uVar13;
    }
    cVar9 = FUN_146d4e40100(&local_f8);
    if (cVar9 != '\0') {
      if (uVar11 != 0) {
        lVar2 = local_f4 + (ulonglong)uVar13 * 2;
        if (uVar16 < 0x10) {
          uVar10 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
          uVar10 = 0;
        }
        else {
          uVar15 = 0;
          uVar10 = (ulonglong)(uVar16 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            uVar6 = puVar3[1];
            uVar7 = puVar3[2];
            uVar8 = puVar3[3];
            puVar4 = (undefined4 *)(lVar2 + uVar15);
            *puVar4 = *puVar3;
            puVar4[1] = uVar6;
            puVar4[2] = uVar7;
            puVar4[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar10 == uVar11) goto LAB_146d4e57702;
        }
        do {
          *(undefined2 *)(lVar2 + uVar10 * 2) = *(undefined2 *)(lVar1 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar11 != uVar10);
      }
LAB_146d4e57702:
      *(uint *)(local_f4 + -4) = uVar12;
      *(undefined2 *)(local_f4 + (ulonglong)uVar12 * 2) = 0;
      goto LAB_146d4e5770d;
    }
  }
  else {
    if (local_164 != 0) {
      uVar16 = *(uint *)(local_164 + -4);
    }
    uVar12 = _DAT_146d4e635d4 + uVar16;
    cVar9 = FUN_146d4e40100(&local_168);
    if (cVar9 != '\0') {
      if (uVar11 != 0) {
        lVar1 = local_164 + (ulonglong)uVar16 * 2;
        if ((uVar13 < 0x10) || (lVar1 - 0x146d4e635d8U < 0x20)) {
          uVar10 = 0;
        }
        else {
          uVar15 = 0;
          uVar10 = (ulonglong)(uVar13 & 0xfffffff8);
          do {
            uVar6 = *(undefined4 *)(uVar15 + 0x146d4e635dc);
            uVar7 = *(undefined4 *)(uVar15 + 0x146d4e635e0);
            uVar8 = *(undefined4 *)(uVar15 + 0x146d4e635e4);
            puVar3 = (undefined4 *)(lVar1 + uVar15);
            *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar15);
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            uVar15 = uVar15 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
          if (uVar10 == uVar11) goto LAB_146d4e56db2;
        }
        do {
          *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar10 * 2);
          uVar10 = uVar10 + 1;
        } while (uVar11 != uVar10);
      }
LAB_146d4e56db2:
      *(uint *)(local_164 + -4) = uVar12;
      *(undefined2 *)(local_164 + (ulonglong)uVar12 * 2) = 0;
      goto LAB_146d4e56dbd;
    }
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a03c4000001f9);
LAB_146d4e57ac0:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3903c4000001f9);
LAB_146d4e57ae0:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2e03c5000001f9);
LAB_146d4e57b00:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c03c6000001f9);
LAB_146d4e57b20:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2403c7000001f9);
LAB_146d4e57b40:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3003c4000001f9);
LAB_146d4e57b60:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3f03c4000001f9);
LAB_146d4e57b80:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3403c5000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3203c6000001f9);
LAB_146d4e57bc0:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a03c7000001f9);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



/* Address: 146d4e57aa0 */

void FUN_146d4e57aa0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a03c4000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3903c4000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2e03c5000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c03c6000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2403c7000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3003c4000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3f03c4000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3403c5000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3203c6000001f9);
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2a03c7000001f9);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 146d4e57bf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e57bf0(int param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  
  lVar5 = *(longlong *)(param_2 + 4);
  if (param_1 == 4) {
    if (_DAT_146d4e68424 == lVar5) {
      return 0;
    }
    if ((_DAT_146d4e68424 != 0) && (lVar5 != 0)) {
      uVar3 = *(uint *)(_DAT_146d4e68424 + -4);
      uVar4 = *(uint *)(lVar5 + -4);
      uVar8 = uVar4;
      if (uVar3 < uVar4) {
        uVar8 = uVar3;
      }
      iVar7 = uVar3 - uVar4;
      if (uVar8 != 0) {
        uVar10 = 1;
        do {
          uVar1 = *(ushort *)(_DAT_146d4e68424 + -2 + uVar10 * 2);
          uVar2 = *(ushort *)(lVar5 + -2 + uVar10 * 2);
          if (uVar8 <= uVar10) break;
          uVar10 = uVar10 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar7 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar7 == 0) {
        return 0;
      }
    }
    puVar6 = &DAT_146d4e68420;
    uVar9 = 0x146d4e65e38;
  }
  else {
    if (_DAT_146d4e68434 == lVar5) {
      return 0;
    }
    if ((_DAT_146d4e68434 != 0) && (lVar5 != 0)) {
      uVar3 = *(uint *)(_DAT_146d4e68434 + -4);
      uVar4 = *(uint *)(lVar5 + -4);
      uVar8 = uVar4;
      if (uVar3 < uVar4) {
        uVar8 = uVar3;
      }
      iVar7 = uVar3 - uVar4;
      if (uVar8 != 0) {
        uVar10 = 1;
        do {
          uVar1 = *(ushort *)(_DAT_146d4e68434 + -2 + uVar10 * 2);
          uVar2 = *(ushort *)(lVar5 + -2 + uVar10 * 2);
          if (uVar8 <= uVar10) break;
          uVar10 = uVar10 + 1;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar7 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar7 == 0) {
        return 0;
      }
    }
    puVar6 = &DAT_146d4e68430;
    uVar9 = 0x146d4e65e48;
  }
  FUN_146d4e407d0(puVar6,param_2,0,uVar9);
  return 1;
}



/* Address: 146d4e57d40 */

void FUN_146d4e57d40(int param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 local_20;
  undefined8 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (param_1 == 4) {
    uVar1 = 0x146d4e61900;
    uVar2 = 0x146d4e65598;
  }
  else {
    uVar1 = 0x146d4e61930;
    uVar2 = 0x146d4e655a8;
  }
  FUN_146d4e407d0(&local_20,uVar1,0,uVar2);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_20,1,0x146d4e655b8);
  FUN_146d4e400a0(&local_20);
  return;
}



/* Address: 146d4e57de0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e57de0(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = _DAT_146d4e68638;
  if (_DAT_146d4e68638 != 0) {
    if (_DAT_146d4e68638 == 1) {
      return 0;
    }
    (*(code *)0x7ff63a0c7370)(0,0x25);
    if (iVar1 - 2U < 9) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e57e53 */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)((ulonglong)(iVar1 - 2U) * 8 + 0x146d4e5e630))
                        (_DAT_146d4e68548,_DAT_146d4e5e5f0);
      return uVar2;
    }
  }
  return _DAT_146d4e68640;
}



/* Address: 146d4e57f60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_146d4e57f60(void)

{
  code *pcVar1;
  byte bVar2;
  longlong lVar3;
  double dVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x22);
  dVar9 = _DAT_146d4e68548;
  uVar11 = SUB84(_DAT_146d4e68548,0);
  uVar12 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
  if ((dVar9 <= 0.0) || (_DAT_146d4e68548 <= 0.0)) {
    return 0.0;
  }
  if (dVar9 <= _DAT_146d4e68650) {
    uVar11 = SUB84(_DAT_146d4e68650,0);
    uVar12 = (undefined4)((ulonglong)_DAT_146d4e68650 >> 0x20);
  }
  if (_DAT_146d4e68548 <= (double)CONCAT44(uVar12,uVar11)) {
    uVar11 = SUB84(_DAT_146d4e68548,0);
    uVar12 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
  }
  dVar9 = (double)CONCAT44(uVar12,uVar11);
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x22);
  dVar7 = _DAT_146d4e68548;
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x23);
  dVar10 = _DAT_146d4e68548;
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e68528,0x24);
  if (0.0 < _DAT_146d4e68548) {
    if ((_DAT_146d4e68548 == 0.0) && (!NAN(_DAT_146d4e68548))) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x340535000001f7);
      pcVar1 = (code *)swi(3);
      dVar9 = (double)(*pcVar1)();
      return dVar9;
    }
    dVar9 = dVar10;
    if ((double)CONCAT44(uVar12,uVar11) <= dVar10) {
      dVar9 = (double)CONCAT44(uVar12,uVar11);
    }
    dVar4 = dVar7;
    if (dVar7 <= dVar9) {
      dVar4 = dVar9;
    }
    dVar8 = (dVar4 - dVar7) / _DAT_146d4e68548 + _DAT_146d4e5e680;
    dVar4 = ABS(dVar8);
    uVar5 = (uint)((ulonglong)dVar4 >> 0x20);
    dVar9 = dVar8;
    if (uVar5 >> 0x14 < 0x3ff) {
      if ((dVar4 != 0.0) && (dVar9 = 0.0, (longlong)dVar8 < 0)) {
        dVar9 = _DAT_146d4e5e688;
      }
    }
    else if (((uVar5 >> 0x16 < 0x10d) &&
             (bVar2 = 0x33 - (char)((ulonglong)dVar4 >> 0x34),
             dVar6 = (double)(((ulonglong)dVar4 >> (bVar2 & 0x3f)) << (bVar2 & 0x3f)), dVar9 = dVar6
             , (longlong)dVar8 < 1)) &&
            (dVar9 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar4)) {
      dVar9 = dVar9 + _DAT_146d4e5e688;
    }
    dVar9 = dVar9 * _DAT_146d4e68548 + dVar7;
    if (dVar9 <= dVar10) {
      dVar10 = dVar9;
    }
    uVar5 = (uint)((ulonglong)_DAT_146d4e68548 >> 0x34) & 0x7ff;
    lVar3 = (ulonglong)uVar5 - 0x3ff;
    dVar4 = _DAT_146d4e68548;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar4 = (double)((ulonglong)_DAT_146d4e68548 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar3 != -1) {
          dVar4 = (double)((ulonglong)_DAT_146d4e68548 & 0x8000000000000000);
        }
      }
      else {
        bVar2 = (byte)lVar3;
        if (((longlong)_DAT_146d4e68548 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar4 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)_DAT_146d4e68548 &
                          -0x10000000000000 >> (bVar2 & 0x3f));
        }
      }
    }
    else if (lVar3 == 0x400) {
      dVar4 = _DAT_146d4e68548 + _DAT_146d4e68548;
    }
    dVar9 = dVar7;
    if (dVar7 <= dVar10) {
      dVar9 = dVar10;
    }
    if ((double)((ulonglong)(_DAT_146d4e68548 - dVar4) & _DAT_146d4e5e690) <= _DAT_146d4e5e680) {
      lVar3 = 0;
    }
    else {
      dVar7 = _DAT_146d4e68548 * _DAT_146d4e5e6a0;
      uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
      lVar3 = (ulonglong)uVar5 - 0x3ff;
      dVar10 = dVar7;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar3 != -1) {
            dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
          }
        }
        else {
          bVar2 = (byte)lVar3;
          if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                             -0x10000000000000 >> (bVar2 & 0x3f));
          }
        }
      }
      else if (lVar3 == 0x400) {
        dVar10 = dVar7 + dVar7;
      }
      lVar3 = 1;
      if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
        dVar7 = dVar7 * _DAT_146d4e5e6a0;
        uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
        lVar3 = (ulonglong)uVar5 - 0x3ff;
        dVar10 = dVar7;
        if ((ulonglong)uVar5 < 0x433) {
          if (uVar5 < 0x3ff) {
            dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar3 != -1) {
              dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
            }
          }
          else {
            bVar2 = (byte)lVar3;
            if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
              dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                               -0x10000000000000 >> (bVar2 & 0x3f));
            }
          }
        }
        else if (lVar3 == 0x400) {
          dVar10 = dVar7 + dVar7;
        }
        lVar3 = 2;
        if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
          dVar7 = dVar7 * _DAT_146d4e5e6a0;
          uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
          lVar3 = (ulonglong)uVar5 - 0x3ff;
          dVar10 = dVar7;
          if ((ulonglong)uVar5 < 0x433) {
            if (uVar5 < 0x3ff) {
              dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
              if (lVar3 != -1) {
                dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
              }
            }
            else {
              bVar2 = (byte)lVar3;
              if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                 -0x10000000000000 >> (bVar2 & 0x3f));
              }
            }
          }
          else if (lVar3 == 0x400) {
            dVar10 = dVar7 + dVar7;
          }
          lVar3 = 3;
          if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
            dVar7 = dVar7 * _DAT_146d4e5e6a0;
            uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
            lVar3 = (ulonglong)uVar5 - 0x3ff;
            dVar10 = dVar7;
            if ((ulonglong)uVar5 < 0x433) {
              if (uVar5 < 0x3ff) {
                dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar3 != -1) {
                  dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                }
              }
              else {
                bVar2 = (byte)lVar3;
                if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                   -0x10000000000000 >> (bVar2 & 0x3f));
                }
              }
            }
            else if (lVar3 == 0x400) {
              dVar10 = dVar7 + dVar7;
            }
            lVar3 = 4;
            if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
              dVar7 = dVar7 * _DAT_146d4e5e6a0;
              uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
              lVar3 = (ulonglong)uVar5 - 0x3ff;
              dVar10 = dVar7;
              if ((ulonglong)uVar5 < 0x433) {
                if (uVar5 < 0x3ff) {
                  dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                  if (lVar3 != -1) {
                    dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                  }
                }
                else {
                  bVar2 = (byte)lVar3;
                  if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                     -0x10000000000000 >> (bVar2 & 0x3f));
                  }
                }
              }
              else if (lVar3 == 0x400) {
                dVar10 = dVar7 + dVar7;
              }
              lVar3 = 5;
              if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
                dVar7 = dVar7 * _DAT_146d4e5e6a0;
                uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
                lVar3 = (ulonglong)uVar5 - 0x3ff;
                dVar10 = dVar7;
                if ((ulonglong)uVar5 < 0x433) {
                  if (uVar5 < 0x3ff) {
                    dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                    if (lVar3 != -1) {
                      dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                    }
                  }
                  else {
                    bVar2 = (byte)lVar3;
                    if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                      dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                       -0x10000000000000 >> (bVar2 & 0x3f));
                    }
                  }
                }
                else if (lVar3 == 0x400) {
                  dVar10 = dVar7 + dVar7;
                }
                lVar3 = 6;
                if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
                  dVar7 = dVar7 * _DAT_146d4e5e6a0;
                  uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
                  lVar3 = (ulonglong)uVar5 - 0x3ff;
                  dVar10 = dVar7;
                  if ((ulonglong)uVar5 < 0x433) {
                    if (uVar5 < 0x3ff) {
                      dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                      if (lVar3 != -1) {
                        dVar10 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                      }
                    }
                    else {
                      bVar2 = (byte)lVar3;
                      if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                        dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                         -0x10000000000000 >> (bVar2 & 0x3f));
                      }
                    }
                  }
                  else if (lVar3 == 0x400) {
                    dVar10 = dVar7 + dVar7;
                  }
                  lVar3 = 7;
                  if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar10) & _DAT_146d4e5e690)) {
                    lVar3 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ((longlong)dVar9 != -0x8000000000000000) {
      dVar7 = (double)(longlong)dVar9;
      dVar10 = *(double *)(lVar3 * 8 + 0x146d4e5e750);
      dVar9 = (double)(longlong)
                      ((dVar9 - dVar7) * dVar10 +
                      *(double *)((ulonglong)(0.0 < dVar9) * 8 + 0x146d4e5e6a8)) / dVar10 + dVar7;
    }
  }
  return dVar9;
}



/* Address: 146d4e58020 */

void FUN_146d4e58020(int param_1)

{
  if (param_1 == 4) {
    FUN_146d4e407d0(&DAT_146d4e68460,0x146d4e5e910,0,0x146d4e66008);
    return;
  }
  FUN_146d4e407d0(&DAT_146d4e68470,0x146d4e5e910,0,0x146d4e66018);
  return;
}



/* Address: 146d4e58090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e58090(undefined8 param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  double dVar13;
  undefined4 local_290;
  undefined8 local_28c;
  ulonglong local_280;
  undefined4 local_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined8 uStack_260;
  undefined8 local_258;
  double dStack_250;
  double local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 local_214;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  ulonglong local_188 [6];
  undefined4 local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined1 local_148 [144];
  undefined1 local_b8 [8];
  double local_b0;
  double local_a8;
  
  local_290 = 0;
  local_28c = 0;
  cVar6 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,param_1);
  if (cVar6 == '\0') {
    iVar7 = -1;
  }
  else {
    iVar7 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,4);
  }
  cVar6 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,param_1);
  if (((cVar6 != '\0') && (cVar6 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,param_1), cVar6 != '\0'))
     && (cVar6 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,0x146d4e5e890,local_b8), cVar6 != '\0')) {
    iVar8 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,4);
    (*(code *)0x7ff63a108280)(0x146d2d8aad8,9);
    dVar3 = _DAT_146d4e68548;
    lVar10 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e5e890,0x1f);
    dVar1 = (double)lVar10 * _DAT_146d4e68518;
    lVar10 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,0x146d4e5e890,0x20);
    dVar2 = (double)lVar10 * _DAT_146d4e68518;
    (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,0x146d4e5e890,0x1b);
    dVar13 = _DAT_146d4e68548;
    if (_DAT_146d4e68548 <= 0.0) {
      dVar13 = _DAT_146d4e68518;
    }
    if (dVar1 <= dVar2) {
      dVar1 = dVar2;
    }
    if (iVar8 == 5) {
      if (local_b0 - (dVar1 + dVar13) <= dVar3) goto LAB_146d4e58de5;
    }
    else if ((iVar8 == 4) && (dVar3 <= dVar1 + dVar13 + local_a8)) {
LAB_146d4e58de5:
      (*(code *)0x7ff63a0e49f0)
                (0x146d2d8aad8,2,3,0x590008,0x146d4e61d58,0x560015,param_1,0x590008,0x146d4e61dd8);
      return 0;
    }
  }
  local_214 = 0;
  local_210 = 0;
  local_154 = 0;
  local_150 = 0;
  uStack_268 = 0;
  uStack_264 = 0;
  uStack_260 = 0;
  local_278 = 0;
  uStack_274 = 0;
  uStack_270 = 0;
  uStack_26c = 0;
  FUN_146d4e400a0(&uStack_264);
  local_228 = 0;
  uStack_220 = 0;
  uStack_21c = 0;
  local_238 = 0;
  uStack_230 = 0;
  local_248 = 0.0;
  uStack_240 = 0;
  local_258 = 0;
  dStack_250 = 0.0;
  uStack_218 = 0;
  FUN_146d4e400a0(&local_214);
  local_198 = 0;
  uStack_190 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_208 = 0;
  uStack_200 = 0;
  local_188[0] = 0;
  local_188[1] = 0;
  local_188[2] = 0;
  local_188[3] = 0;
  local_188[4] = 0;
  local_188[5] = 0;
  local_158 = 0;
  FUN_146d4e400a0(&local_154);
  (*(code *)0x7ff63a3fad20)(local_148,0,0x84);
  local_278 = 8;
  uStack_26c = (undefined4)param_1;
  uVar4 = uStack_26c;
  uStack_268 = (undefined4)((ulonglong)param_1 >> 0x20);
  uVar5 = uStack_268;
  FUN_146d4e407d0(&uStack_264,0x146d4e68528,1,0x146d4e656f8);
  uStack_274 = 0xa0a3;
  if (DAT_146d4e68059 == '\0') {
    uStack_274 = 0;
  }
  uStack_270 = 0;
  cVar6 = (*(code *)0x7ff63a108b70)(0x146d2d8aad8,&local_278,local_188);
  iVar8 = (int)local_188[0];
  uVar11 = local_188[0] & 0xffffffff;
  if ((cVar6 == '\0') || (1 < (int)local_188[0] - 0x2719U)) {
    local_290 = 0;
    local_28c = 0;
    FUN_146d4e407d0(&local_290,&local_154,0,0x146d4e65708);
    cVar6 = (*(code *)0x7ff63a108240)(0x146d2d8aad8,param_1);
    if (cVar6 == '\0') {
      (*(code *)0x7ff63a0e49f0)
                (0x146d2d8aad8,2,6,0x590008,0x146d4e61e80,0x560015,param_1,0x590008,0x146d4e61c50,
                 0x530014,iVar8,0x590008,0x146d4e61c80,0x590008,&local_290);
      FUN_146d4e400a0(&local_290);
      FUN_146d4e400a0(&local_154);
      FUN_146d4e400a0(&local_214);
    }
    else {
      local_280 = uVar11;
      (*(code *)0x7ff63a108280)(0x146d2d8aad8,9);
      dVar1 = _DAT_146d4e68548;
      (*(code *)0x7ff63a108280)(0x146d2d8aad8,0xb);
      dVar2 = _DAT_146d4e68548;
      uVar9 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,6);
      uVar12 = (*(code *)0x7ff63a108310)(0x146d2d8aad8,2);
      uStack_268 = 0;
      local_278 = 0;
      uStack_274 = 0;
      uStack_270 = 0;
      uStack_26c = 0;
      FUN_146d4e400a0(&uStack_264);
      uStack_218 = 0;
      uStack_220 = 0;
      uStack_21c = 0;
      local_228 = 0;
      uStack_230 = 0;
      local_238 = 0;
      uStack_240 = 0;
      local_248 = 0.0;
      dStack_250 = 0.0;
      local_258 = 0;
      FUN_146d4e400a0(&local_214);
      uStack_190 = 0;
      local_198 = 0;
      uStack_1a0 = 0;
      local_1a8 = 0;
      uStack_1b0 = 0;
      local_1b8 = 0;
      uStack_1c0 = 0;
      local_1c8 = 0;
      uStack_1d0 = 0;
      local_1d8 = 0;
      uStack_1e0 = 0;
      local_1e8 = 0;
      uStack_1f0 = 0;
      local_1f8 = 0;
      uStack_200 = 0;
      local_208 = 0;
      local_188[4] = 0;
      local_188[5] = 0;
      local_188[2] = 0;
      local_188[3] = 0;
      local_188[0] = 0;
      local_188[1] = 0;
      local_158 = 0;
      FUN_146d4e400a0(&local_154);
      (*(code *)0x7ff63a3fad20)(local_148,0,0x84);
      local_278 = 7;
      uStack_26c = uVar4;
      uStack_268 = uVar5;
      FUN_146d4e407d0(&uStack_264,0x146d4e68528,1,0x146d4e65718);
      uStack_274 = 0xa0a3;
      if (DAT_146d4e68059 == '\0') {
        uStack_274 = 0;
      }
      uStack_270 = 0;
      dStack_250 = dVar1;
      local_248 = dVar2;
      uStack_240 = 0;
      local_238 = 0;
      uStack_21c = (undefined4)uVar12;
      uStack_218 = (undefined4)((ulonglong)uVar12 >> 0x20);
      uStack_220 = uVar9;
      cVar6 = (*(code *)0x7ff63a108b70)(0x146d2d8aad8,&local_278,local_188);
      uVar9 = (undefined4)local_280;
      if (cVar6 == '\0') {
        (*(code *)0x7ff63a0e49f0)
                  (0x146d2d8aad8,2,10,0x590008,0x146d4e61f00,0x560015,param_1,0x590008,0x146d4e61c50
                   ,0x530014,(int)local_188[0],0x590008,0x146d4e61c80,0x590008,&local_154,0x590008,
                   0x146d4e61f40,0x530014,uVar9,0x590008,0x146d4e61f80,0x590008,&local_290);
        FUN_146d4e400a0(&local_290);
        FUN_146d4e400a0(&local_154);
        FUN_146d4e400a0(&local_214);
        FUN_146d4e400a0(&uStack_264);
        return 0;
      }
      if ((int)local_188[0] == 0x2719) {
        uStack_268 = 0;
        local_278 = 0;
        uStack_274 = 0;
        uStack_270 = 0;
        uStack_26c = 0;
        FUN_146d4e400a0(&uStack_264);
        uStack_218 = 0;
        uStack_220 = 0;
        uStack_21c = 0;
        local_228 = 0;
        uStack_230 = 0;
        local_238 = 0;
        uStack_240 = 0;
        local_248 = 0.0;
        dStack_250 = 0.0;
        local_258 = 0;
        FUN_146d4e400a0(&local_214);
        uStack_190 = 0;
        local_198 = 0;
        uStack_1a0 = 0;
        local_1a8 = 0;
        uStack_1b0 = 0;
        local_1b8 = 0;
        uStack_1c0 = 0;
        local_1c8 = 0;
        uStack_1d0 = 0;
        local_1d8 = 0;
        uStack_1e0 = 0;
        local_1e8 = 0;
        uStack_1f0 = 0;
        local_1f8 = 0;
        uStack_200 = 0;
        local_208 = 0;
        local_188[4] = 0;
        local_188[5] = 0;
        local_188[2] = 0;
        local_188[3] = 0;
        local_188[0] = 0;
        local_188[1] = 0;
        local_158 = 0;
        FUN_146d4e400a0(&local_154);
        (*(code *)0x7ff63a3fad20)(local_148,0,0x84);
        local_278 = 8;
        uStack_26c = uVar4;
        uStack_268 = uVar5;
        FUN_146d4e407d0(&uStack_264,0x146d4e68528,1,0x146d4e65728);
        uStack_274 = 0xa0a3;
        if (DAT_146d4e68059 == '\0') {
          uStack_274 = 0;
        }
        uStack_270 = 0;
        cVar6 = (*(code *)0x7ff63a108b70)(0x146d2d8aad8,&local_278,local_188);
        if (cVar6 == '\0') {
          (*(code *)0x7ff63a0e49f0)
                    (0x146d2d8aad8,2,10,0x590008,0x146d4e62070,0x560015,param_1,0x590008,
                     0x146d4e61c50,0x530014,(int)local_188[0],0x590008,0x146d4e61c80,0x590008,
                     &local_154,0x590008,0x146d4e620b8,0x530014,uVar9,0x590008,0x146d4e62108,
                     0x590008,&local_290);
          FUN_146d4e400a0(&local_290);
          FUN_146d4e400a0(&local_154);
          FUN_146d4e400a0(&local_214);
          goto LAB_146d4e58f44;
        }
        if (0xfffffffd < (int)local_188[0] - 0x271bU) {
          FUN_146d4e400a0(&local_290);
          FUN_146d4e400a0(&local_154);
          FUN_146d4e400a0(&local_214);
          goto LAB_146d4e58b95;
        }
        (*(code *)0x7ff63a0e49f0)
                  (0x146d2d8aad8,2,10,0x590008,0x146d4e62178,0x560015,param_1,0x590008,0x146d4e61c50
                   ,0x530014,(int)local_188[0],0x590008,0x146d4e61c80,0x590008,&local_154,0x590008,
                   0x146d4e620b8,0x530014,uVar9,0x590008,0x146d4e62108,0x590008,&local_290);
        FUN_146d4e400a0(&local_290);
      }
      else {
        (*(code *)0x7ff63a0e49f0)
                  (0x146d2d8aad8,2,10,0x590008,0x146d4e61ff8,0x560015,param_1,0x590008,0x146d4e61c50
                   ,0x530014,(int)local_188[0],0x590008,0x146d4e61c80,0x590008,&local_154,0x590008,
                   0x146d4e61f40,0x530014,uVar9,0x590008,0x146d4e61f80,0x590008,&local_290);
        FUN_146d4e400a0(&local_290);
      }
      FUN_146d4e400a0(&local_154);
      FUN_146d4e400a0(&local_214);
    }
LAB_146d4e58f44:
    FUN_146d4e400a0(&uStack_264);
    return 0;
  }
  if (iVar7 == 5) {
    uVar12 = 0x146d4e61898;
LAB_146d4e58b58:
    iVar7 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,uVar12);
    if (-1 < iVar7) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,uVar12);
    }
  }
  else if (iVar7 == 4) {
    uVar12 = 0x146d4e61850;
    goto LAB_146d4e58b58;
  }
  FUN_146d4e400a0(&local_154);
  FUN_146d4e400a0(&local_214);
LAB_146d4e58b95:
  FUN_146d4e400a0(&uStack_264);
  return 1;
}



/* Address: 146d4e58fa0 */

void FUN_146d4e58fa0(int param_1,undefined8 param_2,double param_3,double param_4)

{
  longlong lVar1;
  uint uVar2;
  code *pcVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 in_R8;
  undefined8 in_R9;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  double dVar14;
  double in_XMM1_Qa;
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar15;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  longlong local_84;
  
  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
  local_a8 = 0;
  local_88 = 0;
  local_b8 = 0;
  local_98 = 0;
  local_a4 = 0;
  local_84 = 0;
  local_b4 = 0;
  local_94 = 0;
  if (((((DAT_146d4e687e0 == '\0') || (param_1 - 6U < 0xfffffffe)) || (in_XMM1_Qa <= 0.0)) ||
      ((param_3 <= 0.0 || (param_4 <= 0.0)))) ||
     (dVar14 = (double)FUN_146d4e5b8f0(param_1,param_2,in_R8,in_R9,1), dVar14 <= 0.0)) {
    if (param_1 == 5) {
      uVar8 = 0x146d4e61898;
    }
    else {
      if (param_1 != 4) goto LAB_146d4e59543;
      uVar8 = 0x146d4e61850;
    }
    iVar6 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,uVar8);
    if (-1 < iVar6) {
      (*(code *)0x7ff63a0f4ce0)(0x146d2d8aad8,0,uVar8);
    }
    goto LAB_146d4e59543;
  }
  lVar7 = (*(code *)0x7ff63a101c40)(0x146d2d8aad8,0);
  if ((lVar7 < 1) && (lVar7 = (*(code *)0x7ff63a101ce0)(0x146d2d8aad8,0), lVar7 < 1)) {
    lVar7 = (*(code *)0x7ff63a101d80)(0x146d2d8aad8,0);
  }
  uVar8 = 0x146d4e61898;
  local_b8 = 0;
  local_b4 = 0;
  if (param_1 == 4) {
    uVar8 = 0x146d4e61850;
  }
  FUN_146d4e407d0(&local_b8,uVar8,0,0x146d4e65558);
  local_98 = 0;
  local_94 = 0;
  (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,dVar14,2);
  FUN_146d4e407d0(&local_88,&DAT_146d4e6853c,1,0x146d4e65568);
  FUN_146d4e407d0(&local_a8,0x146d4e618c8,0);
  lVar4 = local_84;
  if (local_84 != 0) {
    uVar2 = *(uint *)(local_84 + -4);
    uVar12 = (ulonglong)uVar2;
    if ((uVar12 != 0) || (local_a4 == 0)) {
      if (local_a4 == 0) {
        uVar13 = 0;
        uVar10 = uVar2;
      }
      else {
        uVar13 = *(uint *)(local_a4 + -4);
        uVar10 = uVar2 + uVar13;
      }
      cVar5 = FUN_146d4e40100(&local_a8);
      if (cVar5 == '\0') {
        (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x230ba6000001f9);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      if (uVar12 != 0) {
        lVar1 = local_a4 + (ulonglong)uVar13 * 2;
        if (uVar2 < 0x10) {
          uVar9 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar4) < 0x20) {
          uVar9 = 0;
        }
        else {
          uVar11 = 0;
          uVar9 = (ulonglong)(uVar2 & 0xfffffff8);
          do {
            uVar8 = ((undefined8 *)(lVar4 + uVar11))[1];
            *(undefined8 *)(lVar1 + uVar11) = *(undefined8 *)(lVar4 + uVar11);
            ((undefined8 *)(lVar1 + uVar11))[1] = uVar8;
            uVar11 = uVar11 + 0x10;
          } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar11);
          if (uVar9 == uVar12) goto LAB_146d4e59352;
        }
        do {
          *(undefined2 *)(lVar1 + uVar9 * 2) = *(undefined2 *)(lVar4 + uVar9 * 2);
          uVar9 = uVar9 + 1;
        } while (uVar12 != uVar9);
      }
LAB_146d4e59352:
      *(uint *)(local_a4 + -4) = uVar10;
      *(undefined2 *)(local_a4 + (ulonglong)uVar10 * 2) = 0;
    }
  }
  FUN_146d4e407d0(&local_98,&local_a8,0,0x146d4e65588);
  iVar6 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,&local_b8);
  if (iVar6 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,6,0x550005,0,CONCAT44(uVar15,0x590008),&local_b8,0x520004,0x65,
               0x520004,0,0x540005,lVar7,0x580007,param_3);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,&local_b8,0,lVar7,param_3);
  }
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_b8,6,&local_98);
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_b8,0x3e9,0x146d4e632a8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_b8,0x3ea,8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_b8,0,0x4763ff);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_b8,0x3f3,(param_1 != 4) * '\x04' + '\x03');
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_b8,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_b8,0xd0,1);
  FUN_146d4e400a0(&local_98);
  FUN_146d4e400a0(&local_b8);
LAB_146d4e59543:
  FUN_146d4e400a0(&local_88);
  FUN_146d4e400a0(&local_a8);
  return;
}



/* Address: 146d4e595b0 */

void FUN_146d4e595b0(int param_1,undefined8 param_2)

{
  if (param_1 == 4) {
    FUN_146d4e407d0(&DAT_146d4e68460,param_2,0,0x146d4e65fe8);
    return;
  }
  FUN_146d4e407d0(&DAT_146d4e68470,param_2,0,0x146d4e65ff8);
  return;
}



/* Address: 146d4e59600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_146d4e59600(undefined8 param_1,double param_2)

{
  code *pcVar1;
  byte bVar2;
  longlong lVar3;
  double dVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_1,0x22);
  dVar7 = _DAT_146d4e68548;
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_1,0x23);
  dVar8 = _DAT_146d4e68548;
  (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_1,0x24);
  if (0.0 < _DAT_146d4e68548) {
    if ((_DAT_146d4e68548 == 0.0) && (!NAN(_DAT_146d4e68548))) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x340535000001f7);
      pcVar1 = (code *)swi(3);
      dVar8 = (double)(*pcVar1)();
      return dVar8;
    }
    dVar10 = dVar8;
    if (param_2 <= dVar8) {
      dVar10 = param_2;
    }
    dVar4 = dVar7;
    if (dVar7 <= dVar10) {
      dVar4 = dVar10;
    }
    dVar9 = (dVar4 - dVar7) / _DAT_146d4e68548 + _DAT_146d4e5e680;
    dVar4 = ABS(dVar9);
    uVar5 = (uint)((ulonglong)dVar4 >> 0x20);
    dVar10 = dVar9;
    if (uVar5 >> 0x14 < 0x3ff) {
      if ((dVar4 != 0.0) && (dVar10 = 0.0, (longlong)dVar9 < 0)) {
        dVar10 = _DAT_146d4e5e688;
      }
    }
    else if (((uVar5 >> 0x16 < 0x10d) &&
             (bVar2 = 0x33 - (char)((ulonglong)dVar4 >> 0x34),
             dVar6 = (double)(((ulonglong)dVar4 >> (bVar2 & 0x3f)) << (bVar2 & 0x3f)),
             dVar10 = dVar6, (longlong)dVar9 < 1)) &&
            (dVar10 = (double)((ulonglong)dVar6 | 0x8000000000000000), dVar6 != dVar4)) {
      dVar10 = dVar10 + _DAT_146d4e5e688;
    }
    dVar10 = dVar10 * _DAT_146d4e68548 + dVar7;
    if (dVar10 <= dVar8) {
      dVar8 = dVar10;
    }
    uVar5 = (uint)((ulonglong)_DAT_146d4e68548 >> 0x34) & 0x7ff;
    lVar3 = (ulonglong)uVar5 - 0x3ff;
    dVar10 = _DAT_146d4e68548;
    if ((ulonglong)uVar5 < 0x433) {
      if (uVar5 < 0x3ff) {
        dVar10 = (double)((ulonglong)_DAT_146d4e68548 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar3 != -1) {
          dVar10 = (double)((ulonglong)_DAT_146d4e68548 & 0x8000000000000000);
        }
      }
      else {
        bVar2 = (byte)lVar3;
        if (((longlong)_DAT_146d4e68548 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
          dVar10 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)_DAT_146d4e68548 &
                           -0x10000000000000 >> (bVar2 & 0x3f));
        }
      }
    }
    else if (lVar3 == 0x400) {
      dVar10 = _DAT_146d4e68548 + _DAT_146d4e68548;
    }
    param_2 = dVar7;
    if (dVar7 <= dVar8) {
      param_2 = dVar8;
    }
    if ((double)((ulonglong)(_DAT_146d4e68548 - dVar10) & _DAT_146d4e5e690) <= _DAT_146d4e5e680) {
      lVar3 = 0;
    }
    else {
      dVar7 = _DAT_146d4e68548 * _DAT_146d4e5e6a0;
      uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
      lVar3 = (ulonglong)uVar5 - 0x3ff;
      dVar8 = dVar7;
      if ((ulonglong)uVar5 < 0x433) {
        if (uVar5 < 0x3ff) {
          dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
          if (lVar3 != -1) {
            dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
          }
        }
        else {
          bVar2 = (byte)lVar3;
          if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
            dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                            -0x10000000000000 >> (bVar2 & 0x3f));
          }
        }
      }
      else if (lVar3 == 0x400) {
        dVar8 = dVar7 + dVar7;
      }
      lVar3 = 1;
      if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
        dVar7 = dVar7 * _DAT_146d4e5e6a0;
        uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
        lVar3 = (ulonglong)uVar5 - 0x3ff;
        dVar8 = dVar7;
        if ((ulonglong)uVar5 < 0x433) {
          if (uVar5 < 0x3ff) {
            dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar3 != -1) {
              dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
            }
          }
          else {
            bVar2 = (byte)lVar3;
            if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
              dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                              -0x10000000000000 >> (bVar2 & 0x3f));
            }
          }
        }
        else if (lVar3 == 0x400) {
          dVar8 = dVar7 + dVar7;
        }
        lVar3 = 2;
        if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
          dVar7 = dVar7 * _DAT_146d4e5e6a0;
          uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
          lVar3 = (ulonglong)uVar5 - 0x3ff;
          dVar8 = dVar7;
          if ((ulonglong)uVar5 < 0x433) {
            if (uVar5 < 0x3ff) {
              dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
              if (lVar3 != -1) {
                dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
              }
            }
            else {
              bVar2 = (byte)lVar3;
              if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                -0x10000000000000 >> (bVar2 & 0x3f));
              }
            }
          }
          else if (lVar3 == 0x400) {
            dVar8 = dVar7 + dVar7;
          }
          lVar3 = 3;
          if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
            dVar7 = dVar7 * _DAT_146d4e5e6a0;
            uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
            lVar3 = (ulonglong)uVar5 - 0x3ff;
            dVar8 = dVar7;
            if ((ulonglong)uVar5 < 0x433) {
              if (uVar5 < 0x3ff) {
                dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar3 != -1) {
                  dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                }
              }
              else {
                bVar2 = (byte)lVar3;
                if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                  -0x10000000000000 >> (bVar2 & 0x3f));
                }
              }
            }
            else if (lVar3 == 0x400) {
              dVar8 = dVar7 + dVar7;
            }
            lVar3 = 4;
            if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
              dVar7 = dVar7 * _DAT_146d4e5e6a0;
              uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
              lVar3 = (ulonglong)uVar5 - 0x3ff;
              dVar8 = dVar7;
              if ((ulonglong)uVar5 < 0x433) {
                if (uVar5 < 0x3ff) {
                  dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                  if (lVar3 != -1) {
                    dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                  }
                }
                else {
                  bVar2 = (byte)lVar3;
                  if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                    dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                    -0x10000000000000 >> (bVar2 & 0x3f));
                  }
                }
              }
              else if (lVar3 == 0x400) {
                dVar8 = dVar7 + dVar7;
              }
              lVar3 = 5;
              if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
                dVar7 = dVar7 * _DAT_146d4e5e6a0;
                uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
                lVar3 = (ulonglong)uVar5 - 0x3ff;
                dVar8 = dVar7;
                if ((ulonglong)uVar5 < 0x433) {
                  if (uVar5 < 0x3ff) {
                    dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                    if (lVar3 != -1) {
                      dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                    }
                  }
                  else {
                    bVar2 = (byte)lVar3;
                    if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                      dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                      -0x10000000000000 >> (bVar2 & 0x3f));
                    }
                  }
                }
                else if (lVar3 == 0x400) {
                  dVar8 = dVar7 + dVar7;
                }
                lVar3 = 6;
                if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
                  dVar7 = dVar7 * _DAT_146d4e5e6a0;
                  uVar5 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
                  lVar3 = (ulonglong)uVar5 - 0x3ff;
                  dVar8 = dVar7;
                  if ((ulonglong)uVar5 < 0x433) {
                    if (uVar5 < 0x3ff) {
                      dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
                      if (lVar3 != -1) {
                        dVar8 = (double)((ulonglong)dVar7 & 0x8000000000000000);
                      }
                    }
                    else {
                      bVar2 = (byte)lVar3;
                      if (((longlong)dVar7 << (bVar2 & 0x3f) & 0xfffffffffffffU) != 0) {
                        dVar8 = (double)((0x8000000000000U >> (bVar2 & 0x3f)) + (longlong)dVar7 &
                                        -0x10000000000000 >> (bVar2 & 0x3f));
                      }
                    }
                  }
                  else if (lVar3 == 0x400) {
                    dVar8 = dVar7 + dVar7;
                  }
                  lVar3 = 7;
                  if (_DAT_146d4e5e680 < (double)((ulonglong)(dVar7 - dVar8) & _DAT_146d4e5e690)) {
                    lVar3 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ((longlong)param_2 != -0x8000000000000000) {
      dVar7 = (double)(longlong)param_2;
      dVar8 = *(double *)(lVar3 * 8 + 0x146d4e5e750);
      param_2 = (double)(longlong)
                        ((param_2 - dVar7) * dVar8 +
                        *(double *)((ulonglong)(0.0 < param_2) * 8 + 0x146d4e5e6a8)) / dVar8 + dVar7
      ;
    }
  }
  return param_2;
}



/* Address: 146d4e59d80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e59d80(longlong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_70;
  undefined8 local_6c;
  int local_60;
  int local_5c;
  int local_58;
  int local_48;
  
  local_70 = 0;
  local_80 = 0;
  local_a0 = 0;
  local_6c = 0;
  local_7c = 0;
  local_9c = 0;
  if ((DAT_146d4e686f0 == '\0') || (param_1 < 1)) {
    puVar5 = (undefined1 *)0x146d4e5e910;
    uVar6 = 0x146d4e65188;
  }
  else {
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,param_1,&local_60);
    iVar4 = local_58;
    iVar3 = local_5c;
    iVar2 = local_60;
    if (((local_60 == _DAT_146d4e6847c) && (local_5c == _DAT_146d4e68480)) &&
       (local_58 == _DAT_146d4e68484)) {
      puVar5 = &DAT_146d4e68488;
      uVar6 = 0x146d4e65198;
    }
    else {
      if ((local_48 == 0) || (local_48 == 6)) {
        _DAT_146d4e6847c = local_60;
        _DAT_146d4e68480 = local_5c;
        _DAT_146d4e68484 = local_58;
        FUN_146d4e407d0(&DAT_146d4e68488,0x146d4e5e910,0,0x146d4e651a8);
        uVar6 = 0x146d4e651b8;
      }
      else {
        if (0xfffffffa < local_60 - 0x7efU) {
          local_a0 = 0;
          local_9c = 0;
          FUN_146d4e407d0(&local_a0,0x146d4e5e910,0,0x146d4e651e8);
          local_90 = 0;
          local_8c = 0;
          FUN_146d4e5a2d0(param_1);
          FUN_146d4e407d0(&local_90,&DAT_146d4e6853c,1,0x146d4e652b8);
          if ((local_8c == 0) || (local_8c == 0xc)) {
            FUN_146d4e400a0(&local_90);
LAB_146d4e5a06f:
            local_90 = 0;
            local_8c = 0;
            FUN_146d4e5a670(iVar2,iVar3,iVar4);
            FUN_146d4e407d0(&local_90,&DAT_146d4e6853c,1,0x146d4e65328);
            if ((local_8c == 0) || (local_8c == 0xc)) {
              FUN_146d4e400a0(&local_90);
            }
            else {
              iVar1 = *(int *)(local_8c + -4);
              FUN_146d4e400a0(&local_90);
              if (0 < iVar1) {
                FUN_146d4e5a670(iVar2,iVar3,iVar4);
                FUN_146d4e407d0(&local_70,&DAT_146d4e6853c,1,0x146d4e65218);
                uVar6 = 0x146d4e65228;
                goto LAB_146d4e5a108;
              }
            }
            if (iVar3 - 1U < 0xb) {
                    /* WARNING: Could not emulate address calculation at 0x0146d4e5a132 */
                    /* WARNING: Treating indirect jump as call */
              (**(code **)((ulonglong)(iVar3 - 1U) * 8 + 0x146d4e5e6b8))();
              return;
            }
          }
          else {
            iVar1 = *(int *)(local_8c + -4);
            FUN_146d4e400a0(&local_90);
            if (iVar1 < 1) goto LAB_146d4e5a06f;
            FUN_146d4e5a2d0(param_1);
            FUN_146d4e407d0(&local_70,&DAT_146d4e6853c,1,0x146d4e651f8);
            uVar6 = 0x146d4e65208;
LAB_146d4e5a108:
            FUN_146d4e407d0(&local_a0,&local_70,0,uVar6);
          }
          _DAT_146d4e68480 = local_5c;
          _DAT_146d4e6847c = local_60;
          _DAT_146d4e68484 = local_58;
          FUN_146d4e407d0(&DAT_146d4e68488,&local_a0,0,0x146d4e65288);
          FUN_146d4e407d0(&local_80,&local_a0,0,0x146d4e65298);
          FUN_146d4e400a0(&local_a0);
          goto LAB_146d4e59eef;
        }
        _DAT_146d4e6847c = local_60;
        _DAT_146d4e68484 = local_58;
        _DAT_146d4e68480 = local_5c;
        FUN_146d4e407d0(&DAT_146d4e68488,0x146d4e5e910,0,0x146d4e651c8);
        uVar6 = 0x146d4e651d8;
      }
      puVar5 = (undefined1 *)0x146d4e5e910;
    }
  }
  FUN_146d4e407d0(&local_80,puVar5,0,uVar6);
LAB_146d4e59eef:
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_80,1,0x146d4e652a8);
  FUN_146d4e400a0(&local_80);
  FUN_146d4e400a0(&local_70);
  return;
}



/* Address: 146d4e5a2d0 */

void FUN_146d4e5a2d0(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  char cVar10;
  undefined8 uVar11;
  byte bVar12;
  char cVar13;
  uint uVar14;
  int iVar15;
  undefined4 local_50;
  undefined8 local_4c;
  uint local_40;
  uint local_3c;
  int local_38;
  
  local_50 = 0;
  local_4c = 0;
  if (DAT_146d4e686f0 == '\0') {
    uVar5 = 0x146d4e5e910;
    uVar11 = 0x146d4e652c8;
  }
  else {
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,param_1,&local_40);
    uVar1 = local_40 - (local_3c < 3);
    uVar3 = local_3c + 0xc;
    if (2 < local_3c) {
      uVar3 = local_3c;
    }
    if (0 < (int)local_40) {
      uVar9 = local_40 / 100;
      iVar6 = (uVar9 - (uVar9 + 8) / 0x19) + 1;
      iVar6 = (int)((ulonglong)((longlong)iVar6 * 0x55555555) >> 0x20) - iVar6;
      iVar7 = (iVar6 >> 1) - (iVar6 >> 0x1f);
      iVar15 = (uVar9 - local_40 / 400) + (local_40 % 0x13) * 0x13;
      iVar6 = iVar15 + iVar7;
      iVar7 = (int)((ulonglong)((longlong)(iVar15 + 0xf + iVar7) * -0x77777777) >> 0x20) + 0xf +
              iVar6;
      iVar6 = ((iVar7 >> 4) - (iVar7 >> 0x1f)) * -0x1e + 0xf + iVar6;
      uVar9 = ((((uVar9 & 3) * 2 - (local_40 % 100 & 3)) + (local_40 % 100 >> 1 & 0x3e)) - iVar6) +
              0x20;
      cVar10 = (char)((uVar9 & 0xff) * 0x25 >> 8);
      cVar13 = (char)uVar9;
      uVar9 = (uint)(byte)(cVar13 + ((byte)(((byte)(cVar13 - cVar10) >> 1) + cVar10) >> 2) * -7);
      iVar7 = uVar9 * 0x16 + iVar6 * 0xb + local_40 % 0x13;
      uVar14 = ((uint)((short)iVar7 * -0x6eaf) >> 0x10) + iVar7;
      uVar9 = (((int)(short)uVar14 >> 8) + ((uVar14 & 0xffff) >> 0xf)) * 0xf9 + 0x72 + iVar6 + uVar9
      ;
      bVar8 = (byte)uVar9;
      cVar10 = (char)((uVar9 & 0xff) + (uVar9 & 0xff) * 8 >> 8);
      bVar12 = (byte)(((byte)(bVar8 - cVar10) >> 1) + cVar10) >> 4;
      local_40 = local_40 - (bVar8 < 0x5d);
      uVar9 = bVar12 + 0xc;
      if (0x5c < bVar8) {
        uVar9 = (uint)bVar12;
      }
      uVar9 = ((uVar9 * 0x3d3 - 0xb66 >> 5) - 0xafa6c) +
              (((uint)(byte)(bVar8 + bVar12 * -0x1f) + (local_40 >> 2) + local_40 * 0x16d) -
              local_40 / 100) + local_40 / 400;
      if ((uVar9 != 0) &&
         (uVar3 = ((uVar3 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
                  ((uVar1 * 0x16d + local_38 + (uVar1 >> 2)) - uVar1 / 100) + uVar1 / 400,
         uVar3 != 0)) {
        lVar4 = (ulonglong)uVar9 * 0x15180;
        lVar2 = (ulonglong)uVar3 * 0x15180;
        if (lVar2 - (lVar4 + -0x2a300) == 0) {
          uVar5 = 0x146d4e611f8;
          uVar11 = 0x146d4e652e8;
        }
        else if (lVar2 - (lVar4 + 0x15180) == 0) {
          uVar5 = 0x146d4e61250;
          uVar11 = 0x146d4e652f8;
        }
        else {
          uVar5 = 0x146d4e5e910;
          uVar11 = 0x146d4e65308;
        }
        goto LAB_146d4e5a5e7;
      }
    }
    uVar5 = 0x146d4e5e910;
    uVar11 = 0x146d4e652d8;
  }
LAB_146d4e5a5e7:
  FUN_146d4e407d0(&local_50,uVar5,0,uVar11);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_50,1,0x146d4e65318);
  FUN_146d4e400a0(&local_50);
  return;
}



/* Address: 146d4e5a670 */

void FUN_146d4e5a670(uint param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  undefined4 local_90;
  undefined8 local_8c;
  uint local_80;
  int local_7c;
  int local_78;
  undefined1 local_60 [24];
  int local_48;
  
  local_90 = 0;
  local_8c = 0;
  uVar2 = param_1 - 1;
  uVar2 = (((uVar2 >> 2) + uVar2 * 0x16d) - uVar2 / 100) + -0xaf93a + uVar2 / 400;
  if (uVar2 == 0) {
LAB_146d4e5a743:
    iVar5 = ((param_1 >> 2) + param_1 * 0x16d) - param_1 / 100;
    uVar2 = iVar5 + -0xaf93a + param_1 / 400;
    if (uVar2 != 0) {
      lVar6 = (ulonglong)uVar2 * 0x15180;
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,local_60);
      if (local_48 == 6) {
        lVar6 = lVar6 + -0x15180;
      }
      else if (local_48 == 0) {
        lVar6 = lVar6 + 0x15180;
      }
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,&local_80);
      if (((local_80 == param_1) && (local_7c == param_2)) && (local_78 == param_3))
      goto LAB_146d4e5a7d9;
    }
    uVar2 = iVar5 + -0xaf9fe + param_1 / 400;
    if (uVar2 != 0) {
      lVar6 = (ulonglong)uVar2 * 0x15180;
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,local_60);
      if (local_48 == 6) {
        lVar6 = lVar6 + -0x15180;
      }
      else if (local_48 == 0) {
        lVar6 = lVar6 + 0x15180;
      }
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,&local_80);
      if (((local_80 == param_1) && (local_7c == param_2)) && (local_78 == param_3)) {
        uVar3 = 0x146d4e612f0;
        uVar4 = 0x146d4e65348;
        goto LAB_146d4e5a953;
      }
    }
    uVar2 = iVar5 + -0xaf9ef + param_1 / 400;
    if (uVar2 != 0) {
      lVar6 = (ulonglong)uVar2 * 0x15180;
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,local_60);
      if (local_48 == 6) {
        lVar6 = lVar6 + -0x15180;
      }
      else if (local_48 == 0) {
        lVar6 = lVar6 + 0x15180;
      }
      (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,&local_80);
      if (((local_80 == param_1) && (local_7c == param_2)) && (local_78 == param_3)) {
        uVar3 = 0x146d4e61350;
        uVar4 = 0x146d4e65358;
        goto LAB_146d4e5a953;
      }
    }
    cVar1 = FUN_146d4e5abe0(param_1,param_2,param_3,param_1,0xc,0x19);
    if (cVar1 == '\0') {
      uVar3 = 0x146d4e5e910;
      uVar4 = 0x146d4e65378;
    }
    else {
      uVar3 = 0x146d4e613a0;
      uVar4 = 0x146d4e65368;
    }
  }
  else {
    lVar6 = (ulonglong)uVar2 * 0x15180;
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,local_60);
    if (local_48 == 6) {
      lVar6 = lVar6 + -0x15180;
    }
    else if (local_48 == 0) {
      lVar6 = lVar6 + 0x15180;
    }
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar6,&local_80);
    if (((local_80 != param_1) || (local_7c != param_2)) || (local_78 != param_3))
    goto LAB_146d4e5a743;
LAB_146d4e5a7d9:
    uVar3 = 0x146d4e612a0;
    uVar4 = 0x146d4e65338;
  }
LAB_146d4e5a953:
  FUN_146d4e407d0(&local_90,uVar3,0,uVar4);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_90,1,0x146d4e65388);
  FUN_146d4e400a0(&local_90);
  return;
}



/* Address: 146d4e5a9b0 */

int FUN_146d4e5a9b0(uint param_1,uint param_2,int param_3,int param_4)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint local_60;
  uint local_5c;
  int local_58;
  undefined8 local_54;
  undefined4 local_4c;
  int local_48;
  
  if (param_2 < 0xc) {
    lVar4 = 0x1f;
    if ((0xa50U >> (param_2 & 0x1f) & 1) != 0) goto LAB_146d4e5a9eb;
    if (param_2 == 2) {
      if ((param_1 * -0x3d70a3d7 >> 4 | param_1 * -0x70000000) < 0xa3d70b) {
        lVar4 = 0x1e;
      }
      else {
        lVar4 = 0x1e - (ulonglong)
                       ((param_1 * -0x3d70a3d7 >> 2 | param_1 * 0x40000000) < 0x28f5c29 ||
                       (param_1 & 3) != 0);
      }
      goto LAB_146d4e5a9eb;
    }
  }
  lVar4 = 0x20;
LAB_146d4e5a9eb:
  uVar3 = param_1 - (param_2 < 3);
  uVar2 = param_2 + 0xc;
  if (2 < param_2) {
    uVar2 = param_2;
  }
  lVar5 = 0;
  iVar6 = 0;
  while( true ) {
    local_58 = (int)lVar5 + 1;
    uVar1 = (ulonglong)
            (((uVar3 / 400 + (uVar3 >> 2) + (uVar2 * 0x3d3 - 0xb66 >> 5) + uVar3 * 0x16d) -
             uVar3 / 100) - 0xafa6c) + lVar5;
    local_54 = 0;
    local_4c = 0;
    if ((((int)uVar1 != 0) &&
        (local_60 = param_1, local_5c = param_2,
        (*(code *)0x7ff63a101f60)(0x146d2d8aad8,(uVar1 & 0xffffffff) * 0x15180,&local_60),
        local_48 == param_3)) && (iVar6 = iVar6 + 1, iVar6 == param_4)) break;
    lVar5 = lVar5 + 1;
    if (lVar4 + -1 == lVar5) {
      return 0;
    }
  }
  return (int)lVar5 + 1;
}



/* Address: 146d4e5ab20 */

ulonglong FUN_146d4e5ab20(uint param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_50 [3];
  undefined8 local_44;
  undefined4 local_3c;
  int local_38;
  
  uVar2 = 0x1f;
  uVar1 = ((param_1 / 400 + (param_1 >> 2) + param_1 * 0x16d) - param_1 / 100) - 0xafa11;
  do {
    local_50[1] = 5;
    local_50[2] = (uint)uVar2;
    local_44 = 0;
    local_3c = 0;
    if ((uVar1 != 0) &&
       (local_50[0] = param_1,
       (*(code *)0x7ff63a101f60)(0x146d2d8aad8,(ulonglong)uVar1 * 0x15180,local_50), local_38 == 1))
    goto LAB_146d4e5abca;
    uVar2 = uVar2 - 1;
    uVar1 = uVar1 - 1;
  } while (uVar2 != 0);
  uVar2 = 0;
LAB_146d4e5abca:
  return uVar2 & 0xffffffff;
}



/* Address: 146d4e5abe0 */

bool FUN_146d4e5abe0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  int local_68;
  int local_64;
  int local_60;
  undefined1 local_48 [24];
  int local_30;
  
  uVar2 = param_4 - (uint)(param_5 < 3);
  uVar1 = param_5 + 0xc;
  if (2 < param_5) {
    uVar1 = param_5;
  }
  uVar1 = ((uVar1 * 0x3d3 - 0xb66 >> 5) - 0xafa6d) +
          ((uVar2 * 0x16d + param_6 + (uVar2 >> 2)) - uVar2 / 100) + uVar2 / 400;
  if (uVar1 == 0) {
    bVar4 = false;
  }
  else {
    lVar3 = (ulonglong)uVar1 * 0x15180;
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar3,local_48);
    if (local_30 == 6) {
      lVar3 = lVar3 + -0x15180;
    }
    else if (local_30 == 0) {
      lVar3 = lVar3 + 0x15180;
    }
    (*(code *)0x7ff63a101f60)(0x146d2d8aad8,lVar3,&local_68);
    bVar4 = param_3 == local_60 && (param_2 == local_64 && param_1 == local_68);
  }
  return bVar4;
}



/* Address: 146d4e5acd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e5acd0(double *param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  code *pcVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  uint uVar10;
  double dVar11;
  char cVar12;
  int iVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong lVar16;
  ulonglong uVar17;
  int iVar18;
  longlong lVar19;
  ulonglong uVar20;
  undefined4 local_c0;
  longlong local_bc;
  double *local_b0;
  
  local_c0 = 0;
  local_bc = 0;
  *param_1 = 0.0;
  uVar17 = 0;
  uVar14 = (*(code *)0x7ff63a101c40)(0x146d2d8aad8,0);
  cVar12 = (*(code *)0x7ff63a1084f0)(0x146d2d8aad8,0,uVar14);
  if (cVar12 != '\0') {
    iVar13 = (*(code *)0x7ff63a108810)(0x146d2d8aad8);
    uVar17 = _DAT_146d4e5e710;
    if (iVar13 + -1 < 0) {
      uVar17 = 0;
    }
    else {
      dVar8 = 0.0;
      dVar7 = 0.0;
      iVar13 = iVar13 + -1;
      local_b0 = param_1;
      do {
        lVar15 = (*(code *)0x7ff63a108860)(0x146d2d8aad8,iVar13);
        if (lVar15 != 0) {
          (*(code *)0x7ff63a1089d0)(0x146d2d8aad8,lVar15,0);
          FUN_146d4e407d0(&local_c0,&DAT_146d4e6853c,1,0x146d4e65398);
          if (local_bc == _DAT_146d4e6852c) {
LAB_146d4e5aee0:
            lVar16 = (*(code *)0x7ff63a108940)(0x146d2d8aad8,lVar15);
            lVar19 = 0;
            if (DAT_146d4e68059 != '\0') {
              lVar19 = 0xa0a3;
            }
            if ((lVar16 == lVar19) &&
               ((*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar15), dVar11 = _DAT_146d4e68548,
               0.0 < _DAT_146d4e68548)) {
              (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar15,7);
              dVar9 = _DAT_146d4e68548;
              (*(code *)0x7ff63a1088b0)(0x146d2d8aad8,lVar15);
              dVar9 = dVar9 + _DAT_146d4e68548;
              if ((dVar9 != 0.0) || (NAN(dVar9))) {
                dVar8 = dVar8 + dVar11;
                dVar7 = dVar7 + (double)((ulonglong)dVar9 & uVar17);
              }
            }
          }
          else if ((local_bc != 0) && (_DAT_146d4e6852c != 0)) {
            uVar3 = *(uint *)(local_bc + -4);
            uVar4 = *(uint *)(_DAT_146d4e6852c + -4);
            uVar10 = uVar4;
            if (uVar3 < uVar4) {
              uVar10 = uVar3;
            }
            iVar18 = uVar3 - uVar4;
            if (uVar10 != 0) {
              uVar20 = 1;
              do {
                uVar1 = *(ushort *)(local_bc + -2 + uVar20 * 2);
                uVar2 = *(ushort *)(_DAT_146d4e6852c + -2 + uVar20 * 2);
                if (uVar10 <= uVar20) break;
                uVar20 = uVar20 + 1;
              } while (uVar1 == uVar2);
              if (uVar1 != uVar2) {
                iVar18 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar18 == 0) goto LAB_146d4e5aee0;
          }
        }
        bVar5 = 0 < iVar13;
        iVar13 = iVar13 + -1;
      } while (bVar5);
      uVar17 = 0;
      if ((0.0 < dVar7) && (0.0 < dVar8)) {
        if ((dVar8 == 0.0) && (!NAN(dVar8))) {
          (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c0ac9000001f7);
          pcVar6 = (code *)swi(3);
          uVar17 = (*pcVar6)();
          return uVar17;
        }
        *local_b0 = dVar7 / dVar8;
        uVar17 = (ulonglong)(0.0 < dVar7 / dVar8);
      }
    }
  }
  FUN_146d4e400a0(&local_c0);
  return uVar17;
}



/* Address: 146d4e5b030 */

void FUN_146d4e5b030(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x2c0ac9000001f7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 146d4e5b060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_146d4e5b060(uint param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ushort uVar5;
  ushort uVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  undefined1 *puVar12;
  int iVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  uint uVar22;
  bool bVar23;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  longlong local_c4;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  uVar15 = (ulonglong)param_1;
  local_b8 = 0;
  local_88 = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_98 = 0;
  local_e8 = 0;
  local_78 = 0;
  local_b4 = 0;
  local_84 = 0;
  local_c4 = 0;
  local_d4 = 0;
  local_94 = 0;
  local_e4 = 0;
  local_74 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  local_a0 = 0;
  uVar22 = 0;
  (*(code *)0x7ff63a0fdfe0)(0x146d2d8aad8,param_1,0,0x20);
  FUN_146d4e407d0(&local_78,&DAT_146d4e6853c,1,0x146d4e65e58);
  FUN_146d4e407d0(&local_e8,&local_78,0);
  uVar17 = _DAT_146d4e635d4;
  uVar21 = (ulonglong)_DAT_146d4e635d4;
  if ((uVar21 == 0) && (local_e4 != 0)) {
LAB_146d4e5b25d:
    (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_2,_DAT_146d4e68520);
    FUN_146d4e407d0(&local_98,&DAT_146d4e6853c,1,0x146d4e65e78);
    FUN_146d4e407d0(&local_d8,&local_e8);
    lVar1 = local_94;
    if (local_94 == 0) {
LAB_146d4e5b421:
      uVar22 = 0;
      FUN_146d4e407d0(&local_c8,&local_d8,0,0x146d4e65e98);
      uVar17 = _DAT_146d4e635d4;
      uVar21 = (ulonglong)_DAT_146d4e635d4;
      if ((uVar21 != 0) || (local_c4 == 0)) {
        if (local_c4 != 0) {
          uVar22 = *(uint *)(local_c4 + -4);
        }
        uVar18 = _DAT_146d4e635d4 + uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar18) &&
           ((0x7ffffffd < uVar18 || (uVar16 = (uVar18 >> 2) + uVar18, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar11 = FUN_146d4e40100(&local_c8,uVar16);
        if (cVar11 == '\0') goto LAB_146d4e5b884;
        if (uVar21 != 0) {
          lVar1 = local_c4 + (ulonglong)uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar14 = 0;
          }
          else if (lVar1 - 0x146d4e635d8U < 0x20) {
            uVar14 = 0;
          }
          else {
            uVar19 = 0;
            uVar14 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar8 = *(undefined4 *)(uVar19 + 0x146d4e635dc);
              uVar9 = *(undefined4 *)(uVar19 + 0x146d4e635e0);
              uVar10 = *(undefined4 *)(uVar19 + 0x146d4e635e4);
              puVar3 = (undefined4 *)(lVar1 + uVar19);
              *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar19);
              puVar3[1] = uVar8;
              puVar3[2] = uVar9;
              puVar3[3] = uVar10;
              uVar19 = uVar19 + 0x10;
            } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar14 == uVar21) goto LAB_146d4e5b532;
          }
          do {
            *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar14 * 2);
            uVar14 = uVar14 + 1;
          } while (uVar21 != uVar14);
        }
LAB_146d4e5b532:
        *(uint *)(local_c4 + -4) = uVar18;
        *(undefined2 *)(local_c4 + (ulonglong)uVar18 * 2) = 0;
      }
      (*(code *)0x7ff63a0fd7c0)(0x146d2d8aad8,param_3,_DAT_146d4e68520);
      FUN_146d4e407d0(&local_88,&DAT_146d4e6853c,1,0x146d4e65ea8);
      FUN_146d4e407d0(&local_b8,&local_c8,0);
      lVar1 = local_84;
      if (local_84 != 0) {
        uVar22 = *(uint *)(local_84 + -4);
        uVar21 = (ulonglong)uVar22;
        if ((uVar21 != 0) || (local_b4 == 0)) {
          if (local_b4 == 0) {
            uVar17 = 0;
            uVar16 = uVar22;
          }
          else {
            uVar17 = *(uint *)(local_b4 + -4);
            uVar16 = uVar22 + uVar17;
          }
          cVar11 = FUN_146d4e40100(&local_b8);
          if (cVar11 == '\0') goto LAB_146d4e5b8c4;
          if (uVar21 != 0) {
            lVar2 = local_b4 + (ulonglong)uVar17 * 2;
            if (uVar22 < 0x10) {
              uVar14 = 0;
            }
            else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
              uVar14 = 0;
            }
            else {
              uVar19 = 0;
              uVar14 = (ulonglong)(uVar22 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar1 + uVar19);
                uVar8 = puVar3[1];
                uVar9 = puVar3[2];
                uVar10 = puVar3[3];
                puVar4 = (undefined4 *)(lVar2 + uVar19);
                *puVar4 = *puVar3;
                puVar4[1] = uVar8;
                puVar4[2] = uVar9;
                puVar4[3] = uVar10;
                uVar19 = uVar19 + 0x10;
              } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar14 == uVar21) goto LAB_146d4e5b692;
            }
            do {
              *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(lVar1 + uVar14 * 2);
              uVar14 = uVar14 + 1;
            } while (uVar21 != uVar14);
          }
LAB_146d4e5b692:
          *(uint *)(local_b4 + -4) = uVar16;
          *(undefined2 *)(local_b4 + (ulonglong)uVar16 * 2) = 0;
        }
      }
      FUN_146d4e407d0(&local_a8,&local_b8,0,0x146d4e65ec8);
      lVar1 = CONCAT44(local_a0,uStack_a4);
      if ((int)uVar15 == 4) {
        if (_DAT_146d4e68444 == lVar1) {
LAB_146d4e5b7f4:
          uVar20 = 0;
          goto LAB_146d4e5b7f6;
        }
        if ((_DAT_146d4e68444 != 0) && (lVar1 != 0)) {
          uVar22 = *(uint *)(_DAT_146d4e68444 + -4);
          uVar17 = *(uint *)(lVar1 + -4);
          uVar16 = uVar17;
          if (uVar22 < uVar17) {
            uVar16 = uVar22;
          }
          iVar13 = uVar22 - uVar17;
          if (uVar16 != 0) {
            uVar21 = 1;
            do {
              uVar5 = *(ushort *)(_DAT_146d4e68444 + -2 + uVar21 * 2);
              uVar6 = *(ushort *)(lVar1 + -2 + uVar21 * 2);
              bVar23 = uVar5 == uVar6;
              uVar15 = CONCAT71((int7)(uVar15 >> 8),bVar23);
              if (uVar16 <= uVar21) break;
              uVar21 = uVar21 + 1;
            } while (bVar23);
            if (!bVar23) {
              iVar13 = (uint)uVar5 - (uint)uVar6;
            }
          }
          if (iVar13 == 0) goto LAB_146d4e5b7f4;
        }
        puVar12 = &DAT_146d4e68440;
        uVar20 = 0x146d4e65ed8;
      }
      else {
        if (_DAT_146d4e68454 == lVar1) goto LAB_146d4e5b7f4;
        if ((_DAT_146d4e68454 != 0) && (lVar1 != 0)) {
          uVar22 = *(uint *)(_DAT_146d4e68454 + -4);
          uVar17 = *(uint *)(lVar1 + -4);
          uVar16 = uVar17;
          if (uVar22 < uVar17) {
            uVar16 = uVar22;
          }
          iVar13 = uVar22 - uVar17;
          if (uVar16 != 0) {
            uVar21 = 1;
            do {
              uVar5 = *(ushort *)(_DAT_146d4e68454 + -2 + uVar21 * 2);
              uVar6 = *(ushort *)(lVar1 + -2 + uVar21 * 2);
              bVar23 = uVar5 == uVar6;
              uVar15 = CONCAT71((int7)(uVar15 >> 8),bVar23);
              if (uVar16 <= uVar21) break;
              uVar21 = uVar21 + 1;
            } while (bVar23);
            if (!bVar23) {
              iVar13 = (uint)uVar5 - (uint)uVar6;
            }
          }
          if (iVar13 == 0) goto LAB_146d4e5b7f4;
        }
        puVar12 = &DAT_146d4e68450;
        uVar20 = 0x146d4e65ee8;
      }
      FUN_146d4e407d0(puVar12,&local_a8,0,uVar20);
      uVar20 = CONCAT71((int7)(uVar15 >> 8),1);
LAB_146d4e5b7f6:
      FUN_146d4e400a0(&local_a8);
      FUN_146d4e400a0(&local_78);
      FUN_146d4e400a0(&local_e8);
      FUN_146d4e400a0(&local_98);
      FUN_146d4e400a0(&local_d8);
      FUN_146d4e400a0(&local_c8);
      FUN_146d4e400a0(&local_88);
      FUN_146d4e400a0(&local_b8);
      return uVar20;
    }
    uVar22 = *(uint *)(local_94 + -4);
    uVar21 = (ulonglong)uVar22;
    if ((uVar21 == 0) && (local_d4 != 0)) goto LAB_146d4e5b421;
    if (local_d4 == 0) {
      uVar15 = 0;
      uVar17 = uVar22;
    }
    else {
      uVar15 = (ulonglong)*(uint *)(local_d4 + -4);
      uVar17 = uVar22 + *(uint *)(local_d4 + -4);
    }
    local_9c = param_1;
    cVar11 = FUN_146d4e40100(&local_d8);
    if (cVar11 != '\0') {
      if (uVar21 != 0) {
        lVar2 = local_d4 + uVar15 * 2;
        if (uVar22 < 0x10) {
          uVar15 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar1) < 0x20) {
          uVar15 = 0;
        }
        else {
          uVar14 = 0;
          uVar15 = (ulonglong)(uVar22 & 0xfffffff8);
          do {
            puVar3 = (undefined4 *)(lVar1 + uVar14);
            uVar8 = puVar3[1];
            uVar9 = puVar3[2];
            uVar10 = puVar3[3];
            puVar4 = (undefined4 *)(lVar2 + uVar14);
            *puVar4 = *puVar3;
            puVar4[1] = uVar8;
            puVar4[2] = uVar9;
            puVar4[3] = uVar10;
            uVar14 = uVar14 + 0x10;
          } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar14);
          if (uVar15 == uVar21) goto LAB_146d4e5b412;
        }
        do {
          *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(lVar1 + uVar15 * 2);
          uVar15 = uVar15 + 1;
        } while (uVar21 != uVar15);
      }
LAB_146d4e5b412:
      uVar15 = (ulonglong)local_9c;
      *(uint *)(local_d4 + -4) = uVar17;
      *(undefined2 *)(local_d4 + (ulonglong)uVar17 * 2) = 0;
      goto LAB_146d4e5b421;
    }
  }
  else {
    if (local_e4 != 0) {
      uVar22 = *(uint *)(local_e4 + -4);
    }
    uVar16 = _DAT_146d4e635d4 + uVar22;
    cVar11 = FUN_146d4e40100(&local_e8);
    if (cVar11 != '\0') {
      if (uVar21 != 0) {
        lVar1 = local_e4 + (ulonglong)uVar22 * 2;
        if ((uVar17 < 0x10) || (lVar1 - 0x146d4e635d8U < 0x20)) {
          uVar14 = 0;
        }
        else {
          uVar19 = 0;
          uVar14 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar8 = *(undefined4 *)(uVar19 + 0x146d4e635dc);
            uVar9 = *(undefined4 *)(uVar19 + 0x146d4e635e0);
            uVar10 = *(undefined4 *)(uVar19 + 0x146d4e635e4);
            puVar3 = (undefined4 *)(lVar1 + uVar19);
            *puVar3 = *(undefined4 *)(&DAT_146d4e635d8 + uVar19);
            puVar3[1] = uVar8;
            puVar3[2] = uVar9;
            puVar3[3] = uVar10;
            uVar19 = uVar19 + 0x10;
          } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar19);
          if (uVar14 == uVar21) goto LAB_146d4e5b252;
        }
        do {
          *(undefined2 *)(lVar1 + uVar14 * 2) = *(undefined2 *)(&DAT_146d4e635d8 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar21 != uVar14);
      }
LAB_146d4e5b252:
      *(uint *)(local_e4 + -4) = uVar16;
      *(undefined2 *)(local_e4 + (ulonglong)uVar16 * 2) = 0;
      goto LAB_146d4e5b25d;
    }
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3603e4000001f9);
LAB_146d4e5b884:
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3b03e5000001f9);
  }
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x3c03e4000001f9);
LAB_146d4e5b8c4:
  (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x4103e5000001f9);
  pcVar7 = (code *)swi(3);
  uVar20 = (*pcVar7)();
  return uVar20;
}



/* Address: 146d4e5b8f0 */

/* WARNING: Removing unreachable block (ram,0x0146d4e5b9e6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_146d4e5b8f0(uint param_1,double param_2,double param_3,double param_4,char param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  double dVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong in_R9;
  double dVar11;
  ulonglong local_58;
  double local_50;
  
  if (_DAT_146d4e6852c == &DAT_146d4e5e908) {
    iVar7 = 0;
joined_r0x0146d4e5b99d:
    if (iVar7 == 0) {
      return 0.0;
    }
  }
  else if (_DAT_146d4e6852c != (undefined1 *)0x0) {
    uVar3 = *(uint *)(_DAT_146d4e6852c + -4);
    in_R9 = (ulonglong)uVar3;
    uVar9 = _DAT_146d4e5e904;
    if (uVar3 < _DAT_146d4e5e904) {
      uVar9 = uVar3;
    }
    iVar7 = uVar3 - _DAT_146d4e5e904;
    if (uVar9 != 0) {
      in_R9 = 0;
      do {
        uVar1 = *(ushort *)(_DAT_146d4e6852c + in_R9 * 2);
        uVar2 = *(ushort *)(&DAT_146d4e5e908 + in_R9 * 2);
        in_R9 = in_R9 + 1;
        if (uVar9 <= in_R9) break;
      } while (uVar1 == uVar2);
      if (uVar1 != uVar2) {
        iVar7 = (uint)uVar1 - (uint)uVar2;
      }
    }
    goto joined_r0x0146d4e5b99d;
  }
  if (param_4 <= 0.0) {
    return 0.0;
  }
  if (param_2 <= 0.0) {
    return 0.0;
  }
  if (param_3 <= 0.0) {
    return 0.0;
  }
  param_1 = param_1 & 0xfffffffb;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
    if (param_1 != 1) {
      return 0.0;
    }
  }
  bVar5 = param_2 < param_3;
  if (param_1 == 0) {
    bVar5 = param_3 < param_2;
  }
  if (!bVar5) {
    return 0.0;
  }
  local_58 = 0;
  cVar6 = (*(code *)0x7ff63a108cc0)(0,uVar8,0x146d4e68528,in_R9,param_2,param_3,&local_58);
  if (cVar6 == '\0') {
    return 0.0;
  }
  dVar11 = (double)(local_58 & _DAT_146d4e5e720);
  if (param_5 == '\0') {
    return dVar11;
  }
  dVar4 = 0.0;
  if (_DAT_146d4e6852c != &DAT_146d4e5e908) {
    if (_DAT_146d4e6852c != (undefined1 *)0x0) {
      uVar3 = *(uint *)(_DAT_146d4e6852c + -4);
      uVar9 = _DAT_146d4e5e904;
      if (uVar3 < _DAT_146d4e5e904) {
        uVar9 = uVar3;
      }
      iVar7 = uVar3 - _DAT_146d4e5e904;
      if (uVar9 != 0) {
        uVar10 = 0;
        do {
          uVar1 = *(ushort *)(_DAT_146d4e6852c + uVar10 * 2);
          uVar2 = *(ushort *)(&DAT_146d4e5e908 + uVar10 * 2);
          uVar10 = uVar10 + 1;
          if (uVar9 <= uVar10) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar7 = (uint)uVar1 - (uint)uVar2;
        }
      }
      dVar4 = 0.0;
      if (iVar7 == 0) goto LAB_146d4e5bb3a;
    }
    local_50 = 0.0;
    cVar6 = FUN_146d4e5acd0(dVar11);
    dVar4 = 0.0;
    if ((cVar6 != '\0') && (dVar4 = 0.0, 0.0 < local_50)) {
      dVar4 = local_50 * param_4 + local_50 * param_4;
    }
  }
LAB_146d4e5bb3a:
  return dVar11 + dVar4;
}



/* Address: 146d4e5bb60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_146d4e5bb60(undefined8 param_1,longlong param_2,double param_3,double param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  double dVar6;
  double dVar7;
  char cVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  double dVar14;
  undefined4 local_d8;
  longlong local_d4;
  undefined1 local_c8 [8];
  double local_c0;
  double local_b8;
  
  local_d8 = 0;
  local_d4 = 0;
  puVar5 = *(undefined1 **)(param_2 + 4);
  if (puVar5 != &DAT_146d4e5e908) {
    if (puVar5 != (undefined1 *)0x0) {
      uVar3 = *(uint *)(puVar5 + -4);
      uVar4 = _DAT_146d4e5e904;
      if (uVar3 < _DAT_146d4e5e904) {
        uVar4 = uVar3;
      }
      iVar9 = uVar3 - _DAT_146d4e5e904;
      if (uVar4 != 0) {
        uVar13 = 0;
        do {
          uVar1 = *(ushort *)(puVar5 + uVar13 * 2);
          uVar2 = *(ushort *)(&DAT_146d4e5e908 + uVar13 * 2);
          uVar13 = uVar13 + 1;
          if (uVar4 <= uVar13) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar9 == 0) goto LAB_146d4e5bea0;
    }
    cVar8 = (*(code *)0x7ff63a107ee0)(0x146d2d8aad8,param_1);
    if (cVar8 != '\0') {
      (*(code *)0x7ff63a108010)(0x146d2d8aad8,0);
      FUN_146d4e407d0(&local_d8,&DAT_146d4e6853c,1,0x146d4e656e8);
      lVar11 = *(longlong *)(param_2 + 4);
      if (local_d4 != lVar11) {
        uVar13 = 0;
        if ((local_d4 == 0) || (lVar11 == 0)) goto LAB_146d4e5bea2;
        uVar3 = *(uint *)(local_d4 + -4);
        uVar4 = *(uint *)(lVar11 + -4);
        uVar12 = uVar4;
        if (uVar3 < uVar4) {
          uVar12 = uVar3;
        }
        iVar9 = uVar3 - uVar4;
        if (uVar12 != 0) {
          uVar13 = 1;
          do {
            uVar1 = *(ushort *)(local_d4 + -2 + uVar13 * 2);
            uVar2 = *(ushort *)(lVar11 + -2 + uVar13 * 2);
            if (uVar12 <= uVar13) break;
            uVar13 = uVar13 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar9 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar9 != 0) goto LAB_146d4e5bea0;
      }
      cVar8 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,param_2,local_c8);
      if (cVar8 != '\0') {
        uVar10 = (*(code *)0x7ff63a107fc0)(0x146d2d8aad8,2);
        lVar11 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,param_2,0x1f);
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_2,0x10);
        dVar6 = (double)lVar11 * _DAT_146d4e68548;
        lVar11 = (*(code *)0x7ff63a0f2970)(0x146d2d8aad8,param_2,0x20);
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_2,0x10);
        dVar7 = (double)lVar11 * _DAT_146d4e68548;
        (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_2,0x1b);
        if (_DAT_146d4e68548 <= 0.0) {
          (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_2,0x10);
        }
        dVar14 = _DAT_146d4e68548;
        if (_DAT_146d4e68548 <= 0.0) {
          dVar14 = _DAT_146d4e68518;
        }
        if (dVar6 <= dVar7) {
          dVar6 = dVar7;
        }
        dVar6 = dVar6 + dVar14 * _DAT_146d4e5e730;
        if ((int)uVar10 == 1) {
          if (((param_3 <= 0.0) || (local_b8 + dVar6 < param_3)) &&
             ((param_4 <= 0.0 || (param_4 < local_b8 - dVar6)))) goto LAB_146d4e5be9b;
        }
        else if ((((int)uVar10 == 0) && ((param_3 <= 0.0 || (param_3 < local_c0 - dVar6)))) &&
                ((param_4 <= 0.0 || (dVar6 + local_c0 < param_4)))) {
LAB_146d4e5be9b:
          uVar13 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
          goto LAB_146d4e5bea2;
        }
      }
    }
  }
LAB_146d4e5bea0:
  uVar13 = 0;
LAB_146d4e5bea2:
  FUN_146d4e400a0(&local_d8);
  return uVar13 & 0xffffffff;
}



/* Address: 146d4e5bef0 */

ulonglong FUN_146d4e5bef0(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                         undefined8 param_4)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 unaff_RBP;
  ulonglong uVar4;
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
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined1 local_108 [200];
  
  if (DAT_146d4e6806f == '\x01') {
    cVar2 = FUN_146d4e5bb60(param_1,param_2,(int)param_3,(int)param_4);
    if (cVar2 == '\0') {
      uVar4 = 0;
      goto LAB_146d4e5c242;
    }
  }
  lVar1 = (longlong)&local_228 + 4;
  local_1d4 = 0;
  local_1d0 = 0;
  local_114 = 0;
  local_110 = 0;
  local_228 = 0;
  uStack_220 = 0;
  local_238 = 0;
  uStack_234 = 0;
  uStack_230 = 0;
  uStack_22c = 0;
  FUN_146d4e400a0(lVar1);
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_208 = 0;
  uStack_200 = 0;
  local_218 = 0;
  uStack_210 = 0;
  local_1d8 = 0;
  FUN_146d4e400a0(&local_1d4);
  local_150 = 0;
  local_158 = 0;
  local_160 = 0;
  local_168 = 0;
  local_170 = 0;
  local_178 = 0;
  local_180 = 0;
  local_188 = 0;
  local_190 = 0;
  local_198 = 0;
  local_1a0 = 0;
  local_1a8 = 0;
  local_1b0 = 0;
  local_1b8 = 0;
  local_1c0 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_118 = 0;
  FUN_146d4e400a0(&local_114);
  (*(code *)0x7ff63a3fad20)(local_108,0,0x84);
  local_238 = 6;
  local_1c8 = param_1;
  FUN_146d4e407d0(lVar1,param_2,0,0x146d4e656d8);
  uStack_234 = 0xa0a3;
  if (DAT_146d4e68059 == '\0') {
    uStack_234 = 0;
  }
  uStack_230 = 0;
  uStack_200 = param_3;
  local_1f8 = param_4;
  cVar2 = (*(code *)0x7ff63a108b70)(0x146d2d8aad8,&local_238,&local_148);
  if (cVar2 == '\0') {
    uVar3 = 0x146d4e61c20;
LAB_146d4e5c1ae:
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,2,6,0x590008,uVar3,0x560015,param_1,0x590008,0x146d4e61c50,0x530014,
               (int)local_148,0x590008,0x146d4e61c80,0x590008,&local_114);
    uVar4 = 0;
  }
  else {
    uVar4 = CONCAT71((int7)((ulonglong)unaff_RBP >> 8),1);
    if ((int)local_148 != 0x2719) {
      uVar3 = 0x146d4e61ce8;
      goto LAB_146d4e5c1ae;
    }
  }
  FUN_146d4e400a0(&local_114);
  FUN_146d4e400a0(&local_1d4);
  FUN_146d4e400a0(lVar1);
LAB_146d4e5c242:
  return uVar4 & 0xffffffff;
}



/* Address: 146d4e5c280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e5c280(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined4 param_7)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined8 in_stack_ffffffffffffff10;
  undefined4 uVar17;
  undefined8 uVar16;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);
  local_78 = 0;
  local_74 = 0;
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,param_1);
  if (iVar9 < 0) {
    uVar16 = CONCAT44(uVar17,0x590008);
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,8,0x550005,0,uVar16,param_1,0x520004,2,0x520004,0,0x540005,
               param_2,0x580007,param_3,0x540005,param_4,0x580007,param_3);
    uVar17 = (undefined4)((ulonglong)uVar16 >> 0x20);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,0,param_2,param_3);
    uVar16 = param_3;
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,1,param_4,param_3);
    uVar17 = (undefined4)((ulonglong)uVar16 >> 0x20);
  }
  uVar11 = 0;
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,1,2);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,2,1);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3ec,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0xd0,1);
  local_68 = 0;
  local_64 = 0;
  FUN_146d4e407d0(&local_78,param_1,0,0x146d4e65ba8);
  uVar7 = _DAT_146d4e61ba8;
  uVar12 = (ulonglong)_DAT_146d4e61ba8;
  if ((uVar12 == 0) && (local_74 != 0)) goto LAB_146d4e5c5cf;
  if (local_74 != 0) {
    uVar11 = *(uint *)(local_74 + -4);
  }
  uVar15 = _DAT_146d4e61ba8 + uVar11;
  uVar10 = 0x104;
  if ((0x103 < uVar15) &&
     ((0x7ffffffd < uVar15 || (uVar10 = (uVar15 >> 2) + uVar15, 0x7ffffffd < uVar10)))) {
    uVar10 = 0x7ffffffe;
  }
  cVar8 = FUN_146d4e40100(&local_78,uVar10);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x210f9b000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar12 != 0) {
    lVar1 = local_74 + (ulonglong)uVar11 * 2;
    if (uVar7 < 0x10) {
      uVar13 = 0;
    }
    else if (lVar1 - 0x146d4e61bacU < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar14 = 0;
      uVar13 = (ulonglong)(uVar7 & 0xfffffff8);
      do {
        uVar4 = *(undefined4 *)(uVar14 + 0x146d4e61bb0);
        uVar5 = *(undefined4 *)(uVar14 + 0x146d4e61bb4);
        uVar6 = *(undefined4 *)(uVar14 + 0x146d4e61bb8);
        puVar2 = (undefined4 *)(lVar1 + uVar14);
        *puVar2 = *(undefined4 *)(&DAT_146d4e61bac + uVar14);
        puVar2[1] = uVar4;
        puVar2[2] = uVar5;
        puVar2[3] = uVar6;
        uVar14 = uVar14 + 0x10;
      } while ((uVar12 * 2 & 0xfffffffffffffff0) != uVar14);
      if (uVar13 == uVar12) goto LAB_146d4e5c5c2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(&DAT_146d4e61bac + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar12 != uVar13);
  }
LAB_146d4e5c5c2:
  *(uint *)(local_74 + -4) = uVar15;
  *(undefined2 *)(local_74 + (ulonglong)uVar15 * 2) = 0;
LAB_146d4e5c5cf:
  FUN_146d4e407d0(&local_68,&local_78,0,0x146d4e65bb8);
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,&local_68);
  if (iVar9 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,6,0x550005,0,CONCAT44(uVar17,0x590008),&local_68,0x520004,0x65,
               0x520004,0,0x540005,param_2,0x580007,param_3);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,&local_68,0,param_2,param_3);
  }
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_68,6,param_6);
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_68,0x3e9,0x146d4e632a8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0x3ea,8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0x3f3,param_7);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0xd0,1);
  FUN_146d4e400a0(&local_68);
  FUN_146d4e400a0(&local_78);
  return;
}



/* Address: 146d4e5c7e0 */

void FUN_146d4e5c7e0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
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
  (*(code *)0x7ff63a0c7410)(0x146d2d8aad8,3);
  FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e65788);
  FUN_146d4e407d0(&local_70,&local_50,0,0x146d4e65798);
  FUN_146d4e40270(&local_70,0x146d4e623a8);
  FUN_146d4e40270(&local_70,0x146d4e5e9e0);
  FUN_146d4e40270(&local_70,&DAT_146d4e623d8);
  FUN_146d4e40270(&local_70,0x146d4e623e8);
  local_80 = 0;
  local_7c = 0;
  FUN_146d4e407d0(&local_80,0x146d4e68528,1,0x146d4e657a8);
  FUN_146d4e40270(&local_80,0x146d4e623a8);
  FUN_146d4e40270(&local_80,0x146d4e5e9e0);
  FUN_146d4e40270(&local_80,&DAT_146d4e623d8);
  uVar2 = 0xa0a3;
  if (DAT_146d4e68059 == '\0') {
    uVar2 = 0;
  }
  uVar1 = (*(code *)0x7ff63a0c73c0)(0x146d2d8aad8,0);
  (*(code *)0x7ff63a0e49f0)
            (0x146d2d8aad8,0xd8,5,0x590008,0x146d4e62440,0x550005,uVar1,0x560015,uVar2,0x590008,
             &local_70,0x590008,&local_80);
  FUN_146d4e407d0(&local_50,&DAT_146d4e6853c,1,0x146d4e657b8);
  FUN_146d4e407d0(&local_60,&local_50,0,0x146d4e657c8);
  FUN_146d4e400a0(&local_80);
  FUN_146d4e400a0(&local_70);
  FUN_146d4e407d0(&DAT_146d4e6853c,&local_60,1,0x146d4e657d8);
  FUN_146d4e400a0(&local_60);
  FUN_146d4e400a0(&local_50);
  return;
}



/* Address: 146d4e5ca60 */

undefined8
FUN_146d4e5ca60(longlong param_1,int param_2,char *param_3,double *param_4,double *param_5)

{
  double dVar1;
  uint uVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar6;
  double dVar7;
  double dVar8;
  ulonglong uVar5;
  
  *param_4 = 0.0;
  *param_5 = 0.0;
  if (*param_3 == '\0') {
    return 0;
  }
  uVar2 = *(uint *)(param_3 + 0x11);
  uVar6 = 0;
  if ((-1 < (int)uVar2) && ((int)uVar2 < param_2)) {
    if (*(uint *)(param_1 + 8) <= uVar2) {
      (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x290ffa000001f6);
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    uVar5 = (ulonglong)*(uint *)(param_1 + 8) + ~(ulonglong)uVar2;
    if ((*(ushort *)(param_1 + 2) & 0x10) == 0) {
      uVar5 = (ulonglong)uVar2;
    }
    lVar4 = uVar5 * 0x3c;
    dVar8 = *(double *)(*(longlong *)(param_1 + 0x1c) + 8 + lVar4);
    dVar1 = *(double *)(*(longlong *)(param_1 + 0x1c) + 0x20 + lVar4);
    dVar7 = dVar8;
    if (dVar1 <= dVar8) {
      dVar7 = dVar1;
    }
    if (dVar8 <= dVar1) {
      dVar8 = dVar1;
    }
    *param_4 = dVar8;
    *param_5 = dVar7;
    uVar6 = CONCAT71((int7)((ulonglong)lVar4 >> 8),dVar7 < *param_4);
  }
  return uVar6;
}



/* Address: 146d4e5cb10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e5cb10(undefined8 param_1,longlong param_2,double param_3,longlong param_4,
                    double param_5,undefined4 param_6,undefined8 param_7)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined8 in_stack_ffffffffffffff00;
  undefined4 uVar18;
  double dVar16;
  undefined8 uVar17;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  undefined8 local_74;
  
  uVar18 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  local_88 = 0;
  local_84 = 0;
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,param_1);
  if (iVar9 < 0) {
    uVar17 = CONCAT44(uVar18,0x590008);
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,8,0x550005,0,uVar17,param_1,0x520004,0x14,0x520004,0,0x540005,
               param_2,0x580007,param_3,0x540005,param_4,0x580007,param_5);
    uVar18 = (undefined4)((ulonglong)uVar17 >> 0x20);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,0,param_2,param_3);
    dVar16 = param_5;
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,1,param_4,param_5);
    uVar18 = (undefined4)((ulonglong)dVar16 >> 0x20);
  }
  uVar15 = 0;
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0,param_6);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,1,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,2,2);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x407,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,3,1);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0xd0,1);
  local_78 = 0;
  local_74 = 0;
  FUN_146d4e407d0(&local_88,param_1,0,0x146d4e65bc8);
  uVar7 = _DAT_146d4e61ba8;
  uVar11 = (ulonglong)_DAT_146d4e61ba8;
  if ((uVar11 == 0) && (local_84 != 0)) goto LAB_146d4e5ce8d;
  if (local_84 != 0) {
    uVar15 = *(uint *)(local_84 + -4);
  }
  uVar12 = _DAT_146d4e61ba8 + uVar15;
  uVar10 = 0x104;
  if ((0x103 < uVar12) &&
     ((0x7ffffffd < uVar12 || (uVar10 = (uVar12 >> 2) + uVar12, 0x7ffffffd < uVar10)))) {
    uVar10 = 0x7ffffffe;
  }
  cVar8 = FUN_146d4e40100(&local_88,uVar10);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x210fbc000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar11 != 0) {
    lVar1 = local_84 + (ulonglong)uVar15 * 2;
    if (uVar7 < 0x10) {
      uVar13 = 0;
    }
    else if (lVar1 - 0x146d4e61bacU < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar14 = 0;
      uVar13 = (ulonglong)(uVar7 & 0xfffffff8);
      do {
        uVar4 = *(undefined4 *)(uVar14 + 0x146d4e61bb0);
        uVar5 = *(undefined4 *)(uVar14 + 0x146d4e61bb4);
        uVar6 = *(undefined4 *)(uVar14 + 0x146d4e61bb8);
        puVar2 = (undefined4 *)(lVar1 + uVar14);
        *puVar2 = *(undefined4 *)(&DAT_146d4e61bac + uVar14);
        puVar2[1] = uVar4;
        puVar2[2] = uVar5;
        puVar2[3] = uVar6;
        uVar14 = uVar14 + 0x10;
      } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar14);
      if (uVar13 == uVar11) goto LAB_146d4e5ce82;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(&DAT_146d4e61bac + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar11 != uVar13);
  }
LAB_146d4e5ce82:
  *(uint *)(local_84 + -4) = uVar12;
  *(undefined2 *)(local_84 + (ulonglong)uVar12 * 2) = 0;
LAB_146d4e5ce8d:
  FUN_146d4e407d0(&local_78,&local_88,0,0x146d4e65bd8);
  dVar16 = (param_3 + param_5) * _DAT_146d4e5e738;
  param_2 = (param_4 - param_2) / 2 + param_2;
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,&local_78);
  if (iVar9 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,6,0x550005,0,CONCAT44(uVar18,0x590008),&local_78,0x520004,0x65,
               0x520004,0,0x540005,param_2,0x580007,dVar16);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,&local_78,0,param_2,dVar16);
  }
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_78,6,param_7);
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_78,0x3e9,0x146d4e632a8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_78,0x3ea,8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_78,0,param_6);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_78,0x3f3,8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_78,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_78,0xd0,1);
  FUN_146d4e400a0(&local_78);
  FUN_146d4e400a0(&local_88);
  return;
}



/* Address: 146d4e5d0d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_146d4e5d0d0(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4,
                    undefined4 param_5,undefined8 param_6,undefined4 param_7)

{
  longlong lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined8 in_stack_ffffffffffffff10;
  undefined4 uVar17;
  undefined8 uVar16;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);
  local_78 = 0;
  local_74 = 0;
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,param_1);
  if (iVar9 < 0) {
    uVar16 = CONCAT44(uVar17,0x590008);
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,8,0x550005,0,uVar16,param_1,0x520004,2,0x520004,0,0x540005,
               param_2,0x580007,param_3,0x540005,param_4,0x580007,param_3);
    uVar17 = (undefined4)((ulonglong)uVar16 >> 0x20);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,0,param_2,param_3);
    uVar16 = param_3;
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,param_1,1,param_4,param_3);
    uVar17 = (undefined4)((ulonglong)uVar16 >> 0x20);
  }
  uVar15 = 0;
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,1,1);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,2,2);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3ec,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0xd0,1);
  local_68 = 0;
  local_64 = 0;
  FUN_146d4e407d0(&local_78,param_1,0,0x146d4e65be8);
  uVar7 = _DAT_146d4e61ba8;
  uVar11 = (ulonglong)_DAT_146d4e61ba8;
  if ((uVar11 == 0) && (local_74 != 0)) goto LAB_146d4e5d41d;
  if (local_74 != 0) {
    uVar15 = *(uint *)(local_74 + -4);
  }
  uVar12 = _DAT_146d4e61ba8 + uVar15;
  uVar10 = 0x104;
  if ((0x103 < uVar12) &&
     ((0x7ffffffd < uVar12 || (uVar10 = (uVar12 >> 2) + uVar12, 0x7ffffffd < uVar10)))) {
    uVar10 = 0x7ffffffe;
  }
  cVar8 = FUN_146d4e40100(&local_78,uVar10);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x146d2d8aad8,0x210fdf000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar11 != 0) {
    lVar1 = local_74 + (ulonglong)uVar15 * 2;
    if (uVar7 < 0x10) {
      uVar13 = 0;
    }
    else if (lVar1 - 0x146d4e61bacU < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar14 = 0;
      uVar13 = (ulonglong)(uVar7 & 0xfffffff8);
      do {
        uVar4 = *(undefined4 *)(uVar14 + 0x146d4e61bb0);
        uVar5 = *(undefined4 *)(uVar14 + 0x146d4e61bb4);
        uVar6 = *(undefined4 *)(uVar14 + 0x146d4e61bb8);
        puVar2 = (undefined4 *)(lVar1 + uVar14);
        *puVar2 = *(undefined4 *)(&DAT_146d4e61bac + uVar14);
        puVar2[1] = uVar4;
        puVar2[2] = uVar5;
        puVar2[3] = uVar6;
        uVar14 = uVar14 + 0x10;
      } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar14);
      if (uVar13 == uVar11) goto LAB_146d4e5d412;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(&DAT_146d4e61bac + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar11 != uVar13);
  }
LAB_146d4e5d412:
  *(uint *)(local_74 + -4) = uVar12;
  *(undefined2 *)(local_74 + (ulonglong)uVar12 * 2) = 0;
LAB_146d4e5d41d:
  FUN_146d4e407d0(&local_68,&local_78,0,0x146d4e65bf8);
  param_2 = (param_4 - param_2) / 2 + param_2;
  iVar9 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,&local_68);
  if (iVar9 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,6,0x550005,0,CONCAT44(uVar17,0x590008),&local_68,0x520004,0x65,
               0x520004,0,0x540005,param_2,0x580007,param_3);
  }
  else {
    (*(code *)0x7ff63a0f39d0)(0x146d2d8aad8,0,&local_68,0,param_2,param_3);
  }
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_68,6,param_6);
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,&local_68,0x3e9,0x146d4e632a8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0x3ea,8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0,param_5);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0x3f3,param_7);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,&local_68,0xd0,1);
  FUN_146d4e400a0(&local_68);
  FUN_146d4e400a0(&local_78);
  return;
}



/* Address: 146d4e5d650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_146d4e5d650(undefined8 param_1,char param_2,undefined8 param_3,uint *param_4,double *param_5,
               longlong param_6)

{
  double dVar1;
  char cVar2;
  ulonglong uVar3;
  bool bVar4;
  double dVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double local_80 [8];
  
  cVar2 = (*(code *)0x7ff63a0f2c10)(0x146d2d8aad8,param_1,param_6);
  if (cVar2 != '\0') {
    (*(code *)0x7ff63a0f2890)(0x146d2d8aad8,param_1,0x22);
    dVar5 = (double)FUN_146d4e59600(param_1);
    if (0.0 < dVar5) {
      (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x2a);
      uVar6 = SUB84(_DAT_146d4e68548,0);
      uVar7 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
      if (_DAT_146d4e68548 <= 0.0) {
        (*(code *)0x7ff63a0c7370)(0x146d2d8aad8,0x25);
        uVar6 = SUB84(_DAT_146d4e68548,0);
        uVar7 = (undefined4)((ulonglong)_DAT_146d4e68548 >> 0x20);
      }
      bVar4 = param_2 == '\0';
      uVar3 = (ulonglong)!bVar4;
      dVar1 = (double)CONCAT44(uVar7,uVar6) * _DAT_146d4e5e740;
      local_80[0] = 0.0;
      cVar2 = (*(code *)0x7ff63a108d40)
                        (0x146d2d8aad8,bVar4,param_1,dVar5,*(undefined8 *)(param_6 + 8 + uVar3 * 8),
                         local_80);
      if (((cVar2 == '\0') || (local_80[0] <= 0.0)) || (dVar1 < local_80[0])) {
        local_80[0] = 0.0;
        cVar2 = (*(code *)0x7ff63a108d40)
                          (0x146d2d8aad8,uVar3,param_1,dVar5,
                           *(undefined8 *)(param_6 + 8 + (ulonglong)(param_2 == '\0') * 8),local_80)
        ;
        if (cVar2 == '\0') {
          return 0;
        }
        if (local_80[0] <= 0.0) {
          return 0;
        }
        bVar4 = !bVar4;
        if (dVar1 < local_80[0]) {
          return 0;
        }
      }
      FUN_146d4e407d0(param_3,param_1,0,0x146d4e65cf8);
      *param_4 = (uint)bVar4;
      *param_5 = dVar5;
      return 1;
    }
  }
  return 0;
}



/* Address: 146d4e5d870 */

void FUN_146d4e5d870(undefined8 param_1,undefined8 param_2,undefined4 param_3,int param_4,
                    undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = (*(code *)0x7ff63a0f4840)(0x146d2d8aad8,0,param_1);
  if (iVar1 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x146d2d8aad8,0x112,6,0x550005,0,0x590008,param_1,0x520004,0x66,0x520004,0,0x540005,0
               ,0x580007,0);
  }
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,param_1,6,param_2);
  (*(code *)0x7ff63a0f3c80)(0x146d2d8aad8,0,param_1,0x3e9,0x146d4e632a8);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3ea,param_5);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0,param_6);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x402,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3f4,param_3);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3f5,(longlong)param_4);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0x3f3,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,3,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,10,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,4,0);
  (*(code *)0x7ff63a0f3b30)(0x146d2d8aad8,0,param_1,0xd0,1);
  return;
}


