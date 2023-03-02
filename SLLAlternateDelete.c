#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
int size=0;

void insert(int item)
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
          
        temp->next=p->next;
        p->next=temp;

    }
    
        
}

void delete()
{

   if(size==0)
    {
        printf("Empty list\n");
        return;
    }

    struct node* p=head;
    struct node* temp=p->next;
    while(p!=NULL && temp!=NULL)
    {
        p->next=temp->next;
        temp->next=NULL;
        free(temp);
        p=p->next;
        if(p!=NULL)
        temp=p->next;
        size--;
    }
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
    printf("Size of list : %d",size);
}

void main()
{
    int ch,item;
    printf("Choose an option :\n");
    printf("1.INSERTANY\n2.DELETEANY\n3.DISPLAY\n4.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
                
            case 2:delete();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}