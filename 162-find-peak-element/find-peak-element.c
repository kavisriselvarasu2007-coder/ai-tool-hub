int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak must be on the right half
            left = mid + 1;
        } else {
            // Peak must be on the left half (including mid)
            right = mid;
        }
    }

    // When left == right, we have found a peak element index
    return left;
}