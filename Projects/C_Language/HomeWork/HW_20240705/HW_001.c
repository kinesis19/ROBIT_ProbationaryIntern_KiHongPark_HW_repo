#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 학년 구조체 선언
typedef struct _Student {

	int schoolYear;
	double grade;
	char name;
}Student;

int main() {

	// 변수 선언하기.
	int personMax = 5;
	int i;

	// 구조체 정의하기
	Student student[5];


	// 형식 출력하기.
	printf("입력 : ");

	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}

	printf("\n출력 : ");
	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		printf("%d %.1lf %s\n", student[i].schoolYear, student[i].grade, &student[i].name);
	}


	return 0;
}