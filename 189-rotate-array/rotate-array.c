#include <stdio.h>

// Helper function to reverse a portion of the array in-place
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    // Handle cases where k is greater than the array length
    k = k % numsSize;
    if (k == 0) return;
    
    // Step 1: Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    
    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);
    
    // Step 3: Reverse the remaining n - k elements
    reverse(nums, k, numsSize - 1);
}