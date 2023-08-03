#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[],int left_index,int right_index);
void merge(int a[],int l,int m,int r);
void printArray(int A[], int size);


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = 6;

    printf("Given array is \n");
    printArray(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge_sort(int arr[],int left_index,int right_index){
    if(left_index<right_index){

        int mid= (left_index+right_index)/2;
        merge_sort(arr,left_index,mid);
        merge_sort(arr,mid+1,right_index);

        merge(arr,left_index,mid,right_index);
    }
}

void merge(int a[],int l,int m,int r){ 
    int i,j,k;

    int left_length = m-l+1;
    int right_length = r-m;

    int *L=(int*)malloc(left_length*sizeof(int));
    int *R=(int*)malloc(right_length*sizeof(int));

    for(i=0;i<left_length;i++)
        L[i] = a[l+i];
    for(j=0;j<right_length;j++)
        R[j] = a[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<left_length && j<right_length){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<left_length){
        a[k]=L[i];
        i++;
        k++;
    }

    while(j<right_length){
        a[k]=R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

