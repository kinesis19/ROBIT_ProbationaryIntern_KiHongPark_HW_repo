#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	/* 변수 선언하기.
	* tempNum : 숫자를 pArr에 넣을 때, 해당 숫자의 정보를 나타냄.
	*/

	int num1, num2, i, j, cnt = 0, tempCnt = 0, tempNum = 1;
	// pArr 전용 index Checker
	int aryIdxX = 0, aryIdxY = 0;
	/* aryIdx1과 aryIdx2의 변화를 주기 위한 논리 연산자.
	* (but, boolean은 안 배운 개념이므로 int type을 사용함)
	* 0 : false, 1 : true
	* aryIdx1(isHigh)의 값이 0일 때 : High(1), num1일 때 : Low(0).
	* aryIdx2(isLeft)의 값이 0일 때 : Left(1), num2일 때 : Left(0).
	* spaceHigh, spaceLeft : 한 바퀴씩 회전해 돌아 왔을때, 몇 칸 뛰어서 채워야 하는지를 나타냄.
	*/ 
	int isHigh = 0, isLeft = 0, spaceHigh = 1, spaceLeft = 1;

	// 형식 입출력 하기.
	printf("입력 : ");
	scanf("%d %d", &num1, &num2);

	/* 동적 할당하기.
	* 이중 포인터 X -> 이중 포인터 개념은 배우지 않았기 때문임.
	* int type의 2차원 배열 생성 -> 해당 값들을 동적 배열 (포인터 배열)에 할당하기
	*/
	int* pArr = (int*)calloc((num1 * num2), sizeof(int));

	/* 배열의 기준 점(= 가운데 점)
	* refX = j, refY = i.
	*/
	int refX = 0, refY = 0; 

	// 가운데 숫자 지정을 위한 for문.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// 가운데 숫자 지정하기
			if ((num2 - 1) / 2 == j && (num1 - 1) / 2 == i) {
				pArr[tempCnt] = tempNum; // tempNum = 1
				aryIdxY = (num1 - 1) / 2;
				aryIdxX = (num2 - 1) / 2;
				tempNum++;
				refX = aryIdxX;
				refY = aryIdxY;
			}else if((num2 - 1) / 2 == j && i == (num1 - 1) / 2 + 1){ // 가운데 숫자 바로 아래일 때,
				/* 반복문 탈출하기.
				* -> 가운데 숫자를 제외한 모든 숫자를 채우기 위해 반복문을 탈출함.
				*/
				pArr[tempCnt] = tempNum; // tempCnt = 12, tempNum = 2
				cnt = tempCnt;
				aryIdxY++;
				break;
			}
			tempCnt++;
		}
	}
	/*printf("%d %d %d\n", cnt, tempCnt, tempNum);
	printf("%d %d %d %d\n", aryIdxX, aryIdxY, refX, refY);*/

	// 가운데 제외 숫자를 지정하는 for문.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// 숫자 작성하는 알고리즘.
			if (aryIdxX > refX) {
				if (aryIdxY > refY) {
					aryIdxX++;
					aryIdxY--;
					/*printf("%d %d\n\n", aryIdxX, aryIdxY);*/
				}
			}else if(aryIdxX == refX){
				if (aryIdxY > refY) {
					aryIdxX++;
					aryIdxY--;
					pArr[tempCnt] = ++tempNum;
					/*printf("%d %d\n\n", aryIdxX, aryIdxY);*/
				}
			}
		}
	}
	


	cnt = 0;
	// 숫자 출력 알고리즘.
	printf("\n출력 : ");
	for (i = 0; i < num1; i++) {
		if (i != 0) { // 출력 형식을 준수하기 위한 조건문.
			printf("       ");
		}
		for (j = 0; j < num2; j++) {
			printf("%d ", pArr[cnt]);
			cnt++;
		}
		printf("\n");
	}


	free(pArr);

}