#include "linear.h"

int main ()
{
    Linear l1;
    queue_init(&l1);

    enqueue(&l1, 1);
    enqueue(&l1, 2);
    enqueue(&l1, 3);
    enqueue(&l1, 4);
    enqueue(&l1, 5);
    enqueue(&l1, 6);
    printf("Front: %d\n", front(l1));
    printf("Rear: %d\n", rear(l1));
    display(&l1);

    printf("------------------------------------\n");
    dequeue(&l1);
    display(&l1);

    queue_free(&l1);
    return 0;
}