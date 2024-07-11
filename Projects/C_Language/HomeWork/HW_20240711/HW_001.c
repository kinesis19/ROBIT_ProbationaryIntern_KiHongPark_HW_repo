#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 주소 구조체
typedef struct _Address {
	char* country[20]; // 국가
	char* state[20]; // 도
	char* city[20]; // 시
	char* town[20]; // 구
}Address;
// 학생 구조체
typedef struct _Student {
	int* number;
	char* name;
	Address* adr;
	int* list;
}Student;

void Initializing(Student* std);

int main() {

	Student* student = (Student*)malloc(sizeof(student));

	Initializing(student);

	if (student->adr == NULL) {
		printf("NULL상태.");
	}

	free(student);

	return 0;
}

void Initializing(Student* std) {

	std->number = 0;
	std->name = " ";
	std->adr = NULL;
	std->list = NULL;
}