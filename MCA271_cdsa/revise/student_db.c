#include<stdio.h>
#include<stdlib.h>
#define N_SIZE 20
#define C_SIZE 20

typedef struct studentDB{
    unsigned int rollno;
    char name[N_SIZE];
    char class[C_SIZE];
    unsigned short int marks[3];
}stu_DB;


void get_students(stu_DB *s, unsigned short int n){
    for(int i=0; i<n; i++){
        scanf("%u", s->rollno);
        fgets(s->name, N_SIZE, stdin);
        fgets(s->class, C_SIZE, stdin);
        for(int i=0; i<3; i++){
            printf("Marks: %d", i+1);
            scanf("%d", &s->marks[i]);
        }
    }
}


int main(){
    stu_DB *s;
    int selection;

    printf( "\nEnter choice:"
            "\n1. Enter Students."
            "\n2. Update student."
            "\n3. Display Students."
            "\n4. Search student.\n"
            "5. Exit\n"
    );
    
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        short unsigned int n;
        printf("\nHow many students?: ");
        scanf("%hu", &n);
        s = malloc(n * sizeof(stu_DB));
        get_students(s, n);
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    default:
        printf("Wrong Choice entered");
        break;
    }

    return 0;

}



// to do

