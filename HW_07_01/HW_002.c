#include <stdio.h>

int main(void) {

	// 변수 선언하기
	int num, leftNum = 0, rightNum = 1, nowNum = 1;
	int i;

	// 형식 출력하기
	printf("n 입력 : ");
	scanf_s("%d", &num);

	printf("계산 과정 : ");
	// 피보나치 기본 수 표시
	printf("%d %d %d ", leftNum, nowNum, rightNum);

	// 피보나치 수열 구하기
	for (i = 0; i < num; i++) {
		leftNum = nowNum;
		nowNum = rightNum;
		rightNum = nowNum + leftNum;

		printf("%d ", rightNum); // 계산 과정 출력하기

	}

	printf("\nn번째 피보나치 값 : %d ", rightNum);


	return 0;
}
