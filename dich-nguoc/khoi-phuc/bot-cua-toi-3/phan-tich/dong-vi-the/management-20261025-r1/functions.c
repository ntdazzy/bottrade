// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:22943
/* Address: 17156282f60 */

/* WARNING: Removing unreachable block (ram,0x017156283bee) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

ulonglong FUN_17156282f60(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  ulonglong uVar14;
  code *pcVar15;
  char unaff_R12B;
  ulonglong uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  undefined4 local_158;
  undefined8 local_154;
  char local_149;
  ulonglong local_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined8 local_134;
  undefined4 local_12c;
  longlong local_128;
  undefined4 local_120;
  undefined8 local_11c;
  double local_110;
  undefined4 local_108;
  longlong local_104;
  undefined4 local_f8;
  undefined8 local_f4;
  int local_ec;
  
  local_138 = 0;
  local_120 = 0;
  local_158 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_134 = 0;
  local_11c = 0;
  local_154 = 0;
  local_f4 = 0;
  local_104 = 0;
  iVar9 = MT5_PositionsTotal((void *)0x171514ca538);
  if (iVar9 < 1) {
    pcVar15 = (code *)0x0;
  }
  else {
    iVar9 = 0;
    pcVar15 = (code *)0x0;
    local_149 = DAT_17156426fa0;
    do {
      DAT_171562c4838 = MT5_PositionGetTicket((void *)0x171514ca538,iVar9);
      if (DAT_171562c4838 != 0) {
        local_ec = iVar9;
        uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        MT5_PositionGetDouble((void *)0x171514ca538,6);
        dVar20 = DAT_17156426e48;
        if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
          dVar20 = (double)(longlong)DAT_17156426e48;
          uVar16 = uVar11 & 0xffffffff;
          if (10 < (uint)uVar11) {
            uVar16 = 0xb;
          }
          dVar20 = (double)(longlong)
                           ((DAT_17156426e48 - dVar20) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                           + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < DAT_17156426e48) * 8))
                   / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
        }
        uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        MT5_PositionGetDouble((void *)0x171514ca538,7);
        dVar21 = DAT_17156426e48;
        if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
          dVar21 = (double)(longlong)DAT_17156426e48;
          uVar16 = uVar11 & 0xffffffff;
          if (10 < (uint)uVar11) {
            uVar16 = 0xb;
          }
          dVar21 = (double)(longlong)
                           ((DAT_17156426e48 - dVar21) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                           + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < DAT_17156426e48) * 8))
                   / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar21;
        }
        dVar6 = (double)(longlong)DAT_171562c4838;
        uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        MT5_PositionGetDouble((void *)0x171514ca538,4);
        dVar22 = DAT_17156426e48;
        if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
          dVar22 = (double)(longlong)DAT_17156426e48;
          uVar16 = uVar11 & 0xffffffff;
          if (10 < (uint)uVar11) {
            uVar16 = 0xb;
          }
          dVar22 = (double)(longlong)
                           ((DAT_17156426e48 - dVar22) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                           + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < DAT_17156426e48) * 8))
                   / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar22;
        }
        local_f8 = 0;
        local_f4 = 0;
        MT5_PositionGetString((void *)0x171514ca538,0xb);
        FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b8fd0);
        FUN_171562505c0(&local_f8,&local_158,0,&PTR_DAT_171562b8fe0);
        MT5_PositionGetDouble((void *)0x171514ca538,3);
        dVar19 = DAT_17156426e48;
        local_128 = MT5_PositionGetInteger((void *)0x171514ca538,1);
        lVar12 = MT5_PositionGetInteger((void *)0x171514ca538,2);
        lVar13 = MT5_PositionGetInteger((void *)0x171514ca538,0xc);
        local_108 = 0;
        local_104 = 0;
        MT5_PositionGetString((void *)0x171514ca538,0);
        FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b8ff0);
        FUN_171562505c0(&local_108,&local_158,0,&PTR_DAT_171562b9000);
        bVar7 = MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
        if (!bVar7) {
          MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
        }
        if ((int)lVar12 == 0) {
          unaff_R12B = '\0';
          if ((DAT_171562bd564 == (int)lVar13) && (DAT_171562bd520 == 1)) {
            if (local_104 != DAT_171562c495c) {
              unaff_R12B = '\0';
              if ((local_104 == 0) || (DAT_171562c495c == 0)) goto LAB_171562830a3;
              uVar3 = *(uint *)(local_104 + -4);
              uVar4 = *(uint *)(DAT_171562c495c + -4);
              uVar5 = uVar4;
              if (uVar3 < uVar4) {
                uVar5 = uVar3;
              }
              iVar9 = uVar3 - uVar4;
              if (uVar5 != 0) {
                uVar11 = 1;
                do {
                  uVar1 = *(ushort *)(local_104 + -2 + uVar11 * 2);
                  uVar2 = *(ushort *)(DAT_171562c495c + -2 + uVar11 * 2);
                  if (uVar5 <= uVar11) break;
                  uVar11 = uVar11 + 1;
                } while (uVar1 == uVar2);
                if (uVar1 != uVar2) {
                  iVar9 = (uint)uVar1 - (uint)uVar2;
                }
              }
              if (iVar9 != 0) goto LAB_171562830a0;
            }
            if ((dVar20 == 0.0) && (!NAN(dVar20))) {
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar20 = dVar22 - DAT_171562bd588 * DAT_171562c3dd8;
              if ((longlong)dVar20 != -0x8000000000000000) {
                dVar23 = (double)(longlong)dVar20;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar20 = (double)(longlong)
                                 ((dVar20 - dVar23) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar23;
              }
              FUN_17156282a90((longlong)dVar6,dVar20);
            }
            if ((dVar21 == 0.0) && (!NAN(dVar21))) {
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar21 = DAT_171562bd590 * DAT_171562c3dd8 + dVar22;
              if ((longlong)dVar21 != -0x8000000000000000) {
                dVar23 = (double)(longlong)dVar21;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar21 = (double)(longlong)
                                 ((dVar21 - dVar23) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar21) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar23;
              }
              FUN_17156282a90((longlong)dVar6,dVar20);
            }
            if (((DAT_171562bd29e == '\x01') &&
                (lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,
                                    (uint)DAT_171562bd29c), lVar12 <= local_128)) &&
               (lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,0),
               local_128 < lVar12)) {
              MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1);
              dVar23 = DAT_17156426e48;
              MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1);
              if ((dVar23 < DAT_17156426e48) &&
                 (MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1),
                 DAT_17156426e48 < dVar22)) {
                FUN_17156297d20((longlong)dVar6);
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
              }
            }
            if (DAT_171562bd2a0 == '\x01') {
              iVar9 = 0;
              if (DAT_171562bd29f != '\0') {
                iVar9 = 0xf;
              }
              lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar9,(uint)DAT_171562bd29c)
              ;
              if (lVar12 <= local_128) {
                iVar9 = 0;
                if (DAT_171562bd29f != '\0') {
                  iVar9 = 0xf;
                }
                lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar9,0);
                if (local_128 < lVar12) {
                  iVar9 = 0;
                  if (DAT_171562bd29f != '\0') {
                    iVar9 = 0xf;
                  }
                  MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                  dVar23 = DAT_17156426e48;
                  iVar9 = 0;
                  if (DAT_171562bd29f != '\0') {
                    iVar9 = 0xf;
                  }
                  MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                  if (dVar23 < DAT_17156426e48) {
                    iVar9 = 0;
                    if (DAT_171562bd29f != '\0') {
                      iVar9 = 0xf;
                    }
                    MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                    if (DAT_17156426e48 < dVar22) {
                      FUN_17156297d20((longlong)dVar6);
                      MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                    }
                  }
                }
              }
            }
            if (DAT_171562bd2a2 == '\x01') {
              iVar9 = 0;
              if (DAT_171562bd2a1 != '\0') {
                iVar9 = 0x4001;
              }
              lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar9,(uint)DAT_171562bd29c)
              ;
              if (lVar12 <= local_128) {
                iVar9 = 0;
                if (DAT_171562bd2a1 != '\0') {
                  iVar9 = 0x4001;
                }
                lVar12 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar9,0);
                if (local_128 < lVar12) {
                  iVar9 = 0;
                  if (DAT_171562bd2a1 != '\0') {
                    iVar9 = 0x4001;
                  }
                  MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                  dVar23 = DAT_17156426e48;
                  iVar9 = 0;
                  if (DAT_171562bd2a1 != '\0') {
                    iVar9 = 0x4001;
                  }
                  MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                  if (dVar23 < DAT_17156426e48) {
                    iVar9 = 0;
                    if (DAT_171562bd2a1 != '\0') {
                      iVar9 = 0x4001;
                    }
                    MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar9,1);
                    if (DAT_17156426e48 < dVar22) {
                      FUN_17156297d20((longlong)dVar6);
                      MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                    }
                  }
                }
              }
            }
            DAT_171562c4428 = DAT_171562bd600;
            uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            local_148 = (ulonglong)dVar6;
            dVar6 = (double)(longlong)local_148;
            lVar12 = -0x640;
            do {
              if ((*(double *)(&DAT_171562c3450 + lVar12) == dVar6) &&
                 (!NAN(*(double *)(&DAT_171562c3450 + lVar12)) && !NAN(dVar6))) {
                dVar23 = *(double *)((longlong)&DAT_171562c3458 + lVar12);
                lVar12 = (longlong)dVar23;
                if (lVar12 != -0x8000000000000000) goto LAB_17156283c17;
                goto LAB_17156283c76;
              }
              lVar12 = lVar12 + 0x10;
            } while (lVar12 != 0);
            dVar23 = 0.0;
            lVar12 = 0;
LAB_17156283c17:
            uVar16 = uVar11 & 0xffffffff;
            if (10 < (uint)uVar11) {
              uVar16 = 0xb;
            }
            dVar23 = (double)(longlong)
                             ((dVar23 - (double)lVar12) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                             + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar23) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar16 * 8) + (double)lVar12;
LAB_17156283c76:
            if ((dVar23 != 0.0) || (NAN(dVar23))) {
              dVar23 = dVar23 + DAT_171562c3dd8 * DAT_171562a8478;
            }
            else {
              lVar12 = -0x640;
              do {
                dVar23 = dVar22;
                if ((*(double *)(&DAT_171562c3450 + lVar12) == 0.0) &&
                   (!NAN(*(double *)(&DAT_171562c3450 + lVar12)))) {
                  *(double *)(&DAT_171562c3450 + lVar12) = dVar6;
                  *(double *)((longlong)&DAT_171562c3458 + lVar12) = dVar22;
                  break;
                }
                lVar12 = lVar12 + 0x10;
              } while (lVar12 != 0);
            }
            if ((dVar23 <= 0.0 - DAT_171562c3dd8 * 0.0) ||
               (dVar22 - dVar23 <= DAT_171562bd4e0 * DAT_171562c3dd8)) {
              local_12c = 0;
            }
            else {
              local_12c = 0x562bd401;
            }
            local_110 = dVar22;
            if (DAT_171562bd508 != '\0') {
              local_110 = dVar23;
            }
            if (DAT_171562c4798 <
                (dVar22 - DAT_171562c3dd8 * (DAT_171562bd588 + 0.0)) - DAT_171562bd650) {
              MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
              MT5_PositionGetDouble((void *)0x171514ca538,3);
              local_148 = DAT_171562c4838;
LAB_171562872ef:
              FUN_17156297d20(local_148);
              FUN_17156250000(&local_108);
              FUN_17156250000(&local_f8);
              pcVar15 = (code *)CONCAT71((int7)((ulonglong)pcVar15 >> 8),1);
              break;
            }
            if (DAT_171562bd514 == 2) {
              unaff_R12B = '\0';
LAB_17156285d65:
              dVar17 = (double)FUN_17156297f10(1,dVar22,DAT_171562bd588,local_148);
              DAT_171562bd670 = dVar17;
              dVar18 = (double)FUN_171562982b0(dVar21);
              DAT_171562c24a0 = dVar18;
              if ((DAT_171562c4798 <= DAT_171562bd670) ||
                 ((0.0 < dVar18 && (dVar18 <= DAT_171562c4798)))) {
LAB_171562872e3:
                MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
                goto LAB_171562872ef;
              }
              cVar8 = FUN_171562984c0(local_148);
              if (cVar8 != '\0') {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562bd670;
                if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                  dVar24 = (double)(longlong)DAT_171562bd670;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((DAT_171562bd670 - dVar24) *
                                    *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)
                                    (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar24;
                }
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                if (dVar20 + DAT_17156426e48 < dVar24) {
                  uVar16 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                  uVar11 = local_148;
                  dVar20 = DAT_171562bd670;
                  if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                    dVar20 = (double)(longlong)DAT_171562bd670;
                    uVar14 = uVar16 & 0xffffffff;
                    if (10 < (uint)uVar16) {
                      uVar14 = 0xb;
                    }
                    dVar20 = (double)(longlong)
                                     ((DAT_171562bd670 - dVar20) *
                                      *(double *)(&DAT_171562a9b40 + uVar14 * 8) +
                                     *(double *)
                                      (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                             *(double *)(&DAT_171562a9b40 + uVar14 * 8) + dVar20;
                  }
                  FUN_17156282a90(local_148,dVar20);
                  FUN_17156298560(uVar11);
                }
              }
              dVar20 = DAT_171562bd670;
              dVar24 = DAT_171562c4798;
              if ((0.0 < DAT_171562bd5e8) &&
                 (lVar12 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0),
                 dVar25 = DAT_171562c4798, dVar26 = DAT_171562bd670, dVar20 = DAT_171562bd670,
                 dVar24 = DAT_171562c4798, local_128 + DAT_171562c449c <= lVar12)) {
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar20 = DAT_171562bd670;
                dVar24 = DAT_171562c4798;
                if ((dVar26 + DAT_17156426e48 + DAT_171562bd5f0 * DAT_171562c3dd8 < dVar25) &&
                   (DAT_171562c4798 < dVar21 - DAT_171562c44a8)) {
                  unaff_R12B = '\x01';
                  dVar20 = DAT_171562c4798 - DAT_171562bd5f0 * DAT_171562c3dd8;
                }
              }
              DAT_171562bd670 = dVar20;
              DAT_171562c4798 = dVar24;
              if ((((0.0 < DAT_171562bd598) &&
                   (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
                   (DAT_171562bd5b0 + DAT_171562bd598) * DAT_171562c3dd8 + dVar20 + DAT_17156426e48
                   < dVar24)) && (DAT_171562bd5a0 * DAT_171562c3dd8 + local_110 < DAT_171562c4798))
                 && (DAT_171562bd670 < DAT_171562bd5a8 * DAT_171562c3dd8 + dVar22)) {
                DAT_171562bd670 = DAT_171562c4798 - DAT_171562bd598 * DAT_171562c3dd8;
                dVar20 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar24 = (double)(longlong)dVar20;
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar24) * DAT_171562a8480 +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           DAT_171562a8480 + dVar24;
                }
                unaff_R12B = '\x01';
                if ((dVar20 < dVar19) &&
                   (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                   DAT_17156426e48 <= dVar20)) goto LAB_171562872ef;
              }
              dVar20 = DAT_171562c47a0;
              if ((0.0 < DAT_171562bd378) && (0.0 < DAT_171562c24a0)) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562c24a0;
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar26 = DAT_171562c47a0;
                dVar24 = (dVar24 - DAT_17156426e48) - DAT_171562bd378 * DAT_171562c3dd8;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar25) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar25;
                }
                if (dVar20 < dVar24) {
                  uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                  dVar20 = local_110 - DAT_171562bd380 * DAT_171562c3dd8;
                  if ((longlong)dVar20 != -0x8000000000000000) {
                    dVar24 = (double)(longlong)dVar20;
                    uVar16 = uVar11 & 0xffffffff;
                    if (10 < (uint)uVar11) {
                      uVar16 = 0xb;
                    }
                    dVar20 = (double)(longlong)
                                     ((dVar20 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                                     + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)
                                     ) / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar24;
                  }
                  if (dVar26 < dVar20) {
                    uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                    DAT_171562c24a0 = DAT_171562bd378 * DAT_171562c3dd8 + DAT_171562c4798;
                    if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
                      dVar20 = (double)(longlong)DAT_171562c24a0;
                      uVar16 = uVar11 & 0xffffffff;
                      if (10 < (uint)uVar11) {
                        uVar16 = 0xb;
                      }
                      DAT_171562c24a0 =
                           (double)(longlong)
                                   ((DAT_171562c24a0 - dVar20) *
                                    *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)
                                    (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562c24a0) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
                    }
                    dVar20 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                    if ((longlong)dVar20 != -0x8000000000000000) {
                      dVar24 = (double)(longlong)dVar20;
                      dVar20 = (double)(longlong)
                                       ((dVar20 - dVar24) * DAT_171562a8480 +
                                       *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)
                                       ) / DAT_171562a8480 + dVar24;
                    }
                    unaff_R12B = '\x01';
                    if ((dVar20 < dVar19) &&
                       (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                       DAT_17156426e48 <= dVar20)) goto LAB_171562872ef;
                  }
                }
              }
              dVar19 = DAT_171562c4798;
              dVar20 = DAT_171562bd670;
              if (((((byte)local_12c & DAT_171562bd4e8 == 1) == 1) &&
                  (((0.0 < DAT_171562bd4f8 &&
                    (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
                    DAT_171562bd4f8 * DAT_171562c3dd8 + dVar20 + DAT_17156426e48 < dVar19)) &&
                   (dVar23 + DAT_171562bd4f0 * DAT_171562c3dd8 < DAT_171562c4798)))) &&
                 ((DAT_171562c4798 < dVar21 - DAT_171562c44a8 &&
                  (DAT_171562bd670 < DAT_171562c3dd8 * DAT_171562bd500 + dVar22)))) {
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                unaff_R12B = '\x01';
                DAT_171562bd670 = DAT_171562c4798 - DAT_171562bd4f8 * DAT_171562c3dd8;
              }
              if (((0 < DAT_171562bd5d4) &&
                  (dVar20 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8),
                  dVar19 = DAT_171562bd670 + DAT_171562c3ab0,
                  MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
                  dVar19 + DAT_17156426e48 < dVar20)) &&
                 ((dVar20 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8),
                  dVar20 < dVar22 || ((DAT_171562bd5c8 & 1) == 0)))) {
                dVar19 = DAT_171562a8488;
                if (DAT_171562bd5dc == '\0') {
                  dVar19 = 0.0;
                }
                dVar19 = (DAT_171562c4798 - dVar19 * DAT_171562c3dd8) - DAT_171562c3ab0;
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                if ((dVar20 < dVar19 - DAT_17156426e48) &&
                   (DAT_171562c4798 < dVar21 - DAT_171562c44a8)) {
                  unaff_R12B = '\x01';
                  DAT_171562bd670 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8);
                }
              }
              dVar20 = DAT_171562bd670;
              if ((((DAT_171562bd5b8 <= 0.0) || (DAT_171562bd514 != 2)) ||
                  (DAT_171562c4798 <= DAT_171562bd5b8 * DAT_171562c3dd8 + dVar22)) ||
                 (((dVar19 = DAT_171562c3dd8 * DAT_171562bd5c0,
                   MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
                   dVar19 + dVar22 <= dVar20 + DAT_17156426e48 ||
                   (dVar22 = dVar22 + DAT_171562bd5c0 * DAT_171562c3dd8,
                   DAT_171562c4798 <= DAT_171562c3ab0 + dVar22)) ||
                  (dVar21 - DAT_171562c44a8 <= DAT_171562c4798)))) {
                if (unaff_R12B == '\0') {
                  if (DAT_171562bd5f8 == '\x01') {
                    DAT_171562c4430 = DAT_171562c4430 + 1;
                    dVar22 = DAT_171562bd610 * DAT_171562c3dd8 + DAT_171562bd670;
                    if (((DAT_171562c3ab0 + dVar22 < DAT_171562c4798) &&
                        (DAT_171562c4798 < dVar21 - DAT_171562c44a8)) &&
                       ((((DAT_171562bd600 == 0.0 && (!NAN(DAT_171562bd600))) ||
                         (local_110 + DAT_171562c3dd8 * DAT_171562c4428 < DAT_171562c4798)) &&
                        (DAT_171562bd608 <= DAT_171562c4430)))) {
                      DAT_171562c4430 = 0;
                      goto LAB_17156286fb9;
                    }
                  }
                  unaff_R12B = '\0';
                }
                if (DAT_171562c4798 <= DAT_171562bd670) goto LAB_171562872e3;
              }
              else {
LAB_17156286fb9:
                unaff_R12B = '\x01';
                DAT_171562bd670 = dVar22;
                if (DAT_171562c4798 <= dVar22) goto LAB_171562872e3;
              }
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              if ((longlong)dVar17 != -0x8000000000000000) {
                dVar20 = (double)(longlong)dVar17;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar17 = (double)(longlong)
                                 ((dVar17 - dVar20) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
              }
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar20 = DAT_171562bd670;
              if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                dVar20 = (double)(longlong)DAT_171562bd670;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar20 = (double)(longlong)
                                 ((DAT_171562bd670 - dVar20) *
                                  *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)
                                  (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
              }
              if ((dVar17 != dVar20) || (NAN(dVar17) || NAN(dVar20))) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562bd670;
                if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                  dVar20 = (double)(longlong)DAT_171562bd670;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((DAT_171562bd670 - dVar20) *
                                    *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)
                                    (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
                }
                if (DAT_171562c3450 == '\x01') {
                  lVar12 = -12000;
                  do {
                    if ((*(double *)((longlong)&DAT_171562c0560 + lVar12) == dVar6) &&
                       (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar12)) && !NAN(dVar6))) {
                      *(double *)((longlong)&DAT_171562c0568 + lVar12) = dVar20;
                      break;
                    }
                    lVar12 = lVar12 + 0x18;
                  } while (lVar12 != 0);
                }
              }
              if (0.0 < DAT_171562c24a0) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                if ((longlong)dVar18 != -0x8000000000000000) {
                  dVar20 = (double)(longlong)dVar18;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar18 = (double)(longlong)
                                   ((dVar18 - dVar20) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar18) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
                }
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562c24a0;
                if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
                  dVar20 = (double)(longlong)DAT_171562c24a0;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((DAT_171562c24a0 - dVar20) *
                                    *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)
                                    (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562c24a0) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
                }
                if ((dVar18 != dVar20) || (NAN(dVar18) || NAN(dVar20))) {
                  uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                  dVar20 = DAT_171562c24a0;
                  if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
                    dVar20 = (double)(longlong)DAT_171562c24a0;
                    uVar16 = uVar11 & 0xffffffff;
                    if (10 < (uint)uVar11) {
                      uVar16 = 0xb;
                    }
                    dVar20 = (double)(longlong)
                                     ((DAT_171562c24a0 - dVar20) *
                                      *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                     *(double *)
                                      (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562c24a0) * 8)) /
                             *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar20;
                  }
                  if (DAT_171562c3450 == '\x01') {
                    lVar12 = -8000;
                    do {
                      if ((*(double *)((longlong)&DAT_171562c24a0 + lVar12) == dVar6) &&
                         (!NAN(*(double *)((longlong)&DAT_171562c24a0 + lVar12)) && !NAN(dVar6))) {
                        *(double *)(&DAT_171562c24a8 + lVar12) = dVar20;
                        break;
                      }
                      lVar12 = lVar12 + 0x10;
                    } while (lVar12 != 0);
                  }
                }
              }
            }
            else {
              dVar18 = (double)FUN_17156297f10(1,dVar22,DAT_171562bd588,local_148);
              DAT_171562bd670 = dVar18;
              if (DAT_171562c4798 < dVar18) {
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                runtime_cast_to_string
                          ((void *)0x171514ca538,(ulonglong)DAT_171562bd670,0x58,&local_158);
                FUN_171562505c0(&local_120,&string_ref_171562adf08,0,&PTR_DAT_171562b9010);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') {
                  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x2916e9000001f9);
LAB_171562873cd:
                  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x2917bf000001f9);
                }
                else {
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x171514ca538,(ulonglong)DAT_171562c4798,0x58,&local_158);
                  FUN_171562505c0(&local_120,&string_ref_171562adf48,0,&PTR_DAT_171562b9020);
                  cVar8 = FUN_171562504a0(&local_120,local_154);
                  if (cVar8 != '\0') {
LAB_171562872a6:
                    pcVar15 = runtime_cast_to_string;
                    MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                    goto LAB_171562872e3;
                  }
                  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x2716ea000001f9);
LAB_17156287189:
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x171514ca538,(ulonglong)DAT_171562bd670,0x58,&local_158);
                  FUN_171562505c0(&local_120,&string_ref_171562adf08,0,&PTR_DAT_171562b9150);
                  cVar8 = FUN_171562504a0(&local_120,local_154);
                  if (cVar8 == '\0') goto LAB_171562873cd;
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  runtime_cast_to_string
                            ((void *)0x171514ca538,(ulonglong)DAT_171562c4798,0x58,&local_158);
                  FUN_171562505c0(&local_120,&string_ref_171562adf48,0,&PTR_DAT_171562b9160);
                  cVar8 = FUN_171562504a0(&local_120,local_154);
                  if (cVar8 != '\0') goto LAB_171562872a6;
                }
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x2717c0000001f9);
LAB_1715628740d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f16fe000001f9);
LAB_1715628742d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6016fe000001f9);
LAB_1715628744d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f173b000001f9);
LAB_1715628746d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x60173b000001f9);
LAB_1715628748d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f171b000001f9);
LAB_171562874ad:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x60171b000001f9);
LAB_171562874cd:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x42175d000001f9);
LAB_171562874ed:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x63175d000001f9);
LAB_1715628750d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x49179c000001f9);
LAB_1715628752d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6a179c000001f9);
LAB_1715628754d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x351780000001f9);
LAB_1715628756d:
                (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x561780000001f9);
                pcVar15 = (code *)swi(3);
                uVar11 = (*pcVar15)();
                return uVar11;
              }
              if (DAT_171562bd5e8 <= 0.0) goto LAB_17156284131;
              local_140 = 0;
              lVar12 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0);
              dVar17 = DAT_171562c4798;
              if (lVar12 < DAT_171562c449c + local_128) goto LAB_17156284138;
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
              dVar24 = DAT_171562bd5f0 * DAT_171562c3dd8 + DAT_17156426e48 + dVar20;
              if ((longlong)dVar24 != -0x8000000000000000) {
                dVar26 = (double)(longlong)dVar24;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar24 = (double)(longlong)
                                 ((dVar24 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
              }
              if ((dVar24 < dVar17) && (DAT_171562c4798 < dVar21 - DAT_171562c44a8)) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562c4798 - DAT_171562bd5f0 * DAT_171562c3dd8;
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar20;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                if (DAT_171562c4798 - DAT_171562c3ab0 <= dVar20) goto LAB_17156284131;
                uVar11 = local_148;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                local_140 = CONCAT71((int7)(uVar11 >> 8),1);
                if (iVar9 != 0) goto LAB_17156284138;
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b9030);
                FUN_171562505c0(&local_120,&string_ref_171562adf98,0,&PTR_DAT_171562b9040);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') goto LAB_1715628740d;
                FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b9050);
                cVar8 = FUN_171562504a0(&local_138,literal_171562adfbc);
                if (cVar8 != '\0') {
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  goto LAB_17156284138;
                }
                goto LAB_1715628742d;
              }
LAB_17156284131:
              local_140 = 0;
LAB_17156284138:
              dVar24 = DAT_171562c4798;
              dVar17 = DAT_171562c47a0;
              if (0.0 < DAT_171562bd598) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar26 = DAT_171562c4798;
                dVar25 = (DAT_171562bd598 + DAT_171562bd5b0) * DAT_171562c3dd8 +
                         DAT_17156426e48 + dVar20;
                if ((longlong)dVar25 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar25;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar25 = (double)(longlong)
                                   ((dVar25 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar25) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                dVar17 = DAT_171562c47a0;
                if (dVar24 <= dVar25) goto joined_r0x0171562845a7;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562bd5a0 * DAT_171562c3dd8 + local_110;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                dVar17 = DAT_171562c47a0;
                if ((dVar26 <= dVar24) || (dVar21 - DAT_171562c44a8 <= DAT_171562c4798))
                goto joined_r0x0171562845a7;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562bd5a8 * DAT_171562c3dd8 + dVar22;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                dVar17 = DAT_171562c47a0;
                if (dVar24 <= dVar20) goto joined_r0x0171562845a7;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562c4798 - DAT_171562bd598 * DAT_171562c3dd8;
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar20;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                dVar17 = DAT_171562c47a0;
                if (DAT_171562c4798 - DAT_171562c3ab0 <= dVar20) goto joined_r0x0171562845a7;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                if (iVar9 != 0) {
                  dVar24 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                  lVar12 = (longlong)dVar24;
                  if (lVar12 != -0x8000000000000000) {
                    dVar17 = (double)lVar12;
                    lVar12 = (longlong)
                             ((dVar24 - dVar17) * DAT_171562a8480 +
                             *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8));
                    dVar24 = (double)lVar12 / DAT_171562a8480 + dVar17;
                  }
                  local_140 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
                  dVar17 = DAT_171562c47a0;
                  if ((dVar24 < dVar19) &&
                     (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                     dVar17 = DAT_171562c47a0, DAT_17156426e48 <= dVar24)) goto LAB_171562872ef;
                  goto joined_r0x0171562845a7;
                }
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b9060);
                FUN_171562505c0(&local_120,&string_ref_171562adf98,0,&PTR_DAT_171562b9070);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') goto LAB_1715628748d;
                FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b9080);
                cVar8 = FUN_171562504a0(&local_138,literal_171562ae06c);
                if (cVar8 != '\0') {
                  lVar12 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  local_140 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
                  dVar17 = DAT_171562c47a0;
                  goto joined_r0x0171562845a7;
                }
                goto LAB_171562874ad;
              }
joined_r0x0171562845a7:
              DAT_171562c47a0 = dVar17;
              if (0.0 < DAT_171562bd378) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar24 = DAT_171562c47a0;
                dVar26 = (dVar21 - DAT_17156426e48) - DAT_171562bd378 * DAT_171562c3dd8;
                if ((longlong)dVar26 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar26;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar26 = (double)(longlong)
                                   ((dVar26 - dVar25) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar26) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar25;
                }
                if (dVar26 <= dVar17) goto LAB_17156284b22;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar17 = local_110 - DAT_171562bd380 * DAT_171562c3dd8;
                if ((longlong)dVar17 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar17;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar17 = (double)(longlong)
                                   ((dVar17 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if ((dVar17 <= dVar24) || (dVar21 - DAT_171562c44a8 <= DAT_171562c4798))
                goto LAB_17156284b22;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar21 = DAT_171562bd378 * DAT_171562c3dd8 + DAT_171562c4798;
                if ((longlong)dVar21 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar21;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar21 = (double)(longlong)
                                   ((dVar21 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar21) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                if (dVar21 <= DAT_171562c47a0 + DAT_171562c3ab0) goto LAB_17156284b22;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                if (iVar9 != 0) {
                  dVar17 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                  lVar12 = (longlong)dVar17;
                  if (lVar12 != -0x8000000000000000) {
                    dVar24 = (double)lVar12;
                    lVar12 = (longlong)
                             ((dVar17 - dVar24) * DAT_171562a8480 +
                             *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8));
                    dVar17 = (double)lVar12 / DAT_171562a8480 + dVar24;
                  }
                  local_140 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
                  if ((dVar17 < dVar19) &&
                     (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                     DAT_17156426e48 <= dVar17)) goto LAB_171562872ef;
                  goto LAB_17156284b22;
                }
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b9090);
                FUN_171562505c0(&local_120,&string_ref_171562adf98,0,&PTR_DAT_171562b90a0);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') goto LAB_1715628744d;
                FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b90b0);
                cVar8 = FUN_171562504a0(&local_138,literal_171562ae0ec);
                if (cVar8 != '\0') {
                  lVar12 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  local_140 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
                  goto LAB_17156284b22;
                }
                goto LAB_1715628746d;
              }
LAB_17156284b22:
              dVar17 = DAT_171562c4798;
              if (((DAT_171562bd4e8 == 1 & (byte)local_12c) == 1) && (0.0 < DAT_171562bd4f8)) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar24 = DAT_171562c4798;
                dVar26 = DAT_171562bd4f8 * DAT_171562c3dd8 + DAT_17156426e48 + dVar20;
                if ((longlong)dVar26 != -0x8000000000000000) {
                  dVar25 = (double)(longlong)dVar26;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar26 = (double)(longlong)
                                   ((dVar26 - dVar25) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar26) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar25;
                }
                if (dVar17 <= dVar26) goto joined_r0x017156284fd3;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar17 = DAT_171562bd4f0 * DAT_171562c3dd8 + dVar23;
                if ((longlong)dVar17 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar17;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar17 = (double)(longlong)
                                   ((dVar17 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if ((dVar24 <= dVar17) || (dVar21 - DAT_171562c44a8 <= DAT_171562c4798))
                goto joined_r0x017156284fd3;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar17 = DAT_171562bd500 * DAT_171562c3dd8 + dVar22;
                if ((longlong)dVar17 != -0x8000000000000000) {
                  dVar24 = (double)(longlong)dVar17;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar17 = (double)(longlong)
                                   ((dVar17 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar24;
                }
                if (dVar17 <= dVar20) goto joined_r0x017156284fd3;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562c4798 - DAT_171562bd4f8 * DAT_171562c3dd8;
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar20;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                if (DAT_171562c4798 - DAT_171562c3ab0 <= dVar20) goto joined_r0x017156284fd3;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                if (iVar9 != 0) {
LAB_17156284f81:
                  lVar12 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  local_140 = CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
                  goto joined_r0x017156284fd3;
                }
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b90c0);
                FUN_171562505c0(&local_120,&string_ref_171562adf98,0,&PTR_DAT_171562b90d0);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') goto LAB_171562874cd;
                FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b90e0);
                cVar8 = FUN_171562504a0(&local_138,literal_171562ae15c);
                if (cVar8 != '\0') goto LAB_17156284f81;
                goto LAB_171562874ed;
              }
joined_r0x017156284fd3:
              if ((0 < DAT_171562bd5d4) && (local_149 != '\0')) {
                dVar17 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8);
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562c3ab0 + dVar20;
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar24 = dVar24 + DAT_17156426e48;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if (((dVar17 <= dVar24) ||
                    (dVar17 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8),
                    DAT_171562c4798 - (double)DAT_171562bd3c0 * DAT_171562c3dd8 <= dVar17)) ||
                   ((dVar22 <= dVar17 && ((DAT_171562bd5c8 & 1) != 0)))) goto LAB_17156285462;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562a8488;
                if (DAT_171562bd5dc == '\0') {
                  dVar24 = 0.0;
                }
                dVar24 = (DAT_171562c4798 - dVar24 * DAT_171562c3dd8) - DAT_171562c3ab0;
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar24 = dVar24 - DAT_17156426e48;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if ((dVar24 <= dVar17) || (dVar21 - DAT_171562c44a8 <= DAT_171562c4798))
                goto LAB_17156285462;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = *(double *)(&DAT_171562c4110 + (ulonglong)DAT_171562c4934 * 8);
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar20;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                if (DAT_171562c4798 - DAT_171562c3ab0 <= dVar20) goto LAB_17156285462;
                uVar11 = local_148;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                local_140 = CONCAT71((int7)(uVar11 >> 8),1);
                if (iVar9 != 0) goto LAB_17156285462;
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b90f0);
                FUN_171562505c0(&local_120,&string_ref_171562ad8a0,0,&PTR_DAT_171562b9100);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 != '\0') {
                  FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b9110);
                  cVar8 = FUN_171562504a0(&local_138,literal_171562ae20c);
                  if (cVar8 == '\0') goto LAB_1715628756d;
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  goto LAB_17156285462;
                }
                goto LAB_1715628754d;
              }
LAB_17156285462:
              dVar17 = DAT_171562c4798;
              if (0.0 < DAT_171562bd5b8) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar24 = DAT_171562bd5b8 * DAT_171562c3dd8 + dVar22;
                if ((longlong)dVar24 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar24;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar24 = (double)(longlong)
                                   ((dVar24 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar24) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if (dVar17 <= dVar24) goto LAB_171562858b1;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar17 = DAT_171562bd5c0 * DAT_171562c3dd8 + dVar22;
                if ((longlong)dVar17 != -0x8000000000000000) {
                  dVar24 = (double)(longlong)dVar17;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar17 = (double)(longlong)
                                   ((dVar17 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar24;
                }
                MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
                dVar24 = DAT_171562c4798;
                if (dVar17 <= DAT_17156426e48 + dVar20) goto LAB_171562858b1;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar17 = DAT_171562bd5c0 * DAT_171562c3dd8 + dVar22 + DAT_171562c3ab0;
                if ((longlong)dVar17 != -0x8000000000000000) {
                  dVar26 = (double)(longlong)dVar17;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar17 = (double)(longlong)
                                   ((dVar17 - dVar26) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar26;
                }
                if ((dVar24 <= dVar17) || (dVar21 - DAT_171562c44a8 <= DAT_171562c4798))
                goto LAB_171562858b1;
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar20 = DAT_171562bd5c0 * DAT_171562c3dd8 + dVar22;
                if ((longlong)dVar20 != -0x8000000000000000) {
                  dVar17 = (double)(longlong)dVar20;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar20 = (double)(longlong)
                                   ((dVar20 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                }
                if (DAT_171562c4798 - DAT_171562c3ab0 <= dVar20) goto LAB_171562858b1;
                iVar9 = FUN_17156282a90(local_148,dVar20);
                unaff_R12B = '\x01';
                if (iVar9 != 0) goto LAB_17156285b30;
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_158,&DAT_17156426e3c,1,&PTR_DAT_171562b9120);
                FUN_171562505c0(&local_120,&string_ref_171562ae290,0,&PTR_DAT_171562b9130);
                cVar8 = FUN_171562504a0(&local_120,local_154);
                if (cVar8 == '\0') goto LAB_1715628750d;
                FUN_171562505c0(&local_138,&local_120,0,&PTR_DAT_171562b9140);
                cVar8 = FUN_171562504a0(&local_138,literal_171562ae2ac);
                if (cVar8 != '\0') {
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                  goto LAB_17156285b30;
                }
                goto LAB_1715628752d;
              }
LAB_171562858b1:
              unaff_R12B = '\x01';
              if ((char)local_140 == '\0') {
                if (((((DAT_171562bd5f8 == '\x01') &&
                      (DAT_171562c4430 = DAT_171562c4430 + 1,
                      DAT_171562bd610 * DAT_171562c3dd8 + dVar20 + DAT_171562c3ab0 < DAT_171562c4798
                      )) && (DAT_171562c4798 < dVar21 - DAT_171562c44a8)) &&
                    (((DAT_171562bd600 == 0.0 && (!NAN(DAT_171562bd600))) ||
                     (DAT_171562c3dd8 * DAT_171562c4428 + local_110 < DAT_171562c4798)))) &&
                   (DAT_171562bd608 <= DAT_171562c4430)) {
                  uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                  dVar17 = DAT_171562bd610 * DAT_171562c3dd8 + dVar20;
                  if ((longlong)dVar17 != -0x8000000000000000) {
                    dVar24 = (double)(longlong)dVar17;
                    uVar16 = uVar11 & 0xffffffff;
                    if (10 < (uint)uVar11) {
                      uVar16 = 0xb;
                    }
                    dVar17 = (double)(longlong)
                                     ((dVar17 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar16 * 8)
                                     + *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar17) * 8)
                                     ) / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar24;
                  }
                  if (dVar20 < dVar17) {
                    DAT_171562c4430 = 0;
                    uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                    dVar20 = dVar20 + DAT_171562bd610 * DAT_171562c3dd8;
                    if ((longlong)dVar20 != -0x8000000000000000) {
                      dVar17 = (double)(longlong)dVar20;
                      uVar16 = uVar11 & 0xffffffff;
                      if (10 < (uint)uVar11) {
                        uVar16 = 0xb;
                      }
                      dVar20 = (double)(longlong)
                                       ((dVar20 - dVar17) *
                                        *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                       *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar20) * 8)
                                       ) / *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
                    }
                    FUN_17156282a90(local_148,dVar20);
                    goto LAB_17156285b30;
                  }
                }
                unaff_R12B = '\0';
              }
LAB_17156285b30:
              DAT_171562bd670 = dVar20;
              if (DAT_171562c4798 < dVar20) goto LAB_17156287189;
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              if ((longlong)dVar18 != -0x8000000000000000) {
                dVar17 = (double)(longlong)dVar18;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar18 = (double)(longlong)
                                 ((dVar18 - dVar17) * *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)(&DAT_171562a8468 + (ulonglong)(0.0 < dVar18) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
              }
              uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar17 = DAT_171562bd670;
              if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                dVar17 = (double)(longlong)DAT_171562bd670;
                uVar16 = uVar11 & 0xffffffff;
                if (10 < (uint)uVar11) {
                  uVar16 = 0xb;
                }
                dVar17 = (double)(longlong)
                                 ((DAT_171562bd670 - dVar17) *
                                  *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                 *(double *)
                                  (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar17;
              }
              if ((dVar18 != dVar17) || (NAN(dVar18) || NAN(dVar17))) {
                uVar11 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar18 = DAT_171562bd670;
                if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
                  dVar18 = (double)(longlong)DAT_171562bd670;
                  uVar16 = uVar11 & 0xffffffff;
                  if (10 < (uint)uVar11) {
                    uVar16 = 0xb;
                  }
                  dVar18 = (double)(longlong)
                                   ((DAT_171562bd670 - dVar18) *
                                    *(double *)(&DAT_171562a9b40 + uVar16 * 8) +
                                   *(double *)
                                    (&DAT_171562a8468 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar16 * 8) + dVar18;
                }
                if (DAT_171562c3450 == '\x01') {
                  lVar12 = -12000;
                  do {
                    if ((*(double *)((longlong)&DAT_171562c0560 + lVar12) == dVar6) &&
                       (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar12)) && !NAN(dVar6))) {
                      *(double *)((longlong)&DAT_171562c0568 + lVar12) = dVar18;
                      break;
                    }
                    lVar12 = lVar12 + 0x18;
                  } while (lVar12 != 0);
                }
              }
              if (DAT_171562bd514 == 2) goto LAB_17156285d65;
            }
            if (unaff_R12B != '\0') {
              pcVar15 = (code *)0x1;
            }
          }
        }
        else {
LAB_171562830a0:
          unaff_R12B = '\0';
        }
LAB_171562830a3:
        FUN_17156250000(&local_108);
        FUN_17156250000(&local_f8);
        iVar9 = local_ec;
      }
      if (unaff_R12B != '\0') {
        pcVar15 = (code *)0x1;
      }
      iVar9 = iVar9 + 1;
      iVar10 = MT5_PositionsTotal((void *)0x171514ca538);
    } while (iVar9 < iVar10);
  }
  FUN_17156250000(&local_158);
  FUN_17156250000(&local_120);
  FUN_17156250000(&local_138);
  return (ulonglong)pcVar15 & 0xffffffff;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:24295
/* Address: 17156287590 */

