#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 생성하기


	/*동적할당하기
	* 
	* htmlArySize는 max 값을 몰라서 임의로 지정한 것임.
	* 나중에 수정할 필요 있음.
	*/

	int htmlArySize = 10;
	char* htmlAry = (char*)calloc(htmlArySize, sizeof(char) * 100);

	scanf("%s", &htmlAry);

	/*printf("%s", &htmlAry);*/
	

	free(htmlAry);

	return 0;
}