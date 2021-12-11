#pragma once
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

void nhap_diem2D(DIEM2D& p);
void xuat_diem2D(DIEM2D p);
double Tinh_KhoangCach(DIEM2D A, DIEM2D B);
double Tinh_ChuVi(DIEM2D A, DIEM2D B, DIEM2D C);
double Tinh_DienTich(DIEM2D A, DIEM2D B, DIEM2D C);
int KiemTra_ViTri(DIEM2D A, DIEM2D B, DIEM2D C, DIEM2D D);
void xuat_vitri(DIEM2D A, DIEM2D B, DIEM2D C, DIEM2D D);
