#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�.
	char inputText[20] = { '\0', }	;
	int i, textCnt = 0;

	// ����� �ޱ�.
	printf("�Է� : ");
	scanf("%[^\n]s", &inputText); // �������� �Է� �ޱ� ���� ������ (����� SW�����б� �� ��� ����)

	for (i = 0; inputText[i] != 0; i++) {
		printf("%d ", inputText[i]);
		textCnt++;
	}

	printf("\n\n��� : ");
	printf("%d\n\n", textCnt);
	for (i = textCnt; i > 0; i--) {
		printf("%d ", inputText[i-1]);
	}

	printf("\n%s", &inputText);

	return 0;
}