#include <stdio.h>
#include <stdlib.h>

int cmp=0;
void swap(int*,int*);
void bubbleSort(int[],int);

int main()
{
    int n,i;
    do{
        printf("\nEnter the number of elements to be sorted : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int a[n];
    printf("\nEnter the elements to be sorted : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    bubbleSort(a,n);
    printf("\nSorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nComparisons  = %d\n",cmp);



    printf("\n....EXITING....\n");
    return 0;
}

void bubbleSort(int a[],int n)
{
    int i,cnt,pass=n;
    while(pass)
    {
        cnt = 0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(&a[i],&a[i+1]);
                cnt++;
            }
            cmp++;
        }
        if(cnt==0)
            break;
        pass--;
    }
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
