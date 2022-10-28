#ifndef MODULE_H
#define MODULE_H

#include "student.h"


/*
 * Structure to store the module information.
 */
typedef struct Module {
	char *code;
	char *title;
	int year;
} Module;


/*
 * Sets the code of the module.
 * @param module - Pointer to the Module struct.
 * @param code - A char array containing the new code of the module.
 * @param size - The size of the code char array as an integer.
 */
void module_set_code(Module *module, char *code, int size);

/*
 * Sets the title of the module.
 * @param module - Pointer to the Module struct.
 * @param code - A char array containing the new title of the module.
 * @param size - The size of the title char array as an integer.
 */
void module_set_title(Module *module, char *title, int size);

/*
 * Sets the year of the module.
 * @param module - Pointer to the Module struct.
 * @param year - The year in which the module takes place as an integer.
 */
void module_set_year(Module *module, int year);

/*
 * Print module details.
 * @param module - Pointer to the Module struct.
 */
void module_print_details(Module *module);

/*
 * Print module statistics.
 * @param students - Pointer to an array of students.
 * @param student_count - Count of students.
 * @param module - Pointer to the Module struct.
 */
void module_print_statistics(Student *students, int student_count, Module *module);

/*
 * Generate all of the modules for the application.
 */
Module **module_generate_modules();


#endif
