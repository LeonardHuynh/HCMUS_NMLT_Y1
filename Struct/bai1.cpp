#include <stdio.h>
#include <math.h>

struct PHANSO {
	int tu;
	int mau;
};

void Nhap_PS(PHANSO& ps) {
	printf("Tu so: ");
	scanf_s("%d", &ps.tu);
	do {
		printf("Mau so: ");
		scanf_s("%d", &ps.mau);
		if (ps.mau == 0) {
			printf("Mau so khong hop le!");
		}
	} while (ps.mau == 0);
}

void Xuat_PS(PHANSO ps) {
	printf("%d/%d", ps.tu, ps.mau);
}

int Tinh_UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

void RutGon_PS(PHANSO& ps) {
	int UCLN = Tinh_UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / UCLN;
	ps.mau = ps.mau / UCLN;
}

PHANSO Tong_PS(PHANSO a, PHANSO b) {
	PHANSO tong;
	tong.tu = a.tu * b.mau + a.mau * b.tu;
	tong.mau = a.mau * b.mau;
	RutGon_PS(tong);
	return tong;
}

PHANSO Hieu_PS(PHANSO a, PHANSO b) {
	PHANSO hieu;
	hieu.tu = a.tu * b.mau - a.mau * b.tu;
	hieu.mau = a.mau * b.mau;
	RutGon_PS(hieu);
	return hieu;
}

PHANSO Tich_PS(PHANSO a, PHANSO b) {
	PHANSO tich;
	tich.tu = a.tu * b.tu;
	tich.mau = a.mau * b.mau;
	RutGon_PS(tich);
	return tich;
}

PHANSO Thuong_PS(PHANSO a, PHANSO b) {
	PHANSO thuong;
	thuong.tu = a.tu * b.mau;
	thuong.mau = a.mau * b.tu;
	RutGon_PS(thuong);
	return thuong;
}

int SoSanh_PS(PHANSO a, PHANSO b) {
	if (a.tu * b.mau > a.mau * b.tu) {
		return 1;
	}
	else if (a.tu * b.mau == a.mau * b.tu) {
		return 0;
	}
	else {
		return -1;
	}
}

int main()
{
	printf("Bai 3:\n");
	printf("a.Nhap, xuat diem 2D:\n");
	DIEM2D p1;
	nhap_diem2D(p1);
	printf("Diem da nhap: ");
	xuat_diem2D(p1);

	printf("\nb.Tinh khoang cach giua 2 diem A, B:\n");
	DIEM2D A1, B1;
	printf("Nhap diem A:\n");
	nhap_diem2D(A1);
	printf("Nhap diem B:\n");
	nhap_diem2D(B1);
	double khoangcachAB = Tinh_KhoangCach(A1, B1);
	printf("Khoang cach giua 2 diem A,B: %lf", khoangcachAB);

	printf("\nc.Tinh chu vi va dien tich tam giac tu 3 diem A, B, C:\n");
	DIEM2D A, B, C;
	printf("Nhap diem A:\n");
	nhap_diem2D(A);
	printf("Nhap diem B:\n");
	nhap_diem2D(B);
	printf("Nhap diem C:\n");
	nhap_diem2D(C);
	printf("Chu vi tam giac ABC: %lf\n", Tinh_ChuVi(A, B, C));
	printf("Dien tich tam giac ABC: %lf", Tinh_DienTich(A, B, C));

	printf("\nd.Kiem tra diem D nam trong tam giac ABC:\n");
	DIEM2D D;
	printf("Nhap diem D:\n");
	nhap_diem2D(D);
	xuat_vitri(A, B, C, D);
	return 0;
}
