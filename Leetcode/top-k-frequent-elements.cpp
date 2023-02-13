// problem link
// https://leetcode.com/problems/top-k-frequent-elements/description/

#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &x: nums) freq[x]++;

        priority_queue<pi, vector<pi>, greater<pi>> q;

        for(auto &x: freq) {
            q.push({x.second, x.first});
            if(q.size() > k) q.pop();
        }

        vector<int> ans;
        while(!q.empty()) {
            pi top = q.top();
            q.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};