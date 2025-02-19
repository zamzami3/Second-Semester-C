#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

void pesan_alokasi ();
void tampil ();

void insert_awal ();
void insert_akhir ();
void insert_after ();
void insert_before ();

int main () {
    char jawab;
    int menu;

    puts ("Menu insert");
    puts ("1. Awal");
    puts ("2. Akhir");
    puts ("3. After");
    puts ("4. Before");
    puts ("5. Keluar");

    printf ("Masukkan pilihan anda : ");
    scanf ("%d", &menu);
    switch (menu) {
        case 1:
            do {
                fflush(stdin);
                pesan_alokasi ();
                insert_awal ();
                fflush (stdin);
                printf ("Ingin memasukkan nilai lagi (y/t)? ");
                jawab = getchar ();
            } while ((jawab == 'y') || (jawab == 'Y'));
            tampil ();
        break;
        case 2:
            do {
                fflush(stdin);
                pesan_alokasi();
                insert_akhir();
                fflush(stdin);
                printf ("Ingin memasukkan nilai lagi? (y/t) ");
                jawab = getchar();

            } while ((jawab == 'y') || (jawab =='Y'));
            tampil();
        break;
        case 3:
            do {
            fflush(stdin);
            pesan_alokasi();
            insert_akhir();
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
        break;
        case 4:
            do {
                pesan_alokasi ();
                insert_akhir ();
                fflush (stdin);
                printf ("Lagi (y/t)? ");
                jawab = getchar ();
            } while ((jawab == 'y') || (jawab == 'Y'));
            puts ("");
            tampil ();
            fflush(stdin);
            pesan_alokasi ();
            fflush(stdin);
            insert_before ();
            fflush(stdin);
            tampil ();
        break;
        case 5:
            exit(0);
        default:
            printf("Pilihan tidak ada dalam menu\n");
            exit(0);
        break;
        fflush(stdin);
        }
    return 0;
}

void insert_before () {
    Node *bef, *pbef;
    int key;

    printf ("Disispkan sebelum node berapa? ");
    scanf ("%d", &key);
    bef = head;
    while (bef -> data != key) {
        if (bef -> next == NULL) {
            printf ("%d tdk ada dalam SLL\n", key);
            exit (0);
        } else {
            pbef = bef;
            bef = bef -> next;
        }
    }
    p -> next = bef;
    pbef -> next = p;
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

void insert_akhir () {
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

    puts ("Isi dari SLL");
    baca = head;
    while (baca != NULL) {
        printf ("%d\n", baca -> data);
        baca = baca -> next;
    }
}

void pesan_alokasi () {
    int x;

    printf ("Data yg mau disimpan ");
    scanf ("%d", &x);
    p = (Node*) malloc (sizeof (Node));
    if (p == NULL) {
        puts ("Alokasi gagal");
        exit (0);
    } else {
        p -> data = x;
        p -> next = NULL;
    }
}

void insert_awal () {
    if (head != NULL) {
        p -> next = head;
    }
    head = p;
}
