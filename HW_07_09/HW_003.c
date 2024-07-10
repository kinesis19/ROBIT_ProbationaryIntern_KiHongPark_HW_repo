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

	int cntRow = 0, cntCol = 0;
	int inputNumLast = 0; // ������ ���� ����� (��, ��). inputNum���� �ٸ�.
	int head = 1; // 1 : ������, 2 : �Ʒ�, 3 : ����, 4 : ����.
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;


	for (int i = 0; i < (*sizeRow); i++) {
		change = 0;

		for (int j = 0; j < (*sizeCol); j++) {
			int tempInputNum = inputNum;
			// ���� 1ȸ inputNumLast �����ϱ�.
			if (i == 0 && head == 1) {
				inputNumLast = inputNum;
				t1++;
			}

			if (((0 < i && i < 9) && j == (*sizeCol) - 1) && head == 2) { // �� ���
				inputNumLast++;
				inputNum = inputNumLast;
				*(*(pArr + i) + j) = inputNum;
				t2++;
			}else if ((i == (*sizeRow) - 1 && j < ((*sizeCol))) && head ==  3) {
				inputNumLast++;
				inputNum = inputNumLast;
				*(*(pArr + i) + (*sizeCol) - 1 - j) = inputNum;
				t3++;
			}else if ((j == 0 && (0 < i && i < 9)) && head == 4) {
				inputNumLast++;
				inputNum = inputNumLast;
				*(*(pArr + i) + j) = 0;
				t4++;
			}else{
				*(*(pArr + i) + j) = inputNum;
			}

			inputNum = tempInputNum;

			// ���� �����ϱ�.
			change++;
			inputNum++;
		}
		cntRow++;
		if (t1 == (*sizeCol) - 2 || t1 == (*sizeCol)) {
			/*printf("t1 : %d\n\n\n\n", t1);*/
			t1 = 0;
			t2 = 0;
			t3 = 0;
			t4 = 0;
			head = 2;
		}else if (t2 == (*sizeCol) - 2) {
			/*printf("t2 : %d\n\n\n\n", t2);*/
			t1 = 0;
			t2 = 0;
			t3 = 0;
			t4 = 0;
			head = 3;
		}else if (t3 == (*sizeRow) - 2 || t3 == (*sizeCol)) {
			/*printf("t3 : %d\n\n\n\n", t3);*/
			t1 = 0;
			t2 = 0;
			t3 = 0;
			t4 = 0;
			head = 4;
		}else if (t4 == (*sizeCol) - 3) {
			/*printf("t4 : %d\n\n\n\n", t4);*/
			t1 = 0;
			t2 = 0;
			t3 = 0;
			t4 = 0;
			head = 1;
		}
		/*printf("t4 : %d\n\n\n\n", t4);*/

	}

	for (int i = 0; i < (*sizeRow); i++) {
		for (int j = 0; j < (*sizeCol); j++) {
			printf("%3d ", *(*(pArr + i) + j));
			/*printf("%3d[%d][%d] ", *(*(pArr + i) + j), i, j);*/
		}
		printf("\n");
	}
	printf("\n\n%d\n\n", *(*(pArr + 0) + 9));
	/*print(sizeRow, sizeCol, pArr);*/

}


