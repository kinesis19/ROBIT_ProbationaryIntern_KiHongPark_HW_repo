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

// �� ���� TimeStamp�� ���ϴ� �Լ�.
int comparingTimestamp(TIMESTAMP stamp1, TIMESTAMP stamp2, int level);

int main() {
	// ����ü �����ϱ�.
	TIMESTAMP timeStamp1, timeStamp2;
	// ���� �ð�, ��, �ʸ� �����ϴ� ����.
	int resultHour = 0, resultMin = 0, resultSec = 0;


	printf("�Է� : ");
	scanf("%d %d %d %d %d %d", &timeStamp1.Date.year, &timeStamp1.Date.month, &timeStamp1.Date.day, &timeStamp1.Time.hour, &timeStamp1.Time.min, &timeStamp1.Time.sec);
	printf("       ");
	scanf("%d %d %d %d %d %d", &timeStamp2.Date.year, &timeStamp2.Date.month, &timeStamp2.Date.day, &timeStamp2.Time.hour, &timeStamp2.Time.min, &timeStamp2.Time.sec);

	/* ��� �˰���.
	* 1. ��¥ ���ϱ�.
	* ��¥(year, month, day)�� ���� ���ϱ�.
	* 1) year ���ϱ�. if) year�� ���ٸ�, month ���ϱ�.
	* 2) month ���ϱ�. if) month�� ���ٸ�, day ���ϱ�.
	* 3) day ���ϱ�. if) day�� ���ٸ�, hour ���ϱ�.
	* 4) hour ���ϱ�. if) hour�� ���ٸ�, min ���ϱ�.
	* 5) min ���ϱ�. if) min�� ���ٸ�, sec ���ϱ�.
	* 6) sec ���ϱ�. if) sec�� ���ٸ�, '0�� 0�� 0��' ����ϱ�.
	* ū ���� �� �ڿ� �ִ� ��¥, ���� ���� ū ������ �տ� �ִ� ��¥.
	* ū ������ ���� ���� ���� �ϴ� ��.
	*/


	/* �� ���� �����ϱ�.
	* 0 : year ��
	* 1 : month ��
	* 2 : day �� 
	* 3 : hour ��
	* 4 : min ��
	* 5 : sec ��
	*/
	int compareLevel = 0;

	if (timeStamp1.Date.year > timeStamp2.Date.year) {
		comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
	}else if(timeStamp1.Date.year == timeStamp2.Date.year){
		compareLevel++;
		if (timeStamp1.Date.month > timeStamp2.Date.month) {
			comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
		}else if(timeStamp1.Date.month == timeStamp2.Date.month){
			compareLevel++;
			if (timeStamp1.Date.day > timeStamp2.Date.day) {
				comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
			}else if (timeStamp1.Date.day == timeStamp2.Date.day) {
				compareLevel++;
				if (timeStamp1.Time.hour > timeStamp2.Time.hour) {
					comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
				}else if(timeStamp1.Time.hour == timeStamp2.Time.hour){
					compareLevel++;
					if (timeStamp1.Time.min > timeStamp2.Time.min) {
						comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
					}else if(timeStamp1.Time.min == timeStamp2.Time.min){
						compareLevel++;
						if (timeStamp1.Time.sec > timeStamp2.Time.sec) {
							comparingTimestamp(timeStamp1, timeStamp2, compareLevel);
						}else{
							comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
						}
					}else {
						comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
					}
				}else {
					comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
				}
			}else {
				comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
			}
		}else {
			comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
		}
	}else{
		comparingTimestamp(timeStamp2, timeStamp1, compareLevel);
	}



	//Debugging:
	/*printf("%02d %02d %02d %02d %02d %02d\n", timeStamp1.Date.year, timeStamp1.Date.month, timeStamp1.Date.day, timeStamp1.Time.hour, timeStamp1.Time.min, timeStamp1.Time.sec);
	printf("       ");
	printf("%02d %02d %02d %02d %02d %02d", timeStamp2.Date.year, timeStamp2.Date.month, timeStamp2.Date.day, timeStamp2.Time.hour, timeStamp2.Time.min, timeStamp2.Time.sec);*/


	return 0;
}

