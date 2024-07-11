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

void InitializingStack(Stack* tStack); // Stack 초기화 함수.
void PushingStack(Stack* tStack, int num);
void PoppingStack(Stack* tStack);
void Printing_Size(Stack* tStack);
int Getting_Top(Stack* tStack);
int Checking_isEmpty(Stack* tStack);
void Printing_List(Stack* tStack);

int main() {
	
	// Stack 선언 및 동적할당함.
	Stack* stack = (Stack*)malloc(sizeof(stack));


	char* inputText = (char*)malloc(sizeof(char) * 20);
	InitializingStack(stack);
	printf("[SYSTEM]스택이 초기화 되었습니다.\n");

	while (1){
		printf("\n\n[SYSTEM]사용 가능한 명령어 모음\n\n");
		printf("\t1. push\t2.pop\t  3.size\n");
		printf("\t4. top\t5.isEmpty 6.printStack\n\n");
		printf("[SYSTEM]명령을 입력하세요 : ");
		scanf("%s", inputText);


		int tempNum;
		if(strcmp(inputText, "push") == 0){
			printf("[SYSTEM]push할 값을 입력하세요 : ");
			scanf("%d", &tempNum);
			PushingStack(stack, tempNum); // stack은 Call by ref로, tempNum은 Call by Value로 보냄.
		}else if (strcmp(inputText, "pop") == 0) {
			PoppingStack(stack);
		}else if (strcmp(inputText, "size") == 0) {
			Printing_Size(stack);
		}else if (strcmp(inputText, "top") == 0) {
			if (Getting_Top(stack) == 0) {
				printf("현재 top에 위치한 값은 없습니다.\n\n");
			}else{
				printf("현재 top에 위치한 값은 %d입니다.\n\n", Getting_Top(stack));
			}
		}else if (strcmp(inputText, "isEmpty") == 0) {
			if (Checking_isEmpty(stack) == 1) {
				printf("현재 Stack에 데이터가 없는 상태 입니다.\n\n");
			}else{
				printf("현재 Stack에 데이터가 있는 상태 입니다.\n\n");
			}

		}else if (strcmp(inputText, "printStack") == 0) {
			Printing_List(stack);
		}

	}

}

void InitializingStack(Stack* tStack) {

	tStack->size = 0;
	tStack->top = -1; // Stack의 top의 초기 상태는 -1 상태임.
	tStack->cur = NULL;
}

void PushingStack(Stack* tStack, int num) {

	tStack->size++;
	if (0 < tStack->size) { // stack의 용량 범위 이내라면 push를 진행함.
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
		printf("Stack이 비었습니다.\n");
	}else{
		printf("%d이(가) pop되었습니다.\n\n", tStack->data[tStack->size]);
		tStack->data[tStack->size] = NULL;
		tStack->size--;
	}
}

void Printing_Size(Stack* tStack) {
	printf("스택의 size는 %d입니다.\n\n", tStack->size);
}


int Getting_Top(Stack* tStack) {
	if (tStack->size == 0) {
		return 0; // top에 노드가 없는 상태 일때는 0을 반환하여 정해진 문구를 출력함.
	}else{
		return tStack->data[tStack->size]; // top에 위치한 값 반환하기.
	}
}

int Checking_isEmpty(Stack* tStack) {
	
	//true값과 false값을 반환하라고 하였으므로, 각각 1과 0을 반환함.
	if(tStack->size == 0){
		return 1; 
	}else{
		return 0;
	}
}

void Printing_List(Stack* tStack) {

	if (tStack->size == 0) {
		printf("현재 Stack에 data가 없습니다.\n\n");
	}else{
		printf("[   스택   ]\n");
		printf("i----------i\n");
		for (int i = 0; i < tStack->size; i++) {
			printf("I %5d    I\n", tStack->data[tStack->size - i]);
		}
		printf("I----------I");
	}
}