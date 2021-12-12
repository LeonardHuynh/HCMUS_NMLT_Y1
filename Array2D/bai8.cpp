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
	for (int i = 0; i < cols; i++)
	{
		if (a[vitri_dong][i] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
	}
	return true;
}

bool KTra_SoLonNhatCot(int a[][MAX_COLS], int vitri_dong, int vitri_cot, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		if (a[i][vitri_cot] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
	}
	return true;
}

bool KTra_SoLonNhat2DuongCheo(int a[][MAX_COLS], int vitri_dong, int vitri_cot, int rows, int cols)
{
	int dong1, cot1;
	//Kiem tra duong cheo thu nhat
	dong1 = vitri_dong + 1;
	cot1 = vitri_cot + 1;
	while (dong1 < rows && cot1 < cols)
	{
		if (a[dong1][cot1] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
		dong1++;
		cot1++;
	}

	dong1 = vitri_dong - 1;
	cot1 = vitri_cot - 1;
	while (dong1 >= 0 && cot1 >= 0)
	{
		if (a[dong1][cot1] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
		dong1--;
		cot1--;
	}
	//Kiem tra duong cheo thu hai
	dong1 = vitri_dong + 1;
	cot1 = vitri_cot - 1;
	while (dong1 < rows && cot1 >= 0)
	{
		if (a[dong1][cot1] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
		dong1++;
		cot1--;
	}

	dong1 = vitri_dong - 1;
	cot1 = vitri_cot + 1;
	while (dong1 >= 0 && cot1 < cols)
	{
		if (a[dong1][cot1] > a[vitri_dong][vitri_cot])
		{
			return false;
		}
		dong1--;
		cot1++;
	}
	return true;
}

int Dem_HoangHau(int a[][MAX_COLS], int rows, int cols)
{
	int dem = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (KTra_SoLonNhatDong(a, i, j, rows, cols) && KTra_SoLonNhatCot(a, i, j, rows, cols) && KTra_SoLonNhat2DuongCheo(a, i, j, rows, cols))
			{
				printf("a[%d][%d] = %d la mot gia tri 'hoang hau'\n", i, j, a[i][j]);
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
	int dem = Dem_HoangHau(a, rows, cols);
	printf("So luong gia tri 'hoang hau' trong ma tran: %d", dem);
	return 0;
}
