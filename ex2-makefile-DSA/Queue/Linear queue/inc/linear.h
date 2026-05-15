#ifndef _LINEAR_QUEUE_H
#define _LINEAR_QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QUEUE 5

typedef struct 
{
    int *items;
    int size;
    int front;
    int rear;
}Linear;

void queue_init(Linear *q1);
bool isEmpty(Linear q1);
bool isFull(Linear q1);
int enqueue(Linear *q1, int data);
int dequeue(Linear *q1);
int front(Linear q1);
int rear(Linear q1);
void display(Linear *q1);
void queue_free(Linear *q1);

#endif 