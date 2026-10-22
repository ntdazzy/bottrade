/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.
 * Not original MQ5 source. Names, types and external calls may be unresolved.
 * No claim of complete recovery or compilable trading logic.
 */


/* Address: 2b1a6a60000 */

void FUN_2b1a6a60000(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  
  if ((((*param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 1), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



/* Address: 2b1a6a60060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a60060(int *param_1,ulonglong param_2)

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
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2b1a1776bc8);
    if (piVar10 != (int *)0x0) {
      piVar10[1] = 1;
      piVar10[2] = 0;
      *(undefined2 *)(piVar10 + 3) = 0;
      *(int **)(param_1 + 1) = piVar10 + 3;
      *param_1 = *piVar10;
      uVar12 = CONCAT71(uVar13,1);
      goto LAB_2b1a6a601cd;
    }
  }
  else {
    iVar4 = *param_1;
    if (((iVar4 != 0) && ((uint)param_2 <= *puVar14)) &&
       (uVar12 = CONCAT71(uVar13,1), *(int *)(lVar6 + -8) == 1)) goto LAB_2b1a6a601cd;
    piVar10 = (int *)(*(code *)0x7ff63a101190)(0x2b1a1776bc8);
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
        if (uVar15 < 8) goto LAB_2b1a6a60130;
        if ((ulonglong)((longlong)piVar10 - (longlong)puVar14) < 0x20) goto LAB_2b1a6a60130;
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
LAB_2b1a6a60130:
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
          (*(code *)0x7ff63a101200)(0x2b1a1776bc8,puVar14);
        }
      }
      goto LAB_2b1a6a601cd;
    }
  }
  _DAT_2b1a6dcd510 = 0x13aa;
  uVar12 = 0;
LAB_2b1a6a601cd:
  return uVar12 & 0xffffffff;
}



/* Address: 2b1a6a601e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a601e0(int *param_1,longlong param_2,uint param_3)

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
        (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    if (param_3 - 1 < 0xfffffffe) {
      _DAT_2b1a6dcd510 = 0xfa2;
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
    if ((uVar6 <= *puVar5) && (puVar5[1] == 1)) goto LAB_2b1a6a602b7;
    if (*puVar5 != 0) {
      puVar5 = puVar5 + 1;
      *puVar5 = *puVar5 - 1;
      if (*puVar5 == 0) {
        (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
      }
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  piVar3 = (int *)(*(code *)0x7ff63a101190)(0x2b1a1776bc8);
  if (piVar3 == (int *)0x0) {
    _DAT_2b1a6dcd510 = 0x13aa;
    return;
  }
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar4 = piVar3 + 3;
  *(undefined2 *)(piVar3 + 3) = 0;
  *(int **)(param_1 + 1) = piVar4;
  *param_1 = *piVar3;
LAB_2b1a6a602b7:
  if (uVar8 == 0) {
    piVar4[-1] = uVar6;
    *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
    return;
  }
  uVar9 = 0;
  if (uVar8 < 8) goto LAB_2b1a6a60310;
  if ((ulonglong)((longlong)piVar4 - param_2) < 0x20) goto LAB_2b1a6a60310;
  uVar9 = (ulonglong)(uVar6 & 0x7ffffff8);
  uVar10 = 0;
  do {
    uVar2 = ((undefined8 *)(param_2 + uVar10))[1];
    *(undefined8 *)((longlong)piVar4 + uVar10) = *(undefined8 *)(param_2 + uVar10);
    ((undefined8 *)((longlong)piVar4 + uVar10))[1] = uVar2;
    uVar10 = uVar10 + 0x10;
  } while ((uVar7 * 2 & 0xfffffffffffffff0) != uVar10);
  for (; uVar9 != uVar7; uVar9 = uVar9 + 1) {
LAB_2b1a6a60310:
    *(undefined2 *)((longlong)piVar4 + uVar9 * 2) = *(undefined2 *)(param_2 + uVar9 * 2);
  }
  piVar4[-1] = uVar6;
  *(undefined2 *)((longlong)piVar4 + uVar7 * 2) = 0;
  if (0x7ffffffe < uVar8) {
    _DAT_2b1a6dcd510 = 0xfa8;
    return;
  }
  return;
}



/* Address: 2b1a6a603c0 */

ulonglong FUN_2b1a6a603c0(longlong param_1,longlong param_2)

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
  if (param_2 == 0) goto LAB_2b1a6a604cd;
  uVar2 = *(uint *)(param_2 + -4);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(param_1 + 4);
  if ((uVar9 == 0) && (lVar3 != 0)) goto LAB_2b1a6a604cd;
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
  cVar5 = FUN_2b1a6a60060(param_1,uVar6);
  if (cVar5 == '\0') {
    uVar8 = 0;
    goto LAB_2b1a6a604cd;
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
      if (uVar10 == uVar9) goto LAB_2b1a6a604c2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar9 != uVar10);
  }
LAB_2b1a6a604c2:
  *(uint *)(lVar3 + -4) = uVar7;
  *(undefined2 *)(lVar3 + (ulonglong)uVar7 * 2) = 0;
LAB_2b1a6a604cd:
  return uVar8 & 0xffffffff;
}



/* Address: 2b1a6a604e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a604e0(int *param_1,int *param_2,char param_3,undefined8 param_4)

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
        (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
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
        (*(code *)0x7ff63a101200)(0x2b1a1776bc8,piVar13);
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
  piVar13 = (int *)(*(code *)0x7ff63a101190)(0x2b1a1776bc8,uVar15);
  if (piVar13 == (int *)0x0) {
    _DAT_2b1a6dcd510 = 0x13aa;
    (*(code *)0x7ff639cc5c00)(0x2b1a1776bc8,0x1f9,param_4);
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
      if (uVar14 == uVar15) goto LAB_2b1a6a60670;
    }
    do {
      *(undefined2 *)((longlong)piVar1 + uVar14 * 2) = *(undefined2 *)(lVar7 + uVar14 * 2);
      uVar14 = uVar14 + 1;
    } while (uVar15 != uVar14);
  }
LAB_2b1a6a60670:
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
      (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
      return;
    }
  }
  return;
}



/* Address: 2b1a6a60700 */

void FUN_2b1a6a60700(longlong param_1)

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
    (*(code *)0x7ff63a0e6ef0)(0x2b1a1776bc8,lVar2 - *(int *)(lVar2 + -4),0);
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* Address: 2b1a6a607d0 */

undefined8 FUN_2b1a6a607d0(void)

{
  return 0;
}



/* Address: 2b1a6a607e0 */

void FUN_2b1a6a607e0(void)

{
  code *pcVar1;
  
  (*(code *)0x7ff639cc5990)(0x2b1a1776bc8,0x224);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Address: 2b1a6a60830 */

void FUN_2b1a6a60830(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x24) != 0) {
    (*(code *)0x7ff63a0f4ce0)(0x2b1a1776bc8,*(undefined8 *)(param_1 + 0x18),param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x18) = 0;
    FUN_2b1a6a604e0(param_1 + 0x20,0x2b1a6a77f20,0,0x2b1a6ba3680);
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  }
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0x60);
  if (*(longlong *)(param_1 + 0x34) != 0) {
    (*(code *)0x7ff639d9aa30)(0x2b1a1776bc8,param_1 + 0x30);
    FUN_2b1a6a604e0(param_1 + 0x30,0x2b1a6a77f20,0,0x2b1a6ba3690);
  }
  *(undefined8 *)(param_1 + 0x3c) = 0;
  return;
}



/* Address: 2b1a6a60910 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a60910(longlong param_1,longlong param_2,int param_3,int param_4,
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
  FUN_2b1a6a60830();
  if ((0 < param_3) && (0 < param_4)) {
    iVar10 = (*(code *)0x7ff63a0da0e0)(0x2b1a1776bc8,param_1 + 0x60,param_4 * param_3,0);
    if (0 < iVar10) {
      local_a0 = 0;
      local_9c = 0;
      local_94 = param_4;
      local_50 = param_2;
      local_48 = param_1 + 0x60;
      uVar13 = (*(code *)0x7ff63a0f5790)(0x2b1a1776bc8);
      (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,uVar13,0x55,&local_70);
      uVar11 = (*(code *)0x7ff63a3fc2a0)();
      (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,uVar11,0x53,&local_b0);
      FUN_2b1a6a604e0(&local_c0,&local_70);
      lVar14 = local_ac;
      if (local_ac != 0) {
        uVar12 = *(uint *)(local_ac + -4);
        uVar18 = (ulonglong)uVar12;
        if ((uVar18 == 0) && (local_bc != 0)) goto LAB_2b1a6a60bc9;
        if (local_bc == 0) {
          uVar22 = 0;
          uVar21 = uVar12;
        }
        else {
          uVar22 = *(uint *)(local_bc + -4);
          uVar21 = uVar12 + uVar22;
        }
        cVar9 = FUN_2b1a6a60060(&local_c0);
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
              if (uVar15 == uVar18) goto LAB_2b1a6a60bb2;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2b1a6a60bb2:
          *(uint *)(local_bc + -4) = uVar21;
          *(undefined2 *)(local_bc + (ulonglong)uVar21 * 2) = 0;
          goto LAB_2b1a6a60bc9;
        }
LAB_2b1a6a6139c:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x2300ff000201f9);
LAB_2b1a6a613bc:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3e00ff000201f9);
LAB_2b1a6a613dc:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x140101000201f9);
LAB_2b1a6a613fc:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3d0101000201f9);
        pcVar4 = (code *)swi(3);
        uVar18 = (*pcVar4)();
        return uVar18;
      }
LAB_2b1a6a60bc9:
      uVar12 = 0;
      FUN_2b1a6a604e0(&local_90,&local_c0,0,0x2b1a6ba3600);
      uVar22 = _DAT_2b1a6a7813c;
      uVar18 = (ulonglong)_DAT_2b1a6a7813c;
      if ((uVar18 != 0) || (local_8c == 0)) {
        if (local_8c != 0) {
          uVar12 = *(uint *)(local_8c + -4);
        }
        uVar20 = _DAT_2b1a6a7813c + uVar12;
        uVar21 = 0x104;
        if ((0x103 < uVar20) &&
           ((0x7ffffffd < uVar20 || (uVar21 = (uVar20 >> 2) + uVar20, 0x7ffffffd < uVar21)))) {
          uVar21 = 0x7ffffffe;
        }
        cVar9 = FUN_2b1a6a60060(&local_90,uVar21);
        if (cVar9 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3a00ff000201f9);
          goto LAB_2b1a6a6139c;
        }
        if (uVar18 != 0) {
          lVar14 = local_8c + (ulonglong)uVar12 * 2;
          if (uVar22 < 0x10) {
            uVar15 = 0;
          }
          else if (lVar14 - 0x2b1a6a78140U < 0x20) {
            uVar15 = 0;
          }
          else {
            uVar19 = 0;
            uVar15 = (ulonglong)(uVar22 & 0xfffffff8);
            do {
              uVar11 = *(undefined4 *)(&DAT_2b1a6a78144 + uVar19);
              uVar5 = *(undefined4 *)(uVar19 + 0x2b1a6a78148);
              uVar6 = *(undefined4 *)(uVar19 + 0x2b1a6a7814c);
              puVar2 = (undefined4 *)(lVar14 + uVar19);
              *puVar2 = *(undefined4 *)(&DAT_2b1a6a78140 + uVar19);
              puVar2[1] = uVar11;
              puVar2[2] = uVar5;
              puVar2[3] = uVar6;
              uVar19 = uVar19 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar19);
            if (uVar15 == uVar18) goto LAB_2b1a6a60cf2;
          }
          do {
            *(undefined2 *)(lVar14 + uVar15 * 2) = *(undefined2 *)(&DAT_2b1a6a78140 + uVar15 * 2);
            uVar15 = uVar15 + 1;
          } while (uVar18 != uVar15);
        }
LAB_2b1a6a60cf2:
        *(uint *)(local_8c + -4) = uVar20;
        *(undefined2 *)(local_8c + (ulonglong)uVar20 * 2) = 0;
      }
      uVar12 = (*(code *)0x7ff63a0e6780)(0x2b1a1776bc8);
      (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,uVar12 & 0x3ff,0x56,&local_60);
      iVar10 = 0;
      FUN_2b1a6a604e0(&local_80,&local_90,0);
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
          cVar9 = FUN_2b1a6a60060(&local_80);
          if (cVar9 == '\0') goto LAB_2b1a6a613bc;
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
              if (uVar15 == uVar18) goto LAB_2b1a6a60e62;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2b1a6a60e62:
          *(uint *)(local_7c + -4) = uVar21;
          *(undefined2 *)(local_7c + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2b1a6a604e0(&local_a0,&local_80,0,0x2b1a6ba3620);
      iVar8 = local_94;
      if (local_9c == 0) {
        lVar14 = *(longlong *)(local_50 + 4);
        uVar11 = 0xfa9;
        if (lVar14 != 0) goto LAB_2b1a6a60ec4;
LAB_2b1a6a60f2f:
        _DAT_2b1a6dcd510 = uVar11;
        if ((_DAT_2b1a6dcd540 == (undefined2 *)0x0) || (_DAT_2b1a6dcd540 == (undefined2 *)0xc)) {
          _DAT_2b1a6dcd510 = 0xfa9;
        }
        else if ((*(int *)(_DAT_2b1a6dcd540 + -2) != 0) &&
                (cVar9 = FUN_2b1a6a60060(0x2b1a6dcd53c,0), puVar7 = _DAT_2b1a6dcd540, cVar9 != '\0')
                ) {
          *(undefined4 *)(_DAT_2b1a6dcd540 + -2) = 0;
          *puVar7 = 0;
        }
      }
      else {
        if (local_9c != 0xc) {
          iVar10 = *(int *)(local_9c + -4);
        }
        lVar14 = *(longlong *)(local_50 + 4);
        uVar11 = 0xfa9;
        if (lVar14 == 0) goto LAB_2b1a6a60f2f;
LAB_2b1a6a60ec4:
        uVar11 = 0xfa9;
        if (lVar14 == 0xc) goto LAB_2b1a6a60f2f;
        iVar17 = *(int *)(lVar14 + -4);
        if (iVar17 == 0) {
          uVar11 = 0x13ab;
          goto LAB_2b1a6a60f2f;
        }
        iVar16 = 0x3f - iVar10;
        if (-1 < iVar16) {
          if (iVar17 < iVar16) {
            _DAT_2b1a6dcd510 = 0x13ab;
          }
          else {
            uVar11 = _DAT_2b1a6dcd510;
            iVar17 = iVar16;
            if (iVar10 == 0x3f) goto LAB_2b1a6a60f2f;
          }
        }
        FUN_2b1a6a601e0(0x2b1a6dcd53c,lVar14,iVar17);
      }
      FUN_2b1a6a604e0(&local_70,0x2b1a6dcd53c,1,0x2b1a6ba3630);
      FUN_2b1a6a604e0(&local_b0,0x2b1a6a78168,0);
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
          cVar9 = FUN_2b1a6a60060(&local_b0);
          if (cVar9 == '\0') goto LAB_2b1a6a613dc;
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
              if (uVar15 == uVar18) goto LAB_2b1a6a61102;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2b1a6a61102:
          *(uint *)(local_ac + -4) = uVar21;
          *(undefined2 *)(local_ac + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2b1a6a604e0(&local_c0,&local_b0,0);
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
          cVar9 = FUN_2b1a6a60060(&local_c0);
          if (cVar9 == '\0') goto LAB_2b1a6a613fc;
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
              if (uVar15 == uVar18) goto LAB_2b1a6a61232;
            }
            do {
              *(undefined2 *)(lVar1 + uVar15 * 2) = *(undefined2 *)(lVar14 + uVar15 * 2);
              uVar15 = uVar15 + 1;
            } while (uVar18 != uVar15);
          }
LAB_2b1a6a61232:
          *(uint *)(local_bc + -4) = uVar21;
          *(undefined2 *)(local_bc + (ulonglong)uVar21 * 2) = 0;
        }
      }
      FUN_2b1a6a604e0(param_1 + 0x30,&local_c0,0,0x2b1a6ba3660);
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
                        (0x2b1a1776bc8,param_1 + 0x30,local_48,param_3,iVar8,0,0,0,param_5);
      if (cVar9 != '\0') {
        *(int *)(param_1 + 0x3c) = param_3;
        *(int *)(param_1 + 0x40) = iVar8;
        *(undefined4 *)(param_1 + 0x44) = param_5;
        FUN_2b1a6a60000(&local_a0);
        uVar18 = CONCAT71((int7)((ulonglong)param_1 >> 8),1);
        goto LAB_2b1a6a61333;
      }
      FUN_2b1a6a60000(&local_a0);
    }
  }
  FUN_2b1a6a60830(param_1);
  uVar18 = 0;
LAB_2b1a6a61333:
  FUN_2b1a6a60000(&local_70);
  FUN_2b1a6a60000(&local_b0);
  FUN_2b1a6a60000(&local_c0);
  FUN_2b1a6a60000(&local_90);
  FUN_2b1a6a60000(&local_60);
  FUN_2b1a6a60000(&local_80);
  return uVar18 & 0xffffffff;
}



/* Address: 2b1a6a61420 */

void FUN_2b1a6a61420(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0x60);
  FUN_2b1a6a60000(param_1 + 0x48);
  FUN_2b1a6a60000(param_1 + 0x30);
  if ((((*(int *)(param_1 + 0x20) != 0) && (lVar2 = *(longlong *)(param_1 + 0x24), lVar2 != 0)) &&
      ((int *)(lVar2 + -0xc) != (int *)0x0)) && (*(int *)(lVar2 + -0xc) != 0)) {
    piVar1 = (int *)(lVar2 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
    }
  }
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(int *)(param_1 + 0x20) = 0;
  return;
}



/* Address: 2b1a6a614c0 */

void FUN_2b1a6a614c0(longlong param_1)

{
  FUN_2b1a6a6cf10();
  FUN_2b1a6a60000(param_1 + 0x1aa);
  FUN_2b1a6a60000(param_1 + 0x19e);
  FUN_2b1a6a60000(param_1 + 0x192);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0x14e);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0x112);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0xde);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,*(undefined8 *)(param_1 + 0x4a),0x2b1a17b1ee0);
  *(undefined8 *)(param_1 + 0x52) = 0x2b1a6a77e20;
  FUN_2b1a6a61420(param_1 + 0x4a);
  (*(code *)0x7ff63a0e62f0)(0x2b1a1776bc8,*(undefined8 *)(param_1 + 0x4a));
  return;
}



/* Address: 2b1a6a61590 */

undefined4 FUN_2b1a6a61590(longlong param_1,undefined8 param_2,undefined8 param_3)

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
  FUN_2b1a6a604e0(&local_70,0x2b1a6a77f40,0,0x2b1a6ba3b18);
  local_80 = 0;
  local_7c = 0;
  FUN_2b1a6a604e0(&local_80,0x2b1a6a77f40,0,0x2b1a6ba3b28);
  if (*(char *)(param_1 + 0x294) == '\0') {
    pcVar2 = (code *)0x7ff63a108b70;
  }
  else {
    pcVar2 = (code *)0x7ff63a108be0;
  }
  uVar1 = (*pcVar2)(0x2b1a1776bc8,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(int *)(param_1 + 0x2ad) < 1) goto LAB_2b1a6a61762;
    uVar4 = 0x2b1a6ba3b68;
    uVar3 = 0x2b1a6ba3b58;
  }
  else {
    if (*(int *)(param_1 + 0x2ad) < 2) goto LAB_2b1a6a61762;
    uVar4 = 0x2b1a6ba3b48;
    uVar3 = 0x2b1a6ba3b38;
  }
  FUN_2b1a6a72230(&local_80,param_2,param_3);
  FUN_2b1a6a604e0(&local_60,0x2b1a6dcd53c,1,uVar3);
  FUN_2b1a6a72c10(param_1,&local_70,param_2);
  FUN_2b1a6a604e0(&local_50,0x2b1a6dcd53c,1,uVar4);
  (*(code *)0x7ff63a0e49f0)
            (0x2b1a1776bc8,0xd,3,0x590008,0x2b1a6a78b48,0x590008,&local_50,0x590008,&local_60);
LAB_2b1a6a61762:
  FUN_2b1a6a60000(&local_80);
  FUN_2b1a6a60000(&local_70);
  FUN_2b1a6a60000(&local_60);
  FUN_2b1a6a60000(&local_50);
  return uVar1;
}



/* Address: 2b1a6a617a0 */

void FUN_2b1a6a617a0(undefined8 *param_1)

{
  FUN_2b1a6a60000(param_1 + 0x41);
  FUN_2b1a6a60000((longlong)param_1 + 0x144);
  FUN_2b1a6a60000((longlong)param_1 + 0x84);
  FUN_2b1a6a60000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,*param_1,0x2b1a17afe60);
  param_1[1] = 0x2b1a6a77de0;
  return;
}



/* Address: 2b1a6a61810 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a61810(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  char cVar5;
  char cVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined4 uVar18;
  longlong lVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  uint uVar22;
  undefined8 *puVar23;
  undefined4 uVar24;
  undefined8 *puVar25;
  uint uVar26;
  ulonglong uVar27;
  undefined4 uVar28;
  undefined4 local_90;
  longlong local_8c;
  undefined4 local_80;
  longlong local_7c;
  undefined4 local_70;
  longlong local_6c;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_54;
  undefined4 local_50;
  longlong local_4c;
  
  lVar19 = 0;
  lVar14 = 0x4001;
  if (DAT_2b1a6ba6043 == '\0') {
    lVar14 = lVar19;
  }
  _DAT_2b1a6ca4098 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,lVar14,0);
  puVar11 = (undefined8 *)&DAT_2b1a6ba61f0;
  do {
    puVar23 = (undefined8 *)(lVar19 + 0x2b1a6ca4360);
    lVar19 = lVar19 + 0x48;
    puVar25 = puVar11;
    for (lVar14 = 9; lVar14 != 0; lVar14 = lVar14 + -1) {
      *puVar25 = *puVar23;
      puVar23 = puVar23 + 1;
      puVar25 = puVar25 + 1;
    }
    puVar11 = puVar11 + 0x14;
  } while (lVar19 != 0xc888);
  if (_DAT_2b1a6dcd668 == 0) {
    _DAT_2b1a6ba6000 = 1;
  }
  if ((DAT_2b1a6dcd618 != '\x01') ||
     (((iVar9 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,8), iVar9 != 1 ||
       (iVar9 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar9 != 1)) &&
      (iVar9 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar9 != 0)))) goto LAB_2b1a6a6252c;
  lVar14 = _DAT_2b1a6dcd6f0;
  (*(code *)0x7ff63a0da0e0)(0x2b1a1776bc8,&DAT_2b1a6ca422e,0,0);
  uVar3 = _DAT_2b1a6ca4236;
  uVar15 = (ulonglong)_DAT_2b1a6ca4236;
  if (0 < (int)_DAT_2b1a6ca4236) {
    plVar12 = _DAT_2b1a6ca424a;
    if ((_DAT_2b1a6ca4230 & 0x10) == 0) {
      do {
        if (*plVar12 == lVar14) goto LAB_2b1a6a61a04;
        plVar12 = plVar12 + 1;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    else {
      do {
        if (_DAT_2b1a6ca424a[uVar15 - 1] == lVar14) goto LAB_2b1a6a61a04;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
  }
  (*(code *)0x7ff63a0da0e0)(0x2b1a1776bc8,&DAT_2b1a6ca422e,_DAT_2b1a6ca4236 + 1,0);
  uVar15 = (ulonglong)(int)uVar3;
  if (_DAT_2b1a6ca4236 <= uVar15) {
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4700b1000101f6);
LAB_2b1a6a6262a:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3f00be000101f9);
LAB_2b1a6a6264a:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4300be000101f9);
LAB_2b1a6a6266a:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x2600be000101f9);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  uVar17 = (ulonglong)_DAT_2b1a6ca4236 + ~uVar15;
  if ((_DAT_2b1a6ca4230 & 0x10) == 0) {
    uVar17 = uVar15;
  }
  _DAT_2b1a6ca424a[uVar17] = lVar14;
LAB_2b1a6a61a04:
  if (DAT_2b1a6ca42ba != '\0') {
    local_90 = 0;
    local_8c = 0;
    if (_DAT_2b1a6ca4296 != -1) {
      (*(code *)0x7ff63a0eee30)(0x2b1a1776bc8);
    }
    uVar28 = _DAT_2b1a6ca4106;
    _DAT_2b1a6ca4296 = -1;
    if (0 < (int)_DAT_2b1a6ca4236) {
      FUN_2b1a6a6df60(0x2b1a6a77f60);
      FUN_2b1a6a604e0(&local_90,0x2b1a6dcd53c,1,0x2b1a6ba3800);
      _DAT_2b1a6ca4296 =
           (*(code *)0x7ff63a0e49f0)
                     (0x2b1a1776bc8,0x77,5,0x590008,0x2b1a6ca427e,0x520004,1,0x590008,0x2b1a6a78218,
                      0x590008,&local_90,0x520004,uVar28);
    }
    FUN_2b1a6a60000(&local_90);
    _DAT_2b1a6ca42b2 = 0;
  }
  uVar7 = DAT_2b1a6ca40d2;
  cVar6 = DAT_2b1a6ca40d1;
  cVar5 = DAT_2b1a6ca40d0;
  cVar8 = DAT_2b1a6ba6010;
  local_54 = 0;
  if (_DAT_2b1a6dcd788 - 1U < 3) {
    local_54 = *(undefined4 *)((ulonglong)(_DAT_2b1a6dcd788 - 1U) * 4 + 0x2b1a6ba5500);
  }
  local_90 = 0;
  local_50 = 0;
  local_70 = 0;
  local_80 = 0;
  local_60 = 0;
  local_8c = 0;
  local_4c = 0;
  local_6c = 0;
  local_7c = 0;
  local_5c = 0;
  uVar28 = 0;
  if (DAT_2b1a6ba6010 != '\0') {
    uVar28 = 500;
  }
  uVar20 = 10;
  if (DAT_2b1a6ca40d1 == '\0') {
    uVar20 = 0;
  }
  uVar24 = 0x2eee57;
  if (DAT_2b1a6ca40d3 == '\0') {
    uVar24 = 0;
  }
  uVar18 = 0x5959ff;
  if (DAT_2b1a6ca40d4 == '\0') {
    uVar18 = 0;
  }
  uVar21 = 0xd9f0f6;
  if (DAT_2b1a6ca40d5 == '\0') {
    uVar21 = 0;
  }
  FUN_2b1a6a6cf10(&DAT_2b1a6ca40e0);
  DAT_2b1a6ca40f0 = 1;
  DAT_2b1a6ca40f1 = uVar7;
  _DAT_2b1a6ca40fe = 700;
  if (cVar5 == '\0') {
    _DAT_2b1a6ca40fe = 0;
  }
  _DAT_2b1a6ca40f2 = local_54;
  _DAT_2b1a6ca40f6 = _DAT_2b1a6dcd790;
  _DAT_2b1a6ca40fa = _DAT_2b1a6dcd798;
  _DAT_2b1a6ca4106 = 0x1e;
  _DAT_2b1a6ca410e = _DAT_2b1a6dcd7a0;
  _DAT_2b1a6ca4116 = 0x50b7de000c0d0c;
  _DAT_2b1a6ca4102 = uVar20;
  _DAT_2b1a6ca410a = uVar28;
  _DAT_2b1a6ca411e = uVar24;
  _DAT_2b1a6ca4122 = uVar18;
  _DAT_2b1a6ca4126 = uVar21;
  if (((((cVar5 != '\0') && (0.0 < _DAT_2b1a6dcd7a0)) &&
       ((((ulonglong)_DAT_2b1a6dcd7a0 & 0x7ff0000000000000) != 0x7ff0000000000000 &&
        ((-1 < _DAT_2b1a6dcd790 && (-1 < _DAT_2b1a6dcd798)))))) && (cVar6 == '\x01')) &&
     (cVar8 == '\x01')) {
    _DAT_2b1a6ca4262 = (*(code *)0x7ff63a0f5790)(0x2b1a1776bc8);
    (*(code *)0x7ff63a0f5080)(0x2b1a1776bc8,_DAT_2b1a6ca4262);
    FUN_2b1a6a604e0(&local_60,0x2b1a6dcd53c,1,0x2b1a6ba3860);
    FUN_2b1a6a604e0(0x2b1a6ca427e,&local_60,0,0x2b1a6ba3870);
    if (_DAT_2b1a6ca4282 != &DAT_2b1a6a77f38) {
      if (_DAT_2b1a6ca4282 != (undefined1 *)0x0) {
        uVar3 = *(uint *)(_DAT_2b1a6ca4282 + -4);
        uVar26 = _DAT_2b1a6a77f34;
        if (uVar3 < _DAT_2b1a6a77f34) {
          uVar26 = uVar3;
        }
        iVar9 = uVar3 - _DAT_2b1a6a77f34;
        if (uVar26 != 0) {
          uVar15 = 0;
          do {
            uVar1 = *(ushort *)(_DAT_2b1a6ca4282 + uVar15 * 2);
            uVar2 = *(ushort *)(&DAT_2b1a6a77f38 + uVar15 * 2);
            uVar15 = uVar15 + 1;
            if (uVar26 <= uVar15) break;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar9 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar9 == 0) goto LAB_2b1a6a624c6;
      }
      cVar8 = (*(code *)0x7ff639d9ac40)
                        (0x2b1a1776bc8,0x2b1a6a782b8,&DAT_2b1a6ca41be,&DAT_2b1a6ca4226,
                         &DAT_2b1a6ca422a);
      if (((cVar8 != '\0') && (1 < _DAT_2b1a6ca4226)) && (1 < _DAT_2b1a6ca422a)) {
        iVar9 = 0;
        do {
          uVar13 = (*(code *)0x7ff63a3fbf90)();
          (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,uVar13,0x56,&local_60);
          FUN_2b1a6a604e0(&local_80,0x2b1a6a78308,0);
          lVar14 = local_5c;
          if (local_5c != 0) {
            uVar3 = *(uint *)(local_5c + -4);
            uVar15 = (ulonglong)uVar3;
            if ((uVar15 != 0) || (local_7c == 0)) {
              if (local_7c == 0) {
                uVar26 = 0;
                uVar22 = uVar3;
              }
              else {
                uVar26 = *(uint *)(local_7c + -4);
                uVar22 = uVar3 + uVar26;
              }
              cVar8 = FUN_2b1a6a60060(&local_80);
              if (cVar8 == '\0') goto LAB_2b1a6a6266a;
              if (uVar15 != 0) {
                lVar19 = local_7c + (ulonglong)uVar26 * 2;
                if (uVar3 < 8) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar19 - lVar14) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar27 = 0;
                  uVar17 = (ulonglong)(uVar3 & 0xfffffff8);
                  do {
                    uVar13 = ((undefined8 *)(lVar14 + uVar27))[1];
                    *(undefined8 *)(lVar19 + uVar27) = *(undefined8 *)(lVar14 + uVar27);
                    ((undefined8 *)(lVar19 + uVar27))[1] = uVar13;
                    uVar27 = uVar27 + 0x10;
                  } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar27);
                  if (uVar17 == uVar15) goto LAB_2b1a6a62132;
                }
                do {
                  *(undefined2 *)(lVar19 + uVar17 * 2) = *(undefined2 *)(lVar14 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar15 != uVar17);
              }
LAB_2b1a6a62132:
              *(uint *)(local_7c + -4) = uVar22;
              *(undefined2 *)(local_7c + (ulonglong)uVar22 * 2) = 0;
            }
          }
          FUN_2b1a6a604e0(&local_70,&local_80,0,0x2b1a6ba3890);
          uVar3 = _DAT_2b1a6a7831c;
          uVar15 = (ulonglong)_DAT_2b1a6a7831c;
          if ((uVar15 != 0) || (local_6c == 0)) {
            if (local_6c == 0) {
              uVar26 = 0;
              uVar22 = _DAT_2b1a6a7831c;
            }
            else {
              uVar26 = *(uint *)(local_6c + -4);
              uVar22 = _DAT_2b1a6a7831c + uVar26;
            }
            uVar16 = 0x104;
            if ((0x103 < uVar22) &&
               ((0x7ffffffd < uVar22 || (uVar16 = (uVar22 >> 2) + uVar22, 0x7ffffffd < uVar16)))) {
              uVar16 = 0x7ffffffe;
            }
            cVar8 = FUN_2b1a6a60060(&local_70,uVar16);
            if (cVar8 == '\0') goto LAB_2b1a6a6262a;
            if (uVar15 != 0) {
              lVar14 = local_6c + (ulonglong)uVar26 * 2;
              if (uVar3 < 8) {
                uVar17 = 0;
              }
              else if (local_6c + -0x2b1a6a78320 + (ulonglong)uVar26 * 2 < 0x20) {
                uVar17 = 0;
              }
              else {
                uVar27 = 0;
                uVar17 = (ulonglong)(uVar3 & 0xfffffff8);
                do {
                  uVar13 = *(undefined8 *)(uVar27 + 0x2b1a6a78328);
                  puVar11 = (undefined8 *)(lVar14 + uVar27);
                  *puVar11 = *(undefined8 *)(&DAT_2b1a6a78320 + uVar27);
                  puVar11[1] = uVar13;
                  uVar27 = uVar27 + 0x10;
                } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar27);
                if (uVar17 == uVar15) goto LAB_2b1a6a62282;
              }
              do {
                *(undefined2 *)(lVar14 + uVar17 * 2) =
                     *(undefined2 *)(&DAT_2b1a6a78320 + uVar17 * 2);
                uVar17 = uVar17 + 1;
              } while (uVar15 != uVar17);
            }
LAB_2b1a6a62282:
            *(uint *)(local_6c + -4) = uVar22;
            *(undefined2 *)(local_6c + (ulonglong)uVar22 * 2) = 0;
          }
          (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,(longlong)iVar9,0x52,&local_50);
          FUN_2b1a6a604e0(&local_90,&local_70,0);
          lVar14 = local_4c;
          if (local_4c != 0) {
            uVar3 = *(uint *)(local_4c + -4);
            uVar15 = (ulonglong)uVar3;
            if ((uVar15 != 0) || (local_8c == 0)) {
              if (local_8c == 0) {
                uVar26 = 0;
                uVar22 = uVar3;
              }
              else {
                uVar26 = *(uint *)(local_8c + -4);
                uVar22 = uVar3 + uVar26;
              }
              cVar8 = FUN_2b1a6a60060(&local_90);
              if (cVar8 == '\0') goto LAB_2b1a6a6264a;
              if (uVar15 != 0) {
                lVar19 = local_8c + (ulonglong)uVar26 * 2;
                if (uVar3 < 8) {
                  uVar17 = 0;
                }
                else if ((ulonglong)(lVar19 - lVar14) < 0x20) {
                  uVar17 = 0;
                }
                else {
                  uVar27 = 0;
                  uVar17 = (ulonglong)(uVar3 & 0xfffffff8);
                  do {
                    uVar13 = ((undefined8 *)(lVar14 + uVar27))[1];
                    *(undefined8 *)(lVar19 + uVar27) = *(undefined8 *)(lVar14 + uVar27);
                    ((undefined8 *)(lVar19 + uVar27))[1] = uVar13;
                    uVar27 = uVar27 + 0x10;
                  } while ((uVar15 * 2 & 0xfffffffffffffff0) != uVar27);
                  if (uVar17 == uVar15) goto LAB_2b1a6a61f79;
                }
                do {
                  *(undefined2 *)(lVar19 + uVar17 * 2) = *(undefined2 *)(lVar14 + uVar17 * 2);
                  uVar17 = uVar17 + 1;
                } while (uVar15 != uVar17);
              }
LAB_2b1a6a61f79:
              *(uint *)(local_8c + -4) = uVar22;
              *(undefined2 *)(local_8c + (ulonglong)uVar22 * 2) = 0;
            }
          }
          FUN_2b1a6a604e0(&DAT_2b1a6ca4272,&local_90,0,0x2b1a6ba38b0);
          iVar9 = iVar9 + 1;
          iVar10 = (*(code *)0x7ff63a0f4840)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272);
        } while (-1 < iVar10);
        _DAT_2b1a6ca426a = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0);
        (*(code *)0x7ff63a0c7410)(0x2b1a1776bc8,3);
        FUN_2b1a6a604e0(&local_60,0x2b1a6dcd53c,1,0x2b1a6ba38c0);
        FUN_2b1a6a604e0(&DAT_2b1a6ca428a,&local_60,0,0x2b1a6ba38d0);
        DAT_2b1a6ca42ba = '\x01';
        _DAT_2b1a6ca42a2 = 0;
        _DAT_2b1a6ca42b2 = 0;
        cVar8 = FUN_2b1a6a6f2c0();
        if (cVar8 == '\0') {
          FUN_2b1a6a6cf10(&DAT_2b1a6ca40e0);
        }
        else {
          FUN_2b1a6a6f180();
          FUN_2b1a6a640d0(1);
        }
      }
    }
  }
LAB_2b1a6a624c6:
  FUN_2b1a6a60000(&local_60);
  FUN_2b1a6a60000(&local_80);
  FUN_2b1a6a60000(&local_70);
  FUN_2b1a6a60000(&local_50);
  FUN_2b1a6a60000(&local_90);
  uVar13 = 0;
  if (DAT_2b1a6ba6010 != '\0') {
    uVar13 = 500;
  }
  (*(code *)0x7ff63a0e7280)(0x2b1a1776bc8,uVar13);
LAB_2b1a6a6252c:
  lVar14 = _DAT_2b1a6ca40c8;
  lVar19 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,0);
  if (lVar14 != lVar19) {
    _DAT_2b1a6ca4078 = FUN_2b1a6a62690();
    _DAT_2b1a6ca40c8 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,0);
  }
  (*(code *)0x7ff63a0e21f0)(0x2b1a1776bc8,1);
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
  (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,0x2b1a6a77f40);
  return;
}



/* Address: 2b1a6a62690 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_2b1a6a62690(void)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  byte bVar12;
  uint uVar13;
  int iVar14;
  double dVar15;
  bool bVar16;
  double dVar17;
  uint local_84;
  uint local_80;
  undefined1 local_60 [4];
  int local_5c;
  int local_54;
  uint local_48;
  
  iVar6 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
  if (iVar6 == 0) {
    iVar6 = (*(code *)0x7ff63a101e20)(0x2b1a1776bc8,0);
    iVar9 = (*(code *)0x7ff63a101ce0)(0x2b1a1776bc8,0);
    dVar17 = (double)(iVar9 - iVar6) / _DAT_2b1a6a777e0;
    uVar13 = (uint)((ulonglong)dVar17 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar13 - 0x3ff;
    if ((ulonglong)uVar13 < 0x433) {
      if (uVar13 < 0x3ff) {
        dVar15 = (double)((ulonglong)dVar17 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar15 = (double)((ulonglong)dVar17 & 0x8000000000000000);
        }
        return (int)dVar15;
      }
      bVar12 = (byte)lVar1;
      if (((longlong)dVar17 << (bVar12 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar17 = (double)((0x8000000000000U >> (bVar12 & 0x3f)) + (longlong)dVar17 &
                         -0x10000000000000 >> (bVar12 & 0x3f));
      }
    }
    else if (lVar1 == 0x400) {
      dVar17 = dVar17 + dVar17;
    }
    iVar6 = (int)dVar17;
  }
  else {
    iVar7 = (*(code *)0x7ff63a102a30)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001);
    iVar6 = 3;
    iVar9 = 10000;
    if (iVar7 < 10000) {
      iVar9 = iVar7;
    }
    iVar14 = 2;
    if (1 < iVar7) {
      bVar2 = false;
      iVar6 = 1;
      local_80 = 0xffffffff;
      local_84 = 0xffffffff;
      bVar3 = false;
      iVar7 = -1;
      iVar8 = -1;
      do {
        uVar10 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,iVar6);
        iVar6 = iVar6 + 1;
        uVar11 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,iVar6);
        (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar10,local_60);
        uVar13 = local_48;
        (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar11,local_60);
        uVar4 = local_48;
        (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar10,local_60);
        iVar14 = local_54;
        (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar10,local_60);
        bVar16 = uVar4 - 5 < 2;
        if ((local_5c - 4U < 6 && uVar13 < 2) && bVar16) {
          bVar2 = true;
          local_84 = uVar13;
          iVar7 = iVar14;
        }
        if ((local_5c - 0xbU < 0xfffffff8 && uVar13 < 2) && bVar16) {
          local_80 = uVar13;
          iVar8 = iVar14;
          bVar3 = true;
        }
        if ((bVar3) && (bVar2)) {
          bVar2 = true;
          break;
        }
      } while (iVar9 != iVar6);
      if (bVar3) {
        iVar6 = 3;
        iVar14 = 2;
        if (bVar2) {
          iVar9 = iVar7 + -0x16;
          if (local_84 != 0) {
            iVar9 = 99;
          }
          iVar6 = iVar7 + 2;
          if (local_84 != 1) {
            iVar6 = iVar9;
          }
          iVar9 = iVar8 + -0x17;
          if (local_80 != 0) {
            iVar9 = 99;
          }
          iVar14 = iVar8 + 1;
          if (local_80 != 1) {
            iVar14 = iVar9;
          }
        }
      }
      else {
        iVar6 = 3;
        iVar14 = 2;
      }
    }
    uVar10 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
    cVar5 = FUN_2b1a6a752a0(uVar10);
    if (cVar5 == '\0') {
      iVar6 = iVar14;
    }
  }
  return iVar6;
}



/* Address: 2b1a6a62a20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a62a20(void)

{
  double dVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  code *pcVar7;
  double dVar8;
  double dVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  char cVar14;
  char cVar15;
  int iVar16;
  longlong lVar17;
  undefined8 uVar18;
  longlong lVar19;
  undefined8 uVar20;
  int iVar21;
  undefined4 uVar22;
  uint uVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined4 local_3f8;
  undefined8 local_3f4;
  undefined4 local_3e8;
  longlong local_3e4;
  double local_3d8;
  undefined8 local_3d0;
  undefined4 local_3c8;
  undefined8 local_3c4;
  double local_3b8;
  double local_3b0;
  longlong local_3a8;
  int local_3a0;
  undefined4 uStack_39c;
  undefined8 local_398;
  undefined8 local_390;
  undefined8 local_388;
  undefined4 local_36c;
  undefined8 local_368;
  undefined4 local_31c;
  undefined8 local_318;
  undefined4 local_25c;
  undefined8 local_258;
  undefined4 local_198;
  undefined8 local_194;
  
  local_3c8 = 0;
  local_3f8 = 0;
  local_3c4 = 0;
  local_3f4 = 0;
  if ((DAT_2b1a6dcd618 == '\x01') &&
     (((iVar16 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,8), iVar16 == 1 &&
       (iVar16 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar16 == 1)) ||
      (iVar16 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar16 == 0)))) {
    FUN_2b1a6a640d0(0);
  }
  if (((DAT_2b1a6dcd670 == '\x01') && (_DAT_2b1a6ca4074 != 0)) &&
     ((_DAT_2b1a6ca40c0 != 0 &&
      (lVar17 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0),
      (longlong)_DAT_2b1a6dcd678 <= lVar17 - _DAT_2b1a6ca40c0)))) {
    FUN_2b1a6a604e0(&local_3f8,0x2b1a6dcd528,1,0x2b1a6a7a3f0);
    FUN_2b1a6a667d0(_DAT_2b1a6ca4074,&local_3f8);
    _DAT_2b1a6ca4074 = 0;
    _DAT_2b1a6ca40c0 = 0;
  }
  iVar16 = FUN_2b1a6a68520();
  if (((iVar16 == 0xf5) && (iVar16 = FUN_2b1a6a68550(), 0x13 < iVar16)) ||
     ((iVar16 = FUN_2b1a6a68520(), iVar16 == 0xf6 ||
      ((iVar16 = FUN_2b1a6a68520(), iVar16 == 0xf7 ||
       ((*(code *)0x7ff63a101c40)(0x2b1a1776bc8,&local_3a0), local_3a0 < 0x7e0))))))
  goto LAB_2b1a6a63f68;
  (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0);
  _DAT_2b1a6ba6048 = _DAT_2b1a6dcd748 * _DAT_2b1a6a777e8;
  _DAT_2b1a6ba6050 = _DAT_2b1a6a777e8 * _DAT_2b1a6dcd750;
  iVar16 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
  if ((iVar16 == 1) && (((DAT_2b1a6ca4071 & 1) == 0 && (3 < (int)_DAT_2b1a6dcd520)))) {
    DAT_2b1a6ca4071 = 1;
    FUN_2b1a6a604e0(&local_3f8,0x2b1a6dcd528,1,0x2b1a6a7a400);
    FUN_2b1a6a667d0(1,&local_3f8);
    FUN_2b1a6a68580();
  }
  uVar18 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
  cVar14 = FUN_2b1a6a68c80(uVar18);
  if (cVar14 != '\0') {
    local_3e8 = 0;
    local_3e4 = 0;
    iVar16 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x35);
    if (iVar16 == 0) {
      FUN_2b1a6a604e0(&local_3e8,0x2b1a6dcd528,1,0x2b1a6ba47d8);
      cVar14 = (*(code *)0x7ff63a107f20)(0x2b1a1776bc8,&local_3e8);
      if (cVar14 != '\0') {
        (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,3);
        if ((_DAT_2b1a6dcd548 != _DAT_2b1a6a777f0) ||
           (NAN(_DAT_2b1a6dcd548) || NAN(_DAT_2b1a6a777f0))) goto LAB_2b1a6a62d82;
      }
    }
    else {
LAB_2b1a6a62d82:
      (*(code *)0x7ff63a0e4490)(0x2b1a1776bc8,0x2b1a170ac50,&local_3a0);
      (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,CONCAT44(uStack_39c,local_3a0),0x2b1a17978d0);
      local_398 = 0x2b1a6a77da0;
      local_390 = 0;
      local_388 = 0;
      local_36c = 0;
      local_368 = 0;
      local_31c = 0;
      local_318 = 0;
      local_25c = 0;
      local_258 = 0;
      local_198 = 0;
      local_194 = 0;
      FUN_2b1a6a71490(&local_3a0);
      iVar16 = (*(code *)0x7ff63a107da0)(0x2b1a1776bc8);
      cVar14 = DAT_2b1a6dcd768;
      _DAT_2b1a6ba6160 = 0.0;
      _DAT_2b1a6ba6158 = 0.0;
      _DAT_2b1a6ba61a8 = 0;
      if (-1 < iVar16 + -1) {
        local_3a8 = _DAT_2b1a6dcd6f0;
        local_3b0 = _DAT_2b1a6dcd770;
        local_3b8 = _DAT_2b1a6dcd778;
        local_3d8 = _DAT_2b1a6dcd780;
        iVar16 = iVar16 + -1;
        do {
          do {
            uVar18 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar16);
            cVar15 = (*(code *)0x7ff63a107ee0)(0x2b1a1776bc8,uVar18);
          } while (cVar15 == '\0');
          uVar18 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar16);
          cVar15 = (*(code *)0x7ff63a107ee0)(0x2b1a1776bc8,uVar18);
          if (cVar15 == '\x01') {
            local_3d0 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar16);
            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,4);
            dVar26 = _DAT_2b1a6dcd548;
            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,1);
            dVar27 = _DAT_2b1a6dcd548;
            (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,6);
            dVar28 = _DAT_2b1a6dcd548;
            (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,7);
            dVar11 = _DAT_2b1a6dcd548;
            (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,10);
            dVar12 = _DAT_2b1a6dcd548;
            (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,4);
            dVar13 = _DAT_2b1a6dcd548;
            lVar17 = (*(code *)0x7ff63a107fc0)(0x2b1a1776bc8,2);
            lVar19 = (*(code *)0x7ff63a107fc0)(0x2b1a1776bc8,0xc);
            if (lVar19 == local_3a8) {
              (*(code *)0x7ff63a108010)(0x2b1a1776bc8,0);
              FUN_2b1a6a604e0(&local_3e8,0x2b1a6dcd53c,1,0x2b1a6ba47e8);
              if (_DAT_2b1a6dcd52c == local_3e4) {
LAB_2b1a6a63128:
                _DAT_2b1a6ba61a8 = _DAT_2b1a6ba61a8 + 1;
                dVar30 = *(double *)((ulonglong)(_DAT_2b1a6dcd520 == 3) * 8 + 0x2b1a6a777f8);
                dVar8 = local_3b8 * dVar30;
                dVar30 = dVar30 * local_3b0;
                dVar9 = dVar30;
                if (lVar17 == 0) {
                  if ((dVar30 <= 0.0) || (cVar14 != '\x01')) {
LAB_2b1a6a63369:
                    dVar27 = _DAT_2b1a6ba6160;
                    (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,3);
                    _DAT_2b1a6ba6160 = dVar27 + _DAT_2b1a6dcd548;
                    goto LAB_2b1a6a63398;
                  }
                  if (((dVar28 == 0.0) && (!NAN(dVar28))) || (dVar28 < dVar13)) {
                    if ((_DAT_2b1a6dcd518 != 0.0) || (NAN(_DAT_2b1a6dcd518))) {
                      dVar32 = dVar8 * _DAT_2b1a6dcd518 + dVar13;
                      dVar29 = dVar13;
                      if ((longlong)dVar32 != -0x8000000000000000) {
                        dVar31 = (double)(longlong)dVar32;
                        uVar25 = (ulonglong)_DAT_2b1a6dcd520;
                        if (10 < _DAT_2b1a6dcd520) {
                          uVar25 = 0xb;
                        }
                        dVar1 = *(double *)(uVar25 * 8 + 0x2b1a6a77d20);
                        dVar32 = (double)(longlong)
                                         ((dVar32 - dVar31) * dVar1 +
                                         *(double *)((ulonglong)(0.0 < dVar32) * 8 + 0x2b1a6a77808))
                                 / dVar1 + dVar31;
                      }
                      goto LAB_2b1a6a632ed;
                    }
                  }
                  else {
                    if ((_DAT_2b1a6dcd518 != 0.0) || (NAN(_DAT_2b1a6dcd518))) {
                      dVar9 = (dVar30 - dVar8) + local_3d8;
                      dVar32 = local_3d8 * _DAT_2b1a6dcd518 + dVar28;
                      dVar29 = dVar28;
                      if ((longlong)dVar32 != -0x8000000000000000) {
                        dVar31 = (double)(longlong)dVar32;
                        uVar25 = (ulonglong)_DAT_2b1a6dcd520;
                        if (10 < _DAT_2b1a6dcd520) {
                          uVar25 = 0xb;
                        }
                        dVar1 = *(double *)(uVar25 * 8 + 0x2b1a6a77d20);
                        dVar32 = (double)(longlong)
                                         ((dVar32 - dVar31) * dVar1 +
                                         *(double *)((ulonglong)(0.0 < dVar32) * 8 + 0x2b1a6a77808))
                                 / dVar1 + dVar31;
                      }
LAB_2b1a6a632ed:
                      if ((0.0 < dVar12) && (dVar9 <= (dVar27 - dVar29) / _DAT_2b1a6dcd518)) {
                        if (((dVar32 != dVar28) || (NAN(dVar32) || NAN(dVar28))) &&
                           (((_DAT_2b1a6dcd518 * dVar8 + dVar13 < dVar27 &&
                             (cVar15 = FUN_2b1a6a754b0(0,dVar32,dVar11), cVar15 != '\0')) &&
                            ((dVar32 != 0.0 || (NAN(dVar32))))))) {
                          FUN_2b1a6a71f30(&local_3a0,local_3d0,dVar32);
                        }
                      }
                      goto LAB_2b1a6a63369;
                    }
LAB_2b1a6a64024:
                    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1a06a3000001f7);
                  }
                  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x19069d000001f7);
                  goto LAB_2b1a6a64064;
                }
LAB_2b1a6a63398:
                lVar17 = (*(code *)0x7ff63a107fc0)(0x2b1a1776bc8,2);
                if (lVar17 == 1) {
                  if ((0.0 < dVar30) && (cVar14 == '\x01')) {
                    if (((dVar28 == 0.0) && (!NAN(dVar28))) || (dVar13 < dVar28)) {
                      if ((_DAT_2b1a6dcd518 == 0.0) && (!NAN(_DAT_2b1a6dcd518)))
                      goto LAB_2b1a6a64004;
                      dVar27 = dVar13 - dVar8 * _DAT_2b1a6dcd518;
                      dVar30 = dVar13;
                      if ((longlong)dVar27 != -0x8000000000000000) {
                        dVar32 = (double)(longlong)dVar27;
                        uVar25 = (ulonglong)_DAT_2b1a6dcd520;
                        if (10 < _DAT_2b1a6dcd520) {
                          uVar25 = 0xb;
                        }
                        dVar29 = *(double *)(uVar25 * 8 + 0x2b1a6a77d20);
                        dVar27 = (double)(longlong)
                                         ((dVar27 - dVar32) * dVar29 +
                                         *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x2b1a6a77808))
                                 / dVar29 + dVar32;
                      }
                    }
                    else {
                      if ((_DAT_2b1a6dcd518 == 0.0) && (!NAN(_DAT_2b1a6dcd518))) {
                        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1806da000001f7);
LAB_2b1a6a64004:
                        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1806d4000001f7);
                        goto LAB_2b1a6a64024;
                      }
                      dVar9 = (dVar30 - dVar8) + local_3d8;
                      dVar27 = dVar28 - local_3d8 * _DAT_2b1a6dcd518;
                      dVar30 = dVar28;
                      if ((longlong)dVar27 != -0x8000000000000000) {
                        dVar32 = (double)(longlong)dVar27;
                        uVar25 = (ulonglong)_DAT_2b1a6dcd520;
                        if (10 < _DAT_2b1a6dcd520) {
                          uVar25 = 0xb;
                        }
                        dVar29 = *(double *)(uVar25 * 8 + 0x2b1a6a77d20);
                        dVar27 = (double)(longlong)
                                         ((dVar27 - dVar32) * dVar29 +
                                         *(double *)((ulonglong)(0.0 < dVar27) * 8 + 0x2b1a6a77808))
                                 / dVar29 + dVar32;
                      }
                    }
                    if ((0.0 < dVar12) && (dVar9 <= (dVar30 - dVar26) / _DAT_2b1a6dcd518)) {
                      if ((((dVar27 != dVar28) || (NAN(dVar27) || NAN(dVar28))) &&
                          ((dVar26 < dVar13 - dVar8 * _DAT_2b1a6dcd518 &&
                           (cVar15 = FUN_2b1a6a754b0(1,dVar27,dVar11), cVar15 != '\0')))) &&
                         ((dVar27 != 0.0 || (NAN(dVar27))))) {
                        FUN_2b1a6a71f30(&local_3a0,local_3d0,dVar27);
                      }
                    }
                  }
                  dVar26 = _DAT_2b1a6ba6158;
                  (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,3);
                  _DAT_2b1a6ba6158 = dVar26 + _DAT_2b1a6dcd548;
                }
              }
              else if ((_DAT_2b1a6dcd52c != 0) && (local_3e4 != 0)) {
                uVar4 = *(uint *)(_DAT_2b1a6dcd52c + -4);
                uVar5 = *(uint *)(local_3e4 + -4);
                uVar23 = uVar5;
                if (uVar4 < uVar5) {
                  uVar23 = uVar4;
                }
                iVar21 = uVar4 - uVar5;
                if (uVar23 != 0) {
                  uVar25 = 1;
                  do {
                    uVar2 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar25 * 2);
                    uVar3 = *(ushort *)(local_3e4 + -2 + uVar25 * 2);
                    if (uVar23 <= uVar25) break;
                    uVar25 = uVar25 + 1;
                  } while (uVar2 == uVar3);
                  if (uVar2 != uVar3) {
                    iVar21 = (uint)uVar2 - (uint)uVar3;
                  }
                }
                if (iVar21 == 0) goto LAB_2b1a6a63128;
              }
            }
          }
          bVar6 = 0 < iVar16;
          iVar16 = iVar16 + -1;
        } while (bVar6);
      }
      iVar16 = (*(code *)0x7ff63a1081a0)(0x2b1a1776bc8);
      if (iVar16 != 0) {
        iVar21 = 0;
        do {
          (*(code *)0x7ff63a1081f0)(0x2b1a1776bc8,iVar21);
          iVar21 = iVar21 + 1;
        } while (iVar16 != iVar21);
      }
      FUN_2b1a6a75210(&local_3a0);
    }
    FUN_2b1a6a60000(&local_3e8);
  }
  iVar16 = FUN_2b1a6a68dc0();
  if (((((iVar16 == 1) && ((DAT_2b1a6ba6024 & 1) == 0)) ||
       ((iVar16 == 2 && ((DAT_2b1a6ba6025 & 1) == 0)))) ||
      ((iVar16 == 3 && ((DAT_2b1a6ba6026 & 1) == 0)))) ||
     (((iVar16 == 4 && ((DAT_2b1a6ba6027 & 1) == 0)) ||
      ((iVar16 == 5 && ((DAT_2b1a6ba6028 & 1) == 0)))))) goto LAB_2b1a6a63f68;
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,4);
  dVar26 = _DAT_2b1a6dcd548;
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,1);
  if ((_DAT_2b1a6dcd518 != 0.0) || (NAN(_DAT_2b1a6dcd518))) {
    dVar26 = (dVar26 - _DAT_2b1a6dcd548) / _DAT_2b1a6dcd518;
    if (_DAT_2b1a6dcd520 == 3) {
      dVar26 = dVar26 / _DAT_2b1a6a777e8;
    }
    if (dVar26 <= (double)_DAT_2b1a6dcd6d0) {
      if ((dVar26 <= (double)_DAT_2b1a6dcd6d0) && ((DAT_2b1a6ca4072 & 1) != 0)) {
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,0x2b1a6a77f40);
        DAT_2b1a6ca4072 = 0;
      }
      iVar16 = FUN_2b1a6a68dc0();
      cVar14 = DAT_2b1a6dcd630;
      if ((((iVar16 == 5) && (DAT_2b1a6dcd630 == '\x01')) && (0 < _DAT_2b1a6ba61a8)) &&
         (cVar15 = FUN_2b1a6a68df0(5), cVar15 != '\0')) {
        FUN_2b1a6a68580();
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,3,1,0x590008,0x2b1a6a780a8);
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a780a8);
      }
      iVar16 = FUN_2b1a6a68dc0();
      if (((iVar16 == 5) && (cVar14 == '\x01')) && (cVar14 = FUN_2b1a6a68df0(5), cVar14 != '\0'))
      goto LAB_2b1a6a63f68;
      iVar16 = FUN_2b1a6a68dc0();
      cVar14 = DAT_2b1a6dcd640;
      if (((iVar16 == 3) && (DAT_2b1a6dcd640 == '\x01')) &&
         ((0 < _DAT_2b1a6ba61a8 && (cVar15 = FUN_2b1a6a68df0(3), cVar15 != '\0')))) {
        FUN_2b1a6a68580();
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,3,1,0x590008,0x2b1a6a78100);
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a78100);
      }
      iVar16 = FUN_2b1a6a68dc0();
      if (((iVar16 == 3) && (cVar14 == '\x01')) && (cVar14 = FUN_2b1a6a68df0(3), cVar14 != '\0'))
      goto LAB_2b1a6a63f68;
      if (DAT_2b1a6ba61a4 == '\0') {
        FUN_2b1a6a68f10();
        DAT_2b1a6ba61a4 = '\x01';
      }
      FUN_2b1a6a68550();
      lVar17 = _DAT_2b1a6ca4090;
      if (DAT_2b1a6dcd7b8 == '\x01') {
        lVar19 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,1,0);
        if (lVar17 != lVar19) {
          _DAT_2b1a6ca4090 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,1,0);
          cVar14 = FUN_2b1a6a69bf0();
          (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,&DAT_2b1a6ca4080);
          if (cVar14 != '\0') {
            DAT_2b1a6ca4070 = '\x01';
            goto LAB_2b1a6a63f68;
          }
          goto LAB_2b1a6a63be4;
        }
        if (DAT_2b1a6ca4070 != '\0') goto LAB_2b1a6a63f68;
      }
      else {
LAB_2b1a6a63be4:
        DAT_2b1a6ca4070 = '\0';
      }
      if ((0 < _DAT_2b1a6ca40a8) && (0 < _DAT_2b1a6ca40b0)) {
        lVar17 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
        if ((_DAT_2b1a6ca40a8 <= lVar17) &&
           (lVar17 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0), lVar17 <= _DAT_2b1a6ca40b0))
        goto LAB_2b1a6a63f68;
        _DAT_2b1a6ca40a8 = 0;
        _DAT_2b1a6ca40b0 = 0;
      }
      cVar14 = FUN_2b1a6a6bb50();
      if (cVar14 == '\0') {
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,0x2b1a6a77f40);
        goto LAB_2b1a6a63f68;
      }
      uVar22 = 0x4001;
      uVar18 = 0;
      if (DAT_2b1a6ba6043 != '\0') {
        uVar18 = 0x4001;
      }
      dVar26 = (double)FUN_2b1a6a6be50(7,uVar18,(uint)DAT_2b1a6ba6042 + (uint)DAT_2b1a6ba6042 * 4);
      uVar24 = 0x32;
      if (DAT_2b1a6ba6045 == '\0') {
        uVar24 = 0;
      }
      if (DAT_2b1a6ba6046 == '\0') {
        uVar22 = 0;
      }
      FUN_2b1a6a6be50(1,uVar22,uVar24);
      uVar24 = 0x13;
      if (DAT_2b1a6ba603d == '\0') {
        uVar24 = 0;
      }
      uVar20 = 0x4004;
      if (DAT_2b1a6ba603e == '\0') {
        uVar20 = 0;
      }
      dVar27 = (double)FUN_2b1a6a6bfd0(uVar20,uVar24);
      if ((_DAT_2b1a6dcd518 == 0.0) && (!NAN(_DAT_2b1a6dcd518))) goto LAB_2b1a6a640a4;
      dVar28 = 0.0;
      if (DAT_2b1a6ba6044 != '\0') {
        dVar28 = _DAT_2b1a6a77818;
      }
      dVar27 = dVar27 / _DAT_2b1a6dcd518;
      if ((dVar28 <= dVar26) ||
         (lVar17 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,uVar18,0),
         lVar17 == _DAT_2b1a6ca4098)) {
LAB_2b1a6a63e7c:
        bVar10 = _DAT_2b1a6a77828 < dVar26;
        bVar6 = _DAT_2b1a6a77828 < dVar27;
      }
      else {
        dVar28 = _DAT_2b1a6a77820;
        if (DAT_2b1a6ba603f == '\0') {
          dVar28 = 0.0;
        }
        if (dVar28 <= dVar27) goto LAB_2b1a6a63e7c;
        bVar6 = _DAT_2b1a6a77828 < dVar27;
        bVar10 = _DAT_2b1a6a77828 < dVar26;
        if ((_DAT_2b1a6a77828 < dVar26) && (_DAT_2b1a6a77828 < dVar27)) {
          _DAT_2b1a6ca4098 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,uVar18,0);
          bVar6 = true;
          if ((DAT_2b1a6dcd700 == '\x01') || (DAT_2b1a6dcd700 == '\0' && DAT_2b1a6dcd6f8 == '\0')) {
            FUN_2b1a6a6c0f0(0xffffffff);
          }
          bVar10 = true;
        }
      }
      dVar28 = _DAT_2b1a6a77830;
      if (DAT_2b1a6ba6044 == '\0') {
        dVar28 = 0.0;
      }
      if ((dVar28 < dVar26) &&
         (lVar17 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,uVar18,0),
         lVar17 != _DAT_2b1a6ca4098)) {
        dVar26 = _DAT_2b1a6a77820;
        if (DAT_2b1a6ba603f == '\0') {
          dVar26 = 0.0;
        }
        if (((bool)(bVar6 & bVar10 & dVar27 < dVar26)) &&
           ((_DAT_2b1a6ca4098 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,uVar18,0),
            DAT_2b1a6dcd6f8 == '\x01' || (DAT_2b1a6dcd6f8 == '\0' && DAT_2b1a6dcd700 == '\0')))) {
          FUN_2b1a6a6c0f0(1);
        }
      }
LAB_2b1a6a63f68:
      FUN_2b1a6a60000(&local_3f8);
      FUN_2b1a6a60000(&local_3c8);
      return;
    }
    (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,dVar26,0);
    FUN_2b1a6a604e0(&local_3f8,0x2b1a6dcd53c,1,0x2b1a6a7a410);
    FUN_2b1a6a604e0(&local_3c8,0x2b1a6a78058,0,0x2b1a6a7a420);
    cVar14 = FUN_2b1a6a603c0(&local_3c8,local_3f4);
    if (cVar14 != '\0') {
      (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,&local_3c8);
      DAT_2b1a6ca4072 = 1;
      goto LAB_2b1a6a63f68;
    }
  }
  else {
LAB_2b1a6a64064:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x190594000001f7);
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1d059d000001f9);
LAB_2b1a6a640a4:
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x230615000001f7);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



/* Address: 2b1a6a640d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a640d0(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  uint *puVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  ulonglong uVar28;
  bool bVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  int iVar32;
  undefined4 uVar33;
  undefined8 uVar34;
  bool bVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  ulonglong in_stack_fffffffffffffd28;
  undefined8 in_stack_fffffffffffffd30;
  undefined4 in_stack_fffffffffffffd40;
  undefined8 in_stack_fffffffffffffd48;
  undefined4 uVar41;
  undefined4 local_278;
  longlong local_274;
  undefined4 local_268;
  longlong local_264;
  ulonglong local_258;
  ulonglong local_250;
  uint local_244;
  undefined8 local_240;
  ulonglong local_238;
  ulonglong local_230;
  undefined4 local_228;
  undefined1 *local_224;
  undefined4 local_218;
  undefined8 local_214;
  undefined4 local_208;
  longlong local_204;
  undefined4 local_1f8;
  longlong local_1f4;
  undefined4 local_1e8;
  longlong local_1e4;
  undefined4 local_1d8;
  longlong local_1d4;
  uint local_1cc;
  double local_1c8;
  double local_1c0;
  double local_1b8;
  undefined4 local_1b0;
  undefined8 local_1ac;
  double local_1a0;
  undefined4 local_198;
  undefined8 local_194;
  undefined8 local_18c;
  undefined8 local_184;
  double *local_17c;
  undefined8 local_174;
  undefined8 local_16c;
  undefined4 local_160;
  undefined8 local_15c;
  undefined8 local_154;
  undefined8 local_14c;
  double *local_144;
  undefined8 local_13c;
  undefined8 local_134;
  undefined4 local_128;
  undefined8 local_124;
  undefined8 local_11c;
  undefined8 local_114;
  double *local_10c;
  undefined8 local_104;
  undefined8 local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined8 local_e4;
  undefined8 local_dc;
  double *local_d4;
  undefined8 local_cc;
  undefined8 local_c4;
  double local_b0;
  double local_a8;
  
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffd30 >> 0x20);
  local_1d8 = 0;
  local_268 = 0;
  local_278 = 0;
  local_1f8 = 0;
  local_208 = 0;
  local_228 = 0;
  local_1e8 = 0;
  local_218 = 0;
  local_1d4 = 0;
  local_264 = 0;
  local_274 = 0;
  local_1f4 = 0;
  local_204 = 0;
  local_224 = (undefined1 *)0x0;
  local_1e4 = 0;
  local_214 = 0;
  if ((DAT_2b1a6ca42ba == '\0') ||
     (((lVar11 = (*(code *)0x7ff63a3fbf90)(), param_1 == '\0' && (_DAT_2b1a6ca42b2 != 0)) &&
      ((ulonglong)(lVar11 - _DAT_2b1a6ca42b2) < (ulonglong)_DAT_2b1a6ca410a))))
  goto LAB_2b1a6a666dd;
  _DAT_2b1a6ca42b2 = lVar11;
  lVar11 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0);
  local_1f8 = 0;
  local_1f4 = 0;
  (*(code *)0x7ff63a0f5080)(0x2b1a1776bc8,_DAT_2b1a6ca4262);
  FUN_2b1a6a604e0(&local_278,0x2b1a6dcd53c,1,0x2b1a6ba38e0);
  FUN_2b1a6a604e0(&local_1f8,&local_278,0,0x2b1a6ba38f0);
  local_208 = 0;
  local_204 = 0;
  (*(code *)0x7ff63a0c7410)(0x2b1a1776bc8,3);
  FUN_2b1a6a604e0(&local_278,0x2b1a6dcd53c,1,0x2b1a6ba3900);
  FUN_2b1a6a604e0(&local_208,&local_278,0,0x2b1a6ba3910);
  if (lVar11 == _DAT_2b1a6ca426a) {
    if (local_1f4 != _DAT_2b1a6ca4282) {
      if ((local_1f4 != 0) && (_DAT_2b1a6ca4282 != 0)) {
        uVar27 = *(uint *)(local_1f4 + -4);
        uVar16 = *(uint *)(_DAT_2b1a6ca4282 + -4);
        uVar18 = uVar16;
        if (uVar27 < uVar16) {
          uVar18 = uVar27;
        }
        iVar8 = uVar27 - uVar16;
        if (uVar18 != 0) {
          uVar31 = 1;
          do {
            uVar1 = *(ushort *)(local_1f4 + -2 + uVar31 * 2);
            uVar2 = *(ushort *)(_DAT_2b1a6ca4282 + -2 + uVar31 * 2);
            if (uVar18 <= uVar31) break;
            uVar31 = uVar31 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar8 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar8 == 0) goto LAB_2b1a6a643ad;
      }
      goto LAB_2b1a6a6443d;
    }
LAB_2b1a6a643ad:
    if (local_204 != _DAT_2b1a6ca428e) {
      if ((local_204 != 0) && (_DAT_2b1a6ca428e != 0)) {
        uVar27 = *(uint *)(local_204 + -4);
        uVar16 = *(uint *)(_DAT_2b1a6ca428e + -4);
        uVar18 = uVar16;
        if (uVar27 < uVar16) {
          uVar18 = uVar27;
        }
        iVar8 = uVar27 - uVar16;
        if (uVar18 != 0) {
          uVar31 = 1;
          do {
            uVar1 = *(ushort *)(local_204 + -2 + uVar31 * 2);
            uVar2 = *(ushort *)(_DAT_2b1a6ca428e + -2 + uVar31 * 2);
            if (uVar18 <= uVar31) break;
            uVar31 = uVar31 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar8 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar8 == 0) goto LAB_2b1a6a64592;
      }
      goto LAB_2b1a6a6443d;
    }
  }
  else {
LAB_2b1a6a6443d:
    _DAT_2b1a6ca426a = lVar11;
    FUN_2b1a6a604e0(0x2b1a6ca427e,&local_1f8,0,0x2b1a6ba3920);
    FUN_2b1a6a604e0(&DAT_2b1a6ca428a,&local_208,0,0x2b1a6ba3930);
    local_1b0 = 0;
    local_1ac = 0;
    if (_DAT_2b1a6ca4296 != -1) {
      (*(code *)0x7ff63a0eee30)(0x2b1a1776bc8);
    }
    uVar41 = _DAT_2b1a6ca4106;
    _DAT_2b1a6ca4296 = -1;
    if (0 < _DAT_2b1a6ca4236) {
      FUN_2b1a6a6df60(0x2b1a6a77f60);
      FUN_2b1a6a604e0(&local_1b0,0x2b1a6dcd53c,1,0x2b1a6ba3800);
      in_stack_fffffffffffffd28 = 0x2b1a6ca427e;
      in_stack_fffffffffffffd40 = 0x590008;
      uVar34 = CONCAT44(uVar33,0x520004);
      in_stack_fffffffffffffd48 = 0x2b1a6a78218;
      _DAT_2b1a6ca4296 =
           (*(code *)0x7ff63a0e49f0)
                     (0x2b1a1776bc8,0x77,5,0x590008,0x2b1a6ca427e,uVar34,1,0x590008,0x2b1a6a78218,
                      0x590008,&local_1b0,0x520004,uVar41);
      uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
    }
    FUN_2b1a6a60000(&local_1b0);
  }
LAB_2b1a6a64592:
  if (((((DAT_2b1a6ca42bb != '\0') ||
        (iVar9 = (*(code *)0x7ff63a0f4840)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272),
        iVar8 = _DAT_2b1a6ca429a, iVar9 < 0)) ||
       (iVar10 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6a,0),
       iVar9 = _DAT_2b1a6ca429e, iVar8 != iVar10)) ||
      (iVar8 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6b,0), iVar9 != iVar8)) &&
     (cVar7 = FUN_2b1a6a6f2c0(), cVar7 == '\0')) {
LAB_2b1a6a666c7:
    FUN_2b1a6a60000(&local_208);
    FUN_2b1a6a60000(&local_1f8);
LAB_2b1a6a666dd:
    FUN_2b1a6a60000(&local_278);
    FUN_2b1a6a60000(&local_268);
    FUN_2b1a6a60000(&local_1d8);
    return;
  }
  in_stack_fffffffffffffd28 = in_stack_fffffffffffffd28 & 0xffffffff00000000;
  (*(code *)0x7ff63a0c7470)
            (0x2b1a1776bc8,&DAT_2b1a6ca418a,&DAT_2b1a6ca41f2,0,in_stack_fffffffffffffd28,
             CONCAT44(uVar33,0xffffffff));
  uVar33 = (undefined4)(in_stack_fffffffffffffd28 >> 0x20);
  iVar8 = (*(code *)0x7ff63a0f0700)(0x2b1a1776bc8,8);
  iVar9 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,4);
  lVar11 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x21);
  lVar12 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x22);
  iVar10 = (*(code *)0x7ff63a0f0700)(0x2b1a1776bc8,6);
  bVar35 = true;
  if (iVar10 == 0) {
    iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
    bVar35 = iVar10 != 0;
  }
  uVar34 = 0x2b1a6a78380;
  local_250 = CONCAT71(local_250._1_7_,iVar9 != 0);
  if (iVar8 != 0) {
    uVar34 = 0x2b1a6a783b8;
  }
  local_258._0_1_ = iVar8 != 0;
  lVar13 = (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,0x2b1a6ca427e,0x1e);
  uVar19 = 0x2b1a6a78350;
  local_228 = 0;
  local_224 = (undefined1 *)0x0;
  if (((bVar35) && (uVar19 = uVar34, iVar8 != 0)) &&
     ((iVar9 != 0 && ((uVar19 = 0x2b1a6a783f8, lVar11 != 0 && (lVar12 != 0)))))) {
    uVar19 = 0x2b1a6a78470;
    if (lVar13 == 3) {
      uVar19 = 0x2b1a6a78438;
    }
    if (lVar13 == 0) {
      uVar19 = 0x2b1a6a78438;
    }
  }
  FUN_2b1a6a604e0(&local_228,uVar19,0,0x2b1a6ba3940);
  if (local_224 == &DAT_2b1a6a7845c) {
LAB_2b1a6a648cc:
    puVar14 = (uint *)&DAT_2b1a6ca411e;
  }
  else {
    puVar14 = (uint *)&DAT_2b1a6ca4122;
    if (local_224 != (undefined1 *)0x0) {
      uVar27 = *(uint *)(local_224 + -4);
      uVar16 = _DAT_2b1a6a78458;
      if (uVar27 < _DAT_2b1a6a78458) {
        uVar16 = uVar27;
      }
      iVar8 = uVar27 - _DAT_2b1a6a78458;
      if (uVar16 != 0) {
        uVar31 = 0;
        do {
          uVar1 = *(ushort *)(local_224 + uVar31 * 2);
          uVar2 = *(ushort *)(&DAT_2b1a6a7845c + uVar31 * 2);
          uVar31 = uVar31 + 1;
          if (uVar16 <= uVar31) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar8 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar8 == 0) goto LAB_2b1a6a648cc;
    }
  }
  dVar37 = _DAT_2b1a6a77838 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77840 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77848 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77850;
  uVar27 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  uVar27 = *puVar14;
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,CONCAT44(uVar33,0xc2011));
  dVar37 = _DAT_2b1a6a77858 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77860 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77868 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  local_240 = CONCAT44(local_240._4_4_,uVar27);
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77870;
  uVar16 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,uVar27);
  dVar37 = _DAT_2b1a6a77878 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77880 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77888 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77890;
  uVar16 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      uVar27 = (uint)local_240;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,0x61008);
  dVar37 = _DAT_2b1a6a77898 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  iVar8 = 1;
  if (1 < (int)dVar38) {
    iVar8 = (int)dVar38;
  }
  dVar37 = _DAT_2b1a6a778a0 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  local_258._0_1_ = (byte)local_258 & (byte)local_250;
  dVar39 = _DAT_2b1a6ca42bc * _DAT_2b1a6a778a8;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  uVar27 = uVar27 << 0x10 | uVar27 & 0xff00 | uVar27 >> 0x10 & 0xff | 0xff000000;
  local_250 = (ulonglong)(uint)(int)dVar38;
  local_230 = (ulonglong)(uint)(int)dVar37;
  iVar10 = 0;
  local_238 = (ulonglong)(uint)(iVar8 * -2);
  iVar32 = 1 - iVar8;
  iVar23 = 0;
  local_258 = CONCAT71(local_258._1_7_,(byte)local_258 & (lVar11 != 0 && lVar12 != 0));
  iVar9 = 3;
  local_244 = uVar27;
  do {
    iVar25 = iVar8 + (int)local_230;
    iVar22 = (int)local_250;
    iVar21 = (int)local_230 - iVar8;
    FUN_2b1a6a6de10(iVar21,iVar25,iVar22 + iVar23,uVar27);
    FUN_2b1a6a6de10(iVar21,iVar25,iVar22 + iVar10,uVar27);
    if (-1 < iVar32) {
      iVar21 = (int)local_230 + iVar10;
      iVar22 = (int)local_230 + iVar23;
      iVar25 = (int)local_250;
      FUN_2b1a6a6de10(iVar22,iVar21,iVar25 - iVar8,uVar27);
      FUN_2b1a6a6de10(iVar22,iVar21,iVar8 + iVar25,uVar27);
      iVar8 = iVar8 + -1;
      iVar32 = iVar32 + 2 + (int)local_238;
      local_238 = (ulonglong)((int)local_238 + 2);
    }
    iVar10 = iVar10 + 1;
    iVar23 = iVar23 + -1;
    iVar32 = iVar32 + iVar9;
    iVar9 = iVar9 + 2;
  } while (iVar10 <= iVar8);
  uVar33 = CONCAT31((int3)((uint)in_stack_fffffffffffffd40 >> 8),1);
  FUN_2b1a6a70350(&local_228,_DAT_2b1a6a778b0,_DAT_2b1a6a778b8,_DAT_2b1a6a778a0,0x4044000000000000,
                  0x4044000000000000,(uint)local_240,uVar33);
  local_240 = 0x2b1a6a784c8;
  if ((byte)local_258 != 0) {
    local_240 = 0x2b1a6a78498;
  }
  local_1cc = *(uint *)(&DAT_2b1a6ca411e + (ulonglong)((byte)local_258 ^ 1) * 4);
  dVar37 = _DAT_2b1a6a778c0 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  uVar31 = 1;
  if (1 < (int)dVar38) {
    uVar31 = (ulonglong)(uint)(int)dVar38;
  }
  dVar37 = _DAT_2b1a6a778c8 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6ca42bc * _DAT_2b1a6a778d0;
  uVar27 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  uVar27 = local_1cc << 0x10 | local_1cc & 0xff00 | local_1cc >> 0x10 & 0xff | 0xff000000;
  local_258 = (ulonglong)(uint)(int)dVar38;
  local_230 = (ulonglong)(uint)(int)dVar37;
  iVar9 = 0;
  iVar23 = 0;
  local_238 = (ulonglong)(uint)((int)uVar31 * -2);
  iVar10 = 1 - (int)uVar31;
  iVar8 = 3;
  local_244 = uVar27;
  do {
    iVar32 = (int)uVar31 + (int)local_230;
    iVar21 = (int)local_258;
    iVar22 = (int)local_230 - (int)uVar31;
    local_250 = uVar31;
    FUN_2b1a6a6de10(iVar22,iVar32,iVar9 + iVar21,uVar27);
    FUN_2b1a6a6de10(iVar22,iVar32,iVar21 + iVar23,uVar27);
    uVar31 = local_250;
    if (-1 < iVar10) {
      iVar22 = (int)local_230 + iVar9;
      iVar32 = (int)local_230 + iVar23;
      iVar25 = (int)local_250;
      FUN_2b1a6a6de10(iVar22,iVar32,iVar21 - iVar25,uVar27);
      FUN_2b1a6a6de10(iVar22,iVar32,iVar25 + iVar21,uVar27);
      iVar10 = iVar10 + 2 + (int)local_238;
      local_238 = (ulonglong)((int)local_238 + 2);
      uVar31 = (ulonglong)(iVar25 - 1);
    }
    uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
    iVar23 = iVar23 + 1;
    iVar10 = iVar10 + iVar8;
    iVar9 = iVar9 + -1;
    iVar8 = iVar8 + 2;
  } while (iVar23 <= (int)uVar31);
  uVar27 = CONCAT31((int3)((uint)uVar33 >> 8),1);
  uVar33 = 0x40490000;
  FUN_2b1a6a70350(local_240,_DAT_2b1a6a778d8,_DAT_2b1a6a778e0,_DAT_2b1a6a778e8,0x4049000000000000,
                  0x4045000000000000,local_1cc,uVar27);
  if (_DAT_2b1a6ca4296 == -1) {
    bVar35 = false;
    bVar29 = false;
  }
  else {
    local_17c = &local_1b8;
    local_198 = 0x1000058;
    uVar34 = CONCAT44(uVar33,1);
    local_194 = 0x100000008;
    local_18c = 0;
    local_184 = 0x100000000;
    local_174 = 0;
    local_16c = 0;
    iVar8 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,0,0,uVar34,&local_198);
    uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
    if (iVar8 == 1) {
      local_160 = 0x1000058;
      local_15c = 0x100000008;
      local_154 = 0;
      local_14c = 0x100000000;
      uVar34 = CONCAT44(uVar33,1);
      local_144 = &local_1a0;
      local_13c = 0;
      local_134 = 0;
      iVar8 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,1,0,uVar34,&local_160);
      uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
      bVar15 = 1;
      if (iVar8 != 1) goto LAB_2b1a6a65849;
    }
    else {
LAB_2b1a6a65849:
      bVar15 = 0;
    }
    local_128 = 0x1000058;
    local_124 = 0x100000008;
    local_11c = 0;
    local_114 = 0x100000000;
    local_10c = &local_1c0;
    local_104 = 0;
    local_fc = 0;
    bVar35 = _DAT_2b1a6a778f0 < local_1a0;
    iVar8 = (*(code *)0x7ff63a0eeec0)
                      (0x2b1a1776bc8,_DAT_2b1a6ca4296,2,0,CONCAT44(uVar33,1),&local_128);
    if (iVar8 == 1) {
      local_d4 = &local_1c8;
      local_f0 = 0x1000058;
      local_ec = 0x100000008;
      local_e4 = 0;
      local_dc = 0x100000000;
      bVar5 = false;
      local_cc = 0;
      local_c4 = 0;
      iVar8 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,3,0,1,&local_f0);
      if (iVar8 != 1) goto LAB_2b1a6a6597b;
    }
    else {
LAB_2b1a6a6597b:
      bVar5 = true;
    }
    if ((bool)(bVar35 & bVar15)) {
      bVar29 = local_1b8 != _DAT_2b1a6a778f8 && (~(ulonglong)local_1b8 & 0x7ff0000000000000) != 0;
    }
    else {
      bVar29 = false;
    }
    if (bVar5) {
      bVar35 = false;
    }
    else {
      bVar35 = (local_1c0 != _DAT_2b1a6a778f8 && local_1c8 != _DAT_2b1a6a778f8) &&
               (~(ulonglong)local_1c0 & 0x7ff0000000000000) != 0;
    }
  }
  uVar33 = _DAT_2b1a6ca4126;
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
  FUN_2b1a6a6e3b0(_DAT_2b1a6dcd548,0);
  puVar24 = &local_278;
  FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3950);
  uVar19 = _DAT_2b1a6a77908;
  uVar34 = _DAT_2b1a6a77900;
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,_DAT_2b1a6a77900,_DAT_2b1a6a77908,_DAT_2b1a6a77910,0x404a000000000000,
                  0x4045000000000000,uVar33,uVar27);
  uVar33 = _DAT_2b1a6ca4126;
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x28);
  FUN_2b1a6a6e3b0(_DAT_2b1a6dcd548,0);
  FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3960);
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77918,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  if (bVar35) {
    lVar11 = 0x3e;
    if (local_1c0 <= _DAT_2b1a6a77928) {
      lVar11 = (ulonglong)(_DAT_2b1a6a77920 <= local_1c0) * 4 + 0x42;
    }
    uVar33 = *(undefined4 *)(&DAT_2b1a6ca40e0 + lVar11);
    FUN_2b1a6a6e3b0(local_1c0,1);
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3970);
  }
  else {
    puVar24 = (undefined4 *)0x2b1a6a78508;
    uVar33 = _DAT_2b1a6ca4126;
  }
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77930,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  if (bVar29) {
    lVar11 = 0x3e;
    if (local_1b8 <= _DAT_2b1a6a77928) {
      lVar11 = (ulonglong)(_DAT_2b1a6a77920 <= local_1b8) * 4 + 0x42;
    }
    uVar33 = *(undefined4 *)(&DAT_2b1a6ca40e0 + lVar11);
    FUN_2b1a6a6e3b0(local_1b8,1);
    puVar24 = &local_278;
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3980);
  }
  else {
    puVar24 = (undefined4 *)0x2b1a6a78558;
    uVar33 = _DAT_2b1a6ca4126;
  }
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77938,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  local_1e8 = 0;
  local_1e4 = 0;
  if (_DAT_2b1a6ca4236 < 1) {
    puVar24 = (undefined4 *)0x2b1a6a785c8;
  }
  else {
    FUN_2b1a6a6df60(0x2b1a6a78588);
    puVar24 = &local_278;
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3990);
  }
  FUN_2b1a6a604e0(&local_1e8,puVar24,0,0x2b1a6ba39a0);
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(&local_1e8,uVar34,uVar19,_DAT_2b1a6a77940,0x404a000000000000,0x4044000000000000,
                  _DAT_2b1a6ca4126,uVar27);
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6ca427e);
  dVar38 = _DAT_2b1a6dcd548;
  local_218 = 0;
  local_214 = 0;
  FUN_2b1a6a604e0(&local_218,0x2b1a6a78600,0,0x2b1a6ba39b0);
  if ((((dVar38 <= 0.0) ||
       (cVar7 = (*(code *)0x7ff63a0f2c10)(0x2b1a1776bc8,0x2b1a6ca427e), cVar7 == '\0')) ||
      (local_a8 < local_b0)) || (local_b0 <= 0.0)) {
LAB_2b1a6a660c0:
    uVar27 = uVar27 & 0xffffff00;
    FUN_2b1a6a70350(&local_218,uVar34,uVar19,_DAT_2b1a6a77948,0x404a000000000000,0x4044000000000000,
                    _DAT_2b1a6ca4126,uVar27);
    uVar33 = _DAT_2b1a6ca4126;
    if (DAT_2b1a6ca40f1 != '\0') {
      if (bVar35) {
        puVar24 = &local_278;
        (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,(longlong)(int)local_1c8,0x52,puVar24);
      }
      else {
        puVar24 = (undefined4 *)0x2b1a6a78508;
      }
      uVar27 = uVar27 & 0xffffff00;
      FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77950,0x404a000000000000,0x4045000000000000,
                      uVar33,uVar27);
    }
    lVar11 = (*(code *)0x7ff63a101ce0)(0x2b1a1776bc8,0);
    uVar33 = _DAT_2b1a6ca4126;
    if (lVar11 < 1) {
      puVar24 = (undefined4 *)0x2b1a6a78508;
    }
    else {
      (*(code *)0x7ff63a0fcc50)(0x2b1a1776bc8,lVar11,3);
      puVar24 = &local_278;
      FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba39f0);
    }
    uVar31 = 0x4044000000000000;
    FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77958,0x404a000000000000,0x4044000000000000,
                    uVar33,uVar27 & 0xffffff00);
    FUN_2b1a6a604e0(&local_278,0x2b1a6a78670);
    lVar11 = local_1e4;
    if (local_1e4 == 0) {
LAB_2b1a6a6636d:
      uVar27 = 0;
      FUN_2b1a6a604e0(&local_268,&local_278,0,0x2b1a6ba3a10);
      uVar16 = _DAT_2b1a6a78688;
      uVar28 = (ulonglong)_DAT_2b1a6a78688;
      if ((uVar28 != 0) || (local_264 == 0)) {
        if (local_264 != 0) {
          uVar27 = *(uint *)(local_264 + -4);
        }
        uVar17 = _DAT_2b1a6a78688 + uVar27;
        uVar18 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_2b1a6a60060(&local_268,uVar18);
        if (cVar7 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x5500f1000101f9);
          goto LAB_2b1a6a6674b;
        }
        if (uVar28 != 0) {
          lVar11 = local_264 + (ulonglong)uVar27 * 2;
          if (uVar16 < 0x10) {
            uVar20 = 0;
          }
          else if (lVar11 - 0x2b1a6a7868cU < 0x20) {
            uVar20 = 0;
          }
          else {
            uVar30 = 0;
            uVar20 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar34 = *(undefined8 *)(uVar30 + 0x2b1a6a78694);
              *(undefined8 *)(lVar11 + uVar30) = *(undefined8 *)(&DAT_2b1a6a7868c + uVar30);
              ((undefined8 *)(lVar11 + uVar30))[1] = uVar34;
              uVar30 = uVar30 + 0x10;
            } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
            if (uVar20 == uVar28) goto LAB_2b1a6a66492;
          }
          do {
            *(undefined2 *)(lVar11 + uVar20 * 2) = *(undefined2 *)(&DAT_2b1a6a7868c + uVar20 * 2);
            uVar20 = uVar20 + 1;
          } while (uVar28 != uVar20);
        }
LAB_2b1a6a66492:
        *(uint *)(local_264 + -4) = uVar17;
        *(undefined2 *)(local_264 + (ulonglong)uVar17 * 2) = 0;
      }
      FUN_2b1a6a604e0(&local_1d8,&local_268,0);
      puVar6 = local_224;
      if (local_224 != (undefined1 *)0x0) {
        uVar27 = *(uint *)(local_224 + -4);
        uVar28 = (ulonglong)uVar27;
        if ((uVar28 != 0) || (local_1d4 == 0)) {
          if (local_1d4 == 0) {
            uVar16 = 0;
            uVar18 = uVar27;
          }
          else {
            uVar16 = *(uint *)(local_1d4 + -4);
            uVar18 = uVar27 + uVar16;
          }
          cVar7 = FUN_2b1a6a60060(&local_1d8);
          if (cVar7 == '\0') goto LAB_2b1a6a6676b;
          if (uVar28 != 0) {
            lVar11 = local_1d4 + (ulonglong)uVar16 * 2;
            if (uVar27 < 0x10) {
              uVar20 = 0;
            }
            else if ((ulonglong)(lVar11 - (longlong)puVar6) < 0x20) {
              uVar20 = 0;
            }
            else {
              uVar30 = 0;
              uVar20 = (ulonglong)(uVar27 & 0xfffffff8);
              do {
                uVar34 = *(undefined8 *)((longlong)(puVar6 + uVar30) + 8);
                *(undefined8 *)(lVar11 + uVar30) = *(undefined8 *)(puVar6 + uVar30);
                ((undefined8 *)(lVar11 + uVar30))[1] = uVar34;
                uVar30 = uVar30 + 0x10;
              } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
              if (uVar20 == uVar28) goto LAB_2b1a6a665c2;
            }
            do {
              *(undefined2 *)(lVar11 + uVar20 * 2) = *(undefined2 *)(puVar6 + uVar20 * 2);
              uVar20 = uVar20 + 1;
            } while (uVar28 != uVar20);
          }
LAB_2b1a6a665c2:
          *(uint *)(local_1d4 + -4) = uVar18;
          *(undefined2 *)(local_1d4 + (ulonglong)uVar18 * 2) = 0;
        }
      }
      (*(code *)0x7ff63a0f3c80)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0xce,&local_1d8);
      if ((_DAT_2b1a6ca415e != 0) &&
         (cVar7 = (*(code *)0x7ff639d98020)
                            (0x2b1a1776bc8,&DAT_2b1a6ca415a,&DAT_2b1a6ca418a,_DAT_2b1a6ca4166,
                             _DAT_2b1a6ca416a,uVar31 & 0xffffffff00000000,0,0,
                             CONCAT44(uVar41,_DAT_2b1a6ca416e)), cVar7 != '\0')) {
        (*(code *)0x7ff63a0f51b0)(0x2b1a1776bc8,_DAT_2b1a6ca4142);
      }
      FUN_2b1a6a60000(&local_218);
      FUN_2b1a6a60000(&local_1e8);
      FUN_2b1a6a60000(&local_228);
      goto LAB_2b1a6a666c7;
    }
    uVar27 = *(uint *)(local_1e4 + -4);
    uVar28 = (ulonglong)uVar27;
    if ((uVar28 == 0) && (local_274 != 0)) goto LAB_2b1a6a6636d;
    if (local_274 == 0) {
      uVar20 = 0;
      uVar16 = uVar27;
    }
    else {
      uVar20 = (ulonglong)*(uint *)(local_274 + -4);
      uVar16 = uVar27 + *(uint *)(local_274 + -4);
    }
    cVar7 = FUN_2b1a6a60060(&local_278);
    if (cVar7 != '\0') {
      if (uVar28 != 0) {
        lVar12 = local_274 + uVar20 * 2;
        if (uVar27 < 0x10) {
          uVar20 = 0;
        }
        else if ((ulonglong)(lVar12 - lVar11) < 0x20) {
          uVar20 = 0;
        }
        else {
          uVar30 = 0;
          uVar20 = (ulonglong)(uVar27 & 0xfffffff8);
          do {
            uVar34 = ((undefined8 *)(lVar11 + uVar30))[1];
            *(undefined8 *)(lVar12 + uVar30) = *(undefined8 *)(lVar11 + uVar30);
            ((undefined8 *)(lVar12 + uVar30))[1] = uVar34;
            uVar30 = uVar30 + 0x10;
          } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
          if (uVar20 == uVar28) goto LAB_2b1a6a66362;
        }
        do {
          *(undefined2 *)(lVar12 + uVar20 * 2) = *(undefined2 *)(lVar11 + uVar20 * 2);
          uVar20 = uVar20 + 1;
        } while (uVar28 != uVar20);
      }
LAB_2b1a6a66362:
      *(uint *)(local_274 + -4) = uVar16;
      *(undefined2 *)(local_274 + (ulonglong)uVar16 * 2) = 0;
      goto LAB_2b1a6a6636d;
    }
LAB_2b1a6a6674b:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4f00f1000101f9);
LAB_2b1a6a6676b:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x5b00f1000101f9);
  }
  else if ((dVar38 != 0.0) || (NAN(dVar38))) {
    uVar16 = 0;
    (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,(local_a8 - local_b0) / dVar38,0);
    FUN_2b1a6a604e0(&local_278,0x2b1a6dcd53c,1,0x2b1a6ba39c0);
    FUN_2b1a6a604e0(&local_268,&local_278,0,0x2b1a6ba39d0);
    uVar18 = _DAT_2b1a6a78618;
    uVar31 = (ulonglong)_DAT_2b1a6a78618;
    if ((uVar31 != 0) || (local_264 == 0)) {
      if (local_264 != 0) {
        uVar16 = *(uint *)(local_264 + -4);
      }
      uVar26 = _DAT_2b1a6a78618 + uVar16;
      uVar17 = 0x104;
      if ((0x103 < uVar26) &&
         ((0x7ffffffd < uVar26 || (uVar17 = (uVar26 >> 2) + uVar26, 0x7ffffffd < uVar17)))) {
        uVar17 = 0x7ffffffe;
      }
      cVar7 = FUN_2b1a6a60060(&local_268,uVar17);
      if (cVar7 == '\0') goto LAB_2b1a6a667ab;
      if (uVar31 != 0) {
        lVar11 = local_264 + (ulonglong)uVar16 * 2;
        if (uVar18 < 0x10) {
          uVar28 = 0;
        }
        else if (lVar11 - 0x2b1a6a7861cU < 0x20) {
          uVar28 = 0;
        }
        else {
          uVar20 = 0;
          uVar28 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar4 = *(undefined8 *)(uVar20 + 0x2b1a6a78624);
            *(undefined8 *)(lVar11 + uVar20) = *(undefined8 *)(&DAT_2b1a6a7861c + uVar20);
            ((undefined8 *)(lVar11 + uVar20))[1] = uVar4;
            uVar20 = uVar20 + 0x10;
          } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar20);
          if (uVar28 == uVar31) goto LAB_2b1a6a66082;
        }
        do {
          *(undefined2 *)(lVar11 + uVar28 * 2) = *(undefined2 *)(&DAT_2b1a6a7861c + uVar28 * 2);
          uVar28 = uVar28 + 1;
        } while (uVar31 != uVar28);
      }
LAB_2b1a6a66082:
      *(uint *)(local_264 + -4) = uVar26;
      *(undefined2 *)(local_264 + (ulonglong)uVar26 * 2) = 0;
    }
    FUN_2b1a6a604e0(&local_218,&local_268,0,0x2b1a6ba39e0);
    goto LAB_2b1a6a660c0;
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3200ec000101f7);
LAB_2b1a6a667ab:
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3b00ec000101f9);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 2b1a6a667d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a667d0(int param_1,undefined8 param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  code *pcVar7;
  bool bVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  longlong lVar12;
  byte bVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  undefined1 *puVar19;
  longlong lVar20;
  double dVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  longlong lVar24;
  bool bVar25;
  ulonglong uVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  double dVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 local_3d8;
  longlong local_3d4;
  uint local_3cc;
  undefined4 local_3c8;
  longlong local_3c4;
  undefined4 local_3b8;
  short *local_3b4;
  longlong local_3a8;
  undefined8 local_3a0;
  longlong local_398;
  undefined4 local_390;
  undefined8 local_38c;
  int local_384;
  longlong local_380;
  longlong local_378;
  undefined8 local_370;
  undefined8 local_368;
  undefined8 local_360;
  undefined8 local_358;
  undefined4 local_33c;
  undefined8 local_338;
  undefined4 local_2ec;
  undefined8 local_2e8;
  undefined4 local_260;
  undefined4 local_22c;
  undefined8 local_228;
  undefined4 local_168;
  undefined8 local_164;
  longlong local_db;
  longlong local_d3;
  undefined4 local_cb;
  
  local_390 = 0;
  local_38c = 0;
  uVar11 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
  cVar9 = FUN_2b1a6a68c80(uVar11);
  if (cVar9 == '\0') goto LAB_2b1a6a67617;
  local_3a0 = param_2;
  (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x2f);
  (*(code *)0x7ff63a0e4490)(0x2b1a1776bc8,0x2b1a170ac50,&local_370);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,local_370,0x2b1a17978d0);
  local_368 = 0x2b1a6a77da0;
  local_360 = 0;
  local_358 = 0;
  local_33c = 0;
  local_338 = 0;
  local_2ec = 0;
  local_2e8 = 0;
  local_22c = 0;
  local_228 = 0;
  local_168 = 0;
  local_164 = 0;
  FUN_2b1a6a71490(&local_370);
  if (0.0 <= _DAT_2b1a6ba6048) {
    if (0.0 <= _DAT_2b1a6ba6050) {
      local_384 = param_1;
      (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x35);
      (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,4);
      dVar29 = _DAT_2b1a6dcd548;
      uVar33 = SUB84(_DAT_2b1a6dcd548,0);
      uVar34 = (undefined4)((ulonglong)_DAT_2b1a6dcd548 >> 0x20);
      (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,1);
      dVar28 = _DAT_2b1a6dcd548;
      uVar35 = SUB84(_DAT_2b1a6dcd548,0);
      uVar36 = (undefined4)((ulonglong)_DAT_2b1a6dcd548 >> 0x20);
      (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
      local_3d8 = 0;
      local_3b8 = 0;
      local_3c8 = 0;
      local_3d4 = 0;
      local_3b4 = (short *)0x0;
      local_3c4 = 0;
      dVar32 = _DAT_2b1a6dcd6a0;
      if ((_DAT_2b1a6dcd6a0 != 0.0) || (NAN(_DAT_2b1a6dcd6a0))) {
LAB_2b1a6a66d6f:
        FUN_2b1a6a60000(&local_3d8);
        uVar11 = local_3a0;
        if (DAT_2b1a6dcd688 == '\x01') {
          local_3d8 = 0;
          local_3d4 = 0;
          local_3a8 = 0;
          uVar11 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
          (*(code *)0x7ff63a1084f0)(0x2b1a1776bc8,0,uVar11);
          local_3b8 = 0;
          local_3b4 = (short *)0x0;
          local_3cc = (*(code *)0x7ff63a108810)(0x2b1a1776bc8);
          uVar30 = 0;
          uVar31 = 0;
          dVar27 = 0.0;
          uVar15 = 0;
          local_3c8 = 0;
          local_3c4 = 0;
          local_380 = _DAT_2b1a6dcd6f0;
          uVar17 = local_3cc;
          do {
            lVar20 = (*(code *)0x7ff63a108860)(0x2b1a1776bc8,uVar15);
            if (lVar20 != 0) {
              lVar24 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,0xb);
              (*(code *)0x7ff63a1089d0)(0x2b1a1776bc8,lVar20,0);
              FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd53c,1,0x2b1a6ba4ac0);
              FUN_2b1a6a604e0(&local_3c8,&local_3d8,0,0x2b1a6ba4ad0);
              iVar10 = 0;
              uVar17 = local_3cc;
              if (local_3c4 != _DAT_2b1a6dcd52c) {
                if ((local_3c4 == 0) || (_DAT_2b1a6dcd52c == 0)) goto LAB_2b1a6a66e3a;
                uVar4 = *(uint *)(local_3c4 + -4);
                uVar5 = *(uint *)(_DAT_2b1a6dcd52c + -4);
                uVar16 = uVar5;
                if (uVar4 < uVar5) {
                  uVar16 = uVar4;
                }
                iVar10 = uVar4 - uVar5;
                if (uVar16 != 0) {
                  uVar26 = 1;
                  do {
                    uVar2 = *(ushort *)(local_3c4 + -2 + uVar26 * 2);
                    uVar3 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar26 * 2);
                    if (uVar16 <= uVar26) break;
                    uVar26 = uVar26 + 1;
                  } while (uVar2 == uVar3);
                  if (uVar2 != uVar3) {
                    iVar10 = (uint)uVar2 - (uint)uVar3;
                  }
                }
              }
              if ((iVar10 == 0) && (lVar24 == local_380)) {
                (*(code *)0x7ff63a1088b0)(0x2b1a1776bc8,lVar20,6);
                lVar24 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,2);
                (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,3);
                lVar12 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,4);
                (*(code *)0x7ff63a1088b0)(0x2b1a1776bc8,lVar20,9);
                uVar17 = local_3cc;
                dVar18 = _DAT_2b1a6dcd548;
                if ((lVar12 == 1) && ((local_3a8 < lVar24 && (_DAT_2b1a6dcd548 < 0.0)))) {
                  (*(code *)0x7ff63a1088b0)(0x2b1a1776bc8,lVar20,5);
                  uVar30 = SUB84(dVar18,0);
                  uVar31 = (undefined4)((ulonglong)dVar18 >> 0x20);
                  dVar27 = _DAT_2b1a6dcd548;
                  local_3a8 = lVar24;
                }
              }
            }
LAB_2b1a6a66e3a:
            uVar15 = uVar15 + 1;
          } while (uVar15 <= uVar17);
          dVar18 = 0.0;
          dVar21 = 0.0;
          uVar15 = 0;
          local_398 = 0;
          do {
            lVar20 = (*(code *)0x7ff63a108860)(0x2b1a1776bc8,uVar15);
            if (lVar20 != 0) {
              local_378 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,0xb);
              (*(code *)0x7ff63a1089d0)(0x2b1a1776bc8,lVar20,0);
              FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd53c,1,0x2b1a6ba4ae0);
              FUN_2b1a6a604e0(&local_3c8,&local_3d8,0,0x2b1a6ba4af0);
              iVar10 = 0;
              if (local_3c4 != _DAT_2b1a6dcd52c) {
                if ((local_3c4 == 0) || (_DAT_2b1a6dcd52c == 0)) goto LAB_2b1a6a67083;
                uVar4 = *(uint *)(local_3c4 + -4);
                uVar5 = *(uint *)(_DAT_2b1a6dcd52c + -4);
                uVar16 = uVar5;
                if (uVar4 < uVar5) {
                  uVar16 = uVar4;
                }
                iVar10 = uVar4 - uVar5;
                if (uVar16 != 0) {
                  uVar26 = 1;
                  do {
                    uVar2 = *(ushort *)(local_3c4 + -2 + uVar26 * 2);
                    uVar3 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar26 * 2);
                    if (uVar16 <= uVar26) break;
                    uVar26 = uVar26 + 1;
                  } while (uVar2 == uVar3);
                  if (uVar2 != uVar3) {
                    iVar10 = (uint)uVar2 - (uint)uVar3;
                  }
                }
              }
              if ((iVar10 == 0) && (local_378 == local_380)) {
                (*(code *)0x7ff63a1088b0)(0x2b1a1776bc8,lVar20,6);
                lVar24 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,2);
                (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,3);
                lVar12 = (*(code *)0x7ff63a108940)(0x2b1a1776bc8,lVar20,4);
                (*(code *)0x7ff63a1088b0)(0x2b1a1776bc8,lVar20,9);
                if (lVar12 == 1) {
                  if (lVar24 < local_3a8 && local_398 < lVar24) {
                    local_398 = lVar24;
                    dVar21 = _DAT_2b1a6dcd548;
                  }
                  if (local_3a8 < lVar24) {
                    dVar18 = dVar18 + _DAT_2b1a6dcd548;
                  }
                }
              }
            }
LAB_2b1a6a67083:
            uVar15 = uVar15 + 1;
          } while (uVar15 <= uVar17);
          if (uVar17 == 0) {
            FUN_2b1a6a60000(&local_3c8);
            FUN_2b1a6a60000(&local_3b8);
          }
          else {
            if (_DAT_2b1a6a77998 <= dVar21) {
              dVar21 = _DAT_2b1a6a77998;
            }
            FUN_2b1a6a60000(&local_3c8);
            FUN_2b1a6a60000(&local_3b8);
            uVar11 = local_3a0;
            if (dVar18 + (double)CONCAT44(uVar31,uVar30) + dVar21 < 0.0) {
              FUN_2b1a6a60000(&local_3d8);
              if (0.0 < dVar27) {
                dVar32 = dVar27 * _DAT_2b1a6ba6008;
              }
              goto LAB_2b1a6a67324;
            }
          }
          uVar11 = local_3a0;
          FUN_2b1a6a60000(&local_3d8);
        }
LAB_2b1a6a67324:
        if ((longlong)dVar32 != -0x8000000000000000) {
          dVar27 = (double)(longlong)dVar32;
          dVar32 = (double)(longlong)
                           ((dVar32 - dVar27) * _DAT_2b1a6a77990 +
                           *(double *)((ulonglong)(0.0 < dVar32) * 8 + 0x2b1a6a779a0)) /
                   _DAT_2b1a6a77990 + dVar27;
        }
        (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,uVar11,0x23);
        if (_DAT_2b1a6dcd548 < dVar32) {
          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,uVar11,0x23);
          dVar32 = _DAT_2b1a6dcd548;
        }
        (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,uVar11,0x22);
        if (dVar32 < _DAT_2b1a6dcd548) {
          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,uVar11,0x22);
          dVar32 = _DAT_2b1a6dcd548;
        }
        (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,uVar11,0x24);
        if ((_DAT_2b1a6dcd548 != 0.0) || (NAN(_DAT_2b1a6dcd548))) {
          dVar32 = dVar32 / _DAT_2b1a6dcd548;
          dVar18 = ABS(dVar32);
          uVar17 = (uint)((ulonglong)dVar18 >> 0x20);
          dVar27 = dVar32;
          if (uVar17 >> 0x14 < 0x3ff) {
            if ((dVar18 != 0.0) && (dVar27 = 0.0, (longlong)dVar32 < 0)) {
              dVar27 = _DAT_2b1a6a779b0;
            }
          }
          else if (((uVar17 >> 0x16 < 0x10d) &&
                   (bVar13 = 0x33 - (char)((ulonglong)dVar18 >> 0x34),
                   dVar21 = (double)(((ulonglong)dVar18 >> (bVar13 & 0x3f)) << (bVar13 & 0x3f)),
                   dVar27 = dVar21, (longlong)dVar32 < 1)) &&
                  (dVar27 = (double)((ulonglong)dVar21 | 0x8000000000000000), dVar21 != dVar18)) {
            dVar27 = dVar27 + _DAT_2b1a6a779b0;
          }
          dVar27 = _DAT_2b1a6dcd548 * dVar27;
          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,0x22);
          if ((_DAT_2b1a6dcd548 <= dVar27) &&
             ((*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,0x23),
             dVar27 <= _DAT_2b1a6dcd548)) {
            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,0x24);
            if ((_DAT_2b1a6dcd548 == 0.0) && (!NAN(_DAT_2b1a6dcd548))) goto LAB_2b1a6a684f8;
            dVar18 = dVar27 / _DAT_2b1a6dcd548;
            uVar17 = (uint)((ulonglong)dVar18 >> 0x34) & 0x7ff;
            lVar20 = (ulonglong)uVar17 - 0x3ff;
            dVar32 = dVar18;
            if ((ulonglong)uVar17 < 0x433) {
              if (uVar17 < 0x3ff) {
                dVar32 = (double)((ulonglong)dVar18 & 0x8000000000000000 | 0x3ff0000000000000);
                if (lVar20 != -1) {
                  dVar32 = (double)((ulonglong)dVar18 & 0x8000000000000000);
                }
              }
              else {
                bVar13 = (byte)lVar20;
                if (((longlong)dVar18 << (bVar13 & 0x3f) & 0xfffffffffffffU) != 0) {
                  dVar32 = (double)((0x8000000000000U >> (bVar13 & 0x3f)) + (longlong)dVar18 &
                                   -0x10000000000000 >> (bVar13 & 0x3f));
                }
              }
            }
            else if (lVar20 == 0x400) {
              dVar32 = dVar18 + dVar18;
            }
            if ((double)((ulonglong)(_DAT_2b1a6dcd548 * (double)(int)dVar32 - dVar27) &
                        _DAT_2b1a6a779c0) <= _DAT_2b1a6a779d0) {
              (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,0x37);
              dVar18 = _DAT_2b1a6dcd548;
              local_3d8 = 0;
              dVar32 = 0.0;
              local_3d4 = 0;
              bVar25 = 0.0 < _DAT_2b1a6dcd548;
              bVar8 = _DAT_2b1a6dcd548 < dVar27;
              uVar26 = -(ulonglong)bVar25 & (ulonglong)_DAT_2b1a6dcd548;
              iVar10 = (*(code *)0x7ff63a107da0)(0x2b1a1776bc8);
              if (-1 < iVar10 + -1) {
                dVar32 = 0.0;
                iVar10 = iVar10 + -1;
                do {
                  lVar20 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar10);
                  if (lVar20 != 0) {
                    (*(code *)0x7ff63a108010)(0x2b1a1776bc8,0);
                    FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd53c,1,0x2b1a6ba4aa0);
                    if (local_3d4 == _DAT_2b1a6dcd52c) {
LAB_2b1a6a67736:
                      (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,3);
                      dVar32 = dVar32 + _DAT_2b1a6dcd548;
                    }
                    else if ((local_3d4 != 0) && (_DAT_2b1a6dcd52c != 0)) {
                      uVar17 = *(uint *)(local_3d4 + -4);
                      uVar15 = *(uint *)(_DAT_2b1a6dcd52c + -4);
                      uVar4 = uVar15;
                      if (uVar17 < uVar15) {
                        uVar4 = uVar17;
                      }
                      iVar14 = uVar17 - uVar15;
                      if (uVar4 != 0) {
                        uVar23 = 1;
                        do {
                          uVar2 = *(ushort *)(local_3d4 + -2 + uVar23 * 2);
                          uVar3 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar23 * 2);
                          if (uVar4 <= uVar23) break;
                          uVar23 = uVar23 + 1;
                        } while (uVar2 == uVar3);
                        if (uVar2 != uVar3) {
                          iVar14 = (uint)uVar2 - (uint)uVar3;
                        }
                      }
                      if (iVar14 == 0) goto LAB_2b1a6a67736;
                    }
                  }
                  bVar6 = 0 < iVar10;
                  iVar10 = iVar10 + -1;
                } while (bVar6);
              }
              dVar27 = (double)(~-(ulonglong)bVar8 & (ulonglong)dVar27 |
                               (~-(ulonglong)bVar25 & (ulonglong)dVar27 | uVar26) &
                               -(ulonglong)bVar8);
              iVar10 = (*(code *)0x7ff63a1081a0)(0x2b1a1776bc8);
              if (-1 < iVar10 + -1) {
                iVar10 = iVar10 + -1;
                do {
                  lVar20 = (*(code *)0x7ff63a1081f0)(0x2b1a1776bc8,iVar10);
                  if (lVar20 != 0) {
                    (*(code *)0x7ff63a1083a0)(0x2b1a1776bc8,0);
                    FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd53c,1,0x2b1a6ba4ab0);
                    if (local_3d4 == _DAT_2b1a6dcd52c) {
LAB_2b1a6a67882:
                      (*(code *)0x7ff63a108280)(0x2b1a1776bc8,8);
                      dVar32 = dVar32 + _DAT_2b1a6dcd548;
                    }
                    else if ((local_3d4 != 0) && (_DAT_2b1a6dcd52c != 0)) {
                      uVar17 = *(uint *)(local_3d4 + -4);
                      uVar15 = *(uint *)(_DAT_2b1a6dcd52c + -4);
                      uVar4 = uVar15;
                      if (uVar17 < uVar15) {
                        uVar4 = uVar17;
                      }
                      iVar14 = uVar17 - uVar15;
                      if (uVar4 != 0) {
                        uVar26 = 1;
                        do {
                          uVar2 = *(ushort *)(local_3d4 + -2 + uVar26 * 2);
                          uVar3 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar26 * 2);
                          if (uVar4 <= uVar26) break;
                          uVar26 = uVar26 + 1;
                        } while (uVar2 == uVar3);
                        if (uVar2 != uVar3) {
                          iVar14 = (uint)uVar2 - (uint)uVar3;
                        }
                      }
                      if (iVar14 == 0) goto LAB_2b1a6a67882;
                    }
                  }
                  bVar25 = 0 < iVar10;
                  iVar10 = iVar10 + -1;
                } while (bVar25);
              }
              FUN_2b1a6a60000(&local_3d8);
              if ((dVar18 <= 0.0) || (0.0 <= (dVar18 - dVar32) - dVar27)) {
                _DAT_2b1a6ca40a0 = _DAT_2b1a6dcd6f0;
                FUN_2b1a6a604e0(&local_390,0x2b1a6dcd528,1,0x2b1a6ba4b00);
                (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,&local_390,0x32);
                FUN_2b1a6a604e0(&local_390,0x2b1a6dcd528,1,0x2b1a6ba4b10);
                (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,&local_390,0x32);
                if (local_384 == -1) {
                  FUN_2b1a6a604e0(&local_390,0x2b1a6dcd528,1,0x2b1a6ba4b30);
                  cVar9 = FUN_2b1a6a75d20(&local_390,dVar27,1);
                  if (cVar9 != '\0') {
                    if ((_DAT_2b1a6dcd520 == 4) || (_DAT_2b1a6dcd520 == 2)) {
                      dVar29 = _DAT_2b1a6ba6050 * _DAT_2b1a6dcd518;
                      dVar32 = _DAT_2b1a6dcd518 * _DAT_2b1a6ba6048;
                    }
                    else {
                      dVar29 = _DAT_2b1a6ba6050 * _DAT_2b1a6dcd518 * _DAT_2b1a6a779d8;
                      dVar32 = _DAT_2b1a6dcd518 * _DAT_2b1a6ba6048 * _DAT_2b1a6a779d8;
                    }
                    dVar32 = dVar28 - dVar32;
                    dVar18 = 0.0;
                    if (DAT_2b1a6ba6041 == '\x01') {
                      dVar18 = dVar29 + dVar28;
                      if ((longlong)dVar18 != -0x8000000000000000) {
                        dVar29 = (double)(longlong)dVar18;
                        uVar26 = 0xb;
                        if (_DAT_2b1a6dcd520 < 0xb) {
                          uVar26 = (ulonglong)_DAT_2b1a6dcd520;
                        }
                        dVar21 = *(double *)(uVar26 * 8 + 0x2b1a6a77d20);
                        dVar18 = (double)(longlong)
                                         ((dVar18 - dVar29) * dVar21 +
                                         *(double *)((ulonglong)(0.0 < dVar18) * 8 + 0x2b1a6a779a0))
                                 / dVar21 + dVar29;
                      }
                    }
                    if ((longlong)dVar32 != -0x8000000000000000) {
                      dVar29 = (double)(longlong)dVar32;
                      uVar26 = 0xb;
                      if (_DAT_2b1a6dcd520 < 0xb) {
                        uVar26 = (ulonglong)_DAT_2b1a6dcd520;
                      }
                      dVar21 = *(double *)(uVar26 * 8 + 0x2b1a6a77d20);
                      dVar32 = (double)(longlong)
                                       ((dVar32 - dVar29) * dVar21 +
                                       *(double *)((ulonglong)(0.0 < dVar32) * 8 + 0x2b1a6a779a0)) /
                               dVar21 + dVar29;
                    }
                    uVar23 = ~-(ulonglong)(_DAT_2b1a6ba6050 == 0.0) & (ulonglong)dVar18;
                    uVar26 = ~-(ulonglong)(_DAT_2b1a6ba6048 == 0.0) & (ulonglong)dVar32;
                    cVar9 = FUN_2b1a6a754b0(1,uVar23,(int)uVar26);
                    if (cVar9 == '\0') {
LAB_2b1a6a68414:
                      (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a79fd0);
                    }
                    else {
                      local_db = _DAT_2b1a6ca40a0;
                      local_d3 = (longlong)_DAT_2b1a6dcd6d8;
                      local_cb = 2;
                      if (dVar27 <= 0.0) {
LAB_2b1a6a6844f:
                        local_cb = 2;
                        local_260 = 0x271e;
                        local_db = _DAT_2b1a6ca40a0;
                        (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                        local_260 = 0x271e;
                        (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                        local_260 = 0x271e;
LAB_2b1a6a68498:
                        (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                      }
                      else {
                        local_3d8 = 0;
                        local_3d4 = 0;
                        FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3b08);
                        dVar32 = dVar28;
                        if ((dVar28 == 0.0) && (!NAN(dVar28))) {
                          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,1);
                          dVar32 = _DAT_2b1a6dcd548;
                        }
                        cVar9 = FUN_2b1a6a71710(&local_370,&local_3d8,1,dVar27,dVar32,uVar23,uVar26)
                        ;
                        FUN_2b1a6a60000(&local_3d8);
                        if (cVar9 != '\x01') {
                          (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                          local_3d8 = 0;
                          local_3d4 = 0;
                          FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3b08);
                          dVar32 = dVar28;
                          if ((dVar28 == 0.0) && (!NAN(dVar28))) {
                            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,1);
                            dVar32 = _DAT_2b1a6dcd548;
                          }
                          cVar9 = FUN_2b1a6a71710(&local_370,&local_3d8,1,dVar27,dVar32,uVar23,
                                                  uVar26);
                          FUN_2b1a6a60000(&local_3d8);
                          if (cVar9 != '\x01') {
                            (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                            local_3d8 = 0;
                            local_3d4 = 0;
                            FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3b08);
                            if ((dVar28 == 0.0) && (!NAN(dVar28))) {
                              (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,1);
                              uVar35 = SUB84(_DAT_2b1a6dcd548,0);
                              uVar36 = (undefined4)((ulonglong)_DAT_2b1a6dcd548 >> 0x20);
                            }
                            uVar22 = 1;
                            uVar11 = CONCAT44(uVar36,uVar35);
LAB_2b1a6a683f5:
                            cVar9 = FUN_2b1a6a71710(&local_370,&local_3d8,uVar22,dVar27,uVar11,
                                                    uVar23,uVar26);
                            FUN_2b1a6a60000(&local_3d8);
                            if (cVar9 != '\x01') goto LAB_2b1a6a68498;
                          }
                        }
                      }
                    }
                  }
                }
                else if (local_384 == 1) {
                  FUN_2b1a6a604e0(&local_390,0x2b1a6dcd528,1,0x2b1a6ba4b20);
                  cVar9 = FUN_2b1a6a75d20(&local_390,dVar27,0);
                  if (cVar9 != '\0') {
                    if ((_DAT_2b1a6dcd520 == 4) || (_DAT_2b1a6dcd520 == 2)) {
                      dVar32 = _DAT_2b1a6ba6050 * _DAT_2b1a6dcd518;
                      dVar28 = _DAT_2b1a6dcd518 * _DAT_2b1a6ba6048;
                    }
                    else {
                      dVar32 = _DAT_2b1a6ba6050 * _DAT_2b1a6dcd518 * _DAT_2b1a6a779d8;
                      dVar28 = _DAT_2b1a6dcd518 * _DAT_2b1a6ba6048 * _DAT_2b1a6a779d8;
                    }
                    dVar28 = dVar28 + dVar29;
                    dVar18 = 0.0;
                    if (DAT_2b1a6ba6041 == '\x01') {
                      dVar18 = dVar29 - dVar32;
                      if ((longlong)dVar18 != -0x8000000000000000) {
                        dVar32 = (double)(longlong)dVar18;
                        uVar26 = 0xb;
                        if (_DAT_2b1a6dcd520 < 0xb) {
                          uVar26 = (ulonglong)_DAT_2b1a6dcd520;
                        }
                        dVar21 = *(double *)(uVar26 * 8 + 0x2b1a6a77d20);
                        dVar18 = (double)(longlong)
                                         ((dVar18 - dVar32) * dVar21 +
                                         *(double *)((ulonglong)(0.0 < dVar18) * 8 + 0x2b1a6a779a0))
                                 / dVar21 + dVar32;
                      }
                    }
                    if ((longlong)dVar28 != -0x8000000000000000) {
                      dVar32 = (double)(longlong)dVar28;
                      uVar26 = 0xb;
                      if (_DAT_2b1a6dcd520 < 0xb) {
                        uVar26 = (ulonglong)_DAT_2b1a6dcd520;
                      }
                      dVar21 = *(double *)(uVar26 * 8 + 0x2b1a6a77d20);
                      dVar28 = (double)(longlong)
                                       ((dVar28 - dVar32) * dVar21 +
                                       *(double *)((ulonglong)(0.0 < dVar28) * 8 + 0x2b1a6a779a0)) /
                               dVar21 + dVar32;
                    }
                    uVar23 = ~-(ulonglong)(_DAT_2b1a6ba6050 == 0.0) & (ulonglong)dVar18;
                    uVar26 = ~-(ulonglong)(_DAT_2b1a6ba6048 == 0.0) & (ulonglong)dVar28;
                    cVar9 = FUN_2b1a6a754b0(0,uVar23,(int)uVar26);
                    if (cVar9 == '\0') goto LAB_2b1a6a68414;
                    local_db = _DAT_2b1a6ca40a0;
                    local_d3 = (longlong)_DAT_2b1a6dcd6d8;
                    local_cb = 2;
                    if (dVar27 <= 0.0) goto LAB_2b1a6a6844f;
                    local_3d8 = 0;
                    local_3d4 = 0;
                    FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3af8);
                    dVar32 = dVar29;
                    if ((dVar29 == 0.0) && (!NAN(dVar29))) {
                      (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,4);
                      dVar32 = _DAT_2b1a6dcd548;
                    }
                    cVar9 = FUN_2b1a6a71710(&local_370,&local_3d8,0,dVar27,dVar32,uVar23,uVar26);
                    FUN_2b1a6a60000(&local_3d8);
                    if (cVar9 != '\x01') {
                      (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                      local_3d8 = 0;
                      local_3d4 = 0;
                      FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3af8);
                      dVar32 = dVar29;
                      if ((dVar29 == 0.0) && (!NAN(dVar29))) {
                        (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,4);
                        dVar32 = _DAT_2b1a6dcd548;
                      }
                      cVar9 = FUN_2b1a6a71710(&local_370,&local_3d8,0,dVar27,dVar32,uVar23,uVar26);
                      FUN_2b1a6a60000(&local_3d8);
                      if (cVar9 != '\x01') {
                        (*(code *)0x7ff63a0e17c0)(0x2b1a1776bc8,18000);
                        local_3d8 = 0;
                        local_3d4 = 0;
                        FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd528,0,0x2b1a6ba3af8);
                        if ((dVar29 == 0.0) && (!NAN(dVar29))) {
                          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3d8,4);
                          uVar33 = SUB84(_DAT_2b1a6dcd548,0);
                          uVar34 = (undefined4)((ulonglong)_DAT_2b1a6dcd548 >> 0x20);
                        }
                        uVar11 = CONCAT44(uVar34,uVar33);
                        uVar22 = 0;
                        goto LAB_2b1a6a683f5;
                      }
                    }
                  }
                }
              }
            }
          }
          goto LAB_2b1a6a67603;
        }
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0xe0895000001f7);
      }
      else {
        (*(code *)0x7ff63a0c7410)(0x2b1a1776bc8,0x24);
        FUN_2b1a6a604e0(&local_3d8,0x2b1a6dcd53c,1,0x2b1a6ba47f8);
        FUN_2b1a6a604e0(&local_3b8,&local_3d8,0,0x2b1a6ba4808);
        uVar11 = _DAT_2b1a6a77960;
        if ((((_DAT_2b1a6dcd6b8 != 1) &&
             (uVar11 = _DAT_2b1a6dcd6b0, uVar22 = _DAT_2b1a6a77968, _DAT_2b1a6dcd6b8 == 2)) ||
            (uVar22 = uVar11, uVar11 = _DAT_2b1a6a77970, _DAT_2b1a6dcd6b8 != 3)) &&
           (uVar11 = uVar22, _DAT_2b1a6dcd6b8 == 4)) {
          uVar11 = _DAT_2b1a6a77978;
        }
        uVar30 = (undefined4)_DAT_2b1a6a77980;
        uVar31 = (undefined4)(_DAT_2b1a6a77980 >> 0x20);
        if (_DAT_2b1a6dcd6b8 != 5) {
          uVar30 = (undefined4)uVar11;
          uVar31 = (undefined4)((ulonglong)uVar11 >> 0x20);
        }
        if (_DAT_2b1a6dcd6b8 == 6) {
          uVar30 = (undefined4)_DAT_2b1a6a77988;
          uVar31 = (undefined4)((ulonglong)_DAT_2b1a6a77988 >> 0x20);
        }
        uVar26 = -(ulonglong)(0.0 < (double)CONCAT44(uVar31,uVar30));
        dVar32 = (double)(~uVar26 & _DAT_2b1a6a77980 | CONCAT44(uVar31,uVar30) & uVar26);
        if (local_3b4 == (short *)0x0) {
          uVar30 = 0xfa9;
        }
        else {
          uVar30 = 0x13ab;
          if ((_DAT_2b1a6a79d68 != 0) && (uVar17 = *(uint *)(local_3b4 + -2), uVar17 != 0)) {
            uVar30 = _DAT_2b1a6dcd510;
            if (local_3b4 == (short *)&DAT_2b1a6a79d6c) goto LAB_2b1a6a67c4b;
            if ((uVar17 <= _DAT_2b1a6a79d68) &&
               (uVar15 = (_DAT_2b1a6a79d68 - uVar17) + 1, uVar15 != 0)) {
              sVar1 = *local_3b4;
              uVar26 = (ulonglong)uVar15;
              if (uVar17 < 2) {
                if (sVar1 == 0x4a) {
LAB_2b1a6a67c4b:
                  dVar32 = dVar32 * _DAT_2b1a6a77990;
                }
                else {
                  uVar23 = 0;
                  do {
                    if (uVar26 - 1 == uVar23) goto LAB_2b1a6a66c6b;
                    lVar20 = uVar23 * 2;
                    uVar23 = uVar23 + 1;
                  } while (*(short *)(&DAT_2b1a6a79d6e + lVar20) != sVar1);
                  if (uVar23 < uVar26) {
LAB_2b1a6a67c41:
                    if ((int)uVar23 != -1) goto LAB_2b1a6a67c4b;
                  }
                }
              }
              else {
                bVar25 = true;
                uVar23 = 0;
                do {
                  if (*(short *)(&DAT_2b1a6a79d6c + uVar23 * 2) == sVar1) {
                    lVar24 = 1;
                    lVar20 = (ulonglong)uVar17 - 1;
                    while (*(short *)(&DAT_2b1a6a79d6c +
                                     (ulonglong)(uint)((int)uVar23 + (int)lVar24) * 2) ==
                           local_3b4[lVar24]) {
                      lVar24 = lVar24 + 1;
                      lVar20 = lVar20 + -1;
                      if (lVar20 == 0) goto LAB_2b1a6a67c2a;
                    }
                    if ((int)lVar20 == 0) {
LAB_2b1a6a67c2a:
                      if (bVar25) goto LAB_2b1a6a67c41;
                      break;
                    }
                  }
                  uVar23 = uVar23 + 1;
                  bVar25 = uVar23 < uVar26;
                } while (uVar23 != uVar26);
              }
            }
          }
        }
LAB_2b1a6a66c6b:
        _DAT_2b1a6dcd510 = uVar30;
        (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
        if ((dVar32 != 0.0) || (NAN(dVar32))) {
          local_3c8 = 0;
          local_3c4 = 0;
          dVar32 = (_DAT_2b1a6dcd548 / dVar32) * _DAT_2b1a6dcd6a8;
          FUN_2b1a6a604e0(&local_3c8,0x2b1a6dcd528,1,0x2b1a6ba4818);
          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3c8,0x23);
          if (_DAT_2b1a6dcd548 < dVar32) {
            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3c8,0x23);
            dVar32 = _DAT_2b1a6dcd548;
          }
          (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3c8,0x22);
          if (dVar32 < _DAT_2b1a6dcd548) {
            (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_3c8,0x22);
            dVar32 = _DAT_2b1a6dcd548;
          }
          FUN_2b1a6a60000(&local_3c8);
          FUN_2b1a6a60000(&local_3b8);
          goto LAB_2b1a6a66d6f;
        }
      }
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x390746000001f7);
LAB_2b1a6a684f8:
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x220769000001f7);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    puVar19 = &DAT_2b1a6ba61ac;
    if (DAT_2b1a6ba61ac == '\0') {
      uVar11 = 0x2b1a6a79f60;
      goto LAB_2b1a6a669da;
    }
  }
  else {
    puVar19 = &DAT_2b1a6ba61ad;
    if (DAT_2b1a6ba61ad == '\0') {
      uVar11 = 0x2b1a6a79f18;
LAB_2b1a6a669da:
      (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,uVar11);
      *puVar19 = 1;
    }
  }
LAB_2b1a6a67603:
  FUN_2b1a6a75210(&local_370);
LAB_2b1a6a67617:
  FUN_2b1a6a60000(&local_390);
  return;
}



/* Address: 2b1a6a68520 */

undefined4 FUN_2b1a6a68520(void)

{
  undefined1 local_20 [28];
  undefined4 local_4;
  
  (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,local_20);
  return local_4;
}



/* Address: 2b1a6a68550 */

undefined4 FUN_2b1a6a68550(void)

{
  undefined1 local_20 [12];
  undefined4 local_14;
  
  (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,local_20);
  return local_14;
}



/* Address: 2b1a6a68580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a68580(void)

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
  ulonglong uVar12;
  longlong lVar13;
  undefined4 local_348;
  undefined8 local_344;
  undefined4 local_338;
  longlong local_334;
  longlong local_328;
  undefined4 local_320;
  undefined8 local_31c;
  undefined4 local_310;
  undefined8 local_30c;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 local_2e0;
  undefined4 local_2d8;
  undefined4 uStack_2d4;
  undefined4 local_2d0;
  undefined4 uStack_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined8 local_270;
  undefined8 local_268 [16];
  undefined4 local_1e8 [13];
  undefined4 local_1b4;
  undefined8 local_1b0;
  undefined1 local_1a8 [184];
  undefined4 local_f0;
  undefined8 local_ec;
  undefined8 local_e4;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined8 local_cc;
  undefined8 local_c4;
  undefined8 local_bc;
  undefined8 local_b4;
  undefined8 local_ac;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_63;
  undefined8 local_5b;
  
  local_320 = 0;
  local_31c = 0;
  (*(code *)0x7ff63a0e4490)(0x2b1a1776bc8,0x2b1a170ac50,&local_2f8);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,local_2f8,0x2b1a17978d0);
  local_2f0 = 0x2b1a6a77da0;
  local_2e8 = 0;
  local_2e0 = 0;
  local_2c4 = 0;
  local_2c0 = 0;
  local_274 = 0;
  local_270 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_f0 = 0;
  local_ec = 0;
  FUN_2b1a6a71490(&local_2f8);
  iVar8 = (*(code *)0x7ff63a107da0)(0x2b1a1776bc8);
  local_338 = 0;
  local_334 = 0;
  if (-1 < iVar8 + -1) {
    local_328 = _DAT_2b1a6dcd6f0;
    lVar13 = _DAT_2b1a6dcd6f0;
    iVar8 = iVar8 + -1;
    do {
      uVar9 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar8);
      (*(code *)0x7ff63a107ee0)(0x2b1a1776bc8,uVar9);
      (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar8);
      lVar10 = (*(code *)0x7ff63a107fc0)(0x2b1a1776bc8,0xc);
      (*(code *)0x7ff63a108010)(0x2b1a1776bc8,0);
      FUN_2b1a6a604e0(&local_320,0x2b1a6dcd53c,1,0x2b1a6ba47b8);
      FUN_2b1a6a604e0(&local_338,&local_320,0,0x2b1a6ba47c8);
      if (lVar10 == lVar13) {
        if (local_334 == _DAT_2b1a6dcd52c) {
LAB_2b1a6a68700:
          uVar9 = (*(code *)0x7ff63a107df0)(0x2b1a1776bc8,iVar8);
          local_310 = 0;
          local_348 = 0;
          local_30c = 0;
          local_344 = 0;
          if (_DAT_2b1a6dcd514 == 0) {
            cVar7 = (*(code *)0x7ff63a107ee0)(0x2b1a1776bc8,uVar9);
            if (cVar7 != '\0') {
              local_348 = 0;
              local_344 = 0;
              local_300 = uVar9;
              (*(code *)0x7ff63a108010)(0x2b1a1776bc8,0);
              FUN_2b1a6a604e0(&local_310,0x2b1a6dcd53c,1,0x2b1a6ba3ac8);
              FUN_2b1a6a604e0(&local_348,&local_310,0,0x2b1a6ba3ad8);
              local_2c8 = 0;
              local_2d0 = 0;
              uStack_2cc = 0;
              local_2d8 = 0;
              uStack_2d4 = 0;
              FUN_2b1a6a60000(&local_2c4);
              local_278 = 0;
              local_280 = 0;
              local_288 = 0;
              local_290 = 0;
              local_298 = 0;
              local_2a0 = 0;
              local_2a8 = 0;
              local_2b0 = 0;
              local_2b8 = 0;
              FUN_2b1a6a60000(&local_274);
              (*(code *)0x7ff63a3fad20)(local_268,0,0xb4);
              FUN_2b1a6a60000(&local_1b4);
              (*(code *)0x7ff63a3fad20)(local_1a8,0,0xb8);
              FUN_2b1a6a60000(&local_f0);
              local_6c = 0;
              local_74 = 0;
              local_7c = 0;
              local_84 = 0;
              local_8c = 0;
              local_94 = 0;
              local_9c = 0;
              local_a4 = 0;
              local_ac = 0;
              local_b4 = 0;
              local_bc = 0;
              local_c4 = 0;
              local_cc = 0;
              local_d4 = 0;
              local_dc = 0;
              local_e4 = 0;
              cVar7 = FUN_2b1a6a71bb0(&local_2f8,&local_348);
              if (cVar7 != '\0') {
                iVar11 = (*(code *)0x7ff63a107fc0)(0x2b1a1776bc8);
                local_288 = CONCAT44(local_288._4_4_,(uint)(iVar11 == 0));
                (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,&local_348,(iVar11 != 0) * '\x03' + '\x01');
                local_2b0 = _DAT_2b1a6dcd548;
                local_2d8 = 1;
                local_268[0] = local_300;
                FUN_2b1a6a604e0(&local_2c4,&local_348,0,0x2b1a6ba3ae8);
                (*(code *)0x7ff63a107f70)(0x2b1a1776bc8,3);
                local_2b8 = _DAT_2b1a6dcd548;
                uStack_2d4 = (undefined4)local_63;
                local_2d0 = (undefined4)((ulonglong)local_63 >> 0x20);
                local_290 = local_5b;
                FUN_2b1a6a61590(&local_2f8,&local_2d8,local_1e8);
              }
              FUN_2b1a6a60000(&local_348);
              lVar13 = local_328;
            }
          }
          else {
            (*(code *)0x7ff63a0e49f0)
                      (0x2b1a1776bc8,0xd,2,0x590008,0x2b1a6a79b20,0x590008,0x2b1a6a78ae8);
            local_1e8[0] = 0x272b;
          }
          FUN_2b1a6a60000(&local_310);
        }
        else if ((local_334 != 0) && (_DAT_2b1a6dcd52c != 0)) {
          uVar3 = *(uint *)(local_334 + -4);
          uVar4 = *(uint *)(_DAT_2b1a6dcd52c + -4);
          uVar6 = uVar4;
          if (uVar3 < uVar4) {
            uVar6 = uVar3;
          }
          iVar11 = uVar3 - uVar4;
          if (uVar6 != 0) {
            uVar12 = 1;
            do {
              uVar1 = *(ushort *)(local_334 + -2 + uVar12 * 2);
              uVar2 = *(ushort *)(_DAT_2b1a6dcd52c + -2 + uVar12 * 2);
              if (uVar6 <= uVar12) break;
              uVar12 = uVar12 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar11 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar11 == 0) goto LAB_2b1a6a68700;
        }
      }
      bVar5 = 0 < iVar8;
      iVar8 = iVar8 + -1;
    } while (bVar5);
  }
  iVar8 = (*(code *)0x7ff63a1081a0)(0x2b1a1776bc8);
  if (iVar8 != 0) {
    iVar11 = 0;
    do {
      (*(code *)0x7ff63a1081f0)(0x2b1a1776bc8,iVar11);
      iVar11 = iVar11 + 1;
    } while (iVar8 != iVar11);
  }
  FUN_2b1a6a60000(&local_338);
  FUN_2b1a6a75210(&local_2f8);
  FUN_2b1a6a60000(&local_320);
  return;
}



/* Address: 2b1a6a68c80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2b1a6a68c80(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  uint local_50 [2];
  uint local_48 [2];
  undefined1 local_40 [12];
  int local_34;
  int local_30;
  int local_2c;
  
  uVar2 = FUN_2b1a6a68dc0();
  (*(code *)0x7ff63a0f2cb0)(0x2b1a1776bc8,0x2b1a6a77f20,uVar2,0,local_48,local_50);
  (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,param_1,local_40);
  uVar2 = 0xa1776b01;
  if (((local_48[0] != 0) || (local_50[0] != 0 && local_50[0] != 0x15180)) &&
     ((uVar3 = local_34 * 0xe10 + local_30 * 0x3c + local_2c, uVar3 <= local_48[0] ||
      (local_50[0] <= uVar3)))) {
    uVar2 = 0;
    lVar4 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
    lVar1 = _DAT_2b1a6ca40b8;
    if (lVar4 == param_1) {
      lVar4 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,1,1);
      if (lVar1 != lVar4) {
        _DAT_2b1a6ca40b8 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,1,1);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* Address: 2b1a6a68dc0 */

undefined4 FUN_2b1a6a68dc0(void)

{
  undefined1 local_20 [24];
  undefined4 local_8;
  
  (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,local_20);
  return local_8;
}



/* Address: 2b1a6a68df0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b1a6a68df0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  int local_48 [2];
  undefined1 local_40 [12];
  int local_34;
  int local_30;
  int local_2c;
  undefined1 local_20 [8];
  
  uVar1 = FUN_2b1a6a68dc0();
  (*(code *)0x7ff63a0f2cb0)(0x2b1a1776bc8,0x2b1a6a77f20,uVar1,0,local_20,local_48);
  uVar3 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
  (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar3,local_40);
  iVar4 = 0x15180;
  if (local_48[0] != 0) {
    iVar4 = local_48[0];
  }
  uVar2 = (local_30 * -0x3c + local_34 * -0xe10 + iVar4) - local_2c;
  if (param_1 == 3) {
    if ((uVar2 < 0x709) && (_DAT_2b1a6dcd648 == 0)) {
      return 0x2b1a6dcd601;
    }
    iVar4 = _DAT_2b1a6dcd648;
    if (local_34 <= _DAT_2b1a6dcd648) {
      if (_DAT_2b1a6dcd648 < 1) {
        return 0;
      }
      if (local_34 != _DAT_2b1a6dcd648) {
        return 0;
      }
      if (local_30 < _DAT_2b1a6dcd650) {
        return 0;
      }
      return 0x2b1a6dcd601;
    }
  }
  else {
    if (param_1 != 5) {
      return 0;
    }
    if ((uVar2 < 0x709) && (_DAT_2b1a6dcd638 == 0)) {
      return 0x2b1a6dcd601;
    }
    iVar4 = _DAT_2b1a6dcd638;
    if (local_34 < _DAT_2b1a6dcd638) {
      return 0;
    }
  }
  if (iVar4 < 1) {
    return 0;
  }
  return 0x2b1a6dcd601;
}



/* Address: 2b1a6a68f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a68f10(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  short *psVar10;
  bool bVar11;
  
  if (_DAT_2b1a6dcd52c == (short *)0x0) {
    _DAT_2b1a6dcd510 = 0xfa9;
    return;
  }
  uVar2 = *(uint *)(_DAT_2b1a6dcd52c + -2);
  if ((uVar2 == 0) || (_DAT_2b1a6a79ca8 == 0)) {
LAB_2b1a6a690a3:
    _DAT_2b1a6dcd510 = 0x13ab;
  }
  else {
    if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79cac) goto LAB_2b1a6a69034;
    if ((_DAT_2b1a6a79ca8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79ca8) + 1, uVar5 != 0)) {
      uVar6 = (ulonglong)uVar5;
      if (_DAT_2b1a6a79ca8 < 2) {
        if (*_DAT_2b1a6dcd52c == 0x47) {
LAB_2b1a6a69034:
          if (_DAT_2b1a6a79cc8 == 0) goto LAB_2b1a6a690a3;
          if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
            return;
          }
          if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar5 != 0)) {
            uVar6 = (ulonglong)uVar5;
            if (_DAT_2b1a6a79cc8 == 1) {
              if (*_DAT_2b1a6dcd52c == 0x55) {
                return;
              }
              uVar7 = 0;
              do {
                if (uVar6 - 1 == uVar7) goto LAB_2b1a6a690a9;
                lVar4 = uVar7 + 1;
                uVar7 = uVar7 + 1;
              } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
              if (uVar7 < uVar6) {
LAB_2b1a6a69990:
                if ((int)uVar7 != -1) {
                  return;
                }
              }
            }
            else {
              bVar11 = true;
              uVar9 = 1;
              uVar7 = 0;
              do {
                iVar8 = (int)uVar9;
                if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
                  psVar10 = (short *)&DAT_2b1a6a79cce;
                  lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
                  while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
                    psVar10 = psVar10 + 1;
                    uVar9 = (ulonglong)((int)uVar9 + 1);
                    lVar4 = lVar4 + -1;
                    if (lVar4 == 0) goto LAB_2b1a6a69987;
                  }
                  if ((int)lVar4 == 0) {
LAB_2b1a6a69987:
                    if (bVar11) goto LAB_2b1a6a69990;
                    break;
                  }
                }
                uVar7 = uVar7 + 1;
                uVar9 = (ulonglong)(iVar8 + 1);
                bVar11 = uVar7 < uVar6;
              } while (uVar7 != uVar6);
            }
          }
        }
        else {
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a690a9;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x47);
          if (uVar7 < uVar6) {
LAB_2b1a6a6902e:
            if ((int)uVar7 != -1) goto LAB_2b1a6a69034;
          }
        }
      }
      else {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x47) {
            psVar10 = (short *)&DAT_2b1a6a79cae;
            lVar4 = (ulonglong)_DAT_2b1a6a79ca8 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a69029;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a69029:
              if (bVar11) goto LAB_2b1a6a6902e;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
      }
    }
  }
LAB_2b1a6a690a9:
  if ((uVar2 == 0) || (_DAT_2b1a6a79ce8 == 0)) {
LAB_2b1a6a69203:
    _DAT_2b1a6dcd510 = 0x13ab;
  }
  else {
    if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79cec) goto LAB_2b1a6a69194;
    if ((_DAT_2b1a6a79ce8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79ce8) + 1, uVar5 != 0)) {
      uVar6 = (ulonglong)uVar5;
      if (_DAT_2b1a6a79ce8 < 2) {
        if (*_DAT_2b1a6dcd52c == 0x58) {
LAB_2b1a6a69194:
          if (_DAT_2b1a6a79cc8 == 0) goto LAB_2b1a6a69203;
          if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
            return;
          }
          if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar5 != 0)) {
            uVar6 = (ulonglong)uVar5;
            if (_DAT_2b1a6a79cc8 == 1) {
              if (*_DAT_2b1a6dcd52c == 0x55) {
                return;
              }
              uVar7 = 0;
              do {
                if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69209;
                lVar4 = uVar7 + 1;
                uVar7 = uVar7 + 1;
              } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
              if (uVar7 < uVar6) {
LAB_2b1a6a69a08:
                if ((int)uVar7 != -1) {
                  return;
                }
              }
            }
            else {
              bVar11 = true;
              uVar9 = 1;
              uVar7 = 0;
              do {
                iVar8 = (int)uVar9;
                if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
                  psVar10 = (short *)&DAT_2b1a6a79cce;
                  lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
                  while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
                    psVar10 = psVar10 + 1;
                    uVar9 = (ulonglong)((int)uVar9 + 1);
                    lVar4 = lVar4 + -1;
                    if (lVar4 == 0) goto LAB_2b1a6a699ff;
                  }
                  if ((int)lVar4 == 0) {
LAB_2b1a6a699ff:
                    if (bVar11) goto LAB_2b1a6a69a08;
                    break;
                  }
                }
                uVar7 = uVar7 + 1;
                uVar9 = (ulonglong)(iVar8 + 1);
                bVar11 = uVar7 < uVar6;
              } while (uVar7 != uVar6);
            }
          }
        }
        else {
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69209;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x58);
          if (uVar7 < uVar6) {
LAB_2b1a6a6918e:
            if ((int)uVar7 != -1) goto LAB_2b1a6a69194;
          }
        }
      }
      else {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x58) {
            psVar10 = (short *)&DAT_2b1a6a79cee;
            lVar4 = (ulonglong)_DAT_2b1a6a79ce8 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a69189;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a69189:
              if (bVar11) goto LAB_2b1a6a6918e;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
      }
    }
  }
LAB_2b1a6a69209:
  if ((uVar2 == 0) || (_DAT_2b1a6a79d08 == 0)) {
LAB_2b1a6a69363:
    _DAT_2b1a6dcd510 = 0x13ab;
  }
  else {
    if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79d0c) goto LAB_2b1a6a692f4;
    if ((_DAT_2b1a6a79d08 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79d08) + 1, uVar5 != 0)) {
      uVar6 = (ulonglong)uVar5;
      if (_DAT_2b1a6a79d08 < 2) {
        if (*_DAT_2b1a6dcd52c == 0x41) {
LAB_2b1a6a692f4:
          if (_DAT_2b1a6a79cc8 == 0) goto LAB_2b1a6a69363;
          if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
            return;
          }
          if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar5 != 0)) {
            uVar6 = (ulonglong)uVar5;
            if (_DAT_2b1a6a79cc8 == 1) {
              if (*_DAT_2b1a6dcd52c == 0x55) {
                return;
              }
              uVar7 = 0;
              do {
                if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69369;
                lVar4 = uVar7 + 1;
                uVar7 = uVar7 + 1;
              } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
              if (uVar7 < uVar6) {
LAB_2b1a6a69a7d:
                if ((int)uVar7 != -1) {
                  return;
                }
              }
            }
            else {
              bVar11 = true;
              uVar9 = 1;
              uVar7 = 0;
              do {
                iVar8 = (int)uVar9;
                if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
                  psVar10 = (short *)&DAT_2b1a6a79cce;
                  lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
                  while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
                    psVar10 = psVar10 + 1;
                    uVar9 = (ulonglong)((int)uVar9 + 1);
                    lVar4 = lVar4 + -1;
                    if (lVar4 == 0) goto LAB_2b1a6a69a74;
                  }
                  if ((int)lVar4 == 0) {
LAB_2b1a6a69a74:
                    if (bVar11) goto LAB_2b1a6a69a7d;
                    break;
                  }
                }
                uVar7 = uVar7 + 1;
                uVar9 = (ulonglong)(iVar8 + 1);
                bVar11 = uVar7 < uVar6;
              } while (uVar7 != uVar6);
            }
          }
        }
        else {
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69369;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x41);
          if (uVar7 < uVar6) {
LAB_2b1a6a692ee:
            if ((int)uVar7 != -1) goto LAB_2b1a6a692f4;
          }
        }
      }
      else {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x41) {
            psVar10 = (short *)&DAT_2b1a6a79d0e;
            lVar4 = (ulonglong)_DAT_2b1a6a79d08 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a692e9;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a692e9:
              if (bVar11) goto LAB_2b1a6a692ee;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
      }
    }
  }
LAB_2b1a6a69369:
  if ((uVar2 == 0) || (_DAT_2b1a6a79d28 == 0)) {
LAB_2b1a6a694c3:
    _DAT_2b1a6dcd510 = 0x13ab;
  }
  else {
    if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79d2c) goto LAB_2b1a6a69454;
    if ((_DAT_2b1a6a79d28 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79d28) + 1, uVar5 != 0)) {
      uVar6 = (ulonglong)uVar5;
      if (_DAT_2b1a6a79d28 < 2) {
        if (*_DAT_2b1a6dcd52c == 0x4e) {
LAB_2b1a6a69454:
          if (_DAT_2b1a6a79cc8 == 0) goto LAB_2b1a6a694c3;
          if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
            return;
          }
          if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar5 != 0)) {
            uVar6 = (ulonglong)uVar5;
            if (_DAT_2b1a6a79cc8 == 1) {
              if (*_DAT_2b1a6dcd52c == 0x55) {
                return;
              }
              uVar7 = 0;
              do {
                if (uVar6 - 1 == uVar7) goto LAB_2b1a6a694c9;
                lVar4 = uVar7 + 1;
                uVar7 = uVar7 + 1;
              } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
              if (uVar7 < uVar6) {
LAB_2b1a6a69ad5:
                if ((int)uVar7 != -1) {
                  return;
                }
              }
            }
            else {
              bVar11 = true;
              uVar9 = 1;
              uVar7 = 0;
              do {
                iVar8 = (int)uVar9;
                if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
                  psVar10 = (short *)&DAT_2b1a6a79cce;
                  lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
                  while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
                    psVar10 = psVar10 + 1;
                    uVar9 = (ulonglong)((int)uVar9 + 1);
                    lVar4 = lVar4 + -1;
                    if (lVar4 == 0) goto LAB_2b1a6a69acc;
                  }
                  if ((int)lVar4 == 0) {
LAB_2b1a6a69acc:
                    if (bVar11) goto LAB_2b1a6a69ad5;
                    break;
                  }
                }
                uVar7 = uVar7 + 1;
                uVar9 = (ulonglong)(iVar8 + 1);
                bVar11 = uVar7 < uVar6;
              } while (uVar7 != uVar6);
            }
          }
        }
        else {
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a694c9;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x4e);
          if (uVar7 < uVar6) {
LAB_2b1a6a6944e:
            if ((int)uVar7 != -1) goto LAB_2b1a6a69454;
          }
        }
      }
      else {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x4e) {
            psVar10 = (short *)&DAT_2b1a6a79d2e;
            lVar4 = (ulonglong)_DAT_2b1a6a79d28 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a69449;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a69449:
              if (bVar11) goto LAB_2b1a6a6944e;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
      }
    }
  }
LAB_2b1a6a694c9:
  if ((uVar2 == 0) || (_DAT_2b1a6a79d48 == 0)) {
LAB_2b1a6a69615:
    _DAT_2b1a6dcd510 = 0x13ab;
  }
  else {
    if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79d4c) goto LAB_2b1a6a695b4;
    if ((_DAT_2b1a6a79d48 <= uVar2) && (uVar2 = (uVar2 - _DAT_2b1a6a79d48) + 1, uVar2 != 0)) {
      uVar6 = (ulonglong)uVar2;
      if (_DAT_2b1a6a79d48 < 2) {
        if (*_DAT_2b1a6dcd52c == 0x43) {
LAB_2b1a6a695b4:
          uVar2 = *(uint *)(_DAT_2b1a6dcd52c + -2);
          if ((uVar2 == 0) || (_DAT_2b1a6a79cc8 == 0)) goto LAB_2b1a6a69615;
          if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
            return;
          }
          if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar2 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar2 != 0)) {
            uVar6 = (ulonglong)uVar2;
            if (_DAT_2b1a6a79cc8 < 2) {
              if (*_DAT_2b1a6dcd52c == 0x55) {
                return;
              }
              uVar7 = 0;
              do {
                if (uVar6 - 1 == uVar7) goto LAB_2b1a6a6961b;
                lVar4 = uVar7 + 1;
                uVar7 = uVar7 + 1;
              } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
              if (uVar7 < uVar6) {
LAB_2b1a6a69bd7:
                if ((int)uVar7 != -1) {
                  return;
                }
              }
            }
            else {
              bVar11 = true;
              uVar2 = 1;
              uVar7 = 0;
              do {
                if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
                  psVar10 = (short *)&DAT_2b1a6a79cce;
                  lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
                  uVar5 = uVar2;
                  while (_DAT_2b1a6dcd52c[uVar5] == *psVar10) {
                    psVar10 = psVar10 + 1;
                    uVar5 = uVar5 + 1;
                    lVar4 = lVar4 + -1;
                    if (lVar4 == 0) goto LAB_2b1a6a69bce;
                  }
                  if ((int)lVar4 == 0) {
LAB_2b1a6a69bce:
                    if (bVar11) goto LAB_2b1a6a69bd7;
                    break;
                  }
                }
                uVar7 = uVar7 + 1;
                uVar2 = uVar2 + 1;
                bVar11 = uVar7 < uVar6;
              } while (uVar7 != uVar6);
            }
          }
        }
        else {
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a6961b;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x43);
          if (uVar7 < uVar6) {
LAB_2b1a6a695ae:
            if ((int)uVar7 != -1) goto LAB_2b1a6a695b4;
          }
        }
      }
      else {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x43) {
            psVar10 = (short *)&DAT_2b1a6a79d4e;
            lVar4 = (ulonglong)_DAT_2b1a6a79d48 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a695a9;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a695a9:
              if (bVar11) goto LAB_2b1a6a695ae;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
      }
    }
  }
LAB_2b1a6a6961b:
  uVar2 = *(uint *)(_DAT_2b1a6dcd52c + -2);
  if ((uVar2 != 0) && (_DAT_2b1a6a79d68 != 0)) {
    if (_DAT_2b1a6dcd52c != (short *)&DAT_2b1a6a79d6c) {
      if ((uVar2 < _DAT_2b1a6a79d68) || (uVar5 = (uVar2 - _DAT_2b1a6a79d68) + 1, uVar5 == 0))
      goto LAB_2b1a6a69789;
      uVar6 = (ulonglong)uVar5;
      if (1 < _DAT_2b1a6a79d68) {
        bVar11 = true;
        uVar9 = 1;
        uVar7 = 0;
        do {
          iVar8 = (int)uVar9;
          if (_DAT_2b1a6dcd52c[uVar7] == 0x4a) {
            psVar10 = (short *)&DAT_2b1a6a79d6e;
            lVar4 = (ulonglong)_DAT_2b1a6a79d68 - 1;
            while (_DAT_2b1a6dcd52c[uVar9] == *psVar10) {
              psVar10 = psVar10 + 1;
              uVar9 = (ulonglong)((int)uVar9 + 1);
              lVar4 = lVar4 + -1;
              if (lVar4 == 0) goto LAB_2b1a6a69709;
            }
            if ((int)lVar4 == 0) {
LAB_2b1a6a69709:
              if (bVar11) goto LAB_2b1a6a6970e;
              break;
            }
          }
          uVar7 = uVar7 + 1;
          uVar9 = (ulonglong)(iVar8 + 1);
          bVar11 = uVar7 < uVar6;
        } while (uVar7 != uVar6);
        goto LAB_2b1a6a69789;
      }
      if (*_DAT_2b1a6dcd52c != 0x4a) {
        uVar7 = 0;
        do {
          if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69789;
          lVar4 = uVar7 + 1;
          uVar7 = uVar7 + 1;
        } while (_DAT_2b1a6dcd52c[lVar4] != 0x4a);
        if (uVar6 <= uVar7) goto LAB_2b1a6a69789;
LAB_2b1a6a6970e:
        if ((int)uVar7 == -1) goto LAB_2b1a6a69789;
      }
    }
    if (_DAT_2b1a6a79cc8 != 0) {
      if (_DAT_2b1a6dcd52c == (short *)0x2b1a6a79ccc) {
        return;
      }
      if ((_DAT_2b1a6a79cc8 <= uVar2) && (uVar5 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar5 != 0)) {
        uVar6 = (ulonglong)uVar5;
        if (_DAT_2b1a6a79cc8 == 1) {
          if (*_DAT_2b1a6dcd52c == 0x55) {
            return;
          }
          uVar7 = 0;
          do {
            if (uVar6 - 1 == uVar7) goto LAB_2b1a6a69789;
            lVar4 = uVar7 + 1;
            uVar7 = uVar7 + 1;
          } while (_DAT_2b1a6dcd52c[lVar4] != 0x55);
          if (uVar7 < uVar6) {
LAB_2b1a6a69b4a:
            if ((int)uVar7 != -1) {
              return;
            }
          }
        }
        else {
          bVar11 = true;
          uVar5 = 1;
          uVar7 = 0;
          do {
            if (_DAT_2b1a6dcd52c[uVar7] == 0x55) {
              psVar10 = (short *)&DAT_2b1a6a79cce;
              lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
              uVar3 = uVar5;
              while (_DAT_2b1a6dcd52c[uVar3] == *psVar10) {
                psVar10 = psVar10 + 1;
                uVar3 = uVar3 + 1;
                lVar4 = lVar4 + -1;
                if (lVar4 == 0) goto LAB_2b1a6a69b41;
              }
              if ((int)lVar4 == 0) {
LAB_2b1a6a69b41:
                if (bVar11) goto LAB_2b1a6a69b4a;
                break;
              }
            }
            uVar7 = uVar7 + 1;
            uVar5 = uVar5 + 1;
            bVar11 = uVar7 < uVar6;
          } while (uVar7 != uVar6);
        }
      }
      goto LAB_2b1a6a69789;
    }
  }
  _DAT_2b1a6dcd510 = 0x13ab;
LAB_2b1a6a69789:
  if (uVar2 == 0) {
    _DAT_2b1a6dcd510 = 0x13ab;
    return;
  }
  if (_DAT_2b1a6a79d88 == 0) {
    _DAT_2b1a6dcd510 = 0x13ab;
    return;
  }
  if (_DAT_2b1a6dcd52c != (short *)0x2b1a6a79d8c) {
    if (uVar2 < _DAT_2b1a6a79d88) {
      return;
    }
    uVar5 = (uVar2 - _DAT_2b1a6a79d88) + 1;
    if (uVar5 == 0) {
      return;
    }
    uVar6 = (ulonglong)uVar5;
    if (1 < _DAT_2b1a6a79d88) {
      bVar11 = true;
      uVar5 = 1;
      uVar7 = 0;
      do {
        if (_DAT_2b1a6dcd52c[uVar7] == 0x43) {
          psVar10 = (short *)&DAT_2b1a6a79d8e;
          lVar4 = (ulonglong)_DAT_2b1a6a79d88 - 1;
          uVar3 = uVar5;
          while (_DAT_2b1a6dcd52c[uVar3] == *psVar10) {
            psVar10 = psVar10 + 1;
            uVar3 = uVar3 + 1;
            lVar4 = lVar4 + -1;
            if (lVar4 == 0) goto LAB_2b1a6a69869;
          }
          if ((int)lVar4 == 0) {
LAB_2b1a6a69869:
            if (!bVar11) {
              return;
            }
            goto LAB_2b1a6a6986e;
          }
        }
        uVar7 = uVar7 + 1;
        uVar5 = uVar5 + 1;
        bVar11 = uVar7 < uVar6;
        if (uVar7 == uVar6) {
          return;
        }
      } while( true );
    }
    if (*_DAT_2b1a6dcd52c != 0x43) {
      uVar7 = 0;
      do {
        if (uVar6 - 1 == uVar7) {
          return;
        }
        lVar4 = uVar7 + 1;
        uVar7 = uVar7 + 1;
      } while (_DAT_2b1a6dcd52c[lVar4] != 0x43);
      if (uVar6 <= uVar7) {
        return;
      }
LAB_2b1a6a6986e:
      if ((int)uVar7 == -1) {
        return;
      }
    }
  }
  uVar1 = 0x13ab;
  if ((((_DAT_2b1a6a79cc8 != 0) &&
       (uVar1 = _DAT_2b1a6dcd510, _DAT_2b1a6dcd52c != (short *)0x2b1a6a79ccc)) &&
      (_DAT_2b1a6a79cc8 <= uVar2)) &&
     ((uVar2 = (uVar2 - _DAT_2b1a6a79cc8) + 1, uVar2 != 0 && (_DAT_2b1a6a79cc8 != 1)))) {
    uVar6 = 0;
    do {
      if (_DAT_2b1a6dcd52c[uVar6] == 0x55) {
        uVar5 = (uint)uVar6;
        psVar10 = (short *)&DAT_2b1a6a79cce;
        lVar4 = (ulonglong)_DAT_2b1a6a79cc8 - 1;
        while (uVar5 = uVar5 + 1, _DAT_2b1a6dcd52c[uVar5] == *psVar10) {
          psVar10 = psVar10 + 1;
          lVar4 = lVar4 + -1;
          if (lVar4 == 0) {
            return;
          }
        }
        if ((int)lVar4 == 0) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != uVar2);
  }
  _DAT_2b1a6dcd510 = uVar1;
  return;
}



/* Address: 2b1a6a69bf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a69bf0(void)

{
  int *piVar1;
  short *psVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  longlong lVar20;
  undefined1 *puVar21;
  uint uVar22;
  uint uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined8 uVar27;
  int iVar28;
  short sVar29;
  longlong lVar30;
  short *psVar31;
  int iVar32;
  undefined4 local_870;
  longlong local_86c;
  undefined4 local_860;
  longlong local_85c;
  undefined4 local_850;
  longlong local_84c;
  undefined4 local_840;
  longlong local_83c;
  undefined4 local_830;
  longlong local_82c;
  longlong local_820;
  undefined4 local_818;
  longlong local_814;
  int local_80c;
  undefined4 local_808;
  undefined8 local_804;
  undefined4 local_7f8;
  longlong local_7f4;
  undefined4 local_7e8;
  undefined8 local_7e4;
  int local_7d8;
  int local_7d4;
  undefined2 local_7d0;
  ushort local_7ce;
  undefined4 local_7cc;
  ulonglong local_7c8;
  undefined8 local_7c0;
  undefined4 local_7b8;
  undefined4 uStack_7b4;
  undefined4 local_7b0;
  undefined4 uStack_7ac;
  undefined8 local_7a8;
  undefined4 local_7a0;
  undefined4 local_798;
  short *local_794;
  uint local_788 [7];
  undefined1 *local_76c;
  undefined8 local_764;
  undefined8 local_75c;
  ulonglong local_750;
  longlong local_748;
  undefined8 local_740;
  longlong local_738;
  ulonglong local_730;
  undefined2 local_728;
  undefined2 local_726;
  undefined4 local_724;
  undefined8 local_720;
  undefined8 local_718;
  undefined8 local_710;
  undefined8 local_708;
  undefined8 local_700;
  undefined4 local_6f8;
  undefined8 local_6f0;
  undefined4 local_6e8;
  undefined4 uStack_6e4;
  undefined4 local_6e0;
  undefined4 uStack_6dc;
  undefined8 local_6d8;
  undefined8 local_6d0;
  undefined8 local_6c8;
  undefined8 local_6c0;
  undefined8 local_6b8;
  undefined4 local_6b0;
  undefined8 local_670;
  undefined8 local_668;
  undefined8 local_660;
  undefined8 local_658;
  undefined8 local_650;
  undefined8 local_648;
  undefined8 local_640;
  undefined8 local_638;
  undefined4 local_630;
  undefined8 local_5f0;
  undefined8 local_5e8;
  undefined8 local_5e0;
  undefined8 local_5d8;
  undefined4 local_5d0;
  int local_5cc;
  undefined4 local_5c4;
  undefined8 local_5c0;
  undefined8 local_5b8;
  undefined8 local_5b0;
  undefined8 local_5a8;
  undefined4 local_5a0;
  undefined8 local_570;
  undefined8 local_568;
  undefined8 local_560;
  undefined8 local_558;
  undefined4 local_550;
  undefined4 local_544;
  undefined8 local_540;
  undefined8 local_538;
  undefined8 local_530;
  undefined4 local_528;
  undefined4 uStack_524;
  undefined4 local_520;
  undefined1 local_4f0 [1200];
  
  local_830 = 0;
  local_7f8 = 0;
  local_840 = 0;
  local_850 = 0;
  local_860 = 0;
  local_870 = 0;
  local_808 = 0;
  local_818 = 0;
  local_7e8 = 0;
  local_798 = 0;
  local_82c = 0;
  local_7f4 = 0;
  local_83c = 0;
  local_84c = 0;
  local_85c = 0;
  local_86c = 0;
  local_804 = 0;
  local_814 = 0;
  local_7e4 = 0;
  local_794 = (short *)0x0;
  uVar24 = 0;
  FUN_2b1a6a604e0(&local_798,0x2b1a6a78188,0,0x2b1a6ba4628);
  puVar21 = local_4f0;
  (*(code *)0x7ff63a3fad20)(puVar21);
  if (DAT_2b1a6ba603c == '\x01') {
    if ((local_794 == (short *)0x0) || (*(int *)(local_794 + -2) == 0)) {
      sVar29 = 0;
      _DAT_2b1a6dcd510 = 0x13b1;
    }
    else {
      sVar29 = *local_794;
    }
    local_788[0] = 0x1000059;
    local_788[1] = 0xc;
    local_788[2] = 100;
    local_788[3] = 0;
    local_788[4] = 0;
    local_788[5] = 0;
    local_788[6] = 100;
    lVar12 = 0;
    local_764 = 0;
    local_75c = 0;
    do {
      local_76c = puVar21;
      if (local_788[lVar12 + 3] == 0) {
        if (lVar12 == 0) {
          if ((_DAT_2b1a6ba6034 == (short *)0x0) || (*_DAT_2b1a6ba6034 == 0)) goto LAB_2b1a6a6b93b;
          uVar24 = 0;
          uVar19 = 100;
          local_820 = CONCAT44(local_820._4_4_,*(undefined4 *)(_DAT_2b1a6ba6034 + -2));
          psVar31 = _DAT_2b1a6ba6034;
          goto LAB_2b1a6a6a7c0;
        }
        break;
      }
      lVar12 = lVar12 + 1;
    } while (lVar12 != 3);
    _DAT_2b1a6dcd510 = 0xfa6;
LAB_2b1a6a69de4:
    uVar24 = 0xffffffff;
  }
LAB_2b1a6a69de9:
  local_740 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4018,0);
  lVar12 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4018,0);
  cVar8 = DAT_2b1a6dcd7d8;
  cVar10 = DAT_2b1a6dcd7d0;
  local_808 = 0;
  local_818 = 0;
  local_804 = 0;
  local_814 = 0;
  local_668 = 0;
  local_660 = 0;
  local_658 = 0;
  local_650 = 0;
  local_648 = 0;
  local_640 = 0;
  local_638 = 0;
  local_630 = 0;
  local_6e8 = 0;
  uStack_6e4 = 0;
  local_6e0 = 0;
  uStack_6dc = 0;
  local_6d8 = 0;
  local_6d0 = 0;
  local_6c8 = 0;
  local_6c0 = 0;
  local_6b8 = 0;
  local_6b0 = 0;
  local_5a0 = 0;
  local_5a8 = 0;
  local_5b0 = 0;
  local_5b8 = 0;
  local_5c0 = 0;
  local_540 = 0;
  local_538 = 0;
  local_530 = 0;
  local_528 = 0;
  uStack_524 = 0;
  local_520 = 0;
  lVar12 = lVar12 + 0x83d600;
  local_7d0 = _DAT_2b1a179d27a;
  local_728 = _DAT_2b1a179d27a;
  local_7ce = 1;
  local_7cc = 0x80;
  local_726 = 1;
  local_724 = 0x80;
  local_7c8 = 0;
  local_7c0 = 0;
  local_7b8 = 0;
  uStack_7b4 = 0;
  local_7b0 = 0;
  uStack_7ac = 0;
  local_7a8 = 0;
  local_7a0 = 0;
  local_720 = 0;
  local_718 = 0;
  local_710 = 0;
  local_708 = 0;
  local_700 = 0;
  local_6f8 = 0;
  if ((int)uVar24 < 1) {
    iVar32 = _DAT_2b1a6dcd7c0;
    iVar11 = _DAT_2b1a6dcd7c8 * 0x3c;
    iVar28 = 0;
  }
  else {
    local_7d4 = _DAT_2b1a6dcd7c8 * 0x3c;
    local_7d8 = _DAT_2b1a6dcd7c0;
    iVar15 = _DAT_2b1a6dcd7c0 * 0x3c;
    local_80c = 0;
    local_738 = (longlong)local_7d4;
    uVar25 = 0;
    local_820 = lVar12;
    local_750 = uVar24;
    local_748 = lVar12;
    do {
      lVar12 = local_748;
      local_7e8 = 0;
      local_7e4 = 0;
      if (uVar25 == 100) {
LAB_2b1a6a6b9ea:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x19021e000001f6);
        goto LAB_2b1a6a6ba0a;
      }
      local_730 = uVar25;
      FUN_2b1a6a604e0(&local_7e8,local_4f0 + uVar25 * 0xc,0,0x2b1a6ba4648);
      (*(code *)0x7ff639cb0550)(0x2b1a1776bc8,&local_7d0,local_740,lVar12,&local_7e8,0x2b1a6a77f20);
      uVar24 = local_7c8 & 0xffffffff;
      if (0 < (int)local_7c8) {
        lVar12 = -1;
        uVar25 = 0;
        do {
          if ((uVar24 & 0xffffffff) <= uVar25) {
            (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x190230000001f6);
LAB_2b1a6a6b9aa:
            (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1c0235000001f6);
LAB_2b1a6a6b9ca:
            (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x130240000001f6);
            goto LAB_2b1a6a6b9ea;
          }
          uVar24 = (uVar24 & 0xffffffff) + lVar12;
          if ((local_7ce & 0x10) == 0) {
            uVar24 = uVar25;
          }
          cVar9 = (*(code *)0x7ff639cb0380)
                            (0x2b1a1776bc8,
                             *(undefined8 *)(CONCAT44(local_7b0,uStack_7b4) + 8 + uVar24 * 0x80));
          if (cVar9 != '\0') {
            (*(code *)0x7ff639cb03c0)(0x2b1a1776bc8,local_5d8);
            if ((local_7c8 & 0xffffffff) <= uVar25) goto LAB_2b1a6a6b9aa;
            uVar24 = (local_7c8 & 0xffffffff) + lVar12;
            if ((local_7ce & 0x10) == 0) {
              uVar24 = uVar25;
            }
            lVar20 = *(longlong *)(CONCAT44(local_7b0,uStack_7b4) + 0x10 + uVar24 * 0x80);
            if ((((local_5cc == 3) && (cVar10 == '\x01')) || ((local_5cc == 2 && (cVar8 == '\x01')))
                ) && (lVar20 < local_820)) {
              lVar30 = lVar20 - iVar15;
              lVar13 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
              if ((lVar13 < lVar30) ||
                 ((lVar13 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0), lVar30 <= lVar13 &&
                  (lVar20 = lVar20 + local_738, lVar13 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0),
                  lVar13 <= lVar20)))) {
                if ((local_7c8 & 0xffffffff) <= uVar25) goto LAB_2b1a6a6b9ca;
                uVar24 = (local_7c8 & 0xffffffff) + lVar12;
                if ((local_7ce & 0x10) == 0) {
                  uVar24 = uVar25;
                }
                local_820 = *(longlong *)(CONCAT44(local_7b0,uStack_7b4) + 0x10 + uVar24 * 0x80);
                local_6f0 = local_670;
                FUN_2b1a6a604e0(&local_6e8,&local_668,0,0);
                FUN_2b1a6a604e0(&uStack_6dc,(longlong)&local_660 + 4,0,0);
                FUN_2b1a6a604e0(&local_6d0,&local_650,0,0);
                FUN_2b1a6a604e0((longlong)&local_6c8 + 4,(longlong)&local_648 + 4,0,0);
                FUN_2b1a6a604e0(&local_6b8,&local_638,0,0);
                local_570 = local_5f0;
                local_568 = local_5e8;
                local_560 = local_5e0;
                local_558 = local_5d8;
                local_550 = local_5d0;
                local_544 = local_5c4;
                FUN_2b1a6a604e0(&local_540,&local_5c0,0,0);
                FUN_2b1a6a604e0((longlong)&local_538 + 4,(longlong)&local_5b8 + 4,0,0);
                FUN_2b1a6a604e0(&local_528,&local_5a8,0,0);
                FUN_2b1a6a604e0(&local_808,&local_6e8,0,0x2b1a6ba4658);
                FUN_2b1a6a604e0(&local_818,&local_528);
                local_80c = 1;
              }
            }
          }
          uVar24 = (ulonglong)(int)local_7c8;
          uVar25 = uVar25 + 1;
          lVar12 = lVar12 + -1;
        } while ((longlong)uVar25 < (longlong)uVar24);
      }
      FUN_2b1a6a60000(&local_7e8);
      uVar25 = local_730 + 1;
      lVar12 = local_820;
      iVar32 = local_7d8;
      iVar11 = local_7d4;
      iVar28 = local_80c;
    } while (uVar25 != local_750);
  }
  lVar20 = (longlong)(iVar32 * -0x3c + (int)lVar12);
  FUN_2b1a6a604e0(&DAT_2b1a6ca4080,0x2b1a6a77f40,0,0x2b1a6ba4678);
  if (((local_814 != 0) && (local_814 != 0xc)) && (0x1e < *(int *)(local_814 + -4))) {
    FUN_2b1a6a601e0(0x2b1a6dcd53c,local_814,0x1e);
    FUN_2b1a6a604e0(&local_870,0x2b1a6dcd53c,1,0x2b1a6ba4688);
    FUN_2b1a6a604e0(&local_818,&local_870,0,0x2b1a6ba4698);
  }
  lVar13 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
  if (lVar13 < lVar20) {
LAB_2b1a6a6a64f:
    if (iVar28 != 1) {
      puVar16 = (undefined4 *)0x2b1a6a79c90;
      uVar27 = 0x2b1a6ba4788;
LAB_2b1a6a6b036:
      FUN_2b1a6a604e0(&DAT_2b1a6ca4080,puVar16,0,uVar27);
      FUN_2b1a6a60700(&local_728);
      FUN_2b1a6a60700(&local_7d0);
      FUN_2b1a6a60000(&local_528);
      FUN_2b1a6a60000((longlong)&local_538 + 4);
      FUN_2b1a6a60000(&local_540);
      FUN_2b1a6a60000(&local_5a8);
      FUN_2b1a6a60000((longlong)&local_5b8 + 4);
      FUN_2b1a6a60000(&local_5c0);
      FUN_2b1a6a60000(&local_6b8);
      FUN_2b1a6a60000((longlong)&local_6c8 + 4);
      FUN_2b1a6a60000(&local_6d0);
      FUN_2b1a6a60000(&uStack_6dc);
      FUN_2b1a6a60000(&local_6e8);
      FUN_2b1a6a60000(&local_638);
      FUN_2b1a6a60000((longlong)&local_648 + 4);
      FUN_2b1a6a60000(&local_650);
      FUN_2b1a6a60000((longlong)&local_660 + 4);
      FUN_2b1a6a60000(&local_668);
      FUN_2b1a6a60000(&local_818);
      FUN_2b1a6a60000(&local_808);
      lVar12 = -0x4b0;
      do {
        if ((((*(int *)(&stack0xffffffffffffffc0 + lVar12) != 0) &&
             (lVar20 = *(longlong *)(&stack0xffffffffffffffc4 + lVar12), lVar20 != 0)) &&
            ((int *)(lVar20 + -0xc) != (int *)0x0)) && (*(int *)(lVar20 + -0xc) != 0)) {
          piVar1 = (int *)(lVar20 + -8);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
          }
        }
        *(undefined8 *)(&stack0xffffffffffffffc4 + lVar12) = 0;
        *(undefined4 *)(&stack0xffffffffffffffc0 + lVar12) = 0;
        lVar12 = lVar12 + 0xc;
      } while (lVar12 != 0);
      uVar24 = 0;
LAB_2b1a6a6b8ae:
      FUN_2b1a6a60000(&local_798);
      FUN_2b1a6a60000(&local_870);
      FUN_2b1a6a60000(&local_860);
      FUN_2b1a6a60000(&local_850);
      FUN_2b1a6a60000(&local_840);
      FUN_2b1a6a60000(&local_7f8);
      FUN_2b1a6a60000(&local_830);
      return uVar24 & 0xffffffff;
    }
    FUN_2b1a6a604e0(&local_870,0x2b1a6a79c38,0);
    lVar20 = CONCAT44(local_6e0,uStack_6e4);
    if (lVar20 == 0) {
LAB_2b1a6a6aafd:
      uVar19 = 0;
      FUN_2b1a6a604e0(&local_860,&local_870,0);
      uVar18 = _DAT_2b1a6a79bc8;
      uVar24 = (ulonglong)_DAT_2b1a6a79bc8;
      if ((uVar24 != 0) || (local_85c == 0)) {
        if (local_85c != 0) {
          uVar19 = *(uint *)(local_85c + -4);
        }
        uVar22 = _DAT_2b1a6a79bc8 + uVar19;
        cVar10 = FUN_2b1a6a60060(&local_860);
        if (cVar10 != '\0') {
          if (uVar24 != 0) {
            lVar20 = local_85c + (ulonglong)uVar19 * 2;
            if ((uVar18 < 0x10) || (lVar20 - 0x2b1a6a79bccU < 0x20)) {
              uVar25 = 0;
            }
            else {
              uVar26 = 0;
              uVar25 = (ulonglong)(uVar18 & 0xfffffff8);
              do {
                uVar5 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd0);
                uVar6 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd4);
                uVar7 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd8);
                puVar16 = (undefined4 *)(lVar20 + uVar26);
                *puVar16 = *(undefined4 *)(&DAT_2b1a6a79bcc + uVar26);
                puVar16[1] = uVar5;
                puVar16[2] = uVar6;
                puVar16[3] = uVar7;
                uVar26 = uVar26 + 0x10;
              } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
              if (uVar25 == uVar24) goto LAB_2b1a6a6abe2;
            }
            do {
              *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(&DAT_2b1a6a79bcc + uVar25 * 2);
              uVar25 = uVar25 + 1;
            } while (uVar24 != uVar25);
          }
LAB_2b1a6a6abe2:
          *(uint *)(local_85c + -4) = uVar22;
          *(undefined2 *)(local_85c + (ulonglong)uVar22 * 2) = 0;
          goto LAB_2b1a6a6abed;
        }
LAB_2b1a6a6ba0a:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x310263000001f9);
LAB_2b1a6a6ba2a:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x460263000001f9);
        goto LAB_2b1a6a6ba4a;
      }
LAB_2b1a6a6abed:
      FUN_2b1a6a604e0(&local_850,&local_860,0);
      lVar20 = CONCAT44(local_520,uStack_524);
      if (lVar20 != 0) {
        uVar19 = *(uint *)(lVar20 + -4);
        uVar24 = (ulonglong)uVar19;
        if ((uVar24 == 0) && (local_84c != 0)) goto LAB_2b1a6a6ad6d;
        if (local_84c == 0) {
          uVar25 = 0;
          uVar18 = uVar19;
        }
        else {
          uVar25 = (ulonglong)*(uint *)(local_84c + -4);
          uVar18 = uVar19 + *(uint *)(local_84c + -4);
        }
        cVar10 = FUN_2b1a6a60060(&local_850);
        if (cVar10 != '\0') {
          if (uVar24 != 0) {
            lVar13 = local_84c + uVar25 * 2;
            if (uVar19 < 0x10) {
              uVar25 = 0;
            }
            else if ((ulonglong)(lVar13 - lVar20) < 0x20) {
              uVar25 = 0;
            }
            else {
              uVar26 = 0;
              uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
              do {
                puVar16 = (undefined4 *)(lVar20 + uVar26);
                uVar5 = puVar16[1];
                uVar6 = puVar16[2];
                uVar7 = puVar16[3];
                puVar3 = (undefined4 *)(lVar13 + uVar26);
                *puVar3 = *puVar16;
                puVar3[1] = uVar5;
                puVar3[2] = uVar6;
                puVar3[3] = uVar7;
                uVar26 = uVar26 + 0x10;
              } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
              if (uVar25 == uVar24) goto LAB_2b1a6a6ad62;
            }
            do {
              *(undefined2 *)(lVar13 + uVar25 * 2) = *(undefined2 *)(lVar20 + uVar25 * 2);
              uVar25 = uVar25 + 1;
            } while (uVar24 != uVar25);
          }
LAB_2b1a6a6ad62:
          *(uint *)(local_84c + -4) = uVar18;
          *(undefined2 *)(local_84c + (ulonglong)uVar18 * 2) = 0;
          goto LAB_2b1a6a6ad6d;
        }
        goto LAB_2b1a6a6baaa;
      }
LAB_2b1a6a6ad6d:
      uVar19 = 0;
      FUN_2b1a6a604e0(&local_840,&local_850,0);
      uVar18 = _DAT_2b1a6a79be8;
      uVar24 = (ulonglong)_DAT_2b1a6a79be8;
      if ((uVar24 != 0) || (local_83c == 0)) {
        if (local_83c != 0) {
          uVar19 = *(uint *)(local_83c + -4);
        }
        uVar22 = _DAT_2b1a6a79be8 + uVar19;
        cVar10 = FUN_2b1a6a60060(&local_840);
        if (cVar10 == '\0') goto LAB_2b1a6a6ba2a;
        if (uVar24 != 0) {
          lVar20 = local_83c + (ulonglong)uVar19 * 2;
          if ((uVar18 < 0x10) || (lVar20 - 0x2b1a6a79becU < 0x20)) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf0);
              uVar6 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf4);
              uVar7 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf8);
              puVar16 = (undefined4 *)(lVar20 + uVar26);
              *puVar16 = *(undefined4 *)(&DAT_2b1a6a79bec + uVar26);
              puVar16[1] = uVar5;
              puVar16[2] = uVar6;
              puVar16[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6ae52;
          }
          do {
            *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(&DAT_2b1a6a79bec + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6ae52:
        *(uint *)(local_83c + -4) = uVar22;
        *(undefined2 *)(local_83c + (ulonglong)uVar22 * 2) = 0;
      }
      (*(code *)0x7ff63a0fcc50)(0x2b1a1776bc8,lVar12,3);
      FUN_2b1a6a604e0(&local_7f8,0x2b1a6dcd53c,1,0x2b1a6ba4758);
      FUN_2b1a6a604e0(&local_830,&local_840,0);
      lVar12 = local_7f4;
      if (local_7f4 == 0) {
LAB_2b1a6a6b01d:
        uVar27 = 0x2b1a6ba4778;
        puVar16 = &local_830;
        goto LAB_2b1a6a6b036;
      }
      uVar19 = *(uint *)(local_7f4 + -4);
      uVar24 = (ulonglong)uVar19;
      if ((uVar24 == 0) && (local_82c != 0)) goto LAB_2b1a6a6b01d;
      if (local_82c == 0) {
        uVar18 = 0;
        uVar22 = uVar19;
      }
      else {
        uVar18 = *(uint *)(local_82c + -4);
        uVar22 = uVar19 + uVar18;
      }
      cVar10 = FUN_2b1a6a60060(&local_830);
      if (cVar10 != '\0') {
        if (uVar24 != 0) {
          lVar20 = local_82c + (ulonglong)uVar18 * 2;
          if (uVar19 < 0x10) {
            uVar25 = 0;
          }
          else if ((ulonglong)(lVar20 - lVar12) < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar16 = (undefined4 *)(lVar12 + uVar26);
              uVar5 = puVar16[1];
              uVar6 = puVar16[2];
              uVar7 = puVar16[3];
              puVar3 = (undefined4 *)(lVar20 + uVar26);
              *puVar3 = *puVar16;
              puVar3[1] = uVar5;
              puVar3[2] = uVar6;
              puVar3[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6b012;
          }
          do {
            *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(lVar12 + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6b012:
        *(uint *)(local_82c + -4) = uVar22;
        *(undefined2 *)(local_82c + (ulonglong)uVar22 * 2) = 0;
        goto LAB_2b1a6a6b01d;
      }
    }
    else {
      uVar19 = *(uint *)(lVar20 + -4);
      uVar24 = (ulonglong)uVar19;
      if ((uVar24 == 0) && (local_86c != 0)) goto LAB_2b1a6a6aafd;
      if (local_86c == 0) {
        uVar25 = 0;
        uVar18 = uVar19;
      }
      else {
        uVar25 = (ulonglong)*(uint *)(local_86c + -4);
        uVar18 = uVar19 + *(uint *)(local_86c + -4);
      }
      cVar10 = FUN_2b1a6a60060(&local_870);
      if (cVar10 != '\0') {
        if (uVar24 != 0) {
          lVar13 = local_86c + uVar25 * 2;
          if (uVar19 < 0x10) {
            uVar25 = 0;
          }
          else if ((ulonglong)(lVar13 - lVar20) < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar16 = (undefined4 *)(lVar20 + uVar26);
              uVar5 = puVar16[1];
              uVar6 = puVar16[2];
              uVar7 = puVar16[3];
              puVar3 = (undefined4 *)(lVar13 + uVar26);
              *puVar3 = *puVar16;
              puVar3[1] = uVar5;
              puVar3[2] = uVar6;
              puVar3[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6aaf2;
          }
          do {
            *(undefined2 *)(lVar13 + uVar25 * 2) = *(undefined2 *)(lVar20 + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6aaf2:
        *(uint *)(local_86c + -4) = uVar18;
        *(undefined2 *)(local_86c + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2b1a6a6aafd;
      }
LAB_2b1a6a6ba8a:
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x230263000001f9);
LAB_2b1a6a6baaa:
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3a0263000001f9);
    }
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4f0263000001f9);
LAB_2b1a6a6baea:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x2b025c000001f9);
  }
  else {
    lVar30 = (longlong)(iVar11 + (int)lVar12);
    lVar13 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
    if (lVar30 < lVar13) goto LAB_2b1a6a6a64f;
    _DAT_2b1a6ca40a8 = lVar20;
    _DAT_2b1a6ca40b0 = lVar30;
    FUN_2b1a6a604e0(&local_870,0x2b1a6a79ba8);
    lVar20 = CONCAT44(local_6e0,uStack_6e4);
    if (lVar20 != 0) {
      uVar19 = *(uint *)(lVar20 + -4);
      uVar24 = (ulonglong)uVar19;
      if ((uVar24 == 0) && (local_86c != 0)) goto LAB_2b1a6a6b22d;
      if (local_86c == 0) {
        uVar25 = 0;
        uVar18 = uVar19;
      }
      else {
        uVar25 = (ulonglong)*(uint *)(local_86c + -4);
        uVar18 = uVar19 + *(uint *)(local_86c + -4);
      }
      cVar10 = FUN_2b1a6a60060(&local_870);
      if (cVar10 != '\0') {
        if (uVar24 != 0) {
          lVar13 = local_86c + uVar25 * 2;
          if (uVar19 < 0x10) {
            uVar25 = 0;
          }
          else if ((ulonglong)(lVar13 - lVar20) < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
            do {
              puVar16 = (undefined4 *)(lVar20 + uVar26);
              uVar5 = puVar16[1];
              uVar6 = puVar16[2];
              uVar7 = puVar16[3];
              puVar3 = (undefined4 *)(lVar13 + uVar26);
              *puVar3 = *puVar16;
              puVar3[1] = uVar5;
              puVar3[2] = uVar6;
              puVar3[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6b222;
          }
          do {
            *(undefined2 *)(lVar13 + uVar25 * 2) = *(undefined2 *)(lVar20 + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6b222:
        *(uint *)(local_86c + -4) = uVar18;
        *(undefined2 *)(local_86c + (ulonglong)uVar18 * 2) = 0;
        goto LAB_2b1a6a6b22d;
      }
      goto LAB_2b1a6a6baea;
    }
LAB_2b1a6a6b22d:
    uVar19 = 0;
    FUN_2b1a6a604e0(&local_860,&local_870,0,0x2b1a6ba46b8);
    uVar18 = _DAT_2b1a6a79bc8;
    uVar24 = (ulonglong)_DAT_2b1a6a79bc8;
    if ((uVar24 != 0) || (local_85c == 0)) {
      if (local_85c != 0) {
        uVar19 = *(uint *)(local_85c + -4);
      }
      uVar23 = _DAT_2b1a6a79bc8 + uVar19;
      uVar22 = 0x104;
      if ((0x103 < uVar23) &&
         ((0x7ffffffd < uVar23 || (uVar22 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar22)))) {
        uVar22 = 0x7ffffffe;
      }
      cVar10 = FUN_2b1a6a60060(&local_860,uVar22);
      if (cVar10 != '\0') {
        if (uVar24 != 0) {
          lVar20 = local_85c + (ulonglong)uVar19 * 2;
          if (uVar18 < 0x10) {
            uVar25 = 0;
          }
          else if (lVar20 - 0x2b1a6a79bccU < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd0);
              uVar6 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd4);
              uVar7 = *(undefined4 *)(uVar26 + 0x2b1a6a79bd8);
              puVar16 = (undefined4 *)(lVar20 + uVar26);
              *puVar16 = *(undefined4 *)(&DAT_2b1a6a79bcc + uVar26);
              puVar16[1] = uVar5;
              puVar16[2] = uVar6;
              puVar16[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6b352;
          }
          do {
            *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(&DAT_2b1a6a79bcc + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6b352:
        *(uint *)(local_85c + -4) = uVar23;
        *(undefined2 *)(local_85c + (ulonglong)uVar23 * 2) = 0;
        goto LAB_2b1a6a6b35d;
      }
LAB_2b1a6a6ba4a:
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x39025c000001f9);
LAB_2b1a6a6ba6a:
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4e025c000001f9);
      goto LAB_2b1a6a6ba8a;
    }
LAB_2b1a6a6b35d:
    FUN_2b1a6a604e0(&local_850,&local_860);
    lVar20 = CONCAT44(local_520,uStack_524);
    if (lVar20 == 0) {
LAB_2b1a6a6b48d:
      uVar19 = 0;
      FUN_2b1a6a604e0(&local_840,&local_850,0,0x2b1a6ba46d8);
      uVar18 = _DAT_2b1a6a79be8;
      uVar24 = (ulonglong)_DAT_2b1a6a79be8;
      if ((uVar24 == 0) && (local_83c != 0)) {
LAB_2b1a6a6b5bd:
        (*(code *)0x7ff63a0fcc50)(0x2b1a1776bc8,lVar12,3);
        FUN_2b1a6a604e0(&local_7f8,0x2b1a6dcd53c,1,0x2b1a6ba46e8);
        FUN_2b1a6a604e0(&local_830,&local_840,0);
        lVar12 = local_7f4;
        if (local_7f4 != 0) {
          uVar19 = *(uint *)(local_7f4 + -4);
          uVar24 = (ulonglong)uVar19;
          if ((uVar24 != 0) || (local_82c == 0)) {
            if (local_82c == 0) {
              uVar18 = 0;
              uVar22 = uVar19;
            }
            else {
              uVar18 = *(uint *)(local_82c + -4);
              uVar22 = uVar19 + uVar18;
            }
            cVar10 = FUN_2b1a6a60060(&local_830);
            if (cVar10 == '\0') goto LAB_2b1a6a6bb2a;
            if (uVar24 != 0) {
              lVar20 = local_82c + (ulonglong)uVar18 * 2;
              if (uVar19 < 0x10) {
                uVar25 = 0;
              }
              else if ((ulonglong)(lVar20 - lVar12) < 0x20) {
                uVar25 = 0;
              }
              else {
                uVar26 = 0;
                uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
                do {
                  puVar16 = (undefined4 *)(lVar12 + uVar26);
                  uVar5 = puVar16[1];
                  uVar6 = puVar16[2];
                  uVar7 = puVar16[3];
                  puVar3 = (undefined4 *)(lVar20 + uVar26);
                  *puVar3 = *puVar16;
                  puVar3[1] = uVar5;
                  puVar3[2] = uVar6;
                  puVar3[3] = uVar7;
                  uVar26 = uVar26 + 0x10;
                } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
                if (uVar25 == uVar24) goto LAB_2b1a6a6b722;
              }
              do {
                *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(lVar12 + uVar25 * 2);
                uVar25 = uVar25 + 1;
              } while (uVar24 != uVar25);
            }
LAB_2b1a6a6b722:
            *(uint *)(local_82c + -4) = uVar22;
            *(undefined2 *)(local_82c + (ulonglong)uVar22 * 2) = 0;
          }
        }
        FUN_2b1a6a604e0(&DAT_2b1a6ca4080,&local_830,0,0x2b1a6ba4708);
        FUN_2b1a6a60700(&local_728);
        FUN_2b1a6a60700(&local_7d0);
        FUN_2b1a6a60000(&local_528);
        FUN_2b1a6a60000((longlong)&local_538 + 4);
        FUN_2b1a6a60000(&local_540);
        FUN_2b1a6a60000(&local_5a8);
        FUN_2b1a6a60000((longlong)&local_5b8 + 4);
        FUN_2b1a6a60000(&local_5c0);
        FUN_2b1a6a60000(&local_6b8);
        FUN_2b1a6a60000((longlong)&local_6c8 + 4);
        FUN_2b1a6a60000(&local_6d0);
        FUN_2b1a6a60000(&uStack_6dc);
        FUN_2b1a6a60000(&local_6e8);
        FUN_2b1a6a60000(&local_638);
        FUN_2b1a6a60000((longlong)&local_648 + 4);
        FUN_2b1a6a60000(&local_650);
        FUN_2b1a6a60000((longlong)&local_660 + 4);
        FUN_2b1a6a60000(&local_668);
        FUN_2b1a6a60000(&local_818);
        FUN_2b1a6a60000(&local_808);
        lVar12 = -0x4b0;
        do {
          if ((((*(int *)(&stack0xffffffffffffffc0 + lVar12) != 0) &&
               (lVar20 = *(longlong *)(&stack0xffffffffffffffc4 + lVar12), lVar20 != 0)) &&
              ((int *)(lVar20 + -0xc) != (int *)0x0)) && (*(int *)(lVar20 + -0xc) != 0)) {
            piVar1 = (int *)(lVar20 + -8);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
            }
          }
          *(undefined8 *)(&stack0xffffffffffffffc4 + lVar12) = 0;
          *(undefined4 *)(&stack0xffffffffffffffc0 + lVar12) = 0;
          lVar12 = lVar12 + 0xc;
        } while (lVar12 != 0);
        uVar24 = 0x2b1a1776b01;
        goto LAB_2b1a6a6b8ae;
      }
      if (local_83c != 0) {
        uVar19 = *(uint *)(local_83c + -4);
      }
      uVar23 = _DAT_2b1a6a79be8 + uVar19;
      uVar22 = 0x104;
      if ((0x103 < uVar23) &&
         ((0x7ffffffd < uVar23 || (uVar22 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar22)))) {
        uVar22 = 0x7ffffffe;
      }
      cVar10 = FUN_2b1a6a60060(&local_840,uVar22);
      if (cVar10 != '\0') {
        if (uVar24 != 0) {
          lVar20 = local_83c + (ulonglong)uVar19 * 2;
          if (uVar18 < 0x10) {
            uVar25 = 0;
          }
          else if (lVar20 - 0x2b1a6a79becU < 0x20) {
            uVar25 = 0;
          }
          else {
            uVar26 = 0;
            uVar25 = (ulonglong)(uVar18 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf0);
              uVar6 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf4);
              uVar7 = *(undefined4 *)(uVar26 + 0x2b1a6a79bf8);
              puVar16 = (undefined4 *)(lVar20 + uVar26);
              *puVar16 = *(undefined4 *)(&DAT_2b1a6a79bec + uVar26);
              puVar16[1] = uVar5;
              puVar16[2] = uVar6;
              puVar16[3] = uVar7;
              uVar26 = uVar26 + 0x10;
            } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
            if (uVar25 == uVar24) goto LAB_2b1a6a6b5b2;
          }
          do {
            *(undefined2 *)(lVar20 + uVar25 * 2) = *(undefined2 *)(&DAT_2b1a6a79bec + uVar25 * 2);
            uVar25 = uVar25 + 1;
          } while (uVar24 != uVar25);
        }
LAB_2b1a6a6b5b2:
        *(uint *)(local_83c + -4) = uVar23;
        *(undefined2 *)(local_83c + (ulonglong)uVar23 * 2) = 0;
        goto LAB_2b1a6a6b5bd;
      }
      goto LAB_2b1a6a6ba6a;
    }
    uVar19 = *(uint *)(lVar20 + -4);
    uVar24 = (ulonglong)uVar19;
    if ((uVar24 == 0) && (local_84c != 0)) goto LAB_2b1a6a6b48d;
    if (local_84c == 0) {
      uVar25 = 0;
      uVar18 = uVar19;
    }
    else {
      uVar25 = (ulonglong)*(uint *)(local_84c + -4);
      uVar18 = uVar19 + *(uint *)(local_84c + -4);
    }
    cVar10 = FUN_2b1a6a60060(&local_850);
    if (cVar10 != '\0') {
      if (uVar24 != 0) {
        lVar13 = local_84c + uVar25 * 2;
        if (uVar19 < 0x10) {
          uVar25 = 0;
        }
        else if ((ulonglong)(lVar13 - lVar20) < 0x20) {
          uVar25 = 0;
        }
        else {
          uVar26 = 0;
          uVar25 = (ulonglong)(uVar19 & 0xfffffff8);
          do {
            puVar16 = (undefined4 *)(lVar20 + uVar26);
            uVar5 = puVar16[1];
            uVar6 = puVar16[2];
            uVar7 = puVar16[3];
            puVar3 = (undefined4 *)(lVar13 + uVar26);
            *puVar3 = *puVar16;
            puVar3[1] = uVar5;
            puVar3[2] = uVar6;
            puVar3[3] = uVar7;
            uVar26 = uVar26 + 0x10;
          } while ((uVar24 * 2 & 0xfffffffffffffff0) != uVar26);
          if (uVar25 == uVar24) goto LAB_2b1a6a6b482;
        }
        do {
          *(undefined2 *)(lVar13 + uVar25 * 2) = *(undefined2 *)(lVar20 + uVar25 * 2);
          uVar25 = uVar25 + 1;
        } while (uVar24 != uVar25);
      }
LAB_2b1a6a6b482:
      *(uint *)(local_84c + -4) = uVar18;
      *(undefined2 *)(local_84c + (ulonglong)uVar18 * 2) = 0;
      goto LAB_2b1a6a6b48d;
    }
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x42025c000001f9);
LAB_2b1a6a6bb2a:
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x57025c000001f9);
  pcVar4 = (code *)swi(3);
  uVar24 = (*pcVar4)();
  return uVar24;
LAB_2b1a6a6a7c0:
  uVar25 = 0xffffffff;
  uVar18 = 0;
  do {
    uVar22 = uVar18;
    iVar32 = (int)uVar25;
    uVar23 = iVar32 + 1;
    uVar25 = (ulonglong)uVar23;
    if (psVar31[uVar25] == 0) break;
    uVar18 = uVar22 + 1;
  } while (psVar31[uVar25] != sVar29);
  if (0x7ffffffe < uVar23) {
    if ((local_788[0] & 0x10000) != 0) {
      (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,local_788);
    }
    uVar24 = 0xffffffff;
    _DAT_2b1a6dcd510 = 0x13b0;
    goto LAB_2b1a6a69de9;
  }
  uVar18 = (uint)uVar24;
  if (uVar19 <= uVar18) {
    if ((local_788[0] & 0x10000) == 0) {
      uVar24 = 0xffffffff;
      _DAT_2b1a6dcd510 = 0xfa7;
      goto LAB_2b1a6a69de9;
    }
    uVar19 = (uint)local_820;
    if (uVar23 != 0) {
      uVar19 = (uint)local_820 / uVar23;
    }
    uVar19 = uVar18 + 1 + uVar19;
    iVar11 = (*(code *)0x7ff63a0da0e0)(0x2b1a1776bc8,local_788,uVar19,0x20 - (uVar19 & 0x1f));
    puVar21 = local_76c;
    if (iVar11 < 0) goto LAB_2b1a6a69de4;
  }
  puVar16 = *(undefined4 **)(puVar21 + uVar24 * 0xc + 4);
  puVar3 = (undefined4 *)(puVar21 + uVar24 * 0xc);
  puVar17 = puVar16 + -3;
  if (puVar16 == (undefined4 *)0x0) {
    puVar17 = (uint *)0x0;
  }
  if ((*(int *)(puVar21 + uVar24 * 0xc) == 0) || (puVar17 == (uint *)0x0)) {
LAB_2b1a6a6a8c1:
    puVar14 = (undefined4 *)(*(code *)0x7ff63a101190)(0x2b1a1776bc8);
    if (puVar14 != (undefined4 *)0x0) {
      puVar16 = puVar14 + 3;
      *(undefined8 *)(puVar14 + 1) = 1;
      *(undefined2 *)(puVar14 + 3) = 0;
      *(undefined4 **)(puVar3 + 1) = puVar16;
      *puVar3 = *puVar14;
      goto LAB_2b1a6a6a8f9;
    }
    _DAT_2b1a6dcd510 = 0x13aa;
  }
  else {
    if ((*puVar17 < uVar23) || (puVar17[1] != 1)) {
      if (*puVar17 != 0) {
        puVar17 = puVar17 + 1;
        *puVar17 = *puVar17 - 1;
        if (*puVar17 == 0) {
          (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
        }
      }
      *(undefined8 *)(puVar3 + 1) = 0;
      *puVar3 = 0;
      goto LAB_2b1a6a6a8c1;
    }
LAB_2b1a6a6a8f9:
    if (uVar23 != 0) {
      if (uVar23 < 8) {
        uVar24 = 0;
      }
      else {
        uVar24 = 0;
        if (0x1f < (ulonglong)((longlong)puVar16 - (longlong)psVar31)) {
          uVar26 = 0;
          uVar24 = (ulonglong)(uVar23 & 0x7ffffff8);
          do {
            psVar2 = psVar31 + uVar26;
            uVar5 = *(undefined4 *)(psVar2 + 2);
            uVar6 = *(undefined4 *)(psVar2 + 4);
            uVar7 = *(undefined4 *)(psVar2 + 6);
            puVar3 = (undefined4 *)((longlong)puVar16 + uVar26 * 2);
            *puVar3 = *(undefined4 *)psVar2;
            puVar3[1] = uVar5;
            puVar3[2] = uVar6;
            puVar3[3] = uVar7;
            uVar26 = uVar26 + 8;
          } while ((uVar22 & 0x7ffffff8) != uVar26);
          if (uVar24 == uVar25) goto LAB_2b1a6a6a982;
        }
      }
      do {
        *(short *)((longlong)puVar16 + uVar24 * 2) = psVar31[uVar24];
        uVar24 = uVar24 + 1;
      } while (uVar22 != uVar24);
    }
LAB_2b1a6a6a982:
    puVar16[-1] = uVar23;
    *(undefined2 *)((longlong)puVar16 + uVar25 * 2) = 0;
  }
  uVar24 = (ulonglong)(uVar18 + 1);
  if (psVar31[uVar25] == 0) goto LAB_2b1a6a6b905;
  psVar31 = psVar31 + (iVar32 + 2);
  goto LAB_2b1a6a6a7c0;
LAB_2b1a6a6b905:
  if ((local_788[0] & 0x10000) != 0) {
    (*(code *)0x7ff63a0da0e0)(0x2b1a1776bc8,local_788,uVar24,0);
  }
  if (uVar18 + 1 == 0) {
LAB_2b1a6a6b93b:
    FUN_2b1a6a604e0(local_4f0,0x2b1a6a79b48,0,0x2b1a6ba4638);
    uVar24 = 1;
  }
  goto LAB_2b1a6a69de9;
}



/* Address: 2b1a6a6bb50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a6bb50(void)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  ulonglong unaff_RSI;
  
  iVar7 = _DAT_2b1a6dcd728;
  iVar4 = _DAT_2b1a6dcd718;
  lVar1 = _DAT_2b1a6ca40c8;
  if (DAT_2b1a6dcd680 == '\x01') {
    lVar5 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,0);
    if (lVar1 != lVar5) {
      _DAT_2b1a6ca4078 = FUN_2b1a6a62690();
      _DAT_2b1a6ca40c8 = (*(code *)0x7ff63a103b50)(0x2b1a1776bc8,0x2b1a6a77f20,0x4001,0);
    }
    uVar6 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
    cVar2 = FUN_2b1a6a752a0(uVar6);
    iVar7 = (cVar2 == '\0') - 3;
    iVar4 = _DAT_2b1a6dcd718 + iVar7;
    uVar8 = iVar7 + _DAT_2b1a6dcd728;
    unaff_RSI = (ulonglong)uVar8;
    iVar7 = iVar4 + _DAT_2b1a6ca4078;
    iVar4 = _DAT_2b1a6ca4078 + -0x18 + iVar4;
    if (iVar7 < 0x18) {
      iVar4 = iVar7;
    }
    iVar7 = iVar4 + 0x18;
    if (-1 < iVar4) {
      iVar7 = iVar4;
    }
    iVar4 = _DAT_2b1a6ca4078 + -0x18 + uVar8;
    if ((int)(uVar8 + _DAT_2b1a6ca4078) < 0x18) {
      iVar4 = uVar8 + _DAT_2b1a6ca4078;
    }
    iVar3 = iVar4 + 0x18;
    if (-1 < iVar4) {
      iVar3 = iVar4;
    }
    if ((iVar7 < iVar3) &&
       (((iVar4 = FUN_2b1a6a68550(), iVar4 == iVar7 &&
         (iVar4 = FUN_2b1a6a75480(), _DAT_2b1a6dcd720 <= iVar4)) ||
        (iVar4 = FUN_2b1a6a68550(), iVar7 < iVar4)))) {
      iVar4 = FUN_2b1a6a68550();
      unaff_RSI = CONCAT71((uint7)(uint3)(uVar8 >> 8),1);
      if ((iVar4 < iVar3) ||
         ((iVar4 = FUN_2b1a6a68550(), uVar8 = _DAT_2b1a6dcd730, iVar4 == iVar3 &&
          (iVar4 = FUN_2b1a6a75480(), iVar4 < (int)uVar8)))) goto LAB_2b1a6a6be0d;
    }
    if (iVar3 < iVar7) {
      iVar4 = FUN_2b1a6a68550();
      if ((iVar4 != iVar7) || (iVar4 = FUN_2b1a6a75480(), _DAT_2b1a6dcd720 <= iVar4)) {
        iVar4 = FUN_2b1a6a68550();
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),1);
        if (iVar7 <= iVar4) goto LAB_2b1a6a6be0d;
      }
      iVar4 = FUN_2b1a6a68550();
      if (iVar4 <= iVar3) {
        iVar4 = FUN_2b1a6a68550();
        uVar8 = _DAT_2b1a6dcd730;
        if (iVar4 == iVar3) {
          unaff_RSI = (ulonglong)_DAT_2b1a6dcd730;
          iVar4 = FUN_2b1a6a75480();
          if ((int)uVar8 < iVar4) goto LAB_2b1a6a6be0b;
        }
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),1);
        goto LAB_2b1a6a6be0d;
      }
    }
  }
  else if (DAT_2b1a6dcd680 == '\0') {
    if ((_DAT_2b1a6dcd718 < _DAT_2b1a6dcd728) &&
       (((iVar3 = FUN_2b1a6a68550(), iVar3 == iVar4 &&
         (iVar3 = FUN_2b1a6a75480(), _DAT_2b1a6dcd720 <= iVar3)) ||
        (iVar3 = FUN_2b1a6a68550(), iVar4 < iVar3)))) {
      iVar3 = FUN_2b1a6a68550();
      unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),1);
      if ((iVar3 < iVar7) ||
         ((iVar3 = FUN_2b1a6a68550(), uVar8 = _DAT_2b1a6dcd730, iVar3 == iVar7 &&
          (iVar3 = FUN_2b1a6a75480(), iVar3 < (int)uVar8)))) goto LAB_2b1a6a6be0d;
    }
    if (iVar7 < iVar4) {
      iVar3 = FUN_2b1a6a68550();
      if ((iVar3 != iVar4) || (iVar3 = FUN_2b1a6a75480(), _DAT_2b1a6dcd720 <= iVar3)) {
        iVar3 = FUN_2b1a6a68550();
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),1);
        if (iVar4 <= iVar3) goto LAB_2b1a6a6be0d;
      }
      iVar4 = FUN_2b1a6a68550();
      if (iVar4 <= iVar7) {
        iVar4 = FUN_2b1a6a68550();
        uVar8 = _DAT_2b1a6dcd730;
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),1);
        if ((iVar4 != iVar7) || (iVar4 = FUN_2b1a6a75480(), iVar4 <= (int)uVar8))
        goto LAB_2b1a6a6be0d;
      }
    }
  }
LAB_2b1a6a6be0b:
  unaff_RSI = 0;
LAB_2b1a6a6be0d:
  return unaff_RSI & 0xffffffff;
}



/* Address: 2b1a6a6be50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b1a6a6be50(uint param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 local_50;
  ulonglong local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined4 local_20;
  
  local_50 = 0x800010058;
  uVar5 = 0x2b1;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_28 = 0;
  local_20 = 0;
  iVar2 = (*(code *)0x7ff63a0e49f0)
                    (0x2b1a1776bc8,0x55,4,0x590008,0x2b1a6a77f20,0x520004,param_2,0x520004,param_3,
                     0x520004,5);
  if (iVar2 == -1) {
    uVar5 = (undefined4)_DAT_2b1a6a779e0;
    uVar6 = (undefined4)((ulonglong)_DAT_2b1a6a779e0 >> 0x20);
  }
  else {
    local_50._0_4_ = CONCAT22(0x11,(undefined2)local_50);
    (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,iVar2,0,0,CONCAT44(uVar5,0x14),&local_50);
    if ((uint)local_48 <= param_1) {
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0xd09b6000001f6);
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    uVar3 = (local_48 & 0xffffffff) + ~(ulonglong)param_1;
    if ((local_50 & 0x100000) == 0) {
      uVar3 = (ulonglong)param_1;
    }
    uVar4 = *(undefined8 *)(CONCAT44(local_30,uStack_34) + uVar3 * 8);
    uVar5 = (undefined4)uVar4;
    uVar6 = (undefined4)((ulonglong)uVar4 >> 0x20);
  }
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&local_50);
  return CONCAT44(uVar6,uVar5);
}



/* Address: 2b1a6a6bfd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b1a6a6bfd0(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0x2b1;
  iVar2 = (*(code *)0x7ff63a0e49f0)
                    (0x2b1a1776bc8,0x53,3,0x590008,0x2b1a6a77f20,0x520004,param_1,0x520004,param_2);
  if (iVar2 == -1) {
    return _DAT_2b1a6a779e8;
  }
  if ((_DAT_2b1a6ba61b2 & 0xf) != 0) {
    _DAT_2b1a6ba61b2 = _DAT_2b1a6ba61b2 | 0x10;
  }
  (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,iVar2,0,0,CONCAT44(uVar5,0x14),&DAT_2b1a6ba61b0);
  if (1 < (ulonglong)_DAT_2b1a6ba61b8) {
    lVar3 = 1;
    if ((_DAT_2b1a6ba61b2 & 0x10) != 0) {
      lVar3 = (ulonglong)_DAT_2b1a6ba61b8 - 2;
    }
    return *(undefined8 *)(_DAT_2b1a6ba61cc + lVar3 * 8);
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0xd09ce000001f6);
  pcVar1 = (code *)swi(3);
  uVar4 = (*pcVar1)();
  return uVar4;
}



/* Address: 2b1a6a6c0f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6c0f0(int param_1)

{
  double dVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined4 extraout_XMM0_Dc;
  undefined4 extraout_XMM0_Dc_00;
  undefined4 extraout_XMM0_Dd;
  undefined4 extraout_XMM0_Dd_00;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  undefined4 local_1a8;
  undefined8 local_1a4;
  double local_198;
  undefined8 uStack_190;
  double local_188;
  undefined8 uStack_180;
  double local_170;
  double local_168;
  double local_160;
  double local_158;
  double local_150;
  double local_148;
  double local_140;
  double local_138;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double local_110;
  undefined1 local_108 [200];
  
  local_1a8 = 0;
  local_1a4 = 0;
  uVar2 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
  (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,uVar2,local_108);
  local_188 = (double)FUN_2b1a6a6be50(0,0xf,5);
  uStack_180 = CONCAT44(extraout_XMM0_Dd,extraout_XMM0_Dc);
  if ((longlong)local_188 != -0x8000000000000000) {
    dVar17 = (double)(longlong)local_188;
    local_188 = (double)(longlong)
                        ((local_188 - dVar17) * _DAT_2b1a6a779f0 +
                        *(double *)((ulonglong)(0.0 < local_188) * 8 + 0x2b1a6a779f8)) /
                _DAT_2b1a6a779f0 + dVar17;
    uStack_180 = 0;
  }
  local_198 = (double)FUN_2b1a6a6be50(0,0x1e,5);
  uStack_190 = CONCAT44(extraout_XMM0_Dd_00,extraout_XMM0_Dc_00);
  if ((longlong)local_198 != -0x8000000000000000) {
    dVar17 = (double)(longlong)local_198;
    local_198 = (double)(longlong)
                        ((local_198 - dVar17) * _DAT_2b1a6a779f0 +
                        *(double *)((ulonglong)(0.0 < local_198) * 8 + 0x2b1a6a779f8)) /
                _DAT_2b1a6a779f0 + dVar17;
    uStack_190 = 0;
  }
  dVar17 = (double)FUN_2b1a6a6be50(0,0x4001,5);
  if ((longlong)dVar17 != -0x8000000000000000) {
    dVar18 = (double)(longlong)dVar17;
    dVar17 = (double)(longlong)
                     ((dVar17 - dVar18) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar17) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar18;
  }
  dVar18 = (double)FUN_2b1a6a6be50(0,0x4004,5);
  if ((longlong)dVar18 != -0x8000000000000000) {
    dVar19 = (double)(longlong)dVar18;
    dVar18 = (double)(longlong)
                     ((dVar18 - dVar19) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar18) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar19;
  }
  dVar19 = (double)FUN_2b1a6a6be50(0,0x4018,5);
  if ((longlong)dVar19 != -0x8000000000000000) {
    dVar20 = (double)(longlong)dVar19;
    dVar19 = (double)(longlong)
                     ((dVar19 - dVar20) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar19) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar20;
  }
  dVar20 = (double)FUN_2b1a6a6be50(1,0x1e,5);
  if ((longlong)dVar20 != -0x8000000000000000) {
    dVar21 = (double)(longlong)dVar20;
    dVar20 = (double)(longlong)
                     ((dVar20 - dVar21) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar20) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar21;
  }
  dVar21 = (double)FUN_2b1a6a6be50(1,0x4001,5);
  if ((longlong)dVar21 != -0x8000000000000000) {
    dVar22 = (double)(longlong)dVar21;
    dVar21 = (double)(longlong)
                     ((dVar21 - dVar22) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar21) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar22;
  }
  dVar22 = (double)FUN_2b1a6a6be50(1,0x4004,5);
  if ((longlong)dVar22 != -0x8000000000000000) {
    dVar1 = (double)(longlong)dVar22;
    dVar22 = (double)(longlong)
                     ((dVar22 - dVar1) * _DAT_2b1a6a779f0 +
                     *(double *)((ulonglong)(0.0 < dVar22) * 8 + 0x2b1a6a779f8)) / _DAT_2b1a6a779f0
             + dVar1;
  }
  FUN_2b1a6a68f10();
  lVar5 = 0;
  puVar3 = (undefined8 *)&DAT_2b1a6ba61f0;
  do {
    puVar7 = (undefined8 *)(lVar5 + 0x2b1a6ca4360);
    lVar5 = lVar5 + 0x48;
    puVar8 = puVar3;
    for (lVar4 = 9; lVar4 != 0; lVar4 = lVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar3 = puVar3 + 0x14;
  } while (lVar5 != 0xc888);
  if (DAT_2b1a6ca4350 == '\x01') {
    local_110 = _DAT_2b1a6ca4348;
    local_118 = _DAT_2b1a6ca42c8;
    local_120 = _DAT_2b1a6ca4308;
    local_128 = _DAT_2b1a6ca42d0;
    local_130 = _DAT_2b1a6ca4310;
    local_138 = _DAT_2b1a6ca42d8;
    local_140 = _DAT_2b1a6ca4318;
    local_148 = _DAT_2b1a6ca42e0;
    local_150 = _DAT_2b1a6ca4320;
    local_158 = _DAT_2b1a6ca42e8;
    local_160 = _DAT_2b1a6ca4328;
    local_168 = _DAT_2b1a6ca42f0;
    local_170 = _DAT_2b1a6ca4330;
    iVar6 = 0;
    lVar5 = -0x1bda0;
    while ((((_DAT_2b1a6a77a08 <= dVar20 && _DAT_2b1a6a77a08 <= dVar19) &&
            _DAT_2b1a6a77a08 <= dVar21) &&
           ((_DAT_2b1a6a77a08 <= dVar18 && _DAT_2b1a6a77a08 <= dVar17) &&
           (_DAT_2b1a6a77a08 <= local_188 && _DAT_2b1a6a77a08 <= local_198))) &&
           _DAT_2b1a6a77a08 <= dVar22) {
      dVar1 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1f98) - local_188) &
                      _DAT_2b1a6a77a10) * _DAT_2b1a6ca42c8;
      uVar9 = -(ulonglong)(_DAT_2b1a6ca4308 < dVar1);
      dVar29 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fa0) - local_198) &
                       _DAT_2b1a6a77a10) * _DAT_2b1a6ca42d0;
      uVar10 = -(ulonglong)(_DAT_2b1a6ca4310 < dVar29);
      dVar23 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fa8) - dVar17) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca42d8;
      uVar11 = -(ulonglong)(_DAT_2b1a6ca4318 < dVar23);
      dVar24 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fb0) - dVar18) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca42e0;
      uVar12 = -(ulonglong)(_DAT_2b1a6ca4320 < dVar24);
      dVar25 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fb8) - dVar19) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca42e8;
      uVar13 = -(ulonglong)(_DAT_2b1a6ca4328 < dVar25);
      dVar26 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fc0) - dVar20) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca42f0;
      uVar14 = -(ulonglong)(_DAT_2b1a6ca4330 < dVar26);
      dVar27 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fc8) - dVar21) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca42f8;
      uVar15 = -(ulonglong)(_DAT_2b1a6ca4338 < dVar27);
      dVar28 = (double)((ulonglong)(*(double *)(lVar5 + 0x2b1a6bc1fd0) - dVar22) & _DAT_2b1a6a77a10)
               * _DAT_2b1a6ca4300;
      uVar16 = -(ulonglong)(_DAT_2b1a6ca4340 < dVar28);
      if (((double)(uVar16 & _DAT_2b1a6a77a20 | ~uVar16 & (ulonglong)dVar28) +
          (double)(uVar15 & _DAT_2b1a6a77a20 | ~uVar15 & (ulonglong)dVar27) +
          (double)(uVar14 & _DAT_2b1a6a77a20 | ~uVar14 & (ulonglong)dVar26) +
          (double)(uVar13 & _DAT_2b1a6a77a20 | ~uVar13 & (ulonglong)dVar25) +
          (double)(uVar12 & _DAT_2b1a6a77a20 | ~uVar12 & (ulonglong)dVar24) +
          (double)(uVar11 & _DAT_2b1a6a77a20 | ~uVar11 & (ulonglong)dVar23) +
          (double)(uVar10 & _DAT_2b1a6a77a20 | ~uVar10 & (ulonglong)dVar29) +
          (double)(uVar9 & _DAT_2b1a6a77a20 | ~uVar9 & (ulonglong)(dVar1 + 0.0))) * _DAT_2b1a6a77a28
          < _DAT_2b1a6ca4348) {
        if (iVar6 < 0x151) {
          if (iVar6 < 0xa2) {
            if (((iVar6 - 0x18U < 0x3f) &&
                ((0x4000100020000001U >> ((ulonglong)(iVar6 - 0x18U) & 0x3f) & 1) != 0)) ||
               (iVar6 == 0x15)) break;
          }
          else if (((iVar6 - 0xe5U < 0x21) &&
                   ((0x100010005U >> ((ulonglong)(iVar6 - 0xe5U) & 0x3f) & 1) != 0)) ||
                  ((iVar6 - 0xa2U < 0x24 &&
                   ((0x800100001U >> ((ulonglong)(iVar6 - 0xa2U) & 0x3f) & 1) != 0)))) break;
        }
        else {
          if (iVar6 < 0x1e4) {
            if ((0x37 < iVar6 - 0x151U) ||
               ((0x80000000080201U >> ((ulonglong)(iVar6 - 0x151U) & 0x3f) & 1) == 0))
            goto LAB_2b1a6a6c9a6;
            break;
          }
          if (((iVar6 - 0x259U < 2) || (iVar6 == 0x1e4)) || (iVar6 == 0x20f)) break;
        }
        goto LAB_2b1a6a6c9a6;
      }
      iVar6 = iVar6 + 1;
      lVar5 = lVar5 + 0xa0;
      if (lVar5 == 0) goto LAB_2b1a6a6c9a1;
    }
    goto LAB_2b1a6a6cca7;
  }
LAB_2b1a6a6c9a1:
  iVar6 = -1;
LAB_2b1a6a6c9a6:
  (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x2f);
  if ((_DAT_2b1a6ba6000 <= _DAT_2b1a6ba61a8) || (iVar6 == -1)) goto LAB_2b1a6a6cca7;
  if ((*(double *)(&DAT_2b1a6ba61f0 + (ulonglong)(uint)(iVar6 * 0x14) * 8) <= 0.0) || (param_1 != 1)
     ) {
    if ((0.0 <= *(double *)(&DAT_2b1a6ba61f0 + (ulonglong)(uint)(iVar6 * 0x14) * 8)) ||
       (param_1 != -1)) goto LAB_2b1a6a6cca7;
    if (DAT_2b1a6dcd670 != '\x01') {
      (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
      if ((DAT_2b1a6ba6040 == '\0') && ((_DAT_2b1a6ba6160 != 0.0 || (_DAT_2b1a6ba6158 < 0.0))))
      goto LAB_2b1a6a6cca7;
      FUN_2b1a6a604e0(&local_1a8,0x2b1a6dcd528,1,0x2b1a6ba47a8);
      uVar2 = 0xffffffff;
      goto LAB_2b1a6a6cc5f;
    }
    _DAT_2b1a6ca4074 = 0xffffffff;
  }
  else {
    if (DAT_2b1a6dcd670 != '\x01') {
      (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
      if ((DAT_2b1a6ba6040 == '\0') &&
         (((_DAT_2b1a6ba6160 < 0.0 || (_DAT_2b1a6ba6158 != 0.0)) || (NAN(_DAT_2b1a6ba6158)))))
      goto LAB_2b1a6a6cca7;
      FUN_2b1a6a604e0(&local_1a8,0x2b1a6dcd528,1,0x2b1a6ba4798);
      uVar2 = 1;
LAB_2b1a6a6cc5f:
      FUN_2b1a6a667d0(uVar2,&local_1a8);
      goto LAB_2b1a6a6cca7;
    }
    _DAT_2b1a6ca4074 = 1;
  }
  _DAT_2b1a6ca40c0 = (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,0);
LAB_2b1a6a6cca7:
  FUN_2b1a6a60000(&local_1a8);
  return;
}



/* Address: 2b1a6a6cd30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6cd30(void)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  uint *puVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  ulonglong uVar28;
  bool bVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  int iVar32;
  undefined4 uVar33;
  undefined8 uVar34;
  bool bVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  ulonglong in_stack_fffffffffffffd28;
  undefined8 in_stack_fffffffffffffd30;
  undefined4 in_stack_fffffffffffffd40;
  undefined4 uVar41;
  undefined8 in_stack_fffffffffffffd48;
  undefined4 uStack_278;
  longlong lStack_274;
  undefined4 uStack_268;
  longlong lStack_264;
  ulonglong uStack_258;
  ulonglong uStack_250;
  uint uStack_244;
  undefined8 uStack_240;
  ulonglong uStack_238;
  ulonglong uStack_230;
  undefined4 uStack_228;
  undefined1 *puStack_224;
  undefined4 uStack_218;
  undefined8 uStack_214;
  undefined4 uStack_208;
  longlong lStack_204;
  undefined4 uStack_1f8;
  longlong lStack_1f4;
  undefined4 uStack_1e8;
  longlong lStack_1e4;
  undefined4 uStack_1d8;
  longlong lStack_1d4;
  uint uStack_1cc;
  double dStack_1c8;
  double dStack_1c0;
  double dStack_1b8;
  undefined4 uStack_1b0;
  undefined8 uStack_1ac;
  double dStack_1a0;
  undefined4 uStack_198;
  undefined8 uStack_194;
  undefined8 uStack_18c;
  undefined8 uStack_184;
  double *pdStack_17c;
  undefined8 uStack_174;
  undefined8 uStack_16c;
  undefined4 uStack_160;
  undefined8 uStack_15c;
  undefined8 uStack_154;
  undefined8 uStack_14c;
  double *pdStack_144;
  undefined8 uStack_13c;
  undefined8 uStack_134;
  undefined4 uStack_128;
  undefined8 uStack_124;
  undefined8 uStack_11c;
  undefined8 uStack_114;
  double *pdStack_10c;
  undefined8 uStack_104;
  undefined8 uStack_fc;
  undefined4 uStack_f0;
  undefined8 uStack_ec;
  undefined8 uStack_e4;
  undefined8 uStack_dc;
  double *pdStack_d4;
  undefined8 uStack_cc;
  undefined8 uStack_c4;
  double dStack_b0;
  double dStack_a8;
  
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffd30 >> 0x20);
  if ((DAT_2b1a6dcd618 != '\x01') ||
     (((iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,8), iVar10 != 1 ||
       (iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar10 != 1)) &&
      (iVar10 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6), iVar10 != 0)))) {
    return;
  }
  uStack_1d8 = 0;
  uStack_268 = 0;
  uStack_278 = 0;
  uStack_1f8 = 0;
  uStack_208 = 0;
  uStack_228 = 0;
  uStack_1e8 = 0;
  uStack_218 = 0;
  lStack_1d4 = 0;
  lStack_264 = 0;
  lStack_274 = 0;
  lStack_1f4 = 0;
  lStack_204 = 0;
  puStack_224 = (undefined1 *)0x0;
  lStack_1e4 = 0;
  uStack_214 = 0;
  if ((DAT_2b1a6ca42ba == '\0') ||
     ((lVar11 = (*(code *)0x7ff63a3fbf90)(), _DAT_2b1a6ca42b2 != 0 &&
      ((ulonglong)(lVar11 - _DAT_2b1a6ca42b2) < (ulonglong)_DAT_2b1a6ca410a))))
  goto LAB_2b1a6a666dd;
  _DAT_2b1a6ca42b2 = lVar11;
  lVar11 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0);
  uStack_1f8 = 0;
  lStack_1f4 = 0;
  (*(code *)0x7ff63a0f5080)(0x2b1a1776bc8,_DAT_2b1a6ca4262);
  FUN_2b1a6a604e0(&uStack_278,0x2b1a6dcd53c,1,0x2b1a6ba38e0);
  FUN_2b1a6a604e0(&uStack_1f8,&uStack_278,0,0x2b1a6ba38f0);
  uStack_208 = 0;
  lStack_204 = 0;
  (*(code *)0x7ff63a0c7410)(0x2b1a1776bc8,3);
  FUN_2b1a6a604e0(&uStack_278,0x2b1a6dcd53c,1,0x2b1a6ba3900);
  FUN_2b1a6a604e0(&uStack_208,&uStack_278,0,0x2b1a6ba3910);
  if (lVar11 == _DAT_2b1a6ca426a) {
    if (lStack_1f4 != _DAT_2b1a6ca4282) {
      if ((lStack_1f4 != 0) && (_DAT_2b1a6ca4282 != 0)) {
        uVar27 = *(uint *)(lStack_1f4 + -4);
        uVar16 = *(uint *)(_DAT_2b1a6ca4282 + -4);
        uVar18 = uVar16;
        if (uVar27 < uVar16) {
          uVar18 = uVar27;
        }
        iVar10 = uVar27 - uVar16;
        if (uVar18 != 0) {
          uVar31 = 1;
          do {
            uVar1 = *(ushort *)(lStack_1f4 + -2 + uVar31 * 2);
            uVar2 = *(ushort *)(_DAT_2b1a6ca4282 + -2 + uVar31 * 2);
            if (uVar18 <= uVar31) break;
            uVar31 = uVar31 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar10 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar10 == 0) goto LAB_2b1a6a643ad;
      }
      goto LAB_2b1a6a6443d;
    }
LAB_2b1a6a643ad:
    if (lStack_204 != _DAT_2b1a6ca428e) {
      if ((lStack_204 != 0) && (_DAT_2b1a6ca428e != 0)) {
        uVar27 = *(uint *)(lStack_204 + -4);
        uVar16 = *(uint *)(_DAT_2b1a6ca428e + -4);
        uVar18 = uVar16;
        if (uVar27 < uVar16) {
          uVar18 = uVar27;
        }
        iVar10 = uVar27 - uVar16;
        if (uVar18 != 0) {
          uVar31 = 1;
          do {
            uVar1 = *(ushort *)(lStack_204 + -2 + uVar31 * 2);
            uVar2 = *(ushort *)(_DAT_2b1a6ca428e + -2 + uVar31 * 2);
            if (uVar18 <= uVar31) break;
            uVar31 = uVar31 + 1;
          } while (uVar1 == uVar2);
          if (uVar1 != uVar2) {
            iVar10 = (uint)uVar1 - (uint)uVar2;
          }
        }
        if (iVar10 == 0) goto LAB_2b1a6a64592;
      }
      goto LAB_2b1a6a6443d;
    }
  }
  else {
LAB_2b1a6a6443d:
    _DAT_2b1a6ca426a = lVar11;
    FUN_2b1a6a604e0(0x2b1a6ca427e,&uStack_1f8,0,0x2b1a6ba3920);
    FUN_2b1a6a604e0(&DAT_2b1a6ca428a,&uStack_208,0,0x2b1a6ba3930);
    uStack_1b0 = 0;
    uStack_1ac = 0;
    if (_DAT_2b1a6ca4296 != -1) {
      (*(code *)0x7ff63a0eee30)(0x2b1a1776bc8);
    }
    uVar41 = _DAT_2b1a6ca4106;
    _DAT_2b1a6ca4296 = -1;
    if (0 < _DAT_2b1a6ca4236) {
      FUN_2b1a6a6df60(0x2b1a6a77f60);
      FUN_2b1a6a604e0(&uStack_1b0,0x2b1a6dcd53c,1,0x2b1a6ba3800);
      in_stack_fffffffffffffd28 = 0x2b1a6ca427e;
      in_stack_fffffffffffffd40 = 0x590008;
      uVar34 = CONCAT44(uVar33,0x520004);
      in_stack_fffffffffffffd48 = 0x2b1a6a78218;
      _DAT_2b1a6ca4296 =
           (*(code *)0x7ff63a0e49f0)
                     (0x2b1a1776bc8,0x77,5,0x590008,0x2b1a6ca427e,uVar34,1,0x590008,0x2b1a6a78218,
                      0x590008,&uStack_1b0,0x520004,uVar41);
      uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
    }
    FUN_2b1a6a60000(&uStack_1b0);
  }
LAB_2b1a6a64592:
  if (((((DAT_2b1a6ca42bb != '\0') ||
        (iVar8 = (*(code *)0x7ff63a0f4840)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272),
        iVar10 = _DAT_2b1a6ca429a, iVar8 < 0)) ||
       (iVar9 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6a,0),
       iVar8 = _DAT_2b1a6ca429e, iVar10 != iVar9)) ||
      (iVar10 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6b,0), iVar8 != iVar10))
     && (cVar7 = FUN_2b1a6a6f2c0(), cVar7 == '\0')) {
LAB_2b1a6a666c7:
    FUN_2b1a6a60000(&uStack_208);
    FUN_2b1a6a60000(&uStack_1f8);
LAB_2b1a6a666dd:
    FUN_2b1a6a60000(&uStack_278);
    FUN_2b1a6a60000(&uStack_268);
    FUN_2b1a6a60000(&uStack_1d8);
    return;
  }
  in_stack_fffffffffffffd28 = in_stack_fffffffffffffd28 & 0xffffffff00000000;
  (*(code *)0x7ff63a0c7470)
            (0x2b1a1776bc8,&DAT_2b1a6ca418a,&DAT_2b1a6ca41f2,0,in_stack_fffffffffffffd28,
             CONCAT44(uVar33,0xffffffff));
  uVar33 = (undefined4)(in_stack_fffffffffffffd28 >> 0x20);
  iVar10 = (*(code *)0x7ff63a0f0700)(0x2b1a1776bc8,8);
  iVar8 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,4);
  lVar11 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x21);
  lVar12 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x22);
  iVar9 = (*(code *)0x7ff63a0f0700)(0x2b1a1776bc8,6);
  bVar35 = true;
  if (iVar9 == 0) {
    iVar9 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
    bVar35 = iVar9 != 0;
  }
  uVar34 = 0x2b1a6a78380;
  uStack_250 = CONCAT71(uStack_250._1_7_,iVar8 != 0);
  if (iVar10 != 0) {
    uVar34 = 0x2b1a6a783b8;
  }
  uStack_258._0_1_ = iVar10 != 0;
  lVar13 = (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,0x2b1a6ca427e,0x1e);
  uVar19 = 0x2b1a6a78350;
  uStack_228 = 0;
  puStack_224 = (undefined1 *)0x0;
  if (((bVar35) && (uVar19 = uVar34, iVar10 != 0)) &&
     ((iVar8 != 0 && ((uVar19 = 0x2b1a6a783f8, lVar11 != 0 && (lVar12 != 0)))))) {
    uVar19 = 0x2b1a6a78470;
    if (lVar13 == 3) {
      uVar19 = 0x2b1a6a78438;
    }
    if (lVar13 == 0) {
      uVar19 = 0x2b1a6a78438;
    }
  }
  FUN_2b1a6a604e0(&uStack_228,uVar19,0,0x2b1a6ba3940);
  if (puStack_224 == &DAT_2b1a6a7845c) {
LAB_2b1a6a648cc:
    puVar14 = (uint *)&DAT_2b1a6ca411e;
  }
  else {
    puVar14 = (uint *)&DAT_2b1a6ca4122;
    if (puStack_224 != (undefined1 *)0x0) {
      uVar27 = *(uint *)(puStack_224 + -4);
      uVar16 = _DAT_2b1a6a78458;
      if (uVar27 < _DAT_2b1a6a78458) {
        uVar16 = uVar27;
      }
      iVar10 = uVar27 - _DAT_2b1a6a78458;
      if (uVar16 != 0) {
        uVar31 = 0;
        do {
          uVar1 = *(ushort *)(puStack_224 + uVar31 * 2);
          uVar2 = *(ushort *)(&DAT_2b1a6a7845c + uVar31 * 2);
          uVar31 = uVar31 + 1;
          if (uVar16 <= uVar31) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar10 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar10 == 0) goto LAB_2b1a6a648cc;
    }
  }
  dVar37 = _DAT_2b1a6a77838 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77840 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77848 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77850;
  uVar27 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar27 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  uVar27 = *puVar14;
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,CONCAT44(uVar33,0xc2011));
  dVar37 = _DAT_2b1a6a77858 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77860 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77868 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  uStack_240 = CONCAT44(uStack_240._4_4_,uVar27);
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77870;
  uVar16 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,uVar27);
  dVar37 = _DAT_2b1a6a77878 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6a77880 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  dVar40 = _DAT_2b1a6a77888 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar40 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar39 = dVar40;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar39 = (double)((ulonglong)dVar40 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar40) != 0) {
        dVar39 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar40 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar39 = dVar40 + dVar40;
  }
  dVar36 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77890;
  uVar16 = (uint)((ulonglong)dVar36 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar40 = dVar36;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar40 = (double)((ulonglong)dVar36 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      uVar27 = (uint)uStack_240;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar36) != 0) {
        dVar40 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar36 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar40 = dVar36 + dVar36;
  }
  FUN_2b1a6a71000((int)dVar40,(int)dVar39,(int)dVar37,(int)dVar38,0x61008);
  dVar37 = _DAT_2b1a6a77898 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  iVar10 = 1;
  if (1 < (int)dVar38) {
    iVar10 = (int)dVar38;
  }
  dVar37 = _DAT_2b1a6a778a0 * _DAT_2b1a6ca42bc;
  uVar16 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  uStack_258._0_1_ = (byte)uStack_258 & (byte)uStack_250;
  dVar39 = _DAT_2b1a6ca42bc * _DAT_2b1a6a778a8;
  uVar16 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar13 = (ulonglong)uVar16 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar16 < 0x433) {
    if (uVar16 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar13 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar13;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar13 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  uVar27 = uVar27 << 0x10 | uVar27 & 0xff00 | uVar27 >> 0x10 & 0xff | 0xff000000;
  uStack_250 = (ulonglong)(uint)(int)dVar38;
  uStack_230 = (ulonglong)(uint)(int)dVar37;
  iVar9 = 0;
  uStack_238 = (ulonglong)(uint)(iVar10 * -2);
  iVar32 = 1 - iVar10;
  iVar23 = 0;
  uStack_258 = CONCAT71(uStack_258._1_7_,(byte)uStack_258 & (lVar11 != 0 && lVar12 != 0));
  iVar8 = 3;
  uStack_244 = uVar27;
  do {
    iVar25 = iVar10 + (int)uStack_230;
    iVar22 = (int)uStack_250;
    iVar21 = (int)uStack_230 - iVar10;
    FUN_2b1a6a6de10(iVar21,iVar25,iVar22 + iVar23,uVar27);
    FUN_2b1a6a6de10(iVar21,iVar25,iVar22 + iVar9,uVar27);
    if (-1 < iVar32) {
      iVar21 = (int)uStack_230 + iVar9;
      iVar22 = (int)uStack_230 + iVar23;
      iVar25 = (int)uStack_250;
      FUN_2b1a6a6de10(iVar22,iVar21,iVar25 - iVar10,uVar27);
      FUN_2b1a6a6de10(iVar22,iVar21,iVar10 + iVar25,uVar27);
      iVar10 = iVar10 + -1;
      iVar32 = iVar32 + 2 + (int)uStack_238;
      uStack_238 = (ulonglong)((int)uStack_238 + 2);
    }
    iVar9 = iVar9 + 1;
    iVar23 = iVar23 + -1;
    iVar32 = iVar32 + iVar8;
    iVar8 = iVar8 + 2;
  } while (iVar9 <= iVar10);
  uVar33 = CONCAT31((int3)((uint)in_stack_fffffffffffffd40 >> 8),1);
  FUN_2b1a6a70350(&uStack_228,_DAT_2b1a6a778b0,_DAT_2b1a6a778b8,_DAT_2b1a6a778a0,0x4044000000000000,
                  0x4044000000000000,(uint)uStack_240,uVar33);
  uStack_240 = 0x2b1a6a784c8;
  if ((byte)uStack_258 != 0) {
    uStack_240 = 0x2b1a6a78498;
  }
  uStack_1cc = *(uint *)(&DAT_2b1a6ca411e + (ulonglong)((byte)uStack_258 ^ 1) * 4);
  dVar37 = _DAT_2b1a6a778c0 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  uVar31 = 1;
  if (1 < (int)dVar38) {
    uVar31 = (ulonglong)(uint)(int)dVar38;
  }
  dVar37 = _DAT_2b1a6a778c8 * _DAT_2b1a6ca42bc;
  uVar27 = (uint)((ulonglong)dVar37 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar38 = dVar37;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar38 = (double)((ulonglong)dVar37 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar37) != 0) {
        dVar38 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar37 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar38 = dVar37 + dVar37;
  }
  dVar39 = _DAT_2b1a6ca42bc * _DAT_2b1a6a778d0;
  uVar27 = (uint)((ulonglong)dVar39 >> 0x34) & 0x7ff;
  lVar11 = (ulonglong)uVar27 - 0x3ff;
  dVar37 = dVar39;
  if ((ulonglong)uVar27 < 0x433) {
    if (uVar27 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar11 != -1) {
        dVar37 = (double)((ulonglong)dVar39 & 0x8000000000000000);
      }
    }
    else {
      bVar15 = (byte)lVar11;
      if ((0xfffffffffffffU >> (bVar15 & 0x3f) & (ulonglong)dVar39) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar15 & 0x3f)) + (longlong)dVar39 &
                         -0x10000000000000 >> (bVar15 & 0x3f));
      }
    }
  }
  else if (lVar11 == 0x400) {
    dVar37 = dVar39 + dVar39;
  }
  uVar27 = uStack_1cc << 0x10 | uStack_1cc & 0xff00 | uStack_1cc >> 0x10 & 0xff | 0xff000000;
  uStack_258 = (ulonglong)(uint)(int)dVar38;
  uStack_230 = (ulonglong)(uint)(int)dVar37;
  iVar8 = 0;
  iVar23 = 0;
  uStack_238 = (ulonglong)(uint)((int)uVar31 * -2);
  iVar9 = 1 - (int)uVar31;
  iVar10 = 3;
  uStack_244 = uVar27;
  do {
    iVar32 = (int)uVar31 + (int)uStack_230;
    iVar21 = (int)uStack_258;
    iVar22 = (int)uStack_230 - (int)uVar31;
    uStack_250 = uVar31;
    FUN_2b1a6a6de10(iVar22,iVar32,iVar8 + iVar21,uVar27);
    FUN_2b1a6a6de10(iVar22,iVar32,iVar21 + iVar23,uVar27);
    uVar31 = uStack_250;
    if (-1 < iVar9) {
      iVar22 = (int)uStack_230 + iVar8;
      iVar32 = (int)uStack_230 + iVar23;
      iVar25 = (int)uStack_250;
      FUN_2b1a6a6de10(iVar22,iVar32,iVar21 - iVar25,uVar27);
      FUN_2b1a6a6de10(iVar22,iVar32,iVar25 + iVar21,uVar27);
      iVar9 = iVar9 + 2 + (int)uStack_238;
      uStack_238 = (ulonglong)((int)uStack_238 + 2);
      uVar31 = (ulonglong)(iVar25 - 1);
    }
    uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffd48 >> 0x20);
    iVar23 = iVar23 + 1;
    iVar9 = iVar9 + iVar10;
    iVar8 = iVar8 + -1;
    iVar10 = iVar10 + 2;
  } while (iVar23 <= (int)uVar31);
  uVar27 = CONCAT31((int3)((uint)uVar33 >> 8),1);
  uVar33 = 0x40490000;
  FUN_2b1a6a70350(uStack_240,_DAT_2b1a6a778d8,_DAT_2b1a6a778e0,_DAT_2b1a6a778e8,0x4049000000000000,
                  0x4045000000000000,uStack_1cc,uVar27);
  if (_DAT_2b1a6ca4296 == -1) {
    bVar35 = false;
    bVar29 = false;
  }
  else {
    pdStack_17c = &dStack_1b8;
    uStack_198 = 0x1000058;
    uVar34 = CONCAT44(uVar33,1);
    uStack_194 = 0x100000008;
    uStack_18c = 0;
    uStack_184 = 0x100000000;
    uStack_174 = 0;
    uStack_16c = 0;
    iVar10 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,0,0,uVar34,&uStack_198);
    uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
    if (iVar10 == 1) {
      uStack_160 = 0x1000058;
      uStack_15c = 0x100000008;
      uStack_154 = 0;
      uStack_14c = 0x100000000;
      uVar34 = CONCAT44(uVar33,1);
      pdStack_144 = &dStack_1a0;
      uStack_13c = 0;
      uStack_134 = 0;
      iVar10 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,1,0,uVar34,&uStack_160);
      uVar33 = (undefined4)((ulonglong)uVar34 >> 0x20);
      bVar15 = 1;
      if (iVar10 != 1) goto LAB_2b1a6a65849;
    }
    else {
LAB_2b1a6a65849:
      bVar15 = 0;
    }
    uStack_128 = 0x1000058;
    uStack_124 = 0x100000008;
    uStack_11c = 0;
    uStack_114 = 0x100000000;
    pdStack_10c = &dStack_1c0;
    uStack_104 = 0;
    uStack_fc = 0;
    bVar35 = _DAT_2b1a6a778f0 < dStack_1a0;
    iVar10 = (*(code *)0x7ff63a0eeec0)
                       (0x2b1a1776bc8,_DAT_2b1a6ca4296,2,0,CONCAT44(uVar33,1),&uStack_128);
    if (iVar10 == 1) {
      pdStack_d4 = &dStack_1c8;
      uStack_f0 = 0x1000058;
      uStack_ec = 0x100000008;
      uStack_e4 = 0;
      uStack_dc = 0x100000000;
      bVar5 = false;
      uStack_cc = 0;
      uStack_c4 = 0;
      iVar10 = (*(code *)0x7ff63a0eeec0)(0x2b1a1776bc8,_DAT_2b1a6ca4296,3,0,1,&uStack_f0);
      if (iVar10 != 1) goto LAB_2b1a6a6597b;
    }
    else {
LAB_2b1a6a6597b:
      bVar5 = true;
    }
    if ((bool)(bVar35 & bVar15)) {
      bVar29 = dStack_1b8 != _DAT_2b1a6a778f8 && (~(ulonglong)dStack_1b8 & 0x7ff0000000000000) != 0;
    }
    else {
      bVar29 = false;
    }
    if (bVar5) {
      bVar35 = false;
    }
    else {
      bVar35 = (dStack_1c0 != _DAT_2b1a6a778f8 && dStack_1c8 != _DAT_2b1a6a778f8) &&
               (~(ulonglong)dStack_1c0 & 0x7ff0000000000000) != 0;
    }
  }
  uVar33 = _DAT_2b1a6ca4126;
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x25);
  FUN_2b1a6a6e3b0(_DAT_2b1a6dcd548,0);
  puVar24 = &uStack_278;
  FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3950);
  uVar19 = _DAT_2b1a6a77908;
  uVar34 = _DAT_2b1a6a77900;
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,_DAT_2b1a6a77900,_DAT_2b1a6a77908,_DAT_2b1a6a77910,0x404a000000000000,
                  0x4045000000000000,uVar33,uVar27);
  uVar33 = _DAT_2b1a6ca4126;
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x28);
  FUN_2b1a6a6e3b0(_DAT_2b1a6dcd548,0);
  FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3960);
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77918,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  if (bVar35) {
    lVar11 = 0x3e;
    if (dStack_1c0 <= _DAT_2b1a6a77928) {
      lVar11 = (ulonglong)(_DAT_2b1a6a77920 <= dStack_1c0) * 4 + 0x42;
    }
    uVar33 = *(undefined4 *)(&DAT_2b1a6ca40e0 + lVar11);
    FUN_2b1a6a6e3b0(dStack_1c0,1);
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3970);
  }
  else {
    puVar24 = (undefined4 *)0x2b1a6a78508;
    uVar33 = _DAT_2b1a6ca4126;
  }
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77930,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  if (bVar29) {
    lVar11 = 0x3e;
    if (dStack_1b8 <= _DAT_2b1a6a77928) {
      lVar11 = (ulonglong)(_DAT_2b1a6a77920 <= dStack_1b8) * 4 + 0x42;
    }
    uVar33 = *(undefined4 *)(&DAT_2b1a6ca40e0 + lVar11);
    FUN_2b1a6a6e3b0(dStack_1b8,1);
    puVar24 = &uStack_278;
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3980);
  }
  else {
    puVar24 = (undefined4 *)0x2b1a6a78558;
    uVar33 = _DAT_2b1a6ca4126;
  }
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77938,0x404a000000000000,0x4045000000000000,
                  uVar33,uVar27);
  uStack_1e8 = 0;
  lStack_1e4 = 0;
  if (_DAT_2b1a6ca4236 < 1) {
    puVar24 = (undefined4 *)0x2b1a6a785c8;
  }
  else {
    FUN_2b1a6a6df60(0x2b1a6a78588);
    puVar24 = &uStack_278;
    FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba3990);
  }
  FUN_2b1a6a604e0(&uStack_1e8,puVar24,0,0x2b1a6ba39a0);
  uVar27 = uVar27 & 0xffffff00;
  FUN_2b1a6a70350(&uStack_1e8,uVar34,uVar19,_DAT_2b1a6a77940,0x404a000000000000,0x4044000000000000,
                  _DAT_2b1a6ca4126,uVar27);
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6ca427e);
  dVar38 = _DAT_2b1a6dcd548;
  uStack_218 = 0;
  uStack_214 = 0;
  FUN_2b1a6a604e0(&uStack_218,0x2b1a6a78600,0,0x2b1a6ba39b0);
  if ((((dVar38 <= 0.0) ||
       (cVar7 = (*(code *)0x7ff63a0f2c10)(0x2b1a1776bc8,0x2b1a6ca427e), cVar7 == '\0')) ||
      (dStack_a8 < dStack_b0)) || (dStack_b0 <= 0.0)) {
LAB_2b1a6a660c0:
    uVar27 = uVar27 & 0xffffff00;
    FUN_2b1a6a70350(&uStack_218,uVar34,uVar19,_DAT_2b1a6a77948,0x404a000000000000,0x4044000000000000
                    ,_DAT_2b1a6ca4126,uVar27);
    uVar33 = _DAT_2b1a6ca4126;
    if (DAT_2b1a6ca40f1 != '\0') {
      if (bVar35) {
        puVar24 = &uStack_278;
        (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,(longlong)(int)dStack_1c8,0x52,puVar24);
      }
      else {
        puVar24 = (undefined4 *)0x2b1a6a78508;
      }
      uVar27 = uVar27 & 0xffffff00;
      FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77950,0x404a000000000000,0x4045000000000000,
                      uVar33,uVar27);
    }
    lVar11 = (*(code *)0x7ff63a101ce0)(0x2b1a1776bc8,0);
    uVar33 = _DAT_2b1a6ca4126;
    if (lVar11 < 1) {
      puVar24 = (undefined4 *)0x2b1a6a78508;
    }
    else {
      (*(code *)0x7ff63a0fcc50)(0x2b1a1776bc8,lVar11,3);
      puVar24 = &uStack_278;
      FUN_2b1a6a604e0(puVar24,0x2b1a6dcd53c,1,0x2b1a6ba39f0);
    }
    uVar31 = 0x4044000000000000;
    FUN_2b1a6a70350(puVar24,uVar34,uVar19,_DAT_2b1a6a77958,0x404a000000000000,0x4044000000000000,
                    uVar33,uVar27 & 0xffffff00);
    FUN_2b1a6a604e0(&uStack_278,0x2b1a6a78670);
    lVar11 = lStack_1e4;
    if (lStack_1e4 == 0) {
LAB_2b1a6a6636d:
      uVar27 = 0;
      FUN_2b1a6a604e0(&uStack_268,&uStack_278,0,0x2b1a6ba3a10);
      uVar16 = _DAT_2b1a6a78688;
      uVar28 = (ulonglong)_DAT_2b1a6a78688;
      if ((uVar28 != 0) || (lStack_264 == 0)) {
        if (lStack_264 != 0) {
          uVar27 = *(uint *)(lStack_264 + -4);
        }
        uVar17 = _DAT_2b1a6a78688 + uVar27;
        uVar18 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_2b1a6a60060(&uStack_268,uVar18);
        if (cVar7 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x5500f1000101f9);
          goto LAB_2b1a6a6674b;
        }
        if (uVar28 != 0) {
          lVar11 = lStack_264 + (ulonglong)uVar27 * 2;
          if (uVar16 < 0x10) {
            uVar20 = 0;
          }
          else if (lVar11 - 0x2b1a6a7868cU < 0x20) {
            uVar20 = 0;
          }
          else {
            uVar30 = 0;
            uVar20 = (ulonglong)(uVar16 & 0xfffffff8);
            do {
              uVar34 = *(undefined8 *)(uVar30 + 0x2b1a6a78694);
              *(undefined8 *)(lVar11 + uVar30) = *(undefined8 *)(&DAT_2b1a6a7868c + uVar30);
              ((undefined8 *)(lVar11 + uVar30))[1] = uVar34;
              uVar30 = uVar30 + 0x10;
            } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
            if (uVar20 == uVar28) goto LAB_2b1a6a66492;
          }
          do {
            *(undefined2 *)(lVar11 + uVar20 * 2) = *(undefined2 *)(&DAT_2b1a6a7868c + uVar20 * 2);
            uVar20 = uVar20 + 1;
          } while (uVar28 != uVar20);
        }
LAB_2b1a6a66492:
        *(uint *)(lStack_264 + -4) = uVar17;
        *(undefined2 *)(lStack_264 + (ulonglong)uVar17 * 2) = 0;
      }
      FUN_2b1a6a604e0(&uStack_1d8,&uStack_268,0);
      puVar6 = puStack_224;
      if (puStack_224 != (undefined1 *)0x0) {
        uVar27 = *(uint *)(puStack_224 + -4);
        uVar28 = (ulonglong)uVar27;
        if ((uVar28 != 0) || (lStack_1d4 == 0)) {
          if (lStack_1d4 == 0) {
            uVar16 = 0;
            uVar18 = uVar27;
          }
          else {
            uVar16 = *(uint *)(lStack_1d4 + -4);
            uVar18 = uVar27 + uVar16;
          }
          cVar7 = FUN_2b1a6a60060(&uStack_1d8);
          if (cVar7 == '\0') goto LAB_2b1a6a6676b;
          if (uVar28 != 0) {
            lVar11 = lStack_1d4 + (ulonglong)uVar16 * 2;
            if (uVar27 < 0x10) {
              uVar20 = 0;
            }
            else if ((ulonglong)(lVar11 - (longlong)puVar6) < 0x20) {
              uVar20 = 0;
            }
            else {
              uVar30 = 0;
              uVar20 = (ulonglong)(uVar27 & 0xfffffff8);
              do {
                uVar34 = *(undefined8 *)((longlong)(puVar6 + uVar30) + 8);
                *(undefined8 *)(lVar11 + uVar30) = *(undefined8 *)(puVar6 + uVar30);
                ((undefined8 *)(lVar11 + uVar30))[1] = uVar34;
                uVar30 = uVar30 + 0x10;
              } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
              if (uVar20 == uVar28) goto LAB_2b1a6a665c2;
            }
            do {
              *(undefined2 *)(lVar11 + uVar20 * 2) = *(undefined2 *)(puVar6 + uVar20 * 2);
              uVar20 = uVar20 + 1;
            } while (uVar28 != uVar20);
          }
LAB_2b1a6a665c2:
          *(uint *)(lStack_1d4 + -4) = uVar18;
          *(undefined2 *)(lStack_1d4 + (ulonglong)uVar18 * 2) = 0;
        }
      }
      (*(code *)0x7ff63a0f3c80)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0xce,&uStack_1d8);
      if ((_DAT_2b1a6ca415e != 0) &&
         (cVar7 = (*(code *)0x7ff639d98020)
                            (0x2b1a1776bc8,&DAT_2b1a6ca415a,&DAT_2b1a6ca418a,_DAT_2b1a6ca4166,
                             _DAT_2b1a6ca416a,uVar31 & 0xffffffff00000000,0,0,
                             CONCAT44(uVar41,_DAT_2b1a6ca416e)), cVar7 != '\0')) {
        (*(code *)0x7ff63a0f51b0)(0x2b1a1776bc8,_DAT_2b1a6ca4142);
      }
      FUN_2b1a6a60000(&uStack_218);
      FUN_2b1a6a60000(&uStack_1e8);
      FUN_2b1a6a60000(&uStack_228);
      goto LAB_2b1a6a666c7;
    }
    uVar27 = *(uint *)(lStack_1e4 + -4);
    uVar28 = (ulonglong)uVar27;
    if ((uVar28 == 0) && (lStack_274 != 0)) goto LAB_2b1a6a6636d;
    if (lStack_274 == 0) {
      uVar20 = 0;
      uVar16 = uVar27;
    }
    else {
      uVar20 = (ulonglong)*(uint *)(lStack_274 + -4);
      uVar16 = uVar27 + *(uint *)(lStack_274 + -4);
    }
    cVar7 = FUN_2b1a6a60060(&uStack_278);
    if (cVar7 != '\0') {
      if (uVar28 != 0) {
        lVar12 = lStack_274 + uVar20 * 2;
        if (uVar27 < 0x10) {
          uVar20 = 0;
        }
        else if ((ulonglong)(lVar12 - lVar11) < 0x20) {
          uVar20 = 0;
        }
        else {
          uVar30 = 0;
          uVar20 = (ulonglong)(uVar27 & 0xfffffff8);
          do {
            uVar34 = ((undefined8 *)(lVar11 + uVar30))[1];
            *(undefined8 *)(lVar12 + uVar30) = *(undefined8 *)(lVar11 + uVar30);
            ((undefined8 *)(lVar12 + uVar30))[1] = uVar34;
            uVar30 = uVar30 + 0x10;
          } while ((uVar28 * 2 & 0xfffffffffffffff0) != uVar30);
          if (uVar20 == uVar28) goto LAB_2b1a6a66362;
        }
        do {
          *(undefined2 *)(lVar12 + uVar20 * 2) = *(undefined2 *)(lVar11 + uVar20 * 2);
          uVar20 = uVar20 + 1;
        } while (uVar28 != uVar20);
      }
LAB_2b1a6a66362:
      *(uint *)(lStack_274 + -4) = uVar16;
      *(undefined2 *)(lStack_274 + (ulonglong)uVar16 * 2) = 0;
      goto LAB_2b1a6a6636d;
    }
LAB_2b1a6a6674b:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4f00f1000101f9);
LAB_2b1a6a6676b:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x5b00f1000101f9);
  }
  else if ((dVar38 != 0.0) || (NAN(dVar38))) {
    uVar16 = 0;
    (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,(dStack_a8 - dStack_b0) / dVar38,0);
    FUN_2b1a6a604e0(&uStack_278,0x2b1a6dcd53c,1,0x2b1a6ba39c0);
    FUN_2b1a6a604e0(&uStack_268,&uStack_278,0,0x2b1a6ba39d0);
    uVar18 = _DAT_2b1a6a78618;
    uVar31 = (ulonglong)_DAT_2b1a6a78618;
    if ((uVar31 != 0) || (lStack_264 == 0)) {
      if (lStack_264 != 0) {
        uVar16 = *(uint *)(lStack_264 + -4);
      }
      uVar26 = _DAT_2b1a6a78618 + uVar16;
      uVar17 = 0x104;
      if ((0x103 < uVar26) &&
         ((0x7ffffffd < uVar26 || (uVar17 = (uVar26 >> 2) + uVar26, 0x7ffffffd < uVar17)))) {
        uVar17 = 0x7ffffffe;
      }
      cVar7 = FUN_2b1a6a60060(&uStack_268,uVar17);
      if (cVar7 == '\0') goto LAB_2b1a6a667ab;
      if (uVar31 != 0) {
        lVar11 = lStack_264 + (ulonglong)uVar16 * 2;
        if (uVar18 < 0x10) {
          uVar28 = 0;
        }
        else if (lVar11 - 0x2b1a6a7861cU < 0x20) {
          uVar28 = 0;
        }
        else {
          uVar20 = 0;
          uVar28 = (ulonglong)(uVar18 & 0xfffffff8);
          do {
            uVar4 = *(undefined8 *)(uVar20 + 0x2b1a6a78624);
            *(undefined8 *)(lVar11 + uVar20) = *(undefined8 *)(&DAT_2b1a6a7861c + uVar20);
            ((undefined8 *)(lVar11 + uVar20))[1] = uVar4;
            uVar20 = uVar20 + 0x10;
          } while ((uVar31 * 2 & 0xfffffffffffffff0) != uVar20);
          if (uVar28 == uVar31) goto LAB_2b1a6a66082;
        }
        do {
          *(undefined2 *)(lVar11 + uVar28 * 2) = *(undefined2 *)(&DAT_2b1a6a7861c + uVar28 * 2);
          uVar28 = uVar28 + 1;
        } while (uVar31 != uVar28);
      }
LAB_2b1a6a66082:
      *(uint *)(lStack_264 + -4) = uVar26;
      *(undefined2 *)(lStack_264 + (ulonglong)uVar26 * 2) = 0;
    }
    FUN_2b1a6a604e0(&uStack_218,&uStack_268,0,0x2b1a6ba39e0);
    goto LAB_2b1a6a660c0;
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3200ec000101f7);
LAB_2b1a6a667ab:
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3b00ec000101f9);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 2b1a6a6ce50 */

void FUN_2b1a6a6ce50(void)

{
  int iVar1;
  
  iVar1 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,8);
  if (iVar1 == 1) {
    iVar1 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
    if (iVar1 != 1) goto LAB_2b1a6a6ce8b;
  }
  else {
LAB_2b1a6a6ce8b:
    iVar1 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
    if (iVar1 != 0) goto LAB_2b1a6a6cecc;
  }
  (*(code *)0x7ff63a0e72d0)(0x2b1a1776bc8);
  FUN_2b1a6a6cf10(&DAT_2b1a6ca40e0);
LAB_2b1a6a6cecc:
  (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,4,1,0x590008,0x2b1a6a77f40);
  return;
}



/* Address: 2b1a6a6cf10 */

void FUN_2b1a6a6cf10(longlong param_1)

{
  if (*(int *)(param_1 + 0x1b6) != -1) {
    (*(code *)0x7ff63a0eee30)(0x2b1a1776bc8);
    *(undefined4 *)(param_1 + 0x1b6) = 0xffffffff;
  }
  FUN_2b1a6a60830(param_1 + 0x4a);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0x112);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,param_1 + 0xde);
  *(undefined1 *)(param_1 + 0x1da) = 0;
  *(undefined8 *)(param_1 + 0x1c2) = 0;
  return;
}



/* Address: 2b1a6a6cfa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6cfa0(void)

{
  (*(code *)0x7ff63a3fa670)(0x2b1a6ca4360,0x2b1a6a7a430,0x129120);
  _DAT_2b1a6ca4348 = 0x40213851eb851eb8;
  DAT_2b1a6ca4350 = 1;
  _DAT_2b1a6ca4308 = 0x408b080000000000;
  DAT_2b1a6ca40d5 = 1;
  _DAT_2b1a6ca4310 = 0x408a980000000000;
  DAT_2b1a6ca40d3 = 1;
  _DAT_2b1a6ca4318 = 0x4080000000000000;
  DAT_2b1a6ca40d1 = 1;
  _DAT_2b1a6ca4320 = 0x4080780000000000;
  _DAT_2b1a6ca40c8 = 0;
  _DAT_2b1a6ca4328 = 0x4084880000000000;
  _DAT_2b1a6ca40b8 = 0;
  _DAT_2b1a6ca4330 = 0x408ae00000000000;
  _DAT_2b1a6ca40a8 = 0;
  _DAT_2b1a6ca4338 = 0x4087300000000000;
  _DAT_2b1a6ca4098 = 0;
  _DAT_2b1a6ca4340 = 0x4081100000000000;
  _DAT_2b1a6ca4080 = 0;
  _DAT_2b1a6ca42c8 = 0x3fd6666666666666;
  _DAT_2b1a6ca4078 = 0;
  _DAT_2b1a6ca42d0 = 0x3fe29fbe76c8b439;
  DAT_2b1a6ca4072 = 0;
  _DAT_2b1a6ca42d8 = 0x3fe1a9fbe76c8b44;
  DAT_2b1a6ca4070 = 0;
  _DAT_2b1a6ca42e0 = 0x3fe3020c49ba5e35;
  _DAT_2b1a6ba61b0 = 0x800010058;
  _DAT_2b1a6ca42e8 = 0x3fd7be76c8b43958;
  _DAT_2b1a6ca42f0 = 0x3fc6e978d4fdf3b6;
  _DAT_2b1a6ca42f8 = 0x3fe0a3d70a3d70a4;
  DAT_2b1a6ca40d4 = 1;
  _DAT_2b1a6ca4300 = 0x3fea9fbe76c8b439;
  DAT_2b1a6ca40d2 = 1;
  _DAT_2b1a6ba61d8 = 0;
  DAT_2b1a6ca40d0 = 1;
  _DAT_2b1a6ba61c8 = 0;
  _DAT_2b1a6ca40c0 = 0;
  _DAT_2b1a6ba61b8 = 0;
  _DAT_2b1a6ca40b0 = 0;
  DAT_2b1a6ba61ac = 0;
  _DAT_2b1a6ca40a0 = 1;
  DAT_2b1a6ba61a4 = 0;
  _DAT_2b1a6ca4090 = 0;
  _DAT_2b1a6ca4084 = 0;
  _DAT_2b1a6ca4074 = 0;
  DAT_2b1a6ca4071 = 0;
  _DAT_2b1a6ba61e0 = 0;
  _DAT_2b1a6ba61d0 = 0;
  _DAT_2b1a6ba61c0 = 0;
  DAT_2b1a6ba61ad = 0;
  _DAT_2b1a6ba61a8 = 0;
  _DAT_2b1a6ba6170 = 0x800010058;
  _DAT_2b1a6ba61a0 = 0;
  _DAT_2b1a6ba6198 = 0;
  _DAT_2b1a6ba6190 = 0;
  _DAT_2b1a6ba6188 = 0;
  _DAT_2b1a6ba6180 = 0;
  _DAT_2b1a6ba6178 = 0;
  _DAT_2b1a6ba6160 = 0;
  _DAT_2b1a6ba6158 = 0;
  _DAT_2b1a6ba6120 = 0x800010058;
  _DAT_2b1a6ba6150 = 0;
  _DAT_2b1a6ba6148 = 0;
  _DAT_2b1a6ba6140 = 0;
  _DAT_2b1a6ba6138 = 0;
  _DAT_2b1a6ba6130 = 0;
  _DAT_2b1a6ba6128 = 0;
  _DAT_2b1a6ba60e0 = 0x800010058;
  _DAT_2b1a6ba6110 = 0;
  _DAT_2b1a6ba6108 = 0;
  _DAT_2b1a6ba6100 = 0;
  _DAT_2b1a6ba60f8 = 0;
  _DAT_2b1a6ba60f0 = 0;
  _DAT_2b1a6ba60e8 = 0;
  _DAT_2b1a6ba60a0 = 0x800010058;
  _DAT_2b1a6ba60d0 = 0;
  _DAT_2b1a6ba60c8 = 0;
  _DAT_2b1a6ba60c0 = 0;
  _DAT_2b1a6ba60b8 = 0;
  _DAT_2b1a6ba60b0 = 0;
  _DAT_2b1a6ba60a8 = 0;
  _DAT_2b1a6ba6060 = 0x800010058;
  _DAT_2b1a6ba6088 = 0;
  _DAT_2b1a6ba6090 = 0;
  _DAT_2b1a6ba6078 = 0;
  _DAT_2b1a6ba6080 = 0;
  _DAT_2b1a6ba6068 = 0;
  _DAT_2b1a6ba6070 = 0;
  _DAT_2b1a6ba6050 = 0x408f400000000000;
  _DAT_2b1a6ba6048 = 0x408f400000000000;
  DAT_2b1a6ba6046 = 1;
  DAT_2b1a6ba6045 = 1;
  DAT_2b1a6ba6044 = 1;
  DAT_2b1a6ba6043 = 1;
  DAT_2b1a6ba6042 = 1;
  DAT_2b1a6ba6041 = 1;
  DAT_2b1a6ba6040 = 1;
  DAT_2b1a6ba603f = 1;
  DAT_2b1a6ba603e = 1;
  DAT_2b1a6ba603d = 1;
  DAT_2b1a6ba603c = 1;
  _DAT_2b1a6ba6030 = 0;
  _DAT_2b1a6ba6034 = 0;
  FUN_2b1a6a604e0(&DAT_2b1a6ba6030,0x2b1a6a78008,0,0x2b1a6ba3550);
  DAT_2b1a6ba6027 = 1;
  DAT_2b1a6ba6026 = 1;
  DAT_2b1a6ba6028 = 1;
  DAT_2b1a6ba6025 = 1;
  DAT_2b1a6ba6024 = 1;
  _DAT_2b1a6ba6018 = 0;
  _DAT_2b1a6ba601c = 0;
  FUN_2b1a6a604e0(&DAT_2b1a6ba6018,0x2b1a6a77fd8,0,0x2b1a6ba3560);
  _DAT_2b1a6ba6008 = 0x3ff0000000000000;
  DAT_2b1a6ba6010 = 1;
  _DAT_2b1a6ba6000 = 2;
  (*(code *)0x7ff63a0e4490)(0x2b1a1776bc8,0x2b1a17e3740,&DAT_2b1a6ca40e0);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,_DAT_2b1a6ca40e0,0x2b1a17978d0);
  _DAT_2b1a6ca40e8 = 0x2b1a6a77da0;
  (*(code *)0x7ff63a0e4490)(0x2b1a1776bc8,0x2b1a1797ed0,&DAT_2b1a6ca412a);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,_DAT_2b1a6ca412a,0x2b1a17978d0);
  _DAT_2b1a6ca4132 = 0x2b1a6a77da0;
  _DAT_2b1a6ca414a = 0;
  _DAT_2b1a6ca414e = 0;
  _DAT_2b1a6ca415a = 0;
  _DAT_2b1a6ca415e = 0;
  _DAT_2b1a6ca4172 = 0;
  _DAT_2b1a6ca4176 = 0;
  _DAT_2b1a6ca418a = 0x400010053;
  _DAT_2b1a6ca4192 = 0;
  _DAT_2b1a6ca419a = 0;
  _DAT_2b1a6ca41a2 = 0;
  _DAT_2b1a6ca41aa = 0;
  _DAT_2b1a6ca41b2 = 0;
  _DAT_2b1a6ca41ba = 0;
  _DAT_2b1a6ca41be = 0x400010053;
  _DAT_2b1a6ca41c6 = 0;
  _DAT_2b1a6ca41ce = 0;
  _DAT_2b1a6ca41d6 = 0;
  _DAT_2b1a6ca41de = 0;
  _DAT_2b1a6ca41e6 = 0;
  _DAT_2b1a6ca41ee = 0;
  _DAT_2b1a6ca41f2 = 0x400010053;
  _DAT_2b1a6ca4202 = 0;
  _DAT_2b1a6ca41fa = 0;
  _DAT_2b1a6ca4212 = 0;
  _DAT_2b1a6ca420a = 0;
  _DAT_2b1a6ca4222 = 0;
  _DAT_2b1a6ca421a = 0;
  _DAT_2b1a6ca422e = 0x800010055;
  _DAT_2b1a6ca4236 = 0;
  _DAT_2b1a6ca423e = 0;
  _DAT_2b1a6ca4246 = 0;
  _DAT_2b1a6ca424e = 0;
  _DAT_2b1a6ca4256 = 0;
  _DAT_2b1a6ca425e = 0;
  _DAT_2b1a6ca4272 = 0;
  _DAT_2b1a6ca427a = 0;
  _DAT_2b1a6ca4282 = 0;
  _DAT_2b1a6ca428a = 0;
  _DAT_2b1a6ca4292 = 0;
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,_DAT_2b1a6ca40e0,0x2b1a17e3740);
  _DAT_2b1a6ca40e8 = 0x2b1a6a77ea0;
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,_DAT_2b1a6ca412a,0x2b1a17b1ee0);
  _DAT_2b1a6ca4132 = 0x2b1a6a77e20;
  _DAT_2b1a6ca413a = 0xffffffff;
  _DAT_2b1a6ca4142 = 0;
  FUN_2b1a6a604e0(&DAT_2b1a6ca414a,0x2b1a6a77f20,0,0x2b1a6ba35c0);
  _DAT_2b1a6ca4156 = 0xffffffff;
  FUN_2b1a6a604e0(&DAT_2b1a6ca415a,0x2b1a6a77f20,0,0x2b1a6ba35d0);
  _DAT_2b1a6ca4166 = 0;
  _DAT_2b1a6ca416e = 0;
  FUN_2b1a6a604e0(&DAT_2b1a6ca4172,0x2b1a6a78128,0,0x2b1a6ba35e0);
  _DAT_2b1a6ca417e = 0xffffff88;
  _DAT_2b1a6ca4186 = 0;
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,_DAT_2b1a6ca412a,0x2b1a1797ed0);
  _DAT_2b1a6ca4132 = 0x2b1a6a77e60;
  _DAT_2b1a6ca40f0 = 0x101;
  _DAT_2b1a6ca40f2 = 0x1400000000;
  _DAT_2b1a6ca40fa = 0x2bc0000001e;
  _DAT_2b1a6ca4102 = 0x1e0000000a;
  _DAT_2b1a6ca410a = 500;
  _DAT_2b1a6ca410e = 0x3ff0000000000000;
  _DAT_2b1a6ca4116 = 0x50b7de000c0d0c;
  _DAT_2b1a6ca411e = 0x5959ff002eee57;
  _DAT_2b1a6ca4126 = 0xd9f0f6;
  _DAT_2b1a6ca42ba = 0x100;
  _DAT_2b1a6ca4296 = 0xffffffff;
  _DAT_2b1a6ca42b2 = 0;
  _DAT_2b1a6ca42a2 = 0;
  _DAT_2b1a6ca429a = 0;
  _DAT_2b1a6ca42bc = 0x3ff0000000000000;
  _DAT_2b1a6ca4226 = 0;
  _DAT_2b1a6ca426a = 0;
  _DAT_2b1a6ca4262 = 0;
  return;
}



/* Address: 2b1a6a6dd30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6dd30(void)

{
  int *piVar1;
  
  FUN_2b1a6a614c0(&DAT_2b1a6ca40e0);
  (*(code *)0x7ff63a0e62f0)(0x2b1a1776bc8,_DAT_2b1a6ca40e0);
  FUN_2b1a6a60000(&DAT_2b1a6ca4080);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba61b0);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba6170);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba6120);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba60e0);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba60a0);
  (*(code *)0x7ff63a0d9d20)(0x2b1a1776bc8,&DAT_2b1a6ba6060);
  FUN_2b1a6a60000(&DAT_2b1a6ba6030);
  if ((((_DAT_2b1a6ba6018 != 0) && (_DAT_2b1a6ba601c != 0)) &&
      ((int *)(_DAT_2b1a6ba601c + -0xc) != (int *)0x0)) && (*(int *)(_DAT_2b1a6ba601c + -0xc) != 0))
  {
    piVar1 = (int *)(_DAT_2b1a6ba601c + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(code *)0x7ff63a101200)(0x2b1a1776bc8);
    }
  }
  _DAT_2b1a6ba601c = 0;
  _DAT_2b1a6ba6018 = 0;
  return;
}



/* Address: 2b1a6a6de10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6de10(int param_1,int param_2,int param_3,undefined4 param_4)

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
  
  lVar3 = _DAT_2b1a6ca41a6;
  iVar8 = param_2;
  if (param_2 < param_1) {
    iVar8 = param_1;
  }
  if (param_1 < param_2) {
    param_2 = param_1;
  }
  if ((((-1 < iVar8) && (param_2 < _DAT_2b1a6ca4166)) && (-1 < param_3)) &&
     (param_3 < _DAT_2b1a6ca416a)) {
    iVar11 = 0;
    if (0 < param_2) {
      iVar11 = param_2;
    }
    iVar4 = _DAT_2b1a6ca4166 + -1;
    if (iVar8 < _DAT_2b1a6ca4166) {
      iVar4 = iVar8;
    }
    uVar5 = (iVar4 - iVar11) + 1;
    if (uVar5 != 0) {
      param_3 = _DAT_2b1a6ca4166 * param_3;
      uVar7 = param_3 + iVar11;
      uVar6 = uVar5 + uVar7;
      if ((CARRY4(uVar5,uVar7)) || (_DAT_2b1a6ca4192 < uVar6)) {
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x30299000201f6);
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



/* Address: 2b1a6a6df60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6df60(longlong param_1)

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
  longlong lVar10;
  char cVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 local_60;
  longlong local_5c;
  undefined4 local_50;
  undefined8 local_4c;
  
  local_60 = 0;
  local_50 = 0;
  local_5c = 0;
  local_4c = 0;
  local_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uVar16 = 0;
  FUN_2b1a6a604e0(&local_70,0x2b1a6a77f40,0);
  if (0 < (int)_DAT_2b1a6ca4236) {
    do {
      if ((uVar16 != 0) && (lVar5 = *(longlong *)(param_1 + 4), lVar5 != 0)) {
        uVar4 = *(uint *)(lVar5 + -4);
        uVar14 = (ulonglong)uVar4;
        lVar10 = CONCAT44(local_68,uStack_6c);
        if ((uVar14 != 0) || (lVar10 == 0)) {
          if (lVar10 == 0) {
            uVar13 = 0;
            uVar17 = uVar4;
          }
          else {
            uVar13 = *(uint *)(lVar10 + -4);
            uVar17 = uVar4 + uVar13;
          }
          cVar11 = FUN_2b1a6a60060(&local_70);
          if (cVar11 == '\0') goto LAB_2b1a6a6e38c;
          lVar10 = CONCAT44(local_68,uStack_6c);
          if (uVar14 != 0) {
            lVar1 = lVar10 + (ulonglong)uVar13 * 2;
            if (uVar4 < 8) {
              uVar12 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
              uVar12 = 0;
            }
            else {
              uVar15 = 0;
              uVar12 = (ulonglong)(uVar4 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar5 + uVar15);
                uVar7 = puVar3[1];
                uVar8 = puVar3[2];
                uVar9 = puVar3[3];
                puVar2 = (undefined4 *)(lVar1 + uVar15);
                *puVar2 = *puVar3;
                puVar2[1] = uVar7;
                puVar2[2] = uVar8;
                puVar2[3] = uVar9;
                uVar15 = uVar15 + 0x10;
              } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar12 == uVar14) goto LAB_2b1a6a6e153;
            }
            do {
              *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
              uVar12 = uVar12 + 1;
            } while (uVar14 != uVar12);
          }
LAB_2b1a6a6e153:
          *(uint *)(lVar10 + -4) = uVar17;
          *(undefined2 *)(lVar10 + (ulonglong)uVar17 * 2) = 0;
        }
      }
      if (_DAT_2b1a6ca4236 <= uVar16) {
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x5f0033000101f6);
LAB_2b1a6a6e36c:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4c0033000101f9);
LAB_2b1a6a6e38c:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3b0033000101f9);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      uVar14 = ~(ulonglong)uVar16 + (ulonglong)_DAT_2b1a6ca4236;
      if ((_DAT_2b1a6ca4230 & 0x10) == 0) {
        uVar14 = (ulonglong)uVar16;
      }
      (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,*(undefined8 *)(_DAT_2b1a6ca424a + uVar14 * 8),0x55);
      lVar5 = local_5c;
      if (local_5c != 0) {
        uVar4 = *(uint *)(local_5c + -4);
        uVar14 = (ulonglong)uVar4;
        lVar10 = CONCAT44(local_68,uStack_6c);
        if ((uVar14 != 0) || (lVar10 == 0)) {
          if (lVar10 == 0) {
            uVar13 = 0;
            uVar17 = uVar4;
          }
          else {
            uVar13 = *(uint *)(lVar10 + -4);
            uVar17 = uVar4 + uVar13;
          }
          cVar11 = FUN_2b1a6a60060(&local_70);
          if (cVar11 == '\0') goto LAB_2b1a6a6e36c;
          lVar10 = CONCAT44(local_68,uStack_6c);
          if (uVar14 != 0) {
            lVar1 = lVar10 + (ulonglong)uVar13 * 2;
            if (uVar4 < 8) {
              uVar12 = 0;
            }
            else if ((ulonglong)(lVar1 - lVar5) < 0x20) {
              uVar12 = 0;
            }
            else {
              uVar15 = 0;
              uVar12 = (ulonglong)(uVar4 & 0xfffffff8);
              do {
                puVar3 = (undefined4 *)(lVar5 + uVar15);
                uVar7 = puVar3[1];
                uVar8 = puVar3[2];
                uVar9 = puVar3[3];
                puVar2 = (undefined4 *)(lVar1 + uVar15);
                *puVar2 = *puVar3;
                puVar2[1] = uVar7;
                puVar2[2] = uVar8;
                puVar2[3] = uVar9;
                uVar15 = uVar15 + 0x10;
              } while ((uVar14 * 2 & 0xfffffffffffffff0) != uVar15);
              if (uVar12 == uVar14) goto LAB_2b1a6a6e010;
            }
            do {
              *(undefined2 *)(lVar1 + uVar12 * 2) = *(undefined2 *)(lVar5 + uVar12 * 2);
              uVar12 = uVar12 + 1;
            } while (uVar14 != uVar12);
          }
LAB_2b1a6a6e010:
          *(uint *)(lVar10 + -4) = uVar17;
          *(undefined2 *)(lVar10 + (ulonglong)uVar17 * 2) = 0;
        }
      }
      uVar16 = uVar16 + 1;
    } while ((int)uVar16 < (int)_DAT_2b1a6ca4236);
  }
  FUN_2b1a6a604e0(&local_50,&local_70,0,0x2b1a6ba3720);
  FUN_2b1a6a60000(&local_70);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_50,1,0x2b1a6ba3730);
  FUN_2b1a6a60000(&local_50);
  FUN_2b1a6a60000(&local_60);
  return;
}



/* Address: 2b1a6a6e3b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6e3b0(ulonglong param_1,char param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  code *pcVar3;
  double dVar4;
  undefined2 *puVar5;
  char cVar6;
  undefined8 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  uint uVar15;
  short *psVar16;
  uint uVar17;
  ulonglong uVar18;
  longlong lVar19;
  int iVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  uint uVar23;
  bool bVar24;
  undefined4 local_e8;
  longlong local_e4;
  undefined4 local_d8;
  longlong local_d4;
  undefined4 local_c8;
  longlong local_c4;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  short *local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_98 = 0;
  local_78 = 0;
  local_b8 = 0;
  local_c8 = 0;
  local_88 = 0;
  local_d8 = 0;
  local_68 = 0;
  local_a8 = 0;
  local_94 = 0;
  local_74 = 0;
  local_b4 = 0;
  local_c4 = 0;
  local_84 = 0;
  local_d4 = 0;
  local_64 = 0;
  local_a4 = (short *)0x0;
  dVar4 = (double)(~-(ulonglong)((double)(param_1 & _DAT_2b1a6a77a30) < _DAT_2b1a6a77a40) & param_1)
  ;
  (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,_DAT_2b1a6a77a30 & (ulonglong)dVar4,2);
  FUN_2b1a6a604e0(&local_d8,0x2b1a6dcd53c,1,0x2b1a6ba3740);
  uVar17 = 0;
  FUN_2b1a6a604e0(&local_a8,&local_d8,0,0x2b1a6ba3750);
  local_e8 = 0;
  local_e4 = 0;
  FUN_2b1a6a604e0(&local_e8,0x2b1a6a77f40,0);
  if (local_a4 == (short *)0x0) {
    _DAT_2b1a6dcd510 = 0xfa9;
  }
  else {
    uVar15 = *(uint *)(local_a4 + -2);
    if ((uVar15 == 0) || (_DAT_2b1a6a7813c == 0)) {
      _DAT_2b1a6dcd510 = 0x13ab;
      goto LAB_2b1a6a6e5c4;
    }
    uVar17 = 0;
    if (local_a4 == (short *)&DAT_2b1a6a78140) goto LAB_2b1a6a6e995;
    if ((uVar15 < _DAT_2b1a6a7813c) || (uVar10 = (uVar15 - _DAT_2b1a6a7813c) + 1, uVar10 == 0)) {
LAB_2b1a6a6e5c4:
      uVar14 = (ulonglong)uVar15;
      if (local_a4 == (short *)0xc) {
        uVar17 = 0;
        goto LAB_2b1a6a6e995;
      }
    }
    else {
      uVar18 = (ulonglong)uVar10;
      if (1 < _DAT_2b1a6a7813c) {
        bVar24 = true;
        uVar17 = 1;
        uVar14 = 0;
        do {
          if (local_a4[uVar14] == 0x2e) {
            psVar16 = (short *)&DAT_2b1a6a78142;
            lVar19 = (ulonglong)_DAT_2b1a6a7813c - 1;
            uVar10 = uVar17;
            while (local_a4[uVar10] == *psVar16) {
              psVar16 = psVar16 + 1;
              uVar10 = uVar10 + 1;
              lVar19 = lVar19 + -1;
              if (lVar19 == 0) goto LAB_2b1a6a6f099;
            }
            if ((int)lVar19 == 0) {
LAB_2b1a6a6f099:
              if (bVar24) goto LAB_2b1a6a6f0a6;
              break;
            }
          }
          uVar14 = uVar14 + 1;
          uVar17 = uVar17 + 1;
          bVar24 = uVar14 < uVar18;
        } while (uVar14 != uVar18);
        goto LAB_2b1a6a6e5c4;
      }
      if (*local_a4 == 0x2e) goto LAB_2b1a6a6e995;
      uVar14 = 0;
      do {
        if (uVar18 - 1 == uVar14) goto LAB_2b1a6a6e5c4;
        lVar19 = uVar14 + 1;
        uVar14 = uVar14 + 1;
      } while (local_a4[lVar19] != 0x2e);
      if (uVar18 <= uVar14) goto LAB_2b1a6a6e5c4;
LAB_2b1a6a6f0a6:
      if ((int)uVar14 < 0) goto LAB_2b1a6a6e5c4;
    }
    uVar17 = (uint)uVar14;
    if (0 < (int)uVar17) {
      uVar18 = 0;
      do {
        uVar15 = _DAT_2b1a6a7817c;
        if (((uVar18 != 0) && ((uVar17 - (int)uVar18) * -0x55555555 + 0x2aaaaaaa < 0x55555555)) &&
           ((uVar22 = (ulonglong)_DAT_2b1a6a7817c, uVar22 != 0 || (local_e4 == 0)))) {
          if (local_e4 == 0) {
            uVar10 = 0;
            uVar23 = _DAT_2b1a6a7817c;
          }
          else {
            uVar10 = *(uint *)(local_e4 + -4);
            uVar23 = _DAT_2b1a6a7817c + uVar10;
          }
          uVar11 = 0x104;
          if ((0x103 < uVar23) &&
             ((0x7ffffffd < uVar23 || (uVar11 = (uVar23 >> 2) + uVar23, 0x7ffffffd < uVar11)))) {
            uVar11 = 0x7ffffffe;
          }
          cVar6 = FUN_2b1a6a60060(&local_e8,uVar11);
          if (cVar6 != '\0') {
            if (uVar22 != 0) {
              lVar19 = local_e4 + (ulonglong)uVar10 * 2;
              if (uVar15 < 8) {
                uVar12 = 0;
              }
              else if (local_e4 + -0x2b1a6a78180 + (ulonglong)uVar10 * 2 < 0x20) {
                uVar12 = 0;
              }
              else {
                uVar21 = 0;
                uVar12 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar7 = *(undefined8 *)(uVar21 + 0x2b1a6a78188);
                  puVar1 = (undefined8 *)(lVar19 + uVar21);
                  *puVar1 = *(undefined8 *)(&DAT_2b1a6a78180 + uVar21);
                  puVar1[1] = uVar7;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar12 == uVar22) goto LAB_2b1a6a6e772;
              }
              do {
                *(undefined2 *)(lVar19 + uVar12 * 2) =
                     *(undefined2 *)(&DAT_2b1a6a78180 + uVar12 * 2);
                uVar12 = uVar12 + 1;
              } while (uVar22 != uVar12);
            }
LAB_2b1a6a6e772:
            *(uint *)(local_e4 + -4) = uVar23;
            *(undefined2 *)(local_e4 + (ulonglong)uVar23 * 2) = 0;
            goto LAB_2b1a6a6e790;
          }
LAB_2b1a6a6f0d3:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x21003c000101f9);
          goto LAB_2b1a6a6f0f3;
        }
LAB_2b1a6a6e790:
        uVar9 = 0xfa9;
        if ((local_a4 == (short *)0x0) || (local_a4 == (short *)0xc)) {
LAB_2b1a6a6e7f2:
          _DAT_2b1a6dcd510 = uVar9;
          if ((_DAT_2b1a6dcd540 == (undefined2 *)0x0) || (_DAT_2b1a6dcd540 == (undefined2 *)0xc)) {
            _DAT_2b1a6dcd510 = 0xfa9;
          }
          else if ((*(int *)(_DAT_2b1a6dcd540 + -2) != 0) &&
                  (cVar6 = FUN_2b1a6a60060(0x2b1a6dcd53c,0), puVar5 = _DAT_2b1a6dcd540,
                  cVar6 != '\0')) {
            *(undefined4 *)(_DAT_2b1a6dcd540 + -2) = 0;
            *puVar5 = 0;
          }
        }
        else {
          uVar9 = 0x13ab;
          if (*(uint *)(local_a4 + -2) <= uVar18) goto LAB_2b1a6a6e7f2;
          iVar8 = *(uint *)(local_a4 + -2) - (int)uVar18;
          iVar20 = 1;
          if ((iVar8 < 1) &&
             (_DAT_2b1a6dcd510 = 0x13ab, uVar9 = _DAT_2b1a6dcd510, iVar20 = iVar8, iVar8 == 0))
          goto LAB_2b1a6a6e7f2;
          FUN_2b1a6a601e0(0x2b1a6dcd53c,local_a4 + uVar18,iVar20);
        }
        FUN_2b1a6a604e0(&local_d8,0x2b1a6dcd53c,1);
        lVar19 = local_d4;
        if (local_d4 != 0) {
          uVar15 = *(uint *)(local_d4 + -4);
          uVar22 = (ulonglong)uVar15;
          if ((uVar22 != 0) || (local_e4 == 0)) {
            if (local_e4 == 0) {
              uVar10 = 0;
              uVar23 = uVar15;
            }
            else {
              uVar10 = *(uint *)(local_e4 + -4);
              uVar23 = uVar15 + uVar10;
            }
            cVar6 = FUN_2b1a6a60060(&local_e8);
            if (cVar6 == '\0') {
              (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x29003c000101f9);
              goto LAB_2b1a6a6f0d3;
            }
            if (uVar22 != 0) {
              lVar2 = local_e4 + (ulonglong)uVar10 * 2;
              if (uVar15 < 8) {
                uVar12 = 0;
              }
              else if ((ulonglong)(lVar2 - lVar19) < 0x20) {
                uVar12 = 0;
              }
              else {
                uVar21 = 0;
                uVar12 = (ulonglong)(uVar15 & 0xfffffff8);
                do {
                  uVar7 = ((undefined8 *)(lVar19 + uVar21))[1];
                  *(undefined8 *)(lVar2 + uVar21) = *(undefined8 *)(lVar19 + uVar21);
                  ((undefined8 *)(lVar2 + uVar21))[1] = uVar7;
                  uVar21 = uVar21 + 0x10;
                } while ((uVar22 * 2 & 0xfffffffffffffff0) != uVar21);
                if (uVar12 == uVar22) goto LAB_2b1a6a6e600;
              }
              do {
                *(undefined2 *)(lVar2 + uVar12 * 2) = *(undefined2 *)(lVar19 + uVar12 * 2);
                uVar12 = uVar12 + 1;
              } while (uVar22 != uVar12);
            }
LAB_2b1a6a6e600:
            *(uint *)(local_e4 + -4) = uVar23;
            *(undefined2 *)(local_e4 + (ulonglong)uVar23 * 2) = 0;
          }
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 != (uVar14 & 0xffffffff));
    }
  }
LAB_2b1a6a6e995:
  uVar7 = 0x2b1a6a781c8;
  if (dVar4 <= 0.0) {
    uVar7 = 0x2b1a6a77f40;
  }
  if (param_2 == '\0') {
    uVar7 = 0x2b1a6a77f40;
  }
  uVar13 = 0x2b1a6a781a8;
  if (0.0 <= dVar4) {
    uVar13 = uVar7;
  }
  FUN_2b1a6a604e0(&local_d8,uVar13,0);
  lVar19 = local_e4;
  if (local_e4 == 0) {
LAB_2b1a6a6eadd:
    uVar9 = 0xfa9;
    if ((local_a4 == (short *)0x0) || (local_a4 == (short *)0xc)) {
LAB_2b1a6a6eb2d:
      if ((_DAT_2b1a6dcd540 == (undefined2 *)0x0) || (_DAT_2b1a6dcd540 == (undefined2 *)0xc)) {
        _DAT_2b1a6dcd510 = 0xfa9;
      }
      else {
        _DAT_2b1a6dcd510 = uVar9;
        if ((*(int *)(_DAT_2b1a6dcd540 + -2) != 0) &&
           (cVar6 = FUN_2b1a6a60060(0x2b1a6dcd53c,0), puVar5 = _DAT_2b1a6dcd540, cVar6 != '\0')) {
          *(undefined4 *)(_DAT_2b1a6dcd540 + -2) = 0;
          *puVar5 = 0;
        }
      }
    }
    else {
      if (((int)uVar17 < 0) && (uVar17 = uVar17 + *(uint *)(local_a4 + -2), (int)uVar17 < 0)) {
        uVar9 = 0x13ab;
        goto LAB_2b1a6a6eb2d;
      }
      uVar9 = 0x13ab;
      if (*(uint *)(local_a4 + -2) <= uVar17) goto LAB_2b1a6a6eb2d;
      FUN_2b1a6a601e0(0x2b1a6dcd53c,local_a4 + uVar17);
    }
    FUN_2b1a6a604e0(&local_88,0x2b1a6dcd53c,1,0x2b1a6ba3790);
    FUN_2b1a6a604e0(&local_c8,&local_d8,0);
    lVar19 = local_84;
    if (local_84 == 0) {
LAB_2b1a6a6eccd:
      uVar17 = 0;
      FUN_2b1a6a604e0(&local_b8,&local_c8,0);
      uVar15 = _DAT_2b1a6a7817c;
      uVar18 = (ulonglong)_DAT_2b1a6a7817c;
      if ((uVar18 != 0) || (local_b4 == 0)) {
        if (local_b4 != 0) {
          uVar17 = *(uint *)(local_b4 + -4);
        }
        uVar10 = _DAT_2b1a6a7817c + uVar17;
        cVar6 = FUN_2b1a6a60060(&local_b8);
        if (cVar6 == '\0') {
LAB_2b1a6a6f0f3:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4b003d000101f9);
          goto LAB_2b1a6a6f113;
        }
        if (uVar18 != 0) {
          lVar19 = local_b4 + (ulonglong)uVar17 * 2;
          if ((uVar15 < 0x10) || (lVar19 - 0x2b1a6a78180U < 0x20)) {
            uVar14 = 0;
          }
          else {
            uVar22 = 0;
            uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
            do {
              uVar7 = *(undefined8 *)(uVar22 + 0x2b1a6a78188);
              *(undefined8 *)(lVar19 + uVar22) = *(undefined8 *)(&DAT_2b1a6a78180 + uVar22);
              ((undefined8 *)(lVar19 + uVar22))[1] = uVar7;
              uVar22 = uVar22 + 0x10;
            } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar14 == uVar18) goto LAB_2b1a6a6eda2;
          }
          do {
            *(undefined2 *)(lVar19 + uVar14 * 2) = *(undefined2 *)(&DAT_2b1a6a78180 + uVar14 * 2);
            uVar14 = uVar14 + 1;
          } while (uVar18 != uVar14);
        }
LAB_2b1a6a6eda2:
        *(uint *)(local_b4 + -4) = uVar10;
        *(undefined2 *)(local_b4 + (ulonglong)uVar10 * 2) = 0;
      }
      (*(code *)0x7ff63a0c7410)(0x2b1a1776bc8,0x24);
      FUN_2b1a6a604e0(&local_78,0x2b1a6dcd53c,1,0x2b1a6ba37c0);
      FUN_2b1a6a604e0(&local_98,&local_b8,0);
      lVar19 = local_74;
      if (local_74 == 0) goto LAB_2b1a6a6ef6d;
      uVar17 = *(uint *)(local_74 + -4);
      uVar18 = (ulonglong)uVar17;
      if ((uVar18 == 0) && (local_94 != 0)) goto LAB_2b1a6a6ef6d;
      if (local_94 == 0) {
        uVar15 = 0;
        uVar10 = uVar17;
      }
      else {
        uVar15 = *(uint *)(local_94 + -4);
        uVar10 = uVar17 + uVar15;
      }
      cVar6 = FUN_2b1a6a60060(&local_98);
      if (cVar6 == '\0') goto LAB_2b1a6a6f153;
      if (uVar18 != 0) {
        lVar2 = local_94 + (ulonglong)uVar15 * 2;
        if (uVar17 < 0x10) {
          uVar14 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar19) < 0x20) {
          uVar14 = 0;
        }
        else {
          uVar22 = 0;
          uVar14 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar7 = ((undefined8 *)(lVar19 + uVar22))[1];
            *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(lVar19 + uVar22);
            ((undefined8 *)(lVar2 + uVar22))[1] = uVar7;
            uVar22 = uVar22 + 0x10;
          } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar14 == uVar18) goto LAB_2b1a6a6ef62;
        }
        do {
          *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(lVar19 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar18 != uVar14);
      }
LAB_2b1a6a6ef62:
      *(uint *)(local_94 + -4) = uVar10;
      *(undefined2 *)(local_94 + (ulonglong)uVar10 * 2) = 0;
LAB_2b1a6a6ef6d:
      FUN_2b1a6a604e0(&local_68,&local_98,0,0x2b1a6ba37e0);
      FUN_2b1a6a60000(&local_e8);
      FUN_2b1a6a60000(&local_a8);
      FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_68,1,0x2b1a6ba37f0);
      FUN_2b1a6a60000(&local_68);
      FUN_2b1a6a60000(&local_d8);
      FUN_2b1a6a60000(&local_88);
      FUN_2b1a6a60000(&local_c8);
      FUN_2b1a6a60000(&local_b8);
      FUN_2b1a6a60000(&local_78);
      FUN_2b1a6a60000(&local_98);
      return;
    }
    uVar17 = *(uint *)(local_84 + -4);
    uVar18 = (ulonglong)uVar17;
    if ((uVar18 == 0) && (local_c4 != 0)) goto LAB_2b1a6a6eccd;
    if (local_c4 == 0) {
      uVar14 = 0;
      uVar15 = uVar17;
    }
    else {
      uVar14 = (ulonglong)*(uint *)(local_c4 + -4);
      uVar15 = uVar17 + *(uint *)(local_c4 + -4);
    }
    cVar6 = FUN_2b1a6a60060(&local_c8);
    if (cVar6 != '\0') {
      if (uVar18 != 0) {
        lVar2 = local_c4 + uVar14 * 2;
        if (uVar17 < 0x10) {
          uVar14 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar19) < 0x20) {
          uVar14 = 0;
        }
        else {
          uVar22 = 0;
          uVar14 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar7 = ((undefined8 *)(lVar19 + uVar22))[1];
            *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(lVar19 + uVar22);
            ((undefined8 *)(lVar2 + uVar22))[1] = uVar7;
            uVar22 = uVar22 + 0x10;
          } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar14 == uVar18) goto LAB_2b1a6a6ecc2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(lVar19 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar18 != uVar14);
      }
LAB_2b1a6a6ecc2:
      *(uint *)(local_c4 + -4) = uVar15;
      *(undefined2 *)(local_c4 + (ulonglong)uVar15 * 2) = 0;
      goto LAB_2b1a6a6eccd;
    }
  }
  else {
    uVar15 = *(uint *)(local_e4 + -4);
    uVar18 = (ulonglong)uVar15;
    if ((uVar18 == 0) && (local_d4 != 0)) goto LAB_2b1a6a6eadd;
    if (local_d4 == 0) {
      uVar14 = 0;
      uVar10 = uVar15;
    }
    else {
      uVar14 = (ulonglong)*(uint *)(local_d4 + -4);
      uVar10 = uVar15 + *(uint *)(local_d4 + -4);
    }
    cVar6 = FUN_2b1a6a60060(&local_d8);
    if (cVar6 != '\0') {
      if (uVar18 != 0) {
        lVar2 = local_d4 + uVar14 * 2;
        if (uVar15 < 0x10) {
          uVar14 = 0;
        }
        else if ((ulonglong)(lVar2 - lVar19) < 0x20) {
          uVar14 = 0;
        }
        else {
          uVar22 = 0;
          uVar14 = (ulonglong)(uVar15 & 0xfffffff8);
          do {
            uVar7 = ((undefined8 *)(lVar19 + uVar22))[1];
            *(undefined8 *)(lVar2 + uVar22) = *(undefined8 *)(lVar19 + uVar22);
            ((undefined8 *)(lVar2 + uVar22))[1] = uVar7;
            uVar22 = uVar22 + 0x10;
          } while ((uVar18 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar14 == uVar18) goto LAB_2b1a6a6ead2;
        }
        do {
          *(undefined2 *)(lVar2 + uVar14 * 2) = *(undefined2 *)(lVar19 + uVar14 * 2);
          uVar14 = uVar14 + 1;
        } while (uVar18 != uVar14);
      }
LAB_2b1a6a6ead2:
      *(uint *)(local_d4 + -4) = uVar10;
      *(undefined2 *)(local_d4 + (ulonglong)uVar10 * 2) = 0;
      goto LAB_2b1a6a6eadd;
    }
LAB_2b1a6a6f113:
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x33003d000101f9);
  }
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x35003d000101f9);
LAB_2b1a6a6f153:
  (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x4f003d000101f9);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Address: 2b1a6a6f180 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a6f180(void)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined8 local_24;
  
  local_28 = 0;
  local_24 = 0;
  if (_DAT_2b1a6ca4296 != -1) {
    (*(code *)0x7ff63a0eee30)(0x2b1a1776bc8);
  }
  uVar1 = _DAT_2b1a6ca4106;
  _DAT_2b1a6ca4296 = 0xffffffff;
  if (0 < _DAT_2b1a6ca4236) {
    FUN_2b1a6a6df60(0x2b1a6a77f60);
    FUN_2b1a6a604e0(&local_28,0x2b1a6dcd53c,1,0x2b1a6ba3800);
    _DAT_2b1a6ca4296 =
         (*(code *)0x7ff63a0e49f0)
                   (0x2b1a1776bc8,0x77,5,0x590008,0x2b1a6ca427e,0x520004,1,0x590008,0x2b1a6a78218,
                    0x590008,&local_28,0x520004,uVar1);
  }
  FUN_2b1a6a60000(&local_28);
  return;
}



/* Address: 2b1a6a6f2c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a6f2c0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 uVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  byte bVar16;
  ulonglong uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  double dVar21;
  double dVar22;
  ulonglong uVar23;
  longlong lVar24;
  ulonglong uVar25;
  uint uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  int iVar30;
  longlong lVar31;
  undefined1 *puVar32;
  bool bVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  double dVar40;
  double dVar41;
  double dVar42;
  double dVar43;
  double dVar44;
  double dVar45;
  undefined8 in_stack_fffffffffffffea8;
  
  uVar20 = (uint)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  iVar11 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6a,0);
  iVar12 = (*(code *)0x7ff63a0f53d0)(0x2b1a1776bc8,_DAT_2b1a6ca4262,0x6b,0);
  iVar13 = (*(code *)0x7ff63a0f0700)(0x2b1a1776bc8,0x1b);
  dVar7 = _DAT_2b1a6a77a68;
  dVar6 = _DAT_2b1a6a77a58;
  puVar32 = &DAT_2b1a6ca40f6;
  dVar34 = *(double *)((ulonglong)(DAT_2b1a6ca40f1 == '\0') * 8 + 0x2b1a6a77a48);
  dVar37 = _DAT_2b1a6a77a68;
  if (_DAT_2b1a6a77a68 <= (double)iVar13 / _DAT_2b1a6a77a60) {
    dVar37 = (double)iVar13 / _DAT_2b1a6a77a60;
  }
  iVar13 = iVar12 + _DAT_2b1a6ca40fa * -2;
  if (iVar13 < 2) {
    iVar13 = 1;
  }
  dVar35 = (double)iVar13 / dVar34;
  iVar13 = iVar11 + _DAT_2b1a6ca40f6 * -2;
  if (iVar13 < 2) {
    iVar13 = 1;
  }
  dVar37 = (dVar37 * (double)_DAT_2b1a6ca40fe * _DAT_2b1a6ca410e) / _DAT_2b1a6a77a58;
  dVar36 = (double)iVar13 / _DAT_2b1a6a77a58;
  if (dVar35 <= (double)iVar13 / _DAT_2b1a6a77a58) {
    dVar36 = dVar35;
  }
  if (dVar36 <= dVar37) {
    dVar37 = dVar36;
  }
  _DAT_2b1a6ca42bc = _DAT_2b1a6a77a70;
  if (_DAT_2b1a6a77a70 <= dVar37) {
    _DAT_2b1a6ca42bc = dVar37;
  }
  dVar35 = _DAT_2b1a6ca42bc * _DAT_2b1a6a77a58;
  uVar18 = (uint)((ulonglong)dVar35 >> 0x34) & 0x7ff;
  lVar24 = (ulonglong)uVar18 - 0x3ff;
  dVar37 = dVar35;
  if ((ulonglong)uVar18 < 0x433) {
    if (uVar18 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar35 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar24 != -1) {
        dVar37 = (double)((ulonglong)dVar35 & 0x8000000000000000);
      }
    }
    else {
      bVar16 = (byte)lVar24;
      if (((longlong)dVar35 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar35 &
                         -0x10000000000000 >> (bVar16 & 0x3f));
      }
    }
  }
  else if (lVar24 == 0x400) {
    dVar37 = dVar35 + dVar35;
  }
  dVar34 = dVar34 * _DAT_2b1a6ca42bc;
  iVar13 = 1;
  if (1 < (int)dVar37) {
    iVar13 = (int)dVar37;
  }
  uVar18 = (uint)((ulonglong)dVar34 >> 0x34) & 0x7ff;
  lVar24 = (ulonglong)uVar18 - 0x3ff;
  dVar37 = dVar34;
  if ((ulonglong)uVar18 < 0x433) {
    if (uVar18 < 0x3ff) {
      dVar37 = (double)((ulonglong)dVar34 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar24 != -1) {
        dVar37 = (double)((ulonglong)dVar34 & 0x8000000000000000);
      }
    }
    else {
      bVar16 = (byte)lVar24;
      if (((longlong)dVar34 << (bVar16 & 0x3f) & 0xfffffffffffffU) != 0) {
        dVar37 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar34 &
                         -0x10000000000000 >> (bVar16 & 0x3f));
      }
    }
  }
  else if (lVar24 == 0x400) {
    dVar37 = dVar34 + dVar34;
  }
  uVar27 = 1;
  if (1 < (int)dVar37) {
    uVar27 = (ulonglong)(uint)(int)dVar37;
  }
  bVar33 = false;
  uVar18 = (uint)uVar27;
  if (iVar13 == _DAT_2b1a6ca42a2) {
    if (uVar18 == _DAT_2b1a6ca42a6) {
      iVar14 = (*(code *)0x7ff63a0f4840)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272);
      bVar33 = -1 < iVar14;
    }
    else {
      bVar33 = false;
    }
  }
  _DAT_2b1a6ca42aa = (iVar11 - iVar13) - _DAT_2b1a6ca40f6;
  if (_DAT_2b1a6ca40f2 - 4U < 0xfffffffe) {
    _DAT_2b1a6ca42aa = _DAT_2b1a6ca40f6;
  }
  if (_DAT_2b1a6ca42aa < 1) {
    _DAT_2b1a6ca42aa = 0;
  }
  _DAT_2b1a6ca42ae = (iVar12 - uVar18) - _DAT_2b1a6ca40fa;
  if (_DAT_2b1a6ca40f2 - 3U < 0xfffffffe) {
    _DAT_2b1a6ca42ae = _DAT_2b1a6ca40fa;
  }
  if (_DAT_2b1a6ca42ae < 1) {
    _DAT_2b1a6ca42ae = 0;
  }
  _DAT_2b1a6ca429a = iVar11;
  _DAT_2b1a6ca429e = iVar12;
  if (!bVar33) {
    FUN_2b1a6a60830(&DAT_2b1a6ca412a);
    uVar9 = _DAT_2b1a6ca4262;
    lVar31 = (longlong)_DAT_2b1a6ca42ae;
    lVar24 = (longlong)_DAT_2b1a6ca42aa;
    cVar10 = FUN_2b1a6a60910(&DAT_2b1a6ca412a,&DAT_2b1a6ca4272,iVar13,uVar27,
                             (ulonglong)uVar20 << 0x20);
    if ((((cVar10 == '\0') ||
         (cVar10 = (*(code *)0x7ff63a0e49f0)
                             (0x2b1a1776bc8,0x112,6,0x550005,uVar9,0x590008,&DAT_2b1a6ca4272,
                              0x520004,0x6a,0x520004,0,0x540005,0,0x580007,0), cVar10 == '\0')) ||
        (cVar10 = (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,uVar9,&DAT_2b1a6ca4272,0x3f4,lVar24),
        cVar10 == '\0')) ||
       (cVar10 = (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,uVar9,&DAT_2b1a6ca4272,0x3f5,lVar31),
       cVar10 == '\0')) {
LAB_2b1a6a701bc:
      puVar32 = (undefined1 *)0x0;
      goto LAB_2b1a6a701bf;
    }
    cVar10 = (*(code *)0x7ff63a0f3c80)(0x2b1a1776bc8,uVar9,&DAT_2b1a6ca4272,0x3f9,&DAT_2b1a6ca415a);
    puVar32 = (undefined1 *)0x0;
    if (cVar10 == '\0') goto LAB_2b1a6a701bf;
    _DAT_2b1a6ca4142 = uVar9;
    FUN_2b1a6a604e0(&DAT_2b1a6ca414a,&DAT_2b1a6ca4272,0,0x2b1a6ba3670);
    _DAT_2b1a6ca4156 = 0x6a;
    _DAT_2b1a6ca42a2 = iVar13;
    _DAT_2b1a6ca42a6 = uVar18;
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0x402,0);
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,10,0);
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0xd0,1);
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,3,0);
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0x3fb,iVar13);
    (*(code *)0x7ff63a0f3b30)(0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0x3fc,uVar27);
    dVar8 = _DAT_2b1a6a77a98;
    dVar36 = _DAT_2b1a6a77a90;
    dVar35 = _DAT_2b1a6a77a88;
    dVar37 = _DAT_2b1a6a77a80;
    dVar34 = _DAT_2b1a6a77a78;
    uVar38 = SUB84(_DAT_2b1a6ca42bc,0);
    uVar39 = (undefined4)((ulonglong)_DAT_2b1a6ca42bc >> 0x20);
    do {
      if (((double)CONCAT44(uVar39,uVar38) == 0.0) && (!NAN((double)CONCAT44(uVar39,uVar38)))) {
LAB_2b1a6a70326:
        (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1d0077000101f7);
        pcVar4 = (code *)swi(3);
        uVar27 = (*pcVar4)();
        return uVar27;
      }
      iVar11 = (int)puVar32;
      dVar40 = ((double)iVar11 + dVar34) / (double)CONCAT44(uVar39,uVar38) + dVar37;
      dVar5 = dVar40 + dVar35;
      if (DAT_2b1a6ca40f1 != '\0') {
        dVar5 = dVar40;
      }
      iVar12 = 0;
      do {
        if (((double)CONCAT44(uVar39,uVar38) == 0.0) && (!NAN((double)CONCAT44(uVar39,uVar38)))) {
LAB_2b1a6a70306:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x34007c000101f7);
          goto LAB_2b1a6a70326;
        }
        dVar41 = ((double)_DAT_2b1a6ca422a *
                 (double)(-(ulonglong)(dVar36 <= dVar40) & (ulonglong)dVar5 |
                         ~-(ulonglong)(dVar36 <= dVar40) & (ulonglong)dVar40)) / dVar8;
        dVar42 = ((double)_DAT_2b1a6ca4226 *
                 (((double)iVar12 + dVar34) / (double)CONCAT44(uVar39,uVar38) + dVar37)) / dVar6;
        dVar21 = ABS(dVar42);
        dVar44 = dVar42;
        if ((ulonglong)dVar21 < 0x3ff0000000000000) {
          if ((dVar21 != 0.0) && (dVar44 = 0.0, (longlong)dVar42 < 0)) {
            dVar44 = _DAT_2b1a6a77aa0;
          }
        }
        else if ((((ulonglong)dVar21 < 0x4340000000000000) &&
                 (bVar16 = 0x33 - (char)((ulonglong)dVar21 >> 0x34),
                 dVar22 = (double)(((ulonglong)dVar21 >> (bVar16 & 0x3f)) << (bVar16 & 0x3f)),
                 dVar44 = dVar22, (longlong)dVar42 < 1)) &&
                (dVar44 = (double)((ulonglong)dVar22 | 0x8000000000000000), dVar22 != dVar21)) {
          dVar44 = dVar44 + _DAT_2b1a6a77aa0;
        }
        dVar22 = ABS(dVar41);
        dVar21 = dVar41;
        if ((ulonglong)dVar22 < 0x3ff0000000000000) {
          if ((dVar22 != 0.0) && (dVar21 = 0.0, (longlong)dVar41 < 0)) {
            dVar21 = _DAT_2b1a6a77aa0;
          }
        }
        else if ((((ulonglong)dVar22 < 0x4340000000000000) &&
                 (bVar16 = 0x33 - (char)((ulonglong)dVar22 >> 0x34),
                 dVar43 = (double)(((ulonglong)dVar22 >> (bVar16 & 0x3f)) << (bVar16 & 0x3f)),
                 dVar21 = dVar43, (longlong)dVar41 < 1)) &&
                (dVar21 = (double)((ulonglong)dVar43 | 0x8000000000000000), dVar43 != dVar22)) {
          dVar21 = dVar21 + _DAT_2b1a6a77aa0;
        }
        iVar14 = _DAT_2b1a6ca4226 - 1;
        iVar15 = iVar14;
        if ((int)dVar44 <= iVar14) {
          iVar15 = (int)dVar44;
        }
        if (iVar15 < 1) {
          iVar15 = 0;
        }
        iVar30 = _DAT_2b1a6ca422a - 1;
        iVar19 = iVar30;
        if ((int)dVar21 <= iVar30) {
          iVar19 = (int)dVar21;
        }
        if (iVar19 < 1) {
          iVar19 = 0;
        }
        if (iVar15 + 1 <= iVar14) {
          iVar14 = iVar15 + 1;
        }
        if (iVar19 + 1 <= iVar30) {
          iVar30 = iVar19 + 1;
        }
        uVar29 = (ulonglong)(int)(iVar19 * _DAT_2b1a6ca4226 + iVar15);
        uVar17 = (ulonglong)_DAT_2b1a6ca41c6;
        if (uVar17 <= uVar29) {
LAB_2b1a6a702a6:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x200050000101f6);
LAB_2b1a6a702c6:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x200051000101f6);
LAB_2b1a6a702e6:
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3a0050000101f6);
          goto LAB_2b1a6a70306;
        }
        uVar23 = ~uVar29 + uVar17;
        if ((_DAT_2b1a6ca41c0 & 0x10) == 0) {
          uVar23 = uVar29;
        }
        uVar29 = (ulonglong)(int)(iVar19 * _DAT_2b1a6ca4226 + iVar14);
        if (uVar17 <= uVar29) goto LAB_2b1a6a702e6;
        uVar25 = ~uVar29 + uVar17;
        if ((_DAT_2b1a6ca41c0 & 0x10) == 0) {
          uVar25 = uVar29;
        }
        uVar29 = (ulonglong)(int)(iVar30 * _DAT_2b1a6ca4226 + iVar15);
        if (uVar17 <= uVar29) goto LAB_2b1a6a702c6;
        uVar28 = ~uVar29 + uVar17;
        if ((_DAT_2b1a6ca41c0 & 0x10) == 0) {
          uVar28 = uVar29;
        }
        uVar29 = (ulonglong)(int)(iVar30 * _DAT_2b1a6ca4226 + iVar14);
        if (uVar17 <= uVar29) {
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x3a0051000101f6);
          goto LAB_2b1a6a702a6;
        }
        dVar44 = dVar7;
        if (dVar42 - (double)iVar15 <= dVar7) {
          dVar44 = dVar42 - (double)iVar15;
        }
        dVar21 = 0.0;
        if (0.0 <= dVar44) {
          dVar21 = dVar44;
        }
        dVar44 = dVar7;
        if (dVar41 - (double)iVar19 <= dVar7) {
          dVar44 = dVar41 - (double)iVar19;
        }
        dVar41 = dVar7 - dVar21;
        uVar20 = *(uint *)(_DAT_2b1a6ca41da + uVar25 * 4);
        uVar1 = *(uint *)(_DAT_2b1a6ca41da + uVar23 * 4);
        uVar2 = *(uint *)(_DAT_2b1a6ca41da + uVar28 * 4);
        dVar42 = 0.0;
        if (0.0 <= dVar44) {
          dVar42 = dVar44;
        }
        dVar44 = dVar7 - dVar42;
        uVar17 = ~uVar29 + uVar17;
        if ((_DAT_2b1a6ca41c0 & 0x10) == 0) {
          uVar17 = uVar29;
        }
        uVar3 = *(uint *)(_DAT_2b1a6ca41da + uVar17 * 4);
        dVar43 = ((double)(uVar3 & 0xff) * dVar21 + (double)(uVar2 & 0xff) * dVar41) * dVar42 +
                 ((double)(uVar20 & 0xff) * dVar21 + (double)(uVar1 & 0xff) * dVar41) * dVar44;
        uVar26 = (uint)((ulonglong)dVar43 >> 0x34) & 0x7ff;
        lVar24 = (ulonglong)uVar26 - 0x3ff;
        dVar22 = dVar43;
        if ((ulonglong)uVar26 < 0x433) {
          if (uVar26 < 0x3ff) {
            dVar22 = (double)((ulonglong)dVar43 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar24 != -1) {
              dVar22 = (double)((ulonglong)dVar43 & 0x8000000000000000);
            }
          }
          else {
            bVar16 = (byte)lVar24;
            if ((0xfffffffffffffU >> (bVar16 & 0x3f) & (ulonglong)dVar43) != 0) {
              dVar22 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar43 &
                               -0x10000000000000 >> (bVar16 & 0x3f));
            }
          }
        }
        else if (lVar24 == 0x400) {
          dVar22 = dVar43 + dVar43;
        }
        dVar45 = ((double)(uVar3 >> 8 & 0xff) * dVar21 + (double)(uVar2 >> 8 & 0xff) * dVar41) *
                 dVar42 + ((double)(uVar20 >> 8 & 0xff) * dVar21 +
                          (double)(uVar1 >> 8 & 0xff) * dVar41) * dVar44;
        uVar26 = (uint)((ulonglong)dVar45 >> 0x34) & 0x7ff;
        lVar24 = (ulonglong)uVar26 - 0x3ff;
        dVar43 = dVar45;
        if ((ulonglong)uVar26 < 0x433) {
          if (uVar26 < 0x3ff) {
            dVar43 = (double)((ulonglong)dVar45 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar24 != -1) {
              dVar43 = (double)((ulonglong)dVar45 & 0x8000000000000000);
            }
          }
          else {
            bVar16 = (byte)lVar24;
            if ((0xfffffffffffffU >> (bVar16 & 0x3f) & (ulonglong)dVar45) != 0) {
              dVar43 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar45 &
                               -0x10000000000000 >> (bVar16 & 0x3f));
            }
          }
        }
        else if (lVar24 == 0x400) {
          dVar43 = dVar45 + dVar45;
        }
        dVar21 = dVar42 * ((double)(uVar3 >> 0x10 & 0xff) * dVar21 +
                          (double)(uVar2 >> 0x10 & 0xff) * dVar41) +
                 dVar44 * ((double)(uVar20 >> 0x10 & 0xff) * dVar21 +
                          (double)(uVar1 >> 0x10 & 0xff) * dVar41);
        uVar20 = (uint)((ulonglong)dVar21 >> 0x34) & 0x7ff;
        lVar24 = (ulonglong)uVar20 - 0x3ff;
        dVar44 = dVar21;
        if ((ulonglong)uVar20 < 0x433) {
          if (uVar20 < 0x3ff) {
            dVar44 = (double)((ulonglong)dVar21 & 0x8000000000000000 | 0x3ff0000000000000);
            if (lVar24 != -1) {
              dVar44 = (double)((ulonglong)dVar21 & 0x8000000000000000);
            }
          }
          else {
            bVar16 = (byte)lVar24;
            if ((0xfffffffffffffU >> (bVar16 & 0x3f) & (ulonglong)dVar21) != 0) {
              dVar44 = (double)((0x8000000000000U >> (bVar16 & 0x3f)) + (longlong)dVar21 &
                               -0x10000000000000 >> (bVar16 & 0x3f));
            }
          }
        }
        else if (lVar24 == 0x400) {
          dVar44 = dVar21 + dVar21;
        }
        if ((iVar12 < _DAT_2b1a6ca4166) && (iVar11 < _DAT_2b1a6ca416a)) {
          uVar17 = (ulonglong)(_DAT_2b1a6ca4166 * iVar11 + iVar12);
          if (_DAT_2b1a6ca4192 <= uVar17) {
            (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1801ea000201f6);
            goto LAB_2b1a6a701bc;
          }
          uVar29 = (ulonglong)_DAT_2b1a6ca4192 + ~uVar17;
          if ((_DAT_2b1a6ca418c & 0x10) == 0) {
            uVar29 = uVar17;
          }
          *(uint *)(_DAT_2b1a6ca41a6 + uVar29 * 4) =
               (int)(longlong)dVar44 << 0x10 | (uint)(longlong)dVar22 | (int)(longlong)dVar43 << 8 |
               0xff000000;
          uVar38 = SUB84(_DAT_2b1a6ca42bc,0);
          uVar39 = (undefined4)((ulonglong)_DAT_2b1a6ca42bc >> 0x20);
        }
        iVar12 = iVar12 + 1;
      } while (iVar13 != iVar12);
      puVar32 = (undefined1 *)(ulonglong)(iVar11 + 1U);
    } while (iVar11 + 1U != uVar18);
    (*(code *)0x7ff63a0c7470)
              (0x2b1a1776bc8,&DAT_2b1a6ca41f2,&DAT_2b1a6ca418a,0,uVar27 & 0xffffffff00000000,
               0xffffffff);
  }
  (*(code *)0x7ff63a0f3b30)
            (0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0x3f4,(longlong)_DAT_2b1a6ca42aa);
  (*(code *)0x7ff63a0f3b30)
            (0x2b1a1776bc8,_DAT_2b1a6ca4262,&DAT_2b1a6ca4272,0x3f5,(longlong)_DAT_2b1a6ca42ae);
  puVar32 = (undefined1 *)CONCAT71((int7)((ulonglong)puVar32 >> 8),1);
  DAT_2b1a6ca42bb = 0;
LAB_2b1a6a701bf:
  return (ulonglong)puVar32 & 0xffffffff;
}



/* Address: 2b1a6a70350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a70350(undefined8 param_1,double param_2,double param_3,double param_4,double param_5,
                    double param_6,uint param_7,char param_8)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined2 *puVar5;
  char cVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  longlong local_94;
  
  local_98 = 0;
  local_a8 = 0;
  local_94 = 0;
  local_a4 = 0;
  local_b8 = 0;
  uStack_b4 = 0;
  local_b0 = 0;
  FUN_2b1a6a604e0(&local_b8,param_1,0,0x2b1a6ba3810);
  dVar19 = (param_3 - param_2) * _DAT_2b1a6ca42bc;
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
      bVar7 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)dVar19) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar19 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = dVar19 + dVar19;
  }
  param_5 = param_5 * _DAT_2b1a6ca42bc;
  local_bc = 1;
  if (1 < (int)dVar18) {
    local_bc = (int)dVar18;
  }
  uVar8 = (uint)((ulonglong)param_5 >> 0x34) & 0x7ff;
  lVar1 = (ulonglong)uVar8 - 0x3ff;
  dVar18 = param_5;
  if ((ulonglong)uVar8 < 0x433) {
    if (uVar8 < 0x3ff) {
      dVar18 = (double)((ulonglong)param_5 & 0x8000000000000000 | 0x3ff0000000000000);
      if (lVar1 != -1) {
        dVar18 = (double)((ulonglong)param_5 & 0x8000000000000000);
      }
    }
    else {
      bVar7 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)param_5) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)param_5 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = param_5 + param_5;
  }
  local_ac = 1;
  if (1 < (int)dVar18) {
    local_ac = (int)dVar18;
  }
  dVar19 = _DAT_2b1a6ca42bc * (((double)_DAT_2b1a6ca4102 * param_6) / _DAT_2b1a6a77aa8);
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
      bVar7 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)dVar19) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar19 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = dVar19 + dVar19;
  }
  iVar14 = (int)dVar18;
  iVar12 = 1;
  if (1 < iVar14) {
    iVar12 = iVar14;
  }
  cVar6 = (*(code *)0x7ff639d982a0)(0x2b1a1776bc8,0x2b1a6a78250,iVar12,8,0);
  if (cVar6 != '\0') {
    FUN_2b1a6a604e0(&DAT_2b1a6ca4172,0x2b1a6a78250,0,0x2b1a6ba36a0);
    _DAT_2b1a6ca4182 = 8;
    _DAT_2b1a6ca417e = iVar12;
  }
  if (1 < iVar14) {
    uVar8 = iVar12 + 1;
    do {
      cVar6 = (*(code *)0x7ff639d982a0)
                        (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,
                         _DAT_2b1a6ca4182 & 0xffffffff,_DAT_2b1a6ca4186);
      if ((cVar6 == '\0') ||
         ((*(code *)0x7ff639d98480)(0x2b1a1776bc8,&local_b8,&local_c4,&local_c0),
         local_c4 <= local_bc)) {
        cVar6 = (*(code *)0x7ff639d982a0)
                          (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,
                           _DAT_2b1a6ca4182 & 0xffffffff,_DAT_2b1a6ca4186);
        if ((cVar6 == '\0') ||
           ((*(code *)0x7ff639d98480)(0x2b1a1776bc8,&local_b8,&local_c4,&local_c0),
           local_c0 <= local_ac)) break;
      }
      cVar6 = (*(code *)0x7ff639d982a0)(0x2b1a1776bc8,0x2b1a6a78250,uVar8 - 2,8,0);
      if (cVar6 != '\0') {
        FUN_2b1a6a604e0(&DAT_2b1a6ca4172,0x2b1a6a78250,0,0x2b1a6ba36a0);
        _DAT_2b1a6ca4182 = 8;
        _DAT_2b1a6ca417e = uVar8 - 2;
      }
      uVar8 = uVar8 - 1;
    } while (2 < uVar8);
  }
  cVar6 = (*(code *)0x7ff639d982a0)
                    (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,_DAT_2b1a6ca4182 & 0xffffffff,
                     _DAT_2b1a6ca4186);
  if (cVar6 != '\0') {
    do {
      (*(code *)0x7ff639d98480)(0x2b1a1776bc8,&local_b8,&local_c4,&local_c0);
      if ((((local_c4 <= local_bc) || (lVar1 = CONCAT44(local_b0,uStack_b4), lVar1 == 0)) ||
          (lVar1 == 0xc)) || (*(int *)(lVar1 + -4) < 4)) break;
      if (*(int *)(lVar1 + -4) == 4) {
        if ((_DAT_2b1a6dcd540 == (undefined2 *)0x0) || (_DAT_2b1a6dcd540 == (undefined2 *)0xc)) {
          _DAT_2b1a6dcd510 = 0xfa9;
        }
        else if ((*(int *)(_DAT_2b1a6dcd540 + -2) != 0) &&
                (cVar6 = FUN_2b1a6a60060(0x2b1a6dcd53c,0), puVar5 = _DAT_2b1a6dcd540, cVar6 != '\0')
                ) {
          *(undefined4 *)(_DAT_2b1a6dcd540 + -2) = 0;
          *puVar5 = 0;
        }
      }
      else {
        FUN_2b1a6a601e0(0x2b1a6dcd53c,lVar1);
      }
      FUN_2b1a6a604e0(&local_a8,0x2b1a6dcd53c,1,0x2b1a6ba3820);
      FUN_2b1a6a604e0(&local_98,&local_a8,0,0x2b1a6ba3830);
      uVar8 = _DAT_2b1a6a78268;
      uVar11 = (ulonglong)_DAT_2b1a6a78268;
      if ((uVar11 != 0) || (local_94 == 0)) {
        if (local_94 == 0) {
          uVar17 = 0;
          uVar16 = _DAT_2b1a6a78268;
        }
        else {
          uVar17 = *(uint *)(local_94 + -4);
          uVar16 = _DAT_2b1a6a78268 + uVar17;
        }
        uVar9 = 0x104;
        if ((0x103 < uVar16) &&
           ((0x7ffffffd < uVar16 || (uVar9 = (uVar16 >> 2) + uVar16, 0x7ffffffd < uVar9)))) {
          uVar9 = 0x7ffffffe;
        }
        cVar6 = FUN_2b1a6a60060(&local_98,uVar9);
        if (cVar6 == '\0') {
          (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x340090000101f9);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        if (uVar11 != 0) {
          lVar1 = local_94 + (ulonglong)uVar17 * 2;
          if (uVar8 < 8) {
            uVar10 = 0;
          }
          else if (local_94 + -0x2b1a6a7826c + (ulonglong)uVar17 * 2 < 0x20) {
            uVar10 = 0;
          }
          else {
            uVar15 = 0;
            uVar10 = (ulonglong)(uVar8 & 0xfffffff8);
            do {
              uVar4 = *(undefined8 *)(uVar15 + 0x2b1a6a78274);
              puVar2 = (undefined8 *)(lVar1 + uVar15);
              *puVar2 = *(undefined8 *)(&DAT_2b1a6a7826c + uVar15);
              puVar2[1] = uVar4;
              uVar15 = uVar15 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar15);
            if (uVar10 == uVar11) goto LAB_2b1a6a70870;
          }
          do {
            *(undefined2 *)(lVar1 + uVar10 * 2) = *(undefined2 *)(&DAT_2b1a6a7826c + uVar10 * 2);
            uVar10 = uVar10 + 1;
          } while (uVar11 != uVar10);
        }
LAB_2b1a6a70870:
        *(uint *)(local_94 + -4) = uVar16;
        *(undefined2 *)(local_94 + (ulonglong)uVar16 * 2) = 0;
      }
      FUN_2b1a6a604e0(&local_b8,&local_98,0,0x2b1a6ba3840);
      cVar6 = (*(code *)0x7ff639d982a0)
                        (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,
                         _DAT_2b1a6ca4182 & 0xffffffff,_DAT_2b1a6ca4186);
    } while (cVar6 != '\0');
  }
  cVar6 = (*(code *)0x7ff639d982a0)
                    (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,_DAT_2b1a6ca4182 & 0xffffffff,
                     _DAT_2b1a6ca4186);
  iVar12 = 0;
  if (cVar6 != '\0') {
    (*(code *)0x7ff639d98480)(0x2b1a1776bc8,&local_b8,&local_c4,&local_c0);
    iVar12 = local_c4;
  }
  cVar6 = (*(code *)0x7ff639d982a0)
                    (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,_DAT_2b1a6ca4182 & 0xffffffff,
                     _DAT_2b1a6ca4186);
  iVar14 = 0;
  if (cVar6 != '\0') {
    (*(code *)0x7ff639d98480)(0x2b1a1776bc8,&local_b8,&local_c4,&local_c0);
    iVar14 = local_c0;
  }
  if (param_8 == '\0') {
    param_3 = param_3 * _DAT_2b1a6ca42bc;
    uVar8 = (uint)((ulonglong)param_3 >> 0x34) & 0x7ff;
    lVar1 = (ulonglong)uVar8 - 0x3ff;
    dVar18 = param_3;
    if ((ulonglong)uVar8 < 0x433) {
      if (uVar8 < 0x3ff) {
        dVar18 = (double)((ulonglong)param_3 & 0x8000000000000000 | 0x3ff0000000000000);
        if (lVar1 != -1) {
          dVar18 = (double)((ulonglong)param_3 & 0x8000000000000000);
        }
      }
      else {
        bVar7 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)param_3) != 0) {
          dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)param_3 &
                           -0x10000000000000 >> (bVar7 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar18 = param_3 + param_3;
    }
    iVar13 = (int)dVar18 - iVar12;
  }
  else {
    dVar19 = (param_2 + param_3) * _DAT_2b1a6a77ab0 * _DAT_2b1a6ca42bc;
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
        bVar7 = (byte)lVar1;
        if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)dVar19) != 0) {
          dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar19 &
                           -0x10000000000000 >> (bVar7 & 0x3f));
        }
      }
    }
    else if (lVar1 == 0x400) {
      dVar18 = dVar19 + dVar19;
    }
    iVar13 = (int)dVar18 - iVar12 / 2;
  }
  dVar18 = param_4;
  if (DAT_2b1a6ca40f1 == '\0') {
    dVar18 = _DAT_2b1a6a77ab8 + param_4;
  }
  dVar19 = _DAT_2b1a6ca42bc *
           (double)(~-(ulonglong)(_DAT_2b1a6a77ac0 <= param_4) & (ulonglong)param_4 |
                   (ulonglong)dVar18 & -(ulonglong)(_DAT_2b1a6a77ac0 <= param_4));
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
      bVar7 = (byte)lVar1;
      if ((0xfffffffffffffU >> (bVar7 & 0x3f) & (ulonglong)dVar19) != 0) {
        dVar18 = (double)((0x8000000000000U >> (bVar7 & 0x3f)) + (longlong)dVar19 &
                         -0x10000000000000 >> (bVar7 & 0x3f));
      }
    }
  }
  else if (lVar1 == 0x400) {
    dVar18 = dVar19 + dVar19;
  }
  if ((iVar12 <= local_bc) && (iVar14 <= local_ac)) {
    FUN_2b1a6a604e0(&local_a8,&local_b8,0,0x2b1a6ba3850);
    cVar6 = (*(code *)0x7ff639d982a0)
                      (0x2b1a1776bc8,&DAT_2b1a6ca4172,_DAT_2b1a6ca417e,_DAT_2b1a6ca4182 & 0xffffffff
                       ,_DAT_2b1a6ca4186);
    if (cVar6 != '\0') {
      (*(code *)0x7ff639d98540)
                (0x2b1a1776bc8,&local_a8,iVar13,(int)dVar18 - iVar14 / 2,0,&DAT_2b1a6ca418a,
                 _DAT_2b1a6ca4166,_DAT_2b1a6ca416a,
                 param_7 >> 0x10 & 0xff | param_7 & 0xff00 | param_7 << 0x10 | 0xff000000,
                 _DAT_2b1a6ca416e);
    }
  }
  FUN_2b1a6a60000(&local_b8);
  FUN_2b1a6a60000(&local_a8);
  FUN_2b1a6a60000(&local_98);
  return;
}



/* Address: 2b1a6a71000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a71000(int param_1,int param_2,int param_3,ulonglong param_4,uint param_5)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  
  iVar7 = (int)param_4;
  iVar14 = iVar7 + param_2;
  iVar10 = (int)(((uint)(param_4 >> 0x1f) & 1) + iVar7) >> 1;
  uVar17 = (param_3 + param_1) - iVar10;
  uVar8 = param_1 + iVar10;
  uVar5 = param_5 >> 0x10 & 0xff | param_5 & 0xff00 | param_5 << 0x10 | 0xff000000;
  uVar19 = uVar8;
  if ((int)uVar8 < (int)uVar17) {
    uVar19 = uVar17;
  }
  uVar6 = uVar8;
  if ((int)uVar17 < (int)uVar8) {
    uVar6 = uVar17;
  }
  iVar11 = param_2;
  if (param_2 < iVar14) {
    iVar11 = iVar14;
  }
  if (param_2 <= iVar14) {
    iVar14 = param_2;
  }
  if ((((-1 < (int)uVar19) && (-1 < iVar11)) && ((int)uVar6 < _DAT_2b1a6ca4166)) &&
     (iVar14 < _DAT_2b1a6ca416a)) {
    if ((int)uVar6 < 1) {
      uVar6 = 0;
    }
    iVar13 = 0;
    if (0 < iVar14) {
      iVar13 = iVar14;
    }
    uVar3 = _DAT_2b1a6ca4166 - 1;
    if ((int)uVar19 < _DAT_2b1a6ca4166) {
      uVar3 = uVar19;
    }
    iVar14 = _DAT_2b1a6ca416a + -1;
    if (iVar11 < _DAT_2b1a6ca416a) {
      iVar14 = iVar11;
    }
    if (iVar13 <= iVar14) {
      uVar19 = (uVar3 - uVar6) + 1;
      if (uVar19 == 0) {
        do {
          iVar13 = iVar13 + 1;
        } while (iVar13 <= iVar14);
      }
      else {
        iVar21 = 0;
        iVar11 = iVar13;
        do {
          lVar4 = _DAT_2b1a6ca41a6;
          iVar22 = _DAT_2b1a6ca4166 * iVar11;
          uVar18 = iVar22 + uVar6;
          uVar15 = uVar18 + uVar19;
          if ((CARRY4(uVar18,uVar19)) || (_DAT_2b1a6ca4192 < uVar15)) {
            (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x60793000201f6);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          uVar9 = uVar6 + 1 + iVar22;
          uVar12 = uVar9;
          if (uVar9 < uVar15) {
            uVar12 = uVar15;
          }
          iVar20 = (iVar13 + iVar21) * _DAT_2b1a6ca4166;
          uVar12 = (uVar12 - uVar6) - iVar20;
          if (uVar12 < 0x14) {
LAB_2b1a6a711d0:
            do {
              *(uint *)(lVar4 + (longlong)(int)uVar18 * 4) = uVar5;
              uVar18 = uVar18 + 1;
            } while (uVar18 < uVar15);
          }
          else {
            uVar24 = uVar9;
            if (uVar9 < uVar15) {
              uVar24 = uVar15;
            }
            if ((int)(((uVar24 + ~uVar6) - iVar20) + uVar18) < (int)uVar18) goto LAB_2b1a6a711d0;
            uVar23 = iVar22 + uVar3 + 1;
            uVar24 = uVar18 + (uVar12 & 0xfffffff8);
            if (uVar23 <= uVar9) {
              uVar23 = uVar9;
            }
            uVar9 = uVar23 - uVar18 & 0xfffffff8;
            do {
              puVar1 = (uint *)(lVar4 + (longlong)(int)uVar18 * 4);
              *puVar1 = uVar5;
              puVar1[1] = uVar5;
              puVar1[2] = uVar5;
              puVar1[3] = uVar5;
              puVar1 = (uint *)(lVar4 + 0x10 + (longlong)(int)uVar18 * 4);
              *puVar1 = uVar5;
              puVar1[1] = uVar5;
              puVar1[2] = uVar5;
              puVar1[3] = uVar5;
              uVar18 = uVar18 + 8;
              uVar9 = uVar9 - 8;
            } while (uVar9 != 0);
            uVar18 = uVar24;
            if (uVar12 != (uVar12 & 0xfffffff8)) goto LAB_2b1a6a711d0;
          }
          iVar11 = iVar11 + 1;
          iVar21 = iVar21 + 1;
        } while (iVar11 <= iVar14);
      }
    }
  }
  if (-2 < iVar7) {
    param_2 = param_2 + iVar10;
    iVar20 = 0;
    iVar21 = 3;
    iVar16 = 0;
    iVar22 = 1 - iVar10;
    iVar7 = iVar10 * -2;
    iVar11 = iVar10;
    iVar13 = iVar22;
    iVar14 = iVar7;
    do {
      FUN_2b1a6a6de10(uVar8 - iVar11,iVar11 + uVar8,param_2 + iVar20,uVar5);
      FUN_2b1a6a6de10(uVar8 - iVar11,iVar11 + uVar8,param_2 + iVar16,uVar5);
      if (-1 < iVar13) {
        FUN_2b1a6a6de10(uVar8 + iVar20,uVar8 + iVar16,param_2 - iVar11,uVar5);
        FUN_2b1a6a6de10(uVar8 + iVar20,uVar8 + iVar16,iVar11 + param_2,uVar5);
        iVar11 = iVar11 + -1;
        iVar13 = iVar13 + 2 + iVar14;
        iVar14 = iVar14 + 2;
      }
      iVar16 = iVar16 + 1;
      iVar13 = iVar13 + iVar21;
      iVar20 = iVar20 + -1;
      iVar21 = iVar21 + 2;
    } while (iVar16 <= iVar11);
    iVar14 = 0;
    iVar11 = 3;
    iVar13 = 0;
    do {
      FUN_2b1a6a6de10(uVar17 - iVar10,iVar10 + uVar17,param_2 + iVar14,uVar5);
      FUN_2b1a6a6de10(uVar17 - iVar10,iVar10 + uVar17,param_2 + iVar13,uVar5);
      if (-1 < iVar22) {
        FUN_2b1a6a6de10(uVar17 + iVar14,uVar17 + iVar13,param_2 - iVar10,uVar5);
        FUN_2b1a6a6de10(uVar17 + iVar14,uVar17 + iVar13,iVar10 + param_2,uVar5);
        iVar10 = iVar10 + -1;
        iVar22 = iVar22 + 2 + iVar7;
        iVar7 = iVar7 + 2;
      }
      iVar22 = iVar22 + iVar11;
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + -1;
      iVar11 = iVar11 + 2;
    } while (iVar13 <= iVar10);
  }
  return;
}



/* Address: 2b1a6a71490 */

void FUN_2b1a6a71490(undefined8 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,*param_1,0x2b1a17afe60);
  param_1[1] = 0x2b1a6a77de0;
  param_1[2] = 0;
  param_1[3] = 0;
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,*param_1,0x2b1a170ac50);
  param_1[1] = 0x2b1a6a77ee0;
  *(undefined1 *)((longlong)param_1 + 0x294) = 0;
  *(undefined8 *)((longlong)param_1 + 0x295) = 0;
  *(undefined8 *)((longlong)param_1 + 0x29d) = 10;
  *(undefined4 *)((longlong)param_1 + 0x2a5) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2ad) = 1;
  uVar1 = (*(code *)0x7ff63a0c73c0)(0x2b1a1776bc8,0x35);
  *(undefined4 *)((longlong)param_1 + 0x2a9) = uVar1;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  FUN_2b1a6a60000((longlong)param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  FUN_2b1a6a60000((longlong)param_1 + 0x84);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x12,0,0xb4);
  FUN_2b1a6a60000((longlong)param_1 + 0x144);
  (*(code *)0x7ff63a3fad20)(param_1 + 0x2a,0,0xb8);
  FUN_2b1a6a60000(param_1 + 0x41);
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
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,6);
  if (iVar2 != 0) {
    *(undefined4 *)((longlong)param_1 + 0x2ad) = 2;
  }
  iVar2 = (*(code *)0x7ff63a0f0fd0)(0x2b1a1776bc8,7);
  if (iVar2 != 0) {
    *(undefined4 *)((longlong)param_1 + 0x2ad) = 0;
  }
  return;
}



/* Address: 2b1a6a71710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_2b1a6a71710(longlong param_1,longlong param_2,uint param_3,undefined8 param_4,undefined8 param_5
               ,undefined8 param_6,undefined8 param_7)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uStack_a8;
  undefined4 uStack_a0;
  longlong lStack_98;
  undefined4 auStack_90 [20];
  
  if (_DAT_2b1a6dcd514 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    FUN_2b1a6a60000(param_1 + 0x34);
    lStack_98 = param_1 + 0x84;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    FUN_2b1a6a60000();
    (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
    FUN_2b1a6a60000(param_1 + 0x144);
    (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
    FUN_2b1a6a60000(param_1 + 0x208);
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
    if (param_3 < 2) {
      *(undefined4 *)(param_1 + 0x20) = 1;
      FUN_2b1a6a604e0(param_1 + 0x34,param_2,0,0x2b1a6ba3a88);
      *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
      *(undefined8 *)(param_1 + 0x40) = param_4;
      *(uint *)(param_1 + 0x70) = param_3;
      *(undefined8 *)(param_1 + 0x48) = param_5;
      *(undefined8 *)(param_1 + 0x58) = param_6;
      *(undefined8 *)(param_1 + 0x60) = param_7;
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_1 + 0x29d);
      uStack_a8 = 0;
      uStack_a0 = 0;
      lVar4 = 0x2b1a6dcd528;
      if (*(longlong *)(param_2 + 4) != 0) {
        lVar4 = param_2;
      }
      FUN_2b1a6a604e0(&uStack_a8,lVar4,0,0x2b1a6ba4618);
      cVar1 = (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&uStack_a8,0x47,auStack_90);
      uVar3 = 0;
      if (cVar1 != '\0') {
        uVar3 = auStack_90[0];
      }
      if ((ulonglong)*(uint *)(param_1 + 0x70) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a71a92 */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x70) * 8 + 0x2b1a6a77ac8))
                          (0x2b1a6a77ac8,uVar3);
        return uVar2;
      }
      *(undefined4 *)(param_1 + 0x110) = 0x2733;
      (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a79a98);
      FUN_2b1a6a60000(&uStack_a8);
    }
    else {
      *(undefined4 *)(param_1 + 0x110) = 0x271d;
      FUN_2b1a6a604e0(param_1 + 0x144,0x2b1a6a78a48,0,0x2b1a6ba3a78);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,0xd,2,0x590008,0x2b1a6a79b20,0x590008,0x2b1a6a789f8);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  return 0;
}



/* Address: 2b1a6a717e0 */

undefined8 FUN_2b1a6a717e0(undefined8 param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong unaff_RSI;
  undefined8 in_stack_00000040;
  undefined4 in_stack_00000048;
  longlong in_stack_00000050;
  undefined4 in_stack_00000058;
  undefined8 in_stack_00000110;
  undefined8 in_stack_00000118;
  undefined8 in_stack_00000120;
  
  *(undefined4 *)(unaff_RSI + 0x30) = 0;
  *(undefined8 *)(unaff_RSI + 0x28) = 0;
  *(undefined8 *)(unaff_RSI + 0x20) = 0;
  FUN_2b1a6a60000(unaff_RSI + 0x34);
  in_stack_00000050 = unaff_RSI + 0x84;
  *(undefined4 *)(unaff_RSI + 0x80) = 0;
  *(undefined8 *)(unaff_RSI + 0x78) = 0;
  *(undefined8 *)(unaff_RSI + 0x70) = 0;
  *(undefined8 *)(unaff_RSI + 0x68) = 0;
  *(undefined8 *)(unaff_RSI + 0x60) = 0;
  *(undefined8 *)(unaff_RSI + 0x58) = 0;
  *(undefined8 *)(unaff_RSI + 0x50) = 0;
  *(undefined8 *)(unaff_RSI + 0x48) = 0;
  *(undefined8 *)(unaff_RSI + 0x40) = 0;
  FUN_2b1a6a60000();
  (*(code *)0x7ff63a3fad20)(unaff_RSI + 0x90,0,0xb4);
  FUN_2b1a6a60000(unaff_RSI + 0x144);
  (*(code *)0x7ff63a3fad20)(unaff_RSI + 0x150,0,0xb8);
  FUN_2b1a6a60000(unaff_RSI + 0x208);
  uVar2 = in_stack_00000120;
  uVar1 = in_stack_00000118;
  uVar4 = in_stack_00000110;
  *(undefined8 *)(unaff_RSI + 0x28c) = 0;
  *(undefined8 *)(unaff_RSI + 0x284) = 0;
  *(undefined8 *)(unaff_RSI + 0x27c) = 0;
  *(undefined8 *)(unaff_RSI + 0x274) = 0;
  *(undefined8 *)(unaff_RSI + 0x26c) = 0;
  *(undefined8 *)(unaff_RSI + 0x264) = 0;
  *(undefined8 *)(unaff_RSI + 0x25c) = 0;
  *(undefined8 *)(unaff_RSI + 0x254) = 0;
  *(undefined8 *)(unaff_RSI + 0x24c) = 0;
  *(undefined8 *)(unaff_RSI + 0x244) = 0;
  *(undefined8 *)(unaff_RSI + 0x23c) = 0;
  *(undefined8 *)(unaff_RSI + 0x234) = 0;
  *(undefined8 *)(unaff_RSI + 0x22c) = 0;
  *(undefined8 *)(unaff_RSI + 0x224) = 0;
  *(undefined8 *)(unaff_RSI + 0x21c) = 0;
  *(undefined8 *)(unaff_RSI + 0x214) = 0;
  if (param_3 < 2) {
    *(undefined4 *)(unaff_RSI + 0x20) = 1;
    FUN_2b1a6a604e0(unaff_RSI + 0x34,param_2,0,0x2b1a6ba3a88);
    *(undefined8 *)(unaff_RSI + 0x24) = *(undefined8 *)(unaff_RSI + 0x295);
    *(undefined8 *)(unaff_RSI + 0x40) = param_4;
    *(uint *)(unaff_RSI + 0x70) = param_3;
    *(undefined8 *)(unaff_RSI + 0x48) = uVar4;
    *(undefined8 *)(unaff_RSI + 0x58) = uVar1;
    *(undefined8 *)(unaff_RSI + 0x60) = uVar2;
    *(undefined8 *)(unaff_RSI + 0x68) = *(undefined8 *)(unaff_RSI + 0x29d);
    in_stack_00000040 = 0;
    in_stack_00000048 = 0;
    lVar6 = 0x2b1a6dcd528;
    if (*(longlong *)(param_2 + 4) != 0) {
      lVar6 = param_2;
    }
    FUN_2b1a6a604e0(&stack0x00000040,lVar6,0,0x2b1a6ba4618);
    cVar3 = (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&stack0x00000040,0x47,&stack0x00000058);
    uVar5 = 0;
    if (cVar3 != '\0') {
      uVar5 = in_stack_00000058;
    }
    if ((ulonglong)*(uint *)(unaff_RSI + 0x70) < 8) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a71a92 */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (**(code **)((ulonglong)*(uint *)(unaff_RSI + 0x70) * 8 + 0x2b1a6a77ac8))
                        (0x2b1a6a77ac8,uVar5);
      return uVar4;
    }
    *(undefined4 *)(unaff_RSI + 0x110) = 0x2733;
    (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a79a98);
    FUN_2b1a6a60000(&stack0x00000040);
  }
  else {
    *(undefined4 *)(unaff_RSI + 0x110) = 0x271d;
    FUN_2b1a6a604e0(unaff_RSI + 0x144,0x2b1a6a78a48,0,0x2b1a6ba3a78);
  }
  return 0;
}



/* Address: 2b1a6a71bb0 */

ulonglong FUN_2b1a6a71bb0(longlong param_1,longlong param_2)

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
  
  uVar2 = (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,param_2,0x21);
  uVar4 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  if (uVar2 < 2) goto LAB_2b1a6a71f13;
  uVar3 = (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,param_2,0x32);
  if (uVar2 == 2) {
    if (*(int *)(param_1 + 0x20) == 5) goto LAB_2b1a6a71f13;
    if ((uVar3 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      goto LAB_2b1a6a71f13;
    }
    if ((uVar3 & 2) != 0) {
      *(undefined4 *)(param_1 + 0x2a5) = 1;
      *(undefined4 *)(param_1 + 0x74) = 1;
      goto LAB_2b1a6a71f13;
    }
LAB_2b1a6a71e93:
    *(undefined4 *)(param_1 + 0x110) = 0x272e;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x2a5);
    if (iVar1 == 2) {
LAB_2b1a6a71efd:
      *(undefined4 *)(param_1 + 0x74) = 2;
      goto LAB_2b1a6a71f13;
    }
    if (iVar1 == 1) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x2b1a6dcd528;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_2b1a6a604e0(&local_48,lVar5,0,0x2b1a6ba4608);
        (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a71d9b */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2b1a6a77b08))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a79a20);
        FUN_2b1a6a60000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2b1a6a71efd;
      }
      uVar3 = uVar3 & 2;
joined_r0x02b1a6a71e91:
      if (uVar3 != 0) {
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x2a5);
        goto LAB_2b1a6a71f13;
      }
      goto LAB_2b1a6a71e93;
    }
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x20) == 5) {
        local_48 = 0;
        local_40 = 0;
        lVar5 = 0x2b1a6dcd528;
        if (*(longlong *)(param_2 + 4) != 0) {
          lVar5 = param_2;
        }
        FUN_2b1a6a604e0(&local_48,lVar5,0,0x2b1a6ba4608);
        (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_48,0x31,local_38);
        if ((ulonglong)*(uint *)(param_1 + 0x78) < 4) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a71cf2 */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (**(code **)((ulonglong)*(uint *)(param_1 + 0x78) * 8 + 0x2b1a6a77b28))();
          return uVar4;
        }
        (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,2,1,0x590008,0x2b1a6a79a20);
        FUN_2b1a6a60000(&local_48);
        *(undefined4 *)(param_1 + 0x78) = 1;
        if (*(int *)(param_1 + 0x70) - 2U < 4) goto LAB_2b1a6a71efd;
      }
      uVar3 = uVar3 & 1;
      goto joined_r0x02b1a6a71e91;
    }
    *(undefined4 *)(param_1 + 0x110) = 0x271b;
  }
  uVar4 = 0;
LAB_2b1a6a71f13:
  return uVar4 & 0xffffffff;
}



/* Address: 2b1a6a71f30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a71f30(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 local_78;
  undefined8 local_74;
  
  local_78 = 0;
  local_74 = 0;
  if (_DAT_2b1a6dcd514 == 0) {
    cVar1 = (*(code *)0x7ff63a107ee0)(0x2b1a1776bc8);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      FUN_2b1a6a60000(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      FUN_2b1a6a60000(param_1 + 0x84);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x90,0,0xb4);
      FUN_2b1a6a60000(param_1 + 0x144);
      (*(code *)0x7ff63a3fad20)(param_1 + 0x150,0,0xb8);
      FUN_2b1a6a60000(param_1 + 0x208);
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
      (*(code *)0x7ff63a108010)(0x2b1a1776bc8,0);
      FUN_2b1a6a604e0(&local_78,0x2b1a6dcd53c,1,0x2b1a6ba3aa8);
      FUN_2b1a6a604e0(param_1 + 0x34,&local_78,0,0x2b1a6ba3ab8);
      *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x295);
      *(undefined8 *)(param_1 + 0x58) = param_3;
      *(undefined8 *)(param_1 + 0x60) = param_4;
      FUN_2b1a6a61590(param_1,param_1 + 0x20,param_1 + 0x110);
    }
  }
  else {
    (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,0xd,2,0x590008,0x2b1a6a79b20,0x590008,0x2b1a6a78aa0);
    *(undefined4 *)(param_1 + 0x110) = 0x272b;
  }
  FUN_2b1a6a60000(&local_78);
  return;
}



/* Address: 2b1a6a72230 */

void FUN_2b1a6a72230(undefined8 param_1,longlong param_2,int *param_3)

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
  lVar10 = 0x2b1a6dcd528;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar10 = param_2 + 0x14;
  }
  FUN_2b1a6a604e0(&local_60,lVar10,0,0x2b1a6ba42d8);
  (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_60,0x11,local_68);
  (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_60,0x21,local_68);
  uVar9 = *param_3 - 0x2714;
  if (uVar9 < 0x25) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a72367 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar9 * 8 + 0x2b1a6a77b48))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,*param_3,0x53,&local_88);
  FUN_2b1a6a604e0(&local_98,0x2b1a6a799a0,0);
  lVar10 = local_84;
  if (local_84 == 0) goto LAB_2b1a6a729cf;
  uVar9 = *(uint *)(local_84 + -4);
  uVar12 = (ulonglong)uVar9;
  if ((uVar12 == 0) && (local_94 != 0)) goto LAB_2b1a6a729cf;
  if (local_94 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_94 + -4);
  }
  cVar8 = FUN_2b1a6a60060(&local_98);
  if (cVar8 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1f0561000801f9);
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
      if (uVar11 == uVar12) goto LAB_2b1a6a72bc2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar10 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar12 != uVar11);
  }
LAB_2b1a6a72bc2:
  *(uint *)(local_94 + -4) = uVar9 + uVar14;
  *(undefined2 *)(local_94 + (ulonglong)(uVar9 + uVar14) * 2) = 0;
LAB_2b1a6a729cf:
  FUN_2b1a6a604e0(param_1,&local_98,0,0x2b1a6ba45d8);
  FUN_2b1a6a604e0(&local_50,param_1,0,0x2b1a6ba45e8);
  FUN_2b1a6a60000(&local_60);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_50,1,0x2b1a6ba45f8);
  FUN_2b1a6a60000(&local_50);
  FUN_2b1a6a60000(&local_88);
  FUN_2b1a6a60000(&local_98);
  FUN_2b1a6a60000(&local_78);
  return;
}



/* Address: 2b1a6a72a50 */

void FUN_2b1a6a72a50(void)

{
  longlong unaff_RDI;
  undefined8 in_stack_00000048;
  
  (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,*(undefined8 *)(unaff_RDI + 0x14),2);
  FUN_2b1a6a604e0(&stack0x00000060,0x2b1a6dcd53c,1,0x2b1a6ba43a8);
  (*(code *)0x7ff63a0e49f0)(0x2b1a1776bc8,0xd8,2,0x590008,0x2b1a6a79230);
  FUN_2b1a6a604e0(&stack0x00000050,0x2b1a6dcd53c,1,0x2b1a6ba43b8);
  FUN_2b1a6a604e0(in_stack_00000048,&stack0x00000050,0,0x2b1a6ba43c8);
  FUN_2b1a6a604e0(&stack0x00000098,in_stack_00000048,0,0x2b1a6ba45e8);
  FUN_2b1a6a60000(&stack0x00000088);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&stack0x00000098,1,0x2b1a6ba45f8);
  FUN_2b1a6a60000(&stack0x00000098);
  FUN_2b1a6a60000(&stack0x00000060);
  FUN_2b1a6a60000(&stack0x00000050);
  FUN_2b1a6a60000(&stack0x00000070);
  return;
}



/* Address: 2b1a6a72c10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2b1a6a72c10(undefined8 param_1,undefined8 param_2,int *param_3)

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
  FUN_2b1a6a604e0(param_2,0x2b1a6a77f40,0,0x2b1a6ba3cd8);
  local_98 = 0;
  local_94 = 0;
  piVar12 = (int *)0x2b1a6dcd528;
  if (*(longlong *)(param_3 + 6) != 0) {
    piVar12 = param_3 + 5;
  }
  FUN_2b1a6a604e0(&local_98,piVar12,0,0x2b1a6ba3ce8);
  (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_98,0x11,local_a0);
  (*(code *)0x7ff63a0f29d0)(0x2b1a1776bc8,&local_98,0x21,local_a0);
  uVar11 = *param_3 - 1;
  if (uVar11 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a72df0 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)uVar11 * 8 + 0x2b1a6a77c70))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,(longlong)*param_3,0x52,&local_108);
  FUN_2b1a6a604e0(&local_f8,0x2b1a6a790f0,0);
  lVar8 = local_104;
  if (local_104 == 0) goto LAB_2b1a6a736db;
  uVar11 = *(uint *)(local_104 + -4);
  uVar14 = (ulonglong)uVar11;
  if ((uVar14 == 0) && (local_f4 != 0)) goto LAB_2b1a6a736db;
  if (local_f4 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(local_f4 + -4);
  }
  cVar10 = FUN_2b1a6a60060(&local_f8);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x1e04cf000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0xf04a0000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0xf04a5000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x150470000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x150489000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x15043c000801f9);
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x150457000801f9);
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
      if (uVar13 == uVar14) goto LAB_2b1a6a749b2;
    }
    do {
      *(undefined2 *)(lVar1 + uVar13 * 2) = *(undefined2 *)(lVar8 + uVar13 * 2);
      uVar13 = uVar13 + 1;
    } while (uVar14 != uVar13);
  }
LAB_2b1a6a749b2:
  *(uint *)(local_f4 + -4) = uVar11 + uVar16;
  *(undefined2 *)(local_f4 + (ulonglong)(uVar11 + uVar16) * 2) = 0;
LAB_2b1a6a736db:
  uVar9 = local_e8;
  FUN_2b1a6a604e0(local_e8,&local_f8,0,0x2b1a6ba42a8);
  FUN_2b1a6a604e0(&local_68,uVar9,0,0x2b1a6ba42b8);
  FUN_2b1a6a60000(&local_98);
  FUN_2b1a6a60000(&local_e0);
  FUN_2b1a6a60000(&local_88);
  FUN_2b1a6a60000(&local_78);
  FUN_2b1a6a60000(&local_c0);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_68,1,0x2b1a6ba42c8);
  FUN_2b1a6a60000(&local_68);
  FUN_2b1a6a60000(&local_108);
  FUN_2b1a6a60000(&local_f8);
  FUN_2b1a6a60000(&local_d0);
  FUN_2b1a6a60000(&local_b0);
  return;
}



/* Address: 2b1a6a74cd0 */

void FUN_2b1a6a74cd0(undefined8 param_1,uint param_2)

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
                    /* WARNING: Could not emulate address calculation at 0x02b1a6a74d33 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((ulonglong)param_2 * 8 + 0x2b1a6a77ce0))();
    return;
  }
  (*(code *)0x7ff63a0ff6c0)(0x2b1a1776bc8,(ulonglong)param_2,0x53,&local_50);
  FUN_2b1a6a604e0(&local_60,0x2b1a6a78888,0);
  lVar9 = local_4c;
  if (local_4c == 0) goto LAB_2b1a6a74f2d;
  uVar4 = *(uint *)(local_4c + -4);
  uVar13 = (ulonglong)uVar4;
  if ((uVar13 == 0) && (local_5c != 0)) goto LAB_2b1a6a74f2d;
  if (local_5c == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_5c + -4);
  }
  cVar10 = FUN_2b1a6a60060(&local_60);
  if (cVar10 == '\0') {
    (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x2203c7000801f9);
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
      if (uVar11 == uVar13) goto LAB_2b1a6a74f22;
    }
    do {
      *(undefined2 *)(lVar1 + uVar11 * 2) = *(undefined2 *)(lVar9 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar13 != uVar11);
  }
LAB_2b1a6a74f22:
  *(uint *)(local_5c + -4) = uVar4 + uVar14;
  *(undefined2 *)(local_5c + (ulonglong)(uVar4 + uVar14) * 2) = 0;
LAB_2b1a6a74f2d:
  FUN_2b1a6a604e0(param_1,&local_60,0,0x2b1a6ba3c08);
  FUN_2b1a6a604e0(&local_40,param_1,0,0x2b1a6ba3c18);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_40,1,0x2b1a6ba3c28);
  FUN_2b1a6a60000(&local_40);
  FUN_2b1a6a60000(&local_50);
  FUN_2b1a6a60000(&local_60);
  return;
}



/* Address: 2b1a6a74fd0 */

void FUN_2b1a6a74fd0(undefined8 param_1,undefined8 param_2,double param_3,undefined4 param_4)

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
  (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,param_2,param_4);
  if ((param_3 != 0.0) || (NAN(param_3))) {
    FUN_2b1a6a604e0(&local_78,0x2b1a6dcd53c,1,0x2b1a6ba3c38);
    FUN_2b1a6a604e0(&local_88,&local_78,0,0x2b1a6ba3c48);
    (*(code *)0x7ff63a0fd7c0)(0x2b1a1776bc8,param_3,param_4);
    FUN_2b1a6a604e0(&local_78,0x2b1a6dcd53c,1,0x2b1a6ba3c58);
    FUN_2b1a6a604e0(&local_98,&local_78,0,0x2b1a6ba3c68);
    (*(code *)0x7ff63a0e49f0)
              (0x2b1a1776bc8,0xd8,3,0x590008,0x2b1a6a78950,0x590008,&local_88,0x590008,&local_98);
    uVar2 = 0x2b1a6ba3c88;
    uVar1 = 0x2b1a6ba3c78;
  }
  else {
    uVar2 = 0x2b1a6ba3ca8;
    uVar1 = 0x2b1a6ba3c98;
  }
  FUN_2b1a6a604e0(&local_78,0x2b1a6dcd53c,1,uVar1);
  FUN_2b1a6a604e0(param_1,&local_78,0,uVar2);
  FUN_2b1a6a604e0(&local_68,param_1,0,0x2b1a6ba3cb8);
  FUN_2b1a6a60000(&local_98);
  FUN_2b1a6a60000(&local_88);
  FUN_2b1a6a604e0(0x2b1a6dcd53c,&local_68,1,0x2b1a6ba3cc8);
  FUN_2b1a6a60000(&local_68);
  FUN_2b1a6a60000(&local_78);
  return;
}



/* Address: 2b1a6a75210 */

void FUN_2b1a6a75210(undefined8 *param_1)

{
  FUN_2b1a6a60000(param_1 + 0x41);
  FUN_2b1a6a60000((longlong)param_1 + 0x144);
  FUN_2b1a6a60000((longlong)param_1 + 0x84);
  FUN_2b1a6a60000((longlong)param_1 + 0x34);
  (*(code *)0x7ff63a0e6470)(0x2b1a1776bc8,*param_1,0x2b1a17afe60);
  param_1[1] = 0x2b1a6a77de0;
  (*(code *)0x7ff63a0e62f0)(0x2b1a1776bc8,*param_1);
  return;
}



/* Address: 2b1a6a752a0 */

ulonglong FUN_2b1a6a752a0(undefined8 param_1)

{
  undefined8 unaff_RSI;
  ulonglong uVar1;
  uint local_70;
  int local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined8 local_58;
  uint local_50 [4];
  uint local_40;
  uint local_3c;
  undefined8 local_38;
  uint local_30 [4];
  uint local_20;
  uint local_1c;
  undefined8 local_18;
  undefined7 uVar2;
  
  (*(code *)0x7ff63a101f60)(0x2b1a1776bc8,param_1,&local_70);
  if (0xfffffff7 < local_6c - 0xbU) {
    uVar2 = (undefined7)((ulonglong)unaff_RSI >> 8);
    uVar1 = CONCAT71(uVar2,1);
    if (local_6c - 4U < 6) goto LAB_2b1a6a752e2;
    if (local_6c == 10) {
      local_50[0] = local_70;
      local_50[1] = 10;
      local_50[2] = 0x1f;
      local_50[3] = local_64;
      local_40 = local_60;
      local_3c = local_5c;
      local_38 = local_58;
      (*(code *)0x7ff63a101f60)
                (0x2b1a1776bc8,
                 (ulonglong)local_60 * 0x3c + (ulonglong)local_64 * 0xe10 + (ulonglong)local_5c +
                 (ulonglong)
                 ((((local_70 >> 2) + local_70 * 0x16d) - local_70 / 100) + -0xaf978 +
                 local_70 / 400) * 0x15180,local_50);
      if (local_68 < 0x1f - (int)local_38) goto LAB_2b1a6a752e2;
      if (local_68 <= 0x1f - (int)local_38) {
        uVar1 = CONCAT71(uVar2,(int)local_64 < 1);
        goto LAB_2b1a6a752e2;
      }
    }
    else if (local_6c == 3) {
      local_30[0] = local_70;
      local_30[1] = 3;
      local_30[2] = 0x1f;
      local_30[3] = local_64;
      local_20 = local_60;
      local_1c = local_5c;
      local_18 = local_58;
      (*(code *)0x7ff63a101f60)
                (0x2b1a1776bc8,
                 (ulonglong)local_60 * 0x3c + (ulonglong)local_64 * 0xe10 + (ulonglong)local_5c +
                 (ulonglong)
                 ((((local_70 >> 2) + local_70 * 0x16d) - local_70 / 100) + -0xafa4e +
                 local_70 / 400) * 0x15180,local_30);
      if (0x1f - (int)local_18 <= local_68) {
        if (local_68 <= 0x1f - (int)local_18) {
          uVar1 = CONCAT71(uVar2,0 < (int)local_64);
        }
        goto LAB_2b1a6a752e2;
      }
    }
  }
  uVar1 = 0;
LAB_2b1a6a752e2:
  return uVar1 & 0xffffffff;
}



/* Address: 2b1a6a75480 */

undefined4 FUN_2b1a6a75480(void)

{
  undefined1 local_20 [16];
  undefined4 local_10;
  
  (*(code *)0x7ff63a101c40)(0x2b1a1776bc8,local_20);
  return local_10;
}



/* Address: 2b1a6a754b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_2b1a6a754b0(int param_1,double param_2,double param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  byte bVar7;
  longlong *plVar8;
  byte bVar9;
  uint7 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  bool bVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined4 local_158;
  undefined8 local_154;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined6 uStack_130;
  undefined2 uStack_12a;
  undefined4 local_128;
  undefined2 local_124;
  
  local_158 = 0;
  local_154 = 0;
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,4);
  dVar14 = _DAT_2b1a6dcd548;
  (*(code *)0x7ff63a0f2890)(0x2b1a1776bc8,0x2b1a6a77f20,1);
  dVar16 = _DAT_2b1a6dcd548;
  iVar2 = (*(code *)0x7ff63a0f2970)(0x2b1a1776bc8,0x2b1a6a77f20,0x1f);
  uVar10 = (uint7)(uint3)((uint)param_1 >> 8);
  if (param_1 == 0) {
    bVar9 = 1;
    bVar7 = 1;
    if ((param_2 != 0.0) || (NAN(param_2))) {
      bVar7 = 1;
      dVar14 = (double)iVar2 * _DAT_2b1a6dcd518;
      if (dVar16 - param_2 <= dVar14) {
        uVar3 = 1;
        uVar5 = 9;
        puVar6 = (undefined8 *)0x0;
        do {
          if (uVar5 < uVar3) break;
          uVar11 = uVar3 + uVar5 >> 1;
          lVar1 = *(longlong *)(uVar11 * 0x10 + 0x2b1a6ba4d10);
          if (lVar1 == 0) {
            uVar12 = uVar11;
            if (uVar3 + uVar5 < 4) goto LAB_2b1a6a759c6;
            bVar13 = uVar11 != 1;
            plVar8 = (longlong *)(uVar11 * 0x10 + 0x2b1a6ba4d00);
            goto LAB_2b1a6a759b0;
          }
          uVar12 = uVar11 - 1;
          if (lVar1 < 1) {
            uVar3 = uVar11 + 1;
            uVar12 = uVar5;
          }
          uVar5 = uVar12;
        } while (lVar1 != 0);
        goto LAB_2b1a6a759d3;
      }
    }
    goto LAB_2b1a6a75ad7;
  }
  bVar9 = 1;
  bVar7 = 1;
  if ((param_2 != 0.0) || (NAN(param_2))) {
    bVar7 = 1;
    dVar16 = _DAT_2b1a6dcd518 * (double)iVar2;
    if (param_2 - dVar14 <= dVar16) {
      uVar3 = 1;
      uVar5 = 9;
      puVar6 = (undefined8 *)0x0;
      do {
        if (uVar5 < uVar3) break;
        uVar11 = uVar3 + uVar5 >> 1;
        lVar1 = *(longlong *)(uVar11 * 0x10 + 0x2b1a6ba51f0);
        if (lVar1 == 1) {
          uVar12 = uVar11;
          if (uVar3 + uVar5 < 4) goto LAB_2b1a6a75666;
          bVar13 = uVar11 != 1;
          plVar8 = (longlong *)(uVar11 * 0x10 + 0x2b1a6ba51e0);
          goto LAB_2b1a6a75650;
        }
        uVar12 = uVar11 - 1;
        if (lVar1 < 2) {
          uVar3 = uVar11 + 1;
          uVar12 = uVar5;
        }
        uVar5 = uVar12;
      } while (lVar1 != 1);
      goto LAB_2b1a6a75674;
    }
  }
  goto LAB_2b1a6a75778;
  while( true ) {
    uVar11 = uVar11 - 1;
    plVar8 = plVar8 + -2;
    uVar12 = (ulonglong)bVar13;
    if (uVar11 < 2) break;
LAB_2b1a6a759b0:
    uVar12 = uVar11;
    if (*plVar8 != 0) break;
  }
LAB_2b1a6a759c6:
  puVar6 = *(undefined8 **)(uVar12 * 0x10 + 0x2b1a6ba4d18);
LAB_2b1a6a759d3:
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = &local_148;
    _DAT_2b1a6dcd510 = 0xfa3;
    local_138 = _DAT_2b1a6ba4b50;
    local_148 = _DAT_2b1a6ba4b40;
    uStack_140 = uRam000002b1a6ba4b48;
    uStack_130 = (undefined6)uRam000002b1a6ba4b58;
    _uStack_130 = CONCAT26(0x3a,uStack_130);
    local_128 = 0x30003a;
    local_124 = 0;
  }
  FUN_2b1a6a601e0(&local_158,puVar6,0xffffffff);
  (*(code *)0x7ff63a0e49f0)
            (0x2b1a1776bc8,0xd,6,0x590008,0x2b1a6a7a0b0,0x590008,&local_158,0x580007,param_2,
             0x580007,dVar16 - dVar14,0x580007,dVar16,0x520004,iVar2);
  bVar7 = 0;
LAB_2b1a6a75ad7:
  if (((param_3 == 0.0) && (!NAN(param_3))) || ((double)iVar2 * _DAT_2b1a6dcd518 < param_3 - dVar16)
     ) goto LAB_2b1a6a75cb6;
  dVar15 = (double)iVar2 * _DAT_2b1a6dcd518 + dVar16;
  uVar3 = 1;
  uVar5 = 9;
  puVar6 = (undefined8 *)0x0;
  do {
    if (uVar5 < uVar3) break;
    uVar11 = uVar3 + uVar5 >> 1;
    lVar1 = *(longlong *)(uVar11 * 0x10 + 0x2b1a6ba4f80);
    if (lVar1 == 0) {
      uVar12 = uVar11;
      if (uVar3 + uVar5 < 4) goto LAB_2b1a6a75ba6;
      bVar13 = uVar11 != 1;
      plVar8 = (longlong *)(uVar11 * 0x10 + 0x2b1a6ba4f70);
      goto LAB_2b1a6a75b90;
    }
    uVar12 = uVar11 - 1;
    if (lVar1 < 1) {
      uVar3 = uVar11 + 1;
      uVar12 = uVar5;
    }
    uVar5 = uVar12;
  } while (lVar1 != 0);
  goto LAB_2b1a6a75bb3;
  while( true ) {
    uVar11 = uVar11 - 1;
    plVar8 = plVar8 + -2;
    uVar12 = (ulonglong)bVar13;
    if (uVar11 < 2) break;
LAB_2b1a6a75b90:
    uVar12 = uVar11;
    if (*plVar8 != 0) break;
  }
LAB_2b1a6a75ba6:
  puVar6 = *(undefined8 **)(uVar12 * 0x10 + 0x2b1a6ba4f88);
LAB_2b1a6a75bb3:
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = &local_148;
    _DAT_2b1a6dcd510 = 0xfa3;
    local_138 = _DAT_2b1a6ba4dc0;
    local_148 = _DAT_2b1a6ba4db0;
    uStack_140 = uRam000002b1a6ba4db8;
    uStack_130 = (undefined6)uRam000002b1a6ba4dc8;
    _uStack_130 = CONCAT26(0x3a,uStack_130);
    local_128 = 0x30003a;
    local_124 = 0;
  }
  FUN_2b1a6a601e0(&local_158,puVar6,0xffffffff);
  uVar4 = 0x2b1a6a7a1a0;
  goto LAB_2b1a6a75c60;
  while( true ) {
    uVar11 = uVar11 - 1;
    plVar8 = plVar8 + -2;
    uVar12 = (ulonglong)bVar13;
    if (uVar11 < 2) break;
LAB_2b1a6a75820:
    uVar12 = uVar11;
    if (*plVar8 != 1) break;
  }
LAB_2b1a6a75836:
  puVar6 = *(undefined8 **)(uVar12 * 0x10 + 0x2b1a6ba5468);
  goto LAB_2b1a6a75844;
  while( true ) {
    uVar11 = uVar11 - 1;
    plVar8 = plVar8 + -2;
    uVar12 = (ulonglong)bVar13;
    if (uVar11 < 2) break;
LAB_2b1a6a75650:
    uVar12 = uVar11;
    if (*plVar8 != 1) break;
  }
LAB_2b1a6a75666:
  puVar6 = *(undefined8 **)(uVar12 * 0x10 + 0x2b1a6ba51f8);
LAB_2b1a6a75674:
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = &local_148;
    _DAT_2b1a6dcd510 = 0xfa3;
    local_138 = _DAT_2b1a6ba5030;
    local_148 = _DAT_2b1a6ba5020;
    uStack_140 = uRam000002b1a6ba5028;
    uStack_130 = (undefined6)uRam000002b1a6ba5038;
    _uStack_130 = CONCAT26(0x3a,uStack_130);
    local_128 = 0x31003a;
    local_124 = 0;
  }
  FUN_2b1a6a601e0(&local_158,puVar6,0xffffffff);
  (*(code *)0x7ff63a0e49f0)
            (0x2b1a1776bc8,0xd,6,0x590008,0x2b1a6a7a288,0x590008,&local_158,0x580007,param_2,
             0x580007,dVar16 + dVar14,0x580007,dVar14,0x520004,iVar2);
  bVar7 = 0;
LAB_2b1a6a75778:
  if (((param_3 != 0.0) || (NAN(param_3))) &&
     (dVar15 = (double)iVar2 * _DAT_2b1a6dcd518, dVar14 - param_3 <= dVar15)) {
    uVar3 = 1;
    uVar5 = 9;
    puVar6 = (undefined8 *)0x0;
    dVar15 = dVar14 - dVar15;
    do {
      if (uVar5 < uVar3) break;
      uVar11 = uVar3 + uVar5 >> 1;
      lVar1 = *(longlong *)(uVar11 * 0x10 + 0x2b1a6ba5460);
      if (lVar1 == 1) {
        uVar12 = uVar11;
        if (uVar3 + uVar5 < 4) goto LAB_2b1a6a75836;
        bVar13 = uVar11 != 1;
        plVar8 = (longlong *)(uVar11 * 0x10 + 0x2b1a6ba5450);
        goto LAB_2b1a6a75820;
      }
      uVar12 = uVar11 - 1;
      if (lVar1 < 2) {
        uVar3 = uVar11 + 1;
        uVar12 = uVar5;
      }
      uVar5 = uVar12;
    } while (lVar1 != 1);
LAB_2b1a6a75844:
    if (puVar6 == (undefined8 *)0x0) {
      puVar6 = &local_148;
      _DAT_2b1a6dcd510 = 0xfa3;
      local_138 = _DAT_2b1a6ba52a0;
      local_148 = _DAT_2b1a6ba5290;
      uStack_140 = uRam000002b1a6ba5298;
      uStack_130 = (undefined6)uRam000002b1a6ba52a8;
      _uStack_130 = CONCAT26(0x3a,uStack_130);
      local_128 = 0x31003a;
      local_124 = 0;
    }
    FUN_2b1a6a601e0(&local_158,puVar6,0xffffffff);
    uVar4 = 0x2b1a6a7a378;
    dVar16 = dVar14;
LAB_2b1a6a75c60:
    (*(code *)0x7ff63a0e49f0)
              (0x2b1a1776bc8,0xd,6,0x590008,uVar4,0x590008,&local_158,0x580007,param_3,0x580007,
               dVar15,0x580007,dVar16,0x520004,iVar2);
    bVar9 = 0;
    uVar10 = 0;
  }
LAB_2b1a6a75cb6:
  FUN_2b1a6a60000(&local_158);
  return CONCAT71(uVar10,bVar9 & bVar7);
}



/* Address: 2b1a6a75d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_2b1a6a75d20(undefined8 param_1,undefined8 param_2,uint param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  double dVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined8 uVar14;
  double *pdVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  undefined8 in_stack_fffffffffffffe38;
  undefined4 uVar20;
  undefined4 local_180;
  undefined8 local_17c;
  double local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined6 uStack_150;
  undefined2 uStack_14a;
  undefined2 local_148;
  ushort local_146;
  undefined2 local_144;
  undefined1 local_a8 [8];
  undefined8 auStack_a0 [13];
  
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  local_180 = 0;
  local_17c = 0;
  (*(code *)0x7ff63a0f2c10)(0x2b1a1776bc8,param_1,local_a8);
  uVar8 = auStack_a0[param_3 != 1];
  (*(code *)0x7ff63a0c7370)(0x2b1a1776bc8,0x2a);
  dVar3 = _DAT_2b1a6dcd548;
  pdVar15 = &local_170;
  cVar4 = (*(code *)0x7ff63a108d40)(0x2b1a1776bc8,param_3,param_1,param_2,uVar8,pdVar15);
  uVar16 = (undefined4)((ulonglong)pdVar15 >> 0x20);
  if (cVar4 == '\0') {
    uVar19 = 0x520004;
    uVar8 = 4;
    uVar18 = 0x2b1a6a79e40;
    puVar17 = (undefined4 *)0x2b1a6a79e08;
    uVar14 = 0x2b1a6a79dc0;
    param_2 = CONCAT44(uVar20,_DAT_2b1a6dcd510);
  }
  else {
    uVar9 = 0x2b1a1776b01;
    if (local_170 <= dVar3) goto LAB_2b1a6a76084;
    if ((local_170 == 0.0) && (!NAN(local_170))) {
      (*(code *)0x7ff639cc59a0)(0x2b1a1776bc8,0x170788000001f7);
      pcVar2 = (code *)swi(3);
      uVar9 = (*pcVar2)();
      return uVar9;
    }
    uVar5 = (ulonglong)param_3;
    uVar7 = 1;
    uVar9 = 9;
    puVar6 = (undefined8 *)0x0;
    do {
      while( true ) {
        if (uVar9 < uVar7) goto LAB_2b1a6a75ec3;
        uVar11 = uVar7 + uVar9 >> 1;
        uVar1 = *(ulonglong *)(uVar11 * 0x10 + 0x2b1a6ba4a00);
        if (uVar1 != uVar5) break;
        uVar12 = uVar11;
        if (3 < uVar7 + uVar9) {
          bVar13 = uVar11 != 1;
          puVar10 = (ulonglong *)(uVar11 * 0x10 + 0x2b1a6ba49f0);
          do {
            uVar12 = uVar11;
            if (*puVar10 != uVar5) break;
            uVar11 = uVar11 - 1;
            puVar10 = puVar10 + -2;
            uVar12 = (ulonglong)bVar13;
          } while (1 < uVar11);
        }
        puVar6 = *(undefined8 **)(uVar12 * 0x10 + 0x2b1a6ba4a08);
        if (uVar1 == uVar5) goto LAB_2b1a6a75ec3;
      }
      uVar12 = uVar11 - 1;
      if ((longlong)uVar1 <= (longlong)uVar5) {
        uVar7 = uVar11 + 1;
        uVar12 = uVar9;
      }
      uVar9 = uVar12;
    } while (uVar1 != uVar5);
LAB_2b1a6a75ec3:
    if (puVar6 == (undefined8 *)0x0) {
      _DAT_2b1a6dcd510 = 0xfa3;
      local_158 = _DAT_2b1a6ba4840;
      puVar6 = &local_168;
      local_168 = _DAT_2b1a6ba4830;
      uStack_160 = uRam000002b1a6ba4838;
      _uStack_150 = CONCAT26(0x3a,(int6)uRam000002b1a6ba4848);
      local_148 = 0x3a;
      local_146 = (short)param_3 + (short)(param_3 / 10) * -10 | 0x30;
      local_144 = 0;
    }
    puVar17 = &local_180;
    FUN_2b1a6a601e0(puVar17,puVar6,0xffffffff);
    uVar8 = 8;
    uVar19 = 0x580007;
    uVar14 = 0x2b1a6a79e88;
    uVar18 = 0x2b1a6a78188;
  }
  (*(code *)0x7ff63a0e49f0)
            (0x2b1a1776bc8,2,uVar8,0x590008,uVar14,CONCAT44(uVar16,0x590008),puVar17,0x590008,uVar18
             ,uVar19,param_2);
  uVar9 = 0;
LAB_2b1a6a76084:
  FUN_2b1a6a60000(&local_180);
  return uVar9 & 0xffffffff;
}


