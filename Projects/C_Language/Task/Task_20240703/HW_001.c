#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�.
	int min = 0, max = 0, squareCnt = 0;
	// ���� �������� ��� �迭.
	int squareNumAry[10000] = { 1, 0, };
	int i;

	// ���� ����ϱ�.
	printf("%min : ");
	scanf("%d", &min);
	printf("%max : ");
	scanf("%d", &max);
	printf("%���� ������ : %d��\n", squareCnt);

	for (i = 0; i < 10000; i++) {
		if (squareNumAry[i] == 0) {
			break;
		}else{
			printf("%d ", squareNumAry[i]);
		}
	}

	return 0;
}