#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "assignment3.h"


int main() {
    char infixExpression[100];
    printf("Enter the infix expression: ");
    scanf("%s", infixExpression);

    displayInfixToPostfix(infixExpression);

    char postfixExpression[100];
    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}


void displayInfixToPostfix(char* infix) {
    char postfixExpression[100];
    infixToPostfix(infix, postfixExpression);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfixExpression);
}

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element %d.\n", item);
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top];
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Pop '('
            i++;
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i = 0;

    while (postfix[i] != '\0') {
        if (isOperand(postfix[i])) {
            push(stack, postfix[i] - '0'); 
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }

        i++;
    }

    //return pop(stack);
    return pop(stack);
}
