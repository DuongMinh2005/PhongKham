#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
            char masothuoc[100];
            char tenthuoc[100];
            char suatxu[100];
            char ngaysanxuat[100];
            char hansudung[100];
            char tacdung[100];
            int soluong;
            char dongia[100];
}KhoDuoc;


void nhapThongTinThuoc(KhoDuoc *thuoc){
            printf("____NHAP THONG TIN THUOC____\n");
            printf("Ma so thuoc: ");
            getchar();
            fgets(thuoc->masothuoc,sizeof(thuoc->masothuoc),stdin);
            printf("Ten thuoc: ");
            fgets(thuoc->tenthuoc, sizeof(thuoc->tenthuoc),stdin);
            printf("Noi san xuat: ");
            fgets(thuoc->suatxu, sizeof(thuoc->suatxu),stdin);
            printf("Ngay san xuat: ");
            fgets(thuoc->ngaysanxuat, sizeof(thuoc->ngaysanxuat), stdin);
            printf("Han su dung: ");
            fgets(thuoc->hansudung, sizeof(thuoc->hansudung),stdin);
            printf("Tac dung cua thuoc: ");
            fgets(thuoc->tacdung, sizeof(thuoc->tacdung),stdin);
            printf("So luong: ");
            scanf("%d",&thuoc->soluong);
            printf("Don gia: ");
            getchar();
            fgets(thuoc->dongia,sizeof(thuoc->dongia),stdin);

    FILE *file = fopen ("thongtinkhoduoc.txt","a");
        if(file != NULL){
            fprintf(file,"Ma so thuoc: %s", thuoc->masothuoc);
            fprintf(file, "Ten thuoc: %s", thuoc->tenthuoc);
            fprintf(file, "Noi san xuat: %s", thuoc->suatxu);
            fprintf(file, "Ngay san xuat: %s", thuoc->suatxu);
            fprintf(file, "Han su dung: %s", thuoc->hansudung);
            fprintf(file, "Tac dung cua thuoc: %s", thuoc->tacdung);
            fprintf(file, "So luong: %d\n", thuoc->soluong);
            fprintf(file, "Don gia: %s", thuoc->dongia);
            fprintf(file, "------------------------------------\n");\
            fclose(file);
            printf("____NHAP THONG TIN THANH CONG____\n");
        }
        else 
            printf("____KHONG THE MO FILE THONG TIN____\n");
}


void xoaThongTinThuoc(){
            char masothuoc[100];
            printf("____XOA THONG TIN THUOC____\n");
            printf("Nhap ma so thuoc: ");
            fflush(stdin);
            fgets(masothuoc,sizeof(masothuoc),stdin);

    FILE *infile = fopen("thongtinkhoduoc.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile ==NULL || outfile ==NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        int found=0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ma so thuoc: %s", masothuoc);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found =1;
                for( int i=0; i<8;++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if( found){
            remove("thongtinkhoduoc.txt");
            rename("tempt.txt","thongtinkhoduoc.txt");
            printf("____XOA THONG TIN THUOC THANH CONG____\n");
        }
        else{
            printf("____KHONG TIM THAY THONG TIN CAN XOA____\n");
            remove("tempt.txt");
        }
}


int suaThongTinThuoc(){
            char masothuoc[100];
            KhoDuoc thuoc;
            printf("____SUA THONG TIN THUOC____\n");
            printf("Vui long nhap ma so thuoc: ");
            getchar();
            fgets(masothuoc,sizeof(masothuoc),stdin);

        FILE *infile = fopen("thongtinkhoduoc.txt","r");
        FILE *tempfile = fopen("tempt.txt","w");
            if( infile ==NULL||tempfile == NULL ){
                printf("____KHONG THE MO FILE THONG TIN____\n");
                return 0;
            }
            char line[256];
            char search_line[150];
            int found =0;
            snprintf(search_line,sizeof(search_line),"Ma so thuoc: %s",masothuoc);

            while(fgets(line,sizeof(line),infile)){
                if(strcmp(line,search_line)==0){
                    found =1;
                    printf("____NHAP THONG TIN MOI____\n");
                    printf("Ma so thuoc: ");
                    getchar();
                    fgets(thuoc.masothuoc,sizeof(thuoc.masothuoc),stdin);
                    printf("Ten thuoc: ");
                    fgets(thuoc.tenthuoc, sizeof(thuoc.tenthuoc),stdin);
                    printf("Noi san xuat: ");
                    fgets(thuoc.suatxu,sizeof(thuoc.suatxu),stdin);
                    printf("Ngay san xuat: ");
                    fgets(thuoc.ngaysanxuat,sizeof(thuoc.ngaysanxuat),stdin);
                    printf("Han su dung: ");
                    fgets(thuoc.hansudung,sizeof(thuoc.hansudung),stdin);
                    printf("Tac dung:");
                    fgets(thuoc.tacdung,sizeof(thuoc.tacdung),stdin);
                    printf("So luong: ");
                    scanf("%d",&thuoc.soluong);
                    printf("Don gia: ");
                    getchar();
                    fgets(thuoc.dongia,sizeof(thuoc.dongia),stdin);

                    fprintf(tempfile,"Ma so thuoc: %s",thuoc.masothuoc);
                    fprintf(tempfile,"Ten thuoc: %s",thuoc.tenthuoc);
                    fprintf(tempfile,"Noi san xuat: %s",thuoc.suatxu);
                    fprintf(tempfile,"Ngay san xuat: %s",thuoc.ngaysanxuat);
                    fprintf(tempfile,"Han su dung: %s",thuoc.hansudung);
                    fprintf(tempfile,"Tac dung: %s",thuoc.tacdung);
                    fprintf(tempfile,"So luong; %d",thuoc.soluong);
                    fprintf(tempfile,"Don gia: %s",thuoc.dongia);

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
                remove("thongtinkhoduoc.txt");
                rename("tempt.txt","thongtinkhoduoc.txt");
                printf("____SUA THONG TIN THANH CONG____\n");
            }
            else{
                printf("Khong tim thay thong tin thuoc voi ma so: %s", masothuoc);
                remove("temp.txt");
            }

         return found;
}


void timThongTinThuoc(){
    FILE *file = fopen("thongtinkhoduoc.txt","r");
    if(file == NULL)
        printf("____KHONG THE MO FILE THONG TIN____\n");
    char masothuoc[256];
    char line[256];
    char search_line[150];
    int found =0;
    printf("____TIM KIEM THONG TIN THUOC____\n");
    printf("Nhap ma so thuoc: ");
    fflush(stdin);
    getchar();
    fgets(masothuoc,sizeof(masothuoc),stdin);
    snprintf(search_line, sizeof(search_line),"Ma so thuoc: %s",masothuoc);

    while(fgets(line,sizeof(line),stdin)){
        if(strcmp(line, search_line)==0){
            found =1;
            printf("%s", line);
            for ( int i =0 ; i<8;++i){
                if(fgets(line,sizeof(line),stdin))
                    printf("%s", line);
            }
            break;
        }
        
    }
    fclose(file);

    if (!found) 
        printf("____KHONG TIM THAY THONG TIN THUOC____\n");
}


void inDanhSachTHUOC(){
    printf(".______________________________.\n");
    printf("|        DANH SACH THUOC       |\n");
    printf(".______________________________.\n");
    FILE *file = fopen("thongtinkhoduoc.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
    char line[256];

    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}
int main(){
    KhoDuoc a;
    // nhapThongTinThuoc(&a);
    inDanhSachTHUOC();
    timThongTinThuoc();
    xoaThongTinThuoc();
}