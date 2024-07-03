#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// 변수 선언하기
	double num1 = 0, num2 = 0, result = 1;
	char operator;
	int i;

	// 형식 출력하기
	printf("Input Arithmetic Operation\n");
	printf("ex)     3.4 * 8.5\n");
	printf("        2.9 - 5.4\n");
	printf("        3.9 * 8.0\n");
	printf("        3.9 ^ 8\n");
	printf("input : ");

	// 입력 받기
	scanf("%lf %c %lf", &num1, &operator, &num2);

	// 연산하기
	if (operator == '+') {
		result = num1 + num2;
	}else if (operator == '-') {
		result = num1 - num2;
	}else if (operator == '*') {
		result = num1 * num2;
	}else if (operator == '/') {
		// 예외 처리
		if (num2 == 0) {
			printf("0으로 나눌 수 없습니다.");
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