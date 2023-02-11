// problem link
// https://leetcode.com/problems/sqrtx/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while(l<=r) {
            long long mid = l + (r-l)/2;
            long long pro = 1LL * mid * mid;
            if(pro == x) return mid;
            if(pro > x) r = mid - 1;
            else l = mid+1;
        }

        return r;
    }
};