#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void DrawingStar_Type1(int sizeGuide);
void DrawingStar_Type2(int sizeGuide);
void DrawingStar_Type3(int sizeGuide);
void DrawingStar_Type4(int sizeGuide);

int main() {

	// 변수 선언하기
	int size, type;

	printf("사이즈와 종류를 입력하시오.");
	// 선배님께서 말씀하신 입력 조건 : size = 홀수만, max : 9
	scanf("%d %d", &size, &type);

	switch (type)
	{
	case 1:
		DrawingStar_Type1(size);
		break;
	case 2:
		DrawingStar_Type2(size);
		break;
	case 3:
		DrawingStar_Type3(size);
		break;
	case 4:
		DrawingStar_Type4(size);
		break;
	default:
		break;
	}

	return 0;
}

// 종류 1 출력하는 알고리즘
void DrawingStar_Type1(int sizeGuide) {

	int i, j;
	for (i = 0; i < sizeGuide; i++) {
		for (j = 0; j <=i; j++) {
			if (j <= i && j < sizeGuide - i) {
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}


// 종류2 출력하는 알고리즘
void DrawingStar_Type2(int sizeGuide) {

	int i, j;
	for (i = 0; i < sizeGuide; i++) {
		for (j = 0; j < sizeGuide - 2; j++) {
			if (j < sizeGuide - 3 - i || j <= i- 3) {
				printf(" ");
			}else {
				printf("*");
			}
		}
		printf("\n");
	}
}

// 종류3 출력하는 알고리즘
void DrawingStar_Type3(int sizeGuide) {

	int i, j;
	for (i = 0; i < sizeGuide; i++) {
		for (j = 0; j < sizeGuide; j++) {
			if ((i <= j && j < sizeGuide - i) || i >= j && (sizeGuide - (i + 1) <= j)) {
				printf("*");
			}else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// 종류4 출력하는 알고리즘
void DrawingStar_Type4(int sizeGuide) {

	int i, j;
	for (i = 0; i < sizeGuide; i++) {
		for (j = 0; j < sizeGuide; j++) {
			if ((j >= i && j <= (sizeGuide - 1) / 2) || i > ((sizeGuide - 1) / 2) && ((j >= (sizeGuide - 1) /2) && j <= i)) {
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}