#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 변수 선언하기
	int sequenceSize, middleNum, cnt = 1;
	/*
	* 변수 cnt의 초기값을 1로 설정하는 이유:
	* 중복 수열의 특징에 따라 타겟 값(middleNum)도 포함해야 하기 때문이다.
	*/
	// 배열 sequence는 동적할당 하지 않고 구현함.
	int i, sequence[100] = { 0, };
	
	// 형식 출력하기
	printf("N : ");
	scanf("%d", &sequenceSize);
	printf("B : ");
	scanf("%d", &middleNum);

	printf("\n");

	// 알고리즘 구현하기
	// 수열에 값 입력 받기
	for (i = 0; i < sequenceSize; i++) {
		scanf("%d", &sequence[i]);
	}

	// 중복수열 구하는 알고리즘
	for (i = 0; i < sequenceSize; i++) {
		if (sequence[i] == middleNum || sequence[sequenceSize - i - 1] == middleNum) {
			break;
		}else{
			sequence[i] = 0;
			sequence[sequenceSize - i - 1] = 0;
			cnt++;
		}
	}

	// 결과 출력하기
	printf("중앙값이 %d인 부분수열의 개수 : %d", middleNum, cnt);

	return 0;
}