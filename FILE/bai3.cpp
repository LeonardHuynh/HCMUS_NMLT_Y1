#include <stdio.h>

struct PHANSO {
	int tu;
	int mau;
};

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

int main()
{
  printf("\n3. Doc mot cau truc phan so tu file va xuat phan so ra mot tap tin khac\n");
  PHANSO a;
  const char* fnamei = "input_BT_3.txt";
  const char* fnameo = "output_BT_3.txt";
  bool read_result = Doc_PhanSo(fnamei, a);
  if (read_result == true) {
    printf("Doc file thanh cong!\n");
    bool write_result = Ghi_PhanSo(fnameo, a);
    if (write_result == true) {
      printf("Ghi file thanh cong!\n");
    }
    else {
      printf("Ghi file that bai!\n");
    }
  }
  else {
    printf("Doc file that bai!\n");
  }
  return 0;
}
