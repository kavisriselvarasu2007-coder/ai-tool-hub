#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    // Allocate memory for result (at most 100 nodes per constraints)
    int* result = (int*)malloc(100 * sizeof(int));

    // Explicit stack for iterative DFS
    struct TreeNode* stack[100];
    int top = -1;

    // Push root node to stack
    stack[++top] = root;

    while (top >= 0) {
        // Pop top node
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;

        // Push right child first so left child is processed first (LIFO)
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }

    return result;
}
