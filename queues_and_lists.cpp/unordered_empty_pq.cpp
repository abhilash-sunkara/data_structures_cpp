#include <stdio.h>
#include <malloc.h>
#define QCAPACITY 20

struct queue_item{
    int val;
    int is_empty = 0;
};

struct priority_queue{
    struct queue_item* items[QCAPACITY];
    int rear = -1;
};

int is_full(struct priority_queue*);
int is_empty(struct priority_queue*);
void compact(struct priority_queue*, int);

void push(struct priority_queue* pq, int x){
    if(!is_full(pq)){
        pq->items[++(pq->rear)] = (struct queue_item*) malloc(sizeof(struct queue_item));
        struct queue_item* temp = pq->items[(pq->rear)];
        temp->is_empty = 0;
        temp->val = x;
    } else {
        printf("Can't push %d to pq, queue overflow\n", x);
    }
}

int min_remove(struct priority_queue* pq){
    if(!is_empty(pq)){
        struct queue_item* min;
        int min_int = INT_MAX;
        int i = 0;
        int x = 0;
        for(; i <= pq->rear; i++){
            if((pq->items[i]->val < min_int) && !(pq->items[i]->is_empty)){
                min_int = pq->items[i]->val;
                min = pq->items[i];
                x = i;
            }
        }

        compact(pq, x);

        min->is_empty = 1;
        return min->val;
    } else {
        printf("Can't remove from pq, queue underflow\n");
        return -1;
    }
}

int max_remove(struct priority_queue* pq){
    if(!is_empty(pq)){
        struct queue_item* max;
        int max_int = INT_MIN;
        int i = 0;
        int x = 0;
        for(; i <= pq->rear; i++){
            if((pq->items[i]->val > max_int) && !(pq->items[i]->is_empty)){
                max_int = pq->items[i]->val;
                max = pq->items[i];
                x = i;
            }
        }

        compact(pq, x);

        max->is_empty = 1;
        return max->val;
    } else {
        printf("Can't remove from pq, queue underflow\n");
        return -1;
    }
}

void compact(struct priority_queue* pq, int i){
    for(; i < pq->rear; i++){
        pq->items[i] = pq->items[i + 1];
    }
    (pq->rear)--; 
}


int is_empty(struct priority_queue* pq){
    return pq->rear == -1;
}

int is_full(struct priority_queue* pq){
    return pq->rear == QCAPACITY - 1;
}

int main(){
    struct priority_queue pq;
    push(&pq, 2);
    push(&pq, 3);
    push(&pq, 1);
    push(&pq, 4);
    printf("Removed %d\n", min_remove(&pq));
    printf("Removed %d\n", min_remove(&pq));
    push(&pq, 5);
    push(&pq, 1);
    printf("Removed %d\n", min_remove(&pq));
    push(&pq, 1);
    printf("Removed %d\n", max_remove(&pq));
    printf("Removed %d\n", min_remove(&pq));
    printf("Removed %d\n", min_remove(&pq));
    printf("No errors\n");
}


