#include <stdbool.h>

// Helper function to calculate the sum of the squares of the digits
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        n /= 10;
        totalSum += d * d;
    }
    return totalSum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    // If a cycle occurs, slow and fast will eventually meet.
    // If n is happy, fast will eventually reach 1.
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    return fast == 1;
}