#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List node to store key, value, and pointers
typedef struct Node {
    int key;
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Hash Map node for direct access to linked list nodes
typedef struct HashNode {
    int key;
    Node* node;
    struct HashNode* next;
} HashNode;

#define TABLE_SIZE 10007 // A prime number for better hash distribution

typedef struct {
    int capacity;
    int size;
    Node* head; // Dummy head for O(1) insertions at the front
    Node* tail; // Dummy tail for O(1) removals at the back
    HashNode** hashTable;
} LRUCache;

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Add key-node pair to hash map
void hashPut(HashNode** table, int key, Node* node) {
    int idx = hash(key);
    HashNode* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->node = node;
            return;
        }
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->node = node;
    newNode->next = table[idx];
    table[idx] = newNode;
}

// Find node in hash map
Node* hashGet(HashNode** table, int key) {
    int idx = hash(key);
    HashNode* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->node;
        }
        curr = curr->next;
    }
    return NULL;
}

// Remove key from hash map
void hashRemove(HashNode** table, int key) {
    int idx = hash(key);
    HashNode* curr = table[idx];
    HashNode* prev = NULL;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                table[idx] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Initialize the LRU Cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    
    // Create dummy head and tail
    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));
    obj->head->key = -1; obj->head->val = -1;
    obj->tail->key = -1; obj->tail->val = -1;
    
    obj->head->next = obj->tail;
    obj->head->prev = NULL;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    
    obj->hashTable = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));
    return obj;
}

// Helper: Remove a node from its current position in the linked list
void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Helper: Add a node right after the dummy head (mark as most recently used)
void addToHead(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = hashGet(obj->hashTable, key);
    if (node == NULL) {
        return -1;
    }
    // Accessing makes it most recently used, so move it to the head
    removeNode(node);
    addToHead(obj, node);
    return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = hashGet(obj->hashTable, key);
    if (node != NULL) {
        // Update value and move to head
        node->val = value;
        removeNode(node);
        addToHead(obj, node);
        return;
    }
    
    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    
    if (obj->size >= obj->capacity) {
        // Evict least recently used node (the one right before dummy tail)
        Node* lru = obj->tail->prev;
        removeNode(lru);
        hashRemove(obj->hashTable, lru->key);
        free(lru);
        obj->size--;
    }
    
    addToHead(obj, newNode);
    hashPut(obj->hashTable, key, newNode);
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* hCurr = obj->hashTable[i];
        while (hCurr != NULL) {
            HashNode* hNext = hCurr->next;
            free(hCurr);
            hCurr = hNext;
        }
    }
    free(obj->hashTable);
    free(obj);
}