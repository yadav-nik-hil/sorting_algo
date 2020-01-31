#include<stdio.h>
#include<stdlib.h>

void merge(int[],int[],int,int,int);
void mergeSort(int[],int[],int,int);


int main()
{
    int i,n;
    do{
        printf("\nEnter the number of elements to Sort : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int arr[n],brr[n];

    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&brr[i]);

    mergeSort(arr,brr,0,n-1);

    printf("\nMergeSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
    for(i=0;i<n;i++)
        printf("%d ",brr[i]);



    printf("\n....EXITING....\n");
    return 0;
}

void merge(int arr[],int brr[],int low,int mid,int high)
{
    int i,j,k=0,a[high-low+1],b[high-low+1];
    for(i=low,j=mid+1;i<=mid && j<=high;)
    {
        if(arr[i]<arr[j])
        {
            a[k] = arr[i];
            b[k++] = brr[i++];
        }
        else
        {
            a[k] = arr[j];
            b[k++] = brr[j++];
        }
    }
    while(i<=mid)
    {
        a[k] = arr[i];
        b[k++] = brr[i++];
    }
    while(j<=high)
    {
        a[k] = arr[j];
        b[k++] = brr[j++];
    }

    for(i=low;i<=high;i++)
    {
        arr[i] = a[i-low];
        brr[i] = b[i-low];
    }
}

void mergeSort(int arr[],int brr[],int low,int high)
{
    if(low<high)
    {
        int mid = (high+low)/2;
        mergeSort(arr,brr,low,mid);
        mergeSort(arr,brr,mid+1,high);
        merge(arr,brr,low,mid,high);
    }
}
