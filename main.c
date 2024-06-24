#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>>

int main(){
    BenhNhan benhnhan;
    BacSi bacsi;
    KhoDuoc khoduoc;
    
    {
menu:
        int a;
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.QUAN LY TAI KHOAN\n");
        printf("2.QUAN LY BENH NHAN\n");
        printf("3.QUAN LY NHA SI\n");
        printf("4.QUAN LY KHO DUOC\n");
        printf("5.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:
quanlitaikhoan:
                printf(".______________________________.\n");
                printf("|       QUAN LY TAI KHOAN      |\n");
                printf(".______________________________.\n");
                printf("1.TAO TAI KHOAN\n");
                printf("2.XOA TAI KHOAN\n");
                printf("3.SUA TAI KHOAN\n");
                printf("4.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int d;
                scanf("%d",&d);
                switch (d) {
                    case 1:
                        TaoTK();
                        break;
                    case 2:
                        xoaTK();
                        break;
                    case 3:
                        suaTK();
                        break;
                    case 4:
                        goto menu;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlitaikhoan;
                        break;
                }
                goto quanlitaikhoan;
            case 2:
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
                        nhapThongTinBenhNhan();
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
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
            case 3:
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
                        nhapThongTinBacSi();
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
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibacsi;
                }
                goto quanlibacsi;
            case 4:
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
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 5:
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                goto menu;
                break;
        }
    }
    return 0;
} 