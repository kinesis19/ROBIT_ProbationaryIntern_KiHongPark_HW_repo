#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct _Stack {
	Node* top;
	int size;
}Stack;


int main() {
	
	// Stack ���� �� �����Ҵ���.
	Stack* stack = (Stack*)malloc(sizeof(stack));




}