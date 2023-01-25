// problem link
// https://leetcode.com/problems/middle-of-the-linked-list/description/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int ct = 1;
        ListNode* trav = head;
        while(trav->next) {
            trav = trav->next;
            ++ct;
        }
        trav = head;
        int middle = (ct/2) + 1;
        ct = 1;
        while(ct != middle) {
            trav = trav->next;
            ++ct;
        }

        return trav;
    }
};