//Infix To Prefix Conversion

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100

//Code for Declarations of stack
char Stack[MAX];
int top = -1;
void push(char );
char pop();
int isEmpty();
int isFull();


//infix to prefix conversion
char infix[MAX];
char prefix[MAX];

void inToprefix();
int precedence(char );
void display();


void strReverse(char arr[],int n)
{
    char temp;
    int i = 0;
   int ln = n - 1;
  while(i < ln)
  {
    temp = arr[i];
    arr[i] = arr[ln];
    arr[ln] = temp;

    --ln;
    ++i;
    
  }

  arr[n] = '\0';
}
int main()
{   
    printf("enter infix expression:\t");
    gets(infix);
    strReverse(infix,strlen(infix));
    inToprefix();
    display();
}

void inToprefix()
{   

    char next;
    int j = 0;
    for(int i = 0 ; i < strlen(infix); i++)
    {   
        char symbol = infix[i];
        switch (symbol)
        {
        case ')': push(symbol);
            break;
        case '(': 
        while((next=pop()) != ')')
         prefix[j++]  = next;
    break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while(!isEmpty() && precedence(symbol) < precedence(Stack[top]))
            prefix[j++] = pop(); 
        push(symbol);
        break;
        default: prefix[j++] = symbol;
            break;
        }
    }
    while(!isEmpty())
        prefix[j++] = pop();
        prefix[j] = '\0';
    strReverse(prefix,strlen(prefix));
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '+': return 1;
        break;
        case '-': return 1;
        break;
        case '*': return 2;
        break;
        case '/': return 2;
        break;
        case '^': return 3;
        break;
        default : return 0;
        break;
    }
}

void display()
{
    printf("The prefix expressi is: \n");
    for(int i = 0; i <strlen(prefix); i++)
    {
        printf("%c",prefix[i]);
    }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    return 0;
}
int isFull()
{
    if(top == MAX -1)
     {
        return 1;
    }
    else
    return 0;
}

void push(char data)
{
    if(isFull())
    {
        printf("stack overflow\n");
        return;
    }
    ++top;
    Stack[top] = data;
}
char pop()
{   
    if(isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }

    char data = Stack[top];
    --top;
    return data;
}
