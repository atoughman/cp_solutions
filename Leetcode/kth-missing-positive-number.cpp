// problem link
// https://leetcode.com/problems/kth-missing-positive-number/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1;
        int r = arr.back() + k;

        while(l<=r) {
            // guess
            int mid = l + (r-l)/2;

            // validate
            int ct = 0;
            auto it = upper_bound(arr.begin(), arr.end(), mid);
            if(it != arr.begin()) {
                --it;
                ct = it - arr.begin() + 1;
            }

            if(mid-ct < k) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};


///// Slightly bit more optimized...
// https://www.youtube.com/watch?v=GOOl2gikprM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size() - 1;

        while(l<=r) {
            // guess
            int mid = l + (r-l)/2;

            // validate
            int missing_count = arr[mid] - mid - 1;
            if(missing_count < k) {
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return r + k + 1;
    }
};
