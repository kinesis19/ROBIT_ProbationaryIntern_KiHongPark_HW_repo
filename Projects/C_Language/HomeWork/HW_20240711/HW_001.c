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
	// StudentList �����Ҵ� �ϱ�.
	StudentList* studentList = (StudentList*)malloc(sizeof(studentList));
	// ������� ��ɾ�(�Է°�) �����Ҵ� �ϱ�.
	char* inputCommand = (char*)malloc(sizeof(char) * 20);


	InitializingStudentList(studentList);
	printf("[SYSTEM]�⼮�ΰ� �ʱ�ȭ �Ǿ����ϴ�.\n\n");

	while (1){
		printf("|---------------------------------------------|\n");
		printf("|     [�κ� 19�� �����ܿ� �⼮�� �ý���]      |\n");
		printf("|---------------------------------------------|\n");
		printf("|           ��� ������ ��ɾ� ����           |\n");
		printf("|---------------------------------------------|\n");
		printf("|  1. add         2.delete          3.search  |\n");
		printf("|  4. sort        5.SaveAndLoad     6.Exit    |\n");
		printf("|---------------------------------------------|\n\n\n");
		printf("[SYSTEM]��ɾ �Է��ϼ��� : ");
		scanf("%s", inputCommand);

		int tempNum;
		if(strcmp(inputCommand, "add") == 0){
			/*printf("[SYSTEM]�߰��� �л��� ��ȣ�� �Է��ϼ��� : ");
			scanf("%d", &tempNum);*/

		}else if (strcmp(inputCommand, "delete") == 0) {

		}else if (strcmp(inputCommand, "search") == 0) {

		}else if (strcmp(inputCommand, "sort") == 0) {

		}else if (strcmp(inputCommand, "SaveAndLoad") == 0) {


		}else if (strcmp(inputCommand, "Exit") == 0) {

		}

	}





	// �����Ҵ� ����.
	free(studentList);

	return 0;
}

void InitializingStudentList(StudentList* stdList){


}

