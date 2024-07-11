#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 학생 구조체
typedef struct _Student {
	int number; // 번호
	char* name; // 이름
	char* adrCountry; // 국가
	char* adrDo; // 도
	char* adrSi; // 시
	char* adrGu; // 구
	int grade; // 성적
	struct _Student* next; // 다음 학생의 주소
}Student;

// 학생 리스트
typedef struct _StudentList {
	Student* head;
	Student* cur;
	Student* tail;
	int* data[100];
	int size;
}StudentList;

void Initializing_StudentList(StudentList* stdList); // StudentList 초기화 함수.
void Adding_Student(StudentList* stdList); // 학생 추가 함수.
void Deleting_Student(StudentList* stdList); // 학생 삭제 함수.

void Printing_StudentList(StudentList* stdList); // 전체 학생 출력 함수.
int Getting_IsitNumber(char* text, int cnt); // 입력된 값이 숫자인지 아닌지 판별하는 함수.
int Changing_StringToInt(char* text); // 입력된 문자열 값을 int Type으로 return 하는 함수.


int main() {
	// StudentList 동적할당 하기.
	StudentList* studentList = (StudentList*)malloc(sizeof(StudentList));
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
		printf("|  4. sort        5.SaveAndLoad     6.exit    |\n");
		printf("|---------------------------------------------|\n\n\n");
		printf("[SYSTEM]명령어를 입력하세요 : ");
		scanf("%s", inputCommand);

		if(strcmp(inputCommand, "add") == 0){
			Adding_Student(studentList);
		}else if (strcmp(inputCommand, "delete") == 0) {
			Deleting_Student(studentList);
		}else if (strcmp(inputCommand, "search") == 0) {

		}else if (strcmp(inputCommand, "sort") == 0) {

		}else if (strcmp(inputCommand, "SaveAndLoad") == 0) {


		}else if (strcmp(inputCommand, "exit") == 0) {

		}else if (strcmp(inputCommand, "print") == 0) { // Debugging:
			Printing_StudentList(studentList);
		}

	}

	// 동적할당 해제.
	/*free(studentList);*/

	return 0;
}

void Initializing_StudentList(StudentList* stdList){
	stdList->size = 0;
	stdList->head = NULL;
	stdList->cur = NULL;
	stdList->tail = NULL;
}

int Getting_IsitNumber(char* text, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (text[i] < '0' || text[i] > '9') {
			return 0;
		}
	}
	return 1;
}

int Changing_StringToInt(char* text) {
	/* Student의 number와 grade를 할당하는 데 사용함.
	* 등급은 정수 형태의 등급. 1등급부터 ~ n등급까지 존재함. (1등급이 제일 낮은 것으로 하겠음)
	*/
	int result = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		result = result * 10 + (text[i] - '0'); 
		/*
		* ASCII CODE에서 0은 48임.
		* 입력된 문자 Type의 숫자에서 숫자의 기본인 '0'을 빼주면 해당 문자의 숫자가 return 됨.
		* '1' - '0' = 49 - 48 = 1.
		*/ 
	}
	return result;
}

