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

	if (arr == NULL) printf("arr의 동적할당 실패함.\n");
	printf("aaaaaaaa\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("hhhhhh\n");
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

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
	printf("bbb");
	printf("%3d ", pArr[0][0]);
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf("%3d ", pArr[i][j]);
		}
		printf("\n");
	}
}

// 당팽이 형식에 맞게 구현하는 함수.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {
	// 2차원 동적 메모리 할당하기.
	// 1. 행의 갯수만큼 2차원 배열 동적 할당하기.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow)); // 10개의 포인터 변수 선언함. = pArr은 10개의 포인터 변수를 가지고 있음.
	if (pArr == NULL) printf("동적할당 실패함.\n");
	// 2. 각 행별 열의 갯수만큼 동적 할당하기.
	for (int i = 0; i < *sizeRow; i++) {
		*(pArr + i) = (int*)malloc(sizeof(int) * (*sizeCol)); // 선언된 10개의 포인터 변수에 각각 10개의 히위 포인터 변수를 선언함.
	}

	return 0;

	if (*(*(pArr) + 0) == NULL) printf("하위 동적할당 실패함.\n");
	int cnt = 1;
	for (int i = 0; i < *sizeRow; i++) {
		for (int j = 0; j < *sizeCol; j++) {
			*(*(pArr + i) + j) = cnt;
			cnt++;
			printf("%3d ", *(*(pArr + i) + j));
		}
		printf("\n");
	}

}


