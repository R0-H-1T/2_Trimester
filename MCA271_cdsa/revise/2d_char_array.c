#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

int length(char *str){
    int count = 0;
    while(*str != '\0'){
        count ++; str ++;
    }
    return count;
}

void getNames(char *names[], int n){

    for(int i=0; i<n; i++){
        char name[SIZE];
        fgets(name, SIZE, stdin);

        int len = length((char *)name);
        printf("%d: %ld\n\n", len,strlen(name));

        // names[i] = name;
        fflush(stdin);
    }
    // printf("\n");
    // for(int i=0; i<n; i++){
    //     printf("%s ", names[i]);
    // }
}


// void displayNames(char **names, int n){
//     printf("Displaying names: ");
//     for(int i=0; i<n; i++){
//         printf("%s\n", *(names+i));
//     }
// }


int main(){
    int n;
    printf("Enter total names: ");
    scanf("%d", &n);
    fflush(stdin);
    
    char *names[n];

    getNames(names, n);
    // displayNames(names, n);


}