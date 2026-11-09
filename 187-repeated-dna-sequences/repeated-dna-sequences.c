#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for hash map node using separate chaining
typedef struct HashNode {
    char key[11];
    int count;
    struct HashNode* next;
} HashNode;

#define HASH_SIZE 100003

// Hash function to map 10-char DNA string to an index
unsigned int hash(const char* str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

// Function to insert or update count in the hash table
void insertOrUpdate(HashNode** table, const char* key, int* isRepeatedAdded) {
    unsigned int h = hash(key);
    HashNode* curr = table[h];
    
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            curr->count++;
            if (curr->count == 2) {
                *isRepeatedAdded = 1; // Mark that this sequence crossed threshold for the first time
            } else {
                *isRepeatedAdded = 0;
            }
            return;
        }
        curr = curr->next;
    }
    
    // If not found, create a new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->key, key);
    newNode->count = 1;
    newNode->next = table[h];
    table[h] = newNode;
    *isRepeatedAdded = 0;
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    *returnSize = 0;
    int len = strlen(s);
    if (len < 10) return NULL;
    
    // Allocate hash table
    HashNode** hashTable = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    
    // Maximum possible unique 10-letter sequences is (len - 9)
    char** result = (char**)malloc((len - 9) * sizeof(char*));
    
    char sub[11];
    sub[10] = '\0';
    
    for (int i = 0; i <= len - 10; i++) {
        // Extract 10-letter substring
        memcpy(sub, s + i, 10);
        
        int isRepeatedAdded = 0;
        insertOrUpdate(hashTable, sub, &isRepeatedAdded);
        
        // If it was encountered exactly twice now, add to result list
        if (isRepeatedAdded) {
            result[*returnSize] = (char*)malloc(11 * sizeof(char));
            strcpy(result[*returnSize], sub);
            (*returnSize)++;
        }
    }
    
    // Free hash table memory
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = hashTable[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);
    
    return result;
}