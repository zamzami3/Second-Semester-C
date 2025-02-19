//menghitung faktorial dengan iterasi

#include <stdio.h>
#include <stdlib.h>

int faktorial_iterasi(int bil);

int main () {
    int bil;

    printf ("Masukkan bilangan yang akan difaktorialkan: ");
    scanf ("%d", &bil);

    if (bil < 0) {
        puts ("Masukkan bilangan bulat positif");
        puts ("Jangan masukkan bilangan negatif");
        puts ("Silahkan coba lagi");
        exit(0);
    } else {
        int hasil = faktorial_iterasi(bil);
        printf ("Hasil faktorialnya: %d", hasil);
    }
    return 0;
}

int faktorial_iterasi(int bil) {
    int hasil = 1;

    for (int i = 2; i <= bil; i++) {
        hasil *= i;
    }
    return hasil;
}
