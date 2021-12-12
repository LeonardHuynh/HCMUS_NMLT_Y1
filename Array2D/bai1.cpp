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

int Tong_PhanTuDuong(int a[][MAX_COLS], int rows, int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] > 0)
			{
				sum += a[i][j];
			}
		}
		
	}
	return sum;
}

int main()
{
	int a[10][10]; 
	int rows, cols; 
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap: \n");
	XuatMang2D(a, rows, cols);
	int sum = Tong_PhanTuDuong(a, rows, cols);
	printf("Tong cac phan tu duong trong ma tran: %d", sum);
	return 0;
}
