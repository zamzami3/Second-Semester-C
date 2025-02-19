// menu delete int

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

void del_awal();
void del_akhir();
void del_random();

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();

void pesan_alokasi();
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

int main()
{
    int pilih;

    puts("Menu Insert");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");

    printf("Masukkan menu pilihan anda: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
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
        printf("Pilihan tidak ada dalam menu\n");
        exit(0);
        break;
        fflush(stdin);
    }

    return 0;
}

void insert_operation()
{
    int menu_insert;

    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    puts("5. Keluar");

    printf("Masukkan pilihan anda : ");
    scanf("%d", &menu_insert);

    switch (menu_insert)
    {
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
    case 5:
        exit(0);
        break;
    default:
        printf("Pilihan tidak ada dalam menu\n");
        exit(0);
        break;
        fflush(stdin);
    }
}

void case1_insert()
{
    char jawab;
    do
    {
        pesan_alokasi();
        insert_awal();
        fflush(stdin);
        printf("Ingin memasukkan data lagi (y/t)? ");
        jawab = getchar();
        fflush(stdin);
    } while ((jawab == 'y') || (jawab == 'Y'));
    tampil();
    //main();
}

void case2_insert()
{
    char jawab;
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
    //main();
}

void case3_insert()
{
    char jawab;

    puts("Insert after node tertentu");
    pesan_alokasi();
    fflush(stdin);
    insert_after();
    tampil();
    //main();
}

void case4_insert()
{
    char jawab;

    pesan_alokasi();
    fflush(stdin);
    insert_before();
    fflush(stdin);
    tampil();
    //main();
}

void del_operation()
{
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

void case1_delete()
{
    char jawab;

    puts("Hapus insert awal");
    while (head != NULL)
    {
        del_awal();
        tampil();
        //main();
    }
}

void case2_delete()
{
    char jawab;

    puts("Hapus insert akhir");
    while (head != NULL)
    {
        del_akhir();
        tampil();
        //main();
    }
}

void case3_delete()
{
    char jawab;

    puts("Hapus insert mana saja");
    //fflush(stdin);
    del_random();
    tampil();
    //main();
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

void del_random()
{
    Node *del;
    Node *prev_del;
    int key;

    printf("Pilih data yang mau dihapus: ");
    scanf("%d", &key);
    del = head;
    if (del->data == key)
    {
        del_awal();
    }
    else
    {
        while (del->data != key)
        {
            if (del->next == NULL)
            {
                printf("%d tdk ada di linked list", key);
                exit(0);
            }
            else
            {
                prev_del = del;
                del = del->next;
            }
        }
        prev_del->next = del->next;
    }
    free(del);
    del = NULL;
}

void tampil() {
    Node *baca;

    puts("Isi dari SLL setelah inputan user");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    main();
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

void insert_awal()
{
    if (head != NULL)
        p->next = head;
    head = p;
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

void insert_after()
{
    Node *after;
    int key;

    printf("Disisipkan setelah node berapa? ");
    scanf("%d", &key);

    after = head;

    while (after != NULL && after->data != key)
    {
        after = after->next;
    }

    if (after == NULL)
    {
        printf("%d tidak ada dalam SLL\n", key);
        exit(0);
    }

    p->next = after->next;
    after->next = p;
}

void insert_before()
{
    Node *bef, *pbef;
    int key;

    printf("Diletakkan sebelum node berapa? ");
    scanf("%d", &key);

    bef = head;

    while (bef->data != key)
    {
        if (bef->next == NULL)
        {
            printf("%d tidak ada dalam SLL\n", key);
            exit(0);
        }
        else
        {
            pbef = bef;
            bef = bef->next;
        }
    }
    p->next = bef;
    pbef->next = p;
}
