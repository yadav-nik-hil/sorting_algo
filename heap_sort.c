#include<stdio.h>
#include<stdlib.h>

int N;

void swap(int*,int*);
void heapSort(int[]);
void buildMaxheap(int[]);
void maxHeapify(int[],int);


int main()
{
    int i;
    do{
        printf("\nEnter the number of elements to be sorted : \t");
        scanf(" %d",&N);
    }while(N<=0);
    const int n = N;
    int a[N];

    printf("\nEnter the elements : \n");
    for(i=0;i<N;i++)
        scanf(" %d",&a[i]);

    heapSort(a);
    N = n;
    printf("\nSorted array is : \n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);


    printf("\n\n....EXITING....\n\n");
    return 0;
}

void buildMaxheap(int a[])
{
    int i;
    for(i=N/2;i>=0;i--)
        maxHeapify(a,i);
}

void maxHeapify(int a[],int i)
{
    int l = (2*i)+1 ,r = (2*i)+2;
    int max = (l<N && a[l]>a[i]) ? l : i;
    if(r<N && a[r]>a[max])
        max = r;
    if(max!=i)
    {
        swap(&a[i],&a[max]);
        maxHeapify(a,max);
    }
}

void heapSort(int a[])
{
    buildMaxheap(a);
    while(N)
    {
        swap(&a[0],&a[--N]);
        maxHeapify(a,0);
    }
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
