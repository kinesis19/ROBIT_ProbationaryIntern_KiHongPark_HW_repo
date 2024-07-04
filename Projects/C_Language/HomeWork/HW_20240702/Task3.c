#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CheckingScale(char inputString[8]);

int main() {

	// 변수 선언하기
	char userInput[8] = { ' ', };
	int i;

	// 형식 출력하기
	printf("음 입력\n");
	for (i = 0; i < 8; i++) {
		scanf("%c", &userInput[i]);
	}
	
	switch (CheckingScale(userInput))
	{
	case 1:
		printf("결과 : ascending\n");
		break;
	case 2:
		printf("결과 : descending\n");
		break;
	case 3:
		printf("결과 : mixed\n");
		break;
	default:
		break;
	}	

	return 0;
}

int CheckingScale(char inputString[8]) {
	// 변수 선언하기
	char stringAscending[8] = "cdefgabC";
	char stringDescending[8] = "Cbagfedc";
	int i, j, cntScale1 = 0, cntScale2 = 0; // cntScale : Scle 체크 변수

	for (i = 0; i < 8; i++) {
		if (inputString[i] == stringAscending[i]) {
			cntScale1++;
		}else if(inputString[i] == stringDescending[i]){
			cntScale2++;
		}
	}

	if (cntScale1 == 8) {
		return 1;
	}else if (cntScale2 == 8) {
		return 2;
	}else{
		return 3;
	}
}