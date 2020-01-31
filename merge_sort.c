#include<stdio.h>
#include<stdlib.h>

int cnt = 0;

void merge(int[],int,int,int);
void mergeSort(int[],int,int);


int main()
{
    int i,n;
    do{
        printf("\nEnter the number of elements to Sort : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int *arr = (int*)malloc(sizeof(int)*n);

    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&arr[i]);

    mergeSort(arr,0,n-1);

    printf("\nMergeSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nComparisons = %d\n",cnt);



    printf("\n....EXITING....\n");
    return 0;
}

void merge(int arr[],int low,int mid,int high)
{
    int i,j,k=0,a[high-low+1];
    for(i=low,j=mid+1;i<=mid && j<=high;)
    {
        if(arr[i]<arr[j])
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++];
        cnt++;
    }
    while(i<=mid)
        a[k++] = arr[i++];
    while(j<=high)
        a[k++] = arr[j++];

    for(i=low;i<=high;i++)
        arr[i] = a[i-low];
}

void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (high+low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}