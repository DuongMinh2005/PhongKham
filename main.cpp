#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//tệp khách hàng
typedef struct
{
    int tuoi;
    char ten[50];
    char que[100];
    char tinh_trang[200];
}tepkhachhang;
typedef struct 
{
    int ngay;
    int thang;
    int nam;
}lich;
//hàm nhập lựa chọn
int nhapluachon(){
    int n;
    scanf("%d", &n);
    return n;
}

//hàm nhập thông tin người dùng
void nhapthongtin(tepkhachhang* a) {
    printf("Nhap ten: ");
    scanf(" %[^\n]", a->ten); 
    printf("Nhap que: ");
    scanf(" %[^\n]", a->que); 
    printf("Nhap tuoi: ");
    scanf("%d", &a->tuoi); 
}

//hàm xuất thông tin khách hàng
void xuatten(tepkhachhang a) {
    printf("Ten: %s\n", a.ten); 
    printf("Que: %s\n", a.que); 
    printf("Tuoi: %d\n", a.tuoi); 
}
//hàm đặt lịch
void datlich(){
    lich l1;
    printf("Dat lich kham: \n");
    scanf("%d%d%d",&l1.ngay,&l1.thang,&l1.nam);
    printf("Lich da dat la: %d/%d/%d",l1.ngay,l1.thang,l1.nam);
}


int main(){

    tepkhachhang khach;
    nhapthongtin(&khach); //test
    xuatten(khach); //test
    
//option 1: bạn là ai?

int n, k;
BACK1: 
    printf("Ban la ai: \nVui long nhap chinh xac theo yeu cau: \nNha si: nhap 1\nBenh nhan: nhap 2\n");
    k=nhapluachon();
    if(k!=1 && k!=2){
        printf("vui long nhap lai:\n");
        goto BACK1;


switch (k){
case 1://bạn là nha sĩ
    //option 2: bạn muốn thực hiện điềus gì
    BACK2:
    printf("*----------------------------------------------------------------------------------*\n");
    printf("|                       NHA KHOA CR7 XIN CHAO QUY KHACH !                          |\n");
    printf("|                                                                                  |\n");
    printf("|  BAN MUON THUC HIEN DIEU GI?                                                     |\n");
    printf("|  1.Them thong tin benh nhan                                                      |\n");
    printf("|  2.Them thong tin nhan vien                                                      |\n");
    printf("|  3.Them luong cho nhan vien                                                      |\n");
    printf("|  4.Sua thong tin cho benh nhan                                                   |\n");
    printf("|  5.Sua thong tin cho nhan vien                                                   |\n");
    printf("|  6.Xoa thong tin benh nhan                                                       |\n");
    printf("|  7.Xoa thong tin nhan vien                                                       |\n");
    printf("|  9.Them lich hen                                                                 |\n");
    printf("|  10...                                                                           |\n");
    printf("|                                                                                  |\n");
    printf("|                                                                                  |\n");
    printf("|          TRAN THANH CAM ON QUY KHACH DA SU DUNG DICH VU CUA CHUNG TOI <3         |\n");
    printf("|                                                                                  |\n");
    printf("*----------------------------------------------------------------------------------*");
    k=nhapluachon();
    for(int i =1;i <= 10;i++){
        if(k!=i){
        printf("vui long nhap lai:\n");
        goto BACK2;
        }
        break;
    }
    //gọi hàm thêm, sửa, xóa
    switch (k)
    {
    case 1://thêm bệnh nhân
        
        break;
    case 2://thêm nhân viên

        break;
    case 3://thêm lương nhân viên

        break;
    default://quay lại
        break;
    }

case 2://bạn là bệnh nhân
    BACK3:
    printf("*----------------------------------------------------------------------------------*");
    printf("|                       NHA KHOA CR7 XIN CHAO QUY KHACH !                          |");
    printf("|                                                                                  |");
    printf("|  BAN MUON THUC HIEN DIEU GI?                                                     |");
    printf("|  1.Dat lich hen voi nha si                                                       |");
    printf("|  2.Phan hoi ve chat luong dich vu                                                |");
    printf("|  3.                                                                              |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|                                                                                  |");
    printf("|          TRAN THANH CAM ON QUY KHACH DA SU DUNG DICH VU CUA CHUNG TOI <3         |");
    printf("|                                                                                  |");
    printf("*----------------------------------------------------------------------------------*");


    for(int i =1;i <= 3;i++){
        if(k!=i){
        printf("vui long nhap lai:\n");
        goto BACK3;
        }
        break;
    }

    switch (k)
    {
    case 1://đặt lịch hẹn
        
        break;
    case 2://phản hồi về chất lượng dịch vụ

        break;
    default://nhập sai, nhập lại
        k = nhapluachon();
        break;
    }
    //gọi hàm thêm, sửa, xóa,...
    break;

default://nhập sai, yêu cầu nhập lại
    k=nhapluachon();
    break;
}



}

}