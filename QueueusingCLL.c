#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* rear = NULL;
struct node* front = NULL;
int size=0;

void insert()
{
     int n;
    printf("Enter the element\n");
    scanf("%d",&n);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data =n;
    temp->next=NULL;
    size++;

    if(rear==NULL && front==NULL)
    {
        rear=front=temp;
        temp->next=rear;
    }

    else{
       rear->next=temp;
        temp->next=front;
        rear=temp;
    }

    printf("Size of queue is : %d\n",size);
}

void delete()
{
    if(rear==NULL && front==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    if(front==rear)
    {
        printf("Element deleted from queue is : %d\n",front->data);
        front=rear=NULL;
        return;
    }

    struct node* p=front;
    printf("Element deleted from queue is : %d\n",p->data);
    front=p->next;
    p->next=NULL;
    free(p);
    rear->next=front;

    size--;
    printf("Size of queue is : %d\n",size);
}

void display()
{
    if(rear==NULL && front==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Elelments are : \n");
    struct node* p=front;
    while(p->next!=front)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\t",p->data);

     printf("Size of queue is : %d\n",size);
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