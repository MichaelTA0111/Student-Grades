#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "student.h"
#include "module.h"
#include "mark.h"
#include "menu.h"

#define MODULES_PER_YEAR 7
#define TOTAL_YEARS 4


bool menu_continue(char *msg)
{
	char input[5];

	printf("%s", msg);
	while (true) {
		scanf("%4s", input);

		if (tolower((char) *input) == (char) *"yes")
			return true;
		else if (tolower((char) *input) == (char) *"no")
			return false;
		else
			printf("Invalid menu option! Please try again\n");
	}
}

void menu_main_menu(Student *students, int student_count, Module **modules)
{
	char menu_option;
	bool menu;

	menu = true;
	while (menu) {
		printf("What would you like to do?\n1: View student details\n2: View module details\n");
		scanf(" %c", &menu_option);

		switch (menu_option) {
		case '1':
			menu_student_menu(students, student_count);
			menu = menu_continue("Do you want to do anything else? (yes/no)\n");
			break;
		case '2':
			menu_module_menu(students, student_count, modules);
			menu = menu_continue("Do you want to do anything else? (yes/no)\n");
			break;
		default:
			printf("Invalid menu option! Please try again\n");
			break;
		}
	}
}

void menu_student_menu(Student *students, int student_count)
{
	Student student;
	char menu_option;
	bool menu = true;

	student = menu_select_student(students, student_count);

	while (menu) {
		printf("What would you like to view?\n1: General information\n2: Statistics\n3: All marks\n");
		scanf(" %c", &menu_option);

		switch (menu_option) {
		case '1':
			student_print_details(&student);
			menu = menu_continue("Do you want to view anything else for this student? (yes/no)\n");
			break;
		case '2':
			student_print_statistics(&student);
			menu = menu_continue("Do you want to view anything else for this student? (yes/no)\n");
			break;
		case '3':
			student_print_marks(&student);
			menu = menu_continue("Do you want to view anything else for this student? (yes/no)\n");
			break;
		default:
			printf("Invalid menu option! Please try again\n");
			break;
		}
	}
}

Student menu_select_student(Student *students, int student_count)
{
	int student_id;
	
	printf("Please enter a student ID\n");
	while (true) {
		scanf("%d", &student_id);
		
		for (int i = 0; i < student_count; i++) {
			if (students[i].id == student_id)
				return students[i];
		}

		printf("No student with ID %d found! Please try again\n", student_id);
	}
}

void menu_module_menu(Student *students, int student_count, Module **modules)
{
	Module module;
	char menu_option;
	bool menu = true;

	module = menu_select_module(modules);

	while (menu) {
		printf("What would you like to view?\n1: General information\n2: Statistics\n");
		scanf(" %c", &menu_option);

		switch (menu_option) {
		case '1':
			module_print_details(&module);
			menu = menu_continue("Do you want to view anything else for this module? (yes/no)\n");
			break;
		case '2':
			module_print_statistics(students, student_count, &module);
			menu = menu_continue("Do you want to view anything else for this module? (yes/no)\n");
			break;
		default:
			printf("Invalid menu option! Please try again\n");
			break;
		}
	}
}

Module menu_select_module(Module **modules)
{
	char module_code[6];
	
	printf("Please enter a 5-character module code\n");
	while (true) {
		scanf("%5s", module_code);

		for (int i = 0; i < TOTAL_YEARS; i++) {
			for (int j = 0; j < MODULES_PER_YEAR; j++) {
				if (strcmp(modules[i][j].code, module_code) == 0) {
					return modules[i][j];
				}
			}
		}

		printf("No module with code %s found! Please try again\n", module_code);
	}
}
