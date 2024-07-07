#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //C언어 3일차 교육에서 배운 헤더파일.

typedef struct _something {

	char name[20];
	int cost;
}Something;


int main() {

	// 변수 선언하기.
	int inputNum, i, wantIdx = 1;
	// 형식 입출력하기.
	printf("입력 : ");
	scanf("%d", &inputNum);

	// 구조체에 동적할당하기.
	Something* something = calloc(inputNum, sizeof(char) * 20);

	// 동적할당한 값을 입력 받아 구조체에 대입하기.
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d", &something[i].name, &something[i].cost);
		wantIdx++;
	}

	printf("       ");
	scanf("%s", &something[i].name);

	printf("\n출력 : ");

	int totalCost = 0;
	// 찾는 물건이 입력된 물건 리스트에 있는지 찾아보는 알고리즘.
	for (i = 0; i < inputNum; i++) {
		// 찾는 물건이 리스트에 있을 때,
		if (strcmp(something[i].name, something[inputNum].name) == 0) {
			totalCost = totalCost + something[i].cost;
		}
	}
	printf("%d", totalCost);
	// 동적할당 해제하기.
	free(something);

	return 0;

}