#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void selection();
void tukar(int *, int *);
void tampil();

int c, m; //c tukar, m banding
int array1[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main () {
    puts ("Algoritma sorting menggunakan Selection Sort");
    selection();

    puts ("Setelah di urutkan: ");
    tampil();
    printf ("Pertukaran = %d Perbandingan = %d\n", c, m);

    return 0;
}

void selection () {
    int i, j, key, min, temp;
    for (i = 0; i < MAX - 1; i++) {
        min = i;
        for (j = i + 1; j < MAX; j++){
                m++;
            if (array1[j] < array1[min]){
                min = j;
            }
        }
        puts(" ");
        tampil();
        tukar(&array1[i], &array1[min]);
        c++;
    }
    puts (" ");
}

void tampil () {
    for (int i = 0; i < MAX; i++) {
        printf ("%d ", array1[i]);
    }
    puts (" ");
}

void tukar (int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
}
