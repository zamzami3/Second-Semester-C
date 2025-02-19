#include <stdio.h>
#include <stdlib.h>

void hitung_n_ke_0 (int );

int main () {
    int n;

    puts ("Menampilkan bilangan n ke 0");

    printf ("Mau menampilkan dari bilangan berapa? ");
    scanf ("%d", &n);

    hitung_n_ke_0(n);

    return 0;
}

void hitung_n_ke_0 (int n) {
    if (n < 0) {
        return;
    }
    printf("%d\n", n);
    hitung_n_ke_0(n - 1);
}
