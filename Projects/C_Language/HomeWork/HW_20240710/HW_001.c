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

void initializing(LinkedList* list) {
	list = (LinkedList*)malloc(sizeof(LinkedList));


}

int main() {

	// LinkedList 선언 및 동적할당함.
	LinkedList* linkedList;
	linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	initializing(linkedList);

	return 0;
}