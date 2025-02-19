//praktikum 12.2 tambahan merge dan quick sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa {
    int no;
    char nama[256];
    int nilai;
};

void insertion(struct siswa data[]);
void selection(struct siswa data[]);
void bubble(struct siswa data[]);
void shell(struct siswa data[]);
void merge(struct siswa data[], int left, int median, int right);
void quick(struct siswa data[], int p, int r);

void tukar (struct siswa *x, struct siswa *y);
void mergesort (struct siswa data[], int left, int right);
int partisi (struct siswa data[], int p, int r);
void tampil(struct siswa data[]);

void simpandatasiswa(struct siswa data[]);
void modeUrut();
void urut();

int sorting;   //1 untuk ascending 2 untuk descending
int pilih_urut; //1 untuk urut berdasar no, 2 urut berdasar nama, 3 urut berdasarkan nilai
int jmldata;

int main () {
    int menu_metode;

    printf ("Mau memasukkan berapa data? ");
    scanf ("%d", &jmldata);

    struct siswa data[jmldata];

    simpandatasiswa(data);

    do {
        puts ("MENU METODE SORTING");
        puts ("1. Insertion Sort");
        puts ("2. Selection Sort");
        puts ("3. Bubble Sort");
        puts ("4. Shell Sort");
        puts ("5. Merge Sort");
        puts ("6. Quick Sort");
        puts ("7. Keluar");

        printf ("Pilihan Anda: ");
        scanf ("%d", &menu_metode);

        switch (menu_metode) {
                case 1:
                    modeUrut();
                    urut();
                    insertion(data);
                    tampil(data);
                    break;
                case 2:
                    modeUrut();
                    urut();
                    selection(data);
                    tampil(data);
                    break;
                case 3:
                    modeUrut();
                    urut();
                    bubble(data);
                    tampil(data);
                    break;
                case 4:
                    modeUrut();
                    urut();
                    shell(data);
                    tampil(data);
                    break;
                case 5:
                    modeUrut();
                    urut();
                    mergesort(data, 0, jmldata - 1);
                    tampil(data);
                    break;
                case 6:
                    modeUrut();
                    urut();
                    quick(data, 0, jmldata - 1);
                    tampil(data);
                    break;
                case 7:
                    puts("Anda Keluar");
                    exit(0);
                    break;
                default:
                    puts("Pilihan tidak valid!");
                    exit(0);
                    break;
            }
    } while(menu_metode != 7);
}

void simpandatasiswa(struct siswa data[]) {
    printf ("Oke, mari isi %d data siswa\n", jmldata);
    puts (" ");

    for (int i = 0; i < jmldata; i++) {
        printf ("Data siswa ke %d\n", i + 1);
        printf ("No: ");
        scanf ("%d", &data[i].no);

        printf ("Nama: ");
        scanf ("%s", data[i].nama);

        printf ("Nilai [dalam bentuk angka]: ");
        scanf ("%d", &data[i].nilai);
        puts (" ");
    }
}

void modeUrut() {
    puts ("Pengurutan yang dipilih: ");
    puts ("1. Ascending");
    puts ("2. Descending");

    printf ("Pilihan Anda: ");
    scanf ("%d", &sorting);
}

void urut () {
    puts ("Pengurutan berdasarkan: ");
    puts ("1. No");
    puts ("2. Nama");
    puts ("3. Nilai ");

    printf ("Pilihan Anda: ");
    scanf ("%d", &pilih_urut);
}

void insertion (struct siswa data[]) {
    int i, j;
    struct siswa key;

    for (i = 1; i < jmldata; i++) {
        key = data[i];
        j = i - 1;

       if (sorting == 1) {
            //ascending
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no > key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmpi(data[j].nama, key.nama) > 0) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 3) {
                while (j >= 0 && data[j].nilai > key.nilai) {
                    data[j + 1] = data[j];
                    j--;
                }
            }
            //descending
        } else if (sorting == 2) {
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no < key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmpi(data[j].nama, key.nama) < 0) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 3) {
                while (j >= 0 && data[j].nilai < key.nilai) {
                    data[j + 1] = data[j];
                    j--;
                }
            }
        }
        data[j + 1] = key;
    }
}

