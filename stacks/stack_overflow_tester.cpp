#include <stdio.h>

#define STACKSIZE 8

void check_stack_overflow(char* s){
    int val = 0;
    for(; *s != '\0'; s++){
        if(*s == '+'){
            if(val < STACKSIZE){
                val++;
            } else {
                printf("Overflow error");
                return;
            }
        } else {
            if(val > 0){
                val--;
            } else {
                printf("Underflow error");
                return;
            }
        }
    }
    printf("No errors");
}

int main(){
    check_stack_overflow("++++++++--------++++++++");
}