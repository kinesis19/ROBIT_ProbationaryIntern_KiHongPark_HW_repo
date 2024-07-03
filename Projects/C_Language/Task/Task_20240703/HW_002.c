#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int inputNum = 0, numAry[20] = { 0, }; // numAry : ��Ҹ� �����ϴ� ����(�迭)
	char operator[10] = { 0, }; // add, remove ���� �ܾ� ���� �迭
	int i, j, aryIndex = 0;
	int isOkayAdd = 1, isOkayRemove = 0, isOkayCheck = 0, isOkayToggle = 0; // boolean �����ڴ� �� ��� �����̹Ƿ� int�� boolean ������ ��ü��.

	// ���� ����ϱ�
	printf("������ �����ϼ���. (1 <= x <= 20");
	printf("\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n\n");

	while (1) {
		
		printf("input : ");
		scanf("%s %d", &operator, &inputNum);

		/* (����ó��)
		* �������� �������� �ݺ��ϴ���, ���� Ż���ϴ����� ���� ������ �� �Ǿ� ����.
		* ���� ������ �����ϱ� ���� �ݺ��� Ż�⿡ ���� ����ó���� ���Ƿ� ������.
		* ��, ������ ���õ� ��� ������ �ؼ��ϱ� ���� ���� ��¿����� stop ���� ������ �߰����� ����.
		* ����, Ctrl + C ����Ű�� ���� ���� ������ Ż���� �� ����.
		*/ 

		if (!strcmp(operator, "stop") && inputNum == 0) {
			printf("Stopped!");
			break;
		}

		// ��� ������ ���ϱ�
		if (!strcmp(operator, "add")) {
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					isOkayAdd = 0;
					break;
				}
			}
			if (isOkayAdd == 1) {
				numAry[aryIndex] = inputNum;
				printf("���� : { ");
				for (j = 0; j <= aryIndex; j++) {
					printf("%d, ", numAry[j]);
				}
				printf("}\n\n");
				aryIndex++;
			}
			isOkayAdd = 1;
		}else if (!strcmp(operator, "remove")) {
			int removeIdx = 0; // ������ ����� index ��

			// ������ �� �ִ� �������� �����ϱ�. (�ش� ���ڰ� ������ ��ҷ� ���ԵǾ� �ִ��� ����)
			for (i = 0; i < 20; i++) {
				// ���ھ� ���� ���� �ִ� ����� ���� ó��.
				if (numAry[i] == inputNum) {
					removeIdx = i;
					aryIndex--; // ��Ҹ� �߰��� ��, ����� index ������Ʈ�ϱ�
					/* ex) remove�� �� �� �Ǿ�����,
					*  �߰��� ���� index ��ġ�� �߰��� ���� index���� �� �� �ڿ��� �߰��ؾ� ��.
					*/
					isOkayRemove = 1;
					break;
				}
			}
			if (isOkayRemove == 1) {
				// ��� �����ϱ�.
				numAry[removeIdx] = 0;
				// ���ŵ� ��� �ڿ� �ִ� ��ҵ鵵 ������ �̵� ��Ű��.
				for (j = removeIdx; j < 20; j++) {
					numAry[j] = numAry[j + 1];
				}
			}
			// ����� (��� ����ϱ� - ���� ��)
			printf("���� : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf("}\n\n");
			isOkayRemove = 0;
			
		}else if (!strcmp(operator, "check")) {
			// �Էµ� ���ڰ� ���տ� ���ԵǾ� �ִ��� �����ϱ�
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					isOkayCheck = 1;
					break;
				}else{
					isOkayCheck = 0;
				}
			}
			// ����, ���� ���� �ش� ���ڰ� ������ 0�� ����ϱ�.
			// ��� ���� �� �ϳ��� *3�� ������* ����� ����.
			printf("%d ", isOkayCheck == 1 ? 1 : 0);

			printf("���� : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf("}\n\n");

		}else if (!strcmp(operator, "toggle")) {
			int removeIdx = 0;
			// �Էµ� ���ڰ� ���տ� ���ԵǾ� �ִ��� �����ϱ�
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					removeIdx = i;
					isOkayToggle = 1;
					break;
				}else {
					isOkayToggle = 0;
				}
			}
			// ���� ���տ� �ش� ���ڰ� ���� ��,
			if (isOkayToggle == 1) {
				// ��� �����ϱ�.
				numAry[removeIdx] = 0;
				aryIndex--;
				// ���ŵ� ��� �ڿ� �ִ� ��ҵ鵵 ������ �̵� ��Ű��.
				for (j = removeIdx; j < 20; j++) {
					numAry[j] = numAry[j + 1];
				}
			}else{ // ���� ���տ� �ش� ���ڰ� ���� ��,
				numAry[aryIndex] = inputNum;
				aryIndex++;
			}

			printf("���� : { ");
			for (j = 0; j < aryIndex; j++) {
				printf("%d, ", numAry[j]);
			}
			printf("}\n\n");

		}else if (!strcmp(operator, "all") && inputNum == 0) {
			// ������ ���õ� �Է� ���� "all 0"�� �Ǿ�߸� ���õ� �������� ����ǵ��� ������.

			for (j = 0; j < 20; j++) {
				numAry[j] = j + 1;
			}

			printf("���� : { ");
			for (j = 0; j < 20; j++) {
				printf("%d, ", numAry[j]);
			}
			printf("}\n\n");
			aryIndex = 19;

		}else if (!strcmp(operator, "empty") && inputNum == 0) {
			// ������ ���õ� �Է� ���� "empty 0"�� �Ǿ�߸� ���õ� �������� ����ǵ��� ������.
			
			/*
			* ��Ҵ� 0�� �����Ͽ� ������ ó���� ��.
			* 0���� ������ ���� : �Էµ� ������ ������ 1�̻� ~ 20������.
			* ���� �˻� �Ŀ��� 0�� ��Ұ� ������ ���������� �ν��ϰ� �Ͽ�, 
			* ������ ����� �ϵ��� ������.
			*/

			for (j = 0; j < 20; j++) {
				numAry[j] = 0;
			}

			printf("���� : { ");
			for (j = 0; j < aryIndex; j++) {
				// �������̶��
				if (numAry[j] == 0) {
					break;
				}
			}
			printf(" }\n\n");

		}
	}


	return 0;
}