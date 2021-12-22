// FUCNTION
// 1.Kiểm tra một số có phải là só chính phương hay không?
bool kiem_tra_so_chinh_phuong(int a)
{
	int can_bac_hai = sqrt(a);
	if (can_bac_hai * can_bac_hai == a)
	{
    return true;
	}
	return false;
}

// 2.Hoán vị 2 số thực:
void hoan_vi(float& a, float& b)
{
	float tg = a;
	a = b;
	b = tg;
}

// 3.Kiểm tra một số có phải là số chẵn? 
bool Ktra_SoChan(int a) { 
  if (a % 2 == 0) { 
    return true; // Nếu kiểm tra số lẻ thì ngược lại
  }
  return false;
}

// 4.Kiểm tra số toàn số lẻ: 
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


// 5.Tìm chữ số lẻ đầu tiền của số n:
int tim_chu_so_le_dau_tien(int n)
{
	int ket_qua = 0;
	do
	{
		if ((n % 10) % 2 != 0)
		{
			ket_qua = n % 10;
		}
	} while (n /= 10);
	return ket_qua; 
}

// 6.Kiểm tra một số chính phương
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

// 7.Kiểm tra một số nguyên tố:
bool KiemTraSoNguyenTo(int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else
	{
		for (int i = 2; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

// 8. Kiểm tra số đối xứng:
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

bool KiemTraSoDoiXung(int n)
{
	if (DaoNguocSo(n) == n)
		return true;
	else
		return false;
}

// 9.Kiểm tra số hoàn chỉnh:
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

//ARRAY 1D:
// 10.Nhập, xuất mảng số thực:
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

// 11.Hệ 10 --> Hệ 2 (có dấu):
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

// 12.Hệ 2 --> Hệ 10 (có dấu):
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

// 13.Dồn những phần tử là ước số của X về cuối mảng. Sắp xếp các phần tử không phải là ước số
//của X theo thứ tự tăng dần (giữ nguyên vị trí các phần tử là ước số của X):
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

// 14.Đếm số nguyên tố phân biệt:
int Dem_SoNgto_Phanbiet(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoNguyenTo(a[i]) == true)
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

// 15.Xóa những số nguyên tố trong mảng A:
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

// 16.Ghép A, B thành C sao cho C không có phần tử trùng nhau:
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

//ARRAY 2D:
// 17.Nhập, xuất mảng 2D:
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

// 18. Tìm số lớn nhất trên biên:
int Tim_SoLonNhat_TrenBien(int a[][MAX_COLS], int rows, int cols)
{
	int max = a[0][0];
	for (int i = 0; i < rows; i++) //Lấy phần tử 2 bên mảng
	{
		if (max < a[i][0])
			max = a[i][0];
		if (max < a[i][cols - 1])
			max = a[i][cols - 1];
	}
	for (int j = 1; j < cols - 1; j++) //Lấy phần tử ở dòng đầu và cuối
	{
		if (max < a[0][j])
			max = a[0][j];
		if (max < a[rows - 1][j])
			max = a[rows - 1][j];
	}
	return max;
}

// 19. Liệt kê các dòng chứa toàn giá trị chẵn:
void LietKe_Dong_ToanSoChan(int a[][MAX_COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		int check = 1;
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			printf("%d ", i + 1);
		}
	}
}








