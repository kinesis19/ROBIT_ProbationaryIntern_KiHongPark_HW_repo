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
		// (����ó��) ���� �� ���ڿ� ������ ���� �ľ� 
		// -> But, ������ ���� �ȳ��� �������Ƿ� �ش� ����� �ּ� ó�� ��.
		/*if (inputString[i] == '\0') {
			break;
		}*/

		//  �� ���� �м�
		if (inputString[i] == searchString[searchIndex]) {
			/*printf("%c", inputString[i]);*/
			// ����� 1���� �̹Ƿ�, ����� �����ϰ� �ϱ� ���� i + 1���� ������.
			rememberStrPosition[searchIndex] = i + 1;
			searchIndex++;
		}else if(searchString[searchIndex] == '\0'){
			break;
		}
	}

	printf("%s�� ��ġ : ", searchString);
	for (i = 0; i < 100; i++) {
		if (rememberStrPosition[i] == 0) {
			break;
		}
		printf("%d", rememberStrPosition[i]);
	}

	return 0;
}