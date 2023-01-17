// problem link
// https://leetcode.com/problems/find-the-town-judge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ar[n+1];
        fill(ar, ar+n+1, 0);
        for(auto x: trust) {
            ar[x[0]]--;
            ar[x[1]]++;
        }

        for(int i=1; i<=n; i++) {
            if(ar[i] == n-1) return i;
        }
        return -1;
    }
};