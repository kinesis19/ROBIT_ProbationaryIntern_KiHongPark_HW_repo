#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	// ���� �����ϱ�
	int numAry[8] = { 0, };
	int i, j, k;
	int maxNum = 0, aryIndex = 7;

	printf("�Է�\n");

	for (i = 0; i < 8; i++) {
		printf("%d : ", i);
		scanf("%d", &numAry[i]);
	}

	// ���� ��� (���� ��)
	printf("\n��� ����\n");
	for (k = 0; k < 8; k++) {
		printf("%d ", numAry[k]);
	}
	printf("\n");

	// �ִ� �����ϱ�
	for (i = 7; i >= 0; i--) {
		maxNum = numAry[i]; // �ִ� �ӽ� ����
		
		// �ٸ� �� ���ϱ�
		for (j = i - 1; j >= 0; j--) {
			if (maxNum < numAry[j]) {
				// �ִ� �����ϱ�
				maxNum = numAry[j];

				// �ִ� �ε��� ��ġ �����ϱ�
				int tempNum1 = 0;
				int tempNum2 = 0;

				tempNum1 = numAry[j];
				tempNum2 = numAry[aryIndex];
				numAry[aryIndex] = tempNum1;
				numAry[j] = tempNum2;
			}
		}
		aryIndex--;

		for (k = 0; k < 8; k++) {
			printf("%d ", numAry[k]);
		}
		printf("\n");

	}

	// ��� ��� (���� ����)
	printf("\n���\n");
	for (k = 0; k < 8; k++) {
		printf(" %2d : %2d\n", k, numAry[k]);
	}

	return 0;
}

