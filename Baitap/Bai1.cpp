// 
/* Nguoi viet : Quach Dinh Truong thi
	MSSV : 19110294
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cmath>
using namespace std;
struct PhanSo
{
	int tuso;
	int mauso;
};
struct MangPhanSo
{
	PhanSo dsps[100];
	int n;
};
// nhap phan so 
void nhapphanso(PhanSo& ps);
// xuat phan so 
void xuatphanso(const PhanSo ps);
// rut gon phan so
int timucln(int a, int b);
//tinh tong hieu tich thuong 2 phan so
PhanSo Tong2phanso(const PhanSo x, const PhanSo y);
PhanSo Hieu2phanso(const PhanSo x, const PhanSo y);
PhanSo Tich2phanso(const PhanSo x, const PhanSo y);
PhanSo Thuong2phanso(const PhanSo x, const PhanSo y);
// kiem tra phan so toi gian 
bool kiemtrapstg(const PhanSo& ps);
// so sanh 2 phan so 
int sosanh2ps(const PhanSo x, PhanSo y);
// nghich dao
PhanSo NghichDao(const PhanSo x);
void rutgonps(const PhanSo& ps);



int main()
{
	PhanSo x, y;
	nhapphanso(x);
	xuatphanso(x);
	if (kiemtrapstg(x))
	{
		cout << "phan so x toi gian \n";
	}
	else
		cout << "phan so khong toi gian \n";
	cout << endl;
	cout << "Nghich dao cua phan so la : ";
	xuatphanso(NghichDao(x));
	
	
	cout << endl;
	nhapphanso(y);
	xuatphanso(y);
	if (kiemtrapstg(y))
	{
		cout << "phan so y toi gian \n ";
	}
	else
		cout << "phan so y khong toi gian \n";
	cout << endl;
	cout << "Nghich dao cua phan so la : ";
	xuatphanso(NghichDao(y));
	


	do {
		PhanSo tong = Tong2phanso(x, y);
		PhanSo hieu = Hieu2phanso(x, y);
		PhanSo tich = Tich2phanso(x, y);
		PhanSo thuong = Thuong2phanso(x, y);
		cout << "Tong = ";
		xuatphanso(tong);
		cout << "Hieu = ";
		xuatphanso(hieu);
		cout << "tich = ";
		xuatphanso(tich);
		cout << "thuong = ";
		xuatphanso(thuong);
		if (sosanh2ps(x, y) == 1)
			cout << "phan so x lon hon phan so y ";
		else if (sosanh2ps(x, y) == 0)
			cout << "phan so x bang phan so y ";
		else
			cout << " phan so x nho hon phan so y ";



		cout << " \nnhan phim ESC de thoat... \n";
	} while (_getch() != 27);
	return 0;

}
// nhap phan so 
void nhapphanso(PhanSo& ps)
{
	cout << "Nhap tu so : \n";
	cin >> ps.tuso;
	do
	{
		cout << "Nhap mau so : \n";
		cin >> ps.mauso;
		if (ps.mauso == 0)
			cout << "Mau so phai khac 0 \n";
	} while (ps.mauso == 0);
}
// xuat phan so 
void xuatphanso(const PhanSo ps)
{
	cout << ps.tuso << "/" << ps.mauso << endl;
}
// rut gon phan so
int timucln(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return b;
}
void rutgonps(PhanSo& ps)
{
	int ucln = timucln(ps.tuso, ps.mauso);
	ps.tuso /= ucln;
	ps.mauso /= ucln;
}
//tinh tong hieu tich thuong 2 phan so
PhanSo Tong2phanso(const PhanSo x, const PhanSo y)
{
	PhanSo tong;
	tong.tuso = x.tuso * y.mauso + y.tuso * x.mauso;
	tong.mauso = x.mauso * y.mauso;
	rutgonps(tong);
	return tong;

}
PhanSo Hieu2phanso(const PhanSo x, const PhanSo y)
{
	PhanSo hieu;
	hieu.tuso = x.tuso * y.mauso - y.tuso * x.mauso;
	hieu.mauso = x.mauso * y.mauso;
	rutgonps(hieu);
	return hieu;
}
PhanSo Tich2phanso(const PhanSo x, const PhanSo y)
{
	PhanSo tich;
	tich.tuso = x.tuso * y.tuso;
	tich.mauso = x.mauso * y.mauso;
	rutgonps(tich);
	return tich;
}
PhanSo Thuong2phanso(const PhanSo x, const PhanSo y)
{
	PhanSo thuong;
	thuong.tuso = x.tuso * y.mauso;
	thuong.mauso = x.mauso * y.tuso;
	rutgonps(thuong);
	return thuong;

}
PhanSo NghichDao(const PhanSo x)
{
	PhanSo b;
	b.tuso = x.mauso;
	b.mauso = x.tuso;
	return b;
}
// kiem tra phan so toi gian 
bool kiemtrapstg(const PhanSo& ps)
{
	int ucln = timucln(ps.tuso, ps.mauso);
	return ucln == 1;
}

// so sanh 2 phan so 
int sosanh2ps(const PhanSo x, PhanSo y)
{
	if ((float)x.tuso / x.mauso > (float)y.tuso / y.mauso)
		return 1;
	else if ((float)x.tuso / x.mauso == (float)y.tuso / y.mauso)
		return 0;
	else
		return 2;


}
