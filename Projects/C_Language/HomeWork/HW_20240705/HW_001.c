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
	Student student[5];


	// ���� ������ϱ�.
	printf("�Է� : ");

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
				tempName = student[i].name;
				student[i].name = student[j].name;
				student[j].name = tempName;
			}else if(student[i].schoolYear == student[j].schoolYear){
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
					tempName = student[i].name;
					student[i].name = student[j].name;
					student[j].name = tempName;
				}else if(student[i].grade == student[j].grade){
					/*printf("%d %d ", student[i].name, student[j].name);*/
					if (student[i].name > student[j].name) {
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