#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int size;
}LinkedList;

void initializingLinkedList() {
	// 단순 연결 리스트 구조체 선언 및 초기화하기.
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(linkedList) * 10);
}



int main() {

	
	// 노드1 생성하기.
	Node* node1 = NULL;
	node1 = (Node*)malloc(sizeof(node1));

	// 노드2 생성하기.
	Node* node2 = (Node*)malloc(sizeof(node2));

	node1->data = 10;
	node2->data = 20;


	printf("%d\n", node1->data);
	printf("%d\n", node2->data);



	
	free(node1);


	return 0;
}