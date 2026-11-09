#include <stdio.h>

int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    int len1 = 0;
    // Find lengths manually to avoid needing string.h if desired, 
    // or just use pointers directly since strings are null-terminated.
    
    while (version1[i] != '\0' || version2[j] != '\0') {
        long long num1 = 0;
        long long num2 = 0;
        
        // Parse the revision number from version1
        while (version1[i] != '\0' && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        
        // Parse the revision number from version2
        while (version2[j] != '\0' && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        
        // Compare the parsed revision values
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        
        // Skip the dot '.' character if present
        if (version1[i] == '.') i++;
        if (version2[j] == '.') j++;
    }
    
    return 0; // Versions are identical
}