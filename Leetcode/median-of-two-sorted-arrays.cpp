// problem link
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m, pos1, pos2;
    int count_smaller_and_equal(vector<int> &a, int val) {
        return upper_bound(a.begin(), a.end(), val) - a.begin();
    }

    int guess_and_search(vector<int>& nums1, vector<int>& nums2, int target) {
        int l,r;
        if(n == 0) {
            l = nums2[0];
            r = nums2[m-1];
        }else if(m == 0) {
            l = nums1[0];
            r = nums1[n-1];
        } else {
            l = min(nums1[0], nums2[0]);
            r = max(nums1[n-1], nums2[m-1]);    
        }
        
        // guess
        while(l <= r) {
            int mid = l + (r-l)/2;

            // search how many elements are smaller or equal
            int ct = count_smaller_and_equal(nums1, mid) + count_smaller_and_equal(nums2, mid);
            if(ct < target) l = mid + 1;
            else r = mid - 1;
            // cout << l << ' ' << r << " : " << mid << ' ' << ct << endl;
        }
        return l;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        pos1 = (n+m+1)/2;
        pos2 = (n+m+2)/2;

        int val1 = guess_and_search(nums1, nums2, pos1);
        int val2;
        if(pos1 != pos2) {
            val2 = guess_and_search(nums1, nums2, pos2);
        } else val2 = val1;

        return (val1+val2)/2.0;

    }
};