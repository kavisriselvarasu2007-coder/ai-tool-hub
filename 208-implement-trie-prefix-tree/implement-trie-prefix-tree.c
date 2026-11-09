#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

// Helper function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Initializes the trie object
Trie* trieCreate() {
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->root = createNode();
    return obj;
}

// Inserts the string word into the trie
void trieInsert(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}

// Returns true if the string word is in the trie
bool trieSearch(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            return false;
        }
        curr = curr->children[idx];
    }
    return curr->isEnd;
}

// Returns true if there is a previously inserted string word that has the prefix prefix
bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* curr = obj->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (curr->children[idx] == NULL) {
            return false;
        }
        curr = curr->children[idx];
    }
    return true;
}

// Optional helper to free memory recursively (good practice in C)
void freeTrieNode(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; i++) {
        freeTrieNode(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    freeTrieNode(obj->root);
    free(obj);
}