#include <cstdlib>
#include <stdio.h>

#define STACKSIZE 101
struct stack {
    int top = -1;
    int items[STACKSIZE];
};

int empty(struct stack* ps){
    if(ps->top == -1){
        return 1;
    }
    return 0;
}

int pop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    }
    return(ps->items[ps->top--]);
}
    
void push(struct stack* ps, int x){
    if(ps->top == STACKSIZE - 1){
        exit(1);
    } else {
        ps->items[++(ps->top)] = x;
    }
}

int stacktop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    } else {
        return ps->items[ps->top];
    }
}

int main(){
    struct stack s;
    push(&s, 8);
    push(&s, 9);
    push(&s, 12);

    printf("%d\n", pop(&s));
    push(&s, 13);
    printf("%d\n", pop(&s));
    printf("%d\n", stacktop(&s));
    
}