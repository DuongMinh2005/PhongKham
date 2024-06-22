#include <bits/stdc++.h>

struct Taikhoan {
    char usernameDN[50];
    char passwordDN[50];
    int role;    
};

int chonvaitro(){
    int a;
    printf("Ban muon tao tai khoan voi vai tro gi?\n1: Benh Nhan\n2: Bac Si\n3: Quan Li\n");
    scanf("%d", &a);fflush(stdin);
    return a;
}


void TaoTK(){
    printf(".______________________________.\n");
    printf("|         TAO TAI KHOAN        |\n");
    printf(".______________________________.\n");
    int vaitro;
    vaitro = chonvaitro();

    char usernameTaoTK[50]; 
    char passwordTaoTK[50]; 

    printf("Nhap ten dang nhap: ");
    fgets(usernameTaoTK, sizeof(usernameTaoTK), stdin);
    printf("Nhap mat khau: ");
    fgets(passwordTaoTK, sizeof(passwordTaoTK), stdin);

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
    printf(".______________________________.\n");
    printf("|         SUA TAI KHOAN        |\n");
    printf(".______________________________.\n");

    FILE *infile = fopen("user.txt", "r");
    FILE *outfile = fopen("temp.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        if (infile != NULL) fclose(infile);
        if (outfile != NULL) fclose(outfile);
        return;
    }

    char taikhoan[50], matkhau[50];
    int role;
    char TK[50], MK[50], VT[50];
    char search_line[50];
    int found = 0;

    printf("Vui long nhap tai khoan: ");
    fgets(search_line, sizeof(search_line), stdin);
    search_line[strcspn(search_line, "\n")] = '\0'; 

    while (fscanf(infile, "%s %s %d", taikhoan, matkhau, &role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0 && !found) {
            printf("____DA TIM THAY TAI KHOAN CAN SUA____\n");
            printf("____VUI LONG NHAP LAI THONG TIN____\n");

            printf("Ten dang nhap: ");
            fgets(TK, sizeof(TK), stdin);
            TK[strcspn(TK, "\n")] = '\0'; 
            printf("Mat khau: ");
            fgets(MK, sizeof(MK), stdin);
            MK[strcspn(MK, "\n")] = '\0'; 

            printf("Vai tro: ");
            fgets(VT, sizeof(VT), stdin);
            VT[strcspn(VT, "\n")] = '\0'; 

            fprintf(outfile, "%s %s %d\n", TK, MK, atoi(VT));
            found = 1;
        } else {
            fprintf(outfile, "%s %s %d\n", taikhoan, matkhau, role);
        }
    }

    fclose(infile);
    fclose(outfile);

    if (found) {
        printf("____DA SUA TAI KHOAN THANH CONG____\n");
        remove("user.txt");
        rename("temp.txt", "user.txt");
    } else {
        printf("____KHONG TIM THAY TAI KHOAN TREN____\n");
        remove("temp.txt"); 
    }
}



void xoaTK() {
    printf(".______________________________.\n");
    printf("|         XOA TAI KHOAN        |\n");
    printf(".______________________________.\n");

    FILE *file = fopen("user.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");

    if (file == NULL || tempfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }

    char taikhoan[50], matkhau[50], role[50];
    char search_line[50];
    bool found = false;

    printf("Vui long nhap tai khoan: ");
    fgets(search_line, sizeof(search_line), stdin);
    search_line[strcspn(search_line, "\n")] = '\0'; // loại bỏ kí tự newline

    while (fscanf(file, "%s %s %s", taikhoan, matkhau, role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0) {
            found = true;
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



int Dangnhap() {
    char usernameDN[50], passwordDN[50];
    struct Taikhoan taikhoan[100]; 
    int taikhoanCount = 0;

    printf("Vui long nhap ten dang nhap: ");
    fgets(usernameDN, sizeof(usernameDN), stdin);
    usernameDN[strcspn(usernameDN, "\n")] = '\0'; 

    printf("Vui long nhap mat khau: ");
    fgets(passwordDN, sizeof(passwordDN), stdin);
    passwordDN[strcspn(passwordDN, "\n")] = '\0'; 

    FILE *file = fopen("user.txt", "r");
    if (file != NULL) {
        char fileUsernameDN[50], filePasswordDN[50];
        int role;

        while (fscanf(file, "%s %s %d", fileUsernameDN, filePasswordDN, &role) != EOF) {
            strcpy(taikhoan[taikhoanCount].usernameDN, fileUsernameDN);
            strcpy(taikhoan[taikhoanCount].passwordDN, filePasswordDN);
            taikhoan[taikhoanCount].role = role;
            taikhoanCount++;
        }
        fclose(file);

        for (int i = 0; i < taikhoanCount; i++) {
            if (strcmp(taikhoan[i].usernameDN, usernameDN) == 0 && strcmp(taikhoan[i].passwordDN, passwordDN) == 0) {
                return taikhoan[i].role;
            }
        }
    } else {
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
    return 0;
}


struct Person {
    char tenDangNhap[50];
    char ten[50];
    int tuoi;
    char diachi[100];
};

void setTenDangNhap(struct Person *person, const char* tenDN) {
    strcpy(person->tenDangNhap, tenDN);
}

char* getTenDangNhap(struct Person *person) {
    return person->tenDangNhap;
}


int main(){
    TaoTK();
    // int role = Dangnhap();
    // if (role) {
    //     printf("Dang nhap thanh cong voi vai tro: %dSiuu\n", role);
    // } else {
    //     printf("Dang nhap that bai\n");
    // }
    // xoaTK();
    suaTK();
}

