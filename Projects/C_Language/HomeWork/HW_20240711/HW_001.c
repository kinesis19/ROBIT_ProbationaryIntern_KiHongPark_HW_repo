#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �л� ����ü
typedef struct _Student {
	int number; // ��ȣ
	char name[20]; // �̸�
	char adrCountry[20]; // ����
	char adrState[20]; // ��
	char adrCity[20]; // ��
	char adrTown[20]; // ��
	double grade; // ����
	struct _Student* next; // ���� �л��� �ּ�
}Student;

// �л� ����Ʈ
typedef struct _StudentList {
	Student* top;
	Student* cur;
	int* data[100];
	int size;
}StudentList;

void InitializingStudentList(StudentList* stdList);

int main() {

	StudentList* studentList = (StudentList*)malloc(sizeof(studentList));

	InitializingStudentList(studentList);

	free(studentList);

	return 0;
}

void InitializingStudentList(StudentList* stdList){


}

