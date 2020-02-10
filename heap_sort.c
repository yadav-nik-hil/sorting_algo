#include<stdio.h>
#include<stdlib.h>


void swap(int*,int*);
void heapSort(int[],int);
void buildMaxheap(int[],int);
void maxHeapify(int[],int,int);


int main()
{
    int i,N;
    do{
        printf("\nEnter the number of elements to be sorted : \t");
        scanf(" %d",&N);
    }while(N<=0);
    int a[N];

    printf("\nEnter the elements : \n");
    for(i=0;i<N;i++)
        scanf(" %d",&a[i]);

    heapSort(a,N);
    printf("\nSorted array is : \n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);


    printf("\n\n....EXITING....\n\n");
    return 0;
}

void buildMaxheap(int a[],int N)
{
    int i;
    for(i=N/2;i>=0;i--)
        maxHeapify(a,i,N);
}

void maxHeapify(int a[],int i,int N)
{
    int l = (2*i)+1 ,r = (2*i)+2;
    int max = (l<N && a[l]>a[i]) ? l : i;
    if(r<N && a[r]>a[max])
        max = r;
    if(max!=i)
    {
        swap(&a[i],&a[max]);
        maxHeapify(a,max,N);
    }
}

void heapSort(int a[],int N)
{
    buildMaxheap(a,N);
    while(N)
    {
        swap(&a[0],&a[--N]);
        maxHeapify(a,0,N);
    }
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
