#include <stdio.h>
#define MAX_SIZE 100

//typedef string_stack {
//    char stack[MAX_SIZE];
//}string_stack;
//



//void enter_to_stack(char *s) {
//    while(*s != '\0'){
//                        
//        s++;
//    }
//}
//
int main(){
    char user_str[MAX_SIZE];
    char *str;
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    
//    enter_to_stack(user_str);

    printf("%s", user_str);
    return 0;
}