void selection (struct siswa data[]) {
    int i, j, min;
    struct siswa tampung;
    for (i = 0; i < jmldata - 1; i++) {
        min = i;
        for (j = i + 1; j < jmldata; j++){
            if (sorting == 1) {
                if (pilih_urut == 1) {
                    if (data[j].no < data[min].no)
                        min = j;
                } else if (pilih_urut == 2) {
                    if (strcmpi(data[j].nama, data[min].nama) < 0)
                        min = j;
                } else if (pilih_urut == 3) {
                    if (data[j].nilai < data[min].nilai)
                        min = j;
                }
            }
            if (sorting == 2) {
                if (pilih_urut == 1) {
                    if (data[j].no > data[min].no)
                        min = j;
                } else if (pilih_urut == 2) {
                    if (strcmpi(data[j].nama, data[min].nama) > 0)
                        min = j;
                } else if (pilih_urut == 3) {
                    if (data[j].nilai > data[min].nilai)
                        min = j;
                }
            }
        }
        tukar(&data[min], &data[i]);
    }
}

void bubble(struct siswa data[]) {
    int i, kondisi, did_swap = 1;
    int pos_akhir = jmldata - 2;

    while (pos_akhir >= 0 && did_swap) {
        i = 0;
        did_swap = 0;
        while (i <= pos_akhir) {
            if (sorting == 1) {
                if (pilih_urut == 1) {
                    kondisi = data[i].no > data[i + 1].no;
                } else if (pilih_urut == 2) {
                    kondisi = strcmpi(data[i].nama, data[i + 1].nama) > 0;
                } else if (pilih_urut == 3) {
                    kondisi = data[i].nilai > data[i + 1].nilai;
                }
            } else if (sorting == 2) {
                if (pilih_urut == 1) {
                    kondisi = data[i].no < data[i + 1].no;
                } else if (pilih_urut == 2) {
                    kondisi = strcmpi(data[i].nama, data[i + 1].nama) < 0;
                } else if (pilih_urut == 3) {
                    kondisi = data[i].nilai < data[i + 1].nilai;
                }
            }
            if (kondisi) {
                tukar(&data[i], &data[i + 1]);
                did_swap = 1;
            }
            i++;
        }
        pos_akhir--;
    }
}

void shell (struct siswa data[]) {
    int jarak, did_swap, i, kondisi;
    jarak = jmldata;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = 1;
        while (did_swap) {
            did_swap = 0;
            i = 0;
            while (i + jarak < jmldata) {
                if (sorting == 1) {
                    if (pilih_urut == 1) {
                        kondisi = data[i]. no > data[i + jarak].no;
                    } else if (pilih_urut == 2) {
                        kondisi = strcmpi(data[i]. nama , data[i + jarak].nama) >  0;
                    } else if (pilih_urut == 3) {
                        kondisi = data[i]. nilai > data[i + jarak].nilai;
                    }
                } else if (sorting == 2) {
                    if (pilih_urut == 1) {
                        kondisi = data[i].no < data[i + jarak].no;
                    } else if (pilih_urut == 2) {
                        kondisi = strcmpi(data[i].nama, data[i + jarak].nama) < 0;
                    } else if (pilih_urut == 3) {
                        kondisi = data[i].nilai < data[i + jarak].nilai;
                    }
                }
                if (kondisi) {
                    tukar(&data[i], &data[i + jarak]);
                    did_swap = 1;
                }
                i++;
            }
        }
    }
}

