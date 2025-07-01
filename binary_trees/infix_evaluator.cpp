#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#define OPERATOR 0
#define OPERAND 1

struct treenode {
    int utype;
    union{
        char operators[10];
        float val;
    } info;
    struct treenode* son;
    struct treenode* next;
};
typedef treenode* NODEPTR;

float apply(NODEPTR p){
    switch (p->info.operators[0]) {
        case '+' : 
            return p->son->info.val + p->son->next->info.val;
        case '-':
            return p->son->info.val - p->son->next->info.val;
        case '*':
            return p->son->info.val * p->son->next->info.val;
        case '/':
            return p->son->info.val / p->son->next->info.val;
        default:
            return 0.0;
    }
}

void replace(NODEPTR p){
    float value;
    NODEPTR q, r;
    if(p->utype == OPERATOR){
        q = p->son;
        while(q != NULL){
            replace(q);
            q = q->next;
        }
        value = apply(p);
        p->utype = OPERAND;
        p->info.val = value;
        q = p->son;
        p->son = NULL;
        while(q != NULL) {
            r = q;
            q = q->next;
            free(r);
        }
    }
}

float evaltree(NODEPTR p){
    NODEPTR q;

    replace(p);
    return(p->info.val);
    free(p);
}

void setsons(NODEPTR p, NODEPTR list){
    if(p == NULL){
        printf("Invalid insertion");
        exit(1);
    }
    if(p->son != NULL){
        printf("Invalid insertion");
        exit(1);
    }
    p->son = list;
}

void addson(NODEPTR p, int x){
    NODEPTR q;

    if(p == NULL){
        printf("Invalid insertion");
        exit(1);
    }
    q = (NODEPTR) malloc(sizeof(struct treenode));
    q->info.val = x;
    q->next = p->son;
    p->son = q;
}