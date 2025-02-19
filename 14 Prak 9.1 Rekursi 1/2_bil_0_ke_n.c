#include <stdio.h>
#include <stdlib.h>

void hitung_0_ke_n (int n);

int main () {
    int n;

    puts ("Menampilkan bilangan dari 0 ke n");

    printf ("Mau menampilkan 0 ke bilangan berapa? ");
    scanf ("%d", &n);

    hitung_0_ke_n(n);

    return 0;
}

void hitung_0_ke_n (int n) {
    if (n < 0) {
        return;
    }
    hitung_0_ke_n(n - 1);
    printf("%d\n", n);
}
