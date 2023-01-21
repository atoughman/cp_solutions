// problem link
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int mx = 0;
        while(l<r) {
            int bre = r - l;
            int len = min(height[l], height[r]);
            int area = len * bre;
            mx = max(mx, area);
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return mx;
    }
};