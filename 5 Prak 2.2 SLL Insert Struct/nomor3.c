#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    char nama[50];
    int nilai;
    Node *next;
};

Node *head = NULL, *p;

void pesan_alokasi ();
void akhir ();
void tampil ();
void insert_after ();

int main () {
    char jawab;
    puts ("Insert After");

    do {
        //fflush(stdin);
        pesan_alokasi();
        akhir();
        fflush(stdin);
        printf ("Ingin memasukkan data mahasiswa lagi? (y/t) ");
        jawab = getchar();
    } while ((jawab == 'y') || (jawab =='Y'));
    tampil();
    fflush (stdin);
    puts ("Insert after node tertentu");
    pesan_alokasi ();
    fflush (stdin);
    insert_after ();
    tampil ();
    return 0;
}

void insert_after () {
    Node *after;
    int key;

    printf ("Disisipkan setelah node berapa? ");
    scanf ("%d", &key);

    after = head;

    while (after != NULL && after -> nama != key) {
        after = after -> next;
    }

    if (after == NULL) {
        printf ("%d tidak ada dalam SLL\n", key);
        exit (0);
    }

    p -> next = after -> next;
    after -> next = p;
}

void tampil () {
    Node *baca;

    puts("Data yang ada dalam SLL dari inputan user");
    baca = head;
    while (baca != NULL) {
        printf("Nama: %s, Nilai: %d\n", baca->nama, baca->nilai);
        baca = baca->next;
    }
}

void pesan_alokasi () {
    char nama[50];
    int nilai;

    printf("Nama mahasiswa: ");
    scanf("%s", nama);
    printf("Nilai mahasiswa: ");
    scanf("%d", &nilai);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi gagal");
        exit(0);
    } else {
        strcpy(p->nama, nama);
        p->nilai = nilai;
        p->next = NULL;
    }
}

void akhir (){
    Node *tail;

    if (head == NULL){
        head = p;
    } else {
        tail = head;
        while (tail -> next != NULL)
            tail = tail -> next;
        tail -> next = p;
    }
}
