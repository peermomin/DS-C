
//ARRAY IMPLEMENTATION OF STACK
//push an element onto stack

#include <stdio.h>
#define MAX 4


int stack_arr[MAX];
int top = -1;

void push(int );

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    return 0;
}

void push(int data)
{   
    if(top == MAX-1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    ++top;
    stack_arr[top] = data;
}
