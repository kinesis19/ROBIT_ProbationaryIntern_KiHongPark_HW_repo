#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void myPrint1(int* a, int row, int col);
void myPrint2(int a[4][3], int row, int col);
void myPrint3(int a[][3], int row, int col);
void myPrint4(int* (a)[3], int row, int col);

int main() {

	int arr[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	myPrint1(arr, row, col);
	myPrint2(arr, row, col);
	myPrint3(arr, row, col);
	myPrint4(arr, row, col);

	return 0;
}


void myPrint1(int* a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) printf("%d ", *(a + i * col + j));
	}
	printf("\n");
}
void myPrint2(int a[4][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) printf("%d ", a[i][j]);
	}
	printf("\n");
}
void myPrint3(int a[][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) printf("%d ", a[i][j]);
	}
	printf("\n");
}
void myPrint4(int* (a)[3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) printf("%d ", *(*(a + i) + j));
	}
	printf("\n");
}