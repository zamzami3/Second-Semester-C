// pada queue linked list menggunakan insert akhir, dan delete awal

#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *tail = NULL, *p;

void enqueue();
void dequeue();
void tampil();
void pesan_alokasi(char x);
void initialize();

int main () {
    int menu;

    while (menu != 4) {
        puts (" ");
        puts ("MENU QUEUE using LINKED LIST : ");
        puts ("1. Mengisi Queue (ENQUEUE)");
        puts ("2. Mengambil isi Queue (DEQUEUE)");
        puts ("3. Menampilkan isi Queue -> FIFO");
        puts ("4. Keluar");

        printf ("Masukkan pilihan Anda: ");
        scanf ("%d", &menu);

        switch (menu) {
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
            puts ("Anda keluar!");
            exit (0);
            break;
        default:
            puts ("Pilihan tidak ada dalam menu, Anda keluar!");
            menu = 4;
            exit (0);
            break;
        }
    }
    return 0;
}

void enqueue() {
    char x;
    pesan_alokasi(x);

    if (tail != NULL) {
        tail->next = p;
    } else {
        head = p;
    }
    tail = p;
}

void dequeue() {
    Node *temp;
    initialize();

    temp = head;
    printf ("Item yang Anda ambil adalah %c\n", head->data);

    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

void tampil() {
    Node *baca;
    initialize();

    baca = head;
    puts ("Isi Queue saat ini adalah: ");
    while (baca != NULL) {
        printf ("%c\n", baca->data);
        baca = baca->next;
    }
}

void pesan_alokasi(char x) {
    printf ("Masukkan data Anda: ");
    scanf (" %c", &x);

    p = (Node*) malloc (sizeof (Node));

    if (p == NULL) {
        puts ("Alokasi gagal");
        exit (0);
    }
    p->data = x;
    p->next = NULL;
}

void initialize() {
    if (head == NULL) {
        puts ("Queue masih kosong:o");
        puts ("Silakan coba lagi");
        return ' ';
    }
}
