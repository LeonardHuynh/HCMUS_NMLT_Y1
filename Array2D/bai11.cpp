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

void Tach_PhanTuBien(int a[][MAX_COLS], int rows, int cols, int b[], int& size)
{
	size = 0;
	for (int i = 0; i < rows; i++)
	{
		b[size++] = a[i][0];
		b[size++] = a[i][cols - 1];
	}
	for (int j = 1; j < cols - 1; j++)
	{
		b[size++] = a[0][j];
		b[size++] = a[rows - 1][j];
	}
}
void HoanVi(int& a, int& b)
{
	int tg = a;
	a = b;
	b = tg;
}

void SapXep_TangDan(int b[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);
		}
	}
}

void SapXep_MaTran_Bien_ChieuKDH(int a[][MAX_COLS], int rows, int cols)
{
	int b[100];
	int size;
	Tach_PhanTuBien(a, rows, cols, b, size);
	SapXep_TangDan(b, size);
	int i = 0, j = 0; 
	int index = 0;
	for (i, j; j < cols; j++)
	{
		a[i][j] = b[index++];
	}
	i++; // Tang rows them 1 dong
	j--; // Giam cols 1 don vi do vong for lam tang len = cols
	for (i, j; i < rows; i++)
	{
		a[i][j] = b[index++];
	}
	i--; //Giam rows 1 don vi do vong for lam tang len = rows
	j--; //Giam cols 1 don vi
	for (i, j; j >= 0; j--)
	{
		a[i][j] = b[index++];
	}
	i--; //Giam rows 1 don vi, loai bo phan tu da tinh
	j++; //Tang cols len = 0, do vong for lam j = -1
	for (i, j; i > 0; i--)
	{
		a[i][j] = b[index++];
	}
}

int main()
{
	int a[10][10];
	int b[40],size;
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	Tach_PhanTuBien(a, rows, cols, b, size);
	SapXep_MaTran_Bien_ChieuKDH(a, rows, cols);
	printf("Ma tran da sap xep:\n");
	XuatMang2D(a, rows, cols);
	return 0;
}
