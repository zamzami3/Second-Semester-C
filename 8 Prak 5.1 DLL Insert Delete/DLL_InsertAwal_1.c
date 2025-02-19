#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *previous, *next;
};

Dnode *head = NULL, *p;

void pesantempat();
void tampil();
void dll_insertawal();

int main () {
    char jawab;

    puts ("\tDouble Linked List Insert Awal\t");
    do {
        fflush(stdin);
        pesantempat();
        dll_insertawal();
        fflush(stdin);
        printf ("Ingin menambah data lagi? (Y/T) ");
        jawab = getchar();
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    return 0;
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

void dll_insertawal(){
    if (head != NULL) {
        p -> next = head;
        head -> previous = p;
    }
    head = p;
}
