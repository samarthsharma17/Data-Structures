#include<stdio.h>
#include<stdlib.h>
#define length 10

int arr[length];
int curr=-1;


int isFull()
{
    return curr==length-1;
}

int isEmpty()
{
    return curr==-1;
}

void insert()
{
    if(isFull())
    {
        printf("Stack overflow\n");
        return;
    }

    int n;
    printf("Enter the element to be inserted\n");
    scanf("%d",&n);
    curr++;
    int i,ind;

    for(ind=0;ind<curr;ind++)
    {
        if(arr[ind]>n)
        {
            break;
        }
    }

    for(i=curr;i>ind;i--)
    {
        arr[i]=arr[i-1];
    }

    arr[ind]=n;
}

void delete()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Element deleted is : %d",arr[0]);

    for(int i=0;i<curr;i++)
    {
        arr[i]=arr[i+1];
    }
    curr--;
}

void display()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    
    printf("Elements are :\n");
    for(int i=0;i<=curr;i++)
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