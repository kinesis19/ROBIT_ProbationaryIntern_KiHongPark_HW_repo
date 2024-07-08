#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 선언하기.
	int numAry[3][4] = { 0, };
	int* numList = (int*)calloc(12, sizeof(4)); // 입력되는 숫자 저장용(stack)
	int i, j;
	/*
	* idxCnt : 입력받은 숫자를 numList에 집어 넣기 위함.
	* idxCirculation : numAry에 numList의 요소를 순환하여 채워 넣기 위함.
	*/
	int inputNum, nextInput, idxCnt = 0, idxCirculation = 0;

	// 형식 입출력 받기.
	printf("input : ");
	scanf("%d", &inputNum);
	if (inputNum == 0) { // 입력 값이 0이면 프로그램 종료하기.
		printf("프로그램을 종료합니다.");
		return 0;
	}
	*(numList + idxCnt) = inputNum;

	// (최초) 입력 받은 숫자로 배열 전체 지정하기.
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			numAry[i][j] = inputNum;
		}
	}
	// (최초) 입력 받은 숫자 출력하기.
	// 입력 받은 숫자로 배열 전체 지정 및 출력하기.
	printf("\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			numAry[i][j] = *(numList + idxCirculation);
			if (*(numList + idxCirculation) == 0) {
				idxCirculation = 0;
				numAry[i][j] = *(numList + idxCirculation);
				idxCirculation++;
			}else {
				idxCirculation++;
			}
			printf("%d ", numAry[i][j]);
		}
		printf("\n");
	}

	idxCirculation = 0;

	while (1){

		printf("\nnext input : ");
		scanf("%d", &nextInput);
		if (nextInput == 0) { // 입력 값이 0이면 프로그램 종료하기.
			printf("프로그램을 종료합니다.");
			return 0;
		}
		idxCnt++;
		*(numList + idxCnt) = nextInput;

		// 입력 받은 숫자로 배열 전체 지정 및 출력하기.
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				numAry[i][j] = *(numList + idxCirculation);
				if (*(numList + idxCirculation) == 0) {
					idxCirculation = 0;
					numAry[i][j] = *(numList + idxCirculation);
					idxCirculation++;
				}else{
					idxCirculation++;
				}
				printf("%d ", numAry[i][j]);
			}
			printf("\n");
		}
		idxCirculation = 0;
		printf("\n\n");

	}

	free(numList);

	return 0;
}