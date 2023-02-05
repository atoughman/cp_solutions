// problem link
// https://practice.geeksforgeeks.org/problems/eae1fbd0ac8f213a833d231e26ba4d829e79dd9c/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        Node* a = head1;
        Node* b = head2;
        
        while(a != b) {
            if(a == NULL) a = head2;
            else a = a->next;
            
            if(b == NULL) b = head1;
            else b = b->next;
        }
        
        return a == NULL ? -1 : a->data;
        
    }
};