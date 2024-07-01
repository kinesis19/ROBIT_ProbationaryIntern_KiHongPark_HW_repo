#include <stdio.h>

int main() {

	// 변수 선언하기
	int number, i, j,k, cnt;
	
	// 형식 출력하기
	printf("값을 입력하세요. ");
	scanf_s("%d", &number);

	int tempNum = number;
	int star = 1;

	// 트리 구현하는 알고리즘
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