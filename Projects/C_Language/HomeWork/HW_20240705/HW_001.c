#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 학년 구조체 선언
typedef struct _Student {

	int schoolYear;
	double grade;
	char name;
}Student;

int main() {

	// 변수 선언하기.
	int personMax = 5;
	int i, j;

	// 구조체 정의하기
	Student student[5];


	// 형식 입출력하기.
	printf("입력 : ");

	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}

	// 정렬하기 (오름차순)
	for (i = 0; i < personMax; i++) {
		for (j = 0; j < personMax; j++) {
			// 정렬 조건 1: 학년 기준으로 정렬하기 ,
			if (student[i].schoolYear > student[j].schoolYear) {
				int tempSchoolYear;
				tempSchoolYear = student[i].schoolYear;
				student[i].schoolYear = student[j].schoolYear;
				student[j].schoolYear = tempSchoolYear;
			}else if(student[i].schoolYear == student[j].schoolYear){
				// 정렬 조건 2: 학년이 동일할 땐 학점을 기준으로 정렬하기.
				if (student[i].grade > student[j].grade) {
					int tempGrade;
					tempGrade = student[i].grade;
					student[i].grade = student[j].grade;
					student[j].grade = tempGrade;
				}else if(student[i].grade == student[j].grade){
					// 정렬 조건 3: 학점이 동일할 땐 이름을 기준으로 정렬하기.
					/*if (student[i].name > student[j].grade) {
						int tempName;
						tempName = student[i].name;
						student[i].name = student[j].name;
						student[j].name = tempName;
					}*/
				}
			}
		}
	}








	// 최종 결과 값 출력하기.
	printf("\n출력 : ");
	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		printf("%d %.1lf %s\n", student[i].schoolYear, student[i].grade, &student[i].name);
	}

	
	return 0;
}