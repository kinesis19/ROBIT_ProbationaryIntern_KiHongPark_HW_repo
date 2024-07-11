#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _Stack {
	Node* top;
	Node* cur;
	int* data[10];
	int size;
}Stack;

void InitializingStack(Stack* tStack); // Stack �ʱ�ȭ �Լ�.
void PushingStack(Stack* tStack, int num);
void Printing_List(Stack* tStack);

int main() {
	
	// Stack ���� �� �����Ҵ���.
	Stack* stack = (Stack*)malloc(sizeof(stack));


	char* inputText = (char*)malloc(sizeof(char) * 20);
	InitializingStack(stack);
	printf("[SYSTEM]������ �ʱ�ȭ �Ǿ����ϴ�.\n");

	while (1){
		printf("\n\n[SYSTEM]��� ������ ��ɾ� ����\n\n");
		printf("\t1. push\t2.pop\t  3.size\n");
		printf("\t4. top\t5.isEmpty 6.printStack\n\n");
		printf("[SYSTEM]����� �Է��ϼ��� : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "push") == 0){
			printf("[SYSTEM]push�� ���� �Է��ϼ��� : ");
			scanf("%d", &tempNum);
			PushingStack(stack, tempNum); // stack�� Call by ref��, tempNum�� Call by Value�� ����.
		}else if (strcmp(inputText, "printStack") == 0) {
			Printing_List(stack);
		}

	}

}

void InitializingStack(Stack* tStack) {

	tStack->size = 0;
	tStack->top = -1; // Stack�� top�� �ʱ� ���´� -1 ������.
	tStack->cur = NULL;
}



void PushingStack(Stack* tStack, int num) {

	tStack->size++;
	if (0 < tStack->size) { // stack�� �뷮 ���� �̳���� push�� ������.
		Node* node = (Node*)malloc(sizeof(node));

		node->data = num;
		node->next = NULL;

		/*tStack->top++;*/
		tStack->top = node;
		tStack->cur = node;

		tStack->data[tStack->size] = node->data;
	}

	/*printf("data value : %d\n\n", tStack->top->data);*/
}

void Printing_List(Stack* tStack) {

	if (tStack->size == 0) {
		printf("���� ���ÿ� ���ο��� ��尡 �����ϴ�.\n\n");
	}else{
		printf("[   ����   ]\n");
		printf("i----------i\n");
		for (int i = 0; i < tStack->size; i++) {
			printf("I %5d    I\n", tStack->data[tStack->size - i]);
		}
		printf("I----------I");
	}

	

}