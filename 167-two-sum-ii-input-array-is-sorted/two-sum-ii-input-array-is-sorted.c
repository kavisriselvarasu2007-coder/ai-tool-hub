/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    
    // Allocate memory for the result array of size 2
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            // The problem uses 1-indexed arrays, so add 1 to both indices
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // Since the problem guarantees exactly one solution, this point is never reached
    return result;
}