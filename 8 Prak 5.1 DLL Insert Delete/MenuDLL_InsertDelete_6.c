#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *previous, *next;
};

Dnode *head = NULL, *p,  before, *after;

void dll_deleteawal();
void dll_deleteakhir();
void dll_deleterandom();

void dll_insertawal();
void dll_insertakhir();
void dll_insertafter();
void dll_insertbefore();

void pesantempat();
void insert_akhir();
void tampil();

void del_operation();
void case1_delete();
void case2_delete();
void case3_delete();

void insert_operation();
void case1_insert();
void case2_insert();
void case3_insert();
void case4_insert();

int main() {
    int pilih;

    puts("Menu Insert");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");

    printf("Masukkan menu pilihan anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
        insert_operation();
        break;
    case 2:
        del_operation();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan tidak ada dalam menu.\n");
        exit(0);
        break;
        fflush(stdin);
    }
    return 0;
}

void insert_operation() {
    int menu_insert;

    puts("Menu Insert");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");

    printf("Masukkan pilihan anda : ");
    scanf("%d", &menu_insert);

    switch (menu_insert) {
    case 1:
        case1_insert();
        break;
    case 2:
        case2_insert();
        break;
    case 3:
        case3_insert();
        break;
    case 4:
        case4_insert();
        break;
    default:
        printf("Pilihan tidak ada dalam menu\n");
        exit(0);
        break;
        fflush(stdin);
    }
}

void case1_insert() {

    puts ("\tDouble Linked List Insert Awal\t");
    fflush(stdin);
    pesantempat();
    dll_insertawal();
    fflush(stdin);
    tampil();
    main();
}

void case2_insert() {

    puts ("\tDouble Linked List Insert Akhir\t");
    fflush(stdin);
    pesantempat();
    dll_insertakhir();
    fflush(stdin);
    tampil();
    main();
}

void case3_insert() {

    puts ("\tDouble Linked List Insert After\t");
    fflush (stdin);
    pesantempat();
    fflush (stdin);
    dll_insertafter();
    tampil();
    main();
}

void case4_insert() {

    puts ("\tDouble Linked List Insert Before\t");
    fflush (stdin);
    pesantempat();
    fflush (stdin);
    dll_insertbefore();
    tampil();
    main();
}

void del_operation() {
    int menu_delete;

    puts("Menu Delete");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Tertentu");
    puts("4. Keluar");

    printf("Masukkan pilihan anda : ");
    scanf("%d", &menu_delete);

    switch (menu_delete)
    {
    case 1:
        case1_delete();
        break;
    case 2:
        case2_delete();
        break;
    case 3:
        case3_delete();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Pilihan tidak ada dalam menu\n");
        exit(0);
        break;
        fflush(stdin);
    }
}

void case1_delete() {
    char jawab;

    puts("\tDouble Linked List Delete Awal");
    while (head != NULL)
    {
        dll_deleteawal();
        tampil();
        main();
    }
}

void case2_delete() {
    char jawab;

    puts("\tDouble Linked List Delete Akhir\t");
    while (head != NULL)
    {
        dll_deleteakhir();
        tampil();
        main();
    }
}

void case3_delete() {
    char jawab;

    puts("\tDouble Linked List Delete Random\t");
    dll_deleterandom();
    tampil();
    main();
}

void dll_deleteawal() {
    Dnode *del;

    del = head;

    head = del -> next;
    head -> previous = NULL;
    free(del);
    del = NULL;
}

void dll_deleteakhir() {
    Dnode *del;

    del = head;

    while (del -> next != NULL) {
        del = del -> next;
    }
    del -> previous -> next = NULL;
    free(del);
    del = NULL;
}

void dll_deleterandom() {
    Dnode *del;
    int key;

    printf ("Silahkan pilih data mana yang mau dihapus: ");
    scanf ("%d", &key);

    del = head;

    while (del -> data != key) {
        if (del -> next == NULL) {
            printf ("%d tidak ada dalam DLL\n", key);
        } else {
            del = del -> next;
        }
    }
    del -> previous -> next = del -> next;
    del -> next -> previous = del -> previous;
    free (del);
    del = NULL;
}

void tampil() {
    Dnode *read;

    puts ("Isi dari DLL: ");
    read = head;

    while (read != NULL) {
        printf ("%d\n", read -> data);
        read = read -> next;
    }
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

void dll_insertawal() {
    if (head != NULL) {
        p -> next = head;
        head -> previous = p;
    }
    head = p;
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

void dll_insertafter() {
    int key;

    printf ("Mau di taruh setelah node ke berapa? ");
    scanf ("%d", &key);

    after = head;
    while (after -> data != key) {
        if (after -> next == NULL) {
            printf ("%d tidak ada", key);
            exit (0);
        } else {
            after = after -> next;
        }
    }
    if (after->next != NULL) {
        p -> next = after -> next;
        after -> next -> previous = p;
    }
    p -> previous = after;
    after -> next = p;
}

void dll_insertbefore() {
    Dnode *before;
    int key;

    printf ("Mau di taruh before node ke berapa? ");
    scanf ("%d", &key);

    before = head;

    if (head -> data == key) {
        dll_insertawal();
    } else {
        while (before -> data != key) {
            if (before -> next == NULL) {
                printf ("%d tidak ada", key);
                exit (0);
            } else {
                before = before -> next;
            }
        }
    p -> next = before;
    p -> previous = before -> previous;
    before -> previous -> next = p;
    before -> previous = p;
    }
}
