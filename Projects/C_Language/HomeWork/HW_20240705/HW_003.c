#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _something {

	char name[20];
	int cost;
}Something;


int main() {

	// ���� �����ϱ�.
	int inputNum, i, wantIdx = 1;
	// ���� ������ϱ�.
	printf("�Է� : ");
	scanf("%d", &inputNum);

	Something* something = calloc(inputNum, sizeof(char) * 20);


	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d", &something[i].name, &something[i].cost);
		wantIdx++;
	}


	printf("       ");
	scanf("%s", &something[i].name);

	printf("\n��� : ");


	// Debugging:
	for (i = 0; i < inputNum; i++) {
		// ã�� ������ ����Ʈ�� ���� ��,
		printf("%s %s : ", &something[i].name, &something[inputNum].name);
		printf("%d \n", something[i].name == something[inputNum].name);
	}

	int totalCost = 0;
	//// ã�� ������ �Էµ� ���� ����Ʈ�� �ִ��� ã�ƺ��� �˰���.
	for (i = 0; i < inputNum; i++) {
		// ã�� ������ ����Ʈ�� ���� ��,
		if (&something[i].name == &something[wantIdx].name) {
			printf("aaaaaaaa");
			printf("%d ", something[i].cost);
			totalCost = totalCost + something[i].cost;
		}
	}
	printf("%d", totalCost);
	return 0;

}