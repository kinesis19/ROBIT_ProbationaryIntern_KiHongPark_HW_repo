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
	int margin = 0, tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	char* stackAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	/*int* htmlStack = (int*)malloc((int)htmlAry);*/


	// ���� �Է�����ϱ�
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/

	int j = 0;

	/*
	* �Է� ���Ŀ��� ������ ����.
	* ����, �Է� ������ ����(������ ���� ����)�̸� �ٷ� ������ �ߴ��ϰԲ� �˰����� ������.
	*/ 

	while (htmlAry[tempIdx] != ' '){
		// 1. '<'�� ���� ~ '>'�� ���� ��,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					break;
				}else if (htmlAry[j] != '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
				}
				tempIdx++;
				j++;
			}
			printf("%d %d\n", tempIdx, j);
		}else if (htmlAry[tempIdx] != '>' && htmlAry[tempIdx] != '<') { 
			// 2. '>'�� ���� ~ '<'�� ���� �� = '>'�� '<'�� �����ϰ� ������ ���� ��
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					tempWordSize++;
					break;
				}else if (htmlAry[j] != '>' && htmlAry[j] != '<') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
				}
				tempIdx++;
				j++;
			}
			printf("%d %d\n", tempIdx, j);
		}
		tempIdx++;
		j++;

	}
	

	printf("%d\n", tempIdx);

	
	// ���� �ڵ� �ӽ� ����
	/*for (i = 0; i < 100; i++) {
		if (htmlAry[i] == '<') {
			tempWordSize = 0;
		}
		tempWordSize++;
		printf("%c", htmlAry[i]);

		if (htmlAry[i] == '>') {
			printf("%d", tempWordSize);
			tempWordSize = 0;
			printf("\n");
		}
	}*/

	
	

	free(htmlAry);

	return 0;
}