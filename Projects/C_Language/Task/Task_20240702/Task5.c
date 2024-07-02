#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기
	char inputString[100] = " ";
	char searchString[100] = " ";
	int rememberStrPosition[100] = { 0, };
	int i, j, searchIndex = 0;

	// 형식 출력하기
	printf("최대 99개 문자 입력 <inputStr> : ");
	scanf("%s", &inputString);

	printf("찾는 문자열 <subStr> : ");
	scanf("%s", &searchString);

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			// 입력 받은 문자열이 끝날 때
			if (inputString[j] == '\0') {
				break;
			}

			// 찾는 문자열의 요소 하나와 입력 받은 문자열의 모든 요소를 비교하기
			if (inputString[j] == searchString[i]) {
				rememberStrPosition[searchIndex] = j;
				printf("%c %c %d\n", inputString[j], searchString[i], rememberStrPosition[searchIndex]);
				searchIndex++;
			}
			/*printf("%c\n\n", inputString[rememberStrPosition[j] + 1]);*/
			printf("%c\n\n", searchString[i + 1]);
			if (inputString[rememberStrPosition[j] + 1] == searchString[i + 1]) {
				printf("asdasd");
				printf("%c %c %d\n", inputString[j], searchString[i], rememberStrPosition[searchIndex]);
			}
		}		 
	}

	printf("%s의 위치 : ", searchString);
	i = 0;
	while (inputString[i] != '\0') {
		printf("%d ", rememberStrPosition[i]);
		i++;
	}

	/*for (i = 0; i < 100; i++) {
		printf("%d ", rememberStrPosition[i]);
	}*/

	return 0;
}