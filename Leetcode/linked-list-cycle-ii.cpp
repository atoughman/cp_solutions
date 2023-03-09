// problem link
// https://leetcode.com/problems/linked-list-cycle-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast != slow) return NULL;
        fast = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};