#include <stdio.h>

int main(void) {

	// ���� �����ϱ�
	int num, leftNum = 0, rightNum = 1, nowNum = 1;
	int i;

	// ���� ����ϱ�
	printf("n �Է� : ");
	scanf_s("%d", &num);

	printf("��� ���� : ");
	// �Ǻ���ġ �⺻ �� ǥ��
	printf("%d %d %d ", leftNum, nowNum, rightNum);

	// �Ǻ���ġ ���� ���ϱ�
	for (i = 0; i < num; i++) {
		leftNum = nowNum;
		nowNum = rightNum;
		rightNum = nowNum + leftNum;

		printf("%d ", rightNum); // ��� ���� ����ϱ�

	}

	printf("\nn��° �Ǻ���ġ �� : %d ", rightNum);


	return 0;
}
