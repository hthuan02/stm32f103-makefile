#include "stack.h"

void stack_init(Stack *s1)
{
    s1->items = (int *)malloc(MAX_STACK * sizeof(int));
    s1->size  = MAX_STACK;
    s1->top   = -1;
}

bool isEmpty(Stack s1)
{
    return s1.top == -1;
}

bool isFull(Stack s1)
{
    return s1.top == s1.size -1;
}

int push(Stack *s1, int data)
{
    if(isFull(*s1)) return -1;
    else
    {
        s1->items[++s1->top] = data;
        return data;
    }
}


int pop(Stack *s1)
{
    if(isEmpty(*s1)) return -1;
    else
    {
        int value = s1->items[s1->top--];
        return value;
    }
}

int top(Stack s1)
{
    if(isEmpty(s1)) return -1;
    else return s1.items[s1.top];
}

void display(Stack *s1)
{
    if(isEmpty(*s1)) printf("Stack empty!\n");

    else
    {
        printf("Element of stack is: ");
        for (int i = 0; i <= s1->top; i++)
        {
            printf("%d ", s1->items[i]);
        }
        printf("\n");
        
    }    
}

void stack_free(Stack *s1)
{
    if (s1->items)
    {
        free(s1->items);
        s1->items = NULL;
    }
    
}