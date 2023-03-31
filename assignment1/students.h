
 /* 
 This structure represents information about a single university student.
 */
struct student {
  char* name;
  int id;
  float gpa;
};


/*
 * Function prototypes.
 */
void init_student(struct student* student, char* name, int id, float gpa);
void free_student(struct student* student);
struct student* deep_copy_student(struct student* student);
struct student* create_student_array(int num_students, char** names, int* ids,
    float* gpas);
void destroy_student_array(struct student* students, int num_students);
void print_students(struct student* students, int num_students);
struct student* find_max_gpa(struct student* students, int num_students);
struct student* find_min_gpa(struct student* students, int num_students);
void sort_by_gpa(struct student* students, int num_students);
