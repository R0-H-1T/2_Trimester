#ifndef STUDENTDB 
#define STUDENTDB

#define N_SIZE 20
#define C_SIZE 10

typedef struct student_DB{
    unsigned int rollno;
    char name[N_SIZE];
    char classs[C_SIZE]; // class is predefined specifier so classs
    unsigned short int marks[3];
}student_DB;

student_DB* initStudents(student_DB *, int );
void getStudents(student_DB *, int );
void displayStudents(student_DB *, int );
void displayStudentAtPosition(student_DB *, int );
int modifyStudent(student_DB *, int );
int findStudent(student_DB *, int , char* , int );
int searchStudent(student_DB *, int );


#endif
