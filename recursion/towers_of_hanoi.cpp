#include <stdio.h>

void towers(int, char, char, char);

int main(){
    towers(4, 'A', 'B', 'C');
}

void towers(int num, char from_peg, char aux_peg, char to_peg){
    if(num == 1){
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    towers(num - 1, from_peg, to_peg, aux_peg);
    printf("Move disk %d from peg %c to peg %c\n", num, from_peg, to_peg);
    towers(num - 1, aux_peg, from_peg, to_peg);
}

