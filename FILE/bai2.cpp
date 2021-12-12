#include <stdio.h>

bool Doc_MaTran(const char* fname, int a[][10], int& rows, int& cols) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "rt");
	if (f == NULL) {
		return false;
	}
	fscanf_s(f, "%d %d", &rows, &cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fscanf_s(f, "%d ", &a[i][j]);
		}
		fscanf_s(f, "\n");
	}
	fclose(f);
	return true;
}

bool Ghi_Matran(const char* fname, int a[][10], int rows, int cols) {
	FILE* f;
	errno_t errorcheck = fopen_s(&f, fname, "wt");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "%d %d\n", rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(f, "%d ", a[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return true;
}

int main()
{
	printf("\n2. Doc ma tran tu file va xuat noi dung ghi duoc vao mot tap tin khac\n");
  int a[10][10];
  int rows, cols;
  const char* fnamei = "input_BT_2.txt";
  const char* fnameo = "output_BT_2.txt";
  bool read_result = Doc_MaTran(fnamei, a, rows, cols);
  if (read_result == true) {
  	printf("Doc file thanh cong!\n");
    bool write_result = Ghi_Matran(fnameo, a, rows, cols);
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
