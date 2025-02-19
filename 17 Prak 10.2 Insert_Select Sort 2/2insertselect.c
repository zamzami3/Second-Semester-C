//insert select sorting 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa {
    int no;
    char nama[256];
    char nilai;
};

void insertion(struct siswa Data[10]);
void selection(struct siswa Data[10]);
void tampil(struct siswa Data[10]);

void simpandataSiswa(struct siswa Data[10]);
int modeUrut();

int sorting = 1;

int main () {
    struct siswa Data[10];
    int pilih1, pilih2;

    simpandataSiswa(Data);

    do {
        puts ("MENU METODE SORTING");
        puts ("1. Insertion Sort");
        puts ("2. Selection Sort");
        puts ("3. Keluar");

        printf ("Pilihan anda [1/2/3]: ");
        scanf ("%d", &pilih1);

        if (pilih1 == 1 || pilih1 == 2) {
            pilih2 = modeUrut();

            if (pilih1 == 1) {
                if (pilih2 == 1) {
                    puts ("Insertion Sort Pengurutan Ascending");
                } else if (pilih2 == 2) {
                    puts ("Insertion Sort Pengurutan Descending");
                    sorting = 2;
                }
                insertion(Data);
                tampil(Data);
            } else if (pilih1 == 2) {
                if (pilih2 == 1) {
                    puts ("Selection Sort Pengurutan Ascending");
                } else if (pilih2 == 2) {
                    puts ("Selection Sort Pengurutan Descending");
                    sorting = 2;
                }
                selection(Data);
                tampil(Data);
            }
        } else {
            puts ("Anda keluar");
            exit (0);
        }
    } while (pilih1 != 3);
    return 0;
}


int modeUrut () {
    int pilih2;

    puts ("Pengurutan yang dipilih:");
    puts ("1. Ascending");
    puts ("2. Descending");

    printf ("Pilihan anda [1/2]: ");
    scanf ("%d", &pilih2);

    return pilih2;
}

void simpandataSiswa(struct siswa Data[]) {
    puts ("Ayo Mengisi Data^_^");
    puts ("Masukkan sebanyak 10 data siswa");

    for (int i = 0; i < 10; i++) {
        printf ("Data siswa ke %d\n", i + 1);
        printf ("No: ");
        scanf ("%d", &Data[i].no);

        printf ("Nama: ");
        scanf ("%s", Data[i].nama);

        printf ("Nilai [A/B/C]: ");
        scanf (" %c", &Data[i].nilai);
    }
}

void insertion (struct siswa Data[10]) {
    int i, j;
    struct siswa key;

    for (i = 1; i < 10; i++) {
        key = Data[i];
        j = i - 1;

       if (sorting == 1) {
            while (j >= 0 && Data[j].no > key.no) {
                Data[j + 1] = Data[j];
                j--;
            }
        } else if (sorting == 2) {
            while (j >= 0 && Data[j].no < key.no) {
                Data[j + 1] = Data[j];
                j--;
            }
        }
        Data[j + 1] = key;
    }
}

void selection (struct siswa Data[10]) {
    int i, j, min;
    struct siswa tampung;
    for (i = 0; i < 10 - 1; i++) {
        min = i;
        for (j = i + 1; j < 10; j++){
            if (sorting == 1) {
                if (Data[j].no < Data[min].no)
                    min = j;
            }
            if (sorting == 2) {
                if (Data[j].no > Data[min].no) {
                    min = j;
                }
            }
        }
        //tukar
        tampung = Data[min];
        Data[min] = Data[i];
        Data[i] = tampung;
    }
}

void tampil (struct siswa Data[]) {
    printf ("Data siswa:\n");
    printf ("No\tNama\t\tNilai\n");
    for (int i = 0; i < 10; i++) {
        printf ("%d\t%s\t\t%c\n", Data[i].no, Data[i].nama, Data[i].nilai);
    }
    puts (" ");
}
