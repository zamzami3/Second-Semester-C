#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node {
    int data;
    struct Node* next;
} Node;

void insertAfter(Node* prev_node, int new_data);
void printList(Node* node);

int main()
{
    Node* head = NULL;

    char choice;
    int data;
    int new_data;

    printf("SLL INSERT BEFORE\n");

    do
    {
        printf("Nilai yang akan disimpan : ");
        scanf("%d", &data);

        if (head == NULL)
        {
            head = (Node*)malloc(sizeof(Node));
            head->data = data;
            head->next = NULL;
        }
        else
        {
            insertAfter(head, data);
        }

        printf("Lagi (y/t)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Data yang akan disisipkan sebelum data berapa? ");
    scanf("%d", &data);

    printf("Nilai yang akan disisipkan sebelum data %d : ", data);
    scanf("%d", &new_data);

    Node* prev = NULL;
    Node* current = head;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Data tidak ditemukan dalam SLL\n");
    }
    else
    {
        if (prev == NULL)
        {
            head = (Node*)malloc(sizeof(Node));
            head->data = new_data;
            head->next = current;
        }
        else
        {
            insertAfter(prev, new_data);
        }
    }

    printf("Data yang ada dalam SLL :\n");
    printList(head);

    return 0;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void printList(Node* node)
{
    Node* current = node;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}