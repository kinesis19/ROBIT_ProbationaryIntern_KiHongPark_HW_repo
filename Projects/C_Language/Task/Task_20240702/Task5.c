#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	char inputString[100] = " ";
	char searchString[100] = " ";
	int rememberStrPosition[100] = { 0, };
	int i;

	// ���� ����ϱ�
	printf("�ִ� 99�� ���� �Է� <inputStr> : ");
	scanf("%s", &inputString);

	printf("ã�� ���ڿ� <subStr> : ");
	scanf("%s", &searchString);

	for (i = 0; i < 100; i++) {
		// (����ó��) ���� �� ���ڿ� ������ ���� �ľ� 
		// -> But, ������ ���� �ȳ��� �������Ƿ� �ش� ����� �ּ� ó�� ��.
		/*if (inputString[i] == '\0') {
			break;
		}*/
		printf("%c", inputString[i]);
	}


	return 0;
}