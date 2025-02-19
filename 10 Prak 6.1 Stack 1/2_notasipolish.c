//penerapan stack pakai polish
#include <stdio.h>
#include <string.h>
#define MAX 50

typedef char ItemType;
typedef struct {
    char data[MAX]; 
    int count;   //count untuk lihat data teratasnya 
} stack;
stack tumpukan;

void inisialisasi(stack *);
int kosong(stack *);
int penuh(stack *);
void push(ItemType, stack *);
ItemType pop(stack *);

int drjt(char);
void konversi(char[]);

int main() {
    char tampung[MAX], jawab;

    puts("MENGUBAH NOTASI INFIX MENJADI PSOTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");

    do {
        inisialisasi(&tumpukan);
        fflush(stdin);
        puts("");

        printf("Masukan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);

        printf("Ungkapan postfixnya = ");
        konversi(tampung);
        puts("");
        fflush(stdin);

        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
}

void inisialisasi(stack *s) {
    s->count = 0;
}

int kosong(stack *s) {
    return (s->count == 0);
}

int penuh(stack *s) {
    return (s->count == MAX);
}

void push(ItemType x, stack *s) {
    if (penuh(s)) {
        printf("Stack penuh");
    } else {
        s->count++;
        s->data[s->count] = x;
    }
}

ItemType pop(stack *s) {
    ItemType x;
    if (kosong(s)) {
        printf("Stack Kosong");
        return 0;
    } else {
        x = s->data[s->count];
        s->count--;
        return x;
    }
}
int drjt(char x) // menentukan derajat operator dengan prioritas derajat tertinggi
{
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; // invalid atau tidak valid
}

void konversi(char temp[]) {
    int i, panjang, valid = 1;
    char kar, smtr;
    panjang = strlen(temp) - 1;
    for (i = 0; i < panjang; i++) {
        kar = temp[i]; // membaca input per karakter
        switch (kar) {
        // untuk ( langsung masukkan alias push (tapi ga dicetak)
        case '(':
            push(kar, &tumpukan);
            break;
        // untuk case angka langsung cetak
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            printf("%c", kar);
            break;
        // untuk karakter hitung, ada dua kondisi
        //kalo kosong atau lebih tinggi, push operator.
        // kalo tidak, pop lalu cetak
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if ((kosong(&tumpukan)) || ((drjt(kar) > drjt(tumpukan.data[tumpukan.count])))) {
                push(kar, &tumpukan);
            } else {
                do {
                    smtr = pop(&tumpukan);
                    printf("%c", smtr);
                } while (drjt(kar) < drjt(tumpukan.data[tumpukan.count]));
                    push(kar, &tumpukan);
            }
            break;
        // karakter ) >>> di pop + cetak semua, kecuali ( jangan cetak
        case ')':
            while (tumpukan.data[tumpukan.count] != '(')
            {
                smtr = pop(&tumpukan);
                printf("%c", smtr);
            }
            pop(&tumpukan);
            break;
        default:
            valid = 0;
            puts("Karakter yang tidak valid atau tidak cocok:>"); //unvalid
            break;
        } 
    }     
    //valid
    if ((valid != 0) && (!kosong(&tumpukan))) {
        smtr = pop(&tumpukan);
        printf("%c", smtr);
    }
}