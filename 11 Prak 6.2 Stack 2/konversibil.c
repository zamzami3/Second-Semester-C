#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct {
    int data [MAX];
    int count;
} stack;

void push (stack *, int);
int pop(stack *);
void inisialisasi(stack *);
int penuh(stack *);
int kosong(stack *);

void biner(int);
void oktal(int);
void heksa(int);

int main() {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int bil, pilih;

    do {
        puts ("KONVERSI BILANGAN DESIMAL");

        printf ("Masukkan bilangan desimal yang akan dikonversi: ");
        scanf ("%d", &bil);

        puts ("MENU KONVERSI");
        puts ("1. BINER");
        puts ("2. OKTAL");
        puts ("3. HEKSADESIMAL");
        puts ("4. Keluar");

        printf ("Masukkan menu konversinya: ");
        scanf ("%d", &pilih);

        switch(pilih) {
        case 1:
            biner(bil);
            break;
        case 2:
            oktal(bil);
            break;
        case 3:
            heksa(bil);
            break;
        case 4:
            puts ("Anda keluar");
            exit(0);
            break;
        default:
            puts ("Pilihan tidak ada dalam menu, Anda keluar");
            exit(0);
            break;
        }
    } while (pilih != 4);

    return 0;
}

void biner(int bil) {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int sisa;

    // di push untuk meniympan sisa
    while (bil > 0) {
        sisa = bil % 2;
        push(&tumpukan, sisa);
        bil /= 2;
    }
    printf("Hasil konversi BINER nya = ");
    // di pop
    while (!kosong(&tumpukan)) {
        printf("%d", pop(&tumpukan));
    }
    printf("\n");
}

void oktal(int bil) {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int sisa;
    // di push untuk menyimpan sisa pembagian
    while (bil > 0) {
        sisa = bil % 8;
        push(&tumpukan, sisa);
        bil /= 8;
    }
    printf("Hasil konversi OKTAL nya = ");
    //di pop
    while (!kosong(&tumpukan)) {
        printf("%d", pop(&tumpukan));
    } 
    printf("\n");
}

void heksa(int bil) {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int sisa, digit;
    // di push
    while (bil > 0) {
        sisa = bil % 16;
        if (sisa < 10) //karakter 0 sampai 9
            push(&tumpukan, sisa + 48);
        else //mjd karakter heksa
            push(&tumpukan, sisa + 55);
        //bil /= 16;
        bil = bil / 16;
    }
    printf("Hasil konversi HEKSADESIMAL nya = ");
    while (!kosong(&tumpukan)) {
        digit = pop(&tumpukan);
        printf("%c", digit);
    }
    printf("\n");
}

void push(stack *s, int bil){
    if (penuh (s)) {
        puts("Stack penuh");
    } else {
        s -> data [s -> count] = bil;
        s -> count++;
    }
}

int pop(stack *s){
    int temp;
    if (kosong(s)) {
        puts ("Stack kosong");
    //return ' ';
    return -1;
    } else {
        s -> count--;
        temp = s -> data [s -> count];
        return temp;
    }
}

void inisialisasi(stack *s){
    s -> count = 0;
}

int penuh(stack *s){
    if (s -> count == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int kosong(stack *s){
    if (s -> count == 0) {
        return 1;
    } else {
        return 0;
    }
} 