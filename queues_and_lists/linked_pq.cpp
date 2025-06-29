#include <cstddef>
#include <malloc.h>
#include <stdio.h>
struct node{
    int val;
    struct node* next = NULL;
};

void insert(struct node*, int);
int remove(struct node*);

int main(){
    struct node header;
    
    insert(&header, 20);
    insert(&header, 30);
    insert(&header, 10);

    printf("Removed %d\n", remove(&header));
    printf("Removed %d\n", remove(&header));
    printf("Removed %d\n", remove(&header));
}

void insert(struct node* pq, int x){
    struct node* curr = pq;

    while(curr->next != NULL && curr->next->val < x){
        curr = curr->next;
    }

    if(curr->next == NULL){
        curr->next = (struct node*) malloc(sizeof(struct node));
        curr->next->next = NULL;
        curr->next->val = x;
    } else {
        struct node* temp = curr->next;
        curr->next = (struct node*) malloc(sizeof(struct node));
        curr->next->next = temp;
        curr->next->val = x;
    }
}

int remove(struct node* pq){
    if(pq->next != NULL){
        struct node* temp = pq->next;
        pq->next = pq->next->next;
        int return_int = temp->val;
        free(temp);
        return return_int;
    }
    return -1;
}





