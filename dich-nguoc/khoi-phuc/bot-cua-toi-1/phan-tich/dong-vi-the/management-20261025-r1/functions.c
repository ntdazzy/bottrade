// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:17101
/* Address: 23e5aa371f0 */

/* WARNING: Removing unreachable block (ram,0x023e5aa37cce) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

ulonglong FUN_23e5aa371f0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  bool bVar7;
  char cVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  code *pcVar16;
  char unaff_R12B;
  ulonglong uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  undefined4 local_158;
  undefined8 local_154;
  undefined8 local_148;
  undefined4 local_13c;
  undefined4 local_138;
  undefined8 local_134;
  longlong local_128;
  undefined4 local_120;
  longlong local_11c;
  double local_110;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  int local_ec;
  
  local_138 = 0;
  local_f8 = 0;
  local_158 = 0;
  local_108 = 0;
  local_120 = 0;
  local_134 = 0;
  local_f4 = 0;
  local_154 = 0;
  local_104 = 0;
  local_11c = 0;
  iVar10 = MT5_PositionsTotal((void *)0x23e575eae78);
  cVar9 = DAT_23e5aa7a5d0;
  if (iVar10 < 1) {
    pcVar16 = (code *)0x0;
  }
  else {
    iVar10 = 0;
    pcVar16 = (code *)0x0;
    do {
      DAT_23e5aa777f8 = MT5_PositionGetTicket((void *)0x23e575eae78,iVar10);
      if (DAT_23e5aa777f8 != 0) {
        local_ec = iVar10;
        uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        MT5_PositionGetDouble((void *)0x23e575eae78,6);
        dVar21 = DAT_23e5aa7a448;
        if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
          dVar21 = (double)(longlong)DAT_23e5aa7a448;
          uVar17 = uVar12 & 0xffffffff;
          if (10 < (uint)uVar12) {
            uVar17 = 0xb;
          }
          dVar21 = (double)(longlong)
                           ((DAT_23e5aa7a448 - dVar21) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8)
                           + *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8))
                   / *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar21;
        }
        uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        MT5_PositionGetDouble((void *)0x23e575eae78,7);
        dVar22 = DAT_23e5aa7a448;
        if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
          dVar22 = (double)(longlong)DAT_23e5aa7a448;
          uVar17 = uVar12 & 0xffffffff;
          if (10 < (uint)uVar12) {
            uVar17 = 0xb;
          }
          dVar22 = (double)(longlong)
                           ((DAT_23e5aa7a448 - dVar22) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8)
                           + *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8))
                   / *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar22;
        }
        dVar6 = (double)(longlong)DAT_23e5aa777f8;
        uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        MT5_PositionGetDouble((void *)0x23e575eae78,4);
        dVar23 = DAT_23e5aa7a448;
        if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
          dVar23 = (double)(longlong)DAT_23e5aa7a448;
          uVar17 = uVar12 & 0xffffffff;
          if (10 < (uint)uVar12) {
            uVar17 = 0xb;
          }
          dVar23 = (double)(longlong)
                           ((DAT_23e5aa7a448 - dVar23) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8)
                           + *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8))
                   / *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar23;
        }
        local_108 = 0;
        local_104 = 0;
        MT5_PositionGetString((void *)0x23e575eae78,0xb);
        FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ec40);
        FUN_23e5aa105c0(&local_108,&local_158,0,&PTR_DAT_23e5aa6ec50);
        MT5_PositionGetDouble((void *)0x23e575eae78,3);
        dVar20 = DAT_23e5aa7a448;
        local_128 = MT5_PositionGetInteger((void *)0x23e575eae78,1);
        lVar13 = MT5_PositionGetInteger((void *)0x23e575eae78,2);
        lVar14 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
        local_120 = 0;
        local_11c = 0;
        MT5_PositionGetString((void *)0x23e575eae78,0);
        FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ec60);
        FUN_23e5aa105c0(&local_120,&local_158,0,&PTR_DAT_23e5aa6ec70);
        bVar7 = MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
        if (!bVar7) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        }
        if ((int)lVar13 == 0) {
          unaff_R12B = '\0';
          if ((DAT_23e5aa7246c == (int)lVar14) && (DAT_23e5aa72428 == 1)) {
            if (local_11c != DAT_23e5aa7791c) {
              unaff_R12B = '\0';
              if ((local_11c == 0) || (DAT_23e5aa7791c == 0)) goto LAB_23e5aa37333;
              uVar3 = *(uint *)(local_11c + -4);
              uVar4 = *(uint *)(DAT_23e5aa7791c + -4);
              uVar5 = uVar4;
              if (uVar3 < uVar4) {
                uVar5 = uVar3;
              }
              iVar10 = uVar3 - uVar4;
              if (uVar5 != 0) {
                uVar12 = 1;
                do {
                  uVar1 = *(ushort *)(local_11c + -2 + uVar12 * 2);
                  uVar2 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar12 * 2);
                  if (uVar5 <= uVar12) break;
                  uVar12 = uVar12 + 1;
                } while (uVar1 == uVar2);
                if (uVar1 != uVar2) {
                  iVar10 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar10 != 0) goto LAB_23e5aa37330;
            }
            if ((dVar21 == 0.0) && (!NAN(dVar21))) {
              uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar21 = dVar23 - DAT_23e5aa72498 * DAT_23e5aa76d98;
              if ((longlong)dVar21 != -0x8000000000000000) {
                dVar24 = (double)(longlong)dVar21;
                uVar17 = uVar12 & 0xffffffff;
                if (10 < (uint)uVar12) {
                  uVar17 = 0xb;
                }
                dVar21 = (double)(longlong)
                                 ((dVar21 - dVar24) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8) +
                                 *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar24;
              }
              FUN_23e5aa36d20((longlong)dVar6,dVar21);
            }
            if ((dVar22 == 0.0) && (!NAN(dVar22))) {
              uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar22 = DAT_23e5aa724a0 * DAT_23e5aa76d98 + dVar23;
              if ((longlong)dVar22 != -0x8000000000000000) {
                dVar24 = (double)(longlong)dVar22;
                uVar17 = uVar12 & 0xffffffff;
                if (10 < (uint)uVar12) {
                  uVar17 = 0xb;
                }
                dVar22 = (double)(longlong)
                                 ((dVar22 - dVar24) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8) +
                                 *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar22) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar24;
              }
              FUN_23e5aa36d20((longlong)dVar6,dVar21);
            }
            if (((DAT_23e5aa72265 == '\x01') &&
                (lVar13 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1),
                lVar13 <= local_128)) &&
               (lVar13 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,0),
               local_128 < lVar13)) {
              MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1);
              dVar24 = DAT_23e5aa7a448;
              MT5_iOpen((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1);
              if ((dVar24 < DAT_23e5aa7a448) &&
                 (MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1),
                 DAT_23e5aa7a448 < dVar23)) {
                FUN_23e5aa4d010((longlong)dVar6);
                MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
              }
            }
            if (DAT_23e5aa72267 == '\x01') {
              iVar10 = 0;
              if (DAT_23e5aa72266 != '\0') {
                iVar10 = 0x1e;
              }
              lVar13 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,iVar10,1);
              if (lVar13 <= local_128) {
                iVar10 = 0;
                if (DAT_23e5aa72266 != '\0') {
                  iVar10 = 0x1e;
                }
                lVar13 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,iVar10,0);
                if (local_128 < lVar13) {
                  iVar10 = 0;
                  if (DAT_23e5aa72266 != '\0') {
                    iVar10 = 0x1e;
                  }
                  MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,iVar10,1);
                  dVar24 = DAT_23e5aa7a448;
                  iVar10 = 0;
                  if (DAT_23e5aa72266 != '\0') {
                    iVar10 = 0x1e;
                  }
                  MT5_iOpen((void *)0x23e575eae78,&DAT_23e5aa77918,iVar10,1);
                  if (dVar24 < DAT_23e5aa7a448) {
                    iVar10 = 0;
                    if (DAT_23e5aa72266 != '\0') {
                      iVar10 = 0x1e;
                    }
                    MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,iVar10,1);
                    if (DAT_23e5aa7a448 < dVar23) {
                      FUN_23e5aa4d010((longlong)dVar6);
                      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                    }
                  }
                }
              }
            }
            DAT_23e5aa773e8 = DAT_23e5aa72510;
            uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
            uVar12 = (ulonglong)dVar6;
            dVar6 = (double)(longlong)uVar12;
            lVar13 = -0x640;
            do {
              if ((*(double *)(&DAT_23e5aa76410 + lVar13) == dVar6) &&
                 (!NAN(*(double *)(&DAT_23e5aa76410 + lVar13)) && !NAN(dVar6))) {
                dVar24 = *(double *)((longlong)&DAT_23e5aa76418 + lVar13);
                lVar13 = (longlong)dVar24;
                if (lVar13 != -0x8000000000000000) goto LAB_23e5aa37cf7;
                goto LAB_23e5aa37d56;
              }
              lVar13 = lVar13 + 0x10;
            } while (lVar13 != 0);
            dVar24 = 0.0;
            lVar13 = 0;
LAB_23e5aa37cf7:
            uVar15 = uVar17 & 0xffffffff;
            if (10 < (uint)uVar17) {
              uVar15 = 0xb;
            }
            dVar24 = (double)(longlong)
                             ((dVar24 - (double)lVar13) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8)
                             + *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar24) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + (double)lVar13;
LAB_23e5aa37d56:
            if ((dVar24 != 0.0) || (NAN(dVar24))) {
              dVar24 = dVar24 + DAT_23e5aa76d98 * DAT_23e5aa60238;
            }
            else {
              lVar13 = -0x640;
              do {
                dVar24 = dVar23;
                if ((*(double *)(&DAT_23e5aa76410 + lVar13) == 0.0) &&
                   (!NAN(*(double *)(&DAT_23e5aa76410 + lVar13)))) {
                  *(double *)(&DAT_23e5aa76410 + lVar13) = dVar6;
                  *(double *)((longlong)&DAT_23e5aa76418 + lVar13) = dVar23;
                  break;
                }
                lVar13 = lVar13 + 0x10;
              } while (lVar13 != 0);
            }
            if ((dVar24 <= 0.0 - DAT_23e5aa76d98 * 0.0) ||
               (dVar23 - dVar24 <= DAT_23e5aa723e8 * DAT_23e5aa76d98)) {
              local_13c = 0;
            }
            else {
              local_13c = 0x5aa72301;
            }
            local_110 = dVar23;
            if (DAT_23e5aa72410 != '\0') {
              local_110 = dVar24;
            }
            if (DAT_23e5aa77758 <
                (dVar23 - DAT_23e5aa76d98 * (DAT_23e5aa72498 + 0.0)) - DAT_23e5aa72560) {
              MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
              MT5_PositionGetDouble((void *)0x23e575eae78,3);
              uVar12 = DAT_23e5aa777f8;
LAB_23e5aa3a956:
              FUN_23e5aa4d010(uVar12);
              FUN_23e5aa10000(&local_120);
              FUN_23e5aa10000(&local_108);
              pcVar16 = (code *)CONCAT71((int7)((ulonglong)pcVar16 >> 8),1);
              break;
            }
            if (DAT_23e5aa7241c == 2) {
              unaff_R12B = '\0';
LAB_23e5aa3988b:
              dVar19 = (double)FUN_23e5aa4d200(1,dVar23,DAT_23e5aa72498,uVar12);
              DAT_23e5aa72580 = dVar19;
              if (DAT_23e5aa77758 <= dVar19) {
LAB_23e5aa3a94a:
                MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
                goto LAB_23e5aa3a956;
              }
              cVar8 = FUN_23e5aa4d5a0(uVar12);
              if (cVar8 != '\0') {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa72580;
                if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)DAT_23e5aa72580;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((DAT_23e5aa72580 - dVar25) *
                                    *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)
                                    (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                if (dVar21 + DAT_23e5aa7a448 < dVar25) {
                  uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                  dVar21 = DAT_23e5aa72580;
                  if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                    dVar21 = (double)(longlong)DAT_23e5aa72580;
                    uVar15 = uVar17 & 0xffffffff;
                    if (10 < (uint)uVar17) {
                      uVar15 = 0xb;
                    }
                    dVar21 = (double)(longlong)
                                     ((DAT_23e5aa72580 - dVar21) *
                                      *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                     *(double *)
                                      (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                             *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar21;
                  }
                  FUN_23e5aa36d20(uVar12,dVar21);
                  FUN_23e5aa4d640(uVar12);
                }
              }
              dVar21 = DAT_23e5aa72580;
              dVar25 = DAT_23e5aa77758;
              if ((0.0 < DAT_23e5aa724f8) &&
                 (lVar13 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0),
                 dVar26 = DAT_23e5aa77758, dVar18 = DAT_23e5aa72580, dVar21 = DAT_23e5aa72580,
                 dVar25 = DAT_23e5aa77758, local_128 + DAT_23e5aa7745c <= lVar13)) {
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar21 = DAT_23e5aa72580;
                dVar25 = DAT_23e5aa77758;
                if ((dVar18 + DAT_23e5aa7a448 + DAT_23e5aa72500 * DAT_23e5aa76d98 < dVar26) &&
                   (DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468)) {
                  unaff_R12B = '\x01';
                  dVar21 = DAT_23e5aa77758 - DAT_23e5aa72500 * DAT_23e5aa76d98;
                }
              }
              DAT_23e5aa72580 = dVar21;
              DAT_23e5aa77758 = dVar25;
              if ((((0.0 < DAT_23e5aa724a8) &&
                   (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
                   (DAT_23e5aa724c0 + DAT_23e5aa724a8) * DAT_23e5aa76d98 + dVar21 + DAT_23e5aa7a448
                   < dVar25)) && (DAT_23e5aa724b0 * DAT_23e5aa76d98 + local_110 < DAT_23e5aa77758))
                 && (DAT_23e5aa72580 < DAT_23e5aa724b8 * DAT_23e5aa76d98 + dVar23)) {
                DAT_23e5aa72580 = DAT_23e5aa77758 - DAT_23e5aa724a8 * DAT_23e5aa76d98;
                dVar21 = (double)(&DAT_23e5aa76a80)[DAT_23e5aa778f4] * 0.0;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * DAT_23e5aa60240 +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           DAT_23e5aa60240 + dVar25;
                }
                unaff_R12B = '\x01';
                if ((dVar21 < dVar20) &&
                   (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x22),
                   DAT_23e5aa7a448 <= dVar21)) goto LAB_23e5aa3a956;
              }
              dVar20 = DAT_23e5aa77758;
              dVar21 = DAT_23e5aa72580;
              if ((((((byte)local_13c & DAT_23e5aa723f0 == 1) == 1) &&
                   ((0.0 < DAT_23e5aa72400 &&
                    (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
                    DAT_23e5aa72400 * DAT_23e5aa76d98 + dVar21 + DAT_23e5aa7a448 < dVar20)))) &&
                  (dVar24 + DAT_23e5aa723f8 * DAT_23e5aa76d98 < DAT_23e5aa77758)) &&
                 ((DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468 &&
                  (DAT_23e5aa72580 < DAT_23e5aa76d98 * DAT_23e5aa72408 + dVar23)))) {
                MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                unaff_R12B = '\x01';
                DAT_23e5aa72580 = DAT_23e5aa77758 - DAT_23e5aa72400 * DAT_23e5aa76d98;
              }
              if (((0 < DAT_23e5aa724e4) &&
                  (dVar21 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8),
                  dVar20 = DAT_23e5aa72580 + DAT_23e5aa76a70,
                  MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
                  dVar20 + DAT_23e5aa7a448 < dVar21)) &&
                 ((dVar21 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8),
                  dVar21 < dVar23 || ((DAT_23e5aa724d8 & 1) == 0)))) {
                dVar20 = DAT_23e5aa60248;
                if (DAT_23e5aa724ec == '\0') {
                  dVar20 = 0.0;
                }
                dVar20 = (DAT_23e5aa77758 - dVar20 * DAT_23e5aa76d98) - DAT_23e5aa76a70;
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                if ((dVar21 < dVar20 - DAT_23e5aa7a448) &&
                   (DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468)) {
                  unaff_R12B = '\x01';
                  DAT_23e5aa72580 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8);
                }
              }
              dVar21 = DAT_23e5aa72580;
              if ((((DAT_23e5aa724c8 <= 0.0) || (DAT_23e5aa7241c != 2)) ||
                  (DAT_23e5aa77758 <= DAT_23e5aa724c8 * DAT_23e5aa76d98 + dVar23)) ||
                 (((dVar20 = DAT_23e5aa76d98 * DAT_23e5aa724d0,
                   MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
                   dVar20 + dVar23 <= dVar21 + DAT_23e5aa7a448 ||
                   (dVar23 = dVar23 + DAT_23e5aa724d0 * DAT_23e5aa76d98,
                   DAT_23e5aa77758 <= DAT_23e5aa76a70 + dVar23)) ||
                  (dVar22 - DAT_23e5aa77468 <= DAT_23e5aa77758)))) {
                if (unaff_R12B == '\0') {
                  if (DAT_23e5aa72508 == '\x01') {
                    DAT_23e5aa773f0 = DAT_23e5aa773f0 + 1;
                    dVar23 = DAT_23e5aa72520 * DAT_23e5aa76d98 + DAT_23e5aa72580;
                    if (((DAT_23e5aa76a70 + dVar23 < DAT_23e5aa77758) &&
                        (DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468)) &&
                       ((((DAT_23e5aa72510 == 0.0 && (!NAN(DAT_23e5aa72510))) ||
                         (local_110 + DAT_23e5aa76d98 * DAT_23e5aa773e8 < DAT_23e5aa77758)) &&
                        (DAT_23e5aa72518 <= DAT_23e5aa773f0)))) {
                      DAT_23e5aa773f0 = 0;
                      goto LAB_23e5aa3a520;
                    }
                  }
                  unaff_R12B = '\0';
                }
                if (DAT_23e5aa77758 <= DAT_23e5aa72580) goto LAB_23e5aa3a94a;
              }
              else {
LAB_23e5aa3a520:
                unaff_R12B = '\x01';
                DAT_23e5aa72580 = dVar23;
                if (DAT_23e5aa77758 <= dVar23) goto LAB_23e5aa3a94a;
              }
              uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              if ((longlong)dVar19 != -0x8000000000000000) {
                dVar21 = (double)(longlong)dVar19;
                uVar17 = uVar12 & 0xffffffff;
                if (10 < (uint)uVar12) {
                  uVar17 = 0xb;
                }
                dVar19 = (double)(longlong)
                                 ((dVar19 - dVar21) * *(double *)(&DAT_23e5aa61600 + uVar17 * 8) +
                                 *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar19) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar21;
              }
              uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar21 = DAT_23e5aa72580;
              if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                dVar21 = (double)(longlong)DAT_23e5aa72580;
                uVar17 = uVar12 & 0xffffffff;
                if (10 < (uint)uVar12) {
                  uVar17 = 0xb;
                }
                dVar21 = (double)(longlong)
                                 ((DAT_23e5aa72580 - dVar21) *
                                  *(double *)(&DAT_23e5aa61600 + uVar17 * 8) +
                                 *(double *)
                                  (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar21;
              }
              if ((dVar19 != dVar21) || (NAN(dVar19) || NAN(dVar21))) {
                uVar12 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = DAT_23e5aa72580;
                if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                  dVar21 = (double)(longlong)DAT_23e5aa72580;
                  uVar17 = uVar12 & 0xffffffff;
                  if (10 < (uint)uVar12) {
                    uVar17 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((DAT_23e5aa72580 - dVar21) *
                                    *(double *)(&DAT_23e5aa61600 + uVar17 * 8) +
                                   *(double *)
                                    (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar17 * 8) + dVar21;
                }
                if (DAT_23e5aa76410 == '\x01') {
                  lVar13 = -12000;
                  do {
                    if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar13) == dVar6) &&
                       (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar13)) && !NAN(dVar6))) {
                      *(double *)((longlong)&DAT_23e5aa75478 + lVar13) = dVar21;
                      break;
                    }
                    lVar13 = lVar13 + 0x18;
                  } while (lVar13 != 0);
                }
              }
            }
            else {
              dVar19 = (double)FUN_23e5aa4d200(1,dVar23,DAT_23e5aa72498,uVar12);
              DAT_23e5aa72580 = dVar19;
              if (DAT_23e5aa77758 < dVar19) {
                MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                runtime_cast_to_string
                          ((void *)0x23e575eae78,(ulonglong)DAT_23e5aa72580,0x58,&local_158);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa658e8,0,&PTR_DAT_23e5aa6ec80);
                cVar9 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar9 == '\0') {
                  (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x29144c000001f9);
LAB_23e5aa3aa3c:
                  (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x291502000001f9);
                }
                else {
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x23e575eae78,(ulonglong)DAT_23e5aa77758,0x58,&local_158);
                  FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65928,0,&PTR_DAT_23e5aa6ec90);
                  cVar9 = FUN_23e5aa104a0(&local_f8,local_154);
                  if (cVar9 != '\0') {
LAB_23e5aa3a90d:
                    pcVar16 = runtime_cast_to_string;
                    MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                    goto LAB_23e5aa3a94a;
                  }
                  (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x27144d000001f9);
LAB_23e5aa3a7ed:
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x23e575eae78,(ulonglong)DAT_23e5aa72580,0x58,&local_158);
                  FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa658e8,0,&PTR_DAT_23e5aa6ed90);
                  cVar9 = FUN_23e5aa104a0(&local_f8,local_154);
                  if (cVar9 == '\0') goto LAB_23e5aa3aa3c;
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x23e575eae78,(ulonglong)DAT_23e5aa77758,0x58,&local_158);
                  FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65928,0,&PTR_DAT_23e5aa6eda0);
                  cVar9 = FUN_23e5aa104a0(&local_f8,local_154);
                  if (cVar9 != '\0') goto LAB_23e5aa3a90d;
                }
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x271503000001f9);
LAB_23e5aa3aa7c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x3f1461000001f9);
LAB_23e5aa3aa9c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x601461000001f9);
LAB_23e5aa3aabc:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x4214a0000001f9);
LAB_23e5aa3aadc:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x6314a0000001f9);
LAB_23e5aa3aafc:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x4914df000001f9);
LAB_23e5aa3ab1c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x6a14df000001f9);
LAB_23e5aa3ab3c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x3f147e000001f9);
LAB_23e5aa3ab5c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x60147e000001f9);
LAB_23e5aa3ab7c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x3514c3000001f9);
LAB_23e5aa3ab9c:
                (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x5614c3000001f9);
                pcVar16 = (code *)swi(3);
                uVar12 = (*pcVar16)();
                return uVar12;
              }
              if (DAT_23e5aa724f8 <= 0.0) goto LAB_23e5aa38219;
              local_148 = 0;
              lVar13 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
              dVar25 = DAT_23e5aa77758;
              if (lVar13 < DAT_23e5aa7745c + local_128) goto LAB_23e5aa38220;
              uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
              dVar18 = DAT_23e5aa72500 * DAT_23e5aa76d98 + DAT_23e5aa7a448 + dVar21;
              if ((longlong)dVar18 != -0x8000000000000000) {
                dVar26 = (double)(longlong)dVar18;
                uVar15 = uVar17 & 0xffffffff;
                if (10 < (uint)uVar17) {
                  uVar15 = 0xb;
                }
                dVar18 = (double)(longlong)
                                 ((dVar18 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                 *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar18) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
              }
              if ((dVar18 < dVar25) && (DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468)) {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = DAT_23e5aa77758 - DAT_23e5aa72500 * DAT_23e5aa76d98;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                if (DAT_23e5aa77758 - DAT_23e5aa76a70 <= dVar21) goto LAB_23e5aa38219;
                uVar17 = uVar12;
                iVar10 = FUN_23e5aa36d20(uVar12,dVar21);
                local_148 = CONCAT71((int7)(uVar17 >> 8),1);
                if (iVar10 != 0) goto LAB_23e5aa38220;
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6eca0);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ecb0);
                cVar8 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar8 == '\0') goto LAB_23e5aa3aa7c;
                FUN_23e5aa105c0(&local_138,&local_f8,0,&PTR_DAT_23e5aa6ecc0);
                cVar8 = FUN_23e5aa104a0(&local_138,literal_23e5aa6599c);
                if (cVar8 != '\0') {
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  goto LAB_23e5aa38220;
                }
                goto LAB_23e5aa3aa9c;
              }
LAB_23e5aa38219:
              local_148 = 0;
LAB_23e5aa38220:
              dVar25 = DAT_23e5aa77758;
              if (0.0 < DAT_23e5aa724a8) {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar18 = DAT_23e5aa77758;
                dVar26 = (DAT_23e5aa724a8 + DAT_23e5aa724c0) * DAT_23e5aa76d98 +
                         DAT_23e5aa7a448 + dVar21;
                if ((longlong)dVar26 != -0x8000000000000000) {
                  dVar27 = (double)(longlong)dVar26;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar26 = (double)(longlong)
                                   ((dVar26 - dVar27) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar26) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar27;
                }
                if (dVar25 <= dVar26) goto LAB_23e5aa3865c;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa724b0 * DAT_23e5aa76d98 + local_110;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if ((dVar18 <= dVar25) || (dVar22 - DAT_23e5aa77468 <= DAT_23e5aa77758))
                goto LAB_23e5aa3865c;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa724b8 * DAT_23e5aa76d98 + dVar23;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar18 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar18) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar18;
                }
                if (dVar25 <= dVar21) goto LAB_23e5aa3865c;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = DAT_23e5aa77758 - DAT_23e5aa724a8 * DAT_23e5aa76d98;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                if (DAT_23e5aa77758 - DAT_23e5aa76a70 <= dVar21) goto LAB_23e5aa3865c;
                iVar10 = FUN_23e5aa36d20(uVar12,dVar21);
                if (iVar10 != 0) {
                  dVar25 = (double)(&DAT_23e5aa76a80)[DAT_23e5aa778f4] * 0.0;
                  lVar13 = (longlong)dVar25;
                  if (lVar13 != -0x8000000000000000) {
                    dVar18 = (double)lVar13;
                    lVar13 = (longlong)
                             ((dVar25 - dVar18) * DAT_23e5aa60240 +
                             *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8));
                    dVar25 = (double)lVar13 / DAT_23e5aa60240 + dVar18;
                  }
                  local_148 = CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
                  if ((dVar25 < dVar20) &&
                     (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x22),
                     DAT_23e5aa7a448 <= dVar25)) goto LAB_23e5aa3a956;
                  goto LAB_23e5aa3865c;
                }
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ecd0);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ece0);
                cVar8 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar8 == '\0') goto LAB_23e5aa3ab3c;
                FUN_23e5aa105c0(&local_138,&local_f8,0,&PTR_DAT_23e5aa6ecf0);
                cVar8 = FUN_23e5aa104a0(&local_138,literal_23e5aa65a4c);
                if (cVar8 != '\0') {
                  lVar13 = MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  local_148 = CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
                  goto LAB_23e5aa3865c;
                }
                goto LAB_23e5aa3ab5c;
              }
LAB_23e5aa3865c:
              dVar25 = DAT_23e5aa77758;
              if (((DAT_23e5aa723f0 == 1 & (byte)local_13c) == 1) && (0.0 < DAT_23e5aa72400)) {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar18 = DAT_23e5aa77758;
                dVar26 = DAT_23e5aa72400 * DAT_23e5aa76d98 + DAT_23e5aa7a448 + dVar21;
                if ((longlong)dVar26 != -0x8000000000000000) {
                  dVar27 = (double)(longlong)dVar26;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar26 = (double)(longlong)
                                   ((dVar26 - dVar27) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar26) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar27;
                }
                if (dVar25 <= dVar26) goto LAB_23e5aa38aed;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa723f8 * DAT_23e5aa76d98 + dVar24;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if ((dVar18 <= dVar25) || (dVar22 - DAT_23e5aa77468 <= DAT_23e5aa77758))
                goto LAB_23e5aa38aed;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa72408 * DAT_23e5aa76d98 + dVar23;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar18 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar18) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar18;
                }
                if (dVar25 <= dVar21) goto LAB_23e5aa38aed;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = DAT_23e5aa77758 - DAT_23e5aa72400 * DAT_23e5aa76d98;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                if (DAT_23e5aa77758 - DAT_23e5aa76a70 <= dVar21) goto LAB_23e5aa38aed;
                iVar10 = FUN_23e5aa36d20(uVar12,dVar21);
                if (iVar10 != 0) {
LAB_23e5aa38ac1:
                  lVar13 = MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  local_148 = CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
                  goto LAB_23e5aa38aed;
                }
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ed00);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ed10);
                cVar8 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar8 == '\0') goto LAB_23e5aa3aabc;
                FUN_23e5aa105c0(&local_138,&local_f8,0,&PTR_DAT_23e5aa6ed20);
                cVar8 = FUN_23e5aa104a0(&local_138,literal_23e5aa65acc);
                if (cVar8 != '\0') goto LAB_23e5aa38ac1;
                goto LAB_23e5aa3aadc;
              }
LAB_23e5aa38aed:
              if ((0 < DAT_23e5aa724e4) && (cVar9 != '\0')) {
                dVar25 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8);
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar18 = DAT_23e5aa76a70 + dVar21;
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar18 = dVar18 + DAT_23e5aa7a448;
                if ((longlong)dVar18 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar18;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar18 = (double)(longlong)
                                   ((dVar18 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar18) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if (((dVar25 <= dVar18) ||
                    (dVar25 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8),
                    DAT_23e5aa77758 - (double)DAT_23e5aa72360 * DAT_23e5aa76d98 <= dVar25)) ||
                   ((dVar23 <= dVar25 && ((DAT_23e5aa724d8 & 1) != 0)))) goto LAB_23e5aa38f72;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar18 = DAT_23e5aa60248;
                if (DAT_23e5aa724ec == '\0') {
                  dVar18 = 0.0;
                }
                dVar18 = (DAT_23e5aa77758 - dVar18 * DAT_23e5aa76d98) - DAT_23e5aa76a70;
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar18 = dVar18 - DAT_23e5aa7a448;
                if ((longlong)dVar18 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar18;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar18 = (double)(longlong)
                                   ((dVar18 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar18) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if ((dVar18 <= dVar25) || (dVar22 - DAT_23e5aa77468 <= DAT_23e5aa77758))
                goto LAB_23e5aa38f72;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = *(double *)(&DAT_23e5aa770d0 + (ulonglong)DAT_23e5aa778f4 * 8);
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                if (DAT_23e5aa77758 - DAT_23e5aa76a70 <= dVar21) goto LAB_23e5aa38f72;
                uVar17 = uVar12;
                iVar10 = FUN_23e5aa36d20(uVar12,dVar21);
                local_148 = CONCAT71((int7)(uVar17 >> 8),1);
                if (iVar10 != 0) goto LAB_23e5aa38f72;
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ed30);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65140,0,&PTR_DAT_23e5aa6ed40);
                cVar8 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar8 != '\0') {
                  FUN_23e5aa105c0(&local_138,&local_f8,0,&PTR_DAT_23e5aa6ed50);
                  cVar8 = FUN_23e5aa104a0(&local_138,literal_23e5aa65b7c);
                  if (cVar8 == '\0') goto LAB_23e5aa3ab9c;
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  goto LAB_23e5aa38f72;
                }
                goto LAB_23e5aa3ab7c;
              }
LAB_23e5aa38f72:
              dVar25 = DAT_23e5aa77758;
              if (0.0 < DAT_23e5aa724c8) {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar18 = DAT_23e5aa724c8 * DAT_23e5aa76d98 + dVar23;
                if ((longlong)dVar18 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar18;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar18 = (double)(longlong)
                                   ((dVar18 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar18) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if (dVar25 <= dVar18) goto LAB_23e5aa393c6;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa724d0 * DAT_23e5aa76d98 + dVar23;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar18 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar18) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar18;
                }
                MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
                dVar18 = DAT_23e5aa77758;
                if (dVar25 <= DAT_23e5aa7a448 + dVar21) goto LAB_23e5aa393c6;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar25 = DAT_23e5aa724d0 * DAT_23e5aa76d98 + dVar23 + DAT_23e5aa76a70;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar25;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar26;
                }
                if ((dVar18 <= dVar25) || (dVar22 - DAT_23e5aa77468 <= DAT_23e5aa77758))
                goto LAB_23e5aa393c6;
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar21 = DAT_23e5aa724d0 * DAT_23e5aa76d98 + dVar23;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar21;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                }
                if (DAT_23e5aa77758 - DAT_23e5aa76a70 <= dVar21) goto LAB_23e5aa393c6;
                iVar10 = FUN_23e5aa36d20(uVar12,dVar21);
                unaff_R12B = '\x01';
                if (iVar10 != 0) goto LAB_23e5aa393d0;
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_158,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ed60);
                FUN_23e5aa105c0(&local_f8,&string_ref_23e5aa65c00,0,&PTR_DAT_23e5aa6ed70);
                cVar8 = FUN_23e5aa104a0(&local_f8,local_154);
                if (cVar8 == '\0') goto LAB_23e5aa3aafc;
                FUN_23e5aa105c0(&local_138,&local_f8,0,&PTR_DAT_23e5aa6ed80);
                cVar8 = FUN_23e5aa104a0(&local_138,literal_23e5aa65c1c);
                if (cVar8 != '\0') {
                  MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                  goto LAB_23e5aa39651;
                }
                goto LAB_23e5aa3ab1c;
              }
LAB_23e5aa393c6:
              unaff_R12B = '\x01';
              if ((char)local_148 == '\0') {
                if (((((DAT_23e5aa72508 == '\x01') &&
                      (DAT_23e5aa773f0 = DAT_23e5aa773f0 + 1,
                      DAT_23e5aa72520 * DAT_23e5aa76d98 + dVar21 + DAT_23e5aa76a70 < DAT_23e5aa77758
                      )) && (DAT_23e5aa77758 < dVar22 - DAT_23e5aa77468)) &&
                    (((DAT_23e5aa72510 == 0.0 && (!NAN(DAT_23e5aa72510))) ||
                     (DAT_23e5aa76d98 * DAT_23e5aa773e8 + local_110 < DAT_23e5aa77758)))) &&
                   (DAT_23e5aa72518 <= DAT_23e5aa773f0)) {
                  uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                  dVar25 = DAT_23e5aa72520 * DAT_23e5aa76d98 + dVar21;
                  if ((longlong)dVar25 != -0x8000000000000000) {
                    dVar18 = (double)(longlong)dVar25;
                    uVar15 = uVar17 & 0xffffffff;
                    if (10 < (uint)uVar17) {
                      uVar15 = 0xb;
                    }
                    dVar25 = (double)(longlong)
                                     ((dVar25 - dVar18) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8)
                                     + *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar25) * 8)
                                     ) / *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar18;
                  }
                  if (dVar21 < dVar25) {
                    DAT_23e5aa773f0 = 0;
                    uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                    dVar21 = dVar21 + DAT_23e5aa72520 * DAT_23e5aa76d98;
                    if ((longlong)dVar21 != -0x8000000000000000) {
                      dVar25 = (double)(longlong)dVar21;
                      uVar15 = uVar17 & 0xffffffff;
                      if (10 < (uint)uVar17) {
                        uVar15 = 0xb;
                      }
                      dVar21 = (double)(longlong)
                                       ((dVar21 - dVar25) *
                                        *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                       *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar21) * 8)
                                       ) / *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
                    }
                    FUN_23e5aa36d20(uVar12,dVar21);
                    goto LAB_23e5aa39651;
                  }
                }
                unaff_R12B = '\0';
              }
              else {
LAB_23e5aa393d0:
                unaff_R12B = '\x01';
              }
LAB_23e5aa39651:
              DAT_23e5aa72580 = dVar21;
              if (DAT_23e5aa77758 < dVar21) goto LAB_23e5aa3a7ed;
              uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              if ((longlong)dVar19 != -0x8000000000000000) {
                dVar25 = (double)(longlong)dVar19;
                uVar15 = uVar17 & 0xffffffff;
                if (10 < (uint)uVar17) {
                  uVar15 = 0xb;
                }
                dVar19 = (double)(longlong)
                                 ((dVar19 - dVar25) * *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                 *(double *)(&DAT_23e5aa60228 + (ulonglong)(0.0 < dVar19) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
              }
              uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar25 = DAT_23e5aa72580;
              if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                dVar25 = (double)(longlong)DAT_23e5aa72580;
                uVar15 = uVar17 & 0xffffffff;
                if (10 < (uint)uVar17) {
                  uVar15 = 0xb;
                }
                dVar25 = (double)(longlong)
                                 ((DAT_23e5aa72580 - dVar25) *
                                  *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                 *(double *)
                                  (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar25;
              }
              if ((dVar19 != dVar25) || (NAN(dVar19) || NAN(dVar25))) {
                uVar17 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar19 = DAT_23e5aa72580;
                if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
                  dVar19 = (double)(longlong)DAT_23e5aa72580;
                  uVar15 = uVar17 & 0xffffffff;
                  if (10 < (uint)uVar17) {
                    uVar15 = 0xb;
                  }
                  dVar19 = (double)(longlong)
                                   ((DAT_23e5aa72580 - dVar19) *
                                    *(double *)(&DAT_23e5aa61600 + uVar15 * 8) +
                                   *(double *)
                                    (&DAT_23e5aa60228 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar15 * 8) + dVar19;
                }
                if (DAT_23e5aa76410 == '\x01') {
                  lVar13 = -12000;
                  do {
                    if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar13) == dVar6) &&
                       (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar13)) && !NAN(dVar6))) {
                      *(double *)((longlong)&DAT_23e5aa75478 + lVar13) = dVar19;
                      break;
                    }
                    lVar13 = lVar13 + 0x18;
                  } while (lVar13 != 0);
                }
              }
              if (DAT_23e5aa7241c == 2) goto LAB_23e5aa3988b;
            }
            if (unaff_R12B != '\0') {
              pcVar16 = (code *)0x1;
            }
          }
        }
        else {
LAB_23e5aa37330:
          unaff_R12B = '\0';
        }
LAB_23e5aa37333:
        FUN_23e5aa10000(&local_120);
        FUN_23e5aa10000(&local_108);
        iVar10 = local_ec;
      }
      if (unaff_R12B != '\0') {
        pcVar16 = (code *)0x1;
      }
      iVar10 = iVar10 + 1;
      iVar11 = MT5_PositionsTotal((void *)0x23e575eae78);
    } while (iVar10 < iVar11);
  }
  FUN_23e5aa10000(&local_158);
  FUN_23e5aa10000(&local_f8);
  FUN_23e5aa10000(&local_138);
  return (ulonglong)pcVar16 & 0xffffffff;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:18201
/* Address: 23e5aa3abc0 */

