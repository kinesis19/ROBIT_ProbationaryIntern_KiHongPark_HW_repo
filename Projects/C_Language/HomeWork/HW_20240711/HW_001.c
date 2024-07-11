#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 학생 구조체
typedef struct _Student {
	int number; // 번호
	char name[100]; // 이름
	char adrCountry[100]; // 국가
	char adrDo[100]; // 도
	char adrSi[100]; // 시
	char adrGu[100]; // 구
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

void Initializing_StudentList(StudentList* stdList); // StudentList 초기화 함수.
void Adding_Student(StudentList* stdList);
void ExceptionHandling_Adding(char type);


int main() {
	// StudentList 동적할당 하기.
	StudentList* studentList = (StudentList*)malloc(sizeof(studentList));
	// 사용자의 명령어(입력값) 동적할당 하기.
	char* inputCommand = (char*)malloc(sizeof(char) * 20);


	Initializing_StudentList(studentList);
	if (studentList == NULL) {
		printf("[SYSTEM]출석부가 초기화 되지 않았습니다.");
	}else {
		printf("[SYSTEM]출석부가 초기화 되었습니다.");

	}

	while (1){
		printf("\n\n|---------------------------------------------|\n");
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
			Adding_Student(studentList);
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

void Initializing_StudentList(StudentList* stdList){
	stdList->size = 0;
	stdList->top = -1; // Stack의 top의 초기 상태는 -1 상태임.
	stdList->cur = NULL;
}

void Adding_Student(StudentList* stdList) {
	int num;
	char name[20] = { '\0', }, adrCountry[100] = { '\0', }, adrDo[100] = { '\0', }, adrSi[100] = { '\0', }, adrGu[100] = { '\0', };
	double grade;

	printf("[SYSTEM]추가할 학생의 번호를 입력하세요 : ");
	scanf("%d", &num);
	// 예외처리 함수 호출하기. -> num이 숫자인지 아닌지.
	printf("[SYSTEM]추가할 학생의 이름을 입력하세요 : ");
	scanf(" %[^\n]s", &name);
	// 예외처리 함수 호출하기. -> name이 문자(열)인지 아닌지.
	printf("[SYSTEM]추가할 학생의 거주하고 있는 국가를 입력하세요 : ");
	scanf(" %[^\n]s", &adrCountry);
	// 예외처리 함수 호출하기. -> addCountry가 문자(열)인지 아닌지.
	printf("[SYSTEM]추가할 학생의 거주하고 있는 도를 입력하세요 : ");
	scanf(" %[^\n]s", &adrDo);
	// 예외처리 함수 호출하기. -> adrDo가 문자(열)인지 아닌지.
	printf("[SYSTEM]추가할 학생의 거주하고 있는 시를 입력하세요 : ");
	scanf(" %[^\n]s", &adrSi);
	// 예외처리 함수 호출하기. -> adrSi가 문자(열)인지 아닌지.
	printf("[SYSTEM]추가할 학생의 거주하고 있는 구를 입력하세요 : ");
	scanf(" %[^\n]s", &adrGu);
	// 예외처리 함수 호출하기. -> adrGu가 문자(열)인지 아닌지.
	printf("[SYSTEM]추가할 학생의 성적을 입력하세요 : ");
	scanf(" %lf", &grade);
	// 예외처리 함수 호출하기. -> grade가 숫자인지 아닌지.
	printf("%d, %s, %s, %s, %s, %s, %.1lf\n\n", num, name, adrCountry, adrDo, adrSi, adrGu, grade);
}

