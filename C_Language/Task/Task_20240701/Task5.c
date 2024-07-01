#include <stdio.h>

int main() {

	// 변수 선언하기
	int number, i, j;

	// 형식 출력하기
	printf("값을 입력하세요.");

	// 값 입력받기
	scanf_s("%d", &number);

	// 알고리즘 구현하기
	for (i = 0; i < number + 2; i++) {
		printf("*");

		for (j = 0; j < number; j++) {
			printf(" ");
		}
	}

	return 0;
}