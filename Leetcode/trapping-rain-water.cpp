// problem link
// https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        int left_mx = 0;
        int right_mx = 0;

        while(l<r) {
            if(height[l] < height[r]) {
                if(left_mx > height[l]) ans += left_mx - height[l];
                else left_mx = height[l];
                ++l;
            }
            else {
                if(right_mx > height[r]) ans += right_mx - height[r];
                else right_mx = height[r];
                --r;
            }
        }

        return ans;
    }
};