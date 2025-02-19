// delete insert awal

/*#include <stdio.h>
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
void delete_awal();
void bebas(Node *);

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
    puts ("Delete bagian awal");
    delete_awal();
    tampil();
    return 0;
}

void bebas(Node *x) {
    free(x);
    x = NULL;
}

void delete_awal () {
    Node *del;

    del = head;
    if (del -> next != NULL) {
        head = NULL;
    } else {
        head = del -> next;
    }
    free(del);
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

    if (head == NULL){
        head = p;
    } else {
        tail = head;
        while (tail -> next != NULL)
            tail = tail -> next;
        tail -> next = p;
        tail = tail -> next;
    }
} */

#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};
Node *head = NULL;
Node *p;

void pesan_alokasi();
void insert_akhir();
void tampil();
void del_awal();
void bebas(Node *);

int main()
{
    char jawab;
    printf("Insert Akhir\n");

    do
    {
        fflush(stdin);
        pesan_alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Ingin memasukkan nilai lagi? (y/t) ");
        jawab = getchar();
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    puts("Hapus insert awal");
    // del_awal();
    // tampil();
    // del_awal();
    // tampil();
    // del_awal();
    // tampil();
    while (head != NULL)
    {
        del_awal();
        tampil();
    }
    return 0;
}

void del_awal()
{
    Node *del;

    del = head;
    if (del->next == NULL)
        head = NULL;
    else
    {
        head = del->next;
    }
    free(del);
    del = NULL;
}

void insert_akhir()
{
    Node *tail;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
}

void tampil()
{
    Node *baca;

    puts("Isi dari SLL setelah inputan user");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

void pesan_alokasi()
{
    int nilai;

    printf("Data yang mau disimpan: ");
    scanf("%d", &nilai);

    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->data = nilai;
        p->next = NULL;
    }
}
