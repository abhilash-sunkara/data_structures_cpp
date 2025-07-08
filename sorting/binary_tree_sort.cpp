#include <cstddef>
#include <malloc.h>

struct sorted_array{
    int* vals;
    int index_pointer = 0;
};

struct node{
    int val;
    struct node* left_ptr;
    struct node* right_ptr;
};

void add(struct node*, int);
struct node* initialize_tree(int);
struct sorted_array* initialize_array(int[], int);
struct node* getnode(int);
void inorder_sort(struct node*, struct sorted_array*);

int main(){
    int x[] = {7, 5, 3, 9, 8, 12, 15};
    struct sorted_array* arr = initialize_array(x, 7);
    struct node* root = initialize_tree(x[0]);
    for(int i = 1; i < 7; i++){
        add(root, x[i]);
    }
    inorder_sort(root, arr);
}

struct sorted_array* initialize_array(int x[], int n){
    struct sorted_array* new_array = (struct sorted_array*) malloc(sizeof(struct sorted_array*));
    new_array->vals = x;
    new_array->index_pointer = 0;
    return new_array;
}

struct node* initialize_tree(int x){
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->left_ptr = NULL;
    root->right_ptr = NULL;
    root->val = x;
    return root;
}

struct node* getnode(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->left_ptr = NULL;
    temp->right_ptr = NULL;
    temp->val = x;
    return temp;
}

void add(struct node* nb, int x){
    if(x <= nb->val && nb->left_ptr == NULL){
        nb->left_ptr = getnode(x);
    } else if(x > nb->val && nb->right_ptr == NULL){
        nb->right_ptr = getnode(x);
    } else if(x <= nb->val){
        add(nb->left_ptr, x);
    } else {
        add(nb->right_ptr, x);
    }
}

void inorder_sort(struct node* nb, struct sorted_array* x){
    if(nb->left_ptr != NULL)
        inorder_sort(nb->left_ptr, x);
    x->vals[x->index_pointer++] = nb->val;
    if(nb->right_ptr != NULL)
        inorder_sort(nb->right_ptr, x);
}


