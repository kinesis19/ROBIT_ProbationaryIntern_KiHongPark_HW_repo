#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Stack 구조체 정의하기.
typedef struct _textStack {
	int max; // stack의 용량 저장.
	char ptr; // stack의 포인터.
	char* stk[]; // stack을 가리키는 포인터.
}TextStack;

// 필요한 사용자 정의 함수를 프로토타입으로 선언하기.
void InitializingStack(TextStack* tStack, char* text); // Stack 초기화 함수.
void PushingStack(TextStack* tStack, char* text); // Stack에 push하는 함수.
void PoppingStack(TextStack* tStack, char* text); // Stack에 pop하는 함수.

int main() {

	// 단어, 문장이 입력 되며 회문 여부를 스택과 큐 개념을 사용하여 구해야 함.
	// 1. 문자열을 동적 할당으로 받아 봅시다.
	char* inputText = NULL;
	inputText = (char*)malloc(sizeof(char) * 100);

	TextStack* textStack = (TextStack*)malloc(sizeof(TextStack));

	// 형식 입출력하기.
	printf("회문 여부를 파악하고 싶은 문자열 입력 : ");
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

	// 동적 메모리 할당 해제 하기.
	free(inputText);


	return 0;
}
void InitializingStack(TextStack* tStack, char* text) {

	int cnt = 0;
	for (int i = 0; *(text + i) != NULL; i++) {
		cnt++;
	}
	tStack->ptr = 0; // stack 초기화 시, 스택의 pointer는 0으로 초기화 함.
	tStack->max = cnt; // stack의 용량은 입력된 문자열의 문자 수로 지정함.
	printf(" : %d", tStack->max);
}

void PushingStack(TextStack* tStack, char* text) {
	if (tStack->ptr < tStack->max) { // stack의 용량 범위 이내라면 push를 진행함.
		for (int i = 0; *(text + i) != NULL; i++) {
			tStack->stk[tStack->ptr] = *(text + i);
			tStack->ptr++;
		}
	}
}
void PoppingStack(TextStack* tStack, char* text) { // 하나씩 pop 하기.
	tStack->ptr = tStack->max - 1;
	if (0 < tStack->ptr) { // stack의 용량 범위 이내라면 push를 진행함.
		tStack->stk[tStack->ptr] = NULL;
		tStack->max--;
	}
}