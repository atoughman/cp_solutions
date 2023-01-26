// problem link
// https://leetcode.com/problems/odd-even-linked-list/description/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        while(even and even->next) {
            ListNode* tmp = even->next;
            even->next = tmp->next;
            tmp->next = odd->next;
            odd->next = tmp;

            odd = odd->next;
            even = even->next;
        }

        return head;
    }
};