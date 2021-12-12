#include <stdio.h>

void nhap(int& n) {
	do
	{
		printf("Nhap mot so nguyen khong am: ");
		scanf_s("%d", &n);
		if (n < 0) {
			printf("Nhap khong hop le!\n");
		}
	} while (n < 0);
}

bool KiemTra_SoTangDan(int n) {
	int a[50], size = 0;
	while (n > 0) {
		a[size++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < size - 1; i++) {
		if (a[i] <= a[i + 1]) {
			return false;
		}
	}
	return true;
}

bool KiemTra_SoGiamDan(int n) {
	int a[50], size = 0;
	while (n > 0) {
		a[size++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < size - 1; i++) {
		if (a[i] >= a[i + 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	nhap(n);
	bool ketqua_tang = KiemTra_SoTangDan(n);
	if (ketqua_tang) {
		printf("%d la so tang dan!\n", n);
	}
	else {
		printf("%d khong phai la so tang dan!\n", n);
	}

	bool ketqua_giam = KiemTra_SoGiamDan(n);
	if (ketqua_giam) {
		printf("%d la so giam dan!\n", n);
	}
	else {
		printf("%d khong phai la so giam dan!\n", n);
	}
}