int comparingTimestamp(TIMESTAMP stamp1, TIMESTAMP stamp2, int level) {
	// ����� ���� ���� �����ϱ�.
	int tempYear = 0, tempMonth = 0, tempDay = 0, tempHour = 0, tempMin = 0, tempSec = 0;
	// ���� ����ϱ�.
	tempYear = stamp1.Date.year - stamp2.Date.year;

	// ���� �ð��� ���� �ð��� ���� 0 �̸��� ��, year���� 1�� ���� month�� �߰��Ѵ�.
	if (stamp1.Date.month - stamp2.Date.month < 0) {
		tempYear--;
		stamp1.Date.month = stamp1.Date.month + 12; // 1���� �����ϰ�, 12������ �߰���.
	}
	tempMonth = stamp1.Date.month - stamp2.Date.month;

	if (stamp1.Date.day - stamp2.Date.day < 0) {
		// ¦�� ������, Ȧ�� ������ üũ�ϱ�.
		if(stamp1.Date.day % 2 == 0){ // ¦�� ���̶��,
			// ���� �����ϱ�. -> 2�����̰�, �����̶�� 29���� �߰�.
			if (stamp1.Date.month == 2 && ((stamp1.Date.year % 4 == 0 && stamp1.Date.year % 100 != 0) || stamp1.Date.year % 400 == 0)) {
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 29;
			}else if(stamp1.Date.day == 2){ // ������ �ƴ� 2�����̶�� 28���� �߰�.
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 28;
			}else{ // 2���� ���� ¦������ day ó��.
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 30;
			}
		}else{ // Ȧ�� ���̶��,
			tempMonth--;
			stamp1.Date.day = stamp1.Date.day + 31;
		}
	}
	tempDay = stamp1.Date.day - stamp2.Date.day;

	if (stamp1.Time.hour - stamp2.Time.hour < 0) {
		tempDay--;
		stamp1.Time.hour =  stamp1.Time.hour + 24;
	}
	tempHour = stamp1.Time.hour - stamp2.Time.hour;

	if (stamp1.Time.min - stamp2.Time.min < 0) {
		tempHour--;
		stamp1.Time.min = stamp1.Time.min + 60;
	}
	tempMin = stamp1.Time.min - stamp2.Time.min;

	if (stamp1.Time.sec - stamp2.Time.sec < 0) {
		tempMin--;
		stamp1.Time.sec = stamp1.Time.sec + 60;
	}
	tempSec = stamp1.Time.sec - stamp2.Time.sec;

	// year, month, day�� hour�� ȯ���ϴ� �˰���.

	printf("       %d %d %d %d %d %d\n\n", tempYear, tempMonth, tempDay, tempHour, tempMin, tempSec);
	tempHour = tempHour + ((tempYear * 12) * 31) * 24;

	while (1) {
		if (tempMonth == 0) {
			break;
		}
		printf("%d ::::::::: ", tempMonth);
		switch (tempMonth) {
		case 1:
			tempHour = tempHour + 31 * 24; tempMonth--;  break;
		case 2:
			tempHour = tempHour + 28 * 24; tempMonth--; break;
		case 3:
			tempHour = tempHour + 31 * 24; tempMonth--; break;
		case 4:
			tempHour = tempHour + 30 * 24; tempMonth--; break;
		case 5:
			tempHour = tempHour + 31 * 24; tempMonth--; break;
		case 6:
			tempHour = tempHour + 30 * 24; tempMonth--; break;
		case 7:
			tempHour = tempHour + 31 * 24; tempMonth--; break;
		case 8:
			tempHour = tempHour + 30 * 24; tempMonth--; break;
		case 9:
			tempHour = tempHour + 31 * 24; tempMonth--; break;
		case 10:
			tempHour = tempHour + 30 * 24; tempMonth--; break;
		case 11:
			tempHour = tempHour + 31 * 24; tempMonth--; break;
		case 12:
			tempHour = tempHour + 30 * 24; tempMonth--; break;
		default:
			break;
		}
		printf(" || Total Hour : %d\n", tempHour);
	}
	printf("\n");

	tempHour = tempHour + tempDay * 24;
	printf("Day=====%d || Total Hour : %d", tempDay * 24, tempHour);

	printf("       %d %d %d %d %d %d\n\n", tempYear, tempMonth, tempDay, tempHour, tempMin, tempSec);
	printf("��� : %d��  %d�� %d��\n", tempHour, tempMin, tempSec);

	return 0;
}