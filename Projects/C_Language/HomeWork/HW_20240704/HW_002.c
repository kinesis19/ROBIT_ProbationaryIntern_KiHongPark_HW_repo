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
	int margin = 0, tempIdx = 0, targetIdx = 0, tempWordSize = 0;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	char* stackAry = (char*)calloc(htmlArySize, sizeof(char) * 100);
	/*int* htmlStack = (int*)malloc((int)htmlAry);*/


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
			/*printf("%d %d", tempIdx, j);*/
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