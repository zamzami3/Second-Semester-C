#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void insertion(int arr[], int size);
void selection(int arr[], int size);
void bubble(int arr[], int size);
void shell(int arr[], int size);
void tukar(int *x, int *y);
void generate(int x[], int size);

void mode_urut(int arr[], int size);
void tampil(int arr[], int size);
void menu();
void jumlahdata();

int comparison = 0, swapping = 0, movement = 0;
int jml, pilihmenu;

int main() {
    int array[MAX];
    int pilihmode;

    jumlahdata();
    generate(array, jml);
    menu();
    if (pilihmenu != 5) {
        mode_urut(array, jml);
    }
    time_t t1, t2;
    time(&t1);

    switch (pilihmenu) {
        case 1:
            insertion(array, jml);
            break;
        case 2:
            selection(array, jml);
            break;
        case 3:
            bubble(array, jml);
            break;
        case 4:
            shell(array, jml);
            break;
        case 5:
            printf("Anda Keluar\n");
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
            exit(0);
    }

    time(&t2);

    double waktukomputasi = difftime(t2, t1);
    printf("Durasi = %.3f detik\n", waktukomputasi);

    return 0;
}

void menu() {
    puts ("Menu Sorting");
    puts ("1. Insertion");
    puts ("2. Selection");
    puts ("3. Bubble");
    puts ("4. Shell");
    puts ("5. Keluar");
    printf ("Pilihan Anda: ");
    scanf ("%d", &pilihmenu);
}

void jumlahdata() {
    printf("Berapa jumlah data (maks %d)? ", MAX);
    scanf("%d", &jml);

    if (jml > MAX || jml < 1) {
        puts ("Jumlah data tidak valid.");
        puts ("Silakan coba lagi.");
        exit(0);
    }
}

void mode_urut(int arr[], int size) {
    int pilih;

    puts ("Mode Urut");
    puts ("1. Ascending");
    puts ("2. Descending");
    printf ("Pilihan Anda: ");
    scanf ("%d", &pilih);

    if (pilih == 2) {
        for (int i = 0; i < size / 2; i++) {
            tukar(&arr[i], &arr[size - 1 - i]);
        }
    } else if (pilih != 1) {
        puts ("Pilihan tidak valid.");
        exit(0);
    }
}

void insertion(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparison++;
            movement++;
        }
        arr[j + 1] = key;
        comparison++;
    }
}

void selection(int arr[], int size) {
    int i, j, min;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            movement++;
        }
        if (min != i) {
            tukar(&arr[i], &arr[min]);
            comparison++;
        }
        comparison++;
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

void tampil(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}
