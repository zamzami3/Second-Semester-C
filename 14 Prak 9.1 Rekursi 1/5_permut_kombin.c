#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int faktorial(int n);
int permutasi(int n, int r);
int kombinasi (int n, int r);

int main () {
    int n, r;

    puts ("Melakukan perhitungan Permutasi dan Kombinasi");

    printf ("Masukkan n: ");
    scanf ("%d", &n);

    printf ("Masukkan r: ");
    scanf ("%d", &r);

    printf ("Hasil Permutasi nya: %d\n", permutasi(n, r));
    printf ("Hasil Kombinasi nya: %d\n", kombinasi(n, r));

    return 0;
}

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1; //0! dan 1! = 1
    } else {
        return n * faktorial(n - 1);
    }
}

int permutasi(int n, int r) {
    int hasil_permut;
    hasil_permut = faktorial(n) / faktorial(n-r);
    return hasil_permut;
}

int kombinasi (int n, int r) {
    int hasil_kombin;
    hasil_kombin = faktorial(n) / (faktorial(n-r) * faktorial(r));
    return hasil_kombin;
}
