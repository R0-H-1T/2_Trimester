#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char *arr;
    unsigned int capacity;
    int size;
    char top;
} Stack;

int getLength(char *word) {
    int counter = 0;
    while(*word != '\0') {
        counter++;
        word++;
    }
    return counter;
}

int is_alpha(char ch) {
    if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)) {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/') 
        return 2;
    else if (ch == '^')
        return 3;
    return -1;
}

void convert_infix_to_postfix(char *infix_expression) {
    Stack s;
    int len = getLength(infix_expression);
    char *res = s.arr = (char) malloc (sizeof(char) * len);
    s.capacity = len;
    
    for(int i=0; i<len; i++) {
        if(!is_alpha(*infix_expression) && precedence == -1) {
            fprintf(stderr, "An invalid key was found in the expression");
            exit(EXIT_FAILURE);
        }
        if(is_alpha(*infix_expression)) {
            res[i] = *infix_expression;
        }
        if(precedence(*infix_expression) >= precedence(s.top)) {
            s.arr[i] = *infix_expression;
            s.size++;
            s.top = *infix_expression;
        }else{
            int j = i;

            while((s.size != -1) || (precedence(s.top) > precedence(*infix_expression))) {
                res[i] = s.arr[j--];
                s.top = s.arr[j];
                s.size--;
            }
        }z
    }
    for(int i=s.size; i<s.size; i--){
        res[i] = s.arr[s.size];
        s.size--;

    }
}

int main() {
    char infix_expression[64];
    printf("Enter infix expression");
    scanf("%s", infix_expression);
    getchar();

    convert_infix_to_postfix(infix_expression);

    return 0;
}
