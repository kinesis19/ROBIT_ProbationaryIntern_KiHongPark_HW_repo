#include <stdio.h>

int main() {

	// ���� �����ϱ�
	int inputYear;

	// ���� ����ϱ�
	printf("�⵵�� �Է��ϼ��� : ");

	// �� �Է¹ޱ�
	scanf_s("%d", &inputYear);
	
	// ���� ��� �� ����� ����ϱ�
	if ((inputYear % 4 == 0) && (inputYear % 100 != 0) || (inputYear % 400 == 0)) {
		printf("����");
	}else{
		printf("������ �ƴմϴ�.");
	}


	return 0;
}