void Adding_Student(StudentList* stdList) {

	char name[100] = { '\0', }, adrCountry[100] = { '\0', }, adrDo[100] = { '\0', }, adrSi[100] = { '\0', }, adrGu[100] = { '\0', };

	Student* student = (Student*)malloc(sizeof(Student));

	char text[100];
	int cntNum = 0, cntGrade = 0;
	printf("[SYSTEM]추가할 학생의 번호를 입력하세요(1부터 ~ 100사이) : ");
	scanf("%s", text);

	for (int i = 0; text[cntNum] != '\0'; i++) {
		cntNum++;
	}
	while (!Getting_IsitNumber(text, cntNum)) {
		printf("숫자만 입력하세요 : ");
		scanf("%s", text);
		cntNum = 0;
		for (int i = 0; text[cntNum] != '\0'; i++) {
			cntNum++;
		}
	}
	student->number = Changing_StringToInt(text);

	printf("[SYSTEM]추가할 학생의 이름을 입력하세요 : ");
	scanf(" %[^\n]s", &name);
	int cntName = 0;
	for (int i = 0; name[cntName] != '\0'; i++) {
		cntName++;
	}
	student->name = (char*)malloc(cntName + 1); // 이름에 동적할당하기.
	for (int i = 0; i <= cntName; i++) { // 동적할당한 student의 name에 이곳 name의 각각의 문자를 할당함.
		student->name[i] = name[i];
	}

	printf("[SYSTEM]추가할 학생의 거주하고 있는 국가를 입력하세요 : ");
	scanf(" %[^\n]s", &adrCountry);
	int cntCountry = 0;
	for (int i = 0; adrCountry[cntCountry] != '\0'; i++) {
		cntCountry++;
	}
	student->adrCountry = (char*)malloc(cntCountry + 1); // 국가에 동적할당하기.
	for (int i = 0; i <= cntCountry; i++) { // 동적할당한 student의 adrCountry에 이곳 adrCountry의 각각의 문자를 할당함.
		student->adrCountry[i] = adrCountry[i];
	}

	printf("[SYSTEM]추가할 학생의 거주하고 있는 도를 입력하세요 : ");
	scanf(" %[^\n]s", &adrDo);
	int cntDo = 0;
	for (int i = 0; adrDo[cntDo] != '\0'; i++) {
		cntDo++;
	}
	student->adrDo = (char*)malloc(cntDo + 1); // 주소-도에 동적할당하기.
	for (int i = 0; i <= cntDo; i++) { // 동적할당한 student의 adrDo에 이곳 adrDo의 각각의 문자를 할당함.
		student->adrDo[i] = adrDo[i];
	}

	printf("[SYSTEM]추가할 학생의 거주하고 있는 시를 입력하세요 : ");
	scanf(" %[^\n]s", &adrSi);
	int cntSi = 0;
	for (int i = 0; adrSi[cntSi] != '\0'; i++) {
		cntSi++;
	}
	student->adrSi = (char*)malloc(cntSi + 1); // 주소-시에 동적할당하기.
	for (int i = 0; i <= cntSi; i++) { // 동적할당한 student의 adrSi에 이곳 adrSi의 각각의 문자를 할당함.
		student->adrSi[i] = adrSi[i];
	}

	printf("[SYSTEM]추가할 학생의 거주하고 있는 구를 입력하세요 : ");
	scanf(" %[^\n]s", &adrGu);
	int cntGu = 0;
	for (int i = 0; adrGu[cntGu] != '\0'; i++) {
		cntGu++;
	}
	student->adrGu = (char*)malloc(cntGu + 1); // 주소-구에 동적할당하기.
	for (int i = 0; i <= cntGu; i++) { // 동적할당한 student의 adrGu에 이곳 adrGu의 각각의 문자를 할당함.
		student->adrGu[i] = adrGu[i];
	}

	printf("[SYSTEM]추가할 학생의 성적을 입력하세요 : ");
	scanf("%s", text);
	for (int i = 0; text[cntGrade] != '\0'; i++) {
		cntGrade++;
	}
	while (!Getting_IsitNumber(text, cntGrade)) {
		printf("숫자만 입력하세요 : ");
		scanf("%s", text);
		cntGrade = 0;
		for (int i = 0; text[cntGrade] != '\0'; i++) {
			cntGrade++;
		}
	}
	student->grade = Changing_StringToInt(text);

	if (stdList->head == NULL) { // StudnetList에 Student가 없을 때만 실행 => 첫 번째 Student 추가시만 실행.
		stdList->head = student;
		stdList->tail = student;
	}else{
		stdList->tail->next = student;
		stdList->tail = student;
	}

	stdList->size++;
}

void Deleting_Student(StudentList* stdList) {

	printf("아아 삭제됨.");

}



void Printing_StudentList(StudentList* stdList) {
	
	Student* current = stdList->head;

	for (int i = 0; i < stdList->size; i++) {
		printf("[%d번째] 번호 : %d | 이름 :  %s | 국가 : %s | 도 : %s | 시 : %s | 구 : %s | 등급 : %d |\n", i, current->number, current->name, current->adrCountry, current->adrDo, current->adrSi, current->adrGu, current->grade);
		current = current->next;
	}

}