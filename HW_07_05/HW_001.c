#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	Student temp; //�̸� ����(SWAP)�� ���� ����ü ���� �����ϱ�. 
	//-> �Էµ� �л��� ���� �ټ� ���� �Ѱ��̹Ƿ�, 
	// student������ index-5�� ����ص� ������, SWAP�̶�� �뵵�� ��Ÿ���� ���� ����ü�� ���� ���� ������ ������.

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

	// �����ϱ� (��������)
	for (i = 0; i < personMax; i++) {
		for (j = i; j < personMax; j++) {

			// ���� ���� 1: �г� �������� �����ϱ� ,
			if (student[i].schoolYear > student[j].schoolYear) {
				// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
				int tempSchoolYear;
				double tempGrade;

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

			}else if (student[i].schoolYear == student[j].schoolYear) {
				if (student[i].grade > student[j].grade) {
					// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
					int tempSchoolYear;
					double tempGrade;

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

				}else if (student[i].grade == student[j].grade) {
					// �̸��� �� ��°���� ���� ���ϱ�
					for (int n = 0; n < personMax; n++) {
						if (student[i].name[n] > student[j].name[n]) {
							// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
							int tempSchoolYear;
							double tempGrade;

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
						}
					}
				}
			}
		}
	}
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