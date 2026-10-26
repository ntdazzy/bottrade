/* Read-only single-function retry. Address: 253f2620c30; unverified C-like output. */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 FUN_253f2620c30(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  byte bVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 in_R9;
  undefined **ppuVar19;
  double dVar20;
  double dVar21;
  ulonglong uVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  undefined4 local_b8;
  longlong local_b4;
  undefined4 local_a8;
  longlong local_a4;
  undefined4 local_98;
  longlong local_94;
  undefined4 local_88;
  longlong local_84;
  undefined4 local_78;
  longlong local_74;
  undefined4 local_68;
  longlong local_64;
  
  local_68 = 0;
  local_b8 = 0;
  local_98 = 0;
  local_64 = 0;
  local_b4 = 0;
  local_94 = 0;
  DAT_253f26853b0 = 0;
  MT5_AccountInfoInteger((void *)0x253ee076f88,0x20);
  cVar7 = FUN_253f26258d0();
  if (cVar7 == '\0') {
    uVar15 = 1;
    MT5_Dispatch((void *)0x253ee076f88,3,1,0x590008);
    goto LAB_253f2625670;
  }
  DAT_253f26853b0 = 1;
  iVar9 = MT5_MQLInfoInteger((void *)0x253ee076f88,6);
  if (iVar9 == 1) {
    if (DAT_253f2688558 == 2) {
      DAT_253f267e1c8 = 1;
    }
    else {
      if (DAT_253f2688558 != 3) goto LAB_253f2620d60;
      DAT_253f267e1c8 = 0;
    }
    DAT_253f267e1b1 = 1;
  }
LAB_253f2620d60:
  DAT_253f26882b8 = 0;
  if (DAT_253f2688630 == '\0') {
LAB_253f2620f2c:
    if (DAT_253f2688688 != '\0') {
      DAT_253f2688278 = FUN_253f2626650();
      runtime_cast_to_string((void *)0x253ee076f88,DAT_253f2688278,0x54,&local_98);
      FUN_253f26205c0(&local_b8,&string_ref_253f266f2a8,0);
      lVar10 = local_94;
      if (local_94 == 0) {
LAB_253f26210aa:
        in_R9 = 0x590008;
        MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
        goto LAB_253f26210cc;
      }
      uVar3 = *(uint *)(local_94 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_b4 != 0)) goto LAB_253f26210aa;
      if (local_b4 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_b4 + -4);
        uVar18 = uVar3 + *(uint *)(local_b4 + -4);
      }
      cVar7 = FUN_253f2620060(&local_b8);
      if (cVar7 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_b4 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2621092;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2621092:
        *(uint *)(local_b4 + -4) = uVar18;
        *(undefined2 *)(local_b4 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f26210aa;
      }
      goto LAB_253f2625809;
    }
LAB_253f26210cc:
    if (DAT_253f26886c0 != '\0') {
      DAT_253f2688280 = FUN_253f2626ae0();
      runtime_cast_to_string((void *)0x253ee076f88,DAT_253f2688280,0x54,&local_98);
      FUN_253f26205c0(&local_b8,&string_ref_253f266f2e8,0);
      lVar10 = local_94;
      if (local_94 == 0) {
LAB_253f262124a:
        in_R9 = 0x590008;
        MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
        goto LAB_253f262126c;
      }
      uVar3 = *(uint *)(local_94 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_b4 != 0)) goto LAB_253f262124a;
      if (local_b4 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_b4 + -4);
        uVar18 = uVar3 + *(uint *)(local_b4 + -4);
      }
      cVar7 = FUN_253f2620060(&local_b8);
      if (cVar7 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_b4 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2621232;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2621232:
        *(uint *)(local_b4 + -4) = uVar18;
        *(undefined2 *)(local_b4 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f262124a;
      }
      goto LAB_253f2625829;
    }
LAB_253f262126c:
    FUN_253f2627360();
    MT5_AccountInfoDouble((void *)0x253ee076f88,0x25);
    DAT_253f2688260 = DAT_253f2688448;
    if (DAT_253f2688780 != '\0') {
      MT5_AccountInfoDouble((void *)0x253ee076f88,0x28);
    }
    DAT_253f2688260 = DAT_253f2688448;
    lVar10 = MT5_AccountInfoInteger((void *)0x253ee076f88,0);
    MT5_IntegerToString((void *)0x253ee076f88,lVar10,0,
                        (int)CONCAT62((int6)((ulonglong)in_R9 >> 0x10),0x20));
    FUN_253f26205c0(&local_98,&DAT_253f268843c,1,&PTR_DAT_253f2678fe8);
    uVar11 = MT5_StringToInteger((void *)0x253ee076f88,&local_98);
    runtime_cast_to_string((void *)0x253ee076f88,uVar11,0x55,&local_b8);
    FUN_253f26205c0(&local_68,&string_ref_253f266f330);
    lVar10 = local_b4;
    if (local_b4 != 0) {
      uVar3 = *(uint *)(local_b4 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_64 != 0)) goto LAB_253f2621487;
      if (local_64 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_64 + -4);
        uVar18 = uVar3 + *(uint *)(local_64 + -4);
      }
      cVar7 = FUN_253f2620060(&local_68);
      if (cVar7 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_64 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2621472;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2621472:
        *(uint *)(local_64 + -4) = uVar18;
        *(undefined2 *)(local_64 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f2621487;
      }
LAB_253f2625769:
      (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x2a045e000001f9);
LAB_253f2625789:
      (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x28046c000001f9);
LAB_253f26257a9:
      (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x5c06a9000001f9);
LAB_253f26257c9:
      (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x5c06af000001f9);
      goto LAB_253f26257e9;
    }
LAB_253f2621487:
    ppuVar19 = &PTR_DAT_253f2679008;
    FUN_253f26205c0(&DAT_253f26882c8,&local_68,0,&PTR_DAT_253f2679008);
    cVar7 = DAT_253f2688768;
    if (DAT_253f2688768 != '\0') {
      (*(code *)0x7ff7a071dc90)(0x253ee076f88,&DAT_253f26882c8,0);
      (*(code *)0x7ff7a07117c0)(0x253ee076f88,5000);
    }
    (*(code *)0x7ff7a071dbe0)(0x253ee076f88,&DAT_253f26882c8);
    dVar25 = DAT_253f2688448;
    dVar20 = DAT_253f2688260;
    if (DAT_253f2688260 < DAT_253f2688448) {
      runtime_cast_to_string((void *)0x253ee076f88,(ulonglong)DAT_253f2688448,0x58,&local_98);
      FUN_253f26205c0(&local_b8,&string_ref_253f266f388,0);
      lVar10 = local_94;
      if (local_94 == 0) {
LAB_253f2621689:
        ppuVar19 = (undefined **)0x590008;
        MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
        dVar20 = dVar25;
        goto LAB_253f26216b9;
      }
      uVar3 = *(uint *)(local_94 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_b4 != 0)) goto LAB_253f2621689;
      if (local_b4 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_b4 + -4);
        uVar18 = uVar3 + *(uint *)(local_b4 + -4);
      }
      cVar8 = FUN_253f2620060(&local_b8);
      if (cVar8 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_b4 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2621672;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2621672:
        *(uint *)(local_b4 + -4) = uVar18;
        *(undefined2 *)(local_b4 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f2621689;
      }
      goto LAB_253f2625849;
    }
LAB_253f26216b9:
    DAT_253f2688268 = dVar20;
    (*(code *)0x7ff7a071dc90)(0x253ee076f88);
    lVar10 = MT5_AccountInfoInteger((void *)0x253ee076f88,0);
    MT5_IntegerToString((void *)0x253ee076f88,lVar10,0,
                        (int)CONCAT62((int6)((ulonglong)ppuVar19 >> 0x10),0x20));
    FUN_253f26205c0(&local_98,&DAT_253f268843c,1,&PTR_DAT_253f2679028);
    FUN_253f26205c0(&local_b8,&string_ref_253f266f3c8,0);
    lVar10 = local_94;
    if (local_94 != 0) {
      uVar3 = *(uint *)(local_94 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_b4 != 0)) goto LAB_253f2621859;
      if (local_b4 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_b4 + -4);
        uVar18 = uVar3 + *(uint *)(local_b4 + -4);
      }
      cVar8 = FUN_253f2620060(&local_b8);
      if (cVar8 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_b4 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2621842;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2621842:
        *(uint *)(local_b4 + -4) = uVar18;
        *(undefined2 *)(local_b4 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f2621859;
      }
      goto LAB_253f2625789;
    }
