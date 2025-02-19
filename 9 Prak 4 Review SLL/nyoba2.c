/*#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p, *tail, *prev, *current, *del;
int key, nilai, nilai_baru;

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
                printf("Pilihan tidak ada dalam menu\n");
                break;
        }
    } while (pilih >= 1 && pilih <= 3);

    return 0;
}

void insert() {
    printf("Masukkan data: ");
    scanf("%d", &nilai);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        printf("Gagal");
        exit(0);
    }

    p->data = nilai;
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        if (nilai < head->data) {
            p->next = head;
            head = p;
        } else {
            current = head;
            while (current->next != NULL && current->next->data < nilai) {
                current = current->next;
            }
            p->next = current->next;
            current->next = p;
        }
    }
}

void search() {
    int count = 0;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &key);

    current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
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

    current = head;
    prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            count++;
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
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
        puts("Linked List masih kosong");
        return;
    }

    printf("Isi dari Linked List: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}*/






















/*#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *head = NULL, *p, *tail, *prev, *current, *urut, *purut;
int key, nilai;

void pesan();
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
        break;
    case 3:
        pesan ();
        del   ();
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

    Node *p = (Node*) malloc (sizeof(Node));

    if (p != NULL){
        p->data = nilai;
        p->next = NULL;
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
            head = tail = p;
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
    Node *cari = head;
    if (head == NULL) {
        puts("LL masih kosong");
    } else {
        printf("Masukkan data yang ingin dicari: ");
        scanf("%d", &key);
        while (cari != NULL) {
            if (cari -> data == key) {
                printf("%d ada dalam LL", key);
                return;
            }
            cari = cari -> next;
        }
        printf("%d tidak ada dalam LL:v", key);
    }
}

void del() {
    Node *hapus;

    if (head == NULL) {
        puts("LL masih kosong");
    }

    // Implementasi penghapusan data
}

void tampil (){
    current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
*/
