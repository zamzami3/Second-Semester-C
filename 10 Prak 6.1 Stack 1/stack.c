#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct {
    int data [MAX];
    int count;
} stack;

void push (stack *);
int pop(stack *);
void inisialisasi(stack *);
int penuh(stack *);
int kosong(stack *);

int main() {
    stack tumpukan;
    char jawab;

    inisialisasi(&tumpukan);

    do {
        fflush(stdin);
        push (&tumpu  kan);
        fflush(stdin);
        printf ("Ingin memasukkan data stack lagi? ");
        scanf ("%c", &jawab);
    } while ((jawab == 'Y') || (jawab == 'y'));
    puts ("Isi stack (dari paling bawah)");
    while (!kosong(&tumpukan)) {
        printf ("%d", pop(&tumpukan));
        puts(" ");
    }
    return 0;
}

void push(stack *s){
    int n;

    printf ("Masukkan data yang mau di simpan: ");
    scanf ("%d", &n);

    if (penuh (s)) {
        puts("Stack penuh");
    } else {
        s -> data [s -> count] = n;
        s -> count++;
    }
}

int pop(stack *s){
    int temp;
    if (kosong(s)) {
        puts ("Stack kosong");
    return ' ';
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
