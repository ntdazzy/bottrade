// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:26236
/* Address: 1715628ce40 */

void FUN_1715628ce40(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  int arg_1;
  longlong lVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined4 local_c0;
  longlong local_bc;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
  local_c0 = 0;
  local_bc = 0;
  arg_1 = MT5_PositionsTotal((void *)0x171514ca538);
  if (-1 < arg_1) {
    iVar1 = DAT_17156426ff0 + 2;
    lVar11 = (longlong)(DAT_17156426ff0 + 1);
    local_48 = (longlong)(DAT_17156426ff0 + 3);
    local_58 = (longlong)(DAT_17156426ff0 + 4);
    local_60 = (longlong)(DAT_17156426ff0 + 5);
    local_68 = (longlong)(DAT_17156426ff0 + 6);
    local_70 = (longlong)(DAT_17156426ff0 + 7);
    local_78 = (longlong)(DAT_17156426ff0 + 8);
    local_80 = (longlong)(DAT_17156426ff0 + 9);
    local_88 = (longlong)(DAT_17156426ff0 + 10);
    local_90 = (longlong)(DAT_17156426ff0 + 0xb);
    local_98 = (longlong)(DAT_17156426ff0 + 0xc);
    local_a0 = (longlong)(DAT_17156426ff0 + 0xd);
    local_b0 = (longlong)(DAT_17156426ff0 + 0xf);
    local_a8 = (longlong)(DAT_17156426ff0 + 0xe);
    local_50 = lVar11;
    do {
      DAT_171562c4838 = MT5_PositionGetTicket((void *)0x171514ca538,arg_1);
      if ((DAT_171562c4838 != 0) &&
         (((((((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == lVar11 ||
               (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == iVar1)) ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_48)) ||
             ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_58 ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_60)))) ||
            ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_68 ||
             ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_70 ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_78)))))) ||
           (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_80)) ||
          ((((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_88 ||
             (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_90)) ||
            (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_98)) ||
           (((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_a0 ||
             (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_a8)) ||
            (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_b0)))))))) {
        MT5_PositionGetString((void *)0x171514ca538,0);
        FUN_171562505c0(&local_c0,&DAT_17156426e3c,1,&PTR_DAT_171562b8fb0);
        if (local_bc == DAT_171562c495c) {
LAB_1715628cf80:
          lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,2);
          if (lVar8 == 0) {
            MT5_PositionGetDouble((void *)0x171514ca538,3);
            FUN_17156297d20(DAT_171562c4838);
          }
        }
        else if ((local_bc != 0) && (DAT_171562c495c != 0)) {
          uVar4 = *(uint *)(local_bc + -4);
          uVar5 = *(uint *)(DAT_171562c495c + -4);
          uVar7 = uVar5;
          if (uVar4 < uVar5) {
            uVar7 = uVar4;
          }
          iVar9 = uVar4 - uVar5;
          if (uVar7 != 0) {
            uVar10 = 1;
            do {
              uVar2 = *(ushort *)(local_bc + -2 + uVar10 * 2);
              uVar3 = *(ushort *)(DAT_171562c495c + -2 + uVar10 * 2);
              if (uVar7 <= uVar10) break;
              uVar10 = uVar10 + 1;
            } while (uVar2 == uVar3);
            lVar11 = local_50;
            if (uVar2 != uVar3) {
              iVar9 = (uint)uVar2 - (uint)uVar3;
            }
          }
          if (iVar9 == 0) goto LAB_1715628cf80;
        }
      }
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
  }
  FUN_17156250000(&local_c0);
  return;
}




// bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:26352
/* Address: 1715628d220 */

void FUN_1715628d220(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  int arg_1;
  longlong lVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined4 local_c0;
  longlong local_bc;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
  local_c0 = 0;
  local_bc = 0;
  arg_1 = MT5_PositionsTotal((void *)0x171514ca538);
  if (-1 < arg_1) {
    iVar1 = DAT_17156426ff0 + 2;
    lVar11 = (longlong)(DAT_17156426ff0 + 1);
    local_48 = (longlong)(DAT_17156426ff0 + 3);
    local_58 = (longlong)(DAT_17156426ff0 + 4);
    local_60 = (longlong)(DAT_17156426ff0 + 5);
    local_68 = (longlong)(DAT_17156426ff0 + 6);
    local_70 = (longlong)(DAT_17156426ff0 + 7);
    local_78 = (longlong)(DAT_17156426ff0 + 8);
    local_80 = (longlong)(DAT_17156426ff0 + 9);
    local_88 = (longlong)(DAT_17156426ff0 + 10);
    local_90 = (longlong)(DAT_17156426ff0 + 0xb);
    local_98 = (longlong)(DAT_17156426ff0 + 0xc);
    local_a0 = (longlong)(DAT_17156426ff0 + 0xd);
    local_b0 = (longlong)(DAT_17156426ff0 + 0xf);
    local_a8 = (longlong)(DAT_17156426ff0 + 0xe);
    local_50 = lVar11;
    do {
      DAT_171562c4838 = MT5_PositionGetTicket((void *)0x171514ca538,arg_1);
      if ((DAT_171562c4838 != 0) &&
         (((((((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == lVar11 ||
               (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == iVar1)) ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_48)) ||
             ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_58 ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_60)))) ||
            ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_68 ||
             ((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_70 ||
              (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_78)))))) ||
           (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_80)) ||
          ((((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_88 ||
             (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_90)) ||
            (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_98)) ||
           (((lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_a0 ||
             (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_a8)) ||
            (lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,0xc), lVar8 == local_b0)))))))) {
        MT5_PositionGetString((void *)0x171514ca538,0);
        FUN_171562505c0(&local_c0,&DAT_17156426e3c,1,&PTR_DAT_171562b8fc0);
        if (local_bc == DAT_171562c495c) {
LAB_1715628d586:
          lVar8 = MT5_PositionGetInteger((void *)0x171514ca538,2);
          if (lVar8 == 1) {
            MT5_PositionGetDouble((void *)0x171514ca538,3);
            FUN_17156297d20(DAT_171562c4838);
          }
        }
        else if ((local_bc != 0) && (DAT_171562c495c != 0)) {
          uVar4 = *(uint *)(local_bc + -4);
          uVar5 = *(uint *)(DAT_171562c495c + -4);
          uVar7 = uVar5;
          if (uVar4 < uVar5) {
            uVar7 = uVar4;
          }
          iVar9 = uVar4 - uVar5;
          if (uVar7 != 0) {
            uVar10 = 1;
            do {
              uVar2 = *(ushort *)(local_bc + -2 + uVar10 * 2);
              uVar3 = *(ushort *)(DAT_171562c495c + -2 + uVar10 * 2);
              if (uVar7 <= uVar10) break;
              uVar10 = uVar10 + 1;
            } while (uVar2 == uVar3);
            lVar11 = local_50;
            if (uVar2 != uVar3) {
              iVar9 = (uint)uVar2 - (uint)uVar3;
            }
          }
          if (iVar9 == 0) goto LAB_1715628d586;
        }
      }
      bVar6 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar6);
  }
  FUN_17156250000(&local_c0);
  return;
}



