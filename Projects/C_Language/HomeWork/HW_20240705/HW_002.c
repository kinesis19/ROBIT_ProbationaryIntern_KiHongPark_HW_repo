#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _position {

	int posX;
	int posY;
	int posTotal; // ���� �Ÿ��� �� ��ǥ�� �����ϱ� ���� ����
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

	// ������ ������ ����Ͽ� �����Ҵ�� ���� ����ü�� �����ϱ� ���� ����.
	Position* position = calloc(inputNum, sizeof(Position));


	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%d %d", &pArrPosX[i], &pArrPosY[i]);
	}

	// �����Ҵ�� ���� ����ü�� �����ϱ�.
	for (i = 0; i < inputNum; i++) {
		position[i].posX = pArrPosX[i];
		position[i].posY = pArrPosY[i];
		position[i].posTotal = (pArrPosX[i] * pArrPosX[i]) + (pArrPosY[i] * pArrPosY[i]);
	}

	// �Էµ� ��ǥ �� ���� �ָ� �ִ� ��ǥ�� ã�Ƴ���.
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

	double distance = 0.0;
	// �ٸ� ��ǥ�� �Ÿ� ���� ���ϱ�.
	for (i = 0; i < inputNum; i++) {
		if (position[i].posTotal != highPosTot) {
			position[i].posTotal = ((highPosX - position[i].posX) * (highPosX - position[i].posX) + (highPosY - position[i].posY) * (highPosY - position[i].posY));
			distance = distance + sqrt((double)position[i].posTotal);
		}
	}

	// Debugging: Number�� �ӽ÷� ���.
	printf("\n��� : ���� �Ÿ��� �� ��ǥ�� (%d, %d)�̸�, �ٸ� ��ǥ�� �Ÿ� ������ �� %.1lf�Դϴ�.", highPosX, highPosY, distance);

	free(pArrPosX);
	free(pArrPosY);
	free(position);

	return 0;
}