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
	Student student[5];


	// 형식 입출력하기.
	printf("입력 : ");

	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}


	for (int k = 0; k < personMax; k++) {
		printf("%.1lf ", student[k].grade);
	}
	printf("\n\n");

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
				tempName = student[i].name;
				student[i].name = student[j].name;
				student[j].name = tempName;
			}else if(student[i].schoolYear == student[j].schoolYear){
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
					tempName = student[i].name;
					student[i].name = student[j].name;
					student[j].name = tempName;
				}else if(student[i].grade == student[j].grade){
					/*printf("%d %d ", student[i].name, student[j].name);*/
					if (student[i].name > student[j].name) {
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
						tempName = student[i].name;
						student[i].name = student[j].name;
						student[j].name = tempName;
						student[i].name = student[j].name;

					}
				}
			}

		}
		// Debugging
		/*for (int k = 0; k < personMax; k++) {
			printf("%.1lf ", student[k].grade);
		}
		printf("\n\n");*/
	}

	/*char* pArrName = (char*)calloc(personMax, sizeof(char));
	pArrName = student[1].name;
	printf("%s", &pArrName[0]);*/

	printf("\n\n");
	for (i = 0; i < personMax; i++) {
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
	printf("\n\n");


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