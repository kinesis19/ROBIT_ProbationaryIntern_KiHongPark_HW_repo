#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�.
	int numAry[4][3] = { 0, };
	int* numList = (int*)calloc(12, sizeof(4)); // �ԷµǴ� ���� �����(stack)
	int i, j;
	int inputNum, nextInput, idxCnt = 0;

	// Debugging: ���� ��.
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", numAry[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	// ���� ����� �ޱ�.
	printf("input : ");
	scanf("%d", &inputNum);
	*(numList + idxCnt) = inputNum;

	// (����) �Է� ���� ���ڷ� �迭 ��ü �����ϱ�.
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			numAry[i][j] = inputNum;
		}
	}

	// Debugging: ���� ����.
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

		// �Է� ���� ���ڷ� �迭 ��ü �����ϱ�.
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				numAry[i][j] = nextInput;
			}
		}

		// Debugging: ���� ����.
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