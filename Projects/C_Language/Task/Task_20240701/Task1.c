#include <stdio.h>

int main(void) {

	// ���� �����ϱ�
	float num1, num2, num3, num4, num5;
	float sum, avg, max, min;
	int i, j;

	// ��� �� �Է� �ޱ�
	printf("1 ��° �Ǽ��� �Է��Ͻÿ�. ");
	scanf_s("%f", &num1);
	printf("2 ��° �Ǽ��� �Է��Ͻÿ�. ");
	scanf_s("%f", &num2);
	printf("3 ��° �Ǽ��� �Է��Ͻÿ�. ");
	scanf_s("%f", &num3);
	printf("4 ��° �Ǽ��� �Է��Ͻÿ�. ");
	scanf_s("%f", &num4);
	printf("5 ��° �Ǽ��� �Է��Ͻÿ�. ");
	scanf_s("%f", &num5);

	// ��� ���ϱ�
	sum = (num1 + num2 + num3 + num4 + num5);
	avg = sum / 5;

	//TODO: �ִ� ���ϱ�
	max = num1;
	for (i = 0; i < 5; i++) {
		if (max < num1) {
			max = num1;
		}else if(max < num2){
			max = num2;
		}else if(max < num3){
			max = num3;
		}else if(max < num4){
			max = num4;
		}else if(max < num5){
			max = num5;
		}
	}

	//TODO: �ּڰ� ���ϱ�
	min = num1;
	for (i = 0; i < 5; i++) {
		if (min > num1) {
			min = num1;
		}else if (min > num2) {
			min = num2;
		}else if (min > num3) {
			min = num3;
		}else if (min > num4) {
			min = num4;
		}else if (min > num5) {
			min = num5;
		}
	}

	printf("---- ��� ----\n");
	printf("����� %f�Դϴ�.\n", avg);
	printf("�ִ��� %f�Դϴ�.\n", max);
	printf("�ּڰ��� %f�Դϴ�.", min);

	return 0;
}