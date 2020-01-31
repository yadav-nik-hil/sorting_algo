#include <stdio.h>
#include <stdlib.h>

void swap(int*,int*);
void selectionSort(int[],int);

int main()
{
    int n;
    do{
        printf("\nEnter the number of elements to be sorted : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int a[n];

    printf("\nEnter the elements : \n");
    int i=0;
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    selectionSort(a,n);
    printf("\nSorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);



    printf("\n\n....EXITING....\n\n");
    return 0;
}

void selectionSort(int a[],int n)
{
    int i,j,minIdx;
    for(i=0;i<n-1;i++)
    {
        minIdx = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[minIdx])
                minIdx = j;
        }
        swap(&a[i],&a[minIdx]);
    }
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
