// problem link
// https://leetcode.com/problems/palindrome-linked-list/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp != NULL) {
            ++n;
            tmp = tmp->next;
        }
        int mid = n/2;
        tmp = head;
        for(int i=0; i<mid; i++) tmp = tmp->next;
        ListNode* prev = NULL;
        while(tmp->next != NULL) {
            ListNode* nx = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nx;
        }
        tmp->next = prev;

        while(tmp != NULL) {
            if(tmp->val != head->val) return false;
            tmp = tmp->next;
            head = head->next;
        }

        return true;

    }
};