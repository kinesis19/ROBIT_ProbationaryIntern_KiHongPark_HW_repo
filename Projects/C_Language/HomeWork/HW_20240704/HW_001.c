#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기
	int num1, num2, i, j, cnt = 0;

	// 형식 입출력 하기
	printf("입력 : ");
	scanf("%d %d", &num1, &num2);

	
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			cnt++;
			printf("%d ", cnt);
		}
		printf("\n");
	}

}