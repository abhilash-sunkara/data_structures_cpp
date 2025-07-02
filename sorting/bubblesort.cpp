void bubblesort(int x[], int n){
    int hold, j, pass;
    int switched = 1;
    for(pass = 0; pass < n-1 && switched == 1; pass++){
        switched = 0;
        for(j = 0; j < n-pass-1; j++){
            if(x[j] > x[j+1]){
                switched = 1;
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;
            }
        }
    }
}

int main(){
    int x[] = {5, 3, 4, 6, 7, 1, 9};
    bubblesort(x, 7);
}