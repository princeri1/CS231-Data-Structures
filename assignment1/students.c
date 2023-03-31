/*
 * This is the file in which you will implement the functionality required by
 * the assignment.  Make sure to add your name and @oregonstate.edu email
 * address below:
 *
 * Name: Riley Prince
 * Email: princeri@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include "students.h"

/*
 * This function should initialize a single student struct with name, ID, and
 * GPA data.
 *
 * Params:
 *   student - a pointer to the student struct to be initialized.  The memory
 *     for this student will already be allocated before the function is
 *     called.  You simply need to fill its values.  When the function returns,
 *     the fields of this student struct should contain the corresponding
 *     values passed in the other arguments.  Note that this function must
 *     allocate space for the name field and copy the value from name into the
 *     newly-allocated name field.  Make sure that if any of the fields of
 *     student already have memory on the heap allocated to them, you free that
 *     memory before overwriting it with new values.
 *   name - a string containing the student's name.  Note that you'll have to
 *     make a copy of this string to store in the student struct instead of
 *     storing this string directly.
 *   id - an integer ID for the student
 *   gpa - the student's GPA
 */
void init_student(struct student* student, char* name, int id, float gpa) {							//Initializes a new student struct
	student->name = malloc(sizeof(name));										//Finds the number of elements by dividing the bit size of "name" by the bit size of a character										//Allocates memory for Character vector
	for( int i = 0; name[i] != 0; i++)						//Copies the individual elements of the character vector to the new character vector
	{
		student->name[i] = name[i];
	}										// Copies float
											// Assigns the copy's values to the struct
	student->id = id;								// Assigns the copy's values to the struct
	student->gpa = gpa;								// Assigns the copy's values to the struct
}



/*
 * This function should free the memory allocated by init_student() for a
 * single student.
 *
 * Params:
 *   student - a pointer to the student whose memory should be freed.  Note
 *     that only memory stored *within* this struct should be freed.  The
 *     struct itself should not be freed.
 */
void free_student(struct student* student) {
	student->id = 0;
	free(student->name);
	student->name = NULL;
	student->gpa = 0;
}



/*
 * This function should make a deep copy of a single student.  A deep copy is
 * a copy where pointer fields don't simply have their values (i.e. the memory
 * addresses they point to) copied, but the pointers are dereferenced and
 * copies made of the values themselves.  In other words, for each pointer
 * field in the object being copied, new memory is allocated for a copy of that
 * field to be created, and a pointer to this newly-allocated memory is stored
 * in the copied object.
 *
 * Params:
 *   student - a pointer to the student to be deep copied
 *
 * Return:
 *   Should return a pointer to a deep copy of student.  Memory for this copy
 *   should be allocated by this function.  This memory will have to be freed
 *   using a combination of free_student() and free().
 */
struct student* deep_copy_student(struct student* student) {
	
	struct student * deepStudent = malloc(sizeof(struct student));
	deepStudent->id = student->id;
	deepStudent->gpa = student->gpa;
	char * string = malloc(sizeof(student->name));
	for(int i = 0; student->name[i] != 0; i++)
	{
		string[i] = student->name[i];
	}
	deepStudent->name = string;
	return deepStudent;
}


/*
 * This function should allocate space for an array of student structs and
 * initialize their fields using the provided information.  In particular, you
 * should create an array of student structs where the i'th student has the
 * i'th name, the i'th ID, and the i'th GPA from the arrays provided as
 * arguments.  You should use your init_student() function to perform the
 * initialization of each student in the new array.
 *
 * Params:
 *   num_students - the number of students to be stored in the newly allocated
 *     array
 *   names - an array of the names of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   ids - an array of the IDs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   gpas - an array of the GPAs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *
 * Return:
 *   Should return a pointer to the newly allocated and initialized array of
 *   student structs.  The i'th student in this array should have the i'th
 *   name, the i'th ID, and the i'th GPA from the arrays provided as arguments.
 */
struct student* create_student_array(int num_students, char** names, int* ids, float* gpas) {
	struct student * students = malloc( num_students * sizeof(struct student));
	for (int i = 0; i < num_students; i++)
	{
		init_student(&students[i], names[i], ids[i], gpas[i]);
	}
  return students;
}


