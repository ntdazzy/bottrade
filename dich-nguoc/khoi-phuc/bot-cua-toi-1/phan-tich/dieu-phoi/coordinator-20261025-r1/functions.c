// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:8225
/* Address: 23e5aa20f60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_23e5aa20f60(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  double dVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  bool bVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  double *pdVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  wchar_t *pwVar18;
  uint uVar19;
  wchar_t *pwVar20;
  byte bVar21;
  ulonglong uVar22;
  wchar_t *pwVar23;
  undefined **ppuVar24;
  wchar_t *pwVar25;
  ulonglong uVar26;
  uint uVar27;
  ulonglong uVar28;
  wchar_t *pwVar29;
  double dVar30;
  double dVar31;
  int local_108;
  longlong local_104;
  int local_ec;
  undefined4 local_e8;
  longlong local_e4;
  longlong local_d8;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c0;
  undefined8 local_bc;
  int local_a8;
  longlong local_a0;
  undefined4 local_98;
  longlong local_94;
  int local_80;
  
  if (DAT_23e5aa721e0 == 1) {
    lVar10 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
    uVar13 = (ulonglong)DAT_23e5aa721e0;
    if (lVar10 <= (longlong)(DAT_23e5aa721d0 + uVar13)) {
      bVar21 = 1;
      goto joined_r0x023e5aa20fff;
    }
    bVar21 = 0;
    DAT_23e5aa721d0 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
    uVar13 = (ulonglong)DAT_23e5aa721e0;
    if (DAT_23e5aa721c9 == 0) goto LAB_23e5aa2100b;
LAB_23e5aa21010:
    lVar10 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,1,1);
    if (lVar10 <= DAT_23e5aa721d8) goto LAB_23e5aa21072;
    DAT_23e5aa721d8 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,1,1);
  }
  else {
    uVar13 = 0;
    bVar21 = DAT_23e5aa721c9;
joined_r0x023e5aa20fff:
    if (DAT_23e5aa721c9 != 0) goto LAB_23e5aa21010;
LAB_23e5aa2100b:
    if ((uVar13 & 1) != 0) goto LAB_23e5aa21010;
LAB_23e5aa21072:
    if ((bVar21 & 1) != 0) {
      return;
    }
  }
  if (DAT_23e5aa77470 != '\x01') {
    return;
  }
  lVar10 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,0x8001,1);
  if (DAT_23e5aa77478 < lVar10) {
    DAT_23e5aa77478 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,0x8001,1);
    MT5_AccountInfoInteger((void *)0x23e575eae78,0x20);
    cVar8 = FUN_23e5aa15880();
    iVar15 = DAT_23e5aa7a3b0 + 1;
    DAT_23e5aa7a3b0 = 0;
    if (cVar8 == '\0') {
      DAT_23e5aa7a3b0 = iVar15;
    }
    if (2 < DAT_23e5aa7a3b0) {
      DAT_23e5aa77470 = '\0';
      MT5_Dispatch((void *)0x23e575eae78,3,1,0x590008);
      return;
    }
  }
  MT5_AccountInfoDouble((void *)0x23e575eae78,0x25);
  DAT_23e5aa7a320 = DAT_23e5aa7a448;
  if (DAT_23e5aa7a790 != '\0') {
    MT5_AccountInfoDouble((void *)0x23e575eae78,0x28);
  }
  DAT_23e5aa7a320 = DAT_23e5aa7a448;
  FUN_23e5aa273f0();
  if ((DAT_23e5aa7a770 == '\0') || (DAT_23e5aa7a328 <= DAT_23e5aa7a320)) {
    if (DAT_23e5aa7a328 < DAT_23e5aa7a320) {
      DAT_23e5aa7a328 = DAT_23e5aa7a320;
      (*(code *)0x7ff6846ddc90)(0x23e575eae78,&DAT_23e5aa7a330);
    }
  }
  else {
    DAT_23e5aa7a320 = DAT_23e5aa7a328;
  }
  if (0.0 < DAT_23e5aa7a738) {
    DAT_23e5aa7a320 = DAT_23e5aa7a738;
  }
  if (DAT_23e5aa7a5f8 < 4) {
    DAT_23e5aa72265 = (byte)DAT_23e5aa7a5f8 & 1;
    DAT_23e5aa72267 = (0xcU >> (DAT_23e5aa7a5f8 & 0xf) & 1) != 0;
  }
  cVar8 = FUN_23e5aa27840();
  if (cVar8 == '\0') {
    bVar9 = false;
    local_d8 = CONCAT71(local_d8._1_7_,DAT_23e5aa7a650);
    DAT_23e5aa79f64 = DAT_23e5aa7a658;
    if ((((~DAT_23e5aa79f62 | DAT_23e5aa79f60) & 1) != 0) && (DAT_23e5aa7a650 != '\0')) {
      DAT_23e5aa79f60 = 0;
      DAT_23e5aa79f61 = 0;
      DAT_23e5aa79f68 = FUN_23e5aa27d20();
      if (DAT_23e5aa79f68 == 999) {
        MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        (*(code *)0x7ff6846d17c0)(0x23e575eae78,2000);
        DAT_23e5aa79f68 = FUN_23e5aa27d20();
        goto joined_r0x023e5aa21458;
      }
      goto LAB_23e5aa214a8;
    }
  }
  else {
    bVar9 = false;
    local_d8 = CONCAT71(local_d8._1_7_,DAT_23e5aa7a650);
    DAT_23e5aa79f64 = DAT_23e5aa7a660;
    if (((DAT_23e5aa79f60 & DAT_23e5aa79f62 & 1) == 0) && (DAT_23e5aa7a650 != '\0')) {
      DAT_23e5aa79f60 = 1;
      DAT_23e5aa79f61 = 1;
      DAT_23e5aa79f68 = FUN_23e5aa27d20();
      if (DAT_23e5aa79f68 == 999) {
        MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        (*(code *)0x7ff6846d17c0)(0x23e575eae78,2000);
        DAT_23e5aa79f68 = FUN_23e5aa27d20();
joined_r0x023e5aa21458:
        if (DAT_23e5aa79f68 == 999) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        }
      }
LAB_23e5aa214a8:
      DAT_23e5aa79f62 = 1;
      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
      bVar9 = true;
    }
  }
  local_e8 = 0;
  local_d0 = 0;
  local_e4 = 0;
  local_cc = 0;
  uVar28 = 0;
  lVar10 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
  MT5_TimeToStruct((void *)0x23e575eae78,lVar10,&local_108);
  uVar22 = (ulonglong)local_108;
  runtime_cast_to_string((void *)0x23e575eae78,uVar22,0x52,&local_d0);
  FUN_23e5aa105c0(&local_e8,&local_d0,0,&PTR_DAT_23e5aa71740);
  uVar17 = DAT_23e5aa6cc98;
  uVar13 = (ulonglong)DAT_23e5aa6cc98;
  if ((DAT_23e5aa6cc98 != 0) || (local_e4 == 0)) {
    if (local_e4 != 0) {
      uVar28 = (ulonglong)*(uint *)(local_e4 + -4);
    }
    uVar19 = DAT_23e5aa6cc98 + (int)uVar28;
    uVar16 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
      uVar16 = 0x7ffffffe;
    }
    cVar8 = FUN_23e5aa10060(&local_e8,uVar16);
    if (cVar8 != '\0') {
      if (uVar17 != 0) {
        lVar10 = local_e4 + uVar28 * 2;
        if (uVar17 < 0x10) {
          uVar28 = 0;
        }
        else if (lVar10 - 0x23e5aa6cc9cU < 0x20) {
          uVar28 = 0;
        }
        else {
          uVar26 = 0;
          uVar28 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar5 = *(undefined4 *)((longlong)literal_23e5aa6cc9c + uVar26 + 4);
            uVar6 = *(undefined4 *)((longlong)literal_23e5aa6cc9c + uVar26 + 8);
            uVar7 = *(undefined4 *)((longlong)literal_23e5aa6cc9c + uVar26 + 0xc);
            puVar1 = (undefined4 *)(lVar10 + uVar26);
            *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6cc9c + uVar26);
            puVar1[1] = uVar5;
            puVar1[2] = uVar6;
            puVar1[3] = uVar7;
            uVar26 = uVar26 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar26);
          if (uVar28 == uVar13) goto LAB_23e5aa21682;
        }
        do {
          *(wchar_t *)(lVar10 + uVar28 * 2) = literal_23e5aa6cc9c[uVar28];
          uVar28 = uVar28 + 1;
        } while (uVar13 != uVar28);
      }
LAB_23e5aa21682:
      *(uint *)(local_e4 + -4) = uVar19;
      *(undefined2 *)(local_e4 + (ulonglong)uVar19 * 2) = 0;
      goto LAB_23e5aa2168d;
    }
LAB_23e5aa272a3:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x203354000001f9);
LAB_23e5aa272c3:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x203355000001f9);
LAB_23e5aa272e3:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e3019000001f9);
LAB_23e5aa27303:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e3055000001f9);
LAB_23e5aa27323:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e3093000001f9);
LAB_23e5aa27343:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e30d0000001f9);
LAB_23e5aa27363:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e310c000001f9);
LAB_23e5aa27383:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e3148000001f9);
LAB_23e5aa273a3:
    (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e3185000001f9);
    goto LAB_23e5aa273c3;
  }
LAB_23e5aa2168d:
  lVar10 = MT5_StringToTime((void *)0x23e575eae78,&local_e8);
  runtime_cast_to_string((void *)0x23e575eae78,uVar22,0x52,&local_d0);
  uVar22 = 0;
  FUN_23e5aa105c0(&local_e8,&local_d0);
  uVar17 = DAT_23e5aa6ccc8;
  uVar13 = (ulonglong)DAT_23e5aa6ccc8;
  if ((DAT_23e5aa6ccc8 != 0) || (local_e4 == 0)) {
    if (local_e4 != 0) {
      uVar22 = (ulonglong)*(uint *)(local_e4 + -4);
    }
    uVar19 = DAT_23e5aa6ccc8 + (int)uVar22;
    uVar16 = 0x104;
    if ((0x103 < uVar19) &&
       ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
      uVar16 = 0x7ffffffe;
    }
    cVar8 = FUN_23e5aa10060(&local_e8,uVar16);
    if (cVar8 == '\0') goto LAB_23e5aa272c3;
    if (uVar17 != 0) {
      lVar11 = local_e4 + uVar22 * 2;
      if (uVar17 < 0x10) {
        uVar22 = 0;
      }
      else if (lVar11 - 0x23e5aa6ccccU < 0x20) {
        uVar22 = 0;
      }
      else {
        uVar28 = 0;
        uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
        do {
          uVar5 = *(undefined4 *)((longlong)literal_23e5aa6cccc + uVar28 + 4);
          uVar6 = *(undefined4 *)((longlong)literal_23e5aa6cccc + uVar28 + 8);
          uVar7 = *(undefined4 *)((longlong)literal_23e5aa6cccc + uVar28 + 0xc);
          puVar1 = (undefined4 *)(lVar11 + uVar28);
          *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6cccc + uVar28);
          puVar1[1] = uVar5;
          puVar1[2] = uVar6;
          puVar1[3] = uVar7;
          uVar28 = uVar28 + 0x10;
        } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
        if (uVar22 == uVar13) goto LAB_23e5aa217f2;
      }
      do {
        *(wchar_t *)(lVar11 + uVar22 * 2) = literal_23e5aa6cccc[uVar22];
        uVar22 = uVar22 + 1;
      } while (uVar13 != uVar22);
    }
LAB_23e5aa217f2:
    *(uint *)(local_e4 + -4) = uVar19;
    *(undefined2 *)(local_e4 + (ulonglong)uVar19 * 2) = 0;
  }
  lVar11 = MT5_StringToTime((void *)0x23e575eae78,&local_e8);
  MT5_TimeToStruct((void *)0x23e575eae78,lVar10,&local_98);
  MT5_TimeToStruct((void *)0x23e575eae78,lVar11,&local_c0);
  lVar12 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
  MT5_TimeToStruct((void *)0x23e575eae78,lVar12,&local_108);
  iVar15 = local_ec;
  MT5_TimeToStruct((void *)0x23e575eae78,lVar10 - local_80 * 0x15180,&local_108);
  if (local_ec < iVar15) {
    lVar10 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
    MT5_TimeToStruct((void *)0x23e575eae78,lVar10,&local_108);
    iVar15 = local_ec;
    MT5_TimeToStruct((void *)0x23e575eae78,lVar11 - local_a8 * 0x15180,&local_108);
    if (local_ec <= iVar15) goto LAB_23e5aa219b9;
    FUN_23e5aa10000(&local_d0);
    FUN_23e5aa10000(&local_e8);
    if ((bVar9 || (char)local_d8 == '\0') || (DAT_23e5aa79f61 & DAT_23e5aa79f62 & 1) != 0)
    goto LAB_23e5aa21a0f;
    DAT_23e5aa79f61 = 1;
    DAT_23e5aa79f68 = FUN_23e5aa27d20();
    if (DAT_23e5aa79f68 == 999) {
      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
      (*(code *)0x7ff6846d17c0)(0x23e575eae78,2000);
      DAT_23e5aa79f68 = FUN_23e5aa27d20();
      goto LAB_23e5aa21a9e;
    }
LAB_23e5aa21af3:
    DAT_23e5aa79f62 = 1;
    MT5_Dispatch((void *)0x23e575eae78,2,1);
LAB_23e5aa21b23:
    iVar15 = MT5_MQLInfoInteger((void *)0x23e575eae78,6);
    if (iVar15 == 1) goto LAB_23e5aa21b43;
    if (DAT_23e5aa79f68 != 999) {
      lVar10 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
      lVar11 = (longlong)DAT_23e5aa79f68 * 0xe10;
      goto LAB_23e5aa21bac;
    }
    DAT_23e5aa78320 = MT5_TimeGMT((void *)0x23e575eae78,(void *)0x0);
  }
  else {
LAB_23e5aa219b9:
    FUN_23e5aa10000(&local_d0);
    FUN_23e5aa10000(&local_e8);
    if ((!bVar9 && (char)local_d8 != '\0') && (~DAT_23e5aa79f61 & DAT_23e5aa79f62 & 1) == 0) {
      DAT_23e5aa79f61 = 0;
      DAT_23e5aa79f68 = FUN_23e5aa27d20();
      if (DAT_23e5aa79f68 == 999) {
        MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        (*(code *)0x7ff6846d17c0)(0x23e575eae78,2000);
        DAT_23e5aa79f68 = FUN_23e5aa27d20();
LAB_23e5aa21a9e:
        if (DAT_23e5aa79f68 == 999) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        }
      }
      goto LAB_23e5aa21af3;
    }
LAB_23e5aa21a0f:
    if ((char)local_d8 != '\0') goto LAB_23e5aa21b23;
LAB_23e5aa21b43:
    lVar10 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
    lVar11 = (longlong)(DAT_23e5aa79f64 * 0xe10);
LAB_23e5aa21bac:
    DAT_23e5aa78320 = lVar10 - lVar11;
  }
  iVar15 = (*(code *)&MT5_Bars)(0x23e575eae78,&DAT_23e5aa77918,0x4018);
  if (iVar15 != DAT_23e5aa782e4) {
    DAT_23e5aa782e4 = (*(code *)&MT5_Bars)(0x23e575eae78,&DAT_23e5aa77918,0x4018);
    DAT_23e5aa782e0 = '\0';
    DAT_23e5aa78318 = 0.0;
  }
  dVar31 = DAT_23e5aa7a760;
  if (0.0 < DAT_23e5aa7a760) {
    MT5_AccountInfoDouble((void *)0x23e575eae78,0x28);
    dVar30 = DAT_23e5aa7a448;
    MT5_AccountInfoDouble((void *)0x23e575eae78,0x25);
    if ((dVar30 != DAT_23e5aa7a448) || (NAN(dVar30) || NAN(DAT_23e5aa7a448))) {
      MT5_AccountInfoDouble((void *)0x23e575eae78,0x28);
      if (DAT_23e5aa78318 < DAT_23e5aa7a448) {
        MT5_AccountInfoDouble((void *)0x23e575eae78,0x28);
        DAT_23e5aa78318 = DAT_23e5aa7a448;
      }
      bVar9 = MT5_HistorySelect((void *)0x23e575eae78,0,0x7fffffff);
      dVar30 = 0.0;
      if ((bVar9) &&
         (iVar15 = MT5_HistoryDealsTotal((void *)0x23e575eae78), dVar30 = 0.0, -1 < iVar15 + -1)) {
        dVar30 = 0.0;
        do {
          iVar15 = iVar15 + -1;
          uVar13 = MT5_HistoryDealGetTicket((void *)0x23e575eae78,iVar15);
          lVar10 = MT5_HistoryDealGetInteger((void *)0x23e575eae78,uVar13,2);
          lVar11 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,0x4018,0);
          if ((lVar11 <= lVar10) &&
             (lVar10 = MT5_HistoryDealGetInteger((void *)0x23e575eae78,uVar13,4), lVar10 == 1)) {
            MT5_HistoryDealGetDouble((void *)0x23e575eae78,uVar13,9);
            dVar4 = DAT_23e5aa7a448;
            MT5_HistoryDealGetDouble((void *)0x23e575eae78,uVar13,7);
            dVar4 = dVar4 + DAT_23e5aa7a448;
            MT5_HistoryDealGetDouble((void *)0x23e575eae78,uVar13,8);
            dVar30 = dVar30 + dVar4 + DAT_23e5aa7a448;
          }
        } while (0 < iVar15);
      }
      MT5_AccountInfoDouble((void *)0x23e575eae78,0x28);
      dVar4 = DAT_23e5aa7a448;
      MT5_AccountInfoDouble((void *)0x23e575eae78,0x25);
      if ((dVar31 * DAT_23e5aa78318) / DAT_23e5aa5fe20 <
          (double)((ulonglong)((dVar4 - DAT_23e5aa7a448) + dVar30) ^ (ulonglong)DAT_23e5aa5fe10)) {
        if (DAT_23e5aa782e0 == '\0') {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        }
        FUN_23e5aa40010();
        DAT_23e5aa782e0 = '\x01';
        DAT_23e5aa78318 = 0.0;
        return;
      }
    }
  }
  lVar10 = DAT_23e5aa79f78;
  if (DAT_23e5aa782e0 != '\0') {
    return;
  }
  lVar11 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,0x4001,1);
  if (lVar10 != lVar11) {
    DAT_23e5aa79f78 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,0x4001,1);
  }
  if (DAT_23e5aa7a42c == (wchar_t *)0x0) {
    uVar5 = 0xfa9;
    goto LAB_23e5aa21fd7;
  }
  uVar17 = *(uint *)(DAT_23e5aa7a42c + -2);
  if ((uVar17 == 0) || (DAT_23e5aa629f8 == 0)) {
    DAT_23e5aa7a410 = 0x13ab;
    goto LAB_23e5aa2201d;
  }
  pwVar23 = literal_23e5aa629fc;
  if (DAT_23e5aa7a42c == literal_23e5aa629fc) goto LAB_23e5aa223dc;
  if ((uVar17 < DAT_23e5aa629f8) || (uVar16 = (uVar17 - DAT_23e5aa629f8) + 1, uVar16 == 0)) {
LAB_23e5aa2201d:
    if ((uVar17 == 0) || (DAT_23e5aa62a18 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62a1c;
      if (DAT_23e5aa7a42c == literal_23e5aa62a1c) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62a18 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62a18) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62a18 < 2) {
          if (*DAT_23e5aa7a42c == L'x') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa22087;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'x');
          if (pwVar25 < pwVar23) {
LAB_23e5aa22d8c:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'x') {
              pwVar18 = literal_23e5aa62a1c;
              lVar12 = (ulonglong)DAT_23e5aa62a18 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa22d78;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa22d78:
                if (bVar9) goto LAB_23e5aa22d8c;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa22087:
    if ((uVar17 == 0) || (DAT_23e5aa62a38 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62a3c;
      if (DAT_23e5aa7a42c == literal_23e5aa62a3c) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62a38 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62a38) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62a38 < 2) {
          if (*DAT_23e5aa7a42c == L'G') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa220f1;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'G');
          if (pwVar25 < pwVar23) {
LAB_23e5aa22e31:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'G') {
              pwVar18 = literal_23e5aa62a3c;
              lVar12 = (ulonglong)DAT_23e5aa62a38 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa22e1d;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa22e1d:
                if (bVar9) goto LAB_23e5aa22e31;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa220f1:
    if ((uVar17 == 0) || (DAT_23e5aa62a58 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62a5c;
      if (DAT_23e5aa7a42c == literal_23e5aa62a5c) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62a58 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62a58) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62a58 < 2) {
          if (*DAT_23e5aa7a42c == L'g') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa2215b;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'g');
          if (pwVar25 < pwVar23) {
LAB_23e5aa26e03:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'g') {
              pwVar18 = literal_23e5aa62a5c;
              lVar12 = (ulonglong)DAT_23e5aa62a58 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa26def;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa26def:
                if (bVar9) goto LAB_23e5aa26e03;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa2215b:
    if ((uVar17 == 0) || (DAT_23e5aa62a78 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62a7c;
      if (DAT_23e5aa7a42c == literal_23e5aa62a7c) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62a78 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62a78) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62a78 < 2) {
          if (*DAT_23e5aa7a42c == L'G') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa221c5;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'G');
          if (pwVar25 < pwVar23) {
LAB_23e5aa26ea8:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'G') {
              pwVar18 = literal_23e5aa62a7c;
              lVar12 = (ulonglong)DAT_23e5aa62a78 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa26e94;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa26e94:
                if (bVar9) goto LAB_23e5aa26ea8;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa221c5:
    if ((uVar17 == 0) || (DAT_23e5aa62a98 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62a9c;
      if (DAT_23e5aa7a42c == literal_23e5aa62a9c) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62a98 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62a98) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62a98 < 2) {
          if (*DAT_23e5aa7a42c == L'X') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa2222f;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'X');
          if (pwVar25 < pwVar23) {
LAB_23e5aa26f4d:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'X') {
              pwVar18 = literal_23e5aa62a9c;
              lVar12 = (ulonglong)DAT_23e5aa62a98 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa26f39;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa26f39:
                if (bVar9) goto LAB_23e5aa26f4d;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa2222f:
    if ((uVar17 == 0) || (DAT_23e5aa62ab8 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62abc;
      if (DAT_23e5aa7a42c == literal_23e5aa62abc) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62ab8 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62ab8) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62ab8 < 2) {
          if (*DAT_23e5aa7a42c == L'x') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa22299;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'x');
          if (pwVar25 < pwVar23) {
LAB_23e5aa26ff2:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'x') {
              pwVar18 = literal_23e5aa62abc;
              lVar12 = (ulonglong)DAT_23e5aa62ab8 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa26fde;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa26fde:
                if (bVar9) goto LAB_23e5aa26ff2;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa22299:
    if ((uVar17 == 0) || (DAT_23e5aa62ad8 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
    }
    else {
      pwVar23 = literal_23e5aa62adc;
      if (DAT_23e5aa7a42c == literal_23e5aa62adc) goto LAB_23e5aa223dc;
      if ((DAT_23e5aa62ad8 <= uVar17) && (uVar16 = (uVar17 - DAT_23e5aa62ad8) + 1, uVar16 != 0)) {
        pwVar23 = (wchar_t *)(ulonglong)uVar16;
        if (DAT_23e5aa62ad8 < 2) {
          if (*DAT_23e5aa7a42c == L'X') goto LAB_23e5aa223dc;
          pwVar25 = (wchar_t *)0x0;
          do {
            if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa22303;
            lVar12 = (longlong)pwVar25 + 1;
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
          } while (DAT_23e5aa7a42c[lVar12] != L'X');
          if (pwVar25 < pwVar23) {
LAB_23e5aa27097:
            if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
          }
        }
        else {
          bVar9 = true;
          uVar13 = 1;
          pwVar25 = (wchar_t *)0x0;
          do {
            iVar15 = (int)uVar13;
            if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'X') {
              pwVar18 = literal_23e5aa62adc;
              lVar12 = (ulonglong)DAT_23e5aa62ad8 - 1;
              while( true ) {
                pwVar18 = pwVar18 + 1;
                if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
                uVar13 = (ulonglong)((int)uVar13 + 1);
                lVar12 = lVar12 + -1;
                if (lVar12 == 0) goto LAB_23e5aa27083;
              }
              if ((int)lVar12 == 0) {
LAB_23e5aa27083:
                if (bVar9) goto LAB_23e5aa27097;
                break;
              }
            }
            pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
            uVar13 = (ulonglong)(iVar15 + 1);
            bVar9 = pwVar25 < pwVar23;
          } while (pwVar25 != pwVar23);
        }
      }
    }
LAB_23e5aa22303:
    if ((uVar17 == 0) || (DAT_23e5aa62af8 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
      goto LAB_23e5aa22366;
    }
    pwVar23 = (wchar_t *)0x0;
    if (DAT_23e5aa7a42c == literal_23e5aa62afc) goto LAB_23e5aa2236c;
    if ((uVar17 < DAT_23e5aa62af8) || (uVar17 = (uVar17 - DAT_23e5aa62af8) + 1, uVar17 == 0)) {
LAB_23e5aa22366:
      pwVar23 = (wchar_t *)0xffffffff;
    }
    else {
      pwVar25 = (wchar_t *)(ulonglong)uVar17;
      if (1 < DAT_23e5aa62af8) {
        bVar9 = true;
        uVar13 = 1;
        pwVar23 = (wchar_t *)0x0;
        do {
          iVar15 = (int)uVar13;
          if (DAT_23e5aa7a42c[(longlong)pwVar23] == L'x') {
            pwVar18 = literal_23e5aa62afc;
            lVar12 = (ulonglong)DAT_23e5aa62af8 - 1;
            while( true ) {
              pwVar18 = pwVar18 + 1;
              if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
              uVar13 = (ulonglong)((int)uVar13 + 1);
              lVar12 = lVar12 + -1;
              if (lVar12 == 0) goto LAB_23e5aa2715e;
            }
            if ((int)lVar12 == 0) {
LAB_23e5aa2715e:
              if (bVar9) goto LAB_23e5aa2236c;
              break;
            }
          }
          pwVar23 = (wchar_t *)((longlong)pwVar23 + 1);
          uVar13 = (ulonglong)(iVar15 + 1);
          bVar9 = pwVar23 < pwVar25;
        } while (pwVar23 != pwVar25);
        goto LAB_23e5aa22366;
      }
      if (*DAT_23e5aa7a42c != L'x') {
        pwVar23 = (wchar_t *)0x0;
        do {
          if ((wchar_t *)((longlong)pwVar25 - 1U) == pwVar23) goto LAB_23e5aa22366;
          lVar12 = (longlong)pwVar23 + 1;
          pwVar23 = (wchar_t *)((longlong)pwVar23 + 1);
        } while (DAT_23e5aa7a42c[lVar12] != L'x');
        if (pwVar25 <= pwVar23) goto LAB_23e5aa22366;
      }
    }
LAB_23e5aa2236c:
    uVar17 = *(uint *)(DAT_23e5aa7a42c + -2);
    if ((uVar17 == 0) || (DAT_23e5aa62b18 == 0)) {
      DAT_23e5aa7a410 = 0x13ab;
      goto LAB_23e5aa223cd;
    }
    uVar13 = 0;
    if (DAT_23e5aa7a42c == literal_23e5aa62b1c) goto LAB_23e5aa223d3;
    if ((uVar17 < DAT_23e5aa62b18) || (uVar16 = (uVar17 - DAT_23e5aa62b18) + 1, uVar16 == 0)) {
LAB_23e5aa223cd:
      uVar13 = 0xffffffff;
    }
    else {
      uVar22 = (ulonglong)uVar16;
      if (1 < DAT_23e5aa62b18) {
        bVar9 = true;
        uVar28 = 1;
        uVar13 = 0;
        do {
          iVar15 = (int)uVar28;
          if (DAT_23e5aa7a42c[uVar13] == L'G') {
            pwVar25 = literal_23e5aa62b1c;
            lVar12 = (ulonglong)DAT_23e5aa62b18 - 1;
            while( true ) {
              pwVar25 = pwVar25 + 1;
              if (DAT_23e5aa7a42c[uVar28] != *pwVar25) break;
              uVar28 = (ulonglong)((int)uVar28 + 1);
              lVar12 = lVar12 + -1;
              if (lVar12 == 0) goto LAB_23e5aa271ca;
            }
            if ((int)lVar12 == 0) {
LAB_23e5aa271ca:
              if (bVar9) goto LAB_23e5aa223d3;
              break;
            }
          }
          uVar13 = uVar13 + 1;
          uVar28 = (ulonglong)(iVar15 + 1);
          bVar9 = uVar13 < uVar22;
        } while (uVar13 != uVar22);
        goto LAB_23e5aa223cd;
      }
      if (*DAT_23e5aa7a42c != L'G') {
        do {
          if (uVar22 - 1 == uVar13) goto LAB_23e5aa223cd;
          lVar12 = uVar13 + 1;
          uVar13 = uVar13 + 1;
        } while (DAT_23e5aa7a42c[lVar12] != L'G');
        if (uVar22 <= uVar13) goto LAB_23e5aa223cd;
      }
    }
LAB_23e5aa223d3:
    if ((int)((uint)uVar13 & (uint)pwVar23) < 0) {
      uVar5 = 0x13ab;
      if ((uVar17 != 0) && (pwVar23 = (wchar_t *)(ulonglong)DAT_23e5aa62b38, DAT_23e5aa62b38 != 0))
      {
        if (DAT_23e5aa7a42c == literal_23e5aa62b3c) goto LAB_23e5aa223dc;
        uVar5 = DAT_23e5aa7a410;
        if ((DAT_23e5aa62b38 <= uVar17) && (uVar17 = (uVar17 - DAT_23e5aa62b38) + 1, uVar17 != 0)) {
          pwVar25 = (wchar_t *)(ulonglong)uVar17;
          if (DAT_23e5aa62b38 < 2) {
            if (*DAT_23e5aa7a42c == L'g') goto LAB_23e5aa223dc;
            pwVar23 = (wchar_t *)((longlong)pwVar25 - 1);
            pwVar18 = (wchar_t *)0x0;
            do {
              if (pwVar23 == pwVar18) goto LAB_23e5aa21fd7;
              lVar12 = (longlong)pwVar18 + 1;
              pwVar18 = (wchar_t *)((longlong)pwVar18 + 1);
            } while (DAT_23e5aa7a42c[lVar12] != L'g');
            if (pwVar18 < pwVar25) {
LAB_23e5aa27276:
              if (-1 < (int)pwVar18) goto LAB_23e5aa223dc;
            }
          }
          else {
            bVar9 = true;
            uVar13 = 1;
            pwVar18 = (wchar_t *)0x0;
            pwVar23 = (wchar_t *)((longlong)pwVar23 - 1);
            do {
              iVar15 = (int)uVar13;
              if (DAT_23e5aa7a42c[(longlong)pwVar18] == L'g') {
                pwVar29 = literal_23e5aa62b3c;
                pwVar20 = pwVar23;
                while( true ) {
                  pwVar29 = pwVar29 + 1;
                  if (DAT_23e5aa7a42c[uVar13] != *pwVar29) break;
                  uVar13 = (ulonglong)((int)uVar13 + 1);
                  pwVar20 = (wchar_t *)((longlong)pwVar20 - 1);
                  if (pwVar20 == (wchar_t *)0x0) goto LAB_23e5aa27262;
                }
                if ((int)pwVar20 == 0) {
LAB_23e5aa27262:
                  if (bVar9) goto LAB_23e5aa27276;
                  break;
                }
              }
              pwVar18 = (wchar_t *)((longlong)pwVar18 + 1);
              uVar13 = (ulonglong)(iVar15 + 1);
              bVar9 = pwVar18 < pwVar25;
            } while (pwVar18 != pwVar25);
          }
        }
      }
LAB_23e5aa21fd7:
      DAT_23e5aa7a410 = uVar5;
      FUN_23e5aa105c0(&DAT_23e5aa77918,&DAT_23e5aa7a428,1,&PTR_DAT_23e5aa6d748);
      FUN_23e5aa28aa0(0);
      goto LAB_23e5aa26730;
    }
  }
  else {
    pwVar23 = (wchar_t *)(ulonglong)uVar16;
    if (1 < DAT_23e5aa629f8) {
      bVar9 = true;
      uVar13 = 1;
      pwVar25 = (wchar_t *)0x0;
      do {
        iVar15 = (int)uVar13;
        if (DAT_23e5aa7a42c[(longlong)pwVar25] == L'X') {
          pwVar18 = literal_23e5aa629fc;
          lVar12 = (ulonglong)DAT_23e5aa629f8 - 1;
          while( true ) {
            pwVar18 = pwVar18 + 1;
            if (DAT_23e5aa7a42c[uVar13] != *pwVar18) break;
            uVar13 = (ulonglong)((int)uVar13 + 1);
            lVar12 = lVar12 + -1;
            if (lVar12 == 0) goto LAB_23e5aa22cad;
          }
          if ((int)lVar12 == 0) {
LAB_23e5aa22cad:
            if (bVar9) goto LAB_23e5aa22cc1;
            break;
          }
        }
        pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
        uVar13 = (ulonglong)(iVar15 + 1);
        bVar9 = pwVar25 < pwVar23;
      } while (pwVar25 != pwVar23);
      goto LAB_23e5aa2201d;
    }
    if (*DAT_23e5aa7a42c != L'X') {
      pwVar25 = (wchar_t *)0x0;
      do {
        if ((wchar_t *)((longlong)pwVar23 - 1U) == pwVar25) goto LAB_23e5aa2201d;
        lVar12 = (longlong)pwVar25 + 1;
        pwVar25 = (wchar_t *)((longlong)pwVar25 + 1);
      } while (DAT_23e5aa7a42c[lVar12] != L'X');
      if (pwVar25 < pwVar23) {
LAB_23e5aa22cc1:
        if (-1 < (int)pwVar25) goto LAB_23e5aa223dc;
      }
      goto LAB_23e5aa2201d;
    }
  }
LAB_23e5aa223dc:
  FUN_23e5aa105c0(&DAT_23e5aa77918,&DAT_23e5aa7a428,CONCAT71((int7)((ulonglong)pwVar23 >> 8),1),
                  &PTR_DAT_23e5aa6d738);
  if (DAT_23e5aa7a600 != '\0') {
    FUN_23e5aa28790();
  }
  if (DAT_23e5aa7a580 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 4;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 2;
    DAT_23e5aa7228c = 0xa0;
    DAT_23e5aa72290 = 0x4062c00000000000;
    DAT_23e5aa72298 = DAT_23e5aa5fe28 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x4085400000000000;
    DAT_23e5aa722b8 = 0x198;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5fe38 + dVar31;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe68;
      if (DAT_23e5aa7a5f0 <= 0.0) {
        DAT_23e5aa72320 = 500.0;
        dVar31 = DAT_23e5aa5fe70;
        goto LAB_23e5aa22a13;
      }
      dVar30 = 0.0 - DAT_23e5aa7a5f0;
      dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar16 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 + (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      DAT_23e5aa72300 =
           (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      pdVar14 = &DAT_23e5aa5fe78;
      DAT_23e5aa72318 =
           (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a720 + DAT_23e5aa5fe70;
LAB_23e5aa228f5:
      uVar17 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72320 =
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0) + *pdVar14;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72328 =
           (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
           DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa5fe58;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe40;
      if (0.0 < DAT_23e5aa7a5f0) {
        dVar30 = 0.0 - DAT_23e5aa7a5f0;
        dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
        uVar19 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar16 = uVar19 * 0x343fd + 0x269ec3;
        uVar17 = uVar16 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 + (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30
        ;
        DAT_23e5aa72300 =
             (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a718 + DAT_23e5aa5fe48;
        pdVar14 = (double *)&DAT_23e5aa5fe60;
        DAT_23e5aa72318 =
             (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a720 + DAT_23e5aa5fe50;
        goto LAB_23e5aa228f5;
      }
      DAT_23e5aa72320 = 550.0;
      dVar31 = DAT_23e5aa5fe50;
LAB_23e5aa22a13:
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + dVar31;
      DAT_23e5aa72328 = DAT_23e5aa5fe58;
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 2;
    DAT_23e5aa7235c = 3;
    DAT_23e5aa72360 = 800;
    DAT_23e5aa72368 = 0x4034000000000000;
    DAT_23e5aa72180 = 0x403a000000000000;
    DAT_23e5aa721c4 = 0x35;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa71510);
      uVar17 = DAT_23e5aa6c548;
      uVar13 = (ulonglong)DAT_23e5aa6c548;
      if ((DAT_23e5aa6c548 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c548 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa272e3;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c54cU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c54c + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c54c + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c54c + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c54c + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa22eb5;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c54c[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa22eb5:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa71520);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 1;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5fe80);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(0);
    FUN_23e5aa28aa0(0);
    if (lVar10 != lVar11) {
      DAT_23e5aa79f80 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79f80 != 0.0) || (NAN(DAT_23e5aa79f80))) && (0 < DAT_23e5aa77940)) {
        DAT_23e5aa77ad0 = DAT_23e5aa79f80 / (double)DAT_23e5aa77940;
      }
    }
  }
  if (DAT_23e5aa7a588 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 8;
    DAT_23e5aa7227c = 0x4004;
    DAT_23e5aa72288 = 10;
    DAT_23e5aa7228c = 0x96;
    DAT_23e5aa72290 = 0x4082c00000000000;
    DAT_23e5aa72298 = DAT_23e5aa5fe88 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x406cc00000000000;
    DAT_23e5aa722b8 = 0x180;
    DAT_23e5aa722ec = 5;
    DAT_23e5aa722f0 = 0;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5fe90 + dVar31;
    DAT_23e5aa72328 = DAT_23e5aa5fe98;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5feb0;
      if (0.0 < DAT_23e5aa7a5f0) {
        dVar30 = 0.0 - DAT_23e5aa7a5f0;
        dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
        uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar16 = uVar17 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 + (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30
        ;
        uVar19 = uVar16 * 0x343fd + 0x269ec3;
        uVar17 = uVar19 * 0x343fd + 0x269ec3;
        DAT_23e5aa72300 =
             (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a718 + DAT_23e5aa5fea0;
        DAT_23e5aa72318 =
             (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a720 + DAT_23e5aa5fea8;
        dVar30 = (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
        goto LAB_23e5aa234dc;
      }
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fea0;
      DAT_23e5aa72320 = 100.0;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fea8;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe98;
      if (DAT_23e5aa7a5f0 <= 0.0) {
        DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fea0;
        DAT_23e5aa72320 = 100.0;
        DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fea8;
      }
      else {
        dVar30 = 0.0 - DAT_23e5aa7a5f0;
        dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
        uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar16 = uVar17 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 + (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30
        ;
        uVar19 = uVar16 * 0x343fd + 0x269ec3;
        uVar17 = uVar19 * 0x343fd + 0x269ec3;
        DAT_23e5aa72300 =
             (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a718 + DAT_23e5aa5fea0;
        DAT_23e5aa72318 =
             (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a720 + DAT_23e5aa5fea8;
        dVar30 = (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
LAB_23e5aa234dc:
        DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
        DAT_23e5aa72320 = dVar30 + DAT_23e5aa5fe20;
        DAT_23e5aa72328 =
             (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
             DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa5fe98;
      }
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 3;
    DAT_23e5aa7235c = 3;
    DAT_23e5aa72360 = 400;
    DAT_23e5aa72368 = 0x4034000000000000;
    DAT_23e5aa72180 = 0x4039800000000000;
    DAT_23e5aa721c4 = 0x61;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa71530);
      uVar17 = DAT_23e5aa6c568;
      uVar13 = (ulonglong)DAT_23e5aa6c568;
      if ((DAT_23e5aa6c568 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c568 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa27303;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c56cU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c56c + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c56c + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c56c + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c56c + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa237cf;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c56c[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa237cf:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa71540);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 2;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5feb8);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(1);
    FUN_23e5aa28aa0(1);
    if (lVar10 != lVar11) {
      DAT_23e5aa79f88 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79f88 != 0.0) || (NAN(DAT_23e5aa79f88))) && (0 < DAT_23e5aa77944)) {
        DAT_23e5aa77ad8 = DAT_23e5aa79f88 / (double)DAT_23e5aa77944;
      }
    }
  }
  if (DAT_23e5aa7a590 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 0x12;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 3;
    DAT_23e5aa7228c = 0xb4;
    DAT_23e5aa72290 = 0x408c200000000000;
    DAT_23e5aa72298 = DAT_23e5aa5fe90 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x408ea00000000000;
    DAT_23e5aa722b8 = 0x198;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5fec0 + dVar31;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fed8;
      if (DAT_23e5aa7a5f0 <= 0.0) goto LAB_23e5aa23dd1;
      uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 +
           (double)(uVar16 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      DAT_23e5aa72300 =
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa7a718 + DAT_23e5aa5fec8;
LAB_23e5aa23c7b:
      dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
      dVar30 = 0.0 - DAT_23e5aa7a5f0;
      uVar16 = uVar17 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72318 =
           (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a720 + DAT_23e5aa5fed0;
      DAT_23e5aa72320 =
           (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 + DAT_23e5aa5fe50;
      DAT_23e5aa72328 =
           (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa5fe58;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fec8;
      if (0.0 < DAT_23e5aa7a5f0) {
        uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar17 = uVar16 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 +
             (double)(uVar16 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
             DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
        DAT_23e5aa72300 =
             (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
             DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa7a718 + DAT_23e5aa5fec8;
        goto LAB_23e5aa23c7b;
      }
LAB_23e5aa23dd1:
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fec8;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fed0;
      DAT_23e5aa72320 = 600.0;
      DAT_23e5aa72328 = DAT_23e5aa5fe58;
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 1;
    DAT_23e5aa7235c = 6;
    DAT_23e5aa72360 = 700;
    DAT_23e5aa72368 = 0x4014000000000000;
    DAT_23e5aa721c4 = 0x3a;
    DAT_23e5aa72180 = 0x4042c00000000000;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa71550);
      uVar17 = DAT_23e5aa6c588;
      uVar13 = (ulonglong)DAT_23e5aa6c588;
      if ((DAT_23e5aa6c588 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c588 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa27323;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c58cU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c58c + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c58c + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c58c + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c58c + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa23fea;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c58c[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa23fea:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa71560);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 3;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5fee0);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(2);
    FUN_23e5aa28aa0(2);
    if (lVar10 != lVar11) {
      DAT_23e5aa79f90 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79f90 != 0.0) || (NAN(DAT_23e5aa79f90))) && (0 < DAT_23e5aa77948)) {
        DAT_23e5aa77ae0 = DAT_23e5aa79f90 / (double)DAT_23e5aa77948;
      }
    }
  }
  if (DAT_23e5aa7a598 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 4;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 2;
    DAT_23e5aa7228c = 0xf0;
    DAT_23e5aa72290 = 0x408c200000000000;
    DAT_23e5aa72298 = DAT_23e5aa5fee8 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x4085400000000000;
    DAT_23e5aa722b8 = 0x30;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5fe90 + dVar31;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe68;
      if (DAT_23e5aa7a5f0 <= 0.0) goto LAB_23e5aa24495;
LAB_23e5aa242e4:
      dVar30 = 0.0 - DAT_23e5aa7a5f0;
      dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
      uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      uVar27 = uVar17 * 0x343fd + 0x269ec3;
      uVar19 = uVar27 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar19 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 + (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
      DAT_23e5aa72300 =
           (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      DAT_23e5aa72318 =
           (double)(uVar27 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a720 + DAT_23e5aa5fe70;
      DAT_23e5aa72320 =
           (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 + DAT_23e5aa5fe78;
      DAT_23e5aa72328 =
           (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa5fe58;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe98;
      if (0.0 < DAT_23e5aa7a5f0) goto LAB_23e5aa242e4;
LAB_23e5aa24495:
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      DAT_23e5aa72320 = 500.0;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe70;
      DAT_23e5aa72328 = DAT_23e5aa5fe58;
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 5;
    DAT_23e5aa7235c = 6;
    DAT_23e5aa72360 = 100;
    DAT_23e5aa72368 = 0;
    DAT_23e5aa72180 = 0x4041400000000000;
    DAT_23e5aa721c4 = 0x2f;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa71570);
      uVar17 = DAT_23e5aa6c5a8;
      uVar13 = (ulonglong)DAT_23e5aa6c5a8;
      if ((DAT_23e5aa6c5a8 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c5a8 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa27343;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c5acU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c5ac + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c5ac + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c5ac + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c5ac + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa246f4;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c5ac[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa246f4:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa71580);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 4;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5fef0);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(3);
    FUN_23e5aa28aa0(3);
    if (lVar10 != lVar11) {
      DAT_23e5aa79f98 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79f98 != 0.0) || (NAN(DAT_23e5aa79f98))) && (0 < DAT_23e5aa7794c)) {
        DAT_23e5aa77ae8 = DAT_23e5aa79f98 / (double)DAT_23e5aa7794c;
      }
    }
  }
  if (DAT_23e5aa7a5a0 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 0xf;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 3;
    DAT_23e5aa7228c = 0xe6;
    DAT_23e5aa72290 = 0x4081300000000000;
    DAT_23e5aa72298 = DAT_23e5aa5fef8 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x407e000000000000;
    DAT_23e5aa722b8 = 0x1e0;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5ff00 + dVar31;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe50;
      if (DAT_23e5aa7a5f0 <= 0.0) goto LAB_23e5aa24b8e;
LAB_23e5aa249dd:
      dVar30 = 0.0 - DAT_23e5aa7a5f0;
      dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
      uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      uVar27 = uVar17 * 0x343fd + 0x269ec3;
      uVar19 = uVar27 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar19 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 + (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
      DAT_23e5aa72300 =
           (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      DAT_23e5aa72318 =
           (double)(uVar27 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a720 + DAT_23e5aa5fe78;
      DAT_23e5aa72320 =
           (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 + DAT_23e5aa5ff10;
      DAT_23e5aa72328 =
           (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa5fe58;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5ff08;
      if (0.0 < DAT_23e5aa7a5f0) goto LAB_23e5aa249dd;
LAB_23e5aa24b8e:
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fe48;
      DAT_23e5aa72320 = 300.0;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe78;
      DAT_23e5aa72328 = DAT_23e5aa5fe58;
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 1;
    DAT_23e5aa7235c = 4;
    DAT_23e5aa72360 = 600;
    DAT_23e5aa72368 = 0x4018000000000000;
    DAT_23e5aa721c4 = 100;
    DAT_23e5aa72180 = 0x403c000000000000;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      local_a0 = lVar10;
      uVar22 = 0;
      local_d8 = lVar11;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa71590);
      uVar17 = DAT_23e5aa6c5c8;
      uVar13 = (ulonglong)DAT_23e5aa6c5c8;
      if ((DAT_23e5aa6c5c8 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c5c8 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa27363;
        if (uVar17 != 0) {
          lVar10 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar10 - 0x23e5aa6c5ccU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c5cc + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c5cc + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c5cc + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar10 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c5cc + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa24e05;
          }
          do {
            *(wchar_t *)(lVar10 + uVar22 * 2) = literal_23e5aa6c5cc[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa24e05:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa715a0);
      lVar10 = local_a0;
      lVar11 = local_d8;
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 5;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5ff18);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(4);
    FUN_23e5aa28aa0(4);
    if (lVar10 != lVar11) {
      DAT_23e5aa79fa0 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79fa0 != 0.0) || (NAN(DAT_23e5aa79fa0))) && (0 < DAT_23e5aa77950)) {
        DAT_23e5aa77af0 = DAT_23e5aa79fa0 / (double)DAT_23e5aa77950;
      }
    }
  }
  if (DAT_23e5aa7a5a8 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 0xc;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 2;
    DAT_23e5aa7228c = 0x32;
    DAT_23e5aa72290 = 0x4085e00000000000;
    DAT_23e5aa72298 = DAT_23e5aa5ff20 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x403e000000000000;
    DAT_23e5aa722b8 = 0x180;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5ff00 + dVar31;
    DAT_23e5aa72328 = DAT_23e5aa5feb0;
    if (DAT_23e5aa7a5d0 == '\0') {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5feb0;
      if (0.0 < DAT_23e5aa7a5f0) {
        dVar30 = 0.0 - DAT_23e5aa7a5f0;
        dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
        uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar16 = uVar17 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 + (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30
        ;
        uVar19 = uVar16 * 0x343fd + 0x269ec3;
        uVar17 = uVar19 * 0x343fd + 0x269ec3;
        DAT_23e5aa72300 =
             (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a718 + DAT_23e5aa5ff28;
        DAT_23e5aa72318 =
             (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a720 + DAT_23e5aa5fe50;
        dVar30 = (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
        goto LAB_23e5aa2542d;
      }
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5ff28;
      DAT_23e5aa72320 = 500.0;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe50;
    }
    else {
      DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe98;
      if (DAT_23e5aa7a5f0 <= 0.0) {
        DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5ff28;
        DAT_23e5aa72320 = 500.0;
        DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe50;
      }
      else {
        dVar30 = 0.0 - DAT_23e5aa7a5f0;
        dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
        uVar19 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
        uVar16 = uVar19 * 0x343fd + 0x269ec3;
        uVar27 = uVar16 * 0x343fd + 0x269ec3;
        uVar17 = uVar27 * 0x343fd + 0x269ec3;
        DAT_23e5aa722f8 =
             DAT_23e5aa722f8 + (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30
        ;
        DAT_23e5aa72300 =
             (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a718 + DAT_23e5aa5ff28;
        DAT_23e5aa72318 =
             (double)(uVar27 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
             DAT_23e5aa7a720 + DAT_23e5aa5fe50;
        dVar30 = (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
LAB_23e5aa2542d:
        DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
        DAT_23e5aa72320 = dVar30 + DAT_23e5aa5fe78;
        DAT_23e5aa72328 =
             (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
             DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa5feb0;
      }
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 1;
    DAT_23e5aa7235c = 2;
    DAT_23e5aa72360 = 300;
    DAT_23e5aa72368 = 0;
    DAT_23e5aa72180 = 0x4040800000000000;
    DAT_23e5aa721c4 = 99;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa715b0);
      uVar17 = DAT_23e5aa6c5e8;
      uVar13 = (ulonglong)DAT_23e5aa6c5e8;
      if ((DAT_23e5aa6c5e8 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c5e8 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa27383;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c5ecU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c5ec + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c5ec + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c5ec + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c5ec + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa25721;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c5ec[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa25721:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa715c0);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 6;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5ff30);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(5);
    FUN_23e5aa28aa0(5);
    if (lVar10 != lVar11) {
      DAT_23e5aa79fa8 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79fa8 != 0.0) || (NAN(DAT_23e5aa79fa8))) && (0 < DAT_23e5aa77954)) {
        DAT_23e5aa77af8 = DAT_23e5aa79fa8 / (double)DAT_23e5aa77954;
      }
    }
  }
  if (DAT_23e5aa7a5b0 != '\0') {
    dVar31 = 0.0;
    local_108 = 0;
    local_104 = 0;
    DAT_23e5aa72280 = 1;
    DAT_23e5aa72284 = 0x11;
    DAT_23e5aa7227c = 0x4018;
    DAT_23e5aa72288 = 2;
    DAT_23e5aa7228c = 0x6e;
    DAT_23e5aa72290 = 0x4062c00000000000;
    DAT_23e5aa72298 = DAT_23e5aa5ff38 + DAT_23e5aa7a708;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
      DAT_23e5aa72298 =
           DAT_23e5aa72298 +
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
               DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
    }
    DAT_23e5aa722a8 = 1;
    DAT_23e5aa722b0 = 0x4071800000000000;
    DAT_23e5aa722b8 = 0xf0;
    DAT_23e5aa722ec = 1;
    DAT_23e5aa722f0 = 1;
    DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5fe28 + dVar31;
    DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fed8;
    if (DAT_23e5aa7a5f0 <= 0.0) {
      DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5fe98;
      DAT_23e5aa72320 = 200.0;
      DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe50;
      DAT_23e5aa72328 = DAT_23e5aa5ff40;
    }
    else {
      dVar30 = 0.0 - DAT_23e5aa7a5f0;
      dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
      uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      uVar27 = uVar17 * 0x343fd + 0x269ec3;
      uVar19 = uVar27 * 0x343fd + 0x269ec3;
      DAT_23e5aa7a478 = uVar19 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 + (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30;
      DAT_23e5aa72300 =
           (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a718 + DAT_23e5aa5fe98;
      DAT_23e5aa72318 =
           (double)(uVar27 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa7a720 + DAT_23e5aa5fe50;
      DAT_23e5aa72320 =
           (double)(uVar19 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 + DAT_23e5aa5fe58;
      DAT_23e5aa72328 =
           (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
           DAT_23e5aa5ff40;
    }
    DAT_23e5aa72330 = 0x3fb999999999999a;
    DAT_23e5aa72354 = 1;
    DAT_23e5aa72355 = 1;
    DAT_23e5aa72358 = 5;
    DAT_23e5aa7235c = 2;
    DAT_23e5aa72360 = 100;
    DAT_23e5aa72368 = 0x402c000000000000;
    DAT_23e5aa721c4 = 0x5f;
    DAT_23e5aa72180 = 0x403b800000000000;
    DAT_23e5aa721c8 = 1;
    if (DAT_23e5aa7a628 == '\0') {
      uVar22 = 0;
      FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa715d0);
      uVar17 = DAT_23e5aa6c608;
      uVar13 = (ulonglong)DAT_23e5aa6c608;
      if ((DAT_23e5aa6c608 != 0) || (local_104 == 0)) {
        if (local_104 != 0) {
          uVar22 = (ulonglong)*(uint *)(local_104 + -4);
        }
        uVar19 = DAT_23e5aa6c608 + (int)uVar22;
        uVar16 = 0x104;
        if ((0x103 < uVar19) &&
           ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
          uVar16 = 0x7ffffffe;
        }
        cVar8 = FUN_23e5aa10060(&local_108,uVar16);
        if (cVar8 == '\0') goto LAB_23e5aa273a3;
        if (uVar17 != 0) {
          lVar12 = local_104 + uVar22 * 2;
          if (uVar17 < 0x10) {
            uVar22 = 0;
          }
          else if (lVar12 - 0x23e5aa6c60cU < 0x20) {
            uVar22 = 0;
          }
          else {
            uVar28 = 0;
            uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
            do {
              uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c60c + uVar28 + 4);
              uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c60c + uVar28 + 8);
              uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c60c + uVar28 + 0xc);
              puVar1 = (undefined4 *)(lVar12 + uVar28);
              *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c60c + uVar28);
              puVar1[1] = uVar5;
              puVar1[2] = uVar6;
              puVar1[3] = uVar7;
              uVar28 = uVar28 + 0x10;
            } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
            if (uVar22 == uVar13) goto LAB_23e5aa25e01;
          }
          do {
            *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c60c[uVar22];
            uVar22 = uVar22 + 1;
          } while (uVar13 != uVar22);
        }
LAB_23e5aa25e01:
        *(uint *)(local_104 + -4) = uVar19;
        *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
      }
      FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa715e0);
    }
    DAT_23e5aa7246c = DAT_23e5aa7a610 + 7;
    DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5ff48);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa17500(6);
    FUN_23e5aa28aa0(6);
    if (lVar10 != lVar11) {
      DAT_23e5aa79fb0 = (double)FUN_23e5aa2efa0();
      if (((DAT_23e5aa79fb0 != 0.0) || (NAN(DAT_23e5aa79fb0))) && (0 < DAT_23e5aa77958)) {
        DAT_23e5aa77b00 = DAT_23e5aa79fb0 / (double)DAT_23e5aa77958;
      }
    }
  }
  if (DAT_23e5aa7a5b8 == '\0') goto LAB_23e5aa26730;
  dVar31 = 0.0;
  local_108 = 0;
  local_104 = 0;
  DAT_23e5aa72280 = 1;
  DAT_23e5aa72284 = 7;
  DAT_23e5aa7227c = 0x4018;
  DAT_23e5aa72288 = 2;
  DAT_23e5aa7228c = 0x14;
  DAT_23e5aa72290 = 0x406f400000000000;
  DAT_23e5aa72298 = DAT_23e5aa5fe90 + DAT_23e5aa7a708;
  if (0.0 < DAT_23e5aa7a5f0) {
    uVar17 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
    DAT_23e5aa7a478 = uVar17 * 0x343fd + 0x269ec3;
    DAT_23e5aa72298 =
         DAT_23e5aa72298 +
         (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30 +
         (0.0 - DAT_23e5aa7a5f0);
    dVar31 = (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) *
             DAT_23e5aa5fe30 + (0.0 - DAT_23e5aa7a5f0);
  }
  DAT_23e5aa722a8 = 1;
  DAT_23e5aa722b0 = 0x408ea00000000000;
  DAT_23e5aa722b8 = 0x1b0;
  DAT_23e5aa722ec = 1;
  DAT_23e5aa722f0 = 1;
  DAT_23e5aa722a0 = DAT_23e5aa7a708 + DAT_23e5aa5ff50 + dVar31;
  if (DAT_23e5aa7a5d0 == '\0') {
    DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5fe50;
    if (DAT_23e5aa7a5f0 <= 0.0) goto LAB_23e5aa26432;
    uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
    uVar17 = uVar16 * 0x343fd + 0x269ec3;
    DAT_23e5aa722f8 =
         DAT_23e5aa722f8 +
         (double)(uVar16 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30 +
         (0.0 - DAT_23e5aa7a5f0);
    DAT_23e5aa72300 =
         (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30 +
         (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa7a718 + DAT_23e5aa5ff60;
LAB_23e5aa262f2:
    uVar17 = uVar17 * 0x343fd + 0x269ec3;
    dVar31 = DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0;
    dVar30 = 0.0 - DAT_23e5aa7a5f0;
    uVar16 = uVar17 * 0x343fd + 0x269ec3;
    DAT_23e5aa7a478 = uVar16 * 0x343fd + 0x269ec3;
    DAT_23e5aa72318 =
         (double)(uVar17 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
         DAT_23e5aa7a720 + DAT_23e5aa5fe50;
    DAT_23e5aa72320 =
         (double)(uVar16 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 + DAT_23e5aa5ff70;
    DAT_23e5aa72328 =
         (double)(DAT_23e5aa7a478 >> 0x10 & 0x7fff) * dVar31 * DAT_23e5aa5fe30 + dVar30 +
         DAT_23e5aa5ff68;
  }
  else {
    DAT_23e5aa722f8 = DAT_23e5aa7a710 + DAT_23e5aa5ff58;
    if (0.0 < DAT_23e5aa7a5f0) {
      uVar16 = DAT_23e5aa7a478 * 0x343fd + 0x269ec3;
      uVar17 = uVar16 * 0x343fd + 0x269ec3;
      DAT_23e5aa722f8 =
           DAT_23e5aa722f8 +
           (double)(uVar16 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0);
      DAT_23e5aa72300 =
           (double)(uVar17 >> 0x10 & 0x7fff) * (DAT_23e5aa7a5f0 + DAT_23e5aa7a5f0) * DAT_23e5aa5fe30
           + (0.0 - DAT_23e5aa7a5f0) + DAT_23e5aa7a718 + DAT_23e5aa5ff60;
      goto LAB_23e5aa262f2;
    }
LAB_23e5aa26432:
    DAT_23e5aa72300 = DAT_23e5aa7a718 + DAT_23e5aa5ff60;
    DAT_23e5aa72318 = DAT_23e5aa7a720 + DAT_23e5aa5fe50;
    DAT_23e5aa72320 = 350.0;
    DAT_23e5aa72328 = DAT_23e5aa5ff68;
  }
  DAT_23e5aa72330 = 0x3fb999999999999a;
  DAT_23e5aa72354 = 1;
  DAT_23e5aa72355 = 1;
  DAT_23e5aa72358 = 0x11;
  DAT_23e5aa7235c = 1;
  DAT_23e5aa72360 = 100;
  DAT_23e5aa72368 = 0x4043000000000000;
  DAT_23e5aa721c4 = 0x91;
  DAT_23e5aa72180 = 0x4036000000000000;
  DAT_23e5aa721c8 = 1;
  if (DAT_23e5aa7a628 == '\0') {
    uVar22 = 0;
    FUN_23e5aa105c0(&local_108,&DAT_23e5aa7a618,0,&PTR_DAT_23e5aa715f0);
    uVar17 = DAT_23e5aa6c628;
    uVar13 = (ulonglong)DAT_23e5aa6c628;
    if ((DAT_23e5aa6c628 != 0) || (local_104 == 0)) {
      if (local_104 != 0) {
        uVar22 = (ulonglong)*(uint *)(local_104 + -4);
      }
      uVar19 = DAT_23e5aa6c628 + (int)uVar22;
      uVar16 = 0x104;
      if ((0x103 < uVar19) &&
         ((0x7ffffffd < uVar19 || (uVar16 = (uVar19 >> 2) + uVar19, 0x7ffffffd < uVar16)))) {
        uVar16 = 0x7ffffffe;
      }
      cVar8 = FUN_23e5aa10060(&local_108,uVar16);
      if (cVar8 == '\0') {
LAB_23e5aa273c3:
        (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x1e31c4000001f9);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      if (uVar17 != 0) {
        lVar12 = local_104 + uVar22 * 2;
        if (uVar17 < 0x10) {
          uVar22 = 0;
        }
        else if (lVar12 - 0x23e5aa6c62cU < 0x20) {
          uVar22 = 0;
        }
        else {
          uVar28 = 0;
          uVar22 = (ulonglong)(uVar17 & 0xfffffff8);
          do {
            uVar5 = *(undefined4 *)((longlong)literal_23e5aa6c62c + uVar28 + 4);
            uVar6 = *(undefined4 *)((longlong)literal_23e5aa6c62c + uVar28 + 8);
            uVar7 = *(undefined4 *)((longlong)literal_23e5aa6c62c + uVar28 + 0xc);
            puVar1 = (undefined4 *)(lVar12 + uVar28);
            *puVar1 = *(undefined4 *)((longlong)literal_23e5aa6c62c + uVar28);
            puVar1[1] = uVar5;
            puVar1[2] = uVar6;
            puVar1[3] = uVar7;
            uVar28 = uVar28 + 0x10;
          } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
          if (uVar22 == uVar13) goto LAB_23e5aa26643;
        }
        do {
          *(wchar_t *)(lVar12 + uVar22 * 2) = literal_23e5aa6c62c[uVar22];
          uVar22 = uVar22 + 1;
        } while (uVar13 != uVar22);
      }
LAB_23e5aa26643:
      *(uint *)(local_104 + -4) = uVar19;
      *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
    }
    FUN_23e5aa105c0(&DAT_23e5aa72470,&local_108,0,&PTR_DAT_23e5aa71600);
  }
  DAT_23e5aa7246c = DAT_23e5aa7a610 + 8;
  DAT_23e5aa79f70 = FUN_23e5aa57d20((int)DAT_23e5aa5fef0);
  FUN_23e5aa10000(&local_108);
  FUN_23e5aa17500(7);
  FUN_23e5aa28aa0(7);
  if (lVar10 != lVar11) {
    DAT_23e5aa79fb8 = (double)FUN_23e5aa2efa0();
    if (((DAT_23e5aa79fb8 != 0.0) || (NAN(DAT_23e5aa79fb8))) && (0 < DAT_23e5aa7795c)) {
      DAT_23e5aa77b08 = DAT_23e5aa79fb8 / (double)DAT_23e5aa7795c;
    }
  }
LAB_23e5aa26730:
  FUN_23e5aa1e1b0();
  lVar10 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,5,1);
  if (lVar10 != DAT_23e5aa78308) {
    ppuVar24 = (undefined **)0x0;
    DAT_23e5aa78308 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa617c0,5,1);
    local_108 = 0;
    local_98 = 0;
    local_c0 = 0;
    local_104 = 0;
    local_94 = 0;
    local_bc = 0;
    if ((DAT_23e5aa7a528 != '\0') &&
       ((iVar15 = MT5_MQLInfoInteger((void *)0x23e575eae78,6), dVar31 = DAT_23e5aa5fe20, iVar15 != 1
        || (DAT_23e5aa7a530 != '\0')))) {
      local_c0 = 0;
      local_bc = 0;
      uVar17 = (uint)DAT_23e5aa77930 << 2;
      lVar10 = 0;
      do {
        local_d8 = lVar10 + 1;
        MT5_IntegerToString((void *)0x23e575eae78,local_d8,0,
                            (int)CONCAT62((int6)((ulonglong)ppuVar24 >> 0x10),0x20));
        FUN_23e5aa105c0(&local_98,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa705a0);
        FUN_23e5aa105c0(&local_108,&string_ref_23e5aa6b480,0);
        lVar11 = local_94;
        if (local_94 != 0) {
          uVar16 = *(uint *)(local_94 + -4);
          uVar13 = (ulonglong)uVar16;
          if ((uVar16 != 0) || (local_104 == 0)) {
            if (local_104 == 0) {
              uVar22 = 0;
              uVar19 = uVar16;
            }
            else {
              uVar22 = (ulonglong)*(uint *)(local_104 + -4);
              uVar19 = uVar16 + *(uint *)(local_104 + -4);
            }
            cVar8 = FUN_23e5aa10060(&local_108);
            if (cVar8 == '\0') {
              (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x182bf3000001f9);
              goto LAB_23e5aa272a3;
            }
            if (uVar16 != 0) {
              lVar12 = local_104 + uVar22 * 2;
              if (uVar16 < 8) {
                uVar22 = 0;
              }
              else if ((ulonglong)(lVar12 - lVar11) < 0x20) {
                uVar22 = 0;
              }
              else {
                uVar28 = 0;
                uVar22 = (ulonglong)(uVar16 & 0xfffffff8);
                do {
                  puVar1 = (undefined4 *)(lVar11 + uVar28);
                  uVar5 = puVar1[1];
                  uVar6 = puVar1[2];
                  uVar7 = puVar1[3];
                  puVar2 = (undefined4 *)(lVar12 + uVar28);
                  *puVar2 = *puVar1;
                  puVar2[1] = uVar5;
                  puVar2[2] = uVar6;
                  puVar2[3] = uVar7;
                  uVar28 = uVar28 + 0x10;
                } while ((uVar13 * 2 & 0xfffffffffffffff0) != uVar28);
                if (uVar22 == uVar13) goto LAB_23e5aa26a72;
              }
              do {
                *(undefined2 *)(lVar12 + uVar22 * 2) = *(undefined2 *)(lVar11 + uVar22 * 2);
                uVar22 = uVar22 + 1;
              } while (uVar13 != uVar22);
            }
LAB_23e5aa26a72:
            *(uint *)(local_104 + -4) = uVar19;
            *(undefined2 *)(local_104 + (ulonglong)uVar19 * 2) = 0;
          }
        }
        FUN_23e5aa105c0(&local_c0,&local_108,0,&PTR_DAT_23e5aa705c0);
        FUN_23e5aa105c0(&local_98,&local_c0,0,&PTR_DAT_23e5aa705d0);
        FUN_23e5aa57740(uVar17,&local_98);
        dVar30 = (&DAT_23e5aa79f80)[lVar10];
        if ((longlong)dVar30 != -0x8000000000000000) {
          dVar4 = (double)(longlong)dVar30;
          dVar30 = (double)(longlong)
                           ((dVar30 - dVar4) * dVar31 +
                           *(double *)(&DAT_23e5aa5ff78 + (ulonglong)(0.0 < dVar30) * 8)) / dVar31 +
                   dVar4;
        }
        MT5_DoubleToString((void *)0x23e575eae78,dVar30,2);
        FUN_23e5aa105c0(&local_98,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa705e0);
        FUN_23e5aa105c0(&local_c0,&local_98,0,&PTR_DAT_23e5aa705f0);
        FUN_23e5aa105c0(&local_98,&local_c0,0,&PTR_DAT_23e5aa70600);
        FUN_23e5aa57740(uVar17 | 1,&local_98);
        dVar30 = (&DAT_23e5aa77ad0)[lVar10];
        if ((longlong)dVar30 != -0x8000000000000000) {
          dVar4 = (double)(longlong)dVar30;
          dVar30 = (double)(longlong)
                           ((dVar30 - dVar4) * dVar31 +
                           *(double *)(&DAT_23e5aa5ff78 + (ulonglong)(0.0 < dVar30) * 8)) / dVar31 +
                   dVar4;
        }
        MT5_DoubleToString((void *)0x23e575eae78,dVar30,2);
        FUN_23e5aa105c0(&local_98,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa70610);
        FUN_23e5aa105c0(&local_c0,&local_98,0,&PTR_DAT_23e5aa70620);
        FUN_23e5aa105c0(&local_98,&local_c0,0,&PTR_DAT_23e5aa70630);
        FUN_23e5aa57740(uVar17 | 2,&local_98);
        dVar30 = (double)(&DAT_23e5aa76a80)[lVar10];
        if ((longlong)dVar30 != -0x8000000000000000) {
          dVar4 = (double)(longlong)dVar30;
          dVar30 = (double)(longlong)
                           ((dVar30 - dVar4) * dVar31 +
                           *(double *)(&DAT_23e5aa5ff78 + (ulonglong)(0.0 < dVar30) * 8)) / dVar31 +
                   dVar4;
        }
        MT5_DoubleToString((void *)0x23e575eae78,dVar30,2);
        FUN_23e5aa105c0(&local_98,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa70640);
        FUN_23e5aa105c0(&local_c0,&local_98,0,&PTR_DAT_23e5aa70650);
        ppuVar24 = &PTR_DAT_23e5aa70660;
        FUN_23e5aa105c0(&local_98,&local_c0,0,&PTR_DAT_23e5aa70660);
        FUN_23e5aa57740(uVar17 | 3,&local_98);
        uVar17 = uVar17 + 4;
        lVar10 = local_d8;
      } while (local_d8 != 8);
      FUN_23e5aa10000(&local_c0);
    }
    FUN_23e5aa10000(&local_98);
    FUN_23e5aa10000(&local_108);
    FUN_23e5aa1ffb0();
  }
  DAT_23e5aa78310 = DAT_23e5aa78310 + 1;
  if (1 < DAT_23e5aa78310) {
    MT5_AccountInfoDouble((void *)0x23e575eae78,0x25);
    DAT_23e5aa78310 = 0;
    DAT_23e5aa77480 = DAT_23e5aa7a448;
  }
  return;
}



