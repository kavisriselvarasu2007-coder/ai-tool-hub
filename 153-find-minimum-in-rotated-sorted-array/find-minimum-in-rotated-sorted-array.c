int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // it means the minimum element lies in the right half.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // Otherwise, the minimum element is at 'mid' or in the left half.
        else {
            right = mid;
        }
    }

    // When left == right, we have found the minimum element
    return nums[left];
}