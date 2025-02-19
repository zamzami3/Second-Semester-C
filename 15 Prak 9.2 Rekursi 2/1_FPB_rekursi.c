#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fpb(int bil1, int bil2);

int main() {
    int bil1, bil2;

    printf("Masukkan bilangan bulat positif pertama: ");
    scanf("%d", &bil1);

    printf("Masukkan bilangan bulat positif kedua: ");
    scanf("%d", &bil2);

    printf("FPB nya adalah %d", fpb(bil1, bil2));

    return 0;
}

int fpb(int bil1, int bil2) {
    if (bil2 == 0) {
        return bil1;
    }
    return fpb(bil2, bil1 % bil2);
}
