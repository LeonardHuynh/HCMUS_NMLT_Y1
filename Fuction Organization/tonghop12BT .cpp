#include <stdio.h>
#include <math.h>

//kiemtra.cpp
int NhapSoNguyenDuong()
{
	int so_nhap_vao;
	do
	{
		printf("Nhap mot so nguyen duong n: ");
		scanf_s("%d", &so_nhap_vao);
		if (so_nhap_vao <= 0)
			printf("%d khong phai la so nguyen duong, vui long nhap lai!\n", so_nhap_vao);
	} while (so_nhap_vao <= 0);
	return so_nhap_vao;
}

bool KiemTraSoChinhPhuong(int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (i * i == n)
		{
			return true;
		}
	}
	return false;
}

bool KiemTraSoNguyenTo(int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

bool KiemTraSoDoiXung(int n)
{
	if (DaoNguocSo(n) == n)
		return true;
	else
		return false;
}

bool KiemTraSoToanLe(int n)
{
	while (n > 0)
	{
		if ((n % 10) % 2 == 0)
			return false;
		n /= 10;
	}
	return true;
}

bool KiemTraSoHoanChinh(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		return true;
	else
		return false;
}

bool KiemTraSoChan(int n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
}

int TimSoChinhPhuongDauTien(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (KiemTraSoChinhPhuong(i))
			return i;
	}
	return -1;
}

int TimSoHoanChinhCuoiCung(int n)
{
	for (int i = n; i >= 1; i--)
	{
		if (KiemTraSoHoanChinh(i))
			return i;
	}
	return -1;
}

int TimSoHoanChinhDauTien(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (KiemTraSoHoanChinh(i))
			return i;
	}
	return -1;
}

int TimSoChinhPhuongCuoiCung(int n)
{
	for (int i = n; i >= 1; i--)
	{
		if (KiemTraSoChinhPhuong(i))
			return i;
	}
	return -1;
}

//tinhtoan.cpp

int DaoNguocSo(int n)
{
	int so_dao_nguoc = 0;
	do
	{
		so_dao_nguoc = so_dao_nguoc * 10 + n % 10;
		n /= 10;
	} while (n > 0);
	return so_dao_nguoc;
}

int TinhTongCacSoNguyenTo(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (KiemTraSoNguyenTo(i))
			sum += i;
	}
	return sum;
}

int TinhTong_SoChinhPhuong_SoHoanChinh(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (KiemTraSoChinhPhuong(i) || KiemTraSoHoanChinh(i))
			sum += i;
	}
	return sum;
}

long long TinhTich_SoChinhPhuong_SoChan(int n)
{
	long long tich = 1;
	for (int i = 1; i <= n; i++)
	{
		if (KiemTraSoChinhPhuong(i) || KiemTraSoChan(i))
			tich *= i;
	}
	return tich; 
}

long long TinhTich_CacSoNguyenTo_SoToanLe(int n)
{
	long long tich = 1;
	for (int i = 1; i <= n; i++)\
	{
		if (KiemTraSoNguyenTo(i) || KiemTraSoToanLe(i))
		{
			tich *= i;
		}
	}
	return tich;
}

int TinhTong_SoHoanChinhDauTien_SoHoanChinhCuoicung(int n)
{
	int sum = 0;
	if ((TimSoHoanChinhDauTien(n) == -1) || (TimSoHoanChinhCuoiCung(n) == -1))
		sum = -1;
	else 
		for (int i = TimSoHoanChinhDauTien(n); i <= TimSoHoanChinhCuoiCung(n); i++)
		{
			sum += i;
		}
	return sum;
}

long long TinhTich_SoChan_SoHoanChinhDauTien_SoChinhPhuongCuoiCung(int n)
{
	long long tich = 1;
	if ((TimSoHoanChinhDauTien(n) == -1) || (TimSoChinhPhuongCuoiCung(n) == -1))
		tich = -1;
	else 
		for (int i = TimSoHoanChinhDauTien(n); i <= TimSoChinhPhuongCuoiCung(n); i++)
		{
			if (KiemTraSoChan(i))
			{
				tich *= i;
			}
		}
	return tich;
}