/*
 * This function should free all of the memory allocated to an array of
 * student structs, including the memory allocated to the array itself as
 * well as any memory allocated within the individual student structs.  You
 * should use free_student() to free the memory for each individual student.
 *
 * Params:
 *   students - a pointer to the array of student structs whose memory is to
 *     be freed
 *   num_students - the number of students in the array
 */
void destroy_student_array(struct student* students, int num_students) {

}


/*
 * This function should print the name, ID, and GPA of each student in an
 * array, one student per line.
 *
 * Params:
 *   students - the array of students to be printed
 *   num_students - the number of students in the array
 */
void print_students(struct student* students, int num_students) {

	for (int i = 1; i <= num_students; i++)
	{
		printf("Name- %s, ", students[i].name);												// Print tag
		printf(" ID - %d, ", students[i].id);
		printf(" Gpa - %f \n", students[i].gpa);											// Print Id and Gpa
	}
}


/*
 * This function should return a pointer to the student in a given array with
 * the highest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the highest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the highest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_max_gpa(struct student* students, int num_students) {
	int locate;
	float maxGpa;
	float tempGpa;										// location variable to hold the value of the counter with the max gpa
	for (int i = 0; i < num_students; i++)							// This loop holds the value of the highest gpa seen 
	{											// This variable holds the highest gpa seen
		tempGpa = students[i].gpa;						// This grabs the gpa of the student in the struct at this point
		if (i == 0)									// Sets the first student's gpa as the max gpa
		{
			maxGpa = tempGpa;
			locate = i;											
		}
		if (tempGpa >=  maxGpa)								//Replaces the max gpa if this student's gpa is higher
		{
			maxGpa = tempGpa;
			locate = i;
		}
	}
	return &students[locate];								//returns address to the student pointer with max gpa
}


/*
 * This function should return a pointer to the student in a given array with
 * the lowest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the lowest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the lowest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_min_gpa(struct student* students, int num_students) {							// Find the size of the Student struct aray
	int locate;
	float minGpa;
	float tempGpa;
	for (int i = 0; i < num_students; i++)
	{
		tempGpa = students[i].gpa;
		if (i == 0)
		{
			minGpa = tempGpa;
			locate = i;
		}
		if (tempGpa <= minGpa)
		{
			minGpa = tempGpa;
			locate = i;
		}
	}
	return &students[locate];
}


/*
 * This function should sort students by descending GPA (i.e. highest GPAs
 * at the beginning of the array).  You may implement any sorting algorithm
 * you want, with the following constraints:
 *   - You must sort in place, i.e. you can't allocate additional memory.
 *   - You may not use built-in sorting functions like qsort(), i.e. you must
 *     implement the sort yourself.
 *
 * Params:
 *   students - the array of students to be sorted; when the function returns,
 *     this array will be sorted by descending GPA
 *   num_students - the number of students in the array
 */
void sort_by_gpa(struct student* students, int num_students) {
	for (int j = 0; j != 1;)													// This loop ensures the sort runs to completion
	{
		for (int i = 0; i < num_students; i++)									// This loop does the actual sorting
		{
			float sort1;				// Sort1 and sort2 are set equal to the two students whose gpa is being compared if student two's gpa is > student1
			float sort2;
			if (students[i].gpa < students[i+1].gpa)			// The gpa of student1 and student2 are compared 
			{
				sort2 = students[i].gpa;				// If student1's gpa is less than student2's the two are switched
				sort1 = students[i+1].gpa;				// This continues for every student in the students array
				students[i].gpa = sort1;
				students[i+1].gpa = sort2;
			}
		}
		for (int i = 0; i <= num_students; i++)					// This loop checks to see if the list array is fully sorted by gpa or not
		{
			if (i == num_students)				// If the list is sorted (makes it hrough all comparisons it breaks the loop allowing it to leave the function
			{
				j = 1;
				break;
			}
			else
			{
				if ( students[i].gpa < students[i+1].gpa )					// If not the loop continues
				{
					break;
				}
			}
		}
	}
}
