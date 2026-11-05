#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    // Allocate space for the result string (max ~7 characters for max int)
    char* result = (char*)malloc(8 * sizeof(char));
    int len = 0;

    while (columnNumber > 0) {
        // Adjust for 1-indexed Excel columns (A-Z)
        columnNumber--;
        
        // Get the current character and append to result buffer
        int remainder = columnNumber % 26;
        result[len++] = 'A' + remainder;
        
        // Move to the next place value
        columnNumber /= 26;
    }
    
    result[len] = '\0';

    // Since digits are generated from right to left, reverse the string
    int left = 0;
    int right = len - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}