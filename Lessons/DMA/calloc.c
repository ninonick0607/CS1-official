#include <stdio.h>
#include <stdlib.h>


/*
    Similar to malloc except for two different things
    Each block is initialized to 0
    It has two parameters or arguments as compared to malloc()


    ptr=(cast-type*)calloc(n,element-size);
    int* ptr=(int*)calloc(5,sizeof())

    ptr=(float*)calloc(25,sizeof(float));
    this statement allocates contiguous space in memory for
    25 elements each with the size of the float
    So basically, 25 blocks of 4bytes each
*/


int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
 
    return 0;
}