#include <stdio.h>

int main(void) {

	// ���� �����ϱ�
	int num, leftNum = 0, rightNum = 1, nowNum = 1;
	int i;

	// ���� ����ϱ�
	printf("n���� �Է��Ͻÿ�. ");
	scanf_s("%d", &num);

	printf("%d %d %d ", leftNum, nowNum, rightNum);

	// �Ǻ���ġ ���� ���ϱ�
	for (i = 0; i < num; i++) {
		leftNum = nowNum;
		nowNum = rightNum;
		rightNum = nowNum + leftNum;

		printf("%d ", rightNum);

	}


	return 0;
}
