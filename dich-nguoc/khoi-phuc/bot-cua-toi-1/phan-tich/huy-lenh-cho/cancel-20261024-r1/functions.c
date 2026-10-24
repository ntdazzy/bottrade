// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:22529
/* Address: 23e5aa44150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_23e5aa44150(ulonglong param_1)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  double dVar6;
  undefined1 auVar7 [16];
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  undefined8 local_94;
  undefined1 local_88 [8];
  double local_80;
  double local_78;
  
  local_98 = 0;
  local_94 = 0;
  bVar2 = MT5_OrderSelect((void *)0x23e575eae78,param_1);
  if (bVar2) {
    local_a8 = 0;
    local_a4 = 0;
    MT5_OrderGetString((void *)0x23e575eae78,0);
    FUN_23e5aa105c0(&local_98,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6f6b0);
    FUN_23e5aa105c0(&local_a8,&local_98,0,&PTR_DAT_23e5aa6f6c0);
    MT5_SymbolInfoDouble((void *)0x23e575eae78,&local_a8,0x10);
    dVar1 = DAT_23e5aa7a448;
    if ((0.0 < DAT_23e5aa7a448) &&
       (bVar2 = MT5_SymbolInfoTick((void *)0x23e575eae78,&local_a8,local_88), bVar2)) {
      lVar4 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&local_a8,0x20);
      uVar5 = -(ulonglong)(0.0 < dVar1 * (double)lVar4);
      dVar1 = (double)(~uVar5 & (ulonglong)(local_78 - local_80) |
                      (ulonglong)(dVar1 * (double)lVar4) & uVar5);
      if (0.0 < dVar1) {
        MT5_OrderGetDouble((void *)0x23e575eae78,9);
        dVar6 = DAT_23e5aa7a448;
        uVar8 = SUB84(DAT_23e5aa7a448,0);
        uVar9 = (undefined4)((ulonglong)DAT_23e5aa7a448 >> 0x20);
        lVar4 = MT5_OrderGetInteger((void *)0x23e575eae78,4);
        uVar3 = (int)lVar4 - 2;
        if (uVar3 < 5 || (int)lVar4 == 7) {
          switch((&switchD_23e5aa44314::switchdataD_23e5aa60e48)[uVar3]) {
          case (undefined *)0x23e5aa44317:
            dVar6 = local_78;
            break;
          case (undefined *)0x23e5aa44737:
            uVar8 = SUB84(local_80,0);
            uVar9 = (undefined4)((ulonglong)local_80 >> 0x20);
            break;
          case (undefined *)0x23e5aa44743:
            uVar8 = SUB84(local_78,0);
            uVar9 = (undefined4)((ulonglong)local_78 >> 0x20);
            break;
          case (undefined *)0x23e5aa4474f:
            dVar6 = local_80;
          }
          FUN_23e5aa10000(&local_a8);
          FUN_23e5aa10000(&local_98);
          if ((double)CONCAT44(uVar9,uVar8) - dVar6 <= dVar1) {
            return;
          }
          goto LAB_23e5aa4434d;
        }
      }
    }
    FUN_23e5aa10000(&local_a8);
    FUN_23e5aa10000(&local_98);
  }
  else {
    FUN_23e5aa10000(&local_98);
  }
LAB_23e5aa4434d:
  if (DAT_23e5aa7a414 == 0) {
    auVar7 = ZEXT816(0);
    DAT_23e5aa774b0 = 0;
    DAT_23e5aa774b4 = auVar7._4_8_;
    DAT_23e5aa774bc._0_4_ = 0;
    DAT_23e5aa774bc._4_4_ = 0;
    FUN_23e5aa10000(&DAT_23e5aa774c4);
    DAT_23e5aa7750c._4_4_ = 0;
    _DAT_23e5aa774d0 = auVar7;
    _DAT_23e5aa774e0 = auVar7;
    _DAT_23e5aa774f0 = auVar7;
    _DAT_23e5aa77500 = auVar7;
    FUN_23e5aa10000(&DAT_23e5aa77514);
    DAT_23e5aa775d0 = 0;
    _DAT_23e5aa77520 = auVar7;
    _DAT_23e5aa77530 = auVar7;
    _DAT_23e5aa77540 = auVar7;
    _DAT_23e5aa77550 = auVar7;
    _DAT_23e5aa77560 = auVar7;
    _DAT_23e5aa77570 = auVar7;
    _DAT_23e5aa77580 = auVar7;
    _DAT_23e5aa77590 = auVar7;
    _DAT_23e5aa775a0 = auVar7;
    _DAT_23e5aa775b0 = auVar7;
    _DAT_23e5aa775c0 = auVar7;
    FUN_23e5aa10000(&DAT_23e5aa775d4);
    DAT_23e5aa77690 = 0;
    _DAT_23e5aa775e0 = auVar7;
    _DAT_23e5aa775f0 = auVar7;
    _DAT_23e5aa77600 = auVar7;
    _DAT_23e5aa77610 = auVar7;
    _DAT_23e5aa77620 = auVar7;
    _DAT_23e5aa77630 = auVar7;
    _DAT_23e5aa77640 = auVar7;
    _DAT_23e5aa77650 = auVar7;
    _DAT_23e5aa77660 = auVar7;
    _DAT_23e5aa77670 = auVar7;
    _DAT_23e5aa77680 = auVar7;
    FUN_23e5aa10000(&DAT_23e5aa77698);
    DAT_23e5aa77714 = 0;
    DAT_23e5aa7770c = 0;
    DAT_23e5aa7771c = 0;
    DAT_23e5aa77704 = 0;
    DAT_23e5aa776fc = 0;
    DAT_23e5aa776f4 = 0;
    DAT_23e5aa776ec = 0;
    DAT_23e5aa776e4 = 0;
    DAT_23e5aa776dc = 0;
    DAT_23e5aa776d4 = 0;
    DAT_23e5aa776cc = 0;
    DAT_23e5aa776c4 = 0;
    DAT_23e5aa776bc = 0;
    DAT_23e5aa776b4 = 0;
    DAT_23e5aa776ac = 0;
    DAT_23e5aa776a4 = 0;
    DAT_23e5aa774b0 = 8;
    DAT_23e5aa774b4 = DAT_23e5aa77725;
    DAT_23e5aa774bc._0_4_ = (undefined4)param_1;
    DAT_23e5aa774bc._4_4_ = (undefined4)(param_1 >> 0x20);
    FUN_23e5aa10950(&DAT_23e5aa77490,&DAT_23e5aa774b0,&DAT_23e5aa775a0);
  }
  else {
    MT5_Dispatch((void *)0x23e575eae78,0xd,2,0x590008);
    DAT_23e5aa775a0 = 0x272b;
  }
  return;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:21304
/* Address: 23e5aa42110 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_23e5aa42110(void)

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
  arg_1 = MT5_OrdersTotal((void *)0x23e575eae78);
  if (-1 < arg_1) {
    uVar10 = 0;
    uVar11 = 0;
    local_60 = 0;
    do {
      DAT_23e5aa777f8 = MT5_OrderGetTicket((void *)0x23e575eae78,arg_1);
      if ((DAT_23e5aa777f8 != 0) &&
         (lVar7 = MT5_OrderGetInteger((void *)0x23e575eae78,0xf), lVar7 == DAT_23e5aa7246c)) {
        MT5_OrderGetString((void *)0x23e575eae78,0);
        FUN_23e5aa105c0(&local_70,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6e9c0);
        if (local_6c == DAT_23e5aa7791c) {
LAB_23e5aa422a8:
          lVar7 = MT5_OrderGetInteger((void *)0x23e575eae78,4);
          if ((lVar7 == 4) &&
             (MT5_OrderGetDouble((void *)0x23e575eae78,9),
             (double)CONCAT44(uVar11,uVar10) <= DAT_23e5aa7a448 &&
             DAT_23e5aa7a448 != (double)CONCAT44(uVar11,uVar10))) {
            local_60 = DAT_23e5aa777f8;
            MT5_OrderGetDouble((void *)0x23e575eae78,9);
            uVar10 = SUB84(DAT_23e5aa7a448,0);
            uVar11 = (undefined4)((ulonglong)DAT_23e5aa7a448 >> 0x20);
          }
        }
        else if ((local_6c != 0) && (DAT_23e5aa7791c != 0)) {
          uVar3 = *(uint *)(local_6c + -4);
          uVar4 = *(uint *)(DAT_23e5aa7791c + -4);
          uVar5 = uVar4;
          if (uVar3 < uVar4) {
            uVar5 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar5 != 0) {
            uVar9 = 1;
            do {
              uVar1 = *(ushort *)(local_6c + -2 + uVar9 * 2);
              uVar2 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar9 * 2);
              if (uVar5 <= uVar9) break;
              uVar9 = uVar9 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_23e5aa422a8;
        }
      }
      uVar9 = local_60;
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
    if (local_60 != 0) {
      FUN_23e5aa44150(local_60);
      lVar7 = -0x640;
      do {
        if ((*(double *)(&DAT_23e5aa76410 + lVar7) == (double)(longlong)uVar9) &&
           (!NAN(*(double *)(&DAT_23e5aa76410 + lVar7)) && !NAN((double)(longlong)uVar9))) {
          *(undefined8 *)(&DAT_23e5aa76410 + lVar7) = 0;
          *(undefined8 *)((longlong)&DAT_23e5aa76418 + lVar7) = 0;
          break;
        }
        lVar7 = lVar7 + 0x10;
      } while (lVar7 != 0);
      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
    }
  }
  FUN_23e5aa10000(&local_70);
  return;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:21472
/* Address: 23e5aa425b0 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_23e5aa425b0(void)

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
  arg_1 = MT5_OrdersTotal((void *)0x23e575eae78);
  if (-1 < arg_1) {
    uVar10 = (undefined4)DAT_23e5aa60288;
    uVar11 = (undefined4)((ulonglong)DAT_23e5aa60288 >> 0x20);
    local_60 = 0;
    do {
      DAT_23e5aa777f8 = MT5_OrderGetTicket((void *)0x23e575eae78,arg_1);
      if ((DAT_23e5aa777f8 != 0) &&
         (lVar7 = MT5_OrderGetInteger((void *)0x23e575eae78,0xf), lVar7 == DAT_23e5aa7246c)) {
        MT5_OrderGetString((void *)0x23e575eae78,0);
        FUN_23e5aa105c0(&local_70,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6e9d0);
        if (local_6c == DAT_23e5aa7791c) {
LAB_23e5aa42758:
          lVar7 = MT5_OrderGetInteger((void *)0x23e575eae78,4);
          if ((lVar7 == 5) &&
             (MT5_OrderGetDouble((void *)0x23e575eae78,9),
             DAT_23e5aa7a448 <= (double)CONCAT44(uVar11,uVar10) &&
             (double)CONCAT44(uVar11,uVar10) != DAT_23e5aa7a448)) {
            local_60 = DAT_23e5aa777f8;
            MT5_OrderGetDouble((void *)0x23e575eae78,9);
            uVar10 = SUB84(DAT_23e5aa7a448,0);
            uVar11 = (undefined4)((ulonglong)DAT_23e5aa7a448 >> 0x20);
          }
        }
        else if ((local_6c != 0) && (DAT_23e5aa7791c != 0)) {
          uVar3 = *(uint *)(local_6c + -4);
          uVar4 = *(uint *)(DAT_23e5aa7791c + -4);
          uVar5 = uVar4;
          if (uVar3 < uVar4) {
            uVar5 = uVar3;
          }
          iVar8 = uVar3 - uVar4;
          if (uVar5 != 0) {
            uVar9 = 1;
            do {
              uVar1 = *(ushort *)(local_6c + -2 + uVar9 * 2);
              uVar2 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar9 * 2);
              if (uVar5 <= uVar9) break;
              uVar9 = uVar9 + 1;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar8 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar8 == 0) goto LAB_23e5aa42758;
        }
      }
      uVar9 = local_60;
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
    if (local_60 != 0) {
      FUN_23e5aa44150(local_60);
      lVar7 = -0x640;
      do {
        if ((*(double *)(&DAT_23e5aa76410 + lVar7) == (double)(longlong)uVar9) &&
           (!NAN(*(double *)(&DAT_23e5aa76410 + lVar7)) && !NAN((double)(longlong)uVar9))) {
          *(undefined8 *)(&DAT_23e5aa76410 + lVar7) = 0;
          *(undefined8 *)((longlong)&DAT_23e5aa76418 + lVar7) = 0;
          break;
        }
        lVar7 = lVar7 + 0x10;
      } while (lVar7 != 0);
      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
    }
  }
  FUN_23e5aa10000(&local_70);
  return;
}



