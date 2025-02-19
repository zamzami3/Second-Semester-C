#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main () {
    int n;

    puts ("MENAMPILKAN BILANGAN FUNGSI FIBONACCI DENGAN REKURSI");

    printf ("Mau menampilkan berapa bilangan Fibonacci? ");
    scanf ("%d", &n);

    printf ("Maka, deret bilangan fibonacci nya ");
    for (int i = 0; i < n; i++) {
        printf ("%d ", fibonacci (i));
    }
    return 0;
}

int fibonacci(int n){
    int hasil;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        hasil = fibonacci(n - 1) + fibonacci(n - 2);
        return hasil;
    }
}
