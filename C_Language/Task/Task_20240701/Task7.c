#include <stdio.h>

int main(void) {

	// ���� �����ϱ�
	int num1, num2, tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1;
	int result1 = 0, result2 = 0, result3 = 0, result4 = 0;
	
	//���� ����ϱ�
	printf("n, r �Է� : ");
	scanf_s("%d %d", &num1, &num2);


	// ���� ���ϴ� �˰���
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // �ʱ�ȭ
	while (1) {
		// n! ���ϱ�
		while (1) {
			if (cntNum1 <= num1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}else if (cntNum1 > num1) {
				break;
			}
		}
		// (n - r)! ���ϱ�
		while (1) {
			if (cntNum2 <= num1 - num2) {
				tempNum2 = tempNum2 * cntNum2;
				cntNum2++;
			}else if (cntNum2 > num1 - num2) {
				break;
			}
		}
		break;
	}
	result1 = tempNum1 / tempNum2;

	// �ߺ����� ���ϴ� �˰���
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // �ʱ�ȭ
	while (1) {
		if (cntNum1 <= num2) {
			tempNum1 = tempNum1 * num1;
			cntNum1++;
		}else if(cntNum1 > num2){
			break;
		}
	}
	result2 = tempNum1;

	// ���� ���ϴ� �˰���
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // �ʱ�ȭ
	while (1) {
		// n! ���ϱ�
		while (1) {
			if (cntNum1 <= num1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}
			else if (cntNum1 > num1) {
				break;
			}
		}

		// (n - r)! ���ϱ�
		while (1) {
			if (cntNum2 <= num1 - num2) {
				tempNum2 = tempNum2 * cntNum2;
				cntNum2++;
			}else if (cntNum2 > num1 - num2) {
				break;
			}
		}
		// r! ���ϱ�
		while (1) {
			if (cntNum3 <= num2) {
				tempNum3 = tempNum3 * cntNum3;
				cntNum3++;
			}else if(cntNum3 > num2){
				break;
			}
		}
		break;
	}
	result3 = tempNum1 / (tempNum2 * tempNum3);

	// �ߺ����� ���ϴ� �˰���
	tempNum1 = 1, tempNum2 = 1, tempNum3 = 1, cntNum1 = 1, cntNum2 = 1, cntNum3 = 1; // �ʱ�ȭ
	while (1) {
		// (n + r - 1) ���ϱ�
		while (1) {
			if (cntNum1 < num1 + num2 - 1) {
				tempNum1 = tempNum1 * cntNum1;
				cntNum1++;
			}else if (cntNum1 >= num1 + num2 - 1) {
				break;
			}
		}

		// r! ���ϱ�
		while (1) {
			if (cntNum3 <= num2) {
				tempNum3 = tempNum3 * cntNum3;
				cntNum3++;
			}else if (cntNum3 > num2) {
				break;
			}
		}
		break;
	}
	printf("%d %d\n", tempNum1, tempNum3);
	result4 = tempNum1 / tempNum3;


	printf("���� ��� %d\n�ߺ����� ��� : %d\n���� ��� : %d\n�ߺ����� ��� : %d\n", result1, result2, result3, result4);


}