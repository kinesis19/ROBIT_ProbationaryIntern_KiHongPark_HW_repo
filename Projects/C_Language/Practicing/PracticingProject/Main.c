#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Student {
	int number;
	int name[20];
}Student;

void ADD(Student* list, int number) {
	(*(list + number)).number = number;
	printf("이름을 입력하시오 : ");
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
		printf("이름 : %s\n", list[i].name);
		printf("번호 : %d\n\n", list[i].number);
	}
	

	return 0;
}