This progrem creates a list of students with their modules and calculates mean, max, min, and range of grades of the student and module.

Students are read in from a file called `students.txt`.
Modules are read in from a file called `modules.txt`.
Student marks are read in from a file called `marks.txt`.

There are inputs to determine what calculations to make.
Inputs are validated and errors are handled accordingly.

There is a Student struct containing:
	- ID
	- Name
	- Year
	- Linked list of marks

There is a Module struct containing:
	- Code
	- Title
	- Year

There is a Mark struct containing:
	- Module Code
	- Percentage
