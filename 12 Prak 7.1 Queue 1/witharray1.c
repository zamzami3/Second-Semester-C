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

void enqueue(char x, queue *q); //enqueue menyimpan item dari queue, dari belakang, rear
char dequeue(queue *q); //dequeue menghapus item dari queue, dari depan, front

void initialize(queue *q); //fungsi tambahan
int penuh(queue *q); //fugsi tambahan
int kosong(queue *q); //fungsi tambahan

int main () {
    //int pilih;
    queue antrian;
    char karakter;
    int i;

    initialize(&antrian);

    printf ("Memasukkan 5 elemen \n");
    for (i = 0 ; i < MAX; i++) {
        //fflush (stdin);
        printf ("Masukkan elemen ke-%d", i+1);
        scanf (" %c", &karakter);

        enqueue(karakter, &antrian);
    }

    puts(" ");
    printf ("Mengambil 3 elemen \n");
    for (i = 0 ; i < 3; i++) {
        printf ("%c\n", dequeue(&antrian));
    }

    puts(" ");
    printf ("Memasukkan 2 elemen \n");
    for (i = 0 ; i < 2; i++) {
        //fflush (stdin);
        printf ("Masukkan elemen ke-%d", i+1);
        scanf (" %c", &karakter);

        enqueue(karakter, &antrian);
    }

    /*puts ("MENU QUEUE using ARRAY");
    puts ("1. Mengisi Queue (ENQUEUE)");
    puts ("2. Mengambil isi Queue (DEQUEUE)");
    puts ("3. Menampilkan isi Queue -> FIFO");
    puts ("4. Keluar");

    printf ("Masukkan pilihan Anda: ");
    scanf ("%d", &pilih);

    switch (pilih) {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        tampil();
        break;
    case 4:
        puts ("Anda keluar");
        exit (0);
        break;
    default:
        puts ("Pilihan tidak ada dalam menu");
        exit (0);
        break;
    }*/
    return 0;
}

void enqueue (char x, queue *q) {
    if (penuh (q)) { //kalau penuh, gabisa melakukan enqueue
        printf ("Queue penuh, data tidak dapat disimpan lagi:>\n");
    } else {
        q->item[q->rear] = x; //menyimpan data pada posisi rear, lalu increment
        q->rear = (q->rear+1) % MAX; //circular queue
        //q->count++; //jml elemen diincrement
        (q->count)++;
    }
}

char dequeue (queue *q) {
    char temp;

    if (kosong(q)) {
        printf ("Queue masih kosong, belum bisa mengambil data\n");
        return ' '; //return kosong karena belum terisi
    } else {
        temp = q->item [q->front]; //mengambil data waktu posisi front
        q->front = (q->front+1) % MAX; //circular queue
        //q->count--; //jml elemen diincrement
        (q->count)--;
        return (temp);
    }
}

void initialize (queue *q) {
    q->count = 0; //sama dengan nol
    q->front = 0; //menunjuk index 0
    q->rear = 0; //menunjuk index 0
}

int penuh (queue *q) {
    if (q->count == MAX) {
        return 1; //bernilai MAX nya atau benar
    } else {
        return 0; //tidak bernilai penuh
    }
}

int kosong (queue *q) {
    if (q->count == 0) {
        return 1; //ya, masih kosong
    } else {
        return 0; //tidak, sudah penuh
    }
}
