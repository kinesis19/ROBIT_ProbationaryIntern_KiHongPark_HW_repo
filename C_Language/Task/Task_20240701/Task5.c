#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int number, i, j, k, space, cnt;

	// ���� ����ϱ�
	printf("���� �Է��ϼ���.");

	// �� �Է¹ޱ�
	scanf_s("%d", &number);

	// �˰��� ���� �� ����ϱ�
	cnt = 1;
	space = (number * 2) - 2;
	for (i = 0; i < (number * 2); i++) {

		if (i < number) {
			for (j = 0; j < cnt; j++) {
				printf("*");
			}
			for (k = 0; k < space; k++) {
				printf(" ");
			}
			for (j = 0; j < cnt; j++) {
				printf("*");
			}
			cnt++;
			space -= 2;
			/*printf("%d %d %d", space, cnt, i);*/
		}else if(i == number) {
			space = 0;
			continue;
			/*printf("%d", i);*/
		}else if(i > number){
			cnt -= 1;
			space += 2;
			/*printf("%d %d %d", space, cnt, i);*/
			for (j = 0; j < cnt - 1; j++) {
				printf("*");
			}
			for (k = 0; k < space; k++) {
				printf(" ");
			}
			for (j = 0; j < cnt - 1; j++) {
				printf("*");
			}
		}

		printf("\n");
	}

	return 0;
}