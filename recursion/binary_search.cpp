#include <stdio.h>

int binary_search(int a[], int x, int low, int high){
    int mid;

    if(low > high){
        return -1;
    }

    mid = (low + high) / 2;
    return x == a[mid] ? mid : x < a[mid] ? binary_search(a, x, low, mid - 1) : binary_search(a, x, mid + 1, high);
}

int main(){
    int x[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", binary_search(x, x[4], 0, 6));
    printf("%d\n", binary_search(x, x[6], 0, 6));
    printf("%d\n", binary_search(x, x[1], 0, 6));
    printf("%d\n", binary_search(x, 8, 0, 6));
}