LAB_253f2621859:
    FUN_253f26205c0(&DAT_253f26882d8,&local_b8,0,&PTR_DAT_253f2679048);
    cVar8 = (*(code *)0x7ff7a071dda0)(0x253ee076f88);
    if ((cVar7 == '\0') && (cVar8 != '\0')) {
      (*(code *)0x7ff7a071dbe0)(0x253ee076f88,&DAT_253f26882d8);
      DAT_253f26882e8 = (longlong)DAT_253f2688448;
    }
    else {
      DAT_253f26882e8 = MT5_TimeCurrent((void *)0x253ee076f88,(void *)0x0);
    }
    (*(code *)0x7ff7a071dc90)(0x253ee076f88,&DAT_253f26882d8);
    if (0.0 < DAT_253f2688730) {
      DAT_253f2688260 = DAT_253f2688730;
    }
    DAT_253f2687ea1 = 0;
    DAT_253f2686270 = 0x6b12b248;
    DAT_253f2687ea0 = 0;
    DAT_253f2686278 = 0x6aedc848;
    DAT_253f2686280 = 0x6abfa3c8;
    DAT_253f2686288 = 0x6a9ab9c8;
    DAT_253f2686290 = 0x6a75cfc8;
    DAT_253f2686298 = 0x6a4659c8;
    DAT_253f26862a0 = 0x6a22c148;
    DAT_253f26862a8 = 0x69fdd748;
    DAT_253f26862b0 = 0x69cfb2c8;
    DAT_253f26862b8 = 0x69aac8c8;
    DAT_253f26862c0 = 0x6985dec8;
    DAT_253f26862c8 = 0x6960f4c8;
    DAT_253f26862d0 = 0x694150c8;
    DAT_253f26862d8 = 0x690de648;
    DAT_253f26862e0 = 0x68dfc1c8;
    DAT_253f26862e8 = 0x68bad7c8;
    DAT_253f26862f0 = 0x688cb348;
    DAT_253f26862f8 = 0x686677c8;
    DAT_253f2686300 = 0x6842df48;
    DAT_253f2686308 = 0x6814bac8;
    DAT_253f2686310 = 0x67efd0c8;
    DAT_253f2686318 = 0x67cae6c8;
    DAT_253f2686320 = 0x67a5fcc8;
    DAT_253f2686328 = 0x678112c8;
    DAT_253f2686330 = 0x6752ee48;
    DAT_253f2686338 = 0x6724c9c8;
    DAT_253f2686340 = 0x66ffdfc8;
    DAT_253f2686348 = 0x66daf5c8;
    DAT_253f2686350 = 0x66acd148;
    DAT_253f2686358 = 0x6687e748;
    DAT_253f2686360 = 0x6662fd48;
    DAT_253f2686368 = 0x6634d8c8;
    DAT_253f2686370 = 0x660feec8;
    DAT_253f2686378 = 0x65eb04c8;
    DAT_253f2686380 = 0x65bce048;
    DAT_253f2686388 = 0x6597f648;
    DAT_253f2686390 = 0x65730c48;
    DAT_253f2686398 = 0x6544e7c8;
    DAT_253f26863a0 = 0x651ffdc8;
    DAT_253f26863a8 = 0x64f1d948;
    DAT_253f26863b0 = 0x64ccef48;
    DAT_253f26863b8 = 0x64a80548;
    DAT_253f26863c0 = 0x6479e0c8;
    DAT_253f26863c8 = 0x6454f6c8;
    DAT_253f26863d0 = 0x64300cc8;
    DAT_253f26863d8 = 0x640b22c8;
    DAT_253f26863e0 = 0x63dcfe48;
    DAT_253f26863e8 = 0x63b81448;
    DAT_253f26863f0 = 0x6389efc8;
    DAT_253f26863f8 = 0x636505c8;
    DAT_253f2686400 = 0x63401bc8;
    DAT_253f2686408 = 0x6311f748;
    DAT_253f2686410 = 0x62ed0d48;
    DAT_253f2686418 = 0x62c82348;
    DAT_253f2686420 = 0x6299fec8;
    DAT_253f2686428 = 0x627514c8;
    DAT_253f2686430 = 0x6246f048;
    DAT_253f2686438 = 0x62220648;
    DAT_253f2686440 = 0x61fd1c48;
    DAT_253f2686448 = 0x61d83248;
    DAT_253f2686450 = 0x61aa0dc8;
    DAT_253f2686458 = 0x618523c8;
    DAT_253f2686460 = 0x616039c8;
    DAT_253f2686468 = 0x61321548;
    DAT_253f2686470 = 0x610d2b48;
    DAT_253f2686478 = 0x60df06c8;
    DAT_253f2686480 = 0x60ba1cc8;
    DAT_253f2686488 = 0x609532c8;
    DAT_253f2686490 = 0x60670e48;
    DAT_253f2686498 = 0x60422448;
    DAT_253f26864a0 = 0x601d3a48;
    DAT_253f26864a8 = 0x5ff85048;
    DAT_253f26864b0 = 0x5fca2bc8;
    DAT_253f26864b8 = 0x5fa541c8;
    DAT_253f26864c0 = 0x5f771d48;
    DAT_253f26864c8 = 0x5f523348;
    DAT_253f26864d0 = 0x5f2d4948;
    DAT_253f26864d8 = 0x5efdd348;
    DAT_253f26864e0 = 0x5eda3ac8;
    DAT_253f26864e8 = 0x5eb550c8;
    DAT_253f26864f0 = 0x5e872c48;
    DAT_253f26864f8 = 0x5e624248;
    DAT_253f2686500 = 0x5e3d5848;
    DAT_253f2686508 = 0x5e186e48;
    DAT_253f2686510 = 0x5dea49c8;
    DAT_253f2686518 = 0x5dbc2548;
    DAT_253f2686520 = 0x5d973b48;
    DAT_253f2686528 = 0x5d725148;
    DAT_253f2686530 = 0x5d442cc8;
    DAT_253f2686538 = 0x5d1f42c8;
    DAT_253f2686540 = 0x5cfa58c8;
    DAT_253f2686548 = 0x5ccc3448;
    DAT_253f2686550 = 0x5ca74a48;
    DAT_253f2686558 = 0x5c826048;
    DAT_253f2686560 = 0x5c543bc8;
    DAT_253f2686568 = 0x5c2f51c8;
    DAT_253f2686570 = 0x5c0a67c8;
    DAT_253f2686578 = 0x5bdc4348;
    DAT_253f2686580 = 0x5bb75948;
    DAT_253f2686588 = 0x5b926f48;
    DAT_253f2686590 = 0x5b644ac8;
    DAT_253f2686598 = 0x5b3f60c8;
    DAT_253f26865a0 = 0x5b113c48;
    DAT_253f26865a8 = 0x5aec5248;
    DAT_253f26865b0 = 0x5ac76848;
    DAT_253f26865b8 = 0x5aa27e48;
    DAT_253f26865c0 = 0x5a7459c8;
    DAT_253f26865c8 = 0x5a4f6fc8;
    DAT_253f26865d0 = 0x5a2a85c8;
    DAT_253f26865d8 = 0x59fc6148;
    DAT_253f26865e0 = 0x59d77748;
    DAT_253f26865e8 = 0x59a952c8;
    DAT_253f26865f0 = 0x598468c8;
    DAT_253f26865f8 = 0x595f7ec8;
    DAT_253f2686600 = 0x59315a48;
    DAT_253f2686608 = 0x590c7048;
    DAT_253f2686610 = 0x58e78648;
    DAT_253f2686618 = 0x58c29c48;
    DAT_253f2686620 = 0x589477c8;
    DAT_253f2686628 = 0x586f8dc8;
    DAT_253f2686630 = 0x58416948;
    DAT_253f2686638 = 0x581c7f48;
    DAT_253f2686640 = 0x57f79548;
    DAT_253f2686648 = 0x57c970c8;
    DAT_253f2686650 = 0x57a486c8;
    DAT_253f2686658 = 0x577f9cc8;
    DAT_253f2686660 = 0x57517848;
    DAT_253f2686668 = 0x572c8e48;
    DAT_253f2686670 = 0x56fe69c8;
    DAT_253f2686678 = 0x56d97fc8;
    DAT_253f2686680 = 0x56b495c8;
    DAT_253f2686688 = 0x568fabc8;
    DAT_253f2686690 = 0x56618748;
    DAT_253f2686698 = 0x563c9d48;
    DAT_253f26866a0 = 0x560e78c8;
    DAT_253f26866a8 = 0x55e98ec8;
    DAT_253f26866b0 = 0x55c4a4c8;
    DAT_253f26866b8 = 0x55952ec8;
    DAT_253f26866c0 = 0x55719648;
    DAT_253f26866c8 = 0x554cac48;
    DAT_253f26866d0 = 0x551e87c8;
    DAT_253f26866d8 = 0x54f99dc8;
    DAT_253f26866e0 = 0x54d4b3c8;
    DAT_253f26866e8 = 0x54afc9c8;
    DAT_253f26866f0 = 0x5481a548;
    DAT_253f26866f8 = 0x545cbb48;
    DAT_253f2686700 = 0x542e96c8;
    DAT_253f2686708 = 0x5409acc8;
    DAT_253f2686710 = 0x53db8848;
    DAT_253f2686718 = 0x53b54cc8;
    DAT_253f2686720 = 0x5391b448;
    DAT_253f2686728 = 0x53638fc8;
    DAT_253f2686730 = 0x533ea5c8;
    DAT_253f2686738 = 0x5319bbc8;
    DAT_253f2686740 = 0x52f4d1c8;
    DAT_253f2686748 = 0x52cfe7c8;
    DAT_253f2686750 = 0x52a1c348;
    DAT_253f2686758 = 0x527cd948;
    DAT_253f2686760 = 0x52666fc8;
    DAT_253f2686768 = 0x5229cac8;
    DAT_253f2686770 = 0x51fba648;
    DAT_253f2686778 = 0x51d6bc48;
    DAT_253f2686780 = 0x51b1d248;
    DAT_253f2686788 = 0x5183adc8;
    DAT_253f2686790 = 0x515ec3c8;
    DAT_253f2686798 = 0x5139d9c8;
    DAT_253f26867a0 = 0x510bb548;
    DAT_253f26867a8 = 0x50e6cb48;
    DAT_253f26867b0 = 0x50c1e148;
    DAT_253f26867b8 = 0x5093bcc8;
    DAT_253f26867c0 = 0x506ed2c8;
    DAT_253f26867c8 = 0x5049e8c8;
    DAT_253f26867d0 = 0x501bc448;
    DAT_253f26867d8 = 0x4ff6da48;
    DAT_253f26867e0 = 0x4fc8b5c8;
    DAT_253f26867e8 = 0x4fa3cbc8;
    DAT_253f26867f0 = 0x4f7ee1c8;
    DAT_253f26867f8 = 0x4f59f7c8;
    DAT_253f2686800 = 0x4f2bd348;
    DAT_253f2686808 = 0x4f06e948;
    DAT_253f2686810 = 0x4ed8c4c8;
    DAT_253f2686818 = 0x4eb3dac8;
    DAT_253f2686820 = 0x4e8ef0c8;
    DAT_253f2686828 = 0x4e60cc48;
    DAT_253f2686830 = 0x4e3be248;
    DAT_253f2686838 = 0x4e16f848;
    DAT_253f2686840 = 0x4de8d3c8;
    DAT_253f2686848 = 0x4dc3e9c8;
    DAT_253f2686850 = 0x4d95c548;
    DAT_253f2686858 = 0x4d70db48;
    DAT_253f2686860 = 0x4d4bf148;
    DAT_253f2686868 = 0x4d270748;
    DAT_253f2686870 = 0x4cf8e2c8;
    DAT_253f2686878 = 0x4cd3f8c8;
    DAT_253f2686880 = 0x4caf0ec8;
    DAT_253f2686888 = 0x4c80ea48;
    DAT_253f2686890 = 0x4c5c0048;
    DAT_253f2686898 = 0x4c2ddbc8;
    DAT_253f26868a0 = 0x4c08f1c8;
    DAT_253f26868a8 = 0x4be407c8;
    DAT_253f26868b0 = 0x4bb5e348;
    DAT_253f26868b8 = 0x4b90f948;
    DAT_253f26868c0 = 0x4b6c0f48;
    DAT_253f26868c8 = 0x4b472548;
    DAT_253f26868d0 = 0x4b1900c8;
    DAT_253f26868d8 = 0x4af416c8;
    DAT_253f26868e0 = 0x4ac5f248;
    DAT_253f26868e8 = 0x4aa10848;
    DAT_253f26868f0 = 0x4a7c1e48;
    DAT_253f26868f8 = 0x4a4ca848;
    DAT_253f2686900 = 0x4a290fc8;
    DAT_253f2686908 = 0x4a0425c8;
    DAT_253f2686910 = 0x49d60148;
    DAT_253f2686918 = 0x49b11748;
    DAT_253f2686920 = 0x498c2d48;
    DAT_253f2686928 = 0x49674348;
    DAT_253f2686930 = 0x49391ec8;
    DAT_253f2686938 = 0x491434c8;
    DAT_253f2686940 = 0x48e61048;
    DAT_253f2686948 = 0x48c12648;
    DAT_253f2686950 = 0x489301c8;
    DAT_253f2686958 = 0x486cc648;
    DAT_253f2686960 = 0x48492dc8;
    DAT_253f2686968 = 0x481b0948;
    DAT_253f2686970 = 0x47f61f48;
    DAT_253f2686978 = 0x47d13548;
    DAT_253f2686980 = 0x47a310c8;
    DAT_253f2686988 = 0x477e26c8;
    DAT_253f2686990 = 0x47593cc8;
    DAT_253f2686998 = 0x472b1848;
    DAT_253f26869a0 = 0x47062e48;
    DAT_253f26869a8 = 0x46e14448;
    DAT_253f26869b0 = 0x46b31fc8;
    DAT_253f26869b8 = 0x468e35c8;
    DAT_253f26869c0 = 0x46601148;
    DAT_253f26869c8 = 0x463b2748;
    DAT_253f26869d0 = 0x46163d48;
    DAT_253f26869d8 = 0x45f15348;
    DAT_253f26869e0 = 0x45c32ec8;
    DAT_253f26869e8 = 0x459e44c8;
    DAT_253f2686be0 = 0x6b199720;
    DAT_253f2686be8 = 0x6ae23820;
    DAT_253f2686bf0 = 0x6aaad920;
    DAT_253f2686bf8 = 0x6a6a3fa0;
    DAT_253f2686c00 = 0x6a32e0a0;
    DAT_253f2686c08 = 0x69f24720;
    DAT_253f2686c10 = 0x69bae820;
    DAT_253f2686c18 = 0x697a4ea0;
    DAT_253f2686c20 = 0x6939b520;
    DAT_253f2686c28 = 0x69025620;
    DAT_253f2686c30 = 0x68caf720;
    DAT_253f2686c38 = 0x688a5da0;
    DAT_253f2686c40 = 0x6852fea0;
    DAT_253f2686c48 = 0x681b9fa0;
    DAT_253f2686c50 = 0x67db0620;
    DAT_253f2686c58 = 0x679a6ca0;
    DAT_253f2686c60 = 0x67630da0;
    DAT_253f2686c68 = 0x672d0020;
    DAT_253f2686c70 = 0x66eb1520;
    DAT_253f2686c78 = 0x66aa7ba0;
    DAT_253f2686c80 = 0x6669e220;
    DAT_253f2686c88 = 0x66328320;
    DAT_253f2686c90 = 0x65fb2420;
    DAT_253f2686c98 = 0x65ba8aa0;
    DAT_253f2686ca0 = 0x6579f120;
    DAT_253f2686ca8 = 0x65429220;
    DAT_253f2686cb0 = 0x650b3320;
    DAT_253f2686cb8 = 0x64c15f20;
    DAT_253f2686cc0 = 0x648a0020;
    DAT_253f2686cc8 = 0x6452a120;
    DAT_253f2686cd0 = 0x641b4220;
    DAT_253f2686cd8 = 0x63daa8a0;
    DAT_253f2686ce0 = 0x639a0f20;
    DAT_253f2686ce8 = 0x6362b020;
    DAT_253f2686cf0 = 0x632b5120;
    DAT_253f2686cf8 = 0x62e17d20;
    DAT_253f2686d00 = 0x62aa1e20;
    DAT_253f2686d08 = 0x6272bf20;
    DAT_253f2686d10 = 0x623225a0;
    DAT_253f2686d18 = 0x61f18c20;
    DAT_253f2686d20 = 0x61ba2d20;
    DAT_253f2686d28 = 0x6182ce20;
    DAT_253f2686d30 = 0x614b6f20;
    DAT_253f2686d38 = 0x61019b20;
    DAT_253f2686d40 = 0x60ca3c20;
    DAT_253f2686d48 = 0x6089a2a0;
    DAT_253f2686d50 = 0x605243a0;
    DAT_253f2686d58 = 0x6011aa20;
    DAT_253f2686d60 = 0x5fda4b20;
    DAT_253f2686d68 = 0x5fa43da0;
    DAT_253f2686d70 = 0x5f6252a0;
    DAT_253f2686d78 = 0x5f21b920;
    DAT_253f2686d80 = 0x5ee11fa0;
    DAT_253f2686d88 = 0x5ea9c0a0;
    DAT_253f2686d90 = 0x5e6e6d20;
    DAT_253f2686d98 = 0x5e5e9b20;
    DAT_253f2686da0 = 0x5e31c820;
    DAT_253f2686da8 = 0x5df12ea0;
    DAT_253f2686db0 = 0x5db9cfa0;
    DAT_253f2686db8 = 0x5d8270a0;
    DAT_253f2686dc0 = 0x5d41d720;
    DAT_253f2686dc8 = 0x5d0a7820;
    DAT_253f2686dd0 = 0x5cc9dea0;
    DAT_253f2686dd8 = 0x5c927fa0;
    DAT_253f2686de0 = 0x5c51e620;
    DAT_253f2686de8 = 0x5c1a8720;
    DAT_253f2686df0 = 0x5be479a0;
    DAT_253f2686df8 = 0x5babc920;
    DAT_253f2686e00 = 0x5b61f520;
    DAT_253f2686e08 = 0x5b215ba0;
    DAT_253f2686e10 = 0x5ae9fca0;
    DAT_253f2686e18 = 0x5ab29da0;
    DAT_253f2686e20 = 0x5a720420;
    DAT_253f2686e28 = 0x5a316aa0;
    DAT_253f2686e30 = 0x59fa0ba0;
    DAT_253f2686e38 = 0x59c2aca0;
    DAT_253f2686e40 = 0x5978d8a0;
    DAT_253f2686e48 = 0x594179a0;
    DAT_253f2686e50 = 0x590a1aa0;
    DAT_253f2686e58 = 0x58c98120;
    DAT_253f2686e60 = 0x58922220;
    DAT_253f2686e68 = 0x585188a0;
    DAT_253f2686e70 = 0x581a29a0;
    DAT_253f2686e78 = 0x57e2caa0;
    DAT_253f2686e80 = 0x5798f6a0;
    DAT_253f2686e88 = 0x576197a0;
    DAT_253f2686e90 = 0x5720fe20;
    DAT_253f2686e98 = 0x56e99f20;
    DAT_253f2686ea0 = 0x56a905a0;
    DAT_253f2687540 = 0x6b1a9b48;
    DAT_253f2687548 = 0x6af5b148;
    DAT_253f2687550 = 0x6acf75c8;
    DAT_253f2687558 = 0x6aa2a2c8;
    DAT_253f2687560 = 0x6a7db8c8;
    DAT_253f2687568 = 0x6a577d48;
    DAT_253f2687570 = 0x6a2958c8;
    DAT_253f2687578 = 0x6a046ec8;
    DAT_253f2687580 = 0x69df84c8;
    DAT_253f2687588 = 0x69b16048;
    DAT_253f2687590 = 0x698c7648;
    DAT_253f2687598 = 0x69678c48;
    DAT_253f26875a0 = 0x693967c8;
    DAT_253f26875a8 = 0x6915cf48;
    DAT_253f26875b0 = 0x68ef93c8;
    DAT_253f26875b8 = 0x68c2c0c8;
    DAT_253f26875c0 = 0x689b33c8;
    DAT_253f26875c8 = 0x687649c8;
    DAT_253f26875d0 = 0x684976c8;
    DAT_253f26875d8 = 0x68233b48;
    DAT_253f26875e0 = 0x67f7b9c8;
    DAT_253f26875e8 = 0x67d17e48;
    DAT_253f26875f0 = 0x67ac9448;
    DAT_253f26875f8 = 0x6787aa48;
    DAT_253f2687600 = 0x675985c8;
    DAT_253f2687608 = 0x67349bc8;
    DAT_253f2687610 = 0x6707c8c8;
    DAT_253f2687618 = 0x66e18d48;
    DAT_253f2687620 = 0x66bca348;
    DAT_253f2687628 = 0x668fd048;
    DAT_253f2687630 = 0x666994c8;
    DAT_253f2687638 = 0x6644aac8;
    DAT_253f2687640 = 0x66168648;
    DAT_253f2687648 = 0x65f04ac8;
    DAT_253f2687650 = 0x65cb60c8;
    DAT_253f2687658 = 0x659fdf48;
    DAT_253f2687660 = 0x65785248;
    DAT_253f2687668 = 0x65536848;
    DAT_253f2687670 = 0x6527e6c8;
    DAT_253f2687678 = 0x6501ab48;
    DAT_253f2687680 = 0x64d4d848;
    DAT_253f2687688 = 0x64ae9cc8;
    DAT_253f2687690 = 0x64886148;
    DAT_253f2687698 = 0x645b8e48;
    DAT_253f26876a0 = 0x6436a448;
    DAT_253f26876a8 = 0x641068c8;
    DAT_253f26876b0 = 0x63eb7ec8;
    DAT_253f26876b8 = 0x63bffd48;
    DAT_253f26876c0 = 0x63987048;
    DAT_253f26876c8 = 0x636ceec8;
    DAT_253f26876d0 = 0x634804c8;
    DAT_253f26876d8 = 0x632077c8;
    DAT_253f26876e0 = 0x62f3a4c8;
    DAT_253f26876e8 = 0x62cebac8;
    DAT_253f26876f0 = 0x62a33948;
    DAT_253f26876f8 = 0x627bac48;
    DAT_253f2687700 = 0x625570c8;
    DAT_253f2687708 = 0x6229ef48;
    DAT_253f2687710 = 0x62050548;
    DAT_253f2687718 = 0x61dec9c8;
    DAT_253f2687720 = 0x61b34848;
    DAT_253f2687728 = 0x618bbb48;
    DAT_253f2687730 = 0x6166d148;
    DAT_253f2687738 = 0x614095c8;
    DAT_253f2687740 = 0x6113c2c8;
    DAT_253f2687748 = 0x60ed8748;
    DAT_253f2687750 = 0x60c205c8;
    DAT_253f2687758 = 0x609bca48;
    DAT_253f2687760 = 0x60758ec8;
    DAT_253f2687768 = 0x6048bbc8;
    DAT_253f2687770 = 0x6023d1c8;
    DAT_253f2687778 = 0x5ffee7c8;
    DAT_253f2687780 = 0x5fd214c8;
    DAT_253f2687788 = 0x5fad2ac8;
    DAT_253f2687790 = 0x5f859dc8;
    DAT_253f2687798 = 0x5f5b6dc8;
    DAT_253f26877a0 = 0x5f33e0c8;
    DAT_253f26877a8 = 0x5f0da548;
    DAT_253f26877b0 = 0x5ee0d248;
    DAT_253f26877b8 = 0x5eba96c8;
    DAT_253f26877c0 = 0x5e9066c8;
    DAT_253f26877c8 = 0x5e68d9c8;
    DAT_253f26877d0 = 0x5e454148;
    DAT_253f26877d8 = 0x5e1db448;
    DAT_253f26877e0 = 0x5df0e148;
    DAT_253f26877e8 = 0x5dcbf748;
    DAT_253f26877f0 = 0x5d9f2448;
    DAT_253f26877f8 = 0x5d7a3a48;
    DAT_253f2687800 = 0x5d52ad48;
    DAT_253f2687808 = 0x5d272bc8;
    DAT_253f2687810 = 0x5d00f048;
    DAT_253f2687818 = 0x5cd56ec8;
    DAT_253f2687820 = 0x5cade1c8;
    DAT_253f2687828 = 0x5c87a648;
    DAT_253f2687830 = 0x5c640dc8;
    DAT_253f2687838 = 0x5c388c48;
    DAT_253f2687840 = 0x5c10ff48;
    DAT_253f2687848 = 0x5bec1548;
    DAT_253f2687850 = 0x5bbf4248;
    DAT_253f2687858 = 0x5b9a5848;
    DAT_253f2687860 = 0x5b6d8548;
    DAT_253f2687868 = 0x5b4749c8;
    DAT_253f2687870 = 0x5b1fbcc8;
    DAT_253f2687878 = 0x5af43b48;
    DAT_253f2687880 = 0x5acdffc8;
    DAT_253f2687888 = 0x5aa7c448;
    DAT_253f2687890 = 0x5a842bc8;
    DAT_253f2687898 = 0x5a58aa48;
    DAT_253f26878a0 = 0x5a311d48;
    DAT_253f26878a8 = 0x5a0c3348;
    DAT_253f26878b0 = 0x59e0b1c8;
    DAT_253f26878b8 = 0x59ba7648;
    DAT_253f26878c0 = 0x598da348;
    DAT_253f26878c8 = 0x5968b948;
    DAT_253f26878d0 = 0x59412c48;
    DAT_253f26878d8 = 0x5915aac8;
    DAT_253f26878e0 = 0x58f0c0c8;
    DAT_253f26878e8 = 0x58c933c8;
    DAT_253f26878f0 = 0x58a449c8;
    DAT_253f26878f8 = 0x587f5fc8;
    DAT_253f2687900 = 0x58528cc8;
    DAT_253f2687908 = 0x582da2c8;
    DAT_253f2687910 = 0x580615c8;
    DAT_253f2687918 = 0x57dbe5c8;
    DAT_253f2687920 = 0x57b30748;
    DAT_253f2687928 = 0x5788d748;
    DAT_253f2687930 = 0x57629bc8;
    DAT_253f2687938 = 0x573b0ec8;
    DAT_253f2687940 = 0x570f8d48;
    DAT_253f2687948 = 0x56e951c8;
    DAT_253f2687950 = 0x56c70ac8;
    DAT_253f2687958 = 0x569f7dc8;
    DAT_253f2687960 = 0x567007c8;
    DAT_253f2687968 = 0x564b1dc8;
    FUN_253f26205c0(&DAT_253f267e478,&DAT_253f2688608,0,&PTR_DAT_253f2679058);
    DAT_253f2686258 = 0;
    DAT_253f2686220 = 0;
    DAT_253f2686248 = 0;
    DAT_253f267e474 = DAT_253f2688600;
    DAT_253f2688258 = 0xffffffff;
    DAT_253f2688254 = 0;
    DAT_253f26861d4 = 1;
    dVar25 = DAT_253f266cd40;
    if (DAT_253f26861e8 == '\0') {
      dVar25 = 0.0;
    }
    DAT_253f26861d8 = dVar25 * DAT_253f2686238 * DAT_253f2688538;
    dVar25 = 0.0;
    if (DAT_253f26861e8 != '\0') {
      dVar25 = DAT_253f266cd48;
    }
    DAT_253f26861e0 = DAT_253f2688538 * dVar25 * DAT_253f2686240;
    FUN_253f26205c0(&DAT_253f2685858,&DAT_253f2688428,1,&PTR_DAT_253f2679068);
    if (DAT_253f267e1f4 == &DAT_253f266e408) {
LAB_253f26239d3:
      uVar6 = 0xfa9;
      if ((DAT_253f268585c == 0) || (DAT_253f268585c == 0xc)) {
LAB_253f2623a3a:
        DAT_253f2688410 = uVar6;
        if ((DAT_253f2688440 == (undefined2 *)0x0) || (DAT_253f2688440 == (undefined2 *)0xc)) {
          DAT_253f2688410 = 0xfa9;
        }
        else if ((*(int *)(DAT_253f2688440 + -2) != 0) &&
                (cVar7 = FUN_253f2620060(&DAT_253f268843c,0), puVar5 = DAT_253f2688440,
                cVar7 != '\0')) {
          *(undefined4 *)(DAT_253f2688440 + -2) = 0;
          *puVar5 = 0;
        }
      }
      else {
        uVar3 = *(uint *)(DAT_253f268585c + -4);
        uVar6 = 0x13ab;
        if (uVar3 < 7) goto LAB_253f2623a3a;
        iVar9 = 10;
        if (uVar3 == 0xf || (int)(uVar3 - 6) < 9) {
          DAT_253f2688410 = 0x13ab;
          iVar9 = uVar3 - 6;
        }
        FUN_253f26201e0(&DAT_253f268843c,DAT_253f268585c + 0xc,iVar9);
      }
      FUN_253f26205c0(&local_98,&DAT_253f268843c,1,&PTR_DAT_253f2679078);
      FUN_253f26205c0(&DAT_253f267e1f0,&local_98,0,&PTR_DAT_253f2679088);
      if (DAT_253f267e1f4 != &DAT_253f266e408) {
        if (DAT_253f267e1f4 != (undefined2 *)0x0) {
          uVar3 = *(uint *)(DAT_253f267e1f4 + -2);
          uVar18 = DAT_253f266e404;
          if (uVar3 < DAT_253f266e404) {
            uVar18 = uVar3;
          }
          iVar9 = uVar3 - DAT_253f266e404;
          if (uVar18 != 0) {
            uVar11 = 0;
            do {
              uVar1 = DAT_253f267e1f4[uVar11];
              uVar2 = (&DAT_253f266e408)[uVar11];
              uVar11 = uVar11 + 1;
              if (uVar18 <= uVar11) break;
            } while (uVar1 == uVar2);
            if (uVar1 != uVar2) {
              iVar9 = (uint)uVar1 - (uint)uVar2;
            }
          }
          if (iVar9 == 0) goto LAB_253f2623c9c;
        }
        FUN_253f26205c0(&local_98,&string_ref_253f266f410,0);
        puVar5 = DAT_253f267e1f4;
        if (DAT_253f267e1f4 != (undefined2 *)0x0) {
          uVar3 = *(uint *)(DAT_253f267e1f4 + -2);
          uVar11 = (ulonglong)uVar3;
          if ((uVar3 != 0) || (local_94 == 0)) {
            if (local_94 == 0) {
              uVar16 = 0;
              uVar18 = uVar3;
            }
            else {
              uVar16 = (ulonglong)*(uint *)(local_94 + -4);
              uVar18 = uVar3 + *(uint *)(local_94 + -4);
            }
            cVar7 = FUN_253f2620060(&local_98);
            if (cVar7 == '\0') goto LAB_253f26258a9;
            if (uVar3 != 0) {
              lVar10 = local_94 + uVar16 * 2;
              if (uVar3 < 0x10) {
                uVar16 = 0;
              }
              else if ((ulonglong)(lVar10 - (longlong)puVar5) < 0x20) {
                uVar16 = 0;
              }
              else {
                uVar22 = 0;
                uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
                do {
                  uVar15 = ((undefined8 *)((longlong)puVar5 + uVar22))[1];
                  *(undefined8 *)(lVar10 + uVar22) = *(undefined8 *)((longlong)puVar5 + uVar22);
                  ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar16 == uVar11) goto LAB_253f2623c62;
              }
              do {
                *(undefined2 *)(lVar10 + uVar16 * 2) = puVar5[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar11 != uVar16);
            }
LAB_253f2623c62:
            *(uint *)(local_94 + -4) = uVar18;
            *(undefined2 *)(local_94 + (ulonglong)uVar18 * 2) = 0;
          }
        }
        MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
      }
    }
    else if (DAT_253f267e1f4 != (undefined2 *)0x0) {
      uVar3 = *(uint *)(DAT_253f267e1f4 + -2);
      uVar18 = DAT_253f266e404;
      if (uVar3 < DAT_253f266e404) {
        uVar18 = uVar3;
      }
      iVar9 = uVar3 - DAT_253f266e404;
      if (uVar18 != 0) {
        uVar11 = 0;
        do {
          uVar1 = DAT_253f267e1f4[uVar11];
          uVar2 = (&DAT_253f266e408)[uVar11];
          uVar11 = uVar11 + 1;
          if (uVar18 <= uVar11) break;
        } while (uVar1 == uVar2);
        if (uVar1 != uVar2) {
          iVar9 = (uint)uVar1 - (uint)uVar2;
        }
      }
      if (iVar9 == 0) goto LAB_253f26239d3;
    }
LAB_253f2623c9c:
    FUN_253f2627550(0);
    local_88 = 0;
    local_78 = 0;
    local_a8 = 0;
    local_84 = 0;
    local_74 = 0;
    local_a4 = 0;
    if (DAT_253f267e41c < 0) {
      DAT_253f267e54d = 0;
    }
    DAT_253f2685834 = 0;
    (*(code *)&MT5_Bars)(0x253ee076f88,&DAT_253f2685858,DAT_253f267e434);
    (*(code *)&MT5_Bars)(0x253ee076f88,&DAT_253f2685858,DAT_253f267e494);
    MT5_TimeCurrent((void *)0x253ee076f88,(void *)0x0);
    DAT_253f267e558 = DAT_253f26856a0 - DAT_253f2685698;
    dVar24 = DAT_253f267e528 * DAT_253f266cd50;
    dVar20 = ABS(dVar24);
    uVar3 = (uint)((ulonglong)dVar20 >> 0x20);
    dVar25 = dVar24;
    if (uVar3 >> 0x14 < 0x3ff) {
      if ((dVar20 != 0.0) && (dVar25 = 0.0, (longlong)dVar24 < 0)) {
        dVar25 = DAT_253f266cd58;
      }
    }
    else if (((uVar3 >> 0x16 < 0x10d) &&
             (bVar14 = 0x33 - (char)((ulonglong)dVar20 >> 0x34),
             dVar26 = (double)(((ulonglong)dVar20 >> (bVar14 & 0x3f)) << (bVar14 & 0x3f)),
             dVar25 = dVar26, (longlong)dVar24 < 1)) &&
            (dVar25 = (double)((ulonglong)dVar26 | 0x8000000000000000), dVar26 != dVar20)) {
      dVar25 = dVar25 + DAT_253f266cd58;
    }
    dVar25 = dVar25 / DAT_253f266cd50;
    if ((longlong)dVar25 != -0x8000000000000000) {
      dVar20 = (double)(longlong)dVar25;
      dVar25 = (double)(longlong)
                       ((dVar25 - dVar20) * DAT_253f266cd50 +
                       *(double *)(&DAT_253f266cd60 + (ulonglong)(0.0 < dVar25) * 8)) /
               DAT_253f266cd50 + dVar20;
    }
    (&DAT_253f26849c0)[DAT_253f2685834] = dVar25;
    MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x24);
    dVar25 = DAT_253f266cd70;
    uVar11 = (ulonglong)DAT_253f2685834;
    if ((DAT_253f2688448 != DAT_253f266cd70) || (NAN(DAT_253f2688448) || NAN(DAT_253f266cd70))) {
      dVar20 = (double)(&DAT_253f26849c0)[uVar11];
    }
    else {
      dVar26 = DAT_253f267e528 * DAT_253f266cd78;
      dVar24 = ABS(dVar26);
      dVar20 = dVar26;
      if ((ulonglong)dVar24 < 0x3ff0000000000000) {
        if ((dVar24 != 0.0) && (dVar20 = 0.0, (longlong)dVar26 < 0)) {
          dVar20 = DAT_253f266cd58;
        }
      }
      else if ((((uint)((ulonglong)dVar24 >> 0x36) < 0x10d) &&
               (bVar14 = 0x33 - (char)((ulonglong)dVar24 >> 0x34),
               dVar21 = (double)(((ulonglong)dVar24 >> (bVar14 & 0x3f)) << (bVar14 & 0x3f)),
               dVar20 = dVar21, (longlong)dVar26 < 1)) &&
              (dVar20 = (double)((ulonglong)dVar21 | 0x8000000000000000), dVar21 != dVar24)) {
        dVar20 = dVar20 + DAT_253f266cd58;
      }
      dVar20 = dVar20 / DAT_253f266cd78;
      if ((longlong)dVar20 != -0x8000000000000000) {
        dVar24 = (double)(longlong)dVar20;
        dVar20 = (double)(longlong)
                         ((dVar20 - dVar24) * DAT_253f266cd78 +
                         *(double *)(&DAT_253f266cd60 + (ulonglong)(0.0 < dVar20) * 8)) /
                 DAT_253f266cd78 + dVar24;
      }
      (&DAT_253f26849c0)[uVar11] = dVar20;
      if (dVar20 < dVar25) {
        (&DAT_253f26849c0)[uVar11] = 0x3fb999999999999a;
        dVar20 = dVar25;
      }
    }
    MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x22);
    if (dVar20 < DAT_253f2688448) {
      MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x22);
      runtime_cast_to_string((void *)0x253ee076f88,(ulonglong)DAT_253f2688448,0x58,&local_a8);
      FUN_253f26205c0(&local_78,&string_ref_253f2670fe8,0);
      lVar10 = local_a4;
      if (local_a4 == 0) {
LAB_253f26241f7:
        uVar16 = 0;
        FUN_253f26205c0(&local_88,&local_78,0);
        uVar3 = DAT_253f2671008;
        uVar11 = (ulonglong)DAT_253f2671008;
        if ((DAT_253f2671008 == 0) && (local_84 != 0)) {
LAB_253f26242f7:
          MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
          MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x22);
          dVar25 = DAT_253f2688448;
          (&DAT_253f26849c0)[DAT_253f2685834] = DAT_253f2688448;
          goto LAB_253f2624352;
        }
        if (local_84 != 0) {
          uVar16 = (ulonglong)*(uint *)(local_84 + -4);
        }
        uVar18 = DAT_253f2671008 + (int)uVar16;
        cVar7 = FUN_253f2620060(&local_88);
        if (cVar7 != '\0') {
          if (uVar3 != 0) {
            lVar10 = local_84 + uVar16 * 2;
            if ((uVar3 < 0x10) || (lVar10 - 0x253f267100cU < 0x20)) {
              uVar16 = 0;
            }
            else {
              uVar22 = 0;
              uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
              do {
                uVar15 = *(undefined8 *)((longlong)literal_253f267100c + uVar22 + 8);
                *(undefined8 *)(lVar10 + uVar22) =
                     *(undefined8 *)((longlong)literal_253f267100c + uVar22);
                ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                uVar22 = uVar22 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar16 == uVar11) goto LAB_253f26242e2;
            }
            do {
              *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f267100c[uVar16];
              uVar16 = uVar16 + 1;
            } while (uVar11 != uVar16);
          }
LAB_253f26242e2:
          *(uint *)(local_84 + -4) = uVar18;
          *(undefined2 *)(local_84 + (ulonglong)uVar18 * 2) = 0;
          goto LAB_253f26242f7;
        }
        goto LAB_253f26257a9;
      }
      uVar3 = *(uint *)(local_a4 + -4);
      uVar11 = (ulonglong)uVar3;
      if ((uVar3 == 0) && (local_74 != 0)) goto LAB_253f26241f7;
      if (local_74 == 0) {
        uVar16 = 0;
        uVar18 = uVar3;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(local_74 + -4);
        uVar18 = uVar3 + *(uint *)(local_74 + -4);
      }
      cVar7 = FUN_253f2620060(&local_78);
      if (cVar7 != '\0') {
        if (uVar3 != 0) {
          lVar12 = local_74 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              uVar15 = ((undefined8 *)(lVar10 + uVar22))[1];
              *(undefined8 *)(lVar12 + uVar22) = *(undefined8 *)(lVar10 + uVar22);
              ((undefined8 *)(lVar12 + uVar22))[1] = uVar15;
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f26241e2;
          }
          do {
            *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f26241e2:
        *(uint *)(local_74 + -4) = uVar18;
        *(undefined2 *)(local_74 + (ulonglong)uVar18 * 2) = 0;
        goto LAB_253f26241f7;
      }
      goto LAB_253f2625869;
    }
    dVar25 = (double)(&DAT_253f26849c0)[DAT_253f2685834];
