#include <malloc.h>
struct min_heap{
    int* array;
    int length;
    int bound;
};

struct min_heap* create_heap(int);
void add(struct min_heap*, int x);
void bottom_up_heapify(struct min_heap*, int);
void swap(int*, int*);
int min_remove(struct min_heap*);
void top_down_heapify(struct min_heap*, int);

/* int main(){
    struct min_heap* mh = create_heap(7);
    add(mh, 20);
    add(mh, 10);
    add(mh, 30);
    int min1 = min_remove(mh);
    add(mh, 40);
    int min2 = min_remove(mh);
} */

struct min_heap* create_heap(int n){
    struct min_heap* temp = (struct min_heap*) malloc(sizeof(struct min_heap));
    int* arr = (int*) malloc(sizeof(int) * n);
    temp->bound = n-1;
    temp->array = arr;
    temp->length = -1;
    return temp;
}

void add(struct min_heap* mh, int x){
    mh->length++;
    mh->array[mh->length] = x;
    bottom_up_heapify(mh, mh->length);
}

void bottom_up_heapify(struct min_heap* mh, int i){
    int parent = (i - 1) / 2;
    if(i == 0)
        return;
    
    if(parent >= 0){
        if(mh->array[i] < mh->array[parent]){
            swap(&(mh->array[i]), &(mh->array[parent]));
            bottom_up_heapify(mh, parent);
        }
    }
}

void top_down_heapify(struct min_heap* mh, int index){
    int smallest_index = index;

    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;

    if(left_index <= mh->length && mh->array[left_index] < mh->array[index]){
        smallest_index = left_index;
    }

    if(right_index <= mh->length && mh->array[right_index] < mh->array[index]){
        smallest_index = right_index;
    }

    if(smallest_index != index){
        swap(&(mh->array[index]), &(mh->array[smallest_index]));
        top_down_heapify(mh, smallest_index);
    }
}


int min_remove(struct min_heap* mh){
    int min = mh->array[0];
    int last = mh->array[mh->length--];
    mh->array[0] = last;
    top_down_heapify(mh, 0);
    return min;
}

void swap(int* x, int* z){
    int temp = *z;
    *z = *x;
    *x = temp;
}