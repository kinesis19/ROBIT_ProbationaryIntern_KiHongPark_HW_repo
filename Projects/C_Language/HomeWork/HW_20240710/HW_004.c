#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Stack ����ü �����ϱ�.
typedef struct _textStack {
	int max; // stack�� �뷮 ����.
	char ptr; // stack�� ������.
	char* stk[]; // stack�� ����Ű�� ������.
}TextStack;

// �ʿ��� ����� ���� �Լ��� ������Ÿ������ �����ϱ�.
void InitializingStack(TextStack* tStack, char* text); // Stack �ʱ�ȭ �Լ�.
void PushingStack(TextStack* tStack, char* text); // Stack�� push�ϴ� �Լ�.
void PoppingStack(TextStack* tStack, char* text); // Stack�� pop�ϴ� �Լ�.

int main() {

	// �ܾ�, ������ �Է� �Ǹ� ȸ�� ���θ� ���ð� ť ������ ����Ͽ� ���ؾ� ��.
	// 1. ���ڿ��� ���� �Ҵ����� �޾� ���ô�.
	char* inputText = NULL;
	inputText = (char*)malloc(sizeof(char) * 100);

	TextStack* textStack = (TextStack*)malloc(sizeof(TextStack));

	// ���� ������ϱ�.
	printf("ȸ�� ���θ� �ľ��ϰ� ���� ���ڿ� �Է� : ");
	scanf("%[^\n]s", inputText);

	for (int i = 0; *(inputText + i) != NULL; i++) {
		printf("%c", *(inputText + i));
	}
	InitializingStack(textStack, inputText);
	/*GettingPalindrome(&inputText);*/

	printf("\n");
	printf("%d\n", textStack->max);
	printf("%s\n", inputText);

	PushingStack(textStack, inputText);

	PoppingStack(textStack, inputText);

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
	tStack->ptr = 0; // stack �ʱ�ȭ ��, ������ pointer�� 0���� �ʱ�ȭ ��.
	tStack->max = cnt; // stack�� �뷮�� �Էµ� ���ڿ��� ���� ���� ������.
	printf(" : %d", tStack->max);
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