#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �г� ����ü ����
typedef struct _Student {

	int schoolYear;
	double grade;
	char name;
}Student;

int main() {

	// ���� �����ϱ�.
	int personMax = 5;
	int i, j;

	// ����ü �����ϱ�
	Student student[5];


	// ���� ������ϱ�.
	printf("�Է� : ");

	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		scanf("%d %lf %s", &student[i].schoolYear, &student[i].grade, &student[i].name);
	}
	// Nesting ���� �߻�!!!!!!!! ���!!!!!

	// �����ϱ� (��������)
	for (i = 0; i < personMax; i++) {
		for (j = 0; j < personMax; j++) {
			// ���� ���� 1: �г� �������� �����ϱ� ,
			if (student[i].schoolYear > student[j].schoolYear) {
				/*printf("%d %d\n\n", student[i].schoolYear, student[j].schoolYear);*/
				// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
				int tempSchoolYear, tempGrade, tempName;
				tempSchoolYear = student[i].schoolYear;
				tempGrade = student[i].grade;
				tempName = student[i].name;

				// �г� ��ġ �����ϱ�
				student[i].schoolYear = student[j].schoolYear;
				student[j].schoolYear = tempSchoolYear;

				/*printf("%d %d\n\n", student[i].schoolYear, student[j].schoolYear);*/
				//// ���� ��ġ �����ϱ�
				//student[i].grade = student[j].grade;
				//student[j].grade = tempGrade;
				//// �̸� ��ġ �����ϱ�
				//student[i].name = student[j].name;
				//student[j].name = tempName;
			}else if (student[i].schoolYear == student[j].schoolYear) {
				/*printf("%.1lf %.1lf\n\n", student[i].grade, student[j].grade);*/
				// ���� ���� 2: �г��� ������ �� ������ �������� �����ϱ�.
				if (student[i].grade > student[j].grade) {
					int tempGrade;
					tempGrade = student[i].grade;
					student[i].grade = student[j].grade;
					student[j].grade = tempGrade;

				}else if (student[i].grade == student[j].grade) {
					// ���� ���� 3: ������ ������ �� �̸��� �������� �����ϱ�.
					/*if (student[i].name > student[j].grade) {
						int tempName;
						tempName = student[i].name;
						student[i].name = student[j].name;
						student[j].name = tempName;
					}*/
				}
		}
	}



	for (i = 0; i < personMax; i++) {
		printf("%s ", &student[i].name);
	}
	/*for (i = 0; i < personMax; i++) {
		printf("%.1lf ", student[i].grade);
	}*/

	printf("\n\n");








	// ���� ��� �� ����ϱ�.
	printf("\n��� : ");
	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		printf("%d %.1lf %s\n", student[i].schoolYear, student[i].grade, &student[i].name);
	}

	
	return 0;
}