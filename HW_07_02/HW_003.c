#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CheckingScale(char inputString[8]);

int main() {

	// ���� �����ϱ�
	char userInput[8] = { ' ', };
	int i;

	// ���� ����ϱ�
	printf("�� �Է�\n");
	for (i = 0; i < 8; i++) {
		scanf("%c", &userInput[i]);
	}
	
	switch (CheckingScale(userInput))
	{
	case 1:
		printf("��� : ascending\n");
		break;
	case 2:
		printf("��� : descending\n");
		break;
	case 3:
		printf("��� : mixed\n");
		break;
	default:
		break;
	}	

	return 0;
}

int CheckingScale(char inputString[8]) {
	// ���� �����ϱ�
	char stringAscending[8] = "cdefgabC";
	char stringDescending[8] = "Cbagfedc";
	int i, j, cntScale1 = 0, cntScale2 = 0; // cntScale : Scle üũ ����

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