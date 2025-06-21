#include <stdio.h>
#include <stdlib.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

void postfix(char *, char *);
int isoperand(char);
void popandtest(struct stack *, char *, int *);
int prcd(char, char);
void push(struct stack *, char);
char pop(struct stack *);
int empty(struct stack *);

struct stack {
    int top;
    char items[MAXCOLS];
};

int main(){
    char infix[MAXCOLS] = "(1+1)*3\0";
    char postr[MAXCOLS];
    int pos = 0;

    printf("%d\n", prcd('+', '+'));
    printf("%d\n", prcd('*', '+'));
    printf("%d\n", prcd('+', '*'));
    /* while((infix[pos++] = getchar()) != '\n');
    infix[--pos] = '\0'; */
    printf("%s%s\n", "The original expression is ", infix);
    postfix(infix, postr);
    printf("%s\n", postr);
}

void postfix(char* infix, char* postr){
    int position, und;
    int outpos = 0;
    char topsymb = '+';
    char symb;
    struct stack opstck;
    opstck.top = -1;

    for(position = 0; (symb = infix[position]) != '\0'; position++)
        if(isoperand(symb))
            postr[outpos++] = symb;
        else {
            popandtest(&opstck, &topsymb, &und);
            while(!und && prcd(topsymb, symb)){
                postr[outpos++] = topsymb;
                popandtest(&opstck, &topsymb, &und);
            }
            if(!und)
                push(&opstck, topsymb);
            if(und || (symb != ')'))
                push(&opstck, symb);
            else 
                topsymb = pop(&opstck);
        }
    while(!empty(&opstck))
        postr[outpos++] = pop(&opstck);
    postr[outpos] = '\0';
    return;
}

int empty(struct stack* ps){
    if(ps->top == -1){
        return 1;
    }
    return 0;
}

char pop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    }
    return(ps->items[ps->top--]);
}
    
void push(struct stack* ps, char x){
    if(ps->top == MAXCOLS - 1){
        exit(1);
    } else {
        ps->items[++(ps->top)] = x;
    }
}

void popandtest(struct stack* ps, char* pc, int* pund){
    if(empty(ps)){
        *pund = TRUE;
        return;
    }
    *pund = FALSE;
    *pc = ps->items[ps->top--];
    return;
}

int isoperand(char c){
    return !(c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '(' || c == ')');
}

int prcd(char c1, char c2){
    if(c1 == '('){
        return FALSE;
    } else if (c2 == '(' && c1 != ')') {
        return FALSE;
    } else if (c2 == ')' && c1 != '('){
        return TRUE;
    } else if(c1 == ')'){
        exit(1);
    }

    int p1, p2;

    switch(c1){
        case '-' : p1 = 1; break;
        case '+' : p1 = 1; break;
        case '*' : p1 = 2; break;
        case '/' : p1 = 2; break;
        case '&' : p1 = 3; break;
        default : p1 = 0;
    }

    switch(c2){
        case '-' : p2 = 1; break;
        case '+' : p2 = 1; break;
        case '*' : p2 = 2; break;
        case '/' : p2 = 2; break;
        case '&' : p2 = 3; break;
        default : p2 = 0;
    }
   /*  printf("p1 val : %d\n", p1);
    printf("p2 val : %d\n", p2); */
    return p1 >= p2;
}