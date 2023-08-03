# Quick Select 

- Given an integer k and n undordered elements x1,x2, ..., x_n, find the kth smallest element in this set

Example:
    - Input: Arr[]= {7,10,4,3,20,15}, k=3; Output: 7
        - 7 is the third smallest number
You dont need to sort the entire array to find the kth element

- Main idea:
    - Pick a pivot and partition
    - If k is less than pivot index, look in the left partition
    - Else, look in the right partition
    - If k-1==pivot index, it is the item were looking for 

# Psuedo Code:
    quickSelect(arr,left,right,k){
        if(left==right)
            return array[left] // We got one item, so this has to be it
        pivotIndex=partition(array,left,right)

        if(k-1==pivotIndex)
            return array[pivotIndex]
        else if (pivotIndex > k-1) //Pibot is n-th > k-th
            quickSelect(array,left,pivotIndex-1,k)
        else
            quickSelect(array,pibotIndex+1,right,k)

    }

Ex:

            3,2,1,5,6,4
            p                   
        