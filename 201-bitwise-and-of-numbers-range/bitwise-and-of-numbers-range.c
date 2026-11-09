int rangeBitwiseAnd(int left, int right) {
    int shiftCount = 0;
    
    // Find the common prefix of left and right by shifting both to the right
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shiftCount++;
    }
    
    // Shift the common prefix back to its original position
    return left << shiftCount;
}