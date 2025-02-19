// review sll dll

#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *head=NULL, *tail=NULL, *p, *ph;


void alokasi();
void tampil();
void menu();
void insert();
void cari();
void delete();
void bebas(Node *);
void sorted(int value);


int main(){
    char jawab;
    printf("SINGLE LINKED LIST - MENU\n");
    while(1){
        menu();
        printf("\n");
    }
    return 0;
}


void menu(){
    int jawab;


    printf("PILIH MENU DIBAWAH INI: \n");
    printf("1. Masukkan Data \n");
    printf("2. Cari data \n");
    printf("3. Hapus data \n");
    printf("4. Keluar \n");
    printf("Masukkan pilihan:");
    scanf("%d", &jawab);


    switch(jawab){
        case 1:
            insert();
            break;
        case 2:
            cari();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(0);
        default:
            printf("Pilihan yang anda masukkan tidak valid");
    }
}


void alokasi() {
    int value;


    printf("Nilai yg ingin disimpan:");
    scanf("%d", &value);
    p = (Node*) malloc(sizeof(Node));
    if(p == NULL){
        puts("Alokasi gagal");
        exit(0);
    }else{
        p->data = value;
        p->next = NULL;
    }
}


void bebas(Node *x){
    free(x);
    x = NULL;
}


void tampil(){
    Node *baca;


    puts("Data yang ada didalam SLL:");
    baca = head;
    while(baca != NULL){
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}


void sorted(int value) {
    Node *newNode;
    Node *prev;
    Node *current;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        return;
    }


    current = head;
    prev = NULL;


    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }


    newNode->next = current;
    if (prev == NULL) {
        head = newNode;
    } else {
        prev->next = newNode;
    }
}




void insert(){
    alokasi();

    sorted(p->data);


    tampil();
}


void delete(){
    int x;
    Node *hapus;


    printf("Nilai yang ingin dihapus: ");
    scanf("%d", &x);
    hapus = head;
    while(hapus != NULL && hapus->data != x){
        ph = hapus;
        hapus = hapus->next;
    }


    if(hapus == NULL){
        puts("Nilai yang ingin dihapus tidak ada didalam SLL");
        exit(0);
    }else{
        if(hapus == head){
            head = hapus->next;
        } else{
            ph->next = hapus->next;
        }
        bebas(hapus);
    }
    tampil();
}


void cari() {
    int nilai;
    int jumlah = 0;
    Node *current;


    printf("Masukkan nilai yang ingin dicari:");
    scanf("%d", &nilai);


    current = head;


    while (current != NULL) {
        if (current->data == nilai) {
            jumlah++;
        }
        current = current->next;
    }


    if (jumlah == 0) {
        printf("%d tidak ditemukan dalam SLL\n", nilai);
    } else {
        printf("%d ada %d kali didalam SLL\n", nilai, jumlah);
    }
}


