#include <stdio.h>

void dfs(char** grid, int r, int c, int rows, int cols) {
    // Check boundaries and if the current cell is water ('0') or already visited
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
        return;
    }
    
    // Mark the current land cell as visited by changing it to '0'
    grid[r][c] = '0';
    
    // Visit all 4 adjacent directions (up, down, left, right)
    dfs(grid, r - 1, c, rows, cols); // Up
    dfs(grid, r + 1, c, rows, cols); // Down
    dfs(grid, r, c - 1, rows, cols); // Left
    dfs(grid, r, c + 1, rows, cols); // Right
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize == 0) return 0;
    
    int rows = gridSize;
    int cols = gridColSize[0];
    int islandCount = 0;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // When we find a piece of land ('1'), it's the start of a new island
            if (grid[r][c] == '1') {
                islandCount++;
                // Use DFS to sink/visit the entire connected island
                dfs(grid, r, c, rows, cols);
            }
        }
    }
    
    return islandCount;
}