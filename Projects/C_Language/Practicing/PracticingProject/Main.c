#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _Date {
	int month;
	int day;
	int year;
}Date;

typedef struct _Student {
	int number;
	char name[10];
	double grade;
	Date* mdy;
}Student;

int main() {

	Student s = { 44, "Kim", 4.5 };
	Date d = { 6, 26, 1995 };

	s.mdy = &d;

	printf("�й� : %d �̸� : %s ���� : %.1f\n", s.number, s.name, s.grade);
	printf("������� : %d�� %d�� %d��\n", s.mdy->year, s.mdy->month, s.mdy->day);

	return 0;
}