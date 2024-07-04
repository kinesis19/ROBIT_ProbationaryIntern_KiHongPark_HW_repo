#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double GettingDecimalPoint(int num1, int num2, int num3);

int main() {

	// 변수 선언하기.
	int inputNum;
	int i;

	// 형식 출력하기.
	printf("입력 : ");
	scanf("%d", &inputNum);

	/* 학생 이름 배열, 성적 배열
	* 이름의 길이는 안내되어 있지 않으므로, 임의로 지정함.
	*/
	int* chAry = (int*)calloc(inputNum, sizeof(char));
	int* pAry1 = (int*)calloc(inputNum, sizeof(int));
	int* pAry2 = (int*)calloc(inputNum, sizeof(int));
	int* pAry3 = (int*)calloc(inputNum, sizeof(int));

	
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d %d %d", &chAry[i], &pAry1[i], &pAry2[i], &pAry3[i]);
	}

	printf("출력 : \n");
	// Debugging
	/*for (i = 0; i < inputNum; i++) {
		printf("       ");
		printf("%s\n", &chAry[i]);
		printf("%d %d %d\n", pAry1[i], pAry2[i], pAry3[i]);
	}*/


	for (i = 0; i < inputNum; i++) {
		double examAvg = GettingDecimalPoint(pAry1[i], pAry2[i], pAry3[i]);

		printf("       ");
		// 출력 형식에 알맞게 소숫점 한 자리까지만 표시함.

		if ((int)(examAvg * 10) % 10 == 0) {
			printf("%s %d\n", &chAry[i], (int)examAvg);
		}else {
			printf("%s %.1lf\n", &chAry[i], examAvg);
		}

	}
	
	/*
	free(chAry);
	free(pAry1);
	free(pAry2);
	free(pAry3);*/

	return 0;
}

double GettingDecimalPoint(int num1, int num2, int num3) {
	/*
	* 소숫점 한 자리 출력이 형식임.
	* 그냥 계산하면 소숫점이 잘못 출력 되는 경우가 존재함.
	* 따라서, 소숫점 둘째 자리까지 구하고, 둘째 자리의 숫자만 평균에서 빼주도록 구현함.
	* e.x) 평균 : 50.66
	* 1. 50.66
	* 2. 506.6 <- 1
	* 3. 506.0 
	* 4. 50.6 -> 1
	* 조정한 값 : 50.6 (-0.06)
	* 소수점 구하는 공식도 스스로 유추해 적용해서 뿌듯함.
	* 모든 과제는 규칙대로 인공지능 미사용, 인터넷 검색X, 레퍼런스 참고X, 
	* 오직 강의 자료만을 참고하여 수행함.
	*/ 
	double result = 0;
	result = (num1 + num2 + num3) / 3.0;

	result = (int)(result * 10) / 10.0;

	return result;
}