// problem link
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int n = matrix.size();
        int r = matrix[n-1][n-1];

        // let's guess ( will take O(log n) time)
        while(l <= r) {
            int mid = l + (r-l)/2;

            // find how many elements are smaller or equal than our guess.
            // n * log(n)
            int ct = 0;
            for(int i=0; i<n; i++) {
                int dis = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                if(dis == 0) break;
                ct += dis;
            }
            if(ct < k) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};