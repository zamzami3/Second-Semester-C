#include <stdio.h>
#include <stdlib.h>

int faktorial_rekursi(int temp);

int main() {
    int number;

    printf("Masukkan angka yang akan difaktorialkan: ");
    scanf("%d", &number);

    printf("Faktorialnya: %d\n", faktorial_rekursi(number));

    return 0;
}

int faktorial_rekursi(int temp) {
    if (temp > 1) { //case faktorial bil bulat positif
        return temp * faktorial_rekursi(temp - 1); //F(5) = 5 * F(4), F(4) = 4 * F(3), F(3) = 3 * F(2), F(2) = 2 * F(1)
    } else if (temp == 1 || temp == 0) { //kasus 0! atau 1!
        return 1; //0! atau 1! = 1
    } else { //case bilangan negatif
        puts("Faktorial tidak bisa negatif. Silahkan coba lagi");
        exit(0);
    }
}
