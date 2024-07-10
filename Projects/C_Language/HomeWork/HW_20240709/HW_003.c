#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print(int* row, int* col, int** pArr);
void arr_ij(int* sizeRow, int* sizeCol, int** pArr);

int main() {

	// 더블포인터 변수 및 일반 변수 선언하기.
	int** arr = NULL;
	int row, col, sizeRow, sizeCol;
	
	// 입출력 받기.
	printf("열의 수를 입력하세요:");
	scanf("%d", &sizeCol);
	printf("행의 수를 입력하세요:");
	scanf("%d", &sizeRow);

	// 변수 할당하기.
	row = sizeRow;
	col = sizeCol;

	// 2차원 동적 메모리 할당하기.
	arr_ij(&sizeRow, &sizeCol, arr);

	if (arr == NULL) printf("동적 할당 되지 않았습니다.");
	else if (arr != NULL) printf("정상적으로 동적 할당 되었습니다.");
	// 배열 arr 출력하기.
	/*print(&row, &col, &arr);*/

	// 동적 메모리 해제하기.
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}

	return 0;
}

// 달팽이 형식에 맞게 출력하는 함수.
void print(int* row, int* col, int** pArr) {

	pArr = (int**)malloc(sizeof(int) * (*row));

	/*printf("%d %d %d", *row, *col, sizeof(*(*(pArr + 0) + 1)));*/
	printf("%d %d %d", *row, *col, sizeof(*(pArr + 0)));

	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf("%3d ", *(*(pArr + i) + j));
		}
		printf("\n");
	}

}

// 당팽이 형식에 맞게 구현하는 함수.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	int inputNum = 1; // 배열에 넣을 숫자 변수.
	int change = 0; // change가 10이 될 때마다 행과 열의 번호를 삽입함.
	// 2차원 배열 만들기.
	// 1, sizeRow 만큼의 포인터 배열을 동적 할당함.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	if (pArr == NULL) printf("동적할당 실패함.\n");
	for (int i = 0; i < (*sizeRow); i++) {
		// 2. 각각의 포인터 배열 요소에 sizeCol 만큼의 포인터 배열을 동적 할당함.
		*(pArr + i) = (int*)malloc(sizeof(int) * (*sizeCol));
	}

	int cntRow = 0, cntCol = 0;
	int inputNumLast = 0; // 마지막 숫자 저장용 (행, 열). inputNum과는 다름.

	for (int i = 0; i < (*sizeRow); i++) {
		change = 0;

		for (int j = 0; j < (*sizeCol); j++) {
			int tempInputNum = inputNum;
			// 최초 1회 inputNumLast 지정하기.
			if (i == 0) {
				inputNumLast = inputNum;
			}

			if ((0 < i && i < 9) && j == (*sizeCol) - 1) { // 열 출력
				inputNumLast++;
				inputNum = inputNumLast;
				*(*(pArr + i) + j) = inputNum;
			}else if (i == (*sizeRow) - 1 && j < ((*sizeCol))) {
				inputNumLast++;
				inputNum = inputNumLast;
				*(*(pArr + i) + (*sizeCol) - 1 - j) = inputNum;
			}else{
				*(*(pArr + i) + j) = inputNum;
			}

			inputNum = tempInputNum;

			// 변수 증감하기.
			change++;
			inputNum++;
		}
		cntRow++;
	}

	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			printf("%3d[%d][%d] ", *(*(pArr + i) + j), i, j);
		}
		printf("\n");
	}
	printf("\n\n%d\n\n", *(*(pArr + 0) + 9));
	/*print(sizeRow, sizeCol, pArr);*/

}


