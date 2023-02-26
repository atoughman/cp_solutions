#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long rem = 0;
        vector<int> ans;
        for(auto &x: word) {
            rem = rem*10 + x-'0';
            rem %= m;
            ans.push_back(rem == 0);
        }
        
        return ans;
    }
};