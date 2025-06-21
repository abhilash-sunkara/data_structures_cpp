#include <stdio.h>

#define STACKSIZE 100

struct array_item{
    int* items;
    int length;
};

struct stack{
    int top = -1;
    struct array_item items[STACKSIZE];
};

void push(struct stack* ps, int x[], int len){
    struct array_item temp = {
        x, len
    };
    ps->items[++(ps->top)] = temp;
}

void peek(struct stack* ps){
    for(int i = 0; i < ps->items[ps->top].length; i++){
        printf("%d, ", ps->items[ps->top].items[i]);
    }
    printf("\n");
}

array_item* pop(struct stack* ps){
    return &(ps->items[(ps->top)--]);
}

int main(){
    struct stack ps;
    int x[] = {1, 2, 3, 4};
    int y[] = {1, 2, 3, 4, 5, 6, 7, 8};
    push(&ps, x, 4);
    push(&ps, y, 8);
    peek(&ps);
    pop(&ps);
    peek(&ps);
    printf("Finished running");
}