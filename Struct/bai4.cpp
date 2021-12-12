#include <stdio.h>

struct HOCSINH {
	char hoten[200];
	float toan;
	float ly;
	float hoa;
};

void clear() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void nhap_DS_HS(HOCSINH a[], int& soluong) {
	do {
		printf("Nhap so luong hoc sinh: ");
		scanf_s("%d", &soluong);
		if (soluong < 1 && soluong > 200) {
			printf("So luong khong hop le!\n");
		}
	} while (soluong < 1 && soluong > 200);
	for (int i = 0; i < soluong; i++) {
		printf("Nhap hoc sinh %d: \n", i + 1);
		printf("Ho va ten: ");
		clear();
		gets_s(a[i].hoten);
		printf("Diem Toan: ");
		scanf_s("%f", &a[i].toan);
		printf("Diem Ly: ");
		scanf_s("%f", &a[i].ly);
		printf("Diem Hoa: ");
		scanf_s("%f", &a[i].hoa);
	}
}

void xuat_DS_HS(HOCSINH a[], int soluong) {
	for (int i = 0; i < soluong; i++) {
		printf("%d.Hoc sinh %d: \n", i + 1, i + 1);
		printf("Ho va ten: %s\n", a[i].hoten);
		printf("Diem Toan: %.2f\n", a[i].toan);
		printf("Diem Ly: %.2f\n", a[i].ly);
		printf("Diem Hoa: %.2f\n", a[i].hoa);
	}
}

void HoanVi(HOCSINH& a, HOCSINH& b) {
	HOCSINH tg = a;
	a = b;
	b = tg;
}

void Xuat_DSToan_TangDan(HOCSINH a[], int size) {
	HOCSINH b[200];
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (b[i].toan > b[j].toan) {
				HoanVi(b[i], b[j]);
			}
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d.%s: %.2f\n", i + 1, b[i].hoten, b[i].toan);
	}
}

float Tinh_DiemTB(HOCSINH a) {
	return (a.toan + a.ly + a.hoa) / 3;
}

void Xuat_3HS_DTBCaoNhat(HOCSINH a[], int size) {
	HOCSINH b[200];
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (Tinh_DiemTB(b[i]) < Tinh_DiemTB(b[j])) {
				HoanVi(b[i], b[j]);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d.%s, DTB: %.2f\n", i + 1, b[i].hoten, Tinh_DiemTB(b[i]));
	}
}

int main() 
{
  printf("Bai 4:\n");
	printf("a.Nhap, xuat danh sach hoc sinh: \n");
	HOCSINH a[200];
	int size;
	nhap_DS_HS(a, size);
	printf("\nDanh sach hoc sinh da nhap:\n");
	xuat_DS_HS(a, size);

	printf("\nb.Xuat danh sach ho ten theo thu tu diem toan tang dan:\n");
	Xuat_DSToan_TangDan(a, size);

	printf("\nc.Xuat thong tin 3 hoc sinh co diem trung binh cao nhat:\n");
	Xuat_3HS_DTBCaoNhat(a, size);
	return 0;
}
