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

// 두 개의 TimeStamp를 비교하는 함수.
int comparingTimestamp(TIMESTAMP stamp1, TIMESTAMP stamp2, int level);

int main() {
	// 구조체 선언하기.
	TIMESTAMP timeStamp1, timeStamp2;
	// 계산된 시간, 분, 초를 저장하는 변수.
	int resultHour = 0, resultMin = 0, resultSec = 0;


	printf("입력 : ");
	scanf("%d %d %d %d %d %d", &timeStamp1.Date.year, &timeStamp1.Date.month, &timeStamp1.Date.day, &timeStamp1.Time.hour, &timeStamp1.Time.min, &timeStamp1.Time.sec);
	printf("       ");
	scanf("%d %d %d %d %d %d", &timeStamp2.Date.year, &timeStamp2.Date.month, &timeStamp2.Date.day, &timeStamp2.Time.hour, &timeStamp2.Time.min, &timeStamp2.Time.sec);

	/* 계산 알고리즘.
	* 1. 날짜 비교하기.
	* 날짜(year, month, day)를 각각 비교하기.
	* 1) year 비교하기. if) year가 같다면, month 비교하기.
	* 2) month 비교하기. if) month가 같다면, day 비교하기.
	* 3) day 비교하기. if) day가 같다면, hour 비교하기.
	* 4) hour 비교하기. if) hour가 같다면, min 비교하기.
	* 5) min 비교하기. if) min이 같다면, sec 비교하기.
	* 6) sec 비교하기. if) sec가 같다면, '0시 0분 0초' 출력하기.
	* 큰 값은 더 뒤에 있는 날짜, 작은 값은 큰 값보다 앞에 있는 날짜.
	* 큰 값에서 작은 값을 빼야 하는 것.
	*/


	/* 비교 레벨 선언하기.
	* 0 : year 비교
	* 1 : month 비교
	* 2 : day 비교 
	* 3 : hour 비교
	* 4 : min 비교
	* 5 : sec 비교
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

	return 0;
}

int comparingTimestamp(TIMESTAMP stamp1, TIMESTAMP stamp2, int level) {
	// 계산을 위한 변수 선언하기.
	int tempYear = 0, tempMonth = 0, tempDay = 0, tempHour = 0, tempMin = 0, tempSec = 0;
	// 윤년임을 파악하기 위한 변수
	int isLeapYear = 0;

	// 나중에 남은 year, month, day를 hour로 변경하기 위해서 윤년임을 저장하는 알고리즘.
	if (((stamp1.Date.year % 4 == 0 && stamp1.Date.year % 100 != 0) || stamp1.Date.year % 400 == 0)) {
		isLeapYear = 1;
	}else{
		isLeapYear = 0;
	}

	// 차이 계산하기.
	tempYear = stamp1.Date.year - stamp2.Date.year;

	// 늦은 시각과 빠른 시각의 차가 0 미만일 때, year에서 1을 빼고 month를 추가한다.
	if (stamp1.Date.month - stamp2.Date.month < 0) {
		tempYear--;
		stamp1.Date.month = stamp1.Date.month + 12; // 1년을 제외하고, 12개월을 추가함.
	}
	tempMonth = stamp1.Date.month - stamp2.Date.month;

	// 늦은 시각과 빠른 시각의 차가 0 미만일 때, month에서 1을 빼고 day를 추가한다.
	if (stamp1.Date.day - stamp2.Date.day < 0) {
		// 짝수 달인지, 홀수 달인지 체크하기.
		if(stamp1.Date.day % 2 == 0){ // 짝수 달이라면,
			// 윤년 검증하기. -> 2월달이고, 윤년이라면 29일을 추가.
			if (stamp1.Date.month == 2 && ((stamp1.Date.year % 4 == 0 && stamp1.Date.year % 100 != 0) || stamp1.Date.year % 400 == 0)) {
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 29;
			}else if(stamp1.Date.day == 2){ // 윤년이 아닌 2월달이라면 28일을 추가.
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 28;
			}else{ // 2월달 제외 짝수달의 day 처리.
				tempMonth--;
				stamp1.Date.day = stamp1.Date.day + 30;
			}
		}else{ // 홀수 달이라면,
			tempMonth--;
			stamp1.Date.day = stamp1.Date.day + 31;
		}
	}
	tempDay = stamp1.Date.day - stamp2.Date.day;

	// 늦은 시각과 빠른 시각의 차가 0 미만일 때, day에서 1을 빼고 hour를 추가한다.
	if (stamp1.Time.hour - stamp2.Time.hour < 0) {
		tempDay--;
		stamp1.Time.hour =  stamp1.Time.hour + 24;
	}
	tempHour = stamp1.Time.hour - stamp2.Time.hour;

	// 늦은 시각과 빠른 시각의 차가 0 미만일 때, hour에서 1을 빼고 min을 추가한다.
	if (stamp1.Time.min - stamp2.Time.min < 0) {
		tempHour--;
		stamp1.Time.min = stamp1.Time.min + 60;
	}
	tempMin = stamp1.Time.min - stamp2.Time.min;

	// 늦은 시각과 빠른 시각의 차가 0 미만일 때, min에서 1을 빼고 sec을 추가한다.
	if (stamp1.Time.sec - stamp2.Time.sec < 0) {
		tempMin--;
		stamp1.Time.sec = stamp1.Time.sec + 60;
	}
	tempSec = stamp1.Time.sec - stamp2.Time.sec;

	// year, month, day를 hour로 환산하는 알고리즘.
	// 1. year를 hour로 변환하기.
	tempHour = tempHour + ((tempYear * 12) * 31) * 24;

	// 2. month를 hour로 변환하기.
	while (1) {
		if (tempMonth == 0) {
			break;
		}
		switch (tempMonth) {
		case 1:
			tempHour = tempHour + 31 * 24; tempMonth--;  break;
		case 2:
			// 윤년일 때는 29일로 변환하여 계산하기.
			if (isLeapYear == 1) {
				tempHour = tempHour + 29 * 24; tempMonth--; break;
			}else { // 윤년이 아닐때는 28일로 변환하여 계산하기.
				tempHour = tempHour + 28 * 24; tempMonth--; break;
			}
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
	}
	// 3. day를 hour로 변환하기.
	tempHour = tempHour + tempDay * 24;

	printf("\n출력 : %d시  %d분 %d초\n", tempHour, tempMin, tempSec);

	return 0;
}