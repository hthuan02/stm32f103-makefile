#include "stack.h"

int main ()
{
    Stack st1;
    stack_init(&st1);

    push(&st1, 1);
    push(&st1, 2);
    push(&st1, 3);
    push(&st1, 4);
    push(&st1, 5);
    push(&st1, 6);
    printf("Top: %d\n", top(st1));
    display(&st1);
    printf("--------------------\n");

    pop(&st1);
    printf("Top: %d\n", top(st1));
    display(&st1);

    stack_free(&st1);
    return 0;
}