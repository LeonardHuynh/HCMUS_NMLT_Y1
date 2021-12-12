#include <stdio.h>
#define MAX_COLS 10

void NhapMang2D(int a[][MAX_COLS], int& rows, int& cols)
{
	printf("Nhap so dong: ");
	scanf_s("%d", &rows);
	printf("Nhap so cot: ");
	scanf_s("%d", &cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Nhap a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void XuatMang2D(int a[][MAX_COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void Tach_ChuSo(int n, int b[])
{
	int ChuSo;
	while (n > 0)
	{
		ChuSo = n % 10;
		b[ChuSo]++;
		n /= 10;
	}
}

int Tim_ChuSo_XuatHienNhieuNhat(int a[][MAX_COLS], int rows, int cols)
{
	int b[10] = { 0 };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Tach_ChuSo(a[i][j], b);
		}
	}
	int ChuSo_XuatHienNhieuNhat = 0; 
	for (int i = 0; i < 10; i++)
	{
		if (b[ChuSo_XuatHienNhieuNhat] < b[i])
			ChuSo_XuatHienNhieuNhat = i;
	}
	return ChuSo_XuatHienNhieuNhat;
}

int main()
{
	int a[10][10];
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	int ChuSoXuatHienNhieuNhat = Tim_ChuSo_XuatHienNhieuNhat(a, rows, cols);
	printf("Chu so xuat nhieu nhat trong ma tran: %d", ChuSoXuatHienNhieuNhat);
	return 0;
}
