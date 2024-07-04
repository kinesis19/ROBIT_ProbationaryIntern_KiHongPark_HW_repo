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