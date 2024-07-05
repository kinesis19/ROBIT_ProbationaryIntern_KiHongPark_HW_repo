#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	/*Student student[6];*/

	Student student[6] = { {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "}, {0, 0.0, " "} };

	// ���� ������ϱ�.
	printf("�Է� : ");

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

	// �����ϱ� (��������)
	for (i = 0; i < personMax; i++) {
		for (j = i; j < personMax; j++) {

			// ���� ���� 1: �г� �������� �����ϱ� ,
			if (student[i].schoolYear > student[j].schoolYear) {
				// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
				int tempSchoolYear;
				double tempGrade;
				char tempName;

				// �г� ��ġ �����ϱ�
				tempSchoolYear = student[i].schoolYear;
				student[i].schoolYear = student[j].schoolYear;
				student[j].schoolYear = tempSchoolYear;
				// ���� ��ġ �����ϱ�
				tempGrade = student[i].grade;
				student[i].grade = student[j].grade;
				student[j].grade = tempGrade;

				// �̸� ��ġ �����ϱ�
				/*tempName = student[i].name;
				student[i].name = student[j].name;
				student[j].name = tempName;*/
				
				/*student[5].name = student[i].name;
				student[i].name = student[j].name;
				student[j].name = student[5].name;*/

				student[i].name = student[j].name;

			}else if (student[i].schoolYear == student[j].schoolYear) {
				if (student[i].grade > student[j].grade) {
					// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
					int tempSchoolYear;
					double tempGrade;
					char tempName;

					// �г� ��ġ �����ϱ�
					tempSchoolYear = student[i].schoolYear;
					student[i].schoolYear = student[j].schoolYear;
					student[j].schoolYear = tempSchoolYear;
					// ���� ��ġ �����ϱ�
					tempGrade = student[i].grade;
					student[i].grade = student[j].grade;
					student[j].grade = tempGrade;

					// �̸� ��ġ �����ϱ�
					/*tempName = student[i].name;
					student[i].name = student[j].name;
					student[j].name = tempName;*/

					student[i].name = student[j].name;
				}
				else if (student[i].grade == student[j].grade) {
					if (student[i].name > student[j].name) {
						/*printf("%s %s ", &student[i].name, &student[j].name);*/
						// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
						int tempSchoolYear;
						double tempGrade;
						char tempName;

						// �г� ��ġ �����ϱ�
						tempSchoolYear = student[i].schoolYear;
						student[i].schoolYear = student[j].schoolYear;
						student[j].schoolYear = tempSchoolYear;
						// ���� ��ġ �����ϱ�
						tempGrade = student[i].grade;
						student[i].grade = student[j].grade;
						student[j].grade = tempGrade;

						// �̸� ��ġ �����ϱ�
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