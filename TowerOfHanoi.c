#include<stdio.h>
#include<stdlib.h>


void TOH(int n,char rod_from,char rod_middle,char rod_to)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",rod_from,rod_to);
        return;
    }

    TOH(n-1,rod_from,rod_to,rod_middle);
    printf("Move disk %d from %c to %c\n",n,rod_from,rod_to);
    TOH(n-1,rod_middle,rod_from,rod_to);
}

void main()
{
    int n;
    char A,B,C;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}