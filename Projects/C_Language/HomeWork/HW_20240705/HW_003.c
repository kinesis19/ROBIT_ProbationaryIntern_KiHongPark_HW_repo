#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //C��� 3���� �������� ��� �������.

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

	// ����ü�� �����Ҵ��ϱ�.
	Something* something = calloc(inputNum, sizeof(char) * 20);

	// �����Ҵ��� ���� �Է� �޾� ����ü�� �����ϱ�.
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d", &something[i].name, &something[i].cost);
		wantIdx++;
	}

	printf("       ");
	scanf("%s", &something[i].name);

	printf("\n��� : ");

	int totalCost = 0;
	// ã�� ������ �Էµ� ���� ����Ʈ�� �ִ��� ã�ƺ��� �˰���.
	for (i = 0; i < inputNum; i++) {
		// ã�� ������ ����Ʈ�� ���� ��,
		if (strcmp(something[i].name, something[inputNum].name) == 0) {
			totalCost = totalCost + something[i].cost;
		}
	}
	printf("%d", totalCost);
	// �����Ҵ� �����ϱ�.
	free(something);

	return 0;

}