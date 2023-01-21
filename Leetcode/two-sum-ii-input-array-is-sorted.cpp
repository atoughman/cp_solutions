// problem link
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while(l<r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) return {l+1, r+1};
            else if(sum < target) {
                ++l;
            } else --r;
        }

        // will never reach here
        return {-1, -1};
    }
};