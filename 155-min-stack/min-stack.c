#include <stdlib.h>
#include <limits.h>

// Define a node structure for the linked list stack
typedef struct Node {
    int val;
    int min;
    struct Node* next;
} Node;

// Define the MinStack structure
typedef struct {
    Node* top_node;
} MinStack;

// Constructor
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top_node = NULL;
    return obj;
}

// Push value onto stack
void minStackPush(MinStack* obj, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = val;
    
    // Calculate the minimum value at the current level
    if (obj->top_node == NULL) {
        new_node->min = val;
    } else {
        new_node->min = val < obj->top_node->min ? val : obj->top_node->min;
    }
    
    new_node->next = obj->top_node;
    obj->top_node = new_node;
}

// Remove the top element
void minStackPop(MinStack* obj) {
    if (obj->top_node != NULL) {
        Node* temp = obj->top_node;
        obj->top_node = obj->top_node->next;
        free(temp);
    }
}

// Get the top element
int minStackTop(MinStack* obj) {
    return obj->top_node->val;
}

// Retrieve the minimum element in O(1) time
int minStackGetMin(MinStack* obj) {
    return obj->top_node->min;
}

// Free allocated memory
void minStackFree(MinStack* obj) {
    while (obj->top_node != NULL) {
        minStackPop(obj);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */