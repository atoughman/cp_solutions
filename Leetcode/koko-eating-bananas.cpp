// problem link
// https://leetcode.com/problems/koko-eating-bananas/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, long long h) {
        int l = 1;
        int r = INT_MIN;
        for(auto &x: piles) r = max(r, x);

        // guess
        while(l <= r) {
            long long mid = l + (r-l)/2;

            long long time = 0;
            for(auto &x: piles) {
                time += ceil(x/(mid*1.0));
            }

            if(time > h) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};