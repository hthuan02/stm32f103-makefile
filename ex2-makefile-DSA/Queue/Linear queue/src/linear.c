#include "linear.h"

void queue_init(Linear *q1)
{
    q1->items = (int *)malloc(MAX_QUEUE * sizeof(int));
    q1->size  = MAX_QUEUE;
    q1->front = q1->rear = -1;
}

bool isEmpty(Linear q1)
{
    return q1.front == -1;
}

bool isFull(Linear q1)
{
    return q1.rear == q1.size -1;
}

int enqueue(Linear *q1, int data)
{
    if(isFull(*q1)) return -1;
    
    if (q1->front == -1)
    {
        q1->front = 0;
    }
    q1->items[++q1->rear] = data;

    return data;
}


int dequeue(Linear *q1)
{
    if (isEmpty(*q1)) return -1;
    
    int value = q1->items[q1->front++];
    if (q1->front > q1->rear)
    {
        q1->front = q1->rear = -1;
    }
    
    return value;
}

int front(Linear q1)
{
    if (isEmpty(q1)) return -1;
    else return q1.items[q1.front];
}
int rear(Linear q1)
{
    if (isEmpty(q1)) return -1;
    else return q1.items[q1.rear];
}

void display(Linear *q1)
{
    if (isEmpty(*q1))
    {
        printf("Queue empty");
    }
    else
    {
        printf("Element of queue is: ");
        for (int i = q1->front; i <= q1->rear; i++)
        {
            printf("%d ", q1->items[i]);
        }
        printf("\n");
        
    }
    
}

void queue_free(Linear *q1)
{
    if (q1->items)
    {
        free(q1->items);
        q1->items = NULL;
    }
    
}
