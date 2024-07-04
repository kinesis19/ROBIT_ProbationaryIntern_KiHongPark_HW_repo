#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double GettingDecimalPoint(int num1, int num2, int num3);

int main() {

	// 변수 선언하기.
	int inputNum;
	int i, j;

	// 형식 출력하기.
	printf("입력 : ");
	scanf_s("%d", &inputNum);

	/* 학생 이름 배열, 성적 배열
	* 이름의 길이는 안내되어 있지 않으므로, 임의로 지정함.
	*/
	char* chAry = (char*)calloc(inputNum, sizeof(char) * 100); // 이름 저장 배열
	int* pAry1 = (int*)calloc(inputNum, sizeof(int)); // 성적 1 저장 배열
	int* pAry2 = (int*)calloc(inputNum, sizeof(int)); // 성적 2 저장 배열
	int* pAry3 = (int*)calloc(inputNum, sizeof(int)); // 성적 3 저장 배열
	double* pArySort = (double*)calloc(inputNum, sizeof(double)); // 성적 정렬 배열
	int* nameCntAry = (int*)calloc(inputNum, sizeof(int)); // 이름의 시작 index를 알기 위한 배열
	int* nameStartCntAry = (int*)calloc(inputNum, sizeof(int)); // 이름의 시작 index를 알기 위한 배열 (출력용)

	/*nameCntAry[0] = 0;*/
	int tempIdx = 0;
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		if (chAry[tempIdx] == NULL) {
			scanf("%s %d %d %d", &chAry[tempIdx], &pAry1[i], &pAry2[i], &pAry3[i]);

			while (1){
				if (chAry[tempIdx] == NULL) {
					nameCntAry[i] = tempIdx;
					nameStartCntAry[i] = nameCntAry[i];
					break;
				}else{
					tempIdx++;
				}
			}
		}
	}

	// 배열에 할당하기.
	for (i = 0; i < inputNum; i++) {
		double examAvg = GettingDecimalPoint(pAry1[i], pAry2[i], pAry3[i]);
		// 성적 정렬 배열에 값 할당하기 - 초기 할당
		pArySort[i] = examAvg;
	}

	// 배열 정렬하기.
	for (i = 0; i < inputNum; i++) {
		// 성적 정렬하기
		for (j = 0; j < inputNum; j++) {
			if (j + 1 < inputNum && pArySort[j] < pArySort[j + 1]) {
				// 성적 변경하기.
				double tempNum;
				tempNum = pArySort[j];
				pArySort[j] = pArySort[j + 1];
				pArySort[j + 1] = tempNum;


				// 이름 변경하기.
				int tempChar;
				tempChar = nameStartCntAry[j];
				nameStartCntAry[j] = nameStartCntAry[j + 1];
				nameStartCntAry[j + 1] = tempChar;

			}
		}

	}
	nameStartCntAry[j] = 0;


	// Debugging
	/*for (i = 0; i < 5; i++) {
		printf("\n%lf", pArySort[i]);
	}
	printf("\n");
	*/
	for (i = 0; i < 5; i++) {
		printf("%d ", nameCntAry[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", nameStartCntAry[i]);
	}

	// 정렬된 배열 출력하기
	int tempCnt = 0;
	int tempStart = 0;
	i = 0;
	tempStart = nameStartCntAry[i + 1];
	printf("출력 : \n");
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		// 이름 출력하기
		for (j = tempStart; j < nameStartCntAry[i]; j++) {
			printf("%c", chAry[j]);
		}
		while (1) {
			if (tempStart < nameStartCntAry[i]) {
				tempStart++;
			}else {
				break;
			}
		}
		
		
		/*for (j = tempCnt; j < nameCntAry[i]; j++) {
			printf("%c", chAry[j]);
		}
		while (1) {
			if (tempCnt < nameCntAry[i]) {
				tempCnt++;
			}else {
				break;
			}
		}*/
		printf(" ");
		// 출력하기
		if ((int)(pArySort[i] * 10) % 10 == 0) {
			printf("%d", (int)pArySort[i]);
		}else {
			printf("%.1lf", pArySort[i]);
		}
		printf(" %d \n", tempStart);


	}


	free(chAry);
	free(pAry1);	
	free(pAry2);
	free(pAry3);
	free(pArySort);
	free(nameCntAry);

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