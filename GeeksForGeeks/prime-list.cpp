// problem link
// https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1

#include<bits/stdc++.h>
using namespace std;

bool pre = false;
const int mxn = 1e5+3;
int is_prime[mxn];

void pre_compute() {
    fill(is_prime, is_prime+mxn, true);
    
    is_prime[0] = false;
    is_prime[1] = false;
    
    int fast = 1;
    for(int i=2; i*i<mxn; i+=fast) {
        if(is_prime) {
            for(int j=i*i; j<mxn; j+=i) {
                is_prime[j] = false;
            }
        }
        if(i == 3) ++fast;
    }
}

class Solution{
public:
    int update(int val) {
        int l = val;
        int r = val;
        while(true) {
            if(is_prime[l] == true) return l;
            if(is_prime[r] == true) return r;
            --l;
            ++r;
        }
        
        // will never reach here.
        return -1;
    }

    Node *primeList(Node *head){
        if(pre == false) pre_compute();
        pre = true;
        
        Node* trav = head;
        while(trav != NULL) {
            trav->val = update(trav->val);
            trav = trav->next;
        }
        
        return head;
    }
};