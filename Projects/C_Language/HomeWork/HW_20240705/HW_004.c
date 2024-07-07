#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int year, month, day;
}DATE;

typedef struct {
	int hour, min, sec;
}TIME;

typedef struct {
	DATE Date;
	TIME Time;
}TIMESTAMP;


int main() {
	TIMESTAMP timeStamp1, timeStamp2;
	
	printf("입력 : ");
	scanf("%d %d %d %d %d %d", &timeStamp1.Date.year, &timeStamp1.Date.month, &timeStamp1.Date.day, &timeStamp1.Time.hour, &timeStamp1.Time.min, &timeStamp1.Time.sec);
	printf("       ");
	scanf("%d %d %d %d %d %d", &timeStamp2.Date.year, &timeStamp2.Date.month, &timeStamp2.Date.day, &timeStamp2.Time.hour, &timeStamp2.Time.min, &timeStamp2.Time.sec);

	printf("출력 : ");
	//Debugging:
	printf("%02d %02d %02d %02d %02d %02d\n", timeStamp1.Date.year, timeStamp1.Date.month, timeStamp1.Date.day, timeStamp1.Time.hour, timeStamp1.Time.min, timeStamp1.Time.sec);
	printf("       ");
	printf("%02d %02d %02d %02d %02d %02d", timeStamp2.Date.year, timeStamp2.Date.month, timeStamp2.Date.day, timeStamp2.Time.hour, timeStamp2.Time.min, timeStamp2.Time.sec);


	return 0;
}