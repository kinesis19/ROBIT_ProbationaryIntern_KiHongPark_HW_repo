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
	int* data[100];
	int size;
}Stack;

void InitializingStack(Stack* tStack); // Stack �ʱ�ȭ �Լ�.
void PushingStack(Stack* tStack, int num);
void PoppingStack(Stack* tStack);
void Printing_Size(Stack* tStack);
int Getting_Top(Stack* tStack);
int Checking_isEmpty(Stack* tStack);
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
		}else if (strcmp(inputText, "pop") == 0) {
			PoppingStack(stack);
		}else if (strcmp(inputText, "size") == 0) {
			Printing_Size(stack);
		}else if (strcmp(inputText, "top") == 0) {
			if (Getting_Top(stack) == 0) {
				printf("���� top�� ��ġ�� ���� �����ϴ�.\n\n");
			}else{
				printf("���� top�� ��ġ�� ���� %d�Դϴ�.\n\n", Getting_Top(stack));
			}
		}else if (strcmp(inputText, "isEmpty") == 0) {
			if (Checking_isEmpty(stack) == 1) {
				printf("���� Stack�� �����Ͱ� ���� ���� �Դϴ�.\n\n");
			}else{
				printf("���� Stack�� �����Ͱ� �ִ� ���� �Դϴ�.\n\n");
			}

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
}


void PoppingStack(Stack* tStack) {

	if (tStack->size == 0) {
		printf("Stack�� ������ϴ�.\n");
	}else{
		printf("%d��(��) pop�Ǿ����ϴ�.\n\n", tStack->data[tStack->size]);
		tStack->data[tStack->size] = NULL;
		tStack->size--;
	}
}

void Printing_Size(Stack* tStack) {
	printf("������ size�� %d�Դϴ�.\n\n", tStack->size);
}


int Getting_Top(Stack* tStack) {
	if (tStack->size == 0) {
		return 0; // top�� ��尡 ���� ���� �϶��� 0�� ��ȯ�Ͽ� ������ ������ �����.
	}else{
		return tStack->data[tStack->size]; // top�� ��ġ�� �� ��ȯ�ϱ�.
	}
}

int Checking_isEmpty(Stack* tStack) {
	
	//true���� false���� ��ȯ�϶�� �Ͽ����Ƿ�, ���� 1�� 0�� ��ȯ��.
	if(tStack->size == 0){
		return 1; 
	}else{
		return 0;
	}
}

void Printing_List(Stack* tStack) {

	if (tStack->size == 0) {
		printf("���� Stack�� data�� �����ϴ�.\n\n");
	}else{
		printf("[   ����   ]\n");
		printf("i----------i\n");
		for (int i = 0; i < tStack->size; i++) {
			printf("I %5d    I\n", tStack->data[tStack->size - i]);
		}
		printf("I----------I");
	}
}