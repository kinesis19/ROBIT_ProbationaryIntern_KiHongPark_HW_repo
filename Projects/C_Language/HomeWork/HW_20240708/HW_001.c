#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�.
	char* inputText = (char*)malloc(sizeof(char) * 20);
	char tempChar, mostChar; // �ִ� ���� �񱳿뵵.
	int cmpCnt = 0, tempCmpCnt = 0;
	int i, j, textCnt = 0, textSpaceCnt = 0;

	// ����� �ޱ�.
	printf("�Է� : ");
	scanf("%[^\n]s", inputText); // �������� �Է� �ޱ� ���� ������ (����� SW�����б� �� ��� ����)

	printf("%s", inputText);
	for (i = 0; i < 20; i++) {
		printf("%d : %c\n", i, *(inputText + i));
	}

	for (i = 0; *(inputText + i); i++) {
		if (*(inputText + i) != 32) { // ASCII Code���� 32 (����)�� �ƴ϶��,
			textCnt++;
		}else {
			textSpaceCnt++;
		}
	}


	//// �ִٵ��幮�� ���ϴ� �˰���.
	for (i = 0; i < textCnt + textSpaceCnt; i++) {
		tempChar = *(inputText + i);
		if (*(inputText + i) == 32) { // ������ �ִٵ��幮�ڿ� �������� ����.
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

	// ���� ����ϱ�.
	printf("\n��� : ");
	// �Է� ���� ���ڿ� �Ųٷ� ����ϱ�.
	for (i = textCnt + textSpaceCnt; i > 0; i--) {
		printf("%c", *(inputText + (i - 1)));
	}
	// �ִٵ��幮�� ����ϱ�. (���� ����)
	printf("\n       �ִٵ��幮�� : %c", mostChar);

	// �����Ҵ� �޸� �����ϱ�.
	free(inputText);

	return 0;
}