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
	for (i = 0; i < personMax - 1; i++) {
		// ���� ���� 1: �г� �������� �����ϱ� ,
		if (student[i].schoolYear > student[i + 1].schoolYear) {
			/*printf("%d %d\n\n", student[i].schoolYear, student[i + 1].schoolYear);*/
			// �г�, ����, �̸� ������ ���� �ӽ� ���� ���� �� �����ϱ�.
			int tempSchoolYear, tempGrade, tempName;
			tempSchoolYear = student[i].schoolYear;
			tempGrade = student[i].grade;
			tempName = student[i].name;

			// �г� ��ġ �����ϱ�
			student[i].schoolYear = student[i + 1].schoolYear;
			student[i + 1].schoolYear = tempSchoolYear;


			/*printf("%d %d\n\n", student[i].schoolYear, student[i + 1].schoolYear);*/
			//// ���� ��ġ �����ϱ�
			//student[i].grade = student[i + 1].grade;
			//student[i + 1].grade = tempGrade;
			//// �̸� ��ġ �����ϱ�
			//student[i].name = student[i + 1].name;
			//student[i + 1].name = tempName;

		}

		//else if(student[i].schoolYear == student[i + 1].schoolYear){
		//	// ���� ���� 2: �г��� ������ �� ������ �������� �����ϱ�.
		//	if (student[i].grade < student[i + 1].grade) {
		//		int tempGrade;
		//		tempGrade = student[i].grade;
		//		student[i].grade = student[i + 1].grade;
		//		student[i + 1].grade = tempGrade;


		//	}else if(student[i].grade == student[i + 1].grade){
		//		// ���� ���� 3: ������ ������ �� �̸��� �������� �����ϱ�.
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








	// ���� ��� �� ����ϱ�.
	printf("\n��� : ");
	for (i = 0; i < personMax; i++) {
		if (i != 0) {
			printf("       ");
		}
		printf("%d %.2lf %s\n", student[i].schoolYear, student[i].grade, &student[i].name);
	}

	
	return 0;
}