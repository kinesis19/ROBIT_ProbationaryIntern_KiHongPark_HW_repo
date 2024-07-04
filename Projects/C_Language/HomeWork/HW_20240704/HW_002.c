#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 생성하기


	/*동적할당하기
	* 
	* htmlArySize는 max 값을 몰라서 임의로 지정한 것임.
	* 나중에 수정할 필요 있음.
	*/

	int htmlArySize = 1;
	int i;
	int margin = 0, tempIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	/*int* htmlStack = (int*)malloc((int)htmlAry);*/


	// 형식 입력출력하기
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/

	int j = 0;

	/*
	* 입력 형식에는 공백이 없음.
	* 따라서, 입력 값에서 공백(마지막 글자 이후)이면 바로 검출을 중단하게끔 알고리즘을 설계함.
	*/ 

	for (i = 0; htmlAry[i] != ' '; i++) {
		j = 0;
		// '<'로 시작 ~ '>'로 끝날 때,
		if (htmlAry[i] == '<') {
			while(htmlAry[j] != '>'){
				tempWordSize++;
				printf("%c", htmlAry[j]);
				j++;
			}
		}
		j++;
		/*if (htmlAry[i] == '>') {
			printf("%d", tempWordSize);
			tempWordSize = 0;
			printf("\n");
		}*/
	}
	
	// 기존 코드 임시 저장
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




	/*printf("%d\n", tempIdx);*/
	

	free(htmlAry);

	return 0;
}