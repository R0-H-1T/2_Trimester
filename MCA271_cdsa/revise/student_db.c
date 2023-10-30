#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student_db.h"

void getStudents(student_DB *ptr, int n){
    for(int i=0; i<n; i++){
        printf("\nStudent %d", i+1);

        printf("\nRoll no: ");
        scanf("%u", &ptr[i].rollno);
        getchar(); // clears the input buffer because newline is entered into input buffer
                   // when u hit Enter Key. fflush(stdin)
        printf("Name: ");
        fgets(ptr[i].name, N_SIZE, stdin);

        printf("Class: "); 
        fgets(ptr[i].classs, C_SIZE, stdin);

        printf("Marks in 3 subjects: ");
        scanf("%hu %hu %hu", &ptr[i].marks[0], &ptr[i].marks[2], &ptr[i].marks[3]);
    }
}

void displayStudents(student_DB *ptr, int n){
    printf("----------------------------");
    for(int i=0; i<n; i++){
        printf("\n\nStudent #%d\n", i+1);

        printf("Roll: %d\nName: %sClass: %sMarks: %d %d %d",
            ptr[i].rollno,
            ptr[i].name,
            ptr[i].classs,
            ptr[i].marks[0], ptr[i].marks[1], ptr[i].marks[2]
        );
    }
}

void displayStudentAtPosition(student_DB *ptr, int pos){
    if( pos == -1){
        printf("\nNo student found");
    }else {
        printf("\n----------------------------");
        printf("\nStudent #%d\n", pos+1);
        printf("Roll: %d\nName: %sClass: %sMarks: %d %d %d",
            ptr[pos].rollno,
            ptr[pos].name,
            ptr[pos].classs,
            ptr[pos].marks[0], ptr[pos].marks[1], ptr[pos].marks[2]
        );
    }
}

int modifyStudent(student_DB *ptr, int n){
    unsigned int search_roll;
    printf("\n\nEnter roll no of student for updation: ");
    scanf("%u",&search_roll);
    int pos = findStudent(ptr, n, (char*)NULL, search_roll);
    if( pos == -1){
        printf("\nStudent not found for roll no : %d", pos);
        return -1;
    }
    int ch;
    printf("\nUpdate:\n1. Rollno\n2. Name\n3. Class\n4. Marks\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            unsigned int roll; 
            printf("\nEnter rollno: ");
            scanf("%u", &roll);
            ptr[pos].rollno = roll;
            break;
        case 2:
            getchar();
            printf("\nEnter name: ");
            fgets(ptr[pos].name, N_SIZE, stdin);
            break;
        case 3:
            getchar();
            printf("\nEnter class: ");
            fgets(ptr[pos].classs, C_SIZE, stdin);
            break;
        case 4:
            printf("\nEnter marks: ");
            scanf("%hu %hu %hu", &ptr[pos].marks[0], &ptr[pos].marks[1], &ptr[pos].marks[2]);
            break;
        default:
            printf("\nInvalid choice.\nTry Again\n\n");
    }
    return pos;
}

int findStudent(student_DB *ptr, int n, char* searchName, int rollno){
    // * NOTE *
    // Do not check strings using ==.
    // This checks if two pointers are pointing to the same memory locatio.
    // Instead use strcmp
    if (rollno == -1){
        for(int i=0; i<n; i++){
            if ( strcmp( (char*)ptr[i].name, searchName ) == 0){
                // printf("TEST PASSED");
                return i;
            }
        }
    }else{
        for(int i=0; i<n; i++){
            if ( ptr[i].rollno == rollno ){
                return i;
            }
        }
    }
    return -1;
}

int searchStudent(student_DB *ptr, int n){
    char ch;
    int pos;
    printf("\nSearch by name or rollno (n/r): ");
    getchar();
    scanf("%c", &ch);
    if ( ch == 'n'){
        char searchName[N_SIZE];
        getchar(); // clear input buffer
        printf("\nEnter name: ");
        fgets(searchName, N_SIZE, stdin);
        pos = findStudent(ptr, n, (char *)searchName, -1);
    }else if ( ch == 'r'){
        int roll;
        printf("\nEnter roll number: ");
        scanf("%d", &roll);
        pos = findStudent(ptr, n, (char*)NULL, roll);
    }else {
        printf("Invalid input");
    }
    return pos;
}

student_DB* initStudents(student_DB *ptr, int n){
    student_DB *s = (student_DB*)malloc(n * sizeof(student_DB));
    return s;
}

// TESTING ---------------------------------------------------------
// int main(){
//     int n;
//     printf("Enter total students: ");
//     scanf("%d", &n);
//     student_DB *s;
//     s = initStudents(s, n);
//     getStudents(s, n);
//     displayStudents(s, n);
//     free(s);
//     return 0;
// }



// to do -> nothing

