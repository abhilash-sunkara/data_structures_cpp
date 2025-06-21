#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 1
#define MAXSTRINGSIZE 100

void readstr(char *, char *, int *);
int expr(char *, int, int *);
int term(char *, int, int *);
int getsymb(char *, int, int *);
int factor(char *, int, int *);

int getsymb(char* str, int length, int* ppos){
    char c;
    if(*ppos < length){
        c = str[*ppos];
    } else {
        c = ' ';
    }
    (*ppos)++;
    return c;
}

int main(){
    char str[MAXSTRINGSIZE];
    int length, pos;

    readstr(str, "", &length);
    pos = 0;
    if(expr(str, length, &pos) == TRUE && pos >= length)
        printf("%s", "Valid");
    else 
        printf("%s", "Invalid");
}

int expr(char* str, int length, int *ppos){
    if(term(str, length, ppos) == FALSE){
        return FALSE;
    }
    if(getsymb(str, length, ppos) != '+'){
        (*ppos)--;
        return TRUE;
    }
    return (term(str, length, ppos));
}

int term(char* str, int length, int* ppos){
    if(factor(str, length, ppos) == FALSE){
        return FALSE;
    }
    if(getsymb(str, length, ppos) != '*'){
        (*ppos)--;
        return TRUE;
    }
    return factor(str, length, ppos);
}

int factor(char* str, int length, int* ppos){
    int c;

    if((c = getsymb(str, length, ppos)) != '(')
        return isalpha(c);
    return expr(str, length, ppos) && getsymb(str, length, ppos) == ')';
}

void readstr(char* to, char* from, int* l){
    int i = 0;
    for(; (*(to+i) = *(from+i)) != '\0'; i++){

    }

    *l = i;
}