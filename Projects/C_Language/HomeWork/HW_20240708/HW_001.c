#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�.
	char inputText[30] = { '\0', };
	char* pText[30];
	char tempChar, mostChar; // �ִ� ���� �񱳿뵵.
	int cmpCnt = 0, tempCmpCnt = 0;
	int i, j, textCnt = 0, textSpaceCnt = 0;

	*pText = &inputText;

	// ����� �ޱ�.
	printf("�Է� : ");
	scanf("%[^\n]s", &inputText); // �������� �Է� �ޱ� ���� ������ (����� SW�����б� �� ��� ����)

	for (i = 0; inputText[i] != 0; i++) {
		/*printf("%d ", inputText[i]);*/
		/**(pText + i) = inputText[i];*/
		if (inputText[i] != 32) { // ASCII Code���� 32 (����)�� �ƴ϶��,
			textCnt++;
		}else{
			textSpaceCnt++;
		}
	}

	// Debugging: pText ����ϱ�.
	/*printf("\n");
	printf("%d, %d\n", textCnt, textSpaceCnt);*/
	for (i = 0; i < textCnt + textSpaceCnt; i++) {
		*(pText + i) = inputText[i];
		/*printf("%d ", *(pText + i));*/
	}

	// �ִٵ��幮�� ���ϴ� �˰���.
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

	// ���� ����ϱ�.
	printf("\n��� : ");
	for (i = textCnt + textSpaceCnt; i > 0; i--) {
		printf("%c", *(pText + (i - 1)));
	}
	printf("\n       �ִٵ��幮�� : %c", mostChar);

	return 0;
}