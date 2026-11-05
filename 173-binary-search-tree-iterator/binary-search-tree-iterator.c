#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode** data;
    int top;
    int capacity;
} Stack;

Stack* stackCreate(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return s;
}

void stackPush(Stack* s, struct TreeNode* node) {
    s->data[++(s->top)] = node;
}

struct TreeNode* stackPop(Stack* s) {
    if (s->top == -1) return NULL;
    return s->data[(s->top)--];
}

bool stackIsEmpty(Stack* s) {
    return s->top == -1;
}

void stackFree(Stack* s) {
    free(s->data);
    free(s);
}

typedef struct {
    Stack* stack;
} BSTIterator;

// Helper function to push all left descendants onto the stack
void _left_most_inorder(BSTIterator* obj, struct TreeNode* root) {
    while (root != NULL) {
        stackPush(obj->stack, root);
        root = root->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    // Tree height is bounded by 10^5, stack of size 2000 is more than enough
    obj->stack = stackCreate(2000); 
    _left_most_inorder(obj, root);
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    // The top of the stack is the next smallest element in in-order traversal
    struct TreeNode* topmost_node = stackPop(obj->stack);
    int result = topmost_node->val;
    
    // If the node has a right child, push its leftmost branch onto the stack
    if (topmost_node->right != NULL) {
        _left_most_inorder(obj, topmost_node->right);
    }
    
    return result;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return !stackIsEmpty(obj->stack);
}

void bSTIteratorFree(BSTIterator* obj) {
    stackFree(obj->stack);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 * bool param_2 = bSTIteratorHasNext(obj);
 * bSTIteratorFree(obj);
*/