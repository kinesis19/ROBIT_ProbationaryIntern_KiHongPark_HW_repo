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

	printf("��� : ");

	printf("%s \n\n", &something[i].name);


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
		printf("%s %d\n", &something[i].name, something[i].cost);
	}


	return 0;
}