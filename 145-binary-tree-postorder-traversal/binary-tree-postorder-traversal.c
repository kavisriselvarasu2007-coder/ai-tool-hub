/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Helper function to perform recursive traversal.
 */
void traverse(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    
    traverse(root->left, result, returnSize);   // Visit left subtree
    traverse(root->right, result, returnSize);  // Visit right subtree
    result[(*returnSize)++] = root->val;        // Visit root
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    // Allocate space for up to 100 nodes (based on problem constraints)
    int* result = (int*)malloc(100 * sizeof(int));
    
    traverse(root, result, returnSize);
    
    return result;
}