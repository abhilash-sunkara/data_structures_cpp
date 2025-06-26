#include <stdio.h>
struct elem{
    int val;
    int is_empty = 1;
};

#define MAXSIZE 100

void insert(struct elem*, int, int);
int find(struct elem*, int, int);
int has_left(struct elem*, int);
int has_right(struct elem*, int);
int get_index(struct elem*, int, int);

int main(){
    struct elem b_array[MAXSIZE];
    insert(b_array, 8, 0);
    insert(b_array, 4, 0);
    insert(b_array, 12, 0);

    insert(b_array, 2, 0);
    insert(b_array, 6, 0);
    
    insert(b_array, 10, 0);
    insert(b_array, 14, 0);

    /* printf("searching for %d, output should be %d, output is %d\n", 1, 0, find(b_array, 1, 0));
    printf("searching for %d, output should be %d, output is %d\n", 2, 1, find(b_array, 2, 0));
    printf("searching for %d, output should be %d, output is %d\n", 3, 0, find(b_array, 3, 0));
    printf("searching for %d, output should be %d, output is %d\n", 8, 1, find(b_array, 8, 0));
    printf("searching for %d, output should be %d, output is %d\n", 12, 1, find(b_array, 12, 0));
    printf("searching for %d, output should be %d, output is %d\n", 14, 1, find(b_array, 14, 0));
    printf("searching for %d, output should be %d, output is %d\n", 15, 0, find(b_array, 15, 0));
    printf("searching for %d, output should be %d, output is %d\n", 16, 0, find(b_array, 16, 0)); */

    /* printf("index of %d is %d\n", 8, get_index(b_array, 8, 0));
    printf("index of %d is %d\n", 4, get_index(b_array, 4, 0));
    printf("index of %d is %d\n", 12, get_index(b_array, 12, 0));
    printf("index of %d is %d\n", 6, get_index(b_array, 6, 0));
    printf("index of %d is %d\n", 2, get_index(b_array, 2, 0));
    printf("index of %d is %d\n", 10, get_index(b_array, 10, 0));
    printf("index of %d is %d\n", 15, get_index(b_array, 15, 0));
    printf("index of %d is %d\n", 21, get_index(b_array, 21, 0)); */
}

void insert(struct elem* ba, int x, int loc){
    if(ba[loc].is_empty){
        ba[loc].val = x;
        ba[loc].is_empty = 0;
    } else if (x <= ba[loc].val) {
        if(2 * loc + 1 < MAXSIZE)
            return insert(ba, x, 2 * loc + 1);
        else 
            return;
    } else {
        if(2 * loc + 2 < MAXSIZE)
            return insert(ba, x, 2 * loc + 2);
        else 
            return;
    }
}

int find(struct elem* ba, int x, int loc){
    if(!ba[loc].is_empty && ba[loc].val == x){
        return 1;
    } else if (x < ba[loc].val){
        if(2 * loc + 1 < MAXSIZE)
            return find(ba, x, 2 * loc + 1);
        else
            return 0;
    } else {
        if(2 * loc + 2 < MAXSIZE)
            return find(ba, x, 2 * loc + 2);
        else
            return 0;
    }
}

int has_left(struct elem* ba, int loc){
    if(loc * 2 + 1 < MAXSIZE && ba[loc * 2 + 1].is_empty == 0){
        return 0;
    }
    return -1;
}

int has_right(struct elem* ba, int loc){
    if(loc * 2 + 2 < MAXSIZE && ba[loc * 2 + 2].is_empty == 0){
        return 0;
    }
    return -1;
}

int get_index(struct elem* ba, int x, int loc){
    if(!ba[loc].is_empty && ba[loc].val == x){
        return loc;
    } else if (x < ba[loc].val){
        if(2 * loc + 1 < MAXSIZE)
            return get_index(ba, x, 2 * loc + 1);
        else
            return -1;
    } else {
        if(2 * loc + 2 < MAXSIZE)
            return get_index(ba, x, 2 * loc + 2);
        else
            return -1;
    }
}
