#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 선언하기.
	char* inputText = (char*)malloc(sizeof(char) * 20);
	char tempChar, mostChar; // 최다 등장 비교용도.
	int cmpCnt = 0, tempCmpCnt = 0;
	int i, j, textCnt = 0, textSpaceCnt = 0;

	// 입출력 받기.
	printf("입력 : ");
	scanf("%[^\n]s", inputText); // 공백으로 입력 받기 위한 연산자 (광운대 SW예비학교 때 배운 내용)

	printf("%s", inputText);
	for (i = 0; i < 20; i++) {
		printf("%d : %c\n", i, *(inputText + i));
	}

	for (i = 0; *(inputText + i); i++) {
		if (*(inputText + i) != 32) { // ASCII Code값이 32 (공백)이 아니라면,
			textCnt++;
		}else {
			textSpaceCnt++;
		}
	}


	//// 최다등장문자 구하는 알고리즘.
	for (i = 0; i < textCnt + textSpaceCnt; i++) {
		tempChar = *(inputText + i);
		if (*(inputText + i) == 32) { // 공백은 최다등장문자에 포함하지 않음.
			continue;
		}
		for (j = 0; j < textCnt + textSpaceCnt; j++) {
			if (tempChar == *(inputText + j)) {
				tempCmpCnt++;
			}
		}

		if (tempCmpCnt > cmpCnt) {
			cmpCnt = tempCmpCnt;
			mostChar = tempChar;
		}
		tempCmpCnt = 0;
	}

	// 형식 출력하기.
	printf("\n출력 : ");
	// 입력 받은 문자열 거꾸로 출력하기.
	for (i = textCnt + textSpaceCnt; i > 0; i--) {
		printf("%c", *(inputText + (i - 1)));
	}
	// 최다등장문자 출력하기. (공백 제외)
	printf("\n       최다등장문자 : %c", mostChar);

	// 동적할당 메모리 해제하기.
	free(inputText);

	return 0;
}