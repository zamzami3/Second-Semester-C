#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int item[MAX];
    int front;
    int rear;
    int count;
} queue;

void case_enq(queue *q, int nilai);
void case_deq(queue *q);
void case_tampil_fifo(queue *q);
void case_banding(queue *q); //new function
void case_search(queue *q, int nilai); //new function

void enqueue(int nilai, queue *q);
int dequeue(queue *q);
void tampil(queue *q);
void banding(queue *q); //baru
void search(queue *q, int nilai); //baru

void initialize(queue *q);
int penuh(queue *q);
int kosong(queue *q);

int main() {
    int pilih, nilai;
    queue antrian;

    initialize(&antrian);

    while (pilih != 6) {
        puts(" ");
        puts("Menu QUEUE using Array:");
        puts("1. Tambah Data"); //enq
        puts("2. Hapus Data"); //deq
        puts("3. Tampilkan data min & max");
        puts("4. Cari data");
        puts("5. Cetak isi Queue"); //tampil
        puts("6. Keluar");

        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                case_enq(&antrian, nilai);
                break;
            case 2:
                case_deq(&antrian);
                break;
            case 3:
                case_banding(&antrian);
                break;
            case 4:
                case_search(&antrian, nilai);
            case 5:
                case_tampil_fifo(&antrian);
                break;
            case 6:
                puts("Anda keluar!");
                exit (0);
                break;
            default:
                puts("Pilihan tidak ada dalam menu@.@ Anda keluar!");
                exit(0);
                break;
        }
    }
    return 0;
}

void case_enq(queue *q, int nilai){
    if (penuh(q)) {
        puts ("STOP!!!");
        puts ("Queue Penuh! Data terakhir gak bs masuk!");
        return;
    } else {
        printf ("Masukkan data Anda : ");
        scanf ("%d", &nilai);
        enqueue(nilai, q);
    }
}

void case_deq(queue *q) {
    if (kosong(q)) {
        puts("Queue masih kosong, belum bisa mengeluarkan data\n");
    } else {
        printf ("Item yang Anda ambil adalah %d\n", dequeue(q));
    }
}
void case_tampil_fifo(queue *q) {
    if (kosong(q)) {
        puts ("Queue masing kosong, belum bisa menampilkan data");
    } else {
        printf ("Isi Queue saat ini adalah: \n");
        tampil(q);
    }
}

void case_banding(queue *q) {
    if (kosong(q)) {
        puts ("Queue masing kosong, belum bisa membandingkan data");
    } else {
        banding(q);
    }
}

void case_search (queue *q, int nilai) {
    printf ("Data yang di cari: ");
    scanf ("%d", &nilai);

    if (kosong(q)) {
        puts ("Queue masih kosong, tidak bisa mencari data");
    } else {
        search(q,nilai);
    }
}

void enqueue (int nilai, queue *q) {
    q->item[q->rear] = nilai;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
}

int dequeue (queue *q) {
    int temp;

    temp = q->item [q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return temp;
}

void tampil(queue *q) {
    int index = q->front;

    for (int i = 0; i < q->count; i++) {
        printf ("%d\n", q->item[index]);
        index = (index + 1) % MAX;
    }
}

void banding(queue *q){
    int nilai;
    int min = q->item[q->front];
    int max = q->item[q->front];

    int index = q->front;

    for (int i = 0; i < q->count; i++) {
        nilai = q->item[index];
        if (nilai < min) {
            min = nilai;
        }
        if (nilai > max) {
            max = nilai;
        }
        index = (index + 1) % MAX;
}

    printf ("Data terkecil = %d\n", min);
    printf ("Data terbesar = %d\n", max);
}

void search (queue *q, int nilai){
    int index = q->front;

    for (int i = 0; i < q->count; i++) {
        if (q->item[index] == nilai) {
            printf ("%d ada dalam Queue\n", nilai);
            return;
        }
        index = (index + 1) % MAX;
    }
    printf ("%d tidak ada dalam Queue\n", nilai);
}

void initialize (queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int penuh (queue *q) {
    return q->count == MAX;
}

int kosong (queue *q) {
    return q->count == 0;
}
