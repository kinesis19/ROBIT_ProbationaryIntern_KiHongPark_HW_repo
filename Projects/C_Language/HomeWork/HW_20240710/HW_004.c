#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Stack ����ü �����ϱ�.
typedef struct _textStack {
	int max; // stack�� �뷮 ����.
	char ptr; // stack�� ������.
	char qPtr; // stack���� Deque�� �ϱ� ���� ������. Queue ���� Struct�� ����� �� ����, ������ Struct���� Deque�� �ǵ��� �õ��� ��.
	char* stk[]; // stack�� ����Ű�� ������.
}TextStack;

// �ʿ��� ����� ���� �Լ��� ������Ÿ������ �����ϱ�.
void InitializingStack(TextStack* tStack, char* text); // Stack �ʱ�ȭ �Լ�.
void PushingStack(TextStack* tStack, char* text); // Stack�� push�ϴ� �Լ�.
void PoppingStack(TextStack* tStack, char* text); // Stack�� pop�ϴ� �Լ�.
/* Stack���� Deque�ϴ� �Լ�.
* ������ Queue���� Deque�� �ؾ� ������,
* �̸� ������ Stack�� Deque ����� �߰��ϴ� ������ ������.
*/ 
void DequeueingStack(TextStack* tStack, char* text); 

int main() {

	// �ܾ�, ������ �Է� �Ǹ� ȸ�� ���θ� ���ð� ť ������ ����Ͽ� ���ؾ� ��.
	// 1. ���ڿ��� ���� �Ҵ����� �޾� ���ô�.
	char* inputText = NULL;
	inputText = (char*)malloc(sizeof(char) * 100);

	TextStack* textStack = (TextStack*)malloc(sizeof(TextStack));

	// ���� ������ϱ�.
	printf("ȸ�� ���θ� �ľ��ϰ� ���� ���ڿ� �Է� : ");
	scanf("%[^\n]s", inputText);

	printf("\n\n");
	// Stack �ʱ�ȭ�ϱ�.
	InitializingStack(textStack, inputText);
	// inputText ��ü�� Stack�� Push�ϱ�.
	PushingStack(textStack, inputText);
	// Stack���� Pop�ϱ� = �ڿ��� �ϳ� ����.
	PoppingStack(textStack, inputText);
	// Stack���� Deque�ϱ� = �տ��� �ϳ� ����.
	DequeueingStack(textStack, inputText);

	textStack->ptr = 0;
	for (int i = 0; *(inputText + i) != NULL; i++) {
		printf("%c ", textStack->stk[textStack->ptr]);
		textStack->ptr++;
	}

	// ���� �޸� �Ҵ� ���� �ϱ�.
	free(inputText);


	return 0;
}
void InitializingStack(TextStack* tStack, char* text) {

	int cnt = 0;
	for (int i = 0; *(text + i) != NULL; i++) {
		cnt++;
	}
	tStack->ptr = 0; // stack �ʱ�ȭ ��, stack�� pointer�� 0���� �ʱ�ȭ ��.
	tStack->qPtr = 0; // stack �ʱ�ȭ ��, queue�� pointer�� 0���� �ʱ�ȭ ��.
	tStack->max = cnt; // stack�� �뷮�� �Էµ� ���ڿ��� ���� ���� ������.
}

void PushingStack(TextStack* tStack, char* text) {
	if (tStack->ptr < tStack->max) { // stack�� �뷮 ���� �̳���� push�� ������.
		for (int i = 0; *(text + i) != NULL; i++) {
			tStack->stk[tStack->ptr] = *(text + i);
			tStack->ptr++;
		}
	}
}
void PoppingStack(TextStack* tStack, char* text) { // �ϳ��� pop �ϱ�.
	tStack->ptr = tStack->max - 1;
	if (0 < tStack->ptr) { // stack�� �뷮 ���� �̳���� push�� ������.
		tStack->stk[tStack->ptr] = NULL;
		tStack->max--;
	}
}

void DequeueingStack(TextStack* tStack, char* text) { // �ϳ��� deque �ϱ�.
	if (tStack->qPtr < tStack->max) { // stack�� �뷮 ���� �̳���� push�� ������.
		tStack->stk[tStack->qPtr] = NULL;
		tStack->qPtr++;
	}
}