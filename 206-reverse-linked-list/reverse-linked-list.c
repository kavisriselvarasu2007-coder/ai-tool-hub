#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next; // Store the next node
        curr->next = prev;                      // Reverse the current node's pointer
        prev = curr;                            // Move prev forward
        curr = nextTemp;                        // Move curr forward
    }
    
    return prev; // prev will be the new head of the reversed list
}