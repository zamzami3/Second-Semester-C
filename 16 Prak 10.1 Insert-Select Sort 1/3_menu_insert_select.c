#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void case_insertion();
void case_selection();
void insertion();
void selection();
void tampil();
void tukar();

int array[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
int c, m;
int sorting = 1;

int main () {
    int menu, pilih;

    puts ("MENU METODE SORTING");
    puts ("1. Insertion Sort");
    puts ("2. Selection Sort");
    puts ("3. Keluar");

    printf ("Pilihan Anda: ");
    scanf ("%d", &menu);

    if (menu == 1 || menu == 2) {
        puts ("MENU METODE SORTING");
        puts ("1. Ascending");
        puts ("2. Descending");

        printf ("Masukkan pilihan Anda: ");
        scanf ("%d", &pilih);

        if (menu == 1 && pilih == 1) {
            puts ("Insertion Sort Ascending");
            case_insertion();
        } else if (menu == 1 && pilih == 2) {
            puts ("Insertion Sort Descending");
            sorting = 2;
            case_insertion();
        } else if (menu == 2 && pilih == 1) {
            puts ("Selection Sort Ascending");
            case_selection();
        } else if (menu == 2 && pilih == 2) {
            puts ("Selection Sort Descending");
            sorting = 2;
            case_selection();
        } else {
            printf ("Pilihan tidak ada dalam menu, coba lagi");
            exit (0);
        }
    } else {
        puts ("Anda keluar");
        exit(0);
    }
    return 0;
}

void case_insertion() {
    puts ("Algoritma sorting menggunakan Insertion Sort");
    insertion();
    puts ("Setelah di urutkan: ");
    tampil();
    printf ("Pergeseran = %d Perbandingan = %d\n", c, m);
}

void case_selection() {
    puts ("Algoritma sorting menggunakan Selection Sort");
    selection();
    puts ("Setelah di urutkan: ");
    tampil();
    printf ("Pertukaran = %d Perbandingan = %d\n", c, m);
}

void insertion () {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && ((sorting == 1 && array[j] > key) || (sorting == 2 && array[j] < key))) {
            array[j + 1] = array[j];
            j--;
            c++;
            m++;
        }
        array[j + 1] = key;
        c++;
        tampil();
    }
}

void selection () {
    int i, j, min, kondisi;
    for (i = 0; i < MAX - 1; i++) {
        min = i;
        for (j = i + 1; j < MAX; j++){
            if ((sorting == 1 && array[j] < array[min]) || (sorting == 2 && array[j] > array[min])) {
                min = j;
            }
            m++;
        }
        if (min != i) {
            tukar(&array[i], &array[min]);
            c++;
        }
        c++;
        tampil();
    }
}

void tampil () {
    for (int i = 0; i < MAX; i++) {
        printf ("%d ", array[i]);
    }
    puts (" ");
}

void tukar (int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
}
