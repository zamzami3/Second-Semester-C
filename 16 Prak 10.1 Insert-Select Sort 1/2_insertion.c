#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion();
void tampil();

int c, m; //c = geser, m = banding
int array[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main () {
    puts ("Algoritma sorting menggunakan Insertion Sort");
    insertion();

    puts ("Setelah di urutkan: ");
    tampil();

    printf ("Pergeseran = %d Perbandingan = %d\n", c, m);

    return 0;
}

void insertion () {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = array[i];
        m++;
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            m++;
            c++;
            j--;
        }
        array[j + 1] = key;
        puts(" ");
        tampil();
        m++;
    }
}

void tampil () {
    for (int i = 0; i < MAX; i++) {
        printf ("%d ", array[i]);
    }
    puts (" ");
}
