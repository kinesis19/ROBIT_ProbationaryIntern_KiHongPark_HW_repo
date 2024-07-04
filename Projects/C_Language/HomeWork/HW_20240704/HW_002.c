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
	/*
	* 과제에서는 동적할당을 사용해 스택을 구현하라고 제시되었으나,
	* 이번 차시 수업에서는 스택을 배우지 않음.
	* 정확히는 스택이 무엇인지 사진만 보고 넘어갔으며, 스택 사용법은 배우지 않음.
	* 로빛 수습 단원 규정상 생성형 인공지능(GPT), 타인의 소스코드, 구글링은 허용되지 않는 것으로 알고 있음.
	* 확인을 위해 멘토 선배님께 여쭤봄.
	* 구글 검색이 가능하다면 -> 스택 개념을 본 코드에 적용할 예정임.
	* 구글 검색이 불가능하다면 -> 최대한 스택 개념을 비슷하게 구현해 낼 예정임.
	* 지금은, 스택의 FIFO 방식과 유사하게 구현해 봄.
	*/
	int* htmlStack = (int*)malloc((int)htmlAry);


	// 형식 입력출력하기
	scanf("%s", &htmlAry[0]);
	/*printf("%s\n", &htmlAry[2]);*/

	int j = 0;
	int isBreak = 0;

	while (htmlAry[tempIdx] != NULL){
		// 1. '<'로 시작 ~ '>'로 끝날 때,
		if (htmlAry[tempIdx] == '<') {
			while (1) {
				if (htmlAry[j] == '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
					break;
				}else if (htmlAry[j] != '>') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
				}
				tempIdx++;
				j++;
			}
			printf("%d %d", tempIdx, j);
		}else if (htmlAry[tempIdx] != '>' && htmlAry[tempIdx] != '<') { 
			// 2. '>'로 시작 ~ '<'로 끝날 때 = '>'와 '<'로 시작하고 끝나지 않을 때
			while (1) {
				if (htmlAry[j] == '>' || htmlAry[j] == '<') {
					/*tempWordSize++;*/
					isBreak = 1;
					break;
				}else if (htmlAry[j] != '>' && htmlAry[j] != '<') {
					tempWordSize++;
					printf("%c", htmlAry[j]);
					isBreak = 0;
				}
				tempIdx++;
				j++;
			}
			printf("%d %d", tempIdx, j);
		}
		printf("\n");

		if (isBreak == 1) {
			continue;
		}
		tempIdx++;
		j++;
	}
	

	printf("%d\n", tempIdx);

	free(htmlAry);

	return 0;
}