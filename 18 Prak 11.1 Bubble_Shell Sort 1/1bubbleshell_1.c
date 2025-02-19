//prak 11.1

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void bubble();
void shell();
void tukar();
void tampil();

int array[MAX] = {5, 8, 3, 1, 9, 7, 2, 10, 6, 4};
int comparison, swapping, movement;

int main () {
    puts ("Algoritma Shell Sort");
    shell();

    puts("Setelah diurutkan");
    tampil();

    printf ("Total jumlah perbandingan: %d\n", comparison);
    printf ("Total jumlah penukaran: %d\n", swapping);
    printf ("Total jumlah pergeseran: %d\n", movement);
    return 0;
}

void bubble() {
    int pos_akhir = MAX - 2, did_swap = 1;
    while (pos_akhir >= 0 && did_swap) {
        did_swap = 0;
        comparison++;
        for (int i = 0; i <= pos_akhir; i++) {
            if (array[i] > array[i + 1]) {
                tukar(&array[i], &array[i + 1]);
                did_swap = 1;
                comparison++;
                swapping++;
                movement++;
            }
        }
        pos_akhir--;
        tampil();
    }
}



void shell() {
    int jarak, did_swap, i;
    jarak = MAX;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = 1;
        comparison++;
        swapping++;
        movement++;
        while (did_swap == 1) {
            did_swap = 0;
            i = 0;
            swapping++;
            movement++;
            while (i < MAX - jarak) {
                if (array[i] > array[i + jarak]) {
                    tukar(&array[i], &array[i + jarak]);
                    did_swap = 1;
                    comparison++;
                    swapping++;
                    movement++;
                }
                i++;
            }
        }
        tampil();
    }
}

void tukar(int *x, int *y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void tampil() {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }
    puts(" ");
}
