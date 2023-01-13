// problem link
// https://leetcode.com/problems/gas-station/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v;

        for(int i=0; i<gas.size(); i++) v.push_back(gas[i] - cost[i]);

        int so_far = 0;
        for(int k=1; k<=2; k++) {
            for(int i=v.size()-1; i>=0; i--) {
                so_far += v[i];
                so_far = min(0, so_far);
                if(k == 2 and so_far == 0) return i;
            }
        }

        return -1;
    }
};