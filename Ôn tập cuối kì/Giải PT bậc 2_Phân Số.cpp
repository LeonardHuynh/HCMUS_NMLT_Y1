// Định nghĩa cấu trúc phân số:
typedef struct PHANSO {
	int tu;
	int mau;
} PS;
//Như vậy một phân số A sẽ được khai báo nhưu sau:
PS A;

//Hàm giải phương trình bậc 2:

int GiaiPT_Bac2(PS a, PS b, PS c, PSN &x1, PSN &x2) {
	PS zero = {0, 0};
	if (SoSanh(a, zero) == 0) { // Phân số a có giá trị bằng 0
		GiaiPT_Bac1(b, c, PSN &x1);
		return 1;
	}
	PS Delta = TinhDelta (a, b, c);
	if (SoSanh(Delta, zero) == -1) { //Phân số Delta có giá trị nhỏ hơn 0
		return 0; //Phương trình vô nghiệm
	}
	if (SoSanh(Delta, zero) == 0) { //Phân số Delta có giá trị bằng 0
		x1 = ChiaPS(b,a); //x1 = b/a
		PS Am1_2 = {-1, 2}; //Phân số -1/2 
		x1 = NhanPS (x1, Am1_2); // x1 = -b/2a
		return 1; //Phương trình có nghiệm
	}
	x1 = TinhNghiem(b, Delta, a); 
	PS Duongc_a = ChiaPS(c,a); //Phân số c/a
	x2 = ChiaPS(Duongc_a, x1); //x2 = (c/a)/(x1)
	return 1; //Phương trình có nghiệm
}  

//Trong đó kiểu cấu trúc nghiệm là PSN được định nghĩa:
typedef struct PHANSONGHIEM {
	int b; 
	int Delta;
	int a;
} PSN;
//Trong đó các số b, Delta, a được biểu diễn: (b + sqrt(Delta))/2a 

//Hàm so sánh hai phân số: 
int SoSanhPS (PS A, PS B) {
	RutGon(A);
	RutGon(B);
	if (A.tu*B.mau == A.mau*B.tu) {
		return 0; //Hai phân số bằng nhau
	}
	if (A.tu*B.mau > A.mau*B.tu) {
		return 1; //Phấn số A lớn hơn phân số B
	}
	return -1; //Trường hợp duy nhất còn lại là phân số A bé hơn phân số B
}

//Hàm tính UCLN: 
int GCD(int a, int b) { //Hàm tìm UCLN
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		if (b > a) {
			a = b - a;
		}
	}
	return a;
}

//Hàm rút gọn phân số:
void RutGon (PHANSO& A) { //Hàm rút gọn phân số
	int UCLN = GCD(A.tu, A.mau);
	A.tu /= UCLN;
	A.mau /= UCLN;
}	

//Hàm chia 2 phân số:
PS ChiaPS(PS A, PS B) {
	PS Thuong;
	Thuong.tu = A.tu*B.mau;
	Thuong.mau = A.mau*B.tu;
	return Thuong;
}

//Hàm nhân 2 phân số:
PHANSO NhanPS (PS A, PS B) { //Hàm tính tích 2 phân số 
	PS tich;
	tich.tu = A.tu*B.tu;
	tich.mau = A.mau*B.mau;
	RutGon(tich);
	return tich;
}

//Hàm tính hiệu 2 phân số:
PS TruPS (PS A, PS B) { //Hàm tính hiệu 2 phân số
	PS hieu;
	hieu.tu = A.tu*B.mau - A.mau*B.tu;
	hieu.mau = A.mau*B.mau;
	RutGon(hieu);
	return hieu;
}

//Hàm tính Delta:
PS TinhDelta (PS a, PS b, PS c) {
	return TruPS(NhanPS(b,b), NhanPS(NhanPS(a,c),Duong4_1));
}
//Trong đó phân số Duong4_1 là một biến toàn cục được định nghĩa:
PS Duong4_1 = {4, 1};

//Hàm giải phương trình bậc 1 có phần khai báo prototype như sau:
void GiaiPT_Bac1(PS a, PS b, PSN &x1);
//Với a, b có vị trí như trong phương trinh ax = b;
//Hàm trả về kiểu PSN được định nghĩa như trên, giá trị đó là nghiệm của phương trình bậc 1

//Hàm tính nghiệm của phương trình bậc 2 có prototype như sau:
PSN TinhNghiem(PS b, Delta, PS a);
//Trong đó, b là hệ số của x^1 trong phương trình bậc 2, a là hệ số của x^2 trong phương trình bậc 2.
//Hàm trả về kiểu giá trị PSN như được định nghĩa ở trên, giá trị này chính là nghiệm của phương trình bậc 2 có dạng (b + sqrt(Delta))/2a

