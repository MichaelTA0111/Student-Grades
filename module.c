#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "student.h"
#include "mark.h"
#include "module.h"

#define MAX_LINE_LENGTH 1000
#define MODULES_PER_YEAR 7
#define TOTAL_YEARS 4


void module_set_code(Module *module, char *code, int size)
{
	module->code = (char*) calloc(size, sizeof(char));
	strcpy(module->code, code);
}

void module_set_title(Module *module, char *title, int size)
{
	module->title = (char*) calloc(size, sizeof(char));
	strcpy(module->title, title);
}

void module_set_year(Module *module, int year)
{
	module->year = year;
}

void module_print_details(Module *module)
{
	printf("Year %d module %s - %s.\n", module->year, module->code, module->title);
}

void module_print_statistics(Student *students, int student_count, Module *module)
{
	Student *student;
	Mark *mark;
	int pct;
	int min = 100, max = 0, sum = 0, range, mark_count = 0;
	float average;

	for (int i = 0; i < student_count; i++) {
		student = &students[i];

		if (student->year < module->year)
			continue;

		mark = &student->marks[i];
		pct = mark->percentage;
		
		min = (pct < min) ? pct : min;
		max = (pct > max) ? pct : max;
		sum += pct;
		mark_count++;
	}
	range = max - min;
	average = sum / (float) mark_count;

	printf("Total results: %d\n", mark_count);
	printf("Average: %.2f\n", average);
	printf("Maximum: %d\n", max);
	printf("Minimum: %d\n", min);
	printf("Range: %d\n", range);
}

Module **module_generate_modules()
{
	FILE *module_file;
	char line[MAX_LINE_LENGTH];
	Module *yearly_modules = calloc(TOTAL_YEARS * MODULES_PER_YEAR, sizeof(Module));
	Module **modules = malloc(TOTAL_YEARS * sizeof(Module*));
	const char delimiter[2] = ",";
	char *contents;
	int i = 0;
	int len;
	const int buffer_size = 50;
	int year;

	for (int j = 0; j < TOTAL_YEARS; j++) {
		modules[j] = yearly_modules + j * MODULES_PER_YEAR;
	}

	module_file = fopen("modules.txt", "r");

	if (module_file == NULL) {
		printf("Error opening modules.txt\n");
		return modules;
	}

	while (fgets(line, MAX_LINE_LENGTH, module_file)) {
		// Remove the newline character
		len = strlen(line);
		if (line[len - 1] == '\n' )
			line[len - 1] = 0;

		// Create modules
		contents = strtok(line, delimiter);
		year = atoi(contents);
		for (int j = 0; j < MODULES_PER_YEAR; j++) {
			module_set_year(&modules[i][j], year);
			contents = strtok(NULL, delimiter);
			module_set_code(&modules[i][j], contents, buffer_size);
			contents = strtok(NULL, delimiter);
			module_set_title(&modules[i][j], contents, buffer_size);
		}

		// Increment the counter
		i++;
	}

	fclose(module_file);

	return modules;
}
