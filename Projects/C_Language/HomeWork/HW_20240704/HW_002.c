#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	/*���� ���� �� ���� �Ҵ��ϱ�
	* 
	* htmlArySize�� max ���� ���� ���Ƿ� ������ ����.
	* ���߿� ������ �ʿ� ����.
	*/
	int htmlArySize = 1;
	int i;
	int margin = 0, tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);

	// htmlTagAry : �Է� ���� ���ڵ��� �з��Ͽ�, �±׺�, �ܾ�� �����Ͽ� �����ϴ� �迭��.
	char* htmlTagAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	int* htmlStack = (int*)malloc((int)htmlAry);


	// ���� �Է�����ϱ�
	printf("�Է� : ");
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/

	int j = 0, k = 0;
	int isBreak = 0;
	int tagIdx = 0; 
	int tagCnt = 0; // �±��� ���� Ȯ�ο� (�±� ������ 5����? -> �߸��� html �ڵ�)
	int wordCnt = 0; // �ܾ� ���� Ȯ�ο�. �ܾ� ������ ���� margin�� ������.

	printf("��� : ");

	while (htmlAry[tempIdx] != NULL){
		// 1. '<'�� ���� ~ '>'�� ���� ��,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
					tagCnt++;
					wordCnt++; // �ܾ� ���� ���� ��Ű��1
					break;
				}else if (htmlAry[j] != '>') {
					tempWordSize++;
					htmlTagAry[tagIdx] = htmlAry[j];
					printf("%c", htmlAry[j]);
				}
				tempIdx++;
				j++;
				tagIdx++;
			}
			/*printf("%d %d", tempIdx, j);*/
		}else if (htmlAry[tempIdx] != '>' && htmlAry[tempIdx] != '<') { 
			// 2. '>'�� ���� ~ '<'�� ���� �� = '>'�� '<'�� �����ϰ� ������ ���� ��
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					/*tempWordSize++;*/
					isBreak = 1;
					wordCnt++; // �ܾ� ���� ���Խ�Ű�� 2
					break;
				}else if (htmlAry[j] != '>' && htmlAry[j] != '<') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
				}
				tempIdx++;
				j++;
			}
			/*printf("%d %d", tempIdx, j);*/
		}
		printf("\n");

		if (isBreak == 1) {
			continue;
		}
		tempIdx++;
		j++;
		margin++;
		tagIdx++;
	}
	

	printf("%d\n", tempIdx);
	for (i = 0; htmlTagAry[i] != NULL; i++) {
		printf("%c", htmlTagAry[i]);
	}
	printf("\n%d %d", tagCnt, wordCnt);
	
	free(htmlAry);

	return 0;
}