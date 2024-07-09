#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	char s1[] = "Hello World!"; // sizeof(s1) = 12.  (뒤에 NULL문자까지 포함해서)
	char* s2 = "Hello World!";

	s1[0] = 'h';

	printf("s1 : %s\n", s1);

	s2 = "Hello World!!"; // s2는 기존의 s2 주소가 아닌 "Hello World!!"의 주소(새로운 주소)를 가리킴.
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