#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *previous, *next;
};

Dnode *head = NULL, *p, *del;

void pesantempat();
void tampil();
void dll_insertakhir();
void dll_deleteakhir();

int main () {
    char jawab;

    puts ("\tDouble Linked List Insert Akhir\t");
    do {
        fflush(stdin);
        pesantempat();
        dll_insertakhir();
        fflush(stdin);
        printf ("Ingin menambah data lagi? (Y/T) ");
        jawab = getchar();
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    puts ("\tDelete Awal\t");
    fflush (stdin);
    dll_deleteakhir();
    tampil();
    return 0;
}

void dll_deleteakhir(){
    Dnode *del;

    del = head;

    while (del -> next != NULL) {
        del = del -> next;
    }
    del -> previous -> next = NULL;
    free(del);
    del = NULL;
}

void pesantempat() {
    int bil;

    printf ("Bilangan yang mau disimpan? ");
    scanf ("%d", &bil);

    p = (Dnode*) malloc (sizeof (Dnode));
    if (p == NULL) {
        puts ("Alokasi nya gagal");
        exit (0);
    } else {
        p -> data = bil;
        p -> next = NULL;
        p -> previous = NULL;
    }
}
void tampil(){
    Dnode *read;

    puts ("Isi dari DLL: ");
    read = head;

    while (read != NULL) {
        printf ("%d\n", read -> data);
        read = read -> next;
    }
}

void dll_insertakhir() {
    Dnode *tail;
    if (head != NULL) {
        tail = head;
        while (tail -> next != NULL)
            tail = tail -> next;
        p -> previous = tail;
        tail -> next = p;
        tail = p;
    } else {
        head = p;
    }
}
