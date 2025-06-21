#include <cstddef>
#include <stdio.h>
#include <malloc.h>

/* struct list{
    struct node* nodeptr = NULL;
}; */

struct node{
    int val; 
    struct node* nodeptr = NULL;
};

void push(struct node*, int);
void print_all(struct node*);
void insert(struct node*, int, int);
int remove(struct node*, int);

int main(){
    struct node n;
    push(&n, 1);
    push(&n, 3);
    push(&n, 4);
    push(&n, 5);
    /* print_all(&n); */
    insert(&n, 2, 1);
    /* print_all(&n); */
    remove(&n, 1);
    print_all(&n);
    printf("Finished running\n");
}

void push(struct node* n, int x){
    if(n->nodeptr == NULL){
        /* printf("New node generated\n"); */
        n->nodeptr = (struct node*) malloc(sizeof(struct node));
        n->nodeptr->val = x;
        n->nodeptr->nodeptr = NULL;
    } else {
        push(n->nodeptr, x);
    }
}

void print_all(struct node* n){
    struct node* ptr = n->nodeptr;
    while(ptr != NULL){
        printf("%d\n", ptr->val);
        ptr = ptr->nodeptr;
    }
}

void insert(struct node* n, int x, int loc){
    /* int i = 0;
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    struct node* prev = l->nodeptr;
    for(; i < loc; i++){
        prev = prev->nodeptr;
    }
    struct node* ptr = prev;
    prev = temp;
    temp->nodeptr = ptr;
    temp->val = x; */

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* prev = n;
    struct node* temp = n->nodeptr;

    for(int i = 0; i < loc; i++){
        temp = temp->nodeptr;
        prev = prev->nodeptr;
    }

    prev->nodeptr = new_node;
    new_node->nodeptr = temp;
    new_node->val = x;
}

int remove(struct node* n, int loc){
    struct node* prev = n;
    struct node* to_be_removed = n->nodeptr;

    for(int i = 0; i< loc; i++){
        prev = prev->nodeptr;
        to_be_removed = to_be_removed->nodeptr;
    }

    prev->nodeptr = to_be_removed->nodeptr;
    int return_value = to_be_removed->val;
    free(to_be_removed);
    return return_value;
}

