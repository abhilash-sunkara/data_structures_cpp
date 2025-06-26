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

enum branch{
    LEFT, MIDDLE, RIGHT
};

void initialize_node(struct node*);
struct node* get_node();
void add(struct node*, int);
int find(struct node*, int);
void remove(struct node*, int);
int contains_val_in_node(struct node*, int);

int main(){
    struct node b_tree;
    initialize_node(&b_tree);
    add(&b_tree, 10);
    add(&b_tree, 20);

    add(&b_tree, 30);
    add(&b_tree, 40); 
    add(&b_tree, 5);
    add(&b_tree, 8);
    

    /* add(&b_tree, 5);
    add(&b_tree, 15);
    add(&b_tree, 25);
    add(&b_tree, 8);
    add(&b_tree, 18);
    add(&b_tree, 28); */

    /*  printf("looking for number %d, should be %d, is %d\n", 5, 1, find(&b_tree, 5));
    printf("looking for number %d, should be %d, is %d\n", 1, 0, find(&b_tree, 1));
    printf("looking for number %d, should be %d, is %d\n", 7, 0, find(&b_tree, 7));
    printf("looking for number %d, should be %d, is %d\n", 10, 1, find(&b_tree, 10));
    printf("looking for number %d, should be %d, is %d\n", 17, 0, find(&b_tree, 17));
    printf("looking for number %d, should be %d, is %d\n", 25, 1, find(&b_tree, 25));
    printf("looking for number %d, should be %d, is %d\n", 23, 0, find(&b_tree, 23));
    printf("looking for number %d, should be %d, is %d\n", 30, 0, find(&b_tree, 30)); */

    remove(&b_tree, 20);


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

void swap(struct node * nb){
    int temp = nb->val[0];
    nb->val[0] = nb->val[1];
    nb->val[1] = temp;
}


void add(struct node* nb, int x){
    if(nb->num_keys == 0){
        nb->val[0] = x;
        nb->num_keys++;
    } else if(nb->num_keys == 1){
        nb->val[1] = x;
        nb->num_keys++;
        if(nb->val[0] > nb->val[1]){
            swap(nb);
        }
    } else {
        if(x < nb->val[0] && nb->left == NULL){
            nb->left = get_node();
            nb->left->parent = nb;
            nb->num_children++;
            add(nb->left, x);
        } else if(x < nb->val[0]){
            add(nb->left, x);
        } else if(x > nb->val[0] && x < nb->val[1] && nb->middle == NULL){
            nb->middle = get_node();
            nb->middle->parent = nb;
            nb->num_children++;
            add(nb->middle, x);
        } else if(x > nb->val[0] && x < nb->val[1]){
            add(nb->middle, x);
        } else if(x > nb->val[1] && nb->right == NULL){
            nb->right = get_node();
            nb->right->parent = nb;
            nb->num_children++;
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
        return 0;
    } else if(x < nb->val[0]){
        return find(nb->left, x);
    } else if(x > nb->val[0] && x < nb->val[1] && nb->middle == NULL){
        return 0;
    } else if(x > nb->val[0] && x < nb->val[1]){
        return find(nb->middle, x);
    } else if(x > nb->val[1] && nb->right == NULL){
        return 0;
    } else {
        return find(nb->right, x);
    }
}

int contains_val_in_node(struct node* nb, int x){
    if(nb->val[0] == x){
        return 1;
    } else if(nb->val[1] == x){
        return 1;
    } 
    return -1;
}

void fill(struct node* fill, struct node* source, enum branch b){
    if(source == NULL || source->num_children == 0){
        return;
    }

    if(fill->val[1] == 0 && fill->num_keys == 1){
        if(b == RIGHT){
            fill->val[1] = source->val[0];
            source->val[0] = 0;
            fill->num_keys++;
            source->num_keys--;
            if(source->left == NULL){
                swap(source);
            }
        } else if (b == MIDDLE){
            if(source->num_keys == 2){
                fill->val[1] = source->val[1];
                source->val[1] = 0;
                fill->num_keys++;
                source->num_keys--;
            } else {
                fill->val[1] = source->val[0];
                source->val[0] = 0;
                fill->num_keys++;
                source->num_keys--;
                if(source->left == NULL){
                    swap(source);
                }
            }
        }
    }
    
    if(source->left != NULL || source->middle != NULL || source->right != NULL){
        if(source->val[0] == 0){
            if(source->left != NULL){
                
            }
        }
        if(source->val[1] == 0){
            
        }
    } else {
        return;
    }
}

void remove(struct node* nb, int x){
    if(!find(nb, x)){
        return;
    }
    
    if(nb->num_children == 0){
        if(nb->val[0] == x){
            nb->val[0] = 0;
            nb->num_keys--;
            swap(nb);
        } else if(nb->val[1] == x) {
            nb->val[1] = 0;
            nb->num_keys--;
        }
        return;
    }
    
    if(x == nb->val[1] && nb->right != NULL){
        nb->val[1] = 0;
        fill(nb, nb->right, RIGHT);
    } else if(x == nb->val[0] && nb->left != NULL){
        if(nb->left->num_children == 2){
            nb->val[0] = nb->left->val[1];
            nb->right->val[0] = 0;
            swap(nb->right);
        } else {
            
        }
        
    }

    

    /* if(x < nb->val[0] && nb->left == NULL){
        return;
    }
    if(x > nb->val[0] && x < nb->val[1] && nb->middle == NULL){
        return;
    }
    if(x > nb->val[1] && nb->right == NULL){
        return;
    } */

    if(x < nb->val[0]){
        return;
    }



    
    

}


