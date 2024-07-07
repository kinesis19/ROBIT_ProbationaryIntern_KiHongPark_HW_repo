#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

	Something* something = calloc(inputNum, sizeof(char) * 20);


	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d", &something[i].name, &something[i].cost);
		wantIdx++;
	}


	printf("       ");
	scanf("%s", &something[i].name);

	printf("출력 : ");

	printf("%s \n\n", &something[i].name);


	//// 찾는 물건이 입력된 물건 리스트에 있는지 찾아보는 알고리즘.
	//for (i = 0; i < inputNum; i++) {
	//	// 찾는 물건이 리스트에 있을 때,
	//	if (&stuffName[i] == &stuffName[wantIdx]) {
	//		printf("있음");
	//	}
	//	printf("%d ", &stuffName[i] == &stuffName[wantIdx]);
	//}
	//// 없다면 0을 출력하고 종료함.
	//printf("0");
	//return 0;



	for (i = 0; i < inputNum; i++) {
		printf("%s %d\n", &something[i].name, something[i].cost);
	}


	return 0;
}