/*#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct {
    int data[MAX];
    int count;
} stack;

void push(stack *, int);
int pop(stack *);
void inisialisasi(stack *);
int penuh(stack *);
int kosong(stack *);

void case_push(stack *);
void case_pop(stack *);
void tampil(stack *);

int main() {
    stack tumpukan;
    inisialisasi(&tumpukan);
    int pilih;

    do {
        puts("\nMENU STACK using ARRAY");
        puts("1. Mengisi Stack (PUSH)");
        puts("2. Mengambil Isi Stack (POP)");
        puts("3. Menampilkan isi Stack -> LIFO");
        puts("4. Keluar");

        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilih);

        switch (pilih) {
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
                puts("Anda keluar");
                exit(0);
                break;
            default:
                puts("Pilihan tidak ada dalam menu");
                exit(0);
                break;
        }
    } while (pilih != 4);

    return 0;
}

void case_push(stack *s) {
    int n;

    if (penuh(s)) {
        puts("Stack penuh");
    } else {
        printf("Masukkan data yang mau disimpan: ");
        scanf("%d", &n);
        push(s, n);
    }
}

void case_pop(stack *s) {
    if (kosong(s)) {
        puts("Stack kosong");
    } else {
        printf("Data yang diambil dari stack: %d\n", pop(s));
    }
}

void tampil(stack *s) {
    if (kosong(s)) {
        puts("Stack kosong");
    } else {
        puts("Isi stack (dari paling atas):");
        for (int i = s->count - 1; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

void push(stack *s, int n) {
    s->data[s->count] = n;
    s->count++;
}

int pop(stack *s) {
    s->count--;
    return s->data[s->count];
}

void inisialisasi(stack *s) {
    s->count = 0;
}

int penuh(stack *s) {
    return s->count == MAX;
}

int kosong(stack *s) {
    return s->count == 0;
}
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

bool isOperator(char);
int precedence(char);
void infixToPostfix(char[], char[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Masukkan ekspresi dalam notasi infix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Ekspresi dalam notasi postfix: %s\n", postfix);

    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1)
                top--; // pop '(' from stack
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
} */

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 7

// typedef struct {
//     int data[MAX];
//     int count;
// } stack;

// void push(stack *, int);
// int pop(stack *);
// void inisialisasi(stack *);
// int penuh(stack *);
// int kosong(stack *);

// void biner();
// void oktal();
// void heksa();

// int bil;

// int main() {
//     stack tumpukan;
//     inisialisasi(&tumpukan);
//     int pilih;

//     do {
//         puts("\nKONVERSI BILANGAN DESIMAL");

//         printf("Masukkan bilangan desimal yang akan dikonversi: ");
//         scanf("%d", &bil);

//         puts("MENU KONVERSI");
//         puts("1. BINER");
//         puts("2. OKTAL");
//         puts("3. HEKSADESIMAL");
//         puts("4. Keluar");

//         printf("Masukkan pilihan Anda: ");
//         scanf("%d", &pilih);

//         switch (pilih) {
//         case 1:
//             biner();
//             break;
//         case 2:
//             oktal();
//             break;
//         case 3:
//             heksa();
//             break;
//         case 4:
//             puts("Anda keluar");
//             exit(0);
//             break;
//         default:
//             puts("Pilihan tidak ada dalam menu, Anda keluar");
//             exit(0);
//             break;
//         }
//     } while (pilih != 4);

//     return 0;
// }

// void biner() {
//     int jwb, hasil;
//     while (bil != 0) {
//         bil % 2 = jwb;
//         jwb / 2 = hasil;
//     }
//     printf("Hasil konversi %d ke BINER = %d", bil, hasil);
// }

// void oktal() {
// }

// void heksa() {
// }

// void push(stack *s, int bil) {
//     if (penuh(s)) {
//         puts("Stack penuh");
//     } else {
//         s->data[s->count] = bil;
//         s->count++;
//     }
// }

