// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:19915
/* Address: 23e5aa3fa00 */

void FUN_23e5aa3fa00(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  int arg_1;
  longlong lVar9;
  int iVar10;
  ulonglong uVar11;
  undefined4 local_80;
  longlong local_7c;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
  local_80 = 0;
  local_7c = 0;
  arg_1 = MT5_PositionsTotal((void *)0x23e575eae78);
  if (-1 < arg_1) {
    iVar1 = DAT_23e5aa7a610 + 1;
    iVar2 = DAT_23e5aa7a610 + 2;
    local_48 = (longlong)(DAT_23e5aa7a610 + 3);
    local_50 = (longlong)(DAT_23e5aa7a610 + 4);
    local_58 = (longlong)(DAT_23e5aa7a610 + 5);
    local_60 = (longlong)(DAT_23e5aa7a610 + 6);
    local_70 = (longlong)(DAT_23e5aa7a610 + 8);
    local_68 = (longlong)(DAT_23e5aa7a610 + 7);
    do {
      DAT_23e5aa777f8 = MT5_PositionGetTicket((void *)0x23e575eae78,arg_1);
      if ((DAT_23e5aa777f8 != 0) &&
         (((((lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == iVar1 ||
             (lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == iVar2)) ||
            (lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_48)) ||
           ((lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_50 ||
            (lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_58)))) ||
          ((lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_60 ||
           ((lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_68 ||
            (lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc), lVar9 == local_70)))))))) {
        MT5_PositionGetString((void *)0x23e575eae78,0);
        FUN_23e5aa105c0(&local_80,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ec20);
        if (local_7c == DAT_23e5aa7791c) {
LAB_23e5aa3fae0:
          lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,2);
          if (lVar9 == 0) {
            MT5_PositionGetDouble((void *)0x23e575eae78,3);
            FUN_23e5aa4d010(DAT_23e5aa777f8);
          }
        }
        else if ((local_7c != 0) && (DAT_23e5aa7791c != 0)) {
          uVar5 = *(uint *)(local_7c + -4);
          uVar6 = *(uint *)(DAT_23e5aa7791c + -4);
          uVar8 = uVar6;
          if (uVar5 < uVar6) {
            uVar8 = uVar5;
          }
          iVar10 = uVar5 - uVar6;
          if (uVar8 != 0) {
            uVar11 = 1;
            do {
              uVar3 = *(ushort *)(local_7c + -2 + uVar11 * 2);
              uVar4 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar11 * 2);
              if (uVar8 <= uVar11) break;
              uVar11 = uVar11 + 1;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar10 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar10 == 0) goto LAB_23e5aa3fae0;
        }
      }
      bVar7 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar7);
  }
  FUN_23e5aa10000(&local_80);
  return;
}




// bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:20007
/* Address: 23e5aa3fce0 */

void FUN_23e5aa3fce0(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  int arg_1;
  longlong lVar9;
  int iVar10;
  ulonglong uVar11;
  undefined4 local_80;
  longlong local_7c;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
  local_80 = 0;
  local_7c = 0;
  arg_1 = MT5_PositionsTotal((void *)0x23e575eae78);
  if (-1 < arg_1) {
    iVar1 = DAT_23e5aa7a610 + 1;
    iVar2 = DAT_23e5aa7a610 + 2;
    local_48 = (longlong)(DAT_23e5aa7a610 + 3);
    local_50 = (longlong)(DAT_23e5aa7a610 + 4);
    local_58 = (longlong)(DAT_23e5aa7a610 + 5);
    local_60 = (longlong)(DAT_23e5aa7a610 + 6);
    local_70 = (longlong)(DAT_23e5aa7a610 + 8);
    local_68 = (longlong)(DAT_23e5aa7a610 + 7);
    do {
      DAT_23e5aa777f8 = MT5_PositionGetTicket((void *)0x23e575eae78,arg_1);
      if (DAT_23e5aa777f8 != 0) {
        lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
        if (lVar9 != iVar1) {
          lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
          if (lVar9 != iVar2) {
            lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
            if (lVar9 != local_48) {
              lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
              if (lVar9 != local_50) {
                lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
                if (lVar9 != local_58) {
                  lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
                  if (lVar9 != local_60) {
                    lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
                    if (lVar9 != local_68) {
                      lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,0xc);
                      if (lVar9 != local_70) goto LAB_23e5aa3fdc0;
                    }
                  }
                }
              }
            }
          }
        }
        MT5_PositionGetString((void *)0x23e575eae78,0);
        FUN_23e5aa105c0(&local_80,&DAT_23e5aa7a43c,1,&PTR_DAT_23e5aa6ec30);
        if (local_7c == DAT_23e5aa7791c) {
LAB_23e5aa3ff48:
          lVar9 = MT5_PositionGetInteger((void *)0x23e575eae78,2);
          if (lVar9 == 1) {
            MT5_PositionGetDouble((void *)0x23e575eae78,3);
            FUN_23e5aa4d010(DAT_23e5aa777f8);
          }
        }
        else if ((local_7c != 0) && (DAT_23e5aa7791c != 0)) {
          uVar5 = *(uint *)(local_7c + -4);
          uVar6 = *(uint *)(DAT_23e5aa7791c + -4);
          uVar8 = uVar6;
          if (uVar5 < uVar6) {
            uVar8 = uVar5;
          }
          iVar10 = uVar5 - uVar6;
          if (uVar8 != 0) {
            uVar11 = 1;
            do {
              uVar3 = *(ushort *)(local_7c + -2 + uVar11 * 2);
              uVar4 = *(ushort *)(DAT_23e5aa7791c + -2 + uVar11 * 2);
              if (uVar8 <= uVar11) break;
              uVar11 = uVar11 + 1;
            } while (uVar3 == uVar4);
            if (uVar3 != uVar4) {
              iVar10 = (uint)uVar3 - (uint)uVar4;
            }
          }
          if (iVar10 == 0) goto LAB_23e5aa3ff48;
        }
      }
LAB_23e5aa3fdc0:
      bVar7 = 0 < arg_1;
      arg_1 = arg_1 + -1;
    } while (bVar7);
  }
  FUN_23e5aa10000(&local_80);
  return;
}



