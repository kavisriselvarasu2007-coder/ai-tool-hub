/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Splits the list into two parts: first part of length 'size', returns the head of the second part.
struct ListNode* split(struct ListNode* head, int size) {
    for (int i = 1; head && i < size; i++) {
        head = head->next;
    }
    if (!head) return NULL;
    
    struct ListNode* next_head = head->next;
    head->next = NULL;
    return next_head;
}

// Merges two sorted lists and returns [merged_head, merged_tail]
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, struct ListNode** tail_out) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    while (tail->next) {
        tail = tail->next;
    }
    *tail_out = tail;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // 1. Get the total length of the linked list
    int length = 0;
    struct ListNode* curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }

    struct ListNode dummy;
    dummy.next = head;

    // 2. Iteratively merge sublists of size 1, 2, 4, 8, ...
    for (int step = 1; step < length; step *= 2) {
        struct ListNode* prev = &dummy;
        curr = dummy.next;

        while (curr) {
            struct ListNode* left = curr;
            struct ListNode* right = split(left, step);
            curr = split(right, step);

            struct ListNode* merged_tail;
            struct ListNode* merged_head = merge(left, right, &merged_tail);

            prev->next = merged_head;
            prev = merged_tail;
        }
    }

    return dummy.next;
}