// int pop(stack *s) {
//     int temp;
//     if (kosong(s)) {
//         puts("Stack kosong");
//         return ' ';
//     } else {
//         s->count--;
//         temp = s->data[s->count];
//         return temp;
//     }
// }

// void inisialisasi(stack *s) {
//     s->count = 0;
// }

// int penuh(stack *s) {
//     if (s->count == MAX) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int kosong(stack *s) {
//     if (s->count == 0) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

/* Implementasi algoritma utk mengubah infix menjadi postfix */
#include <stdio.h>
#include <string.h>
#define MAXSTACK 100
typedef char ItemType;
typedef struct
{
    char item[MAXSTACK]; /* Array yg berisi data tumpukan */
    int count;           /* menunjukkan indeks data paling atas dari
              stack */
} Stack;
Stack tumpukan;
void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
int drjt(char);
void konversi_cetak(char[]);
int main()
{
    char tampung[MAXSTACK], jawab;
    puts("MENGUBAH NOTASI INFIX MENJADI PSOTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        printf("Masukan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);
        printf("Ungkapan postfixnya = ");
        konversi_cetak(tampung);
        puts("");
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
}
void InitializeStack(Stack *S)
{
    S->count = 0;
}
int Empty(Stack *S)
{
    return (S->count == 0);
}
int Full(Stack *S)
{
    return (S->count == MAXSTACK);
}
void Push(ItemType x, Stack *S)
{
    if (Full(S)) // stack penuh
        printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        ++(S->count);
        S->item[S->count] = x;
    }
}
ItemType Pop(Stack *S)
{
    ItemType x;
    if (Empty(S))
    { // stack kosong
        printf("STACK KOSONG!");
        return 0;
    }
    else
    {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}
int drjt(char x) // menentukan derajat operator
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
        return -1; // invalid operator
}
void konversi_cetak(char temp[])
{
    int i, pjg, valid = 1;
    char kar, smtr;
    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i]; // membaca input per karakter
        switch (kar)
        {
        // if kar = '(' -> push ke dalam tumpukan
        case '(':
            Push(kar, &tumpukan);
            break;
        // if kar = operand -> langsung ditulis
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
        /* if kar = operator -> jika tumpukan kosong atau
        derajad kar lbh tinggi dibanding derajad ujung
        tumpukan, push operator ke dalam tumpukan. Jika
        tidak, pop ujung tumpukan dan tulis; Ulangi
        pembandingan kar dengan ujung tumpukan.
        Kemudian kar di-push
        */
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if ((Empty(&tumpukan)) || ((drjt(kar) >
                                        drjt(tumpukan.item[tumpukan.count]))))
                Push(kar, &tumpukan);
            else
            {
                do
                {
                    smtr = Pop(&tumpukan);
                    printf("%c", smtr);
                } while (drjt(kar) <
                         drjt(tumpukan.item[tumpukan.count]));
                Push(kar, &tumpukan);
            }
            break;
        /* if kar = ')' -> pop dan tulis semua isi tumpukan
        sampai ujung tumpukan = '('.
        Pop juga tanda '(' ini, tetapi tidak usah ditulis
        */
        case ')':
            while (tumpukan.item[tumpukan.count] != '(')
            {
                smtr = Pop(&tumpukan);
                printf("%c", smtr);
            }
            Pop(&tumpukan);
            break;
        default: // selain dari kar yang diijinkan
            valid = 0;
            puts("INVALID STSTEMEN");
            break;
        } // end of switch-case
    }     // end of looping for
    /*
    Jika statemen valid, akhir notasi infix telah tercapai,
    sedangkan tumpukan masih belum kosong, pop semua isi
    tumpukan dan tulis hasilnya
    */
    if ((valid != 0) && (!Empty(&tumpukan)))
    {
        smtr = Pop(&tumpukan);
        printf("%c", smtr);
    }
}
