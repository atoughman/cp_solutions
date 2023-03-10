// problem link
// https://leetcode.com/problems/linked-list-random-node/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* head = NULL;
    
    Solution(ListNode* _head) {
        head = _head;
    }
    
    int getRandom() {
        ListNode* trav = head;
        int n = 0;
        int k = 1;
        int reservoir[k];

        while(trav != NULL) {
            int ind = rand() % (n+1);
            if(ind < k) {
                reservoir[ind] = trav->val;
            }
            trav = trav->next;
            n += 1;
        }

        return reservoir[0];
    }
};