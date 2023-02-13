// problem link
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 == 0) ++low;
        if(high % 2 == 0) --high;
        if(high < low) return 0;
        if(high == low) return 1;
        return ceil((high-low+1)/2.0);
    }
};