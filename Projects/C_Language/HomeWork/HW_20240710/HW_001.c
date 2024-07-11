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
	int size;
}LinkedList;

void Initializing_Node(LinkedList* list);
void Inserting_Node(LinkedList* list, int num, int value);
void Inserting_Node_Back(LinkedList* list, int value);
void Printing_List(LinkedList* list);

int main() {
	// LinkedList ���� �� �����Ҵ���.
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	Initializing_Node(linkedList);

	char* inputText = (char*)malloc(sizeof(char) * 20);
	printf("[SYSTEM]��尡 �ʱ�ȭ �Ǿ����ϴ�.\n");
	while (1){
		printf("\n\n[SYSTEM]��� ������ ��ɾ� ����\n\n");
		printf("\t1. insert\t2.insert_back\t3.insert_first\n");
		printf("\t4. delete\t5.delete_first\t6.delete_back\n");
		printf("\t7. get_length\t8.print_list\t9.reverse\n\n");
		printf("[SYSTEM]����� �Է��ϼ��� : ");
		scanf("%s", inputText);

		if(strcmp(inputText, "insert") == 0){
			int numLocation, nodeValue;
			printf("[SYSTEM]���ϴ� ��ġ�� �Է��ϼ���. ��ġ ���� (%d ~ %d) : ", 0, linkedList->size);
			scanf("%d", &numLocation);
			if (0 <= numLocation && numLocation <= linkedList->size) {
				printf("[SYSTEM]���ϴ� ����� ���� �Է��ϼ���. : ");
				scanf("%d", &nodeValue);
				Inserting_Node(linkedList, numLocation, nodeValue);
			}else{
				printf("[SYSTEM]������ ���� ������ �����ؾ� �մϴ�.\n\n");
			}
		}else if (strcmp(inputText, "insert_back") == 0) {
			int nodeValue;
			printf("[SYSTEM]���ϴ� ����� ���� �Է��ϼ���. : ");
			scanf("%d", &nodeValue);
			Inserting_Node_Back(linkedList, nodeValue);
		}else if (strcmp(inputText, "insert_first") == 0) {

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
	// ������ �� �κ��� head�� NULL�� �ʱ�ȭ ��.
	list->head = NULL;
	list->cur = NULL;
	list->tail = NULL;
	// ����ϴ� ��尡 �����Ƿ�, ����� ������ list�� size ���� 0���� �ʱ�ȭ ��.
	list->size = 0;
}

void Inserting_Node(LinkedList* list, int num, int value) {
	// Node ���� �� �����Ҵ���.
	Node* node = (Node*)malloc(sizeof(node));

	// ��� �߰��ϱ�.
	node->data = value; // ����� ���� �Է� ���� value�� �����ϱ�.


	//node->next = list->head; // ���� ����� �ڿ� �� ����� �ּҸ� �Ӹ��� �����ϱ�
	//list->head = node;
	list->size++;
	
	// Debugging:
	printf("\n\n���� ����� �� : %d��, �Էµ� �� : %d\n\n",list->size ,node->data);
}

void Inserting_Node_Back(LinkedList* list, int value) {

	// Node ���� �� �����Ҵ���.
	Node* node = (Node*)malloc(sizeof(node));

	// ��� �߰��ϱ�.
	node->data = value; // ����� ���� �Է� ���� value�� �����ϱ�.
	node->next = NULL; // ������ ��� �ڿ��� ������� ��尡 ����.
	
	if (list->size == 0) {
		list->head = node;
		list->cur = node;
	}else{
		for (int i = 0; i < list->size; i++) {
			printf("%d\n", list->head->data);
			list->head->next = node;
			list->head = list->head->next;
			printf("%d\n\n", list->head->data);
		}
		list->head = node;
	}
	list->tail = node;
	list->size++;

	// Debugging:
	printf("\n\n���� ����� �� : %d��, �Էµ� �� : %d, �Ӹ� : %d, ������ : %d\n\n", list->size, node->data, list->head->data, list->tail->data);
}



void Printing_List(LinkedList* list) {
	Node* ptr = list->head;
	Node* tPtr = list->tail;
	Node* current = list->cur;
	

	printf("NULL");
	for (int i = 0; i < list->size; i++) {
		printf("<-%d", current->data);
		current = list->head->next;
	}

	/*printf("\n\nHead : %d , Tail : %d", ptr->data, tPtr->data);*/

}