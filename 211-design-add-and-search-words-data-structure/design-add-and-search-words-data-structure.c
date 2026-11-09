#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} WordDictionary;

// Helper function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

WordDictionary* wordDictionaryCreate() {
    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    obj->root = createNode();
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
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

// Helper DFS function for search to handle '.' wildcards
bool searchHelper(TrieNode* node, char* word, int index) {
    if (node == NULL) return false;
    
    // If we have reached the end of the word, check if it's a valid stored word
    if (word[index] == '\0') {
        return node->isEnd;
    }
    
    char ch = word[index];
    
    // If the character is a wildcard '.', we must check all possible child branches
    if (ch == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                if (searchHelper(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        }
        return false;
    } else {
        // Regular lowercase English letter
        int idx = ch - 'a';
        if (node->children[idx] == NULL) {
            return false;
        }
        return searchHelper(node->children[idx], word, index + 1);
    }
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchHelper(obj->root, word, 0);
}

// Memory freeing helper (good practice)
void freeTrie(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; i++) {
        freeTrie(node->children[i]);
    }
    free(node);
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj == NULL) return;
    freeTrie(obj->root);
    free(obj);
}