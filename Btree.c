#include<stdio.h>
#include<stdlib.h>

typedef struct btree{
    int data;
    struct btree *left,*right;
}node;

node *create(){
    int x;
    node* newNode;
    printf("\nEnter data(For no data -1) :");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    newNode = (node*)malloc(sizeof(node));
    newNode->data=x;
    printf("\nEnter left child of %d : ",x);
    newNode->left=create();
    printf("\nEnter right child of %d : ",x);
    newNode->right=create();
    return newNode;
}

void inorder(node *root){
    if(root==NULL)
        return;
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

void postorder(node *root){
    if(root==NULL)
        return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

void preorder(node *root){
    if(root==NULL)
        return;
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
int main(){
    int CASE = 0;
    node *root=NULL;
    while (CASE != 5)
    {
        printf("Choose an option \n 1)create tree \n 2)preorder \n3)inorder \n4)postorder \n5)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
            root = create();
        else if (CASE == 2)
        {
            printf("\nThe preorder traversal of tree is:\n");
            preorder(root);
        }
        else if (CASE == 3)
        {
            printf("\nThe inorder traversal of tree is: \n");
            inorder(root);
        }
        else if (CASE == 4)
        {
            printf("\nThe postorder traversal of tree is:\n");
            postorder(root);
        }
    }
    return 0;
}














