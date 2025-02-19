#include <stdio.h>
#include <stdlib.h>

// Struktur Node
struct Node {
    int data;
    struct Node* next;
};

// Variabel global untuk head linked list
struct Node* head = NULL;

// Fungsi untuk memasukkan nilai baru ke dalam linked list
void insertSorted(int value) {
    // Buat node baru
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Jika linked list kosong atau nilai head lebih besar dari value
    if (head == NULL || head->data > value) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        struct Node* prev = NULL;

        // Cari posisi yang tepat untuk memasukkan nilai baru
        while (current != NULL && current->data < value) {
            prev = current;
            current = current->next;
        }

        // Tautkan node baru di antara prev dan current
        prev->next = newNode;
        newNode->next = current;
    }
}

// Fungsi untuk menampilkan isi linked list
void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Menambahkan beberapa nilai ke dalam linked list
    insertSorted(5);
    insertSorted(3);
    insertSorted(8);
    insertSorted(1);

    // Menampilkan isi linked list
    printf("Linked List setelah penyisipan: ");
    displayList();

    return 0;
}