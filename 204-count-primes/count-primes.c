#include <stdlib.h>
#include <stdbool.h>

int countPrimes(int n) {
    if (n <= 2) return 0;
    
    // Allocate a boolean array to track primality (true means prime, false means composite)
    bool* isPrime = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    // Sieve of Eratosthenes
    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            // Mark all multiples of p starting from p * p as false (not prime)
            for (int i = p * p; i < n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Count the remaining prime numbers strictly less than n
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    
    free(isPrime);
    return count;
}