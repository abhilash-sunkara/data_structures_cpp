#include <stdio.h>
#include <cstdlib>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

struct queue {
    int items[MAXQUEUE];
    int front, rear;
};
struct queue q;

int empty(struct queue*);
int remove(struct queue*);
void insert(struct queue*, int);

int main(){
    q.front = q.rear = MAXQUEUE - 1;
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);
    /* insert(&q, 5); */
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    insert(&q, 5);
    insert(&q, 6);
    insert(&q, 7);
    insert(&q, 8);
    /* insert(&q, 5); */
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    printf("Removing %d\n", remove(&q));
    printf("No errors");
}

int empty(struct queue* pq){
    return ((pq->front == pq->rear) ? TRUE : FALSE);
}

int remove(struct queue* pq){
    if(empty(pq)){
        printf("queue underflow");
        exit(1);
    }

    if(pq->front == MAXQUEUE - 1){
        pq->front = 0;
    } else {
        (pq->front)++;
    }
    return pq->items[pq->front];
}

void insert(struct queue* pq, int x){
    if(pq->rear == MAXQUEUE - 1){
        pq->rear = 0;
    } else {
        (pq->rear)++;
    }
    if(pq->rear == pq->front){
        printf("queue overflow");
        exit(1);
    }
    pq->items[pq->rear] = x;
}



