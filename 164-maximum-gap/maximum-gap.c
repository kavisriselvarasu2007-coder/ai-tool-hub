#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    
    // Step 1: Find the minimum and maximum values in the array
    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    
    // If all elements are the same, the maximum gap is 0
    if (minVal == maxVal) {
        return 0;
    }
    
    // Step 2: Calculate bucket size and bucket count
    // We want bucket size to be at least 1, and we use numsSize buckets.
    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0) bucketSize = 1;
    
    int bucketCount = (maxVal - minVal) / bucketSize + 1;
    
    // Allocate memory for buckets to track min and max values in each bucket
    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int* bucketHasValue = (int*)calloc(bucketCount, sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }
    
    // Step 3: Distribute numbers into buckets
    for (int i = 0; i < numsSize; i++) {
        int bucketIndex = (nums[i] - minVal) / bucketSize;
        if (nums[i] < bucketMin[bucketIndex]) bucketMin[bucketIndex] = nums[i];
        if (nums[i] > bucketMax[bucketIndex]) bucketMax[bucketIndex] = nums[i];
        bucketHasValue[bucketIndex] = 1;
    }
    
    // Step 4: Compute the maximum gap between adjacent buckets
    int maxGap = 0;
    int previousMax = minVal;
    
    for (int i = 0; i < bucketCount; i++) {
        if (!bucketHasValue[i]) continue;
        
        // The gap is between the current bucket's minimum and the previous non-empty bucket's maximum
        int currentGap = bucketMin[i] - previousMax;
        if (currentGap > maxGap) {
            maxGap = currentGap;
        }
        previousMax = bucketMax[i];
    }
    
    // Free allocated memory
    free(bucketMin);
    free(bucketMax);
    free(bucketHasValue);
    
    return maxGap;
}