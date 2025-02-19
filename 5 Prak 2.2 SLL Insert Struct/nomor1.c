/*#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

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
    int nama;

    printf ("Nama ");
    scanf ("%d", &nama);

    p = (Node*) malloc (sizeof (Node));

    if (p == NULL) {
        puts ("Alokasi gagal");
        exit (0);
    } else {
        p -> nama = nilai;
        p -> next = NULL;
    }
}

void awal () {
    if (head != NULL)
        p -> next = head;
    head = p;
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul
{
    char nama[50];
    int nilai;
    Node *next;
};

Node *head = NULL, *p;

void pesan_alokasi();
void awal();
void tampil();

int main()
{
    char jwb;
    puts("Insert Awal");
    do
    {
        fflush(stdin);
        pesan_alokasi();
        awal();
        fflush(stdin);
        printf("Ingin memasukkan data lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while ((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    return 0;
}

void tampil()
{
    Node *baca;

    puts("Data yang ada dalam SLL dari inputan user");
    baca = head;
    while (baca != NULL)
    {
        printf("Nama: %s, Nilai: %d\n", baca->nama, baca->nilai);
        baca = baca->next;
    }
}

void pesan_alokasi()
{
    char nama[50];
    int nilai;

    printf("Nama mahasiswa: ");
    scanf("%s", nama);

    printf("Nilai mahasiswa: ");
    scanf("%d", &nilai);

    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        strcpy(p -> nama, nama);
        p -> nilai = nilai;
        p -> next = NULL;
    }
}

void awal()
{
    if (head != NULL)
        p->next = head;
    head = p;
}
