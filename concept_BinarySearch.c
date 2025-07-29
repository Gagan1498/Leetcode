#include<stdio.h>

int BinarySearch(int *arr, int target, int size){
    int low = 0, high = size-1;
    
    while (low <= high){

        int mid = (low + high)/2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {0,1,2,5,6,9,10,13};
    int index = 0;

    index = BinarySearch(&arr[0], 10, sizeof(arr)/sizeof(int));
    printf("index = %d\n", index);

    return 0;
}