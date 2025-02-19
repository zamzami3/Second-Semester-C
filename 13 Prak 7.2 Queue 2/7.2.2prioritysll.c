#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    char data;
    int priority;
    Node *next;
};

Node *head = NULL, *p, *posisi;


void enqueue();
void dequeue();
void tampil();

void pesan(char kar, int nilai);
void initialize();
void prioritas(char kar, int nilai);

int main () {
    int choose;

    while (choose != 4) {
        puts (" ");
        puts ("MENU PRIORITY using LINKED LIST");
        puts ("1. Mengisi Queue"); //enq
        puts ("2. Mengambil isi Queue"); //deq
        puts ("3. Menampilkan isi Queue"); //tampil
        puts ("4. Keluar");

        printf ("Masukkan pilihan Anda: ");
        scanf ("%d", &choose);

        switch (choose) {
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
            puts ("Anda keluar:(");
            exit(0);
            break;
        default:
            puts ("Pilihan tidak ada dalam menu, Anda keluar");
            puts ("Silahkan coba lagi");
            choose = 4;
            exit(0);
            break;
        }
    }
    return 0;
}

void enqueue() {
    char kar;
    int nilai;

    printf ("Masukkan data Anda: ");
    scanf (" %c", &kar);

    printf ("Nilai prioritasnya: ");
    scanf ("%d", &nilai);

    pesan(kar, nilai);
}

void dequeue() {
    Node *del;
    initialize();

    del = head;
    printf ("Item yang Anda ambil adalah %c\n", del->data);

    head = head->next;
    free(del);
}

void tampil() {
    initialize();
    Node *read;

    read = head;
    puts ("Isi Queue saat ini adalah: ");
    puts ("Data \t Prioritas");
    while (read != NULL) {
        printf ("%c \t %d\n", read->data, read->priority);
        read = read->next;
    }
}

void pesan(char kar, int nilai) {
    p = (Node*) malloc (sizeof(Node));

    if (p == NULL) {
        puts ("Alokasi gagal");
        return;
    }
    p->data = kar;
    p->priority = nilai;
    p->next = NULL;

    prioritas(kar, nilai);
}

void initialize() {
    if (head == NULL) {
        puts ("Queue masih kosong");
        puts ("Silahkan coba lagi");
        return;
    }
}

void prioritas(char kar, int nilai) {
    if (head == NULL || head->priority > nilai) {
        p->next = head;
        head = p; //jadi node pertama
    } else {
        posisi = head;
        while (posisi->next != NULL && posisi->next->priority <= nilai) {
            posisi = posisi->next;
        }
        p->next = posisi->next;
        posisi->next = p;
    }
}
