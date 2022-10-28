#include "student.h"
#include "module.h"
#include "menu.h"


int main()
{
	Student *students;
	int student_count;
	Module **modules;

	students = student_generate_students();
	student_count = student_get_count(students);
	modules = module_generate_modules();

	menu_main_menu(students, student_count, modules);

	return 0;
}
