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

	// ���� ����¹ޱ�.
	printf("�Է� : ");
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

	printf("\n��� : ���� �Ÿ��� �� ��ǥ�� (%d, %d)�̸�, �ٸ� ��ǥ�� �Ÿ� ������ �� %d�Դϴ�.", 1, 1, 1);




	return 0;
}