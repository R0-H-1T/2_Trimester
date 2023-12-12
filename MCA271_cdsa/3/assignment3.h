#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);
void displayInfixToPostfix(char* infix);

#endif
