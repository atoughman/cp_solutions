// problem link
// https://leetcode.com/problems/linked-list-cycle/description/

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode* ref_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return ref_head;
    }
};

// iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* left = NULL;
        ListNode* right = NULL;
        while(head) {
            right = head->next;
            head->next = left;
            left = head;
            head = right;
        }
        return left;
    }
};