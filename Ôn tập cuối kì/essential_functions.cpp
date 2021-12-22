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

// 19.Liệt kê các dòng chứa toàn giá trị chẵn:
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

// 20.Kiểm tra một phần từ là cực trị trong ma trận:
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

// 21. Tìm chữ số xuất hiện nhiều nhât trong ma trận:
void Tach_ChuSo(int n, int b[])
{
	int ChuSo;
	while (n > 0)
	{
		ChuSo = n % 10;
		b[ChuSo]++;
		n /= 10;
	}
}

int Tim_ChuSo_XuatHienNhieuNhat(int a[][MAX_COLS], int rows, int cols)
{
	int b[10] = { 0 };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Tach_ChuSo(a[i][j], b);
		}
	}
	int ChuSo_XuatHienNhieuNhat = 0; 
	for (int i = 0; i < 10; i++)
	{
		if (b[ChuSo_XuatHienNhieuNhat] < b[i])
			ChuSo_XuatHienNhieuNhat = i;
	}
	return ChuSo_XuatHienNhieuNhat;
}

// 22.Sắp xếp phần tử biên tăng dần theo chiều kim đồng hồ:
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

//STRUCT:
//23.Phân số:
struct PHANSO {
	int tu;
	int mau;
};

void Nhap_PS(PHANSO& ps) {
	printf("Tu so: ");
	scanf_s("%d", &ps.tu);
	do {
		printf("Mau so: ");
		scanf_s("%d", &ps.mau);
		if (ps.mau == 0) {
			printf("Mau so khong hop le!");
		}
	} while (ps.mau == 0);
}

void Xuat_PS(PHANSO ps) {
	printf("%d/%d", ps.tu, ps.mau);
}

int Tinh_UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

void RutGon_PS(PHANSO& ps) {
	int UCLN = Tinh_UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / UCLN;
	ps.mau = ps.mau / UCLN;
}

PHANSO Tong_PS(PHANSO a, PHANSO b) {
	PHANSO tong;
	tong.tu = a.tu * b.mau + a.mau * b.tu;
	tong.mau = a.mau * b.mau;
	RutGon_PS(tong);
	return tong;
}

PHANSO Hieu_PS(PHANSO a, PHANSO b) {
	PHANSO hieu;
	hieu.tu = a.tu * b.mau - a.mau * b.tu;
	hieu.mau = a.mau * b.mau;
	RutGon_PS(hieu);
	return hieu;
}

PHANSO Tich_PS(PHANSO a, PHANSO b) {
	PHANSO tich;
	tich.tu = a.tu * b.tu;
	tich.mau = a.mau * b.mau;
	RutGon_PS(tich);
	return tich;
}

PHANSO Thuong_PS(PHANSO a, PHANSO b) {
	PHANSO thuong;
	thuong.tu = a.tu * b.mau;
	thuong.mau = a.mau * b.tu;
	RutGon_PS(thuong);
	return thuong;
}

int SoSanh_PS(PHANSO a, PHANSO b) {
	if (a.tu * b.mau > a.mau * b.tu) {
		return 1;
	}
	else if (a.tu * b.mau == a.mau * b.tu) {
		return 0;
	}
	else {
		return -1;
	}
}
// 24.Dãy phân số:
PHANSO Tong_DayPS(PHANSO a[], int n) {
	PHANSO tong;
	tong.tu = a[0].tu; tong.mau = a[0].mau;
	for (int i = 1; i < n; i++) {
		tong = Tong_PS(tong, a[i]);
	}
	return tong;
}

// 25.Kiểm tra điểm D nằm trong tam giác:
int KiemTra_ViTri(DIEM2D A, DIEM2D B, DIEM2D C, DIEM2D D) {
	double dientichABD = Tinh_DienTich(A, B, D);
	double dientichACD = Tinh_DienTich(A, C, D);
	double dientichBCD = Tinh_DienTich(B, C, D);
	double dientichABC = Tinh_DienTich(A, B, C);
	double d = (dientichABD + dientichACD + dientichBCD) - dientichABC;
	printf("dientichABD = %lf\n", dientichABD);
	printf("dientichACD = %lf\n", dientichACD);
	printf("dientichBCD = %lf\n", dientichBCD);
	printf("dientichABC = %lf\n", dientichABC);
	if (d > 0) {
		return 0;
	}
	else
	{
		return 1;
	}
}

//STRING:
// 26. Hàm xóa buffer thay fflush():
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} 
}

// 27. Xuất 1 từ 1 dòng - Dùng strtok():
void xuat_1tu1dong(char a[])
{
	char* piece = strtok(a, " "); 
	while (piece != NULL)
	{
		printf("%s\n", piece);
		piece = strtok(NULL, " ");
	}
}

// 28.Xuất vị trí xuất hiện chuỗi con:
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

// 29.Đảo chuỗi:
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

// 30. Viết hoa kí tự đầu:
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

// 31. Loại bỏ khoảng trắng:
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

// FILE:
// 32. Đọc, ghi phân số:
bool Doc_PhanSo(const char* fname, PHANSO& a) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "rt");
	if (f == NULL) {
		return false;
	}
	fscanf_s(f, "%d/%d", &a.tu, &a.mau);
	fclose(f);
	return true;
}

bool Ghi_PhanSo(const char* fname, PHANSO a) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "wt");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "%d/%d", a.tu, a.mau);
	fclose(f);
	return true;
}




