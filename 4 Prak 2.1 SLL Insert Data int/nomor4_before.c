#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    struct Node *next;
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

    while (bef -> data != key) {
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

    puts ("Nilai dlm SLL inputan user");
    baca = head;
    while (baca != NULL) {
        Node *after;
    int key;

    printf ("Disisipkan setelah node berapa? ");
    scanf ("%d", &key);

    after = head;

    while (after != NULL && after -> nama != key) {
        after = after -> next;
    }

    if (after == NULL) {
        printf ("%d tidak ada dalam SLL\n", key);
        exit (0);
    }

    p -> next = after -> next;
    after -> next = p;
    }
}

void pesan_alokasi () {
    int x;

    printf ("Nilai yg mau disimpan ");
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

































/*#include <stdio.h>

typedef struct Node{
    int data;
    int *next;
//    Node *next;
};

int main () {

    do {
        int input_data;
        char jawab;

        printf ("Berikan data yang akan dimasukkan dalam SLL: ");
        scanf ("%d", &input_data);

        //before ();

        printf ("Apakah ingin menambah data? (y/t) ");
        scanf ("%c", &jawab);
        fflush (stdin);

    } while (jawab == 'y' || jawab == 'Y');
        lanjut ();

    printf ("isi SLL yang sudah dimasukkan %d", );

}

void before () {
    int
}

void lanjut
*/
