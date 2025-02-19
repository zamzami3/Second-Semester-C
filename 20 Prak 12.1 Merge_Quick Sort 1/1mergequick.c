#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30000

void insertion(int arr[], int size);
void selection(int arr[], int size);
void bubble(int arr[], int size);
void shell(int arr[], int size);
void merge(int arr[], int left, int median, int right);
void quick(int arr[], int p, int r);

void mergesort(int arr[], int left, int right);
int partisi(int arr[], int p, int r);
void tukar(int *x, int *y);
void generate(int x[], int size);
void mode_urut();
void tampil(int arr[], int size);
void menu ();
void input_data();
void case_pilihmenu();

int sorting, pilihmenu, jml;

int main() {

    input_data();
    int arr[jml];
    generate(arr, jml);
    menu();
    if (pilihmenu != 7) {
        mode_urut();
    }

    clock_t start, end;
    start = clock();
    case_pilihmenu(arr);
    end = clock();
    double waktu_komputasi = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Durasi = %f detik\n", waktu_komputasi);
    return 0;
}

void menu() {
    puts ("Menu Sorting");
    puts ("1. Insertion");
    puts ("2. Selection");
    puts ("3. Bubble");
    puts ("4. Shell");
    puts ("5. Merge");
    puts ("6. Quick");
    puts ("7. Keluar");

    printf("Pilihan Anda: ");
    scanf("%d", &pilihmenu);
}

void input_data () {
    printf("Masukkan jumlah elemen >= 30000: ");
    scanf("%d", &jml);

    if (jml < MAX) {
        printf("Jumlah data tidak valid.\n");
        exit(0);
    }
}

void case_pilihmenu(int arr[]) {
    switch (pilihmenu) {
        case 1:
            insertion(arr, jml);
            break;
        case 2:
            selection(arr, jml);
            break;
        case 3:
            bubble(arr, jml);
            break;
        case 4:
            shell(arr, jml);
            break;
        case 5:
            mergesort(arr, 0, jml - 1);
            break;
        case 6:
            quick(arr, 0, jml - 1);
            break;
        case 7:
            printf("Anda Keluar\n");
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
            exit(0);
    }
}

void mode_urut() {
    printf("Mode Urut\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");

    printf("Pilihan Anda: ");
    scanf("%d", &sorting);
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

void selection(int arr[], int size) {
    int i, j, min;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (sorting == 1) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            } else if (sorting == 2) {
                if (arr[j] > arr[min]) {
                    min = j;
                }
            }
        }
        tukar(&arr[i], &arr[min]);
    }
}

void bubble(int arr[], int size) {
    int i, kondisi, did_swap = 1;
    int pos_akhir = size - 2;

    while (pos_akhir >= 0 && did_swap) {
        i = 0;
        did_swap = 0;
        while (i <= pos_akhir) {
            if (sorting == 1) {
                kondisi = arr[i] > arr[i + 1];
            } else if (sorting == 2) {
                kondisi = arr[i] < arr[i + 1];
            }
            if (kondisi) {
                tukar(&arr[i], &arr[i + 1]);
                did_swap = 1;
            }
            i++;
        }
        pos_akhir--;
    }
}

void shell(int arr[], int size) {
    int jarak, did_swap, i, kondisi;
    jarak = size;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = 1;
        while (did_swap) {
            did_swap = 0;
            i = 0;
            while (i < size - jarak) {
                if (sorting == 1) {
                    kondisi = arr[i] > arr[i + jarak];
                } else if (sorting == 2) {
                    kondisi = arr[i] < arr[i + jarak];
                }
                if (kondisi) {
                    tukar(&arr[i], &arr[i + jarak]);
                    did_swap = 1;
                }
                i++;
            }
        }
    }
}

void merge(int arr[], int left, int median, int right) {
    int n1 = median - left + 1;
    int n2 = right - median;

    int kiri1[n1], kanan1[n2];

    for (int i = 0; i < n1; i++)
        kiri1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        kanan1[j] = arr[median + 1 + j];

    int i = 0, j = 0, k = left;

    if (sorting == 1) {
        while (i < n1 && j < n2) {
            if (kiri1[i] <= kanan1[j]) {
                arr[k] = kiri1[i];
                i++;
            } else {
                arr[k] = kanan1[j];
                j++;
            }
            k++;
        }
    } else if (sorting == 2) {
        while (i < n1 && j < n2) {
            if (kiri1[i] >= kanan1[j]) {
                arr[k] = kiri1[i];
                i++;
            } else {
                arr[k] = kanan1[j];
                j++;
            }
            k++;
        }
    }

    while (i < n1) {
        arr[k] = kiri1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = kanan1[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int median = left + (right - left) / 2;
        mergesort(arr, left, median);
        mergesort(arr, median + 1, right);
        merge(arr, left, median, right);
    }
}

void quick(int arr[], int p, int r) {
    if (p < r) {
        int q = partisi(arr, p, r);
        quick(arr, p, q);
        quick(arr, q + 1, r);
    }
}

int partisi(int arr[], int p, int r) {
    int pivot = arr[p];
    int i = p - 1;
    int j = r + 1;

    while (1) {
        if (sorting == 1) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);
        } else if (sorting == 2) {
            do {
                i++;
            } while (arr[i] > pivot);

            do {
                j--;
            } while (arr[j] < pivot);
        }

        if (i >= j) {
            return j;
        }

        tukar(&arr[i], &arr[j]);
    }
}

void tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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
