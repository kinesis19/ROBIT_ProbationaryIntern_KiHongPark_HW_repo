#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �г� ����ü ����
typedef struct _Student {

	int schoolYear;
	double grade;
	char name[20];
}Student;

int main() {

	// ���� �����ϱ�.
	int personMax = 5;
	int i, j;

	// ����ü �����ϱ�
	Student student[5];
	Student temp;

	// ���� ������ϱ�.
	printf("�Է� : ");
	// Name�� Null�� �ʱ�ȭ �ϱ� (�̸� ������ ����)
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
	printf("\n\n");


	// Debugging
	/*for (int k = 0; k < 1; k++) {
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
	}*/


	for (int m = 0; m < personMax; m++) {
		for (int p = 0; p < personMax; p++) {
			printf("%d ", student[m].name[p]);
			/*if (student[m].name[p] == 0) {
				printf("NULL ");
			}*/
		}
		printf("\n");
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
				for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
					temp.name[k] = student[i].name[k];
					student[i].name[k] = student[j].name[k];
					student[j].name[k] = temp.name[k];
				}
				printf("\n\n");

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
					for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
						temp.name[k] = student[i].name[k];
						student[i].name[k] = student[j].name[k];
						student[j].name[k] = temp.name[k];
					}
					printf("\n\n");
				}else if (student[i].grade == student[j].grade) {
					printf("aaaaaaaaaaaaaaaaaaaaaaaaa\n");
					// �̸��� �� ��°���� ���� ���ϱ�
					for (int n = 0; n < personMax; n++) {
						if (student[i].name[n] > student[j].name[n]) {
							printf("bbbbbbbbbbbbbbbbbbbbbbb\n");
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
							for (int k = 0; student[i].name[k] != 0 || student[j].name[k] != 0; k++) {
								printf("Before: %d %d\n", student[i].name[k], student[j].name[k]);
								temp.name[k] = student[i].name[k];
								student[i].name[k] = student[j].name[k];
								student[j].name[k] = temp.name[k];
								printf("After: %d %d\n", student[i].name[k], student[j].name[k]);
							}
							printf("\n\n");
						}
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
					printf("%s ", &student[m].name[0]);
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