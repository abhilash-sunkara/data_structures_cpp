#include <cstddef>
#include <malloc.h>
#include <stdio.h>

struct node{
    int val;
    struct node* left_ptr;
    struct node* right_ptr;
    struct node* parent;
    int num_children;
};


void add(struct node*, int);
struct node* initialize_tree(int);
struct node* getnode(int);
int find(struct node*, int);
struct node* find_node(struct node*, int);
void remove(struct node*, int);
struct node* get_successor(struct node*);
struct node* get_predecessor(struct node*);
void in_order(struct node*);
void pre_order(struct node*);
void post_order(struct node*);

int main(){
    struct node* bst = initialize_tree(8);
    add(bst, 5);
    add(bst, 3);
    add(bst, 6);
    add(bst, 12);
    add(bst, 10);
    add(bst, 14);
    /* add(bst, 6); */
    /* printf("%d\n", find(bst, 5));
    printf("%d\n", find(bst, 7)); */

    in_order(bst);
    printf("\n");
    pre_order(bst);
    printf("\n");
    post_order(bst);
}

struct node* initialize_tree(int x){
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->left_ptr = NULL;
    root->right_ptr = NULL;
    root->parent = NULL;
    root->val = x;
    root->num_children = 0;
    return root;
}

void add(struct node* nb, int x){
    if(x <= nb->val && nb->left_ptr == NULL){
        nb->left_ptr = getnode(x);
        nb->left_ptr->parent = nb;
        nb->num_children++;
    } else if(x > nb->val && nb->right_ptr == NULL){
        nb->right_ptr = getnode(x);
        nb->right_ptr->parent = nb;
        nb->num_children++;
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
    temp->num_children = 0;
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

struct node* find_node(struct node* nb, int x){
    if(nb->val == x){
        return nb;
    } else if (x < nb->val && nb->left_ptr == NULL){
        return NULL;
    } else if (x > nb->val && nb->right_ptr == NULL){
        return NULL;
    } else if(nb->val > x){
        return find_node(nb->left_ptr, x);
    } else {
        return find_node(nb->right_ptr, x);
    }
}

void remove(struct node* nb, int x){
    struct node* temp = find_node(nb, x);
    if(temp == NULL){
        return;
    }

    if(temp->num_children == 0){
        if(temp == temp->parent->left_ptr){
            temp->parent->left_ptr = NULL;
        } else {
            temp->parent->right_ptr = NULL;
        }
        temp->parent->num_children--;
    } else if (temp->num_children == 1){
        if(temp == temp->parent->left_ptr){
            if(temp->left_ptr != NULL){
                temp->parent->left_ptr = temp->left_ptr;
                temp->parent->left_ptr->parent = temp->parent;
            } else {
                temp->parent->left_ptr = temp->right_ptr;
                temp->parent->left_ptr->parent = temp->parent;
            }
        } else {
            if(temp->left_ptr != NULL){
                temp->parent->right_ptr = temp->left_ptr;
                temp->parent->right_ptr->parent = temp->parent;
            } else {
                temp->parent->right_ptr = temp->right_ptr;
                temp->parent->right_ptr->parent = temp->parent;
            }
        }
        temp->parent->num_children--;
    } else {
        if(temp == temp->parent->left_ptr){
           struct node* predecessor = get_predecessor(temp);
           if(temp->parent != NULL){
                temp->parent->left_ptr = predecessor;
            }
            predecessor->parent = temp->parent;
            /* if(predecessor->left_ptr != NULL){
                predecessor->left_ptr->parent = predecessor;
            } */
            predecessor->left_ptr = temp->left_ptr;
            predecessor->left_ptr->parent = predecessor;
        } else {
            struct node* successor = get_successor(temp);
            if(temp->parent != NULL){
                temp->parent->right_ptr = successor;
            }
            successor->parent = temp->parent;
            /* if(successor->left_ptr != NULL){
                successor->left_ptr->parent = successor;
            } */
            successor->right_ptr = temp->right_ptr;
            successor->right_ptr->parent = successor;
        }
        
    }

    free(temp);
}

struct node* get_successor(struct node* nb){
    struct node* temp = nb;
    while(temp != NULL && temp->left_ptr != NULL){
        temp = temp->left_ptr;
    }
    return temp;
}

struct node* get_predecessor(struct node* nb){
    struct node* temp = nb;
    while(temp != NULL && temp->right_ptr != NULL){
        temp = temp->right_ptr;
    }
    return temp;
}

void in_order(struct node* nb){
    if(nb->left_ptr != NULL)
        pre_order(nb->left_ptr);
    printf("%d\n", nb->val);
    if(nb->right_ptr != NULL)
        pre_order(nb->right_ptr);
}

void pre_order(struct node* nb){
    printf("%d\n", nb->val);
    if(nb->left_ptr != NULL)
        pre_order(nb->left_ptr);
    if(nb->right_ptr != NULL)
        pre_order(nb->right_ptr);
}

void post_order(struct node* nb){
    if(nb->left_ptr != NULL)
        pre_order(nb->left_ptr);
    if(nb->right_ptr != NULL)
        pre_order(nb->right_ptr);
    printf("%d\n", nb->val);
}

