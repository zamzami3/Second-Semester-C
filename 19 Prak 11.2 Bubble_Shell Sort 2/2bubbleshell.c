//praktikum 11.2 tambahan bubble dan shell sort terkait sorting dan ascending dan descending

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa {
    int no;
    char nama[256];
    int nilai;
};

void insertion(struct siswa data[], int jmldata);
void selection(struct siswa data[], int jmldata);
void bubble(struct siswa data[], int jmldata);
void shell(struct siswa data[], int jmldata);
void tukar (struct siswa *x, struct siswa *y);
void tampil(struct siswa data[], int jmldata);

void simpandatasiswa(struct siswa data[], int jmldata);
void modeUrut();
void urut();

int sorting;   // 1 untuk ascending, 2 untuk descending
int pilih_urut; // 1 untuk urut berdasar no, 2 urut berdasar nama, 3 urut berdasarkan nilai

int main () {
    int menu_metode;
    int jmldata;

    printf ("Mau memasukkan berapa data? ");
    scanf ("%d", &jmldata);

    struct siswa data[jmldata];

    simpandatasiswa(data, jmldata);

    do {
        puts ("MENU METODE SORTING");
        puts ("1. Insertion Sort");
        puts ("2. Selection Sort");
        puts ("3. Bubble Sort");
        puts ("4. Shell Sort");
        puts ("5. Keluar");

        printf ("Pilihan Anda: ");
        scanf ("%d", &menu_metode);

        if (menu_metode != 5) {
            modeUrut();
            urut();
        }

        switch (menu_metode) {
            case 1:
                insertion(data, jmldata);
                tampil(data, jmldata);
                break;
            case 2:
                selection(data, jmldata);
                tampil(data, jmldata);
                break;
            case 3:
                bubble(data, jmldata);
                tampil(data, jmldata);
                break;
            case 4:
                shell(data, jmldata);
                tampil(data, jmldata);
                break;
            case 5:
                puts("Anda Keluar");
                exit(0);
                break;
            default:
                puts("Pilihan tidak valid!");
                break;
        }
    } while(menu_metode != 5);

    return 0;
}

void simpandatasiswa(struct siswa data[], int jmldata) {
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

    printf ("Pilihan Anda [1/2/3]: ");
    scanf ("%d", &pilih_urut);
}

void insertion (struct siswa data[], int jmldata) {
    int i, j;
    struct siswa key;

    for (i = 1; i < jmldata; i++) {
        key = data[i];
        j = i - 1;

        if (sorting == 1) {
            // ascending
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
        } else if (sorting == 2) {
            // descending
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

void selection (struct siswa data[], int jmldata) {
    int i, j, min;
    for (i = 0; i < jmldata - 1; i++) {
        min = i;
        for (j = i + 1; j < jmldata; j++) {
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
            } else if (sorting == 2) {
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

void bubble(struct siswa data[], int jmldata) {
    int i, did_swap = 1;
    int pos_akhir = jmldata - 1;

    while (pos_akhir > 0 && did_swap) {
        did_swap = 0;
        for (i = 0; i < pos_akhir; i++) {
            int kondisi = 0;
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
        }
        pos_akhir--;
    }
}

void shell (struct siswa data[], int jmldata) {
    int jarak, i, j;
    struct siswa temp;

    for (jarak = jmldata / 2; jarak > 0; jarak /= 2) {
        for (i = jarak; i < jmldata; i++) {
            temp = data[i];
            for (j = i; j >= jarak; j -= jarak) {
                int kondisi = 0;
                if (sorting == 1) {
                    if (pilih_urut == 1) {
                        kondisi = temp.no < data[j - jarak].no;
                    } else if (pilih_urut == 2) {
                        kondisi = strcmpi(temp.nama, data[j - jarak].nama) < 0;
                    } else if (pilih_urut == 3) {
                        kondisi = temp.nilai < data[j - jarak].nilai;
                    }
                } else if (sorting == 2) {
                    if (pilih_urut == 1) {
                        kondisi = temp.no > data[j - jarak].no;
                    } else if (pilih_urut == 2) {
                        kondisi = strcmpi(temp.nama, data[j - jarak].nama) > 0;
                    } else if (pilih_urut == 3) {
                        kondisi = temp.nilai > data[j - jarak].nilai;
                    }
                }
                if (!kondisi) break;
                data[j] = data[j - jarak];
            }
            data[j] = temp;
        }
    }
}

void tukar (struct siswa *x, struct siswa *y) {
    struct siswa temp = *x;
    *x = *y;
    *y = temp;
}

void tampil (struct siswa data[], int jmldata) {
    printf ("Data siswa:\n");
    printf ("No\tNama\t\tNilai\n");
    for (int i = 0; i < jmldata; i++) {
        printf ("%d\t%s\t\t%d\n", data[i].no, data[i].nama, data[i].nilai);
    }
}
