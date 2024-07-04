#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void DrawingStar_Type1(int sizeGuide);
void DrawingStar_Type2(int sizeGuide);
void DrawingStar_Type3(int sizeGuide);
void DrawingStar_Type4(int sizeGuide);

int main() {

	// ���� �����ϱ�
	int size, type;

	printf("������� ������ �Է��Ͻÿ�.");
	// ����Բ��� �����Ͻ� �Է� ���� : size = Ȧ����, max : 9
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

// ���� 1 ����ϴ� �˰���
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


// ����2 ����ϴ� �˰���
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

// ����3 ����ϴ� �˰���
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

// ����4 ����ϴ� �˰���
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