#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int number, i, j,k, cnt;
	
	// ���� ����ϱ�
	printf("���� �Է��ϼ���. ");
	scanf_s("%d", &number);

	int tempNum = number;
	int star = 1;

	// Ʈ�� �����ϴ� �˰���
	for (i = 0; i < number; i++) {
		for (k = 0; k < ((number * 2) - star) / 2; k++) {
			printf(" ");
		}
		for (j = 0; j < star; j++) {
			printf("*");
		}
		for (k = 0; k < number - star; k++) {
			printf(" ");
		}
		star = star + 2;
		printf("\n");
	}


	return 0;
}