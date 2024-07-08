#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	char* text = (char*)malloc(sizeof(char) * 20);

	printf("ют╥б : ");
	scanf("%[^\n]s", text);

	printf("%s", text);


	return 0;
}