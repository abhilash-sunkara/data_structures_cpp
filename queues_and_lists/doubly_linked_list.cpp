#include <cstddef>
#include <malloc.h>

struct node{
    int val;
    struct node* prev = NULL;
    struct node* next = NULL;
};

void print_all(struct node*);
void insert(struct node*, int, int);
int remove(struct node*, int);

int main(){
    struct node dl;
    insert(&dl, 1, 0);
    insert(&dl, 2, 1);
    insert(&dl, 3, 2);
    insert(&dl, 4, 3);
    insert(&dl, 5, 4);
    insert(&dl, 6, 5);
    insert(&dl, 7, 6);
    insert(&dl, 8, 7);
    insert(&dl, 9, 8);
    remove(&dl, 0);
    remove(&dl, 3);
    
}

void insert(struct node* dl, int x, int loc){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    struct node* check = dl;
    for(int i = 0; i < loc; i++){
        check = check->next;
    }

    temp->prev = check;
    temp->next = check->next;
    if(temp->next != NULL){
        temp->next->prev = temp;
    }
    check->next = temp;
    temp->val = x;
}

int remove(struct node* dl, int loc){
    struct node* temp = dl->next;
    
    for(int i = 0; i < loc; i++){
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    int ret_val = temp->val;
    free(temp);
    return ret_val;
}