#include<stdio.h>
#include<stdlib.h>


int binarySearch(int arr[],int low,int high,int n)
{
    if(low<=high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid]==n)
        {
            return mid;
        }

        else if(arr[mid]>n)
        {
            return binarySearch(arr,low,mid-1,n);
        }

        else{
            return binarySearch(arr,mid+1,high,n);
        }

        
    }
    return -1;
}

void main()
{
    int n,size;
    int arr[10];
    printf("Enter the size of the array\n");
    scanf("%d",&size);


    printf("Enter the elements of array:\n");
    for(int i=0;i<size;i++)

    {
        scanf("%d",&arr[i]);
       
    }

    printf("Enter the element\n");
    scanf("%d",&n);

    int x = binarySearch(arr,0,size-1,n);

    if(x==-1)
    {
        printf("Element not present");
    }

    else
        printf("Element %d is present at index %d",n,x+1);

}