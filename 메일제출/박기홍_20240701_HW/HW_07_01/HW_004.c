#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// ���� �����ϱ�
	double num1 = 0, num2 = 0, result = 1;
	char operator;
	int i;

	// ���� ����ϱ�
	printf("Input Arithmetic Operation\n");
	printf("ex)     3.4 * 8.5\n");
	printf("        2.9 - 5.4\n");
	printf("        3.9 * 8.0\n");
	printf("        3.9 ^ 8\n");
	printf("input : ");

	// �Է� �ޱ�
	scanf("%lf %c %lf", &num1, &operator, &num2);

	// �����ϱ�
	if (operator == '+') {
		result = num1 + num2;
	}else if (operator == '-') {
		result = num1 - num2;
	}else if (operator == '*') {
		result = num1 * num2;
	}else if (operator == '/') {
		// ���� ó��
		if (num2 == 0) {
			printf("0���� ���� �� �����ϴ�.");
			return 0;
		}else{
			result = num1 / num2;
		}
	}else if (operator == '^') {
		for (i = 0; i < num2; i++) {
			result = result * num1;
		}
	}

	printf("%.2lf %c %.2lf = %.2lf", num1, operator, num2, result);

	return 0;
}