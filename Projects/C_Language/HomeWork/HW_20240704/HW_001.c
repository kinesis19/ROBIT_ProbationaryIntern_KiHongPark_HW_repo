#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// ���� �����ϱ�.
	int num1, num2, i, j, cnt = 0;

	// ���� ����� �ϱ�.
	printf("�Է� : ");
	scanf("%d %d", &num1, &num2);
	int* pArr;

	/* ���� �Ҵ��ϱ�.
	* ���� ������ X -> ���� ������ ������ ����� �ʾұ� ������.
	* int type�� 2���� �迭 ���� -> �ش� ������ ���� �迭 (������ �迭)�� �Ҵ��ϱ�
	*/
	pArr = (int*)malloc(sizeof(int) * (num1 * num2));

	/*if (pArr == NULL) {
		printf("malloc error!");
	}*/

	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			pArr[cnt] = cnt + 1;
			printf("%d ", pArr[cnt]);
			cnt++;
		}
		printf("\n");
	}

	free(pArr);

}