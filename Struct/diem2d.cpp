#include "diem2d.h"
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


