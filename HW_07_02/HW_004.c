#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int sequenceSize, middleNum, cnt = 1;
	/*
	* ���� cnt�� �ʱⰪ�� 1�� �����ϴ� ����:
	* �ߺ� ������ Ư¡�� ���� Ÿ�� ��(middleNum)�� �����ؾ� �ϱ� �����̴�.
	*/
	// �迭 sequence�� �����Ҵ� ���� �ʰ� ������.
	int i, sequence[100] = { 0, };
	
	// ���� ����ϱ�
	printf("N : ");
	scanf("%d", &sequenceSize);
	printf("B : ");
	scanf("%d", &middleNum);

	printf("\n");

	// �˰��� �����ϱ�
	// ������ �� �Է� �ޱ�
	for (i = 0; i < sequenceSize; i++) {
		scanf("%d", &sequence[i]);
	}

	// �ߺ����� ���ϴ� �˰���
	for (i = 0; i < sequenceSize; i++) {
		if (sequence[i] == middleNum || sequence[sequenceSize - i - 1] == middleNum) {
			break;
		}else{
			sequence[i] = 0;
			sequence[sequenceSize - i - 1] = 0;
			cnt++;
		}
	}

	// ��� ����ϱ�
	printf("�߾Ӱ��� %d�� �κм����� ���� : %d", middleNum, cnt);

	return 0;
}