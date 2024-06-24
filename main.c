#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>>

int main(){
    BenhNhan benhnhan;
    BacSi bacsi;
    KhoDuoc khoduoc;
    
menu:
        int a;
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.QUAN LY BENH NHAN\n");
        printf("2.QUAN LY NHA SI\n");
        printf("3.QUAN LY KHO DUOC\n");
        printf("4.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:
quanlibenhnhan:
                printf(".______________________________.\n");
                printf("|       QUAN LY BENH NHAN      |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN BENH NHAN\n");
                printf("2.XOA THONG TIN BENH NHAN\n");
                printf("3.SUA THONG TIN BENH NHAN\n");
                printf("4.TIM THONG TIN BENH NHAN\n");
                printf("5.XEM DANH SACH BENH NHAN\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int b;
                scanf("%d",&b);
                switch (b){
                    case 1:
                        nhapThongTinBenhNhan(&benhnhan);
                        break;
                    case 2:
                        xoaThongTinBenhNhan();
                        break;
                    case 3:
                        suaThongTinBenhNhan();
                        break;
                    case 4: 
                        timThongTinBenhNhan();
                        break;
                    case 5:
                        inDanhSachBN();
                        break;
                    case 6:
                        goto menu;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
            case 2:
quanlibacsi:
                printf(".______________________________.\n");
                printf("|        QUAN LY NHA SI        |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN NHA SI\n");
                printf("2.XOA THONG TIN NHA SI\n");
                printf("3.SUA THONG TIN NHA SI\n");
                printf("4.TIM THONG TIN NHA SI\n");
                printf("5.XEM DANH SACH NHA SI\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int c;
                scanf("%d",&c);
                switch (c){
                    case 1:
                        nhapThongTinBacSi(&bacsi);
                        break;
                    case 2:
                        xoaThongTinBacSi();
                        break;
                    case 3:
                        suaThongTinBacSi();
                        break;
                    case 4: 
                        timThongTinBacSi();
                        break;
                    case 5:
                        inDanhSachBS();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlibacsi;
                }
                goto quanlibacsi;
            case 3:
quanlikhoduoc:
                printf(".______________________________.\n");
                printf("|        QUAN LY KHO DUOC      |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN THUOC\n");
                printf("2.XOA THONG TIN THUOC\n");
                printf("3.SUA THONG TIN THUOC\n");
                printf("4.TIM THONG TIN THUOC\n");
                printf("5.XEM DANH SACH THUOC\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int e;
                scanf("%d",&e);
                switch (e){
                    case 1:
                        nhapThongTinThuoc(&khoduoc);
                        break;
                    case 2:
                        xoaThongTinThuoc();
                        break;
                    case 3:
                        suaThongTinThuoc();
                        break;
                    case 4: 
                        timThongTinThuoc();
                        break;
                    case 5:
                        inDanhSachTHUOC();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 4:
                printf("____DANG XUAT THANH CONG____\n");
                return 0;
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                printf("======VUI LONG CHON LAI======\n\n");
                goto menu;
        }
        return 0;
    }
    
