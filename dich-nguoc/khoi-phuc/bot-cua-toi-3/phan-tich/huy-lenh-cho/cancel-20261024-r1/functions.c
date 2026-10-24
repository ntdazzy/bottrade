// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:22666
/* Address: 17156282450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined1 FUN_17156282450(ulonglong param_1)

{
  double dVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  double dVar7;
  undefined1 auVar8 [16];
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined1 local_88 [8];
  double local_80;
  double local_78;
  
  local_98 = 0;
  local_94 = 0;
  bVar2 = MT5_OrderSelect((void *)0x171514ca538,param_1);
  if (bVar2) {
    local_a8 = 0;
    local_a4 = 0;
    MT5_OrderGetString((void *)0x171514ca538,0);
    FUN_171562505c0(&local_98,&DAT_17156426e3c,1,&PTR_DAT_171562b9ac0);
    FUN_171562505c0(&local_a8,&local_98,0,&PTR_DAT_171562b9ad0);
    MT5_SymbolInfoDouble((void *)0x171514ca538,&local_a8,0x10);
    dVar1 = DAT_17156426e48;
    if ((0.0 < DAT_17156426e48) &&
       (bVar2 = MT5_SymbolInfoTick((void *)0x171514ca538,&local_a8,local_88), bVar2)) {
      lVar5 = MT5_SymbolInfoInteger((void *)0x171514ca538,&local_a8,0x20);
      uVar6 = -(ulonglong)(0.0 < dVar1 * (double)lVar5);
      dVar1 = (double)(~uVar6 & (ulonglong)(local_78 - local_80) |
                      (ulonglong)(dVar1 * (double)lVar5) & uVar6);
      if (0.0 < dVar1) {
        MT5_OrderGetDouble((void *)0x171514ca538,9);
        dVar7 = DAT_17156426e48;
        uVar9 = SUB84(DAT_17156426e48,0);
        uVar10 = (undefined4)((ulonglong)DAT_17156426e48 >> 0x20);
        lVar5 = MT5_OrderGetInteger((void *)0x171514ca538,4);
        uVar4 = (int)lVar5 - 2;
        if (uVar4 < 5 || (int)lVar5 == 7) {
          switch((&switchD_17156282614::switchdataD_171562a8438)[uVar4]) {
          case (undefined *)0x17156282617:
            dVar7 = local_78;
            break;
          case (undefined *)0x17156282a3c:
            uVar9 = SUB84(local_80,0);
            uVar10 = (undefined4)((ulonglong)local_80 >> 0x20);
            break;
          case (undefined *)0x17156282a48:
            uVar9 = SUB84(local_78,0);
            uVar10 = (undefined4)((ulonglong)local_78 >> 0x20);
            break;
          case (undefined *)0x17156282a54:
            dVar7 = local_80;
          }
          FUN_17156250000(&local_a8);
          FUN_17156250000(&local_98);
          if ((double)CONCAT44(uVar10,uVar9) - dVar7 <= dVar1) {
            return 0;
          }
          goto LAB_1715628264d;
        }
      }
    }
    FUN_17156250000(&local_a8);
    FUN_17156250000(&local_98);
  }
  else {
    FUN_17156250000(&local_98);
  }
LAB_1715628264d:
  if (DAT_17156426e14 == 0) {
    auVar8 = ZEXT816(0);
    DAT_171562c44f0 = 0;
    DAT_171562c44f4 = auVar8._4_8_;
    DAT_171562c44fc._0_4_ = 0;
    DAT_171562c44fc._4_4_ = 0;
    FUN_17156250000(&DAT_171562c4504);
    DAT_171562c454c._4_4_ = 0;
    _DAT_171562c4510 = auVar8;
    _DAT_171562c4520 = auVar8;
    _DAT_171562c4530 = auVar8;
    _DAT_171562c4540 = auVar8;
    FUN_17156250000(&DAT_171562c4554);
    DAT_171562c4610 = 0;
    _DAT_171562c4560 = auVar8;
    _DAT_171562c4570 = auVar8;
    _DAT_171562c4580 = auVar8;
    _DAT_171562c4590 = auVar8;
    _DAT_171562c45a0 = auVar8;
    _DAT_171562c45b0 = auVar8;
    _DAT_171562c45c0 = auVar8;
    _DAT_171562c45d0 = auVar8;
    _DAT_171562c45e0 = auVar8;
    _DAT_171562c45f0 = auVar8;
    _DAT_171562c4600 = auVar8;
    FUN_17156250000(&DAT_171562c4614);
    DAT_171562c46d0 = 0;
    _DAT_171562c4620 = auVar8;
    _DAT_171562c4630 = auVar8;
    _DAT_171562c4640 = auVar8;
    _DAT_171562c4650 = auVar8;
    _DAT_171562c4660 = auVar8;
    _DAT_171562c4670 = auVar8;
    _DAT_171562c4680 = auVar8;
    _DAT_171562c4690 = auVar8;
    _DAT_171562c46a0 = auVar8;
    _DAT_171562c46b0 = auVar8;
    _DAT_171562c46c0 = auVar8;
    FUN_17156250000(&DAT_171562c46d8);
    DAT_171562c4754 = 0;
    DAT_171562c474c = 0;
    DAT_171562c475c = 0;
    DAT_171562c4744 = 0;
    DAT_171562c473c = 0;
    DAT_171562c4734 = 0;
    DAT_171562c472c = 0;
    DAT_171562c4724 = 0;
    DAT_171562c471c = 0;
    DAT_171562c4714 = 0;
    DAT_171562c470c = 0;
    DAT_171562c4704 = 0;
    DAT_171562c46fc = 0;
    DAT_171562c46f4 = 0;
    DAT_171562c46ec = 0;
    DAT_171562c46e4 = 0;
    DAT_171562c44f0 = 8;
    DAT_171562c44f4 = DAT_171562c4765;
    DAT_171562c44fc._0_4_ = (undefined4)param_1;
    DAT_171562c44fc._4_4_ = (undefined4)(param_1 >> 0x20);
    uVar3 = FUN_17156250950(&DAT_171562c44d0,&DAT_171562c44f0,&DAT_171562c45e0);
  }
  else {
    MT5_Dispatch((void *)0x171514ca538,0xd,2,0x590008);
    DAT_171562c45e0 = 0x272b;
    uVar3 = 0;
  }
  return uVar3;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:26616
/* Address: 1715628da90 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_1715628da90(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int arg_1;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_70;
  longlong local_6c;
  ulonglong local_60;
  
  local_70 = 0;
  local_6c = 0;
  arg_1 = MT5_OrdersTotal((void *)0x171514ca538);
  if (-1 < arg_1) {
    uVar10 = 0;
    uVar11 = 0;
    local_60 = 0;
    do {
      DAT_171562c4838 = MT5_OrderGetTicket((void *)0x171514ca538,arg_1);
      if ((DAT_171562c4838 != 0) &&
         (lVar7 = MT5_OrderGetInteger((void *)0x171514ca538,0xf), lVar7 == DAT_171562bd564)) {
        MT5_OrderGetString((void *)0x171514ca538,0);
        FUN_171562505c0(&local_70,&DAT_17156426e3c,1,&PTR_DAT_171562b8d30);
        if (local_6c == DAT_171562c495c) {
LAB_1715628dc28:
          lVar7 = MT5_OrderGetInteger((void *)0x171514ca538,4);
          if ((lVar7 == 4) &&
             (MT5_OrderGetDouble((void *)0x171514ca538,9),
             (double)CONCAT44(uVar11,uVar10) <= DAT_17156426e48 &&
             DAT_17156426e48 != (double)CONCAT44(uVar11,uVar10))) {
            local_60 = DAT_171562c4838;
            MT5_OrderGetDouble((void *)0x171514ca538,9);
            uVar10 = SUB84(DAT_17156426e48,0);
            uVar11 = (undefined4)((ulonglong)DAT_17156426e48 >> 0x20);
          }
        }
        else if ((local_6c != 0) && (DAT_171562c495c != 0)) {
          uVar3 = *(uint *)(local_6c + -4);
          uVar4 = *(uint *)(DAT_171562c495c + -4);
          uVar5 = uVar4;
          if (uVar3 < uVar4) {
            uVar5 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar5 != 0) {
            uVar9 = 1;
            do {
              uVar1 = *(ushort *)(local_6c + -2 + uVar9 * 2);
              uVar2 = *(ushort *)(DAT_171562c495c + -2 + uVar9 * 2);
              if (uVar5 <= uVar9) break;
              uVar9 = uVar9 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_1715628dc28;
        }
      }
      uVar9 = local_60;
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
    if (local_60 != 0) {
      FUN_17156282450(local_60);
      lVar7 = -0x640;
      do {
        if ((*(double *)(&DAT_171562c3450 + lVar7) == (double)(longlong)uVar9) &&
           (!NAN(*(double *)(&DAT_171562c3450 + lVar7)) && !NAN((double)(longlong)uVar9))) {
          *(undefined8 *)(&DAT_171562c3450 + lVar7) = 0;
          *(undefined8 *)((longlong)&DAT_171562c3458 + lVar7) = 0;
          break;
        }
        lVar7 = lVar7 + 0x10;
      } while (lVar7 != 0);
      MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
    }
  }
  FUN_17156250000(&local_70);
  return;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:26713
/* Address: 1715628dd60 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_1715628dd60(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int arg_1;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_70;
  longlong local_6c;
  ulonglong local_60;
  
  local_70 = 0;
  local_6c = 0;
  arg_1 = MT5_OrdersTotal((void *)0x171514ca538);
  if (-1 < arg_1) {
    uVar10 = (undefined4)DAT_171562a84c8;
    uVar11 = (undefined4)((ulonglong)DAT_171562a84c8 >> 0x20);
    local_60 = 0;
    do {
      DAT_171562c4838 = MT5_OrderGetTicket((void *)0x171514ca538,arg_1);
      if ((DAT_171562c4838 != 0) &&
         (lVar7 = MT5_OrderGetInteger((void *)0x171514ca538,0xf), lVar7 == DAT_171562bd564)) {
        MT5_OrderGetString((void *)0x171514ca538,0);
        FUN_171562505c0(&local_70,&DAT_17156426e3c,1,&PTR_DAT_171562b8d40);
        if (local_6c == DAT_171562c495c) {
LAB_1715628df08:
          lVar7 = MT5_OrderGetInteger((void *)0x171514ca538,4);
          if ((lVar7 == 5) &&
             (MT5_OrderGetDouble((void *)0x171514ca538,9),
             DAT_17156426e48 <= (double)CONCAT44(uVar11,uVar10) &&
             (double)CONCAT44(uVar11,uVar10) != DAT_17156426e48)) {
            local_60 = DAT_171562c4838;
            MT5_OrderGetDouble((void *)0x171514ca538,9);
            uVar10 = SUB84(DAT_17156426e48,0);
            uVar11 = (undefined4)((ulonglong)DAT_17156426e48 >> 0x20);
          }
        }
        else if ((local_6c != 0) && (DAT_171562c495c != 0)) {
          uVar3 = *(uint *)(local_6c + -4);
          uVar4 = *(uint *)(DAT_171562c495c + -4);
          uVar5 = uVar4;
          if (uVar3 < uVar4) {
            uVar5 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar5 != 0) {
            uVar9 = 1;
            do {
              uVar1 = *(ushort *)(local_6c + -2 + uVar9 * 2);
              uVar2 = *(ushort *)(DAT_171562c495c + -2 + uVar9 * 2);
              if (uVar5 <= uVar9) break;
              uVar9 = uVar9 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_1715628df08;
        }
      }
      uVar9 = local_60;
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
    if (local_60 != 0) {
      FUN_17156282450(local_60);
      lVar7 = -0x640;
      do {
        if ((*(double *)(&DAT_171562c3450 + lVar7) == (double)(longlong)uVar9) &&
           (!NAN(*(double *)(&DAT_171562c3450 + lVar7)) && !NAN((double)(longlong)uVar9))) {
          *(undefined8 *)(&DAT_171562c3450 + lVar7) = 0;
          *(undefined8 *)((longlong)&DAT_171562c3458 + lVar7) = 0;
          break;
        }
        lVar7 = lVar7 + 0x10;
      } while (lVar7 != 0);
      MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
    }
  }
  FUN_17156250000(&local_70);
  return;
}



