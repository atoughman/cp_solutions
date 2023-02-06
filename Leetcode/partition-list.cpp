// problem link
// https://leetcode.com/problems/partition-list/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ref = new ListNode(); // dummy;
        ref->next = head;
        
        ListNode* l = ref;
        while(l->next != NULL and l->next->val < x) l = l->next;

        ListNode* r = l;

        while(true) {
            while(r->next != NULL and r->next->val >= x) r = r->next;
            if(r->next == NULL) break;

            ListNode* rnx = r->next;
            r->next = rnx->next;
            rnx->next = l->next;
            l->next = rnx;
            l = l->next;
        }

        return ref->next;
        
    }
};