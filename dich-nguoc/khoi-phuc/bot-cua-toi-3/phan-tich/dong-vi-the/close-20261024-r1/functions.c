// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:21093
/* Address: 1715627e370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_1715627e370(ulonglong param_1)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined8 local_64;
  
  local_68 = 0;
  local_78 = 0;
  local_64 = 0;
  local_74 = 0;
  if (DAT_17156426e14 == 0) {
    bVar1 = MT5_PositionSelectByTicket((void *)0x171514ca538,param_1);
    if (bVar1) {
      local_78 = 0;
      local_74 = 0;
      MT5_PositionGetString((void *)0x171514ca538,0);
      FUN_171562505c0(&local_68,&DAT_17156426e3c,1,&PTR_DAT_171562b7cd8);
      FUN_171562505c0(&local_78,&local_68,0,&PTR_DAT_171562b7ce8);
      DAT_171562c44f0 = 0;
      DAT_171562c44f4._0_4_ = 0;
      DAT_171562c44f4._4_4_ = 0;
      DAT_171562c44fc._0_4_ = 0;
      DAT_171562c44fc._4_4_ = 0;
      FUN_17156250000(&DAT_171562c4504);
      DAT_171562c454c._4_4_ = 0;
      _DAT_171562c4540 = 0;
      _DAT_171562c4548 = 0;
      DAT_171562c4530 = 0;
      DAT_171562c4538 = 0;
      DAT_171562c4520 = 0;
      DAT_171562c4528 = 0;
      DAT_171562c4510 = 0;
      DAT_171562c4518 = 0;
      FUN_17156250000(&DAT_171562c4554);
      _DAT_171562c45e0 = 0;
      uRam00000171562c45e8 = 0;
      _DAT_171562c45f0 = 0;
      uRam00000171562c45f8 = 0;
      _DAT_171562c4600 = 0;
      uRam00000171562c4608 = 0;
      DAT_171562c4560 = 0;
      uRam00000171562c4568 = 0;
      _DAT_171562c45c0 = 0;
      uRam00000171562c45c8 = 0;
      _DAT_171562c45d0 = 0;
      uRam00000171562c45d8 = 0;
      _DAT_171562c45a0 = 0;
      uRam00000171562c45a8 = 0;
      _DAT_171562c45b0 = 0;
      uRam00000171562c45b8 = 0;
      _DAT_171562c4580 = 0;
      uRam00000171562c4588 = 0;
      _DAT_171562c4590 = 0;
      uRam00000171562c4598 = 0;
      DAT_171562c4610 = 0;
      _DAT_171562c4570 = 0;
      uRam00000171562c4578 = 0;
      FUN_17156250000(&DAT_171562c4614);
      _DAT_171562c46b0 = 0;
      uRam00000171562c46b8 = 0;
      _DAT_171562c46a0 = 0;
      uRam00000171562c46a8 = 0;
      _DAT_171562c46c0 = 0;
      uRam00000171562c46c8 = 0;
      _DAT_171562c4690 = 0;
      uRam00000171562c4698 = 0;
      _DAT_171562c4680 = 0;
      uRam00000171562c4688 = 0;
      _DAT_171562c4670 = 0;
      uRam00000171562c4678 = 0;
      _DAT_171562c4660 = 0;
      uRam00000171562c4668 = 0;
      _DAT_171562c4650 = 0;
      uRam00000171562c4658 = 0;
      _DAT_171562c4640 = 0;
      uRam00000171562c4648 = 0;
      _DAT_171562c4630 = 0;
      uRam00000171562c4638 = 0;
      _DAT_171562c4620 = 0;
      uRam00000171562c4628 = 0;
      DAT_171562c46d0 = 0;
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
      cVar2 = FUN_1715627e8f0(&local_78);
      if (cVar2 != '\0') {
        uVar3 = MT5_PositionGetInteger((void *)0x171514ca538,2);
        bVar1 = (uVar3 & 0xffffffff) == 0;
        _DAT_171562c4540 = CONCAT44(DAT_171562c4544,(uint)bVar1);
        MT5_SymbolInfoDouble((void *)0x171514ca538,&local_78,(uint)!bVar1 * 3 + 1);
        DAT_171562c4518 = DAT_17156426e48;
        DAT_171562c44f0 = 1;
        DAT_171562c4560 = param_1;
        FUN_171562505c0(&DAT_171562c4504,&local_78,0,&PTR_DAT_171562b7cf8);
        MT5_PositionGetDouble((void *)0x171514ca538,3);
        DAT_171562c4510 = DAT_17156426e48;
        DAT_171562c44f4._0_4_ = (undefined4)DAT_171562c4765;
        DAT_171562c44f4._4_4_ = (undefined4)((ulonglong)DAT_171562c4765 >> 0x20);
        DAT_171562c4538 = DAT_171562c476d;
        FUN_17156250950(&DAT_171562c44d0,&DAT_171562c44f0,&DAT_171562c45e0);
      }
      FUN_17156250000(&local_78);
    }
  }
  else {
    MT5_Dispatch((void *)0x171514ca538,0xd,2,0x590008);
    _DAT_171562c45e0 = CONCAT44(DAT_171562c45e0_4,0x272b);
  }
  FUN_17156250000(&local_68);
  return;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:31922
/* Address: 17156297d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_17156297d20(ulonglong param_1)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  longlong lVar4;
  
  bVar3 = MT5_PositionSelectByTicket((void *)0x171514ca538,param_1);
  if (bVar3) {
    DAT_171562c4765 = MT5_PositionGetInteger((void *)0x171514ca538,0xc);
    lVar4 = MT5_PositionGetInteger((void *)0x171514ca538,2);
    dVar1 = DAT_171562c4798;
    if (lVar4 == 0) {
      MT5_PositionGetDouble((void *)0x171514ca538,6);
      dVar2 = DAT_171562c4798;
      if (DAT_171562c3ab0 < (double)((ulonglong)(dVar1 - DAT_17156426e48) & _DAT_171562a9170)) {
        MT5_PositionGetDouble((void *)0x171514ca538,6);
        if (DAT_171562c44a8 < (double)((ulonglong)(dVar2 - DAT_17156426e48) & _DAT_171562a9170)) {
          FUN_1715627e370(param_1);
        }
      }
    }
    lVar4 = MT5_PositionGetInteger((void *)0x171514ca538,2);
    dVar1 = DAT_171562c47a0;
    if (lVar4 == 1) {
      MT5_PositionGetDouble((void *)0x171514ca538,6);
      dVar2 = DAT_171562c4798;
      if (DAT_171562c3ab0 < (double)((ulonglong)(dVar1 - DAT_17156426e48) & _DAT_171562a9170)) {
        MT5_PositionGetDouble((void *)0x171514ca538,6);
        if (DAT_171562c44a8 < (double)((ulonglong)(dVar2 - DAT_17156426e48) & _DAT_171562a9170)) {
          FUN_1715627e370(param_1);
          return;
        }
      }
    }
  }
  return;
}



