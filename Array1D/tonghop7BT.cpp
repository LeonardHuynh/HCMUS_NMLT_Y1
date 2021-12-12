#include <stdio.h>
#include <math.h>

//nhapxuat.cpp
//Bai 1
void Nhap_DaySoThuc(float a[], int& n)
{
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf_s("%d", &n);
		if ((n <= 0) || (n > 50))
			printf("Nhap khong hop le, xin vui long nhap lai!\n");
	} while ((n <= 0) || (n > 50));
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf_s("%f", &a[i]);
	}
}

void Xuat_DaySoThuc(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %f ", a[i]);
	}
}
//Bai 2:
int Nhap_SoNguyen()
{
	int n;
	do
	{
		printf("Nhap so nguyen can chuyen sang he nhi phan: ");
		scanf_s("%d", &n);
		if ((n < -255) || (n > 255))
			printf("Nhap khong hop le, vui long nhap lai!\n");
	} while ((n < -255) || (n > 255));
	return n;
}
void Xuat_MangNhiPhan(int a[])
{
	for (int i = 8; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}

//Bai 3:
void Nhap_Day16bit(int a[])
{
	for (int i = 0; i < 16; i++)
	{
		do
		{
			printf("Nhap a[%d]: ", i);
			scanf_s("%d", &a[i]);
			if ((a[i] != 1) && (a[i] != 0))
				printf("Nhap khong hop le, vui long nhap lai! \n");
		} while ((a[i] != 1) && (a[i] != 0));
	}
}

void Xuat_Day16bit(int a[])
{
	for (int i = 0; i < 16; i++)
	{
		printf("%d", a[i]);
	}
}
//Bai 4: 
int Nhap_SoNguyenX()
{
	int X;
	printf("Nhap so nguyen X: ");
	scanf_s("%d", &X);
	return X;
}

void Nhap_Max10000(int a[], int& n)
{
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
		if ((n <= 0) || (n > 10000))
			printf("Nhap khong hop le, vui long nhap lai!\n");
	} while ((n <= 0) || (n > 10000));
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}
void Xuat_Max10000(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
}
//Bai 5:
void Nhap_Max15(int a[], int& n)
{
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
		if ((n < 0) || (n > 15))
			printf("Nhap khong hop le, vui long nhap lai!\n");
	} while ((n < 0) || (n > 15));
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("Nhap a[%d]: ", i);
			scanf_s("%d", &a[i]);
			if (a[i] <= 0)
				printf("%d khong la so nguyen duong, vui long nhap lai!\n", a[i]);
		} while (n <= 0);
	}
}
//Bai 6:
void Nhap_Max1000(int a[], int& n)
{
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf_s("%d", &n);
		if ((n <= 0) || (n > 1000))
			printf("Nhap khong hop le, vui long nhap lai!\n");
	} while ((n < 0) || (n > 1000));
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("Nhap a[%d]: ", i);
			scanf_s("%d", &a[i]);
			if (abs(a[i]) > 10000)
				printf("Nhap khong hop le, vui long nhap lai!\n");
		} while (abs(a[i]) > 10000);
	}
}
void Xuat_Max1000(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
}
//Bai 7:
void Nhap_Max25(int a[], int& n)
{
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
		if ((n < 1) || (n > 25))
			printf("Nhap khong hop le, vui long nhap lai!\n");
	} while ((n < 1) || (n > 25));
	
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}
void Xuat_Max50(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
}

//kiemtra.cpp
//Bai 5:
bool KTra_TanCung6(int n)
{
	if (n % 10 == 6)
		return true;
	else
		return false;
}

bool KTra_BoiCua6(int n)
{
	if (n % 6 == 0)
		return true;
	else
		return false;
}

bool KTra_SoNguyenTo(int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
				return false;
		}
	return true;
}