/* WARNING: Removing unreachable block (ram,0x023e5aa3b6de) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

ulonglong FUN_23e5aa3abc0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  double dVar8;
  undefined4 uVar9;
  double dVar10;
  bool bVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  longlong lVar17;
  longlong lVar18;
  ulonglong uVar19;
  code *pcVar20;
  code *pcVar21;
  char unaff_R12B;
  ulonglong uVar22;
  undefined4 uVar23;
  double dVar24;
  undefined4 uVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined4 local_160;
  longlong local_15c;
  undefined4 local_150;
  longlong local_14c;
  undefined8 local_140;
  ulonglong local_138;
  undefined4 local_12c;
  undefined4 local_128;
  undefined8 local_124;
  longlong local_118;
  undefined4 local_110;
  longlong local_10c;
  undefined4 local_100;
  undefined8 local_fc;
  int local_f4;
  double local_f0;
  
  local_128 = 0;
  local_160 = 0;
  local_150 = 0;
  local_100 = 0;
  local_110 = 0;
  local_124 = 0;
  local_15c = 0;
  local_14c = 0;
  local_fc = 0;
  local_10c = 0;
  iVar14 = MT5_PositionsTotal((void *)0x23e575eae78);
  cVar13 = DAT_23e5aa7a5d0;
  if (iVar14 < 1) {
    pcVar21 = (code *)0x0;
LAB_23e5aa3e473:
    FUN_23e5aa10000(&local_150);
    FUN_23e5aa10000(&local_160);
    FUN_23e5aa10000(&local_128);
    return (ulonglong)pcVar21 & 0xffffffff;
  }
  iVar14 = 0;
  pcVar21 = (code *)0x0;
LAB_23e5aa3ad4c:
  DAT_23e5aa777f8 = MT5_PositionGetTicket((void *)0x23e575eae78,iVar14);
  if (DAT_23e5aa777f8 == 0) goto LAB_23e5aa3ad25;
  local_f4 = iVar14;
  uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
  MT5_PositionGetDouble((void *)0x23e575eae78,6);
  dVar26 = DAT_23e5aa7a448;
  if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
    dVar26 = (double)(longlong)DAT_23e5aa7a448;
    uVar22 = uVar16 & 0xffffffff;
    if (10 < (uint)uVar16) {
      uVar22 = 0xb;
    }
    dVar26 = (double)(longlong)
                     ((DAT_23e5aa7a448 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                     *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8)) /
             *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar26;
  }
  uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
  MT5_PositionGetDouble((void *)0x23e575eae78,7);
  dVar27 = DAT_23e5aa7a448;
  if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
    dVar27 = (double)(longlong)DAT_23e5aa7a448;
    uVar22 = uVar16 & 0xffffffff;
    if (10 < (uint)uVar16) {
      uVar22 = 0xb;
    }
    dVar27 = (double)(longlong)
                     ((DAT_23e5aa7a448 - dVar27) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                     *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8)) /
             *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar27;
  }
  dVar8 = (double)(longlong)DAT_23e5aa777f8;
  uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
  MT5_PositionGetDouble((void *)0x23e575eae78,4);
  dVar28 = DAT_23e5aa7a448;
  if ((longlong)DAT_23e5aa7a448 != -0x8000000000000000) {
    dVar28 = (double)(longlong)DAT_23e5aa7a448;
    uVar22 = uVar16 & 0xffffffff;
    if (10 < (uint)uVar16) {
      uVar22 = 0xb;
    }
    dVar28 = (double)(longlong)
                     ((DAT_23e5aa7a448 - dVar28) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                     *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa7a448) * 8)) /
             *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar28;
  }
  local_100 = 0;
  local_fc = 0;
  MT5_PositionGetString((void *)0x23e575eae78,0xb);
  FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6edb0);
  FUN_23e5aa105c0(&local_100,&local_150,0,&PTR_DAT_23e5aa6edc0);
  MT5_PositionGetDouble((void *)0x23e575eae78,3);
  dVar31 = DAT_23e5aa7a448;
  local_118 = MT5_PositionGetInteger((void *)0x23e575eae78,1);
  lVar17 = MT5_PositionGetInteger((void *)0x23e575eae78,2);
  lVar18 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
  local_110 = 0;
  local_10c = 0;
  MT5_PositionGetString((void *)0x23e575eae78,0);
  FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6edd0);
  FUN_23e5aa105c0(&local_110,&local_150,0,&PTR_DAT_23e5aa6ede0);
  bVar11 = MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
  if (bVar11) {
    if ((int)lVar17 != 1) goto LAB_23e5aa3ad00;
LAB_23e5aa3b10d:
    unaff_R12B = '\0';
    if ((DAT_23e5aa7246c == (int)lVar18) && (DAT_23e5aa72428 == 1)) {
      if (local_10c != DAT_23e5aa7791c) {
        unaff_R12B = '\0';
        if ((local_10c == 0) || (DAT_23e5aa7791c == 0)) goto LAB_23e5aa3ad03;
        uVar5 = *(uint *)(local_10c + -4);
        uVar6 = *(uint *)(DAT_23e5aa7791c + -4);
        uVar7 = uVar6;
        if (uVar5 < uVar6) {
          uVar7 = uVar5;
        }
        iVar14 = uVar5 - uVar6;
        if (uVar7 != 0) {
          uVar16 = 1;
          do {
            uVar3 = *(ushort *)(local_10c + -2 + uVar16 * 2);
            uVar4 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar16 * 2);
            if (uVar7 <= uVar16) break;
            uVar16 = uVar16 + 1;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar14 = (uint)uVar3 - (uint)uVar4;
          }
        }
        if (iVar14 != 0) goto LAB_23e5aa3ad00;
      }
      if ((dVar26 == 0.0) && (!NAN(dVar26))) {
        uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        dVar26 = DAT_23e5aa72498 * DAT_23e5aa76d98 + dVar28;
        if ((longlong)dVar26 != -0x8000000000000000) {
          dVar29 = (double)(longlong)dVar26;
          uVar22 = uVar16 & 0xffffffff;
          if (10 < (uint)uVar16) {
            uVar22 = 0xb;
          }
          dVar26 = (double)(longlong)
                           ((dVar26 - dVar29) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                           *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                   *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar29;
        }
        FUN_23e5aa36d20((longlong)dVar8,dVar26,dVar27);
      }
      if ((dVar27 == 0.0) && (!NAN(dVar27))) {
        uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        dVar27 = dVar28 - DAT_23e5aa724a0 * DAT_23e5aa76d98;
        if ((longlong)dVar27 != -0x8000000000000000) {
          dVar29 = (double)(longlong)dVar27;
          uVar22 = uVar16 & 0xffffffff;
          if (10 < (uint)uVar16) {
            uVar22 = 0xb;
          }
          dVar27 = (double)(longlong)
                           ((dVar27 - dVar29) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                           *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar27) * 8)) /
                   *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar29;
        }
        FUN_23e5aa36d20((longlong)dVar8,dVar26,dVar27);
      }
      local_f0 = dVar31;
      if (((DAT_23e5aa72265 == '\x01') &&
          (lVar17 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1),
          lVar17 <= local_118)) &&
         (lVar17 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,0),
         local_118 < lVar17)) {
        MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1);
        dVar31 = DAT_23e5aa7a448;
        MT5_iOpen((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1);
        if ((DAT_23e5aa7a448 < dVar31) &&
           (MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,(uint)DAT_23e5aa72264,1),
           dVar28 < DAT_23e5aa7a448)) {
          FUN_23e5aa4d010((longlong)dVar8);
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
        }
      }
      if (DAT_23e5aa72267 == '\x01') {
        iVar14 = 0;
        if (DAT_23e5aa72266 != '\0') {
          iVar14 = 0x1e;
        }
        lVar17 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,iVar14,1);
        if (lVar17 <= local_118) {
          iVar14 = 0;
          if (DAT_23e5aa72266 != '\0') {
            iVar14 = 0x1e;
          }
          lVar17 = MT5_iTime((void *)0x23e575eae78,&DAT_23e5aa77918,iVar14,0);
          if (local_118 < lVar17) {
            iVar14 = 0;
            if (DAT_23e5aa72266 != '\0') {
              iVar14 = 0x1e;
            }
            MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,iVar14,1);
            dVar31 = DAT_23e5aa7a448;
            iVar14 = 0;
            if (DAT_23e5aa72266 != '\0') {
              iVar14 = 0x1e;
            }
            MT5_iOpen((void *)0x23e575eae78,&DAT_23e5aa77918,iVar14,1);
            if (DAT_23e5aa7a448 < dVar31) {
              iVar14 = 0;
              if (DAT_23e5aa72266 != '\0') {
                iVar14 = 0x1e;
              }
              MT5_iClose((void *)0x23e575eae78,&DAT_23e5aa77918,iVar14,1);
              if (dVar28 < DAT_23e5aa7a448) {
                FUN_23e5aa4d010((longlong)dVar8);
                MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
              }
            }
          }
        }
      }
      DAT_23e5aa773e8 = DAT_23e5aa72510;
      uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
      uVar16 = (ulonglong)dVar8;
      lVar17 = -0x640;
      dVar8 = (double)(longlong)uVar16;
      do {
        if ((*(double *)(&DAT_23e5aa76410 + lVar17) == dVar8) &&
           (!NAN(*(double *)(&DAT_23e5aa76410 + lVar17)) && !NAN(dVar8))) {
          dVar31 = *(double *)((longlong)&DAT_23e5aa76418 + lVar17);
          lVar17 = (longlong)dVar31;
          if (lVar17 == -0x8000000000000000) goto LAB_23e5aa3b766;
          goto LAB_23e5aa3b707;
        }
        lVar17 = lVar17 + 0x10;
      } while (lVar17 != 0);
      dVar31 = 0.0;
      lVar17 = 0;
LAB_23e5aa3b707:
      uVar19 = uVar22 & 0xffffffff;
      if (10 < (uint)uVar22) {
        uVar19 = 0xb;
      }
      dVar31 = (double)(longlong)
                       ((dVar31 - (double)lVar17) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                       *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar31) * 8)) /
               *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + (double)lVar17;
LAB_23e5aa3b766:
      if ((dVar31 != 0.0) || (NAN(dVar31))) {
        dVar31 = dVar31 + DAT_23e5aa76d98 * DAT_23e5aa60260;
      }
      else {
        lVar17 = -0x640;
        do {
          dVar31 = dVar28;
          if ((*(double *)(&DAT_23e5aa76410 + lVar17) == 0.0) &&
             (!NAN(*(double *)(&DAT_23e5aa76410 + lVar17)))) {
            *(double *)(&DAT_23e5aa76410 + lVar17) = dVar8;
            *(double *)((longlong)&DAT_23e5aa76418 + lVar17) = dVar28;
            break;
          }
          lVar17 = lVar17 + 0x10;
        } while (lVar17 != 0);
      }
      if ((dVar31 <= DAT_23e5aa76d98 * 0.0 + 0.0) ||
         (dVar31 - dVar28 <= DAT_23e5aa723e8 * DAT_23e5aa76d98)) {
        local_12c = 0;
      }
      else {
        local_12c = 0x5aa72301;
      }
      dVar29 = dVar28;
      if (DAT_23e5aa72410 != '\0') {
        dVar29 = dVar31;
      }
      if (DAT_23e5aa76d98 * (DAT_23e5aa72498 + 0.0) + dVar28 + DAT_23e5aa72560 < DAT_23e5aa77760) {
        MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
        MT5_PositionGetDouble((void *)0x23e575eae78,3);
        uVar16 = DAT_23e5aa777f8;
        goto LAB_23e5aa3e444;
      }
      if (DAT_23e5aa7241c == 2) {
        unaff_R12B = '\0';
LAB_23e5aa3cfcb:
        dVar24 = (double)FUN_23e5aa4d200(2,dVar28,DAT_23e5aa72498,uVar16);
        DAT_23e5aa72580 = dVar24;
        if (dVar24 <= DAT_23e5aa77760) goto LAB_23e5aa3e438;
        cVar12 = FUN_23e5aa4d5a0(uVar16);
        if (cVar12 != '\0') {
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar30 = DAT_23e5aa72580;
          if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
            dVar30 = (double)(longlong)DAT_23e5aa72580;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar30 = (double)(longlong)
                             ((DAT_23e5aa72580 - dVar30) *
                              *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8))
                     / *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
          }
          MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
          if (dVar30 < dVar26 - DAT_23e5aa7a448) {
            uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
            dVar26 = DAT_23e5aa72580;
            if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
              dVar26 = (double)(longlong)DAT_23e5aa72580;
              uVar19 = uVar22 & 0xffffffff;
              if (10 < (uint)uVar22) {
                uVar19 = 0xb;
              }
              dVar26 = (double)(longlong)
                               ((DAT_23e5aa72580 - dVar26) *
                                *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                               *(double *)
                                (&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8)) /
                       *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar26;
            }
            FUN_23e5aa36d20(uVar16,dVar26,dVar27);
            FUN_23e5aa4d640(uVar16);
          }
        }
        dVar26 = DAT_23e5aa72580;
        dVar30 = DAT_23e5aa77760;
        if ((0.0 < DAT_23e5aa724f8) &&
           (lVar17 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0), dVar10 = DAT_23e5aa77760,
           dVar32 = DAT_23e5aa72580, dVar26 = DAT_23e5aa72580, dVar30 = DAT_23e5aa77760,
           local_118 + DAT_23e5aa7745c <= lVar17)) {
          MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
          dVar26 = DAT_23e5aa72580;
          dVar30 = DAT_23e5aa77760;
          if ((dVar10 < (dVar32 - DAT_23e5aa7a448) - DAT_23e5aa72500 * DAT_23e5aa76d98) &&
             (DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760)) {
            unaff_R12B = '\x01';
            dVar26 = DAT_23e5aa72500 * DAT_23e5aa76d98 + DAT_23e5aa77760;
          }
        }
        DAT_23e5aa72580 = dVar26;
        DAT_23e5aa77760 = dVar30;
        if ((((0.0 < DAT_23e5aa724a8) &&
             (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
             dVar30 < (dVar26 - DAT_23e5aa7a448) -
                      (DAT_23e5aa724c0 + DAT_23e5aa724a8) * DAT_23e5aa76d98)) &&
            (DAT_23e5aa77760 < dVar29 - DAT_23e5aa724b0 * DAT_23e5aa76d98)) &&
           (dVar28 - DAT_23e5aa724b8 * DAT_23e5aa76d98 < DAT_23e5aa72580)) {
          DAT_23e5aa72580 = DAT_23e5aa724a8 * DAT_23e5aa76d98 + DAT_23e5aa77760;
          dVar26 = (double)(&DAT_23e5aa76a80)[DAT_23e5aa778f4] * 0.0;
          if ((longlong)dVar26 != -0x8000000000000000) {
            dVar30 = (double)(longlong)dVar26;
            dVar26 = (double)(longlong)
                             ((dVar26 - dVar30) * DAT_23e5aa60268 +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                     DAT_23e5aa60268 + dVar30;
          }
          unaff_R12B = '\x01';
          if ((dVar26 < local_f0) &&
             (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x22),
             DAT_23e5aa7a448 <= dVar26)) goto LAB_23e5aa3e444;
        }
        dVar30 = DAT_23e5aa77760;
        dVar26 = DAT_23e5aa72580;
        if (((((byte)local_12c & DAT_23e5aa723f0 == 1) == 1) &&
            ((0.0 < DAT_23e5aa72400 &&
             (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
             dVar30 < (dVar26 - DAT_23e5aa7a448) - DAT_23e5aa72400 * DAT_23e5aa76d98)))) &&
           ((DAT_23e5aa77760 < dVar31 - DAT_23e5aa723f8 * DAT_23e5aa76d98 &&
            ((DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760 &&
             (dVar28 - DAT_23e5aa76d98 * DAT_23e5aa72408 < DAT_23e5aa72580)))))) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
          unaff_R12B = '\x01';
          DAT_23e5aa72580 = DAT_23e5aa72400 * DAT_23e5aa76d98 + DAT_23e5aa77760;
        }
        if (((0 < DAT_23e5aa724e4) &&
            (dVar26 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8),
            dVar31 = DAT_23e5aa72580 - DAT_23e5aa76a70,
            MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
            dVar26 < dVar31 - DAT_23e5aa7a448)) &&
           ((dVar26 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8),
            dVar28 < dVar26 || ((DAT_23e5aa724d8 & 1) == 0)))) {
          if (DAT_23e5aa724ec == '\0') {
            uVar23 = 0;
            uVar25 = 0;
          }
          else {
            uVar23 = SUB84(DAT_23e5aa60270,0);
            uVar25 = (undefined4)((ulonglong)DAT_23e5aa60270 >> 0x20);
          }
          dVar31 = (double)CONCAT44(uVar25,uVar23) * DAT_23e5aa76d98 + DAT_23e5aa77760 +
                   DAT_23e5aa76a70;
          MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
          if ((dVar31 + DAT_23e5aa7a448 < dVar26) && (DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760)) {
            unaff_R12B = '\x01';
            DAT_23e5aa72580 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8);
          }
        }
        dVar26 = DAT_23e5aa72580;
        if ((((DAT_23e5aa724c8 <= 0.0) || (DAT_23e5aa7241c != 2)) ||
            (dVar28 - DAT_23e5aa724c8 * DAT_23e5aa76d98 <= DAT_23e5aa77760)) ||
           (dVar31 = DAT_23e5aa76d98 * DAT_23e5aa724d0,
           MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
           dVar26 - DAT_23e5aa7a448 <= dVar28 - dVar31)) {
LAB_23e5aa3d7dd:
          if (unaff_R12B == '\0') {
            uVar23 = SUB84(DAT_23e5aa77760,0);
            uVar25 = (undefined4)((ulonglong)DAT_23e5aa77760 >> 0x20);
            if (DAT_23e5aa72508 == '\x01') {
              DAT_23e5aa773f0 = DAT_23e5aa773f0 + 1;
              dVar28 = DAT_23e5aa72580 - DAT_23e5aa72520 * DAT_23e5aa76d98;
              if (((DAT_23e5aa77760 < dVar28 - DAT_23e5aa76a70) &&
                  (dVar27 + DAT_23e5aa77468 < DAT_23e5aa77760)) &&
                 ((((DAT_23e5aa72510 == 0.0 && (!NAN(DAT_23e5aa72510))) ||
                   (DAT_23e5aa77760 < dVar29 - DAT_23e5aa76d98 * DAT_23e5aa773e8)) &&
                  (DAT_23e5aa72518 <= DAT_23e5aa773f0)))) {
                DAT_23e5aa773f0 = 0;
                goto LAB_23e5aa3dc96;
              }
            }
            unaff_R12B = '\0';
          }
          if (DAT_23e5aa72580 <= DAT_23e5aa77760) goto LAB_23e5aa3e438;
        }
        else {
          uVar23 = SUB84(DAT_23e5aa77760,0);
          uVar25 = (undefined4)((ulonglong)DAT_23e5aa77760 >> 0x20);
          dVar28 = dVar28 - DAT_23e5aa724d0 * DAT_23e5aa76d98;
          if ((dVar28 - DAT_23e5aa76a70 <= DAT_23e5aa77760) ||
             (DAT_23e5aa77760 <= DAT_23e5aa77468 + dVar27)) goto LAB_23e5aa3d7dd;
LAB_23e5aa3dc96:
          unaff_R12B = '\x01';
          DAT_23e5aa72580 = dVar28;
          if (dVar28 <= (double)CONCAT44(uVar25,uVar23)) goto LAB_23e5aa3e438;
        }
        uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        if ((longlong)dVar24 != -0x8000000000000000) {
          dVar26 = (double)(longlong)dVar24;
          uVar22 = uVar16 & 0xffffffff;
          if (10 < (uint)uVar16) {
            uVar22 = 0xb;
          }
          dVar24 = (double)(longlong)
                           ((dVar24 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                           *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar24) * 8)) /
                   *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar26;
        }
        uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        dVar26 = DAT_23e5aa72580;
        if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
          dVar26 = (double)(longlong)DAT_23e5aa72580;
          uVar22 = uVar16 & 0xffffffff;
          if (10 < (uint)uVar16) {
            uVar22 = 0xb;
          }
          dVar26 = (double)(longlong)
                           ((DAT_23e5aa72580 - dVar26) * *(double *)(&DAT_23e5aa61600 + uVar22 * 8)
                           + *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8))
                   / *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar26;
        }
        if ((dVar24 != dVar26) || (NAN(dVar24) || NAN(dVar26))) {
          uVar16 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar26 = DAT_23e5aa72580;
          if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
            dVar26 = (double)(longlong)DAT_23e5aa72580;
            uVar22 = uVar16 & 0xffffffff;
            if (10 < (uint)uVar16) {
              uVar22 = 0xb;
            }
            dVar26 = (double)(longlong)
                             ((DAT_23e5aa72580 - dVar26) *
                              *(double *)(&DAT_23e5aa61600 + uVar22 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8))
                     / *(double *)(&DAT_23e5aa61600 + uVar22 * 8) + dVar26;
          }
          if (DAT_23e5aa76410 == '\x01') {
            lVar17 = -12000;
            do {
              if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar17) == dVar8) &&
                 (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar17)) && !NAN(dVar8))) {
                *(double *)((longlong)&DAT_23e5aa75478 + lVar17) = dVar26;
                break;
              }
              lVar17 = lVar17 + 0x18;
            } while (lVar17 != 0);
          }
        }
      }
      else {
        dVar24 = (double)FUN_23e5aa4d200(2,dVar28,DAT_23e5aa72498,uVar16);
        DAT_23e5aa72580 = dVar24;
        if (dVar24 < DAT_23e5aa77760) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
          pcVar21 = runtime_cast_to_string;
          runtime_cast_to_string((void *)0x23e575eae78,(ulonglong)DAT_23e5aa72580,0x58,&local_150);
          FUN_23e5aa105c0(&local_160,&string_ref_23e5aa658e8,0);
          lVar17 = local_14c;
          if (local_14c == 0) goto LAB_23e5aa3e0f8;
          uVar5 = *(uint *)(local_14c + -4);
          if ((uVar5 == 0) && (local_15c != 0)) goto LAB_23e5aa3e0f8;
          if (local_15c == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(uint *)(local_15c + -4);
          }
          cVar13 = FUN_23e5aa10060(&local_160);
          if (cVar13 == '\0') {
            (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x2916a4000001f9);
          }
          else {
            if (uVar5 != 0) {
              lVar18 = local_15c + (ulonglong)uVar6 * 2;
              if (uVar5 < 0x10) {
                uVar22 = 0;
                goto LAB_23e5aa3e0d8;
              }
              if ((ulonglong)(lVar18 - lVar17) < 0x20) {
                uVar22 = 0;
                goto LAB_23e5aa3e0d8;
              }
              uVar19 = 0;
              uVar22 = (ulonglong)(uVar5 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)(lVar17 + uVar19);
                uVar23 = puVar1[1];
                uVar25 = puVar1[2];
                uVar9 = puVar1[3];
                puVar2 = (undefined4 *)(lVar18 + uVar19);
                *puVar2 = *puVar1;
                puVar2[1] = uVar23;
                puVar2[2] = uVar25;
                puVar2[3] = uVar9;
                uVar19 = uVar19 + 0x10;
              } while (((ulonglong)uVar5 * 2 & 0xfffffffffffffff0) != uVar19);
              for (; uVar22 != uVar5; uVar22 = uVar22 + 1) {
LAB_23e5aa3e0d8:
                *(undefined2 *)(lVar18 + uVar22 * 2) = *(undefined2 *)(lVar17 + uVar22 * 2);
              }
            }
            *(uint *)(local_15c + -4) = uVar5 + uVar6;
            *(undefined2 *)(local_15c + (ulonglong)(uVar5 + uVar6) * 2) = 0;
LAB_23e5aa3e0f8:
            MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
            runtime_cast_to_string((void *)0x23e575eae78,(ulonglong)DAT_23e5aa77760,0x58,&local_150)
            ;
            FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65cd8,0);
            lVar17 = local_14c;
            if (local_14c == 0) {
LAB_23e5aa3e3f2:
              MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
LAB_23e5aa3e438:
              MT5_SymbolInfoTick((void *)0x23e575eae78,&DAT_23e5aa77918,&DAT_23e5aa77750);
LAB_23e5aa3e444:
              FUN_23e5aa4d010(uVar16);
              FUN_23e5aa10000(&local_110);
              FUN_23e5aa10000(&local_100);
              pcVar21 = (code *)CONCAT71((int7)((ulonglong)pcVar21 >> 8),1);
              goto LAB_23e5aa3e473;
            }
            uVar5 = *(uint *)(local_14c + -4);
            pcVar21 = (code *)(ulonglong)uVar5;
            if ((uVar5 == 0) && (local_15c != 0)) goto LAB_23e5aa3e3f2;
            if (local_15c == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = *(uint *)(local_15c + -4);
            }
            uVar22 = (ulonglong)(uVar5 + uVar6);
            cVar13 = FUN_23e5aa10060(&local_160);
            if (cVar13 != '\0') {
              if (uVar5 != 0) {
                lVar18 = local_15c + (ulonglong)uVar6 * 2;
                if (uVar5 < 0x10) {
                  pcVar20 = (code *)0x0;
                }
                else if ((ulonglong)(lVar18 - lVar17) < 0x20) {
                  pcVar20 = (code *)0x0;
                }
                else {
                  uVar19 = 0;
                  pcVar20 = (code *)(ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    puVar1 = (undefined4 *)(lVar17 + uVar19);
                    uVar23 = puVar1[1];
                    uVar25 = puVar1[2];
                    uVar9 = puVar1[3];
                    puVar2 = (undefined4 *)(lVar18 + uVar19);
                    *puVar2 = *puVar1;
                    puVar2[1] = uVar23;
                    puVar2[2] = uVar25;
                    puVar2[3] = uVar9;
                    uVar19 = uVar19 + 0x10;
                  } while (((longlong)pcVar21 * 2 & 0xfffffffffffffff0U) != uVar19);
                  if (pcVar20 == pcVar21) goto LAB_23e5aa3e3e4;
                }
                do {
                  *(undefined2 *)(lVar18 + (longlong)pcVar20 * 2) =
                       *(undefined2 *)(lVar17 + (longlong)pcVar20 * 2);
                  pcVar20 = pcVar20 + 1;
                } while (pcVar21 != pcVar20);
              }
              goto LAB_23e5aa3e3e4;
            }
          }
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x2716a5000001f9);
LAB_23e5aa3e540:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x291761000001f9);
LAB_23e5aa3e560:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x271762000001f9);
LAB_23e5aa3e580:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x3f16bb000001f9);
LAB_23e5aa3e5a0:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x6016bb000001f9);
LAB_23e5aa3e5c0:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x421700000001f9);
LAB_23e5aa3e5e0:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x631700000001f9);
LAB_23e5aa3e600:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x49173e000001f9);
LAB_23e5aa3e620:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x6a173e000001f9);
LAB_23e5aa3e640:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x3f16db000001f9);
LAB_23e5aa3e660:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x6016db000001f9);
LAB_23e5aa3e680:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x351722000001f9);
LAB_23e5aa3e6a0:
          (*(code *)&runtime_memory_helper_3959a0)(0x23e575eae78,0x561722000001f9);
          pcVar21 = (code *)swi(3);
          uVar16 = (*pcVar21)();
          return uVar16;
        }
        if (DAT_23e5aa724f8 <= 0.0) {
LAB_23e5aa3bc7b:
          local_140 = 0;
          dVar30 = DAT_23e5aa77760;
        }
        else {
          local_140 = 0;
          lVar17 = MT5_TimeCurrent((void *)0x23e575eae78,(void *)0x0);
          dVar30 = DAT_23e5aa77760;
          if (DAT_23e5aa7745c + local_118 <= lVar17) {
            MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
            if ((dVar30 < (dVar26 - DAT_23e5aa7a448) - DAT_23e5aa72500 * DAT_23e5aa76d98) &&
               (DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760)) {
              uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar30 = DAT_23e5aa72500 * DAT_23e5aa76d98 + DAT_23e5aa77760;
              if ((longlong)dVar30 != -0x8000000000000000) {
                dVar32 = (double)(longlong)dVar30;
                uVar19 = uVar22 & 0xffffffff;
                if (10 < (uint)uVar22) {
                  uVar19 = 0xb;
                }
                dVar30 = (double)(longlong)
                                 ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                                 *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
              }
              if (dVar26 <= dVar30) goto LAB_23e5aa3bc7b;
              uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar26 = DAT_23e5aa72500 * DAT_23e5aa76d98 + DAT_23e5aa77760;
              if ((longlong)dVar26 != -0x8000000000000000) {
                dVar30 = (double)(longlong)dVar26;
                uVar19 = uVar22 & 0xffffffff;
                if (10 < (uint)uVar22) {
                  uVar19 = 0xb;
                }
                dVar26 = (double)(longlong)
                                 ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                                 *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
              }
              if (DAT_23e5aa77760 + DAT_23e5aa76a70 < dVar26) {
                uVar22 = uVar16;
                iVar14 = FUN_23e5aa36d20(uVar16,dVar26,dVar27);
                local_140 = CONCAT71((int7)(uVar22 >> 8),1);
                dVar30 = DAT_23e5aa77760;
                if (iVar14 == 0) {
                  local_138 = uVar16;
                  FUN_23e5aa436d0(DAT_23e5aa7a410);
                  FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ee10);
                  FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ee20);
                  cVar12 = FUN_23e5aa104a0(&local_160,local_14c);
                  if (cVar12 != '\0') {
                    FUN_23e5aa105c0(&local_128,&local_160,0,&PTR_DAT_23e5aa6ee30);
                    cVar12 = FUN_23e5aa104a0(&local_128,literal_23e5aa6599c);
                    if (cVar12 != '\0') {
                      MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                      uVar16 = local_138;
                      dVar30 = DAT_23e5aa77760;
                      goto joined_r0x023e5aa3bc95;
                    }
                    goto LAB_23e5aa3e5a0;
                  }
                  goto LAB_23e5aa3e580;
                }
                goto joined_r0x023e5aa3bc95;
              }
            }
            goto LAB_23e5aa3bc7b;
          }
        }
joined_r0x023e5aa3bc95:
        DAT_23e5aa77760 = dVar30;
        if ((((0.0 < DAT_23e5aa724a8) &&
             (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
             dVar30 < (dVar26 - DAT_23e5aa7a448) -
                      (DAT_23e5aa724a8 + DAT_23e5aa724c0) * DAT_23e5aa76d98)) &&
            (DAT_23e5aa77760 < dVar29 - DAT_23e5aa724b0 * DAT_23e5aa76d98)) &&
           ((DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760 &&
            (dVar28 - DAT_23e5aa76d98 * DAT_23e5aa724b8 < dVar26)))) {
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar30 = DAT_23e5aa724a8 * DAT_23e5aa76d98 + DAT_23e5aa77760;
          if ((longlong)dVar30 != -0x8000000000000000) {
            dVar32 = (double)(longlong)dVar30;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar30 = (double)(longlong)
                             ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
          }
          if (dVar30 < dVar26) {
            uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
            dVar26 = DAT_23e5aa724a8 * DAT_23e5aa76d98 + DAT_23e5aa77760;
            if ((longlong)dVar26 != -0x8000000000000000) {
              dVar30 = (double)(longlong)dVar26;
              uVar19 = uVar22 & 0xffffffff;
              if (10 < (uint)uVar22) {
                uVar19 = 0xb;
              }
              dVar26 = (double)(longlong)
                               ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                               *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                       *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
            }
            if (DAT_23e5aa77760 + DAT_23e5aa76a70 < dVar26) {
              iVar14 = FUN_23e5aa36d20(uVar16,dVar26,dVar27);
              if (iVar14 == 0) {
                local_138 = uVar16;
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ee40);
                FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ee50);
                cVar12 = FUN_23e5aa104a0(&local_160,local_14c);
                if (cVar12 == '\0') goto LAB_23e5aa3e640;
                FUN_23e5aa105c0(&local_128,&local_160,0,&PTR_DAT_23e5aa6ee60);
                cVar12 = FUN_23e5aa104a0(&local_128,literal_23e5aa65a4c);
                if (cVar12 == '\0') goto LAB_23e5aa3e660;
                lVar17 = MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
                local_140 = CONCAT71((int7)((ulonglong)lVar17 >> 8),1);
                uVar16 = local_138;
              }
              else {
                dVar30 = (double)(&DAT_23e5aa76a80)[DAT_23e5aa778f4] * 0.0;
                lVar17 = (longlong)dVar30;
                if (lVar17 != -0x8000000000000000) {
                  dVar32 = (double)lVar17;
                  lVar17 = (longlong)
                           ((dVar30 - dVar32) * DAT_23e5aa60268 +
                           *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8));
                  dVar30 = (double)lVar17 / DAT_23e5aa60268 + dVar32;
                }
                local_140 = CONCAT71((int7)((ulonglong)lVar17 >> 8),1);
                if ((dVar30 < local_f0) &&
                   (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x22),
                   DAT_23e5aa7a448 <= dVar30)) goto LAB_23e5aa3e444;
              }
            }
          }
        }
        dVar30 = DAT_23e5aa77760;
        if ((((DAT_23e5aa723f0 == 1 & (byte)local_12c) == 1) &&
            (((0.0 < DAT_23e5aa72400 &&
              (MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
              dVar30 < (dVar26 - DAT_23e5aa7a448) - DAT_23e5aa72400 * DAT_23e5aa76d98)) &&
             (DAT_23e5aa77760 < dVar31 - DAT_23e5aa723f8 * DAT_23e5aa76d98)))) &&
           ((DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760 &&
            (dVar28 - DAT_23e5aa76d98 * DAT_23e5aa72408 < dVar26)))) {
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar30 = DAT_23e5aa72400 * DAT_23e5aa76d98 + DAT_23e5aa77760;
          if ((longlong)dVar30 != -0x8000000000000000) {
            dVar32 = (double)(longlong)dVar30;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar30 = (double)(longlong)
                             ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
          }
          if (dVar30 < dVar26) {
            uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
            dVar26 = DAT_23e5aa72400 * DAT_23e5aa76d98 + DAT_23e5aa77760;
            if ((longlong)dVar26 != -0x8000000000000000) {
              dVar30 = (double)(longlong)dVar26;
              uVar19 = uVar22 & 0xffffffff;
              if (10 < (uint)uVar22) {
                uVar19 = 0xb;
              }
              dVar26 = (double)(longlong)
                               ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                               *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                       *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
            }
            if (DAT_23e5aa77760 + DAT_23e5aa76a70 < dVar26) {
              iVar14 = FUN_23e5aa36d20(uVar16,dVar26,dVar27);
              if (iVar14 == 0) {
                local_138 = uVar16;
                FUN_23e5aa436d0(DAT_23e5aa7a410);
                FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ee70);
                FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65978,0,&PTR_DAT_23e5aa6ee80);
                cVar12 = FUN_23e5aa104a0(&local_160,local_14c);
                if (cVar12 == '\0') goto LAB_23e5aa3e5c0;
                FUN_23e5aa105c0(&local_128,&local_160,0,&PTR_DAT_23e5aa6ee90);
                cVar12 = FUN_23e5aa104a0(&local_128,literal_23e5aa65acc);
                uVar16 = local_138;
                if (cVar12 == '\0') goto LAB_23e5aa3e5e0;
              }
              lVar17 = MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
              local_140 = CONCAT71((int7)((ulonglong)lVar17 >> 8),1);
            }
          }
        }
        if ((((DAT_23e5aa724e4 < 1) || (cVar13 == '\0')) ||
            ((dVar32 = dVar26 - DAT_23e5aa76a70,
             dVar30 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8),
             MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
             dVar32 - DAT_23e5aa7a448 <= dVar30 ||
             (dVar30 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8),
             dVar30 <= (double)DAT_23e5aa72360 * DAT_23e5aa76d98 + DAT_23e5aa77760)))) ||
           ((dVar30 <= dVar28 && ((DAT_23e5aa724d8 & 1) != 0)))) {
joined_r0x023e5aa3c7ae:
          if (DAT_23e5aa724c8 <= 0.0) goto LAB_23e5aa3cb0a;
LAB_23e5aa3c7b4:
          if ((((dVar28 - DAT_23e5aa724c8 * DAT_23e5aa76d98 <= DAT_23e5aa77760) ||
               (dVar30 = DAT_23e5aa76d98 * DAT_23e5aa724d0,
               MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10),
               dVar26 - DAT_23e5aa7a448 <= dVar28 - dVar30)) ||
              ((dVar28 - DAT_23e5aa724d0 * DAT_23e5aa76d98) - DAT_23e5aa76a70 <= DAT_23e5aa77760))
             || (DAT_23e5aa77760 <= DAT_23e5aa77468 + dVar27)) goto LAB_23e5aa3cb0a;
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar30 = dVar28 - DAT_23e5aa724d0 * DAT_23e5aa76d98;
          if ((longlong)dVar30 != -0x8000000000000000) {
            dVar32 = (double)(longlong)dVar30;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar30 = (double)(longlong)
                             ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
          }
          if (dVar26 <= dVar30) goto LAB_23e5aa3cb0a;
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar26 = dVar28 - DAT_23e5aa724d0 * DAT_23e5aa76d98;
          if ((longlong)dVar26 != -0x8000000000000000) {
            dVar30 = (double)(longlong)dVar26;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar26 = (double)(longlong)
                             ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
          }
          if (dVar26 <= DAT_23e5aa77760 + DAT_23e5aa76a70) goto LAB_23e5aa3cb0a;
          iVar14 = FUN_23e5aa36d20(uVar16,dVar26,dVar27);
          unaff_R12B = '\x01';
          if (iVar14 == 0) {
            local_138 = uVar16;
            FUN_23e5aa436d0(DAT_23e5aa7a410);
            FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6eed0);
            FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65c00,0,&PTR_DAT_23e5aa6eee0);
            cVar12 = FUN_23e5aa104a0(&local_160,local_14c);
            if (cVar12 == '\0') goto LAB_23e5aa3e600;
            FUN_23e5aa105c0(&local_128,&local_160,0,&PTR_DAT_23e5aa6eef0);
            cVar12 = FUN_23e5aa104a0(&local_128,literal_23e5aa65c1c);
            if (cVar12 == '\0') goto LAB_23e5aa3e620;
            MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
            uVar16 = local_138;
          }
        }
        else {
          dVar32 = DAT_23e5aa60270;
          if (DAT_23e5aa724ec == '\0') {
            dVar32 = 0.0;
          }
          dVar32 = DAT_23e5aa77760 + DAT_23e5aa76d98 * dVar32 + DAT_23e5aa76a70;
          MT5_SymbolInfoDouble((void *)0x23e575eae78,&DAT_23e5aa77918,0x10);
          if ((dVar30 <= dVar32 + DAT_23e5aa7a448) || (DAT_23e5aa77760 <= DAT_23e5aa77468 + dVar27))
          goto joined_r0x023e5aa3c7ae;
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar30 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8);
          if ((longlong)dVar30 != -0x8000000000000000) {
            dVar32 = (double)(longlong)dVar30;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar30 = (double)(longlong)
                             ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
          }
          if (dVar26 <= dVar30) goto joined_r0x023e5aa3c7ae;
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar26 = *(double *)(&DAT_23e5aa76db0 + (ulonglong)DAT_23e5aa778f4 * 8);
          if ((longlong)dVar26 != -0x8000000000000000) {
            dVar30 = (double)(longlong)dVar26;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar26 = (double)(longlong)
                             ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                     *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
          }
          if (dVar26 <= DAT_23e5aa77760 + DAT_23e5aa76a70) goto joined_r0x023e5aa3c7ae;
          uVar22 = uVar16;
          iVar14 = FUN_23e5aa36d20(uVar16,dVar26,dVar27);
          local_140 = CONCAT71((int7)(uVar22 >> 8),1);
          if (iVar14 != 0) goto joined_r0x023e5aa3c7ae;
          local_138 = uVar16;
          FUN_23e5aa436d0(DAT_23e5aa7a410);
          FUN_23e5aa105c0(&local_150,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6eea0);
          FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65140,0,&PTR_DAT_23e5aa6eeb0);
          cVar12 = FUN_23e5aa104a0(&local_160,local_14c);
          if (cVar12 == '\0') goto LAB_23e5aa3e680;
          FUN_23e5aa105c0(&local_128,&local_160,0,&PTR_DAT_23e5aa6eec0);
          cVar12 = FUN_23e5aa104a0(&local_128,literal_23e5aa65b7c);
          if (cVar12 == '\0') goto LAB_23e5aa3e6a0;
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
          uVar16 = local_138;
          if (0.0 < DAT_23e5aa724c8) goto LAB_23e5aa3c7b4;
LAB_23e5aa3cb0a:
          unaff_R12B = '\x01';
          if ((char)local_140 == '\0') {
            if (((((DAT_23e5aa72508 == '\x01') &&
                  (DAT_23e5aa773f0 = DAT_23e5aa773f0 + 1,
                  DAT_23e5aa77760 < (dVar26 - DAT_23e5aa72520 * DAT_23e5aa76d98) - DAT_23e5aa76a70))
                 && (DAT_23e5aa77468 + dVar27 < DAT_23e5aa77760)) &&
                (((DAT_23e5aa72510 == 0.0 && (!NAN(DAT_23e5aa72510))) ||
                 (DAT_23e5aa77760 < dVar29 - DAT_23e5aa76d98 * DAT_23e5aa773e8)))) &&
               (DAT_23e5aa72518 <= DAT_23e5aa773f0)) {
              uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
              dVar30 = dVar26 - DAT_23e5aa72520 * DAT_23e5aa76d98;
              if ((longlong)dVar30 != -0x8000000000000000) {
                dVar32 = (double)(longlong)dVar30;
                uVar19 = uVar22 & 0xffffffff;
                if (10 < (uint)uVar22) {
                  uVar19 = 0xb;
                }
                dVar30 = (double)(longlong)
                                 ((dVar30 - dVar32) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                                 *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar30) * 8)) /
                         *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar32;
              }
              if (dVar30 < dVar26) {
                DAT_23e5aa773f0 = 0;
                uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
                dVar26 = dVar26 - DAT_23e5aa72520 * DAT_23e5aa76d98;
                if ((longlong)dVar26 != -0x8000000000000000) {
                  dVar30 = (double)(longlong)dVar26;
                  uVar19 = uVar22 & 0xffffffff;
                  if (10 < (uint)uVar22) {
                    uVar19 = 0xb;
                  }
                  dVar26 = (double)(longlong)
                                   ((dVar26 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                                   *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar26) * 8)) /
                           *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
                }
                FUN_23e5aa36d20(uVar16,dVar26,dVar27);
                goto LAB_23e5aa3cd92;
              }
            }
            unaff_R12B = '\0';
          }
        }
LAB_23e5aa3cd92:
        DAT_23e5aa72580 = dVar26;
        if (dVar26 < DAT_23e5aa77760) {
          MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
          pcVar21 = runtime_cast_to_string;
          runtime_cast_to_string((void *)0x23e575eae78,(ulonglong)DAT_23e5aa72580,0x58,&local_150);
          FUN_23e5aa105c0(&local_160,&string_ref_23e5aa658e8,0);
          lVar17 = local_14c;
          if (local_14c == 0) goto LAB_23e5aa3e29a;
          uVar5 = *(uint *)(local_14c + -4);
          if ((uVar5 == 0) && (local_15c != 0)) goto LAB_23e5aa3e29a;
          if (local_15c == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(uint *)(local_15c + -4);
          }
          cVar13 = FUN_23e5aa10060(&local_160);
          if (cVar13 != '\0') {
            if (uVar5 != 0) {
              lVar18 = local_15c + (ulonglong)uVar6 * 2;
              if (uVar5 < 0x10) {
                uVar22 = 0;
                goto LAB_23e5aa3e27a;
              }
              if ((ulonglong)(lVar18 - lVar17) < 0x20) {
                uVar22 = 0;
                goto LAB_23e5aa3e27a;
              }
              uVar19 = 0;
              uVar22 = (ulonglong)(uVar5 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)(lVar17 + uVar19);
                uVar23 = puVar1[1];
                uVar25 = puVar1[2];
                uVar9 = puVar1[3];
                puVar2 = (undefined4 *)(lVar18 + uVar19);
                *puVar2 = *puVar1;
                puVar2[1] = uVar23;
                puVar2[2] = uVar25;
                puVar2[3] = uVar9;
                uVar19 = uVar19 + 0x10;
              } while (((ulonglong)uVar5 * 2 & 0xfffffffffffffff0) != uVar19);
              for (; uVar22 != uVar5; uVar22 = uVar22 + 1) {
LAB_23e5aa3e27a:
                *(undefined2 *)(lVar18 + uVar22 * 2) = *(undefined2 *)(lVar17 + uVar22 * 2);
              }
            }
            *(uint *)(local_15c + -4) = uVar5 + uVar6;
            *(undefined2 *)(local_15c + (ulonglong)(uVar5 + uVar6) * 2) = 0;
LAB_23e5aa3e29a:
            MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
            runtime_cast_to_string((void *)0x23e575eae78,(ulonglong)DAT_23e5aa77760,0x58,&local_150)
            ;
            FUN_23e5aa105c0(&local_160,&string_ref_23e5aa65cd8,0);
            lVar17 = local_14c;
            if (local_14c != 0) {
              uVar5 = *(uint *)(local_14c + -4);
              pcVar21 = (code *)(ulonglong)uVar5;
              if ((uVar5 != 0) || (local_15c == 0)) {
                if (local_15c == 0) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = *(uint *)(local_15c + -4);
                }
                uVar22 = (ulonglong)(uVar5 + uVar6);
                cVar13 = FUN_23e5aa10060(&local_160);
                if (cVar13 == '\0') goto LAB_23e5aa3e560;
                if (uVar5 != 0) {
                  lVar18 = local_15c + (ulonglong)uVar6 * 2;
                  if (uVar5 < 0x10) {
                    pcVar20 = (code *)0x0;
                  }
                  else if ((ulonglong)(lVar18 - lVar17) < 0x20) {
                    pcVar20 = (code *)0x0;
                  }
                  else {
                    uVar19 = 0;
                    pcVar20 = (code *)(ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      puVar1 = (undefined4 *)(lVar17 + uVar19);
                      uVar23 = puVar1[1];
                      uVar25 = puVar1[2];
                      uVar9 = puVar1[3];
                      puVar2 = (undefined4 *)(lVar18 + uVar19);
                      *puVar2 = *puVar1;
                      puVar2[1] = uVar23;
                      puVar2[2] = uVar25;
                      puVar2[3] = uVar9;
                      uVar19 = uVar19 + 0x10;
                    } while (((longlong)pcVar21 * 2 & 0xfffffffffffffff0U) != uVar19);
                    if (pcVar20 == pcVar21) goto LAB_23e5aa3e3e4;
                  }
                  do {
                    *(undefined2 *)(lVar18 + (longlong)pcVar20 * 2) =
                         *(undefined2 *)(lVar17 + (longlong)pcVar20 * 2);
                    pcVar20 = pcVar20 + 1;
                  } while (pcVar21 != pcVar20);
                }
LAB_23e5aa3e3e4:
                *(int *)(local_15c + -4) = (int)uVar22;
                *(undefined2 *)(local_15c + uVar22 * 2) = 0;
              }
            }
            goto LAB_23e5aa3e3f2;
          }
          goto LAB_23e5aa3e540;
        }
        uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        if ((longlong)dVar24 != -0x8000000000000000) {
          dVar30 = (double)(longlong)dVar24;
          uVar19 = uVar22 & 0xffffffff;
          if (10 < (uint)uVar22) {
            uVar19 = 0xb;
          }
          dVar24 = (double)(longlong)
                           ((dVar24 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                           *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < dVar24) * 8)) /
                   *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
        }
        uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
        dVar30 = DAT_23e5aa72580;
        if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
          dVar30 = (double)(longlong)DAT_23e5aa72580;
          uVar19 = uVar22 & 0xffffffff;
          if (10 < (uint)uVar22) {
            uVar19 = 0xb;
          }
          dVar30 = (double)(longlong)
                           ((DAT_23e5aa72580 - dVar30) * *(double *)(&DAT_23e5aa61600 + uVar19 * 8)
                           + *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8))
                   / *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar30;
        }
        if ((dVar24 != dVar30) || (NAN(dVar24) || NAN(dVar30))) {
          uVar22 = MT5_SymbolInfoInteger((void *)0x23e575eae78,&DAT_23e5aa77918,0x11);
          dVar24 = DAT_23e5aa72580;
          if ((longlong)DAT_23e5aa72580 != -0x8000000000000000) {
            dVar24 = (double)(longlong)DAT_23e5aa72580;
            uVar19 = uVar22 & 0xffffffff;
            if (10 < (uint)uVar22) {
              uVar19 = 0xb;
            }
            dVar24 = (double)(longlong)
                             ((DAT_23e5aa72580 - dVar24) *
                              *(double *)(&DAT_23e5aa61600 + uVar19 * 8) +
                             *(double *)(&DAT_23e5aa60250 + (ulonglong)(0.0 < DAT_23e5aa72580) * 8))
                     / *(double *)(&DAT_23e5aa61600 + uVar19 * 8) + dVar24;
          }
          if (DAT_23e5aa76410 == '\x01') {
            lVar17 = -12000;
            do {
              if ((*(double *)((longlong)&DAT_23e5aa75470 + lVar17) == dVar8) &&
                 (!NAN(*(double *)((longlong)&DAT_23e5aa75470 + lVar17)) && !NAN(dVar8))) {
                *(double *)((longlong)&DAT_23e5aa75478 + lVar17) = dVar24;
                break;
              }
              lVar17 = lVar17 + 0x18;
            } while (lVar17 != 0);
          }
        }
        if (DAT_23e5aa7241c == 2) goto LAB_23e5aa3cfcb;
      }
      if (unaff_R12B != '\0') {
        pcVar21 = (code *)0x1;
      }
    }
  }
  else {
    MT5_Dispatch((void *)0x23e575eae78,2,1,0x590008);
    if ((int)lVar17 == 1) goto LAB_23e5aa3b10d;
LAB_23e5aa3ad00:
    unaff_R12B = '\0';
  }
LAB_23e5aa3ad03:
  FUN_23e5aa10000(&local_110);
  FUN_23e5aa10000(&local_100);
  iVar14 = local_f4;
LAB_23e5aa3ad25:
  if (unaff_R12B != '\0') {
    pcVar21 = (code *)0x1;
  }
  iVar14 = iVar14 + 1;
  iVar15 = MT5_PositionsTotal((void *)0x23e575eae78);
  if (iVar15 <= iVar14) goto LAB_23e5aa3e473;
  goto LAB_23e5aa3ad4c;
}



