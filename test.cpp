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
        goto BACK1;}
switch (k){
case 1:
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
}}