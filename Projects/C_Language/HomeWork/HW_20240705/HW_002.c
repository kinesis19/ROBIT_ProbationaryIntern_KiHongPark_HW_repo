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
	
	/*for (i = 0; i < inputNum; i++) {
		for (int j = 0; j < inputNum; j++) {

		}
	}*/

	

	// Debugging: �����Ҵ�� ���� ����ü�� �� ����Ǿ����� ����ϱ�.
	for (i = 0; i < inputNum; i++) {
		printf("%d %d %d\n", position[i].posX, position[i].posY, position[i].posTotal);
	}

	// Debugging: Number�� �ӽ÷� ���.
	printf("\n��� : ���� �Ÿ��� �� ��ǥ�� (%d, %d)�̸�, �ٸ� ��ǥ�� �Ÿ� ������ �� %d�Դϴ�.", 1, 1, 1);

	free(position);

	return 0;
}