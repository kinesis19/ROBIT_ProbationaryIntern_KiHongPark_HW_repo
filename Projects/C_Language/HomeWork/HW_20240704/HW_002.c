#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�


	/*�����Ҵ��ϱ�
	* 
	* htmlArySize�� max ���� ���� ���Ƿ� ������ ����.
	* ���߿� ������ �ʿ� ����.
	*/

	int htmlArySize = 10;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);

	scanf("%s", &htmlAry);

	/*printf("%s", &htmlAry);*/
	

	free(htmlAry);

	return 0;
}