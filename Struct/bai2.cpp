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


void Nhap_DayPS(PHANSO a[], int& n) {
	printf("Nhap so phan tu cua day phan so: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Nhap phan so thu %d\n", i + 1);
		Nhap_PS(a[i]);
	}
}

void Xuat_DayPS(PHANSO a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d/%d, ", a[i].tu, a[i].mau);
	}
}

PHANSO Tong_DayPS(PHANSO a[], int n) {
	PHANSO tong;
	tong.tu = a[0].tu; tong.mau = a[0].mau;
	for (int i = 1; i < n; i++) {
		tong = Tong_PS(tong, a[i]);
	}
	return tong;
}

void Thay_PS_ToiGian(PHANSO a[], int n) {
	for (int i = 0; i < n; i++) {
		RutGon_PS(a[i]);
	}
}

void HoanVi_PS(PHANSO& a, PHANSO& b) {
	PHANSO tg = a;
	a = b;
	b = tg;
}

void SapXep_DayPS_TangDan(PHANSO a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (SoSanh_PS(a[i], a[j]) == 1) {
				HoanVi_PS(a[i], a[j]);
			}
		}
	}
}

int KiemTra_TonTaiPS(PHANSO a[], int n, PHANSO ps_nhap) {
	for (int i = 0; i < n; i++) {
		int ket_qua = SoSanh_PS(a[i], ps_nhap);
		if (ket_qua == 0) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	printf("Bai 2:\n");
	printf("a.Nhap, xuat day phan so co N phan tu:\n");
	PHANSO a[50];
	int size;
	Nhap_DayPS(a, size);
	printf("Day phan so da nhap: ");
	Xuat_DayPS(a, size);

	printf("\nb.Tong cac phan so co trong day: ");
	PHANSO tong;
	tong = Tong_DayPS(a, size);
	Xuat_PS(tong);

	printf("\nc.Thay the cac phan so khong toi gian:\n");
	printf("Day phan so sau khi thay the: ");
	Thay_PS_ToiGian(a, size);
	Xuat_DayPS(a, size);

	printf("\nd.Sap xep day phan so tang dan: \n");
	printf("Day phan so sau khi sap xep cac phan so tang dan: ");
	SapXep_DayPS_TangDan(a, size);
	Xuat_DayPS(a, size);

	printf("\ne.Kiem tra 1 phan so K co trong day phan so hay khong:\n");
	printf("Nhap mot phan so can kiem tra:\n");
	PHANSO ps_ktra; 
	Nhap_PS(ps_ktra);
	int ketqua = KiemTra_TonTaiPS(a, size, ps_ktra);
	if (ketqua == 1) {
		printf("Phan so da nhap co trong day");
	}
	else {
		printf("Phan so da nhap khong co trong day");
	}
 	 return 0;
}
