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

	if (arr == NULL) printf("���� �Ҵ� ���� �ʾҽ��ϴ�.");
	else if (arr != NULL) printf("���������� ���� �Ҵ� �Ǿ����ϴ�.");
	// �迭 arr ����ϱ�.
	/*print(&row, &col, &arr);*/

	// ���� �޸� �����ϱ�.
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}

	return 0;
}

// ������ ���Ŀ� �°� ����ϴ� �Լ�.
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

// ������ ���Ŀ� �°� �����ϴ� �Լ�.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	int inputNum = 1; // �迭�� ���� ���� ����.
	int change = 0; // change�� 10�� �� ������ ��� ���� ��ȣ�� ������.
	// 2���� �迭 �����.
	// 1, sizeRow ��ŭ�� ������ �迭�� ���� �Ҵ���.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	if (pArr == NULL) printf("�����Ҵ� ������.\n");
	for (int i = 0; i < (*sizeRow); i++) {
		// 2. ������ ������ �迭 ��ҿ� sizeCol ��ŭ�� ������ �迭�� ���� �Ҵ���.
		*(pArr + i) = (int*)malloc(sizeof(int) * (*sizeCol));
	}

	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			*(*(pArr + i) + j) = 0;
		}
	}





	// �ӽ� ����ϱ�.
	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			printf("%3d[%d][%d] ", *(*(pArr + i) + j), i, j);
		}
		printf("\n");
	}
	printf("\n\n%d\n\n", *(*(pArr + 0) + 9));
	/*print(sizeRow, sizeCol, pArr);*/

}


