#include <stdio.h>
#include <math.h>

void nhap_songuyenduong(int& n) {
	do
	{
		printf("Nhap mot so nguyen duong: ");
		scanf_s("%d", &n);
		if (n <= 0) {
			printf("Nhap khong hop le!\n");
		}
	} while (n <= 0);
}

int GCD(int a, int b) {
	while (a != b) {
		a = abs(a - b);
		b = abs(a - b);
	}
	return a;
}

void xuat_phansotoigian(int m, int n) {
	int tu = m / GCD(m, n);
	int mau = n / GCD(m, n);
	printf("%d/%d", tu, mau);
}

int main()
{
	int m, n;
	printf("Nhap m: \n");
	nhap_songuyenduong(m);
	printf("Nhap n: \n");
	nhap_songuyenduong(n);
	printf("Phan so toi gian: ");
	xuat_phansotoigian(m, n);
	return 0;
}
