#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
int size=0;

void insertNode(int item)
{
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    size++;
    
    if(head==NULL)
    {
        head=temp;
    }

    else{
        struct node* p=head;
         while(p->next!=NULL)
        {
              p=p->next;
        }

        p->next=temp;
    }
    
}

void display()
{
    if(size==0)
    {
        printf("Empty list\n");
        return;
    }

    printf("Elements before are : \n");
    struct node* p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("Size of list : %d\n",size);
}

void reverse()
{
    if(size==0)
    {
        printf("Empty list\n");
        return;
    }

   struct node* prev = NULL;
   struct node* curr = head;
   struct node* Next = NULL;
    
    while(curr!=NULL)
    {
        Next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    
    head=prev;

    printf("Elements after are : \n");
    struct node* p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("Size of list : %d",size);
}

void main()
{
    int ch,n;

    printf("Choose an option\n");
    printf("1.INSERT\n2.EXIT");
    int x=1;

    while(x)
    {
        printf("\nYour Choice : \n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&n);
                    insertNode(n);
                    break;

            case 2: x=0;
                    break;

            default: printf("INVALID INPUT");
        }
        
    }

    display();
    reverse();
}