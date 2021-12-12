#include <stdio.h>
#include <math.h>

void nhap_toado(int& a, int& b) {
	printf("Nhap hoanh do x: ");
	scanf_s("%d", &a);
	printf("Nhap tung do y: ");
	scanf_s("%d", &b);
}

double tinh_khoangcach(int a1, int a2, int b1, int b2) {
	return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
}

int main()
{
	int a1, a2, b1, b2;
	printf("Nhap toa do diem A: \n");
	nhap_toado(a1, a2);
	printf("Nhap toa do diem B: \n");
	nhap_toado(b1, b2);
	double distance = tinh_khoangcach(a1, a2, b1, b2);
	printf("Khoang cach giua hai diem A,B: %.2lf", distance);
	return 0;
}
