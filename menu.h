#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

#include "student.h"
#include "module.h"
#include "mark.h"


/*
 * Run the main menu of the application.
 * @param students - Pointer to an array of students.
 * @param student_count - Count of students.
 * @param modules - Pointer to a 2D array of modules.
 */
void menu_main_menu(Student *students, int student_count, Module **modules);

/*
 * Run the student submenu.
 * @param students - Pointer to an array of students.
 * @param student_count - Count of students.
 */
void menu_student_menu(Student *students, int student_count);

/*
 * Select a specific student.
 * @param students - Pointer to an array of students.
 * @param student_count - Count of students.
 */
Student menu_select_student(Student *students, int student_count);

/*
 * Run the module submenu.
 * @param students - Pointer to an array of students.
 * @param student_count - Count of students.
 * @param modules - Pointer to a 2D array of modules.
 */
void menu_module_menu(Student *students, int student_count, Module **modules);

/*
 * Select a specific module.
 * @param student_count - Count of students.
 * @param modules - Pointer to a 2D array of modules.
 */
Module menu_select_module(Module **modules);


#endif
