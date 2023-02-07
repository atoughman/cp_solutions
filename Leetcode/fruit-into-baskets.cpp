// problem link
// https://leetcode.com/problems/fruit-into-baskets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int so_far = 0;
        while(r<f.size()) {
            mp[f[r]]++;
            while(mp.size() > 2) {
                mp[f[l]]--;
                if(mp[f[l]] == 0) mp.erase(mp.find(f[l]));
                ++l;
            }
            so_far = max(so_far, r-l+1);
            ++r;
        }

        return so_far;
    }
};