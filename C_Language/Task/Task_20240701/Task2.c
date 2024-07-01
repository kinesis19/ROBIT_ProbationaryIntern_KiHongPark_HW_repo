#include <stdio.h>

int main(void) {

	// 변수 선언하기
	int num, leftNum = 0, rightNum = 1, nowNum = 1;
	int i;

	// 형식 출력하기
	printf("n값을 입력하시오. ");
	scanf_s("%d", &num);

	printf("%d %d %d ", leftNum, nowNum, rightNum);

	// 피보나치 수열 구하기
	for (i = 0; i < num; i++) {
		leftNum = nowNum;
		nowNum = rightNum;
		rightNum = nowNum + leftNum;

		printf("%d ", rightNum);

	}


	return 0;
}
