// problem link
// https://leetcode.com/problems/reorganize-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        int freq[26] = {0};
        int mxi = 0;
        for(auto &x: s) {
            freq[x-'a']++;
            if(freq[x-'a'] > freq[mxi]) {
                mxi = x-'a';
            }
        }
        int mx = freq[mxi];

        if(n-mx < mx-1) return "";

        string adj[mx];

        for(int i=0; i<mx; i++) {
            adj[i] += 'a'+mxi;
        }

        int i = 0;
        int j = 0;
        while(true) {
            while(j<26 and freq[j] == 0) ++j;
            if(j == 26) break;
            if(j == mxi) {
                ++j;
                continue;
            }

            i = i%mx;
            adj[i] += 'a'+j;

            freq[j]--;
            ++i;
        }

        string ans = "";
        for(auto &x: adj) {
            ans += x;
        }

        return ans;
    }
};