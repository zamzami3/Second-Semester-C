//menghitung faktorial dengan rekursi tail

#include <stdio.h>
#include <stdlib.h>

int faktorial_rekursi_tail(int temp, int hasil);

int main() {
    int number;

    printf("Masukkan angka yang akan difaktorialkan: ");
    scanf("%d", &number);

    printf("Faktorialnya: %d\n", faktorial_rekursi_tail(number, 1));

    return 0;
}

int faktorial_rekursi_tail(int temp, int hasil) {
    if (temp < 0) {
        puts("Faktorial tidak bisa negatif, tolong coba lagi");
        exit(0);
    } else if (temp == 0) {
        return hasil;
    } else {
        return faktorial_rekursi_tail(temp - 1, hasil * temp); //5; 4, 1*5   F(4, 5) = 3, 5*4
    }
}

