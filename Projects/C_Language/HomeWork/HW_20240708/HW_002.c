#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 선언하기.
	int numAry[4][3] = { 0, };
	int* numList = (int*)calloc(12, sizeof(4)); // 입력되는 숫자 저장용(stack)
	int i, j;
	int inputNum, nextInput, idxCnt = 0;

	// Debugging: 변경 전.
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", numAry[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	// 형식 입출력 받기.
	printf("input : ");
	scanf("%d", &inputNum);
	*(numList + idxCnt) = inputNum;

	// (최초) 입력 받은 숫자로 배열 전체 지정하기.
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			numAry[i][j] = inputNum;
		}
	}

	// Debugging: 변경 이후.
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", numAry[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	while (1){

		printf("next input : ");
		scanf("%d", &nextInput);
		idxCnt++;
		*(numList + idxCnt) = nextInput;

		// 입력 받은 숫자로 배열 전체 지정하기.
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				numAry[i][j] = nextInput;
			}
		}

		// Debugging: 변경 이후.
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				printf("%d ", numAry[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	}

	return 0;
}