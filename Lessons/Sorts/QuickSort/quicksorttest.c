#include <stdio.h>
#include <stdlib.h>

int quickSelect(int arr[],int left,int right,int k);
void quicksort(int* numbers, int low, int high);
int partition(int* vals, int low, int high);
void swap(int* a, int* b);

int main() {
    int i;
    int numbers[10] = {5, 2, 9, 1, 3, 8, 4, 7, 6, 0};
    
    /*
        quicksort(numbers, 0, 9);
        int select=quickselect(numbers,0,9,4);
        for(i=0;i<9;i++){
            printf("%d \n",select);
        }
    
    */
    
    int select[10];

    for(int j=0;j<=9;j++){
        select[j] = quickSelect(numbers,0,9,j+1);
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", select[i]);
    }
    printf("\n");

    return 0;
}

int quickSelect(int arr[],int left,int right,int k){
    if(left==right)
        return arr[left];
    
    int pivotIndex=partition(arr,left,right);

    if(k-1==pivotIndex)
        return arr[pivotIndex];
    else if(pivotIndex>k-1)
        quickSelect(arr,left,pivotIndex-1,k);
    else
        quickSelect(arr,pivotIndex+1,right,k);
}

void quicksort(int arr[],int low,int high){

    if(low<high){
        int split = partition(arr,low,high);
        quicksort(arr,low,split-1);
        quicksort(arr,split+1,high);
    }

}

int partition(int *vals,int low,int high){

    int temp, pivot,low_pos;

    pivot= low+rand()%(high-low+1);

    temp=vals[pivot];
    vals[pivot]=vals[low];
    vals[low]=temp;

    low_pos=low;

    low++;

    while(low<=high){
        while(low<=high && vals[low]<=vals[low_pos])
            low++;
        while(high>=low && vals[high]>vals[low_pos])
            high--;
        if(low<high){
            temp=vals[low];
            vals[low]=vals[high];
            vals[high]=temp;
        }
    }

    temp=vals[low_pos];
    vals[low_pos]=vals[high];
    vals[high]=temp;

    return high;

}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
