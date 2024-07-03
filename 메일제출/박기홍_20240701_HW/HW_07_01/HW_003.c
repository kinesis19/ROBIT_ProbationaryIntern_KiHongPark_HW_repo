#include <stdio.h>

int main() {

	// 변수 선언하기
	int inputYear;

	// 형식 출력하기
	printf("년도를 입력하세요 : ");

	// 값 입력받기
	scanf_s("%d", &inputYear);
	
	// 윤년 계산 및 결과값 출력하기
	if ((inputYear % 4 == 0) && (inputYear % 100 != 0) || (inputYear % 400 == 0)) {
		printf("윤년");
	}else{
		printf("윤년이 아닙니다.");
	}


	return 0;
}