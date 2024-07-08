#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�.
	int numAry[3][4] = { 0, };
	int* numList = (int*)calloc(12, sizeof(4)); // �ԷµǴ� ���� �����(stack)
	int i, j;
	/*
	* idxCnt : �Է¹��� ���ڸ� numList�� ���� �ֱ� ����.
	* idxCirculation : numAry�� numList�� ��Ҹ� ��ȯ�Ͽ� ä�� �ֱ� ����.
	*/
	int inputNum, nextInput, idxCnt = 0, idxCirculation = 0;

	// ���� ����� �ޱ�.
	printf("input : ");
	scanf("%d", &inputNum);
	if (inputNum == 0) { // �Է� ���� 0�̸� ���α׷� �����ϱ�.
		printf("���α׷��� �����մϴ�.");
		return 0;
	}
	*(numList + idxCnt) = inputNum;

	// (����) �Է� ���� ���ڷ� �迭 ��ü �����ϱ�.
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			numAry[i][j] = inputNum;
		}
	}
	// (����) �Է� ���� ���� ����ϱ�.
	// �Է� ���� ���ڷ� �迭 ��ü ���� �� ����ϱ�.
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
		if (nextInput == 0) { // �Է� ���� 0�̸� ���α׷� �����ϱ�.
			printf("���α׷��� �����մϴ�.");
			return 0;
		}
		idxCnt++;
		*(numList + idxCnt) = nextInput;

		// �Է� ���� ���ڷ� �迭 ��ü ���� �� ����ϱ�.
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