/*#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *head = NULL, *p, *tail, *prev, *current, *urut, *purut;
int key, nilai, nilai_baru;

void tampil();
void insert();
void search();
void del();

int main () {
    int pilih;

    puts ("1. Masukkan data terurut");
    puts ("2. Cari data dalam Linked List");
    puts ("3. Hapus data dalam Linked List");

    printf ("Masukkan pilihan: ");
    scanf ("%d", &pilih);

    switch (pilih) {
    case 1 :
        pesan ();
        insert();
        tampil();
        break;
    case 2:
        pesan ();
        search();
        tampil();
        break;
    case 3:
        pesan ();
        del   ();
        tampil();
        break;
    default:
        puts ("Pilihan tidak ada di dalam menu");
        exit (0);
        break;
    }
    return 0;
}

void pesan() {

    printf ("Masukkan data: ");
    scanf ("%d", &nilai);

    p = (Node*) malloc (sizeof(Node));

    if (p != NULL){
        p -> data = nilai;
        p -> next = NULL;
    } else {
        printf ("Gagal");
        exit (0);
    }
}


void insert() {
    int nilai;
    char jawab;
    do {
        printf("Masukkan data: ");
        scanf("%d", &nilai);

        pesan();

        printf("Masukkan data lagi(y/t)?: ");
        scanf(" %c", &jawab);

        if (head == NULL) {
            head = p;
        } else if (head != NULL && head -> next == NULL) {
            urut = head;
            if (urut -> data > p -> data) {
                p -> next = urut;
                head = p;
            } else {
                p -> next = urut -> next;
                urut -> next = p;
            }
        } else {
            urut = head;
            if (urut->data < p->data) {
                while (urut->data < p->data) {
                    if(urut->next != NULL){
                      purut = urut;
                      urut = urut->next;
                    }else{
                        break;
                    }
                }
                if(urut->data > p->data){
                    p->next = urut;
                    purut->next = p;
                }else{
                    urut->next = p;
                }
            } else {
                p->next = urut;
                head = p;
            }
        }
    } while (jawab == 'Y' || jawab == 'y');
    tampil();
}

void search() {
    int key;
    Node *cari;
    if (head == NULL) {
        puts("LL masih kosong");
    } else {
        while (cari != key) {
            cari = cari -> data;
            if (cari -> next != NULL){
                if (key > 1) {
                    printf ("Di dalam LL dengan %d > 1", key);
                } else if (key = 1) {
                    printf ("%d ada dalam LL", key);
                }
            } else {
                printf ("%d tidak ada dalam LL:v");
            }
        }
    }
    main ();
}

void del() {
    Node *hapus;

    if (head == NULL) {
        puts("LL masih kosong");
    }

    main ();
}

void tampil (){
    int nilai;
    Node *nilai_baru;

    if (head == NULL || head->data > nilai) {
        nilai_baru->next = head;
        head = nilai_baru;
    } else {
        while (current != NULL && current->data < nilai) {
            prev = current;
            current = current->next;
        }
        prev->next = nilai_baru;
        nilai_baru->next = current;
    }
    main ();
} */

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    char nama[50];
    int data;
    Node *next;
};

Node *head = NULL, *p, *prev, *posisi;
int key, nilai;
//char nama[50];

void tampil();
void insert();
void search();
void hapus();

int main() {
    int pilih;

    do {
        puts("1. Masukkan data terurut");
        puts("2. Cari data dalam linked list");
        puts("3. Hapus data dalam linked list");
        printf("Masukkan pilihan user: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                insert();
                tampil();
                break;
            case 2:
                search();
                tampil();
                break;
            case 3:
                hapus();
                tampil();
                break;
            default:
                printf("Pilihan tidak ada dalam menu, anda keluar.\n");
                break;
        }
    } while (pilih >= 1 && pilih <= 3);

    return 0;
}

void insert() {
    char nama[50];
    printf("Masukkan data: ");
    scanf("%d", &nilai);

    printf("Masukkan nama: ");
    scanf("%s", p->nama);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        printf("Alokasi gagal");
        exit(0);
    }

    p->data = nilai;
    strcpy(p->nama, nama);
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        if (nilai < head->data) {
            p->next = head;
            head = p;
        } else {
            posisi = head;
            while (posisi->next != NULL && posisi->next->data < nilai) {
                posisi = posisi->next;
            }
            p->next = posisi->next;
            posisi->next = p;
        }
    }
}

void search() {
    int count = 0;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &key);

    posisi = head;
    while (posisi != NULL) {
        if (posisi->data == key) {
            count++;
        }
        posisi = posisi->next;
    }

    if (count > 0) {
        printf("Jumlah data %d ada %d dalam Linked List\n", key, count);
    } else {
        printf("Tidak ada data %d dalam Linked List\n", key);
    }
}

void hapus() {
    int count = 0;
    printf("Masukkan data yang mau dihapus: ");
    scanf("%d", &key);

    posisi = head;
    prev = NULL;

    while (posisi != NULL) {
        if (posisi -> data == key) {
            count++;
            if (prev == NULL) {
                head = posisi -> next;
                free(posisi);
                posisi = head;
            } else {
                prev -> next = posisi -> next;
                free(posisi);
                posisi = prev -> next;
            }
        } else {
            prev = posisi;
            posisi = posisi -> next;
        }
    }

    if (count == 0) {
        printf("Tidak ada data %d dalam Linked List\n", key);
    } else {
        printf("Data %d berhasil dihapus dari Linked List\n", key);
    }
}

void tampil() {
    if (head == NULL) {
        puts("Linked List masih kosong:v");
        puts("Silahkan isi Linked List menggunakan opsi 1");
        return;
    } else {
        printf("Isi dari Linked List:\n");
        posisi = head;
        while (posisi != NULL) {
            printf("%d %s\n", posisi->data, posisi->nama);
            posisi = posisi->next;
        }
    }
} */
