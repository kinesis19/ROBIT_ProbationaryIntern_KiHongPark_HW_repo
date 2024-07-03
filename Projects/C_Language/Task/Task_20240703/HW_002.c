#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {

	// 변수 선언하기
	int inputNum = 0, numAry[20] = { 0, }; // numAry : 요소를 저장하는 집합(배열)
	char operator[10] = { 0, }; // add, remove 등의 단어 저장 배열
	int i, j, aryIndex = 0;

	// 형식 출력하기
	printf("연산을 선택하세요. (1 <= x <= 20");
	printf("\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n");

	while (1) {
	
		printf("input : ");
		scanf("%s %d", &operator, &inputNum);

		// 예외처리 (inputNum 관련 수정 필요)
		if (!strcmp(operator, "stop")) {
			printf("Stopped!");
			break;
		}

		// 계산 연산자 비교하기
		if (!strcmp(operator, "add")) {
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					// 디버깅
					printf("추가할 수 없습니다.\n");
					break;
				}else{
					numAry[aryIndex] = inputNum;
					printf("집합 : { ");
					for (j = 0; j <= aryIndex; j++) {
						printf("%d, ", numAry[j]);
					}
					printf("}\n\n");
					aryIndex++;
					break;
				}

			}
		}
		else if (!strcmp(operator, "remove")) {

		}
		else if (!strcmp(operator, "check")) {

		}
		else if (!strcmp(operator, "toggle")) {

		}
		else if (!strcmp(operator, "all")) {

		}
		else if (!strcmp(operator, "empty")) {

		}


	}


	
	


	return 0;
}