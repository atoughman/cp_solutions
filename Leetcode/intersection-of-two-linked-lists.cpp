// problem link
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b) {
            if(a == NULL) a = headB;
            else a = a->next;

            if(b == NULL) b = headA;
            else b = b->next;
        }

        return a;
    }
};