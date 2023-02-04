// problem link
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int so_far = 1;

        unordered_set<int> s;
        for(auto &x: nums) s.insert(x);

        for(auto &x: nums) {
            if(s.find(x-1) != s.end()) continue;
            // otherwise it is starting value of a sequence.
            // let's get length of that sequence
            
            int right = x+1;
            while(s.find(right) != s.end()) ++right;
            so_far = max(so_far, right-x);
        }

        return so_far;
    }
};