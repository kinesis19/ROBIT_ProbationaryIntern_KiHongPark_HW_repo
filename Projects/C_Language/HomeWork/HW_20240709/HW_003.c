#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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

}

// ������ ���Ŀ� �°� �����ϴ� �Լ�.
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {

	printf("%d %d\n\n", *sizeRow, *sizeCol);
	printf("%d\n\n", sizeof(int) * (*sizeRow));
	// 2���� ���� �޸� �Ҵ��ϱ�.
	pArr = (int**)malloc(sizeof(int) * (*sizeRow));
	for (int i = 0; i < *sizeCol; i++) {
		printf("%d ", i);
	}

}


