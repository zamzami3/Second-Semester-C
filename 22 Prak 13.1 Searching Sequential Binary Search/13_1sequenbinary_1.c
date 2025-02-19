#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void sequential(); //bisa dilakukan untuk data acak maupun data terurut
void binary(); //hanya untuk data terurut tetapi lebih efektif drpd sequential

void tampil();
void insert_data(); // variable n itu jml elemen dalam list, bukan index nya
//mid = middle elemen
void menu();

int sorting = 1;
int pilih, key;
int arr[] = {3, 1, 9, 7, 5, 10, 4, 8, 2, 6};

int main () {
    do {
        menu();
    } while (pilih != 4);
    return 0;
}

void menu() {
    puts ("ALGORTIMA PENCARIAN");
        puts ("1. Sequential Search Unsorted Array");
        puts ("2. Sequential Search Sorted Array");
        puts ("3. Binary Search Sorted Array");
        puts ("4. Keluar");

        printf ("Pilihan Anda: ");
        scanf ("%d", &pilih);

        switch (pilih) {
        case 1:
            tampil();
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            sequential(key);
            break;
        case 2:
            tampil();
            insertion();
            tampil();
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            sequential(key);
            break;
        case 3:
            tampil();
            insertion();
            tampil();
            printf ("Data yang dicari: ");
            scanf ("%d", &key);
            binary(0, MAX - 1, key);
            break;
        case 4:
            puts ("Anda Keluar");
            exit (0);
        default:
            puts ("Pilihan tidak ada dalam menu, silahkan coba lagi");
            exit (0);
        }
}

void sequential(int key) {
    int i, find;

    i = 0;
    find = 0;

    while ((!find) && (i < MAX)) {
        if (arr[i] == key) {
            find = 1;
        } else {
            i = i + 1;
            //i++;
        }
    }
    if (find) {
        printf ("%d ada pada index [%d]\n", key, i);
    } else {
        printf ("Data %d tidak ditemukan\n", key);
    }
    puts (" ");
}

void binary(int l, int r, int key) {
    int find, middle;

    l = 0;
    r = key - 1;
    find = 0;

    while ((l <= r) && (!find)) {
        middle = (l + r) / 2;
        if (arr[middle] == key) {
            find = 1;
        } else if (key < arr[middle]) {
            r = middle - 1;
        } else if (key > arr[middle]) {
            l = middle + 1;
        }
    }
    if (find) {
        printf ("%d ada pada index [%d]\n", key, middle);
        //index data yang dicari;
    } else {
        printf ("Data %d tidak ditemukan\n", key);
    }
    puts (" ");
}

void insertion() {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
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

void tampil () {
    for (int i = 0; i < MAX; i++) {
        printf ("%d ", arr[i]);
    }
    puts (" ");
}
