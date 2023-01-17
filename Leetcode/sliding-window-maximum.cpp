// problem link
// https://leetcode.com/problems/sliding-window-maximum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        deque<int> q;

        while(r<nums.size()) {
            while(!q.empty() && q.back() < nums[r]) q.pop_back();
            q.push_back(nums[r]);

            if(r>=k-1) {
                ans.push_back(q.front());
                if(nums[l] == q.front()) q.pop_front();
                ++l;
            }

            ++r;
        }

        return ans;
    }
};