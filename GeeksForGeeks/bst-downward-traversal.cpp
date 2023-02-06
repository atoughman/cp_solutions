// problem link
// https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    Node* dfs(Node* u, int &target) {
        if(u == NULL or u->data == target) return u;
        if(target < u->data) return dfs(u->left, target);
        else return dfs(u->right, target);
    }

    void dfs2(Node* u, ll &sum, int dir) {
        if(u == NULL) return;
        if(dir == 0) sum += u->data;
        
        dfs2(u->right, sum, dir+1);
        dfs2(u->left, sum, dir-1);
    }

    long long int verticallyDownBST(Node *root,int target){
        Node* match = dfs(root, target);
        if(match == NULL) return -1;
        
        ll sum = 0;
        dfs2(match->left, sum, -1);
        dfs2(match->right, sum, 1);
        
        return sum;
    }
};