LAB_253f2624352:
    MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x23);
    if (dVar25 <= DAT_253f2688448) {
LAB_253f26246c2:
      dVar25 = DAT_253f267e518 * DAT_253f2684cd8;
      MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x10);
      if (DAT_253f2688448 <= dVar25) {
LAB_253f2624746:
        MT5_AccountInfoDouble((void *)0x253ee076f88,0x25);
        lVar10 = MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x1f);
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x10);
        DAT_253f26849b0 = (double)lVar10 * DAT_253f2688448;
        lVar10 = MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x20);
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x10);
        DAT_253f26853a8 = (double)lVar10 * DAT_253f2688448;
        dVar25 = DAT_253f267e4a0;
        if (DAT_253f267e4a0 <= 0.0) {
          DAT_253f267e4a0 = 1.0;
          dVar25 = DAT_253f266cd80;
        }
        dVar20 = DAT_253f267e4a8;
        if (DAT_253f267e4a8 <= 0.0) {
          DAT_253f267e4a8 = 1.0;
          dVar20 = DAT_253f266cd80;
        }
        if (DAT_253f267e4d0 < DAT_253f267e4d8) {
          DAT_253f267e4d8 = DAT_253f267e4d0 + DAT_253f266cd70;
        }
        if ((DAT_253f2684cd8 == 0.0) && (!NAN(DAT_253f2684cd8))) {
          (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x2306c2000001f7);
          goto LAB_253f26256c9;
        }
        dVar24 = DAT_253f26853a8 / DAT_253f2684cd8;
        if ((double)DAT_253f267e3e8 < dVar24) {
          DAT_253f267e3e8 = (int)dVar24;
        }
        if (((DAT_253f267e4b0 != 0.0) || (NAN(DAT_253f267e4b0))) && (DAT_253f267e4b0 < dVar24)) {
          DAT_253f267e4b0 = dVar24;
        }
        if (((DAT_253f267e4b0 != 0.0) || (NAN(DAT_253f267e4b0))) &&
           (DAT_253f267e4b0 < DAT_253f26849b0 / DAT_253f2684cd8)) {
          DAT_253f267e4b0 = DAT_253f26849b0 / DAT_253f2684cd8;
        }
        if (0.0 < DAT_253f267e4f0) {
          if (DAT_253f267e4f8 < dVar24) {
            DAT_253f267e4f8 = dVar24;
          }
          if (DAT_253f267e4f8 < DAT_253f26849b0 / DAT_253f2684cd8) {
            DAT_253f267e4f8 = DAT_253f26849b0 / DAT_253f2684cd8;
          }
        }
        dVar24 = (DAT_253f26849b0 + DAT_253f26849b0) / DAT_253f2684cd8;
        dVar26 = dVar24;
        if (dVar24 <= dVar25) {
          dVar26 = DAT_253f267e4a0;
        }
        DAT_253f267e4a0 = dVar26;
        if (dVar20 < dVar24) {
          DAT_253f267e4a8 = dVar24;
        }
        if (dVar24 <= DAT_253f267e448) {
          dVar24 = DAT_253f267e448;
        }
        DAT_253f267e448 = dVar24;
        if (DAT_253f267e438 < 1) {
          DAT_253f267e438 = 1;
        }
        if (DAT_253f267e43c < 1) {
          DAT_253f267e43c = 1;
        }
        if (DAT_253f267e448 < DAT_253f266cd70) {
          DAT_253f267e448 = 0.1;
        }
        DAT_253f2684ce0 = DAT_253f267e470 * 0xe10;
        if (DAT_253f267e470 < 1) {
          DAT_253f2685390 = 0;
        }
        else {
          lVar10 = MT5_TimeCurrent((void *)0x253ee076f88,(void *)0x0);
          DAT_253f2685390 = (ulonglong)DAT_253f2684ce0 + lVar10;
        }
        DAT_253f26853c9 = 0;
        if (DAT_253f267e421 != '\0') {
          DAT_253f2685390 = 0;
        }
        DAT_253f26853c8 = 0;
        DAT_253f26853ca = 0;
        MT5_TimeCurrent((void *)0x253ee076f88,(void *)0x0);
        DAT_253f26853b8 = MT5_iTime((void *)0x253ee076f88,&DAT_253f2685858,0x8001,1);
        MT5_iTime((void *)0x253ee076f88,&DAT_253f2685858,1,1);
        MT5_iTime((void *)0x253ee076f88,&DAT_253f2685858,1,1);
        if (DAT_253f267e3e0 < DAT_253f267e550) {
          DAT_253f267e550 = DAT_253f267e3e0;
        }
        uVar15 = 0;
        if (DAT_253f267e264 != '\0') {
          uVar15 = 0x4018;
        }
        FUN_253f2646910(uVar15);
        uVar15 = 0;
        if (DAT_253f267e264 != '\0') {
          uVar15 = 0x4018;
        }
        FUN_253f2646d10(uVar15);
        uVar11 = MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x11);
        DAT_253f267e568 = DAT_253f2685380;
        if ((longlong)DAT_253f2685380 != -0x8000000000000000) {
          dVar25 = (double)(longlong)DAT_253f2685380;
          uVar16 = 0xb;
          if ((uint)uVar11 < 0xb) {
            uVar16 = uVar11 & 0xffffffff;
          }
          DAT_253f267e568 =
               (double)(longlong)
                       ((DAT_253f2685380 - dVar25) * *(double *)(&DAT_253f266e230 + uVar16 * 8) +
                       *(double *)(&DAT_253f266cd60 + (ulonglong)(0.0 < DAT_253f2685380) * 8)) /
               *(double *)(&DAT_253f266e230 + uVar16 * 8) + dVar25;
        }
        uVar11 = MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x11);
        DAT_253f267e570 = DAT_253f2685378;
        if ((longlong)DAT_253f2685378 != -0x8000000000000000) {
          dVar25 = (double)(longlong)DAT_253f2685378;
          uVar16 = 0xb;
          if ((uint)uVar11 < 0xb) {
            uVar16 = uVar11 & 0xffffffff;
          }
          DAT_253f267e570 =
               (double)(longlong)
                       ((DAT_253f2685378 - dVar25) * *(double *)(&DAT_253f266e230 + uVar16 * 8) +
                       *(double *)(&DAT_253f266cd60 + (ulonglong)(0.0 < DAT_253f2685378) * 8)) /
               *(double *)(&DAT_253f266e230 + uVar16 * 8) + dVar25;
        }
        DAT_253f2685398 = 1;
        DAT_253f2685330 = 0;
        DAT_253f2685374 = 0;
        DAT_253f268539c = (int)(DAT_253f267e4f0 * DAT_253f266cd88);
        lVar10 = MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x20);
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x10);
        dVar25 = DAT_253f267e530;
        DAT_253f2685398 = 0;
        DAT_253f26853a8 = (double)lVar10 * DAT_253f2688448;
        DAT_253f267e578 = 0;
        if (DAT_253f267e528 < 0.0) {
          DAT_253f267e528 = 0.01;
        }
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x23);
        if (DAT_253f2688448 < dVar25) {
          MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x23);
          DAT_253f267e530 = DAT_253f2688448;
        }
        if (DAT_253f2684350 == '\x01') {
          memset(&DAT_253f267e580,0,12000);
          memset(&DAT_253f2681460,0,8000);
        }
        if (DAT_253f2684368 == '\x01') {
          memset(&DAT_253f26833b0,0,0x960);
        }
        lVar10 = 0;
        do {
          *(undefined8 *)((longlong)&DAT_253f26833b8 + lVar10) = 0;
          *(undefined8 *)((longlong)&DAT_253f26833b0 + lVar10) = 0;
          bVar23 = lVar10 != 0x948;
          lVar10 = lVar10 + 0x18;
        } while (bVar23);
        uVar16 = 0;
        DAT_253f26853a0 = 0;
        FUN_253f26205c0(&local_a8,&DAT_253f267e478,0,&PTR_DAT_253f2679fa8);
        uVar3 = DAT_253f2671098;
        uVar11 = (ulonglong)DAT_253f2671098;
        if ((DAT_253f2671098 != 0) || (local_a4 == 0)) {
          if (local_a4 != 0) {
            uVar16 = (ulonglong)*(uint *)(local_a4 + -4);
          }
          uVar17 = DAT_253f2671098 + (int)uVar16;
          uVar18 = 0x104;
          if ((0x103 < uVar17) &&
             ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
            uVar18 = 0x7ffffffe;
          }
          cVar7 = FUN_253f2620060(&local_a8,uVar18);
          if (cVar7 != '\0') {
            if (uVar3 != 0) {
              lVar10 = local_a4 + uVar16 * 2;
              if (uVar3 < 0x10) {
                uVar16 = 0;
              }
              else if (lVar10 - 0x253f267109cU < 0x20) {
                uVar16 = 0;
              }
              else {
                uVar22 = 0;
                uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
                do {
                  uVar15 = *(undefined8 *)(uVar22 + 0x253f26710a4);
                  *(undefined8 *)(lVar10 + uVar22) =
                       *(undefined8 *)((longlong)literal_253f267109c + uVar22);
                  ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar16 == uVar11) goto LAB_253f2625032;
              }
              do {
                *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f267109c[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar11 != uVar16);
            }
LAB_253f2625032:
            *(uint *)(local_a4 + -4) = uVar17;
            *(undefined2 *)(local_a4 + (ulonglong)uVar17 * 2) = 0;
            goto LAB_253f262503d;
          }
          goto LAB_253f26256e9;
        }
LAB_253f262503d:
        uVar16 = 0;
        FUN_253f26205c0(&DAT_253f2685338,&local_a8,0,&PTR_DAT_253f2679fb8);
        FUN_253f26205c0(&local_a8,&DAT_253f267e478,0,&PTR_DAT_253f2679fc8);
        uVar3 = DAT_253f26710b8;
        uVar11 = (ulonglong)DAT_253f26710b8;
        if ((DAT_253f26710b8 != 0) || (local_a4 == 0)) {
          if (local_a4 != 0) {
            uVar16 = (ulonglong)*(uint *)(local_a4 + -4);
          }
          uVar17 = DAT_253f26710b8 + (int)uVar16;
          uVar18 = 0x104;
          if ((0x103 < uVar17) &&
             ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
            uVar18 = 0x7ffffffe;
          }
          cVar7 = FUN_253f2620060(&local_a8,uVar18);
          if (cVar7 != '\0') {
            if (uVar3 != 0) {
              lVar10 = local_a4 + uVar16 * 2;
              if (uVar3 < 0x10) {
                uVar16 = 0;
              }
              else if (lVar10 - 0x253f26710bcU < 0x20) {
                uVar16 = 0;
              }
              else {
                uVar22 = 0;
                uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
                do {
                  uVar15 = *(undefined8 *)(uVar22 + 0x253f26710c4);
                  *(undefined8 *)(lVar10 + uVar22) =
                       *(undefined8 *)((longlong)literal_253f26710bc + uVar22);
                  ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar16 == uVar11) goto LAB_253f2625182;
              }
              do {
                *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f26710bc[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar11 != uVar16);
            }
LAB_253f2625182:
            *(uint *)(local_a4 + -4) = uVar17;
            *(undefined2 *)(local_a4 + (ulonglong)uVar17 * 2) = 0;
            goto LAB_253f262518d;
          }
          goto LAB_253f2625709;
        }
LAB_253f262518d:
        uVar16 = 0;
        FUN_253f26205c0(&DAT_253f2685348,&local_a8,0,&PTR_DAT_253f2679fd8);
        FUN_253f26205c0(&local_a8,&DAT_253f267e478,0,&PTR_DAT_253f2679fe8);
        uVar3 = DAT_253f26710d8;
        uVar11 = (ulonglong)DAT_253f26710d8;
        if ((DAT_253f26710d8 != 0) || (local_a4 == 0)) {
          if (local_a4 != 0) {
            uVar16 = (ulonglong)*(uint *)(local_a4 + -4);
          }
          uVar17 = DAT_253f26710d8 + (int)uVar16;
          uVar18 = 0x104;
          if ((0x103 < uVar17) &&
             ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
            uVar18 = 0x7ffffffe;
          }
          cVar7 = FUN_253f2620060(&local_a8,uVar18);
          if (cVar7 != '\0') {
            if (uVar3 != 0) {
              lVar10 = local_a4 + uVar16 * 2;
              if (uVar3 < 0x10) {
                uVar16 = 0;
              }
              else if (lVar10 - 0x253f26710dcU < 0x20) {
                uVar16 = 0;
              }
              else {
                uVar22 = 0;
                uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
                do {
                  uVar15 = *(undefined8 *)(uVar22 + 0x253f26710e4);
                  *(undefined8 *)(lVar10 + uVar22) =
                       *(undefined8 *)((longlong)literal_253f26710dc + uVar22);
                  ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                  uVar22 = uVar22 + 0x10;
                } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
                if (uVar16 == uVar11) goto LAB_253f26252d2;
              }
              do {
                *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f26710dc[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar11 != uVar16);
            }
LAB_253f26252d2:
            *(uint *)(local_a4 + -4) = uVar17;
            *(undefined2 *)(local_a4 + (ulonglong)uVar17 * 2) = 0;
            goto LAB_253f26252dd;
          }
          goto LAB_253f2625729;
        }
LAB_253f26252dd:
        uVar16 = 0;
        FUN_253f26205c0(&DAT_253f2685358,&local_a8,0,&PTR_DAT_253f2679ff8);
        FUN_253f26205c0(&local_a8,&DAT_253f267e478,0,&PTR_DAT_253f267a008);
        uVar3 = DAT_253f26710f8;
        uVar11 = (ulonglong)DAT_253f26710f8;
        if ((DAT_253f26710f8 == 0) && (local_a4 != 0)) {
LAB_253f262542d:
          uVar15 = 0;
          FUN_253f26205c0(&DAT_253f2685368,&local_a8,0,&PTR_DAT_253f267a018);
          DAT_253f2685388 = DAT_253f26856dc;
          DAT_253f2684370 = 0;
          MT5_SymbolInfoInteger((void *)0x253ee076f88,&DAT_253f2685858,0x11);
          if ((double)(&DAT_253f26849c0)[DAT_253f2685834] <= DAT_253f267e528 &&
              DAT_253f267e528 != (double)(&DAT_253f26849c0)[DAT_253f2685834]) {
            (&DAT_253f26849c0)[DAT_253f2685834] = DAT_253f267e528;
          }
          FUN_253f2620000(&local_a8);
          FUN_253f2620000(&local_78);
          FUN_253f2620000(&local_88);
          if (DAT_253f2688528 != '\0') {
            if (DAT_253f267e3cc == '\x01') {
              local_88 = 0;
              local_84 = 0;
              iVar9 = MT5_MQLInfoInteger((void *)0x253ee076f88,6);
              if ((((iVar9 != 1) || (DAT_253f2688530 != '\0')) &&
                  (bVar23 = MT5_HistorySelect((void *)0x253ee076f88,0,0x7fffffff), bVar23)) &&
                 (iVar9 = MT5_HistoryDealsTotal((void *)0x253ee076f88), -1 < iVar9 + -1)) {
                do {
                  iVar9 = iVar9 + -1;
                  uVar11 = MT5_HistoryDealGetTicket((void *)0x253ee076f88,iVar9);
                  lVar12 = MT5_HistoryDealGetInteger((void *)0x253ee076f88,uVar11,2);
                  lVar13 = MT5_TimeCurrent((void *)0x253ee076f88,(void *)0x0);
                  lVar10 = lVar13 + -0x76a700;
                  if (DAT_253f267e3cd == '\0') {
                    lVar10 = lVar13;
                  }
                  if (lVar12 < lVar10) break;
                  lVar10 = MT5_HistoryDealGetInteger((void *)0x253ee076f88,uVar11,0xb);
                  if (lVar10 == DAT_253f267e474) {
                    MT5_HistoryDealGetDouble((void *)0x253ee076f88,uVar11,5);
                  }
                } while (0 < iVar9);
              }
              FUN_253f2620000(&local_88);
            }
            FUN_253f26283d0();
            FUN_253f262e250();
            FUN_253f26300b0();
          }
LAB_253f2625670:
          FUN_253f2620000(&local_98);
          FUN_253f2620000(&local_b8);
          FUN_253f2620000(&local_68);
          return uVar15;
        }
        if (local_a4 != 0) {
          uVar16 = (ulonglong)*(uint *)(local_a4 + -4);
        }
        uVar17 = DAT_253f26710f8 + (int)uVar16;
        uVar18 = 0x104;
        if ((0x103 < uVar17) &&
           ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
          uVar18 = 0x7ffffffe;
        }
        cVar7 = FUN_253f2620060(&local_a8,uVar18);
        if (cVar7 != '\0') {
          if (uVar3 != 0) {
            lVar10 = local_a4 + uVar16 * 2;
            if (uVar3 < 0x10) {
              uVar16 = 0;
            }
            else if (lVar10 - 0x253f26710fcU < 0x20) {
              uVar16 = 0;
            }
            else {
              uVar22 = 0;
              uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
              do {
                uVar15 = *(undefined8 *)(uVar22 + 0x253f2671104);
                *(undefined8 *)(lVar10 + uVar22) =
                     *(undefined8 *)((longlong)literal_253f26710fc + uVar22);
                ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
                uVar22 = uVar22 + 0x10;
              } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
              if (uVar16 == uVar11) goto LAB_253f2625422;
            }
            do {
              *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f26710fc[uVar16];
              uVar16 = uVar16 + 1;
            } while (uVar11 != uVar16);
          }
LAB_253f2625422:
          *(uint *)(local_a4 + -4) = uVar17;
          *(undefined2 *)(local_a4 + (ulonglong)uVar17 * 2) = 0;
          goto LAB_253f262542d;
        }
      }
      else {
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x10);
        if ((DAT_253f2684cd8 != 0.0) || (NAN(DAT_253f2684cd8))) {
          DAT_253f267e518 = DAT_253f2688448 / DAT_253f2684cd8;
          goto LAB_253f2624746;
        }
LAB_253f26256c9:
        (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x4306b4000001f7);
LAB_253f26256e9:
        (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x19072e000001f9);
LAB_253f2625709:
        (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x19072f000001f9);
LAB_253f2625729:
        (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x190730000001f9);
      }
      (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x190731000001f9);
      goto LAB_253f2625769;
    }
    MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x23);
    runtime_cast_to_string((void *)0x253ee076f88,(ulonglong)DAT_253f2688448,0x58,&local_a8);
    FUN_253f26205c0(&local_78,&string_ref_253f2671078);
    lVar10 = local_a4;
    if (local_a4 == 0) {
LAB_253f2624537:
      uVar16 = 0;
      FUN_253f26205c0(&local_88,&local_78,0,&PTR_DAT_253f2679f98);
      uVar3 = DAT_253f2671008;
      uVar11 = (ulonglong)DAT_253f2671008;
      if ((DAT_253f2671008 == 0) && (local_84 != 0)) {
LAB_253f2624667:
        MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
        MT5_SymbolInfoDouble((void *)0x253ee076f88,&DAT_253f2685858,0x23);
        (&DAT_253f26849c0)[DAT_253f2685834] = DAT_253f2688448;
        goto LAB_253f26246c2;
      }
      if (local_84 != 0) {
        uVar16 = (ulonglong)*(uint *)(local_84 + -4);
      }
      uVar17 = DAT_253f2671008 + (int)uVar16;
      uVar18 = 0x104;
      if ((0x103 < uVar17) &&
         ((0x7ffffffd < uVar17 || (uVar18 = (uVar17 >> 2) + uVar17, 0x7ffffffd < uVar18)))) {
        uVar18 = 0x7ffffffe;
      }
      cVar7 = FUN_253f2620060(&local_88,uVar18);
      if (cVar7 != '\0') {
        if (uVar3 != 0) {
          lVar10 = local_84 + uVar16 * 2;
          if (uVar3 < 0x10) {
            uVar16 = 0;
          }
          else if (lVar10 - 0x253f267100cU < 0x20) {
            uVar16 = 0;
          }
          else {
            uVar22 = 0;
            uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
            do {
              uVar15 = *(undefined8 *)((longlong)literal_253f267100c + uVar22 + 8);
              *(undefined8 *)(lVar10 + uVar22) =
                   *(undefined8 *)((longlong)literal_253f267100c + uVar22);
              ((undefined8 *)(lVar10 + uVar22))[1] = uVar15;
              uVar22 = uVar22 + 0x10;
            } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
            if (uVar16 == uVar11) goto LAB_253f2624652;
          }
          do {
            *(wchar_t *)(lVar10 + uVar16 * 2) = literal_253f267100c[uVar16];
            uVar16 = uVar16 + 1;
          } while (uVar11 != uVar16);
        }
LAB_253f2624652:
        *(uint *)(local_84 + -4) = uVar17;
        *(undefined2 *)(local_84 + (ulonglong)uVar17 * 2) = 0;
        goto LAB_253f2624667;
      }
      goto LAB_253f26257c9;
    }
    uVar3 = *(uint *)(local_a4 + -4);
    uVar11 = (ulonglong)uVar3;
    if ((uVar3 == 0) && (local_74 != 0)) goto LAB_253f2624537;
    if (local_74 == 0) {
      uVar16 = 0;
      uVar18 = uVar3;
    }
    else {
      uVar16 = (ulonglong)*(uint *)(local_74 + -4);
      uVar18 = uVar3 + *(uint *)(local_74 + -4);
    }
    cVar7 = FUN_253f2620060(&local_78);
    if (cVar7 != '\0') {
      if (uVar3 != 0) {
        lVar12 = local_74 + uVar16 * 2;
        if (uVar3 < 0x10) {
          uVar16 = 0;
        }
        else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar22 = 0;
          uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
          do {
            uVar15 = ((undefined8 *)(lVar10 + uVar22))[1];
            *(undefined8 *)(lVar12 + uVar22) = *(undefined8 *)(lVar10 + uVar22);
            ((undefined8 *)(lVar12 + uVar22))[1] = uVar15;
            uVar22 = uVar22 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar16 == uVar11) goto LAB_253f2624522;
        }
        do {
          *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar11 != uVar16);
      }
