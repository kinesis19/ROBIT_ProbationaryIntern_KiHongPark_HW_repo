#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 학년 구조체 선언
typedef struct _Student {

	int schoolYear;
	double grade;
	char name[20];
}Student;

int main() {

	// 변수 선언하기.
	int personMax = 5;
	int i, j;

	// 구조체 정의하기
	Student student[5];
	Student temp; //이름 변경(SWAP)을 위한 구조체 변수 선언하기. 
	//-> 입력된 학생의 수는 다섯 명이 한계이므로, 
	// student변수의 index-5를 사용해도 되지만, SWAP이라는 용도를 나타내기 위해 구조체에 대한 개별 변수를 선언함.

	// 형식 입출력하기.
	printf("입력 : ");
	// Name을 Null로 초기화 하기 (이름 변경을 위함)
	for (i = 0; i < personMax; i++) {
		for (int k = 0; k < 20; k++) {
			student[i].name[k] = '\0';
		}
	}
	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}

	// 정렬하기 (오름차순)
	for (i = 0; i < personMax; i++) {
		for (j = i; j < personMax; j++) {

			// 정렬 조건 1: 학년 기준으로 정렬하기 ,
			if (student[i].schoolYear > student[j].schoolYear) {
				// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
				int tempSchoolYear;
				double tempGrade;

				// 학년 위치 변경하기
				tempSchoolYear = student[i].schoolYear;
				student[i].schoolYear = student[j].schoolYear;
				student[j].schoolYear = tempSchoolYear;

				// 학점 위치 변경하기
				tempGrade = student[i].grade;
				student[i].grade = student[j].grade;
				student[j].grade = tempGrade;

				// 이름 위치 변경하기
				for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
					temp.name[k] = student[i].name[k];
					student[i].name[k] = student[j].name[k];
					student[j].name[k] = temp.name[k];
				}

			}else if (student[i].schoolYear == student[j].schoolYear) {
				if (student[i].grade > student[j].grade) {
					// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
					int tempSchoolYear;
					double tempGrade;

					// 학년 위치 변경하기
					tempSchoolYear = student[i].schoolYear;
					student[i].schoolYear = student[j].schoolYear;
					student[j].schoolYear = tempSchoolYear;

					// 학점 위치 변경하기
					tempGrade = student[i].grade;
					student[i].grade = student[j].grade;
					student[j].grade = tempGrade;

					// 이름 위치 변경하기
					for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
						temp.name[k] = student[i].name[k];
						student[i].name[k] = student[j].name[k];
						student[j].name[k] = temp.name[k];
					}

				}else if (student[i].grade == student[j].grade) {
					// 이름의 각 번째마다 순서 비교하기
					for (int n = 0; n < personMax; n++) {
						if (student[i].name[n] > student[j].name[n]) {
							// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
							int tempSchoolYear;
							double tempGrade;

							// 학년 위치 변경하기
							tempSchoolYear = student[i].schoolYear;
							student[i].schoolYear = student[j].schoolYear;
							student[j].schoolYear = tempSchoolYear;

							// 학점 위치 변경하기
							tempGrade = student[i].grade;
							student[i].grade = student[j].grade;
							student[j].grade = tempGrade;

							// 이름 위치 변경하기
							for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
								temp.name[k] = student[i].name[k];
								student[i].name[k] = student[j].name[k];
								student[j].name[k] = temp.name[k];
							}
						}
					}
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