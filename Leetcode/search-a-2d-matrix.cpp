// problem link
// https://leetcode.com/problems/search-a-2d-matrix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();
        int r = rows*cols - 1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            int i = mid / cols;
            int j = mid % cols;
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target) l = mid + 1;
            else r = mid - 1;
        }

        return false;
    }
};