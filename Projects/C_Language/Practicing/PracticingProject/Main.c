#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	char s1[] = "Hello World!"; // sizeof(s1) = 12.  (�ڿ� NULL���ڱ��� �����ؼ�)
	char* s2 = "Hello World!";

	s1[0] = 'h';

	printf("s1 : %s\n", s1);

	s2 = "Hello World!!"; // s2�� ������ s2 �ּҰ� �ƴ� "Hello World!!"�� �ּ�(���ο� �ּ�)�� ����Ŵ.
	printf("s2 : %s\n", s2);

	for (int i = 0; s1[i] != '\0'; i++) {
		printf("%c", s1[i]);
	}
	printf("\n");

	for (int i = 0; i < sizeof(s1)/sizeof(char); i++) {
		printf("%c", s1[i]);
	}
	printf("\n");

	return 0;
}