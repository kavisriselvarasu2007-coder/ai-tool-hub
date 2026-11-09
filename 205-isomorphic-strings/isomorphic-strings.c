#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {
    // Arrays to store the last seen positions (or mappings) of characters.
    // Using size 256 to cover all ASCII characters. Initialized to 0.
    int mapS[256] = {0};
    int mapT[256] = {0};
    
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        unsigned char c1 = s[i];
        unsigned char c2 = t[i];
        
        // If the mapping state doesn't match, they aren't isomorphic
        if (mapS[c1] != mapT[c2]) {
            return false;
        }
        
        // Record the current position (1-indexed so 0 remains the default "not seen" state)
        mapS[c1] = i + 1;
        mapT[c2] = i + 1;
    }
    
    return true;
}