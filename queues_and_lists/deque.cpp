#include <cstddef>
#include <malloc.h>
#include <stdio.h>

struct node{
    int val;
    struct node* nodeptr = NULL;
};


int remvleft(struct node*);
int remvright(struct node*);
void insrtleft(struct node*, int);
void insrtright(struct node*, int);

int main(){
    struct node dq;
    insrtleft(&dq, 1);
    insrtright(&dq, 2);
    insrtleft(&dq, 3);
    insrtright(&dq, 5);
    printf("%d\n", remvleft(&dq));
    printf("%d\n", remvright(&dq));
}

void insrtleft(struct node* dq, int x){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp = dq->nodeptr;
    dq->nodeptr = new_node;
    new_node->nodeptr = temp;
    new_node->val = x;
}

void insrtright(struct node* dq, int x){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* check = dq;
    while(check->nodeptr != NULL){
        check = check->nodeptr;
    }
    check->nodeptr = new_node;
    new_node->nodeptr = NULL;
    new_node->val = x;
}

int remvleft(struct node* dq){
    struct node* temp = dq->nodeptr;
    dq->nodeptr = dq->nodeptr->nodeptr;
    int ret_val = temp->val;
    free(temp);
    return ret_val;
}

int remvright(struct node* dq){
    struct node* check = dq;
    while(check->nodeptr->nodeptr != NULL){
        check = check->nodeptr;
    }

    struct node* temp = check->nodeptr;
    check->nodeptr = NULL;
    int ret_val = temp->val;
    free(temp);
    return ret_val;
}

