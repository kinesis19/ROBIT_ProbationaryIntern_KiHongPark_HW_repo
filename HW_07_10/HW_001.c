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
	Node* cur;
	Node* tail;
	int* data[100];
	int size;
}LinkedList;

void Initializing_Node(LinkedList* list);
void Inserting_Node(LinkedList* list, int num, int value);
void Inserting_Node_Back(LinkedList* list, int value);
void Inserting_Node_First(LinkedList* list, int value);
void Deleting_Node_First(LinkedList* list, int value);
void Printing_List(LinkedList* list);

int main() {
	// LinkedList 선언 및 동적할당함.
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
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

		if(strcmp(inputText, "insert") == 0){
			int numLocation, nodeValue;
			printf("[SYSTEM]원하는 위치를 입력하세요. 위치 선택 (%d ~ %d) : ", 0, linkedList->size);
			scanf("%d", &numLocation);
			if (0 <= numLocation && numLocation <= linkedList->size) {
				printf("[SYSTEM]원하는 노드의 값을 입력하세요. : ");
				scanf("%d", &nodeValue);
				Inserting_Node(linkedList, numLocation, nodeValue);
			}else{
				printf("[SYSTEM]정해진 범위 내에서 생성해야 합니다.\n\n");
			}
		}else if (strcmp(inputText, "insert_back") == 0) {
			int nodeValue;
			printf("[SYSTEM]원하는 노드의 값을 입력하세요. : ");
			scanf("%d", &nodeValue);
			Inserting_Node_Back(linkedList, nodeValue);
		}else if (strcmp(inputText, "insert_first") == 0) {
			int nodeValue;
			printf("[SYSTEM]원하는 노드의 값을 입력하세요. : ");
			scanf("%d", &nodeValue);
			Inserting_Node_First(linkedList, nodeValue);
		}else if (strcmp(inputText, "delete") == 0) {

		}else if (strcmp(inputText, "delete_first") == 0) {

		}else if (strcmp(inputText, "delete_back") == 0) {

		}else if (strcmp(inputText, "get_entry") == 0) {

		}else if (strcmp(inputText, "get_length") == 0) {

		}else if (strcmp(inputText, "print_list") == 0) {
			Printing_List(linkedList);
		}else if (strcmp(inputText, "reverse") == 0) {

		}

	}
	
	return 0;
}

void Initializing_Node(LinkedList* list) {
	// 노드들의 앞 부분인 head는 NULL로 초기화 함.
	list->head = NULL;
	list->cur = NULL;
	list->tail = NULL;
	// 사용하는 노드가 없으므로, 노드의 집합인 list의 size 값도 0으로 초기화 함.
	list->size = 0;
}

void Inserting_Node(LinkedList* list, int num, int value) {
	// Node 선언 및 동적할당함.
	Node* node = (Node*)malloc(sizeof(node));

	// 노드 추가하기.
	node->data = value; // 노드의 값은 입력 받은 value로 지정하기.
	list->size++;
	
	// Debugging:
	printf("\n\n현재 노드의 수 : %d개, 입력된 값 : %d\n\n",list->size ,node->data);
}

void Inserting_Node_Back(LinkedList* list, int value) {

	list->size++;
	if (0 < list->size) { // stack의 용량 범위 이내라면 push를 진행함.
		Node* node = (Node*)malloc(sizeof(node));

		node->data = value;
		node->next = NULL;

		list->head = node;

		list->data[list->size - 1] = node->data;
	}
}


void Inserting_Node_First(LinkedList* list, int value) {
	list->size++;
	if (0 < list->size) { // stack의 용량 범위 이내라면 push를 진행함.
		Node* node = (Node*)malloc(sizeof(node));

		node->data = value;
		node->next = NULL;

		list->head = node;

		for (int i = 0; i < list->size - 1; i++) {
			list->data[list->size - i - 1] = list->data[list->size - i - 2];
		}
		list->data[0] = node->data;
	}
}

void Printing_List(LinkedList* list) {

	printf("NULL");
	for (int i = 0; i < list->size; i++) {
		int value = list->data[i];
		printf("<-%d", value);
	}
}