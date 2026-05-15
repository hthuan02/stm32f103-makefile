#include "circular.h"

void queue_init(Circle *q)
{
    q->items = (int *)malloc(MAX_QUEUE * sizeof(int));
    q->size  = MAX_QUEUE;
    q->front = q->rear = -1;
}

bool isEmpty(Circle q)
{
    return q.front == -1;
}

bool isFull(Circle q)
{
    return q.front == (q.rear + 1) % q.size;
}

int enqueue(Circle *q, int data)
{
    if (isFull(*q)) return -1;
    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = data;
    
    // printf("%d\n", data);
    return data;
}

int dequeue(Circle *q)
{   
    if (isEmpty(*q)) return -1;

    // Lấy dữ liệu trước
    int value = q->items[q->front];
    
    // Còn 1 phần tử
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }

    // Còn nhiều hơn 1 phần tử
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    
    return value;
}

int front(Circle q)
{
    if (isEmpty(q)) return -1;
    else return q.items[q.front];
}

int rear(Circle q)
{
    if (isEmpty(q)) return -1;
    else return q.items[q.rear];
}

void display(Circle *q)
{
    if (isEmpty(*q)) printf("Queue empty\n");
    else
    {
        int i = q->front;
        printf("Element of queue is: ");
        while (1)
        {
            printf("%d ", q->items[i]);

            if (i == q->rear)
            {
                break;
            }
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
    
}

void queue_free(Circle *q)
{
    if (q->items)
    {
        free(q->items);
        q->items = NULL;
    }
}
