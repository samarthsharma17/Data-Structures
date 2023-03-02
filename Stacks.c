#include<stdio.h>
#include<stdlib.h>
#define length 10

int arr[length];
int top=-1;


int isFull()
{
    return top==length-1;
}

int isEmpty()
{
    return top==-1;
}

void push()
{
    if(isFull())
    {
        printf("Stack overflow\n");
        return;
    }

    printf("Enter the number to be pushed\n");
    int n;
    scanf("%d",&n);
    arr[++top]=n;
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Element popped from stack is : %d\n",arr[top--]);
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Element at top is : %d\n",arr[top]);
}

void display()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Elements in the stack are :\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int ch;
    printf("Choose an option :\n");
    printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push();
                    break;
                
            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}