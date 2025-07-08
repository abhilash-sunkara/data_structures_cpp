#include <climits>
void selectionsort(int x[], int n){
    int i, temp_largest_index, temp_largest_val;
    for(i = n-1; i >= 0; i--){
        temp_largest_val = INT_MIN;
        for(int j = 0; j <= i; j++){
            if(x[j] > temp_largest_val){
                temp_largest_index = j;
                temp_largest_val = x[j];
            }
        }
        x[temp_largest_index] = x[i];
        x[i] = temp_largest_val;
    }
}

int main(){
    int x[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionsort(x, 9);
}