LAB_253f2624522:
      *(uint *)(local_74 + -4) = uVar18;
      *(undefined2 *)(local_74 + (ulonglong)uVar18 * 2) = 0;
      goto LAB_253f2624537;
    }
  }
  else {
    DAT_253f2688270 = FUN_253f2626200();
    runtime_cast_to_string((void *)0x253ee076f88,DAT_253f2688270,0x54,&local_98);
    FUN_253f26205c0(&local_b8,&string_ref_253f266f248,0);
    lVar10 = local_94;
    if (local_94 == 0) {
LAB_253f2620f0a:
      in_R9 = 0x590008;
      MT5_Dispatch((void *)0x253ee076f88,2,1,0x590008);
      goto LAB_253f2620f2c;
    }
    uVar3 = *(uint *)(local_94 + -4);
    uVar11 = (ulonglong)uVar3;
    if ((uVar3 == 0) && (local_b4 != 0)) goto LAB_253f2620f0a;
    if (local_b4 == 0) {
      uVar16 = 0;
      uVar18 = uVar3;
    }
    else {
      uVar16 = (ulonglong)*(uint *)(local_b4 + -4);
      uVar18 = uVar3 + *(uint *)(local_b4 + -4);
    }
    cVar7 = FUN_253f2620060(&local_b8);
    if (cVar7 != '\0') {
      if (uVar3 != 0) {
        lVar12 = local_b4 + uVar16 * 2;
        if (uVar3 < 0x10) {
          uVar16 = 0;
        }
        else if ((ulonglong)(lVar12 - lVar10) < 0x20) {
          uVar16 = 0;
        }
        else {
          uVar22 = 0;
          uVar16 = (ulonglong)(uVar3 & 0xfffffff8);
          do {
            *(undefined1 (*) [16])(lVar12 + uVar22) = *(undefined1 (*) [16])(lVar10 + uVar22);
            uVar22 = uVar22 + 0x10;
          } while ((uVar11 * 2 & 0xfffffffffffffff0) != uVar22);
          if (uVar16 == uVar11) goto LAB_253f2620ef2;
        }
        do {
          *(undefined2 *)(lVar12 + uVar16 * 2) = *(undefined2 *)(lVar10 + uVar16 * 2);
          uVar16 = uVar16 + 1;
        } while (uVar11 != uVar16);
      }
LAB_253f2620ef2:
      *(uint *)(local_b4 + -4) = uVar18;
      *(undefined2 *)(local_b4 + (ulonglong)uVar18 * 2) = 0;
      goto LAB_253f2620f0a;
    }
LAB_253f26257e9:
    (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x180445000001f9);
LAB_253f2625809:
    (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x2b0450000001f9);
LAB_253f2625829:
    (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x180455000001f9);
LAB_253f2625849:
    (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x2e0462000001f9);
LAB_253f2625869:
    (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x3106a9000001f9);
  }
  (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x3106af000001f9);
LAB_253f26258a9:
  (*(code *)&runtime_memory_helper_3959a0)(0x253ee076f88,0x220668000001f9);
  pcVar4 = (code *)swi(3);
  uVar15 = (*pcVar4)();
  return uVar15;
}

