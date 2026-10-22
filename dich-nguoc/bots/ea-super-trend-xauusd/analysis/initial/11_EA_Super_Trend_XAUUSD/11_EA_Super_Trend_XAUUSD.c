/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 2cc08fc0000 */

void FUN_2cc08fc0000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 2cc08fc0060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fc0060(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_2cc08fc01bd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_2cc08fc01bd;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8);
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
        if (uVar15 < 8) goto LAB_2cc08fc0120;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_2cc08fc0120;
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
LAB_2cc08fc0120:
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
          (*(code *)0x7ff63a101200)(0x2cc03e1bbb8,puVar14);
        }
      }
      goto LAB_2cc08fc01bd;
    }
  }
  _DAT_2cc090d2810 = 0x13aa;
  uVar12 = 0;
LAB_2cc08fc01bd:
  return uVar12 & 0xffffffff;
}



/* Address: 2cc08fc01d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fc01d0(int *param_1,longlong param_2,uint param_3)

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
        (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    if (param_3 - 1 < 0xfffffffe) {
      _DAT_2cc090d2810 = 0xfa2;
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
    if ((uVar6 <= *puVar5) && (puVar5[1] == 1)) goto LAB_2cc08fc02a7;
    if (*puVar5 != 0) {
      puVar5 = puVar5 + 1;
      *puVar5 = *puVar5 - 1;
      if (*puVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  piVar3 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8);
  if (piVar3 == (int *)0x0) {
    _DAT_2cc090d2810 = 0x13aa;
    return;
  }
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar4 = piVar3 + 3;
  *(undefined2 *)(piVar3 + 3) = 0;
  *(int **)(param_1 + 1) = piVar4;
  *param_1 = *piVar3;
LAB_2cc08fc02a7:
  if (uVar8 == 0) {
    piVar4[-1] = uVar6;
    *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
    return;
  }
  uVar9 = 0;
  if (uVar8 < 8) goto LAB_2cc08fc0300;
  if ((ulonglong)((longlong)piVar4 - param_2) < 0x20) goto LAB_2cc08fc0300;
  uVar9 = (ulonglong)(uVar6 & 0x7ffffff8);
  uVar10 = 0;
  do {
    uVar2 = ((undefined8 *)(param_2 + uVar10))[1];
    *(undefined8 *)((longlong)piVar4 + uVar10) = *(undefined8 *)(param_2 + uVar10);
    ((undefined8 *)((longlong)piVar4 + uVar10))[1] = uVar2;
    uVar10 = uVar10 + 0x10;
  } while ((uVar7 * 2 & 0xfffffffffffffff0) != uVar10);
  for (; uVar9 != uVar7; uVar9 = uVar9 + 1) {
LAB_2cc08fc0300:
    *(undefined2 *)((longlong)piVar4 + uVar9 * 2) = *(undefined2 *)(param_2 + uVar9 * 2);
  }
  piVar4[-1] = uVar6;
  *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
  if (0x7ffffffe < uVar8) {
    _DAT_2cc090d2810 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2cc08fc03b0 */

ulonglong FUN_2cc08fc03b0(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_2cc08fc04bd;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_2cc08fc04bd;
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
  cVar5 = FUN_2cc08fc0060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_2cc08fc04bd;
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
      if (uVar10 == uVar9) goto LAB_2cc08fc04b2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_2cc08fc04b2:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_2cc08fc04bd:
  return uVar8 & 0xffffffff;
}



/* Address: 2cc08fc04d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fc04d0(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
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
        (*(code *)0x7ff63a101200)(0x2cc03e1bbb8,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_2cc090d2810 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x2cc03e1bbb8,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_2cc08fc0660;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_2cc08fc0660:
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
      (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
      return;
    }
  }
  return;
}



/* Address: 2cc08fc06f0 */

void FUN_2cc08fc06f0(longlong param_1)

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
    (*(code *)0x7ff63a0e6ef0)(0x2cc03e1bbb8,lVar2 - *(int *)(lVar2 + -4),0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 2cc08fc07c0 */

void FUN_2cc08fc07c0(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  (*(code *)0x7ff63a1021d0)(0x2cc03e1bbb8,0,0,param_1,1,param_2,param_3);
  return;
}



/* Address: 2cc08fc0800 */

void FUN_2cc08fc0800(longlong *param_1)

{
  code *pcVar1;
  
  if (*param_1 != 0) {
    if (param_1[4] != 0) {
      (*(code *)0x7ff639cc5c00)(0x2cc03e1bbb8,0x25b,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((*(byte *)((longlong)param_1 + 0x3f) & 0x40) == 0) {
      (*(code *)0x7ff63a0e6ef0)(0x2cc03e1bbb8,*param_1,param_1[9]);
    }
    param_1[2] = 0;
    param_1[3] = 0;
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}



/* Address: 2cc08fc0870 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2cc08fc0870(undefined8 param_1,ulonglong param_2,longlong param_3,longlong param_4)

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
      if (uVar14 < uVar6) goto LAB_2cc08fc0913;
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
      if (uVar9 == param_2) goto LAB_2cc08fc0913;
    }
    uVar13 = uVar12 - 1;
    if ((longlong)uVar9 <= (longlong)param_2) {
      uVar6 = uVar12 + 1;
      uVar13 = uVar14;
    }
    uVar14 = uVar13;
  } while (uVar9 != param_2);
LAB_2cc08fc0913:
  if (psVar7 != (short *)0x0) goto LAB_2cc08fc0a74;
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
LAB_2cc08fc0a25:
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
    if (bVar16) goto LAB_2cc08fc0a25;
  }
  (local_e8 + lVar8 + 2)[uVar13] = 0;
  _DAT_2cc090d2810 = 0xfa3;
  psVar7 = local_e8;
LAB_2cc08fc0a74:
  FUN_2cc08fc01d0(param_1,psVar7,0xffffffff);
  return param_1;
}



/* Address: 2cc08fc0aa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fc0aa0(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  lVar1 = (*(code *)0x7ff63a0e6e70)(0x2cc03e1bbb8,8,0);
  if (lVar1 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    _DAT_2cc090d2810 = 0xfa4;
    uVar3 = 0xfa4;
    lVar2 = 0;
  }
  else {
    *param_1 = lVar1;
    param_1[1] = 1;
    param_1[2] = 1;
    lVar2 = (*(code *)0x7ff639cc7280)(0x2cc03e1bbb8,0x58,1,1,1);
  }
  *(undefined4 *)(param_1 + 8) = uVar3;
  param_1[3] = (ulonglong)(lVar1 != 0);
  param_1[6] = lVar2;
  param_1[7] = 0x58;
  *(undefined4 *)((longlong)param_1 + 0x44) = 8;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[9] = param_2;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return;
}



/* Address: 2cc08fc0b90 */

undefined8 FUN_2cc08fc0b90(void)

{
  return 0;
}



/* Address: 2cc08fc0ba0 */

void FUN_2cc08fc0ba0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x2cc03e1bbb8,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2cc08fc0bf0 */

void FUN_2cc08fc0bf0(undefined8 *param_1)

{
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,*param_1,0x2cc03e09be0);
  param_1[1] = 0x2cc08fdee90;
  return;
}



/* Address: 2cc08fc0c30 */

undefined4 FUN_2cc08fc0c30(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_2cc08fc04d0(&local_70,0x2cc08fdf038,0,0x2cc090cf358);
  local_80 = 0;
  local_7c = 0;
  FUN_2cc08fc04d0(&local_80,0x2cc08fdf038,0,0x2cc090cf368);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x2cc03e1bbb8,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_2cc08fc0e02;
    uVar4 = 0x2cc090cf3a8;
    uVar3 = 0x2cc090cf398;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_2cc08fc0e02;
    uVar4 = 0x2cc090cf388;
    uVar3 = 0x2cc090cf378;
  }
  FUN_2cc08fd80c0(&local_80,param_2,param_3);
  FUN_2cc08fc04d0(&local_60,0x2cc090d283c,1,uVar3);
  FUN_2cc08fd9370(param_1,&local_70,param_2);
  FUN_2cc08fc04d0(&local_50,0x2cc090d283c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x2cc03e1bbb8,0xd,3,0x590008,0x2cc08fdff68,0x590008,&local_50,0x590008,&local_60);
LAB_2cc08fc0e02:
  FUN_2cc08fc0000(&local_80);
  FUN_2cc08fc0000(&local_70);
  FUN_2cc08fc0000(&local_60);
  FUN_2cc08fc0000(&local_50);
  return uVar1;
}



/* Address: 2cc08fc0e40 */

void FUN_2cc08fc0e40(undefined8 *param_1)

{
  FUN_2cc08fc0000(param_1 + 0x41);
  FUN_2cc08fc0000((longlong)param_1 + 0x144);
  FUN_2cc08fc0000((longlong)param_1 + 0x84);
  FUN_2cc08fc0000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,*param_1,0x2cc03e09be0);
  param_1[1] = 0x2cc08fdee90;
  return;
}



/* Address: 2cc08fc0eb0 */

void FUN_2cc08fc0eb0(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x24) != 0) {
    (*(code *)0x7ff63a0f4ce0)(0x2cc03e1bbb8,*(undefined8 *)(param_1 + 0x18),param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x18) = 0;
    FUN_2cc08fc04d0(param_1 + 0x20,0x2cc08fdefd0,0,0x2cc090d0010);
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  }
  (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,param_1 + 0x60);
  if (*(longlong *)(param_1 + 0x34) != 0) {
    (*(code *)0x7ff639d9aa30)(0x2cc03e1bbb8,param_1 + 0x30);
    FUN_2cc08fc04d0(param_1 + 0x30,0x2cc08fdefd0,0,0x2cc090d0020);
  }
  *(undefined8 *)(param_1 + 0x3c) = 0;
  return;
}



/* Address: 2cc08fc0f90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fc0f90(longlong param_1,longlong param_2,int param_3,int param_4,
                         undefined4 param_5)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined8 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  int iVar16;
  int iVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined4 local_c0;
  longlong local_bc;
  undefined4 local_b0;
  longlong local_ac;
  undefined4 local_a0;
  longlong local_9c;
  int local_94;
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
  FUN_2cc08fc0eb0();
  if ((0 < param_3) && (0 < param_4)) {
    iVar10 = (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,param_1 + 0x60,param_4 * param_3,0);
    if (0 < iVar10) {
      local_a0 = 0;
      local_9c = 0;
      local_94 = param_4;
      local_50 = param_2;
      local_48 = param_1 + 0x60;
      uVar13 = (*(code *)0x7ff63a0f5790)(0x2cc03e1bbb8);
      (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,uVar13,0x55,&local_70);
      uVar11 = (*(code *)0x7ff63a3fc2a0)();
      (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,uVar11,0x53,&local_b0);
      FUN_2cc08fc04d0(&local_c0,&local_70);
      lVar14 = local_ac;
      if (local_ac != 0) {
        uVar12 = *(uint *)(local_ac + -4);
        uVar18 = (ulonglong)uVar12;
        if ((uVar18 == 0) && (local_bc != 0)) goto LAB_2cc08fc1249;
        if (local_bc == 0) {
          uVar22 = 0;
          uVar21 = uVar12;
        }
        else {
          uVar22 = *(uint *)(local_bc + -4);
          uVar21 = uVar12 + uVar22;
        }
        cVar9 = FUN_2cc08fc0060(&local_c0);
        if (cVar9 != '\0') {
          if (uVar18 != 0) {
            lVar1 = local_bc + (ulonglong)uVar22 * 2;
            if (uVar12 < 0x10) {
              uVar15 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
              uVar15 = 0;
            }
            else {
              uVar19 = 0;
              uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar14 + uVar19);
                uVar11 = puVar2[1];
                uVar5 = puVar2[2];
                uVar6 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar19);
                *puVar3 = *puVar2;
                puVar3[1] = uVar11;
                puVar3[2] = uVar5;
                puVar3[3] = uVar6;
                uVar19 = uVar19 + 0x10;
              } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar15 == uVar18) goto LAB_2cc08fc1232;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2cc08fc1232:
          *(uint *)(local_bc + -4) = uVar21;
          *(undefined2 *)(local_bc + (ulonglong)uVar21 * 2) = 0;
          goto LAB_2cc08fc1249;
        }
LAB_2cc08fc1a1c:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2300ff000b01f9);
LAB_2cc08fc1a3c:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3e00ff000b01f9);
LAB_2cc08fc1a5c:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x140101000b01f9);
LAB_2cc08fc1a7c:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3d0101000b01f9);
        pcVar4 = (code *)swi(3);
        uVar18 = (*pcVar4)();
        return uVar18;
      }
LAB_2cc08fc1249:
      uVar12 = 0;
      FUN_2cc08fc04d0(&local_90,&local_c0,0,0x2cc090cff90);
      uVar22 = _DAT_2cc08fe0f7c;
      uVar18 = (ulonglong)_DAT_2cc08fe0f7c;
      if ((uVar18 != 0) || (local_8c == 0)) {
        if (local_8c != 0) {
          uVar12 = *(uint *)(local_8c + -4);
        }
        uVar20 = _DAT_2cc08fe0f7c + uVar12;
        uVar21 = 0x104;
        if ((0x103 < uVar20) &&
           ((0x7ffffffd < uVar20 || (uVar21 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar21)))) {
          uVar21 = 0x7ffffffe;
        }
        cVar9 = FUN_2cc08fc0060(&local_90,uVar21);
        if (cVar9 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3a00ff000b01f9);
          goto LAB_2cc08fc1a1c;
        }
        if (uVar18 != 0) {
          lVar14 = local_8c + (ulonglong)uVar12 * 2;
          if (uVar22 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar14 - 0x2cc08fe0f80U < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar19 = 0;
            uVar15 = (ulonglong)(uVar22 & 0xfffffff8);
            do {
              uVar11 = *(undefined4 *)(uVar19 + 0x2cc08fe0f84);
              uVar5 = *(undefined4 *)(uVar19 + 0x2cc08fe0f88);
              uVar6 = *(undefined4 *)(uVar19 + 0x2cc08fe0f8c);
              puVar2 = (undefined4 *)(lVar14 + uVar19);
              *puVar2 = *(undefined4 *)(&DAT_2cc08fe0f80 + uVar19);
              puVar2[1] = uVar11;
              puVar2[2] = uVar5;
              puVar2[3] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar15 == uVar18) goto LAB_2cc08fc1372;
          }
          do {
            *(undefined2 *)(lVar14 + uVar15 * 2) = *(undefined2 *)(&DAT_2cc08fe0f80 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar18 != uVar15);
        }
LAB_2cc08fc1372:
        *(uint *)(local_8c + -4) = uVar20;
        *(undefined2 *)(local_8c + (ulonglong)uVar20 * 2) = 0;
      }
      uVar12 = (*(code *)0x7ff63a0e6780)(0x2cc03e1bbb8);
      (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,uVar12 & 0x3ff,0x56,&local_60);
      iVar10 = 0;
      FUN_2cc08fc04d0(&local_80,&local_90,0);
      lVar14 = local_5c;
      if (local_5c != 0) {
        uVar12 = *(uint *)(local_5c + -4);
        uVar18 = (ulonglong)uVar12;
        if ((uVar18 != 0) || (local_7c == 0)) {
          if (local_7c == 0) {
            uVar22 = 0;
            uVar21 = uVar12;
          }
          else {
            uVar22 = *(uint *)(local_7c + -4);
            uVar21 = uVar12 + uVar22;
          }
          cVar9 = FUN_2cc08fc0060(&local_80);
          if (cVar9 == '\0') goto LAB_2cc08fc1a3c;
          if (uVar18 != 0) {
            lVar1 = local_7c + (ulonglong)uVar22 * 2;
            if (uVar12 < 0x10) {
              uVar15 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
              uVar15 = 0;
            }
            else {
              uVar19 = 0;
              uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar14 + uVar19);
                uVar11 = puVar2[1];
                uVar5 = puVar2[2];
                uVar6 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar19);
                *puVar3 = *puVar2;
                puVar3[1] = uVar11;
                puVar3[2] = uVar5;
                puVar3[3] = uVar6;
                uVar19 = uVar19 + 0x10;
              } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar15 == uVar18) goto LAB_2cc08fc14e2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2cc08fc14e2:
          *(uint *)(local_7c + -4) = uVar21;
          *(undefined2 *)(local_7c + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2cc08fc04d0(&local_a0,&local_80,0,0x2cc090cffb0);
      iVar8 = local_94;
      if (local_9c == 0) {
        lVar14 = *(longlong *)(local_50 + 4);
        uVar11 = 0xfa9;
        if (lVar14 != 0) goto LAB_2cc08fc1544;
LAB_2cc08fc15af:
        _DAT_2cc090d2810 = uVar11;
        if ((_DAT_2cc090d2840 == (undefined2 *)0x0) || (_DAT_2cc090d2840 == (undefined2 *)0xc)) {
          _DAT_2cc090d2810 = 0xfa9;
        }
        else if ((*(int *)(_DAT_2cc090d2840 + -2) != 0) &&
                (cVar9 = FUN_2cc08fc0060(0x2cc090d283c,0), puVar7 = _DAT_2cc090d2840, cVar9 != '\0')
                ) {
          *(undefined4 *)(_DAT_2cc090d2840 + -2) = 0;
          *puVar7 = 0;
        }
      }
      else {
        if (local_9c != 0xc) {
          iVar10 = *(int *)(local_9c + -4);
        }
        lVar14 = *(longlong *)(local_50 + 4);
        uVar11 = 0xfa9;
        if (lVar14 == 0) goto LAB_2cc08fc15af;
LAB_2cc08fc1544:
        uVar11 = 0xfa9;
        if (lVar14 == 0xc) goto LAB_2cc08fc15af;
        iVar17 = *(int *)(lVar14 + -4);
        if (iVar17 == 0) {
          uVar11 = 0x13ab;
          goto LAB_2cc08fc15af;
        }
        iVar16 = 0x3f - iVar10;
        if (-1 < iVar16) {
          if (iVar17 < iVar16) {
            _DAT_2cc090d2810 = 0x13ab;
          }
          else {
            uVar11 = _DAT_2cc090d2810;
            iVar17 = iVar16;
            if (iVar10 == 0x3f) goto LAB_2cc08fc15af;
          }
        }
        FUN_2cc08fc01d0(0x2cc090d283c,lVar14,iVar17);
      }
      FUN_2cc08fc04d0(&local_70,0x2cc090d283c,1,0x2cc090cffc0);
      FUN_2cc08fc04d0(&local_b0,0x2cc08fe0fa8,0);
      lVar14 = local_6c;
      if (local_6c != 0) {
        uVar12 = *(uint *)(local_6c + -4);
        uVar18 = (ulonglong)uVar12;
        if ((uVar18 != 0) || (local_ac == 0)) {
          if (local_ac == 0) {
            uVar22 = 0;
            uVar21 = uVar12;
          }
          else {
            uVar22 = *(uint *)(local_ac + -4);
            uVar21 = uVar12 + uVar22;
          }
          cVar9 = FUN_2cc08fc0060(&local_b0);
          if (cVar9 == '\0') goto LAB_2cc08fc1a5c;
          if (uVar18 != 0) {
            lVar1 = local_ac + (ulonglong)uVar22 * 2;
            if (uVar12 < 0x10) {
              uVar15 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
              uVar15 = 0;
            }
            else {
              uVar19 = 0;
              uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar14 + uVar19);
                uVar11 = puVar2[1];
                uVar5 = puVar2[2];
                uVar6 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar19);
                *puVar3 = *puVar2;
                puVar3[1] = uVar11;
                puVar3[2] = uVar5;
                puVar3[3] = uVar6;
                uVar19 = uVar19 + 0x10;
              } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar15 == uVar18) goto LAB_2cc08fc1782;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2cc08fc1782:
          *(uint *)(local_ac + -4) = uVar21;
          *(undefined2 *)(local_ac + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2cc08fc04d0(&local_c0,&local_b0,0);
      lVar14 = local_9c;
      if (local_9c != 0) {
        uVar12 = *(uint *)(local_9c + -4);
        uVar18 = (ulonglong)uVar12;
        if ((uVar18 != 0) || (local_bc == 0)) {
          if (local_bc == 0) {
            uVar22 = 0;
            uVar21 = uVar12;
          }
          else {
            uVar22 = *(uint *)(local_bc + -4);
            uVar21 = uVar12 + uVar22;
          }
          cVar9 = FUN_2cc08fc0060(&local_c0);
          if (cVar9 == '\0') goto LAB_2cc08fc1a7c;
          if (uVar18 != 0) {
            lVar1 = local_bc + (ulonglong)uVar22 * 2;
            if (uVar12 < 0x10) {
              uVar15 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar14) < 0x20) {
              uVar15 = 0;
            }
            else {
              uVar19 = 0;
              uVar15 = (ulonglong)(uVar12 & 0xfffffff8);
              do {
                puVar2 = (undefined4 *)(lVar14 + uVar19);
                uVar11 = puVar2[1];
                uVar5 = puVar2[2];
                uVar6 = puVar2[3];
                puVar3 = (undefined4 *)(lVar1 + uVar19);
                *puVar3 = *puVar2;
                puVar3[1] = uVar11;
                puVar3[2] = uVar5;
                puVar3[3] = uVar6;
                uVar19 = uVar19 + 0x10;
              } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
              if (uVar15 == uVar18) goto LAB_2cc08fc18b2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2cc08fc18b2:
          *(uint *)(local_bc + -4) = uVar21;
          *(undefined2 *)(local_bc + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2cc08fc04d0(param_1 + 0x30,&local_c0,0,0x2cc090cfff0);
      if (((*(int *)(param_1 + 100) == 4) && (*(longlong *)(param_1 + 0x7c) != 0)) &&
         (uVar18 = (ulonglong)*(uint *)(param_1 + 0x68), uVar18 != 0)) {
        lVar14 = -3;
        do {
          uVar15 = (ulonglong)*(uint *)(param_1 + 0x78 + lVar14 * 4);
          if (uVar15 == 0) break;
          uVar18 = uVar18 * uVar15;
          lVar14 = lVar14 + 1;
        } while (lVar14 != 0);
        if (uVar18 != 0) {
          (*(code *)0x7ff63a3fad20)(*(longlong *)(param_1 + 0x7c),0,uVar18 << 2);
        }
      }
      cVar9 = (*(code *)0x7ff639d98020)
                        (0x2cc03e1bbb8,param_1 + 0x30,local_48,param_3,iVar8,0,0,0,param_5);
      if (cVar9 != '\0') {
        *(int *)(param_1 + 0x3c) = param_3;
        *(int *)(param_1 + 0x40) = iVar8;
        *(undefined4 *)(param_1 + 0x44) = param_5;
        FUN_2cc08fc0000(&local_a0);
        uVar18 = CONCAT71((int7)((ulonglong)param_1 >> 8),1);
        goto LAB_2cc08fc19b3;
      }
      FUN_2cc08fc0000(&local_a0);
    }
  }
  FUN_2cc08fc0eb0(param_1);
  uVar18 = 0;
LAB_2cc08fc19b3:
  FUN_2cc08fc0000(&local_70);
  FUN_2cc08fc0000(&local_b0);
  FUN_2cc08fc0000(&local_c0);
  FUN_2cc08fc0000(&local_90);
  FUN_2cc08fc0000(&local_60);
  FUN_2cc08fc0000(&local_80);
  return uVar18 & 0xffffffff;
}



/* Address: 2cc08fc1aa0 */

