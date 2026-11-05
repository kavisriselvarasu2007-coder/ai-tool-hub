#include <stdlib.h>
#include <string.h>

// Helper macro to find the minimum of two integers
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int m = dungeonSize;
    int n = dungeonColSize[0];

    // Use a 1D DP array of size n to optimize space to O(n)
    int* dp = (int*)malloc((n + 1) * sizeof(int));

    // Initialize all DP values to infinity
    for (int j = 0; j <= n; j++) {
        dp[j] = 1e9;
    }

    // Base case: right and down outside bounds for the princess's cell
    dp[n - 1] = 1;

    // Traverse backwards from bottom-right to top-left
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // Health needed if we go right vs down
            int min_health_on_exit = MIN(dp[j], dp[j + 1]);
            
            // Current room health requirement: 
            // min_health_on_exit - dungeon[i][j], but at least 1
            int min_health = min_health_on_exit - dungeon[i][j];
            dp[j] = (min_health <= 0) ? 1 : min_health;
        }
    }

    int result = dp[0];
    free(dp);
    return result;
}