#include<stdio.h>
#include<stdlib.h>

int cnt = 0;

void swap(int*,int*);
int *insertionSort(int*,int);

int main()
{
    int n,i,*a;
    printf("\nEnter the number of elements in array : \t");
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    printf("\nUNSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);

    a = insertionSort(a,n);

    printf("\nSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\nComparisons = %d\n",cnt);

    printf("\n\n....EXITING....\n\n");
    return 0;
}

int *insertionSort(int *a,int n)
{
    int i,j,key,k;
    for(i=1;i<n;i++)
    {
        key = a[i];
        k=i;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>key)
            {
                swap(&a[j],&a[k--]);
                cnt++;
            }
        }
    }

    return a;
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