//tinhtoan.cpp
//Bai 1:
int Dem_SoAm(float a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			dem++;
	}
	return dem;
}
//Bai 2: 
void DecToBin(int a[], int n)
{
	n = abs(n);
	int i = 0;
	while (n != 0)
	{
		a[i] = n % 2;
		n /= 2;
		i++;
	}
}
void NegativeNumber(int a[])
{
	int index = 0;
	for (int i = 0; i < 9; i++)
	{
		if (a[i] == 1)
		{
			index = i;
			break;
		}
	}
	for (int j = index + 1; j < 9; j++)
	{
		if (a[j] == 0)
			a[j] = 1;
		else
			a[j] = 0;
	}
}

//Bai 3:
void BinToDec(int a[])
{
	int DecNumber = 0;
	for (int i = 0; i < 16; i++)
	{
		if (i == 0)
			DecNumber += -a[i] * pow(2, 15);
		else
			DecNumber += a[i] * pow(2, 15 - i);
	}
	printf("%d", DecNumber);
}
//Bai 4:
void Tim_UocSo(int a[], int size, int n)
{
	for (int i = 0; i < size; i++)
	{
		if (n % a[i] == 0)
		{
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
}

void HoanVi(int& a, int& b)
{
	int tg = a;
	a = b;
	b = tg;
}


void SapXep(int a[], int size, int X)
{
	int b[1000] = { 0 };
	int end = size - 1, start = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (X % a[i] == 0)
		{
			b[end] = a[i];
			end--;
		}
		else
		{
			b[start] = a[i];
			start++;
		}
	}
	for (int i = 0; i < size; i++)
		a[i] = b[i];

	for (int i = 0; i < end; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
		}
	}
}

//Bai 5:
int Dem_TanCung6_BoiCua6(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTra_TanCung6(a[i]) && KTra_BoiCua6(a[i]))
			dem++;
	}
	return dem;
}
float Tinh_TBC_SoNguyenTo(int a[], int n)
{
	float tong = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTra_SoNguyenTo(a[i]))
		{
			tong += a[i];
			dem++;
		}
	}
	return tong / dem;
}
int Dem_SoNgto_Phanbiet(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTra_SoNguyenTo(a[i]) == true)
		{
			dem++;
			for (int j = 0; j < i; j++)
			{
				if (a[j] == a[i])
				{
					dem--;
					break; 
				}
			}
		}
	}
	return dem;
}
//Bai 6:
void Trich_PhanTu_KhongLaSNT(int mangA[], int size1, int mangB[], int& size2)
{
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		if (KTra_SoNguyenTo(mangA[i]) == false)
		{
			mangB[j] = mangA[i];
			j++;
		}
	}
	size2 = j;
}

void Sapxep_Giamdan(int a[], int n)
{
	int tg = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
			{
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
}

void Xoa_SoNguyenTo(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (KTra_SoNguyenTo(a[i]) == true)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--; // Giảm độ dài của chuỗi đi một đơn vị
			i--; // Xét tiếp a[i] mới vừa được đè lên, vẫn có thể xảy ra trường hợp a[i] mới cũng là một số nguyên tố
		}
	}
}
//Bai 7: 
void Xuat_CoTrongA_KhongCoTrongB(int a[], int size1, int b[], int size2)
{
	int flag = 1;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (a[i] == b[j])
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			printf(" %d ", a[i]);
		}
	}
}
void Ghep_AB_KhongTrungNhau(int a[], int size1, int b[], int size2, int c[], int& size3)
{
	size3 = 0;
	for (int i = 0; i < size1; i++)
	{
		c[i] = a[i];
		size3++;
	}
	int flag = 1;
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (b[i] == a[j])
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			c[size3] = b[i];
			size3++;
		}
	}
}

