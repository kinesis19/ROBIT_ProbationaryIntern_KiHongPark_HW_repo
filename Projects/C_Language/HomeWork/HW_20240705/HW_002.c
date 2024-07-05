#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _position {

	int posX;
	int posY;
}Position;


int main() {

	// 변수 생성하기.
	int inputNum = 0;
	int i;

	// 형식 입출력받기.
	printf("입력 : ");
	scanf("%d", &inputNum);

	int* pArrPosX = (int*)calloc(inputNum, sizeof(int));
	int* pArrPosY = (int*)calloc(inputNum, sizeof(int));

	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%d %d", &pArrPosX[i], &pArrPosY[i]);
	}
	
	for (i = 0; i < inputNum; i++) {
		Position position = { pArrPosX[i], pArrPosY[i] };
	}

	for (i = 0; i < inputNum; i++) {

	}

	printf("\n출력 : 가장 거리가 먼 좌표는 (%d, %d)이며, 다른 좌표의 거리 총합은 약 %d입니다.", 1, 1, 1);




	return 0;
}