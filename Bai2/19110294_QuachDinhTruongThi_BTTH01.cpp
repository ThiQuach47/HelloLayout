// Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Nguoi viet : Quach Dinh Truong Thi
MSSV : 19110294
*/

#include <iostream>
using namespace std;


typedef struct MH {
	char mamh[15];
	char tenmh[50];
	int sotc;
	float diem;
};
typedef struct SV {
	char mssv[10];
	char hoten[50];
	int tuoi;
	int somon;
	MH kq[100];
	int tongtc, tongtctl;
	float dtbc, dtbtl;
};
//Khai báo các hàm thao tác
//1. Đọc dữ liệu từ file --> cấu trúc SV
//Đồng thời tính các thông số còn lại (tongtc,...)
void docfile(char filename[], SV& s);
//2. In thông tin của 1 sinh viên ra màn hình
void insv(SV s);
//3. Ghi dữ liệu từ cấu trúc SV --> file (văn bản)
void ghifile(char filename[], SV s);

int main()
{
	SV a;
	docfile("C:/SV.TXT", a);
	insv(a);
	return 0;
}

void docfile(char filename[], SV& s)
{
	char temp[100];
	FILE* fp;
	fp = fopen(filename, "rt");
	if (!fp) {
		cout << "khong mo duoc tap tin!\n";
			return;
	}
	fgets(s.mssv, 10, fp);
	s.mssv[strlen(s.mssv) - 1] = '\0';
	fgets(s.hoten, 50, fp);
	s.hoten[strlen(s.hoten) - 1] = '\0';
	fscanf(fp, "%d", &s.tuoi);
	fscanf(fp, "%d", &s.somon);

	for (int i = 0; i < s.somon; i++) {
		fgets(temp, 100, fp);
		fgets(temp, 100, fp);
		fgets(s.kq[i].mamh, 15, fp);
		fgets(s.kq[i].tenmh, 50, fp);
		fscanf_s(fp, "%d", &s.kq[i].sotc);
		fscanf_s(fp, "%d", &s.kq[i].diem);

	}

	fclose(fp);
}
void insv(SV s) {
	printf("Ma so SV : %s\n", s.mssv);
	printf("Ho va Ten : %s\n", s.hoten);
	printf("Tuoi : %s\n", s.tuoi);
	printf("so mon : %s\n", s.somon);

}

