#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie Node structure
typedef struct TrieNode {
    struct TrieNode* children[26];
    char* word; // Stores the full word at the end node, or NULL otherwise
} TrieNode;

// Helper to create a new Trie node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->word = NULL;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert word into Trie
void insertWord(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            curr->children[idx] = createTrieNode();
        }
        curr = curr->children[idx];
    }
    curr->word = word; // Store pointer to the word
}

// DFS Backtracking function
void dfs(char** board, int r, int c, int rows, int cols, TrieNode* node, char** result, int* returnSize) {
    char ch = board[r][c];
    if (ch == '#' || node->children[ch - 'a'] == NULL) {
        return;
    }
    
    node = node->children[ch - 'a'];
    
    // If we found a complete word
    if (node->word != NULL) {
        result[(*returnSize)++] = node->word;
        node->word = NULL; // Dedup: prevent finding the same word twice
    }
    
    // Mark current cell as visited
    board[r][c] = '#';
    
    // Explore 4 directions: Up, Down, Left, Right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '#') {
            dfs(board, nr, nc, rows, cols, node, result, returnSize);
        }
    }
    
    // Restore cell state (Backtrack)
    board[r][c] = ch;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    
    // Build Trie
    TrieNode* root = createTrieNode();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(root, words[i]);
    }
    
    int rows = boardSize;
    int cols = boardColSize[0];
    
    // Allocate max possible result array (bounded by wordsSize)
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    
    // Start DFS from every cell on the board
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dfs(board, r, c, rows, cols, root, result, returnSize);
        }
    }
    
    return result;
}