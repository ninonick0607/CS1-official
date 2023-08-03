#include <stdio.h>
#include <stdlib.h>



void swap(int *a,int *b);
void selectionSort(int arr[],int n);
void bubbleSort(int arr[],int n);
void insertionSort(int arr[],int n);
void printArray(int arr[],int n);

//Main function
int main(){
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    //selectionSort(arr,n);
    //bubbleSort(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}


void selectionSort(int arr[],int n){

    int i,j,min;

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        swap(&arr[min],&arr[i]);
    }
}


void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}


void insertionSort(int arr[],int n){
    int i,j,item;
    for(i=1;i<n;i++){ 
        item=arr[i]; 
        for(j=i-1;j>=0;j--){
            if(arr[j]>item){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=item; 
    }
}

//Print array
void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//Swap function
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
