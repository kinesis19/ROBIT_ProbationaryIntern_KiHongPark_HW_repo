#include <stdio.h>

int main() {

	// 변수 선언하기
	int number, i, j, paddingLeftRight, paddingMiddle, 
		cnt = 0;
	
	// 형식 출력하기
	printf("값을 입력하세요. ");
	scanf_s("%d", &number);

	// Padding 설정하기
	paddingLeftRight = number - 1;
	paddingMiddle = 0;

	for (i = 0; i < number; i++) {
		for (j = 0; j <= paddingLeftRight; j++) {
			printf(" ");
		}
		for () {
			printf("*");
		}
		for (j = 0; j < paddingMiddle; j++) {
			printf(" ");
		}

		paddingLeftRight -= 1;
		paddingMiddle++;
		printf("\n");
	}


	return 0;
}