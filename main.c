#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>>

// struct Person {
//     char tenDangNhap[50];
//     char ten[50];
//     int tuoi;
//     char diachi[100];
// };
// void setTenDangNhap(struct Person *person, const char* tenDN) {
//     strcpy(person->tenDangNhap, tenDN);
// }
// char* getTenDangNhap(struct Person *person) {
//     return person->tenDangNhap;
// }

int main(){
    int role;
    // BenhNhan benhnhan;
    // BacSi bacsi;
    // KhoDuoc khoduoc;
    char usernameDN;
    char passwordDN;
    int vaitro;
    printf(".________________________________.\n");
    printf("|             LOGIN              |\n");
    printf(".________________________________.\n");
    int choice = 0;
    printf("Da co tai khoan? : nhap 1\nChua co tai khoan? : nhap 0\n");
    scanf("%d",&choice);
    if(choice==0)
        TaoTK();
tryagain:
    printf("Vui long nhap ten dang nhap: \n");
    scanf("%s",&usernameDN);
    printf("Vui long nhap mat khau: \n");
    scanf("%s",&passwordDN);
    
    FILE *file = fopen("user.txt", "r");
    if (file != NULL) {
        char fileUsernameDN[100], filePasswordDN[100];
        int vaitro;
        while (fscanf(file,"%s %s %d", fileUsernameDN, filePasswordDN, &vaitro) != EOF) {
            if (strcmp(usernameDN, fileUsernameDN) == 0 && strcmp(passwordDN, filePasswordDN) == 0) {
                role = vaitro;
                fclose(file);
            }
        }
    } else
        printf( "____KHONG THE MO FILE THONG TIN____\n");
    switch (role) 
    {
        case 1: 
            printf("____DANG NHAP THANH CONG VOI VAI TRO BENH NHAN____\n\n");
            break;
        case 2:
            printf("____DANG NHAP THANH CONG VOI VAI TRO NHA SI____\n\n");
            break;
        case 3: 
            printf("____DANG NHAP THANH CONG VOI VAI TRO QUAN LI____\n\n");
            break;
        default: 
            printf("____TAI KHOAN MAT KHAU KHONG CHINH XAC____\n____VUI LONG DANG NHAP LAI____\n\n");
            goto tryagain;
    };
    if (role==3)
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
                usernameDN = "";
                passwordDN = "";
                role=0;
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                goto menu;
                break;
        }
    }
    if (role == 1){
menu2:
        int a;
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.XEM THONG TIN CA NHAN\n");
        printf("2.DOI MAT KHAU\n");
        printf("3.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:

                char line[50];
                FILE *file = fopen("thongtinbenhnhan.txt", "r");
                if (!file) {
                printf("____KHONG THE MO FILE THONG TIN____\n");
                }

                while (fgets(line, sizeof(line), file)) {
                    line[strcspn(line, "\n")] = 0; // Xóa ký tự newline ở cuối dòng
                    if (strncmp(line, "Ten dang nhap: ", 15) == 0 && strcmp(line + 15, usernameDN) == 0) {
                    printf("____THONG TIN CA NHAN____\n");
                    for (int i = 0; i < 6; i++) {
                        if (fgets(line, sizeof(line), file))
                        printf("%s", line);
                    }
                    } else 
                        printf("____THONG TIN BENH NHAN KHONG TON TAI____\n");
                }
                fclose(file);
                break;
            case 2:
                doiMK();
                usernameDN = "";
                passwordDN = "";
                role=0;
                goto tryagain;
                break;
            case 3:
                usernameDN="";
                passwordDN="";
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
                break;
            
        }goto menu2;
    }
    if (role == 2)
    {
menu3:
        int a;
        printf("._____________________________.\n");
        printf("|            MENU             |\n");
        printf("._____________________________.\n");
        printf("1.QUAN LI THONG TIN CA NHAN\n");
        printf("2.QUAN LI BENH NHAN\n");
        printf("3.XEM DANH SACH THUOC\n");
        printf("4.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:{
                printf(".______________________________.\n");
                printf("|  QUAN LI THONG TIN CA NHAN   |\n");
                printf(".______________________________.\n");
                printf("1.XEM THONG TIN CA NHAN\n");
                printf("2.DOI MAT KHAU\n");
                printf("3.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int b;
                scanf("%d",&b);
                switch (b) {
                    case 1:
                        char line[50];
                        FILE *file = fopen("thongtinbacsi.txt", "r");
                        if (!file) 
                            printf("____KHONG THE MO FILE THONG TIN____\n");

                        while (fgets(line, sizeof(line), file)) {
                            line[strcspn(line, "\n")] = 0; // Xóa ký tự newline ở cuối dòng
                            if (strncmp(line, "Ten dang nhap: ", 15) == 0 && strcmp(line + 15, usernameDN) == 0) {
                                printf("____THONG TIN CA NHAN____\n");
                            for (int i = 0; i < 8; i++) {
                                if (fgets(line, sizeof(line), file))
                                    printf("%s", line);
                                }
                            } else {
                                printf("____THONG TIN NHA SI KHONG TON TAI____\n");
                                printf("Bam ENTER de quay lai Menu\n");
                                int input = getchar();
                                if (input == '\n')
                                    goto menu3;
                            }
                        }
                        fclose(file);
                        break;
                    case 2:
                        doiMK();
                        usernameDN = "";
                        passwordDN = "";
                        role=0;
                        goto tryagain;
                        break;
                    case 3:
                        goto menu3;
                        break;
                    default :
                        printf("____CHUC NANG KHONG PHU HOP____\n");
                        goto menu3;
                }
                goto menu3;
            }
            case 2:
quanlibenhnhan2:
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
                        goto menu3;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibenhnhan;
                }
                goto quanlibenhnhan2;
                break;
            case 3: 
                inDanhSachTHUOC();
                goto menu2;
            case 4:
                usernameDN="";
                passwordDN="";
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
            default :
                printf("____CHUC NANG KHONG PHU HOP____\n");
                goto menu2;
        }
    }
    return 0;
}; 