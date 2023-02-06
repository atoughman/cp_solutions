// problem link
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* tmp = head;
        while(tmp != NULL) {
            ++sz;
            tmp = tmp->next;
        }

        int pos = sz - n;

        ListNode* dum = new ListNode();
        dum->next = head;
        head = dum;

        while(pos--) {
            head = head->next;
        }

        head->next = head->next->next;
        return dum->next;
    }
};