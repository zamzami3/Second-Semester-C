#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fak_iterasi(int bil);
int fak_rekursi(int temp);
int fak_rek_tail(int temp, int hasil);

time_t t1, t2;
long int waktukomputasi;

int main () {
    int menu, bil;

    printf ("Masukkan bilangan bulat positif: ");
    scanf ("%d", &bil);

    while (menu != 4) {
        puts (" ");
        puts ("MENU FAKTORIAL");
        puts ("1. Faktorial Iterasi");
        puts ("2. Faktorial Rekursi");
        puts ("3. Faktorial Rekursi Tail");
        puts ("4. Keluar");

        printf ("Mau menggunakan Menu Faktorial yang mana dulu? ");
        scanf ("%d", &menu);

        switch (menu) {
        case 1:
            time(&t1);
            if (bil < 0) {
                puts ("Masukkan bilangan bulat positif! Silahkan coba lagi");
                exit(0);
            } else {
                int hasil = fak_iterasi(bil);
                printf ("Hasil faktorialnya: %d\n", hasil);
            }
            time(&t2);
            waktukomputasi = difftime(t2, t1);
            printf("Waktu komputasi: %ld detik\n", waktukomputasi);
            break;
        case 2:
            time(&t1);
            printf("Faktorialnya: %d\n", fak_rekursi(bil));
            time(&t2);
            waktukomputasi = difftime(t2, t1);
            printf("Waktu komputasi: %ld detik\n", waktukomputasi);
            break;
        case 3:
            time(&t1);
            printf("Faktorialnya: %d\n", fak_rek_tail(bil, 1));
            time(&t2);
            waktukomputasi = difftime(t2, t1);
            printf("Waktu komputasi: %ld detik\n", waktukomputasi);
            break;
        case 4:
            exit(0);
            break;
        default:
            puts("Pilihan tidak ada dalam menu. Coba lagi");
            exit(0);
            break;
        }
    }
    return 0;
}

int fak_iterasi(int bil) {
    int hasil = 1;

    for (int i = 2; i <= bil; i++) {
        hasil *= i;
    }
    return hasil;
}

int fak_rekursi(int temp) {
    if (temp > 1) {
        return temp * fak_rekursi(temp - 1);
    } else if (temp == 1 || temp == 0) {
        return 1;
    } else {
        puts("Faktorial tidak bisa negatif, tolong coba lagi");
        exit(0);
    }
}

int fak_rek_tail(int temp, int hasil) {
    if (temp < 0) {
        puts("Faktorial tidak bisa negatif, tolong coba lagi");
        exit(0);
    } else if (temp == 0) {
        return hasil;
    } else {
        return fak_rek_tail(temp - 1, hasil * temp);
    }
}
