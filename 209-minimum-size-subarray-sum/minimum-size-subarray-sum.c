#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int currentSum = 0;
    int minLength = numsSize + 1; // Initialize with a value larger than any possible array length
    
    for (int right = 0; right < numsSize; right++) {
        currentSum += nums[right];
        
        // While the current window's sum is greater than or equal to target,
        // try to shrink the window from the left to find a smaller length.
        while (currentSum >= target) {
            int currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            
            currentSum -= nums[left];
            left++;
        }
    }
    
    // If minLength was never updated, it means no such subarray exists
    return (minLength == numsSize + 1) ? 0 : minLength;
}