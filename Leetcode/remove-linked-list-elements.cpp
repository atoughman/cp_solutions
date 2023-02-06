// problem link
// https://leetcode.com/problems/remove-linked-list-elements/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ref = new ListNode(); // dummy
        ref->next = head;
        head = ref;

        while(head->next != NULL) {
            if(head->next->val == val) {
                head->next = head->next->next;
            } else head = head->next;
        }

        return ref->next;
    }
};