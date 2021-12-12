#include <stdio.h>

void nhap(int& n) {
	do
	{
		printf("Nhap mot so nguyen duong (n > 2): ");
		scanf_s("%d", &n);
		if (n <= 2) {
			printf("Nhap khong hop le!\n");
		}
	} while (n <= 2);
}

void PhanTichThuaSoNguyenTo(int n) {
	for (int i = 2; i < n; i++)
	{
		while (n % i == 0) {
			printf("%d ", i);
			n /= i; 
		}
	}
	printf("%d ", n);
}

int main()
{
	int n; 
	nhap(n);
	PhanTichThuaSoNguyenTo(n);
	return 0;
}
