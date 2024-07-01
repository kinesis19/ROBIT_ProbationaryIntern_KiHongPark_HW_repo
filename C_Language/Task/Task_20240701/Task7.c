#include <stdio.h>

int main(void) {

	// 변수 선언하기
	int num1, num2, tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1;
	int result1 = 0, result2 = 0, result3 = 0, result4 = 0;
	
	//형식 출력하기
	printf("n, r 입력 : ");
	scanf_s("%d %d", &num1, &num2);


	// 순열 구하는 알고리즘
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // 초기화
	while (1) {
		// n! 구하기
		while (1) {
			if (cntNum1 <= num1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}else if (cntNum1 > num1) {
				break;
			}
		}
		// (n - r)! 구하기
		while (1) {
			if (cntNum2 <= num1 - num2) {
				tempNum2 = tempNum2 * cntNum2;
				cntNum2++;
			}else if (cntNum2 > num1 - num2) {
				break;
			}
		}
		break;
	}
	result1 = tempNum1 / tempNum2;

	// 중복순열 구하는 알고리즘
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // 초기화
	while (1) {
		if (cntNum1 <= num2) {
			tempNum1 = tempNum1 * num1;
			cntNum1++;
		}else if(cntNum1 > num2){
			break;
		}
	}
	result2 = tempNum1;

	// 조합 구하는 알고리즘
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // 초기화
	while (1) {
		// n! 구하기
		while (1) {
			if (cntNum1 <= num1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}
			else if (cntNum1 > num1) {
				break;
			}
		}

		// (n - r)! 구하기
		while (1) {
			if (cntNum2 <= num1 - num2) {
				tempNum2 = tempNum2 * cntNum2;
				cntNum2++;
			}else if (cntNum2 > num1 - num2) {
				break;
			}
		}
		// r! 구하기
		while (1) {
			if (cntNum3 <= num2) {
				tempNum3 = tempNum3 * cntNum3;
				cntNum3++;
			}else if(cntNum3 > num2){
				break;
			}
		}
		break;
	}
	result3 = tempNum1 / (tempNum2 * tempNum3);

	// 중복조합 구하는 알고리즘
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // 초기화
	while (1) {
		// (n + r - 1) 구하기
		while (1) {
			if (cntNum1 < num1 + num2 - 1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}else if (cntNum1 >= num1 + num2 - 1) {
				break;
			}
		}

		// r! 구하기
		while (1) {
			if (cntNum3 <= num2) {
				tempNum3 = tempNum3 * cntNum3;
				cntNum3++;
			}else if (cntNum3 > num2) {
				break;
			}
		}
		break;
	}
	printf("%d %d\n", tempNum1, tempNum3);
	result4 = tempNum1 / tempNum3;


	printf("순열 결과 %d\n중복순열 결과 : %d\n조합 결과 : %d\n중복조합 결과 : %d\n", result1, result2, result3, result4);


}