/* WARNING: Removing unreachable block (ram,0x01715628820e) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

ulonglong FUN_17156287590(void)

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
  int iVar13;
  int iVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  ulonglong uVar18;
  code *pcVar19;
  code *pcVar20;
  undefined8 uVar21;
  char unaff_R12B;
  ulonglong uVar22;
  undefined4 uVar23;
  double dVar24;
  double dVar25;
  undefined4 uVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  undefined4 local_160;
  longlong local_15c;
  char local_151;
  undefined4 local_150;
  longlong local_14c;
  ulonglong local_140;
  undefined4 local_134;
  undefined4 local_130;
  longlong local_12c;
  undefined8 local_120;
  longlong local_118;
  undefined4 local_110;
  undefined8 local_10c;
  double local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  int local_ec;
  
  local_110 = 0;
  local_150 = 0;
  local_160 = 0;
  local_f8 = 0;
  local_130 = 0;
  local_10c = 0;
  local_14c = 0;
  local_15c = 0;
  local_f4 = 0;
  local_12c = 0;
  iVar13 = MT5_PositionsTotal((void *)0x171514ca538);
  if (iVar13 < 1) {
    pcVar20 = (code *)0x0;
LAB_1715628b881:
    FUN_17156250000(&local_160);
    FUN_17156250000(&local_150);
    FUN_17156250000(&local_110);
    return (ulonglong)pcVar20 & 0xffffffff;
  }
  iVar13 = 0;
  pcVar20 = (code *)0x0;
  local_151 = DAT_17156426fa0;
LAB_1715628771e:
  DAT_171562c4838 = MT5_PositionGetTicket((void *)0x171514ca538,iVar13);
  if (DAT_171562c4838 == 0) goto LAB_171562876f7;
  local_ec = iVar13;
  uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
  MT5_PositionGetDouble((void *)0x171514ca538,6);
  dVar27 = DAT_17156426e48;
  if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
    dVar27 = (double)(longlong)DAT_17156426e48;
    uVar22 = uVar15 & 0xffffffff;
    if (10 < (uint)uVar15) {
      uVar22 = 0xb;
    }
    dVar27 = (double)(longlong)
                     ((DAT_17156426e48 - dVar27) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                     *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_17156426e48) * 8)) /
             *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
  }
  uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
  MT5_PositionGetDouble((void *)0x171514ca538,7);
  dVar28 = DAT_17156426e48;
  if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
    dVar28 = (double)(longlong)DAT_17156426e48;
    uVar22 = uVar15 & 0xffffffff;
    if (10 < (uint)uVar15) {
      uVar22 = 0xb;
    }
    dVar28 = (double)(longlong)
                     ((DAT_17156426e48 - dVar28) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                     *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_17156426e48) * 8)) /
             *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar28;
  }
  dVar8 = (double)(longlong)DAT_171562c4838;
  uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
  MT5_PositionGetDouble((void *)0x171514ca538,4);
  dVar29 = DAT_17156426e48;
  if ((longlong)DAT_17156426e48 != -0x8000000000000000) {
    dVar29 = (double)(longlong)DAT_17156426e48;
    uVar22 = uVar15 & 0xffffffff;
    if (10 < (uint)uVar15) {
      uVar22 = 0xb;
    }
    dVar29 = (double)(longlong)
                     ((DAT_17156426e48 - dVar29) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                     *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_17156426e48) * 8)) /
             *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar29;
  }
  local_f8 = 0;
  local_f4 = 0;
  MT5_PositionGetString((void *)0x171514ca538,0xb);
  FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9170);
  FUN_171562505c0(&local_f8,&local_160,0,&PTR_DAT_171562b9180);
  MT5_PositionGetDouble((void *)0x171514ca538,3);
  dVar32 = DAT_17156426e48;
  local_118 = MT5_PositionGetInteger((void *)0x171514ca538,1);
  lVar16 = MT5_PositionGetInteger((void *)0x171514ca538,2);
  lVar17 = MT5_PositionGetInteger((void *)0x171514ca538,0xc);
  local_130 = 0;
  local_12c = 0;
  MT5_PositionGetString((void *)0x171514ca538,0);
  FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9190);
  FUN_171562505c0(&local_130,&local_160,0,&PTR_DAT_171562b91a0);
  bVar11 = MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
  if (bVar11) {
    if ((int)lVar16 != 1) goto LAB_171562876d0;
LAB_17156287acd:
    unaff_R12B = '\0';
    if ((DAT_171562bd564 == (int)lVar17) && (DAT_171562bd520 == 1)) {
      if (local_12c != DAT_171562c495c) {
        unaff_R12B = '\0';
        if ((local_12c == 0) || (DAT_171562c495c == 0)) goto LAB_171562876d3;
        uVar5 = *(uint *)(local_12c + -4);
        uVar6 = *(uint *)(DAT_171562c495c + -4);
        uVar7 = uVar6;
        if (uVar5 < uVar6) {
          uVar7 = uVar5;
        }
        iVar13 = uVar5 - uVar6;
        if (uVar7 != 0) {
          uVar15 = 1;
          do {
            uVar3 = *(ushort *)(local_12c + -2 + uVar15 * 2);
            uVar4 = *(ushort *)(DAT_171562c495c + -2 + uVar15 * 2);
            if (uVar7 <= uVar15) break;
            uVar15 = uVar15 + 1;
          } while (uVar3 == uVar4);
          if (uVar3 != uVar4) {
            iVar13 = (uint)uVar3 - (uint)uVar4;
          }
        }
        if (iVar13 != 0) goto LAB_171562876d0;
      }
      if ((dVar27 == 0.0) && (!NAN(dVar27))) {
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        dVar27 = DAT_171562bd588 * DAT_171562c3dd8 + dVar29;
        if ((longlong)dVar27 != -0x8000000000000000) {
          dVar30 = (double)(longlong)dVar27;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar27 = (double)(longlong)
                           ((dVar27 - dVar30) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                   *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar30;
        }
        FUN_17156282a90((longlong)dVar8,dVar27,dVar28);
      }
      if ((dVar28 == 0.0) && (!NAN(dVar28))) {
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        dVar28 = dVar29 - DAT_171562bd590 * DAT_171562c3dd8;
        if ((longlong)dVar28 != -0x8000000000000000) {
          dVar30 = (double)(longlong)dVar28;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar28 = (double)(longlong)
                           ((dVar28 - dVar30) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar28) * 8)) /
                   *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar30;
        }
        FUN_17156282a90((longlong)dVar8,dVar27,dVar28);
      }
      if (((DAT_171562bd29e == '\x01') &&
          (lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,
                              (uint)DAT_171562bd29c), lVar16 <= local_118)) &&
         (lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,0),
         local_118 < lVar16)) {
        MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1);
        dVar30 = DAT_17156426e48;
        MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1);
        if ((DAT_17156426e48 < dVar30) &&
           (MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,(uint)DAT_171562bd29d,1),
           dVar29 < DAT_17156426e48)) {
          FUN_17156297d20((longlong)dVar8);
          MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
        }
      }
      if (DAT_171562bd2a0 == '\x01') {
        iVar13 = 0;
        if (DAT_171562bd29f != '\0') {
          iVar13 = 0xf;
        }
        lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar13,(uint)DAT_171562bd29c);
        if (lVar16 <= local_118) {
          iVar13 = 0;
          if (DAT_171562bd29f != '\0') {
            iVar13 = 0xf;
          }
          lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar13,0);
          if (local_118 < lVar16) {
            iVar13 = 0;
            if (DAT_171562bd29f != '\0') {
              iVar13 = 0xf;
            }
            MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
            dVar30 = DAT_17156426e48;
            iVar13 = 0;
            if (DAT_171562bd29f != '\0') {
              iVar13 = 0xf;
            }
            MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
            if (DAT_17156426e48 < dVar30) {
              iVar13 = 0;
              if (DAT_171562bd29f != '\0') {
                iVar13 = 0xf;
              }
              MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
              if (dVar29 < DAT_17156426e48) {
                FUN_17156297d20((longlong)dVar8);
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
              }
            }
          }
        }
      }
      if (DAT_171562bd2a2 == '\x01') {
        iVar13 = 0;
        if (DAT_171562bd2a1 != '\0') {
          iVar13 = 0x4001;
        }
        lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar13,(uint)DAT_171562bd29c);
        if (lVar16 <= local_118) {
          iVar13 = 0;
          if (DAT_171562bd2a1 != '\0') {
            iVar13 = 0x4001;
          }
          lVar16 = MT5_iTime((void *)0x171514ca538,&DAT_171562c4958,iVar13,0);
          if (local_118 < lVar16) {
            iVar13 = 0;
            if (DAT_171562bd2a1 != '\0') {
              iVar13 = 0x4001;
            }
            MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
            dVar30 = DAT_17156426e48;
            iVar13 = 0;
            if (DAT_171562bd2a1 != '\0') {
              iVar13 = 0x4001;
            }
            MT5_iOpen((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
            if (DAT_17156426e48 < dVar30) {
              iVar13 = 0;
              if (DAT_171562bd2a1 != '\0') {
                iVar13 = 0x4001;
              }
              MT5_iClose((void *)0x171514ca538,&DAT_171562c4958,iVar13,1);
              if (dVar29 < DAT_17156426e48) {
                FUN_17156297d20((longlong)dVar8);
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
              }
            }
          }
        }
      }
      DAT_171562c4428 = DAT_171562bd600;
      uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
      local_140 = (ulonglong)dVar8;
      dVar8 = (double)(longlong)local_140;
      lVar16 = -0x640;
      do {
        if ((*(double *)(&DAT_171562c3450 + lVar16) == dVar8) &&
           (!NAN(*(double *)(&DAT_171562c3450 + lVar16)) && !NAN(dVar8))) {
          dVar30 = *(double *)((longlong)&DAT_171562c3458 + lVar16);
          lVar16 = (longlong)dVar30;
          if (lVar16 == -0x8000000000000000) goto LAB_17156288296;
          goto LAB_17156288237;
        }
        lVar16 = lVar16 + 0x10;
      } while (lVar16 != 0);
      dVar30 = 0.0;
      lVar16 = 0;
LAB_17156288237:
      uVar22 = uVar15 & 0xffffffff;
      if (10 < (uint)uVar15) {
        uVar22 = 0xb;
      }
      dVar30 = (double)(longlong)
                       ((dVar30 - (double)lVar16) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                       *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar30) * 8)) /
               *(double *)(&DAT_171562a9b40 + uVar22 * 8) + (double)lVar16;
LAB_17156288296:
      if ((dVar30 != 0.0) || (NAN(dVar30))) {
        dVar30 = dVar30 + DAT_171562c3dd8 * DAT_171562a84a0;
      }
      else {
        lVar16 = -0x640;
        do {
          dVar30 = dVar29;
          if ((*(double *)(&DAT_171562c3450 + lVar16) == 0.0) &&
             (!NAN(*(double *)(&DAT_171562c3450 + lVar16)))) {
            *(double *)(&DAT_171562c3450 + lVar16) = dVar8;
            *(double *)((longlong)&DAT_171562c3458 + lVar16) = dVar29;
            break;
          }
          lVar16 = lVar16 + 0x10;
        } while (lVar16 != 0);
      }
      if ((dVar30 <= DAT_171562c3dd8 * 0.0 + 0.0) ||
         (dVar30 - dVar29 <= DAT_171562bd4e0 * DAT_171562c3dd8)) {
        local_134 = 0;
      }
      else {
        local_134 = 0x562bd401;
      }
      local_100 = dVar29;
      if (DAT_171562bd508 != '\0') {
        local_100 = dVar30;
      }
      if (DAT_171562c3dd8 * (DAT_171562bd588 + 0.0) + dVar29 + DAT_171562bd650 < DAT_171562c47a0) {
        MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
        MT5_PositionGetDouble((void *)0x171514ca538,3);
        local_140 = DAT_171562c4838;
        goto LAB_1715628b853;
      }
      if (DAT_171562bd514 == 2) {
        unaff_R12B = '\0';
LAB_17156289ff5:
        dVar24 = (double)FUN_17156297f10(2,dVar29,DAT_171562bd588,local_140);
        DAT_171562bd670 = dVar24;
        dVar25 = (double)FUN_171562982b0(SUB84(dVar28,0));
        DAT_171562c24a0 = dVar25;
        if ((DAT_171562bd670 <= DAT_171562c47a0) || ((0.0 < dVar25 && (DAT_171562c47a0 <= dVar25))))
        goto LAB_1715628b847;
        cVar12 = FUN_171562984c0(local_140);
        if (cVar12 != '\0') {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar31 = DAT_171562bd670;
          if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
            dVar31 = (double)(longlong)DAT_171562bd670;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar31 = (double)(longlong)
                             ((DAT_171562bd670 - dVar31) *
                              *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8))
                     / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
          }
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          if (dVar31 < dVar27 - DAT_17156426e48) {
            uVar22 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            uVar15 = local_140;
            dVar27 = DAT_171562bd670;
            if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
              dVar27 = (double)(longlong)DAT_171562bd670;
              uVar18 = uVar22 & 0xffffffff;
              if (10 < (uint)uVar22) {
                uVar18 = 0xb;
              }
              dVar27 = (double)(longlong)
                               ((DAT_171562bd670 - dVar27) *
                                *(double *)(&DAT_171562a9b40 + uVar18 * 8) +
                               *(double *)
                                (&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar18 * 8) + dVar27;
            }
            FUN_17156282a90(local_140,dVar27,dVar28);
            FUN_17156298560(uVar15);
          }
        }
        if ((0.0 < DAT_171562bd5e8) &&
           (lVar16 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0), dVar31 = DAT_171562c47a0,
           dVar27 = DAT_171562bd670, local_118 + DAT_171562c449c <= lVar16)) {
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          if ((dVar31 < (dVar27 - DAT_17156426e48) - DAT_171562bd5f0 * DAT_171562c3dd8) &&
             (DAT_171562c44a8 + dVar28 < DAT_171562c47a0)) {
            unaff_R12B = '\x01';
            DAT_171562bd670 = DAT_171562bd5f0 * DAT_171562c3dd8 + DAT_171562c47a0;
          }
        }
        dVar31 = DAT_171562c47a0;
        dVar27 = DAT_171562bd670;
        if ((((0.0 < DAT_171562bd598) &&
             (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
             dVar31 < (dVar27 - DAT_17156426e48) -
                      (DAT_171562bd5b0 + DAT_171562bd598) * DAT_171562c3dd8)) &&
            (DAT_171562c47a0 < local_100 - DAT_171562bd5a0 * DAT_171562c3dd8)) &&
           (dVar29 - DAT_171562bd5a8 * DAT_171562c3dd8 < DAT_171562bd670)) {
          DAT_171562bd670 = DAT_171562bd598 * DAT_171562c3dd8 + DAT_171562c47a0;
          dVar27 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
          if ((longlong)dVar27 != -0x8000000000000000) {
            dVar31 = (double)(longlong)dVar27;
            dVar27 = (double)(longlong)
                             ((dVar27 - dVar31) * DAT_171562a84a8 +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                     DAT_171562a84a8 + dVar31;
          }
          unaff_R12B = '\x01';
          if ((dVar27 < dVar32) &&
             (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
             DAT_17156426e48 <= dVar27)) goto LAB_1715628b853;
        }
        dVar27 = DAT_171562c4798;
        if ((0.0 < DAT_171562bd378) && (0.0 < DAT_171562c24a0)) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar31 = DAT_171562c24a0;
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          dVar10 = DAT_171562c4798;
          dVar31 = DAT_171562bd378 * DAT_171562c3dd8 + dVar31 + DAT_17156426e48;
          if ((longlong)dVar31 != -0x8000000000000000) {
            dVar33 = (double)(longlong)dVar31;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar31 = (double)(longlong)
                             ((dVar31 - dVar33) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar31) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar33;
          }
          if (dVar31 < dVar27) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar27 = DAT_171562bd380 * DAT_171562c3dd8 + local_100;
            if ((longlong)dVar27 != -0x8000000000000000) {
              dVar31 = (double)(longlong)dVar27;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar27 = (double)(longlong)
                               ((dVar27 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
            }
            if (dVar27 < dVar10) {
              uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              DAT_171562c24a0 = DAT_171562c4798 - DAT_171562bd378 * DAT_171562c3dd8;
              if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
                dVar27 = (double)(longlong)DAT_171562c24a0;
                uVar22 = uVar15 & 0xffffffff;
                if (10 < (uint)uVar15) {
                  uVar22 = 0xb;
                }
                DAT_171562c24a0 =
                     (double)(longlong)
                             ((DAT_171562c24a0 - dVar27) *
                              *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562c24a0) * 8))
                     / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
              }
              dVar27 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
              if ((longlong)dVar27 != -0x8000000000000000) {
                dVar31 = (double)(longlong)dVar27;
                dVar27 = (double)(longlong)
                                 ((dVar27 - dVar31) * DAT_171562a84a8 +
                                 *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                         DAT_171562a84a8 + dVar31;
              }
              unaff_R12B = '\x01';
              if ((dVar27 < dVar32) &&
                 (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                 DAT_17156426e48 <= dVar27)) goto LAB_1715628b853;
            }
          }
        }
        dVar32 = DAT_171562c47a0;
        dVar27 = DAT_171562bd670;
        if (((((byte)local_134 & DAT_171562bd4e8 == 1) == 1) &&
            (((0.0 < DAT_171562bd4f8 &&
              (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
              dVar32 < (dVar27 - DAT_17156426e48) - DAT_171562bd4f8 * DAT_171562c3dd8)) &&
             (DAT_171562c47a0 < dVar30 - DAT_171562bd4f0 * DAT_171562c3dd8)))) &&
           ((DAT_171562c44a8 + dVar28 < DAT_171562c47a0 &&
            (dVar29 - DAT_171562c3dd8 * DAT_171562bd500 < DAT_171562bd670)))) {
          MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
          unaff_R12B = '\x01';
          DAT_171562bd670 = DAT_171562bd4f8 * DAT_171562c3dd8 + DAT_171562c47a0;
        }
        if (((0 < DAT_171562bd5d4) &&
            (dVar27 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8),
            dVar32 = DAT_171562bd670 - DAT_171562c3ab0,
            MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
            dVar27 < dVar32 - DAT_17156426e48)) &&
           ((dVar27 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8),
            dVar29 < dVar27 || ((DAT_171562bd5c8 & 1) == 0)))) {
          if (DAT_171562bd5dc == '\0') {
            uVar23 = 0;
            uVar26 = 0;
          }
          else {
            uVar23 = SUB84(DAT_171562a84b0,0);
            uVar26 = (undefined4)((ulonglong)DAT_171562a84b0 >> 0x20);
          }
          dVar32 = (double)CONCAT44(uVar26,uVar23) * DAT_171562c3dd8 + DAT_171562c47a0 +
                   DAT_171562c3ab0;
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          if ((dVar32 + DAT_17156426e48 < dVar27) && (DAT_171562c44a8 + dVar28 < DAT_171562c47a0)) {
            unaff_R12B = '\x01';
            DAT_171562bd670 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8);
          }
        }
        dVar27 = DAT_171562bd670;
        if ((((DAT_171562bd5b8 <= 0.0) || (DAT_171562bd514 != 2)) ||
            (dVar29 - DAT_171562bd5b8 * DAT_171562c3dd8 <= DAT_171562c47a0)) ||
           (dVar32 = DAT_171562c3dd8 * DAT_171562bd5c0,
           MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
           dVar27 - DAT_17156426e48 <= dVar29 - dVar32)) {
LAB_1715628ac05:
          if (unaff_R12B == '\0') {
            uVar23 = SUB84(DAT_171562c47a0,0);
            uVar26 = (undefined4)((ulonglong)DAT_171562c47a0 >> 0x20);
            if (DAT_171562bd5f8 == '\x01') {
              DAT_171562c4430 = DAT_171562c4430 + 1;
              dVar29 = DAT_171562bd670 - DAT_171562bd610 * DAT_171562c3dd8;
              if (((DAT_171562c47a0 < dVar29 - DAT_171562c3ab0) &&
                  (dVar28 + DAT_171562c44a8 < DAT_171562c47a0)) &&
                 ((((DAT_171562bd600 == 0.0 && (!NAN(DAT_171562bd600))) ||
                   (DAT_171562c47a0 < local_100 - DAT_171562c3dd8 * DAT_171562c4428)) &&
                  (DAT_171562bd608 <= DAT_171562c4430)))) {
                DAT_171562c4430 = 0;
                goto LAB_1715628b1ac;
              }
            }
            unaff_R12B = '\0';
          }
          if (DAT_171562bd670 <= DAT_171562c47a0) goto LAB_1715628b847;
        }
        else {
          uVar23 = SUB84(DAT_171562c47a0,0);
          uVar26 = (undefined4)((ulonglong)DAT_171562c47a0 >> 0x20);
          dVar29 = dVar29 - DAT_171562bd5c0 * DAT_171562c3dd8;
          if ((dVar29 - DAT_171562c3ab0 <= DAT_171562c47a0) ||
             (DAT_171562c47a0 <= DAT_171562c44a8 + dVar28)) goto LAB_1715628ac05;
LAB_1715628b1ac:
          unaff_R12B = '\x01';
          DAT_171562bd670 = dVar29;
          if (dVar29 <= (double)CONCAT44(uVar26,uVar23)) goto LAB_1715628b847;
        }
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        if ((longlong)dVar24 != -0x8000000000000000) {
          dVar27 = (double)(longlong)dVar24;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar24 = (double)(longlong)
                           ((dVar24 - dVar27) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                   *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
        }
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        dVar27 = DAT_171562bd670;
        if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
          dVar27 = (double)(longlong)DAT_171562bd670;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar27 = (double)(longlong)
                           ((DAT_171562bd670 - dVar27) * *(double *)(&DAT_171562a9b40 + uVar22 * 8)
                           + *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8))
                   / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
        }
        if ((dVar24 != dVar27) || (NAN(dVar24) || NAN(dVar27))) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar27 = DAT_171562bd670;
          if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
            dVar27 = (double)(longlong)DAT_171562bd670;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar27 = (double)(longlong)
                             ((DAT_171562bd670 - dVar27) *
                              *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8))
                     / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
          }
          if (DAT_171562c3450 == '\x01') {
            lVar16 = -12000;
            do {
              if ((*(double *)((longlong)&DAT_171562c0560 + lVar16) == dVar8) &&
                 (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar16)) && !NAN(dVar8))) {
                *(double *)((longlong)&DAT_171562c0568 + lVar16) = dVar27;
                break;
              }
              lVar16 = lVar16 + 0x18;
            } while (lVar16 != 0);
          }
        }
        if (0.0 < DAT_171562c24a0) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          if ((longlong)dVar25 != -0x8000000000000000) {
            dVar27 = (double)(longlong)dVar25;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar25 = (double)(longlong)
                             ((dVar25 - dVar27) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar25) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
          }
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar27 = DAT_171562c24a0;
          if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
            dVar27 = (double)(longlong)DAT_171562c24a0;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar27 = (double)(longlong)
                             ((DAT_171562c24a0 - dVar27) *
                              *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562c24a0) * 8))
                     / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
          }
          if ((dVar25 != dVar27) || (NAN(dVar25) || NAN(dVar27))) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar27 = DAT_171562c24a0;
            if ((longlong)DAT_171562c24a0 != -0x8000000000000000) {
              dVar27 = (double)(longlong)DAT_171562c24a0;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar27 = (double)(longlong)
                               ((DAT_171562c24a0 - dVar27) *
                                *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)
                                (&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562c24a0) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar27;
            }
            if (DAT_171562c3450 == '\x01') {
              lVar16 = -8000;
              do {
                if ((*(double *)((longlong)&DAT_171562c24a0 + lVar16) == dVar8) &&
                   (!NAN(*(double *)((longlong)&DAT_171562c24a0 + lVar16)) && !NAN(dVar8))) {
                  *(double *)(&DAT_171562c24a8 + lVar16) = dVar27;
                  break;
                }
                lVar16 = lVar16 + 0x10;
              } while (lVar16 != 0);
            }
          }
        }
      }
      else {
        dVar25 = (double)FUN_17156297f10(2,dVar29,DAT_171562bd588,local_140);
        DAT_171562bd670 = dVar25;
        if (dVar25 < DAT_171562c47a0) {
          MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
          pcVar20 = runtime_cast_to_string;
          runtime_cast_to_string((void *)0x171514ca538,(ulonglong)DAT_171562bd670,0x58,&local_160);
          FUN_171562505c0(&local_150,&string_ref_171562adf08,0);
          lVar16 = local_15c;
          if (local_15c == 0) goto LAB_1715628b51b;
          uVar5 = *(uint *)(local_15c + -4);
          if ((uVar5 == 0) && (local_14c != 0)) goto LAB_1715628b51b;
          if (local_14c == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(uint *)(local_14c + -4);
          }
          cVar12 = FUN_17156250060(&local_150);
          if (cVar12 == '\0') {
LAB_1715628b94e:
            (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x29198d000001f9);
          }
          else {
            if (uVar5 != 0) {
              lVar17 = local_14c + (ulonglong)uVar6 * 2;
              if (uVar5 < 0x10) {
                uVar15 = 0;
                goto LAB_1715628b4f4;
              }
              if ((ulonglong)(lVar17 - lVar16) < 0x20) {
                uVar15 = 0;
                goto LAB_1715628b4f4;
              }
              uVar22 = 0;
              uVar15 = (ulonglong)(uVar5 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)(lVar16 + uVar22);
                uVar23 = puVar1[1];
                uVar26 = puVar1[2];
                uVar9 = puVar1[3];
                puVar2 = (undefined4 *)(lVar17 + uVar22);
                *puVar2 = *puVar1;
                puVar2[1] = uVar23;
                puVar2[2] = uVar26;
                puVar2[3] = uVar9;
                uVar22 = uVar22 + 0x10;
              } while (((ulonglong)uVar5 * 2 & 0xfffffffffffffff0) != uVar22);
              for (; uVar15 != uVar5; uVar15 = uVar15 + 1) {
LAB_1715628b4f4:
                *(undefined2 *)(lVar17 + uVar15 * 2) = *(undefined2 *)(lVar16 + uVar15 * 2);
              }
            }
            *(uint *)(local_14c + -4) = uVar5 + uVar6;
            *(undefined2 *)(local_14c + (ulonglong)(uVar5 + uVar6) * 2) = 0;
LAB_1715628b51b:
            MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
            runtime_cast_to_string((void *)0x171514ca538,(ulonglong)DAT_171562c47a0,0x58,&local_160)
            ;
            FUN_171562505c0(&local_150,&string_ref_171562ae368,0);
            lVar16 = local_15c;
            if (local_15c == 0) {
LAB_1715628b801:
              MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
LAB_1715628b847:
              MT5_SymbolInfoTick((void *)0x171514ca538,&DAT_171562c4958,&DAT_171562c4790);
LAB_1715628b853:
              FUN_17156297d20(local_140);
              FUN_17156250000(&local_130);
              FUN_17156250000(&local_f8);
              pcVar20 = (code *)CONCAT71((int7)((ulonglong)pcVar20 >> 8),1);
              goto LAB_1715628b881;
            }
            uVar5 = *(uint *)(local_15c + -4);
            pcVar20 = (code *)(ulonglong)uVar5;
            if ((uVar5 == 0) && (local_14c != 0)) goto LAB_1715628b801;
            if (local_14c == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = *(uint *)(local_14c + -4);
            }
            uVar15 = (ulonglong)(uVar5 + uVar6);
            cVar12 = FUN_17156250060(&local_150);
            if (cVar12 != '\0') {
              if (uVar5 != 0) {
                lVar17 = local_14c + (ulonglong)uVar6 * 2;
                if (uVar5 < 0x10) {
                  pcVar19 = (code *)0x0;
                }
                else if ((ulonglong)(lVar17 - lVar16) < 0x20) {
                  pcVar19 = (code *)0x0;
                }
                else {
                  uVar22 = 0;
                  pcVar19 = (code *)(ulonglong)(uVar5 & 0xfffffff8);
                  do {
                    puVar1 = (undefined4 *)(lVar16 + uVar22);
                    uVar23 = puVar1[1];
                    uVar26 = puVar1[2];
                    uVar9 = puVar1[3];
                    puVar2 = (undefined4 *)(lVar17 + uVar22);
                    *puVar2 = *puVar1;
                    puVar2[1] = uVar23;
                    puVar2[2] = uVar26;
                    puVar2[3] = uVar9;
                    uVar22 = uVar22 + 0x10;
                  } while (((longlong)pcVar20 * 2 & 0xfffffffffffffff0U) != uVar22);
                  if (pcVar19 == pcVar20) goto LAB_1715628b7f6;
                }
                do {
                  *(undefined2 *)(lVar17 + (longlong)pcVar19 * 2) =
                       *(undefined2 *)(lVar16 + (longlong)pcVar19 * 2);
                  pcVar19 = pcVar19 + 1;
                } while (pcVar20 != pcVar19);
              }
              goto LAB_1715628b7f6;
            }
          }
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x27198e000001f9);
LAB_1715628b98e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x291a6a000001f9);
LAB_1715628b9ae:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x271a6b000001f9);
LAB_1715628b9ce:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f19a4000001f9);
LAB_1715628b9ee:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6019a4000001f9);
LAB_1715628ba0e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f19c4000001f9);
LAB_1715628ba2e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6019c4000001f9);
LAB_1715628ba4e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x421a09000001f9);
LAB_1715628ba6e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x631a09000001f9);
LAB_1715628ba8e:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x491a47000001f9);
LAB_1715628baae:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6a1a47000001f9);
LAB_1715628bace:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x351a2b000001f9);
LAB_1715628baee:
          (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x561a2b000001f9);
          pcVar20 = (code *)swi(3);
          uVar15 = (*pcVar20)();
          return uVar15;
        }
        uVar21 = 0;
        if ((0.0 < DAT_171562bd5e8) &&
           (lVar16 = MT5_TimeCurrent((void *)0x171514ca538,(void *)0x0), dVar24 = DAT_171562c47a0,
           DAT_171562c449c + local_118 <= lVar16)) {
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          if ((dVar24 < (dVar27 - DAT_17156426e48) - DAT_171562bd5f0 * DAT_171562c3dd8) &&
             (DAT_171562c44a8 + dVar28 < DAT_171562c47a0)) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar24 = DAT_171562bd5f0 * DAT_171562c3dd8 + DAT_171562c47a0;
            if ((longlong)dVar24 != -0x8000000000000000) {
              dVar31 = (double)(longlong)dVar24;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar24 = (double)(longlong)
                               ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
            }
            if (dVar24 < dVar27) {
              uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar27 = DAT_171562bd5f0 * DAT_171562c3dd8 + DAT_171562c47a0;
              if ((longlong)dVar27 != -0x8000000000000000) {
                dVar24 = (double)(longlong)dVar27;
                uVar22 = uVar15 & 0xffffffff;
                if (10 < (uint)uVar15) {
                  uVar22 = 0xb;
                }
                dVar27 = (double)(longlong)
                                 ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                                 *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
              }
              if (DAT_171562c47a0 + DAT_171562c3ab0 < dVar27) {
                iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
                uVar21 = 1;
                if (iVar13 != 0) goto LAB_17156288776;
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b91d0);
                FUN_171562505c0(&local_150,&string_ref_171562adf98,0,&PTR_DAT_171562b91e0);
                cVar12 = FUN_171562504a0(&local_150,local_15c);
                if (cVar12 == '\0') goto LAB_1715628b9ce;
                FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b91f0);
                cVar12 = FUN_171562504a0(&local_110,literal_171562adfbc);
                if (cVar12 == '\0') goto LAB_1715628b9ee;
                MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                uVar21 = CONCAT71((int7)((ulonglong)&local_110 >> 8),1);
                goto LAB_17156288776;
              }
            }
          }
          uVar21 = 0;
        }
LAB_17156288776:
        dVar31 = DAT_171562c47a0;
        dVar24 = DAT_171562c4798;
        local_120 = uVar21;
        if ((((0.0 < DAT_171562bd598) &&
             (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
             dVar24 = DAT_171562c4798,
             dVar31 < (dVar27 - DAT_17156426e48) -
                      (DAT_171562bd598 + DAT_171562bd5b0) * DAT_171562c3dd8)) &&
            (DAT_171562c47a0 < local_100 - DAT_171562bd5a0 * DAT_171562c3dd8)) &&
           ((DAT_171562c44a8 + dVar28 < DAT_171562c47a0 &&
            (dVar29 - DAT_171562c3dd8 * DAT_171562bd5a8 < dVar27)))) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar31 = DAT_171562bd598 * DAT_171562c3dd8 + DAT_171562c47a0;
          if ((longlong)dVar31 != -0x8000000000000000) {
            dVar24 = (double)(longlong)dVar31;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar31 = (double)(longlong)
                             ((dVar31 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar31) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
          }
          dVar24 = DAT_171562c4798;
          if (dVar31 < dVar27) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar27 = DAT_171562bd598 * DAT_171562c3dd8 + DAT_171562c47a0;
            if ((longlong)dVar27 != -0x8000000000000000) {
              dVar24 = (double)(longlong)dVar27;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar27 = (double)(longlong)
                               ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
            }
            dVar24 = DAT_171562c4798;
            if (DAT_171562c47a0 + DAT_171562c3ab0 < dVar27) {
              iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
              if (iVar13 == 0) {
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9200);
                FUN_171562505c0(&local_150,&string_ref_171562adf98,0,&PTR_DAT_171562b9210);
                cVar12 = FUN_171562504a0(&local_150,local_15c);
                if (cVar12 == '\0') goto LAB_1715628ba0e;
                FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b9220);
                cVar12 = FUN_171562504a0(&local_110,literal_171562ae06c);
                if (cVar12 == '\0') goto LAB_1715628ba2e;
                lVar16 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                local_120 = CONCAT71((int7)((ulonglong)lVar16 >> 8),1);
                dVar24 = DAT_171562c4798;
              }
              else {
                dVar31 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                lVar16 = (longlong)dVar31;
                if (lVar16 != -0x8000000000000000) {
                  dVar24 = (double)lVar16;
                  lVar16 = (longlong)
                           ((dVar31 - dVar24) * DAT_171562a84a8 +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar31) * 8));
                  dVar31 = (double)lVar16 / DAT_171562a84a8 + dVar24;
                }
                local_120 = CONCAT71((int7)((ulonglong)lVar16 >> 8),1);
                dVar24 = DAT_171562c4798;
                if ((dVar31 < dVar32) &&
                   (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                   dVar24 = DAT_171562c4798, DAT_17156426e48 <= dVar31)) goto LAB_1715628b853;
              }
            }
          }
        }
        DAT_171562c4798 = dVar24;
        if (0.0 < DAT_171562bd378) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          dVar10 = DAT_171562c4798;
          dVar31 = DAT_171562bd378 * DAT_171562c3dd8 + DAT_17156426e48 + dVar28;
          if ((longlong)dVar31 != -0x8000000000000000) {
            dVar33 = (double)(longlong)dVar31;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar31 = (double)(longlong)
                             ((dVar31 - dVar33) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar31) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar33;
          }
          if (dVar31 < dVar24) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar24 = DAT_171562bd380 * DAT_171562c3dd8 + local_100;
            if ((longlong)dVar24 != -0x8000000000000000) {
              dVar31 = (double)(longlong)dVar24;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar24 = (double)(longlong)
                               ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
            }
            if ((dVar24 < dVar10) && (DAT_171562c44a8 + dVar28 < DAT_171562c4798)) {
              uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar28 = DAT_171562c4798 - DAT_171562bd378 * DAT_171562c3dd8;
              if ((longlong)dVar28 != -0x8000000000000000) {
                dVar24 = (double)(longlong)dVar28;
                uVar22 = uVar15 & 0xffffffff;
                if (10 < (uint)uVar15) {
                  uVar22 = 0xb;
                }
                dVar28 = (double)(longlong)
                                 ((dVar28 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                                 *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar28) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
              }
              if (dVar28 < DAT_171562c4798 - DAT_171562c3ab0) {
                iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
                if (iVar13 == 0) {
                  FUN_1715628ee80(DAT_17156426e10);
                  FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9230);
                  FUN_171562505c0(&local_150,&string_ref_171562adf98,0,&PTR_DAT_171562b9240);
                  cVar12 = FUN_171562504a0(&local_150,local_15c);
                  if (cVar12 == '\0') {
                    (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x3f19e4000001f9);
                  }
                  else {
                    FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b9250);
                    cVar12 = FUN_171562504a0(&local_110,literal_171562ae0ec);
                    if (cVar12 != '\0') {
                      lVar16 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                      local_120 = CONCAT71((int7)((ulonglong)lVar16 >> 8),1);
                      goto LAB_17156289064;
                    }
                  }
                  (*(code *)&runtime_memory_helper_3959a0)(0x171514ca538,0x6019e4000001f9);
                  goto LAB_1715628b94e;
                }
                dVar24 = (double)(&DAT_171562c3ac0)[DAT_171562c4934] * 0.0;
                lVar16 = (longlong)dVar24;
                if (lVar16 != -0x8000000000000000) {
                  dVar31 = (double)lVar16;
                  lVar16 = (longlong)
                           ((dVar24 - dVar31) * DAT_171562a84a8 +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8));
                  dVar24 = (double)lVar16 / DAT_171562a84a8 + dVar31;
                }
                local_120 = CONCAT71((int7)((ulonglong)lVar16 >> 8),1);
                if ((dVar24 < dVar32) &&
                   (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x22),
                   DAT_17156426e48 <= dVar24)) goto LAB_1715628b853;
              }
            }
          }
        }
LAB_17156289064:
        dVar24 = DAT_171562c47a0;
        if ((((DAT_171562bd4e8 == 1 & (byte)local_134) == 1) &&
            (((0.0 < DAT_171562bd4f8 &&
              (MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
              dVar24 < (dVar27 - DAT_17156426e48) - DAT_171562bd4f8 * DAT_171562c3dd8)) &&
             (DAT_171562c47a0 < dVar30 - DAT_171562bd4f0 * DAT_171562c3dd8)))) &&
           ((DAT_171562c44a8 + dVar28 < DAT_171562c47a0 &&
            (dVar29 - DAT_171562c3dd8 * DAT_171562bd500 < dVar27)))) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar24 = DAT_171562bd4f8 * DAT_171562c3dd8 + DAT_171562c47a0;
          if ((longlong)dVar24 != -0x8000000000000000) {
            dVar31 = (double)(longlong)dVar24;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar24 = (double)(longlong)
                             ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
          }
          if (dVar24 < dVar27) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar27 = DAT_171562bd4f8 * DAT_171562c3dd8 + DAT_171562c47a0;
            if ((longlong)dVar27 != -0x8000000000000000) {
              dVar24 = (double)(longlong)dVar27;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar27 = (double)(longlong)
                               ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
            }
            if (DAT_171562c47a0 + DAT_171562c3ab0 < dVar27) {
              iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
              if (iVar13 == 0) {
                FUN_1715628ee80(DAT_17156426e10);
                FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9260);
                FUN_171562505c0(&local_150,&string_ref_171562adf98,0,&PTR_DAT_171562b9270);
                cVar12 = FUN_171562504a0(&local_150,local_15c);
                if (cVar12 == '\0') goto LAB_1715628ba4e;
                FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b9280);
                cVar12 = FUN_171562504a0(&local_110,literal_171562ae15c);
                if (cVar12 == '\0') goto LAB_1715628ba6e;
              }
              lVar16 = MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
              local_120 = CONCAT71((int7)((ulonglong)lVar16 >> 8),1);
            }
          }
        }
        if ((((0 < DAT_171562bd5d4) && (local_151 != '\0')) &&
            ((dVar31 = dVar27 - DAT_171562c3ab0,
             dVar24 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8),
             MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
             dVar24 < dVar31 - DAT_17156426e48 &&
             (dVar24 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8),
             (double)DAT_171562bd3c0 * DAT_171562c3dd8 + DAT_171562c47a0 < dVar24)))) &&
           ((dVar29 < dVar24 || ((DAT_171562bd5c8 & 1) == 0)))) {
          dVar31 = DAT_171562a84b0;
          if (DAT_171562bd5dc == '\0') {
            dVar31 = 0.0;
          }
          dVar31 = DAT_171562c47a0 + DAT_171562c3dd8 * dVar31 + DAT_171562c3ab0;
          MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10);
          if ((dVar31 + DAT_17156426e48 < dVar24) && (DAT_171562c44a8 + dVar28 < DAT_171562c47a0)) {
            uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
            dVar24 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8);
            if ((longlong)dVar24 != -0x8000000000000000) {
              dVar31 = (double)(longlong)dVar24;
              uVar22 = uVar15 & 0xffffffff;
              if (10 < (uint)uVar15) {
                uVar22 = 0xb;
              }
              dVar24 = (double)(longlong)
                               ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                               *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                       *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
            }
            if (dVar24 < dVar27) {
              uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar27 = *(double *)(&DAT_171562c3df0 + (ulonglong)DAT_171562c4934 * 8);
              if ((longlong)dVar27 != -0x8000000000000000) {
                dVar24 = (double)(longlong)dVar27;
                uVar22 = uVar15 & 0xffffffff;
                if (10 < (uint)uVar15) {
                  uVar22 = 0xb;
                }
                dVar27 = (double)(longlong)
                                 ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                                 *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
              }
              if (DAT_171562c47a0 + DAT_171562c3ab0 < dVar27) {
                uVar15 = local_140;
                iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
                local_120 = CONCAT71((int7)(uVar15 >> 8),1);
                if (iVar13 == 0) {
                  FUN_1715628ee80(DAT_17156426e10);
                  FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b9290);
                  FUN_171562505c0(&local_150,&string_ref_171562ad8a0,0,&PTR_DAT_171562b92a0);
                  cVar12 = FUN_171562504a0(&local_150,local_15c);
                  if (cVar12 == '\0') goto LAB_1715628bace;
                  FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b92b0);
                  cVar12 = FUN_171562504a0(&local_110,literal_171562ae20c);
                  if (cVar12 == '\0') goto LAB_1715628baee;
                  MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
                }
              }
            }
          }
        }
        if ((((DAT_171562bd5b8 <= 0.0) ||
             (dVar29 - DAT_171562bd5b8 * DAT_171562c3dd8 <= DAT_171562c47a0)) ||
            (dVar24 = DAT_171562c3dd8 * DAT_171562bd5c0,
            MT5_SymbolInfoDouble((void *)0x171514ca538,&DAT_171562c4958,0x10),
            dVar27 - DAT_17156426e48 <= dVar29 - dVar24)) ||
           (((dVar29 - DAT_171562bd5c0 * DAT_171562c3dd8) - DAT_171562c3ab0 <= DAT_171562c47a0 ||
            (DAT_171562c47a0 <= DAT_171562c44a8 + dVar28)))) {
LAB_17156289b32:
          unaff_R12B = '\x01';
          if ((char)local_120 == '\0') {
            if (((DAT_171562bd5f8 == '\x01') &&
                (DAT_171562c4430 = DAT_171562c4430 + 1,
                DAT_171562c47a0 < (dVar27 - DAT_171562bd610 * DAT_171562c3dd8) - DAT_171562c3ab0))
               && ((DAT_171562c44a8 + dVar28 < DAT_171562c47a0 &&
                   ((((DAT_171562bd600 == 0.0 && (!NAN(DAT_171562bd600))) ||
                     (DAT_171562c47a0 < local_100 - DAT_171562c3dd8 * DAT_171562c4428)) &&
                    (DAT_171562bd608 <= DAT_171562c4430)))))) {
              uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
              dVar24 = dVar27 - DAT_171562bd610 * DAT_171562c3dd8;
              if ((longlong)dVar24 != -0x8000000000000000) {
                dVar31 = (double)(longlong)dVar24;
                uVar22 = uVar15 & 0xffffffff;
                if (10 < (uint)uVar15) {
                  uVar22 = 0xb;
                }
                dVar24 = (double)(longlong)
                                 ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                                 *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                         *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
              }
              if (dVar24 < dVar27) {
                DAT_171562c4430 = 0;
                uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
                dVar27 = dVar27 - DAT_171562bd610 * DAT_171562c3dd8;
                if ((longlong)dVar27 != -0x8000000000000000) {
                  dVar24 = (double)(longlong)dVar27;
                  uVar22 = uVar15 & 0xffffffff;
                  if (10 < (uint)uVar15) {
                    uVar22 = 0xb;
                  }
                  dVar27 = (double)(longlong)
                                   ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                                   *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                           *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
                }
                FUN_17156282a90(local_140,dVar27,dVar28);
                goto LAB_17156289dc0;
              }
            }
            unaff_R12B = '\0';
          }
        }
        else {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar24 = dVar29 - DAT_171562bd5c0 * DAT_171562c3dd8;
          if ((longlong)dVar24 != -0x8000000000000000) {
            dVar31 = (double)(longlong)dVar24;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar24 = (double)(longlong)
                             ((dVar24 - dVar31) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar24) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar31;
          }
          if (dVar27 <= dVar24) goto LAB_17156289b32;
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar27 = dVar29 - DAT_171562bd5c0 * DAT_171562c3dd8;
          if ((longlong)dVar27 != -0x8000000000000000) {
            dVar24 = (double)(longlong)dVar27;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar27 = (double)(longlong)
                             ((dVar27 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar27) * 8)) /
                     *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
          }
          if (dVar27 <= DAT_171562c47a0 + DAT_171562c3ab0) goto LAB_17156289b32;
          iVar13 = FUN_17156282a90(local_140,dVar27,dVar28);
          unaff_R12B = '\x01';
          if (iVar13 == 0) {
            FUN_1715628ee80(DAT_17156426e10);
            FUN_171562505c0(&local_160,&DAT_17156426e3c,1,&PTR_DAT_171562b92c0);
            FUN_171562505c0(&local_150,&string_ref_171562ae290,0,&PTR_DAT_171562b92d0);
            cVar12 = FUN_171562504a0(&local_150,local_15c);
            if (cVar12 == '\0') goto LAB_1715628ba8e;
            FUN_171562505c0(&local_110,&local_150,0,&PTR_DAT_171562b92e0);
            cVar12 = FUN_171562504a0(&local_110,literal_171562ae2ac);
            if (cVar12 == '\0') goto LAB_1715628baae;
            MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
          }
        }
LAB_17156289dc0:
        DAT_171562bd670 = dVar27;
        if (dVar27 < DAT_171562c47a0) {
          MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
          pcVar20 = runtime_cast_to_string;
          runtime_cast_to_string((void *)0x171514ca538,(ulonglong)DAT_171562bd670,0x58,&local_160);
          FUN_171562505c0(&local_150,&string_ref_171562adf08,0);
          lVar16 = local_15c;
          if (local_15c == 0) goto LAB_1715628b6b8;
          uVar5 = *(uint *)(local_15c + -4);
          if ((uVar5 == 0) && (local_14c != 0)) goto LAB_1715628b6b8;
          if (local_14c == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(uint *)(local_14c + -4);
          }
          cVar12 = FUN_17156250060(&local_150);
          if (cVar12 != '\0') {
            if (uVar5 != 0) {
              lVar17 = local_14c + (ulonglong)uVar6 * 2;
              if (uVar5 < 0x10) {
                uVar15 = 0;
                goto LAB_1715628b691;
              }
              if ((ulonglong)(lVar17 - lVar16) < 0x20) {
                uVar15 = 0;
                goto LAB_1715628b691;
              }
              uVar22 = 0;
              uVar15 = (ulonglong)(uVar5 & 0xfffffff8);
              do {
                puVar1 = (undefined4 *)(lVar16 + uVar22);
                uVar23 = puVar1[1];
                uVar26 = puVar1[2];
                uVar9 = puVar1[3];
                puVar2 = (undefined4 *)(lVar17 + uVar22);
                *puVar2 = *puVar1;
                puVar2[1] = uVar23;
                puVar2[2] = uVar26;
                puVar2[3] = uVar9;
                uVar22 = uVar22 + 0x10;
              } while (((ulonglong)uVar5 * 2 & 0xfffffffffffffff0) != uVar22);
              for (; uVar15 != uVar5; uVar15 = uVar15 + 1) {
LAB_1715628b691:
                *(undefined2 *)(lVar17 + uVar15 * 2) = *(undefined2 *)(lVar16 + uVar15 * 2);
              }
            }
            *(uint *)(local_14c + -4) = uVar5 + uVar6;
            *(undefined2 *)(local_14c + (ulonglong)(uVar5 + uVar6) * 2) = 0;
LAB_1715628b6b8:
            MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
            runtime_cast_to_string((void *)0x171514ca538,(ulonglong)DAT_171562c47a0,0x58,&local_160)
            ;
            FUN_171562505c0(&local_150,&string_ref_171562ae368,0);
            lVar16 = local_15c;
            if (local_15c != 0) {
              uVar5 = *(uint *)(local_15c + -4);
              pcVar20 = (code *)(ulonglong)uVar5;
              if ((uVar5 != 0) || (local_14c == 0)) {
                if (local_14c == 0) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = *(uint *)(local_14c + -4);
                }
                uVar15 = (ulonglong)(uVar5 + uVar6);
                cVar12 = FUN_17156250060(&local_150);
                if (cVar12 == '\0') goto LAB_1715628b9ae;
                if (uVar5 != 0) {
                  lVar17 = local_14c + (ulonglong)uVar6 * 2;
                  if (uVar5 < 0x10) {
                    pcVar19 = (code *)0x0;
                  }
                  else if ((ulonglong)(lVar17 - lVar16) < 0x20) {
                    pcVar19 = (code *)0x0;
                  }
                  else {
                    uVar22 = 0;
                    pcVar19 = (code *)(ulonglong)(uVar5 & 0xfffffff8);
                    do {
                      puVar1 = (undefined4 *)(lVar16 + uVar22);
                      uVar23 = puVar1[1];
                      uVar26 = puVar1[2];
                      uVar9 = puVar1[3];
                      puVar2 = (undefined4 *)(lVar17 + uVar22);
                      *puVar2 = *puVar1;
                      puVar2[1] = uVar23;
                      puVar2[2] = uVar26;
                      puVar2[3] = uVar9;
                      uVar22 = uVar22 + 0x10;
                    } while (((longlong)pcVar20 * 2 & 0xfffffffffffffff0U) != uVar22);
                    if (pcVar19 == pcVar20) goto LAB_1715628b7f6;
                  }
                  do {
                    *(undefined2 *)(lVar17 + (longlong)pcVar19 * 2) =
                         *(undefined2 *)(lVar16 + (longlong)pcVar19 * 2);
                    pcVar19 = pcVar19 + 1;
                  } while (pcVar20 != pcVar19);
                }
LAB_1715628b7f6:
                *(int *)(local_14c + -4) = (int)uVar15;
                *(undefined2 *)(local_14c + uVar15 * 2) = 0;
              }
            }
            goto LAB_1715628b801;
          }
          goto LAB_1715628b98e;
        }
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        if ((longlong)dVar25 != -0x8000000000000000) {
          dVar24 = (double)(longlong)dVar25;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar25 = (double)(longlong)
                           ((dVar25 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                           *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < dVar25) * 8)) /
                   *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
        }
        uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
        dVar24 = DAT_171562bd670;
        if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
          dVar24 = (double)(longlong)DAT_171562bd670;
          uVar22 = uVar15 & 0xffffffff;
          if (10 < (uint)uVar15) {
            uVar22 = 0xb;
          }
          dVar24 = (double)(longlong)
                           ((DAT_171562bd670 - dVar24) * *(double *)(&DAT_171562a9b40 + uVar22 * 8)
                           + *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8))
                   / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar24;
        }
        if ((dVar25 != dVar24) || (NAN(dVar25) || NAN(dVar24))) {
          uVar15 = MT5_SymbolInfoInteger((void *)0x171514ca538,&DAT_171562c4958,0x11);
          dVar25 = DAT_171562bd670;
          if ((longlong)DAT_171562bd670 != -0x8000000000000000) {
            dVar25 = (double)(longlong)DAT_171562bd670;
            uVar22 = uVar15 & 0xffffffff;
            if (10 < (uint)uVar15) {
              uVar22 = 0xb;
            }
            dVar25 = (double)(longlong)
                             ((DAT_171562bd670 - dVar25) *
                              *(double *)(&DAT_171562a9b40 + uVar22 * 8) +
                             *(double *)(&DAT_171562a8490 + (ulonglong)(0.0 < DAT_171562bd670) * 8))
                     / *(double *)(&DAT_171562a9b40 + uVar22 * 8) + dVar25;
          }
          if (DAT_171562c3450 == '\x01') {
            lVar16 = -12000;
            do {
              if ((*(double *)((longlong)&DAT_171562c0560 + lVar16) == dVar8) &&
                 (!NAN(*(double *)((longlong)&DAT_171562c0560 + lVar16)) && !NAN(dVar8))) {
                *(double *)((longlong)&DAT_171562c0568 + lVar16) = dVar25;
                break;
              }
              lVar16 = lVar16 + 0x18;
            } while (lVar16 != 0);
          }
        }
        if (DAT_171562bd514 == 2) goto LAB_17156289ff5;
      }
      if (unaff_R12B != '\0') {
        pcVar20 = (code *)0x1;
      }
    }
  }
  else {
    MT5_Dispatch((void *)0x171514ca538,2,1,0x590008);
    if ((int)lVar16 == 1) goto LAB_17156287acd;
LAB_171562876d0:
    unaff_R12B = '\0';
  }
LAB_171562876d3:
  FUN_17156250000(&local_130);
  FUN_17156250000(&local_f8);
  iVar13 = local_ec;
LAB_171562876f7:
  if (unaff_R12B != '\0') {
    pcVar20 = (code *)0x1;
  }
  iVar13 = iVar13 + 1;
  iVar14 = MT5_PositionsTotal((void *)0x171514ca538);
  if (iVar14 <= iVar13) goto LAB_1715628b881;
  goto LAB_1715628771e;
}



