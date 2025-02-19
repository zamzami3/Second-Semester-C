#include <stdio.h>
#include <stdlib.h>
//di dalam struct ada data sebagai value dan next sebagai
//pointer/penunjuk ke linked list
typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;
//head = kepala = pointer bantuan
//p = pointer bantuan untuk memesan alokasi node baru

void pesan_alokasi ();
void awal ();
void tampil ();

int main () {
    char jwb;
    puts ("Insert Awal");
    do {
        fflush(stdin);
        pesan_alokasi ();
        awal ();
        fflush (stdin);
        printf ("Ingin memasukkan nilai lagi (y/t)? ");
        jwb = getchar ();
    } while ((jwb == 'y') || (jwb == 'Y'));
    tampil ();
    return 0;
}

void tampil () {
    Node *baca;

    puts ("Data yg ada dlm SLL dr inputan user");
    baca = head;
    while (baca != NULL) {
        printf ("%d\n", baca -> data);
        baca = baca -> next;
    }
}

void pesan_alokasi () {
    int nilai;

    printf ("Nilai yg mau disimpan dalam SLL ");
    scanf ("%d", &nilai);

    p = (Node*) malloc (sizeof (Node));

    if (p == NULL) {
        puts ("Alokasi gagal");
        exit (0);
    } else {
        p -> data = nilai;
        p -> next = NULL;
    }
}

void awal () {
    if (head != NULL)
        p -> next = head;
    head = p;
}
