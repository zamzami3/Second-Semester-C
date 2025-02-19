#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void insertion(int arr[], int size);
void sequential(int arr[], int size, int key);
void binary(int arr[], int size, int key);

void tampil(int arr[], int size);
void generate(int arr[], int size);
void input_data(int *jml);
void menu(int *pilih);
void case_pilih(int pilih, int jml, int arr[]);

int sorting = 1;
int key;

int main () {
    int pilih;
    int jml;

    input_data(&jml);

    int arr[jml];
    generate(arr, jml);

    do {
        menu(&pilih);
        time_t start, end;
        start = clock();

        case_pilih(pilih, jml, arr);

        end = clock();
        double waktu_komputasi = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Durasi = %f detik\n", waktu_komputasi);
    } while (pilih != 4);
    return 0;
}

void menu(int *pilih) {
    puts ("ALGORITMA PENCARIAN");
    puts ("1. Sequential Search Unsorted Array");
    puts ("2. Sequential Search Sorted Array");
    puts ("3. Binary Search Sorted Array");
    puts ("4. Keluar");

    printf ("Pilihan Anda: ");
    scanf ("%d", pilih);
}

void input_data (int *jml) {
    printf("Masukkan jumlah elemen [25000/50000/75000/100000]: ");
    scanf("%d", jml);

    if (*jml > MAX) {
        printf("Jumlah data tidak valid.\n");
        exit(0);
    }
}

void case_pilih (int pilih, int jml, int arr[]) {
    switch (pilih) {
        case 1:
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            sequential(arr, jml, key);
            break;
        case 2:
            insertion(arr, jml);
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            sequential(arr, jml, key);
            break;
        case 3:
            insertion(arr, jml);
            sorting = 2; // Mengatur untuk descending order
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            binary(arr, jml, key);
            break;
        case 4:
            puts ("Anda Keluar");
            exit (0);
        default:
            puts ("Pilihan tidak ada dalam menu, silahkan coba lagi");
            exit (0);
        }
}

void sequential(int arr[], int size, int key) {
    int i, find;

    i = 0;
    find = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            find++;
        }
    }
    if (find > 1) {
        printf ("%d ada pada sebanyak %d kali\n", key, find);
    } else {
        printf ("Data %d tidak ditemukan\n", key);
    }
    puts (" ");
}

void binary(int arr[], int size, int key) {
    int find = 0;
    int l = 0, r = size - 1;

    while (l <= r) {
        int middle = (l + r) / 2;
        if (arr[middle] == key) {
            find++;
            for (int i = middle - 1; i >= 0 && arr[i] == key; i--) {
                find++;
            }
            for (int i = middle + 1; i < size && arr[i] == key; i++) {
                find++;
            }
            break;
        } else if (key < arr[middle]) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }

    if (find > 1) {
        printf("%d ditemukan sebanyak %d kali\n", key, find);
    } else {
        printf("Data %d tidak ditemukan\n", key);
    }
    puts(" ");
}

void insertion(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        if (sorting == 1) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else if (sorting == 2) {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

void tampil (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf ("%d ", arr[i]);
    }
    puts (" ");
}

void generate(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}
