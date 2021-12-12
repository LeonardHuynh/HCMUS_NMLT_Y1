#include <stdio.h>

void nhap_songuyenkhongam(int& k) {
	do
	{
		printf("Nhap mot so nguyen khong am: ");
		scanf_s("%d", &k);
		if (k < 0) {
			printf("Nhap khong hop le!\n");
		}
	} while (k < 0);
}


int giaithua(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	return n * giaithua(n - 1);
}

double tong(int k) {
	if (k == 0) {
		return 1;
	}
	return  (double)1 / giaithua(2 * k) + tong(k - 1);
}

int main()
{
	int k;
	nhap_songuyenkhongam(k);
	double ketqua = tong(k);
	printf("%.9lf", ketqua);
	return 0;
}
