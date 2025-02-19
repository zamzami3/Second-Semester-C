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
void tampil ();
void insert_akhir();
void insert_before ();

int main () {
    char jwb;
    do {
        pesan_alokasi ();
        insert_akhir ();
        fflush (stdin);
        printf ("Lagi (y/t)? ");
        jwb = getchar ();
    } while ((jwb == 'y') || (jwb == 'Y'));
    puts ("");
    tampil ();
    fflush(stdin);
    pesan_alokasi ();
    fflush(stdin);
    insert_before ();
    fflush(stdin);
    tampil ();
    return 0;
}

void insert_before () {
    Node *bef, *pbef;
    int key;

    printf ("Diletakkan sebelum node berapa? ");
    scanf ("%d", &key);

    bef = head;

    while (bef -> nama != key) {
        if (bef -> next == NULL) {
            printf ("%d tidak ada dalam SLL\n", key);
            exit (0);
        } else {
            pbef = bef;
            bef = bef -> next;
        }
    }
    p -> next = bef;
    pbef -> next = p;
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
