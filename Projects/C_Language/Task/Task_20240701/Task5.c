#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////���� 1
//int main() {
//
//	// ���� �����ϱ�
//	int number, i, j, k, space, cnt;
//
//	// ���� ����ϱ�
//	printf("���� �Է��ϼ���.");
//
//	// �� �Է¹ޱ�
//	scanf_s("%d", &number);
//
//	// �˰��� ���� �� ����ϱ�
//	cnt = 1;
//	space = (number * 2) - 2;
//	for (i = 0; i < (number * 2); i++) {
//
//		if (i < number) {
//			for (j = 0; j < cnt; j++) {
//				printf("*");
//			}
//			for (k = 0; k < space; k++) {
//				printf(" ");
//			}
//			for (j = 0; j < cnt; j++) {
//				printf("*");
//			}
//			cnt++;
//			space -= 2;
//			/*printf("%d %d %d", space, cnt, i);*/
//		}else if(i == number) {
//			space = 0;
//			continue;
//			/*printf("%d", i);*/
//		}else if(i > number){
//			cnt -= 1;
//			space += 2;
//			/*printf("%d %d %d", space, cnt, i);*/
//			for (j = 0; j < cnt - 1; j++) {
//				printf("*");
//			}
//			for (k = 0; k < space; k++) {
//				printf(" ");
//			}
//			for (j = 0; j < cnt - 1; j++) {
//				printf("*");
//			}
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}


//// ����2
int main(void) {

	int i, j, number;

	printf("���� �Է��Ͻÿ�.");
	scanf("%d", &number);

	for (i = 0; i < (number * 2) - 1; i++) {
		for (j = 0; j < (number * 2); j++) {
			if ((j <= i || j >= (number * 2) - i - 1) && i <= number - 1) {
				printf("*");
			}else if (i > number - 1 && j < i -1) {
				printf("*");
			}else {
				printf(" ");
			}
		}
		printf("\n");
	}



	return 0;
}