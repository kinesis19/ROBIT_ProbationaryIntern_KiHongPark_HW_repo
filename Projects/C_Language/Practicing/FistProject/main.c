#include <stdio.h>

int main() {

	int input;
	printf("����� �Է��ϼ���.\n");
	scanf_s("%d", &input);

	if (input % 2 == 0) {
		printf("�Է��� �� %d�� ¦���Դϴ�.\n", input);
	}else{
		printf("�Է��� �� %d�� Ȧ���Դϴ�.\n", input);
	}

	return 0;
}