#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기
	char inputString[100] = " ";
	char searchString[100] = " ";
	int rememberStrPosition[100] = { 0, };
	int i;

	// 형식 출력하기
	printf("최대 99개 문자 입력 <inputStr> : ");
	scanf("%s", &inputString);

	printf("찾는 문자열 <subStr> : ");
	scanf("%s", &searchString);

	for (i = 0; i < 100; i++) {
		// (예외처리) 띄어쓰기 및 문자열 끝나는 지점 파악 
		// -> But, 문제에 관련 안내는 없었으므로 해당 기능은 주석 처리 함.
		/*if (inputString[i] == '\0') {
			break;
		}*/
		printf("%c", inputString[i]);
	}


	return 0;
}