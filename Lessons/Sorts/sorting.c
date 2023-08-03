#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Swap
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Selection Sort 
// Worse Case : O(n^2)   Best Case: O(n^2)
void selectionSort(int *arr, int n){

    // Value to store minimum index
    int min_index;

    // Iterate through the array
    for(int i =0; i < n; i++){
        // Default value of minimum index
        min_index = i;

        // Iterate through the loop starting at i to find new minimum index (if any)
        for(int j=i; j < n; j++){
            // If value at current index is smaller than value at minimum index, current index is nre minimum index
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        // Swap
        if(min_index != i){
            swap(&arr[min_index], &arr[i]);
        }
    }
}


// Bubble Sort
// Worse Case : O(n^2)   Best Case: O(n)
void bubbleSort(int *arr, int n){

    // Iterate through array
    for(int i=0; i < n - 1; i++){

        // Iterate through array but stop i indexes before the end
        for(int j=0; j < n - i - 1; j++){

            // If the value at j is greater than to the value to its right, swap them
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Insertion Sort
// Worse Case : O(n^2)   Best Case: O(n)
void insertionSort(int *arr, int n){
    // To store value at i'th index
    int key;

    // Iterate through the loop starting at 1
    for (int i=1; i < n; i++){

        // Assign key to current value at index i
        key = arr[i];

        // Make j iterator to start at one index left of i
        int j = i-1;

        // While j is within our array and the value at j is greater than our key
        while (j >=0 && arr[j] > key){

            // Make the value to the right of j equal to the value at j
            arr[j+1] = arr[j];

            // Shift j to the left
            j--;
        }

        // Make the value to the right of j eqaul to our key
        arr[j+1] = key;
    }
}

// Merge Sort
// Worse Case : O(nlogn)   Best Case: O(nlogn)
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);

// Goal: Split array into chunks of 1, once that finishes, merge them all together in merge
void mergeSort(int *arr, int left, int right){

    // If left index is smaller than right index (to prevent overlap)
    if(left < right){
        
        // Calculate the midpoint of our array
        int mid = left + (right - left)/2;

        // Continue splitting the left half of the array and the right half of the array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid +1, right);

        // Merge everything together
        merge(arr, left, mid, right);
    }
}

// Goal: Split array into two using left, mid, and right. Merge the two new arrays into the main array in sorted order
void merge(int *arr, int left, int mid, int right){

    ////////////////////////////////////////// CREATING AND INITIALIZING TWO NEW ARRAYS /////////////////////////
    // Size of new array1 and new array2
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // Create and initialize the two new arrays
    int leftArray[size1], rightArray[size2];

    for (int i=0; i< size1; i++){
        leftArray[i] = arr[left + i];
    }

    for (int j=0; j < size2; j++){
        rightArray[j] = arr[mid + 1 + j];
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////// COMPARE VALUES AT EACH ARRAY AND INSERT THEM INTO MAIN ARRAY /////////////
    // Index of left array (i) Index of right array (j)
    int i=0, j=0;

    // Index of main array
    int k = left;

    // While we are within both arrays
    while(i<size1 && j<size2){
        // If value in left array index i is less than value in right array index j
        if(leftArray[i] <= rightArray[j]){

            // Plug the value of leftArray index i into the main array
            arr[k] = leftArray[i];
            i++;

        // else meaning the value of rightArray index j is greater than value at leftArray index i    
        }else{
            // Plug the value of the rightArray index j into the main array
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////// EMPTY THE REMAINING ARRAY INTO THE MAIN ARRAY /////////////////////////////
    // ONLY ONE OF THESE LAST TWO WHILE LOOPS WILL RUN
    // If leftArray has not been iterated all the way, empty leftArray into main array
    while(i<size1){
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // If rightArray has not been iterated all the way, empty rightArray into main array
    while(j<size2){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

// Quick Sort
// Worse Case : O(n^2)   Best Case: O(nlogn)
void quickSort(int *arr, int left, int right);
int partition(int *arr, int left, int right);

void quickSort(int *arr, int left, int right){

    if(left < right){

        int part = partition(arr, left, right);

        quickSort(arr, left, part - 1);
        quickSort(arr, part + 1, right);

    }
}

int partition(int *arr, int left, int right){

    int pivot = arr[right];

    int i = left - 1;
    int j = left;

    for(j = left; j <= right-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void randomize(int *arr, int n){
    for(int i=0; i<n; i++){
        arr[i] = rand()%50;
    }
}

int main(){
    srand(time(NULL));

    int const n = 10;
    int *arr = malloc(sizeof(int) * n);

    randomize(arr, n);

    // BUBBLE SORT
    printf("--Bubble Sorting...\n");
    printf("BEFORE\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("AFTER\n");
    printArray(arr, n);
    randomize(arr, 10);

    // INSERTION SORT
    printf("--Insertion Sorting...\n");
    printf("BEFORE\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("AFTER\n");
    printArray(arr, n);
    randomize(arr, 10);

    // SELECTION SORT
    printf("--Selection Sorting...\n");
    printf("BEFORE\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("AFTER\n");
    printArray(arr, n);
    randomize(arr, 10);

    // MERGE SORT
    printf("--Merge Sorting...\n");
    printf("BEFORE\n");
    printArray(arr, n);

    mergeSort(arr,0, n-1);

    printf("AFTER\n");
    printArray(arr, n);
    randomize(arr, 10);

    // QUICK SORT
    printf("--Quick Sorting...\n");
    printf("BEFORE\n");
    printArray(arr, n);

    quickSort(arr,0, n-1);

    printf("AFTER\n");
    printArray(arr, n);
    randomize(arr, 10);

    return 0;
}