#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Student {
	int number;
	int name[20];
}Student;

void ADD(Student* list, int number) {
	(*(list + number)).number = number;
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", (*(list + number)).name);
}

int main() {

	Student* list;

	int student_num = 2;

	list = (Student*)malloc(sizeof(Student) * student_num);

	ADD(list, 0);
	ADD(list, 1);

	for (int i = 0; i < student_num; i++) {
		printf("--------------------\n");
		printf("�̸� : %s\n", list[i].name);
		printf("��ȣ : %d\n\n", list[i].number);
	}
	

	return 0;
}