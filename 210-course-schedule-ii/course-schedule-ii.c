#include <stdio.h>
#include <stdlib.h>

// Helper structure for adjacency list representation of the graph
struct Node {
int dest;
struct Node* next;
};

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    *returnSize = 0;
    
    // Allocate the result array for the course ordering
    int* order = (int*)malloc(numCourses * sizeof(int));
    
    // In-degree array to track how many prerequisites each course has
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    
    // Adjacency list to represent the graph
    struct Node** graph = (struct Node**)calloc(numCourses, sizeof(struct Node*));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        
        // Build graph edge: src -> dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph[src];
        graph[src] = newNode;
        
        // Increment in-degree of the destination course
        inDegree[dest]++;
    }
    
    // Queue for BFS (using an array as a queue)
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    // Push all courses with 0 in-degree (no prerequisites) into the queue
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int count = 0;
    
    // Process the queue
    while (front < rear) {
        int curr = queue[front++];
        order[count++] = curr;
        
        // Decrease in-degree of neighboring courses
        struct Node* temp = graph[curr];
        while (temp != NULL) {
            int neighbor = temp->dest;
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    
    // Free graph memory
    for (int i = 0; i < numCourses; i++) {
        struct Node* currNode = graph[i];
        while (currNode != NULL) {
            struct Node* toFree = currNode;
            currNode = currNode->next;
            free(toFree);
        }
    }
    free(graph);
    free(inDegree);
    free(queue);
    
    // If we couldn't include all courses, a cycle exists (return empty array)
    if (count != numCourses) {
        free(order);
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = numCourses;
    return order;
}