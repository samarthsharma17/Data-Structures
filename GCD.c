#include<stdio.h>
#include<stdlib.h>

int GCD(int x,int y)
{
    if(x==0)
    {
        return y;
    }

    if(y==0)
    {
        return x;
    }

    if(x==y)
    return x;

    if(x>y)
        return GCD(x-y,y);
        
        return GCD(x,y-x);
    
}

void main()
{
    int x,y;
    printf("Enter the numbers :\n");
    scanf("%d %d",&x,&y);
    int n = GCD(x,y);
    printf("GCD of %d and %d is %d",x,y,n);
}