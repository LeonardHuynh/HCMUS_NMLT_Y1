#include <stdio.h>
#include <math.h>

struct DIEM2D {
	int x;
	int y;
};

struct TAMGIAC {
	DIEM2D A;
	DIEM2D B;
	DIEM2D C;
};

void nhap_diem2D(DIEM2D& p) {
	printf("Hoanh do x: ");
	scanf_s("%d", &p.x);
	printf("Tung do x: ");
	scanf_s("%d", &p.y);
}

void xuat_diem2D(DIEM2D p) {
	printf("(%d,%d)", p.x, p.y);
}

double Tinh_KhoangCach(DIEM2D A, DIEM2D B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));;
}

double Tinh_ChuVi(DIEM2D A, DIEM2D B, DIEM2D C) {
	return Tinh_KhoangCach(A, B) + Tinh_KhoangCach(A, C) + Tinh_KhoangCach(B, C);
}

double Tinh_DienTich(DIEM2D A, DIEM2D B, DIEM2D C) {
	double p = Tinh_ChuVi(A, B, C);
	return sqrt(p * (p - Tinh_KhoangCach(A, B)) * (p - Tinh_KhoangCach(A, C)) * (p - Tinh_KhoangCach(B, C)));
}

int KiemTra_ViTri(DIEM2D A, DIEM2D B, DIEM2D C, DIEM2D D) {
	double dientichABD = Tinh_DienTich(A, B, D);
	double dientichACD = Tinh_DienTich(A, C, D);
	double dientichBCD = Tinh_DienTich(B, C, D);
	double dientichABC = Tinh_DienTich(A, B, C);
	double d = (dientichABD + dientichACD + dientichBCD) - dientichABC;
	printf("dientichABD = %lf\n", dientichABD);
	printf("dientichACD = %lf\n", dientichACD);
	printf("dientichBCD = %lf\n", dientichBCD);
	printf("dientichABC = %lf\n", dientichABC);
	if (d > 0) {
		return 0;
	}
	else
	{
		return 1;
	}
}

void xuat_vitri(DIEM2D A, DIEM2D B, DIEM2D C, DIEM2D D) {
	switch (KiemTra_ViTri(A, B, C, D))
	{
	case 1:
	{
		printf("Diem D nam trong tam giac");
		break;
	}
	case 2:
	{
		printf("Diem D khong nam trong tam giac");
		break;
	}
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
