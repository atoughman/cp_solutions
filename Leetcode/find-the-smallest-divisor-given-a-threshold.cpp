// problem link
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = INT_MIN;
        for(auto &x: nums) {
            r = max(r, x);
        }

        // guess
        while(l <= r) {
            int mid = l + (r-l)/2;

            // validate
            int sum = 0;
            for(auto &x: nums) {
                sum += ceil(x/(mid*1.0));
            }

            if(sum > threshold) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};