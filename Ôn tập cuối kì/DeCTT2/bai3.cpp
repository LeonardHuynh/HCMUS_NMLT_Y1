#include <stdio.h>

bool NamNhuan(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int NgayToiDa_TrongThang(int month, int year) {
	switch (month) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: 
	{
		return 31;
	}
	case 2:
	{
		if (NamNhuan(year)) {
			return 29;
		}
		return 28;
	}
	case 4:case 6:case 9:case 11:
	{
		return 30;
	}
	}
}

void NhapNgayThangNam(int& day, int& month, int& year) {
	do
	{
		printf("Nhap nam: ");
		scanf_s("%d", &year);
		if (year < 1975) {
			printf("Nhap khong hop le!\n");
		}
	} while (year < 1975);

	do
	{
		printf("Nhap thang: ");
		scanf_s("%d", &month);
		if (month < 1 || month > 12) {
			printf("Nhap khong hop le!\n");
		}
	} while (month < 1 || month > 12);

	do
	{
		printf("Nhap ngay: ");
		scanf_s("%d", &day);
		if (day < 1 || day > NgayToiDa_TrongThang(month, year)) {
			printf("Nhap khong hop le!\n");
		}
	} while (day < 1 || day > NgayToiDa_TrongThang(month, year));
}

void XuatThu(int day, int month, int year) {
	int n;
	n = (day + 2 * month + (3 * (month + 1)) / 5 + year + (year / 4)) % 7;
	switch (n) {
	case 0:
		printf("Ngay do la chu nhat.");
		break;
	case 1:
		printf("Ngay do la thu 2.");
		break;
	case 2:
		printf("Ngay do la thu 3.");
		break;
	case 3:
		printf("Ngay do la thu 4.");
		break;
	case 4:
		printf("Ngay do la thu 5.");
		break;
	case 5:
		printf("Ngay do la thu 6.");
		break;
	case 6:
		printf("Ngay do la thu 7.");
		break;
	}
}

int main()
{
	int day, month, year;
	NhapNgayThangNam(day, month, year);
	XuatThu(day, month, year);
	return 0;
}
