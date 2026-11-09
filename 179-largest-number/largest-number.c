#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function to sort strings based on concatenated values
int compare(const void *a, const void *b) {
    char *strA = *(char **)a;
    char *strB = *(char **)b;
    
    // Allocate space for combined strings (A + B and B + A)
    char buffer1[64];
    char buffer2[64];
    
    sprintf(buffer1, "%s%s", strA, strB);
    sprintf(buffer2, "%s%s", strB, strA);
    
    // Compare descending so the largest combination comes first
    return strcmp(buffer2, buffer1);
}

char* largestNumber(int* nums, int numsSize) {
    // Step 1: Convert integers to string representations
    char **strArr = (char **)malloc(numsSize * sizeof(char *));
    for (int i = 0; i < numsSize; i++) {
        strArr[i] = (char *)malloc(20 * sizeof(char));
        sprintf(strArr[i], "%d", nums[i]);
    }
    
    // Step 2: Sort strings using the custom comparator
    qsort(strArr, numsSize, sizeof(char *), compare);
    
    // Step 3: Handle edge case where the largest number is "0" (e.g., [0, 0])
    if (strArr[0][0] == '0') {
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "0");
        
        // Free allocated memory
        for (int i = 0; i < numsSize; i++) free(strArr[i]);
        free(strArr);
        
        return result;
    }
    
    // Step 4: Calculate total length needed for the final result string
    int totalLen = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLen += strlen(strArr[i]);
    }
    
    char *result = (char *)malloc((totalLen + 1) * sizeof(char));
    result[0] = '\0';
    
    // Step 5: Concatenate sorted strings
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strArr[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < numsSize; i++) {
        free(strArr[i]);
    }
    free(strArr);
    
    return result;
}