void FUN_2cc08fc1aa0(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  
  (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,param_1 + 0x60);
  FUN_2cc08fc0000(param_1 + 0x48);
  FUN_2cc08fc0000(param_1 + 0x30);
  if ((((*(int *)(param_1 + 0x20) != 0) && (lVar2 = *(longlong *)(param_1 + 0x24), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
    }
  }
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(int *)(param_1 + 0x20) = 0;
  return;
}



/* Address: 2cc08fc2d80 */
/* DECOMPILATION FAILED: Exception while decompiling 2cc08fc2d80: process: timeout
 */

/* Address: 2cc08fcf740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_2cc08fcf740(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  undefined4 local_50;
  longlong local_4c;
  
  local_50 = 0;
  local_4c = 0;
  iVar7 = (*(code *)0x7ff63a107da0)(0x2cc03e1bbb8);
  iVar10 = 0;
  if (-1 < iVar7 + -1) {
    iVar7 = iVar7 + -1;
    do {
      (*(code *)0x7ff63a107e40)(0x2cc03e1bbb8,iVar7);
      FUN_2cc08fc04d0(&local_50,0x2cc090d283c,1,0x2cc090d0040);
      if (local_4c == _DAT_2cc090d282c) {
LAB_2cc08fcf7c0:
        lVar8 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,0xc);
        iVar10 = iVar10 + (uint)(lVar8 == param_1);
      }
      else if ((local_4c != 0) && (_DAT_2cc090d282c != 0)) {
        uVar3 = *(uint *)(local_4c + -4);
        uVar4 = *(uint *)(_DAT_2cc090d282c + -4);
        uVar6 = uVar4;
        if (uVar3 < uVar4) {
          uVar6 = uVar3;
        }
        iVar9 = uVar3 - uVar4;
        if (uVar6 != 0) {
          uVar11 = 1;
          do {
            uVar1 = *(ushort *)(local_4c + -2 + uVar11 * 2);
            uVar2 = *(ushort *)(_DAT_2cc090d282c + -2 + uVar11 * 2);
            if (uVar6 <= uVar11) break;
            uVar11 = uVar11 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar9 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar9 == 0) goto LAB_2cc08fcf7c0;
      }
      bVar5 = 0 < iVar7;
      iVar7 = iVar7 + -1;
    } while (bVar5);
  }
  FUN_2cc08fc0000(&local_50);
  return iVar10;
}



/* Address: 2cc08fcf8e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fcf8e0(void)

{
  undefined8 uVar1;
  code *pcVar2;
  double dVar3;
  char cVar4;
  ushort uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined4 *puVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  ulonglong uVar18;
  longlong lVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  uint uVar22;
  ulonglong uVar23;
  uint uVar24;
  double *pdVar25;
  ulonglong uVar26;
  ushort uVar27;
  longlong lVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  ulonglong uVar31;
  bool bVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  undefined8 in_stack_fffffffffffffd08;
  undefined4 uVar37;
  ulonglong *puVar38;
  ulonglong *puVar39;
  undefined4 local_278;
  longlong local_274;
  uint local_26c;
  undefined2 local_268;
  ushort local_266;
  undefined4 local_264;
  ulonglong local_260;
  undefined8 local_258;
  undefined4 local_250;
  undefined4 uStack_24c;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined8 local_240;
  undefined4 local_238;
  undefined4 local_230;
  undefined8 local_22c;
  undefined4 local_220;
  undefined8 local_21c;
  longlong local_210;
  undefined4 local_208;
  longlong local_204;
  uint local_1f8;
  uint local_1f4;
  undefined8 local_1f0;
  ulonglong local_1e8;
  undefined8 local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined8 local_1c8;
  undefined4 local_1c0;
  ulonglong local_1b8;
  undefined8 local_1b0;
  ulonglong local_1a8;
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined8 local_188;
  undefined4 local_180;
  undefined8 local_178;
  ulonglong local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined8 local_150;
  undefined4 local_148;
  ulonglong local_140;
  ulonglong local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined4 local_110;
  ulonglong local_108;
  ulonglong local_100;
  longlong local_f8;
  ulonglong local_f0;
  ulonglong local_e8;
  undefined8 local_e0;
  ulonglong local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  
  uVar37 = (undefined4)((ulonglong)in_stack_fffffffffffffd08 >> 0x20);
  uVar12 = 0;
  local_278 = 0;
  local_208 = 0;
  local_220 = 0;
  local_230 = 0;
  local_274 = 0;
  local_204 = 0;
  local_21c = 0;
  local_22c = 0;
  if ((DAT_2cc090d2405 != '\0') && (_DAT_2cc090d240c != -1)) {
    local_140 = 0x800010058;
    local_138 = 0;
    local_130 = 0;
    local_128 = 0;
    uStack_124 = 0;
    local_120 = 0;
    uStack_11c = 0;
    local_118 = 0;
    local_110 = 0;
    iVar9 = 2000;
    if (_DAT_2cc090d29f0 < 2000) {
      iVar9 = _DAT_2cc090d29f0;
    }
    iVar10 = 0x32;
    if (0x32 < iVar9) {
      iVar10 = iVar9;
    }
    uVar12 = 0;
    local_268 = _DAT_2cc05fa0efa;
    local_266 = 1;
    local_264 = 0x3c;
    local_260 = 0;
    local_258 = 0;
    local_250 = 0;
    uStack_24c = 0;
    local_248 = 0;
    uStack_244 = 0;
    local_240 = 0;
    local_238 = 0;
    uVar7 = FUN_2cc08fc07c0(0,iVar10,&local_268);
    if (2 < (int)uVar7) {
      puVar39 = &local_140;
      uVar29 = CONCAT44(uVar37,uVar7);
      uVar12 = 0;
      uVar8 = (*(code *)0x7ff63a0eeec0)(0x2cc03e1bbb8,_DAT_2cc090d240c,0,1,uVar29,puVar39);
      uVar37 = (undefined4)((ulonglong)uVar29 >> 0x20);
      uVar24 = uVar8;
      if ((int)uVar7 < (int)uVar8) {
        uVar24 = uVar7;
      }
      if (2 < (int)uVar8) {
        local_178 = 0x800010058;
        local_1b0 = 0x800010058;
        local_e0 = 0x800010058;
        local_170 = 0;
        local_168 = 0;
        local_160 = 0;
        uStack_15c = 0;
        local_158 = 0;
        uStack_154 = 0;
        local_150 = 0;
        local_148 = 0;
        local_1a8 = 0;
        local_1a0 = 0;
        local_198 = 0;
        uStack_194 = 0;
        local_190 = 0;
        uStack_18c = 0;
        local_188 = 0;
        local_180 = 0;
        local_b0 = 0;
        local_b8 = 0;
        local_c0 = 0;
        uStack_bc = 0;
        local_c8 = 0;
        uStack_c4 = 0;
        local_d0 = 0;
        local_d8 = 0;
        local_1f0 = 0x400010052;
        local_1c0 = 0;
        local_1c8 = 0;
        local_1d0 = 0;
        uStack_1cc = 0;
        local_1d8 = 0;
        uStack_1d4 = 0;
        local_1e0 = 0;
        local_1e8 = 0;
        (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_178,uVar24,0);
        (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_1b0,uVar24,0);
        (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_e0,uVar24,0);
        local_1f4 = uVar24;
        (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_1f0,uVar24,0);
        dVar3 = _DAT_2cc08fdea38;
        dVar33 = _DAT_2cc090d29e8;
        if (_DAT_2cc090d29e8 <= _DAT_2cc08fdea30) {
          dVar33 = _DAT_2cc08fdea30;
        }
        if ((int)uVar8 < (int)uVar7) {
          uVar7 = uVar8;
        }
        lVar13 = 0;
        do {
          uVar18 = local_260 & 0xffffffff;
          uVar24 = (uint)lVar13;
          if ((uint)local_260 <= uVar24) {
LAB_2cc08fd0e05:
            (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1d03e4000001f6);
LAB_2cc08fd0e25:
            (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xb03f8000001f6);
            goto LAB_2cc08fd0e45;
          }
          lVar19 = CONCAT44(local_248,uStack_24c);
          lVar16 = (uVar12 - 1) + uVar18;
          if ((local_266 & 0x10) == 0) {
            lVar16 = lVar13;
          }
          dVar34 = (*(double *)(lVar19 + 0x10 + lVar16 * 0x3c) +
                   *(double *)(lVar19 + 0x18 + lVar16 * 0x3c)) * dVar3;
          if ((uint)local_138 <= uVar24) {
            (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3503e5000001f6);
            goto LAB_2cc08fd0e05;
          }
          lVar16 = (uVar12 - 1) + (local_138 & 0xffffffff);
          if ((local_140 & 0x100000) == 0) {
            lVar16 = lVar13;
          }
          dVar36 = *(double *)(CONCAT44(local_120,uStack_124) + lVar16 * 8) * dVar33;
          dVar35 = dVar34 + dVar36;
          dVar36 = dVar34 - dVar36;
          uVar5 = local_1f0._2_2_;
          if ((int)uVar12 == 0) {
            if ((uint)local_170 <= uVar24) goto LAB_2cc08fd1045;
            lVar19 = (local_170 & 0xffffffff) - 1;
            if ((local_178 & 0x100000) == 0) {
              lVar19 = lVar13;
            }
            *(double *)(CONCAT44(local_158,uStack_15c) + lVar19 * 8) = dVar35;
            if ((uint)local_1a8 <= uVar24) goto LAB_2cc08fd1085;
            lVar19 = (local_1a8 & 0xffffffff) - 1;
            if ((local_1b0 & 0x100000) == 0) {
              lVar19 = lVar13;
            }
            *(double *)(CONCAT44(local_190,uStack_194) + lVar19 * 8) = dVar36;
            if ((uint)local_260 <= uVar24) goto LAB_2cc08fd10a5;
            if ((uint)local_1e8 <= uVar24) goto LAB_2cc08fd10c5;
            lVar19 = (local_260 & 0xffffffff) - 1;
            if ((local_266 & 0x10) == 0) {
              lVar19 = lVar13;
            }
            lVar16 = (local_1e8 & 0xffffffff) - 1;
            uVar8 = -(uint)(*(double *)(CONCAT44(local_248,uStack_24c) + 0x20 + lVar19 * 0x3c) <
                           dVar34) | 1;
            bVar32 = (local_1f0 & 0x100000) == 0;
LAB_2cc08fd008c:
            if (bVar32) {
              lVar16 = lVar13;
            }
            *(uint *)(CONCAT44(local_1d0,uStack_1d4) + lVar16 * 4) = uVar8;
          }
          else {
            uVar15 = local_170 & 0xffffffff;
            uVar20 = lVar13 - 1;
            if (uVar15 <= uVar20) goto LAB_2cc08fd0ee5;
            lVar16 = CONCAT44(local_158,uStack_15c);
            uVar11 = uVar12 + uVar15;
            if ((local_178 & 0x100000) == 0) {
              uVar11 = uVar20;
            }
            dVar34 = *(double *)(lVar16 + uVar11 * 8);
            if (dVar34 <= dVar35) {
              if (uVar18 <= uVar20) goto LAB_2cc08fd1105;
              uVar18 = uVar18 + uVar12;
              if ((local_266 & 0x10) == 0) {
                uVar18 = uVar20;
              }
              if (*(double *)(lVar19 + 0x20 + uVar18 * 0x3c) <= dVar34) {
                dVar35 = dVar34;
              }
            }
            if ((uint)local_170 <= uVar24) goto LAB_2cc08fd0e85;
            lVar19 = (uVar12 - 1) + uVar15;
            if ((local_178 & 0x100000) == 0) {
              lVar19 = lVar13;
            }
            *(double *)(lVar16 + lVar19 * 8) = dVar35;
            uVar18 = local_1a8 & 0xffffffff;
            if (uVar18 <= uVar20) goto LAB_2cc08fd0ec5;
            lVar19 = CONCAT44(local_190,uStack_194);
            uVar15 = uVar12 + uVar18;
            if ((local_1b0 & 0x100000) == 0) {
              uVar15 = uVar20;
            }
            dVar34 = *(double *)(lVar19 + uVar15 * 8);
            if (dVar36 <= dVar34) {
              if ((local_260 & 0xffffffff) <= uVar20) goto LAB_2cc08fd10e5;
              uVar26 = (local_260 & 0xffffffff) + uVar12;
              if ((local_266 & 0x10) == 0) {
                uVar26 = uVar20;
              }
              pdVar25 = (double *)(CONCAT44(local_248,uStack_24c) + 0x20 + uVar26 * 0x3c);
              if (dVar34 < *pdVar25 || dVar34 == *pdVar25) {
                dVar36 = dVar34;
              }
            }
            if ((uint)local_1a8 <= uVar24) goto LAB_2cc08fd0f25;
            lVar28 = (uVar12 - 1) + uVar18;
            if ((local_1b0 & 0x100000) == 0) {
              lVar28 = lVar13;
            }
            *(double *)(lVar19 + lVar28 * 8) = dVar36;
            if ((uint)local_260 <= uVar24) goto LAB_2cc08fd0ea5;
            lVar28 = (uVar12 - 1) + (local_260 & 0xffffffff);
            if ((local_266 & 0x10) == 0) {
              lVar28 = lVar13;
            }
            dVar34 = *(double *)(CONCAT44(local_248,uStack_24c) + 0x20 + lVar28 * 0x3c);
            pdVar25 = (double *)(lVar16 + uVar11 * 8);
            if (dVar34 < *pdVar25 || dVar34 == *pdVar25) {
              uVar18 = local_1e8 & 0xffffffff;
              if (*(double *)(lVar19 + uVar15 * 8) <= dVar34) {
                if (uVar20 < uVar18) {
                  if (uVar24 < (uint)local_1e8) {
                    bVar32 = (local_1f0 & 0x100000) == 0;
                    uVar15 = uVar12 + uVar18;
                    if (bVar32) {
                      uVar15 = uVar20;
                    }
                    uVar8 = *(uint *)(CONCAT44(local_1d0,uStack_1d4) + uVar15 * 4);
                    lVar16 = (uVar12 - 1) + uVar18;
                    goto LAB_2cc08fd008c;
                  }
                  goto LAB_2cc08fd11a5;
                }
                goto LAB_2cc08fd1185;
              }
              if ((uint)local_1e8 <= uVar24) goto LAB_2cc08fd11c5;
              lVar19 = (uVar12 - 1) + uVar18;
              if ((local_1f0 & 0x100000) == 0) {
                lVar19 = lVar13;
              }
              *(undefined4 *)(CONCAT44(local_1d0,uStack_1d4) + lVar19 * 4) = 0xffffffff;
            }
            else {
              if ((uint)local_1e8 <= uVar24) goto LAB_2cc08fd1125;
              lVar19 = (uVar12 - 1) + (local_1e8 & 0xffffffff);
              if ((local_1f0 & 0x100000) == 0) {
                lVar19 = lVar13;
              }
              *(undefined4 *)(CONCAT44(local_1d0,uStack_1d4) + lVar19 * 4) = 1;
            }
          }
          lVar28 = CONCAT44(local_1d0,uStack_1d4);
          lVar19 = CONCAT44(local_158,uStack_15c);
          uVar18 = local_1e8 & 0xffffffff;
          lVar16 = (uVar18 - 1) + uVar12;
          if ((local_1f0 & 0x100000) == 0) {
            lVar16 = lVar13;
          }
          if (*(int *)(lVar28 + lVar16 * 4) < 1) {
            uVar27 = local_178._2_2_;
            uVar20 = local_170;
            if ((uint)local_170 <= uVar24) goto LAB_2cc08fd1065;
          }
          else {
            lVar19 = CONCAT44(local_190,uStack_194);
            uVar27 = local_1b0._2_2_;
            uVar20 = local_1a8;
            if ((uint)local_1a8 <= uVar24) goto LAB_2cc08fd0f05;
          }
          if ((uint)local_d8 <= uVar24) goto LAB_2cc08fd0e25;
          lVar16 = (uVar12 - 1) + (uVar20 & 0xffffffff);
          if ((uVar27 & 0x10) == 0) {
            lVar16 = lVar13;
          }
          lVar17 = (uVar12 - 1) + (local_d8 & 0xffffffff);
          if ((local_e0 & 0x100000) == 0) {
            lVar17 = lVar13;
          }
          lVar13 = lVar13 + 1;
          uVar12 = uVar12 - 1;
          *(undefined8 *)(CONCAT44(local_c0,uStack_c4) + lVar17 * 8) =
               *(undefined8 *)(lVar19 + lVar16 * 8);
        } while (uVar7 != (uint)lVar13);
        local_1f8 = (uint)local_e0._2_2_;
        local_f8 = CONCAT44(local_c0,uStack_c4);
        local_f0 = local_d8 & 0xffffffff;
        (*(code *)0x7ff63a0f4da0)
                  (0x2cc03e1bbb8,0,0x2cc08fe1328,0xffffffff,CONCAT44(uVar37,0xffffffff));
        cVar4 = DAT_2cc090d2a00;
        uVar12 = _DAT_2cc08fdea50;
        dVar33 = _DAT_2cc08fdea48;
        dVar3 = _DAT_2cc08fdea40;
        uVar24 = 1;
        local_26c = (uint)uVar5;
        uVar7 = 5;
        if ((int)_DAT_2cc090d29f8 < 5) {
          uVar7 = _DAT_2cc090d29f8;
        }
        local_100 = (ulonglong)uVar7;
        local_210 = lVar28;
        local_1b8 = uVar18;
        local_e8 = uVar18;
        if ((int)uVar7 < 2) {
          local_100 = 1;
        }
        do {
          uVar37 = (undefined4)((ulonglong)puVar39 >> 0x20);
          if ((uint)uVar18 <= uVar24) goto LAB_2cc08fd0e65;
          uVar15 = (ulonglong)uVar24;
          uVar20 = (ulonglong)(int)(uVar24 - 1);
          if (local_e8 <= uVar20) goto LAB_2cc08fd0e45;
          uVar31 = ~uVar15;
          uVar23 = ~uVar20;
          uVar26 = uVar23 + local_e8;
          uVar11 = local_e8 + uVar31;
          if ((local_26c & 0x10) == 0) {
            uVar26 = uVar20;
            uVar11 = uVar15;
          }
          if (*(int *)(local_210 + uVar11 * 4) == *(int *)(local_210 + uVar26 * 4)) {
            local_220 = 0;
            local_21c = 0;
            if ((uint)local_260 <= uVar24) goto LAB_2cc08fd0fa5;
            uVar11 = (local_260 & 0xffffffff) + uVar31;
            if ((local_266 & 0x10) == 0) {
              uVar11 = uVar15;
            }
            (*(code *)0x7ff63a0fdfe0)
                      (0x2cc03e1bbb8,*(undefined8 *)(CONCAT44(local_248,uStack_24c) + uVar11 * 0x3c)
                       ,0,0x20);
            FUN_2cc08fc04d0(&local_208,0x2cc090d283c,1,0x2cc090d0310);
            FUN_2cc08fc04d0(&local_278,0x2cc08fe1408,0);
            lVar13 = local_204;
            if (local_204 != 0) {
              uVar7 = *(uint *)(local_204 + -4);
              uVar11 = (ulonglong)uVar7;
              if ((uVar11 != 0) || (local_274 == 0)) {
                if (local_274 == 0) {
                  local_108 = 0;
                }
                else {
                  local_108 = (ulonglong)*(uint *)(local_274 + -4);
                }
                uVar8 = uVar7 + (int)local_108;
                cVar6 = FUN_2cc08fc0060(&local_278);
                if (cVar6 == '\0') goto LAB_2cc08fd1205;
                if (uVar11 != 0) {
                  lVar19 = local_274 + (local_108 & 0xffffffff) * 2;
                  if (uVar7 < 8) {
                    uVar18 = 0;
                  }
                  else if ((ulonglong)(lVar19 - lVar13) < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar26 = 0;
                    uVar18 = (ulonglong)(uVar7 & 0xfffffff8);
                    do {
                      uVar29 = ((undefined8 *)(lVar13 + uVar26))[1];
                      *(undefined8 *)(lVar19 + uVar26) = *(undefined8 *)(lVar13 + uVar26);
                      ((undefined8 *)(lVar19 + uVar26))[1] = uVar29;
                      uVar26 = uVar26 + 0x10;
                    } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar26);
                    if (uVar18 == uVar11) goto LAB_2cc08fd0722;
                  }
                  do {
                    *(undefined2 *)(lVar19 + uVar18 * 2) = *(undefined2 *)(lVar13 + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar11 != uVar18);
                }
LAB_2cc08fd0722:
                *(uint *)(local_274 + -4) = uVar8;
                *(undefined2 *)(local_274 + (ulonglong)uVar8 * 2) = 0;
                uVar18 = local_1b8;
              }
            }
            FUN_2cc08fc04d0(&local_220,&local_278,0,0x2cc090d0330);
            if (uVar18 <= uVar15) goto LAB_2cc08fd0f85;
            uVar29 = 0x5046f0;
            uVar11 = uVar18 + uVar31;
            if ((local_26c & 0x10) == 0) {
              uVar11 = uVar15;
            }
            if (0 < *(int *)(local_210 + uVar11 * 4)) {
              uVar29 = 0xff912d;
            }
            if ((uint)local_f0 <= uVar24) goto LAB_2cc08fd1005;
            uVar26 = local_260 & 0xffffffff;
            uVar11 = local_f0 + uVar31;
            if ((local_1f8 & 0x10) == 0) {
              uVar11 = uVar15;
            }
            if ((uint)local_260 <= uVar24) goto LAB_2cc08fd0f65;
            uVar31 = uVar31 + uVar26;
            if ((local_266 & 0x10) == 0) {
              uVar31 = uVar15;
            }
            if (local_f0 <= uVar20) goto LAB_2cc08fd0fe5;
            if (uVar26 <= uVar20) goto LAB_2cc08fd0f45;
            puVar38 = *(ulonglong **)(local_f8 + uVar11 * 8);
            uVar30 = *(undefined8 *)(CONCAT44(local_248,uStack_24c) + uVar31 * 0x3c);
            uVar15 = local_f0 + uVar23;
            if ((local_1f8 & 0x10) == 0) {
              uVar15 = uVar20;
            }
            uVar11 = uVar26 + uVar23;
            if ((local_266 & 0x10) == 0) {
              uVar11 = uVar20;
            }
            uVar21 = *(undefined8 *)(local_f8 + uVar15 * 8);
            uVar1 = *(undefined8 *)(CONCAT44(local_248,uStack_24c) + uVar11 * 0x3c);
            FUN_2cc08fc04d0(&local_208,&local_220,0,0x2cc090d0340);
            iVar9 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,&local_208);
            if (iVar9 < 0) {
              puVar39 = (ulonglong *)CONCAT44(uVar37,0x590008);
              cVar6 = (*(code *)0x7ff63a0e49f0)
                                (0x2cc03e1bbb8,0x112,8,0x550005,0,puVar39,&local_208,0x520004,2,
                                 0x520004,0,0x540005,uVar1,0x580007,uVar21,0x540005,uVar30,0x580007,
                                 puVar38);
              puVar14 = &local_220;
              if (cVar6 == '\0') goto LAB_2cc08fd0349;
            }
            (*(code *)0x7ff63a0f39d0)(0x2cc03e1bbb8,0,&local_208,0,uVar1,uVar21);
            (*(code *)0x7ff63a0f39d0)(0x2cc03e1bbb8,0,&local_208,1,uVar30,puVar38);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0x3eb,0);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0x3ec,0);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0,uVar29);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,1,0);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,2,local_100);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,3,1);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,10,0);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0xd0,1);
            (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0xcf,2);
            puVar14 = &local_220;
            puVar39 = puVar38;
          }
          else {
            local_230 = 0;
            local_22c = 0;
            if ((uint)local_260 <= uVar24) goto LAB_2cc08fd1025;
            uVar20 = (local_260 & 0xffffffff) + uVar31;
            if ((local_266 & 0x10) == 0) {
              uVar20 = uVar15;
            }
            (*(code *)0x7ff63a0fdfe0)
                      (0x2cc03e1bbb8,*(undefined8 *)(CONCAT44(local_248,uStack_24c) + uVar20 * 0x3c)
                       ,0,0x20);
            FUN_2cc08fc04d0(&local_208,0x2cc090d283c,1,0x2cc090d0350);
            FUN_2cc08fc04d0(&local_278,0x2cc08fe1448,0);
            lVar13 = local_204;
            if (local_204 != 0) {
              uVar7 = *(uint *)(local_204 + -4);
              uVar20 = (ulonglong)uVar7;
              if ((uVar20 != 0) || (local_274 == 0)) {
                if (local_274 == 0) {
                  uVar8 = 0;
                  uVar22 = uVar7;
                }
                else {
                  uVar8 = *(uint *)(local_274 + -4);
                  uVar22 = uVar7 + uVar8;
                }
                cVar6 = FUN_2cc08fc0060(&local_278);
                if (cVar6 == '\0') goto LAB_2cc08fd11e5;
                if (uVar20 != 0) {
                  lVar19 = local_274 + (ulonglong)uVar8 * 2;
                  if (uVar7 < 8) {
                    uVar18 = 0;
                  }
                  else if ((ulonglong)(lVar19 - lVar13) < 0x20) {
                    uVar18 = 0;
                  }
                  else {
                    uVar26 = 0;
                    uVar18 = (ulonglong)(uVar7 & 0xfffffff8);
                    do {
                      uVar29 = ((undefined8 *)(lVar13 + uVar26))[1];
                      *(undefined8 *)(lVar19 + uVar26) = *(undefined8 *)(lVar13 + uVar26);
                      ((undefined8 *)(lVar19 + uVar26))[1] = uVar29;
                      uVar26 = uVar26 + 0x10;
                    } while ((uVar20 * 2 & 0xfffffffffffffff0) != uVar26);
                    if (uVar18 == uVar20) goto LAB_2cc08fd0972;
                  }
                  do {
                    *(undefined2 *)(lVar19 + uVar18 * 2) = *(undefined2 *)(lVar13 + uVar18 * 2);
                    uVar18 = uVar18 + 1;
                  } while (uVar20 != uVar18);
                }
LAB_2cc08fd0972:
                *(uint *)(local_274 + -4) = uVar22;
                *(undefined2 *)(local_274 + (ulonglong)uVar22 * 2) = 0;
                uVar18 = local_1b8;
              }
            }
            FUN_2cc08fc04d0(&local_230,&local_278,0,0x2cc090d0370);
            if ((uint)local_138 <= uVar24) goto LAB_2cc08fd0fc5;
            uVar20 = (local_138 & 0xffffffff) + uVar31;
            if ((local_140 & 0x100000) == 0) {
              uVar20 = uVar15;
            }
            uVar26 = local_260 & 0xffffffff;
            dVar36 = _DAT_2cc090d2818 * dVar33;
            iVar9 = *(int *)(local_210 + uVar11 * 4);
            dVar34 = *(double *)(CONCAT44(local_120,uStack_124) + uVar20 * 8) * dVar3;
            if (iVar9 < 1) {
              if ((uint)local_260 <= uVar24) goto LAB_2cc08fd1165;
              uVar20 = uVar26 + uVar31;
              if ((local_266 & 0x10) == 0) {
                uVar20 = uVar15;
              }
              pdVar25 = (double *)(CONCAT44(local_248,uStack_24c) + 0x10 + uVar20 * 0x3c);
            }
            else {
              if ((uint)local_260 <= uVar24) goto LAB_2cc08fd1145;
              uVar20 = uVar26 + uVar31;
              if ((local_266 & 0x10) == 0) {
                uVar20 = uVar15;
              }
              pdVar25 = (double *)(CONCAT44(local_248,uStack_24c) + 0x18 + uVar20 * 0x3c);
            }
            dVar35 = *pdVar25;
            puVar14 = &local_230;
            uVar20 = uVar26 + uVar31;
            if ((local_266 & 0x10) == 0) {
              uVar20 = uVar15;
            }
            uVar29 = *(undefined8 *)(CONCAT44(local_248,uStack_24c) + uVar20 * 0x3c);
            FUN_2cc08fc04d0(&local_208,puVar14,0,0x2cc090d0380);
            uVar37 = (undefined4)((ulonglong)puVar39 >> 0x20);
            if (cVar4 != '\0') {
              iVar10 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,&local_208);
              if (iVar10 < 0) {
                puVar39 = (ulonglong *)CONCAT44(uVar37,0x590008);
                cVar6 = (*(code *)0x7ff63a0e49f0)
                                  (0x2cc03e1bbb8,0x112,6,0x550005,0,puVar39,&local_208,0x520004,100,
                                   0x520004,0,0x540005,uVar29,0x580007,dVar35);
                puVar14 = &local_230;
                if (cVar6 == '\0') goto LAB_2cc08fd0349;
              }
              uVar30 = 0xff912d;
              if (dVar34 <= dVar36) {
                dVar34 = dVar36;
              }
              if (iVar9 < 1) {
                uVar30 = 0x5046f0;
              }
              else {
                dVar34 = (double)((ulonglong)dVar34 ^ uVar12);
              }
              uVar21 = 0x2cc08fe1378;
              puVar39 = (ulonglong *)(dVar34 + dVar35);
              if (iVar9 < 1) {
                uVar21 = 0x2cc08fe13d0;
              }
              (*(code *)0x7ff63a0f39d0)(0x2cc03e1bbb8,0,&local_208,0,uVar29,puVar39);
              (*(code *)0x7ff63a0f3b30)
                        (0x2cc03e1bbb8,0,&local_208,0x3f0,(ulonglong)(iVar9 < 1) + 0xe9);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0,uVar30);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,2,2);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0x3f3,(ulonglong)(iVar9 < 1));
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,3,1);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,10,0);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0xd0,1);
              (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_208,0xcf,3);
              (*(code *)0x7ff63a0f3c80)(0x2cc03e1bbb8,0,&local_208,0xce,uVar21);
              puVar14 = &local_230;
            }
          }
LAB_2cc08fd0349:
          FUN_2cc08fc0000(puVar14);
          uVar24 = uVar24 + 1;
        } while (uVar24 != local_1f4);
        uVar7 = local_1f4 - 1;
        if ((uint)uVar18 <= uVar7) goto LAB_2cc08fd1225;
        uVar12 = uVar18 + ~(ulonglong)uVar7;
        if ((local_26c & 0x10) == 0) {
          uVar12 = (ulonglong)uVar7;
        }
        _DAT_2cc090d2410 = *(undefined4 *)(local_210 + uVar12 * 4);
        (*(code *)0x7ff63a0f51b0)(0x2cc03e1bbb8,0);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_1f0);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_e0);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_1b0);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_178);
        uVar12 = 0x7ff63a0d9d01;
      }
    }
    (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_140);
    FUN_2cc08fc06f0(&local_268);
  }
  FUN_2cc08fc0000(&local_208);
  FUN_2cc08fc0000(&local_278);
  return uVar12 & 0xffffffff;
LAB_2cc08fd0e45:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x240400000001f6);
LAB_2cc08fd0e65:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x130400000001f6);
LAB_2cc08fd0e85:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf03ef000001f6);
LAB_2cc08fd0ea5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1203f1000001f6);
LAB_2cc08fd0ec5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2a03f0000001f6);
LAB_2cc08fd0ee5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2a03ef000001f6);
LAB_2cc08fd0f05:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2a03f8000001f6);
LAB_2cc08fd0f25:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf03f0000001f6);
LAB_2cc08fd0f45:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2b0403000001f6);
LAB_2cc08fd0f65:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x460403000001f6);
LAB_2cc08fd0f85:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x260404000001f6);
LAB_2cc08fd0fa5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x4f0402000001f6);
LAB_2cc08fd0fc5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x33040a000001f6);
LAB_2cc08fd0fe5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3b0403000001f6);
LAB_2cc08fd1005:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x540403000001f6);
LAB_2cc08fd1025:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x4f0408000001f6);
LAB_2cc08fd1045:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf03e9000001f6);
LAB_2cc08fd1065:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3503f8000001f6);
LAB_2cc08fd1085:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf03ea000001f6);
LAB_2cc08fd10a5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f03eb000001f6);
LAB_2cc08fd10c5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1303eb000001f6);
LAB_2cc08fd10e5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3803f0000001f6);
LAB_2cc08fd1105:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3803ef000001f6);
LAB_2cc08fd1125:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1603f2000001f6);
LAB_2cc08fd1145:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x490409000001f6);
LAB_2cc08fd1165:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x580409000001f6);
LAB_2cc08fd1185:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2603f6000001f6);
LAB_2cc08fd11a5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1603f6000001f6);
LAB_2cc08fd11c5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1603f4000001f6);
LAB_2cc08fd11e5:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x310408000001f9);
LAB_2cc08fd1205:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x310402000001f9);
LAB_2cc08fd1225:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2b040d000001f6);
  pcVar2 = (code *)swi(3);
  uVar12 = (*pcVar2)();
  return uVar12;
}



/* Address: 2cc08fd1250 */

void FUN_2cc08fd1250(undefined8 *param_1)

{
  *param_1 = 0x800010055;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined8 *)((longlong)param_1 + 0x34) = 0x400010057;
  *(undefined8 *)((longlong)param_1 + 0x3c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x44) = 0;
  *(undefined8 *)((longlong)param_1 + 0x4c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x54) = 0;
  *(undefined8 *)((longlong)param_1 + 0x5c) = 0;
  *(undefined4 *)((longlong)param_1 + 100) = 0;
  return;
}



/* Address: 2cc08fd12d0 */

void FUN_2cc08fd12d0(longlong param_1)

{
  (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,param_1 + 0x34);
  (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,param_1);
  return;
}



/* Address: 2cc08fd1310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2cc08fd1310(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_64 = 0;
  local_74 = 0;
  if (_DAT_2cc090d2814 == 0) {
    cVar1 = (*(code *)0x7ff63a107ee0)(0x2cc03e1bbb8,param_1);
    if (cVar1 == '\0') {
      uVar3 = 0;
    }
    else {
      local_78 = 0;
      local_74 = 0;
      (*(code *)0x7ff63a108010)(0x2cc03e1bbb8,0);
      FUN_2cc08fc04d0(&local_68,0x2cc090d283c,1,0x2cc090cf2f8);
      FUN_2cc08fc04d0(&local_78,&local_68,0,0x2cc090cf308);
      _DAT_2cc090d2020 = 0;
      _DAT_2cc090d2024 = 0;
      uRam000002cc090d2028 = 0;
      uRam000002cc090d202c = 0;
      _DAT_2cc090d2030 = 0;
      FUN_2cc08fc0000(0x2cc090d2034);
      _DAT_2cc090d2050 = 0;
      _DAT_2cc090d2058 = 0;
      _DAT_2cc090d2070 = 0;
      _DAT_2cc090d2078 = 0;
      _DAT_2cc090d2060 = 0;
      _DAT_2cc090d2068 = 0;
      _DAT_2cc090d2040 = 0;
      _DAT_2cc090d2048 = 0;
      _DAT_2cc090d2080 = 0;
      FUN_2cc08fc0000(0x2cc090d2084);
      _DAT_2cc090d2110 = 0;
      uRam000002cc090d2118 = 0;
      _DAT_2cc090d2120 = 0;
      uRam000002cc090d2128 = 0;
      _DAT_2cc090d2130 = 0;
      uRam000002cc090d2138 = 0;
      _DAT_2cc090d2090 = 0;
      uRam000002cc090d2098 = 0;
      _DAT_2cc090d20f0 = 0;
      uRam000002cc090d20f8 = 0;
      _DAT_2cc090d2100 = 0;
      uRam000002cc090d2108 = 0;
      _DAT_2cc090d20d0 = 0;
      uRam000002cc090d20d8 = 0;
      _DAT_2cc090d20e0 = 0;
      uRam000002cc090d20e8 = 0;
      _DAT_2cc090d20b0 = 0;
      uRam000002cc090d20b8 = 0;
      _DAT_2cc090d20c0 = 0;
      uRam000002cc090d20c8 = 0;
      _DAT_2cc090d2140 = 0;
      _DAT_2cc090d20a0 = 0;
      uRam000002cc090d20a8 = 0;
      FUN_2cc08fc0000(0x2cc090d2144);
      _DAT_2cc090d21e0 = 0;
      uRam000002cc090d21e8 = 0;
      _DAT_2cc090d21d0 = 0;
      uRam000002cc090d21d8 = 0;
      _DAT_2cc090d21f0 = 0;
      uRam000002cc090d21f8 = 0;
      _DAT_2cc090d21c0 = 0;
      uRam000002cc090d21c8 = 0;
      _DAT_2cc090d21b0 = 0;
      uRam000002cc090d21b8 = 0;
      _DAT_2cc090d21a0 = 0;
      uRam000002cc090d21a8 = 0;
      _DAT_2cc090d2190 = 0;
      uRam000002cc090d2198 = 0;
      _DAT_2cc090d2180 = 0;
      uRam000002cc090d2188 = 0;
      _DAT_2cc090d2170 = 0;
      uRam000002cc090d2178 = 0;
      _DAT_2cc090d2160 = 0;
      uRam000002cc090d2168 = 0;
      _DAT_2cc090d2150 = 0;
      uRam000002cc090d2158 = 0;
      _DAT_2cc090d2200 = 0;
      FUN_2cc08fc0000(0x2cc090d2208);
      _DAT_2cc090d2284 = 0;
      _DAT_2cc090d227c = 0;
      _DAT_2cc090d228c = 0;
      _DAT_2cc090d2274 = 0;
      _DAT_2cc090d226c = 0;
      _DAT_2cc090d2264 = 0;
      _DAT_2cc090d225c = 0;
      _DAT_2cc090d2254 = 0;
      _DAT_2cc090d224c = 0;
      _DAT_2cc090d2244 = 0;
      _DAT_2cc090d223c = 0;
      _DAT_2cc090d2234 = 0;
      _DAT_2cc090d222c = 0;
      _DAT_2cc090d2224 = 0;
      _DAT_2cc090d221c = 0;
      _DAT_2cc090d2214 = 0;
      cVar1 = FUN_2cc08fd8aa0(&local_78);
      if (cVar1 == '\0') {
        FUN_2cc08fc0000(&local_78);
        uVar3 = 0;
      }
      else {
        iVar2 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8);
        _DAT_2cc090d2070 = CONCAT44(_DAT_2cc090d2074,(uint)(iVar2 == 0));
        (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,&local_78,(iVar2 != 0) * '\x03' + '\x01');
        _DAT_2cc090d2048 = _DAT_2cc090d2848;
        _DAT_2cc090d2020 = 1;
        _DAT_2cc090d2090 = param_1;
        FUN_2cc08fc04d0(0x2cc090d2034,&local_78,0,0x2cc090cf318);
        (*(code *)0x7ff63a107f70)(0x2cc03e1bbb8,3);
        _DAT_2cc090d2040 = _DAT_2cc090d2848;
        _DAT_2cc090d2024 = (undefined4)_DAT_2cc090d2295;
        uRam000002cc090d2028 = (undefined4)((ulonglong)_DAT_2cc090d2295 >> 0x20);
        _DAT_2cc090d2068 = _DAT_2cc090d229d;
        uVar3 = FUN_2cc08fc0c30(&DAT_2cc090d2000,&DAT_2cc090d2020,&DAT_2cc090d2110);
        FUN_2cc08fc0000(&local_78);
      }
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,0xd,2,0x590008,0x2cc08fe0f40,0x590008,0x2cc08fdfea8);
    uVar3 = 0;
    _DAT_2cc090d2110 = CONCAT44(DAT_2cc090d2110_4,0x272b);
  }
  FUN_2cc08fc0000(&local_68);
  return uVar3;
}



/* Address: 2cc08fd18b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fd18b0(void)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 unaff_RSI;
  ulonglong uVar4;
  undefined1 local_30 [12];
  int local_24;
  int local_20;
  uint local_18;
  
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (DAT_2cc090d2a08 != '\0') {
    uVar4 = 0;
    uVar2 = (*(code *)0x7ff63a101c40)(0x2cc03e1bbb8,0);
    (*(code *)0x7ff63a101f60)(0x2cc03e1bbb8,uVar2,local_30);
    if ((ulonglong)local_18 < 7) {
      if (**(char **)((ulonglong)local_18 * 8 + 0x2cc090d0ed0) == '\0') {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
        iVar1 = _DAT_2cc090d2a10 * 0x3c + _DAT_2cc090d2a18;
        iVar3 = _DAT_2cc090d2a20 * 0x3c + _DAT_2cc090d2a28;
        if (iVar1 != iVar3) {
          local_20 = local_24 * 0x3c + local_20;
          if (iVar1 < iVar3) {
            uVar4 = (ulonglong)(iVar1 <= local_20 && local_20 <= iVar3);
          }
          else {
            uVar4 = (ulonglong)(iVar1 <= local_20 || local_20 <= iVar3);
          }
        }
      }
    }
  }
  return uVar4 & 0xffffffff;
}



/* Address: 2cc08fd1990 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fd1990(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong local_98;
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
  
  lVar11 = _DAT_2cc090d2960;
  local_90 = 0;
  local_8c = 0;
  local_80 = param_1;
  iVar8 = FUN_2cc08fcf740(_DAT_2cc090d2960);
  if (iVar8 == 0) {
    uVar13 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
  }
  else {
    iVar8 = FUN_2cc08fcf740(lVar11);
    if (iVar8 != 0) {
      iVar8 = (*(code *)0x7ff63a107da0)(0x2cc03e1bbb8);
      if (iVar8 + -1 < 0) {
        local_98 = 0;
      }
      else {
        local_98 = 0;
        lVar11 = local_80;
        iVar8 = iVar8 + -1;
        do {
          (*(code *)0x7ff63a107e40)(0x2cc03e1bbb8,iVar8);
          FUN_2cc08fc04d0(&local_90,0x2cc090d283c,1,0x2cc090d0060);
          if (local_8c == _DAT_2cc090d282c) {
LAB_2cc08fd1b1d:
            lVar9 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,0xc);
            if ((lVar9 == lVar11) &&
               (lVar9 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,1), local_98 < lVar9)) {
              local_98 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,1);
            }
          }
          else if ((local_8c != 0) && (_DAT_2cc090d282c != 0)) {
            uVar3 = *(uint *)(local_8c + -4);
            uVar4 = *(uint *)(_DAT_2cc090d282c + -4);
            uVar7 = uVar4;
            if (uVar3 < uVar4) {
              uVar7 = uVar3;
            }
            iVar10 = uVar3 - uVar4;
            if (uVar7 != 0) {
              uVar13 = 1;
              do {
                uVar1 = *(ushort *)(local_8c + -2 + uVar13 * 2);
                uVar2 = *(ushort *)(_DAT_2cc090d282c + -2 + uVar13 * 2);
                if (uVar7 <= uVar13) break;
                uVar13 = uVar13 + 1;
              } while (uVar1 == uVar2);
              lVar11 = local_80;
              if (uVar1 != uVar2) {
                iVar10 = (uint)uVar1 - (uint)uVar2;
              }
            }
            if (iVar10 == 0) goto LAB_2cc08fd1b1d;
          }
          bVar5 = 0 < iVar8;
          iVar8 = iVar8 + -1;
        } while (bVar5);
      }
      local_78 = 0x800010054;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      uStack_5c = 0;
      local_58 = 0;
      uStack_54 = 0;
      local_50 = 0;
      local_48 = 0;
      iVar8 = (*(code *)0x7ff63a1021d0)(0x2cc03e1bbb8,1,0,0,0,1,&local_78);
      if (0 < iVar8) {
        if ((local_70 & 0xffffffff) == 0) {
          (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xe01f8000001f6);
          pcVar6 = (code *)swi(3);
          uVar13 = (*pcVar6)();
          return uVar13;
        }
        lVar9 = 0;
        if ((local_78 & 0x100000) != 0) {
          lVar9 = (local_70 & 0xffffffff) - 1;
        }
        lVar12 = local_98 + 0x2a30;
        if (DAT_2cc090d2320 == '\0') {
          lVar12 = local_98;
        }
        uVar13 = CONCAT71((int7)((ulonglong)lVar11 >> 8),
                          lVar12 < *(longlong *)(CONCAT44(local_58,uStack_5c) + lVar9 * 8));
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_78);
        goto LAB_2cc08fd1c92;
      }
      (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_78);
    }
    uVar13 = 0;
  }
LAB_2cc08fd1c92:
  FUN_2cc08fc0000(&local_90);
  return uVar13 & 0xffffffff;
}



/* Address: 2cc08fd1ce0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fd1ce0(void)

{
  undefined4 *puVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  undefined4 *puVar15;
  ulonglong uVar16;
  int *piVar17;
  longlong lVar18;
  int *piVar19;
  ulonglong uVar20;
  undefined1 *puVar21;
  undefined4 *puVar22;
  longlong lVar23;
  uint uVar24;
  uint *puVar25;
  uint uVar26;
  uint uVar27;
  int *piVar28;
  uint uVar29;
  undefined1 *unaff_RSI;
  ulonglong uVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  uint uVar33;
  longlong *plVar34;
  short *psVar35;
  bool bVar36;
  int local_1a0;
  int *local_19c;
  longlong local_190;
  undefined4 local_188;
  longlong local_184;
  undefined4 local_178;
  longlong local_174;
  longlong local_168;
  ulonglong local_160;
  undefined8 local_158;
  undefined8 local_150;
  uint local_148 [8];
  int *local_128;
  longlong local_120;
  longlong local_118;
  ulonglong local_110;
  undefined1 *local_108;
  longlong local_100;
  undefined2 local_f8;
  ushort local_f6;
  undefined4 local_f4;
  ulonglong local_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c0 [36];
  int local_9c;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  
  local_178 = 0;
  local_188 = 0;
  local_1a0 = 0;
  local_174 = 0;
  local_184 = 0;
  local_19c = (int *)0x0;
  if ((DAT_2cc090d2a68 == '\0') ||
     (iVar11 = (*(code *)0x7ff63a0f0fd0)(0x2cc03e1bbb8,6), iVar11 != 0)) {
    uVar30 = 0;
    goto LAB_2cc08fd1fb1;
  }
  lVar14 = (*(code *)0x7ff63a101ce0)(0x2cc03e1bbb8,0);
  if ((_DAT_2cc090d23e0 == 0) || (299 < lVar14 - _DAT_2cc090d23e0)) {
    _DAT_2cc090d23f0 = 0;
    unaff_RSI = (undefined1 *)0x0;
    _DAT_2cc090d23e8 = 0;
    _DAT_2cc090d23e0 = lVar14;
    FUN_2cc08fc04d0(0x2cc090d23f8);
    local_160 = 0xc00010059;
    local_158 = 0;
    local_150 = 0;
    local_148[0] = 0;
    local_148[1] = 0;
    local_148[2] = 0;
    local_148[3] = 0;
    local_148[4] = 0;
    local_148[5] = 0;
    local_148[6] = 0;
    do {
      local_190 = lVar14;
      if (*(int *)((longlong)&local_158 + (longlong)unaff_RSI * 4 + 4) == 0) {
        uVar6 = 0xfa6;
        if (unaff_RSI != (undefined1 *)0x0) goto LAB_2cc08fd1e94;
        puVar21 = (undefined1 *)0x0;
        if ((_DAT_2cc090d2a8c == (short *)0x0) || (*_DAT_2cc090d2a8c == 0)) goto LAB_2cc08fd223e;
        lVar18 = 0;
        unaff_RSI = (undefined1 *)0x0;
        puVar21 = (undefined1 *)0x0;
        local_168 = CONCAT44(local_168._4_4_,*(undefined4 *)(_DAT_2cc090d2a8c + -2));
        psVar35 = _DAT_2cc090d2a8c;
        goto LAB_2cc08fd200a;
      }
      unaff_RSI = unaff_RSI + 1;
    } while (unaff_RSI != (undefined1 *)0x3);
    uVar6 = 0xfa6;
    goto LAB_2cc08fd1e94;
  }
  goto LAB_2cc08fd1f8c;
LAB_2cc08fd200a:
  lVar14 = local_190;
  uVar30 = 0xffffffff;
  uVar26 = 0;
  do {
    uVar29 = uVar26;
    iVar11 = (int)uVar30;
    uVar33 = iVar11 + 1;
    uVar30 = (ulonglong)uVar33;
    if (psVar35[uVar30] == 0x2c) break;
    uVar26 = uVar29 + 1;
  } while (psVar35[uVar30] != 0);
  if (0x7ffffffe < uVar33) {
    uVar6 = 0x13b0;
    if ((local_160 & 0x10000) != 0) {
      (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_160);
    }
    goto LAB_2cc08fd1e94;
  }
  uVar26 = (uint)puVar21;
  if ((uint)unaff_RSI <= uVar26) {
    if ((local_160 & 0x10000) == 0) {
      uVar6 = 0xfa7;
      goto LAB_2cc08fd1e94;
    }
    uVar12 = (uint)local_168;
    if (uVar33 != 0) {
      uVar12 = (uint)local_168 / uVar33;
    }
    uVar12 = uVar26 + 1 + uVar12;
    unaff_RSI = (undefined1 *)(ulonglong)uVar12;
    iVar13 = (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_160,uVar12);
    lVar18 = CONCAT44(local_148[2],local_148[1]);
    if (iVar13 < 0) goto LAB_2cc08fd1e9c;
  }
  puVar22 = *(undefined4 **)(lVar18 + 4 + (longlong)puVar21 * 0xc);
  puVar1 = (undefined4 *)(lVar18 + (longlong)puVar21 * 0xc);
  puVar25 = puVar22 + -3;
  if (puVar22 == (undefined4 *)0x0) {
    puVar25 = (uint *)0x0;
  }
  if ((*(int *)(lVar18 + (longlong)puVar21 * 0xc) == 0) || (puVar25 == (uint *)0x0)) {
LAB_2cc08fd2115:
    puVar15 = (undefined4 *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8);
    if (puVar15 != (undefined4 *)0x0) {
      puVar22 = puVar15 + 3;
      *(undefined8 *)(puVar15 + 1) = 1;
      *(undefined2 *)(puVar15 + 3) = 0;
      *(undefined4 **)(puVar1 + 1) = puVar22;
      *puVar1 = *puVar15;
      goto LAB_2cc08fd2151;
    }
    _DAT_2cc090d2810 = 0x13aa;
  }
  else {
    if ((*puVar25 < uVar33) || (puVar25[1] != 1)) {
      if (*puVar25 != 0) {
        puVar25 = puVar25 + 1;
        *puVar25 = *puVar25 - 1;
        if (*puVar25 == 0) {
          (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
        }
      }
      *(undefined8 *)(puVar1 + 1) = 0;
      *puVar1 = 0;
      goto LAB_2cc08fd2115;
    }
LAB_2cc08fd2151:
    if (uVar33 != 0) {
      if (uVar33 < 8) {
        uVar16 = 0;
      }
      else {
        uVar16 = 0;
        if (0x1f < (ulonglong)((longlong)puVar22 - (longlong)psVar35)) {
          uVar31 = 0;
          uVar16 = (ulonglong)(uVar33 & 0x7ffffff8);
          do {
            psVar2 = psVar35 + uVar31;
            uVar6 = *(undefined4 *)(psVar2 + 2);
            uVar7 = *(undefined4 *)(psVar2 + 4);
            uVar8 = *(undefined4 *)(psVar2 + 6);
            puVar1 = (undefined4 *)((longlong)puVar22 + uVar31 * 2);
            *puVar1 = *(undefined4 *)psVar2;
            puVar1[1] = uVar6;
            puVar1[2] = uVar7;
            puVar1[3] = uVar8;
            uVar31 = uVar31 + 8;
          } while ((uVar29 & 0x7ffffff8) != uVar31);
          if (uVar16 == uVar30) goto LAB_2cc08fd21e2;
        }
      }
      do {
        *(short *)((longlong)puVar22 + uVar16 * 2) = psVar35[uVar16];
        uVar16 = uVar16 + 1;
      } while (uVar29 != uVar16);
    }
LAB_2cc08fd21e2:
    puVar22[-1] = uVar33;
    *(undefined2 *)((longlong)puVar22 + uVar30 * 2) = 0;
  }
  puVar21 = (undefined1 *)(ulonglong)(uVar26 + 1);
  if (psVar35[uVar30] == 0) goto LAB_2cc08fd2237;
  psVar35 = psVar35 + (iVar11 + 2);
  goto LAB_2cc08fd200a;
LAB_2cc08fd2237:
  lVar14 = local_190;
  if ((local_160 & 0x10000) != 0) {
LAB_2cc08fd223e:
    unaff_RSI = puVar21;
    lVar14 = local_190;
    (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_160,unaff_RSI,0);
    puVar21 = unaff_RSI;
  }
  cVar9 = DAT_2cc090d2a80;
  uVar6 = _DAT_2cc090d2810;
  if (0 < (int)puVar21) {
    local_118 = lVar14 + 0x15180;
    local_110 = local_158 & 0xffffffff;
    uVar26 = 0;
    local_168 = (longlong)(_DAT_2cc090d2a78 * 0x3c);
    local_120 = lVar14 - local_168;
    local_100 = (longlong)(_DAT_2cc090d2a70 * 0x3c);
    local_108 = puVar21;
    do {
      local_1a0 = 0;
      local_19c = (int *)0x0;
      if ((uint)local_110 <= uVar26) {
LAB_2cc08fd2d71:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1b052a000001f6);
LAB_2cc08fd2d91:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2b0541000001f9);
LAB_2cc08fd2db1:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x310541000001f9);
        pcVar5 = (code *)swi(3);
        uVar30 = (*pcVar5)();
        return uVar30;
      }
      uVar30 = ~(ulonglong)uVar26 + local_110;
      if ((local_160 & 0x100000) == 0) {
        uVar30 = (ulonglong)uVar26;
      }
      FUN_2cc08fc04d0(&local_1a0,uVar30 * 0xc + CONCAT44(local_148[2],local_148[1]),0,0x2cc090d0e20)
      ;
      piVar19 = local_19c;
      if ((local_19c == (int *)0x0) || (piVar28 = local_19c + -3, piVar28 == (int *)0x0)) {
        _DAT_2cc090d2810 = 0xfa9;
      }
      else {
        uVar29 = local_19c[-1];
        uVar30 = (ulonglong)uVar29;
        if (uVar30 != 0) {
          uVar16 = 0;
          do {
            uVar20 = (ulonglong)*(ushort *)((longlong)local_19c + uVar16 * 2);
            uVar31 = uVar16;
            if ((0x20 < uVar20) || ((0x100002600U >> (uVar20 & 0x3f) & 1) == 0)) break;
            uVar16 = uVar16 + 1;
            uVar31 = uVar30;
          } while (uVar30 != uVar16);
          uVar33 = (uint)uVar31;
          if (uVar33 != 0) {
            local_128 = local_19c;
            uVar12 = uVar29 - uVar33;
            unaff_RSI = (undefined1 *)(ulonglong)uVar12;
            piVar17 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8,unaff_RSI);
            if (piVar17 == (int *)0x0) {
              _DAT_2cc090d2810 = 0x13aa;
            }
            else {
              piVar17[1] = 1;
              piVar17[2] = 0;
              *(undefined2 *)(piVar17 + 3) = 0;
              local_19c = piVar17 + 3;
              uVar30 = (ulonglong)uVar12;
              iVar11 = *piVar17;
              if (uVar29 != uVar33) {
                uVar31 = uVar31 & 0xffffffff;
                uVar16 = uVar30 + (uVar30 == 0);
                if ((7 < uVar12) &&
                   (0x1f < (ulonglong)
                           ((longlong)piVar17 - (longlong)((longlong)piVar28 + uVar31 * 2)))) {
                  uVar32 = 0;
                  uVar20 = (ulonglong)((uint)uVar16 & 0xfffffff8);
                  do {
                    puVar22 = (undefined4 *)((longlong)local_128 + uVar32 * 2 + uVar31 * 2);
                    uVar6 = puVar22[1];
                    uVar7 = puVar22[2];
                    uVar8 = puVar22[3];
                    puVar1 = (undefined4 *)((longlong)local_19c + uVar32 * 2);
                    *puVar1 = *puVar22;
                    puVar1[1] = uVar6;
                    puVar1[2] = uVar7;
                    puVar1[3] = uVar8;
                    uVar32 = uVar32 + 8;
                    if (uVar20 == uVar32) goto LAB_2cc08fd26fd;
                  } while( true );
                }
                uVar20 = 0;
                do {
                  *(undefined2 *)((longlong)local_19c + uVar20 * 2) =
                       *(undefined2 *)((longlong)local_128 + uVar20 * 2 + uVar31 * 2);
                  uVar20 = uVar20 + 1;
LAB_2cc08fd26fd:
                } while (uVar16 != uVar20);
              }
              piVar17[2] = uVar12;
              *(undefined2 *)((longlong)local_19c + uVar30 * 2) = 0;
              bVar36 = local_1a0 != 0;
              local_1a0 = iVar11;
              if ((bVar36) && (*piVar28 != 0)) {
                piVar19 = piVar19 + -2;
                *piVar19 = *piVar19 + -1;
                if (*piVar19 == 0) {
                  (*(code *)0x7ff63a101200)(0x2cc03e1bbb8,piVar28);
                }
              }
            }
          }
        }
      }
      if ((local_19c == (int *)0x0) || (local_19c == (int *)0xc)) {
        _DAT_2cc090d2810 = 0xfa9;
LAB_2cc08fd252b:
        if (local_19c != (int *)0x0) goto LAB_2cc08fd2534;
        _DAT_2cc090d2810 = 0xfa9;
LAB_2cc08fd2853:
        local_f8 = _DAT_2cc03e4621a;
        local_f6 = 1;
        local_f4 = 0x80;
        local_c8 = 0;
        local_d0 = 0;
        local_d8 = 0;
        uStack_d4 = 0;
        local_e0 = 0;
        uStack_dc = 0;
        local_e8 = 0;
        local_f0 = 0;
        iVar11 = (*(code *)0x7ff639cb0550)
                           (0x2cc03e1bbb8,&local_f8,local_120,local_118,0x2cc08fdefd0,&local_1a0);
        if ((0 < iVar11) && (0 < (int)(uint)local_f0)) {
          unaff_RSI = (undefined1 *)0x0;
          do {
            uVar29 = (uint)unaff_RSI;
            local_70 = 0;
            local_78 = 0;
            uStack_74 = 0;
            local_80 = 0;
            local_88 = 0;
            local_90 = 0;
            if ((uint)local_f0 <= uVar29) {
              (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x240534000001f6);
LAB_2cc08fd2d51:
              (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x210539000001f6);
              goto LAB_2cc08fd2d71;
            }
            puVar21 = (undefined1 *)((ulonglong)(uint)local_f0 + ~(ulonglong)unaff_RSI);
            if ((local_f6 & 0x10) == 0) {
              puVar21 = unaff_RSI;
            }
            cVar10 = (*(code *)0x7ff639cb0380)
                               (0x2cc03e1bbb8,
                                *(undefined8 *)
                                 (CONCAT44(local_d8,uStack_dc) + 8 + (longlong)puVar21 * 0x80),
                                local_c0);
            if (cVar10 != '\0') {
              if ((local_9c == 3) || (local_9c == 2 && cVar9 == '\0')) {
                if ((uint)local_f0 <= uVar29) goto LAB_2cc08fd2d51;
                puVar21 = (undefined1 *)((local_f0 & 0xffffffff) + ~(ulonglong)unaff_RSI);
                if ((local_f6 & 0x10) == 0) {
                  puVar21 = unaff_RSI;
                }
                lVar18 = *(longlong *)
                          (CONCAT44(local_d8,uStack_dc) + 0x10 + (longlong)puVar21 * 0x80);
                lVar23 = local_168 + lVar18;
                if ((lVar14 <= lVar23) &&
                   ((lVar18 = lVar18 - local_100, _DAT_2cc090d23e8 == 0 ||
                    (lVar18 < _DAT_2cc090d23e8)))) {
                  _DAT_2cc090d23e8 = lVar18;
                  _DAT_2cc090d23f0 = lVar23;
                  FUN_2cc08fc04d0(&local_188,&local_1a0,0,0x2cc090d0e30);
                  uVar33 = _DAT_2cc08fdf654;
                  uVar30 = (ulonglong)_DAT_2cc08fdf654;
                  if ((uVar30 != 0) || (local_184 == 0)) {
                    if (local_184 == 0) {
                      uVar12 = 0;
                      uVar27 = _DAT_2cc08fdf654;
                    }
                    else {
                      uVar12 = *(uint *)(local_184 + -4);
                      uVar27 = _DAT_2cc08fdf654 + uVar12;
                    }
                    uVar24 = 0x104;
                    if ((0x103 < uVar27) &&
                       ((0x7ffffffd < uVar27 ||
                        (uVar24 = (uVar27 >> 2) + uVar27, 0x7ffffffd < uVar24)))) {
                      uVar24 = 0x7ffffffe;
                    }
                    cVar10 = FUN_2cc08fc0060(&local_188,uVar24);
                    if (cVar10 == '\0') goto LAB_2cc08fd2d91;
                    if (uVar30 != 0) {
                      lVar18 = local_184 + (ulonglong)uVar12 * 2;
                      if (uVar33 < 8) {
                        uVar16 = 0;
                      }
                      else if (local_184 + -0x2cc08fdf658 + (ulonglong)uVar12 * 2 < 0x20) {
                        uVar16 = 0;
                      }
                      else {
                        uVar31 = 0;
                        uVar16 = (ulonglong)(uVar33 & 0xfffffff8);
                        do {
                          uVar6 = *(undefined4 *)(uVar31 + 0x2cc08fdf65c);
                          uVar7 = *(undefined4 *)(uVar31 + 0x2cc08fdf660);
                          uVar8 = *(undefined4 *)(uVar31 + 0x2cc08fdf664);
                          puVar22 = (undefined4 *)(lVar18 + uVar31);
                          *puVar22 = *(undefined4 *)(&DAT_2cc08fdf658 + uVar31);
                          puVar22[1] = uVar6;
                          puVar22[2] = uVar7;
                          puVar22[3] = uVar8;
                          uVar31 = uVar31 + 0x10;
                        } while ((uVar30 * 2 & 0xfffffffffffffff0) != uVar31);
                        if (uVar16 == uVar30) goto LAB_2cc08fd2be2;
                      }
                      do {
                        *(undefined2 *)(lVar18 + uVar16 * 2) =
                             *(undefined2 *)(&DAT_2cc08fdf658 + uVar16 * 2);
                        uVar16 = uVar16 + 1;
                      } while (uVar30 != uVar16);
                    }
LAB_2cc08fd2be2:
                    *(uint *)(local_184 + -4) = uVar27;
                    *(undefined2 *)(local_184 + (ulonglong)uVar27 * 2) = 0;
                  }
                  FUN_2cc08fc04d0(&local_178,&local_188,0);
                  lVar18 = CONCAT44(local_70,uStack_74);
                  if (lVar18 != 0) {
                    uVar33 = *(uint *)(lVar18 + -4);
                    uVar30 = (ulonglong)uVar33;
                    if ((uVar30 != 0) || (local_174 == 0)) {
                      if (local_174 == 0) {
                        uVar12 = 0;
                        uVar27 = uVar33;
                      }
                      else {
                        uVar12 = *(uint *)(local_174 + -4);
                        uVar27 = uVar33 + uVar12;
                      }
                      cVar10 = FUN_2cc08fc0060(&local_178);
                      if (cVar10 == '\0') goto LAB_2cc08fd2db1;
                      if (uVar30 != 0) {
                        lVar14 = local_174 + (ulonglong)uVar12 * 2;
                        if (uVar33 < 8) {
                          uVar16 = 0;
                        }
                        else if ((ulonglong)(lVar14 - lVar18) < 0x20) {
                          uVar16 = 0;
                        }
                        else {
                          uVar31 = 0;
                          uVar16 = (ulonglong)(uVar33 & 0xfffffff8);
                          do {
                            puVar22 = (undefined4 *)(lVar18 + uVar31);
                            uVar6 = puVar22[1];
                            uVar7 = puVar22[2];
                            uVar8 = puVar22[3];
                            puVar1 = (undefined4 *)(lVar14 + uVar31);
                            *puVar1 = *puVar22;
                            puVar1[1] = uVar6;
                            puVar1[2] = uVar7;
                            puVar1[3] = uVar8;
                            uVar31 = uVar31 + 0x10;
                          } while ((uVar30 * 2 & 0xfffffffffffffff0) != uVar31);
                          if (uVar16 == uVar30) goto LAB_2cc08fd2915;
                        }
                        do {
                          *(undefined2 *)(lVar14 + uVar16 * 2) =
                               *(undefined2 *)(lVar18 + uVar16 * 2);
                          uVar16 = uVar16 + 1;
                        } while (uVar30 != uVar16);
                      }
LAB_2cc08fd2915:
                      *(uint *)(local_174 + -4) = uVar27;
                      *(undefined2 *)(local_174 + (ulonglong)uVar27 * 2) = 0;
                      lVar14 = local_190;
                    }
                  }
                  FUN_2cc08fc04d0(0x2cc090d23f8,&local_178,0,0x2cc090d0e50);
                }
              }
            }
            FUN_2cc08fc0000(&local_78);
            FUN_2cc08fc0000((longlong)&local_88 + 4);
            FUN_2cc08fc0000(&local_90);
            unaff_RSI = (undefined1 *)(ulonglong)(uVar29 + 1);
          } while ((int)(uVar29 + 1) < (int)(uint)local_f0);
        }
        FUN_2cc08fc06f0(&local_f8);
      }
      else {
        uVar29 = local_19c[-1];
        unaff_RSI = (undefined1 *)(ulonglong)uVar29;
        if (unaff_RSI != (undefined1 *)0x0) {
          lVar18 = 0;
          puVar21 = unaff_RSI;
          do {
            uVar30 = (ulonglong)
                     *(ushort *)((longlong)local_19c + lVar18 * 2 + (longlong)unaff_RSI * 2 + -2);
            if ((0x20 < uVar30) || ((0x100002600U >> (uVar30 & 0x3f) & 1) == 0)) {
              if ((int)lVar18 == 0) goto LAB_2cc08fd252b;
              uVar33 = -(int)lVar18;
              break;
            }
            lVar18 = lVar18 + -1;
            uVar12 = (int)puVar21 - 1;
            puVar21 = (undefined1 *)(ulonglong)uVar12;
            uVar33 = uVar29;
          } while (uVar12 != 0);
          uVar29 = uVar29 - uVar33;
          unaff_RSI = (undefined1 *)(ulonglong)uVar29;
          cVar10 = FUN_2cc08fc0060(&local_1a0,unaff_RSI);
          if (cVar10 != '\0') {
            local_19c[-1] = uVar29;
            *(undefined2 *)((longlong)local_19c + (ulonglong)uVar29 * 2) = 0;
          }
          goto LAB_2cc08fd252b;
        }
LAB_2cc08fd2534:
        piVar19 = local_19c;
        iVar11 = local_1a0;
        uVar29 = local_19c[-1];
        if (uVar29 != 0) {
          puVar25 = (uint *)(local_19c + -3);
          if (puVar25 == (uint *)0x0) {
            piVar19 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8,uVar29);
            if (piVar19 == (int *)0x0) {
              _DAT_2cc090d2810 = 0x13aa;
              goto LAB_2cc08fd27d9;
            }
            piVar19[1] = 1;
            piVar19[2] = 0;
            *(undefined2 *)(piVar19 + 3) = 0;
            piVar28 = piVar19 + 3;
            local_1a0 = *piVar19;
            local_19c = piVar28;
          }
          else if (((local_1a0 == 0) || (*puVar25 < uVar29)) ||
                  (piVar28 = local_19c, local_19c[-2] != 1)) {
            piVar17 = (int *)(*(code *)0x7ff63a101190)(0x2cc03e1bbb8,uVar29);
            if (piVar17 == (int *)0x0) {
              _DAT_2cc090d2810 = 0x13aa;
              goto LAB_2cc08fd27d9;
            }
            piVar17[1] = 1;
            piVar17[2] = 0;
            *(undefined2 *)(piVar17 + 3) = 0;
            piVar28 = piVar17 + 3;
            uVar33 = piVar19[-1];
            local_1a0 = *piVar17;
            uVar12 = uVar29;
            if (uVar33 < uVar29) {
              uVar12 = uVar33;
            }
            if (uVar33 != 0) {
              uVar30 = (ulonglong)uVar12;
              uVar16 = uVar30 + (uVar30 == 0);
              if (uVar12 < 8) {
                uVar31 = 0;
                goto LAB_2cc08fd2760;
              }
              uVar31 = 0;
              if ((ulonglong)((longlong)piVar17 - (longlong)puVar25) < 0x20) goto LAB_2cc08fd2760;
              uVar20 = 0;
              uVar31 = (ulonglong)((uint)uVar16 & 0xfffffff8);
              do {
                puVar22 = (undefined4 *)((longlong)piVar19 + uVar20);
                uVar6 = puVar22[1];
                uVar7 = puVar22[2];
                uVar8 = puVar22[3];
                puVar1 = (undefined4 *)((longlong)piVar28 + uVar20);
                *puVar1 = *puVar22;
                puVar1[1] = uVar6;
                puVar1[2] = uVar7;
                puVar1[3] = uVar8;
                uVar20 = uVar20 + 0x10;
              } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar20);
              for (; uVar16 != uVar31; uVar31 = uVar31 + 1) {
LAB_2cc08fd2760:
                *(undefined2 *)((longlong)piVar28 + uVar31 * 2) =
                     *(undefined2 *)((longlong)piVar19 + uVar31 * 2);
              }
              piVar17[2] = uVar12;
              *(undefined2 *)((longlong)piVar28 + uVar30 * 2) = 0;
            }
            local_19c = piVar28;
            if ((iVar11 != 0) && (*puVar25 != 0)) {
              piVar19 = piVar19 + -2;
              *piVar19 = *piVar19 + -1;
              if (*piVar19 == 0) {
                (*(code *)0x7ff63a101200)(0x2cc03e1bbb8,puVar25);
              }
            }
          }
          uVar33 = (*(code *)0x7ff63a3fc030)(piVar28,uVar29);
          if (uVar33 != uVar29) {
            piVar28[-1] = uVar33;
            *(undefined2 *)((longlong)piVar28 + (ulonglong)uVar33 * 2) = 0;
          }
        }
LAB_2cc08fd27d9:
        unaff_RSI = &DAT_2cc08fdf030;
        if (local_19c != (int *)&DAT_2cc08fdf030) {
          if (local_19c != (int *)0x0) {
            uVar29 = local_19c[-1];
            uVar33 = _DAT_2cc08fdf02c;
            if (uVar29 < _DAT_2cc08fdf02c) {
              uVar33 = uVar29;
            }
            iVar11 = uVar29 - _DAT_2cc08fdf02c;
            if (uVar33 != 0) {
              uVar30 = 0;
              do {
                uVar3 = *(ushort *)((longlong)local_19c + uVar30 * 2);
                uVar4 = *(ushort *)(&DAT_2cc08fdf030 + uVar30 * 2);
                uVar30 = uVar30 + 1;
                if (uVar33 <= uVar30) break;
              } while (uVar3 == uVar4);
              if (uVar3 != uVar4) {
                iVar11 = (uint)uVar3 - (uint)uVar4;
              }
            }
            if (iVar11 == 0) goto LAB_2cc08fd2304;
          }
          goto LAB_2cc08fd2853;
        }
      }
LAB_2cc08fd2304:
      FUN_2cc08fc0000(&local_1a0);
      uVar26 = uVar26 + 1;
      uVar6 = _DAT_2cc090d2810;
    } while (uVar26 != (uint)local_108);
  }
LAB_2cc08fd1e94:
  _DAT_2cc090d2810 = uVar6;
  lVar18 = CONCAT44(local_148[2],local_148[1]);
LAB_2cc08fd1e9c:
  if (lVar18 != 0) {
    uVar30 = local_158 & 0xffffffff;
    if (uVar30 != 0) {
      lVar14 = -0xc;
      do {
        if ((ulonglong)*(uint *)((longlong)local_148 + lVar14) == 0) break;
        uVar30 = uVar30 * *(uint *)((longlong)local_148 + lVar14);
        lVar14 = lVar14 + 4;
      } while (lVar14 != 0);
      if (uVar30 != 0) {
        plVar34 = (longlong *)(lVar18 + 4);
        unaff_RSI = (undefined1 *)0x2cc03e1bbb8;
        do {
          if ((((*(int *)((longlong)plVar34 + -4) != 0) && (lVar14 = *plVar34, lVar14 != 0)) &&
              ((int *)(lVar14 + -0xc) != (int *)0x0)) && (*(int *)(lVar14 + -0xc) != 0)) {
            piVar19 = (int *)(lVar14 + -8);
            *piVar19 = *piVar19 + -1;
            if (*piVar19 == 0) {
              (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
            }
          }
          *plVar34 = 0;
          *(undefined4 *)((longlong)plVar34 + -4) = 0;
          plVar34 = (longlong *)((longlong)plVar34 + 0xc);
          uVar30 = uVar30 - 1;
        } while (uVar30 != 0);
      }
    }
    (*(code *)0x7ff63a0e6ef0)(0x2cc03e1bbb8,lVar18,0);
    local_148[1] = 0;
    local_148[2] = 0;
    lVar14 = local_190;
  }
  local_158 = local_158 & 0xffffffff00000000;
  local_148[0] = 0;
LAB_2cc08fd1f8c:
  uVar30 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),
                    lVar14 <= _DAT_2cc090d23f0 &&
                    (_DAT_2cc090d23e8 <= lVar14 && 0 < _DAT_2cc090d23e8));
LAB_2cc08fd1fb1:
  FUN_2cc08fc0000(&local_188);
  FUN_2cc08fc0000(&local_178);
  return uVar30 & 0xffffffff;
}



/* Address: 2cc08fd2de0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2cc08fd2de0(void)

{
  longlong lVar1;
  code *pcVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  
  (*(code *)0x7ff63a0e4490)(0x2cc03e1bbb8,0x2cc03e3a870,&local_68);
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,local_68,0x2cc03e3a630);
  local_60 = 0x2cc08fdee50;
  local_58 = 0;
  local_50 = 0;
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,local_68,0x2cc03e09be0);
  local_60 = 0x2cc08fdee90;
  local_58 = 0;
  local_50 = 0;
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,local_68,0x2cc03e3a870);
  local_60 = 0x2cc08fdef50;
  if (DAT_2cc090d2940 == '\0') {
    (*(code *)0x7ff63a0c7370)(0x2cc03e1bbb8,0x2a);
    dVar6 = (_DAT_2cc090d2848 * _DAT_2cc090d2318) / _DAT_2cc08fdea60;
    if ((longlong)dVar6 != -0x8000000000000000) {
      dVar8 = (double)(longlong)dVar6;
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar8) * _DAT_2cc08fdea68 +
                      *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2cc08fdea70)) / _DAT_2cc08fdea68
              + dVar8;
    }
    if ((_DAT_2cc090d2958 != 0.0) || (NAN(_DAT_2cc090d2958))) {
      dVar6 = _DAT_2cc090d2958;
    }
  }
  else {
    (*(code *)0x7ff63a0c7370)(0x2cc03e1bbb8,0x25);
    uVar9 = SUB84(_DAT_2cc090d2848,0);
    uVar10 = (undefined4)((ulonglong)_DAT_2cc090d2848 >> 0x20);
    if (_DAT_2cc090d2848 <= 0.0) {
      (*(code *)0x7ff63a0c7370)(0x2cc03e1bbb8,0x28);
      uVar9 = SUB84(_DAT_2cc090d2848,0);
      uVar10 = (undefined4)((ulonglong)_DAT_2cc090d2848 >> 0x20);
    }
    dVar6 = ((double)CONCAT44(uVar10,uVar9) /
            (double)(~-(ulonglong)(0.0 < _DAT_2cc090d2950) & (ulonglong)_DAT_2cc08fdea60 |
                    (ulonglong)_DAT_2cc090d2950 & -(ulonglong)(0.0 < _DAT_2cc090d2950))) *
            _DAT_2cc090d2948;
    if ((longlong)dVar6 != -0x8000000000000000) {
      dVar8 = (double)(longlong)dVar6;
      dVar6 = (double)(longlong)
                      ((dVar6 - dVar8) * _DAT_2cc08fdea68 +
                      *(double *)((ulonglong)(0.0 < dVar6) * 8 + 0x2cc08fdea70)) / _DAT_2cc08fdea68
              + dVar8;
    }
  }
  (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,0x24);
  if ((_DAT_2cc090d2848 == 0.0) && (!NAN(_DAT_2cc090d2848))) {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f024a000001f7);
    pcVar2 = (code *)swi(3);
    dVar6 = (double)(*pcVar2)();
    return dVar6;
  }
  dVar7 = dVar6 / _DAT_2cc090d2848;
  uVar4 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar4 - 0x3ff;
  dVar8 = dVar7;
  if ((ulonglong)uVar4 < 0x433) {
    if (uVar4 < 0x3ff) {
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
  uVar5 = -(ulonglong)
           (_DAT_2cc08fdea90 <
           (double)((ulonglong)(_DAT_2cc090d2848 * (double)(int)dVar8 - dVar6) & _DAT_2cc08fdea80));
  dVar6 = (double)(~uVar5 & (ulonglong)dVar6 |
                  (ulonglong)(_DAT_2cc090d2848 * (double)(int)dVar8) & uVar5);
  (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,0x22);
  if (dVar6 < _DAT_2cc090d2848) {
    (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,0x22);
    dVar6 = _DAT_2cc090d2848;
  }
  (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,0x23);
  if (_DAT_2cc090d2848 < dVar6) {
    (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,0x23);
    dVar6 = _DAT_2cc090d2848;
  }
  FUN_2cc08fdb970(&local_68);
  return dVar6;
}



/* Address: 2cc08fd3240 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2cc08fd3240(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  double dVar2;
  char cVar3;
  undefined4 uVar4;
  double *pdVar5;
  undefined8 in_stack_ffffffffffffff08;
  undefined4 local_b0;
  undefined8 local_ac;
  double local_a0;
  undefined1 local_98 [16];
  undefined8 local_88;
  undefined4 uVar6;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  local_b0 = 0;
  local_ac = 0;
  (*(code *)0x7ff63a0f2c10)(0x2cc03e1bbb8,param_1,local_98);
  (*(code *)0x7ff63a0c7370)(0x2cc03e1bbb8,0x2a);
  dVar2 = _DAT_2cc090d2848;
  pdVar5 = &local_a0;
  cVar3 = (*(code *)0x7ff63a108d40)(0x2cc03e1bbb8,0,param_1,(int)param_2,local_88,pdVar5);
  uVar1 = _DAT_2cc090d2810;
  uVar6 = (undefined4)((ulonglong)pdVar5 >> 0x20);
  if (cVar3 == '\0') {
    (*(code *)0x7ff63a0e49f0)
              (0x2cc03e1bbb8,2,4,0x590008,0x2cc08fe0fe0,CONCAT44(uVar6,0x590008),0x2cc08fe1028,
               0x590008,0x2cc08fe1060,0x520004,CONCAT44(uVar4,_DAT_2cc090d2810));
    uVar4 = 0;
  }
  else {
    uVar4 = 0x3e1bb01;
    if (dVar2 < local_a0) {
      uVar4 = 0;
      FUN_2cc08fc0870(&local_b0,0,0x2cc090d0240,10);
      (*(code *)0x7ff63a0e49f0)
                (0x2cc03e1bbb8,2,8,0x590008,0x2cc08fe10a8,CONCAT44(uVar6,0x590008),&local_b0,
                 0x590008,0x2cc08fdf660,0x580007,param_2,0x590008,0x2cc08fdf660,0x590008,param_1,
                 0x590008,0x2cc08fe10e8,0x520004,uVar1);
    }
  }
  FUN_2cc08fc0000(&local_b0);
  return uVar4;
}



/* Address: 2cc08fd34c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2cc08fd34c0(longlong param_1,ulonglong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_80;
  longlong local_7c;
  longlong local_70;
  ulonglong local_68;
  longlong local_60;
  
  local_80 = 0;
  local_7c = 0;
  local_60 = param_1;
  iVar7 = (*(code *)0x7ff63a107da0)(0x2cc03e1bbb8);
  if (iVar7 + -1 < 0) {
    uVar11 = 0;
    uVar12 = 0;
  }
  else {
    uVar11 = 0;
    uVar12 = 0;
    local_70 = 0;
    iVar7 = iVar7 + -1;
    local_68 = param_2 & 0xffffffff;
    do {
      (*(code *)0x7ff63a107e40)(0x2cc03e1bbb8,iVar7);
      FUN_2cc08fc04d0(&local_80,0x2cc090d283c,1,0x2cc090d0050);
      if (local_7c == _DAT_2cc090d282c) {
LAB_2cc08fd3618:
        lVar8 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,0xc);
        if (lVar8 == local_60) {
          uVar10 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,2);
          if (uVar10 == local_68) {
            lVar8 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,1);
            if (local_70 < lVar8) {
              (*(code *)0x7ff63a107f70)(0x2cc03e1bbb8,4);
              uVar11 = (undefined4)_DAT_2cc090d2848;
              uVar12 = (undefined4)((ulonglong)_DAT_2cc090d2848 >> 0x20);
              local_70 = lVar8;
            }
          }
        }
      }
      else if ((local_7c != 0) && (_DAT_2cc090d282c != 0)) {
        uVar3 = *(uint *)(local_7c + -4);
        uVar4 = *(uint *)(_DAT_2cc090d282c + -4);
        uVar6 = uVar4;
        if (uVar3 < uVar4) {
          uVar6 = uVar3;
        }
        iVar9 = uVar3 - uVar4;
        if (uVar6 != 0) {
          uVar10 = 1;
          do {
            uVar1 = *(ushort *)(local_7c + -2 + uVar10 * 2);
            uVar2 = *(ushort *)(_DAT_2cc090d282c + -2 + uVar10 * 2);
            if (uVar6 <= uVar10) break;
            uVar10 = uVar10 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar9 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar9 == 0) goto LAB_2cc08fd3618;
      }
      bVar5 = 0 < iVar7;
      iVar7 = iVar7 + -1;
    } while (bVar5);
  }
  FUN_2cc08fc0000(&local_80);
  return CONCAT44(uVar12,uVar11);
}



/* Address: 2cc08fd36c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_2cc08fd36c0(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 local_a0;
  undefined4 local_98;
  undefined1 local_90 [80];
  
  if (_DAT_2cc090d2814 == 0) {
    _DAT_2cc090d2020 = 0;
    _DAT_2cc090d2024 = 0;
    uRam000002cc090d2028 = 0;
    uRam000002cc090d202c = 0;
    _DAT_2cc090d2030 = 0;
    FUN_2cc08fc0000(0x2cc090d2034);
    _DAT_2cc090d2080 = 0;
    _DAT_2cc090d2070 = 0;
    _DAT_2cc090d2078 = 0;
    _DAT_2cc090d2060 = 0;
    _DAT_2cc090d2068 = 0;
    _DAT_2cc090d2050 = 0;
    _DAT_2cc090d2058 = 0;
    _DAT_2cc090d2040 = 0;
    _DAT_2cc090d2048 = 0;
    FUN_2cc08fc0000(0x2cc090d2084);
    _DAT_2cc090d2100 = 0;
    uRam000002cc090d2108 = 0;
    _DAT_2cc090d2120 = 0;
    uRam000002cc090d2128 = 0;
    _DAT_2cc090d2130 = 0;
    uRam000002cc090d2138 = 0;
    _DAT_2cc090d2110 = 0;
    uRam000002cc090d2118 = 0;
    _DAT_2cc090d20e0 = 0;
    uRam000002cc090d20e8 = 0;
    _DAT_2cc090d20f0 = 0;
    uRam000002cc090d20f8 = 0;
    _DAT_2cc090d20c0 = 0;
    uRam000002cc090d20c8 = 0;
    _DAT_2cc090d20d0 = 0;
    uRam000002cc090d20d8 = 0;
    _DAT_2cc090d20a0 = 0;
    uRam000002cc090d20a8 = 0;
    _DAT_2cc090d20b0 = 0;
    uRam000002cc090d20b8 = 0;
    _DAT_2cc090d2140 = 0;
    _DAT_2cc090d2090 = 0;
    uRam000002cc090d2098 = 0;
    FUN_2cc08fc0000(0x2cc090d2144);
    _DAT_2cc090d21e0 = 0;
    uRam000002cc090d21e8 = 0;
    _DAT_2cc090d21d0 = 0;
    uRam000002cc090d21d8 = 0;
    _DAT_2cc090d21f0 = 0;
    uRam000002cc090d21f8 = 0;
    _DAT_2cc090d21c0 = 0;
    uRam000002cc090d21c8 = 0;
    _DAT_2cc090d21b0 = 0;
    uRam000002cc090d21b8 = 0;
    _DAT_2cc090d21a0 = 0;
    uRam000002cc090d21a8 = 0;
    _DAT_2cc090d2190 = 0;
    uRam000002cc090d2198 = 0;
    _DAT_2cc090d2180 = 0;
    uRam000002cc090d2188 = 0;
    _DAT_2cc090d2170 = 0;
    uRam000002cc090d2178 = 0;
    _DAT_2cc090d2160 = 0;
    uRam000002cc090d2168 = 0;
    _DAT_2cc090d2150 = 0;
    uRam000002cc090d2158 = 0;
    _DAT_2cc090d2200 = 0;
    FUN_2cc08fc0000(0x2cc090d2208);
    _DAT_2cc090d2284 = 0;
    _DAT_2cc090d227c = 0;
    _DAT_2cc090d228c = 0;
    _DAT_2cc090d2274 = 0;
    _DAT_2cc090d226c = 0;
    _DAT_2cc090d2264 = 0;
    _DAT_2cc090d225c = 0;
    _DAT_2cc090d2254 = 0;
    _DAT_2cc090d224c = 0;
    _DAT_2cc090d2244 = 0;
    _DAT_2cc090d223c = 0;
    _DAT_2cc090d2234 = 0;
    _DAT_2cc090d222c = 0;
    _DAT_2cc090d2224 = 0;
    _DAT_2cc090d221c = 0;
    _DAT_2cc090d2214 = 0;
    if (param_1 < 2) {
      _DAT_2cc090d2020 = 1;
      FUN_2cc08fc04d0(0x2cc090d2034,0x2cc090d2828,0,0x2cc090cf2b8);
      local_a0 = 0;
      local_98 = 0;
      _DAT_2cc090d2024 = (undefined4)_DAT_2cc090d2295;
      uRam000002cc090d2028 = (undefined4)((ulonglong)_DAT_2cc090d2295 >> 0x20);
      _DAT_2cc090d2070 = CONCAT44(_DAT_2cc090d2074,param_1);
      _DAT_2cc090d2060 = param_5;
      _DAT_2cc090d2068 = _DAT_2cc090d229d;
      _DAT_2cc090d2040 = param_2;
      _DAT_2cc090d2048 = param_3;
      _DAT_2cc090d2058 = param_4;
      FUN_2cc08fc04d0(&local_a0,0x2cc090d2828,0,0x2cc090cfe58);
      (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_a0,0x47,local_90);
      if ((_DAT_2cc090d2070 & 0xffffffff) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02cc08fd3bcb */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)((_DAT_2cc090d2070 & 0xffffffff) * 8 + 0x2cc08fdea98))();
        return uVar1;
      }
      _DAT_2cc090d2110 = CONCAT44(DAT_2cc090d2110_4,0x2733);
      (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,2,1,0x590008,0x2cc08fe0eb8);
      FUN_2cc08fc0000(&local_a0);
    }
    else {
      _DAT_2cc090d2110 = CONCAT44(DAT_2cc090d2110_4,0x271d);
      FUN_2cc08fc04d0(0x2cc090d2144,0x2cc08fdfe08,0,0x2cc090cf2a8);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,0xd,2,0x590008,0x2cc08fe0f40,0x590008,0x2cc08fdfdb8);
    _DAT_2cc090d2110 = CONCAT44(DAT_2cc090d2110_4,0x272b);
  }
  return 0;
}



