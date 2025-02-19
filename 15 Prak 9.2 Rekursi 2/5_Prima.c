#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prima(int bil, int pembagi);

int main () {
    int bil;

    printf ("Masukkan bilangan bulat: ");
    scanf ("%d", &bil);

    if (prima(bil, 2)) {
        puts ("Bilangan prima");
    } else {
        puts ("Bukan bilangan prima");
    }
    return 0;
}

int prima(int bil, int pembagi) {
    if (bil <= 1) {
        return 0;
    } else if (bil % pembagi == 0) {
        return 0;
    } else if (pembagi * pembagi > bil) {
        return 1;
    }
    return prima(bil, pembagi + 1);
}
