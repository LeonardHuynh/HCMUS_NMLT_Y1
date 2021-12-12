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

int Tim_SoDuongNhoNhat(int a[][MAX_COLS], int rows, int cols)
{
	int minDuong = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] > 0)
			{
				minDuong = a[i][j];
				break;
			}
		}
	}
	if (minDuong == 0)
		return 0;
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if ((a[i][j] > 0) && (minDuong > a[i][j]))
				{
					minDuong = a[i][j];
				}
			}
		}
	}
	return minDuong;
}

int main()
{
	int a[10][10];
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	int min = Tim_SoDuongNhoNhat(a, rows, cols);
	if (min == 0)
		printf("Khong ton tai so duong nho nhat!");
	else
		printf("So duong nho nhat trong ma tran: %d", min);
	return 0;
}
