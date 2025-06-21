#include <stdio.h>

int factorial(int n){
    int x, y;
    if(n == 0)
        return 1;
    x = n-1;
    y = factorial(x);
    return (n * y);
}

int multiply(int a, int b){
    return (b == 1 ? a : multiply(a, b-1) + a);
}

int fibonacci(int n){
    int x, y;

    if(n <= 1){
        return n;
    }
    x = fibonacci(n-1);
    y = fibonacci(n-2);
    return x + y;
}

int main(){
    printf("%d\n", factorial(6));
    printf("%d\n", factorial(5));
    printf("%d\n", factorial(4));

    printf("%d\n", multiply(6, 3));
    printf("%d\n", multiply(21, 4));
    printf("%d\n", multiply(10, 10));

    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(12));
    printf("%d\n", fibonacci(0));
}