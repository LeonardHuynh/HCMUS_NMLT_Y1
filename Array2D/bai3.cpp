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

int Tim_SoLonNhat_TrenBien(int a[][MAX_COLS], int rows, int cols)
{
	int max = a[0][0];
	for (int i = 0; i < rows; i++)
	{
		if (max < a[i][0])
			max = a[i][0];
		if (max < a[i][cols - 1])
			max = a[i][cols - 1];
	}
	for (int j = 1; j < cols - 1; j++)
	{
		if (max < a[0][j])
			max = a[0][j];
		if (max < a[rows - 1][j])
			max = a[rows - 1][j];
	}
	return max;
}

int main()
{
	int a[10][10];
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	int max = Tim_SoLonNhat_TrenBien(a, rows, cols);
	printf("So lon nhat tren bien ma tran: %d", max);
	return 0;
}
