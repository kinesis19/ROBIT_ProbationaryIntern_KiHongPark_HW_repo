#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print(int* row, int* col, int** pArr);
void arr_ij(int* sizeRow, int* sizeCol, int** pArr);

int main() {

	// ���������� ���� �� �Ϲ� ���� �����ϱ�.
	int** arr = NULL;
	int row, col, sizeRow, sizeCol;
	
	// ����� �ޱ�.
	printf("���� ���� �Է��ϼ���:");
	scanf("%d", &sizeCol);
	printf("���� ���� �Է��ϼ���:");
	scanf("%d", &sizeRow);

	// ���� �Ҵ��ϱ�.
	row = sizeRow;
	col = sizeCol;

	// 2���� ���� �޸� �Ҵ��ϱ�.
	arr_ij(&sizeRow, &sizeCol, arr);

	// �迭 arr ����ϱ�.
	/*print(&row, &col, arr);*/

	// ���� �޸� �����ϱ�.
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}

	return 0;
}

// ������ ���Ŀ� �°� ����ϴ� �Լ�.
void print(int* row, int* col, int** pArr) {

	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf("%3d ", *(*(pArr + i) + j));
		}
		printf("\n");
	}

}

// ������ ���Ŀ� �°� �����ϴ� �Լ�.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	int cnt = 1;
	// 2���� �迭 �����.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	if (pArr == NULL) printf("�����Ҵ� ������.\n");
	for (int i = 0; i < (*sizeRow); i++) {
		pArr[i] = (int*)malloc(sizeof(int) * (*sizeCol));
	}

	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			*(*(pArr + i) + j) = cnt;
			cnt++;
		}
	}

	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			printf("%d ", *(*(pArr + i) + j));
		}
		printf("\n");
	}

	print(sizeRow, sizeCol, pArr);

}


