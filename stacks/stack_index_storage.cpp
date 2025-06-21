#include <cstdlib>
#include <stdio.h>

#define STACKSIZE 101

struct stack {
    int items[STACKSIZE + 1];
};

void initialize(struct stack* ps){
    ps->items[0] = 0;
}

int empty(struct stack* ps){
    if(ps->items[0] == 0){
        return 1;
    }
    return 0;
}

int pop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    }
    return ps->items[(ps->items[0])--];
}

void push(struct stack* ps, int x){
    if(ps->items[ps->items[0]] == STACKSIZE - 1){
        exit(1);
    }
    ps->items[++(ps->items[0])] = x;
}

int stacktop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    }
    return ps->items[(ps->items[0])];
}

int main(){
    struct stack ps;
    initialize(&ps);

    push(&ps, 5);
    push(&ps, 6);
    push(&ps, 7);
    push(&ps, 8);

    printf("%d\n", stacktop(&ps));

    pop(&ps);
    pop(&ps);
    printf("%d\n", stacktop(&ps));
}

