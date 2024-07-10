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

	// 배열 arr 출력하기.
	print(&row, &col, arr);

	// 동적 메모리 해제하기.
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}

	return 0;
}
// 달팽이 형식에 맞게 출력하는 함수.
void print(int* row, int* col, int** pArr) {

	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf("%d ", *(*(pArr + 0) + 0));
		}
		printf("\n");
	}
}

// 당팽이 형식에 맞게 구현하는 함수.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	printf("%d %d\n\n", *sizeRow, *sizeCol);
	printf("%d\n\n", sizeof(int) * (*sizeRow));
	// 2차원 동적 메모리 할당하기.
	// 1. 행의 갯수만큼 2차원 배열 동적 할당하기.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	if (pArr == NULL) printf("동적할당 실패함.");
	for (int i = 0; i < *sizeRow; i++) {

		printf("%d ", pArr);

	}
	// 2. 각 행별 열의 갯수만큼 동적 할당하기.
	for (int i = 0; i < *sizeRow; i++) {
		printf("aa\n");
		pArr[i] = (int*)malloc(sizeof(int) * (*sizeCol));
	}

}


