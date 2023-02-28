// problem link
// https://practice.geeksforgeeks.org/problems/d4aeef538e6dd3280dda5f8ed7964727fdc7075f/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // calculate prefix sum
        int pref[n];
        pref[0] = a[0];
        
        for(int i=1; i<n; i++) {
            pref[i] = pref[i-1] + a[i];
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int cv = a[i/2];  // common value
            int cvi = upper_bound(a.begin(), a.begin() + i+1, cv) - a.begin() - 1;   // common value index

            int left = pref[cvi];
            int right = pref[i] - left;
            int left_len = cvi + 1;
            int right_len = i+1 - left_len;
            int operations = right - (cv * right_len) + (cv * left_len) - left;

            ans.push_back(operations);
        }
        
        return ans;
    }
};