#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    // Use two variables to keep track of the maximum money robbed up to the previous houses
    int prev2 = 0; // Represents dp[i-2]
    int prev1 = nums[0]; // Represents dp[i-1]
    
    for (int i = 1; i < numsSize; i++) {
        int current = MAX(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}