#include <stdio.h>

int main() {

	int min, max;

	int x = 10, y = 20;

	max = (x > y) ? x : y;
	min = (x > y) ? y : x;

	printf("�� �� %d�� %d �߿� ū ���� %d�̴�.\n", x, y, max);
	printf("�� �� %d�� %d �߿� ���� ���� %d�̴�.\n", x, y, min);
	
	return 0;
}