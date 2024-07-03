#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	char inputString[100] = " ";
	char searchString[100] = " ";
	int rememberStrPosition[100] = { 0, };
	int i, j, searchIndex = 0;

	// ���� ����ϱ�
	printf("�ִ� 99�� ���� �Է� <inputStr> : ");
	scanf("%s", &inputString);

	printf("ã�� ���ڿ� <subStr> : ");
	scanf("%s", &searchString);

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			// �Է� ���� ���ڿ��� ���� ��
			if (inputString[j] == '\0') {
				break;
			}

			// ã�� ���ڿ��� ��� �ϳ��� �Է� ���� ���ڿ��� ��� ��Ҹ� ���ϱ�
			if (inputString[j] == searchString[i]) {
				rememberStrPosition[searchIndex] = j;
				/*printf("%c %c %d\n", inputString[j], searchString[i], rememberStrPosition[searchIndex]);*/
				searchIndex++;
			}
			/*printf("%c\n", inputString[rememberStrPosition[j] + 1]);*/
			/*printf("%c\n\n", searchString[i + 1]);*/
			/*if (inputString[rememberStrPosition[j] + 1] == searchString[i + 1]) {
				printf("asdasd");
				printf("%c %c %d\n", inputString[j], searchString[i], rememberStrPosition[searchIndex]);
			}*/
		}		 
	}

	printf("%s�� ��ġ : ", searchString);
	i = 0;
	while (inputString[i] != '\0') {
		printf("%d��° ", rememberStrPosition[i]);
		i++;
	}

	/*for (i = 0; i < 100; i++) {
		printf("%d ", rememberStrPosition[i]);
	}*/

	return 0;
}