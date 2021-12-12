#include <stdio.h>

struct PHANSO {
	int tu;
	int mau;
};

bool Doc_SoNguyenDuong(const char* fname, int a[]) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "rt");
	if (f == NULL) {
		return false;
	}
	for (int i = 0; i < 2; i++) {
		fscanf_s(f, "%d ", &a[i]);
	}
	fclose(f);
	return true;
}

bool KTra_SoNguyenTo(int n) {
	if (n < 2) {
		return false;
	}
	else if (n == 2) {
		return true;
	}
	else {
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}

bool Ghi_SoNguyenTo(const char* fname, int a[]) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "wt");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "Cac so nguyen to trong doan [%d,%d] la: ", a[0], a[1]);
	for (int i = a[0]; i <= a[1]; i++) {
		if (KTra_SoNguyenTo(i) == true) {
			fprintf(f, "%d ", i);
		}
	}
	fclose(f);
	return true;
}

int main()
{
  printf("\n1. Doc file chua 2 so nguyen duong M N va ghi cac so nguyen to trong khoang M N ra tap tin output.txt\n");
  int a[2];
  const char* fnamei = "input_BT_1.txt";
  const char* fnameo = "output_BT_1.txt";
  bool read_result = Doc_SoNguyenDuong(fnamei, a);
  if (read_result == true) {
    printf("Doc file thanh cong!\n");
    bool write_result = Ghi_SoNguyenTo(fnameo, a);
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
