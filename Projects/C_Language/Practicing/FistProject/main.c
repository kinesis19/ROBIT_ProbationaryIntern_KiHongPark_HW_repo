#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2

typedef struct _Student {

	int number;
	char name[10];
	double grade;
}Student;

int main() {
	Student list[SIZE];
	int i = 0;

	printf("%d", sizeof(list[SIZE]));


	for (i = 0; i < SIZE; i++) {
		printf("�й��� �Է��Ͻÿ�: ");
		scanf("%d", &list[i].number);
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", &list[i].name);
		printf("������ �Է��Ͻÿ�: ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++) {
		printf("�й� : %d, �̸� : %s, ���� : %lf\n", list[i].number, list[i].name, list[i].grade);
	}


	return 0;
}