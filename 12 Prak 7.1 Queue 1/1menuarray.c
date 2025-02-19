//queue

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//typedef char itemType;
typedef struct {
    char item[MAX];
    int front;
    int rear;
    int count;
} queue;

void case_enq(queue *q);
void case_deq(queue *q);
void case_tampil_fifo(queue *q);

void enqueue(char x, queue *q);
char dequeue(queue *q);
void tampil(queue *q);

void initialize(queue *q);
int penuh(queue *q);
int kosong(queue *q);

int main() {
    int pilih;
    queue antrian;

    initialize(&antrian);

    while (pilih != 4) {
        puts(" ");
        puts("MENU QUEUE using ARRAY");
        puts("1. Mengisi Queue (ENQUEUE)");
        puts("2. Mengambil isi Queue (DEQUEUE)");
        puts("3. Menampilkan isi Queue -> FIFO");
        puts("4. Keluar");

        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                case_enq(&antrian);
                break;
            case 2:
                case_deq(&antrian);
                break;
            case 3:
                case_tampil_fifo(&antrian);
                break;
            case 4:
                puts("Anda keluar!");
                break;
            default:
                puts("Pilihan tidak ada dalam menu@.@ Anda keluar!");
                pilih = 4;
                break;
        }
    }
    return 0;
}

void case_enq(queue *q){
    char elemen;

    if (penuh(q)) {
        puts ("STOP!!!");
        puts ("Queue Penuh! Data  terakhir gak bs masuk!");
        return;
    } else {
        printf ("Masukkan data Anda : ");
        scanf (" %c", &elemen);
        enqueue(elemen, q);
    }
}

void case_deq(queue *q) {
    if (kosong(q)) {
        puts("Queue masih kosong, belum bisa mengambil data:o\n");
        return '\0';
    } else {
        printf ("Item yang Anda ambil adalah %c\n", dequeue(q));
    }
}
void case_tampil_fifo(queue *q) {
    tampil(q);
}

void enqueue (char x, queue *q) {
    q->item[q->rear] = x;
    q->rear = (q->rear + 1) % MAX; //circular queue
    q->count++;
}

char dequeue (queue *q) {
    char temp;

    temp = q->item [q->front]; //mengambil data waktu posisi front
    q->front = (q->front + 1) % MAX; //circular queue
    q->count--;
    return temp;
}

void tampil(queue *q) {
    if (kosong(q)) {
        puts ("Queue Kosong!");
    } else {
        printf ("Isi Queue saat ini adalah: \n");
        for (int i = 0; i < q->count; i++) {
            printf ("%c\n", q->item[q->front]);
            q->front = (q->front + 1) % MAX;
        }
    }
}

void initialize (queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int penuh (queue *q) {
    if (q->count == MAX) {
        return 1;
    } else {
        return 0;
    }
    //return q->count == MAX
}

int kosong (queue *q) {
    if (q->count == 0) {
        return 1;
    } else {
        return 0;
    }
    //return q->count == 0;
}
