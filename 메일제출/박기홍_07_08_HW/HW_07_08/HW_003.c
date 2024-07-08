#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next; // ���� ��带 ����Ŵ.
}Node;

typedef struct _LinkedList {
	Node* head;
	Node* tail;
	Node* Cur;
	int size;
}LinkedList;

void Inserting(LinkedList* list);

int main() {
	// �ܼ� ���� ����Ʈ ����ü �����ϱ�.
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(linkedList) * 10);
	// ���1 �����ϱ�.
	Node* node = (Node*)malloc(sizeof(node));
	
	// ���� �����ϱ�.
	char* inputCmd = (char*)malloc(sizeof(char) * 20);
	
	// ���1�� ���� ���� NULL ������.
	/*node->data = NULL;
	printf("size : %d\n\n", node->data);*/

	// ���1 �����ϱ�
	/*printf("Bit structure Data : %d\n\n", node->data);*/



	// ��ɾ�(cmd)�� �Է� �ް�, �� ��ɿ� ���� ������ �۾��� ������.
	while (1){
		scanf("%s", inputCmd);

		if (strcmp(inputCmd, "insert") == 0) {
			// �� ��° ���(���2)�� ���� ���(���1)�� ���� �ڿ� ���Բ� ��.
			/*Node* node = linkedList->tail;*/
			// ���2�� ���� NULL�� ������. (���� ��Ȳ : node1->node2)
			/*node->next->data = NULL;
			printf("%d %d", node->data, node->next->data);*/
			printf("insert!");
		}else if (strcmp(inputCmd, "insert_back") == 0) {
			printf("insert_back!");
		}else if (strcmp(inputCmd, "insert_first") == 0) {
			printf("insert_first!");
		}else if (strcmp(inputCmd, "delete") == 0) {
			printf("delete!");
		}else if (strcmp(inputCmd, "delete_first") == 0) {
			printf("delete_first!");
		}else if (strcmp(inputCmd, "delete_back") == 0) {
			printf("delete_back!");
		}else if (strcmp(inputCmd, "get_entry") == 0) {
			printf("get_entry!");
		}else if (strcmp(inputCmd, "get_length") == 0) {
			printf("get_length!");
		}else if (strcmp(inputCmd, "print_list") == 0) {
			printf("print_list!");
		}else if (strcmp(inputCmd, "reverse") == 0) {
			printf("reverse!");
		}else if (strcmp(inputCmd, "Data") == 0) {
			printf("Data!");
		}

		printf("\n");
	}


	return 0;
}


// 1. insert �Լ�
void Inserting(LinkedList* list) {
	

}