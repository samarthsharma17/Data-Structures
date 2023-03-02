#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
     struct node* prev;
    struct node* next;
};

struct node* head = NULL;
int size=0;

void insertNodeAny(int item,int pos)
{
    size++;

    if(pos<=0 || pos>size)
    {
        printf("INVALID INPUT\n");
        size--;
        return;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;
    

    if(head==NULL)
    {
        head=temp;
    }

    else if(pos==1)
    {
        temp->next=head;
        head=temp;
        temp->next->prev=temp;
    }

    else if(pos==size)
    {
        struct node* p = head;
        
        while(p->next!=NULL)
        {
            p=p->next;
        }

        temp->prev=p;
        p->next=temp;
    }

    else{
        struct node* p = head;
        pos=pos-1;
        while(--pos)
        {
            p=p->next;
        }

        temp->next=p->next;
        temp->prev=p;
        p->next->prev=temp;
        p->next=temp;
    }
}

void deleteAny(int pos)
{
     if(size==0)
    {
        printf("Empty list\n");
        return;
    }

    if(pos<=0 || pos>size)
    {
        printf("INVALID INPUT\n");
        return;
    }

   

    if(size==1)
    {
        printf("Deleted element is : %d\n",head->data);
        head=NULL;
        free(head);
    }

    else if(pos==1)
    {
        struct node* p=head;
        printf("Deleted element is : %d\n",p->data);
        head=p->next;
        p->next->prev=NULL;
        p->next=NULL;
        free(p);
    }

    else if(pos==size)
    {
        struct node* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }

        printf("Deleted element is : %d\n",p->data);
        p->prev->next=NULL;
        p->prev=NULL;
        free(p);
    }

    else{
        struct node* p=head;
        struct node* curr=head;

        pos=pos-1;
        while(--pos)
        {
            p=p->next;
        }
        curr=p->next;

        
        printf("Deleted element is : %d\n",curr->data);
        p->next=curr->next;
        curr->next->prev=curr->prev;
        curr->next=NULL;
        curr->prev=NULL;
        free(curr);
    }
    size--;
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
    int ch,item,pos1,pos2;
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
                    printf("Enter the position\n");
                    scanf("%d",&pos1);
                    insertNodeAny(item,pos1);
                    break;
                
            case 2: printf("Enter the position\n");
                    scanf("%d",&pos2);
                    deleteAny(pos2);
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}