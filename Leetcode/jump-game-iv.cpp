// problem link
// https://leetcode.com/problems/jump-game-iv/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int tar = n-1;
        if(n <= 2) return n-1;

        queue<int> q;
        int inq[n];
        memset(inq, 0, sizeof(inq));
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }

        q.push(0);
        inq[0] = 1;
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            steps += 1;

            for(int k=0; k<sz; k++) {
                int i = q.front();
                q.pop();

                if(i+1 == tar) return steps;

                // left
                if(i-1>=0) {
                    if(!inq[i-1]) {
                        q.push(i-1);
                        inq[i-1] = 1;
                    }
                }
                
                // right
                if(!inq[i+1]) {
                    q.push(i+1);
                    inq[i+1] = 1;
                }

                for(auto &v: mp[arr[i]]) {
                    if(v == tar) return steps;
                    if(inq[v]) continue;

                    // otherwise
                    q.push(v);
                    inq[v] = 1;
                }
                mp[arr[i]].clear();

            }
        }

        // will never reach here.
        return -1;
    }
};