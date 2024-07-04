#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double GettingDecimalPoint(int num1, int num2, int num3);

int main() {

	// ���� �����ϱ�.
	int inputNum;
	int i, j;

	// ���� ����ϱ�.
	printf("�Է� : ");
	scanf_s("%d", &inputNum);

	/* �л� �̸� �迭, ���� �迭
	* �̸��� ���̴� �ȳ��Ǿ� ���� �����Ƿ�, ���Ƿ� ������.
	*/
	char* chAry = (char*)calloc(inputNum, sizeof(char) * 100); // �̸� ���� �迭
	int* pAry1 = (int*)calloc(inputNum, sizeof(int)); // ���� 1 ���� �迭
	int* pAry2 = (int*)calloc(inputNum, sizeof(int)); // ���� 2 ���� �迭
	int* pAry3 = (int*)calloc(inputNum, sizeof(int)); // ���� 3 ���� �迭
	double* pArySort = (double*)calloc(inputNum, sizeof(double)); // ���� ���� �迭
	int* nameCntAry = (int*)calloc(inputNum, sizeof(int)); // �̸��� ���� index�� �˱� ���� �迭
	int* nameStartCntAry = (int*)calloc(inputNum, sizeof(int)); // �̸��� ���� index�� �˱� ���� �迭 (��¿�)

	/*nameCntAry[0] = 0;*/
	int tempIdx = 0;
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		if (chAry[tempIdx] == NULL) {
			scanf("%s %d %d %d", &chAry[tempIdx], &pAry1[i], &pAry2[i], &pAry3[i]);

			while (1){
				if (chAry[tempIdx] == NULL) {
					nameCntAry[i] = tempIdx;
					nameStartCntAry[i] = nameCntAry[i];
					break;
				}else{
					tempIdx++;
				}
			}
		}
	}

	// �迭�� �Ҵ��ϱ�.
	for (i = 0; i < inputNum; i++) {
		double examAvg = GettingDecimalPoint(pAry1[i], pAry2[i], pAry3[i]);
		// ���� ���� �迭�� �� �Ҵ��ϱ� - �ʱ� �Ҵ�
		pArySort[i] = examAvg;
	}

	// �迭 �����ϱ�.
	for (i = 0; i < inputNum; i++) {
		// ���� �����ϱ�
		for (j = 0; j < inputNum; j++) {
			if (j + 1 < inputNum && pArySort[j] < pArySort[j + 1]) {
				// ���� �����ϱ�.
				double tempNum;
				tempNum = pArySort[j];
				pArySort[j] = pArySort[j + 1];
				pArySort[j + 1] = tempNum;


				// �̸� �����ϱ�.
				int tempChar;
				tempChar = nameStartCntAry[j];
				nameStartCntAry[j] = nameStartCntAry[j + 1];
				nameStartCntAry[j + 1] = tempChar;

			}
		}

	}
	nameStartCntAry[j] = 0;


	// Debugging
	/*for (i = 0; i < 5; i++) {
		printf("\n%lf", pArySort[i]);
	}
	printf("\n");
	*/
	for (i = 0; i < 5; i++) {
		printf("%d ", nameCntAry[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", nameStartCntAry[i]);
	}

	// ���ĵ� �迭 ����ϱ�
	int tempCnt = 0;
	int tempStart = 0;
	i = 0;
	tempStart = nameStartCntAry[i + 1];
	printf("��� : \n");
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		// �̸� ����ϱ�
		for (j = tempStart; j < nameStartCntAry[i]; j++) {
			printf("%c", chAry[j]);
		}
		while (1) {
			if (tempStart < nameStartCntAry[i]) {
				tempStart++;
			}else {
				break;
			}
		}
		
		
		/*for (j = tempCnt; j < nameCntAry[i]; j++) {
			printf("%c", chAry[j]);
		}
		while (1) {
			if (tempCnt < nameCntAry[i]) {
				tempCnt++;
			}else {
				break;
			}
		}*/
		printf(" ");
		// ����ϱ�
		if ((int)(pArySort[i] * 10) % 10 == 0) {
			printf("%d", (int)pArySort[i]);
		}else {
			printf("%.1lf", pArySort[i]);
		}
		printf(" %d \n", tempStart);


	}


	free(chAry);
	free(pAry1);	
	free(pAry2);
	free(pAry3);
	free(pArySort);
	free(nameCntAry);

	return 0;
}

double GettingDecimalPoint(int num1, int num2, int num3) {
	/*
	* �Ҽ��� �� �ڸ� ����� ������.
	* �׳� ����ϸ� �Ҽ����� �߸� ��� �Ǵ� ��찡 ������.
	* ����, �Ҽ��� ��° �ڸ����� ���ϰ�, ��° �ڸ��� ���ڸ� ��տ��� ���ֵ��� ������.
	* e.x) ��� : 50.66
	* 1. 50.66
	* 2. 506.6 <- 1
	* 3. 506.0 
	* 4. 50.6 -> 1
	* ������ �� : 50.6 (-0.06)
	* �Ҽ��� ���ϴ� ���ĵ� ������ ������ �����ؼ� �ѵ���.
	* ��� ������ ��Ģ��� �ΰ����� �̻��, ���ͳ� �˻�X, ���۷��� ����X, 
	* ���� ���� �ڷḸ�� �����Ͽ� ������.
	*/ 
	double result = 0;
	result = (num1 + num2 + num3) / 3.0;

	result = (int)(result * 10) / 10.0;

	return result;
}