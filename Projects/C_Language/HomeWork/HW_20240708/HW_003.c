#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _LinkedList {
	Node* head;
	Node* tail;
	Node* Cur;
	int size;
}LinkedList;

void Inserting(LinkedList* list);


int main() {
	// 단순 연결 리스트 구조체 선언하기.
	LinkedList linkedList;
	linkedList.Cur = 0;
	// 변수 선언하기.
	char* inputCmd = (char*)malloc(sizeof(char) * 20);
	
	// 명령어(cmd)을 입력 받고, 각 명령에 따라 정해진 작업을 진행함.
	while (1){
		scanf("%s", inputCmd);

		if (strcmp(inputCmd, "insert") == 0) {
			printf("%d\n", linkedList.Cur);
			Inserting(&linkedList);
			printf("%d\n", linkedList.Cur);
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


// 1. insert 함수
void Inserting(LinkedList* list) {
	
	list->Cur = 1;

	printf("%d\n", list->Cur);

}













