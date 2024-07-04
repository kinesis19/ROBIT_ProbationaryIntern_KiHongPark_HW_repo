#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double GettingDecimalPoint(int num1, int num2, int num3);

int main() {

	// ���� �����ϱ�.
	int inputNum;
	int i;

	// ���� ����ϱ�.
	printf("�Է� : ");
	scanf("%d", &inputNum);

	/* �л� �̸� �迭, ���� �迭
	* �̸��� ���̴� �ȳ��Ǿ� ���� �����Ƿ�, ���Ƿ� ������.
	*/
	int* chAry = (int*)calloc(inputNum, sizeof(char));
	int* pAry1 = (int*)calloc(inputNum, sizeof(int));
	int* pAry2 = (int*)calloc(inputNum, sizeof(int));
	int* pAry3 = (int*)calloc(inputNum, sizeof(int));

	
	for (i = 0; i < inputNum; i++) {
		printf("       ");
		scanf("%s %d %d %d", &chAry[i], &pAry1[i], &pAry2[i], &pAry3[i]);
	}

	printf("��� : \n");
	// Debugging
	/*for (i = 0; i < inputNum; i++) {
		printf("       ");
		printf("%s\n", &chAry[i]);
		printf("%d %d %d\n", pAry1[i], pAry2[i], pAry3[i]);
	}*/


	for (i = 0; i < inputNum; i++) {
		double examAvg = GettingDecimalPoint(pAry1[i], pAry2[i], pAry3[i]);

		printf("       ");
		// ��� ���Ŀ� �˸°� �Ҽ��� �� �ڸ������� ǥ����.

		if ((int)(examAvg * 10) % 10 == 0) {
			printf("%s %d\n", &chAry[i], (int)examAvg);
		}else {
			printf("%s %.1lf\n", &chAry[i], examAvg);
		}

	}
	
	/*
	free(chAry);
	free(pAry1);
	free(pAry2);
	free(pAry3);*/

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