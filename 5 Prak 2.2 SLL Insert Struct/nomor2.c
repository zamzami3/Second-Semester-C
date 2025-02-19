#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    char nama[50];
    int nilai;
    Node *next;
};

Node *head = NULL;
Node *p;

void pesan_alokasi ();
void insert_akhir ();
void tampil ();

int main () {
    char jawab;
    printf ("Insert Akhir\n");

    do {
        fflush(stdin);
        pesan_alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Ingin memasukkan data lagi (y/t)? ");
        jawab = getchar();
        fflush (stdin);
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    fflush (stdin);
    return 0;
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
void insert_akhir (){
    Node *tail;

    if (head == NULL){
        head = p;
    } else {
        tail = head;
        while (tail -> next != NULL)
            tail = tail -> next;
        tail -> next = p;
        tail = tail -> next;
    }
}
