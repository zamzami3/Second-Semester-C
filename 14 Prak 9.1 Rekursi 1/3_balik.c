#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void balik_kata(char kata[], int pjg);

int main() {
    char kata[256];

    puts ("Menampilkan kata yang dibalik dari inputan user");

    printf("Masukkan kata: ");
    fgets(kata, sizeof kata, stdin);

    if (kata[strlen(kata) - 1] == '\n') {
        kata[strlen(kata) - 1] = '\0';
    }
    balik_kata(kata, strlen(kata));
    return 0;
}

void balik_kata(char kata[], int pjg) {
    if (pjg == 0) {
        return;
    }
    printf("%c", kata[pjg - 1]);
    balik_kata(kata, pjg - 1);
}
