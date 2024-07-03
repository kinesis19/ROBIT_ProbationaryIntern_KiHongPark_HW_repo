#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	// 변수 선언하기
	int numAry[8] = { 0, };
	int i, j, k;
	int maxNum = 0, aryIndex = 7;

	printf("입력\n");

	for (i = 0; i < 8; i++) {
		printf("%d : ", i);
		scanf("%d", &numAry[i]);
	}

	// 과정 출력 (정렬 전)
	printf("\n계산 과정\n");
	for (k = 0; k < 8; k++) {
		printf("%d ", numAry[k]);
	}
	printf("\n");

	// 최댓값 선택하기
	for (i = 7; i >= 0; i--) {
		maxNum = numAry[i]; // 최댓값 임시 지정
		
		// 다른 수 비교하기
		for (j = i - 1; j >= 0; j--) {
			if (maxNum < numAry[j]) {
				// 최댓값 지정하기
				maxNum = numAry[j];

				// 최댓값 인덱스 위치 변경하기
				int tempNum1 = 0;
				int tempNum2 = 0;

				tempNum1 = numAry[j];
				tempNum2 = numAry[aryIndex];
				numAry[aryIndex] = tempNum1;
				numAry[j] = tempNum2;
			}
		}
		aryIndex--;

		for (k = 0; k < 8; k++) {
			printf("%d ", numAry[k]);
		}
		printf("\n");

	}

	// 결과 출력 (정렬 정리)
	printf("\n출력\n");
	for (k = 0; k < 8; k++) {
		printf(" %2d : %2d\n", k, numAry[k]);
	}

	return 0;
}

