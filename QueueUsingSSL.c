#include<stdio.h>
#include<stdlib.h>

struct node{
    int ele;
    struct node* next;
};

struct node * rear=NULL;
struct node * front=NULL;

void insert()
{
    int n;
    printf("Enter the element\n");
    scanf("%d",&n);

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->ele=n;
    temp->next=NULL;

    if(rear==NULL && front==NULL)
    {
        rear=temp;
        front=temp;
    }

    else{
        rear->next=temp;
        rear=temp;
    }
       
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
        printf("Element deleted from queue is : %d\n",front->ele);
        front=rear=NULL;
        return;
    }

    struct node* p=front;
    printf("Element deleted from queue is : %d\n",p->ele);
    front=p->next;
    p->next=NULL;
    free(p);
    
}

void display()
{
    if(rear==NULL && front==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    struct node* p=front;
     printf("Elements are : \n");
    while(p!=NULL)
    {
        printf("%d\t",p->ele);
        p=p->next;
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