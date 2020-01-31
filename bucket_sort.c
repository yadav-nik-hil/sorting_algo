//THis code is working correctly
//18MA20027

#include<stdio.h>
#include<stdlib.h>


void bucketSort(float[],int);
void insertionSort(float[],int);


int main()
{
    int n,i;
    do{
        printf("\nEnter the number of elements to Sort : ");
        scanf(" %d",&n);
    }while(n<=0);

    float a[n];
    printf("\nEnter the numbers [Please insert numbers between 0 to 1 (both included)] : \n"); // creating input array
    for(i=0;i<n;i++)
    {
        scanf(" %f",&a[i]);
        if(a[i]<0 || a[i]>1)
            i--;
    }

    bucketSort(a,n);                            // calling of bucketSort function

    printf("\n\nThe Sorted Array is : \n");     // final sorted array
    for(i=0;i<n;i++)
        printf("%f ",a[i]);
    printf("\n\n");



    return 0;
}

void bucketSort(float a[],int n)
{
    int i,j,k,c[10];
    float out[n];

    float **p = (float**)malloc(sizeof(float*)*10);         //p[i] denotes the buckets

    for(i=0;i<10;i++)           //initializing buckets
        c[i] = 0;
    for(i=0;i<n;i++)
    {
        j = a[i]*10;            //Bucket Number
        if(j==10)
            j--;
        c[j]++;                 //counting the number of elements in each bucket
    }

    int count[10];              //Saving the counts in an auxiliary array
    for(i=0;i<10;i++)
    {
        count[i] = c[i];
        /*
        if(i==9)
            printf("c[0.9 - 1.0] = %d ",c[i]);
        else
            printf("c[0.%d - 0.%d] = %d ",i,i+1,c[i]);
        */
    }
    printf("\n\n");
    for(i=0;i<10;i++) 			//assigning size to each bucket
    {
        if(c[i])
        	p[i] = (float*)malloc(sizeof(float)*c[i]);
        else
        	p[i] = NULL;
    }

    for(i=0;i<n;i++)
    {
        j = a[i]*10; 			//Bucket Number
        if(j==10)
            j--;
        p[j][c[j]-1] = a[i];
        c[j]--;
    }

	for(i=0;i<10;i++)           // sort each bucket
		insertionSort(p[i],count[i]);

	k = 0;
    for(i=0;i<10;i++)
    {
		if(p[i])
		{
		    for(j=0;j<count[i];j++)
				out[k++] = p[i][j];
		}
    }

    for(k=0;k<n;k++)
        a[k] = out[k];
}

void insertionSort(float b[],int n)
{
    int i,j;
    float key;

    for(i=1;i<n;i++)
    {
        key = b[i];
        j=i-1;

        while(j>=0 && b[j]>key)
        {
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = key;
    }
}
