// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:11091
/* Address: 23e5aa28790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23e5aa28790(void)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  int arg_1;
  ulonglong uVar7;
  bool bVar8;
  
  if ((int)DAT_23e5aa7a3c8 < 0x40) {
    (*(code *)&runtime_array_helper_7aa0e0)(0x23e575eae78,&DAT_23e5aa7a3c0,0x40,0);
  }
  iVar2 = MT5_PositionsTotal((void *)0x23e575eae78);
  if (iVar2 < 1) {
    uVar6 = 0;
  }
  else {
    arg_1 = 0;
    uVar6 = 0;
    do {
      uVar3 = MT5_PositionGetTicket((void *)0x23e575eae78,arg_1);
      if (uVar3 != 0) {
        uVar4 = MT5_PositionGetInteger((void *)0x23e575eae78,2);
        if (uVar4 < 2) {
          if ((int)DAT_23e5aa7a3c8 <= (int)uVar6) {
            (*(code *)&runtime_array_helper_7aa0e0)(0x23e575eae78,&DAT_23e5aa7a3c0,uVar6 + 0x40,0);
          }
          uVar4 = (ulonglong)(int)uVar6;
          if (DAT_23e5aa7a3c8 <= uVar4) goto LAB_23e5aa28a7e;
          uVar7 = (ulonglong)DAT_23e5aa7a3c8 + ~uVar4;
          if ((DAT_23e5aa7a3c0._2_2_ & 0x10) == 0) {
            uVar7 = uVar4;
          }
          uVar6 = uVar6 + 1;
          *(ulonglong *)(ram0x023e5aa7a3dc + uVar7 * 8) = uVar3;
        }
      }
      arg_1 = arg_1 + 1;
    } while (iVar2 != arg_1);
  }
  if (DAT_23e5aa76410 == '\x01') {
    if ((int)uVar6 < 1) {
      lVar5 = 0;
      do {
        if (0.0 < *(double *)((longlong)&DAT_23e5aa72590 + lVar5)) {
          *(undefined8 *)((longlong)&DAT_23e5aa725a0 + lVar5) = 0;
          *(undefined8 *)((longlong)&DAT_23e5aa72598 + lVar5) = 0;
          *(undefined8 *)((longlong)&DAT_23e5aa72590 + lVar5) = 0;
        }
        lVar5 = lVar5 + 0x18;
      } while (lVar5 != 12000);
    }
    else {
      uVar3 = (ulonglong)DAT_23e5aa7a3c8;
      if ((DAT_23e5aa7a3c0._2_2_ & 0x10) == 0) {
        lVar5 = 0;
        do {
          if (0.0 < (double)(&DAT_23e5aa72590)[lVar5 * 3]) {
            uVar4 = 0;
            do {
              if (uVar3 == uVar4) goto LAB_23e5aa28a5e;
              if (*(longlong *)(ram0x023e5aa7a3dc + uVar4 * 8) ==
                  (longlong)(double)(&DAT_23e5aa72590)[lVar5 * 3]) goto LAB_23e5aa28910;
              uVar4 = uVar4 + 1;
            } while (uVar6 != uVar4);
            (&DAT_23e5aa725a0)[lVar5 * 3] = 0;
            (&DAT_23e5aa72598)[lVar5 * 3] = 0;
            (&DAT_23e5aa72590)[lVar5 * 3] = 0;
          }
LAB_23e5aa28910:
          bVar8 = lVar5 != 499;
          lVar5 = lVar5 + 1;
        } while (bVar8);
      }
      else {
        lVar5 = 0;
        do {
          if (0.0 < (double)(&DAT_23e5aa72590)[lVar5 * 3]) {
            uVar4 = (ulonglong)uVar6;
            uVar7 = uVar3;
            do {
              bVar8 = uVar7 == 0;
              uVar7 = uVar7 - 1;
              if (bVar8) goto LAB_23e5aa28a5e;
              if (*(longlong *)(ram0x023e5aa7a3dc + uVar7 * 8) ==
                  (longlong)(double)(&DAT_23e5aa72590)[lVar5 * 3]) goto LAB_23e5aa289f0;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
            (&DAT_23e5aa725a0)[lVar5 * 3] = 0;
            (&DAT_23e5aa72598)[lVar5 * 3] = 0;
            (&DAT_23e5aa72590)[lVar5 * 3] = 0;
          }
LAB_23e5aa289f0:
          bVar8 = lVar5 != 499;
          lVar5 = lVar5 + 1;
        } while (bVar8);
      }
    }
  }
  return;
LAB_23e5aa28a5e:
  (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1f1ad9000001f6);
LAB_23e5aa28a7e:
  (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x161ace000001f6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:27109
/* Address: 23e5aa4d200 */

