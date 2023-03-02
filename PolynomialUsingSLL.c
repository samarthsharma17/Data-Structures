#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

struct node{
    int coeff,exp;
    char var;
    struct node* next;
};

struct node* create()
{
    int again;
    struct node* temp,*first,*newnode;
    first=(struct node*)malloc(sizeof(struct node));

    printf("Enter the coefficient and exponent of the node\n");
    scanf("%d %s %d",&(first->coeff),&(first->var),&(first->exp));
    first->next=NULL;
    temp=first;

    printf("Do youn want to create next Node : 1->YES 0->NO\n");
    scanf("%d",&again);

    while(again)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of the node\n");
        scanf("%d %s %d",&newnode->coeff,&newnode->var,&newnode->exp);
        newnode->next=NULL;

        temp->next=newnode;
        temp=newnode;

         printf("Do youn want to create next Node : 1->YES 0->NO\n");
         scanf("%d",&again);
    }

    return(first);
}

float evaluate(struct node* temp)
{
    float value;
    int coeff=temp->coeff;
    int exp=temp->exp;
    int z;

    printf("Enter the value of the variable : %c\n",temp->var);
    scanf("%d",&z);

    value=(float)coeff*pow(z,exp); 

    return value;
}

float traversal(struct node* first)
{
    struct node* temp=first;
    float sum,a;
    sum=0;
    int z;

    while(temp!=NULL)
    {
        a=evaluate(temp);    
        temp=temp->next;
        sum=sum+a;
    }

    return sum;
}



void main()
{
    struct node* h;

    h=create();
    printf("Result of the polynomial is : %f\n",traversal(h));

}