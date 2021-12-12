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

bool KTra_CucTri(int a[][MAX_COLS], int vitri_dong, int vitri_cot, int rows, int cols)
{
	bool CucDai = true, CucTieu = true;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (vitri_dong + i >= 0 && vitri_cot + j >= 0 && vitri_dong + i < rows && vitri_cot + j < cols && !(i == 0 && j == 0))
			{
				if (a[vitri_dong + i][vitri_cot + j] >= a[vitri_dong][vitri_cot])
					CucDai = false;
				if (a[vitri_dong + i][vitri_cot + j] <= a[vitri_dong][vitri_cot])
					CucTieu = false;
				if (CucDai == false && CucTieu == false)
					break;
			}
		}
	}
	if (CucDai == false && CucTieu == false)
		return false;
	return true;
}

int Tinh_TongCucTri(int a[][MAX_COLS], int rows, int cols)
{
	int tong = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (KTra_CucTri(a, i, j, rows, cols) == true)
			{
				printf("a[%d][%d] = %d la phan tu cuc tri\n", i, j, a[i][j]);
				tong += a[i][j];
			}
		}
	}
	return tong;
}

int main()
{
	int a[10][10];
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	int tong = Tinh_TongCucTri(a, rows, cols);
	printf("Tong cac phan tu cuc tri trong ma tran: %d", tong);
	return 0;
}
