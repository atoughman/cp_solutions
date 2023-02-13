// problem link
// https://leetcode.com/problems/sort-characters-by-frequency/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};
        for(auto &x: s) {
            freq[x]++;
        }

        vector<pair<int, int>> v;
        for(int i=0; i<128; i++) {
            if(freq[i]) {
                v.push_back({freq[i], i});
            }
        }

        sort(v.rbegin(), v.rend());

        string ans = "";
        for(auto &x: v) {
            int ct = x.first;
            while(ct) {
                ans += x.second;
                ct -= 1;
            }
        }

        return ans;
    }
};