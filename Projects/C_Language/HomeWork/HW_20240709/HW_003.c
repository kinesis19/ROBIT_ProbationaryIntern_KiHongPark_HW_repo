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
	print(&row, &col, arr);

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
			printf("%d ", *(*(pArr + 0) + 0));
		}
		printf("\n");
	}
}

// ������ ���Ŀ� �°� �����ϴ� �Լ�.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	printf("%d %d\n\n", *sizeRow, *sizeCol);
	printf("%d\n\n", sizeof(int) * (*sizeRow));
	// 2���� ���� �޸� �Ҵ��ϱ�.
	// 1. ���� ������ŭ 2���� �迭 ���� �Ҵ��ϱ�.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	if (pArr == NULL) printf("�����Ҵ� ������.");
	for (int i = 0; i < *sizeRow; i++) {

		printf("%d ", pArr);

	}
	// 2. �� �ະ ���� ������ŭ ���� �Ҵ��ϱ�.
	for (int i = 0; i < *sizeRow; i++) {
		printf("aa\n");
		pArr[i] = (int*)malloc(sizeof(int) * (*sizeCol));
	}

}


