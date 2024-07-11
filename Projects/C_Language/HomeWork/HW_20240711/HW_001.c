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

void Initializing_StudentList(StudentList* stdList); // StudentList �ʱ�ȭ �Լ�.
void Adding_Student(StudentList* stdList); // �л� �߰� �Լ�.


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
		printf("|  4. sort        5.SaveAndLoad     6.Exit    |\n");
		printf("|---------------------------------------------|\n\n\n");
		printf("[SYSTEM]��ɾ �Է��ϼ��� : ");
		scanf("%s", inputCommand);

		if(strcmp(inputCommand, "add") == 0){
			Adding_Student(studentList);
			printf("%d", studentList->top->number);
		}else if (strcmp(inputCommand, "delete") == 0) {

		}else if (strcmp(inputCommand, "search") == 0) {

		}else if (strcmp(inputCommand, "sort") == 0) {

		}else if (strcmp(inputCommand, "SaveAndLoad") == 0) {


		}else if (strcmp(inputCommand, "Exit") == 0) {

		}

	}

	// �����Ҵ� ����.
	/*free(studentList);*/

	return 0;
}

void Initializing_StudentList(StudentList* stdList){
	stdList->size = 0;
	stdList->top = -1; // Stack�� top�� �ʱ� ���´� -1 ������.
	stdList->cur = NULL;
}

void Adding_Student(StudentList* stdList) {
	int num;
	char name[100] = { '\0', }, adrCountry[100] = { '\0', }, adrDo[100] = { '\0', }, adrSi[100] = { '\0', }, adrGu[100] = { '\0', };
	double grade;

	Student* student = (Student*)malloc(sizeof(Student));

	stdList->size++;
	printf("[SYSTEM]�߰��� �л��� ��ȣ�� �Է��ϼ���(1���� ~ 100����) : ");
	scanf("%d", &num);
	// �ӽ÷� ������ ����ó��.
	getchar();
	while (num < 1 || num > 100) {
		printf("�ٽ� �Է��ϼ��� : ");
		scanf("%d", &num);
		getchar();
	}
	student->number = num;
	// ����ó�� �Լ� ȣ���ϱ�. -> num�� �������� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� �̸��� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &name);
	student->name = name;
	// ����ó�� �Լ� ȣ���ϱ�. -> name�� ����(��)���� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ������ �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrCountry);
	student->adrCountry = adrCountry;
	// ����ó�� �Լ� ȣ���ϱ�. -> addCountry�� ����(��)���� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ���� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrDo);
	student->adrDo = adrDo;
	// ����ó�� �Լ� ȣ���ϱ�. -> adrDo�� ����(��)���� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� �ø� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrSi);
	student->adrSi = adrSi;
	// ����ó�� �Լ� ȣ���ϱ�. -> adrSi�� ����(��)���� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� �����ϰ� �ִ� ���� �Է��ϼ��� : ");
	scanf(" %[^\n]s", &adrGu);
	student->adrGu = adrGu;
	// ����ó�� �Լ� ȣ���ϱ�. -> adrGu�� ����(��)���� �ƴ���.

	printf("[SYSTEM]�߰��� �л��� ������ �Է��ϼ��� : ");
	scanf(" %lf", &grade);
	student->grade = grade;
	// ����ó�� �Լ� ȣ���ϱ�. -> grade�� �������� �ƴ���.
	
	student->next = NULL;
	stdList->top = student;

	printf("%d, %s, %s, %s, %s, %s, %.1lf\n\n", student->number, student->name, student->adrCountry, student->adrDo, student->adrSi, student->adrGu, student->grade);
}