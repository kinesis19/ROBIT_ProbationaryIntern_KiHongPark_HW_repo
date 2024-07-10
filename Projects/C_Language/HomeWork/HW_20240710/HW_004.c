#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _textStack {
	int max; // stack�� �뷮 ����.
	int ptr; // stack�� ������.
	int* stk; // stack�� ����Ű�� ������.
}TextStack;

void GettingPalindrome(char* text);
void InitializingStack(TextStack* tStack, char* text); // Stack �ʱ�ȭ �Լ�.
void PushingStack(TextStack* tStack, char* text); // Stack�� push�ϴ� �Լ�.

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

	for (int i = 0; *(inputText + i) != NULL; i++) {
		printf("%c ", textStack->stk[textStack->ptr]);
		textStack->stk[textStack->ptr] = *(inputText + i);
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
	printf("aa");
	if (tStack->ptr < tStack->max) { // stack�� �뷮 ���� �̳���� push�� ������.
		printf("�Ф�\n\n");
		for (int i = 0; *(text + i) != NULL; i++) {
			/*printf("%d\n", *(text + i));*/
			/*tStack->stk[tStack->ptr] = 0;*/
			printf("%d\n\n", sizeof(*(text + i)));
			printf("%d %d\n\n", tStack->stk, tStack->ptr);
			printf("%c %d\n", *(text + i), *(text + i));
			tStack->ptr++;
		}
	}

}

void GettingPalindrome(char* text) {
	char a[] = "bbbb";
	text = a;
}