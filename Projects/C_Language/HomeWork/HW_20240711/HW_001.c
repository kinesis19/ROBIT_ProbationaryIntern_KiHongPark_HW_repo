#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 학생 구조체
typedef struct _Student {
	int number; // 번호
	char name[20]; // 이름
	char adrCountry[20]; // 국가
	char adrState[20]; // 도
	char adrCity[20]; // 시
	char adrTown[20]; // 구
	double grade; // 성적
	struct _Student* next; // 다음 학생의 주소
}Student;

// 학생 리스트
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

