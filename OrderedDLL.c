#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
int size=0;

void insertNode()
{
    int item;
    printf("Enter the element\n");
    scanf("%d",&item);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;
    size++;

    if(head==NULL)
    {
        head=temp;
    }

    else{
        struct node* p=head;
        while(p->data<=temp->data && p->next!=NULL)
        {
            p=p->next;
        }

        if(p==head && p->data>temp->data)
        {
            temp->next=p;
            p->prev=temp;
            head=temp;
        }

        else if(p->next==NULL && p->data<=temp->data)
        {

            p->next=temp;
            temp->prev=p;
        }

        else{
            if(p->data<=temp->data)
            {
                temp->next=p->next;
                temp->prev=p;
                p->next->prev=temp;
                p->next=temp;
            }
           
           else{
               temp->next=p;
               temp->prev=p->prev;
               p->prev->next=temp;
               p->prev=temp;
           }
        }
    }
    
    printf("Size of list : %d\n",size);
}

void display()
{
    if(size==0)
    {
        printf("Empty list\n");
        return;
    }

    printf("Elements are : \n");
    struct node* p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("Size of list : %d\n",size);
}

void main()
{
    int ch;
    printf("Choose an option :\n");
    printf("1.INSERT\n2.DISPLAY\n3.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertNode();
                    break;
                
            case 2: display();
                    break;

            case 3: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}