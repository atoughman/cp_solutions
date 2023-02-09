// problem link
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            Node* prev = NULL;
            for(int i=0; i<sz; i++) {
                Node* u = q.front();
                q.pop();

                if(u == NULL) break;
                if(prev != NULL) prev->next = u;
                prev = u; 

                q.push(u->left);
                q.push(u->right);
            }
            if(prev != NULL) prev->next = NULL;
        }

        return root;
    }
};