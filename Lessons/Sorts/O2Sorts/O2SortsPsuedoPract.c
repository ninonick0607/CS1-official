#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[],int n);
void selectionSort(int arr[],int n);
void bubbleSort(int arr[],int n);
void insertionSort(int arr[],int n);

int main(){//    0 1 2 3 4
    int arr[] = {4,3,2,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    //selectionSort(arr,n);
    //bubbleSort(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}

void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void selectionSort(int arr[],int n){
    int i,j,min,temp;

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void bubbleSort(int arr[],int n){

    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insertionSort(int arr[],int n){
    int i,j,item;

    for(i=1;i<n;i++){
        item=arr[i];
        for(j=i-1;j>=0;j--){
            if(item<arr[j])
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=item;
    }

}