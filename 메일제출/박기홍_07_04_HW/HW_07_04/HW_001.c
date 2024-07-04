#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	/* ���� �����ϱ�.
	* tempNum : ���ڸ� pArr�� ���� ��, �ش� ������ ������ ��Ÿ��.
	*/

	int num1, num2, i, j, cnt = 0, tempCnt = 0, tempNum = 1;
	// pArr ���� index Checker
	int aryIdxX = 0, aryIdxY = 0;
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

	/* ���� �Ҵ��ϱ�.
	* ���� ������ X -> ���� ������ ������ ����� �ʾұ� ������.
	* int type�� 2���� �迭 ���� -> �ش� ������ ���� �迭 (������ �迭)�� �Ҵ��ϱ�
	*/
	int* pArr = (int*)calloc((num1 * num2), sizeof(int));

	/* �迭�� ���� ��(= ��� ��)
	* refX = j, refY = i.
	*/
	int refX = 0, refY = 0; 

	// ��� ���� ������ ���� for��.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// ��� ���� �����ϱ�
			if ((num2 - 1) / 2 == j && (num1 - 1) / 2 == i) {
				pArr[tempCnt] = tempNum; // tempNum = 1
				aryIdxY = (num1 - 1) / 2;
				aryIdxX = (num2 - 1) / 2;
				tempNum++;
				refX = aryIdxX;
				refY = aryIdxY;
			}else if((num2 - 1) / 2 == j && i == (num1 - 1) / 2 + 1){ // ��� ���� �ٷ� �Ʒ��� ��,
				/* �ݺ��� Ż���ϱ�.
				* -> ��� ���ڸ� ������ ��� ���ڸ� ä��� ���� �ݺ����� Ż����.
				*/
				pArr[tempCnt] = tempNum; // tempCnt = 12, tempNum = 2
				cnt = tempCnt;
				aryIdxY++;
				break;
			}
			tempCnt++;
		}
	}
	/*printf("%d %d %d\n", cnt, tempCnt, tempNum);
	printf("%d %d %d %d\n", aryIdxX, aryIdxY, refX, refY);*/

	// ��� ���� ���ڸ� �����ϴ� for��.
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			// ���� �ۼ��ϴ� �˰���.
			if (aryIdxX > refX) {
				if (aryIdxY > refY) {
					aryIdxX++;
					aryIdxY--;
					/*printf("%d %d\n\n", aryIdxX, aryIdxY);*/
				}
			}else if(aryIdxX == refX){
				if (aryIdxY > refY) {
					aryIdxX++;
					aryIdxY--;
					pArr[tempCnt] = ++tempNum;
					/*printf("%d %d\n\n", aryIdxX, aryIdxY);*/
				}
			}
		}
	}
	


	cnt = 0;
	// ���� ��� �˰���.
	printf("\n��� : ");
	for (i = 0; i < num1; i++) {
		if (i != 0) { // ��� ������ �ؼ��ϱ� ���� ���ǹ�.
			printf("       ");
		}
		for (j = 0; j < num2; j++) {
			printf("%d ", pArr[cnt]);
			cnt++;
		}
		printf("\n");
	}


	free(pArr);

}