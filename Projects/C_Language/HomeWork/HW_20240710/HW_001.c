#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _LinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int size;
}LinkedList;

void Initializing_Node(LinkedList* list) {
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
}

void Inserting_Node(LinkedList* list, int num) {

}

int main() {

	// LinkedList ���� �� �����Ҵ���.
	LinkedList* linkedList;
	linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	Initializing_Node(linkedList);

	/*printf("%d", linkedList->head);*/

	// �����ϱ�.
	Inserting_Node(linkedList, 1);



	return 0;
}