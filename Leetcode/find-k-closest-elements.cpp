// problem link
// https://leetcode.com/problems/find-k-closest-elements/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;
        int n = arr.size();

        int ct = 0;
        while(ct<k) {
            // cout << l << ' ' << r << ' ' << ct << endl;
            if(l == -1) {
                ++r;
            }
            else if(r == n) {
                --l;
            }
            else if(abs(x-arr[l]) <= abs(x-arr[r])) {
                --l;
            } else {
                ++r;
            }
            ++ct;
        }

        return vector<int>(arr.begin()+l+1, arr.begin()+r);

    }
};