#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _Queue {
	Node* top;
	Node* cur;
	int* data[100];
	int size;
}Queue;

void InitializingQueue(Queue* sQueue); // Queue 초기화 함수.
void PushingQueue(Queue* sQueue, int num);
void PoppingQueue(Queue* sQueue);
void Printing_Size(Queue* sQueue);
int Getting_Top(Queue* sQueue);
int Checking_isEmpty(Queue* sQueue);
void Printing_List(Queue* sQueue);

int main() {
	
	// Queue 선언 및 동적할당함.
	Queue* queue = (Queue*)malloc(sizeof(queue));


	char* inputText = (char*)malloc(sizeof(char) * 20);
	InitializingQueue(queue);
	printf("[SYSTEM]큐가 초기화 되었습니다.\n");

	while (1){
		printf("\n\n[SYSTEM]사용 가능한 명령어 모음\n\n");
		printf("\t1. Enqueue\t2.Dequeue\t  3.size\n");
		printf("\t4. front\t5.rear\t\t  6.isEmpty\n");
		printf("\t7. printQueue\n\n");
		printf("[SYSTEM]명령을 입력하세요 : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "push") == 0){
			printf("[SYSTEM]push할 값을 입력하세요 : ");
			scanf("%d", &tempNum);
		}else if (strcmp(inputText, "pop") == 0) {

		}else if (strcmp(inputText, "size") == 0) {

		}else if (strcmp(inputText, "top") == 0) {

		}else if (strcmp(inputText, "isEmpty") == 0) {

		}else if (strcmp(inputText, "prinsQueue") == 0) {

		}

	}

}

void InitializingQueue(Queue* sQueue) {

	sQueue->size = 0;
	sQueue->top = 0; // Queue의 초기 상태는 0임.
	sQueue->cur = NULL;
}