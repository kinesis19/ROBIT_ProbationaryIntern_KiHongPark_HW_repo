#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _LinkedList {
	Node* head;
	int size;
}LinkedList;

void Initializing_Node(LinkedList* list);
void Inserting_Node(LinkedList* list, int num);

int main() {
	// LinkedList 선언 및 동적할당함.
	LinkedList* linkedList;
	linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	Initializing_Node(linkedList);

	char* inputText = (char*)malloc(sizeof(char) * 20);
	printf("[SYSTEM]노드가 초기화 되었습니다.\n");
	while (1){
		printf("\n\n[SYSTEM]사용 가능한 명령어 모음\n\n");
		printf("\t1. insert\t2.insert_back\t3.insert_first\n");
		printf("\t4. delete\t5.delete_first\t6.delete_back\n");
		printf("\t7. get_length\t8.print_list\t9.reverse\n\n");
		printf("[SYSTEM]명령을 입력하세요 : ");
		scanf("%s", inputText);
		printf("입력된 명령 : %s\n", inputText);

		if(strcmp(inputText, "insert") == 0){
			
		}else if (strcmp(inputText, "insert_back") == 0) {
			printf("nnnnnnnn");
		}else if (strcmp(inputText, "insert_first") == 0) {

		}else if (strcmp(inputText, "delete") == 0) {

		}else if (strcmp(inputText, "delete_first") == 0) {

		}else if (strcmp(inputText, "delete_back") == 0) {

		}else if (strcmp(inputText, "get_entry") == 0) {

		}else if (strcmp(inputText, "get_length") == 0) {

		}else if (strcmp(inputText, "print_list") == 0) {

		}else if (strcmp(inputText, "reverse") == 0) {

		}

	}

	/*printf("%d", linkedList->head);*/

	// 삽입하기.
	Inserting_Node(linkedList, 1);
	
	return 0;
}



void Initializing_Node(LinkedList* list) {
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
}

void Inserting_Node(LinkedList* list, int num) {

}