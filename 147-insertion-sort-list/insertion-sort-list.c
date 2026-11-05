/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // Dummy head to simplify insertion at the beginning
    struct ListNode dummy;
    dummy.next = head;
    
    // 'last_sorted' points to the last node of the sorted portion
    // 'curr' points to the first node of the unsorted portion
    struct ListNode* last_sorted = head;
    struct ListNode* curr = head->next;

    while (curr != NULL) {
        if (curr->val >= last_sorted->val) {
            // If the current element is already greater or equal, 
            // it's already in the correct sorted position. Just advance.
            last_sorted = last_sorted->next;
        } else {
            // Otherwise, find the place to insert 'curr' starting from the dummy head
            struct ListNode* prev = &dummy;
            while (prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Remove 'curr' from its current position
            last_sorted->next = curr->next;

            // Insert 'curr' between 'prev' and 'prev->next'
            curr->next = prev->next;
            prev->next = curr;
        }
        // Move to the next node in the unsorted portion
        curr = last_sorted->next;
    }

    return dummy.next;
}