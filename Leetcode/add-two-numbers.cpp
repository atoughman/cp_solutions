// problem link
// https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry = 0;

        while(l1 || l2 || carry != 0) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            carry = sum/10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dummyHead->next;
    }
};