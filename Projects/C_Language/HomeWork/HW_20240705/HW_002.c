#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _position {

	int posX;
	int posY;
	int posTotal; // 가장 거리가 먼 좌표를 저장하기 위한 변수
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

	// 포인터 개념을 사용하여 동적할당된 값을 구조체에 저장하기 위한 선언.
	Position* position = (int*)malloc(inputNum, sizeof(int));


	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%d %d", &pArrPosX[i], &pArrPosY[i]);
	}

	// 동적할당된 값을 구조체에 대입하기.
	for (i = 0; i < inputNum; i++) {
		position[i].posX = pArrPosX[i];
		position[i].posY = pArrPosY[i];
		position[i].posTotal = (pArrPosX[i] * pArrPosX[i]) + (pArrPosY[i] * pArrPosY[i]);
	}

	// 입력된 좌표 중 가장 멀리 있는 좌표를 찾아내기.
	int highPosX = position[0].posX;
	int highPosY = position[0].posY;
	int highPosTot = position[0].posTotal;
	for (i = 0; i < inputNum; i++) {
		for (int j = 0; j < inputNum; j++) {
			if (highPosTot < position[j].posTotal) {
				highPosX = position[j].posX;
				highPosY = position[j].posY;
				highPosTot = position[j].posTotal;
			}
		}
	}

	// 다른 좌표의 거리 총합 구하기.
	for (i = 0; i < inputNum; i++) {
		printf("%d %d\n\n", position[i].posTotal, highPosTot);
		if (position[i].posTotal != highPosTot) {
			// 두 좌표의 직선 길이 구하기. (루트 값에 제곱근 제거한 상태)
			printf("highPosX:%d, position[%d].posX: %d\nhightPosY: %d, position[%d].posY: %d\n\n", highPosX, i, position[i].posX, highPosY, i, position[i].posY);
			position[i].posTotal = ((highPosX - position[i].posX) * (highPosX - position[i].posX) + (highPosY - position[i].posY) * (highPosY - position[i].posY));
		}
	}
	// Debugging: 제곱근 구하기 (동일한 두 수의 곲)
	for (i = 0; i < inputNum; i++) {
		for (int j = 0; j < inputNum; j++) {
			if (j * j == position[i].posTotal) {
				printf("가장 거리가 먼 좌표와 position[%d].posTotal의 거리에 대한 제곱근은 %d입니다.\n", i, j);
			}
		}
	}



	// Debugging: 동적할당된 값이 구조체에 잘 저장되었는지 출력하기.
	for (i = 0; i < inputNum; i++) {
		printf("%d %d %d\n", position[i].posX, position[i].posY, position[i].posTotal);
	}

	// Debugging: Number는 임시로 출력.
	printf("\n출력 : 가장 거리가 먼 좌표는 (%d, %d)이며, 다른 좌표의 거리 총합은 약 %.1lf입니다.", highPosX, highPosY, 1.0);

	return 0;
}