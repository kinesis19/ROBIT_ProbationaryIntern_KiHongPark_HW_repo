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

void InitializingQueue(Queue* sQueue); // Queue �ʱ�ȭ �Լ�.
void PushingQueue(Queue* sQueue, int num);
void PoppingQueue(Queue* sQueue);
void Printing_Size(Queue* sQueue);
int Getting_Top(Queue* sQueue);
int Checking_isEmpty(Queue* sQueue);
void Printing_List(Queue* sQueue);

int main() {
	
	// Queue ���� �� �����Ҵ���.
	Queue* queue = (Queue*)malloc(sizeof(queue));


	char* inputText = (char*)malloc(sizeof(char) * 20);
	InitializingQueue(queue);
	printf("[SYSTEM]������ �ʱ�ȭ �Ǿ����ϴ�.\n");

	while (1){
		printf("\n\n[SYSTEM]��� ������ ��ɾ� ����\n\n");
		printf("\t1. push\t2.pop\t  3.size\n");
		printf("\t4. top\t5.isEmpty 6.prinsQueue\n\n");
		printf("[SYSTEM]����� �Է��ϼ��� : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "push") == 0){
			printf("[SYSTEM]push�� ���� �Է��ϼ��� : ");
			scanf("%d", &tempNum);
			PushingQueue(queue, tempNum); // Queue�� Call by ref��, tempNum�� Call by Value�� ����.
		}else if (strcmp(inputText, "pop") == 0) {
			PoppingQueue(queue);
		}else if (strcmp(inputText, "size") == 0) {
			Printing_Size(queue);
		}else if (strcmp(inputText, "top") == 0) {
			if (Getting_Top(queue) == 0) {
				printf("���� top�� ��ġ�� ���� �����ϴ�.\n\n");
			}else{
				printf("���� top�� ��ġ�� ���� %d�Դϴ�.\n\n", Getting_Top(queue));
			}
		}else if (strcmp(inputText, "isEmpty") == 0) {
			if (Checking_isEmpty(queue) == 1) {
				printf("���� Queue�� �����Ͱ� ���� ���� �Դϴ�.\n\n");
			}else{
				printf("���� Queue�� �����Ͱ� �ִ� ���� �Դϴ�.\n\n");
			}

		}else if (strcmp(inputText, "prinsQueue") == 0) {
			Printing_List(Queue);
		}

	}

}