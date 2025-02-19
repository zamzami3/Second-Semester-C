/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul
{
    char nama [50];
    int nilai;
    Node *next;
};
Node *head = NULL;
Node *p;

void pesan_alokasi();
void insert_akhir();
void tampil();
void del_awal();

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
    scanf("%d", &nama);

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
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul
{
    char nama [50];
    float nilai;
    Node *next;
};
Node *head = NULL;
Node *p;

void pesan_alokasi();
void insert_akhir();
void tampil();
void del_awal();
void del_akhir();

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
        scanf(" %c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    puts("Hapus insert awal");
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
        free(del);
        del = NULL;
    }
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
        printf ("Nilai: %.2f\n", baca -> nilai);
        baca = baca->next;
    }
}

void pesan_alokasi()
{
    char nama [50];
    float nilai;

    printf("Nama mahasiswa: ");
    scanf("%s", nama);

    printf ("Nilai mahasiswa: ");
    scanf ("%f", &nilai);

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




/*#include <stdio.h>
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
void del_awal();

int main()
{
    char jawab, jwb;
    printf("Insert Akhir\n");
    do
    {
        fflush(stdin);
        pesan_alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Ingin memasukkan data lagi? (y/t) ");
        jawab = getchar();
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    fflush (stdin);
    printf ("Mau menghapus node pertama? ");
    scanf ("%d", &jwb);
        if (jwb == 'y' || jwb == 'Y') {
            puts ("Menghapus simpul pertama dari list...");
            fflush (stdin);
            del_awal();
            tampil();
        } else {
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
        free(del);
        del = NULL;
    }
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
} */
