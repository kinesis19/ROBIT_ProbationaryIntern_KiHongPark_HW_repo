#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	Position* position = (int*)malloc(inputNum, sizeof(int));


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

	// �ٸ� ��ǥ�� �Ÿ� ���� ���ϱ�.
	for (i = 0; i < inputNum; i++) {
		printf("%d %d\n\n", position[i].posTotal, highPosTot);
		if (position[i].posTotal != highPosTot) {
			// �� ��ǥ�� ���� ���� ���ϱ�. (��Ʈ ���� ������ ������ ����)
			printf("highPosX:%d, position[%d].posX: %d\nhightPosY: %d, position[%d].posY: %d\n\n", highPosX, i, position[i].posX, highPosY, i, position[i].posY);
			position[i].posTotal = ((highPosX - position[i].posX) * (highPosX - position[i].posX) + (highPosY - position[i].posY) * (highPosY - position[i].posY));
		}
	}
	// Debugging: ������ ���ϱ� (������ �� ���� ��)
	for (i = 0; i < inputNum; i++) {
		for (int j = 0; j < inputNum; j++) {
			if (j * j == position[i].posTotal) {
				printf("���� �Ÿ��� �� ��ǥ�� position[%d].posTotal�� �Ÿ��� ���� �������� %d�Դϴ�.\n", i, j);
			}
		}
	}



	// Debugging: �����Ҵ�� ���� ����ü�� �� ����Ǿ����� ����ϱ�.
	for (i = 0; i < inputNum; i++) {
		printf("%d %d %d\n", position[i].posX, position[i].posY, position[i].posTotal);
	}

	// Debugging: Number�� �ӽ÷� ���.
	printf("\n��� : ���� �Ÿ��� �� ��ǥ�� (%d, %d)�̸�, �ٸ� ��ǥ�� �Ÿ� ������ �� %.1lf�Դϴ�.", highPosX, highPosY, 1.0);

	return 0;
}