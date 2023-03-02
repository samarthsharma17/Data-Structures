#include<stdio.h>
#include<stdlib.h>
#define length 10

int arr[length];
int front=-1;
int rear=-1;

int isFull()
{
    return rear==length-1;
}

int isEmpty()
{
    return front==-1;
}

void insert()
{
    if(isFull())
    {
        printf("Stack overflow");
        return;
    }

    int n;
    printf("Enter the element to be inserted\n");
    scanf("%d",&n);
    arr[++rear]=n;
    front=0;
}

void delete()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    
    if(rear!=front)
    {
        printf("Element deleted from queue is : %d\n",arr[front]);
        for(int i=0;i<rear;i++)
    {
        arr[i]=arr[i+1];
    }
    rear--;
    }

    else
        {
            printf("Element deleted from queue is : %d\n",arr[front]);
            rear=front=-1;
        }
    
}

void display()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    
    printf("Elements are :\n");
    for(int i=0;i<=rear;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int ch;
    printf("Choose an option :\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert();
                    break;
                
            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}