/* Address: 2cc08fd3d40 */

void FUN_2cc08fd3d40(void)

{
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_30;
  undefined8 local_2c;
  
  local_30 = 0;
  local_2c = 0;
  local_40 = 0;
  local_38 = 0;
  FUN_2cc08fd80c0(&local_40,&DAT_2cc090d2020,&DAT_2cc090d2110);
  FUN_2cc08fc04d0(&local_30,&local_40,0,0x2cc090cf288);
  FUN_2cc08fc0000(&local_40);
  FUN_2cc08fc04d0(0x2cc090d283c,&local_30,1,0x2cc090cf298);
  FUN_2cc08fc0000(&local_30);
  return;
}



/* Address: 2cc08fd3e00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd3e00(void)

{
  char cVar1;
  longlong lVar2;
  
  if (DAT_2cc090d2406 != '\0') {
    FUN_2cc08fd3ed0();
  }
  lVar2 = _DAT_2cc090d2418;
  if ((((DAT_2cc090d2405 == '\0') || (_DAT_2cc090d240c == -1)) ||
      ((lVar2 = (*(code *)0x7ff63a103b50)(0x2cc03e1bbb8,0x2cc08fdefd0,0,1), 0 < lVar2 &&
       (((_DAT_2cc090d2410 == 0 || (lVar2 != _DAT_2cc090d2418)) &&
        (cVar1 = FUN_2cc08fcf8e0(), cVar1 != '\0')))))) &&
     (_DAT_2cc090d2418 = lVar2, DAT_2cc090d2404 != '\0')) {
    FUN_2cc08fc2d80();
    return;
  }
  return;
}



/* Address: 2cc08fd3ed0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd3ed0(void)

{
  double dVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined1 local_d8 [8];
  double local_d0;
  
  uVar19 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  local_e8 = 0;
  local_e4 = 0;
  if (DAT_2cc090d2420 != '\x01') goto LAB_2cc08fd42f7;
  uVar10 = 0xfa;
  if (DAT_2cc090d2327 != '\0') {
    uVar10 = 900;
  }
  iVar5 = (*(code *)0x7ff63a3fc2a0)();
  uVar11 = iVar5 - _DAT_2cc090d2424;
  if (uVar11 < uVar10) {
    lVar7 = (*(code *)0x7ff63a103b50)(0x2cc03e1bbb8,0x2cc08fdefd0,0,0);
    if (lVar7 != _DAT_2cc090d2428) goto LAB_2cc08fd42b0;
    (*(code *)0x7ff63a103c40)(0x2cc03e1bbb8,0x2cc08fdefd0,0,0);
    dVar1 = _DAT_2cc090d2848;
    uVar21 = SUB84(_DAT_2cc090d2848,0);
    uVar2 = (ulonglong)_DAT_2cc090d2848 >> 0x20;
    (*(code *)0x7ff63a103cc0)(0x2cc03e1bbb8,0x2cc08fdefd0,0,0);
    dVar17 = _DAT_2cc090d2848;
    uVar19 = SUB84(_DAT_2cc090d2848,0);
    uVar3 = (ulonglong)_DAT_2cc090d2848 >> 0x20;
    cVar4 = (*(code *)0x7ff63a0f2c10)(0x2cc03e1bbb8,0x2cc08fdefd0,local_d8);
    if ((cVar4 == '\0') || (local_d0 <= 0.0)) goto LAB_2cc08fd42f7;
    uVar8 = (undefined4)((ulonglong)local_d0 >> 0x20);
    uVar22 = (int)uVar2;
    if (dVar1 <= local_d0) {
      uVar21 = SUB84(local_d0,0);
      uVar22 = uVar8;
    }
    uVar20 = (int)uVar3;
    if (local_d0 <= dVar17) {
      uVar19 = SUB84(local_d0,0);
      uVar20 = uVar8;
    }
    dVar1 = (double)uVar11 / (double)uVar10;
    iVar6 = (*(code *)0x7ff63a0e2010)(0x2cc03e1bbb8,0);
    iVar5 = 0x3c;
    if (0 < iVar6) {
      iVar5 = iVar6;
    }
    dVar17 = (double)CONCAT44(uVar22,uVar21) - (double)CONCAT44(uVar20,uVar19);
    dVar18 = (double)iVar5;
    if (dVar17 <= _DAT_2cc090d2818 * _DAT_2cc08fdead8) {
      dVar17 = _DAT_2cc090d2818 * _DAT_2cc08fdead8;
    }
    dVar16 = (_DAT_2cc08fdeae0 * dVar1 + _DAT_2cc08fdeae8) * dVar17;
    dVar17 = (_DAT_2cc08fdeaf0 * dVar1 + _DAT_2cc08fdeaf8) * dVar17;
    lVar7 = (longlong)((_DAT_2cc08fdeb10 * dVar1 + _DAT_2cc08fdeb18) * dVar18) + _DAT_2cc090d2428;
    lVar13 = (longlong)((_DAT_2cc08fdeb20 * dVar1 + _DAT_2cc08fdeb28) * dVar18) + _DAT_2cc090d2428;
    lVar15 = _DAT_2cc090d2428 - (longlong)((_DAT_2cc08fdeb00 * dVar1 + _DAT_2cc08fdeb08) * dVar18);
    uVar8 = 0x965f19;
    if (dVar1 < _DAT_2cc08fdeb30) {
      uVar8 = 0xffb92d;
    }
    uVar9 = 0xcd911e;
    if (dVar1 < _DAT_2cc08fdeb30) {
      uVar9 = 0xffe146;
    }
    uVar12 = 0xfff5be;
    if (_DAT_2cc08fdeb18 <= dVar1) {
      uVar12 = uVar8;
    }
    uVar8 = 0xffffff;
    if (_DAT_2cc08fdeb18 <= dVar1) {
      uVar8 = uVar9;
    }
    uVar11 = (uint)DAT_2cc090d2328;
    uVar10 = (uint)DAT_2cc090d2328;
    uVar14 = (uint)DAT_2cc090d2328;
    FUN_2cc08fc04d0(&local_e8,0x2cc08fe12c8,0,0x2cc090d02f0);
    FUN_2cc08fdc7c0(&local_e8,lVar15,(double)CONCAT44(uVar20,uVar19) - dVar16,lVar7,
                    (double)CONCAT44(uVar22,uVar21) + dVar16,uVar12,uVar14 * 2 + (uint)(uVar14 == 0)
                   );
    lVar7 = _DAT_2cc090d2428;
    FUN_2cc08fc04d0(&local_e8,0x2cc08fe1300,0,0x2cc090d0300);
    FUN_2cc08fdc7c0(&local_e8,lVar7,(double)CONCAT44(uVar20,uVar19) - dVar17,lVar13,
                    (double)CONCAT44(uVar22,uVar21) + dVar17,uVar8,uVar11 + 1 + uVar10);
  }
  else {
LAB_2cc08fd42b0:
    (*(code *)0x7ff63a0f4da0)(0x2cc03e1bbb8,0,0x2cc08fe1288,0xffffffff,CONCAT44(uVar19,0xffffffff));
    DAT_2cc090d2420 = '\0';
  }
  (*(code *)0x7ff63a0f51b0)(0x2cc03e1bbb8,0);
LAB_2cc08fd42f7:
  FUN_2cc08fc0000(&local_e8);
  return;
}



/* Address: 2cc08fd4350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd4350(int param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ushort uVar5;
  ushort uVar6;
  undefined1 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char cVar12;
  int iVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  undefined4 local_58;
  longlong local_54;
  
  local_68 = 0;
  local_78 = 0;
  local_88 = 0;
  local_58 = 0;
  local_64 = 0;
  local_74 = 0;
  local_84 = 0;
  local_54 = 0;
  if (param_1 != 1) goto LAB_2cc08fd4a34;
  puVar7 = *(undefined1 **)(param_4 + 4);
  if (puVar7 == &DAT_2cc08fdf6dc) {
LAB_2cc08fd4527:
    DAT_2cc090d23d8 = DAT_2cc090d23d8 == '\0';
    if ((bool)DAT_2cc090d23d8) {
      uVar23 = (undefined4)_DAT_2cc08fdeb38;
    }
    else {
      uVar23 = 0;
    }
    (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,_DAT_2cc090d2960,0x56,&local_58);
    FUN_2cc08fc04d0(&local_88,0x2cc08fdf2c8);
    lVar2 = local_54;
    if (local_54 != 0) {
      uVar22 = *(uint *)(local_54 + -4);
      uVar21 = (ulonglong)uVar22;
      if ((uVar21 == 0) && (local_84 != 0)) goto LAB_2cc08fd473d;
      if (local_84 == 0) {
        uVar18 = 0;
        uVar16 = uVar22;
      }
      else {
        uVar18 = *(uint *)(local_84 + -4);
        uVar16 = uVar22 + uVar18;
      }
      cVar12 = FUN_2cc08fc0060(&local_88);
      if (cVar12 != '\0') {
        if (uVar21 != 0) {
          lVar1 = local_84 + (ulonglong)uVar18 * 2;
          if (uVar22 < 0x10) {
            uVar15 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar20 = 0;
            uVar15 = (ulonglong)(uVar22 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar20);
              uVar9 = puVar3[1];
              uVar10 = puVar3[2];
              uVar11 = puVar3[3];
              puVar4 = (undefined4 *)(lVar1 + uVar20);
              *puVar4 = *puVar3;
              puVar4[1] = uVar9;
              puVar4[2] = uVar10;
              puVar4[3] = uVar11;
              uVar20 = uVar20 + 0x10;
            } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar20);
            if (uVar15 == uVar21) goto LAB_2cc08fd4732;
          }
          do {
            *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar2 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar21 != uVar15);
        }
LAB_2cc08fd4732:
        *(uint *)(local_84 + -4) = uVar16;
        *(undefined2 *)(local_84 + (ulonglong)uVar16 * 2) = 0;
        goto LAB_2cc08fd473d;
      }
LAB_2cc08fd4a94:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x260509000001f9);
LAB_2cc08fd4ab4:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x410509000001f9);
      pcVar8 = (code *)swi(3);
      (*pcVar8)();
      return;
    }
LAB_2cc08fd473d:
    uVar22 = 0;
    FUN_2cc08fc04d0(&local_78,&local_88,0,0x2cc090cf158);
    uVar18 = _DAT_2cc08fdf2dc;
    uVar21 = (ulonglong)_DAT_2cc08fdf2dc;
    if ((uVar21 != 0) || (local_74 == 0)) {
      if (local_74 != 0) {
        uVar22 = *(uint *)(local_74 + -4);
      }
      uVar17 = _DAT_2cc08fdf2dc + uVar22;
      uVar16 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar16 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar12 = FUN_2cc08fc0060(&local_78,uVar16);
      if (cVar12 == '\0') {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3b0509000001f9);
        goto LAB_2cc08fd4a94;
      }
      if (uVar21 != 0) {
        lVar2 = local_74 + (ulonglong)uVar22 * 2;
        if (uVar18 < 0x10) {
          uVar15 = 0;
        }
        else if (lVar2 - 0x2cc08fdf2e0U < 0x20) {
          uVar15 = 0;
        }
        else {
          uVar20 = 0;
          uVar15 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar9 = *(undefined4 *)(uVar20 + 0x2cc08fdf2e4);
            uVar10 = *(undefined4 *)(uVar20 + 0x2cc08fdf2e8);
            uVar11 = *(undefined4 *)(uVar20 + 0x2cc08fdf2ec);
            puVar3 = (undefined4 *)(lVar2 + uVar20);
            *puVar3 = *(undefined4 *)(&DAT_2cc08fdf2e0 + uVar20);
            puVar3[1] = uVar9;
            puVar3[2] = uVar10;
            puVar3[3] = uVar11;
            uVar20 = uVar20 + 0x10;
          } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar20);
          if (uVar15 == uVar21) goto LAB_2cc08fd4862;
        }
        do {
          *(undefined2 *)(lVar2 + uVar15 * 2) = *(undefined2 *)(&DAT_2cc08fdf2e0 + uVar15 * 2);
          uVar15 = uVar15 + 1;
        } while (uVar21 != uVar15);
      }
LAB_2cc08fd4862:
      *(uint *)(local_74 + -4) = uVar17;
      *(undefined2 *)(local_74 + (ulonglong)uVar17 * 2) = 0;
    }
    FUN_2cc08fc04d0(&local_68,&local_78,0);
    lVar2 = _DAT_2cc090d282c;
    if (_DAT_2cc090d282c != 0) {
      uVar22 = *(uint *)(_DAT_2cc090d282c + -4);
      uVar21 = (ulonglong)uVar22;
      if ((uVar21 != 0) || (local_64 == 0)) {
        if (local_64 == 0) {
          uVar15 = 0;
          uVar18 = uVar22;
        }
        else {
          uVar15 = (ulonglong)*(uint *)(local_64 + -4);
          uVar18 = uVar22 + *(uint *)(local_64 + -4);
        }
        cVar12 = FUN_2cc08fc0060(&local_68);
        if (cVar12 == '\0') goto LAB_2cc08fd4ab4;
        if (uVar21 != 0) {
          lVar1 = local_64 + uVar15 * 2;
          if (uVar22 < 0x10) {
            uVar15 = 0;
          }
          else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar20 = 0;
            uVar15 = (ulonglong)(uVar22 & 0xfffffff8);
            do {
              puVar3 = (undefined4 *)(lVar2 + uVar20);
              uVar9 = puVar3[1];
              uVar10 = puVar3[2];
              uVar11 = puVar3[3];
              puVar4 = (undefined4 *)(lVar1 + uVar20);
              *puVar4 = *puVar3;
              puVar4[1] = uVar9;
              puVar4[2] = uVar10;
              puVar4[3] = uVar11;
              uVar20 = uVar20 + 0x10;
            } while ((uVar21 * 2 & 0xfffffffffffffff0) != uVar20);
            if (uVar15 == uVar21) goto LAB_2cc08fd4992;
          }
          do {
            *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar2 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar21 != uVar15);
        }
LAB_2cc08fd4992:
        *(uint *)(local_64 + -4) = uVar18;
        *(undefined2 *)(local_64 + (ulonglong)uVar18 * 2) = 0;
      }
    }
    (*(code *)0x7ff63a0edc90)(0x2cc03e1bbb8,&local_68,uVar23);
    uVar14 = 0x2cc08fdf770;
    uVar19 = 1;
    if (DAT_2cc090d23d8 == '\0') {
      uVar14 = 0x2cc08fdf7b8;
    }
LAB_2cc08fd49f6:
    (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,2,uVar19,0x590008,uVar14);
  }
  else {
    if (puVar7 == (undefined1 *)0x0) goto LAB_2cc08fd4a34;
    uVar22 = *(uint *)(puVar7 + -4);
    uVar18 = _DAT_2cc08fdf6d8;
    if (uVar22 < _DAT_2cc08fdf6d8) {
      uVar18 = uVar22;
    }
    iVar13 = uVar22 - _DAT_2cc08fdf6d8;
    if (uVar18 != 0) {
      uVar21 = 0;
      do {
        uVar5 = *(ushort *)(puVar7 + uVar21 * 2);
        uVar6 = *(ushort *)(&DAT_2cc08fdf6dc + uVar21 * 2);
        uVar21 = uVar21 + 1;
        if (uVar18 <= uVar21) break;
      } while (uVar5 == uVar6);
      if (uVar5 != uVar6) {
        iVar13 = (uint)uVar5 - (uint)uVar6;
      }
    }
    if (iVar13 == 0) goto LAB_2cc08fd4527;
    if (puVar7 != &DAT_2cc08fdf7dc) {
      uVar18 = _DAT_2cc08fdf7d8;
      if (uVar22 < _DAT_2cc08fdf7d8) {
        uVar18 = uVar22;
      }
      iVar13 = uVar22 - _DAT_2cc08fdf7d8;
      if (uVar18 != 0) {
        uVar21 = 0;
        do {
          uVar5 = *(ushort *)(puVar7 + uVar21 * 2);
          uVar6 = *(ushort *)(&DAT_2cc08fdf7dc + uVar21 * 2);
          uVar21 = uVar21 + 1;
          if (uVar18 <= uVar21) break;
        } while (uVar5 == uVar6);
        if (uVar5 != uVar6) {
          iVar13 = (uint)uVar5 - (uint)uVar6;
        }
      }
      if (iVar13 == 0) goto LAB_2cc08fd45f1;
      if (puVar7 != &DAT_2cc08fdf8cc) {
        uVar18 = _DAT_2cc08fdf8c8;
        if (uVar22 < _DAT_2cc08fdf8c8) {
          uVar18 = uVar22;
        }
        iVar13 = uVar22 - _DAT_2cc08fdf8c8;
        if (uVar18 != 0) {
          uVar21 = 0;
          do {
            uVar5 = *(ushort *)(puVar7 + uVar21 * 2);
            uVar6 = *(ushort *)(&DAT_2cc08fdf8cc + uVar21 * 2);
            uVar21 = uVar21 + 1;
            if (uVar18 <= uVar21) break;
          } while (uVar5 == uVar6);
          if (uVar5 != uVar6) {
            iVar13 = (uint)uVar5 - (uint)uVar6;
          }
        }
        if (iVar13 != 0) goto LAB_2cc08fd4a34;
      }
      FUN_2cc08fd4ae0(1);
      uVar14 = 0x2cc08fdf938;
LAB_2cc08fd4649:
      uVar19 = 2;
      goto LAB_2cc08fd49f6;
    }
LAB_2cc08fd45f1:
    iVar13 = (*(code *)0x7ff63a0e16a0)(0x2cc03e1bbb8,0x2cc08fdf860,0x2cc08fdf018,0x24);
    if (iVar13 == 6) {
      FUN_2cc08fd4ae0(0);
      uVar14 = 0x2cc08fdf8a8;
      goto LAB_2cc08fd4649;
    }
  }
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_4,0x3fa,0);
  FUN_2cc08fc2d80();
LAB_2cc08fd4a34:
  FUN_2cc08fc0000(&local_58);
  FUN_2cc08fc0000(&local_88);
  FUN_2cc08fc0000(&local_78);
  FUN_2cc08fc0000(&local_68);
  return;
}



/* Address: 2cc08fd4ae0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_2cc08fd4ae0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  double dVar7;
  longlong lVar8;
  char cVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  ulonglong uVar14;
  int local_8c;
  undefined4 local_78;
  longlong local_74;
  
  local_78 = 0;
  local_74 = 0;
  iVar10 = (*(code *)0x7ff63a107da0)(0x2cc03e1bbb8);
  lVar8 = _DAT_2cc090d2960;
  if (iVar10 + -1 < 0) {
    local_8c = 0;
  }
  else {
    local_8c = 0;
    iVar10 = iVar10 + -1;
    do {
      lVar11 = (*(code *)0x7ff63a107df0)(0x2cc03e1bbb8,iVar10);
      if (lVar11 != 0) {
        (*(code *)0x7ff63a108010)(0x2cc03e1bbb8,0);
        FUN_2cc08fc04d0(&local_78,0x2cc090d283c,1,0x2cc090d0e00);
        if (local_74 == _DAT_2cc090d282c) {
LAB_2cc08fd4cd8:
          lVar12 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,0xc);
          if (lVar12 == lVar8) {
            (*(code *)0x7ff63a107f70)(0x2cc03e1bbb8,10);
            dVar7 = _DAT_2cc090d2848;
            (*(code *)0x7ff63a107f70)(0x2cc03e1bbb8,9);
            if ((param_1 != 1) || (0.0 < dVar7 + _DAT_2cc090d2848)) {
              cVar9 = FUN_2cc08fd1310(lVar11);
              if (cVar9 == '\0') {
                (*(code *)0x7ff63a0e49f0)
                          (0x2cc03e1bbb8,2,4,0x590008,0x2cc08fe1ee8,0x560015,lVar11,0x590008,
                           0x2cc08fdf5f0,0x530014,_DAT_2cc090d2110);
              }
              else {
                local_8c = local_8c + 1;
              }
            }
          }
        }
        else if ((local_74 != 0) && (_DAT_2cc090d282c != 0)) {
          uVar3 = *(uint *)(local_74 + -4);
          uVar4 = *(uint *)(_DAT_2cc090d282c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar13 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar14 = 1;
            do {
              uVar1 = *(ushort *)(local_74 + -2 + uVar14 * 2);
              uVar2 = *(ushort *)(_DAT_2cc090d282c + -2 + uVar14 * 2);
              if (uVar6 <= uVar14) break;
              uVar14 = uVar14 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar13 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar13 == 0) goto LAB_2cc08fd4cd8;
        }
      }
      bVar5 = 0 < iVar10;
      iVar10 = iVar10 + -1;
    } while (bVar5);
  }
  FUN_2cc08fc0000(&local_78);
  return local_8c;
}



/* Address: 2cc08fd4db0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd4db0(int param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  if ((param_1 == 1) && (DAT_2cc090d2540 == '\x01')) {
    uVar1 = 0x15;
    if (DAT_2cc090d24c8 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d24d8);
    uVar1 = 0x16;
    if (DAT_2cc090d24c9 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d24e0);
    uVar1 = 0x17;
    if (DAT_2cc090d24ca == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d24e8);
    uVar1 = 0x19;
    if (DAT_2cc090d24cb == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d24f0);
    uVar1 = 0x1a;
    if (DAT_2cc090d24cc == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d24f8);
    uVar1 = 0x1c;
    if (DAT_2cc090d24cd == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2500);
    uVar1 = 0x1d;
    if (DAT_2cc090d24ce == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2508);
    uVar1 = 0x1b;
    if (DAT_2cc090d24cf == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2510);
    uVar1 = 0x18;
    if (DAT_2cc090d24d0 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2518);
    uVar1 = 0x1e;
    if (DAT_2cc090d24d1 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2520);
    uVar1 = 0x1f;
    if (DAT_2cc090d24d2 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2528);
    uVar1 = 0x21;
    if (DAT_2cc090d24d3 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2530);
    uVar1 = 0x11;
    if (DAT_2cc090d24d4 == '\0') {
      uVar1 = 0;
    }
    (*(code *)0x7ff63a0f5240)(0x2cc03e1bbb8,0,uVar1,_DAT_2cc090d2538);
    (*(code *)0x7ff63a0f51b0)(0x2cc03e1bbb8,0);
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2cc03e1bbb8,0xd,7,0x590008,0x2cc08fdfa00,0x520004,_DAT_2cc090d2498,0x520004,
             _DAT_2cc090d249c,0x520004,_DAT_2cc090d24a0,0x520004,_DAT_2cc090d24a4,0x520004,
             _DAT_2cc090d24a8,0x520004,_DAT_2cc090d24ac);
  uVar2 = 0x2cc;
  (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,0xd,2,0x590008,0x2cc08fdfa50,0x520004,_DAT_2cc090d24b0);
  (*(code *)0x7ff63a0e72d0)(0x2cc03e1bbb8);
  if (DAT_2cc090d23c4 == '\x01') {
    FUN_2cc08fc0eb0(&DAT_2cc090d2330);
    DAT_2cc090d23c4 = '\0';
  }
  uVar1 = CONCAT44(uVar2,0xffffffff);
  (*(code *)0x7ff63a0f4da0)(0x2cc03e1bbb8,0,0x2cc08fe1478,0xffffffff,uVar1);
  uVar2 = (undefined4)((ulonglong)uVar1 >> 0x20);
  (*(code *)0x7ff63a0f51b0)(0x2cc03e1bbb8,0);
  (*(code *)0x7ff63a0f4da0)(0x2cc03e1bbb8,0,0x2cc08fe1328,0xffffffff,CONCAT44(uVar2,0xffffffff));
  _DAT_2cc090d2410 = 0;
  (*(code *)0x7ff63a0f4da0)(0x2cc03e1bbb8,0,0x2cc08fe1288,0xffffffff,0xffffffff);
  DAT_2cc090d2420 = 0;
  if (_DAT_2cc090d240c != -1) {
    (*(code *)0x7ff63a0eee30)(0x2cc03e1bbb8);
  }
  (*(code *)0x7ff639d926a0)(0x2cc03e1bbb8,_DAT_2cc090d24b8,0x2cc03e76f40,0x2cc090cf178);
  (*(code *)0x7ff639d926a0)(0x2cc03e1bbb8,_DAT_2cc090d24c0,0x2cc03e76f40,0x2cc090cf188);
  return;
}



/* Address: 2cc08fd60a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd60a0(void)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  
  FUN_2cc08fc1aa0(&DAT_2cc090d2330);
  (*(code *)0x7ff63a0e62f0)(0x2cc03e1bbb8,_DAT_2cc090d2330);
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,_DAT_2cc090d22c0,0x2cc03e09be0);
  _DAT_2cc090d22c8 = 0x2cc08fdee90;
  (*(code *)0x7ff63a0e62f0)(0x2cc03e1bbb8,_DAT_2cc090d22c0);
  FUN_2cc08fc0000(0x2cc090d2208);
  FUN_2cc08fc0000(0x2cc090d2144);
  FUN_2cc08fc0000(0x2cc090d2084);
  FUN_2cc08fc0000(0x2cc090d2034);
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,_DAT_2cc090d2000,0x2cc03e09be0);
  _DAT_2cc090d2008 = 0x2cc08fdee90;
  (*(code *)0x7ff63a0e62f0)(0x2cc03e1bbb8,_DAT_2cc090d2000);
  lVar3 = -0x90;
  do {
    if ((((*(int *)(lVar3 + 0x2cc090d2750) != 0) &&
         (lVar2 = *(longlong *)(lVar3 + 0x2cc090d2754), lVar2 != 0)) &&
        ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
      piVar1 = (int *)(lVar2 + -8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(code *)0x7ff63a101200)(0x2cc03e1bbb8);
      }
    }
    *(undefined8 *)(lVar3 + 0x2cc090d2754) = 0;
    *(undefined4 *)(lVar3 + 0x2cc090d2750) = 0;
    lVar3 = lVar3 + 0xc;
  } while (lVar3 != 0);
  if (DAT_2cc090d2660 == '\x01') {
    FUN_2cc08fc0800(0x2cc090d25e0);
  }
  if (DAT_2cc090d25d0 == '\x01') {
    FUN_2cc08fc0800(0x2cc090d2550);
  }
  (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,0x2cc090d2440);
  FUN_2cc08fc0000(0x2cc090d23f8);
  return;
}



/* Address: 2cc08fd6290 */

