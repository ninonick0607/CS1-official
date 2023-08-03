# Quick Sort

- Usually fastest in practice
- Probably most common sorting technique used
- Uses the idea of partitions with recursion to achieve efficiency 
- Another divide and conquer algorithm

Pivot
=
- The algorithm randomly picks an element as a pivot which is used to divide partitions around it
- Some of the ways it picks the pivot is:
    - Always pick first element as pivot
    - Always pick last element as pivot
    - Pick a random element as pivot
    - Pick median as pivot

General Outlook for the Quick sort looks like:

    1) Partion the array with respect to pivot
    2) Sort left part of array using quick sort
    3) Sort right part of array using quick sort

There is no merge step as we have to create a pre condition to the recursion so that the algorithm knows when to stop


# How to partition in place

- Assume we have an array and our pivot is the first element of the array 5
- Create two counters, one after the first index and one at the last index
- Advance the left counter forward until a value greater than the pivot is encountered
- Advance the right counter backwards until a value less than the pivot is encountered

- Once both counters meet their parameter then swap the elements at both counters with each other
- Then continue to move the counters and continue to swap
- Once the counters meet each other then they will swap places with the right counter being on the left and vice versa
- Now you will swap the pivot value with the right counter

# Psuedo code

Another general look:

    quickSort(arr[],low,high){
        
        - IF the low index is smaller than the large
            - Define a variable which runs the partition function
            - Recursively run quicksort from the start to one before the variable for the above partition
            - Recursively run quicksort from one after the partition to the end 

    }

    int partition(int *vals,int low,int high){
        - Initialize three variables for temp, a counter, and for counting the low position

        - The counter declared has to equal low+rand()%(high-low+1) which is used to get a random index number from the range of the array between the lowest number and the highest

        - Swap the value at the counter with the value at the low position because the counter is the pivot and because its easy to swap once the pivot is at the start or end

        - Store the value at low into low position which is now our pivot

        - Increase the low counter

        - WHILE the low counter is less than or equal to the high counter
            - WHILE the low counter is less than or equal to the high counter AND the element at the low index is less than or equal to the element at the low_position/pivot
                - Increase the low counter
            - WHILE the high counter is greater than or equal to the low counter AND the element at the high index is greater than the element at the low_position/pivot
                - Decrease the high counter since its going in reverse
            - IF the low counter is less than the high counter
                - Swap the elements at the low and high index
        Swap the elements at the low position and at the high

        return high
    }


# Analysis of Quick sort run time

Do this