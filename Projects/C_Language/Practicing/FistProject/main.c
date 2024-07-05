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
		printf("학번을 입력하시오: ");
		scanf("%d", &list[i].number);
		printf("이름을 입력하시오: ");
		scanf("%s", &list[i].name);
		printf("학점을 입력하시오: ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++) {
		printf("학번 : %d, 이름 : %s, 학점 : %lf\n", list[i].number, list[i].name, list[i].grade);
	}


	return 0;
}