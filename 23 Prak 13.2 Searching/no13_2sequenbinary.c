//praktikum 13.2

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct siswa {
    int no;
    char nama[256];
    int nilai;
};

void insertion(struct siswa data[]);
void sequential(struct siswa data[], int size, struct siswa key);
void binary(struct siswa data[], int size, struct siswa key);

void tampil(struct siswa data[]);
void simpandatasiswa(struct siswa data[]);
void modeUrut();
void urut();

void menu(struct siswa data[], struct siswa key);
void input_data();

int sorting = 1, pilih_urut = 1;
int bentukdata, pilih_cari, jmldata;

int main() {
    struct siswa key;

    puts("SEARCHING - DATA STRUCT");
    input_data();
    struct siswa data[jmldata];

    simpandatasiswa(data);

    int menu_metode;
    do {
        menu(data, key);
    } while (menu_metode != 4);
    return 0;
}

void menu(struct siswa data[], struct siswa key) {
    int menu_metode, size;

    puts("MENU SEARCHING");
    puts("1. Tampilkan Data");
    puts("2. Sequential Search");
    puts("3. Binary Search");
    puts("4. Keluar");

    printf("Pilihan Anda[1/2/3/4]: ");
    scanf("%d", &menu_metode);

    if (menu_metode == 1) {
        modeUrut();
        if (bentukdata == 1) {
            tampil(data);
        } else if (bentukdata == 2) {
            insertion(data);
            tampil(data);
        }
    } else if (menu_metode == 2) {
        urut();
        if (pilih_cari == 1 || pilih_cari == 2) {
            insertion(data);
            sequential(data, size, key);
        }
    } else if (menu_metode == 3) {
        urut();
        if (pilih_cari == 1 || pilih_cari == 2) {
            insertion(data);
            binary(data, size, key);
        }
    } else if (menu_metode == 4) {
        puts("Anda Keluar");
        exit(0);
    } else {
        puts("Pilihan Anda tidak valid! Silakan coba lagi");
    }
}

void input_data() {
    printf("Berapa jumlah data <maks 30>? ");
    scanf("%d", &jmldata);

    if (jmldata > MAX) {
        puts("Data tidak valid");
        puts ("Tolong masukkan data kurang dari 30");
        puts("Silakan coba lagi");
        exit(0);
    }
}

void simpandatasiswa(struct siswa data[]) {
    printf("Baik. Mari kita isi %d data siswa\n", jmldata);
    puts(" ");

    for (int i = 0; i < jmldata; i++) {
        printf("Data mhs ke-%d\n", i + 1);
        printf("No\t: ");
        scanf("%d", &data[i].no);

        printf("Nama\t: ");
        scanf("%s", data[i].nama);

        printf("Nilai\t: ");
        scanf("%d", &data[i].nilai);

        puts(" ");
    }
}

void modeUrut() {
    puts("BENTUK DATA : ");
    puts("1. Tidak Terurut");
    puts("2. Terurut Berdasarkan No");

    printf("Pilihan Anda [1/2]: ");
    scanf("%d", &bentukdata);
}

void urut() {
    puts("PENCARIAN BERDASARKAN");
    puts("1. No");
    puts("2. Nama");

    printf("Pilihan Anda [1/2]: ");
    scanf("%d", &pilih_cari);
}

