#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int inputNum = 0, numAry[20] = { 0, }; // numAry : ��Ҹ� �����ϴ� ����(�迭)
	char operator[10] = { 0, }; // add, remove ���� �ܾ� ���� �迭
	int i, j, aryIndex = 0;
	int isOkayAdd = 1, isOkayRemove = 0, isOkayCheck = 0; // boolean �����ڴ� �� ��� �����̹Ƿ� int�� boolean ������ ��ü��.

	// ���� ����ϱ�
	printf("������ �����ϼ���. (1 <= x <= 20");
	printf("\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n\n");

	while (1) {
		
		printf("input : ");
		scanf("%s %d", &operator, &inputNum);

		// ����ó�� (inputNum ���� ���� �ʿ�)
		/*if (!strcmp(operator, "stop")) {
			printf("Stopped!");
			break;
		}*/

		// ��� ������ ���ϱ�
		if (!strcmp(operator, "add")) {
			for (i = 0; i < 20; i++) {
				if (numAry[i] == inputNum) {
					isOkayAdd = 0;
					// ����ó�� (���� �߰��� Ŀ����)
					/*printf("�߰��� �� �����ϴ�.\n");*/
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
			}else{
				/* ����ó��(���� �߰��� Ŀ����)
				* ������ ����ó�� ���� ���� Ŀ������ ��� �Ǿ� ���� ������,
				* ��� ������ �ؼ��ϱ� ���� �ش� ������ �ּ�ó�� ��.
				*/
				/*printf("�ش� ���ڴ� ������ ��Ұ� �ƴϹǷ�, ������ �� �����ϴ�.\n");*/
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

		}else if (!strcmp(operator, "all")) {

		}else if (!strcmp(operator, "empty")) {

		}
	}


	return 0;
}