#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _position {

	int posX;
	int posY;
}Position;


int main() {

	// ���� �����ϱ�.
	int inputNum = 0;
	int i;
	int* pArrPosX = (int*)calloc(inputNum, sizeof(int));
	int* pArrPosY = (int*)calloc(inputNum, sizeof(int));

	printf("�Է� : ");
	scanf("%d", &inputNum);

	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%d %d", &pArrPosX[i], &pArrPosY[i]);
	}

	printf("\n");

	for (i = 0; i < inputNum; i++) {
		printf("       ");
		printf("%d %d\n", pArrPosX[i], pArrPosY[i]);
	}


	return 0;
}