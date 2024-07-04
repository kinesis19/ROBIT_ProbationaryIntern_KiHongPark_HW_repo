#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 선언하기.
	int num1, num2, i, j, cnt = 0;

	// 형식 입출력 하기.
	printf("입력 : ");
	scanf("%d %d", &num1, &num2);
	int* pArr;

	/* 동적 할당하기.
	* 이중 포인터 X -> 이중 포인터 개념은 배우지 않았기 때문임.
	* int type의 2차원 배열 생성 -> 해당 값들을 동적 배열 (포인터 배열)에 할당하기
	*/
	pArr = (int*)malloc(sizeof(int) * (num1 * num2));

	/*if (pArr == NULL) {
		printf("malloc error!");
	}*/



	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {

			if ((num2 - 1) / 2 == j && (num1 - 1) / 2 == i) {
				pArr[cnt] = 1;
			}else{
				pArr[cnt] = 0;
				/*pArr[cnt] = cnt + 1;*/
			}
			cnt++;
		}
	}

	cnt = 0;

	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			printf("%d ", pArr[cnt]);
			cnt++;
		}
		printf("\n");
	}


	free(pArr);

}