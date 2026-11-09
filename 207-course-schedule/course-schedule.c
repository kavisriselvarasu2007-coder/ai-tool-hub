#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper structure for adjacency list representation of the graph
struct Node {
    int dest;
    struct Node* next;
};

// DFS function to detect cycles
bool dfs(int course, struct Node** graph, int* visited) {
    // If the course is currently in the recursion stack, we found a cycle
    if (visited[course] == 1) return true;
    
    // If the course is already fully processed and verified safe, no cycle here
    if (visited[course] == 2) return false;
    
    // Mark the current course as being visited in the current recursion stack (Visiting = 1)
    visited[course] = 1;
    
    // Visit all neighboring/prerequisite courses
    struct Node* curr = graph[course];
    while (curr != NULL) {
        if (dfs(curr->dest, graph, visited)) {
            return true; // Cycle detected
        }
        curr = curr->next;
    }
    
    // Mark the course as fully processed/safe (Visited = 2)
    visited[course] = 2;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Build adjacency list
    struct Node** graph = (struct Node**)calloc(numCourses, sizeof(struct Node*));
    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph[src];
        graph[src] = newNode;
    }
    
    // State array: 0 = unvisited, 1 = visiting (in current DFS stack), 2 = visited (safe)
    int* visited = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(i, graph, visited)) {
                // Free allocated memory before returning on cycle detection
                for (int j = 0; j < numCourses; j++) {
                    struct Node* curr = graph[j];
                    while (curr != NULL) {
                        struct Node* temp = curr;
                        curr = curr->next;
                        free(temp);
                    }
                }
                free(graph);
                free(visited);
                return false; // Cycle detected, cannot finish all courses
            }
        }
    }
    
    // Free allocated memory on successful completion
    for (int i = 0; i < numCourses; i++) {
        struct Node* curr = graph[i]; // Fixed from graph[j] to graph[i]
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(visited);
    
    return true; // No cycles found, all courses can be finished
}