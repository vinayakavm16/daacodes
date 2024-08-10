#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high) {
/*int low: This is the starting index of the first subarray.
int mid: This is the ending index of the first subarray and the midpoint of the array to be merged.
int high: This is the ending index of the second subarray.*/
    int b[50000];
    /*array is used to hold the merged elements temporarily*/
    int i = low, j = mid + 1, k = 0;
    /*int i = low: Pointer i starts at the beginning of the first subarray.
int j = mid + 1: Pointer j starts at the beginning of the second subarray.
int k = 0: Pointer k is used to keep track of the index in the temporary array b*/
    // Merge two halves into the temporary array b
    while (i <= mid && j <= high) {
        /*This loop runs while there are elements in both subarrays to be compared.*/
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
 /* If the element in the first subarray is less than or equal to the element in the second subarray,
place the element from the first subarray into b and move to the next element.*/
        } else {
            b[k++] = a[j++];
/* If the element in the second subarray is less, 
place the element from the second subarray into b and move to the next element.*/
        }
    }
    while (i <= mid) {/* If there are any remaining elements in the first subarray 
    (those that have not been copied yet), copy them into b.*/
        b[k++] = a[i++];
    }
    while (j <= high) {/*same for the second subarray*/
        b[k++] = a[j++];
    }

    // Copy the sorted elements back into the original array a[]
    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }
}

void mergesort(int a[],int low ,int high)/*int low: The starting index of the portion of the array to be sorted.
int high: The ending index of the portion of the array to be sorted.*/
{
    int mid;
    if(low<high)/*condition checks if the subarray contains more than one element.*/
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);//mergesort mergesort mersgesort merge
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int n,i;
    printf("enter the no of elements ");
    scanf("%d",&n);
    int a[n];
        for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }
    for(i=0;i<n;i++)
    printf("%d \t ",a[i]);
    float t1,t2;
    t1=clock();
    mergesort(a,0,n-1);
    t2=clock();
    printf("sorted elements\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    printf("time taken is %f\n",(t2-t1));
    return 0;
}