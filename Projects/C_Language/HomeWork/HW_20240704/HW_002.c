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

	printf("\n��� : ");

	// ���� ó�� ���� �˰���.

	while (htmlAry[tempIdx] != NULL) {
		// 1. '<'�� ���� ~ '>'�� ���� ��,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					isBreak = 0;
					tagCnt++;
					wordCnt++; // �ܾ� ���� ���� ��Ű��1
					break;
				}
				else if (htmlAry[j] != '>') {
					tempWordSize++;
					htmlTagAry[tagIdx] = htmlAry[j];
				}
				tempIdx++;
				j++;
				tagIdx++;
			}
			/*printf("%d %d", tempIdx, j);*/
		}
		else if (htmlAry[tempIdx] != '>' && htmlAry[tempIdx] != '<') {
			// 2. '>'�� ���� ~ '<'�� ���� �� = '>'�� '<'�� �����ϰ� ������ ���� ��
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					/*tempWordSize++;*/
					isBreak = 1;
					wordCnt++; // �ܾ� ���� ���Խ�Ű�� 2
					break;
				}
				else if (htmlAry[j] != '>' && htmlAry[j] != '<') {
					tempWordSize++;
					isBreak = 0;
				}
				tempIdx++;
				j++;
			}
		}

		if (isBreak == 1) {
			continue;
		}
		tempIdx++;
		j++;
		margin++;
		tagIdx++;
	}

	if (tagCnt % 2 != 0) {
		printf("�߸��� �±� �����̹Ƿ�, ���α׷��� �����մϴ�.\n");
		return 0;
	}


	// �ʱ�ȭ
	tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	isBreak = 0;
	tagIdx = 0;
	tagCnt = 0; // �±��� ���� Ȯ�ο� (�±� ������ 5����? -> �߸��� html �ڵ�)
	//wordCnt = 0; // �ܾ� ���� Ȯ�ο�. �ܾ� ������ ���� margin�� ������.
	j = 0;
	int marginCnt = 0;
	// ���� wordCnt�� ����� ���� �� ������ ����. wordCnt2�� �� ������ �񱳸� �� �� ����ϱ� ���� ������.
	int wordCnt2 = 0; 

	// ����� ���� �˰���.
	while (htmlAry[tempIdx] != NULL){
		// ù ��° �±� ���� ������ �±��� ���� ����ȭ �۾�.
		if (0 < tagCnt) {
			printf("       ");
		}
		if (wordCnt2 <= wordCnt / 2) {
			for (k = 0; k < wordCnt2; k++) {
				printf("  ");
			}
		}else if(wordCnt2 > wordCnt / 2){
			for (k = 0; k < wordCnt - wordCnt2 - 1; k++) {
				printf("  ");
			}
		}
		// 1. '<'�� ���� ~ '>'�� ���� ��,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
					tagCnt++;
					wordCnt2++; // �ܾ� ���� ���� ��Ű��1
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
					wordCnt2++; // �ܾ� ���� ���Խ�Ű�� 2
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
	

	/*printf("%d\n", tempIdx);
	for (i = 0; htmlTagAry[i] != NULL; i++) {
		printf("%c", htmlTagAry[i]);
	}
	printf("\n%d %d", tagCnt, wordCnt2);*/
	
	free(htmlAry);

	return 0;
}