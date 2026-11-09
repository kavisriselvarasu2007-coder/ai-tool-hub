#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize <= 0 || k <= 0) return 0;
    
    // If k is large enough, it becomes equivalent to unlimited transactions (Best Time to Buy and Sell Stock II)
    if (k >= pricesSize / 2) {
        int max_profit = 0;
        for (int i = 1; i < pricesSize; i++) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
    
    // Allocate arrays for buy and sell states for each transaction up to k
    int* buy = (int*)malloc((k + 1) * sizeof(int));
    int* sell = (int*)malloc((k + 1) * sizeof(int));
    
    for (int j = 0; j <= k; j++) {
        buy[j] = -prices[0];
        sell[j] = 0;
    }
    
    for (int i = 1; i < pricesSize; i++) {
        for (int j = 1; j <= k; j++) {
            buy[j] = MAX(buy[j], sell[j - 1] - prices[i]);
            sell[j] = MAX(sell[j], buy[j] + prices[i]);
        }
    }
    
    int result = sell[k];
    
    free(buy);
    free(sell);
    
    return result;
}