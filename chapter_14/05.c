#include <stdio.h>
#define CSIZE 4

// a.
struct name {
	char first[30];
	char last[30];
};

// b.
struct student {
	struct name name;
	float grade[3];
	float average_grade;
};

void prompt_grades(int nb_students, struct student *);
void set_average_grades(int nb_students, struct student *);
void print_infos(int nb_students, struct student [nb_students]);
void print_average(int nb_students, struct student [nb_students]);

int main(void)
{
	// c.
	struct student class[CSIZE] = {
		{{"Clara", "Conzo"}},
		{{"Lucas", "Lonzo"}},
		{{"Tommy", "Tonzo"}},
		{{"Simon", "Sonzo"}}
	};
	prompt_grades(CSIZE, class);
	set_average_grades(CSIZE, class);
	print_infos(CSIZE, class);
	print_average(CSIZE, class);
	return 0;
}

// d.
void prompt_grades(int nb_students, struct student * student)
{
	for (int i = 0; i < nb_students; ++i) {
		printf("Enter the three grades of %s %s: ",
				student[i].name.first,
				student[i].name.last);
		for (int j = 0; j < 3; ++j)
			scanf("%f", student[i].grade + j);
	}
}

// e.
void set_average_grades(int nb_students, struct student * student)
{
	for (int i = 0; i < nb_students; ++i) {
		float sum = 0;
		for (int j = 0; j < nb_students; ++j)
			sum += student[i].grade[j];
		student[i].average_grade = sum / 3;
	}
}

// f.
void print_infos(int nb_students, struct student student[nb_students])
{
	for (int i = 0; i < nb_students; ++i)
		printf("%s %s --- grades: %.2f %.2f %.2f --- average: %.2f\n",
				student[i].name.first,
				student[i].name.last,
				student[i].grade[0],
				student[i].grade[1],
				student[i].grade[2],
				student[i].average_grade);
}

// g.
void print_average(int nb_students, struct student student[nb_students])
{
	float sum_grade1 = 0;
	float sum_grade2 = 0;
	float sum_grade3 = 0;
	float sum_average_grade = 0;
	for (int i = 0; i < nb_students; ++i) {
		sum_grade1 += student[i].grade[0];
		sum_grade2 += student[i].grade[1];
		sum_grade3 += student[i].grade[2];
		sum_average_grade += student[i].average_grade;
	}
	printf("Average of the first grade: %.2f\n", sum_grade1 / nb_students);
	printf("Average of the second grade: %.2f\n", sum_grade2 / nb_students);
	printf("Average of the third grade: %.2f\n", sum_grade3 / nb_students);
	printf("Average of all grades: %.2f\n", sum_average_grade / nb_students);
}
