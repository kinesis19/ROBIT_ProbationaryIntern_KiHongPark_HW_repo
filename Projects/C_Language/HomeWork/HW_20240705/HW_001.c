#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	/*Student student[6];*/

	Student student[6] = { {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "} };

	// 형식 입출력하기.
	printf("입력 : ");

	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}
	printf("\n\n");


	// Debugging
	for (int k = 0; k < 1; k++) {
		printf("[%d %d]\n", 0, 0);
		for (int m = 0; m < personMax; m++) {
			printf("%d ", student[m].schoolYear);
		}
		printf("\n");
		for (int m = 0; m < personMax; m++) {
			printf("%.1lf ", student[m].grade);
		}
		printf("\n");
		for (int m = 0; m < personMax; m++) {
			printf("%s ", &student[m].name);
		}
		printf("\n\n");
	}

	// 정렬하기 (오름차순)
	for (i = 0; i < personMax; i++) {
		for (j = i; j < personMax; j++) {

			// 정렬 조건 1: 학년 기준으로 정렬하기 ,
			if (student[i].schoolYear > student[j].schoolYear) {
				// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
				int tempSchoolYear;
				double tempGrade;
				char tempName;

				// 학년 위치 변경하기
				tempSchoolYear = student[i].schoolYear;
				student[i].schoolYear = student[j].schoolYear;
				student[j].schoolYear = tempSchoolYear;
				// 학점 위치 변경하기
				tempGrade = student[i].grade;
				student[i].grade = student[j].grade;
				student[j].grade = tempGrade;

				// 이름 위치 변경하기
				/*tempName = student[i].name;
				student[i].name = student[j].name;
				student[j].name = tempName;*/
				
				/*student[5].name = student[i].name;
				student[i].name = student[j].name;
				student[j].name = student[5].name;*/

				student[i].name = student[j].name;

			}else if (student[i].schoolYear == student[j].schoolYear) {
				if (student[i].grade > student[j].grade) {
					// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
					int tempSchoolYear;
					double tempGrade;
					char tempName;

					// 학년 위치 변경하기
					tempSchoolYear = student[i].schoolYear;
					student[i].schoolYear = student[j].schoolYear;
					student[j].schoolYear = tempSchoolYear;
					// 학점 위치 변경하기
					tempGrade = student[i].grade;
					student[i].grade = student[j].grade;
					student[j].grade = tempGrade;

					// 이름 위치 변경하기
					/*tempName = student[i].name;
					student[i].name = student[j].name;
					student[j].name = tempName;*/

					student[i].name = student[j].name;
				}
				else if (student[i].grade == student[j].grade) {
					if (student[i].name > student[j].name) {
						/*printf("%s %s ", &student[i].name, &student[j].name);*/
						// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
						int tempSchoolYear;
						double tempGrade;
						char tempName;

						// 학년 위치 변경하기
						tempSchoolYear = student[i].schoolYear;
						student[i].schoolYear = student[j].schoolYear;
						student[j].schoolYear = tempSchoolYear;
						// 학점 위치 변경하기
						tempGrade = student[i].grade;
						student[i].grade = student[j].grade;
						student[j].grade = tempGrade;

						// 이름 위치 변경하기
						/*tempName = student[i].name;
						student[i].name = student[j].name;
						student[j].name = tempName;*/

						student[i].name = student[j].name;
					}
				}
			}

			// Debugging
			for (int k = 0; k < 1; k++) {
				printf("[%d %d]\n", i, j);
				for (int m = 0; m < personMax; m++) {
					printf("%d ", student[m].schoolYear);
				}
				printf("\n");
				for (int m = 0; m < personMax; m++) {
					printf("%.1lf ", student[m].grade);
				}
				printf("\n");
				for (int m = 0; m < personMax; m++) {
					printf("%s ", &student[m].name);
				}
				printf("\n\n");
			}

		}
	}


	printf("\n\n");
	/*for (i = 0; i < personMax; i++) {
		printf("%d ", student[i].schoolYear);
	}
	printf("\n\n");
	for (i = 0; i < personMax; i++) {
		printf("%.1lf ", student[i].grade);
	}
	printf("\n\n");
	for (i = 0; i < personMax; i++) {
		printf("%s ", &student[i].name);
	}
	printf("\n\n");*/


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