/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }

    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    // Traverse both lists. When a pointer hits the end, redirect it to the 
    // other list's head. They will either meet at the intersection node or 
    // both become NULL at the same time after swapping once.
    while (ptrA != ptrB) {
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }

    return ptrA;
}