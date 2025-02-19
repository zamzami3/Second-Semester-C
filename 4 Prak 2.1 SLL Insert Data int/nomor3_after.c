#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
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
        fflush(stdin);
        pesan_alokasi();
        akhir();
        fflush(stdin);
        printf ("Lagi (y/t)? ");
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

    while (after != NULL && after -> data != key) {
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

    puts("Isi dari SLL");
    baca = head;
    while (baca != NULL) {
        printf ("%d\n", baca -> data);
        baca = baca -> next;
    }
}


void pesan_alokasi () {
    int x;

    printf ("Data yang mau disimpan: ");
    scanf ("%d", &x);
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        puts("Alokasi gagal");
        exit (0);
    } else {
        p -> data = x;
        p -> next = NULL;
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