double FUN_2cc08fd6290(longlong param_1,int param_2,int param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  double dVar6;
  
  dVar6 = 0.0;
  if (param_2 < param_3 + param_2) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 8);
    uVar2 = (ulonglong)param_2;
    uVar4 = 0;
    if (uVar2 <= uVar5) {
      uVar4 = uVar5 - uVar2;
    }
    uVar5 = ~uVar2 + uVar5;
    do {
      if (uVar4 <= param_3 - 1) {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x65000e000101f6);
        goto LAB_2cc08fd6329;
      }
      uVar3 = uVar5;
      if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
        uVar3 = uVar2;
      }
      uVar2 = uVar2 + 1;
      uVar5 = uVar5 - 1;
      dVar6 = dVar6 + *(double *)(*(longlong *)(param_1 + 0x1c) + uVar3 * 8);
    } while ((longlong)(param_3 + param_2) != uVar2);
  }
  if (param_3 != 0) {
    return dVar6 / (double)param_3;
  }
LAB_2cc08fd6329:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x71000e000101f7);
  pcVar1 = (code *)swi(3);
  dVar6 = (double)(*pcVar1)();
  return dVar6;
}



/* Address: 2cc08fd6350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fd6350(longlong param_1)

{
  double dVar1;
  code *pcVar2;
  double *pdVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  ulonglong uVar19;
  uint uVar20;
  longlong lVar21;
  longlong lVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  longlong lVar25;
  longlong lVar26;
  longlong lVar27;
  longlong lVar28;
  uint uVar29;
  ulonglong unaff_R14;
  double dVar30;
  undefined8 uVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  undefined2 local_2a8;
  ushort local_2a6;
  undefined4 local_2a4;
  ulonglong local_2a0;
  undefined8 local_298;
  undefined4 local_290;
  undefined4 uStack_28c;
  undefined4 local_288;
  undefined4 uStack_284;
  undefined8 local_280;
  undefined4 local_278;
  ulonglong local_270;
  ulonglong local_268;
  undefined8 local_260;
  undefined4 local_258;
  undefined4 uStack_254;
  undefined4 local_250;
  undefined4 uStack_24c;
  undefined8 local_248;
  undefined4 local_240;
  longlong local_238;
  double local_230;
  longlong local_228;
  longlong local_220;
  longlong local_218;
  longlong local_210;
  longlong local_208;
  longlong local_200;
  longlong local_1f8;
  longlong local_1f0;
  longlong local_1e8;
  longlong local_1e0;
  longlong local_1d8;
  longlong local_1d0;
  longlong local_1c8;
  longlong local_1c0;
  longlong local_1b8;
  longlong local_1b0;
  longlong local_1a8;
  longlong local_1a0;
  longlong local_198;
  ulonglong local_190;
  ulonglong local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined8 local_168;
  undefined4 local_160;
  ulonglong local_158;
  ulonglong local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined4 local_128;
  ulonglong local_120;
  ulonglong local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined4 local_f0;
  
  local_2a8 = _DAT_2cc05fa0efa;
  local_2a4 = 0x3c;
  local_2a0 = 0;
  local_298 = 0;
  local_290 = 0;
  uStack_28c = 0;
  local_288 = 0;
  uStack_284 = 0;
  local_280 = 0;
  local_278 = 0;
  local_2a6 = 0x11;
  iVar10 = FUN_2cc08fc07c0(0x4001,300,&local_2a8);
  if (iVar10 < 300) {
    uVar15 = 0;
    goto LAB_2cc08fd7c18;
  }
  lVar21 = 0;
  local_270 = 0x800010058;
  local_120 = 0x800010058;
  local_158 = 0x800010058;
  local_190 = 0x800010058;
  local_268 = 0;
  local_260 = 0;
  local_258 = 0;
  uStack_254 = 0;
  local_250 = 0;
  uStack_24c = 0;
  local_248 = 0;
  local_240 = 0;
  local_118 = 0;
  local_110 = 0;
  local_108 = 0;
  uStack_104 = 0;
  local_100 = 0;
  uStack_fc = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_128 = 0;
  local_130 = 0;
  local_138 = 0;
  uStack_134 = 0;
  local_140 = 0;
  uStack_13c = 0;
  local_148 = 0;
  local_150 = 0;
  local_160 = 0;
  local_168 = 0;
  local_170 = 0;
  uStack_16c = 0;
  local_178 = 0;
  uStack_174 = 0;
  local_180 = 0;
  local_188 = 0;
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_270,300,0);
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_120,300,0);
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_158,300,0);
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,&local_190,300,0);
  uVar8 = local_120;
  uVar6 = local_158;
  uVar4 = local_190;
  uVar15 = local_270;
  lVar11 = -1;
  do {
    uVar20 = (uint)lVar21;
    if ((uint)local_2a0 <= uVar20) {
LAB_2cc08fd7d77:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2a0018000101f6);
      goto LAB_2cc08fd7d97;
    }
    uVar29 = (uint)local_268;
    unaff_R14 = local_268 & 0xffffffff;
    if ((uint)local_268 <= uVar20) {
LAB_2cc08fd7d57:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x250018000101f6);
      goto LAB_2cc08fd7d77;
    }
    pdVar3 = (double *)CONCAT44(local_250,uStack_254);
    lVar16 = (local_2a0 & 0xffffffff) + lVar11;
    if ((local_2a6 & 0x10) == 0) {
      lVar16 = lVar21;
    }
    lVar17 = lVar11 + unaff_R14;
    if ((local_270 & 0x100000) == 0) {
      lVar17 = lVar21;
    }
    pdVar3[lVar17] = *(double *)(CONCAT44(local_288,uStack_28c) + 0x20 + lVar16 * 0x3c);
    if ((uint)local_2a0 <= uVar20) {
LAB_2cc08fd7d37:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3b0018000101f6);
      goto LAB_2cc08fd7d57;
    }
    uVar9 = (uint)local_118;
    uVar23 = local_118 & 0xffffffff;
    if ((uint)local_118 <= uVar20) {
LAB_2cc08fd7d17:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x360018000101f6);
      goto LAB_2cc08fd7d37;
    }
    lVar16 = (local_2a0 & 0xffffffff) + lVar11;
    if ((local_2a6 & 0x10) == 0) {
      lVar16 = lVar21;
    }
    lVar17 = CONCAT44(local_100,uStack_104);
    lVar25 = lVar11 + uVar23;
    if ((local_120 & 0x100000) == 0) {
      lVar25 = lVar21;
    }
    *(undefined8 *)(lVar17 + lVar25 * 8) =
         *(undefined8 *)(CONCAT44(local_288,uStack_28c) + 8 + lVar16 * 0x3c);
    if ((uint)local_2a0 <= uVar20) {
LAB_2cc08fd7cf7:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x4b0018000101f6);
      goto LAB_2cc08fd7d17;
    }
    uVar7 = (uint)local_150;
    uVar19 = local_150 & 0xffffffff;
    local_238 = lVar17;
    if ((uint)local_150 <= uVar20) {
LAB_2cc08fd7cd7:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x460018000101f6);
      goto LAB_2cc08fd7cf7;
    }
    lVar16 = CONCAT44(local_138,uStack_13c);
    lVar17 = (local_2a0 & 0xffffffff) + lVar11;
    if ((local_2a6 & 0x10) == 0) {
      lVar17 = lVar21;
    }
    lVar25 = lVar11 + uVar19;
    if ((local_158 & 0x100000) == 0) {
      lVar25 = lVar21;
    }
    *(undefined8 *)(lVar16 + lVar25 * 8) =
         *(undefined8 *)(CONCAT44(local_288,uStack_28c) + 0x10 + lVar17 * 0x3c);
    if ((uint)local_2a0 <= uVar20) {
LAB_2cc08fd7cb7:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x5b0018000101f6);
      goto LAB_2cc08fd7cd7;
    }
    uVar5 = (uint)local_188;
    uVar24 = local_188 & 0xffffffff;
    if ((uint)local_188 <= uVar20) {
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x560018000101f6);
      goto LAB_2cc08fd7cb7;
    }
    lVar17 = CONCAT44(local_170,uStack_174);
    lVar25 = (local_2a0 & 0xffffffff) + lVar11;
    if ((local_2a6 & 0x10) == 0) {
      lVar25 = lVar21;
    }
    lVar14 = lVar11 + uVar24;
    if ((local_190 & 0x100000) == 0) {
      lVar14 = lVar21;
    }
    lVar21 = lVar21 + 1;
    lVar11 = lVar11 + -1;
    *(undefined8 *)(lVar17 + lVar14 * 8) =
         *(undefined8 *)(CONCAT44(local_288,uStack_28c) + 0x18 + lVar25 * 0x3c);
  } while ((int)lVar21 != 300);
  lVar11 = 0;
  if ((local_270 & 0x100000) != 0) {
    lVar11 = unaff_R14 - 1;
  }
  dVar1 = pdVar3[lVar11];
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,param_1,0x14,0);
  dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x1e);
  if ((dVar1 != 0.0) || (NAN(dVar1))) {
    if (uVar29 < 0x1e) goto LAB_2cc08fd7edd;
    if ((uVar15 & 0x100000) == 0) {
      dVar32 = pdVar3[0x1c];
      dVar34 = (pdVar3[0x1b] - dVar30) * (pdVar3[0x1b] - dVar30) +
               (pdVar3[0x1a] - dVar30) * (pdVar3[0x1a] - dVar30) +
               (pdVar3[0x19] - dVar30) * (pdVar3[0x19] - dVar30) +
               (pdVar3[0x18] - dVar30) * (pdVar3[0x18] - dVar30) +
               (pdVar3[0x17] - dVar30) * (pdVar3[0x17] - dVar30) +
               (pdVar3[0x16] - dVar30) * (pdVar3[0x16] - dVar30) +
               (pdVar3[0x15] - dVar30) * (pdVar3[0x15] - dVar30) +
               (pdVar3[0x14] - dVar30) * (pdVar3[0x14] - dVar30) +
               (pdVar3[0x13] - dVar30) * (pdVar3[0x13] - dVar30) +
               (pdVar3[0x12] - dVar30) * (pdVar3[0x12] - dVar30) +
               (pdVar3[0x11] - dVar30) * (pdVar3[0x11] - dVar30) +
               (pdVar3[0x10] - dVar30) * (pdVar3[0x10] - dVar30) +
               (pdVar3[0xf] - dVar30) * (pdVar3[0xf] - dVar30) +
               (pdVar3[0xe] - dVar30) * (pdVar3[0xe] - dVar30) +
               (pdVar3[0xd] - dVar30) * (pdVar3[0xd] - dVar30) +
               (pdVar3[0xc] - dVar30) * (pdVar3[0xc] - dVar30) +
               (pdVar3[0xb] - dVar30) * (pdVar3[0xb] - dVar30) +
               (pdVar3[10] - dVar30) * (pdVar3[10] - dVar30) +
               (pdVar3[9] - dVar30) * (pdVar3[9] - dVar30) +
               (pdVar3[8] - dVar30) * (pdVar3[8] - dVar30) +
               (pdVar3[7] - dVar30) * (pdVar3[7] - dVar30) +
               (pdVar3[6] - dVar30) * (pdVar3[6] - dVar30) +
               (pdVar3[5] - dVar30) * (pdVar3[5] - dVar30) +
               (pdVar3[4] - dVar30) * (pdVar3[4] - dVar30) +
               (pdVar3[3] - dVar30) * (pdVar3[3] - dVar30) +
               (pdVar3[2] - dVar30) * (pdVar3[2] - dVar30) +
               (pdVar3[1] - dVar30) * (pdVar3[1] - dVar30) + (*pdVar3 - dVar30) * (*pdVar3 - dVar30)
      ;
      dVar33 = pdVar3[0x1d];
    }
    else {
      dVar32 = pdVar3[unaff_R14 - 0x1d];
      dVar34 = (pdVar3[unaff_R14 - 0x1c] - dVar30) * (pdVar3[unaff_R14 - 0x1c] - dVar30) +
               (pdVar3[unaff_R14 - 0x1b] - dVar30) * (pdVar3[unaff_R14 - 0x1b] - dVar30) +
               (pdVar3[unaff_R14 - 0x1a] - dVar30) * (pdVar3[unaff_R14 - 0x1a] - dVar30) +
               (pdVar3[unaff_R14 - 0x19] - dVar30) * (pdVar3[unaff_R14 - 0x19] - dVar30) +
               (pdVar3[unaff_R14 - 0x18] - dVar30) * (pdVar3[unaff_R14 - 0x18] - dVar30) +
               (pdVar3[unaff_R14 - 0x17] - dVar30) * (pdVar3[unaff_R14 - 0x17] - dVar30) +
               (pdVar3[unaff_R14 - 0x16] - dVar30) * (pdVar3[unaff_R14 - 0x16] - dVar30) +
               (pdVar3[unaff_R14 - 0x15] - dVar30) * (pdVar3[unaff_R14 - 0x15] - dVar30) +
               (pdVar3[unaff_R14 - 0x14] - dVar30) * (pdVar3[unaff_R14 - 0x14] - dVar30) +
               (pdVar3[unaff_R14 - 0x13] - dVar30) * (pdVar3[unaff_R14 - 0x13] - dVar30) +
               (pdVar3[unaff_R14 - 0x12] - dVar30) * (pdVar3[unaff_R14 - 0x12] - dVar30) +
               (pdVar3[unaff_R14 - 0x11] - dVar30) * (pdVar3[unaff_R14 - 0x11] - dVar30) +
               (pdVar3[unaff_R14 - 0x10] - dVar30) * (pdVar3[unaff_R14 - 0x10] - dVar30) +
               (pdVar3[unaff_R14 - 0xf] - dVar30) * (pdVar3[unaff_R14 - 0xf] - dVar30) +
               (pdVar3[unaff_R14 - 0xe] - dVar30) * (pdVar3[unaff_R14 - 0xe] - dVar30) +
               (pdVar3[unaff_R14 - 0xd] - dVar30) * (pdVar3[unaff_R14 - 0xd] - dVar30) +
               (pdVar3[unaff_R14 - 0xc] - dVar30) * (pdVar3[unaff_R14 - 0xc] - dVar30) +
               (pdVar3[unaff_R14 - 0xb] - dVar30) * (pdVar3[unaff_R14 - 0xb] - dVar30) +
               (pdVar3[unaff_R14 - 10] - dVar30) * (pdVar3[unaff_R14 - 10] - dVar30) +
               (pdVar3[unaff_R14 - 9] - dVar30) * (pdVar3[unaff_R14 - 9] - dVar30) +
               (pdVar3[unaff_R14 - 8] - dVar30) * (pdVar3[unaff_R14 - 8] - dVar30) +
               (pdVar3[unaff_R14 - 7] - dVar30) * (pdVar3[unaff_R14 - 7] - dVar30) +
               (pdVar3[unaff_R14 - 6] - dVar30) * (pdVar3[unaff_R14 - 6] - dVar30) +
               (pdVar3[unaff_R14 - 5] - dVar30) * (pdVar3[unaff_R14 - 5] - dVar30) +
               (pdVar3[unaff_R14 - 4] - dVar30) * (pdVar3[unaff_R14 - 4] - dVar30) +
               (pdVar3[unaff_R14 - 3] - dVar30) * (pdVar3[unaff_R14 - 3] - dVar30) +
               (pdVar3[unaff_R14 - 2] - dVar30) * (pdVar3[unaff_R14 - 2] - dVar30) +
               (pdVar3[unaff_R14 - 1] - dVar30) * (pdVar3[unaff_R14 - 1] - dVar30);
      dVar33 = pdVar3[unaff_R14 - 0x1e];
    }
    if ((ulonglong)*(uint *)(param_1 + 8) == 0) {
LAB_2cc08fd7e57:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x22001e000101f6);
LAB_2cc08fd7e77:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2b0021000101f7);
LAB_2cc08fd7e97:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x220021000101f6);
      goto LAB_2cc08fd7eb7;
    }
    lVar21 = 0;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 1;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) =
         SQRT(((dVar33 - dVar30) * (dVar33 - dVar30) +
              (dVar32 - dVar30) * (dVar32 - dVar30) + dVar34) / _DAT_2cc08fdeb40) / dVar1;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x5a);
    if (uVar29 < 0x5a) goto LAB_2cc08fd7edd;
    if ((uVar15 & 0x100000) == 0) {
      dVar32 = 0.0;
      lVar21 = -0x2d0;
      do {
        lVar25 = lVar21 + 0x2d0;
        lVar21 = lVar21 + 8;
        dVar33 = *(double *)((longlong)pdVar3 + lVar25) - dVar30;
        dVar32 = dVar32 + dVar33 * dVar33;
      } while (lVar21 != 0);
    }
    else {
      dVar32 = 0.0;
      lVar21 = 0x5a;
      do {
        lVar25 = lVar21 + -0x5b;
        lVar21 = lVar21 + -1;
        dVar32 = dVar32 + (pdVar3[unaff_R14 + lVar25] - dVar30) *
                          (pdVar3[unaff_R14 + lVar25] - dVar30);
      } while (lVar21 != 0);
    }
    if ((ulonglong)*(uint *)(param_1 + 8) < 2) goto LAB_2cc08fd7e57;
    lVar21 = 1;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 2;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) =
         SQRT(dVar32 / _DAT_2cc08fdeb48) / dVar1;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0xb4);
    if (uVar29 < 0xb4) goto LAB_2cc08fd7edd;
    if ((uVar15 & 0x100000) == 0) {
      dVar32 = 0.0;
      lVar21 = -0x5a0;
      do {
        lVar25 = lVar21 + 0x5a0;
        lVar21 = lVar21 + 8;
        dVar33 = *(double *)((longlong)pdVar3 + lVar25) - dVar30;
        dVar32 = dVar32 + dVar33 * dVar33;
      } while (lVar21 != 0);
    }
    else {
      dVar32 = 0.0;
      lVar21 = 0xb4;
      do {
        lVar25 = lVar21 + -0xb5;
        lVar21 = lVar21 + -1;
        dVar32 = dVar32 + (pdVar3[unaff_R14 + lVar25] - dVar30) *
                          (pdVar3[unaff_R14 + lVar25] - dVar30);
      } while (lVar21 != 0);
    }
    if ((ulonglong)*(uint *)(param_1 + 8) < 3) goto LAB_2cc08fd7e57;
    lVar21 = 2;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 3;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) =
         SQRT(dVar32 / _DAT_2cc08fdeb50) / dVar1;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x10e);
    if (uVar29 < 0x10e) goto LAB_2cc08fd7edd;
    if ((uVar15 & 0x100000) == 0) {
      dVar32 = 0.0;
      lVar21 = -0x870;
      do {
        lVar25 = lVar21 + 0x870;
        lVar21 = lVar21 + 8;
        dVar33 = *(double *)((longlong)pdVar3 + lVar25) - dVar30;
        dVar32 = dVar32 + dVar33 * dVar33;
      } while (lVar21 != 0);
    }
    else {
      dVar32 = 0.0;
      lVar21 = 0x10e;
      do {
        lVar25 = lVar21 + -0x10f;
        lVar21 = lVar21 + -1;
        dVar32 = dVar32 + (pdVar3[unaff_R14 + lVar25] - dVar30) *
                          (pdVar3[unaff_R14 + lVar25] - dVar30);
      } while (lVar21 != 0);
    }
    if ((ulonglong)*(uint *)(param_1 + 8) < 4) goto LAB_2cc08fd7e57;
    lVar21 = 3;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 4;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) =
         SQRT(dVar32 / _DAT_2cc08fdeb58) / dVar1;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x14);
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e77;
    if ((ulonglong)*(uint *)(param_1 + 8) < 5) goto LAB_2cc08fd7e97;
    lVar21 = 4;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 5;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = dVar1 / dVar30 + _DAT_2cc08fdeb60;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x32);
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e77;
    if ((ulonglong)*(uint *)(param_1 + 8) < 6) goto LAB_2cc08fd7e97;
    lVar21 = 5;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 6;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = dVar1 / dVar30 + _DAT_2cc08fdeb60;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,100);
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e77;
    if ((ulonglong)*(uint *)(param_1 + 8) < 7) goto LAB_2cc08fd7e97;
    lVar21 = 6;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 7;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = dVar1 / dVar30 + _DAT_2cc08fdeb60;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,200);
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e77;
    if ((ulonglong)*(uint *)(param_1 + 8) < 8) goto LAB_2cc08fd7e97;
    lVar21 = 7;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 8;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = dVar1 / dVar30 + _DAT_2cc08fdeb60;
    dVar30 = (double)FUN_2cc08fd6290(&local_270,0,0x32);
    dVar32 = (double)FUN_2cc08fd6290(&local_270,5,0x32);
    if ((ulonglong)*(uint *)(param_1 + 8) < 9) goto LAB_2cc08fd7efd;
    lVar21 = 8;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)*(uint *)(param_1 + 8) - 9;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = (dVar30 - dVar32) / dVar1;
    lVar21 = 3;
    if ((uVar15 & 0x100000) != 0) {
      lVar21 = unaff_R14 - 4;
    }
    dVar30 = pdVar3[lVar21];
    if ((dVar30 == 0.0) && (!NAN(dVar30))) {
LAB_2cc08fd7e17:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x330026000101f7);
LAB_2cc08fd7e37:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x220026000101f6);
      goto LAB_2cc08fd7e57;
    }
    uVar20 = *(uint *)(param_1 + 8);
    if ((ulonglong)uVar20 < 10) goto LAB_2cc08fd7e37;
    uVar31 = (*(code *)0x7ff63a3dae50)(dVar1 / dVar30);
    lVar21 = 9;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)uVar20 - 10;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = uVar31;
    lVar21 = 6;
    if ((uVar15 & 0x100000) != 0) {
      lVar21 = unaff_R14 - 7;
    }
    dVar30 = pdVar3[lVar21];
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e17;
    uVar20 = *(uint *)(param_1 + 8);
    if ((ulonglong)uVar20 < 0xb) goto LAB_2cc08fd7e37;
    uVar31 = (*(code *)0x7ff63a3dae50)(dVar1 / dVar30);
    lVar21 = 10;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)uVar20 - 0xb;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = uVar31;
    lVar21 = 0xc;
    if ((uVar15 & 0x100000) != 0) {
      lVar21 = unaff_R14 - 0xd;
    }
    dVar30 = pdVar3[lVar21];
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e17;
    uVar20 = *(uint *)(param_1 + 8);
    if ((ulonglong)uVar20 < 0xc) goto LAB_2cc08fd7e37;
    uVar31 = (*(code *)0x7ff63a3dae50)(dVar1 / dVar30);
    lVar21 = 0xb;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)uVar20 - 0xc;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = uVar31;
    lVar21 = 0x18;
    if ((uVar15 & 0x100000) != 0) {
      lVar21 = unaff_R14 - 0x19;
    }
    dVar30 = pdVar3[lVar21];
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e17;
    uVar20 = *(uint *)(param_1 + 8);
    if ((ulonglong)uVar20 < 0xd) goto LAB_2cc08fd7e37;
    uVar31 = (*(code *)0x7ff63a3dae50)(dVar1 / dVar30);
    lVar21 = 0xc;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)uVar20 - 0xd;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = uVar31;
    lVar21 = 0x30;
    if ((uVar15 & 0x100000) != 0) {
      lVar21 = unaff_R14 - 0x31;
    }
    dVar30 = pdVar3[lVar21];
    if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd7e17;
    uVar20 = *(uint *)(param_1 + 8);
    if ((ulonglong)uVar20 < 0xe) goto LAB_2cc08fd7e37;
    uVar31 = (*(code *)0x7ff63a3dae50)(dVar1 / dVar30);
    dVar30 = 0.0;
    lVar21 = 0xd;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar21 = (ulonglong)uVar20 - 0xe;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar21 * 8) = uVar31;
    local_198 = uVar19 - 1;
    if ((uVar6 & 0x100000) == 0) {
      local_198 = 0;
    }
    lVar21 = uVar24 - 1;
    if ((uVar4 & 0x100000) == 0) {
      lVar21 = 0;
    }
    dVar32 = *(double *)(lVar16 + local_198 * 8) - *(double *)(lVar17 + lVar21 * 8);
    if (0.0 < dVar32) {
      if ((dVar32 == 0.0) && (!NAN(dVar32))) goto LAB_2cc08fd7f9d;
      if ((ulonglong)*(uint *)(param_1 + 8) < 0xf) goto LAB_2cc08fd7fdd;
      lVar25 = 0;
      if ((uVar8 & 0x100000) != 0) {
        lVar25 = uVar23 - 1;
      }
      lVar14 = 0xe;
      if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
        lVar14 = (ulonglong)*(uint *)(param_1 + 8) - 0xf;
      }
      *(double *)(*(longlong *)(param_1 + 0x1c) + lVar14 * 8) =
           (pdVar3[lVar11] - *(double *)(local_238 + lVar25 * 8)) / dVar32;
      if ((ulonglong)*(uint *)(param_1 + 8) < 0x10) goto LAB_2cc08fd801d;
      dVar30 = *(double *)(local_238 + lVar25 * 8);
      if (dVar30 <= pdVar3[lVar11]) {
        dVar30 = pdVar3[lVar11];
      }
      lVar14 = 0xf;
      if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
        lVar14 = (ulonglong)*(uint *)(param_1 + 8) - 0x10;
      }
      *(double *)(*(longlong *)(param_1 + 0x1c) + lVar14 * 8) =
           (*(double *)(lVar16 + local_198 * 8) - dVar30) / dVar32;
      uVar20 = *(uint *)(param_1 + 8);
      if (0x10 < uVar20) {
        dVar30 = *(double *)(local_238 + lVar25 * 8);
        if (pdVar3[lVar11] <= dVar30) {
          dVar30 = pdVar3[lVar11];
        }
        dVar30 = (dVar30 - *(double *)(lVar17 + lVar21 * 8)) / dVar32;
        goto LAB_2cc08fd7565;
      }
      goto LAB_2cc08fd805d;
    }
    if ((ulonglong)*(uint *)(param_1 + 8) < 0xf) goto LAB_2cc08fd7fbd;
    lVar11 = 0xe;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar11 = (ulonglong)*(uint *)(param_1 + 8) - 0xf;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar11 * 8) = 0;
    if ((ulonglong)*(uint *)(param_1 + 8) < 0x10) goto LAB_2cc08fd7ffd;
    lVar11 = 0xf;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar11 = (ulonglong)*(uint *)(param_1 + 8) - 0x10;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x1c) + lVar11 * 8) = 0;
    uVar20 = *(uint *)(param_1 + 8);
    if (uVar20 < 0x11) goto LAB_2cc08fd803d;
LAB_2cc08fd7565:
    lVar11 = 0x10;
    if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
      lVar11 = (ulonglong)uVar20 - 0x11;
    }
    *(double *)(*(longlong *)(param_1 + 0x1c) + lVar11 * 8) = dVar30;
    if (uVar7 < 2) {
LAB_2cc08fd7dd7:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x30002e000101f6);
LAB_2cc08fd7df7:
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x35002e000101f6);
      goto LAB_2cc08fd7e17;
    }
    if (uVar5 < 2) goto LAB_2cc08fd7df7;
    lVar11 = uVar19 - 2;
    lVar25 = uVar24 - 2;
    local_1a0 = lVar11;
    if ((uVar6 & 0x100000) == 0) {
      local_1a0 = 1;
    }
    lVar14 = 1;
    if ((uVar4 & 0x100000) != 0) {
      lVar14 = lVar25;
    }
    if (uVar19 == 2) goto LAB_2cc08fd7dd7;
    if (uVar5 == 2) goto LAB_2cc08fd7df7;
    local_1a8 = uVar19 - 3;
    local_1b0 = uVar24 - 3;
    if ((uVar6 & 0x100000) == 0) {
      local_1a8 = 2;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_1b0 = 2;
    }
    if (uVar7 < 4) goto LAB_2cc08fd7dd7;
    if (uVar5 < 4) goto LAB_2cc08fd7df7;
    local_1b8 = uVar19 - 4;
    local_1c0 = uVar24 - 4;
    if ((uVar6 & 0x100000) == 0) {
      local_1b8 = 3;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_1c0 = 3;
    }
    if (uVar19 == 4) goto LAB_2cc08fd7dd7;
    if (uVar5 == 4) goto LAB_2cc08fd7df7;
    local_1c8 = uVar19 - 5;
    local_1d0 = uVar24 - 5;
    if ((uVar6 & 0x100000) == 0) {
      local_1c8 = 4;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_1d0 = 4;
    }
    if (uVar7 < 6) goto LAB_2cc08fd7dd7;
    if (uVar5 < 6) goto LAB_2cc08fd7df7;
    local_1d8 = uVar19 - 6;
    local_1e0 = uVar24 - 6;
    if ((uVar6 & 0x100000) == 0) {
      local_1d8 = 5;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_1e0 = 5;
    }
    if (uVar19 == 6) goto LAB_2cc08fd7dd7;
    if (uVar5 == 6) goto LAB_2cc08fd7df7;
    local_1e8 = uVar19 - 7;
    local_1f0 = uVar24 - 7;
    if ((uVar6 & 0x100000) == 0) {
      local_1e8 = 6;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_1f0 = 6;
    }
    if (uVar7 < 8) goto LAB_2cc08fd7dd7;
    if (uVar5 < 8) goto LAB_2cc08fd7df7;
    local_1f8 = uVar19 - 8;
    local_200 = uVar24 - 8;
    if ((uVar6 & 0x100000) == 0) {
      local_1f8 = 7;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_200 = 7;
    }
    if (uVar19 == 8) goto LAB_2cc08fd7dd7;
    if (uVar5 == 8) goto LAB_2cc08fd7df7;
    local_208 = uVar19 - 9;
    local_210 = uVar24 - 9;
    if ((uVar6 & 0x100000) == 0) {
      local_208 = 8;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_210 = 8;
    }
    if (uVar7 < 10) goto LAB_2cc08fd7dd7;
    if (uVar5 < 10) goto LAB_2cc08fd7df7;
    local_218 = uVar19 - 10;
    local_220 = uVar24 - 10;
    if ((uVar6 & 0x100000) == 0) {
      local_218 = 9;
    }
    if ((uVar4 & 0x100000) == 0) {
      local_220 = 9;
    }
    if (uVar19 == 10) goto LAB_2cc08fd7dd7;
    if (uVar5 == 10) goto LAB_2cc08fd7df7;
    local_228 = uVar19 - 0xb;
    lVar26 = uVar24 - 0xb;
    if ((uVar6 & 0x100000) == 0) {
      local_228 = 10;
    }
    if ((uVar4 & 0x100000) == 0) {
      lVar26 = 10;
    }
    if (uVar7 < 0xc) goto LAB_2cc08fd7dd7;
    if (uVar5 < 0xc) goto LAB_2cc08fd7df7;
    lVar18 = uVar19 - 0xc;
    lVar27 = uVar24 - 0xc;
    if ((uVar6 & 0x100000) == 0) {
      lVar18 = 0xb;
    }
    if ((uVar4 & 0x100000) == 0) {
      lVar27 = 0xb;
    }
    if (uVar19 == 0xc) goto LAB_2cc08fd7dd7;
    if (uVar5 == 0xc) goto LAB_2cc08fd7df7;
    lVar22 = uVar19 - 0xd;
    lVar28 = uVar24 - 0xd;
    if ((uVar6 & 0x100000) == 0) {
      lVar22 = 0xc;
    }
    if ((uVar4 & 0x100000) == 0) {
      lVar28 = 0xc;
    }
    if (uVar7 < 0xe) goto LAB_2cc08fd7dd7;
    if (uVar5 < 0xe) goto LAB_2cc08fd7df7;
    lVar12 = uVar19 - 0xe;
    if ((uVar6 & 0x100000) == 0) {
      lVar12 = 0xd;
    }
    lVar13 = uVar24 - 0xe;
    if ((uVar4 & 0x100000) == 0) {
      lVar13 = 0xd;
    }
    dVar30 = ((*(double *)(lVar16 + lVar12 * 8) - *(double *)(lVar17 + lVar13 * 8)) +
             (*(double *)(lVar16 + lVar22 * 8) - *(double *)(lVar17 + lVar28 * 8)) +
             (*(double *)(lVar16 + lVar18 * 8) - *(double *)(lVar17 + lVar27 * 8)) +
             (*(double *)(lVar16 + local_228 * 8) - *(double *)(lVar17 + lVar26 * 8)) +
             (*(double *)(lVar16 + local_218 * 8) - *(double *)(lVar17 + local_220 * 8)) +
             (*(double *)(lVar16 + local_208 * 8) - *(double *)(lVar17 + local_210 * 8)) +
             (*(double *)(lVar16 + local_1f8 * 8) - *(double *)(lVar17 + local_200 * 8)) +
             (*(double *)(lVar16 + local_1e8 * 8) - *(double *)(lVar17 + local_1f0 * 8)) +
             (*(double *)(lVar16 + local_1d8 * 8) - *(double *)(lVar17 + local_1e0 * 8)) +
             (*(double *)(lVar16 + local_1c8 * 8) - *(double *)(lVar17 + local_1d0 * 8)) +
             (*(double *)(lVar16 + local_1b8 * 8) - *(double *)(lVar17 + local_1c0 * 8)) +
             (*(double *)(lVar16 + local_1a8 * 8) - *(double *)(lVar17 + local_1b0 * 8)) +
             (*(double *)(lVar16 + local_1a0 * 8) - *(double *)(lVar17 + lVar14 * 8)) +
             (*(double *)(lVar16 + local_198 * 8) - *(double *)(lVar17 + lVar21 * 8)) + 0.0) /
             _DAT_2cc08fdeb68;
    dVar33 = _DAT_2cc08fdeb70;
    local_230 = dVar1;
    if (dVar30 <= 0.0) {
LAB_2cc08fd7a6a:
      if ((ulonglong)*(uint *)(param_1 + 8) < 0x12) goto LAB_2cc08fd7f1d;
      lVar14 = 0x11;
      if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
        lVar14 = (ulonglong)*(uint *)(param_1 + 8) - 0x12;
      }
      *(double *)(*(longlong *)(param_1 + 0x1c) + lVar14 * 8) = dVar33;
      if (uVar9 < 2) goto LAB_2cc08fd7f3d;
      if ((ulonglong)*(uint *)(param_1 + 8) < 0x13) goto LAB_2cc08fd7f5d;
      unaff_R14 = unaff_R14 - 2;
      lVar14 = 1;
      if ((uVar15 & 0x100000) == 0) {
        unaff_R14 = 1;
      }
      lVar26 = uVar23 - 2;
      if ((uVar8 & 0x100000) == 0) {
        lVar26 = 1;
      }
      lVar18 = 0x12;
      if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
        lVar18 = (ulonglong)*(uint *)(param_1 + 8) - 0x13;
      }
      *(double *)(*(longlong *)(param_1 + 0x1c) + lVar18 * 8) =
           (pdVar3[unaff_R14] - *(double *)(local_238 + lVar26 * 8)) / dVar1;
      dVar30 = *(double *)(lVar16 + local_198 * 8);
      dVar32 = *(double *)(lVar17 + lVar21 * 8);
      iVar10 = 0x17;
      do {
        if (uVar7 <= (uint)lVar14) goto LAB_2cc08fd7db7;
        if (uVar5 <= (uint)lVar14) goto LAB_2cc08fd7d97;
        lVar21 = lVar11;
        if ((uVar6 & 0x100000) == 0) {
          lVar21 = lVar14;
        }
        dVar33 = *(double *)(lVar16 + lVar21 * 8);
        if (dVar30 <= dVar33) {
          dVar30 = dVar33;
        }
        lVar21 = lVar25;
        if ((uVar4 & 0x100000) == 0) {
          lVar21 = lVar14;
        }
        lVar14 = lVar14 + 1;
        lVar25 = lVar25 + -1;
        lVar11 = lVar11 + -1;
        iVar10 = iVar10 + -1;
        dVar33 = *(double *)(lVar17 + lVar21 * 8);
        if (dVar33 <= dVar32) {
          dVar32 = dVar33;
        }
      } while (iVar10 != 0);
      dVar33 = _DAT_2cc08fdeb78;
      if (dVar32 < dVar30) {
        dVar30 = dVar30 - dVar32;
        if ((dVar30 == 0.0) && (!NAN(dVar30))) goto LAB_2cc08fd809d;
        dVar33 = (dVar1 - dVar32) / dVar30;
      }
      if (0x13 < (ulonglong)*(uint *)(param_1 + 8)) {
        lVar11 = 0x13;
        if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
          lVar11 = (ulonglong)*(uint *)(param_1 + 8) - 0x14;
        }
        *(double *)(*(longlong *)(param_1 + 0x1c) + lVar11 * 8) = dVar33;
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_190);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_158);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_120);
        (*(code *)0x7ff63a0d9d20)(0x2cc03e1bbb8,&local_270);
        uVar15 = 0x2cc03e1bb01;
LAB_2cc08fd7c18:
        FUN_2cc08fc06f0(&local_2a8);
        return uVar15 & 0xffffffff;
      }
      goto LAB_2cc08fd7f7d;
    }
    if ((dVar30 != 0.0) || (NAN(dVar30))) {
      dVar33 = dVar32 / dVar30;
      goto LAB_2cc08fd7a6a;
    }
  }
  else {
LAB_2cc08fd7eb7:
    if (0x1d < uVar29) {
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x3e001e000101f7);
    }
LAB_2cc08fd7edd:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x6a000f000101f6);
LAB_2cc08fd7efd:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0023000101f6);
LAB_2cc08fd7f1d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd002f000101f6);
LAB_2cc08fd7f3d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1b0030000101f6);
LAB_2cc08fd7f5d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0030000101f6);
LAB_2cc08fd7f7d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0033000101f6);
LAB_2cc08fd7f9d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x22002a000101f7);
LAB_2cc08fd7fbd:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x16002d000101f6);
LAB_2cc08fd7fdd:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x10002a000101f6);
LAB_2cc08fd7ffd:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x27002d000101f6);
LAB_2cc08fd801d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x10002b000101f6);
LAB_2cc08fd803d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x38002d000101f6);
LAB_2cc08fd805d:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x10002c000101f6);
  }
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f002f000101f7);
LAB_2cc08fd809d:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x250033000101f7);
  pcVar2 = (code *)swi(3);
  uVar15 = (*pcVar2)();
  return uVar15;
LAB_2cc08fd7d97:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x590032000101f6);
LAB_2cc08fd7db7:
  uVar29 = (uint)unaff_R14;
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x440032000101f6);
  goto LAB_2cc08fd7dd7;
}



/* Address: 2cc08fd80c0 */

