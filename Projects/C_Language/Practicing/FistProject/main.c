#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int i = 0;
	int key = 0;
	int list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	printf("탐색할 값을 적으시오 : ");
	scanf("%d", &key);

	for (i = 0; i < 8; i++) {
		if (list[i] == key) {
			printf("Find! list[%d]\n", i);
			break;
		}
	}
	printf("end\n");

	return 0;
}