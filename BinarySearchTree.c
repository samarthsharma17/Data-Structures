#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
int size=0;

void insert()
{
    int item;
    printf("Enter the element\n");
    scanf("%d",&item);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    size++;

    if(root==NULL)
    {
        root=temp;
    }

    else{
        struct node* p=root;
        struct node* curr=root;

        while(curr!=NULL)
        {
            p=curr;
            
            if(curr->data<temp->data)
            {
                curr=curr->right;
            }

            else{
                curr=curr->left;
            }
        }

        if(p->data<temp->data)
        {
            p->right=temp;
        }
        
        else{
            p->left=temp;
        }
        
         printf("Size of tree : %d\n",size);
    }
}

void delete(int n)
{
    if(size==0)
    {
        printf("Empty Tree\n");
        return;
    }

    if(size==1)
    {
        struct node* curr=root;
        printf("Element deleted is : %d\n",curr->data);
        free(curr);
    }

    else{
        
        struct node* p =root;
        struct node* curr=root;
        while(curr->data!=n)
        {
            p=curr;
            if(curr->data<n)
            {
                curr=curr->right;
            }

            else{
                curr=curr->left;
            }
        }

        //deleting node with no child
        if(curr->right==NULL && curr->left==NULL)
        {
            printf("Element deleted from tree is : %d\n",curr->data);
            free(curr);
        }

        //deleting node with 1 child
       else if(curr->right==NULL)
        {
            if(p->right==curr)
            {
                p->right=curr->left;
                curr->left=NULL;
            }

            else{
                p->left=curr->left;
                curr->left=NULL;
            }
            free(curr);
        }

        else if(curr->left=NULL)
        {
            if(p->right==curr)
            {
                p->right=curr->right;
                curr->right=NULL;
            }

            else{
                p->left=curr->right;
                curr->right=NULL;
            }
            free(curr);
        }

        //deleting node with 2 child
        else if(curr->right!=NULL && curr->left!=NULL)
        {
            struct node* q;
            q=curr->right;

            if(q->right==NULL && q->left==NULL)
            {
                curr->data=q->data;
                curr->right=NULL;
                free(q);
            }

            else if(q->right!=NULL && q->left==NULL)
            {
                curr->right=q->right;
                curr->data=q->data;
                q->right=NULL;
                free(q);
            }

            else{
                struct node* r=q;
                while(q->left!=NULL)
                {
                    q=q->left;
                }

                if(q->right!=NULL)
                {
                    while(r->left!=q)
                    {
                        r=r->left;
                    }

                    r->left=q->right;
                    curr->data=q->data;
                    q->right=NULL;
                    free(q);
                }

                else{
                    curr->data=q->data;
                    free(q);
                }

            }
            
        }
    }
    size--;
    printf("Size of tree : %d\n",size);
}

void preorder(struct node* t)
{
    printf("%d\t",t->data);

    if(t->left!=NULL)
    {
        preorder(t->left);
    }

    if(t->right!=NULL)
    {
        preorder(t->right);
    }
}

void postorder(struct node* t)
{

    if(t->left!=NULL)
    {
        postorder(t->left);
    }

    if(t->right!=NULL)
    {
        postorder(t->right);
    }

    printf("%d\t",t->data);
}

void inorder(struct node* t)
{

        if(t->left!=NULL)
    {
        inorder(t->left);
    }

    printf("%d\t",t->data);

    if(t->right!=NULL)
    {
        inorder(t->right);
    }

}

void display()
{
    int ch;
    printf("Choose an option\n");
    printf("1.Preorder\n2.Postorder\n3.Inorder\n4.Exit\n");

    while(1)
    {
        printf("\nYour Choice : \n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Elements are : \n");
                    preorder(root);
                   break;

            case 2:printf("Elements are : \n");
                    postorder(root);
                   break;

            case 3:printf("Elements are : \n");
                   inorder(root);
                   break;

            case 4:exit(0);
                   break;

            default : printf("INVALID INPUT");
                  
        }
    }
    printf("Size of tree : %d\n",size);

}

void main()
{
    int ch,n;
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
                
            case 2: printf("Enter the element to be deleted");
                    scanf("%d",n);
                    delete(n);
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}