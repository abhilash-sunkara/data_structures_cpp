#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack{
    int top;
    double items[MAXCOLS];
};

double eval(char[]);
double pop(struct stack *);
void push(struct stack*, double);
int empty(struct stack *);
int isdigit(char);
double oper(int, double, double);

int main(){
    char expr[MAXCOLS] = "55+8*\0";;
    int position = 0;

    /* while((expr[position++] = getchar()) != '\n')
        ;
    expr[position--] = '\0'; */

    printf("%s%s", "The original postfix expression is ", expr);

    printf("\n%f", eval(expr));
}

double eval(char expr[]){
    int c, position;
    double opnd1, opnd2, value;
    struct stack opndstck;

    opndstck.top = -1;
    for(position = 0; (c = expr[position]) != '\0'; position++){
        if(isdigit(c)){
            push(&opndstck, double (c-'0'));
        } else {
            opnd2 = pop(&opndstck);
            opnd1 = pop(&opndstck);
            value = oper(c, opnd1, opnd2);
            push(&opndstck, value);
        }
    }
    return(pop(&opndstck));
}

int isdigit(char symb){
    return (symb >= '0' && symb <= '9');
}

double oper(int symb, double op1, double op2){
    switch(symb){
        case '+' : return (op1 + op2);
        case '-' : return (op1 - op2);
        case '*' : return (op1 * op2);
        case '/' : return (op1 / op2);
        case '$' : return (pow(op1, op2));
        default : printf("%s", "Illegal operation"); exit(1);
    }
}

int empty(struct stack* ps){
    if(ps->top == -1){
        return 1;
    }
    return 0;
}

double pop(struct stack* ps){
    if(empty(ps)){
        exit(1);
    }
    return(ps->items[ps->top--]);
}
    
void push(struct stack* ps, double x){
    if(ps->top == MAXCOLS - 1){
        exit(1);
    } else {
        ps->items[++(ps->top)] = x;
    }
}