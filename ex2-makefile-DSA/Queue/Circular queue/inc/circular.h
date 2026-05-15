#ifndef _CIRCLE_QUEUE_H
#define _CIRCLE_QUEUE_H

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
}Circle;

void queue_init(Circle *q);
bool isEmpty(Circle q);
bool isFull(Circle q);
int enqueue(Circle *q, int data);
int dequeue(Circle *q);
int front(Circle q);
int rear(Circle q);
void display(Circle *q);
void queue_free(Circle *q);

#endif