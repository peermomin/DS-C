/*
ALGORITHM FOR INFIX TO POST FIX CONVERSION
Scan the symbols of the expression from left to right and for each symbol, do the following:

a.If symbol is an operand:
Print that symbol onto the screen.

b.If symbol is a left parenthesis:
Push it on the stack.

c. If symbol is a right parenthesis:
Pop all the operators from the stack upto the first left parenthesis and print them on the screen.
Discard the left and right parentheses.

d. If symbol is an operator:
If the precedence of the operators in the stack are greater than or equal to the current operator, 
then Pop the operators out of the stack and print them onto the
screen, and push the current operator onto the stack.

else
Push the current operator onto the stack.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


char stack_arr[MAX];
int top = -1;

//stack operations
void push(char );
char  pop(void);
int isEmpty(void);
int isFull(void);

char infix[MAX],postfix[MAX];\
void inToPost(void);
int precedence(char);
void display(void);



int main()
{
    printf("Enter Infix Expression:\t");
    gets(infix);
    
    inToPost();
    display();

}

void display()
{   int i = 0;
    printf("The Postfix Expression For this is:\t");
    while(postfix[i] != '\0')
    {
        printf("%c",postfix[i]);
        i++;
    }
}

void inToPost()
{
    char symbol,next;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++) 
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(': push(symbol);
        break;
        case ')': 
        while((next = pop()) != '(')
        {
            postfix[j++] = next;
        }
        break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
           while(!isEmpty() && precedence(stack_arr[top])>=precedence(symbol))
            postfix[j++] = pop();
            push(symbol);
          break;
        default:
        postfix[j++]= symbol;
            break;
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
        postfix[j] = '\0';
    }
}
int precedence(char symbol)
{
    switch (symbol)
    {
        case '+': return 1;
        case '-': return 1;
        case '/': return 2;
        case '*': return 2;
        case '^': return 3;
    default:
        return 0;
    }
}

void push(char data)
{   
    if(isFull())
    {
        printf("Stack Overflow.\n");
        return;
    }
    ++top;
    stack_arr[top] = data;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    char value;
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