#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 0

int main() {

#if NUM == 0
	printf("0\n");
#elif NUM == 1
	printf("1\n");
#elif NUM == 2
	printf("2\n");
#elif NUM == 3
	printf("3\n");
#elif NUM == 4
	printf("4\n");
#endif


	return 0;
}