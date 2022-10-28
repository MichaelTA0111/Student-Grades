#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "student.h"
#include "mark.h"

#define MAX_LINE_LENGTH 300


void mark_set_module_code(Mark *mark, char *module_code, int size)
{
	mark->module_code = (char*) calloc(size, sizeof(char));
	strcpy(mark->module_code, module_code);
}

void mark_set_percentage(Mark *mark, int percentage)
{
	mark->percentage = percentage;
}

void mark_print_details(Mark *mark)
{
	printf("Module %s percentage %d.\n", mark->module_code, mark->percentage);
}

Mark *mark_generate_marks(int student_id, int student_year)
{
	FILE *mark_file;
	char line[MAX_LINE_LENGTH];
	const char delimiter[2] = ",";
	char *contents;
	int len;
	char buffer_size = 50;
	const int modules_per_year = 7;
	bool found = false;
	Mark *marks = calloc(student_year * modules_per_year, sizeof(Mark));

	mark_file = fopen("marks.txt", "r");

	if (mark_file == NULL) {
		printf("Error opening marks.txt\n");
		return marks;
	}

	while (fgets(line, MAX_LINE_LENGTH, mark_file)) {
		// Remove the newline character
		len = strlen(line);
		if (line[len - 1] == '\n' )
			line[len - 1] = 0;

		// Check to see if the student ID matches
		contents = strtok(line, delimiter);
		if (atoi(contents) != student_id)
			continue;

		found = true;
		for (int i = 0; i < modules_per_year * student_year; i++) {
			contents = strtok(NULL, delimiter);
			mark_set_module_code(&marks[i], contents, buffer_size);
			contents = strtok(NULL, delimiter);
			mark_set_percentage(&marks[i], atoi(contents));
		}
	}

	fclose(mark_file);

	if (!found)
		printf("Marks for student %d not found\n", student_id);

	return marks;
}
