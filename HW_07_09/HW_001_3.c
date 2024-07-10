#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void SetStr(char** str);

int main() {

	char* str;

	str = "I'am sad";
	
	SetStr(&str);

	printf("%s", str);

	return 0;
}

void SetStr(char** str) {
	*str = "I'am happy";
}