void FUN_2cc08fd80c0(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x2cc090d2828;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_2cc08fc04d0(&local_60,lVar10,0,0x2cc090cfb18);
  (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x02cc08fd81f7 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x2cc08fdeb80))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,*param_3,0x53,&local_88);
  FUN_2cc08fc04d0(&local_98,0x2cc08fe0dc0,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_2cc08fd885f;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_2cc08fd885f;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_2cc08fc0060(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f0561000301f9);
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
      if (uVar11 == uVar12) goto LAB_2cc08fd8a52;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_2cc08fd8a52:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_2cc08fd885f:
  FUN_2cc08fc04d0(param_1,&local_98,0,0x2cc090cfe18);
  FUN_2cc08fc04d0(&local_50,param_1,0,0x2cc090cfe28);
  FUN_2cc08fc0000(&local_60);
  FUN_2cc08fc04d0(0x2cc090d283c,&local_50,1,0x2cc090cfe38);
  FUN_2cc08fc0000(&local_50);
  FUN_2cc08fc0000(&local_88);
  FUN_2cc08fc0000(&local_98);
  FUN_2cc08fc0000(&local_78);
  return;
}



/* Address: 2cc08fd88e0 */

void FUN_2cc08fd88e0(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x2cc03e1bbb8,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_2cc08fc04d0(&stack0x00000060,0x2cc090d283c,1,0x2cc090cfbe8);
  (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,0xd8,2,0x590008,0x2cc08fe0650);
  FUN_2cc08fc04d0(&stack0x00000050,0x2cc090d283c,1,0x2cc090cfbf8);
  FUN_2cc08fc04d0(in_stack_00000048,&stack0x00000050,0,0x2cc090cfc08);
  FUN_2cc08fc04d0(&stack0x00000098,in_stack_00000048,0,0x2cc090cfe28);
  FUN_2cc08fc0000(&stack0x00000088);
  FUN_2cc08fc04d0(0x2cc090d283c,&stack0x00000098,1,0x2cc090cfe38);
  FUN_2cc08fc0000(&stack0x00000098);
  FUN_2cc08fc0000(&stack0x00000060);
  FUN_2cc08fc0000(&stack0x00000050);
  FUN_2cc08fc0000(&stack0x00000070);
  return;
}



