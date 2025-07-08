#include <malloc.h>
struct node{
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* add_node(struct node*, int, struct node*);
struct node* max_delete(struct node*, int*);
struct node* get_last_node(struct node*);
struct node* heapify(struct node*, struct node*);
struct node* get_node(int, struct node*);
void swap(struct node*, struct node*);

int main(){
    struct node* root = get_node(100, NULL);
    root = add_node(root, 75, NULL);
    root = add_node(root, 50, NULL);
    root = add_node(root, 200, NULL);
    root = add_node(root, 150, NULL);
    int z = 0;
    root = max_delete(root, &z);
}

struct node* get_node(int x, struct node* parent){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->val = x;
    temp->parent = parent;
    return temp;
}

struct node* add_node(struct node* root, int x, struct node* parent){
    if(root->val < x){
        struct node* temp = get_node(x, parent);
        temp->left = root->left;
        temp->right = root;
        root->left = NULL;
        if(temp->left != NULL)
            temp->left->parent = temp;
        if(temp->right != NULL)
            temp->right->parent = temp;
        return temp;
    } else {
        if(root->left == NULL){
            root->left = get_node(x, root);
            root->left->left = NULL;
            root->left->right = NULL;
            root->left->val = x;
            root->left->parent = root;
            return root;
        } else if(root->right == NULL){
            root->right = get_node(x, root);
            root->right->left = NULL;
            root->right->right = NULL;
            root->right->val = x;
            root->right->parent = root;
            return root;
        } else if(x % 2){
            root->right = add_node(root->right, x, root);
        } else {
            root->left = add_node(root->left, x, root);
        }
    }
    return root;
}

struct node* max_delete(struct node* root, int* x){
    *x = root->val;
    struct node* last = get_last_node(root);
    last->left = root->left;
    last->right = root->right;
    if(last->parent->left == last)
        last->parent->left = NULL;
    if(last->parent->right == last)
        last->parent->right = NULL;
    last->parent = root->parent;
    if(last->left != NULL)
        last->left->parent = last;
    if(last->right != NULL)
        last->right->parent = last;
    return heapify(last, NULL);
    free(root);
}

struct node* get_last_node(struct node* root){
    if(root->right != NULL){
        return get_last_node(root->right);
    } else if(root->left != NULL){
        return get_last_node(root->left);
    } else {
        return root;
    }
}

struct node* heapify(struct node* root, struct node* parent){
    struct node* largest_node = root;
    struct node* left = root->left;
    struct node* right = root->right;

    if(left != NULL && left->val > largest_node->val){
        largest_node = left;
    }

    if(right != NULL && right->val > largest_node->val){
        largest_node = right;
    }

    if(largest_node->parent != parent){
        swap(root, largest_node);
        heapify(root, largest_node);
    }
    return largest_node;
}

void swap(struct node* x, struct node* y){
    if(x->left == y){
        struct node* temp_right = x->right;
        struct node* temp_parent = x->parent;
        x->left = y->left;
        x->right = y->right;
        x->parent = y;
        y->left = x;
        y->right = temp_right;
        y->parent = temp_parent;
        if(x->left != NULL)
            x->left->parent = x;
        if(x->right != NULL)
            x->right->parent = x;
    } else if (x->right == y){
        struct node* temp_left = x->left;
        struct node* temp_parent = x->parent;
        x->left = y->left;
        x->right = y->right;
        x->parent = y;
        y->right = x;
        y->left = temp_left;
        y->parent = temp_parent;
        if(x->left != NULL)
            x->left->parent = x;
        if(x->right != NULL)
            x->right->parent = x;
    }
}