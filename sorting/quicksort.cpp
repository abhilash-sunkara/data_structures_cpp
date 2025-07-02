#include <stdio.h>
int partition(int[], int, int);

void quicksort(int x[], int lower, int upper){
   if(lower >= upper){
        return;
    }

    int mid = partition(x, lower, upper);
    quicksort(x, lower, mid-1);
    quicksort(x, mid+1, upper);
}

int partition(int x[], int lower, int upper){
    int temp_lower_index = lower;
    int temp_upper_index = upper;
    while(upper > lower){
        while(x[lower] <= x[temp_lower_index] && lower < temp_upper_index){
            lower++;
        }
        while(x[upper] > x[temp_lower_index]){
            upper--;
        }
        if(upper > lower){
            int temp = x[lower];
            x[lower] = x[upper];
            x[upper] = temp;
        }
    }
    int temp = x[temp_lower_index];
    x[temp_lower_index] = x[upper];
    x[upper] = temp;
    return upper;
}

int main(){
    int x[] = {57, 12, 48, 37, 12, 92, 86, 33};

    /* printf("Output is %d\n", partition(x, 0, 7)); */

    quicksort(x, 0, 7);
}