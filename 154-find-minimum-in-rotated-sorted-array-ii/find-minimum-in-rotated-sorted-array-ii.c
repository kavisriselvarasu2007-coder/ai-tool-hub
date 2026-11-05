int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // The minimum must be in the right half
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            // The minimum is at 'mid' or in the left half
            right = mid;
        } else {
            // When nums[mid] == nums[right], we can't be sure which side 
            // the minimum is on, but we can safely shrink the right boundary.
            right--;
        }
    }

    return nums[left];
}