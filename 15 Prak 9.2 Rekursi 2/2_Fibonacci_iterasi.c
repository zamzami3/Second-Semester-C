//menampilkan bilangan fibonacci dengan fungsi iterasi

#include <stdio.h>
#include <stdlib.h>

void fibonacci(int bil);

int main () {
    int bil;

    puts ("MENAMPILKAN BILANGAN FUNGSI FIBONACCI DENGAN ITERASI");
    printf ("Mau menampilkan berapa bilangan Fibonacci? ");
    scanf ("%d", &bil);

    fibonacci(bil);

    return 0;
}

void fibonacci (int bil) {
    int a, b, temp;
    a = 0;
    b = 1;

    printf ("Deret Fibonacci nya: ");
    for (int i = 0; i <= bil; i++) {
        printf ("%d ", a); //0 1 1 2
        temp = a;
        a = b;
        b = temp + b;
    }
}
