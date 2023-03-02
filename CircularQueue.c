#include<stdio.h>
#include<stdlib.h>
#define size 5

int cqueue[size];
int rear=-1;
int front=-1;

void insert(int ele)
{
    if((rear==size-1 && front==0) || front==rear+1)
    {
        printf("Stack overflow\n");
        //return;
    }

    else if(rear==-1 && front==-1)
    {
        cqueue[++rear]=ele;
        front=0;
    }

    else if(rear==size-1)
    {
        rear=0;
        cqueue[rear]=ele;
    }

    else{
        cqueue[++rear]=ele;
    }
}

void delete()
{
    if(rear==-1 && front==-1)
    {
        printf("Stack underflow\n");
        //return;
    }

    else if(rear==front)
    {
        printf("Element deleted from queue is : %d\n",cqueue[front]);
        front=rear=-1;
    }

    else if(front==size-1)
    {
        printf("Element deleted from queue is : %d\n",cqueue[front]);
        front=0;
    }

    else{
        printf("Element deleted from queue is : %d\n",cqueue[front++]);
    }
}

void display()
{
    if(rear==-1 && front==-1)
    {
        printf("Stack underflow\n");
        return;
    }

    if(rear>=front)
    {
        printf("Elements in queue are : \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",cqueue[i]);
        }
    }

    else{
        printf("Elements in queue are : \n");
        for(int i=front;i<size;i++)
        {
            printf("%d\t",cqueue[i]);
        }
         for(int j=0;j<=rear;j++)
        {
            printf("%d\t",cqueue[j]);
        }
    }
}

void main()
{
    int ch,n;
    printf("Choose an option\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");

    while(1){
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&n);
                    insert(n);
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