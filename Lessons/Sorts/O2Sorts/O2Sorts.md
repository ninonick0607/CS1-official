# O2 Sorts:

Selection Sort:
=
How it works:
- You start with the first element and begin to swap that with the smallest one in the list
- Now you go to the second element and replace that with the smallest one in the list as well
- Basically has a current value which looks at the entire array and swaps itself with the lowest unsorted number
- Find the minimum element in array
- Swap the minimum element with the first element of the unsorted array
- Repeat this process until array is sorted

Psuedo Code:
    
    void selectionSort(int arr[],int n){
        - Initialize variables minimum and temp_value
        - LOOP the array n-1 times as the last element will be sorted automatically
            - SET the minimum value to the first value in array
            - NESTED LOOP starting from the next value j to the end of array
                - IF the next value is less than the minimum, minimum equals next value.
                - Nested Loop exits once all values are evaluated
                - The current value i needs to find lowest number in list to swap
            - SWAP the current value and next value with temp as middle man.
            - LOOP will continue to update minimum value to the next unsorted value. 
        - End
    }



Bubble Sort:
=
- Start with first element of array and compare it to the second
- Swap if the first element is greater than the second
- Compare second and third elements and swap if the second is greater than the third
- Do the same for the third and fourth

Psuedo Code:

    void bubbleSort(int arr[],int n){
        - Initialize varables
        - LOOP the array n-1 times as the last element will be sorted automatically
            -NESTED LOOP which runs n-i-1 times as it will always be two before the ending of the array since the last two are sorted
                -IF the current value is less than the next
                    - SWAP current value and the next
    }

Insertion Sort:
=
How it works:
- Start with the second element of the arry and compare it with the first
- If the second is smaller than the first then swap them (now sorted)
- Compare the third element with the second and swap them if the third element is smaller
- Now compare the third element with the first and swap them if the third element is smaller (first three numbers sorted)
- Repeat this process until array is sorted

Psuedo Code:

    void insertionSort(int arr[],int n){
        - Initialize variables item to store the current item in the array
        - LOOP starting from 1 as the first element will be sorted once the rest of the numbers pass through
            - SET the item variable equal to the the array at i
            - NESTED LOOP starts one before the the parent loop and decreases so that you travel in reverse, will always be equal to or greater than 0
                - IF the previous value is greater than the item 
                    - The current value will equal the previous
                - ELSE
                    - Break out of loop
            -  SET the previous index equal to the item
    }