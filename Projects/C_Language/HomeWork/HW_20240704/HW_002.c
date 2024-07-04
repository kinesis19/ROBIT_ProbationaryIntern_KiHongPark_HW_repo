#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	/*변수 생성 및 동적 할당하기
	* 
	* htmlArySize는 max 값을 몰라서 임의로 지정한 것임.
	* 나중에 수정할 필요 있음.
	*/
	int htmlArySize = 1;
	int i;
	int margin = 0, tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);

	// htmlTagAry : 입력 받은 문자들을 분류하여, 태그별, 단어별로 구분하여 저장하는 배열임.
	char* htmlTagAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	int* htmlStack = (int*)malloc((int)htmlAry);


	// 형식 입력출력하기
	printf("입력 : ");
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/

	int j = 0, k = 0;
	int isBreak = 0;
	int tagIdx = 0; 
	int tagCnt = 0; // 태그의 개수 확인용 (태그 개수가 5개다? -> 잘못된 html 코드)
	int wordCnt = 0; // 단어 개수 확인용. 단어 개수에 따라 margin이 정해짐.

	printf("\n출력 : ");

	// 예외 처리 위한 알고리즘.

	while (htmlAry[tempIdx] != NULL) {
		// 1. '<'로 시작 ~ '>'로 끝날 때,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					isBreak = 0;
					tagCnt++;
					wordCnt++; // 단어 수에 포함 시키기1
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
			// 2. '>'로 시작 ~ '<'로 끝날 때 = '>'와 '<'로 시작하고 끝나지 않을 때
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					/*tempWordSize++;*/
					isBreak = 1;
					wordCnt++; // 단어 수에 포함시키기 2
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
		printf("잘못된 태그 구조이므로, 프로그램을 종료합니다.\n");
		return 0;
	}


	// 초기화
	tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	isBreak = 0;
	tagIdx = 0;
	tagCnt = 0; // 태그의 개수 확인용 (태그 개수가 5개다? -> 잘못된 html 코드)
	//wordCnt = 0; // 단어 개수 확인용. 단어 개수에 따라 margin이 정해짐.
	j = 0;
	int marginCnt = 0;
	// 기존 wordCnt는 출력을 위해 비교 변수로 사용됨. wordCnt2는 비교 변수와 비교를 할 때 사용하기 위해 선언함.
	int wordCnt2 = 0; 

	// 출력을 위한 알고리즘.
	while (htmlAry[tempIdx] != NULL){
		// 첫 번째 태그 제외 나머지 태그의 여백 균일화 작업.
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
		// 1. '<'로 시작 ~ '>'로 끝날 때,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
					tagCnt++;
					wordCnt2++; // 단어 수에 포함 시키기1
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
			// 2. '>'로 시작 ~ '<'로 끝날 때 = '>'와 '<'로 시작하고 끝나지 않을 때
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					/*tempWordSize++;*/
					isBreak = 1;
					wordCnt2++; // 단어 수에 포함시키기 2
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