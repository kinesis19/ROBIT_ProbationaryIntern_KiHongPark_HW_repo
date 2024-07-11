#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �л� ����ü
typedef struct _Student {
	int number; // ��ȣ
	char* name; // �̸�
	char* adrCountry; // ����
	char* adrDo; // ��
	char* adrSi; // ��
	char* adrGu; // ��
	int grade; // ����
	struct _Student* next; // ���� �л��� �ּ�
}Student;

// �л� ����Ʈ
typedef struct _StudentList {
	Student* head;
	Student* cur;
	Student* tail;
	int* data[100];
	int size;
}StudentList;

void Initializing_StudentList(StudentList* stdList); // StudentList �ʱ�ȭ �Լ�.
void Adding_Student(StudentList* stdList); // �л� �߰� �Լ�.
void Deleting_Student(StudentList* stdList); // �л� ���� �Լ�.

void Printing_StudentList(StudentList* stdList); // ��ü �л� ��� �Լ�.
int Getting_IsitNumber(char* text, int cnt); // �Էµ� ���� �������� �ƴ��� �Ǻ��ϴ� �Լ�.
int Changing_StringToInt(char* text); // �Էµ� ���ڿ� ���� int Type���� return �ϴ� �Լ�.


int main() {
	// StudentList �����Ҵ� �ϱ�.
	StudentList* studentList = (StudentList*)malloc(sizeof(StudentList));
	// ������� ��ɾ�(�Է°�) �����Ҵ� �ϱ�.
	char* inputCommand = (char*)malloc(sizeof(char) * 20);


	Initializing_StudentList(studentList);
	if (studentList == NULL) {
		printf("[SYSTEM]�⼮�ΰ� �ʱ�ȭ ���� �ʾҽ��ϴ�.");
	}else {
		printf("[SYSTEM]�⼮�ΰ� �ʱ�ȭ �Ǿ����ϴ�.");

	}

	while (1){
		printf("\n\n|---------------------------------------------|\n");
		printf("|     [�κ� 19�� �����ܿ� �⼮�� �ý���]      |\n");
		printf("|---------------------------------------------|\n");
		printf("|           ��� ������ ��ɾ� ����           |\n");
		printf("|---------------------------------------------|\n");
		printf("|  1. add         2.delete          3.search  |\n");
		printf("|  4. sort        5.SaveAndLoad     6.exit    |\n");
		printf("|---------------------------------------------|\n\n\n");
		printf("[SYSTEM]��ɾ �Է��ϼ��� : ");
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

	// �����Ҵ� ����.
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
	/* Student�� number�� grade�� �Ҵ��ϴ� �� �����.
	* ����� ���� ������ ���. 1��޺��� ~ n��ޱ��� ������. (1����� ���� ���� ������ �ϰ���)
	*/
	int result = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		result = result * 10 + (text[i] - '0'); 
		/*
		* ASCII CODE���� 0�� 48��.
		* �Էµ� ���� Type�� ���ڿ��� ������ �⺻�� '0'�� ���ָ� �ش� ������ ���ڰ� return ��.
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
	printf("[SYSTEM]�߰��� �л��� ��ȣ�� �Է��ϼ���(1���� ~ 100����) : ");
	scanf("%s", text);

	for (int i = 0; text[cntNum] != '\0'; i++) {
		cntNum++;
	}
	while (!Getting_IsitNumber(text, cntNum)) {
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%s", text);
		cntNum = 0;
		for (int i = 0; text[cntNum] != '\0'; i++) {
			cntNum++;
		}
	}
	student->number = Changing_StringToInt(text);

	printf("[SYSTEM]�߰��� �л��� �̸��� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &name);
	int cntName = 0;
	for (int i = 0; name[cntName] != '\0'; i++) {
		cntName++;
	}
	student->name = (char*)malloc(cntName + 1); // �̸��� �����Ҵ��ϱ�.
	for (int i = 0; i <= cntName; i++) { // �����Ҵ��� student�� name�� �̰� name�� ������ ���ڸ� �Ҵ���.
		student->name[i] = name[i];
	}

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ������ �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrCountry);
	int cntCountry = 0;
	for (int i = 0; adrCountry[cntCountry] != '\0'; i++) {
		cntCountry++;
	}
	student->adrCountry = (char*)malloc(cntCountry + 1); // ������ �����Ҵ��ϱ�.
	for (int i = 0; i <= cntCountry; i++) { // �����Ҵ��� student�� adrCountry�� �̰� adrCountry�� ������ ���ڸ� �Ҵ���.
		student->adrCountry[i] = adrCountry[i];
	}

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ���� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrDo);
	int cntDo = 0;
	for (int i = 0; adrDo[cntDo] != '\0'; i++) {
		cntDo++;
	}
	student->adrDo = (char*)malloc(cntDo + 1); // �ּ�-���� �����Ҵ��ϱ�.
	for (int i = 0; i <= cntDo; i++) { // �����Ҵ��� student�� adrDo�� �̰� adrDo�� ������ ���ڸ� �Ҵ���.
		student->adrDo[i] = adrDo[i];
	}

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� �ø� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrSi);
	int cntSi = 0;
	for (int i = 0; adrSi[cntSi] != '\0'; i++) {
		cntSi++;
	}
	student->adrSi = (char*)malloc(cntSi + 1); // �ּ�-�ÿ� �����Ҵ��ϱ�.
	for (int i = 0; i <= cntSi; i++) { // �����Ҵ��� student�� adrSi�� �̰� adrSi�� ������ ���ڸ� �Ҵ���.
		student->adrSi[i] = adrSi[i];
	}

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ���� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrGu);
	int cntGu = 0;
	for (int i = 0; adrGu[cntGu] != '\0'; i++) {
		cntGu++;
	}
	student->adrGu = (char*)malloc(cntGu + 1); // �ּ�-���� �����Ҵ��ϱ�.
	for (int i = 0; i <= cntGu; i++) { // �����Ҵ��� student�� adrGu�� �̰� adrGu�� ������ ���ڸ� �Ҵ���.
		student->adrGu[i] = adrGu[i];
	}

	printf("[SYSTEM]�߰��� �л��� ������ �Է��ϼ��� : ");
	scanf("%s", text);
	for (int i = 0; text[cntGrade] != '\0'; i++) {
		cntGrade++;
	}
	while (!Getting_IsitNumber(text, cntGrade)) {
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%s", text);
		cntGrade = 0;
		for (int i = 0; text[cntGrade] != '\0'; i++) {
			cntGrade++;
		}
	}
	student->grade = Changing_StringToInt(text);

	if (stdList->head == NULL) { // StudnetList�� Student�� ���� ���� ���� => ù ��° Student �߰��ø� ����.
		stdList->head = student;
		stdList->tail = student;
	}else{
		stdList->tail->next = student;
		stdList->tail = student;
	}

	stdList->size++;
}

void Deleting_Student(StudentList* stdList) {

	printf("�ƾ� ������.");

}



void Printing_StudentList(StudentList* stdList) {
	
	Student* current = stdList->head;

	for (int i = 0; i < stdList->size; i++) {
		printf("[%d��°] ��ȣ : %d | �̸� :  %s | ���� : %s | �� : %s | �� : %s | �� : %s | ��� : %d |\n", i, current->number, current->name, current->adrCountry, current->adrDo, current->adrSi, current->adrGu, current->grade);
		current = current->next;
	}

}