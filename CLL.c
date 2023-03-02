#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
int size=0;

void insertNodeAny(int item,int pos)
{
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    size++;
     
     if(pos==1 && head==NULL)
    {
        head = temp;
        temp->next=head;
        
    }

    else if(pos==1)
    {
        struct node* p=head;
        while(p->next!=head)
        {
            p=p->next;
        }

        temp->next=head;
        head = temp;
        p->next=temp;
    }

    else if(pos==size)
    {
        struct node* p=head;
        while(p->next!=head)
        {
            p=p->next;
        }

        temp->next=p->next;
        p->next=temp;
    }

    else{
        struct node* p =head;
        pos=pos-1;
        while(--pos)
        {
            p=p->next;
        }

        temp->next=p->next;
        p->next=temp;
    }

}

void deleteAny(int pos)
{
    if(pos<0 || pos>size+1)
    {
        printf("INVALID INPUT");
        return;
    }

    if(size==0)
    {
        printf("Empty list\n");
        return;
    }

    struct node* p=head;
    if(pos==1)
    {
        struct node* q=head;
        while(q->next!=head)
        {
            q=q->next;
        }

        q->next=p->next;
        head=p->next;
        p->next=NULL;
        free(p);
    }
    
    else{
        struct node* q=head;
        pos=pos-1;
        while(--pos)
       {
           p=p->next;
       }

       q=p->next;
       printf("Element deleted is : %d\n",q->data);

       p->next=q->next;
       q->next=NULL;
       free(q);

    }
    size--;
    printf("Size of list : %d",size);
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
    while(p->next!=head)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\t",p->data);
    printf("Size of list : %d",size);
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