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

void case_push(stack *);
void case_pop(stack *);
void tampil (stack *);

int main() {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int pilih;

    do {
        puts ("MENU STACK using ARRAY");
        puts ("1. Mengisi Stack (PUSH)");
        puts ("2. Mengambil Isi Stack (POP)");
        puts ("3. Menampilkan isi Stack -> LIFO");
        puts ("4. Keluar");

        printf ("Masukkan pilihan Anda: ");
        scanf ("%d", &pilih);

        switch(pilih) {
        case 1:
            case_push(&tumpukan);
            break;
        case 2:
            case_pop(&tumpukan);
            break;
        case 3:
            tampil(&tumpukan);
            break;
        case 4:
            puts ("Anda keluar");
            exit(0);
            break;
        default:
            puts ("Pilihan tidak ada dalam menu, anda keluar");
            exit(0);
            break;
        }
    } while (pilih != 4);

    return 0;
}

void case_push(stack *s) {
    int n;

    if (penuh(s)){
        puts ("Stack sudah penuh");
    } else {
        printf ("Masukkan data yang mau di simpan: ");
        scanf ("%d", &n);

        push(s, n);
    }
    puts (" ");
}

void case_pop(stack *s) {
    if (kosong(s)) {
        puts("Stack kosong");
    } else {
        printf("Mengambil data %d, karena berada data paling atas\n", pop(s));
    }
}

void tampil(stack *s) {
    if (kosong(s)) {
        puts("Stack kosong");
    } else {
        puts("Isi stack: ");
        for (int i = s->count - 1; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
    puts (" ");
}

void push(stack *s, int n){
    s -> data [s -> count] = n;
    s -> count++;
}

int pop(stack *s){
    s -> count--;
    return s -> data [s -> count];
}

void inisialisasi(stack *s){
    s -> count = 0;
}

int penuh(stack *s) {
    return s -> count == MAX;
}

int kosong(stack *s){
    return s -> count == 0;
}
