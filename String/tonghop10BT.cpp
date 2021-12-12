#include <stdio.h>
#include <string>

//nhapxuat.cpp
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} 
}

void xuat_1tu1dong(char a[])
{
	char* piece = strtok(a, " "); 
	while (piece != NULL)
	{
		printf("%s\n", piece);
		piece = strtok(NULL, " ");
	}
}

void xuat_ViTriXuatHienChuoiCon(char a[], char chuoicon[])
{
	int len_a = strlen(a);
	int len_chuoicon = strlen(chuoicon);
	for (int i = 0; i < len_a; i++)
	{
		if (a[i] == chuoicon[0])
		{
			int flag = 1;
			int index = i;
			for (int j = 1; j < len_chuoicon; j++)
			{
				if (a[++index] != chuoicon[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				printf("Vi tri xuat hien chuoi con: %d\n", i);
		}
	}
}

void xuat_ViTriKhongLaKiSo_KiTu(char a[])
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if ((a[i] < '0' || a[i] > '9') && (a[i] < 'A' || a[i] > 'Z') && (a[i] < 'a' || a[i] > 'z'))
		{
			printf("Vi tri xuat hien ki tu khong phai ki so hoac ki tu: %d\n", i);
		}
	}
}


//tinhtoan.cpp
void hoanvi(char& a, char& b)
{
	int tg = a;
	a = b;
	b = tg;
}
void DaoChuoi(char a[])
{
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++)
	{
		hoanvi(a[i], a[len - 1 - i]);
	}
}
void VietHoa_KiTuDau(char a[])
{
	if (a[0] >= 'a' && a[0] <= 'z')
	{
		a[0] -= 32;
	}
	int len = strlen(a);
	for (int i = 1; i < len; i++)
	{
		if (a[i] == ' ' && a[i + 1] >= 'a' && a[i + 1] <= 'z')
		{
			a[i + 1] -= 32;
		}
	}
}

void LoaiBoKhoangTrang(char a[])
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] == ' ')
		{
			for (int j = i; j < len; j++)
			{
				a[j] = a[j + 1];
			}
			i--;
		}
	}
}

int Dem_SoKyTu_CuaTu(char a[], int vitri_tu)
{
	int dem = 0;
	for (int i = vitri_tu; a[i] != '\0' && a[i] != ' '; i++)
	{
		dem++;
	}
	return dem;
}

int DemKyTu(char a[])
{
	int thutu_tu;
	int dem = 0, vitri_tu = 0;
	int soluongtu = 0;
	printf("Nhap vi tri cua tu (tu thu bao nhieu trong mang): ");
	scanf_s("%d", &thutu_tu);
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] != ' ' && a[i + 1] == ' ')
		{
			dem++;
			vitri_tu = i + 2;
		}
		if (dem == thutu_tu - 1)
		{
			soluongtu = Dem_SoKyTu_CuaTu(a, vitri_tu);
			break;
		}
	}
	return soluongtu;
}

void LoaiBo_KhongPhaiKiSo_KiTu(char a[])
{
	int len = strlen(a);
	int n;
	for (int i = 0; i < len; i++)
	{
		if (a[i] < '0' || (a[i] > '9' && a[i] < 'A') || (a[i] > 'Z' && a[i] < 'a') || a[i] > 'z')
		{
			printf("Vi tri khong phai ki so hoac ki tu: %d\n", i);
		}
	}
	printf("Ban co muon xoa cac ki tu khong phai ki so hay ki tu(Nhap '1' hoac '0'): ");
	scanf_s("%d", &n);
	if (n == 1)
	{
		for (int i = 0; i < len; i++)
		{
			if (a[i] < '0' || (a[i] > '9' && a[i] < 'A') || (a[i] > 'Z' && a[i] < 'a') || a[i] > 'z')
			{
				for (int j = i; j < len - 1; j++)
				{
					a[j] = a[j + 1];
				}
				a[len - 1] = '\0';
				i--;
				len--;
			}
		}
	}
}

int main()
{
	int n;
	do
	{
		printf("\n----CHUC NANG----\n");
		printf("Nhap 1: (Bai 1,2) Nhap vao mot chuoi, xuat chuoi do ra man hinh\n");
		printf("Nhap 3: (Bai 3) Xuat chuoi dao\n");
		printf("Nhap 4: (Bai 4) Xuat moi tu trong chuoi tren mot dong\n");
		printf("Nhap 5: (Bai 5) Viet hoa tat ca ki tu dau cua moi tu\n");
		printf("Nhap 6: (Bai 6) Nhap vao chuoi con, xuat danh sach vi tri xuat hien cua chuoi con trong chuoi \n");
		printf("Nhap 7: (Bai 7) Loai bo tat ca khoang trang thua trong chuoi\n");
		printf("Nhap 8: (Bai 8) Nhap vao vi tri cua tu hay cho biet tu nay duoc tao thanh tu bao nhieu ky tu \n");
		printf("Nhap 9: (Bai 9) Tim danh sach vi tri cac ki tu khong phai ki so hoac ky tu trong chuoi\n");
		printf("Nhap 10: (Bai 10) Loai bo nhung ki tu khong phai so hoac ki tu trong chuoi. Truoc khi xoa phai hoi nguoi dung co muon xoa khong. \n");
		printf("Nhap chuc nang: ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			printf("Chuoi vua nhap: ");
			puts(a);
			break;
		}
		case 3:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			DaoChuoi(a);
			puts(a);
			break;
		}
		case 4:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			xuat_1tu1dong(a);
			break;
		}
		case 5:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			VietHoa_KiTuDau(a);
			puts(a);
			break;
		}
		case 6:
		{
			char a[100];
			char chuoicon[100];
			clear();
			printf("Nhap chuoi me: ");
			gets_s(a);
			printf("Nhap chuoi con: ");
			gets_s(chuoicon);
			xuat_ViTriXuatHienChuoiCon(a, chuoicon);
			break;
		}
		case 7:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			LoaiBoKhoangTrang(a);
			puts(a);
			break;
		}
		case 8:
		{
			char a[100];
			int vitri;
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			printf("Chuoi vua nhap: ");
			puts(a);
			int sokytu = DemKyTu(a);
			printf("So ky tu cua tu la: %d", sokytu);
			break;
		}
		case 9:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			xuat_ViTriKhongLaKiSo_KiTu(a);
			break;
		}
		case 10:
		{
			char a[100];
			clear();
			printf("Nhap mot chuoi: ");
			gets_s(a);
			LoaiBo_KhongPhaiKiSo_KiTu(a);
			printf("Chuoi sau khi loai bo: ");
			puts(a);
			break;
		}
		}
		printf("\n-------------------------------------------------------------------------------------------");
	} while (n != 0);
	return 0;
}
