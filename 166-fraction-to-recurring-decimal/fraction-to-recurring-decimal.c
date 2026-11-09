#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple structure for a hash map node to store remainders and their positions
typedef struct HashNode {
    long long key;     // the remainder
    int val;           // the index in the result string where this remainder occurred
    struct HashNode* next;
} HashNode;

#define TABLE_SIZE 10007

int hashFunc(long long key) {
    long long hash = key % TABLE_SIZE;
    if (hash < 0) hash += TABLE_SIZE;
    return hash;
}

void insertHash(HashNode** table, long long key, int val) {
    int idx = hashFunc(key);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->val = val;
    node->next = table[idx];
    table[idx] = node;
}

int findHash(HashNode** table, long long key) {
    int idx = hashFunc(key);
    HashNode* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->val;
        }
        curr = curr->next;
    }
    return -1; // Not found
}

void freeTable(HashNode** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* curr = table[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    
    // Allocate space for result string. Given constraints, length < 10^4.
    int capacity = 20000;
    char* res = (char*)malloc(capacity * sizeof(char));
    int resLen = 0;
    
    // Handle signs (XOR of signs tells us if the final result is negative)
    long long num = numerator;
    long long den = denominator;
    if ((num < 0) ^ (den < 0)) {
        res[resLen++] = '-';
    }
    
    num = llabs(num);
    den = llabs(den);
    
    // 1. Integer part
    long long integerPart = num / den;
    char intBuffer[32];
    sprintf(intBuffer, "%lld", integerPart);
    int intLen = strlen(intBuffer);
    
    // Copy integer part into result string
    strcpy(res + resLen, intBuffer);
    resLen += intLen;
    
    long long remainder = num % den;
    if (remainder == 0) {
        res[resLen] = '\0';
        return res;
    }
    
    // Fractional part
    res[resLen++] = '.';
    
    // Hash table to store remainders and their corresponding string indices
    HashNode** hashTable = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));
    
    while (remainder != 0) {
        int pos = findHash(hashTable, remainder);
        if (pos != -1) {
            // Found a repeating remainder! Insert '(' at the start of the repeating part and ')' at the end.
            // Shift elements right to make room for '('
            for (int i = resLen; i > pos; i--) {
                res[i] = res[i - 1];
            }
            res[pos] = '(';
            resLen++;
            res[resLen++] = ')';
            res[resLen] = '\0';
            
            freeTable(hashTable);
            free(hashTable);
            return res;
        }
        
        // Record current remainder and its output index
        insertHash(hashTable, remainder, resLen);
        
        remainder *= 10;
        long long digit = remainder / den;
        res[resLen++] = digit + '0';
        remainder %= den;
    }
    
    res[resLen] = '\0';
    freeTable(hashTable);
    free(hashTable);
    return res;
}