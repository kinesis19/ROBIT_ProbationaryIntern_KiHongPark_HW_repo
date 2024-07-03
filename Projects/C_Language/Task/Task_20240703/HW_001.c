#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기.
	int min = 0, max = 0, squareCnt = 0;
	// 제곱 ㄴㄴ수를 담는 배열.
	int squareNumAry[10000] = { 1, 0, };
	int i;

	// 형식 출력하기.
	printf("%min : ");
	scanf("%d", &min);
	printf("%max : ");
	scanf("%d", &max);
	printf("%제곱 ㄴㄴ수 : %d개\n", squareCnt);

	for (i = 0; i < 10000; i++) {
		if (squareNumAry[i] == 0) {
			break;
		}else{
			printf("%d ", squareNumAry[i]);
		}
	}

	return 0;
}