void swap(int* x, int* z){
    int temp = *z;
    *z = *x;
    *x = temp;
}

void insertion_sort(int* vals, int n){
    for(int i = 0; i < n; i++){
        int temp = i;
        while(temp != 0 && vals[temp] < vals[temp - 1]){
            swap(&vals[temp], &vals[temp - 1]);
            temp--;
        }
    }
}

int main(){
    int vals[] = {5, 6, 2, 3, 1, 9, 8, 4};
    insertion_sort(vals, 8);
}

