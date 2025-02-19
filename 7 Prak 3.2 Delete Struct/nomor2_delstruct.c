// delete insert akhir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul
{
    int nilai;
    char nama[50];
    Node *next;
};

Node *head = NULL;
Node *p;

void pesan_alokasi();
void insert_akhir();
void tampil();
void del_akhir();
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
    puts("Hapus insert akhir");
    while (head != NULL)
    {
        del_akhir();
        tampil();
    }
    return 0;
}

void del_akhir()
{
    Node *del;
    Node *prev_del;

    del = head;
    if (del->next == NULL)
        head = NULL;
    else
    {
        while (del->next != NULL)
        {
            prev_del = del;
            del = del->next;
        }
        prev_del->next = NULL;
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
        printf ("Nama: %s\n", baca->nama);
        printf ("Nilai: %d\n", baca -> nilai);
        baca = baca->next;
    }
}
void pesan_alokasi()
{
    char nama [50];
    int nilai;

    printf("Nama mahasiswa: ");
    scanf("%s", nama);

    printf ("Nilai mahasiswa: ");
    scanf ("%d", &nilai);

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
