#include<stdio.h>

/* hàm kiểm tra năm nhuận */
int nhuan(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/* hàm trả về số ngày tối đa của một tháng bất kì */
int songaytrongthang(int month, int year)
{
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
	{
		return 31;
		break;
	}
	case 2:
	{
		if (nhuan(year))
		{
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

/* hàm tìm ngày trước đó - in ra ngày trước đó*/
void ngaytruocdo(int day, int month, int year)
{
	// ta cần khai báo các biến previous_year, previous_month, previous_day là các ngày tháng năm trước đó
	int previous_year = year; int previous_month = month; int previous_day = day;
	//nếu không rơi vào các trước hợp đặc biệt thì ngày trước đó bằng ngày nhập - 1
	previous_day = previous_day - 1;
	//nếu tháng nhập vào != 1 và ngày nhập vào = 1 thì có các trường hợp xảy ra như sau:
	if (month != 1 && day == 1)
	{
		//trường hơp 1: tháng nhập vào là 2,4,6,8,9,11 thì ngày trước đó sẽ là ngày 31 tháng trước đó
		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			previous_day = 31;
			previous_month = month - 1;
		}
		//trường hơp 2: tháng nhập vào là tháng 3 thì ngày trước đó là ngày 29 nếu năm nhuận và 28 nếu không nhuận
		if (month == 3) {
			if (nhuan(year)) {
				previous_day = 29;
				previous_month = month - 1;
				}
			else
			{
				previous_day = 28;
				previous_month = month - 1;
			}
		}
		//trường hơp 3: tháng nhập vào là tháng 5,7,10,12 thì ngày trước đó sẽ là 30
		if (month == 5 || month == 7 || month == 10 || month == 12) {
			previous_day = 30;
			previous_month = month - 1;
		}
	}
	//nếu tháng nhập vào là tháng 1 và ngày 1 thì ngày tháng năm trước đó sẽ là ngày 31 tháng 12 năm trước đó
	else if (month == 1 && day == 1) {
		previous_day = 31;
		previous_year = year - 1;
		previous_month = 12;
	}
	printf("\nNgay truoc do : %d:%d:%d", previous_day, previous_month, previous_year);
}

void ngaytieptheo(int day, int month, int year)
{
	//ta cần khai báo các biến ny, nm, nd là ngày tháng năm tiếp theo
	int next_year = year; int next_month = month; int next_day = day;
	//nếu ngày tháng năm thỏa mãn điều kiện của nó (nghĩa là tháng năm phải lớn hơn 0,....)
	next_day = day + 1;
	//nếu tháng nhập vào không phải tháng 12 và số ngày bằng số ngày tối đa của tháng thì ta tăng tháng lên 1 và ngày = 1
	if (month != 12 && day == songaytrongthang(month, day))
	{
		next_day = 1;
		next_month = month + 1;
	}
	//nếu tháng nhập vào là tháng 12 và số ngày bằng số ngày bằng 31 thì ta tăng tháng, năm lên 1 và ngày sẽ bằng 1
	else if (month == 12 && day == songaytrongthang(month, day))
	{
		next_day = 1;
		next_year = year + 1;
		next_month = 1;
	}
	else if (month == 2)
	{
		//nếu tháng nhập vào là tháng 2 và năm nhuận thì ngày tối đa sẽ là 29
		if (nhuan(year))
		{
			//nếu người dùng nhập vào ngày 29 thì ta tăng tháng lên 1 và ngày bằng 1
			if (day == 29)
			{
				next_day = 1;
				next_month = month + 1;
			}
		}
		//ngược lại nếu tháng 2 và không phải năm nhuận thì tháng 2 có 28 ngày
		else
		{
			//nếu người dùng nhập vào ngày 28 thì tăng tháng lên 1 và ngày bằng 1
			if (day == 28)
			{
				next_day = 1;
				next_month = month + 1;
			}
		}
	}
	printf("\nNgay tiep theo : %d:%d:%d", next_day, next_month, next_year);
}

int main()
{
	int day; int month; int year;
	do
	{
		printf("\nNhap ngay: ");
		scanf_s("%d", &day);
		printf("nNhap thang: ");
		scanf_s("%d", &month);
		printf("nNhap nam: ");
		scanf_s("%d", &year);
	} while (year < 0 || month < 1 || month >12 || day < 0 || day > songaytrongthang(month, year));
	ngaytruocdo(day, month, year);
	ngaytieptheo(day, month, year);
	printf("\n------------------------------------\n");
}
