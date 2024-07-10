#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Stack 구조체 정의하기.
typedef struct _textStack {
	int max; // stack의 용량 저장. (동적)
	char ptr; // stack의 포인터.
	char qPtr; // stack에서 Deque를 하기 위한 포인터. Queue 전용 Struct를 만드는 것 말고, 동일한 Struct에서 Deque가 되도록 시도해 봄.
	char* stk[]; // stack을 가리키는 포인터.
}TextStack;

// 필요한 사용자 정의 함수를 프로토타입으로 선언하기.
void InitializingStack(TextStack* tStack, char* text, int* textCnt); // Stack 초기화 함수.
void PushingStack(TextStack* tStack, char* text); // Stack에 push하는 함수.
void PoppingStack(TextStack* tStack, char* text); // Stack에 pop하는 함수.
/* Stack에서 Deque하는 함수.
* 원래는 Queue에서 Deque를 해야 하지만,
* 미리 선언한 Stack에 Deque 기능을 추가하는 것으로 설계함.
*/ 
void DequeueingStack(TextStack* tStack, char* text);

int main() {

	// 단어, 문장이 입력 되며 회문 여부를 스택과 큐 개념을 사용하여 구해야 함.
	// 1. 문자열을 동적 할당으로 받아 봅시다.
	char* inputText = NULL;
	inputText = (char*)malloc(sizeof(char) * 100);

	TextStack* textStack = (TextStack*)malloc(sizeof(TextStack));
	
	// inputText의 총 갯수를 저장하기 위한 변수.
	int temp = 0;
	int* textCnt = &temp;

	// 형식 입출력하기.
	printf("회문 여부를 파악하고 싶은 문자열 입력 : ");
	scanf("%[^\n]s", inputText);

	printf("\n\n");
	// Stack 초기화하기.
	InitializingStack(textStack, inputText, textCnt);

	printf("%d\n\n\n", *textCnt);
	// inputText 전체를 Stack에 Push하기.
	PushingStack(textStack, inputText);


	textStack->ptr = textStack->max - 1;
	// 회문 판별하기.
	for (int i = 0; i < *textCnt / 2; i++) {
		printf("%c %c\n", textStack->stk[textStack->qPtr], textStack->stk[textStack->ptr]);
		// Stack에서 Deque하기 = 앞에서 하나 빼기.
		DequeueingStack(textStack, inputText);
		// Stack에서 Pop하기 = 뒤에서 하나 빼기.
		PoppingStack(textStack, inputText);
	}

	// 동적 메모리 할당 해제 하기.
	free(inputText);


	return 0;
}
void InitializingStack(TextStack* tStack, char* text, int* textCnt) {

	int cnt = 0;
	for (int i = 0; *(text + i) != NULL; i++) {
		cnt++;
	}
	tStack->ptr = 0; // stack 초기화 시, stack의 pointer는 0으로 초기화 함.
	tStack->qPtr = 0; // stack 초기화 시, queue의 pointer는 0으로 초기화 함.
	tStack->max = cnt; // stack의 용량은 입력된 문자열의 문자 수로 지정함.
	*textCnt = cnt;
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
	/*tStack->ptr = tStack->max - 1;*/
	if (tStack->qPtr < tStack->ptr) { // stack의 용량 범위 이내라면 push를 진행함.
		tStack->stk[tStack->ptr] = NULL;
		tStack->max--;
		tStack->ptr--;
	}else{
		printf("더 이상 Pop을 못 합니다.");
	}
}

void DequeueingStack(TextStack* tStack, char* text) { // 하나씩 deque 하기.
	if (tStack->qPtr < tStack->max) { // stack의 용량 범위 이내라면 push를 진행함.
		tStack->stk[tStack->qPtr] = NULL;
		tStack->qPtr++;
	}else{
		printf("더 이상 Deque를 못 합니다.");
	}
}