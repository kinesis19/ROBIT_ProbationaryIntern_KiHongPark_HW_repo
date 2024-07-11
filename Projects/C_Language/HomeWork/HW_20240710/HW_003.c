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
	printf("[SYSTEM]스택이 초기화 되었습니다.\n");

	while (1){
		printf("\n\n[SYSTEM]사용 가능한 명령어 모음\n\n");
		printf("\t1. push\t2.pop\t  3.size\n");
		printf("\t4. top\t5.isEmpty 6.prinsQueue\n\n");
		printf("[SYSTEM]명령을 입력하세요 : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "push") == 0){
			printf("[SYSTEM]push할 값을 입력하세요 : ");
			scanf("%d", &tempNum);
			PushingQueue(queue, tempNum); // Queue은 Call by ref로, tempNum은 Call by Value로 보냄.
		}else if (strcmp(inputText, "pop") == 0) {
			PoppingQueue(queue);
		}else if (strcmp(inputText, "size") == 0) {
			Printing_Size(queue);
		}else if (strcmp(inputText, "top") == 0) {
			if (Getting_Top(queue) == 0) {
				printf("현재 top에 위치한 값은 없습니다.\n\n");
			}else{
				printf("현재 top에 위치한 값은 %d입니다.\n\n", Getting_Top(queue));
			}
		}else if (strcmp(inputText, "isEmpty") == 0) {
			if (Checking_isEmpty(queue) == 1) {
				printf("현재 Queue에 데이터가 없는 상태 입니다.\n\n");
			}else{
				printf("현재 Queue에 데이터가 있는 상태 입니다.\n\n");
			}

		}else if (strcmp(inputText, "prinsQueue") == 0) {
			Printing_List(Queue);
		}

	}

}