// problem link
// https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast) {
            slow = slow->next;
            if(fast == NULL or fast->next == NULL) break;
            fast = fast->next->next;
            if(slow == fast) return true;
        }

        return false;

    }
};