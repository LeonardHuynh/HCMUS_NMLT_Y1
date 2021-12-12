#include <stdio.h>
 
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void RPS(char nguoi1, char nguoi2) {
	if (nguoi1 == 'r') {
		if (nguoi2 == 'R') {
			printf("Hoa\n");
		}
		else if (nguoi2 == 'P') {
			printf("Nguoi choi 1 thang\n");
		}
		else {
			printf("Nguoi choi 1 thang\n");
		}
	}

	if (nguoi1 == 'p') {
		if (nguoi2 == 'R') {
			printf("Nguoi choi 2 thang\n");
		}
		else if (nguoi2 == 'P') {
			printf("Hoa\n");
		}
		else {
			printf("Nguoi choi 2 thang\n");
		}
	}

	if (nguoi1 == 's') {
		if (nguoi2 == 'R') {
			printf("Nguoi choi 2 thang\n");
		}
		else if (nguoi2 == 'P') {
			printf("Nguoi choi 1 thang\n");
		}
		else {
			printf("Hoa\n");
		}
	}
}

int main()
{
	char nguoi1, nguoi2;
	printf("Nguoi choi 1: ");
	scanf_s("%c", &nguoi1);
	clear();
	printf("Nguoi choi 2: ");
	scanf_s("%c", &nguoi2);
	RPS(nguoi1, nguoi2);
	return 0;
}
