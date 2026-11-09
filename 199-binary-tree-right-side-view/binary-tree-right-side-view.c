#include <stdio.h>
#include <stdlib.h>

// Queue node for BFS level-order traversal
typedef struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    
    // Allocate result array (max possible nodes in constraints is 100)
    int* result = (int*)malloc(100 * sizeof(int));
    
    // Initialize queue for BFS
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    
    // Push root to queue
    QueueNode* rootNode = (QueueNode*)malloc(sizeof(QueueNode));
    rootNode->treeNode = root;
    rootNode->next = NULL;
    front = rear = rootNode;
    
    while (front != NULL) {
        int levelSize = 0;
        QueueNode* curr = front;
        
        // Count how many nodes are in the current level
        while (curr != NULL) {
            levelSize++;
            curr = curr->next;
        }
        
        // Process all nodes of the current level
        for (int i = 0; i < levelSize; i++) {
            // Dequeue node
            QueueNode* temp = front;
            front = front->next;
            if (front == NULL) rear = NULL;
            
            struct TreeNode* node = temp->treeNode;
            free(temp);
            
            // If this is the last node in this level, add it to the result view
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }
            
            // Enqueue left child if it exists
            if (node->left != NULL) {
                QueueNode* leftChild = (QueueNode*)malloc(sizeof(QueueNode));
                leftChild->treeNode = node->left;
                leftChild->next = NULL;
                if (rear == NULL) {
                    front = rear = leftChild;
                } else {
                    rear->next = leftChild;
                    rear = leftChild;
                }
            }
            
            // Enqueue right child if it exists
            if (node->right != NULL) {
                QueueNode* rightChild = (QueueNode*)malloc(sizeof(QueueNode));
                rightChild->treeNode = node->right;
                rightChild->next = NULL;
                if (rear == NULL) {
                    front = rear = rightChild;
                } else {
                    rear->next = rightChild;
                    rear = rightChild;
                }
            }
        }
    }
    
    return result;
}
