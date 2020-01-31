#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void radixSort(int[],int);
void countingSort(int[],int,int);

int main()
{
    int n,i;
    do{
        printf("\nEnter the number of elements to sort [positive nos. only] : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int a[n];
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
        if(a[i]<=0)
            i--;
    }

    radixSort(a,n);

    printf("\nSorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);



    printf("\n\n....EXITING....\n\n");
    int p = main();
    return 0;
}

void countingSort(int a[],int n,int exp)
{
    int b[n],i,c[10];
    for(i=0;i<10;i++)
        c[i] = 0;
    for(i=0;i<n;i++)
        c[ (a[i]/exp)%10 ]++;
    for(i=1;i<10;i++)
        c[i] += c[i-1];
    for(i=0;i<n;i++)
    {
        b[c[ (a[i]/exp)%10 ]-1 ] = a[i];
        c[ (a[i]/exp)%10 ]--;
    }
    for(i=0;i<n;i++)
        a[i] = b[i];
}

void radixSort(int a[],int n)
{
    int i,max=a[0];
    for(i=1;i<n;i++)
        max = (a[i]>max) ? a[i] : max;
    for(i=1; max/i >0; i*=10)
        countingSort(a,n,i);
}
