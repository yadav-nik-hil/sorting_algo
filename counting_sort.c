#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void countingSort(int[],int);

int main()
{
    int n,i,min;
    do{
        printf("\nEnter the number of elements in array : \t");
        scanf(" %d",&n);
    }while(n<=0);
    int a[n];
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    printf("\nUNSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    min = a[0];
    for(i=1;i<n;i++)        // removing the negatives
    {
        if(a[i]<min)
            min = a[i];
    }
    if(min<0)
    {
        for(i=0;i<n;i++)
            a[i] += abs(min);
    }

    countingSort(a,n);

    if(min<0)               // normalizing the array
    {
        for(i=0;i<n;i++)
            a[i] -= abs(min);
    }

    printf("\nSorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);


    printf("\n\n....EXITING....\n\n");
    return 0;
}

void countingSort(int a[],int n)
{
    int b[n],i,max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    int c[max+1];
    for(i=0;i<=max;i++)         // initializing the auxiliary array
        c[i] = 0;
    for(i=0;i<n;i++)            // storing the frequencies
        c[a[i]] += 1;
    for(i=1;i<=max;i++)         // updating the cumulative frequencies
        c[i] += c[i-1];

    for(i=n-1;i>=0;i--)         // sorting the array
        b[--c[a[i]]] = a[i];

    for(i=0;i<n;i++)
        a[i] = b[i];
}
