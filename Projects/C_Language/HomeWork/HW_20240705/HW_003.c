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

	char* stuffName = (char*)calloc(inputNum, sizeof(char) * 20);
	int* stuffCost = (int*)calloc(inputNum, sizeof(int));


	for (i = 0; i < inputNum; i++) {
		scanf("%s %d", &stuffName[i], &stuffCost[i]);
		wantIdx++;
	}


	scanf("%s", &stuffName[wantIdx]);

	printf("��� : ");

	printf("%s \n\n", &stuffName[wantIdx]);


	//// ã�� ������ �Էµ� ���� ����Ʈ�� �ִ��� ã�ƺ��� �˰���.
	//for (i = 0; i < inputNum; i++) {
	//	// ã�� ������ ����Ʈ�� ���� ��,
	//	if (&stuffName[i] == &stuffName[wantIdx]) {
	//		printf("����");
	//	}
	//	printf("%d ", &stuffName[i] == &stuffName[wantIdx]);
	//}
	//// ���ٸ� 0�� ����ϰ� ������.
	//printf("0");
	//return 0;



	for (i = 0; i < inputNum; i++) {
		printf("%s %d\n", &stuffName[i], stuffCost[i]);
	}


	return 0;
}