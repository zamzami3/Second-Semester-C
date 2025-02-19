// ada pengkondisian pembandingan antara kata push sama dengan pop
#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct {
    char data [MAX];
    int count;
} stack;

void push (stack *, char);
int pop(stack *);
void inisialisasi(stack *);
int penuh(stack *);
int kosong(stack *);

void palindrom(stack *, char *);

int main() {
    stack tumpukan;
    char jawab;
    char n;

    inisialisasi(&tumpukan);

    printf ("Masukkan data yang mau di simpan: ");
    scanf (" %c", &n);

    //fflush(stdin);
    //push (&tumpukan, n);
    fflush(stdin);
    palindrom(&tumpukan, n);
    fflush(stdin);
    //pop (&tumpukan);
    //palindrom(&tumpukan);

    return 0;
}

void palindrom(stack *s, char *n) {
    int i=0;
    int j=0;
    //untuk push
    while (n[i] != '\0') {
        push(s, n[i]);
        i++;
    }
    while (n[j] != '\0') {
        if (n[j] != pop(s)){
            puts ("bkn Palindrom");
            return;
        }
        j++;
    }
    puts ("Palindrom");
    //int palindrom = 1;

    //if (push(&tumpukan) == pop(&tumpukan)) {
    //if (palindrom) {
      //  puts ("Palindrom");
    //} else {
    //    puts("Bukna Palindrom");
    //}
}

void push(stack *s, char n){

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
