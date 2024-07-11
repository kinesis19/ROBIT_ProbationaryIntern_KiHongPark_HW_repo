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

void InitializingStudentList(StudentList* stdList); // StudentList 초기화 함수.
void AddingStudent(StudentList* stdList);


int main() {
	// StudentList 동적할당 하기.
	StudentList* studentList = (StudentList*)malloc(sizeof(studentList));
	// 사용자의 명령어(입력값) 동적할당 하기.
	char* inputCommand = (char*)malloc(sizeof(char) * 20);


	InitializingStudentList(studentList);
	printf("[SYSTEM]출석부가 초기화 되었습니다.\n\n");

	while (1){
		printf("|---------------------------------------------|\n");
		printf("|     [로빛 19기 수습단원 출석부 시스템]      |\n");
		printf("|---------------------------------------------|\n");
		printf("|           사용 가능한 명령어 모음           |\n");
		printf("|---------------------------------------------|\n");
		printf("|  1. add         2.delete          3.search  |\n");
		printf("|  4. sort        5.SaveAndLoad     6.Exit    |\n");
		printf("|---------------------------------------------|\n\n\n");
		printf("[SYSTEM]명령어를 입력하세요 : ");
		scanf("%s", inputCommand);

		if(strcmp(inputCommand, "add") == 0){
			int num;
			char name[20] = { '\0', }, adrCountry[20] = { '\0', }, adrState[20] = { '\0', }, adrCity[20] = { '\0', }, adrTown[20] = { '\0', };
			double grade;

			printf("[SYSTEM]추가할 학생의 번호를 입력하세요 : ");
			scanf("%d", &num);
			printf("[SYSTEM]추가할 학생의 이름을 입력하세요 : ");
			scanf("%s", &name);
			printf("[SYSTEM]추가할 학생의 이름을 입력하세요 : ");
			scanf("%s", &name);

		}else if (strcmp(inputCommand, "delete") == 0) {

		}else if (strcmp(inputCommand, "search") == 0) {

		}else if (strcmp(inputCommand, "sort") == 0) {

		}else if (strcmp(inputCommand, "SaveAndLoad") == 0) {


		}else if (strcmp(inputCommand, "Exit") == 0) {

		}

	}

	// 동적할당 해제.
	free(studentList);

	return 0;
}

void InitializingStudentList(StudentList* stdList){
	stdList->size = 0;
	stdList->top = -1; // Stack의 top의 초기 상태는 -1 상태임.
	stdList->cur = NULL;
}

void AddingStudent(StudentList* stdList) {

}