/* WARNING: Restarted to delay deadcode elimination for space: register */

double FUN_23e5aa4d200(int param_1,double param_2,double param_3,longlong param_4)

{
  double dVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  
  if (DAT_23e5aa76410 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar2) == (double)param_4) &&
         (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar2)) && !NAN((double)param_4))) {
        return *(double *)((longlong)&DAT_23e5aa75478 + lVar2);
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  if (param_1 == 2) {
    uVar3 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
    dVar1 = param_3 * DAT_23e5aa76d98 + param_2;
    if ((longlong)dVar1 == -0x8000000000000000) goto LAB_23e5aa4d3f2;
    dVar6 = (double)(longlong)dVar1;
    uVar4 = 0xb;
    if ((uint)uVar3 < 0xb) {
      uVar4 = uVar3 & 0xffffffff;
    }
    dVar5 = *(double *)(&DAT_23e5aa61600 + uVar4 * 8);
    dVar1 = (dVar1 - dVar6) * dVar5 + *(double *)(&DAT_23e5aa60f20 + (ulonglong)(0.0 < dVar1) * 8);
  }
  else {
    dVar1 = 0.0;
    if (param_1 != 1) goto LAB_23e5aa4d3f2;
    uVar3 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
    dVar1 = param_2 - param_3 * DAT_23e5aa76d98;
    if ((longlong)dVar1 == -0x8000000000000000) goto LAB_23e5aa4d3f2;
    dVar6 = (double)(longlong)dVar1;
    uVar4 = 0xb;
    if ((uint)uVar3 < 0xb) {
      uVar4 = uVar3 & 0xffffffff;
    }
    dVar5 = *(double *)(&DAT_23e5aa61600 + uVar4 * 8);
    dVar1 = (dVar1 - dVar6) * dVar5 + *(double *)(&DAT_23e5aa60f20 + (ulonglong)(0.0 < dVar1) * 8);
  }
  dVar1 = (double)(longlong)dVar1 / dVar5 + dVar6;
LAB_23e5aa4d3f2:
  if (DAT_23e5aa76410 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar2) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar2)))) goto LAB_23e5aa4d541;
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  FUN_23e5aa28790();
  if (DAT_23e5aa76410 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar2) == 0.0) &&
         (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar2)))) {
LAB_23e5aa4d541:
        *(double *)((longlong)&DAT_23e5aa75470 + lVar2) = (double)param_4;
        *(double *)((longlong)&DAT_23e5aa75478 + lVar2) = dVar1;
        *(undefined8 *)((longlong)&DAT_23e5aa75480 + lVar2) = 0;
        return dVar1;
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  if (DAT_23e5aa76418 != param_4) {
    DAT_23e5aa76418 = param_4;
    MT5_PositionsTotal((void *)0x23e575eae78);
    MT5_Dispatch((void *)0x23e575eae78,2,7,0x590008);
  }
  return dVar1;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:27194
/* Address: 23e5aa4d5a0 */

undefined8 FUN_23e5aa4d5a0(longlong param_1)

{
  double dVar1;
  longlong lVar2;
  
  if ((0 < DAT_23e5aa72420) && (DAT_23e5aa76410 == '\x01')) {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar2) == (double)param_1) &&
         (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar2)) && !NAN((double)param_1))) {
        dVar1 = *(double *)((longlong)&DAT_23e5aa75480 + lVar2);
        if ((longlong)dVar1 != 0) {
          lVar2 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
          lVar2 = lVar2 - (longlong)dVar1;
          return CONCAT71((int7)((ulonglong)lVar2 >> 8),DAT_23e5aa72420 <= lVar2);
        }
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  return 0;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:27223
/* Address: 23e5aa4d640 */

void FUN_23e5aa4d640(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (DAT_23e5aa76410 == '\x01') {
    lVar2 = -12000;
    do {
      if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar2) == (double)param_1) &&
         (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar2)) && !NAN((double)param_1))) {
        lVar1 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
        *(double *)((longlong)&DAT_23e5aa75480 + lVar2) = (double)lVar1;
        return;
      }
      lVar2 = lVar2 + 0x18;
    } while (lVar2 != 0);
  }
  return;
}



