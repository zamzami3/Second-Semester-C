#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int front, rear, count;
} queue;

void initialize(queue *);
void enqueue(itemType, queue *);
itemType dequeue (queue *);
int isFull (queue *);
int isEmpty (queue *);

int main () {
    queue antrian;
    char jawab, x  ;
    //itemType temp;

    initialize(&antrian);
    do {
        fflush(stdin);
        printf ("Data yang mau disimpan: ");
        x = getchar();
        fflush(stdin);
        enqueue(x, &antrian);
        fflush(stdin);
        printf ("Lagi? (y/t) ");
        jawab = getchar();
    } while (jawab == 'y' || jawab == 'Y');

    for (int i = 0; i < MAX; i++) {
        //temp = dequeue(&antrian);
        //printf ("%c\n", temp);
        printf ("%c\n", dequeue(&antrian));
    }
    return 0;
}

void enqueue(itemType item, queue *q){
    if (isFull(q)) {
        puts ("Queue penuh");
        exit(0);
    } else {
        q->data[q->rear] = item;
        q->rear++;
        q->count++;
    }
}

itemType dequeue (queue *q) {
    itemType temp;

    if (isEmpty(q)) {
        puts ("Kosong");
        temp =' ';
    } else {
        temp = q->data[q->front];
        q->front++;
        q->count--;
    }
    return temp;
}

int isFull (queue *q) {
    /*if (q->count == MAX) {
        return 1;
    } else {
        return 0;
    }*/
    return (q->count == MAX? 1 : 0);
}

int isEmpty (queue *q) {
    return (q->count == 0? 1 : 0);
}

void initialize(queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}
