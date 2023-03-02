#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 100

char stack[size];
int top=-1;

void push(char item)
{
    stack[++top]=item;
}

char pop()
{
    if(top==-1)
    {
        return -1;
    }

    return stack[top--];
}

int priority(char a)
{
    if(a=='(')
       return 0;

    else if(a=='+' || a=='-')
        return 1;

    else if(a=='*' || a=='/' || a=='%')
        return 2;

    else if(a=='^')
        return 3;

}

void main()
{
    char infix[size];
    char *ptr,ch;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    ptr=infix;

    printf("\nStack equals : \n");

    while(*ptr !='\0')
    {
        if(isdigit(*ptr))
        {
            printf("%c",*ptr);
        }

        else if(*ptr=='(')
        {
            push(*ptr);
        }

        else if(*ptr==')')
        {
            while((ch=pop()) != '(')
            {
                printf("%c",ch);
            }
        }

        else{
            while(priority(stack[top]) >= priority(*ptr))
            {
                printf("%c",pop());
            }
            push(*ptr);
        }
        ptr++;
    }

    while(top!=-1)
    {
        printf("%c",pop());
    }


}