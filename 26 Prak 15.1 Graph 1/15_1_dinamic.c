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

void warshall(int [N][N], int[N][N], int [N][N], int);
int cek (stack*, int);
void rute (int[N][N], int, int, stack*);

void tampil (int [N][N], int[N][N], int [N][N], int);
void matriks (int [N][N], int);

void input_titik (int*, int*);
void input_node(int*, int[N][N], int[N][N], int [N][N]);
void hitung_beban(int [N][N], int, int);

int main () {
    int titik_asal, titik_tujuan, jml_node;
    int Q[N][N], P[N][N], R[N][N];
    stack a;
    char jwb;

    input_node(&jml_node, Q, P, R);

    tampil(Q, P, R, jml_node);
    warshall(Q, P, R, jml_node);

    puts ("Setelah pencarian lokasi terdekat");
    puts ("Matriks Beban");
    matriks (Q, jml_node);
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

void input_node(int *jml_node, int Q[N][N], int P[N][N], int R[N][N]) {
    int i, j, k;
    char input[10];
    printf ("Masukkan jumlah node maksimal %d: ", N);
    scanf ("%d", jml_node);

    //pesan peringatan jika user menginputkan jml node > 5
    if (*jml_node > N) {
        *jml_node = N;
        printf ("Eits, jumlah node terlalu besar");
    }
    //input elemen matriks beban (Q)
    puts ("Baiklah, mari kita isi matriks nya");
    for(i = 0; i < *jml_node; i++) {
        printf ("Baris ke-%d: \n", i + 1);
        for (j = 0; j < *jml_node; j++) {
            input[10];
            scanf ("%s", input);
            if (input[0] == '-') { //input - ubah jadi M
                Q[i][j] = M;
            } else {
                Q[i][j] = 0;
                for (k = 0; input[k] != '\0'; k++) {
                    Q[i][j] = Q[i][j] * 10 + (input[k] - '0');
                }
            }
        }
    }
    for (i = 0; i < *jml_node; i++) {
        for (j = 0; j < *jml_node; j++) {
            if (Q[i][j] != M) { //angka
                P[i][j] = 1; //jalur = 1
                R[i][j] = 0; //rute = 0
            } else {           // -
                P[i][j] = 0; //di jalur = 0
                R[i][j] = M; //di rute = M
            }
        }
    }
}

void hitung_beban (int Q[N][N], int titik_asal, int titik_tujuan) {
    if (Q[titik_asal - 1][titik_tujuan - 1] == M) {
            printf ("Jalur tidak ditemukan");
    } else {
        printf ("Jumlah Beban: %d ", Q[titik_asal - 1][titik_tujuan - 1]);
    }
}

void input_titik (int *titik_asal, int *titik_tujuan) {
    printf ("Titik asalnya dari mana ya? ");
    scanf ("%d", titik_asal);
    printf ("Titik tujuannya mau ke mana nih? ");
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
        puts ("Silakan Coba Lagi.");
        return ' ';
    } else {
        --s->count;
        printf ("%d-", s->data[s->count]);
        temporary = s->data[s->count];
        return temporary;
    }
}

void tampil(int Q[N][N], int P[N][N], int R[N][N], int jml_node) {
    puts ("Matriks Beban: ");
    matriks(Q, jml_node);
    puts (" ");
    puts ("Matriks Jalur");
    matriks(P, jml_node);
    puts (" ");
    puts ("Matriks Rute: ");
    matriks(R, jml_node);
    puts (" ");
}

void matriks (int a[N][N], int jml_node) { //print matriks
    int i, j;

    for (i = 0; i < jml_node; i++) {
        for (j = 0; j < jml_node; j++) {
            if (a[i][j] == M) {
                printf ("M ");
            } else {
                printf ("%d ", a[i][j]);
            }
        }
        puts (" ");
    }
}

void warshall (int Q[N][N], int P[N][N], int R[N][N], int jml_node) {
    int k, i, j;

    for (k = 0; k < jml_node; k++) {
        for (i = 0; i < jml_node; i++) {
            for (j = 0; j < jml_node; j++) {
                if (P[i][k] && P[k][j]) {
                    P[i][j] = 1;
                }
                if (Q[i][k] + Q[k][j] < Q[i][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[i][j] == M || R[i][j] == 0){
                        R[i][j] = k + 1;
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
        if (cek.data[i] == x) {
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
