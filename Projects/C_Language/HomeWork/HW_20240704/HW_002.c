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
	int margin = 0, tempIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	/*int* htmlStack = (int*)malloc((int)htmlAry);*/


	// ���� �Է�����ϱ�
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/


	for (i = 0; i < 100; i++) {
		if (htmlAry[i] == '<') {
			tempWordSize = 0;
		}
		tempWordSize++;
		printf("%c", htmlAry[i]);

		if (htmlAry[i] == '>') {
			printf("%d", tempWordSize);
			tempWordSize = 0;
			printf("\n");
			/*break;*/
		}


	}
	
	/*printf("%d\n", tempIdx);*/
	

	free(htmlAry);

	return 0;
}