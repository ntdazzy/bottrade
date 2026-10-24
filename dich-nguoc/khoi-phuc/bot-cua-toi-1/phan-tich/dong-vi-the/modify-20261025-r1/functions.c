// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:16977
/* Address: 23e5aa36d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined1 FUN_23e5aa36d20(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  undefined4 local_88;
  undefined8 local_84;
  
  local_88 = 0;
  local_84 = 0;
  if (DAT_23e5aa7a414 == 0) {
    bVar1 = MT5_PositionSelectByTicket((void *)0x23e575eae78,param_1);
    if (bVar1) {
      DAT_23e5aa774b0 = 0;
      DAT_23e5aa774b4._0_4_ = 0;
      DAT_23e5aa774b4._4_4_ = 0;
      DAT_23e5aa774bc._0_4_ = 0;
      DAT_23e5aa774bc._4_4_ = 0;
      FUN_23e5aa10000(&DAT_23e5aa774c4);
      DAT_23e5aa774e0 = 0;
      DAT_23e5aa774e8 = 0;
      _DAT_23e5aa77500 = 0;
      _DAT_23e5aa77508 = 0;
      DAT_23e5aa774f0 = 0;
      DAT_23e5aa774f8 = 0;
      DAT_23e5aa774d0 = 0;
      DAT_23e5aa774d8 = 0;
      DAT_23e5aa7750c._4_4_ = 0;
      FUN_23e5aa10000(&DAT_23e5aa77514);
      _DAT_23e5aa775b0 = 0;
      uRam0000023e5aa775b8 = 0;
      _DAT_23e5aa77590 = 0;
      uRam0000023e5aa77598 = 0;
      _DAT_23e5aa775c0 = 0;
      uRam0000023e5aa775c8 = 0;
      _DAT_23e5aa775a0 = 0;
      uRam0000023e5aa775a8 = 0;
      DAT_23e5aa77520 = 0;
      uRam0000023e5aa77528 = 0;
      _DAT_23e5aa77580 = 0;
      uRam0000023e5aa77588 = 0;
      _DAT_23e5aa77570 = 0;
      uRam0000023e5aa77578 = 0;
      _DAT_23e5aa77560 = 0;
      uRam0000023e5aa77568 = 0;
      _DAT_23e5aa77550 = 0;
      uRam0000023e5aa77558 = 0;
      _DAT_23e5aa77540 = 0;
      uRam0000023e5aa77548 = 0;
      _DAT_23e5aa77530 = 0;
      uRam0000023e5aa77538 = 0;
      DAT_23e5aa775d0 = 0;
      FUN_23e5aa10000(&DAT_23e5aa775d4);
      _DAT_23e5aa77670 = 0;
      uRam0000023e5aa77678 = 0;
      _DAT_23e5aa77660 = 0;
      uRam0000023e5aa77668 = 0;
      _DAT_23e5aa77680 = 0;
      uRam0000023e5aa77688 = 0;
      _DAT_23e5aa77650 = 0;
      uRam0000023e5aa77658 = 0;
      _DAT_23e5aa77640 = 0;
      uRam0000023e5aa77648 = 0;
      _DAT_23e5aa77630 = 0;
      uRam0000023e5aa77638 = 0;
      _DAT_23e5aa77620 = 0;
      uRam0000023e5aa77628 = 0;
      _DAT_23e5aa77610 = 0;
      uRam0000023e5aa77618 = 0;
      _DAT_23e5aa77600 = 0;
      uRam0000023e5aa77608 = 0;
      _DAT_23e5aa775f0 = 0;
      uRam0000023e5aa775f8 = 0;
      _DAT_23e5aa775e0 = 0;
      uRam0000023e5aa775e8 = 0;
      DAT_23e5aa77690 = 0;
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
      DAT_23e5aa774b0 = 6;
      DAT_23e5aa77520 = param_1;
      MT5_PositionGetString((void *)0x23e575eae78,0);
      FUN_23e5aa105c0(&local_88,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6d958);
      FUN_23e5aa105c0(&DAT_23e5aa774c4,&local_88,0,&PTR_DAT_23e5aa6d968);
      DAT_23e5aa774b4._0_4_ = (undefined4)DAT_23e5aa77725;
      DAT_23e5aa774b4._4_4_ = (undefined4)((ulonglong)DAT_23e5aa77725 >> 0x20);
      DAT_23e5aa774e8 = param_2;
      DAT_23e5aa774f0 = param_3;
      uVar2 = FUN_23e5aa10950(&DAT_23e5aa77490,&DAT_23e5aa774b0,&DAT_23e5aa775a0);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    MT5_Dispatch((void *)0x23e575eae78,0xd,2,0x590008);
    uVar2 = 0;
    _DAT_23e5aa775a0 = CONCAT44(DAT_23e5aa775a0_4,0x272b);
  }
  FUN_23e5aa10000(&local_88);
  return uVar2;
}



