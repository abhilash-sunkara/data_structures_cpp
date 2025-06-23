#include <cstddef>
#include <malloc.h>
#include <stdio.h>
struct node {
    int val[2];
    struct node* left;
    struct node* right;
    struct node* middle;
    struct node* parent;
    int num_children;
    int num_keys;
};

void initialize_node(struct node*);
struct node* get_node();
void add(struct node*, int);
int find(struct node*, int);

int main(){
    struct node b_tree;
    initialize_node(&b_tree);
    add(&b_tree, 10);
    add(&b_tree, 20);

    add(&b_tree, 5);
    add(&b_tree, 15);
    add(&b_tree, 25);
    add(&b_tree, 8);
    add(&b_tree, 18);
    add(&b_tree, 28);

    printf("looking for number %d, should be %d, is %d\n", 5, 1, find(&b_tree, 5));
    printf("looking for number %d, should be %d, is %d\n", 1, -1, find(&b_tree, 1));
    printf("looking for number %d, should be %d, is %d\n", 7, -1, find(&b_tree, 7));
    printf("looking for number %d, should be %d, is %d\n", 10, 1, find(&b_tree, 10));
    printf("looking for number %d, should be %d, is %d\n", 17, -1, find(&b_tree, 17));
    printf("looking for number %d, should be %d, is %d\n", 25, 1, find(&b_tree, 25));
    printf("looking for number %d, should be %d, is %d\n", 23, -1, find(&b_tree, 23));
    printf("looking for number %d, should be %d, is %d\n", 30, -1, find(&b_tree, 30));
}   

void initialize_node(struct node* nb){
    nb->left = NULL;
    nb->middle = NULL;
    nb->right = NULL;
    nb->parent = NULL;

    nb->val[0] = 0;
    nb->val[1] = 0;

    nb->num_children = 0;
    nb->num_keys = 0;
}

struct node* get_node(){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    initialize_node(temp);
    return temp;
}

void check_swap(struct node * nb){
    if(nb->val[0] > nb->val[1]){
        int temp = nb->val[0];
        nb->val[0] = nb->val[1];
        nb->val[1] = temp;
    }
}

void add(struct node* nb, int x){
    if(nb->num_keys == 0){
        nb->val[0] = x;
        nb->num_keys++;
    } else if(nb->num_keys == 1){
        nb->val[1] = x;
        nb->num_keys++;
        check_swap(nb);
    } else {
        if(x < nb->val[0] && nb->left == NULL){
            nb->left = get_node();
            nb->left->parent = nb;
            add(nb->left, x);
        } else if(x < nb->val[0]){
            add(nb->left, x);
        } else if(x > nb->val[0] && x < nb->val[1] && nb->middle == NULL){
            nb->middle = get_node();
            nb->middle->parent = nb;
            add(nb->middle, x);
        } else if(x > nb->val[0] && x < nb->val[1]){
            add(nb->middle, x);
        } else if(x > nb->val[1] && nb->right == NULL){
            nb->right = get_node();
            nb->right->parent = nb;
            add(nb->right, x);
        } else{
            add(nb->right, x);
        }
    }
}

int find(struct node* nb, int x){
    if(nb->val[0] == x || nb->val[1] == x){
        return 1;
    } else if(x < nb->val[0] && nb->left == NULL){
        return -1;
    } else if(x < nb->val[0]){
        return find(nb->left, x);
    } else if(x > nb->val[0] && x < nb->val[1] && nb->middle == NULL){
        return -1;
    } else if(x > nb->val[0] && x < nb->val[1]){
        return find(nb->middle, x);
    } else if(x > nb->val[1] && nb->right == NULL){
        return -1;
    } else {
        return find(nb->right, x);
    }
}



