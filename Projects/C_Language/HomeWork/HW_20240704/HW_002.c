#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�


	/*�����Ҵ��ϱ�
	* 
	* htmlArySize�� max ���� ���� ���Ƿ� ������ ����.
	* ���߿� ������ �ʿ� ����.
	*/

	int htmlArySize = 1;
	int i;
	int margin = 0, tempIdx = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	/*int* htmlStack = (int*)malloc((int)htmlAry);*/


	// ���� �Է�����ϱ�
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry);

	printf("%c\n", &htmlAry[1]);*/
	printf("%s\n", &htmlAry[2]);

	/*printf("%d\n", tempIdx);*/
	for (i = 0; i < 10; i++) {
		printf("%c", &htmlAry[i]);
	}

	printf("%d\n", tempIdx);
	

	free(htmlAry);

	return 0;
}