#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tenDangNhap[100];
    char tenBacSi[50];
    int tuoi;
    long maso;
    char diachi[200];
    char chucvu[100];
    char chuyenkhoa[100];
    int kinhnghiem;
}BacSi;

void NhapThongTinBacSi(BacSi* nhap){
        printf("____NHAP THONG TIN BAC SI____\n");
        printf("Ten dang nhap: ");
        //getchar();
        gets(nhap->tenDangNhap);
        printf("Ten: ");
        gets(nhap->tenBacSi);
        printf("Tuoi: ");
        scanf("%d",&nhap->tuoi);
        printf("Ma so: ");
        scanf("%ld",&nhap->maso);
        getchar();
        printf("Dia chi: ");
        gets(nhap->diachi);
        printf("Chuc vu: ");
        gets(nhap->chucvu);
        printf("Chuyen khoa: ");
        gets(nhap->chuyenkhoa);
        fflush(stdin);
        printf("Kinh nghiem: ");
        scanf("%d",&nhap->kinhnghiem);
        getchar();

    FILE *file = fopen ("thongtinbacsi.txt","a");
        if(file != NULL){
            fprintf(file,"Ten dang nhap: %s\n", nhap->tenDangNhap);
            fprintf(file, "Ten: %s\n", nhap->tenBacSi);
            fprintf(file, "Tuoi: %d\n", nhap->tuoi);
            fprintf(file, "Ma so: %ld\n", nhap->maso);
            fprintf(file, "Dia chi: %s\n", nhap->diachi);
            fprintf(file, "Chuc vu: %s\n", nhap->chucvu);
            fprintf(file, "Chuyen khoa: %s\n", nhap->chuyenkhoa);
            fprintf(file, "Tuoi: %d\n", nhap->kinhnghiem);
            fprintf(file, "------------------------------------\n");
            fclose(file);
            printf("____NHAP THONG TIN BAC SI THANH CONG____\n");
        }
        else {
            printf("____KHONG THE MO FILE THONG TIN BAC SI____\n");
        }
}

void xoaThongTinBacSi(){
        char TenDangNhap[100];
        printf("____XOA THONG TIN BAC SI____\n");
        printf("Nhap ten tai khoan can xoa: \n");
        printf("Ten dang nhap: ");
        getchar();
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbasi.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile == NULL || outfile == NULL){
            printf("____KHONG THE MO FILE THONG TIN BAC SI____\n");
            return;
        }
        char line[256];
        int found = 0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n", TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found = 1;
                for( int i = 0; i < 8; ++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if(found){
            remove("thongtinbacsi.txt");
            rename("tempt.txt","thongtinbacsi.txt");
            printf("____XOA THONG TIN BAC SI THANH CONG____\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN BAC SI CAN XOA____\n");
            remove("tempt.txt");
        }
}

void suaThongTinBacSi(){
        char TenDangNhap[100];
        BacSi nhap;
        printf("____SUA THONG TIN BAC SI____\n");
        printf("Vui long nhap ten dang nhap: ");
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbacsi.txt","r");
    FILE *tempfile = fopen("tempt.txt","w");
        if( infile == NULL || tempfile == NULL ){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        char search_line[150];
        int found = 0; //flag
        snprintf(search_line,sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line,search_line) == 0){
                found = 1;
                printf("____NHAP LAI THONG TIN CHO BAC SI____\n");
                printf("Ten dang nhap: ");
                gets(nhap.tenDangNhap);
                printf("Ten: ");
                gets(nhap.tenBacSi);
                printf("Tuoi: ");
                scanf("%d",&nhap.tuoi);
                printf("Ma so: ");
                scanf("%ld",&nhap.maso);
                getchar();
                printf("Dia chi: ");
                gets(nhap.diachi);
                printf("Chuc vu: ");
                gets(nhap.chucvu);
                printf("Chuyen khoa: ");
                gets(nhap.chuyenkhoa);
                printf("Kinh nghiem: ");
                scanf("%d",&nhap.kinhnghiem);

                fprintf(tempfile,"Ten dang nhap: %s\n", nhap.tenDangNhap);
                fprintf(tempfile, "Ten: %s\n", nhap.tenBacSi);
                fprintf(tempfile, "Tuoi: %d\n", nhap.tuoi);
                fprintf(tempfile, "Ma so: %ld\n", nhap.maso);
                fprintf(tempfile, "Dia chi: %s\n", nhap.diachi);
                fprintf(tempfile, "Chuc vu: %s\n", nhap.chucvu);
                fprintf(tempfile, "Chuyen khoa: %s\n", nhap.chuyenkhoa);
                fprintf(tempfile, "Kinh nghiem: %d\n", nhap.kinhnghiem);
                fprintf(tempfile, "------------------------------------\n");

                for( int i=0; i<8; ++i){
                    fgets(line, sizeof(line),infile);
                }
            }
            else{
                fputs(line,tempfile);
            }
        }
        fclose(infile);
        fclose(tempfile);
        if(found){
            remove("thongtinbacsi.txt");
            rename("tempt.txt","thongtinbacsi.txt");
            printf("____SUA THONG TIN BAC SI THANH CONG____\n");
        }
        else{
            printf("Khong tim thay thong tin bac si voi ten dang nhap: %s\n", TenDangNhap);
            remove("temp.txt");
        }
}

void timThongTinBacSi(){
    FILE* file = fopen("thongtinbacsi.txt","a");
    if(file == NULL){
        printf("____KHONG THE MO FILE THONG TIN BAC SI____\n");
    }

    char TenDangNhap[100];
    char line[256];
    char search_line[150];
    int found = 0;
    printf("____TIM KIEM THONG TIN BAC SI____\n");
    printf("Nhap ten dang nhap: ");
    getchar();
    gets(TenDangNhap);
    snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

    while(fgets(line,sizeof(line),stdin)){
        if(strcmp(line, search_line) == 0){
            found = 1;
            printf("%s", line);
            for ( int i = 0 ; i < 8; i++){
                if(fgets(line,sizeof(line),stdin))
                    printf("%s", line);
            }
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("____KHONG TIM THAY THONG BAC SI____\n");
    }
}

void inThongTinBacSi(){
    printf("________________________________\n");
    printf("|        DANH SACH BAC SI       |\n");
    printf("________________________________\n");
    FILE *file = fopen("thongtinbacsi.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN BAC SI____\n");
    }

    char line[256];
    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}

int main(){
    BacSi b1,b2,b3;
    // NhapThongTinBacSi(&b1);
    // NhapThongTinBacSi(&b2);
    // NhapThongTinBacSi(&b3);
    inThongTinBacSi();
    // suaThongTinBacSi();
    timThongTinBacSi();
}
