#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Taikhoan {
    char usernameDN[50];
    char passwordDN[50];
    int role;    
};

int chonvaitro()
{
    int a;
    printf("Ban muon tao tai khoan voi vai tro:\n1: BENH NHAN\n2: BAC SI\n3: QUAN LY\nHay nhap lua chon:");
    scanf("%d", &a);
    fflush(stdin);
    return a;
}

// lưu ý: khi để file text và file code khác thư mục, cần truyền thêm đường dẫn trực tiếp, VD: "D//VScode1//Project2//user.txt"

void TaoTK()
{
    printf("________________________________\n");
    printf("|         TAO TAI KHOAN        |\n");
    printf("________________________________\n");
    int vaitro;
    vaitro = chonvaitro();
    char usernameTaoTK[50], passwordTaoTK[50];
    printf("Nhap ten dang nhap: ");
    scanf("%s", usernameTaoTK);
    printf("Nhap mat khau: ");
    scanf("%s", passwordTaoTK);
    
    FILE *file = fopen("user.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s %d\n", usernameTaoTK, passwordTaoTK, vaitro);
        fclose(file);
        printf("____TAO TAI KHOAN THANH CONG____\n");
    } else {
        printf("Khong the mo tep ghi!\n");
    }
}

void suaTK() {
    printf("________________________________\n");
    printf("|         SUA TAI KHOAN        |\n");
    printf("________________________________\n");
    FILE *infile = fopen("user.txt", "r");
    FILE *outfile = fopen("temp.txt", "w");
    char taikhoan[50], matkhau[50], role[50], line[50];
    char TK[50], MK[50], VT[50];
    char search_line[50];
    int found = 0;
    printf("Vui long nhap tai khoan: ");
    scanf("%s", search_line);
    if (infile == NULL || outfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }
    while (fscanf(infile, "%s %s %s", taikhoan, matkhau, role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0) {
            printf("____DA TIM THAY TAI KHOAN CAN SUA____\n");
            printf("_____VUI LONG NHAP LAI THONG TIN_____\n");
            printf("Ten dang nhap: ");
            scanf("%s", TK);
            printf("Mat khau: ");
            scanf("%s", MK);
            printf("Vai tro: ");
            scanf("%s", VT);
            fgets(line, 50, infile); // to skip the remaining part of the line
            fprintf(outfile, "%s %s %s\n", TK, MK, VT);
            found = 1;
        } else {
            fprintf(outfile, "%s %s %s\n", taikhoan, matkhau, role);
        }
    }
    fclose(infile);
    fclose(outfile);
    if (found) {
        printf("____DA SUA TAI KHOAN THANH CONG____\n");
        remove("user.txt");
        rename("temp.txt", "user.txt");
    }
}

void xoaTK() {
    printf("________________________________\n");
    printf("|         XOA TAI KHOAN        |\n");
    printf("________________________________\n");
    FILE *file = fopen("user.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");
    char taikhoan[50], matkhau[50], role[50], line[50];
    char search_line[50];
    int found = 0;
    printf("Vui long nhap tai khoan: ");
    scanf("%s", search_line);
    if (file == NULL || tempfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }
    while (fscanf(file, "%s %s %s", taikhoan, matkhau, role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0) {
            fgets(line, 50, file); // to skip the remaining part of the line
            found = 1;
        } else {
            fprintf(tempfile, "%s %s %s\n", taikhoan, matkhau, role);
        }
    }
    fclose(file);
    fclose(tempfile);
    if (found) {
        remove("user.txt");
        rename("temp.txt", "user.txt");
        printf("____XOA TAI KHOAN %s THANH CONG____\n", search_line);
    } else {
        printf("____KHONG TIM THAY TAI KHOAN TREN____\n");
    }
}

int Dangnhap()
{
    char usernameDN[50], passwordDN[50];
    struct Taikhoan taikhoan[50];
    int count = 0;

    printf("Vui long nhap ten dang nhap: ");
    scanf("%s", usernameDN);
    printf("Vui long nhap mat khau: ");
    scanf("%s", passwordDN);

    FILE *file = fopen("user.txt", "r");
    if (file != NULL) {
        char fileUsernameDN[50], filePasswordDN[50];
        int role;
        while (fscanf(file, "%s %s %d", fileUsernameDN, filePasswordDN, &role) != EOF) {
            strcpy(taikhoan[count].usernameDN, fileUsernameDN);
            strcpy(taikhoan[count].passwordDN, filePasswordDN);
            taikhoan[count].role = role;
            count++;
        }
        fclose(file);

        for (int i = 0; i < count; i++) {
            if (strcmp(taikhoan[i].usernameDN, usernameDN) == 0 && strcmp(taikhoan[i].passwordDN, passwordDN) == 0) {
                return taikhoan[i].role;
            }
        }
    } else {
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
    return 0;
}
