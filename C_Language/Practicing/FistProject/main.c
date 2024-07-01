#include <stdio.h>

int main() {

	int min, max;

	int x = 10, y = 20;

	max = (x > y) ? x : y;
	min = (x > y) ? y : x;

	printf("두 수 %d과 %d 중에 큰 수는 %d이다.\n", x, y, max);
	printf("두 수 %d과 %d 중에 작은 수는 %d이다.\n", x, y, min);
	
	return 0;
}