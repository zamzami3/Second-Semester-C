#include <stdio.h>
#include <stdlib.h>

#define M 999
#define N 5

typedef struct {
    int data[N];
    int count;
} stack;


void inisialisasi (stack*);
int kosong (stack*);
int penuh (stack*);

void push (int, stack*);
int pop (stack*);

void tampil (int [N][N], int[N][N], int [N][N]);
void matriks (int [N][N]);

void warshall(int [N][N], int[N][N], int [N][N]);
int cek (stack*,int);
void rute (int[N][N],int,int,stack*);

void input_titik (int *, int *);
void hitung_beban(int [N][N], int, int);

int main () {
    int titik_asal, titik_tujuan;
    stack a;
    char jwb;
    int Q[N][N] = { //beban
        {M, 1, 3, M, M},
        {M, M, 1, M, 5},
        {3, M, M, 2, M},
        {M, M, M, M, 1},
        {M, M, M, M, M}
    };
    int P[N][N] = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int R[N][N] = {
        {M, 0, 0, M, M},
        {M, M, 0, M, 0},
        {0, M, M, 0, M},
        {M, M, M, M, 0},
        {M, M, M, M, M}
    };
    tampil(Q, P, R);
    warshall(Q, P, R);
    puts ("Setelah pencarian lokasi terdekat");
    puts ("Matriks Beban");
    matriks (Q);
    do {
        input_titik(&titik_asal, &titik_tujuan);
        printf ("Rute Terpendek adalah: ");
        inisialisasi(&a);
        push (titik_tujuan,&a);
        rute (R, titik_asal, titik_tujuan, &a);
        printf ("\b \n");
        hitung_beban(Q, titik_asal, titik_tujuan);
        puts (" ");
        printf ("Ingin memasukkan lagi? (Y/T)? ");
        getchar();
        jwb = getchar();
    } while (jwb == 'Y' || jwb == 'y');
    return 0;
}

void hitung_beban (int Q[N][N], int titik_asal, int titik_tujuan) {
    if (Q[titik_asal - 1][titik_tujuan - 1] == M) {
            printf ("Jalur tidak ditemukan");
    } else {
        printf ("Jumlah Beban: %d ", Q[titik_asal - 1][titik_tujuan - 1]);
    }
}

void input_titik (int *titik_asal, int *titik_tujuan) {
    printf ("Titik asalnya dari mana? ");
    scanf ("%d", titik_asal);
    printf ("Titik tujuannya mau ke mana? ");
    scanf ("%d", titik_tujuan);
}

void inisialisasi (stack *s) {
    s->count = 0;
}

int kosong (stack *s) {
    return s->count == 0;
}

int penuh (stack *s) {
    return s->count == N;
}

void push (int data, stack *s) {
    if (penuh(s)) {
        puts ("Stack sudah penuh. Tidak bisa menyimpan data");
        puts ("Silahkan Coba Lagi.");
    } else {
        s->data[s->count] = data;
        s->count++;
    }
}

int pop (stack *s) {
    int temporary;
    if (kosong(s)) {
        puts ("Stack masih kosong. Tidak bisa mengambil data");
        puts ("Silahkan Coba Lagi.");
        return ' ';
    } else {
        --s->count;
        printf ("%d-", s->data[s->count]);
        temporary = s->data[s->count];
        return temporary;
    }
}

void tampil(int Q[N][N], int P[N][N], int R[N][N]) {
    puts ("Matriks Beban: ");
    matriks(Q);
    puts (" ");
    puts ("Matriks Jalur");
    matriks(P);
    puts (" ");
    puts ("Matriks Rute: ");
    matriks(R);
    puts (" ");
}

void matriks (int a[N][N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (a[i][j] == M) {
                printf ("M ");
            } else {
                printf ("%d ", a[i][j]);
            }
        }
        puts (" ");
    }
}

void warshall (int Q[N][N], int P[N][N], int R[N][N]) {
    int k, i, j;

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[k][j] == 0) {
                        R[i][j] = k + 1;
                    } else {
                        R[i][j] = R[k][j];
                    }
                }
            }
        }
    }
}

int cek (stack *q, int x) {
    int i, status = 0;
    stack cek;
    cek = *q;

    for (i = 0; i < cek.count; i++) {
        if (cek.data[i] == M) {
            break;
        } else {
            status++;
        }
    }
    if (status == cek.count - 1) {
        return 1;
    } else {
        return 0;
    }
}

void rute (int R[N][N], int titik_asal, int titik_tujuan, stack *a) {
    int transit, i, j, k;

    i = titik_asal - 1;
    k = 0;
    for (j = titik_tujuan - 1; j >= 0; j--) {
        k++;
        if (R[i][j] != 0) {
            transit = R [i][j];
            push (transit, a);
        } else {
            push (titik_asal , a);
            break;
        }
    }
    if (!cek (a, M)) {
        for (i = 0; i <= k; i++) {
            pop(a);
        }
    } else {
        printf ("Error, Rute tidak tersedia");
    }
}
