//ARRAY IMPLEMENTATION OF STACK
//ALL OPERATIONS

#include <stdio.h>
#include <stdlib.h>
#define MAX 4


int stack_arr[MAX];
int top = -1;

void push(int );
int pop(void);
int isEmpty(void);
int isFull(void);

void print()
{
    if(isEmpty())
    {
        printf("Stack Underfow\n");
        return;
    }
    int temp = top;
    while(temp >= 0)
    {
        printf("%d\t",stack_arr[temp]);
        --temp;
    }
    printf("\n");
}

int main()
{
    int data;

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    data = pop();
    printf("%d\n",data);

    push(60);
    print();

    return 0;
}

void push(int data)
{   
    if(isFull())
    {
        printf("Stack Overflow.\n");
        return;
    }
    ++top;
    stack_arr[top] = data;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    int value;
    value = stack_arr[top];
    --top;
    return value;
}

int isEmpty()
{
    if(top == -1)
    return 1;
    else
    return 0;
}

int isFull()
{
    if(top == MAX-1)
    return 1;
    else
    return 0;
}