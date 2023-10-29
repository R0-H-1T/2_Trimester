#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

void displayStr(char *str){
    while(*str != 0){
        printf("%c", *str);
        str ++;
    }   
}

int length(char *str){
    int count = 0;
    while(*str != '\0'){
        count ++; str ++;
    }
    return count;
}

char* reverseStr(char *str){
    int start = 0, end = length(str)-1;

    char *rev = str;
    while(start <= end){
        char temp = rev[start];
        rev[start] = rev[end];
        rev[end] = temp;
        start ++; end --;
    }
    return rev;
}

void copyStr(char *str, char *copystr){
    copystr = str;
}

int charPresent(char *str, char ch){
    while(*str != '\0'){
        if ( *str == ch){
            return 1;
        }
        str++;
    }
    return 0;
}

int noOfTimesRepeated(char *str, char ch){
    int count = 0;
    if (!charPresent(str, ch)){
        return 0;
    }
    while( *str != '\0'){
            if ( *str == ch){
                count ++;
            }   
            str ++;
    }
    return count;
}

int main(){
    char str[SIZE];
    char *str_ptr, *copy_str;

    printf("Enter a string: ");
    fgets(str, SIZE, stdin);
    str_ptr = (char*)str;

    return 0;
}