void merge (struct siswa data[], int left, int median, int right) {
    int kiri1 = left;
    int kanan1 = median;
    int kiri2 = median + 1;
    int kanan2 = right;
    int i, j, hasil[jmldata];

    i = left;

    if (sorting == 1) {
        if (pilih_urut == 1){
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (data[kiri1].no <= data[kiri2].no) {
                    hasil[i] = data[kiri1].no;
                    kiri1++;
                } else {
                    hasil[i] = data[kiri2].no;
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                hasil[i] = data[kiri1].no;
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                hasil[i] = data[kiri2].no;
                kiri2++;
                i++;
            }
            j = left;
            while (j <= right) {
                data[j].no = hasil[j];
                j++;
            }
        } else if (pilih_urut == 2) {
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (strcmpi(data[kiri1].nama, data[kiri2].nama) <= 0) {
                    strcpy(hasil + i, data[kiri1].nama);
                    kiri1++;
                } else {
                    strcpy(hasil + i, data[kiri2].nama);
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                strcpy(hasil + i, data[kiri1].nama);
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                strcpy(hasil + i, data[kiri2].nama);
                kiri2++;
                i++;
            }
            j = left;
            while (j <= right) {
                strcpy(data[j].nama, hasil + j);
                j++;
            }
        } else if (pilih_urut == 3) {
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (data[kiri1].nilai <= data[kiri2].nilai) {
                    hasil[i] = data[kiri1].nilai;
                    kiri1++;
                } else {
                    hasil[i] = data[kiri2].nilai;
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                hasil[i] = data[kiri1].nilai;
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                hasil[i] = data[kiri2].nilai;
                kiri2++;
                i++;
            }
            j = left;
            while (j <= right) {
                data[j].nilai = hasil[j];
                j++;
            }
        } else {
            puts ("Menu metode tidak ditemukan, silahkan coba lagi.");
            exit(0);
        }
    } else if (sorting == 2) {
        if (pilih_urut == 1) {
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (data[kiri1].no >= data[kiri2].no) {
                    hasil[i] = data[kiri1].no;
                    kiri1++;
                } else {
                    hasil[i] = data[kiri2].no;
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                hasil[i] = data[kiri1].no;
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                hasil[i] = data[kiri2].no;
                kiri2++;
                i++;
            }
            j = left;
            while (j <= right) {
                data[j].no = hasil[j];
                j++;
            }
        } else if (pilih_urut == 2) {
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (strcmpi(data[kiri1].nama, data[kiri2].nama) >= 0) {
                    strcpy(hasil + i, data[kiri1].nama);
                    kiri1++;
                } else {
                    strcpy(hasil + i, data[kiri2].nama);
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                strcpy(hasil + i, data[kiri1].nama);
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                strcpy(hasil + i, data[kiri2].nama);
                kiri2++;
                i++;
            }
            j = left;
            while (j >= right) {
                strcpy(data[j].nama, hasil + j);
                j++;
            }
        } else if (pilih_urut == 3) {
            while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
                if (data[kiri1].nilai >= data[kiri2].nilai) {
                    hasil[i] = data[kiri1].nilai;
                    kiri1++;
                } else {
                    hasil[i] = data[kiri2].nilai;
                    kiri2++;
                }
                i++;
            }
            while (kiri1 <= kanan1) {
                hasil[i] = data[kiri1].nilai;
                kiri1++;
                i++;
            }
            while (kiri2 <= kanan2) {
                hasil[i] = data[kiri2].nilai;
                kiri2++;
                i++;
            }
            j = left;
            while (j <= right) {
                data[j].nilai = hasil[j];
                j++;
            }
        }
    }
}

void quick(struct siswa data[], int p, int r) {
    int q;
    if (p < r) {
        q = partisi(data, p, r);
        quick(data, p, q - 1);
        quick(data, q + 1, r);
    }
}

void mergesort(struct siswa data[], int left, int right) {
    int median;
    if (left < right) {
        median = (left + right) / 2;
        mergesort (data, left, median);
        mergesort (data, median + 1, right);
        merge (data, left, median, right);
    }
}

int partisi(struct siswa data[], int p, int r) {
    int i, j;
    struct siswa pivot;

    i = p - 1;
    pivot = data[r];

    for (int j = p; j <= r - 1; j++) {
        int kondisi = 0;
        if (sorting == 1) {
            if ((pilih_urut == 1 && data[j].no <= pivot.no) || (pilih_urut == 2 && strcmp(data[j].nama, pivot.nama) <= 0) || (pilih_urut == 3 && data[j].nilai <= pivot.nilai)) {
                kondisi = 1;
            }
        } else if (sorting == 2) {
            if ((pilih_urut == 1 && data[j].no >= pivot.no) || (pilih_urut == 2 && strcmp(data[j].nama, pivot.nama) >= 0) || (pilih_urut == 3 && data[j].nilai >= pivot.nilai)) {
                kondisi = 1;
            }
        }
        if (kondisi) {
            i++;
            tukar(&data[i], &data[j]);
        }
    }
    tukar(&data[i + 1], &data[r]);
    return (i + 1);
}

void tukar (struct siswa *x, struct siswa *y){
    struct siswa z;
    z = *x;
    *x = *y;
    *y = z;
}

void tampil (struct siswa data[]) {
    printf ("Data siswa:\n");
    printf ("No\tNama\t\tNilai\n");
    for (int i = 0; i < jmldata; i++) {
        printf ("%d\t%s\t\t%d\n", data[i].no, data[i].nama, data[i].nilai);
    }
    puts (" ");
}
