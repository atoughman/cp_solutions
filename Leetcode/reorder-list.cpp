// problem link
// https://leetcode.com/problems/reorder-list/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        int sz = 0;
        ListNode* tmp = head;
        while(tmp != NULL) {
            ++sz;
            tmp = tmp->next;
        }

        int mid = sz/2;
        tmp = head;
        while(mid--) {
            tmp = tmp->next;
        }

        ListNode* prev = NULL;
        while(tmp->next != NULL) {
            ListNode* nx = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nx;
        }
        tmp->next = prev;
        
        while(true) {
            if(head->next == tmp or head == tmp) break;
            ListNode* l = head->next;
            ListNode* r = tmp->next;
            head->next = tmp;
            tmp->next = l;
            head = l;
            tmp = r;
        }
    }
};