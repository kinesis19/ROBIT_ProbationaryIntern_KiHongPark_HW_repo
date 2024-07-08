#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기.
	char inputText[30] = { '\0', };
	char* pText[30];
	char tempChar, mostChar; // 최다 등장 비교용도.
	int cmpCnt = 0, tempCmpCnt = 0;
	int i, j, textCnt = 0, textSpaceCnt = 0;

	*pText = &inputText;

	// 입출력 받기.
	printf("입력 : ");
	scanf("%[^\n]s", &inputText); // 공백으로 입력 받기 위한 연산자 (광운대 SW예비학교 때 배운 내용)

	for (i = 0; inputText[i] != 0; i++) {
		/*printf("%d ", inputText[i]);*/
		/**(pText + i) = inputText[i];*/
		if (inputText[i] != 32) { // ASCII Code값이 32 (공백)이 아니라면,
			textCnt++;
		}else{
			textSpaceCnt++;
		}
	}

	// Debugging: pText 출력하기.
	/*printf("\n");
	printf("%d, %d\n", textCnt, textSpaceCnt);*/
	for (i = 0; i < textCnt + textSpaceCnt; i++) {
		*(pText + i) = inputText[i];
		/*printf("%d ", *(pText + i));*/
	}

	// 최다등장문자 구하는 알고리즘.
	for (i = 0; i < textCnt + textSpaceCnt; i++) {
		tempChar = *(pText + i);
		if (*(pText + i) == 32) { //
			continue;
		}
		for (j = 0; j < textCnt + textSpaceCnt; j++) {
			if (tempChar == *(pText + j)) {
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
	for (i = textCnt + textSpaceCnt; i > 0; i--) {
		printf("%c", *(pText + (i - 1)));
	}
	printf("\n       최다등장문자 : %c", mostChar);

	return 0;
}