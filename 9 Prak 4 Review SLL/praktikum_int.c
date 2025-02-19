#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p, *prev, *posisi;
int key, nilai;

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
                printf("Pilihan tidak ada dalam menu:> Anda keluar");
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
        printf("Eits, Alokasi gagal");
        exit(0);
    }

    p->data = nilai;
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        if (nilai < head -> data) {
            p -> next = head;
            head = p;
        } else {
            posisi = head;
            while (posisi -> next != NULL && posisi -> next < nilai) {
                posisi = posisi -> next;
            }
            p -> next = posisi -> next;
            posisi -> next = p;
        }
    }
}

void search() {
    int hitung = 0;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &key);

    posisi = head;
    while (posisi != NULL) {
        if (posisi -> data == key) {
            hitung++;
        }
        posisi = posisi->next;
    }

    if (hitung > 0) {
        printf("Jumlah data %d ada %d dalam Linked List\n", key, hitung);
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
        if (posisi->data == key) {
            count++;
            if (prev == NULL) {
                head = posisi->next;
                free(posisi);
                posisi = head;
            } else {
                prev->next = posisi->next;
                free(posisi);
                posisi = prev->next;
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
        puts("Silahkan gunakan menu 1 terlebih dahulu");
        return;
    } else {
        printf("Isi dari Linked List: ");
        posisi = head;
        while (posisi != NULL) {
        printf("%d ", posisi -> data);
        posisi = posisi -> next;
    }
    }
    printf("\n");
}