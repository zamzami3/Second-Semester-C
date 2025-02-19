#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fibonacci_iterasi (int jml);
int fibonacci_rekursi (int jml);

time_t t1, t2;
long int waktukomputasi;

int main () {
    int menu, jml;

    printf ("Masukkan bilangan untuk deret Fibonacci: ");
    scanf ("%d", &jml);

    while (menu != 3){
        puts (" ");
        puts ("MENU FIBONACCI");
        puts ("1. Menggunakan Iterasi");
        puts ("2. Menggunakan Rekursi");
        puts ("3. Keluar");

        printf ("Mau menggunakan rumus yang mana? ");
        scanf ("%d", &menu);

        switch (menu) {
        case 1:
            time(&t1);
            fibonacci_iterasi(jml);
            time(&t2);
            waktukomputasi = difftime(t2, t1);
            printf("\nWaktu komputasi: %ld detik\n", waktukomputasi);
            break;
        case 2:
            time(&t1);
            printf ("Maka, deret bilangan fibonacci nya ");
            for (int i = 0; i < jml; i++) {
                printf ("%d ", fibonacci_rekursi (i));
            }
            time(&t2);
            waktukomputasi = difftime(t2, t1);
            printf("\nWaktu komputasi: %ld detik\n", waktukomputasi);
            break;
        case 3:
            puts ("Anda keluar");
            exit(0);
            break;
        default :
            puts ("Pilihan tidak ada dalam menu. Silahkan coba lagi");
            exit(0);
            break;
        }
    }
}

void fibonacci_iterasi(int jml) {
    int a, b, temp;
    a = 0;
    b = 1;

    printf ("Deret Fibonacci nya: ");
    for (int i = 0; i <= jml; i++) {
        printf ("%d ", a);
        temp = a;
        a = b;
        b = temp + b;
    }
}

int fibonacci_rekursi(int jml) {
    int hasil;
    if (jml == 0) {
        return 0;
    } else if (jml == 1) {
        return 1;
    } else {
        hasil = fibonacci_rekursi(jml - 1) + fibonacci_rekursi(jml - 2);
        return hasil;
    }
}
