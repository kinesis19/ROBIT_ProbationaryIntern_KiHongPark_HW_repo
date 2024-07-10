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
			int numLocation;
			printf("[SYSTEM]���ϴ� ��ġ�� �Է��ϼ���. ��ġ ���� (%d ~ %d) : ", 0, 1);
			scanf("%d", &numLocation);
			Inserting_Node(linkedList, numLocation);
			printf("%d\n\n", linkedList->head->data);

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

	// �����ϱ�.
	Inserting_Node(linkedList, 1);
	
	return 0;
}

void Initializing_Node(LinkedList* list) {
	// ������ �� �κ��� head�� NULL�� �ʱ�ȭ ��.
	list->head = NULL;
	// ����ϴ� ��尡 �����Ƿ�, ����� ������ list�� size ���� 0���� �ʱ�ȭ ��.
	list->size = 0;
}

void Inserting_Node(LinkedList* list, int num) {
	// Node ���� �� �����Ҵ���.
	Node* node = (Node*)malloc(sizeof(node));

	node->data = num;
	list->head = node;

	list->size++;
	
	printf("\n\n���� ����� �� : %d��, �Էµ� �� : %d\n\n",list->size ,node->data);
}