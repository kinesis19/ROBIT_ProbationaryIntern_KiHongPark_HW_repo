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
	for (i = 0; i < inputNum; i++) {
		for (int j = 0; j < inputNum; j++) {
			if (position[i].posTotal < position[j].posTotal) {
				highPosX = position[j].posX;
				highPosY = position[j].posY;
			}
		}
	}

	

	// Debugging: 동적할당된 값이 구조체에 잘 저장되었는지 출력하기.
	for (i = 0; i < inputNum; i++) {
		/*printf("%d %d\n", position[i].posX, position[i].posY);*/
		printf("%d %d %d\n", position[i].posX, position[i].posY, position[i].posTotal);
	}

	// Debugging: Number는 임시로 출력.
	printf("\n출력 : 가장 거리가 먼 좌표는 (%d, %d)이며, 다른 좌표의 거리 총합은 약 %d입니다.", highPosX, highPosY, 1);

	return 0;
}