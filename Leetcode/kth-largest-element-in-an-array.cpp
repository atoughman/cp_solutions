// problem link
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(int l, int r, vector<int> &nums, int k) {
        // cout << l << ' ' << r << endl;
        
        if(l == r) return nums[l];
        // search for pivot
        int mn = nums[l];
        int mx = nums[l];
        for(int i=l; i<=r; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        if(mn == mx) return mn;  // optimization for range that is filled with same numbers

        int pivot = mn + (mx-mn)/2;

        int left = l;
        int right = r;
        while(true) {
            while(left+1 <= r and nums[left] <= pivot) ++left;
            while(right-1 >= l and nums[right] > pivot) --right;
            if(left>=right) break;
            swap(nums[left], nums[right]);
        }

        // for(auto x: nums) cout << x << ' ';
        // cout << endl;

        if(left <= k) return search(left, r, nums, k);
        else return search(l, left-1, nums, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return search(0, nums.size()-1, nums, k);
    }
};