int main()
{
	int n;
	do
	{
		printf("\n\n----CHUC NANG----\n");
		printf("Nhap 1: Kiem tra mot so co phai la so chinh phuong hay khong.\n");
		printf("Nhap 2: Kiem tra mot so co phai la so nguyen to hay khong.\n");
		printf("Nhap 3: Kiem tra mot so co phai la so doi xung hay khong.\n");
		printf("Nhap 4: Kiem tra mot so co phai la so toan so le hay khong.\n");
		printf("Nhap 5: Kiem tra mot so co phai la so hoan chinh hay khong.\n");
		printf("Nhap 6: Tinh tong cac so nguyen to tu 1 den n.\n");
		printf("Nhap 7: Tinh tong cac so chinh phuong hoac so hoan chinh tu 1 den n.\n");
		printf("Nhap 8: Tinh tich cac so chinh phuong hoac so chan tu 1 den n.\n");
		printf("Nhap 9: Tinh tich cac so nguyen to hoac so toan le tu 1 den n.\n");
		printf("Nhap 10: Tim so chinh phuong dau tien trong khoang tu 1 den n.\n");
		printf("Nhap 11: Tim so hoan chinh cuoi cung trong khoang tu 1 den n.\n");
		printf("Nhap 12: Tim tong cac so tu so hoan chinh dau tien den so hoan chinh cuoi cung trong khoang tu 1 den n.\n");
		printf("Nhap 13: Tim tich cac so chan tu so hoan chinh dau tien den so chinh phuong cuoi cung trong khoang tu 1 den n.\n");
		printf("Nhap 0: Ket thuc chuong trinh\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
		{
			printf("Cau 1: Kiem tra mot so co phai la so chinh phuong hay khong.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			if (KiemTraSoChinhPhuong(so_nhap_vao))
				printf("%d la so chinh phuong\n", so_nhap_vao);
			else
				printf("%d khong la so chinh phuong\n", so_nhap_vao);
			break;
		}
		case 2:
		{
			printf("Cau 2: Kiem tra mot so co phai la so nguyen to hay khong.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			if (KiemTraSoNguyenTo(so_nhap_vao))
				printf("%d la so nguyen to\n", so_nhap_vao);
			else
				printf("%d khong la so nguyen to\n", so_nhap_vao);
			break;
		}
		case 3:
		{
			printf("Cau 3: Kiem tra mot so co phai la so doi xung hay khong.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			if (KiemTraSoDoiXung(so_nhap_vao))
				printf("%d la so doi xung\n", so_nhap_vao);
			else
				printf("%d khong la so doi xung\n", so_nhap_vao);
			break;
		}
		case 4:
		{
			printf("Cau 4: Kiem tra mot so co phai la so toan so le hay khong.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			if (KiemTraSoToanLe(so_nhap_vao))
				printf("%d la so toan le\n", so_nhap_vao);
			else
				printf("%d khong la so toan le\n", so_nhap_vao);
			break;
		}
		case 5:
		{
			printf("Cau 5: Kiem tra mot so co phai la so hoan chinh hay khong.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			if (KiemTraSoHoanChinh(so_nhap_vao))
				printf("%d la so hoan chinh\n", so_nhap_vao);
			else
				printf("%d khong la so hoan chinh\n", so_nhap_vao);
			break;
		}
		case 6:
		{
			printf("Cau 6: Tinh tong cac so nguyen to tu 1 den n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			int sum = TinhTongCacSoNguyenTo(so_nhap_vao);
			printf("Tong cac so nguyen to tu 1 den %d la: %d\n ", so_nhap_vao, sum);
			break;
		}
		case 7:
		{
			printf("Cau 7: Tinh tong cac so chinh phuong hoac so hoan chinh tu 1 den n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			int sum = TinhTong_SoChinhPhuong_SoHoanChinh(so_nhap_vao);
			printf("Tong cac so chinh phuong hoac so hoan chinh tu 1 den %d la: %d\n", so_nhap_vao, sum);
			break;
		}
		case 8:
		{
			printf("Cau 8: Tinh tich cac so chinh phuong hoac so chan tu 1 den n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			long long tich = TinhTich_SoChinhPhuong_SoChan(so_nhap_vao);
			printf("Tich cac so chinh phuong hoac so chan tu 1 den %d la: %lld\n", so_nhap_vao, tich);
			break;
		}
		case 9:
		{
			printf("Cau 9: Tinh tich cac so nguyen to hoac so toan le tu 1 toi n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			long long tich = TinhTich_CacSoNguyenTo_SoToanLe(so_nhap_vao);
			printf("Tich cac so nguyen to hoac so toan le tu 1 den %d la: %lld\n", so_nhap_vao, tich);
			break;
		}
		case 10:
		{
			printf("Cau 10: Tim so chinh phuong dau tien trong khoang tu 1 toi n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			int so_chinh_phuong_dau_tien = TimSoChinhPhuongDauTien(so_nhap_vao);
			printf("So chinh phuong dau tien trong khoang tu 1 den %d la: %d", so_nhap_vao, so_chinh_phuong_dau_tien);
			break;
		}
		case 11:
		{
			printf("Cau 11: Tim so hoan chinh cuoi cung trong khoang tu 1 toi n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			int so_hoan_chinh_cuoi_cung = TimSoHoanChinhCuoiCung(so_nhap_vao);
			printf("So hoan chinh cuoi cung trong khoang tu 1 den %d la: %d", so_nhap_vao, so_hoan_chinh_cuoi_cung);
			break;
		}
		case 12:
		{
			printf("Cau 12: Tim tong cac so tu so hoan chinh dau tien den so hoan chinh cuoi cung trong khoang tu 1 den n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			int sum = TinhTong_SoHoanChinhDauTien_SoHoanChinhCuoicung(so_nhap_vao);
			printf("Tong cac so tu so hoan chinh dau tien den so hoan chinh cuoi cung trong khoang tu 1 den %d la: %d.\n", so_nhap_vao, sum);
			break;
		}
		case 13:
		{
			printf("Nhap 13: Tim tich cac so chan tu so hoan chinh dau tien den so chinh phuong cuoi cung trong khoang tu 1 den n.\n");
			int so_nhap_vao = NhapSoNguyenDuong();
			long long tich = TinhTich_SoChan_SoHoanChinhDauTien_SoChinhPhuongCuoiCung(so_nhap_vao);
			printf("Tich cac so chan tu so hoan chinh dau tien den so chinh phuong cuoi cung trong khoang tu 1 den %d la: %lld.\n", so_nhap_vao, tich);
			break;
		}
		}
		printf("---------------------------------------------------------------------------------------------");
	} while (n != 0);
	return 0;
}
