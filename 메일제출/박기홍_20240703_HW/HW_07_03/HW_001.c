#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�.
	int min = 0, max = 0, squareCnt = 0;
	// ���� �������� ��� �迭.
	int squareNumAry[10000] = { 0, };
	int i, j, isSquare = 0;

	// ���� ����ϱ�.
	printf("%min : ");
	scanf("%d", &min);
	printf("%max : ");
	scanf("%d", &max);

	// ���� ������ ���ϱ�
	/*
	* �����ϴ� ���� : (� �� X) % (���� ��) != 0->���� ������.
	* � �� X : min�̻� ~ max ������ ��� ��.
	* ���� �� : 4, 9, 16 ~~~.
	*/ 

	for (i = min; i <= max; i++) {
		// ������ ���� �� ����
		int tempSquareNum = 0;
		for (j = 2; j < 10000; j++) {
			tempSquareNum = j * j;
			// ���� �������� �ƴ϶��
			if (i % tempSquareNum == 0) {
				isSquare = 0;
				break;
			}else{
				isSquare = 1;
			}
			// ���� �� ���� ����
		}
		if (isSquare == 1) {
			squareNumAry[squareCnt] = i;
			// ���� �������� �迭�� ���ԵǸ� �ش� �迭�� index �� ������Ű��.
			squareCnt++;
		}
		isSquare = 0;
	}



	printf("%���� ������ : %d��\n", squareCnt);


	// ���� �������� ��� �迭�� ����ϱ�
	for (i = 0; i < 10000; i++) {
		if (squareNumAry[i] == 0) {
			break;
		}else{
			printf("%d ", squareNumAry[i]);
		}
	}

	return 0;
}