int main()
{
	int n;
	do
	{
		printf("\n----BAI TAP----\n");
		printf("Nhap 1: Giai cau 1\n");
		printf("Nhap 2: Giai cau 2\n");
		printf("Nhap 3: Giai cau 3\n");
		printf("Nhap 4: Giai cau 4\n");
		printf("Nhap 5: Giai cau 5\n");
		printf("Nhap 6: Giai cau 6\n");
		printf("Nhap 7: Giai cau 7\n");
		printf("Nhap 0: Ket thuc\n");
		printf("Nhap: ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
		{
			float a[50];
			int size;
			Nhap_DaySoThuc(a, size);
			printf("Mang da nhap: ");
			Xuat_DaySoThuc(a, size);
			int dem = Dem_SoAm(a, size);
			printf("\nSo phan tu am trong mang: %d", dem);
			break;
		}
		case 2:
		{
			int a[9] = { 0 };
			int n = Nhap_SoNguyen();
			if (n < 0)
			{
				DecToBin(a, n);
				NegativeNumber(a);
				printf("He nhi phan: ");
				Xuat_MangNhiPhan(a);
			}
			else
			{
				DecToBin(a, n);
				Xuat_MangNhiPhan(a);
			}
			break;
		}
		case 3:
		{
			int a[16];
			Nhap_Day16bit(a);
			printf("Day bit nhi phan da nhap: ");
			Xuat_Day16bit(a);
			printf("\nHe thap phan: ");
			BinToDec(a);
			break;
		}
		case 4:
		{
			int a[10000];
			int size;
			int So_X = Nhap_SoNguyenX();
			Nhap_Max10000(a, size);
			printf("Cau a: \n");
			printf("Cac phan tu la uoc cua %d:\n", So_X);
			Tim_UocSo(a, size, So_X);
			printf("Cau b: \n");
			SapXep(a, size, So_X);
			printf("Ket qua: ");
			Xuat_Max10000(a, size);
			break;
		}
		case 5: 
		{
			int a[15];
			int size;
			Nhap_Max15(a, size);
			printf("Cau a:\n");
			int dem = Dem_TanCung6_BoiCua6(a, size);
			printf("So phan tu tan cung la 6 va chia het cho 6 trong mang la: %d\n", dem);
			printf("Cau b:\n");
			float tbc = Tinh_TBC_SoNguyenTo(a, size);
			printf("Trung binh cac so nguyen to trong mang: %f\n", tbc);
			printf("Cau c:\n");
			dem = Dem_SoNgto_Phanbiet(a, size);
			printf("So so nguyen to phan biet trong mang: %d\n", dem);
			break;
		}
		case 6:
		{
			int a[1000], b[1000];
			int size1; int size2;
			Nhap_Max1000(a, size1);
			printf("\nCau a:\n");
			Trich_PhanTu_KhongLaSNT(a, size1, b, size2);
			printf("Mang B la: ");
			Xuat_Max1000(b, size2);
			printf("\nCau b:\n");
			Sapxep_Giamdan(b, size2);
			printf("Mang B sau khi sap xep: ");
			Xuat_Max1000(b, size2);
			printf("\nCau c:\n");
			Xoa_SoNguyenTo(a, size1);
			printf("Mang A sau khi xoa cac so nguyen to: ");
			Xuat_Max1000(a, size1);
			break;
		}
		case 7:
		{
			int a[25], b[25], size1, size2;
			printf("Nhap mang A:\n");
			Nhap_Max25(a, size1);
			printf("Nhap mang B:\n");
			Nhap_Max25(b, size2);
			printf("Cau a:\n");
			printf("Phan tu co trong A nhung khong co trong B la: ");
			Xuat_CoTrongA_KhongCoTrongB(a, size1, b, size2);
			printf("\nCau b:\n");
			int c[50], size3;
			Ghep_AB_KhongTrungNhau(a, size1, b, size2, c, size3);
			printf("Mang C la: ");
			Xuat_Max50(c, size3);
			break;
		}
		}
		printf("\n------------------------------------------------");
	} while (n != 0);
	return 0;
}
