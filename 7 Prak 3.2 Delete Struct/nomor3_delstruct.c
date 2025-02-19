// del tertentu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul
{
    int nomor;
    int nilai;
    char nama[50];
    Node *next;
};
Node *head = NULL;
Node *p;

void pesan_alokasi();
void insert_akhir();
void tampil();
void del_random();

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
    puts("Hapus insert mana saja");
    fflush(stdin);
    del_random();
    tampil();

    return 0;
}

void del_random()
{
    Node *del;
    Node *prev_del;
    int nomor;

    printf("Pilih nomor mahasiswa berapa yang mau dihapus: ");
    scanf("%d", &nomor);
    del = head;
    prev_del = NULL;

    while (del != NULL && del -> nomor != nomor)
    {
        prev_del = del;
        del = del->next;
    }
    if (del == NULL)
    {
        printf("%d tidak ada di linked list", nomor);
        return;
    }
    if (prev_del == NULL)
    {
        head = del->next;
    }
    else
    {
        prev_del->next = del->next;
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
    }
}

void tampil()
{
    Node *baca;

    puts("Isi dari SLL setelah inputan user");
    baca = head;
    while (baca != NULL)
    {
        printf ("No: %d\n", baca -> nomor);
        printf ("Nama: %s\n", baca->nama);
        printf ("Nilai: %d\n", baca -> nilai);
        baca = baca->next;
    }
}

void pesan_alokasi()
{
    char nama [50];
    int nilai, nomor;

    printf("No: ");
    scanf("%d", &nomor);

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
        p->nomor = nomor;
        p -> next = NULL;
    }
}

/*void pesan_alokasi()
{
    char nama [50];
    int nilai;
    int nomor;

    printf("No: ");
    scanf("%d", &nomor);

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
        p->nomor = nilai;
        p -> next = NULL;
    }
} */
