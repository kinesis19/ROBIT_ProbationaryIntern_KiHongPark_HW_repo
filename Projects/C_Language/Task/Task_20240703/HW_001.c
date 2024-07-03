#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기.
	int min = 0, max = 0, squareCnt = 0;
	// 제곱 ㄴㄴ수를 담는 배열.
	int squareNumAry[10000] = { 0, };
	int i, j, isSquare = 0;

	// 형식 출력하기.
	printf("%min : ");
	scanf("%d", &min);
	printf("%max : ");
	scanf("%d", &max);

	// 제곱 ㄴㄴ수 구하기
	/*
	* 추정하는 공식 : (어떤 수 X) % (제곱 수) != 0->제곱 ㄴㄴ수.
	* 어떤 수 X : min이상 ~ max 이하의 모든 수.
	* 제곱 수 : 4, 9, 16 ~~~.
	*/ 

	for (i = min; i <= max; i++) {
		// 임의의 제곱 수 선언
		int tempSquareNum = 0;
		for (j = 2; j < 10000; j++) {
			tempSquareNum = j * j;
			// 제곱 ㄴㄴ수가 아니라면
			if (i % tempSquareNum == 0) {
				isSquare = 0;
				break;
			}else{
				isSquare = 1;
			}
			// 제곱 수 증가 공식
		}
		if (isSquare == 1) {
			squareNumAry[squareCnt] = i;
			// 제곱 ㄴㄴ수가 배열에 포함되면 해당 배열의 index 값 증가시키기.
			squareCnt++;
		}
		isSquare = 0;
	}



	printf("%제곱 ㄴㄴ수 : %d개\n", squareCnt);


	// 제곱 ㄴㄴ수가 담긴 배열을 출력하기
	for (i = 0; i < 10000; i++) {
		if (squareNumAry[i] == 0) {
			break;
		}else{
			printf("%d ", squareNumAry[i]);
		}
	}

	return 0;
}