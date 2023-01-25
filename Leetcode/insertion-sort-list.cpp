// problem link
// https://leetcode.com/problems/insertion-sort-list/description/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(0); // it's a dummy node will never be compared, so can have any value
        start->next = head;
        ListNode* prev = start;
        while(head) {
            ListNode* cur = start;
            while(cur->next->val < head->val) cur = cur->next;

            if(cur->next != head) {
                prev->next = head->next;
                head->next = cur->next;
                cur->next = head;
            } else prev = prev->next;
            
            head = prev->next;
        }

        return start->next;
    }
};