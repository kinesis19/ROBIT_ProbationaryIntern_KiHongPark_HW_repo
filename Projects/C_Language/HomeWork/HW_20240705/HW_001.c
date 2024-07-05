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
	// Nesting 현상 발생!!!!!!!! 비상!!!!!

	// 정렬하기 (오름차순)
	for (i = 0; i < personMax - 1; i++) {
		// 정렬 조건 1: 학년 기준으로 정렬하기 ,
		if (student[i].schoolYear > student[i + 1].schoolYear) {
			/*printf("%d %d\n\n", student[i].schoolYear, student[i + 1].schoolYear);*/
			// 학년, 학점, 이름 변경을 위한 임시 변수 선언 및 정의하기.
			int tempSchoolYear, tempGrade, tempName;
			tempSchoolYear = student[i].schoolYear;
			tempGrade = student[i].grade;
			tempName = student[i].name;

			// 학년 위치 변경하기
			student[i].schoolYear = student[i + 1].schoolYear;
			student[i + 1].schoolYear = tempSchoolYear;


			/*printf("%d %d\n\n", student[i].schoolYear, student[i + 1].schoolYear);*/
			//// 학점 위치 변경하기
			//student[i].grade = student[i + 1].grade;
			//student[i + 1].grade = tempGrade;
			//// 이름 위치 변경하기
			//student[i].name = student[i + 1].name;
			//student[i + 1].name = tempName;

		}

		//else if(student[i].schoolYear == student[i + 1].schoolYear){
		//	// 정렬 조건 2: 학년이 동일할 땐 학점을 기준으로 정렬하기.
		//	if (student[i].grade < student[i + 1].grade) {
		//		int tempGrade;
		//		tempGrade = student[i].grade;
		//		student[i].grade = student[i + 1].grade;
		//		student[i + 1].grade = tempGrade;


		//	}else if(student[i].grade == student[i + 1].grade){
		//		// 정렬 조건 3: 학점이 동일할 땐 이름을 기준으로 정렬하기.
		//		/*if (student[i].name > student[i + 1].grade) {
		//			int tempName;
		//			tempName = student[i].name;
		//			student[i].name = student[i + 1].name;
		//			student[i + 1].name = tempName;
		//		}*/
		//	}
		//}
	}



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
		printf("%d %.2lf %s\n", student[i].schoolYear, student[i].grade, &student[i].name);
	}

	
	return 0;
}