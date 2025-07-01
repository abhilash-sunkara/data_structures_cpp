#include <cstddef>
#include <malloc.h>
#include <string>
#include <map>
#include <iostream>

#define MAX_CODE_SIZE 10

struct tree_node{
    char val;
    int frequency;
    struct tree_node* left = NULL;
    struct tree_node* right = NULL;
};

struct queue_node{
    struct tree_node* val;
    struct queue_node* next = NULL;
};

void fill_queue(struct queue_node*, char*);
struct tree_node* build_tree(struct queue_node*);
void generate_codes(struct tree_node*, std::map<char, std::string>*, std::string);
void message_to_code(char*, std::string*, std::map<char, std::string>*);
void code_to_message(struct tree_node*, std::string*, std::string*);

int find_in_queue(struct queue_node*, char*);
void increment(struct queue_node*, int);
void insert(struct queue_node*, struct tree_node*);
struct tree_node* remove(struct queue_node*);
int queue_contains_char(struct queue_node*, char*);
struct tree_node* combine_leaves(struct tree_node*, struct tree_node*);

int main(){
    char s[] = "Sun is down, freezing cold\nThat\'s how we already know winter\'s here\nMy dawg would probably do it for a Louis belt\nThat\'s just all he know he don\'t know nothing else\nI tried to show \'em, yeah";
    /* char s[] = "test"; */
    struct queue_node header;
    fill_queue(&header, s);
    struct tree_node* root = build_tree(&header);
    std::map<char, std::string> codes;
    generate_codes(root, &codes, "");
    std::string gen_code = "";
    message_to_code(s, &gen_code, &codes);
    std::string ans = "";
    code_to_message(root, &gen_code, &ans);
    std::cout << ans << std::endl;
}

void code_to_message(struct tree_node* tr, std::string* s, std::string* a){
    struct tree_node* tracker = tr;
    for(int i = 0; i < (*s).size(); i++){
        if((*s)[i] == '0'){
            tracker = tracker->left;
        } else {
            tracker = tracker->right;
        }

        if(tracker->left == NULL && tracker->right == NULL){
            a->push_back(tracker->val);
            tracker = tr;
        }
    }
}



void message_to_code(char* s, std::string* a, std::map<char, std::string>* c){
    while(*s != '\0'){
        *a = a->append(c->at(*s));
        s++;
    }
}

void generate_codes(struct tree_node* tr, std::map<char, std::string>* ans, std::string curr){
    if(tr == NULL){
        return;
    }
    if(tr->left == NULL && tr->right == NULL){
        (*ans).insert({tr->val, curr});
        return;
    }

    generate_codes(tr->left, ans, curr + '0');
    generate_codes(tr->right, ans, curr + '1');
}

struct tree_node* build_tree(struct queue_node* pq){
    while(pq->next->next != NULL){
        struct tree_node* first_min = remove(pq);
        struct tree_node* second_min = remove(pq);
        insert(pq, (combine_leaves(first_min, second_min)));
    }
    return pq->next->val;
}

struct tree_node* combine_leaves(struct tree_node* left, struct tree_node* right){
    struct tree_node* temp = (struct tree_node*) malloc(sizeof(struct tree_node));
    temp->left = left;
    temp->right = right;
    temp->val = '\0';
    temp->frequency = temp->left->frequency + temp->right->frequency;
    return temp;
}

void fill_queue(struct queue_node* pq, char* s){
    char* c = s;
    while(*c != '\0'){
        if(!queue_contains_char(pq, c)){
            char* x = s;
            struct tree_node* temp = (struct tree_node*) malloc(sizeof(struct tree_node));
            temp->frequency = 0;
            temp->left = NULL;
            temp->right = NULL;
            temp->val = *c;
            while(*x != '\0'){
                if(*x == *c){
                    temp->frequency++;
                }
                *x++;
            }
            insert(pq, temp);
        }
        *c++;
    }

    /* while(*s != '\0'){
        if(find_in_queue(pq, s) == -1){
            struct tree_node* temp = (struct tree_node*) malloc(sizeof(tree_node));
            temp->frequency = 1;
            temp->left = NULL;
            temp->right = NULL;
            temp->val = *s;
            insert(pq, temp);
        } else
            increment(pq, find_in_queue(pq, s));
        s++;
    } */
}

int queue_contains_char(struct queue_node* pq, char* c){
    while(pq->next != NULL){
        if(pq->next->val->val == *c){
            return 1;
        }
        pq = pq->next;
    }
    return 0;
}

int find_in_queue(struct queue_node* pq, char* s){
    struct queue_node* temp = pq;
    int loc = 0;
    while(temp->next != NULL && temp->val->val != *s){
        temp = temp->next;
        loc++;
    }
    if(pq->val->val == *s){
        return loc;
    }
    return -1;
}

void increment(struct queue_node* pq, int loc){
    struct queue_node* temp = pq;
    for(int i = 0; i < loc; i++){
        temp = temp->next;
    }
    temp->val->frequency++;
}

void insert(struct queue_node* pq, struct tree_node* x){
    struct queue_node* curr = pq;

    while(curr->next != NULL && curr->next->val->frequency < x->frequency){
        curr = curr->next;
    }

    if(curr->next == NULL){
        curr->next = (struct queue_node*) malloc(sizeof(struct queue_node));
        curr->next->next = NULL;
        curr->next->val = x;
    } else {
        struct queue_node* temp = curr->next;
        curr->next = (struct queue_node*) malloc(sizeof(struct queue_node));
        curr->next->next = temp;
        curr->next->val = x;
    }
}

struct tree_node* remove(struct queue_node* pq){
    if(pq->next != NULL){
        struct queue_node* temp = pq->next;
        pq->next = pq->next->next;
        struct tree_node* return_val = temp->val;
        free(temp);
        return return_val;
    }
    return NULL;
}





