#include <stdio.h>
#include <stdlib.h>
#define M 999
#define N 5

typedef int itemType;
typedef struct {
    int item[N];
    int front;
    int rear;
    int count;
} queue;

typedef struct {
    int data[N];
    int count;
} stack;

void inisialisasiQueue(queue *);
int empty_q(queue *);
int full_q(queue *);
void enqueue(itemType, queue *);
itemType dequeue(queue *);

void inisialisasiStack(stack *);
int empty_s(stack *);
int full_s(stack *);
void push(itemType, stack *);
itemType pop(stack *);

void djikstra();
void inisialisasiTQ();
void inisialisasiR();
int ada(itemType, queue *);
void baca_rute();

int QQ[][6] = {
    {M, 1, 3, M, M, M},
    {M, M, 1, M, 5, 7},
    {3, M, M, 2, M, M},
    {M, M, M, M, 1, M},
    {M, 4, M, M, M, 2},
    {M, M, M, M, M, M}
};

int Q[][5] = {
    {M, 1, 3, M, M},
    {M, M, 1, M, 5},
    {3, M, M, 2, M},
    {M, M, M, M, 1},
    {M, M, M, M, M}
};
int TQ[N], R[N];

int asal, tujuan;

int main() {
    int i;

    puts("Graph Djikstra");
    tampil(Q);
    djikstra();
    baca_rute();
    printf("Matriks TQ: ");
    for (i = 0; i < N; i++) {
        printf("%d ", TQ[i]);
    }
    puts("");
    printf("Matriks R: ");
    for (i = 0; i < N; i++) {
        printf("%d ", R[i]);
    }
    puts("");
    return 0;
}

void baca_rute() {
    int tujuan_asli;
    stack tumpukan;

    inisialisasiStack(&tumpukan);
    tujuan_asli = tujuan;
    printf("\nRute dari %d ke %d = ", asal + 1, tujuan + 1);
    while (R[tujuan] != asal) {
        push(R[tujuan], &tumpukan);
        tujuan = R[tujuan];
    }
    printf("%d - ", asal + 1);
    while (!empty_s(&tumpukan)) {
        printf("%d - ", pop(&tumpukan) + 1);
    }
    printf("%d\n", tujuan_asli + 1);
    printf("Total beban = %d\n", TQ[tujuan_asli]);
}

void djikstra() {
    int i, cn;
    queue antrian;

    printf("Masukkan asal: ");
    scanf("%d", &asal);
    asal--;
    fflush(stdin);
    printf("Masukkan tujuan: ");
    scanf("%d", &tujuan);
    tujuan--;
    inisialisasiTQ();
    inisialisasiR();
    inisialisasiQueue(&antrian);
    enqueue(asal, &antrian);
    while (!empty_q(&antrian)) {
        cn = dequeue(&antrian);
        i = 0;
        while (i < N) {
            if (Q[cn][i] != M) {
                if (Q[cn][i] + TQ[cn] < TQ[i]) {
                    TQ[i] = Q[cn][i] + TQ[cn];
                    R[i] = cn;
                    if (i != asal && i != tujuan && !ada(i, &antrian)) {
                        enqueue(i, &antrian);
                    }
                }
            }
            i++;
        }
    }
}

void inisialisasiR() {
    int i;
    for (i = 0; i < N; i++) {
        R[i] = -1;
    }
}

void inisialisasiTQ() {
    int i;

    for (i = 0; i < N; i++) {
        if (i == asal) {
            TQ[i] = 0;
        } else {
            TQ[i] = M;
        }
    }
}

int ada(itemType x, queue *q) {
    int i;
    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % N;
        if (q->item[index] == x) {
            return 1;
        }
    }
    return 0;
}

void inisialisasiQueue(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int empty_q(queue *q) {
    return (q->count == 0);
}

int full_q(queue *q) {
    return (q->count == N);
}

void enqueue(itemType x, queue *q) {
    if (!full_q(q)) {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % N; // circular queue
        q->count++;
    } else {
        printf("Queue penuh, data tidak dapat disimpan\n");
    }
}

itemType dequeue(queue *q) {
    if (!empty_q(q)) {
        itemType temp = q->item[q->front];
        q->front = (q->front + 1) % N;
        q->count--;
        return temp;
    } else {
        printf("Queue kosong, tidak ada data untuk diambil\n");
        return -1; // Assuming -1 is not a valid node index
    }
}

void inisialisasiStack(stack *s) {
    s->count = 0;
}

int empty_s(stack *s) {
    return (s->count == 0);
}

int full_s(stack *s) {
    return (s->count == N);
}

void push(itemType x, stack *s) {
    if (!full_s(s)) {
        s->data[s->count] = x;
        s->count++;
    } else {
        puts("Stack penuh, data tidak dapat disimpan");
    }
}

itemType pop(stack *s) {
    if (!empty_s(s)) {
        s->count--;
        return s->data[s->count];
    } else {
        puts("Saat ini Stack Kosong, tidak bisa mengambil data");
        return -1; // Assuming -1 is not a valid node index
    }
}

void tampil(int matriks[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriks[i][j] == M)
                printf("M ");
            else
                printf("%d ", matriks[i][j]);
        }
        puts("");
    }
}