/* Address: 2cc08fd8aa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2cc08fd8aa0(longlong param_1)

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
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x2cc03e1bbb8,param_1,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  iVar1 = _DAT_2cc090d2074;
  if (uVar2 < 2) goto LAB_2cc08fd8e89;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2cc03e1bbb8,param_1,0x32);
  if (uVar2 == 2) {
    iVar1 = _DAT_2cc090d2074;
    if (_DAT_2cc090d2020 == 5) goto LAB_2cc08fd8e89;
    if ((uVar3 & 1) != 0) {
      _DAT_2cc090d22a5 = 0;
      _DAT_2cc090d2074 = 0;
      iVar1 = _DAT_2cc090d2074;
      goto LAB_2cc08fd8e89;
    }
    if ((uVar3 & 2) != 0) {
      _DAT_2cc090d22a5 = 1;
      _DAT_2cc090d2074 = 1;
      iVar1 = _DAT_2cc090d2074;
      goto LAB_2cc08fd8e89;
    }
LAB_2cc08fd8de6:
    _DAT_2cc090d2110 = 0x272e;
  }
  else {
    if (_DAT_2cc090d22a5 == 2) {
LAB_2cc08fd8e61:
      _DAT_2cc090d2074 = 2;
      iVar1 = _DAT_2cc090d2074;
      goto LAB_2cc08fd8e89;
    }
    if (_DAT_2cc090d22a5 == 1) {
      if (_DAT_2cc090d2020 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x2cc090d2828;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_2cc08fc04d0(&local_40,lVar5,0,0x2cc090cfe48);
        (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_2cc090d2078 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02cc08fd8cc9 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_2cc090d2078 * 8 + 0x2cc08fdeca8))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,2,1,0x590008,0x2cc08fe0e40);
        FUN_2cc08fc0000(&local_40);
        _DAT_2cc090d2078 = 1;
        if (_DAT_2cc090d2070 - 2U < 4) goto LAB_2cc08fd8e61;
      }
      uVar3 = uVar3 & 2;
joined_r0x02cc08fd8de0:
      iVar1 = _DAT_2cc090d22a5;
      if (uVar3 != 0) goto LAB_2cc08fd8e89;
      goto LAB_2cc08fd8de6;
    }
    if (_DAT_2cc090d22a5 == 0) {
      if (_DAT_2cc090d2020 == 5) {
        local_40 = 0;
        local_38 = 0;
        lVar5 = 0x2cc090d2828;
        if (*(longlong *)(param_1 + 4) != 0) {
          lVar5 = param_1;
        }
        FUN_2cc08fc04d0(&local_40,lVar5,0,0x2cc090cfe48);
        (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_40,0x31,local_30);
        if ((ulonglong)_DAT_2cc090d2078 < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02cc08fd8c0e */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)_DAT_2cc090d2078 * 8 + 0x2cc08fdecc8))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,2,1,0x590008,0x2cc08fe0e40);
        FUN_2cc08fc0000(&local_40);
        _DAT_2cc090d2078 = 1;
        if (_DAT_2cc090d2070 - 2U < 4) goto LAB_2cc08fd8e61;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x02cc08fd8de0;
    }
    _DAT_2cc090d2110 = 0x271b;
  }
  uVar4 = 0;
  iVar1 = _DAT_2cc090d2074;
