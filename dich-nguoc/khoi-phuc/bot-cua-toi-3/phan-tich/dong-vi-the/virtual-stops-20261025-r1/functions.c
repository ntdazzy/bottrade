// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:15263
/* Address: 17156270bc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_17156270bc0(void)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int arg_1;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  bool bVar11;
  
  if ((int)(uint)DAT_17156426d18 < 0x40) {
    (*(code *)&runtime_array_helper_7aa0e0)(0x171514ca538,&DAT_17156426d10,0x40,0);
  }
  iVar3 = MT5_PositionsTotal((void *)0x171514ca538);
  if (iVar3 < 1) {
    uVar10 = 0;
  }
  else {
    arg_1 = 0;
    uVar10 = 0;
    do {
      uVar4 = MT5_PositionGetTicket((void *)0x171514ca538,arg_1);
      if ((uVar4 != 0) && (uVar5 = MT5_PositionGetInteger((void *)0x171514ca538,2), uVar5 < 2)) {
        if ((int)(uint)DAT_17156426d18 <= (int)uVar10) {
          (*(code *)&runtime_array_helper_7aa0e0)(0x171514ca538,&DAT_17156426d10,uVar10 + 0x40,0);
        }
        uVar5 = (ulonglong)(int)uVar10;
        if ((uint)DAT_17156426d18 <= uVar5) goto LAB_17156270ecf;
        uVar6 = (ulonglong)(uint)DAT_17156426d18 + ~uVar5;
        if ((DAT_17156426d10._2_2_ & 0x10) == 0) {
          uVar6 = uVar5;
        }
        uVar10 = uVar10 + 1;
        *(ulonglong *)(ram0x017156426d2c + uVar6 * 8) = uVar4;
      }
      arg_1 = arg_1 + 1;
    } while (iVar3 != arg_1);
  }
  uVar2 = DAT_17156426d10._2_2_;
  if (DAT_171562c3450 == '\x01') {
    uVar5 = (ulonglong)uVar10;
    lVar9 = 0;
    uVar4 = (ulonglong)(uint)DAT_17156426d18;
    do {
      if (0.0 < (double)(&DAT_171562bd680)[lVar9 * 3]) {
        if (0 < (int)uVar10) {
          lVar7 = (longlong)(double)(&DAT_171562bd680)[lVar9 * 3];
          uVar6 = uVar5;
          uVar8 = uVar4;
          if ((uVar2 & 0x10) == 0) {
            uVar6 = 0;
            do {
              if (uVar4 == uVar6) goto LAB_17156270e8f;
              if (*(longlong *)(ram0x017156426d2c + uVar6 * 8) == lVar7) goto LAB_17156270e04;
              uVar6 = uVar6 + 1;
            } while (uVar5 != uVar6);
          }
          else {
            do {
              bVar11 = uVar8 == 0;
              uVar8 = uVar8 - 1;
              if (bVar11) goto LAB_17156270e8f;
              if (*(longlong *)(ram0x017156426d2c + uVar8 * 8) == lVar7) goto LAB_17156270e04;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
        }
        (&DAT_171562bd690)[lVar9 * 3] = 0;
        (&DAT_171562bd688)[lVar9 * 3] = 0;
        (&DAT_171562bd680)[lVar9 * 3] = 0;
      }
LAB_17156270e04:
      if (0.0 < (double)(&DAT_171562c0560)[lVar9 * 2]) {
        if (0 < (int)uVar10) {
          lVar7 = (longlong)(double)(&DAT_171562c0560)[lVar9 * 2];
          uVar6 = uVar4;
          uVar8 = uVar5;
          if ((uVar2 & 0x10) == 0) {
            uVar6 = 0;
            do {
              if (uVar4 == uVar6) goto LAB_17156270eaf;
              if (*(longlong *)(ram0x017156426d2c + uVar6 * 8) == lVar7) goto LAB_17156270d74;
              uVar6 = uVar6 + 1;
            } while (uVar5 != uVar6);
          }
          else {
            do {
              bVar11 = uVar6 == 0;
              uVar6 = uVar6 - 1;
              if (bVar11) goto LAB_17156270eaf;
              if (*(longlong *)(ram0x017156426d2c + uVar6 * 8) == lVar7) goto LAB_17156270d74;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
        }
        (&DAT_171562c0560)[lVar9 * 2] = 0;
        (&DAT_171562c0568)[lVar9 * 2] = 0;
      }
LAB_17156270d74:
      bVar11 = lVar9 != 499;
      lVar9 = lVar9 + 1;
    } while (bVar11);
  }
  return;
LAB_17156270e8f:
  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x1f1ea8000001f6);
LAB_17156270eaf:
  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x1f1ebe000001f6);
LAB_17156270ecf:
  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x161e9d000001f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:31968
/* Address: 17156297f10 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

double FUN_17156297f10(int param_1,double param_2,double param_3,longlong param_4)

{
  double dVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  
  if (DAT_171562c3450 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_171562c0560 + lVar2) == (double)param_4) &&
         (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar2)) && !NAN((double)param_4))) {
        return *(double *)((longlong)&DAT_171562c0568 + lVar2);
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  if (param_1 == 2) {
    uVar3 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
    dVar1 = param_3 * DAT_171562c3dd8 + param_2;
    if ((longlong)dVar1 == -0x8000000000000000) goto LAB_17156298102;
    dVar6 = (double)(longlong)dVar1;
    uVar4 = 0xb;
    if ((uint)uVar3 < 0xb) {
      uVar4 = uVar3 & 0xffffffff;
    }
    dVar5 = *(double *)(&DAT_171562a9b40 + uVar4 * 8);
    dVar1 = (dVar1 - dVar6) * dVar5 + *(double *)(&DAT_171562a9180 + (ulonglong)(0.0 < dVar1) * 8);
  }
  else {
    dVar1 = 0.0;
    if (param_1 != 1) goto LAB_17156298102;
    uVar3 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
    dVar1 = param_2 - param_3 * DAT_171562c3dd8;
    if ((longlong)dVar1 == -0x8000000000000000) goto LAB_17156298102;
    dVar6 = (double)(longlong)dVar1;
    uVar4 = 0xb;
    if ((uint)uVar3 < 0xb) {
      uVar4 = uVar3 & 0xffffffff;
    }
    dVar5 = *(double *)(&DAT_171562a9b40 + uVar4 * 8);
    dVar1 = (dVar1 - dVar6) * dVar5 + *(double *)(&DAT_171562a9180 + (ulonglong)(0.0 < dVar1) * 8);
  }
  dVar1 = (double)(longlong)dVar1 / dVar5 + dVar6;
LAB_17156298102:
  if (DAT_171562c3450 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_171562c0560 + lVar2) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar2)))) goto LAB_17156298251;
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  FUN_17156270bc0();
  if (DAT_171562c3450 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_171562c0560 + lVar2) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar2)))) {
LAB_17156298251:
        *(double *)((longlong)&DAT_171562c0560 + lVar2) = (double)param_4;
        *(double *)((longlong)&DAT_171562c0568 + lVar2) = dVar1;
        *(undefined8 *)((longlong)&DAT_171562c0570 + lVar2) = 0;
        return dVar1;
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  if (DAT_171562c3458 != param_4) {
    DAT_171562c3458 = param_4;
    MT5_PositionsTotal((void *)0x171514ca538);
    MT5_Dispatch((void *)0x171514ca538,2,7,0x590008);
  }
  return dVar1;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:32053
/* Address: 171562982b0 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

double FUN_171562982b0(double param_1,longlong param_2)

{
  longlong lVar1;
  double dVar2;
  
  if (DAT_171562c3450 == '\x01') {
    dVar2 = (double)param_2;
    lVar1 = -8000;
    do {
      if ((*(double *)((longlong)&DAT_171562c24a0 + lVar1) == dVar2) &&
         (!NAN(*(double *)((longlong)&DAT_171562c24a0 + lVar1)) && !NAN(dVar2))) {
        return *(double *)(&DAT_171562c24a8 + lVar1);
      }
      lVar1 = lVar1 + 0x10;
    } while (lVar1 != 0);
    if (param_1 <= 0.0) {
      return 0.0;
    }
    lVar1 = -8000;
    do {
      if ((*(double *)((longlong)&DAT_171562c24a0 + lVar1) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_171562c24a0 + lVar1)))) {
        *(double *)((longlong)&DAT_171562c24a0 + lVar1) = dVar2;
        goto LAB_17156298499;
      }
      lVar1 = lVar1 + 0x10;
    } while (lVar1 != 0);
  }
  else if (param_1 <= 0.0) {
    return 0.0;
  }
  FUN_17156270bc0();
  if (DAT_171562c3450 == '\x01') {
    lVar1 = -8000;
    do {
      if ((*(double *)((longlong)&DAT_171562c24a0 + lVar1) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_171562c24a0 + lVar1)))) {
        *(double *)((longlong)&DAT_171562c24a0 + lVar1) = (double)param_2;
LAB_17156298499:
        *(double *)(&DAT_171562c24a8 + lVar1) = param_1;
        return param_1;
      }
      lVar1 = lVar1 + 0x10;
    } while (lVar1 != 0);
  }
  if (DAT_171562c3460 != param_2) {
    DAT_171562c3460 = param_2;
    MT5_PositionsTotal((void *)0x171514ca538);
    MT5_Dispatch((void *)0x171514ca538,2,7,0x590008);
  }
  return param_1;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:32113
/* Address: 171562984c0 */

undefined8 FUN_171562984c0(longlong param_1)

{
  double dVar1;
  longlong lVar2;
  
  if ((0 < DAT_171562bd518) && (DAT_171562c3450 == '\x01')) {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_171562c0560 + lVar2) == (double)param_1) &&
         (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar2)) && !NAN((double)param_1))) {
        dVar1 = *(double *)((longlong)&DAT_171562c0570 + lVar2);
        if ((longlong)dVar1 != 0) {
          lVar2 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0);
          lVar2 = lVar2 - (longlong)dVar1;
          return CONCAT71((int7)((ulonglong)lVar2 >> 8),DAT_171562bd518 <= lVar2);
        }
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  return 0;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:32142
/* Address: 17156298560 */

void FUN_17156298560(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (DAT_171562c3450 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_171562c0560 + lVar2) == (double)param_1) &&
         (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar2)) && !NAN((double)param_1))) {
        lVar1 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0);
        *(double *)((longlong)&DAT_171562c0570 + lVar2) = (double)lVar1;
        return;
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  return;
}



