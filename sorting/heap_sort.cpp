#include "min_heap_array.cpp"

struct min_heap* create_heap(int);
void add(struct min_heap*, int x);
void bottom_up_heapify(struct min_heap*, int);
void swap(int*, int*);
int min_remove(struct min_heap*);
void top_down_heapify(struct min_heap*, int);

int main(){
    int vals[] = {9, 6, 4, 10, 13, 3, 2, 20};
    struct min_heap* mh = create_heap(8);
    for(int i = 0; i < 8; i++){
        add(mh, vals[i]);
    }

    for(int i = 0; i < 8; i++){
        vals[i] = min_remove(mh);
    }
}

