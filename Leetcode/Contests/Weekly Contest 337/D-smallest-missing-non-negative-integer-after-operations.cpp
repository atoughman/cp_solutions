#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& ar, int value) {
        int rems[value];
        memset(rems, 0, sizeof(rems));
        
        for(auto &x: ar) {
            int res = x%value;
            if(res < 0) res += value;
            rems[res]++;
        }
        
        int ct = 0;
        
        while(true) {
            if(rems[ct%value] == 0) break;
            rems[ct%value] -= 1;
            ct += 1;
        }
        
        return ct;
    }
};