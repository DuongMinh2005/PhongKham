#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tenDangNhap[100];
    char ten[50];
    int tuoi;
    char diachi[200];
    char loaiBenh[100];
    long vienPhi;
}BenhNhan;

void nhapThongTinBenhNhan(BenhNhan* nhap){
    printf(".______________________________.\n");
    printf("|   NHAP THONG TIN BENH NHAN   |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Ten dang nhap: ");
    gets(nhap->tenDangNhap);
    printf("Ten: ");
    gets(nhap->ten);
    printf("Tuoi: ");
    scanf("%d",&nhap->tuoi);
    printf("Dia chi: ");
    getchar();
    gets(nhap->diachi);
    printf("Loai benh: ");
    gets(nhap->loaiBenh);
    printf("Vien phi: ");
    scanf("%ld",&nhap->vienPhi);
    getchar();

    FILE *file = fopen ("thongtinbenhnhan.txt","a");
        if(file != NULL){
            fprintf(file,"Ten dang nhap: %s\n", nhap->tenDangNhap);
            fprintf(file, "Ten: %s\n", nhap->ten);
            fprintf(file, "Tuoi: %d\n", nhap->tuoi);
            fprintf(file, "Dia chi: %s\n", nhap->diachi);
            fprintf(file, "Loai benh: %s\n", nhap->loaiBenh);
            fprintf(file, "Vien phi: %ld\n", nhap->vienPhi);
            fprintf(file, "--------------------------------\n");
            fclose(file);
            printf("====NHAP THONG TIN THANH CONG====\n");
        }
        else {
            printf("___KHONG THE MO FILE THONG TIN___\n");
        }
}

void xoaThongTinBenhNhan(){
        char TenDangNhap[100];
        printf(".______________________________.\n");
        printf("|   XOA THONG TIN BENH NHAN    |\n");
        printf(".______________________________.\n");
        printf("Nhap ten tai khoan can xoa: \n");
        getchar();
        printf("Ten dang nhap: ");
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbenhnhan.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile == NULL || outfile == NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        int found=0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n", TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found = 1;
                for( int i=0; i<6; ++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if(found){
            remove("thongtinbenhnhan.txt");
            rename("tempt.txt","thongtinbenhnhan.txt");
            printf("====XOA THONG TIN BENH NHAN THANH CONG====\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN BENH NHAN____\n");
            remove("tempt.txt");
        }
}

void suaThongTinBenhNhan(){
        char TenDangNhap[100];
        BenhNhan nhap;
        printf(".______________________________.\n");
        printf("|    SUA THONG TIN BENH NHAN   |\n");
        printf(".______________________________.\n");
        printf("Vui long nhap ten dang nhap: ");
        getchar();
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbenhnhan.txt","r");
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
            if(strcmp(line, search_line) == 0){
                found = 1;
                printf("____NHAP LAI THONG TIN CHO BENH NHAN____\n");
                printf("Ten dang nhap: ");
                gets(nhap.tenDangNhap);
                printf("Ten: ");
                gets(nhap.ten);
                printf("Tuoi: ");
                scanf("%d",&nhap.tuoi);
                printf("Dia chi: ");
                getchar();
                gets(nhap.diachi);
                printf("Loai benh: ");
                gets(nhap.loaiBenh);
                printf("Vien phi: ");
                scanf("%ld",&nhap.vienPhi);

                fprintf(tempfile,"Ten dang nhap: %s\n", nhap.tenDangNhap);
                fprintf(tempfile, "Ten: %s\n", nhap.ten);
                fprintf(tempfile, "Tuoi: %d\n", nhap.tuoi);
                fprintf(tempfile, "Dia chi: %s\n", nhap.diachi);
                fprintf(tempfile, "Loai benh: %s\n", nhap.loaiBenh);
                fprintf(tempfile, "Vien phi: %ld\n", nhap.vienPhi);
                fprintf(tempfile, "--------------------------------\n");
                for( int i=0; i<6; ++i){
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
            remove("thongtinbenhnhan.txt");
            rename("tempt.txt","thongtinbenhnhan.txt");
            printf("====SUA THONG TIN BENH NHAN THANH CONG====\n");
        }
        else {
            printf("Khong tim thay thong tin benh nhan voi ten dang nhap: %s\n", TenDangNhap);
            remove("temp.txt");
        }
}

void timThongTinBenhNhan(){
    FILE* file = fopen("thongtinbenhnhan.txt","r");
    if(file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }

    char TenDangNhap[100];
    char line[256];
    char search_line[150];
    int found =0;
    printf(".______________________________.\n");
    printf("| TIM KIEM THONG TIN BENH NHAN |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Nhap ten dang nhap: ");
    gets(TenDangNhap);
    snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

    while(fgets(line,sizeof(line),file)){
        if(strcmp(line, search_line) == 0){
            found = 1;
            printf("%s", line);
            for ( int i = 0 ; i < 6; i++){
                if(fgets(line,sizeof(line),file))
                    printf("%s", line);
            }
            break;
        }
        else
        printf("____KHONG TIM THAY THONG BENH NHAN____\n");
    
    }
    fclose(file);
}

void inThongTinBenhNhan(){
    printf(".______________________________.\n");
    printf("|      DANH SACH BENH NHAN     |\n");
    printf(".______________________________.\n");
    FILE *file = fopen("thongtinbenhnhan.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN BENH NHAN____\n");
    }

    char line[256];

    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}

int main(){
    BenhNhan b1;
    // nhapThongTinBenhNhan(&b1);
    inThongTinBenhNhan();
    // xoaThongTinBenhNhan();
    // suaThongTinBenhNhan();
    timThongTinBenhNhan();
    // inThongTinBenhNhan();
}