void insertion(struct siswa data[]) {
    int i, j;
    struct siswa key;

    for (i = 1; i < jmldata; i++) {
        key = data[i];
        j = i - 1;

        if (sorting == 1) {
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no > key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmp(data[j].nama, key.nama) > 0) {
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
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no < key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmp(data[j].nama, key.nama) < 0) {
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

void sequential(struct siswa data[], int size, struct siswa key) {
    int i, find;

    if (pilih_cari == 1) {
        printf("Masukkkan no mhs yang akan dicari: ");
        scanf("%d", &key.no);

        i = 0;
        find = 0;
        while ((!find) && (i < size)) {
            if (data[i].no == key.no) {
                find = 1; //true, ketemu
            } else {
                i++;
            }
        }
        if (find) {
            printf("Data %d ketemu pada index [%d]\n", key.no, i);
        } else {
            printf("Data %d tidak ditemukan\n", key.no);
        }
        puts(" ");
    } else if (pilih_cari == 2) {
        printf("Masukkkan nama mhs yang akan dicari: ");
        scanf("%s", key.nama);

        i = 0;
        find = 0;
        while ((!find) && (i < size)) {
            if (strcmp(data[i].nama, key.nama) == 0) {
                find = 1; //true, ketemu
            } else {
                i++;
            }
        }
        if (find) {
            printf("Data %s ketemu pada index [%d]\n", key.nama, i);
        } else {
            printf("Data %s tidak ditemukan\n", key.nama);
        }
        puts(" ");
    }
}

void binary(struct siswa data[], int size, struct siswa key) {
    int find, middle;
    int l, r;

    if (pilih_cari == 1) {
        printf("Masukkkan no mhs yang akan dicari: ");
        scanf("%d", &key.no);

        l = 0;
        r = size - 1;
        find = 0;

        while ((l <= r) && (!find)) {
            middle = (l + r) / 2;
            if (data[middle].no == key.no) {
                find = 1;
            } else if (key.no < data[middle].no) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }
        if (find) {
            printf("%d ada pada index [%d]\n", key.no, middle);
        } else {
            printf("Data %d tidak ditemukan\n", key.no);
        }
        puts(" ");
    } else if (pilih_cari == 2) {
        printf("Masukkkan nama mhs yang akan dicari: ");
        scanf("%s", key.nama);

        l = 0;
        r = size - 1;
        find = 0;

        while ((l <= r) && (!find)) {
            middle = (l + r) / 2;
            if (strcmp(data[middle].nama, key.nama) == 0) {
                find = 1;
            } else if (strcmp(key.nama, data[middle].nama) < 0) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }
        if (find) {
            printf("Data %s ketemu pada index [%d]\n", key.nama, middle);
        } else {
            printf("Data %s tidak ditemukan\n", key.nama);
        }
        puts(" ");
    }
}

void tampil(struct siswa data[]) {
    printf("Data siswa:\n");
    printf("No\tNama\t\tNilai\n");
    for (int i = 0; i < jmldata; i++) {
        printf("%d\t%s\t\t%d\n", data[i].no, data[i].nama, data[i].nilai);
    }
    puts(" ");
}*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct siswa {
    int no;
    char nama[256];
    int nilai;
};

void insertion(struct siswa data[]);
void sequential(struct siswa data[], int size, struct siswa key);
void binary(struct siswa data[], int size, struct siswa key);

void tampil(struct siswa data[]);
void simpandatasiswa(struct siswa data[]);
void modeUrut();
void urut();

int sorting = 1;
int pilih_urut = 1;
int jmldata;
int bentukdata;
int pilih_cari;

int main() {
    int menu_metode;

    puts("SEARCHING - DATA STRUCT");
    printf("Berapa jumlah data <maks 30>? ");
    scanf("%d", &jmldata);

    if (jmldata > MAX) {
        puts("Data tidak valid, masukkan data kurang dari 30!");
        puts("Silakan coba lagi");
        exit(0);
    }

    struct siswa data[jmldata];
    struct siswa key;

    simpandatasiswa(data);

    do {
        puts("MENU SEARCHING");
        puts("1. Tampilkan Data");
        puts("2. Sequential Search");
        puts("3. Binary Search");
        puts("4. Keluar");

        printf("Pilihan Anda[1/2/3/4]: ");
        scanf("%d", &menu_metode);

        if (menu_metode == 1) {
            modeUrut();
            if (bentukdata == 1) {
                tampil(data);
            } else if (bentukdata == 2) {
                insertion(data);
                tampil(data);
            }
        } else if (menu_metode == 2) {
            urut();
            if (pilih_cari == 1 || pilih_cari == 2) {
                insertion(data);
                sequential(data, jmldata, key);
            }
        } else if (menu_metode == 3) {
            urut();
            if (pilih_cari == 1 || pilih_cari == 2) {
                insertion(data);
                binary(data, jmldata, key);
            }
        } else if (menu_metode == 4) {
            puts("Anda Keluar");
            exit(0);
        } else {
            puts("Pilihan Anda tidak valid! Silakan coba lagi");
            exit(0);
        }
    } while (menu_metode != 4);
    return 0;
}

void simpandatasiswa(struct siswa data[]) {
    printf("Baik. Mari isi %d data siswa\n", jmldata);
    puts(" ");

    for (int i = 0; i < jmldata; i++) {
        printf("Data mhs ke-%d\n", i + 1);
        printf("No\t: ");
        scanf("%d", &data[i].no);

        printf("Nama\t: ");
        scanf("%s", data[i].nama);

        printf("Nilai\t: ");
        scanf("%d", &data[i].nilai);

        puts(" ");
    }
}

void modeUrut() {
    puts("BENTUK DATA : ");
    puts("1. Tidak Terurut");
    puts("2. Terurut Berdasarkan No");

    printf("Pilihan Anda [1/2]: ");
    scanf("%d", &bentukdata);
}

void urut() {
    puts("PENCARIAN BERDASARKAN");
    puts("1. No");
    puts("2. Nama");

    printf("Pilihan Anda [1/2]: ");
    scanf("%d", &pilih_cari);
}

void insertion(struct siswa data[]) {
    int i, j;
    struct siswa key;

    for (i = 1; i < jmldata; i++) {
        key = data[i];
        j = i - 1;

        if (sorting == 1) {
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no > key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmp(data[j].nama, key.nama) > 0) {
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
            if (pilih_urut == 1) {
                while (j >= 0 && data[j].no < key.no) {
                    data[j + 1] = data[j];
                    j--;
                }
            } else if (pilih_urut == 2) {
                while (j >= 0 && strcmp(data[j].nama, key.nama) < 0) {
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

void sequential(struct siswa data[], int size, struct siswa key) {
    int i, find;

    if (pilih_cari == 1) {
        printf("Masukkkan no mhs yang akan dicari: ");
        scanf("%d", &key.no);

        i = 0;
        find = 0;
        while ((!find) && (i < size)) {
            if (data[i].no == key.no) {
                find = 1;
            } else {
                i++;
            }
        }
        if (find) {
            printf("Data %d ketemu pada index [%d]\n", key.no, i);
        } else {
            printf("Data %d tidak ditemukan\n", key.no);
        }
        puts(" ");
    } else if (pilih_cari == 2) {
        printf("Masukkkan nama mhs yang akan dicari: ");
        scanf("%s", key.nama);

        i = 0;
        find = 0;
        while ((!find) && (i < size)) {
            if (strcmp(data[i].nama, key.nama) == 0) {
                find = 1;
            } else {
                i++;
            }
        }
        if (find) {
            printf("Data %s ketemu pada index [%d]\n", key.nama, i);
        } else {
            printf("Data %s tidak ditemukan\n", key.nama);
        }
        puts(" ");
    }
}

void binary(struct siswa data[], int size, struct siswa key) {
    int find, middle;
    int l, r;

    if (pilih_cari == 1) {
        printf("Masukkkan no mhs yang akan dicari: ");
        scanf("%d", &key.no);

        l = 0;
        r = size - 1;
        find = 0;

        while ((l <= r) && (!find)) {
            middle = (l + r) / 2;
            if (data[middle].no == key.no) {
                find = 1;
            } else if (key.no < data[middle].no) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }
        if (find) {
            printf("%d ada pada index [%d]\n", key.no, middle);
        } else {
            printf("Data %d tidak ditemukan\n", key.no);
        }
        puts(" ");
    } else if (pilih_cari == 2) {
        printf("Masukkkan nama mhs yang akan dicari: ");
        scanf("%s", key.nama);

        l = 0;
        r = size - 1;
        find = 0;

        while ((l <= r) && (!find)) {
            middle = (l + r) / 2;
            if (strcmp(data[middle].nama, key.nama) == 0) {
                find = 1;
            } else if (strcmp(key.nama, data[middle].nama) < 0) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }
        if (find) {
            printf("Data %s ketemu pada index [%d]\n", key.nama, middle);
        } else {
            printf("Data %s tidak ditemukan\n", key.nama);
        }
        puts(" ");
    }
}

void tampil(struct siswa data[]) {
    printf("Data siswa:\n");
    printf("No\tNama\t\tNilai\n");
    for (int i = 0; i < jmldata; i++) {
        printf("%d\t%s\t\t%d\n", data[i].no, data[i].nama, data[i].nilai);
    }
    puts(" ");
}
