#include <stdio.h>

int main(void) {

	// 변수 선언하기
	float num1, num2, num3, num4, num5;
	float sum, avg, max, min;
	int i, j;

	// 출력 및 입력 받기
	printf("1 번째 실수를 입력하시오. ");
	scanf_s("%f", &num1);
	printf("2 번째 실수를 입력하시오. ");
	scanf_s("%f", &num2);
	printf("3 번째 실수를 입력하시오. ");
	scanf_s("%f", &num3);
	printf("4 번째 실수를 입력하시오. ");
	scanf_s("%f", &num4);
	printf("5 번째 실수를 입력하시오. ");
	scanf_s("%f", &num5);

	// 평균 구하기
	sum = (num1 + num2 + num3 + num4 + num5);
	avg = sum / 5;

	//TODO: 최댓값 구하기
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

	//TODO: 최솟값 구하기
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

	printf("---- 결과 ----\n");
	printf("평균은 %f입니다.\n", avg);
	printf("최댓값은 %f입니다.\n", max);
	printf("최솟값은 %f입니다.", min);

	return 0;
}