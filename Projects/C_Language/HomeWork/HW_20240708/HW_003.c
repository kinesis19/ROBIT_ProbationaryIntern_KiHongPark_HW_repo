#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next; // ���� ��带 ����Ŵ.
}Node;

typedef struct _LinkedList {
	Node* head;
	Node* tail;
	Node* Cur;
	Node Test;
	int size;
	int sibal;
}LinkedList;

void Inserting(LinkedList* list);


int main() {
	// �ܼ� ���� ����Ʈ ����ü �����ϱ�.
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(linkedList) * 10);
	
	// ���� �����ϱ�.
	char* inputCmd = (char*)malloc(sizeof(char) * 20);
	
	linkedList->size = 22;
	printf("size : %d\n\n", linkedList->size);

	linkedList->Test.data = 2;
	printf("With Out the pointer : %d\n\n", linkedList->Test.data);


	/*linkedList->sibal = 1234;
	printf("sibal : %d\n\n", linkedList->head->data);*/


	// ��ɾ�(cmd)�� �Է� �ް�, �� ��ɿ� ���� ������ �۾��� ������.
	while (1){
		scanf("%s", inputCmd);

		if (strcmp(inputCmd, "insert") == 0) {
			Inserting(&linkedList);
			printf("%d", linkedList->Test.data);
			printf("insert!");
		}else if (strcmp(inputCmd, "insert_back") == 0) {
			printf("insert_back!");
		}else if (strcmp(inputCmd, "insert_first") == 0) {
			printf("insert_first!");
		}else if (strcmp(inputCmd, "delete") == 0) {
			printf("delete!");
		}else if (strcmp(inputCmd, "delete_first") == 0) {
			printf("delete_first!");
		}else if (strcmp(inputCmd, "delete_back") == 0) {
			printf("delete_back!");
		}else if (strcmp(inputCmd, "get_entry") == 0) {
			printf("get_entry!");
		}else if (strcmp(inputCmd, "get_length") == 0) {
			printf("get_length!");
		}else if (strcmp(inputCmd, "print_list") == 0) {
			printf("print_list!");
		}else if (strcmp(inputCmd, "reverse") == 0) {
			printf("reverse!");
		}else if (strcmp(inputCmd, "Data") == 0) {
			printf("Data!");
		}

		printf("\n");
	}


	return 0;
}


// 1. insert �Լ�
void Inserting(LinkedList* list) {
	
	list->Test.data = 3;

	printf("%d\n", list->Test.data);

}


