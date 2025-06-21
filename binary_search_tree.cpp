#include <cstddef>
#include <malloc.h>
#include <stdio.h>

struct node{
    int val;
    struct node* left_ptr;
    struct node* right_ptr;
};

void add(struct node*, int);
struct node* initialize_tree(int);
struct node* getnode(int);
int find(struct node*, int);

int main(){
    struct node* b_tree = initialize_tree(8);
    add(b_tree, 5);
    add(b_tree, 12);
    add(b_tree, 6);
    printf("%d\n", find(b_tree, 5));
    printf("%d\n", find(b_tree, 7));
}

struct node* initialize_tree(int x){
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->left_ptr = NULL;
    root->right_ptr = NULL;
    root->val = x;
    return root;
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

struct node* getnode(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->left_ptr = NULL;
    temp->right_ptr = NULL;
    temp->val = x;
    return temp;
}

int find(struct node* nb, int x){
    if(nb->val == x){
        return 1;
    } else if (nb->val < x && nb->left_ptr == NULL){
        return -1;
    } else if (nb->val > x && nb->right_ptr == NULL){
        return -1;
    } else if(nb->val > x){
        return find(nb->left_ptr, x);
    } else {
        return find(nb->right_ptr, x);
    }
}

