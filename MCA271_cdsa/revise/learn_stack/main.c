#include<stdio.h>
#include"arr_stack.h"



void display_stack(Stack *s) {
    if(!is_empty(s)) {
        printf("\nDisplaying elems in stack: ");
        for(int i=0; i<stack_size(s); i++) {
            printf("%d ", s->arr[i]);
        }
    }
}


int main(){
    Stack s;
    init_stack(&s, 3);
    // printf("%s", (is_empty(&s)) ? "Yes" : "No");
    // printf("%s", is_full(&s) ? "Yes" : "No");
    pop(&s);
    display_stack(&s);
    
    push(&s, -2);
    push(&s, -90);
    push(&s, -8);
    push(&s, 45);
    display_stack(&s);
    printf("\nPeek %d", peek(&s));
    pop(&s);
    printf("\nPeek %d", peek(&s));
    pop(&s);
    printf("\nPeek %d", peek(&s));
    pop(&s);

    return 0;
}
