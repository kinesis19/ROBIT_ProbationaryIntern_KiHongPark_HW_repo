#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _textStack {
	int max; // stack�� �뷮 ����.
	int ptr; // stack�� ������.
	int* stk; // stack�� ����Ű�� ������.
}TextStack;

void GettingPalindrome(char* text);
void InitializingStack(TextStack* tStack, char* text);

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
	printf("%s", inputText);

	// ���� �޸� �Ҵ� ���� �ϱ�.
	free(inputText);


	return 0;
}
void InitializingStack(TextStack* tStack, char* text) {

	int cnt = 0;
	for (int i = 0; *(text + i) != NULL; i++) {
		cnt++;
	}
	tStack->max = 0; // stack �ʱ�ȭ ��, ������ pointer�� 0���� �ʱ�ȭ ��.
	tStack->max = cnt; // stack�� �뷮�� �Էµ� ���ڿ��� ���� ���� ������.
	printf(" : %d", tStack->max);
}

void GettingPalindrome(char* text) {
	char a[] = "bbbb";
	text = a;
}