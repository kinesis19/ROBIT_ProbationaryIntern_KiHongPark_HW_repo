#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int number, i, j;

	// ���� ����ϱ�
	printf("���� �Է��ϼ���.");

	// �� �Է¹ޱ�
	scanf_s("%d", &number);

	// �˰��� �����ϱ�
	for (i = 0; i < number + 2; i++) {
		printf("*");

		for (j = 0; j < number; j++) {
			printf(" ");
		}
	}

	return 0;
}