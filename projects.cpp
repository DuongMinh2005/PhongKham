#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to hold patient information
typedef struct {
    char tenDangNhap[100];
    char ten[100];
    int tuoi;
    char diachi[200];
    char loaiBenh[200];
    float vienPhi;
} BenhNhan;

// Function prototypes
void nhapThongTinBenhNhan();
void xoaThongTinBenhNhan();
void suaThongTinBenhNhan();
void timThongTinBenhNhan();
void inDanhSachBN();
void inDanhSachTHUOC();

void nhapThongTinBenhNhan() {
    FILE *file = fopen("thongtinbenhnhan.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file de ghi thong tin benh nhan.\n");
        return;
    }

    BenhNhan bn;
    printf("Nhap ten dang nhap: ");
    scanf("%s", bn.tenDangNhap);
    printf("Nhap ten: ");
    scanf("%s", bn.ten);
    printf("Nhap tuoi: ");
    scanf("%d", &bn.tuoi);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", bn.diachi);
    printf("Nhap loai benh: ");
    scanf(" %[^\n]", bn.loaiBenh);
    printf("Nhap vien phi: ");
    scanf("%f", &bn.vienPhi);

    fprintf(file, "Ten dang nhap: %s\n", bn.tenDangNhap);
    fprintf(file, "Ten: %s\n", bn.ten);
    fprintf(file, "Tuoi: %d\n", bn.tuoi);
    fprintf(file, "Dia chi: %s\n", bn.diachi);
    fprintf(file, "Loai benh: %s\n", bn.loaiBenh);
    fprintf(file, "Vien phi: %.2f\n", bn.vienPhi);
    fprintf(file, "--------------------------------------\n");

    fclose(file);
    printf("Thong tin benh nhan da duoc nhap.\n");
}

void xoaThongTinBenhNhan() {
    char tenDangNhap[100];
    printf("Nhap ten dang nhap cua benh nhan can xoa: ");
    scanf("%s", tenDangNhap);

    FILE *file = fopen("thongtinbenhnhan.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Loi mo file de xoa thong tin.\n");
        return;
    }

    char line[256];
    bool found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, tenDangNhap) != NULL) {
            found = true;
            for (int i = 0; i < 6; ++i) {
                fgets(line, sizeof(line), file); // Bo qua cac dong khac
            }
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("thongtinbenhnhan.txt");
        rename("temp.txt", "thongtinbenhnhan.txt");
        printf("Thong tin benh nhan da duoc xoa.\n");
    } else {
        printf("Khong tim thay benh nhan voi ten dang nhap: %s\n", tenDangNhap);
        remove("temp.txt");
    }
}

void suaThongTinBenhNhan() {
    char tenDangNhap[100];
    printf("Nhap ten dang nhap cua benh nhan can sua: ");
    scanf("%s", tenDangNhap);

    FILE *file = fopen("thongtinbenhnhan.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Loi mo file de sua thong tin.\n");
        return;
    }

    char line[256];
    bool found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, tenDangNhap) != NULL) {
            printf("Nhap thong tin moi cho benh nhan:\n");

            BenhNhan bn;
            printf("Nhap ten dang nhap: ");
            scanf("%s", bn.tenDangNhap);
            printf("Nhap ten: ");
            scanf("%s", bn.ten);
            printf("Nhap tuoi: ");
            scanf("%d", &bn.tuoi);
            printf("Nhap dia chi: ");
            scanf(" %[^\n]", bn.diachi);
            printf("Nhap loai benh: ");
            scanf(" %[^\n]", bn.loaiBenh);
            printf("Nhap vien phi: ");
            scanf("%f", &bn.vienPhi);

            fprintf(tempFile, "Ten dang nhap: %s\n", bn.tenDangNhap);
            fprintf(tempFile, "Ten: %s\n", bn.ten);
            fprintf(tempFile, "Tuoi: %d\n", bn.tuoi);
            fprintf(tempFile, "Dia chi: %s\n", bn.diachi);
            fprintf(tempFile, "Loai benh: %s\n", bn.loaiBenh);
            fprintf(tempFile, "Vien phi: %.2f\n", bn.vienPhi);
            fprintf(tempFile, "--------------------------------------\n");

            found = true;

            for (int i = 0; i < 6; ++i) {
                fgets(line, sizeof(line), file); // Bo qua cac dong cu
            }
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("thongtinbenhnhan.txt");
        rename("temp.txt", "thongtinbenhnhan.txt");
        printf("Thong tin benh nhan da duoc sua thanh cong.\n");
    } else {
        printf("Khong tim thay benh nhan voi ten dang nhap: %s\n", tenDangNhap);
        remove("temp.txt");
    }
}

void timThongTinBenhNhan() {
    char search_line[100];
    printf("Nhap ten dang nhap: ");
    scanf("%s", search_line);

    FILE *file = fopen("thongtinbenhnhan.txt", "r");

    if (file == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }

    char line[256];
    bool found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search_line) != NULL) {
            for (int i = 0; i < 6; ++i) {
                fgets(line, sizeof(line), file);
                printf("%s", line);
            }
            found = true;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Khong tim thay benh nhan voi ten dang nhap: %s\n", search_line);
    }
}

void inDanhSachBN() {
    FILE *file = fopen("thongtinbenhnhan.txt", "r");

    if (file == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }

    char line[256];
    printf("____DANH SACH BENH NHAN____\n");

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void inDanhSachTHUOC() {
    // Function to print medicine list (not provided in original code)
}

int main() {
    int choice;
    while (1) {
        printf("________________________________\n");
        printf("|       QUAN LY BENH NHAN      |\n");
        printf("________________________________\n");
        printf("1. NHAP THONG TIN BENH NHAN\n");
        printf("2. XOA THONG TIN BENH NHAN\n");
        printf("3. SUA THONG TIN BENH NHAN\n");
        printf("4. TIM THONG TIN BENH NHAN\n");
        printf("5. XEM DANH SACH BENH NHAN\n");
        printf("6. THOAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d", &choice);

        switch (choice) {
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
                exit(0);
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                printf("VUI LONG CHON LAI\n");
                break;
        }
    }

    return 0;
}
