#include <stdio.h>
#include <stdlib.h>

// Comparison function to sort intervals by their start times
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 1) {
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }
    
    // Sort intervals based on the starting value
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    // Allocate memory for the merged intervals (at most intervalsSize)
    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int mergedIndex = 0;
    
    // Add the first interval to start comparing
    merged[mergedIndex] = (int*)malloc(2 * sizeof(int));
    merged[mergedIndex][0] = intervals[0][0];
    merged[mergedIndex][1] = intervals[0][1];
    
    for (int i = 1; i < intervalsSize; i++) {
        // If the current interval overlaps with the last merged interval, merge them
        if (intervals[i][0] <= merged[mergedIndex][1]) {
            if (intervals[i][1] > merged[mergedIndex][1]) {
                merged[mergedIndex][1] = intervals[i][1];
            }
        } else {
            // No overlap, add the current interval as a new entry
            mergedIndex++;
            merged[mergedIndex] = (int*)malloc(2 * sizeof(int));
            merged[mergedIndex][0] = intervals[i][0];
            merged[mergedIndex][1] = intervals[i][1];
        }
    }
    
    *returnSize = mergedIndex + 1;
    
    // Set column sizes for each returned interval (always 2)
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    return merged;
}