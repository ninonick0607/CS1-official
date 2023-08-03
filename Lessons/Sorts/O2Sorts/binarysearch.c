#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int high=numsSize-1;
    int low=0;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        
        if(nums[mid]<target)
            low=mid+1;
        else if(nums[mid]>target)
            high=mid-1;
        else
            return mid;
    }
    
    for(int i=0;i<numsSize;i++){
        if(nums[low]<target && nums[low+1]<target){
            int index= low+1;
            return index;
        }
    }

    return low;
    
}


int main(){
    int nums[4]={1,3,5,6};
    int target=7;
    int numsSize=4;
    int index=searchInsert(nums,numsSize,target);
    printf("%d",index);

    return 0;
}
