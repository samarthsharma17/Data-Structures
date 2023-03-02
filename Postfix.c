#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define POSTFIXSIZE 100
#define MAXSTACK 100

int stack[MAXSTACK];
int top=-1;

void push(int item)
{
    if(top==MAXSTACK-1)
    {
        printf("Stack overflow");
        return;
    }

    stack[++top]=item;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return -1;
    }

    return stack[top--];
}

void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int val;
    int A,B;

    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }

        else {

            A=pop();
            B=pop();

                switch(ch)
                {
                    case '*': val = B*A;
                              break;

                    case '/': val = B/A;
                              break;

                    case '+': val = B+A;
                              break;

                    case '-': val = B-A;
                              break;

                    default : printf("INVALID INPUT");
                              
                }

                push(val);
        }
    }

    printf("Result of the expression is : %d\n",pop());
}

void main()
{
    char postfix[POSTFIXSIZE];

    printf("Enter the postfix expression : \n");
    scanf("%s",postfix);
    

    EvalPostfix(postfix);
}