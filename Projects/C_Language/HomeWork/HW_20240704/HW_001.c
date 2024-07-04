#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	/* ���� �����ϱ�.
	*
	* tempNum : ���ڸ� pArr�� ���� ��, �ش� ������ ������ ��Ÿ��.
	* 
	*/

	int num1, num2, i, j, cnt = 0, tempNum = 1;
	// pArr ���� index Checker
	int aryIdx1 = 0, aryIdx2 = 0;
	/* aryIdx1�� aryIdx2�� ��ȭ�� �ֱ� ���� �� ������.
	* (but, boolean�� �� ��� �����̹Ƿ� int type�� �����)
	* 0 : false, 1 : true
	* aryIdx1(isHigh)�� ���� 0�� �� : High(1), num1�� �� : Low(0).
	* aryIdx2(isLeft)�� ���� 0�� �� : Left(1), num2�� �� : Left(0).
	* spaceHigh, spaceLeft : �� ������ ȸ���� ���� ������, �� ĭ �پ ä���� �ϴ����� ��Ÿ��.
	*/ 
	int isHigh = 0, isLeft = 0, spaceHigh = 1, spaceLeft = 1;

	// ���� ����� �ϱ�.
	printf("�Է� : ");
	scanf("%d %d", &num1, &num2);
	int* pArr;

	/* ���� �Ҵ��ϱ�.
	* ���� ������ X -> ���� ������ ������ ����� �ʾұ� ������.
	* int type�� 2���� �迭 ���� -> �ش� ������ ���� �迭 (������ �迭)�� �Ҵ��ϱ�
	*/
	pArr = (int*)calloc((num1 * num2), sizeof(int));
	
	// ��� ���� ������ ���� for��.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// ��� ���� �����ϱ�
			if ((num2 - 1) / 2 == j && (num1 - 1) / 2 == i) {
				pArr[cnt] = tempNum; // tempNum = 1
				aryIdx1 = (num1 - 1) / 2;
				aryIdx2 = (num2 - 1) / 2;
				tempNum++;
			}else if((num2 - 1) / 2 == j && i == (num1 - 1) / 2 + 1){ // ��� ���� �ٷ� �Ʒ��� ��,
				/* �ݺ��� Ż���ϱ�.
				* -> ��� ���ڸ� ������ ��� ���ڸ� ä��� ���� �ݺ����� Ż����.
				*/
				pArr[cnt] = tempNum; // cnt = 12, tempNum = 2
				break;
			}
			cnt++;
		}
	}

	// ��� ���� ���ڸ� �����ϴ� for��.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// ���� �ۼ��ϴ� �˰���.
			printf("%d %d - %d %d\n", aryIdx1, aryIdx2, isHigh, isLeft);

		}
		printf("\n");
	}

	// Debugging: pArr Index
	printf("%d %d\n\n", aryIdx1, aryIdx2);


	cnt = 0;

	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			printf("%d ", pArr[cnt]);
			cnt++;
		}
		printf("\n");
	}


	free(pArr);

}