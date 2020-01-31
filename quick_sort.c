#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int*,int*);
int  partition(int*,int,int);
int *quickSort(int*,int,int);

int main()
{
    int n=1,i,*a;
    do
    {
        if(n<=0)
            printf("\nError : ");
        printf("\nEnter the number of elements in array : \t");
        scanf(" %d",&n);
    }while(n<=0);
    a = (int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    printf("\nUNSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);

    quickSort(a,0,n-1);

    printf("\nSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);



    return 0;
}

int *quickSort(int *a,int low,int high)                             // low and high, both index are included
{
    if(low<high)
    {
        int i = partition(a,low,high);                              // call partition
        quickSort(a,low,i-1);
        quickSort(a,i+1,high);
    }
}

int partition(int *a,int low,int high)
{
    //int i = (rand()%(high-low+1))+low;                            // rand_quickSort
    //swap(&a[i],&a[high]);                                         // selecting pivot randomly
    int i,pi = low-1,key = a[high];
    for(i=low;i<high;i++)
    {
        if(a[i]<key)
            swap(&a[++pi],&a[i]);
    }
    swap(&a[high],&a[++pi]);

    return pi;
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
