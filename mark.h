#ifndef MARK_H
#define MARK_H

#include "student.h"


/*
 * Structure to store marks for a module.
 */
typedef struct Mark {
	char *module_code;
	int percentage;
} Mark;

/*
 * Sets the code of the module.
 * @param mark - Pointer to the Mark struct.
 * @param module_code - A char array containing the code of the module.
 * @param size - The size of the module_code char array as an integer.
 */
void mark_set_module_code(Mark *mark, char *module_code, int size);

/*
 * Sets the percentage achieved for the module.
 * @param mark - Pointer to the Mark struct.
 * @param percentage - The percentage received for that module.
 */
void mark_set_percentage(Mark *mark, int percentage);

/*
 * Debug feature to print marks.
 * @param mark - Pointer to the Mark struct.
 */
void mark_print_details(Mark *mark);

/*
 * Generate all of the marks for a student.
 * @param student_id - The student ID.
 * @param student_year - The student year.
*/
Mark *mark_generate_marks(int student_id, int student_year);


#endif
