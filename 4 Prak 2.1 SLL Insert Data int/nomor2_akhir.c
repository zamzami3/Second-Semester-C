#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
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
        printf ("Ingin memasukkan nilai lagi? (y/t) ");
        jawab = getchar();

    } while ((jawab == 'y') || (jawab =='Y'));
    tampil();
    return 0;
}
void tampil () {
    Node *baca;

    puts("Isi dari SLL setelah inputan user");
    baca = head;
    while (baca != NULL) {
        printf ("%d\n", baca -> data);
        baca = baca -> next;
    }
}
void pesan_alokasi () {
    int nilai;

    printf ("Data yang mau disimpan: ");
    scanf ("%d", &nilai);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi gagal");
        exit (0);
    } else {
        p -> data = nilai;
        p -> next = NULL;
    }
}
void insert_akhir (){
    Node *tail;
    //tail pointer u/ menghubungkan node baru ke bagian akhir atau NULL

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
