#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to handle edge cases easily 
    // (e.g., when the head itself needs to be removed)
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* curr = &dummy;
    
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next; // Bypass the node with the target value
            free(temp);                    // Free the removed node's memory
        } else {
            curr = curr->next;
        }
    }
    
    return dummy.next;
}