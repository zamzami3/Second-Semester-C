#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

//stack
typedef struct {
    int *data[MAX];
    int count;
} stack;

//tree
typedef struct node tree;
struct node {
    tree *kiri;
    tree *kanan;
    char data;
};

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
int derajat(char x);
void konversi(char infix[], char postfix[]);

void push(stack *s, char x);
char pop(stack *s);
void push_tree(stack *s, tree* node);
tree* pop_tree(stack *s);

tree* alokasi(char data);
tree* postfixkebinarytree(char *postfix);
void preorder(tree *root);
void inorder(tree *root);
void postorder(tree *root);

int main() {
    char infix[MAX], postfix[MAX];

    printf ("MEMBENTUK BINARY TREE DARI SEBUAH EKSPRESI ARITMATIKA \n DENGAN MEMANFAATKAN STRUKTUR DATA STACK\n");
    printf("Masukkan ekspresi dalam notasi infix: ");
    fgets(infix, sizeof(infix), stdin);

    konversi(infix, postfix);
    puts(" ");
    printf("Ungkapan postfixnya: %s\n", postfix);

    tree* root = postfixkebinarytree(postfix);

    puts(" ");
    printf("Hasil kunjungan secara PREORDER adalah: ");
    preorder(root);
    puts(" ");

    printf("Hasil kunjungan secara INORDER adalah: ");
    inorder(root);
    puts(" ");

    printf("Hasil kunjungan secara POSTORDER adalah: ");
    postorder(root);
    puts(" ");

    return 0;
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

void push(stack *s, char x) {
    if (penuh(s)) {
        puts("Stack penuh");
    } else {
        s->data[s->count++] = x;
    }
}

char pop(stack *s) {
    if (kosong(s)) {
        puts("Stack Kosong");
        return '\0';
    } else {
        return s->data[--s->count];
    }
}

void push_tree(stack *s, tree* node) {
    if (penuh(s)) {
        puts("Stack penuh");
    } else {
        s->data[s->count++] = node;
    }
}

tree* pop_tree(stack *s) {
    if (kosong(s)) {
        puts("Stack Kosong");
        return NULL;
    } else {
        s->count--;
        return s->data[s->count];
    }
}


int derajat(char x) {
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; // operator invalid
}

void konversi(char infix[], char postfix[]) {
    int i, j = 0, panjang;
    char karakter;
    stack tumpukan;
    inisialisasi(&tumpukan);
    panjang = strlen(infix) - 1; //hitung panjang

    for (i = 0; i < panjang; i++) {
        karakter = infix[i]; // membaca input per karakter
        switch (karakter) {
            case '(':
                push(&tumpukan, karakter);
                break;
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6':
            case '7': case '8': case '9':
                postfix[j++] = karakter;
                break;
            case '+': case '-': case '*':
            case '/': case '^':
                while (!kosong(&tumpukan) && derajat(karakter) <= derajat(tumpukan.data[tumpukan.count - 1])) {
                    postfix[j++] = pop(&tumpukan);
                }
                push(&tumpukan, karakter);
                break;
            case ')':
                while (tumpukan.data[tumpukan.count - 1] != '(') {
                    postfix[j++] = pop(&tumpukan);
                }
                pop(&tumpukan);
                break;
            default:
                printf("Karakter tidak valid atau tidak cocok");
                break;
        }
    }
    while (!kosong(&tumpukan)) {
        postfix[j++] = pop(&tumpukan);
    }
    postfix[j] = '\0';
}

tree* alokasi(char data) {
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = data;
    newnode->kiri = newnode->kanan = NULL;
    return newnode;
}

tree* postfixkebinarytree(char *postfix) {
    stack tumpukan;
    inisialisasi(&tumpukan);
    tree *oprtr;
    int i, panjang = strlen(postfix);
    char kar;

    for (i = 0; i < panjang; i++) {
        kar = postfix[i];
        if (kar >= '0' && kar <= '9') {
            push_tree(&tumpukan, alokasi(kar));
        } else {
            oprtr = alokasi(kar);
            oprtr->kanan = pop_tree(&tumpukan);
            oprtr->kiri = pop_tree(&tumpukan);
            push_tree(&tumpukan, oprtr);
        }
    }
    return pop_tree(&tumpukan);
}

void preorder(tree *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void inorder(tree *root) {
    if (root != NULL) {
        inorder(root->kiri);
        printf("%c ", root->data);
        inorder(root->kanan);
    }
}

void postorder(tree *root) {
    if (root != NULL) {
        postorder(root->kiri);
        postorder(root->kanan);
        printf ("%c ", root->data);
    }
}
