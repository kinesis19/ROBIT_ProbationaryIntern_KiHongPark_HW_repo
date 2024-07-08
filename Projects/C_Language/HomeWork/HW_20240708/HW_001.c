#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기.
	char inputText[20] = { '\0', }	;
	int i, textCnt = 0;

	// 입출력 받기.
	printf("입력 : ");
	scanf("%[^\n]s", &inputText); // 공백으로 입력 받기 위한 연산자 (광운대 SW예비학교 때 배운 내용)

	for (i = 0; inputText[i] != 0; i++) {
		printf("%d ", inputText[i]);
		textCnt++;
	}

	printf("\n\n출력 : ");
	printf("%d\n\n", textCnt);
	for (i = textCnt; i > 0; i--) {
		printf("%d ", inputText[i-1]);
	}

	printf("\n%s", &inputText);

	return 0;
}