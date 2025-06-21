#include <stdio.h>
#include <cstdlib>

#define STACKSIZE 100

struct double_stack{
    int top = -1;
    int bottom = STACKSIZE;
    int items[STACKSIZE];
};

void set_top(struct double_stack* ps, int x){
    ps->top = x;
}

void push_top(struct double_stack* ps, int x){
    if(ps->top < ps->bottom){
        ps->items[++(ps->top)] = x;
    } else {
        exit(1);
    }
}

void push_bottom(struct double_stack* ps, int x){
    if(ps->bottom > ps->top){
        ps->items[--(ps->bottom)] = x;
    } else {
        exit(1);
    }
}

int pop_top(struct double_stack* ps){
    if(ps->top > -1){
        return ps->items[(ps->top)--];
    } else {
        exit(1);
    }
}

int pop_bottom(struct double_stack* ps){
    if(ps->bottom < STACKSIZE){
        return ps->items[(ps->bottom)++];
    } else {
        exit(1);
    }
}

int peek_top(struct double_stack* ps){
    if(ps->top > -1){
        return ps->items[(ps->top)];
    } else {
        exit(1);
    }
}

int peek_bottom(struct double_stack* ps){
    if(ps->bottom < STACKSIZE){
        return ps->items[(ps->bottom)];
    } else {
        exit(1);
    }
}

int main(){
    struct double_stack ds;

    for(int i = 0; i < 15; i++){
        push_top(&ds, 8);
        push_bottom(&ds, 7);
    }
    
    printf("Finished running\n");
}
