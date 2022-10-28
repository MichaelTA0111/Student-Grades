#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "student.h"
#include "mark.h"

#define MAX_LINE_LENGTH 200
#define MAX_STUDENTS 100
#define MODULES_PER_YEAR 7


void student_set_id(Student *student, int id)
{
	student->id = id;
}

void student_set_name(Student *student, char *name, int size)
{
	student->name = (char*) calloc(size, sizeof(char));
	strcpy(student->name, name);
}

void student_set_year(Student *student, int year)
{
	student->year = year;
}

void student_generate_marks(Student *student)
{
	Mark *marks = mark_generate_marks(student->id, student->year);
	student->marks = marks;
}

void student_print_details(Student *student)
{
	printf("Student %d - %s, year %d.\n", student->id, student->name, student->year);
}

void student_print_statistics(Student *student)
{
	Mark *mark;
	int pct;
	int min = 100, max = 0, sum = 0, range;
	float average, module_count;
	
	module_count = student->year * MODULES_PER_YEAR;

	for (int i = 0; i < module_count; i++) {
		mark = &student->marks[i];
		pct = mark->percentage;
		
		min = (pct < min) ? pct : min;
		max = (pct > max) ? pct : max;
		sum += pct;
	}
	range = max - min;
	average = sum / module_count;

	printf("Average: %.2f\n", average);
	printf("Maximum: %d\n", max);
	printf("Minimum: %d\n", min);
	printf("Range: %d\n", range);
}

void student_print_marks(Student *student)
{
	for (int i = 0; i < student->year * MODULES_PER_YEAR; i++) {
		mark_print_details(&student->marks[i]);
	}
}

Student *student_generate_students()
{
	FILE *student_file;
	char line[MAX_LINE_LENGTH];
	Student *students = calloc(MAX_STUDENTS, sizeof(Student));
	const char delimiter[2] = ",";
	char *contents;
	int i = 0;
	int len;
	const int buffer_size = 50;

	student_file = fopen("students.txt", "r");

	if (student_file == NULL) {
		printf("Error opening students.txt\n");
		return students;
	}

	while (fgets(line, MAX_LINE_LENGTH, student_file)) {
		// Check the maximum students are not yet reached
		if (i == MAX_STUDENTS) {
			printf("Maximum students reached");
			break; 
		}
		
		// Remove the newline character
		len = strlen(line);
		if (line[len - 1] == '\n' )
			line[len - 1] = 0;

		// Create student
		contents = strtok(line, delimiter);
		student_set_id(&students[i], atoi(contents));
		contents = strtok(NULL, delimiter);
		student_set_name(&students[i], contents, buffer_size);
		contents = strtok(NULL, delimiter);
		student_set_year(&students[i], atoi(contents));
		
		// Generate marks
		student_generate_marks(&students[i]);

		// Increment the counter
		i++;
	}

	fclose(student_file);

	return students;
}

int student_get_count(Student *students)
{
	for (int i = 0; i < MAX_STUDENTS; i++) {
		if (!students[i].id)
			return i;
	}

	return MAX_STUDENTS;
}
