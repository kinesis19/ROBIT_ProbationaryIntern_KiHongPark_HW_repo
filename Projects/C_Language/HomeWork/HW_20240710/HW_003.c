#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _Queue {
	Node* front;
	Node* cur;
	int* data[100];
	int size;
}Queue;

void InitializingQueue(Queue* sQueue); // Queue �ʱ�ȭ �Լ�.
void Engueuing(Queue* sQueue, int num);
void Dequeuing(Queue* sQueue);
void Printing_Size(Queue* sQueue);
int Getting_Front(Queue* sQueue);
int Checking_isEmpty(Queue* sQueue);
void Printing_List(Queue* sQueue);

int main() {
	
	// Queue ���� �� �����Ҵ���.
	Queue* queue = (Queue*)malloc(sizeof(queue));


	char* inputText = (char*)malloc(sizeof(char) * 20);
	InitializingQueue(queue);
	printf("[SYSTEM]ť�� �ʱ�ȭ �Ǿ����ϴ�.\n");

	while (1){
		printf("\n\n[SYSTEM]��� ������ ��ɾ� ����\n\n");
		printf("\t1. Enqueue\t2.Dequeue\t  3.size\n");
		printf("\t4. front\t5.rear\t\t  6.isEmpty\n");
		printf("\t7. printQueue\n\n");
		printf("[SYSTEM]����� �Է��ϼ��� : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "Enqueue") == 0){
			printf("[SYSTEM]Enqueue�� ���� �Է��ϼ��� : ");
			scanf("%d", &tempNum);
			Engueuing(queue, tempNum);
		}else if (strcmp(inputText, "Dequeue") == 0) {
			Dequeuing(queue);
		}else if (strcmp(inputText, "size") == 0) {
			Printing_Size(queue);
		}else if (strcmp(inputText, "front") == 0) {
			if (Getting_Front(queue) != -999) {
				printf("front�� ��ġ�� ���� %d�Դϴ�.\n\n", Getting_Front(queue));
			}else{
				printf("front�� ��ġ�� ���� �����ϴ�.\n\n");
			}
		}else if (strcmp(inputText, "isEmpty") == 0) {

		}else if (strcmp(inputText, "printQueue") == 0) {
			Printing_List(queue);
		}

	}

}

void InitializingQueue(Queue* sQueue) {

	sQueue->size = 0;
	sQueue->front = 0; // Queue�� �ʱ� ���´� 0��.
	sQueue->cur = NULL;
}

void Engueuing(Queue* sQueue, int num) {

	sQueue->size++;

	if (0 < sQueue->size) { // ť�� �뷮 ���� ����� Enqueue�� ������.
		Node* node = (Node*)malloc(sizeof(node));

		node->data = num;
		node->next = NULL;

		sQueue->front = node;
		sQueue->data[sQueue->size - 1] = node->data;

	}

	printf("%d\n\n", sQueue->data[sQueue->size - 1]);

}

void Dequeuing(Queue* sQueue) {

	if (sQueue->size == 0) {
		printf("Queue�� ������ϴ�.\n\n");
	}else{
		printf("%d��(��) Dequeue �Ǿ����ϴ�.\n\n", sQueue->data[0]);

		for (int i = 0; i < sQueue->size - 1; i++) {
			sQueue->data[i] = sQueue->data[i + 1];
		}
		sQueue->size--;
	}

}

void Printing_Size(Queue* sQueue) {
	printf("ť�� size�� %d�Դϴ�.\n\n", sQueue->size);
}

int Getting_Front(Queue* sQueue) {

	if (0 < sQueue->size) {
		return sQueue->data[0];
	}else{
		return -999;
	}
}





void Printing_List(Queue* sQueue) {

	if (sQueue->size == 0) {
		printf("���� Queue�� data�� �����ϴ�.\n\n");
	}else {
		printf("[   ť    ]\n");
		printf("i----------i\n");
		for (int i = 0; i < sQueue->size; i++) {
			printf("I %5d    I\n", sQueue->data[i]);
		}
		printf("I----------I");
	}
}