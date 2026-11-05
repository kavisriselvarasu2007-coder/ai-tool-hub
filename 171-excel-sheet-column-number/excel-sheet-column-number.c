#include <string.h>

int titleToNumber(char* columnTitle) {
    long long result = 0;
    
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int current_value = columnTitle[i] - 'A' + 1;
        result = result * 26 + current_value;
    }
    
    return (int)result;
}