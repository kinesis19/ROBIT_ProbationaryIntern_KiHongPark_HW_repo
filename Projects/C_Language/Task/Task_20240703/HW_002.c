#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int inputNum = 0, numAry[20] = { 0, }; // numAry : ��Ҹ� �����ϴ� ����(�迭)
	char operator[10] = { 0, }; // add, remove ���� �ܾ� ���� �迭
	int i, j, aryIndex = 0;

	// ���� ����ϱ�
	printf("������ �����ϼ���. (1 <= x <= 20");
	printf("\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n");

	while (1) {
	
		printf("input : ");
		scanf("%s %d", &operator, &inputNum);

		// ����ó�� (inputNum ���� ���� �ʿ�)
		if (!strcmp(operator, "stop")) {
			printf("Stopped!");
			break;
		}

		// ��� ������ ���ϱ�
		if (!strcmp(operator, "add")) {
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					// �����
					printf("�߰��� �� �����ϴ�.\n");
					break;
				}else{
					numAry[aryIndex] = inputNum;
					printf("���� : { ");
					for (j = 0; j <= aryIndex; j++) {
						printf("%d, ", numAry[j]);
					}
					printf("}\n\n");
					aryIndex++;
					break;
				}

			}
		}
		else if (!strcmp(operator, "remove")) {

		}
		else if (!strcmp(operator, "check")) {

		}
		else if (!strcmp(operator, "toggle")) {

		}
		else if (!strcmp(operator, "all")) {

		}
		else if (!strcmp(operator, "empty")) {

		}


	}


	
	


	return 0;
}