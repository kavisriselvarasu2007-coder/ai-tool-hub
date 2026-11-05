#include <stdio.h>

// Helper function to find the maximum of three numbers
int max3(int a, int b, int c) {
    int m = a > b ? a : b;
    return m > c ? m : c;
}

// Helper function to find the minimum of three numbers
int min3(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_so_far = nums[0];
    int current_max = nums[0];
    int current_min = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];
        
        // Temporarily store current_max before updating
        int temp_max = current_max;

        // Current max can be the element itself, or element * previous_max, or element * previous_min
        current_max = max3(num, num * current_max, num * current_min);
        
        // Current min can be the element itself, or element * previous_max, or element * previous_min
        current_min = min3(num, num * temp_max, num * current_min);

        // Update the global maximum product found so far
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }

    return max_so_far;
}