#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STACK 5

typedef struct 
{
    int *items;
    int size;
    int top;
}Stack;

void stack_init(Stack *s1);
bool isEmpty(Stack s1);
bool isFull(Stack s1);
int push(Stack *s1, int data);
int pop(Stack *s1);
int top(Stack s1);
void display(Stack *s1);
void stack_free(Stack *s1);

#endif