#include <stdio.h>

struct CAPSO {
	int a;
	int b;
};

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

void xoa_1phantutrongday(CAPSO a[], int index, int& size) {
	for (int i = index; i < size - 1; i++) {
		a[i] = a[i + 1];
	}
	size--;
}

void loai_phantulap(CAPSO a[], int& size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((a[i].a == a[j].b) && (a[i].b == a[j].a)) {
				xoa_1phantutrongday(a, i, size);
				i--;
			}
		}
	}
}

void xuat_daycapso(CAPSO a[], int size) {
	for (int i = 0; i < size; i++)
	{
		printf("(%d,%d), ", a[i].a, a[i].b);
	}
}

void xuat_capso(int n) {
	CAPSO a[10000];
	int size = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if ((i * i + j * j) < n) {
				a[size].a = i;
				a[size].b = j;
				size++;
			}
		}
	}
	loai_phantulap(a, size);
	xuat_daycapso(a, size);
}

int main()
{
	int n;
	nhap_songuyenduong(n);
	xuat_capso(n);
	return 0;
}
