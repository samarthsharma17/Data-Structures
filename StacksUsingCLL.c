#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;
int size=0;

void push(int item)
{
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    size++;
     
     if(top==NULL)
    {
        top = temp;
        temp->next=top;
        
    }

    else{
        struct node* p =top;
        while(p->next!=top)
        {
            p=p->next;
        }

        temp->next=top;
        top=temp;
        p->next=temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    if(size==1)
    {
        printf("Element popped from stack is : %d\n",top->data);
        top=NULL;
    }

    else{
        printf("Element popped from stack is : %d\n",top->data);
        struct node* p = top;
        while(p->next!=top)
        {
            p=p->next;
        }
        p->next=top->next;
        free(top);
        top=p->next;
    }
    
    size--;
    printf("Size of stack is : %d\n",size);
}

void display()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Elements are : \n");
    struct node* p= top;
    while(p->next!=top)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\t",p->data);
    printf("Size of stack is : %d\n",size);

}

void peek()
{
     if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Element at top is : %d\n",top->data);
}

void main()
{
    
    int ch,n;
    printf("Choose an option :\n");
    printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the element to be pushed\n");
                    scanf("%d",&n);
                    push(n);
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