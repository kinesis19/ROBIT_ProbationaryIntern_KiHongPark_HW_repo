#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �ּ� ����ü
typedef struct _Address {
	char* country[20]; // ����
	char* state[20]; // ��
	char* city[20]; // ��
	char* town[20]; // ��
}Address;
// �л� ����ü
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
		printf("NULL����.");
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