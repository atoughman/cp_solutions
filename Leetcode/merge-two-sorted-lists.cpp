// problem link
// https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* ans = new ListNode(); // dummyNode
        ListNode* trav = ans;

        while(list1 || list2) {
            int val1 = list1 ? list1->val : INT_MAX;
            int val2 = list2 ? list2->val : INT_MAX;

            if(val1 <= val2) {
                trav->next = list1;
                list1 = list1->next;
            } else {
                trav->next = list2;
                list2 = list2->next;
            }
            trav = trav->next;
        }

        return ans->next;
    }
};