#ifndef STUDENT_H
#define STUDENT_H

#include "mark.h"


/*
 * Structure to store the student information.
 */
typedef struct Student {
	int id;
	char *name;
	int year;
	Mark *marks;
} Student;

/*
 * Sets the ID of the student.
 * @param student - Pointer to the Student struct.
 * @param id - The student ID.
 */
void student_set_id(Student *student, int id);

/*
 * Sets the name of the student.
 * @param student - Pointer to the Student struct.
 * @param name - A char array containing the new name of the student.
 * @param size - The size of the title char array as an integer.
 */
void student_set_name(Student *student, char *name, int size);

/*
 * Sets the year of the student.
 * @param student - Pointer to the Student struct.
 * @param year - The year which the student has most recently completed.
 */
void student_set_year(Student *student, int year);

/*
 * Sets the module marks for the student.
 * @param student - Pointer to the Student struct.
 */
void student_generate_marks(Student *student);

/*
 * Print student details.
 * @param student - Pointer to the Student struct.
 */
void student_print_details(Student *student);

/*
 * Print student statistics.
 * @param student - Pointer to the Student struct.
 */
void student_print_statistics(Student *student);

/*
 * Print student marks.
 * @param student - Pointer to the Student struct.
 */
void student_print_marks(Student *student);

/*
 * Generate all of the students for the application.
 */
Student *student_generate_students();

/*
 * Get the total count of students in a list of students.
 * @param students - Pointer to an array of students.
 */
int student_get_count(Student *students);


#endif
