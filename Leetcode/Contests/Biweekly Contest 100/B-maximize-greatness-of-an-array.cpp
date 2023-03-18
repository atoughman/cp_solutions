#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int>& a) {
        int l=0;
        int r = 1;
        int n = a.size();
        sort(a.begin(), a.end());
        while(r<n) {
            if(a[r] > a[l]) {
                l += 1;
            }
            r += 1;
        }
        
        return l;
    }
};