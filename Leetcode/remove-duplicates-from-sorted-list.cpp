// problem link
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode* ref_head = head;
        while(head->next != NULL) {
            if(head->val == head->next->val) {
                head->next = head->next->next;
            } else head = head->next;
        }

        return ref_head;
    }
};