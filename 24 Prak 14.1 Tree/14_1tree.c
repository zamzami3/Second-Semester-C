#include <stdio.h>
#include <stdlib.h>

typedef char typeInfo;
typedef struct node tree;
struct node {
    tree *kiri;
    tree *kanan;
    typeInfo data;
};

tree *root = NULL, *newnode;

void binary_tree(typeInfo data);
void preorder(tree *root); //kiri
void inorder(tree *root); //tengah
void postorder(tree *root); //kanan

tree* cari(tree *root, typeInfo key);
void sisip(typeInfo data); //fungsi alokasi
void bentuk(typeInfo data);
void menu_kunjungan();

void memasukkan_data ();
void mencari_data ();
void case_menukunjungan();

int pilih_menukunjungan; //pre, in, atau post
typeInfo input_data, key;
char jwb_input, jwb_cari;

int main () {
    char jwb_menu;
    puts ("MEMBENTUK SEBUAH TREE");
    memasukkan_data();
    fflush(stdin);
    do {
        menu_kunjungan();
        case_menukunjungan();
        puts (" ");
        printf ("Mencoba mode yang lain [y/t]? ");
        scanf(" %c", &jwb_menu);
    } while ((jwb_menu == 'y') || (jwb_menu == 'Y'));
    fflush(stdin);
    mencari_data();
    return 0;
}

void case_menukunjungan () {
     switch (pilih_menukunjungan) {
        case 1:
            puts ("Hasil kunjungan secara PREORDER adalah: ");
            preorder(root);
            break;
        case 2:
            puts ("Hasil kunjungan secara INORDER adalah: ");
            inorder(root);
            break;
        case 3:
            puts ("Hasil kunjungan secara POSTORDER adalah: ");
            postorder(root);
            break;
        default:
            puts ("Pilihan tidak terdaftar. Silahkan coba lagi");
            exit(0);
        }
}

//gabungan antara sisip() dan bentuk()
void binary_tree (typeInfo data) {
    sisip (data); //pesan alokasi
    if (root == NULL) {
        root = newnode;
    } else {
        bentuk(data);
    }
}

void preorder(tree *root) {
    if (root != NULL) {
        printf("%c\t", root->data);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}
void inorder(tree *root) {
    if (root != NULL) {
        inorder(root->kiri);
        printf("%c\t", root->data);
        inorder(root->kanan);
    }
}

void postorder(tree *root) {
    if (root != NULL) {
        postorder(root->kiri);
        postorder(root->kanan);
        printf ("%c\t", root->data);
    }
}

tree* cari(tree *root, typeInfo key) {
    while ((root != NULL) && (root->data != key)) {
        if (key < root->data) {
            root = root->kiri;
        } else {
            root = root->kanan;
        }
    }
    return root;
}

void sisip (typeInfo n) {
    newnode = (tree*) malloc (sizeof (tree));

    if (newnode == NULL) {
        puts ("Pemesanan memori gagal. Silakan coba lagi");
        exit (0);
    } else {
        newnode->data = n;
        newnode->kiri = NULL;
        newnode->kanan = NULL;
    }
}

void bentuk(typeInfo data) {
    tree *P = root;
    tree *Q = NULL;

    while (P != NULL) {
        Q = P;
        if (data < P->data) {
            P = P->kiri;
        } else if (data > P->data) {
            P = P->kanan;
        } else {
            puts ("Pesan Duplikasi!");
            puts ("Silakan coba lagi");
            exit (0);
        }
    }
    if (data < Q->data) {
        Q->kiri = newnode;
    } else {
        Q->kanan = newnode;
    }
}

void menu_kunjungan() {
    puts (" ");
    puts("Pilih Penelusuran Tree");
    puts ("1. Preorder");
    puts ("2. Postorder");
    puts ("3. Inorder");
    printf ("Pilihan Anda: ");
    scanf ("%d", &pilih_menukunjungan);
}

void memasukkan_data () {
    do {
        printf ("Ketikkan 1 data/infonya: "); //menggunakan soal, memasukkan data one by one
        scanf (" %c", &input_data);
        binary_tree(input_data);
        printf("Ada Data lagi? [y/t]: ");
        scanf(" %c", &jwb_input);
    } while ((jwb_input == 'y') || (jwb_input == 'Y'));
}

void mencari_data () {
    tree *find;

    do {
        puts (" ");
        puts ("Mencari dara dalam tree...");
        printf ("Masukkan data yang dicari: ");
        scanf (" %c", &key);

        find = cari(root, key);
        if (find) {
            printf ("%c ADA dalam tree\n", key);
        } else {
            printf ("%c TIDAK ADA dalam tree\n", key);
        }
        puts (" ");
        printf ("Mau mencari data yang lain [y/t]? ");
        scanf (" %c", &jwb_cari);
    } while ((jwb_cari == 'y') || (jwb_cari == 'Y'));
}
