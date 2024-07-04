#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 변수 선언하기.
	int num1, num2, i, j, cnt = 0;
	// pArr 전용 index Checker
	int aryIdx1 = 0, aryIdx2 = 0;
	/* aryIdx1과 aryIdx2의 변화를 주기 위한 논리 연산자.
	* (but, boolean은 안 배운 개념이므로 int type을 사용함)
	* 0 : false, 1 : true
	* aryIdx1(isHigh)의 값이 0일 때 : High(1), num1일 때 : Low(0).
	*/ 
	int isHigh = 0;

	// 형식 입출력 하기.
	printf("입력 : ");
	scanf("%d %d", &num1, &num2);
	int* pArr;

	/* 동적 할당하기.
	* 이중 포인터 X -> 이중 포인터 개념은 배우지 않았기 때문임.
	* int type의 2차원 배열 생성 -> 해당 값들을 동적 배열 (포인터 배열)에 할당하기
	*/
	pArr = (int*)calloc((num1 * num2), sizeof(int));
	
	// 가운데 숫자 지정을 위한 for문.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// 가운데 숫자 지정하기
			if ((num2 - 1) / 2 == j && (num1 - 1) / 2 == i) {
				pArr[cnt] = 1;
				aryIdx1 = (num1 - 1) / 2;
				aryIdx2 = (num2 - 1) / 2;
			}else if((num2 - 1) / 2 == j && i == (num1 - 1) / 2 + 1){ // 가운데 숫자 바로 아래일 때,
				/* 반복문 탈출하기.
				* -> 가운데 숫자를 제외한 모든 숫자를 채우기 위해 반복문을 탈출함.
				*/
				pArr[cnt] = 2;
				break;
			}
			cnt++;
		}
	}

	// 가운데 제외 숫자를 지정하는 for문.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {

			if (aryIdx1 == (num1 - 1)) {
				isHigh = 0;
			}else if (aryIdx1 == 0) {
				isHigh = 1;
			}

			if (isHigh != 1) {
				aryIdx1--;
			}else if(isHigh == 1){
				aryIdx1++;
			}


		}
	}

	// Debugging: pArr Index
	printf("%d %d\n\n", aryIdx1, aryIdx2);


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