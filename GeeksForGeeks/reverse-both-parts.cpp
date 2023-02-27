// problem link
// https://practice.geeksforgeeks.org/problems/bae68b4d6a2a77fb6bd459cf7447240919ebfbf5/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node* rev(Node* head, int k = INT_MAX) {
        // base
        if(head == NULL or head->next == NULL or k == 1) {
            return head;
        }
        
        Node* end = rev(head->next, k-1);
        head->next->next = head;
        head->next = NULL;
        
        return end;
    }
   
    Node *reverse(Node *head, int k)
    {
        Node* trav = head;
        Node* left_end = head;
        int ct = k;
        while(ct--) {
            trav = trav->next;
        }
        
        Node* left = rev(head, k);
        Node* right = rev(trav);
        
        left_end->next = right;
        head = left;
        
        return head;
    }
};