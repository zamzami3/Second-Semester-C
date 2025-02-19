/*#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
void decToBinOctHex(int decimal)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int temp = decimal;
    while (temp != 0)
    {
        push(stack, temp % 2); // Binary
        temp /= 2;
    }
    printf("Biner: ");
    while (!isEmpty(stack))
    {
        printf("%d", pop(stack));
    }
    temp = decimal;
    while (temp != 0)
    {
        push(stack, temp % 8); // Octal
        temp /= 8;
    }
    printf("\nOktal: ");
    while (!isEmpty(stack))
    {
        printf("%d", pop(stack));
    }
    temp = decimal;
    while (temp != 0)
    {
        int remainder = temp % 16; // Hexadecimal
        if (remainder < 10)
            push(stack, remainder);
        else
            push(stack, remainder + 55); // 'A' is 65 in ASCII
        temp /= 16;
    }
    printf("\nHeksadesimal: ");
    while (!isEmpty(stack))
    {
        int digit = pop(stack);
        if (digit < 10)
            printf("%d", digit);
        else
            printf("%c", digit);
    }
}
int main()
{
    int decimal;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);
    decToBinOctHex(decimal);
    return 0;
} */
