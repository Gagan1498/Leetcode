#include <stdio.h>

// Assume the function is declared elsewhere
int searchInsert(int* nums, int numsSize, int target){
    
    int out=0;

    for(int i=0; i<numsSize; i++){
        if  (nums[i] == target){
            return out;
        }        
        else if  (i == 0 && target < nums[0]){
            return 0;
        }
        else if (i == numsSize-1){
            return numsSize;
        }
        else if  (nums[i] < target && nums[i+1] > target){
            return out+1;
        }
        else{
            out++;
        }
    }

    return -1;    
}

int main() {
    int nums1[] = {-1, 3, 5, 6};
    int target1 = 5;
    int result1 = searchInsert(nums1, 4, target1);
    printf("Output for target %d: %d\n", target1, result1);

    int nums2[] = {-1, 3, 5, 6};
    int target2 = 2;
    int result2 = searchInsert(nums2, 4, target2);
    printf("Output for target %d: %d\n", target2, result2);

    int nums3[] = {-1, 3, 5, 6};
    int target3 = 0;
    int result3 = searchInsert(nums3, 4, target3);
    printf("Output for target %d: %d\n", target3, result3);

    return 0;
}