LAB_2cc08fd8e89:
  _DAT_2cc090d2074 = iVar1;
  return uVar4 & 0xffffffff;
}



/* Address: 2cc08fd8ea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2cc08fd8ea0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_84 = 0;
  if (_DAT_2cc090d2814 == 0) {
    cVar1 = (*(code *)0x7ff63a107ee0)(0x2cc03e1bbb8,param_1);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      _DAT_2cc090d2020 = 0;
      _DAT_2cc090d2024 = 0;
      uRam000002cc090d2028 = 0;
      uRam000002cc090d202c = 0;
      _DAT_2cc090d2030 = 0;
      FUN_2cc08fc0000(0x2cc090d2034);
      _DAT_2cc090d2050 = 0;
      _DAT_2cc090d2058 = 0;
      _DAT_2cc090d2070 = 0;
      _DAT_2cc090d2078 = 0;
      _DAT_2cc090d2060 = 0;
      _DAT_2cc090d2068 = 0;
      _DAT_2cc090d2040 = 0;
      _DAT_2cc090d2048 = 0;
      _DAT_2cc090d2080 = 0;
      FUN_2cc08fc0000(0x2cc090d2084);
      _DAT_2cc090d2120 = 0;
      uRam000002cc090d2128 = 0;
      _DAT_2cc090d2100 = 0;
      uRam000002cc090d2108 = 0;
      _DAT_2cc090d2130 = 0;
      uRam000002cc090d2138 = 0;
      _DAT_2cc090d2110 = 0;
      uRam000002cc090d2118 = 0;
      _DAT_2cc090d2090 = 0;
      uRam000002cc090d2098 = 0;
      _DAT_2cc090d20f0 = 0;
      uRam000002cc090d20f8 = 0;
      _DAT_2cc090d20e0 = 0;
      uRam000002cc090d20e8 = 0;
      _DAT_2cc090d20d0 = 0;
      uRam000002cc090d20d8 = 0;
      _DAT_2cc090d20c0 = 0;
      uRam000002cc090d20c8 = 0;
      _DAT_2cc090d20b0 = 0;
      uRam000002cc090d20b8 = 0;
      _DAT_2cc090d20a0 = 0;
      uRam000002cc090d20a8 = 0;
      _DAT_2cc090d2140 = 0;
      FUN_2cc08fc0000(0x2cc090d2144);
      _DAT_2cc090d21e0 = 0;
      uRam000002cc090d21e8 = 0;
      _DAT_2cc090d21d0 = 0;
      uRam000002cc090d21d8 = 0;
      _DAT_2cc090d21f0 = 0;
      uRam000002cc090d21f8 = 0;
      _DAT_2cc090d21c0 = 0;
      uRam000002cc090d21c8 = 0;
      _DAT_2cc090d21b0 = 0;
      uRam000002cc090d21b8 = 0;
      _DAT_2cc090d21a0 = 0;
      uRam000002cc090d21a8 = 0;
      _DAT_2cc090d2190 = 0;
      uRam000002cc090d2198 = 0;
      _DAT_2cc090d2180 = 0;
      uRam000002cc090d2188 = 0;
      _DAT_2cc090d2170 = 0;
      uRam000002cc090d2178 = 0;
      _DAT_2cc090d2160 = 0;
      uRam000002cc090d2168 = 0;
      _DAT_2cc090d2150 = 0;
      uRam000002cc090d2158 = 0;
      _DAT_2cc090d2200 = 0;
      FUN_2cc08fc0000(0x2cc090d2208);
      _DAT_2cc090d2284 = 0;
      _DAT_2cc090d227c = 0;
      _DAT_2cc090d228c = 0;
      _DAT_2cc090d2274 = 0;
      _DAT_2cc090d226c = 0;
      _DAT_2cc090d2264 = 0;
      _DAT_2cc090d225c = 0;
      _DAT_2cc090d2254 = 0;
      _DAT_2cc090d224c = 0;
      _DAT_2cc090d2244 = 0;
      _DAT_2cc090d223c = 0;
      _DAT_2cc090d2234 = 0;
      _DAT_2cc090d222c = 0;
      _DAT_2cc090d2224 = 0;
      _DAT_2cc090d221c = 0;
      _DAT_2cc090d2214 = 0;
      _DAT_2cc090d2020 = 6;
      _DAT_2cc090d2090 = param_1;
      (*(code *)0x7ff63a108010)(0x2cc03e1bbb8,0);
      FUN_2cc08fc04d0(&local_88,0x2cc090d283c,1,0x2cc090cf2d8);
      FUN_2cc08fc04d0(0x2cc090d2034,&local_88,0,0x2cc090cf2e8);
      _DAT_2cc090d2024 = (undefined4)_DAT_2cc090d2295;
      uRam000002cc090d2028 = (undefined4)((ulonglong)_DAT_2cc090d2295 >> 0x20);
      _DAT_2cc090d2058 = param_2;
      _DAT_2cc090d2060 = param_3;
      uVar2 = FUN_2cc08fc0c30(&DAT_2cc090d2000,&DAT_2cc090d2020,&DAT_2cc090d2110);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2cc03e1bbb8,0xd,2,0x590008,0x2cc08fe0f40,0x590008,0x2cc08fdfe60);
    uVar2 = 0;
    _DAT_2cc090d2110 = CONCAT44(DAT_2cc090d2110_4,0x272b);
  }
  FUN_2cc08fc0000(&local_88);
  return uVar2;
}



/* Address: 2cc08fd9370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fd9370(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_2cc08fc04d0(param_2,0x2cc08fdf038,0,0x2cc090cf518);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x2cc090d2828;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_2cc08fc04d0(&local_98,piVar12,0,0x2cc090cf528);
  (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x2cc03e1bbb8,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x02cc08fd9550 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x2cc08fdece8))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,(longlong)*param_3,0x52,&local_108);
  FUN_2cc08fc04d0(&local_f8,0x2cc08fe0510,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_2cc08fd9e3b;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_2cc08fd9e3b;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_2cc08fc0060(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1e04cf000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf04a0000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf04a5000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x150470000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x150489000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x15043c000301f9);
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x150457000301f9);
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
      if (uVar13 == uVar14) goto LAB_2cc08fdb112;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_2cc08fdb112:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_2cc08fd9e3b:
  uVar9 = local_e8;
  FUN_2cc08fc04d0(local_e8,&local_f8,0,0x2cc090cfae8);
  FUN_2cc08fc04d0(&local_68,uVar9,0,0x2cc090cfaf8);
  FUN_2cc08fc0000(&local_98);
  FUN_2cc08fc0000(&local_e0);
  FUN_2cc08fc0000(&local_88);
  FUN_2cc08fc0000(&local_78);
  FUN_2cc08fc0000(&local_c0);
  FUN_2cc08fc04d0(0x2cc090d283c,&local_68,1,0x2cc090cfb08);
  FUN_2cc08fc0000(&local_68);
  FUN_2cc08fc0000(&local_108);
  FUN_2cc08fc0000(&local_f8);
  FUN_2cc08fc0000(&local_d0);
  FUN_2cc08fc0000(&local_b0);
  return;
}



/* Address: 2cc08fdb430 */

void FUN_2cc08fdb430(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x02cc08fdb493 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x2cc08fded58))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2cc03e1bbb8,(ulonglong)param_2,0x53,&local_50);
  FUN_2cc08fc04d0(&local_60,0x2cc08fdfc48,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_2cc08fdb68d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_2cc08fdb68d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_2cc08fc0060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x2203c7000301f9);
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
      if (uVar11 == uVar13) goto LAB_2cc08fdb682;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_2cc08fdb682:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_2cc08fdb68d:
  FUN_2cc08fc04d0(param_1,&local_60,0,0x2cc090cf448);
  FUN_2cc08fc04d0(&local_40,param_1,0,0x2cc090cf458);
  FUN_2cc08fc04d0(0x2cc090d283c,&local_40,1,0x2cc090cf468);
  FUN_2cc08fc0000(&local_40);
  FUN_2cc08fc0000(&local_50);
  FUN_2cc08fc0000(&local_60);
  return;
}



/* Address: 2cc08fdb730 */

void FUN_2cc08fdb730(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x2cc03e1bbb8,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_2cc08fc04d0(&local_78,0x2cc090d283c,1,0x2cc090cf478);
    FUN_2cc08fc04d0(&local_88,&local_78,0,0x2cc090cf488);
    (*(code *)0x7ff63a0fd7c0)(0x2cc03e1bbb8,param_3,param_4);
    FUN_2cc08fc04d0(&local_78,0x2cc090d283c,1,0x2cc090cf498);
    FUN_2cc08fc04d0(&local_98,&local_78,0,0x2cc090cf4a8);
    (*(code *)0x7ff63a0e49f0)
              (0x2cc03e1bbb8,0xd8,3,0x590008,0x2cc08fdfd10,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x2cc090cf4c8;
    uVar1 = 0x2cc090cf4b8;
  }
  else {
    uVar2 = 0x2cc090cf4e8;
    uVar1 = 0x2cc090cf4d8;
  }
  FUN_2cc08fc04d0(&local_78,0x2cc090d283c,1,uVar1);
  FUN_2cc08fc04d0(param_1,&local_78,0,uVar2);
  FUN_2cc08fc04d0(&local_68,param_1,0,0x2cc090cf4f8);
  FUN_2cc08fc0000(&local_98);
  FUN_2cc08fc0000(&local_88);
  FUN_2cc08fc04d0(0x2cc090d283c,&local_68,1,0x2cc090cf508);
  FUN_2cc08fc0000(&local_68);
  FUN_2cc08fc0000(&local_78);
  return;
}



/* Address: 2cc08fdb970 */

void FUN_2cc08fdb970(undefined8 *param_1)

{
  (*(code *)0x7ff63a0e6470)(0x2cc03e1bbb8,*param_1,0x2cc03e09be0);
  param_1[1] = 0x2cc08fdee90;
  (*(code *)0x7ff63a0e62f0)(0x2cc03e1bbb8,*param_1);
  return;
}



