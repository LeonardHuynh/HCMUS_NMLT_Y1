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

bool KTra_SoLonNhatDong(int a[][MAX_COLS], int vitri_dong, int vitri_cot, int rows, int cols)
{
	for (int j = 0; j < cols; j++)
	{
		if (a[vitri_dong][j] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
	}
	return true;
}

bool KTra_SoNhoNhatCot(int a[][MAX_COLS], int vitri_dong, int vitri_cot, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		if (a[i][vitri_cot] < a[vitri_dong][vitri_cot])
			return false;
	}
	return true;
}

int Dem_YenNgua(int a[][MAX_COLS], int rows, int cols)
{
	int dem = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (KTra_SoLonNhatDong(a, i, j, rows, cols) && KTra_SoNhoNhatCot(a, i, j, rows, cols))
			{
				printf("a[%d][%d] = %d la mot diem yen ngua\n", i, j, a[i][j]);
				dem++;
			}
		}
		
	}
	return dem;
}

int main()
{
	int a[10][10];
	int rows, cols;
	NhapMang2D(a, rows, cols);
	printf("Ma tran da nhap:\n");
	XuatMang2D(a, rows, cols);
	int dem = Dem_YenNgua(a, rows, cols);
	printf("So gia tri 'yen ngua' trong ma tran: %d", dem);
	return 0;
}
