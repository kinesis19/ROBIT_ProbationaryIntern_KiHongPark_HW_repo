#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int number, i, j, paddingLeftRight, paddingMiddle, 
		cnt = 0;
	
	// ���� ����ϱ�
	printf("���� �Է��ϼ���. ");
	scanf_s("%d", &number);

	// Padding �����ϱ�
	paddingLeftRight = number - 1;
	paddingMiddle = 0;

	for (i = 0; i < number; i++) {
		for (j = 0; j <= paddingLeftRight; j++) {
			printf(" ");
		}
		for () {
			printf("*");
		}
		for (j = 0; j < paddingMiddle; j++) {
			printf(" ");
		}

		paddingLeftRight -= 1;
		paddingMiddle++;
		printf("\n");
	}


	return 0;
}