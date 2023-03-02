#include<stdio.h>
#include<stdlib.h>

struct node{
    int ele;
    struct node* next;
};

struct node * top=NULL;

void push()
{
    int n;
    printf("Enter the element\n");
    scanf("%d",&n);

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->ele=n;
    temp->next=NULL;

    temp->next=top;
    top=temp;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    struct node* p=top;
    printf("Element popped from the stack is : %d\n",p->ele);
    top=p->next;
    p->next=NULL;
    free(p);
}

void peek()
{
     if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Element at top is : %d\n",top->ele);
}

void display()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Elements are : \n");
    struct node* p=top;
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
    printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push();
                    break;
                
            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}