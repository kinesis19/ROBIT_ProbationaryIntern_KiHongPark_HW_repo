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

	if (arr == NULL) printf("arr�� �����Ҵ� ������.\n");
	printf("aaaaaaaa\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("hhhhhh\n");
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

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
	printf("bbb");
	printf("%3d ", pArr[0][0]);
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf("%3d ", pArr[i][j]);
		}
		printf("\n");
	}
}

// ������ ���Ŀ� �°� �����ϴ� �Լ�.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {
	// 2���� ���� �޸� �Ҵ��ϱ�.
	// 1. ���� ������ŭ 2���� �迭 ���� �Ҵ��ϱ�.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow)); // 10���� ������ ���� ������. = pArr�� 10���� ������ ������ ������ ����.
	if (pArr == NULL) printf("�����Ҵ� ������.\n");
	// 2. �� �ະ ���� ������ŭ ���� �Ҵ��ϱ�.
	for (int i = 0; i < *sizeRow; i++) {
		*(pArr + i) = (int*)malloc(sizeof(int) * (*sizeCol)); // ����� 10���� ������ ������ ���� 10���� ���� ������ ������ ������.
	}

	return 0;

	if (*(*(pArr) + 0) == NULL) printf("���� �����Ҵ� ������.\n");
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


