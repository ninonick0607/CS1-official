#include<stdio.h>
#include<stdlib.h>



int findNonMinOrMax(int* nums, int numsSize){
    int i,j,min,temp;

    if(numsSize<3)
        return -1;

    for(i=0;i<numsSize-1;i++){
        min=i;
        for(j=i+1;j<numsSize;j++){
            if(nums[min]>nums[j]){
                min=j;
            }
        }
        temp=nums[min];
        nums[min]=nums[i];
        nums[i]=temp;
    }
    
    return nums[numsSize-2];
}

int main(){
    int unsorted_nums[]={3,2,1,4};
    int numsSize=4;

    printf("%d ",findNonMinOrMax(unsorted_nums,numsSize));
    
    return 0;

}