#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�.
	char inputText[20] = { '\0', }	;
	int i;

	// ����� �ޱ�.
	printf("�Է� : ");
	scanf("%[^\n]s", &inputText); // �������� �Է� �ޱ� ���� ������ (����� SW�����б� �� ��� ����)

	for (i = 0; inputText[i] != 0; i++) {
		printf("%d ", inputText[i]);
	}

	printf("\n\n��� : ");

	printf("\n%s", &inputText);

	return 0;
}