/* Address: 2cc08fdb9d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdb9d0(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if ((((-1 < param_1) && (param_1 < _DAT_2cc090d236c)) && (-1 < param_2)) &&
     (param_2 < _DAT_2cc090d2370)) {
    uVar3 = (ulonglong)(_DAT_2cc090d236c * param_2 + param_1);
    if (_DAT_2cc090d2398 <= uVar3) {
      (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1801ea000b01f6);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = (ulonglong)_DAT_2cc090d2398 + ~uVar3;
    if ((_DAT_2cc090d2392 & 0x10) == 0) {
      uVar2 = uVar3;
    }
    *(undefined4 *)(_DAT_2cc090d23ac + uVar2 * 4) = param_3;
  }
  return;
}



/* Address: 2cc08fdba70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdba70(int param_1,int param_2,int param_3,undefined4 param_4)

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
  if ((((-1 < iVar6) && (param_3 < _DAT_2cc090d2370)) && (-1 < param_1)) &&
     (param_1 < _DAT_2cc090d236c)) {
    iVar3 = 0;
    if (0 < param_3) {
      iVar3 = param_3;
    }
    iVar2 = _DAT_2cc090d2370 + -1;
    if (iVar6 < _DAT_2cc090d2370) {
      iVar2 = iVar6;
    }
    if (iVar3 <= iVar2) {
      param_1 = _DAT_2cc090d236c * iVar3 + param_1;
      do {
        uVar4 = (ulonglong)param_1;
        if (_DAT_2cc090d2398 <= uVar4) {
          (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xf0281000b01f6);
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        uVar5 = (ulonglong)_DAT_2cc090d2398 + ~uVar4;
        if ((_DAT_2cc090d2392 & 0x10) == 0) {
          uVar5 = uVar4;
        }
        iVar3 = iVar3 + 1;
        *(undefined4 *)(_DAT_2cc090d23ac + uVar5 * 4) = param_4;
        param_1 = _DAT_2cc090d236c + param_1;
      } while (iVar3 <= iVar2);
    }
  }
  return;
}



/* Address: 2cc08fdbb70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdbb70(int param_1,int param_2,int param_3,undefined4 param_4)

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
  
  lVar3 = _DAT_2cc090d23ac;
  iVar8 = param_2;
  if (param_2 < param_1) {
    iVar8 = param_1;
  }
  if (param_1 < param_2) {
    param_2 = param_1;
  }
  if ((((-1 < iVar8) && (param_2 < _DAT_2cc090d236c)) && (-1 < param_3)) &&
     (param_3 < _DAT_2cc090d2370)) {
    iVar11 = 0;
    if (0 < param_2) {
      iVar11 = param_2;
    }
    iVar4 = _DAT_2cc090d236c + -1;
    if (iVar8 < _DAT_2cc090d236c) {
      iVar4 = iVar8;
    }
    uVar5 = (iVar4 - iVar11) + 1;
    if (uVar5 != 0) {
      param_3 = _DAT_2cc090d236c * param_3;
      uVar7 = param_3 + iVar11;
      uVar6 = uVar5 + uVar7;
      if ((CARRY4(uVar5,uVar7)) || (_DAT_2cc090d2398 < uVar6)) {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x30299000b01f6);
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



/* Address: 2cc08fdbcc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdbcc0(double param_1,double param_2,uint param_3)

{
  code *pcVar1;
  double dVar2;
  int iVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  double *pdVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  
  dVar2 = _DAT_2cc08fded98;
  uVar6 = (uint)((ulonglong)param_1 >> 0x34) & 0x7ff;
  lVar9 = (ulonglong)uVar6 - 0x3ff;
  dVar11 = param_1;
  if ((ulonglong)uVar6 < 0x433) {
    if (uVar6 < 0x3ff) {
      dVar11 = (double)((ulonglong)param_1 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar9 != -1) {
        dVar11 = (double)((ulonglong)param_1 & 0x8000000000000000);
      }
    }
    else {
      bVar5 = (byte)lVar9;
      if (((longlong)param_1 << (bVar5 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar5 & 0x3f)) + (longlong)param_1 &
                         -0x10000000000000 >> (bVar5 & 0x3f));
      }
    }
  }
  else if (lVar9 == 0x400) {
    dVar11 = param_1 + param_1;
  }
  iVar3 = (int)dVar11;
  uVar6 = (uint)((ulonglong)param_2 >> 0x34) & 0x7ff;
  lVar9 = (ulonglong)uVar6 - 0x3ff;
  dVar11 = param_2;
  if ((ulonglong)uVar6 < 0x433) {
    if (uVar6 < 0x3ff) {
      dVar11 = (double)((ulonglong)param_2 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar9 != -1) {
        dVar11 = (double)((ulonglong)param_2 & 0x8000000000000000);
      }
    }
    else {
      bVar5 = (byte)lVar9;
      if (((longlong)param_2 << (bVar5 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar11 = (double)((0x8000000000000U >> (bVar5 & 0x3f)) + (longlong)param_2 &
                         -0x10000000000000 >> (bVar5 & 0x3f));
      }
    }
  }
  else if (lVar9 == 0x400) {
    dVar11 = param_2 + param_2;
  }
  iVar7 = (int)dVar11;
  dVar13 = param_1 - (double)iVar3;
  dVar12 = param_2 - (double)(int)dVar11;
  if ((((dVar13 == 0.0) && (!NAN(dVar13))) && (dVar12 == 0.0)) && (!NAN(dVar12))) {
    if (((-1 < iVar3) && (iVar3 < _DAT_2cc090d236c)) && ((-1 < iVar7 && (iVar7 < _DAT_2cc090d2370)))
       ) {
      uVar8 = (ulonglong)(_DAT_2cc090d236c * iVar7 + iVar3);
      if (_DAT_2cc090d2398 <= uVar8) {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1801ea000b01f6);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = (ulonglong)_DAT_2cc090d2398 + ~uVar8;
      if ((_DAT_2cc090d2392 & 0x10) == 0) {
        uVar4 = uVar8;
      }
      *(uint *)(_DAT_2cc090d23ac + uVar4 * 4) = param_3;
    }
    return;
  }
  if (dVar13 < 0.0) {
    _DAT_2cc090d2694 = iVar3 + -1;
    _DAT_2cc090d269c = _DAT_2cc090d2694;
  }
  if ((dVar13 == 0.0) && (!NAN(dVar13))) {
    _DAT_2cc090d2694 = iVar3;
    _DAT_2cc090d269c = iVar3;
  }
  if (0.0 < dVar13) {
    _DAT_2cc090d2694 = iVar3 + 1;
    _DAT_2cc090d269c = _DAT_2cc090d2694;
  }
  if (dVar12 < 0.0) {
    _DAT_2cc090d26a8 = iVar7 + -1;
    _DAT_2cc090d26ac = _DAT_2cc090d26a8;
  }
  if ((dVar12 == 0.0) && (!NAN(dVar12))) {
    _DAT_2cc090d26a8 = iVar7;
    _DAT_2cc090d26ac = iVar7;
  }
  if (0.0 < dVar12) {
    _DAT_2cc090d26a8 = iVar7 + 1;
    _DAT_2cc090d26ac = _DAT_2cc090d26a8;
  }
  dVar13 = (double)iVar3 - param_1;
  dVar12 = (double)(int)dVar11 - param_2;
  dVar13 = dVar13 * dVar13;
  dVar12 = dVar12 * dVar12;
  dVar11 = dVar13 + dVar12;
  _DAT_2cc090d2690 = iVar3;
  _DAT_2cc090d2698 = iVar3;
  _DAT_2cc090d26a0 = iVar7;
  _DAT_2cc090d26a4 = iVar7;
  if ((dVar11 != 0.0) || (NAN(dVar11))) {
    pdVar10 = (double *)&DAT_2cc090d2670;
    _DAT_2cc090d2670 = _DAT_2cc08fded98 / dVar11;
    dVar12 = ((double)_DAT_2cc090d2694 - param_1) * ((double)_DAT_2cc090d2694 - param_1) + dVar12;
    if ((dVar12 != 0.0) || (NAN(dVar12))) {
      _DAT_2cc090d2678 = _DAT_2cc08fded98 / dVar12;
      dVar13 = dVar13 + ((double)_DAT_2cc090d26a8 - param_2) * ((double)_DAT_2cc090d26a8 - param_2);
      if ((dVar13 != 0.0) || (NAN(dVar13))) {
        _DAT_2cc090d2680 = _DAT_2cc08fded98 / dVar13;
        dVar11 = ((double)_DAT_2cc090d26ac - param_2) * ((double)_DAT_2cc090d26ac - param_2) +
                 ((double)_DAT_2cc090d269c - param_1) * ((double)_DAT_2cc090d269c - param_1);
        if ((dVar11 != 0.0) || (NAN(dVar11))) {
          _DAT_2cc090d2688 = _DAT_2cc08fded98 / dVar11;
          dVar11 = _DAT_2cc090d2688 + _DAT_2cc090d2670 + _DAT_2cc090d2678 + _DAT_2cc090d2680;
          if ((dVar11 != 0.0) || (NAN(dVar11))) {
            lVar9 = 0;
            do {
              uVar6 = 0;
              iVar3 = *(int *)(&DAT_2cc090d26a0 + lVar9);
              iVar7 = *(int *)(&DAT_2cc090d2690 + lVar9);
              if ((((-1 < iVar7) && (iVar7 < _DAT_2cc090d236c)) && (-1 < iVar3)) &&
                 (iVar3 < _DAT_2cc090d2370)) {
                uVar8 = (ulonglong)(_DAT_2cc090d236c * iVar3 + iVar7);
                if (_DAT_2cc090d2398 <= uVar8) {
                  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f01df000b01f6);
                  goto LAB_2cc08fdc289;
                }
                uVar4 = (ulonglong)_DAT_2cc090d2398 + ~uVar8;
                if ((_DAT_2cc090d2392 & 0x10) == 0) {
                  uVar4 = uVar8;
                }
                uVar6 = *(uint *)(_DAT_2cc090d23ac + uVar4 * 4);
              }
              dVar12 = *pdVar10 / dVar11;
              dVar13 = dVar2 - dVar12;
              FUN_2cc08fdb9d0(iVar7,iVar3,
                              (int)((double)(uVar6 & 0xff) * dVar13 +
                                   dVar12 * (double)(param_3 & 0xff)) & 0xffU |
                              ((int)((double)(uVar6 >> 8 & 0xff) * dVar13 +
                                    dVar12 * (double)(param_3 >> 8 & 0xff)) & 0xffU) << 8 |
                              ((int)((double)(uVar6 >> 0x10 & 0xff) * dVar13 +
                                    dVar12 * (double)(param_3 >> 0x10 & 0xff)) & 0xffU) << 0x10 |
                              (int)((double)(uVar6 >> 0x18) * dVar13 +
                                   dVar12 * (double)(param_3 >> 0x18)) << 0x18);
              lVar9 = lVar9 + 4;
              pdVar10 = pdVar10 + 1;
              if (lVar9 == 0x10) {
                return;
              }
            } while( true );
          }
          goto LAB_2cc08fdc2a9;
        }
      }
    }
  }
LAB_2cc08fdc289:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0842000b01f7);
LAB_2cc08fdc2a9:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0848000b01f7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2cc08fdc2d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdc2d0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  ulonglong uVar11;
  byte bVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  double *pdVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  
  uVar13 = _DAT_2cc08fdeda0;
  uVar31 = CONCAT44(unaff_XMM11_Db,unaff_XMM11_Da);
  uVar32 = CONCAT44(unaff_XMM11_Dd,unaff_XMM11_Dc);
  uVar29 = CONCAT44(unaff_XMM10_Db,unaff_XMM10_Da);
  uVar30 = CONCAT44(unaff_XMM10_Dd,unaff_XMM10_Dc);
  uVar27 = CONCAT44(unaff_XMM9_Db,unaff_XMM9_Da);
  uVar28 = CONCAT44(unaff_XMM9_Dd,unaff_XMM9_Dc);
  uVar25 = CONCAT44(unaff_XMM8_Db,unaff_XMM8_Da);
  uVar26 = CONCAT44(unaff_XMM8_Dd,unaff_XMM8_Dc);
  uVar22 = CONCAT44(unaff_XMM7_Db,unaff_XMM7_Da);
  uVar24 = CONCAT44(unaff_XMM7_Dd,unaff_XMM7_Dc);
  if (((((param_1 < 0) && (param_3 < 0)) || ((param_2 < 0 && (param_4 < 0)))) ||
      ((_DAT_2cc090d236c <= param_1 && (_DAT_2cc090d236c <= param_3)))) ||
     ((_DAT_2cc090d2370 <= param_2 && (_DAT_2cc090d2370 <= param_4)))) {
    return;
  }
  if ((param_3 - param_1 == 0) && (param_4 == param_2)) {
code_r0x02cc08fdb9d0:
    if (((-1 < param_1) && (param_1 < _DAT_2cc090d236c)) &&
       ((-1 < param_2 && (param_2 < _DAT_2cc090d2370)))) {
      uVar13 = (ulonglong)(_DAT_2cc090d236c * param_2 + param_1);
      if (_DAT_2cc090d2398 <= uVar13) {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1801ea000b01f6);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar11 = (ulonglong)_DAT_2cc090d2398 + ~uVar13;
      if ((_DAT_2cc090d2392 & 0x10) == 0) {
        uVar11 = uVar13;
      }
      *(uint *)(_DAT_2cc090d23ac + uVar11 * 4) = param_5;
    }
    return;
  }
  dVar19 = (double)(param_3 - param_1);
  dVar20 = (double)(param_4 - param_2);
  dVar18 = SQRT(dVar20 * dVar20 + dVar19 * dVar19);
  if ((dVar18 == 0.0) && (!NAN(dVar18))) {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x508aa000b01f7);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  dVar6 = (double)param_1;
  dVar5 = (double)param_2;
  dVar4 = (double)param_3;
  dVar7 = (double)param_4;
  uVar14 = 1 << (DAT_2cc090d2344 & 0x1f);
  dVar9 = (double)((ulonglong)(dVar19 / dVar18) & _DAT_2cc08fdeda0);
  dVar8 = (double)(_DAT_2cc08fdeda0 & (ulonglong)(dVar20 / dVar18));
  uVar15 = _DAT_2cc090d2340;
  do {
    if ((uVar14 & ~uVar15) == 0) {
      FUN_2cc08fdbcc0(SUB84(dVar6,0),dVar5,param_5);
      uVar15 = _DAT_2cc090d2340;
    }
    dVar10 = _DAT_2cc08fded98;
    dVar6 = dVar6 + dVar19 / dVar18;
    uVar14 = uVar14 * 2;
    if (uVar14 == 0x1000000) {
      uVar14 = 1;
    }
  } while ((dVar9 <= (double)((ulonglong)(dVar4 - dVar6) & uVar13)) &&
          (dVar5 = dVar5 + dVar20 / dVar18, dVar8 <= (double)((ulonglong)(dVar7 - dVar5) & uVar13)))
  ;
  if ((uVar14 & ~uVar15) != 0) {
    return;
  }
  uVar21 = CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da);
  uVar23 = CONCAT44(unaff_XMM6_Dd,unaff_XMM6_Dc);
  uVar14 = (uint)((ulonglong)dVar4 >> 0x34) & 0x7ff;
  lVar16 = (ulonglong)uVar14 - 0x3ff;
  dVar18 = dVar4;
  if ((ulonglong)uVar14 < 0x433) {
    if (uVar14 < 0x3ff) {
      dVar18 = (double)((ulonglong)dVar4 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar16 != -1) {
        dVar18 = (double)((ulonglong)dVar4 & 0x8000000000000000);
      }
    }
    else {
      bVar12 = (byte)lVar16;
      if (((longlong)dVar4 << (bVar12 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar12 & 0x3f)) + (longlong)dVar4 &
                         -0x10000000000000 >> (bVar12 & 0x3f));
      }
    }
  }
  else if (lVar16 == 0x400) {
    dVar18 = dVar4 + dVar4;
  }
  param_1 = (int)dVar18;
  uVar14 = (uint)((ulonglong)dVar7 >> 0x34) & 0x7ff;
  lVar16 = (ulonglong)uVar14 - 0x3ff;
  dVar18 = dVar7;
  if ((ulonglong)uVar14 < 0x433) {
    if (uVar14 < 0x3ff) {
      dVar18 = (double)((ulonglong)dVar7 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar16 != -1) {
        dVar18 = (double)((ulonglong)dVar7 & 0x8000000000000000);
      }
    }
    else {
      bVar12 = (byte)lVar16;
      if (((longlong)dVar7 << (bVar12 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar12 & 0x3f)) + (longlong)dVar7 &
                         -0x10000000000000 >> (bVar12 & 0x3f));
      }
    }
  }
  else if (lVar16 == 0x400) {
    dVar18 = dVar7 + dVar7;
  }
  param_2 = (int)dVar18;
  dVar20 = dVar4 - (double)param_1;
  dVar19 = dVar7 - (double)(int)dVar18;
  if ((((dVar20 == 0.0) && (!NAN(dVar20))) && (dVar19 == 0.0)) && (!NAN(dVar19)))
  goto code_r0x02cc08fdb9d0;
  if (dVar20 < 0.0) {
    _DAT_2cc090d2694 = param_1 + -1;
    _DAT_2cc090d269c = _DAT_2cc090d2694;
  }
  if ((dVar20 == 0.0) && (!NAN(dVar20))) {
    _DAT_2cc090d2694 = param_1;
    _DAT_2cc090d269c = param_1;
  }
  if (0.0 < dVar20) {
    _DAT_2cc090d2694 = param_1 + 1;
    _DAT_2cc090d269c = _DAT_2cc090d2694;
  }
  if (dVar19 < 0.0) {
    _DAT_2cc090d26a8 = param_2 + -1;
    _DAT_2cc090d26ac = _DAT_2cc090d26a8;
  }
  if ((dVar19 == 0.0) && (!NAN(dVar19))) {
    _DAT_2cc090d26a8 = param_2;
    _DAT_2cc090d26ac = param_2;
  }
  if (0.0 < dVar19) {
    _DAT_2cc090d26a8 = param_2 + 1;
    _DAT_2cc090d26ac = _DAT_2cc090d26a8;
  }
  dVar20 = (double)param_1 - dVar4;
  dVar19 = (double)(int)dVar18 - dVar7;
  dVar20 = dVar20 * dVar20;
  dVar19 = dVar19 * dVar19;
  dVar18 = dVar20 + dVar19;
  _DAT_2cc090d2690 = param_1;
  _DAT_2cc090d2698 = param_1;
  _DAT_2cc090d26a0 = param_2;
  _DAT_2cc090d26a4 = param_2;
  if ((dVar18 != 0.0) || (NAN(dVar18))) {
    pdVar17 = (double *)&DAT_2cc090d2670;
    _DAT_2cc090d2670 = _DAT_2cc08fded98 / dVar18;
    dVar19 = ((double)_DAT_2cc090d2694 - dVar4) * ((double)_DAT_2cc090d2694 - dVar4) + dVar19;
    if ((dVar19 != 0.0) || (NAN(dVar19))) {
      _DAT_2cc090d2678 = _DAT_2cc08fded98 / dVar19;
      dVar20 = dVar20 + ((double)_DAT_2cc090d26a8 - dVar7) * ((double)_DAT_2cc090d26a8 - dVar7);
      if ((dVar20 != 0.0) || (NAN(dVar20))) {
        _DAT_2cc090d2680 = _DAT_2cc08fded98 / dVar20;
        dVar18 = ((double)_DAT_2cc090d26ac - dVar7) * ((double)_DAT_2cc090d26ac - dVar7) +
                 ((double)_DAT_2cc090d269c - dVar4) * ((double)_DAT_2cc090d269c - dVar4);
        if ((dVar18 != 0.0) || (NAN(dVar18))) {
          _DAT_2cc090d2688 = _DAT_2cc08fded98 / dVar18;
          dVar18 = _DAT_2cc090d2688 + _DAT_2cc090d2670 + _DAT_2cc090d2678 + _DAT_2cc090d2680;
          if ((dVar18 != 0.0) || (NAN(dVar18))) {
            lVar16 = 0;
            do {
              uVar14 = 0;
              iVar1 = *(int *)(&DAT_2cc090d26a0 + lVar16);
              iVar2 = *(int *)(&DAT_2cc090d2690 + lVar16);
              if ((((-1 < iVar2) && (iVar2 < _DAT_2cc090d236c)) && (-1 < iVar1)) &&
                 (iVar1 < _DAT_2cc090d2370)) {
                uVar13 = (ulonglong)(_DAT_2cc090d236c * iVar1 + iVar2);
                if (_DAT_2cc090d2398 <= uVar13) {
                  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1f01df000b01f6);
                  goto LAB_2cc08fdc289;
                }
                uVar11 = (ulonglong)_DAT_2cc090d2398 + ~uVar13;
                if ((_DAT_2cc090d2392 & 0x10) == 0) {
                  uVar11 = uVar13;
                }
                uVar14 = *(uint *)(_DAT_2cc090d23ac + uVar11 * 4);
              }
              dVar19 = *pdVar17 / dVar18;
              dVar20 = dVar10 - dVar19;
              uVar15 = ((int)((double)(uVar14 >> 8 & 0xff) * dVar20 +
                             dVar19 * (double)(param_5 >> 8 & 0xff)) & 0xffU) << 8 |
                       ((int)((double)(uVar14 >> 0x10 & 0xff) * dVar20 +
                             dVar19 * (double)(param_5 >> 0x10 & 0xff)) & 0xffU) << 0x10 |
                       (int)((double)(uVar14 >> 0x18) * dVar20 + dVar19 * (double)(param_5 >> 0x18))
                       << 0x18;
              FUN_2cc08fdb9d0(iVar2,iVar1,
                              (int)((double)(uVar14 & 0xff) * dVar20 +
                                   dVar19 * (double)(param_5 & 0xff)) & 0xffU | uVar15,uVar15,uVar21
                              ,uVar23,uVar22,uVar24,uVar25,uVar26,uVar27,uVar28,uVar29,uVar30,uVar31
                              ,uVar32);
              lVar16 = lVar16 + 4;
              pdVar17 = pdVar17 + 1;
              if (lVar16 == 0x10) {
                return;
              }
            } while( true );
          }
          goto LAB_2cc08fdc2a9;
        }
      }
    }
  }
LAB_2cc08fdc289:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0842000b01f7);
LAB_2cc08fdc2a9:
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0xd0848000b01f7);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 2cc08fdc5d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdc5d0(undefined8 param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)(int)_DAT_2cc090d2448;
  (*(code *)0x7ff63a0da0e0)(0x2cc03e1bbb8,0x2cc090d2440,_DAT_2cc090d2448 + 1,0);
  if (uVar3 < _DAT_2cc090d2448) {
    uVar2 = (ulonglong)_DAT_2cc090d2448 + ~uVar3;
    if ((_DAT_2cc090d2442 & 0x10) == 0) {
      uVar2 = uVar3;
    }
    *(undefined8 *)(_DAT_2cc090d245c + uVar2 * 8) = param_1;
    return;
  }
  (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1202d3000001f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2cc08fdc670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_2cc08fdc670(undefined8 param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  double dVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  cVar2 = (*(code *)0x7ff63a107ee0)(0x2cc03e1bbb8,param_1);
  if (cVar2 == '\0') {
    dVar4 = 0.0;
  }
  else {
    (*(code *)0x7ff63a107f70)(0x2cc03e1bbb8,4);
    dVar4 = _DAT_2cc090d2848;
    uVar5 = SUB84(_DAT_2cc090d2848,0);
    uVar6 = (undefined4)((ulonglong)_DAT_2cc090d2848 >> 0x20);
    iVar3 = (*(code *)0x7ff63a107fc0)(0x2cc03e1bbb8,2);
    if (iVar3 == 0) {
      (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,1);
      if ((_DAT_2cc090d2818 == 0.0) && (!NAN(_DAT_2cc090d2818))) goto LAB_2cc08fdc799;
      uVar5 = SUB84(_DAT_2cc090d2848,0);
      uVar6 = (undefined4)((ulonglong)_DAT_2cc090d2848 >> 0x20);
    }
    else {
      (*(code *)0x7ff63a0f2890)(0x2cc03e1bbb8,0x2cc08fdefd0,4);
      dVar4 = _DAT_2cc090d2848;
      if ((_DAT_2cc090d2818 == 0.0) && (!NAN(_DAT_2cc090d2818))) {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1702dd000001f7);
LAB_2cc08fdc799:
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1a02dc000001f7);
        pcVar1 = (code *)swi(3);
        dVar4 = (double)(*pcVar1)();
        return dVar4;
      }
    }
    dVar4 = ((double)CONCAT44(uVar6,uVar5) - dVar4) / _DAT_2cc090d2818;
  }
  return dVar4;
}



/* Address: 2cc08fdc7c0 */

void FUN_2cc08fdc7c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined4 param_6,int param_7)

{
  char cVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);
  iVar2 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,param_1);
  if ((iVar2 < 0) &&
     (cVar1 = (*(code *)0x7ff63a0e49f0)
                        (0x2cc03e1bbb8,0x112,8,0x550005,0,CONCAT44(uVar3,0x590008),param_1,0x520004,
                         0x14,0x520004,0,0x540005,param_2,0x580007,param_3,0x540005,param_4,0x580007
                         ,param_5), cVar1 == '\0')) {
    return;
  }
  (*(code *)0x7ff63a0f39d0)(0x2cc03e1bbb8,0,param_1,0,param_2,param_3);
  (*(code *)0x7ff63a0f39d0)(0x2cc03e1bbb8,0,param_1,1,param_4,param_5);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0,param_6);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,1,0);
  iVar2 = 1;
  if (1 < param_7) {
    iVar2 = param_7;
  }
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,2,iVar2);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x407,0);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,3,1);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,10,0);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0xd0,1);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0xcf,6);
  return;
}



/* Address: 2cc08fdca10 */

void FUN_2cc08fdca10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 local_48;
  undefined4 local_40;
  
  local_40 = 0;
  local_48 = 0;
  FUN_2cc08fc04d0(&local_48,0x2cc08fe14b0,0,0x2cc090d0390);
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,&local_48);
  if (iVar1 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2cc03e1bbb8,0x112,6,0x550005,0,0x590008,&local_48,0x520004,0x6e,0x520004,0,0x540005
               ,0,0x580007,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,3,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0xd0,1);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x401,0x50804);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x405,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0,0x50c800);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,2,1);
  }
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x3f4,(longlong)param_1);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x3f5,(longlong)param_2);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x3fb,(longlong)param_3);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_48,0x3fc,(longlong)param_4);
  FUN_2cc08fc0000(&local_48);
  return;
}



/* Address: 2cc08fdcc90 */

void FUN_2cc08fdcc90(longlong param_1,int param_2,int param_3,undefined8 param_4,undefined4 param_5,
                    undefined4 param_6,undefined8 param_7)

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
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined4 local_60;
  longlong local_5c;
  undefined8 local_50;
  undefined4 local_48;
  
  local_60 = 0;
  local_5c = 0;
  local_50 = 0;
  local_48 = 0;
  FUN_2cc08fc04d0(&local_60,0x2cc08fe1478,0);
  lVar5 = *(longlong *)(param_1 + 4);
  if (lVar5 == 0) goto LAB_2cc08fdce0d;
  uVar4 = *(uint *)(lVar5 + -4);
  uVar16 = (ulonglong)uVar4;
  if ((uVar16 == 0) && (local_5c != 0)) goto LAB_2cc08fdce0d;
  if (local_5c == 0) {
    uVar14 = 0;
    uVar13 = uVar4;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
    uVar13 = uVar4 + uVar14;
  }
  cVar10 = FUN_2cc08fc0060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x1e0433000001f9);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  if (uVar16 != 0) {
    lVar1 = local_5c + (ulonglong)uVar14 * 2;
    if (uVar4 < 0x10) {
      uVar12 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
      uVar12 = 0;
    }
    else {
      uVar15 = 0;
      uVar12 = (ulonglong)(uVar4 & 0xfffffff8);
      do {
        puVar2 = (undefined4 *)(lVar5 + uVar15);
        uVar7 = puVar2[1];
        uVar8 = puVar2[2];
        uVar9 = puVar2[3];
        puVar3 = (undefined4 *)(lVar1 + uVar15);
        *puVar3 = *puVar2;
        puVar3[1] = uVar7;
        puVar3[2] = uVar8;
        puVar3[3] = uVar9;
        uVar15 = uVar15 + 0x10;
      } while ((uVar16 * 2 & 0xfffffffffffffff0) != uVar15);
      if (uVar12 == uVar16) goto LAB_2cc08fdce02;
    }
    do {
      *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
      uVar12 = uVar12 + 1;
    } while (uVar16 != uVar12);
  }
LAB_2cc08fdce02:
  *(uint *)(local_5c + -4) = uVar13;
  *(undefined2 *)(local_5c + (ulonglong)uVar13 * 2) = 0;
LAB_2cc08fdce0d:
  FUN_2cc08fc04d0(&local_50,&local_60,0,0x2cc090d03b0);
  iVar11 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,&local_50);
  if (iVar11 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2cc03e1bbb8,0x112,6,0x550005,0,0x590008,&local_50,0x520004,0x66,0x520004,0,0x540005
               ,0,0x580007,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0xd0,1);
  }
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0x3f4,(longlong)param_2);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0x3f5,(longlong)param_3);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0x3ea,param_6);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,&local_50,0,param_5);
  (*(code *)0x7ff63a0f3c80)(0x2cc03e1bbb8,0,&local_50,0x3e9,param_7);
  (*(code *)0x7ff63a0f3c80)(0x2cc03e1bbb8,0,&local_50,6,param_4);
  FUN_2cc08fc0000(&local_50);
  FUN_2cc08fc0000(&local_60);
  return;
}



/* Address: 2cc08fdd030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2cc08fdd030(int *param_1,int param_2,longlong param_3,undefined8 param_4,undefined4 param_5
                    )

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_a8;
  longlong local_a4;
  int *local_98;
  undefined4 local_90;
  undefined8 local_8c;
  undefined4 local_80;
  undefined8 local_7c;
  int local_74;
  undefined8 local_70;
  
  local_a8 = 0;
  local_80 = 0;
  local_90 = 0;
  local_a4 = 0;
  local_7c = 0;
  local_8c = 0;
  local_70 = param_4;
  FUN_2cc08fc04d0(&local_90,0x2cc08fdf070,0,0x2cc090d03c0);
  bVar9 = DAT_2cc090d2325;
  FUN_2cc08fc04d0(&local_80,param_3,0,0x2cc090d03d0);
  iVar10 = *param_1;
  FUN_2cc08fc04d0(&local_a8,0x2cc08fe14d0,0);
  lVar2 = *(longlong *)(param_3 + 4);
  if (lVar2 != 0) {
    uVar11 = *(uint *)(lVar2 + -4);
    uVar15 = (ulonglong)uVar11;
    if ((uVar15 != 0) || (local_a4 == 0)) {
      if (local_a4 == 0) {
        uVar12 = 0;
        uVar13 = uVar11;
      }
      else {
        uVar12 = (ulonglong)*(uint *)(local_a4 + -4);
        uVar13 = uVar11 + *(uint *)(local_a4 + -4);
      }
      local_98 = param_1;
      local_74 = param_2;
      cVar5 = FUN_2cc08fc0060(&local_a8);
      if (cVar5 == '\0') {
        (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x110450000001f9);
        goto LAB_2cc08fdd65c;
      }
      if (uVar15 != 0) {
        lVar1 = local_a4 + uVar12 * 2;
        if (uVar11 < 0x10) {
          uVar12 = 0;
        }
        else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
          uVar12 = 0;
        }
        else {
          uVar16 = 0;
          uVar12 = (ulonglong)(uVar11 & 0xfffffff8);
          do {
            uVar4 = ((undefined8 *)(lVar2 + uVar16))[1];
            *(undefined8 *)(lVar1 + uVar16) = *(undefined8 *)(lVar2 + uVar16);
            ((undefined8 *)(lVar1 + uVar16))[1] = uVar4;
            uVar16 = uVar16 + 0x10;
          } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
          if (uVar12 == uVar15) goto LAB_2cc08fdd212;
        }
        do {
          *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
          uVar12 = uVar12 + 1;
        } while (uVar15 != uVar12);
      }
LAB_2cc08fdd212:
      *(uint *)(local_a4 + -4) = uVar13;
      *(undefined2 *)(local_a4 + (ulonglong)uVar13 * 2) = 0;
      param_1 = local_98;
      param_2 = local_74;
    }
  }
  FUN_2cc08fdcc90(&local_a8,param_2,iVar10,&local_80,0xb9a596,(bVar9 & 1) * '\t',&local_90);
  FUN_2cc08fc04d0(&local_90,0x2cc08fdf070,0,0x2cc090d03f0);
  bVar9 = DAT_2cc090d2325;
  FUN_2cc08fc04d0(&local_80,local_70,0,0x2cc090d0400);
  if (DAT_2cc090d2325 == 0) {
    uVar19 = 0;
    uVar20 = 0;
  }
  else {
    uVar19 = (undefined4)_DAT_2cc08fdedb0;
    uVar20 = (undefined4)((ulonglong)_DAT_2cc08fdedb0 >> 0x20);
  }
  iVar10 = *param_1;
  iVar6 = (*(code *)0x7ff63a0f0700)(0x2cc03e1bbb8,0x1b);
  iVar7 = 0x60;
  if (0 < iVar6) {
    iVar7 = iVar6;
  }
  dVar18 = ((double)iVar7 / _DAT_2cc08fdedb8) * (double)CONCAT44(uVar20,uVar19);
  uVar11 = (uint)((ulonglong)dVar18 >> 0x34) & 0x7ff;
  lVar2 = (ulonglong)uVar11 - 0x3ff;
  dVar17 = dVar18;
  if ((ulonglong)uVar11 < 0x433) {
    if (uVar11 < 0x3ff) {
      dVar17 = (double)((ulonglong)dVar18 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar2 != -1) {
        dVar17 = (double)((ulonglong)dVar18 & 0x8000000000000000);
      }
    }
    else {
      bVar8 = (byte)lVar2;
      if (((longlong)dVar18 << (bVar8 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar17 = (double)((0x8000000000000U >> (bVar8 & 0x3f)) + (longlong)dVar18 &
                         -0x10000000000000 >> (bVar8 & 0x3f));
      }
    }
  }
  else if (lVar2 == 0x400) {
    dVar17 = dVar18 + dVar18;
  }
  FUN_2cc08fc04d0(&local_a8,0x2cc08fe14f0,0);
  lVar2 = *(longlong *)(param_3 + 4);
  if (lVar2 == 0) goto LAB_2cc08fdd4c2;
  uVar11 = *(uint *)(lVar2 + -4);
  uVar15 = (ulonglong)uVar11;
  if ((uVar15 == 0) && (local_a4 != 0)) goto LAB_2cc08fdd4c2;
  if (local_a4 == 0) {
    uVar13 = 0;
    uVar14 = uVar11;
  }
  else {
    uVar13 = *(uint *)(local_a4 + -4);
    uVar14 = uVar11 + uVar13;
  }
  local_98 = param_1;
  cVar5 = FUN_2cc08fc0060(&local_a8);
  if (cVar5 == '\0') {
LAB_2cc08fdd65c:
    (*(code *)0x7ff639cc59a0)(0x2cc03e1bbb8,0x110451000001f9);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar15 != 0) {
    lVar1 = local_a4 + (ulonglong)uVar13 * 2;
    if (uVar11 < 0x10) {
      uVar12 = 0;
    }
    else if ((ulonglong)(lVar1 - lVar2) < 0x20) {
      uVar12 = 0;
    }
    else {
      uVar16 = 0;
      uVar12 = (ulonglong)(uVar11 & 0xfffffff8);
      do {
        uVar4 = ((undefined8 *)(lVar2 + uVar16))[1];
        *(undefined8 *)(lVar1 + uVar16) = *(undefined8 *)(lVar2 + uVar16);
        ((undefined8 *)(lVar1 + uVar16))[1] = uVar4;
        uVar16 = uVar16 + 0x10;
      } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar16);
      if (uVar12 == uVar15) goto LAB_2cc08fdd4b2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar2 + uVar12 * 2);
      uVar12 = uVar12 + 1;
    } while (uVar15 != uVar12);
  }
LAB_2cc08fdd4b2:
  *(uint *)(local_a4 + -4) = uVar14;
  *(undefined2 *)(local_a4 + (ulonglong)uVar14 * 2) = 0;
  param_1 = local_98;
LAB_2cc08fdd4c2:
  FUN_2cc08fdcc90(&local_a8,(int)dVar17 + param_2,iVar10,&local_80,param_5,(bVar9 & 1) * '\t',
                  &local_90);
  dVar17 = _DAT_2cc08fdedc0;
  if (DAT_2cc090d2325 == 0) {
    dVar17 = 0.0;
  }
  iVar7 = (*(code *)0x7ff63a0f0700)(0x2cc03e1bbb8,0x1b);
  iVar10 = 0x60;
  if (0 < iVar7) {
    iVar10 = iVar7;
  }
  dVar17 = ((double)iVar10 / _DAT_2cc08fdedb8) * dVar17;
  uVar11 = (uint)((ulonglong)dVar17 >> 0x34) & 0x7ff;
  lVar2 = (ulonglong)uVar11 - 0x3ff;
  dVar18 = dVar17;
  if ((ulonglong)uVar11 < 0x433) {
    if (uVar11 < 0x3ff) {
      dVar18 = (double)((ulonglong)dVar17 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar2 != -1) {
        dVar18 = (double)((ulonglong)dVar17 & 0x8000000000000000);
      }
    }
    else {
      bVar9 = (byte)lVar2;
      if (((longlong)dVar17 << (bVar9 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar9 & 0x3f)) + (longlong)dVar17 &
                         -0x10000000000000 >> (bVar9 & 0x3f));
      }
    }
  }
  else if (lVar2 == 0x400) {
    dVar18 = dVar17 + dVar17;
  }
  *param_1 = *param_1 + (int)dVar18;
  FUN_2cc08fc0000(&local_90);
  FUN_2cc08fc0000(&local_80);
  FUN_2cc08fc0000(&local_a8);
  return;
}



/* Address: 2cc08fdd680 */

void FUN_2cc08fdd680(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,
                    undefined8 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = (*(code *)0x7ff63a0f4840)(0x2cc03e1bbb8,0,param_1);
  if (iVar1 < 0) {
    (*(code *)0x7ff63a0e49f0)
              (0x2cc03e1bbb8,0x112,6,0x550005,0,0x590008,param_1,0x520004,0x67,0x520004,0,0x540005,0
               ,0x580007,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0xd0,1);
    (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0xcf,10);
    (*(code *)0x7ff63a0f3c80)(0x2cc03e1bbb8,0,param_1,0x3e9,0x2cc08fe1560);
  }
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3f4,(longlong)param_2);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3f5,(longlong)param_3);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3fb,(longlong)param_4);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3fc,(longlong)param_5);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3ea,(ulonglong)DAT_2cc090d2325 * 9);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0,0xffffff);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x401,param_7);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x40b,param_7);
  (*(code *)0x7ff63a0f3b30)(0x2cc03e1bbb8,0,param_1,0x3fa,0);
  (*(code *)0x7ff63a0f3c80)(0x2cc03e1bbb8,0,param_1,6,param_6);
  return;
}



/* Address: 2cc08fdd910 */

void thunk_FUN_2cc08fc0bf0(void)

{
  FUN_2cc08fc0bf0();
  return;
}


