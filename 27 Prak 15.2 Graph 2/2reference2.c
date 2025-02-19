#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000
#define N 5

typedef int typeinfo;
typedef struct {
    typeinfo data[N];
    int index;
} stack;

typedef struct {
    int count;
    int front;
    int rear;
    typeinfo item[N];
} queue;

int Q[][N] = {
    {M, 1, 3, M, M},
    {M, M, 1, M, 5},
    {3, M, M, 2, M},
    {M, M, M, M, 1},
    {M, M, M, M, M}
};
int TQ[N], R[N];
int asal, tujuan;

void inisialisasiTQR();
void inisialisasique(queue *);
typeinfo dequeue(queue *);
void enqueue(queue *, typeinfo);
int penuh(queue *);
int kosong(queue *);
int skosong(stack *);
void tampil();
void tampilTQR();
void djikstra(queue *);
typeinfo cek(int, queue *);
void rute();
void input();
void inisialisasi(stack *);
void push(typeinfo, stack *);
int pop(stack *);

int main() {
    queue antre;

    puts("Graph Djikstra\nMatriks Beban [Q]");
    tampil(Q);
    input();
    inisialisasiTQR();
    inisialisasique(&antre);
    enqueue(&antre, asal);
    djikstra(&antre);
    rute();
    tampilTQR();

    return 0;
}
void input() {
    printf("Masukkan asal : ");
    scanf("%d", &asal);
    asal--;
    printf("Masukkan tujuan : ");
    scanf("%d", &tujuan);
    tujuan--;
}

void rute() {
    int i, j;
    i = asal;
    stack graph;

    inisialisasi(&graph);
    j = tujuan;
    printf("Rute dari %d ke %d = ", asal + 1, tujuan + 1);
    while (R[tujuan] != -1) {
        push(R[tujuan], &graph);
        tujuan = R[tujuan];
    }
    while (!skosong(&graph)) {
        int node = pop(&graph) + 1;
        printf("%d", node);
        if(!skosong(&graph))
           printf(" - ");
    }
    printf(" - %d\n", j + 1);
}

void inisialisasi(stack *s) {
    s->index = 0;
}
void push(typeinfo data, stack *s) {
    if (s->index >= N) {
        puts("Stack penuh");
    } else {
        s->data[s->index] = data;
        s->index++;
    }
}
int skosong(stack *s) {
    return s->index == 0;
}
int pop(stack *s) {
    int tampung = -1;
    if (skosong(s)) {
        puts("Stack kosong");
    } else {
        s->index--;
        tampung = s->data[s->index];
    }
    return tampung;
}

typeinfo cek(int data, queue *antre) {
    queue cek = *antre;
    for (int i = 0; i < cek.count; i++) {
        if (cek.item[(cek.front + i) % N] == data)
            return 1;
    }
    return 0;
}

void djikstra(queue *antre) {
    int currnode, i;
    do {
        currnode = dequeue(antre);
        i = 0;
        while (i < N){
            if (Q[currnode][i] != M){
                if (Q[currnode][i] + TQ[currnode] < TQ[i]){
                    TQ[i] = Q[currnode][i] + TQ[currnode];
                    R[i] = currnode;
                    if(i != asal && i != tujuan && !cek(i , antre))
                        enqueue(antre, i);
                }
            }
            i++;
        }
    } while (!kosong(antre));
    printf("\nTotal beban = %d\n", TQ[tujuan]);
}

void enqueue(queue *q, typeinfo x) {
    if (penuh(q)) {
        puts("Queue penuh! Data terakhir tidak bisa masuk");
    } else {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % N;
        q->count++;
    }
}

typeinfo dequeue(queue *q) {
    typeinfo temp = -1;
    if (kosong(q)) {
        puts("Queue kosong!");
    } else {
        temp = q->item[q->front];
        q->front = (q->front + 1) % N;
        q->count--;
    }
    return temp;
}

void tampil(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == M)
                printf("M ");
            else
                printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}
void tampilTQR() {
    printf("Matriks TQ : ");
    for (int i = 0; i < N; i++) {
        if (TQ[i] == M) {
            printf("M ");
        } else
            printf("%d ", TQ[i]);
    }
    puts("");
    printf("Matriks R : ");
    for (int i = 0; i < N; i++) {
            printf("%d ", R[i]);
    }
    puts("");
}

int penuh(queue *q) {
    return q->count == N;
}

int kosong(queue *q) {
    return q->count == 0;
}
void inisialisasique(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}
void inisialisasiTQR(){
    for (int i = 0; i < N; i++){
        R[i] = -1;
        if (i == asal)
            TQ[i] = 0;
        else
            TQ[i] = M;
    }
}
