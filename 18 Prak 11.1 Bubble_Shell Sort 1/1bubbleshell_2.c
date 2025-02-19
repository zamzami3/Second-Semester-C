#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20000

void bubble(int arr[], int size);
void shell(int arr[], int size);
void tukar(int *x, int *y);

void generate(int x[], int size);
void mode_urut(int arr[], int size);

int comparison, swapping, movement;

int main() {
    int array[MAX];
    time_t t1, t2;

    //puts("Bubble Short");
    puts ("Shell Short");

    time(&t1);

    generate(array, MAX);
    mode_urut(array, MAX);

    //bubble(array, MAX);
    shell (array, MAX);

    time(&t2);

    double waktukomputasi = difftime(t2, t1);

    printf("Waktu komputasi: %.2f detik\n", waktukomputasi);

    return 0;
}

void mode_urut(int arr[], int size) {
    int pilih;

    puts ("Pilih menu:");
    puts ("1. Ascending");
    puts ("2. Descending");

    printf("Pilihan Anda: ");
    scanf("%d", &pilih);

    if (pilih == 1) {
    } else if (pilih == 2) {
        for (int i = 0; i < size / 2; i++) {
            tukar(&arr[i], &arr[size - 1 - i]);
        }
    } else {
        printf("Pilihan tidak valid.\n");
        exit(1);
    }
}

void bubble(int arr[], int size) {
    int pos_akhir = size - 2, did_swap = 1;
    while (pos_akhir >= 0 && did_swap) {
        did_swap = 0;
        for (int i = 0; i <= pos_akhir; i++) {
            if (arr[i] > arr[i + 1]) {
                tukar(&arr[i], &arr[i + 1]);
                did_swap = 1;
                swapping++;
                movement++;
            }
            comparison++;
        }
        pos_akhir--;
    }
}

void shell(int arr[], int size) {
    int jarak, did_swap, i;
    jarak = size;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = 1;
        while (did_swap) {
            did_swap = 0;
            i = 0;
            while (i < size - jarak) {
                if (arr[i] > arr[i + jarak]) {
                    tukar(&arr[i], &arr[i + jarak]);
                    did_swap = 1;
                    swapping++;
                    movement++;
                }
                comparison++;
                i++;
            }
        }
    }
}

void tukar(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void generate(int x[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        x[i] = rand() % 1000;
    }
}
