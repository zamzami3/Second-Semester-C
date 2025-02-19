/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    char nama[50];
    int data, nilai_mhs;
    Node *next;
};

Node *head = NULL, *p, *prev, *posisi;
int key, nilai;

void tampil();
void insert();
void search();
void hapus();
void rata_rata();

int main() {
    int pilih;

    do {
        puts("1. Masukkan data terurut");
        puts("2. Cari data dalam linked list");
        puts("3. Hapus data dalam linked list");
        puts("4. Nilai rata-rata kelas");

        printf("Masukkan pilihan user: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                insert();
                tampil();
                printf ("\n");
                break;
            case 2:
                search();
                tampil();
                printf ("\n");
                break;
            case 3:
                hapus();
                tampil();
                printf ("\n");
                break;
            case 4:
                rata_rata();
                tampil();
                printf ("\n");
            default:
                printf("Pilihan tidak ada dalam menu, Anda keluar:v\n");
                break;
        }
    } while (pilih >= 1 && pilih <= 3);

    return 0;
}

void insert() {
    char nama[50];
    int nilai_mhs;

    printf("No: ");
    scanf("%d", &nilai);

    printf("Nama: ");
    scanf("%s", nama);

    printf("Nilai: ");
    scanf("%d", &nilai_mhs);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        printf("Alokasi gagal");
        exit(0);
    }

    p -> data = nilai;
    strcpy (p -> nama, nama);
    p -> next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        if (nilai < head->data) {
            p->next = head;
            head = p;
        } else {
            posisi = head;
            while (posisi -> next != NULL && posisi -> next -> data < nilai) {
                posisi = posisi -> next;
            }
            p -> next = posisi -> next;
            posisi -> next = p;
        }
    }
}

void search() {
    int count = 0;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &key);

    posisi = head;
    while (posisi != NULL) {
        if (posisi -> data == key) {
            count++;
        }
        posisi = posisi -> next;
    }

    if (count > 0) {
        printf("Jumlah data %d ada %d dalam Linked List:>\n", key, count);
    } else {
        printf("Tidak ada data %d dalam Linked List:<\n", key);
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
                prev->next = posisi -> next;
                free(posisi);
                posisi = prev -> next;
            }
        } else {
            prev = posisi;
            posisi = posisi -> next;
        }
    }

    if (count == 0) {
        printf("Tidak ada data %d dalam Linked List:<\n", key);
    } else {
        printf("Data %d berhasil dihapus dari Linked List:>\n", key);
    }
}

void rata_rata() {
}

void tampil() {
    if (head == NULL) {
        puts("Linked List masih kosong:v");
        puts("Silahkan isi Linked List menggunakan opsi 1:D");
    } else {
        printf("Isi dari Linked List:\n");
        posisi = head;
        puts ("No.\t Nama\t Nilai\t");
        while (posisi != NULL) {
            printf("%d.\t %s\t %d\n", posisi -> data, posisi -> nama, posisi -> nilai_mhs);
            posisi = posisi -> next;
        }
    }
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    char nama[50];
    int data, nilai_mhs;
    Node *next;
};

Node *head = NULL, *p, *prev, *posisi;
int key, nilai;

void tampil();
void insert();
void search();
void hapus();
void rata_rata();

int main() {
    int pilih;

    do {
        puts("1. Masukkan data terurut");
        puts("2. Cari data dalam linked list");
        puts("3. Hapus data dalam linked list");
        puts("4. Nilai rata-rata kelas");

        printf("Masukkan pilihan user: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                insert();
                tampil();
                printf ("\n");
                break;
            case 2:
                search();
                tampil();
                printf ("\n");
                break;
            case 3:
                hapus();
                tampil();
                printf ("\n");
                break;
            case 4:
                rata_rata();
                printf ("\n");
                break;
            default:
                printf("Pilihan tidak ada dalam menu, Anda keluar:v\n");
                break;
        }
    } while (pilih >= 1 && pilih <= 4);

    return 0;
}

void insert() {
    char nama[50];
    int nilai_mhs;

    printf("No: ");
    scanf("%d", &nilai);

    printf("Nama: ");
    scanf("%s", nama);

    printf("Nilai: ");
    scanf("%d", &nilai_mhs);

    p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        printf("Alokasi gagal");
        exit(0);
    }

    p -> data = nilai;
    p -> nilai_mhs = nilai_mhs;
    strcpy (p -> nama, nama);
    p -> next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        if (nilai < head->data) {
            p->next = head;
            head = p;
        } else {
            posisi = head;
            while (posisi -> next != NULL && posisi -> next -> data < nilai) {
                posisi = posisi -> next;
            }
            p -> next = posisi -> next;
            posisi -> next = p;
        }
    }
}

void search() {
    int count = 0;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &key);

    posisi = head;
    while (posisi != NULL) {
        if (posisi -> data == key) {
            count++;
        }
        posisi = posisi -> next;
    }

    if (count > 0) {
        printf("Jumlah data %d ada %d dalam Linked List:>\n", key, count);
    } else {
        printf("Tidak ada data %d dalam Linked List:<\n", key);
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
                prev->next = posisi -> next;
                free(posisi);
                posisi = prev -> next;
            }
        } else {
            prev = posisi;
            posisi = posisi -> next;
        }
    }

    if (count == 0) {
        printf("Tidak ada data %d dalam Linked List:<\n", key);
    } else {
        printf("Data %d berhasil dihapus dari Linked List:>\n", key);
    }
}

void rata_rata() {
    if (head == NULL) {
        printf("Linked List masih kosong:v\n");
        return;
    }

    int total_nilai = 0;
    int total_siswa = 0;

    posisi = head;
    while (posisi != NULL) {
        total_nilai += posisi->nilai_mhs;
        total_siswa++;
        posisi = posisi->next;
    }

    float rata_rata = (float)total_nilai / total_siswa;
    printf("Nilai rata-rata kelas: %.2f\n", rata_rata);
}

void tampil() {
    if (head == NULL) {
        puts("Linked List masih kosong:v");
        puts("Silahkan isi Linked List menggunakan opsi 1:D");
    } else {
        printf("Isi dari Linked List:\n");
        posisi = head;
        puts ("No.\t Nama\t Nilai\t");
        while (posisi != NULL) {
            printf("%d.\t %s\t %d\n", posisi -> data, posisi -> nama, posisi -> nilai_mhs);
            posisi = posisi -> next;
        }
    }
}
