// problem link
// https://leetcode.com/problems/gas-station/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_left = 0;
        int start = 0;
        int defecit = 0;

        for(int i=0; i<gas.size(); i++) {
            gas_left += gas[i] - cost[i];
            if(gas_left < 0) {
                defecit += gas_left;
                start = i+1;
                gas_left = 0;
            }
        }
        
        if(gas_left + defecit >= 0) return start;
        else return -1;
    }
};